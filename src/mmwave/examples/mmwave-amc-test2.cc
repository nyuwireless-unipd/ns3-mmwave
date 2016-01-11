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
#include "ns3/mmwave-propagation-loss-model.h"

using namespace ns3;

double updateInterval = 100.0;  // in ms
double increment = .1; // increment by x dB
double lossMin = 100.0;
double lossMax = 145.0;

void updateLoss (double loss, Ptr<MmWavePropagationLossModel> model)
{
//  std::cout << "************* distance changing to " << dist << " *************" << std::endl;
//  Ptr<MobilityModel> mobModel = ue->GetObject<MobilityModel> ();
//  mobModel->SetPosition (Vector (dist, 0.0, 0.0));
	model->SetLossFixedDb (loss);
  std::cout << "************* SINR changing to " << loss << " *************" << std::endl;
  if (loss >= lossMax)
  {
  	return;
  }
	Simulator::Schedule (MilliSeconds(updateInterval), &updateLoss, loss+increment, model);
}

int 
main (int argc, char *argv[])
{
  /* Information regarding the traces generated:
   *
   * 1. UE_1_SINR.txt : Gives the SINR for each sub-band
   * 	Subframe no.  | Slot No. | Sub-band  | SINR (db)
   *
   * 2. UE_1_Tb_size.txt : Allocated transport block size
   * 	Time (micro-sec)  |  Tb-size in bytes
   * */

	LogComponentEnable ("MmWaveSpectrumPhy", LOG_LEVEL_DEBUG);
//	LogComponentEnable ("MmWaveBeamforming", LOG_LEVEL_DEBUG);
//	LogComponentEnable ("MmWaveUePhy", LOG_LEVEL_DEBUG);
//	LogComponentEnable ("MmWaveEnbPhy", LOG_LEVEL_DEBUG);
//	LogComponentEnable ("MmWaveFlexTtiMacScheduler", LOG_LEVEL_DEBUG);
	LogComponentEnable ("MmWavePhyRxTrace", LOG_LEVEL_DEBUG);
	//LogComponentEnable ("LteRlcUm", LOG_LEVEL_LOGIC);
	//LogComponentEnable ("MmWaveUeMac", LOG_LEVEL_LOGIC);
	//LogComponentEnable ("UdpClient", LOG_LEVEL_INFO);
	//LogComponentEnable ("PacketSink", LOG_LEVEL_INFO);
	//LogComponentEnable("PropagationLossModel",LOG_LEVEL_ALL);

	uint16_t numEnb = 1;
	uint16_t numUe = 1;

	double simTime = 1.0;
	bool harqEnabled = true;
	int mcsDl = -1;
	std::string channelState = "n";
	bool smallScale = true;
	double speed = 0.5;
	double dist = 100.0;

	// Command line arguments
	CommandLine cmd;
	cmd.AddValue("numEnb", "Number of eNBs", numEnb);
	cmd.AddValue("numUe", "Number of UEs per eNB", numUe);
	cmd.AddValue("simTime", "Total duration of the simulation [s])", simTime);
	cmd.AddValue("harq", "Enable Hybrid ARQ", harqEnabled);
	cmd.AddValue("mcsDl", "Fixed DL MCS", mcsDl);
	cmd.AddValue("channelState", "Channel state 'l'=LOS, 'n'=NLOS, 'a'=all", channelState);
	cmd.AddValue("lossMin", "Initial distance", lossMin);
	cmd.AddValue("lossMax", "Final distance", lossMax);
	cmd.AddValue("increment", "Distance increment", increment);
	cmd.AddValue("updateInterval", "Period after which distance is updated", updateInterval);
	cmd.AddValue("smallScale", "Enable small scale fading", smallScale);
	cmd.Parse(argc, argv);

	simTime = ((lossMax - lossMin) / increment) * (updateInterval/1000.0);

	if (mcsDl >= 0 && mcsDl < 29)
	{
		Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::FixedMcsDl", BooleanValue(true));
		Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::McsDefaultDl", UintegerValue(mcsDl));
	}

	//Config::SetDefault ("ns3::MmWaveAmc::AmcModel", EnumValue (MmWaveAmc::PiroEW2010));
	Config::SetDefault ("ns3::MmWaveAmc::Ber", DoubleValue (0.01));
	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(harqEnabled));
	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::UlSchedOnly", BooleanValue(true));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::ResourceBlockNum", UintegerValue(1));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(72));
	Config::SetDefault ("ns3::MmWaveBeamforming::LongTermUpdatePeriod", TimeValue (Seconds (2*simTime)));
	Config::SetDefault ("ns3::LteEnbRrc::SystemInformationPeriodicity", TimeValue (MilliSeconds (1.0)));
	Config::SetDefault ("ns3::MmWaveBeamforming::SmallScaleFading", BooleanValue (smallScale));
	Config::SetDefault ("ns3::MmWaveBeamforming::FixSpeed", BooleanValue (true));
	Config::SetDefault ("ns3::MmWaveBeamforming::UeSpeed", DoubleValue (speed));
	//Config::SetDefault ("ns3::MmWavePropagationLossModel::ChannelStates", StringValue (channelState));
	Config::SetDefault ("ns3::MmWavePropagationLossModel::FixedLossTst", BooleanValue (true));
	Config::SetDefault ("ns3::MmWavePropagationLossModel::LossFixedDb", DoubleValue (100.0));

  Ptr<MmWaveHelper> mmwHelper = CreateObject<MmWaveHelper> ();

  mmwHelper->Initialize();
  mmwHelper->SetHarqEnabled (harqEnabled);
  Ptr<MmWavePropagationLossModel> lossModel = mmwHelper->GetPathLossModel ()->GetObject<MmWavePropagationLossModel> ();

  /* A configuration example.
   * mmwHelper->GetPhyMacConfigurable ()->SetAttribute("SymbolPerSlot", UintegerValue(30)); */

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
  uePositionAlloc->Add (Vector (dist, 0.0, 0.0));

  Simulator::Schedule (MilliSeconds(0), &updateLoss, lossMin, lossModel);

  uemobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  uemobility.SetPositionAllocator(uePositionAlloc);
  uemobility.Install (ueNodes);
  BuildingsHelper::Install (ueNodes);

  NetDeviceContainer enbNetDev = mmwHelper->InstallEnbDevice (enbNodes);
  NetDeviceContainer ueNetDev = mmwHelper->InstallUeDevice (ueNodes);

  mmwHelper->AttachToClosestEnb (ueNetDev, enbNetDev);
  mmwHelper->EnableTraces();

  // Activate a data radio bearer
  enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
  EpsBearer bearer (q);
  mmwHelper->ActivateDataRadioBearer (ueNetDev, bearer);

  Simulator::Stop (Seconds (simTime));
	NS_LOG_UNCOND ("Simulation running for " << simTime << " seconds");
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}


