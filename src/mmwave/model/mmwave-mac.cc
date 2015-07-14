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

NS_LOG_COMPONENT_DEFINE ("MmWaveMac");

NS_OBJECT_ENSURE_REGISTERED (MmWaveMac);

MmWaveMac::MmWaveMac ()
{
	m_macQueue = CreateObject <PacketBurst> ();
}

MmWaveMac::~MmWaveMac ()
{

}


void
MmWaveMac::SetCofigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig)
{
	m_phyMacConfig = ptrConfig;
}

Ptr<MmWavePhyMacCommon>
MmWaveMac::GetConfigurationParameters (void) const
{
	return m_phyMacConfig;
}

bool
MmWaveMac::QueueData (Ptr<Packet> packet)
{
	NS_LOG_INFO ("Queue in Mac");

	m_macQueue->AddPacket (packet);

	return true;
}

Ptr<PacketBurst>
MmWaveMac::GetPacketBurstFromMacQueue ()
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
