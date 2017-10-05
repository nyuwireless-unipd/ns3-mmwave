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
#include "ns3/lte-helper.h"
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
#include <ns3/random-variable-stream.h>
#include <ns3/lte-ue-net-device.h>

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <list>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("McTcp");


static ns3::GlobalValue g_mmw1DistFromMainStreet("mmw1Dist", "Distance from the main street of the first MmWaveEnb",
    ns3::UintegerValue(100), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_mmw2DistFromMainStreet("mmw2Dist", "Distance from the main street of the second MmWaveEnb",
    ns3::UintegerValue(100), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_mmw3DistFromMainStreet("mmw3Dist", "Distance from the main street of the third MmWaveEnb",
    ns3::UintegerValue(100), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_mmWaveDistance("mmWaveDist", "Distance between MmWave eNB 1 and 2",
    ns3::UintegerValue(200), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_numBuildingsBetweenMmWaveEnb("numBlocks", "Number of buildings between MmWave eNB 1 and 2",
    ns3::UintegerValue(15), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_bufferSize("bufferSize", "RLC tx buffer size (MB)",
    ns3::UintegerValue(1), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_x2Latency("x2Latency", "Latency on X2 interface (us)",
    ns3::DoubleValue(1000), ns3::MakeDoubleChecker<double>());
static ns3::GlobalValue g_mmeLatency("mmeLatency", "Latency on MME interface (us)",
    ns3::DoubleValue(10000), ns3::MakeDoubleChecker<double>());
static ns3::GlobalValue g_p2pDelay("p2pDelay", "Latency on the internet [ms]",
    ns3::UintegerValue(0), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_mobileUeSpeed("mobileSpeed", "The speed of the UE (m/s)",
    ns3::DoubleValue(5), ns3::MakeDoubleChecker<double>());
static ns3::GlobalValue g_fastSwitching("fastSwitching", "If true, use mc setup, else use hard handover",
    ns3::BooleanValue(true), ns3::MakeBooleanChecker());
static ns3::GlobalValue g_rlcAmEnabled("rlcAmEnabled", "If true, use RLC AM, else use RLC UM",
    ns3::BooleanValue(true), ns3::MakeBooleanChecker());
static ns3::GlobalValue g_runNumber ("runNumber", "Run number for rng",
    ns3::UintegerValue(4), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_maxXAxis("maxXAxis", "The maximum X coordinate for the area in which to deploy the buildings",
    ns3::DoubleValue(200), ns3::MakeDoubleChecker<double>());
static ns3::GlobalValue g_maxYAxis("maxYAxis", "The maximum Y coordinate for the area in which to deploy the buildings",
    ns3::DoubleValue(99), ns3::MakeDoubleChecker<double>());
static ns3::GlobalValue g_outPath("outPath",
    "The path of output log files",
    ns3::StringValue("./"), ns3::MakeStringChecker());
static ns3::GlobalValue g_handoverMode("handoverMode",
    "Handover mode",
    ns3::UintegerValue(3), ns3::MakeUintegerChecker<uint8_t>());
static ns3::GlobalValue g_reportTablePeriodicity("reportTablePeriodicity", "Periodicity of RTs",
    ns3::UintegerValue(1600), ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_udp("udp", "If true, use UDP. If false, TCP",
    ns3::BooleanValue(true), ns3::MakeBooleanChecker());
static ns3::GlobalValue g_lteUplink("lteUplink", "If true, use LTE for TCP ACKS. If false, mmWave",
    ns3::BooleanValue(false), ns3::MakeBooleanChecker());
static ns3::GlobalValue g_noMob("noMob", "If true, don't handover",
    ns3::BooleanValue(false), ns3::MakeBooleanChecker());
static ns3::GlobalValue g_outageThreshold("outageTh", "Outage threshold",
    ns3::DoubleValue(-5), ns3::MakeDoubleChecker<double>());


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
              //<< " height " << box.zMin << "," << box.zMax
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
PrintPosition(Ptr<Node> node)
{
  Ptr<MobilityModel> model = node->GetObject<MobilityModel> ();
  NS_LOG_UNCOND("Position +****************************** " << model->GetPosition() << " at time " << Simulator::Now().GetSeconds());
}

static void
CwndChange (Ptr<OutputStreamWrapper> stream, uint32_t oldCwnd, uint32_t newCwnd)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldCwnd << "\t" << newCwnd << std::endl;
}

static void
RttChange (Ptr<OutputStreamWrapper> stream, Time oldRtt, Time newRtt)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldRtt.GetSeconds () << "\t" << newRtt.GetSeconds () << std::endl;
}



static void Rx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet, const Address &from)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << packet->GetSize()<< std::endl;
}

/*static void Sstresh (Ptr<OutputStreamWrapper> stream, uint32_t oldSstresh, uint32_t newSstresh)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldSstresh << "\t" << newSstresh << std::endl;
}*/

void
ChangeSpeed(Ptr<Node>  n, Vector speed)
{
	n->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (speed);
}


static void
Traces(uint32_t serverId, uint32_t ueId, std::string pathVersion, std::string finalPart)
{
	AsciiTraceHelper asciiTraceHelper;

	std::ostringstream pathCW;
	pathCW<<"/NodeList/"<< serverId <<"/$ns3::TcpL4Protocol/SocketList/0/CongestionWindow";

	std::ostringstream fileCW;
	fileCW << pathVersion << "TCP-cwnd-change"  << ueId+1 << "_" << finalPart;

	std::ostringstream pathRTT;
	pathRTT << "/NodeList/"<< serverId <<"/$ns3::TcpL4Protocol/SocketList/0/RTT";

	std::ostringstream fileRTT;
	fileRTT << pathVersion << "TCP-rtt"  << ueId+1 << "_" << finalPart;

	std::ostringstream pathRCWnd;
	pathRCWnd<<"/NodeList/"<< serverId <<"/$ns3::TcpL4Protocol/SocketList/0/RWND";

	std::ostringstream fileRCWnd;
	fileRCWnd<<pathVersion << "TCP-rwnd-change"  << ueId+1 << "_" << finalPart;

	Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream (fileCW.str ().c_str ());
	Config::ConnectWithoutContext (pathCW.str ().c_str (), MakeBoundCallback(&CwndChange, stream1));

	Ptr<OutputStreamWrapper> stream2 = asciiTraceHelper.CreateFileStream (fileRTT.str ().c_str ());
	Config::ConnectWithoutContext (pathRTT.str ().c_str (), MakeBoundCallback(&RttChange, stream2));

	Ptr<OutputStreamWrapper> stream4 = asciiTraceHelper.CreateFileStream (fileRCWnd.str ().c_str ());
	Config::ConnectWithoutContext (pathRCWnd.str ().c_str (), MakeBoundCallback(&CwndChange, stream4));

}


bool
AreOverlapping(Box a, Box b)
{
  return !((a.xMin > b.xMax) || (b.xMin > a.xMax) || (a.yMin > b.yMax) || (b.yMin > a.yMax) );
}


bool
OverlapWithAnyPrevious(Box box, std::list<Box> m_previousBlocks)
{
  for (std::list<Box>::iterator it = m_previousBlocks.begin(); it != m_previousBlocks.end(); ++it)
  {
    if (AreOverlapping(*it,box))
    {
      return true;
    }
  }
  return false;
}


std::pair<Box, std::list<Box>>
GenerateBuildingBounds(double xMin, double xMax, double yMin, double yMax, double maxBuildSize, std::list<Box> m_previousBlocks )
{

  Ptr<UniformRandomVariable> xMinBuilding = CreateObject<UniformRandomVariable>();
  xMinBuilding->SetAttribute("Min",DoubleValue(xMin));
  xMinBuilding->SetAttribute("Max",DoubleValue(xMax-1)); // 1 m is the minimum size

  NS_LOG_UNCOND("min " << xMin << " max " << xMax);

  Ptr<UniformRandomVariable> yMinBuilding = CreateObject<UniformRandomVariable>();
  yMinBuilding->SetAttribute("Min",DoubleValue(yMin));
  yMinBuilding->SetAttribute("Max",DoubleValue(yMax-1)); // 1 m is the minimum size

  NS_LOG_UNCOND("min " << yMin << " max " << yMax);

  Box box;
  uint32_t attempt = 0;
  do
  {
    NS_ASSERT_MSG(attempt < 100, "Too many failed attempts to position non-overlapping buildings. Maybe area too small or too many buildings?");
    box.xMin = xMinBuilding->GetValue();

    Ptr<UniformRandomVariable> xMaxBuilding = CreateObject<UniformRandomVariable>();
    xMaxBuilding->SetAttribute("Min",DoubleValue(box.xMin + 1)); // 1 m is the minimum size
    xMaxBuilding->SetAttribute("Max",DoubleValue(box.xMin + maxBuildSize));
    box.xMax = xMaxBuilding->GetValue();
    
    box.yMin = yMinBuilding->GetValue();

    Ptr<UniformRandomVariable> yMaxBuilding = CreateObject<UniformRandomVariable>();
    yMaxBuilding->SetAttribute("Min",DoubleValue(box.yMin + 1)); // 1 m is the minimum size
    yMaxBuilding->SetAttribute("Max",DoubleValue(box.yMin + maxBuildSize));
    box.yMax = yMaxBuilding->GetValue();

    ++attempt;
  }
  while (OverlapWithAnyPrevious (box, m_previousBlocks));


  NS_LOG_UNCOND("Building in coordinates (" << box.xMin << " , " << box.yMin << ") and ("  << box.xMax << " , " << box.yMax <<
    ") accepted after " << attempt << " attempts");
  m_previousBlocks.push_back(box);
  std::pair<Box, std::list<Box>> pairReturn = std::make_pair(box,m_previousBlocks);
  return pairReturn;

}

int
main (int argc, char *argv[])
{

	// LogComponentEnable("LteEnbRrc", LOG_LEVEL_INFO);
  //LogComponentEnable("LteUeRrc", LOG_LEVEL_INFO);
  LogComponentEnable("LteRlcAm", LOG_LEVEL_INFO);
  LogComponentEnable("McUePdcp", LOG_LEVEL_INFO);
	//LogComponentEnable("TcpSocketBase", LOG_LEVEL_DEBUG);
  LogComponentEnable("McEnbPdcp", LOG_LEVEL_INFO);

	uint16_t numberOfNodes = 1;
	bool harqEnabled = true;
	bool fixedTti = false;

	// Command line arguments
	CommandLine cmd;
	cmd.Parse(argc, argv);

	UintegerValue uintegerValue;
	BooleanValue booleanValue;
	StringValue stringValue;
	DoubleValue doubleValue;
	//EnumValue enumValue;
	GlobalValue::GetValueByName("numBlocks", uintegerValue);
	uint32_t numBlocks = uintegerValue.Get();
	GlobalValue::GetValueByName("mmw1Dist", uintegerValue);
	uint32_t mmw1Dist = uintegerValue.Get();
	GlobalValue::GetValueByName("mmw2Dist", uintegerValue);
	uint32_t mmw2Dist = uintegerValue.Get();
	GlobalValue::GetValueByName("mmw3Dist", uintegerValue);
	uint32_t mmw3Dist = uintegerValue.Get();
	GlobalValue::GetValueByName("maxXAxis", doubleValue);
	double maxXAxis = doubleValue.Get();
	GlobalValue::GetValueByName("maxYAxis", doubleValue);
	double maxYAxis = doubleValue.Get();
	GlobalValue::GetValueByName("mmWaveDist", uintegerValue);
	uint32_t mmWaveDist = uintegerValue.Get();
	uint32_t mmWaveZ = 10;
	uint32_t streetWidth = 15;
	uint32_t minimumBuildingWidth = 10;

	// intial and final UE x coordinates
	double ueInitialPosition = 50;
  	double ueFinalPosition = 150;

  	GlobalValue::GetValueByName("fastSwitching", booleanValue);
	bool fastSwitching = booleanValue.Get();
	bool hardHandover = !fastSwitching;
  	GlobalValue::GetValueByName("noMob", booleanValue);
	bool noMob = booleanValue.Get();
	

	GlobalValue::GetValueByName("handoverMode", uintegerValue);
	uint8_t hoMode = uintegerValue.Get();
	GlobalValue::GetValueByName("udp", booleanValue);
	bool tcp = !(booleanValue.Get());
	GlobalValue::GetValueByName("outageTh", doubleValue);
	double outageTh = doubleValue.Get();
	GlobalValue::GetValueByName("reportTablePeriodicity", uintegerValue);
  	int ReportTablePeriodicity = (int)uintegerValue.Get(); // in microseconds

	GlobalValue::GetValueByName("rlcAmEnabled", booleanValue);
	bool rlcAmEnabled = booleanValue.Get();
	GlobalValue::GetValueByName("bufferSize", uintegerValue);
	uint32_t bufferSize = uintegerValue.Get();
	GlobalValue::GetValueByName("x2Latency", doubleValue);
	double x2Latency = doubleValue.Get();
	GlobalValue::GetValueByName("mmeLatency", doubleValue);
	double mmeLatency = doubleValue.Get();
	GlobalValue::GetValueByName("p2pDelay", uintegerValue);
	uint32_t p2pDelay = uintegerValue.Get();
	GlobalValue::GetValueByName("mobileSpeed", doubleValue);
	double ueSpeed = doubleValue.Get();
  GlobalValue::GetValueByName("lteUplink", booleanValue);
  bool lteUplink = booleanValue.Get();

	double simTime = ((double)ueFinalPosition - (double)ueInitialPosition)/ueSpeed + 1;

	NS_LOG_UNCOND("fastSwitching " << fastSwitching << " rlcAmEnabled " << rlcAmEnabled << " bufferSize " << bufferSize 
		<< " x2Latency " << x2Latency << " mmeLatency " << mmeLatency << " mobileSpeed " << ueSpeed << " tcp " << tcp);


	// rng things
	GlobalValue::GetValueByName("runNumber", uintegerValue);
	uint32_t runSet = uintegerValue.Get();
	uint32_t seedSet = 1;
	RngSeedManager::SetSeed (seedSet);
	RngSeedManager::SetRun (runSet); 
	char seedSetStr[21];
	char runSetStr[21];
	sprintf(seedSetStr, "%d", seedSet);
	sprintf(runSetStr, "%d", runSet);

	GlobalValue::GetValueByName("outPath", stringValue);
	std::string path = stringValue.Get();
	std::string mmWaveOutName = "MmWaveSwitchStats";
	std::string lteOutName = "LteSwitchStats";
	std::string dlRlcOutName = "DlRlcStats";
	std::string dlPdcpOutName = "DlPdcpStats";
	std::string ulRlcOutName = "UlRlcStats";
	std::string ulPdcpOutName = "UlPdcpStats";
	std::string  ueHandoverStartOutName =  "UeHandoverStartStats";
	std::string enbHandoverStartOutName = "EnbHandoverStartStats";
	std::string  ueHandoverEndOutName =  "UeHandoverEndStats";
	std::string enbHandoverEndOutName = "EnbHandoverEndStats";
	std::string cellIdInTimeOutName = "CellIdStats";
	std::string cellIdInTimeHandoverOutName = "CellIdStatsHandover";
	std::string mmWaveSinrOutputFilename = "MmWaveSinrTime";
	std::string x2statOutputFilename = "X2Stats";
	std::string udpSentFilename = "UdpSent";
	std::string udpReceivedFilename = "UdpReceived";
	std::string extension = ".txt";
	std::string version;
	if(fastSwitching)
	{
	version = "mc";
  if(lteUplink)
  {
    version = "lu";
  }

	}
	else if(hardHandover)
	{
	version = "hh";
	}

	if(noMob)
	{
		version="nb";
	}
	//get current time
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,80,"%d_%m_%Y_%I_%M_%S",timeinfo);
	std::string time_str(buffer);

	// settings for the channel
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::ChannelCondition", StringValue("a"));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Scenario", StringValue("UMi-StreetCanyon"));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::OptionalNlos", BooleanValue(true));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Shadowing", BooleanValue(true)); // enable or disable the shadowing effect
	Config::SetDefault ("ns3::MmWave3gppBuildingsPropagationLossModel::UpdateCondition", BooleanValue(true)); // enable or disable the LOS/NLOS update when the UE moves
	Config::SetDefault ("ns3::AntennaArrayModel::AntennaHorizontalSpacing", DoubleValue(0.5));
	Config::SetDefault ("ns3::AntennaArrayModel::AntennaVerticalSpacing", DoubleValue(0.5));
	Config::SetDefault ("ns3::MmWave3gppChannel::UpdatePeriod", TimeValue(MilliSeconds(50))); // interval after which the channel for a moving user is updated, 
	                                                                                   // with spatial consistency procedure. If 0, spatial consistency is not used
	Config::SetDefault ("ns3::MmWave3gppChannel::CellScan", BooleanValue(false)); // Set true to use cell scanning method, false to use the default power method.
	Config::SetDefault ("ns3::MmWave3gppChannel::Blockage", BooleanValue(true)); // use blockage or not
	Config::SetDefault ("ns3::MmWave3gppChannel::PortraitMode", BooleanValue(true)); // use blockage model with UT in portrait mode
	Config::SetDefault ("ns3::MmWave3gppChannel::NumNonselfBlocking", IntegerValue(4)); // number of non-self blocking obstacles

	// RLC PHY and MAC
	Config::SetDefault ("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue(rlcAmEnabled));
	Config::SetDefault ("ns3::MmWaveHelper::HarqEnabled", BooleanValue(harqEnabled));
	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(harqEnabled));
	Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::HarqEnabled", BooleanValue(harqEnabled));
	Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::FixedTti", BooleanValue(fixedTti));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::TbDecodeLatency", UintegerValue(200.0));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::NumHarqProcess", UintegerValue(100));
	Config::SetDefault ("ns3::LteEnbRrc::SystemInformationPeriodicity", TimeValue (MilliSeconds (5.0)));
	Config::SetDefault ("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MicroSeconds(100.0)));
	Config::SetDefault ("ns3::LteRlcUmLowLat::ReportBufferStatusTimer", TimeValue(MicroSeconds(100.0)));
	Config::SetDefault ("ns3::LteEnbRrc::SrsPeriodicity", UintegerValue (320));
	Config::SetDefault ("ns3::LteEnbRrc::FirstSibTime", UintegerValue (2));
	Config::SetDefault ("ns3::LteRlcUm::MaxTxBufferSize", UintegerValue (bufferSize * 1024 * 1024));
	Config::SetDefault ("ns3::LteRlcUmLowLat::MaxTxBufferSize", UintegerValue (bufferSize * 1024 * 1024));
	//Config::SetDefault ("ns3::LteRlcAm::StatusProhibitTimer", TimeValue(MilliSeconds(10.0)));
	Config::SetDefault ("ns3::LteRlcAm::EnableAQM", BooleanValue(false));

  Config::SetDefault ("ns3::LteRlcAm::PollRetransmitTimer", TimeValue(MilliSeconds(2.0)));
  Config::SetDefault ("ns3::LteRlcAm::ReorderingTimer", TimeValue(MilliSeconds(1.0)));
  Config::SetDefault ("ns3::LteRlcAm::StatusProhibitTimer", TimeValue(MilliSeconds(1.0)));
  Config::SetDefault ("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MilliSeconds(2.0)));

	// handover and RT related params
	switch(hoMode)
	{
	case 1:
	    Config::SetDefault ("ns3::LteEnbRrc::SecondaryCellHandoverMode", EnumValue(LteEnbRrc::THRESHOLD));
	    break;
	case 2:
	    Config::SetDefault ("ns3::LteEnbRrc::SecondaryCellHandoverMode", EnumValue(LteEnbRrc::FIXED_TTT));
	    break;
	case 3:
	    Config::SetDefault ("ns3::LteEnbRrc::SecondaryCellHandoverMode", EnumValue(LteEnbRrc::DYNAMIC_TTT));
	    break;
	}

if(!noMob)
{
	Config::SetDefault ("ns3::LteEnbRrc::FixedTttValue", UintegerValue (150));
	Config::SetDefault ("ns3::LteEnbRrc::CrtPeriod", IntegerValue (ReportTablePeriodicity));
	Config::SetDefault ("ns3::LteEnbRrc::OutageThreshold", DoubleValue (outageTh));
	Config::SetDefault ("ns3::MmWaveEnbPhy::UpdateSinrEstimatePeriod", IntegerValue (ReportTablePeriodicity));
}
else
{
		    Config::SetDefault ("ns3::LteEnbRrc::SecondaryCellHandoverMode", EnumValue(LteEnbRrc::THRESHOLD));
	Config::SetDefault ("ns3::LteEnbRrc::HoSinrDifference", DoubleValue (100000));


Config::SetDefault ("ns3::LteEnbRrc::FixedTttValue", UintegerValue (150));
	Config::SetDefault ("ns3::LteEnbRrc::CrtPeriod", IntegerValue (ReportTablePeriodicity));
	Config::SetDefault ("ns3::LteEnbRrc::OutageThreshold", DoubleValue (-10000));
	Config::SetDefault ("ns3::MmWaveEnbPhy::UpdateSinrEstimatePeriod", IntegerValue (ReportTablePeriodicity));	
}


	// core network
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkDelay", TimeValue (MicroSeconds(x2Latency)));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkDataRate", DataRateValue(DataRate ("1000Gb/s")));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkMtu",  UintegerValue(10000));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::S1uLinkDelay", TimeValue (MicroSeconds(1000)));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::S1apLinkDelay", TimeValue (MicroSeconds(mmeLatency)));

	// names
	Config::SetDefault ("ns3::McStatsCalculator::MmWaveOutputFilename", StringValue                 (path + version + mmWaveOutName + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::McStatsCalculator::LteOutputFilename", StringValue                    (path + version + lteOutName    + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::McStatsCalculator::CellIdInTimeOutputFilename", StringValue           (path + version + cellIdInTimeOutName    + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsCalculator::DlRlcOutputFilename", StringValue        (path + version + dlRlcOutName   + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsCalculator::UlRlcOutputFilename", StringValue        (path + version + ulRlcOutName   + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsCalculator::DlPdcpOutputFilename", StringValue       (path + version + dlPdcpOutName + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsCalculator::UlPdcpOutputFilename", StringValue       (path + version + ulPdcpOutName + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsConnector::UeHandoverStartOutputFilename", StringValue    (path + version +  ueHandoverStartOutName + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsConnector::EnbHandoverStartOutputFilename", StringValue   (path + version + enbHandoverStartOutName + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsConnector::UeHandoverEndOutputFilename", StringValue    (path + version +  ueHandoverEndOutName + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsConnector::EnbHandoverEndOutputFilename", StringValue   (path + version + enbHandoverEndOutName + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsConnector::CellIdStatsHandoverOutputFilename", StringValue(path + version + cellIdInTimeHandoverOutName + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::MmWaveBearerStatsConnector::MmWaveSinrOutputFilename", StringValue(path + version + mmWaveSinrOutputFilename + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::CoreNetworkStatsCalculator::X2FileName", StringValue                  (path + version + x2statOutputFilename    + "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	std::string lostFilename = path + version + "LostUdpPackets" +  "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension;
	//Config::SetDefault ("ns3::MmWaveHelper::ChannelModel", StringValue("ns3::MmWaveChannelMatrix"))
	//Config::SetDefault ("ns3::UdpServer::ReceivedPacketsFilename", StringValue(path + version + "ReceivedUdp" +  "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	//Config::SetDefault ("ns3::UdpClient::SentPacketsFilename", StringValue(path + version + "SentUdp" +  "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	//Config::SetDefault ("ns3::UdpServer::ReceivedSnFilename", StringValue(path + version + "ReceivedSn" +  "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));
	Config::SetDefault ("ns3::LteRlcAm::BufferSizeFilename", StringValue(path + version + "RlcAmBufferSize" +  "_" + seedSetStr + "_" + runSetStr + "_" + time_str + extension));

	// TCP settings
	Config::SetDefault ("ns3::TcpSocketBase::MinRto", TimeValue (MilliSeconds (200)));
	Config::SetDefault ("ns3::Ipv4L3Protocol::FragmentExpirationTimeout", TimeValue (Seconds (0.2)));
	Config::SetDefault ("ns3::TcpSocket::SegmentSize", UintegerValue (1400));
	Config::SetDefault ("ns3::TcpSocket::DelAckCount", UintegerValue (1));
	Config::SetDefault ("ns3::TcpSocket::SndBufSize", UintegerValue (131072*400));
	Config::SetDefault ("ns3::TcpSocket::RcvBufSize", UintegerValue (131072*400));
	
	std::string protocol = "TcpHighSpeed";
	if(protocol == "TcpNewReno")
    {
		Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpNewReno::GetTypeId ()));
    }
    else if (protocol == "TcpVegas")
    {
    	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpVegas::GetTypeId ()));
    }
    else if (protocol == "TcpLedbat")
    {
    	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpLedbat::GetTypeId ()));

    }
    else if (protocol == "TcpHighSpeed")
    {
    	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpHighSpeed::GetTypeId ()));

    }
    // else if (protocol == "TcpCubic")
    // {
    // 	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpCubic::GetTypeId ()));

    // }
    else if (protocol == "TcpIllinois")
    {
    	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpIllinois::GetTypeId ()));

    }
    else if (protocol == "TcpHybla")
    {
    	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpHybla::GetTypeId ()));

    }
    else if (protocol == "TcpVeno")
    {
    	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpVeno::GetTypeId ()));

    }
    else if (protocol == "TcpWestwood")
    {
    	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpWestwood::GetTypeId ()));

    }
    else if (protocol == "TcpYeah")
    {
    	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpYeah::GetTypeId ()));

    }
    else
    {
		std::cout<<protocol<<" Unkown protocol.\n";
		return 1;
    }

	Config::SetDefault ("ns3::TcpVegas::Alpha", UintegerValue (20));
	Config::SetDefault ("ns3::TcpVegas::Beta", UintegerValue (40));
	Config::SetDefault ("ns3::TcpVegas::Gamma", UintegerValue (2));

  if(lteUplink)
  {
    Config::SetDefault("ns3::McUePdcp::LteUplink", BooleanValue(true));
  }


	// CoDel queue settings
	Config::SetDefault ("ns3::CoDelQueueDisc::Mode", EnumValue (ns3::CoDelQueueDisc::QueueDiscMode::QUEUE_DISC_MODE_PACKETS));
	Config::SetDefault ("ns3::CoDelQueueDisc::MaxPackets", UintegerValue (50000));
	
	Ptr<MmWaveHelper> mmwaveHelper = CreateObject<MmWaveHelper> (); 
	if(true)
	{
	mmwaveHelper->SetAttribute ("PathlossModel", StringValue ("ns3::MmWave3gppBuildingsPropagationLossModel"));
	}
	else
	{
	mmwaveHelper->SetAttribute ("PathlossModel", StringValue ("ns3::MmWave3gppPropagationLossModel"));
	}
	mmwaveHelper->SetAttribute ("ChannelModel", StringValue ("ns3::MmWave3gppChannel"));

	Ptr<MmWavePointToPointEpcHelper> epcHelper = CreateObject<MmWavePointToPointEpcHelper> ();
	mmwaveHelper->SetEpcHelper (epcHelper);
	mmwaveHelper->SetHarqEnabled (harqEnabled);
	mmwaveHelper->Initialize();

	// Create the Internet by connecting remoteHost to pgw. Setup routing too
	Ptr<Node> pgw = epcHelper->GetPgwNode ();

	// Create numberOfNodes remotehosts
	NodeContainer remoteHostContainer;
	remoteHostContainer.Create (numberOfNodes);
	InternetStackHelper internet;
	internet.Install (remoteHostContainer);
	Ipv4StaticRoutingHelper ipv4RoutingHelper;
	Ipv4InterfaceContainer internetIpIfaces;
	for (uint16_t i = 0; i < numberOfNodes; i++)
	{
		Ptr<Node> remoteHost = remoteHostContainer.Get (i);
		// Create the Internet
		PointToPointHelper p2ph;
		p2ph.SetDeviceAttribute ("DataRate", DataRateValue (DataRate ("100Gb/s")));
		p2ph.SetDeviceAttribute ("Mtu", UintegerValue (1500));
		p2ph.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (p2pDelay)));

		NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);

		Ipv4AddressHelper ipv4h;
	    std::ostringstream subnet;
	    subnet<<i<<".1.0.0";
		ipv4h.SetBase (subnet.str ().c_str (), "255.255.0.0");
		internetIpIfaces = ipv4h.Assign (internetDevices);
		// interface 0 is localhost, 1 is the p2p device
		Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
		remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.255.0.0"), 1);
	}

	// create LTE, mmWave eNB nodes and UE node
	NodeContainer ueNodes;
	NodeContainer mmWaveEnbNodes;
	NodeContainer lteEnbNodes;
	NodeContainer allEnbNodes;
	mmWaveEnbNodes.Create(3);
	lteEnbNodes.Create(1);
	ueNodes.Create(numberOfNodes);
	allEnbNodes.Add(lteEnbNodes);
	allEnbNodes.Add(mmWaveEnbNodes);

	// Positions
	Vector mmw1Position = Vector(-1, mmw1Dist, mmWaveZ);
	//Vector mmw2Position = Vector(5.0 + 200, mmw2Dist, mmWaveZ); // --------------------> change
	Vector mmw2Position = Vector(1 + mmWaveDist, mmw2Dist, mmWaveZ); 
	Vector mmw3Position = Vector(double(mmWaveDist)/2, mmw3Dist, mmWaveZ);

	double blockSize = (double)mmWaveDist/4;
	uint32_t roundedBlockSize = std::floor(blockSize);
	NS_ASSERT_MSG(roundedBlockSize > streetWidth + minimumBuildingWidth, "Too many blocks");
	uint32_t buildingWidth = roundedBlockSize - streetWidth;

	std::vector<Ptr<Building> > buildingVector;
	std::list<Box>  m_previousBlocks;

	double maxObstacleSize = buildingWidth;

	for(uint32_t buildingIndex = 0; buildingIndex < numBlocks; buildingIndex++)
	{
		Ptr < Building > building;
		building = Create<Building> ();
		/* returns a vecotr where:
		* position [0]: coordinates for x min
		* position [1]: coordinates for x max
		* position [2]: coordinates for y min
		* position [3]: coordinates for y max
		*/
		std::pair<Box, std::list<Box>> pairBuildings = GenerateBuildingBounds(0, maxXAxis, 0, maxYAxis, maxObstacleSize, m_previousBlocks);
		m_previousBlocks = std::get<1>(pairBuildings);
		Box box = std::get<0>(pairBuildings);
		Ptr<UniformRandomVariable> randomBuildingZ = CreateObject<UniformRandomVariable>();
		randomBuildingZ->SetAttribute("Min",DoubleValue(1.6));
		randomBuildingZ->SetAttribute("Max",DoubleValue(50));
		double buildingHeight = randomBuildingZ->GetValue();

		building->SetBoundaries (Box(box.xMin, box.xMax,
		                              box.yMin,  box.yMax,
		                              0.0, buildingHeight));
		building->SetNRoomsX(1);
		building->SetNRoomsY(1);
		building->SetNFloors(1);
		buildingVector.push_back(building);
	}

	// Install Mobility Model
	Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
	//enbPositionAlloc->Add (Vector ((double)mmWaveDist/2 + streetWidth, mmw1Dist + 2*streetWidth, mmWaveZ));
	enbPositionAlloc->Add (mmw3Position); // LTE BS, out of area where buildings are deployed
	enbPositionAlloc->Add (mmw1Position);
	enbPositionAlloc->Add (mmw2Position);
	enbPositionAlloc->Add (mmw3Position);
	MobilityHelper enbmobility;
	enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	enbmobility.SetPositionAllocator(enbPositionAlloc);
	enbmobility.Install (allEnbNodes);
	BuildingsHelper::Install (allEnbNodes);

	double ueZ = 1.6;

	MobilityHelper uemobility;
	Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
	uePositionAlloc->Add (Vector (ueInitialPosition, -1, ueZ));
	uemobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
	uemobility.SetPositionAllocator(uePositionAlloc);
	uemobility.Install (ueNodes);
	BuildingsHelper::Install (ueNodes);

	ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (ueInitialPosition, -1, ueZ));
	ueNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (0, 0, 0));

	// Install mmWave, lte, mc Devices to the nodes
	NetDeviceContainer lteEnbDevs = mmwaveHelper->InstallLteEnbDevice (lteEnbNodes);
	NetDeviceContainer mmWaveEnbDevs = mmwaveHelper->InstallEnbDevice (mmWaveEnbNodes);
	NetDeviceContainer mcUeDevs;
	if(fastSwitching)
	{
		mcUeDevs = mmwaveHelper->InstallMcUeDevice (ueNodes);
	} 
	else if(hardHandover)
	{
		mcUeDevs = mmwaveHelper->InstallInterRatHoCapableUeDevice (ueNodes);
	}
	else
	{
		NS_FATAL_ERROR("Invalid option");
	}

	// Install the IP stack on the UEs
	internet.Install (ueNodes);
	Ipv4InterfaceContainer ueIpIface;
	ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (mcUeDevs));

	// Add X2 interfaces
	mmwaveHelper->AddX2Interface (lteEnbNodes, mmWaveEnbNodes);

	// Manual attachment
	if(fastSwitching)
	{
		mmwaveHelper->AttachToClosestEnb (mcUeDevs, mmWaveEnbDevs, lteEnbDevs);  
	}
	else if(hardHandover)
	{
		mmwaveHelper->AttachIrToClosestEnb (mcUeDevs, mmWaveEnbDevs, lteEnbDevs);
	}

	ApplicationContainer sourceApps;
	ApplicationContainer sinkApps;
	uint16_t sinkPort = 20000;

	for (uint16_t i = 0; i < ueNodes.GetN (); i++)
	{
		// Set the default gateway for the UE
		Ptr<Node> ueNode = ueNodes.Get (i);
		Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (ueNode->GetObject<Ipv4> ());
		ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);

		// Install and start applications on UEs and remote host
		PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), sinkPort));
		sinkApps.Add (packetSinkHelper.Install (ueNodes.Get (i)));

		BulkSendHelper ftp ("ns3::TcpSocketFactory",
		                         InetSocketAddress (ueIpIface.GetAddress (i), sinkPort));
		sourceApps.Add (ftp.Install (remoteHostContainer.Get (i)));

		uint32_t serverId = remoteHostContainer.Get (i)->GetId();
		uint32_t ueId = ueNodes.Get(i)->GetId();

		NS_LOG_UNCOND("ueId " << ueId << " serverId " << serverId);

	    std::ostringstream fileName;
	    fileName << path << version << "TCP-rx-data"  << ueId+1 << "_" << seedSetStr << "_" << runSetStr << "_" << time_str << extension;

		AsciiTraceHelper asciiTraceHelper;

		Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (fileName.str ().c_str ());
		sinkApps.Get(i)->TraceConnectWithoutContext("Rx", MakeBoundCallback (&Rx, stream));
	    sourceApps.Get(i)->SetStartTime(Seconds (0.1+0.01*i));
	    Simulator::Schedule (Seconds (0.1001+0.01*i), &Traces, serverId, ueId, 
	    	path + version, seedSetStr + std::string("_") + runSetStr + "_" + time_str + extension);
	    //sourceApps.Get(i)->SetStopTime (Seconds (10-1.5*i));
	    sourceApps.Get(i)->SetStopTime (Seconds (simTime - 1));

		sinkPort++;

	}

	sinkApps.Start (Seconds (0.));
	sinkApps.Stop (Seconds (simTime));

	Simulator::Schedule(Seconds(0.1), &ChangeSpeed, ueNodes.Get(0), Vector(ueSpeed, 0, 0)); // start UE movement after Seconds(0.5)
	Simulator::Schedule(Seconds(simTime - 1), &ChangeSpeed, ueNodes.Get(0), Vector(0, 0, 0)); // start UE movement after Seconds(0.5)
	//Simulator::Schedule(Seconds(transientDuration), &ChangeSpeed, ueNodes.Get(1), Vector(0, ueSpeed, 0)); // start UE movement after Seconds(0.5)
	//Simulator::Schedule(Seconds(simTime - 1), &ChangeSpeed, ueNodes.Get(1), Vector(0, 0, 0)); // start UE movement after Seconds(0.5)

	double numPrints = 0;
	for(int i = 0; i < numPrints; i++)
	{
		Simulator::Schedule(Seconds(i*simTime/numPrints), &PrintPosition, ueNodes.Get(0)); 
	}

	// Uncomment to enable PCAP tracing
	// p2ph.EnablePcapAll("mmwave-epc-simple");
	BuildingsHelper::MakeMobilityModelConsistent ();

	// Ptr<LteHelper> lteHelper = CreateObject<LteHelper>();
	// lteHelper->EnablePdcpTraces();
	// lteHelper->EnableRlcTraces();
	mmwaveHelper->EnableTraces ();

	
	// print buildings and UEs positions
	std::ostringstream fileName;
	fileName << path << seedSetStr << "_" << runSetStr << "_" << time_str + "buildings" << extension;
	PrintGnuplottableBuildingListToFile(fileName.str());// fileName.str ());
	fileName.str("");
	fileName.clear();
	fileName << path << seedSetStr << "_" << runSetStr << "_" << time_str + "enbs" << extension;
	PrintGnuplottableEnbListToFile(fileName.str());
	fileName.str("");
	fileName.clear();
	fileName << path << seedSetStr << "_" << runSetStr << "_" << time_str + "ues" << extension;
	//std::ostringstream ueFileName;
	//  ueFileName<<protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay)<<"-"<<std::to_string(runSet)<<"-ues.txt";
	PrintGnuplottableUeListToFile(fileName.str());

	Simulator::Stop(Seconds(simTime));
	Simulator::Run();    
	
	Simulator::Destroy();
	return 0;
}