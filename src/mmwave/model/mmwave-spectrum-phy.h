/*
 * mmwave-apectrum-phy.h
 *
 *  Created on: Nov 4, 2014
 *      Author: sourjya
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
#include "ns3/mmwave-beamforming.h"
#include "mmwave-interference.h"
#include "mmwave-control-messages.h"
#include "mmwave-harq-phy.h"

namespace ns3{

struct ExpectedTbInfo_t
{
  uint8_t ndi;
  uint16_t size;
  uint8_t mcs;
  std::vector<int> rbBitmap;
  uint8_t harqProcessId;
  uint8_t rv;
  double mi;
  bool downlink;
  bool corrupt;
  bool harqFeedbackSent;
  double tbler;
  uint8_t		symStart;
  uint8_t		numSym;
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
	MmWaveSpectrumPhy();
	virtual ~MmWaveSpectrumPhy();

	enum State
	  {
	    IDLE = 0,
		TX,
		RX_DATA,
		RX_CTRL
	  };

	static TypeId GetTypeId(void);
	virtual void DoDispose();

	void Reset();
	void ResetSpectrumModel();

	void SetDevice(Ptr<NetDevice> d);
	Ptr<NetDevice> GetDevice () const;
	void SetMobility (Ptr<MobilityModel> m);
	Ptr<MobilityModel> GetMobility ();
	void SetChannel (Ptr<SpectrumChannel> c);
	Ptr<const SpectrumModel> GetRxSpectrumModel () const;

	Ptr<AntennaModel> GetRxAntenna ();
	void SetAntenna (Ptr<AntennaModel> a);

	void SetState (State newState);

	void SetNoisePowerSpectralDensity (Ptr<const SpectrumValue> noisePsd);
	void SetTxPowerSpectralDensity (Ptr<SpectrumValue> TxPsd);
	void StartRx (Ptr<SpectrumSignalParameters> params);
	void StartRxData (Ptr<MmwaveSpectrumSignalParametersDataFrame> params);
	void StartRxCtrl (Ptr<SpectrumSignalParameters> params);
	Ptr<SpectrumChannel> GetSpectrumChannel();
	void SetCellId (uint16_t cellId);

	bool StartTxDataFrames (Ptr<PacketBurst> pb, std::list<Ptr<MmWaveControlMessage> > ctrlMsgList, Time duration, uint8_t slotInd);

	bool StartTxDlControlFrames (std::list<Ptr<MmWaveControlMessage> > ctrlMsgList, Time duration); // control frames from enb to ue
	bool StartTxUlControlFrames (void); // control frames from ue to enb

	void SetPhyRxDataEndOkCallback (MmWavePhyRxDataEndOkCallback c);
	void SetPhyRxCtrlEndOkCallback (MmWavePhyRxCtrlEndOkCallback c);
	void SetPhyDlHarqFeedbackCallback (MmWavePhyDlHarqFeedbackCallback c);
	void SetPhyUlHarqFeedbackCallback (MmWavePhyUlHarqFeedbackCallback c);

	void AddDataPowerChunkProcessor (Ptr<mmWaveChunkProcessor> p);
	void AddDataSinrChunkProcessor (Ptr<mmWaveChunkProcessor> p);

	void UpdateSinrPerceived (const SpectrumValue& sinr);

	void AddExpectedTb (uint16_t rnti, uint8_t ndi, uint16_t size, uint8_t mcs, std::vector<int> map, uint8_t harqId,
	                    uint8_t rv, bool downlink, uint8_t symStart, uint8_t numSym);
//	void AddExpectedTb (uint16_t rnti, uint16_t size, uint8_t m_mcs, std::vector<int> chunkMap, bool downlink);

	void SetHarqPhyModule (Ptr<MmWaveHarqPhy> harq);


private:
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

	Ptr<AntennaModel> m_antenna;

	uint16_t m_cellId;

	State m_state;

	MmWavePhyRxCtrlEndOkCallback    m_phyRxCtrlEndOkCallback;
	MmWavePhyRxDataEndOkCallback 		m_phyRxDataEndOkCallback;

	MmWavePhyDlHarqFeedbackCallback m_phyDlHarqFeedbackCallback;
	MmWavePhyUlHarqFeedbackCallback m_phyUlHarqFeedbackCallback;

	TracedCallback<RxPacketTraceParams> m_rxPacketTraceEnb;
	TracedCallback<RxPacketTraceParams> m_rxPacketTraceUe;

	SpectrumValue m_sinrPerceived;

	ExpectedTbMap_t m_expectedTbs;

	Ptr<UniformRandomVariable> m_random;

	bool m_dataErrorModelEnabled; // when true (default) the phy error model is enabled
	bool m_ctrlErrorModelEnabled; // when true (default) the phy error model is enabled for DL ctrl frame

	Ptr<MmWaveHarqPhy> m_harqPhyModule;

	bool m_isEnb;

	EventId m_endTxEvent;
	EventId m_endRxDataEvent;
  	EventId m_endRxDlCtrlEvent;


};

}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_SPECTRUM_PHY_H_ */
