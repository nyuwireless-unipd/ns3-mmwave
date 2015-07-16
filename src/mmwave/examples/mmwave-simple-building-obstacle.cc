/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ns3/core-module.h"
#include "ns3/mobility-module.h"
#include "ns3/config-store.h"
#include "ns3/mmwave-helper.h"
#include <ns3/buildings-helper.h>
#include "ns3/log.h"
#include <ns3/buildings-module.h>


using namespace ns3;

int 
main (int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse (argc, argv);

  /* Information regarding the traces generated:
   *
   * 1. UE_1_SINR.txt : Gives the SINR for each sub-band
   * 	Subframe no.  | Slot No. | Sub-band  | SINR (db)
   *
   * 2. UE_1_Tb_size.txt : Allocated transport block size
   * 	Time (micro-sec)  |  Tb-size in bytes
   * */

  Ptr<MmWaveHelper> ptr_mmWave = CreateObject<MmWaveHelper> ();
  ptr_mmWave->SetAttribute ("PathlossModel", StringValue ("ns3::BuildingsObstaclePropagationLossModel"));
  ptr_mmWave->Initialize();

  NodeContainer enbNodes;
  NodeContainer ueNodes;
  enbNodes.Create (1);
  ueNodes.Create (1);

  Ptr < Building > building;
  building = Create<Building> ();
  building->SetBoundaries (Box (20.0, 40.0,
                                0.0, 20.0,
                                0.0, 20.0));
  building->SetBuildingType (Building::Residential);
  building->SetExtWallsType (Building::ConcreteWithWindows);
  building->SetNFloors (1);
  building->SetNRoomsX (1);
  building->SetNRoomsY (1);

  Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector (0.0, 0.0, 0.0));
  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator(enbPositionAlloc);
  enbmobility.Install (enbNodes);
  BuildingsHelper::Install (enbNodes);


  MobilityHelper uemobility;
  uemobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
  uemobility.Install (ueNodes);
  ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (60, -20, 0));
  ueNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (0, 100, 0));
  /*
  MobilityHelper uemobility;
  Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
  uePositionAlloc->Add (Vector (80.0, -80.0, 0.0));
  uemobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  uemobility.SetPositionAllocator(uePositionAlloc);
  uemobility.Install (ueNodes);
  */
  BuildingsHelper::Install (ueNodes);

  NetDeviceContainer enbNetDev = ptr_mmWave->InstallEnbDevice (enbNodes);
  NetDeviceContainer ueNetDev = ptr_mmWave->InstallUeDevice (ueNodes);


  ptr_mmWave->RegisterToClosestEnb (ueNetDev, enbNetDev);
  ptr_mmWave->EnableTraces();

  // Activate a data radio bearer
  enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
  EpsBearer bearer (q);
  ptr_mmWave->ActivateDataRadioBearer (ueNetDev, bearer);
  BuildingsHelper::MakeMobilityModelConsistent ();

  Simulator::Stop (Seconds (1));
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}


