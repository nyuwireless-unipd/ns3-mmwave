/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2015 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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


#include "ns3/core-module.h"
#include "ns3/config-store.h"
#include <ns3/buildings-helper.h>
#include "ns3/component-carrier.h"
#include "ns3/cc-helper.h"
#include "ns3/mmwave-helper.h"
#include "ns3/mobility-module.h"
#include "ns3/global-route-manager.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/log.h"
#include "ns3/mmwave-point-to-point-epc-helper.h"

using namespace ns3;

void
DlSchedTrace (Ptr<OutputStreamWrapper> stream, DlSchedulingCallbackInfo params)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << (uint32_t)params.componentCarrierId << '\t' << params.sizeTb1 << std::endl;
}

void
Traces(void)
{
	std::string path = "/NodeList/*/DeviceList/*/ComponentCarrierMap/*/LteEnbMac/DlScheduling";
	std::string filePath = "DlSchedTrace.txt";
	AsciiTraceHelper asciiTraceHelper;
	Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream (filePath);
	*stream1->GetStream () << "Time" << "\t" << "CC" << '\t' << "sizeTb1" << std::endl;
	Config::ConnectWithoutContext (path, MakeBoundCallback(&DlSchedTrace, stream1));
}



void Print ( ComponentCarrier cc);

int main (int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse (argc, argv);

  // create the map of LTE component carriers
  Ptr<CcHelper> lteCcHelper = CreateObject<CcHelper> ();
  lteCcHelper->SetNumberOfComponentCarriers(2);
  lteCcHelper->SetUlEarfcn (18100);
  lteCcHelper->SetDlEarfcn (100);
  lteCcHelper->SetDlBandwidth (100);
  lteCcHelper->SetUlBandwidth (100);
  std::map< uint8_t, ComponentCarrier > lteCcMap = lteCcHelper->EquallySpacedCcs ();
  lteCcMap.at(0).SetAsPrimary(true);

  std::cout << " LteCcMap size " << lteCcMap.size () << std::endl;
  for (std::map< uint8_t, ComponentCarrier >::iterator it = lteCcMap.begin (); it !=lteCcMap.end (); it++)
    {
      ComponentCarrier cc = it->second;
      std::cout << " CC ID " << (uint16_t)it->first
                << " UlBandwidth " << uint16_t (cc.GetUlBandwidth ())
                << " DlBandwidth " << uint16_t (cc.GetDlBandwidth ())
                << " Dl Earfcn " << cc.GetDlEarfcn ()
                << " Ul Earfcn " << cc.GetUlEarfcn ()
                << " - Is this the Primary Channel? " << cc.IsPrimary ()
                << std::endl;
    }

  // create the map of mmWave component carriers
  //create MmWavePhyMacCommon objects
	Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(28e9));
	Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(0));
	Ptr<MmWavePhyMacCommon> phyMacConfig1 = CreateObject<MmWavePhyMacCommon> ();

	Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(73e9));
	Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(1));
	Ptr<MmWavePhyMacCommon> phyMacConfig2 = CreateObject<MmWavePhyMacCommon> ();

	//create the carriers
	Ptr<MmWaveComponentCarrier> mmWaveCc1 = CreateObject<MmWaveComponentCarrier> ();
	mmWaveCc1->SetConfigurationParameters(phyMacConfig1);
	mmWaveCc1->SetAsPrimary(true);

	Ptr<MmWaveComponentCarrier> mmWaveCc2 = CreateObject<MmWaveComponentCarrier> ();
	mmWaveCc2->SetConfigurationParameters(phyMacConfig2);
	mmWaveCc2->SetAsPrimary(false);

	//create the ccMap
	std::map<uint8_t, MmWaveComponentCarrier > mmWaveCcMap;
	mmWaveCcMap [0] = *mmWaveCc1;
	//mmWaveCcMap [1] = *mmWaveCc2;

  // print mmWave CC parameters
  std::cout << " mmWaveCcMap size " << mmWaveCcMap.size () << std::endl;
  for(uint8_t i = 0; i < mmWaveCcMap.size(); i++)
  {
    Ptr<MmWavePhyMacCommon> phyMacConfig = mmWaveCcMap[i].GetConfigurationParameters();
    std::cout << "Component Carrier " << (uint32_t)(phyMacConfig->GetCcId ())
              << " frequency : " << phyMacConfig->GetCenterFrequency()/1e9 << " GHz,"
              << " bandwidth : " << (phyMacConfig->GetNumRb() * phyMacConfig->GetChunkWidth() * phyMacConfig->GetNumChunkPerRb())/1e6 << " MHz,"
              << " is Primary? " << mmWaveCcMap[i].IsPrimary ()
              //<< ", numRefSc: " << (uint32_t)phyMacConfig->GetNumRefScPerSym()
              //<< ", ChunkPerRB: " << phyMacConfig->GetNumChunkPerRb()
              << std::endl;
  }


  // set the attributes
  Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(mmWaveCcMap.size()>1));
  Config::SetDefault("ns3::MmWaveHelper::LteUseCa",BooleanValue(lteCcMap.size()>1));
  Config::SetDefault("ns3::MmWaveHelper::NumberOfComponentCarriers",UintegerValue(mmWaveCcMap.size()));
	Config::SetDefault("ns3::MmWaveHelper::NumberOfLteComponentCarriers",UintegerValue(lteCcMap.size()));
  Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::MmWaveBaRrComponentCarrierManager"));
	Config::SetDefault("ns3::MmWaveHelper::LteEnbComponentCarrierManager",StringValue ("ns3::RrComponentCarrierManager"));
  //Config::SetDefault("ns3::MmWaveHelper::UseIdealRrc", BooleanValue(true));
  // create the helper
  Ptr<MmWaveHelper> mmWaveHelper = CreateObject<MmWaveHelper> ();
  mmWaveHelper->SetLteCcPhyParams (lteCcMap);
  mmWaveHelper->SetCcPhyParams (mmWaveCcMap);

  Ptr<MmWavePointToPointEpcHelper> epcHelper = CreateObject<MmWavePointToPointEpcHelper> ();
  mmWaveHelper->SetEpcHelper (epcHelper);

  // Create the Internet by connecting remoteHost to pgw. Setup routing too
  Ptr<Node> pgw = epcHelper->GetPgwNode ();

  // Create remotehost
  NodeContainer remoteHostContainer;
  remoteHostContainer.Create (1);
  InternetStackHelper internet;
  internet.Install (remoteHostContainer);
  Ipv4StaticRoutingHelper ipv4RoutingHelper;
  Ipv4InterfaceContainer internetIpIfaces;

  Ptr<Node> remoteHost = remoteHostContainer.Get (0);
  // Create the Internet
  PointToPointHelper p2ph;
  p2ph.SetDeviceAttribute ("DataRate", DataRateValue (DataRate ("100Gb/s")));
  p2ph.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  p2ph.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (0.01)));

  NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);

  Ipv4AddressHelper ipv4h;
  ipv4h.SetBase ("1.0.0.0", "255.255.0.0");
  internetIpIfaces = ipv4h.Assign (internetDevices);
  // interface 0 is localhost, 1 is the p2p device
  Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress (1);

  Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
  remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.255.0.0"), 1);

  // create the nodes
  NodeContainer enbNodes;
  NodeContainer mcUeNodes;
  enbNodes.Create (2);
  mcUeNodes.Create (1);

  // set enb mobility
	Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector (0.0, 0.0, 30.0));

  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator(enbPositionAlloc);
  enbmobility.Install (enbNodes);
  BuildingsHelper::Install (enbNodes);

  // set mc-ue mobility
	MobilityHelper mcUeMobility;
  Ptr<ListPositionAllocator> mcUePositionAlloc = CreateObject<ListPositionAllocator> ();
  mcUePositionAlloc->Add (Vector (80.0, 0.0, 5.0)); // with distance = 15km txOpportunity is 903 bytes, so CC1 is used too.

  mcUeMobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  mcUeMobility.SetPositionAllocator(mcUePositionAlloc);
  mcUeMobility.Install (mcUeNodes);
  BuildingsHelper::Install (mcUeNodes);

	// Create Devices and install them in the Nodes
	NetDeviceContainer lteEnbDevs;
	lteEnbDevs = mmWaveHelper->InstallLteEnbDevice (enbNodes.Get(0));
	std::cout << "LTE eNB device installed" << std::endl;

  NetDeviceContainer mmWaveEnbDevs;
  mmWaveEnbDevs = mmWaveHelper->InstallEnbDevice (enbNodes.Get(1));
  std::cout << "mmWave eNB device installed" << std::endl;

  NetDeviceContainer mcUeDevs;
  mcUeDevs = mmWaveHelper->InstallMcUeDevice (mcUeNodes);
  std::cout << "McUe device installed" << std::endl;

  // Install the IP stack on the UEs
  internet.Install (mcUeNodes);
  Ipv4InterfaceContainer ueIpIface;
  ueIpIface = epcHelper->AssignUeIpv4Address (mcUeDevs);
  // Assign IP address to UEs, and install applications
  // Set the default gateway for the UE
  Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (mcUeNodes.Get (0)->GetObject<Ipv4> ());
  ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);

  NodeContainer lteEnbNodes;
  lteEnbNodes.Add(enbNodes.Get(0));
  NodeContainer mmWaveEnbNodes;
  mmWaveEnbNodes.Add(enbNodes.Get(1));
  mmWaveHelper->AddX2Interface (lteEnbNodes, mmWaveEnbNodes);

  mmWaveHelper->AttachToClosestEnb (mcUeDevs, mmWaveEnbDevs, lteEnbDevs);


  // Install and start applications on UEs and remote host
  uint16_t dlPort = 1234;
  uint16_t ulPort = 2000;
  ApplicationContainer clientApps;
  ApplicationContainer serverApps;

  uint16_t interPacketInterval = 1;

  PacketSinkHelper dlPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), dlPort));
  PacketSinkHelper ulPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
  serverApps.Add (dlPacketSinkHelper.Install (mcUeNodes.Get(0)));
  serverApps.Add (ulPacketSinkHelper.Install (remoteHost));

  UdpClientHelper dlClient (ueIpIface.GetAddress (0), dlPort);
  dlClient.SetAttribute ("Interval", TimeValue (MilliSeconds(interPacketInterval)));
  dlClient.SetAttribute ("MaxPackets", UintegerValue(1000000));

  UdpClientHelper ulClient (remoteHostAddr, ulPort);
  ulClient.SetAttribute ("Interval", TimeValue (MilliSeconds(interPacketInterval)));
  ulClient.SetAttribute ("MaxPackets", UintegerValue(1000000));

  clientApps.Add (dlClient.Install (remoteHost));
  clientApps.Add (ulClient.Install (mcUeNodes.Get(0)));

  serverApps.Start (Seconds (0.01));
  clientApps.Start (Seconds (0.01));


  mmWaveHelper->EnableTraces ();
  Traces(); //Mac Traces

  Simulator::Stop (Seconds (0.5));

  Simulator::Run ();

  // GtkConfigStore config;
  // config.ConfigureAttributes ();

  Simulator::Destroy ();
  return 0;
}
