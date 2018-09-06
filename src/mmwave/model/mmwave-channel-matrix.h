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


#ifndef MMWAVE_CHANNEL_MATRIX_H_
#define MMWAVE_CHANNEL_MATRIX_H_


#include <ns3/spectrum-value.h>
#include <complex>
#include <ns3/spectrum-signal-parameters.h>
#include <ns3/mobility-model.h>
#include <ns3/spectrum-propagation-loss-model.h>
#include <ns3/net-device.h>
#include <map>
#include <ns3/angles.h>
#include <ns3/net-device-container.h>
#include <ns3/random-variable-stream.h>
#include "mmwave-phy-mac-common.h"




namespace ns3 {

namespace mmwave {


typedef std::vector<double> doubleVector_t;
typedef std::vector< std::complex<double> > complexVector_t;
typedef std::vector<complexVector_t> complex2DVector_t;
typedef std::pair<Ptr<NetDevice>, Ptr<NetDevice> > key_t;


struct ChannelParams : public SimpleRefCount<ChannelParams>
{
	complex2DVector_t 	m_txSpatialMatrix; // tx side spatial matrix
	complex2DVector_t 	m_rxSpatialMatrix; // rx side spatial matrix
	doubleVector_t 		m_powerFraction; // store subpath power fraction
	doubleVector_t 		m_delaySpread; // store delay spread
	doubleVector_t 		m_doppler; // store doppler



};

struct mmWaveBeamFormingParams : public SimpleRefCount<mmWaveBeamFormingParams>
{
	complexVector_t 		m_txW; // tx antenna weights
	complexVector_t 		m_rxW; // rx antenna weights
	Ptr<ChannelParams>  	m_channelParams;
};


class MmWaveChannelMatrix : public SpectrumPropagationLossModel
{
public:

	MmWaveChannelMatrix ();
	virtual ~MmWaveChannelMatrix ();

	static TypeId GetTypeId (void);
	void DoDispose ();
	void ConnectDevices (Ptr<NetDevice> dev1, Ptr<NetDevice> dev2);
	void Initial(NetDeviceContainer ueDevices, NetDeviceContainer enbDevices);

	void SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig);
	Ptr<MmWavePhyMacCommon> GetConfigurationParameters (void) const;

	// hack to allow MmWaveEnbPhy to compute SINR even without pilots
	Ptr<SpectrumValue> CalcRxPowerSpectralDensity(Ptr<const SpectrumValue> txPsd,
	                                                   Ptr<const MobilityModel> a,
	                                                   Ptr<const MobilityModel> b) const;

private:

	Ptr<SpectrumValue> DoCalcRxPowerSpectralDensity (Ptr<const SpectrumValue> txPsd,
														Ptr<const MobilityModel> a,
														Ptr<const MobilityModel> b) const;

	complex2DVector_t GenSpatialMatrix (std::vector<uint16_t> cluster, Angles angle, uint8_t* antennaNum) const;
	complexVector_t GenSinglePath (double hAngle, double vAngle, uint8_t* antennaNum) const;
	//complexVector_t CalcBeamformingVector (complex2DVector_t SpatialMatrix) const;
	Ptr<SpectrumValue> GetChannelGain (Ptr<const SpectrumValue> txPsd, Ptr<mmWaveBeamFormingParams> bfParams, double speed) const;
	double GetSystemBandwidth () const;

	mutable std::map< key_t, int > m_connectedPair;
	mutable std::map< key_t, Ptr<ChannelParams> > m_channelMatrixMap;
	double m_antennaSeparation; //the ratio of the distance between 2 antennas over wave length
	double m_subBW;
	uint32_t m_numRB;
	uint32_t m_numSBPerRB;
	Ptr<UniformRandomVariable> m_uniformRv;
	Ptr<ExponentialRandomVariable> m_expRv;
	Ptr<MmWavePhyMacCommon> m_phyMacConfig;

};

} // namespace mmwave

}  // namespace ns3


#endif /* MMWAVE_CHANNEL_MATRIX_H_ */
