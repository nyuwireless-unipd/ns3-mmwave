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

#ifndef MMWAVE_3GPP_BUILDINGS_OBSTACLE_PROPAGATION_LOSS_MODEL_H_
#define MMWAVE_3GPP_BUILDINGS_OBSTACLE_PROPAGATION_LOSS_MODEL_H_

#include "ns3/mmwave-3gpp-propagation-loss-model.h"
#include <ns3/buildings-propagation-loss-model.h>
#include <ns3/simulator.h>
#include "mmwave-phy-mac-common.h"
#include <fstream>

namespace ns3 {

namespace mmwave {


class MmWave3gppBuildingsPropagationLossModel : public BuildingsPropagationLossModel
{
public:
	static TypeId GetTypeId (void);
	MmWave3gppBuildingsPropagationLossModel ();
	~MmWave3gppBuildingsPropagationLossModel ();
	virtual double GetLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	  // inherited from PropagationLossModel
	virtual double DoCalcRxPower (double txPowerDbm, Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;

	void SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig);
	std::string GetScenario();
	char GetChannelCondition(Ptr<MobilityModel> a, Ptr<MobilityModel> b);

private:
	//The IsLineIntersectBuildings method is based on
	//ISLineInBox method implemented in Bounding Box Types.
	//Link: http://www.3dkingdoms.com/weekly/weekly.php?a=21.
	bool IsLineIntersectBuildings (Vector L1, Vector L2 ) const;
	void LocationTrace (Vector enbLoc, Vector ueLoc, bool los) const;
	double mmWaveLosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	double mmWaveNlosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	double m_frequency;
	double m_lambda;

	static std::ofstream m_enbUeLocTrace;
	Ptr<MmWave3gppPropagationLossModel> m_3gppLos;
	Ptr<MmWave3gppPropagationLossModel> m_3gppNlos;
	mutable channelConditionMap_t m_conditionMap;
	bool m_updateCondition;
	mutable Time m_prevTime;
	Ptr<MmWavePhyMacCommon> m_phyMacConfig;
};

} // namespace mmwave
} // namespace ns3

#endif /* MMWAVE_3GPP_BUILDINGS_OBSTACLE_PROPAGATION_LOSS_MODEL_H_ */
