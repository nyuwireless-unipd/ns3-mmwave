/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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
 *          Marco Miozzo <mmiozzo@cttc.es>
 *          Manuel Requena <manuel.requena@cttc.es>
 * Modified by:  Danilo Abrignani <danilo.abrignani@unibo.it> (Carrier Aggregation - GSoC 2015),
 *               Biljana Bojovic <biljana.bojovic@cttc.es> (Carrier Aggregation)
 *
 * Modified by Michele Polese <michele.polese@gmail.com> for DC functionalities
 * Lossless HO code from https://github.com/binhqnguyen/lena
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *              Integration of Carrier Aggregation for the mmWave module
 */

#include "lte-enb-rrc.h"

#include "ns3/lte-pdcp-tag.h"
#include <ns3/abort.h>
#include <ns3/eps-bearer-tag.h>
#include <ns3/fatal-error.h>
#include <ns3/log.h>
#include <ns3/lte-pdcp-header.h>
#include <ns3/lte-pdcp.h>
#include <ns3/lte-radio-bearer-info.h>
#include <ns3/lte-rlc-am-header.h>
#include <ns3/lte-rlc-am.h>
#include <ns3/lte-rlc-sap.h>
#include <ns3/lte-rlc-sdu-status-tag.h>
#include <ns3/lte-rlc-tm.h>
#include <ns3/lte-rlc-um-lowlat.h>
#include <ns3/lte-rlc-um.h>
#include <ns3/lte-rlc.h>
#include <ns3/mc-enb-pdcp.h>
#include <ns3/object-factory.h>
#include <ns3/object-map.h>
#include <ns3/packet.h>
#include <ns3/pointer.h>
#include <ns3/simulator.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("LteEnbRrc");

///////////////////////////////////////////
// CMAC SAP forwarder
///////////////////////////////////////////

/**
 * \brief Class for forwarding CMAC SAP User functions.
 */
class EnbRrcMemberLteEnbCmacSapUser : public LteEnbCmacSapUser
{
  public:
    /**
     * Constructor
     *
     * \param rrc ENB RRC
     * \param componentCarrierId
     */
    EnbRrcMemberLteEnbCmacSapUser(LteEnbRrc* rrc, uint8_t componentCarrierId);

    virtual uint16_t AllocateTemporaryCellRnti();
    virtual void NotifyLcConfigResult(uint16_t rnti, uint8_t lcid, bool success);
    virtual void RrcConfigurationUpdateInd(UeConfig params);

  private:
    LteEnbRrc* m_rrc;             ///< the RRC
    uint8_t m_componentCarrierId; ///< Component carrier ID
};

EnbRrcMemberLteEnbCmacSapUser::EnbRrcMemberLteEnbCmacSapUser(LteEnbRrc* rrc,
                                                             uint8_t componentCarrierId)
    : m_rrc(rrc),
      m_componentCarrierId{componentCarrierId}
{
}

uint16_t
EnbRrcMemberLteEnbCmacSapUser::AllocateTemporaryCellRnti()
{
    return m_rrc->DoAllocateTemporaryCellRnti(m_componentCarrierId);
}

void
EnbRrcMemberLteEnbCmacSapUser::NotifyLcConfigResult(uint16_t rnti, uint8_t lcid, bool success)
{
    m_rrc->DoNotifyLcConfigResult(rnti, lcid, success);
}

void
EnbRrcMemberLteEnbCmacSapUser::RrcConfigurationUpdateInd(UeConfig params)
{
    m_rrc->DoRrcConfigurationUpdateInd(params);
}

///////////////////////////////////////////
// UeManager
///////////////////////////////////////////

/// Map each of UE Manager states to its string representation.
static const std::string g_ueManagerStateName[UeManager::NUM_STATES] = {
    "INITIAL_RANDOM_ACCESS",
    "CONNECTION_SETUP",
    "CONNECTION_REJECTED",
    "CONNECTED_NORMALLY",
    "CONNECTION_RECONFIGURATION",
    "CONNECTION_REESTABLISHMENT",
    "HANDOVER_PREPARATION",
    "HANDOVER_JOINING",
    "HANDOVER_PATH_SWITCH",
    "HANDOVER_LEAVING",
    "PREPARE_MC_CONNECTION_RECONFIGURATION",
    "MC_CONNECTION_RECONFIGURATION"};

/**
 * \param s The UE manager state.
 * \return The string representation of the given state.
 */
static const std::string&
ToString(UeManager::State s)
{
    return g_ueManagerStateName[s];
}

NS_OBJECT_ENSURE_REGISTERED(UeManager);

UeManager::UeManager()
{
    NS_FATAL_ERROR("this constructor is not expected to be used");
}

UeManager::UeManager(Ptr<LteEnbRrc> rrc, uint16_t rnti, State s, uint8_t componentCarrierId)
    : m_lastAllocatedDrbid(0),
      m_rnti(rnti),
      m_imsi(0),
      m_componentCarrierId(componentCarrierId),
      m_lastRrcTransactionIdentifier(0),
      m_rrc(rrc),
      m_state(s),
      m_pendingRrcConnectionReconfiguration(false),
      m_pendingConnectToMmWave(false),
      m_sourceX2apId(0),
      m_sourceCellId(0),
      m_needPhyMacConfiguration(false),
      m_x2forwardingBufferSize(0),
      m_maxx2forwardingBufferSize(2 * 1024),
      m_allMmWaveInOutageAtInitialAccess(false),
      m_caSupportConfigured(false),
      m_pendingStartDataRadioBearers(false)
{
    NS_LOG_FUNCTION(this);
}

void
UeManager::DoInitialize()
{
    NS_LOG_FUNCTION(this);
    m_drbPdcpSapUser = new LtePdcpSpecificLtePdcpSapUser<UeManager>(this);

    m_physicalConfigDedicated.haveAntennaInfoDedicated = true;
    m_physicalConfigDedicated.antennaInfo.transmissionMode = m_rrc->m_defaultTransmissionMode;
    m_physicalConfigDedicated.haveSoundingRsUlConfigDedicated = true;
    m_physicalConfigDedicated.soundingRsUlConfigDedicated.srsConfigIndex =
        m_rrc->GetNewSrsConfigurationIndex();
    m_physicalConfigDedicated.soundingRsUlConfigDedicated.type =
        LteRrcSap::SoundingRsUlConfigDedicated::SETUP;
    m_physicalConfigDedicated.soundingRsUlConfigDedicated.srsBandwidth = 0;
    m_physicalConfigDedicated.havePdschConfigDedicated = true;
    m_physicalConfigDedicated.pdschConfigDedicated.pa = LteRrcSap::PdschConfigDedicated::dB0;

    m_rlcMap.clear();

    for (uint8_t i = 0; i < m_rrc->m_numberOfComponentCarriers; i++)
    {
        m_rrc->m_cmacSapProvider.at(i)->AddUe(m_rnti);
        m_rrc->m_cphySapProvider.at(i)->AddUe(m_rnti);
    }

    // setup the eNB side of SRB0
    {
        uint8_t lcid = 0;

        Ptr<LteRlc> rlc = CreateObject<LteRlcTm>()->GetObject<LteRlc>();
        rlc->SetLteMacSapProvider(m_rrc->m_macSapProvider);
        rlc->SetRnti(m_rnti);
        rlc->SetLcId(lcid);

        m_srb0 = CreateObject<LteSignalingRadioBearerInfo>();
        m_srb0->m_rlc = rlc;
        m_srb0->m_srbIdentity = 0;
        // no need to store logicalChannelConfig as SRB0 is pre-configured

        LteEnbCmacSapProvider::LcInfo lcinfo;
        lcinfo.rnti = m_rnti;
        lcinfo.lcId = lcid;
        // Initialise the rest of lcinfo structure even if CCCH (LCID 0) is pre-configured, and only
        // m_rnti and lcid will be used from passed lcinfo structure. See FF LTE MAC Scheduler
        // Iinterface Specification v1.11, 4.3.4 logicalChannelConfigListElement
        lcinfo.lcGroup = 0;
        lcinfo.qci = 0;
        lcinfo.isGbr = false;
        lcinfo.mbrUl = 0;
        lcinfo.mbrDl = 0;
        lcinfo.gbrUl = 0;
        lcinfo.gbrDl = 0;

        // MacSapUserForRlc in the ComponentCarrierManager MacSapUser
        LteMacSapUser* lteMacSapUser =
            m_rrc->m_ccmRrcSapProvider->ConfigureSignalBearer(lcinfo, rlc->GetLteMacSapUser());
        // Signal Channel are only on Primary Carrier
        m_rrc->m_cmacSapProvider.at(m_componentCarrierId)->AddLc(lcinfo, lteMacSapUser);
        m_rrc->m_ccmRrcSapProvider->AddLc(lcinfo, lteMacSapUser);
    }

    // setup the eNB side of SRB1; the UE side will be set up upon RRC connection establishment
    {
        uint8_t lcid = 1;

        Ptr<LteRlc> rlc = CreateObject<LteRlcAm>()->GetObject<LteRlc>();
        rlc->SetLteMacSapProvider(m_rrc->m_macSapProvider);
        rlc->SetRnti(m_rnti);
        rlc->SetLcId(lcid);

        Ptr<LtePdcp> pdcp = CreateObject<LtePdcp>();
        pdcp->SetRnti(m_rnti);
        pdcp->SetLcId(lcid);
        pdcp->SetLtePdcpSapUser(m_drbPdcpSapUser);
        pdcp->SetLteRlcSapProvider(rlc->GetLteRlcSapProvider());
        rlc->SetLteRlcSapUser(pdcp->GetLteRlcSapUser());

        m_srb1 = CreateObject<LteSignalingRadioBearerInfo>();
        m_srb1->m_rlc = rlc;
        m_srb1->m_pdcp = pdcp;
        m_srb1->m_srbIdentity = 1;
        m_srb1->m_logicalChannelConfig.priority = 1;
        m_srb1->m_logicalChannelConfig.prioritizedBitRateKbps = 100;
        m_srb1->m_logicalChannelConfig.bucketSizeDurationMs = 100;
        m_srb1->m_logicalChannelConfig.logicalChannelGroup = 0;

        LteEnbCmacSapProvider::LcInfo lcinfo;
        lcinfo.rnti = m_rnti;
        lcinfo.lcId = lcid;
        lcinfo.lcGroup = 0; // all SRBs always mapped to LCG 0
        lcinfo.qci =
            EpsBearer::GBR_CONV_VOICE; // not sure why the FF API requires a CQI even for SRBs...
        lcinfo.isGbr = true;
        lcinfo.mbrUl = 1e6;
        lcinfo.mbrDl = 1e6;
        lcinfo.gbrUl = 1e4;
        lcinfo.gbrDl = 1e4;
        // MacSapUserForRlc in the ComponentCarrierManager MacSapUser
        LteMacSapUser* MacSapUserForRlc =
            m_rrc->m_ccmRrcSapProvider->ConfigureSignalBearer(lcinfo, rlc->GetLteMacSapUser());
        // Signal Channel are only on Primary Carrier
        m_rrc->m_cmacSapProvider.at(m_componentCarrierId)->AddLc(lcinfo, MacSapUserForRlc);
        m_rrc->m_ccmRrcSapProvider->AddLc(lcinfo, MacSapUserForRlc);
    }

    LteEnbRrcSapUser::SetupUeParameters ueParams;
    ueParams.srb0SapProvider = m_srb0->m_rlc->GetLteRlcSapProvider();
    ueParams.srb1SapProvider = m_srb1->m_pdcp->GetLtePdcpSapProvider();
    m_rrc->m_rrcSapUser->SetupUe(m_rnti, ueParams);

    // configure MAC (and scheduler)
    LteEnbCmacSapProvider::UeConfig req;
    req.m_rnti = m_rnti;
    req.m_transmissionMode = m_physicalConfigDedicated.antennaInfo.transmissionMode;

    // configure PHY
    for (uint16_t i = 0; i < m_rrc->m_numberOfComponentCarriers; i++)
    {
        m_rrc->m_cmacSapProvider.at(i)->UeUpdateConfigurationReq(req);
        m_rrc->m_cphySapProvider.at(i)->SetTransmissionMode(
            m_rnti,
            m_physicalConfigDedicated.antennaInfo.transmissionMode);
        m_rrc->m_cphySapProvider.at(i)->SetSrsConfigurationIndex(
            m_rnti,
            m_physicalConfigDedicated.soundingRsUlConfigDedicated.srsConfigIndex);
    }
    // schedule this UeManager instance to be deleted if the UE does not give any sign of life
    // within a reasonable time
    Time maxConnectionDelay;
    switch (m_state)
    {
    case INITIAL_RANDOM_ACCESS:
        m_connectionRequestTimeout = Simulator::Schedule(m_rrc->m_connectionRequestTimeoutDuration,
                                                         &LteEnbRrc::ConnectionRequestTimeout,
                                                         m_rrc,
                                                         m_rnti);
        break;

    case HANDOVER_JOINING:
        m_handoverJoiningTimeout = Simulator::Schedule(m_rrc->m_handoverJoiningTimeoutDuration,
                                                       &LteEnbRrc::HandoverJoiningTimeout,
                                                       m_rrc,
                                                       m_rnti);
        break;

    default:
        NS_FATAL_ERROR("unexpected state " << ToString(m_state));
        break;
    }

    if (m_rrc->m_numberOfComponentCarriers > 1)
    {
        m_caSupportConfigured = false; // if CA is used do CA configuration
    }
    else
    {
        m_caSupportConfigured = true; // if CA is not used we do not need to configure it
    }
    m_firstConnection = false;
    m_mmWaveCellId = 0;
    m_mmWaveRnti = 0;
    m_mmWaveCellAvailableForMcSetup = false;
    m_receivedLteMmWaveHandoverCompleted = false;
    m_queuedHandoverRequestCellId = 0;
}

UeManager::~UeManager(void)
{
}

void
UeManager::DoDispose()
{
    delete m_drbPdcpSapUser;
    m_rlcMap.clear();
    // delete eventual X2-U TEIDs
    for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.begin();
         it != m_drbMap.end();
         ++it)
    {
        m_rrc->m_x2uTeidInfoMap.erase(it->second->m_gtpTeid);
    }
}

TypeId
UeManager::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::UeManager")
            .SetParent<Object>()
            .AddConstructor<UeManager>()
            .AddAttribute("DataRadioBearerMap",
                          "List of UE DataRadioBearerInfo by DRBID.",
                          ObjectMapValue(),
                          MakeObjectMapAccessor(&UeManager::m_drbMap),
                          MakeObjectMapChecker<LteDataRadioBearerInfo>())
            .AddAttribute("DataRadioRlcMap",
                          "List of UE Secondary RLC by DRBID.",
                          ObjectMapValue(),
                          MakeObjectMapAccessor(&UeManager::m_rlcMap),
                          MakeObjectMapChecker<RlcBearerInfo>())
            .AddAttribute("Srb0",
                          "SignalingRadioBearerInfo for SRB0",
                          PointerValue(),
                          MakePointerAccessor(&UeManager::m_srb0),
                          MakePointerChecker<LteSignalingRadioBearerInfo>())
            .AddAttribute("Srb1",
                          "SignalingRadioBearerInfo for SRB1",
                          PointerValue(),
                          MakePointerAccessor(&UeManager::m_srb1),
                          MakePointerChecker<LteSignalingRadioBearerInfo>())
            .AddAttribute("C-RNTI",
                          "Cell Radio Network Temporary Identifier",
                          TypeId::ATTR_GET, // read-only attribute
                          UintegerValue(0), // unused, read-only attribute
                          MakeUintegerAccessor(&UeManager::m_rnti),
                          MakeUintegerChecker<uint16_t>())
            .AddTraceSource("StateTransition",
                            "fired upon every UE state transition seen by the "
                            "UeManager at the eNB RRC",
                            MakeTraceSourceAccessor(&UeManager::m_stateTransitionTrace),
                            "ns3::UeManager::StateTracedCallback")
            .AddTraceSource("SecondaryRlcCreated",
                            "fired upon receiving RecvRlcSetupRequest",
                            MakeTraceSourceAccessor(&UeManager::m_secondaryRlcCreatedTrace),
                            "ns3::UeManager::ImsiCidRntiTracedCallback");
    return tid;
}

void
UeManager::SetSource(uint16_t sourceCellId, uint16_t sourceX2apId)
{
    m_sourceX2apId = sourceX2apId;
    m_sourceCellId = sourceCellId;
}

std::pair<uint16_t, uint16_t>
UeManager::GetSource(void)
{
    return std::pair<uint16_t, uint16_t>(m_sourceCellId, m_sourceX2apId);
}

void
UeManager::SetImsi(uint64_t imsi)
{
    m_imsi = imsi;
}

void
UeManager::SetIsMc(bool isMc)
{
    m_isMc = isMc;
}

// void
// UeManager::SetIsInterRatHoCapable (bool isInterRatHoCapable)
//{
//   m_isInterRatHoCapable = isInterRatHoCapable;
// }

bool
UeManager::GetIsMc() const
{
    return m_isMc;
}

void
UeManager::SetupDataRadioBearer(EpsBearer bearer,
                                uint8_t bearerId,
                                uint32_t gtpTeid,
                                Ipv4Address transportLayerAddress)
{
    NS_LOG_FUNCTION(this << (uint32_t)m_rnti);

    Ptr<LteDataRadioBearerInfo> drbInfo = CreateObject<LteDataRadioBearerInfo>();
    uint8_t drbid = AddDataRadioBearerInfo(drbInfo);
    uint8_t lcid = Drbid2Lcid(drbid);
    uint8_t bid = Drbid2Bid(drbid);
    NS_ASSERT_MSG(bearerId == 0 || bid == bearerId,
                  "bearer ID mismatch (" << (uint32_t)bid << " != " << (uint32_t)bearerId
                                         << ", the assumption that ID are allocated in the same "
                                            "way by MME and RRC is not valid any more");
    drbInfo->m_epsBearer = bearer;
    drbInfo->m_epsBearerIdentity = bid;
    drbInfo->m_drbIdentity = drbid;
    drbInfo->m_logicalChannelIdentity = lcid;
    drbInfo->m_gtpTeid = gtpTeid;
    drbInfo->m_transportLayerAddress = transportLayerAddress;

    if (m_state == HANDOVER_JOINING)
    {
        // setup TEIDs for receiving data eventually forwarded over X2-U
        LteEnbRrc::X2uTeidInfo x2uTeidInfo;
        x2uTeidInfo.rnti = m_rnti;
        x2uTeidInfo.drbid = drbid;
        std::pair<std::map<uint32_t, LteEnbRrc::X2uTeidInfo>::iterator, bool> ret =
            m_rrc->m_x2uTeidInfoMap.insert(
                std::pair<uint32_t, LteEnbRrc::X2uTeidInfo>(gtpTeid, x2uTeidInfo));
        NS_ASSERT_MSG(ret.second == true, "overwriting a pre-existing entry in m_x2uTeidInfoMap");
    }

    TypeId rlcTypeId = m_rrc->GetRlcType(bearer);

    ObjectFactory rlcObjectFactory;
    rlcObjectFactory.SetTypeId(rlcTypeId);
    Ptr<LteRlc> rlc = rlcObjectFactory.Create()->GetObject<LteRlc>();
    rlc->SetLteMacSapProvider(m_rrc->m_macSapProvider);
    rlc->SetRnti(m_rnti);

    drbInfo->m_rlc = rlc;

    rlc->SetLcId(lcid);

    // we need PDCP only for real RLC, i.e., RLC/UM or RLC/AM
    // if we are using RLC/SM we don't care of anything above RLC
    if (rlcTypeId != LteRlcSm::GetTypeId())
    {
        Ptr<McEnbPdcp> pdcp =
            CreateObject<McEnbPdcp>(); // Modified with McEnbPdcp to support MC
                                       // This will allow to add an X2 interface to pdcp
        pdcp->SetRnti(m_rnti);
        pdcp->SetLcId(lcid);
        pdcp->SetLtePdcpSapUser(m_drbPdcpSapUser);
        pdcp->SetLteRlcSapProvider(rlc->GetLteRlcSapProvider());
        rlc->SetLteRlcSapUser(pdcp->GetLteRlcSapUser());
        drbInfo->m_pdcp = pdcp;
    }

    std::vector<LteCcmRrcSapProvider::LcsConfig> lcOnCcMapping =
        m_rrc->m_ccmRrcSapProvider->SetupDataRadioBearer(bearer,
                                                         bearerId,
                                                         m_rnti,
                                                         lcid,
                                                         m_rrc->GetLogicalChannelGroup(bearer),
                                                         rlc->GetLteMacSapUser());
    // LteEnbCmacSapProvider::LcInfo lcinfo;
    // lcinfo.rnti = m_rnti;
    // lcinfo.lcId = lcid;
    // lcinfo.lcGroup = m_rrc->GetLogicalChannelGroup (bearer);
    // lcinfo.qci = bearer.qci;
    // lcinfo.isGbr = bearer.IsGbr ();
    // lcinfo.mbrUl = bearer.gbrQosInfo.mbrUl;
    // lcinfo.mbrDl = bearer.gbrQosInfo.mbrDl;
    // lcinfo.gbrUl = bearer.gbrQosInfo.gbrUl;
    // lcinfo.gbrDl = bearer.gbrQosInfo.gbrDl;
    // use a for cycle to send the AddLc to the appropriate Mac Sap
    // if the sap is not initialized the appropriated method has to be called
    std::vector<LteCcmRrcSapProvider::LcsConfig>::iterator itLcOnCcMapping = lcOnCcMapping.begin();
    NS_ASSERT_MSG(itLcOnCcMapping != lcOnCcMapping.end(), "Problem");
    for (itLcOnCcMapping = lcOnCcMapping.begin(); itLcOnCcMapping != lcOnCcMapping.end();
         ++itLcOnCcMapping)
    {
        NS_LOG_DEBUG(this << " RNTI " << itLcOnCcMapping->lc.rnti << "Lcid "
                          << (uint16_t)itLcOnCcMapping->lc.lcId << " lcGroup "
                          << (uint16_t)itLcOnCcMapping->lc.lcGroup << " ComponentCarrierId "
                          << itLcOnCcMapping->componentCarrierId);
        uint8_t index = itLcOnCcMapping->componentCarrierId;
        LteEnbCmacSapProvider::LcInfo lcinfo = itLcOnCcMapping->lc;
        LteMacSapUser* msu = itLcOnCcMapping->msu;
        m_rrc->m_cmacSapProvider.at(index)->AddLc(lcinfo, msu);
        m_rrc->m_ccmRrcSapProvider->AddLc(lcinfo, msu);
    }

    if (rlcTypeId == LteRlcAm::GetTypeId())
    {
        drbInfo->m_rlcConfig.choice = LteRrcSap::RlcConfig::AM;
    }
    else
    {
        drbInfo->m_rlcConfig.choice = LteRrcSap::RlcConfig::UM_BI_DIRECTIONAL;
    }

    drbInfo->m_logicalChannelIdentity = lcid;
    drbInfo->m_logicalChannelConfig.priority = m_rrc->GetLogicalChannelPriority(bearer);
    drbInfo->m_logicalChannelConfig.logicalChannelGroup = m_rrc->GetLogicalChannelGroup(bearer);
    if (bearer.IsGbr())
    {
        drbInfo->m_logicalChannelConfig.prioritizedBitRateKbps = bearer.gbrQosInfo.gbrUl;
    }
    else
    {
        drbInfo->m_logicalChannelConfig.prioritizedBitRateKbps = 0;
    }
    drbInfo->m_logicalChannelConfig.bucketSizeDurationMs = 1000;

    EpcX2Sap::RlcSetupRequest req;
    req.sourceCellId = m_rrc->GetCellId();
    req.gtpTeid = drbInfo->m_gtpTeid;
    req.lteRnti = m_rnti;
    req.drbid = drbid;
    // req.lcinfo = lcinfo;
    req.logicalChannelConfig = drbInfo->m_logicalChannelConfig;
    req.rlcConfig = drbInfo->m_rlcConfig;
    req.targetCellId = 0;
    req.mmWaveRnti = 0;
    // mmWaveRnti & targetCellId will be set before sending the request
    drbInfo->m_rlcSetupRequest = req;

    drbInfo->m_epsBearer = bearer;
    drbInfo->m_isMc = false;
    ScheduleRrcConnectionReconfiguration();
}

void
UeManager::RecordDataRadioBearersToBeStarted()
{
    NS_LOG_FUNCTION(this << (uint32_t)m_rnti);
    for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.begin();
         it != m_drbMap.end();
         ++it)
    {
        m_drbsToBeStarted.push_back(it->first);
    }
}

void
UeManager::StartDataRadioBearers()
{
    NS_LOG_FUNCTION(this << (uint32_t)m_rnti);
    for (std::list<uint8_t>::iterator drbIdIt = m_drbsToBeStarted.begin();
         drbIdIt != m_drbsToBeStarted.end();
         ++drbIdIt)
    {
        std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator drbIt = m_drbMap.find(*drbIdIt);
        NS_ASSERT(drbIt != m_drbMap.end());
        drbIt->second->m_rlc->Initialize();
        if (drbIt->second->m_pdcp)
        {
            drbIt->second->m_pdcp->Initialize();
        }
    }
    m_drbsToBeStarted.clear();
}

void
UeManager::ReleaseDataRadioBearer(uint8_t drbid)
{
    NS_LOG_FUNCTION(this << (uint32_t)m_rnti << (uint32_t)drbid);
    uint8_t lcid = Drbid2Lcid(drbid);
    std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.find(drbid);
    NS_ASSERT_MSG(it != m_drbMap.end(),
                  "request to remove radio bearer with unknown drbid " << drbid);

    // first delete eventual X2-U TEIDs
    m_rrc->m_x2uTeidInfoMap.erase(it->second->m_gtpTeid);

    m_drbMap.erase(it);
    std::vector<uint8_t> ccToRelease =
        m_rrc->m_ccmRrcSapProvider->ReleaseDataRadioBearer(m_rnti, lcid);
    std::vector<uint8_t>::iterator itCcToRelease = ccToRelease.begin();
    NS_ASSERT_MSG(itCcToRelease != ccToRelease.end(),
                  "request to remove radio bearer with unknown drbid (ComponentCarrierManager)");
    for (itCcToRelease = ccToRelease.begin(); itCcToRelease != ccToRelease.end(); ++itCcToRelease)
    {
        m_rrc->m_cmacSapProvider.at(*itCcToRelease)->ReleaseLc(m_rnti, lcid);
    }
    LteRrcSap::RadioResourceConfigDedicated rrcd;
    rrcd.havePhysicalConfigDedicated = false;
    rrcd.drbToReleaseList.push_back(drbid);
    // populating RadioResourceConfigDedicated information element as per 3GPP TS 36.331
    // version 9.2.0
    rrcd.havePhysicalConfigDedicated = true;
    rrcd.physicalConfigDedicated = m_physicalConfigDedicated;

    // populating RRCConnectionReconfiguration message as per 3GPP TS 36.331 version 9.2.0 Release 9
    LteRrcSap::RrcConnectionReconfiguration msg;
    msg.haveMeasConfig = false;
    msg.haveMobilityControlInfo = false;
    msg.radioResourceConfigDedicated = rrcd;
    msg.haveRadioResourceConfigDedicated = true;
    // ToDo: Resend in any case this configuration
    // needs to be initialized
    msg.haveNonCriticalExtension = false;
    // RRC Connection Reconfiguration towards UE
    m_rrc->m_rrcSapUser->SendRrcConnectionReconfiguration(m_rnti, msg);
}

void
LteEnbRrc::DoSendReleaseDataRadioBearer(uint64_t imsi, uint16_t rnti, uint8_t bearerId)
{
    Ptr<UeManager> ueManager = GetUeManager(rnti);
    // Bearer de-activation towards UE
    ueManager->ReleaseDataRadioBearer(bearerId);
    // Bearer de-activation indication towards epc-enb application
    m_s1SapProvider->DoSendReleaseIndication(imsi, rnti, bearerId);
}

void
UeManager::ScheduleRrcConnectionReconfiguration()
{
    NS_LOG_FUNCTION(this);
    switch (m_state)
    {
    case INITIAL_RANDOM_ACCESS:
    case CONNECTION_SETUP:
    case CONNECTION_RECONFIGURATION:
    case CONNECTION_REESTABLISHMENT:
    case HANDOVER_PREPARATION:
    case HANDOVER_JOINING:
    case HANDOVER_LEAVING:
        // a previous reconfiguration still ongoing, we need to wait for it to be finished
        m_pendingRrcConnectionReconfiguration = true;
        break;

    case CONNECTED_NORMALLY: {
        m_pendingRrcConnectionReconfiguration = false;
        LteRrcSap::RrcConnectionReconfiguration msg = BuildRrcConnectionReconfiguration();
        m_rrc->m_rrcSapUser->SendRrcConnectionReconfiguration(m_rnti, msg);
        RecordDataRadioBearersToBeStarted();
        SwitchToState(CONNECTION_RECONFIGURATION);
    }
    break;

    case PREPARE_MC_CONNECTION_RECONFIGURATION: {
        m_pendingRrcConnectionReconfiguration = false;
        LteRrcSap::RrcConnectionReconfiguration msg = BuildRrcConnectionReconfiguration();
        msg.haveMeasConfig = false;
        msg.haveMobilityControlInfo = false;
        msg.radioResourceConfigDedicated.srbToAddModList.clear();
        msg.radioResourceConfigDedicated.physicalConfigDedicated.haveAntennaInfoDedicated = false;
        msg.radioResourceConfigDedicated.physicalConfigDedicated.haveSoundingRsUlConfigDedicated =
            false;
        msg.radioResourceConfigDedicated.physicalConfigDedicated.havePdschConfigDedicated = false;
        m_rrc->m_rrcSapUser->SendRrcConnectionReconfiguration(m_rnti, msg);
        RecordDataRadioBearersToBeStarted();
        SwitchToState(MC_CONNECTION_RECONFIGURATION);
    }
    break;

    default:
        NS_FATAL_ERROR("method unexpected in state " << ToString(m_state));
        break;
    }
}

void
UeManager::PrepareHandover(uint16_t cellId)
{
    NS_LOG_FUNCTION(this << cellId);
    switch (m_state)
    {
    case CONNECTED_NORMALLY: {
        m_targetCellId = cellId;
        EpcX2SapProvider::HandoverRequestParams params;
        params.oldEnbUeX2apId = m_rnti;
        params.cause = EpcX2SapProvider::HandoverDesirableForRadioReason;
        params.sourceCellId = m_rrc->ComponentCarrierToCellId(m_componentCarrierId);
        params.targetCellId = cellId;
        params.mmeUeS1apId = m_imsi;
        params.ueAggregateMaxBitRateDownlink = 200 * 1000;
        params.ueAggregateMaxBitRateUplink = 100 * 1000;
        params.bearers = GetErabList();
        params.rlcRequests = m_rlcRequestVector;
        // clear the vector to avoid keeping old information
        // the target eNB will add the rlcRequests in its own vector
        m_rlcRequestVector.clear();

        LteRrcSap::HandoverPreparationInfo hpi;
        hpi.asConfig.sourceUeIdentity = m_rnti;
        hpi.asConfig.sourceDlCarrierFreq = m_rrc->m_dlEarfcn;
        hpi.asConfig.sourceMeasConfig = m_rrc->m_ueMeasConfig;
        hpi.asConfig.sourceRadioResourceConfig = GetRadioResourceConfigForHandoverPreparationInfo();
        hpi.asConfig.sourceMasterInformationBlock.dlBandwidth = m_rrc->m_dlBandwidth;
        hpi.asConfig.sourceMasterInformationBlock.systemFrameNumber = 0;
        hpi.asConfig.sourceSystemInformationBlockType1.cellAccessRelatedInfo.plmnIdentityInfo
            .plmnIdentity = m_rrc->m_sib1.at(m_componentCarrierId)
                                .cellAccessRelatedInfo.plmnIdentityInfo.plmnIdentity;
        hpi.asConfig.sourceSystemInformationBlockType1.cellAccessRelatedInfo.cellIdentity =
            m_rrc->ComponentCarrierToCellId(m_componentCarrierId);
        hpi.asConfig.sourceSystemInformationBlockType1.cellAccessRelatedInfo.csgIndication =
            m_rrc->m_sib1.at(m_componentCarrierId).cellAccessRelatedInfo.csgIndication;
        hpi.asConfig.sourceSystemInformationBlockType1.cellAccessRelatedInfo.csgIdentity =
            m_rrc->m_sib1.at(m_componentCarrierId).cellAccessRelatedInfo.csgIdentity;
        LteEnbCmacSapProvider::RachConfig rc =
            m_rrc->m_cmacSapProvider.at(m_componentCarrierId)->GetRachConfig();
        hpi.asConfig.sourceSystemInformationBlockType2.radioResourceConfigCommon.rachConfigCommon
            .preambleInfo.numberOfRaPreambles = rc.numberOfRaPreambles;
        hpi.asConfig.sourceSystemInformationBlockType2.radioResourceConfigCommon.rachConfigCommon
            .raSupervisionInfo.preambleTransMax = rc.preambleTransMax;
        hpi.asConfig.sourceSystemInformationBlockType2.radioResourceConfigCommon.rachConfigCommon
            .raSupervisionInfo.raResponseWindowSize = rc.raResponseWindowSize;
        hpi.asConfig.sourceSystemInformationBlockType2.freqInfo.ulCarrierFreq = m_rrc->m_ulEarfcn;
        hpi.asConfig.sourceSystemInformationBlockType2.freqInfo.ulBandwidth = m_rrc->m_ulBandwidth;
        params.rrcContext = m_rrc->m_rrcSapUser->EncodeHandoverPreparationInformation(hpi);

        params.isMc = m_isMc;
        NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
        NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
        NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
        NS_LOG_LOGIC("mmeUeS1apId = " << params.mmeUeS1apId);
        NS_LOG_LOGIC("rrcContext   = " << params.rrcContext);

        m_rrc->m_x2SapProvider->SendHandoverRequest(params);
        SwitchToState(HANDOVER_PREPARATION);
    }
    break;

    case CONNECTION_RECONFIGURATION:
    case HANDOVER_JOINING: // there may be some delays in the TX of RRC messages, thus an handover
                           // may be completed at UE side, but not at eNB side
    {
        m_queuedHandoverRequestCellId = cellId;
        NS_LOG_INFO("UeManager is in CONNECTION_RECONFIGURATION, postpone the PrepareHandover "
                    "command to cell "
                    << m_queuedHandoverRequestCellId);
    }
    break;
    default:
        NS_FATAL_ERROR("method unexpected in state " << ToString(m_state));
        break;
    }
}

/*
 * Merge 2 buffers of RlcAmPdus into 1 vector with increment order of Pdus
 */
std::vector<LteRlcAm::RetxPdu>
UeManager::MergeBuffers(std::vector<LteRlcAm::RetxPdu> first, std::vector<LteRlcAm::RetxPdu> second)
{
    LteRlcAmHeader rlcamHeader_1, rlcamHeader_2;
    std::vector<LteRlcAm::RetxPdu> result;
    std::vector<LteRlcAm::RetxPdu>::iterator it_1 = first.begin();
    std::vector<LteRlcAm::RetxPdu>::iterator it_2 = second.begin();
    bool end_1_reached = false;
    bool end_2_reached = false;
    while (it_1 != first.end() && it_2 != second.end())
    {
        while (!((*it_1).m_pdu))
        {
            ++it_1;
            if (it_1 == first.end())
            {
                end_1_reached = true;
                break;
            }
        }
        while (!((*it_2).m_pdu))
        {
            ++it_2;
            if (it_2 == second.end())
            {
                end_2_reached = true;
                break;
            }
        }
        if (!end_1_reached && !end_2_reached)
        {
            (*it_1).m_pdu->PeekHeader(rlcamHeader_1);
            (*it_2).m_pdu->PeekHeader(rlcamHeader_2);
            if (rlcamHeader_1.GetSequenceNumber() > rlcamHeader_2.GetSequenceNumber())
            {
                result.push_back((*it_2));
                ++it_2;
            }
            else if (rlcamHeader_2.GetSequenceNumber() > rlcamHeader_1.GetSequenceNumber())
            {
                result.push_back((*it_1));
                ++it_1;
            }
            else
            {
                result.push_back((*it_1));
                ++it_1;
                ++it_2;
            }
            NS_LOG_DEBUG("first,second = " << rlcamHeader_1.GetSequenceNumber() << ","
                                           << rlcamHeader_2.GetSequenceNumber());
        }
        else
        {
            break;
        }
    }
    while (it_1 != first.end())
    {
        result.push_back((*it_1));
        it_1++;
    }
    while (it_2 != second.end())
    {
        result.push_back((*it_2));
        it_2++;
    }
    return result;
}

void
UeManager::RecvHandoverRequestAck(EpcX2SapUser::HandoverRequestAckParams params)
{
    NS_LOG_FUNCTION(this);

    NS_ASSERT_MSG(params.notAdmittedBearers.empty(),
                  "not admission of some bearers upon handover is not supported");
    NS_ASSERT_MSG(params.admittedBearers.size() == m_drbMap.size(),
                  "not enough bearers in admittedBearers");

    // note: the Handover command from the target eNB to the source eNB
    // is expected to be sent transparently to the UE; however, here we
    // decode the message and eventually re-encode it. This way we can
    // support both a real RRC protocol implementation and an ideal one
    // without actual RRC protocol encoding.

    Ptr<Packet> encodedHandoverCommand = params.rrcContext;
    LteRrcSap::RrcConnectionReconfiguration handoverCommand =
        m_rrc->m_rrcSapUser->DecodeHandoverCommand(encodedHandoverCommand);
    if (handoverCommand.haveNonCriticalExtension)
    {
        // Total number of component carriers =
        // handoverCommand.nonCriticalExtension.sCellsToAddModList.size() + 1 (Primary carrier)
        if (handoverCommand.nonCriticalExtension.sCellsToAddModList.size() + 1 !=
            m_rrc->m_numberOfComponentCarriers)
        {
            // Currently handover is only possible if source and target eNBs have equal number of
            // component carriers
            NS_FATAL_ERROR("The source and target eNBs have unequal number of component carriers. "
                           "Target eNB CCs = "
                           << handoverCommand.nonCriticalExtension.sCellsToAddModList.size() + 1
                           << " Source eNB CCs = " << m_rrc->m_numberOfComponentCarriers);
        }
    }
    m_rrc->m_rrcSapUser->SendRrcConnectionReconfiguration(m_rnti, handoverCommand);
    SwitchToState(HANDOVER_LEAVING);
    m_handoverLeavingTimeout = Simulator::Schedule(m_rrc->m_handoverLeavingTimeoutDuration,
                                                   &LteEnbRrc::HandoverLeavingTimeout,
                                                   m_rrc,
                                                   m_rnti);
    NS_ASSERT(handoverCommand.haveMobilityControlInfo);
    m_rrc->m_handoverStartTrace(m_imsi,
                                m_rrc->ComponentCarrierToCellId(m_componentCarrierId),
                                m_rnti,
                                handoverCommand.mobilityControlInfo.targetPhysCellId);

    EpcX2SapProvider::SnStatusTransferParams sst;
    sst.oldEnbUeX2apId = params.oldEnbUeX2apId;
    sst.newEnbUeX2apId = params.newEnbUeX2apId;
    sst.sourceCellId = params.sourceCellId;
    sst.targetCellId = params.targetCellId;
    for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator drbIt = m_drbMap.begin();
         drbIt != m_drbMap.end();
         ++drbIt)
    {
        // SN status transfer is only for AM RLC
        if (drbIt->second->m_rlc->GetObject<LteRlcAm>())
        {
            LtePdcp::Status status = drbIt->second->m_pdcp->GetStatus();
            EpcX2Sap::ErabsSubjectToStatusTransferItem i;
            i.dlPdcpSn = status.txSn;
            i.ulPdcpSn = status.rxSn;
            sst.erabsSubjectToStatusTransferList.push_back(i);
        }
    }
    m_rrc->m_x2SapProvider->SendSnStatusTransfer(sst);

    // on a mmWave eNB, for a UeManager of an MC device, notify the EpcX2 class that it has to
    // forward the incoming packets
    if (m_rrc->m_ismmWave && m_isMc)
    {
        NS_LOG_INFO(
            "Notify the X2 that packets with a certain TEID must be forwarded to the targetCell");
        for (std::map<uint8_t, Ptr<RlcBearerInfo>>::iterator rlcIt = m_rlcMap.begin();
             rlcIt != m_rlcMap.end();
             ++rlcIt)
        {
            m_rrc->m_x2SapProvider->AddTeidToBeForwarded(rlcIt->second->gtpTeid,
                                                         params.targetCellId);
        }
    }

    // LL HO
    // Forward RlcTxBuffers to target eNodeb.
    // TODO forwarding for secondary cell HO
    NS_LOG_INFO("m_drbMap size " << m_drbMap.size() << " in cell " << m_rrc->m_cellId
                                 << " forward RLC buffers");
    for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator drbIt = m_drbMap.begin();
         drbIt != m_drbMap.end();
         ++drbIt)
    {
        ForwardRlcBuffers(drbIt->second->m_rlc,
                          drbIt->second->m_pdcp,
                          drbIt->second->m_gtpTeid,
                          0,
                          0,
                          0);
    }

    if (m_rrc->m_ismmWave && m_isMc) // for secondary cell HO
    {
        NS_LOG_INFO("m_rlcMap size " << m_rlcMap.size() << " in cell " << m_rrc->m_cellId
                                     << " forward RLC buffers");
        for (std::map<uint8_t, Ptr<RlcBearerInfo>>::iterator rlcIt = m_rlcMap.begin();
             rlcIt != m_rlcMap.end();
             ++rlcIt)
        {
            // the buffers are forwarded to m_targetCellId, which is set in PrepareHandover
            // the target cell
            ForwardRlcBuffers(rlcIt->second->m_rlc, 0, rlcIt->second->gtpTeid, 0, 1, 0);
        }
    }
}

// This code from the LL HO implementation is refactored in a function
// in order to be used also when switching from LTE to MmWave and back
void
UeManager::ForwardRlcBuffers(Ptr<LteRlc> rlc,
                             Ptr<LtePdcp> pdcp,
                             uint32_t gtpTeid,
                             bool mcLteToMmWaveForwarding,
                             bool mcMmToMmWaveForwarding,
                             uint8_t bid)
{
    // RlcBuffers forwarding only for RlcAm bearers.
    if (rlc->GetObject<LteRlcAm>())
    {
        // Copy lte-rlc-am.m_txOnBuffer to X2 forwarding buffer.
        Ptr<LteRlcAm> rlcAm = rlc->GetObject<LteRlcAm>();
        uint32_t txonBufferSize = rlcAm->GetTxBufferSize();
        std::vector<Ptr<Packet>> txonBuffer = rlcAm->GetTxBuffer();
        // m_x2forwardingBufferSize =
        // drbIt->second->m_rlc->GetObject<LteRlcAm>()->GetTxBufferSize(); m_x2forwardingBuffer =
        // drbIt->second->m_rlc->GetObject<LteRlcAm>()->GetTxBuffer();
        uint32_t txedBufferSize = rlcAm->GetTxedBufferSize();
        std::vector<LteRlcAm::RetxPdu> txedBuffer = rlcAm->GetTxedBuffer();
        uint32_t retxBufferSize = rlcAm->GetRetxBufferSize();
        std::vector<LteRlcAm::RetxPdu> retxBuffer = rlcAm->GetRetxBuffer();

        // Translate Pdus in Rlc txed/retx buffer into RLC Sdus
        // and put these Sdus into rlcAm->m_transmittingRlcSdus.
        NS_LOG_INFO("retxBuffer size = " << retxBufferSize);
        NS_LOG_INFO("txedBuffer size = " << txedBufferSize);
        // Merge txed and retx buffers into a single buffer before doing RlcPdusToRlc.
        if (retxBufferSize + txedBufferSize > 0)
        {
            std::vector<LteRlcAm::RetxPdu> sortedTxedRetxBuffer;
            if (retxBufferSize == 0)
            {
                sortedTxedRetxBuffer = txedBuffer;
            }
            else if (txedBufferSize == 0)
            {
                sortedTxedRetxBuffer = retxBuffer;
            }
            else
            {
                sortedTxedRetxBuffer = MergeBuffers(txedBuffer, retxBuffer);
            }
            rlcAm->RlcPdusToRlcSdus(sortedTxedRetxBuffer);
        }

        // Construct the forwarding buffer
        // Forwarding buffer = retxBuffer + txedBuffer + txonBuffer.
        // if ( txonBufferSize > 0 )
        //{
        LtePdcpHeader pdcpHeader;
        uint32_t pos = 0;
        for (std::vector<Ptr<Packet>>::iterator it = txonBuffer.begin(); it != txonBuffer.end();
             ++it)
        {
            pos++;
            if ((*it)->GetSize() > 3)
            {
                (*it)->PeekHeader(pdcpHeader);
                NS_LOG_DEBUG("txonBuffer SEQ = " << pdcpHeader.GetSequenceNumber()
                                                 << " Size = " << (*it)->GetSize());
            }
            else
            {
                NS_LOG_UNCOND("Fragment too small in txonBuffer, pos " << pos);
            }
        }

        // this cycle adds the SDUs given by the merge of txed and retxed buffers
        if (rlcAm->GetTransmittingRlcSduBufferSize() > 0)
        { // something inside the RLC AM's transmitting buffer
            NS_LOG_DEBUG("ADDING TRANSMITTING SDUS OF RLC AM TO X2FORWARDINGBUFFER... Size = "
                         << rlcAm->GetTransmittingRlcSduBufferSize());
            // copy the RlcSdu buffer (map) to forwardingBuffer.
            std::map<uint32_t, Ptr<Packet>> rlcAmTransmittingBuffer =
                rlcAm->GetTransmittingRlcSduBuffer();
            NS_LOG_DEBUG(" *** SIZE = " << rlcAmTransmittingBuffer.size());
            for (std::map<uint32_t, Ptr<Packet>>::iterator it = rlcAmTransmittingBuffer.begin();
                 it != rlcAmTransmittingBuffer.end();
                 ++it)
            {
                if (it->second)
                {
                    NS_LOG_DEBUG(this << " add to forwarding buffer SEQ = " << it->first
                                      << " Ptr<Packet> = " << it->second);
                    m_x2forwardingBuffer.push_back(it->second);
                }
            }
            NS_LOG_DEBUG(this << " ADDING TXONBUFFER OF RLC AM " << m_rnti
                              << " Size = " << txonBufferSize);

            Ptr<Packet> segmentedRlcsdu = rlcAm->GetSegmentedRlcsdu();
            if (segmentedRlcsdu != NULL)
            {
                segmentedRlcsdu->PeekHeader(pdcpHeader);
                NS_LOG_DEBUG(this << "SegmentedRlcSdu = " << segmentedRlcsdu->GetSize()
                                  << " SEQ = " << pdcpHeader.GetSequenceNumber());
                // insert the complete version of the fragmented SDU to the front of txonBuffer.
                txonBuffer.insert(txonBuffer.begin(), segmentedRlcsdu);
            }
            m_x2forwardingBuffer.insert(m_x2forwardingBuffer.end(),
                                        txonBuffer.begin(),
                                        txonBuffer.end());
            m_x2forwardingBufferSize += rlcAm->GetTransmittingRlcSduBufferSize() + txonBufferSize;

            // Get the rlcAm
            std::vector<Ptr<Packet>> rlcAmTxedSduBuffer = rlcAm->GetTxedRlcSduBuffer();
            LtePdcpHeader pdcpHeader_1;
            m_x2forwardingBuffer.at(0)->PeekHeader(pdcpHeader_1);
            uint16_t i = 0;
            for (std::vector<Ptr<Packet>>::iterator it = rlcAmTxedSduBuffer.begin();
                 it != rlcAmTxedSduBuffer.end();
                 ++it)
            {
                if ((*it) != NULL)
                {
                    (*it)->PeekHeader(pdcpHeader);
                    NS_LOG_DEBUG("rlcAmTxedSduBuffer SEQ = " << pdcpHeader.GetSequenceNumber()
                                                             << " Size = " << (*it)->GetSize());

                    // add the previous SDU of the forwarding buffer to the forwarding buffer.
                    if (pdcpHeader.GetSequenceNumber() >= (pdcpHeader_1.GetSequenceNumber() - 2) &&
                        pdcpHeader.GetSequenceNumber() <= (pdcpHeader_1.GetSequenceNumber()))
                    {
                        NS_LOG_DEBUG("Added previous SDU to forwarding buffer SEQ = "
                                     << pdcpHeader.GetSequenceNumber()
                                     << " Size = " << (*it)->GetSize());
                        m_x2forwardingBuffer.insert(m_x2forwardingBuffer.begin() + i,
                                                    (*it)->Copy());
                        ++i;
                    }
                }
            }
        }
        else
        { // TransmittingBuffer is empty. Only copy TxonBuffer.
            NS_LOG_DEBUG(this << " ADDING TXONBUFFER OF RLC AM " << m_rnti
                              << " Size = " << txonBufferSize);
            m_x2forwardingBuffer = txonBuffer;
            m_x2forwardingBufferSize += txonBufferSize;
        }
        //}
    }
    // For RlcUM, no forwarding available as the simulator itself (seamless HO).
    // However, as the LTE-UMTS book, PDCP txbuffer should be forwarded for seamless
    // HO. Enable this code for txbuffer forwarding in seamless HO (which is believe to
    // be correct).
    else if (rlc->GetObject<LteRlcUm>())
    {
        // Copy lte-rlc-um.m_txOnBuffer to X2 forwarding buffer.
        NS_LOG_DEBUG(this << " Copying txonBuffer from RLC UM " << m_rnti);
        m_x2forwardingBuffer = rlc->GetObject<LteRlcUm>()->GetTxBuffer();
        m_x2forwardingBufferSize = rlc->GetObject<LteRlcUm>()->GetTxBufferSize();
    }
    else if (rlc->GetObject<LteRlcUmLowLat>())
    {
        // Copy lte-rlc-um-low-lat.m_txOnBuffer to X2 forwarding buffer.
        NS_LOG_DEBUG(this << " Copying txonBuffer from RLC UM " << m_rnti);
        m_x2forwardingBuffer = rlc->GetObject<LteRlcUmLowLat>()->GetTxBuffer();
        m_x2forwardingBufferSize = rlc->GetObject<LteRlcUmLowLat>()->GetTxBufferSize();
    }
    // LteRlcAm m_txBuffer stores PDCP "PDU".
    NS_LOG_DEBUG(this << " m_x2forw buffer size = " << m_x2forwardingBufferSize);
    // Forwarding the packet inside m_x2forwardingBuffer to target eNB.

    // Prepare the variables for the LTE to MmWave DC forward
    Ptr<McEnbPdcp> mcPdcp;
    if (mcLteToMmWaveForwarding)
    {
        mcPdcp = DynamicCast<McEnbPdcp>(pdcp);
        NS_ASSERT_MSG(mcPdcp, "Invalid option for standard PDCP");
        NS_ASSERT_MSG(bid > 0, "Bid can't be 0");
        NS_ASSERT_MSG(mcPdcp->GetUseMmWaveConnection(),
                      "The McEnbPdcp is not forwarding data to the mmWave eNB, check if the switch "
                      "happened!");
    }

    while (!m_x2forwardingBuffer.empty())
    {
        NS_LOG_DEBUG(this << " Forwarding m_x2forwardingBuffer to target eNB, gtpTeid = "
                          << gtpTeid);
        EpcX2Sap::UeDataParams params;
        params.sourceCellId = m_rrc->m_cellId;
        params.targetCellId = m_targetCellId;
        params.gtpTeid = gtpTeid;
        // Remove tags to get PDCP SDU from PDCP PDU.
        // Ptr<Packet> rlcSdu =  (*(m_x2forwardingBuffer.begin()))->Copy();
        Ptr<Packet> rlcSdu = m_x2forwardingBuffer.at(0);
        // Tags to be removed from rlcSdu (from outer to inner)
        // LteRlcSduStatusTag rlcSduStatusTag;
        // RlcTag  rlcTag; //rlc layer timestamp
        // PdcpTag pdcpTag;  //pdcp layer timestamp
        LtePdcpHeader pdcpHeader;

        NS_LOG_DEBUG("RlcSdu size = " << rlcSdu->GetSize());
        // rlcSdu->RemoveHeader(pdcpHeader); //remove pdcp header

        // only forward data PDCP PDUs (1-DATA_PDU,0-CTR_PDU)
        if (rlcSdu->GetSize() >= 3)
        {
            rlcSdu->PeekHeader(pdcpHeader);
            if (pdcpHeader.GetDcBit() == 1)
            { // ignore control SDU.
                NS_LOG_LOGIC("SEQ = " << pdcpHeader.GetSequenceNumber());
                NS_LOG_LOGIC("removed pdcp header, size = " << rlcSdu->GetSize());

                rlcSdu->RemoveAllPacketTags(); // this does not remove byte tags
                NS_LOG_LOGIC("removed tags, size = " << rlcSdu->GetSize());
                params.ueData = rlcSdu;
                /*
                rlcSdu->RemovePacketTag(rlcSduStatusTag); //remove Rlc status tag.
                NS_LOG_DEBUG ("removed rlc status tag, size = " << rlcSdu->GetSize() );
                rlcSdu->RemovePacketTag(rlcTag);  //remove Rlc timestamp
                NS_LOG_DEBUG ("removed rlc timestamp, size = " << rlcSdu->GetSize() );
                //rlcSdu->RemoveByteTag(pdcpTag); //remove pdcp timestamp
                //NS_LOG_DEBUG ("removed pdcp timestamp, size = " << rlcSdu->GetSize());
                */

                if (!mcLteToMmWaveForwarding)
                {
                    if (!mcMmToMmWaveForwarding)
                    {
                        rlcSdu->RemoveHeader(pdcpHeader); // remove pdcp header

                        NS_LOG_INFO("Forward to target cell in HO");
                        m_rrc->m_x2SapProvider->SendUeData(params);
                        NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
                        NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
                        NS_LOG_LOGIC("gtpTeid = " << params.gtpTeid);
                        NS_LOG_LOGIC("ueData = " << params.ueData);
                        NS_LOG_LOGIC("ueData size = " << params.ueData->GetSize());
                    }
                    else
                    {
                        NS_LOG_INFO("Forward to target cell RLC in HO");
                        m_rrc->m_x2SapProvider->ForwardRlcPdu(params);
                        NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
                        NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
                        NS_LOG_LOGIC("gtpTeid = " << params.gtpTeid);
                        NS_LOG_LOGIC("ueData = " << params.ueData);
                        NS_LOG_LOGIC("ueData size = " << params.ueData->GetSize());
                    }
                }
                else // the target eNB has no PDCP entity. Thus re-insert the packets in the
                // LTE eNB PDCP, which will forward them to the MmWave RLC entity.
                // Thus this method must be called after the switch to MmWave is done!
                {
                    rlcSdu->RemoveHeader(pdcpHeader); // remove pdcp header
                    NS_LOG_INFO("Forward to mmWave cell in switch");
                    NS_ASSERT(mcPdcp);
                    NS_ASSERT(mcPdcp->GetUseMmWaveConnection());
                    LtePdcpSapProvider::TransmitPdcpSduParameters pdcpParams;
                    pdcpParams.pdcpSdu = rlcSdu;
                    pdcpParams.rnti = m_rnti;
                    pdcpParams.lcid = Bid2Lcid(bid);
                    mcPdcp->GetLtePdcpSapProvider()->TransmitPdcpSdu(pdcpParams);
                }
            }
        }
        else
        {
            NS_LOG_UNCOND("Too small, not forwarded");
        }
        m_x2forwardingBufferSize -= (*(m_x2forwardingBuffer.begin()))->GetSize();
        m_x2forwardingBuffer.erase(m_x2forwardingBuffer.begin());
        NS_LOG_LOGIC(this << " After forwarding: buffer size = " << m_x2forwardingBufferSize);
    }
}

LteRrcSap::RadioResourceConfigDedicated
UeManager::GetRadioResourceConfigForHandoverPreparationInfo()
{
    NS_LOG_FUNCTION(this);
    return BuildRadioResourceConfigDedicated();
}

LteRrcSap::RrcConnectionReconfiguration
UeManager::GetRrcConnectionReconfigurationForHandover()
{
    NS_LOG_FUNCTION(this);
    return BuildRrcConnectionReconfiguration();
}

void
UeManager::SendData(uint8_t bid, Ptr<Packet> p)
{
    NS_LOG_FUNCTION(this << p << (uint16_t)bid);
    switch (m_state)
    {
    case INITIAL_RANDOM_ACCESS:
    case CONNECTION_SETUP:
        NS_LOG_WARN("not connected, discarding packet");
        return;
        break;

    case CONNECTED_NORMALLY:
    case CONNECTION_RECONFIGURATION:
    case MC_CONNECTION_RECONFIGURATION:
    case CONNECTION_REESTABLISHMENT:
    case HANDOVER_PREPARATION:
    case HANDOVER_JOINING:
    case HANDOVER_PATH_SWITCH: {
        NS_LOG_LOGIC("queueing data on PDCP for transmission over the air");
        LtePdcpSapProvider::TransmitPdcpSduParameters params;
        params.pdcpSdu = p;
        params.rnti = m_rnti;
        params.lcid = Bid2Lcid(bid);
        uint8_t drbid = Bid2Drbid(bid);
        // Transmit PDCP sdu only if DRB ID found in drbMap
        std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.find(drbid);
        if (it != m_drbMap.end())
        {
            Ptr<LteDataRadioBearerInfo> bearerInfo = GetDataRadioBearerInfo(drbid);
            if (bearerInfo != NULL)
            {
                LtePdcpSapProvider* pdcpSapProvider = bearerInfo->m_pdcp->GetLtePdcpSapProvider();
                pdcpSapProvider->TransmitPdcpSdu(params);
            }
        }
    }
    break;

    case HANDOVER_LEAVING: {
        NS_LOG_LOGIC("SEQ SEQ HANDOVERLEAVING STATE LTE ENB RRC.");
        // m_x2forwardingBuffer is empty, forward incomming pkts to target eNB.
        if (m_x2forwardingBuffer.empty())
        {
            NS_LOG_INFO("forwarding incoming pkts to target eNB over X2-U");
            NS_LOG_LOGIC("forwarding data to target eNB over X2-U");
            uint8_t drbid = Bid2Drbid(bid);
            EpcX2Sap::UeDataParams params;
            params.sourceCellId = m_rrc->ComponentCarrierToCellId(m_componentCarrierId);
            params.targetCellId = m_targetCellId;
            params.gtpTeid = GetDataRadioBearerInfo(drbid)->m_gtpTeid;
            params.ueData = p;
            NS_LOG_LOGIC("PDCP_FORWARDING_SEQ");
            NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
            NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
            NS_LOG_LOGIC("gtpTeid = " << params.gtpTeid);
            NS_LOG_LOGIC("ueData = " << params.ueData);
            NS_LOG_LOGIC("ueData size = " << params.ueData->GetSize());
            m_rrc->m_x2SapProvider->SendUeData(params);
        }
        // m_x2forwardingBuffer is not empty, append incomming pkts to m_x2forwardingBuffer.
        // Forwarding of this m_x2forwardingBuffer is done in RecvHandoverRequestAck
        else
        {
            NS_LOG_INFO("append incomming pkts to m_x2forwardingBuffer");
            m_x2forwardingBuffer.push_back(p);
            // NS_LOG_DEBUG("Forwarding but push_bach to buffer SEQ = " <<
            // pdcpHeader.GetSequenceNumber());
        }
    }
    break;

    default:
        NS_FATAL_ERROR("method unexpected in state " << ToString(m_state));
        break;
    }
}

std::vector<EpcX2Sap::ErabToBeSetupItem>
UeManager::GetErabList()
{
    NS_LOG_FUNCTION(this);
    std::vector<EpcX2Sap::ErabToBeSetupItem> ret;
    for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.begin();
         it != m_drbMap.end();
         ++it)
    {
        EpcX2Sap::ErabToBeSetupItem etbsi;
        etbsi.erabId = it->second->m_epsBearerIdentity;
        etbsi.erabLevelQosParameters = it->second->m_epsBearer;
        etbsi.dlForwarding = false;
        etbsi.transportLayerAddress = it->second->m_transportLayerAddress;
        etbsi.gtpTeid = it->second->m_gtpTeid;
        ret.push_back(etbsi);
    }
    return ret;
}

void
UeManager::SendUeContextRelease()
{
    NS_LOG_FUNCTION(this);
    switch (m_state)
    {
    case HANDOVER_PATH_SWITCH:
        NS_LOG_INFO("Send UE CONTEXT RELEASE from target eNB to source eNB");
        EpcX2SapProvider::UeContextReleaseParams ueCtxReleaseParams;
        ueCtxReleaseParams.oldEnbUeX2apId = m_sourceX2apId;
        ueCtxReleaseParams.newEnbUeX2apId = m_rnti;
        ueCtxReleaseParams.sourceCellId = m_sourceCellId;
        ueCtxReleaseParams.targetCellId = m_targetCellId;
        m_rrc->m_x2SapProvider->SendUeContextRelease(ueCtxReleaseParams);
        SwitchToState(CONNECTED_NORMALLY);
        m_rrc->m_handoverEndOkTrace(m_imsi,
                                    m_rrc->ComponentCarrierToCellId(m_componentCarrierId),
                                    m_rnti);
        break;

    default:
        NS_FATAL_ERROR("method unexpected in state " << ToString(m_state));
        break;
    }
}

void
UeManager::RecvHandoverPreparationFailure(uint16_t cellId)
{
    NS_LOG_FUNCTION(this << cellId);
    switch (m_state)
    {
    case HANDOVER_PREPARATION:
        NS_ASSERT(cellId == m_targetCellId);
        NS_LOG_INFO("target eNB sent HO preparation failure, aborting HO");
        SwitchToState(CONNECTED_NORMALLY);
        break;

    case HANDOVER_LEAVING:
        NS_ASSERT(cellId == m_targetCellId);
        NS_LOG_INFO("target eNB sent HO preparation failure, aborting HO because "
                    "RrcConnectionReconfigurationCompleted was not received at target");
        break;
    default:
        NS_FATAL_ERROR("method unexpected in state " << ToString(m_state));
        break;
    }
}

void
UeManager::RecvSnStatusTransfer(EpcX2SapUser::SnStatusTransferParams params)
{
    NS_LOG_FUNCTION(this);
    for (std::vector<EpcX2Sap::ErabsSubjectToStatusTransferItem>::iterator erabIt =
             params.erabsSubjectToStatusTransferList.begin();
         erabIt != params.erabsSubjectToStatusTransferList.end();
         ++erabIt)
    {
        // LtePdcp::Status status;
        // status.txSn = erabIt->dlPdcpSn;
        // status.rxSn = erabIt->ulPdcpSn;
        // uint8_t drbId = Bid2Drbid (erabIt->erabId);
        // std::map <uint8_t, Ptr<LteDataRadioBearerInfo> >::iterator drbIt = m_drbMap.find (drbId);
        // NS_ASSERT_MSG (drbIt != m_drbMap.end (), "could not find DRBID " << (uint32_t) drbId);
        // drbIt->second->m_pdcp->SetStatus (status);
    }
}

void
UeManager::RecvUeContextRelease(EpcX2SapUser::UeContextReleaseParams params)
{
    NS_LOG_FUNCTION(this);
    NS_ASSERT_MSG(m_state == HANDOVER_LEAVING, "method unexpected in state " << ToString(m_state));
    m_handoverLeavingTimeout.Cancel();
    NS_LOG_INFO("Remove UE " << m_rnti << " from eNB " << m_rrc->m_cellId);
    if (m_rrc->m_ismmWave && m_isMc)
    {
        for (std::map<uint8_t, Ptr<RlcBearerInfo>>::iterator rlcIt = m_rlcMap.begin();
             rlcIt != m_rlcMap.end();
             ++rlcIt)
        {
            NS_LOG_INFO("Remove the X2 forward for TEID " << rlcIt->second->gtpTeid);
            m_rrc->m_x2SapProvider->RemoveTeidToBeForwarded(rlcIt->second->gtpTeid);
        }
    }
}

void
UeManager::RecvRlcSetupRequest(EpcX2SapUser::RlcSetupRequest params) // TODO only on MC
{
    if (m_isMc)
    {
        NS_LOG_INFO("Setup remote RLC in cell " << m_rrc->GetCellId());
        NS_ASSERT_MSG(m_state == HANDOVER_JOINING || params.mmWaveRnti == m_rnti,
                      "Rnti not correct " << params.mmWaveRnti << " " << m_rnti);
        // store the params, so that on handover the eNB sends the RLC request
        // to the othe MmWaveEnb
        m_rlcRequestVector.push_back(params);

        // setup TEIDs to receive data eventually forwarded over X2-U
        LteEnbRrc::X2uTeidInfo x2uTeidInfo;
        x2uTeidInfo.rnti = m_rnti;
        x2uTeidInfo.drbid = params.drbid;
        std::pair<std::map<uint32_t, LteEnbRrc::X2uTeidInfo>::iterator, bool> ret;
        ret = m_rrc->m_x2uMcTeidInfoMap.insert(
            std::pair<uint32_t, LteEnbRrc::X2uTeidInfo>(params.gtpTeid, x2uTeidInfo));
        // TODO overwrite may be legit, as in EpcX2::SetMcEpcX2PdcpUser
        // NS_ASSERT_MSG (ret.second == true, "overwriting a pre-existing entry in
        // m_x2uTeidInfoMap");
        NS_LOG_INFO("Added entry in m_x2uMcTeidInfoMap");

        // create new Rlc
        // define a new struct similar to LteDataRadioBearerInfo with only rlc
        Ptr<RlcBearerInfo> rlcInfo = CreateObject<RlcBearerInfo>();
        rlcInfo->targetCellId = params.sourceCellId; // i.e. the LTE cell
        rlcInfo->gtpTeid = params.gtpTeid;
        rlcInfo->mmWaveRnti = m_rnti;
        rlcInfo->lteRnti = params.lteRnti;
        rlcInfo->drbid = params.drbid;
        rlcInfo->rlcConfig = params.rlcConfig;
        rlcInfo->logicalChannelConfig = params.logicalChannelConfig;

        uint8_t lcid = Drbid2Lcid(params.drbid);
        uint8_t bid = Drbid2Bid(params.drbid);

        EpsBearer bearer;
        TypeId rlcTypeId = m_rrc->GetRlcType(bearer); // actually, this doesn't depend on bearer

        ObjectFactory rlcObjectFactory;
        rlcObjectFactory.SetTypeId(rlcTypeId);
        Ptr<LteRlc> rlc = rlcObjectFactory.Create()->GetObject<LteRlc>();
        NS_LOG_INFO("Created rlc " << rlc);
        rlc->SetLteMacSapProvider(m_rrc->m_macSapProvider);
        rlc->SetRnti(m_rnti);

        rlcInfo->m_rlc = rlc;

        rlc->SetLcId(lcid);

        if (rlcTypeId != LteRlcSm::GetTypeId())
        {
            // connect with remote PDCP
            rlc->SetEpcX2RlcProvider(m_rrc->GetEpcX2RlcProvider());
            EpcX2Sap::UeDataParams ueParams;
            ueParams.sourceCellId = m_rrc->GetCellId();
            ueParams.targetCellId = rlcInfo->targetCellId; // the LTE cell
            ueParams.gtpTeid = rlcInfo->gtpTeid;
            rlc->SetUeDataParams(ueParams);
            m_rrc->m_x2SapProvider->SetEpcX2RlcUser(params.gtpTeid, rlc->GetEpcX2RlcUser());
        }

        std::vector<LteCcmRrcSapProvider::LcsConfig> lcOnCcMapping =
            m_rrc->m_ccmRrcSapProvider->SetupDataRadioBearer(bearer,
                                                             bid,
                                                             m_rnti,
                                                             lcid,
                                                             m_rrc->GetLogicalChannelGroup(bearer),
                                                             rlc->GetLteMacSapUser());
        // LteEnbCmacSapProvider::LcInfo lcinfo;
        // lcinfo.rnti = m_rnti;
        // lcinfo.lcId = lcid;
        // lcinfo.lcGroup = m_rrc->GetLogicalChannelGroup (params.lcinfo.isGbr);
        // lcinfo.qci = params.lcinfo.qci;
        // lcinfo.isGbr = params.lcinfo.isGbr;
        // lcinfo.mbrUl = params.lcinfo.mbrUl;
        // lcinfo.mbrDl = params.lcinfo.mbrDl;
        // lcinfo.gbrUl = params.lcinfo.gbrUl;
        // lcinfo.gbrDl = params.lcinfo.gbrDl;
        std::vector<LteCcmRrcSapProvider::LcsConfig>::iterator itLcOnCcMapping =
            lcOnCcMapping.begin();
        NS_ASSERT_MSG(itLcOnCcMapping != lcOnCcMapping.end(), "Problem");
        for (itLcOnCcMapping = lcOnCcMapping.begin(); itLcOnCcMapping != lcOnCcMapping.end();
             ++itLcOnCcMapping)
        {
            NS_LOG_DEBUG(this << " RNTI " << itLcOnCcMapping->lc.rnti << "Lcid "
                              << (uint16_t)itLcOnCcMapping->lc.lcId << " lcGroup "
                              << (uint16_t)itLcOnCcMapping->lc.lcGroup << " ComponentCarrierId "
                              << itLcOnCcMapping->componentCarrierId);
            uint8_t index = itLcOnCcMapping->componentCarrierId;
            LteEnbCmacSapProvider::LcInfo lcinfo = itLcOnCcMapping->lc;
            LteMacSapUser* msu = itLcOnCcMapping->msu;
            m_rrc->m_cmacSapProvider.at(index)->AddLc(lcinfo, msu);
            m_rrc->m_ccmRrcSapProvider->AddLc(lcinfo, msu);
        }

        // rlcInfo->lcinfo = lcinfo;

        rlcInfo->logicalChannelIdentity = lcid;
        rlcInfo->logicalChannelConfig.priority = m_rrc->GetLogicalChannelPriority(bearer);
        rlcInfo->logicalChannelConfig.logicalChannelGroup = m_rrc->GetLogicalChannelGroup(bearer);
        if (bearer.IsGbr())
        {
            rlcInfo->logicalChannelConfig.prioritizedBitRateKbps =
                params.logicalChannelConfig.prioritizedBitRateKbps;
        }
        else
        {
            rlcInfo->logicalChannelConfig.prioritizedBitRateKbps = 0;
        }
        rlcInfo->logicalChannelConfig.bucketSizeDurationMs =
            params.logicalChannelConfig.bucketSizeDurationMs;

        m_rlcMap[params.drbid] = rlcInfo; // TODO add assert

        // callback to notify the BearerConnector that new rlcs are available
        m_secondaryRlcCreatedTrace(m_imsi, m_rrc->m_cellId, m_rnti);

        if (m_state !=
            HANDOVER_JOINING) // when performing a secondary cell HO do not ack the LTE eNB
        {
            // Ack the LTE BS, that will trigger the setup in the UE
            EpcX2Sap::UeDataParams ackParams;
            ackParams.sourceCellId = params.targetCellId;
            ackParams.targetCellId = params.sourceCellId;
            ackParams.gtpTeid = params.gtpTeid;
            m_rrc->m_x2SapProvider->SendRlcSetupCompleted(ackParams);
        }
    }
    else
    {
        NS_FATAL_ERROR("This is not a MC device");
    }
}

void
UeManager::RecvRlcSetupCompleted(uint8_t drbid)
{
    NS_ASSERT_MSG(m_drbMap.find(drbid) != m_drbMap.end(), "The drbid does not match");
    NS_LOG_INFO("Setup completed for split DataRadioBearer " << (uint16_t)drbid);
    m_drbMap.find(drbid)->second->m_isMc = true;
    SwitchToState(PREPARE_MC_CONNECTION_RECONFIGURATION);
    ScheduleRrcConnectionReconfiguration();
}

// methods forwarded from RRC SAP

void
UeManager::CompleteSetupUe(LteEnbRrcSapProvider::CompleteSetupUeParameters params)
{
    NS_LOG_FUNCTION(this);
    m_srb0->m_rlc->SetLteRlcSapUser(params.srb0SapUser);
    m_srb1->m_pdcp->SetLtePdcpSapUser(params.srb1SapUser);
}

void
UeManager::RecvRrcConnectionRequest(LteRrcSap::RrcConnectionRequest msg)
{
    NS_LOG_FUNCTION(this);
    switch (m_state)
    {
    case INITIAL_RANDOM_ACCESS: {
        m_connectionRequestTimeout.Cancel();
        m_isMc = msg.isMc;

        if (m_rrc->m_admitRrcConnectionRequest == true)
        {
            m_imsi = msg.ueIdentity;
            m_rrc->RegisterImsiToRnti(m_imsi, m_rnti);
            m_rrc->m_mmWaveCellSetupCompleted[m_imsi] = false;
            NS_LOG_DEBUG("For imsi " << m_imsi << " m_rrc->m_mmWaveCellSetupCompleted[m_imsi] "
                                     << m_rrc->m_mmWaveCellSetupCompleted[m_imsi]);
            if (!m_isMc && m_rrc->m_s1SapProvider != 0)
            {
                m_rrc->m_s1SapProvider->InitialUeMessage(m_imsi, m_rnti);
            }

            // send RRC CONNECTION SETUP to UE
            LteRrcSap::RrcConnectionSetup msg2;
            msg2.rrcTransactionIdentifier = GetNewRrcTransactionIdentifier();
            msg2.radioResourceConfigDedicated = BuildRadioResourceConfigDedicated();
            m_rrc->m_rrcSapUser->SendRrcConnectionSetup(m_rnti, msg2);

            RecordDataRadioBearersToBeStarted();
            m_connectionSetupTimeout = Simulator::Schedule(m_rrc->m_connectionSetupTimeoutDuration,
                                                           &LteEnbRrc::ConnectionSetupTimeout,
                                                           m_rrc,
                                                           m_rnti);
            SwitchToState(CONNECTION_SETUP);
        }
        else
        {
            NS_LOG_INFO("rejecting connection request for RNTI " << m_rnti);

            // send RRC CONNECTION REJECT to UE
            LteRrcSap::RrcConnectionReject rejectMsg;
            rejectMsg.waitTime = 3;
            m_rrc->m_rrcSapUser->SendRrcConnectionReject(m_rnti, rejectMsg);

            m_connectionRejectedTimeout =
                Simulator::Schedule(m_rrc->m_connectionRejectedTimeoutDuration,
                                    &LteEnbRrc::ConnectionRejectedTimeout,
                                    m_rrc,
                                    m_rnti);
            SwitchToState(CONNECTION_REJECTED);
        }
    }
    break;

    default:
        NS_FATAL_ERROR("method unexpected in state " << ToString(m_state));
        break;
    }
}

void
UeManager::RecvRrcConnectionSetupCompleted(LteRrcSap::RrcConnectionSetupCompleted msg)
{
    NS_LOG_FUNCTION(this);
    switch (m_state)
    {
    case CONNECTION_SETUP:
        m_connectionSetupTimeout.Cancel();
        // StartDataRadioBearers ();
        NS_LOG_INFO("m_firstConnection " << m_firstConnection);

        if (!m_rrc->m_ismmWave)
        {
            // the UE is connected to the LTE eNB, now we have to select the best
            // mmWave eNB. We do it after the CA configuration.
            m_pendingConnectToMmWave = true; // the UE
            NS_LOG_INFO("m_pendingConnectToMmWave " << m_pendingConnectToMmWave);
        }

        if (m_caSupportConfigured == false && m_rrc->m_numberOfComponentCarriers > 1)
        {
            m_pendingRrcConnectionReconfiguration = true; // Force Reconfiguration
            m_pendingStartDataRadioBearers = true;
        }
        else
        {
            m_pendingStartDataRadioBearers = false;
            StartDataRadioBearers();
        }
        SwitchToState(CONNECTED_NORMALLY);
        m_rrc->m_connectionEstablishedTrace(m_imsi,
                                            m_rrc->ComponentCarrierToCellId(m_componentCarrierId),
                                            m_rnti);
        break;

    default:
        NS_FATAL_ERROR("method unexpected in state " << ToString(m_state));
        break;
    }
}

bool
UeManager::GetAllMmWaveInOutageAtInitialAccess()
{
    return m_allMmWaveInOutageAtInitialAccess;
}

void
UeManager::SetAllMmWaveInOutageAtInitialAccess(bool param)
{
    m_allMmWaveInOutageAtInitialAccess = param;
}

void
UeManager::RecvRrcConnectionReconfigurationCompleted(
    LteRrcSap::RrcConnectionReconfigurationCompleted msg)
{
    NS_LOG_FUNCTION(this);
    switch (m_state)
    {
    case MC_CONNECTION_RECONFIGURATION:
        // cycle on the MC bearers and perform switch to MmWave connection
        for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.begin();
             it != m_drbMap.end();
             ++it)
        {
            if (it->second->m_isMc)
            {
                bool useMmWaveConnection = true;
                Ptr<McEnbPdcp> pdcp = DynamicCast<McEnbPdcp>(it->second->m_pdcp);
                if (pdcp)
                {
                    pdcp->SwitchConnection(useMmWaveConnection);
                    m_rrc->m_lastMmWaveCell[m_imsi] = m_mmWaveCellId;
                    m_rrc->m_mmWaveCellSetupCompleted[m_imsi] = true;
                    NS_LOG_INFO("Imsi " << m_imsi << " m_mmWaveCellSetupCompleted set to "
                                        << m_rrc->m_mmWaveCellSetupCompleted[m_imsi] << " for cell "
                                        << m_rrc->m_lastMmWaveCell[m_imsi]);
                    m_rrc->m_imsiUsingLte[m_imsi] = false;
                    ForwardRlcBuffers(it->second->m_rlc,
                                      pdcp,
                                      it->second->m_gtpTeid,
                                      1,
                                      0,
                                      it->first);
                }
                else
                {
                    NS_FATAL_ERROR("A device defined as MC has not a McEnbPdcp");
                }
            }
        }
        // no break so that also the CONNECTION_RECONFIGURATION code is executed
    case CONNECTION_RECONFIGURATION:
        StartDataRadioBearers();
        if (m_needPhyMacConfiguration)
        {
            // configure MAC (and scheduler)
            LteEnbCmacSapProvider::UeConfig req;
            req.m_rnti = m_rnti;
            req.m_transmissionMode = m_physicalConfigDedicated.antennaInfo.transmissionMode;
            for (uint8_t i = 0; i < m_rrc->m_numberOfComponentCarriers; i++)
            {
                m_rrc->m_cmacSapProvider.at(i)->UeUpdateConfigurationReq(req);

                // configure PHY
                m_rrc->m_cphySapProvider.at(i)->SetTransmissionMode(req.m_rnti,
                                                                    req.m_transmissionMode);
                double paDouble = LteRrcSap::ConvertPdschConfigDedicated2Double(
                    m_physicalConfigDedicated.pdschConfigDedicated);
                m_rrc->m_cphySapProvider.at(i)->SetPa(m_rnti, paDouble);
            }

            m_needPhyMacConfiguration = false;
        }
        if (m_mmWaveCellAvailableForMcSetup)
        {
            NS_LOG_INFO("Notify the secondary cell that some bearers' RLC can be setup");
            NS_ASSERT_MSG((m_mmWaveCellId != 0) && (m_mmWaveRnti != 0),
                          "Unkonwn secondary MmWave cell");
            RecvRrcSecondaryCellInitialAccessSuccessful(m_mmWaveRnti, m_mmWaveCellId);
        }
        if (m_receivedLteMmWaveHandoverCompleted)
        {
            NS_LOG_INFO(
                "Notify LteEnbRrc that LTE cell received a NotifyLteMmWaveHandoverCompleted and "
                "has completed CONNECTION_RECONFIGURATION");
            m_rrc->m_mmWaveCellSetupCompleted.find(m_imsi)->second = true;
            m_rrc->m_imsiUsingLte.find(m_imsi)->second = true;
        }

        // for IA on LTE eNB, need to wait for CONNECTION_RECONF to be completed and a bearer to be
        // setup
        if (m_rrc->m_interRatHoMode && m_firstConnection && !m_rrc->m_ismmWave)
        {
            m_rrc->m_mmWaveCellSetupCompleted[m_imsi] = true;
            m_rrc->m_lastMmWaveCell[m_imsi] = m_rrc->m_cellId;
            m_rrc->m_imsiUsingLte[m_imsi] = true; // the inital connection happened on a LTE eNB
            m_firstConnection = false;
        }
        SwitchToState(CONNECTED_NORMALLY);
        NS_LOG_INFO("m_queuedHandoverRequestCellId " << m_queuedHandoverRequestCellId);
        if (m_queuedHandoverRequestCellId > 0)
        {
            NS_LOG_INFO("Call the postponed PrepareHandover to cell "
                        << m_queuedHandoverRequestCellId);
            PrepareHandover(m_queuedHandoverRequestCellId);
        }
        m_rrc->m_connectionReconfigurationTrace(
            m_imsi,
            m_rrc->ComponentCarrierToCellId(m_componentCarrierId),
            m_rnti);
        break;

    // This case is added to NS-3 in order to handle bearer de-activation scenario for CONNECTED
    // state UE
    case CONNECTED_NORMALLY:
        NS_LOG_INFO("ignoring RecvRrcConnectionReconfigurationCompleted in state "
                    << ToString(m_state));
        break;

    case HANDOVER_LEAVING:
        NS_LOG_INFO("ignoring RecvRrcConnectionReconfigurationCompleted in state "
                    << ToString(m_state));
        break;

    case HANDOVER_JOINING: {
        m_handoverJoiningTimeout.Cancel();
        if (!m_isMc)
        {
            NS_LOG_INFO("Send PATH SWITCH REQUEST to the MME");
            EpcEnbS1SapProvider::PathSwitchRequestParameters params;
            params.rnti = m_rnti;
            params.cellId = m_rrc->ComponentCarrierToCellId(m_componentCarrierId);
            params.mmeUeS1Id = m_imsi;
            SwitchToState(HANDOVER_PATH_SWITCH);
            for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.begin();
                 it != m_drbMap.end();
                 ++it)
            {
                EpcEnbS1SapProvider::BearerToBeSwitched b;
                b.epsBearerId = it->second->m_epsBearerIdentity;
                b.teid = it->second->m_gtpTeid;
                params.bearersToBeSwitched.push_back(b);
            }

            m_rrc->m_s1SapProvider->PathSwitchRequest(params);
        }
        else
        {
            // Send "path switch to the LTE eNB"
            // The context release will be sent by the LTE eNB
            NS_LOG_INFO("RRC Reconfiguration completed after secondary cell HO: send path switch "
                        "to LTE coordinator");
            EpcX2Sap::SecondaryHandoverCompletedParams params;
            params.mmWaveRnti = m_rnti;
            params.oldEnbUeX2apId = m_sourceX2apId;
            params.imsi = m_imsi;
            params.cellId =
                m_rrc->m_lteCellId; // just a placeholder to find the correct X2 socket in EpcX2
            // Notify the LTE eNB
            m_rrc->m_handoverEndOkTrace(m_imsi, m_rrc->m_cellId, m_rnti);
            m_rrc->m_x2SapProvider->SendSecondaryCellHandoverCompleted(params);
            SwitchToState(CONNECTED_NORMALLY);
            NS_LOG_INFO("m_queuedHandoverRequestCellId " << m_queuedHandoverRequestCellId);
            if (m_queuedHandoverRequestCellId > 0)
            {
                NS_LOG_INFO("Call the postponed PrepareHandover to cell "
                            << m_queuedHandoverRequestCellId);
                PrepareHandover(m_queuedHandoverRequestCellId);
            }
        }
    }
    break;

    default:
        NS_FATAL_ERROR("method unexpected in state " << ToString(m_state));
        break;
    }
}

void
UeManager::RecvRrcConnectionReestablishmentRequest(
    LteRrcSap::RrcConnectionReestablishmentRequest msg)
{
    NS_LOG_FUNCTION(this);
    switch (m_state)
    {
    case CONNECTED_NORMALLY:
        break;

    case HANDOVER_LEAVING:
        m_handoverLeavingTimeout.Cancel();
        break;

    default:
        NS_FATAL_ERROR("method unexpected in state " << ToString(m_state));
        break;
    }

    LteRrcSap::RrcConnectionReestablishment msg2;
    msg2.rrcTransactionIdentifier = GetNewRrcTransactionIdentifier();
    msg2.radioResourceConfigDedicated = BuildRadioResourceConfigDedicated();
    m_rrc->m_rrcSapUser->SendRrcConnectionReestablishment(m_rnti, msg2);
    SwitchToState(CONNECTION_REESTABLISHMENT);
}

void
UeManager::RecvRrcConnectionReestablishmentComplete(
    LteRrcSap::RrcConnectionReestablishmentComplete msg)
{
    NS_LOG_FUNCTION(this);
    SwitchToState(CONNECTED_NORMALLY);
}

void
UeManager::RecvMeasurementReport(LteRrcSap::MeasurementReport msg)
{
    uint8_t measId = msg.measResults.measId;
    NS_LOG_FUNCTION(this << (uint16_t)measId);
    NS_LOG_LOGIC("measId " << (uint16_t)measId << " haveMeasResultNeighCells "
                           << msg.measResults.haveMeasResultNeighCells << " measResultListEutra "
                           << msg.measResults.measResultListEutra.size() << " haveScellsMeas "
                           << msg.measResults.haveScellsMeas << " measScellResultList "
                           << msg.measResults.measScellResultList.measResultScell.size());
    NS_LOG_LOGIC("serving cellId " << m_rrc->ComponentCarrierToCellId(m_componentCarrierId)
                                   << " RSRP " << (uint16_t)msg.measResults.rsrpResult << " RSRQ "
                                   << (uint16_t)msg.measResults.rsrqResult);

    for (std::list<LteRrcSap::MeasResultEutra>::iterator it =
             msg.measResults.measResultListEutra.begin();
         it != msg.measResults.measResultListEutra.end();
         ++it)
    {
        NS_LOG_LOGIC("neighbour cellId " << it->physCellId << " RSRP "
                                         << (it->haveRsrpResult ? (uint16_t)it->rsrpResult : 255)
                                         << " RSRQ "
                                         << (it->haveRsrqResult ? (uint16_t)it->rsrqResult : 255));
    }

    if ((m_rrc->m_handoverManagementSapProvider != 0) &&
        (m_rrc->m_handoverMeasIds.find(measId) != m_rrc->m_handoverMeasIds.end()))
    {
        // this measurement was requested by the handover algorithm
        m_rrc->m_handoverManagementSapProvider->ReportUeMeas(m_rnti, msg.measResults);
    }

    if ((m_rrc->m_ccmRrcSapProvider != 0) &&
        (m_rrc->m_componentCarrierMeasIds.find(measId) != m_rrc->m_componentCarrierMeasIds.end()))
    {
        // this measurement was requested by the handover algorithm
        m_rrc->m_ccmRrcSapProvider->ReportUeMeas(m_rnti, msg.measResults);
    }

    if ((m_rrc->m_anrSapProvider != 0) &&
        (m_rrc->m_anrMeasIds.find(measId) != m_rrc->m_anrMeasIds.end()))
    {
        // this measurement was requested by the ANR function
        m_rrc->m_anrSapProvider->ReportUeMeas(msg.measResults);
    }

    if ((m_rrc->m_ffrRrcSapProvider.at(0) != 0) &&
        (m_rrc->m_ffrMeasIds.find(measId) != m_rrc->m_ffrMeasIds.end()))
    {
        // this measurement was requested by the FFR function
        m_rrc->m_ffrRrcSapProvider.at(0)->ReportUeMeas(m_rnti, msg.measResults);
    }

    if (msg.measResults.haveScellsMeas == true)
    {
        for (std::list<LteRrcSap::MeasResultScell>::iterator it =
                 msg.measResults.measScellResultList.measResultScell.begin();
             it != msg.measResults.measScellResultList.measResultScell.end();
             ++it)
        {
            m_rrc->m_ffrRrcSapProvider.at(it->servFreqId)->ReportUeMeas(m_rnti, msg.measResults);
            /// ToDo: implement on Ffr algorithm the code to properly parsing the new measResults
            /// message format alternatevely it is needed to 'repack' properly the measResults
            /// message before sending to Ffr
        }
    }

    /// Report any measurements to ComponentCarrierManager, so it can react to any change or
    /// activate the SCC
    m_rrc->m_ccmRrcSapProvider->ReportUeMeas(m_rnti, msg.measResults);
    // fire a trace source
    m_rrc->m_recvMeasurementReportTrace(m_imsi,
                                        m_rrc->ComponentCarrierToCellId(m_componentCarrierId),
                                        m_rnti,
                                        msg);

} // end of UeManager::RecvMeasurementReport

void
UeManager::RecvRrcSecondaryCellInitialAccessSuccessful(uint16_t mmWaveRnti, uint16_t mmWaveCellId)
{
    m_mmWaveCellId = mmWaveCellId;
    m_mmWaveRnti = mmWaveRnti;

    NS_LOG_INFO("Map size " << m_drbMap.size());

    // If the Map size is > 0 (Bearers already setup in the LTE cell) perform this action
    // immediately, otherwise wait for the InitialContextSetupResponse in EpcEnbApplication
    // that calls DataRadioBearerSetupRequest
    if (m_drbMap.size() == 0)
    {
        m_mmWaveCellAvailableForMcSetup = true;
        NS_LOG_INFO("Postpone RLC setup in the secondary cell since no bearers are yet available");
        return;
    }
    else
    {
        for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.begin();
             it != m_drbMap.end();
             ++it)
        {
            if (!(it->second->m_isMc) ||
                (it->second->m_isMc &&
                 m_rrc->m_lastMmWaveCell.find(m_imsi)->second != m_mmWaveCellId))
            {
                Ptr<McEnbPdcp> pdcp = DynamicCast<McEnbPdcp>(it->second->m_pdcp);
                if (pdcp)
                {
                    // Get the EPC X2 and set it in the PDCP
                    pdcp->SetEpcX2PdcpProvider(m_rrc->GetEpcX2PdcpProvider());
                    // Set UeDataParams
                    EpcX2Sap::UeDataParams params;
                    params.sourceCellId = m_rrc->GetCellId();
                    params.targetCellId = m_mmWaveCellId;
                    params.gtpTeid = it->second->m_gtpTeid;
                    pdcp->SetUeDataParams(params);
                    pdcp->SetMmWaveRnti(mmWaveRnti);
                    // Setup TEIDs for receiving data eventually forwarded over X2-U
                    LteEnbRrc::X2uTeidInfo x2uTeidInfo;
                    x2uTeidInfo.rnti = m_rnti;
                    x2uTeidInfo.drbid = it->first;
                    std::pair<std::map<uint32_t, LteEnbRrc::X2uTeidInfo>::iterator, bool> ret;
                    ret = m_rrc->m_x2uMcTeidInfoMap.insert(
                        std::pair<uint32_t, LteEnbRrc::X2uTeidInfo>(it->second->m_gtpTeid,
                                                                    x2uTeidInfo));
                    // NS_ASSERT_MSG (ret.second == true, "overwriting a pre-existing entry in
                    // m_x2uMcTeidInfoMap"); Setup McEpcX2PdcpUser
                    m_rrc->m_x2SapProvider->SetEpcX2PdcpUser(it->second->m_gtpTeid,
                                                             pdcp->GetEpcX2PdcpUser());

                    // Create a remote RLC, pass along the UeDataParams + mmWaveRnti
                    EpcX2SapProvider::RlcSetupRequest rlcParams = it->second->m_rlcSetupRequest;
                    rlcParams.targetCellId = m_mmWaveCellId;
                    rlcParams.mmWaveRnti = mmWaveRnti;

                    m_rrc->m_x2SapProvider->SendRlcSetupRequest(rlcParams);
                }
                else
                {
                    NS_FATAL_ERROR("Trying to setup a MC device with a non MC capable PDCP");
                }
            }
            else
            {
                NS_LOG_INFO("MC Bearer already setup"); // TODO consider bearer modifications
            }
        }
    }
}

void
UeManager::RecvSecondaryCellHandoverCompleted(EpcX2Sap::SecondaryHandoverCompletedParams params)
{
    uint16_t oldMmWaveCellId = m_mmWaveCellId;
    m_mmWaveCellId = params.cellId;
    m_mmWaveRnti = params.mmWaveRnti;

    for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.begin();
         it != m_drbMap.end();
         ++it)
    {
        if (!(it->second->m_isMc) ||
            (it->second->m_isMc && m_rrc->m_lastMmWaveCell.find(m_imsi)->second != m_mmWaveCellId))
        {
            Ptr<McEnbPdcp> pdcp = DynamicCast<McEnbPdcp>(it->second->m_pdcp);
            if (pdcp)
            {
                // Updated UeDataParams in the PDCP instance
                EpcX2Sap::UeDataParams params;
                params.sourceCellId = m_rrc->GetCellId();
                params.targetCellId = m_mmWaveCellId;
                params.gtpTeid = it->second->m_gtpTeid;
                pdcp->SetUeDataParams(params);
                pdcp->SetMmWaveRnti(m_mmWaveRnti);
                // Update TEIDs for receiving data eventually forwarded over X2-U
                LteEnbRrc::X2uTeidInfo x2uTeidInfo;
                x2uTeidInfo.rnti = m_rnti;
                x2uTeidInfo.drbid = it->first;
                std::pair<std::map<uint32_t, LteEnbRrc::X2uTeidInfo>::iterator, bool> ret;
                ret = m_rrc->m_x2uMcTeidInfoMap.insert(
                    std::pair<uint32_t, LteEnbRrc::X2uTeidInfo>(it->second->m_gtpTeid,
                                                                x2uTeidInfo));
                // NS_ASSERT_MSG (ret.second == true, "overwriting a pre-existing entry in
                // m_x2uMcTeidInfoMap"); Setup McEpcX2PdcpUser
                m_rrc->m_x2SapProvider->SetEpcX2PdcpUser(it->second->m_gtpTeid,
                                                         pdcp->GetEpcX2PdcpUser());
                // Remote RLC already setup

                m_rrc->m_lastMmWaveCell[m_imsi] = m_mmWaveCellId;
                m_rrc->m_mmWaveCellSetupCompleted[m_imsi] = true;
                NS_LOG_INFO("Imsi " << m_imsi << " m_mmWaveCellSetupCompleted set to "
                                    << m_rrc->m_mmWaveCellSetupCompleted[m_imsi] << " for cell "
                                    << m_rrc->m_lastMmWaveCell[m_imsi]);
                m_rrc->m_imsiUsingLte[m_imsi] = false;

                pdcp->SwitchConnection(
                    true); // this is needed when an handover happens after coming back from outage
            }
            else
            {
                NS_FATAL_ERROR("Trying to update a MC device with a non MC capable PDCP");
            }
        }
        else
        {
            NS_LOG_INFO("No difference with the MC Bearer already defined"); // TODO consider bearer
                                                                             // modifications
        }
    }

    // send ContextRelease to the old mmWave eNB
    NS_LOG_INFO("Send UE CONTEXT RELEASE from target eNB to source eNB");
    EpcX2SapProvider::UeContextReleaseParams ueCtxReleaseParams;
    ueCtxReleaseParams.oldEnbUeX2apId = params.oldEnbUeX2apId;
    ueCtxReleaseParams.newEnbUeX2apId = m_mmWaveRnti;
    ueCtxReleaseParams.sourceCellId = oldMmWaveCellId;
    m_rrc->m_x2SapProvider->SendUeContextRelease(ueCtxReleaseParams);
}

void
UeManager::SendRrcConnectionSwitch(bool useMmWaveConnection)
{
    LteRrcSap::RrcConnectionSwitch msg;
    msg.rrcTransactionIdentifier = GetNewRrcTransactionIdentifier();
    std::vector<uint8_t> drbidVector;
    for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.begin();
         it != m_drbMap.end();
         ++it)
    {
        if (it->second->m_isMc)
        {
            drbidVector.push_back(it->first);
            Ptr<McEnbPdcp> pdcp = DynamicCast<McEnbPdcp>(it->second->m_pdcp);
            if (pdcp)
            {
                // m_rrc->m_x2SapProvider->
                pdcp->SwitchConnection(useMmWaveConnection);
                // forward packets in RLC buffers!
                // when a switch happens, the swicth target RETX and TXED buffers of RLC AM are
                // emptied, and the different windows are resetted. then the switch message is sent
                // and the RLC buffers are fed back to the pdpc
                if (!m_rrc->m_ismmWave && useMmWaveConnection) //
                {
                    NS_LOG_INFO("UeManager: forward LTE RLC buffers to mmWave");
                    ForwardRlcBuffers(it->second->m_rlc,
                                      it->second->m_pdcp,
                                      it->second->m_gtpTeid,
                                      1,
                                      0,
                                      it->first);
                    // create a new rlc instance!

                    // reset RLC and LC
                    it->second->m_rlc = 0;
                    uint8_t lcid = it->second->m_logicalChannelIdentity;
                    // TODO needs to be corrected
                    // m_rrc->m_cmacSapProvider.at(0)->ReleaseLc(m_rnti, lcid);
                    std::vector<uint8_t> ccToRelease =
                        m_rrc->m_ccmRrcSapProvider->ReleaseDataRadioBearer(m_rnti, lcid);
                    std::vector<uint8_t>::iterator itCcToRelease = ccToRelease.begin();
                    NS_ASSERT_MSG(itCcToRelease != ccToRelease.end(),
                                  "request to remove radio bearer with unknown drbid "
                                  "(ComponentCarrierManager)");
                    for (itCcToRelease = ccToRelease.begin(); itCcToRelease != ccToRelease.end();
                         ++itCcToRelease)
                    {
                        m_rrc->m_cmacSapProvider.at(*itCcToRelease)->ReleaseLc(m_rnti, lcid);
                    }

                    TypeId rlcTypeId = m_rrc->GetRlcType(it->second->m_epsBearer);

                    ObjectFactory rlcObjectFactory;
                    rlcObjectFactory.SetTypeId(rlcTypeId);
                    Ptr<LteRlc> rlc = rlcObjectFactory.Create()->GetObject<LteRlc>();
                    rlc->SetLteMacSapProvider(m_rrc->m_macSapProvider);
                    rlc->SetRnti(m_rnti);

                    it->second->m_rlc = rlc;

                    NS_LOG_INFO("Reset RLC in LTE eNB after switch, new rlc " << rlc);

                    rlc->SetLcId(lcid);

                    // we need PDCP only for real RLC, i.e., RLC/UM or RLC/AM
                    // if we are using RLC/SM we don't care of anything above RLC
                    if (rlcTypeId != LteRlcSm::GetTypeId())
                    {
                        DynamicCast<McEnbPdcp>(it->second->m_pdcp)
                            ->SetLteRlcSapProvider(rlc->GetLteRlcSapProvider());
                        rlc->SetLteRlcSapUser(
                            DynamicCast<McEnbPdcp>(it->second->m_pdcp)->GetLteRlcSapUser());
                    }

                    uint8_t drbid = it->first;
                    uint8_t bid = Drbid2Bid(drbid);

                    std::vector<LteCcmRrcSapProvider::LcsConfig> lcOnCcMapping =
                        m_rrc->m_ccmRrcSapProvider->SetupDataRadioBearer(
                            it->second->m_epsBearer,
                            bid,
                            m_rnti,
                            lcid,
                            m_rrc->GetLogicalChannelGroup(it->second->m_epsBearer),
                            rlc->GetLteMacSapUser());
                    // LteEnbCmacSapProvider::LcInfo lcinfo;
                    // lcinfo.rnti = m_rnti;
                    // lcinfo.lcId = lcid;
                    // lcinfo.lcGroup = m_rrc->GetLogicalChannelGroup (it->second->m_epsBearer);
                    // lcinfo.qci =   it->second->m_epsBearer.qci;
                    // lcinfo.isGbr = it->second->m_epsBearer.IsGbr ();
                    // lcinfo.mbrUl = it->second->m_epsBearer.gbrQosInfo.mbrUl;
                    // lcinfo.mbrDl = it->second->m_epsBearer.gbrQosInfo.mbrDl;
                    // lcinfo.gbrUl = it->second->m_epsBearer.gbrQosInfo.gbrUl;
                    // lcinfo.gbrDl = it->second->m_epsBearer.gbrQosInfo.gbrDl;
                    // TODO needs to be corrected
                    // m_rrc->m_cmacSapProvider.at(0)->AddLc (lcinfo, rlc->GetLteMacSapUser ());
                    std::vector<LteCcmRrcSapProvider::LcsConfig>::iterator itLcOnCcMapping =
                        lcOnCcMapping.begin();
                    NS_ASSERT_MSG(itLcOnCcMapping != lcOnCcMapping.end(), "Problem");
                    for (itLcOnCcMapping = lcOnCcMapping.begin();
                         itLcOnCcMapping != lcOnCcMapping.end();
                         ++itLcOnCcMapping)
                    {
                        NS_LOG_DEBUG(this << " RNTI " << itLcOnCcMapping->lc.rnti << "Lcid "
                                          << (uint16_t)itLcOnCcMapping->lc.lcId << " lcGroup "
                                          << (uint16_t)itLcOnCcMapping->lc.lcGroup
                                          << " ComponentCarrierId "
                                          << itLcOnCcMapping->componentCarrierId);
                        uint8_t index = itLcOnCcMapping->componentCarrierId;
                        LteEnbCmacSapProvider::LcInfo lcinfo = itLcOnCcMapping->lc;
                        LteMacSapUser* msu = itLcOnCcMapping->msu;
                        m_rrc->m_cmacSapProvider.at(index)->AddLc(lcinfo, msu);
                        m_rrc->m_ccmRrcSapProvider->AddLc(lcinfo, msu);
                    }
                }
                else if (!m_rrc->m_ismmWave && !useMmWaveConnection)
                {
                    // switch from mmWave to LTE: it will be the mmWave cell that forwards the data
                    // back to LTE
                    EpcX2SapProvider::SwitchConnectionParams params;
                    params.mmWaveRnti = m_mmWaveRnti;
                    params.mmWaveCellId = m_mmWaveCellId;
                    params.useMmWaveConnection = useMmWaveConnection;
                    params.drbid = it->first;
                    m_rrc->m_x2SapProvider->SendSwitchConnectionToMmWave(params);
                }
            }
            else
            {
                NS_FATAL_ERROR("A device defined as MC has not a McEnbPdcp");
            }
        }
    }
    msg.drbidList = drbidVector;
    msg.useMmWaveConnection = useMmWaveConnection;
    NS_LOG_INFO("SendRrcConnectionSwitch to " << m_rnti << " with useMmWaveConnection "
                                              << msg.useMmWaveConnection << " at time "
                                              << Simulator::Now().GetSeconds());
    m_rrc->m_rrcSapUser->SendRrcConnectionSwitch(m_rnti, msg);
}

void
UeManager::RecvConnectionSwitchToMmWave(bool useMmWaveConnection, uint8_t drbid)
{
    NS_ASSERT_MSG(m_rlcMap.find(drbid) != m_rlcMap.end(), "drbid not found in m_rlcMap");
    NS_LOG_INFO("RecvConnectionSwitchToMmWave on cell " << m_rrc->m_cellId << " switch "
                                                        << useMmWaveConnection << " for drbid "
                                                        << (uint32_t)drbid);
    if (!useMmWaveConnection)
    {
        // Ptr<RlcBearerInfo> rlcInfo = m_rlcMap.find(drbid)->second;
        m_targetCellId = m_rrc->m_lteCellId;
        ForwardRlcBuffers(m_rlcMap.find(drbid)->second->m_rlc,
                          0,
                          m_rlcMap.find(drbid)->second->gtpTeid,
                          0,
                          0,
                          0);
        // create a new rlc!

        m_rlcMap.find(drbid)->second->m_rlc = 0;

        uint8_t lcid = m_rlcMap.find(drbid)->second->logicalChannelIdentity;
        // TODO needs to be corrected
        // m_rrc->m_cmacSapProvider.at(0)->ReleaseLc(m_rnti, lcid);
        std::vector<uint8_t> ccToRelease =
            m_rrc->m_ccmRrcSapProvider->ReleaseDataRadioBearer(m_rnti, lcid);
        std::vector<uint8_t>::iterator itCcToRelease = ccToRelease.begin();
        NS_ASSERT_MSG(
            itCcToRelease != ccToRelease.end(),
            "request to remove radio bearer with unknown drbid (ComponentCarrierManager)");
        for (itCcToRelease = ccToRelease.begin(); itCcToRelease != ccToRelease.end();
             ++itCcToRelease)
        {
            m_rrc->m_cmacSapProvider.at(*itCcToRelease)->ReleaseLc(m_rnti, lcid);
        }

        EpsBearer bearer;
        TypeId rlcTypeId = m_rrc->GetRlcType(bearer); // actually, this doesn't depend on bearer

        ObjectFactory rlcObjectFactory;
        rlcObjectFactory.SetTypeId(rlcTypeId);
        Ptr<LteRlc> rlc = rlcObjectFactory.Create()->GetObject<LteRlc>();
        NS_LOG_INFO("Reset rlc in mmWave after switch to LTE " << rlc);
        rlc->SetLteMacSapProvider(m_rrc->m_macSapProvider);
        rlc->SetRnti(m_rnti);

        m_rlcMap.find(drbid)->second->m_rlc = rlc;
        rlc->SetLcId(lcid);

        if (rlcTypeId != LteRlcSm::GetTypeId())
        {
            // connect with remote PDCP
            rlc->SetEpcX2RlcProvider(m_rrc->GetEpcX2RlcProvider());
            EpcX2Sap::UeDataParams ueParams;
            ueParams.sourceCellId = m_rrc->GetCellId();
            ueParams.targetCellId = m_rlcMap.find(drbid)->second->targetCellId; // the LTE cell
            ueParams.gtpTeid = m_rlcMap.find(drbid)->second->gtpTeid;
            rlc->SetUeDataParams(ueParams);
            m_rrc->m_x2SapProvider->SetEpcX2RlcUser(m_rlcMap.find(drbid)->second->gtpTeid,
                                                    rlc->GetEpcX2RlcUser());
        }
        // TODO needs to be corrected
        // m_rrc->m_cmacSapProvider.at(0)->AddLc (m_rlcMap.find(drbid)->second->lcinfo,
        // rlc->GetLteMacSapUser ());

        std::vector<LteCcmRrcSapProvider::LcsConfig> lcOnCcMapping =
            m_rrc->m_ccmRrcSapProvider->SetupDataRadioBearer(bearer,
                                                             Drbid2Bid(drbid),
                                                             m_rnti,
                                                             lcid,
                                                             m_rrc->GetLogicalChannelGroup(bearer),
                                                             rlc->GetLteMacSapUser());

        std::vector<LteCcmRrcSapProvider::LcsConfig>::iterator itLcOnCcMapping =
            lcOnCcMapping.begin();
        NS_ASSERT_MSG(itLcOnCcMapping != lcOnCcMapping.end(), "Problem");
        for (itLcOnCcMapping = lcOnCcMapping.begin(); itLcOnCcMapping != lcOnCcMapping.end();
             ++itLcOnCcMapping)
        {
            NS_LOG_DEBUG(this << " RNTI " << itLcOnCcMapping->lc.rnti << "Lcid "
                              << (uint16_t)itLcOnCcMapping->lc.lcId << " lcGroup "
                              << (uint16_t)itLcOnCcMapping->lc.lcGroup << " ComponentCarrierId "
                              << itLcOnCcMapping->componentCarrierId);
            uint8_t index = itLcOnCcMapping->componentCarrierId;
            LteEnbCmacSapProvider::LcInfo lcinfo = itLcOnCcMapping->lc;
            LteMacSapUser* msu = itLcOnCcMapping->msu;
            m_rrc->m_cmacSapProvider.at(index)->AddLc(lcinfo, msu);
            m_rrc->m_ccmRrcSapProvider->AddLc(lcinfo, msu);
        }
    }
}

// methods forwarded from CMAC SAP

void
UeManager::CmacUeConfigUpdateInd(LteEnbCmacSapUser::UeConfig cmacParams)
{
    NS_LOG_FUNCTION(this << m_rnti);
    // at this stage used only by the scheduler for updating txMode

    m_physicalConfigDedicated.antennaInfo.transmissionMode = cmacParams.m_transmissionMode;

    m_needPhyMacConfiguration = true;

    // reconfigure the UE RRC
    ScheduleRrcConnectionReconfiguration();
}

// methods forwarded from PDCP SAP

void
UeManager::DoReceivePdcpSdu(LtePdcpSapUser::ReceivePdcpSduParameters params)
{
    NS_LOG_FUNCTION(this);
    if (params.lcid > 2)
    {
        // data radio bearer
        EpsBearerTag tag;
        tag.SetRnti(params.rnti);
        tag.SetBid(Lcid2Bid(params.lcid));
        params.pdcpSdu->AddPacketTag(tag);
        m_rrc->m_forwardUpCallback(params.pdcpSdu);
    }
}

uint16_t
UeManager::GetRnti(void) const
{
    return m_rnti;
}

uint64_t
UeManager::GetImsi(void) const
{
    return m_imsi;
}

uint8_t
UeManager::GetComponentCarrierId() const
{
    return m_componentCarrierId;
}

uint16_t
UeManager::GetSrsConfigurationIndex(void) const
{
    return m_physicalConfigDedicated.soundingRsUlConfigDedicated.srsConfigIndex;
}

void
UeManager::SetSrsConfigurationIndex(uint16_t srsConfIndex)
{
    NS_LOG_FUNCTION(this);
    m_physicalConfigDedicated.soundingRsUlConfigDedicated.srsConfigIndex = srsConfIndex;
    for (uint16_t i = 0; i < m_rrc->m_numberOfComponentCarriers; i++)
    {
        m_rrc->m_cphySapProvider.at(i)->SetSrsConfigurationIndex(m_rnti, srsConfIndex);
    }
    switch (m_state)
    {
    case INITIAL_RANDOM_ACCESS:
        // do nothing, srs conf index will be correctly enforced upon
        // RRC connection establishment
        break;

    default:
        ScheduleRrcConnectionReconfiguration();
        break;
    }
}

UeManager::State
UeManager::GetState(void) const
{
    return m_state;
}

void
UeManager::SetPdschConfigDedicated(LteRrcSap::PdschConfigDedicated pdschConfigDedicated)
{
    NS_LOG_FUNCTION(this);
    m_physicalConfigDedicated.pdschConfigDedicated = pdschConfigDedicated;

    m_needPhyMacConfiguration = true;

    // reconfigure the UE RRC
    ScheduleRrcConnectionReconfiguration();
}

uint8_t
UeManager::AddDataRadioBearerInfo(Ptr<LteDataRadioBearerInfo> drbInfo)
{
    NS_LOG_FUNCTION(this);
    const uint8_t MAX_DRB_ID = 32;
    for (int drbid = (m_lastAllocatedDrbid + 1) % MAX_DRB_ID; drbid != m_lastAllocatedDrbid;
         drbid = (drbid + 1) % MAX_DRB_ID)
    {
        if (drbid != 0) // 0 is not allowed
        {
            if (m_drbMap.find(drbid) == m_drbMap.end())
            {
                m_drbMap.insert(std::pair<uint8_t, Ptr<LteDataRadioBearerInfo>>(drbid, drbInfo));
                drbInfo->m_drbIdentity = drbid;
                m_lastAllocatedDrbid = drbid;
                return drbid;
            }
        }
    }
    NS_FATAL_ERROR("no more data radio bearer ids available");
    return 0;
}

Ptr<LteDataRadioBearerInfo>
UeManager::GetDataRadioBearerInfo(uint8_t drbid)
{
    NS_LOG_FUNCTION(this << (uint32_t)drbid);
    NS_ASSERT(0 != drbid);
    std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.find(drbid);
    NS_ABORT_IF(it == m_drbMap.end());
    return it->second;
}

void
UeManager::RemoveDataRadioBearerInfo(uint8_t drbid)
{
    NS_LOG_FUNCTION(this << (uint32_t)drbid);
    std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.find(drbid);
    NS_ASSERT_MSG(it != m_drbMap.end(),
                  "request to remove radio bearer with unknown drbid " << drbid);
    m_drbMap.erase(it);
}

LteRrcSap::RrcConnectionReconfiguration
UeManager::BuildRrcConnectionReconfiguration()
{
    NS_LOG_FUNCTION(this);
    LteRrcSap::RrcConnectionReconfiguration msg;
    msg.rrcTransactionIdentifier = GetNewRrcTransactionIdentifier();
    msg.haveRadioResourceConfigDedicated = true;
    msg.radioResourceConfigDedicated = BuildRadioResourceConfigDedicated();
    msg.haveMobilityControlInfo = false;
    msg.haveMeasConfig = true;
    msg.measConfig = m_rrc->m_ueMeasConfig;
    if (m_caSupportConfigured == false && m_rrc->m_numberOfComponentCarriers > 1)
    {
        m_caSupportConfigured = true;
        NS_LOG_FUNCTION(this << "CA not configured. Configure now!");
        msg.haveNonCriticalExtension = true;
        msg.nonCriticalExtension = BuildNonCriticalExtentionConfigurationCa();
        NS_LOG_FUNCTION(this << " haveNonCriticalExtension " << msg.haveNonCriticalExtension);
    }
    else
    {
        msg.haveNonCriticalExtension = false;
    }

    return msg;
}

LteRrcSap::RadioResourceConfigDedicated
UeManager::BuildRadioResourceConfigDedicated()
{
    NS_LOG_FUNCTION(this);
    LteRrcSap::RadioResourceConfigDedicated rrcd;

    if (m_srb1)
    {
        LteRrcSap::SrbToAddMod stam;
        stam.srbIdentity = m_srb1->m_srbIdentity;
        stam.logicalChannelConfig = m_srb1->m_logicalChannelConfig;
        rrcd.srbToAddModList.push_back(stam);
    }

    for (std::map<uint8_t, Ptr<LteDataRadioBearerInfo>>::iterator it = m_drbMap.begin();
         it != m_drbMap.end();
         ++it)
    {
        LteRrcSap::DrbToAddMod dtam;
        dtam.epsBearerIdentity = it->second->m_epsBearerIdentity;
        dtam.drbIdentity = it->second->m_drbIdentity;
        dtam.rlcConfig = it->second->m_rlcConfig;
        dtam.logicalChannelIdentity = it->second->m_logicalChannelIdentity;
        dtam.logicalChannelConfig = it->second->m_logicalChannelConfig;
        dtam.is_mc = it->second->m_isMc;
        rrcd.drbToAddModList.push_back(dtam);
    }

    if (m_drbMap.size() == 0 && m_isMc &&
        m_rrc->m_ismmWave) // UeManager on a secondary cell for a MC device
    {
        for (std::map<uint8_t, Ptr<RlcBearerInfo>>::iterator it = m_rlcMap.begin();
             it != m_rlcMap.end();
             ++it)
        {
            LteRrcSap::DrbToAddMod dtam;
            dtam.epsBearerIdentity = Drbid2Bid(it->second->drbid);
            dtam.drbIdentity = it->second->drbid;
            dtam.rlcConfig = it->second->rlcConfig;
            dtam.logicalChannelIdentity = it->second->logicalChannelIdentity;
            dtam.logicalChannelConfig = it->second->logicalChannelConfig;
            dtam.is_mc = true;
            rrcd.drbToAddModList.push_back(dtam);
        }
    }

    rrcd.havePhysicalConfigDedicated = true;
    rrcd.physicalConfigDedicated = m_physicalConfigDedicated;
    return rrcd;
}

uint8_t
UeManager::GetNewRrcTransactionIdentifier()
{
    NS_LOG_FUNCTION(this);
    ++m_lastRrcTransactionIdentifier;
    m_lastRrcTransactionIdentifier %= 4;
    return m_lastRrcTransactionIdentifier;
}

uint8_t
UeManager::Lcid2Drbid(uint8_t lcid)
{
    NS_ASSERT(lcid > 2);
    return lcid - 2;
}

uint8_t
UeManager::Drbid2Lcid(uint8_t drbid)
{
    return drbid + 2;
}

uint8_t
UeManager::Lcid2Bid(uint8_t lcid)
{
    NS_ASSERT(lcid > 2);
    return lcid - 2;
}

uint8_t
UeManager::Bid2Lcid(uint8_t bid)
{
    return bid + 2;
}

uint8_t
UeManager::Drbid2Bid(uint8_t drbid)
{
    return drbid;
}

uint8_t
UeManager::Bid2Drbid(uint8_t bid)
{
    return bid;
}

void
UeManager::SwitchToState(State newState)
{
    NS_LOG_FUNCTION(this << ToString(newState));
    State oldState = m_state;
    m_state = newState;
    NS_LOG_INFO(this << " IMSI " << m_imsi << " RNTI " << m_rnti << " UeManager "
                     << ToString(oldState) << " --> " << ToString(newState));
    m_stateTransitionTrace(m_imsi,
                           m_rrc->ComponentCarrierToCellId(m_componentCarrierId),
                           m_rnti,
                           oldState,
                           newState);

    switch (newState)
    {
    case INITIAL_RANDOM_ACCESS:
    case HANDOVER_JOINING:
        NS_FATAL_ERROR("cannot switch to an initial state");
        break;

    case CONNECTION_SETUP:
        break;

    case CONNECTED_NORMALLY: {
        if (m_caSupportConfigured == true && m_pendingConnectToMmWave == true)
        {
            // the CA setup is completed. Now we have to connect the UE to the
            // best mmWave eNB

            m_pendingConnectToMmWave = false;
            NS_LOG_INFO("Send connect to mmwave");
            // reply to the UE with a command to connect to the best MmWave eNB
            if (m_rrc->m_bestMmWaveCellForImsiMap.find(m_imsi) !=
                m_rrc->m_bestMmWaveCellForImsiMap.end())
            {
                if (m_rrc->m_bestMmWaveCellForImsiMap.at(m_imsi) != m_rrc->GetCellId() &&
                    !m_rrc->m_ismmWave)
                {
                    uint16_t maxSinrCellId = m_rrc->m_bestMmWaveCellForImsiMap.at(m_imsi);
                    // get the SINR
                    double maxSinrDb = 10 * std::log10(m_rrc->m_imsiCellSinrMap.find(m_imsi)
                                                           ->second.find(maxSinrCellId)
                                                           ->second);
                    if (maxSinrDb > m_rrc->m_outageThreshold)
                    {
                        // there is a MmWave cell to which the UE can connect
                        // send the connection message, then, if capable, the UE will connect
                        NS_LOG_INFO("Send connect to "
                                    << m_rrc->m_bestMmWaveCellForImsiMap.find(m_imsi)->second
                                    << " at least one mmWave eNB is not in outage");
                        m_rrc->m_rrcSapUser->SendRrcConnectToMmWave(
                            m_rnti,
                            m_rrc->m_bestMmWaveCellForImsiMap.find(m_imsi)->second);
                    }
                    else
                    {
                        // TODO
                        m_allMmWaveInOutageAtInitialAccess = true;
                        m_rrc->m_imsiUsingLte[m_imsi] = true;
                    }
                }
            }
        }
        if (m_pendingRrcConnectionReconfiguration == true)
        {
            ScheduleRrcConnectionReconfiguration();
        }
        if (m_pendingStartDataRadioBearers == true && m_caSupportConfigured == true)
        {
            StartDataRadioBearers();
        }
    }
    break;

    case CONNECTION_RECONFIGURATION:
        break;

    case CONNECTION_REESTABLISHMENT:
        break;

    case HANDOVER_LEAVING:
        break;

    default:
        break;
    }
}

void
UeManager::SetFirstConnection()
{
    m_firstConnection = true;
}

void
UeManager::RecvNotifyLteMmWaveHandoverCompleted()
{
    NS_LOG_FUNCTION(this << m_state);

    switch (m_state)
    {
    case CONNECTED_NORMALLY:
        m_rrc->m_mmWaveCellSetupCompleted.find(m_imsi)->second = true;
        NS_LOG_DEBUG("RecvNotifyLteMmWaveHandoverCompleted imsi "
                     << m_imsi << " m_rrc->m_mmWaveCellSetupCompleted[m_imsi] "
                     << m_rrc->m_mmWaveCellSetupCompleted[m_imsi]);
        m_rrc->m_imsiUsingLte.find(m_imsi)->second = true;
        break;
    default:
        m_receivedLteMmWaveHandoverCompleted = true;
        break;
    }
}

LteRrcSap::NonCriticalExtensionConfiguration
UeManager::BuildNonCriticalExtentionConfigurationCa()
{
    NS_LOG_FUNCTION(this);
    LteRrcSap::NonCriticalExtensionConfiguration ncec;

    //  LteRrcSap::SCellToAddMod scell;
    std::list<LteRrcSap::SCellToAddMod> SccCon;

    // sCellToReleaseList is always empty since no Scc is released

    if (!m_rrc->m_ismmWave)
    {
        for (auto& it : m_rrc->m_componentCarrierPhyConf)
        {
            uint8_t ccId = it.first;

            if (ccId == m_componentCarrierId)
            {
                // Skip primary CC.
                continue;
            }
            else if (ccId < m_componentCarrierId)
            {
                // Shift all IDs below PCC forward so PCC can use CC ID 1.
                ccId++;
            }

            Ptr<ComponentCarrierEnb> eNbCcm = it.second;
            LteRrcSap::SCellToAddMod component;
            component.sCellIndex = ccId;
            component.cellIdentification.physCellId = eNbCcm->GetCellId();
            component.cellIdentification.dlCarrierFreq = eNbCcm->GetDlEarfcn();
            component.radioResourceConfigCommonSCell.haveNonUlConfiguration = true;
            component.radioResourceConfigCommonSCell.nonUlConfiguration.dlBandwidth =
                eNbCcm->GetDlBandwidth();
            component.radioResourceConfigCommonSCell.nonUlConfiguration.antennaInfoCommon
                .antennaPortsCount = 0;
            component.radioResourceConfigCommonSCell.nonUlConfiguration.pdschConfigCommon
                .referenceSignalPower = m_rrc->m_cphySapProvider.at(0)->GetReferenceSignalPower();
            component.radioResourceConfigCommonSCell.nonUlConfiguration.pdschConfigCommon.pb = 0;
            component.radioResourceConfigCommonSCell.haveUlConfiguration = true;
            component.radioResourceConfigCommonSCell.ulConfiguration.ulFreqInfo.ulCarrierFreq =
                eNbCcm->GetUlEarfcn();
            component.radioResourceConfigCommonSCell.ulConfiguration.ulFreqInfo.ulBandwidth =
                eNbCcm->GetUlBandwidth();
            component.radioResourceConfigCommonSCell.ulConfiguration.ulPowerControlCommonSCell
                .alpha = 0;
            // component.radioResourceConfigCommonSCell.ulConfiguration.soundingRsUlConfigCommon.type
            // = LteRrcSap::SoundingRsUlConfigDedicated::SETUP;
            component.radioResourceConfigCommonSCell.ulConfiguration.soundingRsUlConfigCommon
                .srsBandwidthConfig = 0;
            component.radioResourceConfigCommonSCell.ulConfiguration.soundingRsUlConfigCommon
                .srsSubframeConfig = 0;
            component.radioResourceConfigCommonSCell.ulConfiguration.prachConfigSCell.index = 0;

            if (true)
            {
                component.haveRadioResourceConfigDedicatedSCell = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveNonUlConfiguration = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveAntennaInfoDedicated = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell.antennaInfo
                    .transmissionMode = m_rrc->m_defaultTransmissionMode;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .crossCarrierSchedulingConfig = false;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .havePdschConfigDedicated = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .pdschConfigDedicated.pa = LteRrcSap::PdschConfigDedicated::dB0;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveUlConfiguration = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveAntennaInfoUlDedicated = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .antennaInfoUl.transmissionMode = m_rrc->m_defaultTransmissionMode;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .pushConfigDedicatedSCell.nPuschIdentity = 0;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .ulPowerControlDedicatedSCell.pSrsOffset = 0;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveSoundingRsUlConfigDedicated = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .soundingRsUlConfigDedicated.srsConfigIndex = GetSrsConfigurationIndex();
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .soundingRsUlConfigDedicated.type =
                    LteRrcSap::SoundingRsUlConfigDedicated::SETUP;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .soundingRsUlConfigDedicated.srsBandwidth = 0;
            }
            else
            {
                component.haveRadioResourceConfigDedicatedSCell = false;
            }
            SccCon.push_back(component);
        }
    }
    else
    {
        for (auto& it : m_rrc->m_mmWaveComponentCarrierPhyConf)
        {
            uint8_t ccId = it.first;

            if (ccId == m_componentCarrierId)
            {
                // Skip primary CC.
                continue;
            }
            else if (ccId < m_componentCarrierId)
            {
                // Shift all IDs below PCC forward so PCC can use CC ID 1.
                ccId++;
            }

            LteEnbRrc::MmWaveComponentCarrierConf eNbCcm = it.second;
            LteRrcSap::SCellToAddMod component;
            component.sCellIndex = ccId;
            component.cellIdentification.physCellId = eNbCcm.m_cellId;
            // component.cellIdentification.dlCarrierFreq = eNbCcm->GetDlEarfcn ();
            component.radioResourceConfigCommonSCell.haveNonUlConfiguration = true;
            component.radioResourceConfigCommonSCell.nonUlConfiguration.dlBandwidth =
                eNbCcm.m_bandwidth;
            component.radioResourceConfigCommonSCell.nonUlConfiguration.antennaInfoCommon
                .antennaPortsCount = 0;
            component.radioResourceConfigCommonSCell.nonUlConfiguration.pdschConfigCommon
                .referenceSignalPower = m_rrc->m_cphySapProvider.at(0)->GetReferenceSignalPower();
            component.radioResourceConfigCommonSCell.nonUlConfiguration.pdschConfigCommon.pb = 0;
            component.radioResourceConfigCommonSCell.haveUlConfiguration = true;
            // component.radioResourceConfigCommonSCell.ulConfiguration.ulFreqInfo.ulCarrierFreq =
            // eNbCcm->GetUlEarfcn ();
            component.radioResourceConfigCommonSCell.ulConfiguration.ulFreqInfo.ulBandwidth =
                eNbCcm.m_bandwidth;
            component.radioResourceConfigCommonSCell.ulConfiguration.ulPowerControlCommonSCell
                .alpha = 0;
            // component.radioResourceConfigCommonSCell.ulConfiguration.soundingRsUlConfigCommon.type
            // = LteRrcSap::SoundingRsUlConfigDedicated::SETUP;
            component.radioResourceConfigCommonSCell.ulConfiguration.soundingRsUlConfigCommon
                .srsBandwidthConfig = 0;
            component.radioResourceConfigCommonSCell.ulConfiguration.soundingRsUlConfigCommon
                .srsSubframeConfig = 0;
            component.radioResourceConfigCommonSCell.ulConfiguration.prachConfigSCell.index = 0;

            if (true)
            {
                component.haveRadioResourceConfigDedicatedSCell = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveNonUlConfiguration = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveAntennaInfoDedicated = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell.antennaInfo
                    .transmissionMode = m_rrc->m_defaultTransmissionMode;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .crossCarrierSchedulingConfig = false;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .havePdschConfigDedicated = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .pdschConfigDedicated.pa = LteRrcSap::PdschConfigDedicated::dB0;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveUlConfiguration = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveAntennaInfoUlDedicated = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .antennaInfoUl.transmissionMode = m_rrc->m_defaultTransmissionMode;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .pushConfigDedicatedSCell.nPuschIdentity = 0;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .ulPowerControlDedicatedSCell.pSrsOffset = 0;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .haveSoundingRsUlConfigDedicated = true;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .soundingRsUlConfigDedicated.srsConfigIndex = GetSrsConfigurationIndex();
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .soundingRsUlConfigDedicated.type =
                    LteRrcSap::SoundingRsUlConfigDedicated::SETUP;
                component.radioResourceConfigDedicateSCell.physicalConfigDedicatedSCell
                    .soundingRsUlConfigDedicated.srsBandwidth = 0;
            }
            else
            {
                component.haveRadioResourceConfigDedicatedSCell = false;
            }
            SccCon.push_back(component);
        }
    }

    ncec.sCellsToAddModList = SccCon;

    return ncec;
}

///////////////////////////////////////////
// eNB RRC methods
///////////////////////////////////////////

NS_OBJECT_ENSURE_REGISTERED(LteEnbRrc);

LteEnbRrc::LteEnbRrc()
    : m_x2SapProvider(0),
      m_cmacSapProvider(0),
      m_handoverManagementSapProvider(0),
      m_ccmRrcSapProvider(0),
      m_anrSapProvider(0),
      m_ffrRrcSapProvider(0),
      m_rrcSapUser(0),
      m_macSapProvider(0),
      m_s1SapProvider(0),
      m_cphySapProvider(0),
      m_configured(false),
      m_lastAllocatedRnti(0),
      m_srsCurrentPeriodicityId(0),
      m_lastAllocatedConfigurationIndex(0),
      m_reconfigureUes(false),
      m_firstSibTime(16),
      m_numNewSinrReports(0),
      m_numberOfComponentCarriers(0),
      m_carriersConfigured(false)
{
    NS_LOG_FUNCTION(this);
    m_cmacSapUser.push_back(new EnbRrcMemberLteEnbCmacSapUser(this, 0));
    m_handoverManagementSapUser = new MemberLteHandoverManagementSapUser<LteEnbRrc>(this);
    m_anrSapUser = new MemberLteAnrSapUser<LteEnbRrc>(this);
    m_ffrRrcSapUser.push_back(new MemberLteFfrRrcSapUser<LteEnbRrc>(this));
    m_rrcSapProvider = new MemberLteEnbRrcSapProvider<LteEnbRrc>(this);
    m_x2SapUser = new EpcX2SpecificEpcX2SapUser<LteEnbRrc>(this);
    m_s1SapUser = new MemberEpcEnbS1SapUser<LteEnbRrc>(this);
    m_cphySapUser.push_back(new MemberLteEnbCphySapUser<LteEnbRrc>(this));

    m_imsiCellSinrMap.clear();
    m_x2_received_cnt = 0;
    m_switchEnabled = true;
    m_lteCellId = 0;

    m_ccmRrcSapUser = new MemberLteCcmRrcSapUser<LteEnbRrc>(this);
    m_cphySapProvider.push_back(0);
    m_cmacSapProvider.push_back(0);
    m_ffrRrcSapProvider.push_back(0);
}

void
LteEnbRrc::ConfigureCarriers(std::map<uint8_t, Ptr<ComponentCarrierEnb>> ccPhyConf)
{
    NS_ASSERT_MSG(!m_carriersConfigured, "Secondary carriers can be configured only once.");
    m_componentCarrierPhyConf = ccPhyConf;
    NS_ABORT_MSG_IF(m_numberOfComponentCarriers != m_componentCarrierPhyConf.size(),
                    " Number of component carriers "
                    "are not equal to the number of he component carrier configuration provided");

    for (uint8_t i = 1; i < m_numberOfComponentCarriers; i++)
    {
        m_cphySapUser.push_back(new MemberLteEnbCphySapUser<LteEnbRrc>(this));
        m_cmacSapUser.push_back(new EnbRrcMemberLteEnbCmacSapUser(this, i));
        m_ffrRrcSapUser.push_back(new MemberLteFfrRrcSapUser<LteEnbRrc>(this));
        m_cphySapProvider.push_back(0);
        m_cmacSapProvider.push_back(0);
        m_ffrRrcSapProvider.push_back(0);
    }
    m_carriersConfigured = true;
    Object::DoInitialize();
}

void
LteEnbRrc::ConfigureMmWaveCarriers(
    std::map<uint8_t, LteEnbRrc::MmWaveComponentCarrierConf> ccPhyConf)
{
    NS_LOG_FUNCTION(this);
    // TODO do we need to duplicate all the CC paramenters to support mmwave carriers?
    NS_ASSERT_MSG(!m_carriersConfigured, "Secondary carriers can be configured only once.");
    m_mmWaveComponentCarrierPhyConf = ccPhyConf;
    m_numberOfComponentCarriers = ccPhyConf.size();

    NS_ASSERT(m_numberOfComponentCarriers >= MIN_NO_MMW_CC &&
              m_numberOfComponentCarriers <= MAX_NO_MMW_CC);

    for (uint8_t i = 1; i < m_numberOfComponentCarriers; i++)
    {
        m_cphySapUser.push_back(new MemberLteEnbCphySapUser<LteEnbRrc>(this));
        m_cmacSapUser.push_back(new EnbRrcMemberLteEnbCmacSapUser(this, i));
        // m_ffrRrcSapUser.push_back (new MemberLteFfrRrcSapUser<LteEnbRrc> (this));
        m_cphySapProvider.push_back(0);
        m_cmacSapProvider.push_back(0);
        // m_ffrRrcSapProvider.push_back (0);
    }
    m_carriersConfigured = true;
    Object::DoInitialize();
}

LteEnbRrc::~LteEnbRrc()
{
    NS_LOG_FUNCTION(this);
}

void
LteEnbRrc::DoDispose()
{
    NS_LOG_FUNCTION(this);
    for (uint8_t i = 0; i < m_numberOfComponentCarriers; i++)
    {
        delete m_cphySapUser[i];
        delete m_cmacSapUser[i];

        // If this LteEnbRrc is part of a mmwave enb device, m_ffrRrcSapUser
        // contains one (dummy) element only, the one associated to the PCC which is
        // instantiated in the constructor.
        if (!(m_ismmWave == true && i > 0))
        {
            delete m_ffrRrcSapUser[i];
        }
    }
    // delete m_cphySapUser;
    m_cphySapUser.erase(m_cphySapUser.begin(), m_cphySapUser.end());
    m_cphySapUser.clear();
    // delete m_cmacSapUser;
    m_cmacSapUser.erase(m_cmacSapUser.begin(), m_cmacSapUser.end());
    m_cmacSapUser.clear();
    // delete m_ffrRrcSapUser;
    m_ffrRrcSapUser.erase(m_ffrRrcSapUser.begin(), m_ffrRrcSapUser.end());
    m_ffrRrcSapUser.clear();
    m_ueMap.clear();
    delete m_handoverManagementSapUser;
    delete m_ccmRrcSapUser;
    delete m_anrSapUser;
    delete m_rrcSapProvider;
    delete m_x2SapUser;
    delete m_s1SapUser;
}

TypeId
LteEnbRrc::GetTypeId(void)
{
    NS_LOG_FUNCTION("LteEnbRrc::GetTypeId");
    static TypeId tid =
        TypeId("ns3::LteEnbRrc")
            .SetParent<Object>()
            .SetGroupName("Lte")
            .AddConstructor<LteEnbRrc>()
            .AddAttribute("UeMap",
                          "List of UeManager by C-RNTI.",
                          ObjectMapValue(),
                          MakeObjectMapAccessor(&LteEnbRrc::m_ueMap),
                          MakeObjectMapChecker<UeManager>())
            .AddAttribute("DefaultTransmissionMode",
                          "The default UEs' transmission mode (0: SISO)",
                          UintegerValue(0), // default tx-mode
                          MakeUintegerAccessor(&LteEnbRrc::m_defaultTransmissionMode),
                          MakeUintegerChecker<uint8_t>())
            .AddAttribute("EpsBearerToRlcMapping",
                          "Specify which type of RLC will be used for each type of EPS bearer. ",
                          EnumValue(RLC_SM_ALWAYS),
                          MakeEnumAccessor(&LteEnbRrc::m_epsBearerToRlcMapping),
                          MakeEnumChecker(RLC_SM_ALWAYS,
                                          "RlcSmAlways",
                                          RLC_UM_ALWAYS,
                                          "RlcUmAlways",
                                          RLC_AM_ALWAYS,
                                          "RlcAmAlways",
                                          PER_BASED,
                                          "PacketErrorRateBased",
                                          RLC_UM_LOWLAT_ALWAYS,
                                          "MmwRlcUmAlways"))
            .AddAttribute("SystemInformationPeriodicity",
                          "The interval for sending system information (Time value)",
                          TimeValue(MilliSeconds(5)),
                          MakeTimeAccessor(&LteEnbRrc::m_systemInformationPeriodicity),
                          MakeTimeChecker())

            // SRS related attributes
            .AddAttribute(
                "SrsPeriodicity",
                "The SRS periodicity in milliseconds",
                UintegerValue(320),
                MakeUintegerAccessor(&LteEnbRrc::SetSrsPeriodicity, &LteEnbRrc::GetSrsPeriodicity),
                MakeUintegerChecker<uint32_t>())

            // Timeout related attributes
            .AddAttribute("ConnectionRequestTimeoutDuration",
                          "After a RA attempt, if no RRC CONNECTION REQUEST is "
                          "received before this time, the UE context is destroyed. "
                          "Must account for reception of RAR and transmission of "
                          "RRC CONNECTION REQUEST over UL GRANT.",
                          TimeValue(MilliSeconds(15)),
                          MakeTimeAccessor(&LteEnbRrc::m_connectionRequestTimeoutDuration),
                          MakeTimeChecker())
            .AddAttribute("ConnectionSetupTimeoutDuration",
                          "After accepting connection request, if no RRC CONNECTION "
                          "SETUP COMPLETE is received before this time, the UE "
                          "context is destroyed. Must account for the UE's reception "
                          "of RRC CONNECTION SETUP and transmission of RRC CONNECTION "
                          "SETUP COMPLETE.",
                          TimeValue(MilliSeconds(150)),
                          MakeTimeAccessor(&LteEnbRrc::m_connectionSetupTimeoutDuration),
                          MakeTimeChecker())
            .AddAttribute("ConnectionRejectedTimeoutDuration",
                          "Time to wait between sending a RRC CONNECTION REJECT and "
                          "destroying the UE context",
                          TimeValue(MilliSeconds(30)),
                          MakeTimeAccessor(&LteEnbRrc::m_connectionRejectedTimeoutDuration),
                          MakeTimeChecker())
            .AddAttribute("HandoverJoiningTimeoutDuration",
                          "After accepting a handover request, if no RRC CONNECTION "
                          "RECONFIGURATION COMPLETE is received before this time, the "
                          "UE context is destroyed. Must account for reception of "
                          "X2 HO REQ ACK by source eNB, transmission of the Handover "
                          "Command, non-contention-based random access and reception "
                          "of the RRC CONNECTION RECONFIGURATION COMPLETE message.",
                          TimeValue(Seconds(45)),
                          MakeTimeAccessor(&LteEnbRrc::m_handoverJoiningTimeoutDuration),
                          MakeTimeChecker())
            .AddAttribute("HandoverLeavingTimeoutDuration",
                          "After issuing a Handover Command, if neither RRC "
                          "CONNECTION RE-ESTABLISHMENT nor X2 UE Context Release has "
                          "been previously received, the UE context is destroyed.",
                          TimeValue(Seconds(45)),
                          MakeTimeAccessor(&LteEnbRrc::m_handoverLeavingTimeoutDuration),
                          MakeTimeChecker())
            .AddAttribute("OutageThreshold",
                          "SNR threshold for outage events [dB]",
                          DoubleValue(-5.0),
                          MakeDoubleAccessor(&LteEnbRrc::m_outageThreshold),
                          MakeDoubleChecker<long double>(-10000.0, 10.0))

            // Cell selection related attribute
            .AddAttribute("QRxLevMin",
                          "One of information transmitted within the SIB1 message, "
                          "indicating the required minimum RSRP level that any UE must "
                          "receive from this cell before it is allowed to camp to this "
                          "cell. The default value -70 corresponds to -140 dBm and is "
                          "the lowest possible value as defined by Section 6.3.4 of "
                          "3GPP TS 36.133. This restriction, however, only applies to "
                          "initial cell selection and EPC-enabled simulation.",
                          TypeId::ATTR_GET | TypeId::ATTR_CONSTRUCT,
                          IntegerValue(-70),
                          MakeIntegerAccessor(&LteEnbRrc::m_qRxLevMin),
                          MakeIntegerChecker<int8_t>(-70, -22))
            .AddAttribute("NumberOfComponentCarriers",
                          "Number of Component Carriers ",
                          UintegerValue(1),
                          MakeIntegerAccessor(&LteEnbRrc::m_numberOfComponentCarriers),
                          MakeIntegerChecker<int16_t>(MIN_NO_CC, MAX_NO_CC))

            // Handover related attributes
            .AddAttribute("AdmitHandoverRequest",
                          "Whether to admit an X2 handover request from another eNB",
                          BooleanValue(true),
                          MakeBooleanAccessor(&LteEnbRrc::m_admitHandoverRequest),
                          MakeBooleanChecker())
            .AddAttribute("AdmitRrcConnectionRequest",
                          "Whether to admit a connection request from a UE",
                          BooleanValue(true),
                          MakeBooleanAccessor(&LteEnbRrc::m_admitRrcConnectionRequest),
                          MakeBooleanChecker())

            // UE measurements related attributes
            .AddAttribute("RsrpFilterCoefficient",
                          "Determines the strength of smoothing effect induced by "
                          "layer 3 filtering of RSRP in all attached UE; "
                          "if set to 0, no layer 3 filtering is applicable",
                          // i.e. the variable k in 3GPP TS 36.331 section 5.5.3.2
                          UintegerValue(4),
                          MakeUintegerAccessor(&LteEnbRrc::m_rsrpFilterCoefficient),
                          MakeUintegerChecker<uint8_t>(0))
            .AddAttribute("RsrqFilterCoefficient",
                          "Determines the strength of smoothing effect induced by "
                          "layer 3 filtering of RSRQ in all attached UE; "
                          "if set to 0, no layer 3 filtering is applicable",
                          // i.e. the variable k in 3GPP TS 36.331 section 5.5.3.2
                          UintegerValue(4),
                          MakeUintegerAccessor(&LteEnbRrc::m_rsrqFilterCoefficient),
                          MakeUintegerChecker<uint8_t>(0))
            .AddAttribute("mmWaveDevice",
                          "Indicates whether RRC is for mmWave base station",
                          BooleanValue(false),
                          MakeBooleanAccessor(&LteEnbRrc::m_ismmWave),
                          MakeBooleanChecker())
            .AddAttribute("FirstSibTime",
                          "Time in ms of initial SIB message",
                          // i.e. the variable k in 3GPP TS 36.331 section 5.5.3.2
                          UintegerValue(2),
                          MakeUintegerAccessor(&LteEnbRrc::m_firstSibTime),
                          MakeUintegerChecker<uint32_t>(0))
            .AddAttribute("InterRatHoMode",
                          "Indicates whether RRC is for LTE base station that coordinates "
                          "InterRatHo among eNBs",
                          BooleanValue(false),
                          MakeBooleanAccessor(&LteEnbRrc::m_interRatHoMode),
                          MakeBooleanChecker())
            .AddAttribute("HoSinrDifference",
                          "The value for which an handover between MmWave eNB is triggered",
                          DoubleValue(3),
                          MakeDoubleAccessor(&LteEnbRrc::m_sinrThresholdDifference),
                          MakeDoubleChecker<double>())
            .AddAttribute("SecondaryCellHandoverMode",
                          "Select the secondary cell handover mode",
                          EnumValue(DYNAMIC_TTT),
                          MakeEnumAccessor(&LteEnbRrc::m_handoverMode),
                          MakeEnumChecker(FIXED_TTT,
                                          "FixedTtt",
                                          DYNAMIC_TTT,
                                          "DynamicTtt",
                                          THRESHOLD,
                                          "Threshold"))
            .AddAttribute("FixedTttValue",
                          "The value of TTT in case of fixed TTT handover (in ms)",
                          UintegerValue(110),
                          MakeUintegerAccessor(&LteEnbRrc::m_fixedTttValue),
                          MakeUintegerChecker<uint8_t>()) // TODO consider using a TimeValue
            .AddAttribute("MinDynTttValue",
                          "The minimum value of TTT in case of dynamic TTT handover (in ms)",
                          UintegerValue(25),
                          MakeUintegerAccessor(&LteEnbRrc::m_minDynTttValue),
                          MakeUintegerChecker<uint8_t>()) // TODO consider using a TimeValue
            .AddAttribute("MaxDynTttValue",
                          "The maximum value of TTT in case of dynamic TTT handover (in ms)",
                          UintegerValue(150),
                          MakeUintegerAccessor(&LteEnbRrc::m_maxDynTttValue),
                          MakeUintegerChecker<uint8_t>()) // TODO consider using a TimeValue
            .AddAttribute(
                "MinDiffValue",
                "The minimum value of the difference in case of dynamic TTT handover [dB]",
                DoubleValue(3),
                MakeDoubleAccessor(&LteEnbRrc::m_minDiffTttValue),
                MakeDoubleChecker<double>()) // TODO set the proper value
            .AddAttribute(
                "MaxDiffValue",
                "The maximum value of the difference in case of dynamic TTT handover [dB]",
                DoubleValue(20),
                MakeDoubleAccessor(&LteEnbRrc::m_maxDiffTttValue),
                MakeDoubleChecker<double>()) // TODO set the proper value
            .AddAttribute("CrtPeriod",
                          "The periodicity of a CRT (us)",
                          IntegerValue(1600),
                          MakeIntegerAccessor(&LteEnbRrc::m_crtPeriod),
                          MakeIntegerChecker<int>()) // TODO consider using a TimeValue
            .AddAttribute("ReportAllUeMeas",
                          "If true, the MmWave eNB sends to the LTE coordinator all the received "
                          "UE measures (one per CC). If false, it sends only the maximum measures",
                          BooleanValue(true),
                          MakeBooleanAccessor(&LteEnbRrc::m_reportAllUeMeas),
                          MakeBooleanChecker())
            // Trace sources
            .AddTraceSource("NewUeContext",
                            "Fired upon creation of a new UE context.",
                            MakeTraceSourceAccessor(&LteEnbRrc::m_newUeContextTrace),
                            "ns3::LteEnbRrc::NewUeContextTracedCallback")
            .AddTraceSource("ConnectionEstablished",
                            "Fired upon successful RRC connection establishment.",
                            MakeTraceSourceAccessor(&LteEnbRrc::m_connectionEstablishedTrace),
                            "ns3::LteEnbRrc::ConnectionHandoverTracedCallback")
            .AddTraceSource("ConnectionReconfiguration",
                            "trace fired upon RRC connection reconfiguration",
                            MakeTraceSourceAccessor(&LteEnbRrc::m_connectionReconfigurationTrace),
                            "ns3::LteEnbRrc::ConnectionHandoverTracedCallback")
            .AddTraceSource("HandoverStart",
                            "trace fired upon start of a handover procedure",
                            MakeTraceSourceAccessor(&LteEnbRrc::m_handoverStartTrace),
                            "ns3::LteEnbRrc::HandoverStartTracedCallback")
            .AddTraceSource("HandoverEndOk",
                            "trace fired upon successful termination of a handover procedure",
                            MakeTraceSourceAccessor(&LteEnbRrc::m_handoverEndOkTrace),
                            "ns3::LteEnbRrc::ConnectionHandoverTracedCallback")
            .AddTraceSource("RecvMeasurementReport",
                            "trace fired when measurement report is received",
                            MakeTraceSourceAccessor(&LteEnbRrc::m_recvMeasurementReportTrace),
                            "ns3::LteEnbRrc::ReceiveReportTracedCallback")
            .AddTraceSource("NotifyMmWaveSinr",
                            "trace fired when measurement report is received from mmWave cells, "
                            "for each cell, for each UE",
                            MakeTraceSourceAccessor(&LteEnbRrc::m_notifyMmWaveSinrTrace),
                            "ns3::LteEnbRrc::NotifyMmWaveSinrTracedCallback");
    return tid;
}

void
LteEnbRrc::SetEpcX2SapProvider(EpcX2SapProvider* s)
{
    NS_LOG_FUNCTION(this << s);
    m_x2SapProvider = s;
}

EpcX2SapUser*
LteEnbRrc::GetEpcX2SapUser()
{
    NS_LOG_FUNCTION(this);
    return m_x2SapUser;
}

void
LteEnbRrc::SetEpcX2PdcpProvider(EpcX2PdcpProvider* s)
{
    NS_LOG_FUNCTION(this << s);
    m_x2PdcpProvider = s;
}

void
LteEnbRrc::SetEpcX2RlcProvider(EpcX2RlcProvider* s)
{
    NS_LOG_FUNCTION(this << s);
    m_x2RlcProvider = s;
}

EpcX2PdcpProvider*
LteEnbRrc::GetEpcX2PdcpProvider() const
{
    return m_x2PdcpProvider;
}

EpcX2RlcProvider*
LteEnbRrc::GetEpcX2RlcProvider() const
{
    return m_x2RlcProvider;
}

void
LteEnbRrc::SetLteEnbCmacSapProvider(LteEnbCmacSapProvider* s)
{
    NS_LOG_FUNCTION(this << s);
    m_cmacSapProvider.at(0) = s;
}

void
LteEnbRrc::SetLteEnbCmacSapProvider(LteEnbCmacSapProvider* s, uint8_t pos)
{
    NS_LOG_FUNCTION(this << s);
    m_cmacSapProvider.at(pos) = s;
}

LteEnbCmacSapUser*
LteEnbRrc::GetLteEnbCmacSapUser()
{
    NS_LOG_FUNCTION(this);
    return m_cmacSapUser.at(0);
}

LteEnbCmacSapUser*
LteEnbRrc::GetLteEnbCmacSapUser(uint8_t pos)
{
    NS_LOG_FUNCTION(this);
    return m_cmacSapUser.at(pos);
}

void
LteEnbRrc::SetLteHandoverManagementSapProvider(LteHandoverManagementSapProvider* s)
{
    NS_LOG_FUNCTION(this << s);
    m_handoverManagementSapProvider = s;
}

LteHandoverManagementSapUser*
LteEnbRrc::GetLteHandoverManagementSapUser()
{
    NS_LOG_FUNCTION(this);
    return m_handoverManagementSapUser;
}

void
LteEnbRrc::SetLteCcmRrcSapProvider(LteCcmRrcSapProvider* s)
{
    NS_LOG_FUNCTION(this << s);
    m_ccmRrcSapProvider = s;
}

LteCcmRrcSapUser*
LteEnbRrc::GetLteCcmRrcSapUser()
{
    NS_LOG_FUNCTION(this);
    return m_ccmRrcSapUser;
}

void
LteEnbRrc::SetLteAnrSapProvider(LteAnrSapProvider* s)
{
    NS_LOG_FUNCTION(this << s);
    m_anrSapProvider = s;
}

LteAnrSapUser*
LteEnbRrc::GetLteAnrSapUser()
{
    NS_LOG_FUNCTION(this);
    return m_anrSapUser;
}

void
LteEnbRrc::SetLteFfrRrcSapProvider(LteFfrRrcSapProvider* s)
{
    NS_LOG_FUNCTION(this << s);
    m_ffrRrcSapProvider.at(0) = s;
}

void
LteEnbRrc::SetLteFfrRrcSapProvider(LteFfrRrcSapProvider* s, uint8_t index)
{
    NS_LOG_FUNCTION(this << s);
    m_ffrRrcSapProvider.at(index) = s;
}

LteFfrRrcSapUser*
LteEnbRrc::GetLteFfrRrcSapUser()
{
    NS_LOG_FUNCTION(this);
    return m_ffrRrcSapUser.at(0);
}

LteFfrRrcSapUser*
LteEnbRrc::GetLteFfrRrcSapUser(uint8_t index)
{
    NS_LOG_FUNCTION(this);
    NS_ASSERT_MSG(index < m_numberOfComponentCarriers,
                  "Invalid component carrier index:"
                      << index << " provided in order to obtain FfrRrcSapUser.");
    return m_ffrRrcSapUser.at(index);
}

void
LteEnbRrc::SetLteEnbRrcSapUser(LteEnbRrcSapUser* s)
{
    NS_LOG_FUNCTION(this << s);
    m_rrcSapUser = s;
}

LteEnbRrcSapProvider*
LteEnbRrc::GetLteEnbRrcSapProvider()
{
    NS_LOG_FUNCTION(this);
    return m_rrcSapProvider;
}

void
LteEnbRrc::SetLteMacSapProvider(LteMacSapProvider* s)
{
    NS_LOG_FUNCTION(this);
    m_macSapProvider = s;
}

void
LteEnbRrc::SetS1SapProvider(EpcEnbS1SapProvider* s)
{
    m_s1SapProvider = s;
}

EpcEnbS1SapUser*
LteEnbRrc::GetS1SapUser()
{
    return m_s1SapUser;
}

void
LteEnbRrc::SetLteEnbCphySapProvider(LteEnbCphySapProvider* s)
{
    NS_LOG_FUNCTION(this << s);
    m_cphySapProvider.at(0) = s;
}

LteEnbCphySapUser*
LteEnbRrc::GetLteEnbCphySapUser()
{
    NS_LOG_FUNCTION(this);
    return m_cphySapUser.at(0);
}

void
LteEnbRrc::SetLteEnbCphySapProvider(LteEnbCphySapProvider* s, uint8_t pos)
{
    NS_LOG_FUNCTION(this << s);
    m_cphySapProvider.at(pos) = s;
}

LteEnbCphySapUser*
LteEnbRrc::GetLteEnbCphySapUser(uint8_t pos)
{
    NS_LOG_FUNCTION(this);
    return m_cphySapUser.at(pos);
}

bool
LteEnbRrc::HasUeManager(uint16_t rnti) const
{
    NS_LOG_FUNCTION(this << (uint32_t)rnti);
    std::map<uint16_t, Ptr<UeManager>>::const_iterator it = m_ueMap.find(rnti);
    return (it != m_ueMap.end());
}

Ptr<UeManager>
LteEnbRrc::GetUeManager(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << (uint32_t)rnti);
    NS_ASSERT(0 != rnti);
    std::map<uint16_t, Ptr<UeManager>>::iterator it = m_ueMap.find(rnti);
    NS_ASSERT_MSG(it != m_ueMap.end(), "UE manager for RNTI " << rnti << " not found");
    return it->second;
}

void
LteEnbRrc::RegisterImsiToRnti(uint64_t imsi, uint16_t rnti)
{
    if (m_imsiRntiMap.find(imsi) == m_imsiRntiMap.end())
    {
        m_imsiRntiMap.insert(std::pair<uint64_t, uint16_t>(imsi, rnti));
        NS_LOG_INFO("New entry in m_imsiRntiMap, for rnti " << rnti << " m_interRatHoMode "
                                                            << m_interRatHoMode << " m_ismmWave "
                                                            << m_ismmWave);
        if (m_interRatHoMode) // warn the UeManager that this is the first time a UE with a certain
                              // imsi connects to this MmWave eNB. This will trigger a notification
                              // to the LTE RRC once RecvRrcReconfCompleted is called
        {
            GetUeManager(rnti)->SetFirstConnection();
        }
    }
    else
    {
        m_imsiRntiMap.find(imsi)->second = rnti;
    }

    if (m_rntiImsiMap.find(rnti) == m_rntiImsiMap.end())
    {
        m_rntiImsiMap.insert(std::pair<uint16_t, uint64_t>(rnti, imsi));
    }
    else
    {
        m_rntiImsiMap.find(rnti)->second = imsi;
    }
}

uint16_t
LteEnbRrc::GetRntiFromImsi(uint64_t imsi)
{
    if (m_imsiRntiMap.find(imsi) != m_imsiRntiMap.end())
    {
        return m_imsiRntiMap.find(imsi)->second;
    }
    else
    {
        return 0;
    }
}

uint64_t
LteEnbRrc::GetImsiFromRnti(uint16_t rnti)
{
    if (m_rntiImsiMap.find(rnti) != m_rntiImsiMap.end())
    {
        return m_rntiImsiMap.find(rnti)->second;
    }
    else
    {
        return 0;
    }
}

uint8_t
LteEnbRrc::AddUeMeasReportConfig(LteRrcSap::ReportConfigEutra config)
{
    NS_LOG_FUNCTION(this);

    // SANITY CHECK

    NS_ASSERT_MSG(
        m_ueMeasConfig.measIdToAddModList.size() == m_ueMeasConfig.reportConfigToAddModList.size(),
        "Measurement identities and reporting configuration should not have different quantity");

    if (Simulator::Now() != Seconds(0))
    {
        NS_FATAL_ERROR("AddUeMeasReportConfig may not be called after the simulation has run");
    }

    // INPUT VALIDATION

    switch (config.triggerQuantity)
    {
    case LteRrcSap::ReportConfigEutra::RSRP:
        if ((config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A5) &&
            (config.threshold2.choice != LteRrcSap::ThresholdEutra::THRESHOLD_RSRP))
        {
            NS_FATAL_ERROR(
                "The given triggerQuantity (RSRP) does not match with the given threshold2.choice");
        }

        if (((config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A1) ||
             (config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A2) ||
             (config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A4) ||
             (config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A5)) &&
            (config.threshold1.choice != LteRrcSap::ThresholdEutra::THRESHOLD_RSRP))
        {
            NS_FATAL_ERROR(
                "The given triggerQuantity (RSRP) does not match with the given threshold1.choice");
        }
        break;

    case LteRrcSap::ReportConfigEutra::RSRQ:
        if ((config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A5) &&
            (config.threshold2.choice != LteRrcSap::ThresholdEutra::THRESHOLD_RSRQ))
        {
            NS_FATAL_ERROR(
                "The given triggerQuantity (RSRQ) does not match with the given threshold2.choice");
        }

        if (((config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A1) ||
             (config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A2) ||
             (config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A4) ||
             (config.eventId == LteRrcSap::ReportConfigEutra::EVENT_A5)) &&
            (config.threshold1.choice != LteRrcSap::ThresholdEutra::THRESHOLD_RSRQ))
        {
            NS_FATAL_ERROR(
                "The given triggerQuantity (RSRQ) does not match with the given threshold1.choice");
        }
        break;

    default:
        NS_FATAL_ERROR("unsupported triggerQuantity");
        break;
    }

    if (config.purpose != LteRrcSap::ReportConfigEutra::REPORT_STRONGEST_CELLS)
    {
        NS_FATAL_ERROR("Only REPORT_STRONGEST_CELLS purpose is supported");
    }

    if (config.reportQuantity != LteRrcSap::ReportConfigEutra::BOTH)
    {
        NS_LOG_WARN("reportQuantity = BOTH will be used instead of the given reportQuantity");
    }

    uint8_t nextId = m_ueMeasConfig.reportConfigToAddModList.size() + 1;

    // create the reporting configuration
    LteRrcSap::ReportConfigToAddMod reportConfig;
    reportConfig.reportConfigId = nextId;
    reportConfig.reportConfigEutra = config;

    // create the measurement identity
    LteRrcSap::MeasIdToAddMod measId;
    measId.measId = nextId;
    measId.measObjectId = 1;
    measId.reportConfigId = nextId;

    // add both to the list of UE measurement configuration
    m_ueMeasConfig.reportConfigToAddModList.push_back(reportConfig);
    m_ueMeasConfig.measIdToAddModList.push_back(measId);

    return nextId;
}

void
LteEnbRrc::ConfigureCell(std::map<uint8_t, Ptr<ComponentCarrierEnb>> ccPhyConf)
{
    auto it = ccPhyConf.begin();
    NS_ASSERT(it != ccPhyConf.end());
    uint8_t ulBandwidth = it->second->GetUlBandwidth();
    uint8_t dlBandwidth = it->second->GetDlBandwidth();
    uint32_t ulEarfcn = it->second->GetUlEarfcn();
    uint32_t dlEarfcn = it->second->GetDlEarfcn();
    uint16_t cellId = it->second->GetCellId();
    NS_LOG_FUNCTION(this << cellId << (uint16_t)ulBandwidth << (uint16_t)dlBandwidth << ulEarfcn
                         << dlEarfcn);
    NS_ASSERT(!m_configured);

    for (const auto& it : ccPhyConf)
    {
        m_cphySapProvider.at(it.first)->SetBandwidth(it.second->GetUlBandwidth(),
                                                     it.second->GetDlBandwidth());
        m_cphySapProvider.at(it.first)->SetEarfcn(it.second->GetUlEarfcn(),
                                                  it.second->GetDlEarfcn());
        m_cphySapProvider.at(it.first)->SetCellId(it.second->GetCellId());
        m_cmacSapProvider.at(it.first)->ConfigureMac(it.second->GetUlBandwidth(),
                                                     it.second->GetDlBandwidth());
        m_ffrRrcSapProvider.at(it.first)->SetCellId(it.second->GetCellId());
        m_ffrRrcSapProvider.at(it.first)->SetBandwidth(it.second->GetUlBandwidth(),
                                                       it.second->GetDlBandwidth());
    }

    m_dlEarfcn = dlEarfcn;
    m_ulEarfcn = ulEarfcn;
    m_dlBandwidth = dlBandwidth;
    m_ulBandwidth = ulBandwidth;
    m_cellId = cellId; // RRC cellId is equal to the cellId of the primary carrier

    /*
     * Initializing the list of UE measurement configuration (m_ueMeasConfig).
     * Only intra-frequency measurements are supported, so only one measurement
     * object is created.
     */

    LteRrcSap::MeasObjectToAddMod measObject;
    measObject.measObjectId = 1;
    measObject.measObjectEutra.carrierFreq = m_dlEarfcn;
    measObject.measObjectEutra.allowedMeasBandwidth = m_dlBandwidth;
    measObject.measObjectEutra.presenceAntennaPort1 = false;
    measObject.measObjectEutra.neighCellConfig = 0;
    measObject.measObjectEutra.offsetFreq = 0;
    measObject.measObjectEutra.haveCellForWhichToReportCGI = false;

    m_ueMeasConfig.measObjectToAddModList.push_back(measObject);
    m_ueMeasConfig.haveQuantityConfig = true;
    m_ueMeasConfig.quantityConfig.filterCoefficientRSRP = m_rsrpFilterCoefficient;
    m_ueMeasConfig.quantityConfig.filterCoefficientRSRQ = m_rsrqFilterCoefficient;
    m_ueMeasConfig.haveMeasGapConfig = false;
    m_ueMeasConfig.haveSmeasure = false;
    m_ueMeasConfig.haveSpeedStatePars = false;

    m_sib1.clear();
    m_sib1.reserve(ccPhyConf.size());
    for (const auto& it : ccPhyConf)
    {
        // Enabling MIB transmission
        LteRrcSap::MasterInformationBlock mib;
        mib.dlBandwidth = it.second->GetDlBandwidth();
        mib.systemFrameNumber = 0;
        m_cphySapProvider.at(it.first)->SetMasterInformationBlock(mib);

        // Enabling SIB1 transmission with default values
        LteRrcSap::SystemInformationBlockType1 sib1;
        sib1.cellAccessRelatedInfo.cellIdentity = it.second->GetCellId();
        sib1.cellAccessRelatedInfo.csgIndication = false;
        sib1.cellAccessRelatedInfo.csgIdentity = 0;
        sib1.cellAccessRelatedInfo.plmnIdentityInfo.plmnIdentity = 0; // not used
        sib1.cellSelectionInfo.qQualMin = -34;          // not used, set as minimum value
        sib1.cellSelectionInfo.qRxLevMin = m_qRxLevMin; // set as minimum value
        m_sib1.push_back(sib1);
        m_cphySapProvider.at(it.first)->SetSystemInformationBlockType1(sib1);
    }
    /*
     * Enabling transmission of other SIB. The first time System Information is
     * transmitted is arbitrarily assumed to be at +0.016s, and then it will be
     * regularly transmitted every 80 ms by default (set the
     * SystemInformationPeriodicity attribute to configure this).
     */
    Simulator::Schedule(MilliSeconds(16), &LteEnbRrc::SendSystemInformation, this);
    m_imsiCellSinrMap.clear();
    m_firstReport = true;
    m_configured = true;
}

void
LteEnbRrc::ConfigureCell(std::map<uint8_t, MmWaveComponentCarrierConf> ccPhyConf)
{
    NS_LOG_FUNCTION(this);
    auto it = ccPhyConf.begin();
    NS_ASSERT(it != ccPhyConf.end());
    uint8_t bandwidth = it->second.m_bandwidth; // this information is not used
    // uint32_t earfcn = it->second->GetEarfcn ();
    uint16_t cellId = it->second.m_cellId;
    // NS_LOG_FUNCTION (this << (uint16_t) bandwidth << earfcn);
    NS_ASSERT(!m_configured);

    // m_dlEarfcn = earfcn;
    // m_ulEarfcn = earfcn;
    // m_dlBandwidth = bandwidth;
    // m_ulBandwidth = bandwidth;

    m_dlBandwidth =
        6; // this information is not used in case of mmwave dev, we set it to the default value
    m_ulBandwidth =
        6; // this information is not used in case of mmwave dev, we set it to the default value
    m_cellId = cellId; // RRC cellId is equal to the cellId of the primary carrier

    for (const auto& it : ccPhyConf)
    {
        bandwidth = it.second.m_bandwidth;
        m_cphySapProvider.at(it.first)->SetBandwidth(bandwidth, bandwidth);
        // earfcn = it.second->GetEarfcn ();
        // m_cphySapProvider.at (it.first)->SetEarfcn (earfcn, earfcn);
        m_cphySapProvider.at(it.first)->SetCellId(it.second.m_cellId);
        m_cmacSapProvider.at(it.first)->ConfigureMac(bandwidth, bandwidth);
        // m_ffrRrcSapProvider.at (it.first)->SetCellId (it.second->GetCellId ());
        // m_ffrRrcSapProvider.at (it.first)->SetBandwidth (bandwidth, bandwidth);
    }

    /*
     * Initializing the list of UE measurement configuration (m_ueMeasConfig).
     * Only intra-frequency measurements are supported, so only one measurement
     * object is created.
     */

    LteRrcSap::MeasObjectToAddMod measObject;
    measObject.measObjectId = 1;
    measObject.measObjectEutra.carrierFreq = m_dlEarfcn;
    measObject.measObjectEutra.allowedMeasBandwidth = m_dlBandwidth;
    measObject.measObjectEutra.presenceAntennaPort1 = false;
    measObject.measObjectEutra.neighCellConfig = 0;
    measObject.measObjectEutra.offsetFreq = 0;
    measObject.measObjectEutra.haveCellForWhichToReportCGI = false;

    m_ueMeasConfig.measObjectToAddModList.push_back(measObject);
    m_ueMeasConfig.haveQuantityConfig = true;
    m_ueMeasConfig.quantityConfig.filterCoefficientRSRP = m_rsrpFilterCoefficient;
    m_ueMeasConfig.quantityConfig.filterCoefficientRSRQ = m_rsrqFilterCoefficient;
    m_ueMeasConfig.haveMeasGapConfig = false;
    m_ueMeasConfig.haveSmeasure = false;
    m_ueMeasConfig.haveSpeedStatePars = false;

    m_sib1.clear();
    m_sib1.reserve(ccPhyConf.size());
    for (const auto& it : ccPhyConf)
    {
        // Enabling MIB transmission
        LteRrcSap::MasterInformationBlock mib;
        mib.dlBandwidth = it.second.m_bandwidth;
        mib.systemFrameNumber = 0;
        m_cphySapProvider.at(it.first)->SetMasterInformationBlock(mib);

        // Enabling SIB1 transmission with default values
        LteRrcSap::SystemInformationBlockType1 sib1;
        sib1.cellAccessRelatedInfo.cellIdentity = it.second.m_cellId;
        sib1.cellAccessRelatedInfo.csgIndication = false;
        sib1.cellAccessRelatedInfo.csgIdentity = 0;
        sib1.cellAccessRelatedInfo.plmnIdentityInfo.plmnIdentity = 0; // not used
        sib1.cellSelectionInfo.qQualMin = -34;          // not used, set as minimum value
        sib1.cellSelectionInfo.qRxLevMin = m_qRxLevMin; // set as minimum value
        m_sib1.push_back(sib1);
        m_cphySapProvider.at(it.first)->SetSystemInformationBlockType1(sib1);
    }
    /*
     * Enabling transmission of other SIB. The first time System Information is
     * transmitted is arbitrarily assumed to be at +0.016s, and then it will be
     * regularly transmitted every 80 ms by default (set the
     * SystemInformationPeriodicity attribute to configure this).
     */
    // mmWave module: Changed scheduling of initial system information to +2ms
    Simulator::Schedule(MilliSeconds(m_firstSibTime), &LteEnbRrc::SendSystemInformation, this);
    m_imsiCellSinrMap.clear();
    m_firstReport = true;
    m_configured = true;
}

void
LteEnbRrc::SetInterRatHoMode(void)
{
    m_interRatHoMode = true;
}

void
LteEnbRrc::SetCellId(uint16_t cellId)
{
    // update SIB1
    m_sib1.at(0).cellAccessRelatedInfo.cellIdentity = cellId;
    m_cphySapProvider.at(0)->SetSystemInformationBlockType1(m_sib1.at(0));
}

void
LteEnbRrc::SetCellId(uint16_t cellId, uint8_t ccIndex)
{
    // update SIB1
    m_sib1.at(ccIndex).cellAccessRelatedInfo.cellIdentity = cellId;
    m_cphySapProvider.at(ccIndex)->SetSystemInformationBlockType1(m_sib1.at(ccIndex));
}

void
LteEnbRrc::SetClosestLteCellId(uint16_t cellId)
{
    m_lteCellId = cellId;
    NS_LOG_LOGIC("Closest Lte CellId set to " << m_lteCellId);
}

uint16_t
LteEnbRrc::GetCellId() const
{
    return m_cellId;
}

void
LteEnbRrc::DoUpdateUeSinrEstimate(LteEnbCphySapUser::UeAssociatedSinrInfo info)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_INFO("CC " << (uint16_t)info.componentCarrierId << " reports the ueImsiSinrMap");
    m_ueImsiSinrMap[info.componentCarrierId] =
        info.ueImsiSinrMap; // store the received report in m_ueImsiSinrMap

    // TODO report immediately or with some filtering
    if (m_lteCellId >
        0) // i.e., only if a LTE eNB was actually registered in the scenario
           // (this is done when an X2 interface among mmWave eNBs and LTE eNB is added)
    {
        // send the report to the LTE coordinator
        EpcX2SapProvider::UeImsiSinrParams params;
        params.targetCellId = m_lteCellId;
        params.sourceCellId = m_cellId;

        // if (m_reportAllUeMeas == true)
        if (false)
        {
            params.ueImsiSinrMap = info.ueImsiSinrMap;
            m_ueImsiSinrMap.clear(); // delete the reports
        }
        else
        {
            if (m_ueImsiSinrMap.size() ==
                m_numberOfComponentCarriers) // if we received the ueImsiSinrMap report from all the
                                             // CCs
            {
                // Build the ueImsiSinrMapToSend containing, for each UE, the max SINR among all the
                // CCs
                NS_LOG_DEBUG("Number of ueImsiSinrMaps in m_ueImsiSinrMap "
                             << (uint16_t)m_ueImsiSinrMap.size());

                std::map<uint64_t, double> ueImsiSinrMapToSend; // map which contains the max SINR
                                                                // for each UE among the CCs
                ueImsiSinrMapToSend = m_ueImsiSinrMap.at(0);    // initialization

                for (uint8_t cc = 1; cc < m_numberOfComponentCarriers; cc++)
                {
                    NS_ASSERT_MSG(m_ueImsiSinrMap.find(cc) != m_ueImsiSinrMap.end(),
                                  "CC " << (uint16_t)cc << " didn't report the ueImsiSinrMap");

                    for (std::map<uint64_t, double>::iterator ue = ueImsiSinrMapToSend.begin();
                         ue != ueImsiSinrMapToSend.end();
                         ue++)
                    {
                        NS_ASSERT_MSG(
                            m_ueImsiSinrMap.at(cc).find(ue->first) != m_ueImsiSinrMap.at(cc).end(),
                            "CC " << (uint16_t)cc << " didn't report SINR for UE " << ue->first);

                        NS_LOG_DEBUG("UE " << ue->first << " current SINR " << ue->second
                                           << " is higher than "
                                           << m_ueImsiSinrMap.at(cc).at(ue->first) << " ?");
                        if (ue->second < m_ueImsiSinrMap.at(cc).at(ue->first))
                        {
                            NS_LOG_DEBUG("No, update SINR to "
                                         << m_ueImsiSinrMap.at(cc).at(ue->first));
                            ue->second = m_ueImsiSinrMap.at(cc).at(
                                ue->first); // insert the max SINR for this UE among all the CCs
                        }
                    }
                }
                params.ueImsiSinrMap = ueImsiSinrMapToSend;
                m_ueImsiSinrMap.clear(); // delete the reports
            }
        }

        NS_LOG_INFO("number of SINR reported " << params.ueImsiSinrMap.size());
        m_x2SapProvider->SendUeSinrUpdate(params);
    }
}

void
LteEnbRrc::DoRecvUeSinrUpdate(EpcX2SapUser::UeImsiSinrParams params)
{
    NS_LOG_FUNCTION(this);
    NS_LOG_LOGIC("Recv Ue SINR Update from cell " << params.sourceCellId);
    uint16_t mmWaveCellId = params.sourceCellId;
    if (m_cellSinrMap.find(mmWaveCellId) != m_cellSinrMap.end())
    { // update the entry
        m_cellSinrMap[mmWaveCellId] = params.ueImsiSinrMap;
        m_numNewSinrReports++;
    }
    else // add the entry
    {
        m_cellSinrMap.insert(std::pair<uint16_t, ImsiSinrMap>(mmWaveCellId, params.ueImsiSinrMap));
        m_numNewSinrReports++;
    }
    // cycle on all the Imsi whose SINR is known in cell mmWaveCellId
    for (std::map<uint64_t, double>::iterator imsiIter = params.ueImsiSinrMap.begin();
         imsiIter != params.ueImsiSinrMap.end();
         ++imsiIter)
    {
        uint64_t imsi = imsiIter->first;
        double sinr = imsiIter->second;

        m_notifyMmWaveSinrTrace(imsi, mmWaveCellId, sinr);

        NS_LOG_LOGIC("Imsi " << imsi << " sinr " << sinr);

        if (m_imsiCellSinrMap.find(imsi) != m_imsiCellSinrMap.end())
        {
            if (m_imsiCellSinrMap[imsi].find(mmWaveCellId) != m_imsiCellSinrMap[imsi].end())
            {
                // update the SINR measure
                m_imsiCellSinrMap[imsi].find(mmWaveCellId)->second = sinr;
            }
            else // new cell for this Imsi
            {
                // insert a new SINR measure
                m_imsiCellSinrMap[imsi].insert(std::pair<uint16_t, double>(mmWaveCellId, sinr));
            }
        }
        else // new imsi
        {
            CellSinrMap map;
            map.insert(std::pair<uint16_t, double>(mmWaveCellId, sinr));
            m_imsiCellSinrMap.insert(std::pair<uint64_t, CellSinrMap>(imsi, map));
        }
    }

    for (std::map<uint64_t, CellSinrMap>::iterator imsiIter = m_imsiCellSinrMap.begin();
         imsiIter != m_imsiCellSinrMap.end();
         ++imsiIter)
    {
        NS_LOG_LOGIC("Imsi " << imsiIter->first);
        for (CellSinrMap::iterator cellIter = imsiIter->second.begin();
             cellIter != imsiIter->second.end();
             ++cellIter)
        {
            NS_LOG_LOGIC("mmWaveCell " << cellIter->first << " sinr " << cellIter->second);
        }
    }

    if (!m_ismmWave && !m_interRatHoMode && m_firstReport)
    {
        m_firstReport = false;
        switch (m_handoverMode)
        {
        case FIXED_TTT:
            NS_LOG_INFO("Handover Mode: Fixed TTT");
            break;
        case DYNAMIC_TTT:
            NS_LOG_INFO("Handover Mode: Dynamic TTT");
            break;
        case THRESHOLD:
            NS_LOG_INFO("Handover Mode: Threshold");
            break;
        }
        Simulator::Schedule(MilliSeconds(0), &LteEnbRrc::TriggerUeAssociationUpdate, this);
    }
    else if (!m_ismmWave && m_interRatHoMode && m_firstReport)
    {
        m_firstReport = false;
        Simulator::Schedule(MilliSeconds(0), &LteEnbRrc::UpdateUeHandoverAssociation, this);
    }
}

void
LteEnbRrc::TttBasedHandover(std::map<uint64_t, CellSinrMap>::iterator imsiIter,
                            double sinrDifference,
                            uint16_t maxSinrCellId,
                            double maxSinrDb)
{
    uint64_t imsi = imsiIter->first;
    bool alreadyAssociatedImsi = false;
    bool onHandoverImsi = true;
    // On RecvRrcConnectionRequest for a new RNTI, the Lte Enb RRC stores the imsi
    // of the UE and insert a new false entry in m_mmWaveCellSetupCompleted.
    // After the first connection to a MmWave eNB, the entry becomes true.
    // When an handover between MmWave cells is triggered, it is set to false.
    if (m_mmWaveCellSetupCompleted.find(imsi) != m_mmWaveCellSetupCompleted.end())
    {
        alreadyAssociatedImsi = true;
        // onHandoverImsi = (!m_switchEnabled) ? true :
        // !m_mmWaveCellSetupCompleted.find(imsi)->second;
        onHandoverImsi = !m_mmWaveCellSetupCompleted.find(imsi)->second;
    }
    else
    {
        alreadyAssociatedImsi = false;
        onHandoverImsi = true;
    }
    NS_LOG_INFO("TttBasedHandover: alreadyAssociatedImsi " << alreadyAssociatedImsi
                                                           << " onHandoverImsi " << onHandoverImsi);

    bool handoverNeeded = false;

    double currentSinrDb = 0;
    if (alreadyAssociatedImsi && m_lastMmWaveCell.find(imsi) != m_lastMmWaveCell.end())
    {
        currentSinrDb =
            10 * std::log10(m_imsiCellSinrMap.find(imsi)->second[m_lastMmWaveCell[imsi]]);
        NS_LOG_DEBUG("Current SINR " << currentSinrDb);
    }

    // the UE was in outage, now a mmWave eNB is available. It may be the one to which the UE is
    // already attached or another one
    if (alreadyAssociatedImsi && m_imsiUsingLte[imsi])
    {
        if (!m_interRatHoMode)
        {
            if (GetUeManager(GetRntiFromImsi(imsi))->GetAllMmWaveInOutageAtInitialAccess())
            {
                NS_LOG_INFO("Send connect to "
                            << maxSinrCellId
                            << ", for the first time at least one mmWave eNB is not in outage");
                m_rrcSapUser->SendRrcConnectToMmWave(GetRntiFromImsi(imsi), maxSinrCellId);
                GetUeManager(GetRntiFromImsi(imsi))->SetAllMmWaveInOutageAtInitialAccess(false);
            }
            else if (m_lastMmWaveCell[imsi] == maxSinrCellId && !onHandoverImsi)
            // it is on LTE, but now the last used MmWave cell is not in outage
            {
                // switch back to MmWave
                NS_LOG_INFO("----- on LTE, switch to lastMmWaveCell "
                            << m_lastMmWaveCell[imsi] << " at time "
                            << Simulator::Now().GetSeconds());
                Ptr<UeManager> ueMan = GetUeManager(GetRntiFromImsi(imsi));
                bool useMmWaveConnection = true;
                m_imsiUsingLte[imsi] = !useMmWaveConnection;
                ueMan->SendRrcConnectionSwitch(useMmWaveConnection);
            }
            else if (m_lastMmWaveCell[imsi] != maxSinrCellId && !onHandoverImsi)
            // it is on LTE, but now a MmWave cell different from the last used is not in outage, so
            // we need to handover
            {
                // already using LTE connection
                NS_LOG_INFO("----- on LTE, switch to new MmWaveCell "
                            << maxSinrCellId << " at time " << Simulator::Now().GetSeconds());
                // trigger ho via X2
                EpcX2SapProvider::SecondaryHandoverParams params;
                params.imsi = imsi;
                params.targetCellId = maxSinrCellId;
                params.oldCellId = m_lastMmWaveCell[imsi];
                m_x2SapProvider->SendMcHandoverRequest(params);

                m_mmWaveCellSetupCompleted[imsi] = false;
            }
        }
        else
        {
            if (!onHandoverImsi)
            {
                // trigger an handover to mmWave
                m_mmWaveCellSetupCompleted[imsi] = false;
                m_bestMmWaveCellForImsiMap[imsi] = maxSinrCellId;
                NS_LOG_INFO("---- on LTE, handover to MmWave " << maxSinrCellId << " at time "
                                                               << Simulator::Now().GetSeconds());
                SendHandoverRequest(GetRntiFromImsi(imsi), maxSinrCellId);
            }
        }
    }
    else if (alreadyAssociatedImsi && !onHandoverImsi)
    {
        // the UE is connected to a mmWave eNB which was not in outage
        // check if there are HO events pending
        HandoverEventMap::iterator handoverEvent = m_imsiHandoverEventsMap.find(imsi);
        if (handoverEvent != m_imsiHandoverEventsMap.end())
        {
            // an handover event is already scheduled
            // check if the cell to which the handover should happen is maxSinrCellId
            if (handoverEvent->second.targetCellId == maxSinrCellId)
            {
                if (currentSinrDb < m_outageThreshold) // we need to handover right now!
                {
                    handoverEvent->second.scheduledHandoverEvent.Cancel();
                    handoverNeeded = true;
                    NS_LOG_INFO("------ Handover was already scheduled, but the current cell is in "
                                "outage, thus HO to "
                                << maxSinrCellId);
                }
                else
                {
                    // TODO consider if TTT must be updated or if it can remain as computed before
                    // we should compute the new TTT: if Now() + TTT < scheduledTime then update!
                    uint8_t newTtt = ComputeTtt(sinrDifference);
                    uint64_t handoverHappensAtTime =
                        handoverEvent->second.scheduledHandoverEvent.GetTs(); // in nanoseconds
                    NS_LOG_INFO("Scheduled for " << handoverHappensAtTime
                                                 << " while now the scheduler would give "
                                                 << Simulator::Now().GetMilliSeconds() + newTtt);
                    if (Simulator::Now().GetMilliSeconds() + newTtt <
                        (double)handoverHappensAtTime / 1e6)
                    {
                        handoverEvent->second.scheduledHandoverEvent.Cancel();
                        NS_LOG_INFO("------ Handover remains scheduled for "
                                    << maxSinrCellId << " but a new shorter TTT is computed");
                        handoverNeeded = true;
                    }
                }
            }
            else
            {
                uint16_t targetCellId = handoverEvent->second.targetCellId;
                NS_LOG_INFO("------ Handover was scheduled for "
                            << handoverEvent->second.targetCellId << " but now maxSinrCellId is "
                            << maxSinrCellId);
                //  get the SINR for the scheduled targetCellId: if the diff is smaller than 3 dB
                //  handover anyway
                double originalTargetSinrDb =
                    10 * std::log10(m_imsiCellSinrMap.find(imsi)->second[targetCellId]);
                if (maxSinrDb - originalTargetSinrDb >
                    m_sinrThresholdDifference) // this parameter is the same as the one for
                                               // ThresholdBasedSecondaryCellHandover
                {
                    // delete this event
                    handoverEvent->second.scheduledHandoverEvent.Cancel();
                    // we need to re-compute the TTT and schedule a new event
                    if (maxSinrCellId != m_lastMmWaveCell[imsi])
                    {
                        handoverNeeded = true;
                    }
                    else
                    {
                        m_imsiHandoverEventsMap.erase(handoverEvent);
                    }
                }
                else
                {
                    if (maxSinrCellId == m_lastMmWaveCell[imsi])
                    {
                        // delete this event
                        NS_LOG_INFO("-------------- The difference between the two mmWave SINR is "
                                    "smaller than "
                                    << m_sinrThresholdDifference
                                    << " dB, but the new max is the current cell, thus cancel the "
                                       "handover");
                        handoverEvent->second.scheduledHandoverEvent.Cancel();
                        m_imsiHandoverEventsMap.erase(handoverEvent);
                    }
                    else
                    {
                        NS_LOG_INFO("-------------- The difference between the two mmWave SINR is "
                                    "smaller than "
                                    << m_sinrThresholdDifference
                                    << " dB, do not cancel the handover");
                    }
                }
            }
        }
        else
        {
            // check if the maxSinrCellId is different from the current cell
            if (maxSinrCellId != m_lastMmWaveCell[imsi])
            {
                NS_LOG_INFO("----- Handover needed from cell " << m_lastMmWaveCell[imsi] << " to "
                                                               << maxSinrCellId);
                handoverNeeded = true;
            }
        }
    }

    if (handoverNeeded)
    {
        NS_LOG_DEBUG("handoverNeeded");
        // compute the TTT
        uint8_t millisecondsToHandover = ComputeTtt(sinrDifference);
        NS_LOG_INFO("The sinrDifference is "
                    << sinrDifference << " and the TTT computed is "
                    << (uint32_t)millisecondsToHandover
                    << " ms, thus the event will happen at time "
                    << Simulator::Now().GetMilliSeconds() + millisecondsToHandover);
        if (currentSinrDb < m_outageThreshold)
        {
            millisecondsToHandover = 0;
            NS_LOG_INFO("Current Cell is in outage, handover immediately");
        }
        // schedule the event
        EventId scheduledHandoverEvent = Simulator::Schedule(MilliSeconds(millisecondsToHandover),
                                                             &LteEnbRrc::PerformHandover,
                                                             this,
                                                             imsi);
        LteEnbRrc::HandoverEventInfo handoverInfo;
        handoverInfo.sourceCellId = m_lastMmWaveCell[imsi];
        handoverInfo.targetCellId = maxSinrCellId;
        handoverInfo.scheduledHandoverEvent = scheduledHandoverEvent;
        HandoverEventMap::iterator handoverEvent = m_imsiHandoverEventsMap.find(imsi);
        if (handoverEvent !=
            m_imsiHandoverEventsMap.end()) // another event was scheduled, but it was already
                                           // deleted. Replace the entry
        {
            handoverEvent->second = handoverInfo;
        }
        else
        {
            m_imsiHandoverEventsMap.insert(
                std::pair<uint64_t, HandoverEventInfo>(imsi, handoverInfo));
        }
        // when the handover event happens, we need to check that no other procedures are ongoing
        // and in case postpone it!
    }
}

uint8_t
LteEnbRrc::ComputeTtt(double sinrDifference)
{
    if (m_handoverMode == FIXED_TTT)
    {
        return m_fixedTttValue;
    }
    else if (m_handoverMode == DYNAMIC_TTT)
    {
        if (sinrDifference < m_minDiffTttValue)
        {
            return m_maxDynTttValue;
        }
        else if (sinrDifference > m_maxDiffTttValue)
        {
            return m_minDynTttValue;
        }
        else // in between
        {
            double ttt = m_maxDynTttValue - (m_maxDynTttValue - m_minDynTttValue) *
                                                (sinrDifference - m_minDiffTttValue) /
                                                (m_maxDiffTttValue - m_minDiffTttValue);
            NS_ASSERT_MSG(ttt >= 0, "Negative TTT!");
            uint8_t truncated_ttt = ttt;
            return truncated_ttt;
        }
    }
    else
    {
        NS_FATAL_ERROR("Unsupported HO mode");
    }
}

void
LteEnbRrc::PerformHandover(uint64_t imsi)
{
    NS_ASSERT_MSG(m_imsiHandoverEventsMap.find(imsi) != m_imsiHandoverEventsMap.end(),
                  "No handover event for this imsi!");
    LteEnbRrc::HandoverEventInfo handoverInfo = m_imsiHandoverEventsMap.find(imsi)->second;
    NS_ASSERT_MSG(
        handoverInfo.sourceCellId == m_lastMmWaveCell[imsi],
        "The secondary cell to which the UE is attached has changed handoverInfo.sourceCellId "
            << handoverInfo.sourceCellId << " m_lastMmWaveCell[imsi] " << m_lastMmWaveCell[imsi]
            << " imsi " << imsi);
    bool alreadyAssociatedImsi = false;
    bool onHandoverImsi = true;
    // On RecvRrcConnectionRequest for a new RNTI, the Lte Enb RRC stores the imsi
    // of the UE and insert a new false entry in m_mmWaveCellSetupCompleted.
    // After the first connection to a MmWave eNB, the entry becomes true.
    // When an handover between MmWave cells is triggered, it is set to false.
    if (m_mmWaveCellSetupCompleted.find(imsi) != m_mmWaveCellSetupCompleted.end())
    {
        alreadyAssociatedImsi = true;
        // onHandoverImsi = (!m_switchEnabled) ? true :
        // !m_mmWaveCellSetupCompleted.find(imsi)->second;
        onHandoverImsi = !m_mmWaveCellSetupCompleted.find(imsi)->second;
    }
    else
    {
        alreadyAssociatedImsi = false;
        onHandoverImsi = true;
    }
    NS_LOG_INFO("PerformHandover: alreadyAssociatedImsi " << alreadyAssociatedImsi
                                                          << " onHandoverImsi " << onHandoverImsi);

    if (alreadyAssociatedImsi)
    {
        if (!onHandoverImsi)
        {
            // The new secondary cell HO procedure does not require to switch to LTE
            NS_LOG_INFO("PerformHandover ----- handover from "
                        << m_lastMmWaveCell[imsi] << " to " << handoverInfo.targetCellId
                        << " at time " << Simulator::Now().GetSeconds());

            // trigger ho via X2
            EpcX2SapProvider::SecondaryHandoverParams params;
            params.imsi = imsi;
            params.targetCellId = handoverInfo.targetCellId;
            params.oldCellId = m_lastMmWaveCell[imsi];
            m_x2SapProvider->SendMcHandoverRequest(params);

            m_mmWaveCellSetupCompleted[imsi] = false;
        }
        else
        {
            // TODO Do nothing or what?
            NS_LOG_UNCOND(
                "## Warn: handover not triggered because the UE is already performing HO!");
        }
    }
    else
    {
        NS_LOG_UNCOND("## Warn: handover not triggered because the UE is not associated yet!");
    }

    // remove the HandoverEvent from the map
    m_imsiHandoverEventsMap.erase(m_imsiHandoverEventsMap.find(imsi));
}

void
LteEnbRrc::ThresholdBasedSecondaryCellHandover(std::map<uint64_t, CellSinrMap>::iterator imsiIter,
                                               double sinrDifference,
                                               uint16_t maxSinrCellId,
                                               double maxSinrDb)
{
    uint64_t imsi = imsiIter->first;
    bool alreadyAssociatedImsi = false;
    bool onHandoverImsi = true;
    // On RecvRrcConnectionRequest for a new RNTI, the Lte Enb RRC stores the imsi
    // of the UE and insert a new false entry in m_mmWaveCellSetupCompleted.
    // After the first connection to a MmWave eNB, the entry becomes true.
    // When an handover between MmWave cells is triggered, it is set to false.
    if (m_mmWaveCellSetupCompleted.find(imsi) != m_mmWaveCellSetupCompleted.end())
    {
        alreadyAssociatedImsi = true;
        // onHandoverImsi = (!m_switchEnabled) ? true :
        // !m_mmWaveCellSetupCompleted.find(imsi)->second;
        onHandoverImsi = !m_mmWaveCellSetupCompleted.find(imsi)->second;
    }
    else
    {
        alreadyAssociatedImsi = false;
        onHandoverImsi = true;
    }
    NS_LOG_INFO("ThresholdBasedSecondaryCellHandover: alreadyAssociatedImsi "
                << alreadyAssociatedImsi << " onHandoverImsi " << onHandoverImsi);

    if (maxSinrCellId == m_bestMmWaveCellForImsiMap.at(imsi) && !m_imsiUsingLte[imsi])
    {
        if (alreadyAssociatedImsi && !onHandoverImsi && m_lastMmWaveCell[imsi] != maxSinrCellId &&
            sinrDifference > m_sinrThresholdDifference) // not on LTE, handover between MmWave cells
        // this may happen when channel changes while there is an handover
        {
            NS_LOG_INFO("----- handover from " << m_lastMmWaveCell[imsi] << " to " << maxSinrCellId
                                               << " channel changed previously at time "
                                               << Simulator::Now().GetSeconds());

            // The new secondary cell HO procedure does not require to switch to LTE
            // Ptr<UeManager> ueMan = GetUeManager(GetRntiFromImsi(imsi));
            // bool useMmWaveConnection = false;
            // m_imsiUsingLte[imsi] = !useMmWaveConnection;
            // ueMan->SendRrcConnectionSwitch(useMmWaveConnection);

            // trigger ho via X2
            EpcX2SapProvider::SecondaryHandoverParams params;
            params.imsi = imsi;
            params.targetCellId = maxSinrCellId;
            params.oldCellId = m_lastMmWaveCell[imsi];
            m_x2SapProvider->SendMcHandoverRequest(params);

            m_mmWaveCellSetupCompleted[imsi] = false; // TODO check this bool
            m_bestMmWaveCellForImsiMap[imsi] = maxSinrCellId;
            NS_LOG_INFO("For imsi " << imsi << " the best cell is "
                                    << m_bestMmWaveCellForImsiMap.at(imsi) << " with SINR "
                                    << maxSinrDb);
        }
        else if (alreadyAssociatedImsi && !onHandoverImsi &&
                 m_lastMmWaveCell[imsi] != maxSinrCellId &&
                 sinrDifference < m_sinrThresholdDifference)
        {
            NS_LOG_INFO("----- handover from " << m_lastMmWaveCell[imsi] << " to " << maxSinrCellId
                                               << " not triggered due to small diff "
                                               << sinrDifference << " at time "
                                               << Simulator::Now().GetSeconds());
        }
    }
    else
    {
        if (alreadyAssociatedImsi && !onHandoverImsi && m_imsiUsingLte[imsi] &&
            GetUeManager(GetRntiFromImsi(imsi))->GetAllMmWaveInOutageAtInitialAccess())
        {
            // perform initial access to mmWave eNB, since for the first time one mmWave eNB is not
            // in outage!
            NS_LOG_INFO("Send connect to "
                        << maxSinrCellId
                        << ", for the first time at least one mmWave eNB is not in outage");
            m_rrcSapUser->SendRrcConnectToMmWave(GetRntiFromImsi(imsi), maxSinrCellId);
        }
        else if (alreadyAssociatedImsi && !onHandoverImsi && m_imsiUsingLte[imsi] &&
                 m_lastMmWaveCell[imsi] == maxSinrCellId)
        // it is on LTE, but now the last used MmWave cell is not in outage
        {
            // switch back to MmWave
            NS_LOG_INFO("----- on LTE, switch to lastMmWaveCell "
                        << m_lastMmWaveCell[imsi] << " at time " << Simulator::Now().GetSeconds());
            Ptr<UeManager> ueMan = GetUeManager(GetRntiFromImsi(imsi));
            bool useMmWaveConnection = true;
            m_imsiUsingLte[imsi] = !useMmWaveConnection;
            ueMan->SendRrcConnectionSwitch(useMmWaveConnection);
        }
        else if (alreadyAssociatedImsi && !onHandoverImsi && m_imsiUsingLte[imsi] &&
                 m_lastMmWaveCell[imsi] != maxSinrCellId)
        // it is on LTE, but now a MmWave cell different from the last used is not in outage, so we
        // need to handover
        {
            // already using LTE connection
            NS_LOG_INFO("----- on LTE, switch to new MmWaveCell " << maxSinrCellId << " at time "
                                                                  << Simulator::Now().GetSeconds());
            // trigger ho via X2
            EpcX2SapProvider::SecondaryHandoverParams params;
            params.imsi = imsi;
            params.targetCellId = maxSinrCellId;
            params.oldCellId = m_lastMmWaveCell[imsi];
            m_x2SapProvider->SendMcHandoverRequest(params);

            m_mmWaveCellSetupCompleted[imsi] = false;
        }
        else if (alreadyAssociatedImsi && !onHandoverImsi &&
                 m_lastMmWaveCell[imsi] != maxSinrCellId &&
                 sinrDifference > m_sinrThresholdDifference)
        // not on LTE, handover between MmWave cells
        {
            // The new secondary cell HO procedure does not require to switch to LTE
            NS_LOG_INFO("----- handover from " << m_lastMmWaveCell[imsi] << " to " << maxSinrCellId
                                               << " at time " << Simulator::Now().GetSeconds());
            // Ptr<UeManager> ueMan = GetUeManager(GetRntiFromImsi(imsi));
            // bool useMmWaveConnection = false;
            // m_imsiUsingLte[imsi] = !useMmWaveConnection;
            // ueMan->SendRrcConnectionSwitch(useMmWaveConnection);

            // trigger ho via X2
            EpcX2SapProvider::SecondaryHandoverParams params;
            params.imsi = imsi;
            params.targetCellId = maxSinrCellId;
            params.oldCellId = m_lastMmWaveCell[imsi];
            m_x2SapProvider->SendMcHandoverRequest(params);

            m_mmWaveCellSetupCompleted[imsi] = false;
        }
        else if (alreadyAssociatedImsi && !onHandoverImsi &&
                 m_lastMmWaveCell[imsi] != maxSinrCellId &&
                 sinrDifference < m_sinrThresholdDifference)
        {
            NS_LOG_INFO("----- handover from " << m_lastMmWaveCell[imsi] << " to " << maxSinrCellId
                                               << " not triggered due to small diff "
                                               << sinrDifference << " at time "
                                               << Simulator::Now().GetSeconds());
        }
        m_bestMmWaveCellForImsiMap[imsi] = maxSinrCellId;
        NS_LOG_INFO("For imsi " << imsi << " the best cell is "
                                << m_bestMmWaveCellForImsiMap.at(imsi) << " with SINR "
                                << maxSinrDb);
    }
}

void
LteEnbRrc::TriggerUeAssociationUpdate()
{
    if (m_imsiCellSinrMap.size() > 0) // there are some entries
    {
        for (std::map<uint64_t, CellSinrMap>::iterator imsiIter = m_imsiCellSinrMap.begin();
             imsiIter != m_imsiCellSinrMap.end();
             ++imsiIter)
        {
            uint64_t imsi = imsiIter->first;
            long double maxSinr = 0;
            long double currentSinr = 0;
            uint16_t maxSinrCellId = 0;
            bool alreadyAssociatedImsi = false;
            bool onHandoverImsi = true;
            Ptr<UeManager> ueMan;
            // On RecvRrcConnectionRequest for a new RNTI, the Lte Enb RRC stores the imsi
            // of the UE and insert a new false entry in m_mmWaveCellSetupCompleted.
            // After the first connection to a MmWave eNB, the entry becomes true.
            // When an handover between MmWave cells is triggered, it is set to false.
            if (m_mmWaveCellSetupCompleted.find(imsi) != m_mmWaveCellSetupCompleted.end())
            {
                alreadyAssociatedImsi = true;
                // onHandoverImsi = (!m_switchEnabled) ? true :
                // !m_mmWaveCellSetupCompleted.find(imsi)->second;
                onHandoverImsi = !m_mmWaveCellSetupCompleted.find(imsi)->second;
            }
            else
            {
                alreadyAssociatedImsi = false;
                onHandoverImsi = true;
            }
            NS_LOG_INFO("alreadyAssociatedImsi " << alreadyAssociatedImsi << " onHandoverImsi "
                                                 << onHandoverImsi);

            for (CellSinrMap::iterator cellIter = imsiIter->second.begin();
                 cellIter != imsiIter->second.end();
                 ++cellIter)
            {
                NS_LOG_INFO("Cell " << cellIter->first << " reports "
                                    << 10 * std::log10(cellIter->second));
                if (cellIter->second > maxSinr)
                {
                    maxSinr = cellIter->second;
                    maxSinrCellId = cellIter->first;
                }
                if (m_lastMmWaveCell[imsi] == cellIter->first)
                {
                    currentSinr = cellIter->second;
                }
            }
            long double sinrDifference = std::abs(
                10 * (std::log10((long double)maxSinr) - std::log10((long double)currentSinr)));
            long double maxSinrDb = 10 * std::log10((long double)maxSinr);
            long double currentSinrDb = 10 * std::log10((long double)currentSinr);
            NS_LOG_INFO("MaxSinr " << maxSinrDb << " in cell " << maxSinrCellId << " current cell "
                                   << m_lastMmWaveCell[imsi] << " currentSinr " << currentSinrDb
                                   << " sinrDifference " << sinrDifference);
            if ((maxSinrDb < m_outageThreshold ||
                 (m_imsiUsingLte[imsi] && maxSinrDb < m_outageThreshold + 2)) &&
                alreadyAssociatedImsi) // no MmWaveCell can serve this UE
            {
                // outage, perform fast switching if MC device or hard handover
                NS_LOG_INFO("----- Warn: outage detected ------ at time "
                            << Simulator::Now().GetSeconds());
                if (m_imsiUsingLte[imsi] == false)
                {
                    ueMan = GetUeManager(GetRntiFromImsi(imsi));
                    NS_LOG_INFO("Switch to LTE stack");
                    bool useMmWaveConnection = false;
                    m_imsiUsingLte[imsi] = !useMmWaveConnection;
                    ueMan->SendRrcConnectionSwitch(useMmWaveConnection);
                    // m_switchEnabled = false;
                    // Simulator::Schedule(MilliSeconds(50), &LteEnbRrc::EnableSwitching, this,
                    // imsi);

                    // delete the handover event which was scheduled for this UE (if any)
                    HandoverEventMap::iterator handoverEvent = m_imsiHandoverEventsMap.find(imsi);
                    if (handoverEvent != m_imsiHandoverEventsMap.end())
                    {
                        handoverEvent->second.scheduledHandoverEvent.Cancel();
                        m_imsiHandoverEventsMap.erase(handoverEvent);
                    }
                }
                else
                {
                    NS_LOG_INFO("Already on LTE");
                    ueMan = GetUeManager(GetRntiFromImsi(imsi));
                    if (ueMan->GetAllMmWaveInOutageAtInitialAccess())
                    {
                        NS_LOG_INFO("The UE never connected to a mmWave eNB");
                    }
                }
            }
            else
            {
                m_bestMmWaveCellForImsiMap[imsi] = maxSinrCellId;
                if (m_handoverMode == THRESHOLD)
                {
                    ThresholdBasedSecondaryCellHandover(imsiIter,
                                                        sinrDifference,
                                                        maxSinrCellId,
                                                        maxSinrDb);
                }
                else if (m_handoverMode == FIXED_TTT || m_handoverMode == DYNAMIC_TTT)
                {
                    TttBasedHandover(imsiIter, sinrDifference, maxSinrCellId, maxSinrDb);
                }
                else
                {
                    NS_FATAL_ERROR("Unsupported HO mode");
                }
            }
        }
    }

    Simulator::Schedule(MicroSeconds(m_crtPeriod), &LteEnbRrc::TriggerUeAssociationUpdate, this);
}

void
LteEnbRrc::ThresholdBasedInterRatHandover(std::map<uint64_t, CellSinrMap>::iterator imsiIter,
                                          double sinrDifference,
                                          uint16_t maxSinrCellId,
                                          double maxSinrDb)
{
    uint64_t imsi = imsiIter->first;
    bool alreadyAssociatedImsi = false;
    bool onHandoverImsi = true;
    // On RecvRrcConnectionRequest for a new RNTI, the Lte Enb RRC stores the imsi
    // of the UE and insert a new false entry in m_mmWaveCellSetupCompleted.
    // After the first connection to a MmWave eNB, the entry becomes true.
    // When an handover between MmWave cells is triggered, it is set to false.
    if (m_mmWaveCellSetupCompleted.find(imsi) != m_mmWaveCellSetupCompleted.end())
    {
        alreadyAssociatedImsi = true;
        // onHandoverImsi = (!m_switchEnabled) ? true :
        // !m_mmWaveCellSetupCompleted.find(imsi)->second;
        onHandoverImsi = !m_mmWaveCellSetupCompleted.find(imsi)->second;
    }
    else
    {
        alreadyAssociatedImsi = false;
        onHandoverImsi = true;
    }
    NS_LOG_INFO("ThresholdBasedSecondaryCellHandover: alreadyAssociatedImsi "
                << alreadyAssociatedImsi << " onHandoverImsi " << onHandoverImsi);

    if (maxSinrCellId == m_bestMmWaveCellForImsiMap.at(imsi) && !m_imsiUsingLte.at(imsi))
    {
        if (alreadyAssociatedImsi && !onHandoverImsi && m_lastMmWaveCell[imsi] != maxSinrCellId &&
            sinrDifference > m_sinrThresholdDifference) // not on LTE, handover between MmWave cells
        // this may happen when channel changes while there is an handover
        {
            NS_LOG_INFO("----- handover from " << m_lastMmWaveCell[imsi] << " to " << maxSinrCellId
                                               << " channel changed previously");
            // trigger ho via X2
            EpcX2SapProvider::SecondaryHandoverParams params;
            params.imsi = imsi;
            params.targetCellId = maxSinrCellId;
            params.oldCellId = m_lastMmWaveCell[imsi];
            m_x2SapProvider->SendMcHandoverRequest(params);

            m_mmWaveCellSetupCompleted[imsi] = false;
            m_bestMmWaveCellForImsiMap[imsi] = maxSinrCellId;
            NS_LOG_INFO("For imsi " << imsi << " the best cell is "
                                    << m_bestMmWaveCellForImsiMap.at(imsi) << " with SINR "
                                    << maxSinrDb);
        }
        else if (alreadyAssociatedImsi && !onHandoverImsi &&
                 m_lastMmWaveCell[imsi] != maxSinrCellId &&
                 sinrDifference < m_sinrThresholdDifference)
        {
            NS_LOG_INFO("----- handover from " << m_lastMmWaveCell[imsi] << " to " << maxSinrCellId
                                               << " not triggered due to small diff "
                                               << sinrDifference);
        }
    }
    else
    {
        if (m_imsiUsingLte[imsi] && alreadyAssociatedImsi && !onHandoverImsi)
        // it is on LTE, but now the a MmWave cell is not in outage
        {
            // switch back to MmWave
            m_mmWaveCellSetupCompleted[imsi] = false;
            m_bestMmWaveCellForImsiMap[imsi] = maxSinrCellId;
            NS_LOG_INFO("Handover to MmWave " << m_bestMmWaveCellForImsiMap.at(imsi));
            SendHandoverRequest(GetRntiFromImsi(imsi), m_bestMmWaveCellForImsiMap.at(imsi));
        }
        else if (!m_imsiUsingLte[imsi] && alreadyAssociatedImsi && !onHandoverImsi &&
                 m_lastMmWaveCell[imsi] != maxSinrCellId &&
                 sinrDifference >
                     m_sinrThresholdDifference) // not on LTE, handover between MmWave cells
        {
            NS_LOG_INFO("----- handover from " << m_lastMmWaveCell[imsi] << " to "
                                               << maxSinrCellId);
            // trigger ho via X2
            EpcX2SapProvider::SecondaryHandoverParams params;
            params.imsi = imsi;
            params.targetCellId = maxSinrCellId;
            params.oldCellId = m_lastMmWaveCell[imsi];
            m_x2SapProvider->SendMcHandoverRequest(params);

            m_mmWaveCellSetupCompleted[imsi] = false;
        }
        else if (alreadyAssociatedImsi && !onHandoverImsi &&
                 m_lastMmWaveCell[imsi] != maxSinrCellId &&
                 sinrDifference < m_sinrThresholdDifference)
        {
            NS_LOG_INFO("----- handover from " << m_lastMmWaveCell[imsi] << " to " << maxSinrCellId
                                               << " not triggered due to small diff "
                                               << sinrDifference);
        }
        m_bestMmWaveCellForImsiMap[imsi] = maxSinrCellId;
        NS_LOG_INFO("For imsi " << imsi << " the best cell is "
                                << m_bestMmWaveCellForImsiMap.at(imsi) << " with SINR "
                                << maxSinrDb);
    }
}

void
LteEnbRrc::EnableSwitching(uint64_t imsi)
{
    m_switchEnabled = true;
}

void
LteEnbRrc::UpdateUeHandoverAssociation()
{
    // TODO rules for possible ho of each UE
    if (m_imsiCellSinrMap.size() > 0) // there are some entries
    {
        for (std::map<uint64_t, CellSinrMap>::iterator imsiIter = m_imsiCellSinrMap.begin();
             imsiIter != m_imsiCellSinrMap.end();
             ++imsiIter)
        {
            uint64_t imsi = imsiIter->first;
            long double maxSinr = 0;
            long double currentSinr = 0;
            uint16_t maxSinrCellId = 0;
            bool alreadyAssociatedImsi = false;
            bool onHandoverImsi = true;

            // If the LteEnbRrc is InterRatHo mode, the MmWave eNB notifies the
            // LTE eNB of the first access of a certain imsi. This is stored in a map
            // and m_mmWaveCellSetupCompleted for that imsi is set to true.
            // When an handover between MmWave cells is triggered, it is set to false.
            if (m_mmWaveCellSetupCompleted.find(imsi) != m_mmWaveCellSetupCompleted.end())
            {
                alreadyAssociatedImsi = true;
                onHandoverImsi = !m_mmWaveCellSetupCompleted.find(imsi)->second;
            }
            else
            {
                alreadyAssociatedImsi = false;
                onHandoverImsi = true;
            }
            NS_LOG_INFO("alreadyAssociatedImsi " << alreadyAssociatedImsi << " onHandoverImsi "
                                                 << onHandoverImsi);

            for (CellSinrMap::iterator cellIter = imsiIter->second.begin();
                 cellIter != imsiIter->second.end();
                 ++cellIter)
            {
                NS_LOG_INFO("Cell " << cellIter->first << " reports "
                                    << 10 * std::log10(cellIter->second));
                if (cellIter->second > maxSinr)
                {
                    maxSinr = cellIter->second;
                    maxSinrCellId = cellIter->first;
                }
                if (m_lastMmWaveCell[imsi] == cellIter->first)
                {
                    currentSinr = cellIter->second;
                }
            }

            long double sinrDifference = std::abs(
                10 * (std::log10((long double)maxSinr) - std::log10((long double)currentSinr)));
            long double maxSinrDb = 10 * std::log10((long double)maxSinr);
            long double currentSinrDb = 10 * std::log10((long double)currentSinr);
            NS_LOG_INFO("MaxSinr " << maxSinrDb << " in cell " << maxSinrCellId << " current cell "
                                   << m_lastMmWaveCell[imsi] << " currentSinr " << currentSinrDb
                                   << " sinrDifference " << sinrDifference);
            // check if MmWave cells are in outage. In this case the UE should handover to LTE cell
            if (maxSinrDb < m_outageThreshold ||
                (m_imsiUsingLte[imsi] &&
                 maxSinrDb < m_outageThreshold + 2)) // no MmWaveCell can serve this UE
            {
                // outage, perform handover to LTE
                NS_LOG_INFO("----- Warn: outage detected ------");
                if (m_imsiUsingLte[imsi] == false)
                {
                    NS_LOG_INFO("Handover to LTE");
                    if (!onHandoverImsi)
                    {
                        bool useMmWaveConnection = false;
                        m_imsiUsingLte[imsi] = !useMmWaveConnection;
                        // trigger ho via X2
                        EpcX2SapProvider::SecondaryHandoverParams params;
                        params.imsi = imsi;
                        params.targetCellId = m_cellId;
                        params.oldCellId = m_lastMmWaveCell[imsi];
                        m_mmWaveCellSetupCompleted.find(imsi)->second = false;
                        m_x2SapProvider->SendMcHandoverRequest(params);
                    }
                    else
                    {
                        NS_LOG_INFO("Already performing another HO");
                    }

                    // delete the handover event which was scheduled for this UE (if any)
                    HandoverEventMap::iterator handoverEvent = m_imsiHandoverEventsMap.find(imsi);
                    if (handoverEvent != m_imsiHandoverEventsMap.end())
                    {
                        handoverEvent->second.scheduledHandoverEvent.Cancel();
                        m_imsiHandoverEventsMap.erase(handoverEvent);
                    }
                }
                else
                {
                    NS_LOG_INFO("Already on LTE");
                }
            }
            else // there is at least a MmWave eNB that can serve this UE
            {
                if (m_handoverMode == THRESHOLD)
                {
                    ThresholdBasedInterRatHandover(imsiIter,
                                                   sinrDifference,
                                                   maxSinrCellId,
                                                   maxSinrDb);
                }
                else if (m_handoverMode == FIXED_TTT || m_handoverMode == DYNAMIC_TTT)
                {
                    m_bestMmWaveCellForImsiMap[imsi] = maxSinrCellId;
                    TttBasedHandover(imsiIter, sinrDifference, maxSinrCellId, maxSinrDb);
                }
                else
                {
                    NS_FATAL_ERROR("Unsupported HO mode");
                }
            }
        }
    }
    Simulator::Schedule(MicroSeconds(m_crtPeriod), &LteEnbRrc::UpdateUeHandoverAssociation, this);
}

void
LteEnbRrc::DoRecvMcHandoverRequest(EpcX2SapUser::SecondaryHandoverParams params)
{
    NS_ASSERT_MSG(m_ismmWave == true,
                  "Trying to perform HO for a secondary cell on a non secondary cell");
    // retrieve RNTI
    uint16_t rnti = GetRntiFromImsi(params.imsi);
    NS_LOG_LOGIC("Rnti " << rnti);
    SendHandoverRequest(rnti, params.targetCellId);
}

uint8_t
LteEnbRrc::CellToComponentCarrierId(uint16_t cellId)
{
    NS_LOG_FUNCTION(this << cellId);
    if (!m_ismmWave)
    {
        for (auto& it : m_componentCarrierPhyConf)
        {
            if (it.second->GetCellId() == cellId)
            {
                return it.first;
            }
        }
    }
    else
    {
        for (auto& it : m_mmWaveComponentCarrierPhyConf)
        {
            if (it.second.m_cellId == cellId)
            {
                return it.first;
            }
        }
    }
    NS_FATAL_ERROR("Cell " << cellId << " not found in CC map");
}

uint16_t
LteEnbRrc::ComponentCarrierToCellId(uint8_t componentCarrierId)
{
    NS_LOG_FUNCTION(this << (uint32_t)componentCarrierId);
    uint16_t cellId;
    if (!m_ismmWave)
    {
        cellId = m_componentCarrierPhyConf.at(componentCarrierId)->GetCellId();
    }
    else
    {
        cellId = m_mmWaveComponentCarrierPhyConf.at(componentCarrierId).m_cellId;
    }
    return cellId;
}

bool
LteEnbRrc::SendData(Ptr<Packet> packet)
{
    NS_LOG_FUNCTION(this << packet);

    EpsBearerTag tag;
    bool found = packet->RemovePacketTag(tag);
    NS_ASSERT_MSG(found, "no EpsBearerTag found in packet to be sent");
    Ptr<UeManager> ueManager = GetUeManager(tag.GetRnti());
    ueManager->SendData(tag.GetBid(), packet);

    return true;
}

void
LteEnbRrc::SetForwardUpCallback(Callback<void, Ptr<Packet>> cb)
{
    m_forwardUpCallback = cb;
}

void
LteEnbRrc::ConnectionRequestTimeout(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);
    NS_ASSERT_MSG(GetUeManager(rnti)->GetState() == UeManager::INITIAL_RANDOM_ACCESS,
                  "ConnectionRequestTimeout in unexpected state "
                      << ToString(GetUeManager(rnti)->GetState()));
    RemoveUe(rnti);
}

void
LteEnbRrc::ConnectionSetupTimeout(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);
    NS_ASSERT_MSG(GetUeManager(rnti)->GetState() == UeManager::CONNECTION_SETUP,
                  "ConnectionSetupTimeout in unexpected state "
                      << ToString(GetUeManager(rnti)->GetState()));
    RemoveUe(rnti);
}

void
LteEnbRrc::ConnectionRejectedTimeout(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);
    NS_ASSERT_MSG(GetUeManager(rnti)->GetState() == UeManager::CONNECTION_REJECTED,
                  "ConnectionRejectedTimeout in unexpected state "
                      << ToString(GetUeManager(rnti)->GetState()));
    RemoveUe(rnti);
}

void
LteEnbRrc::HandoverJoiningTimeout(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);
    NS_LOG_INFO("Handover joining Timeout on cell " << m_cellId);
    NS_ASSERT_MSG(GetUeManager(rnti)->GetState() == UeManager::HANDOVER_JOINING,
                  "HandoverJoiningTimeout in unexpected state "
                      << ToString(GetUeManager(rnti)->GetState()));

    // notify the LTE eNB (coordinator) of the failure
    if (m_ismmWave)
    {
        uint16_t sourceCellId = (GetUeManager(rnti)->GetSource()).first;

        NS_LOG_INFO("rejecting handover request from cellId " << sourceCellId);
        EpcX2SapProvider::HandoverFailedParams res;
        res.sourceCellId = sourceCellId;
        res.targetCellId = m_cellId;
        res.coordinatorId = m_lteCellId;
        res.imsi = GetImsiFromRnti(rnti);
        m_x2SapProvider->NotifyCoordinatorHandoverFailed(res);
    }
    // schedule the removal of the UE
    Simulator::Schedule(MilliSeconds(300), &LteEnbRrc::RemoveUe, this, rnti);
}

void
LteEnbRrc::HandoverLeavingTimeout(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);
    NS_ASSERT_MSG(GetUeManager(rnti)->GetState() == UeManager::HANDOVER_LEAVING,
                  "HandoverLeavingTimeout in unexpected state "
                      << ToString(GetUeManager(rnti)->GetState()));
    RemoveUe(rnti);
}

void
LteEnbRrc::SendHandoverRequest(uint16_t rnti, uint16_t cellId)
{
    NS_LOG_FUNCTION(this << rnti << cellId);
    NS_LOG_LOGIC("Request to send HANDOVER REQUEST");
    NS_ASSERT(m_configured);

    NS_LOG_INFO("LteEnbRrc on cell " << m_cellId << " for rnti " << rnti
                                     << " SendHandoverRequest at time "
                                     << Simulator::Now().GetSeconds() << " to cellId " << cellId);

    Ptr<UeManager> ueManager = GetUeManager(rnti);
    ueManager->PrepareHandover(cellId);
}

void
LteEnbRrc::DoCompleteSetupUe(uint16_t rnti, LteEnbRrcSapProvider::CompleteSetupUeParameters params)
{
    NS_LOG_FUNCTION(this << rnti);
    GetUeManager(rnti)->CompleteSetupUe(params);
}

void
LteEnbRrc::DoRecvRrcConnectionRequest(uint16_t rnti, LteRrcSap::RrcConnectionRequest msg)
{
    NS_LOG_FUNCTION(this << rnti);
    GetUeManager(rnti)->RecvRrcConnectionRequest(msg);
}

void
LteEnbRrc::DoRecvRrcConnectionSetupCompleted(uint16_t rnti,
                                             LteRrcSap::RrcConnectionSetupCompleted msg)
{
    NS_LOG_FUNCTION(this << rnti);
    GetUeManager(rnti)->RecvRrcConnectionSetupCompleted(msg);
}

void
LteEnbRrc::DoRecvRrcConnectionReconfigurationCompleted(
    uint16_t rnti,
    LteRrcSap::RrcConnectionReconfigurationCompleted msg)
{
    NS_LOG_FUNCTION(this << rnti);
    NS_LOG_INFO("Received RRC connection reconf completed on cell " << m_cellId);
    GetUeManager(rnti)->RecvRrcConnectionReconfigurationCompleted(msg);
}

void
LteEnbRrc::DoRecvRrcConnectionReestablishmentRequest(
    uint16_t rnti,
    LteRrcSap::RrcConnectionReestablishmentRequest msg)
{
    NS_LOG_FUNCTION(this << rnti);
    GetUeManager(rnti)->RecvRrcConnectionReestablishmentRequest(msg);
}

void
LteEnbRrc::DoRecvRrcConnectionReestablishmentComplete(
    uint16_t rnti,
    LteRrcSap::RrcConnectionReestablishmentComplete msg)
{
    NS_LOG_FUNCTION(this << rnti);
    GetUeManager(rnti)->RecvRrcConnectionReestablishmentComplete(msg);
}

void
LteEnbRrc::DoRecvMeasurementReport(uint16_t rnti, LteRrcSap::MeasurementReport msg)
{
    NS_LOG_FUNCTION(this << rnti);
    GetUeManager(rnti)->RecvMeasurementReport(msg);
}

void
LteEnbRrc::DoRecvRrcSecondaryCellInitialAccessSuccessful(uint16_t rnti,
                                                         uint16_t mmWaveRnti,
                                                         uint16_t mmWaveCellId)
{
    NS_LOG_FUNCTION(this << rnti);
    GetUeManager(rnti)->RecvRrcSecondaryCellInitialAccessSuccessful(mmWaveRnti, mmWaveCellId);
}

void
LteEnbRrc::DoDataRadioBearerSetupRequest(
    EpcEnbS1SapUser::DataRadioBearerSetupRequestParameters request)
{
    Ptr<UeManager> ueManager = GetUeManager(request.rnti);
    ueManager->SetupDataRadioBearer(request.bearer,
                                    request.bearerId,
                                    request.gtpTeid,
                                    request.transportLayerAddress);
}

void
LteEnbRrc::DoPathSwitchRequestAcknowledge(
    EpcEnbS1SapUser::PathSwitchRequestAcknowledgeParameters params)
{
    Ptr<UeManager> ueManager = GetUeManager(params.rnti);
    ueManager->SendUeContextRelease();
}

void
LteEnbRrc::DoRecvHandoverRequest(EpcX2SapUser::HandoverRequestParams req)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: HANDOVER REQUEST");

    NS_LOG_LOGIC("oldEnbUeX2apId = " << req.oldEnbUeX2apId);
    NS_LOG_LOGIC("sourceCellId = " << req.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << req.targetCellId);
    NS_LOG_LOGIC("mmeUeS1apId = " << req.mmeUeS1apId);
    NS_LOG_INFO("isMc = " << req.isMc);

    if (m_admitHandoverRequest == false)
    {
        NS_LOG_INFO("rejecting handover request from cellId " << req.sourceCellId);
        EpcX2Sap::HandoverPreparationFailureParams res;
        res.oldEnbUeX2apId = req.oldEnbUeX2apId;
        res.sourceCellId = req.sourceCellId;
        res.targetCellId = req.targetCellId;
        res.cause = 0;
        res.criticalityDiagnostics = 0;
        m_x2SapProvider->SendHandoverPreparationFailure(res);
        return;
    }

    uint16_t rnti = AddUe(UeManager::HANDOVER_JOINING, CellToComponentCarrierId(req.targetCellId));
    LteEnbCmacSapProvider::AllocateNcRaPreambleReturnValue anrcrv =
        m_cmacSapProvider.at(0)->AllocateNcRaPreamble(rnti);
    if (anrcrv.valid == false)
    {
        NS_LOG_INFO(
            this
            << " failed to allocate a preamble for non-contention based RA => cannot accept HO");
        RemoveUe(rnti);
        NS_FATAL_ERROR("should trigger HO Preparation Failure, but it is not implemented");
        return;
    }

    Ptr<UeManager> ueManager = GetUeManager(rnti);
    ueManager->SetSource(req.sourceCellId, req.oldEnbUeX2apId);
    ueManager->SetImsi(req.mmeUeS1apId);
    ueManager->SetIsMc(req.isMc);
    RegisterImsiToRnti(req.mmeUeS1apId, rnti);

    EpcX2SapProvider::HandoverRequestAckParams ackParams;
    ackParams.oldEnbUeX2apId = req.oldEnbUeX2apId;
    ackParams.newEnbUeX2apId = rnti;
    ackParams.sourceCellId = req.sourceCellId;
    ackParams.targetCellId = req.targetCellId;

    for (std::vector<EpcX2Sap::ErabToBeSetupItem>::iterator it = req.bearers.begin();
         it != req.bearers.end();
         ++it)
    {
        ueManager->SetupDataRadioBearer(it->erabLevelQosParameters,
                                        it->erabId,
                                        it->gtpTeid,
                                        it->transportLayerAddress);
        EpcX2Sap::ErabAdmittedItem i;
        i.erabId = it->erabId;
        ackParams.admittedBearers.push_back(i);
    }

    // For secondary cell HO for MC devices, setup RLC instances
    for (std::vector<EpcX2Sap::RlcSetupRequest>::iterator it = req.rlcRequests.begin();
         it != req.rlcRequests.end();
         ++it)
    {
        ueManager->RecvRlcSetupRequest(*it);
    }

    LteRrcSap::RrcConnectionReconfiguration handoverCommand =
        ueManager->GetRrcConnectionReconfigurationForHandover();
    handoverCommand.haveMobilityControlInfo = true;
    handoverCommand.mobilityControlInfo.targetPhysCellId = req.targetCellId;
    handoverCommand.mobilityControlInfo.haveCarrierFreq = true;
    handoverCommand.mobilityControlInfo.carrierFreq.dlCarrierFreq = m_dlEarfcn;
    handoverCommand.mobilityControlInfo.carrierFreq.ulCarrierFreq = m_ulEarfcn;
    handoverCommand.mobilityControlInfo.haveCarrierBandwidth = true;
    handoverCommand.mobilityControlInfo.carrierBandwidth.dlBandwidth = m_dlBandwidth;
    handoverCommand.mobilityControlInfo.carrierBandwidth.ulBandwidth = m_ulBandwidth;
    handoverCommand.mobilityControlInfo.newUeIdentity = rnti;
    handoverCommand.mobilityControlInfo.haveRachConfigDedicated = true;
    handoverCommand.mobilityControlInfo.rachConfigDedicated.raPreambleIndex = anrcrv.raPreambleId;
    handoverCommand.mobilityControlInfo.rachConfigDedicated.raPrachMaskIndex =
        anrcrv.raPrachMaskIndex;

    LteEnbCmacSapProvider::RachConfig rc = m_cmacSapProvider.at(0)->GetRachConfig();
    handoverCommand.mobilityControlInfo.radioResourceConfigCommon.rachConfigCommon.preambleInfo
        .numberOfRaPreambles = rc.numberOfRaPreambles;
    handoverCommand.mobilityControlInfo.radioResourceConfigCommon.rachConfigCommon.raSupervisionInfo
        .preambleTransMax = rc.preambleTransMax;
    handoverCommand.mobilityControlInfo.radioResourceConfigCommon.rachConfigCommon.raSupervisionInfo
        .raResponseWindowSize = rc.raResponseWindowSize;
    Ptr<Packet> encodedHandoverCommand = m_rrcSapUser->EncodeHandoverCommand(handoverCommand);

    ackParams.rrcContext = encodedHandoverCommand;

    NS_LOG_LOGIC("Send X2 message: HANDOVER REQUEST ACK");

    NS_LOG_LOGIC("oldEnbUeX2apId = " << ackParams.oldEnbUeX2apId);
    NS_LOG_LOGIC("newEnbUeX2apId = " << ackParams.newEnbUeX2apId);
    NS_LOG_LOGIC("sourceCellId = " << ackParams.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << ackParams.targetCellId);

    m_x2SapProvider->SendHandoverRequestAck(ackParams);
}

void
LteEnbRrc::DoRecvHandoverRequestAck(EpcX2SapUser::HandoverRequestAckParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: HANDOVER REQUEST ACK");

    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("newEnbUeX2apId = " << params.newEnbUeX2apId);
    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);

    uint16_t rnti = params.oldEnbUeX2apId;
    Ptr<UeManager> ueManager = GetUeManager(rnti);
    ueManager->RecvHandoverRequestAck(params);
}

void
LteEnbRrc::DoRecvSecondaryCellHandoverCompleted(
    EpcX2SapUser::SecondaryHandoverCompletedParams params)
{
    NS_LOG_FUNCTION(this);

    NS_ASSERT_MSG(
        !m_ismmWave,
        "Only the LTE cell (coordinator) can receive a SecondaryCellHandoverCompleted message");
    NS_LOG_LOGIC("Recv X2 message: SECONDARY CELL HANDOVER COMPLETED");

    // get the RNTI from IMSI
    Ptr<UeManager> ueMan = GetUeManager(GetRntiFromImsi(params.imsi));
    ueMan->RecvSecondaryCellHandoverCompleted(params);
}

void
LteEnbRrc::DoRecvHandoverPreparationFailure(EpcX2SapUser::HandoverPreparationFailureParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: HANDOVER PREPARATION FAILURE");

    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("cause = " << params.cause);
    NS_LOG_LOGIC("criticalityDiagnostics = " << params.criticalityDiagnostics);

    uint16_t rnti = params.oldEnbUeX2apId;
    Ptr<UeManager> ueManager = GetUeManager(rnti);
    ueManager->RecvHandoverPreparationFailure(params.targetCellId);
}

void
LteEnbRrc::DoRecvSnStatusTransfer(EpcX2SapUser::SnStatusTransferParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: SN STATUS TRANSFER");

    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("newEnbUeX2apId = " << params.newEnbUeX2apId);
    NS_LOG_LOGIC("erabsSubjectToStatusTransferList size = "
                 << params.erabsSubjectToStatusTransferList.size());

    uint16_t rnti = params.newEnbUeX2apId;
    Ptr<UeManager> ueManager = GetUeManager(rnti);
    ueManager->RecvSnStatusTransfer(params);
}

void
LteEnbRrc::DoRecvUeContextRelease(EpcX2SapUser::UeContextReleaseParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: UE CONTEXT RELEASE");

    NS_LOG_LOGIC("oldEnbUeX2apId = " << params.oldEnbUeX2apId);
    NS_LOG_LOGIC("newEnbUeX2apId = " << params.newEnbUeX2apId);

    uint16_t rnti = params.oldEnbUeX2apId;

    if (m_interRatHoMode && m_ismmWave)
    {
        NS_LOG_INFO("Notify LTE eNB that the handover is completed from cell "
                    << m_cellId << " to " << params.sourceCellId);
        EpcX2Sap::SecondaryHandoverParams sendParams;
        sendParams.imsi = GetImsiFromRnti(rnti);
        sendParams.oldCellId = m_lteCellId;
        sendParams.targetCellId = params.sourceCellId;
        m_x2SapProvider->NotifyLteMmWaveHandoverCompleted(sendParams);
    }
    else if (m_interRatHoMode && !m_ismmWave)
    {
        NS_LOG_INFO("LTE eNB received UE context release from cell " << params.sourceCellId);
        m_lastMmWaveCell[GetImsiFromRnti(rnti)] = params.sourceCellId;
        m_mmWaveCellSetupCompleted[GetImsiFromRnti(rnti)] = true;
        m_imsiUsingLte[GetImsiFromRnti(rnti)] = false;
    }

    GetUeManager(rnti)->RecvUeContextRelease(params);
    RemoveUe(rnti);
}

void
LteEnbRrc::DoRecvLteMmWaveHandoverCompleted(EpcX2SapUser::SecondaryHandoverParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_INFO("Recv X2 message: NOTIFY MMWAVE HANDOVER COMPLETED "
                << m_interRatHoMode << " m_ismmWave " << m_ismmWave);

    if (m_interRatHoMode && !m_ismmWave)
    {
        uint64_t imsi = params.imsi;
        NS_LOG_INFO("LTE eNB received notification that MmWave handover is completed to cell "
                    << params.targetCellId);
        m_lastMmWaveCell[imsi] = params.targetCellId;
        if (params.targetCellId != m_cellId)
        {
            m_imsiUsingLte[imsi] = false;
            m_mmWaveCellSetupCompleted[imsi] = true;
        }
        else
        {
            // m_imsiUsingLte[imsi] = true;
            // if the LTE cell is the target of the Handover, it may still
            // be in the RRC RECONFIGURATION phase
            GetUeManager(GetRntiFromImsi(imsi))->RecvNotifyLteMmWaveHandoverCompleted();
            // m_mmWaveCellSetupCompleted[imsi] = true;
        }
    }
}

void
LteEnbRrc::DoRecvConnectionSwitchToMmWave(EpcX2SapUser::SwitchConnectionParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: SWITCH CONNECTION");

    GetUeManager(params.mmWaveRnti)
        ->RecvConnectionSwitchToMmWave(params.useMmWaveConnection, params.drbid);
}

void
LteEnbRrc::DoRecvLoadInformation(EpcX2SapUser::LoadInformationParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: LOAD INFORMATION");

    NS_LOG_LOGIC("Number of cellInformationItems = " << params.cellInformationList.size());

    m_ffrRrcSapProvider.at(0)->RecvLoadInformation(params);
}

void
LteEnbRrc::DoRecvResourceStatusUpdate(EpcX2SapUser::ResourceStatusUpdateParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: RESOURCE STATUS UPDATE");

    NS_LOG_LOGIC(
        "Number of cellMeasurementResultItems = " << params.cellMeasurementResultList.size());

    NS_ASSERT("Processing of RESOURCE STATUS UPDATE X2 message IS NOT IMPLEMENTED");
}

void
LteEnbRrc::DoRecvRlcSetupRequest(EpcX2SapUser::RlcSetupRequest params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: RLC SETUP REQUEST");

    GetUeManager(params.mmWaveRnti)->RecvRlcSetupRequest(params);
}

void
LteEnbRrc::DoRecvRlcSetupCompleted(EpcX2SapUser::UeDataParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv X2 message: RLC SETUP COMPLETED");

    std::map<uint32_t, X2uTeidInfo>::iterator teidInfoIt = m_x2uMcTeidInfoMap.find(params.gtpTeid);
    if (teidInfoIt != m_x2uMcTeidInfoMap.end())
    {
        GetUeManager(teidInfoIt->second.rnti)->RecvRlcSetupCompleted(teidInfoIt->second.drbid);
    }
    else
    {
        NS_FATAL_ERROR("No X2uMcTeidInfo found");
    }
}

void
LteEnbRrc::DoRecvUeData(EpcX2SapUser::UeDataParams params)
{
    NS_LOG_FUNCTION(this);

    NS_LOG_LOGIC("Recv UE DATA FORWARDING through X2 interface");
    NS_LOG_LOGIC("sourceCellId = " << params.sourceCellId);
    NS_LOG_LOGIC("targetCellId = " << params.targetCellId);
    NS_LOG_LOGIC("gtpTeid = " << params.gtpTeid);
    NS_LOG_LOGIC("ueData = " << params.ueData);
    NS_LOG_LOGIC("ueData size = " << params.ueData->GetSize());

    std::map<uint32_t, X2uTeidInfo>::iterator teidInfoIt = m_x2uTeidInfoMap.find(params.gtpTeid);
    if (teidInfoIt != m_x2uTeidInfoMap.end())
    {
        GetUeManager(teidInfoIt->second.rnti)->SendData(teidInfoIt->second.drbid, params.ueData);
    }
    else
    {
        teidInfoIt = m_x2uMcTeidInfoMap.find(params.gtpTeid);
        if (teidInfoIt != m_x2uMcTeidInfoMap.end())
        {
            GetUeManager(teidInfoIt->second.rnti)
                ->SendData(teidInfoIt->second.drbid, params.ueData);
        }
        else
        {
            NS_FATAL_ERROR("X2-U data received but no X2uTeidInfo found");
        }
    }
}

uint16_t
LteEnbRrc::DoAllocateTemporaryCellRnti(uint8_t componentCarrierId)
{
    NS_LOG_FUNCTION(this << +componentCarrierId);
    return AddUe(UeManager::INITIAL_RANDOM_ACCESS, componentCarrierId);
}

void
LteEnbRrc::DoRrcConfigurationUpdateInd(LteEnbCmacSapUser::UeConfig cmacParams)
{
    Ptr<UeManager> ueManager = GetUeManager(cmacParams.m_rnti);
    ueManager->CmacUeConfigUpdateInd(cmacParams);
}

void
LteEnbRrc::DoNotifyLcConfigResult(uint16_t rnti, uint8_t lcid, bool success)
{
    NS_LOG_FUNCTION(this << (uint32_t)rnti);
    NS_FATAL_ERROR("not implemented");
}

uint8_t
LteEnbRrc::DoAddUeMeasReportConfigForHandover(LteRrcSap::ReportConfigEutra reportConfig)
{
    NS_LOG_FUNCTION(this);
    uint8_t measId = AddUeMeasReportConfig(reportConfig);
    m_handoverMeasIds.insert(measId);
    return measId;
}

uint8_t
LteEnbRrc::DoAddUeMeasReportConfigForComponentCarrier(LteRrcSap::ReportConfigEutra reportConfig)
{
    NS_LOG_FUNCTION(this);
    uint8_t measId = AddUeMeasReportConfig(reportConfig);
    m_componentCarrierMeasIds.insert(measId);
    return measId;
}

void
LteEnbRrc::DoSetNumberOfComponentCarriers(uint16_t numberOfComponentCarriers)
{
    m_numberOfComponentCarriers = numberOfComponentCarriers;
}

void
LteEnbRrc::DoTriggerHandover(uint16_t rnti, uint16_t targetCellId)
{
    NS_LOG_FUNCTION(this << rnti << targetCellId);

    bool isHandoverAllowed = true;

    Ptr<UeManager> ueManager = GetUeManager(rnti);
    NS_ASSERT_MSG(ueManager, "Cannot find UE context with RNTI " << rnti);

    if (m_anrSapProvider != 0)
    {
        // ensure that proper neighbour relationship exists between source and target cells
        bool noHo = m_anrSapProvider->GetNoHo(targetCellId);
        bool noX2 = m_anrSapProvider->GetNoX2(targetCellId);
        NS_LOG_DEBUG(this << " cellId="
                          << ComponentCarrierToCellId(ueManager->GetComponentCarrierId())
                          << " targetCellId=" << targetCellId << " NRT.NoHo=" << noHo
                          << " NRT.NoX2=" << noX2);

        if (noHo || noX2)
        {
            isHandoverAllowed = false;
            NS_LOG_LOGIC(this << " handover to cell " << targetCellId << " is not allowed by ANR");
        }
    }

    if (ueManager->GetState() != UeManager::CONNECTED_NORMALLY)
    {
        isHandoverAllowed = false;
        NS_LOG_LOGIC(this << " handover is not allowed because the UE"
                          << " rnti=" << rnti << " is in " << ToString(ueManager->GetState())
                          << " state");
    }

    if (isHandoverAllowed)
    {
        // initiate handover execution
        ueManager->PrepareHandover(targetCellId);
    }
}

uint8_t
LteEnbRrc::DoAddUeMeasReportConfigForAnr(LteRrcSap::ReportConfigEutra reportConfig)
{
    NS_LOG_FUNCTION(this);
    uint8_t measId = AddUeMeasReportConfig(reportConfig);
    m_anrMeasIds.insert(measId);
    return measId;
}

uint8_t
LteEnbRrc::DoAddUeMeasReportConfigForFfr(LteRrcSap::ReportConfigEutra reportConfig)
{
    NS_LOG_FUNCTION(this);
    uint8_t measId = AddUeMeasReportConfig(reportConfig);
    m_ffrMeasIds.insert(measId);
    return measId;
}

void
LteEnbRrc::DoSetPdschConfigDedicated(uint16_t rnti,
                                     LteRrcSap::PdschConfigDedicated pdschConfigDedicated)
{
    NS_LOG_FUNCTION(this);
    Ptr<UeManager> ueManager = GetUeManager(rnti);
    ueManager->SetPdschConfigDedicated(pdschConfigDedicated);
}

void
LteEnbRrc::DoSendLoadInformation(EpcX2Sap::LoadInformationParams params)
{
    NS_LOG_FUNCTION(this);

    m_x2SapProvider->SendLoadInformation(params);
}

uint16_t
LteEnbRrc::AddUe(UeManager::State state, uint8_t componentCarrierId)
{
    NS_LOG_FUNCTION(this);
    bool found = false;
    uint16_t rnti;
    for (rnti = m_lastAllocatedRnti + 1; (rnti != m_lastAllocatedRnti - 1) && (!found); ++rnti)
    {
        if ((rnti != 0) && (m_ueMap.find(rnti) == m_ueMap.end()))
        {
            found = true;
            break;
        }
    }

    NS_ASSERT_MSG(found, "no more RNTIs available (do you have more than 65535 UEs in a cell?)");
    m_lastAllocatedRnti = rnti;
    Ptr<UeManager> ueManager = CreateObject<UeManager>(this, rnti, state, componentCarrierId);
    m_ccmRrcSapProvider->AddUe(rnti, (uint8_t)state);
    m_ueMap.insert(std::pair<uint16_t, Ptr<UeManager>>(rnti, ueManager));
    ueManager->Initialize();
    const uint16_t cellId = ComponentCarrierToCellId(componentCarrierId);
    NS_LOG_DEBUG(this << " New UE RNTI " << rnti << " cellId " << cellId << " srs CI "
                      << ueManager->GetSrsConfigurationIndex());
    m_newUeContextTrace(cellId, rnti);
    return rnti;
}

void
LteEnbRrc::RemoveUe(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << (uint32_t)rnti);
    std::map<uint16_t, Ptr<UeManager>>::iterator it = m_ueMap.find(rnti);
    NS_ASSERT_MSG(it != m_ueMap.end(), "request to remove UE info with unknown rnti " << rnti);
    uint16_t srsCi = (*it).second->GetSrsConfigurationIndex();
    bool isMc = it->second->GetIsMc();

    m_ueMap.erase(it);
    for (uint8_t i = 0; i < m_numberOfComponentCarriers; i++)
    {
        m_cmacSapProvider.at(i)->RemoveUe(rnti);
        m_cphySapProvider.at(i)->RemoveUe(rnti);
    }
    if (m_s1SapProvider != 0 && !isMc)
    {
        m_s1SapProvider->UeContextRelease(rnti);
    }
    m_ccmRrcSapProvider->RemoveUe(rnti);
    // need to do this after UeManager has been deleted
    RemoveSrsConfigurationIndex(srsCi);
}

TypeId
LteEnbRrc::GetRlcType(EpsBearer bearer)
{
    switch (m_epsBearerToRlcMapping)
    {
    case RLC_SM_ALWAYS:
        return LteRlcSm::GetTypeId();
        break;

    case RLC_UM_ALWAYS:
        return LteRlcUm::GetTypeId();
        break;

    case RLC_AM_ALWAYS:
        return LteRlcAm::GetTypeId();
        break;

    case PER_BASED:
        if (bearer.GetPacketErrorLossRate() > 1.0e-5)
        {
            return LteRlcUm::GetTypeId();
        }
        else
        {
            return LteRlcAm::GetTypeId();
        }
        break;

    case RLC_UM_LOWLAT_ALWAYS:
        return LteRlcUmLowLat::GetTypeId();
        break;

    default:
        return LteRlcSm::GetTypeId();
        break;
    }
}

void
LteEnbRrc::AddX2Neighbour(uint16_t cellId)
{
    NS_LOG_FUNCTION(this << cellId);

    if (m_anrSapProvider != 0)
    {
        m_anrSapProvider->AddNeighbourRelation(cellId);
    }
}

void
LteEnbRrc::SetCsgId(uint32_t csgId, bool csgIndication)
{
    NS_LOG_FUNCTION(this << csgId << csgIndication);
    for (uint8_t componentCarrierId = 0; componentCarrierId < m_sib1.size(); componentCarrierId++)
    {
        m_sib1.at(componentCarrierId).cellAccessRelatedInfo.csgIdentity = csgId;
        m_sib1.at(componentCarrierId).cellAccessRelatedInfo.csgIndication = csgIndication;
        m_cphySapProvider.at(componentCarrierId)
            ->SetSystemInformationBlockType1(m_sib1.at(componentCarrierId));
    }
}

/// Number of distinct SRS periodicity plus one.
static const uint8_t SRS_ENTRIES = 9;
/**
 * Sounding Reference Symbol (SRS) periodicity (TSRS) in milliseconds. Taken
 * from 3GPP TS 36.213 Table 8.2-1. Index starts from 1.
 */
static const uint16_t g_srsPeriodicity[SRS_ENTRIES] = {0, 2, 5, 10, 20, 40, 80, 160, 320};
/**
 * The lower bound (inclusive) of the SRS configuration indices (ISRS) which
 * use the corresponding SRS periodicity (TSRS). Taken from 3GPP TS 36.213
 * Table 8.2-1. Index starts from 1.
 */
static const uint16_t g_srsCiLow[SRS_ENTRIES] = {0, 0, 2, 7, 17, 37, 77, 157, 317};
/**
 * The upper bound (inclusive) of the SRS configuration indices (ISRS) which
 * use the corresponding SRS periodicity (TSRS). Taken from 3GPP TS 36.213
 * Table 8.2-1. Index starts from 1.
 */
static const uint16_t g_srsCiHigh[SRS_ENTRIES] = {0, 1, 6, 16, 36, 76, 156, 316, 636};

void
LteEnbRrc::SetSrsPeriodicity(uint32_t p)
{
    NS_LOG_FUNCTION(this << p);
    for (uint32_t id = 1; id < SRS_ENTRIES; ++id)
    {
        if (g_srsPeriodicity[id] == p)
        {
            m_srsCurrentPeriodicityId = id;
            return;
        }
    }
    // no match found
    std::ostringstream allowedValues;
    for (uint32_t id = 1; id < SRS_ENTRIES; ++id)
    {
        allowedValues << g_srsPeriodicity[id] << " ";
    }
    NS_FATAL_ERROR("illecit SRS periodicity value " << p
                                                    << ". Allowed values: " << allowedValues.str());
}

uint32_t
LteEnbRrc::GetSrsPeriodicity() const
{
    NS_LOG_FUNCTION(this);
    NS_ASSERT(m_srsCurrentPeriodicityId > 0);
    NS_ASSERT(m_srsCurrentPeriodicityId < SRS_ENTRIES);
    return g_srsPeriodicity[m_srsCurrentPeriodicityId];
}

uint16_t
LteEnbRrc::GetNewSrsConfigurationIndex()
{
    NS_LOG_FUNCTION(this << m_ueSrsConfigurationIndexSet.size());
    // SRS
    NS_ASSERT(m_srsCurrentPeriodicityId > 0);
    NS_ASSERT(m_srsCurrentPeriodicityId < SRS_ENTRIES);
    NS_LOG_DEBUG(this << " SRS p " << g_srsPeriodicity[m_srsCurrentPeriodicityId] << " set "
                      << m_ueSrsConfigurationIndexSet.size());
    if (m_ueSrsConfigurationIndexSet.size() >= g_srsPeriodicity[m_srsCurrentPeriodicityId])
    {
        NS_FATAL_ERROR("too many UEs ("
                       << m_ueSrsConfigurationIndexSet.size() + 1
                       << ") for current SRS periodicity "
                       << g_srsPeriodicity[m_srsCurrentPeriodicityId]
                       << ", consider increasing the value of ns3::LteEnbRrc::SrsPeriodicity");
    }

    if (m_ueSrsConfigurationIndexSet.empty())
    {
        // first entry
        m_lastAllocatedConfigurationIndex = g_srsCiLow[m_srsCurrentPeriodicityId];
        m_ueSrsConfigurationIndexSet.insert(m_lastAllocatedConfigurationIndex);
    }
    else
    {
        // find a CI from the available ones
        std::set<uint16_t>::reverse_iterator rit = m_ueSrsConfigurationIndexSet.rbegin();
        NS_ASSERT(rit != m_ueSrsConfigurationIndexSet.rend());
        NS_LOG_DEBUG(this << " lower bound " << (*rit) << " of "
                          << g_srsCiHigh[m_srsCurrentPeriodicityId]);
        if ((*rit) < g_srsCiHigh[m_srsCurrentPeriodicityId])
        {
            // got it from the upper bound
            m_lastAllocatedConfigurationIndex = (*rit) + 1;
            m_ueSrsConfigurationIndexSet.insert(m_lastAllocatedConfigurationIndex);
        }
        else
        {
            // look for released ones
            for (uint16_t srcCi = g_srsCiLow[m_srsCurrentPeriodicityId];
                 srcCi < g_srsCiHigh[m_srsCurrentPeriodicityId];
                 srcCi++)
            {
                std::set<uint16_t>::iterator it = m_ueSrsConfigurationIndexSet.find(srcCi);
                if (it == m_ueSrsConfigurationIndexSet.end())
                {
                    m_lastAllocatedConfigurationIndex = srcCi;
                    m_ueSrsConfigurationIndexSet.insert(srcCi);
                    break;
                }
            }
        }
    }
    return m_lastAllocatedConfigurationIndex;
}

void
LteEnbRrc::RemoveSrsConfigurationIndex(uint16_t srcCi)
{
    NS_LOG_FUNCTION(this << srcCi);
    std::set<uint16_t>::iterator it = m_ueSrsConfigurationIndexSet.find(srcCi);
    NS_ASSERT_MSG(it != m_ueSrsConfigurationIndexSet.end(),
                  "request to remove unkwown SRS CI " << srcCi);
    m_ueSrsConfigurationIndexSet.erase(it);
}

uint8_t
LteEnbRrc::GetLogicalChannelGroup(EpsBearer bearer)
{
    if (bearer.IsGbr())
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

uint8_t
LteEnbRrc::GetLogicalChannelGroup(bool isGbr)
{
    if (isGbr)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

uint8_t
LteEnbRrc::GetLogicalChannelPriority(EpsBearer bearer)
{
    return bearer.qci;
}

void
LteEnbRrc::SendSystemInformation()
{
    NS_LOG_FUNCTION(this);

    if (!m_ismmWave)
    {
        for (auto& it : m_componentCarrierPhyConf)
        {
            uint8_t ccId = it.first;

            LteRrcSap::SystemInformation si;
            si.haveSib2 = true;
            si.sib2.freqInfo.ulCarrierFreq = it.second->GetUlEarfcn();
            si.sib2.freqInfo.ulBandwidth = it.second->GetUlBandwidth();
            si.sib2.radioResourceConfigCommon.pdschConfigCommon.referenceSignalPower =
                m_cphySapProvider.at(ccId)->GetReferenceSignalPower();
            si.sib2.radioResourceConfigCommon.pdschConfigCommon.pb = 0;

            LteEnbCmacSapProvider::RachConfig rc = m_cmacSapProvider.at(ccId)->GetRachConfig();
            LteRrcSap::RachConfigCommon rachConfigCommon;
            rachConfigCommon.preambleInfo.numberOfRaPreambles = rc.numberOfRaPreambles;
            rachConfigCommon.raSupervisionInfo.preambleTransMax = rc.preambleTransMax;
            rachConfigCommon.raSupervisionInfo.raResponseWindowSize = rc.raResponseWindowSize;
            si.sib2.radioResourceConfigCommon.rachConfigCommon = rachConfigCommon;

            m_rrcSapUser->SendSystemInformation(it.second->GetCellId(), si);
        }
    }
    else
    {
        for (auto& it : m_mmWaveComponentCarrierPhyConf)
        {
            uint8_t ccId = it.first;

            LteRrcSap::SystemInformation si;
            si.haveSib2 = true;
            // si.sib2.freqInfo.ulCarrierFreq = it.second->GetUlEarfcn ();
            si.sib2.freqInfo.ulBandwidth = it.second.m_bandwidth;
            si.sib2.radioResourceConfigCommon.pdschConfigCommon.referenceSignalPower =
                m_cphySapProvider.at(ccId)->GetReferenceSignalPower();
            si.sib2.radioResourceConfigCommon.pdschConfigCommon.pb = 0;

            LteEnbCmacSapProvider::RachConfig rc = m_cmacSapProvider.at(ccId)->GetRachConfig();
            LteRrcSap::RachConfigCommon rachConfigCommon;
            rachConfigCommon.preambleInfo.numberOfRaPreambles = rc.numberOfRaPreambles;
            rachConfigCommon.raSupervisionInfo.preambleTransMax = rc.preambleTransMax;
            rachConfigCommon.raSupervisionInfo.raResponseWindowSize = rc.raResponseWindowSize;
            si.sib2.radioResourceConfigCommon.rachConfigCommon = rachConfigCommon;

            m_rrcSapUser->SendSystemInformation(it.second.m_cellId, si);
        }
    }

    /*
     * For simplicity, we use the same periodicity for all SIBs. Note that in real
     * systems the periodicy of each SIBs could be different.
     */
    Simulator::Schedule(m_systemInformationPeriodicity, &LteEnbRrc::SendSystemInformation, this);
}

} // namespace ns3
