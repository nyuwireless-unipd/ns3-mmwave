/*
 * mmwave-ue-mac.h
 *
 *  Created on: May 1, 2015
 *      Author: root
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_UE_MAC_H_
#define SRC_MMWAVE_MODEL_MMWAVE_UE_MAC_H_

#include "mmwave-mac.h"
#include <ns3/lte-ue-cmac-sap.h>
#include <ns3/lte-mac-sap.h>
#include <ns3/lte-radio-bearer-tag.h>


namespace ns3
{
class MmWaveControlMessage;

class MmWaveUeMac : public Object
{
	friend class UeMemberMmWaveUeCmacSapProvider;
	friend class UeMemberMmWaveMacSapProvider;
	friend class MacUeMemberPhySapUser;

public:
	static TypeId GetTypeId (void);

	MmWaveUeMac (void);
	~MmWaveUeMac (void);
  virtual void DoDispose (void);

	void  SetUeCmacSapUser (LteUeCmacSapUser* s);
	LteUeCmacSapProvider*  GetUeCmacSapProvider (void);
	LteMacSapProvider*  GetUeMacSapProvider (void);

	void SetCofigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig);
	Ptr<MmWavePhyMacCommon> GetConfigurationParameters (void) const;

	void DoSubframeIndication (SfnSf sfn);

	MmWaveUePhySapUser* GetPhySapUser ();
	void SetPhySapProvider (MmWavePhySapProvider* ptr);

	void RecvRaResponse (BuildRarListElement_s raResponse);

private:

	void DoTransmitPdu (LteMacSapProvider::TransmitPduParameters params);
	void DoReportBufferStatus (LteMacSapProvider::ReportBufferStatusParameters params);

  // forwarded from PHY SAP
	void DoReceivePhyPdu (Ptr<Packet> p);
	void DoReceiveControlMessage  (Ptr<MmWaveControlMessage> msg);
	//void DoNotifyHarqDeliveryFailure (uint8_t harqId);

	// forwarded from UE CMAC SAP
	void DoConfigureRach (LteUeCmacSapProvider::RachConfig rc);
	void DoStartContentionBasedRandomAccessProcedure ();
	void DoStartNonContentionBasedRandomAccessProcedure (uint16_t rnti, uint8_t rapId, uint8_t prachMask);
	void AddLc (uint8_t lcId, LteUeCmacSapProvider::LogicalChannelConfig lcConfig, LteMacSapUser* msu);
	void DoRemoveLc (uint8_t lcId);
	void DoReset ();

	void RandomlySelectAndSendRaPreamble ();
	void SendRaPreamble (bool contention);
  void SendReportBufferStatus (void);
  void RefreshHarqProcessesPacketBuffer (void);

  std::map<uint32_t, struct MacPduInfo>::iterator AddToMacPduMap (DciInfoElementTdma dci, unsigned activeLcs);

	Ptr<MmWavePhyMacCommon> m_phyMacConfig;

	LteUeCmacSapUser* m_cmacSapUser;
	LteUeCmacSapProvider* m_cmacSapProvider;

	TddSlotTypeList m_DataTxTDDMap;
	SfAllocInfo m_DataTxAllocationList;

	MmWavePhySapProvider* m_phySapProvider;
	MmWaveUePhySapUser* m_phySapUser;
	LteMacSapProvider* m_macSapProvider;

	uint32_t m_frameNum;
	uint32_t m_sfNum;
	uint32_t m_slotNum;

	//uint8_t	m_tbUid;
	std::map<uint32_t, struct MacPduInfo> m_macPduMap;

	std::map <uint8_t, LteMacSapProvider::ReportBufferStatusParameters> m_ulBsrReceived; // BSR received from RLC (the last one)
	Time m_bsrPeriodicity;
	Time m_bsrLast;
	bool m_freshUlBsr; // true when a BSR has been received in the last TTI


	Ptr<UniformRandomVariable> m_raPreambleUniformVariable;
	uint8_t m_raPreambleId;
	uint8_t m_raRnti;

	struct UlHarqProcessInfo
		{
			Ptr<PacketBurst> m_pktBurst;
			// maintain list of LCs contained in this TB
			// used to signal HARQ failure to RLC handlers
			std::vector<uint8_t> m_lcidList;
		};

  //uint8_t m_harqProcessId;
  std::vector < UlHarqProcessInfo > m_miUlHarqProcessesPacket; // Packets under trasmission of the UL HARQ processes
  std::vector < uint8_t > m_miUlHarqProcessesPacketTimer; // timer for packet life in the buffer

	struct LcInfo
	{
		LteUeCmacSapProvider::LogicalChannelConfig lcConfig;
		LteMacSapUser* macSapUser;
	};

	std::map <uint8_t, LcInfo> m_lcInfoMap;
	uint16_t m_rnti;

	bool m_waitingForRaResponse;
	static uint8_t g_raPreambleId;

};

}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_UE_MAC_H_ */
