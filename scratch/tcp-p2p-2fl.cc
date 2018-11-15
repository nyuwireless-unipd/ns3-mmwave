/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
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
 */

// Network topology
//
//           100Mb/s, 10ms       10Mb/s, 10ms
//       n0-----------------n1-----------------n2
//

#include <string>
#include <fstream>
#include "ns3/core-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/network-module.h"
#include "ns3/packet-sink.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("TcpBulkSendExample");

//if(m_queue->GetNBytes() < 25000*10) add this to NetDevice

static void
CwndChange (Ptr<OutputStreamWrapper> stream, uint32_t oldCwnd, uint32_t newCwnd)
{
  *stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldCwnd << "\t" << newCwnd << std::endl;
}

static void
RttChange (Ptr<OutputStreamWrapper> stream, Time oldRtt, Time newRtt)
{
  *stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldRtt.GetSeconds () << "\t" << newRtt.GetSeconds () << std::endl;
}



static void Rx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet, const Address &from)
{
  *stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << packet->GetSize()<< std::endl;
}

static void queueSize (Ptr<OutputStreamWrapper> stream, uint32_t bytes, uint32_t bytesNew)
{
  *stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << bytesNew<< std::endl;
}



static void
Traces(uint16_t nodeNum, std::string protocol)
{
  AsciiTraceHelper asciiTraceHelper;

  std::ostringstream pathCW;
  pathCW<<"/NodeList/"<<0+nodeNum*2<<"/$ns3::TcpL4Protocol/SocketList/0/CongestionWindow";

  std::ostringstream fileCW;
  fileCW<<protocol<<"-"<<nodeNum+1<<"-TCP-CWND.txt";

  std::ostringstream pathRTT;
  pathRTT<<"/NodeList/"<<0+nodeNum*2<<"/$ns3::TcpL4Protocol/SocketList/0/RTT";

  std::ostringstream fileRTT;
  fileRTT<<protocol<<"-"<<nodeNum+1<<"-TCP-RTT.txt";

  std::ostringstream pathRCWnd;
  pathRCWnd<<"/NodeList/"<<0+nodeNum*2<<"/$ns3::TcpL4Protocol/SocketList/0/RWND";

  std::ostringstream fileRCWnd;
  fileRCWnd<<protocol<<"-"<<nodeNum+1<<"-TCP-RCWND.txt";

  Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream (fileCW.str ().c_str ());
  Config::ConnectWithoutContext (pathCW.str ().c_str (), MakeBoundCallback(&CwndChange, stream1));

  Ptr<OutputStreamWrapper> stream2 = asciiTraceHelper.CreateFileStream (fileRTT.str ().c_str ());
  Config::ConnectWithoutContext (pathRTT.str ().c_str (), MakeBoundCallback(&RttChange, stream2));

  Ptr<OutputStreamWrapper> stream4 = asciiTraceHelper.CreateFileStream (fileRCWnd.str ().c_str ());
  Config::ConnectWithoutContext (pathRCWnd.str ().c_str (), MakeBoundCallback(&CwndChange, stream4));

}


int
main (int argc, char *argv[])
{

  uint32_t maxBytes = 0;
  int packetSize = 14000;
  std::string protocol = "TcpNyu";
  double simStopTime = 60;
  int bufferSize = 1000;
  int p2pDelay = 9;

  //
// Allow the user to override any of the defaults at
// run-time, via command-line arguments
//
  CommandLine cmd;
  cmd.AddValue ("maxBytes",
                "Total number of bytes for application to send", maxBytes);
  cmd.Parse (argc, argv);

  Config::SetDefault ("ns3::TcpSocketBase::MinRto", TimeValue (MilliSeconds (200)));
  Config::SetDefault ("ns3::Ipv4L3Protocol::FragmentExpirationTimeout", TimeValue (Seconds (1)));
  Config::SetDefault ("ns3::TcpSocket::SegmentSize", UintegerValue (packetSize));
  Config::SetDefault ("ns3::TcpSocket::DelAckCount", UintegerValue (1));

  Config::SetDefault ("ns3::TcpSocket::SndBufSize", UintegerValue (131072*400));
  Config::SetDefault ("ns3::TcpSocket::RcvBufSize", UintegerValue (131072*400));


  if(protocol == "TcpNewReno")
    {
  Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpNewReno::GetTypeId ()));
    }
    else if (protocol == "TcpVegas")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpVegas::GetTypeId ()));
    }
    else if (protocol == "TcpLedbat")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpLedbat::GetTypeId ()));

    }
    else if (protocol == "TcpHighSpeed")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpHighSpeed::GetTypeId ()));

    }
    else if (protocol == "TcpCubic")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpCubic::GetTypeId ()));

    }
    else if (protocol == "TcpIllinois")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpIllinois::GetTypeId ()));

    }
    else if (protocol == "TcpHybla")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpHybla::GetTypeId ()));

    }
    else if (protocol == "TcpVeno")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpVeno::GetTypeId ()));

    }
    else if (protocol == "TcpWestwood")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpWestwood::GetTypeId ()));

    }
    else if (protocol == "TcpYeah")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpYeah::GetTypeId ()));

    }
    else if (protocol == "TcpBbr")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpBbr::GetTypeId ()));

    }
    else if (protocol == "TcpNyu")
    {
      Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpNyu::GetTypeId ()));

    }    
    else
    {
    std::cout<<protocol<<" Unkown protocol.\n";
    return 1;
    }



// install the network interfaces and connect them with a channel.
  NodeContainer n0n1;
  n0n1.Create (2);

  NodeContainer n3n1;
  n3n1.Create (1);
  n3n1.Add (n0n1.Get (1));
  
  NodeContainer n1n2;
  n1n2.Add (n0n1.Get (1));
  n1n2.Create (1);

  // We create the channels first without any IP addressing information
  // First make and configure the helper, so that it will put the appropriate
  // attributes on the network interfaces and channels we are about to install.
  PointToPointHelper p2p1;
  p2p1.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (10000000000)));
  p2p1.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (9)));
  p2p1.SetDeviceAttribute ("Mtu", UintegerValue (1500));


  PointToPointHelper p2p2;
  p2p2.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1120000000)));
  p2p2.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (1)));
  p2p2.SetDeviceAttribute ("Mtu", UintegerValue (1500));

  PointToPointHelper p2p3;
  p2p3.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (10000000000)));
  p2p3.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (19)));
  p2p3.SetDeviceAttribute ("Mtu", UintegerValue (1500));

  //p2p1.SetQueue ("ns3::DropTailQueue", "MaxPackets", UintegerValue(1000), "MaxBytes", UintegerValue(1000*1460));
  //p2p2.SetQueue ("ns3::DropTailQueue", "MaxPackets", UintegerValue(1000), "MaxBytes", UintegerValue(1000*1460));

  // And then install devices and channels connecting our topology.
  NetDeviceContainer dev0 = p2p1.Install (n0n1);
  NetDeviceContainer dev1 = p2p2.Install (n1n2);
  NetDeviceContainer dev2 = p2p3.Install (n3n1);

  // Now add ip/tcp stack to all nodes.
  InternetStackHelper internet;
  internet.InstallAll ();

  // Later, we add IP addresses.
  Ipv4AddressHelper ipv4;
  ipv4.SetBase ("10.1.3.0", "255.255.255.0");
  ipv4.Assign (dev0);
  ipv4.SetBase ("10.1.2.0", "255.255.255.0");
  Ipv4InterfaceContainer ipInterfs = ipv4.Assign (dev1);

  ipv4.SetBase ("10.1.4.0", "255.255.255.0");
  ipv4.Assign (dev2);

  // and setup ip routing tables to get total ip-level connectivity.
  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

  uint16_t port = 9;  // well-known echo port number

for (int fl = 0; fl < 2; fl++)
{
  BulkSendHelper source ("ns3::TcpSocketFactory",
                         InetSocketAddress (ipInterfs.GetAddress (1), port));
  // Set the amount of data to send in bytes.  Zero is unlimited.
  source.SetAttribute ("MaxBytes", UintegerValue (maxBytes));
  ApplicationContainer sourceApps;
  if(fl ==0)
  {
   sourceApps= source.Install (n0n1.Get (0));
  }
  else
  {
   sourceApps = source.Install (n3n1.Get (0));

  }
  sourceApps.Start (Seconds (0.0+2*fl));
  sourceApps.Stop (Seconds (simStopTime));


//
// Create a PacketSinkApplication and install it on node 1
//
  PacketSinkHelper sink ("ns3::TcpSocketFactory",
                         InetSocketAddress (Ipv4Address::GetAny (), port));
  ApplicationContainer sinkApps = sink.Install (n1n2.Get (1));
  sinkApps.Start (Seconds (0.0));
  sinkApps.Stop (Seconds (simStopTime));

    std::ostringstream fileName;
  fileName<<protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay)<<"-"<<fl+1<<"-TCP-DATA.txt";

  AsciiTraceHelper asciiTraceHelper;

    Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (fileName.str ().c_str ());
    sinkApps.Get(0)->TraceConnectWithoutContext("Rx",MakeBoundCallback (&Rx, stream));
    Simulator::Schedule (Seconds (0.001+2*fl), &Traces, fl, protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay));


  //dev1.Get(0)->GetObject<PointToPointNetDevice>()->GetQueue()->SetMaxPackets(300);
  //dev0.Get(0)->GetObject<PointToPointNetDevice>()->GetQueue()->SetMaxBytes(2000);
  //dev0.Get(0)->GetObject<PointToPointNetDevice>()->GetQueue()->SetMode(ns3::QueueBase::QUEUE_MODE_BYTES);

    std::ostringstream fileName1;
  fileName1<<protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay)<<"-"<<fl+1<<"-QUEUE.txt";

  AsciiTraceHelper asciiTraceHelper1;

    Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper1.CreateFileStream (fileName1.str ().c_str ());

  dev1.Get(0)->GetObject<PointToPointNetDevice>()->GetQueue()->TraceConnectWithoutContext("PacketsInQueue",MakeBoundCallback (&queueSize, stream1));

  port++;
}
  NS_LOG_INFO ("Run Simulation.");
  Simulator::Stop (Seconds (simStopTime));
  Simulator::Run ();
  Simulator::Destroy ();
  NS_LOG_INFO ("Done.");

  //Ptr<PacketSink> sink1 = DynamicCast<PacketSink> (sinkApps.Get (0));
  //std::cout << "Total Bytes Received: " << sink1->GetTotalRx () << std::endl;
}
