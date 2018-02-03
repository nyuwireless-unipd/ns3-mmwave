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
 bool useCa = true;
 double ueDist = 50;
 bool blockage0 = false;
 bool blockage1 = false;
 //double chunkWidth = 13.889e6;
 uint32_t chunkPerRb0 = 72;
 uint32_t chunkPerRb1 = 72;
 double frequency0 = 28e9;
 double frequency1 = 73e9;
 double simTime = 5;
 uint8_t runSet = 1;
 std::string filePath;

 CommandLine cmd;
 cmd.AddValue("useCa", "If enabled use 2 CC", useCa);
 cmd.AddValue("ueDist", "Distance between Enb and Ue [m]", ueDist);
 cmd.AddValue("blockage0", "If enabled, PCC blockage = true", blockage0);
 cmd.AddValue("blockage1", "If enabled, SCC blockage = true", blockage1);
 cmd.AddValue("chunkPerRb0", "Number of chunks per RB CC 0", chunkPerRb0);
 cmd.AddValue("chunkPerRb1", "Number of chunks per RB CC 1", chunkPerRb1);
 cmd.AddValue("frequency0", "CC 0 central frequency", frequency0);
 cmd.AddValue("frequency1", "CC 1 central frequency", frequency1);
 cmd.AddValue("simTime", "Simulation time", simTime);
 cmd.AddValue("filePath", "Where to put the output files", filePath);
 cmd.AddValue("runSet", "Run number", runSet);
 cmd.Parse (argc, argv);

 // RNG
 uint32_t seedSet = 1;
 RngSeedManager::SetSeed (seedSet);
 RngSeedManager::SetRun (runSet);

 std::cout << "File path: " << filePath << std::endl;
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlRlcOutputFilename", StringValue(filePath + "DlRlcStats.txt"));
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlRlcOutputFilename", StringValue(filePath + "UlRlcStats.txt"));
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlPdcpOutputFilename", StringValue(filePath + "DlPdcpStats.txt"));
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlPdcpOutputFilename", StringValue(filePath + "UlPdcpStats.txt"));
 Config::SetDefault("ns3::MmWavePhyRxTrace::OutputFilename", StringValue(filePath + "RxPacketTrace.txt"));
 Config::SetDefault("ns3::LteRlcAm::BufferSizeFilename", StringValue(filePath + "RlcAmBufferSize.txt"));

 //create MmWavePhyMacCommon object
 Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(frequency0));
 Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(0));
 Config::SetDefault("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(chunkPerRb0));
 /*
 if(useCa)
 {
   Config::SetDefault("ns3::MmWavePhyMacCommon::ChunkWidth", DoubleValue(chunkWidth/2));
 }
 else
 {
   Config::SetDefault("ns3::MmWavePhyMacCommon::ChunkWidth", DoubleValue(chunkWidth));
 }
 */
 Ptr<MmWavePhyMacCommon> phyMacConfig0 = CreateObject<MmWavePhyMacCommon> ();
 double bandwidth0 = phyMacConfig0->GetNumRb() * phyMacConfig0->GetChunkWidth() * phyMacConfig0->GetNumChunkPerRb();

 //create the primary carrier
 Ptr<MmWaveComponentCarrier> cc0 = CreateObject<MmWaveComponentCarrier> ();
 cc0->SetConfigurationParameters(phyMacConfig0);
 cc0->SetAsPrimary(true);

 Ptr<MmWaveComponentCarrier> cc1;
 if(useCa)
 {
   //create MmWavePhyMacCommon object
   Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(frequency1));
   Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(1));
   Config::SetDefault("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(chunkPerRb1));
   //Config::SetDefault("ns3::MmWavePhyMacCommon::ChunkWidth", DoubleValue(chunkWidth/2));

   Ptr<MmWavePhyMacCommon> phyMacConfig1 = CreateObject<MmWavePhyMacCommon> ();
   //double bandwidth1 = phyMacConfig1->GetNumRb() * phyMacConfig1->GetChunkWidth() * phyMacConfig1->GetNumChunkPerRb();

   //create the secondary carrier
   cc1 = CreateObject<MmWaveComponentCarrier> ();
   cc1->SetConfigurationParameters(phyMacConfig1);
   cc1->SetAsPrimary(false);

  }

  //create the ccMap
  std::map<uint8_t, MmWaveComponentCarrier> ccMap;
  ccMap [0] = *cc0;
  if(useCa)
  {
    ccMap [1] = *cc1;
  }

  //set the blockageMap
  std::map <uint8_t, bool> blockageMap;
  blockageMap [0] = blockage0;
  if(useCa)
  {
    blockageMap [1] = blockage1;
  }

  for(uint8_t i = 0; i < ccMap.size(); i++)
  {
    std::cout << "Component Carrier " << (uint32_t)(ccMap[i].GetConfigurationParameters()->GetCcId ())
              << " frequency : " << ccMap[i].GetConfigurationParameters()->GetCenterFrequency()/1e9 << " GHz,"
              << " bandwidth : " << bandwidth0/1e6 << " MHz,"
              << " blockage : " << blockageMap[i]
              << std::endl;
  }


 //create and set the helper
 //first set UseCa = true, then NumberOfComponentCarriers
 Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(useCa));
 if(useCa)
 {
   Config::SetDefault("ns3::MmWaveHelper::NumberOfComponentCarriers",UintegerValue(2));
   Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::RrComponentCarrierManager"));
 }
 Config::SetDefault("ns3::MmWaveHelper::ChannelModel",StringValue("ns3::MmWave3gppChannel"));
 Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppPropagationLossModel"));

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

 Ptr<MmWaveHelper> helper = CreateObject<MmWaveHelper> ();
 helper->SetCcPhyParams(ccMap);
 helper->SetBlockageMap(blockageMap);


 //create the enb node
 NodeContainer enbNodes;
 enbNodes.Create(1);

 //set mobility
 Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
 enbPositionAlloc->Add (Vector (0.0, 0.0, 15.0));

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
 std::cout << "Distance : " << (uint32_t)ueDist << " m" << std::endl;
 MobilityHelper uemobility;
 uemobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
 Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
 uePositionAlloc->Add (Vector (ueDist, 0.0, 1.6));
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
