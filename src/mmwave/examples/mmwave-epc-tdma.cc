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
#include "ns3/config-store-module.h"
#include "ns3/epc-helper.h"
#include "ns3/internet-module.h"
#include "ns3/mmwave-helper.h"
#include "ns3/mmwave-point-to-point-epc-helper.h"
#include "ns3/mobility-module.h"
#include "ns3/point-to-point-helper.h"

#include <sstream>
#include <string>

using namespace ns3;
using namespace mmwave;

/**
 * Sample simulation script for LTE+EPC. It instantiates several eNodeB,
 * attaches one UE per eNodeB starts a flow for each UE to  and from a remote host.
 * It also  starts yet another flow between each UE pair.
 */
NS_LOG_COMPONENT_DEFINE("MmWaveEpcTdma");

int
main(int argc, char* argv[])
{
    uint16_t numEnb = 1;
    uint16_t numUe = 1;
    double simTime = 1.0;
    double interPacketInterval = 100;
    double minDistance = 10.0;  // eNB-UE distance in meters
    double maxDistance = 200.0; // eNB-UE distance in meters
    bool harqEnabled = true;
    bool rlcAmEnabled = false;
    bool fixedTti = false;

    // Command line arguments
    CommandLine cmd;
    cmd.AddValue("numEnb", "Number of eNBs", numEnb);
    cmd.AddValue("numUe", "Number of UEs per eNB", numUe);
    cmd.AddValue("simTime", "Total duration of the simulation [s])", simTime);
    cmd.AddValue("interPacketInterval", "Inter-packet interval [us])", interPacketInterval);
    cmd.AddValue("harq", "Enable Hybrid ARQ", harqEnabled);
    cmd.AddValue("rlcAm", "Enable RLC-AM", rlcAmEnabled);
    cmd.AddValue("fixedTti", "Fixed TTI scheduler", fixedTti);
    cmd.Parse(argc, argv);

    Config::SetDefault("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue(rlcAmEnabled));
    Config::SetDefault("ns3::MmWaveHelper::HarqEnabled", BooleanValue(harqEnabled));
    Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(harqEnabled));
    Config::SetDefault("ns3::MmWavePhyMacCommon::TbDecodeLatency", UintegerValue(200.0));
    Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod",
                       TimeValue(MilliSeconds(100000.0)));
    Config::SetDefault("ns3::LteEnbRrc::SystemInformationPeriodicity",
                       TimeValue(MilliSeconds(5.0)));
    Config::SetDefault("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MicroSeconds(100.0)));
    Config::SetDefault("ns3::LteRlcUmLowLat::ReportBufferStatusTimer",
                       TimeValue(MicroSeconds(100.0)));
    Config::SetDefault("ns3::LteEnbRrc::SrsPeriodicity", UintegerValue(320));
    Config::SetDefault("ns3::LteEnbRrc::FirstSibTime", UintegerValue(2));

    // the applications on this example start very early.
    // Use the IDEAL mode in RRC (no radio messages are exchanged for RRC control ops)
    // and set to the minimum the latency on the S1-AP link to speed up the link and bearers setup
    Config::SetDefault("ns3::MmWaveHelper::UseIdealRrc", BooleanValue(true));
    Config::SetDefault("ns3::MmWavePointToPointEpcHelper::S1apLinkDelay", TimeValue(Seconds(0)));

    Ptr<MmWaveHelper> mmwaveHelper = CreateObject<MmWaveHelper>();
    Ptr<MmWavePointToPointEpcHelper> epcHelper = CreateObject<MmWavePointToPointEpcHelper>();
    mmwaveHelper->SetEpcHelper(epcHelper);
    mmwaveHelper->SetHarqEnabled(harqEnabled);

    ConfigStore inputConfig;
    inputConfig.ConfigureDefaults();

    // parse again so you can override default values from the command line
    cmd.Parse(argc, argv);

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
    p2ph.SetChannelAttribute("Delay", TimeValue(MicroSeconds(100.0)));
    NetDeviceContainer internetDevices = p2ph.Install(pgw, remoteHost);
    Ipv4AddressHelper ipv4h;
    ipv4h.SetBase("1.0.0.0", "255.0.0.0");
    Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign(internetDevices);

    Ipv4StaticRoutingHelper ipv4RoutingHelper;
    Ptr<Ipv4StaticRouting> remoteHostStaticRouting =
        ipv4RoutingHelper.GetStaticRouting(remoteHost->GetObject<Ipv4>());
    remoteHostStaticRouting->AddNetworkRouteTo(Ipv4Address("7.0.0.0"), Ipv4Mask("255.0.0.0"), 1);

    NodeContainer ueNodes;
    NodeContainer enbNodes;
    enbNodes.Create(numEnb);
    ueNodes.Create(numUe);

    // Install Mobility Model
    Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator>();
    enbPositionAlloc->Add(Vector(0.0, 0.0, 0.0));
    MobilityHelper enbmobility;
    enbmobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    enbmobility.SetPositionAllocator(enbPositionAlloc);
    enbmobility.Install(enbNodes);

    MobilityHelper uemobility;
    Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator>();
    Ptr<UniformRandomVariable> distRv = CreateObject<UniformRandomVariable>();

    for (unsigned i = 0; i < numUe; i++)
    {
        double dist = distRv->GetValue(minDistance, maxDistance);
        uePositionAlloc->Add(Vector(dist, 0.0, 0.0));
    }
    uemobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    uemobility.SetPositionAllocator(uePositionAlloc);
    uemobility.Install(ueNodes);

    // Install mmWave Devices to the nodes
    NetDeviceContainer enbmmWaveDevs = mmwaveHelper->InstallEnbDevice(enbNodes);
    NetDeviceContainer uemmWaveDevs = mmwaveHelper->InstallUeDevice(ueNodes);

    // Install the IP stack on the UEs
    internet.Install(ueNodes);
    Ipv4InterfaceContainer ueIpIface;
    ueIpIface = epcHelper->AssignUeIpv4Address(NetDeviceContainer(uemmWaveDevs));
    // Assign IP address to UEs, and install applications
    for (uint32_t u = 0; u < ueNodes.GetN(); ++u)
    {
        Ptr<Node> ueNode = ueNodes.Get(u);
        // Set the default gateway for the UE
        Ptr<Ipv4StaticRouting> ueStaticRouting =
            ipv4RoutingHelper.GetStaticRouting(ueNode->GetObject<Ipv4>());
        ueStaticRouting->SetDefaultRoute(epcHelper->GetUeDefaultGatewayAddress(), 1);
    }

    mmwaveHelper->AttachToClosestEnb(uemmWaveDevs, enbmmWaveDevs);

    // Install and start applications on UEs and remote host
    uint16_t dlPort = 1234;
    uint16_t ulPort = 2000;
    uint16_t otherPort = 3000;
    ApplicationContainer clientApps;
    ApplicationContainer serverApps;
    uint32_t packetSize = 1400;

    double dataRateMB = 100e6; // 100 MBps
    double onTimeSec = 5e-6;   // packetSize / dataRateMB;
    std::stringstream ss;
    ss << "ns3::ConstantRandomVariable[Constant=" << onTimeSec << "]";
    std::cout << "OnTime == " << ss.str() << std::endl;
    OnOffHelper dlClient("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), dlPort));
    OnOffHelper ulClient("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), ulPort));
    dlClient.SetAttribute("PacketSize", UintegerValue(packetSize));
    ulClient.SetAttribute("PacketSize", UintegerValue(packetSize));
    dlClient.SetAttribute("DataRate", DataRateValue(8 * dataRateMB));
    ulClient.SetAttribute("DataRate", DataRateValue(8 * dataRateMB));
    dlClient.SetAttribute("OnTime", StringValue(ss.str()));
    ulClient.SetAttribute("OnTime", StringValue(ss.str()));
    ss.str("");
    ss << "ns3::ExponentialRandomVariable[Mean=" << interPacketInterval * 1e-6 << "]";
    std::cout << "OffTime == " << ss.str() << std::endl;
    dlClient.SetAttribute("OffTime", StringValue(ss.str()));
    ulClient.SetAttribute("OffTime", StringValue(ss.str()));

    for (uint32_t u = 0; u < ueNodes.GetN(); ++u)
    {
        ++ulPort;
        ++otherPort;
        PacketSinkHelper dlPacketSinkHelper("ns3::UdpSocketFactory",
                                            InetSocketAddress(Ipv4Address::GetAny(), dlPort));
        PacketSinkHelper ulPacketSinkHelper("ns3::UdpSocketFactory",
                                            InetSocketAddress(Ipv4Address::GetAny(), ulPort));
        serverApps.Add(dlPacketSinkHelper.Install(ueNodes.Get(u)));
        serverApps.Add(ulPacketSinkHelper.Install(remoteHost));

        //      UdpClientHelper dlClient (ueIpIface.GetAddress (u), dlPort);
        //      dlClient.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
        //      dlClient.SetAttribute ("MaxPackets", UintegerValue(1000000));
        //      dlClient.SetAttribute ("PacketSize", UintegerValue(packetSize));
        //
        //      UdpClientHelper ulClient (remoteHostAddr, ulPort);
        //      ulClient.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
        //      ulClient.SetAttribute ("MaxPackets", UintegerValue(1000000));
        //      ulClient.SetAttribute ("PacketSize", UintegerValue(packetSize));

        // UdpClientHelper client (ueIpIface.GetAddress (u), otherPort);
        // client.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
        // client.SetAttribute ("MaxPackets", UintegerValue(1000000));
        dlClient.SetAttribute("Remote",
                              AddressValue(InetSocketAddress(ueIpIface.GetAddress(u), dlPort)));
        // ulClient.SetAttribute ("Remote", AddressValue (InetSocketAddress (remoteHostAddr,
        // ulPort)));

        clientApps.Add(dlClient.Install(remoteHost));
        clientApps.Add(ulClient.Install(ueNodes.Get(u)));
        //      if (u+1 < ueNodes.GetN ())
        //      {
        //          clientApps.Add (client.Install (ueNodes.Get(u+1)));
        //      }
        //      else
        //      {
        //          clientApps.Add (client.Install (ueNodes.Get(0)));
        //      }
    }
    serverApps.Start(Seconds(0.1));
    clientApps.Start(Seconds(0.1));
    mmwaveHelper->EnableTraces();
    // Uncomment to enable PCAP tracing
    // p2ph.EnablePcapAll("mmwave-epc-simple");

    Simulator::Stop(Seconds(simTime));
    Simulator::Run();

    /*GtkConfigStore config;
  config.ConfigureAttributes();*/

    Simulator::Destroy();
    return 0;
}
