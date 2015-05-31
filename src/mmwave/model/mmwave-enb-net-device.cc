/*
 * mmwave-enb-net-device.cc
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
#include <ns3/uinteger.h>
#include "mmwave-enb-net-device.h"
#include "mmwave-ue-net-device.h"
#include <ns3/lte-enb-rrc.h>
#include <ns3/ipv4-l3-protocol.h>
#include <ns3/abort.h>
#include <ns3/log.h>

namespace ns3{

NS_LOG_COMPONENT_DEFINE ("mmWaveEnbNetDevice");

NS_OBJECT_ENSURE_REGISTERED ( mmWaveEnbNetDevice);

TypeId mmWaveEnbNetDevice::GetTypeId()
{
	static TypeId
	    tid =
	    TypeId ("ns3::mmWaveEnbNetDevice")
	    .SetParent<mmWaveNetDevice> ()
	    .AddConstructor<mmWaveEnbNetDevice> ()
		.AddAttribute ("mmWaveEnbPhy",
			           "The PHY associated to this EnbNetDevice",
			           PointerValue (),
			           MakePointerAccessor (&mmWaveEnbNetDevice::m_phy),
		               MakePointerChecker <mmWaveEnbPhy> ())
		.AddAttribute ("mmWaveEnbMac",
						   "The MAC associated to this EnbNetDevice",
						   PointerValue (),
						   MakePointerAccessor (&mmWaveEnbNetDevice::m_mac),
						   MakePointerChecker <mmWaveEnbMac> ())
		.AddAttribute ("mmWaveScheduler",
						"The Scheduler associated with the MAC",
						PointerValue (),
					    MakePointerAccessor (&mmWaveEnbNetDevice::m_scheduler),
					    MakePointerChecker <mmWaveMacScheduler> ())
		.AddAttribute ("ConnectedLteRRC",
						"The RRC layer associated with the ENB",
						PointerValue (),
						MakePointerAccessor (&mmWaveEnbNetDevice::m_rrc),
						MakePointerChecker <LteEnbRrc> ())
		.AddAttribute ("CellId",
					   "Cell Identifier",
					   UintegerValue (0),
					   MakeUintegerAccessor (&mmWaveEnbNetDevice::m_cellId),
					   MakeUintegerChecker<uint16_t> ())
		.AddAttribute ("AntennaNum",
					   "Antenna number of the device",
					   UintegerValue (64),
					   MakeUintegerAccessor (&mmWaveEnbNetDevice::SetAntennaNum,
											 &mmWaveEnbNetDevice::GetAntennaNum),
					   MakeUintegerChecker<uint8_t> ())
	;

	return tid;
}

mmWaveEnbNetDevice::mmWaveEnbNetDevice()
	:m_cellId(0),
	 m_Bandwidth (72),
	 m_Earfcn(1),
	 m_isConstructed (false),
	 m_isConfigured (false)
{
	NS_LOG_FUNCTION (this);
}

mmWaveEnbNetDevice::~mmWaveEnbNetDevice()
{
	NS_LOG_FUNCTION (this);
}

void
mmWaveEnbNetDevice::DoInitialize(void)
{
	NS_LOG_FUNCTION(this);
	m_isConstructed = true;
	UpdateConfig ();
	m_phy->Initialize ();
}

void
mmWaveEnbNetDevice::DoDispose()
{
	NS_LOG_FUNCTION (this);
}

Ptr<mmWaveEnbPhy>
mmWaveEnbNetDevice::GetPhy (void) const
{
	NS_LOG_FUNCTION (this);
	return m_phy;
}

uint16_t
mmWaveEnbNetDevice::GetCellId () const
{
	NS_LOG_FUNCTION (this);
	return m_cellId;
}

uint8_t
mmWaveEnbNetDevice::GetBandwidth () const
{
	NS_LOG_FUNCTION (this);
	return m_Bandwidth;
}

void
mmWaveEnbNetDevice::SetBandwidth (uint8_t bw)
{
	NS_LOG_FUNCTION (this);
	m_Bandwidth = bw;
}

void
mmWaveEnbNetDevice::SetEarfcn(uint16_t earfcn)
{
	NS_LOG_FUNCTION (this);
	m_Earfcn = earfcn;
}

uint16_t
mmWaveEnbNetDevice::GetEarfcn() const
{
	NS_LOG_FUNCTION (this);
	return m_Earfcn;

}

void
mmWaveEnbNetDevice::SetMac (Ptr<mmWaveEnbMac> mac)
{
	m_mac = mac;
}

Ptr<mmWaveEnbMac>
mmWaveEnbNetDevice::GetMac (void)
{
	return m_mac;
}

void
mmWaveEnbNetDevice::SetRrc (Ptr<LteEnbRrc> rrc)
{
	m_rrc = rrc;
}

Ptr<LteEnbRrc>
mmWaveEnbNetDevice::GetRrc (void)
{
	return m_rrc;
}

void
mmWaveEnbNetDevice::SetAntennaNum (uint8_t antennaNum)
{
	m_antennaNum = antennaNum;
}
uint8_t
mmWaveEnbNetDevice::GetAntennaNum () const
{
	return m_antennaNum;
}

bool
mmWaveEnbNetDevice::DoSend (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber)
{
	NS_LOG_FUNCTION (this << packet   << dest << protocolNumber);
	NS_ASSERT_MSG (protocolNumber == Ipv4L3Protocol::PROT_NUMBER, "unsupported protocol " << protocolNumber << ", only IPv4 is supported");

	return false;
}

void
mmWaveEnbNetDevice::UpdateConfig (void)
{
  NS_LOG_FUNCTION (this);

	if (m_isConstructed)
	{
		if (!m_isConfigured)
		{
			NS_LOG_LOGIC (this << " Configure cell " << m_cellId);
			// we have to make sure that this function is called only once
			m_rrc->ConfigureCell (m_Bandwidth, m_Bandwidth, m_Earfcn, m_Earfcn, m_cellId);
			m_isConfigured = true;
		}

		//m_rrc->SetCsgId (m_csgId, m_csgIndication);
		}
		else
		{
			/*
			* Lower layers are not ready yet, so do nothing now and expect
			* ``DoInitialize`` to re-invoke this function.
			*/
		}
	}

}


