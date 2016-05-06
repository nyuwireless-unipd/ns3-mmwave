/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/* *
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
 * Author: Michele Polese <michele.polese@gmail.com>
 */

#include "ns3/mmwave-helper.h"
#include "ns3/epc-helper.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/internet-module.h"
#include "ns3/mobility-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/config-store.h"
#include "ns3/mmwave-point-to-point-epc-helper.h"
//#include "ns3/gtk-config-store.h"
#include <ns3/buildings-helper.h>
#include <ns3/buildings-module.h>

using namespace ns3;

/**
 * Sample simulation script for MC device. It instantiates a LTE and a MmWave eNodeB,
 * attaches one MC UE to both and starts a flow for the UE to  and from a remote host.
 */

NS_LOG_COMPONENT_DEFINE ("McFirstExample");
void 
PrintGnuplottableBuildingListToFile (std::string filename)
{
  std::ofstream outFile;
  outFile.open (filename.c_str (), std::ios_base::out | std::ios_base::trunc);
  if (!outFile.is_open ())
    {
      NS_LOG_ERROR ("Can't open file " << filename);
      return;
    }
  uint32_t index = 0;
  for (BuildingList::Iterator it = BuildingList::Begin (); it != BuildingList::End (); ++it)
    {
      ++index;
      Box box = (*it)->GetBoundaries ();
      outFile << "set object " << index
              << " rect from " << box.xMin  << "," << box.yMin
              << " to "   << box.xMax  << "," << box.yMax
              << " front fs empty "
              << std::endl;
    }
}

void 
PrintGnuplottableUeListToFile (std::string filename)
{
  std::ofstream outFile;
  outFile.open (filename.c_str (), std::ios_base::out | std::ios_base::trunc);
  if (!outFile.is_open ())
    {
      NS_LOG_ERROR ("Can't open file " << filename);
      return;
    }
  for (NodeList::Iterator it = NodeList::Begin (); it != NodeList::End (); ++it)
    {
      Ptr<Node> node = *it;
      int nDevs = node->GetNDevices ();
      for (int j = 0; j < nDevs; j++)
        {
          Ptr<LteUeNetDevice> uedev = node->GetDevice (j)->GetObject <LteUeNetDevice> ();
          Ptr<MmWaveUeNetDevice> mmuedev = node->GetDevice (j)->GetObject <MmWaveUeNetDevice> ();
          Ptr<McUeNetDevice> mcuedev = node->GetDevice (j)->GetObject <McUeNetDevice> ();
          if (uedev)
            {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << uedev->GetImsi ()
                      << "\" at "<< pos.x << "," << pos.y << " left font \"Helvetica,8\" textcolor rgb \"black\" front point pt 1 ps 0.3 lc rgb \"black\" offset 0,0"
                      << std::endl;
            }
          else if (mmuedev)
           {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << mmuedev->GetImsi ()
                      << "\" at "<< pos.x << "," << pos.y << " left font \"Helvetica,8\" textcolor rgb \"black\" front point pt 1 ps 0.3 lc rgb \"black\" offset 0,0"
                      << std::endl;
            }
          else if (mcuedev)
           {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << mcuedev->GetImsi ()
                      << "\" at "<< pos.x << "," << pos.y << " left font \"Helvetica,8\" textcolor rgb \"black\" front point pt 1 ps 0.3 lc rgb \"black\" offset 0,0"
                      << std::endl;
            } 
        }
    }
}

void 
PrintGnuplottableEnbListToFile (std::string filename)
{
  std::ofstream outFile;
  outFile.open (filename.c_str (), std::ios_base::out | std::ios_base::trunc);
  if (!outFile.is_open ())
    {
      NS_LOG_ERROR ("Can't open file " << filename);
      return;
    }
  for (NodeList::Iterator it = NodeList::Begin (); it != NodeList::End (); ++it)
    {
      Ptr<Node> node = *it;
      int nDevs = node->GetNDevices ();
      for (int j = 0; j < nDevs; j++)
        {
          Ptr<LteEnbNetDevice> enbdev = node->GetDevice (j)->GetObject <LteEnbNetDevice> ();
          Ptr<MmWaveEnbNetDevice> mmdev = node->GetDevice (j)->GetObject <MmWaveEnbNetDevice> ();
          if (enbdev)
            {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << enbdev->GetCellId ()
                      << "\" at "<< pos.x << "," << pos.y
                      << " left font \"Helvetica,8\" textcolor rgb \"blue\" front  point pt 4 ps 0.3 lc rgb \"blue\" offset 0,0"
                      << std::endl;
            }
          else if (mmdev)
            {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << mmdev->GetCellId ()
                      << "\" at "<< pos.x << "," << pos.y
                      << " left font \"Helvetica,8\" textcolor rgb \"red\" front  point pt 4 ps 0.3 lc rgb \"red\" offset 0,0"
                      << std::endl;
            } 
        }
    }
}

void
ChangePosition(Ptr<Node> node, Vector vector)
{
  Ptr<MobilityModel> model = node->GetObject<MobilityModel> ();
  model->SetPosition(vector);
  NS_LOG_UNCOND("************************--------------------Change Position-------------------------------*****************");
}

void
ChangeSpeed(Ptr<Node> n, Vector speed)
{
  n->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (speed);
  NS_LOG_UNCOND("************************--------------------Change Speed-------------------------------*****************");
}

void
PrintPosition(Ptr<Node> node)
{
  Ptr<MobilityModel> model = node->GetObject<MobilityModel> ();
  NS_LOG_UNCOND("Position +****************************** " << model->GetPosition() << " at time " << Simulator::Now().GetSeconds());
}

static ns3::GlobalValue g_mmw1DistFromMainStreet("mmw1Dist", "Distance from the main street of the first MmWaveEnb",
    ns3::UintegerValue(50), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_mmw2DistFromMainStreet("mmw2Dist", "Distance from the main street of the second MmWaveEnb",
    ns3::UintegerValue(50), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_mmWaveDistance("mmWaveDist", "Distance between MmWave eNB 1 and 2",
    ns3::UintegerValue(400), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_numBuildingsBetweenMmWaveEnb("numBlocks", "Number of buildings between MmWave eNB 1 and 2",
    ns3::UintegerValue(2), ns3::MakeUintegerChecker<uint32_t>());

int
main (int argc, char *argv[])
{
  LogComponentEnable ("LteUeRrc", LOG_LEVEL_INFO);
  LogComponentEnable ("LteEnbRrc", LOG_LEVEL_INFO);
  //LogComponentEnable("MmWavePointToPointEpcHelper",LOG_LEVEL_ALL);
  LogComponentEnable("EpcUeNas",LOG_LEVEL_INFO);
  //LogComponentEnable ("MmWaveSpectrumPhy", LOG_LEVEL_LOGIC);
  //LogComponentEnable ("MmWaveUeMac", LOG_LEVEL_INFO);
  //LogComponentEnable ("MmWaveEnbPhy", LOG_LEVEL_INFO);
  //LogComponentEnable ("MmWaveEnbMac", LOG_LEVEL_INFO);
  //LogComponentEnable ("UdpClient", LOG_LEVEL_INFO);
  //LogComponentEnable ("PacketSink", LOG_LEVEL_INFO);
  //LogComponentEnable("PropagationLossModel",LOG_LEVEL_ALL);
  //LogComponentEnable("LteUePhy", LOG_LEVEL_INFO);
  //LogComponentEnable ("mmWavePhyRxTrace", LOG_LEVEL_ALL);
  //LogComponentEnable ("MmWaveRrMacScheduler", LOG_LEVEL_ALL);
  LogComponentEnable("McUeNetDevice", LOG_LEVEL_INFO);
  LogComponentEnable("EpcSgwPgwApplication", LOG_LEVEL_INFO);
  //LogComponentEnable("MmWaveEnbMac", LOG_LEVEL_INFO);
  //LogComponentEnable("LteEnbMac", LOG_LEVEL_INFO);
  //LogComponentEnable("MmWavePointToPointEpcHelper", LOG_LEVEL_INFO);
  //LogComponentEnable("MmWaveHelper", LOG_LEVEL_LOGIC);
  //LogComponentEnable("EpcX2", LOG_LEVEL_ALL);
  //LogComponentEnable("EpcX2Header", LOG_LEVEL_ALL);
  LogComponentEnable("McEnbPdcp", LOG_LEVEL_INFO);
  LogComponentEnable("McUePdcp", LOG_LEVEL_INFO);
  LogComponentEnable("LteRlcUm", LOG_LEVEL_INFO);
  LogComponentEnable("LteRlcUmLowLat", LOG_LEVEL_INFO);
  //LogComponentEnable("AntennaArrayModel", LOG_LEVEL_ALL);

  // rng things
  RngSeedManager::SetSeed (2);
  RngSeedManager::SetRun (90);  


  uint16_t numberOfNodes = 1;
  double simTime = 60.0;
  double interPacketInterval = 1;  // 500 microseconds
  bool harqEnabled = true;
  bool rlcAmEnabled = false;
  bool fixedTti = false;
  unsigned symPerSf = 24;
  double sfPeriod = 100.0;

  // Command line arguments
  CommandLine cmd;
  cmd.AddValue("numberOfNodes", "Number of eNodeBs + UE pairs", numberOfNodes);
  cmd.AddValue("simTime", "Total duration of the simulation [s])", simTime);
  cmd.AddValue("interPacketInterval", "Inter packet interval [ms])", interPacketInterval);
  cmd.Parse(argc, argv);

  UintegerValue uintegerValue;
  GlobalValue::GetValueByName("numBlocks", uintegerValue);
  uint32_t numBlocks = uintegerValue.Get();
  GlobalValue::GetValueByName("mmw1Dist", uintegerValue);
  uint32_t mmw1Dist = uintegerValue.Get();
  GlobalValue::GetValueByName("mmw2Dist", uintegerValue);
  uint32_t mmw2Dist = uintegerValue.Get();
  GlobalValue::GetValueByName("mmWaveDist", uintegerValue);
  uint32_t mmWaveDist = uintegerValue.Get();
  uint32_t mmWaveZ = 10;
  uint32_t streetWidth = 15;
  uint32_t minimumBuildingWidth = 10;
  uint32_t buildingZ = 15;
  

  Config::SetDefault ("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue(rlcAmEnabled));
  Config::SetDefault ("ns3::MmWaveHelper::HarqEnabled", BooleanValue(harqEnabled));
  Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(harqEnabled));
  Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::HarqEnabled", BooleanValue(harqEnabled));
  Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::FixedTti", BooleanValue(fixedTti));
  Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::SymPerSlot", UintegerValue(6));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::ResourceBlockNum", UintegerValue(1));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(72));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SymbolsPerSubframe", UintegerValue(symPerSf));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::SubframePeriod", DoubleValue(sfPeriod));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::TbDecodeLatency", UintegerValue(200.0));
  Config::SetDefault ("ns3::MmWaveBeamforming::LongTermUpdatePeriod", TimeValue (MilliSeconds (100000.0)));
  Config::SetDefault ("ns3::LteEnbRrc::SystemInformationPeriodicity", TimeValue (MilliSeconds (5.0)));
  //Config::SetDefault ("ns3::MmWavePropagationLossModel::ChannelStates", StringValue ("n"));
  Config::SetDefault ("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MicroSeconds(100.0)));
  Config::SetDefault ("ns3::LteRlcUmLowLat::ReportBufferStatusTimer", TimeValue(MicroSeconds(100.0)));
  Config::SetDefault ("ns3::LteEnbRrc::SrsPeriodicity", UintegerValue (320));
  Config::SetDefault ("ns3::LteEnbRrc::FirstSibTime", UintegerValue (2));
  Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkDelay", TimeValue (MilliSeconds(0.1)));
  //Config::SetDefault ("ns3::MmWaveHelper::ChannelModel", StringValue("ns3::MmWaveChannelMatrix"));

  Ptr<MmWaveHelper> mmwaveHelper = CreateObject<MmWaveHelper> ();
  mmwaveHelper->SetSchedulerType ("ns3::MmWaveFlexTtiMaxWeightMacScheduler");
  Ptr<MmWavePointToPointEpcHelper> epcHelper = CreateObject<MmWavePointToPointEpcHelper> ();
  mmwaveHelper->SetEpcHelper (epcHelper);
  mmwaveHelper->SetHarqEnabled (harqEnabled);
  mmwaveHelper->SetAttribute ("PathlossModel", StringValue ("ns3::BuildingsObstaclePropagationLossModel"));

  ConfigStore inputConfig;
  inputConfig.ConfigureDefaults();

  // parse again so you can override default values from the command line
  cmd.Parse(argc, argv);

   // Get SGW/PGW and create a single RemoteHost 
  Ptr<Node> pgw = epcHelper->GetPgwNode ();
  NodeContainer remoteHostContainer;
  remoteHostContainer.Create (1);
  Ptr<Node> remoteHost = remoteHostContainer.Get (0);
  InternetStackHelper internet;
  internet.Install (remoteHostContainer);

  // Create the Internet by connecting remoteHost to pgw. Setup routing too
  PointToPointHelper p2ph;
  p2ph.SetDeviceAttribute ("DataRate", DataRateValue (DataRate ("100Gb/s")));
  p2ph.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  p2ph.SetChannelAttribute ("Delay", TimeValue (Seconds (0.010)));
  NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);
  Ipv4AddressHelper ipv4h;
  ipv4h.SetBase ("1.0.0.0", "255.0.0.0");
  Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign (internetDevices);
  // interface 0 is localhost, 1 is the p2p device
  Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress (1);
  Ipv4StaticRoutingHelper ipv4RoutingHelper;
  Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
  remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.0.0.0"), 1);

  // create LTE, mmWave eNB nodes and UE node
  NodeContainer ueNodes;
  NodeContainer mmWaveEnbNodes;
  NodeContainer lteEnbNodes;
  NodeContainer allEnbNodes;
  mmWaveEnbNodes.Create(2);
  lteEnbNodes.Create(1);
  ueNodes.Create(1);
  allEnbNodes.Add(lteEnbNodes);
  allEnbNodes.Add(mmWaveEnbNodes);

  // Positions
  Vector mmw1Position = Vector(5.0, mmw1Dist, mmWaveZ);
  Vector mmw2Position = Vector(5.0 + mmWaveDist, mmw2Dist, mmWaveZ);
  double blockSize = (double)mmWaveDist/numBlocks;
  uint32_t roundedBlockSize = std::floor(blockSize);
  NS_ASSERT_MSG(roundedBlockSize > streetWidth + minimumBuildingWidth, "Too many blocks");
  uint32_t buildingFirstX = streetWidth;
  uint32_t buildingWidth = roundedBlockSize - streetWidth;

  std::vector<Ptr<Building> > buildingVector;
  // create first building (negative coordinates)
  Ptr< Building > firstBuilding = Create<Building> ();
  firstBuilding->SetBoundaries(Box(-100, 0, 
                              0, mmw1Dist + streetWidth, 
                              0, buildingZ));
  buildingVector.push_back(firstBuilding);
  for(uint32_t buildingIndex = 0; buildingIndex < numBlocks; buildingIndex++)
  {
    Ptr < Building > building;
      building = Create<Building> ();
      building->SetBoundaries (Box (buildingFirstX, buildingFirstX + buildingWidth,
                                    0, mmw1Dist + streetWidth,
                                    0.0, buildingZ));
      buildingVector.push_back(building);
      buildingFirstX += buildingWidth + streetWidth;
  }
  // create last building
  Ptr< Building > lastBuilding = Create<Building> ();
  lastBuilding->SetBoundaries(Box(mmWaveDist + streetWidth, mmWaveDist + streetWidth + 20, 
                              0, mmw2Dist + streetWidth, 
                              0, buildingZ));
  buildingVector.push_back(lastBuilding);

  // Install Mobility Model
  Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector ((double)mmWaveDist/2 + streetWidth, mmw1Dist + 2*streetWidth, mmWaveZ));
  enbPositionAlloc->Add (mmw1Position);
  enbPositionAlloc->Add (mmw2Position);
  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator(enbPositionAlloc);
  enbmobility.Install (allEnbNodes);
  BuildingsHelper::Install (allEnbNodes);

  MobilityHelper uemobility;
  Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
  uePositionAlloc->Add (Vector (0, -5, 0));
  uemobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
  uemobility.SetPositionAllocator(uePositionAlloc);
  uemobility.Install (ueNodes);
  BuildingsHelper::Install (ueNodes);

  ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (0, -5, 0));
  ueNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (0, 0, 0));

  // Install mmWave, lte, mc Devices to the nodes
  NetDeviceContainer lteEnbDevs = mmwaveHelper->InstallLteEnbDevice (lteEnbNodes);
  NetDeviceContainer mmWaveEnbDevs = mmwaveHelper->InstallEnbDevice (mmWaveEnbNodes);
  NetDeviceContainer mcUeDevs = mmwaveHelper->InstallMcUeDevice (ueNodes);

  // Install the IP stack on the UEs
  internet.Install (ueNodes);
  Ipv4InterfaceContainer ueIpIface;
  ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (mcUeDevs));
  // Assign IP address to UEs, and install applications
  for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
  {
    Ptr<Node> ueNode = ueNodes.Get (u);
    // Set the default gateway for the UE
    Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (ueNode->GetObject<Ipv4> ());
    ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);
  }

  // Add X2 interfaces
  mmwaveHelper->AddX2Interface (lteEnbNodes, mmWaveEnbNodes);

  // Manual attachment
  mmwaveHelper->AttachToClosestEnb (mcUeDevs, mmWaveEnbDevs, lteEnbDevs);

  // Install and start applications on UEs and remote host
  uint16_t dlPort = 1234;
  uint16_t ulPort = 2000;
  ApplicationContainer clientApps;
  ApplicationContainer serverApps;
  bool dl = 1;
  bool ul = 1;
  for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
  {
      if(dl)
      {
        PacketSinkHelper dlPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), dlPort));
        serverApps.Add (dlPacketSinkHelper.Install (ueNodes.Get(u)));
        UdpClientHelper dlClient (ueIpIface.GetAddress (u), dlPort);
        dlClient.SetAttribute ("Interval", TimeValue (MilliSeconds(interPacketInterval)));
        dlClient.SetAttribute ("MaxPackets", UintegerValue(1000000));
        clientApps.Add (dlClient.Install (remoteHost));

      }
      if(ul)
      {
        ++ulPort;
        PacketSinkHelper ulPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
        serverApps.Add (ulPacketSinkHelper.Install (remoteHost));
        UdpClientHelper ulClient (remoteHostAddr, ulPort);
        ulClient.SetAttribute ("Interval", TimeValue (MilliSeconds(interPacketInterval)));
        ulClient.SetAttribute ("MaxPackets", UintegerValue(1000000));
        clientApps.Add (ulClient.Install (ueNodes.Get(u)));
      }
  }

  // Start applications
  serverApps.Start (Seconds (0.7));
  clientApps.Start (Seconds (0.7));


  Simulator::Schedule(Seconds(1.0), &ChangeSpeed, ueNodes.Get(0), Vector(5, 0, 0));
  double numPrints = 100;
  for(int i = 0; i < numPrints; i++)
  {
   Simulator::Schedule(Seconds(i*simTime/numPrints), &PrintPosition, ueNodes.Get(0)); 
  }

  // Uncomment to enable PCAP tracing
  // p2ph.EnablePcapAll("mmwave-epc-simple");
  BuildingsHelper::MakeMobilityModelConsistent ();

  mmwaveHelper->EnableTraces ();

  bool print = false;
  if(print)
  {
    PrintGnuplottableBuildingListToFile("buildings.txt");
    PrintGnuplottableEnbListToFile("enbs.txt");
    PrintGnuplottableUeListToFile("ues.txt");
  }
  else
  {
    Simulator::Stop(Seconds(simTime));
    Simulator::Run();    
  }
  
  Simulator::Destroy();
  return 0;
}

