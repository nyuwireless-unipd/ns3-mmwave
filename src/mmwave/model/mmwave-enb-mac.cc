/*
 * mmwave-enb-mac.cc
 *
 *  Created on: May 1, 2015
 *      Author: root
 */


#include "mmwave-enb-mac.h"
#include <ns3/log.h>

namespace ns3
{
NS_LOG_COMPONENT_DEFINE ("mmWaveEnbMac");

NS_OBJECT_ENSURE_REGISTERED (mmWaveEnbMac);



// //////////////////////////////////////
// member SAP forwarders
// //////////////////////////////////////


class EnbMacMemberLteEnbCmacSapProvider : public LteEnbCmacSapProvider
{
public:
  EnbMacMemberLteEnbCmacSapProvider (mmWaveEnbMac* mac);

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
  mmWaveEnbMac* m_mac;
};


EnbMacMemberLteEnbCmacSapProvider::EnbMacMemberLteEnbCmacSapProvider (mmWaveEnbMac* mac)
  : m_mac (mac)
{
}

void
EnbMacMemberLteEnbCmacSapProvider::ConfigureMac (uint8_t ulBandwidth, uint8_t dlBandwidth)
{
  m_mac->DoConfigureMac (ulBandwidth, dlBandwidth);
}

void
EnbMacMemberLteEnbCmacSapProvider::AddUe (uint16_t rnti)
{
  m_mac->DoAddUe (rnti);
}

void
EnbMacMemberLteEnbCmacSapProvider::RemoveUe (uint16_t rnti)
{
  m_mac->DoRemoveUe (rnti);
}

void
EnbMacMemberLteEnbCmacSapProvider::AddLc (LcInfo lcinfo, LteMacSapUser* msu)
{
  m_mac->DoAddLc (lcinfo, msu);
}

void
EnbMacMemberLteEnbCmacSapProvider::ReconfigureLc (LcInfo lcinfo)
{
  m_mac->DoReconfigureLc (lcinfo);
}

void
EnbMacMemberLteEnbCmacSapProvider::ReleaseLc (uint16_t rnti, uint8_t lcid)
{
  m_mac->DoReleaseLc (rnti, lcid);
}

void
EnbMacMemberLteEnbCmacSapProvider::UeUpdateConfigurationReq (UeConfig params)
{
  m_mac->DoUeUpdateConfigurationReq (params);
}

LteEnbCmacSapProvider::RachConfig
EnbMacMemberLteEnbCmacSapProvider::GetRachConfig ()
{
  return m_mac->DoGetRachConfig ();
}

LteEnbCmacSapProvider::AllocateNcRaPreambleReturnValue
EnbMacMemberLteEnbCmacSapProvider::AllocateNcRaPreamble (uint16_t rnti)
{
  return m_mac->DoAllocateNcRaPreamble (rnti);
}




/* SAP */
// ENB MAC-Phy
class MacEnbMembermmWavePhySapUser : public mmWavePhySapUser
{
public:
	MacEnbMembermmWavePhySapUser (mmWaveEnbMac* mac);

	virtual void ReceivePhyPdu (Ptr<Packet> p);

	virtual void ReceivemmWaveControlMessage (Ptr<mmWaveControlMessages> msg);

	virtual void SubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo);

	virtual void CqiReport (CqiInfo cqi);

	virtual void ReceiveRachPreamble (uint32_t raId);
private:
	mmWaveEnbMac* m_mac;
};

MacEnbMembermmWavePhySapUser::MacEnbMembermmWavePhySapUser (mmWaveEnbMac* mac)
:m_mac(mac)
{

}

void
MacEnbMembermmWavePhySapUser::ReceivePhyPdu (Ptr<Packet> p)
{
	m_mac->PhyPacketRx (p);
}

void
MacEnbMembermmWavePhySapUser::ReceivemmWaveControlMessage (Ptr<mmWaveControlMessages> msg)
{
	m_mac->DoReceivemmWaveControlMessage(msg);
}

void
MacEnbMembermmWavePhySapUser::SubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo)
{
	m_mac->DoSubframeIndication(frameNo, subframeNo, slotNo);
}

void
MacEnbMembermmWavePhySapUser::CqiReport (CqiInfo cqi)
{

}

void
MacEnbMembermmWavePhySapUser::ReceiveRachPreamble (uint32_t raId)
{
	m_mac->ReceiveRachPreamble(raId);
}

// MAC Sched

class MacMemberMacSchedSapUser : public mmWaveMacSchedSapUser
{
public:
	MacMemberMacSchedSapUser (mmWaveEnbMac* mac);
	virtual void SchedConfigInd (const struct SchedConfigIndParameters& params);
private:
	mmWaveEnbMac* m_mac;
};

MacMemberMacSchedSapUser::MacMemberMacSchedSapUser (mmWaveEnbMac* mac)
:m_mac(mac)
{
	/* Some blank spaces*/
}

void
MacMemberMacSchedSapUser::SchedConfigInd (const struct SchedConfigIndParameters& params)
{
	m_mac->DoSchedConfigIndication (params);
}


TypeId
mmWaveEnbMac::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::mmWaveEnbMac")
			.SetParent<mmWaveMac> ()
			.AddConstructor<mmWaveEnbMac> ()
	;
	return tid;
}

mmWaveEnbMac::mmWaveEnbMac (void)
	:mmWaveMac (),
	 m_frameNum (0),
	 m_sfNum (0),
	 m_slotNum (0)
{
	m_cmacSapProvider = new EnbMacMemberLteEnbCmacSapProvider (this);
	m_macSapProvider = new EnbMacMemberLteMacSapProvider<mmWaveEnbMac> (this);

	NS_LOG_FUNCTION (this);
	m_phySapUser = new MacEnbMembermmWavePhySapUser (this);
	m_macSchedSapUser = new MacMemberMacSchedSapUser (this);
}

mmWaveEnbMac::~mmWaveEnbMac (void)
{
	NS_LOG_FUNCTION (this);
}

void
mmWaveEnbMac::DoDispose (void)
{
	NS_LOG_FUNCTION (this);
}

void
mmWaveEnbMac::ReceiveRachPreamble (uint32_t raId)
{
	++m_receivedRachPreambleCount[raId];
}

// forwarded from LteMacSapProvider
void
mmWaveEnbMac::DoTransmitPdu (LteMacSapProvider::TransmitPduParameters params)
{
	LteRadioBearerTag tag (params.rnti, params.lcid, params.layer);
	params.pdu->AddPacketTag (tag);
	bool flag = QueueData(params.pdu);
	NS_ASSERT (flag);
}
void
mmWaveEnbMac::DoReportBufferStatus (LteMacSapProvider::ReportBufferStatusParameters)
{
	//NS_LOG_UNCOND ("***************************************ENB__Reporting buffer staftus");
}


LteMacSapProvider*
mmWaveEnbMac::GetmmWaveMacSapProvider (void)
{
  return m_macSapProvider;
}

LteEnbCmacSapProvider*
mmWaveEnbMac::GetmmWaveEnbCmacSapProvider (void)
{
  return m_cmacSapProvider;
}
void
mmWaveEnbMac::SetmmWaveEnbCmacSapUser (LteEnbCmacSapUser* s)
{
  m_cmacSapUser = s;
}

void
mmWaveEnbMac::DoSubframeIndication (uint32_t frameNo, uint32_t subframeNo, uint32_t slotNo)
{
	m_frameNum = frameNo;
	m_sfNum = subframeNo;
	m_slotNum = slotNo;

	if (!m_receivedRachPreambleCount.empty ())
	{
		Ptr<RarmmWaveControlMessage> rarMsg = Create<RarmmWaveControlMessage> ();

		for (std::map<uint8_t, uint32_t>::const_iterator it = m_receivedRachPreambleCount.begin ();
				it != m_receivedRachPreambleCount.end ();
				++it)
		{
			uint32_t rnti = m_cmacSapUser->AllocateTemporaryCellRnti ();
			NS_LOG_INFO (rnti);
			RarmmWaveControlMessage::Rar rar;
			rar.rapId = (*it).first;
			rar.rarPayload.m_rnti = rnti;
			rarMsg->AddRar (rar);
			NS_ASSERT_MSG((*it).second ==1, "Two user send the same Rach ID, collision detected");
		}
		m_phySapProvider->SendmmWaveControlMessage (rarMsg);
		m_receivedRachPreambleCount.clear ();
	}

	if(m_ReceivedCqi.size () > 0)
	{
		mmWaveMacSchedSapProvider::SchedCqiInfoReqParameters cqiInfoReq;
		cqiInfoReq.m_sfnsf = ((0x3FF & frameNo) << 16) | ((0xFF & subframeNo) << 8) | ((0xFF & slotNo));

		cqiInfoReq.m_cqiList.insert (cqiInfoReq.m_cqiList.begin (), m_ReceivedCqi.begin (), m_ReceivedCqi.end ());
		m_ReceivedCqi.erase (m_ReceivedCqi.begin (), m_ReceivedCqi.end ());

		m_macSchedSapProvider->SchedCqiInfoReq (cqiInfoReq);
	}

	if (m_slotNum==1)
	{
		uint32_t dlSchedFrameNo = m_frameNum;
		uint32_t dlSchedSubframeNo = m_sfNum;

		if (dlSchedSubframeNo + m_PhyMACConfig->GetL1L2CtrlLatency() > m_PhyMACConfig->GetSubframePerFrame() )
		{
		  dlSchedFrameNo++;
		  dlSchedSubframeNo = (dlSchedSubframeNo + m_PhyMACConfig->GetL1L2CtrlLatency()) - m_PhyMACConfig->GetSubframePerFrame();
		}
		else
		{
		  dlSchedSubframeNo = dlSchedSubframeNo + m_PhyMACConfig->GetL1L2CtrlLatency();
		}

		mmWaveMacSchedSapProvider::SchedTriggerReqParameters params;
		uint32_t sfn = ((0x3FF & dlSchedFrameNo) << 16) | ((0xFF & dlSchedSubframeNo) << 8) | ((0xFF & 1));;
		params.m_snfSf = sfn;

		//NS_LOG_UNCOND ("Req for :"<< dlSchedFrameNo << "  "<<dlSchedSubframeNo);

		params.m_ueList = m_associatedUE;
		m_macSchedSapProvider->SchedTriggerReq (params);
		std::map <uint32_t, allocationList>::iterator it = m_scheduleMap.find (sfn);
		m_DataTxAllocationList = (*it).second;
	}

	// Manage Data Tx
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
					flag = true;

					std::map <uint16_t, std::map<uint8_t, LteMacSapUser*> >::iterator rntiIt = m_rlcAttached.find (alMap.m_user.at(i).userImsi);
					if (rntiIt != m_rlcAttached.end ())
					{
						std::map<uint8_t, LteMacSapUser*>::iterator lcidIt = rntiIt->second.begin ();

						for (lcidIt = rntiIt->second.begin (); lcidIt!= rntiIt->second.end (); lcidIt++)
						{
							(*lcidIt).second->NotifyTxOpportunity (alMap.m_user.at(i).m_tbsSize, 0, 0);
						}
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
mmWaveEnbMac::AssociateUeMAC (uint64_t imsi)
{
	//NS_LOG_UNCOND (this<<"Associate UE (imsi:"<< imsi<<" ) with enb");

	//m_associatedUE.push_back (imsi);

}

void
mmWaveEnbMac::SetForwardUpCallback (Callback <void, Ptr<Packet> > cb)
{
	m_forwardUpCallback = cb;
}

void
mmWaveEnbMac::PhyPacketRx (Ptr<Packet> p)
{
	//m_forwardUpCallback (p);

	NS_LOG_FUNCTION (this);
	LteRadioBearerTag tag;
	p->RemovePacketTag (tag);
	uint16_t rnti = tag.GetRnti ();

	uint8_t lcid = tag.GetLcid ();
	std::map <uint16_t, std::map<uint8_t, LteMacSapUser*> >::iterator rntiIt = m_rlcAttached.find (rnti);
	NS_ASSERT_MSG (rntiIt != m_rlcAttached.end (), "could not find RNTI" << rnti);
	std::map<uint8_t, LteMacSapUser*>::iterator lcidIt = rntiIt->second.find (lcid);
	NS_ASSERT_MSG (lcidIt != rntiIt->second.end (), "could not find LCID" << lcid);
	//NS_LOG_UNCOND ("Enb Mac Rx Packet, tag_Rnti:"<<rnti<<" enb_Rnti:"<<(int)(*rntiIt).first);
	(*lcidIt).second->ReceivePdu (p);
}

mmWavePhySapUser*
mmWaveEnbMac::GetmmWavePhySapUser ()
{
	return m_phySapUser;
}

void
mmWaveEnbMac::SetmmWavePhySapProvider (mmWavePhySapProvider* ptr)
{
	m_phySapProvider = ptr;
}

mmWaveMacSchedSapUser*
mmWaveEnbMac::GetmmWaveMacSchedSapUser ()
{
	return m_macSchedSapUser;
}

void
mmWaveEnbMac::SetmmWaveMacSchedSapProvider (mmWaveMacSchedSapProvider* ptr)
{
	m_macSchedSapProvider = ptr;
}

void
mmWaveEnbMac::DoReceivemmWaveControlMessage  (Ptr<mmWaveControlMessages> msg)
{
	NS_LOG_FUNCTION (this << msg);

	switch (msg->GetMessageType())
	{
	case (mmWaveControlMessages::CQI):
	{
		Ptr<mmWaveCqiReport> cqi = DynamicCast<mmWaveCqiReport> (msg);
		CqiInfo cqiElement;
		cqiElement = cqi->GetCqiReport ();
		NS_ASSERT (cqiElement.m_ueId != 0);
		m_ReceivedCqi.push_back (cqiElement);
		break;
	}
	default:
		NS_LOG_INFO ("Control message not supported/expected");
	}

}

void
mmWaveEnbMac::DoSchedConfigIndication (mmWaveMacSchedSapUser::SchedConfigIndParameters ind)
{
	uint16_t allocSize = ind.m_allocationList.m_AllocationMapforSF.size();
	uint16_t patLen = ind.m_tddPattern.m_slotType.size ();

	NS_ASSERT_MSG (allocSize == patLen, "Pattern length and allocation map length should be same");
	//m_DataTxAllocationList.

	m_scheduleMap.insert(std::make_pair(ind.m_sfn, ind.m_allocationList));

	Ptr<mmWaveResourceAllocation> msg = Create<mmWaveResourceAllocation> ();
	msg->SetAllocationMap (ind.m_allocationList);
	msg->SetSchedule (ind.m_tddPattern);
	msg->SetSFNSF (ind.m_sfn);
	/*uint32_t key = msg->GetSFNSF ();
	NS_LOG_UNCOND("Frame Num"<< (key >> 16) <<" Subframe Num:" << ((key & 0xff00)>>8) );*/
	m_phySapProvider->SendmmWaveControlMessage (msg);

}
// ////////////////////////////////////////////
// CMAC SAP
// ////////////////////////////////////////////

void
mmWaveEnbMac::DoConfigureMac (uint8_t ulBandwidth, uint8_t dlBandwidth)
{
  NS_LOG_FUNCTION (this << " ulBandwidth=" << (uint16_t) ulBandwidth << " dlBandwidth=" << (uint16_t) dlBandwidth);
}


void
mmWaveEnbMac::DoAddUe (uint16_t rnti)
{
	NS_LOG_FUNCTION (this << " rnti=" << rnti);
	std::map<uint8_t, LteMacSapUser*> empty;
	std::pair <std::map <uint16_t, std::map<uint8_t, LteMacSapUser*> >::iterator, bool>
	  ret = m_rlcAttached.insert (std::pair <uint16_t,  std::map<uint8_t, LteMacSapUser*> >
								  (rnti, empty));
	m_associatedUE.push_back (rnti);
	NS_ASSERT_MSG (ret.second, "element already present, RNTI already existed");

}

void
mmWaveEnbMac::DoRemoveUe (uint16_t rnti)
{
  NS_LOG_FUNCTION (this << " rnti=" << rnti);
}

void
mmWaveEnbMac::DoAddLc (LteEnbCmacSapProvider::LcInfo lcinfo, LteMacSapUser* msu)
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
mmWaveEnbMac::DoReconfigureLc (LteEnbCmacSapProvider::LcInfo lcinfo)
{
  NS_FATAL_ERROR ("not implemented");
}

void
mmWaveEnbMac::DoReleaseLc (uint16_t rnti, uint8_t lcid)
{
  NS_FATAL_ERROR ("not implemented");
}

void
mmWaveEnbMac::DoUeUpdateConfigurationReq (LteEnbCmacSapProvider::UeConfig params)
{
  NS_LOG_FUNCTION (this);
  //FfMacCschedSapProvider::CschedUeConfigReqParameters req;
  //req.m_rnti = params.m_rnti;
  //req.m_transmissionMode = params.m_transmissionMode;
  //req.m_reconfigureFlag = true;
  //m_macScheduler->CschedUeConfigReq (req);
}

LteEnbCmacSapProvider::RachConfig
mmWaveEnbMac::DoGetRachConfig ()
{
  struct LteEnbCmacSapProvider::RachConfig rc;
  return rc;
}

LteEnbCmacSapProvider::AllocateNcRaPreambleReturnValue
mmWaveEnbMac::DoAllocateNcRaPreamble (uint16_t rnti)
{
  LteEnbCmacSapProvider::AllocateNcRaPreambleReturnValue ret;
  return ret;
}

}
