/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *                 Dual Connectivity and Handover functionalities
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                               Integration of Carrier Aggregation
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_ENB_MAC_H_
#define SRC_MMWAVE_MODEL_MMWAVE_ENB_MAC_H_

#include "mmwave-enb-mac.h"
#include "mmwave-mac.h"
#include "mmwave-phy-mac-common.h"

#include <ns3/lte-ccm-mac-sap.h>
#include <ns3/lte-enb-cmac-sap.h>
#include <ns3/lte-mac-sap.h>

namespace ns3
{

namespace mmwave
{

struct MmWaveDlHarqProcessInfo
{
    Ptr<PacketBurst> m_pktBurst;
    // maintain list of LCs contained in this TB
    // used to signal HARQ failure to RLC handlers
    std::vector<uint8_t> m_lcidList;
};

typedef std::vector<MmWaveDlHarqProcessInfo> MmWaveDlHarqProcessesBuffer_t;

class MmWaveEnbMac : public Object
{
    friend class MmWaveEnbMacMemberEnbCmacSapProvider;
    friend class MmWaveMacEnbMemberPhySapUser;

  public:
    static TypeId GetTypeId(void);
    MmWaveEnbMac(void);
    virtual ~MmWaveEnbMac(void);
    virtual void DoDispose(void) override;

    struct TransmitPduParameters
    {
        Ptr<Packet> pdu; /**< the RLC PDU */
        uint16_t rnti;   /**< the C-RNTI identifying the UE */
        uint8_t lcid;    /**< the logical channel id corresponding to the sending RLC instance */
        uint8_t layer;   /**< the layer value that was passed by the MAC in the call to
                            NotifyTxOpportunity that generated this PDU */
        uint8_t harqProcessId; /**< the HARQ process id that was passed by the MAC in the call to
                                  NotifyTxOpportunity that generated this PDU */
    };

    struct ReportBufferStatusParameters
    {
        uint16_t rnti; /**< the C-RNTI identifying the UE */
        uint8_t lcid;  /**< the logical channel id corresponding to the sending RLC instance */
        uint32_t txQueueSize;     /**< the current size of the RLC transmission queue */
        uint16_t txQueueHolDelay; /**< the Head Of Line delay of the transmission queue */
        uint32_t retxQueueSize;   /**<  the current size of the RLC retransmission queue in bytes */
        uint16_t retxQueueHolDelay; /**<  the Head Of Line delay of the retransmission queue */
        uint16_t
            statusPduSize; /**< the current size of the pending STATUS RLC  PDU message in bytes */
    };

    /**
     * Data structure used for tracing purposes only.
     *
     * Specifically, it carries the information regarding a TTI allocation.
     */
    struct MmWaveSchedTraceInfo
    {
        uint8_t m_ccId; //!< The Component Carrier ID
        MmWaveMacSchedSapUser::SchedConfigIndParameters
            m_indParam; //!< Structure containing all the scheduling decisions
    };

    /*
      struct RachConfig
      {
            uint8_t numberOfRaPreambles;
            uint8_t preambleTransMax;
            uint8_t raResponseWindowSize;
      };

      struct AllocateNcRaPreambleReturnValue
      {
            bool valid; ///< true if a valid RA config was allocated, false otherwise
            uint8_t raPreambleId; ///< random access preamble id
            uint8_t raPrachMaskIndex; /// PRACH mask index
      };
    */
    void SetComponentCarrierId(uint8_t index);
    void SetConfigurationParameters(Ptr<MmWavePhyMacCommon> ptrConfig);
    Ptr<MmWavePhyMacCommon> GetConfigurationParameters(void) const;

    void SetCellId(uint16_t cellId);

    // forwarded from LteMacSapProvider
    void DoTransmitPdu(LteMacSapProvider::TransmitPduParameters);
    void DoReportBufferStatus(LteMacSapProvider::ReportBufferStatusParameters);
    void DoUlCqiReport(MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters ulcqi);

    /**
     * \brief Receive from the PHY layer the current frame, subframe, slot numbers and the current
     * starting OFDM symbol within the slot. \param sfnSf The current frame, subframe, slot and
     * starting OFDM symbol counters
     */
    void DoSlotIndication(SfnSf sfnSf);

    void SetMcs(int mcs);

    void AssociateUeMAC(uint64_t imsi);

    void SetForwardUpCallback(Callback<void, Ptr<Packet>> cb);

    //  void PhyPacketRx (Ptr<Packet> p);

    void DoReceivePhyPdu(Ptr<Packet> p);

    void DoReceiveControlMessage(Ptr<MmWaveControlMessage> msg);

    void DoSchedConfigIndication(MmWaveMacSchedSapUser::SchedConfigIndParameters ind);

    MmWaveEnbPhySapUser* GetPhySapUser();
    void SetPhySapProvider(MmWavePhySapProvider* ptr);

    MmWaveMacSchedSapUser* GetMmWaveMacSchedSapUser();
    void SetMmWaveMacSchedSapProvider(MmWaveMacSchedSapProvider* ptr);

    MmWaveMacCschedSapUser* GetMmWaveMacCschedSapUser();
    void SetMmWaveMacCschedSapProvider(MmWaveMacCschedSapProvider* ptr);

    LteMacSapProvider* GetUeMacSapProvider(void);
    LteEnbCmacSapProvider* GetEnbCmacSapProvider(void);

    void SetEnbCmacSapUser(LteEnbCmacSapUser* s);
    void ReceiveRachPreamble(uint32_t raId);

    // forwarded from FfMacCchedSapUser
    void DoCschedCellConfigCnf(MmWaveMacCschedSapUser::CschedCellConfigCnfParameters params);
    void DoCschedUeConfigCnf(MmWaveMacCschedSapUser::CschedUeConfigCnfParameters params);
    void DoCschedLcConfigCnf(MmWaveMacCschedSapUser::CschedLcConfigCnfParameters params);
    void DoCschedLcReleaseCnf(MmWaveMacCschedSapUser::CschedLcReleaseCnfParameters params);
    void DoCschedUeReleaseCnf(MmWaveMacCschedSapUser::CschedUeReleaseCnfParameters params);
    void DoCschedUeConfigUpdateInd(
        MmWaveMacCschedSapUser::CschedUeConfigUpdateIndParameters params);
    void DoCschedCellConfigUpdateInd(
        MmWaveMacCschedSapUser::CschedCellConfigUpdateIndParameters params);

    void SetLteCcmMacSapUser(LteCcmMacSapUser* s);
    LteCcmMacSapProvider* GetLteCcmMacSapProvider();

    // forwarded from LteCcmMacSapProvider
    void DoReportMacCeToScheduler(MacCeListElement_s bsr);

    /**
     * TracedCallback signature for
     *
     * \param [in] rnti C-RNTI scheduled.
     * \param [in] the cellId
     * \param [in] the allocated transport block size
     * \param [in] the number of HARQ retransmissions for that packet
     */
    typedef void (*HarqRetxCallback)(uint16_t rnti,
                                     uint16_t cellId,
                                     uint32_t tbSize,
                                     uint8_t numRetx);

  private:
    // forwarded from LteEnbCmacSapProvider
    void DoConfigureMac(uint8_t ulBandwidth, uint8_t dlBandwidth);
    void DoAddUe(uint16_t rnti);
    void DoRemoveUe(uint16_t rnti);
    void DoAddLc(LteEnbCmacSapProvider::LcInfo lcinfo, LteMacSapUser* msu);
    void DoReconfigureLc(LteEnbCmacSapProvider::LcInfo lcinfo);
    void DoReleaseLc(uint16_t rnti, uint8_t lcid);
    void UeUpdateConfigurationReq(LteEnbCmacSapProvider::UeConfig params);
    LteEnbCmacSapProvider::RachConfig DoGetRachConfig();
    LteEnbCmacSapProvider::AllocateNcRaPreambleReturnValue DoAllocateNcRaPreamble(uint16_t rnti);
    uint8_t AllocateTbUid();

    void DoDlHarqFeedback(DlHarqInfo params);
    void DoUlHarqFeedback(UlHarqInfo params);

    /**
     * Triggers the callback for the SchedulingTraceEnb Trace Source
     *
     * Sets up the necessary info for the SchedulingTraceEnb source and triggers the related
     * callback
     *
     * \param ind the actual scheduling info
     */
    void TraceSchedInfo(MmWaveMacSchedSapUser::SchedConfigIndParameters ind);

    Ptr<MmWavePhyMacCommon> m_phyMacConfig;

    LteMacSapProvider* m_macSapProvider;
    LteEnbCmacSapProvider* m_cmacSapProvider;
    LteEnbCmacSapUser* m_cmacSapUser;

    // Sap For ComponentCarrierManager 'Uplink case'
    LteCcmMacSapProvider* m_ccmMacSapProvider; ///< CCM MAC SAP provider
    LteCcmMacSapUser* m_ccmMacSapUser;         ///< CCM MAC SAP user

    /// component carrier Id used to address sap
    uint8_t m_componentCarrierId;

    uint32_t m_frameNum;
    uint8_t m_sfNum;
    uint8_t m_slotNum;

    uint8_t m_tbUid;
    std::map<uint32_t, struct MacPduInfo> m_macPduMap;

    std::list<uint16_t> m_associatedUe;

    Callback<void, Ptr<Packet>> m_forwardUpCallback;

    std::vector<DlCqiInfo> m_dlCqiReceived;
    std::vector<MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters> m_ulCqiReceived;
    std::vector<MacCeElement> m_ulCeReceived; // CE received (BSR up to now)

    MmWavePhySapProvider* m_phySapProvider;
    MmWaveEnbPhySapUser* m_phySapUser;

    MmWaveMacSchedSapProvider* m_macSchedSapProvider;
    MmWaveMacSchedSapUser* m_macSchedSapUser;
    MmWaveMacCschedSapProvider* m_macCschedSapProvider;
    MmWaveMacCschedSapUser* m_macCschedSapUser;

    std::map<uint8_t, uint32_t> m_receivedRachPreambleCount;

    std::map<uint16_t, std::map<uint8_t, LteMacSapUser*>> m_rlcAttached;

    std::vector<DlHarqInfo> m_dlHarqInfoReceived; // DL HARQ feedback received
    std::vector<UlHarqInfo> m_ulHarqInfoReceived; // UL HARQ feedback received
    std::map<uint16_t, MmWaveDlHarqProcessesBuffer_t>
        m_miDlHarqProcessesPackets; // Packet under trasmission of the DL HARQ process

    /**
     * info associated with a preamble allocated for non-contention based RA
     *
     */
    struct NcRaPreambleInfo
    {
        uint16_t rnti;   ///< rnti previously allocated for this non-contention based RA procedure
        Time expiryTime; ///< value the expiration time of this allocation (so that stale preambles
                         ///< can be reused)
    };

    uint8_t m_numberOfRaPreambles;
    uint8_t m_preambleTransMax;
    uint8_t m_raResponseWindowSize;

    /**
     * map storing as key the random acccess preamble IDs allocated for
     * non-contention based access, and as value the associated info
     *
     */
    std::map<uint8_t, NcRaPreambleInfo> m_allocatedNcRaPreambleMap;

    uint16_t m_cellId;

    TracedCallback<uint16_t, uint16_t, uint32_t, uint8_t> m_macDlTxSizeRetx;

    TracedCallback<uint16_t, uint8_t, uint32_t> m_txMacPacketTraceEnb;

    TracedCallback<MmWaveSchedTraceInfo>
        m_schedEnbInfo; //!< Trace information registering the scheduling decisions undertaken by
                        //!< the scheduler.
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_ENB_MAC_H_ */
