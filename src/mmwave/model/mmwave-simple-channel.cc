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
 *   Author: Michele Polese
 *   		<michele.polese@gmail.com>
 */


#include "mmwave-simple-channel.h"
#include <limits>
#include <ns3/log.h>
#include <ns3/math.h>
#include <ns3/simulator.h>
#include <ns3/mmwave-phy.h>
#include <ns3/mmwave-net-device.h>
#include <ns3/node.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mc-ue-net-device.h>
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/mmwave-ue-phy.h>
#include <ns3/mmwave-enb-phy.h>
#include <ns3/double.h>
#include <algorithm>
#include <random>       // std::default_random_engine
#include <ns3/boolean.h>
#include <ns3/integer.h>
#include "mmwave-spectrum-value-helper.h"
#include <iomanip>

namespace ns3 {

namespace mmwave {

NS_LOG_COMPONENT_DEFINE ("MmWaveSimpleChannel");

NS_OBJECT_ENSURE_REGISTERED (MmWaveSimpleChannel);


MmWaveSimpleChannel::MmWaveSimpleChannel ()
	// :m_antennaSeparation(0.5)
{
}

TypeId
MmWaveSimpleChannel::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::MmWaveSimpleChannel")
	.SetParent<Object> ()
	.AddAttribute ("mLos",
                   "m for LOS fading. Default is 3 as in Bai, Heath, Coverage and Rate"
                   "Analysis for mmWave Cellular Networks",
                   DoubleValue (3),
                   MakeDoubleAccessor (&MmWaveSimpleChannel::m_nakaParamLos),
                   MakeDoubleChecker<double> ())
	.AddAttribute ("mNlos",
                   "m for NLOS fading. Default is 2 as in Bai, Heath, Coverage and Rate"
                   "Analysis for mmWave Cellular Networks",
                   DoubleValue (2),
                   MakeDoubleAccessor (&MmWaveSimpleChannel::m_nakaParamNlos),
                   MakeDoubleChecker<double> ())
	.AddAttribute("DisableFadingBeamforming",
				   "Disable the beamforming and the fading, useful for pathloss testing",
				   BooleanValue(false),
				   MakeBooleanAccessor (&MmWaveSimpleChannel::m_disableFadingBeamforming),
				   MakeBooleanChecker())
	.AddAttribute("QuantizeBeamforming",
				   "Do not use the optimal direction for BF but quantize the available bins",
				   BooleanValue(true),
				   MakeBooleanAccessor (&MmWaveSimpleChannel::m_quantizeBeams),
				   MakeBooleanChecker())
	.AddAttribute("UpdatePeriodicity",
				  "Periodicity of BF udpates",
 	  			   TimeValue (MilliSeconds (20)),
				   MakeTimeAccessor (&MmWaveSimpleChannel::m_updatePeriodicity),
				   MakeTimeChecker())
	;
	return tid;
}

MmWaveSimpleChannel::~MmWaveSimpleChannel ()
{

}

void
MmWaveSimpleChannel::DoDispose ()
{
	NS_LOG_FUNCTION (this);
}

void
MmWaveSimpleChannel::DoInitialize()
{
	// LOS fading
	m_nakaLosFading = CreateObject<NakagamiPropagationLossModel>();
	// consider a single distance
	m_nakaLosFading->SetAttribute("Distance1", DoubleValue(std::numeric_limits<double>::max()));
	m_nakaLosFading->SetAttribute("Distance2", DoubleValue(std::numeric_limits<double>::max()));
	m_nakaLosFading->SetAttribute("m0", DoubleValue(m_nakaParamLos));
	m_nakaLosFading->SetAttribute("m1", DoubleValue(m_nakaParamLos));
	m_nakaLosFading->SetAttribute("m2", DoubleValue(m_nakaParamLos));

	// NLOS fading
	m_nakaNlosFading = CreateObject<NakagamiPropagationLossModel>();
	// consider a single distance
	m_nakaNlosFading->SetAttribute("Distance1", DoubleValue(std::numeric_limits<double>::max()));
	m_nakaNlosFading->SetAttribute("Distance2", DoubleValue(std::numeric_limits<double>::max()));
	m_nakaNlosFading->SetAttribute("m0", DoubleValue(m_nakaParamNlos));
	m_nakaNlosFading->SetAttribute("m1", DoubleValue(m_nakaParamNlos));
	m_nakaNlosFading->SetAttribute("m2", DoubleValue(m_nakaParamNlos));
}

void
MmWaveSimpleChannel::SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig)
{
	m_phyMacConfig = ptrConfig;
}

Ptr<MmWavePhyMacCommon>
MmWaveSimpleChannel::GetConfigurationParameters (void) const
{
	return m_phyMacConfig;
}


void
MmWaveSimpleChannel::ConnectDevices (Ptr<NetDevice> dev1, Ptr<NetDevice> dev2)
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
MmWaveSimpleChannel::Initial(NetDeviceContainer ueDevices, NetDeviceContainer enbDevices)
{

	NS_LOG_INFO (&ueDevices<<&enbDevices);

	for (NetDeviceContainer::Iterator i = ueDevices.Begin(); i != ueDevices.End(); i++)
	{
		for (NetDeviceContainer::Iterator j = enbDevices.Begin(); j != enbDevices.End(); j++)
		{
			// get the mobility objects
			Ptr<const MobilityModel> a = (*j)->GetNode()->GetObject<MobilityModel> ();
			Ptr<const MobilityModel> b = (*i)->GetNode()->GetObject<MobilityModel> ();
			NS_LOG_INFO("a " << a << " b " << b);

			Angles enbAngle (b->GetPosition (), a->GetPosition ());
			Angles ueAngle (a->GetPosition (), b->GetPosition ());

			SetBeamformingVector(*i,*j, ueAngle, enbAngle);

			// initialize the pathloss and channel condition
			if (DynamicCast<MmWave3gppPropagationLossModel> (m_3gppPathloss)!=0)
			{
				m_3gppPathloss->GetObject<MmWave3gppPropagationLossModel> ()
						->GetLoss(a->GetObject<MobilityModel>(),b->GetObject<MobilityModel>());
			}			// the GetObject trick is a trick against the const keyword
			else if (DynamicCast<MmWave3gppBuildingsPropagationLossModel> (m_3gppPathloss)!=0)
			{
				m_3gppPathloss->GetObject<MmWave3gppBuildingsPropagationLossModel> ()
						->GetLoss(a->GetObject<MobilityModel>(),b->GetObject<MobilityModel>());
			}
			else
			{
				NS_FATAL_ERROR("unknow pathloss model");
			}


			// std::vector<int> listOfSubchannels;
			// for (unsigned subChannelIndex = 0; subChannelIndex < m_phyMacConfig->GetTotalNumChunk(); subChannelIndex++)
			// {
			// 	listOfSubchannels.push_back(subChannelIndex);
			// }

			// Ptr<const SpectrumValue> fakePsd =
			// 	MmWaveSpectrumValueHelper::CreateTxPowerSpectralDensity (m_phyMacConfig, 0, listOfSubchannels);
			// DoCalcRxPowerSpectralDensity(fakePsd, a, b);

		}
	}
}

Ptr<SpectrumValue>
MmWaveSimpleChannel::DoCalcRxPowerSpectralDensity (Ptr<const SpectrumValue> txPsd,
                                                   Ptr<const MobilityModel> a,
                                                   Ptr<const MobilityModel> b) const
{
	NS_LOG_INFO(" ");

	// we want be able to test different models of small scale fading as well as
	// beamforming models
	NS_LOG_FUNCTION (this);
	Ptr<SpectrumValue> rxPsd = Copy (txPsd);

	if(m_disableFadingBeamforming)
	{
		return rxPsd; // do nothing
	}

	Ptr<AntennaArrayModel> txAntennaArray, rxAntennaArray;

	auto returnParams = GetTxRxInfo(a, b);

	uint16_t txAntennaNum[2];
	txAntennaNum[0] = std::get<0>(returnParams);
	txAntennaNum[1] = std::get<1>(returnParams);
	uint16_t rxAntennaNum[2];
	rxAntennaNum[0] = std::get<2>(returnParams);
	rxAntennaNum[1] = std::get<3>(returnParams);
	txAntennaArray = std::get<4>(returnParams);
	rxAntennaArray = std::get<5>(returnParams);
	bool connectedPair = std::get<6>(returnParams);
	bool d2dOrBackhaul = std::get<7>(returnParams);
	Angles txAngle = std::get<8>(returnParams);
	Angles rxAngle = std::get<9>(returnParams);
	complexVector_t txBfVector = std::get<10>(returnParams);
	complexVector_t rxBfVector = std::get<11>(returnParams);

	if(d2dOrBackhaul)
	{
		// skip
		return rxPsd;
	}

	NS_LOG_INFO("txAntennaNum " << txAntennaNum[0] << " x " << txAntennaNum[1]
		<< " rxAntennaNum " << rxAntennaNum[0] << " x " << rxAntennaNum[1]);

	NS_LOG_INFO("connectedPair " << connectedPair);

	// get the channel condition
	char condition;
	if (DynamicCast<MmWave3gppPropagationLossModel> (m_3gppPathloss)!=0)
	{
		condition = m_3gppPathloss->GetObject<MmWave3gppPropagationLossModel> ()
				->GetChannelCondition(a->GetObject<MobilityModel>(),b->GetObject<MobilityModel>());
	}
	else if (DynamicCast<MmWave3gppBuildingsPropagationLossModel> (m_3gppPathloss)!=0)
	{
		condition = m_3gppPathloss->GetObject<MmWave3gppBuildingsPropagationLossModel> ()
				->GetChannelCondition(a->GetObject<MobilityModel>(),b->GetObject<MobilityModel>());
	}
	else
	{
		NS_FATAL_ERROR("unkonw pathloss model");
	}
	bool los = false;
	// bool o2i = false;
	if(condition == 'l')
	{
		los = true;
	}
	else if(condition == 'i')
	{
		NS_FATAL_ERROR("Not supported");
	}
	else if(condition == 's')
	{
		NS_FATAL_ERROR("Not supported");
	}

	NS_LOG_INFO("los " << los);

	// compute the fading
	// we assume the fading to be the same for the whole band, as in the literature
	// compute the fading as nakagami-m with the parameters already specified,
	// and use average power equal to 1 since the pathloss is applied in another
	// class
	double fadingDbm = 1;

	// the CalcRxPower accepts the power in dBm as the first parameter, then converts
	// it in watt and uses this power in the nakagami fading computation. Thus in order
	// to have the power in watt = 1 we need 30 dBm
	// TODO consider using directly the Gamma or Erlang random variables
	if(los)
	{
		fadingDbm = m_nakaLosFading->CalcRxPower(30, a->GetObject<MobilityModel>(), b->GetObject<MobilityModel>());
	}
	else
	{
		fadingDbm = m_nakaNlosFading->CalcRxPower(30, a->GetObject<MobilityModel>(), b->GetObject<MobilityModel>());
	}
	// we want dBW
	double fadingDbw = fadingDbm - 30;

	NS_LOG_INFO("fadingDbw " << fadingDbw);

	double bfGainLin;

	// compute the beamforming
	// compute it for all the links, the BF vector is set correctly only for the connected devices
	//if(connectedPair)
	//{
		bfGainLin = ComputeBfGain(txAngle, rxAngle, txBfVector, rxBfVector, txAntennaNum[0], rxAntennaNum[0]);
	//}

	NS_LOG_DEBUG("bfGainDb " << 10*std::log10(bfGainLin) << " fadingDbw " << fadingDbw
		<< " connectedPair " << connectedPair << " txAngle " << txAngle << " rxAngle " << rxAngle);

	(*rxPsd) *= std::pow(10, fadingDbw/10)*bfGainLin;

	NS_LOG_INFO(" ");

	return rxPsd;
}

std::tuple<uint16_t, uint16_t, uint16_t, uint16_t, Ptr<AntennaArrayModel>,
Ptr<AntennaArrayModel>, bool, bool, Angles, Angles, complexVector_t, complexVector_t>
MmWaveSimpleChannel::GetTxRxInfo(Ptr<MobilityModel const> a, Ptr<MobilityModel const> b) const
{
	Ptr<NetDevice> txDevice = a->GetObject<Node> ()->GetDevice (0);
	Ptr<NetDevice> rxDevice = b->GetObject<Node> ()->GetDevice (0);

	Angles txAngle (b->GetPosition (), a->GetPosition ());
	Angles rxAngle (a->GetPosition (), b->GetPosition ());

	NS_LOG_INFO("a in position " << a->GetPosition () << " b " << b->GetPosition () <<
		" txAngle " << txAngle << " rxAngle " << rxAngle);

	Ptr<MmWaveEnbNetDevice> txEnb =
					DynamicCast<MmWaveEnbNetDevice> (txDevice);
	Ptr<MmWaveUeNetDevice> rxUe =
					DynamicCast<MmWaveUeNetDevice> (rxDevice);

	Ptr<AntennaArrayModel> txAntennaArray, rxAntennaArray;

	uint16_t txAntennaNum[2];
	uint16_t rxAntennaNum[2];

	bool connectedPair = false;
	bool d2dOrBackhaul = false;

	complexVector_t txBfVector;
	complexVector_t rxBfVector;

	// get tx and rx info
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

		NS_LOG_INFO("target " << txEnb << " " << rxUe->GetTargetEnb());
		NS_LOG_INFO("antenna " << txAntennaArray->GetCurrentDevice() << " " << rxUe);
		if(txEnb == rxUe->GetTargetEnb() && txAntennaArray->GetCurrentDevice() == rxUe)
		{
			connectedPair = true;
			if(rxAntennaArray->GetLastUpdate(txEnb) + m_updatePeriodicity < Simulator::Now()) // consider UE's antenna
			{
				NS_LOG_INFO("Update for devices " << txEnb << " " << rxUe << " " << rxAntennaArray->GetLastUpdate(txEnb).GetSeconds()
					<< " " << m_updatePeriodicity.GetSeconds() << " " << Simulator::Now().GetSeconds());
				SetBeamformingVector(rxUe, txEnb, rxAngle, txAngle); // UE, eNB, ueAngle, enbAngle
			}
		}

		// get the BF vectors associated to this UE and eNB (either in a connected or a non connected state)
		txBfVector = txAntennaArray->GetBeamformingVector(); // it is the one of the active link
		rxBfVector = rxAntennaArray->GetBeamformingVector();
		// TODO check what happens if they are not connected!!!

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

			if(txEnb == mcRxUe->GetMmWaveTargetEnb() && txAntennaArray->GetCurrentDevice() == mcRxUe) // TODO also check the current dev
			{
				connectedPair = true;
				if(rxAntennaArray->GetLastUpdate(txEnb) + m_updatePeriodicity < Simulator::Now()) // consider UE's antenna
				{
					NS_LOG_INFO("Update for devices " << txEnb << " " << mcRxUe << " " << rxAntennaArray->GetLastUpdate(txEnb).GetSeconds()
						<< " " << m_updatePeriodicity.GetSeconds() << " " << Simulator::Now().GetSeconds());
					SetBeamformingVector(mcRxUe, txEnb, rxAngle, txAngle); // UE, eNB, ueAngle, enbAngle
				}
			}

			// get the BF vectors associated to this UE and eNB (either in a connected or a non connected state)
			rxBfVector = rxAntennaArray->GetBeamformingVector(); // it is the one of the active link
			txBfVector = txAntennaArray->GetBeamformingVector();
			// TODO check what happens if they are not connected!!!
		}
		else
		{
			NS_LOG_INFO ("enb to enb or ue to ue transmission, skip beamforming");
			d2dOrBackhaul = true;
		}
	}
	else if (txEnb==0 && rxUe==0 )
	{
		Ptr<MmWaveUeNetDevice> txUe =
						DynamicCast<MmWaveUeNetDevice> (txDevice);
		Ptr<MmWaveEnbNetDevice> rxEnb =
						DynamicCast<MmWaveEnbNetDevice> (rxDevice);
		if (txUe != 0 && rxEnb !=0)
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
			NS_LOG_INFO("target " << rxEnb << " " << txUe->GetTargetEnb());
			NS_LOG_INFO("antenna " << rxAntennaArray->GetCurrentDevice() << " " << txUe);

			if(rxEnb == txUe->GetTargetEnb() && rxAntennaArray->GetCurrentDevice() == txUe)
			{
				connectedPair = true;
				if(txAntennaArray->GetLastUpdate(rxEnb) + m_updatePeriodicity < Simulator::Now()) // consider UE's antenna
				{
					NS_LOG_INFO("Update for devices " << rxEnb << " " << txUe << " " << txAntennaArray->GetLastUpdate(rxEnb).GetSeconds()
						<< " " << m_updatePeriodicity.GetSeconds() << " " << Simulator::Now().GetSeconds());
					SetBeamformingVector(txUe, rxEnb, txAngle, rxAngle); // UE, eNB, ueAngle, enbAngle
				}
			}

			// get the BF vectors associated to this UE and eNB (either in a connected or a non connected state)
			txBfVector = txAntennaArray->GetBeamformingVector(); // it is the one of the active link
			rxBfVector = rxAntennaArray->GetBeamformingVector();
			// TODO check what happens if they are not connected!!!
		}
		else if (txUe == 0 && rxEnb != 0)
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

				if(rxEnb == mcTxUe->GetMmWaveTargetEnb() && rxAntennaArray->GetCurrentDevice() == mcTxUe)
				{
					connectedPair = true;
					if(txAntennaArray->GetLastUpdate(rxEnb) + m_updatePeriodicity < Simulator::Now()) // consider UE's antenna
					{
						NS_LOG_INFO("Update for devices " << rxEnb << " " << mcTxUe << " " << txAntennaArray->GetLastUpdate(rxEnb).GetSeconds()
							<< " " << m_updatePeriodicity.GetSeconds() << " " << Simulator::Now().GetSeconds());
						SetBeamformingVector(mcTxUe, rxEnb, txAngle, rxAngle); // UE, eNB, ueAngle, enbAngle
					}
				}

				// get the BF vectors associated to this UE and eNB (either in a connected or a non connected state)
				txBfVector = txAntennaArray->GetBeamformingVector(); // it is the one of the active link
				rxBfVector = rxAntennaArray->GetBeamformingVector();
				// TODO check what happens if they are not connected!!!
			}
			else
			{
				NS_LOG_INFO ("enb to enb or ue to ue transmission, skip beamforming");
				d2dOrBackhaul = true;
			}
		}

	}
	else
	{
		NS_LOG_INFO ("enb to enb or ue to ue transmission, skip beamforming");
		d2dOrBackhaul = true;
	}

	return std::make_tuple(txAntennaNum[0], txAntennaNum[1], rxAntennaNum[0], rxAntennaNum[1],
		txAntennaArray, rxAntennaArray, connectedPair, d2dOrBackhaul, txAngle, rxAngle, txBfVector, rxBfVector);
}

Ptr<SpectrumValue>
MmWaveSimpleChannel::CalcRxPowerSpectralDensity(Ptr<const SpectrumValue> txPsd,
	                                                   Ptr<const MobilityModel> a,
	                                                   Ptr<const MobilityModel> b) const
{
	return DoCalcRxPowerSpectralDensity(txPsd, a, b);
}

void
MmWaveSimpleChannel::SetPathlossModel (Ptr<PropagationLossModel> pathloss)
{
	m_3gppPathloss = pathloss;
}

void
MmWaveSimpleChannel::SetBeamformingVector (Ptr<NetDevice> ueDevice, Ptr<NetDevice> enbDevice, Angles ueAngle, Angles enbAngle) const
{
	key_t key = std::make_pair(ueDevice,enbDevice);
	Ptr<MmWaveEnbNetDevice> EnbDev =
				DynamicCast<MmWaveEnbNetDevice> (enbDevice);
	Ptr<MmWaveUeNetDevice> UeDev =
				DynamicCast<MmWaveUeNetDevice> (ueDevice);
	if(UeDev != 0)
	{
		NS_LOG_INFO("SetBeamformingVector between UE " << ueDevice << " and enbDevice " << enbDevice);
		Ptr<AntennaArrayModel> ueAntennaArray = DynamicCast<AntennaArrayModel> (
				UeDev->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
		Ptr<AntennaArrayModel> enbAntennaArray = DynamicCast<AntennaArrayModel> (
				EnbDev->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());

		// TODO compute and set the BF vector
		{
			// update the BF vector
			complexVector_t ueBfVector = ComputeBfVector(UeDev->GetAntennaNum(), ueAngle); // steering angle = LOS angle
			complexVector_t enbBfVector = ComputeBfVector(EnbDev->GetAntennaNum(), enbAngle);

			ueAntennaArray->SetBeamformingVector (ueBfVector,enbDevice);
			enbAntennaArray->SetBeamformingVector (enbBfVector,ueDevice);
		}

	}
	else
	{
		Ptr<McUeNetDevice> UeDev =
				DynamicCast<McUeNetDevice> (ueDevice);
		if(UeDev != 0)
		{
			NS_LOG_INFO("SetBeamformingVector between UE " << ueDevice << " and enbDevice " << enbDevice);
			Ptr<AntennaArrayModel> ueAntennaArray = DynamicCast<AntennaArrayModel> (
					UeDev->GetMmWavePhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
			Ptr<AntennaArrayModel> enbAntennaArray = DynamicCast<AntennaArrayModel> (
					EnbDev->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
			complexVector_t dummy;

			// compute and set the BF vector
			{
				// update the BF vector
				complexVector_t ueBfVector = ComputeBfVector(UeDev->GetAntennaNum(), ueAngle); // steering angle = LOS angle
				complexVector_t enbBfVector = ComputeBfVector(EnbDev->GetAntennaNum(), enbAngle);

				ueAntennaArray->SetBeamformingVector (ueBfVector,enbDevice);
				enbAntennaArray->SetBeamformingVector (enbBfVector,ueDevice);
			}
		}
		else
		{
			NS_FATAL_ERROR("Unrecognized pair of devices");
		}
	}
}

complexVector_t
MmWaveSimpleChannel::ComputeBfVector(uint16_t antennaNum, Angles steeringAngle) const
{
	uint16_t rowNum = sqrt(antennaNum);
	uint16_t colNum = rowNum;

	double phi;
	double theta;

	if(m_quantizeBeams)
	{
		// quantization
		// number of bins
		// NS_LOG_DEBUG("numBins " << antennaNum);
		double binWidth = 360/antennaNum;
		// NS_LOG_DEBUG("binWidth " << binWidth);
		double binWidthRad = binWidth*M_PI/180;

		int indexBeamPhi = std::round(steeringAngle.phi/binWidthRad);
		int indexBeamTheta = std::round(steeringAngle.theta/binWidthRad);

		// NS_LOG_DEBUG("indexBeamPhi " << indexBeamPhi << " indexBeamTheta " << indexBeamTheta);

		phi = binWidthRad * indexBeamPhi;
		theta = binWidthRad * indexBeamTheta;

		// NS_LOG_DEBUG("original angle PHI " << steeringAngle.phi*180/M_PI << " new angle " << phi*180/M_PI);
		// NS_LOG_DEBUG("original angle THETA " << steeringAngle.theta*180/M_PI << " new angle " << theta*180/M_PI);
	}
	else
	{
		phi = steeringAngle.phi;
		theta = steeringAngle.theta;
	}



	double sinPhi = std::sin(phi);
	double sinTheta = std::sin(theta);
	double cosTheta = std::cos(theta);

	double sinProduct = sinTheta*sinPhi;

	complexVector_t w;

	for (uint16_t p = 0; p < rowNum; ++p)
	{
		for (uint16_t r = 0; r < colNum; ++r)
		{
			double expTerm = -M_PI*(p*cosTheta + r*sinProduct); // a *2 factor simplifies with the 0.5 = Delta/Lambda antenna spacing
			w.push_back(exp(std::complex<double> (0, expTerm))/(double)rowNum);
		}
	}
	NS_ASSERT_MSG(w.size() == antennaNum, "BF with the wrong size");

	return w;
}

double
MmWaveSimpleChannel::ComputeBfGain(Angles txAngle, Angles rxAngle, complexVector_t txBfVector, complexVector_t rxBfVector, uint16_t txNumCol, uint16_t rxNumCol) const
{
	// we need the spatial signature
	// for now we can assume that the steering angle corresponds to the LOS direction,
	// but the update rate of the vector w is limited
	double phiTx = txAngle.phi;
	double phiRx = rxAngle.phi;
	double thetaTx = txAngle.theta;
	double thetaRx = rxAngle.theta;

	// double m_antennaSeparation = 0.5;
	// we also assume that the antennas have the same number of elements in the horizontal and vertical directions
	// we use a fixed rho = 1

	// compute cos and sin just once
	double sinPhiTx = std::sin(phiTx);
	double sinPhiRx = std::sin(phiRx);
	double sinThetaTx = std::sin(thetaTx);
	double sinThetaRx = std::sin(thetaRx);
	double sinProductTx = sinThetaTx*sinPhiTx;
	double sinProductRx = sinThetaRx*sinPhiRx;
	double cosThetaTx = std::cos(thetaTx);
	double cosThetaRx = std::cos(thetaRx);

	complexVector_t ssTx;
	for (uint16_t p = 0; p < txNumCol; ++p)
	{
		for (uint16_t r = 0; r < txNumCol; ++r)
		{
			double expTerm = M_PI*(p*cosThetaTx + r*sinProductTx); // a *2 factor simplifies with the 0.5 = Delta/Lambda antenna spacing
			ssTx.push_back(exp(std::complex<double> (0, expTerm)));
		}
	}
	NS_ASSERT_MSG(ssTx.size() == txBfVector.size(), "BF with the wrong size");

	//auto iter = txBfVector.begin();
	NS_LOG_LOGIC("Tx BF");
	for(auto iter : txBfVector)
	{
		NS_LOG_LOGIC(iter);
	}
	NS_LOG_LOGIC("Tx Spatial signature");
	for(auto iter : ssTx)
	{
		NS_LOG_LOGIC(iter);
	}
	// NS_LOG_INFO(txBfVector);
	// NS_LOG_INFO(ssTx);

	std::complex<double> txVectorProduct = 0;
	uint16_t txTotAntennas = txBfVector.size();
	for (uint16_t p = 0; p < txTotAntennas; ++p)
	{
		NS_LOG_LOGIC(p << " " << ssTx.at(p) << " " << txBfVector.at(p) << " " << ssTx.at(p) * txBfVector.at(p) << " " << txVectorProduct);
		txVectorProduct += ssTx.at(p) * txBfVector.at(p);
	}

	double linTxGain = std::pow(std::abs(txVectorProduct), 2);

	complexVector_t ssRx;
	for (uint16_t p = 0; p < rxNumCol; ++p)
	{
		for (uint16_t r = 0; r < rxNumCol; ++r)
		{
			double expTerm = M_PI*(p*cosThetaRx + r*sinProductRx); // a *2 factor simplifies with the 0.5 = Delta/Lambda antenna spacing
			ssRx.push_back(exp(std::complex<double> (0, expTerm)));
		}
	}
	NS_ASSERT_MSG(ssRx.size() == rxBfVector.size(), "BF with the wrong size");

	std::complex<double> rxVectorProduct = 0;
	uint16_t rxTotAntennas = rxBfVector.size();
	for (uint16_t p = 0; p < rxTotAntennas; ++p)
	{
		NS_LOG_LOGIC(p << " " << ssRx.at(p) << " " << rxBfVector.at(p) << " " << ssRx.at(p) * rxBfVector.at(p) << " " << rxVectorProduct);
		rxVectorProduct += ssRx.at(p) * rxBfVector.at(p);
	}

	double linRxGain = std::pow(std::abs(rxVectorProduct), 2);

	NS_LOG_DEBUG("txGain " << 10*std::log10(linTxGain) << " rxGain " << 10*std::log10(linRxGain));
	return linTxGain*linRxGain;


	// create static arrays with bf gain with enough granularity
	// for different steering directions
	// maybe also in a file and pre-load them in a intelligent way

	// vs

	// actually compute the bf gain with equations
}

} // namespace mmwave

}// namespace ns3
