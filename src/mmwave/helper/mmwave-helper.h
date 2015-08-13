/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef MMWAVE_HELPER_H
#define MMWAVE_HELPER_H

#include <ns3/config.h>
#include <ns3/simulator.h>
#include <ns3/names.h>
#include <ns3/net-device.h>
#include <ns3/net-device-container.h>
#include <ns3/node.h>
#include <ns3/node-container.h>
#include <ns3/mobility-model.h>
#include <ns3/spectrum-phy.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/mmwave-phy.h>
#include <ns3/mmwave-ue-phy.h>
#include <ns3/mmwave-enb-phy.h>
#include <ns3/mmwave-spectrum-value-helper.h>
#include <ns3/mmwave-beamforming.h>
#include <ns3/mmwave-phy-mac-common.h>
#include <ns3/antenna-array-model.h>
#include <ns3/mmwave-rrc-protocol-ideal.h>
#include "mmwave-phy-rx-trace.h"
#include <ns3/epc-helper.h>
#include <ns3/epc-ue-nas.h>
#include <ns3/lte-enb-rrc.h>
#include <ns3/lte-ue-rrc.h>
#include <ns3/boolean.h>
#include <ns3/epc-helper.h>
#include <ns3/lte-ffr-algorithm.h>
#include <ns3/mmwave-channel-matrix.h>



namespace ns3 {

/* ... */
class MmWaveUePhy;
class MmWaveEnbPhy;
class SpectrumChannel;
class SpectrumpropagationLossModel;
class mmWaveSpectrumValueHelper;
class PropagationLossModel;


class MmWaveHelper : public Object
{
public:
	MmWaveHelper(void);
	virtual ~MmWaveHelper(void);

	static TypeId GetTypeId (void);
	virtual void DoDispose (void);

	NetDeviceContainer InstallUeDevice (NodeContainer c);
	NetDeviceContainer InstallEnbDevice (NodeContainer c);
	void SetAntenna (uint16_t Nrx, uint16_t Ntx);
	void SetPathlossModelType (std::string type);
	void RegisterToClosestEnb (NetDeviceContainer ueDevices, NetDeviceContainer enbDevices);
	void EnableTraces ();

	void SetSchedulerType (std::string type);
	std::string GetSchedulerType () const;

	void SetPhyMacConfigurationParameters (std::string paramName, std::string value);
    Ptr<MmWavePhyMacCommon> GetPhyMacConfigurable (void);
	void ActivateDataRadioBearer (NetDeviceContainer ueDevices, EpsBearer bearer);
	void ActivateDataRadioBearer (Ptr<NetDevice> ueDevice, EpsBearer bearer);
	void SetEpcHelper (Ptr<EpcHelper> epcHelper);


protected:
	virtual void DoInitialize();

private:
	Ptr<NetDevice> InstallSingleUeDevice (Ptr<Node> n);
	Ptr<NetDevice> InstallSingleEnbDevice (Ptr<Node> n);
	void RegisterToClosestEnb (Ptr<NetDevice> ueDevice, NetDeviceContainer enbDevices);
	void EnableDlPhyTrace ();
	void EnableEnbPacketCountTrace ();
	void EnableUePacketCountTrace ();
	void EnableTransportBlockTrace ();

	Ptr<SpectrumChannel> m_channel;
	Ptr<mmWaveBeamforming> m_beamforming;
	//Ptr<mmWaveChannelMatrix> m_beamforming;


	Ptr<Object> m_pathlossModel;

	ObjectFactory m_enbNetDeviceFactory;
	ObjectFactory m_ueNetDeviceFactory;
	ObjectFactory m_channelFactory;
	ObjectFactory m_pathlossModelFactory;
	ObjectFactory m_schedulerFactory;
	ObjectFactory m_phyMacCommonFactory;

	uint64_t m_imsiCounter;
	uint16_t m_cellIdCounter;

	uint16_t m_noTxAntenna;
	uint16_t m_noRxAntenna;

	Ptr<mmWavePhyRxTrace> m_phyStats;

	Ptr<MmWavePhyMacCommon> m_phyMacCommon;

	ObjectFactory m_ffrAlgorithmFactory;
	ObjectFactory m_enbAntennaModelFactory;
	ObjectFactory m_ueAntennaModelFactory;

	Ptr<EpcHelper> m_epcHelper;


};

}

#endif /* MMWAVE_HELPER_H */

