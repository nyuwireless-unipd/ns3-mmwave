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
 uint32_t bandDiv = 2; // if useCa=true, CC0 get (1-1/bandDiv)*totalBandwidth, CC1 get (1/bandDiv)*totalBandwidth
 bool blockage0 = false;
 bool blockage1 = false;
 int numRefSc0 = 864;
 int numRefSc1 = 864;
 //double chunkWidth = 13.889e6;
 uint32_t chunkPerRb0 = 72;
 uint32_t chunkPerRb1 = 72;
 double frequency0 = 28e9;
 double frequency1 = 73e9;
 double simTime = 5;
 uint32_t runSet = 1;
 std::string filePath;

 CommandLine cmd;
 cmd.AddValue("useCa", "If enabled use 2 CC", useCa);
 cmd.AddValue("bandDiv", "Bandwidth divisor", bandDiv);
 cmd.AddValue("blockage0", "If enabled, PCC blockage = true", blockage0);
 cmd.AddValue("blockage1", "If enabled, SCC blockage = true", blockage1);
 cmd.AddValue("frequency0", "CC 0 central frequency", frequency0);
 cmd.AddValue("frequency1", "CC 1 central frequency", frequency1);
 cmd.AddValue("simTime", "Simulation time", simTime);
 cmd.AddValue("filePath", "Where to put the output files", filePath);
 cmd.AddValue("runSet", "Run number", runSet);
 cmd.Parse (argc, argv);

 if(useCa)
 {
   chunkPerRb0 = chunkPerRb0*(bandDiv-1)/bandDiv;
   chunkPerRb1 = chunkPerRb1/bandDiv;
   numRefSc0 = numRefSc0*(bandDiv-1)/bandDiv;
   numRefSc1 = numRefSc1/bandDiv;
 }

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
 phyMacConfig0->SetNumRefScPerSym( numRefSc0 );

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
   phyMacConfig1->SetNumRefScPerSym( numRefSc1 );

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
    Ptr<MmWavePhyMacCommon> phyMacConfig = ccMap[i].GetConfigurationParameters();
    std::cout << "Component Carrier " << (uint32_t)(phyMacConfig->GetCcId ())
              << " frequency : " << phyMacConfig->GetCenterFrequency()/1e9 << " GHz,"
              << " bandwidth : " << (phyMacConfig->GetNumRb() * phyMacConfig->GetChunkWidth() * phyMacConfig->GetNumChunkPerRb())/1e6 << " MHz,"
              << " blockage : " << blockageMap[i]
              << ", numRefSc: " << (uint32_t)phyMacConfig->GetNumRefScPerSym()
              << ", ChunkPerRB: " << phyMacConfig->GetNumChunkPerRb()
              << std::endl;
  }


 //create and set the helper
 //first set UseCa = true, then NumberOfComponentCarriers
 Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(useCa));
 if(useCa)
 {
   Config::SetDefault("ns3::MmWaveHelper::NumberOfComponentCarriers",UintegerValue(2));
   Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::MmWaveComponentCarrierManager"));
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
 //set mobility
 MobilityHelper uemobility;
 uemobility.SetMobilityModel ("ns3::RandomWalk2dMobilityModel",
                              "Bounds", RectangleValue (Rectangle (-200, 200, -200, 200)));
 Config::SetDefault ("ns3::UniformDiscPositionAllocator::rho", DoubleValue(150));
 Ptr<UniformDiscPositionAllocator> uePositionAlloc = CreateObject<UniformDiscPositionAllocator> ();
 uemobility.SetPositionAllocator(uePositionAlloc);
 uemobility.Install (ueNodes.Get (0));
 BuildingsHelper::Install (ueNodes);
 NS_LOG_UNCOND("ue pos :" << ueNodes.Get(0)->GetObject<MobilityModel>()->GetPosition());

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
