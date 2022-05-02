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
*                         Sourjya Dutta <sdutta@nyu.edu>
*                         Russell Ford <russell.ford@nyu.edu>
*                         Menglei Zhang <menglei@nyu.edu>
*
* Modified by: Michele Polese <michele.polese@gmail.com>
*                 Dual Connectivity and Handover functionalities
*
* Modified by: Tommaso Zugno <tommasozugno@gmail.com>
*								 Integration of Carrier Aggregation
* 
* Modified by: Argha Sen <arghasen10@gmail.com>
*                 MmWave Radio Energy Model
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
#include <ns3/mmwave-lte-mi-error-model.h>
#include "mmwave-mac-pdu-tag.h"
#include <ns3/phased-array-model.h>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("MmWaveSpectrumPhy");

namespace mmwave {

NS_OBJECT_ENSURE_REGISTERED (MmWaveSpectrumPhy);

MmWaveSpectrumPhy::MmWaveSpectrumPhy ()
  : m_cellId (0),
    m_state (IDLE),
    m_componentCarrierId (0)
{
  m_interferenceData = CreateObject<mmWaveInterference> ();
  m_random = CreateObject<UniformRandomVariable> ();
  m_random->SetAttribute ("Min", DoubleValue (0.0));
  m_random->SetAttribute ("Max", DoubleValue (1.0));
}
MmWaveSpectrumPhy::~MmWaveSpectrumPhy ()
{

}

TypeId
MmWaveSpectrumPhy::GetTypeId (void)
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
    .AddTraceSource ("State",
                     "State Value to trace",
                     MakeTraceSourceAccessor (&MmWaveSpectrumPhy::m_intState),
                     "ns3::TracedValueCallback::Int32")
    .AddAttribute ("DataErrorModelEnabled",
                   "Activate/Deactivate the error model of data (TBs of PDSCH and PUSCH) [by default is active].",
                   BooleanValue (true),
                   MakeBooleanAccessor (&MmWaveSpectrumPhy::m_dataErrorModelEnabled),
                   MakeBooleanChecker ())
    .AddAttribute ("ErrorModelType",
                   "Type of the Error Model to apply to TBs of PDSCH and PUSCH",
                    TypeIdValue (MmWaveLteMiErrorModel::GetTypeId ()),
                    MakeTypeIdAccessor (&MmWaveSpectrumPhy::SetErrorModelType,
                                        &MmWaveSpectrumPhy::GetErrorModelType),
                    MakeTypeIdChecker ())
    .AddAttribute ("FileName",
                   "file name",
                   StringValue ("no"),
                   MakeStringAccessor (&MmWaveSpectrumPhy::m_fileName),
                   MakeStringChecker ())
  ;

  return tid;
}
void
MmWaveSpectrumPhy::DoDispose ()
{

}

void
MmWaveSpectrumPhy::Reset ()
{
  NS_LOG_FUNCTION (this);
  m_cellId = 0;
  ChangeState (IDLE);
  m_endTxEvent.Cancel ();
  m_endRxDataEvent.Cancel ();
  m_endRxDlCtrlEvent.Cancel ();
  m_rxControlMessageList.clear ();
  m_transportBlocks.clear ();
  m_rxPacketBurstList.clear ();
  //m_txPacketBurst = 0;
  //m_rxSpectrumModel = 0;
}

void
MmWaveSpectrumPhy::ResetSpectrumModel ()
{
  m_rxSpectrumModel = 0;
}

void
MmWaveSpectrumPhy::SetDevice (Ptr<NetDevice> d)
{
  m_device = d;

  Ptr<MmWaveEnbNetDevice> enbNetDev = DynamicCast<MmWaveEnbNetDevice> (GetDevice ());

  // TODO m_isEnb is never used
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
MmWaveSpectrumPhy::GetDevice () const
{
  return m_device;
}

void
MmWaveSpectrumPhy::SetMobility (Ptr<MobilityModel> m)
{
  m_mobility = m;
}

Ptr<MobilityModel>
MmWaveSpectrumPhy::GetMobility () const
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

void
MmWaveSpectrumPhy::SetErrorModelType (TypeId errorModelType)
{
  m_errorModelType = errorModelType;
}

Ptr<AntennaModel>
MmWaveSpectrumPhy::GetRxAntenna () const
{
  // NOTE the antenna gain is implicitly taken into account in the channel
  // model classes
  return 0;
}

void
MmWaveSpectrumPhy::SetBeamformingModel (Ptr<MmWaveBeamformingModel> bfModule)
{
  NS_LOG_FUNCTION (this);

  m_beamforming = bfModule;
}

Ptr<MmWaveBeamformingModel>
MmWaveSpectrumPhy::GetBeamformingModel () const
{
  NS_LOG_FUNCTION (this);

  return m_beamforming;
}

void
MmWaveSpectrumPhy::ChangeState (State newState)
{
  NS_LOG_LOGIC (this << " state: " << m_state << " -> " << newState);
  m_state = newState;
  m_intState = newState;
}


void
MmWaveSpectrumPhy::SetNoisePowerSpectralDensity (Ptr<const SpectrumValue> noisePsd)
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
MmWaveSpectrumPhy::AddExpectedTb (uint16_t rnti, uint8_t ndi, uint32_t tbSize, uint8_t mcs,
                                  std::vector<int> chunkMap, uint8_t harqId, uint8_t rv, bool downlink,
                                  uint8_t symStart, uint8_t numSym)
{
  auto it = m_transportBlocks.find (rnti);
  if (it != m_transportBlocks.end ())
    {
      m_transportBlocks.erase (it);
    }
  // insert new entry
  //ExpectedTbInfo_t tbInfo = {ndi, tbSize, mcs, chunkMap, harqId, rv, 0.0, downlink, false, false, 0};
  ExpectedTb expTbInfo {ndi, tbSize, mcs, chunkMap, harqId, rv, downlink, symStart, numSym};
  m_transportBlocks.emplace (std::make_pair(rnti, TransportBlockInfo (expTbInfo)));
}

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
MmWaveSpectrumPhy::ConfigureBeamforming (Ptr<NetDevice> device)
{
  NS_LOG_FUNCTION (this << device);
  Ptr<PhasedArrayModel> antenna;

  // test if device is a MmWaveNetDevice
  Ptr<MmWaveNetDevice> mmNetDevice = DynamicCast<MmWaveNetDevice> (device);
  if (mmNetDevice)
    {
      antenna = mmNetDevice->GetAntenna (m_componentCarrierId);
    }

  // test if device is a MmWaveNetDevice
  Ptr<McUeNetDevice> mcUeNetDevice = DynamicCast<McUeNetDevice> (device);
  if (mcUeNetDevice)
    {
      antenna = mcUeNetDevice->GetAntenna (m_componentCarrierId);
    }
  
  m_beamforming->SetBeamformingVectorForDevice (device, antenna);
}

void
MmWaveSpectrumPhy::StartRx (Ptr<SpectrumSignalParameters> params)
{

  NS_LOG_FUNCTION (this);

  // TODO the code below avoids to receive a signal from devices of the
  // same type.
  // In principle, this should be allowed and the signal should be considered
  // as interferer.
  // CASE 1: BS is transmitting and another BS is receiving
  // No need to do this check, the packet will be discarded since the cell ids
  // are different
  // CASE 2: UE is transmitting and another UE is receiving, both attached to
  // the same cell
  //

  Ptr<MmWaveEnbNetDevice> enbTx = DynamicCast<MmWaveEnbNetDevice> (params->txPhy->GetDevice ());
  Ptr<MmWaveEnbNetDevice> enbRx = DynamicCast<MmWaveEnbNetDevice> (GetDevice ());
  if ((enbTx != 0 && enbRx != 0) || (enbTx == 0 && enbRx == 0))
    {
      NS_LOG_INFO ("BS to BS or UE to UE transmission neglected.");
      return;
    }

  // check if the received signal is mmWave DATA or CTRL
  Ptr<MmwaveSpectrumSignalParametersDataFrame> mmwaveDataRxParams = DynamicCast<MmwaveSpectrumSignalParametersDataFrame> (params);
  Ptr<MmWaveSpectrumSignalParametersDlCtrlFrame> mmwaveDlCtrlRxParams = DynamicCast<MmWaveSpectrumSignalParametersDlCtrlFrame> (params);

  if (mmwaveDataRxParams != 0)
    {
      // mmWave DATA case

      // TODO in case our device is a UE, the code below checks if the UePhy is
      // allowed to receive a signal.
      // This should be done inside the UePhy class as a state machine

      bool isAllocated = true;
      Ptr<MmWaveUeNetDevice> ueRx = DynamicCast<MmWaveUeNetDevice> (GetDevice ());
      Ptr<McUeNetDevice> rxMcUe = DynamicCast<McUeNetDevice> (GetDevice ());


      if ((ueRx != 0) && (ueRx->GetPhy (m_componentCarrierId)->IsReceptionEnabled () == false))
        {               // if the first cast is 0 (the device is MC) then this if will not be executed
          isAllocated = false;
        }
      else if ((rxMcUe != 0) && (rxMcUe->GetMmWavePhy (m_componentCarrierId)->IsReceptionEnabled () == false))
        {               // this is executed if the device is MC and is transmitting
          isAllocated = false;
        }

      NS_LOG_DEBUG("Now: " << Simulator::Now().GetSeconds() << " enb? " << (enbRx != 0)
        << " ue? " << (ueRx != 0) << " "
        << isAllocated);

      if (isAllocated)
        {

          // add the signal to the sum of all the signals received in this time instant
          m_interferenceData->AddSignal (mmwaveDataRxParams->psd, mmwaveDataRxParams->duration);

          // check if the signal comes from a device connected to this cell
          if (mmwaveDataRxParams->cellId == m_cellId)
          {
            StartRxData (mmwaveDataRxParams);
          }
          else
          {
            NS_LOG_LOGIC (this << " not in sync with this signal (cellId=" << mmwaveDataRxParams->cellId  << ", m_cellId=" << m_cellId << ")");
          }
        }
    }
  else if (mmwaveDlCtrlRxParams != 0)
    {
      // for CTRL messages interference is not considered
      StartRxCtrl (mmwaveDlCtrlRxParams);
    }
  else
  {
    // other type of signal
    m_interferenceData->AddSignal (params->psd, params->duration);
  }
}

void
MmWaveSpectrumPhy::StartRxData (Ptr<MmwaveSpectrumSignalParametersDataFrame> params)
{

  NS_LOG_FUNCTION (this);

  switch (m_state)
    {
      case TX:
        NS_FATAL_ERROR ("Cannot receive while transmitting");
        break;

      case RX_CTRL:
        NS_FATAL_ERROR ("Cannot receive control in data period");
        break;

      case RX_DATA:
      case IDLE:
        {
          // this is a useful signal
          m_interferenceData->StartRx (params->psd);

          if (m_rxPacketBurstList.empty ())
            {
              NS_ASSERT (m_state == IDLE);
              // first transmission, i.e., we're IDLE and we start RX
              m_firstRxStart = Simulator::Now ();
              m_firstRxDuration = params->duration;
              NS_LOG_LOGIC (this << " scheduling EndRx with delay " << params->duration.GetSeconds () << "s");

              m_endRxDataEvent = Simulator::Schedule (params->duration, &MmWaveSpectrumPhy::EndRxData, this);

              ChangeState (RX_DATA);
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


          if (params->packetBurst && !params->packetBurst->GetPackets ().empty ())
            {
              m_rxPacketBurstList.push_back (params->packetBurst);
            }

          m_rxControlMessageList.insert (m_rxControlMessageList.end (), params->ctrlMsgList.begin (), params->ctrlMsgList.end ());

          NS_LOG_LOGIC (this << " numSimultaneousRxEvents = " << m_rxPacketBurstList.size ());
        }
        break;

      default:
        NS_FATAL_ERROR ("Programming Error: Unknown State");
    }
}

void
MmWaveSpectrumPhy::StartRxCtrl (Ptr<MmWaveSpectrumSignalParametersDlCtrlFrame> dlCtrlRxParams)
{
  NS_LOG_FUNCTION (this);
  // RDF: method currently supports Downlink control only! // TODO is this true??
  switch (m_state)
    {
      case TX:
        NS_FATAL_ERROR ("Cannot RX while TX: according to FDD channel access, the physical layer for transmission cannot be used for reception");
        break;

      case RX_DATA:
        NS_FATAL_ERROR ("Cannot RX data while receiving control");
        break;

      case RX_CTRL:
        {
          // To check if we're synchronized to this signal, we check for the CellId
          if (dlCtrlRxParams->cellId  == m_cellId)
            {
              NS_LOG_LOGIC (this << " synchronized with this signal (cellId=" << m_cellId << ")");

              Ptr<MmWaveUeNetDevice> ueRx = DynamicCast<MmWaveUeNetDevice> (GetDevice ());
              Ptr<McUeNetDevice> rxMcUe = DynamicCast<McUeNetDevice> (GetDevice ());
              if (ueRx || rxMcUe)
                {
                  NS_FATAL_ERROR ("UE already receiving control data from serving cell");
                }
              NS_ASSERT ((m_firstRxStart == Simulator::Now ()) && (m_firstRxDuration == dlCtrlRxParams->duration));

              m_rxControlMessageList.insert (m_rxControlMessageList.end (), dlCtrlRxParams->ctrlMsgList.begin (), dlCtrlRxParams->ctrlMsgList.end ());
            }
          else
            {
              NS_LOG_LOGIC (this << " not in sync with this signal (cellId=" << dlCtrlRxParams->cellId  << ", m_cellId=" << m_cellId << ")");
            }
          break;
        }

      case IDLE:
        {
          // the behavior is similar when we're IDLE or RX because we can receive more signals
          // simultaneously (e.g., at the eNB).

          // To check if we're synchronized to this signal, we check for the CellId
          if (dlCtrlRxParams->cellId  == m_cellId)
            {
              NS_LOG_LOGIC (this << " synchronized with this signal (cellId=" << m_cellId << ")");

              // first transmission, i.e., we're IDLE and we start RX
              NS_ASSERT (m_rxControlMessageList.empty ());
              m_firstRxStart = Simulator::Now ();
              m_firstRxDuration = dlCtrlRxParams->duration;
              NS_LOG_LOGIC (this << " scheduling EndRx with delay " << dlCtrlRxParams->duration);

              // store the DCIs
              m_rxControlMessageList = dlCtrlRxParams->ctrlMsgList;
              m_endRxDlCtrlEvent = Simulator::Schedule (dlCtrlRxParams->duration, &MmWaveSpectrumPhy::EndRxCtrl, this);
              ChangeState (RX_CTRL);
            }
          else
            {
              NS_LOG_LOGIC (this << " not in sync with this signal (cellId=" << dlCtrlRxParams->cellId  << ", m_cellId=" << m_cellId << ")");
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
  NS_ASSERT (m_state = RX_DATA);

  m_interferenceData->EndRx (); // trigger the SINR computation

  // check if the transmissions succeeded or failed
  auto itTb = m_transportBlocks.begin ();
  while (itTb != m_transportBlocks.end ())
    {
        // compute the average SINR
      itTb->second.m_sinrAvg = Sum (m_sinrPerceived) / (m_sinrPerceived.GetSpectrumModel ()->GetNumBands ());
      itTb->second.m_sinrMin = MmWaveSpectrumPhy::Min (m_sinrPerceived);
      NS_LOG_DEBUG ("m_sinrPerceived=" << m_sinrPerceived <<
                    ", sinrMin=" << itTb->second.m_sinrMin << 
                    ", sinrAvg=" << itTb->second.m_sinrAvg << 
                    ", Avg SINR dB=" << 10*std::log10(itTb->second.m_sinrAvg) <<
                    ", GetNumBands=" << m_sinrPerceived.GetSpectrumModel ()->GetNumBands ());

      if ((m_dataErrorModelEnabled) && (m_rxPacketBurstList.size () > 0))
        {
          // Retrieve HARQ history
          std::function <const MmWaveErrorModel::MmWaveErrorModelHistory & (uint16_t, uint8_t)> RetrieveHistory;

          if (itTb->second.m_expected.m_isDownlink)
            {
              RetrieveHistory = std::bind (&MmWaveHarqPhy::GetHarqProcessInfoDl, m_harqPhyModule,
                                          std::placeholders::_1, std::placeholders::_2);
            }
          else
            {
              RetrieveHistory = std::bind (&MmWaveHarqPhy::GetHarqProcessInfoUl, m_harqPhyModule,
                                          std::placeholders::_1, std::placeholders::_2);
            }

          const MmWaveErrorModel::MmWaveErrorModelHistory & harqInfoList = RetrieveHistory (itTb->first, 
                                                                itTb->second.m_expected.m_harqProcessId);

          // Obtain pointer to the specific error model used
          NS_ABORT_MSG_IF (!m_errorModelType.IsChildOf (MmWaveErrorModel::GetTypeId ()),
                           "The error model must be a subclass of MmWaveErrorModel!");
          ObjectFactory emFactory;
          emFactory.SetTypeId (m_errorModelType);
          Ptr<MmWaveErrorModel> em = DynamicCast<MmWaveErrorModel> (emFactory.Create ());

          // Check whether the TB is corrupted or not, update TB info accordingly
          itTb->second.m_outputOfEM = em->GetTbDecodificationStats (m_sinrPerceived, 
                                                                    itTb->second.m_expected.m_rbBitmap, 
                                                                    itTb->second.m_expected.m_tbSize, 
                                                                    itTb->second.m_expected.m_mcs, 
                                                                    harqInfoList);
          itTb->second.m_isCorrupted = m_random->GetValue () > itTb->second.m_outputOfEM->m_tbler ? false : true;

          if (itTb->second.m_isCorrupted)
            {
              NS_LOG_INFO (" RNTI " << itTb->first << 
                           " size " << itTb->second.m_expected.m_tbSize << 
                           " mcs " << +itTb->second.m_expected.m_mcs << 
                           " bitmap " << itTb->second.m_expected.m_rbBitmap.size () << 
                           " rv "<< +itTb->second.m_expected.m_rv << 
                           " TBLER " << itTb->second.m_outputOfEM->m_tbler << 
                           " corrupted " << itTb->second.m_isCorrupted);
            }
        }
      itTb++;
    }

  // fire the traces and send the ACKs/NACKs
  std::map <uint16_t, DlHarqInfo> harqDlInfoMap;
  for (auto packetBurst : m_rxPacketBurstList)
    {
      for (auto packet : packetBurst->GetPackets ())
        {
          if (packet->GetSize () == 0)
            {
              continue;
            }

          LteRadioBearerTag bearerTag;
          if (packet->PeekPacketTag (bearerTag) == false)
            {
              NS_FATAL_ERROR ("No radio bearer tag found");
            }
          uint16_t rnti = bearerTag.GetRnti ();
          itTb = m_transportBlocks.find (rnti);
          if (itTb != m_transportBlocks.end ())
            {
              if (!itTb->second.m_isCorrupted)
                {
                  m_phyRxDataEndOkCallback (packet);
                }
              else
                {
                  NS_LOG_INFO ("TB failed");
                }

              MmWaveMacPduTag pduTag;
              if (packet->PeekPacketTag (pduTag) == false)
                {
                  NS_FATAL_ERROR ("No radio bearer tag found");
                }

              RxPacketTraceParams traceParams;
              traceParams.m_tbSize = itTb->second.m_expected.m_tbSize;
              traceParams.m_cellId = m_cellId;
              traceParams.m_frameNum = pduTag.GetSfn ().m_frameNum;
              traceParams.m_sfNum = pduTag.GetSfn ().m_sfNum;
              traceParams.m_slotNum = pduTag.GetSfn ().m_slotNum;
              traceParams.m_rnti = rnti;
              traceParams.m_mcs = itTb->second.m_expected.m_mcs;
              traceParams.m_rv = itTb->second.m_expected.m_rv;
              traceParams.m_sinr = itTb->second.m_sinrAvg;
              traceParams.m_sinrMin = itTb->second.m_sinrMin;
              traceParams.m_tbler = itTb->second.m_outputOfEM->m_tbler;
              traceParams.m_corrupt = itTb->second.m_isCorrupted;
              traceParams.m_symStart = itTb->second.m_expected.m_symStart;
              traceParams.m_numSym = itTb->second.m_expected.m_numSym;
              traceParams.m_ccId = m_componentCarrierId;

              if (!itTb->second.m_expected.m_isDownlink)
                {
                  // eNB received an uplink TB
                  m_rxPacketTraceEnb (traceParams);
                }
              else
                {
                  // UE received a downlink TB
                  m_rxPacketTraceUe (traceParams);
                }

              // send HARQ feedback (if not already done for this TB)
              if (!itTb->second.m_harqFeedbackSent)
                {
                  itTb->second.m_harqFeedbackSent = true;
                  if (!itTb->second.m_expected.m_isDownlink) // UPLINK TB
                    {
                      UlHarqInfo harqUlInfo;
                      harqUlInfo.m_rnti = rnti;
                      harqUlInfo.m_harqProcessId = itTb->second.m_expected.m_harqProcessId;
                      harqUlInfo.m_numRetx = itTb->second.m_expected.m_rv;
                      if (itTb->second.m_isCorrupted)
                        {
                          harqUlInfo.m_receptionStatus = UlHarqInfo::NotOk;
                          NS_LOG_DEBUG ("UE" << rnti <<
                                        " send UL-HARQ-NACK" << 
                                        " harqId " << +itTb->second.m_expected.m_harqProcessId << 
                                        " size " << itTb->second.m_expected.m_tbSize << 
                                        " mcs " << +itTb->second.m_expected.m_mcs << 
                                        " tbler " << itTb->second.m_outputOfEM->m_tbler << 
                                        " sinrAvg " << itTb->second.m_sinrAvg);
                        }
                      else
                        {
                          harqUlInfo.m_receptionStatus = UlHarqInfo::Ok;
                          NS_LOG_DEBUG ("UE" << rnti <<
                                        " send UL-HARQ-ACK" << 
                                        " harqId " << +itTb->second.m_expected.m_harqProcessId << 
                                        " size " << itTb->second.m_expected.m_tbSize << 
                                        " mcs " << +itTb->second.m_expected.m_mcs << 
                                        " tbler " << itTb->second.m_outputOfEM->m_tbler << 
                                        " sinrAvg " << itTb->second.m_sinrAvg);
                        }

                      if (!m_phyUlHarqFeedbackCallback.IsNull ())
                        {
                          m_phyUlHarqFeedbackCallback (harqUlInfo);
                        }

                      // Update HARQ process info accordingly
                      if (!itTb->second.m_isCorrupted || itTb->second.m_expected.m_rv == 3)
                        {
                          m_harqPhyModule->ResetUlHarqProcessStatus (rnti, itTb->second.m_expected.m_harqProcessId);
                        }
                      else
                        {
                          m_harqPhyModule->UpdateUlHarqProcessStatus (rnti, itTb->second.m_expected.m_harqProcessId, 
                                                                      itTb->second.m_outputOfEM);
                        }
                    }
                  else
                    { // DOWNLIK TB
                      DlHarqInfo harqDlInfo;
                      harqDlInfo.m_rnti = rnti;
                      harqDlInfo.m_harqProcessId = itTb->second.m_expected.m_harqProcessId;
                      harqDlInfo.m_numRetx = itTb->second.m_expected.m_rv;

                      if (itTb->second.m_isCorrupted)
                        {
                          NS_LOG_DEBUG ("UE" << rnti <<
                                       " send DL-HARQ-NACK" << 
                                       " harqId " << +itTb->second.m_expected.m_harqProcessId << 
                                       " size " << itTb->second.m_expected.m_tbSize << 
                                       " mcs " << +itTb->second.m_expected.m_mcs << 
                                       " tbler " << itTb->second.m_outputOfEM->m_tbler << 
                                       " sinrAvg " << itTb->second.m_sinrAvg);
                          harqDlInfo.m_harqStatus = DlHarqInfo::NACK;
                        }
                      else
                        {
                          NS_LOG_DEBUG ("UE" << rnti <<
                                       " send DL-HARQ-NACK" << 
                                       " harqId " << +itTb->second.m_expected.m_harqProcessId << 
                                       " size " << itTb->second.m_expected.m_tbSize << 
                                       " mcs " << +itTb->second.m_expected.m_mcs << 
                                       " tbler " << itTb->second.m_outputOfEM->m_tbler << 
                                       " sinrAvg " << itTb->second.m_sinrAvg);
                          harqDlInfo.m_harqStatus = DlHarqInfo::ACK;
                        }

                        NS_ASSERT (harqDlInfoMap.find (rnti) == harqDlInfoMap.end ());
                        harqDlInfoMap.insert(std::make_pair (rnti, harqDlInfo));

                        if (!m_phyDlHarqFeedbackCallback.IsNull ())
                          {
                            m_phyDlHarqFeedbackCallback (harqDlInfo);
                          }

                        // Arrange the history
                        if (!itTb->second.m_isCorrupted || itTb->second.m_expected.m_rv == 3)
                          {
                            m_harqPhyModule->ResetDlHarqProcessStatus (rnti, itTb->second.m_expected.m_harqProcessId);
                          }
                        else
                          {
                            m_harqPhyModule->UpdateDlHarqProcessStatus (rnti, itTb->second.m_expected.m_harqProcessId,
                                                                        itTb->second.m_outputOfEM);
                          }
                    }
                }
            }
          else
            {
              // TODO what to do here?
              // NS_FATAL_ERROR ("End of the tbMap");
              // Packet is for other device
              continue;
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

  ChangeState (IDLE);
  m_rxPacketBurstList.clear ();
  m_transportBlocks.clear ();
  m_rxControlMessageList.clear ();
}

void
MmWaveSpectrumPhy::EndRxCtrl ()
{
  NS_ASSERT (m_state = RX_CTRL);

  // control error model not supported
  // forward control messages of this frame to LtePhy
  if (!m_rxControlMessageList.empty ())
    {
      if (!m_phyRxCtrlEndOkCallback.IsNull ())
        {
          m_phyRxCtrlEndOkCallback (m_rxControlMessageList);
        }
    }

  ChangeState (IDLE);
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
          NS_ASSERT (m_txPsd);
          Ptr<MmwaveSpectrumSignalParametersDataFrame> txParams = Create<MmwaveSpectrumSignalParametersDataFrame> ();
          txParams->duration = duration;
          txParams->txPhy = this->GetObject<SpectrumPhy> ();
          txParams->psd = m_txPsd;
          txParams->packetBurst = pb;
          txParams->cellId = m_cellId;
          txParams->ctrlMsgList = ctrlMsgList;
          txParams->slotInd = slotInd;
          txParams->txAntenna = GetRxAntenna (); // TODO do we need to know the antenna?
          NS_LOG_DEBUG(Simulator::Now().GetSeconds() << " StartTxDataFrames " << txParams << " cellId " << m_cellId
            << " duration " << (Simulator::Now() + duration).GetSeconds()
            << " slotInd " << (uint16_t)slotInd);

          m_channel->StartTx (txParams);

          ChangeState (TX);

          m_endTxEvent = Simulator::Schedule (duration, &MmWaveSpectrumPhy::EndTx, this);
        }
        break;

      default:
        NS_LOG_FUNCTION (this << "Programming Error. Code should not reach this point");
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
          NS_ASSERT (m_txPsd);

          Ptr<MmWaveSpectrumSignalParametersDlCtrlFrame> txParams = Create<MmWaveSpectrumSignalParametersDlCtrlFrame> ();
          txParams->duration = duration;
          txParams->txPhy = GetObject<SpectrumPhy> ();
          txParams->psd = m_txPsd;
          txParams->cellId = m_cellId;
          txParams->pss = true;
          txParams->ctrlMsgList = ctrlMsgList;
          txParams->txAntenna = GetRxAntenna (); // TODO do we need to know the antenna?

          m_channel->StartTx (txParams);

          ChangeState (TX);

          m_endTxEvent = Simulator::Schedule (duration, &MmWaveSpectrumPhy::EndTx, this);
      }
      //TODO is the default case needed here ??
    }
  return false;
}

void
MmWaveSpectrumPhy::EndTx ()
{
  NS_ASSERT (m_state == TX);

  ChangeState (IDLE);
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

double 
MmWaveSpectrumPhy::Min (const SpectrumValue& specVal)
{
  auto minIt {std::min_element (specVal.ConstValuesBegin (), specVal.ConstValuesEnd ())};
  return *minIt;
}

TypeId
MmWaveSpectrumPhy::GetErrorModelType () const
{
  NS_LOG_FUNCTION (this);
  return m_errorModelType;
}

} // end namespace mmwave
} // end namespace ns3
