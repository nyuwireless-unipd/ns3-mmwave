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
#include "ns3/config-store.h"
#include "ns3/core-module.h"
#include "ns3/global-route-manager.h"
#include "ns3/internet-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/log.h"
#include "ns3/mmwave-helper.h"
#include "ns3/mmwave-point-to-point-epc-helper.h"
#include "ns3/mmwave-propagation-loss-model.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-helper.h"
#include <ns3/buildings-helper.h>

using namespace ns3;
using namespace mmwave;

double updateInterval = 100.0; // in ms
double increment = 5.0;        // increment by x dB
double lossMin = 100.0;
double lossMax = 145.0;

void
updateLoss(double loss, Ptr<MmWavePropagationLossModel> model)
{
    model->SetLossFixedDb(loss);
    std::cout << "************* Path loss changing to " << loss << " *************" << std::endl;
    if (loss >= lossMax)
    {
        return;
    }
    Simulator::Schedule(MilliSeconds(updateInterval), &updateLoss, loss + increment, model);
}

int
main(int argc, char* argv[])
{
    /* Information regarding the traces generated:
     *
     * 1. UE_1_SINR.txt : Gives the SINR for each sub-band
     *    Subframe no.  | Slot No. | Sub-band  | SINR (db)
     *
     * 2. UE_1_Tb_size.txt : Allocated transport block size
     *    Time (micro-sec)  |  Tb-size in bytes
     * */

    uint16_t numEnb = 1;
    uint16_t numUe = 1;

    bool harqEnabled = true;
    bool rlcAmEnabled = true;
    int mcsDl = -1;
    std::string channelState = "n";
    double dist = 100.0;
    double interPacketInterval = 1000;

    // Command line arguments
    CommandLine cmd;
    cmd.AddValue("numEnb", "Number of eNBs", numEnb);
    cmd.AddValue("numUe", "Number of UEs per eNB", numUe);
    cmd.AddValue("harq", "Enable Hybrid ARQ", harqEnabled);
    cmd.AddValue("mcsDl", "Fixed DL MCS", mcsDl);
    cmd.AddValue("channelState", "Channel state 'l'=LOS, 'n'=NLOS, 'a'=all", channelState);
    cmd.AddValue("lossMin", "Initial distance", lossMin);
    cmd.AddValue("lossMax", "Final distance", lossMax);
    cmd.AddValue("increment", "Distance increment", increment);
    cmd.AddValue("updateInterval", "Period after which distance is updated", updateInterval);
    cmd.AddValue("rlcAm", "Enable RLC-AM", rlcAmEnabled);
    cmd.Parse(argc, argv);

    double simTime = ((lossMax - lossMin) / increment) * (updateInterval / 1000.0);

    if (mcsDl >= 0 && mcsDl < 29)
    {
        Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::FixedMcsDl", BooleanValue(true));
        Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::McsDefaultDl", UintegerValue(mcsDl));
    }

    // Config::SetDefault ("ns3::MmWaveAmc::AmcModel", EnumValue (MmWaveAmc::PiroEW2010));
    Config::SetDefault("ns3::MmWaveAmc::Ber", DoubleValue(0.01));
    Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(harqEnabled));
    //  Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::UlSchedOnly", BooleanValue(true));
    Config::SetDefault("ns3::ThreeGppChannelModel::UpdatePeriod", TimeValue(Seconds(2 * simTime)));
    Config::SetDefault("ns3::LteEnbRrc::SystemInformationPeriodicity",
                       TimeValue(MilliSeconds(1.0)));
    Config::SetDefault("ns3::MmWavePropagationLossModel::FixedLossTst", BooleanValue(true));
    Config::SetDefault("ns3::MmWavePropagationLossModel::LossFixedDb", DoubleValue(100.0));
    Config::SetDefault("ns3::MmWaveHelper::HarqEnabled", BooleanValue(harqEnabled));
    Config::SetDefault("ns3::MmWaveHelper::RlcAmEnabled", BooleanValue(rlcAmEnabled));
    Config::SetDefault("ns3::LteRlcAm::ReportBufferStatusTimer", TimeValue(MicroSeconds(100.0)));
    Config::SetDefault("ns3::LteRlcAm::PollRetransmitTimer", TimeValue(MilliSeconds(1.0)));
    //  Config::SetDefault ("ns3::LteRlcAm::StatusProhibitTimer", TimeValue(MicroSeconds(100.0)));

    Ptr<MmWaveHelper> mmwHelper = CreateObject<MmWaveHelper>();
    mmwHelper->SetPathlossModelType("ns3::MmWavePropagationLossModel");
    if (channelState == "l")
    {
        mmwHelper->SetChannelConditionModelType("ns3::NeverLosChannelConditionModel");
    }
    else if (channelState == "n")
    {
        mmwHelper->SetChannelConditionModelType("ns3::NeverLosChannelConditionModel");
    }
    else
    {
        NS_FATAL_ERROR("Unknown channel condition");
    }

    Ptr<MmWavePointToPointEpcHelper> epcHelper = CreateObject<MmWavePointToPointEpcHelper>();
    mmwHelper->SetEpcHelper(epcHelper);

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
    // interface 0 is localhost, 1 is the p2p device
    Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress(1);

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
    uePositionAlloc->Add(Vector(dist, 0.0, 0.0));
    uemobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    uemobility.SetPositionAllocator(uePositionAlloc);
    uemobility.Install(ueNodes);

    // Install mmWave Devices to the nodes
    NetDeviceContainer enbmmWaveDevs = mmwHelper->InstallEnbDevice(enbNodes);
    NetDeviceContainer uemmWaveDevs = mmwHelper->InstallUeDevice(ueNodes);

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

    mmwHelper->AttachToClosestEnb(uemmWaveDevs, enbmmWaveDevs);

    // Install and start applications on UEs and remote host
    uint16_t dlPort = 1234;
    uint16_t ulPort = 2000;
    uint16_t otherPort = 3000;
    ApplicationContainer clientApps;
    ApplicationContainer serverApps;
    uint32_t packetSize = 500;
    for (uint32_t u = 0; u < ueNodes.GetN(); ++u)
    {
        ++ulPort;
        ++otherPort;
        PacketSinkHelper dlPacketSinkHelper("ns3::UdpSocketFactory",
                                            InetSocketAddress(Ipv4Address::GetAny(), dlPort));
        PacketSinkHelper ulPacketSinkHelper("ns3::UdpSocketFactory",
                                            InetSocketAddress(Ipv4Address::GetAny(), ulPort));
        // PacketSinkHelper packetSinkHelper ("ns3::UdpSocketFactory", InetSocketAddress
        // (Ipv4Address::GetAny (), otherPort));
        serverApps.Add(dlPacketSinkHelper.Install(ueNodes.Get(u)));
        serverApps.Add(ulPacketSinkHelper.Install(remoteHost));
        // serverApps.Add (packetSinkHelper.Install (ueNodes.Get(u)));

        UdpClientHelper dlClient(ueIpIface.GetAddress(u), dlPort);
        dlClient.SetAttribute("Interval", TimeValue(MicroSeconds(interPacketInterval)));
        dlClient.SetAttribute("MaxPackets", UintegerValue(1000000));
        dlClient.SetAttribute("PacketSize", UintegerValue(packetSize));

        UdpClientHelper ulClient(remoteHostAddr, ulPort);
        ulClient.SetAttribute("Interval", TimeValue(MicroSeconds(interPacketInterval)));
        ulClient.SetAttribute("MaxPackets", UintegerValue(1000000));
        ulClient.SetAttribute("PacketSize", UintegerValue(packetSize));

        //      UdpClientHelper client (ueIpIface.GetAddress (u), otherPort);
        //      client.SetAttribute ("Interval", TimeValue (MicroSeconds(interPacketInterval)));
        //      client.SetAttribute ("MaxPackets", UintegerValue(1000000));

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
    mmwHelper->EnableTraces();

    // get the loss model for the default CC
    Ptr<MmWavePropagationLossModel> lossModel =
        mmwHelper->GetPathLossModel(0)->GetObject<MmWavePropagationLossModel>();
    NS_LOG_UNCOND("lossModel " << lossModel);
    NS_ASSERT_MSG(lossModel, "Unable to find the correct loss model");
    Simulator::Schedule(MilliSeconds(0), &updateLoss, lossMin, lossModel);

    serverApps.Start(Seconds(0.020));
    clientApps.Start(Seconds(0.020));
    Simulator::Stop(Seconds(simTime));
    NS_LOG_UNCOND("Simulation running for " << simTime << " seconds");
    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
