/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 CTTC
 * Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab
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
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *          Dual Connectivity functionalities
 */

#ifndef X2_TAG_H
#define X2_TAG_H

#include "ns3/nstime.h"
#include "ns3/packet.h"

namespace ns3
{

class Tag;

/**
 * Tag to calculate the per-PDU delay on X2 links
 */

class EpcX2Tag : public Tag
{
  public:
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;

    /**
     * Create an empty X2 tag
     */
    EpcX2Tag();
    /**
     * Create an X2 tag with the given senderTimestamp
     */
    EpcX2Tag(Time senderTimestamp);

    virtual void Serialize(TagBuffer i) const;
    virtual void Deserialize(TagBuffer i);
    virtual uint32_t GetSerializedSize() const;
    virtual void Print(std::ostream& os) const;

    /**
     * Get the instant when the X2 delivers the PDU to the MAC SAP provider
     * @return the sender timestamp
     */
    Time GetSenderTimestamp(void) const
    {
        return m_senderTimestamp;
    }

    /**
     * Set the sender timestamp
     * @param senderTimestamp time stamp of the instant when the X2 delivers the PDU
     */
    void SetSenderTimestamp(Time senderTimestamp)
    {
        this->m_senderTimestamp = senderTimestamp;
    }

  private:
    Time m_senderTimestamp;
};

} // namespace ns3

#endif /* X2_TAG_H */
