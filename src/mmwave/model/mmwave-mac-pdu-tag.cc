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

#include "mmwave-mac-pdu-tag.h"

#include "mmwave-phy-mac-common.h"

#include "ns3/tag.h"
#include "ns3/uinteger.h"

namespace ns3
{

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWaveMacPduTag);

MmWaveMacPduTag::MmWaveMacPduTag(SfnSf sfn, uint8_t numSym)
    : m_sfnSf(sfn),
      m_numSym(numSym),
      m_tagSize(8)
{
}

TypeId
MmWaveMacPduTag::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveMacPduTag").SetParent<Tag>().AddConstructor<MmWaveMacPduTag>();
    return tid;
}

TypeId
MmWaveMacPduTag::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

uint32_t
MmWaveMacPduTag::GetSerializedSize(void) const
{
    return (m_tagSize);
}

void
MmWaveMacPduTag::Serialize(TagBuffer i) const
{
    i.WriteU32(m_sfnSf.m_frameNum);
    i.WriteU8(m_sfnSf.m_sfNum);
    i.WriteU8(m_sfnSf.m_slotNum);
    i.WriteU8(m_sfnSf.m_symStart);
    i.WriteU8(m_numSym);
}

void
MmWaveMacPduTag::Deserialize(TagBuffer i)
{
    m_sfnSf.m_frameNum = i.ReadU32();
    m_sfnSf.m_sfNum = i.ReadU8();
    m_sfnSf.m_slotNum = i.ReadU8();
    m_sfnSf.m_symStart = i.ReadU8();
    m_numSym = i.ReadU8();
    m_tagSize = 8;
}

void
MmWaveMacPduTag::Print(std::ostream& os) const
{
    os << m_sfnSf.m_sfNum << " " << m_sfnSf.m_slotNum;
}

} // namespace mmwave

} // namespace ns3
