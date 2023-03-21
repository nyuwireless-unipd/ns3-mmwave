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

#ifndef SRC_MMWAVE_MODEL_MMWAVE_PHY_H_
#define SRC_MMWAVE_MODEL_MMWAVE_PHY_H_

#include "mmwave-net-device.h"
#include "mmwave-phy-mac-common.h"
#include "mmwave-phy-sap.h"
#include "mmwave-spectrum-phy.h"

#include <ns3/generic-phy.h>
#include <ns3/mobility-model.h>
#include <ns3/nstime.h>
#include <ns3/packet.h>
#include <ns3/propagation-loss-model.h>
#include <ns3/spectrum-channel.h>
#include <ns3/spectrum-interference.h>
#include <ns3/spectrum-phy.h>
#include <ns3/spectrum-signal-parameters.h>
#include <ns3/spectrum-value.h>

#include <map>
#include <string>

namespace ns3
{

namespace mmwave
{

class MmWaveNetDevice;
class MmWaveControlMessage;

class MmWavePhy : public Object
{
  public:
    MmWavePhy();

    MmWavePhy(Ptr<MmWaveSpectrumPhy> dlChannelPhy, Ptr<MmWaveSpectrumPhy> ulChannelPhy);

    virtual ~MmWavePhy();

    static TypeId GetTypeId(void);

    void SetDevice(Ptr<NetDevice> d);

    Ptr<NetDevice> GetDevice();

    void SetChannel(Ptr<SpectrumChannel> c);

    /**
     * \brief Compute the TX Power Spectral Density
     * \return a pointer to a newly allocated SpectrumValue representing the TX Power Spectral
     * Density in W/Hz for each Resource Block
     */
    virtual Ptr<SpectrumValue> CreateTxPowerSpectralDensity() = 0;

    virtual void DoDispose() override;

    virtual void DoInitialize(void) override;

    /**
     * The purpose of this function is to sync the slot duration to the correct value
     *
     * Since the OFDM symbols duration can not be expressed in ns as an integer,
     * each of these symbols has a slightly lower duration (by a fraction of ns) than it should.
     * Therefore, a sync anchor is needed in order to align the slots starting time.
     *
     * \returns the exact delay between the current TTI end and the next slot start
     *
     */
    Time GetNextSlotDelay();

    void DoSetCellId(uint16_t cellId);

    void SetNoiseFigure(double nf);
    double GetNoiseFigure(void) const;

    void SetControlMessage(Ptr<MmWaveControlMessage> m);
    std::list<Ptr<MmWaveControlMessage>> GetControlMessages(void);

    virtual void SetMacPdu(Ptr<Packet> pb);

    virtual void SendRachPreamble(uint32_t PreambleId, uint32_t Rnti);

    //  virtual Ptr<PacketBurst> GetPacketBurst (void);
    virtual Ptr<PacketBurst> GetPacketBurst(SfnSf);

    void SetConfigurationParameters(Ptr<MmWavePhyMacCommon> ptrConfig);
    Ptr<MmWavePhyMacCommon> GetConfigurationParameters(void) const;

    MmWavePhySapProvider* GetPhySapProvider();
    //  void SetPhySapUser (MmWavePhySapUser* ptr);

    void UpdateCurrentAllocationAndSchedule(uint32_t frame, uint32_t sf);

    /**
     * Sets the control data allocation within a NR slot.
     *
     * The first OFDM symbol of each slot gets assigned to DL control data, while the last one to UL
     * control data.
     *
     * \param slotIndex the slot index to be allocated.
     */
    void SetSlotCtrlStructure(uint8_t slotIndex);

    SlotAllocInfo GetSfAllocInfo(uint8_t subframeNum);
    void DoSetSlotAllocInfo(SlotAllocInfo sfAllocInfo);

    // hacks needed to compute SINR at eNB for each UE, without pilots
    void AddSpectrumPropagationLossModel(Ptr<SpectrumPropagationLossModel> model);
    void AddPhasedArraySpectrumPropagationLossModel(
        Ptr<PhasedArraySpectrumPropagationLossModel> model);
    void AddPropagationLossModel(Ptr<PropagationLossModel> model);

    /**
     * Set the component carrier ID
     *
     * \param index the component carrier ID index
     */
    void SetComponentCarrierId(uint8_t index);

    /**
     * Get the component carrier ID
     *
     * \returns the component carrier ID index
     */
    uint8_t GetComponentCarrierId();

  protected:
    Ptr<NetDevice> m_netDevice;

    Ptr<MmWaveSpectrumPhy> m_spectrumPhy;
    Ptr<MmWaveSpectrumPhy> m_downlinkSpectrumPhy;
    Ptr<MmWaveSpectrumPhy> m_uplinkSpectrumPhy;

    double m_txPower;
    double m_noiseFigure;

    uint16_t m_cellId;

    Ptr<MmWavePhyMacCommon> m_phyMacConfig;

    std::map<uint64_t, Ptr<PacketBurst>> m_packetBurstMap;
    std::vector<std::list<Ptr<MmWaveControlMessage>>> m_controlMessageQueue;

    std::vector<SlotAllocInfo> m_slotAllocInfo; //!< Maps slot number to its allocation info

    uint32_t m_frameNum;
    uint8_t m_sfNum;
    uint8_t m_slotNum;
    uint8_t m_ttiIndex; //!< Keeps track of the TTIs within the single NR slot

    Time m_ctrlPeriod;
    Time m_dataPeriod;
    Time m_slotPeriod;    //!< Slot period time duration
    Time m_lastSlotStart; //!< Time at which the current slot started

    std::map<uint32_t, SlotAllocInfo> m_slotAllocInfoMap;

    MmWavePhySapProvider* m_phySapProvider;

    uint32_t m_raPreambleId;

    bool m_sfAllocInfoUpdated;

    // hack to allow eNB to compute the SINR, periodically, without pilots
    Ptr<SpectrumPropagationLossModel> m_spectrumPropagationLossModel;
    Ptr<PhasedArraySpectrumPropagationLossModel> m_phasedArraySpectrumPropagationLossModel;
    Ptr<PropagationLossModel> m_propagationLoss;

    /// component carrier Id used to address sap
    uint8_t m_componentCarrierId;

  private:
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_PHY_H_ */
