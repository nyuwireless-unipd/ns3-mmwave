/*
 * mmwave-rr-mac-scheduler.h
 *
 *  Created on: Jan 10, 2015
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_MAXRATE_MAC_SCHEDULER_H_
#define SRC_MMWAVE_MODEL_MMWAVE_MAXRATE_MAC_SCHEDULER_H_

#include "mmwave-amc.h"
#include "mmwave-mac-csched-sap.h"
#include "mmwave-mac-sched-sap.h"
#include "mmwave-mac-scheduler.h"
#include "string"

#include <functional>
#include <queue>
#include <set>
#include <vector>

namespace ns3
{

namespace mmwave
{

class MmWaveFlexTtiMaxRateMacScheduler : public MmWaveMacScheduler
{
  public:
    typedef std::vector<uint8_t> DlHarqProcessesStatus_t;
    typedef std::vector<uint8_t> DlHarqProcessesTimer_t;
    typedef std::vector<DciInfoElementTdma> DlHarqProcessesDciInfoList_t;
    typedef std::vector<std::vector<struct RlcPduInfo>>
        DlHarqRlcPduList_t; // vector of the LCs per per UE HARQ process
    //  typedef std::vector < RlcPduElement > DlHarqRlcPduList_t; // vector of the 8 HARQ processes
    //per UE

    typedef std::vector<uint8_t> UlHarqProcessesTimer_t;
    typedef std::vector<DciInfoElementTdma> UlHarqProcessesDciInfoList_t;
    typedef std::vector<uint8_t> UlHarqProcessesStatus_t;

    MmWaveFlexTtiMaxRateMacScheduler();

    virtual ~MmWaveFlexTtiMaxRateMacScheduler();
    virtual void DoDispose(void) override;
    static TypeId GetTypeId(void);

    virtual void SetMacSchedSapUser(MmWaveMacSchedSapUser* sap) override;
    virtual void SetMacCschedSapUser(MmWaveMacCschedSapUser* s) override;

    virtual MmWaveMacSchedSapProvider* GetMacSchedSapProvider() override;
    virtual MmWaveMacCschedSapProvider* GetMacCschedSapProvider() override;

    virtual void ConfigureCommonParameters(Ptr<MmWavePhyMacCommon> config) override;

    static bool SortRlcBufferReq(MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters i,
                                 MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters j);

    void RefreshDlCqiMaps(void);
    void RefreshUlCqiMaps(void);

    void UpdateDlRlcBufferInfo(uint16_t rnti, uint8_t lcid, uint16_t size);
    void UpdateUlRlcBufferInfo(uint16_t rnti, uint16_t size);

    friend class MmWaveFlexTtiMaxRateMacSchedSapProvider;
    friend class MmWaveFlexTtiMaxRateMacCschedSapProvider;

  private:
    struct UeSchedInfo;

    struct FlowStats
    {
        /*FlowStats () :
                m_isUplink (false), m_ueSchedInfo (0),
                m_lcid (0), m_arrivalRate (0.0), m_grantedRate(0.0),
                m_qci (0), m_txQueueHolDelay (0), m_reTxQueueHolDelay (0), m_probErr (0.0),
                m_deadlineUs (0)
        {
        }*/

        FlowStats(bool uplink, UeSchedInfo* ueSchedInfo, uint8_t lcid)
            : m_isUplink(uplink),
              m_ueSchedInfo(ueSchedInfo),
              m_lcid(lcid),
              m_arrivalRate(0.0),
              m_grantedRate(0.0),
              m_qci(0),
              m_txQueueHolDelay(0),
              m_reTxQueueHolDelay(0),
              m_probErr(0.0),
              m_deadlineUs(0),
              m_totalBufSize(0),
              m_totalSchedSize(0)
        {
            NS_ASSERT(ueSchedInfo != 0);
        }

        bool m_isUplink;            // is uplink?
        UeSchedInfo* m_ueSchedInfo; // pointer to parent UE Info
        uint8_t m_lcid;             // LCID (for DL) or LC Group ID (for UL)
        double m_arrivalRate;       // Mbps
        double m_grantedRate;       // Mbps
        uint8_t m_qci;              // We interpret QCI 69 as delay critical
        // uint32_t m_deliveryDebt;
        double m_txQueueHolDelay;
        uint32_t m_reTxQueueHolDelay;
        double m_probErr; // expected probability of each HARQ TX/reTX failure (i.e. 1/E[num TX to
                          // success])
        double m_deadlineUs;                 // relative deadline
        std::list<uint32_t> m_txPacketSizes; // estimated packet sizes from consecutive BSRs
        uint32_t m_totalBufSize;
        std::list<uint32_t> m_retxPacketSizes;
        std::list<double> m_txPacketDelays; // estimated delays for each packet
        std::list<double> m_retxPacketDelays;

        // We maintain a queue of PDU sizes scheduled in the last M subframes.
        // M = delay between scheduling and transmission (default DL = 1, UL = 2)
        // The sum of these M elements is subtracted from the BSR to account for
        // data that has been scheduled but not yet extracted from the DL or UL queue.
        std::list<uint32_t> m_schedPacketSizes;
        uint32_t m_totalSchedSize; // total of last M elements in list
    };

    struct UeSchedInfo
    {
        UeSchedInfo()
            : m_rnti(0),
              m_dlMcs(0),
              m_ulMcs(0),
              m_maxDlBufSize(0),
              m_maxUlBufSize(0),
              m_maxDlSymbols(0),
              m_maxUlSymbols(0),
              m_dlSymbols(0),
              m_ulSymbols(0),
              m_dlSymbolsRetx(0),
              m_ulSymbolsRetx(0),
              m_dlTbSize(0),
              m_ulTbSize(0),
              m_dlAllocDone(false),
              m_ulAllocDone(false),
              m_avgTputDl(0.0),
              m_avgTputUl(0.0),
              m_lastAvgTputDl(0.0),
              m_lastAvgTputUl(0.0),
              m_currTputDl(0.0),
              m_currTputUl(0.0),
              m_totBufDl(0),
              m_totBufUl(0),
              m_allocUlLast(false)
        {
        }

        UeSchedInfo(uint16_t rnti)
            : m_rnti(rnti),
              m_dlMcs(0),
              m_ulMcs(0),
              m_maxDlBufSize(0),
              m_maxUlBufSize(0),
              m_maxDlSymbols(0),
              m_maxUlSymbols(0),
              m_dlSymbols(0),
              m_ulSymbols(0),
              m_dlSymbolsRetx(0),
              m_ulSymbolsRetx(0),
              m_dlTbSize(0),
              m_ulTbSize(0),
              m_dlAllocDone(false),
              m_ulAllocDone(false),
              m_avgTputDl(0.0),
              m_avgTputUl(0.0),
              m_lastAvgTputDl(0.0),
              m_lastAvgTputUl(0.0),
              m_currTputDl(0.0),
              m_currTputUl(0.0),
              m_totBufDl(0),
              m_totBufUl(0),
              m_allocUlLast(false)
        {
        }

        uint16_t m_rnti;
        uint8_t m_dlMcs;
        uint8_t m_ulMcs;
        uint32_t m_maxDlBufSize;
        uint32_t m_maxUlBufSize;
        uint8_t m_maxDlSymbols;
        uint8_t m_maxUlSymbols;
        uint8_t m_dlSymbols;
        uint8_t m_ulSymbols;
        uint8_t m_dlSymbolsRetx;
        uint8_t m_ulSymbolsRetx;
        uint32_t m_dlTbSize;
        uint32_t m_ulTbSize;
        std::vector<struct RlcPduInfo> m_rlcPduInfo;
        bool m_dlAllocDone;
        bool m_ulAllocDone;
        std::vector<FlowStats> m_flowStatsDl; // for each LC
        std::vector<FlowStats> m_flowStatsUl;
        double m_avgTputDl;
        double m_avgTputUl;
        double m_lastAvgTputDl;
        double m_lastAvgTputUl;
        double m_currTputDl;
        double m_currTputUl;
        uint32_t m_totBufDl;
        uint32_t m_totBufUl;
        bool m_allocUlLast;
    };

    static bool CompareUeWeightsMaxRate(UeSchedInfo* lue, UeSchedInfo* rue)
    {
        double lPfMetric = std::max(lue->m_currTputDl, lue->m_currTputUl);
        double rPfMetric = std::max(rue->m_currTputDl, rue->m_currTputUl);
        return (lPfMetric > rPfMetric);
    }

    unsigned CalcMinTbSizeNumSym(unsigned mcs, unsigned bufSize, unsigned& tbSize);

    uint32_t BsrId2BufferSize(uint8_t val)
    {
        NS_ABORT_MSG_UNLESS(val < 64, "val = " << val << " is out of range");
        return BufferSizeLevelBsrTable[val];
    }

    uint8_t BufferSize2BsrId(uint32_t val)
    {
        int index = 0;
        if (BufferSizeLevelBsrTable[63] < val)
        {
            index = 63;
        }
        else
        {
            while (BufferSizeLevelBsrTable[index] < val)
            {
                NS_ASSERT(index < 64);
                index++;
            }
        }

        return (index);
    }

    uint8_t UpdateDlHarqProcessId(uint16_t rnti);
    uint8_t UpdateUlHarqProcessId(uint16_t rnti);

    //
    // Implementation of the CSCHED API primitives
    // (See 4.1 for description of the primitives)
    //

    void DoCschedCellConfigReq(
        const struct MmWaveMacCschedSapProvider::CschedCellConfigReqParameters& params);

    void DoCschedUeConfigReq(
        const struct MmWaveMacCschedSapProvider::CschedUeConfigReqParameters& params);

    void DoCschedLcConfigReq(
        const struct MmWaveMacCschedSapProvider::CschedLcConfigReqParameters& params);

    void DoCschedLcReleaseReq(
        const struct MmWaveMacCschedSapProvider::CschedLcReleaseReqParameters& params);

    void DoCschedUeReleaseReq(
        const struct MmWaveMacCschedSapProvider::CschedUeReleaseReqParameters& params);

    //
    // Implementation of the SCHED API primitives
    // (See 4.2 for description of the primitives)
    //

    void DoSchedDlRlcBufferReq(
        const struct MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters& params);

    void DoSchedDlCqiInfoReq(
        const MmWaveMacSchedSapProvider::SchedDlCqiInfoReqParameters& params); // Put in UML

    void DoSchedUlCqiInfoReq(
        const struct MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters& params);

    void DoSchedUlMacCtrlInfoReq(
        const struct MmWaveMacSchedSapProvider::SchedUlMacCtrlInfoReqParameters& params);

    void DoSchedTriggerReq(
        const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params);

    bool DoSchedDlTriggerReq(
        const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params,
        MmWaveMacSchedSapUser::SchedConfigIndParameters& ret,
        uint32_t frameNum,
        unsigned int sfNum,
        unsigned int islot);

    bool DoSchedUlTriggerReq(
        const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params,
        MmWaveMacSchedSapUser::SchedConfigIndParameters& ret,
        uint32_t frameNum,
        unsigned int sfNum,
        unsigned int islot);

    void DoSchedSetMcs(int mcs);
    /**
     * \brief Refresh HARQ processes according to the timers
     *
     */
    void RefreshHarqProcesses();

    Ptr<MmWaveAmc> m_amc;

    /*
     * Vectors of UE's RLC info
     */
    std::list<MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters> m_rlcBufferReq;

    /*
     * Map of UE's DL CQI WB received
     */
    std::map<uint16_t, uint8_t> m_wbCqiRxed;
    /*
     * Map of UE's timers on DL CQI WB received
     */
    std::map<uint16_t, uint32_t> m_wbCqiTimers;

    uint32_t m_cqiTimersThreshold; // # of TTIs for which a CQI can be considered valid

    /*
     * Map of UEs' UL-CQI per RBG
     */
    struct UlCqiMapElem
    {
        UlCqiMapElem(std::vector<double> ulCqi, uint8_t nSym, uint32_t tbs)
            : m_ueUlCqi(ulCqi),
              m_numSym(nSym),
              m_tbSize(tbs)
        {
        }

        std::vector<double> m_ueUlCqi;
        uint8_t m_numSym;
        uint32_t m_tbSize;
    };

    std::map<uint16_t, struct UlCqiMapElem> m_ueUlCqi;
    /*
     * Map of UEs' timers on UL-CQI per RBG
     */
    std::map<uint16_t, uint32_t> m_ueCqiTimers;

    /*
     * Map of UE's buffer status reports received
     */
    std::map<uint16_t, uint32_t> m_ceBsrRxed;

    uint16_t m_nextRnti;
    uint64_t m_nextRntiDl;
    uint64_t m_nextRntiUl;

    uint32_t m_frameNo;
    uint8_t m_tbUid;
    uint32_t m_numChunks;
    uint32_t m_numDataSymbols;

    MmWaveMacSchedSapProvider* m_macSchedSapProvider;
    MmWaveMacSchedSapUser* m_macSchedSapUser;
    MmWaveMacCschedSapUser* m_macCschedSapUser;
    MmWaveMacCschedSapProvider* m_macCschedSapProvider;

    MmWaveMacCschedSapProvider::CschedCellConfigReqParameters m_cschedCellConfig;

    struct AllocMapElem
    {
        AllocMapElem(std::vector<uint16_t> rntiMap, uint8_t nSym, uint32_t tbs)
            : m_rntiPerChunk(rntiMap),
              m_numSym(nSym),
              m_tbSize(tbs)
        {
        }

        std::vector<uint16_t> m_rntiPerChunk;
        uint8_t m_numSym;
        uint32_t m_tbSize;
    };
    /*
     * Map of previous allocated UE per RBG
     * (used to retrieve info from UL-CQI)
     */
    std::map<uint32_t, struct AllocMapElem> m_ulAllocationMap;

    // HARQ attributes
    /**
     * m_harqOn when false inhibit te HARQ mechanisms (by default active)
     */
    bool m_harqOn;
    uint8_t m_numHarqProcess;
    uint8_t m_harqTimeout;

    std::map<uint16_t, uint8_t> m_dlHarqCurrentProcessId;
    // HARQ status
    //  0: process Id available
    //  x>0: process Id equal to `x` trasmission count
    std::map<uint16_t, DlHarqProcessesStatus_t> m_dlHarqProcessesStatus;
    std::map<uint16_t, DlHarqProcessesTimer_t> m_dlHarqProcessesTimer;
    std::map<uint16_t, DlHarqProcessesDciInfoList_t> m_dlHarqProcessesDciInfoMap;
    std::map<uint16_t, DlHarqRlcPduList_t> m_dlHarqProcessesRlcPduMap;
    std::vector<DlHarqInfo> m_dlHarqInfoList; // HARQ retx buffered
    std::vector<UlHarqInfo> m_ulHarqInfoList; // HARQ retx buffered

    std::map<uint16_t, uint8_t> m_ulHarqCurrentProcessId;
    // HARQ status
    //  0: process Id available
    //  x>0: process Id equal to `x` trasmission count
    std::map<uint16_t, UlHarqProcessesStatus_t> m_ulHarqProcessesStatus;
    std::map<uint16_t, UlHarqProcessesTimer_t> m_ulHarqProcessesTimer;
    std::map<uint16_t, UlHarqProcessesDciInfoList_t> m_ulHarqProcessesDciInfoMap;

    // needed to keep track of uplink allocations in later slots
    std::list<struct SlotAllocInfo> m_ulSfAllocInfo;

    static const unsigned m_macHdrSize;
    static const unsigned m_subHdrSize;
    static const unsigned m_rlcHdrSize;

    double m_berDl; // used for SNR-based AMC model

    // for testing
    bool m_fixedMcsDl;
    bool m_fixedMcsUl;
    uint8_t m_mcsDefaultDl;
    uint8_t m_mcsDefaultUl;
    bool m_dlOnly;
    bool m_ulOnly;

    // typedef std::priority_queue <FlowStats, std::vector<FlowStats*>, CompareWeightDesc>
    // flowQueue_t; flowQueue_t m_flowQueue;

    std::map<uint16_t, UeSchedInfo> m_ueSchedInfoMap;
    std::vector<UeSchedInfo*> m_ueSchedInfoHeap;

    bool m_fixedTti;      // one slot per TTI
    uint8_t m_symPerSlot; // symbols per slot

    double m_timeWindow;

    std::vector<FlowStats*> m_flowHeap;
    std::vector<UeSchedInfo*> m_ueStatHeap;
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAXRATE_MAC_SCHEDULER_H_ */
