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

#ifndef ANTENNA_ARRAY_MODEL_H_
#define ANTENNA_ARRAY_MODEL_H_
#include <ns3/antenna-model.h>
#include <complex>
#include <ns3/net-device.h>
#include <map>

namespace ns3 {

typedef std::vector< std::complex<double> > complexVector_t;

class AntennaArrayModel: public AntennaModel {
public:
	AntennaArrayModel();
	virtual ~AntennaArrayModel();
	static TypeId GetTypeId ();
	virtual double GetGainDb (Angles a);
	void SetBeamformingVector (complexVector_t antennaWeights, Ptr<NetDevice> device = 0);
	void SetBeamformingVectorWithDelay (complexVector_t antennaWeights, Ptr<NetDevice> device = 0);

	void ChangeBeamformingVector (Ptr<NetDevice> device);
	void ChangeToOmniTx ();
	complexVector_t GetBeamformingVector ();
	complexVector_t GetBeamformingVector (Ptr<NetDevice> device);
	void SetToSector (uint32_t sector, uint32_t antennaNum);
	bool IsOmniTx ();
	double GetRadiationPattern (double vangle, double hangle = 0);
	Vector GetAntennaLocation (uint8_t index, uint8_t* antennaNum) ;
	void SetSector (uint8_t sector, uint8_t *antennaNum, double elevation = 90);

private:
	bool m_omniTx;
	double m_minAngle;
	double m_maxAngle;
	complexVector_t m_beamformingVector;
	std::map<Ptr<NetDevice>, complexVector_t> m_beamformingVectorMap;

	double m_disV; //antenna spacing in the vertical direction in terms of wave length.
	double m_disH; //antenna spacing in the horizontal direction in terms of wave length.

};

} /* namespace ns3 */

#endif /* SRC_ANTENNA_MODEL_ANTENNA_ARRAY_MODEL_H_ */
