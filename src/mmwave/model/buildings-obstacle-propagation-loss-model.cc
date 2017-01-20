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

#include "buildings-obstacle-propagation-loss-model.h"

#include "ns3/log.h"
#include "ns3/mobility-model.h"
#include "ns3/double.h"
#include <ns3/mobility-building-info.h>
#include <ns3/building-list.h>
#include <ns3/angles.h>
#include "ns3/config-store.h"




NS_LOG_COMPONENT_DEFINE ("BuildingsObstaclePropagationLossModel");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (BuildingsObstaclePropagationLossModel);



BuildingsObstaclePropagationLossModel::BuildingsObstaclePropagationLossModel ()
{
}

BuildingsObstaclePropagationLossModel::~BuildingsObstaclePropagationLossModel ()
{
}

TypeId
BuildingsObstaclePropagationLossModel::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::BuildingsObstaclePropagationLossModel")
		.SetParent<BuildingsPropagationLossModel> ()
		.AddConstructor<BuildingsObstaclePropagationLossModel> ()
		.AddAttribute ("Frequency",
					   "The Frequency  (default is 28 GHz).",
					   DoubleValue (28e9),
					   MakeDoubleAccessor (&BuildingsObstaclePropagationLossModel::SetFrequency),
					   MakeDoubleChecker<double> ())
	;
	return tid;
}



void
BuildingsObstaclePropagationLossModel::SetFrequency (double freq)
	{
	m_frequency = freq;
	static const double C = 299792458.0; // speed of light in vacuum
	m_lambda = C / freq;
}

double
BuildingsObstaclePropagationLossModel::DoCalcRxPower (double txPowerDbm, Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{
	  return txPowerDbm - GetLoss (a, b);
}

double
BuildingsObstaclePropagationLossModel::GetLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
	{
	NS_ASSERT_MSG ((a->GetPosition ().z >= 0) && (b->GetPosition ().z >= 0), "BuildingsObstaclePropagationLossModel does not support underground nodes (placed at z < 0)");

	// get the MobilityBuildingInfo pointers
	Ptr<MobilityBuildingInfo> a1 = a->GetObject<MobilityBuildingInfo> ();
	Ptr<MobilityBuildingInfo> b1 = b->GetObject<MobilityBuildingInfo> ();
	NS_ASSERT_MSG ((a1 != 0) && (b1 != 0), "BuildingsObstaclePropagationLossModel only works with MobilityBuildingInfo");

	double loss = 0.0;

	if (a1->IsOutdoor () && b1->IsOutdoor ())
	{
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



		if(los)
		{
			//NS_LOG_UNCOND ("LOS");
			loss = mmWaveLosLoss (a,b);
		}
		else
		{
			//NS_LOG_UNCOND ("NLOS");
			loss = mmWaveNlosLoss (a,b);
		}
	}
	else
	{
		NS_FATAL_ERROR("indoor propagation loss not implement yet");
	}

	loss = std::max (loss, 0.0);
	/*double t = Simulator::Now ().GetSeconds();
	if (t > 5 && t < 5.5)
	{
		loss = loss + 50;
	}
	else if (t > 8 && t < 8.5)
	{
		loss = loss + 50;
	}*/
	NS_LOG_DEBUG (loss);

	return loss;
}

double
BuildingsObstaclePropagationLossModel::mmWaveLosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{
	double distance = a->GetDistanceFrom (b);
	if (distance < 3*m_lambda)
	{
		NS_LOG_WARN ("distance not within the far field region => inaccurate propagation loss value");
	}
	if (distance <= 0)
	{
		return 0;
	}

	double alpha, beta;
	if (m_frequency == 28e9)
	{
		alpha = 61.4;
		beta = 2;
	}
	else if (m_frequency == 73e9)
	{
		alpha = 69.8;
		beta = 2;
	}
	else
	{
		NS_FATAL_ERROR ("Other frequency is not impletmented.");
	}

	double lossDb = alpha + beta * 10 * log10(distance);
	return lossDb;
}
double
BuildingsObstaclePropagationLossModel::mmWaveNlosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{
	double distance = a->GetDistanceFrom (b);

	double alpha, beta;
	if (m_frequency == 28e9)
	{
		alpha = 72.0;
		beta = 2.92;
	}
	else if (m_frequency == 73e9)
	{
		alpha = 82.7;
		beta = 2.69;
	}
	else
	{
		NS_FATAL_ERROR ("Other frequency is not impletmented.");
	}
	double lossDb = alpha + beta * 10 * log10(distance);
	return lossDb;
}






} // namespace ns3
