/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2020 University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 */

#include "ns3/beamforming-codebook.h"

#include <ns3/log.h>
#include <ns3/pointer.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("BeamformingCodebook");

NS_OBJECT_ENSURE_REGISTERED(BeamformingCodebook);

TypeId
BeamformingCodebook::GetTypeId()
{
    static TypeId tid = TypeId("ns3::BeamformingCodebook")
                            .SetParent<Object>()
                            .AddAttribute("Array",
                                          "The PhasedArrayModel for which the codebook is created",
                                          PointerValue(),
                                          MakePointerAccessor(&BeamformingCodebook::m_array),
                                          MakePointerChecker<PhasedArrayModel>());
    return tid;
}

BeamformingCodebook::~BeamformingCodebook()
{
}

void
BeamformingCodebook::DoInitialize()
{
    Object::DoInitialize();
}

} // namespace mmwave
} // namespace ns3
