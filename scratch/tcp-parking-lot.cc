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



static void
Traces(uint16_t nodeNum, uint16_t socketNum, std::string protocol)
{
  AsciiTraceHelper asciiTraceHelper;

  std::ostringstream pathCW;
  pathCW<<"/NodeList/"<<nodeNum<<"/$ns3::TcpL4Protocol/SocketList/"<<socketNum<<"/CongestionWindow";

  std::ostringstream fileCW;
  fileCW<<protocol<<"-"<<nodeNum+1<<"-TCP-CWND.txt";

  std::ostringstream pathRTT;
  pathRTT<<"/NodeList/"<<nodeNum<<"/$ns3::TcpL4Protocol/SocketList/"<<socketNum<<"/RTT";

  std::ostringstream fileRTT;
  fileRTT<<protocol<<"-"<<nodeNum+1<<"-TCP-RTT.txt";

  std::ostringstream pathRCWnd;
  pathRCWnd<<"/NodeList/"<<nodeNum<<"/$ns3::TcpL4Protocol/SocketList/"<<socketNum<<"/RWND";

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
  NodeContainer s;
  s.Create (4);
  NodeContainer c;
  c.Create (4);
  NodeContainer r;
  r.Create (4);



  NodeContainer r0r1 = NodeContainer (r.Get (0), r.Get (1));
  NodeContainer r1r2 = NodeContainer (r.Get (1), r.Get (2));
  NodeContainer r2r3 = NodeContainer (r.Get (2), r.Get (3));

  NodeContainer s0r0 = NodeContainer (s.Get (0), r.Get (0));
  NodeContainer s2r0 = NodeContainer (s.Get (2), r.Get (0));
  NodeContainer c2r1 = NodeContainer (c.Get (2), r.Get (1));
  NodeContainer s1r1 = NodeContainer (s.Get (1), r.Get (1));
  NodeContainer s3r2 = NodeContainer (s.Get (3), r.Get (2));
  NodeContainer c3r3 = NodeContainer (c.Get (3), r.Get (3));
  NodeContainer c1r3 = NodeContainer (c.Get (1), r.Get (3));
  NodeContainer c0r3 = NodeContainer (c.Get (0), r.Get (3));




  PointToPointHelper p_r0r1;
  p_r0r1.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_r0r1.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_r0r1.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_r0r1 = p_r0r1.Install (r0r1);

  PointToPointHelper p_r1r2;
  p_r1r2.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_r1r2.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_r1r2.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_r1r2 = p_r1r2.Install (r1r2);

  PointToPointHelper p_r2r3;
  p_r2r3.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_r2r3.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_r2r3.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_r2r3 = p_r2r3.Install (r2r3);


  PointToPointHelper p_s0r0;
  p_s0r0.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_s0r0.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_s0r0.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_s0r0 = p_s0r0.Install (s0r0);

  PointToPointHelper p_s2r0;
  p_s2r0.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_s2r0.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_s2r0.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_s2r0 = p_s2r0.Install (s2r0);

  PointToPointHelper p_c2r1;
  p_c2r1.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_c2r1.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_c2r1.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_c2r1 = p_c2r1.Install (c2r1);

  PointToPointHelper p_s1r1;
  p_s1r1.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_s1r1.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_s1r1.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_s1r1 = p_s1r1.Install (s1r1);

    PointToPointHelper p_s3r2;
  p_s3r2.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_s3r2.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_s3r2.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_s3r2 = p_s3r2.Install (s3r2);

    PointToPointHelper p_c3r3;
  p_c3r3.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_c3r3.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_c3r3.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_c3r3 = p_c3r3.Install (c3r3);

    PointToPointHelper p_c1r3;
  p_c1r3.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_c1r3.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_c1r3.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_c1r3 = p_c1r3.Install (c1r3);

    PointToPointHelper p_c0r3;
  p_c0r3.SetDeviceAttribute ("DataRate", DataRateValue (DataRate (1000000000)));
  p_c0r3.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (5)));
  p_c0r3.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  NetDeviceContainer d_c0r3 = p_c0r3.Install (c0r3);


  // Now add ip/tcp stack to all nodes.
  InternetStackHelper internet;
  internet.InstallAll ();

  // Later, we add IP addresses.
  Ipv4AddressHelper ipv4;
  ipv4.SetBase ("10.1.1.0", "255.255.255.0");
  ipv4.Assign (d_r0r1);
  ipv4.SetBase ("10.1.2.0", "255.255.255.0");
  ipv4.Assign (d_r1r2);
  ipv4.SetBase ("10.1.3.0", "255.255.255.0");
  ipv4.Assign (d_r2r3);

  ipv4.SetBase ("10.1.8.0", "255.255.255.0");
  ipv4.Assign (d_s0r0);
  ipv4.SetBase ("10.1.9.0", "255.255.255.0");
  ipv4.Assign (d_s2r0);
  ipv4.SetBase ("10.1.10.0", "255.255.255.0");
  ipv4.Assign (d_s1r1);
  ipv4.SetBase ("10.1.11.0", "255.255.255.0");
  ipv4.Assign (d_s3r2);

  ipv4.SetBase ("10.1.4.0", "255.255.255.0");
  Ipv4InterfaceContainer ipInterf0 = ipv4.Assign (d_c0r3);
  ipv4.SetBase ("10.1.5.0", "255.255.255.0");
  Ipv4InterfaceContainer ipInterf1 = ipv4.Assign (d_c1r3);
  ipv4.SetBase ("10.1.6.0", "255.255.255.0");
  Ipv4InterfaceContainer ipInterf2 = ipv4.Assign (d_c2r1);
  ipv4.SetBase ("10.1.7.0", "255.255.255.0");
  Ipv4InterfaceContainer ipInterf3 = ipv4.Assign (d_c3r3);

  // and setup ip routing tables to get total ip-level connectivity.
  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

  uint16_t port = 9;  // well-known echo port number

for (int fl = 0; fl < 4; fl++)
{
  if(fl == 0)
  {
  BulkSendHelper source ("ns3::TcpSocketFactory",
                         InetSocketAddress (ipInterf0.GetAddress (0), port));
  // Set the amount of data to send in bytes.  Zero is unlimited.
  source.SetAttribute ("MaxBytes", UintegerValue (maxBytes));
  ApplicationContainer sourceApps = source.Install (s.Get (0));
  sourceApps.Start (Seconds (0.0));
  sourceApps.Stop (Seconds (simStopTime));


//
// Create a PacketSinkApplication and install it on node 1
//
  PacketSinkHelper sink ("ns3::TcpSocketFactory",
                         InetSocketAddress (Ipv4Address::GetAny (), port));
  ApplicationContainer sinkApps = sink.Install (c.Get (0));
  sinkApps.Start (Seconds (0.0));
  sinkApps.Stop (Seconds (simStopTime));

    std::ostringstream fileName;
  fileName<<protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay)<<"-"<<fl+1<<"-TCP-DATA.txt";

  AsciiTraceHelper asciiTraceHelper;

    Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (fileName.str ().c_str ());
    sinkApps.Get(0)->TraceConnectWithoutContext("Rx",MakeBoundCallback (&Rx, stream));
    Simulator::Schedule (Seconds (0.001), &Traces, 0, 0, protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay));
  }
  else if(fl == 1)
  {
      BulkSendHelper source ("ns3::TcpSocketFactory",
                         InetSocketAddress (ipInterf1.GetAddress (0), port));
  // Set the amount of data to send in bytes.  Zero is unlimited.
  source.SetAttribute ("MaxBytes", UintegerValue (maxBytes));
  ApplicationContainer sourceApps = source.Install (s.Get (1));
  sourceApps.Start (Seconds (0.0));
  sourceApps.Stop (Seconds (simStopTime));


//
// Create a PacketSinkApplication and install it on node 1
//
  PacketSinkHelper sink ("ns3::TcpSocketFactory",
                         InetSocketAddress (Ipv4Address::GetAny (), port));
  ApplicationContainer sinkApps = sink.Install (c.Get (1));
  sinkApps.Start (Seconds (0.0));
  sinkApps.Stop (Seconds (simStopTime));

    std::ostringstream fileName;
  fileName<<protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay)<<"-"<<fl+1<<"-TCP-DATA.txt";

  AsciiTraceHelper asciiTraceHelper;

    Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (fileName.str ().c_str ());
    sinkApps.Get(0)->TraceConnectWithoutContext("Rx",MakeBoundCallback (&Rx, stream));
    Simulator::Schedule (Seconds (0.001), &Traces, 1, 0, protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay));
  }
  else if(fl == 2)
  {
      BulkSendHelper source ("ns3::TcpSocketFactory",
                         InetSocketAddress (ipInterf2.GetAddress (0), port));
  // Set the amount of data to send in bytes.  Zero is unlimited.
  source.SetAttribute ("MaxBytes", UintegerValue (maxBytes));
  ApplicationContainer sourceApps = source.Install (s.Get (2));
  sourceApps.Start (Seconds (0.0));
  sourceApps.Stop (Seconds (simStopTime));


//
// Create a PacketSinkApplication and install it on node 1
//
  PacketSinkHelper sink ("ns3::TcpSocketFactory",
                         InetSocketAddress (Ipv4Address::GetAny (), port));
  ApplicationContainer sinkApps = sink.Install (c.Get (2));
  sinkApps.Start (Seconds (0.0));
  sinkApps.Stop (Seconds (simStopTime));

    std::ostringstream fileName;
  fileName<<protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay)<<"-"<<fl+1<<"-TCP-DATA.txt";

  AsciiTraceHelper asciiTraceHelper;

    Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (fileName.str ().c_str ());
    sinkApps.Get(0)->TraceConnectWithoutContext("Rx",MakeBoundCallback (&Rx, stream));
    Simulator::Schedule (Seconds (0.001), &Traces, 2, 0, protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay));
  }
    else if(fl == 3)
  {
      BulkSendHelper source ("ns3::TcpSocketFactory",
                         InetSocketAddress (ipInterf3.GetAddress (0), port));
  // Set the amount of data to send in bytes.  Zero is unlimited.
  source.SetAttribute ("MaxBytes", UintegerValue (maxBytes));
  ApplicationContainer sourceApps = source.Install (s.Get (3));
  sourceApps.Start (Seconds (0.0));
  sourceApps.Stop (Seconds (simStopTime));


//
// Create a PacketSinkApplication and install it on node 1
//
  PacketSinkHelper sink ("ns3::TcpSocketFactory",
                         InetSocketAddress (Ipv4Address::GetAny (), port));
  ApplicationContainer sinkApps = sink.Install (c.Get (3));
  sinkApps.Start (Seconds (0.0));
  sinkApps.Stop (Seconds (simStopTime));

    std::ostringstream fileName;
  fileName<<protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay)<<"-"<<fl+1<<"-TCP-DATA.txt";

  AsciiTraceHelper asciiTraceHelper;

    Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (fileName.str ().c_str ());
    sinkApps.Get(0)->TraceConnectWithoutContext("Rx",MakeBoundCallback (&Rx, stream));
    Simulator::Schedule (Seconds (0.001), &Traces, 3, 0, protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay));
  }
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
