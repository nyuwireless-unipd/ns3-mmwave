/*
 * mmwave-enb-phy.cc
 *
 *  Created on: Nov 5, 2014
 *      Author: sourjya
 */

#include <ns3/object-factory.h>
#include <ns3/log.h>
#include <cfloat>
#include <cmath>
#include <ns3/simulator.h>
#include <ns3/attribute-accessor-helper.h>
#include <ns3/double.h>

#include "mmwave-enb-phy.h"
#include "mmwave-ue-phy.h"
#include "mmwave-net-device.h"
#include "mmwave-ue-net-device.h"
#include "mmwave-spectrum-value-helper.h"
#include "mmwave-radio-bearer-tag.h"

#include <ns3/node-list.h>
#include <ns3/node.h>
#include <ns3/pointer.h>

namespace ns3{

NS_LOG_COMPONENT_DEFINE ("MmWaveEnbPhy");

NS_OBJECT_ENSURE_REGISTERED (MmWaveEnbPhy);

MmWaveEnbPhy::MmWaveEnbPhy ()
{
	NS_LOG_FUNCTION (this);
	NS_FATAL_ERROR ("This constructor should not be called");
}

MmWaveEnbPhy::MmWaveEnbPhy (Ptr<MmWaveSpectrumPhy> dlPhy, Ptr<MmWaveSpectrumPhy> ulPhy)
    :MmWavePhy (dlPhy, ulPhy),
	m_prevSlot (0),
  m_prevSlotDir (SlotAllocInfo::NA),
  m_currSymStart (0)
{
	m_enbCphySapProvider = new MemberLteEnbCphySapProvider<MmWaveEnbPhy> (this);
	Simulator::ScheduleNow (&MmWaveEnbPhy::StartSubFrame, this);
}

MmWaveEnbPhy::~MmWaveEnbPhy ()
{

}

TypeId
MmWaveEnbPhy::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::MmWaveEnbPhy")
    .SetParent<MmWavePhy> ()
    .AddConstructor<MmWaveEnbPhy> ()
	.AddAttribute ("TxPower",
	               "Transmission power in dBm",
	               DoubleValue (30.0),
	               MakeDoubleAccessor (&MmWaveEnbPhy::SetTxPower,
	                                   &MmWaveEnbPhy::GetTxPower),
	               MakeDoubleChecker<double> ())
	.AddAttribute ("NoiseFigure",
	               "Loss (dB) in the Signal-to-Noise-Ratio due to non-idealities in the receiver."
	               " According to Wikipedia (http://en.wikipedia.org/wiki/Noise_figure), this is "
	               "\"the difference in decibels (dB) between"
	               " the noise output of the actual receiver to the noise output of an "
	               " ideal receiver with the same overall gain and bandwidth when the receivers "
	               " are connected to sources at the standard noise temperature T0.\" "
	               "In this model, we consider T0 = 290K.",
	               DoubleValue (5.0),
	               MakeDoubleAccessor (&MmWavePhy::SetNoiseFigure,
	                                   &MmWavePhy::GetNoiseFigure),
	               MakeDoubleChecker<double> ())
	 .AddAttribute ("DlSpectrumPhy",
				    "The downlink MmWaveSpectrumPhy associated to this MmWavePhy",
				    TypeId::ATTR_GET,
				    PointerValue (),
				    MakePointerAccessor (&MmWaveEnbPhy::GetDlSpectrumPhy),
				    MakePointerChecker <MmWaveSpectrumPhy> ())
	 .AddAttribute ("UlSpectrumPhy",
				    "The uplink MmWaveSpectrumPhy associated to this MmWavePhy",
				    TypeId::ATTR_GET,
				    PointerValue (),
				    MakePointerAccessor (&MmWaveEnbPhy::GetUlSpectrumPhy),
				    MakePointerChecker <MmWaveSpectrumPhy> ())
	 .AddTraceSource ("UlSinrTrace",
					  "UL SINR statistics.",
					  MakeTraceSourceAccessor (&MmWaveEnbPhy::m_ulSinrTrace))

	;
  return tid;

}

void
MmWaveEnbPhy::DoInitialize (void)
{
	NS_LOG_FUNCTION (this);
	Ptr<SpectrumValue> noisePsd = MmWaveSpectrumValueHelper::CreateNoisePowerSpectralDensity (m_phyMacConfig, m_noiseFigure);
	m_downlinkSpectrumPhy->SetNoisePowerSpectralDensity (noisePsd);
  //m_numRbg = m_phyMacConfig->GetNumRb() / m_phyMacConfig->GetNumRbPerRbg();
	//m_ctrlPeriod = NanoSeconds (1000 * m_phyMacConfig->GetCtrlSymbols() * m_phyMacConfig->GetSymbolPeriod());
	//m_dataPeriod = NanoSeconds (1000 * (m_phyMacConfig->GetSymbPerSlot() - m_phyMacConfig->GetCtrlSymbols()) * m_phyMacConfig->GetSymbolPeriod());

	for (unsigned i = 0; i < m_phyMacConfig->GetL1L2CtrlLatency(); i++)
	{ // push elements onto queue for initial scheduling delay
		m_controlMessageQueue.push_back (std::list<Ptr<MmWaveControlMessage> > ());
	}

	for (unsigned i = 0; i < m_phyMacConfig->GetSubframesPerFrame(); i++)
	{
		m_sfAllocInfo.push_back(SfAllocInfo(SfnSf (0, i, 0)));
		SlotAllocInfo dlCtrlSlot;
		dlCtrlSlot.m_numCtrlSym = 1;
		dlCtrlSlot.m_tddMode = SlotAllocInfo::DL;
		dlCtrlSlot.m_dci.m_numSym = 1;
		dlCtrlSlot.m_dci.m_symStart = 0;
		SlotAllocInfo ulCtrlSlot;
		ulCtrlSlot.m_numCtrlSym = 1;
		ulCtrlSlot.m_tddMode = SlotAllocInfo::UL;
		ulCtrlSlot.m_slotIdx = 0xFF;
		ulCtrlSlot.m_dci.m_numSym = 1;
		ulCtrlSlot.m_dci.m_symStart = m_phyMacConfig->GetSymbolsPerSubframe()-1;
		m_sfAllocInfo[i].m_dlSlotAllocInfo.push_back (dlCtrlSlot);
		m_sfAllocInfo[i].m_ulSlotAllocInfo.push_back (ulCtrlSlot);
	}
	m_sfAllocInfoUpdated = true;

	for (unsigned i = 0; i < m_phyMacConfig->GetTotalNumChunk(); i++)
	{
		m_channelChunks.push_back(i);
	}
	SetSubChannels(m_channelChunks);

	m_sfPeriod = NanoSeconds (1000.0 * m_phyMacConfig->GetSubframePeriod ());

	MmWavePhy::DoInitialize ();
}
void
MmWaveEnbPhy::DoDispose (void)
{

}

void
MmWaveEnbPhy::SetmmWaveEnbCphySapUser (LteEnbCphySapUser* s)
{
  NS_LOG_FUNCTION (this);
  m_enbCphySapUser = s;
}

LteEnbCphySapProvider*
MmWaveEnbPhy::GetmmWaveEnbCphySapProvider ()
{
  NS_LOG_FUNCTION (this);
  return m_enbCphySapProvider;
}

void
MmWaveEnbPhy::SetTxPower (double pow)
{
	m_txPower = pow;
}
double
MmWaveEnbPhy::GetTxPower () const
{
	return m_txPower;
}

void
MmWaveEnbPhy::SetNoiseFigure (double nf)
{
	m_noiseFigure = nf;
}
double
MmWaveEnbPhy::GetNoiseFigure () const
{
	return m_noiseFigure;
}

void
MmWaveEnbPhy::CalcChannelQualityForUe (std::vector <double> sinr, Ptr<MmWaveSpectrumPhy> ue)
{

}

Ptr<SpectrumValue>
MmWaveEnbPhy::CreateTxPowerSpectralDensity ()
{
	Ptr<SpectrumValue> psd =
			MmWaveSpectrumValueHelper::CreateTxPowerSpectralDensity (m_phyMacConfig, m_txPower, m_listOfSubchannels );
	return psd;
}

void
MmWaveEnbPhy::DoSetSubChannels ()
{

}

void
MmWaveEnbPhy::SetSubChannels (std::vector<int> mask )
{
	m_listOfSubchannels = mask;
	Ptr<SpectrumValue> txPsd = CreateTxPowerSpectralDensity ();
	NS_ASSERT (txPsd);
	m_downlinkSpectrumPhy->SetTxPowerSpectralDensity (txPsd);
}

Ptr<MmWaveSpectrumPhy>
MmWaveEnbPhy::GetDlSpectrumPhy () const
{
  return m_downlinkSpectrumPhy;
}

Ptr<MmWaveSpectrumPhy>
MmWaveEnbPhy::GetUlSpectrumPhy () const
{
  return m_uplinkSpectrumPhy;
}

void
MmWaveEnbPhy::StartSubFrame (void)
{
	NS_LOG_FUNCTION (this);

<<<<<<< HEAD
	m_lastSfStart = Simulator::Now();
=======
	++m_nrFrames;
	if (m_nrFrames == 1024)
	{
		m_nrFrames = 0;
	}

	m_nrSlots = 0;
	/*sending MIB at the beginning of each frame*/
	LteRrcSap::MasterInformationBlock mib;
	mib.dlBandwidth = (uint8_t)4;
	mib.systemFrameNumber = 1;
>>>>>>> b36c54152804fd16ccc9464c4123d6ceeba3fb48

	m_currSfAllocInfo = m_sfAllocInfo[m_sfNum];
	m_currSfNumSlots = m_currSfAllocInfo.m_dlSlotAllocInfo.size () + m_currSfAllocInfo.m_ulSlotAllocInfo.size ();

	NS_ASSERT ((m_currSfAllocInfo.m_sfnSf.m_frameNum == m_frameNum) &&
	           (m_currSfAllocInfo.m_sfnSf.m_sfNum == m_sfNum));

	// reset SfAllocInfo for next frame
	if (!m_sfAllocInfoUpdated)
	{
		m_sfAllocInfo[m_sfNum] = SfAllocInfo (SfnSf (m_frameNum+1, m_sfNum, 0));
		SlotAllocInfo dlCtrlSlot;
		dlCtrlSlot.m_numCtrlSym = 1;
		dlCtrlSlot.m_tddMode = SlotAllocInfo::DL;
		dlCtrlSlot.m_dci.m_numSym = 1;
		dlCtrlSlot.m_dci.m_symStart = 0;
		SlotAllocInfo ulCtrlSlot;
		ulCtrlSlot.m_numCtrlSym = 1;
		ulCtrlSlot.m_tddMode = SlotAllocInfo::UL;
		ulCtrlSlot.m_slotIdx = 0xFF;
		ulCtrlSlot.m_dci.m_numSym = 1;
		ulCtrlSlot.m_dci.m_symStart = m_phyMacConfig->GetSymbolsPerSubframe()-2;
		m_sfAllocInfo[m_sfNum].m_dlSlotAllocInfo.push_back (dlCtrlSlot);
		m_sfAllocInfo[m_sfNum].m_ulSlotAllocInfo.push_back (ulCtrlSlot);
	}

	m_sfAllocInfoUpdated = false;

	if (m_sfNum == 0) 		// send MIB at the beginning of each frame
	{
		LteRrcSap::MasterInformationBlock mib;
		mib.dlBandwidth = (uint8_t)4;
		mib.systemFrameNumber = 1;
		Ptr<MmWaveMibMessage> mibMsg = Create<MmWaveMibMessage> ();
		mibMsg->SetMib(mib);
		if (m_controlMessageQueue.empty())
		{
			std::list<Ptr<MmWaveControlMessage> > l;
			m_controlMessageQueue.push_back (l);
		}
		m_controlMessageQueue.at (0).push_back (mibMsg);
	}
	else if (m_sfNum == 5)  // send SIB at beginning of half-frame
	{
		Ptr<MmWaveSib1Message> msg = Create<MmWaveSib1Message> ();
		msg->SetSib1 (m_sib1);
		m_controlMessageQueue.at (0).push_back (msg);
	}

	//Simulator::Schedule (m_sfPeriod, &MmWaveEnbPhy::EndSubFrame, this);

	StartSlot();
}

/*
void
MmWaveEnbPhy::QueueUlTbAlloc (TbAllocInfo m)
{
  NS_LOG_FUNCTION (this);
  m_ulTbAllocQueue.at (m_phyMacConfig->GetUlSchedDelay () - 1).push_back (m);
}

std::list<TbAllocInfo>
MmWaveEnbPhy::DequeueUlTbAlloc (void)
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
*/


void
MmWaveEnbPhy::StartSlot (void)
{
	NS_LOG_FUNCTION (this);

	SlotAllocInfo currSlot;

	uint8_t slotInd = 0;
	if (m_slotNum >= m_currSfAllocInfo.m_dlSlotAllocInfo.size ())
	{
		if (m_currSfAllocInfo.m_ulSlotAllocInfo.size () > 0)
		{
			slotInd = m_slotNum - m_currSfAllocInfo.m_dlSlotAllocInfo.size ();
			currSlot = m_currSfAllocInfo.m_ulSlotAllocInfo[slotInd];
			m_currSymStart = currSlot.m_dci.m_symStart;
		}
	}
	else
	{
		if (m_currSfAllocInfo.m_ulSlotAllocInfo.size () > 0)
		{
			slotInd = m_slotNum;
			currSlot = m_currSfAllocInfo.m_dlSlotAllocInfo[slotInd];
			m_currSymStart = currSlot.m_dci.m_symStart;
		}
	}

	SfnSf sfn = SfnSf (m_frameNum, m_sfNum, m_slotNum);
  m_harqPhyModule->SubframeIndication (sfn);  // trigger HARQ module

  std::list <Ptr<MmWaveControlMessage > > dciMsgList;
//  std::map<uint16_t, std::list<Ptr<MmWaveTdmaDciMessage> > > dciMsgMap;		// DCI messages for each RNTI
//	std::map<uint16_t, std::list<Ptr<MmWaveTdmaDciMessage> > >::iterator itDci;
//	std::map<uint16_t, std::list<Ptr<MmWaveControlMessage> > > ctrlMsgMap;  // other control messages
//	std::map<uint16_t, std::list<Ptr<MmWaveControlMessage> > >::iterator itCtrl;

	// get control messages to be transmitted in UE-specific slots
	std::list <Ptr<MmWaveControlMessage > > ctrlMsgs = GetControlMessages ();
	std::list <Ptr<MmWaveControlMessage > >::iterator it = ctrlMsgs.begin ();
//	while (it != ctrlMsgs.end ())
//	{
//		uint16_t rnti = 0;
//		if ((*it)->GetMessageType() == MmWaveControlMessage::RAR)		// RAR only DL message expected here
//		{
//			Ptr<MmWaveRarMessage> rarMsg = DynamicCast <MmWaveRarMessage> (*it);
//			rnti = rarMsg->GetRaRnti ();
//		}
//		if (rnti > 0)
//		{
//			itCtrl = ctrlMsgMap.find (rnti);
//			if (itCtrl == ctrlMsgMap.end ())
//			{
//				itCtrl = ctrlMsgMap.insert (std::pair<uint16_t, std::vector<Ptr<MmWaveTdmaDciMessage> > >
//																			(rnti,  std::vector<Ptr<MmWaveTdmaDciMessage> >)).first;
//			}
//			it++;
//		}
//	}

	Time guardPeriod;
	Time slotPeriod;

	if(m_slotNum == 0) // DL control slot
	{
		// find all DL/UL DCI elements and create DCI messages to be transmitted in DL control period
		for (unsigned islot = 0; islot < m_currSfAllocInfo.m_dlSlotAllocInfo.size (); islot++)
		{
			DciInfoElementTdma &dciElem = m_currSfAllocInfo.m_dlSlotAllocInfo[islot].m_dci;
			if (dciElem.m_tbSize > 0)
			{
<<<<<<< HEAD
				Ptr<MmWaveTdmaDciMessage> dciMsg = Create<MmWaveTdmaDciMessage> ();
				dciMsg->SetDciInfoElement (dciElem);
				dciMsg->SetSfnSf (sfn);
				dciMsgList.push_back (dciMsg);
				ctrlMsgs.push_back (dciMsg);
			}
		}
		unsigned ulSfNum = (m_sfNum + m_phyMacConfig->GetUlSchedDelay ()) % m_phyMacConfig->GetSubframesPerFrame ();
		for (unsigned islot = 0; islot < m_sfAllocInfo[ulSfNum].m_ulSlotAllocInfo.size (); islot++)
		{
			DciInfoElementTdma &dciElem = m_sfAllocInfo[ulSfNum].m_ulSlotAllocInfo[islot].m_dci;
			if (dciElem.m_tbSize > 0)
			{
				Ptr<MmWaveTdmaDciMessage> dciMsg = Create<MmWaveTdmaDciMessage> ();
				dciMsg->SetDciInfoElement (dciElem);
				dciMsg->SetSfnSf (sfn);
				//dciMsgList.push_back (dciMsg);
				ctrlMsgs.push_back (dciMsg);
=======
				// process DCI message
				Ptr<MmWaveDciMessage> dci = DynamicCast<MmWaveDciMessage> (msg);
				unsigned dciSfn = dci->GetSfnSf ();
				if(dciSfn != sfn)
				{
					unsigned dciFrame = ((dciSfn >> 16) & 0x3FF);
					unsigned dciSf = ((dciSfn >> 8) & 0xFF);
					NS_FATAL_ERROR ("DCI intended for different subframe (dci= "<<dciFrame<<" "<<dciSf<<", actual= "<<m_nrFrames<<" "<<sfInd);
				}

				DciInfoElement dciInfo = dci->GetDciInfoElement ();

		  	std::set <uint16_t>::iterator ueIt = m_ueAttachedRnti.find (dciInfo.m_rnti);
				if (ueIt == m_ueAttachedRnti.end ())
				{
					NS_LOG_ERROR ("UE not attached");
				}
				else
				{
					for (std::vector<TbInfoElement>::const_iterator tbIt = dciInfo.m_tbInfoElements.begin(); tbIt != dciInfo.m_tbInfoElements.end(); tbIt++)
					{
						// loop through resource allocation info elements (can be multiple per DCI corresponding to TBs)
						SlotAllocInfo* slotInfo; // get reference to slot information
						SlotAllocInfo::TddMode slotMode;
						if ( ((dciInfo.m_tddBitmap >> tbIt->m_slotInd) & 0x1) == 0 && (dciInfo.m_tbInfoElements.size () > 0))
						{
							slotMode = SlotAllocInfo::DL;
						}
						else
						{
							slotMode = SlotAllocInfo::UL;
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
								NS_LOG_ERROR ("Slot already assigned in UL");
							}

							TbAllocInfo tbAllocInfo;
							tbAllocInfo.m_rnti = dciInfo.m_rnti;
							tbAllocInfo.m_tbInfo = *tbIt;
							for (unsigned irbg = 0; irbg < m_numRbg; irbg++) // assumes res alloc type 0
							{
								if((tbIt->m_rbBitmap >> irbg) & 0x1)
								{
									tbAllocInfo.m_rbMap.push_back (irbg);
								}
							}
							slotInfo->m_tbInfo.push_back (tbAllocInfo);
							std::map<uint16_t, std::vector<unsigned> >::iterator ueRbIt = slotInfo->m_ueRbMap.find (dciInfo.m_rnti);
							if (ueRbIt == slotInfo->m_ueRbMap.end ())
							{
								slotInfo->m_ueRbMap.insert (std::pair<uint16_t, std::vector<unsigned> > (dciInfo.m_rnti, tbAllocInfo.m_rbMap));
							}
							else
							{
								ueRbIt->second.insert(ueRbIt->second.end (), tbAllocInfo.m_rbMap.begin (), tbAllocInfo.m_rbMap.end ());
							}
						}
						else if (slotMode == SlotAllocInfo::UL)
						{
							// Uplink TbInfoElement applies to n+3th subframe
							TbAllocInfo tbAllocInfo;
							tbAllocInfo.m_rnti = dciInfo.m_rnti;
							tbAllocInfo.m_tbInfo = *tbIt;
							for (unsigned irb = tbIt->m_rbStart; irb < (tbIt->m_rbStart + tbIt->m_rbLen); irb++) // assumes res alloc type 0
							{
								tbAllocInfo.m_rbMap.push_back (irb);
							}
							QueueUlTbAlloc (tbAllocInfo);
						}
					}
				}
>>>>>>> b36c54152804fd16ccc9464c4123d6ceeba3fb48
			}
		}

		// TX control period
		slotPeriod = NanoSeconds (1000.0*m_phyMacConfig->GetSymbolPeriod ()*m_phyMacConfig->GetDlCtrlSymbols());
		NS_LOG_DEBUG ("ENB TXing DL CTRL frame " << m_frameNum << " subframe " << (unsigned)m_sfNum << " symbols "
		              << (unsigned)currSlot.m_dci.m_symStart << "-" << (unsigned)(currSlot.m_dci.m_symStart+currSlot.m_dci.m_numSym-1)
		              << "\t start " << Simulator::Now() << " end " << Simulator::Now() + slotPeriod-NanoSeconds(1.0));
		SendCtrlChannels(ctrlMsgs, slotPeriod-NanoSeconds(1.0)); // -1 ns ensures control ends before data period
	}
	else if (m_slotNum == m_currSfNumSlots-1) // UL control slot
	{
		slotPeriod = NanoSeconds (1000.0*m_phyMacConfig->GetSymbolPeriod ()*m_phyMacConfig->GetUlCtrlSymbols());
		NS_LOG_DEBUG ("ENB RXing UL CTRL frame " << m_frameNum << " subframe " << (unsigned)m_sfNum << " symbols "
		              << (unsigned)currSlot.m_dci.m_symStart << "-" << (unsigned)(currSlot.m_dci.m_symStart+currSlot.m_dci.m_numSym-1)
							    << "\t start " << Simulator::Now() << " end " << Simulator::Now() + slotPeriod);
	}
	else if (currSlot.m_tddMode == SlotAllocInfo::DL) 	  // transmit DL slot
	{
		slotPeriod = NanoSeconds (1000.0 * m_phyMacConfig->GetSymbolPeriod() * currSlot.m_dci.m_numSym);
		NS_ASSERT (currSlot.m_tddMode == SlotAllocInfo::DL);
		//NS_LOG_DEBUG ("Slot " << m_slotNum << " scheduled for Downlink");
		//			if (m_prevSlotDir == SlotAllocInfo::UL)  // if curr slot == DL and prev slot == UL
		//			{
		//				guardPeriod = NanoSeconds (1000.0 * m_phyMacConfig->GetGuardPeriod ());
		//			}
		Ptr<PacketBurst> pktBurst = GetPacketBurst (SfnSf (m_frameNum, m_sfNum, currSlot.m_dci.m_symStart));
		if(pktBurst && pktBurst->GetNPackets() > 0)
		{
			std::list< Ptr<Packet> > pkts = pktBurst->GetPackets ();
			if (!pkts.empty ())
			{
				MmWaveMacPduTag macTag;
				pkts.front ()->PeekPacketTag (macTag);
				NS_ASSERT ((macTag.GetSfn().m_sfNum == m_sfNum) && (macTag.GetSfn().m_slotNum == currSlot.m_dci.m_symStart));
			}
		}
		NS_LOG_DEBUG ("ENB TXing DL DATA frame " << m_frameNum << " subframe " << (unsigned)m_sfNum << " symbols "
		              << (unsigned)currSlot.m_dci.m_symStart << "-" << (unsigned)(currSlot.m_dci.m_symStart+currSlot.m_dci.m_numSym-1)
		              << "\t start " << Simulator::Now()+NanoSeconds(1.0) << " end " << Simulator::Now() + slotPeriod-NanoSeconds (2.0));
		Simulator::Schedule (NanoSeconds(1.0), &MmWaveEnbPhy::SendDataChannels, this, pktBurst, slotPeriod-NanoSeconds (2.0), currSlot);
	}
	else if (currSlot.m_tddMode == SlotAllocInfo::UL)  // receive UL slot
	{
		slotPeriod = NanoSeconds (1000.0 * m_phyMacConfig->GetSymbolPeriod() * currSlot.m_dci.m_numSym);
		//NS_LOG_DEBUG ("Slot " << (uint8_t)m_slotNum << " scheduled for Uplink");
		m_downlinkSpectrumPhy->AddExpectedTb(currSlot.m_dci.m_rnti, currSlot.m_dci.m_ndi, currSlot.m_dci.m_tbSize,
		                                     currSlot.m_dci.m_mcs, m_channelChunks, currSlot.m_dci.m_harqProcess, currSlot.m_dci.m_rv, false);
		NS_LOG_DEBUG ("ENB RXing UL DATA frame " << m_frameNum << " subframe " << (unsigned)m_sfNum << " symbols "
		              << (unsigned)currSlot.m_dci.m_symStart << "-" << (unsigned)(currSlot.m_dci.m_symStart+currSlot.m_dci.m_numSym-1)
		              << "\t start " << Simulator::Now() << " end " << Simulator::Now() + slotPeriod );
	}

<<<<<<< HEAD
  m_prevSlotDir = currSlot.m_tddMode;
=======
	// transmit or receive slot data
  SlotAllocInfo::TddMode slotDir = m_currSfAllocInfo.m_tddPattern[slotInd-1];
  SlotAllocInfo& slotInfo = m_currSfAllocInfo.m_slotAllocInfo[slotInd-1];
  // if no scheduling decision available, slotDir will be 'NA', so we assume a default schedule with odd slots being DL and even UL
  if (slotDir == SlotAllocInfo::DL || slotInd == 1) // Downlink slot
  {
  	if (slotInfo.m_slotType == SlotAllocInfo::CTRL_DATA || slotInfo.m_slotType == SlotAllocInfo::DATA)
  	{
  		if(slotInfo.m_slotType == SlotAllocInfo::CTRL_DATA)
  		{
  			NS_LOG_DEBUG ("Slot " << slotInd << " scheduled for Downlink Ctrl+Data");
  		}
  		else
  		{
  			NS_LOG_DEBUG ("Slot " << slotInd << " scheduled for Downlink Data");
  		}

  		Time ctrlPeriod;
  		Time guardPeriod;
  		Time dataPeriod;

  		if(slotInfo.m_slotType == SlotAllocInfo::CTRL_DATA)
  		{
  			// the -1 ns ensures control period ends before data period and events do not overlap
  			ctrlPeriod = NanoSeconds (1000 * slotInfo.m_numCtrlSym * m_phyMacConfig->GetSymbolPeriod ());
  			dataPeriod = NanoSeconds (1000 * ( m_phyMacConfig->GetSymbPerSlot() - slotInfo.m_numCtrlSym) * \
  			                           m_phyMacConfig->GetSymbolPeriod ());
  			NS_LOG_DEBUG ("ENB TXing CTRL period frame " << m_nrFrames << " subframe " << sfInd << " slot " << slotInd << \
  			              " start " << Simulator::Now() << " end " << Simulator::Now() + ctrlPeriod-NanoSeconds(1.0));
    		SendCtrlChannels(ctrlMsg, ctrlPeriod-NanoSeconds(1.0));
  		}
  		else
  		{
    		if (slotDir == SlotAllocInfo::DL && m_prevSlotDir == SlotAllocInfo::UL)  // if curr slot == DL and prev slot == UL
    		{
//    			guardPeriod = NanoSeconds (1000 * m_phyMacConfig->GetGuardPeriod ());
    			guardPeriod = Seconds (0.0);
    			dataPeriod = NanoSeconds (1000 * m_phyMacConfig->GetSymbPerSlot() * m_phyMacConfig->GetSymbolPeriod ()) - \
    					guardPeriod;
    		}
    		else
    		{
    			guardPeriod = Seconds (0.0);
    			dataPeriod = NanoSeconds (1000 * m_phyMacConfig->GetSymbPerSlot() * m_phyMacConfig->GetSymbolPeriod ());
    		}
  		}

  		for (unsigned itb = 0; itb < slotInfo.m_tbInfo.size (); itb++)	// for loop is for debugging only
  		{
  			TbAllocInfo tbAllocInfo = slotInfo.m_tbInfo[itb];
  			TbInfoElement tbInfoElem = tbAllocInfo.m_tbInfo;
  			NS_LOG_DEBUG ("UE " << tbAllocInfo.m_rnti << " TBS " << (int)tbInfoElem.m_tbSize << " MCS " << (int)tbInfoElem.m_mcs << " RBs " << tbAllocInfo.m_rbMap.front () << "-" <<  tbAllocInfo.m_rbMap.back ());
  		}

  		Ptr<PacketBurst> pktBurst = GetPacketBurst (sfInd, slotInd);
  		if(pktBurst)
  		{
  			std::list< Ptr<Packet> > pkts = pktBurst->GetPackets ();
  			if (!pkts.empty ())
  			{
  				MmWaveMacPduTag macTag;
  				pkts.front ()->PeekPacketTag (macTag);
  				NS_ASSERT ((macTag.GetSubframeNum() == sfInd) && (macTag.GetSlotNum() == slotInd));
  			}
  		}
			NS_LOG_DEBUG ("ENB TXing DATA period frame " << m_nrFrames << " subframe " << sfInd << " slot " << slotInd << \
			              " start " << Simulator::Now()+ctrlPeriod+NanoSeconds(1.0) << " end " << Simulator::Now() + ctrlPeriod + dataPeriod-NanoSeconds (2.0));
  		Simulator::Schedule (ctrlPeriod, &MmWaveEnbPhy::SendDataChannels, this, pktBurst, dataPeriod-NanoSeconds (2.0), slotInfo);

  	}
  }
  else if (slotDir == SlotAllocInfo::UL || slotInd == 2)  // Uplink slot
  {
		NS_LOG_DEBUG ("Slot scheduled " << slotInd << "  for Uplink Data");
  	for (unsigned itb = 0; itb < slotInfo.m_tbInfo.size (); itb++)
  	{
  		TbAllocInfo tbAllocInfo = slotInfo.m_tbInfo[itb];
  		TbInfoElement tbInfoElem = tbAllocInfo.m_tbInfo;
  		NS_LOG_DEBUG ("UE " << tbAllocInfo.m_rnti << " TBS " << tbInfoElem.m_tbSize << " MCS " << (int)tbInfoElem.m_mcs << \
  		              " RBs " << tbAllocInfo.m_rbMap.front () << "-" <<  tbAllocInfo.m_rbMap.back ());
  		std::vector<int> bwChunkMap;
  		for(unsigned irb = tbAllocInfo.m_tbInfo.m_rbStart; irb < (tbAllocInfo.m_tbInfo.m_rbStart + tbAllocInfo.m_tbInfo.m_rbLen); irb++)
  		{
  			for(unsigned ichunk = 0; ichunk < m_phyMacConfig->GetNumChunkPerRb (); ichunk++)
  			{
  				bwChunkMap.push_back (ichunk + irb * m_phyMacConfig->GetNumChunkPerRb ());
  			}
  		}
  		m_downlinkSpectrumPhy->AddExpectedTb(tbAllocInfo.m_rnti, tbInfoElem.m_tbSize, tbInfoElem.m_mcs, bwChunkMap, true);
  	}
  	if (slotInd == 2)
  	{
  		NS_LOG_DEBUG ("ENB RXing CTRL+DATA period frame " << m_nrFrames << " subframe " << sfInd << " slot " << slotInd << \
  		              " start " << Simulator::Now() << " end " << Simulator::Now() + Seconds(GetTti()) );
  	}
  	else
  	{
  		NS_LOG_DEBUG ("ENB RXing DATA period frame " << m_nrFrames << " subframe " << sfInd << " slot " << slotInd << \
  		              " start " << Simulator::Now() << " end " << Simulator::Now() + Seconds(GetTti()) );
  	}
  }
  else
  {
  	NS_LOG_DEBUG ("ENB no allocation frame " << m_nrFrames << " subframe " << sfInd << " slot " << slotInd << \
  			              " start " << Simulator::Now() << " end " << Simulator::Now() + Seconds(GetTti()) );
  }

  m_prevSlotDir = slotDir;
>>>>>>> b36c54152804fd16ccc9464c4123d6ceeba3fb48

	m_phySapUser->SubframeIndication (SfnSf (m_frameNum, m_sfNum, m_slotNum));  // trigger MAC

	Simulator::Schedule (slotPeriod, &MmWaveEnbPhy::EndSlot, this);
}

void
MmWaveEnbPhy::EndSlot (void)
{
	NS_LOG_FUNCTION (this << Simulator::Now ().GetSeconds ());

	if (m_slotNum == m_currSfNumSlots-1)
	{
		m_slotNum = 0;
		EndSubFrame ();
	}
	else
	{
		Time nextSlotStart;
		uint8_t slotInd = m_slotNum+1;
		if (slotInd >= m_currSfAllocInfo.m_dlSlotAllocInfo.size ())
		{
			if (m_currSfAllocInfo.m_ulSlotAllocInfo.size () > 0)
			{
				slotInd = slotInd - m_currSfAllocInfo.m_dlSlotAllocInfo.size ();
				nextSlotStart = NanoSeconds (1000.0 * m_phyMacConfig->GetSymbolPeriod () *
				                             m_currSfAllocInfo.m_ulSlotAllocInfo[slotInd].m_dci.m_symStart);
			}
		}
		else
		{
			if (m_currSfAllocInfo.m_dlSlotAllocInfo.size () > 0)
			{
				nextSlotStart = NanoSeconds (1000.0 * m_phyMacConfig->GetSymbolPeriod () *
				                             m_currSfAllocInfo.m_dlSlotAllocInfo[slotInd].m_dci.m_symStart);
			}
		}
		m_slotNum++;
		Simulator::Schedule (nextSlotStart+m_lastSfStart-Simulator::Now(), &MmWaveEnbPhy::StartSlot, this);
	}
}

void
MmWaveEnbPhy::EndSubFrame (void)
{
	NS_LOG_FUNCTION (this << Simulator::Now ().GetSeconds ());
	Time sfStart = m_lastSfStart + m_sfPeriod - Simulator::Now();
	m_slotNum = 0;
	if (m_sfNum == m_phyMacConfig->GetSubframesPerFrame ()-1)
	{
		m_sfNum = 0;
//		if (m_frameNum == 1023)
//		{
//			m_frameNum = 0;
//		}
//		else
//		{
//			m_frameNum++;
//		}
		m_frameNum++;
	}
	else
	{
		m_sfNum++;
	}

	Simulator::Schedule (sfStart, &MmWaveEnbPhy::StartSubFrame, this);
}

void
MmWaveEnbPhy::SendDataChannels (Ptr<PacketBurst> pb, Time slotPrd, SlotAllocInfo& slotInfo)
{
	if (slotInfo.m_isOmni)
	{
		Ptr<AntennaArrayModel> antennaArray = DynamicCast<AntennaArrayModel> (GetDlSpectrumPhy ()->GetRxAntenna());
		antennaArray->ChangeToOmniTx ();
	}
	else
	{ // update beamforming vectors (currently supports 1 user only)
		//std::map<uint16_t, std::vector<unsigned> >::iterator ueRbIt = slotInfo.m_ueRbMap.begin();
		//uint16_t rnti = ueRbIt->first;
		for (uint8_t i = 0; i < m_deviceMap.size (); i++)
		{
			Ptr<MmWaveUeNetDevice> ueDev = DynamicCast<MmWaveUeNetDevice> (m_deviceMap.at (i));
			uint64_t ueRnti = ueDev->GetPhy ()-> GetRnti ();
			//NS_LOG_UNCOND ("Scheduled rnti:"<<rnti <<" ue rnti:"<< ueRnti);
			if (slotInfo.m_rnti == ueRnti)
			{
				//NS_LOG_UNCOND ("Change Beamforming Vector");
				Ptr<AntennaArrayModel> antennaArray = DynamicCast<AntennaArrayModel> (GetDlSpectrumPhy ()->GetRxAntenna());
				antennaArray->ChangeBeamformingVector (m_deviceMap.at (i));
				break;
			}
		}
	}

	/*
	if (!slotInfo.m_isOmni && !slotInfo.m_ueRbMap.empty ())
	{
		Ptr<AntennaArrayModel> antennaArray = DynamicCast<AntennaArrayModel> (GetDlSpectrumPhy ()->GetRxAntenna());
		 //set beamforming vector;
		 //for ENB, you can choose 64 antenna with 0-15 sectors, or 4 antenna with 0-3 sectors;
		 //input is (sector, antenna number)
		antennaArray->SetSector (0,64);
	}
	*/

	std::list<Ptr<MmWaveControlMessage> > ctrlMsgs;
	m_downlinkSpectrumPhy->StartTxDataFrames(pb, ctrlMsgs, slotPrd, slotInfo.m_slotIdx);
}

void
MmWaveEnbPhy::SendCtrlChannels(std::list<Ptr<MmWaveControlMessage> > ctrlMsgs, Time slotPrd)
{
	/* Send Ctrl messages*/
	NS_LOG_FUNCTION (this<<"Send Ctrl");
	m_downlinkSpectrumPhy->StartTxDlControlFrames (ctrlMsgs, slotPrd);
}

bool
MmWaveEnbPhy::AddUePhy (uint64_t imsi, Ptr<NetDevice> ueDevice)
{
	NS_LOG_FUNCTION (this<<imsi);
	std::set <uint64_t>::iterator it;
	it = m_ueAttached.find(imsi);

	if (it == m_ueAttached.end ())
	{
		m_ueAttached.insert(imsi);
		m_deviceMap.push_back(ueDevice);
		return (true);
	}
	else
	{
		NS_LOG_ERROR ("Programming error...UE already attached");
		return (false);
	}
}

void
MmWaveEnbPhy::PhyDataPacketReceived (Ptr<Packet> p)
{
	m_phySapUser->ReceivePhyPdu(p);
}

void
MmWaveEnbPhy::GenerateDataCqiReport (const SpectrumValue& sinr)
{
  NS_LOG_FUNCTION (this << sinr);

  Values::const_iterator it;
  MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters ulcqi;
  ulcqi.m_ulCqi.m_type = UlCqiInfo::PUSCH;
  int i = 0;
  for (it = sinr.ConstValuesBegin (); it != sinr.ConstValuesEnd (); it++)
  {
//  	double sinrdb = 10 * std::log10 ((*it));
  	//       NS_LOG_DEBUG ("ULCQI RB " << i << " value " << sinrdb);
  	// convert from double to fixed point notaltion Sxxxxxxxxxxx.xxx
//  	int16_t sinrFp = LteFfConverter::double2fpS11dot3 (sinrdb);
  	ulcqi.m_ulCqi.m_sinr.push_back (*it);
  	i++;
  }

  // here we use the start symbol index of the slot in place of the slot index because the absolute UL slot index is
  // not known to the scheduler when m_allocationMap gets populated
  ulcqi.m_sfnSf = SfnSf (m_frameNum, m_sfNum, m_currSymStart);
  SpectrumValue newSinr = sinr;
	m_ulSinrTrace (0, newSinr, newSinr);
  m_phySapUser->UlCqiReport (ulcqi);
}


void
MmWaveEnbPhy::PhyCtrlMessagesReceived (std::list<Ptr<MmWaveControlMessage> > msgList)
{
	std::list<Ptr<MmWaveControlMessage> >::iterator ctrlIt = msgList.begin ();

	while (ctrlIt != msgList.end ())
	{
		Ptr<MmWaveControlMessage> msg = (*ctrlIt);

		if (msg->GetMessageType () == MmWaveControlMessage::DL_CQI)
		{
			NS_LOG_INFO ("received CQI");
			m_phySapUser->ReceiveControlMessage (msg);
		}
		else if (msg->GetMessageType () == MmWaveControlMessage::BSR)
		{
			NS_LOG_INFO ("received BSR");
			m_phySapUser->ReceiveControlMessage (msg);
		}
		else if (msg->GetMessageType() == MmWaveControlMessage::RACH_PREAMBLE)
	  {
			NS_LOG_INFO ("received RACH_PREAMBLE");
			NS_ASSERT (m_cellId > 0);
			Ptr<MmWaveRachPreambleMessage> rachPreamble = DynamicCast<MmWaveRachPreambleMessage> (msg);
			m_phySapUser->ReceiveRachPreamble (rachPreamble->GetRapId ());
		}
		else if (msg->GetMessageType() == MmWaveControlMessage::DL_HARQ)
		{
			Ptr<MmWaveDlHarqFeedbackMessage> dlharqMsg = DynamicCast<MmWaveDlHarqFeedbackMessage> (msg);
			DlHarqInfo dlharq = dlharqMsg->GetDlHarqFeedback ();
			// check whether the UE is connected
			if (m_ueAttached.find (dlharq.m_rnti) != m_ueAttached.end ())
			{
				m_phySapUser->ReceiveControlMessage (msg);
			}
		}

		ctrlIt++;
	}

}

uint32_t
MmWaveEnbPhy::GetAbsoluteSubframeNo ()
{
	return ((m_frameNum - 1)*(m_phyMacConfig->GetSubframesPerFrame()*m_phyMacConfig->GetSlotsPerSubframe()) + m_slotNum);
}

////////////////////////////////////////////////////////////
/////////                     sap                 /////////
///////////////////////////////////////////////////////////

void
MmWaveEnbPhy::DoSetBandwidth (uint8_t ulBandwidth, uint8_t dlBandwidth)
{
  NS_LOG_FUNCTION (this << (uint32_t) ulBandwidth << (uint32_t) dlBandwidth);
}

void
MmWaveEnbPhy::DoSetEarfcn (uint16_t ulEarfcn, uint16_t dlEarfcn)
{
  NS_LOG_FUNCTION (this << ulEarfcn << dlEarfcn);
}


void
MmWaveEnbPhy::DoAddUe (uint16_t rnti)
{
	NS_LOG_FUNCTION (this << rnti);
	bool success = AddUePhy (rnti);
	NS_ASSERT_MSG (success, "AddUePhy() failed");

}

bool
MmWaveEnbPhy::AddUePhy (uint16_t rnti)
{
  NS_LOG_FUNCTION (this << rnti);
  std::set <uint16_t>::iterator it;
  it = m_ueAttachedRnti.find (rnti);
  if (it == m_ueAttachedRnti.end ())
    {
	  m_ueAttachedRnti.insert (rnti);
      return (true);
    }
  else
    {
      NS_LOG_ERROR ("UE already attached");
      return (false);
    }
}

void
MmWaveEnbPhy::DoRemoveUe (uint16_t rnti)
{
  NS_LOG_FUNCTION (this << rnti);
}

void
MmWaveEnbPhy::DoSetPa (uint16_t rnti, double pa)
{
  NS_LOG_FUNCTION (this << rnti);
}

void
MmWaveEnbPhy::DoSetTransmissionMode (uint16_t  rnti, uint8_t txMode)
{
  NS_LOG_FUNCTION (this << rnti << (uint16_t)txMode);
  // UL supports only SISO MODE
}

void
MmWaveEnbPhy::DoSetSrsConfigurationIndex (uint16_t  rnti, uint16_t srcCi)
{
  NS_LOG_FUNCTION (this);
}


void
MmWaveEnbPhy::DoSetMasterInformationBlock (LteRrcSap::MasterInformationBlock mib)
{
  NS_LOG_FUNCTION (this);
  //m_mib = mib;
}


void
MmWaveEnbPhy::DoSetSystemInformationBlockType1 (LteRrcSap::SystemInformationBlockType1 sib1)
{
  NS_LOG_FUNCTION (this);
  m_sib1 = sib1;
}

int8_t
MmWaveEnbPhy::DoGetReferenceSignalPower () const
{
  NS_LOG_FUNCTION (this);
  return m_txPower;
}

void
MmWaveEnbPhy::SetPhySapUser (MmWaveEnbPhySapUser* ptr)
{
	m_phySapUser = ptr;
}

void
MmWaveEnbPhy::SetHarqPhyModule (Ptr<MmWaveHarqPhy> harq)
{
  m_harqPhyModule = harq;
}

void
MmWaveEnbPhy::ReceiveUlHarqFeedback (UlHarqInfo mes)
{
  NS_LOG_FUNCTION (this);
  // forward to scheduler
  m_phySapUser->UlHarqFeedback (mes);
}

}
