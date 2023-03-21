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

#include "mmwave-mac-scheduler.h"

#include <ns3/log.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWaveMacScheduler");

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWaveMacScheduler);

MmWaveMacScheduler::MmWaveMacScheduler()
{
    NS_LOG_FUNCTION(this);
}

MmWaveMacScheduler::~MmWaveMacScheduler()
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveMacScheduler::DoDispose(void)
{
    NS_LOG_FUNCTION(this);
}

TypeId
MmWaveMacScheduler::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::MmWaveMacScheduler").SetParent<Object>();

    return tid;
}

/*void
MmWaveMacScheduler::ConfigureCommonParameters (Ptr<MmWavePhyMacCommon> config)
{
        m_phyMacConfig = config;
}*/

} // namespace mmwave

} // namespace ns3
