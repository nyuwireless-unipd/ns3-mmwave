 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
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
 */


#ifndef MMWAVE_3GPP_CHANNEL_H_
#define MMWAVE_3GPP_CHANNEL_H_


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
#include "ns3/mmwave-phy-mac-common.h"
#include "ns3/mmwave-3gpp-propagation-loss-model.h"
#include <ns3/antenna-array-model.h>
#include "ns3/mmwave-3gpp-buildings-propagation-loss-model.h"

#define AOA_INDEX 0
#define ZOA_INDEX 1
#define AOD_INDEX 2
#define ZOD_INDEX 3

#define PHI_INDEX 0
#define X_INDEX 1
#define THETA_INDEX 2
#define Y_INDEX 3
#define R_INDEX 4

namespace ns3 {

namespace mmwave {

//class MmWave3gppBuildingsPropagationLossModel;

typedef std::vector<double> doubleVector_t;
typedef std::vector<doubleVector_t> double2DVector_t;

typedef std::vector< std::complex<double> > complexVector_t;
typedef std::vector<complexVector_t> complex2DVector_t;
typedef std::vector<complex2DVector_t> complex3DVector_t;

typedef std::pair<Ptr<NetDevice>, Ptr<NetDevice> > key_t;

/**
 * Data structure that stores a channel realization
 */
struct Params3gpp : public SimpleRefCount<Params3gpp>
{
	complexVector_t 		m_txW; // tx antenna weights.
	complexVector_t 		m_rxW; // rx antenna weights.
	complex3DVector_t  		m_channel; // channel matrix H[u][s][n].
	doubleVector_t  		m_delay; // cluster delay.
	double2DVector_t		m_angle; //cluster angle angle[direction][n], where direction = 0(aoa), 1(zoa), 2(aod), 3(zod) in degree.
	complexVector_t 		m_longTerm; // long term conponet.

	double2DVector_t		m_nonSelfBlocking; // store the blockages

	/*The following parameters are stored for spatial consistent updating*/
	Vector m_preLocUT; // location of UT when generating the previous channel
	Vector m_locUT; // location of UT
	double2DVector_t m_norRvAngles; //stores the normal variable for random angles angle[cluster][id] generated for equation (7.6-11)-(7.6-14), where id = 0(aoa),1(zoa),2(aod),3(zod)
	Time m_generatedTime;
	double m_DS; // delay spread
	double m_K; //K factor
	uint8_t m_numCluster; // reduced cluster number;
	double2DVector_t m_clusterPhase;
	double m_losPhase;
	bool m_los;
	bool m_o2i;
	Vector m_speed;
	double m_dis2D;
	double m_dis3D;

	std::map<Ptr<NetDevice>, complexVector_t> m_allLongTermMap;
};

/**
 * Data structure that stores the parameters of 3GPP TR 38.900, Table 7.5-6, for a certain scenario
 */
struct ParamsTable: public Object
{
	uint8_t m_numOfCluster = 0;
	uint8_t m_raysPerCluster = 0;
	double m_uLgDS = 0;
	double m_sigLgDS = 0;
	double m_uLgASD = 0;
	double m_sigLgASD = 0;
	double m_uLgASA = 0;
	double m_sigLgASA = 0;
	double m_uLgZSA = 0;
	double m_sigLgZSA = 0;
	double m_uLgZSD = 0;
	double m_sigLgZSD = 0;
	double m_offsetZOD = 0;
	double m_cDS = 0;
	double m_cASD = 0;
	double m_cASA = 0;
	double m_cZSA = 0;
	double m_uK = 0;
	double m_sigK = 0;
	double m_rTau = 0;
	double m_shadowingStd = 0;

	double m_sqrtC[7][7];

	ParamsTable(){}
	void SetParams(uint8_t numOfCluster, uint8_t raysPerCluster, double uLgDS, double sigLgDS,
			double uLgASD, double sigLgASD, double uLgASA, double sigLgASA,
			double uLgZSA, double sigLgZSA, double uLgZSD, double sigLgZSD, double offsetZOD,
			double cDS, double cASD, double cASA, double cZSA,
			double uK, double sigK, double rTau, double shadowingStd)
	{
		m_numOfCluster = numOfCluster;
		m_raysPerCluster = raysPerCluster;
		m_uLgDS = uLgDS;
		m_sigLgDS = sigLgDS;
		m_uLgASD = uLgASD;
		m_sigLgASD = sigLgASD;
		m_uLgASA = uLgASA;
		m_sigLgASA = sigLgASA;
		m_uLgZSA = uLgZSA;
		m_sigLgZSA = sigLgZSA;
		m_uLgZSD = uLgZSD;
		m_sigLgZSD = sigLgZSD;
		m_offsetZOD = offsetZOD;
		m_cDS = cDS;
		m_cASD = cASD;
		m_cASA = cASA;
		m_cZSA = cZSA;
		m_uK = uK;
		m_sigK = sigK;
		m_rTau = rTau;
		m_shadowingStd = shadowingStd;
	}

};

/**
 * \brief This class implements the fading computation of the 3GPP TR 38.900 channel model and performs the
 * beamforming gain computation. It implements the SpectrumPropagationLossModel interface
 */
class MmWave3gppChannel : public SpectrumPropagationLossModel
{
public:

	/**
    * Constructor
    */
	MmWave3gppChannel ();
	/**
   	* Destructor
   	*/
	virtual ~MmWave3gppChannel ();

	// inherited from Object
	static TypeId GetTypeId (void);
	void DoDispose ();

	/**
	 * Register the connection between two devices
	 * @param a pointer to a NetDevice
	 * @param a pointer to a NetDevice
	 */
	void ConnectDevices (Ptr<NetDevice> dev1, Ptr<NetDevice> dev2);

	/**
	 * Register the connection between all the devices in the NetDeviceContainer given
	 * as input
	 * @param a NetDeviceContainer for the UEs
	 * @param a NetDeviceContainer for the eNBs
	 */
	void Initial(NetDeviceContainer ueDevices, NetDeviceContainer enbDevices);

	/**
	 * Set the initial BF vector between two devices
	 * @param a pointer to a NetDevice for the UE
	 * @param a pointer to a NetDevice for the eNB
	 */
	void SetBeamformingVector (Ptr<NetDevice> ueDevice, Ptr<NetDevice> enbDevice);

	/**
	 * Set the MmWavePhyMacCommon object with the parameters of the scenario
	 * @param a pointer to the MmWavePhyMacCommon configuration
	 */
	void SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig);

	/**
	 * Get the MmWavePhyMacCommon object with the parameters of the scenario
	 * @returns a pointer to the MmWavePhyMacCommon configuration
	 */
	Ptr<MmWavePhyMacCommon> GetConfigurationParameters (void) const;

	/**
	 * Set the pathloss model associated to this class
	 * @param a pointer to the pathloss model, which has to implement the PropagationLossModel interface
	 */
	void SetPathlossModel (Ptr<PropagationLossModel> pathloss);

	/**
	 * Set MmWave3gppChannel in interference/data or reference signal mode.
	 * With the first, the beamforming pairs are associated to the data transmission
	 * ongoing, and correctly handle the interference
	 * With the second, on each link MmWave3gppChannel uses the BF vectors associated to the link
	 *@param boolean flag (true = interference/data mode)
	 */
	void SetInterferenceOrDataMode(bool flag);

private:

	/**
	 * Inherited from SpectrumPropagationLossModel, it returns the PSD at the receiver
	 * @params the transmitted PSD
	 * @params the mobility model of the transmitter
	 * @params the mobility model of the receiver
	 * @returns the received PSD
	 */
	Ptr<SpectrumValue> DoCalcRxPowerSpectralDensity (Ptr<const SpectrumValue> txPsd,
														Ptr<const MobilityModel> a,
														Ptr<const MobilityModel> b) const;

	/**
	 * Get a new realization of the channel
	 * @params the ParamsTable for the specific scenario
	 * @params the location of UT
	 * @params the los condition
	 * @params the o2i condition
	 * @params the ArrayAntennaModel for the txAntenna
	 * @params the ArrayAntennaModel for the rxAntenna
	 * @params the number of txAntenna per row
	 * @params the number of rxAntenna per row
	 * @params the rxAngle
	 * @params the txAngle
	 * @params the relative speed between tx and rx
	 * @params the 2D distance between tx and rx
	 * @params the 3D distance between tx and rx
	 * @returns the channel realization in a Params3gpp object
	 */
	Ptr<Params3gpp> GetNewChannel(Ptr<ParamsTable> table3gpp, Vector locUT, bool los, bool o2i,
			Ptr<AntennaArrayModel> txAntenna, Ptr<AntennaArrayModel> rxAntenna,
			uint8_t *txAntennaNum, uint8_t *rxAntennaNum, Angles &rxAngle, Angles &txAngle,
			Vector speed, double dis2D, double dis3D) const;

	/**
	 * Update the channel realization with procedure A of TR 38.900 Sec 7.6.3.2
	 * for the spatial consistency
	 * @params the previous channel realization in a Params3gpp object
	 * @params the ParamsTable for the specific scenario
	 * @params the ArrayAntennaModel for the txAntenna
	 * @params the ArrayAntennaModel for the rxAntenna
	 * @params the number of txAntenna per row
	 * @params the number of rxAntenna per row
	 * @params the rxAngle
	 * @params the txAngle
	 * @returns the channel realization in a Params3gpp object
	 */
	Ptr<Params3gpp> UpdateChannel(Ptr<Params3gpp> params3gpp, Ptr<ParamsTable> table3gpp,
			Ptr<AntennaArrayModel> txAntenna, Ptr<AntennaArrayModel> rxAntenna,
			uint8_t *txAntennaNum, uint8_t *rxAntennaNum, Angles &rxAngle, Angles &txAngle) const;

	/**
	 * Compute the optimal BF vector with the Power Method (Maximum Ratio Transmission method).
	 * The vector is stored in the Params3gpp object passed as parameter
	 * @params the channel realizationin as a Params3gpp object
	 */
	void LongTermCovMatrixBeamforming (Ptr<Params3gpp> params) const;

	/**
	 * Scan all sectors with predefined code book and select the one returns maximum gain.
	 * The BF vector is stored in the Params3gpp object passed as parameter
	 * @params the channel realizationin as a Params3gpp object
	 */
	void BeamSearchBeamforming (Ptr<const SpectrumValue> txPsd, Ptr<Params3gpp> params, Ptr<AntennaArrayModel> txAntenna,
			Ptr<AntennaArrayModel> rxAntenna, uint8_t *txAntennaNum, uint8_t *rxAntennaNum) const;


	/**
	 * Compute and return the long term fading params in order to decrease the computational load
	 * @params the channel realizationin as a Params3gpp object
	 * @return the complexVector_t with the BF applied to the channel
	 */
	complexVector_t CalLongTerm (Ptr<Params3gpp> params) const;

	/**
	 * Compute the BF gain, apply frequency selectivity by phase-shifting with the cluster delays
	 * and scale the txPsd to get the rxPsd
	 * @params the tx PSD
	 * @params the channel realizationin as a Params3gpp object
	 * @params the longTerm component (i.e., with the BF vectors already applied)
	 * @params the relative speed between UE and eNB
	 * @returns the rx PSD
	 */
	Ptr<SpectrumValue> CalBeamformingGain (Ptr<const SpectrumValue> txPsd,
												Ptr<Params3gpp> params,
												complexVector_t longTerm,
												Vector speed) const;

	/**
	 * Returns the bandwidth used in a scenario
	 * @returns a double with the bandwidth
	 */
	double GetSystemBandwidth () const;

	/**
	 * Returns the ParamsTable with the parameters of TR 38.900 Table 7.5-6
	 * that apply to a certain scenario
	 * @params the los condition
	 * @params the o2i condition
	 * @params the BS height (i.e., eNB)
	 * @params the UT height (i.e., UE)
	 * @params the 2D distance
	 * @return the ParamsTable structure
	 */
	Ptr<ParamsTable> Get3gppTable (bool los, bool o2i,
										double hBS, double hUT, double distance2D) const;

	/**
	 * Delete the m_channel entry associated to the Params3gpp object of pair (a,b)
	 * but keep the other parameters, so that the spatial consistency procedure can be used
	 * @params the mobility model of the transmitter
	 * @params the mobility model of the receiver
	 */
	void DeleteChannel(Ptr<const MobilityModel> a,
			Ptr<const MobilityModel> b) const;
	/*
	 * Returns the attenuation of each cluster in dB after applying blockage model
	 * @params the channel realizationin as a Params3gpp object
	 * @params cluster azimuth angle of arrival
	 * @params cluster zenith angle of arrival
	 */
	doubleVector_t CalAttenuationOfBlockage(Ptr<Params3gpp> params,
			doubleVector_t clusterAOA, doubleVector_t clusterZOA) const;

	mutable std::map< key_t, int > m_connectedPair;
	mutable std::map< key_t, Ptr<Params3gpp> > m_channelMap;

	Ptr<UniformRandomVariable> m_uniformRv;
	Ptr<UniformRandomVariable> m_uniformRvBlockage;

	Ptr<NormalRandomVariable> m_normalRv; //there is a bug in the NormalRandomVariable::GetValue() function.
	Ptr<NormalRandomVariable> m_normalRvBlockage;


	Ptr<ExponentialRandomVariable> m_expRv;
	Ptr<MmWavePhyMacCommon> m_phyMacConfig;
	Ptr<PropagationLossModel> m_3gppPathloss;
	Ptr<ParamsTable> m_table3gpp;
	Time m_updatePeriod;
	bool m_directBeam;
	bool m_blockage;
	uint16_t m_numNonSelfBloking; //number of non-self-blocking regions.
	bool m_portraitMode; //true (portrait mode); false (landscape mode).
	std::string m_scenario;
	double m_blockerSpeed;
	bool m_forceInitialBfComputation;
	bool m_interferenceOrDataMode;

	NetDeviceContainer m_enbNetDeviceContainer;
	NetDeviceContainer m_ueNetDeviceContainer;

};


} // namespace mmwave
}  // namespace ns3


#endif /* MMWAVE_3GPP_CHANNEL_H_ */
