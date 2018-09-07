 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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



#include "mmwave-3gpp-propagation-loss-model.h"
#include <ns3/log.h>
#include "ns3/mobility-model.h"
#include "ns3/boolean.h"
#include "ns3/double.h"
#include "ns3/string.h"
#include "ns3/pointer.h"
#include <ns3/simulator.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mc-ue-net-device.h>
#include <ns3/node.h>

namespace ns3 {

namespace mmwave {

// ------------------------------------------------------------------------- //
NS_LOG_COMPONENT_DEFINE ("MmWave3gppPropagationLossModel");

NS_OBJECT_ENSURE_REGISTERED (MmWave3gppPropagationLossModel);

TypeId
MmWave3gppPropagationLossModel::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::MmWave3gppPropagationLossModel")
    .SetParent<PropagationLossModel> ()
    .AddConstructor<MmWave3gppPropagationLossModel> ()
    .AddAttribute ("MinLoss",
                   "The minimum value (dB) of the total loss, used at short ranges.",
                   DoubleValue (0.0),
                   MakeDoubleAccessor (&MmWave3gppPropagationLossModel::SetMinLoss,
                                       &MmWave3gppPropagationLossModel::GetMinLoss),
                   MakeDoubleChecker<double> ())
    .AddAttribute ("ChannelCondition",
					"'l' for LOS, 'n' for NLOS, 'a' for all",
					StringValue ("a"),
					MakeStringAccessor (&MmWave3gppPropagationLossModel::m_channelConditions),
					MakeStringChecker ())
	.AddAttribute ("Scenario",
				"The available channel scenarios are 'RMa', 'UMa', 'UMi-StreetCanyon', 'InH-OfficeMixed', 'InH-OfficeOpen', 'InH-ShoppingMall'",
				StringValue ("RMa"),
				MakeStringAccessor (&MmWave3gppPropagationLossModel::m_scenario),
				MakeStringChecker ())
	.AddAttribute ("OptionalNlos",
				"Use the optional NLoS propagation loss model",
				BooleanValue (false),
				MakeBooleanAccessor (&MmWave3gppPropagationLossModel::m_optionNlosEnabled),
				MakeBooleanChecker ())
	.AddAttribute ("Shadowing",
				"Enable shadowing effect",
				BooleanValue (true),
				MakeBooleanAccessor (&MmWave3gppPropagationLossModel::m_shadowingEnabled),
				MakeBooleanChecker ())
	.AddAttribute ("InCar",
				"If inside a vehicle, car penetration loss should be added to propagation loss",
				BooleanValue (false),
				MakeBooleanAccessor (&MmWave3gppPropagationLossModel::m_inCar),
				MakeBooleanChecker ())
  ;
  return tid;
}

MmWave3gppPropagationLossModel::MmWave3gppPropagationLossModel ()
{
  m_channelConditionMap.clear ();
  m_norVar = CreateObject<NormalRandomVariable> ();
  m_norVar->SetAttribute ("Mean", DoubleValue (0));
  m_norVar->SetAttribute ("Variance", DoubleValue (1));

  m_uniformVar = CreateObject<UniformRandomVariable> ();
  m_uniformVar->SetAttribute ("Min", DoubleValue (0));
  m_uniformVar->SetAttribute ("Max", DoubleValue (1));

}

void
MmWave3gppPropagationLossModel::SetMinLoss (double minLoss)
{
  m_minLoss = minLoss;
}
double
MmWave3gppPropagationLossModel::GetMinLoss (void) const
{
  return m_minLoss;
}

double
MmWave3gppPropagationLossModel::GetFrequency (void) const
{
  return m_frequency;
}


double
MmWave3gppPropagationLossModel::DoCalcRxPower (double txPowerDbm,
                                          Ptr<MobilityModel> a,
                                          Ptr<MobilityModel> b) const
{
	  return (txPowerDbm - GetLoss (a, b));
}

double
MmWave3gppPropagationLossModel::GetLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const
{
	Ptr<MobilityModel> ueMob, enbMob;
	if((DynamicCast<mmwave::MmWaveUeNetDevice> (a->GetObject<Node> ()->GetDevice (0)) !=0)
		|| (DynamicCast<McUeNetDevice> (a->GetObject<Node> ()->GetDevice (0)) !=0))
	{
		if(DynamicCast<MmWaveEnbNetDevice> (b->GetObject<Node> ()->GetDevice (0)) !=0)
		{
			ueMob = a;
			enbMob = b;
		}
		else
		{
			NS_LOG_INFO("UE->UE Link, skip Pathloss computation");
			return 0;
		}
	}
	else
	{
		if(DynamicCast<MmWaveEnbNetDevice> (b->GetObject<Node> ()->GetDevice (0)) !=0)
		{
			NS_LOG_INFO("ENB->ENB Link, skip Pathloss computation");
			return 0;
		}
		else
		{
			ueMob = b;
			enbMob = a;
		}
	}


	Vector uePos = ueMob->GetPosition();
	Vector enbPos = enbMob->GetPosition();
	double x = uePos.x-enbPos.x;
	double y = uePos.y-enbPos.y;
	double distance2D = sqrt (x*x +y*y);
	double hBs = enbPos.z;
	double hUt = uePos.z;

	double distance3D = a->GetDistanceFrom (b);

	if (distance3D < 3*m_lambda)
	{
		NS_LOG_UNCOND ("distance not within the far field region => inaccurate propagation loss value");
	}
	if (distance3D <= 0)
	{
		return  m_minLoss;
	}


	channelConditionMap_t::const_iterator it;
	it = m_channelConditionMap.find(std::make_pair(a,b));
	if (it == m_channelConditionMap.end ())
	{
		channelCondition condition;

		if (m_channelConditions.compare("l")==0 )
		{
			condition.m_channelCondition = 'l';
			NS_LOG_UNCOND (m_scenario << " scenario, channel condition is fixed to be " << condition.m_channelCondition<<", h_BS="<<hBs<<",h_UT="<<hUt);
		}
		else if (m_channelConditions.compare("n")==0)
		{
			condition.m_channelCondition = 'n';
			NS_LOG_UNCOND (m_scenario << " scenario, channel condition is fixed to be " << condition.m_channelCondition<<", h_BS="<<hBs<<",h_UT="<<hUt);
		}
		else if (m_channelConditions.compare("a")==0)
		{
			double PRef = m_uniformVar->GetValue();
			double probLos;
			//Note: The LOS probability is derived with assuming antenna heights of 3m for indoor, 10m for UMi, and 25m for UMa.
			if (m_scenario == "RMa")
			{
				if(distance2D <= 10)
				{
					probLos = 1;
				}
				else
				{
					probLos = exp(-(distance2D-10)/1000);
				}
			}
			else if (m_scenario == "UMa")
			{
				if(distance2D <= 18)
				{
					probLos = 1;
				}
				else
				{
					double C_hUt;
					if (hUt <= 13)
					{
						C_hUt = 0;
					}
					else if(hUt <=23)
					{
						C_hUt = pow((hUt-13)/10,1.5);
					}
					else
					{
						NS_FATAL_ERROR ("From Table 7.4.2-1, UMa scenario hUT cannot be larger than 23 m");
					}
					probLos = (18/distance2D+exp(-distance2D/63)*(1-18/distance2D))*(1+C_hUt*5/4*pow(distance2D/100,3)*exp(-distance2D/150));
				}
			}
			else if (m_scenario == "UMi-StreetCanyon")
			{
				if(distance2D <= 18)
				{
					probLos = 1;
				}
				else
				{
					probLos = 18/distance2D+exp(-distance2D/36)*(1-18/distance2D);
				}
			}
			else if (m_scenario == "InH-OfficeMixed")
			{
				if(distance2D <= 1.2)
				{
					probLos = 1;
				}
				else if (distance2D <= 6.5)
				{
					probLos = exp(-(distance2D-1.2)/4.7);
				}
				else
				{
					probLos = exp(-(distance2D-6.5)/32.6)*0.32;
				}
			}
			else if (m_scenario == "InH-OfficeOpen")
			{
				if(distance2D <= 5)
				{
					probLos = 1;
				}
				else if (distance2D <= 49)
				{
					probLos = exp(-(distance2D-5)/70.8);
				}
				else
				{
					probLos = exp(-(distance2D-49)/211.7)*0.54;
				}
			}
			else if (m_scenario == "InH-ShoppingMall")
			{
				probLos = 1;

			}
			else
			{
				NS_FATAL_ERROR ("Unknown scenario");
			}

			if (PRef <= probLos)
			{
				condition.m_channelCondition = 'l';
			}
			else
			{
				condition.m_channelCondition = 'n';
			}
			NS_LOG_UNCOND (m_scenario << " scenario, 2D distance = " << distance2D <<"m, Prob_LOS = " << probLos
					<< ", Prob_REF = " << PRef << ", the channel condition is " << condition.m_channelCondition<<", h_BS="<<hBs<<",h_UT="<<hUt);

		}
		else
		{
			NS_FATAL_ERROR ("Wrong channel condition configuration");
		}
		// assign a large negative value to identify initial transmission.
		condition.m_shadowing = -1e6;
		condition.m_hE = 0;
		//condition.m_carPenetrationLoss = 9+m_norVar->GetValue()*5;
		condition.m_carPenetrationLoss = 10;
		std::pair<channelConditionMap_t::const_iterator, bool> ret;
		ret = m_channelConditionMap.insert (std::make_pair(std::make_pair (a,b), condition));
		m_channelConditionMap.insert (std::make_pair(std::make_pair (b,a), condition));
		it = ret.first;
	}

	/* Reminder.
	 * The The LOS NLOS state transition will be implemented in the future as mentioned in secction 7.6.3.3
	 * */

	double lossDb = 0;
	double freqGHz = m_frequency/1e9;

	double shadowingStd = 0;
	double shadowingCorDistance = 0;
	if (m_scenario == "RMa")
	{
		if(distance2D < 10)
		{
			NS_LOG_UNCOND ("The 2D distance is smaller than 10 meters, the 3GPP RMa model may not be accurate");
		}

		if (hBs < 10 || hBs > 150 )
		{
			NS_FATAL_ERROR ("According to table 7.4.1-1, the RMa scenario need to satisfy the following condition, 10 m <= hBS <= 150 m");
		}

		if (hUt < 1 || hUt > 10 )
		{
			NS_FATAL_ERROR ("According to table 7.4.1-1, the RMa scenario need to satisfy the following condition, 1 m <= hUT <= 10 m");
		}
		//default base station antenna height is 35 m
		//hBs = 35;
		//default user antenna height is 1.5 m
		//hUt = 1.5;
		double W = 20; //average street height
		double h = 5; //average building height

		double dBP = 2*M_PI*hBs*hUt*m_frequency/3e8; //break point distance
		double PL1 = 20*log10(40*M_PI*distance3D*freqGHz/3) + std::min(0.03*pow(h,1.72),10.0)*log10(distance3D) - std::min(0.044*pow(h,1.72),14.77) + 0.002*log10(h)*distance3D;

		if(distance2D <= dBP)
		{
			lossDb = PL1;
			shadowingStd = 4;

		}
		else
		{
			//PL2
			lossDb = PL1 + 40*log10(distance3D/dBP);
			shadowingStd= 6;
		}

		switch ((*it).second.m_channelCondition)
		{
			case 'l':
			{
				shadowingCorDistance = 37;
				break;
			}
			case 'n':
			{
				shadowingCorDistance = 120;
				double PLNlos = 161.04-7.1*log10(W)+7.5*log10(h)-(24.37-3.7*pow((h/hBs),2))*log10(hBs)+(43.42-3.1*log10(hBs))*(log10(distance3D)-3)+20*log10(freqGHz)-(3.2*pow(log10(11.75*hUt),2)-4.97);
				lossDb = std::max(PLNlos, lossDb);
				shadowingStd = 8;
				break;
			}
			default:
				NS_FATAL_ERROR ("Programming Error.");
		}

	}
	else if (m_scenario == "UMa")
	{
		if(distance2D < 10)
		{
			NS_LOG_UNCOND ("The 2D distance is smaller than 10 meters, the 3GPP UMa model may not be accurate");
		}

		//default base station value is 25 m
		//hBs = 25;

		if (hUt < 1.5 || hUt > 22.5 )
		{
			NS_FATAL_ERROR ("According to table 7.4.1-1, the UMa scenario need to satisfy the following condition, 1.5 m <= hUT <= 22.5 m");
		}
		//For UMa, the effective environment height should be computed follow Table7.4.1-1.
		if((*it).second.m_hE == 0)
		{
			channelCondition condition;
			condition = (*it).second;
			if (hUt <= 18)
			{
				condition.m_hE = 1;
			}
			else
			{
				double g_d2D = 1.25*pow(distance2D/100,3)*exp(-1*distance2D/150);
				double C_d2D_hUT = pow((hUt-13)/10,1.5)*g_d2D;
				double prob = 1/(1+C_d2D_hUT);

				if(m_uniformVar->GetValue() < prob)
				{
					condition.m_hE = 1;
				}
				else
				{
					int random = m_uniformVar->GetInteger(12, (int)(hUt-1.5));
					condition.m_hE = (double)floor(random/3)*3;
				}
			}
			UpdateConditionMap(a,b,condition);
		}
		double dBP = 4*(hBs-(*it).second.m_hE)*(hUt-(*it).second.m_hE)*m_frequency/3e8;
		if(distance2D <= dBP)
		{
			//PL1
			lossDb = 32.4+20*log10(distance3D)+20*log10(freqGHz);
		}
		else
		{
			//PL2
			lossDb = 32.4+40*log10(distance3D)+20*log10(freqGHz)-10*log10(pow(dBP,2)+pow(hBs-hUt,2));
		}


		switch ((*it).second.m_channelCondition)
		{
			case 'l':
			{
				shadowingStd = 4;
				shadowingCorDistance = 37;
				break;
			}
			case 'n':
			{
				shadowingCorDistance = 50;
				if(m_optionNlosEnabled)
				{
					//optional propagation loss
					lossDb = 32.4+20*log10(freqGHz)+30*log10(distance3D);
					shadowingStd = 7.8;
				}
				else
				{
					double PLNlos = 13.54+39.08*log10(distance3D)+20*log10(freqGHz)-0.6*(hUt-1.5);
					shadowingStd = 6;
					lossDb = std::max(PLNlos, lossDb);
				}


				break;
			}
			default:
				NS_FATAL_ERROR ("Programming Error.");
		}
	}
	else if (m_scenario == "UMi-StreetCanyon")
	{

		if(distance2D < 10)
		{
			NS_LOG_UNCOND ("The 2D distance is smaller than 10 meters, the 3GPP UMi-StreetCanyon model may not be accurate");
		}

		//default base station value is 10 m
		//hBs = 10;

		if (hUt < 1.5 || hUt > 22.5 )
		{
			NS_FATAL_ERROR ("According to table 7.4.1-1, the UMi-StreetCanyon scenario need to satisfy the following condition, 1.5 m <= hUT <= 22.5 m");
		}
		double dBP = 4*(hBs-1)*(hUt-1)*m_frequency/3e8;
		if(distance2D <= dBP)
		{
			//PL1
			lossDb = 32.4+21*log10(distance3D)+20*log10(freqGHz);
		}
		else
		{
			//PL2
			lossDb = 32.4+40*log10(distance3D)+20*log10(freqGHz)-9.5*log10(pow(dBP,2)+pow(hBs-hUt,2));
		}


		switch ((*it).second.m_channelCondition)
		{
			case 'l':
			{
				shadowingStd = 4;
				shadowingCorDistance = 10;
				break;
			}
			case 'n':
			{
				shadowingCorDistance = 13;
				if(m_optionNlosEnabled)
				{
					//optional propagation loss
					lossDb = 32.4+20*log10(freqGHz)+31.9*log10(distance3D);
					shadowingStd = 8.2;
				}
				else
				{
					double PLNlos = 35.3*log10(distance3D)+22.4+21.3*log10(freqGHz)-0.3*(hUt-1.5);
					shadowingStd = 7.82;
					lossDb = std::max(PLNlos, lossDb);
				}

				break;
			}
			default:
				NS_FATAL_ERROR ("Programming Error.");
		}
	}
	else if (m_scenario == "InH-OfficeMixed" || m_scenario == "InH-OfficeOpen")
	{
		if(distance3D < 1 || distance3D > 100)
		{
			NS_LOG_UNCOND ("The pathloss might not be accurate since 3GPP InH-Office model LoS condition is accurate only within 3D distance between 1 m and 100 m");
		}

		lossDb = 32.4+17.3*log10(distance3D)+20*log10(freqGHz);


		switch ((*it).second.m_channelCondition)
		{
			case 'l':
			{
				shadowingStd = 3;
				shadowingCorDistance = 10;
				break;
			}
			case 'n':
			{
				shadowingCorDistance = 6;
				if(distance3D > 86)
				{
					NS_LOG_UNCOND ("The pathloss might not be accurate since 3GPP InH-Office model NLoS condition only supports 3D distance between 1 m and 86 m");
				}

				if(m_optionNlosEnabled)
				{
					//optional propagation loss
					double PLNlos = 32.4+20*log10(freqGHz)+31.9*log10(distance3D);
					shadowingStd = 8.29;
					lossDb = std::max(PLNlos, lossDb);

				}
				else
				{
					double PLNlos = 38.3*log10(distance3D)+17.3+24.9*log10(freqGHz);
					shadowingStd = 8.03;
					lossDb = std::max(PLNlos, lossDb);
				}
				break;
			}
			default:
				NS_FATAL_ERROR ("Programming Error.");
		}
	}

	else if (m_scenario == "InH-ShoppingMall")
	{
		shadowingCorDistance = 10; //I use the office correlation distance since shopping mall is not in the table.

		if(distance3D < 1 || distance3D > 150)
		{
			NS_LOG_UNCOND ("The pathloss might not be accurate since 3GPP InH-Shopping mall model only supports 3D distance between 1 m and 150 m");\
		}
		lossDb = 32.4+17.3*log10(distance3D)+20*log10(freqGHz);
		shadowingStd = 2;
	}
	else
	{
		NS_FATAL_ERROR ("Unknown channel condition");
	}

	if(m_shadowingEnabled)
	{
		channelCondition cond;
		cond = (*it).second;
		//The first transmission the shadowing is initialed as -1e6,
		//we perform this if check the identify first  transmission.
		if((*it).second.m_shadowing < -1e5)
		{
			cond.m_shadowing = m_norVar->GetValue()*shadowingStd;
		}
		else
		{
			double deltaX = uePos.x-(*it).second.m_position.x;
			double deltaY = uePos.y-(*it).second.m_position.y;
			double disDiff = sqrt (deltaX*deltaX +deltaY*deltaY);
			//NS_LOG_UNCOND (shadowingStd <<"  "<<disDiff <<"  "<<shadowingCorDistance);
			double R = exp(-1*disDiff/shadowingCorDistance); // from equation 7.4-5.
			cond.m_shadowing = R*(*it).second.m_shadowing + sqrt(1-R*R)*m_norVar->GetValue()*shadowingStd;
		}

		lossDb += cond.m_shadowing;
		cond.m_position = ueMob->GetPosition();
		UpdateConditionMap(a,b,cond);
	}


	 /*FILE* log_file;

	  char* fname = (char*)malloc(sizeof(char) * 255);

	  memset(fname, 0, sizeof(char) * 255);
	  std::string temp;
	  if(m_optionNlosEnabled)
	  {
		  temp = m_scenario+"-"+(*it).second.m_channelCondition+"-opt.txt";
	  }
	  else
	  {
		  temp = m_scenario+"-"+(*it).second.m_channelCondition+".txt";
	  }

	  log_file = fopen(temp.c_str(), "a");

	  fprintf(log_file, "%f \t  %f\n", distance3D, lossDb);

	  fflush(log_file);

	  fclose(log_file);

	  if(fname)

	  free(fname);

	  fname = 0;*/

	if(m_inCar)
	{
		lossDb += (*it).second.m_carPenetrationLoss;
	}

	return std::max (lossDb, m_minLoss);
}

int64_t
MmWave3gppPropagationLossModel::DoAssignStreams (int64_t stream)
{
  return 0;
}

void
MmWave3gppPropagationLossModel::UpdateConditionMap (Ptr<MobilityModel> a, Ptr<MobilityModel> b, channelCondition cond) const
{
	m_channelConditionMap[std::make_pair (a,b)] = cond;
	m_channelConditionMap[std::make_pair (b,a)] = cond;

}

char
MmWave3gppPropagationLossModel::GetChannelCondition(Ptr<MobilityModel> a, Ptr<MobilityModel> b)
{
	channelConditionMap_t::const_iterator it;
	it = m_channelConditionMap.find(std::make_pair(a,b));
	if (it == m_channelConditionMap.end ())
	{
		NS_FATAL_ERROR ("Cannot find the link in the map");
	}
	return (*it).second.m_channelCondition;

}

std::string
MmWave3gppPropagationLossModel::GetScenario ()
{
	return m_scenario;
}

void
MmWave3gppPropagationLossModel::SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig)
{
	m_phyMacConfig = ptrConfig;
	m_frequency = m_phyMacConfig->GetCenterFrequency();
    static const double C = 299792458.0; // speed of light in vacuum
    m_lambda = C / m_frequency;

    NS_LOG_INFO("Frequency " << m_frequency);
}

} // namespace mmwave

} // namespace ns3
