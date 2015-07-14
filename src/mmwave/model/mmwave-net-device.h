/*
 * mmwave-net-device.h
 *
 *  Created on: Nov 4, 2014
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_NET_DEVICE_H_
#define SRC_MMWAVE_MODEL_MMWAVE_NET_DEVICE_H_



#include <ns3/net-device.h>
#include <ns3/event-id.h>
#include <ns3/mac48-address.h>
#include <ns3/traced-callback.h>
#include <ns3/nstime.h>
#include "mmwave-phy.h"

namespace ns3{

class Node;
class Packet;

class MmWaveNetDevice : public NetDevice
{
public:
	static TypeId GetTypeId (void);

	MmWaveNetDevice (void);
	virtual ~MmWaveNetDevice (void);

    virtual void DoDispose (void);

    virtual void SetIfIndex (const uint32_t index);
    virtual uint32_t GetIfIndex (void) const;
    virtual Ptr<Channel> GetChannel (void) const;
    virtual void SetAddress (Address address);
    virtual Address GetAddress (void) const;
    virtual bool SetMtu (const uint16_t mtu);
    virtual uint16_t GetMtu (void) const;
    virtual bool IsLinkUp (void) const;
    virtual void AddLinkChangeCallback (Callback<void> callback);
    virtual bool IsBroadcast (void) const;
    virtual Address GetBroadcast (void) const;
    virtual bool IsMulticast (void) const;
    virtual Address GetMulticast (Ipv4Address multicastGroup) const;
    virtual bool IsBridge (void) const;
    virtual bool IsPointToPoint (void) const;
    virtual bool SendFrom (Ptr<Packet> packet, const Address& source, const Address& dest, uint16_t protocolNumber);
    virtual Ptr<Node> GetNode (void) const;
    virtual void SetNode (Ptr<Node> node);
    virtual bool NeedsArp (void) const;
    virtual Address GetMulticast (Ipv6Address addr) const;
    virtual void SetReceiveCallback (ReceiveCallback cb);
    virtual void SetPromiscReceiveCallback (PromiscReceiveCallback cb);
    virtual bool SupportsSendFrom (void) const;
    virtual bool Send (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber);
    virtual bool DoSend (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber) = 0;

    Ipv4Address GetPacketDestination (Ptr<Packet> packet);

    void Receive (Ptr<Packet> p);
protected:
    NetDevice::ReceiveCallback m_rxCallback;
private:
    Mac48Address m_macaddress;
    Ptr<Node> m_node;
    mutable uint16_t m_mtu;
    bool m_linkUp;
    uint32_t m_ifIndex;

};

}

#endif /* SRC_MMWAVE_MODEL_MMWAVE_NET_DEVICE_H_ */
