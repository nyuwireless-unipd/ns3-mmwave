 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2 as
 *   published by the Free Software Foundation;
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
 *   Author: Marco Mezzavilla < mezzavilla@nyu.edu>
 *        	 Sourjya Dutta <sdutta@nyu.edu>
 *        	 Russell Ford <russell.ford@nyu.edu>
 *        	 Menglei Zhang <menglei@nyu.edu>
 */



#include "antenna-array-model.h"
#include <ns3/log.h>
#include <ns3/math.h>
#include <ns3/simulator.h>
#include "ns3/double.h"
#include "ns3/boolean.h"


NS_LOG_COMPONENT_DEFINE ("AntennaArrayModel");

namespace ns3 {

namespace mmwave {

NS_OBJECT_ENSURE_REGISTERED (AntennaArrayModel);

AntennaArrayModel::AntennaArrayModel()
	// :m_minAngle (0),m_maxAngle(2*M_PI)
{
	m_omniTx = false;
	m_lastUpdateMap.clear();
	m_lastUpdatePairMap.clear();

	m_hpbw = 0; //HPBW value of each antenna element
	m_gMax = 0; //directivity value expressed in dBi and valid only for TRP (see table A.1.6-3 in 38.802)
	m_noPlane = 0;
	m_isUe = false;
	m_totNoArrayElements = 0;
}

AntennaArrayModel::~AntennaArrayModel()
{

}

TypeId
AntennaArrayModel::GetTypeId ()
{
	static TypeId tid = TypeId ("ns3::AntennaArrayModel")
	.SetParent<Object> ()
	.AddConstructor<AntennaArrayModel> ()
	.AddAttribute ("AntennaHorizontalSpacing",
			"Horizontal spacing between antenna elements, in multiples of lambda",
			DoubleValue (0.5),
			MakeDoubleAccessor (&AntennaArrayModel::m_disH),
		    MakeDoubleChecker<double> ())
	.AddAttribute ("AntennaVerticalSpacing",
			"Vertical spacing between antenna elements, in multiples of lambda",
			DoubleValue (0.5),
			MakeDoubleAccessor (&AntennaArrayModel::m_disV),
		    MakeDoubleChecker<double> ())
	.AddAttribute ("IsotropicAntennaElements",
			"If true, the antenna elements are isotropic. If false, they follow the 3GPP spec on element radiation pattern",
			BooleanValue (true),
			MakeBooleanAccessor (&AntennaArrayModel::m_isotropicElement),
			MakeBooleanChecker ())
	;
	return tid;
}

double
AntennaArrayModel::GetGainDb (Angles a)
{
	/*NS_ASSERT (m_minAngle<=m_maxAngle);
	double gain;
	if (m_maxAngle <= M_PI)
	{
		if(a.phi < m_minAngle || a.phi > m_maxAngle)
		{
			gain = -500;
			//NS_LOG_UNCOND ("++++++++++++++++++++++blocked");
		}
		else
		{
			gain = 0;
		}
	}
	else
	{
		double maxAngle = m_maxAngle - 2*M_PI;
		if(a.phi < m_minAngle || a.phi > maxAngle)
		{
			gain = -500;
			//NS_LOG_UNCOND ("++++++++++++++++++++++blocked");
			}
		else
		{
			gain = 0;
		}

	}

	return gain;*/
	return 0;
}
void
AntennaArrayModel::SetBeamformingVectorWithDelay (complexVector_t antennaWeights, Ptr<NetDevice> device)
{
	Simulator::Schedule (MilliSeconds(8), &AntennaArrayModel::SetBeamformingVectorPanel,this,antennaWeights,device);
}

void
AntennaArrayModel::SetPlanesNumber (double planesNumber)
{
	m_noPlane = planesNumber;
}

double
AntennaArrayModel::GetPlanesId (void)
{
	return m_currentPanelId;
}


void
AntennaArrayModel::SetTotNoArrayElements (double arrayElements)
{
	m_totNoArrayElements = arrayElements;
}

void
AntennaArrayModel::SetDeviceType (bool isUe)
{
	m_isUe = isUe;
	if (isUe)
	{
		m_hpbw = 90; //HPBW value of each antenna element
		m_gMax = 5; //directivity value expressed in dBi and valid only for TRP (see table A.1.6-3 in 38.802
		}
	else
	{
		m_hpbw = 65; //HPBW value of each antenna element
		m_gMax = 8; //directivity value expressed in dBi and valid only for TRP (see table A.1.6-3 in 38.802
	}
}

double
AntennaArrayModel::GetOffset ()
{
	NS_LOG_DEBUG("GetOffset " << m_currentPanelId);
	NS_LOG_DEBUG("Offset " << m_currentPanelId*2*M_PI/m_noPlane);
	return m_currentPanelId*2*M_PI/m_noPlane;
}

void
AntennaArrayModel::SetBeamformingVectorPanelDevices (Ptr<NetDevice> thisDevice, Ptr<NetDevice> otherDevice)
{
	NS_LOG_FUNCTION(this << otherDevice << Simulator::Now());
	m_omniTx = false;
	complexVector_t antennaWeights;
	int panelId = 0; // initialize all the variables
	if (thisDevice != 0 && otherDevice != 0)
	{
		Vector aPos = thisDevice->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
		NS_LOG_INFO("aPos: " << aPos);
		Vector bPos = otherDevice->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
		NS_LOG_INFO("bPos: " << bPos);

		Angles completeAngle (bPos,aPos);

		double posX = bPos.x-aPos.x;
		double phiAngle = atan((bPos.y-aPos.y)/posX); //horizontal angle only

		if (posX < 0)
			phiAngle = phiAngle + M_PI;
		if (phiAngle < 0)
			phiAngle = phiAngle + 2*M_PI;

		// if (m_isUe)
		// 	phiAngle = M_PI;
		// else
		// 	phiAngle=0; // cast BF vectors fixed to zero [DEBUG PROCEDURE TEST LINE]

		panelId = floor(fmod(phiAngle+M_PI/m_noPlane,2*M_PI)*m_noPlane/(2*M_PI)); // panel id into the interval [0,N-1]

		double hAngleRadian = fmod((phiAngle+(M_PI/m_noPlane)),2*M_PI/m_noPlane) - (M_PI/m_noPlane);
		double vAngleRadian = completeAngle.theta;
		double power = 1/sqrt(m_totNoArrayElements);
		uint8_t antennaNum [2];
		antennaNum[0] = sqrt(m_totNoArrayElements);
		antennaNum[1] = sqrt(m_totNoArrayElements);
		NS_LOG_INFO("hAngleRadian: " << hAngleRadian);

		for(int ind=0; ind<m_totNoArrayElements; ind++)
		{
			Vector loc = GetAntennaLocation(ind, antennaNum);
			double phase = -2*M_PI*(sin(vAngleRadian)*cos(hAngleRadian)*loc.x
								+ sin(vAngleRadian)*sin(hAngleRadian)*loc.y
								+ cos(vAngleRadian)*loc.z);
			antennaWeights.push_back(exp(std::complex<double>(0, phase))*power);
		}

		std::map< Ptr<NetDevice>, std::pair<complexVector_t,int> >::iterator iter = m_beamformingVectorPanelMap.find (otherDevice);
		if (iter != m_beamformingVectorPanelMap.end ())
		{
			(*iter).second = std::make_pair (antennaWeights, panelId);
			m_lastUpdatePairMap[otherDevice] = Simulator::Now();
		}
		else
		{
			m_beamformingVectorPanelMap.insert (std::make_pair (otherDevice, std::make_pair(antennaWeights, panelId) ));
			m_lastUpdatePairMap.insert(std::make_pair (otherDevice, Simulator::Now()));

			NS_LOG_INFO("m_lastUpdatePairMap.size " << m_lastUpdatePairMap.size());
		}
	}
	m_beamformingVector = antennaWeights;
	m_currentPanelId = panelId;
	m_currentDev = otherDevice;
	NS_LOG_INFO("panelId: " << panelId);
	NS_LOG_INFO("otherDevice: " << otherDevice);
}

// to store dummy info
void
AntennaArrayModel::SetBeamformingVectorPanel (complexVector_t antennaWeights, Ptr<NetDevice> device)
{
	NS_LOG_FUNCTION(this << device << Simulator::Now());
	m_omniTx = false;
	if (device != 0)
	{
		auto iter = m_beamformingVectorPanelMap.find (device);
		if (iter != m_beamformingVectorPanelMap.end ())
		{
			(*iter).second = std::make_pair(antennaWeights, 0);
			m_lastUpdatePairMap[device] = Simulator::Now();
		}
		else
		{
			m_beamformingVectorPanelMap.insert (std::make_pair (device, std::make_pair(antennaWeights, 0)) );
			m_lastUpdatePairMap.insert(std::make_pair (device, Simulator::Now()));

			NS_LOG_INFO("m_lastUpdatePairMap.size " << m_lastUpdatePairMap.size());
		}
	}
	// following lines are commented to store dummy info; call ChangeBeamformingVectorPanel (device) to set the antennaWeights
	// m_beamformingVector = antennaWeights;
	// m_currentDev = device;
}

void
AntennaArrayModel::ChangeBeamformingVectorPanel (Ptr<NetDevice> device)
{
	NS_LOG_FUNCTION(this << device << Simulator::Now());
	m_omniTx = false;
	std::map< Ptr<NetDevice>, std::pair<complexVector_t,int> >::iterator it = m_beamformingVectorPanelMap.find (device);
	NS_ASSERT_MSG (it != m_beamformingVectorPanelMap.end (), "could not find");
	NS_LOG_DEBUG("ChangeBeamformingVectorPanel towards dev " << device << " prev panel " << m_currentPanelId << " updated to " << it->second.second);
	m_beamformingVector = it->second.first;
	m_currentPanelId = it->second.second;
	m_currentDev = device;
}

complexVector_t
AntennaArrayModel::GetBeamformingVectorPanel ()
{
	NS_LOG_FUNCTION(this << Simulator::Now());
	if(m_omniTx)
	{
		NS_FATAL_ERROR ("Omni transmission do not need beamforming vector");
	}
	return m_beamformingVector;
}

void
AntennaArrayModel::ChangeToOmniTx ()
{
	m_omniTx = true;
}

bool
AntennaArrayModel::IsOmniTx ()
{
	return m_omniTx;
}

complexVector_t
AntennaArrayModel::GetBeamformingVectorPanel (Ptr<NetDevice> device)
{
	NS_LOG_FUNCTION(this << device << Simulator::Now());
	complexVector_t weights;
	std::map< Ptr<NetDevice>, std::pair<complexVector_t,int> >::iterator it = m_beamformingVectorPanelMap.find (device);
	if (it != m_beamformingVectorPanelMap.end ())
	{
		weights = it->second.first;
	}
	else
	{
		weights = m_beamformingVector;
	}
	return weights;
}

Ptr<NetDevice>
AntennaArrayModel::GetCurrentDevice()
{
	return m_currentDev;
}

double
AntennaArrayModel::GetRadiationPattern (double vAngleRadian, double hAngleRadian)
{
	if(m_isotropicElement)
	{
		return 1;
	}

	while (hAngleRadian >= M_PI)
		hAngleRadian -= 2*M_PI;
	while (hAngleRadian < -M_PI)
		hAngleRadian += 2*M_PI;

	double vAngle = vAngleRadian*180/M_PI;
	double hAngle = hAngleRadian*180/M_PI;
	//NS_LOG_INFO(" it is " << vAngle);
	NS_ASSERT_MSG(vAngle>=0&&vAngle<=180, "the vertical angle should be the range of [0,180]");
	//NS_LOG_INFO(" it is " << hAngle);
	NS_ASSERT_MSG(hAngle>=-180&&hAngle<=180, "the horizontal angle should be the range of [-180,180]");

	double A_M = 30; //front-back ratio expressed in dB
	double SLA = 30; //side-lobe level limit expressed in dB

	double A_v = -1*std::min(SLA,12*pow ((vAngle-90)/m_hpbw,2)); //TODO: check position of z-axis zero
	double A_h = -1*std::min(A_M,12*pow(hAngle/m_hpbw,2));
	double A = m_gMax-1*std::min(A_M,-1*A_v-1*A_h);

	return sqrt(pow(10,A/10)); //filed factor term converted to linear;
}

Vector
AntennaArrayModel::GetAntennaLocation(uint8_t index, uint8_t* antennaNum)
{
	//assume the left bottom corner is (0,0,0), and the rectangular antenna array is on the y-z plane.
	Vector loc;
	loc.x = 0;
	loc.y = m_disH* (index % antennaNum[0]);
	loc.z = m_disV* floor(index / antennaNum[0]);
	return loc;
}

void
AntennaArrayModel::SetSector (uint8_t sector, uint8_t *antennaNum, double elevation)
{
	complexVector_t tempVector;
	double hAngle_radian = M_PI*(double)sector/(double)antennaNum[1]-0.5*M_PI;
	double vAngle_radian = elevation*M_PI/180;
	uint16_t size = antennaNum[0]*antennaNum[1];
	double power = 1/sqrt(size);
	for(int ind=0; ind<size; ind++)
	{
		Vector loc = GetAntennaLocation(ind, antennaNum);
		double phase = -2*M_PI*(sin(vAngle_radian)*cos(hAngle_radian)*loc.x
							+ sin(vAngle_radian)*sin(hAngle_radian)*loc.y
							+ cos(vAngle_radian)*loc.z);
		tempVector.push_back(exp(std::complex<double>(0, phase))*power);
	}
	m_beamformingVector = tempVector;
}

Time
AntennaArrayModel::GetLastUpdate(Ptr<NetDevice> device)
{
	NS_LOG_FUNCTION(this << device << Simulator::Now());
	auto lastUpdate = m_lastUpdateMap.find(device);
	NS_ASSERT_MSG(lastUpdate != m_lastUpdateMap.end(), "Device never updated!");
	NS_LOG_INFO("Last update for device " << device << " at time " << lastUpdate->second.GetSeconds());
	return lastUpdate->second;
}

} /* namespace mmwave */

} /* namespace ns3 */
