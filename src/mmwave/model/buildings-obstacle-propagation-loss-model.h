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

#ifndef BUILDINGS_OBSTACLE_PROPAGATION_LOSS_MODEL_H_
#define BUILDINGS_OBSTACLE_PROPAGATION_LOSS_MODEL_H_

#include <ns3/buildings-propagation-loss-model.h>
#include "mmwave-los-tracker.h"
#include <ns3/simulator.h>
#include "mmwave-phy-mac-common.h"



namespace ns3 {

namespace mmwave {

class MmWaveBeamforming;

typedef std::pair<Ptr<MobilityModel>, Ptr<MobilityModel> > keyMob_t;

class BuildingsObstaclePropagationLossModel : public BuildingsPropagationLossModel
{

public:
	static TypeId GetTypeId (void);
	BuildingsObstaclePropagationLossModel ();
	~BuildingsObstaclePropagationLossModel ();
	virtual double GetLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	  // inherited from PropagationLossModel
	virtual double DoCalcRxPower (double txPowerDbm, Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;

	/**
	* Set the configuration parameters which are common in the whole simulation
	* \param a pointer to the MmWavePhyMacCommon object
	*/
	void SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig);

	void SetBeamforming (Ptr<MmWaveBeamforming> beamforming);
	void SetLosTracker (Ptr<MmWaveLosTracker> losTracker);

private:
	double mmWaveLosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	double mmWaveNlosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	double m_frequency;
	double m_lambda;
	Ptr<MmWaveBeamforming> m_beamforming;
	Ptr<MmWaveLosTracker> m_losTracker;
	Ptr<MmWavePhyMacCommon> m_phyMacConfig;
};

}

}

#endif /* BUILDINGS_OBSTACLE_PROPAGATION_LOSS_MODEL_H_ */
