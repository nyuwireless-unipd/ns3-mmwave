/*
 * mmwave-ue-phy.h
 *
 *  Created on: Nov 4, 2014
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_UE_PHY_H_
#define SRC_MMWAVE_MODEL_MMWAVE_UE_PHY_H_

#include <ns3/mmwave-phy.h>
#include "mmwave-phy-mac-common.h"
#include <ns3/ptr.h>
#include "mmwave-amc.h"
#include <map>
#include <ns3/lte-ue-phy-sap.h>
#include <ns3/lte-ue-cphy-sap.h>


namespace ns3{

class PacketBurst;
class mmwEnbPhy;

class mmWaveUePhy : public mmWavePhy
{
	friend class UeMemberLteUePhySapProvider;
	friend class MemberLteUeCphySapProvider<mmWaveUePhy>;

public:
	mmWaveUePhy ();

	mmWaveUePhy (Ptr<mmWaveSpectrumPhy> ulPhy, Ptr<mmWaveSpectrumPhy> dlPhy);

	virtual ~mmWaveUePhy ();

	// inherited from Object
	static TypeId GetTypeId (void);
	virtual void DoInitialize (void);
	virtual void DoDispose (void);

	LteUeCphySapProvider* GetmmWaveUeCphySapProvider ();
	void SetmmWaveUeCphySapUser (LteUeCphySapUser* s);

	void SetTxPower (double pow);
	double GetTxPower () const;

	void SetNoiseFigure (double pf);
	double GetNoiseFigure () const;

	bool SendPacket(Ptr<Packet> packet);

	Ptr<SpectrumValue> CreateTxPowerSpectralDensity();

	void DoSetSubChannels();

	void SetSubChannelsForReception(std::vector <int> mask);
	std::vector <int> GetSubChannelsForReception(void);

	void SetSubChannelsForTransmission(std::vector <int> mask);
	std::vector <int> GetSubChannelsForTransmission(void);

	void DoSendmmWaveControlMessage (Ptr<mmWaveControlMessages> msg);

	void RegisterToEnb (uint16_t cellId, Ptr<mmWavePhyMacCommon> config);
	Ptr<mmWaveSpectrumPhy> GetDlSpectrumPhy () const;
	Ptr<mmWaveSpectrumPhy> GetUlSpectrumPhy () const;

	void ReceivemmWaveControlMessageList (std::list<Ptr<mmWaveControlMessages> > msgList, uint32_t cellId);

	void SubframeIndication (uint32_t frameNo, uint32_t subframeNo);

	uint32_t GetSubframeNumber (void);

	void PhyDataPacketReceived (Ptr<Packet> p);

	void SendDataChannel (Ptr<PacketBurst> pb, Time duration);

	void SendControlChannels (std::list<Ptr<mmWaveControlMessages> > ctrlMsg, Time prd);

	uint32_t GetAbsoulteSubframeNo (); // Used for tracing purposes

	Ptr<mmWaveCqiReport> CreateDlCqiFeedbackMessage (const SpectrumValue& sinr);
	void GenerateDlCqiReport (const SpectrumValue& sinr);

	bool IsReceptionEnabled ();
	void ResetReception ();

	uint16_t GetRnti ();

private:
	void DoReset ();
	void DoStartCellSearch (uint16_t dlEarfcn);
	void DoSynchronizeWithEnb (uint16_t cellId);
	void DoSynchronizeWithEnb (uint16_t cellId, uint16_t dlEarfcn);
	void DoSetDlBandwidth (uint8_t ulBandwidth);
	void DoConfigureUplink (uint16_t ulEarfcn, uint8_t ulBandwidth);
	void DoConfigureReferenceSignalPower (int8_t referenceSignalPower);
	void DoSetRnti (uint16_t rnti);
	void DoSetTransmissionMode (uint8_t txMode);
	void DoSetSrsConfigurationIndex (uint16_t srcCi);

	LteUeCphySapProvider* m_ueCphySapProvider;
	LteUeCphySapUser* m_ueCphySapUser;

	Ptr<mmWaveAmc> m_amc;
	std::vector <int> m_subChannelsForTx;
	std::vector <int> m_subChannelsforRx;

	uint32_t m_nrsubframe;
	uint32_t m_nrFrame;

	uint32_t m_AllocatedBandwidth;

	TracedCallback< uint64_t, SpectrumValue&, SpectrumValue& > m_reportCurrentCellRsrpSinrTrace;

	TracedCallback<uint64_t, uint64_t> m_reportULTbSize;
	TracedCallback<uint64_t, uint64_t> m_reportDLTbSize;

	uint8_t m_prevSlot;

	bool m_ReceptionEnabled;
	uint16_t m_rnti;


};


}

#endif /* SRC_MMWAVE_MODEL_MMWAVE_UE_PHY_H_ */
