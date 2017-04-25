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
 *   along with this program; if not, write to the Free Software
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
 * Modified by: Michele Polese <michele.polese@gmail.com> 
 *                 Dual Connectivity and Handover functionalities
 */


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
#include <ns3/mc-ue-net-device.h>
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/mmwave-phy.h>
#include <ns3/mmwave-ue-phy.h>
#include <ns3/mmwave-enb-phy.h>
#include <ns3/mmwave-spectrum-value-helper.h>
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
#include <ns3/mmwave-beamforming.h>
#include <ns3/mmwave-channel-matrix.h>
#include <ns3/mmwave-bearer-stats-calculator.h>
#include <ns3/mc-stats-calculator.h>
#include <ns3/mmwave-bearer-stats-connector.h>
#include <ns3/propagation-loss-model.h>
#include <ns3/mmwave-channel-raytracing.h>

#include <ns3/lte-enb-mac.h>
#include <ns3/lte-enb-net-device.h>
#include <ns3/lte-enb-phy.h>
#include <ns3/ff-mac-scheduler.h>
#include <ns3/lte-handover-algorithm.h>
#include <ns3/epc-enb-s1-sap.h>
#include <ns3/lte-anr.h>
#include <ns3/lte-spectrum-value-helper.h>
#include <ns3/core-network-stats-calculator.h>
#include <ns3/mmwave-los-tracker.h>

#include <ns3/buildings-obstacle-propagation-loss-model.h>
#include <ns3/mmwave-3gpp-channel.h>

namespace ns3 {

/* ... */
class MmWaveUePhy;
class MmWaveEnbPhy;
class SpectrumChannel;
class SpectrumpropagationLossModel;
class MmWaveSpectrumValueHelper;
class PropagationLossModel;
//class MmWave3gppChannel;

class MmWaveHelper : public Object
{
public:
	MmWaveHelper(void);
	virtual ~MmWaveHelper(void);

	static TypeId GetTypeId (void);
	virtual void DoDispose (void);

	NetDeviceContainer InstallUeDevice (NodeContainer c);
	NetDeviceContainer InstallMcUeDevice (NodeContainer c);
	NetDeviceContainer InstallInterRatHoCapableUeDevice(NodeContainer c);
	NetDeviceContainer InstallEnbDevice (NodeContainer c);
	NetDeviceContainer InstallLteEnbDevice (NodeContainer c);
	void SetAntenna (uint16_t Nrx, uint16_t Ntx);
	void SetPathlossModelType (std::string type);
	void SetChannelModelType (std::string type);
	void SetLtePathlossModelType (std::string type);
	/**
	 * Attach mmWave-only ueDevices to the closest enbDevice
	 */ 
	void AttachToClosestEnb (NetDeviceContainer ueDevices, NetDeviceContainer enbDevices);
	/**
	 * Attach MC ueDevices to the closest LTE enbDevice, register all MmWave eNBs to the MmWaveUePhy
	 */
	void AttachToClosestEnb (NetDeviceContainer ueDevices, NetDeviceContainer mmWaveEnbDevices, NetDeviceContainer lteEnbDevices);

	/**
	 * Attach MC ueDevices to the closest MmWave eNB device, register all MmWave eNBs to the MmWaveUePhy,
	 * store all cellId in each LteUeRrc layer.
	 * This must be used when attaching InterRatHandover capable devices
	 */
	void AttachIrToClosestEnb (NetDeviceContainer ueDevices, NetDeviceContainer mmWaveEnbDevices, NetDeviceContainer lteEnbDevices);


	void EnableTraces ();

	void SetSchedulerType (std::string type);
	std::string GetSchedulerType () const;

	void SetLteSchedulerType (std::string type);
	std::string GetLteSchedulerType () const;


	void SetPhyMacConfigurationParameters (std::string paramName, std::string value);
    Ptr<MmWavePhyMacCommon> GetPhyMacConfigurable (void);
	void ActivateDataRadioBearer (NetDeviceContainer ueDevices, EpsBearer bearer);
	void ActivateDataRadioBearer (Ptr<NetDevice> ueDevice, EpsBearer bearer);
	void SetEpcHelper (Ptr<EpcHelper> epcHelper);

	void SetHarqEnabled (bool harqEnabled);
	bool GetHarqEnabled ();
	void SetSnrTest (bool snrTest);
	bool GetSnrTest ();
	Ptr<PropagationLossModel> GetPathLossModel (void);

	/**
	* Set the type of FFR algorithm to be used by LTE eNodeB devices.
	*
	* \param type type of FFR algorithm, must be a type name of any class
	*             inheriting from ns3::LteFfrAlgorithm, for example:
	*             "ns3::LteFrNoOpAlgorithm"
	*
	* Equivalent with setting the `FfrAlgorithm` attribute.
	*/
	void SetLteFfrAlgorithmType (std::string type);

	/**
	*
	* \return the LTE FFR algorithm type
	*/
	std::string GetLteFfrAlgorithmType () const;

	/**
	* Set the type of handover algorithm to be used by LTE eNodeB devices.
	*
	* \param type type of handover algorithm, must be a type name of any class
	*             inheriting from ns3::LteHandoverAlgorithm, for example:
	*             "ns3::NoOpHandoverAlgorithm"
	*
	* Equivalent with setting the `HandoverAlgorithm` attribute.
	*/
	void SetLteHandoverAlgorithmType (std::string type);

	/**
	*
	* \return the LTE handover algorithm type
	*/
	std::string GetLteHandoverAlgorithmType () const;

	void AddX2Interface (NodeContainer enbNodes);
	void AddX2Interface (NodeContainer lteEnbNodes, NodeContainer mmWaveEnbNodes);
	void AddX2Interface (Ptr<Node> enbNode1, Ptr<Node> enbNode2);

protected:
	virtual void DoInitialize();

private:
	Ptr<NetDevice> InstallSingleUeDevice (Ptr<Node> n);
	Ptr<NetDevice> InstallSingleMcUeDevice (Ptr<Node> n);
	Ptr<NetDevice> InstallSingleEnbDevice (Ptr<Node> n);
	Ptr<NetDevice> InstallSingleLteEnbDevice (Ptr<Node> n);
	Ptr<NetDevice> InstallSingleInterRatHoCapableUeDevice(Ptr<Node> n);

	void AttachToClosestEnb (Ptr<NetDevice> ueDevice, NetDeviceContainer enbDevices);
	void AttachMcToClosestEnb (Ptr<NetDevice> ueDevice, NetDeviceContainer mmWaveEnbDevices, NetDeviceContainer lteEnbDevices);
	void AttachIrToClosestEnb (Ptr<NetDevice> ueDevice, NetDeviceContainer mmWaveEnbDevices, NetDeviceContainer lteEnbDevices);

	void EnableDlPhyTrace ();
	void EnableUlPhyTrace ();
	void EnableEnbPacketCountTrace ();
	void EnableUePacketCountTrace ();
	void EnableTransportBlockTrace ();
	void EnableRlcTraces (void);
	Ptr<MmWaveBearerStatsCalculator> GetRlcStats (void);
	void EnablePdcpTraces (void);
	Ptr<MmWaveBearerStatsCalculator> GetPdcpStats (void);
	void EnableMcTraces (void);
	Ptr<McStatsCalculator> GetMcStats (void);

	Ptr<SpectrumChannel> m_channel; // mmWave TDD channel	
	Ptr<SpectrumChannel> m_downlinkChannel; /// The downlink LTE channel used in the simulation.
	Ptr<SpectrumChannel> m_uplinkChannel; 	/// The uplink LTE channel used in the simulation.

	Ptr<MmWaveBeamforming> m_beamforming;
	Ptr<MmWaveLosTracker> m_losTracker;
	Ptr<MmWaveChannelMatrix> m_channelMatrix;
	Ptr<MmWaveChannelRaytracing> m_raytracing;
	Ptr<MmWave3gppChannel> m_3gppChannel;

	Ptr<Object> m_pathlossModel;
	std::string m_pathlossModelType;
	Ptr<Object> m_downlinkPathlossModel; 	  /// The path loss model used in the LTE downlink channel.
	Ptr<Object> m_uplinkPathlossModel;   /// The path loss model used in the LTE uplink channel.


	std::string m_channelModelType;

	ObjectFactory m_enbNetDeviceFactory;
	ObjectFactory m_lteEnbNetDeviceFactory;
	ObjectFactory m_ueNetDeviceFactory;
	ObjectFactory m_mcUeNetDeviceFactory;
	ObjectFactory m_channelFactory; 	// TODO check if one factory for the channel is enough
	ObjectFactory m_pathlossModelFactory;	// Each channel (mmWave, LteUl & LteDl) may have a different pathloss with diff attributes
	ObjectFactory m_schedulerFactory;
	ObjectFactory m_lteSchedulerFactory; // Factory for LTE scheduler
	ObjectFactory m_ffrAlgorithmFactory;	
	ObjectFactory m_lteFfrAlgorithmFactory;
	ObjectFactory m_lteHandoverAlgorithmFactory;

	ObjectFactory m_phyMacCommonFactory;
	ObjectFactory m_lteChannelFactory; 	/// Factory of both the downlink and uplink LTE channels.
	ObjectFactory m_dlPathlossModelFactory; 	/// Factory of path loss model object for the downlink channel.
	ObjectFactory m_ulPathlossModelFactory; 	/// Factory of path loss model object for the uplink channel.


	uint64_t m_imsiCounter;
	uint16_t m_cellIdCounter;

	uint16_t m_noTxAntenna;
	uint16_t m_noRxAntenna;

	Ptr<MmWavePhyRxTrace> m_phyStats;

	Ptr<MmWavePhyMacCommon> m_phyMacCommon;

 	ObjectFactory m_enbAntennaModelFactory;
	ObjectFactory m_ueAntennaModelFactory;	// Factory of antenna object for mmWave UE
	ObjectFactory m_lteUeAntennaModelFactory;	/// Factory of antenna object for Lte UE.
	ObjectFactory m_lteEnbAntennaModelFactory; /// Factory of antenna objects for Lte eNB.
 
 	/**
	* From lte-helper.h
	* The `UsePdschForCqiGeneration` attribute. If true, DL-CQI will be
	* calculated from PDCCH as signal and PDSCH as interference. If false,
	* DL-CQI will be calculated from PDCCH as signal and PDCCH as interference.
	*/
	bool m_usePdschForCqiGeneration;
	bool m_isAnrEnabled;

	Ptr<EpcHelper> m_epcHelper;

	bool m_harqEnabled;
	bool m_rlcAmEnabled;
	bool m_snrTest;
 	bool m_useIdealRrc; // Initialized as true in the constructor

	Ptr<MmWaveBearerStatsCalculator> m_rlcStats;
	Ptr<MmWaveBearerStatsCalculator> m_pdcpStats;
	Ptr<McStatsCalculator> m_mcStats;
	Ptr<MmWaveBearerStatsConnector> m_radioBearerStatsConnector;
  	Ptr<CoreNetworkStatsCalculator> m_cnStats;

};

}

#endif /* MMWAVE_HELPER_H */

