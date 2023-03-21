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

#include "mmwave-radio-bearer-tag.h"

#include "ns3/tag.h"
#include "ns3/uinteger.h"

namespace ns3
{

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWaveRadioBearerTag);

TypeId
MmWaveRadioBearerTag::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveRadioBearerTag")
            .SetParent<Tag>()
            .AddConstructor<MmWaveRadioBearerTag>()
            .AddAttribute("rnti",
                          "The rnti that indicates the UE to which packet belongs",
                          UintegerValue(0),
                          MakeUintegerAccessor(&MmWaveRadioBearerTag::GetRnti),
                          MakeUintegerChecker<uint16_t>())
            .AddAttribute(
                "lcid",
                "The id whithin the UE identifying the logical channel to which the packet belongs",
                UintegerValue(0),
                MakeUintegerAccessor(&MmWaveRadioBearerTag::GetLcid),
                MakeUintegerChecker<uint8_t>())
            .AddAttribute("size",
                          "Size in bytes of the RLC PDU",
                          UintegerValue(0),
                          MakeUintegerAccessor(&MmWaveRadioBearerTag::GetSize),
                          MakeUintegerChecker<uint32_t>());
    return tid;
}

TypeId
MmWaveRadioBearerTag::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

MmWaveRadioBearerTag::MmWaveRadioBearerTag()
    : m_rnti(0),
      m_lcid(0),
      m_layer(0),
      m_size(0)
{
}

MmWaveRadioBearerTag::MmWaveRadioBearerTag(uint16_t rnti, uint8_t lcid, uint32_t size)
    : m_rnti(rnti),
      m_lcid(lcid),
      m_size(size)
{
}

MmWaveRadioBearerTag::MmWaveRadioBearerTag(uint16_t rnti,
                                           uint8_t lcid,
                                           uint32_t size,
                                           uint8_t layer)
    : m_rnti(rnti),
      m_lcid(lcid),
      m_layer(layer),
      m_size(size)
{
}

void
MmWaveRadioBearerTag::SetRnti(uint16_t rnti)
{
    m_rnti = rnti;
}

void
MmWaveRadioBearerTag::SetLcid(uint8_t lcid)
{
    m_lcid = lcid;
}

void
MmWaveRadioBearerTag::SetLayer(uint8_t layer)
{
    m_layer = layer;
}

void
MmWaveRadioBearerTag::SetSize(uint32_t size)
{
    m_size = size;
}

uint32_t
MmWaveRadioBearerTag::GetSerializedSize(void) const
{
    return 4;
}

void
MmWaveRadioBearerTag::Serialize(TagBuffer i) const
{
    i.WriteU16(m_rnti);
    i.WriteU8(m_lcid);
    i.WriteU8(m_layer);
    i.WriteU32(m_size);
}

void
MmWaveRadioBearerTag::Deserialize(TagBuffer i)
{
    m_rnti = (uint16_t)i.ReadU16();
    m_lcid = (uint8_t)i.ReadU8();
    m_layer = (uint8_t)i.ReadU8();
}

uint16_t
MmWaveRadioBearerTag::GetRnti() const
{
    return m_rnti;
}

uint8_t
MmWaveRadioBearerTag::GetLcid() const
{
    return m_lcid;
}

uint8_t
MmWaveRadioBearerTag::GetLayer() const
{
    return m_layer;
}

uint32_t
MmWaveRadioBearerTag::GetSize() const
{
    return m_size;
}

void
MmWaveRadioBearerTag::Print(std::ostream& os) const
{
    os << "rnti=" << m_rnti << ", lcid=" << (uint16_t)m_lcid << ", layer=" << (uint16_t)m_layer;
}

} // namespace mmwave

} // namespace ns3
