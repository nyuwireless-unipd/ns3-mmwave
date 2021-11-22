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

#include <sys/stat.h>
#include <sys/types.h>
#include "ns3/mmwave-helper.h"
#include "ns3/epc-helper.h"
#include "ns3/node-list.h"
#include "ns3/internet-module.h"
#include "ns3/mobility-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/config-store-module.h"
#include "ns3/mmwave-point-to-point-epc-helper.h"
#include "ns3/mmwave-radio-energy-model-helper.h"
#include "ns3/mmwave-radio-energy-model-enb-helper.h"
#include "ns3/basic-energy-source-helper.h"
#include "ns3/buildings-helper.h"
#include "ns3/buildings-module.h"
#include "ns3/global-value.h"
#include "ns3/command-line.h"
#include <ns3/random-variable-stream.h>
#include <ns3/lte-ue-net-device.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <list>
#include <random>
#include <chrono>
#include <cmath>
#include <fstream>

using namespace ns3;
using namespace mmwave;
using namespace std;

map<uint32_t, uint64_t> uenodeid_imsi;
map<uint32_t, uint16_t> ue_cellid;

map<uint16_t, Ptr<Node>> cellid_node;

map<uint32_t, uint16_t> ue_cellid_usinghandover;
map<uint32_t, double> ue_energy_map;
map<uint16_t, double> enb_energy_map;
map<uint32_t, pair<uint16_t, double>> ue_distancefromgnodeb;
map<uint32_t, RxPacketTraceParams> ue_rxpackettrace;
map<uint32_t, double> ue_speed;

map<uint64_t, uint32_t> ueimsi_nodeid;
map<uint16_t, set<uint64_t>> imsi_list;

map<int, uint32_t> seq_nodeid;

/**
 * Sample simulation script for MC device. It instantiates a LTE and two MmWave eNodeB,
 * attaches one MC UE to both and starts a flow for the UE to and from a remote host.
 */

NS_LOG_COMPONENT_DEFINE ("Final");

std::string outputDir = "";
std::string tracefilename = "/trace_Data.csv";
class MyAppTag : public Tag
{
public:
  MyAppTag ()
  {
  }

  MyAppTag (Time sendTs) : m_sendTs (sendTs)
  {
  }

  static TypeId
  GetTypeId (void)
  {
    static TypeId tid = TypeId ("ns3::MyAppTag").SetParent<Tag> ().AddConstructor<MyAppTag> ();
    return tid;
  }

  virtual TypeId
  GetInstanceTypeId (void) const
  {
    return GetTypeId ();
  }

  virtual void
  Serialize (TagBuffer i) const
  {
    i.WriteU64 (m_sendTs.GetNanoSeconds ());
  }

  virtual void
  Deserialize (TagBuffer i)
  {
    m_sendTs = NanoSeconds (i.ReadU64 ());
  }

  virtual uint32_t
  GetSerializedSize () const
  {
    return sizeof (m_sendTs);
  }

  virtual void
  Print (std::ostream &os) const
  {
    std::cout << m_sendTs;
  }

  Time m_sendTs;
};

class MyApp : public Application
{
public:
  MyApp ();
  virtual ~MyApp ();
  void ChangeDataRate (DataRate rate);
  void Setup (Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets,
              DataRate dataRate);

private:
  virtual void StartApplication (void);
  virtual void StopApplication (void);

  void ScheduleTx (void);
  void SendPacket (void);

  Ptr<Socket> m_socket;
  Address m_peer;
  uint32_t m_packetSize;
  uint32_t m_nPackets;
  DataRate m_dataRate;
  EventId m_sendEvent;
  bool m_running;
  uint32_t m_packetsSent;
};

MyApp::MyApp ()
    : m_socket (0),
      m_peer (),
      m_packetSize (0),
      m_nPackets (0),
      m_dataRate (0),
      m_sendEvent (),
      m_running (false),
      m_packetsSent (0)
{
}

MyApp::~MyApp ()
{
  m_socket = 0;
}

void
MyApp::Setup (Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets,
              DataRate dataRate)
{
  m_socket = socket;
  m_peer = address;
  m_packetSize = packetSize;
  m_nPackets = nPackets;
  m_dataRate = dataRate;
}

void
MyApp::ChangeDataRate (DataRate rate)
{
  m_dataRate = rate;
}

void
MyApp::StartApplication (void)
{
  m_running = true;
  m_packetsSent = 0;
  m_socket->Bind ();
  m_socket->Connect (m_peer);
  SendPacket ();
}

void
MyApp::StopApplication (void)
{
  m_running = false;

  if (m_sendEvent.IsRunning ())
    {
      Simulator::Cancel (m_sendEvent);
    }

  if (m_socket)
    {
      m_socket->Close ();
    }
}

void
MyApp::SendPacket (void)
{
  Ptr<Packet> packet = Create<Packet> (m_packetSize);
  MyAppTag tag (Simulator::Now ());

  m_socket->Send (packet);
  if (++m_packetsSent < m_nPackets)
    {
      ScheduleTx ();
    }
}

void
MyApp::ScheduleTx (void)
{
  if (m_running)
    {
      Time tNext (Seconds (m_packetSize * 8 / static_cast<double> (m_dataRate.GetBitRate ())));
      m_sendEvent = Simulator::Schedule (tNext, &MyApp::SendPacket, this);
    }
}

static void
CwndChange (Ptr<OutputStreamWrapper> stream, uint32_t oldCwnd, uint32_t newCwnd)
{
  *stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldCwnd << "\t" << newCwnd
                        << std::endl;
}

static void
RttChange (Ptr<OutputStreamWrapper> stream, Time oldRtt, Time newRtt)
{
  *stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldRtt.GetSeconds () << "\t"
                        << newRtt.GetSeconds () << std::endl;
}

static void
Rx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet, const Address &from)
{
  *stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << packet->GetSize ()
                        << std::endl;
}

void
trackCellId (uint32_t node_id, uint16_t old_cellid, uint16_t new_cellid)
{
  ue_cellid[node_id] = new_cellid;
  std::cout << "nodeid " << node_id << " old cellid : " << old_cellid
            << " new cellid : " << new_cellid << "\n";
}

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
      outFile << "set object " << index << " rect from " << box.xMin << "," << box.yMin << " to "
              << box.xMax << "," << box.yMax << " front fs empty " << std::endl;
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
          Ptr<LteUeNetDevice> uedev = node->GetDevice (j)->GetObject<LteUeNetDevice> ();
          Ptr<MmWaveUeNetDevice> mmuedev = node->GetDevice (j)->GetObject<MmWaveUeNetDevice> ();
          Ptr<McUeNetDevice> mcuedev = node->GetDevice (j)->GetObject<McUeNetDevice> ();
          if (uedev)
            {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << uedev->GetImsi () << "\" at " << pos.x << "," << pos.y
                      << " left font \"Helvetica,8\" textcolor rgb \"black\" front point pt 1 ps "
                         "0.3 lc rgb \"black\" offset 0,0"
                      << std::endl;
            }
          else if (mmuedev)
            {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << mmuedev->GetImsi () << "\" at " << pos.x << "," << pos.y
                      << " left font \"Helvetica,8\" textcolor rgb \"black\" front point pt 1 ps "
                         "0.3 lc rgb \"black\" offset 0,0"
                      << std::endl;
            }
          else if (mcuedev)
            {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << mcuedev->GetImsi () << "\" at " << pos.x << "," << pos.y
                      << " left font \"Helvetica,8\" textcolor rgb \"black\" front point pt 1 ps "
                         "0.3 lc rgb \"black\" offset 0,0"
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
          Ptr<LteEnbNetDevice> enbdev = node->GetDevice (j)->GetObject<LteEnbNetDevice> ();
          Ptr<MmWaveEnbNetDevice> mmdev = node->GetDevice (j)->GetObject<MmWaveEnbNetDevice> ();
          if (enbdev)
            {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << enbdev->GetCellId () << "\" at " << pos.x << "," << pos.y
                      << " left font \"Helvetica,8\" textcolor rgb \"blue\" front  point pt 4 ps "
                         "0.3 lc rgb \"blue\" offset 0,0"
                      << std::endl;
            }
          else if (mmdev)
            {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << mmdev->GetCellId () << "\" at " << pos.x << "," << pos.y
                      << " left font \"Helvetica,8\" textcolor rgb \"red\" front  point pt 4 ps "
                         "0.3 lc rgb \"red\" offset 0,0"
                      << std::endl;
            }
        }
    }
}

void
ChangePosition (Ptr<Node> node, Vector vector)
{
  Ptr<MobilityModel> model = node->GetObject<MobilityModel> ();
  model->SetPosition (vector);
  NS_LOG_UNCOND ("************************--------------------Change "
                 "Position-------------------------------*****************");
}

void
ChangeSpeed (Ptr<Node> n, Vector speed)
{
  n->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (speed);
  NS_LOG_UNCOND ("************************--------------------Change "
                 "Speed-------------------------------*****************");
}

void
PrintPosition (Ptr<Node> node)
{
  Ptr<MobilityModel> model = node->GetObject<MobilityModel> ();
  NS_LOG_UNCOND ("Position +****************************** " << model->GetPosition () << " at time "
                                                             << Simulator::Now ().GetSeconds ());
}

void
PrintLostUdpPackets (Ptr<UdpServer> app, std::string fileName)
{
  std::ofstream logFile (fileName.c_str (), std::ofstream::app);
  logFile << Simulator::Now ().GetSeconds () << " " << app->GetLost () << std::endl;
  logFile.close ();
  Simulator::Schedule (MilliSeconds (20), &PrintLostUdpPackets, app, fileName);
}

bool
AreOverlapping (Box a, Box b)
{
  return !((a.xMin > b.xMax) || (b.xMin > a.xMax) || (a.yMin > b.yMax) || (b.yMin > a.yMax));
}

bool
OverlapWithAnyPrevious (Box box, std::list<Box> m_previousBlocks)
{
  for (std::list<Box>::iterator it = m_previousBlocks.begin (); it != m_previousBlocks.end (); ++it)
    {
      if (AreOverlapping (*it, box))
        {
          return true;
        }
    }
  return false;
}

std::pair<Box, std::list<Box>>
GenerateBuildingBounds (double xArea, double yArea, double maxBuildSize,
                        std::list<Box> m_previousBlocks)
{

  Ptr<UniformRandomVariable> xMinBuilding = CreateObject<UniformRandomVariable> ();
  xMinBuilding->SetAttribute ("Min", DoubleValue (30));
  xMinBuilding->SetAttribute ("Max", DoubleValue (xArea));

  NS_LOG_UNCOND ("min " << 0 << " max " << xArea);

  Ptr<UniformRandomVariable> yMinBuilding = CreateObject<UniformRandomVariable> ();
  yMinBuilding->SetAttribute ("Min", DoubleValue (0));
  yMinBuilding->SetAttribute ("Max", DoubleValue (yArea));

  NS_LOG_UNCOND ("min " << 0 << " max " << yArea);

  Box box;
  uint32_t attempt = 0;
  do
    {
      NS_ASSERT_MSG (attempt < 100, "Too many failed attempts to position non-overlapping "
                                    "buildings. Maybe area too small or too many buildings?");
      box.xMin = xMinBuilding->GetValue ();

      Ptr<UniformRandomVariable> xMaxBuilding = CreateObject<UniformRandomVariable> ();
      xMaxBuilding->SetAttribute ("Min", DoubleValue (box.xMin));
      xMaxBuilding->SetAttribute ("Max", DoubleValue (box.xMin + maxBuildSize));
      box.xMax = xMaxBuilding->GetValue ();

      box.yMin = yMinBuilding->GetValue ();

      Ptr<UniformRandomVariable> yMaxBuilding = CreateObject<UniformRandomVariable> ();
      yMaxBuilding->SetAttribute ("Min", DoubleValue (box.yMin));
      yMaxBuilding->SetAttribute ("Max", DoubleValue (box.yMin + maxBuildSize));
      box.yMax = yMaxBuilding->GetValue ();

      ++attempt;
  } while (OverlapWithAnyPrevious (box, m_previousBlocks));

  NS_LOG_UNCOND ("Building in coordinates (" << box.xMin << " , " << box.yMin << ") and ("
                                             << box.xMax << " , " << box.yMax << ") accepted after "
                                             << attempt << " attempts");
  m_previousBlocks.push_back (box);
  std::pair<Box, std::list<Box>> pairReturn = std::make_pair (box, m_previousBlocks);
  return pairReturn;
}
bool
isDir (std::string path)
{
  struct stat statbuf;
  if (stat (path.c_str (), &statbuf) != 0)
    return false;
  return S_ISDIR (statbuf.st_mode);
}

void
deployEnb (int deploypoints[][2])
{

  unsigned seed1 = std::chrono::system_clock::now ().time_since_epoch ().count ();
  std::default_random_engine generator (seed1);
  std::uniform_int_distribution<int> distribution (1, 1000);

  int x = distribution (generator);
  int y = distribution (generator);
  std::cout << "1 Point X: " << x << "\tY: " << y << std::endl;
  deploypoints[0][0] = x;
  deploypoints[0][1] = y;
  int numofgNb = 1;
  int intergNbgap = 100;
  int numofAttempts = 0;
  while (numofgNb < 10)
    {
      numofAttempts++;
      int thisx = distribution (generator);
      int thisy = distribution (generator);
      bool overlapping = false;
      for (int j = 0; j < numofgNb; j++)
        {
          double distance = sqrt (
              (pow ((thisx - deploypoints[j][0]), 2) + pow ((thisy - deploypoints[j][1]), 2)));

          if ((distance < 2 * intergNbgap) || (thisx < 150) || (thisy < 150) || (thisx > 850) ||
              (thisy > 850))
            {
              //overlapping gNbs
              overlapping = true;
              break;
            }
        }
      if (!overlapping)
        {
          deploypoints[numofgNb][0] = thisx;
          deploypoints[numofgNb][1] = thisy;
          numofgNb++;
          std::cout << numofgNb << " Point X: " << deploypoints[numofgNb - 1][0]
                    << "\tY: " << deploypoints[numofgNb - 1][1] << std::endl;
        }
      if (numofAttempts > 10000)
        {
          break;
        }
    }
  std::cout << "Number of Attempts Made\t" << numofAttempts << std::endl;
}

void
EnergyConsumptionUpdate (uint32_t node_id, double totaloldEnergyConsumption,
                         double totalnewEnergyConsumption)
{
  ue_energy_map[node_id] = totalnewEnergyConsumption;
}

void
EnbEnergyConsumptionUpdate (uint32_t node_id, double totaloldEnergyConsumption,
                         double totalnewEnergyConsumption)
{
  enb_energy_map[node_id] = totalnewEnergyConsumption;
}

void
NotifyConnectionEstablishedUe (std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti)
{


  int imsi_count = imsi_list[cellid].size ();
  Ptr<Node> gnode_2 = cellid_node[cellid];

  std::cout << "Total number of UE " << imsi_count << " Connected to Cell " << cellid << std::endl;
}

void
NotifyHandoverStartUe (std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti,
                       uint16_t targetCellId)
{

  std::cout << Simulator::Now ().GetSeconds () << " " << context << " UE IMSI " << imsi
            << ": previously connected to CellId " << cellid << " with RNTI " << rnti
            << ", doing handover to CellId " << targetCellId << std::endl;
}

void
NotifyHandoverEndOkUe (std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti)
{
  uint32_t nodeid = ueimsi_nodeid[imsi];
  ue_cellid_usinghandover[nodeid] = cellid;

  std::cout << Simulator::Now ().GetSeconds () << " " << context << " UE IMSI " << imsi
            << ": successful handover to CellId " << cellid << " with RNTI " << rnti << std::endl;
}

void
NotifyConnectionEstablishedEnb (std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti)
{

  std::cout << Simulator::Now ().GetSeconds () << " " << context << " eNB CellId " << cellid
            << ": successful connection of UE with IMSI " << imsi << " RNTI " << rnti << std::endl;
}

void
NotifyHandoverStartEnb (std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti,
                        uint16_t targetCellId)
{

  std::cout << Simulator::Now ().GetSeconds () << " " << context << " eNB CellId " << cellid
            << ": start handover of UE with IMSI " << imsi << " RNTI " << rnti << " to CellId "
            << targetCellId << std::endl;
}

void
NotifyHandoverEndOkEnb (std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti)
{

  std::cout << Simulator::Now ().GetSeconds () << " " << context << " eNB CellId " << cellid
            << ": completed handover of UE with IMSI " << imsi << " RNTI " << rnti << std::endl;
}

void
traceuefunc (std::string path, RxPacketTraceParams params)
{
  string s = path;
  s.erase (0, 10);
  string token = s.substr (0, s.find ('/'));
  int nval = stoi (token);
  uint32_t nodeid = seq_nodeid[nval];
  ue_rxpackettrace[nodeid] = params;

  std::cout << "DL\t" << Simulator::Now ().GetSeconds () << "\t" << params.m_frameNum << "\t"
            << +params.m_sfNum << "\t" << +params.m_slotNum << "\t" << +params.m_symStart << "\t"
            << +params.m_numSym << "\t" << params.m_cellId << "\t" << params.m_rnti << "\t"
            << +params.m_ccId << "\t" << params.m_tbSize << "\t" << +params.m_mcs << "\t"
            << +params.m_rv << "\t" << 10 * std::log10 (params.m_sinr) << "\t" << params.m_corrupt
            << "\t" << params.m_tbler << "\t" << 10 * std::log10 (params.m_sinrMin) << std::endl;

  // tracefile << "DL," << Simulator::Now ().GetSeconds () << ","
  //                     << params.m_frameNum << "," << +params.m_sfNum << ","
  //                     << +params.m_slotNum << "," << +params.m_symStart << ","
  //                     << +params.m_numSym << "," << params.m_cellId << ","
  //                     << params.m_rnti << "," << +params.m_ccId << ","
  //                     << params.m_tbSize << "," << +params.m_mcs << ","
  //                     << +params.m_rv << "," << 10 * std::log10 (params.m_sinr) << ","
  //                     << params.m_corrupt << "," <<  params.m_tbler << ","
  //                     << 10 * std::log10(params.m_sinrMin) << std::endl;
}

void
traceenbfunc (std::string path, RxPacketTraceParams params)
{

  std::cout << "UL\t" << Simulator::Now ().GetSeconds () << "\t" << params.m_frameNum << "\t"
            << +params.m_sfNum << "\t" << +params.m_slotNum << "\t" << +params.m_symStart << "\t"
            << +params.m_numSym << "\t" << params.m_cellId << "\t" << params.m_rnti << "\t"
            << +params.m_ccId << "\t" << params.m_tbSize << "\t" << +params.m_mcs << "\t"
            << +params.m_rv << "\t" << 10 * std::log10 (params.m_sinr) << "\t" << params.m_corrupt
            << "\t" << params.m_tbler << "\t" << 10 * std::log10 (params.m_sinrMin) << std::endl;
}

void
CourseChange (uint32_t nodeid, Ptr<const MobilityModel> model)
{
  if (Simulator::Now ().GetSeconds () * 10 > 40)
    {
      double x_s = model->GetVelocity ().x;
      double y_s = model->GetVelocity ().y;
      ue_speed[nodeid] = sqrt (x_s * x_s + y_s * y_s);

      uint16_t connected_cellid = ue_cellid[nodeid];
      Ptr<Node> ap = cellid_node[connected_cellid];

      //   Ptr<MobilityModel> apModel = ap->GetObject<MobilityModel> ();
      double m_distance = model->GetDistanceFrom (ap->GetObject<MobilityModel> ());

      ue_distancefromgnodeb[nodeid] = make_pair (connected_cellid, m_distance);

      Vector position = model->GetPosition ();
      std::cout << "node " << nodeid << " x = " << position.x << ", y = " << position.y << "\n";
    }
}

void
trace_data (uint32_t node_id)
{

  double totalnewEnergyConsumption = ue_energy_map[node_id];
  RxPacketTraceParams params = ue_rxpackettrace[node_id];
  double velocity = ue_speed[node_id];
  pair<uint16_t, double> cellid_distance = ue_distancefromgnodeb[node_id];
  double enbEnergyConsumption = enb_energy_map[cellid_distance.first];

  double currenttime = Simulator::Now ().GetSeconds ();
  std::ofstream outFile;
  outFile.open (outputDir + tracefilename, std::ios::out | std::ios::app);
  outFile << currenttime << "," << node_id << "," << totalnewEnergyConsumption << ","
          << enbEnergyConsumption << "," << cellid_distance.first << "," << cellid_distance.second << "," 
          << velocity << "," << params.m_cellId << "," << params.m_rnti << "," << +params.m_ccId << ","
          << params.m_tbSize << "," << +params.m_mcs << "," << +params.m_rv << ","
          << 10 * std::log10 (params.m_sinr) << "," << params.m_corrupt << "," << params.m_tbler
          << "," << 10 * std::log10 (params.m_sinrMin) << "," << params.m_sinr << std::endl;

  Simulator::Schedule (Seconds (1), &trace_data, node_id);
}

static ns3::GlobalValue
    g_mmw1DistFromMainStreet ("mmw1Dist", "Distance from the main street of the first MmWaveEnb",
                              ns3::UintegerValue (50), ns3::MakeUintegerChecker<uint32_t> ());
static ns3::GlobalValue
    g_mmw2DistFromMainStreet ("mmw2Dist", "Distance from the main street of the second MmWaveEnb",
                              ns3::UintegerValue (50), ns3::MakeUintegerChecker<uint32_t> ());
static ns3::GlobalValue
    g_mmw3DistFromMainStreet ("mmw3Dist", "Distance from the main street of the third MmWaveEnb",
                              ns3::UintegerValue (110), ns3::MakeUintegerChecker<uint32_t> ());
static ns3::GlobalValue g_mmWaveDistance ("mmWaveDist", "Distance between MmWave eNB 1 and 2",
                                          ns3::UintegerValue (200),
                                          ns3::MakeUintegerChecker<uint32_t> ());
// static ns3::GlobalValue g_numBuildingsBetweenMmWaveEnb ("numBlocks", "Number of buildings between MmWave eNB 1 and 2",
//                                                         ns3::UintegerValue (8), ns3::MakeUintegerChecker<uint32_t> ());
static ns3::GlobalValue g_interPckInterval ("interPckInterval",
                                            "Interarrival time of UDP packets (us)",
                                            ns3::UintegerValue (20),
                                            ns3::MakeUintegerChecker<uint32_t> ());
static ns3::GlobalValue g_bufferSize ("bufferSize", "RLC tx buffer size (MB)",
                                      ns3::UintegerValue (20),
                                      ns3::MakeUintegerChecker<uint32_t> ());
static ns3::GlobalValue g_x2Latency ("x2Latency", "Latency on X2 interface (us)",
                                     ns3::DoubleValue (500), ns3::MakeDoubleChecker<double> ());
static ns3::GlobalValue g_mmeLatency ("mmeLatency", "Latency on MME interface (us)",
                                      ns3::DoubleValue (10000), ns3::MakeDoubleChecker<double> ());
static ns3::GlobalValue g_mobileUeSpeed ("mobileSpeed", "The speed of the UE (m/s)",
                                         ns3::DoubleValue (2), ns3::MakeDoubleChecker<double> ());
static ns3::GlobalValue g_rlcAmEnabled ("rlcAmEnabled", "If true, use RLC AM, else use RLC UM",
                                        ns3::BooleanValue (true), ns3::MakeBooleanChecker ());
// static ns3::GlobalValue g_maxXAxis ("maxXAxis", "The maximum X coordinate for the area in which to deploy the buildings",
//                                     ns3::DoubleValue (150), ns3::MakeDoubleChecker<double> ());
// static ns3::GlobalValue g_maxYAxis ("maxYAxis", "The maximum Y coordinate for the area in which to deploy the buildings",
//                                     ns3::DoubleValue (40), ns3::MakeDoubleChecker<double> ());
static ns3::GlobalValue g_outPath ("outPath", "The path of output log files",
                                   ns3::StringValue ("./"), ns3::MakeStringChecker ());
static ns3::GlobalValue g_noiseAndFilter (
    "noiseAndFilter",
    "If true, use noisy SINR samples, filtered. If false, just use the SINR measure",
    ns3::BooleanValue (false), ns3::MakeBooleanChecker ());
static ns3::GlobalValue g_handoverMode ("handoverMode", "Handover mode", ns3::UintegerValue (3),
                                        ns3::MakeUintegerChecker<uint8_t> ());
static ns3::GlobalValue g_reportTablePeriodicity ("reportTablePeriodicity", "Periodicity of RTs",
                                                  ns3::UintegerValue (1600),
                                                  ns3::MakeUintegerChecker<uint32_t> ());
static ns3::GlobalValue g_outageThreshold ("outageTh", "Outage threshold", ns3::DoubleValue (-5),
                                           ns3::MakeDoubleChecker<double> ());
static ns3::GlobalValue g_lteUplink ("lteUplink", "If true, always use LTE for uplink signalling",
                                     ns3::BooleanValue (false), ns3::MakeBooleanChecker ());

int
main (int argc, char *argv[])
{
  bool harqEnabled = true;
  bool fixedTti = false;

  std::list<Box> m_previousBlocks;

  // Command line arguments
  CommandLine cmd;
  cmd.AddValue ("outputDir", "Output Directory for trace storing", outputDir);
  cmd.Parse (argc, argv);

  UintegerValue uintegerValue;
  BooleanValue booleanValue;
  StringValue stringValue;
  DoubleValue doubleValue;
  //EnumValue enumValue;
//   GlobalValue::GetValueByName ("numBlocks", uintegerValue);
//   uint32_t numBlocks = uintegerValue.Get ();
//   GlobalValue::GetValueByName ("maxXAxis", doubleValue);
//   double maxXAxis = doubleValue.Get ();
//   GlobalValue::GetValueByName ("maxYAxis", doubleValue);
//   double maxYAxis = doubleValue.Get ();

//   double ueInitialPosition = 90;
//   double ueFinalPosition = 110;

  // Variables for the RT
  int windowForTransient = 150; // number of samples for the vector to use in the filter
  GlobalValue::GetValueByName ("reportTablePeriodicity", uintegerValue);
  int ReportTablePeriodicity = (int) uintegerValue.Get (); // in microseconds
  if (ReportTablePeriodicity == 1600)
    {
      windowForTransient = 150;
    }
  else if (ReportTablePeriodicity == 25600)
    {
      windowForTransient = 50;
    }
  else if (ReportTablePeriodicity == 12800)
    {
      windowForTransient = 100;
    }
  else
    {
      NS_ASSERT_MSG (false, "Unrecognized");
    }
  if (!isDir (outputDir))
    {
      mkdir (outputDir.c_str (), S_IRWXU);
    }

  int vectorTransient = windowForTransient * ReportTablePeriodicity;

  // params for RT, filter, HO mode
  GlobalValue::GetValueByName ("noiseAndFilter", booleanValue);
  bool noiseAndFilter = booleanValue.Get ();
  GlobalValue::GetValueByName ("handoverMode", uintegerValue);
  uint8_t hoMode = uintegerValue.Get ();
  GlobalValue::GetValueByName ("outageTh", doubleValue);
  double outageTh = doubleValue.Get ();

  GlobalValue::GetValueByName ("rlcAmEnabled", booleanValue);
  bool rlcAmEnabled = booleanValue.Get ();
  GlobalValue::GetValueByName ("bufferSize", uintegerValue);
  uint32_t bufferSize = uintegerValue.Get ();
  GlobalValue::GetValueByName ("interPckInterval", uintegerValue);
  uint32_t interPacketInterval = uintegerValue.Get ();
  GlobalValue::GetValueByName ("x2Latency", doubleValue);
  double x2Latency = doubleValue.Get ();
  GlobalValue::GetValueByName ("mmeLatency", doubleValue);
  double mmeLatency = doubleValue.Get ();
  GlobalValue::GetValueByName ("mobileSpeed", doubleValue);
  double ueSpeed = doubleValue.Get ();

//   double transientDuration = double(vectorTransient) / 1000000;
//   double simTime = transientDuration + ((double)ueFinalPosition - (double)ueInitialPosition) / ueSpeed + 1;

  NS_LOG_UNCOND ("rlcAmEnabled " << rlcAmEnabled << " bufferSize " << bufferSize
                                 << " interPacketInterval " << interPacketInterval << " x2Latency "
                                 << x2Latency << " mmeLatency " << mmeLatency << " mobileSpeed "
                                 << ueSpeed);

  GlobalValue::GetValueByName ("outPath", stringValue);
  std::string path = stringValue.Get ();
  std::string mmWaveOutName = "MmWaveSwitchStats";
  std::string lteOutName = "LteSwitchStats";
  std::string dlRlcOutName = "DlRlcStats";
  std::string dlPdcpOutName = "DlPdcpStats";
  std::string ulRlcOutName = "UlRlcStats";
  std::string ulPdcpOutName = "UlPdcpStats";
  std::string ueHandoverStartOutName = "UeHandoverStartStats";
  std::string enbHandoverStartOutName = "EnbHandoverStartStats";
  std::string ueHandoverEndOutName = "UeHandoverEndStats";
  std::string enbHandoverEndOutName = "EnbHandoverEndStats";
  std::string cellIdInTimeOutName = "CellIdStats";
  std::string cellIdInTimeHandoverOutName = "CellIdStatsHandover";
  std::string mmWaveSinrOutputFilename = "MmWaveSinrTime";
  std::string x2statOutputFilename = "X2Stats";
  std::string udpSentFilename = "UdpSent";
  std::string udpReceivedFilename = "UdpReceived";
  std::string extension = ".txt";
  std::string version;
  version = "mc";
  Config::SetDefault ("ns3::MmWaveUeMac::UpdateUeSinrEstimatePeriod", DoubleValue (0));

  //get current time
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[80];
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  strftime (buffer,80,"%d_%m_%Y_%I_%M_%S",timeinfo);
  std::string time_str (buffer);

  Config::SetDefault ("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue (rlcAmEnabled));
  Config::SetDefault ("ns3::MmWaveHelper::HarqEnabled", BooleanValue (harqEnabled));
  Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue (harqEnabled));
  Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::HarqEnabled", BooleanValue (harqEnabled));
  Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::FixedTti", BooleanValue (fixedTti));
  Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::SymPerSlot", UintegerValue (6));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::TbDecodeLatency", UintegerValue (200.0));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::NumHarqProcess", UintegerValue (100));
  Config::SetDefault ("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue (MilliSeconds (100.0)));
  Config::SetDefault ("ns3::LteEnbRrc::SystemInformationPeriodicity", TimeValue (MilliSeconds (5.0)));
  Config::SetDefault ("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue (MicroSeconds (100.0)));
  Config::SetDefault ("ns3::LteRlcUmLowLat::ReportBufferStatusTimer", TimeValue (MicroSeconds (100.0)));
  Config::SetDefault ("ns3::LteEnbRrc::SrsPeriodicity", UintegerValue (320));
  Config::SetDefault ("ns3::LteEnbRrc::FirstSibTime", UintegerValue (2));
  Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkDelay", TimeValue (MicroSeconds (x2Latency)));
  Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkDataRate", DataRateValue (DataRate ("1000Gb/s")));
  Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkMtu",  UintegerValue (10000));
  Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::S1uLinkDelay", TimeValue (MicroSeconds (1000)));
  Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::S1apLinkDelay", TimeValue (MicroSeconds (mmeLatency)));
  Config::SetDefault ("ns3::LteRlcUm::MaxTxBufferSize", UintegerValue (bufferSize * 1024 * 1024));
  Config::SetDefault ("ns3::LteRlcUmLowLat::MaxTxBufferSize", UintegerValue (bufferSize * 1024 * 1024));
  Config::SetDefault ("ns3::LteRlcAm::StatusProhibitTimer", TimeValue (MilliSeconds (10.0)));
  Config::SetDefault ("ns3::LteRlcAm::MaxTxBufferSize", UintegerValue (bufferSize * 1024 * 1024));

  // handover and RT related params
  switch (hoMode)
    {
    case 1:
      Config::SetDefault ("ns3::LteEnbRrc::SecondaryCellHandoverMode", EnumValue (LteEnbRrc::THRESHOLD));
      break;
    case 2:
      Config::SetDefault ("ns3::LteEnbRrc::SecondaryCellHandoverMode", EnumValue (LteEnbRrc::FIXED_TTT));
      break;
    case 3:
      Config::SetDefault ("ns3::LteEnbRrc::SecondaryCellHandoverMode", EnumValue (LteEnbRrc::DYNAMIC_TTT));
      break;
    }

  Config::SetDefault ("ns3::LteEnbRrc::FixedTttValue", UintegerValue (150));
  Config::SetDefault ("ns3::LteEnbRrc::CrtPeriod", IntegerValue (ReportTablePeriodicity));
  Config::SetDefault ("ns3::LteEnbRrc::OutageThreshold", DoubleValue (outageTh));
  Config::SetDefault ("ns3::MmWaveEnbPhy::UpdateSinrEstimatePeriod", IntegerValue (ReportTablePeriodicity));
  Config::SetDefault ("ns3::MmWaveEnbPhy::Transient", IntegerValue (vectorTransient));
  Config::SetDefault ("ns3::MmWaveEnbPhy::NoiseAndFilter", BooleanValue (noiseAndFilter));
  
  // set the type of RRC to use, i.e., ideal or real
  // by setting the following two attributes to true, the simulation will use 
  // the ideal paradigm, meaning no packets are sent. in fact, only the callbacks are triggered
  Config::SetDefault ("ns3::MmWaveHelper::UseIdealRrc", BooleanValue(true));

  GlobalValue::GetValueByName ("lteUplink", booleanValue);
  bool lteUplink = booleanValue.Get ();

  Config::SetDefault ("ns3::McUePdcp::LteUplink", BooleanValue (lteUplink));
  std::cout << "Lte uplink " << lteUplink << "\n";

  // settings for the 3GPP the channel
  Config::SetDefault ("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue (MilliSeconds (100))); // interval after which the channel for a moving user is updated,
  Config::SetDefault ("ns3::ThreeGppChannelModel::Blockage", BooleanValue (true)); // use blockage or not
  Config::SetDefault ("ns3::ThreeGppChannelModel::PortraitMode", BooleanValue (true)); // use blockage model with UT in portrait mode
  Config::SetDefault ("ns3::ThreeGppChannelModel::NumNonselfBlocking", IntegerValue (4)); // number of non-self blocking obstacles

  // set the number of antennas in the devices
  Config::SetDefault ("ns3::McUeNetDevice::AntennaNum", UintegerValue(16));
  Config::SetDefault ("ns3::MmWaveNetDevice::AntennaNum", UintegerValue(64));
  
  // set to false to use the 3GPP radiation pattern (proper configuration of the bearing and downtilt angles is needed) 
  Config::SetDefault ("ns3::ThreeGppAntennaArrayModel::IsotropicElements", BooleanValue (true)); 

  Ptr<MmWaveHelper> mmwaveHelper = CreateObject<MmWaveHelper> ();
  mmwaveHelper->SetPathlossModelType ("ns3::ThreeGppUmiStreetCanyonPropagationLossModel");
//   mmwaveHelper->SetChannelConditionModelType ("ns3::BuildingsChannelConditionModel");

  Ptr<MmWavePointToPointEpcHelper> epcHelper = CreateObject<MmWavePointToPointEpcHelper> ();
  mmwaveHelper->SetEpcHelper (epcHelper);
  mmwaveHelper->SetHarqEnabled (harqEnabled);
  mmwaveHelper->Initialize ();

  ConfigStore inputConfig;
  inputConfig.ConfigureDefaults ();

  // parse again so you can override default values from the command line
  cmd.Parse (argc, argv);

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
  p2ph.SetDeviceAttribute ("Mtu", UintegerValue (2500));
  p2ph.SetChannelAttribute ("Delay", TimeValue (Seconds (0.010)));
  NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);
  Ipv4AddressHelper ipv4h;
  ipv4h.SetBase ("1.0.0.0", "255.0.0.0");
  Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign (internetDevices);
  // interface 0 is localhost, 1 is the p2p device
  Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress (1);
  std::cout << "RemoteHostAddr. " << remoteHostAddr << std::endl; 
  Ipv4StaticRoutingHelper ipv4RoutingHelper;
  Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
  remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.0.0.0"), 1);

  Ns2MobilityHelper sumo_trace ("scratch/ns2mobility.tcl");

  // create LTE, mmWave eNB nodes and UE node
  double gNbHeight = 10;
  uint16_t ueNum = 50;
  uint16_t gNbNum = 10;
  NodeContainer ueNodes;
 // NodeContainer enbNodes;
  NodeContainer mmWaveEnbNodes;
  NodeContainer lteEnbNodes;
  NodeContainer allEnbNodes;
  ueNodes.Create (ueNum);
  mmWaveEnbNodes.Create (2);
  lteEnbNodes.Create (1);
  allEnbNodes.Add (lteEnbNodes);
  allEnbNodes.Add (mmWaveEnbNodes);
  sumo_trace.Install(ueNodes.Begin(),ueNodes.End());

 for (uint32_t i = 0; i < mmWaveEnbNodes.GetN(); i++)
    {
      std::cout << "gNb:" << i << " : " << mmWaveEnbNodes.Get (i)->GetId ()
          << std::endl;
    }
  for (uint32_t i = 0; i < ueNodes.GetN (); i++)
    {
      std::cout << "ue:" << i << " : " << ueNodes.Get (i)->GetId ()
          << std::endl;
    }
  for (uint32_t i = 0; i < lteEnbNodes.GetN (); i++)
    {
      std::cout << "LTE:" << i << " : " << lteEnbNodes.Get (i)->GetId ()
          << std::endl;
    }

  // Positions
//   std::vector<Ptr<Building> > buildingVector;

//   double maxBuildingSize = 20;

//   for (uint32_t buildingIndex = 0; buildingIndex < numBlocks; buildingIndex++)
//     {
//       Ptr < Building > building;
//       building = Create<Building> ();
//       /* returns a vecotr where:
//       * position [0]: coordinates for x min
//       * position [1]: coordinates for x max
//       * position [2]: coordinates for y min
//       * position [3]: coordinates for y max
//       */
//       std::pair<Box, std::list<Box> > pairBuildings = GenerateBuildingBounds (maxXAxis, maxYAxis, maxBuildingSize, m_previousBlocks);
//       m_previousBlocks = std::get<1> (pairBuildings);
//       Box box = std::get<0> (pairBuildings);
//       Ptr<UniformRandomVariable> randomBuildingZ = CreateObject<UniformRandomVariable> ();
//       randomBuildingZ->SetAttribute ("Min",DoubleValue (1.6));
//       randomBuildingZ->SetAttribute ("Max",DoubleValue (40));
//       double buildingHeight = randomBuildingZ->GetValue ();

//       building->SetBoundaries (Box (box.xMin, box.xMax,
//                                     box.yMin,  box.yMax,
//                                     0.0, buildingHeight));
//       buildingVector.push_back (building);
//     }


  // Install Mobility Model
  MobilityHelper gNbMobility, ueMobility, LteMobility;
  Ptr<ListPositionAllocator> ltepositionAloc = CreateObject<ListPositionAllocator> ();
    
  Ptr<ListPositionAllocator> apPositionAlloc = CreateObject<ListPositionAllocator> ();
  // int mobilityType = 1;
  // if(mobilityType == 0)
  //   {
  //     ueMobility.SetPositionAllocator ("ns3::GridPositionAllocator",
  //                                      "MinX", DoubleValue (166.0),
  //                                      "MinY", DoubleValue (333.0),
  //                                      "DeltaX", DoubleValue (166.0),
  //                                      "DeltaY", DoubleValue (333.0),
  //                                      "GridWidth", UintegerValue (5),
  //                                      "LayoutType", StringValue ("RowFirst"));
  //     ueMobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  //   }
  // else if (mobilityType == 1)
  // {
  //   Ptr<ListPositionAllocator> staPositionAllocator = CreateObject<ListPositionAllocator> ();
  //   double x_random, y_random;
  //   for(uint32_t i = 0; i < ueNodes.GetN(); i ++)
  //   {
  //     x_random = (rand() % 1000) + 1;
  //     y_random = (rand() % 1000) + 1;
  //     staPositionAllocator->Add (Vector (x_random, y_random, 1.5));
  //   }
  //   ueMobility.SetPositionAllocator(staPositionAllocator);
  //   ueMobility.SetMobilityModel("ns3::RandomWalk2dMobilityModel",
  //     "Bounds", RectangleValue (Rectangle (0, 1000, 0, 1000)),
  //     "Speed", StringValue("ns3::UniformRandomVariable[Min=" + std::to_string(5) + "|Max=" + std::to_string(30) + "]"));
  // }
  
  
  // ueMobility.Install (ueNodes);
  //BuildingsHelper::Install(ueNodes);
    for (uint32_t i = 0; i < ueNodes.GetN (); i++)
  {
    Ptr<MobilityModel> model = ueNodes.Get (i)->GetObject<MobilityModel> ();
    std::cout << "Node " << i << " Position " << model->GetPosition () << std::endl;
  }
  int p[gNbNum][2] = {};
  deployEnb(p);
  for(int i = 0; i < gNbNum; i++)
   {
       apPositionAlloc->Add (Vector (p[i][0],p[i][1],gNbHeight));
   }

  LteMobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  ltepositionAloc->Add(Vector(500.0, 500, 10.0));
  LteMobility.SetPositionAllocator (ltepositionAloc);
  LteMobility.Install (lteEnbNodes);

  gNbMobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  gNbMobility.SetPositionAllocator (apPositionAlloc);
  gNbMobility.Install (mmWaveEnbNodes);

//   BuildingsHelper::Install (ueNodes);

  //ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (ueInitialPosition, -5, 0));
//   ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (ueInitialPosition, -5, 1.6));
//   ueNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (0, 0, 0));

  // Install mmWave, lte, mc Devices to the nodes
  NetDeviceContainer lteEnbDevs = mmwaveHelper->InstallLteEnbDevice (lteEnbNodes);
  NetDeviceContainer mmWaveEnbDevs = mmwaveHelper->InstallEnbDevice (mmWaveEnbNodes);
  NetDeviceContainer mcUeDevs;
  mcUeDevs = mmwaveHelper->InstallMcUeDevice (ueNodes);

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
 for (uint32_t i = 0; i < ueNodes.GetN (); i++)
    {
      ueimsi_nodeid[mcUeDevs.Get(i)->GetObject<McUeNetDevice>()->GetImsi()]= ueNodes.Get(i)->GetId();
      std::cout << "ue:" << i << " : " << ueNodes.Get (i)->GetId ()
          << std::endl;
    }

    for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
    {
      
      Ptr<Node> ueNode = ueNodes.Get (u);
      seq_nodeid[u]=ueNode->GetId();
      // Set the default gateway for the UE
      Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (ueNode->GetObject<Ipv4> ());
      ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);
    }
  for(uint32_t i = 0; i < mmWaveEnbNodes.GetN(); i++)
  {
    Ptr<MmWaveEnbNetDevice> mmdev = DynamicCast<MmWaveEnbNetDevice> (mmWaveEnbNodes.Get(i)->GetDevice(0));
    Ptr<Node> nn=mmWaveEnbNodes.Get(i);
    cellid_node[mmdev->GetCellId()]  = nn;
  }
// distancechange & trackcellid

BasicEnergySourceHelper basicSourceHelper;
  basicSourceHelper.Set ("BasicEnergySourceInitialEnergyJ", DoubleValue (10));
  basicSourceHelper.Set ("BasicEnergySupplyVoltageV", DoubleValue (5.0));
  basicSourceHelper.Set ("BasicEnergySourceInitialEnergyJ", DoubleValue (1000000000.0));
  for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
  {
    // Install Energy Source
    EnergySourceContainer sources = basicSourceHelper.Install (ueNodes.Get (u));
    // Device Energy Model
    MmWaveRadioEnergyModelHelper nrEnergyHelper;
    DeviceEnergyModelContainer deviceEnergyModel = nrEnergyHelper.Install (ueNodes.Get(u)->GetDevice (0), sources);
    //Install and start applications on UEs and remote host
    Ptr<Node> nn = ueNodes.Get (u);
    deviceEnergyModel.Get(0)->TraceConnectWithoutContext ("TotalEnergyConsumption", MakeBoundCallback (&EnergyConsumptionUpdate,nn->GetId()));
    
  }

  for (uint32_t u = 0; u < mmWaveEnbNodes.GetN (); ++u)
  {
    // Install Energy Source
    EnergySourceContainer sources = basicSourceHelper.Install (mmWaveEnbNodes.Get (u));
    // Device Energy Model
    MmWaveRadioEnergyModelEnbHelper nrEnergyHelper;
    DeviceEnergyModelContainer deviceEnergyModel = nrEnergyHelper.Install (mmWaveEnbNodes.Get(u)->GetDevice (0), sources);
    //Install and start applications on UEs and remote host
    Ptr<Node> nn = mmWaveEnbNodes.Get (u);
    deviceEnergyModel.Get(0)->TraceConnectWithoutContext ("TotalEnergyConsumption", MakeBoundCallback (&EnergyConsumptionUpdate,nn->GetId()));
    
  }
  bool tcp = true;
  // Install and start applications on UEs and remote host
   if (tcp)
    {
      // Install and start applications on UEs and remote host
      uint16_t sinkPort = 20000;

      Address sinkAddress (InetSocketAddress (ueIpIface.GetAddress (0), sinkPort));
      PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), sinkPort));
      ApplicationContainer sinkApps = packetSinkHelper.Install (ueNodes);

      sinkApps.Start (Seconds (5));
      sinkApps.Stop (Seconds (86400));

      Ptr<Socket> ns3TcpSocket = Socket::CreateSocket (remoteHostContainer.Get (0), TcpSocketFactory::GetTypeId ());
      Ptr<MyApp> app = CreateObject<MyApp> ();
      app->Setup (ns3TcpSocket, sinkAddress, 1400, 5000000, DataRate ("500Mb/s"));

      remoteHostContainer.Get (0)->AddApplication (app);
      AsciiTraceHelper asciiTraceHelper;
      Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream ("mmWave-tcp-window-newreno.txt");
      ns3TcpSocket->TraceConnectWithoutContext ("CongestionWindow", MakeBoundCallback (&CwndChange, stream1));

      Ptr<OutputStreamWrapper> stream4 = asciiTraceHelper.CreateFileStream ("mmWave-tcp-rtt-newreno.txt");
      ns3TcpSocket->TraceConnectWithoutContext ("RTT", MakeBoundCallback (&RttChange, stream4));

      Ptr<OutputStreamWrapper> stream2 = asciiTraceHelper.CreateFileStream ("mmWave-tcp-data-newreno.txt");
      sinkApps.Get (0)->TraceConnectWithoutContext ("Rx",MakeBoundCallback (&Rx, stream2));

      //Ptr<OutputStreamWrapper> stream3 = asciiTraceHelper.CreateFileStream ("mmWave-tcp-sstresh-newreno.txt");
      //ns3TcpSocket->TraceConnectWithoutContext("SlowStartThreshold",MakeBoundCallback (&Sstresh, stream3));
      app->SetStartTime (Seconds (5));
      app->SetStopTime (Seconds (86400));
    }
  else
    {
      // Install and start applications on UEs and remote host
      uint16_t sinkPort = 20000;

      Address sinkAddress (InetSocketAddress (ueIpIface.GetAddress (0), sinkPort));
      PacketSinkHelper packetSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), sinkPort));
      ApplicationContainer sinkApps = packetSinkHelper.Install (ueNodes);

      sinkApps.Start (Seconds (5));
      sinkApps.Stop (Seconds (86400));

      Ptr<Socket> ns3UdpSocket = Socket::CreateSocket (remoteHostContainer.Get (0), UdpSocketFactory::GetTypeId ());
      Ptr<MyApp> app = CreateObject<MyApp> ();
      app->Setup (ns3UdpSocket, sinkAddress, 1400, 5000000, DataRate ("500Mb/s"));

      remoteHostContainer.Get (0)->AddApplication (app);
      AsciiTraceHelper asciiTraceHelper;
      Ptr<OutputStreamWrapper> stream2 = asciiTraceHelper.CreateFileStream ("mmWave-udp-data-am.txt");
      sinkApps.Get (0)->TraceConnectWithoutContext ("Rx",MakeBoundCallback (&Rx, stream2));

      app->SetStartTime (Seconds (5));
      app->SetStopTime (Seconds (86400));

    }

  // Start applications
  std::ofstream tracefile;
  tracefile.open (outputDir + tracefilename, std::ios::out | std::ios::trunc);
  tracefile << "Time,NodeId,Energy,Energy_BS,CellId,Distance,Velocity,cellId,rnti,ccId,tbSize,mcs,rv,SINR(dB),corrupt,TBler,min_sinr,rsrp";
  tracefile << std::endl;
  
  Config::Connect ("/NodeList/*/DeviceList/*/LteEnbRrc/ConnectionEstablished",
                   MakeCallback (&NotifyConnectionEstablishedEnb));
  Config::Connect ("/NodeList/*/DeviceList/*/LteUeRrc/ConnectionEstablished",
                   MakeCallback (&NotifyConnectionEstablishedUe));
  Config::Connect ("/NodeList/*/DeviceList/*/LteEnbRrc/HandoverStart",
                   MakeCallback (&NotifyHandoverStartEnb));
  Config::Connect ("/NodeList/*/DeviceList/*/LteUeRrc/HandoverStart",
                   MakeCallback (&NotifyHandoverStartUe));
  Config::Connect ("/NodeList/*/DeviceList/*/LteEnbRrc/HandoverEndOk",
                   MakeCallback (&NotifyHandoverEndOkEnb));
  Config::Connect ("/NodeList/*/DeviceList/*/LteUeRrc/HandoverEndOk",
                   MakeCallback (&NotifyHandoverEndOkUe));

  Config::Connect ("/NodeList/*/DeviceList/*/MmWaveComponentCarrierMapUe/*/MmWaveUePhy/DlSpectrumPhy/RxPacketTraceUe",
                   MakeCallback (&traceuefunc));

  Config::Connect ("/NodeList/*/DeviceList/*/ComponentCarrierMap/*/MmWaveEnbPhy/DlSpectrumPhy/RxPacketTraceEnb",
                   MakeCallback (&traceenbfunc));
    for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
    {
      Ptr<Node> nn = ueNodes.Get (u);
      Ptr<MmWaveUePhy> mmwaveUePhy =
          nn->GetDevice (0)->GetObject<McUeNetDevice> ()->GetMmWavePhy ();
      mmwaveUePhy->TraceConnectWithoutContext ("CurrentCellId",
                                               MakeBoundCallback (&trackCellId, nn->GetId ()));
      //mmwaveUePhy->TraceConnectWithoutContext("Distancefromconnectedgnodeb",MakeBoundCallback(&distancechange,nn->GetId()));
    }

  for (uint32_t j = 0; j < ueNodes.GetN (); j++)
    {
      Ptr<MobilityModel> mModel = ueNodes.Get (j)->GetObject<MobilityModel> ();
      mModel->TraceConnectWithoutContext (
          "CourseChange", MakeBoundCallback (&CourseChange, ueNodes.Get (j)->GetId ()));
    }
  AsciiTraceHelper ascii;
  p2ph.EnableAsciiAll (ascii.CreateFileStream ("myapplication.tr"));
  p2ph.EnablePcapAll ("myapplication");
  for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
    {
      Simulator::Schedule (Seconds (1), &trace_data, ueNodes.Get (u)->GetId ());
    }
  Simulator::Stop (Seconds (86400));
  Simulator::Run ();
  Simulator::Destroy ();

  return 0;
}