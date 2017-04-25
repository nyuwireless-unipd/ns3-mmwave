 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
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
 *   Author: Marco Giordani <m.giordani91@gmail.com>
 * 			 Michele Polese <michele.polese@gmail.com> 
 *           
 */
#ifndef MMWAVE_LOS_TRACKER_H
#define MMWAVE_LOS_TRACKER_H

#include <ns3/buildings-propagation-loss-model.h>
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
