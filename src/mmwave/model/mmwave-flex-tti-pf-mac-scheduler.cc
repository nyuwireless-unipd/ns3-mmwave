/*
 * mmwave-rr-mac-scheduler.cc
 *
 *  Created on: Jan 11, 2015
 *      Author: sourjya
 */

#include "mmwave-flex-tti-pf-mac-scheduler.h"

#include "mmwave-mac-pdu-header.h"
#include "mmwave-mac-pdu-tag.h"
#include "mmwave-spectrum-value-helper.h"

#include <ns3/abort.h>
#include <ns3/boolean.h>
#include <ns3/eps-bearer.h>
#include <ns3/log.h>
#include <ns3/lte-common.h>

#include <algorithm>
#include <cmath>
#include <stdlib.h> /* abs */

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWaveFlexTtiPfMacScheduler");

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWaveFlexTtiPfMacScheduler);

class MmWaveFlexTtiPfMacCschedSapProvider : public MmWaveMacCschedSapProvider
{
  public:
    MmWaveFlexTtiPfMacCschedSapProvider(MmWaveFlexTtiPfMacScheduler* scheduler);

    // inherited from MmWaveMacCschedSapProvider
    virtual void CschedCellConfigReq(
        const struct MmWaveMacCschedSapProvider::CschedCellConfigReqParameters& params);
    virtual void CschedUeConfigReq(
        const struct MmWaveMacCschedSapProvider::CschedUeConfigReqParameters& params);
    virtual void CschedLcConfigReq(
        const struct MmWaveMacCschedSapProvider::CschedLcConfigReqParameters& params);
    virtual void CschedLcReleaseReq(
        const struct MmWaveMacCschedSapProvider::CschedLcReleaseReqParameters& params);
    virtual void CschedUeReleaseReq(
        const struct MmWaveMacCschedSapProvider::CschedUeReleaseReqParameters& params);

  private:
    MmWaveFlexTtiPfMacCschedSapProvider();
    MmWaveFlexTtiPfMacScheduler* m_scheduler;
};

MmWaveFlexTtiPfMacCschedSapProvider::MmWaveFlexTtiPfMacCschedSapProvider()
{
}

MmWaveFlexTtiPfMacCschedSapProvider::MmWaveFlexTtiPfMacCschedSapProvider(
    MmWaveFlexTtiPfMacScheduler* scheduler)
    : m_scheduler(scheduler)
{
}

void
MmWaveFlexTtiPfMacCschedSapProvider::CschedCellConfigReq(
    const struct MmWaveMacCschedSapProvider::CschedCellConfigReqParameters& params)
{
    m_scheduler->DoCschedCellConfigReq(params);
}

void
MmWaveFlexTtiPfMacCschedSapProvider::CschedUeConfigReq(
    const struct MmWaveMacCschedSapProvider::CschedUeConfigReqParameters& params)
{
    m_scheduler->DoCschedUeConfigReq(params);
}

void
MmWaveFlexTtiPfMacCschedSapProvider::CschedLcConfigReq(
    const struct MmWaveMacCschedSapProvider::CschedLcConfigReqParameters& params)
{
    m_scheduler->DoCschedLcConfigReq(params);
}

void
MmWaveFlexTtiPfMacCschedSapProvider::CschedLcReleaseReq(
    const struct MmWaveMacCschedSapProvider::CschedLcReleaseReqParameters& params)
{
    m_scheduler->DoCschedLcReleaseReq(params);
}

void
MmWaveFlexTtiPfMacCschedSapProvider::CschedUeReleaseReq(
    const struct MmWaveMacCschedSapProvider::CschedUeReleaseReqParameters& params)
{
    m_scheduler->DoCschedUeReleaseReq(params);
}

class MmWaveFlexTtiPfMacSchedSapProvider : public MmWaveMacSchedSapProvider
{
  public:
    MmWaveFlexTtiPfMacSchedSapProvider(MmWaveFlexTtiPfMacScheduler* sched);

    virtual void SchedDlRlcBufferReq(
        const struct MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters& params);
    virtual void SchedTriggerReq(
        const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params);
    virtual void SchedDlCqiInfoReq(
        const struct MmWaveMacSchedSapProvider::SchedDlCqiInfoReqParameters& params);
    virtual void SchedUlCqiInfoReq(
        const struct MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters& params);
    virtual void SchedUlMacCtrlInfoReq(
        const struct MmWaveMacSchedSapProvider::SchedUlMacCtrlInfoReqParameters& params);
    virtual void SchedSetMcs(int mcs);

  private:
    MmWaveFlexTtiPfMacSchedSapProvider();
    MmWaveFlexTtiPfMacScheduler* m_scheduler;
};

MmWaveFlexTtiPfMacSchedSapProvider::MmWaveFlexTtiPfMacSchedSapProvider()
{
}

MmWaveFlexTtiPfMacSchedSapProvider::MmWaveFlexTtiPfMacSchedSapProvider(
    MmWaveFlexTtiPfMacScheduler* sched)
    : m_scheduler(sched)
{
}

void
MmWaveFlexTtiPfMacSchedSapProvider::SchedDlRlcBufferReq(
    const struct MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters& params)
{
    m_scheduler->DoSchedDlRlcBufferReq(params);
}

void
MmWaveFlexTtiPfMacSchedSapProvider::SchedTriggerReq(
    const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params)
{
    m_scheduler->DoSchedTriggerReq(params);
}

void
MmWaveFlexTtiPfMacSchedSapProvider::SchedDlCqiInfoReq(
    const struct MmWaveMacSchedSapProvider::SchedDlCqiInfoReqParameters& params)
{
    m_scheduler->DoSchedDlCqiInfoReq(params);
}

void
MmWaveFlexTtiPfMacSchedSapProvider::SchedUlCqiInfoReq(
    const struct MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters& params)
{
    m_scheduler->DoSchedUlCqiInfoReq(params);
}

void
MmWaveFlexTtiPfMacSchedSapProvider::SchedUlMacCtrlInfoReq(
    const struct MmWaveMacSchedSapProvider::SchedUlMacCtrlInfoReqParameters& params)
{
    m_scheduler->DoSchedUlMacCtrlInfoReq(params);
}

void
MmWaveFlexTtiPfMacSchedSapProvider::SchedSetMcs(int mcs)
{
    m_scheduler->DoSchedSetMcs(mcs);
}

const unsigned MmWaveFlexTtiPfMacScheduler::m_macHdrSize = 0;
const unsigned MmWaveFlexTtiPfMacScheduler::m_subHdrSize = 4;
const unsigned MmWaveFlexTtiPfMacScheduler::m_rlcHdrSize = 3;

MmWaveFlexTtiPfMacScheduler::MmWaveFlexTtiPfMacScheduler()
    : m_nextRnti(0),
      m_tbUid(0),
      m_macSchedSapUser(0),
      m_macCschedSapUser(0),
      m_timeWindow(99.0)
{
    NS_LOG_FUNCTION(this);
    m_macSchedSapProvider = new MmWaveFlexTtiPfMacSchedSapProvider(this);
    m_macCschedSapProvider = new MmWaveFlexTtiPfMacCschedSapProvider(this);
}

MmWaveFlexTtiPfMacScheduler::~MmWaveFlexTtiPfMacScheduler()
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveFlexTtiPfMacScheduler::DoDispose(void)
{
    NS_LOG_FUNCTION(this);
    m_wbCqiRxed.clear();
    m_dlHarqProcessesDciInfoMap.clear();
    m_dlHarqProcessesTimer.clear();
    m_dlHarqProcessesRlcPduMap.clear();
    m_dlHarqInfoList.clear();
    m_ulHarqCurrentProcessId.clear();
    m_ulHarqProcessesStatus.clear();
    m_ulHarqProcessesTimer.clear();
    m_ulHarqProcessesDciInfoMap.clear();
    delete m_macCschedSapProvider;
    delete m_macSchedSapProvider;
}

TypeId
MmWaveFlexTtiPfMacScheduler::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveFlexTtiPfMacScheduler")
            .SetParent<MmWaveMacScheduler>()
            .AddConstructor<MmWaveFlexTtiPfMacScheduler>()
            .AddAttribute("CqiTimerThreshold",
                          "The number of TTIs a CQI is valid (default 1000 - 1 sec.)",
                          UintegerValue(100),
                          MakeUintegerAccessor(&MmWaveFlexTtiPfMacScheduler::m_cqiTimersThreshold),
                          MakeUintegerChecker<uint32_t>())
            .AddAttribute("HarqEnabled",
                          "Activate/Deactivate the HARQ [by default is active].",
                          BooleanValue(false),
                          MakeBooleanAccessor(&MmWaveFlexTtiPfMacScheduler::m_harqOn),
                          MakeBooleanChecker())
            .AddAttribute("FixedMcsDl",
                          "Fix MCS to value set in McsDlDefault",
                          BooleanValue(false),
                          MakeBooleanAccessor(&MmWaveFlexTtiPfMacScheduler::m_fixedMcsDl),
                          MakeBooleanChecker())
            .AddAttribute("McsDefaultDl",
                          "Fixed DL MCS",
                          UintegerValue(1),
                          MakeUintegerAccessor(&MmWaveFlexTtiPfMacScheduler::m_mcsDefaultDl),
                          MakeUintegerChecker<uint8_t>())
            .AddAttribute("FixedMcsUl",
                          "Fix MCS to value set in McsUlDefault (for testing)",
                          BooleanValue(false),
                          MakeBooleanAccessor(&MmWaveFlexTtiPfMacScheduler::m_fixedMcsUl),
                          MakeBooleanChecker())
            .AddAttribute("McsDefaultUl",
                          "Fixed UL MCS (for testing)",
                          UintegerValue(1),
                          MakeUintegerAccessor(&MmWaveFlexTtiPfMacScheduler::m_mcsDefaultUl),
                          MakeUintegerChecker<uint8_t>())
            .AddAttribute("DlSchedOnly",
                          "Only schedule downlink traffic (for testing)",
                          BooleanValue(false),
                          MakeBooleanAccessor(&MmWaveFlexTtiPfMacScheduler::m_dlOnly),
                          MakeBooleanChecker())
            .AddAttribute("UlSchedOnly",
                          "Only schedule uplink traffic (for testing)",
                          BooleanValue(false),
                          MakeBooleanAccessor(&MmWaveFlexTtiPfMacScheduler::m_ulOnly),
                          MakeBooleanChecker())
            .AddAttribute("FixedTti",
                          "Fix slot size",
                          BooleanValue(false),
                          MakeBooleanAccessor(&MmWaveFlexTtiPfMacScheduler::m_fixedTti),
                          MakeBooleanChecker())
            .AddAttribute("SymPerSlot",
                          "Number of symbols per slot in Fixed TTI mode",
                          UintegerValue(6),
                          MakeUintegerAccessor(&MmWaveFlexTtiPfMacScheduler::m_symPerSlot),
                          MakeUintegerChecker<uint8_t>());

    return tid;
}

void
MmWaveFlexTtiPfMacScheduler::SetMacSchedSapUser(MmWaveMacSchedSapUser* sap)
{
    m_macSchedSapUser = sap;
}

void
MmWaveFlexTtiPfMacScheduler::SetMacCschedSapUser(MmWaveMacCschedSapUser* sap)
{
    m_macCschedSapUser = sap;
}

MmWaveMacSchedSapProvider*
MmWaveFlexTtiPfMacScheduler::GetMacSchedSapProvider()
{
    return m_macSchedSapProvider;
}

MmWaveMacCschedSapProvider*
MmWaveFlexTtiPfMacScheduler::GetMacCschedSapProvider()
{
    return m_macCschedSapProvider;
}

void
MmWaveFlexTtiPfMacScheduler::ConfigureCommonParameters(Ptr<MmWavePhyMacCommon> config)
{
    m_phyMacConfig = config;
    m_amc = CreateObject<MmWaveAmc>(m_phyMacConfig);
    m_numHarqProcess = m_phyMacConfig->GetNumHarqProcess();
    m_harqTimeout = m_phyMacConfig->GetHarqTimeout();
    m_numDataSymbols = m_phyMacConfig->GetSymbPerSlot() - m_phyMacConfig->GetDlCtrlSymbols() -
                       m_phyMacConfig->GetUlCtrlSymbols();

    for (unsigned i = 0; i < m_phyMacConfig->GetUlSchedDelay(); i++)
    {
        m_ulSfAllocInfo.push_back(SlotAllocInfo(SfnSf(0, i, 0)));
    }
}

void
MmWaveFlexTtiPfMacScheduler::DoSchedDlRlcBufferReq(
    const struct MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters& params)
{
    NS_LOG_FUNCTION(this << params.m_rnti << (uint32_t)params.m_logicalChannelIdentity);
    std::map<uint16_t, struct UeSchedInfo>::iterator itUe = m_ueSchedInfoMap.find(params.m_rnti);
    if (itUe == m_ueSchedInfoMap.end())
    {
        NS_LOG_ERROR("UE entry not found in sched info map");
    }
    else
    {
        uint8_t lcid = params.m_logicalChannelIdentity;
        if ((unsigned)lcid >= itUe->second.m_flowStatsDl.size())
        {
            NS_LOG_ERROR("LC not registered");
        }
        else
        {
            if (params.m_txPacketSizes.size() > 0)
            {
                itUe->second.m_flowStatsDl[lcid].m_txPacketSizes.clear();
                itUe->second.m_flowStatsDl[lcid].m_txPacketDelays.clear();
                // add the new DL PDCP packet sizes and their delays
                uint32_t totalSize = 0;
                double maxDelay = 0.0;
                std::list<uint32_t>::const_iterator itSize = params.m_txPacketSizes.begin();
                std::list<double>::const_iterator itDelay = params.m_txPacketDelays.begin();
                while (itSize != params.m_txPacketSizes.end() &&
                       itDelay != params.m_txPacketDelays.end())
                {
                    totalSize += *itSize;
                    if (totalSize > itUe->second.m_flowStatsDl[lcid].m_totalSchedSize)
                    {
                        //                                      uint32_t diff = totalSize -
                        //                                      itUe->second.m_flowStatsDl[lcid].m_totalSchedSize;
                        //                                      if (diff > *itSize)
                        //                                      {
                        //                                              itUe->second.m_flowStatsDl[lcid].m_txPacketSizes.push_back
                        //                                              (*itSize);
                        //                                              itUe->second.m_flowStatsDl[lcid].m_totalBufSize
                        //                                              += *itSize;
                        //                                      }
                        //                                      else
                        //                                      {
                        //                                              itUe->second.m_flowStatsDl[lcid].m_txPacketSizes.push_back
                        //                                              (diff);
                        //                                              itUe->second.m_flowStatsDl[lcid].m_totalBufSize
                        //                                              += diff;
                        //                                      }
                        itUe->second.m_flowStatsDl[lcid].m_totalBufSize =
                            params.m_rlcTransmissionQueueSize;
                        itUe->second.m_flowStatsDl[lcid].m_txPacketSizes.push_back(*itSize);
                        itUe->second.m_flowStatsDl[lcid].m_txPacketDelays.push_back(*itDelay);
                        if (*itDelay > maxDelay)
                        {
                            maxDelay = *itDelay;
                        }
                    }
                    itSize++;
                    itDelay++;
                }
                itUe->second.m_flowStatsDl[lcid].m_txQueueHolDelay = maxDelay;
            }
            else if (params.m_rlcTransmissionQueueSize > 0) // case for RlcSm
            {
                itUe->second.m_flowStatsDl[lcid].m_totalBufSize = params.m_rlcTransmissionQueueSize;
            }
        }
    }
}

void
MmWaveFlexTtiPfMacScheduler::DoSchedUlMacCtrlInfoReq(
    const struct MmWaveMacSchedSapProvider::SchedUlMacCtrlInfoReqParameters& params)
{
    NS_LOG_FUNCTION(this);

    std::map<uint16_t, uint32_t>::iterator it;

    for (unsigned int i = 0; i < params.m_macCeList.size(); i++)
    {
        if (params.m_macCeList.at(i).m_macCeType == MacCeElement::BSR)
        {
            // buffer status report
            // note that this scheduler does not differentiate the
            // allocation according to which LCGs have more/less bytes
            // to send.
            // Hence the BSR of different LCGs are just summed up to get
            // a total queue size that is used for allocation purposes.
            uint16_t rnti = params.m_macCeList.at(i).m_rnti;
            std::map<uint16_t, struct UeSchedInfo>::iterator itUe = m_ueSchedInfoMap.find(rnti);

            uint32_t buffer = 0;
            for (uint8_t lcg = 1; lcg <= 3; ++lcg)
            {
                uint8_t bsrId = params.m_macCeList.at(i).m_macCeValue.m_bufferStatus.at(lcg - 1);
                uint32_t bufSize = BsrId2BufferSize(bsrId);
                if (bufSize > 0)
                {
                    buffer += bufSize;

                    if (itUe == m_ueSchedInfoMap.end())
                    {
                        NS_LOG_ERROR("UE entry not found in sched info map");
                    }
                    else
                    {
                        int diff = bufSize - (itUe->second.m_flowStatsUl[lcg].m_totalBufSize +
                                              itUe->second.m_flowStatsUl[lcg].m_totalSchedSize);
                        if (diff > 0)
                        { // estimate additional packet sizes
                            itUe->second.m_flowStatsUl[lcg].m_totalBufSize += diff;
                            itUe->second.m_flowStatsUl[lcg].m_txPacketSizes.push_back(diff);
                            // since we expect the BSR to be generated following a packet arrival
                            // and sent at least by the end of the prev. subframe, the maximum delay
                            // is one SF (in microseconds)
                            itUe->second.m_flowStatsUl[lcg].m_txPacketDelays.push_back(
                                m_phyMacConfig->GetSlotPeriod().GetMicroSeconds());
                            if (itUe->second.m_flowStatsUl[lcg].m_txQueueHolDelay == 0)
                            {
                                itUe->second.m_flowStatsUl[lcg].m_txQueueHolDelay =
                                    m_phyMacConfig->GetSlotPeriod().GetMicroSeconds();
                            }
                        }
                    }
                }
            }
        }
    }

    return;
}

void
MmWaveFlexTtiPfMacScheduler::DoSchedDlCqiInfoReq(
    const struct MmWaveMacSchedSapProvider::SchedDlCqiInfoReqParameters& params)
{
    NS_LOG_FUNCTION(this);

    std::map<uint16_t, uint8_t>::iterator it;
    for (unsigned int i = 0; i < params.m_cqiList.size(); i++)
    {
        if (params.m_cqiList.at(i).m_cqiType == DlCqiInfo::WB)
        {
            // wideband CQI reporting
            std::map<uint16_t, uint8_t>::iterator it;
            uint16_t rnti = params.m_cqiList.at(i).m_rnti;
            it = m_wbCqiRxed.find(rnti);
            if (it == m_wbCqiRxed.end())
            {
                // create the new entry
                m_wbCqiRxed.insert(std::pair<uint16_t, uint8_t>(
                    rnti,
                    params.m_cqiList.at(i).m_wbCqi)); // only codeword 0 at this stage (SISO)
                // generate correspondent timer
                m_wbCqiTimers.insert(std::pair<uint16_t, uint32_t>(rnti, m_cqiTimersThreshold));
            }
            else
            {
                // update the CQI value
                (*it).second = params.m_cqiList.at(i).m_wbCqi;
                // update correspondent timer
                std::map<uint16_t, uint32_t>::iterator itTimers;
                itTimers = m_wbCqiTimers.find(rnti);
                (*itTimers).second = m_cqiTimersThreshold;
            }
        }
        else if (params.m_cqiList.at(i).m_cqiType == DlCqiInfo::SB)
        {
            // subband CQI reporting high layer configured
            // Not used by RR Scheduler
        }
        else
        {
            NS_LOG_ERROR(this << " CQI type unknown");
        }
    }
}

void
MmWaveFlexTtiPfMacScheduler::DoSchedUlCqiInfoReq(
    const struct MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters& params)
{
    NS_LOG_FUNCTION(this);

    uint16_t frameNum = params.m_sfnSf.m_frameNum;
    uint8_t subframeNum = params.m_sfnSf.m_sfNum;
    uint8_t slotNum = params.m_sfnSf.m_slotNum;
    uint8_t symNum = params.m_sfnSf.m_symStart;

    switch (params.m_ulCqi.m_type)
    {
    case UlCqiInfo::PUSCH: {
        std::map<uint32_t, struct AllocMapElem>::iterator itMap;
        std::map<uint16_t, struct UlCqiMapElem>::iterator itCqi;
        itMap = m_ulAllocationMap.find(params.m_sfnSf.Encode());
        if (itMap == m_ulAllocationMap.end())
        {
            NS_LOG_INFO(this << " Does not find info on allocation, size : "
                             << m_ulAllocationMap.size());
            return;
        }
        NS_ASSERT_MSG(itMap->second.m_rntiPerChunk.size() == m_phyMacConfig->GetNumRb(),
                      "SINR chunk map must cover full BW in TDMA mode");
        for (unsigned i = 0; i < itMap->second.m_rntiPerChunk.size(); i++)
        {
            // convert from fixed point notation Sxxxxxxxxxxx.xxx to double
            // double sinr = LteFfConverter::fpS11dot3toDouble (params.m_ulCqi.m_sinr.at (i));
            itCqi = m_ueUlCqi.find(itMap->second.m_rntiPerChunk.at(i));
            if (itCqi == m_ueUlCqi.end())
            {
                // create a new entry
                std::vector<double> newCqi;
                for (uint32_t j = 0; j < m_phyMacConfig->GetNumRb(); j++)
                {
                    unsigned chunkInd = i;
                    if (chunkInd == j)
                    {
                        newCqi.push_back(params.m_ulCqi.m_sinr.at(i));
                        NS_LOG_INFO("UL CQI report for RNTI "
                                    << itMap->second.m_rntiPerChunk.at(i) << " chunk " << i
                                    << " SINR " << params.m_ulCqi.m_sinr.at(i) << " frame "
                                    << frameNum << " subframe " << +subframeNum << " slot "
                                    << +slotNum << " startSym " << +symNum);
                    }
                    else
                    {
                        // initialize with NO_SINR value.
                        newCqi.push_back(30.0);
                    }
                }
                m_ueUlCqi.insert(std::pair<uint16_t, struct UlCqiMapElem>(
                    itMap->second.m_rntiPerChunk.at(i),
                    UlCqiMapElem(newCqi, itMap->second.m_numSym, itMap->second.m_tbSize)));
                // generate correspondent timer
                m_ueCqiTimers.insert(
                    std::pair<uint16_t, uint32_t>(itMap->second.m_rntiPerChunk.at(i),
                                                  m_cqiTimersThreshold));
            }
            else
            {
                // update the value
                (*itCqi).second.m_ueUlCqi.at(i) = params.m_ulCqi.m_sinr.at(i);
                (*itCqi).second.m_numSym = itMap->second.m_numSym;
                (*itCqi).second.m_tbSize = itMap->second.m_tbSize;
                // update correspondent timer
                std::map<uint16_t, uint32_t>::iterator itTimers;
                itTimers = m_ueCqiTimers.find(itMap->second.m_rntiPerChunk.at(i));
                (*itTimers).second = m_cqiTimersThreshold;

                NS_LOG_INFO("UL CQI report for RNTI "
                            << itMap->second.m_rntiPerChunk.at(i) << " chunk " << i << " SINR "
                            << params.m_ulCqi.m_sinr.at(i) << " frame " << frameNum << " subframe "
                            << +subframeNum << " slot " << +slotNum << " startSym " << +symNum);
            }
        }
        // remove obsolete info on allocation
        m_ulAllocationMap.erase(itMap);
    }
    break;
    default:
        NS_FATAL_ERROR("Unknown type of UL-CQI");
    }
    return;
}

void
MmWaveFlexTtiPfMacScheduler::DoSchedSetMcs(int mcs)
{
    if (mcs >= 0 && mcs <= 28)
    {
        m_mcsDefaultDl = mcs;
        m_mcsDefaultUl = mcs;
    }
}

void
MmWaveFlexTtiPfMacScheduler::RefreshHarqProcesses()
{
    NS_LOG_FUNCTION(this);

    std::map<uint16_t, DlHarqProcessesTimer_t>::iterator itTimers;
    for (itTimers = m_dlHarqProcessesTimer.begin(); itTimers != m_dlHarqProcessesTimer.end();
         itTimers++)
    {
        for (uint16_t i = 0; i < m_phyMacConfig->GetNumHarqProcess(); i++)
        {
            if ((*itTimers).second.at(i) == m_phyMacConfig->GetHarqTimeout())
            { // reset HARQ process
                NS_LOG_INFO(this << " Reset HARQ proc " << i << " for RNTI " << (*itTimers).first);
                std::map<uint16_t, DlHarqProcessesStatus_t>::iterator itStat =
                    m_dlHarqProcessesStatus.find((*itTimers).first);
                if (itStat == m_dlHarqProcessesStatus.end())
                {
                    NS_FATAL_ERROR("No Process Id Status found for this RNTI "
                                   << (*itTimers).first);
                }
                (*itStat).second.at(i) = 0;
                (*itTimers).second.at(i) = 0;
            }
            else
            {
                (*itTimers).second.at(i)++;
            }
        }
    }

    std::map<uint16_t, UlHarqProcessesTimer_t>::iterator itTimers2;
    for (itTimers2 = m_ulHarqProcessesTimer.begin(); itTimers2 != m_ulHarqProcessesTimer.end();
         itTimers2++)
    {
        for (uint16_t i = 0; i < m_phyMacConfig->GetNumHarqProcess(); i++)
        {
            if ((*itTimers2).second.at(i) == m_phyMacConfig->GetHarqTimeout())
            { // reset HARQ process
                NS_LOG_INFO(this << " Reset HARQ proc " << i << " for RNTI " << (*itTimers2).first);
                std::map<uint16_t, UlHarqProcessesStatus_t>::iterator itStat =
                    m_ulHarqProcessesStatus.find((*itTimers2).first);
                if (itStat == m_ulHarqProcessesStatus.end())
                {
                    NS_FATAL_ERROR("No Process Id Status found for this RNTI "
                                   << (*itTimers2).first);
                }
                (*itStat).second.at(i) = 0;
                (*itTimers2).second.at(i) = 0;
            }
            else
            {
                (*itTimers2).second.at(i)++;
            }
        }
    }
}

uint8_t
MmWaveFlexTtiPfMacScheduler::UpdateDlHarqProcessId(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);

    if (m_harqOn == false)
    {
        uint8_t tbUid = m_tbUid;
        m_tbUid = (m_tbUid + 1) % m_phyMacConfig->GetNumHarqProcess();
        return tbUid;
    }

    //  std::map <uint16_t, uint8_t>::iterator it = m_dlHarqCurrentProcessId.find (rnti);
    //  if (it == m_dlHarqCurrentProcessId.end ())
    //  {
    //      NS_FATAL_ERROR ("No Process Id found for this RNTI " << rnti);
    //  }
    std::map<uint16_t, DlHarqProcessesStatus_t>::iterator itStat =
        m_dlHarqProcessesStatus.find(rnti);
    if (itStat == m_dlHarqProcessesStatus.end())
    {
        NS_FATAL_ERROR("No Process Id Statusfound for this RNTI " << rnti);
    }

    // search for available process ID, if none available return numHarqProcess
    uint8_t harqId = m_phyMacConfig->GetNumHarqProcess();
    for (unsigned i = 0; i < m_phyMacConfig->GetNumHarqProcess(); i++)
    {
        if (itStat->second[i] == 0)
        {
            itStat->second[i] = 1;
            harqId = i;
            break;
        }
    }
    return harqId;

    //  uint8_t i = (*it).second;
    //  do
    //  {
    //      i = (i + 1) % m_phyMacConfig->GetNumHarqProcess ();
    //  }
    //  while ( ((*itStat).second.at (i) != 0)&&(i != (*it).second));
    //  if ((*itStat).second.at (i) == 0)
    //  {
    //      (*it).second = i;
    //      (*itStat).second.at (i) = 1;
    //  }
    //  else
    //  {
    //      return (m_phyMacConfig->GetNumHarqProcess () + 1); // return a not valid harq proc id
    //  }
    //
    //  return ((*it).second);
}

uint8_t
MmWaveFlexTtiPfMacScheduler::UpdateUlHarqProcessId(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);

    if (m_harqOn == false)
    {
        uint8_t tbUid = m_tbUid;
        m_tbUid = (m_tbUid + 1) % m_phyMacConfig->GetNumHarqProcess();
        return tbUid;
    }

    //  std::map <uint16_t, uint8_t>::iterator it = m_ulHarqCurrentProcessId.find (rnti);
    //  if (it == m_ulHarqCurrentProcessId.end ())
    //  {
    //      NS_FATAL_ERROR ("No Process Id found for this RNTI " << rnti);
    //  }
    std::map<uint16_t, DlHarqProcessesStatus_t>::iterator itStat =
        m_ulHarqProcessesStatus.find(rnti);
    if (itStat == m_ulHarqProcessesStatus.end())
    {
        NS_FATAL_ERROR("No Process Id Statusfound for this RNTI " << rnti);
    }

    // search for available process ID, if none available return numHarqProcess+1
    uint8_t harqId = m_phyMacConfig->GetNumHarqProcess();
    for (unsigned i = 0; i < m_phyMacConfig->GetNumHarqProcess(); i++)
    {
        if (itStat->second[i] == 0)
        {
            itStat->second[i] = 1;
            harqId = i;
            break;
        }
    }
    return harqId;
    //  uint8_t i = (*it).second;
    //  do
    //  {
    //      i = (i + 1) % m_phyMacConfig->GetNumHarqProcess ();
    //  }
    //  while ( ((*itStat).second.at (i) != 0)&&(i != (*it).second));
    //  if ((*itStat).second.at (i) == 0)
    //  {
    //      (*it).second = i;
    //      (*itStat).second.at (i) = 1;
    //  }
    //  else
    //  {
    //      return (m_phyMacConfig->GetNumHarqProcess () + 1); // return a not valid harq proc id
    //  }
    //  return ((*it).second);
}

unsigned
MmWaveFlexTtiPfMacScheduler::CalcMinTbSizeNumSym(unsigned mcs, unsigned bufSize, unsigned& tbSize)
{
    // Bisection line search is used to find the minimum number of slots (OFDM symbols)
    // needed to encode entire buffer.
    MmWaveMacPduHeader dummyMacHeader;
    // unsigned macHdrSize = 10; //dummyMacHeader.GetSerializedSize ();
    int numSymLow = 0;
    int numSymHigh = m_phyMacConfig->GetSymbPerSlot();

    int diff = 0;
    tbSize = m_amc->CalculateTbSize(mcs, numSymHigh); // start with max value, in number of bytes
    while ((unsigned)tbSize > bufSize)
    {
        diff = abs(numSymHigh - numSymLow) / 2;
        if (diff == 0)
        {
            tbSize = m_amc->CalculateTbSize(mcs, numSymHigh);
            return numSymHigh;
        }
        tbSize = m_amc->CalculateTbSize(mcs, numSymHigh - diff);
        if ((unsigned)tbSize >= bufSize)
        {
            numSymHigh -= diff;
        }
        if ((unsigned)tbSize == bufSize)
        {
            return numSymHigh;
        }
        while ((unsigned)tbSize < bufSize)
        {
            diff = abs(numSymHigh - numSymLow) / 2;
            if (diff == 0)
            {
                tbSize = m_amc->CalculateTbSize(mcs, numSymHigh);
                return numSymHigh;
            }
            tbSize = m_amc->CalculateTbSize(mcs, numSymLow + diff);
            if ((unsigned)tbSize <= bufSize)
            {
                numSymLow += diff;
            }
            if ((unsigned)tbSize == bufSize)
            {
                return numSymLow;
            }
        }
    }
    tbSize = m_amc->CalculateTbSize(mcs, numSymHigh);
    return (unsigned)numSymHigh;
}

void
MmWaveFlexTtiPfMacScheduler::DoSchedTriggerReq(
    const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params)
{
    uint32_t frameNum = params.m_snfSf.m_frameNum;
    uint8_t sfNum = params.m_snfSf.m_sfNum;
    uint8_t slotNum = params.m_snfSf.m_slotNum;

    MmWaveMacSchedSapUser::SchedConfigIndParameters ret;
    ret.m_sfnSf = params.m_snfSf;
    ret.m_slotAllocInfo.m_sfnSf = ret.m_sfnSf;

    NS_LOG_DEBUG("Creating scheduling allocation info for: frame "
                 << frameNum << " subframe " << +sfNum << " slot " << +slotNum);

    // Add TTI for DL control at the beginning of the slot
    TtiAllocInfo dlCtrlSlot(0, TtiAllocInfo::DL_slotAllocInfo, TtiAllocInfo::CTRL, 0);
    dlCtrlSlot.m_dci.m_numSym = 1;
    dlCtrlSlot.m_dci.m_symStart = 0;
    ret.m_slotAllocInfo.m_ttiAllocInfo.push_back(dlCtrlSlot);
    int resvCtrl = m_phyMacConfig->GetDlCtrlSymbols() + m_phyMacConfig->GetUlCtrlSymbols();
    int symAvail = m_phyMacConfig->GetSymbPerSlot() - resvCtrl;
    uint8_t ttiIdx = 1;
    uint8_t symIdx =
        m_phyMacConfig->GetDlCtrlSymbols(); // symbols reserved for control at beginning of subframe

    // process received CQIs
    RefreshDlCqiMaps();
    RefreshUlCqiMaps();

    // Process DL HARQ feedback
    RefreshHarqProcesses();

    // m_rlcBufferReq.sort (SortRlcBufferReq);     // sort list by RNTI
    //  number of DL/UL flows for new transmissions (not HARQ RETX)
    std::map<uint16_t, UeSchedInfo*> ueAllocMap; // map of allocated users for this SF
    std::map<uint16_t, UeSchedInfo*>::iterator itUeAllocMap;
    std::map<uint16_t, UeSchedInfo>::iterator itUeSchedInfoMap;
    std::map<uint8_t, FlowStats>::iterator itFlow;
    std::list<MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator itRlcBuf;

    // retrieve past HARQ retx buffered
    if (m_dlHarqInfoList.size() > 0 && params.m_dlHarqInfoList.size() > 0)
    {
        m_dlHarqInfoList.insert(m_dlHarqInfoList.end(),
                                params.m_dlHarqInfoList.begin(),
                                params.m_dlHarqInfoList.end());
    }
    else if (params.m_dlHarqInfoList.size() > 0)
    {
        m_dlHarqInfoList = params.m_dlHarqInfoList;
    }
    if (m_ulHarqInfoList.size() > 0 && params.m_ulHarqInfoList.size() > 0)
    {
        m_ulHarqInfoList.insert(m_ulHarqInfoList.end(),
                                params.m_ulHarqInfoList.begin(),
                                params.m_ulHarqInfoList.end());
    }
    else if (params.m_ulHarqInfoList.size() > 0)
    {
        m_ulHarqInfoList = params.m_ulHarqInfoList;
    }

    if (m_harqOn == false) // Ignore HARQ feedback
    {
        m_dlHarqInfoList.clear();
    }
    else
    {
        // Process DL HARQ feedback and assign slots for RETX if resources available
        std::vector<struct DlHarqInfo>
            dlInfoListUntxed; // TBs not able to be retransmitted in this sf
        std::vector<struct UlHarqInfo> ulInfoListUntxed;

        for (unsigned i = 0; i < m_dlHarqInfoList.size(); i++)
        {
            if (symAvail == 0)
            {
                break; // no symbols left to allocate
            }
            uint8_t harqId = m_dlHarqInfoList.at(i).m_harqProcessId;
            uint16_t rnti = m_dlHarqInfoList.at(i).m_rnti;
            itUeSchedInfoMap = m_ueSchedInfoMap.find(rnti);
            NS_ASSERT(itUeSchedInfoMap != m_ueSchedInfoMap.end());
            std::map<uint16_t, UlHarqProcessesStatus_t>::iterator itStat =
                m_dlHarqProcessesStatus.find(rnti);
            if (itStat == m_dlHarqProcessesStatus.end())
            {
                NS_FATAL_ERROR("No HARQ status info found for UE " << rnti);
            }
            std::map<uint16_t, DlHarqRlcPduList_t>::iterator itRlcPdu =
                m_dlHarqProcessesRlcPduMap.find(rnti);
            if (itRlcPdu == m_dlHarqProcessesRlcPduMap.end())
            {
                NS_FATAL_ERROR("Unable to find RlcPdcList in HARQ buffer for RNTI "
                               << m_dlHarqInfoList.at(i).m_rnti);
            }
            if (m_dlHarqInfoList.at(i).m_harqStatus == DlHarqInfo::ACK ||
                itStat->second.at(harqId) == 0)
            { // acknowledgment or process timeout, reset process
                // NS_LOG_DEBUG ("UE" << rnti << " DL harqId " << (unsigned)harqId << " HARQ-ACK
                // received");
                itStat->second.at(harqId) = 0;                         // release process ID
                for (uint16_t k = 0; k < itRlcPdu->second.size(); k++) // clear RLC buffers
                {
                    itRlcPdu->second.at(harqId).clear();
                }
                continue;
            }
            else if (m_dlHarqInfoList.at(i).m_harqStatus == DlHarqInfo::NACK)
            {
                std::map<uint16_t, DlHarqProcessesDciInfoList_t>::iterator itHarq =
                    m_dlHarqProcessesDciInfoMap.find(rnti);
                if (itHarq == m_dlHarqProcessesDciInfoMap.end())
                {
                    NS_FATAL_ERROR("No DCI/HARQ buffer entry found for UE " << rnti);
                }
                DciInfoElementTdma dciInfoReTx = itHarq->second.at(harqId);
                // NS_LOG_DEBUG ("UE" << rnti << " DL harqId " << (unsigned)harqId << " HARQ-NACK
                // received, rv " << (unsigned)dciInfoReTx.m_rv);
                NS_ASSERT(harqId == dciInfoReTx.m_harqProcess);
                // NS_ASSERT(itStat->second.at (harqId) > 0);
                NS_ASSERT(itStat->second.at(harqId) - 1 == dciInfoReTx.m_rv);
                if (dciInfoReTx.m_rv == 3) // maximum number of retx reached -> drop process
                {
                    NS_LOG_INFO("Max number of retransmissions reached -> drop process");
                    itStat->second.at(harqId) = 0;
                    for (uint16_t k = 0; k < (*itRlcPdu).second.size(); k++)
                    {
                        itRlcPdu->second.at(harqId).clear();
                    }
                    continue;
                }
                // allocate retx if enough symbols are available
                if (symAvail >= dciInfoReTx.m_numSym)
                {
                    symAvail -= dciInfoReTx.m_numSym;
                    dciInfoReTx.m_symStart = symIdx;
                    symIdx += dciInfoReTx.m_numSym;
                    NS_ASSERT(symIdx <= m_phyMacConfig->GetSymbPerSlot() -
                                            m_phyMacConfig->GetUlCtrlSymbols());
                    dciInfoReTx.m_rv++;
                    dciInfoReTx.m_ndi = 0;
                    itHarq->second.at(harqId) = dciInfoReTx;
                    itStat->second.at(harqId) = itStat->second.at(harqId) + 1;
                    TtiAllocInfo ttiInfo(ttiIdx++,
                                         TtiAllocInfo::DL_slotAllocInfo,
                                         TtiAllocInfo::CTRL_DATA,
                                         rnti);
                    ttiInfo.m_dci = dciInfoReTx;
                    NS_LOG_DEBUG("UE" << dciInfoReTx.m_rnti << " gets DL slots "
                                      << +dciInfoReTx.m_symStart << "-"
                                      << +(dciInfoReTx.m_symStart + dciInfoReTx.m_numSym - 1)
                                      << " tbs " << dciInfoReTx.m_tbSize << " harqId "
                                      << +dciInfoReTx.m_harqProcess << " harqId "
                                      << +dciInfoReTx.m_harqProcess << " rv " << +dciInfoReTx.m_rv
                                      << " in frame " << ret.m_sfnSf.m_frameNum << " subframe "
                                      << +ret.m_sfnSf.m_sfNum << " RETX");
                    std::map<uint16_t, DlHarqRlcPduList_t>::iterator itRlcList =
                        m_dlHarqProcessesRlcPduMap.find(rnti);
                    if (itRlcList == m_dlHarqProcessesRlcPduMap.end())
                    {
                        NS_FATAL_ERROR("Unable to find RlcPdcList in HARQ buffer for RNTI "
                                       << rnti);
                    }
                    for (uint16_t k = 0;
                         k < (*itRlcList).second.at(dciInfoReTx.m_harqProcess).size();
                         k++)
                    {
                        ttiInfo.m_rlcPduInfo.push_back(
                            (*itRlcList).second.at(dciInfoReTx.m_harqProcess).at(k));
                    }
                    ret.m_slotAllocInfo.m_ttiAllocInfo.push_back(ttiInfo);
                    ret.m_slotAllocInfo.m_numSymAlloc += dciInfoReTx.m_numSym;

                    itUeSchedInfoMap->second.m_dlSymbolsRetx = dciInfoReTx.m_numSym;
                    itUeAllocMap = ueAllocMap.find(rnti);
                    if (itUeAllocMap == ueAllocMap.end())
                    {
                        itUeAllocMap = ueAllocMap
                                           .insert(std::pair<uint16_t, UeSchedInfo*>(
                                               rnti,
                                               &itUeSchedInfoMap->second))
                                           .first;
                    }
                }
                else
                {
                    NS_LOG_INFO("No resource for this retx -> buffer it");
                    dlInfoListUntxed.push_back(m_dlHarqInfoList.at(i));
                }
            }
        }

        m_dlHarqInfoList.clear();
        m_dlHarqInfoList = dlInfoListUntxed;

        // Process UL HARQ feedback
        for (uint16_t i = 0; i < m_ulHarqInfoList.size(); i++)
        {
            if (symAvail == 0)
            {
                break; // no symbols left to allocate
            }
            UlHarqInfo harqInfo = m_ulHarqInfoList.at(i);
            uint8_t harqId = harqInfo.m_harqProcessId;
            uint16_t rnti = harqInfo.m_rnti;
            itUeSchedInfoMap = m_ueSchedInfoMap.find(rnti);
            NS_ASSERT(itUeSchedInfoMap != m_ueSchedInfoMap.end());
            std::map<uint16_t, UlHarqProcessesStatus_t>::iterator itStat =
                m_ulHarqProcessesStatus.find(rnti);
            if (itStat == m_ulHarqProcessesStatus.end())
            {
                NS_LOG_ERROR("No info found in HARQ buffer for UE (might have changed eNB) "
                             << rnti);
            }
            if (harqInfo.m_receptionStatus == UlHarqInfo::Ok || itStat->second.at(harqId) == 0)
            {
                // NS_LOG_DEBUG ("UE" << rnti << " UL harqId " << (unsigned)harqInfo.m_harqProcessId
                // << " HARQ-ACK received");
                if (itStat != m_ulHarqProcessesStatus.end())
                {
                    itStat->second.at(harqId) = 0; // release process ID
                }
            }
            else if (harqInfo.m_receptionStatus == UlHarqInfo::NotOk)
            {
                std::map<uint16_t, UlHarqProcessesDciInfoList_t>::iterator itHarq =
                    m_ulHarqProcessesDciInfoMap.find(rnti);
                if (itHarq == m_ulHarqProcessesDciInfoMap.end())
                {
                    NS_LOG_ERROR("No info found in UL-HARQ buffer for UE (might have changed eNB) "
                                 << rnti);
                }
                // retx correspondent block: retrieve the UL-DCI
                DciInfoElementTdma dciInfoReTx = itHarq->second.at(harqId);
                // NS_LOG_DEBUG ("UE" << rnti << " UL harqId " << (unsigned)harqInfo.m_harqProcessId
                // << " HARQ-NACK received, rv " << (unsigned)dciInfoReTx.m_rv);
                NS_ASSERT(harqId == dciInfoReTx.m_harqProcess);
                NS_ASSERT(itStat->second.at(harqId) > 0);
                NS_ASSERT(itStat->second.at(harqId) - 1 == dciInfoReTx.m_rv);
                if (dciInfoReTx.m_rv == 3)
                {
                    NS_LOG_INFO("Max number of retransmissions reached (UL)-> drop process");
                    itStat->second.at(harqId) = 0;
                    continue;
                }

                if (symAvail >= dciInfoReTx.m_numSym)
                {
                    symAvail -= dciInfoReTx.m_numSym;
                    dciInfoReTx.m_symStart = symIdx;
                    symIdx += dciInfoReTx.m_numSym;
                    NS_ASSERT(symIdx <= m_phyMacConfig->GetSymbPerSlot() -
                                            m_phyMacConfig->GetUlCtrlSymbols());
                    dciInfoReTx.m_rv++;
                    dciInfoReTx.m_ndi = 0;
                    itStat->second.at(harqId) = itStat->second.at(harqId) + 1;
                    itHarq->second.at(harqId) = dciInfoReTx;
                    TtiAllocInfo ttiInfo(ttiIdx++,
                                         TtiAllocInfo::UL_slotAllocInfo,
                                         TtiAllocInfo::CTRL_DATA,
                                         rnti);
                    ttiInfo.m_dci = dciInfoReTx;
                    NS_LOG_DEBUG("UE" << dciInfoReTx.m_rnti << " gets DL OFDM symbols "
                                      << +dciInfoReTx.m_symStart << "-"
                                      << +(dciInfoReTx.m_symStart + dciInfoReTx.m_numSym - 1)
                                      << " tbs " << dciInfoReTx.m_tbSize << " harqId "
                                      << +dciInfoReTx.m_harqProcess << " harqId "
                                      << +dciInfoReTx.m_harqProcess << " rv " << +dciInfoReTx.m_rv
                                      << " in frame " << ret.m_sfnSf.m_frameNum << " subframe "
                                      << +ret.m_sfnSf.m_sfNum << " slot " << +ret.m_sfnSf.m_slotNum
                                      << " RETX");

                    ret.m_slotAllocInfo.m_ttiAllocInfo.push_back(ttiInfo);
                    ret.m_slotAllocInfo.m_numSymAlloc += dciInfoReTx.m_numSym;

                    itUeSchedInfoMap->second.m_ulSymbolsRetx = dciInfoReTx.m_numSym;
                    itUeAllocMap = ueAllocMap.find(rnti);
                    if (itUeAllocMap == ueAllocMap.end())
                    {
                        itUeAllocMap = ueAllocMap
                                           .insert(std::pair<uint16_t, UeSchedInfo*>(
                                               rnti,
                                               &itUeSchedInfoMap->second))
                                           .first;
                    }
                }
                else
                {
                    ulInfoListUntxed.push_back(m_ulHarqInfoList.at(i));
                }
            }
        }

        m_ulHarqInfoList.clear();
        m_ulHarqInfoList = ulInfoListUntxed;
    }

    // no further allocations
    if (symAvail == 0)
    {
        // add slot for UL control
        TtiAllocInfo ulCtrlSlot(0xFF, TtiAllocInfo::UL_slotAllocInfo, TtiAllocInfo::CTRL, 0);
        ulCtrlSlot.m_dci.m_numSym = 1;
        ulCtrlSlot.m_dci.m_symStart = m_phyMacConfig->GetSymbPerSlot() - 1;
        // ret.m_ulSfAllocInfo.m_ttiAllocInfo.push_back (ulCtrlSlot);
        ret.m_slotAllocInfo.m_ttiAllocInfo.push_back(ulCtrlSlot);
        // m_ulSfAllocInfo.push_back (ret.m_ulSfAllocInfo); // add UL SF info for later calls to
        // scheduler
        m_macSchedSapUser->SchedConfigInd(ret);

        // reset the alloc info for the next scheduler call
        for (itUeAllocMap = ueAllocMap.begin(); itUeAllocMap != ueAllocMap.end(); itUeAllocMap++)
        {
            itUeAllocMap->second->m_dlSymbolsRetx = 0;
            itUeAllocMap->second->m_ulSymbolsRetx = 0;
        }
        return;
    }

    // ********************* END OF HARQ SECTION, START OF NEW DATA SCHEDULING *********************
    // //

    // compute achievable rates in current subframe
    for (std::map<uint16_t, UeSchedInfo>::iterator ueIt = m_ueSchedInfoMap.begin();
         ueIt != m_ueSchedInfoMap.end();
         ueIt++)
    {
        UeSchedInfo* ueInfo = &ueIt->second;

        // get DL-CQI and compute DL rate per symbol
        bool dlAdded = false;
        std::map<uint16_t, uint8_t>::iterator itCqiDl = m_wbCqiRxed.find(ueInfo->m_rnti);
        uint8_t cqi = 0;
        if (itCqiDl != m_wbCqiRxed.end())
        {
            cqi = itCqiDl->second;
        }
        else // no CQI available
        {
            NS_LOG_INFO(this << " UE " << ueInfo->m_rnti << " does not have DL-CQI");
            cqi = 1; // lowest value for trying a transmission
        }
        if (cqi != 0)
        {
            ueInfo->m_dlMcs = m_amc->GetMcsFromCqi(cqi); // update MCS
            // compute total DL and UL bytes buffered
            for (unsigned iflow = 0; iflow < ueInfo->m_flowStatsDl.size(); iflow++)
            {
                if (ueInfo->m_flowStatsDl[iflow].m_totalBufSize > 0)
                {
                    ueInfo->m_totBufDl += ueInfo->m_flowStatsDl[iflow].m_totalBufSize;
                    RlcPduInfo newRlcEl;
                    newRlcEl.m_lcid = ueInfo->m_flowStatsDl[iflow].m_lcid;
                    newRlcEl.m_size =
                        ueInfo->m_flowStatsDl[iflow].m_totalBufSize + m_subHdrSize + m_rlcHdrSize;
                    ueInfo->m_rlcPduInfo.push_back(newRlcEl);
                }
            }
            if (ueInfo->m_totBufDl > 0)
            {
                uint32_t tbSizeMax =
                    m_amc->CalculateTbSize(ueInfo->m_dlMcs, 1) * 8; // Bytes -> Bits
                ueInfo->m_currTputDl = std::min(ueInfo->m_totBufDl, tbSizeMax) /
                                       (m_phyMacConfig->GetSlotPeriod().GetSeconds());
                m_ueStatHeap.push_back(ueInfo);
                itUeAllocMap = ueAllocMap.find(ueInfo->m_rnti);
                if (itUeAllocMap == ueAllocMap.end())
                {
                    ueAllocMap.insert(std::pair<uint16_t, UeSchedInfo*>(ueInfo->m_rnti, ueInfo));
                }

                dlAdded = true;
            }
        }

        // get UL-CQI and compute UL rate per symbol
        std::map<uint16_t, struct UlCqiMapElem>::iterator itCqiUl = m_ueUlCqi.find(ueInfo->m_rnti);
        uint8_t mcs{0};
        if (itCqiUl != m_ueUlCqi.end()) // no cqi info for this UE
        {
            // translate vector of doubles to SpectrumValue's
            SpectrumValue specVals(MmWaveSpectrumValueHelper::GetSpectrumModel(m_phyMacConfig));
            Values::iterator specIt = specVals.ValuesBegin();
            for (uint32_t ichunk = 0; ichunk < m_phyMacConfig->GetNumRb(); ichunk++)
            {
                NS_ASSERT(specIt != specVals.ValuesEnd());
                *specIt = itCqiUl->second.m_ueUlCqi.at(ichunk); // sinrLin;
                specIt++;
            }
            // for UL CQI, we need to know the TB size previously allocated to accurately compute
            // CQI/MCS
            cqi = m_amc->CreateCqiFeedbackWbTdma(specVals, mcs);
        }
        else
        {
            NS_LOG_INFO(this << " UE " << ueInfo->m_rnti << " does not have UL-CQI");
            cqi = 1;
            mcs = 0;
        }
        if (cqi != 0)
        {
            ueInfo->m_ulMcs = mcs;
            for (unsigned iflow = 0; iflow < ueInfo->m_flowStatsUl.size(); iflow++)
            {
                ueInfo->m_totBufUl +=
                    ueInfo->m_flowStatsUl[iflow].m_totalBufSize + m_subHdrSize + m_rlcHdrSize;
            }
            if (ueInfo->m_totBufUl > 0)
            {
                uint32_t tbSizeMax =
                    m_amc->CalculateTbSize(ueInfo->m_ulMcs, 1) * 8; // Bytes -> Bits
                ueInfo->m_currTputUl = std::min(ueInfo->m_totBufUl, tbSizeMax) /
                                       (m_phyMacConfig->GetSlotPeriod().GetSeconds());
                if (!dlAdded)
                {
                    m_ueStatHeap.push_back(ueInfo);
                    itUeAllocMap = ueAllocMap.find(ueInfo->m_rnti);
                    if (itUeAllocMap == ueAllocMap.end())
                    {
                        ueAllocMap.insert(
                            std::pair<uint16_t, UeSchedInfo*>(ueInfo->m_rnti, ueInfo));
                    }
                }
            }
        }
    }

    //  itUeAllocMap = ueAllocMap.find (10);
    //  if (itUeAllocMap != ueAllocMap.end())
    //  {
    //      std::cout << frameNum << " " << sfNum << " " << itUeAllocMap->second->m_rlcPduInfo.size ()
    //<< std::endl;
    //  }

    // allocate each slot to UE with highest PF metric, then update PF metrics
    while (symAvail > 0)
    {
        std::sort(m_ueStatHeap.begin(),
                  m_ueStatHeap.end(),
                  MmWaveFlexTtiPfMacScheduler::CompareUeWeightsPf);
        // evenly distribute symbols between DL and UL flows of same UE
        bool ueAlloc = false;
        std::vector<UeSchedInfo*>::iterator ueHeapIt = m_ueStatHeap.begin();
        //      for (itUeAllocMap = ueAllocMap.begin (); itUeAllocMap != ueAllocMap.end();
        //itUeAllocMap++)
        //      {
        //          UeSchedInfo* ueInfo = itUeAllocMap->second;
        //          double pfMetric = std::max(ueInfo->m_currTputDl,ueInfo->m_currTputUl) /
        //std::max(1E-9,(ueInfo->m_avgTputDl + ueInfo->m_avgTputDl));           std::cout << ueInfo->m_rnti <<
        //"=" << pfMetric << " ";
        //      }
        //      std::cout << std::endl;

        while (!ueAlloc && ueHeapIt != m_ueStatHeap.end())
        {
            UeSchedInfo* ueInfo = *ueHeapIt;

            if (ueInfo->m_totBufDl == 0)
            {
                ueInfo->m_dlAllocDone = true;
            }
            if (ueInfo->m_totBufUl == 0)
            {
                ueInfo->m_ulAllocDone = true;
            }

            if ((ueInfo->m_allocUlLast || ueInfo->m_dlAllocDone) && !ueInfo->m_ulAllocDone)
            {
                ueInfo->m_ulSymbols++;
                symAvail--;
                ueInfo->m_ulTbSize = m_amc->CalculateTbSize(ueInfo->m_ulMcs, ueInfo->m_ulSymbols);
                if (ueInfo->m_ulTbSize >= ueInfo->m_totBufUl)
                {
                    ueInfo->m_ulAllocDone = true;
                    ueInfo->m_lastAvgTputUl = ueInfo->m_avgTputUl;
                }
                ueInfo->m_allocUlLast = true;

                uint32_t tbSize = m_amc->CalculateTbSize(ueInfo->m_ulMcs, ueInfo->m_ulSymbols) *
                                  8; // Bytes -> Bits
                ueInfo->m_currTputUl = std::min(ueInfo->m_totBufUl, tbSize) /
                                       (m_phyMacConfig->GetSlotPeriod().GetSeconds());
                ueInfo->m_avgTputUl =
                    ((1.0 - (1.0 / m_timeWindow)) * ueInfo->m_lastAvgTputUl) +
                    ((1.0 / m_timeWindow) *
                     ((double)ueInfo->m_ulTbSize / (m_phyMacConfig->GetSlotPeriod().GetSeconds())));
                ueAlloc = true;
            }
            else if (!ueInfo->m_dlAllocDone)
            {
                ueInfo->m_dlSymbols++;
                symAvail--;
                ueInfo->m_dlTbSize = m_amc->CalculateTbSize(ueInfo->m_dlMcs, ueInfo->m_dlSymbols);
                if (ueInfo->m_dlTbSize >= ueInfo->m_totBufDl)
                {
                    ueInfo->m_dlAllocDone = true;
                    ueInfo->m_lastAvgTputDl = ueInfo->m_avgTputDl;
                }
                ueInfo->m_allocUlLast = false;

                uint32_t tbSize = m_amc->CalculateTbSize(ueInfo->m_dlMcs, ueInfo->m_dlSymbols) *
                                  8; // Bytes -> Bits
                ueInfo->m_currTputDl = std::min(ueInfo->m_totBufDl, tbSize) /
                                       (m_phyMacConfig->GetSlotPeriod().GetSeconds());
                ueInfo->m_avgTputDl =
                    ((1.0 - (1.0 / m_timeWindow)) * ueInfo->m_lastAvgTputDl) +
                    ((1.0 / m_timeWindow) *
                     ((double)ueInfo->m_dlTbSize / (m_phyMacConfig->GetSlotPeriod().GetSeconds())));
                ueAlloc = true;
            }

            ueHeapIt++;
        }

        if (!ueAlloc)
        {
            break;
        }
    }

    // no further allocations
    if (ueAllocMap.size() == 0)
    {
        // add slot for UL control
        TtiAllocInfo ulCtrlSlot(0xFF, TtiAllocInfo::UL_slotAllocInfo, TtiAllocInfo::CTRL, 0);
        ulCtrlSlot.m_dci.m_numSym = 1;
        ulCtrlSlot.m_dci.m_symStart = m_phyMacConfig->GetSymbPerSlot() - 1;
        // ret.m_ulSfAllocInfo.m_ttiAllocInfo.push_back (ulCtrlSlot);
        ret.m_slotAllocInfo.m_ttiAllocInfo.push_back(ulCtrlSlot);
        // m_ulSfAllocInfo.push_back (ret.m_ulSfAllocInfo); // add UL SF info for later calls to
        // scheduler
        m_macSchedSapUser->SchedConfigInd(ret);

        // reset the alloc info for the next scheduler call
        for (itUeAllocMap = ueAllocMap.begin(); itUeAllocMap != ueAllocMap.end(); itUeAllocMap++)
        {
            itUeAllocMap->second->m_dlSymbols = 0;
            itUeAllocMap->second->m_ulSymbols = 0;
            itUeAllocMap->second->m_dlTbSize = 0;
            itUeAllocMap->second->m_ulTbSize = 0;
            itUeAllocMap->second->m_dlSymbolsRetx = 0;
            itUeAllocMap->second->m_ulSymbolsRetx = 0;
            itUeAllocMap->second->m_currTputDl = 0;
            itUeAllocMap->second->m_currTputUl = 0;
            itUeAllocMap->second->m_avgTputDl = 0;
            itUeAllocMap->second->m_avgTputUl = 0;
            itUeAllocMap->second->m_totBufDl = 0;
            itUeAllocMap->second->m_totBufUl = 0;
            itUeAllocMap->second->m_dlAllocDone = false;
            itUeAllocMap->second->m_ulAllocDone = false;
            itUeAllocMap->second->m_rlcPduInfo.clear();
        }
        return;
    }

    //  itUeAllocMap = ueAllocMap.find (10);
    //  if (itUeAllocMap != ueAllocMap.end())
    //  {
    //      std::cout << frameNum << " " << sfNum << " " << itUeAllocMap->second->m_rlcPduInfo.size ()
    //<< std::endl;
    //  }

    // iterate through map of allocated UEs, assign TDMA symbol indices and create DCIs
    // unsigned numSymAllocPrev = ret.m_dlSfAllocInfo.m_numSymAlloc; // allocated in prev sched
    // request
    for (itUeAllocMap = ueAllocMap.begin(); itUeAllocMap != ueAllocMap.end(); itUeAllocMap++)
    {
        UeSchedInfo* ueInfo = itUeAllocMap->second;
        if (ueInfo->m_dlSymbols > 0)
        {
            DciInfoElementTdma dci;
            dci.m_rnti = ueInfo->m_rnti;
            dci.m_format = 0;
            dci.m_symStart = symIdx;
            dci.m_numSym = ueInfo->m_dlSymbols;
            symIdx += ueInfo->m_dlSymbols;
            NS_ASSERT(symIdx <=
                      m_phyMacConfig->GetSymbPerSlot() - m_phyMacConfig->GetUlCtrlSymbols());
            dci.m_mcs = ueInfo->m_dlMcs;
            dci.m_rv = 0;
            dci.m_ndi = 1;
            dci.m_tbSize = m_amc->CalculateTbSize(dci.m_mcs, dci.m_numSym);
            dci.m_harqProcess = UpdateDlHarqProcessId(ueInfo->m_rnti);
            NS_ASSERT(dci.m_harqProcess < m_phyMacConfig->GetNumHarqProcess());
            // NS_LOG_DEBUG ("UE" << ueInfo->m_rnti << " DL harqId " << (unsigned)dci.m_harqProcess
            // << " HARQ process assigned");
            TtiAllocInfo ttiInfo(ttiIdx++,
                                 TtiAllocInfo::DL_slotAllocInfo,
                                 TtiAllocInfo::CTRL_DATA,
                                 ueInfo->m_rnti);
            ttiInfo.m_dci = dci;
            NS_LOG_DEBUG("UE" << dci.m_rnti << " gets DL symbols " << +dci.m_symStart << "-"
                              << +(dci.m_symStart + dci.m_numSym - 1) << " tbs " << dci.m_tbSize
                              << " mcs " << +dci.m_mcs << " harqId " << +dci.m_harqProcess << " rv "
                              << +dci.m_rv << " in frame " << ret.m_sfnSf.m_frameNum << " subframe "
                              << +ret.m_sfnSf.m_sfNum);

            if (m_harqOn == true)
            { // store DCI for HARQ buffer
                std::map<uint16_t, DlHarqProcessesDciInfoList_t>::iterator itDciInfo =
                    m_dlHarqProcessesDciInfoMap.find(dci.m_rnti);
                if (itDciInfo == m_dlHarqProcessesDciInfoMap.end())
                {
                    NS_FATAL_ERROR("Unable to find RNTI entry in DCI HARQ buffer for RNTI "
                                   << dci.m_rnti);
                }
                (*itDciInfo).second.at(dci.m_harqProcess) = dci;
                // refresh timer
                std::map<uint16_t, DlHarqProcessesTimer_t>::iterator itHarqTimer =
                    m_dlHarqProcessesTimer.find(dci.m_rnti);
                if (itHarqTimer == m_dlHarqProcessesTimer.end())
                {
                    NS_FATAL_ERROR("Unable to find HARQ timer for RNTI " << (uint16_t)dci.m_rnti);
                }
                (*itHarqTimer).second.at(dci.m_harqProcess) = 0;
            }

            // distribute bytes between active RLC queues
            unsigned numLc = ueInfo->m_rlcPduInfo.size();
            unsigned bytesRem = dci.m_tbSize;
            unsigned numFulfilled = 0;
            uint16_t avgPduSize = bytesRem / numLc;
            // first for loop computes extra to add to average if some flows are less than average
            for (unsigned i = 0; i < ueInfo->m_rlcPduInfo.size(); i++)
            {
                if (ueInfo->m_rlcPduInfo[i].m_size < avgPduSize)
                {
                    bytesRem -= ueInfo->m_rlcPduInfo[i].m_size;
                    numFulfilled++;
                }
            }

            if (numFulfilled < ueInfo->m_rlcPduInfo.size())
            {
                avgPduSize = bytesRem / (ueInfo->m_rlcPduInfo.size() - numFulfilled);
            }

            for (unsigned i = 0; i < ueInfo->m_rlcPduInfo.size(); i++)
            {
                if (ueInfo->m_rlcPduInfo[i].m_size > avgPduSize)
                {
                    ueInfo->m_rlcPduInfo[i].m_size = avgPduSize;
                }
                // else tbSize equals RLC queue size
                NS_ASSERT(ueInfo->m_rlcPduInfo[i].m_size > 0);
                /*for (itRlcBuf = m_rlcBufferReq.begin (); itRlcBuf != m_rlcBufferReq.end ();
                   itRlcBuf++)
                                                {
                                                        if(itRlcBuf->m_rnti == itUeInfo->first)
                                                        {
                                                                if(itRlcBuf->m_rlcTransmissionQueueSize
                   == 0)
                                                                {
                                                                        NS_FATAL_ERROR ("LC is
                   scheduled but RLC buffer == 0");
                                                                }
                                                        }
                                                }*/
                // update RLC buffer info with expected queue size after scheduling
                UpdateDlRlcBufferInfo(ueInfo->m_rnti,
                                      ueInfo->m_rlcPduInfo[i].m_lcid,
                                      ueInfo->m_rlcPduInfo[i].m_size - m_subHdrSize);
                ttiInfo.m_rlcPduInfo.push_back(ueInfo->m_rlcPduInfo[i]);
                if (m_harqOn == true)
                {
                    // store RLC PDU list for HARQ
                    std::map<uint16_t, DlHarqRlcPduList_t>::iterator itRlcPdu =
                        m_dlHarqProcessesRlcPduMap.find(dci.m_rnti);
                    if (itRlcPdu == m_dlHarqProcessesRlcPduMap.end())
                    {
                        NS_FATAL_ERROR("Unable to find RlcPdcList in HARQ buffer for RNTI "
                                       << dci.m_rnti);
                    }
                    (*itRlcPdu).second.at(dci.m_harqProcess).push_back(ueInfo->m_rlcPduInfo[i]);
                }
            }

            for (unsigned i = 0; i < ueInfo->m_rlcPduInfo.size(); i++)
            {
                // update RLC buffer info with expected queue size after scheduling
                ttiInfo.m_rlcPduInfo.push_back(ueInfo->m_rlcPduInfo[i]);
                if (m_harqOn == true)
                {
                    // store RLC PDU list for HARQ
                    std::map<uint16_t, DlHarqRlcPduList_t>::iterator itRlcPdu =
                        m_dlHarqProcessesRlcPduMap.find(dci.m_rnti);
                    if (itRlcPdu == m_dlHarqProcessesRlcPduMap.end())
                    {
                        NS_FATAL_ERROR("Unable to find RlcPdcList in HARQ buffer for RNTI "
                                       << dci.m_rnti);
                    }
                    itRlcPdu->second.at(dci.m_harqProcess).push_back(ueInfo->m_rlcPduInfo[i]);
                }
            }

            if (m_harqOn == true)
            {
                // reorder/reindex slots to maintain DL before UL slot order
                bool reordered = false;
                std::deque<TtiAllocInfo>::iterator itTti =
                    ret.m_slotAllocInfo.m_ttiAllocInfo.begin();
                for (unsigned iTti = 0; iTti < ret.m_slotAllocInfo.m_ttiAllocInfo.size(); iTti++)
                {
                    if (ret.m_slotAllocInfo.m_ttiAllocInfo[iTti].m_tddMode ==
                        TtiAllocInfo::UL_slotAllocInfo)
                    {
                        ttiInfo.m_ttiIdx = ret.m_slotAllocInfo.m_ttiAllocInfo[iTti].m_ttiIdx;
                        ttiInfo.m_dci.m_symStart =
                            ret.m_slotAllocInfo.m_ttiAllocInfo[iTti].m_dci.m_symStart;
                        ret.m_slotAllocInfo.m_ttiAllocInfo.insert(itTti, ttiInfo);
                        for (unsigned jTti = iTti + 1;
                             jTti < ret.m_slotAllocInfo.m_ttiAllocInfo.size();
                             jTti++)
                        {
                            ret.m_slotAllocInfo.m_ttiAllocInfo[jTti]
                                .m_ttiIdx++; // increase indices of UL slots
                            ret.m_slotAllocInfo.m_ttiAllocInfo[jTti].m_dci.m_symStart =
                                ret.m_slotAllocInfo.m_ttiAllocInfo[jTti - 1].m_dci.m_symStart +
                                ret.m_slotAllocInfo.m_ttiAllocInfo[jTti - 1].m_dci.m_numSym;
                        }
                        reordered = true;
                        break;
                    }
                    itTti++;
                }
                if (!reordered)
                {
                    ret.m_slotAllocInfo.m_ttiAllocInfo.push_back(ttiInfo);
                }
            }
            else
            {
                ret.m_slotAllocInfo.m_ttiAllocInfo.push_back(ttiInfo);
            }
            ret.m_slotAllocInfo.m_numSymAlloc += dci.m_numSym;
        }
    }
    ttiIdx = ret.m_slotAllocInfo.m_ttiAllocInfo.back().m_ttiIdx + 1;
    symIdx = ret.m_slotAllocInfo.m_ttiAllocInfo.back().m_dci.m_symStart +
             ret.m_slotAllocInfo.m_ttiAllocInfo.back().m_dci.m_numSym;

    for (itUeAllocMap = ueAllocMap.begin(); itUeAllocMap != ueAllocMap.end(); itUeAllocMap++)
    {
        UeSchedInfo* ueInfo = itUeAllocMap->second;
        // Note: UL-DCI applies to subframe i+Tsched
        if (ueInfo->m_ulSymbols > 0)
        {
            DciInfoElementTdma dci;
            dci.m_rnti = ueInfo->m_rnti;
            dci.m_format = 1;
            dci.m_symStart = symIdx;
            dci.m_numSym = ueInfo->m_ulSymbols;
            symIdx += ueInfo->m_ulSymbols;
            NS_ASSERT(symIdx <=
                      m_phyMacConfig->GetSymbPerSlot() - m_phyMacConfig->GetUlCtrlSymbols());
            dci.m_mcs = ueInfo->m_ulMcs;
            dci.m_ndi = 1;
            dci.m_tbSize = m_amc->CalculateTbSize(dci.m_mcs, dci.m_numSym);
            dci.m_harqProcess = UpdateUlHarqProcessId(ueInfo->m_rnti);
            // NS_LOG_DEBUG ("UE" << ueInfo->m_rnti << " UL harqId " << (unsigned)dci.m_harqProcess
            // << " HARQ process assigned");
            NS_ASSERT(dci.m_harqProcess < m_phyMacConfig->GetNumHarqProcess());
            TtiAllocInfo ttiInfo(ttiIdx++,
                                 TtiAllocInfo::UL_slotAllocInfo,
                                 TtiAllocInfo::CTRL_DATA,
                                 ueInfo->m_rnti);
            ttiInfo.m_dci = dci;
            NS_LOG_DEBUG("UE" << dci.m_rnti << " gets UL symbols " << dci.m_symStart << "-"
                              << (dci.m_symStart + dci.m_numSym - 1) << " tbs " << dci.m_tbSize
                              << " mcs " << dci.m_mcs << " harqId " << dci.m_harqProcess << " rv "
                              << dci.m_rv << " in frame " << ret.m_sfnSf.m_frameNum << " subframe "
                              << ret.m_sfnSf.m_sfNum);
            // UpdateUlRlcBufferInfo (ueInfo->m_rnti, dci.m_tbSize - m_subHdrSize);
            ret.m_slotAllocInfo.m_ttiAllocInfo.push_back(ttiInfo);
            ret.m_slotAllocInfo.m_numSymAlloc += dci.m_numSym;
            std::vector<uint16_t> ueChunkMap;
            for (uint32_t i = 0; i < m_phyMacConfig->GetNumRb(); i++)
            {
                ueChunkMap.push_back(dci.m_rnti);
            }
            // SfnSf slotSfn = ret.m_ulSfAllocInfo.m_sfnSf;
            SfnSf slotSfn = ret.m_slotAllocInfo.m_sfnSf;
            slotSfn.m_slotNum =
                dci.m_symStart; // use the start symbol index of the slot because the absolute UL
                                // slot index depends on the future DL allocation
            // insert into allocation map to recall previous allocations upon receiving UL-CQI
            m_ulAllocationMap.insert(std::pair<uint32_t, struct AllocMapElem>(
                slotSfn.Encode(),
                AllocMapElem(ueChunkMap, dci.m_numSym, dci.m_tbSize)));

            if (m_harqOn == true)
            {
                uint8_t harqId = dci.m_harqProcess;
                std::map<uint16_t, UlHarqProcessesDciInfoList_t>::iterator itHarqTbInfo =
                    m_ulHarqProcessesDciInfoMap.find(dci.m_rnti);
                if (itHarqTbInfo == m_ulHarqProcessesDciInfoMap.end())
                {
                    NS_FATAL_ERROR("Unable to find RNTI entry in UL DCI HARQ buffer for RNTI "
                                   << dci.m_rnti);
                }
                (*itHarqTbInfo).second.at(harqId) = dci;
                // Update HARQ process status (RV 0)
                std::map<uint16_t, UlHarqProcessesStatus_t>::iterator itStat =
                    m_ulHarqProcessesStatus.find(dci.m_rnti);
                NS_ASSERT(itStat->second[dci.m_harqProcess] > 0);
                // refresh timer
                std::map<uint16_t, UlHarqProcessesTimer_t>::iterator itHarqTimer =
                    m_ulHarqProcessesTimer.find(dci.m_rnti);
                if (itHarqTimer == m_ulHarqProcessesTimer.end())
                {
                    NS_FATAL_ERROR("Unable to find HARQ timer for RNTI " << (uint16_t)dci.m_rnti);
                }
                (*itHarqTimer).second.at(dci.m_harqProcess) = 0;
            }
        }
    }

    // reset the alloc info for the next scheduler call
    for (itUeAllocMap = ueAllocMap.begin(); itUeAllocMap != ueAllocMap.end(); itUeAllocMap++)
    {
        itUeAllocMap->second->m_dlSymbols = 0;
        itUeAllocMap->second->m_ulSymbols = 0;
        itUeAllocMap->second->m_dlTbSize = 0;
        itUeAllocMap->second->m_ulTbSize = 0;
        itUeAllocMap->second->m_dlSymbolsRetx = 0;
        itUeAllocMap->second->m_ulSymbolsRetx = 0;
        itUeAllocMap->second->m_currTputDl = 0;
        itUeAllocMap->second->m_currTputUl = 0;
        itUeAllocMap->second->m_avgTputDl = 0;
        itUeAllocMap->second->m_avgTputUl = 0;
        itUeAllocMap->second->m_totBufDl = 0;
        itUeAllocMap->second->m_totBufUl = 0;
        itUeAllocMap->second->m_dlAllocDone = false;
        itUeAllocMap->second->m_ulAllocDone = false;
        itUeAllocMap->second->m_rlcPduInfo.clear();
    }

    // add slot for UL control
    TtiAllocInfo ulCtrlSlot(0xFF, TtiAllocInfo::UL_slotAllocInfo, TtiAllocInfo::CTRL, 0);
    ulCtrlSlot.m_dci.m_numSym = 1;
    ulCtrlSlot.m_dci.m_symStart = m_phyMacConfig->GetSymbPerSlot() - 1;
    // ret.m_ulSfAllocInfo.m_ttiAllocInfo.push_back (ulCtrlSlot);
    ret.m_slotAllocInfo.m_ttiAllocInfo.push_back(ulCtrlSlot);

    // m_ulSfAllocInfo.push_back (ret.m_ulSfAllocInfo); // add UL SF info for later calls to
    // scheduler

    m_macSchedSapUser->SchedConfigInd(ret);
    return;
}

bool
MmWaveFlexTtiPfMacScheduler::SortRlcBufferReq(
    MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters i,
    MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters j)
{
    return (i.m_rnti < j.m_rnti);
}

void
MmWaveFlexTtiPfMacScheduler::RefreshDlCqiMaps(void)
{
    NS_LOG_FUNCTION(this << m_wbCqiTimers.size());
    // refresh DL CQI P01 Map
    std::map<uint16_t, uint32_t>::iterator itP10 = m_wbCqiTimers.begin();
    while (itP10 != m_wbCqiTimers.end())
    {
        NS_LOG_INFO(this << " P10-CQI for user " << (*itP10).first << " is "
                         << (uint32_t)(*itP10).second << " thr " << (uint32_t)m_cqiTimersThreshold);
        if ((*itP10).second == 0)
        {
            // delete correspondent entries
            std::map<uint16_t, uint8_t>::iterator itMap = m_wbCqiRxed.find((*itP10).first);
            NS_ASSERT_MSG(itMap != m_wbCqiRxed.end(),
                          " Does not find CQI report for user " << (*itP10).first);
            NS_LOG_INFO(this << " P10-CQI exired for user " << (*itP10).first);
            m_wbCqiRxed.erase(itMap);
            std::map<uint16_t, uint32_t>::iterator temp = itP10;
            itP10++;
            m_wbCqiTimers.erase(temp);
        }
        else
        {
            (*itP10).second--;
            itP10++;
        }
    }

    return;
}

void
MmWaveFlexTtiPfMacScheduler::RefreshUlCqiMaps(void)
{
    // refresh UL CQI  Map
    std::map<uint16_t, uint32_t>::iterator itUl = m_ueCqiTimers.begin();
    while (itUl != m_ueCqiTimers.end())
    {
        NS_LOG_INFO(this << " UL-CQI for user " << (*itUl).first << " is "
                         << (uint32_t)(*itUl).second << " thr " << (uint32_t)m_cqiTimersThreshold);
        if ((*itUl).second == 0)
        {
            // delete correspondent entries
            std::map<uint16_t, struct UlCqiMapElem>::iterator itMap = m_ueUlCqi.find((*itUl).first);
            NS_ASSERT_MSG(itMap != m_ueUlCqi.end(),
                          " Does not find CQI report for user " << (*itUl).first);
            NS_LOG_INFO(this << " UL-CQI expired for user " << (*itUl).first);
            itMap->second.m_ueUlCqi.clear();
            m_ueUlCqi.erase(itMap);
            std::map<uint16_t, uint32_t>::iterator temp = itUl;
            itUl++;
            m_ueCqiTimers.erase(temp);
        }
        else
        {
            (*itUl).second--;
            itUl++;
        }
    }

    return;
}

void
MmWaveFlexTtiPfMacScheduler::UpdateDlRlcBufferInfo(uint16_t rnti, uint8_t lcid, uint16_t size)
{
    NS_LOG_FUNCTION(this);
    std::list<MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it;
    for (it = m_rlcBufferReq.begin(); it != m_rlcBufferReq.end(); it++)
    {
        if (((*it).m_rnti == rnti) && ((*it).m_logicalChannelIdentity == lcid))
        {
            NS_LOG_INFO(this << " UE " << rnti << " LC " << (uint16_t)lcid << " txqueue "
                             << (*it).m_rlcTransmissionQueueSize << " retxqueue "
                             << (*it).m_rlcRetransmissionQueueSize << " status "
                             << (*it).m_rlcStatusPduSize << " decrease " << size);
            // Update queues: RLC tx order Status, ReTx, Tx
            // Update status queue
            if (((*it).m_rlcStatusPduSize > 0) && (size >= (*it).m_rlcStatusPduSize))
            {
                (*it).m_rlcStatusPduSize = 0;
            }
            else if (((*it).m_rlcRetransmissionQueueSize > 0) &&
                     (size >= (*it).m_rlcRetransmissionQueueSize))
            {
                (*it).m_rlcRetransmissionQueueSize = 0;
            }
            else if ((*it).m_rlcTransmissionQueueSize > 0)
            {
                uint32_t rlcOverhead;
                if (lcid == 1)
                {
                    // for SRB1 (using RLC AM) it's better to
                    // overestimate RLC overhead rather than
                    // underestimate it and risk unneeded
                    // segmentation which increases delay
                    rlcOverhead = 4;
                }
                else
                {
                    // minimum RLC overhead due to header
                    rlcOverhead = 2;
                }
                // update transmission queue
                if ((*it).m_rlcTransmissionQueueSize <= size - rlcOverhead)
                {
                    (*it).m_rlcTransmissionQueueSize = 0;
                }
                else
                {
                    (*it).m_rlcTransmissionQueueSize -= size - rlcOverhead;
                }
            }
            return;
        }
    }
}

void
MmWaveFlexTtiPfMacScheduler::UpdateUlRlcBufferInfo(uint16_t rnti, uint16_t size)
{
    size = size - 2; // remove the minimum RLC overhead
    std::map<uint16_t, uint32_t>::iterator it = m_ceBsrRxed.find(rnti);
    if (it != m_ceBsrRxed.end())
    {
        NS_LOG_INFO(this << " Update RLC BSR UE " << rnti << " size " << size << " BSR "
                         << (*it).second);
        if ((*it).second >= size)
        {
            (*it).second -= size;
        }
        else
        {
            (*it).second = 0;
        }
    }
    else
    {
        NS_LOG_ERROR(this << " Does not find BSR report info of UE " << rnti);
    }
}

void
MmWaveFlexTtiPfMacScheduler::DoCschedCellConfigReq(
    const struct MmWaveMacCschedSapProvider::CschedCellConfigReqParameters& params)
{
    NS_LOG_FUNCTION(this);
    // Read the subset of parameters used
    m_cschedCellConfig = params;
    // m_rachAllocationMap.resize (m_cschedCellConfig.m_ulBandwidth, 0);
    MmWaveMacCschedSapUser::CschedUeConfigCnfParameters cnf;
    cnf.m_result = SUCCESS;
    m_macCschedSapUser->CschedUeConfigCnf(cnf);
    return;
}

void
MmWaveFlexTtiPfMacScheduler::DoCschedUeConfigReq(
    const struct MmWaveMacCschedSapProvider::CschedUeConfigReqParameters& params)
{
    NS_LOG_FUNCTION(this << " RNTI " << params.m_rnti << " txMode "
                         << (uint16_t)params.m_transmissionMode);

    std::map<uint16_t, struct UeSchedInfo>::iterator itUe = m_ueSchedInfoMap.find(params.m_rnti);
    if (itUe == m_ueSchedInfoMap.end())
    {
        itUe = m_ueSchedInfoMap
                   .insert(std::pair<uint16_t, struct UeSchedInfo>(params.m_rnti,
                                                                   UeSchedInfo(params.m_rnti)))
                   .first;
        for (unsigned i = 0; i <= 3; i++)
        {
            itUe->second.m_flowStatsDl.push_back(FlowStats(false, &(itUe->second), i));
            itUe->second.m_flowStatsUl.push_back(FlowStats(true, &(itUe->second), i));
        }
    }

    if (m_dlHarqProcessesStatus.find(params.m_rnti) == m_dlHarqProcessesStatus.end())
    {
        // m_dlHarqCurrentProcessId.insert (std::pair <uint16_t,uint8_t > (params.m_rnti, 0));
        DlHarqProcessesStatus_t dlHarqPrcStatus;
        dlHarqPrcStatus.resize(m_phyMacConfig->GetNumHarqProcess(), 0);
        m_dlHarqProcessesStatus.insert(
            std::pair<uint16_t, DlHarqProcessesStatus_t>(params.m_rnti, dlHarqPrcStatus));
        DlHarqProcessesTimer_t dlHarqProcessesTimer;
        dlHarqProcessesTimer.resize(m_phyMacConfig->GetNumHarqProcess(), 0);
        m_dlHarqProcessesTimer.insert(
            std::pair<uint16_t, DlHarqProcessesTimer_t>(params.m_rnti, dlHarqProcessesTimer));
        DlHarqProcessesDciInfoList_t dlHarqTbInfoList;
        dlHarqTbInfoList.resize(m_phyMacConfig->GetNumHarqProcess());
        m_dlHarqProcessesDciInfoMap.insert(
            std::pair<uint16_t, DlHarqProcessesDciInfoList_t>(params.m_rnti, dlHarqTbInfoList));
        DlHarqRlcPduList_t dlHarqRlcPduList;
        dlHarqRlcPduList.resize(m_phyMacConfig->GetNumHarqProcess());
        m_dlHarqProcessesRlcPduMap.insert(
            std::pair<uint16_t, DlHarqRlcPduList_t>(params.m_rnti, dlHarqRlcPduList));
    }

    if (m_ulHarqProcessesStatus.find(params.m_rnti) == m_ulHarqProcessesStatus.end())
    {
        //              m_ulHarqCurrentProcessId.insert (std::pair <uint16_t,uint8_t > (rnti, 0));
        UlHarqProcessesStatus_t ulHarqPrcStatus;
        ulHarqPrcStatus.resize(m_phyMacConfig->GetNumHarqProcess(), 0);
        m_ulHarqProcessesStatus.insert(
            std::pair<uint16_t, UlHarqProcessesStatus_t>(params.m_rnti, ulHarqPrcStatus));
        UlHarqProcessesTimer_t ulHarqProcessesTimer;
        ulHarqProcessesTimer.resize(m_phyMacConfig->GetNumHarqProcess(), 0);
        m_ulHarqProcessesTimer.insert(
            std::pair<uint16_t, UlHarqProcessesTimer_t>(params.m_rnti, ulHarqProcessesTimer));
        UlHarqProcessesDciInfoList_t ulHarqTbInfoList;
        ulHarqTbInfoList.resize(m_phyMacConfig->GetNumHarqProcess());
        m_ulHarqProcessesDciInfoMap.insert(
            std::pair<uint16_t, UlHarqProcessesDciInfoList_t>(params.m_rnti, ulHarqTbInfoList));
    }
}

void
MmWaveFlexTtiPfMacScheduler::DoCschedLcConfigReq(
    const struct MmWaveMacCschedSapProvider::CschedLcConfigReqParameters& params)
{
    NS_LOG_FUNCTION(this);
    std::map<uint16_t, struct UeSchedInfo>::iterator itUe = m_ueSchedInfoMap.find(params.m_rnti);
    if (itUe != m_ueSchedInfoMap.end())
    {
        for (uint16_t i = 0; i < params.m_logicalChannelConfigList.size(); i++)
        {
            if (params.m_logicalChannelConfigList[i].m_direction ==
                LogicalChannelConfigListElement_s::DIR_DL)
            {
                uint8_t lcid = params.m_logicalChannelConfigList[i].m_logicalChannelIdentity;
                for (unsigned j = itUe->second.m_flowStatsDl.size(); j <= lcid; j++)
                {
                    itUe->second.m_flowStatsDl.push_back(FlowStats(false, &(itUe->second), j));
                }
                itUe->second.m_flowStatsDl[lcid].m_qci = params.m_logicalChannelConfigList[i].m_qci;
                if (params.m_logicalChannelConfigList[i].m_qci == EpsBearer::NGBR_LOW_LAT_EMBB_AR)
                {
                    EpsBearer lowLatBearer(EpsBearer::NGBR_LOW_LAT_EMBB_AR);
                    itUe->second.m_flowStatsDl[lcid].m_deadlineUs =
                        lowLatBearer.GetPacketDelayBudgetMs() * 1000;
                }
                m_flowHeap.push_back(&(itUe->second.m_flowStatsDl[lcid]));
            }
            else if (params.m_logicalChannelConfigList[i].m_direction ==
                     LogicalChannelConfigListElement_s::DIR_UL)
            {
                uint8_t lcid = params.m_logicalChannelConfigList[i]
                                   .m_logicalChannelGroup; // use LCG ID instead of LCID
                for (unsigned j = itUe->second.m_flowStatsUl.size(); j <= lcid; j++)
                {
                    itUe->second.m_flowStatsUl.push_back(FlowStats(true, &(itUe->second), j));
                }
                itUe->second.m_flowStatsUl[lcid].m_isUplink = true;
                itUe->second.m_flowStatsUl[lcid].m_qci = params.m_logicalChannelConfigList[i].m_qci;
                if (params.m_logicalChannelConfigList[i].m_qci == EpsBearer::NGBR_LOW_LAT_EMBB_AR)
                {
                    EpsBearer lowLatBearer(EpsBearer::NGBR_LOW_LAT_EMBB_AR);
                    itUe->second.m_flowStatsUl[lcid].m_deadlineUs =
                        lowLatBearer.GetPacketDelayBudgetMs() * 1000;
                }
                m_flowHeap.push_back(&(itUe->second.m_flowStatsUl[lcid]));
            }
            else if (params.m_logicalChannelConfigList[i].m_direction ==
                     LogicalChannelConfigListElement_s::DIR_BOTH)
            {
                uint8_t lcid = params.m_logicalChannelConfigList[i].m_logicalChannelIdentity;
                for (unsigned j = itUe->second.m_flowStatsDl.size(); j <= lcid; j++)
                {
                    itUe->second.m_flowStatsDl.push_back(FlowStats(false, &(itUe->second), j));
                    itUe->second.m_flowStatsUl.push_back(FlowStats(true, &(itUe->second), j));
                }
                itUe->second.m_flowStatsDl[lcid].m_qci = params.m_logicalChannelConfigList[i].m_qci;
                itUe->second.m_flowStatsUl[lcid].m_qci = params.m_logicalChannelConfigList[i].m_qci;

                if (1 ||
                    params.m_logicalChannelConfigList[i].m_qci == EpsBearer::NGBR_LOW_LAT_EMBB_AR)
                {
                    EpsBearer lowLatBearer(EpsBearer::NGBR_LOW_LAT_EMBB_AR);
                    itUe->second.m_flowStatsDl[lcid].m_deadlineUs =
                        lowLatBearer.GetPacketDelayBudgetMs() * 1000;
                    itUe->second.m_flowStatsUl[lcid].m_deadlineUs =
                        lowLatBearer.GetPacketDelayBudgetMs() * 1000;
                }

                m_flowHeap.push_back(&(itUe->second.m_flowStatsDl[lcid]));
                m_flowHeap.push_back(&(itUe->second.m_flowStatsUl[lcid]));
            }
        }
    }
    else
    {
        NS_LOG_ERROR("Cannot find UE info entry");
    }
    return;
}

void
MmWaveFlexTtiPfMacScheduler::DoCschedLcReleaseReq(
    const struct MmWaveMacCschedSapProvider::CschedLcReleaseReqParameters& params)
{
    NS_LOG_FUNCTION(this);
    for (uint16_t i = 0; i < params.m_logicalChannelIdentity.size(); i++)
    {
        std::list<MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it =
            m_rlcBufferReq.begin();
        while (it != m_rlcBufferReq.end())
        {
            if (((*it).m_rnti == params.m_rnti) &&
                ((*it).m_logicalChannelIdentity == params.m_logicalChannelIdentity.at(i)))
            {
                it = m_rlcBufferReq.erase(it);
            }
            else
            {
                it++;
            }
        }
    }
    return;
}

void
MmWaveFlexTtiPfMacScheduler::DoCschedUeReleaseReq(
    const struct MmWaveMacCschedSapProvider::CschedUeReleaseReqParameters& params)
{
    NS_LOG_FUNCTION(this << " Release RNTI " << params.m_rnti);

    // m_dlHarqCurrentProcessId.erase (params.m_rnti);
    m_dlHarqProcessesStatus.erase(params.m_rnti);
    m_dlHarqProcessesTimer.erase(params.m_rnti);
    m_dlHarqProcessesDciInfoMap.erase(params.m_rnti);
    m_dlHarqProcessesRlcPduMap.erase(params.m_rnti);
    // m_ulHarqCurrentProcessId.erase  (params.m_rnti);
    m_ulHarqProcessesTimer.erase(params.m_rnti);
    m_ulHarqProcessesStatus.erase(params.m_rnti);
    m_ulHarqProcessesDciInfoMap.erase(params.m_rnti);
    m_ceBsrRxed.erase(params.m_rnti);
    std::list<MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it =
        m_rlcBufferReq.begin();
    while (it != m_rlcBufferReq.end())
    {
        if ((*it).m_rnti == params.m_rnti)
        {
            NS_LOG_INFO(this << " Erase RNTI " << (*it).m_rnti << " LC "
                             << (uint16_t)(*it).m_logicalChannelIdentity);
            it = m_rlcBufferReq.erase(it);
        }
        else
        {
            it++;
        }
    }
    if (m_nextRntiUl == params.m_rnti)
    {
        m_nextRntiUl = 0;
    }

    if (m_nextRntiDl == params.m_rnti)
    {
        m_nextRntiDl = 0;
    }

    return;
}

} // namespace mmwave

} // namespace ns3
