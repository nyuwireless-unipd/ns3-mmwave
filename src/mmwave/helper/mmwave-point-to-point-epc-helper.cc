/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 *
 *   Modified by: Michele Polese <michele.polese@gmail.com>
 *                Dual Connectivity and Handover functionalities
 *   Modified by: Gabriel Arrobo <gab.arrobo@gmail.com>
 *                Added IPv6 support in ActivateEpsBearer function
 */

#include "ns3/ipv6-static-routing-helper.h"
#include "ns3/ipv6-static-routing.h"
#include <ns3/config.h>
#include <ns3/epc-enb-application.h>
#include <ns3/epc-mme-application.h>
#include <ns3/epc-s1ap.h>
#include <ns3/epc-sgw-pgw-application.h>
#include <ns3/epc-ue-nas.h>
#include <ns3/epc-x2.h>
#include <ns3/eps-bearer.h>
#include <ns3/icmpv6-l4-protocol.h>
#include <ns3/inet-socket-address.h>
#include <ns3/internet-stack-helper.h>
#include <ns3/ipv4-address.h>
#include <ns3/log.h>
#include <ns3/lte-enb-net-device.h>
#include <ns3/lte-enb-rrc.h>
#include <ns3/mac48-address.h>
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/mmwave-point-to-point-epc-helper.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/packet-socket-address.h>
#include <ns3/packet-socket-helper.h>
#include <ns3/point-to-point-helper.h>
#include <ns3/queue-size.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWavePointToPointEpcHelper");

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWavePointToPointEpcHelper);

MmWavePointToPointEpcHelper::MmWavePointToPointEpcHelper()
    : m_gtpuUdpPort(2152),
      // fixed by the standard
      m_s1apUdpPort(36412)
{
    NS_LOG_FUNCTION(this);

    // since we use point-to-point links for all S1-U and S1-AP links,
    // we use a /30 subnet which can hold exactly two addresses
    // (remember that net broadcast and null address are not valid)
    m_s1uIpv4AddressHelper.SetBase("10.0.0.0", "255.255.255.252");
    m_s1apIpv4AddressHelper.SetBase("11.0.0.0", "255.255.255.252");
    m_x2Ipv4AddressHelper.SetBase("12.0.0.0", "255.255.255.252");

    // we use a /8 net for all UEs
    m_uePgwAddressHelper.SetBase("7.0.0.0", "255.0.0.0");

    // we use a /64 IPv6 net all UEs
    m_uePgwAddressHelper6.SetBase("7777:f00d::", Ipv6Prefix(64));

    // create SgwPgwNode
    m_sgwPgw = CreateObject<Node>();
    InternetStackHelper internet;
    internet.Install(m_sgwPgw);

    // create MmeNode
    m_mmeNode = CreateObject<Node>();
    internet.Install(m_mmeNode);

    // create S1-U socket
    // The Tun device resides in different 64 bit subnet.
    // We must create an unique route to tun device for all the packets destined
    // to all 64 bit IPv6 prefixes of UEs, based by the unique 48 bit network
    // prefix of this EPC network
    Ipv6StaticRoutingHelper ipv6RoutingHelper;
    Ptr<Ipv6StaticRouting> pgwStaticRouting =
        ipv6RoutingHelper.GetStaticRouting(m_sgwPgw->GetObject<Ipv6>());
    pgwStaticRouting->AddNetworkRouteTo("7777:f00d::", Ipv6Prefix(64), Ipv6Address("::"), 1, 0);

    // create S1-U socket for SgwPgwNode
    Ptr<Socket> sgwPgwS1uSocket =
        Socket::CreateSocket(m_sgwPgw, TypeId::LookupByName("ns3::UdpSocketFactory"));
    int retval = sgwPgwS1uSocket->Bind(InetSocketAddress(Ipv4Address::GetAny(), m_gtpuUdpPort));
    NS_ASSERT(retval == 0);

    // create S1-AP socket for MmeNode
    Ptr<Socket> mmeS1apSocket =
        Socket::CreateSocket(m_mmeNode, TypeId::LookupByName("ns3::UdpSocketFactory"));
    retval = mmeS1apSocket->Bind(
        InetSocketAddress(Ipv4Address::GetAny(),
                          m_s1apUdpPort)); // it listens on any IP, port m_s1apUdpPort
    NS_ASSERT(retval == 0);

    // create TUN device implementing tunneling of user data over GTP-U/UDP/IP
    m_tunDevice = CreateObject<VirtualNetDevice>();
    // allow jumbo packets
    m_tunDevice->SetAttribute("Mtu", UintegerValue(30000));

    // yes we need this
    m_tunDevice->SetAddress(Mac48Address::Allocate());

    m_sgwPgw->AddDevice(m_tunDevice);
    NetDeviceContainer tunDeviceContainer;
    tunDeviceContainer.Add(m_tunDevice);

    // the TUN device is on the same subnet as the UEs, so when a packet
    // addressed to an UE arrives at the intenet to the WAN interface of
    // the PGW it will be forwarded to the TUN device.
    Ipv4InterfaceContainer tunDeviceIpv4IfContainer = AssignUeIpv4Address(tunDeviceContainer);

    // the TUN device for IPv6 address is on the different subnet as the
    // UEs, it will forward the UE packets as we have inserted the route
    // for all UEs at the time of assigning UE addresses
    Ipv6InterfaceContainer tunDeviceIpv6IfContainer = AssignUeIpv6Address(tunDeviceContainer);

    // Set Forwarding of the IPv6 interface
    tunDeviceIpv6IfContainer.SetForwarding(0, true);
    tunDeviceIpv6IfContainer.SetDefaultRouteInAllNodes(0);

    // create EpcSgwPgwApplication
    m_sgwPgwApp = CreateObject<EpcSgwPgwApplication>(m_tunDevice, sgwPgwS1uSocket);
    m_sgwPgw->AddApplication(m_sgwPgwApp);

    // connect SgwPgwApplication and virtual net device for tunneling
    m_tunDevice->SetSendCallback(
        MakeCallback(&EpcSgwPgwApplication::RecvFromTunDevice, m_sgwPgwApp));

    // create S1apMme object and aggregate it with the m_mmeNode
    Ptr<EpcS1apMme> s1apMme = CreateObject<EpcS1apMme>(mmeS1apSocket, 1); // for now, only one mme!
    m_mmeNode->AggregateObject(s1apMme);

    // create EpcMmeApplication and connect with SGW via S11 interface
    m_mmeApp = CreateObject<EpcMmeApplication>();
    m_mmeNode->AddApplication(m_mmeApp);
    m_mmeApp->SetS11SapSgw(m_sgwPgwApp->GetS11SapSgw());
    m_sgwPgwApp->SetS11SapMme(m_mmeApp->GetS11SapMme());
    // connect m_mmeApp to the s1apMme
    m_mmeApp->SetS1apSapMmeProvider(s1apMme->GetEpcS1apSapMmeProvider());
    s1apMme->SetEpcS1apSapMmeUser(m_mmeApp->GetS1apSapMme());
}

MmWavePointToPointEpcHelper::~MmWavePointToPointEpcHelper()
{
    NS_LOG_FUNCTION(this);
}

TypeId
MmWavePointToPointEpcHelper::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWavePointToPointEpcHelper")
            .SetParent<EpcHelper>()
            .SetGroupName("mmWave")
            .AddConstructor<MmWavePointToPointEpcHelper>()
            .AddAttribute("S1uLinkDataRate",
                          "The data rate to be used for the next S1-U link to be created",
                          DataRateValue(DataRate("10Gb/s")),
                          MakeDataRateAccessor(&MmWavePointToPointEpcHelper::m_s1uLinkDataRate),
                          MakeDataRateChecker())
            .AddAttribute("S1uLinkDelay",
                          "The delay to be used for the next S1-U link to be created",
                          TimeValue(Seconds(0.001)),
                          MakeTimeAccessor(&MmWavePointToPointEpcHelper::m_s1uLinkDelay),
                          MakeTimeChecker())
            .AddAttribute(
                "S1uLinkMtu",
                "The MTU of the next S1-U link to be created. Note that, because of the "
                "additional GTP/UDP/IP tunneling overhead, you need a MTU larger than the "
                "end-to-end MTU that you want to support.",
                UintegerValue(2000),
                MakeUintegerAccessor(&MmWavePointToPointEpcHelper::m_s1uLinkMtu),
                MakeUintegerChecker<uint16_t>())
            .AddAttribute("S1apLinkDataRate",
                          "The data rate to be used for the S1-AP link to be created",
                          DataRateValue(DataRate("10Gb/s")),
                          MakeDataRateAccessor(&MmWavePointToPointEpcHelper::m_s1apLinkDataRate),
                          MakeDataRateChecker())
            .AddAttribute("S1apLinkDelay",
                          "The delay to be used for the S1-AP link to be created",
                          TimeValue(MilliSeconds(15)),
                          MakeTimeAccessor(&MmWavePointToPointEpcHelper::m_s1apLinkDelay),
                          MakeTimeChecker())
            .AddAttribute("S1apLinkMtu",
                          "The MTU of the next S1-AP link to be created",
                          UintegerValue(10000),
                          MakeUintegerAccessor(&MmWavePointToPointEpcHelper::m_s1apLinkMtu),
                          MakeUintegerChecker<uint16_t>())
            .AddAttribute("X2LinkDataRate",
                          "The data rate to be used for the next X2 link to be created",
                          DataRateValue(DataRate("100Gb/s")),
                          MakeDataRateAccessor(&MmWavePointToPointEpcHelper::m_x2LinkDataRate),
                          MakeDataRateChecker())
            .AddAttribute("X2LinkDelay",
                          "The delay to be used for the next X2 link to be created",
                          TimeValue(Seconds(0.001)),
                          MakeTimeAccessor(&MmWavePointToPointEpcHelper::m_x2LinkDelay),
                          MakeTimeChecker())
            .AddAttribute("X2LinkMtu",
                          "The MTU of the next X2 link to be created. Note that, because of some "
                          "big X2 messages, you need a big MTU.",
                          UintegerValue(10000),
                          MakeUintegerAccessor(&MmWavePointToPointEpcHelper::m_x2LinkMtu),
                          MakeUintegerChecker<uint16_t>());
    return tid;
}

void
MmWavePointToPointEpcHelper::DoDispose()
{
    NS_LOG_FUNCTION(this);
    m_tunDevice->SetSendCallback(
        MakeNullCallback<bool, Ptr<Packet>, const Address&, const Address&, uint16_t>());
    m_tunDevice = 0;
    m_sgwPgwApp = 0;
    m_sgwPgw->Dispose();
}

void
MmWavePointToPointEpcHelper::AddEnb(Ptr<Node> enb, Ptr<NetDevice> lteEnbNetDevice, uint16_t cellId)
{
    NS_LOG_FUNCTION(this << enb << lteEnbNetDevice << cellId);

    NS_ASSERT(enb == lteEnbNetDevice->GetNode());

    // add an IPv4 stack to the previously created eNB
    InternetStackHelper internet;
    internet.Install(enb);
    NS_LOG_LOGIC("number of Ipv4 ifaces of the eNB after node creation: "
                 << enb->GetObject<Ipv4>()->GetNInterfaces());

    // create a point to point link between the new eNB and the SGW with
    // the corresponding new NetDevices on each side
    NodeContainer enbSgwNodes;
    enbSgwNodes.Add(m_sgwPgw);
    enbSgwNodes.Add(enb);
    PointToPointHelper p2ph;
    p2ph.SetDeviceAttribute("DataRate", DataRateValue(m_s1uLinkDataRate));
    p2ph.SetDeviceAttribute("Mtu", UintegerValue(m_s1uLinkMtu));
    p2ph.SetChannelAttribute("Delay", TimeValue(m_s1uLinkDelay));
    NetDeviceContainer enbSgwDevices = p2ph.Install(enb, m_sgwPgw);
    NS_LOG_LOGIC("number of Ipv4 ifaces of the eNB after installing p2p dev: "
                 << enb->GetObject<Ipv4>()->GetNInterfaces());
    Ptr<NetDevice> enbDev = enbSgwDevices.Get(0);
    Ptr<NetDevice> sgwDev = enbSgwDevices.Get(1);
    m_s1uIpv4AddressHelper.NewNetwork();
    Ipv4InterfaceContainer enbSgwIpIfaces = m_s1uIpv4AddressHelper.Assign(enbSgwDevices);
    NS_LOG_LOGIC("number of Ipv4 ifaces of the eNB after assigning Ipv4 addr to S1 dev: "
                 << enb->GetObject<Ipv4>()->GetNInterfaces());

    Ipv4Address enbAddress = enbSgwIpIfaces.GetAddress(0);
    Ipv4Address sgwAddress = enbSgwIpIfaces.GetAddress(1);

    // create S1-U socket for the ENB
    Ptr<Socket> enbS1uSocket =
        Socket::CreateSocket(enb, TypeId::LookupByName("ns3::UdpSocketFactory"));
    int retval = enbS1uSocket->Bind(InetSocketAddress(enbAddress, m_gtpuUdpPort));
    NS_ASSERT(retval == 0);

    // create a point to point link between the new eNB and the MME with
    // the corresponding new NetDevices on each side
    NodeContainer enbMmeNodes;
    enbMmeNodes.Add(m_mmeNode);
    enbMmeNodes.Add(enb);
    PointToPointHelper p2ph_mme;
    p2ph_mme.SetDeviceAttribute("DataRate", DataRateValue(m_s1apLinkDataRate));
    p2ph_mme.SetDeviceAttribute("Mtu", UintegerValue(m_s1apLinkMtu));
    p2ph_mme.SetChannelAttribute("Delay", TimeValue(m_s1apLinkDelay));
    NetDeviceContainer enbMmeDevices = p2ph_mme.Install(enb, m_mmeNode);
    NS_LOG_LOGIC("number of Ipv4 ifaces of the eNB after installing p2p dev: "
                 << enb->GetObject<Ipv4>()->GetNInterfaces());

    m_s1apIpv4AddressHelper.NewNetwork();
    Ipv4InterfaceContainer enbMmeIpIfaces = m_s1apIpv4AddressHelper.Assign(enbMmeDevices);
    NS_LOG_LOGIC("number of Ipv4 ifaces of the eNB after assigning Ipv4 addr to S1 dev: "
                 << enb->GetObject<Ipv4>()->GetNInterfaces());

    Ipv4Address mme_enbAddress = enbMmeIpIfaces.GetAddress(0);
    Ipv4Address mmeAddress = enbMmeIpIfaces.GetAddress(1);

    // create S1-AP socket for the ENB
    Ptr<Socket> enbS1apSocket =
        Socket::CreateSocket(enb, TypeId::LookupByName("ns3::UdpSocketFactory"));
    retval = enbS1apSocket->Bind(InetSocketAddress(mme_enbAddress, m_s1apUdpPort));
    NS_ASSERT(retval == 0);

    // give PacketSocket powers to the eNB
    // PacketSocketHelper packetSocket;
    // packetSocket.Install (enb);

    // create LTE socket for the ENB
    Ptr<Socket> enbLteSocket =
        Socket::CreateSocket(enb, TypeId::LookupByName("ns3::PacketSocketFactory"));
    PacketSocketAddress enbLteSocketBindAddress;
    enbLteSocketBindAddress.SetSingleDevice(lteEnbNetDevice->GetIfIndex());
    enbLteSocketBindAddress.SetProtocol(Ipv4L3Protocol::PROT_NUMBER);
    retval = enbLteSocket->Bind(enbLteSocketBindAddress);
    NS_ASSERT(retval == 0);
    PacketSocketAddress enbLteSocketConnectAddress;
    enbLteSocketConnectAddress.SetPhysicalAddress(Mac48Address::GetBroadcast());
    enbLteSocketConnectAddress.SetSingleDevice(lteEnbNetDevice->GetIfIndex());
    enbLteSocketConnectAddress.SetProtocol(Ipv4L3Protocol::PROT_NUMBER);
    retval = enbLteSocket->Connect(enbLteSocketConnectAddress);
    NS_ASSERT(retval == 0);

    // create LTE socket for the ENB
    Ptr<Socket> enbLteSocket6 =
        Socket::CreateSocket(enb, TypeId::LookupByName("ns3::PacketSocketFactory"));
    PacketSocketAddress enbLteSocketBindAddress6;
    enbLteSocketBindAddress6.SetSingleDevice(lteEnbNetDevice->GetIfIndex());
    enbLteSocketBindAddress6.SetProtocol(Ipv6L3Protocol::PROT_NUMBER);
    retval = enbLteSocket6->Bind(enbLteSocketBindAddress6);
    NS_ASSERT(retval == 0);
    PacketSocketAddress enbLteSocketConnectAddress6;
    enbLteSocketConnectAddress6.SetPhysicalAddress(Mac48Address::GetBroadcast());
    enbLteSocketConnectAddress6.SetSingleDevice(lteEnbNetDevice->GetIfIndex());
    enbLteSocketConnectAddress6.SetProtocol(Ipv6L3Protocol::PROT_NUMBER);
    retval = enbLteSocket6->Connect(enbLteSocketConnectAddress6);
    NS_ASSERT(retval == 0);

    NS_LOG_INFO("create EpcEnbApplication");
    Ptr<EpcEnbApplication> enbApp = CreateObject<EpcEnbApplication>(enbLteSocket,
                                                                    enbLteSocket6,
                                                                    enbS1uSocket,
                                                                    enbAddress,
                                                                    sgwAddress,
                                                                    cellId);
    enb->AddApplication(enbApp);
    NS_ASSERT(enb->GetNApplications() == 1);
    NS_ASSERT_MSG(enb->GetApplication(0)->GetObject<EpcEnbApplication>(),
                  "cannot retrieve EpcEnbApplication");
    NS_LOG_LOGIC("enb: " << enb << ", enb->GetApplication (0): " << enb->GetApplication(0));

    NS_LOG_INFO("Create EpcX2 entity");
    Ptr<EpcX2> x2 = CreateObject<EpcX2>();
    enb->AggregateObject(x2);

    NS_LOG_INFO("connect S1-AP interface");

    uint16_t mmeId = 1;
    Ptr<EpcS1apEnb> s1apEnb = CreateObject<EpcS1apEnb>(enbS1apSocket,
                                                       mme_enbAddress,
                                                       mmeAddress,
                                                       cellId,
                                                       mmeId); // only one mme!
    enb->AggregateObject(s1apEnb);
    enbApp->SetS1apSapMme(s1apEnb->GetEpcS1apSapEnbProvider());
    s1apEnb->SetEpcS1apSapEnbUser(enbApp->GetS1apSapEnb());
    m_mmeApp->AddEnb(cellId, mme_enbAddress); // TODO consider if this can be removed
    // add the interface to the S1AP endpoint on the MME
    Ptr<EpcS1apMme> s1apMme = m_mmeNode->GetObject<EpcS1apMme>();
    s1apMme->AddS1apInterface(cellId, mme_enbAddress);

    m_sgwPgwApp->AddEnb(cellId, enbAddress, sgwAddress);
}

void
MmWavePointToPointEpcHelper::AddX2Interface(Ptr<Node> enb1, Ptr<Node> enb2)
{
    NS_LOG_FUNCTION(this << enb1 << enb2);

    // Create a point to point link between the two eNBs with
    // the corresponding new NetDevices on each side
    NodeContainer enbNodes;
    enbNodes.Add(enb1);
    enbNodes.Add(enb2);
    PointToPointHelper p2ph;
    p2ph.SetDeviceAttribute("DataRate", DataRateValue(m_x2LinkDataRate));
    p2ph.SetDeviceAttribute("Mtu", UintegerValue(m_x2LinkMtu));
    p2ph.SetChannelAttribute("Delay", TimeValue(m_x2LinkDelay));
    // in case the RLC buffer is full, the forwarding of packets from the source eNB to the target
    // eNB during a handover or a switch may overflow the transmission queue of point to point
    // devices. Therefore the following line increases the size of tx queue in p2p devices. The
    // parameter should be related to the maximum size of the RLC buffer.
    p2ph.SetQueue("ns3::DropTailQueue", "MaxSize", QueueSizeValue(QueueSize("4294967295p")));
    NetDeviceContainer enbDevices = p2ph.Install(enb1, enb2);
    NS_LOG_LOGIC("number of Ipv4 ifaces of the eNB #1 after installing p2p dev: "
                 << enb1->GetObject<Ipv4>()->GetNInterfaces());
    NS_LOG_LOGIC("number of Ipv4 ifaces of the eNB #2 after installing p2p dev: "
                 << enb2->GetObject<Ipv4>()->GetNInterfaces());
    Ptr<NetDevice> enb1Dev = enbDevices.Get(0);
    Ptr<NetDevice> enb2Dev = enbDevices.Get(1);

    m_x2Ipv4AddressHelper.NewNetwork();
    Ipv4InterfaceContainer enbIpIfaces = m_x2Ipv4AddressHelper.Assign(enbDevices);
    NS_LOG_LOGIC("number of Ipv4 ifaces of the eNB #1 after assigning Ipv4 addr to X2 dev: "
                 << enb1->GetObject<Ipv4>()->GetNInterfaces());
    NS_LOG_LOGIC("number of Ipv4 ifaces of the eNB #2 after assigning Ipv4 addr to X2 dev: "
                 << enb2->GetObject<Ipv4>()->GetNInterfaces());

    Ipv4Address enb1X2Address = enbIpIfaces.GetAddress(0);
    Ipv4Address enb2X2Address = enbIpIfaces.GetAddress(1);

    // Add X2 interface to both eNBs' X2 entities
    Ptr<EpcX2> enb1X2 = enb1->GetObject<EpcX2>();
    Ptr<MmWaveEnbNetDevice> enb1MmWaveDev = enb1->GetDevice(0)->GetObject<MmWaveEnbNetDevice>();
    Ptr<LteEnbNetDevice> enb1LteDev = enb1->GetDevice(0)->GetObject<LteEnbNetDevice>();
    // we may have a LTE or a MmWave eNB
    uint16_t enb1CellId = 0;
    if (enb1MmWaveDev)
    {
        enb1CellId = enb1MmWaveDev->GetCellId();
        NS_LOG_INFO("MmWaveEnbNetDevice #1 = " << enb1MmWaveDev << " - CellId = " << enb1CellId);
    }
    else if (enb1LteDev)
    {
        enb1CellId = enb1LteDev->GetCellId();
        NS_LOG_INFO("LteEnbNetDevice #1 = " << enb1LteDev << " - CellId = " << enb1CellId);
    }

    Ptr<EpcX2> enb2X2 = enb2->GetObject<EpcX2>();
    Ptr<MmWaveEnbNetDevice> enb2MmWaveDev = enb2->GetDevice(0)->GetObject<MmWaveEnbNetDevice>();
    Ptr<LteEnbNetDevice> enb2LteDev = enb2->GetDevice(0)->GetObject<LteEnbNetDevice>();
    // we may have a LTE or a MmWave eNB
    uint16_t enb2CellId = 0;
    if (enb2MmWaveDev)
    {
        enb2CellId = enb2MmWaveDev->GetCellId();
        NS_LOG_INFO("MmWaveEnbNetDevice #2 = " << enb2MmWaveDev << " - CellId = " << enb2CellId);
        enb2MmWaveDev->GetRrc()->AddX2Neighbour(enb1CellId);
    }
    else if (enb2LteDev)
    {
        enb2CellId = enb2LteDev->GetCellId();
        NS_LOG_INFO("LteEnbNetDevice #2 = " << enb2LteDev << " - CellId = " << enb2CellId);
        enb2LteDev->GetRrc()->AddX2Neighbour(enb1CellId);
    }

    enb1X2->AddX2Interface(enb1CellId, enb1X2Address, enb2CellId, enb2X2Address);
    enb2X2->AddX2Interface(enb2CellId, enb2X2Address, enb1CellId, enb1X2Address);

    if (enb1MmWaveDev)
    {
        enb1MmWaveDev->GetRrc()->AddX2Neighbour(enb2CellId);
    }
    else if (enb1LteDev)
    {
        enb1LteDev->GetRrc()->AddX2Neighbour(enb2CellId);
    }

    // if((enb1CellId == 1 && enb2CellId == 2) || (enb1CellId == 2 && enb2CellId == 1))
    // {
    //   //AsciiTraceHelper ascii;
    //   p2ph.EnablePcapAll("x2.pcap");
    // }
}

void
MmWavePointToPointEpcHelper::AddUe(Ptr<NetDevice> ueDevice, uint64_t imsi)
{
    NS_LOG_FUNCTION(this << imsi << ueDevice);

    m_mmeApp->AddUe(imsi);
    m_sgwPgwApp->AddUe(imsi);
}

uint8_t
MmWavePointToPointEpcHelper::ActivateEpsBearer(Ptr<NetDevice> ueDevice,
                                               uint64_t imsi,
                                               Ptr<EpcTft> tft,
                                               EpsBearer bearer)
{
    NS_LOG_FUNCTION(this << ueDevice << imsi);

    // we now retrieve the IPv4/IPv6 address of the UE and notify it to the SGW;
    // we couldn't do it before since address assignment is triggered by
    // the user simulation program, rather than done by the EPC
    Ptr<Node> ueNode = ueDevice->GetNode();
    Ptr<Ipv4> ueIpv4 = ueNode->GetObject<Ipv4>();

    Ptr<Ipv6> ueIpv6 = ueNode->GetObject<Ipv6>();
    NS_ASSERT_MSG(ueIpv4 || ueIpv6,
                  "UEs need to have IPv4/IPv6 installed before EPS bearers can be activated");
    if (ueIpv4)
    {
        int32_t interface = ueIpv4->GetInterfaceForDevice(ueDevice);
        if (interface >= 0 && ueIpv4->GetNAddresses(interface) == 1)
        {
            Ipv4Address ueAddr = ueIpv4->GetAddress(interface, 0).GetLocal();
            NS_LOG_LOGIC(" UE IP address: " << ueAddr);
            m_sgwPgwApp->SetUeAddress(imsi, ueAddr);
        }
    }
    if (ueIpv6)
    {
        int32_t interface6 = ueIpv6->GetInterfaceForDevice(ueDevice);
        if (interface6 >= 0 && ueIpv6->GetNAddresses(interface6) == 2)
        {
            Ipv6Address ueAddr6 = ueIpv6->GetAddress(interface6, 1).GetAddress();
            NS_LOG_LOGIC(" UE IPv6 address: " << ueAddr6);
            m_sgwPgwApp->SetUeAddress6(imsi, ueAddr6);
        }
    }

    uint8_t bearerId = m_mmeApp->AddBearer(imsi, tft, bearer);
    Ptr<mmwave::MmWaveUeNetDevice> ueLteDevice = ueDevice->GetObject<mmwave::MmWaveUeNetDevice>();
    if (ueLteDevice)
    {
        Simulator::ScheduleNow(&EpcUeNas::ActivateEpsBearer, ueLteDevice->GetNas(), bearer, tft);
    }
    NS_LOG_LOGIC("Bearer Id added in mmeApp " << bearerId);
    return bearerId;
}

uint8_t
MmWavePointToPointEpcHelper::ActivateEpsBearer(Ptr<NetDevice> ueDevice,
                                               Ptr<EpcUeNas> ueNas,
                                               uint64_t imsi,
                                               Ptr<EpcTft> tft,
                                               EpsBearer bearer)
{
    NS_LOG_FUNCTION(this << ueDevice << imsi);

    // we now retrieve the IPv4 address of the UE and notify it to the SGW;
    // we couldn't do it before since address assignment is triggered by
    // the user simulation program, rather than done by the EPC
    Ptr<Node> ueNode = ueDevice->GetNode();
    Ptr<Ipv4> ueIpv4 = ueNode->GetObject<Ipv4>();

    Ptr<Ipv6> ueIpv6 = ueNode->GetObject<Ipv6>();
    NS_ASSERT_MSG(ueIpv4 || ueIpv6,
                  "UEs need to have IPv4/IPv6 installed before EPS bearers can be activated");
    if (ueIpv4)
    {
        int32_t interface = ueIpv4->GetInterfaceForDevice(ueDevice);
        if (interface >= 0 && ueIpv4->GetNAddresses(interface) == 1)
        {
            Ipv4Address ueAddr = ueIpv4->GetAddress(interface, 0).GetLocal();
            NS_LOG_LOGIC(" UE IP address: " << ueAddr);
            m_sgwPgwApp->SetUeAddress(imsi, ueAddr);
        }
    }
    if (ueIpv6)
    {
        int32_t interface6 = ueIpv6->GetInterfaceForDevice(ueDevice);
        if (interface6 >= 0 && ueIpv6->GetNAddresses(interface6) == 2)
        {
            Ipv6Address ueAddr6 = ueIpv6->GetAddress(interface6, 1).GetAddress();
            NS_LOG_LOGIC(" UE IPv6 address: " << ueAddr6);
            m_sgwPgwApp->SetUeAddress6(imsi, ueAddr6);
        }
    }

    uint8_t bearerId = m_mmeApp->AddBearer(imsi, tft, bearer);
    ueNas->ActivateEpsBearer(bearer, tft);
    return bearerId;
}

Ptr<Node>
MmWavePointToPointEpcHelper::GetPgwNode()
{
    return m_sgwPgw;
}

Ptr<Node>
MmWavePointToPointEpcHelper::GetMmeNode()
{
    return m_mmeNode;
}

Ipv4InterfaceContainer
MmWavePointToPointEpcHelper::AssignUeIpv4Address(NetDeviceContainer ueDevices)
{
    return m_uePgwAddressHelper.Assign(ueDevices);
}

Ipv6InterfaceContainer
MmWavePointToPointEpcHelper::AssignUeIpv6Address(NetDeviceContainer ueDevices)
{
    for (NetDeviceContainer::Iterator iter = ueDevices.Begin(); iter != ueDevices.End(); iter++)
    {
        Ptr<Icmpv6L4Protocol> icmpv6 = (*iter)->GetNode()->GetObject<Icmpv6L4Protocol>();
        icmpv6->SetAttribute("DAD", BooleanValue(false));
    }
    return m_uePgwAddressHelper6.Assign(ueDevices);
}

Ipv4Address
MmWavePointToPointEpcHelper::GetUeDefaultGatewayAddress()
{
    // return the address of the tun device
    return m_sgwPgw->GetObject<Ipv4>()->GetAddress(1, 0).GetLocal();
}

Ipv6Address
MmWavePointToPointEpcHelper::GetUeDefaultGatewayAddress6()
{
    // return the address of the tun device
    return m_sgwPgw->GetObject<Ipv6>()->GetAddress(1, 1).GetAddress();
}

int64_t
MmWavePointToPointEpcHelper::AssignStreams(int64_t stream)
{
    int64_t currentStream = stream;
    NS_ABORT_MSG_UNLESS(m_sgwPgw && m_mmeNode, "Running AssignStreams on empty node pointers");
    InternetStackHelper internet;
    NodeContainer nc;
    nc.Add(m_sgwPgw);
    nc.Add(m_mmeNode);
    currentStream += internet.AssignStreams(nc, currentStream);
    return (currentStream - stream);
}

} // namespace mmwave

} // namespace ns3
