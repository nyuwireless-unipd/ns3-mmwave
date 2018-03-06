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

int packetSinkDlRxCounter = 0;
int packetSinkUlRxCounter = 0;

void
DlSchedTrace (Ptr<OutputStreamWrapper> stream, DlSchedulingCallbackInfo params)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << (uint32_t)params.componentCarrierId << '\t' << params.sizeTb1 << std::endl;
}

static void
DlRx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet, const Address &from)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << packet->GetSize()<< std::endl;
	packetSinkDlRxCounter++;
}

static void
UlRx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet, const Address &from)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << packet->GetSize()<< std::endl;
	packetSinkUlRxCounter++;
}

void
TxMacPacketTrace (Ptr<OutputStreamWrapper> stream, uint16_t rnti, uint8_t componentCarrierId, uint32_t size)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t"
												<< (uint32_t)rnti << '\t'
												<< (uint32_t)componentCarrierId << '\t'
												<< size
												<< std::endl;
}

void
PositionTrace(Ptr<Node> n)
{
	Vector pos = n->GetObject<MobilityModel>()->GetPosition();
	std::cout << "UE position at " << Simulator::Now().GetSeconds() << "\t" << pos << std::endl;
	Simulator::Schedule (Seconds(1), &PositionTrace, n);
}

void
ChangeSpeed (Ptr<Node> n, Vector speed)
{
	n->GetObject<ConstantVelocityMobilityModel>()->SetVelocity(speed);
}

void
Traces(std::string outPath)
{
	//std::string path = "/NodeList/*/DeviceList/*/ComponentCarrierMap/*/LteEnbMac/DlScheduling";
	/*std::string filePath = "DlSchedTrace.txt";
	AsciiTraceHelper asciiTraceHelper;
	Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (filePath);
	*stream->GetStream () << "Time" << "\t" << "CC" << '\t' << "sizeTb1" << std::endl;
	Config::ConnectWithoutContext (path, MakeBoundCallback(&DlSchedTrace, stream));*/

	std::string dlTxMacPath = "/NodeList/*/DeviceList/*/ComponentCarrierMap/*/MmWaveEnbMac/TxMacPacketTraceEnb";
	std::string dlTxMacFilePath = outPath + "/DlTxMac.txt";
	AsciiTraceHelper dlTxMacAsciiTraceHelper;
	Ptr<OutputStreamWrapper> dlTxMacStream = dlTxMacAsciiTraceHelper.CreateFileStream (dlTxMacFilePath);
	//*stream->GetStream () << "Time" << "\t" << "CC" << '\t' << "sizeTb1" << std::endl;
	Config::ConnectWithoutContext (dlTxMacPath, MakeBoundCallback(&TxMacPacketTrace, dlTxMacStream));

	std::string ulTxMacPath = "/NodeList/*/DeviceList/*/MmWaveComponentCarrierMapUe/*/MmWaveUeMac/TxMacPacketTraceUe";
	std::string ulTxMacFilePath = outPath + "UlTxMac.txt";
	AsciiTraceHelper ulTxMacAsciiTraceHelper;
	Ptr<OutputStreamWrapper> ulTxMacStream = ulTxMacAsciiTraceHelper.CreateFileStream (ulTxMacFilePath);
	//*stream->GetStream () << "Time" << "\t" << "CC" << '\t' << "sizeTb1" << std::endl;
	Config::ConnectWithoutContext (ulTxMacPath, MakeBoundCallback(&TxMacPacketTrace, ulTxMacStream));


}


int main (int argc, char *argv[])
{
	bool useRR = false;
	double mmWaveCc0Freq = 28e9;
	double mmWaveCc1Freq = 73e9;
	double mmWaveCc0Bw = 1; // in GHz
	double mmWaveCc1Bw = 1; // in GHz
	double simTime;
	std::string filePath;
	uint8_t runSet = 1;
	double speed = 3;
	bool reportAllUeMeas = false;
	bool useOneMmWaveCc = false;
	double interPacketInterval = 1000;

	CommandLine cmd;
  cmd.AddValue("useRR", "If true use MmWaveRrComponentCarrierManager, else use MmWaveBaRrComponentCarrierManager", useRR);
  cmd.AddValue("mmWaveCc0Freq", "CC0 central frequency [Hz]", mmWaveCc0Freq);
	cmd.AddValue("mmWaveCc1Freq", "CC1 central frequency [Hz]", mmWaveCc1Freq);
	cmd.AddValue("mmWaveCc0Bw", "CC0 bandwidth (in GHz)", mmWaveCc0Bw);
	cmd.AddValue("mmWaveCc1Bw", "CC1 bandwidth (in GHz)", mmWaveCc1Bw);
  //cmd.AddValue("simTime", "Simulation time", simTime);
  cmd.AddValue("filePath", "Where to put the output files", filePath);
  cmd.AddValue("runSet", "Run number", runSet);
	cmd.AddValue("speed", "Speed in the x direction [m/s]",speed);
	cmd.AddValue("reportAllUeMeas", "Report the measures from all the CCs or only the max values", reportAllUeMeas);
	cmd.AddValue("useOneMmWaveCc", "Use one CC for mmWave", useOneMmWaveCc);
	cmd.AddValue("interPacketInterval", "inter-packet interval [us]", interPacketInterval);
  cmd.Parse (argc, argv);

	// RNG
  uint32_t seedSet = 1;
  RngSeedManager::SetSeed (seedSet);
  RngSeedManager::SetRun (runSet);

	// Set the correct file path
	std::cout << "File path: " << filePath << std::endl;
  Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlRlcOutputFilename", StringValue(filePath + "DlRlcStats.txt"));
  Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlRlcOutputFilename", StringValue(filePath + "UlRlcStats.txt"));
  Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlPdcpOutputFilename", StringValue(filePath + "DlPdcpStats.txt"));
  Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlPdcpOutputFilename", StringValue(filePath + "UlPdcpStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::EnbHandoverStartOutputFilename", StringValue(filePath + "EnbHandoverStartStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::EnbHandoverEndOutputFilename", StringValue(filePath + "EnbHandoverEndStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::MmWaveSinrOutputFilename", StringValue(filePath + "MmWaveSinrTime.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::LteSinrOutputFilename", StringValue(filePath + "LteSinrTime.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::UeHandoverStartOutputFilename", StringValue(filePath + "UeHandoverStartStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::UeHandoverEndOutputFilename", StringValue(filePath + "UeHandoverEndStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::CellIdStatsHandoverOutputFilename", StringValue(filePath + "CellIdStatsHandover.txt"));
  Config::SetDefault("ns3::MmWavePhyRxTrace::OutputFilename", StringValue(filePath + "RxPacketTrace.txt"));
  Config::SetDefault("ns3::LteRlcAm::BufferSizeFilename", StringValue(filePath + "RlcAmBufferSize.txt"));
	Config::SetDefault("ns3::McStatsCalculator::LteOutputFilename", StringValue(filePath + "LteSwitchStats.txt"));
	Config::SetDefault("ns3::McStatsCalculator::MmWaveOutputFilename", StringValue(filePath + "MmWaveSwitchStats.txt"));
	Config::SetDefault("ns3::McStatsCalculator::CellIdInTimeOutputFilename", StringValue(filePath + "CellIdStats.txt"));
	Config::SetDefault("ns3::CoreNetworkStatsCalculator::X2FileName", StringValue(filePath + "X2Stats.txt"));
	Config::SetDefault("ns3::CoreNetworkStatsCalculator::S1MmeFileName", StringValue(filePath + "MmeStats.txt"));

	// set the attributes
  Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(mmWaveCcMap.size()>1));
  Config::SetDefault("ns3::MmWaveHelper::LteUseCa",BooleanValue(lteCcMap.size()>1));
  Config::SetDefault("ns3::MmWaveHelper::NumberOfComponentCarriers",UintegerValue(mmWaveCcMap.size()));
	Config::SetDefault("ns3::MmWaveHelper::NumberOfLteComponentCarriers",UintegerValue(lteCcMap.size()));
  Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::MmWaveBaRrComponentCarrierManager"));
	Config::SetDefault("ns3::MmWaveHelper::LteEnbComponentCarrierManager",StringValue ("ns3::RrComponentCarrierManager"));
  //Config::SetDefault("ns3::MmWaveHelper::UseIdealRrc", BooleanValue(true));
	Config::SetDefault("ns3::MmWaveHelper::ChannelModel",StringValue("ns3::MmWave3gppChannel"));
  Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppPropagationLossModel"));
	Config::SetDefault("ns3::MmWaveHelper::RlcAmEnabled",BooleanValue(true));
	Config::SetDefault("ns3::MmWaveHelper::HarqEnabled",BooleanValue(true));
	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::TbDecodeLatency", UintegerValue(200.0));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::NumHarqProcess", UintegerValue(100));
	Config::SetDefault("ns3::LteEnbRrc::ReportAllUeMeas",BooleanValue(reportAllUeMeas));

	Config::SetDefault ("ns3::LteRlcAm::EnableAQM", BooleanValue(false));
  Config::SetDefault ("ns3::LteRlcAm::PollRetransmitTimer", TimeValue(MilliSeconds(2.0)));
  Config::SetDefault ("ns3::LteRlcAm::ReorderingTimer", TimeValue(MilliSeconds(1.0)));
  Config::SetDefault ("ns3::LteRlcAm::StatusProhibitTimer", TimeValue(MilliSeconds(1.0)));
  Config::SetDefault ("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MilliSeconds(2.0)));

	//The available channel scenarios are 'RMa', 'UMa', 'UMi-StreetCanyon', 'InH-OfficeMixed', 'InH-OfficeOpen', 'InH-ShoppingMall'
  std::string scenario = "UMa";
  std::string condition = "n"; // n = NLOS, l = LOS
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::ChannelCondition", StringValue(condition));
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Scenario", StringValue(scenario));
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::OptionalNlos", BooleanValue(false));
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Shadowing", BooleanValue(false)); // enable or disable the shadowing effect
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::InCar", BooleanValue(false)); // enable or disable the shadowing effect

  Config::SetDefault ("ns3::MmWave3gppChannel::UpdatePeriod", TimeValue (MilliSeconds (100))); // Set channel update period, 0 stands for no update.
  Config::SetDefault ("ns3::MmWave3gppChannel::CellScan", BooleanValue(false)); // Set true to use cell scanning method, false to use the default power method.
  Config::SetDefault ("ns3::MmWave3gppChannel::PortraitMode", BooleanValue(true)); // use blockage model with UT in portrait mode
  Config::SetDefault ("ns3::MmWave3gppChannel::NumNonselfBlocking", IntegerValue(4)); // number of non-self blocking obstacles
  Config::SetDefault ("ns3::MmWave3gppChannel::BlockerSpeed", DoubleValue(1)); // speed of non-self blocking obstacles

	// core network
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkDelay", TimeValue (MilliSeconds(1)));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkDataRate", DataRateValue(DataRate ("1000Gb/s")));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkMtu",  UintegerValue(10000));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::S1uLinkDelay", TimeValue (MicroSeconds(1000)));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::S1apLinkDelay", TimeValue (MilliSeconds(10))); // MME latency

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
	Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(mmWaveCc0Freq));
	Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(0));
	Ptr<MmWavePhyMacCommon> phyMacConfig0 = CreateObject<MmWavePhyMacCommon> ();
	uint32_t chunkPerRb0 = phyMacConfig0->GetNumChunkPerRb () * mmWaveCc0Bw;
	phyMacConfig0->SetNumChunkPerRB (chunkPerRb0);
	uint32_t numRefSc0 = phyMacConfig0->GetNumRefScPerSym () * mmWaveCc0Bw;
	phyMacConfig0->SetNumRefScPerSym (numRefSc0);

	Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(mmWaveCc1Freq));
	Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(1));
	Ptr<MmWavePhyMacCommon> phyMacConfig1 = CreateObject<MmWavePhyMacCommon> ();
	uint32_t chunkPerRb1 = phyMacConfig1->GetNumChunkPerRb () * mmWaveCc1Bw;
	phyMacConfig1->SetNumChunkPerRB (chunkPerRb1);
	uint32_t numRefSc1 = phyMacConfig1->GetNumRefScPerSym () * mmWaveCc1Bw;
	phyMacConfig1->SetNumRefScPerSym (numRefSc1);

	//create the carriers
	Ptr<MmWaveComponentCarrier> mmWaveCc0 = CreateObject<MmWaveComponentCarrier> ();
	mmWaveCc0->SetConfigurationParameters(phyMacConfig0);
	mmWaveCc0->SetAsPrimary(true);

	Ptr<MmWaveComponentCarrier> mmWaveCc1 = CreateObject<MmWaveComponentCarrier> ();
	mmWaveCc1->SetConfigurationParameters(phyMacConfig1);
	mmWaveCc1->SetAsPrimary(false);

	//create the ccMap
	std::map<uint8_t, MmWaveComponentCarrier > mmWaveCcMap;
	mmWaveCcMap [0] = *mmWaveCc0;
	if(useOneMmWaveCc == false)
	{
		mmWaveCcMap [1] = *mmWaveCc1;
	}

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
	NodeContainer lteEnbNodes;
	NodeContainer mmWaveEnbNodes;
  NodeContainer mcUeNodes;
  enbNodes.Create (3);
	lteEnbNodes.Add(enbNodes.Get(0));
	mmWaveEnbNodes.Add (enbNodes.Get (1));
	mmWaveEnbNodes.Add (enbNodes.Get (2));
  mcUeNodes.Create (1);

 // MOBILITY
	Vector mcUeInitialPos = Vector (-120.0, -30, 1.6);
	double mmWaveEnbDist = 150;
	Vector mcUeVelocity = Vector (speed, 0, 0);

  // set enb mobility
	// mmW eNB 1 ------------------- LTE eNB ------------------- mmW eNB2
	Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector (0, 0, 30.0));
	enbPositionAlloc->Add (Vector (0, 0, 15.0));
	enbPositionAlloc->Add (Vector (-mmWaveEnbDist, 0, 15.0));


  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator(enbPositionAlloc);
  enbmobility.Install (enbNodes);
  BuildingsHelper::Install (enbNodes);
	std::cout << "Lte eNB position " << lteEnbNodes.Get(0)->GetObject<MobilityModel>()->GetPosition() << std::endl;
	std::cout << "mmWave eNB position " << mmWaveEnbNodes.Get(0)->GetObject<MobilityModel>()->GetPosition() << std::endl;
	std::cout << "mmWave eNB position " << mmWaveEnbNodes.Get(1)->GetObject<MobilityModel>()->GetPosition() << std::endl;


  // set mc-ue mobility
	MobilityHelper mcUeMobility;
  Ptr<ListPositionAllocator> mcUePositionAlloc = CreateObject<ListPositionAllocator> ();
  mcUePositionAlloc->Add (mcUeInitialPos); // with distance = 15km txOpportunity is 903 bytes, so LTE CC1 is used too.

  mcUeMobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
  mcUeMobility.SetPositionAllocator(mcUePositionAlloc);
  mcUeMobility.Install (mcUeNodes);
  BuildingsHelper::Install (mcUeNodes);

	mcUeNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (mcUeVelocity);
	std::cout << "UE speed " << mcUeVelocity << std::endl;
	//Simulator::Schedule(Seconds(1),&ChangeSpeed, mcUeNodes.Get(0),Vector (-10, 0, 0));

	// Create Devices and install them in the Nodes
	NetDeviceContainer lteEnbDevs;
	lteEnbDevs = mmWaveHelper->InstallLteEnbDevice (lteEnbNodes);
	std::cout << "LTE eNB device installed" << std::endl;

  NetDeviceContainer mmWaveEnbDevs;
  mmWaveEnbDevs = mmWaveHelper->InstallEnbDevice (mmWaveEnbNodes);
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

  mmWaveHelper->AddX2Interface (lteEnbNodes, mmWaveEnbNodes);

  mmWaveHelper->AttachToClosestEnb (mcUeDevs, mmWaveEnbDevs, lteEnbDevs);


  // Install and start applications on UEs and remote host
  uint16_t dlPort = 1234;
  uint16_t ulPort = 2000;
  ApplicationContainer clientApps;
  ApplicationContainer serverApps;

  PacketSinkHelper dlPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), dlPort));
  PacketSinkHelper ulPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
  serverApps.Add (dlPacketSinkHelper.Install (mcUeNodes.Get(0)));
  serverApps.Add (ulPacketSinkHelper.Install (remoteHost));

  UdpClientHelper dlClient (ueIpIface.GetAddress (0), dlPort);
  dlClient.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
  dlClient.SetAttribute ("MaxPackets", UintegerValue(1000000));

  UdpClientHelper ulClient (remoteHostAddr, ulPort);
  ulClient.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
  ulClient.SetAttribute ("MaxPackets", UintegerValue(1000000));

  clientApps.Add (dlClient.Install (remoteHost));
  clientApps.Add (ulClient.Install (mcUeNodes.Get(0)));

	double appStartTime = 0.1;
  serverApps.Start (Seconds (appStartTime));
  clientApps.Start (Seconds (appStartTime));


  //mmWaveHelper->EnableTraces (); // enable all the Traces
	mmWaveHelper->EnableMcTraces();
	mmWaveHelper->EnablePdcpTraces();
	mmWaveHelper->EnableDlPhyTrace ();
	mmWaveHelper->EnableUlPhyTrace ();
  Traces(filePath); // mac tx traces

	// -------------------APPLICATION LAYER TRACES -------------------------------
	// 1. packets sent by the remoteHost and received by the UE
	std::string packetSinkDlFilePath = filePath + "PacketSinkDlRx.txt";
	AsciiTraceHelper asciiTraceHelper;
	Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (packetSinkDlFilePath);
	//*stream->GetStream () << "Packets sent by the remoteHost and received by the UE\n"
	//										  << "Time" << "\t" << "Size" << std::endl;
	serverApps.Get(0)->TraceConnectWithoutContext("Rx", MakeBoundCallback (&DlRx, stream));

	// 2. packets sent by the UE and received by the remoteHost
	std::string packetSinkUlFilePath = filePath + "PacketSinkUlRx.txt";
	Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream (packetSinkUlFilePath);
	//*stream1->GetStream () << "Packets sent by the UE and received by the remoteHost\n"
	//											 << "Time" << "\t" << "Size" << std::endl;
	serverApps.Get(1)->TraceConnectWithoutContext("Rx", MakeBoundCallback (&UlRx, stream1));
	//----------------------------------------------------------------------------

	// position
	Simulator::Schedule (Seconds(0.1), &PositionTrace, mcUeNodes.Get(0));
	std::cout << "MmWaveEnb1 " << mmWaveEnbNodes.Get(0)->GetObject<MobilityModel>()->GetPosition()<<std::endl;
	std::cout << "MmWaveEnb2 " << mmWaveEnbNodes.Get(1)->GetObject<MobilityModel>()->GetPosition()<<std::endl;

	simTime = ceil(100/speed);
	std::cout << "Simulation time " << simTime << std::endl;
  Simulator::Stop (Seconds (simTime));

  Simulator::Run ();

  // GtkConfigStore config;
  // config.ConfigureAttributes ();

  Simulator::Destroy ();

	std::cout << "Number of sent packets " << (simTime-appStartTime)/interPacketInterval*1e6 << std::endl;
	std::cout << "Remote Host received " << packetSinkUlRxCounter << " packets" << std::endl;
	std::cout << "UE received " << packetSinkDlRxCounter << " packets" << std::endl;

  return 0;
}
