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

#include "mmwave-component-carrier-ue.h"

#include <ns3/abort.h>
#include <ns3/boolean.h>
#include <ns3/log.h>
#include <ns3/mmwave-ue-mac.h>
#include <ns3/mmwave-ue-phy.h>
#include <ns3/pointer.h>
#include <ns3/simulator.h>
#include <ns3/uinteger.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveComponentCarrierUe");

NS_OBJECT_ENSURE_REGISTERED(MmWaveComponentCarrierUe);

TypeId
MmWaveComponentCarrierUe::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::MmWaveComponentCarrierUe")
                            .SetParent<MmWaveComponentCarrier>()
                            .AddConstructor<MmWaveComponentCarrierUe>()
                            .AddAttribute("MmWaveUePhy",
                                          "The PHY associated to this ComponentCarrierUe",
                                          PointerValue(),
                                          MakePointerAccessor(&MmWaveComponentCarrierUe::m_phy),
                                          MakePointerChecker<MmWaveUePhy>())
                            .AddAttribute("MmWaveUeMac",
                                          "The MAC associated to this ComponentCarrierUe",
                                          PointerValue(),
                                          MakePointerAccessor(&MmWaveComponentCarrierUe::m_mac),
                                          MakePointerChecker<MmWaveUeMac>());
    return tid;
}

MmWaveComponentCarrierUe::MmWaveComponentCarrierUe()
{
    NS_LOG_FUNCTION(this);
}

MmWaveComponentCarrierUe::~MmWaveComponentCarrierUe(void)
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveComponentCarrierUe::DoDispose()
{
    NS_LOG_FUNCTION(this);
    m_phy->Dispose();
    m_phy = 0;
    m_mac->Dispose();
    m_mac = 0;
    MmWaveComponentCarrier::DoDispose();
}

void
MmWaveComponentCarrierUe::DoInitialize(void)
{
    NS_LOG_FUNCTION(this);
    m_isConstructed = true;
    m_phy->Initialize();
    m_mac->Initialize();
}

void
MmWaveComponentCarrierUe::SetPhy(Ptr<MmWaveUePhy> s)
{
    NS_LOG_FUNCTION(this);
    m_phy = s;
}

Ptr<MmWaveUePhy>
MmWaveComponentCarrierUe::GetPhy() const
{
    NS_LOG_FUNCTION(this);
    return m_phy;
}

void
MmWaveComponentCarrierUe::SetMac(Ptr<MmWaveUeMac> s)
{
    NS_LOG_FUNCTION(this);
    m_mac = s;
}

Ptr<MmWaveUeMac>
MmWaveComponentCarrierUe::GetMac() const
{
    NS_LOG_FUNCTION(this);
    return m_mac;
}

} // namespace mmwave

} // namespace ns3
