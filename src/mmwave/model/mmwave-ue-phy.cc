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

NS_LOG_COMPONENT_DEFINE ("MmWaveUePhy");

NS_OBJECT_ENSURE_REGISTERED (MmWaveUePhy);

MmWaveUePhy::MmWaveUePhy ()
{
	NS_LOG_FUNCTION (this);
	NS_FATAL_ERROR ("This constructor should not be called");
}

MmWaveUePhy::MmWaveUePhy (Ptr<MmWaveSpectrumPhy> dlPhy, Ptr<MmWaveSpectrumPhy> ulPhy)
: MmWavePhy(dlPhy, ulPhy),
  m_nrSlots (0),
  m_nrFrames (0),
  m_prevSlot (0)
{
	NS_LOG_FUNCTION (this);
	m_wbCqiLast = Simulator::Now ();
	m_ueCphySapProvider = new MemberLteUeCphySapProvider<MmWaveUePhy> (this);
	m_pucchSlotInd = 2; // default slot containing dedicated UL control channel
	Simulator::ScheduleNow (&MmWaveUePhy::SubframeIndication, this, 1, 1);}

MmWaveUePhy::~MmWaveUePhy ()
{
	NS_LOG_FUNCTION (this);
}

TypeId
MmWaveUePhy::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::MmWaveUePhy")
	    .SetParent<MmWavePhy> ()
	    .AddConstructor<MmWaveUePhy> ()
	    .AddAttribute ("TxPower",
	                   "Transmission power in dBm",
	                   DoubleValue (30.0), //TBD zml
	                   MakeDoubleAccessor (&MmWaveUePhy::SetTxPower,
	                                       &MmWaveUePhy::GetTxPower),
	                   MakeDoubleChecker<double> ())
		.AddAttribute ("DlSpectrumPhy",
					    "The downlink MmWaveSpectrumPhy associated to this MmWavePhy",
					    TypeId::ATTR_GET,
					    PointerValue (),
					    MakePointerAccessor (&MmWaveUePhy::GetDlSpectrumPhy),
					    MakePointerChecker <MmWaveSpectrumPhy> ())
		.AddAttribute ("UlSpectrumPhy",
					    "The uplink MmWaveSpectrumPhy associated to this MmWavePhy",
					    TypeId::ATTR_GET,
					    PointerValue (),
					    MakePointerAccessor (&MmWaveUePhy::GetUlSpectrumPhy),
					    MakePointerChecker <MmWaveSpectrumPhy> ())
		.AddTraceSource ("ReportCurrentCellRsrpSinr",
						 "RSRP and SINR statistics.",
						 MakeTraceSourceAccessor (&MmWaveUePhy::m_reportCurrentCellRsrpSinrTrace))
		.AddTraceSource ("ReportUplinkTbSize",
						 "Report allocated uplink TB size for trace.",
						 MakeTraceSourceAccessor (&MmWaveUePhy::m_reportUlTbSize))
		.AddTraceSource ("ReportDownlinkTbSize",
						 "Report allocated downlink TB size for trace.",
						 MakeTraceSourceAccessor (&MmWaveUePhy::m_reportDlTbSize))
;

	return tid;
}

void
MmWaveUePhy::DoInitialize (void)
{
	NS_LOG_FUNCTION (this);
	m_ctrlPeriod = NanoSeconds (1000 * m_phyMacConfig->GetCtrlSymbols() * m_phyMacConfig->GetSymbolPeriod());
	m_dataPeriod = NanoSeconds (1000 * (m_phyMacConfig->GetSymbPerSlot() - m_phyMacConfig->GetCtrlSymbols()) * m_phyMacConfig->GetSymbolPeriod());
	m_numRbg = m_phyMacConfig->GetNumRb () / m_phyMacConfig->GetNumRbPerRbg ();
	m_ulTbAllocQueue.resize (m_phyMacConfig->GetUlSchedDelay());
	MmWavePhy::DoInitialize ();
}

void
MmWaveUePhy::DoDispose (void)
{

}

void
MmWaveUePhy::SetUeCphySapUser (LteUeCphySapUser* s)
{
  NS_LOG_FUNCTION (this);
  m_ueCphySapUser = s;
}

LteUeCphySapProvider*
MmWaveUePhy::GetUeCphySapProvider ()
{
  NS_LOG_FUNCTION (this);
  return (m_ueCphySapProvider);
}

void
MmWaveUePhy::SetTxPower (double pow)
{
	m_txPower = pow;
}
double
MmWaveUePhy::GetTxPower () const
{
	return m_txPower;
}

void
MmWaveUePhy::SetNoiseFigure (double pf)
{

}

double
MmWaveUePhy::GetNoiseFigure () const
{
	return m_noiseFigure;
}

Ptr<SpectrumValue>
MmWaveUePhy::CreateTxPowerSpectralDensity()
{
	Ptr<SpectrumValue> psd =
				mmWaveSpectrumValueHelper::CreateTxPowerSpectralDensity (m_phyMacConfig, m_txPower, m_subChannelsForTx );
	return psd;
}

void
MmWaveUePhy::DoSetSubChannels()
{

}

void
MmWaveUePhy::SetSubChannelsForReception(std::vector <int> mask)
{

}

std::vector <int>
MmWaveUePhy::GetSubChannelsForReception(void)
{
	std::vector <int> vec;

	return vec;
}

void
MmWaveUePhy::SetSubChannelsForTransmission(std::vector <int> mask)
{
	m_subChannelsForTx = mask;
	Ptr<SpectrumValue> txPsd = CreateTxPowerSpectralDensity ();
	NS_ASSERT (txPsd);
	m_downlinkSpectrumPhy->SetTxPowerSpectralDensity (txPsd);
}

std::vector <int>
MmWaveUePhy::GetSubChannelsForTransmission(void)
{
	std::vector <int> vec;

	return vec;
}

void
MmWaveUePhy::DoSendControlMessage (Ptr<MmWaveControlMessage> msg)
{
  NS_LOG_FUNCTION (this << msg);
  SetControlMessage (msg);
}


void
MmWaveUePhy::RegisterToEnb (uint16_t cellId, Ptr<MmWavePhyMacCommon> config)
{
	m_cellId = cellId;
	//TBD how to assign bandwitdh and earfcn
	m_noiseFigure = 5.0;
	m_phyMacConfig = config;

	Ptr<SpectrumValue> noisePsd =
			mmWaveSpectrumValueHelper::CreateNoisePowerSpectralDensity (m_phyMacConfig, m_noiseFigure);
	m_downlinkSpectrumPhy->SetNoisePowerSpectralDensity (noisePsd);
	m_downlinkSpectrumPhy->GetSpectrumChannel()->AddRx(m_downlinkSpectrumPhy);
	m_downlinkSpectrumPhy->SetCellId(m_cellId);
}

Ptr<MmWaveSpectrumPhy>
MmWaveUePhy::GetDlSpectrumPhy () const
{
  return m_downlinkSpectrumPhy;
}

Ptr<MmWaveSpectrumPhy>
MmWaveUePhy::GetUlSpectrumPhy () const
{
  return m_uplinkSpectrumPhy;
}

void
MmWaveUePhy::ReceiveControlMessageList (std::list<Ptr<MmWaveControlMessage> > msgList)
{
	NS_LOG_FUNCTION (this);

	uint32_t slotInd = ((m_nrSlots-1)%m_phyMacConfig->GetSlotsPerSubframe ()) + 1;
	uint32_t sfInd= ((m_nrSlots-1)/m_phyMacConfig->GetSlotsPerSubframe ()) + 1;

	if(slotInd == 1 && !m_sfAllocInfoUpdated) 		// reset SF allocation info prior to DCI reception
	{
		NS_LOG_DEBUG ("UE resetting alloc info for subframe " << sfInd);
		m_currSfAllocInfo = SfAllocationInfo (m_phyMacConfig->GetSlotsPerSubframe ());
		m_sfAllocInfoUpdated = true;
	}

	std::list<Ptr<MmWaveControlMessage> >::iterator it;
	for (it = msgList.begin (); it != msgList.end (); it++)
	{
		Ptr<MmWaveControlMessage> msg = (*it);

		if (msg->GetMessageType() == MmWaveControlMessage::DCI)
		{
			Ptr<MmWaveDciMessage> dciMsg = DynamicCast<MmWaveDciMessage> (msg);
			DciInfoElement dciInfoElem = dciMsg->GetDciInfoElement ();
			if (dciInfoElem.m_rnti != m_rnti)
			{
				continue; // DCI not for me
			}
			//NS_LOG_UNCOND ("===========Received DCI");

			// process TB info elements and set SF schedule
			for (std::vector<TbInfoElement>::const_iterator tbIt = dciInfoElem.m_tbInfoElements.begin(); \
			tbIt != dciInfoElem.m_tbInfoElements.end(); tbIt++)
			{
				// loop through TB info elements (can be multiple per DCI)
				SlotAllocInfo* slotInfo; // get reference to slot information
				SlotAllocInfo::TddMode slotMode;
				bool ulSlot = ((dciInfoElem.m_tddBitmap >> tbIt->m_slotInd) & 0x1);
				if (ulSlot)
				{
					slotMode = SlotAllocInfo::UL;
					NS_ASSERT ((tbIt->m_slotInd % 2) == 1);
				}
				else
				{
					slotMode = SlotAllocInfo::DL;
				}
				if (slotMode == SlotAllocInfo::DL)
				{
					// Downlink TbInfoElement applies to current subframe
					slotInfo = &(m_currSfAllocInfo.m_slotAllocInfo[tbIt->m_slotInd]); // DL res alloc info, applies to this subframe
					if (m_currSfAllocInfo.m_tddPattern[tbIt->m_slotInd] == SlotAllocInfo::NA)
					{
						m_currSfAllocInfo.m_tddPattern[tbIt->m_slotInd] = SlotAllocInfo::DL;
					}
					else if (m_currSfAllocInfo.m_tddPattern[tbIt->m_slotInd] == SlotAllocInfo::UL)
					{
						NS_LOG_ERROR ("Slot already assigned in DL");
					}
					TbAllocInfo tbAllocInfo;
					tbAllocInfo.m_rnti = dciInfoElem.m_rnti;
					tbAllocInfo.m_tbInfo = *tbIt;
					for (unsigned irbg = 0; irbg < m_numRbg; irbg++) // assumes res alloc type 0
					{
						if((tbIt->m_rbBitmap >> irbg) & 0x1)
						{
							for (unsigned irb = 0; irb < m_phyMacConfig->GetNumRbPerRbg (); irb++)
							{
								// add all RBs for allocated RBGs to rbMap
								tbAllocInfo.m_rbMap.push_back (irbg * m_phyMacConfig->GetNumRbPerRbg () + irb);
							}
						}
					}
					slotInfo->m_tbInfo.push_back (tbAllocInfo);
				}
				else if (slotMode == SlotAllocInfo::UL)
				{
					// Uplink TbInfoElement applies to n+3th subframe
					TbAllocInfo tbAllocInfo;
					tbAllocInfo.m_rnti = dciInfoElem.m_rnti;
					tbAllocInfo.m_tbInfo = *tbIt;
					for (unsigned irb = 0; irb < tbAllocInfo.m_tbInfo.m_rbLen; irb++) // assumes res alloc type 0
					{
						tbAllocInfo.m_rbMap.push_back (tbAllocInfo.m_tbInfo.m_rbStart + irb);
					}
					QueueUlTbAlloc (tbAllocInfo);
				}
			}
			m_phySapUser->ReceiveControlMessage (msg);
		}
		else if (msg->GetMessageType () == MmWaveControlMessage::MIB)
		{
			NS_LOG_INFO ("received MIB");
			NS_ASSERT (m_cellId > 0);
			Ptr<MmWaveMibMessage> msg2 = DynamicCast<MmWaveMibMessage> (msg);
			m_ueCphySapUser->RecvMasterInformationBlock (m_cellId, msg2->GetMib ());
		}
		else if (msg->GetMessageType () == MmWaveControlMessage::SIB1)
		{
			NS_ASSERT (m_cellId > 0);
			Ptr<MmWaveSib1Message> msg2 = DynamicCast<MmWaveSib1Message> (msg);
			m_ueCphySapUser->RecvSystemInformationBlockType1 (m_cellId, msg2->GetSib1 ());
		}
		else if (msg->GetMessageType () == MmWaveControlMessage::RAR)
		{
			NS_LOG_INFO ("received RAR");
			NS_ASSERT (m_cellId > 0);

			Ptr<MmWaveRarMessage> rarMsg = DynamicCast<MmWaveRarMessage> (msg);

			for (std::list<MmWaveRarMessage::Rar>::const_iterator it = rarMsg->RarListBegin ();
					it != rarMsg->RarListEnd ();
					++it)
			{
				if (it->rapId == m_raPreambleId)
				{
					m_phySapUser->ReceiveControlMessage (rarMsg);
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
MmWaveUePhy::QueueUlTbAlloc (TbAllocInfo m)
{
  NS_LOG_FUNCTION (this);
  NS_LOG_DEBUG ("UL TB Info Elem queue size == " << m_ulTbAllocQueue.size ());
  m_ulTbAllocQueue.at (m_phyMacConfig->GetUlSchedDelay () - 1).push_back (m);
}

std::list<TbAllocInfo>
MmWaveUePhy::DequeueUlTbAlloc (void)
{
	NS_LOG_FUNCTION (this);

	if (m_ulTbAllocQueue.empty())
	{
		std::list<TbAllocInfo> emptylist;
		return (emptylist);
	}

	if (m_ulTbAllocQueue.at (0).size () > 0)
	{
		std::list<TbAllocInfo> ret = m_ulTbAllocQueue.at (0);
		m_ulTbAllocQueue.erase (m_ulTbAllocQueue.begin ());
		std::list<TbAllocInfo> l;
		m_ulTbAllocQueue.push_back (l);
		return (ret);
	}
	else
	{
		m_ulTbAllocQueue.erase (m_ulTbAllocQueue.begin ());
		std::list<TbAllocInfo> l;
		m_ulTbAllocQueue.push_back (l);
		std::list<TbAllocInfo> emptylist;
		return (emptylist);
	}
}

void
MmWaveUePhy::SubframeIndication (uint32_t nrFrames, uint32_t nrSlots)
{
	m_nrSlots = nrSlots;
	m_nrFrames = nrFrames;

	uint32_t slotInd = ((nrSlots-1)%m_phyMacConfig->GetSlotsPerSubframe ()) + 1;
	uint32_t sfInd = ((nrSlots-1)/m_phyMacConfig->GetSlotsPerSubframe ()) + 1;

	NS_LOG_DEBUG ("UE subframe " << sfInd << " slot " << slotInd);

	if (slotInd == 1)
	{
		// delay for control period reception/processing
		NS_LOG_DEBUG ("UE RXing CTRL period start " << Simulator::Now() << " end " << m_ctrlPeriod+NanoSeconds (1.0));
		Simulator::Schedule (m_ctrlPeriod + NanoSeconds (1.0), &MmWaveUePhy::ProcessSubframe, this);
	}
	else
	{
		ProcessSubframe ();
	}
}

void
MmWaveUePhy::ProcessSubframe ()
{
	uint32_t slotInd = ((m_nrSlots-1)%m_phyMacConfig->GetSlotsPerSubframe ()) + 1;
	uint32_t sfInd = ((m_nrSlots-1)/m_phyMacConfig->GetSlotsPerSubframe ()) + 1;

	ResetReception ();
	//m_receptionEnabled = true;
	if (slotInd == m_phyMacConfig->GetSlotsPerSubframe ())
	{
		m_sfAllocInfoUpdated = false;
	}

	if (slotInd == 1)
	{
		// process UL grants previously received
		std::list<TbAllocInfo> ulAllocInfoList = DequeueUlTbAlloc ();
		std::list<TbAllocInfo>::iterator it = ulAllocInfoList.begin ();
		if(it == ulAllocInfoList.end ())
		{
			m_ulGrant = false;	// no grant received, need to transmit UL control on PUCCH
		}
		else
		{
			m_ulGrant = true;
		}
		NS_LOG_DEBUG (this << " eNB Expected UL TBs " << ulAllocInfoList.size ());
		while(it != ulAllocInfoList.end ())
		{
			SlotAllocInfo& slotInfo = m_currSfAllocInfo.m_slotAllocInfo[it->m_tbInfo.m_slotInd];
			slotInfo.m_tbInfo.push_back (*it);
			if (m_currSfAllocInfo.m_tddPattern[it->m_tbInfo.m_slotInd] == SlotAllocInfo::NA)
			{
				m_currSfAllocInfo.m_tddPattern[it->m_tbInfo.m_slotInd] = SlotAllocInfo::UL;
				slotInfo.m_tddMode = SlotAllocInfo::UL;
			}
			else if (m_currSfAllocInfo.m_tddPattern[it->m_tbInfo.m_slotInd] == SlotAllocInfo::DL)
			{
				NS_LOG_ERROR ("Slot already assigned in DL");
			}
			it++;
		}
	}

	if (!m_ulGrant && slotInd == m_pucchSlotInd)
	{
		// no grant received, need to transmit UL control on PUCCH (currently this is an "ideal" channel)
		m_receptionEnabled = false;
		std::list<Ptr<MmWaveControlMessage> > ctrlMsg = GetControlMessages ();
		Ptr<PacketBurst> emptyPb = CreateObject<PacketBurst> ();
		std::vector<int> ulRbChunks;
		for (unsigned irb = 0; irb < m_phyMacConfig->GetNumRb (); irb++)
		{
			for(unsigned ichunk = 0; ichunk < m_phyMacConfig->GetNumChunkPerRb (); ichunk++)
			{
				ulRbChunks.push_back (irb * m_phyMacConfig->GetNumChunkPerRb () + ichunk);
				// NS_LOG_DEBUG(this << " RNTI " << m_rnti << " RBG " << i << " DL-DCI allocated PRB " << (i*GetRbgSize()) + k);
			}
		}
		SetSubChannelsForTransmission (ulRbChunks);
		// assume for now that the PUCCH is transmitted over one OFDM symbol across all RBs
		NS_LOG_DEBUG ("UE " << m_rnti << " TXing PUCCH (num ctrl msgs == " << ctrlMsg.size () << ")");
		NS_LOG_DEBUG ("UE TXing CTRL period start " << Simulator::Now() << " end " << Simulator::Now()+NanoSeconds(1000 * m_phyMacConfig->GetSymbolPeriod ()));
		MmWaveUePhy::SendDataChannels (emptyPb, ctrlMsg, NanoSeconds(1000 * m_phyMacConfig->GetSymbolPeriod ()), slotInd);
		m_prevSlotDir = SlotAllocInfo::UL;
	}
	else
	{
		// transmit or receive slot data
		SlotAllocInfo::TddMode slotDir = m_currSfAllocInfo.m_tddPattern[slotInd-1];
		SlotAllocInfo& slotInfo = m_currSfAllocInfo.m_slotAllocInfo[slotInd-1];
		if (slotDir == SlotAllocInfo::DL) // Downlink slot
		{
			m_receptionEnabled = true;
			if (slotInfo.m_slotType == SlotAllocInfo::DATA || slotInfo.m_slotType == SlotAllocInfo::CTRL_DATA)
			{
				std::vector <int> dlRbChunks;
				for (unsigned itb = 0; itb < slotInfo.m_tbInfo.size (); itb++)
				{
					TbAllocInfo& tbAlloc = slotInfo.m_tbInfo[itb];
					// translate the TB info to Spectrum framework
					for (unsigned irb = 0; irb < tbAlloc.m_rbMap.size (); irb++)
					{
						unsigned rbInd = tbAlloc.m_rbMap[irb];
						for(unsigned ichunk = 0; ichunk < m_phyMacConfig->GetNumChunkPerRb (); ichunk++)
						{
							dlRbChunks.push_back (rbInd * m_phyMacConfig->GetNumChunkPerRb () + ichunk);
							// NS_LOG_DEBUG(this << " RNTI " << m_rnti << " RBG " << i << " DL-DCI allocated PRB " << (i*GetRbgSize()) + k);
						}
					}
					SetSubChannelsForReception (dlRbChunks);

					// send TB info to LteSpectrumPhy
					NS_LOG_DEBUG (this << " UE " << m_rnti << " DL-DCI " << tbAlloc.m_rnti << " bitmap "  << tbAlloc.m_tbInfo.m_rbBitmap);
					//					m_downlinkSpectrumPhy->AddExpectedTb (dciInfoElem.m_rnti, tbInfo.m_ndi, tbInfo.m_tbSize, tbInfo.m_mcs, dlRbChunks, tbInfo.m_harqProcess, tbInfo.m_rv, true);
					m_downlinkSpectrumPhy->AddExpectedTb (tbAlloc.m_rnti, tbAlloc.m_tbInfo.m_tbSize, tbAlloc.m_tbInfo.m_mcs, dlRbChunks, true);
					m_reportDlTbSize (GetDevice ()->GetObject <MmWaveUeNetDevice> ()->GetImsi(), tbAlloc.m_tbInfo.m_tbSize);
				}
			}
		}
		else if (slotDir == SlotAllocInfo::UL)  // Uplink slot
		{
			m_receptionEnabled = false;
			if (slotInfo.m_slotType == SlotAllocInfo::DATA || slotInfo.m_slotType == SlotAllocInfo::CTRL_DATA)
			{
				std::vector <int> ulRbChunks;
				for (unsigned itb = 0; itb < slotInfo.m_tbInfo.size (); itb++)
				{
					TbAllocInfo& tbAlloc = slotInfo.m_tbInfo[itb];
					// translate the TB info to Spectrum framework
					for (unsigned irb = 0; irb < tbAlloc.m_rbMap.size (); irb++)
					{
						unsigned rbInd = tbAlloc.m_rbMap[irb];
						for(unsigned ichunk = 0; ichunk < m_phyMacConfig->GetNumChunkPerRb (); ichunk++)
						{
							ulRbChunks.push_back (rbInd * m_phyMacConfig->GetNumChunkPerRb () + ichunk);
							// NS_LOG_DEBUG(this << " RNTI " << m_rnti << " RBG " << i << " DL-DCI allocated PRB " << (i*GetRbgSize()) + k);
						}
					}
					SetSubChannelsForTransmission (ulRbChunks);

					std::list<Ptr<MmWaveControlMessage> > ctrlMsg = GetControlMessages ();

					Ptr<PacketBurst> pktBurst = GetPacketBurst (sfInd, slotInd);
					std::list< Ptr<Packet> > pkts = pktBurst->GetPackets ();
					if (!pkts.empty ())
					{
						MmWaveMacPduHeader macHeader;
						pkts.front ()->PeekHeader (macHeader);
						NS_ASSERT ((macHeader.GetSubframeNum() == sfInd) && (macHeader.GetSlotNum() == slotInd));
					}

					Time guardPeriod;
					Time dataPeriod;
					if (0 && slotDir == SlotAllocInfo::DL && m_prevSlotDir == SlotAllocInfo::UL)  // if curr slot == DL and prev slot == UL
					{
						guardPeriod = NanoSeconds (1000 * m_phyMacConfig->GetGuardPeriod ());
						dataPeriod = m_dataPeriod - guardPeriod;
						Simulator::Schedule (guardPeriod, &MmWaveUePhy::SendDataChannels, this, pktBurst, ctrlMsg, dataPeriod, slotInd);
					}
					else
					{
						NS_LOG_DEBUG ("UE TXing DATA period start " << Simulator::Now() << " end " << Simulator::Now()+NanoSeconds(1000 * m_phyMacConfig->GetTti ()));
						MmWaveUePhy::SendDataChannels (pktBurst, ctrlMsg, NanoSeconds(1000 * m_phyMacConfig->GetTti ()), slotInd);
					}

					// send TB info to LteSpectrumPhy
					NS_LOG_DEBUG (this << " UE " << m_rnti << " UL-DCI " << tbAlloc.m_rnti << " rbStart "  << (unsigned)tbAlloc.m_tbInfo.m_rbStart << " rbLen "  << (unsigned)tbAlloc.m_tbInfo.m_rbLen);
					m_reportUlTbSize (GetDevice ()->GetObject <MmWaveUeNetDevice> ()->GetImsi(), tbAlloc.m_tbInfo.m_tbSize);
				}
			}
		}
		m_prevSlotDir = slotDir;
	}

	m_phySapUser->SubframeIndication (m_nrFrames, sfInd, slotInd); 	/*triger mac*/

	if (m_nrSlots == (m_phyMacConfig->GetSlotsPerSubframe () * m_phyMacConfig->GetSubframesPerFrame ()))
	{
		m_nrSlots = 1;
		m_nrFrames++;
	}
	else
	{
		m_nrSlots++;
	}

	if (slotInd == 1)
	{
		Simulator::Schedule (Seconds(GetTti()) - (m_ctrlPeriod + NanoSeconds (1.0)), &MmWaveUePhy::SubframeIndication, this, m_nrFrames, m_nrSlots);
	}
	else
	{
		Simulator::Schedule (Seconds(GetTti()), &MmWaveUePhy::SubframeIndication, this, m_nrFrames, m_nrSlots);
	}
}

uint32_t
MmWaveUePhy::GetSubframeNumber (void)
{
	return m_nrSlots;
}

void
MmWaveUePhy::PhyDataPacketReceived (Ptr<Packet> p)
{
	m_phySapUser->ReceivePhyPdu (p);
}

void
MmWaveUePhy::SendDataChannels (Ptr<PacketBurst> pb, std::list<Ptr<MmWaveControlMessage> > ctrlMsg, Time duration, uint8_t slotInd)
{
	m_downlinkSpectrumPhy->StartTxDataFrames (pb, ctrlMsg, duration, slotInd);
}

void
MmWaveUePhy::SendCtrlChannels (std::list<Ptr<MmWaveControlMessage> > ctrlMsg, Time prd)
{
	m_downlinkSpectrumPhy->StartTxDlControlFrames(ctrlMsg,prd);
}


uint32_t
MmWaveUePhy::GetAbsoluteSubframeNo ()
{
	return ((m_nrFrames-1)*8 + m_nrSlots);
}

Ptr<MmWaveDlCqiMessage>
MmWaveUePhy::CreateDlCqiFeedbackMessage (const SpectrumValue& sinr)
{
	if (!m_amc)
	{
		m_amc = CreateObject <mmWaveAmc> (m_phyMacConfig);
	}
	NS_LOG_FUNCTION (this);
	SpectrumValue newSinr = sinr;
	// CREATE DlCqiLteControlMessage
	Ptr<MmWaveDlCqiMessage> msg = Create<MmWaveDlCqiMessage> ();
	DlCqiInfo dlcqi;

	dlcqi.m_rnti = m_rnti;

	std::vector<int> cqi;

	uint8_t dlBandwidth = m_phyMacConfig->GetNumChunkPerRb ();

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
//		NS_LOG_DEBUG (this << " subch " << i << " cqi " <<  cqi.at (i));
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
	msg->SetDlCqi (dlcqi);
	return msg;
}

void
MmWaveUePhy::GenerateDlCqiReport (const SpectrumValue& sinr)
{
	if(m_ulConfigured && (m_rnti > 0))
	{
		if (Simulator::Now () > m_wbCqiLast + m_wbCqiPeriod)
		{
			SpectrumValue newSinr = sinr;
			Ptr<MmWaveDlCqiMessage> msg = CreateDlCqiFeedbackMessage (newSinr);

			if (msg)
			{
				DoSendControlMessage (msg);
			}
			Ptr<MmWaveUeNetDevice> UeRx = DynamicCast<MmWaveUeNetDevice> (GetDevice());
			m_reportCurrentCellRsrpSinrTrace (UeRx->GetImsi(), newSinr, newSinr);
		}
	}
}

bool
MmWaveUePhy::IsReceptionEnabled ()
{
	return m_receptionEnabled;
}

void
MmWaveUePhy::ResetReception()
{
	m_receptionEnabled = false;
}

uint16_t
MmWaveUePhy::GetRnti ()
{
	return m_rnti;
}


void
MmWaveUePhy::DoReset ()
{
	NS_LOG_FUNCTION (this);
}

void
MmWaveUePhy::DoStartCellSearch (uint16_t dlEarfcn)
{
	NS_LOG_FUNCTION (this << dlEarfcn);
}

void
MmWaveUePhy::DoSynchronizeWithEnb (uint16_t cellId, uint16_t dlEarfcn)
{
	NS_LOG_FUNCTION (this << cellId << dlEarfcn);
	DoSynchronizeWithEnb (cellId);
}

void
MmWaveUePhy::DoSynchronizeWithEnb (uint16_t cellId)
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
MmWaveUePhy::DoSetDlBandwidth (uint8_t dlBandwidth)
{
	NS_LOG_FUNCTION (this << (uint32_t) dlBandwidth);
}


void
MmWaveUePhy::DoConfigureUplink (uint16_t ulEarfcn, uint8_t ulBandwidth)
{
	NS_LOG_FUNCTION (this << ulEarfcn << ulBandwidth);
	m_ulConfigured = true;
}

void
MmWaveUePhy::DoConfigureReferenceSignalPower (int8_t referenceSignalPower)
{
	NS_LOG_FUNCTION (this << referenceSignalPower);
}

void
MmWaveUePhy::DoSetRnti (uint16_t rnti)
{
	NS_LOG_FUNCTION (this << rnti);
	m_rnti = rnti;
}

void
MmWaveUePhy::DoSetTransmissionMode (uint8_t txMode)
{
	NS_LOG_FUNCTION (this << (uint16_t)txMode);
}

void
MmWaveUePhy::DoSetSrsConfigurationIndex (uint16_t srcCi)
{
	NS_LOG_FUNCTION (this << srcCi);
}

}


