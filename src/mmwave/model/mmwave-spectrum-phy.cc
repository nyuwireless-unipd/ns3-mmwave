 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2 as
 *   published by the Free Software Foundation;
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *   Author: Marco Miozzo <marco.miozzo@cttc.es>
 *           Nicola Baldo  <nbaldo@cttc.es>
 *
 *   Modified by: Marco Mezzavilla < mezzavilla@nyu.edu>
 *        	 	  Sourjya Dutta <sdutta@nyu.edu>
 *        	 	  Russell Ford <russell.ford@nyu.edu>
 *        		  Menglei Zhang <menglei@nyu.edu>
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *                 Dual Connectivity and Handover functionalities
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *								 Integration of Carrier Aggregation
 */



#include <ns3/object-factory.h>
#include <ns3/log.h>
#include <ns3/ptr.h>
#include <ns3/boolean.h>
#include <cmath>
#include <ns3/simulator.h>
#include <ns3/trace-source-accessor.h>
#include <ns3/antenna-model.h>
#include "mmwave-spectrum-phy.h"
#include "mmwave-phy-mac-common.h"
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mc-ue-net-device.h>
#include <ns3/mmwave-ue-phy.h>
#include "mmwave-radio-bearer-tag.h"
#include <stdio.h>
#include <ns3/double.h>
#include <ns3/mmwave-mi-error-model.h>
#include "mmwave-mac-pdu-tag.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("MmWaveSpectrumPhy");

namespace mmwave {

NS_OBJECT_ENSURE_REGISTERED (MmWaveSpectrumPhy);

static const double EffectiveCodingRate[29] = {
  0.08,
  0.1,
  0.11,
  0.15,
  0.19,
  0.24,
  0.3,
  0.37,
  0.44,
  0.51,
  0.3,
  0.33,
  0.37,
  0.42,
  0.48,
  0.54,
  0.6,
  0.43,
  0.45,
  0.5,
  0.55,
  0.6,
  0.65,
  0.7,
  0.75,
  0.8,
  0.85,
  0.89,
  0.92
};

MmWaveSpectrumPhy::MmWaveSpectrumPhy()
	:m_cellId(0),
	 m_state(IDLE),
   m_componentCarrierId (0)
{
	m_interferenceData = CreateObject<mmWaveInterference> ();
	m_random = CreateObject<UniformRandomVariable> ();
	m_random->SetAttribute ("Min", DoubleValue (0.0));
	m_random->SetAttribute ("Max", DoubleValue (1.0));
}
MmWaveSpectrumPhy::~MmWaveSpectrumPhy()
{

}

TypeId
MmWaveSpectrumPhy::GetTypeId(void)
{
	static TypeId
		tid =
	    TypeId ("ns3::MmWaveSpectrumPhy")
	    .SetParent<NetDevice> ()
		.AddTraceSource ("RxPacketTraceEnb",
						 "The no. of packets received and transmitted by the Base Station",
						 MakeTraceSourceAccessor (&MmWaveSpectrumPhy::m_rxPacketTraceEnb),
						 "ns3::EnbTxRxPacketCount::TracedCallback")
		.AddTraceSource ("RxPacketTraceUe",
						 "The no. of packets received and transmitted by the User Device",
						 MakeTraceSourceAccessor (&MmWaveSpectrumPhy::m_rxPacketTraceUe),
						 "ns3::UeTxRxPacketCount::TracedCallback")
		.AddAttribute ("DataErrorModelEnabled",
										"Activate/Deactivate the error model of data (TBs of PDSCH and PUSCH) [by default is active].",
						 BooleanValue (true),
						 MakeBooleanAccessor (&MmWaveSpectrumPhy::m_dataErrorModelEnabled),
						 MakeBooleanChecker ())

		.AddAttribute ("FileName",
						"file name",
						 StringValue ("no"),
						 MakeStringAccessor (&MmWaveSpectrumPhy::m_fileName),
						 MakeStringChecker ())
		;

	return tid;
}
void
MmWaveSpectrumPhy::DoDispose()
{

}

void
MmWaveSpectrumPhy::Reset ()
{
  NS_LOG_FUNCTION (this);
  m_cellId = 0;
  m_state = IDLE;
  m_endTxEvent.Cancel ();
  m_endRxDataEvent.Cancel ();
  m_endRxDlCtrlEvent.Cancel ();
  m_rxControlMessageList.clear ();
  m_expectedTbs.clear ();
  m_rxPacketBurstList.clear ();
  //m_txPacketBurst = 0;
  //m_rxSpectrumModel = 0;
}

void
MmWaveSpectrumPhy::ResetSpectrumModel()
{
	m_rxSpectrumModel = 0;
}

void
MmWaveSpectrumPhy::SetDevice(Ptr<NetDevice> d)
{
	m_device = d;

	Ptr<MmWaveEnbNetDevice> enbNetDev =
			DynamicCast<MmWaveEnbNetDevice> (GetDevice ());

	if (enbNetDev != 0)
	{
		m_isEnb = true;
	}
	else
	{
		m_isEnb = false;
	}
}

Ptr<NetDevice>
MmWaveSpectrumPhy::GetDevice() const
{
	return m_device;
}

void
MmWaveSpectrumPhy::SetMobility (Ptr<MobilityModel> m)
{
	m_mobility = m;
}

Ptr<MobilityModel>
MmWaveSpectrumPhy::GetMobility ()
{
	return m_mobility;
}

void
MmWaveSpectrumPhy::SetChannel (Ptr<SpectrumChannel> c)
{
	m_channel = c;
}

Ptr<const SpectrumModel>
MmWaveSpectrumPhy::GetRxSpectrumModel () const
{
	return m_rxSpectrumModel;
}

Ptr<AntennaModel>
MmWaveSpectrumPhy::GetRxAntenna ()
{
	return m_antenna;
}

void
MmWaveSpectrumPhy::SetAntenna (Ptr<AntennaModel> a)
{
	m_antenna = a;
}

void
MmWaveSpectrumPhy::SetState (State newState)
{
  ChangeState (newState);
}

void
MmWaveSpectrumPhy::ChangeState (State newState)
{
  NS_LOG_LOGIC (this << " state: " << m_state << " -> " << newState);
  m_state = newState;
}


void
MmWaveSpectrumPhy::SetNoisePowerSpectralDensity(Ptr<const SpectrumValue> noisePsd)
{
	NS_LOG_FUNCTION (this << noisePsd);
	NS_ASSERT (noisePsd);
	m_rxSpectrumModel = noisePsd->GetSpectrumModel ();
	m_interferenceData->SetNoisePowerSpectralDensity (noisePsd);

}

void
MmWaveSpectrumPhy::SetTxPowerSpectralDensity (Ptr<SpectrumValue> TxPsd)
{
	m_txPsd = TxPsd;
}

void
MmWaveSpectrumPhy::SetPhyRxDataEndOkCallback (MmWavePhyRxDataEndOkCallback c)
{
	m_phyRxDataEndOkCallback = c;
}


void
MmWaveSpectrumPhy::SetPhyRxCtrlEndOkCallback (MmWavePhyRxCtrlEndOkCallback c)
{
  m_phyRxCtrlEndOkCallback = c;
}

void
MmWaveSpectrumPhy::AddExpectedTb (uint16_t rnti, uint8_t ndi, uint16_t size, uint8_t mcs,
                                  std::vector<int> chunkMap, uint8_t harqId, uint8_t rv, bool downlink,
                                  uint8_t symStart, uint8_t numSym)
{
	//layer = layer;
	ExpectedTbMap_t::iterator it;
	it = m_expectedTbs.find (rnti);
	if (it != m_expectedTbs.end ())
	{
		m_expectedTbs.erase (it);
	}
	// insert new entry
	//ExpectedTbInfo_t tbInfo = {ndi, size, mcs, chunkMap, harqId, rv, 0.0, downlink, false, false, 0};
	ExpectedTbInfo_t tbInfo = {ndi, size, mcs, chunkMap, harqId, rv, 0.0, downlink, false, false, 0, symStart, numSym};
	m_expectedTbs.insert (std::pair<uint16_t, ExpectedTbInfo_t> (rnti,tbInfo));
}

/*
void
MmWaveSpectrumPhy::AddExpectedTb (uint16_t rnti, uint16_t size, uint8_t mcs, std::vector<int> chunkMap, bool downlink)
{
	//layer = layer;
	ExpectedTbMap_t::iterator it;
	it = m_expectedTbs.find (rnti);
	if (it != m_expectedTbs.end ())
	{
		m_expectedTbs.erase (it);
	}
	// insert new entry
	ExpectedTbInfo_t tbInfo = {1, size, mcs, chunkMap, 0, 0, 0.0, downlink, false, false};
	m_expectedTbs.insert (std::pair<uint16_t, ExpectedTbInfo_t> (rnti,tbInfo));
}
*/

void
MmWaveSpectrumPhy::SetPhyDlHarqFeedbackCallback (MmWavePhyDlHarqFeedbackCallback c)
{
  NS_LOG_FUNCTION (this);
  m_phyDlHarqFeedbackCallback = c;
}

void
MmWaveSpectrumPhy::SetPhyUlHarqFeedbackCallback (MmWavePhyUlHarqFeedbackCallback c)
{
  NS_LOG_FUNCTION (this);
  m_phyUlHarqFeedbackCallback = c;
}

void
MmWaveSpectrumPhy::StartRx (Ptr<SpectrumSignalParameters> params)
{

	NS_LOG_FUNCTION(this);

	Ptr<MmWaveEnbNetDevice> EnbTx =
			DynamicCast<MmWaveEnbNetDevice> (params->txPhy->GetDevice ());
	Ptr<MmWaveEnbNetDevice> enbRx =
			DynamicCast<MmWaveEnbNetDevice> (GetDevice ());
	if((EnbTx != 0 && enbRx != 0) || (EnbTx == 0 && enbRx == 0))
	{
		NS_LOG_INFO ("BS to BS or UE to UE transmission neglected.");
		return;
	}

	Ptr<MmwaveSpectrumSignalParametersDataFrame> mmwaveDataRxParams =
			DynamicCast<MmwaveSpectrumSignalParametersDataFrame> (params);

	if (mmwaveDataRxParams!=0)
	{
		bool isAllocated = true;
		Ptr<mmwave::MmWaveUeNetDevice> ueRx = 0;
		ueRx = DynamicCast<mmwave::MmWaveUeNetDevice> (GetDevice ());
		Ptr<McUeNetDevice> rxMcUe = 0;
		rxMcUe = DynamicCast<McUeNetDevice> (GetDevice ());

		if ((ueRx!=0) && (ueRx->GetPhy (m_componentCarrierId)->IsReceptionEnabled () == false))
		{	// if the first cast is 0 (the device is MC) then this if will not be executed
			isAllocated = false;
		}
		else if ((rxMcUe != 0) && (rxMcUe->GetMmWavePhy(m_componentCarrierId)->IsReceptionEnabled() == false))
		{	// this is executed if the device is MC and is transmitting
			isAllocated = false;
		}

		if (isAllocated)
		{
			m_interferenceData->AddSignal (mmwaveDataRxParams->psd, mmwaveDataRxParams->duration);
			if(mmwaveDataRxParams->cellId == m_cellId)
			{
				//m_interferenceData->AddSignal (mmwaveDataRxParams->psd, mmwaveDataRxParams->duration);
				StartRxData (mmwaveDataRxParams);
			}
			/*
			else
			{
				if (ueRx != 0)
				{
					m_interferenceData->AddSignal (mmwaveDataRxParams->psd, mmwaveDataRxParams->duration);
				}
			}
			*/
		}
	}
	else
	{
		Ptr<MmWaveSpectrumSignalParametersDlCtrlFrame> DlCtrlRxParams =
				DynamicCast<MmWaveSpectrumSignalParametersDlCtrlFrame> (params);
		if (DlCtrlRxParams!=0)
		{
			if (DlCtrlRxParams->cellId == m_cellId)
			{
				StartRxCtrl (params);
			}
			else
			{
				// Do nothing
			}
		}
	}
}

void
MmWaveSpectrumPhy::StartRxData (Ptr<MmwaveSpectrumSignalParametersDataFrame> params)
{
	m_interferenceData->StartRx (params->psd);

	NS_LOG_FUNCTION(this);

	Ptr<MmWaveEnbNetDevice> enbRx =
				DynamicCast<MmWaveEnbNetDevice> (GetDevice ());
	Ptr<mmwave::MmWaveUeNetDevice> ueRx =
				DynamicCast<mmwave::MmWaveUeNetDevice> (GetDevice ());
	Ptr<McUeNetDevice> rxMcUe =
				DynamicCast<McUeNetDevice> (GetDevice ());

	switch(m_state)
	{
	case TX:
		NS_LOG_INFO(this << " m_cellId");
		NS_FATAL_ERROR("Cannot receive while transmitting");
		break;
	case RX_CTRL:
			NS_FATAL_ERROR("Cannot receive control in data period");
			break;
	case RX_DATA:
	case IDLE:
	{
		if (params->cellId == m_cellId)
		{
			if (m_rxPacketBurstList.empty())
			{
        NS_ASSERT (m_state == IDLE);
				// first transmission, i.e., we're IDLE and we start RX
				m_firstRxStart = Simulator::Now ();
				m_firstRxDuration = params->duration;
				NS_LOG_LOGIC (this << " scheduling EndRx with delay " << params->duration.GetSeconds () << "s");

				m_endRxDataEvent = Simulator::Schedule (params->duration, &MmWaveSpectrumPhy::EndRxData, this);
			}
			else
			{
				NS_ASSERT (m_state == RX_DATA);
				// sanity check: if there are multiple RX events, they
				// should occur at the same time and have the same
				// duration, otherwise the interference calculation
				// won't be correct
				NS_ASSERT ((m_firstRxStart == Simulator::Now ()) && (m_firstRxDuration == params->duration));
			}

			ChangeState (RX_DATA);
			if (params->packetBurst && !params->packetBurst->GetPackets ().empty ())
			{
				m_rxPacketBurstList.push_back (params->packetBurst);
			}
			//NS_LOG_DEBUG (this << " insert msgs " << params->ctrlMsgList.size ());
			m_rxControlMessageList.insert (m_rxControlMessageList.end (), params->ctrlMsgList.begin (), params->ctrlMsgList.end ());

			NS_LOG_LOGIC (this << " numSimultaneousRxEvents = " << m_rxPacketBurstList.size ());
		}
		else
		{
			NS_LOG_LOGIC (this << " not in sync with this signal (cellId="
			              << params->cellId  << ", m_cellId=" << m_cellId << ")");
		}
	}
	break;
	default:
		NS_FATAL_ERROR("Programming Error: Unknown State");
	}
}

void
MmWaveSpectrumPhy::StartRxCtrl (Ptr<SpectrumSignalParameters> params)
{
	NS_LOG_FUNCTION (this);
	// RDF: method currently supports Downlink control only!
	switch (m_state)
	{
		case TX:
			NS_FATAL_ERROR ("Cannot RX while TX: according to FDD channel access, the physical layer for transmission cannot be used for reception");
			break;
		case RX_DATA:
			NS_FATAL_ERROR ("Cannot RX data while receiving control");
			break;
		case RX_CTRL:
		case IDLE:
		{
			// the behavior is similar when we're IDLE or RX because we can receive more signals
			// simultaneously (e.g., at the eNB).
			Ptr<MmWaveSpectrumSignalParametersDlCtrlFrame> dlCtrlRxParams = \
					DynamicCast<MmWaveSpectrumSignalParametersDlCtrlFrame> (params);
			// To check if we're synchronized to this signal, we check for the CellId
			uint16_t cellId = 0;
			if (dlCtrlRxParams != 0)
			{
				cellId = dlCtrlRxParams->cellId;
			}
			else
			{
				NS_LOG_ERROR ("SpectrumSignalParameters type not supported");
			}
			// check presence of PSS for UE measuerements
			/*if (dlCtrlRxParams->pss == true)
			{
				SpectrumValue pssPsd = *params->psd;
				if (!m_phyRxPssCallback.IsNull ())
				{
					m_phyRxPssCallback (cellId, params->psd);
				}
			}*/
			if (cellId  == m_cellId)
			{
				if(m_state == RX_CTRL)
				{
					Ptr<mmwave::MmWaveUeNetDevice> ueRx =
									DynamicCast<mmwave::MmWaveUeNetDevice> (GetDevice ());
					Ptr<McUeNetDevice> rxMcUe =
									DynamicCast<McUeNetDevice> (GetDevice ());
					if (ueRx || rxMcUe)
					{
						NS_FATAL_ERROR ("UE already receiving control data from serving cell");
					}
					NS_ASSERT ((m_firstRxStart == Simulator::Now ())
					           && (m_firstRxDuration == params->duration));
				}
				NS_LOG_LOGIC (this << " synchronized with this signal (cellId=" << cellId << ")");
				if (m_state == IDLE)
				{
					// first transmission, i.e., we're IDLE and we start RX
					NS_ASSERT (m_rxControlMessageList.empty ());
					m_firstRxStart = Simulator::Now ();
					m_firstRxDuration = params->duration;
					NS_LOG_LOGIC (this << " scheduling EndRx with delay " << params->duration);
					// store the DCIs
					m_rxControlMessageList = dlCtrlRxParams->ctrlMsgList;
					m_endRxDlCtrlEvent = Simulator::Schedule (params->duration, &MmWaveSpectrumPhy::EndRxCtrl, this);
					ChangeState (RX_CTRL);
				}
				else
				{
					m_rxControlMessageList.insert (m_rxControlMessageList.end (), dlCtrlRxParams->ctrlMsgList.begin (), dlCtrlRxParams->ctrlMsgList.end ());
				}

			}
			break;
	}
	default:
	{
	    NS_FATAL_ERROR ("unknown state");
	    break;
	}
	}
}

void
MmWaveSpectrumPhy::EndRxData ()
{
	m_interferenceData->EndRx();

	double sinrAvg = Sum(m_sinrPerceived)/(m_sinrPerceived.GetSpectrumModel()->GetNumBands());
	double sinrMin = 99999999999;
	for (Values::const_iterator it = m_sinrPerceived.ConstValuesBegin (); it != m_sinrPerceived.ConstValuesEnd (); it++)
	{
		if (*it < sinrMin)
		{
			sinrMin = *it;
		}
	}

	Ptr<MmWaveEnbNetDevice> enbRx = DynamicCast<MmWaveEnbNetDevice> (GetDevice ());
	Ptr<mmwave::MmWaveUeNetDevice> ueRx = DynamicCast<mmwave::MmWaveUeNetDevice> (GetDevice ());
	Ptr<McUeNetDevice> rxMcUe = DynamicCast<McUeNetDevice> (GetDevice ());

	NS_ASSERT(m_state = RX_DATA);
	ExpectedTbMap_t::iterator itTb = m_expectedTbs.begin ();
	while (itTb != m_expectedTbs.end ())
	{
		if ((m_dataErrorModelEnabled)&&(m_rxPacketBurstList.size ()>0))
		{
			MmWaveHarqProcessInfoList_t harqInfoList;
			uint8_t rv = 0;
			if (itTb->second.ndi == 0)
			{
				// TB retxed: retrieve HARQ history
				if (itTb->second.downlink)
				{
					harqInfoList = m_harqPhyModule->GetHarqProcessInfoDl (itTb->first, itTb->second.harqProcessId);
				}
				else
				{
					harqInfoList = m_harqPhyModule->GetHarqProcessInfoUl (itTb->first, itTb->second.harqProcessId);
				}
				if (harqInfoList.size () > 0)
				{
					rv = harqInfoList.back ().m_rv;
				}
			}

			MmWaveTbStats_t tbStats = MmWaveMiErrorModel::GetTbDecodificationStats (m_sinrPerceived,
					itTb->second.rbBitmap, itTb->second.size, itTb->second.mcs, harqInfoList);
			itTb->second.tbler = tbStats.tbler;
			itTb->second.mi = tbStats.miTotal;
			itTb->second.corrupt = m_random->GetValue () > tbStats.tbler ? false : true;
			if (itTb->second.corrupt)
			{
				NS_LOG_INFO (this << " RNTI " << itTb->first << " size " << itTb->second.size << " mcs " << (uint32_t)itTb->second.mcs << " bitmap " << itTb->second.rbBitmap.size () << " rv " << rv << " TBLER " << tbStats.tbler << " corrupted " << itTb->second.corrupt);
			}
		}
		itTb++;
	}

	std::map <uint16_t, DlHarqInfo> harqDlInfoMap;
	for (std::list<Ptr<PacketBurst> >::const_iterator i = m_rxPacketBurstList.begin ();
			i != m_rxPacketBurstList.end (); ++i)
	{
		for (std::list<Ptr<Packet> >::const_iterator j = (*i)->Begin (); j != (*i)->End (); ++j)
		{
			if ((*j)->GetSize () == 0)
			{
				continue;
			}

			LteRadioBearerTag bearerTag;
			if((*j)->PeekPacketTag (bearerTag) == false)
			{
				NS_FATAL_ERROR ("No radio bearer tag found");
			}
			uint16_t rnti = bearerTag.GetRnti ();
			itTb = m_expectedTbs.find (rnti);
			if(itTb != m_expectedTbs.end ())
			{
				if (!itTb->second.corrupt)
				{
					m_phyRxDataEndOkCallback (*j);
				}
				else
				{
					NS_LOG_INFO ("TB failed");
				}

				MmWaveMacPduTag pduTag;
				if((*j)->PeekPacketTag (pduTag) == false)
				{
					NS_FATAL_ERROR ("No radio bearer tag found");
				}

				RxPacketTraceParams traceParams;
				traceParams.m_tbSize = itTb->second.size;
				traceParams.m_cellId = m_cellId;
				traceParams.m_frameNum = pduTag.GetSfn ().m_frameNum;
				traceParams.m_sfNum = pduTag.GetSfn ().m_sfNum;
				traceParams.m_slotNum = pduTag.GetSfn ().m_slotNum;
				traceParams.m_rnti = rnti;
				traceParams.m_mcs = itTb->second.mcs;
				traceParams.m_rv = itTb->second.rv;
				traceParams.m_sinr = sinrAvg;
				traceParams.m_sinrMin = itTb->second.mi;//sinrMin;
				traceParams.m_tbler = itTb->second.tbler;
				traceParams.m_corrupt = itTb->second.corrupt;
				traceParams.m_symStart = itTb->second.symStart;
				traceParams.m_numSym = itTb->second.numSym;
        traceParams.m_ccId = m_componentCarrierId;

				if (enbRx)
				{
          //TODO check if this is correct
					//traceParams.m_cellId = enbRx->GetCellId(); //now m_cellId is set correctly
					m_rxPacketTraceEnb (traceParams);
					 /*FILE* log_file;

					char* fname = (char*)malloc(sizeof(char) * 255);

					memset(fname, 0, sizeof(char) * 255);

					sprintf(fname, "%s-sinr-%llu.txt", m_fileName.c_str(), traceParams.m_cellId);

					log_file = fopen(fname, "a");

					fprintf(log_file, "%lld \t  %f\n", Now().GetMicroSeconds (), 10*log10(traceParams.m_sinr));

					fflush(log_file);

					fclose(log_file);

					if(fname)

					free(fname);

					fname = 0;*/
				}
				else if (ueRx)
				{

					//traceParams.m_cellId = ueRx->GetTargetEnb()->GetCellId(); //now m_cellId is set correctly
					m_rxPacketTraceUe (traceParams);
				}
				else if (rxMcUe)
				{
					Ptr<McUeNetDevice> mcUe = DynamicCast<McUeNetDevice>(ueRx);
					if(mcUe != 0)
					{
						Ptr<MmWaveEnbNetDevice> mmWaveEnb = mcUe->GetMmWaveTargetEnb();
						if (mmWaveEnb != 0)
						{
							//traceParams.m_cellId = mmWaveEnb->GetCellId(); //now m_cellId is set correctly
						}
					}
					m_rxPacketTraceUe (traceParams); // TODO consider a different trace for MC UE
				}

				// send HARQ feedback (if not already done for this TB)
				if (!itTb->second.harqFeedbackSent)
				{
					itTb->second.harqFeedbackSent = true;
					if (!itTb->second.downlink)  // UPLINK TB
					{
						UlHarqInfo harqUlInfo;
						harqUlInfo.m_rnti = rnti;
						harqUlInfo.m_tpc = 0;
						harqUlInfo.m_harqProcessId = itTb->second.harqProcessId;
						harqUlInfo.m_numRetx = itTb->second.rv;
						if (itTb->second.corrupt)
						{
							harqUlInfo.m_receptionStatus = UlHarqInfo::NotOk;
							NS_LOG_DEBUG ("UE" << rnti << " send UL-HARQ-NACK" << " harqId " << (unsigned)itTb->second.harqProcessId <<
														" size " << itTb->second.size << " mcs " << (unsigned)itTb->second.mcs <<
														" mi " << itTb->second.mi << " tbler " << itTb->second.tbler << " SINRavg " << sinrAvg);
							m_harqPhyModule->UpdateUlHarqProcessStatus (rnti, itTb->second.harqProcessId, itTb->second.mi, itTb->second.size, itTb->second.size / EffectiveCodingRate [itTb->second.mcs]);
						}
						else
						{
							harqUlInfo.m_receptionStatus = UlHarqInfo::Ok;
//							NS_LOG_DEBUG ("UE" << rnti << " send UL-HARQ-ACK" << " harqId " << (unsigned)itTb->second.harqProcessId <<
//														" size " << itTb->second.size << " mcs " << (unsigned)itTb->second.mcs <<
//														" mi " << itTb->second.mi << " tbler " << itTb->second.tbler << " SINRavg " << sinrAvg);
							m_harqPhyModule->ResetUlHarqProcessStatus (rnti, itTb->second.harqProcessId);
						}
						if (!m_phyUlHarqFeedbackCallback.IsNull ())
						{
							m_phyUlHarqFeedbackCallback (harqUlInfo);
						}
					}
					else
					{
						std::map <uint16_t, DlHarqInfo>::iterator itHarq = harqDlInfoMap.find (rnti);
						if (itHarq==harqDlInfoMap.end ())
						{
							DlHarqInfo harqDlInfo;
							harqDlInfo.m_harqStatus = DlHarqInfo::NACK;
							harqDlInfo.m_rnti = rnti;
							harqDlInfo.m_harqProcessId = itTb->second.harqProcessId;
							harqDlInfo.m_numRetx = itTb->second.rv;
							if (itTb->second.corrupt)
							{
								harqDlInfo.m_harqStatus = DlHarqInfo::NACK;
								NS_LOG_DEBUG ("UE" << rnti << " send DL-HARQ-NACK" << " harqId " << (unsigned)itTb->second.harqProcessId <<
															" size " << itTb->second.size << " mcs " << (unsigned)itTb->second.mcs <<
															" mi " << itTb->second.mi << " tbler " << itTb->second.tbler << " SINRavg " << sinrAvg);
								m_harqPhyModule->UpdateDlHarqProcessStatus (rnti, itTb->second.harqProcessId, itTb->second.mi, itTb->second.size, itTb->second.size / EffectiveCodingRate [itTb->second.mcs]);
							}
							else
							{
								harqDlInfo.m_harqStatus = DlHarqInfo::ACK;
//								NS_LOG_DEBUG ("UE" << rnti << " send DL-HARQ-ACK" << " harqId " << (unsigned)itTb->second.harqProcessId <<
//															" size " << itTb->second.size << " mcs " << (unsigned)itTb->second.mcs <<
//															" mi " << itTb->second.mi << " tbler " << itTb->second.tbler << " SINRavg " << sinrAvg);
								m_harqPhyModule->ResetDlHarqProcessStatus (rnti, itTb->second.harqProcessId);
							}
							harqDlInfoMap.insert (std::pair <uint16_t, DlHarqInfo> (rnti, harqDlInfo));
						}
						else
						{
							if (itTb->second.corrupt)
							{
								(*itHarq).second.m_harqStatus = DlHarqInfo::NACK;
								NS_LOG_DEBUG ("UE" << rnti << " send DL-HARQ-NACK" << " harqId " << (unsigned)itTb->second.harqProcessId <<
															" size " << itTb->second.size << " mcs " << (unsigned)itTb->second.mcs <<
															" mi " << itTb->second.mi << " tbler " << itTb->second.tbler << " SINRavg " << sinrAvg);
								m_harqPhyModule->UpdateDlHarqProcessStatus (rnti, itTb->second.harqProcessId, itTb->second.mi, itTb->second.size, itTb->second.size / EffectiveCodingRate [itTb->second.mcs]);
							}
							else
							{
								(*itHarq).second.m_harqStatus = DlHarqInfo::ACK;
//								NS_LOG_DEBUG ("UE" << rnti << " send DL-HARQ-ACK" << " harqId " << (unsigned)itTb->second.harqProcessId <<
//								              " size " << itTb->second.size << " mcs " << (unsigned)itTb->second.mcs <<
//								              " mi " << itTb->second.mi << " tbler " << itTb->second.tbler << " SINRavg " << sinrAvg);
								m_harqPhyModule->ResetDlHarqProcessStatus (rnti, itTb->second.harqProcessId);
							}
						}
					} // end if (itTb->second.downlink) HARQ
				} // end if (!itTb->second.harqFeedbackSent)
			}
			else
			{
				//				NS_FATAL_ERROR ("End of the tbMap");
				// Packet is for other device
			}


		}
	}

	// send DL HARQ feedback to LtePhy
	std::map <uint16_t, DlHarqInfo>::iterator itHarq;
	for (itHarq = harqDlInfoMap.begin (); itHarq != harqDlInfoMap.end (); itHarq++)
	{
		if (!m_phyDlHarqFeedbackCallback.IsNull ())
		{
			m_phyDlHarqFeedbackCallback ((*itHarq).second);
		}
	}
	// forward control messages of this frame to MmWavePhy

	if (!m_rxControlMessageList.empty () && !m_phyRxCtrlEndOkCallback.IsNull ())
	{
		m_phyRxCtrlEndOkCallback (m_rxControlMessageList);
	}

	m_state = IDLE;
	m_rxPacketBurstList.clear ();
	m_expectedTbs.clear ();
	m_rxControlMessageList.clear ();
}

void
MmWaveSpectrumPhy::EndRxCtrl ()
{
	NS_ASSERT(m_state = RX_CTRL);

	// control error model not supported
  // forward control messages of this frame to LtePhy
  if (!m_rxControlMessageList.empty ())
    {
      if (!m_phyRxCtrlEndOkCallback.IsNull ())
        {
          m_phyRxCtrlEndOkCallback (m_rxControlMessageList);
        }
    }

	m_state = IDLE;
	m_rxControlMessageList.clear ();
}

bool
MmWaveSpectrumPhy::StartTxDataFrames (Ptr<PacketBurst> pb, std::list<Ptr<MmWaveControlMessage> > ctrlMsgList, Time duration, uint8_t slotInd)
{
	switch (m_state)
	{
	case RX_DATA:
  case RX_CTRL:
		NS_FATAL_ERROR ("cannot TX while RX: Cannot transmit while receiving");
		break;
	case TX:
		NS_FATAL_ERROR ("cannot TX while already Tx: Cannot transmit while a transmission is still on");
		break;
	case IDLE:
	{
		NS_ASSERT(m_txPsd);

		m_state = TX;
		Ptr<MmwaveSpectrumSignalParametersDataFrame> txParams = Create<MmwaveSpectrumSignalParametersDataFrame> ();
		txParams->duration = duration;
		txParams->txPhy = this->GetObject<SpectrumPhy> ();
		txParams->psd = m_txPsd;
		txParams->packetBurst = pb;
		txParams->cellId = m_cellId;
		txParams->ctrlMsgList = ctrlMsgList;
		txParams->slotInd = slotInd;
		txParams->txAntenna = m_antenna;

		//NS_LOG_DEBUG ("ctrlMsgList.size () == " << txParams->ctrlMsgList.size ());

		/* This section is used for trace */
//		Ptr<MmWaveEnbNetDevice> enbTx =
//					DynamicCast<MmWaveEnbNetDevice> (GetDevice ());
//		Ptr<MmWaveUeNetDevice> ueTx =
//					DynamicCast<MmWaveUeNetDevice> (GetDevice ());
//		if (enbTx)
//		{
//			EnbPhyPacketCountParameter traceParam;
//			traceParam.m_noBytes = (txParams->packetBurst)?txParams->packetBurst->GetSize ():0;
//			traceParam.m_cellId = txParams->cellId;
//			traceParam.m_isTx = true;
//			traceParam.m_subframeno = enbTx->GetPhy ()->GetAbsoluteSubframeNo ();
//			m_reportEnbPacketCount (traceParam);
//		}
//		else if (ueTx)
//		{
//			UePhyPacketCountParameter traceParam;
//			traceParam.m_noBytes = (txParams->packetBurst)?txParams->packetBurst->GetSize ():0;
//			traceParam.m_imsi = ueTx->GetImsi ();
//			traceParam.m_isTx = true;
//			traceParam.m_subframeno = ueTx->GetPhy ()->GetAbsoluteSubframeNo ();
//			m_reportUePacketCount (traceParam);
//		}

		m_channel->StartTx (txParams);

		m_endTxEvent = Simulator::Schedule (duration, &MmWaveSpectrumPhy::EndTx, this);
	}
	break;
	default:
		NS_LOG_FUNCTION (this<<"Programming Error. Code should not reach this point");
	}
	return true;
}

bool
MmWaveSpectrumPhy::StartTxDlControlFrames (std::list<Ptr<MmWaveControlMessage> > ctrlMsgList, Time duration)
{
	NS_LOG_LOGIC (this << " state: " << m_state);

	switch (m_state)
	{
  case RX_DATA:
	case RX_CTRL:
		NS_FATAL_ERROR ("cannot TX while RX: Cannot transmit while receiving");
		break;
	case TX:
		NS_FATAL_ERROR ("cannot TX while already Tx: Cannot transmit while a transmission is still on");
		break;
	case IDLE:
	{
		NS_ASSERT(m_txPsd);

		m_state = TX;

		Ptr<MmWaveSpectrumSignalParametersDlCtrlFrame> txParams = Create<MmWaveSpectrumSignalParametersDlCtrlFrame> ();
		txParams->duration = duration;
		txParams->txPhy = GetObject<SpectrumPhy> ();
		txParams->psd = m_txPsd;
		txParams->cellId = m_cellId;
		txParams->pss = true;
		txParams->ctrlMsgList = ctrlMsgList;
		txParams->txAntenna = m_antenna;
		m_channel->StartTx (txParams);
		m_endTxEvent = Simulator::Schedule (duration, &MmWaveSpectrumPhy::EndTx, this);
		//NS_LOG_UNCOND("Tx to cellId " << txParams->cellId << " m_cellID " << m_cellId);
	}
	}
	return false;
}

void
MmWaveSpectrumPhy::EndTx()
{
	NS_ASSERT (m_state == TX);

	m_state = IDLE;
}

Ptr<SpectrumChannel>
MmWaveSpectrumPhy::GetSpectrumChannel ()
{
	return m_channel;
}

void
MmWaveSpectrumPhy::SetCellId (uint16_t cellId)
{
	m_cellId = cellId;
}

void
MmWaveSpectrumPhy::SetComponentCarrierId (uint8_t componentCarrierId)
{
  m_componentCarrierId = componentCarrierId;
}


void
MmWaveSpectrumPhy::AddDataPowerChunkProcessor (Ptr<mmWaveChunkProcessor> p)
{
	m_interferenceData->AddPowerChunkProcessor (p);
}

void
MmWaveSpectrumPhy::AddDataSinrChunkProcessor (Ptr<mmWaveChunkProcessor> p)
{
	m_interferenceData->AddSinrChunkProcessor (p);
}

void
MmWaveSpectrumPhy::UpdateSinrPerceived (const SpectrumValue& sinr)
{
	NS_LOG_FUNCTION (this << sinr);
	m_sinrPerceived = sinr;
}

void
MmWaveSpectrumPhy::SetHarqPhyModule (Ptr<MmWaveHarqPhy> harq)
{
  m_harqPhyModule = harq;
}


}

}
