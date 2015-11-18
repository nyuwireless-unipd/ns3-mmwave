/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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
 * Author: Jaume Nin <jaume.nin@cttc.cat>
 */

#include "ns3/mmwave-helper.h"
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
#include "ns3/rng-seed-manager.h"
//#include "ns3/gtk-config-store.h"

using namespace ns3;

/**
 * Sample simulation script for LTE+EPC. It instantiates several eNodeB,
 * attaches one UE per eNodeB starts a flow for each UE to  and from a remote host.
 * It also  starts yet another flow between each UE pair.
 */
NS_LOG_COMPONENT_DEFINE ("MmWaveEpcTdma");
int
main (int argc, char *argv[])
{
	//LogComponentEnable ("LteUeRrc", LOG_LEVEL_ALL);
	//LogComponentEnable ("LteEnbRrc", LOG_LEVEL_ALL);
	//	LogComponentEnable("MmWavePointToPointEpcHelper",LOG_LEVEL_ALL);
	//	LogComponentEnable("EpcUeNas",LOG_LEVEL_ALL);
		LogComponentEnable ("MmWaveSpectrumPhy", LOG_LEVEL_DEBUG);
	LogComponentEnable ("MmWaveBeamforming", LOG_LEVEL_DEBUG);
	LogComponentEnable ("MmWaveUePhy", LOG_LEVEL_DEBUG);
	LogComponentEnable ("MmWaveEnbPhy", LOG_LEVEL_DEBUG);
	LogComponentEnable ("MmWaveFlexTtiHarqMacScheduler", LOG_LEVEL_DEBUG);
	//LogComponentEnable ("LteRlcUm", LOG_LEVEL_LOGIC);
	//LogComponentEnable ("MmWaveUeMac", LOG_LEVEL_LOGIC);
	//LogComponentEnable ("UdpClient", LOG_LEVEL_INFO);
	//LogComponentEnable ("PacketSink", LOG_LEVEL_INFO);
	//LogComponentEnable("PropagationLossModel",LOG_LEVEL_ALL);


	uint16_t numEnb = 1;
	uint16_t numUe = 4;
	double simTime = 0.5;
	double interPacketInterval = 1000;  // 500 microseconds
	double distance = 250.0;  // eNB-UE distance in meters

	// Command line arguments
	CommandLine cmd;
	cmd.AddValue("numEnb", "Number of eNBs", numEnb);
	cmd.AddValue("numUe", "Number of UEs per eNB", numUe);
	cmd.AddValue("simTime", "Total duration of the simulation [s])", simTime);
	cmd.AddValue("interPacketInterval", "Inter-packet interval [us])", interPacketInterval);
	cmd.Parse(argc, argv);

	Config::SetDefault ("ns3::MmWaveFlexTtiHarqMacScheduler::HarqEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::ResourceBlockNum", UintegerValue(1));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(72));
	Config::SetDefault ("ns3::MmWaveBeamforming::LongTermUpdatePeriod", TimeValue (MilliSeconds (10.0)));
	Config::SetDefault ("ns3::LteEnbRrc::SystemInformationPeriodicity", TimeValue (MilliSeconds (5.0)));

<<<<<<< HEAD
	RngSeedManager::SetSeed (1234);
=======
	Ptr<MmWaveHelper> mmwaveHelper = CreateObject<MmWaveHelper> ();
	Ptr<MmWavePointToPointEpcHelper>  epcHelper = CreateObject<MmWavePointToPointEpcHelper> ();
>>>>>>> b36c54152804fd16ccc9464c4123d6ceeba3fb48

	Ptr<MmWaveHelper> mmwaveHelper = CreateObject<MmWaveHelper> ();
	mmwaveHelper->SetHarqEnabled (true);
	Ptr<MmWavePointToPointEpcHelper>  epcHelper = CreateObject<MmWavePointToPointEpcHelper> ();
	mmwaveHelper->SetEpcHelper (epcHelper);

	ConfigStore inputConfig;
	inputConfig.ConfigureDefaults();

	// parse again so you can override default values from the command line
	cmd.Parse(argc, argv);

	Ptr<Node> pgw = epcHelper->GetPgwNode ();

	// Create a single RemoteHost
	NodeContainer remoteHostContainer;
	remoteHostContainer.Create (1);
	Ptr<Node> remoteHost = remoteHostContainer.Get (0);
	InternetStackHelper internet;
	internet.Install (remoteHostContainer);

	// Create the Internet
	PointToPointHelper p2ph;
	p2ph.SetDeviceAttribute ("DataRate", DataRateValue (DataRate ("100Gb/s")));
	p2ph.SetDeviceAttribute ("Mtu", UintegerValue (1500));
	p2ph.SetChannelAttribute ("Delay", TimeValue (MicroSeconds (100.0)));
	NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);
	Ipv4AddressHelper ipv4h;
	ipv4h.SetBase ("1.0.0.0", "255.0.0.0");
	Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign (internetDevices);
	// interface 0 is localhost, 1 is the p2p device
	Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress (1);

	Ipv4StaticRoutingHelper ipv4RoutingHelper;
	Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
	remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.0.0.0"), 1);

	NodeContainer ueNodes;
	NodeContainer enbNodes;
	enbNodes.Create(numEnb);
	ueNodes.Create(numUe);

	// Install Mobility Model
	Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
	enbPositionAlloc->Add (Vector (0.0, 0.0, 0.0));
	MobilityHelper enbmobility;
	enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	enbmobility.SetPositionAllocator(enbPositionAlloc);
	enbmobility.Install (enbNodes);

	MobilityHelper uemobility;
	Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
	uePositionAlloc->Add (Vector (distance, 0.0, 0.0));
	uemobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	uemobility.SetPositionAllocator(uePositionAlloc);
	uemobility.Install (ueNodes);

	// Install mmWave Devices to the nodes
	NetDeviceContainer enbmmWaveDevs = mmwaveHelper->InstallEnbDevice (enbNodes);
	NetDeviceContainer uemmWaveDevs = mmwaveHelper->InstallUeDevice (ueNodes);

	// Install the IP stack on the UEs
	internet.Install (ueNodes);
	Ipv4InterfaceContainer ueIpIface;
	ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (uemmWaveDevs));
	// Assign IP address to UEs, and install applications
	for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
	{
		Ptr<Node> ueNode = ueNodes.Get (u);
		// Set the default gateway for the UE
		Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (ueNode->GetObject<Ipv4> ());
		ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);
	}

	mmwaveHelper->AttachToClosestEnb (uemmWaveDevs, enbmmWaveDevs);


	// Install and start applications on UEs and remote host
	uint16_t dlPort = 1234;
	uint16_t ulPort = 2000;
	uint16_t otherPort = 3000;
	ApplicationContainer clientApps;
	ApplicationContainer serverApps;
	for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
	{
		++ulPort;
		++otherPort;
		PacketSinkHelper dlPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), dlPort));
		PacketSinkHelper ulPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
		PacketSinkHelper packetSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), otherPort));
		serverApps.Add (dlPacketSinkHelper.Install (ueNodes.Get(u)));
		serverApps.Add (ulPacketSinkHelper.Install (remoteHost));
		serverApps.Add (packetSinkHelper.Install (ueNodes.Get(u)));

		UdpClientHelper dlClient (ueIpIface.GetAddress (u), dlPort);
		dlClient.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
		dlClient.SetAttribute ("MaxPackets", UintegerValue(1000000));
		dlClient.SetAttribute ("PacketSize", UintegerValue(1450));

		UdpClientHelper ulClient (remoteHostAddr, ulPort);
		ulClient.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
		ulClient.SetAttribute ("MaxPackets", UintegerValue(1000000));
		dlClient.SetAttribute ("PacketSize", UintegerValue(1450));

//		UdpClientHelper client (ueIpIface.GetAddress (u), otherPort);
//		client.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
//		client.SetAttribute ("MaxPackets", UintegerValue(1000000));

		clientApps.Add (dlClient.Install (remoteHost));
		clientApps.Add (ulClient.Install (ueNodes.Get(u)));
//		if (u+1 < ueNodes.GetN ())
//		{
//			clientApps.Add (client.Install (ueNodes.Get(u+1)));
//		}
//		else
//		{
//			clientApps.Add (client.Install (ueNodes.Get(0)));
//		}
	}
	serverApps.Start (Seconds (0.001));
	clientApps.Start (Seconds (0.001));
	mmwaveHelper->EnableTraces ();
	// Uncomment to enable PCAP tracing
	//p2ph.EnablePcapAll("mmwave-epc-simple");

	Simulator::Stop(Seconds(simTime));
	Simulator::Run();

	/*GtkConfigStore config;
  config.ConfigureAttributes();*/

	Simulator::Destroy();
	return 0;

}

