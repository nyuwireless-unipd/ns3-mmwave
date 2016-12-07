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
 *        	 	  Sourjya Dutta <sdutta@nyu.edu>
 *        	 	  Russell Ford <russell.ford@nyu.edu>
 *        		  Menglei Zhang <menglei@nyu.edu>
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

NS_LOG_COMPONENT_DEFINE ("MmWaveEnbNetDevice");

NS_OBJECT_ENSURE_REGISTERED ( MmWaveEnbNetDevice);

TypeId MmWaveEnbNetDevice::GetTypeId()
{
	static TypeId
	    tid =
	    TypeId ("ns3::MmWaveEnbNetDevice")
	    .SetParent<MmWaveNetDevice> ()
	    .AddConstructor<MmWaveEnbNetDevice> ()
		.AddAttribute ("MmWaveEnbPhy",
			           "The PHY associated to this EnbNetDevice",
			           PointerValue (),
			           MakePointerAccessor (&MmWaveEnbNetDevice::m_phy),
		               MakePointerChecker <MmWaveEnbPhy> ())
		.AddAttribute ("MmWaveEnbMac",
						   "The MAC associated to this EnbNetDevice",
						   PointerValue (),
						   MakePointerAccessor (&MmWaveEnbNetDevice::m_mac),
						   MakePointerChecker <MmWaveEnbMac> ())
		.AddAttribute ("mmWaveScheduler",
						"The Scheduler associated with the MAC",
						PointerValue (),
					    MakePointerAccessor (&MmWaveEnbNetDevice::m_scheduler),
					    MakePointerChecker <MmWaveMacScheduler> ())
		.AddAttribute ("LteEnbRrc",
						"The RRC layer associated with the ENB",
						PointerValue (),
						MakePointerAccessor (&MmWaveEnbNetDevice::m_rrc),
						MakePointerChecker <LteEnbRrc> ())
		.AddAttribute ("CellId",
					   "Cell Identifier",
					   UintegerValue (0),
					   MakeUintegerAccessor (&MmWaveEnbNetDevice::m_cellId),
					   MakeUintegerChecker<uint16_t> ())
		.AddAttribute ("AntennaNum",
					   "Antenna number of the device",
					   UintegerValue (64),
					   MakeUintegerAccessor (&MmWaveEnbNetDevice::SetAntennaNum,
											 &MmWaveEnbNetDevice::GetAntennaNum),
					   MakeUintegerChecker<uint8_t> ())
	;

	return tid;
}

MmWaveEnbNetDevice::MmWaveEnbNetDevice()
	:m_cellId(0),
	 m_Bandwidth (72),
	 m_Earfcn(1),
	 m_isConstructed (false),
	 m_isConfigured (false)
{
	NS_LOG_FUNCTION (this);
}

MmWaveEnbNetDevice::~MmWaveEnbNetDevice()
{
	NS_LOG_FUNCTION (this);
}

void
MmWaveEnbNetDevice::DoInitialize(void)
{
	NS_LOG_FUNCTION(this);
	m_isConstructed = true;
	UpdateConfig ();
	m_phy->Initialize ();
}

void
MmWaveEnbNetDevice::DoDispose()
{
	NS_LOG_FUNCTION (this);
}

Ptr<MmWaveEnbPhy>
MmWaveEnbNetDevice::GetPhy (void) const
{
	NS_LOG_FUNCTION (this);
	return m_phy;
}

uint16_t
MmWaveEnbNetDevice::GetCellId () const
{
	NS_LOG_FUNCTION (this);
	return m_cellId;
}

uint8_t
MmWaveEnbNetDevice::GetBandwidth () const
{
	NS_LOG_FUNCTION (this);
	return m_Bandwidth;
}

void
MmWaveEnbNetDevice::SetBandwidth (uint8_t bw)
{
	NS_LOG_FUNCTION (this);
	m_Bandwidth = bw;
}

void
MmWaveEnbNetDevice::SetEarfcn(uint16_t earfcn)
{
	NS_LOG_FUNCTION (this);
	m_Earfcn = earfcn;
}

uint16_t
MmWaveEnbNetDevice::GetEarfcn() const
{
	NS_LOG_FUNCTION (this);
	return m_Earfcn;

}

void
MmWaveEnbNetDevice::SetMac (Ptr<MmWaveEnbMac> mac)
{
	m_mac = mac;
}

Ptr<MmWaveEnbMac>
MmWaveEnbNetDevice::GetMac (void)
{
	return m_mac;
}

void
MmWaveEnbNetDevice::SetRrc (Ptr<LteEnbRrc> rrc)
{
	m_rrc = rrc;
}

Ptr<LteEnbRrc>
MmWaveEnbNetDevice::GetRrc (void)
{
	return m_rrc;
}

void
MmWaveEnbNetDevice::SetAntennaNum (uint8_t antennaNum)
{
	m_antennaNum = antennaNum;
}
uint8_t
MmWaveEnbNetDevice::GetAntennaNum () const
{
	return m_antennaNum;
}

bool
MmWaveEnbNetDevice::DoSend (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber)
{
	NS_LOG_FUNCTION (this << packet   << dest << protocolNumber);
	NS_ASSERT_MSG (protocolNumber == Ipv4L3Protocol::PROT_NUMBER, "unsupported protocol " << protocolNumber << ", only IPv4 is supported");

	return m_rrc->SendData (packet);
}

void
MmWaveEnbNetDevice::UpdateConfig (void)
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


