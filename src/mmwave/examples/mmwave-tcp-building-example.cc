
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


class MyApp : public Application
{
public:

  MyApp ();
  virtual ~MyApp();
  void ChangeDataRate (DataRate rate);
  void Setup (Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets, DataRate dataRate);

private:
  virtual void StartApplication (void);
  virtual void StopApplication (void);

  void ScheduleTx (void);
  void SendPacket (void);

  Ptr<Socket>     m_socket;
  Address         m_peer;
  uint32_t        m_packetSize;
  uint32_t        m_nPackets;
  DataRate        m_dataRate;
  EventId         m_sendEvent;
  bool            m_running;
  uint32_t        m_packetsSent;
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

MyApp::~MyApp()
{
  m_socket = 0;
}

void
MyApp::Setup (Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets, DataRate dataRate)
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
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldCwnd << "\t" << newCwnd << std::endl;
}


static void Rx (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet, const Address &from)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << packet->GetSize()<< std::endl;
}

void
ChangeSpeed(Ptr<Node>  n, Vector speed)
{
	n->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (speed);
}


int
main (int argc, char *argv[])
{
//	LogComponentEnable ("MmWaveUePhy", LOG_LEVEL_DEBUG);
//	LogComponentEnable ("MmWaveEnbPhy", LOG_LEVEL_DEBUG);
	LogComponentEnable ("MmWaveFlexTtiMacScheduler", LOG_LEVEL_DEBUG);

	Config::SetDefault ("ns3::LteRlcUmLowLat::MaxTxBufferSize", UintegerValue (1024 * 100));
	Config::SetDefault ("ns3::LteRlcAm::MaxTxBufferSize", UintegerValue (1024 * 100));
	//Config::SetDefault ("ns3::LteRlcUm::MaxTxBufferSize", UintegerValue (1024 * 100));
	//Config::SetDefault ("ns3::TcpSocket::SndBufSize", UintegerValue (131072*10));
	//Config::SetDefault ("ns3::TcpSocket::RcvBufSize", UintegerValue (131072*10));
	Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpNewReno::GetTypeId ()));
	//Config::SetDefault ("ns3::PointToPointEpcHelper::S1uLinkDelay", TimeValue (Seconds (0.010)));
	//Config::SetDefault ("ns3::MmWavePointToPointEpcHelper::S1uLinkDelay", TimeValue (Seconds (0.010)));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::ResourceBlockNum", UintegerValue(1));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::ChunkPerRB", UintegerValue(72));
	Config::SetDefault ("ns3::MmWavePhyMacCommon::TbDecodeLatency", UintegerValue(100.0));
	Config::SetDefault ("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::MmWaveHelper::HarqEnabled", BooleanValue(true));
	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(true));
	//Config::SetDefault ("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MilliSeconds(1.0)));
	//Config::SetDefault ("ns3::LteRlcUmLowLat::ReportBufferStatusTimer", TimeValue(MicroSeconds(100.0)));

    /*
     * scenario 1: 1 building;
     * scenario 2: 3 building;
     * scenario 3: 6 random located small building, simulate tree and human blockage.
     * */
  int scenario = 1;
	double stopTime = 25;
	double simStopTime = 25;


	Ptr<MmWaveHelper> mmwaveHelper = CreateObject<MmWaveHelper> ();
	//mmwaveHelper->SetSchedulerType ("ns3::MmWaveFlexTtiMaxWeightMacScheduler");
	mmwaveHelper->SetAttribute ("PathlossModel", StringValue ("ns3::BuildingsObstaclePropagationLossModel"));
	mmwaveHelper->Initialize();
	Ptr<MmWavePointToPointEpcHelper>  epcHelper = CreateObject<MmWavePointToPointEpcHelper> ();
	mmwaveHelper->SetEpcHelper (epcHelper);

	/*
	Ptr<LteHelper> mmwaveHelper = CreateObject<LteHelper> ();
	Ptr<PointToPointEpcHelper>  epcHelper = CreateObject<PointToPointEpcHelper> ();
	mmwaveHelper->SetEpcHelper (epcHelper);
*/

	Ptr<Node> pgw = epcHelper->GetPgwNode ();

	// Create a single RemoteHost
	NodeContainer remoteHostContainer;
	remoteHostContainer.Create (1);
	Ptr<Node> remoteHost = remoteHostContainer.Get (0);
	InternetStackHelper internet;
	internet.Install (remoteHostContainer);

	// Create the Internet
	PointToPointHelper p2ph;
	p2ph.SetDeviceAttribute ("DataRate", DataRateValue (DataRate ("100Gb/s")));
	p2ph.SetDeviceAttribute ("Mtu", UintegerValue (1500));
	p2ph.SetChannelAttribute ("Delay", TimeValue (Seconds (0.010)));
	NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);
	Ipv4AddressHelper ipv4h;
	ipv4h.SetBase ("1.0.0.0", "255.0.0.0");
	Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign (internetDevices);
	// interface 0 is localhost, 1 is the p2p device
	Ipv4Address remoteHostAddr;
	remoteHostAddr = internetIpIfaces.GetAddress (1);
	Ipv4StaticRoutingHelper ipv4RoutingHelper;
	Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
	remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.0.0.0"), 1);



	switch (scenario)
	{
		case 1:
		{
			Ptr < Building > building;
			building = Create<Building> ();
			building->SetBoundaries (Box (20.0,30.0,
										0.0, 7.3,
										0.0, 15.0));
			break;
		}
		case 2:
		{
			Ptr < Building > building1;
			building1 = Create<Building> ();
			building1->SetBoundaries (Box (30.0,32.0,
										0.0, 2.0,
										0.0, 1.5));

			Ptr < Building > building2;
			building2 = Create<Building> ();
			building2->SetBoundaries (Box (30.0,32.0,
										6.0, 8.0,
										0.0, 15.0));

			Ptr < Building > building3;
			building3 = Create<Building> ();
			building3->SetBoundaries (Box (30.0,32.0,
										10.0, 11.0,
										0.0, 15.0));
			break;
		}
		case 3:
		{
			Ptr < Building > building1;
			building1 = Create<Building> ();
			building1->SetBoundaries (Box (34.5,35.0,
										4.5, 5.0,
										0.0, 1.5));

			Ptr < Building > building2;
			building2 = Create<Building> ();
			building2->SetBoundaries (Box (30.0,30.5,
										9.5, 10.0,
										0.0, 1.5));

			Ptr < Building > building3;
			building3 = Create<Building> ();
			building3->SetBoundaries (Box (27.0,27.5,
										5.5, 6.0,
										0.0, 1.5));
			Ptr < Building > building4;
			building1 = Create<Building> ();
			building1->SetBoundaries (Box (30.0,30.5,
										6.0, 6.5,
										0.0, 1.5));

			Ptr < Building > building5;
			building2 = Create<Building> ();
			building2->SetBoundaries (Box (35.0,35.5,
										0.0, 0.5,
										0.0, 1.5));

			Ptr < Building > building6;
			building3 = Create<Building> ();
			building3->SetBoundaries (Box (25.0,25.5,
										4.0, 4.5,
										0.0, 1.5));
			break;
			break;
		}
		default:
		{
		    NS_FATAL_ERROR ("Invalid scenario");
		}
	}


	NodeContainer ueNodes;
	NodeContainer enbNodes;
	enbNodes.Create(1);
	ueNodes.Create(1);

	Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
	enbPositionAlloc->Add (Vector (0.0, 0.0, 3.0));
	MobilityHelper enbmobility;
	enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	enbmobility.SetPositionAllocator(enbPositionAlloc);
	enbmobility.Install (enbNodes);
	BuildingsHelper::Install (enbNodes);
	MobilityHelper uemobility;
	uemobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
	uemobility.Install (ueNodes);
	ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (40, -0.2, 1));
	ueNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (0, 0, 0));

	Simulator::Schedule (Seconds (5), &ChangeSpeed, ueNodes.Get (0), Vector (0, 1.5, 0));
	Simulator::Schedule (Seconds (15), &ChangeSpeed, ueNodes.Get (0), Vector (0, 0, 0));

	BuildingsHelper::Install (ueNodes);

	// Install LTE Devices to the nodes
	NetDeviceContainer enbDevs = mmwaveHelper->InstallEnbDevice (enbNodes);
	NetDeviceContainer ueDevs = mmwaveHelper->InstallUeDevice (ueNodes);

	// Install the IP stack on the UEs
	// Assign IP address to UEs, and install applications
	internet.Install (ueNodes);
	Ipv4InterfaceContainer ueIpIface;
	ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (ueDevs));

	mmwaveHelper->AttachToClosestEnb (ueDevs, enbDevs);
	mmwaveHelper->EnableTraces ();

	// Set the default gateway for the UE
	Ptr<Node> ueNode = ueNodes.Get (0);
	Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (ueNode->GetObject<Ipv4> ());
	ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);

	// Install and start applications on UEs and remote host
	uint16_t sinkPort = 20000;

	Address sinkAddress (InetSocketAddress (ueIpIface.GetAddress (0), sinkPort));
	PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), sinkPort));
	ApplicationContainer sinkApps = packetSinkHelper.Install (ueNodes.Get (0));

	sinkApps.Start (Seconds (0.));
	sinkApps.Stop (Seconds (simStopTime));

	Ptr<Socket> ns3TcpSocket = Socket::CreateSocket (remoteHostContainer.Get (0), TcpSocketFactory::GetTypeId ());
	Ptr<MyApp> app = CreateObject<MyApp> ();
	app->Setup (ns3TcpSocket, sinkAddress, 512, 1000000, DataRate ("1000Mb/s"));
	remoteHostContainer.Get (0)->AddApplication (app);
	AsciiTraceHelper asciiTraceHelper;
	Ptr<OutputStreamWrapper> stream1 = asciiTraceHelper.CreateFileStream ("mmWave-tcp-window.txt");
	ns3TcpSocket->TraceConnectWithoutContext ("CongestionWindow", MakeBoundCallback (&CwndChange, stream1));
	Ptr<OutputStreamWrapper> stream2 = asciiTraceHelper.CreateFileStream ("mmWave-tcp-data.txt");
	sinkApps.Get(0)->TraceConnectWithoutContext("Rx",MakeBoundCallback (&Rx, stream2));
	app->SetStartTime (Seconds (0.02));
	app->SetStopTime (Seconds (stopTime));


	//p2ph.EnablePcapAll("mmwave-sgi-capture");
	BuildingsHelper::MakeMobilityModelConsistent ();
	Config::Set ("/NodeList/*/DeviceList/*/TxQueue/MaxPackets", UintegerValue (1000*100));

	Simulator::Stop (Seconds (simStopTime));
	Simulator::Run ();
	Simulator::Destroy ();

	return 0;

}
