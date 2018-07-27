/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */

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
using namespace mmwave;

/* In this example a single UE is connected with a single MmWave BS. The UE is
 * placed at distance ueDist from the BS and it does not move. The system
 * bandwidth is fixed at 1GHz. If CA is enabled, 2 CCs are used and each of them
 * uses half of the total bandwidth.
 */

int
main (int argc, char *argv[])
{
 bool useCa = true;
 double ueDist = 50;
 bool blockage0 = false;
 bool blockage1 = false;
 int numRefSc = 864;
 uint32_t chunkPerRb0 = 72;
 uint32_t chunkPerRb1 = 72;
 double frequency0 = 28e9;
 double frequency1 = 73e9;
 double simTime = 5;
 uint32_t runSet = 1;
 std::string filePath;

 CommandLine cmd;
 cmd.AddValue("useCa", "If enabled use 2 CC", useCa);
 cmd.AddValue("ueDist", "Distance between Enb and Ue [m]", ueDist);
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
   // use half BW per carrier
   chunkPerRb0 = chunkPerRb0/2;
   chunkPerRb1 = chunkPerRb1/2;
   numRefSc = numRefSc/2;
 }

 // RNG
 uint32_t seedSet = 1;
 RngSeedManager::SetSeed (seedSet);
 RngSeedManager::SetRun (runSet);

 // set output file names
 std::cout << "File path: " << filePath << std::endl;
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlRlcOutputFilename", StringValue(filePath + "DlRlcStats.txt"));
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlRlcOutputFilename", StringValue(filePath + "UlRlcStats.txt"));
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlPdcpOutputFilename", StringValue(filePath + "DlPdcpStats.txt"));
 Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlPdcpOutputFilename", StringValue(filePath + "UlPdcpStats.txt"));
 Config::SetDefault("ns3::MmWavePhyRxTrace::OutputFilename", StringValue(filePath + "RxPacketTrace.txt"));
 Config::SetDefault("ns3::LteRlcAm::BufferSizeFilename", StringValue(filePath + "RlcAmBufferSize.txt"));

 // CC 0
 // 1. create MmWavePhyMacCommon object
 Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(frequency0));
 Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(0));
 Config::SetDefault("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(chunkPerRb0));
 Ptr<MmWavePhyMacCommon> phyMacConfig0 = CreateObject<MmWavePhyMacCommon> ();
 phyMacConfig0->SetNumRefScPerSym( numRefSc );
 double bandwidth0 = phyMacConfig0->GetNumRb() * phyMacConfig0->GetChunkWidth() * phyMacConfig0->GetNumChunkPerRb();

 // 2. create the MmWaveComponentCarrier object
 Ptr<MmWaveComponentCarrier> cc0 = CreateObject<MmWaveComponentCarrier> ();
 cc0->SetConfigurationParameters(phyMacConfig0);
 cc0->SetAsPrimary(true);

 // CC 1
 Ptr<MmWaveComponentCarrier> cc1;
 if(useCa)
 {
   // 1. create MmWavePhyMacCommon object
   Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(frequency1));
   Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(1));
   Config::SetDefault("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(chunkPerRb1));
   Ptr<MmWavePhyMacCommon> phyMacConfig1 = CreateObject<MmWavePhyMacCommon> ();
   phyMacConfig1->SetNumRefScPerSym( numRefSc );

   // 2. create the MmWaveComponentCarrier object
   cc1 = CreateObject<MmWaveComponentCarrier> ();
   cc1->SetConfigurationParameters(phyMacConfig1);
   cc1->SetAsPrimary(false);

  }

  // create the CC map
  std::map<uint8_t, MmWaveComponentCarrier> ccMap;
  ccMap [0] = *cc0;
  if(useCa)
  {
    ccMap [1] = *cc1;
  }

  // set the blockageMap
  std::map <uint8_t, bool> blockageMap;
  blockageMap [0] = blockage0;
  if(useCa)
  {
    blockageMap [1] = blockage1;
  }

  // print CC parameters
  for(uint8_t i = 0; i < ccMap.size(); i++)
  {
    std::cout << "Component Carrier " << (uint32_t)(ccMap[i].GetConfigurationParameters()->GetCcId ())
              << " frequency : " << ccMap[i].GetConfigurationParameters()->GetCenterFrequency()/1e9 << " GHz,"
              << " bandwidth : " << bandwidth0/1e6 << " MHz,"
              << " blockage : " << blockageMap[i]
              << std::endl;
  }


 // create and set the helper
 // first set UseCa = true, then NumberOfComponentCarriers
 Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(useCa));
 if(useCa)
 {
   Config::SetDefault("ns3::MmWaveHelper::NumberOfComponentCarriers",UintegerValue(2));
   Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::MmWaveRrComponentCarrierManager"));
 }
 Config::SetDefault("ns3::MmWaveHelper::ChannelModel",StringValue("ns3::MmWave3gppChannel"));
 Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppPropagationLossModel"));

 // The available channel scenarios are 'RMa', 'UMa', 'UMi-StreetCanyon', 'InH-OfficeMixed', 'InH-OfficeOpen', 'InH-ShoppingMall'
 std::string scenario = "UMa";
 std::string condition = "n"; // n = NLOS, l = LOS
 Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::ChannelCondition", StringValue(condition));
 Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Scenario", StringValue(scenario));
 Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::OptionalNlos", BooleanValue(false));
 Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Shadowing", BooleanValue(false)); // enable or disable the shadowing effect
 Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::InCar", BooleanValue(false)); // enable or disable the shadowing effect

 Config::SetDefault ("ns3::MmWave3gppChannel::UpdatePeriod", TimeValue (MilliSeconds (100))); // Set channel update period, 0 stands for no update.
 Config::SetDefault ("ns3::MmWave3gppChannel::DirectBeam", BooleanValue(true)); // Set true to perform the beam in the exact direction of receiver node.
 Config::SetDefault ("ns3::MmWave3gppChannel::PortraitMode", BooleanValue(true)); // use blockage model with UT in portrait mode
 Config::SetDefault ("ns3::MmWave3gppChannel::NumNonselfBlocking", IntegerValue(4)); // number of non-self blocking obstacles
 Config::SetDefault ("ns3::MmWave3gppChannel::BlockerSpeed", DoubleValue(1)); // speed of non-self blocking obstacles

 Ptr<MmWaveHelper> helper = CreateObject<MmWaveHelper> ();
 helper->SetCcPhyParams(ccMap);
 helper->SetBlockageMap(blockageMap);


 // create the enb node
 NodeContainer enbNodes;
 enbNodes.Create(1);

 // set mobility
 Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
 enbPositionAlloc->Add (Vector (0.0, 0.0, 15.0));

 MobilityHelper enbmobility;
 enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
 enbmobility.SetPositionAllocator(enbPositionAlloc);
 enbmobility.Install (enbNodes);
 BuildingsHelper::Install (enbNodes);

 // install enb device
 NetDeviceContainer enbNetDevices = helper->InstallEnbDevice (enbNodes);
 std::cout<< "eNB device installed" << std::endl;

 // create ue node
 NodeContainer ueNodes;
 ueNodes.Create(1);

 // set mobility
 std::cout << "Distance : " << (uint32_t)ueDist << " m" << std::endl;
 MobilityHelper uemobility;
 uemobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
 Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
 uePositionAlloc->Add (Vector (ueDist, 0.0, 1.6));
 uemobility.SetPositionAllocator(uePositionAlloc);
 uemobility.Install (ueNodes.Get (0));
 BuildingsHelper::Install (ueNodes);

 // install ue device
 NetDeviceContainer ueNetDevices = helper->InstallUeDevice(ueNodes);
 std::cout<< "UE device installed" << std::endl;

 helper->AttachToClosestEnb (ueNetDevices, enbNetDevices);
 helper->EnableTraces();

 // activate a data radio bearer
 enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
 EpsBearer bearer (q);
 helper->ActivateDataRadioBearer (ueNetDevices, bearer);

 BuildingsHelper::MakeMobilityModelConsistent ();

 Simulator::Stop (Seconds (simTime));
 Simulator::Run ();
 Simulator::Destroy ();

 return 0;
}
