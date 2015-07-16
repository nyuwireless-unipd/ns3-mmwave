/*
 * mmwave-enb-mac.h
 *
 *  Created on: Jan 7, 2015
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_MAC_H_
#define SRC_MMWAVE_MODEL_MMWAVE_MAC_H_


#include <vector>
#include "mmwave-enb-phy.h"
#include "mmwave-phy-mac-common.h"
#include "mmwave-mac-scheduler.h"
#include "mmwave-control-messages.h"
#include <ns3/packet.h>
#include <ns3/packet-burst.h>
#include <ns3/lte-mac-sap.h>
#include <map>
#include <list>
#include "mmwave-mac-sched-sap.h"
#include <ns3/lte-radio-bearer-tag.h>

namespace ns3 {

class MmWaveMac : public Object
{
public:
	/* Do not put the set TypeId function. */
	MmWaveMac ();
	~MmWaveMac ();


	void SetCofigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig);
	Ptr<MmWavePhyMacCommon> GetConfigurationParameters (void) const;

	bool QueueData (Ptr<Packet> packet);
	Ptr<PacketBurst> GetPacketBurstFromMacQueue ();

protected:
	Ptr<MmWavePhyMacCommon> m_phyMacConfig;

	Ptr<PacketBurst>  m_macQueue;


};




}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAC_H_ */
