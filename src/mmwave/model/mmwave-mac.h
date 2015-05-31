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
#include <map>
#include <list>
#include "mmwave-mac-sched-sap.h"
#include <ns3/lte-radio-bearer-tag.h>

namespace ns3 {

class mmWaveMac : public Object
{
public:
	/* Do not put the set TypeId function. */
	mmWaveMac ();
	~mmWaveMac ();

	void SetCofigurationParameters (Ptr<mmWavePhyMacCommon> ptrConfig);
	Ptr<mmWavePhyMacCommon> GetConfigurationParameters (void) const;

	bool QueueData (Ptr<Packet> packet);
	Ptr<PacketBurst> GetPacketBurstFromMacQueue ();

protected:
	Ptr<mmWavePhyMacCommon> m_PhyMACConfig;

	Ptr<PacketBurst>  m_macQueue;


};




}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAC_H_ */
