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

#ifndef MMWAVE_MAC_PDU_TAG_H
#define MMWAVE_MAC_PDU_TAG_H

#include "mmwave-phy-mac-common.h"

#include "ns3/nstime.h"
#include "ns3/packet.h"

namespace ns3
{

namespace mmwave
{

struct SfnSf;

class MmWaveMacPduTag : public Tag
{
  public:
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;

    MmWaveMacPduTag(SfnSf sfn = SfnSf(), uint8_t numSym = 0);

    virtual void Serialize(TagBuffer i) const;
    virtual void Deserialize(TagBuffer i);
    virtual uint32_t GetSerializedSize() const;
    virtual void Print(std::ostream& os) const;

    SfnSf GetSfn() const
    {
        return m_sfnSf;
    }

    void SetSfn(SfnSf sfn)
    {
        this->m_sfnSf = sfn;
    }

    void SetNumSym(uint8_t numSym)
    {
        m_numSym = numSym;
    }

  protected:
    SfnSf m_sfnSf;
    uint8_t m_numSym;
    uint32_t m_tagSize; //!< the tag size, expressed in number of bytes
};

} // namespace mmwave

} // namespace ns3

#endif /* MMWAVE_MAC_PDU_TAG_H */
