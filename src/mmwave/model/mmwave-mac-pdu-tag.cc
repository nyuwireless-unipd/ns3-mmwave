/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 CTTC
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
 * Author: Jaume Nin <jaume.nin@cttc.es>
 */

#include "mmwave-mac-pdu-tag.h"
#include "ns3/tag.h"
#include "ns3/uinteger.h"

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (MmWaveMacPduTag);

MmWaveMacPduTag::MmWaveMacPduTag () : m_tagSize (2)
{
}

MmWaveMacPduTag::MmWaveMacPduTag (uint16_t frameNum, uint8_t sfNum, uint8_t slotNum)
  :  m_frameNum (frameNum), m_sfNum (sfNum), m_slotNum (slotNum)
{
	m_tagSize = 2;
}

TypeId
MmWaveMacPduTag::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::MmWaveMacPduTag")
    .SetParent<Header> ()
    .AddConstructor<MmWaveMacPduTag> ();
  return tid;
}

TypeId
MmWaveMacPduTag::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

uint32_t
MmWaveMacPduTag::GetSerializedSize (void) const
{
  return (m_tagSize);
}

void
MmWaveMacPduTag::Serialize (TagBuffer i) const
{
	i.WriteU8 (m_sfNum);
	i.WriteU8 (m_slotNum);
}

void
MmWaveMacPduTag::Deserialize (TagBuffer i)
{
	m_sfNum = (uint8_t)i.ReadU8 ();
	m_slotNum = (uint8_t)i.ReadU8 ();
	m_tagSize = 2;
}

void
MmWaveMacPduTag::Print (std::ostream &os) const
{
  os << m_frameNum << " " << m_sfNum << " " << m_slotNum;
}

} // namespace ns3

