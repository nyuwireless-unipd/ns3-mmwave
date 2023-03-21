/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2015 Danilo Abrignani
 * Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 * Author: Danilo Abrignani <danilo.abrignani@unibo.it>
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                               Integration of Carrier Aggregation
 */

#ifndef MMWAVE_COMPONENT_CARRIER_UE_H
#define MMWAVE_COMPONENT_CARRIER_UE_H

#include "ns3/mmwave-phy.h"
#include <ns3/mmwave-component-carrier.h>
#include <ns3/mmwave-ue-phy.h>
#include <ns3/nstime.h>
#include <ns3/object.h>
#include <ns3/packet.h>

namespace ns3
{

namespace mmwave
{

class MmWaveUeMac;

/**
 * \ingroup lte
 *
 * ComponentCarrierUe Object, it defines a single Carrier for the Ue
 */
class MmWaveComponentCarrierUe : public MmWaveComponentCarrier
{
  public:
    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);

    MmWaveComponentCarrierUe();

    virtual ~MmWaveComponentCarrierUe(void);
    virtual void DoDispose(void) override;

    /**
     * \return a pointer to the physical layer.
     */
    Ptr<MmWaveUePhy> GetPhy(void) const;

    /**
     * \return a pointer to the MAC layer.
     */
    Ptr<MmWaveUeMac> GetMac(void) const;

    /**
     * Set MmWaveUePhy
     * \param s a pointer to the MmWaveUePhy
     */
    void SetPhy(Ptr<MmWaveUePhy> s);

    /**
     * Set the MmWaveEnbMac
     * \param s a pointer to the MmWaveEnbMac
     */
    void SetMac(Ptr<MmWaveUeMac> s);

  protected:
    // inherited from Object
    virtual void DoInitialize(void) override;

  private:
    Ptr<MmWaveUePhy> m_phy; ///< the Phy instance of this eNodeB component carrier
    Ptr<MmWaveUeMac> m_mac; ///< the MAC instance of this eNodeB component carrier
};

} // namespace mmwave

} // namespace ns3

#endif /* MMWAVE_COMPONENT_CARRIER_UE_H */
