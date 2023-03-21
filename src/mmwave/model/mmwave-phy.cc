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
 *                               Integration of Carrier Aggregation
 */

#include "mmwave-phy.h"

#include "mmwave-mac-pdu-header.h"
#include "mmwave-mac-pdu-tag.h"
#include "mmwave-phy-sap.h"

#include <ns3/callback.h>
#include <ns3/log.h>
#include <ns3/node.h>
#include <ns3/packet.h>
#include <ns3/simulator.h>

#include <sstream>
#include <vector>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWavePhy");

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWavePhy);

/*   SAP   */
class MmWaveMemberPhySapProvider : public MmWavePhySapProvider
{
  public:
    MmWaveMemberPhySapProvider(MmWavePhy* phy);

    virtual void SendMacPdu(Ptr<Packet> p);

    virtual void SendControlMessage(Ptr<MmWaveControlMessage> msg);

    virtual void SendRachPreamble(uint8_t PreambleId, uint8_t Rnti);

    virtual void SetSlotAllocInfo(SlotAllocInfo slotAllocInfo);

  private:
    MmWavePhy* m_phy;
};

MmWaveMemberPhySapProvider::MmWaveMemberPhySapProvider(MmWavePhy* phy)
    : m_phy(phy)
{
    //   Nothing more to do
}

void
MmWaveMemberPhySapProvider::SendMacPdu(Ptr<Packet> p)
{
    m_phy->SetMacPdu(p);
}

void
MmWaveMemberPhySapProvider::SendControlMessage(Ptr<MmWaveControlMessage> msg)
{
    m_phy->SetControlMessage(msg); // May need to change
}

void
MmWaveMemberPhySapProvider::SendRachPreamble(uint8_t PreambleId, uint8_t Rnti)
{
    m_phy->SendRachPreamble(PreambleId, Rnti);
}

void
MmWaveMemberPhySapProvider::SetSlotAllocInfo(SlotAllocInfo slotAllocInfo)
{
    m_phy->DoSetSlotAllocInfo(slotAllocInfo);
}

TypeId
MmWavePhy::GetTypeId()
{
    static TypeId tid = TypeId("ns3::MmWavePhy").SetParent<Object>();

    return tid;
}

MmWavePhy::MmWavePhy()
{
    NS_LOG_FUNCTION(this);
    NS_FATAL_ERROR("This constructor should not be called");
}

MmWavePhy::MmWavePhy(Ptr<MmWaveSpectrumPhy> dlChannelPhy, Ptr<MmWaveSpectrumPhy> ulChannelPhy)
    : m_downlinkSpectrumPhy(dlChannelPhy),
      m_uplinkSpectrumPhy(ulChannelPhy),
      m_cellId(0),
      m_frameNum(0),
      m_sfNum(0),
      m_slotNum(0),
      m_ttiIndex(0),
      m_sfAllocInfoUpdated(false),
      m_componentCarrierId(0)
{
    NS_LOG_FUNCTION(this);
    m_phySapProvider = new MmWaveMemberPhySapProvider(this);
}

MmWavePhy::~MmWavePhy()
{
}

void
MmWavePhy::DoInitialize()
{
}

void
MmWavePhy::DoDispose()
{
    NS_LOG_FUNCTION(this);
    m_controlMessageQueue.clear();

    Object::DoDispose();
}

void
MmWavePhy::SetDevice(Ptr<NetDevice> d)
{
    m_netDevice = d;
}

Ptr<NetDevice>
MmWavePhy::GetDevice()
{
    return m_netDevice;
}

void
MmWavePhy::SetChannel(Ptr<SpectrumChannel> c)
{
}

Time
MmWavePhy::GetNextSlotDelay()
{
    return m_lastSlotStart + m_slotPeriod - Simulator::Now();
}

void
MmWavePhy::DoSetCellId(uint16_t cellId)
{
    NS_LOG_FUNCTION(this);
    m_cellId = cellId;
    m_downlinkSpectrumPhy->SetCellId(cellId);
    m_uplinkSpectrumPhy->SetCellId(cellId);
}

void
MmWavePhy::SetNoiseFigure(double nf)
{
    m_noiseFigure = nf;
}

double
MmWavePhy::GetNoiseFigure(void) const
{
    return m_noiseFigure;
}

void
MmWavePhy::SendRachPreamble(uint32_t PreambleId, uint32_t Rnti)
{
    m_raPreambleId = PreambleId;
    Ptr<MmWaveRachPreambleMessage> msg = Create<MmWaveRachPreambleMessage>();
    msg->SetRapId(PreambleId);
    SetControlMessage(msg);
}

void
MmWavePhy::SetMacPdu(Ptr<Packet> p)
{
    MmWaveMacPduTag tag;
    if (p->PeekPacketTag(tag))
    {
        NS_ASSERT((tag.GetSfn().m_sfNum >= 0) &&
                  (tag.GetSfn().m_sfNum < m_phyMacConfig->GetSubframesPerFrame()));
        std::map<uint64_t, Ptr<PacketBurst>>::iterator it =
            m_packetBurstMap.find(tag.GetSfn().Encode());
        if (it == m_packetBurstMap.end())
        {
            it = m_packetBurstMap
                     .insert(std::pair<uint64_t, Ptr<PacketBurst>>(tag.GetSfn().Encode(),
                                                                   CreateObject<PacketBurst>()))
                     .first;
        }
        else
        {
            NS_FATAL_ERROR("Packet burst map entry already exists");
        }
        it->second->AddPacket(p);
    }
    else
    {
        NS_FATAL_ERROR("No MAC packet PDU header available");
    }
}

Ptr<PacketBurst>
MmWavePhy::GetPacketBurst(SfnSf sfn)
{
    Ptr<PacketBurst> pburst;
    std::map<uint64_t, Ptr<PacketBurst>>::iterator it = m_packetBurstMap.find(sfn.Encode());
    if (it == m_packetBurstMap.end())
    {
        NS_LOG_ERROR("GetPacketBurst(): Packet burst not found for frame "
                     << (unsigned)sfn.m_frameNum << " subframe " << (unsigned)sfn.m_sfNum
                     << " slot " << (unsigned)sfn.m_slotNum << "sym start "
                     << (unsigned)sfn.m_symStart);
        return pburst;
    }
    else
    {
        pburst = it->second;
        m_packetBurstMap.erase(it);
    }
    return pburst;
}

void
MmWavePhy::SetControlMessage(Ptr<MmWaveControlMessage> m)
{
    if (m_controlMessageQueue.empty())
    {
        std::list<Ptr<MmWaveControlMessage>> l;
        l.push_back(m);
        m_controlMessageQueue.push_back(l);
    }
    else
    {
        m_controlMessageQueue.at(m_controlMessageQueue.size() - 1).push_back(m);
    }
}

std::list<Ptr<MmWaveControlMessage>>
MmWavePhy::GetControlMessages(void)
{
    NS_LOG_FUNCTION(this);
    if (m_controlMessageQueue.empty())
    {
        std::list<Ptr<MmWaveControlMessage>> emptylist;
        return (emptylist);
    }

    if (m_controlMessageQueue.at(0).size() > 0)
    {
        std::list<Ptr<MmWaveControlMessage>> ret = m_controlMessageQueue.front();
        m_controlMessageQueue.erase(m_controlMessageQueue.begin());
        std::list<Ptr<MmWaveControlMessage>> newlist;
        m_controlMessageQueue.push_back(newlist);
        return (ret);
    }
    else
    {
        m_controlMessageQueue.erase(m_controlMessageQueue.begin());
        std::list<Ptr<MmWaveControlMessage>> newlist;
        m_controlMessageQueue.push_back(newlist);
        std::list<Ptr<MmWaveControlMessage>> emptylist;
        return (emptylist);
    }
}

void
MmWavePhy::SetSlotCtrlStructure(uint8_t slotIndex)
{
    // Currently hardcoded: first OFDM symbol = DL control, last OFDM symbol = UL control
    TtiAllocInfo dlCtrlTti;
    dlCtrlTti.m_ttiType = TtiAllocInfo::CTRL;
    dlCtrlTti.m_numCtrlSym = 1;
    dlCtrlTti.m_tddMode = TtiAllocInfo::DL_slotAllocInfo;
    dlCtrlTti.m_dci.m_numSym = 1;
    dlCtrlTti.m_dci.m_symStart = 0;
    TtiAllocInfo ulCtrlTti;
    ulCtrlTti.m_ttiType = TtiAllocInfo::CTRL;
    ulCtrlTti.m_numCtrlSym = 1;
    ulCtrlTti.m_tddMode = TtiAllocInfo::UL_slotAllocInfo;
    ulCtrlTti.m_ttiIdx = 0xFF;
    ulCtrlTti.m_dci.m_numSym = 1;
    ulCtrlTti.m_dci.m_symStart = m_phyMacConfig->GetSymbPerSlot() - 1;
    m_slotAllocInfo[slotIndex].m_ttiAllocInfo.push_front(dlCtrlTti);
    m_slotAllocInfo[slotIndex].m_ttiAllocInfo.push_back(ulCtrlTti);
}

void
MmWavePhy::SetConfigurationParameters(Ptr<MmWavePhyMacCommon> ptrConfig)
{
    m_phyMacConfig = ptrConfig;
}

Ptr<MmWavePhyMacCommon>
MmWavePhy::GetConfigurationParameters(void) const
{
    return m_phyMacConfig;
}

MmWavePhySapProvider*
MmWavePhy::GetPhySapProvider()
{
    return m_phySapProvider;
}

SlotAllocInfo
MmWavePhy::GetSfAllocInfo(uint8_t subframeNum)
{
    return m_slotAllocInfo[subframeNum];
}

void
MmWavePhy::DoSetSlotAllocInfo(SlotAllocInfo slotAllocInfo)
{
    // get previously enqueued SlotAllocInfo and set DL slot allocations
    // SlotAllocInfo &sf = m_sfAllocInfo[slotAllocInfo.m_sfnSf.m_sfNum];
    // merge slot lists
    // sf.m_dlSlotAllocInfo = slotAllocInfo.m_dlSlotAllocInfo;
    m_slotAllocInfo[slotAllocInfo.m_sfnSf.m_slotNum] = slotAllocInfo;
    // m_sfAllocInfoUpdated = true;
}

void
MmWavePhy::AddPropagationLossModel(Ptr<PropagationLossModel> model)
{
    m_propagationLoss = model;
}

void
MmWavePhy::AddSpectrumPropagationLossModel(Ptr<SpectrumPropagationLossModel> model)
{
    m_spectrumPropagationLossModel = model;
}

void
MmWavePhy::AddPhasedArraySpectrumPropagationLossModel(
    Ptr<PhasedArraySpectrumPropagationLossModel> model)
{
    m_phasedArraySpectrumPropagationLossModel = model;
}

void
MmWavePhy::SetComponentCarrierId(uint8_t index)
{
    m_componentCarrierId = index;
    m_downlinkSpectrumPhy->SetComponentCarrierId(index);
    m_uplinkSpectrumPhy->SetComponentCarrierId(index);
}

uint8_t
MmWavePhy::GetComponentCarrierId()
{
    return m_componentCarrierId;
}

} // namespace mmwave

} // namespace ns3
