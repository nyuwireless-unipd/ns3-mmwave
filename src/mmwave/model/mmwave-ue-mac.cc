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
 *                Dual Connectivity and Handover functionalities
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                               Integration of Carrier Aggregation
 */

#include "mmwave-ue-mac.h"

#include "mmwave-phy-sap.h"

#include <ns3/log.h>
#include <ns3/lte-rlc.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWaveUeMac");

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWaveUeMac);

uint8_t MmWaveUeMac::g_raPreambleId = 0;

///////////////////////////////////////////////////////////
// SAP forwarders
///////////////////////////////////////////////////////////

class UeMemberMmWaveUeCmacSapProvider : public LteUeCmacSapProvider
{
  public:
    UeMemberMmWaveUeCmacSapProvider(MmWaveUeMac* mac);

    // inherited from LteUeCmacSapProvider
    virtual void ConfigureRach(RachConfig rc);
    virtual void StartContentionBasedRandomAccessProcedure();
    virtual void StartNonContentionBasedRandomAccessProcedure(uint16_t rnti,
                                                              uint8_t preambleId,
                                                              uint8_t prachMask);
    virtual void SetRnti(uint16_t rnti);
    virtual void AddLc(uint8_t lcId,
                       LteUeCmacSapProvider::LogicalChannelConfig lcConfig,
                       LteMacSapUser* msu);
    virtual void RemoveLc(uint8_t lcId);
    virtual void Reset();

  private:
    MmWaveUeMac* m_mac;
};

UeMemberMmWaveUeCmacSapProvider::UeMemberMmWaveUeCmacSapProvider(MmWaveUeMac* mac)
    : m_mac(mac)
{
}

void
UeMemberMmWaveUeCmacSapProvider::ConfigureRach(RachConfig rc)
{
    m_mac->DoConfigureRach(rc);
}

void
UeMemberMmWaveUeCmacSapProvider::StartContentionBasedRandomAccessProcedure()
{
    m_mac->DoStartContentionBasedRandomAccessProcedure();
}

void
UeMemberMmWaveUeCmacSapProvider::StartNonContentionBasedRandomAccessProcedure(uint16_t rnti,
                                                                              uint8_t preambleId,
                                                                              uint8_t prachMask)
{
    m_mac->DoStartNonContentionBasedRandomAccessProcedure(rnti, preambleId, prachMask);
}

void
UeMemberMmWaveUeCmacSapProvider::SetRnti(uint16_t rnti)
{
    m_mac->DoSetRnti(rnti);
}

void
UeMemberMmWaveUeCmacSapProvider::AddLc(uint8_t lcId,
                                       LogicalChannelConfig lcConfig,
                                       LteMacSapUser* msu)
{
    m_mac->AddLc(lcId, lcConfig, msu);
}

void
UeMemberMmWaveUeCmacSapProvider::RemoveLc(uint8_t lcid)
{
    m_mac->DoRemoveLc(lcid);
}

void
UeMemberMmWaveUeCmacSapProvider::Reset()
{
    m_mac->DoReset();
}

class UeMemberMmWaveMacSapProvider : public LteMacSapProvider
{
  public:
    UeMemberMmWaveMacSapProvider(MmWaveUeMac* mac);

    // inherited from LteMacSapProvider
    virtual void TransmitPdu(TransmitPduParameters params);
    virtual void ReportBufferStatus(ReportBufferStatusParameters params);

  private:
    MmWaveUeMac* m_mac;
};

UeMemberMmWaveMacSapProvider::UeMemberMmWaveMacSapProvider(MmWaveUeMac* mac)
    : m_mac(mac)
{
}

void
UeMemberMmWaveMacSapProvider::TransmitPdu(TransmitPduParameters params)
{
    m_mac->DoTransmitPdu(params);
}

void
UeMemberMmWaveMacSapProvider::ReportBufferStatus(ReportBufferStatusParameters params)
{
    m_mac->DoReportBufferStatus(params);
}

class MmWaveUePhySapUser;

class MacUeMemberPhySapUser : public MmWaveUePhySapUser
{
  public:
    MacUeMemberPhySapUser(MmWaveUeMac* mac);

    virtual void ReceivePhyPdu(Ptr<Packet> p);

    virtual void ReceiveControlMessage(Ptr<MmWaveControlMessage> msg);

    virtual void SlotIndication(SfnSf sfn);

    virtual void SetConfigurationParameters(Ptr<MmWavePhyMacCommon> params);

    // virtual void NotifyHarqDeliveryFailure (uint8_t harqId);

  private:
    MmWaveUeMac* m_mac;
};

MacUeMemberPhySapUser::MacUeMemberPhySapUser(MmWaveUeMac* mac)
    : m_mac(mac)
{
}

void
MacUeMemberPhySapUser::ReceivePhyPdu(Ptr<Packet> p)
{
    m_mac->DoReceivePhyPdu(p);
}

void
MacUeMemberPhySapUser::ReceiveControlMessage(Ptr<MmWaveControlMessage> msg)
{
    m_mac->DoReceiveControlMessage(msg);
}

void
MacUeMemberPhySapUser::SlotIndication(SfnSf sfn)
{
    m_mac->DoSlotIndication(sfn);
}

void
MacUeMemberPhySapUser::SetConfigurationParameters(Ptr<MmWavePhyMacCommon> params)
{
    m_mac->SetConfigurationParameters(params);
}

// void
// MacUeMemberPhySapUser::NotifyHarqDeliveryFailure (uint8_t harqId)
//{
//  m_mac->DoNotifyHarqDeliveryFailure (harqId);
// }

//-----------------------------------------------------------------------

TypeId
MmWaveUeMac::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveUeMac")
            .SetParent<MmWaveMac>()
            .AddConstructor<MmWaveUeMac>()
            .AddAttribute("UpdateUeSinrEstimatePeriod",
                          "Period (in ms) of reporting of SINR estimate of all the UE",
                          DoubleValue(25.6),
                          MakeDoubleAccessor(&MmWaveUeMac::m_ueUpdateSinrPeriod),
                          MakeDoubleChecker<double>())
            .AddAttribute("InterRatHoCapable",
                          "True if this UE supports hard handover between LTE and MmWave",
                          BooleanValue(false),
                          MakeBooleanAccessor(&MmWaveUeMac::m_interRatHoCapable),
                          MakeBooleanChecker())
            .AddTraceSource("TxMacPacketTraceUe",
                            "Packets transmitted by UeMac",
                            MakeTraceSourceAccessor(&MmWaveUeMac::m_txMacPacketTraceUe),
                            "ns3::UeTxRxPacketCount::TracedCallback")

        ;
    return tid;
}

MmWaveUeMac::MmWaveUeMac(void)
    : m_componentCarrierId(0),
      m_bsrPeriodicity(MicroSeconds(100.0)),
      // ideal behavior
      m_bsrLast(MilliSeconds(0)),
      m_freshUlBsr(false),
      m_raPreambleId(0),
      m_rnti(0),
      m_waitingForRaResponse(true)
{
    NS_LOG_FUNCTION(this);
    m_cmacSapProvider = new UeMemberMmWaveUeCmacSapProvider(this);
    m_macSapProvider = new UeMemberMmWaveMacSapProvider(this);
    m_phySapUser = new MacUeMemberPhySapUser(this);
    m_randomAccessProcedureDelay = CreateObject<UniformRandomVariable>();
}

MmWaveUeMac::~MmWaveUeMac(void)
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveUeMac::DoDispose()
{
    NS_LOG_FUNCTION(this);
    m_miUlHarqProcessesPacket.clear();
    delete m_macSapProvider;
    delete m_cmacSapProvider;
    delete m_phySapUser;
    Object::DoDispose();
}

void
MmWaveUeMac::SetComponentCarrierId(uint8_t index)
{
    m_componentCarrierId = index;
}

void
MmWaveUeMac::SetConfigurationParameters(Ptr<MmWavePhyMacCommon> ptrConfig)
{
    m_phyMacConfig = ptrConfig;

    m_miUlHarqProcessesPacket.clear();
    m_miUlHarqProcessesPacket.resize(m_phyMacConfig->GetNumHarqProcess());
    for (uint8_t i = 0; i < m_miUlHarqProcessesPacket.size(); i++)
    {
        Ptr<PacketBurst> pb = CreateObject<PacketBurst>();
        m_miUlHarqProcessesPacket.at(i).m_pktBurst = pb;
    }
    m_miUlHarqProcessesPacketTimer.clear();
    m_miUlHarqProcessesPacketTimer.resize(m_phyMacConfig->GetNumHarqProcess(), 0);

    m_bsrPeriodicity = MicroSeconds(m_phyMacConfig->GetSymbolsPerSubframe());

    m_randomAccessProcedureDelay->SetAttribute("Min", DoubleValue(0.0));
    m_randomAccessProcedureDelay->SetAttribute("Max", DoubleValue(m_ueUpdateSinrPeriod));
}

Ptr<MmWavePhyMacCommon>
MmWaveUeMac::GetConfigurationParameters(void) const
{
    return m_phyMacConfig;
}

// forwarded from MAC SAP
void
MmWaveUeMac::DoTransmitPdu(LteMacSapProvider::TransmitPduParameters params)
{
    // TB UID passed back along with RLC data as HARQ process ID
    std::map<uint32_t, struct MacPduInfo>::iterator it = m_macPduMap.find(params.harqProcessId);
    if (it == m_macPduMap.end())
    {
        NS_FATAL_ERROR("No MAC PDU storage element found for this TB UID/RNTI");
    }
    else
    {
        MmWaveMacPduTag tag;
        it->second.m_pdu->PeekPacketTag(tag);
        if (tag.GetSfn().m_frameNum < m_frameNum)
        {
            return;
        }
        if (!it->second.m_pdu)
        {
            it->second.m_pdu = params.pdu;
        }
        else
        {
            it->second.m_pdu->AddAtEnd(params.pdu); // append to MAC PDU
        }

        MacSubheader subheader(params.lcid, params.pdu->GetSize());
        it->second.m_macHeader.AddSubheader(subheader); // add RLC PDU sub-header into MAC header
        m_miUlHarqProcessesPacket.at(params.harqProcessId).m_lcidList.push_back(params.lcid);
        if (it->second.m_size <
            (params.pdu->GetSize() + it->second.m_macHeader.GetSerializedSize()))
        {
            NS_FATAL_ERROR("Maximum TB size exceeded");
        }

        if (it->second.m_numRlcPdu <= 1)
        {
            // wait for all RLC PDUs to be received
            it->second.m_pdu->AddHeader(it->second.m_macHeader);

            MmWaveMacPduHeader headerTst;
            it->second.m_pdu->PeekHeader(headerTst);
            if (headerTst.GetSubheaders().size() > 0)
            {
                // NS_LOG_UNCOND(headerTst.GetSubheaders ().at (0).m_size);
            }

            LteRadioBearerTag bearerTag(params.rnti, 0, 0);
            it->second.m_pdu->AddPacketTag(bearerTag);
            m_miUlHarqProcessesPacket.at(params.harqProcessId)
                .m_pktBurst->AddPacket(it->second.m_pdu);
            m_miUlHarqProcessesPacketTimer.at(params.harqProcessId) =
                m_phyMacConfig->GetHarqTimeout();
            // m_harqProcessId = (m_harqProcessId + 1) % m_phyMacConfig->GetHarqTimeout();

            m_txMacPacketTraceUe(params.rnti, m_componentCarrierId, it->second.m_pdu->GetSize());

            m_phySapProvider->SendMacPdu(it->second.m_pdu);
            m_macPduMap.erase(it); // delete map entry
        }
        else
        {
            it->second.m_numRlcPdu--; // decrement count of remaining RLC requests
        }
    }
}

void
MmWaveUeMac::DoReportBufferStatus(LteMacSapProvider::ReportBufferStatusParameters params)
{
    NS_LOG_FUNCTION(this << (uint32_t)params.lcid);

    std::map<uint8_t, LteMacSapProvider::ReportBufferStatusParameters>::iterator it;

    it = m_ulBsrReceived.find(params.lcid);
    if (it != m_ulBsrReceived.end())
    {
        if (params.lcid == 1)
        {
            NS_LOG_INFO("Update entry");
        }

        // update entry
        (*it).second = params;
    }
    else
    {
        if (params.lcid == 1)
        {
            NS_LOG_INFO("Insert entry");
        }
        m_ulBsrReceived.insert(
            std::pair<uint8_t, LteMacSapProvider::ReportBufferStatusParameters>(params.lcid,
                                                                                params));
    }
    m_freshUlBsr = true;
}

void
MmWaveUeMac::SendReportBufferStatus(void)
{
    NS_LOG_FUNCTION(this);

    if (m_rnti == 0)
    {
        NS_LOG_INFO("MAC not initialized, BSR deferred");
        return;
    }

    if (m_ulBsrReceived.size() == 0)
    {
        NS_LOG_INFO("No BSR report to transmit");
        return;
    }
    MacCeElement bsr{m_rnti, MacCeElement::BSR};

    bool send = true;

    // BSR is reported for each LCG
    std::map<uint8_t, LteMacSapProvider::ReportBufferStatusParameters>::iterator it;
    std::vector<uint32_t> queue(4, 0); // one value per each of the 4 LCGs, initialized to 0
    for (it = m_ulBsrReceived.begin(); it != m_ulBsrReceived.end(); it++)
    {
        uint8_t lcid = it->first;
        NS_LOG_INFO("MmWave lcid of BSR " << (uint16_t)lcid << " queue size "
                                          << (*it).second.txQueueSize);

        std::map<uint8_t, LcInfo>::iterator lcInfoMapIt;
        lcInfoMapIt = m_lcInfoMap.find(lcid);
        if (lcInfoMapIt != m_lcInfoMap.end())
        {
            NS_ASSERT_MSG((lcid != 0) || (((*it).second.txQueueSize == 0) &&
                                          ((*it).second.retxQueueSize == 0) &&
                                          ((*it).second.statusPduSize == 0)),
                          "BSR should not be used for LCID 0");
            uint8_t lcg = lcInfoMapIt->second.lcConfig.logicalChannelGroup;
            queue.at(lcg) += ((*it).second.txQueueSize + (*it).second.retxQueueSize +
                              (*it).second.statusPduSize);
        }
        else
        {
            NS_LOG_INFO("lcid not found");
            send = false;
        }
    }

    // FF API says that all 4 LCGs are always present
    bsr.m_macCeValue.m_bufferStatus.push_back(BufferSizeLevelBsr::BufferSize2BsrId(queue.at(0)));
    bsr.m_macCeValue.m_bufferStatus.push_back(BufferSizeLevelBsr::BufferSize2BsrId(queue.at(1)));
    bsr.m_macCeValue.m_bufferStatus.push_back(BufferSizeLevelBsr::BufferSize2BsrId(queue.at(2)));
    bsr.m_macCeValue.m_bufferStatus.push_back(BufferSizeLevelBsr::BufferSize2BsrId(queue.at(3)));

    // create the feedback to eNB
    Ptr<MmWaveBsrMessage> msg = Create<MmWaveBsrMessage>();
    msg->SetBsr(bsr);
    if (send)
    {
        m_phySapProvider->SendControlMessage(msg);
    }
}

void
MmWaveUeMac::SetUeCmacSapUser(LteUeCmacSapUser* s)
{
    m_cmacSapUser = s;
}

LteUeCmacSapProvider*
MmWaveUeMac::GetUeCmacSapProvider(void)
{
    return m_cmacSapProvider;
}

void
MmWaveUeMac::RefreshHarqProcessesPacketBuffer(void)
{
    // NS_LOG_FUNCTION (this);

    for (uint16_t i = 0; i < m_miUlHarqProcessesPacketTimer.size(); i++)
    {
        if (m_miUlHarqProcessesPacketTimer.at(i) == 0)
        {
            if (m_miUlHarqProcessesPacket.at(i).m_pktBurst->GetSize() > 0)
            {
                // timer expired: drop packets in buffer for this process
                NS_LOG_INFO(this << " HARQ Proc Id " << i << " packets buffer expired");
                Ptr<PacketBurst> emptyPb = CreateObject<PacketBurst>();
                m_miUlHarqProcessesPacket.at(i).m_pktBurst = emptyPb;
                m_miUlHarqProcessesPacket.at(i).m_lcidList.clear();
            }
        }
        else
        {
            // m_miUlHarqProcessesPacketTimer.at (i)--;  // ignore HARQ timeout
        }
    }
}

void
MmWaveUeMac::DoSlotIndication(SfnSf sfn)
{
    // NS_LOG_FUNCTION (this);
    m_frameNum = sfn.m_frameNum;
    m_sfNum = sfn.m_sfNum;
    m_slotNum = sfn.m_slotNum;

    RefreshHarqProcessesPacketBuffer();
    if ((Simulator::Now() >= m_bsrLast + m_bsrPeriodicity) && (m_freshUlBsr == true))
    {
        if (m_componentCarrierId == 0) // only the Primary CC sends BSRs
        {
            SendReportBufferStatus();
        }
        m_bsrLast = Simulator::Now();
        m_freshUlBsr = false;
        // m_harqProcessId = (m_harqProcessId + 1) % m_phyMacConfig->GetHarqTimeout();
    }
}

void
MmWaveUeMac::DoReceivePhyPdu(Ptr<Packet> p)
{
    NS_LOG_FUNCTION(this);
    LteRadioBearerTag tag;
    p->RemovePacketTag(tag);
    MmWaveMacPduHeader macHeader;
    p->RemoveHeader(macHeader);
    NS_LOG_INFO("ReceivePdu for rnti " << tag.GetRnti());
    if (tag.GetRnti() == m_rnti) // packet is for the current user
    {
        std::vector<MacSubheader> macSubheaders = macHeader.GetSubheaders();
        // NS_LOG_UNCOND("MmWaveUeMac receive PHY pdu with " << macSubheaders.size() << " pdu");
        uint32_t currPos = 0;
        for (unsigned ipdu = 0; ipdu < macSubheaders.size(); ipdu++)
        {
            if (macSubheaders[ipdu].m_size == 0)
            {
                continue;
            }
            NS_LOG_INFO("It is for lcid " << (uint16_t)macSubheaders[ipdu].m_lcid);
            std::map<uint8_t, LcInfo>::const_iterator it =
                m_lcInfoMap.find(macSubheaders[ipdu].m_lcid);
            // NS_ASSERT_MSG (it != m_lcInfoMap.end (), "received packet with unknown lcid " <<
            // (uint16_t)macSubheaders[ipdu].m_lcid);
            if (it == m_lcInfoMap.end())
            {
                NS_LOG_WARN("received packet with unknown lcid "
                            << (uint16_t)macSubheaders[ipdu].m_lcid);
            }

            if (it != m_lcInfoMap.end())
            {
                Ptr<Packet> rlcPdu;
                if ((p->GetSize() - currPos) < (uint32_t)macSubheaders[ipdu].m_size)
                {
                    NS_LOG_ERROR("Packet size less than specified in MAC header (actual= "
                                 << p->GetSize()
                                 << " header= " << (uint32_t)macSubheaders[ipdu].m_size << ")");
                }
                else if ((p->GetSize() - currPos) > (uint32_t)macSubheaders[ipdu].m_size)
                {
                    NS_LOG_DEBUG("Fragmenting MAC PDU (packet size greater than specified in MAC "
                                 "header (actual= "
                                 << p->GetSize()
                                 << " header= " << (uint32_t)macSubheaders[ipdu].m_size << ")");
                    rlcPdu = p->CreateFragment(currPos, (uint32_t)macSubheaders[ipdu].m_size);
                    currPos += (uint32_t)macSubheaders[ipdu].m_size;

                    LteMacSapUser::ReceivePduParameters rxPduParams;
                    rxPduParams.p = rlcPdu;
                    rxPduParams.rnti = m_rnti;
                    rxPduParams.lcid = macSubheaders[ipdu].m_lcid;
                    it->second.macSapUser->ReceivePdu(rxPduParams);
                }
                else
                {
                    rlcPdu = p->CreateFragment(currPos, p->GetSize() - currPos);
                    currPos = p->GetSize();
                    LteRlcSpecificLteMacSapUser* user =
                        (LteRlcSpecificLteMacSapUser*)it->second.macSapUser;

                    LteMacSapUser::ReceivePduParameters rxPduParams;
                    rxPduParams.p = rlcPdu;
                    rxPduParams.rnti = m_rnti;
                    rxPduParams.lcid = macSubheaders[ipdu].m_lcid;
                    user->ReceivePdu(rxPduParams);
                }
            }
        }
    }
}

// void
// MmWaveUeMac::DoNotifyHarqDeliveryFailure (uint8_t harqId)
//{
//   NS_LOG_FUNCTION (this);
//   for (unsigned i = 0; i < m_miUlHarqProcessesPacket.at (harqId).m_lcidList.size (); i++)
//   {
//       uint8_t lcid = m_miUlHarqProcessesPacket.at (harqId).m_lcidList[i];
//       std::map <uint8_t, LcInfo>::const_iterator it = m_lcInfoMap.find (lcid);
//       NS_ASSERT_MSG (it != m_lcInfoMap.end (), "received packet with unknown lcid");
//       it->second.macSapUser->NotifyHarqDeliveryFailure (harqId);
//   }
// }

void
MmWaveUeMac::RecvRaResponse(BuildRarListElement_s raResponse)
{
    NS_LOG_FUNCTION(this);
    m_waitingForRaResponse = false;
    // m_noRaResponseReceivedEvent.Cancel ();
    NS_LOG_INFO("got RAR for RAPID " << (uint32_t)m_raPreambleId
                                     << ", setting T-C-RNTI = " << raResponse.m_rnti);
    m_rnti = raResponse.m_rnti;
    m_cmacSapUser->SetTemporaryCellRnti(m_rnti);

    m_cmacSapUser->NotifyRandomAccessSuccessful();
    // trigger tx opportunity for Message 3 over LC 0
    // this is needed since Message 3's UL GRANT is in the RAR, not in UL-DCIs
    // const uint8_t lc0Lcid = 0;
    // std::map <uint8_t, LcInfo>::iterator lc0InfoIt = m_lcInfoMap.find (lc0Lcid);
    // NS_ASSERT (lc0InfoIt != m_lcInfoMap.end ());
    // std::map <uint8_t, LteMacSapProvider::ReportBufferStatusParameters>::iterator lc0BsrIt
    //   = m_ulBsrReceived.find (lc0Lcid);
    // if ((lc0BsrIt != m_ulBsrReceived.end ())
    //     && (lc0BsrIt->second.txQueueSize > 0))
    //   {
    //     NS_ASSERT_MSG (raResponse.m_grant.m_tbSize > lc0BsrIt->second.txQueueSize,
    //                    "segmentation of Message 3 is not allowed raResponse.m_grant.m_tbSize " <<
    //                    raResponse.m_grant.m_tbSize
    //                    << " lc0BsrIt->second.txQueueSize " << lc0BsrIt->second.txQueueSize);
    //     lc0InfoIt->second.macSapUser->NotifyTxOpportunity (raResponse.m_grant.m_tbSize, 0, 0);
    //     lc0BsrIt->second.txQueueSize = 0;
    //   }
}

std::map<uint32_t, struct MacPduInfo>::iterator
MmWaveUeMac::AddToMacPduMap(DciInfoElementTdma dci, unsigned activeLcs)
{
    uint8_t slotNum =
        (m_slotNum + m_phyMacConfig->GetUlSchedDelay()) % m_phyMacConfig->GetSlotsPerSubframe();
    uint8_t deltaSubframe =
        (m_slotNum + m_phyMacConfig->GetUlSchedDelay()) / m_phyMacConfig->GetSlotsPerSubframe();
    uint8_t sfNum = (m_sfNum + deltaSubframe) % m_phyMacConfig->GetSubframesPerFrame();
    uint32_t frameNum =
        m_frameNum + ((m_sfNum + deltaSubframe) / m_phyMacConfig->GetSubframesPerFrame());

    NS_ASSERT((slotNum < m_phyMacConfig->GetSlotsPerSubframe()) &&
              (sfNum < m_phyMacConfig->GetSubframesPerFrame()) && (deltaSubframe >= 0) &&
              (slotNum >= 0) && (sfNum >= 0) && (frameNum >= m_frameNum));

    MacPduInfo macPduInfo(SfnSf(frameNum, sfNum, slotNum, dci.m_symStart), dci.m_tbSize, activeLcs);
    std::map<uint32_t, struct MacPduInfo>::iterator it = m_macPduMap.find(dci.m_harqProcess);
    if (it != m_macPduMap.end())
    {
        m_macPduMap.erase(it);
    }
    it = (m_macPduMap.insert(std::pair<uint32_t, struct MacPduInfo>(dci.m_harqProcess, macPduInfo)))
             .first;
    return it;
}

void
MmWaveUeMac::DoReceiveControlMessage(Ptr<MmWaveControlMessage> msg)
{
    NS_LOG_FUNCTION(this << msg);

    switch (msg->GetMessageType())
    {
    case (MmWaveControlMessage::DCI_TDMA): {
        Ptr<MmWaveTdmaDciMessage> dciMsg = DynamicCast<MmWaveTdmaDciMessage>(msg);
        DciInfoElementTdma dciInfoElem = dciMsg->GetDciInfoElement();

        if (dciInfoElem.m_format == DciInfoElementTdma::UL_dci)
        {
            NS_LOG_DEBUG("UE MAC " << (uint32_t)m_componentCarrierId << " received UL_DCI");
            if (dciInfoElem.m_ndi == 1)
            {
                // New transmission -> empty pkt buffer queue (for deleting eventual pkts not acked
                // )
                Ptr<PacketBurst> pb = CreateObject<PacketBurst>();
                m_miUlHarqProcessesPacket.at(dciInfoElem.m_harqProcess).m_pktBurst = pb;
                m_miUlHarqProcessesPacket.at(dciInfoElem.m_harqProcess).m_lcidList.clear();
                // Retrieve data from RLC
                std::map<uint8_t, LteMacSapProvider::ReportBufferStatusParameters>::iterator itBsr;
                uint16_t activeLcs = 0;
                uint32_t statusPduMinSize = 0;
                for (itBsr = m_ulBsrReceived.begin(); itBsr != m_ulBsrReceived.end(); itBsr++)
                {
                    if (((*itBsr).second.statusPduSize > 0) ||
                        ((*itBsr).second.retxQueueSize > 0) || ((*itBsr).second.txQueueSize > 0))
                    {
                        // check if this LC is active in this MmWaveUeMac instance
                        if (m_lcInfoMap.find(itBsr->first) != m_lcInfoMap.end())
                        {
                            activeLcs++;
                            if (((*itBsr).second.statusPduSize != 0) &&
                                ((*itBsr).second.statusPduSize < statusPduMinSize))
                            {
                                statusPduMinSize = (*itBsr).second.statusPduSize;
                            }
                            if (((*itBsr).second.statusPduSize != 0) && (statusPduMinSize == 0))
                            {
                                statusPduMinSize = (*itBsr).second.statusPduSize;
                            }
                        }
                    }
                }

                if (activeLcs == 0)
                {
                    NS_LOG_DEBUG(this << " No active flows for this UL-DCI");
                    // the UE may have been scheduled when it has no buffered data due to BSR
                    // quantization, send empty packet
                    uint8_t slotNum = (m_slotNum + m_phyMacConfig->GetUlSchedDelay()) %
                                      m_phyMacConfig->GetSlotsPerSubframe();
                    uint8_t deltaSubframe = (m_slotNum + m_phyMacConfig->GetUlSchedDelay()) /
                                            m_phyMacConfig->GetSlotsPerSubframe();
                    uint8_t sfNum =
                        (m_sfNum + deltaSubframe) % m_phyMacConfig->GetSubframesPerFrame();
                    uint32_t frameNum = m_frameNum + ((m_sfNum + deltaSubframe) /
                                                      m_phyMacConfig->GetSubframesPerFrame());

                    NS_ASSERT((slotNum < m_phyMacConfig->GetSlotsPerSubframe()) &&
                              (sfNum < m_phyMacConfig->GetSubframesPerFrame()) &&
                              (deltaSubframe >= 0) && (slotNum >= 0) && (sfNum >= 0) &&
                              (frameNum >= m_frameNum));

                    MmWaveMacPduTag tag(SfnSf(frameNum, sfNum, slotNum, dciInfoElem.m_symStart));
                    Ptr<Packet> emptyPdu = Create<Packet>();
                    MmWaveMacPduHeader header;
                    MacSubheader subheader(3, 0); // lcid = 3, size = 0
                    header.AddSubheader(subheader);
                    emptyPdu->AddHeader(header);
                    emptyPdu->AddPacketTag(tag);
                    LteRadioBearerTag bearerTag(dciInfoElem.m_rnti, 3, 0);
                    emptyPdu->AddPacketTag(bearerTag);
                    m_miUlHarqProcessesPacket.at(dciInfoElem.m_harqProcess)
                        .m_pktBurst->AddPacket(emptyPdu);
                    m_miUlHarqProcessesPacketTimer.at(dciInfoElem.m_harqProcess) =
                        m_phyMacConfig->GetHarqTimeout();
                    // m_harqProcessId = (m_harqProcessId + 1) % m_phyMacConfig->GetHarqTimeout();
                    m_phySapProvider->SendMacPdu(emptyPdu);
                    return;
                }

                std::map<uint32_t, struct MacPduInfo>::iterator macPduIt =
                    AddToMacPduMap(dciInfoElem, activeLcs);
                std::map<uint8_t, LcInfo>::iterator lcIt;
                uint32_t bytesPerActiveLc = dciInfoElem.m_tbSize / activeLcs;
                bool statusPduPriority = false;
                if ((statusPduMinSize != 0) && (bytesPerActiveLc < statusPduMinSize))
                {
                    // send only the status PDU which has highest priority
                    statusPduPriority = true;
                    NS_LOG_DEBUG(this << " Reduced resource -> send only Status, bytes "
                                      << statusPduMinSize);
                    if (dciInfoElem.m_tbSize < statusPduMinSize)
                    {
                        NS_FATAL_ERROR("Insufficient Tx Opportunity for sending a status message");
                    }
                }
                NS_LOG_LOGIC(this << " UE " << m_rnti << ": UL-CQI notified TxOpportunity of "
                                  << dciInfoElem.m_tbSize << " => " << bytesPerActiveLc
                                  << " bytes per active LC"
                                  << " statusPduMinSize " << statusPduMinSize);

                LteMacSapUser::TxOpportunityParameters txOpParams;

                for (lcIt = m_lcInfoMap.begin(); lcIt != m_lcInfoMap.end(); lcIt++)
                {
                    itBsr = m_ulBsrReceived.find((*lcIt).first);
                    NS_LOG_DEBUG(this << " Processing LC " << (uint32_t)(*lcIt).first
                                      << " bytesPerActiveLc " << bytesPerActiveLc);
                    if ((itBsr != m_ulBsrReceived.end()) &&
                        (((*itBsr).second.statusPduSize > 0) ||
                         ((*itBsr).second.retxQueueSize > 0) || ((*itBsr).second.txQueueSize > 0)))
                    {
                        if ((statusPduPriority) &&
                            ((*itBsr).second.statusPduSize == statusPduMinSize))
                        {
                            MacSubheader subheader((*lcIt).first, (*itBsr).second.statusPduSize);

                            txOpParams.bytes = (*itBsr).second.statusPduSize;
                            txOpParams.layer = 0;
                            txOpParams.harqId = dciInfoElem.m_harqProcess;
                            txOpParams.componentCarrierId = m_componentCarrierId;
                            txOpParams.rnti = m_rnti;
                            txOpParams.lcid = (*lcIt).first;
                            (*lcIt).second.macSapUser->NotifyTxOpportunity(txOpParams);
                            NS_LOG_LOGIC(this << "\t" << bytesPerActiveLc << " send  "
                                              << (*itBsr).second.statusPduSize
                                              << " status bytes to LC " << (uint32_t)(*lcIt).first
                                              << " statusQueue " << (*itBsr).second.statusPduSize
                                              << " retxQueue" << (*itBsr).second.retxQueueSize
                                              << " txQueue" << (*itBsr).second.txQueueSize);
                            (*itBsr).second.statusPduSize = 0;
                            break;
                        }
                        else
                        {
                            uint32_t bytesForThisLc = bytesPerActiveLc;
                            NS_LOG_LOGIC(this << "\t" << bytesPerActiveLc << " bytes to LC "
                                              << (uint32_t)(*lcIt).first << " statusQueue "
                                              << (*itBsr).second.statusPduSize << " retxQueue"
                                              << (*itBsr).second.retxQueueSize << " txQueue"
                                              << (*itBsr).second.txQueueSize);
                            if (((*itBsr).second.statusPduSize > 0) &&
                                (bytesForThisLc > (*itBsr).second.statusPduSize))
                            {
                                if ((*itBsr).second.txQueueSize > 0 ||
                                    (*itBsr).second.retxQueueSize > 0)
                                {
                                    macPduIt->second.m_numRlcPdu++; // send status PDU + data PDU
                                }
                                // MacSubheader
                                // subheader((*lcIt).first,(*itBsr).second.statusPduSize);

                                txOpParams.bytes = (*itBsr).second.statusPduSize;
                                txOpParams.layer = 0;
                                txOpParams.harqId = dciInfoElem.m_harqProcess;
                                txOpParams.componentCarrierId = m_componentCarrierId;
                                txOpParams.rnti = m_rnti;
                                txOpParams.lcid = (*lcIt).first;
                                (*lcIt).second.macSapUser->NotifyTxOpportunity(txOpParams);
                                bytesForThisLc -= (*itBsr).second.statusPduSize;
                                NS_LOG_DEBUG(this << " serve STATUS "
                                                  << (*itBsr).second.statusPduSize);
                                (*itBsr).second.statusPduSize = 0;
                            }
                            else
                            {
                                if ((*itBsr).second.statusPduSize > bytesForThisLc)
                                {
                                    NS_FATAL_ERROR(
                                        "Insufficient Tx Opportunity for sending a status message");
                                }
                            }

                            if ((bytesForThisLc > 7) // 7 is the min TxOpportunity useful for Rlc
                                && (((*itBsr).second.retxQueueSize > 0) ||
                                    ((*itBsr).second.txQueueSize > 0)))
                            {
                                if ((*itBsr).second.retxQueueSize > 0)
                                {
                                    NS_LOG_DEBUG(this << " serve retx DATA, bytes "
                                                      << bytesForThisLc);
                                    MacSubheader subheader((*lcIt).first, bytesForThisLc);

                                    txOpParams.bytes = (bytesForThisLc - subheader.GetSize() - 1);
                                    txOpParams.layer = 0;
                                    txOpParams.harqId = dciInfoElem.m_harqProcess;
                                    txOpParams.componentCarrierId = m_componentCarrierId;
                                    txOpParams.rnti = m_rnti;
                                    txOpParams.lcid = (*lcIt).first;
                                    (*lcIt).second.macSapUser->NotifyTxOpportunity(
                                        txOpParams); // zml add 1 byte overhead
                                    if ((*itBsr).second.retxQueueSize >= bytesForThisLc)
                                    {
                                        (*itBsr).second.retxQueueSize -= bytesForThisLc;
                                    }
                                    else
                                    {
                                        (*itBsr).second.retxQueueSize = 0;
                                    }
                                }
                                else if ((*itBsr).second.txQueueSize > 0)
                                {
                                    uint16_t lcid = (*lcIt).first;
                                    uint32_t rlcOverhead;
                                    if (lcid == 1)
                                    {
                                        // for SRB1 (using RLC AM) it's better to
                                        // overestimate RLC overhead rather than
                                        // underestimate it and risk unneeded
                                        // segmentation which increases delay
                                        rlcOverhead = 4;
                                    }
                                    else
                                    {
                                        // minimum RLC overhead due to header
                                        rlcOverhead = 2;
                                    }
                                    NS_LOG_DEBUG(this << " serve tx DATA, bytes " << bytesForThisLc
                                                      << ", RLC overhead " << rlcOverhead);
                                    MacSubheader subheader((*lcIt).first, bytesForThisLc);

                                    txOpParams.bytes = (bytesForThisLc - subheader.GetSize() - 1);
                                    txOpParams.layer = 0;
                                    txOpParams.harqId = dciInfoElem.m_harqProcess;
                                    txOpParams.componentCarrierId = m_componentCarrierId;
                                    txOpParams.rnti = m_rnti;
                                    txOpParams.lcid = (*lcIt).first;
                                    (*lcIt).second.macSapUser->NotifyTxOpportunity(
                                        txOpParams); // zml add 1 byte overhead
                                    if ((*itBsr).second.txQueueSize >= bytesForThisLc - rlcOverhead)
                                    {
                                        (*itBsr).second.txQueueSize -= bytesForThisLc - rlcOverhead;
                                    }
                                    else
                                    {
                                        (*itBsr).second.txQueueSize = 0;
                                    }
                                }
                            }
                            else
                            {
                                if (((*itBsr).second.retxQueueSize > 0) ||
                                    ((*itBsr).second.txQueueSize > 0))
                                {
                                    // resend BSR info for updating eNB peer MAC
                                    m_freshUlBsr = true;
                                }
                            }
                            NS_LOG_LOGIC(this << "\t" << bytesPerActiveLc << "\t new queues "
                                              << (uint32_t)(*lcIt).first << " statusQueue "
                                              << (*itBsr).second.statusPduSize << " retxQueue"
                                              << (*itBsr).second.retxQueueSize << " txQueue"
                                              << (*itBsr).second.txQueueSize);
                        }
                    }
                }
            }
            else if (dciInfoElem.m_ndi == 0)
            {
                // HARQ retransmission -> retrieve data from HARQ buffer
                NS_LOG_DEBUG(this << " UE MAC RETX HARQ " << (unsigned)dciInfoElem.m_harqProcess);
                Ptr<PacketBurst> pb =
                    m_miUlHarqProcessesPacket.at(dciInfoElem.m_harqProcess).m_pktBurst;
                for (std::list<Ptr<Packet>>::const_iterator j = pb->Begin(); j != pb->End(); ++j)
                {
                    Ptr<Packet> pkt = (*j)->Copy();
                    // update packet tag
                    MmWaveMacPduTag tag;
                    if (!pkt->RemovePacketTag(tag))
                    {
                        NS_FATAL_ERROR("No MAC PDU tag");
                    }
                    LteRadioBearerTag bearerTag;
                    if (!pkt->PeekPacketTag(bearerTag))
                    {
                        NS_FATAL_ERROR("No radio bearer tag");
                    }
                    uint8_t slotNum = (m_slotNum + m_phyMacConfig->GetUlSchedDelay()) %
                                      m_phyMacConfig->GetSlotsPerSubframe();
                    uint8_t deltaSubframe = (m_slotNum + m_phyMacConfig->GetUlSchedDelay()) /
                                            m_phyMacConfig->GetSlotsPerSubframe();
                    uint8_t sfNum =
                        (m_sfNum + deltaSubframe) % m_phyMacConfig->GetSubframesPerFrame();
                    uint32_t frameNum = m_frameNum + ((m_sfNum + deltaSubframe) /
                                                      m_phyMacConfig->GetSubframesPerFrame());

                    NS_ASSERT((slotNum < m_phyMacConfig->GetSlotsPerSubframe()) &&
                              (sfNum < m_phyMacConfig->GetSubframesPerFrame()) &&
                              (deltaSubframe >= 0) && (slotNum >= 0) && (sfNum >= 0) &&
                              (frameNum >= m_frameNum));

                    tag.SetSfn(SfnSf(frameNum, sfNum, slotNum, dciInfoElem.m_symStart));
                    pkt->AddPacketTag(tag);

                    m_txMacPacketTraceUe(m_rnti, m_componentCarrierId, pkt->GetSize());
                    m_phySapProvider->SendMacPdu(pkt);
                }
                m_miUlHarqProcessesPacketTimer.at(dciInfoElem.m_harqProcess) =
                    m_phyMacConfig->GetHarqTimeout();
            }
        }
        break;
    }
    case (MmWaveControlMessage::RAR): {
        if (m_waitingForRaResponse == true)
        {
            Ptr<MmWaveRarMessage> rarMsg = DynamicCast<MmWaveRarMessage>(msg);
            NS_LOG_DEBUG(this << "got RAR with RA-RNTI " << (uint32_t)rarMsg->GetRaRnti()
                              << ", expecting " << (uint32_t)m_raRnti);
            for (std::list<MmWaveRarMessage::Rar>::const_iterator it = rarMsg->RarListBegin();
                 it != rarMsg->RarListEnd();
                 ++it)
            {
                if (it->rapId == m_raPreambleId)
                {
                    RecvRaResponse(it->rarPayload);
                }
            }
        }
        break;
    }

    default:
        NS_LOG_LOGIC("Control message not supported/expected");
    }
}

MmWaveUePhySapUser*
MmWaveUeMac::GetPhySapUser()
{
    return m_phySapUser;
}

void
MmWaveUeMac::SetPhySapProvider(MmWavePhySapProvider* ptr)
{
    m_phySapProvider = ptr;
}

void
MmWaveUeMac::DoConfigureRach(LteUeCmacSapProvider::RachConfig rc)
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveUeMac::DoStartContentionBasedRandomAccessProcedure()
{
    NS_LOG_FUNCTION(this);
    RandomlySelectAndSendRaPreamble();
}

void
MmWaveUeMac::DoSetRnti(uint16_t rnti)
{
    NS_LOG_FUNCTION(this);
    m_rnti = rnti;
}

void
MmWaveUeMac::RandomlySelectAndSendRaPreamble()
{
    NS_LOG_FUNCTION(this);
    bool contention = true;
    SendRaPreamble(contention);
}

void
MmWaveUeMac::SendRaPreamble(bool contention)
{
    if (contention)
    {
        m_raPreambleId = ++g_raPreambleId;
    }
    // else m_raPreambleId was already set

    /*raRnti should be subframeNo -1 */
    m_raRnti = m_sfNum - 1;
    m_waitingForRaResponse = true;

    NS_LOG_DEBUG("SendRachPreamble at time " << Simulator::Now());
    m_phySapProvider->SendRachPreamble(m_raPreambleId, m_raRnti);
}

void
MmWaveUeMac::DoStartNonContentionBasedRandomAccessProcedure(uint16_t rnti,
                                                            uint8_t preambleId,
                                                            uint8_t prachMask)
{
    NS_LOG_FUNCTION(this << " rnti" << rnti);
    NS_ASSERT_MSG(prachMask == 0,
                  "requested PRACH MASK = " << (uint32_t)prachMask
                                            << ", but only PRACH MASK = 0 is supported");
    m_rnti = rnti;
    m_raPreambleId = preambleId;
    bool contention = false;
    if (!m_interRatHoCapable) // we assume that the LTE eNB can send directionality info, thus the
                              // UE has not to wait to collect updated info
    {
        SendRaPreamble(contention);
    }
    else // instead in a single connectivity framework, the UE must wait for the periodic update
         // with the channel estimate
    {
        Time delay = MilliSeconds(m_randomAccessProcedureDelay->GetValue());
        NS_LOG_DEBUG("Schedule RA with delay " << delay);
        Simulator::Schedule(delay, &MmWaveUeMac::SendRaPreamble, this, contention);
    }
}

void
MmWaveUeMac::AddLc(uint8_t lcId,
                   LteUeCmacSapProvider::LogicalChannelConfig lcConfig,
                   LteMacSapUser* msu)
{
    NS_LOG_FUNCTION(this << " lcId" << (uint32_t)lcId);
    // NS_ASSERT_MSG (m_lcInfoMap.find (lcId) == m_lcInfoMap.end (), "cannot add channel because
    // LCID " << lcId << " is already present");
    NS_LOG_DEBUG("Add LC in " << m_rnti << " lcid " << (uint32_t)lcId);
    LcInfo lcInfo;
    lcInfo.lcConfig = lcConfig;
    lcInfo.macSapUser = msu;
    m_lcInfoMap[lcId] = lcInfo;
}

void
MmWaveUeMac::DoRemoveLc(uint8_t lcId)
{
    NS_LOG_FUNCTION(this << " lcId" << lcId);
    NS_LOG_DEBUG("Remove LC in " << m_rnti << " lcid " << (uint32_t)lcId);
    if (m_lcInfoMap.find(lcId) != m_lcInfoMap.end())
    {
        m_lcInfoMap.erase(m_lcInfoMap.find(lcId));
    }
}

LteMacSapProvider*
MmWaveUeMac::GetUeMacSapProvider(void)
{
    return m_macSapProvider;
}

void
MmWaveUeMac::DoReset()
{
    NS_LOG_FUNCTION(this);
    std::map<uint8_t, LcInfo>::iterator it = m_lcInfoMap.begin();
    while (it != m_lcInfoMap.end())
    {
        // don't delete CCCH)
        if (it->first == 0)
        {
            ++it;
        }
        else
        {
            // note: use of postfix operator preserves validity of iterator
            NS_LOG_LOGIC("RemoveLc " << (uint16_t)it->first);
            m_lcInfoMap.erase(it++);
        }
    }
    m_rnti = 0;

    // m_noRaResponseReceivedEvent.Cancel ();
    // m_rachConfigured = false;
    m_miUlHarqProcessesPacket.clear();
    m_miUlHarqProcessesPacketTimer.clear();
    m_freshUlBsr = false;
    m_ulBsrReceived.clear();
    m_macPduMap.clear();

    // set things to their initial state
    SetConfigurationParameters(m_phyMacConfig);
}

int64_t
MmWaveUeMac::AssignStreams(int64_t stream)
{
    NS_LOG_FUNCTION(this << stream);
    m_randomAccessProcedureDelay->SetStream(stream);
    return 1;
}

//////////////////////////////////////////////

} // namespace mmwave

} // namespace ns3
