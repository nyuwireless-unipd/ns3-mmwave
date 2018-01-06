/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2015 Danilo Abrignani
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
 */

#include "mmwave-component-carrier.h"
#include <ns3/uinteger.h>
#include <ns3/boolean.h>
#include <ns3/simulator.h>
#include <ns3/log.h>
#include <ns3/abort.h>
#include <ns3/mmwave-enb-phy.h>
#include <ns3/pointer.h>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("MmWaveComponentCarrier");

NS_OBJECT_ENSURE_REGISTERED ( MmWaveComponentCarrier);

TypeId MmWaveComponentCarrier::GetTypeId (void)
{
  static TypeId
    tid =
    TypeId ("ns3::MmWaveComponentCarrier")
    .SetParent<Object> ()
    .AddConstructor<MmWaveComponentCarrier> ()
    .AddAttribute ("Bandwidth",
                   "Transmission Bandwidth Configuration in number of Resource Blocks",
                   UintegerValue (25),
                   MakeUintegerAccessor (&MmWaveComponentCarrier::SetUlBandwidth,
                                         &MmWaveComponentCarrier::GetUlBandwidth),
                   MakeUintegerChecker<uint8_t> ())
    .AddAttribute ("Earfcn",
                   "E-UTRA Absolute Radio Frequency Channel Number (EARFCN) "
                   "as per 3GPP 36.101 Section 5.7.3. ",
                   UintegerValue (100),
                   MakeUintegerAccessor (&MmWaveComponentCarrier::m_Earfcn),
                   MakeUintegerChecker<uint32_t> (0, 262143))
    .AddAttribute ("CsgId",
                   "The Closed Subscriber Group (CSG) identity that this eNodeB belongs to",
                   UintegerValue (0),
                   MakeUintegerAccessor (&MmWaveComponentCarrier::SetCsgId,
                                         &MmWaveComponentCarrier::GetCsgId),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("CsgIndication",
                   "If true, only UEs which are members of the CSG (i.e. same CSG ID) "
                   "can gain access to the eNodeB, therefore enforcing closed access mode. "
                   "Otherwise, the eNodeB operates as a non-CSG cell and implements open access mode.",
                   BooleanValue (false),
                   MakeBooleanAccessor (&MmWaveComponentCarrier::SetCsgIndication,
                                        &MmWaveComponentCarrier::GetCsgIndication),
                   MakeBooleanChecker ())
    .AddAttribute ("PrimaryCarrier",
                   "If true, this Carrier Component will be the Primary Carrier Component (PCC) "
                   "Only one PCC per eNodeB is (currently) allowed",
                   BooleanValue (false),
                   MakeBooleanAccessor (&MmWaveComponentCarrier::SetAsPrimary,
                                        &MmWaveComponentCarrier::IsPrimary),
                   MakeBooleanChecker ())
  ;
  return tid;
}
MmWaveComponentCarrier::MmWaveComponentCarrier ()
  : m_isConstructed (false)
{
  NS_LOG_FUNCTION (this);
}

MmWaveComponentCarrier::~MmWaveComponentCarrier (void)
{
  NS_LOG_FUNCTION (this);
}

void
MmWaveComponentCarrier::DoDispose ()
{
  NS_LOG_FUNCTION (this);
  Object::DoDispose ();
}

uint8_t
MmWaveComponentCarrier::GetBandwidth () const
{
  return m_Bandwidth;
}

void
MmWaveComponentCarrier::SetBandwidth (uint8_t bw)
{
  NS_LOG_FUNCTION (this << uint16_t (bw));
  switch (bw)
    {
    case 6:
    case 15:
    case 25:
    case 50:
    case 75:
    case 100:
      m_Bandwidth = bw;
      break;

    default:
      NS_FATAL_ERROR ("Invalid bandwidth value " << (uint16_t) bw);
      break;
    }
}

uint32_t
MmWaveComponentCarrier::GetEarfcn () const
{
  return m_Earfcn;
}

void
MmWaveComponentCarrier::SetEarfcn (uint32_t earfcn)
{
  NS_LOG_FUNCTION (this << earfcn);
  m_Earfcn = earfcn;
}

uint32_t
MmWaveComponentCarrier::GetCsgId () const
{
  return m_csgId;
}

void
MmWaveComponentCarrier::SetCsgId (uint32_t csgId)
{
  NS_LOG_FUNCTION (this << csgId);
  m_csgId = csgId;
}

bool
MmWaveComponentCarrier::GetCsgIndication () const
{
  return m_csgIndication;
}

void
MmWaveComponentCarrier::SetCsgIndication (bool csgIndication)
{
  NS_LOG_FUNCTION (this << csgIndication);
  m_csgIndication = csgIndication;
}

bool
MmWaveComponentCarrier::IsPrimary () const
{
  return m_primaryCarrier;
}

void
MmWaveComponentCarrier::SetAsPrimary (bool primaryCarrier)
{
  NS_LOG_FUNCTION (this << primaryCarrier);
  m_primaryCarrier = primaryCarrier;
}

void
MmWaveComponentCarrier::DoInitialize (void)
{
  NS_LOG_FUNCTION (this);
  m_isConstructed = true;
}

} // namespace ns3
