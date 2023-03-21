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
 *
 *   Modified by: Gabriel Arrobo <gab.arrobo@gmail.com>
 *                Added IPv6 support in ActivateEpsBearer function
 */

#ifndef MMWAVE_POINT_TO_POINT_EPC_HELPER_H
#define MMWAVE_POINT_TO_POINT_EPC_HELPER_H

#include <ns3/core-network-stats-calculator.h>
#include <ns3/data-rate.h>
#include <ns3/epc-helper.h>
#include <ns3/epc-tft.h>
#include <ns3/eps-bearer.h>
#include <ns3/ipv4-address-helper.h>
#include <ns3/ipv6-address-helper.h>
#include <ns3/object.h>

namespace ns3
{

class Node;
class NetDevice;
class VirtualNetDevice;
class EpcSgwPgwApplication;
class EpcX2;
class EpcMme;
class EpcUeNas;
class EpcMmeApplication;
class EpcS1apEnb;
class EpcS1apMme;

namespace mmwave
{
/**
 * \ingroup lte
 * \brief Create an EPC network with PointToPoint links
 *
 * This Helper will create an EPC network topology comprising of a
 * single node that implements both the SGW and PGW functionality, and
 * an MME node. The S1-U, S1-AP, X2-U and X2-C interfaces are realized over
 * PointToPoint links.
 */
class MmWavePointToPointEpcHelper : public EpcHelper
{
  public:
    /**
     * Constructor
     */
    MmWavePointToPointEpcHelper();

    /**
     * Destructor
     */
    virtual ~MmWavePointToPointEpcHelper();

    // inherited from Object
    /**
     *  Register this type.
     *  \return The object TypeId.
     */
    static TypeId GetTypeId(void);
    virtual void DoDispose();

    // inherited from EpcHelper
    virtual void AddEnb(Ptr<Node> enbNode, Ptr<NetDevice> lteEnbNetDevice, uint16_t cellId);
    virtual void AddUe(Ptr<NetDevice> ueLteDevice, uint64_t imsi);
    virtual void AddX2Interface(Ptr<Node> enbNode1, Ptr<Node> enbNode2);
    virtual uint8_t ActivateEpsBearer(Ptr<NetDevice> ueLteDevice,
                                      uint64_t imsi,
                                      Ptr<EpcTft> tft,
                                      EpsBearer bearer);
    virtual uint8_t ActivateEpsBearer(Ptr<NetDevice> ueLteDevice,
                                      Ptr<EpcUeNas> ueNas,
                                      uint64_t imsi,
                                      Ptr<EpcTft> tft,
                                      EpsBearer bearer);
    virtual Ptr<Node> GetPgwNode();
    virtual Ptr<Node> GetMmeNode();
    virtual Ipv4InterfaceContainer AssignUeIpv4Address(NetDeviceContainer ueDevices);
    virtual Ipv6InterfaceContainer AssignUeIpv6Address(NetDeviceContainer ueDevices);
    virtual Ipv4Address GetUeDefaultGatewayAddress();
    virtual Ipv6Address GetUeDefaultGatewayAddress6();
    virtual int64_t AssignStreams(int64_t stream) override;

  private:
    MmWavePointToPointEpcHelper(const MmWavePointToPointEpcHelper&);
    /**
     * helper to assign addresses to UE devices as well as to the TUN device of the SGW/PGW
     */
    Ipv4AddressHelper m_uePgwAddressHelper;

    /**
     * helper to assign IPv6 addresses to UE devices as well as to the TUN device of the SGW/PGW
     */
    Ipv6AddressHelper m_uePgwAddressHelper6;

    /**
     * SGW-PGW network element
     */
    Ptr<Node> m_sgwPgw;

    /**
     * SGW-PGW application
     */
    Ptr<EpcSgwPgwApplication> m_sgwPgwApp;

    /**
     * TUN device implementing tunneling of user data over GTP-U/UDP/IP
     */
    Ptr<VirtualNetDevice> m_tunDevice;

    /**
     * MME network element
     */
    Ptr<Node> m_mmeNode;

    /**
     * MME application
     */
    Ptr<EpcMmeApplication> m_mmeApp;

    /**
     * S1-U interfaces
     */

    /**
     * helper to assign addresses to S1-U NetDevices
     */
    Ipv4AddressHelper m_s1uIpv4AddressHelper;

    /**
     * The data rate to be used for the next S1-U link to be created
     */
    DataRate m_s1uLinkDataRate;

    /**
     * The delay to be used for the next S1-U link to be created
     */
    Time m_s1uLinkDelay;

    /**
     * The MTU of the next S1-U link to be created. Note that,
     * because of the additional GTP/UDP/IP tunneling overhead,
     * you need a MTU larger than the end-to-end MTU that you
     * want to support.
     */
    uint16_t m_s1uLinkMtu;

    /**
     * UDP port where the GTP-U Socket is bound, fixed by the standard as 2152
     */
    uint16_t m_gtpuUdpPort;

    /**
     * Map storing for each IMSI the corresponding eNB NetDevice
     */
    std::map<uint64_t, Ptr<NetDevice>> m_imsiEnbDeviceMap;

    /**
     * S1-AP interfaces
     */

    /**
     * helper to assign addresses to S1-AP NetDevices
     */
    Ipv4AddressHelper m_s1apIpv4AddressHelper;

    /**
     * The data rate to be used for the next S1-AP link to be created
     */
    DataRate m_s1apLinkDataRate;

    /**
     * The delay to be used for the next S1-AP link to be created
     */
    Time m_s1apLinkDelay;

    /**
     * The MTU of the next S1-AP link to be created.
     */
    uint16_t m_s1apLinkMtu;

    /**
     * UDP port where the UDP Socket is bound, fixed by the standard as
     * 36412 (it should be sctp, but it is not supported in ns-3)
     */
    uint16_t m_s1apUdpPort;

    /**
     * Map storing for each eNB the corresponding MME NetDevice
     */
    std::map<uint16_t, Ptr<NetDevice>> m_cellIdMmeDeviceMap;

    /**
     * helper to assign addresses to X2 NetDevices
     */
    Ipv4AddressHelper m_x2Ipv4AddressHelper;

    /**
     * The data rate to be used for the next X2 link to be created
     */
    DataRate m_x2LinkDataRate;

    /**
     * The delay to be used for the next X2 link to be created
     */
    Time m_x2LinkDelay;

    /**
     * The MTU of the next X2 link to be created. Note that,
     * because of some big X2 messages, you need a big MTU.
     */
    uint16_t m_x2LinkMtu;
};

} // namespace mmwave

} // namespace ns3

#endif // MMWAVE_POINT_TO_POINT_EPC_HELPER_H
