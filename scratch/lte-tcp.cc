#include <fstream>
#include "ns3/point-to-point-module.h"
#include "ns3/lte-helper.h"
#include "ns3/epc-helper.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/internet-module.h"
#include "ns3/mobility-module.h"
#include "ns3/lte-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/config-store.h"

//#include "ns3/gtk-config-store.h"

using namespace ns3;

/**
 * Sample simulation script for LTE+EPC. It instantiates several eNodeB,
 * attaches one UE per eNodeB starts a flow for each UE to  and from a remote host.
 * It also  starts yet another flow between each UE pair.
 */
NS_LOG_COMPONENT_DEFINE ("EpcFirstExample");


class MyApp : public Application
{
public:

  MyApp ();
  virtual ~MyApp();

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
int send_num=0;
int rev_num=1;
void
MyApp::SendPacket (void)
{
  Ptr<Packet> packet = Create<Packet> (m_packetSize);
  m_socket->Send (packet);
  send_num+= packet->GetSize();
  //NS_LOG_UNCOND ("Sending:    "<<send_num++ << "\t" << Simulator::Now ().GetSeconds ());
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

 //NS_LOG_UNCOND ("CwndChange: "<<Simulator::Now ().GetSeconds () << "\t" << newCwnd);
  *stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldCwnd << "\t" << newCwnd << std::endl;
}


static void 
Rx (Ptr<OutputStreamWrapper> stream,Ptr<const Packet> packet, const Address &from)
{
  //NS_LOG_UNCOND ("Receiving:  "<<rev_num++ << "\t" << Simulator::Now ().GetSeconds ());
  *stream->GetStream () << Simulator::Now ().GetSeconds () <<":    "<< packet->GetSize()<< std::endl;
}

unsigned int Send_bytes=0;
static void
TxTrace (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> p)
{
	Send_bytes+=p->GetSize();
	*stream->GetStream () << Simulator::Now ().GetSeconds () <<"    "<< Send_bytes<<std::endl;
}

static void
RTO_change (Ptr<OutputStreamWrapper> stream, Time old_rto,Time new_rto)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds ()<<"    "<< old_rto<<"    "<< new_rto<< std::endl;
}

static void
RTT_change (Ptr<OutputStreamWrapper> stream, Time old_rtt,Time new_rtt)
{
	*stream->GetStream () << Simulator::Now ().GetSeconds () <<"    "<< old_rtt.GetMilliSeconds()<<"     "<< new_rtt<< std::endl;
}

static void
RxDrop (Ptr<OutputStreamWrapper> stream, Ptr<const Packet> p)
{
  //NS_LOG_UNCOND ("RxDrop at " << Simulator::Now ().GetSeconds ());
  *stream->GetStream () << Simulator::Now ().GetSeconds ()<<"  "<<p->GetSize()<< std::endl;
}

void
ChangeErrorModel(Ptr<NetDevice> dev, Ptr<RateErrorModel> error)
{
  dev->SetAttribute ("ReceiveErrorModel", PointerValue (error));
}


int
main (int argc, char *argv[])
{
  Config::SetDefault ("ns3::LteRlcUm::MaxTxBufferSize", UintegerValue (1024 * 100));

  NS_LOG_UNCOND ("TEST!!!!!!!!!!!!!!!!!!!!!");
  //LogComponentEnable ("TcpSocketBase", LOG_LEVEL_INFO);
  //LogComponentEnable ("PacketSink", LOG_LEVEL_INFO);
  //LogComponentEnable ("LteUePhy", LOG_LEVEL_INFO);
  Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpNewReno::GetTypeId ()));
  //Config::SetDefault ("ns3::TcpL4Protocol::SocketType", TypeIdValue (TcpCubic::GetTypeId ()));



  uint16_t numberOfNodes = 1;
  


  Ptr<LteHelper> lteHelper = CreateObject<LteHelper> ();
  Ptr<PointToPointEpcHelper>  epcHelper = CreateObject<PointToPointEpcHelper> ();
  lteHelper->SetEpcHelper (epcHelper);
  lteHelper->SetSchedulerType("ns3::PfFfMacScheduler");

  ConfigStore inputConfig;
  inputConfig.ConfigureDefaults();



  Ptr<Node> pgw = epcHelper->GetPgwNode ();

   // Create a single RemoteHost
  NodeContainer remoteHostContainer;
  remoteHostContainer.Create (1);
  Ptr<Node> remoteHost = remoteHostContainer.Get (0);
  InternetStackHelper internet;
  internet.Install (remoteHostContainer);

  // Create the Internet
  PointToPointHelper p2ph;
  p2ph.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  p2ph.SetChannelAttribute ("Delay", StringValue ("40ms"));

  //p2ph.SetDeviceAttribute ("DataRate", StringValue ("10Gbps"));
  //p2ph.SetChannelAttribute ("Delay", TimeValue (Seconds (0.010)));
  
  NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);
  
  
  Ptr<RateErrorModel> em = CreateObject<RateErrorModel> ();
  em->SetAttribute ("ErrorRate", DoubleValue (0.0));
  internetDevices.Get (0)->SetAttribute ("ReceiveErrorModel", PointerValue (em));
  //Ptr<RateErrorModel> em1 = CreateObject<RateErrorModel> ();
  //em1->SetAttribute ("ErrorRate", DoubleValue (0.000005*2));
  //Simulator::Schedule (Seconds (5), &ChangeErrorModel, internetDevices.Get (0), em1);

  //Simulator::Schedule (Seconds (10), &ChangeErrorModel, internetDevices.Get (0), em);



  
  
  Ipv4AddressHelper ipv4h;
  ipv4h.SetBase ("1.0.0.0", "255.0.0.0");
  Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign (internetDevices);
  

  Ipv4StaticRoutingHelper ipv4RoutingHelper;
  Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
  remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.0.0.0"), 1);

  NodeContainer ueNodes;
  NodeContainer enbNodes;
  enbNodes.Create(numberOfNodes);
  ueNodes.Create(numberOfNodes);

  // Install Mobility Model
  Ptr<ListPositionAllocator> positionAlloc = CreateObject<ListPositionAllocator> ();

  positionAlloc->Add (Vector(0, 0, 0));

  MobilityHelper mobility;
  mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
  mobility.SetPositionAllocator(positionAlloc);
  mobility.Install(enbNodes);


  Ptr<ListPositionAllocator> ue_positionAlloc = CreateObject<ListPositionAllocator> ();
  ue_positionAlloc->Add (Vector(0, 0, 50));
  MobilityHelper ue1mobility;
  ue1mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  ue1mobility.SetPositionAllocator(ue_positionAlloc);
  ue1mobility.Install (ueNodes);

  // Install LTE Devices to the nodes
  NetDeviceContainer enbLteDevs = lteHelper->InstallEnbDevice (enbNodes);
  NetDeviceContainer ueLteDevs = lteHelper->InstallUeDevice (ueNodes);

  // Install the IP stack on the UEs
  internet.Install (ueNodes);
  Ipv4InterfaceContainer ueIpIface;
  ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (ueLteDevs));
  // Assign IP address to UEs, and install applications

  Ptr<Node> ueNode = ueNodes.Get (0);
  // Set the default gateway for the UE
  Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (ueNode->GetObject<Ipv4> ());
  ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);

  //enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
  //EpsBearer bearer (q);
  //lteHelper->ActivateDataRadioBearer (ueLteDevs, bearer);


  // Attach one UE per eNodeB
  lteHelper->Attach (ueLteDevs.Get(0), enbLteDevs.Get(0));

  

  uint16_t sinkPort = 8080;
  Address sinkAddress (InetSocketAddress (ueIpIface.GetAddress (0), sinkPort));
  PacketSinkHelper packetSinkHelper ("ns3::TcpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), sinkPort));
  ApplicationContainer sinkApps = packetSinkHelper.Install (ueNodes.Get (0));
  sinkApps.Start (Seconds (0.));
  sinkApps.Stop (Seconds (30.));

  Ptr<Socket> ns3TcpSocket = Socket::CreateSocket (remoteHostContainer.Get (0), TcpSocketFactory::GetTypeId ());

  Ptr<MyApp> app = CreateObject<MyApp> ();


  app->Setup (ns3TcpSocket, sinkAddress, 536, 1000000, DataRate ("10Mb/s"));



  remoteHostContainer.Get (0)->AddApplication (app);
  app->SetStartTime (Seconds (0.2));
  app->SetStopTime (Seconds (30.));

  AsciiTraceHelper asciiTraceHelper;
  Ptr<OutputStreamWrapper> stream = asciiTraceHelper.CreateFileStream ("lte-tcp-cwnd.txt");
  ns3TcpSocket->TraceConnectWithoutContext ("CongestionWindow", MakeBoundCallback (&CwndChange, stream));

  Ptr<OutputStreamWrapper> stream2 = asciiTraceHelper.CreateFileStream ("lte-tcp-rx.txt");
  sinkApps.Get(0)->TraceConnectWithoutContext("Rx",MakeBoundCallback (&Rx, stream2));

  Ptr<OutputStreamWrapper> stream3 = asciiTraceHelper.CreateFileStream ("lte-rtt.txt");
  ns3TcpSocket->TraceConnectWithoutContext("RTT",MakeBoundCallback (&RTT_change, stream3));

  Ptr<OutputStreamWrapper> stream4 = asciiTraceHelper.CreateFileStream ("lte-rto.txt");
  ns3TcpSocket->TraceConnectWithoutContext("RTO",MakeBoundCallback (&RTO_change, stream4));

  Ptr<OutputStreamWrapper> streamTx = asciiTraceHelper.CreateFileStream ("lte-tcp-TxTime.txt");
  internetDevices.Get (1)->TraceConnectWithoutContext ("PhyTxBegin", MakeBoundCallback (&TxTrace, streamTx));


  Ptr<OutputStreamWrapper> stream_drop = asciiTraceHelper.CreateFileStream ("lte-tcp-p2p_error.txt");
  internetDevices.Get (0)->TraceConnectWithoutContext ("PhyRxDrop", MakeBoundCallback (&RxDrop, stream_drop));
  
  Simulator::Stop (Seconds (30));
  Simulator::Run ();
  Simulator::Destroy ();

   return 0;

}

