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
 *                Dual Connectivity and Handover functionalities
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                               Integration of Carrier Aggregation
 * Modified by: Argha Sen <arghasen10@gmail.com>
 *                 MmWave Radio Energy Model
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_SPECTRUM_PHY_H_
#define SRC_MMWAVE_MODEL_MMWAVE_SPECTRUM_PHY_H_

#include "mmwave-control-messages.h"
#include "mmwave-harq-phy.h"
#include "mmwave-interference.h"
#include "mmwave-spectrum-signal-parameters.h"

#include "ns3/mmwave-beamforming-model.h"
#include "ns3/random-variable-stream.h"
#include "ns3/trace-source-accessor.h"
#include "ns3/traced-value.h"
#include <ns3/data-rate.h>
#include <ns3/event-id.h>
#include <ns3/generic-phy.h>
#include <ns3/mobility-model.h>
#include <ns3/net-device.h>
#include <ns3/nstime.h>
#include <ns3/object-factory.h>
#include <ns3/packet-burst.h>
#include <ns3/packet.h>
#include <ns3/spectrum-channel.h>
#include <ns3/spectrum-interference.h>
#include <ns3/spectrum-phy.h>
#include <ns3/spectrum-value.h>

#include <algorithm>

namespace ns3
{

namespace mmwave
{

/**
 * \brief Information about the expected transport block at a certain point in the slot
 *
 * Information passed by the PHY through a call to AddExpectedTb
 */
struct ExpectedTb
{
    ExpectedTb(uint8_t ndi,
               uint32_t tbSize,
               uint8_t mcs,
               const std::vector<int>& rbBitmap,
               uint8_t harqProcessId,
               uint8_t rv,
               bool isDownlink,
               uint8_t symStart,
               uint8_t numSym)
        : m_ndi(ndi),
          m_tbSize(tbSize),
          m_mcs(mcs),
          m_rbBitmap(rbBitmap),
          m_harqProcessId(harqProcessId),
          m_rv(rv),
          m_isDownlink(isDownlink),
          m_symStart(symStart),
          m_numSym(numSym)
    {
    }

    ExpectedTb() = delete;
    ExpectedTb(const ExpectedTb& o) = default;

    uint8_t m_ndi{0};            //!< New data indicator
    uint32_t m_tbSize{0};        //!< TBSize
    uint8_t m_mcs{0};            //!< MCS
    std::vector<int> m_rbBitmap; //!< RB Bitmap
    uint8_t m_harqProcessId{0};  //!< HARQ process ID (MAC)
    uint8_t m_rv{0};             //!< RV
    bool m_isDownlink{0};        //!< is Downlink?
    uint8_t m_symStart{0};       //!< Sym start
    uint8_t m_numSym{0};         //!< Num sym
};

struct TransportBlockInfo
{
    TransportBlockInfo(const ExpectedTb& expected)
        : m_expected(expected)
    {
    }

    TransportBlockInfo() = delete;

    ExpectedTb m_expected;          //!< Expected data from the PHY. Filled by AddExpectedTb
    bool m_isCorrupted{false};      //!< True if the ErrorModel indicates that the TB is corrupted.
                                    //    Filled at the end of data rx/tx
    bool m_harqFeedbackSent{false}; //!< Indicate if the feedback has been sent for an entire TB
    Ptr<MmWaveErrorModelOutput>
        m_outputOfEM;      //!< Output of the Error Model (depends on the EM type)
    double m_sinrAvg{0.0}; //!< AVG SINR (only for the RB used to transmit the TB)
    double m_sinrMin{0.0}; //!< MIN SINR (only between the RB used to transmit the TB)
};

typedef std::unordered_map<uint16_t, TransportBlockInfo>
    TbInfoMap_t; //!< Transport block map per RNTI of TBs which are expected to be received by
                 //!< reading DL or UL DCIs

typedef Callback<void, Ptr<Packet>> MmWavePhyRxDataEndOkCallback;
typedef Callback<void, std::list<Ptr<MmWaveControlMessage>>> MmWavePhyRxCtrlEndOkCallback;

/**
 * This method is used by the LteSpectrumPhy to notify the PHY about
 * the status of a certain DL HARQ process
 */
typedef Callback<void, DlHarqInfo> MmWavePhyDlHarqFeedbackCallback;

/**
 * This method is used by the LteSpectrumPhy to notify the PHY about
 * the status of a certain UL HARQ process
 */
typedef Callback<void, UlHarqInfo> MmWavePhyUlHarqFeedbackCallback;

class MmWaveSpectrumPhy : public SpectrumPhy
{
  public:
    MmWaveSpectrumPhy();
    virtual ~MmWaveSpectrumPhy();

    enum State
    {
        IDLE = 0,
        TX = 1,
        RX_DATA = 2,
        RX_CTRL = 3
    };

    TracedValue<int32_t> m_intState; //!< used to trace the value of m_state
    static TypeId GetTypeId(void);
    virtual void DoDispose() override;

    void Reset();
    void ResetSpectrumModel();

    void SetDevice(Ptr<NetDevice> d) override;
    Ptr<NetDevice> GetDevice() const override;
    void SetMobility(Ptr<MobilityModel> m) override;
    Ptr<MobilityModel> GetMobility() const override;
    void SetChannel(Ptr<SpectrumChannel> c) override;
    Ptr<const SpectrumModel> GetRxSpectrumModel() const override;

    /**
     * \brief Set Error model type
     * \param type the Error model type
     */
    void SetErrorModelType(TypeId errorModelType);

    /**
     * \brief Get the error model type
     * \return the error model type
     */
    TypeId GetErrorModelType() const;

    /**
     * This function is used by SpectrumChannel to account for the antenna gain.
     * However, in our module the antenna gain is implicitly accounted in the
     * channel model classes, therefore this function returns 0.
     * \return 0
     */
    Ptr<Object> GetAntenna() const override;

    /**
     * Set the beamforming module
     * \param bfModule the beamforming module
     */
    void SetBeamformingModel(Ptr<MmWaveBeamformingModel> bfModule);

    /**
     * Returns the beamforming module
     * \return the beamforming module
     */
    Ptr<MmWaveBeamformingModel> GetBeamformingModel() const;

    /**
     * Compute the beamforming vector and update the antenna configuration
     * to point the beam towards the target device.
     * \param device target device
     */
    void ConfigureBeamforming(Ptr<NetDevice> device);

    void SetNoisePowerSpectralDensity(Ptr<const SpectrumValue> noisePsd);
    void SetTxPowerSpectralDensity(Ptr<SpectrumValue> TxPsd);
    void StartRx(Ptr<SpectrumSignalParameters> params) override;
    void StartRxData(Ptr<MmwaveSpectrumSignalParametersDataFrame> params);
    void StartRxCtrl(Ptr<MmWaveSpectrumSignalParametersDlCtrlFrame> params);
    Ptr<SpectrumChannel> GetSpectrumChannel();
    void SetCellId(uint16_t cellId);

    /**
     *
     * \param componentCarrierId the component carrier id
     */
    void SetComponentCarrierId(uint8_t componentCarrierId);

    bool StartTxDataFrames(Ptr<PacketBurst> pb,
                           std::list<Ptr<MmWaveControlMessage>> ctrlMsgList,
                           Time duration,
                           uint8_t slotInd);

    bool StartTxDlControlFrames(std::list<Ptr<MmWaveControlMessage>> ctrlMsgList,
                                Time duration); // control frames from enb to ue
    bool StartTxUlControlFrames(void);          // control frames from ue to enb

    void SetPhyRxDataEndOkCallback(MmWavePhyRxDataEndOkCallback c);
    void SetPhyRxCtrlEndOkCallback(MmWavePhyRxCtrlEndOkCallback c);
    void SetPhyDlHarqFeedbackCallback(MmWavePhyDlHarqFeedbackCallback c);
    void SetPhyUlHarqFeedbackCallback(MmWavePhyUlHarqFeedbackCallback c);

    void AddDataPowerChunkProcessor(Ptr<mmWaveChunkProcessor> p);
    void AddDataSinrChunkProcessor(Ptr<mmWaveChunkProcessor> p);

    void UpdateSinrPerceived(const SpectrumValue& sinr);

    /**
     * Add the transport block that the spectrum should expect to receive.
     *
     * \param rnti the RNTI of the UE
     * \param ndi the New Data Indicator
     * \param tbSize the size of the transport block
     * \param mcs the modulation and coding scheme to use
     * \param map a map of the resource blocks used
     * \param harqId the ID of the HARQ process
     * \param rv the number of retransmissions
     * \param downlink a boolean flag for a downlink transmission
     * \param symStart the first symbol of this TB
     * \param numSym the number of symbols of the TB
     */
    void AddExpectedTb(uint16_t rnti,
                       uint8_t ndi,
                       uint32_t tbSize,
                       uint8_t mcs,
                       std::vector<int> map,
                       uint8_t harqId,
                       uint8_t rv,
                       bool downlink,
                       uint8_t symStart,
                       uint8_t numSym);

    void SetHarqPhyModule(Ptr<MmWaveHarqPhy> harq);

  private:
    /**
     * \brief change the state
     * \param newState the new state
     */
    void ChangeState(State newState);
    void EndTx();
    void EndRxData();
    void EndRxCtrl();

    /**
     * \brief Computes the minimum of the stored values
     * \param specVal the SpectrumValue
     */
    double Min(const SpectrumValue& specVal);

    Ptr<mmWaveInterference> m_interferenceData;
    Ptr<MobilityModel> m_mobility;
    Ptr<NetDevice> m_device;
    Ptr<SpectrumChannel> m_channel;
    Ptr<const SpectrumModel> m_rxSpectrumModel;
    Ptr<SpectrumValue> m_txPsd;
    // Ptr<PacketBurst> m_txPacketBurst;
    std::list<Ptr<PacketBurst>> m_rxPacketBurstList;
    std::list<Ptr<MmWaveControlMessage>> m_rxControlMessageList;

    Time m_firstRxStart;
    Time m_firstRxDuration;

    Ptr<MmWaveBeamformingModel> m_beamforming; //!< used to compute the beamforming vector

    uint16_t m_cellId;

    State m_state;

    uint8_t m_componentCarrierId; ///< the component carrier ID

    MmWavePhyRxCtrlEndOkCallback m_phyRxCtrlEndOkCallback;
    MmWavePhyRxDataEndOkCallback m_phyRxDataEndOkCallback;

    MmWavePhyDlHarqFeedbackCallback m_phyDlHarqFeedbackCallback;
    MmWavePhyUlHarqFeedbackCallback m_phyUlHarqFeedbackCallback;

    TracedCallback<RxPacketTraceParams> m_rxPacketTraceEnb;
    TracedCallback<RxPacketTraceParams> m_rxPacketTraceUe;

    SpectrumValue m_sinrPerceived;

    TbInfoMap_t m_transportBlocks;

    Ptr<UniformRandomVariable> m_random;

    bool m_dataErrorModelEnabled; // when true (default) the phy error model is enabled
    bool m_ctrlErrorModelEnabled; // when true (default) the phy error model is enabled for DL ctrl
                                  // frame
    TypeId m_errorModelType{
        Object::GetTypeId()}; //!< Error model type by default is MmWaveLteMiErrorModel

    Ptr<MmWaveHarqPhy> m_harqPhyModule;

    bool m_isEnb;

    EventId m_endTxEvent;
    EventId m_endRxDataEvent;
    EventId m_endRxDlCtrlEvent;
    std::string m_fileName;
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_SPECTRUM_PHY_H_ */
