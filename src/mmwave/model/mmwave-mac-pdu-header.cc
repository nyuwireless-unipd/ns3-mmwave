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

#include "mmwave-mac-pdu-header.h"

#include "ns3/tag.h"
#include "ns3/uinteger.h"

namespace ns3
{

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWaveMacPduHeader);

MmWaveMacPduHeader::MmWaveMacPduHeader()
    : m_headerSize(0)
{
}

TypeId
MmWaveMacPduHeader::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveMacPduHeader").SetParent<Header>().AddConstructor<MmWaveMacPduHeader>();
    return tid;
}

TypeId
MmWaveMacPduHeader::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

uint32_t
MmWaveMacPduHeader::GetSerializedSize(void) const
{
    return (m_headerSize);
}

void
MmWaveMacPduHeader::Serialize(Buffer::Iterator i) const
{
    // RDF TODO: implement BSR MAC control elements

    // this part builds the MAC sub-header format from 36.321 sec 6.1.2
    for (unsigned ipdu = 0; ipdu < m_subheaderList.size(); ipdu++)
    {
        // first octet R/R/E/LCID (R=reserved bit, E=extension bit)
        uint8_t octet1 = m_subheaderList[ipdu].m_lcid & 0x1F;
        if (ipdu < (m_subheaderList.size() - 1)) // not the last subheader
        {
            octet1 |= (1 << 5);
        }
        i.WriteU8(octet1);
        // second octet F/Length (F=1 if length > 127 bits)
        uint8_t octet2 = (m_subheaderList[ipdu].m_size & 0x7F);
        // third octet = upper 8 bits of length if length > 127
        uint8_t octet3 = 0;
        if (m_subheaderList[ipdu].m_size > 0x7F)
        {
            octet2 |= (1 << 7);
            octet3 = ((m_subheaderList[ipdu].m_size >> 7) & 0x7F);
            i.WriteU8(octet2);
            if (m_subheaderList[ipdu].m_size > 0x3FFF)
            {
                octet3 |= (1 << 7); // write extension flag 2
                uint8_t octet4 = ((m_subheaderList[ipdu].m_size >> 14) & 0xFF);
                i.WriteU8(octet3);
                i.WriteU8(octet4);
            }
            else
            {
                i.WriteU8(octet3);
            }
        }
        else
        {
            i.WriteU8(octet2);
        }
    }
}

uint32_t
MmWaveMacPduHeader::Deserialize(Buffer::Iterator i)
{
    // decode sub-headers and create RLC info elements
    m_headerSize = 0;
    bool done = false;
    while (!done)
    {
        uint8_t octet1 = (uint8_t)i.ReadU8();
        uint8_t lcid = (octet1 & 0x1F);
        if (!(octet1 >> 5)) // extension bit not set
        {
            done = true;
        }
        uint8_t octet2 = (uint8_t)i.ReadU8();
        bool flag = octet2 >> 7;
        uint32_t size = (octet2 & 0x7F);
        if (flag) // size > 127
        {
            uint8_t octet3 = (uint8_t)i.ReadU8();
            size |= (octet3 & 0x7F) << 7;
            bool flag2 = (octet3 >> 7);
            if (flag2)
            {
                uint8_t octet4 = (uint8_t)i.ReadU8();
                size |= (octet4 << 14);
                m_headerSize += 4;
            }
            else
            {
                m_headerSize += 3;
            }
        }
        else
        {
            m_headerSize += 2;
        }
        m_subheaderList.push_back(MacSubheader(lcid, size));
    }

    return m_headerSize;
}

void
MmWaveMacPduHeader::Print(std::ostream& os) const
{
}

void
MmWaveMacPduHeader::AddSubheader(MacSubheader macSubheader)
{
    this->m_subheaderList.push_back(macSubheader);
    if (macSubheader.m_size > 0x3FFF)
    {
        m_headerSize += 4;
    }
    else if (macSubheader.m_size > 0x7F)
    {
        m_headerSize += 3;
    }
    else
    {
        m_headerSize += 2;
    }
}

} // namespace mmwave

} // namespace ns3
