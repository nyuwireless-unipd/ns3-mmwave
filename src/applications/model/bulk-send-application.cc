/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2010 Georgia Institute of Technology
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
 * Author: George F. Riley <riley@ece.gatech.edu>
 */

#include "ns3/log.h"
#include "ns3/address.h"
#include "ns3/node.h"
#include "ns3/nstime.h"
#include "ns3/socket.h"
#include "ns3/simulator.h"
#include "ns3/socket-factory.h"
#include "ns3/packet.h"
#include "ns3/uinteger.h"
#include "ns3/trace-source-accessor.h"
#include "ns3/tcp-socket-factory.h"
#include "bulk-send-application.h"
#include "ns3/tcp-socket-base.h" // For pacing configuration.

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("BulkSendApplication");

NS_OBJECT_ENSURE_REGISTERED (BulkSendApplication);

TypeId
BulkSendApplication::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::BulkSendApplication")
    .SetParent<Application> ()
    .SetGroupName("Applications") 
    .AddConstructor<BulkSendApplication> ()
    .AddAttribute ("SendSize", "The amount of data to send each time.",
                   UintegerValue (512),
                   MakeUintegerAccessor (&BulkSendApplication::m_sendSize),
                   MakeUintegerChecker<uint32_t> (1))
    .AddAttribute ("Remote", "The address of the destination",
                   AddressValue (),
                   MakeAddressAccessor (&BulkSendApplication::m_peer),
                   MakeAddressChecker ())
    .AddAttribute ("MaxBytes",
                   "The total number of bytes to send. "
                   "Once these bytes are sent, "
                   "no data  is sent again. The value zero means "
                   "that there is no limit.",
                   UintegerValue (0),
                   MakeUintegerAccessor (&BulkSendApplication::m_maxBytes),
                   MakeUintegerChecker<uint64_t> ())
    .AddAttribute ("Protocol", "The type of protocol to use.",
                   TypeIdValue (TcpSocketFactory::GetTypeId ()),
                   MakeTypeIdAccessor (&BulkSendApplication::m_tid),
                   MakeTypeIdChecker ())
    .AddTraceSource ("Tx", "A new packet is created and is sent",
                     MakeTraceSourceAccessor (&BulkSendApplication::m_txTrace),
                     "ns3::Packet::TracedCallback")
  ;
  return tid;
}


BulkSendApplication::BulkSendApplication ()
  : m_socket (0),
    m_connected (false),
    m_totBytes (0),
    m_to_send (0),              // For pacing
    m_pacing_event ()           // For pacing
{
  NS_LOG_FUNCTION (this);

  if (PACING_CONFIG == APP_PACING)
    NS_LOG_INFO ("APP_PACING. No pacing in TCP. This app *will do* pacing.");
  else
    NS_LOG_INFO ("This application will *not* do pacing.");
}

BulkSendApplication::~BulkSendApplication ()
{
  NS_LOG_FUNCTION (this);
}

void
BulkSendApplication::SetMaxBytes (uint64_t maxBytes)
{
  NS_LOG_FUNCTION (this << maxBytes);
  m_maxBytes = maxBytes;
}

Ptr<Socket>
BulkSendApplication::GetSocket (void) const
{
  NS_LOG_FUNCTION (this);
  return m_socket;
}

void
BulkSendApplication::DoDispose (void)
{
  NS_LOG_FUNCTION (this);

  m_socket = 0;
  // chain up
  Application::DoDispose ();
}

// Application Methods
void BulkSendApplication::StartApplication (void) // Called at time specified by Start
{
  NS_LOG_FUNCTION (this);

  // Create the socket if not already
  if (!m_socket)
    {
      m_socket = Socket::CreateSocket (GetNode (), m_tid);

      // Fatal error if socket type is not NS3_SOCK_STREAM or NS3_SOCK_SEQPACKET
      if (m_socket->GetSocketType () != Socket::NS3_SOCK_STREAM &&
          m_socket->GetSocketType () != Socket::NS3_SOCK_SEQPACKET)
        {
          NS_FATAL_ERROR ("Using BulkSend with an incompatible socket type. "
                          "BulkSend requires SOCK_STREAM or SOCK_SEQPACKET. "
                          "In other words, use TCP instead of UDP.");
        }

      if (Inet6SocketAddress::IsMatchingType (m_peer))
        {
          if (m_socket->Bind6 () == -1)
            {
              NS_FATAL_ERROR ("Failed to bind socket");
            }
        }
      else if (InetSocketAddress::IsMatchingType (m_peer))
        {
          if (m_socket->Bind () == -1)
            {
              NS_FATAL_ERROR ("Failed to bind socket");
            }
        }

      m_socket->Connect (m_peer);
      m_socket->ShutdownRecv ();
      m_socket->SetConnectCallback (
        MakeCallback (&BulkSendApplication::ConnectionSucceeded, this),
        MakeCallback (&BulkSendApplication::ConnectionFailed, this));
      m_socket->SetSendCallback (
        MakeCallback (&BulkSendApplication::DataSend, this));
    }
  if (m_connected)
    {
      SendData ();
    }
}

void BulkSendApplication::StopApplication (void) // Called at time specified by Stop
{
  NS_LOG_FUNCTION (this);

  if (m_socket != 0)
    {
      m_socket->Close ();
      m_connected = false;
    }
  else
    {
      NS_LOG_WARN ("BulkSendApplication found null socket to close in StopApplication");
    }
}


// Private helpers

void BulkSendApplication::SendData (void)
{
  NS_LOG_FUNCTION (this);

  while (m_maxBytes == 0 || m_totBytes < m_maxBytes)
    { // Time to send more

      // IF APPLICATION PACING
      if (PACING_CONFIG == APP_PACING) {

        // If no pacing rate set, normal (non-paced) code will handle.
        if (GetPacingRate() == 0.0) { 

          NS_LOG_INFO (this << " Pacing rate is 0 - not pacing send.");

        } else {

          m_to_send += 1;

          // If previous timer expired, send immediately.
          if (m_pacing_event.IsExpired()) {
            NS_LOG_INFO (this << " Timer expired.  Send now.");
            PaceSend();
          }

          return;
        }

      } 
      
      // uint64_t to allow the comparison later.
      // the result is in a uint32_t range anyway, because
      // m_sendSize is uint32_t.
      uint64_t toSend = m_sendSize;
      // Make sure we don't send too many
      if (m_maxBytes > 0)
        {
          toSend = std::min (toSend, m_maxBytes - m_totBytes);
        }

      NS_LOG_LOGIC ("sending packet at " << Simulator::Now ());
      Ptr<Packet> packet = Create<Packet> (toSend);
      int actual = m_socket->Send (packet);
      if (actual > 0)
        {
          m_totBytes += actual;
          m_txTrace (packet);
        }
      // We exit this loop when actual < toSend as the send side
      // buffer is full. The "DataSent" callback will pop when
      // some buffer space has freed ip.
      if ((unsigned)actual != toSend)
        {
          break;
        }
 
    } // End of while() time to send more.

  // Check if time to close (all sent)
  if (m_totBytes == m_maxBytes && m_connected)
    {
      m_socket->Close ();
      m_connected = false;
    }
}
  
void BulkSendApplication::ConnectionSucceeded (Ptr<Socket> socket)
{
  NS_LOG_FUNCTION (this << socket);
  NS_LOG_LOGIC ("BulkSendApplication Connection succeeded");
  m_connected = true;
  SendData ();
}

void BulkSendApplication::ConnectionFailed (Ptr<Socket> socket)
{
  NS_LOG_FUNCTION (this << socket);
  NS_LOG_LOGIC ("BulkSendApplication, Connection Failed");
}

void BulkSendApplication::DataSend (Ptr<Socket>, uint32_t)
{
  NS_LOG_FUNCTION (this);

  if (m_connected)
    { // Only send new data if the connection has completed
      SendData ();
    }
}


////////////////////////////////////////////////////////
// ADDED TO SUPPORT PACING - Start

// Send packet and set timer for subsequent send.
void BulkSendApplication::PaceSend() {
  NS_LOG_FUNCTION (this);

  // If not connected, cannot send.
  if (!m_connected) {
    NS_LOG_WARN (this << "  BulkSendApplication is not connected!");
    return;
  }

  // If pacing timer expired, but device wasn't ready,
  // there may be nothing to send.
  if (m_to_send == 0) {
    NS_LOG_INFO (this << "  No packets to send");
    return;
  } else
    NS_LOG_INFO (this << "  packets to send: " << m_to_send);

  // Prepare to send packet.
  NS_LOG_INFO (this << "  Sending packet at " << Simulator::Now());
  uint64_t size = m_sendSize;

  // Make sure we don't send too many bytes.
  if (m_maxBytes > 0)
    size = std::min(size, m_maxBytes - m_totBytes);

  NS_LOG_INFO (this <<
               "  m_sendSize: " << m_sendSize <<
               "  m_maxBytes: " << m_maxBytes <<
               "  m_totBytes: " << m_totBytes <<
               "  size: " << size);

  // Create packet.
  Ptr<Packet> packet = Create<Packet>(size);

  // Send packet.
  int actual = m_socket->Send(packet);
  m_to_send -= 1;
  
  // Record stats.
  if (actual > 0) {
    m_totBytes += actual;
    m_txTrace(packet);
  }

  // If all sent --> close connection.
  if (m_totBytes == m_maxBytes && m_connected) {
    m_socket->Close();
    m_connected = false;
  }

  // Schedule next send event based on pacing rate.
  double pacing_rate = GetPacingRate();
  if (pacing_rate > 0) {
    double sz = size * 8 / 1000000.0;  // Convert to Mbits.
    double delta = sz / pacing_rate;   // Convert to seconds.
    delta *= 1000000000;               // Convert to nanoseconds.
    m_pacing_event.Cancel();           // Cancel any pending events.
    m_pacing_event = Simulator::Schedule(Time(delta),
                                         &BulkSendApplication::PaceSend, this);
    NS_LOG_INFO (this <<
                 "  sz: " << sz/8*1000000 <<
                 "  rate: " << pacing_rate <<
                 "  delta: " << delta/1000000000 <<
                 "  @time: " << Time(Simulator::Now()+delta).GetSeconds());
  } else
    NS_LOG_INFO (this << " rate: " << pacing_rate << " (not pacing)");  
  
}

// Get pacing rate from TCP socket base.
double BulkSendApplication::GetPacingRate() const {
  
  // Since must be NS3_SOCK_STREAM (TCP), get the TCP socket base.
  TcpSocketBase *p_temp = dynamic_cast <TcpSocketBase *>(GetPointer(m_socket));
  NS_ASSERT(p_temp != NULL);
  Ptr<TcpSocketBase> tcp_socket_base = p_temp;

  return  tcp_socket_base -> GetPacingRate();
}
  
// ADDED TO SUPPORT PACING - End
////////////////////////////////////////////////////////
  
} // Namespace ns3
