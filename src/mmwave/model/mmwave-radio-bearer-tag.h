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

#ifndef SRC_MMWAVE_MODEL_MMWAVE_RADIO_BEARER_TAG_H_
#define SRC_MMWAVE_MODEL_MMWAVE_RADIO_BEARER_TAG_H_

#include "ns3/tag.h"

namespace ns3
{

class Tag;

namespace mmwave
{

/**
 * Tag used to define the RNTI and LC id for each MAC packet trasmitted
 */

class MmWaveRadioBearerTag : public Tag
{
  public:
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;

    /**
     * Create an empty MmWaveRadioBearerTag
     */
    MmWaveRadioBearerTag();

    /**
     * Create a MmWaveRadioBearerTag with the given RNTI and LC id
     */
    MmWaveRadioBearerTag(uint16_t rnti, uint8_t lcId, uint32_t size);

    /**
     * Create a MmWaveRadioBearerTag with the given RNTI, LC id and layer
     */
    MmWaveRadioBearerTag(uint16_t rnti, uint8_t lcId, uint32_t size, uint8_t layer);

    /**
     * Set the RNTI to the given value.
     *
     * @param rnti the value of the RNTI to set
     */
    void SetRnti(uint16_t rnti);

    /**
     * Set the LC id to the given value.
     *
     * @param lcid the value of the RNTI to set
     */
    void SetLcid(uint8_t lcid);

    /**
     * Set the layer id to the given value.
     *
     * @param layer the value of the layer to set
     */
    void SetLayer(uint8_t layer);

    /**
     * Set the size of the RLC PDU in bytes.
     *
     * @param size the size of the RLC PDU in bytes
     */
    void SetSize(uint32_t size);

    virtual void Serialize(TagBuffer i) const;
    virtual void Deserialize(TagBuffer i);
    virtual uint32_t GetSerializedSize() const;
    virtual void Print(std::ostream& os) const;

    uint16_t GetRnti(void) const;
    uint8_t GetLcid(void) const;
    uint8_t GetLayer(void) const;
    uint32_t GetSize(void) const;

  private:
    uint16_t m_rnti;
    uint8_t m_lcid;
    uint8_t m_layer;
    uint32_t m_size; // size in bytes of RLC PDU
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_RADIO_BEARER_TAG_H_ */
