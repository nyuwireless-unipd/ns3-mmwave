/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2015 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *
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
 * Author: Danilo Abrignani <danilo.abrignani@unibo.it>
 */


#include "ns3/core-module.h"
#include "ns3/config-store.h"
#include "ns3/component-carrier.h"
#include "ns3/cc-helper.h"
#include "ns3/mmwave-helper.h"
#include "ns3/mobility-module.h"
#include "ns3/global-route-manager.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/log.h"
#include "ns3/mmwave-point-to-point-epc-helper.h"
#include "ns3/lte-ue-net-device.h"
#include "ns3/mmwave-ue-net-device.h"
#include "ns3/mc-ue-net-device.h"
#include <ns3/buildings-helper.h>
#include <ns3/buildings-module.h>
#include "ns3/network-module.h"


using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("MyMcExample");

int packetSinkDlRxCounter = 0;
int packetSinkUlRxCounter = 0;
int numOfTxPackets = 0;

void
DlSchedTrace (Ptr<OutputStreamWrapper> stream, DlSchedulingCallbackInfo params)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << (uint32_t)params.componentCarrierId << '\t' << params.sizeTb1 << std::endl;
}

static void
DlRx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet, const Address &from)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << packet->GetSize()<< std::endl;
	packetSinkDlRxCounter++;
}

static void
UlRx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet, const Address &from)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << packet->GetSize()<< std::endl;
	packetSinkUlRxCounter++;
}

void
TxMacPacketTrace (Ptr<OutputStreamWrapper> stream, uint16_t rnti, uint8_t componentCarrierId, uint32_t size)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t"
												<< (uint32_t)rnti << '\t'
												<< (uint32_t)componentCarrierId << '\t'
												<< size
												<< std::endl;
}

void
PositionTrace(Ptr<Node> n)
{
	Vector pos = n->GetObject<MobilityModel>()->GetPosition();
	std::cout << "UE position at " << Simulator::Now().GetSeconds() << "\t" << pos << std::endl;
	Simulator::Schedule (Seconds(1), &PositionTrace, n);
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

	outFile << "set xrange [-200:200]" << std::endl;
	outFile << "set yrange [-200:200]" << std::endl;
	outFile << "unset key" << std::endl;
	outFile << "set grid" << std::endl;

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
PrintGnuplottableEnbListToFile (std::string filename)
{
  std::ofstream outFile;
  outFile.open (filename.c_str (), std::ios_base::out | std::ios_base::app);
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
                      << " left font \"Helvetica,8\" textcolor rgb \"blue\" front  point pt 7 ps 0.5 lc rgb \"blue\" offset 0,0"
                      << std::endl;
            }
          else if (mmdev)
            {
              Vector pos = node->GetObject<MobilityModel> ()->GetPosition ();
              outFile << "set label \"" << mmdev->GetCellId ()
                      << "\" at "<< pos.x << "," << pos.y
                      << " left font \"Helvetica,8\" textcolor rgb \"red\" front  point pt 7 ps 0.5 lc rgb \"red\" offset 0,0"
                      << std::endl;
            }
        }
    }
}

void
PrintGnuplottableUeListToFile (std::string filename)
{
  std::ofstream outFile;
  outFile.open (filename.c_str (), std::ios_base::out | std::ios_base::app);
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
Traces(std::string outPath)
{
	//std::string path = "/NodeList/*/DeviceList/*/ComponentCarrierMap/*/LteEnbMac/DlScheduling";
	/*std::string filePath = "DlSchedTrace.txt";
	AsciiTraceHelper asciiTraceHelper;
	Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (filePath);
	*stream->GetStream () << "Time" << "\t" << "CC" << '\t' << "sizeTb1" << std::endl;
	Config::ConnectWithoutContext (path, MakeBoundCallback(&DlSchedTrace, stream));*/

	std::string dlTxMacPath = "/NodeList/*/DeviceList/*/ComponentCarrierMap/*/MmWaveEnbMac/TxMacPacketTraceEnb";
	std::string dlTxMacFilePath = outPath + "/DlTxMac.txt";
	AsciiTraceHelper dlTxMacAsciiTraceHelper;
	Ptr<OutputStreamWrapper> dlTxMacStream = dlTxMacAsciiTraceHelper.CreateFileStream (dlTxMacFilePath);
	//*stream->GetStream () << "Time" << "\t" << "CC" << '\t' << "sizeTb1" << std::endl;
	Config::ConnectWithoutContext (dlTxMacPath, MakeBoundCallback(&TxMacPacketTrace, dlTxMacStream));

	std::string ulTxMacPath = "/NodeList/*/DeviceList/*/MmWaveComponentCarrierMapUe/*/MmWaveUeMac/TxMacPacketTraceUe";
	std::string ulTxMacFilePath = outPath + "UlTxMac.txt";
	AsciiTraceHelper ulTxMacAsciiTraceHelper;
	Ptr<OutputStreamWrapper> ulTxMacStream = ulTxMacAsciiTraceHelper.CreateFileStream (ulTxMacFilePath);
	//*stream->GetStream () << "Time" << "\t" << "CC" << '\t' << "sizeTb1" << std::endl;
	Config::ConnectWithoutContext (ulTxMacPath, MakeBoundCallback(&TxMacPacketTrace, ulTxMacStream));


}

void
LossRateTrace (std::string outPath)
{
	std::string lossRateFilePath = outPath + "/LossRate.txt";
	AsciiTraceHelper lossRateAsciiTraceHelper;
	Ptr<OutputStreamWrapper> lossRateStream = lossRateAsciiTraceHelper.CreateFileStream (lossRateFilePath);

	double dlLossRate = 1-std::min(numOfTxPackets, packetSinkDlRxCounter)/(double)numOfTxPackets;
	double ulLossRate = 1-std::min(numOfTxPackets, packetSinkUlRxCounter)/(double)numOfTxPackets;
	*lossRateStream->GetStream () << dlLossRate << "\t" << ulLossRate << std::endl;
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


int main (int argc, char *argv[])
{
	bool useRR = false;
	double mmWaveCc0Freq = 28e9;
	double mmWaveCc1Freq = 73e9;
	double mmWaveCc0Bw = 1; // in GHz
	double mmWaveCc1Bw = 1; // in GHz
	double simTime = 0;
	std::string filePath;
	int runSet = 1;
	double speed = 3.0;
	bool reportAllUeMeas = false;
	bool useOneMmWaveCc = false;
	double interPacketInterval = 1000;
	bool useRlcUm = false;
	uint8_t hoMode = 3;
	double bsrTimer = 2.0;
	double reorderingTimer = 1.0;
	bool useHarq = true;
	bool sendBsrWhenPacketTx = true;
	bool useBuilding = true;

	CommandLine cmd;
  cmd.AddValue("useRR", "If true use MmWaveRrComponentCarrierManager, else use MmWaveBaRrComponentCarrierManager", useRR);
  cmd.AddValue("mmWaveCc0Freq", "CC0 central frequency [Hz]", mmWaveCc0Freq);
	cmd.AddValue("mmWaveCc1Freq", "CC1 central frequency [Hz]", mmWaveCc1Freq);
	cmd.AddValue("mmWaveCc0Bw", "CC0 bandwidth (in GHz)", mmWaveCc0Bw);
	cmd.AddValue("mmWaveCc1Bw", "CC1 bandwidth (in GHz)", mmWaveCc1Bw);
  cmd.AddValue("simTime", "Simulation time", simTime);
  cmd.AddValue("filePath", "Where to put the output files", filePath);
  cmd.AddValue("runSet", "Run number", runSet);
	cmd.AddValue("speed", "Speed in the x direction [m/s]",speed);
	cmd.AddValue("reportAllUeMeas", "Report the measures from all the CCs or only the max values", reportAllUeMeas);
	cmd.AddValue("useOneMmWaveCc", "Use one CC for mmWave", useOneMmWaveCc);
	cmd.AddValue("interPacketInterval", "inter-packet interval [us]", interPacketInterval);
	cmd.AddValue("useRlcUm", "Use rlc um", useRlcUm);
	cmd.AddValue("hoMode", "1.Threshold, 2.FixedTtt, 3.DynamicTtt", hoMode);
	cmd.AddValue("bsrTimer", "BSR timer [ms]", bsrTimer);
	cmd.AddValue("reorderingTimer", "reordering timer [ms]", reorderingTimer);
	cmd.AddValue("useHarq", "use HARQ", useHarq);
	cmd.AddValue("sendBsrWhenPacketTx", "send BSR at each tx (LteRlcUmLowLat)", sendBsrWhenPacketTx);
	cmd.AddValue("useBuilding", "use the building module", useBuilding);
  cmd.Parse (argc, argv);

	// RNG
  uint32_t seedSet = 1;
  RngSeedManager::SetSeed (seedSet);
  RngSeedManager::SetRun (runSet);

	// Set the correct file path
	std::cout << "File path: " << filePath << std::endl;
  Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlRlcOutputFilename", StringValue(filePath + "DlRlcStats.txt"));
  Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlRlcOutputFilename", StringValue(filePath + "UlRlcStats.txt"));
  Config::SetDefault("ns3::MmWaveBearerStatsCalculator::DlPdcpOutputFilename", StringValue(filePath + "DlPdcpStats.txt"));
  Config::SetDefault("ns3::MmWaveBearerStatsCalculator::UlPdcpOutputFilename", StringValue(filePath + "UlPdcpStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::EnbHandoverStartOutputFilename", StringValue(filePath + "EnbHandoverStartStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::EnbHandoverEndOutputFilename", StringValue(filePath + "EnbHandoverEndStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::MmWaveSinrOutputFilename", StringValue(filePath + "MmWaveSinrTime.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::LteSinrOutputFilename", StringValue(filePath + "LteSinrTime.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::UeHandoverStartOutputFilename", StringValue(filePath + "UeHandoverStartStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::UeHandoverEndOutputFilename", StringValue(filePath + "UeHandoverEndStats.txt"));
	Config::SetDefault("ns3::MmWaveBearerStatsConnector::CellIdStatsHandoverOutputFilename", StringValue(filePath + "CellIdStatsHandover.txt"));
  Config::SetDefault("ns3::MmWavePhyRxTrace::OutputFilename", StringValue(filePath + "RxPacketTrace.txt"));
  Config::SetDefault("ns3::LteRlcAm::BufferSizeFilename", StringValue(filePath + "RlcAmBufferSize.txt"));
	Config::SetDefault("ns3::McStatsCalculator::LteOutputFilename", StringValue(filePath + "LteSwitchStats.txt"));
	Config::SetDefault("ns3::McStatsCalculator::MmWaveOutputFilename", StringValue(filePath + "MmWaveSwitchStats.txt"));
	Config::SetDefault("ns3::McStatsCalculator::CellIdInTimeOutputFilename", StringValue(filePath + "CellIdStats.txt"));
	Config::SetDefault("ns3::CoreNetworkStatsCalculator::X2FileName", StringValue(filePath + "X2Stats.txt"));
	Config::SetDefault("ns3::CoreNetworkStatsCalculator::S1MmeFileName", StringValue(filePath + "MmeStats.txt"));

	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(useHarq));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::TbDecodeLatency", UintegerValue(200.0));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::NumHarqProcess", UintegerValue(100));

	Config::SetDefault("ns3::LteEnbRrc::ReportAllUeMeas",BooleanValue(reportAllUeMeas));
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
	Config::SetDefault ("ns3::LteEnbRrc::FixedTttValue", UintegerValue (150));

	Config::SetDefault ("ns3::LteRlcAm::EnableAQM", BooleanValue(false));
	Config::SetDefault ("ns3::LteRlcAm::PollRetransmitTimer", TimeValue(MilliSeconds(2.0)));
	Config::SetDefault ("ns3::LteRlcAm::ReorderingTimer", TimeValue(MilliSeconds(reorderingTimer)));
	Config::SetDefault ("ns3::LteRlcAm::StatusProhibitTimer", TimeValue(MilliSeconds(1.0)));
	Config::SetDefault ("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MilliSeconds(bsrTimer)));
	Config::SetDefault ("ns3::LteRlcUm::ReorderingTimer", TimeValue(MilliSeconds(reorderingTimer)));
	Config::SetDefault ("ns3::LteRlcUm::ReportBufferStatusTimer", TimeValue(MilliSeconds(bsrTimer)));
	Config::SetDefault ("ns3::LteRlcUmLowLat::SendBsrWhenPacketTx", BooleanValue(sendBsrWhenPacketTx));


	//The available channel scenarios are 'RMa', 'UMa', 'UMi-StreetCanyon', 'InH-OfficeMixed', 'InH-OfficeOpen', 'InH-ShoppingMall'
  std::string scenario = "UMa";
  std::string condition = "n"; // n = NLOS, l = LOS
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::ChannelCondition", StringValue(condition));
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Scenario", StringValue(scenario));
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::OptionalNlos", BooleanValue(false));
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Shadowing", BooleanValue(false)); // enable or disable the shadowing effect
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::InCar", BooleanValue(false)); // enable or disable the shadowing effect

	Config::SetDefault ("ns3::MmWave3gppBuildingsPropagationLossModel::UpdateCondition", BooleanValue(true)); // enable or disable the LOS/NLOS update when the UE moves


  Config::SetDefault ("ns3::MmWave3gppChannel::UpdatePeriod", TimeValue (MilliSeconds (100))); // Set channel update period, 0 stands for no update.
  Config::SetDefault ("ns3::MmWave3gppChannel::CellScan", BooleanValue(false)); // Set true to use cell scanning method, false to use the default power method.
  Config::SetDefault ("ns3::MmWave3gppChannel::PortraitMode", BooleanValue(true)); // use blockage model with UT in portrait mode
  Config::SetDefault ("ns3::MmWave3gppChannel::NumNonselfBlocking", IntegerValue(4)); // number of non-self blocking obstacles
  Config::SetDefault ("ns3::MmWave3gppChannel::BlockerSpeed", DoubleValue(1)); // speed of non-self blocking obstacles

	// core network
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkDelay", TimeValue (MilliSeconds(1)));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkDataRate", DataRateValue(DataRate ("1000Gb/s")));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::X2LinkMtu",  UintegerValue(10000));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::S1uLinkDelay", TimeValue (MicroSeconds(1000)));
	Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::S1apLinkDelay", TimeValue (MilliSeconds(10))); // MME latency

  // create the map of LTE component carriers
  Ptr<CcHelper> lteCcHelper = CreateObject<CcHelper> ();
  lteCcHelper->SetNumberOfComponentCarriers(2);
  lteCcHelper->SetUlEarfcn (18100);
  lteCcHelper->SetDlEarfcn (100);
  lteCcHelper->SetDlBandwidth (100);
  lteCcHelper->SetUlBandwidth (100);
  std::map< uint8_t, ComponentCarrier > lteCcMap = lteCcHelper->EquallySpacedCcs ();
  lteCcMap.at(0).SetAsPrimary(true);

  std::cout << " LteCcMap size " << lteCcMap.size () << std::endl;
  for (std::map< uint8_t, ComponentCarrier >::iterator it = lteCcMap.begin (); it !=lteCcMap.end (); it++)
    {
      ComponentCarrier cc = it->second;
      std::cout << " CC ID " << (uint16_t)it->first
                << " UlBandwidth " << uint16_t (cc.GetUlBandwidth ())
                << " DlBandwidth " << uint16_t (cc.GetDlBandwidth ())
                << " Dl Earfcn " << cc.GetDlEarfcn ()
                << " Ul Earfcn " << cc.GetUlEarfcn ()
                << " - Is this the Primary Channel? " << cc.IsPrimary ()
                << std::endl;
    }

  // create the map of mmWave component carriers
  //create MmWavePhyMacCommon objects
	Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(mmWaveCc0Freq));
	Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(0));
	Ptr<MmWavePhyMacCommon> phyMacConfig0 = CreateObject<MmWavePhyMacCommon> ();
	uint32_t chunkPerRb0 = phyMacConfig0->GetNumChunkPerRb () * mmWaveCc0Bw;
	phyMacConfig0->SetNumChunkPerRB (chunkPerRb0);
	uint32_t numRefSc0 = phyMacConfig0->GetNumRefScPerSym () * mmWaveCc0Bw;
	phyMacConfig0->SetNumRefScPerSym (numRefSc0);

	Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(mmWaveCc1Freq));
	Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(1));
	Ptr<MmWavePhyMacCommon> phyMacConfig1 = CreateObject<MmWavePhyMacCommon> ();
	uint32_t chunkPerRb1 = phyMacConfig1->GetNumChunkPerRb () * mmWaveCc1Bw;
	phyMacConfig1->SetNumChunkPerRB (chunkPerRb1);
	uint32_t numRefSc1 = phyMacConfig1->GetNumRefScPerSym () * mmWaveCc1Bw;
	phyMacConfig1->SetNumRefScPerSym (numRefSc1);

	//create the carriers
	Ptr<MmWaveComponentCarrier> mmWaveCc0 = CreateObject<MmWaveComponentCarrier> ();
	mmWaveCc0->SetConfigurationParameters(phyMacConfig0);
	mmWaveCc0->SetAsPrimary(true);

	Ptr<MmWaveComponentCarrier> mmWaveCc1 = CreateObject<MmWaveComponentCarrier> ();
	mmWaveCc1->SetConfigurationParameters(phyMacConfig1);
	mmWaveCc1->SetAsPrimary(false);

	//create the ccMap
	std::map<uint8_t, MmWaveComponentCarrier > mmWaveCcMap;
	std::map<uint8_t, bool> mmWaveBlockageMap;
	mmWaveCcMap [0] = *mmWaveCc0;
	mmWaveBlockageMap[0] = false;
	if(useOneMmWaveCc == false)
	{
		mmWaveCcMap [1] = *mmWaveCc1;
		mmWaveBlockageMap[1] = false;
	}

  // print mmWave CC parameters
  std::cout << " mmWaveCcMap size " << mmWaveCcMap.size () << std::endl;
  for(uint8_t i = 0; i < mmWaveCcMap.size(); i++)
  {
    Ptr<MmWavePhyMacCommon> phyMacConfig = mmWaveCcMap[i].GetConfigurationParameters();
    std::cout << "Component Carrier " << (uint32_t)(phyMacConfig->GetCcId ())
              << " frequency : " << phyMacConfig->GetCenterFrequency()/1e9 << " GHz,"
              << " bandwidth : " << (phyMacConfig->GetNumRb() * phyMacConfig->GetChunkWidth() * phyMacConfig->GetNumChunkPerRb())/1e6 << " MHz,"
              << " is Primary? " << mmWaveCcMap[i].IsPrimary ()
              //<< ", numRefSc: " << (uint32_t)phyMacConfig->GetNumRefScPerSym()
              //<< ", ChunkPerRB: " << phyMacConfig->GetNumChunkPerRb()
              << std::endl;
  }

	// set the attributes
	Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(mmWaveCcMap.size()>1));
	Config::SetDefault("ns3::MmWaveHelper::LteUseCa",BooleanValue(lteCcMap.size()>1));
	Config::SetDefault("ns3::MmWaveHelper::NumberOfComponentCarriers",UintegerValue(mmWaveCcMap.size()));
	Config::SetDefault("ns3::MmWaveHelper::NumberOfLteComponentCarriers",UintegerValue(lteCcMap.size()));
	if (mmWaveCcMap.size()>1)
	{
		if(useRR)
		{
			Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::MmWaveRrComponentCarrierManager"));
		}
		else
		{
			Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::MmWaveBaRrComponentCarrierManager"));
		}
	}
	else
	{
		Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::MmWaveNoOpComponentCarrierManager"));
	}

	if (lteCcMap.size()>1)
	{
		Config::SetDefault("ns3::MmWaveHelper::LteEnbComponentCarrierManager",StringValue ("ns3::RrComponentCarrierManager"));
	}
	else
	{
		Config::SetDefault("ns3::MmWaveHelper::LteEnbComponentCarrierManager",StringValue ("ns3::NoOpComponentCarrierManager"));
	}
	//Config::SetDefault("ns3::MmWaveHelper::UseIdealRrc", BooleanValue(true));
	Config::SetDefault("ns3::MmWaveHelper::ChannelModel",StringValue("ns3::MmWave3gppChannel"));
	if(useBuilding)
	{
		Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppBuildingsPropagationLossModel"));
	}
	else
	{
		Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppPropagationLossModel"));
	}
	Config::SetDefault("ns3::MmWaveHelper::RlcAmEnabled",BooleanValue(!useRlcUm));
	Config::SetDefault("ns3::MmWaveHelper::HarqEnabled",BooleanValue(useHarq));

  // create the helper
  Ptr<MmWaveHelper> mmWaveHelper = CreateObject<MmWaveHelper> ();
  mmWaveHelper->SetLteCcPhyParams (lteCcMap);
  mmWaveHelper->SetCcPhyParams (mmWaveCcMap);
	mmWaveHelper->SetBlockageMap (mmWaveBlockageMap);

  Ptr<MmWavePointToPointEpcHelper> epcHelper = CreateObject<MmWavePointToPointEpcHelper> ();
  mmWaveHelper->SetEpcHelper (epcHelper);

  // Create the Internet by connecting remoteHost to pgw. Setup routing too
  Ptr<Node> pgw = epcHelper->GetPgwNode ();

  // Create remotehost
  NodeContainer remoteHostContainer;
  remoteHostContainer.Create (1);
  InternetStackHelper internet;
  internet.Install (remoteHostContainer);
  Ipv4StaticRoutingHelper ipv4RoutingHelper;
  Ipv4InterfaceContainer internetIpIfaces;

  Ptr<Node> remoteHost = remoteHostContainer.Get (0);
  // Create the Internet
  PointToPointHelper p2ph;
  p2ph.SetDeviceAttribute ("DataRate", DataRateValue (DataRate ("100Gb/s")));
  p2ph.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  p2ph.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (0.01)));

  NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);

  Ipv4AddressHelper ipv4h;
  ipv4h.SetBase ("1.0.0.0", "255.255.0.0");
  internetIpIfaces = ipv4h.Assign (internetDevices);
  // interface 0 is localhost, 1 is the p2p device
  Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress (1);

  Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
  remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.255.0.0"), 1);

  // create the nodes
  NodeContainer enbNodes;
	NodeContainer lteEnbNodes;
	NodeContainer mmWaveEnbNodes;
  NodeContainer mcUeNodes;
  enbNodes.Create (3);
	lteEnbNodes.Add(enbNodes.Get(0));
	mmWaveEnbNodes.Add (enbNodes.Get (1));
	mmWaveEnbNodes.Add (enbNodes.Get (2));
  mcUeNodes.Create (1);

	/* Create the building */
	 double streetWidth = 0;
	 double blockSize = 20;
	 double maxObstacleSize = blockSize - streetWidth;


	 double maxXAxis = 100;
	 double maxYAxis = 50;
	 uint32_t numBlocks = 7;

	 std::vector<Ptr<Building> > buildingVector;
	 std::list<Box>  m_previousBlocks;

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

		 std::pair<Box, std::list<Box>> pairBuildings = GenerateBuildingBounds(0, maxXAxis-maxObstacleSize, 0, maxYAxis-maxObstacleSize, maxObstacleSize, m_previousBlocks);
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
		/* END Create the building */


 // MOBILITY
	Vector mcUeInitialPos = Vector (30, -5, 1.6);
	Vector mcUeVelocity = Vector (speed, 0, 0);

  // set enb mobility
	// mmW eNB 1 ------------------- LTE eNB ------------------- mmW eNB2
	Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector (maxXAxis, maxYAxis, 30.0));
	enbPositionAlloc->Add (Vector (maxXAxis, maxYAxis, 15.0));
	enbPositionAlloc->Add (Vector (0, maxYAxis, 15.0));


  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator(enbPositionAlloc);
  enbmobility.Install (enbNodes);
  BuildingsHelper::Install (enbNodes);
	std::cout << "Lte eNB position " << lteEnbNodes.Get(0)->GetObject<MobilityModel>()->GetPosition() << std::endl;
	std::cout << "mmWave eNB position " << mmWaveEnbNodes.Get(0)->GetObject<MobilityModel>()->GetPosition() << std::endl;
	std::cout << "mmWave eNB position " << mmWaveEnbNodes.Get(1)->GetObject<MobilityModel>()->GetPosition() << std::endl;


  // set mc-ue mobility
	MobilityHelper mcUeMobility;
  Ptr<ListPositionAllocator> mcUePositionAlloc = CreateObject<ListPositionAllocator> ();
  mcUePositionAlloc->Add (mcUeInitialPos); // with distance = 15km txOpportunity is 903 bytes, so LTE CC1 is used too.

  mcUeMobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
  mcUeMobility.SetPositionAllocator(mcUePositionAlloc);
  mcUeMobility.Install (mcUeNodes);
  BuildingsHelper::Install (mcUeNodes);

	mcUeNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (mcUeVelocity);
	std::cout << "UE speed " << mcUeVelocity << std::endl;
	//Simulator::Schedule(Seconds(1),&ChangeSpeed, mcUeNodes.Get(0),Vector (-10, 0, 0));

	// Create Devices and install them in the Nodes
	NetDeviceContainer lteEnbDevs;
	lteEnbDevs = mmWaveHelper->InstallLteEnbDevice (lteEnbNodes);
	std::cout << "LTE eNB device installed" << std::endl;

  NetDeviceContainer mmWaveEnbDevs;
  mmWaveEnbDevs = mmWaveHelper->InstallEnbDevice (mmWaveEnbNodes);
  std::cout << "mmWave eNB device installed" << std::endl;

  NetDeviceContainer mcUeDevs;
  mcUeDevs = mmWaveHelper->InstallMcUeDevice (mcUeNodes);
  std::cout << "McUe device installed" << std::endl;

  // Install the IP stack on the UEs
  internet.Install (mcUeNodes);
  Ipv4InterfaceContainer ueIpIface;
  ueIpIface = epcHelper->AssignUeIpv4Address (mcUeDevs);
  // Assign IP address to UEs, and install applications
  // Set the default gateway for the UE
  Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (mcUeNodes.Get (0)->GetObject<Ipv4> ());
  ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);

  mmWaveHelper->AddX2Interface (lteEnbNodes, mmWaveEnbNodes);

  mmWaveHelper->AttachToClosestEnb (mcUeDevs, mmWaveEnbDevs, lteEnbDevs);


  // Install and start applications on UEs and remote host
  uint16_t dlPort = 1234;
  uint16_t ulPort = 2000;
  ApplicationContainer clientApps;
  ApplicationContainer serverApps;

  PacketSinkHelper dlPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), dlPort));
  PacketSinkHelper ulPacketSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), ulPort));
  serverApps.Add (dlPacketSinkHelper.Install (mcUeNodes.Get(0)));
  serverApps.Add (ulPacketSinkHelper.Install (remoteHost));

  UdpClientHelper dlClient (ueIpIface.GetAddress (0), dlPort);
  dlClient.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
  dlClient.SetAttribute ("MaxPackets", UintegerValue(10000000));

  UdpClientHelper ulClient (remoteHostAddr, ulPort);
  ulClient.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
  ulClient.SetAttribute ("MaxPackets", UintegerValue(10000000));

  clientApps.Add (dlClient.Install (remoteHost));
  clientApps.Add (ulClient.Install (mcUeNodes.Get(0)));

	double mcUeFinalPosition = 70;
	if (simTime == 0)
	{
		simTime = ceil(mcUeFinalPosition/speed);
	}
	std::cout << "-------------------final ue position " << mcUeFinalPosition << std::endl;
	double appStartTime = 0.1;
	double appEndTime = simTime-0.1;
	std::cout << "Simulation time " << simTime << std::endl;
	std::cout << "ServerApps start at " << appStartTime << " and end at " << appEndTime <<  std::endl;
	std::cout << "ClientApps start at " << appStartTime << " and end at " << simTime << std::endl;

  serverApps.Start (Seconds (appStartTime));
  clientApps.Start (Seconds (appStartTime));
	clientApps.Stop (Seconds (appEndTime));


  //mmWaveHelper->EnableTraces (); // enable all the Traces
	mmWaveHelper->EnableMcTraces();
	mmWaveHelper->EnablePdcpTraces();
	mmWaveHelper->EnableDlPhyTrace ();
	mmWaveHelper->EnableUlPhyTrace ();
	//mmWaveHelper->EnableRlcTraces ();
  Traces(filePath); // mac tx traces

	// -------------------APPLICATION LAYER TRACES -------------------------------
	// 1. packets sent by the remoteHost and received by the UE
	std::string packetSinkDlFilePath = filePath + "PacketSinkDlRx.txt";
	AsciiTraceHelper asciiTraceHelper;
	Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (packetSinkDlFilePath);
	//*stream->GetStream () << "Packets sent by the remoteHost and received by the UE\n"
	//										  << "Time" << "\t" << "Size" << std::endl;
	serverApps.Get(0)->TraceConnectWithoutContext("Rx", MakeBoundCallback (&DlRx, stream));

	// 2. packets sent by the UE and received by the remoteHost
	std::string packetSinkUlFilePath = filePath + "PacketSinkUlRx.txt";
	Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream (packetSinkUlFilePath);
	//*stream1->GetStream () << "Packets sent by the UE and received by the remoteHost\n"
	//											 << "Time" << "\t" << "Size" << std::endl;
	serverApps.Get(1)->TraceConnectWithoutContext("Rx", MakeBoundCallback (&UlRx, stream1));
	//----------------------------------------------------------------------------

	BuildingsHelper::MakeMobilityModelConsistent ();
	// Export the gnuplot script to plot the scenario
  // To plot the scenario, execute with gnuplot:
  // 1. load 'plot-file.txt'
  // 2. plot 1/0
  std::string buildingFileName;
  buildingFileName = filePath + "building-file.txt";
  PrintGnuplottableBuildingListToFile(buildingFileName);
  PrintGnuplottableEnbListToFile(buildingFileName);
  PrintGnuplottableUeListToFile(buildingFileName);


	Simulator::Schedule (Seconds(0.1), &PositionTrace, mcUeNodes.Get(0));

  Simulator::Stop (Seconds (simTime));

  Simulator::Run ();

  // GtkConfigStore config;
  // config.ConfigureAttributes ();

  Simulator::Destroy ();

	numOfTxPackets = std::floor((appEndTime-appStartTime)/interPacketInterval*1e6);

	LossRateTrace (filePath);

	std::cout << "Number of sent packets " << numOfTxPackets << std::endl;
	std::cout << "Remote Host received " << packetSinkUlRxCounter << " packets" << std::endl;
	std::cout << "UE received " << packetSinkDlRxCounter << " packets" << std::endl;

  return 0;
}
