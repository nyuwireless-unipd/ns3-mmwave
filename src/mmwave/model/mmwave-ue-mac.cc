/*
 * mmwave-ue-mac.cc
 *
 *  Created on: May 1, 2015
 *      Author: root
 */

#include "mmwave-ue-mac.h"
#include <ns3/log.h>

namespace ns3
{
NS_LOG_COMPONENT_DEFINE ("mmWaveUeMac");

NS_OBJECT_ENSURE_REGISTERED (mmWaveUeMac);


///////////////////////////////////////////////////////////
// SAP forwarders
///////////////////////////////////////////////////////////


class UeMemberLteUeCmacSapProvider : public LteUeCmacSapProvider
{
public:
  UeMemberLteUeCmacSapProvider (mmWaveUeMac* mac);

  // inherited from LteUeCmacSapProvider
  virtual void ConfigureRach (RachConfig rc);
  virtual void StartContentionBasedRandomAccessProcedure ();
  virtual void StartNonContentionBasedRandomAccessProcedure (uint16_t rnti, uint8_t preambleId, uint8_t prachMask);
  virtual void AddLc (uint8_t lcId, LteUeCmacSapProvider::LogicalChannelConfig lcConfig, LteMacSapUser* msu);
  virtual void RemoveLc (uint8_t lcId);
  virtual void Reset ();

private:
  mmWaveUeMac* m_mac;
};


UeMemberLteUeCmacSapProvider::UeMemberLteUeCmacSapProvider (mmWaveUeMac* mac)
  : m_mac (mac)
{
}

void
UeMemberLteUeCmacSapProvider::ConfigureRach (RachConfig rc)
{
  m_mac->DoConfigureRach (rc);
}

  void
UeMemberLteUeCmacSapProvider::StartContentionBasedRandomAccessProcedure ()
{
  m_mac->DoStartContentionBasedRandomAccessProcedure ();
}

 void
UeMemberLteUeCmacSapProvider::StartNonContentionBasedRandomAccessProcedure (uint16_t rnti, uint8_t preambleId, uint8_t prachMask)
{
  m_mac->DoStartNonContentionBasedRandomAccessProcedure (rnti, preambleId, prachMask);
}


void
UeMemberLteUeCmacSapProvider::AddLc (uint8_t lcId, LogicalChannelConfig lcConfig, LteMacSapUser* msu)
{
  m_mac->DoAddLc (lcId, lcConfig, msu);
}

void
UeMemberLteUeCmacSapProvider::RemoveLc (uint8_t lcid)
{
  m_mac->DoRemoveLc (lcid);
}

void
UeMemberLteUeCmacSapProvider::Reset ()
{
  m_mac->DoReset ();
}


class UeMemberLteMacSapProvider : public LteMacSapProvider
{
public:
  UeMemberLteMacSapProvider (mmWaveUeMac* mac);

  // inherited from LteMacSapProvider
  virtual void TransmitPdu (TransmitPduParameters params);
  virtual void ReportBufferStatus (ReportBufferStatusParameters params);

private:
  mmWaveUeMac* m_mac;
};


UeMemberLteMacSapProvider::UeMemberLteMacSapProvider (mmWaveUeMac* mac)
  : m_mac (mac)
{
}

void
UeMemberLteMacSapProvider::TransmitPdu (TransmitPduParameters params)
{
  m_mac->DoTransmitPdu (params);
}


void
UeMemberLteMacSapProvider::ReportBufferStatus (ReportBufferStatusParameters params)
{
  m_mac->DoReportBufferStatus (params);
}




class MacUeMembermmWavePhySapUser : public mmWavePhySapUser
{
public:
	MacUeMembermmWavePhySapUser (mmWaveUeMac* mac);

	virtual void ReceivePhyPdu (Ptr<Packet> p);

	virtual void ReceivemmWaveControlMessage (Ptr<mmWaveControlMessages> msg);

	virtual void SubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo);

	virtual void CqiReport (CqiInfo cqi);
	virtual void ReceiveRachPreamble (uint32_t raId);

private:
	mmWaveUeMac* m_mac;
};

MacUeMembermmWavePhySapUser::MacUeMembermmWavePhySapUser (mmWaveUeMac* mac)
:m_mac(mac)
{

}
void
MacUeMembermmWavePhySapUser::ReceivePhyPdu (Ptr<Packet> p)
{
	m_mac->DoReceivePhyPdu(p);
}

void
MacUeMembermmWavePhySapUser::ReceivemmWaveControlMessage (Ptr<mmWaveControlMessages> msg)
{
	m_mac->DoReceivemmWaveControlMessage(msg);
}

void
MacUeMembermmWavePhySapUser::SubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo)
{
	m_mac->DoSubframeIndication(frameNo, subframeNo, slotNo);
}

void
MacUeMembermmWavePhySapUser::CqiReport (CqiInfo cqi)
{

}

void
MacUeMembermmWavePhySapUser::ReceiveRachPreamble (uint32_t raId)
{

}
//-----------------------------------------------------------------------

TypeId
mmWaveUeMac::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::mmWaveUeMac")
			.SetParent<mmWaveMac> ()
			.AddConstructor<mmWaveUeMac> ()
	;
	return tid;
}

mmWaveUeMac::mmWaveUeMac (void)
:m_phySapProvider (0),
 m_rnti(0)
{
	m_raPreambleUniformVariable = CreateObject<UniformRandomVariable> ();

	m_cmacSapProvider = new UeMemberLteUeCmacSapProvider (this);
	m_macSapProvider = new UeMemberLteMacSapProvider (this);
	NS_LOG_FUNCTION (this);
	m_phySapUser = new MacUeMembermmWavePhySapUser (this);
}

mmWaveUeMac::~mmWaveUeMac (void)
{

}

// forwarded from MAC SAP
void
mmWaveUeMac::DoTransmitPdu (LteMacSapProvider::TransmitPduParameters params)
{
	//NS_LOG_UNCOND ("-------------------------------------------------RLC -> UE Packet fragment size:"<<params.pdu->GetSize ());

	LteRadioBearerTag tag (params.rnti, params.lcid, 0); //UE works in SISO mode);
	params.pdu->AddPacketTag (tag);
	bool flag = QueueData(params.pdu);
	NS_ASSERT (flag);
}

void
mmWaveUeMac::DoReportBufferStatus (LteMacSapProvider::ReportBufferStatusParameters params)
{
	//NS_LOG_UNCOND ("***************************************UE___Reporting buffer staftus");
}

void
mmWaveUeMac::SetmmWaveUeCmacSapUser (LteUeCmacSapUser* s)
{
  m_cmacSapUser = s;
}

LteUeCmacSapProvider*
mmWaveUeMac::GetmmWaveUeCmacSapProvider (void)
{
  return m_cmacSapProvider;
}


void
mmWaveUeMac::DoSubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo)
{
	//NS_LOG_UNCOND ("MAC SF Ind");
	if (!m_DataTxAllocationList.m_AllocationMapforSF.empty())
	{
		allocationMap alMap;
		while(!m_DataTxAllocationList.m_AllocationMapforSF.empty())
		{
			std::list<allocationMap>::iterator amIt;
			bool flag = false;

			amIt = m_DataTxAllocationList.m_AllocationMapforSF.begin ();
			alMap = (*amIt);
			m_DataTxAllocationList.m_AllocationMapforSF.pop_front ();
			if (alMap.m_IsUL == true)
			{
				continue;
			}

			for (uint32_t i = 0; i < alMap.m_user.size (); i++)
			{
				if (alMap.m_user.at(i).noAllocation == false)
				{
					/* Something needs to be transmitted here*/
					flag = true;
					/* Send Tx opportunity to RLC */

				    std::map <uint8_t, LcInfo>::iterator it;
				    for (it = m_lcInfoMap.begin (); it!=m_lcInfoMap.end (); it++)
				    {
						(*it).second.macSapUser->NotifyTxOpportunity (alMap.m_user.at(i).m_tbsSize, 0, 0);
				    }
				}
			}

			if (flag)
			{
				break;
			}
		}
		Ptr<PacketBurst> pb = GetPacketBurstFromMacQueue ();
		m_phySapProvider->SendMacPdu (pb);
	}

}

void
mmWaveUeMac::DoReceivePhyPdu (Ptr<Packet> p)
{
  LteRadioBearerTag tag;
  p->RemovePacketTag (tag);
  //NS_LOG_UNCOND ("Ue Mac Rx Packet, tag_Rnti:"<<tag.GetRnti ()<<" ue_Rnti:"<<(int)m_rnti);

  if (tag.GetRnti () == m_rnti)
    {
      // packet is for the current user
      std::map <uint8_t, LcInfo>::const_iterator it = m_lcInfoMap.find (tag.GetLcid ());
      NS_ASSERT_MSG (it != m_lcInfoMap.end (), "received packet with unknown lcid");
      it->second.macSapUser->ReceivePdu (p);
    }
}

void
mmWaveUeMac::RecvRaResponse (BuildRarListElement_s raResponse)
{
  NS_LOG_FUNCTION (this);
  m_rnti = raResponse.m_rnti;
  m_cmacSapUser->SetTemporaryCellRnti (m_rnti);
  m_cmacSapUser->NotifyRandomAccessSuccessful ();
}

void
mmWaveUeMac::DoReceivemmWaveControlMessage  (Ptr<mmWaveControlMessages> msg)
{
	NS_LOG_FUNCTION (this << msg);

	switch (msg->GetMessageType())
	{
	case (mmWaveControlMessages::RSC_ALLOCATION):
	{
		Ptr<mmWaveResourceAllocation> rscMsg = DynamicCast <mmWaveResourceAllocation> (msg);
		m_DataTxTDDMap = rscMsg->GetSchedule ();
		m_DataTxAllocationList = rscMsg->GetAllocationMap ();
		break;
	}

	case (mmWaveControlMessages::RAR):
	{
		Ptr<RarmmWaveControlMessage> rarMsg = DynamicCast<RarmmWaveControlMessage> (msg);
		for (std::list<RarmmWaveControlMessage::Rar>::const_iterator it = rarMsg->RarListBegin ();
						   it != rarMsg->RarListEnd ();
						   ++it)
		{
			if (it->rapId == m_raPreambleId)
			{
                RecvRaResponse (it->rarPayload);
			}
		}
		break;
	}

	default:
		NS_LOG_LOGIC ("Control message not supported/expected");
	}
}

mmWavePhySapUser*
mmWaveUeMac::GetmmWavePhySapUser ()
{
	return m_phySapUser;
}

void
mmWaveUeMac::SetmmWavePhySapProvider (mmWavePhySapProvider* ptr)
{
	m_phySapProvider = ptr;
}

void
mmWaveUeMac::DoConfigureRach (LteUeCmacSapProvider::RachConfig rc)
{
  NS_LOG_FUNCTION (this);

}

void
mmWaveUeMac::DoStartContentionBasedRandomAccessProcedure ()
{
  NS_LOG_FUNCTION (this);
  RandomlySelectAndSendRaPreamble ();
}

void
mmWaveUeMac::RandomlySelectAndSendRaPreamble ()
{
  NS_LOG_FUNCTION (this);
  bool contention = true;
  SendRaPreamble (contention);
}

void
mmWaveUeMac::SendRaPreamble(bool contention)
{
	m_raPreambleId = m_raPreambleUniformVariable->GetInteger (0, 64 - 1);
	/*raRnti should be subframeNo -1 */
	m_raRnti = 1;
	m_phySapProvider->SendRachPreamble(m_raPreambleId, m_raRnti);
}

void
mmWaveUeMac::DoStartNonContentionBasedRandomAccessProcedure (uint16_t rnti, uint8_t preambleId, uint8_t prachMask)
{
	NS_LOG_FUNCTION (this << " rnti" << rnti);
	NS_ASSERT_MSG (prachMask == 0, "requested PRACH MASK = " << (uint32_t) prachMask << ", but only PRACH MASK = 0 is supported");
	m_rnti = rnti;
}

void
mmWaveUeMac::DoAddLc (uint8_t lcId,  LteUeCmacSapProvider::LogicalChannelConfig lcConfig, LteMacSapUser* msu)
{
	NS_LOG_FUNCTION (this << " lcId" << (uint32_t) lcId);
	NS_ASSERT_MSG (m_lcInfoMap.find (lcId) == m_lcInfoMap.end (), "cannot add channel because LCID " << lcId << " is already present");

	LcInfo lcInfo;
	lcInfo.lcConfig = lcConfig;
	lcInfo.macSapUser = msu;
	m_lcInfoMap[lcId] = lcInfo;
}

void
mmWaveUeMac::DoRemoveLc (uint8_t lcId)
{
	NS_LOG_FUNCTION (this << " lcId" << lcId);
}

LteMacSapProvider*
mmWaveUeMac::GetmmWaveMacSapProvider (void)
{
	return m_macSapProvider;
}

void
mmWaveUeMac::DoReset ()
{
	NS_LOG_FUNCTION (this);
}
//////////////////////////////////////////////


}
