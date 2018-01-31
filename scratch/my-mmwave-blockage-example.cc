/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
*   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
*   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License version 2 as
*   published by the Free Software Foundation;
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*   Author: Marco Miozzo <marco.miozzo@cttc.es>
*           Nicola Baldo  <nbaldo@cttc.es>
*
*   Modified by: Marco Mezzavilla < mezzavilla@nyu.edu>
*        	 	  Sourjya Dutta <sdutta@nyu.edu>
*        	 	  Russell Ford <russell.ford@nyu.edu>
*        		  Menglei Zhang <menglei@nyu.edu>
*/


#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/config-store.h"
#include "ns3/mmwave-helper.h"
#include <ns3/buildings-helper.h>
#include "ns3/global-route-manager.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/log.h"
#include <map>

using namespace ns3;

int
main (int argc, char *argv[])
{
 uint32_t chunkPerRb0 = 72;
 uint32_t chunkPerRb1 = 72;
 double frequency0 = 28e9;
 double frequency1 = 73e9;
 double simTime = 5;
 std::string filePath;

 CommandLine cmd;
 cmd.AddValue("chunkPerRb0", "Number of chunks per RB CC 0", chunkPerRb0);
 cmd.AddValue("chunkPerRb1", "Number of chunks per RB CC 1", chunkPerRb1);
 cmd.AddValue("frequency0", "CC 0 central frequency", frequency0);
 cmd.AddValue("frequency1", "CC 1 central frequency", frequency1);
 cmd.AddValue("simTime", "Simulation time", simTime);
 cmd.AddValue("filePath", "Where to put the output files", filePath);
 cmd.Parse (argc, argv);

 //set names of trace files
 std::string freq0str = std::to_string(frequency0/1e9);
 freq0str.resize(4);
 std::string freq1str = std::to_string(frequency1/1e9);
 freq1str.resize(4);
 std::string chunk0str = std::to_string(chunkPerRb0);
 std::string chunk1str = std::to_string(chunkPerRb1);

 //std::string filePath = "F0" + freq0str + "F1" + freq1str + "CN0" + chunk0str + "CN1" + chunk1str;

 std::cout << "File path: " << filePath << std::endl;
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlRlcOutputFilename", StringValue(filePath + "DlRlcStats.txt"));
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlRlcOutputFilename", StringValue(filePath + "UlRlcStats.txt"));
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlPdcpOutputFilename", StringValue(filePath + "DlPdcpStats.txt"));
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlPdcpOutputFilename", StringValue(filePath + "UlPdcpStats.txt"));
 Config::SetDefault("ns3::MmWavePhyRxTrace::OutputFilename", StringValue(filePath + "RxPacketTrace.txt"));
 Config::SetDefault("ns3::LteRlcAm::BufferSizeFilename", StringValue(filePath + "RlcAmBufferSize.txt"));

 //create MmWavePhyMacCommon objects
 Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(frequency0));
 Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(0));
 Config::SetDefault("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(chunkPerRb0));
 Ptr<MmWavePhyMacCommon> phyMacConfig1 = CreateObject<MmWavePhyMacCommon> ();
 double bandwidth1 = phyMacConfig1->GetNumRb() * phyMacConfig1->GetChunkWidth() * phyMacConfig1->GetNumChunkPerRb();

 Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(frequency1));
 Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(1));
 Config::SetDefault("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(chunkPerRb1));
 Ptr<MmWavePhyMacCommon> phyMacConfig2 = CreateObject<MmWavePhyMacCommon> ();
 double bandwidth2 = phyMacConfig2->GetNumRb() * phyMacConfig2->GetChunkWidth() * phyMacConfig2->GetNumChunkPerRb();

 //create the carriers
 Ptr<MmWaveComponentCarrier> cc1 = CreateObject<MmWaveComponentCarrier> ();
 cc1->SetConfigurationParameters(phyMacConfig1);
 cc1->SetAsPrimary(true);

 Ptr<MmWaveComponentCarrier> cc2 = CreateObject<MmWaveComponentCarrier> ();
 cc2->SetConfigurationParameters(phyMacConfig2);
 cc2->SetAsPrimary(false);

 std::cout << "Component Carrier " << std::to_string(phyMacConfig1->GetCcId ()) << " frequency : " << cc1->GetCenterFrequency() << " bandwidth : " << bandwidth1/1e6 << " MHz" <<std::endl;
 std::cout << "Component Carrier " << std::to_string(phyMacConfig2->GetCcId ()) << " frequency : " << cc2->GetCenterFrequency() << " bandwidth : " << bandwidth2/1e6 << " MHz" <<  std::endl;

 //create the ccMap
 std::map<uint8_t, MmWaveComponentCarrier > ccMap;
 ccMap [0] = *cc1;
 ccMap [1] = *cc2;

 //create and set the helper
 //first set UseCa = true, then NumberOfComponentCarriers
 std::string scenario = "UMa";
 std::string condition = "n";

 Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(true));
 Config::SetDefault("ns3::MmWaveHelper::NumberOfComponentCarriers",UintegerValue(2));
 Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::RrComponentCarrierManager"));
 Config::SetDefault("ns3::MmWaveHelper::ChannelModel",StringValue("ns3::MmWave3gppChannel"));
 Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppPropagationLossModel"));

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

 Ptr<MmWaveHelper> helper = CreateObject<MmWaveHelper> ();
 helper->SetCcPhyParams(ccMap);

 //set the blockageMap
 std::map <uint8_t, bool> blockageMap;
 blockageMap [0] = false;
 blockageMap [1] = true;
 helper->SetBlockageMap(blockageMap);


 //create the enb node
 NodeContainer enbNodes;
 enbNodes.Create(1);

 //set mobility
 Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
 enbPositionAlloc->Add (Vector (50.0, 50.0, 15.0));

 MobilityHelper enbmobility;
 enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
 enbmobility.SetPositionAllocator(enbPositionAlloc);
 enbmobility.Install (enbNodes);
 BuildingsHelper::Install (enbNodes);

 //install enb device
 NetDeviceContainer enbNetDevices = helper->InstallEnbDevice (enbNodes);
 std::cout<< "enb dev installed" << std::endl;

 //create ue node
 NodeContainer ueNodes;
 ueNodes.Create(1);

 //set mobility
 MobilityHelper uemobility;
 uemobility.SetMobilityModel ("ns3::RandomWalk2dMobilityModel",
                              "Bounds", RectangleValue (Rectangle (-20, 20, -20, 20)));
 Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
 uePositionAlloc->Add (Vector (0.0, 0.0, 1.6));
 uemobility.SetPositionAllocator(uePositionAlloc);
 uemobility.Install (ueNodes.Get (0));
 BuildingsHelper::Install (ueNodes);

 //install ue device
 NetDeviceContainer ueNetDevices = helper->InstallUeDevice(ueNodes);
 std::cout<< "ue dev installed" << std::endl;

 helper->AttachToClosestEnb (ueNetDevices, enbNetDevices);
 helper->EnableTraces();

 // Activate a data radio bearer
 enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
 EpsBearer bearer (q);
 helper->ActivateDataRadioBearer (ueNetDevices, bearer);

 BuildingsHelper::MakeMobilityModelConsistent ();

 Simulator::Stop (Seconds (simTime));
 Simulator::Run ();
 Simulator::Destroy ();

 return 0;
}
