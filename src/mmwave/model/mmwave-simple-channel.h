 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
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
 *
 *   Author: Marco Mezzavilla < mezzavilla@nyu.edu>
 *        	 Sourjya Dutta <sdutta@nyu.edu>
 *        	 Russell Ford <russell.ford@nyu.edu>
 *        	 Menglei Zhang <menglei@nyu.edu>
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *			Dual Connectivity and Handover functionalities
 */


#ifndef MMWAVE_SIMPLE_CHANNEL_H
#define MMWAVE_SIMPLE_CHANNEL_H


#include <ns3/object.h>
#include <ns3/mobility-model.h>
#include <ns3/propagation-loss-model.h>
#include <ns3/spectrum-value.h>
#include <ns3/spectrum-propagation-loss-model.h>
#include <ns3/net-device.h>
#include <ns3/net-device-container.h>
#include <map>
#include <tuple>
#include "mmwave-3gpp-channel.h"


namespace ns3 {

namespace mmwave {

class MmWaveSimpleChannel : public SpectrumPropagationLossModel
{
public:

	MmWaveSimpleChannel ();
	virtual ~MmWaveSimpleChannel ();
	static TypeId GetTypeId (void);

protected:
	virtual void DoDispose ();
	virtual void DoInitialize ();

public:
	void ConnectDevices (Ptr<NetDevice> dev1, Ptr<NetDevice> dev2);
	void Initial(NetDeviceContainer ueDevices, NetDeviceContainer enbDevices);

	void SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig);
	Ptr<MmWavePhyMacCommon> GetConfigurationParameters (void) const;

	// hack to allow MmWaveEnbPhy to compute SINR even without pilots
	// public method with the same name and params of the private one
	Ptr<SpectrumValue> CalcRxPowerSpectralDensity(Ptr<const SpectrumValue> txPsd,
	                                                   Ptr<const MobilityModel> a,
	                                                   Ptr<const MobilityModel> b) const;

	/**
	 * Set the pathloss model associated to this class
	 * @param a pointer to the pathloss model, which has to implement the PropagationLossModel interface
	 */
	void SetPathlossModel (Ptr<PropagationLossModel> pathloss);

private:

	// apply the small scale fading and the beamforming gain
	Ptr<SpectrumValue> DoCalcRxPowerSpectralDensity (Ptr<const SpectrumValue> txPsd,
														Ptr<const MobilityModel> a,
														Ptr<const MobilityModel> b) const;

	double ComputeBfGain(Angles txAngle, Angles rxAngle, complexVector_t txBfVector, complexVector_t rxBfVector, uint16_t txNumCol, uint16_t rxNumCol) const;
	complexVector_t ComputeBfVector(uint16_t antennaNum, Angles steeringAngle) const;

	void SetBeamformingVector (Ptr<NetDevice> ueDevice, Ptr<NetDevice> enbDevice, Angles ueAngle, Angles enbAngle) const;

	std::tuple<uint16_t, uint16_t, uint16_t, uint16_t, Ptr<AntennaArrayModel>, Ptr<AntennaArrayModel>, bool, bool, Angles, Angles,
		complexVector_t, complexVector_t> GetTxRxInfo(Ptr<MobilityModel const> a, Ptr<MobilityModel const> b) const;

	mutable std::map< key_t, int > m_connectedPair;
	// double m_antennaSeparation; //the ratio of the distance between 2 antennas over wave length
	Ptr<MmWavePhyMacCommon> m_phyMacConfig;

	double m_nakaParamLos;
	double m_nakaParamNlos;
	Ptr<NakagamiPropagationLossModel> m_nakaLosFading; //it is called Prop Loss but if used with power = 1 it computes only the fading
	Ptr<NakagamiPropagationLossModel> m_nakaNlosFading;

	Ptr<PropagationLossModel> m_3gppPathloss;

	bool m_disableFadingBeamforming;

	bool m_quantizeBeams;

	Time m_updatePeriodicity;
};

} //namespace mmwave

}  //namespace ns3

#endif /* MMWAVE_SIMPLE_CHANNEL_H */
