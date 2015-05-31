/*
 * antenna-array.h
 *
 *  Created on: Feb 17, 2015
 *      Author: macair
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
	void ChangeBeamformingVector (Ptr<NetDevice> device);
	complexVector_t GetBeamformingVector ();
	complexVector_t GetBeamformingVector (Ptr<NetDevice> device);
private:
	complexVector_t m_beamformingVector;
	std::map<Ptr<NetDevice>, complexVector_t> m_beamformingVectorMap;

};

} /* namespace ns3 */

#endif /* SRC_ANTENNA_MODEL_ANTENNA_ARRAY_MODEL_H_ */
