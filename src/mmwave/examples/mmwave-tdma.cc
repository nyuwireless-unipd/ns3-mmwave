/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

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

using namespace ns3;

int 
main (int argc, char *argv[])
{
//  LogComponentEnable ("MmWaveSpectrumPhy", LOG_LEVEL_INFO);
  //LogComponentEnable ("MmWaveUePhy", LOG_LEVEL_INFO);
  //LogComponentEnable ("MmWaveEnbPhy", LOG_LEVEL_INFO);
  //LogComponentEnable ("MmWavePhy", LOG_LEVEL_INFO);

//  LogComponentEnable ("MmWaveUeMac", LOG_LEVEL_INFO);
//  LogComponentEnable ("MmWaveEnbMac", LOG_LEVEL_INFO);
  LogComponentEnable ("MmWaveRrMacScheduler", LOG_LEVEL_INFO);
  LogComponentEnable ("MmWaveHarqPhy", LOG_LEVEL_DEBUG);


  //LogComponentEnable ("LteUeRrc", LOG_LEVEL_ALL);
  //LogComponentEnable ("LteEnbRrc", LOG_LEVEL_ALL);
  //LogComponentEnable("PropagationLossModel",LOG_LEVEL_ALL);
  //LogComponentEnable("mmWaveInterference",LOG_LEVEL_ALL);
  //LogComponentEnable("MmWaveBeamforming",LOG_LEVEL_ALL);
  //LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  //LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  /* Information regarding the traces generated:
   *
   * 1. UE_1_SINR.txt : Gives the SINR for each sub-band
   * 	Subframe no.  | Slot No. | Sub-band  | SINR (db)
   *
   * 2. UE_1_Tb_size.txt : Allocated transport block size
   * 	Time (micro-sec)  |  Tb-size in bytes
   * */


  uint16_t numEnb = 1;
  uint16_t numUe = 4;

  double simTime = 0.3;
  double interPacketInterval = 10;

  // Command line arguments
  CommandLine cmd;
  cmd.AddValue("numEnb", "Number of eNBs", numEnb);
  cmd.AddValue("numUe", "Number of UEs per eNB", numUe);
  cmd.AddValue("simTime", "Total duration of the simulation [s])", simTime);
  cmd.AddValue("interPacketInterval", "Inter packet interval [ms])", interPacketInterval);
  cmd.Parse(argc, argv);

  Config::SetDefault ("ns3::MmWaveRrMacScheduler::HarqEnabled", BooleanValue (false));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::ResourceBlockNum", UintegerValue (1));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue (72));

  Ptr<MmWaveHelper> ptr_mmWave = CreateObject<MmWaveHelper> ();

  ptr_mmWave->Initialize();

  /* A configuration example.
   * ptr_mmWave->GetPhyMacConfigurable ()->SetAttribute("SymbolPerSlot", UintegerValue(30)); */

  NodeContainer enbNodes;
  NodeContainer ueNodes;
  enbNodes.Create (numEnb);
  ueNodes.Create (numUe);

  Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector (0.0, 0.0, 0.0));

  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator(enbPositionAlloc);
  enbmobility.Install (enbNodes);
  BuildingsHelper::Install (enbNodes);

  MobilityHelper uemobility;
  Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
  uePositionAlloc->Add (Vector (80.0, 0.0, 0.0));

  uemobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  uemobility.SetPositionAllocator(uePositionAlloc);
  uemobility.Install (ueNodes);
  BuildingsHelper::Install (ueNodes);

  NetDeviceContainer enbNetDev = ptr_mmWave->InstallEnbDevice (enbNodes);
  NetDeviceContainer ueNetDev = ptr_mmWave->InstallUeDevice (ueNodes);


  ptr_mmWave->RegisterToClosestEnb (ueNetDev, enbNetDev);
  ptr_mmWave->EnableTraces();

  // Activate a data radio bearer
  enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
  EpsBearer bearer (q);
  ptr_mmWave->ActivateDataRadioBearer (ueNetDev, bearer);



  Simulator::Stop (Seconds (0.03));
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}


