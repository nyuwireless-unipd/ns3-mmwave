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

#include "ns3/applications-module.h"
#include "ns3/command-line.h"
#include "ns3/config-store.h"
#include "ns3/internet-module.h"
#include "ns3/isotropic-antenna-model.h"
#include "ns3/mmwave-helper.h"
#include "ns3/mmwave-point-to-point-epc-helper.h"
#include "ns3/mobility-module.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/point-to-point-module.h"
#include <ns3/buildings-helper.h>
#include <ns3/buildings-module.h>
#include <ns3/packet.h>
#include <ns3/queue-size.h>
#include <ns3/tag.h>

using namespace ns3;
using namespace mmwave;

/**
 * A script to simulate the DOWNLINK TCP data over mmWave links
 * with the mmWave devices and the LTE EPC.
 */
NS_LOG_COMPONENT_DEFINE("mmWaveTCPExample");

class MyAppTag : public Tag
{
  public:
    MyAppTag()
    {
    }

    MyAppTag(Time sendTs)
        : m_sendTs(sendTs)
    {
    }

    static TypeId GetTypeId(void)
    {
        static TypeId tid = TypeId("ns3::MyAppTag").SetParent<Tag>().AddConstructor<MyAppTag>();
        return tid;
    }

    virtual TypeId GetInstanceTypeId(void) const
    {
        return GetTypeId();
    }

    virtual void Serialize(TagBuffer i) const
    {
        i.WriteU64(m_sendTs.GetNanoSeconds());
    }

    virtual void Deserialize(TagBuffer i)
    {
        m_sendTs = NanoSeconds(i.ReadU64());
    }

    virtual uint32_t GetSerializedSize() const
    {
        return sizeof(m_sendTs);
    }

    virtual void Print(std::ostream& os) const
    {
        std::cout << m_sendTs;
    }

    Time m_sendTs;
};

class MyApp : public Application
{
  public:
    MyApp();
    virtual ~MyApp();
    void ChangeDataRate(DataRate rate);
    void Setup(Ptr<Socket> socket,
               Address address,
               uint32_t packetSize,
               uint32_t nPackets,
               DataRate dataRate);

  private:
    virtual void StartApplication(void);
    virtual void StopApplication(void);

    void ScheduleTx(void);
    void SendPacket(void);

    Ptr<Socket> m_socket;
    Address m_peer;
    uint32_t m_packetSize;
    uint32_t m_nPackets;
    DataRate m_dataRate;
    EventId m_sendEvent;
    bool m_running;
    uint32_t m_packetsSent;
};

MyApp::MyApp()
    : m_socket(0),
      m_peer(),
      m_packetSize(0),
      m_nPackets(0),
      m_dataRate(0),
      m_sendEvent(),
      m_running(false),
      m_packetsSent(0)
{
}

MyApp::~MyApp()
{
    m_socket = 0;
}

void
MyApp::Setup(Ptr<Socket> socket,
             Address address,
             uint32_t packetSize,
             uint32_t nPackets,
             DataRate dataRate)
{
    m_socket = socket;
    m_peer = address;
    m_packetSize = packetSize;
    m_nPackets = nPackets;
    m_dataRate = dataRate;
}

void
MyApp::ChangeDataRate(DataRate rate)
{
    m_dataRate = rate;
}

void
MyApp::StartApplication(void)
{
    m_running = true;
    m_packetsSent = 0;
    m_socket->Bind();
    m_socket->Connect(m_peer);
    SendPacket();
}

void
MyApp::StopApplication(void)
{
    m_running = false;

    if (m_sendEvent.IsRunning())
    {
        Simulator::Cancel(m_sendEvent);
    }

    if (m_socket)
    {
        m_socket->Close();
    }
}

void
MyApp::SendPacket(void)
{
    Ptr<Packet> packet = Create<Packet>(m_packetSize);
    MyAppTag tag(Simulator::Now());

    m_socket->Send(packet);
    if (++m_packetsSent < m_nPackets)
    {
        ScheduleTx();
    }
}

void
MyApp::ScheduleTx(void)
{
    if (m_running)
    {
        Time tNext(Seconds(m_packetSize * 8 / static_cast<double>(m_dataRate.GetBitRate())));
        m_sendEvent = Simulator::Schedule(tNext, &MyApp::SendPacket, this);
    }
}

static void
CwndChange(Ptr<OutputStreamWrapper> stream, uint32_t oldCwnd, uint32_t newCwnd)
{
    *stream->GetStream() << Simulator::Now().GetSeconds() << "\t" << oldCwnd << "\t" << newCwnd
                         << std::endl;
}

static void
RttChange(Ptr<OutputStreamWrapper> stream, Time oldRtt, Time newRtt)
{
    *stream->GetStream() << Simulator::Now().GetSeconds() << "\t" << oldRtt.GetSeconds() << "\t"
                         << newRtt.GetSeconds() << std::endl;
}

static void
Rx(Ptr<OutputStreamWrapper> stream, Ptr<const Packet> packet, const Address& from)
{
    *stream->GetStream() << Simulator::Now().GetSeconds() << "\t" << packet->GetSize() << std::endl;
}

/*static void Sstresh (Ptr<OutputStreamWrapper> stream, uint32_t oldSstresh, uint32_t newSstresh)
{
        *stream->GetStream () << Simulator::Now ().GetSeconds () << "\t" << oldSstresh << "\t" <<
newSstresh << std::endl;
}*/

void
ChangeSpeed(Ptr<Node> n, Vector speed)
{
    n->GetObject<ConstantVelocityMobilityModel>()->SetVelocity(speed);
}

int
main(int argc, char* argv[])
{
    /*
     * scenario 1: 1 building;
     * scenario 2: 3 building;
     * scenario 3: 6 random located small building, simulate tree and human blockage.
     * */
    int scenario = 1;
    double stopTime = 1.0;
    double simStopTime = 1.5;
    bool harqEnabled = true;
    bool rlcAmEnabled = true;
    bool tcp = true;

    CommandLine cmd;
    cmd.AddValue("simTime", "Total duration of the simulation [s])", simStopTime);
    cmd.AddValue("harq", "Enable Hybrid ARQ", harqEnabled);
    cmd.AddValue("rlcAm", "Enable RLC-AM", rlcAmEnabled);
    cmd.Parse(argc, argv);

    // TCP settings
    Config::SetDefault("ns3::TcpL4Protocol::SocketType", TypeIdValue(TcpCubic::GetTypeId()));
    Config::SetDefault("ns3::TcpSocketBase::MinRto", TimeValue(MilliSeconds(200)));
    Config::SetDefault("ns3::Ipv4L3Protocol::FragmentExpirationTimeout", TimeValue(Seconds(0.2)));
    Config::SetDefault("ns3::TcpSocket::SegmentSize", UintegerValue(2500));
    Config::SetDefault("ns3::TcpSocket::DelAckCount", UintegerValue(1));
    Config::SetDefault("ns3::TcpSocket::SndBufSize", UintegerValue(131072 * 50));
    Config::SetDefault("ns3::TcpSocket::RcvBufSize", UintegerValue(131072 * 50));

    Config::SetDefault("ns3::LteRlcUm::MaxTxBufferSize", UintegerValue(1024 * 1024));
    Config::SetDefault("ns3::LteRlcUmLowLat::MaxTxBufferSize", UintegerValue(1024 * 1024));
    Config::SetDefault("ns3::LteRlcAm::MaxTxBufferSize", UintegerValue(1024 * 1024));
    Config::SetDefault("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue(rlcAmEnabled));
    Config::SetDefault("ns3::MmWaveHelper::HarqEnabled", BooleanValue(harqEnabled));
    Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(true));
    Config::SetDefault("ns3::MmWaveFlexTtiMaxWeightMacScheduler::HarqEnabled", BooleanValue(true));
    Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(true));
    Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(100.0)));
    Config::SetDefault("ns3::LteRlcAm::PollRetransmitTimer", TimeValue(MilliSeconds(4.0)));
    Config::SetDefault("ns3::LteRlcAm::ReorderingTimer", TimeValue(MilliSeconds(2.0)));
    Config::SetDefault("ns3::LteRlcAm::StatusProhibitTimer", TimeValue(MilliSeconds(1.0)));
    Config::SetDefault("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MilliSeconds(4.0)));
    Config::SetDefault("ns3::LteRlcAm::MaxTxBufferSize", UintegerValue(20 * 1024 * 1024));

    // by default, isotropic antennas are used. To use the 3GPP radiation pattern instead, use the
    // <ThreeGppAntennaArrayModel> beware: proper configuration of the bearing and downtilt angles
    // is needed
    Config::SetDefault("ns3::PhasedArrayModel::AntennaElement",
                       PointerValue(CreateObject<IsotropicAntennaModel>()));

    Ptr<MmWaveHelper> mmwaveHelper = CreateObject<MmWaveHelper>();

    mmwaveHelper->SetChannelConditionModelType("ns3::BuildingsChannelConditionModel");
    mmwaveHelper->Initialize();
    mmwaveHelper->SetHarqEnabled(true);

    Ptr<MmWavePointToPointEpcHelper> epcHelper = CreateObject<MmWavePointToPointEpcHelper>();
    mmwaveHelper->SetEpcHelper(epcHelper);

    Ptr<Node> pgw = epcHelper->GetPgwNode();

    // Create a single RemoteHost
    NodeContainer remoteHostContainer;
    remoteHostContainer.Create(1);
    Ptr<Node> remoteHost = remoteHostContainer.Get(0);
    InternetStackHelper internet;
    internet.Install(remoteHostContainer);

    // Create the Internet
    PointToPointHelper p2ph;
    p2ph.SetDeviceAttribute("DataRate", DataRateValue(DataRate("100Gb/s")));
    p2ph.SetDeviceAttribute("Mtu", UintegerValue(1500));
    p2ph.SetChannelAttribute("Delay", TimeValue(Seconds(0.010)));
    NetDeviceContainer internetDevices = p2ph.Install(pgw, remoteHost);
    Ipv4AddressHelper ipv4h;
    ipv4h.SetBase("1.0.0.0", "255.0.0.0");
    Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign(internetDevices);
    // interface 0 is localhost, 1 is the p2p device
    Ipv4Address remoteHostAddr;
    remoteHostAddr = internetIpIfaces.GetAddress(1);
    Ipv4StaticRoutingHelper ipv4RoutingHelper;
    Ptr<Ipv4StaticRouting> remoteHostStaticRouting =
        ipv4RoutingHelper.GetStaticRouting(remoteHost->GetObject<Ipv4>());
    remoteHostStaticRouting->AddNetworkRouteTo(Ipv4Address("7.0.0.0"), Ipv4Mask("255.0.0.0"), 1);

    switch (scenario)
    {
    case 1: {
        Ptr<Building> building;
        building = Create<Building>();
        building->SetBoundaries(Box(40.0, 60.0, 0.0, 6, 0.0, 15.0));
        break;
    }
    case 2: {
        Ptr<Building> building1;
        building1 = Create<Building>();
        building1->SetBoundaries(Box(60.0, 64.0, 0.0, 2.0, 0.0, 1.5));

        Ptr<Building> building2;
        building2 = Create<Building>();
        building2->SetBoundaries(Box(60.0, 64.0, 6.0, 8.0, 0.0, 15.0));

        Ptr<Building> building3;
        building3 = Create<Building>();
        building3->SetBoundaries(Box(60.0, 64.0, 10.0, 11.0, 0.0, 15.0));
        break;
    }
    case 3: {
        Ptr<Building> building1;
        building1 = Create<Building>();
        building1->SetBoundaries(Box(69.5, 70.0, 4.5, 5.0, 0.0, 1.5));

        Ptr<Building> building2;
        building2 = Create<Building>();
        building2->SetBoundaries(Box(60.0, 60.5, 9.5, 10.0, 0.0, 1.5));

        Ptr<Building> building3;
        building3 = Create<Building>();
        building3->SetBoundaries(Box(54.0, 54.5, 5.5, 6.0, 0.0, 1.5));
        Ptr<Building> building4;
        building1 = Create<Building>();
        building1->SetBoundaries(Box(60.0, 60.5, 6.0, 6.5, 0.0, 1.5));

        Ptr<Building> building5;
        building2 = Create<Building>();
        building2->SetBoundaries(Box(70.0, 70.5, 0.0, 0.5, 0.0, 1.5));

        Ptr<Building> building6;
        building3 = Create<Building>();
        building3->SetBoundaries(Box(50.0, 50.5, 4.0, 4.5, 0.0, 1.5));
        break;
        break;
    }
    default: {
        NS_FATAL_ERROR("Invalid scenario");
    }
    }

    NodeContainer ueNodes;
    NodeContainer enbNodes;
    enbNodes.Create(1);
    ueNodes.Create(1);

    Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator>();
    enbPositionAlloc->Add(Vector(0.0, 0.0, 25.0));
    MobilityHelper enbmobility;
    enbmobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    enbmobility.SetPositionAllocator(enbPositionAlloc);
    enbmobility.Install(enbNodes);
    BuildingsHelper::Install(enbNodes);
    MobilityHelper uemobility;
    uemobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");
    uemobility.Install(ueNodes);

    ueNodes.Get(0)->GetObject<MobilityModel>()->SetPosition(Vector(70, -2.0, 1.8));
    ueNodes.Get(0)->GetObject<ConstantVelocityMobilityModel>()->SetVelocity(Vector(0, 1.0, 0));

    Simulator::Schedule(Seconds(0.5), &ChangeSpeed, ueNodes.Get(0), Vector(0, 1.5, 0));
    Simulator::Schedule(Seconds(1.0), &ChangeSpeed, ueNodes.Get(0), Vector(0, 0, 0));

    BuildingsHelper::Install(ueNodes);

    // Install LTE Devices to the nodes
    NetDeviceContainer enbDevs = mmwaveHelper->InstallEnbDevice(enbNodes);
    NetDeviceContainer ueDevs = mmwaveHelper->InstallUeDevice(ueNodes);

    // Install the IP stack on the UEs
    // Assign IP address to UEs, and install applications
    internet.Install(ueNodes);
    Ipv4InterfaceContainer ueIpIface;
    ueIpIface = epcHelper->AssignUeIpv4Address(NetDeviceContainer(ueDevs));

    mmwaveHelper->AttachToClosestEnb(ueDevs, enbDevs);
    mmwaveHelper->EnableTraces();

    // Set the default gateway for the UE
    Ptr<Node> ueNode = ueNodes.Get(0);
    Ptr<Ipv4StaticRouting> ueStaticRouting =
        ipv4RoutingHelper.GetStaticRouting(ueNode->GetObject<Ipv4>());
    ueStaticRouting->SetDefaultRoute(epcHelper->GetUeDefaultGatewayAddress(), 1);

    if (tcp)
    {
        // Install and start applications on UEs and remote host
        uint16_t sinkPort = 20000;

        Address sinkAddress(InetSocketAddress(ueIpIface.GetAddress(0), sinkPort));
        PacketSinkHelper packetSinkHelper("ns3::TcpSocketFactory",
                                          InetSocketAddress(Ipv4Address::GetAny(), sinkPort));
        ApplicationContainer sinkApps = packetSinkHelper.Install(ueNodes.Get(0));

        sinkApps.Start(Seconds(0.));
        sinkApps.Stop(Seconds(simStopTime));

        Ptr<Socket> ns3TcpSocket =
            Socket::CreateSocket(remoteHostContainer.Get(0), TcpSocketFactory::GetTypeId());
        Ptr<MyApp> app = CreateObject<MyApp>();
        app->Setup(ns3TcpSocket, sinkAddress, 1400, 5000000, DataRate("500Mb/s"));

        remoteHostContainer.Get(0)->AddApplication(app);
        AsciiTraceHelper asciiTraceHelper;
        Ptr<OutputStreamWrapper> stream1 =
            asciiTraceHelper.CreateFileStream("mmWave-tcp-window-newreno.txt");
        ns3TcpSocket->TraceConnectWithoutContext("CongestionWindow",
                                                 MakeBoundCallback(&CwndChange, stream1));

        Ptr<OutputStreamWrapper> stream4 =
            asciiTraceHelper.CreateFileStream("mmWave-tcp-rtt-newreno.txt");
        ns3TcpSocket->TraceConnectWithoutContext("RTT", MakeBoundCallback(&RttChange, stream4));

        Ptr<OutputStreamWrapper> stream2 =
            asciiTraceHelper.CreateFileStream("mmWave-tcp-data-newreno.txt");
        sinkApps.Get(0)->TraceConnectWithoutContext("Rx", MakeBoundCallback(&Rx, stream2));

        // Ptr<OutputStreamWrapper> stream3 = asciiTraceHelper.CreateFileStream
        // ("mmWave-tcp-sstresh-newreno.txt");
        // ns3TcpSocket->TraceConnectWithoutContext("SlowStartThreshold",MakeBoundCallback
        // (&Sstresh, stream3));
        app->SetStartTime(Seconds(0.1));
        app->SetStopTime(Seconds(stopTime));
    }
    else
    {
        // Install and start applications on UEs and remote host
        uint16_t sinkPort = 20000;

        Address sinkAddress(InetSocketAddress(ueIpIface.GetAddress(0), sinkPort));
        PacketSinkHelper packetSinkHelper("ns3::UdpSocketFactory",
                                          InetSocketAddress(Ipv4Address::GetAny(), sinkPort));
        ApplicationContainer sinkApps = packetSinkHelper.Install(ueNodes.Get(0));

        sinkApps.Start(Seconds(0.));
        sinkApps.Stop(Seconds(simStopTime));

        Ptr<Socket> ns3UdpSocket =
            Socket::CreateSocket(remoteHostContainer.Get(0), UdpSocketFactory::GetTypeId());
        Ptr<MyApp> app = CreateObject<MyApp>();
        app->Setup(ns3UdpSocket, sinkAddress, 1400, 5000000, DataRate("500Mb/s"));

        remoteHostContainer.Get(0)->AddApplication(app);
        AsciiTraceHelper asciiTraceHelper;
        Ptr<OutputStreamWrapper> stream2 =
            asciiTraceHelper.CreateFileStream("mmWave-udp-data-am.txt");
        sinkApps.Get(0)->TraceConnectWithoutContext("Rx", MakeBoundCallback(&Rx, stream2));

        app->SetStartTime(Seconds(0.1));
        app->SetStopTime(Seconds(stopTime));
    }

    // p2ph.EnablePcapAll("mmwave-sgi-capture");
    Config::Set("/NodeList/*/DeviceList/*/TxQueue/MaxSize", QueueSizeValue(QueueSize("100000p")));

    Simulator::Stop(Seconds(simStopTime));
    Simulator::Run();
    Simulator::Destroy();

    return 0;
}
