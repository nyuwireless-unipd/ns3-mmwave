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
*								 Integration of Carrier Aggregation
* Modified by: Argha Sen <arghasen10@gmail.com>
*                 MmWave Radio Energy Model
*/



#ifndef SRC_MMWAVE_MODEL_MMWAVE_SPECTRUM_PHY_H_
#define SRC_MMWAVE_MODEL_MMWAVE_SPECTRUM_PHY_H_


#include <ns3/object-factory.h>
#include <ns3/event-id.h>
#include <ns3/spectrum-value.h>
#include <ns3/mobility-model.h>
#include <ns3/packet.h>
#include <ns3/nstime.h>
#include <ns3/net-device.h>
#include <ns3/spectrum-phy.h>
#include <ns3/spectrum-channel.h>
#include <ns3/spectrum-interference.h>
#include <ns3/data-rate.h>
#include <ns3/generic-phy.h>
#include <ns3/packet-burst.h>
#include "mmwave-spectrum-signal-parameters.h"
#include "ns3/random-variable-stream.h"
#include "mmwave-interference.h"
#include "mmwave-control-messages.h"
#include "mmwave-harq-phy.h"
#include "ns3/mmwave-beamforming-model.h"
#include "ns3/traced-value.h"
#include "ns3/trace-source-accessor.h"

namespace ns3 {

namespace mmwave {

struct ExpectedTbInfo_t
{
  uint8_t ndi;
  uint32_t size;
  uint8_t mcs;
  std::vector<int> rbBitmap;
  uint8_t harqProcessId;
  uint8_t rv;
  double mi;
  bool downlink;
  bool corrupt;
  bool harqFeedbackSent;
  double tbler;
  uint8_t               symStart;
  uint8_t               numSym;
};

typedef std::map<uint16_t, ExpectedTbInfo_t> ExpectedTbMap_t;

typedef Callback< void, Ptr<Packet> > MmWavePhyRxDataEndOkCallback;
typedef Callback< void, std::list<Ptr<MmWaveControlMessage> > > MmWavePhyRxCtrlEndOkCallback;

/**
* This method is used by the LteSpectrumPhy to notify the PHY about
* the status of a certain DL HARQ process
*/
typedef Callback< void, DlHarqInfo > MmWavePhyDlHarqFeedbackCallback;

/**
* This method is used by the LteSpectrumPhy to notify the PHY about
* the status of a certain UL HARQ process
*/
typedef Callback< void, UlHarqInfo > MmWavePhyUlHarqFeedbackCallback;


class MmWaveSpectrumPhy : public SpectrumPhy
{
public:
  MmWaveSpectrumPhy ();
  virtual ~MmWaveSpectrumPhy ();

  enum State
  {
    IDLE,
    TX,
    RX_DATA,
    RX_CTRL
  };

  TracedValue<int32_t> m_intstate;
  static TypeId GetTypeId (void);
  virtual void DoDispose () override;

  void Reset ();
  void ResetSpectrumModel ();

  void SetDevice (Ptr<NetDevice> d) override;
  Ptr<NetDevice> GetDevice () const override;
  void SetMobility (Ptr<MobilityModel> m) override;
  Ptr<MobilityModel> GetMobility () override;
  void SetChannel (Ptr<SpectrumChannel> c) override;
  Ptr<const SpectrumModel> GetRxSpectrumModel () const override;

  /**
  * This function is used by SpectrumChannel to account for the antenna gain.
  * However, in our module the antenna gain is implicitly accounted in the
  * channel model classes, therefore this function returns 0.
  * \return 0
  */
  Ptr<AntennaModel> GetRxAntenna () override;

  /**
  * Set the beamforming module
  * \param bfModule the beamforming module
  */
  void SetBeamformingModel (Ptr<MmWaveBeamformingModel> bfModule);

  /**
  * Returns the beamforming module
  * \return the beamforming module
  */
  Ptr<MmWaveBeamformingModel> GetBeamformingModel () const;

  /**
  * Compute the beamforming vector and update the antenna configuration
  * to point the beam towards the target device.
  * \param device target device
  */
  void ConfigureBeamforming (Ptr<NetDevice> device);

  void SetNoisePowerSpectralDensity (Ptr<const SpectrumValue> noisePsd);
  void SetTxPowerSpectralDensity (Ptr<SpectrumValue> TxPsd);
  void StartRx (Ptr<SpectrumSignalParameters> params) override;
  void StartRxData (Ptr<MmwaveSpectrumSignalParametersDataFrame> params);
  void StartRxCtrl (Ptr<MmWaveSpectrumSignalParametersDlCtrlFrame> params);
  Ptr<SpectrumChannel> GetSpectrumChannel ();
  void SetCellId (uint16_t cellId);

  /**
   *
   * \param componentCarrierId the component carrier id
   */
  void SetComponentCarrierId (uint8_t componentCarrierId);


  bool StartTxDataFrames (Ptr<PacketBurst> pb, std::list<Ptr<MmWaveControlMessage> > ctrlMsgList, Time duration, uint8_t slotInd);

  bool StartTxDlControlFrames (std::list<Ptr<MmWaveControlMessage> > ctrlMsgList, Time duration);       // control frames from enb to ue
  bool StartTxUlControlFrames (void);       // control frames from ue to enb

  void SetPhyRxDataEndOkCallback (MmWavePhyRxDataEndOkCallback c);
  void SetPhyRxCtrlEndOkCallback (MmWavePhyRxCtrlEndOkCallback c);
  void SetPhyDlHarqFeedbackCallback (MmWavePhyDlHarqFeedbackCallback c);
  void SetPhyUlHarqFeedbackCallback (MmWavePhyUlHarqFeedbackCallback c);

  void AddDataPowerChunkProcessor (Ptr<mmWaveChunkProcessor> p);
  void AddDataSinrChunkProcessor (Ptr<mmWaveChunkProcessor> p);

  void UpdateSinrPerceived (const SpectrumValue& sinr);

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
  void AddExpectedTb (uint16_t rnti, uint8_t ndi, uint32_t tbSize, uint8_t mcs, std::vector<int> map, uint8_t harqId,
                      uint8_t rv, bool downlink, uint8_t symStart, uint8_t numSym);

  void SetHarqPhyModule (Ptr<MmWaveHarqPhy> harq);


private:

  /**
   * \brief change the state
   * \param the new state
   */
  void ChangeState (State newState);
  void EndTx ();
  void EndRxData ();
  void EndRxCtrl ();

  Ptr<mmWaveInterference> m_interferenceData;
  Ptr<MobilityModel> m_mobility;
  Ptr<NetDevice> m_device;
  Ptr<SpectrumChannel> m_channel;
  Ptr<const SpectrumModel> m_rxSpectrumModel;
  Ptr<SpectrumValue> m_txPsd;
  //Ptr<PacketBurst> m_txPacketBurst;
  std::list<Ptr<PacketBurst> > m_rxPacketBurstList;
  std::list<Ptr<MmWaveControlMessage> > m_rxControlMessageList;

  Time m_firstRxStart;
  Time m_firstRxDuration;

  Ptr<AntennaModel> m_antenna; // TODO can we remove this? it is never used
  Ptr<MmWaveBeamformingModel> m_beamforming; //!< used to compute the beamforming vector

  uint16_t m_cellId;

  State m_state;

  uint8_t m_componentCarrierId; ///< the component carrier ID

  MmWavePhyRxCtrlEndOkCallback    m_phyRxCtrlEndOkCallback;
  MmWavePhyRxDataEndOkCallback            m_phyRxDataEndOkCallback;

  MmWavePhyDlHarqFeedbackCallback m_phyDlHarqFeedbackCallback;
  MmWavePhyUlHarqFeedbackCallback m_phyUlHarqFeedbackCallback;

  TracedCallback<RxPacketTraceParams> m_rxPacketTraceEnb;
  TracedCallback<RxPacketTraceParams> m_rxPacketTraceUe;

  SpectrumValue m_sinrPerceived;

  ExpectedTbMap_t m_expectedTbs;

  Ptr<UniformRandomVariable> m_random;

  bool m_dataErrorModelEnabled;       // when true (default) the phy error model is enabled
  bool m_ctrlErrorModelEnabled;       // when true (default) the phy error model is enabled for DL ctrl frame

  Ptr<MmWaveHarqPhy> m_harqPhyModule;

  bool m_isEnb;

  EventId m_endTxEvent;
  EventId m_endRxDataEvent;
  EventId m_endRxDlCtrlEvent;
  std::string m_fileName;

};

}

}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_SPECTRUM_PHY_H_ */
