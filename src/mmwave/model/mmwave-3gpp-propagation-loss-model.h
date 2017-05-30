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
 *   Author: Marco Miozzo <marco.miozzo@cttc.es>
 *           Nicola Baldo  <nbaldo@cttc.es>
 *  
 *   Modified by: Marco Mezzavilla < mezzavilla@nyu.edu>
 *        	 	  Sourjya Dutta <sdutta@nyu.edu>
 *        	 	  Russell Ford <russell.ford@nyu.edu>
 *        		  Menglei Zhang <menglei@nyu.edu>
 */


#ifndef MMWAVE_3GPP_PROPAGATION_LOSS_MODEL_H_
#define MMWAVE_3GPP_PROPAGATION_LOSS_MODEL_H_


#include <ns3/propagation-loss-model.h>
#include "ns3/object.h"
#include "ns3/random-variable-stream.h"
#include <ns3/vector.h>
#include <map>
#include "mmwave-phy-mac-common.h"
/*
 * This 3GPP channel model is implemented base on the 3GPP TR 38.900 v14.1.0 (2016-09).
 *
 * 3rd Generation Partnership Project;
 * Technical Specification Group Radio Access Network;
 * Study on channel model for frequency spectrum above 6 GHz
 * (Release 14)
 *
 * */


using namespace ns3;

struct channelCondition
{
	  char m_channelCondition;
	  double m_shadowing;
	  Vector m_position;
	  double m_hE; //the effective environment height mentioned in Table 7.4.1-1 Note 1.
	  double m_carPenetrationLoss; //car penetration loss in dB.
};

// map store the path loss scenario(LOS,NLOS,OUTAGE) of each propapgation channel
typedef std::map< std::pair< Ptr<MobilityModel>, Ptr<MobilityModel> >, channelCondition> channelConditionMap_t;

class MmWave3gppPropagationLossModel : public PropagationLossModel
{
public:
  static TypeId GetTypeId (void);
  MmWave3gppPropagationLossModel ();

  void SetConfigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig);

  /**
   * \param minLoss the minimum loss (dB)
   *
   * no matter how short the distance, the total propagation loss (in
   * dB) will always be greater or equal than this value
   */
  void SetMinLoss (double minLoss);

  /**
   * \return the minimum loss.
   */
  double GetMinLoss (void) const;

  /**
   * \returns the current frequency (Hz)
   */
  double GetFrequency (void) const;

  char GetChannelCondition(Ptr<MobilityModel> a, Ptr<MobilityModel> b);

  std::string GetScenario();

  double GetLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;

private:
  MmWave3gppPropagationLossModel (const MmWave3gppPropagationLossModel &o);
  MmWave3gppPropagationLossModel & operator = (const MmWave3gppPropagationLossModel &o);
  virtual double DoCalcRxPower (double txPowerDbm,
                                Ptr<MobilityModel> a,
                                Ptr<MobilityModel> b) const;
  virtual int64_t DoAssignStreams (int64_t stream);
  void UpdateConditionMap (Ptr<MobilityModel> a, Ptr<MobilityModel> b, channelCondition cond) const;

  double m_lambda;
  double m_frequency;
  double m_minLoss;
  mutable channelConditionMap_t m_channelConditionMap;
  std::string m_channelConditions; //limit the channel condition to be LoS/NLoS only.
  std::string m_scenario;
  bool m_optionNlosEnabled;
  Ptr<NormalRandomVariable> m_norVar;
  Ptr<UniformRandomVariable> m_uniformVar;
  bool m_shadowingEnabled;
  bool m_inCar;
  Ptr<MmWavePhyMacCommon> m_phyMacConfig;
};

#endif
