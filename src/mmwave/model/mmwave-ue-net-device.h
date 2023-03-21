/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 *
 *        Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                               Integration of Carrier Aggregation
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_UE_NET_DEVICE_H_
#define SRC_MMWAVE_MODEL_MMWAVE_UE_NET_DEVICE_H_

#include "mmwave-enb-net-device.h"
#include "mmwave-net-device.h"
#include "mmwave-phy.h"
#include "mmwave-ue-mac.h"

#include "ns3/event-id.h"
#include "ns3/nstime.h"
#include "ns3/traced-callback.h"
#include <ns3/epc-ue-nas.h>
#include <ns3/lte-ue-rrc.h>

#include <map>

namespace ns3
{

class Packet;
class PacketBurst;
class Node;
class LteUeComponentCarrierManager;

// class MmWavePhy;

namespace mmwave
{
class MmWaveUePhy;
class MmWaveUeMac;
class MmWaveEnbNetDevice;

class MmWaveUeNetDevice : public MmWaveNetDevice
{
  public:
    static TypeId GetTypeId(void);

    MmWaveUeNetDevice(void);
    virtual ~MmWaveUeNetDevice(void);
    virtual void DoDispose() override;

    uint32_t GetCsgId() const;
    void SetCsgId(uint32_t csgId);

    void UpdateConfig(void);

    virtual bool DoSend(Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber) override;

    Ptr<MmWaveUePhy> GetPhy(void) const;

    Ptr<MmWaveUePhy> GetPhy(uint8_t index) const;

    Ptr<MmWaveUeMac> GetMac(void) const;

    uint64_t GetImsi() const;

    Ptr<EpcUeNas> GetNas(void) const;

    Ptr<LteUeComponentCarrierManager> GetComponentCarrierManager(void) const;

    Ptr<LteUeRrc> GetRrc() const;

    void SetTargetEnb(Ptr<MmWaveEnbNetDevice> enb);

    Ptr<MmWaveEnbNetDevice> GetTargetEnb(void);

  protected:
    // inherited from Object
    virtual void DoInitialize(void) override;

  private:
    MmWaveUeNetDevice(const MmWaveUeNetDevice&);

    Ptr<MmWaveEnbNetDevice> m_targetEnb;

    Ptr<LteUeRrc> m_rrc;
    Ptr<EpcUeNas> m_nas;
    Ptr<LteUeComponentCarrierManager> m_componentCarrierManager; ///< the component carrier manager

    uint64_t m_imsi;

    uint32_t m_csgId;
};

} // namespace mmwave
} // namespace ns3
#endif /* SRC_MMWAVE_MODEL_MMWAVE_UE_NET_DEVICE_H_ */
