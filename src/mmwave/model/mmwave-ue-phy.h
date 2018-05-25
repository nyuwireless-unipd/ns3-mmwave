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
 *        	 	  Sourjya Dutta <sdutta@nyu.edu>
 *        	 	  Russell Ford <russell.ford@nyu.edu>
 *        		  Menglei Zhang <menglei@nyu.edu>
 *
 *	Modified by: Michele Polese <michele.polese@gmail.com>
 *                Dual Connectivity and Handover functionalities
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
#include <ns3/mmwave-harq-phy.h>
#include "mmwave-enb-net-device.h"



namespace ns3 {

class PacketBurst;

namespace mmwave {

class mmwEnbPhy;

class MmWaveUePhy : public MmWavePhy
{
	friend class UeMemberLteUePhySapProvider;
	friend class MemberLteUeCphySapProvider<MmWaveUePhy>;

public:
	MmWaveUePhy ();

	MmWaveUePhy (Ptr<MmWaveSpectrumPhy> ulPhy, Ptr<MmWaveSpectrumPhy> dlPhy);

	virtual ~MmWaveUePhy ();

	// inherited from Object
	static TypeId GetTypeId (void);
	virtual void DoInitialize (void);
	virtual void DoDispose (void);

	LteUeCphySapProvider* GetUeCphySapProvider ();
	void SetUeCphySapUser (LteUeCphySapUser* s);

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

	void DoSendControlMessage (Ptr<MmWaveControlMessage> msg);

	void RegisterToEnb (uint16_t cellId, Ptr<MmWavePhyMacCommon> config);
	void RegisterOtherEnb (uint16_t cellId, Ptr<MmWavePhyMacCommon> config, Ptr<MmWaveEnbNetDevice> enb);
	Ptr<MmWaveSpectrumPhy> GetDlSpectrumPhy () const;
	Ptr<MmWaveSpectrumPhy> GetUlSpectrumPhy () const;

	void ReceiveControlMessageList (std::list<Ptr<MmWaveControlMessage> > msgList);

	void SubframeIndication (uint16_t frameNum, uint8_t subframeNum);
	void StartSlot ();
	void EndSlot ();


	uint32_t GetSubframeNumber (void);

	void PhyDataPacketReceived (Ptr<Packet> p);
	void DelayPhyDataPacketReceived (Ptr<Packet> p);

	void SendDataChannels (Ptr<PacketBurst> pb, std::list<Ptr<MmWaveControlMessage> > ctrlMsg, Time duration, uint8_t slotInd);

	void SendCtrlChannels (std::list<Ptr<MmWaveControlMessage> > ctrlMsg, Time prd);

	uint32_t GetAbsoluteSubframeNo (); // Used for tracing purposes

	Ptr<MmWaveDlCqiMessage> CreateDlCqiFeedbackMessage (const SpectrumValue& sinr);

	void GenerateDlCqiReport (const SpectrumValue& sinr);

	void SetImsi (uint64_t imsi);
	uint64_t GetImsi () const;

	bool IsReceptionEnabled ();
	void ResetReception ();

	uint16_t GetRnti ();

	void SetPhySapUser (MmWaveUePhySapUser* ptr);

	void SetHarqPhyModule (Ptr<MmWaveHarqPhy> harq);

	void ReceiveLteDlHarqFeedback (DlHarqInfo m);

	void UpdateSinrEstimate(uint16_t cellId, double sinr);


private:
	void DoReset ();
	void DoStartCellSearch (uint16_t dlEarfcn);
	void DoSynchronizeWithEnb (uint16_t cellId);
	void DoSynchronizeWithEnb (uint16_t cellId, uint16_t dlEarfcn);
	void DoSetPa (double pa);
	void DoSetDlBandwidth (uint8_t ulBandwidth);
	void DoConfigureUplink (uint16_t ulEarfcn, uint8_t ulBandwidth);
	void DoConfigureReferenceSignalPower (int8_t referenceSignalPower);
	void DoSetRnti (uint16_t rnti);
	void DoSetTransmissionMode (uint8_t txMode);
	void DoSetSrsConfigurationIndex (uint16_t srcCi);

	void ReceiveDataPeriod (uint32_t slotNum);
	void QueueUlTbAlloc (TbAllocInfo tbAllocInfo);
	std::list<TbAllocInfo> DequeueUlTbAlloc ();

	MmWaveUePhySapUser* m_phySapUser;

	LteUeCphySapProvider* m_ueCphySapProvider;
	LteUeCphySapUser* m_ueCphySapUser;

	Ptr<MmWaveAmc> m_amc;
	std::vector <int> m_subChannelsForTx;
	std::vector <int> m_subChannelsforRx;

	uint32_t m_numRbg;

	Time m_wbCqiPeriod; /**< Wideband Periodic CQI: 2, 5, 10, 16, 20, 32, 40, 64, 80 or 160 ms */
	Time m_wbCqiLast;

	SlotAllocInfo::TddMode m_prevSlotDir;

	SfAllocInfo m_currSfAllocInfo;
	std::vector< std::list<TbAllocInfo> > m_ulTbAllocQueue; // for storing info on future UL TB transmissions
	bool m_ulGrant; 	// true if no uplink grant in subframe, need to transmit UL control in PUCCH instead
	bool m_sfAllocInfoUpdated;
	Time m_dlCtrlPeriod;
	Time m_ulCtrlPeriod;

	Time m_dataPeriod;	// data period length in microseconds
	Time m_sfPeriod;
	Time m_lastSfStart;

	bool m_dlConfigured;
	bool m_ulConfigured;

	TracedCallback< uint64_t, SpectrumValue&, SpectrumValue& > m_reportCurrentCellRsrpSinrTrace;

	TracedCallback<uint64_t, uint64_t> m_reportUlTbSize;
	TracedCallback<uint64_t, uint64_t> m_reportDlTbSize;
	uint8_t m_prevSlot;

	bool m_receptionEnabled;
	uint16_t m_rnti;
	uint64_t m_imsi;

	Ptr<MmWaveHarqPhy> m_harqPhyModule;

	std::vector<int> m_channelChunks;

	SlotAllocInfo m_currSlot;

	std::map<uint16_t, std::pair<Ptr<MmWavePhyMacCommon>, Ptr<MmWaveEnbNetDevice> > > m_registeredEnb;

	EventId m_sendDataChannelEvent;
	EventId m_sendDlHarqFeedbackEvent;
	bool m_phyReset;

	std::map<uint16_t, double> m_cellSinrMap;

	uint8_t m_consecutiveSinrBelowThreshold;
	long double m_outageThreshold;
	uint8_t m_n310;

};


}

}

#endif /* SRC_MMWAVE_MODEL_MMWAVE_UE_PHY_H_ */
