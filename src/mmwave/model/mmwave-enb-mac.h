/*
 * mmwave-enb-mac.h
 *
 *  Created on: May 1, 2015
 *      Author: root
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_ENB_MAC_H_
#define SRC_MMWAVE_MODEL_MMWAVE_ENB_MAC_H_

#include "mmwave-mac.h"
#include <ns3/lte-enb-cmac-sap.h>
#include <ns3/lte-mac-sap.h>


namespace ns3
{
class mmWaveEnbPhy;
class mmWaveMacScheduler;
class mmWaveControlMessages;

class mmWaveEnbMac : public mmWaveMac
{
	friend class EnbMacMemberLteEnbCmacSapProvider;

public:
	static TypeId GetTypeId (void);

	mmWaveEnbMac (void);
	virtual ~mmWaveEnbMac (void);
	virtual void DoDispose (void);

	// forwarded from LteMacSapProvider
	void DoTransmitPdu (LteMacSapProvider::TransmitPduParameters);
	void DoReportBufferStatus (LteMacSapProvider::ReportBufferStatusParameters);


	void DoSubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo);

	void AssociateUeMAC (uint64_t imsi);

	void SetForwardUpCallback (Callback <void, Ptr<Packet> > cb);

	void PhyPacketRx (Ptr<Packet> p);

	void DoReceivemmWaveControlMessage  (Ptr<mmWaveControlMessages> msg);

	void DoSchedConfigIndication (mmWaveMacSchedSapUser::SchedConfigIndParameters ind);

	mmWavePhySapUser* GetmmWavePhySapUser ();
	void SetmmWavePhySapProvider (mmWavePhySapProvider* ptr);

	mmWaveMacSchedSapUser* GetmmWaveMacSchedSapUser ();
	void SetmmWaveMacSchedSapProvider (mmWaveMacSchedSapProvider* ptr);

	LteMacSapProvider* GetmmWaveMacSapProvider (void);
	LteEnbCmacSapProvider* GetmmWaveEnbCmacSapProvider (void);
	void SetmmWaveEnbCmacSapUser (LteEnbCmacSapUser* s);
	void ReceiveRachPreamble (uint32_t raId);

private:
	// forwarded from LteEnbCmacSapProvider
	void DoConfigureMac (uint8_t ulBandwidth, uint8_t dlBandwidth);
	void DoAddUe (uint16_t rnti);
	void DoRemoveUe (uint16_t rnti);
	void DoAddLc (LteEnbCmacSapProvider::LcInfo lcinfo, LteMacSapUser* msu);
	void DoReconfigureLc (LteEnbCmacSapProvider::LcInfo lcinfo);
	void DoReleaseLc (uint16_t  rnti, uint8_t lcid);
	void DoUeUpdateConfigurationReq (LteEnbCmacSapProvider::UeConfig params);
	LteEnbCmacSapProvider::RachConfig DoGetRachConfig ();
	LteEnbCmacSapProvider::AllocateNcRaPreambleReturnValue DoAllocateNcRaPreamble (uint16_t rnti);

	LteMacSapProvider* m_macSapProvider;
	LteEnbCmacSapProvider* m_cmacSapProvider;
	LteEnbCmacSapUser* m_cmacSapUser;

	uint32_t m_frameNum;
	uint32_t m_sfNum;
	uint32_t m_slotNum;


	/* The MAC data queue is a map of Destination MAC Address, IMSI, Packet burst*/
	std::map <Ipv4Address, uint64_t> m_mac2imsimap;

	std::list <uint64_t> m_associatedUE;

	Callback <void, Ptr<Packet> > m_forwardUpCallback;

	std::vector <CqiInfo> m_ReceivedCqi;

	std::map <uint32_t, allocationList> m_scheduleMap;
	Schedule m_DataTxTDDMap;
	allocationList m_DataTxAllocationList;

	mmWavePhySapProvider* m_phySapProvider;
	mmWavePhySapUser* m_phySapUser;


	mmWaveMacSchedSapProvider* m_macSchedSapProvider;
	mmWaveMacSchedSapUser* m_macSchedSapUser;

	std::map<uint8_t, uint32_t> m_receivedRachPreambleCount;

	std::map <uint16_t, std::map<uint8_t, LteMacSapUser*> > m_rlcAttached;


};

}



#endif /* SRC_MMWAVE_MODEL_MMWAVE_ENB_MAC_H_ */
