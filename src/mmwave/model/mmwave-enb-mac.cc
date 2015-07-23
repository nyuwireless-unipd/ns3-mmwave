/*
 * mmwave-enb-mac.cc
 *
 *  Created on: May 1, 2015
 *      Author: root
 */


#include "mmwave-enb-mac.h"
#include "mmwave-phy-mac-common.h"
#include "mmwave-mac-pdu-header.h"
#include "mmwave-mac-sched-sap.h"
#include "mmwave-mac-scheduler.h"
#include <ns3/lte-mac-sap.h>
#include <ns3/lte-enb-cmac-sap.h>
#include <ns3/log.h>

namespace ns3
{
NS_LOG_COMPONENT_DEFINE ("MmWaveEnbMac");

NS_OBJECT_ENSURE_REGISTERED (MmWaveEnbMac);



// //////////////////////////////////////
// member SAP forwarders
// //////////////////////////////////////


class MmWaveEnbMacMemberEnbCmacSapProvider : public LteEnbCmacSapProvider
{
public:
  MmWaveEnbMacMemberEnbCmacSapProvider (MmWaveEnbMac* mac);

  // inherited from LteEnbCmacSapProvider
  virtual void ConfigureMac (uint8_t ulBandwidth, uint8_t dlBandwidth);
  virtual void AddUe (uint16_t rnti);
  virtual void RemoveUe (uint16_t rnti);
  virtual void AddLc (LcInfo lcinfo, LteMacSapUser* msu);
  virtual void ReconfigureLc (LcInfo lcinfo);
  virtual void ReleaseLc (uint16_t rnti, uint8_t lcid);
  virtual void UeUpdateConfigurationReq (UeConfig params);
  virtual RachConfig GetRachConfig ();
  virtual AllocateNcRaPreambleReturnValue AllocateNcRaPreamble (uint16_t rnti);


private:
  MmWaveEnbMac* m_mac;
};


MmWaveEnbMacMemberEnbCmacSapProvider::MmWaveEnbMacMemberEnbCmacSapProvider (MmWaveEnbMac* mac)
  : m_mac (mac)
{
}

void
MmWaveEnbMacMemberEnbCmacSapProvider::ConfigureMac (uint8_t ulBandwidth, uint8_t dlBandwidth)
{
  m_mac->DoConfigureMac (ulBandwidth, dlBandwidth);
}

void
MmWaveEnbMacMemberEnbCmacSapProvider::AddUe (uint16_t rnti)
{
  m_mac->DoAddUe (rnti);
}

void
MmWaveEnbMacMemberEnbCmacSapProvider::RemoveUe (uint16_t rnti)
{
  m_mac->DoRemoveUe (rnti);
}

void
MmWaveEnbMacMemberEnbCmacSapProvider::AddLc (LcInfo lcinfo, LteMacSapUser* msu)
{
  m_mac->DoAddLc (lcinfo, msu);
}

void
MmWaveEnbMacMemberEnbCmacSapProvider::ReconfigureLc (LcInfo lcinfo)
{
  m_mac->DoReconfigureLc (lcinfo);
}

void
MmWaveEnbMacMemberEnbCmacSapProvider::ReleaseLc (uint16_t rnti, uint8_t lcid)
{
  m_mac->DoReleaseLc (rnti, lcid);
}

void
MmWaveEnbMacMemberEnbCmacSapProvider::UeUpdateConfigurationReq (UeConfig params)
{
  m_mac->UeUpdateConfigurationReq (params);
}

LteEnbCmacSapProvider::RachConfig
MmWaveEnbMacMemberEnbCmacSapProvider::GetRachConfig ()
{
  return m_mac->DoGetRachConfig ();
}

LteEnbCmacSapProvider::AllocateNcRaPreambleReturnValue
MmWaveEnbMacMemberEnbCmacSapProvider::AllocateNcRaPreamble (uint16_t rnti)
{
  return m_mac->DoAllocateNcRaPreamble (rnti);
}



// SAP
// ENB MAC-Phy
class MmWaveMacEnbMemberPhySapUser : public MmWaveEnbPhySapUser
{
public:
	MmWaveMacEnbMemberPhySapUser (MmWaveEnbMac* mac);

	virtual void ReceivePhyPdu (Ptr<Packet> p);

	virtual void ReceiveControlMessage (Ptr<MmWaveControlMessage> msg);

	virtual void SubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo);

	virtual void UlCqiReport (MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters cqi);

	virtual void ReceiveRachPreamble (uint32_t raId);
private:
	MmWaveEnbMac* m_mac;
};

MmWaveMacEnbMemberPhySapUser::MmWaveMacEnbMemberPhySapUser (MmWaveEnbMac* mac)
:m_mac(mac)
{

}

void
MmWaveMacEnbMemberPhySapUser::ReceivePhyPdu (Ptr<Packet> p)
{
	m_mac->DoReceivePhyPdu (p);
}

void
MmWaveMacEnbMemberPhySapUser::ReceiveControlMessage (Ptr<MmWaveControlMessage> msg)
{
	m_mac->DoReceiveControlMessage(msg);
}

void
MmWaveMacEnbMemberPhySapUser::SubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo)
{
	m_mac->DoSubframeIndication(frameNo, subframeNo, slotNo);
}

void
MmWaveMacEnbMemberPhySapUser::UlCqiReport (MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters ulcqi)
{
	m_mac->DoUlCqiReport(ulcqi);
}

void
MmWaveMacEnbMemberPhySapUser::ReceiveRachPreamble (uint32_t raId)
{
	m_mac->ReceiveRachPreamble(raId);
}

// MAC Sched

class MmWaveMacMemberMacSchedSapUser : public MmWaveMacSchedSapUser
{
public:
	MmWaveMacMemberMacSchedSapUser (MmWaveEnbMac* mac);
	virtual void SchedConfigInd (const struct SchedConfigIndParameters& params);
private:
	MmWaveEnbMac* m_mac;
};

MmWaveMacMemberMacSchedSapUser::MmWaveMacMemberMacSchedSapUser (MmWaveEnbMac* mac)
:m_mac(mac)
{
//	 Some blank spaces
}

void
MmWaveMacMemberMacSchedSapUser::SchedConfigInd (const struct SchedConfigIndParameters& params)
{
	m_mac->DoSchedConfigIndication (params);
}


TypeId
MmWaveEnbMac::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::MmWaveEnbMac")
			.SetParent<MmWaveMac> ()
			.AddConstructor<MmWaveEnbMac> ()
	;
	return tid;
}

MmWaveEnbMac::MmWaveEnbMac (void) :
	 m_frameNum (0),
	 m_sfNum (0),
	 m_slotNum (0),
	 m_tbUid (0)
{
	NS_LOG_FUNCTION (this);
	m_cmacSapProvider = new MmWaveEnbMacMemberEnbCmacSapProvider (this);
	m_macSapProvider = new EnbMacMemberLteMacSapProvider<MmWaveEnbMac> (this);
	m_phySapUser = new MmWaveMacEnbMemberPhySapUser (this);
	m_macSchedSapUser = new MmWaveMacMemberMacSchedSapUser (this);
}

MmWaveEnbMac::~MmWaveEnbMac (void)
{
	NS_LOG_FUNCTION (this);
}

void
MmWaveEnbMac::DoDispose (void)
{
	NS_LOG_FUNCTION (this);
	m_dlCqiReceived.clear ();
	m_ulCqiReceived.clear ();
	m_ulCeReceived.clear ();
	//  m_dlHarqInfoListReceived.clear ();
	//  m_ulHarqInfoListReceived.clear ();
	m_miDlHarqProcessesPackets.clear ();
	delete m_macSapProvider;
	delete m_cmacSapProvider;
	delete m_macSchedSapUser;
	//  delete m_macCschedSapUser;
	delete m_phySapUser;
}

void
MmWaveEnbMac::SetCofigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig)
{
	m_phyMacConfig = ptrConfig;
}

Ptr<MmWavePhyMacCommon>
MmWaveEnbMac::GetConfigurationParameters (void) const
{
	return m_phyMacConfig;
}

void
MmWaveEnbMac::ReceiveRachPreamble (uint32_t raId)
{
	++m_receivedRachPreambleCount[raId];
}

// forwarded from LteMacSapProvider
void
MmWaveEnbMac::DoTransmitPdu (LteMacSapProvider::TransmitPduParameters params)
{
	// TB UID passed back along with RLC data as HARQ process ID
	uint32_t tbMapKey = ((params.rnti & 0xFFFF) << 8) | (params.harqProcessId & 0xFF);
	std::map<uint32_t, struct MacPduInfo>::iterator it = m_macPduMap.find (tbMapKey);
	if (it == m_macPduMap.end ())
	{
		NS_FATAL_ERROR ("No MAC PDU storage element found for this TB UID/RNTI");
	}
	else
	{
		if(it->second.m_pdu == 0)
		{
			it->second.m_pdu = params.pdu;
		}
		else
		{
			it->second.m_pdu->AddAtEnd (params.pdu); // append to MAC PDU
		}

		MacSubheader subheader (params.lcid, params.pdu->GetSize ());
		it->second.m_macHeader.AddSubheader (subheader); // add RLC PDU sub-header into MAC header

		if (it->second.m_numRlcPdu == 1)
		{			// wait for all RLC PDUs to be received
			it->second.m_pdu->AddHeader (it->second.m_macHeader);
			LteRadioBearerTag bearerTag (params.rnti, it->second.m_size, 0);
			it->second.m_pdu->AddPacketTag (bearerTag);
			NS_LOG_DEBUG ("eNB sending MAC pdu size " << it->second.m_pdu->GetSize());
			for (unsigned i = 0; i < it->second.m_macHeader.GetSubheaders().size(); i++)
			{
				NS_LOG_DEBUG("Subheader " << i << " size " << it->second.m_macHeader.GetSubheaders().at(i).m_size);
			}

			//harq process
			std::map <uint16_t, DlHarqProcessesBuffer_t>::iterator iter =  m_miDlHarqProcessesPackets.find (params.rnti);
			NS_ASSERT (iter!=m_miDlHarqProcessesPackets.end ());
			(*iter).second.at (params.layer).at (params.harqProcessId)->AddPacket (it->second.m_pdu);

			m_phySapProvider->SendMacPdu (it->second.m_pdu);
			m_macPduMap.erase (it);  // delete map entry
		}
		else
		{
			it->second.m_numRlcPdu--; // decrement count of remaining RLC requests
		}
	}
}

LteMacSapProvider*
MmWaveEnbMac::GetUeMacSapProvider (void)
{
  return m_macSapProvider;
}

LteEnbCmacSapProvider*
MmWaveEnbMac::GetEnbCmacSapProvider (void)
{
  return m_cmacSapProvider;
}
void
MmWaveEnbMac::SetEnbCmacSapUser (LteEnbCmacSapUser* s)
{
  m_cmacSapUser = s;
}

void
MmWaveEnbMac::DoSubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo)
{
	m_frameNum = frameNo;
	m_sfNum = subframeNo;
	m_slotNum = slotNo;

	// --- DOWNLINK ---
	// Send Dl-CQI info to the scheduler	if(m_dlCqiReceived.size () > 0)
	{
		MmWaveMacSchedSapProvider::SchedDlCqiInfoReqParameters dlCqiInfoReq;
		dlCqiInfoReq.m_sfnsf = ((0x3FF & frameNo) << 16) | ((0xFF & subframeNo) << 8) | ((0xFF & slotNo));

		dlCqiInfoReq.m_cqiList.insert (dlCqiInfoReq.m_cqiList.begin (), m_dlCqiReceived.begin (), m_dlCqiReceived.end ());
		m_dlCqiReceived.erase (m_dlCqiReceived.begin (), m_dlCqiReceived.end ());

		m_macSchedSapProvider->SchedDlCqiInfoReq (dlCqiInfoReq);
	}

	if (!m_receivedRachPreambleCount.empty ())
	{
    // process received RACH preambles and notify the scheduler
		Ptr<MmWaveRarMessage> rarMsg = Create<MmWaveRarMessage> ();

		for (std::map<uint8_t, uint32_t>::const_iterator it = m_receivedRachPreambleCount.begin ();
				it != m_receivedRachPreambleCount.end ();
				++it)
		{
			uint32_t rnti = m_cmacSapUser->AllocateTemporaryCellRnti ();
			NS_LOG_INFO (rnti);
			MmWaveRarMessage::Rar rar;
			rar.rapId = (*it).first;
			rar.rarPayload.m_rnti = rnti;
			rarMsg->AddRar (rar);
			NS_ASSERT_MSG((*it).second ==1, "Two user send the same Rach ID, collision detected");
		}
		m_phySapProvider->SendControlMessage (rarMsg);
		m_receivedRachPreambleCount.clear ();
	}

	// --- UPLINK ---
	// Send UL-CQI info to the scheduler
	std::vector <MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters>::iterator itCqi;
	for (uint16_t i = 0; i < m_ulCqiReceived.size (); i++)
	{
		if (subframeNo > 1)
		{
//			m_ulCqiReceived.at (i).m_sfnSf = ((0x3FF & frameNo) << 4) | (0xF & (subframeNo - 1));
			m_ulCqiReceived.at (i).m_sfnSf = ((0x3FF & frameNo) << 16) | ((0xFF & (subframeNo-1)) << 8) | ((0xFF & slotNo));
		}
		else
		{
//			m_ulCqiReceived.at (i).m_sfnSf = ((0x3FF & (frameNo-1)) << 4) | (0xF & 10);
			m_ulCqiReceived.at (i).m_sfnSf = ((0x3FF & (frameNo-1)) << 16) | ((0xFF & 8) << 8) | ((0xFF & slotNo));

		}
		m_macSchedSapProvider->SchedUlCqiInfoReq (m_ulCqiReceived.at (i));
	}
	m_ulCqiReceived.clear ();

	// Send BSR reports to the scheduler
	if (m_ulCeReceived.size () > 0)
	{
		MmWaveMacSchedSapProvider::SchedUlMacCtrlInfoReqParameters ulMacReq;
		ulMacReq.m_sfnSf = ((0x3FF & frameNo) << 4) | (0xF & subframeNo);
		ulMacReq.m_macCeList.insert (ulMacReq.m_macCeList.begin (), m_ulCeReceived.begin (), m_ulCeReceived.end ());
		m_ulCeReceived.erase (m_ulCeReceived.begin (), m_ulCeReceived.end ());
		m_macSchedSapProvider->SchedUlMacCtrlInfoReq (ulMacReq);
	}

	if (m_slotNum == 1)
	{
		// trigger scheduler
		uint32_t dlSchedFrameNo = m_frameNum;
		uint32_t dlSchedSubframeNo = m_sfNum;

		if (dlSchedSubframeNo + m_phyMacConfig->GetL1L2CtrlLatency () > m_phyMacConfig->GetSubframesPerFrame ())
		{
		  dlSchedFrameNo++;
		  dlSchedSubframeNo = (dlSchedSubframeNo + m_phyMacConfig->GetL1L2CtrlLatency()) - m_phyMacConfig->GetSubframesPerFrame();
		}
		else
		{
		  dlSchedSubframeNo = dlSchedSubframeNo + m_phyMacConfig->GetL1L2CtrlLatency();
		}

		MmWaveMacSchedSapProvider::SchedTriggerReqParameters params;
		uint32_t sfn = ((0x3FF & dlSchedFrameNo) << 16) | ((0xFF & dlSchedSubframeNo) << 8) | ((0xFF & 1));;
		params.m_snfSf = sfn;

		// Forward DL HARQ feebacks collected during last subframe TTI
		if (m_dlHarqInfoListReceived.size () > 0)
		{
			params.m_dlHarqInfoList = m_dlHarqInfoListReceived;
			// empty local buffer
			m_dlHarqInfoListReceived.clear ();
		}

		// Forward UL HARQ feebacks collected during last TTI
		if (m_ulHarqInfoListReceived.size () > 0)
		{
			params.m_ulHarqInfoList = m_ulHarqInfoListReceived;
			// empty local buffer
			m_ulHarqInfoListReceived.clear ();
		}

		params.m_ueList = m_associatedUe;
		m_macSchedSapProvider->SchedTriggerReq (params);
	}
}

void
MmWaveEnbMac::AssociateUeMAC (uint64_t imsi)
{
	//NS_LOG_UNCOND (this<<"Associate UE (imsi:"<< imsi<<" ) with enb");

	//m_associatedUe.push_back (imsi);

}

void
MmWaveEnbMac::SetForwardUpCallback (Callback <void, Ptr<Packet> > cb)
{
	m_forwardUpCallback = cb;
}

void
MmWaveEnbMac::DoReceivePhyPdu (Ptr<Packet> p)
{
	NS_LOG_FUNCTION (this);
	LteRadioBearerTag tag;
	p->RemovePacketTag (tag);
	uint16_t rnti = tag.GetRnti ();
	MmWaveMacPduHeader macHeader;
	p->RemoveHeader (macHeader);
	std::map <uint16_t, std::map<uint8_t, LteMacSapUser*> >::iterator rntiIt = m_rlcAttached.find (rnti);
	NS_ASSERT_MSG (rntiIt != m_rlcAttached.end (), "could not find RNTI" << rnti);
	std::vector<MacSubheader> macSubheaders = macHeader.GetSubheaders ();
	uint32_t currPos = 0;
	for (unsigned ipdu = 0; ipdu < macSubheaders.size (); ipdu++)
	{
		std::map<uint8_t, LteMacSapUser*>::iterator lcidIt = rntiIt->second.find (macSubheaders[ipdu].m_lcid);
		NS_ASSERT_MSG (lcidIt != rntiIt->second.end (), "could not find LCID" << macSubheaders[ipdu].m_lcid);
		Ptr<Packet> rlcPdu;
		if((p->GetSize ()-currPos) < (uint32_t)macSubheaders[ipdu].m_size)
			{
				NS_LOG_ERROR ("Packet size less than specified in MAC header (actual= " \
				              <<p->GetSize ()<<" header= "<<(uint32_t)macSubheaders[ipdu].m_size<<")" );
			}
			else if ((p->GetSize ()-currPos) > (uint32_t)macSubheaders[ipdu].m_size)
			{
				NS_LOG_DEBUG ("Fragmenting MAC PDU (packet size greater than specified in MAC header (actual= " \
				              <<p->GetSize ()<<" header= "<<(uint32_t)macSubheaders[ipdu].m_size<<")" );
				rlcPdu = p->CreateFragment (currPos, p->GetSize ());
				currPos += p->GetSize ();
			}
			else
			{
				rlcPdu = p->CreateFragment (currPos, (uint32_t)macSubheaders[ipdu].m_size);
				currPos += (uint32_t)macSubheaders[ipdu].m_size;
			}
		NS_LOG_DEBUG ("Enb Mac Rx Packet, Rnti:" <<rnti<<" lcid:"<<macSubheaders[ipdu].m_lcid<<" size:"<<macSubheaders[ipdu].m_size);
		(*lcidIt).second->ReceivePdu (rlcPdu);
	}
}

MmWaveEnbPhySapUser*
MmWaveEnbMac::GetPhySapUser ()
{
	return m_phySapUser;
}

void
MmWaveEnbMac::SetPhySapProvider (MmWavePhySapProvider* ptr)
{
	m_phySapProvider = ptr;
}

MmWaveMacSchedSapUser*
MmWaveEnbMac::GetMmWaveMacSchedSapUser ()
{
	return m_macSchedSapUser;
}

void
MmWaveEnbMac::SetMmWaveMacSchedSapProvider (MmWaveMacSchedSapProvider* ptr)
{
	m_macSchedSapProvider = ptr;
}

void
MmWaveEnbMac::DoUlCqiReport (MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters ulcqi)
{
  if (ulcqi.m_ulCqi.m_type == UlCqiInfo::PUSCH)
    {
      NS_LOG_DEBUG (this << " eNB rxed an PUSCH UL-CQI");
    }
  else if (ulcqi.m_ulCqi.m_type == UlCqiInfo::SRS)
    {
      NS_LOG_DEBUG (this << " eNB rxed an SRS UL-CQI");
    }
  m_ulCqiReceived.push_back (ulcqi);
}


void
MmWaveEnbMac::DoReceiveControlMessage  (Ptr<MmWaveControlMessage> msg)
{
	NS_LOG_FUNCTION (this << msg);

	switch (msg->GetMessageType())
	{
		case (MmWaveControlMessage::DL_CQI):
		{
			Ptr<MmWaveDlCqiMessage> cqi = DynamicCast<MmWaveDlCqiMessage> (msg);
			DlCqiInfo cqiElement = cqi->GetDlCqi ();
			NS_ASSERT (cqiElement.m_rnti != 0);
			m_dlCqiReceived.push_back (cqiElement);
			break;
		}
		case (MmWaveControlMessage::BSR):
		{
			Ptr<MmWaveBsrMessage> bsr = DynamicCast<MmWaveBsrMessage> (msg);
		  m_ulCeReceived.push_back (bsr->GetBsr ());
			break;
		}
		case (MmWaveControlMessage::DL_HARQ):
	  {
			//	      Ptr<DlHarqFeedbackLteControlMessage> dlharq = DynamicCast<DlHarqFeedbackLteControlMessage> (msg);
			//	      DoDlInfoListElementHarqFeeback (dlharq->GetDlHarqFeedback ());
			break;
	  }
		default:
			NS_LOG_INFO ("Control message not supported/expected");
	}

}

void
MmWaveEnbMac::DoReportBufferStatus (LteMacSapProvider::ReportBufferStatusParameters params)
{
  NS_LOG_FUNCTION (this);
  MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters schedParams;
  schedParams.m_logicalChannelIdentity = params.lcid;
  schedParams.m_rlcRetransmissionHolDelay = params.retxQueueHolDelay;
  schedParams.m_rlcRetransmissionQueueSize = params.retxQueueSize;
  schedParams.m_rlcStatusPduSize = params.statusPduSize;
  schedParams.m_rlcTransmissionQueueHolDelay = params.txQueueHolDelay;
  schedParams.m_rlcTransmissionQueueSize = params.txQueueSize;
  schedParams.m_rnti = params.rnti;

  m_macSchedSapProvider->SchedDlRlcBufferReq (schedParams);
}

void
MmWaveEnbMac::DoSchedConfigIndication (MmWaveMacSchedSapUser::SchedConfigIndParameters ind)
{
	std::map<uint16_t, SchedInfoElement>::iterator schedTt;
	// process scheduling entries and generate messages for PHY
	for (schedTt = ind.m_schedInfoMap.begin (); schedTt != ind.m_schedInfoMap.end (); schedTt++)
	{
		// Create DCI message object and send to PHY
		SchedInfoElement& schedInfo = schedTt->second;
		uint16_t rnti = schedInfo.m_rnti;
		Ptr<MmWaveDciMessage> dciMsg = Create<MmWaveDciMessage> ();
		dciMsg->SetDciInfoElement (schedInfo.m_dci);
		dciMsg->SetSfnSf (ind.m_sfn);
		m_phySapProvider->SendControlMessage (dciMsg);
		std::map <uint16_t, std::map<uint8_t, LteMacSapUser*> >::iterator rntiIt = m_rlcAttached.find (rnti);

		for (unsigned int itb = 0; itb < schedInfo.m_dci.m_tbInfoElements.size (); itb++)
		{
			// iterate through RLC PDUs for each slot
			TbInfoElement& tbInfo = schedInfo.m_dci.m_tbInfoElements[itb];
			std::vector<RlcPduInfo>& rlcPduElems = schedInfo.m_rlcPduList[itb];

			MacPduInfo macPduInfo (schedInfo.m_frameNum, schedInfo.m_sfNum, tbInfo.m_slotInd+1, \
			                       tbInfo.m_tbSize, rlcPduElems.size ());
			//uint8_t tbUid = AllocateTbUid ();
			uint8_t tbUid = AllocateTbUid ()%20;

			// insert into MAC PDU map
			uint32_t tbMapKey = ((rnti & 0xFFFF) << 8) | (tbUid & 0xFF);
			m_macPduMap.insert (std::pair<uint32_t, struct MacPduInfo> (tbMapKey, macPduInfo));

			//Harq Process
			if (tbInfo.m_ndi == 1)
			{
				// new data -> force emptying correspondent harq pkt buffer
				std::map <uint16_t, DlHarqProcessesBuffer_t>::iterator it = m_miDlHarqProcessesPackets.find (rnti);
				NS_ASSERT(it!=m_miDlHarqProcessesPackets.end());
				for (uint16_t lcId = 0; lcId < (*it).second.size (); lcId ++)
				{
					Ptr<PacketBurst> pb = CreateObject <PacketBurst> ();
					//(*it).second.at (lcId).at (tbInfo.m_harqProcess) = pb;
					(*it).second.at (lcId).at (tbUid) = pb;

				}

				for (unsigned int ipdu = 0; ipdu < rlcPduElems.size (); ipdu++)
				{
					NS_ASSERT_MSG (rntiIt != m_rlcAttached.end (), "could not find RNTI" << rnti);
					std::map<uint8_t, LteMacSapUser*>::iterator lcidIt = rntiIt->second.find (rlcPduElems[ipdu].m_lcid);
					NS_ASSERT_MSG (lcidIt != rntiIt->second.end (), "could not find LCID" << rlcPduElems[ipdu].m_lcid);
					// Instead of passing the HARQ process number to RLC, use a unique identifier to match the RLC PDU to its TB
					NS_LOG_DEBUG ("Notifying RLC of TX opportunity for TB " << (unsigned int)tbUid << " PDU num " << ipdu << " size " << (unsigned int)rlcPduElems[ipdu].m_size);
					MacSubheader subheader (rlcPduElems[ipdu].m_lcid, rlcPduElems[ipdu].m_size);
					(*lcidIt).second->NotifyTxOpportunity ((rlcPduElems[ipdu].m_size - subheader.GetSize ()), 0, tbUid);
				}
			}
			else
			{
				NS_LOG_UNCOND ("Retransmission");
				if (tbInfo.m_tbSize > 0)
				{
					// HARQ retransmission -> retrieve TB from HARQ buffer
					std::map <uint16_t, DlHarqProcessesBuffer_t>::iterator it = m_miDlHarqProcessesPackets.find (rnti);
					NS_ASSERT(it!=m_miDlHarqProcessesPackets.end());
					//Ptr<PacketBurst> pb = (*it).second.at (k).at (tbInfo.m_harqProcess);
					Ptr<PacketBurst> pb = (*it).second.at (0).at (tbUid);
					for (std::list<Ptr<Packet> >::const_iterator j = pb->Begin (); j != pb->End (); ++j)
					{
						Ptr<Packet> pkt = (*j)->Copy ();
						m_phySapProvider->SendMacPdu (pkt);
					}
				}
			}
		}
	}
}

uint8_t MmWaveEnbMac::AllocateTbUid (void)
{
	return m_tbUid++;
}

// ////////////////////////////////////////////
// CMAC SAP
// ////////////////////////////////////////////

void
MmWaveEnbMac::DoConfigureMac (uint8_t ulBandwidth, uint8_t dlBandwidth)
{
  NS_LOG_FUNCTION (this << " ulBandwidth=" << (uint16_t) ulBandwidth << " dlBandwidth=" << (uint16_t) dlBandwidth);
}


void
MmWaveEnbMac::DoAddUe (uint16_t rnti)
{
	NS_LOG_FUNCTION (this << " rnti=" << rnti);
	std::map<uint8_t, LteMacSapUser*> empty;
	std::pair <std::map <uint16_t, std::map<uint8_t, LteMacSapUser*> >::iterator, bool>
	 ret = m_rlcAttached.insert (std::pair <uint16_t,  std::map<uint8_t, LteMacSapUser*> >
								  (rnti, empty));
	m_associatedUe.push_back (rnti);
	NS_ASSERT_MSG (ret.second, "element already present, RNTI already existed");

	// Create DL trasmission HARQ buffers
	std::vector < Ptr<PacketBurst> > dlHarqLayer0pkt;
	uint16_t harqNum = m_phyMacConfig->GetNumHarqProcess ();
	dlHarqLayer0pkt.resize (harqNum);
	for (uint8_t i = 0; i < harqNum; i++)
	{
		Ptr<PacketBurst> pb = CreateObject <PacketBurst> ();
		dlHarqLayer0pkt.at (i) = pb;
	}
	/*
	std::vector < Ptr<PacketBurst> > dlHarqLayer1pkt;
	dlHarqLayer1pkt.resize (harqNum);
	for (uint8_t i = 0; i < harqNum; i++)
	{
		Ptr<PacketBurst> pb = CreateObject <PacketBurst> ();
		dlHarqLayer1pkt.at (i) = pb;
	}
	*/
	DlHarqProcessesBuffer_t buf;
	buf.push_back (dlHarqLayer0pkt);
	//buf.push_back (dlHarqLayer1pkt);
	m_miDlHarqProcessesPackets.insert (std::pair <uint16_t, DlHarqProcessesBuffer_t> (rnti, buf));

}

void
MmWaveEnbMac::DoRemoveUe (uint16_t rnti)
{
  NS_LOG_FUNCTION (this << " rnti=" << rnti);
  m_miDlHarqProcessesPackets.erase (rnti);
}

void
MmWaveEnbMac::DoAddLc (LteEnbCmacSapProvider::LcInfo lcinfo, LteMacSapUser* msu)
{
  NS_LOG_FUNCTION (this);
  NS_LOG_FUNCTION (this);

  std::map <LteFlowId_t, LteMacSapUser* >::iterator it;

  LteFlowId_t flow (lcinfo.rnti, lcinfo.lcId);

  std::map <uint16_t, std::map<uint8_t, LteMacSapUser*> >::iterator rntiIt = m_rlcAttached.find (lcinfo.rnti);
  NS_ASSERT_MSG (rntiIt != m_rlcAttached.end (), "RNTI not found");
  std::map<uint8_t, LteMacSapUser*>::iterator lcidIt = rntiIt->second.find (lcinfo.lcId);
  if (lcidIt == rntiIt->second.end ())
    {
      rntiIt->second.insert (std::pair<uint8_t, LteMacSapUser*> (lcinfo.lcId, msu));
    }
  else
    {
      NS_LOG_ERROR ("LC already exists");
    }

}

void
MmWaveEnbMac::DoReconfigureLc (LteEnbCmacSapProvider::LcInfo lcinfo)
{
  NS_FATAL_ERROR ("not implemented");
}

void
MmWaveEnbMac::DoReleaseLc (uint16_t rnti, uint8_t lcid)
{
  NS_FATAL_ERROR ("not implemented");
}

void
MmWaveEnbMac::UeUpdateConfigurationReq (LteEnbCmacSapProvider::UeConfig params)
{
  NS_LOG_FUNCTION (this);
  //FfMacCschedSapProvider::CschedUeConfigReqParameters req;
  //req.m_rnti = params.m_rnti;
  //req.m_transmissionMode = params.m_transmissionMode;
  //req.m_reconfigureFlag = true;
  //m_macScheduler->CschedUeConfigReq (req);
}

LteEnbCmacSapProvider::RachConfig
MmWaveEnbMac::DoGetRachConfig ()
{
  struct LteEnbCmacSapProvider::RachConfig rc;
  return rc;
}

LteEnbCmacSapProvider::AllocateNcRaPreambleReturnValue
MmWaveEnbMac::DoAllocateNcRaPreamble (uint16_t rnti)
{
	LteEnbCmacSapProvider::AllocateNcRaPreambleReturnValue ret;
  return ret;
}

}
