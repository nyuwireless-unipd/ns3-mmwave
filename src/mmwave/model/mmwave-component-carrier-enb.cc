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

#include "mmwave-component-carrier-enb.h"

#include <ns3/abort.h>
#include <ns3/boolean.h>
#include <ns3/log.h>
#include <ns3/lte-ffr-algorithm.h>
#include <ns3/mmwave-enb-mac.h>
#include <ns3/mmwave-enb-phy.h>
#include <ns3/mmwave-mac-scheduler.h>
#include <ns3/pointer.h>
#include <ns3/simulator.h>
#include <ns3/uinteger.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveComponentCarrierEnb");
NS_OBJECT_ENSURE_REGISTERED(MmWaveComponentCarrierEnb);

TypeId
MmWaveComponentCarrierEnb::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveComponentCarrierEnb")
            .SetParent<MmWaveComponentCarrier>()
            .AddConstructor<MmWaveComponentCarrierEnb>()
            .AddAttribute("MmWaveEnbPhy",
                          "The PHY associated to this ComponentCarrierEnb",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveComponentCarrierEnb::m_phy),
                          MakePointerChecker<MmWaveEnbPhy>())
            .AddAttribute("MmWaveEnbMac",
                          "The MAC associated to this ComponentCarrierEnb",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveComponentCarrierEnb::m_mac),
                          MakePointerChecker<MmWaveEnbMac>())
            .AddAttribute("MmWaveMacScheduler",
                          "The scheduler associated to this ComponentCarrierEnb",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveComponentCarrierEnb::m_scheduler),
                          MakePointerChecker<MmWaveMacScheduler>())
        /*
        .AddAttribute ("LteFfrAlgorithm",
                       "The FFR algorithm associated to this ComponentCarrierEnb",
                       PointerValue (),
                       MakePointerAccessor (&ComponentCarrierEnb::m_ffrAlgorithm),
                       MakePointerChecker <LteFfrAlgorithm> ())
                       */
        ;
    return tid;
}

MmWaveComponentCarrierEnb::MmWaveComponentCarrierEnb()
{
    NS_LOG_FUNCTION(this);
}

MmWaveComponentCarrierEnb::~MmWaveComponentCarrierEnb(void)
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveComponentCarrierEnb::DoDispose()
{
    NS_LOG_FUNCTION(this);
    if (m_phy)
    {
        m_phy->Dispose();
        m_phy = 0;
    }
    if (m_mac)
    {
        m_mac->Dispose();
        m_mac = 0;
    }
    if (m_scheduler)
    {
        m_scheduler->Dispose();
        m_scheduler = 0;
    }
    /*
    if (m_ffrAlgorithm)
      {
        m_ffrAlgorithm->Dispose ();
        m_ffrAlgorithm = 0;
      }
   */
    MmWaveComponentCarrier::DoDispose();
}

void
MmWaveComponentCarrierEnb::DoInitialize(void)
{
    NS_LOG_FUNCTION(this);
    m_isConstructed = true;
    m_phy->Initialize();
    m_mac->Initialize();
    // m_ffrAlgorithm->Initialize ();
    m_scheduler->Initialize();
}

uint16_t
MmWaveComponentCarrierEnb::GetCellId()
{
    return m_cellId;
}

Ptr<MmWaveEnbPhy>
MmWaveComponentCarrierEnb::GetPhy()
{
    NS_LOG_FUNCTION(this);
    return m_phy;
}

void
MmWaveComponentCarrierEnb::SetCellId(uint16_t cellId)
{
    NS_LOG_FUNCTION(this << cellId);
    m_cellId = cellId;
}

void
MmWaveComponentCarrierEnb::SetPhy(Ptr<MmWaveEnbPhy> s)
{
    NS_LOG_FUNCTION(this);
    m_phy = s;
}

Ptr<MmWaveEnbMac>
MmWaveComponentCarrierEnb::GetMac()
{
    NS_LOG_FUNCTION(this);
    return m_mac;
}

void
MmWaveComponentCarrierEnb::SetMac(Ptr<MmWaveEnbMac> s)
{
    NS_LOG_FUNCTION(this);
    m_mac = s;
}

/*
Ptr<LteFfrAlgorithm>
ComponentCarrierEnb::GetFfrAlgorithm ()
{
  NS_LOG_FUNCTION (this);
  return m_ffrAlgorithm;
}

void
ComponentCarrierEnb::SetFfrAlgorithm (Ptr<LteFfrAlgorithm> s)
{
  NS_LOG_FUNCTION (this);
  m_ffrAlgorithm = s;
}
*/

Ptr<MmWaveMacScheduler>
MmWaveComponentCarrierEnb::GetMacScheduler()
{
    NS_LOG_FUNCTION(this);
    return m_scheduler;
}

void
MmWaveComponentCarrierEnb::SetMacScheduler(Ptr<MmWaveMacScheduler> s)
{
    NS_LOG_FUNCTION(this);
    m_scheduler = s;
}

} // namespace mmwave

} // namespace ns3
