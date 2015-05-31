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
class mmWaveControlMessages;

class mmWaveUeMac : public mmWaveMac
{
	friend class UeMemberLteUeCmacSapProvider;
	friend class UeMemberLteMacSapProvider;
public:
	static TypeId GetTypeId (void);

	mmWaveUeMac (void);
	~mmWaveUeMac (void);

	void  SetmmWaveUeCmacSapUser (LteUeCmacSapUser* s);
	LteUeCmacSapProvider*  GetmmWaveUeCmacSapProvider (void);
	LteMacSapProvider*  GetmmWaveMacSapProvider (void);

	void DoSubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo);
	void DoReceivemmWaveControlMessage  (Ptr<mmWaveControlMessages> msg);

	mmWavePhySapUser* GetmmWavePhySapUser ();
	void SetmmWavePhySapProvider (mmWavePhySapProvider* ptr);

	void DoReceivePhyPdu (Ptr<Packet> p);

	void RecvRaResponse (BuildRarListElement_s raResponse);


private:

	void RandomlySelectAndSendRaPreamble ();
	void SendRaPreamble (bool contention);

	void DoTransmitPdu (LteMacSapProvider::TransmitPduParameters params);
	void DoReportBufferStatus (LteMacSapProvider::ReportBufferStatusParameters params);
	// forwarded from UE CMAC SAP
	void DoConfigureRach (LteUeCmacSapProvider::RachConfig rc);
	void DoStartContentionBasedRandomAccessProcedure ();
	void DoStartNonContentionBasedRandomAccessProcedure (uint16_t rnti, uint8_t rapId, uint8_t prachMask);
	void DoAddLc (uint8_t lcId, LteUeCmacSapProvider::LogicalChannelConfig lcConfig, LteMacSapUser* msu);
	void DoRemoveLc (uint8_t lcId);
	void DoReset ();
	LteUeCmacSapUser* m_cmacSapUser;
	LteUeCmacSapProvider* m_cmacSapProvider;

	Schedule m_DataTxTDDMap;
	allocationList m_DataTxAllocationList;

	mmWavePhySapProvider* m_phySapProvider;
	mmWavePhySapUser* m_phySapUser;

	LteMacSapProvider* m_macSapProvider;

	Ptr<UniformRandomVariable> m_raPreambleUniformVariable;
	uint8_t m_raPreambleId;
	uint8_t m_raRnti;


	struct LcInfo
	{
		LteUeCmacSapProvider::LogicalChannelConfig lcConfig;
		LteMacSapUser* macSapUser;
	};

	std::map <uint8_t, LcInfo> m_lcInfoMap;
	uint8_t m_rnti;




};

}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_UE_MAC_H_ */
