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

#ifndef MMWAVE_COMPONENT_CARRIER_ENB_H
#define MMWAVE_COMPONENT_CARRIER_ENB_H

#include "mmwave-component-carrier.h"

#include "ns3/mmwave-phy.h"
#include <ns3/mmwave-enb-phy.h>
#include <ns3/nstime.h>
#include <ns3/object.h>
#include <ns3/packet.h>
#include <ns3/pointer.h>

//#include <ns3/lte-enb-mac.h>

namespace ns3
{

namespace mmwave
{

class MmWaveEnbMac;

/**
 * \ingroup mmwave
 *
 * Defines a single carrier for enb, and contains pointers to MmWaveEnbPhy,
 * MmWaveEnbMac objects.
 *
 */
class MmWaveComponentCarrierEnb : public MmWaveComponentCarrier
{
  public:
    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);

    MmWaveComponentCarrierEnb();

    virtual ~MmWaveComponentCarrierEnb(void);
    virtual void DoDispose(void) override;

    /**
     * Get cell identifier
     * \return cell identifer
     */
    uint16_t GetCellId();

    /**
     * \return a pointer to the physical layer.
     */
    Ptr<MmWaveEnbPhy> GetPhy(void);

    /**
     * \return a pointer to the MAC layer.
     */
    Ptr<MmWaveEnbMac> GetMac(void);

    /**
     * \return a pointer to the Ffr Algorithm.
     */
    // Ptr<LteFfrAlgorithm> GetFfrAlgorithm ();

    /**
     * \return a pointer to the Mac Scheduler.
     */
    Ptr<MmWaveMacScheduler> GetMacScheduler();

    /**
     * Set physical cell identifier
     * \param cellId cell identifier
     */
    void SetCellId(uint16_t cellId);

    /**
     * Set the LteEnbPhy
     * \param s a pointer to the LteEnbPhy
     */
    void SetPhy(Ptr<MmWaveEnbPhy> s);
    /**
     * Set the LteEnbMac
     * \param s a pointer to the LteEnbMac
     */
    void SetMac(Ptr<MmWaveEnbMac> s);

    /**
     * Set the FfMacScheduler Algorithm
     * \param s a pointer to the FfMacScheduler
     */
    void SetMacScheduler(Ptr<MmWaveMacScheduler> s);

    // void SetFfrAlgorithm (Ptr<LteFfrAlgorithm> s);

  protected:
    virtual void DoInitialize(void) override;

  private:
    uint16_t m_cellId;       ///< Cell identifer
    Ptr<MmWaveEnbPhy> m_phy; ///< the Phy instance of this eNodeB component carrier
    Ptr<MmWaveEnbMac> m_mac; ///< the MAC instance of this eNodeB component carrier
    Ptr<MmWaveMacScheduler>
        m_scheduler; ///< the scheduler instance of this eNodeB component carrier
    // Ptr<LteFfrAlgorithm> m_ffrAlgorithm; ///< the FFR algorithm instance of this eNodeB component
    // carrier
};

} // namespace mmwave

} // namespace ns3

#endif /* MMWAVE_COMPONENT_CARRIER_H */
