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

#ifndef MMWAVE_MAC_PDU_HEADER_H
#define MMWAVE_MAC_PDU_HEADER_H

#include "ns3/nstime.h"
#include "ns3/packet.h"

namespace ns3
{

class Tag;

namespace mmwave
{

struct MacSubheader
{
    MacSubheader()
        : m_lcid(0),
          m_size(0)
    {
    }

    MacSubheader(uint8_t lcid, uint32_t size)
        : m_lcid(lcid),
          m_size(size)
    {
    }

    uint32_t GetSize()
    {
        if (m_size > 127)
        {
            return 3;
        }
        else
        {
            return 2;
        }
    }

    uint8_t m_lcid;
    uint32_t m_size; // 22 bits
};

class MmWaveMacPduHeader : public Header
{
  public:
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;

    /**
     * Create an empty Mac header
     */
    MmWaveMacPduHeader();

    MmWaveMacPduHeader(uint16_t frameNo, uint8_t sfNo, uint8_t slotNo);

    virtual void Serialize(Buffer::Iterator i) const;
    virtual uint32_t Deserialize(Buffer::Iterator i);
    virtual uint32_t GetSerializedSize() const;
    virtual void Print(std::ostream& os) const;
    void AddSubheader(MacSubheader rlcPduInfo);

    void SetSubheaders(std::vector<MacSubheader> macSubheaderList)
    {
        m_subheaderList = macSubheaderList;
    }

    std::vector<MacSubheader> GetSubheaders(void)
    {
        return m_subheaderList;
    }

  protected:
    std::vector<MacSubheader> m_subheaderList;
    uint32_t m_headerSize;
};

} // namespace mmwave

} // namespace ns3

#endif /* MMWAVE_MAC_PDU_HEADER_H */
