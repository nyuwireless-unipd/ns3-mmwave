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
  m_nrSlots (0),
	m_nrFrames (0),
	m_prevSlot (0)
{
	m_enbCphySapProvider = new MemberLteEnbCphySapProvider<MmWaveEnbPhy> (this);
	Simulator::ScheduleNow (&MmWaveEnbPhy::StartFrame, this);
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
	;
  return tid;

}

void
MmWaveEnbPhy::DoInitialize (void)
{
	NS_LOG_FUNCTION (this);
	Ptr<SpectrumValue> noisePsd = mmWaveSpectrumValueHelper::CreateNoisePowerSpectralDensity (m_phyMacConfig, m_noiseFigure);
	m_downlinkSpectrumPhy->SetNoisePowerSpectralDensity (noisePsd);
  m_numRbg = m_phyMacConfig->GetNumRb() / m_phyMacConfig->GetNumRbPerRbg();
	m_ctrlPeriod = NanoSeconds (1000 * m_phyMacConfig->GetCtrlSymbols() * m_phyMacConfig->GetSymbolPeriod());
	m_dataPeriod = NanoSeconds (1000 * (m_phyMacConfig->GetSymbPerSlot() - m_phyMacConfig->GetCtrlSymbols()) * m_phyMacConfig->GetSymbolPeriod());
	m_ulTbAllocQueue.resize (m_phyMacConfig->GetUlSchedDelay());
	for (unsigned i = 0; i < m_phyMacConfig->GetL1L2CtrlLatency(); i++)
	{ // push elements onto queue for initial scheduling delay
		m_controlMessageQueue.push_back (std::list<Ptr<MmWaveControlMessage> > ());
	}

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
			mmWaveSpectrumValueHelper::CreateTxPowerSpectralDensity (m_phyMacConfig, m_txPower, m_listOfSubchannels );
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
MmWaveEnbPhy::StartFrame (void)
{
	NS_LOG_FUNCTION (this);

	++m_nrFrames;
	m_nrSlots = 0;
	/*sending MIB at the beginning of each frame*/
	LteRrcSap::MasterInformationBlock mib;
	mib.dlBandwidth = (uint8_t)4;
	mib.systemFrameNumber = 1;

	Ptr<MmWaveMibMessage> mibMsg = Create<MmWaveMibMessage> ();
	mibMsg->SetMib(mib);
	/*
	if (m_controlMessageQueue.empty())
	{
		std::list<Ptr<MmWaveControlMessage> > l;
		m_controlMessageQueue.push_back (l);
	}
	*/
	m_controlMessageQueue.at (0).push_back (mibMsg);

	StartSubFrame();
}

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

void
MmWaveEnbPhy::StartSubFrame (void)
{
	NS_LOG_FUNCTION (this);

	std::vector <int> channelRB;
	std::vector <SlotAllocInfo>::iterator itAllocMap;
	++m_nrSlots;

	uint16_t slotInd = ((m_nrSlots-1)%(m_phyMacConfig->GetSlotsPerSubframe ())) + 1;
	uint16_t sfInd = (m_nrSlots-1)/(m_phyMacConfig->GetSlotsPerSubframe ()) + 1;

	for (uint8_t i = 0; i< m_phyMacConfig->GetTotalNumChunk(); i++)
	{
		channelRB.push_back(i);
	}
	SetSubChannels(channelRB);

	/*sending sib1 every odd frame*/
	if ((m_nrSlots == 48) && ((m_nrFrames % 2) == 1))
	{
		Ptr<MmWaveSib1Message> msg = Create<MmWaveSib1Message> ();
		msg->SetSib1 (m_sib1);
		m_controlMessageQueue.at (0).push_back (msg);
	}

	std::list<Ptr<MmWaveControlMessage> > ctrlMsg;
	if(slotInd == 1)
	{
		uint32_t sfn = ((0x3FF & m_nrFrames) << 16) | ((0xFF & sfInd) << 8) | ((0xFF & 1));

	  m_harqPhyModule->SubframeIndication (m_nrFrames, sfInd);

	  m_prevSlotDir = SlotAllocInfo::NA;

		// create new subframe allocation info
		m_currSfAllocInfo = SfAllocationInfo (m_phyMacConfig->GetSlotsPerSubframe ());

		ctrlMsg = GetControlMessages ();

		// process downlink assignments for current subframe
		std::list<Ptr<MmWaveControlMessage> >::iterator it = ctrlMsg.begin ();
		while (it != ctrlMsg.end ())
		{
			Ptr<MmWaveControlMessage> msg = (*it);
			if (msg->GetMessageType () == MmWaveControlMessage::DCI)
			{
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
						if ( ((dciInfo.m_tddBitmap >> tbIt->m_slotInd) & 0x1) == 0)
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
			}
			it++;
		}

		// process uplink assignments for current subframe
	  std::list<TbAllocInfo> ulAllocInfoList = DequeueUlTbAlloc ();
	  std::list<TbAllocInfo>::iterator ulAllocIt = ulAllocInfoList.begin ();
	  NS_LOG_DEBUG (this << " eNB Expected UL TBs " << ulAllocInfoList.size ());
	  while(ulAllocIt != ulAllocInfoList.end ())
	  {
	  	std::set <uint16_t>::iterator ueIt = m_ueAttachedRnti.find ((*ulAllocIt).m_rnti);

	  	if (ueIt == m_ueAttachedRnti.end ())
	  	{
	  		NS_LOG_ERROR ("UE not attached");
	  	}
	  	else
	  	{
	  		SlotAllocInfo& slotInfo = m_currSfAllocInfo.m_slotAllocInfo[(unsigned) ulAllocIt->m_tbInfo.m_slotInd]; // DL res alloc info, applies to this subframe
				NS_LOG_INFO ("ENB: UL slot " << (unsigned) slotInfo.m_slotInd);
	  		slotInfo.m_tbInfo.push_back (*ulAllocIt);
	  		if (m_currSfAllocInfo.m_tddPattern[ulAllocIt->m_tbInfo.m_slotInd] == SlotAllocInfo::NA)
	  		{
	  			m_currSfAllocInfo.m_tddPattern[ulAllocIt->m_tbInfo.m_slotInd] = SlotAllocInfo::UL;
	  		}
	  		else if (m_currSfAllocInfo.m_tddPattern[ulAllocIt->m_tbInfo.m_slotInd] == SlotAllocInfo::DL)
	  		{
	  			NS_LOG_ERROR ("Slot already assigned in DL");
	  		}
				std::map<uint16_t, std::vector<unsigned> >::iterator ueRbIt = slotInfo.m_ueRbMap.find (ulAllocIt->m_rnti);
				if (ueRbIt == slotInfo.m_ueRbMap.end ())
				{
					slotInfo.m_ueRbMap.insert (std::pair<uint16_t, std::vector<unsigned> > (ulAllocIt->m_rnti, ulAllocIt->m_rbMap));
				}
				else
				{
					ueRbIt->second.insert(ueRbIt->second.end (), ulAllocIt->m_rbMap.begin (), ulAllocIt->m_rbMap.end ());
				}
	  	}
	  	ulAllocIt++;
	  }
	}

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
  			NS_LOG_DEBUG ("Slot scheduled for Downlink Ctrl+Data");
  		}
  		else
  		{
  			NS_LOG_DEBUG ("Slot scheduled for Downlink Data");
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
  			NS_LOG_DEBUG ("ENB TXing CTRL period frame " << m_nrFrames << " sf " << sfInd << " slot " << slotInd << \
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
  				MmWaveMacPduHeader macHeader;
  				pkts.front ()->PeekHeader (macHeader);
  				NS_ASSERT ((macHeader.GetSubframeNum() == sfInd) && (macHeader.GetSlotNum() == slotInd));
  			}
  		}
			NS_LOG_DEBUG ("ENB TXing DATA period frame " << m_nrFrames << " sf " << sfInd << " slot " << slotInd << \
			              " start " << Simulator::Now()+ctrlPeriod+NanoSeconds(1.0) << " end " << Simulator::Now() + ctrlPeriod + dataPeriod-NanoSeconds (2.0));
  		Simulator::Schedule (ctrlPeriod, &MmWaveEnbPhy::SendDataChannels, this, pktBurst, dataPeriod-NanoSeconds (2.0), slotInfo);
  	}
  }
  else if (slotDir == SlotAllocInfo::UL || slotInd == 2)  // Uplink slot
  {
		NS_LOG_DEBUG ("Slot scheduled for Uplink Data");
  	for (unsigned itb = 0; itb < slotInfo.m_tbInfo.size (); itb++)
  	{
  		TbAllocInfo tbAllocInfo = slotInfo.m_tbInfo[itb];
  		TbInfoElement tbInfoElem = tbAllocInfo.m_tbInfo;
  		NS_LOG_DEBUG ("UE " << tbAllocInfo.m_rnti << " TBS " << tbInfoElem.m_tbSize << " MCS " << tbInfoElem.m_mcs << \
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
  		NS_LOG_DEBUG ("ENB RXing CTRL+DATA period frame " << m_nrFrames << " sf " << sfInd << " slot " << slotInd << \
  		              " start " << Simulator::Now() << " end " << Simulator::Now() + Seconds(GetTti()) );
  	}
  	else
  	{
  		NS_LOG_DEBUG ("ENB RXing DATA period frame " << m_nrFrames << " sf " << sfInd << " slot " << slotInd << \
  		              " start " << Simulator::Now() << " end " << Simulator::Now() + Seconds(GetTti()) );
  	}
  }
  else
  {
  	NS_LOG_DEBUG ("ENB no allocation frame " << m_nrFrames << " sf " << sfInd << " slot " << slotInd << \
  			              " start " << Simulator::Now() << " end " << Simulator::Now() + Seconds(GetTti()) );
  }

  m_prevSlotDir = slotDir;

	m_phySapUser->SubframeIndication (m_nrFrames, sfInd, slotInd);

	Simulator::Schedule (Seconds(GetTti()), &MmWaveEnbPhy::EndSubFrame, this);
}

void
MmWaveEnbPhy::EndSubFrame (void)
{
	NS_LOG_FUNCTION (this << Simulator::Now ().GetSeconds ());


	if (m_nrSlots == (m_phyMacConfig->GetSlotsPerSubframe()*m_phyMacConfig->GetSubframesPerFrame()) )
	{
		Simulator::ScheduleNow (&MmWaveEnbPhy::EndFrame, this);
	}
	else
	{
		Simulator::ScheduleNow (&MmWaveEnbPhy::StartSubFrame, this);
	}
}
void

MmWaveEnbPhy::EndFrame (void)
{
	NS_LOG_FUNCTION (this << Simulator::Now ().GetSeconds ());
	Simulator::ScheduleNow (&MmWaveEnbPhy::StartFrame, this);
}

void
MmWaveEnbPhy::SendDataChannels (Ptr<PacketBurst> pb, Time slotPrd, SlotAllocInfo& slotInfo)
{
	if (slotInfo.m_isOmni)
	{
		Ptr<AntennaArrayModel> antennaArray = DynamicCast<AntennaArrayModel> (GetDlSpectrumPhy ()->GetRxAntenna());
		antennaArray->ChangeToOmniTx ();
	}

	if (!slotInfo.m_isOmni && !slotInfo.m_ueRbMap.empty ())
	{ // update beamforming vectors (currently supports 1 user only)
		std::map<uint16_t, std::vector<unsigned> >::iterator ueRbIt = slotInfo.m_ueRbMap.begin();
		uint16_t rnti = ueRbIt->first;
		for (uint8_t i = 0; i < m_deviceMap.size (); i++)
		{
			Ptr<MmWaveUeNetDevice> ueDev = DynamicCast<MmWaveUeNetDevice> (m_deviceMap.at (i));
			uint64_t ueRnti = ueDev->GetPhy ()-> GetRnti ();
			//NS_LOG_UNCOND ("Scheduled rnti:"<<rnti <<" ue rnti:"<< ueRnti);
			if (rnti == ueRnti)
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

	std::list<Ptr<MmWaveControlMessage> > ctrlMsg;
	m_downlinkSpectrumPhy->StartTxDataFrames(pb, ctrlMsg, slotPrd, slotInfo.m_slotInd);
}

void
MmWaveEnbPhy::SendCtrlChannels(std::list<Ptr<MmWaveControlMessage> > ctrlMsg, Time slotPrd)
{
	/* Send Ctrl messages*/
	NS_LOG_FUNCTION (this<<"Send Ctrl");
	m_downlinkSpectrumPhy->StartTxDlControlFrames (ctrlMsg, slotPrd);
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
  	double sinrdb = 10 * std::log10 ((*it));
  	//       NS_LOG_DEBUG ("ULCQI RB " << i << " value " << sinrdb);
  	// convert from double to fixed point notation Sxxxxxxxxxxx.xxx
  	int16_t sinrFp = LteFfConverter::double2fpS11dot3 (sinrdb);
  	ulcqi.m_ulCqi.m_sinr.push_back (sinrFp);
  	i++;
  }

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
	return ((m_nrFrames - 1)*(m_phyMacConfig->GetSubframesPerFrame()*m_phyMacConfig->GetSlotsPerSubframe()) + m_nrSlots);
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
