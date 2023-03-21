/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2012 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 * Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors: Nicola Baldo <nbaldo@cttc.es>
 *          Lluis Parcerisa <lparcerisa@cttc.cat>
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *          Dual Connectivity functionalities
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                               Integration of Carrier Aggregation
 */

#include <ns3/fatal-error.h>
#include <ns3/log.h>
#include <ns3/lte-enb-net-device.h>
#include <ns3/lte-enb-rrc.h>
#include <ns3/lte-ue-net-device.h>
#include <ns3/lte-ue-rrc.h>
#include <ns3/mc-ue-net-device.h>
#include <ns3/mmwave-lte-rrc-protocol-real.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/node-list.h>
#include <ns3/node.h>
#include <ns3/nstime.h>
#include <ns3/simulator.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveLteRrcProtocolReal");

const Time RRC_REAL_MSG_DELAY = MicroSeconds(500);

NS_OBJECT_ENSURE_REGISTERED(MmWaveLteUeRrcProtocolReal);

MmWaveLteUeRrcProtocolReal::MmWaveLteUeRrcProtocolReal()
    : m_ueRrcSapProvider(0),
      m_enbRrcSapProvider(0)
{
    m_ueRrcSapUser = new MemberLteUeRrcSapUser<MmWaveLteUeRrcProtocolReal>(this);
    m_completeSetupParameters.srb0SapUser =
        new LteRlcSpecificLteRlcSapUser<MmWaveLteUeRrcProtocolReal>(this);
    m_completeSetupParameters.srb1SapUser =
        new LtePdcpSpecificLtePdcpSapUser<MmWaveLteUeRrcProtocolReal>(this);
}

MmWaveLteUeRrcProtocolReal::~MmWaveLteUeRrcProtocolReal()
{
}

void
MmWaveLteUeRrcProtocolReal::DoDispose()
{
    NS_LOG_FUNCTION(this);
    delete m_ueRrcSapUser;
    delete m_completeSetupParameters.srb0SapUser;
    delete m_completeSetupParameters.srb1SapUser;
    m_rrc = 0;
}

TypeId
MmWaveLteUeRrcProtocolReal::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::MmWaveLteUeRrcProtocolReal")
                            .SetParent<Object>()
                            .SetGroupName("MmWave")
                            .AddConstructor<MmWaveLteUeRrcProtocolReal>();
    return tid;
}

void
MmWaveLteUeRrcProtocolReal::SetLteUeRrcSapProvider(LteUeRrcSapProvider* p)
{
    m_ueRrcSapProvider = p;
}

LteUeRrcSapUser*
MmWaveLteUeRrcProtocolReal::GetLteUeRrcSapUser()
{
    return m_ueRrcSapUser;
}

void
MmWaveLteUeRrcProtocolReal::SetUeRrc(Ptr<LteUeRrc> rrc)
{
    m_rrc = rrc;
}

void
MmWaveLteUeRrcProtocolReal::DoSetup(LteUeRrcSapUser::SetupParameters params)
{
    NS_LOG_FUNCTION(this);

    m_setupParameters.srb0SapProvider = params.srb0SapProvider;
    m_setupParameters.srb1SapProvider = params.srb1SapProvider;
    m_ueRrcSapProvider->CompleteSetup(m_completeSetupParameters);
}

void
MmWaveLteUeRrcProtocolReal::DoSendRrcConnectionRequest(LteRrcSap::RrcConnectionRequest msg)
{
    // initialize the RNTI and get the EnbLteRrcSapProvider for the
    // eNB we are currently attached to
    m_rnti = m_rrc->GetRnti();
    SetEnbRrcSapProvider();

    Simulator::Schedule(RRC_REAL_MSG_DELAY,
                        &LteEnbRrcSapProvider::RecvRrcConnectionRequest,
                        m_enbRrcSapProvider,
                        m_rnti,
                        msg);

    // real RRC code
    // Ptr<Packet> packet = Create<Packet> ();

    // RrcConnectionRequestHeader rrcConnectionRequestHeader;
    // rrcConnectionRequestHeader.SetMessage (msg);

    // packet->AddHeader (rrcConnectionRequestHeader);

    // LteRlcSapProvider::TransmitPdcpPduParameters transmitPdcpPduParameters;
    // transmitPdcpPduParameters.pdcpPdu = packet;
    // transmitPdcpPduParameters.rnti = m_rnti;
    // transmitPdcpPduParameters.lcid = 0;

    // m_setupParameters.srb0SapProvider->TransmitPdcpPdu (transmitPdcpPduParameters);
}

void
MmWaveLteUeRrcProtocolReal::DoSendRrcConnectionSetupCompleted(
    LteRrcSap::RrcConnectionSetupCompleted msg)
{
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionSetupCompleteHeader rrcConnectionSetupCompleteHeader;
    rrcConnectionSetupCompleteHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionSetupCompleteHeader);

    LtePdcpSapProvider::TransmitPdcpSduParameters transmitPdcpSduParameters;
    transmitPdcpSduParameters.pdcpSdu = packet;
    transmitPdcpSduParameters.rnti = m_rnti;
    transmitPdcpSduParameters.lcid = 1;

    if (m_setupParameters.srb1SapProvider)
    {
        m_setupParameters.srb1SapProvider->TransmitPdcpSdu(transmitPdcpSduParameters);
    }
}

void
MmWaveLteUeRrcProtocolReal::DoSendRrcConnectionReconfigurationCompleted(
    LteRrcSap::RrcConnectionReconfigurationCompleted msg)
{
    // re-initialize the RNTI and get the EnbLteRrcSapProvider for the
    // eNB we are currently attached to
    m_rnti = m_rrc->GetRnti();
    SetEnbRrcSapProvider();

    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionReconfigurationCompleteHeader rrcConnectionReconfigurationCompleteHeader;
    rrcConnectionReconfigurationCompleteHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionReconfigurationCompleteHeader);

    LtePdcpSapProvider::TransmitPdcpSduParameters transmitPdcpSduParameters;
    transmitPdcpSduParameters.pdcpSdu = packet;
    transmitPdcpSduParameters.rnti = m_rnti;
    transmitPdcpSduParameters.lcid = 1;
    NS_LOG_INFO("Tx RRC Connection reconf completed");
    m_setupParameters.srb1SapProvider->TransmitPdcpSdu(transmitPdcpSduParameters);
}

void
MmWaveLteUeRrcProtocolReal::DoSendMeasurementReport(LteRrcSap::MeasurementReport msg)
{
    // re-initialize the RNTI and get the EnbLteRrcSapProvider for the
    // eNB we are currently attached to
    m_rnti = m_rrc->GetRnti();
    SetEnbRrcSapProvider();

    Ptr<Packet> packet = Create<Packet>();

    MeasurementReportHeader measurementReportHeader;
    measurementReportHeader.SetMessage(msg);

    packet->AddHeader(measurementReportHeader);

    LtePdcpSapProvider::TransmitPdcpSduParameters transmitPdcpSduParameters;
    transmitPdcpSduParameters.pdcpSdu = packet;
    transmitPdcpSduParameters.rnti = m_rnti;
    transmitPdcpSduParameters.lcid = 1;

    m_setupParameters.srb1SapProvider->TransmitPdcpSdu(transmitPdcpSduParameters);
}

void
MmWaveLteUeRrcProtocolReal::DoSendNotifySecondaryCellConnected(uint16_t mmWaveRnti,
                                                               uint16_t mmWaveCellId)
{
    m_rnti = m_rrc->GetRnti();
    SetEnbRrcSapProvider();

    Ptr<Packet> packet = Create<Packet>();

    RrcNotifySecondaryConnectedHeader rrcNotifyHeader;
    rrcNotifyHeader.SetMessage(mmWaveCellId, mmWaveRnti);

    packet->AddHeader(rrcNotifyHeader);

    LtePdcpSapProvider::TransmitPdcpSduParameters transmitPdcpSduParameters;
    transmitPdcpSduParameters.pdcpSdu = packet;
    transmitPdcpSduParameters.rnti = m_rnti;
    transmitPdcpSduParameters.lcid = 1;

    m_setupParameters.srb1SapProvider->TransmitPdcpSdu(transmitPdcpSduParameters);
}

void
MmWaveLteUeRrcProtocolReal::DoSendRrcConnectionReestablishmentRequest(
    LteRrcSap::RrcConnectionReestablishmentRequest msg)
{
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionReestablishmentRequestHeader rrcConnectionReestablishmentRequestHeader;
    rrcConnectionReestablishmentRequestHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionReestablishmentRequestHeader);

    LteRlcSapProvider::TransmitPdcpPduParameters transmitPdcpPduParameters;
    transmitPdcpPduParameters.pdcpPdu = packet;
    transmitPdcpPduParameters.rnti = m_rnti;
    transmitPdcpPduParameters.lcid = 0;

    m_setupParameters.srb0SapProvider->TransmitPdcpPdu(transmitPdcpPduParameters);
}

void
MmWaveLteUeRrcProtocolReal::DoSendRrcConnectionReestablishmentComplete(
    LteRrcSap::RrcConnectionReestablishmentComplete msg)
{
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionReestablishmentCompleteHeader rrcConnectionReestablishmentCompleteHeader;
    rrcConnectionReestablishmentCompleteHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionReestablishmentCompleteHeader);

    LtePdcpSapProvider::TransmitPdcpSduParameters transmitPdcpSduParameters;
    transmitPdcpSduParameters.pdcpSdu = packet;
    transmitPdcpSduParameters.rnti = m_rnti;
    transmitPdcpSduParameters.lcid = 1;

    m_setupParameters.srb1SapProvider->TransmitPdcpSdu(transmitPdcpSduParameters);
}

void
MmWaveLteUeRrcProtocolReal::SetEnbRrcSapProvider()
{
    uint16_t cellId = m_rrc->GetCellId();

    // walk list of all nodes to get the peer eNB
    Ptr<LteEnbNetDevice> enbDev;
    Ptr<MmWaveEnbNetDevice> mmWaveEnbDev;
    NodeList::Iterator listEnd = NodeList::End();
    bool found = false;
    for (NodeList::Iterator i = NodeList::Begin(); (i != listEnd) && (!found); ++i)
    {
        Ptr<Node> node = *i;
        int nDevs = node->GetNDevices();
        for (int j = 0; (j < nDevs) && (!found); j++)
        {
            enbDev = node->GetDevice(j)->GetObject<LteEnbNetDevice>();
            if (!enbDev)
            {
                // check if it is a MmWave eNB
                mmWaveEnbDev = node->GetDevice(j)->GetObject<MmWaveEnbNetDevice>();
                if (!mmWaveEnbDev)
                {
                    continue;
                }
                else
                {
                    if (mmWaveEnbDev->HasCellId(cellId))
                    {
                        found = true;
                        break;
                    }
                }
            }
            else
            {
                if (enbDev->GetCellId() == cellId)
                {
                    found = true;
                    break;
                }
            }
        }
    }
    NS_ASSERT_MSG(found, " Unable to find eNB with CellId =" << cellId);
    if (enbDev)
    {
        m_enbRrcSapProvider = enbDev->GetRrc()->GetLteEnbRrcSapProvider();
        Ptr<MmWaveLteEnbRrcProtocolReal> enbRrcProtocolReal =
            enbDev->GetRrc()->GetObject<MmWaveLteEnbRrcProtocolReal>();
        enbRrcProtocolReal->SetUeRrcSapProvider(m_rnti, m_ueRrcSapProvider);
    }
    else if (mmWaveEnbDev)
    {
        m_enbRrcSapProvider = mmWaveEnbDev->GetRrc()->GetLteEnbRrcSapProvider();
        Ptr<MmWaveLteEnbRrcProtocolReal> enbRrcProtocolReal =
            mmWaveEnbDev->GetRrc()->GetObject<MmWaveLteEnbRrcProtocolReal>();
        enbRrcProtocolReal->SetUeRrcSapProvider(m_rnti, m_ueRrcSapProvider);
    }
    else
    {
        NS_FATAL_ERROR("Nor LTE eNB neither MmWave eNB");
    }
}

void
MmWaveLteUeRrcProtocolReal::DoReceivePdcpPdu(Ptr<Packet> p)
{
    NS_LOG_FUNCTION(this);
    // Get type of message received
    RrcDlCcchMessage rrcDlCcchMessage;
    p->PeekHeader(rrcDlCcchMessage);
    NS_LOG_INFO(rrcDlCcchMessage);

    // Declare possible headers to receive
    RrcConnectionReestablishmentHeader rrcConnectionReestablishmentHeader;
    RrcConnectionReestablishmentRejectHeader rrcConnectionReestablishmentRejectHeader;
    RrcConnectionSetupHeader rrcConnectionSetupHeader;
    RrcConnectionRejectHeader rrcConnectionRejectHeader;
    RrcConnectToMmWaveHeader rrcConnectToMmWaveHeader;

    // Declare possible messages
    LteRrcSap::RrcConnectionReestablishment rrcConnectionReestablishmentMsg;
    LteRrcSap::RrcConnectionReestablishmentReject rrcConnectionReestablishmentRejectMsg;
    LteRrcSap::RrcConnectionSetup rrcConnectionSetupMsg;
    LteRrcSap::RrcConnectionReject rrcConnectionRejectMsg;

    // Deserialize packet and call member recv function with appropiate structure
    switch (rrcDlCcchMessage.GetMessageType())
    {
    case 0:
        // RrcConnectionReestablishment
        p->RemoveHeader(rrcConnectionReestablishmentHeader);
        rrcConnectionReestablishmentMsg = rrcConnectionReestablishmentHeader.GetMessage();
        m_ueRrcSapProvider->RecvRrcConnectionReestablishment(rrcConnectionReestablishmentMsg);
        break;
    case 1:
        // RrcConnectionReestablishmentReject
        p->RemoveHeader(rrcConnectionReestablishmentRejectHeader);
        rrcConnectionReestablishmentRejectMsg =
            rrcConnectionReestablishmentRejectHeader.GetMessage();
        // m_ueRrcSapProvider->RecvRrcConnectionReestablishmentReject
        // (rrcConnectionReestablishmentRejectMsg);
        break;
    case 2:
        // RrcConnectionReject
        p->RemoveHeader(rrcConnectionRejectHeader);
        rrcConnectionRejectMsg = rrcConnectionRejectHeader.GetMessage();
        m_ueRrcSapProvider->RecvRrcConnectionReject(rrcConnectionRejectMsg);
        break;
    case 3:
        // RrcConnectionSetup
        p->RemoveHeader(rrcConnectionSetupHeader);
        rrcConnectionSetupMsg = rrcConnectionSetupHeader.GetMessage();
        m_ueRrcSapProvider->RecvRrcConnectionSetup(rrcConnectionSetupMsg);
        break;
    case 4:
        // RrcConnectToMmWave
        p->RemoveHeader(rrcConnectToMmWaveHeader);
        uint16_t mmWaveCellId = rrcConnectToMmWaveHeader.GetMessage();
        NS_LOG_INFO("Recv RRC connect to MmWave cellId " << mmWaveCellId);
        m_ueRrcSapProvider->RecvRrcConnectToMmWave(mmWaveCellId);
        break;
    }
}

void
MmWaveLteUeRrcProtocolReal::DoReceivePdcpSdu(LtePdcpSapUser::ReceivePdcpSduParameters params)
{
    // Get type of message received
    RrcDlDcchMessage rrcDlDcchMessage;
    params.pdcpSdu->PeekHeader(rrcDlDcchMessage);

    // Declare possible headers to receive
    RrcConnectionReconfigurationHeader rrcConnectionReconfigurationHeader;
    RrcConnectionReleaseHeader rrcConnectionReleaseHeader;
    RrcConnectionSwitchHeader rrcSwitchHeader;

    // Declare possible messages to receive
    LteRrcSap::RrcConnectionReconfiguration rrcConnectionReconfigurationMsg;
    LteRrcSap::RrcConnectionRelease rrcConnectionReleaseMsg;
    LteRrcSap::RrcConnectionSwitch rrcConnectionSwitchMsg;
    // Deserialize packet and call member recv function with appropiate structure
    switch (rrcDlDcchMessage.GetMessageType())
    {
    case 4:
        params.pdcpSdu->RemoveHeader(rrcConnectionReconfigurationHeader);
        rrcConnectionReconfigurationMsg = rrcConnectionReconfigurationHeader.GetMessage();
        m_ueRrcSapProvider->RecvRrcConnectionReconfiguration(rrcConnectionReconfigurationMsg);
        break;
    case 5:
        params.pdcpSdu->RemoveHeader(rrcConnectionReleaseHeader);
        rrcConnectionReleaseMsg = rrcConnectionReleaseHeader.GetMessage();
        // m_ueRrcSapProvider->RecvRrcConnectionRelease (rrcConnectionReleaseMsg);
        break;
    case 6:
        params.pdcpSdu->RemoveHeader(rrcSwitchHeader);
        rrcConnectionSwitchMsg = rrcSwitchHeader.GetMessage();
        m_ueRrcSapProvider->RecvRrcConnectionSwitch(rrcConnectionSwitchMsg);
        break;
    }
}

NS_OBJECT_ENSURE_REGISTERED(MmWaveLteEnbRrcProtocolReal);

MmWaveLteEnbRrcProtocolReal::MmWaveLteEnbRrcProtocolReal()
    : m_enbRrcSapProvider(0)
{
    NS_LOG_FUNCTION(this);
    m_enbRrcSapUser = new MemberLteEnbRrcSapUser<MmWaveLteEnbRrcProtocolReal>(this);
}

MmWaveLteEnbRrcProtocolReal::~MmWaveLteEnbRrcProtocolReal()
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveLteEnbRrcProtocolReal::DoDispose()
{
    NS_LOG_FUNCTION(this);
    delete m_enbRrcSapUser;
    for (std::map<uint16_t, LteEnbRrcSapProvider::CompleteSetupUeParameters>::iterator it =
             m_completeSetupUeParametersMap.begin();
         it != m_completeSetupUeParametersMap.end();
         ++it)
    {
        delete it->second.srb0SapUser;
        delete it->second.srb1SapUser;
    }
    m_completeSetupUeParametersMap.clear();
}

TypeId
MmWaveLteEnbRrcProtocolReal::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::MmWaveLteEnbRrcProtocolReal")
                            .SetParent<Object>()
                            .SetGroupName("Lte")
                            .AddConstructor<MmWaveLteEnbRrcProtocolReal>();
    return tid;
}

void
MmWaveLteEnbRrcProtocolReal::SetLteEnbRrcSapProvider(LteEnbRrcSapProvider* p)
{
    m_enbRrcSapProvider = p;
}

LteEnbRrcSapUser*
MmWaveLteEnbRrcProtocolReal::GetLteEnbRrcSapUser()
{
    return m_enbRrcSapUser;
}

void
MmWaveLteEnbRrcProtocolReal::SetCellId(uint16_t cellId)
{
    m_cellId = cellId;
}

LteUeRrcSapProvider*
MmWaveLteEnbRrcProtocolReal::GetUeRrcSapProvider(uint16_t rnti)
{
    std::map<uint16_t, LteUeRrcSapProvider*>::const_iterator it;
    it = m_enbRrcSapProviderMap.find(rnti);
    NS_ASSERT_MSG(it != m_enbRrcSapProviderMap.end(), "could not find RNTI = " << rnti);
    return it->second;
}

void
MmWaveLteEnbRrcProtocolReal::SetUeRrcSapProvider(uint16_t rnti, LteUeRrcSapProvider* p)
{
    std::map<uint16_t, LteUeRrcSapProvider*>::iterator it;
    it = m_enbRrcSapProviderMap.find(rnti);
    NS_ASSERT_MSG(it != m_enbRrcSapProviderMap.end(), "could not find RNTI = " << rnti);
    it->second = p;
}

void
MmWaveLteEnbRrcProtocolReal::DoSetupUe(uint16_t rnti, LteEnbRrcSapUser::SetupUeParameters params)
{
    NS_LOG_FUNCTION(this << rnti);

    // // walk list of all nodes to get the peer UE RRC SAP Provider
    // Ptr<LteUeRrc> ueRrc;
    // NodeList::Iterator listEnd = NodeList::End ();
    // bool found = false;
    // for (NodeList::Iterator i = NodeList::Begin (); (i != listEnd) && (found == false); i++)
    //   {
    //     Ptr<Node> node = *i;
    //     int nDevs = node->GetNDevices ();
    //     for (int j = 0; j < nDevs; j++)
    //       {
    //         Ptr<LteUeNetDevice> ueDev = node->GetDevice (j)->GetObject <LteUeNetDevice> ();
    //         if (!ueDev)
    //           {
    //             continue;
    //           }
    //         else
    //           {
    //             ueRrc = ueDev->GetRrc ();
    //             if ((ueRrc->GetRnti () == rnti) && (ueRrc->GetCellId () == m_cellId))
    //               {
    //              found = true;
    //              break;
    //               }
    //           }
    //       }
    //   }
    // NS_ASSERT_MSG (found , " Unable to find UE with RNTI=" << rnti << " cellId=" << m_cellId);
    // m_enbRrcSapProviderMap[rnti] = ueRrc->GetLteUeRrcSapProvider ();

    // just create empty entry, the UeRrcSapProvider will be set by the
    // ue upon connection request or connection reconfiguration
    // completed
    m_enbRrcSapProviderMap[rnti] = 0;

    // Store SetupUeParameters
    m_setupUeParametersMap[rnti] = params;

    LteEnbRrcSapProvider::CompleteSetupUeParameters completeSetupUeParameters;
    std::map<uint16_t, LteEnbRrcSapProvider::CompleteSetupUeParameters>::iterator csupIt =
        m_completeSetupUeParametersMap.find(rnti);
    if (csupIt == m_completeSetupUeParametersMap.end())
    {
        // Create LteRlcSapUser, LtePdcpSapUser
        LteRlcSapUser* srb0SapUser = new MmWaveRealProtocolRlcSapUser(this, rnti);
        LtePdcpSapUser* srb1SapUser =
            new LtePdcpSpecificLtePdcpSapUser<MmWaveLteEnbRrcProtocolReal>(this);
        completeSetupUeParameters.srb0SapUser = srb0SapUser;
        completeSetupUeParameters.srb1SapUser = srb1SapUser;
        // Store LteRlcSapUser, LtePdcpSapUser
        m_completeSetupUeParametersMap[rnti] = completeSetupUeParameters;
    }
    else
    {
        completeSetupUeParameters = csupIt->second;
    }
    m_enbRrcSapProvider->CompleteSetupUe(rnti, completeSetupUeParameters);
}

void
MmWaveLteEnbRrcProtocolReal::DoRemoveUe(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);
    std::map<uint16_t, LteEnbRrcSapProvider::CompleteSetupUeParameters>::iterator it =
        m_completeSetupUeParametersMap.find(rnti);
    NS_ASSERT(it != m_completeSetupUeParametersMap.end());
    delete it->second.srb0SapUser;
    delete it->second.srb1SapUser;
    m_completeSetupUeParametersMap.erase(it);
    m_enbRrcSapProviderMap.erase(rnti);
    m_setupUeParametersMap.erase(rnti);
}

void
MmWaveLteEnbRrcProtocolReal::DoSendSystemInformation(uint16_t cellId,
                                                     LteRrcSap::SystemInformation msg)
{
    NS_LOG_FUNCTION(this << cellId);
    // walk list of all nodes to get UEs with this cellId
    Ptr<LteUeRrc> ueRrc;
    for (NodeList::Iterator i = NodeList::Begin(); i != NodeList::End(); ++i)
    {
        Ptr<Node> node = *i;
        int nDevs = node->GetNDevices();
        NS_LOG_LOGIC("Consider UE with nDevs " << nDevs);

        for (int j = 0; j < nDevs; ++j)
        {
            Ptr<mmwave::MmWaveUeNetDevice> ueDev =
                node->GetDevice(j)->GetObject<mmwave::MmWaveUeNetDevice>();
            if (ueDev)
            {
                ueRrc = ueDev->GetRrc();
                NS_LOG_LOGIC("considering UE IMSI " << ueDev->GetImsi() << " that has cellId "
                                                    << ueRrc->GetCellId());
                if (ueRrc->GetCellId() == cellId)
                {
                    NS_LOG_LOGIC("sending SI to IMSI " << ueDev->GetImsi());
                    ueRrc->GetLteUeRrcSapProvider()->RecvSystemInformation(msg);
                    Simulator::Schedule(RRC_REAL_MSG_DELAY,
                                        &LteUeRrcSapProvider::RecvSystemInformation,
                                        ueRrc->GetLteUeRrcSapProvider(),
                                        msg);
                }
            }
            else
            {
                // it may be a MC device
                Ptr<McUeNetDevice> mcUeDev = node->GetDevice(j)->GetObject<McUeNetDevice>();
                if (mcUeDev)
                {
                    ueRrc = mcUeDev->GetLteRrc();
                    NS_LOG_LOGIC("considering UE IMSI " << mcUeDev->GetImsi() << " that has cellId "
                                                        << ueRrc->GetCellId());
                    if (ueRrc->GetCellId() == cellId)
                    {
                        NS_LOG_LOGIC("sending SI to IMSI " << mcUeDev->GetImsi());
                        ueRrc->GetLteUeRrcSapProvider()->RecvSystemInformation(msg);
                        Simulator::Schedule(RRC_REAL_MSG_DELAY,
                                            &LteUeRrcSapProvider::RecvSystemInformation,
                                            ueRrc->GetLteUeRrcSapProvider(),
                                            msg);
                    } // if the first condition is false, the second is not executed
                    else if (mcUeDev->GetMmWaveRrc() &&
                             mcUeDev->GetMmWaveRrc()->GetCellId() == cellId)
                    {
                        NS_LOG_LOGIC("sending SI to IMSI " << mcUeDev->GetImsi());
                        Simulator::Schedule(RRC_REAL_MSG_DELAY,
                                            &LteUeRrcSapProvider::RecvSystemInformation,
                                            mcUeDev->GetMmWaveRrc()->GetLteUeRrcSapProvider(),
                                            msg);
                    }
                }
                else
                {
                    // it may be a LTE device
                    Ptr<LteUeNetDevice> ueDev = node->GetDevice(j)->GetObject<LteUeNetDevice>();
                    if (ueDev)
                    {
                        ueRrc = ueDev->GetRrc();
                        NS_LOG_LOGIC("considering UE IMSI " << ueDev->GetImsi()
                                                            << " that has cellId "
                                                            << ueRrc->GetCellId());
                        if (ueRrc->GetCellId() == cellId)
                        {
                            NS_LOG_LOGIC("sending SI to IMSI " << ueDev->GetImsi());
                            Simulator::Schedule(RRC_REAL_MSG_DELAY,
                                                &LteUeRrcSapProvider::RecvSystemInformation,
                                                ueRrc->GetLteUeRrcSapProvider(),
                                                msg);
                        }
                    }
                }
            }
        }
    }
}

void
MmWaveLteEnbRrcProtocolReal::DoSendRrcConnectionSetup(uint16_t rnti,
                                                      LteRrcSap::RrcConnectionSetup msg)
{
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionSetupHeader rrcConnectionSetupHeader;
    rrcConnectionSetupHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionSetupHeader);

    LteRlcSapProvider::TransmitPdcpPduParameters transmitPdcpPduParameters;
    transmitPdcpPduParameters.pdcpPdu = packet;
    transmitPdcpPduParameters.rnti = rnti;
    transmitPdcpPduParameters.lcid = 0;

    if (m_setupUeParametersMap.find(rnti) == m_setupUeParametersMap.end())
    {
        NS_LOG_ERROR("RNTI not found in Enb setup parameters Map!");
    }
    else
    {
        NS_LOG_INFO("Queue RRC connection setup " << packet << " rnti " << rnti << " cellId "
                                                  << m_cellId);
        m_setupUeParametersMap[rnti].srb0SapProvider->TransmitPdcpPdu(transmitPdcpPduParameters);
    }
}

void
MmWaveLteEnbRrcProtocolReal::DoSendRrcConnectionReject(uint16_t rnti,
                                                       LteRrcSap::RrcConnectionReject msg)
{
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionRejectHeader rrcConnectionRejectHeader;
    rrcConnectionRejectHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionRejectHeader);

    LteRlcSapProvider::TransmitPdcpPduParameters transmitPdcpPduParameters;
    transmitPdcpPduParameters.pdcpPdu = packet;
    transmitPdcpPduParameters.rnti = rnti;
    transmitPdcpPduParameters.lcid = 0;

    m_setupUeParametersMap[rnti].srb0SapProvider->TransmitPdcpPdu(transmitPdcpPduParameters);
}

void
MmWaveLteEnbRrcProtocolReal::DoSendRrcConnectionSwitch(uint16_t rnti,
                                                       LteRrcSap::RrcConnectionSwitch msg)
{
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionSwitchHeader rrcSwitchHeader;
    rrcSwitchHeader.SetMessage(msg);

    packet->AddHeader(rrcSwitchHeader);

    LtePdcpSapProvider::TransmitPdcpSduParameters transmitPdcpSduParameters;
    transmitPdcpSduParameters.pdcpSdu = packet;
    transmitPdcpSduParameters.rnti = rnti;
    transmitPdcpSduParameters.lcid = 1;

    m_setupUeParametersMap[rnti].srb1SapProvider->TransmitPdcpSdu(transmitPdcpSduParameters);
}

void
MmWaveLteEnbRrcProtocolReal::DoSendRrcConnectToMmWave(uint16_t rnti, uint16_t mmWaveId)
{
    NS_LOG_FUNCTION(this << " rnti " << rnti << " mmWave cellId " << mmWaveId);
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectToMmWaveHeader connectToMmWaveHeader;
    connectToMmWaveHeader.SetMessage(mmWaveId);

    packet->AddHeader(connectToMmWaveHeader);

    NS_LOG_INFO(connectToMmWaveHeader);

    LteRlcSapProvider::TransmitPdcpPduParameters transmitPdcpPduParameters;
    transmitPdcpPduParameters.pdcpPdu = packet;
    transmitPdcpPduParameters.rnti = rnti;
    transmitPdcpPduParameters.lcid = 0;

    m_setupUeParametersMap[rnti].srb0SapProvider->TransmitPdcpPdu(transmitPdcpPduParameters);
}

void
MmWaveLteEnbRrcProtocolReal::DoSendRrcConnectionReconfiguration(
    uint16_t rnti,
    LteRrcSap::RrcConnectionReconfiguration msg)
{
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionReconfigurationHeader rrcConnectionReconfigurationHeader;
    rrcConnectionReconfigurationHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionReconfigurationHeader);

    LtePdcpSapProvider::TransmitPdcpSduParameters transmitPdcpSduParameters;
    transmitPdcpSduParameters.pdcpSdu = packet;
    transmitPdcpSduParameters.rnti = rnti;
    transmitPdcpSduParameters.lcid = 1;

    m_setupUeParametersMap[rnti].srb1SapProvider->TransmitPdcpSdu(transmitPdcpSduParameters);
}

void
MmWaveLteEnbRrcProtocolReal::DoSendRrcConnectionReestablishment(
    uint16_t rnti,
    LteRrcSap::RrcConnectionReestablishment msg)
{
    NS_LOG_FUNCTION(this << " rnti " << rnti);
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionReestablishmentHeader rrcConnectionReestablishmentHeader;
    rrcConnectionReestablishmentHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionReestablishmentHeader);

    LteRlcSapProvider::TransmitPdcpPduParameters transmitPdcpPduParameters;
    transmitPdcpPduParameters.pdcpPdu = packet;
    transmitPdcpPduParameters.rnti = rnti;
    transmitPdcpPduParameters.lcid = 0;

    m_setupUeParametersMap[rnti].srb0SapProvider->TransmitPdcpPdu(transmitPdcpPduParameters);
}

void
MmWaveLteEnbRrcProtocolReal::DoSendRrcConnectionReestablishmentReject(
    uint16_t rnti,
    LteRrcSap::RrcConnectionReestablishmentReject msg)
{
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionReestablishmentRejectHeader rrcConnectionReestablishmentRejectHeader;
    rrcConnectionReestablishmentRejectHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionReestablishmentRejectHeader);

    LteRlcSapProvider::TransmitPdcpPduParameters transmitPdcpPduParameters;
    transmitPdcpPduParameters.pdcpPdu = packet;
    transmitPdcpPduParameters.rnti = rnti;
    transmitPdcpPduParameters.lcid = 0;

    m_setupUeParametersMap[rnti].srb0SapProvider->TransmitPdcpPdu(transmitPdcpPduParameters);
}

void
MmWaveLteEnbRrcProtocolReal::DoSendRrcConnectionRelease(uint16_t rnti,
                                                        LteRrcSap::RrcConnectionRelease msg)
{
    Ptr<Packet> packet = Create<Packet>();

    RrcConnectionReleaseHeader rrcConnectionReleaseHeader;
    rrcConnectionReleaseHeader.SetMessage(msg);

    packet->AddHeader(rrcConnectionReleaseHeader);

    LtePdcpSapProvider::TransmitPdcpSduParameters transmitPdcpSduParameters;
    transmitPdcpSduParameters.pdcpSdu = packet;
    transmitPdcpSduParameters.rnti = rnti;
    transmitPdcpSduParameters.lcid = 1;

    m_setupUeParametersMap[rnti].srb1SapProvider->TransmitPdcpSdu(transmitPdcpSduParameters);
}

void
MmWaveLteEnbRrcProtocolReal::DoReceivePdcpPdu(uint16_t rnti, Ptr<Packet> p)
{
    // Get type of message received
    RrcUlCcchMessage rrcUlCcchMessage;
    p->PeekHeader(rrcUlCcchMessage);

    // Declare possible headers to receive
    RrcConnectionReestablishmentRequestHeader rrcConnectionReestablishmentRequestHeader;
    RrcConnectionRequestHeader rrcConnectionRequestHeader;

    // Deserialize packet and call member recv function with appropiate structure
    switch (rrcUlCcchMessage.GetMessageType())
    {
    case 0:
        p->RemoveHeader(rrcConnectionReestablishmentRequestHeader);
        LteRrcSap::RrcConnectionReestablishmentRequest rrcConnectionReestablishmentRequestMsg;
        rrcConnectionReestablishmentRequestMsg =
            rrcConnectionReestablishmentRequestHeader.GetMessage();
        m_enbRrcSapProvider->RecvRrcConnectionReestablishmentRequest(
            rnti,
            rrcConnectionReestablishmentRequestMsg);
        break;
    case 1:
        p->RemoveHeader(rrcConnectionRequestHeader);
        LteRrcSap::RrcConnectionRequest rrcConnectionRequestMsg;
        rrcConnectionRequestMsg = rrcConnectionRequestHeader.GetMessage();
        m_enbRrcSapProvider->RecvRrcConnectionRequest(rnti, rrcConnectionRequestMsg);
        break;
    }
}

void
MmWaveLteEnbRrcProtocolReal::DoReceivePdcpSdu(LtePdcpSapUser::ReceivePdcpSduParameters params)
{
    // Get type of message received
    RrcUlDcchMessage rrcUlDcchMessage;
    params.pdcpSdu->PeekHeader(rrcUlDcchMessage);

    // Declare possible headers to receive
    MeasurementReportHeader measurementReportHeader;
    RrcConnectionReconfigurationCompleteHeader rrcConnectionReconfigurationCompleteHeader;
    RrcConnectionReestablishmentCompleteHeader rrcConnectionReestablishmentCompleteHeader;
    RrcConnectionSetupCompleteHeader rrcConnectionSetupCompleteHeader;
    RrcNotifySecondaryConnectedHeader rrcNotifyHeader;

    // Declare possible messages to receive
    LteRrcSap::MeasurementReport measurementReportMsg;
    LteRrcSap::RrcConnectionReconfigurationCompleted rrcConnectionReconfigurationCompleteMsg;
    LteRrcSap::RrcConnectionReestablishmentComplete rrcConnectionReestablishmentCompleteMsg;
    LteRrcSap::RrcConnectionSetupCompleted rrcConnectionSetupCompletedMsg;

    // Deserialize packet and call member recv function with appropiate structure
    switch (rrcUlDcchMessage.GetMessageType())
    {
    case 1:
        params.pdcpSdu->RemoveHeader(measurementReportHeader);
        measurementReportMsg = measurementReportHeader.GetMessage();
        m_enbRrcSapProvider->RecvMeasurementReport(params.rnti, measurementReportMsg);
        break;
    case 2:
        params.pdcpSdu->RemoveHeader(rrcConnectionReconfigurationCompleteHeader);
        rrcConnectionReconfigurationCompleteMsg =
            rrcConnectionReconfigurationCompleteHeader.GetMessage();
        m_enbRrcSapProvider->RecvRrcConnectionReconfigurationCompleted(
            params.rnti,
            rrcConnectionReconfigurationCompleteMsg);
        break;
    case 3:
        params.pdcpSdu->RemoveHeader(rrcConnectionReestablishmentCompleteHeader);
        rrcConnectionReestablishmentCompleteMsg =
            rrcConnectionReestablishmentCompleteHeader.GetMessage();
        m_enbRrcSapProvider->RecvRrcConnectionReestablishmentComplete(
            params.rnti,
            rrcConnectionReestablishmentCompleteMsg);
        break;
    case 4:
        params.pdcpSdu->RemoveHeader(rrcConnectionSetupCompleteHeader);
        rrcConnectionSetupCompletedMsg = rrcConnectionSetupCompleteHeader.GetMessage();
        m_enbRrcSapProvider->RecvRrcConnectionSetupCompleted(params.rnti,
                                                             rrcConnectionSetupCompletedMsg);
        break;
    case 5:
        params.pdcpSdu->RemoveHeader(rrcNotifyHeader);
        std::pair<uint16_t, uint16_t> rrcNotifyPair;
        rrcNotifyPair = rrcNotifyHeader.GetMessage();
        m_enbRrcSapProvider->RecvRrcSecondaryCellInitialAccessSuccessful(params.rnti,
                                                                         rrcNotifyPair.second,
                                                                         rrcNotifyPair.first);
        break;
    }
}

Ptr<Packet>
MmWaveLteEnbRrcProtocolReal::DoEncodeHandoverPreparationInformation(
    LteRrcSap::HandoverPreparationInfo msg)
{
    HandoverPreparationInfoHeader h;
    h.SetMessage(msg);

    Ptr<Packet> p = Create<Packet>();
    p->AddHeader(h);
    return p;
}

LteRrcSap::HandoverPreparationInfo
MmWaveLteEnbRrcProtocolReal::DoDecodeHandoverPreparationInformation(Ptr<Packet> p)
{
    HandoverPreparationInfoHeader h;
    p->RemoveHeader(h);
    LteRrcSap::HandoverPreparationInfo msg = h.GetMessage();
    return msg;
}

Ptr<Packet>
MmWaveLteEnbRrcProtocolReal::DoEncodeHandoverCommand(LteRrcSap::RrcConnectionReconfiguration msg)
{
    RrcConnectionReconfigurationHeader h;
    h.SetMessage(msg);
    Ptr<Packet> p = Create<Packet>();
    p->AddHeader(h);
    return p;
}

LteRrcSap::RrcConnectionReconfiguration
MmWaveLteEnbRrcProtocolReal::DoDecodeHandoverCommand(Ptr<Packet> p)
{
    RrcConnectionReconfigurationHeader h;
    p->RemoveHeader(h);
    LteRrcSap::RrcConnectionReconfiguration msg = h.GetMessage();
    return msg;
}

//////////////////////////////////////////////////////

MmWaveRealProtocolRlcSapUser::MmWaveRealProtocolRlcSapUser(MmWaveLteEnbRrcProtocolReal* pdcp,
                                                           uint16_t rnti)
    : m_pdcp(pdcp),
      m_rnti(rnti)
{
}

MmWaveRealProtocolRlcSapUser::MmWaveRealProtocolRlcSapUser()
{
}

void
MmWaveRealProtocolRlcSapUser::ReceivePdcpPdu(Ptr<Packet> p)
{
    m_pdcp->DoReceivePdcpPdu(m_rnti, p);
}

} // namespace mmwave

} // namespace ns3
