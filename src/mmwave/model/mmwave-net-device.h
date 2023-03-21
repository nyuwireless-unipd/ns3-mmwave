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

#ifndef SRC_MMWAVE_MODEL_MMWAVE_NET_DEVICE_H_
#define SRC_MMWAVE_MODEL_MMWAVE_NET_DEVICE_H_

#include "mmwave-phy.h"

#include <ns3/event-id.h>
#include <ns3/mac64-address.h>
#include <ns3/net-device.h>
#include <ns3/nstime.h>
#include <ns3/phased-array-model.h>
#include <ns3/traced-callback.h>

namespace ns3
{

class Node;
class Packet;

namespace mmwave
{

class MmWaveComponentCarrier;

class MmWaveNetDevice : public NetDevice
{
  public:
    static TypeId GetTypeId(void);

    MmWaveNetDevice(void);
    virtual ~MmWaveNetDevice(void);

    virtual void DoDispose(void) override;

    virtual void SetIfIndex(const uint32_t index) override;
    virtual uint32_t GetIfIndex(void) const override;
    virtual Ptr<Channel> GetChannel(void) const override;
    virtual void SetAddress(Address address) override;
    virtual Address GetAddress(void) const override;
    virtual bool SetMtu(const uint16_t mtu) override;
    virtual uint16_t GetMtu(void) const override;
    virtual bool IsLinkUp(void) const override;
    virtual void AddLinkChangeCallback(Callback<void> callback) override;
    virtual bool IsBroadcast(void) const override;
    virtual Address GetBroadcast(void) const override;
    virtual bool IsMulticast(void) const override;
    virtual Address GetMulticast(Ipv4Address multicastGroup) const override;
    virtual bool IsBridge(void) const override;
    virtual bool IsPointToPoint(void) const override;
    virtual bool SendFrom(Ptr<Packet> packet,
                          const Address& source,
                          const Address& dest,
                          uint16_t protocolNumber) override;
    virtual Ptr<Node> GetNode(void) const override;
    virtual void SetNode(Ptr<Node> node) override;
    virtual bool NeedsArp(void) const override;
    virtual Address GetMulticast(Ipv6Address addr) const override;
    virtual void SetReceiveCallback(ReceiveCallback cb) override;
    virtual void SetPromiscReceiveCallback(PromiscReceiveCallback cb) override;
    virtual bool SupportsSendFrom(void) const override;
    virtual bool Send(Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber) override;
    virtual bool DoSend(Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber) = 0;

    Ipv4Address GetPacketDestination(Ptr<Packet> packet);

    void Receive(Ptr<Packet> p);

    virtual void SetEarfcn(uint16_t earfcn);
    virtual uint16_t GetEarfcn() const;

    virtual void SetCcMap(std::map<uint8_t, Ptr<MmWaveComponentCarrier>> ccm);
    virtual std::map<uint8_t, Ptr<MmWaveComponentCarrier>> GetCcMap() const;

    /**
     * Get the antenna for the component carrier
     * \param ccId the target Component Carrier ID
     * \return the antenna
     */
    Ptr<PhasedArrayModel> GetAntenna(uint8_t ccId) const;

  protected:
    NetDevice::ReceiveCallback m_rxCallback;

    uint16_t m_earfcn;                                      //!< Carrier frequency
    std::map<uint8_t, Ptr<MmWaveComponentCarrier>> m_ccMap; //!< ComponentCarrier map
    bool m_isConstructed; //!< indicates if the object has been initialized

  private:
    Mac64Address m_macaddress;
    Ptr<Node> m_node;
    mutable uint16_t m_mtu;
    bool m_linkUp;
    uint32_t m_ifIndex;
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_NET_DEVICE_H_ */
