/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2015 Danilo Abrignani
 * Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Danilo Abrignani <danilo.abrignani@unibo.it>
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                               Integration of Carrier Aggregation
 */

#include "mmwave-component-carrier.h"

#include <ns3/abort.h>
#include <ns3/boolean.h>
#include <ns3/log.h>
#include <ns3/mmwave-enb-phy.h>
#include <ns3/pointer.h>
#include <ns3/simulator.h>
#include <ns3/uinteger.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveComponentCarrier");

NS_OBJECT_ENSURE_REGISTERED(MmWaveComponentCarrier);

TypeId
MmWaveComponentCarrier::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveComponentCarrier")
            .SetParent<Object>()
            .AddConstructor<MmWaveComponentCarrier>()
            .AddAttribute("CsgId",
                          "The Closed Subscriber Group (CSG) identity that this eNodeB belongs to",
                          UintegerValue(0),
                          MakeUintegerAccessor(&MmWaveComponentCarrier::SetCsgId,
                                               &MmWaveComponentCarrier::GetCsgId),
                          MakeUintegerChecker<uint32_t>())
            .AddAttribute(
                "CsgIndication",
                "If true, only UEs which are members of the CSG (i.e. same CSG ID) "
                "can gain access to the eNodeB, therefore enforcing closed access mode. "
                "Otherwise, the eNodeB operates as a non-CSG cell and implements open access mode.",
                BooleanValue(false),
                MakeBooleanAccessor(&MmWaveComponentCarrier::SetCsgIndication,
                                    &MmWaveComponentCarrier::GetCsgIndication),
                MakeBooleanChecker())
            .AddAttribute(
                "PrimaryCarrier",
                "If true, this Carrier Component will be the Primary Carrier Component (PCC) "
                "Only one PCC per eNodeB is (currently) allowed",
                BooleanValue(false),
                MakeBooleanAccessor(&MmWaveComponentCarrier::SetAsPrimary,
                                    &MmWaveComponentCarrier::IsPrimary),
                MakeBooleanChecker())
            .AddAttribute("Antenna",
                          "Antenna used by the device in this component carrier",
                          PointerValue(0),
                          MakePointerAccessor(&MmWaveComponentCarrier::SetAntenna,
                                              &MmWaveComponentCarrier::GetAntenna),
                          MakePointerChecker<PhasedArrayModel>());
    return tid;
}

MmWaveComponentCarrier::MmWaveComponentCarrier()
    : m_isConstructed(false)
{
    NS_LOG_FUNCTION(this);
}

MmWaveComponentCarrier::~MmWaveComponentCarrier(void)
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveComponentCarrier::DoDispose()
{
    NS_LOG_FUNCTION(this);
    m_antenna = 0;
    Object::DoDispose();
}

uint32_t
MmWaveComponentCarrier::GetBandwidthInRb() const
{
    return m_phyMacConfig->GetNumRb();
}

double
MmWaveComponentCarrier::GetCenterFrequency() const
{
    return m_phyMacConfig->GetCenterFrequency();
}

uint32_t
MmWaveComponentCarrier::GetCsgId() const
{
    return m_csgId;
}

void
MmWaveComponentCarrier::SetCsgId(uint32_t csgId)
{
    NS_LOG_FUNCTION(this << csgId);
    m_csgId = csgId;
}

bool
MmWaveComponentCarrier::GetCsgIndication() const
{
    return m_csgIndication;
}

void
MmWaveComponentCarrier::SetCsgIndication(bool csgIndication)
{
    NS_LOG_FUNCTION(this << csgIndication);
    m_csgIndication = csgIndication;
}

bool
MmWaveComponentCarrier::IsPrimary() const
{
    return m_primaryCarrier;
}

void
MmWaveComponentCarrier::SetAsPrimary(bool primaryCarrier)
{
    NS_LOG_FUNCTION(this << primaryCarrier);
    m_primaryCarrier = primaryCarrier;
}

void
MmWaveComponentCarrier::DoInitialize(void)
{
    NS_LOG_FUNCTION(this);
    m_isConstructed = true;
}

void
MmWaveComponentCarrier::SetConfigurationParameters(Ptr<MmWavePhyMacCommon> ptrConfig)
{
    NS_LOG_FUNCTION(this);
    m_phyMacConfig = ptrConfig;
}

Ptr<MmWavePhyMacCommon>
MmWaveComponentCarrier::GetConfigurationParameters(void) const
{
    NS_LOG_FUNCTION(this);
    return m_phyMacConfig;
}

void
MmWaveComponentCarrier::SetAntenna(Ptr<PhasedArrayModel> antenna)
{
    NS_LOG_FUNCTION(this << antenna);
    m_antenna = antenna;
}

Ptr<PhasedArrayModel>
MmWaveComponentCarrier::GetAntenna(void) const
{
    NS_LOG_FUNCTION(this);
    return m_antenna;
}

} // namespace mmwave

} // namespace ns3
