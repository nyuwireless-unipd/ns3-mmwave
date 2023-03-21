/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

//
// Handoff scenario with Multipath TCPed iperf
//
// Simulation Topology:
// Scenario:
//
//   <--------------------            ----------------------->
//                  LTE               Ethernet
//                   sim0 +----------+ sim1
//                  +------|  LTE  R  |------+
//                  |     +----------+      |
//              +---+                       +-----+
//          sim1|                                 |sim1
//     +----+---+                                 +----+---+
//     |   H1   |           co-located            |   H2   |
//     +---+----+           (0, 0, 3)           +----+---+
//          sim0|                                 |sim0
//              +--+                        +-----+
//                 | sim0 +----------+ sim1 |
//                  +-----|  MmWave R  |------+
//                        +----------+
//                  MmWave              Ethernet
//   <--------------------            ----------------------->

// Author: Michele Polese michele.polese@gmail.com

#include "ns3/applications-module.h"
#include "ns3/buildings-module.h"
#include "ns3/config-store-module.h"
#include "ns3/constant-position-mobility-model.h"
#include "ns3/core-module.h"
#include "ns3/dce-module.h"
#include "ns3/internet-module.h"
#include "ns3/lte-module.h"
#include "ns3/mmwave-module.h"
#include "ns3/mobility-module.h"
#include "ns3/netanim-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/wifi-module.h"

#include <ctime>
#include <iostream>
#include <sstream>
#include <stdlib.h>

#define SSTR(x) static_cast<std::ostringstream&>((std::ostringstream() << std::dec << x)).str()

using namespace ns3;
NS_LOG_COMPONENT_DEFINE("DceMptcpMmWave");

void
setPos(Ptr<Node> n, int x, int y, int z)
{
    Ptr<ConstantVelocityMobilityModel> loc = CreateObject<ConstantVelocityMobilityModel>();
    n->AggregateObject(loc);
    Vector locVec2(x, y, z);
    loc->SetPosition(locVec2);
    loc->SetVelocity(Vector(0, 0, 0));
}

void
randomPos(Ptr<Node> n, int R_max, int z)
{
    Ptr<UniformRandomVariable> rand = CreateObject<UniformRandomVariable>();
    // already U[0,1] by default
    double rho = R_max * std::sqrt(rand->GetValue());
    double theta = rand->GetValue();
    double x = rho * std::cos(theta);
    double y = rho * std::sin(theta);
    Ptr<ConstantPositionMobilityModel> loc = CreateObject<ConstantPositionMobilityModel>();
    n->AggregateObject(loc);
    Vector locVec2(x, y, z);
    NS_LOG_UNCOND("UE in Position " << locVec2);
    loc->SetPosition(locVec2);
}

void
changePos(Ptr<Node> node, int x, int y, int z)
{
    Ptr<ConstantVelocityMobilityModel> model = node->GetObject<ConstantVelocityMobilityModel>();
    Vector locVec2(x, y, z);
    model->SetPosition(locVec2);
    model->SetVelocity(Vector(0, 0, 0));
    NS_LOG_UNCOND("************************--------------------Change "
                  "Position-------------------------------*****************");
}

void
ChangeSpeed(Ptr<Node> n, Vector speed)
{
    n->GetObject<ConstantVelocityMobilityModel>()->SetVelocity(speed);
    NS_LOG_UNCOND("************************--------------------Change "
                  "Speed-------------------------------*****************");
}

void
PrintTcpFlags(std::string key, std::string value)
{
    NS_LOG_INFO(key << "=" << value);
}

void
PrintPid(ApplicationContainer apps, DceApplicationHelper dce)
{
    NS_LOG_UNCOND("PID " << dce.GetPid(PeekPointer(apps.Get(0))));
}

static ns3::GlobalValue g_dist("dist",
                               "Distance from eNB",
                               ns3::UintegerValue(190),
                               ns3::MakeUintegerChecker<uint32_t>());
static ns3::GlobalValue g_outPath("outPath",
                                  "The path of output log files",
                                  ns3::StringValue("./"),
                                  ns3::MakeStringChecker());
static ns3::GlobalValue g_congestionControl("congestionControl",
                                            "CC algorithm",
                                            ns3::StringValue("cubic"),
                                            ns3::MakeStringChecker());
static ns3::GlobalValue g_rlcAmEnabled("rlcAmEnabled",
                                       "If true, use RLC AM, else use RLC UM",
                                       ns3::BooleanValue(true),
                                       ns3::MakeBooleanChecker());
static ns3::GlobalValue g_harqEnabled("harqEnabled",
                                      "If true, enable harq",
                                      ns3::BooleanValue(true),
                                      ns3::MakeBooleanChecker());

int
main(int argc, char* argv[])
{
    LogComponentEnable("DceMptcpMmWave", LOG_LEVEL_ALL);

    // Command line arguments
    CommandLine cmd;
    // cmd.AddValue("numberOfNodes", "Number of eNodeBs + UE pairs", numberOfNodes);
    // cmd.AddValue("simTime", "Total duration of the simulation [s])", simTime);
    // cmd.AddValue("interPacketInterval", "Inter packet interval [ms])", interPacketInterval);
    cmd.Parse(argc, argv);

    std::string bufSize = "";
    double stopTime = 23.0;
    std::string p2pdelay = "0ms";

    UintegerValue uintegerValue;
    StringValue stringValue;
    BooleanValue booleanValue;

    GlobalValue::GetValueByName("outPath", stringValue);
    std::string path = stringValue.Get();
    NS_LOG_UNCOND(path);
    std::string dlRlcOutName = "DlRlcStats";
    std::string dlPdcpOutName = "DlPdcpStats";
    std::string ulRlcOutName = "UlRlcStats";
    std::string ulPdcpOutName = "UlPdcpStats";
    std::string extension = ".txt";

    // get current time
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%d_%m_%Y_%I_%M_%S", timeinfo);
    std::string time_str(buffer);

    // Congestion Control algorithm
    GlobalValue::GetValueByName("congestionControl", stringValue);
    std::string ccAlg = stringValue.Get();

    // mmWave config
    GlobalValue::GetValueByName("harqEnabled", booleanValue);
    bool harqEnabled = booleanValue.Get();
    GlobalValue::GetValueByName("rlcAmEnabled", booleanValue);
    bool rlcAmEnabled = booleanValue.Get();
    bool fixedTti = false;
    uint32_t bufferSize = 10;

    Config::SetDefault("ns3::LteRlcUm::MaxTxBufferSize", UintegerValue(20 * 1024 * 1024));
    Config::SetDefault("ns3::LteRlcUmLowLat::MaxTxBufferSize", UintegerValue(20 * 1024 * 1024));
    Config::SetDefault("ns3::LteRlcAm::MaxTxBufferSize", UintegerValue(20 * 1024 * 1024));
    Config::SetDefault("ns3::LteHelper::UseIdealRrc", BooleanValue(false));

    Config::SetDefault("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue(rlcAmEnabled));
    Config::SetDefault("ns3::MmWaveHelper::HarqEnabled", BooleanValue(harqEnabled));
    Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(harqEnabled));
    Config::SetDefault("ns3::MmWaveFlexTtiMaxWeightMacScheduler::HarqEnabled",
                       BooleanValue(harqEnabled));
    Config::SetDefault("ns3::MmWaveFlexTtiMaxWeightMacScheduler::FixedTti", BooleanValue(fixedTti));
    Config::SetDefault("ns3::MmWaveFlexTtiMaxWeightMacScheduler::SymPerSlot", UintegerValue(6));
    Config::SetDefault("ns3::MmWavePhyMacCommon::TbDecodeLatency", UintegerValue(200.0));
    Config::SetDefault("ns3::MmWavePhyMacCommon::NumHarqProcess", UintegerValue(100));
    Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(MilliSeconds(100.0)));
    Config::SetDefault("ns3::LteEnbRrc::SystemInformationPeriodicity",
                       TimeValue(MilliSeconds(5.0)));
    Config::SetDefault("ns3::LteEnbRrc::SrsPeriodicity", UintegerValue(320));
    Config::SetDefault("ns3::LteEnbRrc::FirstSibTime", UintegerValue(2));
    Config::SetDefault("ns3::LteHelper::UseIdealRrc", BooleanValue(false));
    Config::SetDefault("ns3::MmWavePointToPointEpcHelper::S1uLinkDelay", TimeValue(Seconds(0.001)));
    Config::SetDefault("ns3::PointToPointEpcHelper::S1uLinkDelay", TimeValue(Seconds(0.001)));

    GlobalValue::Bind("ChecksumEnabled", BooleanValue(true));
    NodeContainer nodes, routers;
    uint32_t numberOfNodes = 1;
    nodes.Create(numberOfNodes * 2);
    routers.Create(1);

    DceManagerHelper dceManager;
    dceManager.SetNetworkStack("ns3::LinuxSocketFdFactory", "Library", StringValue("liblinux.so"));
    LinuxStackHelper stack;
    stack.Install(nodes);
    stack.Install(routers);

    dceManager.Install(nodes);
    dceManager.Install(routers);

    PointToPointHelper pointToPoint;
    NetDeviceContainer devices1, devices2, devices3;

    // mmWave helper
    Ptr<MmWaveHelper> mmWaveHelper = CreateObject<MmWaveHelper>();
    mmWaveHelper->SetAttribute("BasicCellId", UintegerValue(0));
    mmWaveHelper->SetAttribute("BasicImsi", UintegerValue(0));
    mmWaveHelper->SetHarqEnabled(harqEnabled);
    mmWaveHelper->SetChannelConditionModelType("ns3::BuildingsChannelConditionModel");
    mmWaveHelper->Initialize();
    mmWaveHelper->SetPhyMacConfigurationParameters("CenterFreq", "28e9");
    Ptr<MmWavePointToPointEpcHelper> mmWaveEpcHelper = CreateObject<MmWavePointToPointEpcHelper>();
    mmWaveEpcHelper->SetAttribute("UeBaseAddress", StringValue("7.0.0.0"));
    mmWaveEpcHelper->SetAttribute("X2BaseAddress", StringValue("15.0.0.0"));
    mmWaveEpcHelper->SetAttribute("S1apBaseAddress", StringValue("16.0.0.0"));
    mmWaveEpcHelper->SetAttribute("S1uBaseAddress", StringValue("17.0.0.0"));
    mmWaveEpcHelper->Initialize();

    // LTE helper
    Ptr<LteHelper> lteHelper_2 = CreateObject<LteHelper>();
    lteHelper_2->SetAttribute("BasicCellId", UintegerValue(2));
    lteHelper_2->SetAttribute("BasicImsi", UintegerValue(numberOfNodes));
    lteHelper_2->SetAttribute("PathlossModel",
                              StringValue("ns3::HybridBuildingsPropagationLossModel"));
    lteHelper_2->SetPathlossModelAttribute("ShadowSigmaExtWalls", DoubleValue(0));
    lteHelper_2->SetPathlossModelAttribute("ShadowSigmaOutdoor", DoubleValue(6));
    lteHelper_2->SetPathlossModelAttribute("ShadowSigmaIndoor", DoubleValue(8));
    lteHelper_2->SetSpectrumChannelType("ns3::MultiModelSpectrumChannel");
    Ptr<PointToPointEpcHelper> epcHelper_2 = CreateObject<PointToPointEpcHelper>();
    epcHelper_2->SetAttribute("UeBaseAddress", StringValue("8.0.0.0"));
    epcHelper_2->SetAttribute("X2BaseAddress", StringValue("10.0.0.0"));
    epcHelper_2->SetAttribute("S1apBaseAddress", StringValue("11.0.0.0"));
    epcHelper_2->SetAttribute("S1uBaseAddress", StringValue("12.0.0.0"));
    epcHelper_2->Initialize();

    Ipv4AddressHelper address1, address2, address3;
    std::ostringstream cmd_oss;
    address1.SetBase("10.1.0.0", "255.255.255.0");
    address2.SetBase("10.2.0.0", "255.255.255.0");
    address3.SetBase("10.3.0.0", "255.255.255.0");
    Ipv4InterfaceContainer if1, if2, if3;
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("20Gbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue(p2pdelay));
    Ptr<RateErrorModel> em1 = CreateObjectWithAttributes<RateErrorModel>(
        "RanVar",
        StringValue("ns3::UniformRandomVariable[Min=0.0,Max=1.0]"),
        "ErrorRate",
        DoubleValue(0),
        "ErrorUnit",
        EnumValue(RateErrorModel::ERROR_UNIT_PACKET));

    NodeContainer ueNodes;
    NodeContainer serverNodes;
    // set UE distance
    for (uint32_t i = 0; i < numberOfNodes; i++)
    {
        setPos(nodes.Get(i), 100, -20, 1);
        setPos(nodes.Get(numberOfNodes + i), 200, 200, 0);
        ueNodes.Add(nodes.Get(i));
        serverNodes.Add(nodes.Get(i + numberOfNodes));
    }

    double x_min = 80.0;
    double x_max = 90.0;
    double y_min = -10.0;
    double y_max = 10.0;
    double z_min = 0.0;
    double z_max = 10.0;
    Ptr<Building> b = CreateObject<Building>();
    b->SetBoundaries(Box(x_min, x_max, y_min, y_max, z_min, z_max));
    b->SetBuildingType(Building::Residential);
    b->SetExtWallsType(Building::ConcreteWithWindows);
    b->SetNFloors(3);
    b->SetNRoomsX(3);
    b->SetNRoomsY(2);

    BuildingsHelper::Install(nodes);

    Simulator::Schedule(Seconds(2),
                        &ChangeSpeed,
                        nodes.Get(0),
                        Vector(0, 2, 0)); // start UE movement

    // Left link: H1 <-> mmWave eNB
    NodeContainer enbNodes;
    enbNodes.Create(1);

    mmWaveHelper->SetEpcHelper(mmWaveEpcHelper);
    Ptr<Node> pgw = mmWaveEpcHelper->GetPgwNode();
    setPos(enbNodes.Get(0), 0, 0, 3);
    BuildingsHelper::Install(enbNodes);

    NetDeviceContainer enbMmWaveDevs = mmWaveHelper->InstallEnbDevice(enbNodes);
    NetDeviceContainer ueMmWaveDevs = mmWaveHelper->InstallUeDevice(ueNodes);

    // Assign ip addresses
    if1 = mmWaveEpcHelper->AssignUeIpv4Address(NetDeviceContainer(ueMmWaveDevs));
    mmWaveHelper->AttachToClosestEnb(ueMmWaveDevs, enbMmWaveDevs);

    // setup ip routes
    for (uint32_t i = 0; i < numberOfNodes; i++)
    {
        cmd_oss.str("");
        cmd_oss << "rule add from " << if1.GetAddress(i, 0) << " table " << 1;
        NS_LOG_UNCOND("rule add from " << if1.GetAddress(i, 0) << " table " << 1 << " node "
                                       << nodes.Get(i));
        LinuxStackHelper::RunIp(nodes.Get(i), Seconds(0.01), cmd_oss.str().c_str());
        cmd_oss.str("");
        cmd_oss << "route add default via "
                << "7.0.0. " << i << " dev sim" << 0 << " table " << 1;
        NS_LOG_UNCOND("route add default via "
                      << "7.0.0.1 " << i << " dev sim" << ueMmWaveDevs.Get(i)->GetIfIndex()
                      << " table " << 1 << " node " << nodes.Get(i));
        LinuxStackHelper::RunIp(nodes.Get(i), Seconds(0.01), cmd_oss.str().c_str());
    }

    for (uint32_t i = 0; i < numberOfNodes; i++)
    {
        devices2 = pointToPoint.Install(serverNodes.Get(i), pgw);
        if2 = address2.Assign(devices2);
        address2.NewNetwork();

        NS_LOG_UNCOND("if2.GetAddress (0, 0) " << if2.GetAddress(0, 0));
        NS_LOG_UNCOND("if2.GetAddress (1, 0) " << if2.GetAddress(1, 0));
        cmd_oss.str("");
        cmd_oss << "rule add from " << if2.GetAddress(0, 0) << " table " << (1);
        NS_LOG_UNCOND("rule add from " << if2.GetAddress(0, 0) << " table " << (1) << " node "
                                       << serverNodes.Get(i));
        LinuxStackHelper::RunIp(serverNodes.Get(i), Seconds(0.01), cmd_oss.str().c_str());
        cmd_oss.str("");
        cmd_oss << "route add 10.2." << i << ".0/24 dev sim" << 0 << " scope link table " << (1);
        NS_LOG_UNCOND("route add 10.2." << i << ".0/24 dev sim" << 0 << " scope link table " << (1)
                                        << " node " << serverNodes.Get(i));
        LinuxStackHelper::RunIp(serverNodes.Get(i), Seconds(0.01), cmd_oss.str().c_str());
    }

    // ------------------------ link: H1 <-> LTE-R
    NodeContainer lteEnbNodes;
    lteEnbNodes.Create(1);

    lteHelper_2->SetEpcHelper(epcHelper_2);
    pgw = epcHelper_2->GetPgwNode();
    setPos(lteEnbNodes.Get(0), 0, 0, 3);
    BuildingsHelper::Install(lteEnbNodes);
    // Simulator::Schedule(Seconds(10.0), &changePos, lteEnbNodes.Get (0), 60, +15000, 3);

    NetDeviceContainer enbLteDevs = lteHelper_2->InstallEnbDevice(lteEnbNodes);
    NetDeviceContainer ueLteDevs = lteHelper_2->InstallUeDevice(ueNodes);

    // Assign ip addresses
    if1 = epcHelper_2->AssignUeIpv4Address(NetDeviceContainer(ueLteDevs));
    lteHelper_2->Attach(ueLteDevs, enbLteDevs.Get(0));

    // setup ip routes
    for (uint32_t i = 0; i < numberOfNodes; i++)
    {
        cmd_oss.str("");
        cmd_oss << "rule add from " << if1.GetAddress(i, 0) << " table " << 2;
        NS_LOG_UNCOND("rule add from " << if1.GetAddress(i, 0) << " table " << 2 << " node "
                                       << nodes.Get(i));
        LinuxStackHelper::RunIp(nodes.Get(i), Seconds(0.01), cmd_oss.str().c_str());
        cmd_oss.str("");
        cmd_oss << "route add default via "
                << "8.0.0.1 "
                << " dev sim" << ueLteDevs.Get(i)->GetIfIndex() << " table " << 2;
        NS_LOG_UNCOND("route add default via "
                      << "8.0.0.1 "
                      << " dev sim" << ueLteDevs.Get(i)->GetIfIndex() << " table " << 2 << " node "
                      << nodes.Get(i));
        LinuxStackHelper::RunIp(nodes.Get(i), Seconds(0.01), cmd_oss.str().c_str());
    }

    for (uint32_t i = 0; i < numberOfNodes; i++)
    {
        devices3 = pointToPoint.Install(serverNodes.Get(i), pgw);
        if3 = address2.Assign(devices3);
        address2.NewNetwork();

        NS_LOG_UNCOND("if3.GetAddress (0, 0) " << if3.GetAddress(0, 0));
        NS_LOG_UNCOND("if3.GetAddress (1, 0) " << if3.GetAddress(1, 0));
        cmd_oss.str("");
        cmd_oss << "rule add from " << if3.GetAddress(0, 0) << " table " << (2);
        NS_LOG_UNCOND("rule add from " << if3.GetAddress(0, 0) << " table " << (2) << " node "
                                       << serverNodes.Get(i));
        LinuxStackHelper::RunIp(serverNodes.Get(i), Seconds(0.01), cmd_oss.str().c_str());
        cmd_oss.str("");
        cmd_oss << "route add 10.2." << i << ".0/24 dev sim" << 0 << " scope link table " << (2);
        NS_LOG_UNCOND("route add 10.2." << i << ".0/24 dev sim" << 0 << " scope link table " << (2)
                                        << " node " << serverNodes.Get(i));
        LinuxStackHelper::RunIp(serverNodes.Get(i), Seconds(0.01), cmd_oss.str().c_str());
        cmd_oss.str("");
        cmd_oss << "route add 8.0.0.0/8 via " << if3.GetAddress(1, 0) << " dev sim" << 1
                << " table " << (2);
        NS_LOG_UNCOND("route add 8.0.0.0/8 via " << if3.GetAddress(1, 0) << " dev sim" << 1
                                                 << " table " << (2) << " node "
                                                 << serverNodes.Get(i));
        LinuxStackHelper::RunIp(serverNodes.Get(i), Seconds(0.1), cmd_oss.str().c_str());
    }
    setPos(pgw, 70, 0, 0);

    // default route
    for (uint32_t i = 0; i < numberOfNodes; i++)
    {
        LinuxStackHelper::RunIp(nodes.Get(i),
                                Seconds(0.1),
                                "route add default via 7.0.0.1 dev sim0");
        LinuxStackHelper::RunIp(nodes.Get(i), Seconds(0.1), "rule show");
        LinuxStackHelper::RunIp(nodes.Get(i), Seconds(5.1), "route show table all");
        LinuxStackHelper::RunIp(serverNodes.Get(i),
                                Seconds(0.1),
                                "route add default via 10.2." + SSTR(i) + ".2 dev sim0");
        // LinuxStackHelper::RunIp (serverNodes.Get (i), Seconds (0.1), "route add default
        // via 10.3." + SSTR(i) + ".2 dev sim0"); LinuxStackHelper::RunIp (nodes.Get
        // (numberOfNodes+1), Seconds (0.1), "route add default via 10.2.1.2 dev sim0");
        LinuxStackHelper::RunIp(serverNodes.Get(i), Seconds(0.1), "rule show");
        LinuxStackHelper::RunIp(serverNodes.Get(i), Seconds(5.1), "route show table all");
    }

    // set
    stack.SysctlSet(nodes, ".net.mptcp.mptcp_debug", "0");

    stack.SysctlSet(nodes, ".net.ipv4.tcp_rmem", "4096 87380 87380");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_wmem", "4096 87380 87380");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_congestion_control", ccAlg);
    stack.SysctlSet(nodes, ".net.mptcp.mptcp_scheduler", "default");
    stack.SysctlSet(nodes, ".net.mptcp.mptcp_checksum", "1");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_rmem", "4096 99999999 204217728");
    //                       "4096 87380 " +bufSize);
    stack.SysctlSet(nodes, ".net.ipv4.tcp_wmem", "4096 99999999 204217728");
    // stack.SysctlSet (nodes, ".net.ipv4.tcp_mem",
    //                  "768174 10242330 15363480");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_mem", "204217728 204217728 204217728");
    stack.SysctlSet(nodes, ".net.core.rmem_max", "99999999");
    stack.SysctlSet(nodes, ".net.core.wmem_max", "99999999");
    stack.SysctlSet(nodes, ".net.core.optmem_max", "99999999");
    // stack.SysctlSet (nodes, ".net.core.rmem_default",
    //                  "199999999");
    // stack.SysctlSet (nodes, ".net.core.wmem_default",
    //                  "199999999");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_congestion_control", ccAlg);
    stack.SysctlSet(nodes, ".net.mptcp.mptcp_scheduler", "default");
    stack.SysctlSet(nodes, ".net.mptcp.mptcp_checksum", "1");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_low_latency", "0");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_no_metrics_save", "1");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_timestamps", "1");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_sack", "1");
    stack.SysctlSet(nodes, ".net.core.netdev_max_backlog", "250000");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_moderate_rcvbuf", "0");
    stack.SysctlSet(nodes, ".net.ipv4.tcp_reordering", "0");

    for (int i = 0; i < numberOfNodes; ++i)
    {
        DceApplicationHelper dce;
        ApplicationContainer apps;

        dce.SetStackSize(1 << 20);
        // Launch iperf client on node 0
        dce.SetBinary("iperf");
        dce.ResetArguments();
        dce.ResetEnvironment();
        dce.AddArgument("-c");
        dce.AddArgument("10.2." + SSTR(i) + ".1");
        dce.ParseArguments("-y C");
        dce.AddArgument("-i");
        dce.AddArgument("0.25");
        dce.AddArgument("--time");
        dce.AddArgument("20");
        dce.AddArgument("-f");
        dce.AddArgument("m");
        // dce.AddArgument ("-l");
        // dce.AddArgument ("100K");
        // dce.AddArgument ("-w");
        // dce.AddArgument ("99M");
        apps = dce.Install(nodes.Get(i));
        apps.Start(Seconds(2.0));

        Simulator::Schedule(Seconds(2.1), &PrintPid, apps, dce);

        dce.SetStackSize(1 << 20);
        // Launch iperf server on node 1
        dce.SetBinary("iperf");
        dce.ResetArguments();
        dce.ResetEnvironment();
        dce.AddArgument("-s");
        dce.AddArgument("-P");
        dce.AddArgument("1");
        dce.AddArgument("-f");
        dce.AddArgument("m");

        apps = dce.Install(nodes.Get(numberOfNodes + i));
        apps.Start(Seconds(1.5));
    }

    lteHelper_2->EnablePdcpTraces();
    lteHelper_2->EnableRlcTraces();

    // Output config store to txt format
    Config::SetDefault("ns3::ConfigStore::Filename", StringValue("output-attributes.txt"));
    Config::SetDefault("ns3::ConfigStore::FileFormat", StringValue("RawText"));
    Config::SetDefault("ns3::ConfigStore::Mode", StringValue("Save"));
    ConfigStore outputConfig2;
    outputConfig2.ConfigureDefaults();
    outputConfig2.ConfigureAttributes();

    Simulator::Stop(Seconds(stopTime));
    Simulator::Run();
    Simulator::Destroy();

    return 0;
}
