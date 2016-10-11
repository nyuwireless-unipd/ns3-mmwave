
#ifndef MMWAVE_LOS_TRACKER_H
#define MMWAVE_LOS_TRACKER_H

#include <ns3/buildings-propagation-loss-model.h>
#include "mmwave-beamforming.h"
#include <ns3/simulator.h>

namespace ns3 {

typedef std::pair<Ptr<MobilityModel>, Ptr<MobilityModel> > keyMob_t;

class MmWaveLosTracker : public Object
{

public:
	static TypeId GetTypeId (void);
	MmWaveLosTracker ();
	~MmWaveLosTracker ();
	/**
	 *	Given the two mobility models, updates the m_mapNlos and m_mapLos
	 */
	void UpdateLosNlosState (Ptr<MobilityModel> a, Ptr<MobilityModel> b);
	int GetNlosSamples(Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	int GetLosSamples(Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;

private:
	std::map< keyMob_t, int > m_mapNlos; // map for counting number of slots in NLOS for 'drop phase'
	std::map< keyMob_t, int > m_mapLos; // map for counting number of slots in LOS for 'raise phase'
};

}

#endif /* MMWAVE_LOS_TRACKER_H */
