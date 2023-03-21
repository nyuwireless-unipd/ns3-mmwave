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
*   along with this program; if not, write to the Free Software:100cento

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
*/

#ifndef SRC_MMWAVE_MODEL_MMWAVE_UE_PHY_H_
#define SRC_MMWAVE_MODEL_MMWAVE_UE_PHY_H_

#include "mmwave-amc.h"
#include "mmwave-enb-net-device.h"
#include "mmwave-phy-mac-common.h"

#include <ns3/lte-ue-cphy-sap.h>
#include <ns3/lte-ue-phy-sap.h>
#include <ns3/mmwave-harq-phy.h>
#include <ns3/mmwave-phy.h>
#include <ns3/ptr.h>

#include <map>

namespace ns3
{

class PacketBurst;

namespace mmwave
{

class mmwEnbPhy;

class MmWaveUePhy : public MmWavePhy
{
    friend class UeMemberLteUePhySapProvider;
    friend class MemberLteUeCphySapProvider<MmWaveUePhy>;

  public:
    MmWaveUePhy();

    MmWaveUePhy(Ptr<MmWaveSpectrumPhy> ulPhy, Ptr<MmWaveSpectrumPhy> dlPhy);

    virtual ~MmWaveUePhy();

    // inherited from Object
    static TypeId GetTypeId(void);
    virtual void DoInitialize(void) override;
    virtual void DoDispose(void) override;

    /**
     * Sets the period of the WB CQI generation and report process.
     * The supported values are: {4, 5, 8, 10, 16, 20, 40, 80, 160, 320} slots,
     * see CSI-ReportPeriodicityAndOffset from TS 38.331 V16.0.0 Sec 6.3.2
     *
     * \param period the WB CQI period, in number of slots
     */
    void SetWbCqiPeriod(uint16_t period);

    LteUeCphySapProvider* GetUeCphySapProvider();
    void SetUeCphySapUser(LteUeCphySapUser* s);

    void SetTxPower(double pow);
    double GetTxPower() const;

    void SetNoiseFigure(double pf);
    double GetNoiseFigure() const;

    bool SendPacket(Ptr<Packet> packet);

    Ptr<SpectrumValue> CreateTxPowerSpectralDensity() override;

    void DoSetSubChannels();

    void SetSubChannelsForReception(std::vector<int> mask);
    std::vector<int> GetSubChannelsForReception(void);

    void SetSubChannelsForTransmission(std::vector<int> mask);
    std::vector<int> GetSubChannelsForTransmission(void);

    void DoSendControlMessage(Ptr<MmWaveControlMessage> msg);

    void RegisterToEnb(uint16_t cellId, Ptr<MmWavePhyMacCommon> config);
    void RegisterOtherEnb(uint16_t cellId,
                          Ptr<MmWavePhyMacCommon> config,
                          Ptr<MmWaveEnbNetDevice> enb);
    Ptr<MmWaveSpectrumPhy> GetDlSpectrumPhy() const;
    Ptr<MmWaveSpectrumPhy> GetUlSpectrumPhy() const;

    void ReceiveControlMessageList(std::list<Ptr<MmWaveControlMessage>> msgList);

    /**
     * Marks the beginning of a new NR slot.
     *
     * \param frameNum the current frame
     * \param subframeNum the current subframe
     * \param slotNum the current slot
     */
    void SlotIndication(uint32_t frameNum, uint8_t subframeNum, uint8_t slotNum);

    /**
     * Marks the beginning of a new Transmission Time Interval (TTI).
     *
     * Periodically, it alternates with \ref EndTti in order to scan through the TTIs scheduled
     * within a slot.
     *
     */
    void StartTti();

    /**
     * Marks the end of a Transmission Time Interval (TTI).
     *
     * Periodically, it alternates with \ref StartTti in order to scan through the TTIs scheduled
     * within a slot. Using the duration of the current TTI, the various frame/subframe and slot
     * counters get updated; whenever the end of the current slot is reached, \ref SlotIndication is
     * called.
     *
     */
    void EndTti();

    /**
     * Initializes the slots allocation info for the given frame, subframe and slot.
     *
     * This function is periodically called by \ref SlotIndication in order to initialize the slot
     * allocation structure for the same slot and next subframe (and, eventually, frame). N.S. The
     * timing of such process can not be changed, as future slots might contain UL DCIs that have
     * been previously scheduled in advance.
     *
     * \param frameNum the intended frame number.
     * \param sfNum the intended subframe number.
     * \param slotNum the intended slot number.
     *
     */
    void InitializeSlotAllocation(uint32_t frameNum, uint8_t sfNum, uint8_t slotNum);

    uint32_t GetSubframeNumber(void);

    void PhyDataPacketReceived(Ptr<Packet> p);
    void DelayPhyDataPacketReceived(Ptr<Packet> p);

    void SendDataChannels(Ptr<PacketBurst> pb,
                          std::list<Ptr<MmWaveControlMessage>> ctrlMsg,
                          Time duration,
                          uint8_t slotInd);

    void SendCtrlChannels(std::list<Ptr<MmWaveControlMessage>> ctrlMsg, Time prd);

    uint32_t GetAbsoluteSubframeNo(); // Used for tracing purposes

    Ptr<MmWaveDlCqiMessage> CreateDlCqiFeedbackMessage(const SpectrumValue& sinr);

    void GenerateDlCqiReport(const SpectrumValue& sinr);

    void SetImsi(uint64_t imsi);
    uint64_t GetImsi() const;

    bool IsReceptionEnabled();
    void ResetReception();

    uint16_t GetRnti();

    void SetPhySapUser(MmWaveUePhySapUser* ptr);

    void SetHarqPhyModule(Ptr<MmWaveHarqPhy> harq);

    void ReceiveLteDlHarqFeedback(DlHarqInfo m);

    void UpdateSinrEstimate(uint16_t cellId, double sinr);

  private:
    void DoReset();
    void DoStartCellSearch(uint16_t dlEarfcn);
    void DoSynchronizeWithEnb(uint16_t cellId);
    void DoSynchronizeWithEnb(uint16_t cellId, uint16_t dlEarfcn);
    void DoSetPa(double pa);
    void DoSetRsrpFilterCoefficient(uint8_t rsrpFilterCoefficient);
    void DoSetDlBandwidth(uint8_t ulBandwidth);
    void DoConfigureUplink(uint16_t ulEarfcn, uint8_t ulBandwidth);
    void DoConfigureReferenceSignalPower(int8_t referenceSignalPower);
    void DoSetRnti(uint16_t rnti);
    void DoSetTransmissionMode(uint8_t txMode);
    void DoSetSrsConfigurationIndex(uint16_t srcCi);

    /**
     * Triggers the callback for the ReportUlPhyTransmission Trace Source
     *
     * Sets up the necessary info for the ReportUlPhyTransmission source and triggers the related
     * callback
     *
     * \param dciInfo the actual DCI info for the current UL transmission
     * \param tddType the TDD TTI type. Either DATA or CTRL
     */
    void TraceUlPhyTransmission(DciInfoElementTdma dciInfo, uint8_t tddType);

    void ReceiveDataPeriod(uint32_t slotNum);

    MmWaveUePhySapUser* m_phySapUser;

    LteUeCphySapProvider* m_ueCphySapProvider;
    LteUeCphySapUser* m_ueCphySapUser;

    Ptr<MmWaveAmc> m_amc;
    std::vector<int> m_subChannelsForTx;
    std::vector<int> m_subChannelsforRx;

    uint16_t m_wbCqiPeriod; //!< The period of the WB CQI, in number of slots. See TS 38.331 V16.0.0
                            //!< Sec 6.3.2
    Time m_wbCqiLast;

    TtiAllocInfo::TddMode m_prevTtiDir; //!< Time Division Duplexing (TDD) mode of the previous Tti.

    SlotAllocInfo m_currSlotAllocInfo; //!< Holds the allocation info for the current NR slot
    bool m_ulGrant; // true if no uplink grant in subframe, need to transmit UL control in PUCCH
                    // instead
    bool m_sfAllocInfoUpdated;

    Time m_dataPeriod; //!< Data period time duration

    bool m_dlConfigured;
    bool m_ulConfigured;

    TracedCallback<uint64_t, SpectrumValue&, SpectrumValue&> m_reportCurrentCellRsrpSinrTrace;

    TracedCallback<uint64_t, uint64_t> m_reportUlTbSize;
    TracedCallback<uint64_t, uint64_t> m_reportDlTbSize;

    TracedCallback<PhyTransmissionTraceParams>
        m_ulPhyTrace; //!< Traces the current TTI allocation info, from the UE side

    uint8_t m_prevSlot;

    bool m_receptionEnabled;
    uint16_t m_rnti;
    uint64_t m_imsi;

    Ptr<MmWaveHarqPhy> m_harqPhyModule;

    std::vector<int> m_channelChunks;

    TtiAllocInfo m_currTti; //!< Holds the allocation info for the current Tti.

    std::map<uint16_t, std::pair<Ptr<MmWavePhyMacCommon>, Ptr<MmWaveEnbNetDevice>>> m_registeredEnb;

    EventId m_sendDataChannelEvent;
    EventId m_sendDlHarqFeedbackEvent;
    bool m_phyReset;

    std::map<uint16_t, double> m_cellSinrMap;

    uint8_t m_consecutiveSinrBelowThreshold;
    long double m_outageThreshold;
    uint8_t m_n310;
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_UE_PHY_H_ */
