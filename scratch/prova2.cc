#include <ns3/mmwave-helper.h>
#include "ns3/epc-helper.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/internet-module.h"
#include "ns3/mobility-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/config-store.h"
#include "ns3/mmwave-point-to-point-epc-helper.h"
//#include "ns3/gtk-config-store.h"
#include <ns3/buildings-helper.h>
#include <ns3/buildings-module.h>
#include <ns3/random-variable-stream.h>
#include <ns3/lte-ue-net-device.h>

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <list>


using namespace ns3;

int
main(int argc, char *argv[])
{
  Ptr<MmWavePointToPointEpcHelper> epcHelper = CreateObject<MmWavePointToPointEpcHelper>();
  Ptr<MmWaveHelper> mmWaveHelper = CreateObject<MmWaveHelper>();
  mmWaveHelper -> SetEpcHelper(epcHelper);
  mmWaveHelper->Initialize();

  //create remote host
  NodeContainer remoteHostContainer;
  remoteHostContainer.Create(1);
  Ptr<Node> remoteHost = remoteHostContainer.Get(0);
  //install IP stack on the remote host
  InternetStackHelper internet;
  internet.Install(remoteHostContainer);

  // Create the Internet by connecting remoteHost to pgw. Setup routing too
  Ptr<Node> pgw = epcHelper->GetPgwNode();
  PointToPointHelper p2ph;
  p2ph.SetDeviceAttribute ("DataRate", DataRateValue (DataRate ("100Gb/s")));
  p2ph.SetDeviceAttribute ("Mtu", UintegerValue (2500));
  p2ph.SetChannelAttribute ("Delay", TimeValue (Seconds (0.010)));
  NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);
  Ipv4AddressHelper ipv4h;
  ipv4h.SetBase ("1.0.0.0", "255.0.0.0");
  Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign (internetDevices);
  // interface 0 is localhost, 1 is the p2p device
  Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress (1);
  Ipv4StaticRoutingHelper ipv4RoutingHelper;
  Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
  remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.0.0.0"), 1);


  NodeContainer enbNodes;
  NodeContainer lteEnbNodes;
  NodeContainer ueNodes;
  enbNodes.Create(1);
  lteEnbNodes.Create(1);
  ueNodes.Create(1);

  MobilityHelper mobility;
  mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
  mobility.Install(enbNodes);
  mobility.Install(lteEnbNodes);
  mobility.Install(ueNodes);

  NetDeviceContainer enbNetDev = mmWaveHelper -> InstallEnbDevice(enbNodes);
  NetDeviceContainer lteEnbDev = mmWaveHelper -> InstallLteEnbDevice(lteEnbNodes);
  NetDeviceContainer ueNetDev = mmWaveHelper -> InstallMcUeDevice(ueNodes);

  //Install IP stack on the UE
  internet.Install(ueNodes);
  Ipv4InterfaceContainer ueIpIface;
  ueIpIface = epcHelper -> AssignUeIpv4Address(NetDeviceContainer(ueNetDev));

  //add route to reach the remote host
  Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting(ueNodes.Get(0)->GetObject<Ipv4>());
  ueStaticRouting -> SetDefaultRoute(epcHelper->GetUeDefaultGatewayAddress(),1);

  //add X2 interface
  mmWaveHelper -> AddX2Interface(lteEnbNodes,enbNodes);

  mmWaveHelper -> AttachToClosestEnb(ueNetDev,enbNetDev,lteEnbDev);


  // Install and start applications on UEs and remote host
  uint16_t dlPort = 1234;
  uint16_t ulPort = 2000;
  ApplicationContainer clientApps;
  ApplicationContainer serverApps;
  bool dl = 1;
  bool ul = 0;

  for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
  {
      if(dl)
      {
        UdpServerHelper dlPacketSinkHelper (dlPort);
        dlPacketSinkHelper.SetAttribute ("PacketWindowSize", UintegerValue(256));
        serverApps.Add (dlPacketSinkHelper.Install (ueNodes.Get(u)));

        // Simulator::Schedule(MilliSeconds(20), &PrintLostUdpPackets, DynamicCast<UdpServer>(serverApps.Get(serverApps.GetN()-1)), lostFilename);

        UdpClientHelper dlClient (ueIpIface.GetAddress (u), dlPort);
        dlClient.SetAttribute ("Interval", TimeValue (MicroSeconds(100)));
        dlClient.SetAttribute ("MaxPackets", UintegerValue(0xFFFFFFFF));
        clientApps.Add (dlClient.Install (remoteHost));

      }
      if(ul)
      {
        ++ulPort;
        PacketSinkHelper ulPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
        ulPacketSinkHelper.SetAttribute ("PacketWindowSize", UintegerValue(256));
        serverApps.Add (ulPacketSinkHelper.Install (remoteHost));
        UdpClientHelper ulClient (remoteHostAddr, ulPort);
        ulClient.SetAttribute ("Interval", TimeValue (MicroSeconds(100)));
        ulClient.SetAttribute ("MaxPackets", UintegerValue(0xFFFFFFFF));
        clientApps.Add (ulClient.Install (ueNodes.Get(u)));
      }
  }

  mmWaveHelper->EnableTraces();

  // Start applications
  serverApps.Start (Seconds(0.05));
  clientApps.Start (Seconds(0.05));
  clientApps.Stop (Seconds(0.5));

  Simulator::Stop(Seconds(1));
  Simulator::Run();
  Simulator::Destroy();



  return 0;
}
