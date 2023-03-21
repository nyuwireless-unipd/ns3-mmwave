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
 *   Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                               Integration of Carrier Aggregation
 */

#include "mmwave-ue-net-device.h"

#include "mmwave-enb-net-device.h"
#include "mmwave-net-device.h"
#include "mmwave-ue-phy.h"

#include "ns3/mmwave-component-carrier-ue.h"
#include <ns3/callback.h>
#include <ns3/enum.h>
#include <ns3/ipv4-header.h>
#include <ns3/ipv4-l3-protocol.h>
#include <ns3/ipv4.h>
#include <ns3/ipv6-l3-protocol.h>
#include <ns3/llc-snap-header.h>
#include <ns3/log.h>
#include <ns3/lte-ue-component-carrier-manager.h>
#include <ns3/node.h>
#include <ns3/packet-burst.h>
#include <ns3/packet.h>
#include <ns3/pointer.h>
#include <ns3/simulator.h>
#include <ns3/trace-source-accessor.h>
#include <ns3/uinteger.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWaveUeNetDevice");

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWaveUeNetDevice);

TypeId
MmWaveUeNetDevice::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveUeNetDevice")
            .SetParent<MmWaveNetDevice>()
            .AddConstructor<MmWaveUeNetDevice>()
            .AddAttribute("EpcUeNas",
                          "The NAS associated to this UeNetDevice",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveUeNetDevice::m_nas),
                          MakePointerChecker<EpcUeNas>())
            .AddAttribute("mmWaveUeRrc",
                          "The RRC associated to this UeNetDevice",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveUeNetDevice::m_rrc),
                          MakePointerChecker<LteUeRrc>())
            .AddAttribute("LteUeComponentCarrierManager",
                          "The ComponentCarrierManager associated to this UeNetDevice",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveUeNetDevice::m_componentCarrierManager),
                          MakePointerChecker<LteUeComponentCarrierManager>())
            .AddAttribute("Imsi",
                          "International Mobile Subscriber Identity assigned to this UE",
                          UintegerValue(0),
                          MakeUintegerAccessor(&MmWaveUeNetDevice::m_imsi),
                          MakeUintegerChecker<uint64_t>())
            .AddAttribute("LteUeRrc",
                          "The RRC layer associated with the ENB",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveUeNetDevice::m_rrc),
                          MakePointerChecker<LteUeRrc>());
    return tid;
}

MmWaveUeNetDevice::MmWaveUeNetDevice(void)
{
    NS_LOG_FUNCTION(this);
}

MmWaveUeNetDevice::~MmWaveUeNetDevice(void)
{
}

void
MmWaveUeNetDevice::DoInitialize(void)
{
    NS_LOG_FUNCTION(this);
    m_isConstructed = true;
    UpdateConfig();

    for (auto it = m_ccMap.begin(); it != m_ccMap.end(); ++it)
    {
        Ptr<MmWaveComponentCarrierUe> ccUe = DynamicCast<MmWaveComponentCarrierUe>(it->second);
        ccUe->GetPhy()->Initialize();
        ccUe->GetMac()->Initialize();
    }
    m_rrc->Initialize();
}

void
MmWaveUeNetDevice::DoDispose()
{
    NS_LOG_FUNCTION(this);
    m_targetEnb = 0;

    m_rrc->Dispose();
    m_rrc = 0;

    m_nas->Dispose();
    m_nas = 0;

    for (uint32_t i = 0; i < m_ccMap.size(); i++)
    {
        m_ccMap.at(i)->Dispose();
    }
    m_componentCarrierManager->Dispose();
}

uint32_t
MmWaveUeNetDevice::GetCsgId() const
{
    NS_LOG_FUNCTION(this);
    return m_csgId;
}

void
MmWaveUeNetDevice::SetCsgId(uint32_t csgId)
{
    NS_LOG_FUNCTION(this << csgId);
    m_csgId = csgId;
    UpdateConfig(); // propagate the change down to NAS and RRC
}

void
MmWaveUeNetDevice::UpdateConfig(void)
{
    NS_LOG_FUNCTION(this);

    if (m_isConstructed)
    {
        NS_LOG_LOGIC(this << " Updating configuration: IMSI " << m_imsi << " CSG ID " << m_csgId);
        m_nas->SetImsi(m_imsi);
        m_rrc->SetImsi(m_imsi);
        m_nas->SetCsgId(m_csgId); // this also handles propagation to RRC
    }
    else
    {
        /*
         * NAS and RRC instances are not be ready yet, so do nothing now and
         * expect ``DoInitialize`` to re-invoke this function.
         */
    }
}

bool
MmWaveUeNetDevice::DoSend(Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber)
{
    NS_LOG_FUNCTION(this << dest << protocolNumber);
    NS_ABORT_MSG_IF(protocolNumber != Ipv4L3Protocol::PROT_NUMBER &&
                        protocolNumber != Ipv6L3Protocol::PROT_NUMBER,
                    "unsupported protocol " << protocolNumber
                                            << ", only IPv4 and IPv6 are supported");

    return m_nas->Send(packet, protocolNumber);
}

Ptr<MmWaveUePhy>
MmWaveUeNetDevice::GetPhy(void) const
{
    NS_LOG_FUNCTION(this);
    return DynamicCast<MmWaveComponentCarrierUe>(m_ccMap.at(0))->GetPhy();
}

Ptr<MmWaveUePhy>
MmWaveUeNetDevice::GetPhy(uint8_t index) const
{
    NS_LOG_FUNCTION(this);
    return DynamicCast<MmWaveComponentCarrierUe>(m_ccMap.at(index))->GetPhy();
}

Ptr<LteUeComponentCarrierManager>
MmWaveUeNetDevice::GetComponentCarrierManager(void) const
{
    NS_LOG_FUNCTION(this);
    return m_componentCarrierManager;
}

Ptr<MmWaveUeMac>
MmWaveUeNetDevice::GetMac(void) const
{
    NS_LOG_FUNCTION(this);
    return DynamicCast<MmWaveComponentCarrierUe>(m_ccMap.at(0))->GetMac();
}

Ptr<EpcUeNas>
MmWaveUeNetDevice::GetNas(void) const
{
    NS_LOG_FUNCTION(this);
    return m_nas;
}

Ptr<LteUeRrc>
MmWaveUeNetDevice::GetRrc(void) const
{
    NS_LOG_FUNCTION(this);
    return m_rrc;
}

uint64_t
MmWaveUeNetDevice::GetImsi() const
{
    NS_LOG_FUNCTION(this);
    return m_imsi;
}

void
MmWaveUeNetDevice::SetTargetEnb(Ptr<MmWaveEnbNetDevice> enb)
{
    NS_LOG_FUNCTION(this << enb);
    m_targetEnb = enb;
}

Ptr<MmWaveEnbNetDevice>
MmWaveUeNetDevice::GetTargetEnb(void)
{
    NS_LOG_FUNCTION(this);
    return m_targetEnb;
}

} // namespace mmwave
} // namespace ns3
