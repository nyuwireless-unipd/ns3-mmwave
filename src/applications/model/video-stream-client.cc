/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ns3/log.h"
#include "ns3/ipv4-address.h"
#include "ns3/ipv6-address.h"
#include "ns3/nstime.h"
#include "ns3/inet-socket-address.h"
#include "ns3/inet6-socket-address.h"
#include "ns3/socket.h"
#include "ns3/simulator.h"
#include "ns3/socket-factory.h"
#include "ns3/packet.h"
#include "ns3/uinteger.h"
#include "ns3/trace-source-accessor.h"
#include "video-stream-client.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("VideoStreamClientApplication");

NS_OBJECT_ENSURE_REGISTERED (VideoStreamClient);

TypeId
VideoStreamClient::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::VideoStreamClient")
    .SetParent<Application> ()
    .SetGroupName ("Applications")
    .AddConstructor<VideoStreamClient> ()
    .AddAttribute ("RemoteAddress", "The destination address of the outbound packets",
                    AddressValue (),
                    MakeAddressAccessor (&VideoStreamClient::m_peerAddress),
                    MakeAddressChecker ())
    .AddAttribute ("RemotePort", "The destination port of the outbound packets",
                    UintegerValue (5000),
                    MakeUintegerAccessor (&VideoStreamClient::m_peerPort),
                    MakeUintegerChecker<uint16_t> ())
    
  ;
  return tid;
}

VideoStreamClient::VideoStreamClient ()
{
  NS_LOG_FUNCTION (this);
  m_initialDelay = 3;
  m_lastBufferSize = 0;
  m_currentBufferSize = 0;
  m_frameSize = 0;
  m_frameRate = 25;
  m_videoLevel = 3;
  m_stopCounter = 0;
  m_lastRecvFrame = 1e6;
  m_rebufferCounter = 0;
  m_bufferEvent = EventId();
  m_sendEvent = EventId();
}

VideoStreamClient::~VideoStreamClient ()
{
  NS_LOG_FUNCTION (this);
  m_socket = 0;
}

void
VideoStreamClient::SetRemote (Address ip, uint16_t port)
{
  NS_LOG_FUNCTION (this << ip << port);
  m_peerAddress = ip;
  m_peerPort = port;
}

void 
VideoStreamClient::SetRemote (Address addr)
{
  NS_LOG_FUNCTION (this << addr);
  m_peerAddress = addr;
}

void
VideoStreamClient::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
  Application::DoDispose ();
}

void 
VideoStreamClient::StartApplication (void)
{
  NS_LOG_FUNCTION (this);

  if (m_socket == 0)
  {
    TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");
    m_socket = Socket::CreateSocket (GetNode (), tid);
    if (Ipv4Address::IsMatchingType (m_peerAddress) == true)
    {
      if (m_socket->Bind () == -1)
      {
        NS_FATAL_ERROR ("Failed to bind socket");
      }
      m_socket->Connect (InetSocketAddress(Ipv4Address::ConvertFrom (m_peerAddress), m_peerPort));
    }
    else if (Ipv6Address::IsMatchingType (m_peerAddress) == true)
    {
      if (m_socket->Bind6 () == -1)
      {
        NS_FATAL_ERROR ("Failed to bind socket");
      }
      m_socket->Connect (m_peerAddress);
    }
    else if (InetSocketAddress::IsMatchingType (m_peerAddress) == true)
    {
      if (m_socket->Bind () == -1)
      {
        NS_FATAL_ERROR ("Failed to bind socket");
      }
      m_socket->Connect (m_peerAddress);
    }
    else if (Inet6SocketAddress::IsMatchingType (m_peerAddress) == true)
    {
      if (m_socket->Bind6 () == -1)
      {
        NS_FATAL_ERROR ("Failed to bind socket");
      }
      m_socket->Connect (m_peerAddress);
    }
    else
    {
      NS_ASSERT_MSG (false, "Incompatible address type: " << m_peerAddress);
    }
  }

  m_socket->SetRecvCallback (MakeCallback (&VideoStreamClient::HandleRead, this));
  m_sendEvent = Simulator::Schedule (MilliSeconds (1.0), &VideoStreamClient::Send, this);
  m_bufferEvent = Simulator::Schedule (Seconds (m_initialDelay), &VideoStreamClient::ReadFromBuffer, this);
}

void
VideoStreamClient::StopApplication ()
{
  NS_LOG_FUNCTION (this);

  if (m_socket != 0)
  {
    m_socket->Close ();
    m_socket->SetRecvCallback (MakeNullCallback<void, Ptr<Socket>> ());
    m_socket = 0;
  }

  Simulator::Cancel (m_bufferEvent);
}

void
VideoStreamClient::Send (void)
{
  NS_LOG_FUNCTION (this);
  NS_ASSERT (m_sendEvent.IsExpired ());

  uint8_t dataBuffer[10];
  sprintf((char *) dataBuffer, "%hu", 0);
  Ptr<Packet> firstPacket = Create<Packet> (dataBuffer, 10);
  m_socket->Send (firstPacket);

  if (Ipv4Address::IsMatchingType (m_peerAddress))
  {
    NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s client sent 10 bytes to " <<
                  Ipv4Address::ConvertFrom (m_peerAddress) << " port " << m_peerPort);
  }
  else if (Ipv6Address::IsMatchingType (m_peerAddress))
  {
    NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s client sent 10 bytes to " <<
                  Ipv6Address::ConvertFrom (m_peerAddress) << " port " << m_peerPort);
  }
  else if (InetSocketAddress::IsMatchingType (m_peerAddress))
  {
    NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s client sent 10 bytes to " <<
                  InetSocketAddress::ConvertFrom (m_peerAddress).GetIpv4 () << " port " << InetSocketAddress::ConvertFrom (m_peerAddress).GetPort ());
  }
  else if (Inet6SocketAddress::IsMatchingType (m_peerAddress))
  {
    NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s client sent 10 bytes to " <<
                  Inet6SocketAddress::ConvertFrom (m_peerAddress).GetIpv6 () << " port " << Inet6SocketAddress::ConvertFrom (m_peerAddress).GetPort ());
  }
}

uint32_t 
VideoStreamClient::ReadFromBuffer (void)
{
  // NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << " s, last buffer size: " << m_lastBufferSize << ", current buffer size: " << m_currentBufferSize);
  if (m_currentBufferSize < m_frameRate) 
  {

    if (m_lastBufferSize == m_currentBufferSize)
    {
      m_stopCounter++;
      // If the counter reaches 3, which means the client has been waiting for 3 sec, and no packets arrived.
      // In this case, we think the video streaming has finished, and there is no need to schedule the event.
      if (m_stopCounter < 3)
      {
        m_bufferEvent = Simulator::Schedule (Seconds (1.0), &VideoStreamClient::ReadFromBuffer, this);
      }
    }
    else
    {
      NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << " s: Not enough frames in the buffer, rebuffering!");
      m_stopCounter = 0;  // reset the stopCounter
      m_rebufferCounter++;
      m_bufferEvent = Simulator::Schedule (Seconds (1.0), &VideoStreamClient::ReadFromBuffer, this);
    }

    m_lastBufferSize = m_currentBufferSize;
    return (-1);
  }
  else
  {
    NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << " s: Play video frames from the buffer");
    if (m_stopCounter > 0) m_stopCounter = 0;    // reset the stopCounter
    if (m_rebufferCounter > 0) m_rebufferCounter = 0;   // reset the rebufferCounter
    m_currentBufferSize -= m_frameRate;

    m_bufferEvent = Simulator::Schedule (Seconds (1.0), &VideoStreamClient::ReadFromBuffer, this);
    m_lastBufferSize = m_currentBufferSize;
    return (m_currentBufferSize);
  }
}

void 
VideoStreamClient::HandleRead (Ptr<Socket> socket)
{
  NS_LOG_FUNCTION (this << socket);

  Ptr<Packet> packet;
  Address from;
  Address localAddress;
  while ((packet = socket->RecvFrom (from)))
  {
    socket->GetSockName (localAddress);
    if (InetSocketAddress::IsMatchingType (from))
    {
      uint8_t recvData[packet->GetSize()];
      packet->CopyData (recvData, packet->GetSize ());
      uint32_t frameNum;
      sscanf ((char *) recvData, "%u", &frameNum);

      if (frameNum == m_lastRecvFrame)
      {
        m_frameSize += packet->GetSize ();
      }
      else
      {
        if (frameNum > 0)
        {
          NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s client received frame " << frameNum-1 << " and " << m_frameSize << " bytes from " <<  InetSocketAddress::ConvertFrom (from).GetIpv4 () << " port " << InetSocketAddress::ConvertFrom (from).GetPort ());
        }

        m_currentBufferSize++;
        m_lastRecvFrame = frameNum;
        m_frameSize = packet->GetSize ();
      }

      // The rebuffering event has happend 3+ times, which suggest the client to lower the video quality.
      if (m_rebufferCounter >= 3)
      {
        if (m_videoLevel > 1)
        {
          NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds () << "s: Lower the video quality level!");
          m_videoLevel--;
          // reflect the change to the server
          uint8_t dataBuffer[10];
          sprintf((char *) dataBuffer, "%hu", m_videoLevel);
          Ptr<Packet> levelPacket = Create<Packet> (dataBuffer, 10);
          socket->SendTo (levelPacket, 0, from);
          m_rebufferCounter = 0;
        }
      }
      
      // If the current buffer size supports 5+ seconds video, we can try to increase the video quality level.
      if (m_currentBufferSize > 5 * m_frameRate)
      {
        if (m_videoLevel < MAX_VIDEO_LEVEL)
        {
          m_videoLevel++;
          // reflect the change to the server
          uint8_t dataBuffer[10];
          sprintf((char *) dataBuffer, "%hu", m_videoLevel);
          Ptr<Packet> levelPacket = Create<Packet> (dataBuffer, 10);
          socket->SendTo (levelPacket, 0, from);
          m_currentBufferSize = m_frameRate;
          NS_LOG_INFO ("At time " << Simulator::Now ().GetSeconds() << "s: Increase the video quality level to " << m_videoLevel);
        }
      }
    }
  }
}

} // namespace ns3
