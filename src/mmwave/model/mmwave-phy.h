/*
 * mmwave-phy.h
 *
 *  Created on: Nov 4, 2014
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_PHY_H_
#define SRC_MMWAVE_MODEL_MMWAVE_PHY_H_

#include <ns3/spectrum-value.h>
#include <ns3/mobility-model.h>
#include <ns3/packet.h>
#include <ns3/nstime.h>
#include <ns3/spectrum-phy.h>
#include <ns3/spectrum-channel.h>
#include <ns3/spectrum-signal-parameters.h>
#include <ns3/spectrum-interference.h>
#include <ns3/generic-phy.h>
#include <ns3/antenna-array-model.h>
#include "mmwave-spectrum-phy.h"
#include "mmwave-net-device.h"
#include "mmwave-phy-sap.h"
#include <string>
#include <map>

namespace ns3 {

class mmWaveNetDevice;
class mmWaveControlMessages;

class mmWavePhy : public Object
{
public:
	mmWavePhy();

	mmWavePhy(Ptr<mmWaveSpectrumPhy> dlChannelPhy, Ptr<mmWaveSpectrumPhy> ulChannelPhy);

	virtual ~mmWavePhy ();

	static TypeId GetTypeId (void);

	void SetDevice (Ptr<mmWaveNetDevice> d);

	Ptr<mmWaveNetDevice> GetDevice ();

	void SetChannel (Ptr<SpectrumChannel> c);

	/**
	 * \brief Compute the TX Power Spectral Density
	 * \return a pointer to a newly allocated SpectrumValue representing the TX Power Spectral Density in W/Hz for each Resource Block
	 */
	virtual Ptr<SpectrumValue> CreateTxPowerSpectralDensity () = 0;

	void DoDispose ();

	/**
	 * \returns transmission time interval
	 */
	double GetTti (void) const;

	void DoSetCellId (uint16_t cellId);


	void SetNoiseFigure (double nf);
	double GetNoiseFigure (void) const;

	void SetControlMessages (Ptr<mmWaveControlMessages> m);
	std::list<Ptr<mmWaveControlMessages> > GetControlMessages (void);

	void SetMacData (Ptr<PacketBurst> pb);

	void SendRachPreamble (uint32_t PreambleId, uint32_t Rnti);


	Ptr<PacketBurst> GetPacketBurst (void);

	void SetCofigurationParameters (Ptr<mmWavePhyMacCommon> ptrConfig);
	Ptr<mmWavePhyMacCommon> GetConfigurationParameters (void) const;

	mmWavePhySapProvider* GetmmWavePhySapProvider ();
	void SetmmWavePhySapUser (mmWavePhySapUser* ptr);

	void UpdateCurrentAllocationAndSchedule (uint32_t frame, uint32_t sf);

protected:
	Ptr<mmWaveNetDevice> m_netDevice;

	Ptr<mmWaveSpectrumPhy> m_downlinkSpectrumPhy;
	Ptr<mmWaveSpectrumPhy> m_uplinkSpectrumPhy;

	double m_txPower;
	double m_noiseFigure;

	uint16_t m_cellId;

	Ptr<mmWavePhyMacCommon> m_PhyMACConfig;

	std::vector< Ptr<PacketBurst> > m_packetBurstQueue;
	std::vector< std::list<Ptr<mmWaveControlMessages> > > m_controlMessagesQueue;

	Schedule m_CurrentTDDMap;
	allocationList m_CurrentAllocationList;

	std::map <uint32_t,Schedule> m_TDDPatternsFrorSF;

	std::map <uint32_t,allocationList> m_AllocationListforSF;

	mmWavePhySapProvider* m_phySapProvider;
	mmWavePhySapUser* m_phySapUser;

	uint32_t m_raPreambleId;

private:
};

}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_PHY_H_ */
