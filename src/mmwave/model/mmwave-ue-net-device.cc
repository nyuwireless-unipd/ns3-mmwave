/*
 * mmwave-ue-net-device.cc
 *
 *  Created on: Nov 5, 2014
 *      Author: sourjya
 */

#include <ns3/llc-snap-header.h>
#include <ns3/simulator.h>
#include <ns3/callback.h>
#include <ns3/node.h>
#include <ns3/packet.h>
#include "mmwave-net-device.h"
#include <ns3/packet-burst.h>
#include <ns3/uinteger.h>
#include <ns3/trace-source-accessor.h>
#include <ns3/pointer.h>
#include <ns3/enum.h>
#include "mmwave-enb-net-device.h"
#include "mmwave-ue-net-device.h"
#include <ns3/ipv4-header.h>
#include <ns3/ipv4.h>
#include "mmwave-ue-phy.h"
#include <ns3/ipv4-l3-protocol.h>
#include <ns3/log.h>

namespace ns3{

NS_LOG_COMPONENT_DEFINE ("mmWaveUeNetDevice");

NS_OBJECT_ENSURE_REGISTERED (mmWaveUeNetDevice);

TypeId
mmWaveUeNetDevice::GetTypeId (void)
{
	static TypeId
	    tid =
	    TypeId ("ns3::mmWaveUeNetDevice")
	    .SetParent<mmWaveNetDevice> ()
	    .AddConstructor<mmWaveUeNetDevice> ()
		.AddAttribute ("EpcUeNas",
		                   "The NAS associated to this UeNetDevice",
		                   PointerValue (),
		                   MakePointerAccessor (&mmWaveUeNetDevice::m_nas),
		                   MakePointerChecker <EpcUeNas> ())
		.AddAttribute ("mmWaveUeRrc",
		                   "The RRC associated to this UeNetDevice",
		                   PointerValue (),
		                   MakePointerAccessor (&mmWaveUeNetDevice::m_rrc),
		                   MakePointerChecker <LteUeRrc> ())
		.AddAttribute ("mmWaveUePhy",
						"The PHY associated to this UeNetDevice",
						PointerValue (),
						MakePointerAccessor (&mmWaveUeNetDevice::m_phy),
						MakePointerChecker <mmWaveUePhy> ())
		.AddAttribute ("mmWaveUeMac",
						"The MAC associated to this UeNetDevice",
						PointerValue (),
						MakePointerAccessor (&mmWaveUeNetDevice::m_mac),
						MakePointerChecker <mmWaveUeMac> ())
		.AddAttribute ("Imsi",
			 "International Mobile Subscriber Identity assigned to this UE",
			 UintegerValue (0),
			 MakeUintegerAccessor (&mmWaveUeNetDevice::m_imsi),
			 MakeUintegerChecker<uint64_t> ())
		.AddAttribute ("AntennaNum",
					   "Antenna number of the device",
					   UintegerValue (16),
					   MakeUintegerAccessor (&mmWaveUeNetDevice::SetAntennaNum,
											 &mmWaveUeNetDevice::GetAntennaNum),
					   MakeUintegerChecker<uint8_t> ())
	;
	return tid;
}

mmWaveUeNetDevice::mmWaveUeNetDevice (void)
	: m_isConstructed (false)

{
	NS_LOG_FUNCTION (this);
}

mmWaveUeNetDevice::~mmWaveUeNetDevice (void)
{

}

void
mmWaveUeNetDevice::DoInitialize (void)
{
	m_isConstructed = true;
	UpdateConfig ();
	m_phy->DoInitialize ();
	m_rrc->Initialize ();

}
void
mmWaveUeNetDevice::DoDispose ()
{
	m_rrc->Dispose ();
}

uint32_t
mmWaveUeNetDevice::GetCsgId () const
{
  NS_LOG_FUNCTION (this);
  return m_csgId;
}

void
mmWaveUeNetDevice::SetCsgId (uint32_t csgId)
{
  NS_LOG_FUNCTION (this << csgId);
  m_csgId = csgId;
  UpdateConfig (); // propagate the change down to NAS and RRC
}

void
mmWaveUeNetDevice::UpdateConfig (void)
{
  NS_LOG_FUNCTION (this);

  if (m_isConstructed)
    {
      NS_LOG_LOGIC (this << " Updating configuration: IMSI " << m_imsi
                         << " CSG ID " << m_csgId);
      m_nas->SetImsi (m_imsi);
      m_rrc->SetImsi (m_imsi);
      m_nas->SetCsgId (m_csgId); // this also handles propagation to RRC
    }
  else
    {
      /*
       * NAS and RRC instances are not be ready yet, so do nothing now and
       * expect ``DoInitialize`` to re-invoke this function.
       */
    }
}

bool
mmWaveUeNetDevice::DoSend (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber)
{
	NS_LOG_FUNCTION (this << dest << protocolNumber);
    if (protocolNumber != Ipv4L3Protocol::PROT_NUMBER)
	{
	  NS_LOG_INFO("unsupported protocol " << protocolNumber << ", only IPv4 is supported");
	  return true;
	}

    return m_phy->SendPacket (packet);
}

Ptr<mmWaveUePhy>
mmWaveUeNetDevice::GetPhy (void) const
{
	return m_phy; //Inherited from mmwaveNetDevice
}

Ptr<mmWaveUeMac>
mmWaveUeNetDevice::GetMac (void) const
{
	return m_mac;
}

Ptr<EpcUeNas>
mmWaveUeNetDevice::GetNas (void) const
{
  NS_LOG_FUNCTION (this);
  return m_nas;
}


Ptr<LteUeRrc>
mmWaveUeNetDevice::GetRrc (void) const
{
  NS_LOG_FUNCTION (this);
  return m_rrc;
}

uint64_t
mmWaveUeNetDevice::GetImsi () const
{
	return m_imsi;
}

uint16_t
mmWaveUeNetDevice::GetEarfcn () const
{
	return m_earfcn;
}

void
mmWaveUeNetDevice::SetEarfcn (uint16_t earfcn)
{
	m_earfcn = earfcn;
}

void
mmWaveUeNetDevice::SetTargetEnb (Ptr<mmWaveEnbNetDevice> enb)
{
	m_targetEnb = enb;
}

Ptr<mmWaveEnbNetDevice>
mmWaveUeNetDevice::GetTargetEnb (void)
{
	return m_targetEnb;
}

uint8_t
mmWaveUeNetDevice::GetAntennaNum () const
{
	return m_antennaNum;
}

void
mmWaveUeNetDevice::SetAntennaNum (uint8_t antennaNum)
{
	m_antennaNum = antennaNum;
}

}
