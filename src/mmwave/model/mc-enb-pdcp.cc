/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011-2012 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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
 * Author: Manuel Requena <manuel.requena@cttc.es>
 */

#include "ns3/log.h"
#include "ns3/simulator.h"

#include "ns3/mc-enb-pdcp.h"
#include "ns3/lte-pdcp-header.h"
#include "ns3/lte-pdcp-sap.h"
#include "ns3/lte-pdcp-tag.h"
#include "ns3/epc-x2-sap.h"


namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("McEnbPdcp");

class McPdcpSpecificLteRlcSapUser : public LteRlcSapUser
{
public:
  McPdcpSpecificLteRlcSapUser (McEnbPdcp* pdcp);

  // Interface provided to lower RLC entity (implemented from LteRlcSapUser)
  virtual void ReceivePdcpPdu (Ptr<Packet> p);

private:
  McPdcpSpecificLteRlcSapUser ();
  McEnbPdcp* m_pdcp;
};

McPdcpSpecificLteRlcSapUser::McPdcpSpecificLteRlcSapUser (McEnbPdcp* pdcp)
  : m_pdcp (pdcp)
{
}

McPdcpSpecificLteRlcSapUser::McPdcpSpecificLteRlcSapUser ()
{
}

void
McPdcpSpecificLteRlcSapUser::ReceivePdcpPdu (Ptr<Packet> p)
{
  m_pdcp->DoReceivePdu (p);
}

///////////////////////////////////////

NS_OBJECT_ENSURE_REGISTERED (McEnbPdcp);

McEnbPdcp::McEnbPdcp ()
  : m_pdcpSapUser (0),
    m_rlcSapProvider (0),
    m_rnti (0),
    m_lcid (0),
    m_epcX2PdcpProvider (0),
    m_txSequenceNumber (0),
    m_rxSequenceNumber (0),
    m_useMmWaveConnection (false)
{
  NS_LOG_FUNCTION (this);
  m_pdcpSapProvider = new LtePdcpSpecificLtePdcpSapProvider<McEnbPdcp> (this);
  m_rlcSapUser = new McPdcpSpecificLteRlcSapUser (this);
  m_epcX2PdcpUser = new EpcX2PdcpSpecificUser<McEnbPdcp> (this);
}

McEnbPdcp::~McEnbPdcp ()
{
  NS_LOG_FUNCTION (this);
}

TypeId
McEnbPdcp::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::McEnbPdcp")
    .SetParent<Object> ()
    .AddTraceSource ("TxPDU",
                     "PDU transmission notified to the RLC.",
                     MakeTraceSourceAccessor (&McEnbPdcp::m_txPdu),
                     "ns3::McEnbPdcp::PduTxTracedCallback")
    .AddTraceSource ("RxPDU",
                     "PDU received.",
                     MakeTraceSourceAccessor (&McEnbPdcp::m_rxPdu),
                     "ns3::McEnbPdcp::PduRxTracedCallback")
    ;
  return tid;
}

void
McEnbPdcp::DoDispose ()
{
  NS_LOG_FUNCTION (this);
  delete (m_pdcpSapProvider);
  delete (m_rlcSapUser);
  delete (m_epcX2PdcpUser);
}

void
McEnbPdcp::SetEpcX2PdcpProvider (EpcX2PdcpProvider * s)
{
  NS_LOG_FUNCTION(this);
  m_epcX2PdcpProvider = s;
}

  
EpcX2PdcpUser* 
McEnbPdcp::GetEpcX2PdcpUser ()
{
  NS_LOG_FUNCTION(this);
  return m_epcX2PdcpUser;
}

void
McEnbPdcp::SetMmWaveRnti (uint16_t rnti)
{
  m_mmWaveRnti = rnti;
}

void
McEnbPdcp::SetRnti (uint16_t rnti)
{
  NS_LOG_FUNCTION (this << (uint32_t) rnti);
  m_rnti = rnti;
}

void
McEnbPdcp::SetLcId (uint8_t lcId)
{
  NS_LOG_FUNCTION (this << (uint32_t) lcId);
  m_lcid = lcId;
}

void
McEnbPdcp::SetLtePdcpSapUser (LtePdcpSapUser * s)
{
  NS_LOG_FUNCTION (this << s);
  m_pdcpSapUser = s;
}

LtePdcpSapProvider*
McEnbPdcp::GetLtePdcpSapProvider ()
{
  NS_LOG_FUNCTION (this);
  return m_pdcpSapProvider;
}

void
McEnbPdcp::SetLteRlcSapProvider (LteRlcSapProvider * s)
{
  NS_LOG_FUNCTION (this << s);
  m_rlcSapProvider = s;
}

LteRlcSapUser*
McEnbPdcp::GetLteRlcSapUser ()
{
  NS_LOG_FUNCTION (this);
  return m_rlcSapUser;
}

McEnbPdcp::Status 
McEnbPdcp::GetStatus ()
{
  Status s;
  s.txSn = m_txSequenceNumber;
  s.rxSn = m_rxSequenceNumber;
  return s;
}

void 
McEnbPdcp::SetStatus (Status s)
{
  m_txSequenceNumber = s.txSn;
  m_rxSequenceNumber = s.rxSn;
}

void 
McEnbPdcp::SetUeDataParams(EpcX2Sap::UeDataParams params)
{
  m_ueDataParams = params;
}


////////////////////////////////////////

void
McEnbPdcp::DoTransmitPdcpSdu (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this << m_rnti << (uint32_t) m_lcid << p->GetSize ());

  LtePdcpHeader pdcpHeader;
  pdcpHeader.SetSequenceNumber (m_txSequenceNumber);

  m_txSequenceNumber++;
  if (m_txSequenceNumber > m_maxPdcpSn)
    {
      m_txSequenceNumber = 0;
    }

  pdcpHeader.SetDcBit (LtePdcpHeader::DATA_PDU);

  NS_LOG_LOGIC ("PDCP header: " << pdcpHeader);
  p->AddHeader (pdcpHeader);

  // Sender timestamp
  PdcpTag pdcpTag (Simulator::Now ());
  p->AddByteTag (pdcpTag);
  m_txPdu (m_rnti, m_lcid, p->GetSize ());

  LteRlcSapProvider::TransmitPdcpPduParameters params;
  params.rnti = m_rnti;
  params.lcid = m_lcid;
  params.pdcpPdu = p;

  if(m_epcX2PdcpProvider == 0 || (!m_useMmWaveConnection)) 
  {
    NS_LOG_INFO(this << " McEnbPdcp: Tx packet to downlink LTE stack");
    m_rlcSapProvider->TransmitPdcpPdu (params);
  } 
  else if (m_useMmWaveConnection) 
  {
    NS_LOG_INFO(this << " McEnbPdcp: Tx packet to downlink MmWave stack on remote cell " << m_ueDataParams.targetCellId);
    m_ueDataParams.ueData = p;
    m_epcX2PdcpProvider->SendMcPdcpPdu (m_ueDataParams);
  } 
  else 
  {
    NS_FATAL_ERROR("Invalid combination");
  }
  // TODO switch -- or if the m_epcX2PdcpProvider is 0 always use the rlcSapProvider
}

void
McEnbPdcp::DoReceivePdu (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this << m_rnti << (uint32_t) m_lcid << p->GetSize ());

  NS_LOG_INFO(this << " McEnbPdcp received uplink Pdu");
  // Receiver timestamp
  PdcpTag pdcpTag;
  Time delay;
  if (p->FindFirstMatchingByteTag (pdcpTag))
    {
      delay = Simulator::Now() - pdcpTag.GetSenderTimestamp ();
    }
  m_rxPdu(m_rnti, m_lcid, p->GetSize (), delay.GetNanoSeconds ());

  LtePdcpHeader pdcpHeader;
  p->RemoveHeader (pdcpHeader);
  NS_LOG_LOGIC ("PDCP header: " << pdcpHeader);

  m_rxSequenceNumber = pdcpHeader.GetSequenceNumber () + 1;
  if (m_rxSequenceNumber > m_maxPdcpSn)
    {
      m_rxSequenceNumber = 0;
    }

  LtePdcpSapUser::ReceivePdcpSduParameters params;
  params.pdcpSdu = p;
  params.rnti = m_rnti;
  params.lcid = m_lcid;
  m_pdcpSapUser->ReceivePdcpSdu (params);
}

void
McEnbPdcp::DoReceiveMcPdcpPdu (EpcX2Sap::UeDataParams params)
{
  NS_LOG_FUNCTION(this << m_mmWaveRnti << (uint32_t) m_lcid);
  DoReceivePdu(params.ueData);
}

void
McEnbPdcp::SwitchConnection (bool useMmWaveConnection)
{
  m_useMmWaveConnection = useMmWaveConnection;
}


} // namespace ns3
