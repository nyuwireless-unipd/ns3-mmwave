
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
Traces(uint16_t nodeNum)
{
	AsciiTraceHelper asciiTraceHelper;

	std::ostringstream pathCW;
	pathCW<<"/NodeList/"<<nodeNum+1<<"/$ns3::TcpL4Protocol/SocketList/0/CongestionWindow";

	std::ostringstream fileCW;
	fileCW<<"UE-"<<nodeNum+1<<"-TCP-CWND.txt";

	std::ostringstream pathRTT;
	pathRTT<<"/NodeList/"<<nodeNum+1<<"/$ns3::TcpL4Protocol/SocketList/0/RTT";

	std::ostringstream fileRTT;
	fileRTT<<"UE-"<<nodeNum+1<<"-TCP-RTT.txt";

	std::ostringstream pathRCWnd;
	pathRCWnd<<"/NodeList/"<<nodeNum+1<<"/$ns3::TcpL4Protocol/SocketList/0/RWND";

	std::ostringstream fileRCWnd;
	fileRCWnd<<"UE-"<<nodeNum+1<<"-TCP-RCWND.txt";

	Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream (fileCW.str ().c_str ());
	Config::ConnectWithoutContext (pathCW.str ().c_str (), MakeBoundCallback(&CwndChange, stream1));

	Ptr<OutputStreamWrapper> stream2 = asciiTraceHelper.CreateFileStream (fileRTT.str ().c_str ());
	Config::ConnectWithoutContext (pathRTT.str ().c_str (), MakeBoundCallback(&RttChange, stream2));

	Ptr<OutputStreamWrapper> stream4 = asciiTraceHelper.CreateFileStream (fileRCWnd.str ().c_str ());
	Config::ConnectWithoutContext (pathRCWnd.str ().c_str (), MakeBoundCallback(&CwndChange, stream4));

}


void
TraceBuildingLoc()
{
	//Write the location of buildings.
	static bool firstTitme = true;
	if(firstTitme)
	{
		firstTitme = false;
		std::ofstream outFile;
		outFile.open ("building.txt");
		if (!outFile.is_open ())
		{
		  NS_FATAL_ERROR ("Can't open file building.txt");
		}
		for (BuildingList::Iterator bit = BuildingList::Begin (); bit != BuildingList::End (); ++bit)
		{
			Box boundaries = (*bit)->GetBoundaries ();
			outFile << boundaries.xMin<< "\t";
			outFile << boundaries.xMax<< "\t";
			outFile << boundaries.yMin<< "\t";
			outFile << boundaries.yMax<< "\t";
			outFile << boundaries.zMin<< "\t";
			outFile << boundaries.zMax << std::endl;
		}
		outFile.close ();
	}
}


int
main (int argc, char *argv[])
{

  // LogComponentEnable("TcpCongestionOps", LOG_LEVEL_INFO);
  // LogComponentEnable("TcpSocketBase", LOG_LEVEL_INFO);

	uint16_t nodeNum = 2;
	double simStopTime = 50;
	bool harqEnabled = true;
	bool rlcAmEnabled = true;

	// This 3GPP channel model example only demonstrate the pathloss model. The fast fading model is still in developing.

	//The available channel scenarios are 'RMa', 'UMa', 'UMi-StreetCanyon', 'InH-OfficeMixed', 'InH-OfficeOpen', 'InH-ShoppingMall'
	std::string scenario = "UMa";
	std::string condition = "a";

	CommandLine cmd;
//	cmd.AddValue("numEnb", "Number of eNBs", numEnb);
//	cmd.AddValue("numUe", "Number of UEs per eNB", numUe);
	cmd.AddValue("simTime", "Total duration of the simulation [s])", simStopTime);
//	cmd.AddValue("interPacketInterval", "Inter-packet interval [us])", interPacketInterval);
	cmd.AddValue("harq", "Enable Hybrid ARQ", harqEnabled);
	cmd.AddValue("rlcAm", "Enable RLC-AM", rlcAmEnabled);
	cmd.Parse(argc, argv);

	//Config::SetDefault ("ns3::TcpSocket::SegmentSize", UintegerValue (65535));
	int PacketSize = 60000;
	Config::SetDefault ("ns3::TcpSocketBase::MinRto", TimeValue (MilliSeconds (200)));
	Config::SetDefault ("ns3::Ipv4L3Protocol::FragmentExpirationTimeout", TimeValue (Seconds (1)));
	Config::SetDefault ("ns3::TcpSocket::SegmentSize", UintegerValue (PacketSize));
	Config::SetDefault ("ns3::TcpSocket::DelAckCount", UintegerValue (1));

	Config::SetDefault ("ns3::TcpSocket::SndBufSize", UintegerValue (131072*200));
	Config::SetDefault ("ns3::TcpSocket::RcvBufSize", UintegerValue (131072*200));


	Config::SetDefault ("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue(rlcAmEnabled));
	Config::SetDefault ("ns3::MmWaveHelper::HarqEnabled", BooleanValue(harqEnabled));
	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::MmWaveFlexTtiMaxWeightMacScheduler::HarqEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::LteRlcAm::PollRetransmitTimer", TimeValue(MilliSeconds(2.0)));
	Config::SetDefault ("ns3::LteRlcAm::ReorderingTimer", TimeValue(MilliSeconds(1.0)));
	Config::SetDefault ("ns3::LteRlcAm::StatusProhibitTimer", TimeValue(MilliSeconds(1.0)));
	Config::SetDefault ("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MilliSeconds(2.0)));
	Config::SetDefault ("ns3::LteRlcAm::MaxTxBufferSize", UintegerValue (1000 *1000 * 6));

    Config::SetDefault ("ns3::Queue::MaxPackets", UintegerValue (100*1000));

	Config::SetDefault ("ns3::CoDelQueueDisc::Mode", StringValue ("QUEUE_MODE_PACKETS"));
    Config::SetDefault ("ns3::CoDelQueueDisc::MaxPackets", UintegerValue (50000));
    //Config::SetDefault ("ns3::CoDelQueue::Interval", StringValue ("500ms"));
    //Config::SetDefault ("ns3::CoDelQueue::Target", StringValue ("50ms"));


	//Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpCubic::GetTypeId ()));
	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpNewReno::GetTypeId ()));


	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::ChannelCondition", StringValue(condition));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Scenario", StringValue(scenario));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::OptionalNlos", BooleanValue(false));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Shadowing", BooleanValue(false)); // enable or disable the shadowing effect

	Config::SetDefault ("ns3::MmWave3gppChannel::UpdatePeriod", TimeValue (MilliSeconds (100))); // Set channel update period, 0 stands for no update.
	Config::SetDefault ("ns3::MmWave3gppChannel::CellScan", BooleanValue(false)); // Set true to use cell scanning method, false to use the default power method.
	Config::SetDefault ("ns3::MmWave3gppChannel::Blockage", BooleanValue(false)); // use blockage or not
	Config::SetDefault ("ns3::MmWave3gppChannel::PortraitMode", BooleanValue(true)); // use blockage model with UT in portrait mode
	Config::SetDefault ("ns3::MmWave3gppChannel::NumNonselfBlocking", IntegerValue(4)); // number of non-self blocking obstacles
	Config::SetDefault ("ns3::MmWave3gppChannel::BlockerSpeed", DoubleValue(1)); // speed of non-self blocking obstacles

	Config::SetDefault ("ns3::MmWavePhyMacCommon::NumHarqProcess", UintegerValue(100));

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
		p2ph.SetChannelAttribute ("Delay", TimeValue (Seconds (0.010)));

		//p2ph.SetChannelAttribute ("Delay", TimeValue (Seconds (0.010+i*0.0025)));

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


	Ptr < Building > building1a;
		building1a = Create<Building> ();
		building1a->SetBoundaries (Box (0.0,67.0,
									0.0, 100,
									0.0, 12));

		Ptr < Building > building1b;
		building1b = Create<Building> ();
		building1b->SetBoundaries (Box (10.0,57.0,
									20.0, 90,
									12.0, 95));

		Ptr < Building > building2;
		building2 = Create<Building> ();
		building2->SetBoundaries (Box (86.0,156.0,
									18.0, 100,
									0.0, 40));
		/*Ptr < Building > building3;
		building3 = Create<Building> ();
		building3->SetBoundaries (Box (178.0,240.0,
									18.0, 100,
									0.0, 40));*/

		Ptr < Building > building4a;
		building4a = Create<Building> ();
		building4a->SetBoundaries (Box (21.0,67.0,
									119.0, 149,
									0.0, 32));
		Ptr < Building > building4b;
		building4b = Create<Building> ();
		building4b->SetBoundaries (Box (38.0,67.0,
									149.0, 199,
									0.0, 32));
		Ptr < Building > building4c;
		building4c = Create<Building> ();
		building4c->SetBoundaries (Box (14.0,38.0,
									149.0, 164,
									0.0, 30));
		Ptr < Building > building4d;
		building4d = Create<Building> ();
		building4d->SetBoundaries (Box (0.0,14.0,
									149.0, 185,
									0.0, 32));

		/*Ptr < Building > building5a;
		building5a = Create<Building> ();
		building5a->SetBoundaries (Box (178.0,278.0,
									119.0, 163,
									0.0, 80));
		Ptr < Building > building5b;
		building5b = Create<Building> ();
		building5b->SetBoundaries (Box (203.0,258.0,
									163.0, 184,
									0.0, 30));
		Ptr < Building > building5c;
		building5c = Create<Building> ();
		building5c->SetBoundaries (Box (178.0,238.0,
									184.0, 226,
									0.0, 30));*/

		Ptr < Building > building6;
		building6 = Create<Building> ();
		building6->SetBoundaries (Box (91.0,156.0,
									184.0, 221,
									0.0, 17));

		/*Ptr < Building > building4;
		building4 = Create<Building> ();
		building4->SetBoundaries (Box (30.0,70.0,
									60.0, 80,
									0.0, 20));*/


		Ptr < Building > tree1;
		tree1 = Create<Building> ();
		tree1->SetBoundaries (Box (100.0,100.50,
									120.0, 120.50,
									0.0, 3));

		Ptr < Building > tree1a;
		tree1a = Create<Building> ();
		tree1a->SetBoundaries (Box (95.0,105.50,
									115.0, 125.50,
									3, 12));
		Ptr < Building > tree2;
		tree2 = Create<Building> ();
		tree2->SetBoundaries (Box (140.0,140.50,
									120.0, 120.50,
									0.0, 2.5));

		Ptr < Building > tree2a;
		tree2a = Create<Building> ();
		tree2a->SetBoundaries (Box (134.0,146.50,
									114.0, 126.50,
									2.5, 15));
		Ptr < Building > tree3;
		tree3 = Create<Building> ();
		tree3->SetBoundaries (Box (135.0,135.50,
									132.0, 132.5,
									0.0, 2));
		Ptr < Building > tree3a;
		tree3a = Create<Building> ();
		tree3a->SetBoundaries (Box (130.0,140.50,
									127.0, 137.5,
									2, 13));
		Ptr < Building > tree4;
		tree4 = Create<Building> ();
		tree4->SetBoundaries (Box (110.0,110.50,
									160.0, 160.5,
									0.0, 3));
		Ptr < Building > tree4a;
		tree4a = Create<Building> ();
		tree4a->SetBoundaries (Box (105,115.50,
									155.0, 165.5,
									3, 20));



	NodeContainer ueNodes;
	NodeContainer enbNodes;
	enbNodes.Create(2);
	ueNodes.Create(nodeNum);

	Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
	enbPositionAlloc->Add (Vector (70.0, 180.0, hBS));
	enbPositionAlloc->Add (Vector (160.0, 180.0, hBS));	MobilityHelper enbmobility;
	enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	enbmobility.SetPositionAllocator(enbPositionAlloc);
	enbmobility.Install (enbNodes);
	BuildingsHelper::Install (enbNodes);
	MobilityHelper uemobility;
	uemobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
	uemobility.Install (ueNodes);
	BuildingsHelper::Install (ueNodes);

	ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (76, 170, hUT));
	ueNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (0, -1, 0));

	ueNodes.Get (1)->GetObject<MobilityModel> ()->SetPosition (Vector (120, 110, hUT));
	ueNodes.Get (1)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (-1, 0, 0));



	// Install LTE Devices to the nodes
	NetDeviceContainer enbDevs = mmwaveHelper->InstallEnbDevice (enbNodes);
	NetDeviceContainer ueDevs = mmwaveHelper->InstallUeDevice (ueNodes);

	// Install the IP stack on the UEs
	// Assign IP address to UEs, and install applications
	internet.Install (ueNodes);
	Ipv4InterfaceContainer ueIpIface;
	ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (ueDevs));

	mmwaveHelper->AttachToClosestEnb (ueDevs, enbDevs);
	//mmwaveHelper->EnableTraces ();

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
	    fileName<<"UE-"<<i+1<<"-TCP-DATA.txt";

		AsciiTraceHelper asciiTraceHelper;

		Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream (fileName.str ().c_str ());
		sinkApps.Get(i)->TraceConnectWithoutContext("Rx",MakeBoundCallback (&Rx, stream));
	    sourceApps.Get(i)->SetStartTime(Seconds (0.1+1.5*i));
	    Simulator::Schedule (Seconds (0.1001+1.5*i), &Traces, i);
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
	TraceBuildingLoc();

	Config::Set ("/NodeList/*/DeviceList/*/TxQueue/MaxPackets", UintegerValue (1000*1000));
	Config::Set ("/NodeList/*/DeviceList/*/TxQueue/MaxBytes", UintegerValue (1500*1000*1000));


	Simulator::Stop (Seconds (simStopTime));
	Simulator::Run ();
	Simulator::Destroy ();

	return 0;

}
