/*
 * mmwave-phy-sap.h
 *
 *  Created on: Apr 14, 2015
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_PHY_SAP_H_
#define SRC_MMWAVE_MODEL_MMWAVE_PHY_SAP_H_

#include <ns3/packet-burst.h>
#include <ns3/mmwave-phy-mac-common.h>

namespace ns3 {

class MmWaveControlMessage;
/* Mac to Phy comm*/
class MmWavePhySapProvider
{
public:
	virtual ~MmWavePhySapProvider ();

	virtual void SendMacPdu (Ptr<Packet> p ) = 0;

	virtual void SendControlMessage (Ptr<MmWaveControlMessage> msg) = 0;

	virtual void SendRachPreamble(uint8_t PreambleId, uint8_t Rnti) = 0;
};

/* Phy to Mac comm */
class MmWavePhySapUser
{
public:
	virtual ~MmWavePhySapUser ();

	virtual void ReceivePhyPdu (Ptr<Packet> p) = 0;

	virtual void ReceiveControlMessage (Ptr<MmWaveControlMessage> msg) = 0;

	virtual void SubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo) = 0;

	virtual void CqiReport (DlCqiInfo cqi) = 0;

	virtual void ReceiveRachPreamble (uint32_t raId) = 0;
};
}



#endif /* SRC_MMWAVE_MODEL_MMWAVE_PHY_SAP_H_ */
