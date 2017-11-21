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

namespace ns3{

NS_LOG_COMPONENT_DEFINE ("MmWaveSimpleChannel");

NS_OBJECT_ENSURE_REGISTERED (MmWaveSimpleChannel);


MmWaveSimpleChannel::MmWaveSimpleChannel ()
	:m_antennaSeparation(0.5)
{
}

TypeId
MmWaveSimpleChannel::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::MmWaveSimpleChannel")
	.SetParent<Object> ()
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
MmWaveSimpleChannel::DoCalcRxPowerSpectralDensity (Ptr<const SpectrumValue> txPsd,
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
	Ptr<MmWaveUeNetDevice> rxUe =
					DynamicCast<MmWaveUeNetDevice> (rxDevice);

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
		Ptr<MmWaveUeNetDevice> txUe =
						DynamicCast<MmWaveUeNetDevice> (txDevice);
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


}



Ptr<SpectrumValue> 
MmWaveSimpleChannel::CalcRxPowerSpectralDensity(Ptr<const SpectrumValue> txPsd,
	                                                   Ptr<const MobilityModel> a,
	                                                   Ptr<const MobilityModel> b) const
{
	return DoCalcRxPowerSpectralDensity(txPsd, a, b);
}


}// namespace ns3
