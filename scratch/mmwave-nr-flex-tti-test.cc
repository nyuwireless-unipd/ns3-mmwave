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
*                         Sourjya Dutta <sdutta@nyu.edu>
*                         Russell Ford <russell.ford@nyu.edu>
*                         Menglei Zhang <menglei@nyu.edu>
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
#include <ns3/lte-mac-sap.h>
#include <ns3/mmwave-enb-mac.h>

using namespace ns3;
using namespace mmwave;

double distUpdateInterval = 100.0;  // in ms
double distInc = 0.5; // increment by 10 meters

void 
updateDistance (double dist, Ptr<Node> ue)
{
  std::cout << "************* distance changing to " << dist << " *************" << std::endl;
  Ptr<MobilityModel> mobModel = ue->GetObject<MobilityModel> ();
  mobModel->SetPosition (Vector (dist, 0.0, 0.0));
  Simulator::Schedule (MilliSeconds (distUpdateInterval), &updateDistance, dist + distInc, ue);
}

int
main (int argc, char *argv[])
{
  /* Information regarding the traces generated:
   *
   * 1. UE_1_SINR.txt : Gives the SINR for each sub-band
   *    Subframe no.  | Slot No. | Sub-band  | SINR (db)
   *
   * 2. UE_1_Tb_size.txt : Allocated transport block size
   *    Time (micro-sec)  |  Tb-size in bytes
   * */

  //LogComponentEnable ("MmWaveSpectrumPhy", LOG_LEVEL_DEBUG);
  //LogComponentEnable ("MmWaveBeamforming", LOG_LEVEL_DEBUG);
  //LogComponentEnable ("MmWaveUePhy", LOG_LEVEL_FUNCTION);
  //LogComponentEnable ("MmWaveEnbPhy", LOG_LEVEL_LOGIC);
  //LogComponentEnable ("MmWaveFlexTtiMacScheduler", LOG_LEVEL_FUNCTION);
  //LogComponentEnable ("MmWavePhyTrace", LOG_LEVEL_DEBUG);
  //LogComponentEnable ("LteRlcUm", LOG_LEVEL_LOGIC);
  //LogComponentEnable ("MmWaveUeMac", LOG_LEVEL_LOGIC);
  //LogComponentEnable ("MmWaveEnbMac", LOG_LEVEL_LOGIC);
  //LogComponentEnable ("UdpClient", LOG_LEVEL_INFO);
  //LogComponentEnable ("PacketSink", LOG_LEVEL_INFO);
  //LogComponentEnable("PropagationLossModel",LOG_LEVEL_ALL);
  LogComponentEnableAll (LOG_PREFIX_ALL);

  uint16_t numEnb = 1;
  uint16_t numUe = 1;
  double distMin = 15.0;        // eNB-UE distance in meters
  double distMax = 250.0;        // eNB-UE distance in meters
  double simTime = 20;         // Simulation time, in ms
  bool enableData = true;   // Do actually transmit some data
  bool dlOnly = true;   // Schedule only DL packets
  bool ulOnly = false;      // Schedule only UL packets
  bool harqEnabled = false;     // Enable HARQ
  int mcsDl = -1;
  std::string channelState = "n";
  bool smallScale = true;
  double speed = 1.0;


  // Command line arguments
  CommandLine cmd;
  cmd.AddValue ("numEnb", "Number of eNBs", numEnb);
  cmd.AddValue ("numUe", "Number of UEs per eNB", numUe);
  cmd.AddValue ("simTime", "Total duration of the simulation [ms])", simTime);
  cmd.AddValue ("harq", "Enable Hybrid ARQ", harqEnabled);
  cmd.AddValue ("mcsDl", "Fixed DL MCS", mcsDl);
  cmd.AddValue ("channelState", "Channel state 'l'=LOS, 'n'=NLOS, 'a'=all", channelState);
  cmd.AddValue ("distMin", "Initial distance", distMin);
  cmd.AddValue ("distMax", "Final distance", distMax);
  cmd.AddValue ("distInc", "Distance increment", distInc);
  cmd.AddValue ("distUpdateInterval", "Period after which distance is updated", distUpdateInterval);
  cmd.AddValue ("smallScale", "Enable small scale fading", smallScale);
  cmd.AddValue ("dlOnly", "Schedule only downlink traffic", dlOnly);
  cmd.AddValue ("ulOnly", "Schedule only uplink traffic", ulOnly);
  cmd.AddValue ("enableData", "Activate an EPS bearer", enableData);
  cmd.Parse (argc, argv);

  //simTime = ((distMax - distMin) / distInc) * (distUpdateInterval / 1000.0);

  if (mcsDl >= 0 && mcsDl < 29)
    {
      Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::FixedMcsDl", BooleanValue (true));
      Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::McsDefaultDl", UintegerValue (mcsDl));
    }

  // Set DL or UL only for testing purposes
  Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::DlSchedOnly", BooleanValue (dlOnly));
  Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::UlSchedOnly", BooleanValue (ulOnly));

  Config::SetDefault ("ns3::MmWaveBeamforming::LongTermUpdatePeriod", TimeValue (Seconds (2 * simTime)));
  Config::SetDefault ("ns3::LteEnbRrc::SystemInformationPeriodicity", TimeValue (MilliSeconds (1.0)));
  Config::SetDefault ("ns3::MmWaveAmc::Ber", DoubleValue (0.001));
  Config::SetDefault ("ns3::MmWavePropagationLossModel::ChannelStates", StringValue (channelState));
  Config::SetDefault ("ns3::MmWaveBeamforming::SmallScaleFading", BooleanValue (smallScale));
  Config::SetDefault ("ns3::MmWaveBeamforming::FixSpeed", BooleanValue (true));
  Config::SetDefault ("ns3::MmWaveBeamforming::UeSpeed", DoubleValue (speed));
  Config::SetDefault ("ns3::MmWaveHelper::UseIdealRrc", BooleanValue(true));

  // Set NR numerology
  uint8_t index = 2;
  uint8_t slotsPerSubframe = std::pow (2, index);
  double subCarriersPerRB = 12; // TS 38.211 Sec 4.4.4.1
  double subcarrierSpacing = 15 * std::pow (2, index) * 1000; // Subcarrier spacing, only 60KHz and 120KHz are supported in NR for FR2.
  Time subframePeriod = Time (MilliSeconds (1));

  Config::SetDefault ("ns3::MmWavePhyMacCommon::SymbolPerSlot", UintegerValue (14));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SlotsPerSubframe", UintegerValue (slotsPerSubframe));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SymbolsPerSubframe", UintegerValue (14*slotsPerSubframe));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SubframePeriod", TimeValue (subframePeriod));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SymbolPeriod", TimeValue (NanoSeconds (subframePeriod / 14 / slotsPerSubframe)));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::ChunkWidth", DoubleValue (subCarriersPerRB*subcarrierSpacing));

  Ptr<MmWaveHelper> mmwHelper = CreateObject<MmWaveHelper> ();

  mmwHelper->Initialize ();
  // mmwHelper->SetHarqEnabled (harqEnabled);


  NodeContainer enbNodes;
  NodeContainer ueNodes;
  enbNodes.Create (numEnb);
  ueNodes.Create (numUe);

  Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector (0.0, 0.0, 0.0));

  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator (enbPositionAlloc);
  enbmobility.Install (enbNodes);
  BuildingsHelper::Install (enbNodes);

  MobilityHelper uemobility;
  Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
  uePositionAlloc->Add (Vector (distMin, 0.0, 0.0));

  Simulator::Schedule (MilliSeconds (distUpdateInterval), &updateDistance, distMin + distInc, ueNodes.Get (0));

  uemobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  uemobility.SetPositionAllocator (uePositionAlloc);
  uemobility.Install (ueNodes);
  BuildingsHelper::Install (ueNodes);

  NetDeviceContainer enbNetDev = mmwHelper->InstallEnbDevice (enbNodes);
  NetDeviceContainer ueNetDev = mmwHelper->InstallUeDevice (ueNodes);

  mmwHelper->AttachToClosestEnb (ueNetDev, enbNetDev);

  if(enableData)
  {
      
      //Activate a data radio bearer
      enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
      EpsBearer bearer (q);
      mmwHelper->ActivateDataRadioBearer (ueNetDev, bearer);
  }

  mmwHelper->EnableTraces ();

  Simulator::Stop (MilliSeconds (simTime));
  NS_LOG_UNCOND ("Simulation running for " << simTime << " seconds");
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
