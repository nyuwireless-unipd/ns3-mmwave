/*
 * mmwave-net-device.cc
 *
 *  Created on: Nov 5, 2014
 *      Author: sourjya
 */

#include <ns3/simulator.h>
#include <ns3/callback.h>
#include <ns3/node.h>
#include <ns3/packet.h>
#include <ns3/log.h>
#include <ns3/ipv4-l3-protocol.h>
#include "mmwave-net-device.h"


namespace ns3{

NS_LOG_COMPONENT_DEFINE ("mmWaveNetDevice");

NS_OBJECT_ENSURE_REGISTERED (mmWaveNetDevice);

TypeId mmWaveNetDevice::GetTypeId ()
{
	static TypeId
	    tid =
	    TypeId ("ns3::mmWaveNetDevice")
	    .SetParent<NetDevice> ()
		.AddAttribute ("Mtu", "The MAC-level Maximum Transmission Unit",
					   UintegerValue (30000),
					   MakeUintegerAccessor (&mmWaveNetDevice::SetMtu,
											 &mmWaveNetDevice::GetMtu),
					   MakeUintegerChecker<uint16_t> ())
;

	return tid;
}

mmWaveNetDevice::mmWaveNetDevice (void)
{
  NS_LOG_FUNCTION (this);
}


mmWaveNetDevice::~mmWaveNetDevice (void)
{
  NS_LOG_FUNCTION (this);
}

void
mmWaveNetDevice::DoDispose (void)
{
	m_node = 0;
	NetDevice::DoDispose ();
}

void
mmWaveNetDevice::SetIfIndex (const uint32_t index)
{
	m_ifIndex = index;
}
uint32_t
mmWaveNetDevice::GetIfIndex (void) const
{
	return m_ifIndex;
}
Ptr<Channel>
mmWaveNetDevice::GetChannel (void) const
{
	return 0;
}
void
mmWaveNetDevice::SetAddress (Address address)
{
	NS_LOG_FUNCTION (this << address);
	m_macaddress = Mac48Address::ConvertFrom (address);
}
Address
mmWaveNetDevice::GetAddress (void) const
{
	NS_LOG_FUNCTION (this);
	return m_macaddress;
}
bool
mmWaveNetDevice::SetMtu (const uint16_t mtu)
{
	m_mtu = mtu;
	return true;
}
uint16_t
mmWaveNetDevice::GetMtu (void) const
{
	return m_mtu;
}
bool
mmWaveNetDevice::IsLinkUp (void) const
{
	return m_linkUp;
}
void
mmWaveNetDevice::AddLinkChangeCallback (Callback<void> callback)
{

}
bool
mmWaveNetDevice::IsBroadcast (void) const
{
	return false;
}
Address
mmWaveNetDevice::GetBroadcast (void) const
{
	return Mac48Address::GetBroadcast ();
}
bool
mmWaveNetDevice::IsMulticast (void) const
{
	return false;
}
Address
mmWaveNetDevice::GetMulticast (Ipv4Address multicastGroup) const
{
	return Mac48Address ("01:00:5e:00:00:00");
}
bool
mmWaveNetDevice::IsBridge (void) const
{
	return false;
}
bool
mmWaveNetDevice::IsPointToPoint (void) const
{
	return false;
}

bool
mmWaveNetDevice::SendFrom (Ptr<Packet> packet, const Address& source, const Address& dest, uint16_t protocolNumber)
{
	NS_FATAL_ERROR ("Send from not supported");
	return false;
}

Ptr<Node>
mmWaveNetDevice::GetNode (void) const
{
	return m_node;
}

void
mmWaveNetDevice::SetNode (Ptr<Node> node)
{
	m_node = node;
}

bool
mmWaveNetDevice::NeedsArp (void) const
{
	return false;
}

Address
mmWaveNetDevice::GetMulticast (Ipv6Address addr) const
{
	Address dummy;
	return dummy;
}

void
mmWaveNetDevice::SetReceiveCallback (ReceiveCallback cb)
{
	NS_LOG_FUNCTION (this);
	m_rxCallback = cb;
}

void
mmWaveNetDevice::SetPromiscReceiveCallback (PromiscReceiveCallback cb)
{

}

bool
mmWaveNetDevice::SupportsSendFrom (void) const
{
	return false;
}

void
mmWaveNetDevice::Receive (Ptr<Packet> p)
{
	NS_LOG_FUNCTION (this << p);
	m_rxCallback (this, p, Ipv4L3Protocol::PROT_NUMBER, Address ());
}

bool
mmWaveNetDevice::Send (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber)
{
	bool ret = DoSend ( packet, dest, protocolNumber);
	return ret;
}

Ipv4Address
mmWaveNetDevice::GetPacketDestination (Ptr<Packet> packet)
{
	Ipv4Address dest_ip;
	Ptr<Packet> q = packet->Copy();

	Ipv4Header ipHeader;
	q->PeekHeader (ipHeader);
	dest_ip = ipHeader.GetDestination();
	return dest_ip;
}


}


