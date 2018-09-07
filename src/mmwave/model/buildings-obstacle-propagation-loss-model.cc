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
 *					Dual Connectivity and Handover functionalities
 *				Marco Giordani <m.giordani91@gmail.com>
 *					LOS-NLOS transitions
 */

#include "buildings-obstacle-propagation-loss-model.h"

#include "ns3/log.h"
#include "ns3/mobility-model.h"
#include "ns3/double.h"
#include <ns3/mobility-building-info.h>
#include <ns3/building-list.h>
#include <ns3/angles.h>
#include "ns3/config-store.h"
#include <utility>
#include <iostream>
#include "mmwave-beamforming.h"





NS_LOG_COMPONENT_DEFINE ("BuildingsObstaclePropagationLossModel");

namespace ns3 {

namespace mmwave {

NS_OBJECT_ENSURE_REGISTERED (BuildingsObstaclePropagationLossModel);

static const int g_nlosSamplesTrace = 340;

static const double g_blockage_down[9766] = { // Aditya's trace for SINR drop due to blockage
-0.143156,
-0.305271,
-0.445706,
-0.521129,
-0.525290,
-0.424424,
-0.332017,
-0.150800,
-0.071036,
0.121661,
0.146066,
0.088242,
0.017742,
-0.006420,
-0.228977,
-0.287621,
-0.446782,
-0.544409,
-0.568508,
-0.551139,
-0.440483,
-0.316480,
-0.140054,
0.009955,
0.197839,
0.259876,
0.225242,
0.257431,
0.069440,
-0.039298,
-0.269983,
-0.463294,
-0.659582,
-0.765646,
-0.739628,
-0.704979,
-0.454959,
-0.255826,
-0.042315,
0.102321,
0.212834,
0.329262,
0.293065,
0.241862,
0.137127,
-0.026773,
-0.203513,
-0.318958,
-0.428057,
-0.544092,
-0.572746,
-0.521200,
-0.461658,
-0.377918,
-0.312158,
-0.210205,
-0.145555,
-0.102277,
-0.057896,
-0.002832,
-0.027374,
-0.015452,
0.059279,
0.061236,
0.077514,
0.059850,
-0.037925,
-0.100298,
-0.258361,
-0.341506,
-0.476886,
-0.594060,
-0.678424,
-0.765942,
-0.740172,
-0.586668,
-0.500313,
-0.263187,
-0.089928,
0.080674,
0.252648,
0.394833,
0.440695,
0.515957,
0.488636,
0.410864,
0.320519,
0.184308,
0.027795,
-0.137395,
-0.403998,
-0.575180,
-0.729833,
-0.790260,
-0.900701,
-0.936464,
-0.969057,
-0.847965,
-0.822974,
-0.661438,
-0.571599,
-0.411621,
-0.284793,
-0.108007,
0.087111,
0.200808,
0.376294,
0.398154,
0.512300,
0.494971,
0.485569,
0.540187,
0.474398,
0.384233,
0.248015,
0.030593,
-0.167884,
-0.241534,
-0.414298,
-0.514799,
-0.589338,
-0.704769,
-0.723231,
-0.804766,
-0.796111,
-0.787478,
-0.723579,
-0.724234,
-0.774019,
-0.695476,
-0.666312,
-0.660590,
-0.685553,
-0.673293,
-0.634656,
-0.633024,
-0.616388,
-0.605710,
-0.589001,
-0.539892,
-0.465568,
-0.302807,
-0.136732,
0.014522,
0.160321,
0.368205,
0.543382,
0.714995,
0.812399,
0.933484,
1.100135,
1.257916,
1.323027,
1.380619,
1.406058,
1.414900,
1.407222,
1.381133,
1.337843,
1.266705,
1.149845,
1.095932,
0.942718,
0.766929,
0.675382,
0.513004,
0.326206,
0.137720,
-0.083905,
-0.296019,
-0.525252,
-0.713323,
-0.807550,
-0.966604,
-1.142265,
-1.245889,
-1.382312,
-1.527737,
-1.717279,
-1.797723,
-1.947712,
-2.069104,
-2.132696,
-2.302528,
-2.394466,
-2.553930,
-2.705542,
-2.874716,
-3.034799,
-3.232739,
-3.393308,
-3.557832,
-3.792046,
-3.955314,
-4.222041,
-4.376391,
-4.600475,
-4.804743,
-5.098716,
-5.349870,
-5.586870,
-5.903859,
-6.236358,
-6.575979,
-6.912211,
-7.171866,
-7.502323,
-7.728030,
-8.039439,
-8.304107,
-8.509109,
-8.814202,
-8.997569,
-9.225590,
-9.403257,
-9.535958,
-9.688579,
-9.844398,
-9.975387,
-9.940783,
-9.974733,
-10.009171,
-10.012700,
-10.062996,
-10.222380,
-10.226847,
-10.363991,
-10.523214,
-10.666099,
-10.744694,
-10.886488,
-11.008854,
-11.189020,
-11.400263,
-11.515420,
-11.719230,
-11.930227,
-12.211957,
-12.380009,
-12.532707,
-12.806651,
-12.994064,
-13.171256,
-13.446301,
-13.570567,
-13.734144,
-14.015862,
-14.241516,
-14.333808,
-14.552775,
-14.757431,
-14.972272,
-15.207482,
-15.402908,
-15.532766,
-15.765653,
-15.951768,
-16.027105,
-16.270796,
-16.352182,
-16.459486,
-16.625288,
-16.792631,
-16.880499,
-16.985546,
-17.183737,
-17.438513,
-17.677819,
-18.022837,
-18.212433,
-18.479297,
-18.671891,
-18.835204,
-18.930439,
-19.086569,
-19.246267,
-19.368219,
-19.552343,
-19.783466,
-19.975504,
-20.005392,
-20.158885,
-20.189524,
-20.365117,
-20.717048,
-21.078951,
-21.561730,
-21.964372,
-22.212211,
-22.374259,
-22.482698,
-22.377371,
-22.594875,
-22.835124,
-23.169423,
-23.720986,
-24.195096,
-24.636722,
-25.059902,
-25.354778,
-25.862948,
-26.532733,
-27.699042,
-28.801576,
-29.983090,
-30.636709,
-30.724636,
-29.846587,
-29.248176,
-29.046088,
-29.498667,
-30.554450,
-32.596557,
-36.307257,
-40.792113,
-38.220804,
-35.047257,
-32.629152,
-31.588129,
-31.780929,
-32.984136,
-35.822857,
-41.589456,
-44.179106,
-37.296766,
-33.648777,
-32.003182,
-31.621521,
-32.429015,
-35.129796,
-40.182370,
-42.495745,
-36.485499,
-32.361387,
-30.158301,
-29.129017,
-29.033153,
-30.024597,
-32.146189,
-35.964785,
-43.403173,
};

static const double g_blockage_up[9766] = { // Aditya's trace for SINR raise after a blockage
-44.626535,
-41.484524,
-35.542639,
-33.064564,
-32.188339,
-32.308196,
-33.959766,
-38.189198,
-43.802573,
-39.960459,
-34.752793,
-31.928620,
-30.581219,
-30.043458,
-30.479568,
-31.859104,
-34.548992,
-38.583358,
-42.314841,
-39.043043,
-35.487203,
-34.000037,
-33.438540,
-34.175793,
-36.461240,
-38.008759,
-36.506506,
-33.367996,
-30.805426,
-29.240918,
-28.533020,
-28.618357,
-29.048438,
-29.750305,
-29.997189,
-29.263524,
-28.025960,
-26.988622,
-26.330587,
-26.249934,
-26.525372,
-26.877738,
-27.091934,
-26.863477,
-26.171755,
-25.494812,
-25.021712,
-24.954998,
-25.067283,
-25.503315,
-25.558404,
-25.417581,
-25.077902,
-24.722768,
-24.848458,
-25.008788,
-25.429112,
-25.710709,
-25.365337,
-24.695416,
-23.858858,
-23.183555,
-22.818343,
-22.571359,
-22.405672,
-21.967075,
-21.457582,
-20.722213,
-19.989888,
-19.379964,
-19.045431,
-18.637251,
-18.383420,
-18.130031,
-17.845410,
-17.541016,
-17.197698,
-16.948952,
-16.696425,
-16.581112,
-16.526838,
-16.407787,
-16.343810,
-16.298724,
-16.067830,
-16.008159,
-15.863471,
-15.769570,
-15.673789,
-15.567685,
-15.427417,
-15.330002,
-15.191814,
-14.961074,
-14.696628,
-14.480673,
-14.333925,
-13.983246,
-13.686761,
-13.338735,
-12.946241,
-12.595711,
-12.227199,
-11.957683,
-11.527987,
-11.129961,
-10.734705,
-10.309212,
-9.891662,
-9.467709,
-9.017386,
-8.576982,
-8.139815,
-7.818811,
-7.316656,
-6.933068,
-6.566058,
-6.161070,
-5.825050,
-5.531342,
-5.158729,
-4.856072,
-4.438305,
-4.130858,
-3.865557,
-3.522963,
-3.211267,
-2.941180,
-2.651798,
-2.396255,
-2.098285,
-1.901528,
-1.599872,
-1.367262,
-1.203772,
-0.976312,
-0.773541,
-0.543251,
-0.376763,
-0.237732,
-0.035621,
0.061213,
0.237083,
0.360996,
0.491490,
0.604232,
0.675108,
0.804700,
0.897717,
1.007502,
1.026231,
1.050464,
1.143780,
1.182812,
1.199146,
1.105602,
1.113688,
0.981048,
0.944792,
0.773064,
0.654949,
0.455159,
0.166922,
-0.063521,
-0.326096,
-0.582304,
-0.903156,
-1.094482,
-1.345051,
-1.374299,
-1.428529,
-1.429321,
-1.226625,
-1.078834,
-0.839772,
-0.679579,
-0.482935,
-0.197857,
-0.117328,
0.092895,
0.192236,
0.178557,
0.263884,
0.198042,
0.209534,
0.148779,
0.141852,
0.083053,
0.110475,
0.107337,
0.137198,
0.062725,
0.047181,
0.045192,
-0.054041,
-0.197548,
-0.409544,
-0.516984,
-0.603162,
-0.676756,
-0.632196,
-0.583109,
-0.463176,
-0.322816,
-0.263915,
-0.142003,
-0.182175,
-0.120161,
-0.118149,
-0.119640,
-0.092736,
0.021954,
0.099498,
0.173234,
0.194717,
0.146947,
0.078616,
-0.056910,
-0.264259,
-0.472042,
-0.621954,
-0.716587,
-0.708166,
-0.545882,
-0.483361,
-0.362359,
-0.334516,
-0.241875,
-0.238640,
-0.204181,
-0.136935,
0.010405,
0.195253,
0.294927,
0.410286,
0.390945,
0.306402,
0.075973,
-0.187623,
-0.433617,
-0.581261,
-0.756389,
-0.707387,
-0.619136,
-0.495465,
-0.364591,
-0.258932,
-0.224123,
-0.076019,
0.004296,
0.057513,
0.084012,
0.060935,
-0.027674,
-0.099927,
-0.178570,
-0.262350,
-0.373930,
-0.334063,
-0.357786,
-0.213532,
-0.198885,
-0.167385,
-0.101620,
-0.101289,
-0.105508,
-0.164391,
-0.143763,
-0.138498,
-0.177581,
-0.238055,
-0.337353,
-0.367534,
-0.371986,
-0.356527,
-0.281895,
-0.244018,
-0.212179,
-0.057154,
-0.051453,
0.003529,
-0.004547,
-0.054926,
-0.039110,
-0.077921,
-0.189837,
-0.187059,
-0.295733,
-0.297197,
-0.369554,
-0.365608,
-0.424311,
-0.366450,
-0.297944,
-0.237656,
-0.228504,
-0.134198,
-0.082439,
-0.068396,
-0.076791,
-0.085823,
-0.076667,
-0.150096,
-0.056207,
-0.078692,
-0.105029,
-0.253010,
-0.243778,
-0.225778,
-0.295634,
-0.257755,
-0.253912,
-0.287460,
-0.384676,
-0.376763,
-0.346816,
-0.284475,
-0.258721,
-0.190147,
-0.168166,
-0.040819,
-0.045488,
0.040594,
0.081626,
0.098988,
0.009271,
-0.072222,
-0.190947,
-0.274643,
-0.390476,
-0.384739,
-0.411463,
-0.514524,
-0.430885,
-0.440192,
-0.287669,
-0.178381,
-0.115565,
-0.017997,
-0.023686,
0.019578,
};



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
	;
	return tid;
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
	double loss_inner = 0.0;

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

		int nlosSamples = m_losTracker->GetNlosSamples(a,b); // sample to be used in the Aditya's traces
		int losSamples = m_losTracker->GetLosSamples(a,b); // sample to be used in the Aditya's traces

		NS_LOG_LOGIC("At time " << Now().GetMicroSeconds()<< " [mus], nlosSamples in BuildingsPropagationLossModel is:" << nlosSamples
			<< " for mobility model " << a << " and " << b);
		NS_LOG_LOGIC("At time " << Now().GetMicroSeconds()<< " [mus], losSamples in BuildingsPropagationLossModel is:" << losSamples
			<< " for mobility model " << a << " and " << b);

		// TODO: react when PL is LOS or NLOS, according to previoius instants

		if (nlosSamples == -1 || losSamples == -1)
		{
			if(los)
			{
				loss = mmWaveLosLoss (a,b);
			}
			else
			{
				loss = mmWaveNlosLoss (a,b);
			}
		}
		else
		{
			if (!los && nlosSamples < g_nlosSamplesTrace) // I am in NLOS and in the 'drop phase'
			{
				loss_inner = mmWaveLosLoss(a,b);
				double sample_trace = g_blockage_down[nlosSamples-1];
				loss = loss_inner - sample_trace; // 'minus' because I need to "decrement" the pathloss
				NS_LOG_DEBUG("PL NLOS drop phase is " << loss << " and Aditya's sample is " << sample_trace);
			}
			else if (!los && nlosSamples == g_nlosSamplesTrace) // I am in NLOS but in the 'flat phase'
			{
				loss_inner = mmWaveLosLoss(a,b); // -----------------_> CHECK
				double sample_trace = g_blockage_down[nlosSamples-1]; // take the last sample, as a baseline
				loss = loss_inner - sample_trace;
				NS_LOG_DEBUG("PL NLOS is " << loss);

			}
			else if (los && losSamples < g_nlosSamplesTrace && nlosSamples > 0) // I am in NLOS but in the 'raise phase'
			{
				loss_inner = mmWaveLosLoss(a,b);

				double sample_trace;
				if (nlosSamples < g_nlosSamplesTrace) // the 'drop phase' has not lasted, so I need to skip some samples of the 'raise phase'
				{
					 sample_trace = g_blockage_up[g_nlosSamplesTrace - nlosSamples + losSamples - 1];
				}
				else // 'drop phase' has been completely overcome
				{
					 sample_trace = g_blockage_up[losSamples-1]; // in this case, nlosSamples = g_nlosSamplesTrace, so I could use also the if condition
				}

				loss = loss_inner - sample_trace; // 'minus' because I need to "decrement" the pathloss
				NS_LOG_DEBUG("PL LOS raise phase is " << loss << " and Aditya's sample is " << sample_trace);
			}
			else if (los && losSamples == g_nlosSamplesTrace) // I am in LOS, and the 'raise phase' is finally over
			{
				loss = mmWaveLosLoss(a,b);
				NS_LOG_DEBUG("PL LOS  is " << loss);
			}
			else if (los && losSamples == 0 && nlosSamples == 0) // I am in the normal LOS phase
			{
				loss = mmWaveLosLoss(a,b);
				NS_LOG_DEBUG("PL LOS  is " << loss);
			}

		}

		/* OLD VERSION OF THE CODE
		if(los)
		{
			NS_LOG_UNCOND ("LOS");
			//m_beamforming->UpdateMatrices(false);
			loss = mmWaveLosLoss (a,b);
		}
		else
		{
			//m_beamforming->UpdateMatrices(true);
			loss = mmWaveNlosLoss (a,b);
			NS_LOG_UNCOND ("NLOS" << loss );
		}
		*/
	}
	else
	{
		NS_FATAL_ERROR("indoor propagation loss not implement yet");
	}

	loss = std::max (loss, 0.0);
	/*double t = Simulator::Now ().GetSeconds();
	if (t > 5 && t < 5.5)
	{
		m_beamforming->UpdateMatrices(false);
		loss = loss + 50;
	}
	else if (t > 8 && t < 8.5)
	{
		m_beamforming->UpdateMatrices(false);
		loss = loss + 50;
	}*/
	//NS_LOG_UNCOND (a << " " << b << " pathloss " << loss);

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

void
BuildingsObstaclePropagationLossModel::SetBeamforming (Ptr<MmWaveBeamforming> beamforming)
{
	m_beamforming = beamforming;
}

void
BuildingsObstaclePropagationLossModel::SetLosTracker (Ptr<MmWaveLosTracker> losTracker)
{
	m_losTracker = losTracker; // use m_losTracker in the class BuildingsObstaclePropagationLossModel
}

void
BuildingsObstaclePropagationLossModel::SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig)
{
	m_phyMacConfig = ptrConfig;
	m_frequency = m_phyMacConfig->GetCenterFrequency();
    static const double C = 299792458.0; // speed of light in vacuum
    m_lambda = C / m_frequency;

	NS_LOG_UNCOND("Frequency " << m_frequency);
}

} // namespace mmwave

} // namespace ns3
