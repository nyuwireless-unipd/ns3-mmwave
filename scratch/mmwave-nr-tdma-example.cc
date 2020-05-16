/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2020, University of Padova, Dep. of Information Engineering, SIGNET lab
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
 *   Author: Matteo Pagin <mattpagg@gmail.com>
 */

/*  
 *  This example shows how to setup a basic TDMA, mmWave cellular network.
 *  A single eNB is located at (0, 0, 10), while UEs are placed at a distance initialPos 
 *  along the x axis from the BSs, i.e., at (initialPos, 0, 1.5). Furthermore, UEs
 *  progressively move further away from the BS with a velocity ueSpeed, once again 
 *  along the x axis.
 *  If data transmission is enabled, a bearer is installed on the eNBs and the
 *  UEs, generating both UL and DL traffic.
 */

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/config-store.h"
#include "ns3/mmwave-helper.h"
#include <ns3/buildings-helper.h>
#include "ns3/log.h"

using namespace ns3;
using namespace mmwave;

int
main (int argc, char *argv[])
{
 /*
  * These allow the user to enable the desired logging outputs. 
  */

  //LogComponentEnable ("MmWaveSpectrumPhy", LOG_LEVEL_DEBUG);
  //LogComponentEnable ("MmWaveBeamforming", LOG_LEVEL_DEBUG);
  LogComponentEnable ("MmWaveUePhy", LOG_LEVEL_FUNCTION);
  LogComponentEnable ("MmWaveEnbPhy", LOG_LEVEL_FUNCTION);
  //LogComponentEnable ("MmWaveFlexTtiMacScheduler", LOG_LEVEL_FUNCTION);
  //LogComponentEnable ("MmWavePhyTrace", LOG_LEVEL_LOGIC);
  //LogComponentEnable ("LteRlcUm", LOG_LEVEL_LOGIC);
  //LogComponentEnable ("MmWaveUeMac", LOG_LEVEL_LOGIC);
  //LogComponentEnable ("MmWaveEnbMac", LOG_LEVEL_LOGIC);
  //LogComponentEnable ("UdpClient", LOG_LEVEL_INFO);
  //LogComponentEnable ("PacketSink", LOG_LEVEL_INFO);
  //LogComponentEnable("PropagationLossModel",LOG_LEVEL_ALL);
  //LogComponentEnableAll (LOG_PREFIX_ALL);

  uint8_t const numEnb = 1;    // The amoount of eNBs
  uint16_t numUe = 1;   // The amount of UEs
  uint8_t numIndex = 2;   // The NR numerology index. Either 2 or 3.
  uint16_t simTime = 1000;         // Simulation time [ms]
  bool enableData = false;   // Do actually transmit some data
  bool dlOnly = false;   // Schedule only DL packets
  bool ulOnly = false;      // Schedule only UL packets
  bool harqEnabled = false;     // Enable HARQ
  int mcsDl = -1;   // If between 0 and 28, fixes the DL MCS (respectively to the lowest and higher possible values)
  std::string channelState = "a";   // Channel state, The possible values are: 'a' = all, 'l' = LOS, 'n' = NLOS
  bool smallScale = true;
  double bw = 500e6;    // The overall system bandwidth
  double initalPos = 100;   // The UEs intended initial position along the x axis.
  double ueSpeed = 5;   // The intended UEs speed [m/s]
  

 /*
  * This enables to parse command line arguments and assign the specified values at runtime,
  * therefore avoiding the need of re-compiling the simulation script for a simple parameter change.
  */

  CommandLine cmd;
  cmd.AddValue ("numUe", "Number of UEs per eNB", numUe);
  cmd.AddValue ("simTime", "Total duration of the simulation [ms])", simTime);
  cmd.AddValue ("harq", "Enable Hybrid ARQ", harqEnabled);
  cmd.AddValue ("mcsDl", "Fixed DL MCS", mcsDl);
  cmd.AddValue ("channelState", "Channel state 'l'=LOS, 'n'=NLOS, 'a'=all", channelState);
  cmd.AddValue ("smallScale", "Enable small scale fading", smallScale);
  cmd.AddValue ("dlOnly", "Schedule only downlink traffic", dlOnly);
  cmd.AddValue ("ulOnly", "Schedule only uplink traffic", ulOnly);
  cmd.AddValue ("enableData", "Activate an EPS bearer", enableData);
  cmd.AddValue ("numIndex", "The NR numerology index", numIndex);
  cmd.AddValue ("bw", "Total system bandwidth", bw);
  cmd.AddValue ("initialPos", "Initial position of the UEs along the x axis [m]", initalPos);
  cmd.AddValue ("ueSpeed", "UEs speed along the x axis [m/s]", ueSpeed);
  cmd.Parse (argc, argv);

 /*
  * First of all, the intended settings must be set using the corresponding attributes.
  * In such a way, all future objects of a given class will be initialized with the values we are hereby specifying.
  */

  // Set the fixed DL MCS, if specified
  if (mcsDl >= 0 && mcsDl < 29)
    {
      Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::FixedMcsDl", BooleanValue (true));
      Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::McsDefaultDl", UintegerValue (mcsDl));
    }

  // Set DL or UL only (mainly for testing purposes)
  Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::DlSchedOnly", BooleanValue (dlOnly));
  Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::UlSchedOnly", BooleanValue (ulOnly));

  Config::SetDefault ("ns3::MmWaveBeamforming::LongTermUpdatePeriod", TimeValue (Seconds (2 * simTime)));
  Config::SetDefault ("ns3::LteEnbRrc::SystemInformationPeriodicity", TimeValue (MilliSeconds (1.0)));
  Config::SetDefault ("ns3::MmWaveAmc::Ber", DoubleValue (0.001));
  Config::SetDefault ("ns3::MmWavePropagationLossModel::ChannelStates", StringValue (channelState));
  Config::SetDefault ("ns3::MmWaveBeamforming::SmallScaleFading", BooleanValue (smallScale));
  Config::SetDefault ("ns3::MmWaveBeamforming::FixSpeed", BooleanValue (true));
  Config::SetDefault ("ns3::MmWaveBeamforming::UeSpeed", DoubleValue (ueSpeed));
  Config::SetDefault ("ns3::MmWaveHelper::UseIdealRrc", BooleanValue(true));

  // Set NR numerology. TODO: make more user friendly.
  uint8_t slotsPerSubframe = std::pow (2, numIndex);
  double subCarriersPerRB = 12; // TS 38.211 Sec 4.4.4.1
  double subcarrierSpacing = 15 * std::pow (2, numIndex) * 1000; // Subcarrier spacing, only 60KHz and 120KHz are supported in NR for FR2.
  Time subframePeriod = Time (MilliSeconds (1));

  Config::SetDefault ("ns3::MmWavePhyMacCommon::SymbolPerSlot", UintegerValue (14));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SlotsPerSubframe", UintegerValue (slotsPerSubframe));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SymbolsPerSubframe", UintegerValue (14*slotsPerSubframe));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SubframePeriod", TimeValue (subframePeriod));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SymbolPeriod", TimeValue (NanoSeconds (subframePeriod / 14 / slotsPerSubframe)));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::ChunkWidth", DoubleValue (subCarriersPerRB*subcarrierSpacing));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue (bw/(subCarriersPerRB*subcarrierSpacing*1)));

 /*
  * Now that the attributes are set, we can proceed with the creation of the needed entities.
  * In order to facilitate this procedure, we can use the MmWaveHelper class, that abstracts
  * most of the tedious operations that would otherwise be needed in order to setup a simulation.
  */

  Ptr<MmWaveHelper> mmwHelper = CreateObject<MmWaveHelper> ();

  mmwHelper->Initialize ();
  mmwHelper->SetHarqEnabled (harqEnabled);

  NodeContainer enbNode;
  NodeContainer ueNodes;
  enbNode.Create (numEnb);
  ueNodes.Create (numUe);

  Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector (0, 0, 10));

  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator (enbPositionAlloc);
  enbmobility.Install (enbNode);
  BuildingsHelper::Install (enbNode);

  MobilityHelper uemobility;
  Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
  uePositionAlloc->Add (Vector (initalPos, 0, 1.5));

  // Let UEs move with a constant velocity along the x axis
  uemobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
  uemobility.SetPositionAllocator (uePositionAlloc);
  uemobility.Install (ueNodes);
  // Assign the UE speeds
  for (uint16_t i = 0; i < numUe; i++)
    {
      ueNodes.Get (i)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (ueSpeed, 0, 0));
    }
  BuildingsHelper::Install (ueNodes);

  NetDeviceContainer enbNetDev = mmwHelper->InstallEnbDevice (enbNode);
  NetDeviceContainer ueNetDev = mmwHelper->InstallUeDevice (ueNodes);

  mmwHelper->AttachToClosestEnb (ueNetDev, enbNetDev);

  if(enableData)
  {
      // Activate a data radio bearer
      enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
      EpsBearer bearer (q);
      mmwHelper->ActivateDataRadioBearer (ueNetDev, bearer);
  }

  // Enable all the mmWave output traces
  mmwHelper->EnableTraces ();

  Simulator::Stop (MilliSeconds (simTime));
  NS_LOG_UNCOND ("Simulation running for " << simTime << " milliseconds");
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
