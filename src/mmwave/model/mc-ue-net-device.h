/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/* *
 * Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 * Author: Michele Polese <michele.polese@gmail.com>
 *
 */

#ifndef MC_UE_NET_DEVICE_H
#define MC_UE_NET_DEVICE_H

#include "ns3/component-carrier-ue.h"
#include "ns3/epc-ue-nas.h"
#include "ns3/lte-phy.h"
#include "ns3/lte-ue-mac.h"
#include "ns3/lte-ue-phy.h"
#include "ns3/lte-ue-rrc.h"
#include "ns3/mmwave-component-carrier-ue.h"
#include "ns3/mmwave-ue-mac.h"
#include "ns3/mmwave-ue-phy.h"
#include <ns3/event-id.h>
#include <ns3/mac48-address.h>
#include <ns3/net-device.h>
#include <ns3/nstime.h>
#include <ns3/traced-callback.h>

//#include "ns3/mmwave-enb-net-device.h"
//#include "ns3/lte-enb-net-device.h"
//#include "ns3/lte-ue-net-device.h"
//#include "ns3/mmwave-ue-net-device.h"

namespace ns3
{

class Packet;
class PacketBurst;
class Node;
class LteEnbNetDevice;
class LteUeComponentCarrierManager;

namespace mmwave
{

class MmWaveEnbNetDevice;

/**
 * \ingroup mmWave
 * This class represents a MC LTE + mmWave UE NetDevice, therefore
 * it is a union of the UeNetDevice classes of those modules,
 * up to some point
 */
class McUeNetDevice : public NetDevice
{
  public:
    // methods inherited from NetDevide.
    // TODO check if 2 (or more) Mac Addresses are needed or if the
    // same can be used for the 2 (or more) eNB

    static TypeId GetTypeId(void);

    McUeNetDevice();
    virtual ~McUeNetDevice();

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

    Ipv4Address GetPacketDestination(Ptr<Packet> packet);

    /**
     * receive a packet from the lower layers in order to forward it to the upper layers
     *
     * \param p the packet
     */
    void Receive(Ptr<Packet> p);

    // ---------------------------- Common ----------------------------
    /**
     * \brief Returns the CSG ID the UE is currently a member of.
     * \return the Closed Subscriber Group identity
     */
    uint32_t GetCsgId() const;

    /**
     * \brief Enlist the UE device as a member of a particular CSG.
     * \param csgId the intended Closed Subscriber Group identity
     *
     * UE is associated with a single CSG identity, and thus becoming a member of
     * this particular CSG. As a result, the UE may gain access to cells which
     * belong to this CSG. This does not revoke the UE's access to non-CSG cells.
     *
     * \note This restriction only applies to initial cell selection and
     *       EPC-enabled simulation.
     */
    void SetCsgId(uint32_t csgId);

    Ptr<EpcUeNas> GetNas(void) const;

    uint64_t GetImsi() const;

    // -------------------------- LTE methods -------------------------
    Ptr<LteUeMac> GetLteMac(void) const;

    Ptr<LteUeMac> GetLteMac(uint8_t index) const;

    Ptr<LteUeRrc> GetLteRrc() const;

    Ptr<LteUeComponentCarrierManager> GetLteComponentCarrierManager(void) const;

    Ptr<LteUePhy> GetLtePhy(void) const;

    Ptr<LteUePhy> GetLtePhy(uint8_t index) const;

    std::map<uint8_t, Ptr<ComponentCarrierUe>> GetLteCcMap();

    void SetLteCcMap(std::map<uint8_t, Ptr<ComponentCarrierUe>> ccm);

    /**
     * \return the downlink carrier frequency (EARFCN)
     *
     * Note that real-life handset typically supports more than one EARFCN, but
     * the sake of simplicity we assume only one EARFCN is supported.
     */
    uint16_t GetLteDlEarfcn() const;

    /**
     * \param earfcn the downlink carrier frequency (EARFCN)
     *
     * Note that real-life handset typically supports more than one EARFCN, but
     * the sake of simplicity we assume only one EARFCN is supported.
     */
    void SetLteDlEarfcn(uint16_t earfcn);

    /**
     * \brief Set the targer eNB where the UE is registered
     * \param enb
     */
    void SetLteTargetEnb(Ptr<LteEnbNetDevice> enb);

    /**
     * \brief Get the targer eNB where the UE is registered
     * \return the pointer to the enb
     */
    Ptr<LteEnbNetDevice> GetLteTargetEnb(void);

    // ---------------------------- From mmWave ------------------------

    Ptr<MmWaveUePhy> GetMmWavePhy(void) const;

    Ptr<MmWaveUePhy> GetMmWavePhy(uint8_t index) const;

    Ptr<MmWaveUeMac> GetMmWaveMac(void) const;

    Ptr<MmWaveUeMac> GetMmWaveMac(uint8_t index) const;

    std::map<uint8_t, Ptr<MmWaveComponentCarrierUe>> GetMmWaveCcMap();

    void SetMmWaveCcMap(std::map<uint8_t, Ptr<MmWaveComponentCarrierUe>> ccm);

    Ptr<LteUeRrc> GetMmWaveRrc() const;

    Ptr<LteUeComponentCarrierManager> GetMmWaveComponentCarrierManager(void) const;

    uint16_t GetMmWaveEarfcn() const;

    void SetMmWaveEarfcn(uint16_t earfcn);

    void SetMmWaveTargetEnb(Ptr<MmWaveEnbNetDevice> enb);

    Ptr<MmWaveEnbNetDevice> GetMmWaveTargetEnb(void);

    void SetAntennaNum(uint16_t antennaNum);

    uint16_t GetAntennaNum() const;

    /**
     * Get the antenna for the given mmWave component carrier
     * \param ccId the target mmwave Component Carrier ID
     * \return the antenna
     */
    Ptr<PhasedArrayModel> GetAntenna(uint8_t ccId) const;

  protected:
    NetDevice::ReceiveCallback m_rxCallback;
    virtual void DoInitialize(void) override;

  private:
    McUeNetDevice(const McUeNetDevice&);

    Mac64Address m_macaddress;
    Ptr<Node> m_node;
    mutable uint16_t m_mtu;
    bool m_linkUp;
    uint32_t m_ifIndex;

    // From LTE
    bool m_isConstructed;
    TracedCallback<> m_linkChangeCallbacks;

    /**
     * \brief Propagate attributes and configuration to sub-modules.
     *
     * Several attributes (e.g., the IMSI) are exported as the attributes of the
     * McUeNetDevice from a user perspective, but are actually used also in other
     * sub-modules (the RRC, the PHY, etc.). This method takes care of updating
     * the configuration of all these sub-modules so that their copy of attribute
     * values are in sync with the one in the McUeNetDevice.
     */
    void UpdateConfig();

    bool DoSend(Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber);
    // LTE

    Ptr<LteEnbNetDevice> m_lteTargetEnb;
    Ptr<LteUeRrc> m_lteRrc;
    Ptr<LteUeComponentCarrierManager>
        m_lteComponentCarrierManager;                      ///< LTE component carrier manager
    std::map<uint8_t, Ptr<ComponentCarrierUe>> m_lteCcMap; ///< LTE CC map
    uint16_t m_lteDlEarfcn;                                /**< LTE downlink carrier frequency */

    // MmWave
    Ptr<MmWaveEnbNetDevice> m_mmWaveTargetEnb;
    Ptr<LteUeRrc> m_mmWaveRrc; // TODO consider a lightweight RRC for the mmwave part
    Ptr<LteUeComponentCarrierManager>
        m_mmWaveComponentCarrierManager; ///< mmWave component carrier manager
    std::map<uint8_t, Ptr<MmWaveComponentCarrierUe>> m_mmWaveCcMap; ///< mmWave CC map
    uint16_t m_mmWaveEarfcn;                                        /**< MmWave carrier frequency */
    uint16_t m_mmWaveAntennaNum;

    // Common
    Ptr<EpcUeNas> m_nas;
    uint64_t m_imsi;
    uint32_t m_csgId;

    // TODO this will be useless
    Ptr<UniformRandomVariable> m_random;
};

} // namespace mmwave

} // namespace ns3

#endif
// MC_UE_NET_DEVICE_H
