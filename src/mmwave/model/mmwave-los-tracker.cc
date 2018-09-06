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
#include "mmwave-los-tracker.h"

#include <ns3/log.h>
#include <fstream>
#include <ns3/simulator.h>
#include <ns3/abort.h>
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mc-ue-net-device.h>
#include <ns3/mmwave-ue-phy.h>
#include <ns3/antenna-array-model.h>
#include <ns3/node.h>
#include <algorithm>
#include <ns3/double.h>
#include <ns3/boolean.h>
#include "ns3/mobility-model.h"
#include <ns3/mobility-building-info.h>
#include <ns3/building-list.h>
#include <ns3/angles.h>
#include "ns3/config-store.h"
#include <utility>
#include <iostream>

namespace ns3 {

namespace mmwave {

NS_LOG_COMPONENT_DEFINE ("MmWaveLosTracker");

NS_OBJECT_ENSURE_REGISTERED (MmWaveLosTracker);

static const int g_nlosSamplesTrace = 340;

MmWaveLosTracker::MmWaveLosTracker ()
{}


TypeId
MmWaveLosTracker::GetTypeId (void)
{
	static TypeId tid = TypeId("ns3::MmWaveLosTracker")
	.SetParent<Object>()
	;

	return tid;

}

MmWaveLosTracker::~MmWaveLosTracker ()
{

}

void
MmWaveLosTracker::UpdateLosNlosState(Ptr<MobilityModel> a, Ptr<MobilityModel> b)
{

	/* Get the MobilityBuildingInfo pointers */
	Ptr<MobilityBuildingInfo> a1 = a->GetObject<MobilityBuildingInfo> ();
	Ptr<MobilityBuildingInfo> b1 = b->GetObject<MobilityBuildingInfo> ();
	NS_ASSERT_MSG ((a1 != 0) && (b1 != 0), "BuildingsObstaclePropagationLossModel only works with MobilityBuildingInfo");


	/*Determine LOS or NLOS*/
	bool los = true;
	for (BuildingList::Iterator bit = BuildingList::Begin (); bit != BuildingList::End (); ++bit)
	{
		Box boundaries = (*bit)->GetBoundaries ();
		Vector locationA = a->GetPosition ();
		Vector locationB = b->GetPosition ();
		Angles pathAngles (locationB, locationA);
		double angle = pathAngles.phi;
		if (angle >= M_PI/2 || angle < -M_PI/2)
		{
			locationA = b->GetPosition ();
			locationB = a->GetPosition ();
			Angles pathAngles (locationB, locationA);
			angle = pathAngles.phi;
		}

		if (angle >=0 && angle < M_PI/2 )
		{
			Vector loc1(boundaries.xMax,boundaries.yMin,boundaries.zMin);
			Vector loc2(boundaries.xMin,boundaries.yMax,boundaries.zMin);
			Angles angles1 (loc1,locationA);
			Angles angles2 (loc2,locationA);
			if (angle > angles1.phi && angle < angles2.phi && locationB.x > boundaries.xMin && locationB.y > boundaries.yMin)
			{
				los = false;
				break;
			}
		}
		else if (angle >= -M_PI/2 && angle < 0)
		{
			Vector loc1(boundaries.xMin,boundaries.yMin,boundaries.zMin);
			Vector loc2(boundaries.xMax,boundaries.yMax,boundaries.zMin);
			Angles angles1 (loc1,locationA);
			Angles angles2 (loc2,locationA);
			if (angle > angles1.phi && angle < angles2.phi && locationB.x > boundaries.xMin && locationB.y < boundaries.yMax)
			{
				los = false;
				break;
			}
		}
	}


	/*
	* Initialization: if this is the first time that I encounter this MobilityModel pair, then add
	* a new instance of the mapNloS/mapLos
	*/

	keyMob_t key = std::make_pair(a,b);
	keyMob_t key_reverse = std::make_pair(b,a); // check for the MobilityModel pair (b.a), assuming 'channel reciprocity'

	std::map< keyMob_t, int >::iterator iteratorNlos =
							 m_mapNlos.find(key); // pair [key,value] for that pair of MobilityModels (a,b)

	std::map< keyMob_t, int >::iterator iteratorLos =
							 m_mapLos.find(key); // pair [key,value] for that pair of MobilityModels (a,b)

	int nlosSamples;
	int losSamples;
	if(iteratorNlos != m_mapNlos.end()) // an instance of the MobilityModel pair (a,b) aready exists
	{
		nlosSamples = iteratorNlos->second; // current counter for Nlossamples in the exerimental blockage trace
	}
	else
	{
		iteratorNlos = m_mapNlos.find(key_reverse);
		if (iteratorNlos != m_mapNlos.end())
	 	{
			nlosSamples = iteratorNlos->second;
		}
		else
		{
			m_mapNlos.insert(std::pair<keyMob_t, int>(key_reverse,0));
			m_mapNlos.insert(std::pair<keyMob_t, int>(key,0));
			nlosSamples = m_mapNlos.at(key);
		}
	}


	if(iteratorLos != m_mapLos.end()) // an instance of the MobilityModel pair (a,b) aready exists
	{
		losSamples = iteratorLos->second; // current counter for Nlossamples in the exerimental blockage trace
	}
	else
	{
		iteratorLos = m_mapLos.find(key_reverse);
		if (iteratorLos != m_mapLos.end())
	 	{
			losSamples = iteratorLos->second;
		}
		else
		{
			m_mapLos.insert(std::pair<keyMob_t, int>(key_reverse,0));
			m_mapLos.insert(std::pair<keyMob_t, int>(key,0));
			losSamples = m_mapLos.at(key);
		}
	}


	/* CHANGE BOTH MobilityModel for pair (a,b) and pair (b,a), since we assume channel reciprocity */
	if (!los && nlosSamples < g_nlosSamplesTrace) // I am in NLOS and in the 'drop phase'
	{
		if (Now().GetMicroSeconds() == 0) // simualtion starts when the UE is in NLOS --> assume it is in the 'flat phase'
		{
			m_mapNlos.at(key) = g_nlosSamplesTrace;
			m_mapNlos.at(key_reverse) = g_nlosSamplesTrace;
			NS_LOG_LOGIC("NLOS in flat phase beacuse it is the beginning of the simulation");
		}
		else
		{
			m_mapNlos.at(key) = nlosSamples + 1; // still in the 'drop' phase
			m_mapNlos.at(key_reverse) = nlosSamples + 1; // still in the 'drop' phase
			NS_LOG_LOGIC("NLOS in drop phase, at sample " <<  nlosSamples+1);
		}
	}
	else if (!los && nlosSamples == g_nlosSamplesTrace) // I am in NLOS but in the 'flat phase'
	{
		m_mapNlos.at(key) = g_nlosSamplesTrace; // NLOS but in 'flat phase'
		m_mapNlos.at(key_reverse) = g_nlosSamplesTrace; // NLOS but in 'flat phase'
		NS_LOG_LOGIC("NLOS in flat phase, at sample " << nlosSamples+1);
	}
	else if (los && losSamples < g_nlosSamplesTrace && nlosSamples > 0) // I am in NLOS but in the 'raise phase'
	{
		m_mapLos.at(key) = losSamples + 1;
		m_mapLos.at(key_reverse) = losSamples + 1;
		NS_LOG_LOGIC("LOS in raise phase, at sample " << losSamples+1);
	}
	else if (los && losSamples == g_nlosSamplesTrace) // I am in LOS, and the 'raise phase' is finally over
	{
		m_mapLos.at(key) = 0;
		m_mapNlos.at(key) = 0;
		m_mapLos.at(key_reverse) = 0;
		m_mapNlos.at(key_reverse) = 0;
		NS_LOG_LOGIC("End of LOS in raise phase, at sample " << nlosSamples);
	}
	else if (los && losSamples == 0 && nlosSamples == 0) // I am in the normal LOS phase
	{
		m_mapLos.at(key) = 0;
		m_mapNlos.at(key) = 0;
		m_mapLos.at(key_reverse) = 0;
		m_mapNlos.at(key_reverse) = 0;
		NS_LOG_LOGIC("Nomral LOS phase");
	}

}


int
MmWaveLosTracker::GetNlosSamples (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{

	if (m_mapNlos.find(std::make_pair(a,b)) != m_mapNlos.end()) // at least initialized for MobilityModel (a,b)
	{
		NS_LOG_LOGIC("Method GetNlosSamples is MmWaveLosTracker. For normal mobility pair: nlossamples = " << m_mapNlos.at(std::make_pair(a,b)));
		return m_mapNlos.at(std::make_pair(a,b));
	}
	else
	{
		if (m_mapNlos.find(std::make_pair(b,a)) != m_mapNlos.end()) // at least initialized for MobilityModel (b,a)
		{
			NS_LOG_LOGIC("Method GetNlosSamples is MmWaveLosTracker. For reverse mobility pair: nlossamples = " << m_mapNlos.at(std::make_pair(b,a)));
			return m_mapNlos.at(std::make_pair(b,a));
		}
		else
		{
			NS_LOG_LOGIC("Method GetNlosSamples for MmWaveLosTracker not initliazied");
			return -1;
		}
	}

}

int
MmWaveLosTracker::GetLosSamples (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{

	if (m_mapLos.find(std::make_pair(a,b)) != m_mapLos.end()) // at least initialized for MobilityModel (a,b)
	{
		NS_LOG_LOGIC("Method GetLosSamples is MmWaveLosTracker. For normal mobility pair: lossamples = " << m_mapLos.at(std::make_pair(a,b)));
		return m_mapLos.at(std::make_pair(a,b));
	}
	else
	{
		if (m_mapLos.find(std::make_pair(b,a)) != m_mapLos.end()) // at least initialized for MobilityModel (b,a)
		{
			NS_LOG_LOGIC("Method GetLosSamples is MmWaveLosTracker. For reverse mobility pair: lossamples = " << m_mapLos.at(std::make_pair(b,a)));
			return m_mapLos.at(std::make_pair(b,a));
		}
		else
		{
			NS_LOG_LOGIC("Method GetLosSamples for MmWaveLosTracker not initliazied");
			return -1;
		}
	}
}


} // namespace mmwave

} // namespace ns3
