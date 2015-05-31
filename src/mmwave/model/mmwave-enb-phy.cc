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

NS_LOG_COMPONENT_DEFINE ("mmWaveEnbPhy");

NS_OBJECT_ENSURE_REGISTERED (mmWaveEnbPhy);

mmWaveEnbPhy::mmWaveEnbPhy ()
{
	NS_LOG_FUNCTION (this);
	NS_FATAL_ERROR ("This constructor should not be called");
}

mmWaveEnbPhy::mmWaveEnbPhy (Ptr<mmWaveSpectrumPhy> dlPhy, Ptr<mmWaveSpectrumPhy> ulPhy)
    :mmWavePhy (dlPhy, ulPhy),
	m_nrFrames (0),
	m_nrSubFrames (0),
	m_prevSlot (2)
{
	m_enbCphySapProvider = new MemberLteEnbCphySapProvider<mmWaveEnbPhy> (this);
	Simulator::ScheduleNow (&mmWaveEnbPhy::StartFrame, this);
}

mmWaveEnbPhy::~mmWaveEnbPhy ()
{

}

TypeId
mmWaveEnbPhy::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::mmWaveEnbPhy")
    .SetParent<mmWavePhy> ()
    .AddConstructor<mmWaveEnbPhy> ()
	.AddAttribute ("TxPower",
	               "Transmission power in dBm",
	               DoubleValue (30.0),
	               MakeDoubleAccessor (&mmWaveEnbPhy::SetTxPower,
	                                   &mmWaveEnbPhy::GetTxPower),
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
	               MakeDoubleAccessor (&mmWavePhy::SetNoiseFigure,
	                                   &mmWavePhy::GetNoiseFigure),
	               MakeDoubleChecker<double> ())
	 .AddAttribute ("DlSpectrumPhy",
				    "The downlink mmWaveSpectrumPhy associated to this mmWavePhy",
				    TypeId::ATTR_GET,
				    PointerValue (),
				    MakePointerAccessor (&mmWaveEnbPhy::GetDlSpectrumPhy),
				    MakePointerChecker <mmWaveSpectrumPhy> ())
	 .AddAttribute ("UlSpectrumPhy",
				    "The uplink mmWaveSpectrumPhy associated to this mmWavePhy",
				    TypeId::ATTR_GET,
				    PointerValue (),
				    MakePointerAccessor (&mmWaveEnbPhy::GetUlSpectrumPhy),
				    MakePointerChecker <mmWaveSpectrumPhy> ())
	;
  return tid;

}

void
mmWaveEnbPhy::DoInitialize (void)
{
	NS_LOG_FUNCTION (this);
	Ptr<SpectrumValue> noisePsd = mmWaveSpectrumValueHelper::CreateNoisePowerSpectralDensity (m_PhyMACConfig, m_noiseFigure);
		m_downlinkSpectrumPhy->SetNoisePowerSpectralDensity (noisePsd);
	mmWavePhy::DoInitialize ();
}
void
mmWaveEnbPhy::DoDispose (void)
{

}

void
mmWaveEnbPhy::SetmmWaveEnbCphySapUser (LteEnbCphySapUser* s)
{
  NS_LOG_FUNCTION (this);
  m_enbCphySapUser = s;
}

LteEnbCphySapProvider*
mmWaveEnbPhy::GetmmWaveEnbCphySapProvider ()
{
  NS_LOG_FUNCTION (this);
  return m_enbCphySapProvider;
}

void
mmWaveEnbPhy::SetTxPower (double pow)
{
	m_txPower = pow;
}
double
mmWaveEnbPhy::GetTxPower () const
{
	return m_txPower;
}

void
mmWaveEnbPhy::SetNoiseFigure (double nf)
{
	m_noiseFigure = nf;
}
double
mmWaveEnbPhy::GetNoiseFigure () const
{
	return m_noiseFigure;
}

void
mmWaveEnbPhy::CalcChannelQualityForUe (std::vector <double> sinr, Ptr<mmWaveSpectrumPhy> ue)
{

}

Ptr<SpectrumValue>
mmWaveEnbPhy::CreateTxPowerSpectralDensity ()
{
	Ptr<SpectrumValue> psd =
			mmWaveSpectrumValueHelper::CreateTxPowerSpectralDensity (m_PhyMACConfig, m_txPower, m_listOfSubchannels );
	return psd;
}

void
mmWaveEnbPhy::DoSetSubChannels ()
{

}

void
mmWaveEnbPhy::SetSubChannels (std::vector<int> mask )
{
	m_listOfSubchannels = mask;
	Ptr<SpectrumValue> txPsd = CreateTxPowerSpectralDensity ();
	NS_ASSERT (txPsd);
	m_downlinkSpectrumPhy->SetTxPowerSpectralDensity (txPsd);
}

Ptr<mmWaveSpectrumPhy>
mmWaveEnbPhy::GetDlSpectrumPhy () const
{
  return m_downlinkSpectrumPhy;
}

Ptr<mmWaveSpectrumPhy>
mmWaveEnbPhy::GetUlSpectrumPhy () const
{
  return m_uplinkSpectrumPhy;
}

void
mmWaveEnbPhy::StartFrame (void)
{
	NS_LOG_FUNCTION (this);

	++m_nrFrames;
	m_nrSubFrames = 0;
	/*sending MIB at the beginning of each frame*/
	LteRrcSap::MasterInformationBlock mib;
	mib.dlBandwidth = (uint8_t)4;
	mib.systemFrameNumber = 1;

	Ptr<MibmmWaveControlMessage> mibMsg = Create<MibmmWaveControlMessage> ();
	mibMsg->SetMib(mib);
	if (m_controlMessagesQueue.empty())
	{
		std::list<Ptr<mmWaveControlMessages> > l;
		m_controlMessagesQueue.push_back (l);
	}
	m_controlMessagesQueue.at (0).push_back (mibMsg);

	StartSubFrame();
}
void
mmWaveEnbPhy::StartSubFrame (void)
{
	NS_LOG_FUNCTION (this);

	std::vector <int> channelRB;
	std::vector <allocationMap>::iterator itAllocMap;
	++m_nrSubFrames;

	uint16_t slot_num = ((m_nrSubFrames-1)%(m_PhyMACConfig->GetSlotPerSubframe ())) + 1;
	uint16_t sf_num = (m_nrSubFrames-1)/(m_PhyMACConfig->GetSlotPerSubframe ()) + 1;
	//NS_LOG_UNCOND ("ENB frame:"<<m_nrFrames<<"subframe:"<<sf_num<<"slot:"<<slot_num);

	/*sending sib1 every odd frame*/
	if ((m_nrSubFrames == 48) && ((m_nrFrames % 2) == 1))
	{
		Ptr<Sib1mmWaveControlMessage> msg = Create<Sib1mmWaveControlMessage> ();
		msg->SetSib1 (m_sib1);
		m_controlMessagesQueue.at (0).push_back (msg);
	}

	if(slot_num == 1)
	{
		UpdateCurrentAllocationAndSchedule (m_nrFrames, sf_num);
	}


	if (m_CurrentTDDMap.m_slotType.empty () || m_CurrentAllocationList.m_AllocationMapforSF.empty ())
	{
		NS_FATAL_ERROR ("No allocation decision available. MAC should avoid this");
	}

	Time dataFrameDelay = MicroSeconds (0);

	int channelDirection = 2;
	allocationMap map = m_CurrentAllocationList.m_AllocationMapforSF.front ();
	m_CurrentAllocationList.m_AllocationMapforSF.pop_front ();
	slotType st = m_CurrentTDDMap.m_slotType.at(slot_num-1);
	channelDirection = (int)map.m_IsUL;

	for (uint8_t i = 0; i< m_PhyMACConfig->GetTotalNumChunk(); i++)
	{
		channelRB.push_back(i);
	}

	SetSubChannels(channelRB);

	if (m_prevSlot != channelDirection && m_prevSlot != 2)
	{
		dataFrameDelay = MicroSeconds (1);
	}
	m_prevSlot = channelDirection;

	Time slotPeriod = Seconds(GetTti()) - dataFrameDelay - NanoSeconds (1);/*-1ns as margin to avoid overlapping simulator events*/
	if (st ==DATA)
	{

		/* Beam forming array element */

		uint64_t rnti = map.m_user.front().userImsi;
		uint16_t deviceNum = m_deviceMap. size ();
		if(deviceNum != 1)
		{
			/*change beamforming vector only attach more than 1 user*/
			for (uint8_t i = 0; i < deviceNum; i++)
			{
				Ptr<mmWaveUeNetDevice> ueDev = DynamicCast<mmWaveUeNetDevice> (m_deviceMap.at (i));
				uint64_t ueRnti = ueDev->GetPhy ()-> GetRnti ();
				//NS_LOG_UNCOND ("Scheduled rnti:"<<rnti <<" ue rnti:"<<  ueRnti);
				if (rnti == ueRnti)
				{
					//NS_LOG_UNCOND ("Change Beamforming Vector");
					Ptr<AntennaArrayModel> antennaArray = DynamicCast<AntennaArrayModel> (GetDlSpectrumPhy ()->GetRxAntenna());
					antennaArray->ChangeBeamformingVector (m_deviceMap.at (i));
					break;
				}
				else
				{
					//NS_LOG_UNCOND ("Not Change");
				}
			}
		}
	}

	if (channelDirection == 1)
	{
		/*set tbSize for Downlink Rx, only consider 1 user use the whole bandwidth*/
		if( st == DATA)
		{
			uint8_t rbs = m_PhyMACConfig->GetRBperSlot ();
			uint8_t chunksPerRb = m_PhyMACConfig->GetNumChunkPerRB ();
			std::map <uint16_t, tbInfo_t> tbMap;
			for (int i = 0; i < rbs; i++)
			{
				uint16_t rnti = map.m_user.at (i).userImsi;
				tbInfo_t tbInfo;
				tbInfo.size = map.m_user.at (i).m_tbsSize;
				tbInfo.mcs = map.m_user.at (i).m_mcs;
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
					if (map.m_user.at (rbId).userImsi == (*iter).first)
					{
						for (uint16_t chunkId = 0; chunkId<chunksPerRb; chunkId++)
						{
							rbMap.push_back (chunkId + chunksPerRb*rbId);
						}
					}
				}
				m_downlinkSpectrumPhy->AddExpectedTb((*iter).first, (*iter).second.size, (*iter).second.mcs, rbMap, true);
			}
		}//end calc expected tbSize
	}
	else if (channelDirection == 0)
	{
		if (st == DATA)
		{
			/* Downlink transmission*/
			Ptr<PacketBurst> pburst = GetPacketBurst ();
			Simulator::Schedule (dataFrameDelay, &mmWaveEnbPhy::SendDataChannels, this, pburst, slotPeriod);
		}
		else if (st == CTRL)
		{
			/*Control messages*/
			std::list<Ptr<mmWaveControlMessages> > ctrlMsg = GetControlMessages ();
			if (ctrlMsg.size() > 0)
			{
				std::list<Ptr<mmWaveControlMessages> >::iterator it = ctrlMsg.begin ();
				while (it != ctrlMsg.end ())
				{
					Ptr<mmWaveControlMessages> msg = (*it);
					if (msg->GetMessageType () == mmWaveControlMessages::RSC_ALLOCATION)
					{
						Ptr<mmWaveResourceAllocation> rsc = DynamicCast<mmWaveResourceAllocation> (msg);
						uint32_t key = rsc->GetSFNSF ();

						if (m_TDDPatternsFrorSF.find (key) == m_TDDPatternsFrorSF.end ())
						{
							m_TDDPatternsFrorSF.insert(std::pair <uint32_t,Schedule> (key,rsc->GetSchedule()));
						}

						if (m_AllocationListforSF.find (key) == m_AllocationListforSF.end ())
						{
							m_AllocationListforSF.insert (std::pair <uint32_t,allocationList> (key,rsc->GetAllocationMap()));
						}
					}
					it++;
				}
			}
			Simulator::Schedule (dataFrameDelay, &mmWaveEnbPhy::SendCtrlChannels, this, ctrlMsg, slotPeriod);
		}
		else
		{
			NS_LOG_ERROR ("Programming Error: Slot type is neither data nor control");
		}
	}
	else
	{
		NS_LOG_ERROR("Programming Error");
	}

	m_phySapUser->SubframeIndication( m_nrFrames, sf_num, slot_num);

	Simulator::Schedule (Seconds(GetTti()),
			            &mmWaveEnbPhy::EndSubFrame,
						this);
}

void
mmWaveEnbPhy::EndSubFrame (void)
{
	NS_LOG_FUNCTION (this << Simulator::Now ().GetSeconds ());


	if (m_nrSubFrames == (m_PhyMACConfig->GetSlotPerSubframe()*m_PhyMACConfig->GetSubframePerFrame()) )
	{
		Simulator::ScheduleNow (&mmWaveEnbPhy::EndFrame, this);
	}
	else
	{
		Simulator::ScheduleNow (&mmWaveEnbPhy::StartSubFrame, this);
	}
}
void
mmWaveEnbPhy::EndFrame (void)
{
	NS_LOG_FUNCTION (this << Simulator::Now ().GetSeconds ());
	Simulator::ScheduleNow (&mmWaveEnbPhy::StartFrame, this);
}

void
mmWaveEnbPhy::SendDataChannels (Ptr<PacketBurst> pb, Time slotPrd )
{
	std::list<Ptr<mmWaveControlMessages> > ctrlMsg;
	m_downlinkSpectrumPhy->StartTxDataFrames(pb, ctrlMsg, slotPrd);
}

void
mmWaveEnbPhy::SendCtrlChannels(std::list<Ptr<mmWaveControlMessages> > ctrlMsg, Time slotPrd)
{
	/* Send Ctrl messages*/
	NS_LOG_FUNCTION (this<<"Send Ctrl");
	m_downlinkSpectrumPhy->StartTxDlControlFrames (ctrlMsg, slotPrd);
}

bool
mmWaveEnbPhy::AddUePhy (uint64_t imsi, Ptr<NetDevice> ueDevice)
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
mmWaveEnbPhy::PhyDataPacketReceived (Ptr<Packet> p)
{
	m_phySapUser->ReceivePhyPdu(p);
}

void
mmWaveEnbPhy::PhyCtrlMessageReceived (std::list<Ptr<mmWaveControlMessages> > msgList)
{
	std::list<Ptr<mmWaveControlMessages> >::iterator ctrlIt = msgList.begin ();

	while (ctrlIt != msgList.end ())
	{
		Ptr<mmWaveControlMessages> msg = (*ctrlIt);

		if (msg->GetMessageType () == mmWaveControlMessages::CQI)
		{
			NS_LOG_INFO ("received CQI");
			m_phySapUser->ReceivemmWaveControlMessage (msg);

		}
		else if (msg->GetMessageType() == mmWaveControlMessages::RACH_PREAMBLE)
	    {
			NS_LOG_INFO ("received RACH_PREAMBLE");
			NS_ASSERT (m_cellId > 0);
			Ptr<RachPreamblemmWaveControlMessage> rachPreamble = DynamicCast<RachPreamblemmWaveControlMessage> (msg);
			m_phySapUser->ReceiveRachPreamble (rachPreamble->GetRapId ());

		}


		ctrlIt++;
	}

}

uint32_t
mmWaveEnbPhy::GetAbsoulteSubframeNo ()
{
	return ((m_nrFrames - 1)*(m_PhyMACConfig->GetSubframePerFrame()*m_PhyMACConfig->GetSlotPerSubframe()) + m_nrSubFrames);
}

////////////////////////////////////////////////////////////
/////////                     sap                 /////////
///////////////////////////////////////////////////////////

void
mmWaveEnbPhy::DoSetBandwidth (uint8_t ulBandwidth, uint8_t dlBandwidth)
{
  NS_LOG_FUNCTION (this << (uint32_t) ulBandwidth << (uint32_t) dlBandwidth);
}

void
mmWaveEnbPhy::DoSetEarfcn (uint16_t ulEarfcn, uint16_t dlEarfcn)
{
  NS_LOG_FUNCTION (this << ulEarfcn << dlEarfcn);
}


void
mmWaveEnbPhy::DoAddUe (uint16_t rnti)
{
	NS_LOG_FUNCTION (this << rnti);
	bool success = AddUePhy (rnti);
	NS_ASSERT_MSG (success, "AddUePhy() failed");

}

bool
mmWaveEnbPhy::AddUePhy (uint16_t rnti)
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
mmWaveEnbPhy::DoRemoveUe (uint16_t rnti)
{
  NS_LOG_FUNCTION (this << rnti);
}

void
mmWaveEnbPhy::DoSetPa (uint16_t rnti, double pa)
{
  NS_LOG_FUNCTION (this << rnti);
}

void
mmWaveEnbPhy::DoSetTransmissionMode (uint16_t  rnti, uint8_t txMode)
{
  NS_LOG_FUNCTION (this << rnti << (uint16_t)txMode);
  // UL supports only SISO MODE
}

void
mmWaveEnbPhy::DoSetSrsConfigurationIndex (uint16_t  rnti, uint16_t srcCi)
{
  NS_LOG_FUNCTION (this);
}


void
mmWaveEnbPhy::DoSetMasterInformationBlock (LteRrcSap::MasterInformationBlock mib)
{
  NS_LOG_FUNCTION (this);
  //m_mib = mib;
}


void
mmWaveEnbPhy::DoSetSystemInformationBlockType1 (LteRrcSap::SystemInformationBlockType1 sib1)
{
  NS_LOG_FUNCTION (this);
  m_sib1 = sib1;
}

int8_t
mmWaveEnbPhy::DoGetReferenceSignalPower () const
{
  NS_LOG_FUNCTION (this);
  return m_txPower;
}

}
