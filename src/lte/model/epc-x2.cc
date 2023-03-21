/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2012 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 * Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab
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
 * Author: Manuel Requena <manuel.requena@cttc.es>
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *          Dual Connectivity functionalities
 */

#include "ns3/epc-x2.h"

#include "ns3/epc-gtpu-header.h"
#include "ns3/epc-x2-header.h"
#include "ns3/epc-x2-tag.h"
#include "ns3/inet-socket-address.h"
#include "ns3/log.h"
#include "ns3/lte-pdcp-tag.h"
#include "ns3/node.h"
#include "ns3/packet.h"

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("EpcX2");

X2IfaceInfo::X2IfaceInfo(Ipv4Address remoteIpAddr,
                         Ptr<Socket> localCtrlPlaneSocket,
                         Ptr<Socket> localUserPlaneSocket)
{
    m_remoteIpAddr = remoteIpAddr;
    m_localCtrlPlaneSocket = localCtrlPlaneSocket;
    m_localUserPlaneSocket = localUserPlaneSocket;
}

X2IfaceInfo::~X2IfaceInfo(void)
{
    m_localCtrlPlaneSocket = 0;
    m_localUserPlaneSocket = 0;
}

X2IfaceInfo&
X2IfaceInfo::operator=(const X2IfaceInfo& value)
{
    NS_LOG_FUNCTION(this);
    m_remoteIpAddr = value.m_remoteIpAddr;
    m_localCtrlPlaneSocket = value.m_localCtrlPlaneSocket;
    m_localUserPlaneSocket = value.m_localUserPlaneSocket;
    return *this;
}

///////////////////////////////////////////

X2CellInfo::X2CellInfo(uint16_t localCellId, uint16_t remoteCellId)
{
    m_localCellId = localCellId;
    m_remoteCellId = remoteCellId;
}

X2CellInfo::~X2CellInfo(void)
{
    m_localCellId = 0;
    m_remoteCellId = 0;
}

X2CellInfo&
X2CellInfo::operator=(const X2CellInfo& value)
{
    NS_LOG_FUNCTION(this);
    m_localCellId = value.m_localCellId;
    m_remoteCellId = value.m_remoteCellId;
    return *this;
}

///////////////////////////////////////////

NS_OBJECT_ENSURE_REGISTERED(EpcX2);

EpcX2::EpcX2()
    : m_x2cUdpPort(4444),
      m_x2uUdpPort(2152)
{
    NS_LOG_FUNCTION(this);

    m_x2SapProvider = new EpcX2SpecificEpcX2SapProvider<EpcX2>(this);
    m_x2PdcpProvider = new EpcX2PdcpSpecificProvider<EpcX2>(this);
    m_x2RlcProvider = new EpcX2RlcSpecificProvider<EpcX2>(this);
}

EpcX2::~EpcX2()
{
    NS_LOG_FUNCTION(this);
}

void
EpcX2::DoDispose(void)
{
    NS_LOG_FUNCTION(this);

    m_x2InterfaceSockets.clear();
    m_x2InterfaceCellIds.clear();
    m_x2RlcUserMap.clear();
    m_x2PdcpUserMap.clear();
    delete m_x2SapProvider;
    delete m_x2RlcProvider;
    delete m_x2PdcpProvider;
}

TypeId
EpcX2::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::EpcX2")
                            .SetParent<Object>()
                            .SetGroupName("Lte")
                            .AddTraceSource("RxPDU",
                                            "PDU received.",
                                            MakeTraceSourceAccessor(&EpcX2::m_rxPdu),
                                            "ns3::EpcX2::ReceiveTracedCallback");
    return tid;
}

void
EpcX2::SetEpcX2SapUser(EpcX2SapUser* s)
{
    NS_LOG_FUNCTION(this << s);
    m_x2SapUser = s;
}

EpcX2SapProvider*
EpcX2::GetEpcX2SapProvider()
{
    NS_LOG_FUNCTION(this);
    return m_x2SapProvider;
}

// Get and Set interfaces with PDCP and RLC
EpcX2PdcpProvider*
EpcX2::GetEpcX2PdcpProvider()
{
    NS_LOG_FUNCTION(this);
    return m_x2PdcpProvider;
}

EpcX2RlcProvider*
EpcX2::GetEpcX2RlcProvider()
{
    return m_x2RlcProvider;
}

void
EpcX2::SetMcEpcX2RlcUser(uint32_t teid, EpcX2RlcUser* rlcUser)
{
    // TODO it may change (for the same teid) on handover between secondary cells, as in
    // LteEnbRrc::RecvRlcSetupRequest
    // NS_ASSERT_MSG(m_x2RlcUserMap.find(teid) == m_x2RlcUserMap.end(), "Teid " << teid
    //  << " is already setup\n");
    NS_LOG_INFO("Add EpcX2RlcUser for teid " << teid);
    m_x2RlcUserMap[teid] = rlcUser;
}

void
EpcX2::SetMcEpcX2PdcpUser(uint32_t teid, EpcX2PdcpUser* pdcpUser)
{
    // TODO it may change (for the same teid) on handover between secondary cells, as in
    // LteEnbRrc::RecvRlcSetupRequest
    // NS_ASSERT_MSG(m_x2PdcpUserMap.find(teid) == m_x2PdcpUserMap.end(), "Teid " << teid
    //  << " is already setup\n");
    NS_LOG_INFO("Add EpcX2PdcpUser for teid " << teid);
    m_x2PdcpUserMap[teid] = pdcpUser;
}

// Add X2 endpoint
void
EpcX2::AddX2Interface(uint16_t localCellId,
                      Ipv4Address localX2Address,
                      uint16_t remoteCellId,
                      Ipv4Address remoteX2Address)
{
    NS_LOG_FUNCTION(this << localCellId << localX2Address << remoteCellId << remoteX2Address);

    int retval;

    // Get local eNB where this X2 entity belongs to
    Ptr<Node> localEnb = GetObject<Node>();

    // Create X2-C socket for the local eNB
    Ptr<Socket> localX2cSocket =
        Socket::CreateSocket(localEnb, TypeId::LookupByName("ns3::UdpSocketFactory"));
    retval = localX2cSocket->Bind(InetSocketAddress(localX2Address, m_x2cUdpPort));
    NS_ASSERT(retval == 0);
    localX2cSocket->SetRecvCallback(MakeCallback(&EpcX2::RecvFromX2cSocket, this));

    // Create X2-U socket for the local eNB
    Ptr<Socket> localX2uSocket =
        Socket::CreateSocket(localEnb, TypeId::LookupByName("ns3::UdpSocketFactory"));
    retval = localX2uSocket->Bind(InetSocketAddress(localX2Address, m_x2uUdpPort));
    NS_ASSERT(retval == 0);
    localX2uSocket->SetRecvCallback(MakeCallback(&EpcX2::RecvFromX2uSocket, this));

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(remoteCellId) == m_x2InterfaceSockets.end(),
                  "Mapping for remoteCellId = " << remoteCellId << " is already known");
    m_x2InterfaceSockets[remoteCellId] =
        Create<X2IfaceInfo>(remoteX2Address, localX2cSocket, localX2uSocket);

    NS_ASSERT_MSG(m_x2InterfaceCellIds.find(localX2cSocket) == m_x2InterfaceCellIds.end(),
                  "Mapping for control plane localSocket = " << localX2cSocket
                                                             << " is already known");
    m_x2InterfaceCellIds[localX2cSocket] = Create<X2CellInfo>(localCellId, remoteCellId);

    NS_ASSERT_MSG(m_x2InterfaceCellIds.find(localX2uSocket) == m_x2InterfaceCellIds.end(),
                  "Mapping for data plane localSocket = " << localX2uSocket << " is already known");
    m_x2InterfaceCellIds[localX2uSocket] = Create<X2CellInfo>(localCellId, remoteCellId);
}

void
EpcX2::DoAddTeidToBeForwarded(uint32_t gtpTeid, uint16_t targetCellId)
{
    NS_LOG_FUNCTION(this << " add an entry to the map of teids to be forwarded: teid " << gtpTeid
                         << " targetCellId " << targetCellId);
    NS_ASSERT_MSG(m_teidToBeForwardedMap.find(gtpTeid) == m_teidToBeForwardedMap.end(),
                  "TEID already in the map");
    m_teidToBeForwardedMap.insert(std::pair<uint32_t, uint16_t>(gtpTeid, targetCellId));
}

void
EpcX2::DoRemoveTeidToBeForwarded(uint32_t gtpTeid)
{
    NS_LOG_FUNCTION(this << " remove and entry from the map of teids to be forwarded: teid "
                         << gtpTeid);
    NS_ASSERT_MSG(m_teidToBeForwardedMap.find(gtpTeid) != m_teidToBeForwardedMap.end(),
                  "TEID not in the map");
    m_teidToBeForwardedMap.erase(m_teidToBeForwardedMap.find(gtpTeid));
}

void
EpcX2::RecvFromX2cSocket(Ptr<Socket> socket)
{
    NS_LOG_FUNCTION(this << socket);

    NS_LOG_LOGIC("Recv X2 message: from Socket");
    Ptr<Packet> packet = socket->Recv();
    NS_LOG_LOGIC("packetLen = " << packet->GetSize());

    NS_ASSERT_MSG(m_x2InterfaceCellIds.find(socket) != m_x2InterfaceCellIds.end(),
                  "Missing infos of local and remote CellId");
    Ptr<X2CellInfo> cellsInfo = m_x2InterfaceCellIds[socket];

    EpcX2Tag epcX2Tag;
    Time delay;
    if (packet->PeekPacketTag(epcX2Tag))
    {
        delay = Simulator::Now() - epcX2Tag.GetSenderTimestamp();
        packet->RemovePacketTag(epcX2Tag);
    }

    m_rxPdu(cellsInfo->m_remoteCellId,
            cellsInfo->m_localCellId,
            packet->GetSize(),
            delay.GetNanoSeconds(),
            0);

    EpcX2Header x2Header;
    packet->RemoveHeader(x2Header);

    NS_LOG_LOGIC("X2 header: " << x2Header);

    uint8_t messageType = x2Header.GetMessageType();
    uint8_t procedureCode = x2Header.GetProcedureCode();

    if (procedureCode == EpcX2Header::HandoverPreparation)
    {
        if (messageType == EpcX2Header::InitiatingMessage)
        {
            NS_LOG_LOGIC("Recv X2 message: HANDOVER REQUEST");

            EpcX2HandoverRequestHeader x2HoReqHeader;
            packet->RemoveHeader(x2HoReqHeader);

            NS_LOG_INFO("X2 HandoverRequest header: " << x2HoReqHeader);

            EpcX2SapUser::HandoverRequestParams params;
            params.oldEnbUeX2apId = x2HoReqHeader.GetOldEnbUeX2apId();
            params.cause = x2HoReqHeader.GetCause();
            params.sourceCellId = cellsInfo->m_remoteCellId;
            params.targetCellId = x2HoReqHeader.GetTargetCellId();
            params.mmeUeS1apId = x2HoReqHeader.GetMmeUeS1apId();
            params.ueAggregateMaxBitRateDownlink = x2HoReqHeader.GetUeAggregateMaxBitRateDownlink();
            params.ueAggregateMaxBitRateUplink = x2HoReqHeader.GetUeAggregateMaxBitRateUplink();
            params.bearers = x2HoReqHeader.GetBearers();
            // RlcRequests for secondary cell HO
            params.rlcRequests = x2HoReqHeader.GetRlcSetupRequests();
            params.rrcContext = packet;
            params.isMc = x2HoReqHeader.GetIsMc();

            NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
            NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
            NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
            NS_LOG_LOGIC("mmeUeS1apId = " << params.mmeUeS1apId);
            NS_LOG_LOGIC("cellsInfo->m_localCellId = " << cellsInfo->m_localCellId);
            NS_ASSERT_MSG(params.targetCellId == cellsInfo->m_localCellId,
                          "TargetCellId mismatches with localCellId");

            m_x2SapUser->RecvHandoverRequest(params);
        }
        else if (messageType == EpcX2Header::SuccessfulOutcome)
        {
            NS_LOG_LOGIC("Recv X2 message: HANDOVER REQUEST ACK");

            EpcX2HandoverRequestAckHeader x2HoReqAckHeader;
            packet->RemoveHeader(x2HoReqAckHeader);

            NS_LOG_INFO("X2 HandoverRequestAck header: " << x2HoReqAckHeader);

            EpcX2SapUser::HandoverRequestAckParams params;
            params.oldEnbUeX2apId = x2HoReqAckHeader.GetOldEnbUeX2apId();
            params.newEnbUeX2apId = x2HoReqAckHeader.GetNewEnbUeX2apId();
            params.sourceCellId = cellsInfo->m_localCellId;
            params.targetCellId = cellsInfo->m_remoteCellId;
            params.admittedBearers = x2HoReqAckHeader.GetAdmittedBearers();
            params.notAdmittedBearers = x2HoReqAckHeader.GetNotAdmittedBearers();
            params.rrcContext = packet;

            NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
            NS_LOG_LOGIC("newEnbUeX2apId = " << params.newEnbUeX2apId);
            NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
            NS_LOG_LOGIC("targetCellId = " << params.targetCellId);

            m_x2SapUser->RecvHandoverRequestAck(params);
        }
        else // messageType == EpcX2Header::UnsuccessfulOutcome
        {
            NS_LOG_LOGIC("Recv X2 message: HANDOVER PREPARATION FAILURE");

            EpcX2HandoverPreparationFailureHeader x2HoPrepFailHeader;
            packet->RemoveHeader(x2HoPrepFailHeader);

            NS_LOG_INFO("X2 HandoverPreparationFailure header: " << x2HoPrepFailHeader);

            EpcX2SapUser::HandoverPreparationFailureParams params;
            params.oldEnbUeX2apId = x2HoPrepFailHeader.GetOldEnbUeX2apId();
            params.sourceCellId = cellsInfo->m_localCellId;
            params.targetCellId = cellsInfo->m_remoteCellId;
            params.cause = x2HoPrepFailHeader.GetCause();
            params.criticalityDiagnostics = x2HoPrepFailHeader.GetCriticalityDiagnostics();

            NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
            NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
            NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
            NS_LOG_LOGIC("cause = " << params.cause);
            NS_LOG_LOGIC("criticalityDiagnostics = " << params.criticalityDiagnostics);

            m_x2SapUser->RecvHandoverPreparationFailure(params);
        }
    }
    else if (procedureCode == EpcX2Header::LoadIndication)
    {
        if (messageType == EpcX2Header::InitiatingMessage)
        {
            NS_LOG_LOGIC("Recv X2 message: LOAD INFORMATION");

            EpcX2LoadInformationHeader x2LoadInfoHeader;
            packet->RemoveHeader(x2LoadInfoHeader);

            NS_LOG_INFO("X2 LoadInformation header: " << x2LoadInfoHeader);

            EpcX2SapUser::LoadInformationParams params;
            params.cellInformationList = x2LoadInfoHeader.GetCellInformationList();

            NS_LOG_LOGIC("cellInformationList size = " << params.cellInformationList.size());

            m_x2SapUser->RecvLoadInformation(params);
        }
    }
    else if (procedureCode == EpcX2Header::SnStatusTransfer)
    {
        if (messageType == EpcX2Header::InitiatingMessage)
        {
            NS_LOG_LOGIC("Recv X2 message: SN STATUS TRANSFER");

            EpcX2SnStatusTransferHeader x2SnStatusXferHeader;
            packet->RemoveHeader(x2SnStatusXferHeader);

            NS_LOG_INFO("X2 SnStatusTransfer header: " << x2SnStatusXferHeader);

            EpcX2SapUser::SnStatusTransferParams params;
            params.oldEnbUeX2apId = x2SnStatusXferHeader.GetOldEnbUeX2apId();
            params.newEnbUeX2apId = x2SnStatusXferHeader.GetNewEnbUeX2apId();
            params.sourceCellId = cellsInfo->m_remoteCellId;
            params.targetCellId = cellsInfo->m_localCellId;
            params.erabsSubjectToStatusTransferList =
                x2SnStatusXferHeader.GetErabsSubjectToStatusTransferList();

            NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
            NS_LOG_LOGIC("newEnbUeX2apId = " << params.newEnbUeX2apId);
            NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
            NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
            NS_LOG_LOGIC("erabsList size = " << params.erabsSubjectToStatusTransferList.size());

            m_x2SapUser->RecvSnStatusTransfer(params);
        }
    }
    else if (procedureCode == EpcX2Header::UeContextRelease)
    {
        if (messageType == EpcX2Header::InitiatingMessage)
        {
            NS_LOG_LOGIC("Recv X2 message: UE CONTEXT RELEASE");

            EpcX2UeContextReleaseHeader x2UeCtxReleaseHeader;
            packet->RemoveHeader(x2UeCtxReleaseHeader);

            NS_LOG_INFO("X2 UeContextRelease header: " << x2UeCtxReleaseHeader);

            EpcX2SapUser::UeContextReleaseParams params;
            params.oldEnbUeX2apId = x2UeCtxReleaseHeader.GetOldEnbUeX2apId();
            params.newEnbUeX2apId = x2UeCtxReleaseHeader.GetNewEnbUeX2apId();
            params.sourceCellId = cellsInfo->m_remoteCellId;

            NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
            NS_LOG_LOGIC("newEnbUeX2apId = " << params.newEnbUeX2apId);

            m_x2SapUser->RecvUeContextRelease(params);
        }
    }
    else if (procedureCode == EpcX2Header::ResourceStatusReporting)
    {
        if (messageType == EpcX2Header::InitiatingMessage)
        {
            NS_LOG_LOGIC("Recv X2 message: RESOURCE STATUS UPDATE");

            EpcX2ResourceStatusUpdateHeader x2ResStatUpdHeader;
            packet->RemoveHeader(x2ResStatUpdHeader);

            NS_LOG_INFO("X2 ResourceStatusUpdate header: " << x2ResStatUpdHeader);

            EpcX2SapUser::ResourceStatusUpdateParams params;
            params.targetCellId = 0;
            params.enb1MeasurementId = x2ResStatUpdHeader.GetEnb1MeasurementId();
            params.enb2MeasurementId = x2ResStatUpdHeader.GetEnb2MeasurementId();
            params.cellMeasurementResultList = x2ResStatUpdHeader.GetCellMeasurementResultList();

            NS_LOG_LOGIC("enb1MeasurementId = " << params.enb1MeasurementId);
            NS_LOG_LOGIC("enb2MeasurementId = " << params.enb2MeasurementId);
            NS_LOG_LOGIC(
                "cellMeasurementResultList size = " << params.cellMeasurementResultList.size());

            m_x2SapUser->RecvResourceStatusUpdate(params);
        }
    }
    else if (procedureCode == EpcX2Header::RlcSetupRequest)
    {
        NS_LOG_LOGIC("Recv X2 message: RLC SETUP REQUEST");

        EpcX2RlcSetupRequestHeader x2RlcHeader;
        packet->RemoveHeader(x2RlcHeader);

        NS_LOG_INFO("X2 RlcSetupRequest header: " << x2RlcHeader);

        EpcX2SapUser::RlcSetupRequest params;
        params.targetCellId = x2RlcHeader.GetTargetCellId();
        params.sourceCellId = x2RlcHeader.GetSourceCellId();
        params.mmWaveRnti = x2RlcHeader.GetMmWaveRnti();
        params.gtpTeid = x2RlcHeader.GetGtpTeid();
        params.lteRnti = x2RlcHeader.GetLteRnti();
        params.drbid = x2RlcHeader.GetDrbid();
        params.lcinfo = x2RlcHeader.GetLcInfo();
        params.rlcConfig = x2RlcHeader.GetRlcConfig();
        params.logicalChannelConfig = x2RlcHeader.GetLogicalChannelConfig();

        NS_LOG_LOGIC("GtpTeid = " << params.gtpTeid);
        NS_LOG_LOGIC("MmWaveRnti = " << params.mmWaveRnti);
        NS_LOG_LOGIC("SourceCellID = " << params.sourceCellId);
        NS_LOG_LOGIC("TargetCellID = " << params.targetCellId);
        NS_LOG_LOGIC("Drbid = " << params.drbid);

        m_x2SapUser->RecvRlcSetupRequest(params);
    }
    else if (procedureCode == EpcX2Header::RlcSetupCompleted)
    {
        NS_LOG_LOGIC("Recv X2 message: RLC SETUP COMPLETED");

        EpcX2RlcSetupCompletedHeader x2RlcHeader;
        packet->RemoveHeader(x2RlcHeader);

        NS_LOG_INFO("X2 RlcSetupCompleted header: " << x2RlcHeader);

        EpcX2SapUser::UeDataParams params;
        params.targetCellId = x2RlcHeader.GetTargetCellId();
        params.sourceCellId = x2RlcHeader.GetSourceCellId();
        params.gtpTeid = x2RlcHeader.GetGtpTeid();

        NS_LOG_LOGIC("GtpTeid = " << params.gtpTeid);
        NS_LOG_LOGIC("SourceCellID = " << params.sourceCellId);
        NS_LOG_LOGIC("TargetCellID = " << params.targetCellId);

        m_x2SapUser->RecvRlcSetupCompleted(params);
    }
    else if (procedureCode == EpcX2Header::UpdateUeSinr)
    {
        NS_LOG_LOGIC("Recv X2 message: UPDATE UE SINR");

        EpcX2UeImsiSinrUpdateHeader x2ueSinrUpdateHeader;
        packet->RemoveHeader(x2ueSinrUpdateHeader);

        NS_LOG_INFO("X2 SinrUpdateHeader header: " << x2ueSinrUpdateHeader);

        EpcX2SapUser::UeImsiSinrParams params;
        params.ueImsiSinrMap = x2ueSinrUpdateHeader.GetUeImsiSinrMap();
        params.sourceCellId = x2ueSinrUpdateHeader.GetSourceCellId();

        m_x2SapUser->RecvUeSinrUpdate(params);
    }
    else if (procedureCode == EpcX2Header::RequestMcHandover)
    {
        NS_LOG_LOGIC("Recv X2 message: REQUEST MC HANDOVER");

        EpcX2McHandoverHeader x2mcHeader;
        packet->RemoveHeader(x2mcHeader);

        NS_LOG_INFO("X2 RequestMcHandover header: " << x2mcHeader);

        EpcX2SapUser::SecondaryHandoverParams params;
        params.targetCellId = x2mcHeader.GetTargetCellId();
        params.imsi = x2mcHeader.GetImsi();
        params.oldCellId = x2mcHeader.GetOldCellId();

        m_x2SapUser->RecvMcHandoverRequest(params);
    }
    else if (procedureCode == EpcX2Header::NotifyMmWaveLteHandover)
    {
        NS_LOG_LOGIC("Recv X2 message: NOTIFY MMWAVE HANDOVER TO LTE");

        EpcX2McHandoverHeader x2mcHeader;
        packet->RemoveHeader(x2mcHeader);

        NS_LOG_INFO("X2 McHandover header: " << x2mcHeader);

        EpcX2SapUser::SecondaryHandoverParams params;
        params.targetCellId =
            x2mcHeader.GetTargetCellId(); // the new MmWave cell to which the UE is connected
        params.imsi = x2mcHeader.GetImsi();
        params.oldCellId = x2mcHeader.GetOldCellId(); // actually, the LTE cell ID

        m_x2SapUser->RecvLteMmWaveHandoverCompleted(params);
    }
    else if (procedureCode == EpcX2Header::SwitchConnection)
    {
        NS_LOG_LOGIC("Recv X2 message: SWITCH CONNECTION");

        EpcX2ConnectionSwitchHeader x2mcHeader;
        packet->RemoveHeader(x2mcHeader);

        NS_LOG_INFO("X2 SwitchConnection header: " << x2mcHeader);

        EpcX2SapUser::SwitchConnectionParams params;
        params.mmWaveRnti = x2mcHeader.GetMmWaveRnti();
        params.useMmWaveConnection = x2mcHeader.GetUseMmWaveConnection();
        params.drbid = x2mcHeader.GetDrbid();

        m_x2SapUser->RecvConnectionSwitchToMmWave(params);
    }
    else if (procedureCode == EpcX2Header::SecondaryCellHandoverCompleted)
    {
        NS_LOG_LOGIC("Recv X2 message: SECONDARY CELL HANDOVER COMPLETED");

        EpcX2SecondaryCellHandoverCompletedHeader x2hoHeader;
        packet->RemoveHeader(x2hoHeader);

        EpcX2SapUser::SecondaryHandoverCompletedParams params;
        params.mmWaveRnti = x2hoHeader.GetMmWaveRnti();
        params.imsi = x2hoHeader.GetImsi();
        params.oldEnbUeX2apId = x2hoHeader.GetOldEnbUeX2apId();
        params.cellId = cellsInfo->m_remoteCellId;

        m_x2SapUser->RecvSecondaryCellHandoverCompleted(params);
    }
    else
    {
        NS_ASSERT_MSG(false, "ProcedureCode NOT SUPPORTED!!!");
    }
}

void
EpcX2::RecvFromX2uSocket(Ptr<Socket> socket)
{
    NS_LOG_FUNCTION(this << socket);

    NS_LOG_LOGIC("Recv UE DATA through X2-U interface from Socket");
    Ptr<Packet> packet = socket->Recv();
    NS_LOG_LOGIC("packetLen = " << packet->GetSize());

    NS_ASSERT_MSG(m_x2InterfaceCellIds.find(socket) != m_x2InterfaceCellIds.end(),
                  "Missing infos of local and remote CellId");
    Ptr<X2CellInfo> cellsInfo = m_x2InterfaceCellIds[socket];

    NS_LOG_INFO("localCellId = " << cellsInfo->m_localCellId);
    NS_LOG_INFO("remoteCellId = " << cellsInfo->m_remoteCellId);

    EpcX2Tag epcX2Tag;
    Time delay;
    if (packet->PeekPacketTag(epcX2Tag))
    {
        delay = Simulator::Now() - epcX2Tag.GetSenderTimestamp();
        packet->RemovePacketTag(epcX2Tag);
    }
    m_rxPdu(cellsInfo->m_remoteCellId,
            cellsInfo->m_localCellId,
            packet->GetSize(),
            delay.GetNanoSeconds(),
            1);

    GtpuHeader gtpu;
    packet->RemoveHeader(gtpu);
    // SocketAddressTag satag;
    // packet->RemovePacketTag(satag);

    NS_LOG_LOGIC("GTP-U header: " << gtpu);

    EpcX2SapUser::UeDataParams params;
    params.sourceCellId = cellsInfo->m_remoteCellId;
    params.targetCellId = cellsInfo->m_localCellId;
    params.gtpTeid = gtpu.GetTeid();
    params.ueData = packet;

    NS_LOG_LOGIC("Received packet on X2 u, size "
                 << packet->GetSize() << " source " << params.sourceCellId << " target "
                 << params.targetCellId << " type " << gtpu.GetMessageType());

    if (m_teidToBeForwardedMap.find(params.gtpTeid) == m_teidToBeForwardedMap.end())
    {
        if (gtpu.GetMessageType() == EpcX2Header::McForwardDownlinkData)
        {
            // add PdcpTag
            PdcpTag pdcpTag(Simulator::Now());
            params.ueData->AddByteTag(pdcpTag);
            // call rlc interface
            EpcX2RlcUser* user = m_x2RlcUserMap.find(params.gtpTeid)->second;
            if (user != 0)
            {
                user->SendMcPdcpSdu(params);
            }
            else
            {
                NS_LOG_INFO("Not implemented: Forward to the other cell or to LTE");
            }
        }
        else if (gtpu.GetMessageType() == EpcX2Header::McForwardUplinkData)
        {
            // call pdcp interface
            NS_LOG_INFO("Call PDCP interface");
            m_x2PdcpUserMap[params.gtpTeid]->ReceiveMcPdcpPdu(params);
        }
        else
        {
            m_x2SapUser->RecvUeData(params);
        }
    }
    else // the packet was received during a secondary cell HO, forward to the target cell
    {
        params.sourceCellId = cellsInfo->m_remoteCellId;
        params.targetCellId = m_teidToBeForwardedMap.find(params.gtpTeid)->second;
        NS_LOG_LOGIC("Forward from " << cellsInfo->m_localCellId << " to " << params.targetCellId);
        DoSendMcPdcpPdu(params);
    }
}

//
// Implementation of the X2 SAP Provider
//
void
EpcX2::DoSendHandoverRequest(EpcX2SapProvider::HandoverRequestParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("mmeUeS1apId  = " << params.mmeUeS1apId);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for targetCellId = " << params.targetCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.targetCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localCtrlPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    NS_LOG_INFO("Send X2 message: HANDOVER REQUEST");

    // Build the X2 message
    EpcX2HandoverRequestHeader x2HoReqHeader;
    x2HoReqHeader.SetOldEnbUeX2apId(params.oldEnbUeX2apId);
    x2HoReqHeader.SetCause(params.cause);
    x2HoReqHeader.SetTargetCellId(params.targetCellId);
    x2HoReqHeader.SetMmeUeS1apId(params.mmeUeS1apId);
    x2HoReqHeader.SetUeAggregateMaxBitRateDownlink(params.ueAggregateMaxBitRateDownlink);
    x2HoReqHeader.SetUeAggregateMaxBitRateUplink(params.ueAggregateMaxBitRateUplink);
    x2HoReqHeader.SetBearers(params.bearers);
    // For secondary cell handover
    x2HoReqHeader.SetRlcSetupRequests(params.rlcRequests);
    x2HoReqHeader.SetIsMc(params.isMc);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::HandoverPreparation);
    x2Header.SetLengthOfIes(x2HoReqHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2HoReqHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 HandoverRequest header: " << x2HoReqHeader);

    // Build the X2 packet
    Ptr<Packet> packet = (params.rrcContext) ? (params.rrcContext) : (Create<Packet>());
    packet->AddHeader(x2HoReqHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendRlcSetupRequest(EpcX2SapProvider::RlcSetupRequest params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("teid  = " << params.gtpTeid);
    NS_LOG_LOGIC("rnti = " << params.mmWaveRnti);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for targetCellId = " << params.targetCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.targetCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localCtrlPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    NS_LOG_INFO("Send X2 message: RLC SETUP REQUEST");

    // Build the X2 message
    EpcX2RlcSetupRequestHeader x2RlcHeader;
    x2RlcHeader.SetSourceCellId(params.sourceCellId);
    x2RlcHeader.SetTargetCellId(params.targetCellId);
    x2RlcHeader.SetGtpTeid(params.gtpTeid);
    x2RlcHeader.SetMmWaveRnti(params.mmWaveRnti);
    x2RlcHeader.SetLteRnti(params.lteRnti);
    x2RlcHeader.SetDrbid(params.drbid);
    x2RlcHeader.SetLcInfo(params.lcinfo);
    x2RlcHeader.SetRlcConfig(params.rlcConfig);
    x2RlcHeader.SetLogicalChannelConfig(params.logicalChannelConfig);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::RlcSetupRequest);
    x2Header.SetLengthOfIes(x2RlcHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2RlcHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 RlcSetupRequest header: " << x2RlcHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2RlcHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendRlcSetupCompleted(EpcX2Sap::UeDataParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("teid  = " << params.gtpTeid);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for targetCellId = " << params.targetCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.targetCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localCtrlPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    NS_LOG_INFO("Send X2 message: RLC SETUP COMPLETED");

    // Build the X2 message
    EpcX2RlcSetupCompletedHeader x2RlcHeader;
    x2RlcHeader.SetSourceCellId(params.sourceCellId);
    x2RlcHeader.SetTargetCellId(params.targetCellId);
    x2RlcHeader.SetGtpTeid(params.gtpTeid);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::RlcSetupCompleted);
    x2Header.SetLengthOfIes(x2RlcHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2RlcHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 RlcSetupCompleted header: " << x2RlcHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2RlcHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendHandoverRequestAck(EpcX2SapProvider::HandoverRequestAckParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("newEnbUeX2apId = " << params.newEnbUeX2apId);
    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.sourceCellId) != m_x2InterfaceSockets.end(),
                  "Socket infos not defined for sourceCellId = " << params.sourceCellId);

    Ptr<Socket> localSocket = m_x2InterfaceSockets[params.sourceCellId]->m_localCtrlPlaneSocket;
    Ipv4Address remoteIpAddr = m_x2InterfaceSockets[params.sourceCellId]->m_remoteIpAddr;

    NS_LOG_LOGIC("localSocket = " << localSocket);
    NS_LOG_LOGIC("remoteIpAddr = " << remoteIpAddr);

    NS_LOG_INFO("Send X2 message: HANDOVER REQUEST ACK");

    // Build the X2 message
    EpcX2HandoverRequestAckHeader x2HoAckHeader;
    x2HoAckHeader.SetOldEnbUeX2apId(params.oldEnbUeX2apId);
    x2HoAckHeader.SetNewEnbUeX2apId(params.newEnbUeX2apId);
    x2HoAckHeader.SetAdmittedBearers(params.admittedBearers);
    x2HoAckHeader.SetNotAdmittedBearers(params.notAdmittedBearers);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::SuccessfulOutcome);
    x2Header.SetProcedureCode(EpcX2Header::HandoverPreparation);
    x2Header.SetLengthOfIes(x2HoAckHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2HoAckHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 HandoverAck header: " << x2HoAckHeader);
    NS_LOG_INFO("RRC context: " << params.rrcContext);

    // Build the X2 packet
    Ptr<Packet> packet = (params.rrcContext) ? (params.rrcContext) : (Create<Packet>());
    packet->AddHeader(x2HoAckHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    localSocket->SendTo(packet, 0, InetSocketAddress(remoteIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendHandoverPreparationFailure(EpcX2SapProvider::HandoverPreparationFailureParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("cause = " << params.cause);
    NS_LOG_LOGIC("criticalityDiagnostics = " << params.criticalityDiagnostics);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.sourceCellId) != m_x2InterfaceSockets.end(),
                  "Socket infos not defined for sourceCellId = " << params.sourceCellId);

    Ptr<Socket> localSocket = m_x2InterfaceSockets[params.sourceCellId]->m_localCtrlPlaneSocket;
    Ipv4Address remoteIpAddr = m_x2InterfaceSockets[params.sourceCellId]->m_remoteIpAddr;

    NS_LOG_LOGIC("localSocket = " << localSocket);
    NS_LOG_LOGIC("remoteIpAddr = " << remoteIpAddr);

    NS_LOG_INFO("Send X2 message: HANDOVER PREPARATION FAILURE");

    // Build the X2 message
    EpcX2HandoverPreparationFailureHeader x2HoPrepFailHeader;
    x2HoPrepFailHeader.SetOldEnbUeX2apId(params.oldEnbUeX2apId);
    x2HoPrepFailHeader.SetCause(params.cause);
    x2HoPrepFailHeader.SetCriticalityDiagnostics(params.criticalityDiagnostics);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::UnsuccessfulOutcome);
    x2Header.SetProcedureCode(EpcX2Header::HandoverPreparation);
    x2Header.SetLengthOfIes(x2HoPrepFailHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2HoPrepFailHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 HandoverPrepFail header: " << x2HoPrepFailHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2HoPrepFailHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    localSocket->SendTo(packet, 0, InetSocketAddress(remoteIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoNotifyCoordinatorHandoverFailed(EpcX2SapProvider::HandoverFailedParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("coordinator cellId " << params.coordinatorId);
    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("imsi = " << params.imsi);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.coordinatorId) != m_x2InterfaceSockets.end(),
                  "Socket infos not defined for coordinatorId = " << params.coordinatorId);

    Ptr<Socket> localSocket = m_x2InterfaceSockets[params.coordinatorId]->m_localCtrlPlaneSocket;
    Ipv4Address remoteIpAddr = m_x2InterfaceSockets[params.coordinatorId]->m_remoteIpAddr;

    NS_LOG_LOGIC("localSocket = " << localSocket);
    NS_LOG_LOGIC("remoteIpAddr = " << remoteIpAddr);

    NS_LOG_INFO("Send X2 message: NOTIFY HANDOVER FAILED");

    // Build the X2 message
    EpcX2NotifyCoordinatorHandoverFailedHeader x2failHeader;
    x2failHeader.SetSourceCellId(params.sourceCellId);
    x2failHeader.SetTargetCellId(params.targetCellId);
    x2failHeader.SetImsi(params.imsi);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::UnsuccessfulOutcome);
    x2Header.SetProcedureCode(EpcX2Header::NotifyCoordinatorHandoverFailed);
    x2Header.SetLengthOfIes(x2failHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2failHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 HandoverPrepFail header: " << x2failHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2failHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    localSocket->SendTo(packet, 0, InetSocketAddress(remoteIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendSnStatusTransfer(EpcX2SapProvider::SnStatusTransferParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("newEnbUeX2apId = " << params.newEnbUeX2apId);
    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("erabsList size = " << params.erabsSubjectToStatusTransferList.size());

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Socket infos not defined for targetCellId = " << params.targetCellId);

    Ptr<Socket> localSocket = m_x2InterfaceSockets[params.targetCellId]->m_localCtrlPlaneSocket;
    Ipv4Address remoteIpAddr = m_x2InterfaceSockets[params.targetCellId]->m_remoteIpAddr;

    NS_LOG_LOGIC("localSocket = " << localSocket);
    NS_LOG_LOGIC("remoteIpAddr = " << remoteIpAddr);

    NS_LOG_INFO("Send X2 message: SN STATUS TRANSFER");

    // Build the X2 message
    EpcX2SnStatusTransferHeader x2SnStatusXferHeader;
    x2SnStatusXferHeader.SetOldEnbUeX2apId(params.oldEnbUeX2apId);
    x2SnStatusXferHeader.SetNewEnbUeX2apId(params.newEnbUeX2apId);
    x2SnStatusXferHeader.SetErabsSubjectToStatusTransferList(
        params.erabsSubjectToStatusTransferList);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::SnStatusTransfer);
    x2Header.SetLengthOfIes(x2SnStatusXferHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2SnStatusXferHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 SnStatusTransfer header: " << x2SnStatusXferHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2SnStatusXferHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    localSocket->SendTo(packet, 0, InetSocketAddress(remoteIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendUeContextRelease(EpcX2SapProvider::UeContextReleaseParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("newEnbUeX2apId = " << params.newEnbUeX2apId);
    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.sourceCellId) != m_x2InterfaceSockets.end(),
                  "Socket infos not defined for sourceCellId = " << params.sourceCellId);

    Ptr<Socket> localSocket = m_x2InterfaceSockets[params.sourceCellId]->m_localCtrlPlaneSocket;
    Ipv4Address remoteIpAddr = m_x2InterfaceSockets[params.sourceCellId]->m_remoteIpAddr;

    NS_LOG_LOGIC("localSocket = " << localSocket);
    NS_LOG_LOGIC("remoteIpAddr = " << remoteIpAddr);

    NS_LOG_INFO("Send X2 message: UE CONTEXT RELEASE");

    // Build the X2 message
    EpcX2UeContextReleaseHeader x2UeCtxReleaseHeader;
    x2UeCtxReleaseHeader.SetOldEnbUeX2apId(params.oldEnbUeX2apId);
    x2UeCtxReleaseHeader.SetNewEnbUeX2apId(params.newEnbUeX2apId);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::UeContextRelease);
    x2Header.SetLengthOfIes(x2UeCtxReleaseHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2UeCtxReleaseHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 UeContextRelease header: " << x2UeCtxReleaseHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2UeCtxReleaseHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    localSocket->SendTo(packet, 0, InetSocketAddress(remoteIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendLoadInformation(EpcX2SapProvider::LoadInformationParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("cellInformationList size = " << params.cellInformationList.size());

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for targetCellId = " << params.targetCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.targetCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localCtrlPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    NS_LOG_INFO("Send X2 message: LOAD INFORMATION");

    // Build the X2 message
    EpcX2LoadInformationHeader x2LoadInfoHeader;
    x2LoadInfoHeader.SetCellInformationList(params.cellInformationList);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::LoadIndication);
    x2Header.SetLengthOfIes(x2LoadInfoHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2LoadInfoHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 LoadInformation header: " << x2LoadInfoHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2LoadInfoHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendResourceStatusUpdate(EpcX2SapProvider::ResourceStatusUpdateParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("enb1MeasurementId = " << params.enb1MeasurementId);
    NS_LOG_LOGIC("enb2MeasurementId = " << params.enb2MeasurementId);
    NS_LOG_LOGIC("cellMeasurementResultList size = " << params.cellMeasurementResultList.size());

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for targetCellId = " << params.targetCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.targetCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localCtrlPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    NS_LOG_INFO("Send X2 message: RESOURCE STATUS UPDATE");

    // Build the X2 message
    EpcX2ResourceStatusUpdateHeader x2ResourceStatUpdHeader;
    x2ResourceStatUpdHeader.SetEnb1MeasurementId(params.enb1MeasurementId);
    x2ResourceStatUpdHeader.SetEnb2MeasurementId(params.enb2MeasurementId);
    x2ResourceStatUpdHeader.SetCellMeasurementResultList(params.cellMeasurementResultList);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::ResourceStatusReporting);
    x2Header.SetLengthOfIes(x2ResourceStatUpdHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2ResourceStatUpdHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 ResourceStatusUpdate header: " << x2ResourceStatUpdHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2ResourceStatUpdHeader);
    packet->AddHeader(x2Header);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("packetLen = " << packet->GetSize());

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendUeData(EpcX2SapProvider::UeDataParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("gtpTeid = " << params.gtpTeid);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for targetCellId = " << params.targetCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.targetCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localUserPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    GtpuHeader gtpu;
    gtpu.SetTeid(params.gtpTeid);
    gtpu.SetLength(params.ueData->GetSize() + gtpu.GetSerializedSize() -
                   8); /// \todo This should be done in GtpuHeader
    NS_LOG_INFO("GTP-U header: " << gtpu);

    Ptr<Packet> packet = params.ueData;
    packet->AddHeader(gtpu);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("Forward UE DATA through X2 interface");
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2uUdpPort));
}

void
EpcX2::DoSendMcPdcpPdu(EpcX2Sap::UeDataParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("gtpTeid = " << params.gtpTeid);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for targetCellId = " << params.targetCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.targetCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localUserPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    // add a message type to the gtpu header, so that it is possible to distinguish at receiver
    GtpuHeader gtpu;
    gtpu.SetTeid(params.gtpTeid);
    gtpu.SetMessageType(EpcX2Header::McForwardDownlinkData);
    gtpu.SetLength(params.ueData->GetSize() + gtpu.GetSerializedSize() -
                   8); /// \todo This should be done in GtpuHeader
    NS_LOG_INFO("GTP-U header: " << gtpu);

    Ptr<Packet> packet = params.ueData;
    packet->AddHeader(gtpu);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("Forward MC UE DATA through X2 interface");
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2uUdpPort));
}

void
EpcX2::DoReceiveMcPdcpSdu(EpcX2Sap::UeDataParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("gtpTeid = " << params.gtpTeid);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for targetCellId = " << params.targetCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.targetCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localUserPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    // add a message type to the gtpu header, so that it is possible to distinguish at receiver
    GtpuHeader gtpu;
    gtpu.SetTeid(params.gtpTeid);
    gtpu.SetMessageType(EpcX2Header::McForwardUplinkData);
    gtpu.SetLength(params.ueData->GetSize() + gtpu.GetSerializedSize() -
                   8); /// \todo This should be done in GtpuHeader
    NS_LOG_INFO("GTP-U header: " << gtpu);

    Ptr<Packet> packet = params.ueData;
    packet->AddHeader(gtpu);

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    NS_LOG_INFO("Forward MC UE DATA through X2 interface");
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2uUdpPort));
}

void
EpcX2::DoSendUeSinrUpdate(EpcX2Sap::UeImsiSinrParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.targetCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for targetCellId = " << params.targetCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.targetCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localUserPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    // Build the X2 message
    EpcX2UeImsiSinrUpdateHeader x2imsiSinrHeader;
    x2imsiSinrHeader.SetUeImsiSinrMap(params.ueImsiSinrMap);
    x2imsiSinrHeader.SetSourceCellId(params.sourceCellId);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::UpdateUeSinr);
    x2Header.SetLengthOfIes(x2imsiSinrHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2imsiSinrHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 UeImsiSinrUpdate header: " << x2imsiSinrHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2imsiSinrHeader);
    packet->AddHeader(x2Header);
    NS_LOG_INFO("packetLen = " << packet->GetSize());

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendMcHandoverRequest(EpcX2SapProvider::SecondaryHandoverParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("oldCellId = " << params.oldCellId);
    NS_LOG_LOGIC("imsi = " << params.imsi);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.oldCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for oldCellId = " << params.oldCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.oldCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localCtrlPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    NS_LOG_INFO("Send X2 message: REQUEST MC HANDOVER");

    // Build the X2 message
    EpcX2McHandoverHeader x2mcHeader;
    x2mcHeader.SetTargetCellId(params.targetCellId);
    x2mcHeader.SetImsi(params.imsi);
    x2mcHeader.SetOldCellId(params.oldCellId);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::RequestMcHandover);
    x2Header.SetLengthOfIes(x2mcHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2mcHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 RequestMcHandover header: " << x2mcHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2mcHeader);
    packet->AddHeader(x2Header);
    NS_LOG_INFO("packetLen = " << packet->GetSize());

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoNotifyLteMmWaveHandoverCompleted(EpcX2SapProvider::SecondaryHandoverParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("lteCellId = " << params.oldCellId);
    NS_LOG_LOGIC("imsi = " << params.imsi);
    NS_LOG_LOGIC("MmWave cellId = " << params.targetCellId);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.oldCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for oldCellId = " << params.oldCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.oldCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localCtrlPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    NS_LOG_INFO("Send X2 message: NOTIFY MMWAVE HANDOVER TO LTE");

    // Build the X2 message
    EpcX2McHandoverHeader x2mcHeader;
    x2mcHeader.SetTargetCellId(params.targetCellId);
    x2mcHeader.SetImsi(params.imsi);
    x2mcHeader.SetOldCellId(params.oldCellId);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::NotifyMmWaveLteHandover);
    x2Header.SetLengthOfIes(x2mcHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2mcHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 RequestMcHandover header: " << x2mcHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2mcHeader);
    packet->AddHeader(x2Header);
    NS_LOG_INFO("packetLen = " << packet->GetSize());

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendSwitchConnectionToMmWave(EpcX2SapProvider::SwitchConnectionParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("MmWaveCellId = " << params.mmWaveCellId);
    NS_LOG_LOGIC("MmWaveRnti = " << params.mmWaveRnti);
    NS_LOG_LOGIC("UseMmWaveConnection " << params.useMmWaveConnection);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.mmWaveCellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for mmWaveCellId = " << params.mmWaveCellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.mmWaveCellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localCtrlPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    NS_LOG_INFO("Send X2 message: SEND CONNECTION SWITCH MESSAGE");

    // Build the X2 message
    EpcX2ConnectionSwitchHeader x2mcHeader;
    x2mcHeader.SetMmWaveRnti(params.mmWaveRnti);
    x2mcHeader.SetUseMmWaveConnection(params.useMmWaveConnection);
    x2mcHeader.SetDrbid(params.drbid);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::InitiatingMessage);
    x2Header.SetProcedureCode(EpcX2Header::SwitchConnection);
    x2Header.SetLengthOfIes(x2mcHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2mcHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 RequestMcHandover header: " << x2mcHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2mcHeader);
    packet->AddHeader(x2Header);
    NS_LOG_INFO("packetLen = " << packet->GetSize());

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

void
EpcX2::DoSendSecondaryCellHandoverCompleted(
    EpcX2SapProvider::SecondaryHandoverCompletedParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("MmWaveRnti = " << params.mmWaveRnti);
    NS_LOG_LOGIC("Imsi = " << params.imsi);
    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("Dst cellId = " << params.cellId);

    NS_ASSERT_MSG(m_x2InterfaceSockets.find(params.cellId) != m_x2InterfaceSockets.end(),
                  "Missing infos for cellId = " << params.cellId);
    Ptr<X2IfaceInfo> socketInfo = m_x2InterfaceSockets[params.cellId];
    Ptr<Socket> sourceSocket = socketInfo->m_localCtrlPlaneSocket;
    Ipv4Address targetIpAddr = socketInfo->m_remoteIpAddr;

    NS_LOG_LOGIC("sourceSocket = " << sourceSocket);
    NS_LOG_LOGIC("targetIpAddr = " << targetIpAddr);

    NS_LOG_INFO("Send X2 message: SEND SECONDARY CELL HANDOVER COMPLETED MESSAGE");

    // Build the X2 message
    EpcX2SecondaryCellHandoverCompletedHeader x2hoHeader;
    x2hoHeader.SetMmWaveRnti(params.mmWaveRnti);
    x2hoHeader.SetImsi(params.imsi);
    x2hoHeader.SetOldEnbUeX2apId(params.oldEnbUeX2apId);

    EpcX2Header x2Header;
    x2Header.SetMessageType(EpcX2Header::SuccessfulOutcome);
    x2Header.SetProcedureCode(EpcX2Header::SecondaryCellHandoverCompleted);
    x2Header.SetLengthOfIes(x2hoHeader.GetLengthOfIes());
    x2Header.SetNumberOfIes(x2hoHeader.GetNumberOfIes());

    NS_LOG_INFO("X2 header: " << x2Header);
    NS_LOG_INFO("X2 SecondaryCellHandoverCompleted header: " << x2hoHeader);

    // Build the X2 packet
    Ptr<Packet> packet = Create<Packet>();
    packet->AddHeader(x2hoHeader);
    packet->AddHeader(x2Header);
    NS_LOG_INFO("packetLen = " << packet->GetSize());

    EpcX2Tag tag(Simulator::Now());
    packet->AddPacketTag(tag);

    // Send the X2 message through the socket
    sourceSocket->SendTo(packet, 0, InetSocketAddress(targetIpAddr, m_x2cUdpPort));
}

} // namespace ns3
