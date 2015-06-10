/*
 * mmwave-ue-phy.cc
 *
 *  Created on: Nov 5, 2014
 *      Author: sourjya
 */

#include <ns3/object-factory.h>
#include <ns3/log.h>
#include <cfloat>
#include <cmath>
#include <ns3/simulator.h>
#include <ns3/double.h>
#include "mmwave-ue-phy.h"
#include "mmwave-ue-net-device.h"
#include "mmwave-spectrum-value-helper.h"
#include <ns3/pointer.h>


namespace ns3{

NS_LOG_COMPONENT_DEFINE ("mmWaveUePhy");

NS_OBJECT_ENSURE_REGISTERED (mmWaveUePhy);

mmWaveUePhy::mmWaveUePhy ()
{
	NS_LOG_FUNCTION (this);
	NS_FATAL_ERROR ("This constructor should not be called");
}

mmWaveUePhy::mmWaveUePhy (Ptr<mmWaveSpectrumPhy> dlPhy, Ptr<mmWaveSpectrumPhy> ulPhy)
: mmWavePhy(dlPhy, ulPhy),
  m_nrsubframe (0),
  m_nrFrame (0),
  m_AllocatedBandwidth (0),
  m_packetChunkSize (500),//Just an arbitrary default value
  m_prevSlot (2),
  m_ReceptionEnabled (false)
{
	NS_LOG_FUNCTION (this);

	//m_amc = CreateObject <mmWaveAmc> (m_PhyMACConfig);

	m_ueCphySapProvider = new MemberLteUeCphySapProvider<mmWaveUePhy> (this);
	Simulator::ScheduleNow (&mmWaveUePhy::SubframeIndication, this, 1, 1);

	m_packetBurstQueue.clear ();
	Ptr<PacketBurst> pb = CreateObject <PacketBurst> ();
	m_packetBurstQueue.push_back (pb);
}

mmWaveUePhy::~mmWaveUePhy ()
{
	NS_LOG_FUNCTION (this);
}

TypeId
mmWaveUePhy::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::mmWaveUePhy")
	    .SetParent<mmWavePhy> ()
	    .AddConstructor<mmWaveUePhy> ()
	    .AddAttribute ("TxPower",
	                   "Transmission power in dBm",
	                   DoubleValue (30.0), //TBD zml
	                   MakeDoubleAccessor (&mmWaveUePhy::SetTxPower,
	                                       &mmWaveUePhy::GetTxPower),
	                   MakeDoubleChecker<double> ())
		.AddAttribute ("DlSpectrumPhy",
					    "The downlink mmWaveSpectrumPhy associated to this mmWavePhy",
					    TypeId::ATTR_GET,
					    PointerValue (),
					    MakePointerAccessor (&mmWaveUePhy::GetDlSpectrumPhy),
					    MakePointerChecker <mmWaveSpectrumPhy> ())
		.AddAttribute ("UlSpectrumPhy",
					    "The uplink mmWaveSpectrumPhy associated to this mmWavePhy",
					    TypeId::ATTR_GET,
					    PointerValue (),
					    MakePointerAccessor (&mmWaveUePhy::GetUlSpectrumPhy),
					    MakePointerChecker <mmWaveSpectrumPhy> ())
		.AddTraceSource ("ReportCurrentCellRsrpSinr",
						 "RSRP and SINR statistics.",
						 MakeTraceSourceAccessor (&mmWaveUePhy::m_reportCurrentCellRsrpSinrTrace))
		.AddTraceSource ("ReportUplinkTbSize",
						 "Report allocated uplink TB size for trace.",
						 MakeTraceSourceAccessor (&mmWaveUePhy::m_reportULTbSize))
		.AddTraceSource ("ReportDownlinkTbSize",
						 "Report allocated downlink TB size for trace.",
						 MakeTraceSourceAccessor (&mmWaveUePhy::m_reportDLTbSize))
;

	return tid;
}

void
mmWaveUePhy::DoInitialize (void)
{
	NS_LOG_FUNCTION (this);
	mmWavePhy::DoInitialize ();
}

void
mmWaveUePhy::DoDispose (void)
{

}

void
mmWaveUePhy::SetmmWaveUeCphySapUser (LteUeCphySapUser* s)
{
  NS_LOG_FUNCTION (this);
  m_ueCphySapUser = s;
}

LteUeCphySapProvider*
mmWaveUePhy::GetmmWaveUeCphySapProvider ()
{
  NS_LOG_FUNCTION (this);
  return (m_ueCphySapProvider);
}

void
mmWaveUePhy::SetTxPower (double pow)
{
	m_txPower = pow;
}
double
mmWaveUePhy::GetTxPower () const
{
	return m_txPower;
}

void
mmWaveUePhy::SetNoiseFigure (double pf)
{

}

double
mmWaveUePhy::GetNoiseFigure () const
{
	return m_noiseFigure;
}

bool
mmWaveUePhy::SendPacket(Ptr<Packet> packet)
{
	SetMacData (packet);
	return true;
}

Ptr<SpectrumValue>
mmWaveUePhy::CreateTxPowerSpectralDensity()
{
	Ptr<SpectrumValue> psd =
				mmWaveSpectrumValueHelper::CreateTxPowerSpectralDensity (m_PhyMACConfig, m_txPower, m_subChannelsForTx );
	return psd;
}

void
mmWaveUePhy::DoSetSubChannels()
{

}

void
mmWaveUePhy::SetSubChannelsForReception(std::vector <int> mask)
{

}

std::vector <int>
mmWaveUePhy::GetSubChannelsForReception(void)
{
	std::vector <int> vec;

	return vec;
}

void
mmWaveUePhy::SetSubChannelsForTransmission(std::vector <int> mask)
{
	m_subChannelsForTx = mask;
	Ptr<SpectrumValue> txPsd = CreateTxPowerSpectralDensity ();
	NS_ASSERT (txPsd);
	m_downlinkSpectrumPhy->SetTxPowerSpectralDensity (txPsd);
}

std::vector <int>
mmWaveUePhy::GetSubChannelsForTransmission(void)
{
	std::vector <int> vec;

	return vec;
}

void
mmWaveUePhy::DoSendmmWaveControlMessage (Ptr<mmWaveControlMessages> msg)
{
  NS_LOG_FUNCTION (this << msg);
  SetControlMessages (msg);
}


void
mmWaveUePhy::RegisterToEnb (uint16_t cellId, Ptr<mmWavePhyMacCommon> config)
{
	m_cellId = cellId;
	//TBD how to assign bandwitdh and earfcn
	m_noiseFigure = 5.0;
	m_PhyMACConfig = config;

	Ptr<SpectrumValue> noisePsd =
			mmWaveSpectrumValueHelper::CreateNoisePowerSpectralDensity (m_PhyMACConfig, m_noiseFigure);
	m_downlinkSpectrumPhy->SetNoisePowerSpectralDensity (noisePsd);
	m_downlinkSpectrumPhy->GetSpectrumChannel()->AddRx(m_downlinkSpectrumPhy);
	m_downlinkSpectrumPhy->SetCellId(m_cellId);
}

Ptr<mmWaveSpectrumPhy>
mmWaveUePhy::GetDlSpectrumPhy () const
{
  return m_downlinkSpectrumPhy;
}

Ptr<mmWaveSpectrumPhy>
mmWaveUePhy::GetUlSpectrumPhy () const
{
  return m_uplinkSpectrumPhy;
}

void
mmWaveUePhy::ReceivemmWaveControlMessageList (std::list<Ptr<mmWaveControlMessages> > msgList, uint32_t cellId)
{
	NS_LOG_FUNCTION (this);

	std::list<Ptr<mmWaveControlMessages> >::iterator it;
	for (it = msgList.begin (); it != msgList.end (); it++)
	{
	    Ptr<mmWaveControlMessages> msg = (*it);

	    if (msg->GetMessageType() == mmWaveControlMessages::RSC_ALLOCATION)
	    {
	    	m_phySapUser->ReceivemmWaveControlMessage(msg);
	    	Ptr<mmWaveResourceAllocation> rscAllocMsg= DynamicCast<mmWaveResourceAllocation> (msg);
	    	uint32_t sfnsf = rscAllocMsg->GetSFNSF ();
	    	std::map <uint32_t, Schedule>::iterator pIt = m_TDDPatternsFrorSF.find(sfnsf);
	    	if ( pIt == m_TDDPatternsFrorSF.end ())
	    	{
	    		m_TDDPatternsFrorSF.insert (std::pair <uint32_t, Schedule> (sfnsf, rscAllocMsg->GetSchedule()));
	    	}

	    	std::map <uint32_t, allocationList>::iterator alIt = m_AllocationListforSF.find(sfnsf);

	    	if (alIt == m_AllocationListforSF.end ())
	    	{
	    		m_AllocationListforSF.insert (std::pair <uint32_t,allocationList> (sfnsf,rscAllocMsg->GetAllocationMap()));
	    	}

	    }
	    else if (msg->GetMessageType () == mmWaveControlMessages::MIB)
		{

			NS_LOG_INFO ("received MIB");
			NS_ASSERT (m_cellId > 0);
			Ptr<MibmmWaveControlMessage> msg2 = DynamicCast<MibmmWaveControlMessage> (msg);
			m_ueCphySapUser->RecvMasterInformationBlock (m_cellId, msg2->GetMib ());
		}
		else if (msg->GetMessageType () == mmWaveControlMessages::SIB1)
		{
			NS_ASSERT (m_cellId > 0);
			Ptr<Sib1mmWaveControlMessage> msg2 = DynamicCast<Sib1mmWaveControlMessage> (msg);
			m_ueCphySapUser->RecvSystemInformationBlockType1 (m_cellId, msg2->GetSib1 ());
		}
		else if (msg->GetMessageType () == mmWaveControlMessages::RAR)
		{
			NS_LOG_INFO ("received RAR");
			NS_ASSERT (m_cellId > 0);

			Ptr<RarmmWaveControlMessage> rarMsg = DynamicCast<RarmmWaveControlMessage> (msg);

			for (std::list<RarmmWaveControlMessage::Rar>::const_iterator it = rarMsg->RarListBegin ();
							   it != rarMsg->RarListEnd ();
							   ++it)
			{
				if (it->rapId == m_raPreambleId)
				{
					m_phySapUser->ReceivemmWaveControlMessage (rarMsg);
				}
			}

		}

	    else
	    {
	    	NS_LOG_DEBUG ("Control message not handled. Type: "<< msg->GetMessageType());
	    }
	}
}

void
mmWaveUePhy::SubframeIndication (uint32_t frameNo, uint32_t subframeNo)
{
	/* Do a bunch of stuff here */
	uint16_t DevRnti = GetRnti ();
	uint64_t imsi = GetDevice ()->GetObject <mmWaveUeNetDevice> ()->GetImsi(); //for tracing

	m_nrsubframe = subframeNo;
	m_nrFrame = frameNo;

	ResetReception ();

	uint32_t slotNo = ((subframeNo-1)%m_PhyMACConfig->GetSlotPerSubframe ()) + 1;
	uint32_t sfNo = ((subframeNo-1)/m_PhyMACConfig->GetSlotPerSubframe ()) + 1;

	//uint32_t sfnsf = ((0x3FF & frameNo) << 16) | ((0xFF & sfNo) << 8) | ((0xFF & slotNo));

	if (slotNo == 1)
	{
		UpdateCurrentAllocationAndSchedule (frameNo, sfNo);
	}

	std::list<allocationMap>::const_iterator it = m_CurrentAllocationList.m_AllocationMapforSF.begin();
	allocationMap AllocMap = (*it);
	bool isUL = m_CurrentAllocationList.m_AllocationMapforSF.front().m_IsUL;

	m_CurrentAllocationList.m_AllocationMapforSF.pop_front ();

	slotType stype = m_CurrentTDDMap.m_slotType.at (slotNo-1);

	/*set tbSize for Downlink Rx, only consider that 1 user uses the whole bandwidth*/
	if( stype == DATA)
	{
		if(!isUL)
		{
			uint8_t rbs = m_PhyMACConfig->GetRBperSlot ();
			uint8_t chunksPerRb = m_PhyMACConfig->GetNumChunkPerRB ();
			std::map <uint16_t, tbInfo_t> tbMap;

			for (int i = 0; i < rbs; i++)
			{
				uint16_t rnti = AllocMap.m_user.at (i).userImsi;

				tbInfo_t tbInfo;
				tbInfo.size = AllocMap.m_user.at (i).m_tbsSize;
				tbInfo.mcs = AllocMap.m_user.at (i).m_mcs;
				std::map <uint16_t, tbInfo_t>::const_iterator it = tbMap.find (rnti);
				if(it == tbMap.end ())
				{
					tbMap.insert (std::make_pair (rnti, tbInfo));
				}
				else
				{
					tbInfo.size += (*it).second.size;
					tbMap.erase (rnti);
					tbMap.insert (std::make_pair(rnti, tbInfo));

				}
			}
			std::map <uint16_t, tbInfo_t>::const_iterator iter;
			for (iter = tbMap.begin (); iter != tbMap.end (); iter++)
			{
				std::vector<int> rbMap;
				for(uint8_t rbId = 0; rbId < rbs; rbId++)
				{
					if (AllocMap.m_user.at (rbId).userImsi == (*iter).first)
					{
						for (uint16_t chunkId = 0; chunkId<chunksPerRb; chunkId++)
						{
							rbMap.push_back (chunkId + chunksPerRb*rbId);
						}
					}
				}
				m_downlinkSpectrumPhy->AddExpectedTb((*iter).first, (*iter).second.size, (*iter).second.mcs, rbMap, true);
			}
		}
	}//end calc expected tbSize


	Time dataPeriod = Seconds (GetTti());
	Time delay  = MicroSeconds (0);
	if (m_prevSlot!=2 && m_prevSlot!=(int)isUL)
	{
		delay = MicroSeconds (1);
	}
	dataPeriod = dataPeriod - delay  - NanoSeconds (1);/*-1ns as margin to avoid overlapping simulator events*/
	m_prevSlot = (int)isUL;

	if (isUL == true)
	{
		uint16_t rbSize = m_PhyMACConfig->GetNumChunkPerRB();
		uint32_t Bandwidth_alloc = 0;
		uint64_t totalTbSize = 0;
		for (uint16_t i = 0; i < m_PhyMACConfig->GetRBperSlot(); i++)
		{
			if ( ( AllocMap.m_user.at (i).userImsi == DevRnti) || (AllocMap.m_user.at (i).noAllocation == true))
			{
				Bandwidth_alloc = Bandwidth_alloc + rbSize;
				totalTbSize = totalTbSize + AllocMap.m_user.at (i).m_tbsSize; //trace
			}
		}

		m_reportULTbSize (imsi, totalTbSize);

		if (Bandwidth_alloc != 0)
		{
			m_AllocatedBandwidth = Bandwidth_alloc;
			std::vector <int> channelRb;
			for (int j = 0; j < m_AllocatedBandwidth; j++)
			{
				channelRb.push_back (j);
			}
			SetSubChannelsForTransmission (channelRb);

			if (stype == DATA)
			{
				Ptr<PacketBurst> pb = GetPacketBurst ();
				if (pb)
				{
					Simulator::Schedule (delay, &mmWaveUePhy::SendDataChannel, this, pb, dataPeriod);
				}
			}
			else if (stype == CTRL)
			{
				std::list<Ptr<mmWaveControlMessages> > ctrlMsg = GetControlMessages ();
				if (ctrlMsg.size() > 0)
				{
					Simulator::Schedule (delay, &mmWaveUePhy::SendControlChannels, this, ctrlMsg, dataPeriod);
				}
			}
		}

	}
	else if (!isUL)
	{
		uint64_t totalTbSize = 0;
		for (uint16_t i = 0; i < m_PhyMACConfig->GetRBperSlot(); i++)
		{
			if ( AllocMap.m_user.at (i).userImsi == DevRnti )
			{
				m_ReceptionEnabled = true;if (stype == DATA)
				{
					totalTbSize = totalTbSize + AllocMap.m_user.at (i).m_tbsSize;
				}
				else
				{
					break;
				}
			}
		}
		if (stype == DATA)
		{
			m_reportDLTbSize (imsi, totalTbSize);
		}

	}
	/*triger mac*/
	m_phySapUser->SubframeIndication (frameNo, subframeNo,slotNo);


	if (subframeNo == m_PhyMACConfig->GetSlotPerSubframe () * m_PhyMACConfig->GetSubframePerFrame ())
	{
		subframeNo = 1;
		frameNo++;
	}
	else
	{
		subframeNo++;
	}


	Simulator::Schedule (Seconds(GetTti()), &mmWaveUePhy::SubframeIndication, this, frameNo, subframeNo);

}

uint32_t
mmWaveUePhy::GetSubframeNumber (void)
{
	return m_nrsubframe;
}

void
mmWaveUePhy::PhyDataPacketReceived (Ptr<Packet> p)
{
	m_phySapUser->ReceivePhyPdu (p);
}

void
mmWaveUePhy::SetForwardUpCallback (Callback <void, Ptr<Packet> > cb)
{
	m_forwardUpCallback = cb;
}

void
mmWaveUePhy::SendDataChannel (Ptr<PacketBurst> pb, Time duration)
{
	std::list<Ptr<mmWaveControlMessages> > ctrlMsg ;
	ctrlMsg.clear();
	m_downlinkSpectrumPhy->StartTxDataFrames (pb, ctrlMsg, duration);
}

void
mmWaveUePhy::SendControlChannels (std::list<Ptr<mmWaveControlMessages> > ctrlMsg, Time prd)
{
	m_downlinkSpectrumPhy->StartTxDlControlFrames(ctrlMsg,prd);
}


uint32_t
mmWaveUePhy::GetAbsoulteSubframeNo ()
{
	return ((m_nrFrame-1)*8 + m_nrsubframe);
}

void
mmWaveUePhy::SetMacData (Ptr<Packet> p)
{
	if ( (m_packetBurstQueue.at (m_packetBurstQueue.size () - 1)->GetSize () + p->GetSize ()) <= m_packetChunkSize )
	{
		m_packetBurstQueue.at (m_packetBurstQueue.size () - 1)->AddPacket (p);
	}
	else
	{
		m_packetBurstQueue.push_back (CreateObject <PacketBurst> ());
		m_packetBurstQueue.at (m_packetBurstQueue.size () - 1)->AddPacket (p);
	}
}

Ptr<mmWaveCqiReport>
mmWaveUePhy::CreateDlCqiFeedbackMessage (const SpectrumValue& sinr)
{
	if (!m_amc)
	{
		m_amc = CreateObject <mmWaveAmc> (m_PhyMACConfig);
	}
	NS_LOG_FUNCTION (this);
	SpectrumValue newSinr = sinr;
	// CREATE DlCqiLteControlMessage
	Ptr<mmWaveCqiReport> msg = Create<mmWaveCqiReport> ();
	CqiInfo dlcqi;

	dlcqi.m_ueId = m_netDevice->GetObject<mmWaveUeNetDevice> ()->GetImsi ();

	std::vector<int> cqi;

	uint8_t dlBandwidth = m_PhyMACConfig->GetNumChunkPerRB ();

	cqi = m_amc->CreateCqiFeedbacks (newSinr, dlBandwidth);
	int nbSubChannels = cqi.size ();
	double cqiSum = 0.0;
	int activeSubChannels = 0;
	// average the CQIs of the different RBs
	for (int i = 0; i < nbSubChannels; i++)
	{
		if (cqi.at (i) != -1)
		{
			cqiSum += cqi.at (i);
			activeSubChannels++;
		}
		NS_LOG_DEBUG (this << " subch " << i << " cqi " <<  cqi.at (i));
	}
	if (activeSubChannels > 0)
	{
		dlcqi.m_wbCqi = ((uint16_t) cqiSum / activeSubChannels);
	}
	else
	{
		// approximate with the worst case -> CQI = 1
		dlcqi.m_wbCqi = 1;
	}
	msg->SetCqiReport(dlcqi);
	return msg;
}

void
mmWaveUePhy::GenerateDlCqiReport (const SpectrumValue& sinr)
{
	SpectrumValue newSinr = sinr;
	Ptr<mmWaveCqiReport> msg = CreateDlCqiFeedbackMessage (newSinr);

    if (msg)
	{
    	DoSendmmWaveControlMessage (msg);
	}
    Ptr<mmWaveUeNetDevice> UeRx = DynamicCast<mmWaveUeNetDevice> (GetDevice());
    m_reportCurrentCellRsrpSinrTrace (UeRx->GetImsi(), newSinr, newSinr/* Power*/);
}

bool
mmWaveUePhy::IsReceptionEnabled ()
{
	return m_ReceptionEnabled;
}

void
mmWaveUePhy::ResetReception()
{
	m_ReceptionEnabled = false;
}

uint16_t
mmWaveUePhy::GetRnti ()
{
	return m_rnti;
}


void
mmWaveUePhy::DoReset ()
{
	NS_LOG_FUNCTION (this);
}

void
mmWaveUePhy::DoStartCellSearch (uint16_t dlEarfcn)
{
	NS_LOG_FUNCTION (this << dlEarfcn);
}

void
mmWaveUePhy::DoSynchronizeWithEnb (uint16_t cellId, uint16_t dlEarfcn)
{
	NS_LOG_FUNCTION (this << cellId << dlEarfcn);
	DoSynchronizeWithEnb (cellId);
}

void
mmWaveUePhy::DoSynchronizeWithEnb (uint16_t cellId)
{
	NS_LOG_FUNCTION (this << cellId);
	if (cellId == 0)
	{
		NS_FATAL_ERROR ("Cell ID shall not be zero");
	}
	/*
	m_cellId = cellId;
	//TBD how to assign bandwitdh and earfcn
	m_noiseFigure = 5.0;
	//m_Bandwidth = BANDWIDTH;
	//m_earfcn = 1;

	Ptr<SpectrumValue> noisePsd =
			mmWaveSpectrumValueHelper::CreateNoisePowerSpectralDensity (m_earfcn, m_Bandwidth, m_noiseFigure);
	m_downlinkSpectrumPhy->SetNoisePowerSpectralDensity (noisePsd);
	m_downlinkSpectrumPhy->GetSpectrumChannel()->AddRx(m_downlinkSpectrumPhy);
	m_downlinkSpectrumPhy->SetCellId(m_cellId);*/
}

void
mmWaveUePhy::DoSetDlBandwidth (uint8_t dlBandwidth)
{
	NS_LOG_FUNCTION (this << (uint32_t) dlBandwidth);
}


void
mmWaveUePhy::DoConfigureUplink (uint16_t ulEarfcn, uint8_t ulBandwidth)
{
	NS_LOG_FUNCTION (this << ulEarfcn << ulBandwidth);
}

void
mmWaveUePhy::DoConfigureReferenceSignalPower (int8_t referenceSignalPower)
{
	NS_LOG_FUNCTION (this << referenceSignalPower);
}

void
mmWaveUePhy::DoSetRnti (uint16_t rnti)
{
	m_rnti = rnti;
	NS_LOG_FUNCTION (this << rnti);
}

void
mmWaveUePhy::DoSetTransmissionMode (uint8_t txMode)
{
	NS_LOG_FUNCTION (this << (uint16_t)txMode);
}

void
mmWaveUePhy::DoSetSrsConfigurationIndex (uint16_t srcCi)
{
	NS_LOG_FUNCTION (this << srcCi);
}

}


