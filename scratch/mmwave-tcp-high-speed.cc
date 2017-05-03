
#include "ns3/point-to-point-module.h"
#include "ns3/mmwave-helper.h"
#include "ns3/epc-helper.h"
#include "ns3/mmwave-point-to-point-epc-helper.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/internet-module.h"
#include "ns3/mobility-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/config-store.h"
#include <ns3/buildings-helper.h>
#include <ns3/buildings-module.h>
#include <ns3/packet.h>
#include <ns3/tag.h>
/*#include <ns3/lte-helper.h>
#include <ns3/epc-helper.h>
#include <ns3/point-to-point-helper.h>
#include <ns3/lte-module.h>*/

//#include "ns3/gtk-config-store.h"

using namespace ns3;

/**
 * A script to simulate the DOWNLINK TCP data over mmWave links
 * with the mmWave devices and the LTE EPC.
 */
NS_LOG_COMPONENT_DEFINE ("mmWaveTCPExample");



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
Traces(uint16_t nodeNum, std::string protocol)
{
	AsciiTraceHelper asciiTraceHelper;

	std::ostringstream pathCW;
	pathCW<<"/NodeList/"<<nodeNum+2<<"/$ns3::TcpL4Protocol/SocketList/0/CongestionWindow";

	std::ostringstream fileCW;
	fileCW<<protocol<<"-"<<nodeNum+1<<"-TCP-CWND.txt";

	std::ostringstream pathRTT;
	pathRTT<<"/NodeList/"<<nodeNum+2<<"/$ns3::TcpL4Protocol/SocketList/0/RTT";

	std::ostringstream fileRTT;
	fileRTT<<protocol<<"-"<<nodeNum+1<<"-TCP-RTT.txt";

	std::ostringstream pathRCWnd;
	pathRCWnd<<"/NodeList/"<<nodeNum+2<<"/$ns3::TcpL4Protocol/SocketList/0/RWND";

	std::ostringstream fileRCWnd;
	fileRCWnd<<protocol<<"-"<<nodeNum+1<<"-TCP-RCWND.txt";

	Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream (fileCW.str ().c_str ());
	Config::ConnectWithoutContext (pathCW.str ().c_str (), MakeBoundCallback(&CwndChange, stream1));

	Ptr<OutputStreamWrapper> stream2 = asciiTraceHelper.CreateFileStream (fileRTT.str ().c_str ());
	Config::ConnectWithoutContext (pathRTT.str ().c_str (), MakeBoundCallback(&RttChange, stream2));

	Ptr<OutputStreamWrapper> stream4 = asciiTraceHelper.CreateFileStream (fileRCWnd.str ().c_str ());
	Config::ConnectWithoutContext (pathRCWnd.str ().c_str (), MakeBoundCallback(&CwndChange, stream4));

}


int
main (int argc, char *argv[])
{

  // LogComponentEnable("TcpCongestionOps", LOG_LEVEL_INFO);
  // LogComponentEnable("TcpSocketBase", LOG_LEVEL_INFO);

	uint16_t nodeNum = 1;
	double simStopTime = 60;
	bool harqEnabled = true;
	bool rlcAmEnabled = true;
	std::string protocol = "TcpVegas";
	//int bufferSize = 1000 *1000 * 3.5 * 0.4;
	int bufferSize = 1000 *1000 * 1.5;
	int packetSize = 14000;
	int p2pDelay = 0;
	// This 3GPP channel model example only demonstrate the pathloss model. The fast fading model is still in developing.

	//The available channel scenarios are 'RMa', 'UMa', 'UMi-StreetCanyon', 'InH-OfficeMixed', 'InH-OfficeOpen', 'InH-ShoppingMall'
	std::string scenario = "RMa";
	std::string condition = "n";

	CommandLine cmd;
//	cmd.AddValue("numEnb", "Number of eNBs", numEnb);
//	cmd.AddValue("numUe", "Number of UEs per eNB", numUe);
	cmd.AddValue("simTime", "Total duration of the simulation [s])", simStopTime);
//	cmd.AddValue("interPacketInterval", "Inter-packet interval [us])", interPacketInterval);
	cmd.AddValue("harq", "Enable Hybrid ARQ", harqEnabled);
	cmd.AddValue("rlcAm", "Enable RLC-AM", rlcAmEnabled);
	cmd.AddValue("protocol", "TCP protocol", protocol);
	cmd.AddValue("bufferSize", "buffer size", bufferSize);
	cmd.AddValue("packetSize", "packet size", packetSize);
	cmd.AddValue("p2pDelay","delay between server and PGW", p2pDelay);
	cmd.Parse(argc, argv);

	//Config::SetDefault ("ns3::TcpSocket::SegmentSize", UintegerValue (65535));
	Config::SetDefault ("ns3::TcpSocketBase::MinRto", TimeValue (MilliSeconds (200)));
	Config::SetDefault ("ns3::Ipv4L3Protocol::FragmentExpirationTimeout", TimeValue (Seconds (1)));
	Config::SetDefault ("ns3::TcpSocket::SegmentSize", UintegerValue (packetSize));
	Config::SetDefault ("ns3::TcpSocket::DelAckCount", UintegerValue (1));

	Config::SetDefault ("ns3::TcpSocket::SndBufSize", UintegerValue (131072*400));
	Config::SetDefault ("ns3::TcpSocket::RcvBufSize", UintegerValue (131072*400));


	Config::SetDefault ("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue(rlcAmEnabled));
	Config::SetDefault ("ns3::MmWaveHelper::HarqEnabled", BooleanValue(harqEnabled));
	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::HarqEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::LteRlcAm::PollRetransmitTimer", TimeValue(MilliSeconds(2.0)));
	Config::SetDefault ("ns3::LteRlcAm::ReorderingTimer", TimeValue(MilliSeconds(1.0)));
	Config::SetDefault ("ns3::LteRlcAm::StatusProhibitTimer", TimeValue(MilliSeconds(1.0)));
	Config::SetDefault ("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MilliSeconds(2.0)));
	Config::SetDefault ("ns3::LteRlcAm::MaxTxBufferSize", UintegerValue (bufferSize));
    Config::SetDefault ("ns3::QueueBase::MaxPackets", UintegerValue (100*1000));

	Config::SetDefault ("ns3::CoDelQueueDisc::Mode", StringValue ("QUEUE_DISC_MODE_PACKETS"));
    Config::SetDefault ("ns3::CoDelQueueDisc::MaxPackets", UintegerValue (50000));
    //Config::SetDefault ("ns3::CoDelQueue::Interval", StringValue ("500ms"));
    //Config::SetDefault ("ns3::CoDelQueue::Target", StringValue ("50ms"));

    //Config::SetDefault ("ns3::LteEnbRrc::SecondaryCellHandoverMode", EnumValue(LteEnbRrc::FIXED_TTT));

	//Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpCubic::GetTypeId ()));
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
    else if (protocol == "TcpCubic")
    {
    	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpCubic::GetTypeId ()));

    }
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


	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::ChannelCondition", StringValue(condition));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Scenario", StringValue(scenario));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::OptionalNlos", BooleanValue(false));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Shadowing", BooleanValue(true)); // enable or disable the shadowing effect
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::InCar", BooleanValue(true)); // enable or disable the shadowing effect



	Config::SetDefault ("ns3::MmWave3gppChannel::UpdatePeriod", TimeValue (MilliSeconds (100))); // Set channel update period, 0 stands for no update.
	Config::SetDefault ("ns3::MmWave3gppChannel::CellScan", BooleanValue(false)); // Set true to use cell scanning method, false to use the default power method.
	Config::SetDefault ("ns3::MmWave3gppChannel::Blockage", BooleanValue(true)); // use blockage or not
	Config::SetDefault ("ns3::MmWave3gppChannel::PortraitMode", BooleanValue(true)); // use blockage model with UT in portrait mode
	Config::SetDefault ("ns3::MmWave3gppChannel::NumNonselfBlocking", IntegerValue(4)); // number of non-self blocking obstacles
	Config::SetDefault ("ns3::MmWave3gppChannel::BlockerSpeed", DoubleValue(1)); // speed of non-self blocking obstacles

	Config::SetDefault ("ns3::MmWavePhyMacCommon::NumHarqProcess", UintegerValue(100));

	Config::SetDefault ("ns3::MmWaveSpectrumPhy::FileName", StringValue(protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay)));

	double hBS = 0; //base station antenna height in meters;
	double hUT = 0; //user antenna height in meters;
	if(scenario.compare("RMa")==0)
	{
		hBS = 35;
		hUT = 1.5;
	}
	else if(scenario.compare("UMa")==0)
	{
		hBS = 25;
		hUT = 1.5;
	}
	else if (scenario.compare("UMi-StreetCanyon")==0)
	{
		hBS = 10;
		hUT = 1.5;
	}
	else if (scenario.compare("InH-OfficeMixed")==0 || scenario.compare("InH-OfficeOpen")==0 || scenario.compare("InH-ShoppingMall")==0)
	{
		hBS = 3;
		hUT = 1;
	}
	else
	{
		std::cout<<"Unkown scenario.\n";
		return 1;
	}


	Ptr<MmWaveHelper> mmwaveHelper = CreateObject<MmWaveHelper> ();

	mmwaveHelper->SetAttribute ("PathlossModel", StringValue ("ns3::MmWave3gppBuildingsPropagationLossModel"));
	mmwaveHelper->SetAttribute ("ChannelModel", StringValue ("ns3::MmWave3gppChannel"));

	mmwaveHelper->Initialize();
	mmwaveHelper->SetHarqEnabled(true);

	Ptr<MmWavePointToPointEpcHelper>  epcHelper = CreateObject<MmWavePointToPointEpcHelper> ();
	mmwaveHelper->SetEpcHelper (epcHelper);

	Ptr<Node> pgw = epcHelper->GetPgwNode ();


	// Create a single RemoteHost
	NodeContainer remoteHostContainer;
	remoteHostContainer.Create (nodeNum);
	InternetStackHelper internet;
	internet.Install (remoteHostContainer);
	Ipv4StaticRoutingHelper ipv4RoutingHelper;
	Ipv4InterfaceContainer internetIpIfaces;

	for (uint16_t i = 0; i < nodeNum; i++)
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

	Ptr < Building > building1;
	building1 = Create<Building> ();
	building1->SetBoundaries (Box (1100,1140.0,
								12, 20.0,
								0.0, 40));


	Ptr < Building > building2;
	building2 = Create<Building> ();
	building2->SetBoundaries (Box (620,700.0,
								0, 5.0,
								0.0, 40));

	Ptr < Building > building3;
	building3 = Create<Building> ();
	building3->SetBoundaries (Box (565,575.0,
								1.0, 5.0,
								0.0, 40));

	Ptr < Building > building4;
	building4 = Create<Building> ();
	building4->SetBoundaries (Box (1220,1260.0,
								11.0, 11.5,
								0.0, 40));

	Ptr < Building > building5;
	building5 = Create<Building> ();
	building5->SetBoundaries (Box (1330,1360.0,
								11.0, 11.5,
								0.0, 40));


	  NodeContainer ueNodes;
	  NodeContainer mmWaveEnbNodes;
	  NodeContainer lteEnbNodes;
	  NodeContainer allEnbNodes;
	  mmWaveEnbNodes.Create(4);
	  lteEnbNodes.Create(1);
	  ueNodes.Create(1);
	  allEnbNodes.Add(lteEnbNodes);
	  allEnbNodes.Add(mmWaveEnbNodes);

	Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
	enbPositionAlloc->Add (Vector (0.0, 0.0, hBS));

	enbPositionAlloc->Add (Vector (0.0, 16.0, hBS));
	enbPositionAlloc->Add (Vector (580.0, 0.0, hBS));
	enbPositionAlloc->Add (Vector (1160.0, 16.0, hBS));
	enbPositionAlloc->Add (Vector (1732.0, 0.0, hBS));

	MobilityHelper enbmobility;
	enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	enbmobility.SetPositionAllocator(enbPositionAlloc);
	enbmobility.Install (allEnbNodes);
	BuildingsHelper::Install (allEnbNodes);
	MobilityHelper uemobility;
	uemobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
	uemobility.Install (ueNodes);
	BuildingsHelper::Install (ueNodes);

	ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (0, 8, hUT));
	ueNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (30, 0, 0));


	// Install LTE Devices to the nodes
	  NetDeviceContainer lteEnbDevs = mmwaveHelper->InstallLteEnbDevice (lteEnbNodes);
	  NetDeviceContainer mmWaveEnbDevs = mmwaveHelper->InstallEnbDevice (mmWaveEnbNodes);
	  NetDeviceContainer mcUeDevs;

	    mcUeDevs = mmwaveHelper->InstallMcUeDevice (ueNodes);

	// Install the IP stack on the UEs
	// Assign IP address to UEs, and install applications
	internet.Install (ueNodes);
	Ipv4InterfaceContainer ueIpIface;
	ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (mcUeDevs));

	  mmwaveHelper->AddX2Interface (lteEnbNodes, mmWaveEnbNodes);
	    mmwaveHelper->AttachToClosestEnb (mcUeDevs, mmWaveEnbDevs, lteEnbDevs);  	//mmwaveHelper->EnableTraces ();

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

	    std::ostringstream fileName;
	    fileName<<protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay)<<"-"<<i+1<<"-TCP-DATA.txt";

		AsciiTraceHelper asciiTraceHelper;

		Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (fileName.str ().c_str ());
		sinkApps.Get(i)->TraceConnectWithoutContext("Rx",MakeBoundCallback (&Rx, stream));
	    sourceApps.Get(i)->SetStartTime(Seconds (0.1+0.01*i));
	    Simulator::Schedule (Seconds (0.1001+0.01*i), &Traces, i, protocol+"-"+std::to_string(bufferSize)+"-"+std::to_string(packetSize)+"-"+std::to_string(p2pDelay));
	    //sourceApps.Get(i)->SetStopTime (Seconds (10-1.5*i));
	    sourceApps.Get(i)->SetStopTime (Seconds (simStopTime));

		sinkPort++;

	}

	sinkApps.Start (Seconds (0.));
	sinkApps.Stop (Seconds (simStopTime));
    //sourceAppsUL.Start (Seconds (0.1));
    //sourceApps.Stop (Seconds (simStopTime));


	//p2ph.EnablePcapAll("mmwave-sgi-capture");
	BuildingsHelper::MakeMobilityModelConsistent ();

	Config::Set ("/NodeList/*/DeviceList/*/TxQueue/MaxPackets", UintegerValue (1000*1000));
	Config::Set ("/NodeList/*/DeviceList/*/TxQueue/MaxBytes", UintegerValue (1500*1000*1000));


	Simulator::Stop (Seconds (simStopTime));
	Simulator::Run ();
	Simulator::Destroy ();

	return 0;

}
