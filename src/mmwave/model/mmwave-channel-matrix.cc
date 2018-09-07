 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *			Dual Connectivity and Handover functionalities
 */


#include "mmwave-channel-matrix.h"
#include <ns3/log.h>
#include <ns3/math.h>
#include <ns3/simulator.h>
#include <ns3/mmwave-phy.h>
#include <ns3/mmwave-net-device.h>
#include <ns3/node.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mc-ue-net-device.h>
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/antenna-array-model.h>
#include <ns3/mmwave-ue-phy.h>
#include <ns3/mmwave-enb-phy.h>
#include <ns3/double.h>
#include <algorithm>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("MmWaveChannelMatrix");

namespace mmwave {

NS_OBJECT_ENSURE_REGISTERED (MmWaveChannelMatrix);

static const double CdfOfClusterNum[4] = {0.480, 0.761, 0.927, 1.0}; //Cdf of cluster number equal {1,2,3,4}


MmWaveChannelMatrix::MmWaveChannelMatrix ()
	:m_antennaSeparation(0.5)
{
	m_uniformRv = CreateObject<UniformRandomVariable> ();
	m_expRv = CreateObject<ExponentialRandomVariable> ();

}

TypeId
MmWaveChannelMatrix::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::MmWaveChannelMatrix")
	.SetParent<Object> ()
	.AddAttribute ("ChunkWidth",
			   "Width of each chunk in Hz",
			   DoubleValue (13.889e6),
			   MakeDoubleAccessor (&MmWaveChannelMatrix::m_subBW),
			   MakeDoubleChecker<double> ())
	.AddAttribute ("NumResourceBlocks",
			   "Number of resource blocks in one slot",
			   UintegerValue (4),
			   MakeUintegerAccessor (&MmWaveChannelMatrix::m_numRB),
			   MakeUintegerChecker<uint32_t> ())
	.AddAttribute ("NumSubbandPerRB",
			   "Number of sub-bands in one resource block",
			   UintegerValue (18),
			   MakeUintegerAccessor (&MmWaveChannelMatrix::m_numSBPerRB),
			   MakeUintegerChecker<uint32_t> ())
	;
	return tid;
}

MmWaveChannelMatrix::~MmWaveChannelMatrix ()
{

}

void
MmWaveChannelMatrix::DoDispose ()
{
	NS_LOG_FUNCTION (this);
}

void
MmWaveChannelMatrix::SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig)
{
	m_phyMacConfig = ptrConfig;
}

Ptr<MmWavePhyMacCommon>
MmWaveChannelMatrix::GetConfigurationParameters (void) const
{
	return m_phyMacConfig;
}


void
MmWaveChannelMatrix::ConnectDevices (Ptr<NetDevice> dev1, Ptr<NetDevice> dev2)
{
	key_t key = std::make_pair(dev1,dev2);

	std::map< key_t, int >::iterator iter = m_connectedPair.find(key);
	if (iter != m_connectedPair.end ())
	{
		m_connectedPair.erase (iter);
	}
	m_connectedPair.insert(std::make_pair(key,1));
}

void
MmWaveChannelMatrix::Initial(NetDeviceContainer ueDevices, NetDeviceContainer enbDevices)
{

	NS_LOG_INFO (&ueDevices<<&enbDevices);
	/*
	for (NetDeviceContainer::Iterator i = ueDevices.Begin(); i != ueDevices.End(); i++)
	{
		Ptr<MmWaveUeNetDevice> UeDev =
						DynamicCast<MmWaveUeNetDevice> (*i);
		if (UeDev->GetTargetEnb ())
		{
			Ptr<NetDevice> targetBs = UeDev->GetTargetEnb ();
			ConnectDevices (*i, targetBs);
			ConnectDevices (targetBs, *i);

		}
	}
	*/
}

Ptr<SpectrumValue>
MmWaveChannelMatrix::DoCalcRxPowerSpectralDensity (Ptr<const SpectrumValue> txPsd,
                                                   Ptr<const MobilityModel> a,
                                                   Ptr<const MobilityModel> b) const
{
	NS_LOG_FUNCTION (this);
	Ptr<SpectrumValue> rxPsd = Copy (txPsd);
	Ptr<AntennaArrayModel> txAntennaArray, rxAntennaArray;

	Ptr<NetDevice> txDevice = a->GetObject<Node> ()->GetDevice (0);
	Ptr<NetDevice> rxDevice = b->GetObject<Node> ()->GetDevice (0);
	Ptr<MmWaveEnbNetDevice> txEnb =
					DynamicCast<MmWaveEnbNetDevice> (txDevice);
	Ptr<mmwave::MmWaveUeNetDevice> rxUe =
					DynamicCast<mmwave::MmWaveUeNetDevice> (rxDevice);

	uint8_t txAntennaNum[2];
	uint8_t rxAntennaNum[2];

	if(txEnb!=0 && rxUe!=0)
	{
		NS_LOG_INFO ("this is downlink case");
		txAntennaNum[0] = sqrt (txEnb->GetAntennaNum ());
		txAntennaNum[1] = sqrt (txEnb->GetAntennaNum ());
		rxAntennaNum[0] = sqrt (rxUe->GetAntennaNum ());
		rxAntennaNum[1] = sqrt (rxUe->GetAntennaNum ());

		txAntennaArray = DynamicCast<AntennaArrayModel> (
					txEnb->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
		rxAntennaArray = DynamicCast<AntennaArrayModel> (
					rxUe->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
	}
	else if (txEnb!=0 && rxUe == 0)
	{
		Ptr<McUeNetDevice> mcRxUe = DynamicCast<McUeNetDevice> (rxDevice);
		if (mcRxUe != 0)
		{
			NS_LOG_INFO ("this is downlink case for MC device");
			txAntennaNum[0] = sqrt (txEnb->GetAntennaNum ());
			txAntennaNum[1] = sqrt (txEnb->GetAntennaNum ());
			rxAntennaNum[0] = sqrt (mcRxUe->GetAntennaNum ());
			rxAntennaNum[1] = sqrt (mcRxUe->GetAntennaNum ());

			txAntennaArray = DynamicCast<AntennaArrayModel> (
						txEnb->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
			rxAntennaArray = DynamicCast<AntennaArrayModel> (
						mcRxUe->GetMmWavePhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
		}
	}
	else if (txEnb==0 && rxUe==0 )
	{
		Ptr<mmwave::MmWaveUeNetDevice> txUe =
						DynamicCast<mmwave::MmWaveUeNetDevice> (txDevice);
		Ptr<MmWaveEnbNetDevice> rxEnb =
						DynamicCast<MmWaveEnbNetDevice> (rxDevice);
		if (txUe != 0)
		{
			NS_LOG_INFO ("this is uplink case");
			txAntennaNum[0] = sqrt (txUe->GetAntennaNum ());
			txAntennaNum[1] = sqrt (txUe->GetAntennaNum ());
			rxAntennaNum[0] = sqrt (rxEnb->GetAntennaNum ());
			rxAntennaNum[1] = sqrt (rxEnb->GetAntennaNum ());

			txAntennaArray = DynamicCast<AntennaArrayModel> (
						txUe->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
			rxAntennaArray = DynamicCast<AntennaArrayModel> (
						rxEnb->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
		}
		else
		{
			Ptr<McUeNetDevice> mcTxUe = DynamicCast<McUeNetDevice> (txDevice);

			if (mcTxUe != 0)
			{
				NS_LOG_INFO ("this is MC uplink case");
				txAntennaNum[0] = sqrt (mcTxUe->GetAntennaNum ());
				txAntennaNum[1] = sqrt (mcTxUe->GetAntennaNum ());
				rxAntennaNum[0] = sqrt (rxEnb->GetAntennaNum ());
				rxAntennaNum[1] = sqrt (rxEnb->GetAntennaNum ());

				txAntennaArray = DynamicCast<AntennaArrayModel> (
							mcTxUe->GetMmWavePhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
				rxAntennaArray = DynamicCast<AntennaArrayModel> (
							rxEnb->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
			}
		}
	}
	else
	{
		NS_LOG_INFO ("enb to enb or ue to ue transmission, skip beamforming");
		return rxPsd;
	}

	Ptr<mmWaveBeamFormingParams> bfParams = Create<mmWaveBeamFormingParams> ();
	Angles txAngles (b->GetPosition (), a->GetPosition ());
	Angles rxAngles (a->GetPosition (), b->GetPosition ());
	key_t key = std::make_pair(txDevice,rxDevice);
	std::map< key_t, Ptr<ChannelParams> >::iterator it = m_channelMatrixMap.find (key);
	if (it == m_channelMatrixMap.end ())
	{
		/*make sure txAngles rxAngles exist, i.e., the position of tx and rx cannot be the same*/

		//Generate the cluster number depend on Poisson distribution.
		double Pref = m_uniformRv->GetValue (0,1);
		std::vector<uint16_t> cluster;
		uint16_t clusterNum;
		if (Pref < CdfOfClusterNum[0])
		{
			clusterNum = 1;

		}
		else if (Pref < CdfOfClusterNum[1])
		{
			clusterNum = 2;

		}
		else if (Pref < CdfOfClusterNum[2])
		{
			clusterNum = 3;
		}
		else
		{
			clusterNum = 4;
		}

		for (int i = 0; i < clusterNum; i++)
		{
			uint16_t subpath = m_uniformRv->GetInteger (1,10);
			cluster.push_back (subpath);
		}

		//Generate cluster power fraction for each cluster
		doubleVector_t clusterPowerFraction;
		Ptr<NormalRandomVariable> normalRv = CreateObject<NormalRandomVariable> ();
		for(int i = 0; i < clusterNum; i++)
		{
			double u = m_uniformRv->GetValue (0,1);
			double z = normalRv->GetValue()*4;
			//double p = std::pow(u,1.8)*std::pow(10,(-0.1)*z); this is the correct formula, but the result is not convincing
			double p = std::pow(u,1.8)*std::pow(10,(0.1)*z)/cluster.at (i);
			clusterPowerFraction.push_back (p);
		}
		doubleVector_t powerFraction;
		for(int i = 0; i < clusterNum; i++)
		{

			for (int l = 0; l < cluster.at (i); l++)
			{
				powerFraction.push_back (clusterPowerFraction. at (i)*std::pow(10, m_uniformRv->GetValue(0, 0.6)));
			}

		}
		std::sort (powerFraction.begin (), powerFraction.end (),std::greater<double>());

		//normalize cluster power fraction
		double powerSum = 0;
		uint32_t s = powerFraction.size ();
		for (unsigned int j = 0; j< s; j++)
		{
			powerSum += powerFraction. at(j);
		}
		for (unsigned int j = 0; j< s; j++)
		{
			powerFraction.at (j) = powerFraction.at (j)/powerSum;
			NS_LOG_UNCOND (j<<" "<<powerFraction. at (j));
		}

		doubleVector_t clusterDelay;
		for (int i = 0; i < clusterNum; i++)
		{
			double tao = m_expRv->GetValue (83,300);
			clusterDelay.push_back (tao);
		}
		std::sort (clusterDelay.begin (), clusterDelay.end ());
		for (int i = 0; i < clusterNum; i++)
		{
			if (i == 0)
			{
				clusterDelay.at (0) = 0;
			}
			else
			{
			clusterDelay.at (i) = (clusterDelay.at (i-1)+clusterDelay.at (i)-clusterDelay.at (0)+25)*1e-9;
			}
		}

		doubleVector_t subpathDelay;
		double bandwidth = m_subBW*m_numSBPerRB*m_numRB;
		for (int i = 0; i < clusterNum; i++)
		{
			for (int j = 0; j < cluster.at (i); j++)
			{
				subpathDelay.push_back (clusterDelay. at(i)+std::pow(1/bandwidth*j, m_uniformRv->GetValue(0,0.43)+1));
			}
		}

		std::sort (subpathDelay.begin (), subpathDelay.end ());

		/*debug----------------------------------*/
		int counter = 0;
		for (int i = 0; i < clusterNum; i++)
		{
			for (int j = 0; j < cluster.at (i); j++)
			{
				NS_LOG_UNCOND ("cluster"<<i<<"subpath"<<j<<":"<<subpathDelay.at(counter));
				counter++;
			}
		}
		/*----------------------------------end*/

		doubleVector_t dopplerShift;
		for (unsigned int i = 0; i < subpathDelay.size (); i++)
		{
			dopplerShift.push_back(m_uniformRv->GetValue (0,1));
		}


		complex2DVector_t txSpatialMatrix = GenSpatialMatrix (cluster,txAngles,txAntennaNum);
		complex2DVector_t rxSpatialMatrix = GenSpatialMatrix (cluster,rxAngles,rxAntennaNum);
		Ptr<ChannelParams> channel = Create<ChannelParams> ();

		channel->m_txSpatialMatrix = txSpatialMatrix;
		channel->m_rxSpatialMatrix = rxSpatialMatrix;
		channel->m_powerFraction = powerFraction;
		channel->m_delaySpread = subpathDelay;
		channel->m_doppler = dopplerShift;


		m_channelMatrixMap.insert(std::make_pair(key,channel));

		key_t reverseKey = std::make_pair(rxDevice,txDevice);
		Ptr<ChannelParams> reverseChannel = Create<ChannelParams> ();
		reverseChannel->m_txSpatialMatrix = rxSpatialMatrix;
		reverseChannel->m_rxSpatialMatrix = txSpatialMatrix;
		reverseChannel->m_powerFraction = powerFraction;
		reverseChannel->m_delaySpread = subpathDelay;
		reverseChannel->m_doppler = dopplerShift;

		m_channelMatrixMap.insert(std::make_pair(reverseKey,reverseChannel));

		bfParams->m_channelParams = channel;
	}
	else
	{
		bfParams->m_channelParams = (*it).second;
	}
	//	calculate antenna weights, better method should be implemented
	bfParams->m_txW = txAntennaArray->GetBeamformingVectorPanel();
	bfParams->m_rxW = rxAntennaArray->GetBeamformingVectorPanel();

	/*
	std::map< key_t, int >::iterator it1 = m_connectedPair.find (key);
	if(it1 != m_connectedPair.end ())
	{
		if (txW.empty() && rxW.empty ())
		{
			txW = CalcBeamformingVector(bfParams->m_channelParams->m_txSpatialMatrix);
			rxW = CalcBeamformingVector(bfParams->m_channelParams->m_rxSpatialMatrix);
			txAntennaArray->SetBeamformingVector(txW,rxDevice);
			rxAntennaArray->SetBeamformingVector(rxW,txDevice);
		}
	}
	*/

	Vector rxSpeed = b->GetVelocity();
	Vector txSpeed = a->GetVelocity();
	double relativeSpeed = (rxSpeed.x-txSpeed.x)
			+(rxSpeed.y-txSpeed.y)+(rxSpeed.z-txSpeed.z);
	Ptr<SpectrumValue> bfPsd = GetChannelGain(rxPsd,bfParams, relativeSpeed);


	/*loging the beamforming gain for debug*/
	Values::iterator bfit = bfPsd->ValuesBegin ();
	Values::iterator rxit = rxPsd->ValuesBegin ();
	uint32_t subChannel = 0;
	double value=0;
	while (bfit != bfPsd->ValuesEnd ())
	{
		value += (*bfit)/(*rxit);
		bfit++;
		rxit++;
		subChannel++;
	}
	NS_LOG_UNCOND("Gain("<<10*log10(value/72)<<"dB)");

	//NS_LOG_UNCOND ("TxAngle("<<txAngles.phi*180/M_PI<<") RxAngle("<<rxAngles.phi*180/M_PI
	//		<<") Speed["<<relativeSpeed<<"]");
	NS_LOG_UNCOND ("Gain("<<10*Log10((*bfPsd)/(*txPsd))<<"dB)");
	return bfPsd;


}

/*
complexVector_t
MmWaveChannelMatrix::CalcBeamformingVector(complex2DVector_t spatialMatrix) const
{
	complexVector_t antennaWeights;
	uint16_t antennaNum = spatialMatrix.at (0).size ();
	for (int i = 0; i< antennaNum; i++)
	{
		antennaWeights.push_back(spatialMatrix.at (0).at (i)/sqrt(antennaNum));
	}

	for(int iter = 0; iter<10; iter++)
	{
		complexVector_t antennaWeights_New;

		for(unsigned pathIndex = 0; pathIndex<spatialMatrix.size (); pathIndex++)
		{
			std::complex<double> sum;
			for (int i = 0; i< antennaNum; i++)
			{
				sum += std::conj(spatialMatrix.at (pathIndex).at (i))*antennaWeights.at (i);
			}

			for (int i = 0; i< antennaNum; i++)
			{
				if(pathIndex ==0)
				{
					antennaWeights_New.push_back(PowerSpread[pathIndex]*spatialMatrix.at (pathIndex).at (i)*sum);
				}
				else
				{
					antennaWeights_New.at (i) += PowerSpread[pathIndex]*spatialMatrix.at (pathIndex).at (i)*sum;
				}
			}
		}
		//normalize antennaWeights;
		double weightSum = 0;
		for (int i = 0; i< antennaNum; i++)
		{
			weightSum += pow (std::abs(antennaWeights_New. at(i)),2);
		}
		for (int i = 0; i< antennaNum; i++)
		{
			antennaWeights_New. at(i) = antennaWeights_New. at(i)/sqrt(weightSum);
		}
		antennaWeights = antennaWeights_New;
	}
	return antennaWeights;
}
*/


complex2DVector_t
MmWaveChannelMatrix::GenSpatialMatrix (std::vector<uint16_t> cluster, Angles angle, uint8_t* antennaNum) const
{
	complex2DVector_t spatialMatrix;
	for(unsigned int clusterIndex = 0; clusterIndex < cluster.size (); clusterIndex++)
	{
		double azimuthAngle;
		double verticalAngle;
		if (clusterIndex == 0)
		{
			//directed cluster
			azimuthAngle = angle.phi;
			verticalAngle = angle.theta;
		}
		else
		{
			//reflected cluster
			azimuthAngle = m_uniformRv->GetValue (-1*M_PI,M_PI);
			verticalAngle = angle.theta;
		}
		for(int subpathIndex = 0; subpathIndex < cluster. at (clusterIndex); subpathIndex++)
		{
			complexVector_t singlePath;
			double subpathAngle = m_expRv->GetValue (0.178,0.7)/2;
			singlePath = GenSinglePath (azimuthAngle+std::pow(-1,subpathIndex)*subpathAngle, verticalAngle, antennaNum);
			spatialMatrix.push_back(singlePath);
		}
	}
	return spatialMatrix;
}


complexVector_t
MmWaveChannelMatrix::GenSinglePath (double hAngle, double vAngle, uint8_t* antennaNum) const
{
	NS_LOG_FUNCTION (this);
	complexVector_t singlePath;
	uint16_t vSize = antennaNum[0];
	uint16_t hSize = antennaNum[1];

	for (int vIndex = 0; vIndex < vSize; vIndex++)
	{
		for (int hIndex =0; hIndex < hSize; hIndex++)
		{
			double w = (-2)*M_PI*hIndex*m_antennaSeparation*cos(hAngle)
										+ (-2)*M_PI*vIndex*m_antennaSeparation*cos(vAngle);
			singlePath.push_back (std::complex<double> (cos (w), sin (w)));
		}
	}
	return singlePath;
}

Ptr<SpectrumValue>
MmWaveChannelMatrix::GetChannelGain (Ptr<const SpectrumValue> txPsd, Ptr<mmWaveBeamFormingParams> bfParams, double speed) const
{
	NS_LOG_FUNCTION (this);

	NS_ASSERT(bfParams->m_channelParams->m_rxSpatialMatrix.size () == bfParams->m_channelParams->m_txSpatialMatrix.size ());
	uint16_t pathNum = bfParams->m_channelParams->m_txSpatialMatrix.size ();
	Time time = Simulator::Now ();
	double t = time.GetSeconds ();
	Ptr<SpectrumValue> tempPsd = Copy<SpectrumValue> (txPsd);

	Values::iterator vit = tempPsd->ValuesBegin ();
	uint16_t iSubband = 0;

	bool noSpeed = false;
	if (speed == 0)
	{
		noSpeed = true;
	}

	while (vit != tempPsd->ValuesEnd ())
	{
		std::complex<double> subsbandGain (0.0,0.0);
		if ((*vit) != 0.00)
		{
			double fsb = m_phyMacConfig->GetCenterFrequency () - GetSystemBandwidth ()/2 + m_phyMacConfig->GetChunkWidth ()*iSubband ;
			for (unsigned int pathIndex = 0; pathIndex < pathNum; pathIndex++)
			{

				std::complex<double> doppler;
				if (noSpeed)
				{
					doppler = std::complex<double> (1,0);
				}
				else
				{
					double f_d = speed*m_phyMacConfig->GetCenterFrequency ()/3e8;
					double temp_Doppler = 2*M_PI*t*f_d*bfParams->m_channelParams->m_doppler.at (pathIndex);
					doppler = std::complex<double> (cos (temp_Doppler), sin (temp_Doppler));
				}

				double temp_delay = -2*M_PI*fsb*bfParams->m_channelParams->m_delaySpread.at (pathIndex);
				std::complex<double> delay (cos (temp_delay), sin (temp_delay));

				std::complex<double> smallScaleFading = sqrt(bfParams->m_channelParams->m_powerFraction. at(pathIndex))*doppler*delay;

				if(bfParams->m_txW.empty ()||bfParams->m_rxW.empty ())
				{
					/*antenna weights is empty, siso*/
					subsbandGain = subsbandGain + smallScaleFading;
				}
				else
				{
					/* beam forming*/
					std::complex<double> txSum, rxSum;
					for (unsigned i = 0; i < bfParams->m_txW.size (); i++)
					{
						txSum += std::conj(bfParams->m_channelParams->m_txSpatialMatrix.at (pathIndex).at (i))*bfParams->m_txW.at (i);
					}
					for (unsigned i = 0; i < bfParams->m_rxW.size (); i++)
					{
						rxSum += bfParams->m_channelParams->m_rxSpatialMatrix.at (pathIndex). at (i)*std::conj(bfParams->m_rxW.at (i));
					}
					subsbandGain = subsbandGain + txSum*rxSum*smallScaleFading;
				}
			}
			*vit = (*vit)*(norm (subsbandGain));
		}
		vit++;
		iSubband++;
	}
	return tempPsd;
}

double
MmWaveChannelMatrix::GetSystemBandwidth () const
{
	double bw = 0.00;
	bw = m_phyMacConfig->GetChunkWidth () * m_phyMacConfig->GetNumChunkPerRb () * m_phyMacConfig->GetNumRb ();
	return bw;
}


Ptr<SpectrumValue>
MmWaveChannelMatrix::CalcRxPowerSpectralDensity(Ptr<const SpectrumValue> txPsd,
	                                                   Ptr<const MobilityModel> a,
	                                                   Ptr<const MobilityModel> b) const
{
	return DoCalcRxPowerSpectralDensity(txPsd, a, b);
}

} // namespace mmwave

} // namespace ns3
