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

#include "mmwave-3gpp-buildings-propagation-loss-model.h"

#include "mmwave-3gpp-propagation-loss-model.h"
#include "ns3/log.h"
#include "ns3/mobility-model.h"
#include "ns3/double.h"
#include <ns3/mobility-building-info.h>
#include <ns3/building-list.h>
#include <ns3/angles.h>
#include "ns3/config-store.h"
#include "ns3/string.h"
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mc-ue-net-device.h>
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/node.h>
#include "ns3/boolean.h"

NS_LOG_COMPONENT_DEFINE ("MmWave3gppBuildingsPropagationLossModel");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (MmWave3gppBuildingsPropagationLossModel);

std::ofstream MmWave3gppBuildingsPropagationLossModel::m_enbUeLocTrace;


MmWave3gppBuildingsPropagationLossModel::MmWave3gppBuildingsPropagationLossModel ()
{
	m_3gppLos = CreateObject<MmWave3gppPropagationLossModel> ();
	m_3gppLos->SetAttribute("ChannelCondition", StringValue ("l"));

	m_3gppNlos = CreateObject<MmWave3gppPropagationLossModel> ();
	m_3gppNlos->SetAttribute("ChannelCondition", StringValue ("n"));
	m_prevTime = Time(0);

	if(!m_enbUeLocTrace.is_open())
	{
		m_enbUeLocTrace.open("ENB-UE.txt");
		if (!m_enbUeLocTrace.is_open ())
		{
		  NS_FATAL_ERROR ("Can't open file ENB-UE.txt");
		  return;
		}
	}
	m_enbUeLocTrace.close();
}

MmWave3gppBuildingsPropagationLossModel::~MmWave3gppBuildingsPropagationLossModel ()
{
	if (m_enbUeLocTrace.is_open ())
	{
		m_enbUeLocTrace.close ();
	}
}

TypeId
MmWave3gppBuildingsPropagationLossModel::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::MmWave3gppBuildingsPropagationLossModel")
		.SetParent<BuildingsPropagationLossModel> ()
		.AddConstructor<MmWave3gppBuildingsPropagationLossModel> ()
		.AddAttribute ("UpdateCondition",
					"Update los/nlos condition while UE moves",
					BooleanValue (true),
					MakeBooleanAccessor (&MmWave3gppBuildingsPropagationLossModel::m_updateCondition),
					MakeBooleanChecker ())
	;
	return tid;
}


double
MmWave3gppBuildingsPropagationLossModel::DoCalcRxPower (double txPowerDbm, Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{
	return txPowerDbm - GetLoss (a, b);
}

double
MmWave3gppBuildingsPropagationLossModel::GetLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{
	NS_ASSERT_MSG ((a->GetPosition ().z >= 0) && (b->GetPosition ().z >= 0),
			"MmWave3gppBuildingsPropagationLossModel does not support underground nodes (placed at z < 0)");

	// get the MobilityBuildingInfo pointers
	Ptr<MobilityBuildingInfo> a1 = a->GetObject<MobilityBuildingInfo> ();
	Ptr<MobilityBuildingInfo> b1 = b->GetObject<MobilityBuildingInfo> ();
	NS_ASSERT_MSG ((a1 != 0) && (b1 != 0), "MmWave3gppBuildingsPropagationLossModel only works with MobilityBuildingInfo");

	double loss = 0.0;
	channelConditionMap_t::const_iterator it;
	it = m_conditionMap.find(std::make_pair(a,b));
	//it == m_conditionMap.end () check whether it is the first transmission, if yes determine the channel condition
	//m_updateCondition refresh conditionMap very transmission.
	if (it == m_conditionMap.end () || m_updateCondition)
	{
		channelCondition condition;
		/* The IsOutdoor and IsIndoor function is only based on the initial node position,
		 * it is not updated when the node is entering the building from outside or vise versa.*/
		if (a1->IsOutdoor () && b1->IsOutdoor ())
		{
			/* The outdoor case, determine LOS/NLOS
			 * The channel condition should be NLOS if the line intersect one of the buildings, otherwise LOS.
			 * */
			bool intersect = IsLineIntersectBuildings(a->GetPosition(), b->GetPosition());
			if(!intersect)
			{
				condition.m_channelCondition = 'l';
				condition.m_shadowing = 0;
			}
			else
			{
				condition.m_channelCondition = 'n';
				condition.m_shadowing = 0;
			}

		}
		else if(a1->IsIndoor () && b1->IsIndoor ())
		{
			//NS_FATAL_ERROR("indoor propagation loss not implemented yet");
			return	m_3gppLos->GetLoss (a,b);

		}
		else //outdoor to indoor case
		{
			//PL = PL_b + PL_tw + PL_in + N(0,sig^2); (7.4-2)
			//Here we assume the indoor nodes are all NLOS O2I.
			condition.m_channelCondition = 'i';
			//Compute the addition indoor pathloss term when this is the first transmission, or the node moves from outdoor to indoor.
			if(it == m_conditionMap.end () || (*it).second.m_channelCondition != 'i')
			{
				double lossIndoor = 0;
				double PL_tw;
				double stdP;
				if(m_3gppNlos->GetScenario ()== "RMa")
				{
					// only low-loss model is applied to RMa
					PL_tw = 5-10*log10(0.3*pow(10,-1*(2+0.2*m_frequency*1e-9)/10)+0.7*pow(10,-1*(5+4*m_frequency*1e-9)/10));
					stdP = 4.4;
				}
				else
				{
					if (a1->IsIndoor () && b1->IsOutdoor ())
					{
						if(a1->GetBuilding()->GetBuildingType () == Building::Commercial || a1->GetBuilding()->GetBuildingType () == Building::Office)
						{
							NS_LOG_DEBUG ("Commercial and office building use high-loss model for UMa and UMi, use low-loss model for RMa");
							PL_tw = 5-10*log10(0.7*pow(10,-1*(23+0.3*m_frequency*1e-9)/10)+0.3*pow(10,-1*(5+4*m_frequency*1e-9)/10));
							stdP = 6.5;
						}
						else
						{
							NS_LOG_DEBUG ("Residential building use low-loss model");
							PL_tw = 5-10*log10(0.3*pow(10,-1*(2+0.2*m_frequency*1e-9)/10)+0.7*pow(10,-1*(5+4*m_frequency*1e-9)/10));
							stdP = 4.4;

						}

					}
					else if (b1->IsIndoor () && a1->IsOutdoor ())
					{
						if(b1->GetBuilding()->GetBuildingType () == Building::Commercial || b1->GetBuilding()->GetBuildingType () == Building::Office)
						{
							NS_LOG_DEBUG("Commercial and office building use high-loss model for UMa and UMi, use low-loss model for RMa");
							PL_tw = 5-10*log10(0.7*pow(10,-1*(23+0.3*m_frequency*1e-9)/10)+0.3*pow(10,-1*(5+4*m_frequency*1e-9)/10));
							stdP = 6.5;
						}

						else
						{
							NS_LOG_DEBUG ("Residential building use low-loss model");
							PL_tw = 5-10*log10(0.3*pow(10,-1*(2+0.2*m_frequency*1e-9)/10)+0.7*pow(10,-1*(5+4*m_frequency*1e-9)/10));
							stdP = 4.4;
						}

					}
					else
					{
						NS_FATAL_ERROR("Programming Error");
					}
				}
				lossIndoor += PL_tw;
				//compute PL_in
				Ptr<UniformRandomVariable> uniRv1 = CreateObject<UniformRandomVariable> ();
				Ptr<UniformRandomVariable> uniRv2 = CreateObject<UniformRandomVariable> ();
				double dis_2D_in;
				if(m_3gppNlos->GetScenario ()== "RMa")
				{
					dis_2D_in = std::min(uniRv1->GetValue(0,10), uniRv2->GetValue(0,10));
				}
				else
				{
					dis_2D_in = std::min(uniRv1->GetValue(0,25), uniRv2->GetValue(0,25));
				}
				lossIndoor += 0.5*dis_2D_in;
				//compute indoor shadowing
				Ptr<NormalRandomVariable> norRv = CreateObject<NormalRandomVariable> ();
				lossIndoor += stdP*norRv->GetValue();
				//store the indoor pathloss term to the shadowing parameter.
				condition.m_shadowing = lossIndoor;
			}
			else
			{
				condition.m_shadowing = (*it).second.m_shadowing;
			}
		}


		if (it == m_conditionMap.end ())
		{
			//First transmission. Generate the channel condition and insert to the map
			m_conditionMap.insert (std::make_pair(std::make_pair (a,b), condition));
			m_conditionMap.insert (std::make_pair(std::make_pair (b,a), condition));
			it = m_conditionMap.find(std::make_pair(a,b));
		}
		else if ((*it).second.m_channelCondition != condition.m_channelCondition)
		{
			//m_updateCondition enabled and the channel condition changed. Update the conditionMap.
			m_conditionMap.erase (std::make_pair (a,b));
			m_conditionMap.erase (std::make_pair (b,a));
			m_conditionMap.insert (std::make_pair(std::make_pair (a,b), condition));
			m_conditionMap.insert (std::make_pair(std::make_pair (b,a), condition));
			it = m_conditionMap.find(std::make_pair(a,b));
		}

	}

	if((*it).second.m_channelCondition == 'l')
	{
		//LoS channel condition
		loss = m_3gppLos->GetLoss (a,b);

	}
	else if ((*it).second.m_channelCondition == 'n')
	{
		//NLoS channel condition
		loss = m_3gppNlos->GetLoss (a,b);

	}
	else if ((*it).second.m_channelCondition == 'i')
	{
		//for simplicity, the pathloss formulat still use d_2D instead of d_2D_out.
		//All the indoor pathloss terms are stored in the m_shadowing.
		loss =  m_3gppNlos->GetLoss (a,b) + (*it).second.m_shadowing;
	}
	else
	{
		NS_FATAL_ERROR("Programming error");
	}
	// Log ENB and UE location.
	if(Now().GetSeconds()-m_prevTime.GetSeconds()>3)
	{
		m_prevTime = Now();
	}

	if (Now().GetSeconds() - m_prevTime.GetSeconds()<0.00009)
	{
		Vector ueLoc, enbLoc;
		if(DynamicCast<MmWaveUeNetDevice> (a->GetObject<Node> ()->GetDevice (0)) !=0)
		{
			// if(DynamicCast<MmWaveEnbNetDevice> (b->GetObject<Node> ()->GetDevice (0)) !=0)
			// {
			// 	NS_LOG_INFO("UE->ENB Link");
			// 	ueLoc = a->GetPosition();
			// 	enbLoc = b->GetPosition();
			// 	LocationTrace(enbLoc, ueLoc, (*it).second.m_channelCondition == 'l');

			// }
		}
		else
		{
			if((DynamicCast<MmWaveUeNetDevice> (b->GetObject<Node> ()->GetDevice (0)) !=0) ||
				(DynamicCast<McUeNetDevice> (b->GetObject<Node> ()->GetDevice (0)) !=0))
			{
				NS_LOG_INFO("ENB->UE Link");
				enbLoc = a->GetPosition();
				ueLoc = b->GetPosition();
				LocationTrace(enbLoc, ueLoc, (*it).second.m_channelCondition == 'l');
			}
		}

	}


	return loss;
}

double
MmWave3gppBuildingsPropagationLossModel::mmWaveLosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{
	return 0;
}
double
MmWave3gppBuildingsPropagationLossModel::mmWaveNlosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{
	return 0;
}

bool
MmWave3gppBuildingsPropagationLossModel::IsLineIntersectBuildings(Vector L1, Vector L2 ) const
{
	for (BuildingList::Iterator bit = BuildingList::Begin (); bit != BuildingList::End (); ++bit)
	{
		Box boundaries = (*bit)->GetBoundaries ();

		Vector boxSize (0.5*(boundaries.xMax - boundaries.xMin),
				0.5*(boundaries.yMax - boundaries.yMin),
				0.5*(boundaries.zMax - boundaries.zMin));
		Vector boxCenter (boundaries.xMin + boxSize.x,
				boundaries.yMin + boxSize.y,
				boundaries.zMin + boxSize.z);

		// Put line in box space
		Vector LB1 (L1.x-boxCenter.x, L1.y-boxCenter.y, L1.z-boxCenter.z);
		Vector LB2 (L2.x-boxCenter.x, L2.y-boxCenter.y, L2.z-boxCenter.z);

		// Get line midpoint and extent
		Vector LMid (0.5*(LB1.x+LB2.x), 0.5*(LB1.y+LB2.y), 0.5*(LB1.z+LB2.z));
		Vector L (LB1.x - LMid.x, LB1.y - LMid.y, LB1.z - LMid.z);
		Vector LExt ( std::abs(L.x), std::abs(L.y), std::abs(L.z) );

		// Use Separating Axis Test
		// Separation vector from box center to line center is LMid, since the line is in box space
		// If the line did not intersect this building, jump to the next building.
		if ( std::abs( LMid.x ) > boxSize.x + LExt.x ) continue;
		if ( std::abs( LMid.y ) > boxSize.y + LExt.y ) continue;
		if ( std::abs( LMid.z ) > boxSize.z + LExt.z ) continue;
		// Crossproducts of line and each axis
		if ( std::abs( LMid.y * L.z - LMid.z * L.y)  >  (boxSize.y * LExt.z + boxSize.z * LExt.y) ) continue;
		if ( std::abs( LMid.x * L.z - LMid.z * L.x)  >  (boxSize.x * LExt.z + boxSize.z * LExt.x) ) continue;
		if ( std::abs( LMid.x * L.y - LMid.y * L.x)  >  (boxSize.x * LExt.y + boxSize.y * LExt.x) ) continue;

		// No separating axis, the line intersects
		// If the line intersect this building, return true.
		return true;
	}
	return false;
}

void
MmWave3gppBuildingsPropagationLossModel::LocationTrace (Vector enbLoc, Vector ueLoc, bool los) const
{
	if(!m_enbUeLocTrace.is_open())
	{
		m_enbUeLocTrace.open("ENB-UE.txt",std::ofstream::app);
		if (!m_enbUeLocTrace.is_open ())
		{
		  NS_FATAL_ERROR ("Can't open file ENB-UE.txt");
		  return;
		}
	}
	m_enbUeLocTrace << Simulator::Now ().GetNanoSeconds () / (double) 1e9 << "\t";
	m_enbUeLocTrace << enbLoc.x<< "\t";
	m_enbUeLocTrace << enbLoc.y<< "\t";
	m_enbUeLocTrace << enbLoc.z<< "\t";
	m_enbUeLocTrace << ueLoc.x<< "\t";
	m_enbUeLocTrace << ueLoc.y<< "\t";
	m_enbUeLocTrace << ueLoc.z << "\t";
	m_enbUeLocTrace << los << "\n";
	m_enbUeLocTrace.close();
}

std::string
MmWave3gppBuildingsPropagationLossModel::GetScenario ()
{
	return m_3gppLos->GetScenario();
}

char
MmWave3gppBuildingsPropagationLossModel::GetChannelCondition(Ptr<MobilityModel> a, Ptr<MobilityModel> b)
{
	channelConditionMap_t::const_iterator it;
	it = m_conditionMap.find(std::make_pair(a,b));
	if (it == m_conditionMap.end ())
	{
		NS_FATAL_ERROR ("Cannot find the link in the map");
	}
	return (*it).second.m_channelCondition;

}

void
MmWave3gppBuildingsPropagationLossModel::SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig)
{
	m_phyMacConfig = ptrConfig;
	m_frequency = m_phyMacConfig->GetCenterFrequency();
    static const double C = 299792458.0; // speed of light in vacuum
    m_lambda = C / m_frequency;

	NS_LOG_INFO("Frequency " << m_frequency);

    m_3gppNlos->SetConfigurationParameters(ptrConfig);
    m_3gppLos->SetConfigurationParameters(ptrConfig);
}

} // namespace ns3
