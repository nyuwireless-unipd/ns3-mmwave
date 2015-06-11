/*
 * mmwave-enb-mac.cc
 *
 *  Created on: Jan 7, 2015
 *      Author: sourjya
 */


#include "mmwave-mac.h"

#include <ns3/object-factory.h>
#include <ns3/log.h>
#include "mmwave-radio-bearer-tag.h"
#include "mmwave-phy-sap.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("mmWaveMac");

NS_OBJECT_ENSURE_REGISTERED (mmWaveMac);

mmWaveMac::mmWaveMac ()
{
	m_macQueue = CreateObject <PacketBurst> ();
}

mmWaveMac::~mmWaveMac ()
{

}


void
mmWaveMac::SetCofigurationParameters (Ptr<mmWavePhyMacCommon> ptrConfig)
{
	m_PhyMACConfig = ptrConfig;
}

Ptr<mmWavePhyMacCommon>
mmWaveMac::GetConfigurationParameters (void) const
{
	return m_PhyMACConfig;
}

bool
mmWaveMac::QueueData (Ptr<Packet> packet)
{
	NS_LOG_INFO ("Queue in Mac");

	m_macQueue->AddPacket (packet);

	return true;
}

Ptr<PacketBurst>
mmWaveMac::GetPacketBurstFromMacQueue ()
{
	NS_LOG_FUNCTION (this);

	Ptr<PacketBurst> pb = CreateObject <PacketBurst> ();
	if (m_macQueue->GetNPackets () > 0)
	{
		pb = m_macQueue->Copy ();
		m_macQueue->Dispose ();
		m_macQueue = CreateObject <PacketBurst> ();
	}

	return pb;
}


}
