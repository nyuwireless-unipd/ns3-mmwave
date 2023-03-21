/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
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
 */

#include "mmwave-mac.h"

#include "mmwave-phy-sap.h"
#include "mmwave-radio-bearer-tag.h"

#include <ns3/log.h>
#include <ns3/object-factory.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWaveMac");

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWaveMac);

MmWaveMac::MmWaveMac()
{
    m_macQueue = CreateObject<PacketBurst>();
}

MmWaveMac::~MmWaveMac()
{
}

void
MmWaveMac::SetConfigurationParameters(Ptr<MmWavePhyMacCommon> ptrConfig)
{
    m_phyMacConfig = ptrConfig;
}

Ptr<MmWavePhyMacCommon>
MmWaveMac::GetConfigurationParameters(void) const
{
    return m_phyMacConfig;
}

bool
MmWaveMac::QueueData(Ptr<Packet> packet)
{
    NS_LOG_INFO("Queue in Mac");

    m_macQueue->AddPacket(packet);

    return true;
}

Ptr<PacketBurst>
MmWaveMac::GetPacketBurstFromMacQueue()
{
    NS_LOG_FUNCTION(this);

    Ptr<PacketBurst> pb = CreateObject<PacketBurst>();
    if (m_macQueue->GetNPackets() > 0)
    {
        pb = m_macQueue->Copy();
        m_macQueue->Dispose();
        m_macQueue = CreateObject<PacketBurst>();
    }

    return pb;
}

} // namespace mmwave

} // namespace ns3
