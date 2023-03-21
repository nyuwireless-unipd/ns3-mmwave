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

#ifndef SRC_MMWAVE_MODEL_MMWAVE_UE_MAC_H_
#define SRC_MMWAVE_MODEL_MMWAVE_UE_MAC_H_

#include "mmwave-mac.h"

#include <ns3/lte-mac-sap.h>
#include <ns3/lte-radio-bearer-tag.h>
#include <ns3/lte-ue-cmac-sap.h>

namespace ns3
{

namespace mmwave
{

class MmWaveControlMessage;

class MmWaveUeMac : public Object
{
    friend class UeMemberMmWaveUeCmacSapProvider;
    friend class UeMemberMmWaveMacSapProvider;
    friend class MacUeMemberPhySapUser;

  public:
    static TypeId GetTypeId(void);

    MmWaveUeMac(void);
    ~MmWaveUeMac(void);
    virtual void DoDispose(void) override;

    void SetUeCmacSapUser(LteUeCmacSapUser* s);
    LteUeCmacSapProvider* GetUeCmacSapProvider(void);
    LteMacSapProvider* GetUeMacSapProvider(void);

    void SetConfigurationParameters(Ptr<MmWavePhyMacCommon> ptrConfig);
    Ptr<MmWavePhyMacCommon> GetConfigurationParameters(void) const;

    /**
     * \brief Receive from the PHY layer the current frame, subframe, slot numbers and the current
     * starting OFDM symbol within the slot. \param sfn The current frame, subframe, slot and
     * starting OFDM symbol counters
     */
    void DoSlotIndication(SfnSf sfn);

    MmWaveUePhySapUser* GetPhySapUser();
    void SetPhySapProvider(MmWavePhySapProvider* ptr);

    void RecvRaResponse(BuildRarListElement_s raResponse);

    void SetComponentCarrierId(uint8_t index);

    /**
     * Assign a fixed random variable stream number to the random variables
     * used by this model.  Return the number of streams (possibly zero) that
     * have been assigned.
     *
     * \param stream first stream index to use
     * \return the number of stream indices assigned by this model
     */
    int64_t AssignStreams(int64_t stream);

  private:
    void DoTransmitPdu(LteMacSapProvider::TransmitPduParameters params);
    void DoReportBufferStatus(LteMacSapProvider::ReportBufferStatusParameters params);

    // forwarded from PHY SAP
    void DoReceivePhyPdu(Ptr<Packet> p);
    void DoReceiveControlMessage(Ptr<MmWaveControlMessage> msg);
    // void DoNotifyHarqDeliveryFailure (uint8_t harqId);

    // forwarded from UE CMAC SAP
    void DoConfigureRach(LteUeCmacSapProvider::RachConfig rc);
    void DoStartContentionBasedRandomAccessProcedure();
    void DoSetRnti(uint16_t rnti);
    void DoStartNonContentionBasedRandomAccessProcedure(uint16_t rnti,
                                                        uint8_t rapId,
                                                        uint8_t prachMask);
    void AddLc(uint8_t lcId,
               LteUeCmacSapProvider::LogicalChannelConfig lcConfig,
               LteMacSapUser* msu);
    void DoRemoveLc(uint8_t lcId);
    void DoReset();

    void RandomlySelectAndSendRaPreamble();
    void SendRaPreamble(bool contention);
    void SendReportBufferStatus(void);
    void RefreshHarqProcessesPacketBuffer(void);

    std::map<uint32_t, struct MacPduInfo>::iterator AddToMacPduMap(DciInfoElementTdma dci,
                                                                   unsigned activeLcs);

    /// component carrier Id --> used to address sap
    uint8_t m_componentCarrierId;

    Ptr<MmWavePhyMacCommon> m_phyMacConfig;

    LteUeCmacSapUser* m_cmacSapUser;
    LteUeCmacSapProvider* m_cmacSapProvider;

    SlotAllocInfo m_DataTxAllocationList;

    MmWavePhySapProvider* m_phySapProvider;
    MmWaveUePhySapUser* m_phySapUser;
    LteMacSapProvider* m_macSapProvider;

    uint32_t m_frameNum;
    uint8_t m_sfNum;
    uint8_t m_slotNum;

    // uint8_t  m_tbUid;
    std::map<uint32_t, struct MacPduInfo> m_macPduMap;

    std::map<uint8_t, LteMacSapProvider::ReportBufferStatusParameters>
        m_ulBsrReceived; // BSR received from RLC (the last one)
    Time m_bsrPeriodicity;
    Time m_bsrLast;
    bool m_freshUlBsr; // true when a BSR has been received in the last TTI

    uint8_t m_raPreambleId;
    uint8_t m_raRnti;

    struct UlHarqProcessInfo
    {
        Ptr<PacketBurst> m_pktBurst;
        // maintain list of LCs contained in this TB
        // used to signal HARQ failure to RLC handlers
        std::vector<uint8_t> m_lcidList;
    };

    // uint8_t m_harqProcessId;
    std::vector<UlHarqProcessInfo>
        m_miUlHarqProcessesPacket; // Packets under trasmission of the UL HARQ processes
    std::vector<uint8_t> m_miUlHarqProcessesPacketTimer; // timer for packet life in the buffer

    struct LcInfo
    {
        LteUeCmacSapProvider::LogicalChannelConfig lcConfig;
        LteMacSapUser* macSapUser;
    };

    std::map<uint8_t, LcInfo> m_lcInfoMap;
    uint16_t m_rnti;

    bool m_waitingForRaResponse;
    static uint8_t g_raPreambleId;
    Ptr<UniformRandomVariable> m_randomAccessProcedureDelay;
    double m_ueUpdateSinrPeriod;
    bool m_interRatHoCapable;

    TracedCallback<uint16_t, uint8_t, uint32_t> m_txMacPacketTraceUe;
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_UE_MAC_H_ */
