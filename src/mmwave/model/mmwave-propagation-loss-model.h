/*
 * mmwave-propagation-loss-model.h
 *
 *  Created on: Oct 28, 2015
 *      Author: mengleizhang
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_PROPAGATION_LOSS_MODEL_H_
#define SRC_MMWAVE_MODEL_MMWAVE_PROPAGATION_LOSS_MODEL_H_


#include <ns3/propagation-loss-model.h>
#include "ns3/object.h"
#include "ns3/random-variable-stream.h"
#include <map>

using namespace ns3;

struct channelScenario
{
	  char m_channelScenario;
	  double m_shadowing;
};

// map store the path loss scenario(LOS,NLOS,OUTAGE) of each propapgation channel
typedef std::map< std::pair< Ptr<MobilityModel>, Ptr<MobilityModel> >, channelScenario> channelScenarioMap_t;

class MmWavePropagationLossModel : public PropagationLossModel
{
public:
  static TypeId GetTypeId (void);
  MmWavePropagationLossModel ();
  /**
   * \param frequency (Hz)
   *
   * Set the carrier frequency used in the mmWave model
   * calculation.
   */
  void SetFrequency (double frequency);

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

private:
  MmWavePropagationLossModel (const MmWavePropagationLossModel &o);
  MmWavePropagationLossModel & operator = (const MmWavePropagationLossModel &o);
  virtual double DoCalcRxPower (double txPowerDbm,
                                Ptr<MobilityModel> a,
                                Ptr<MobilityModel> b) const;
  virtual int64_t DoAssignStreams (int64_t stream);
  void UpDataScenarioMap ();

  double m_lambda;
  mutable double m_frequency;
  double m_minLoss;
  mutable channelScenarioMap_t m_channelScenarioMap;
  std::string m_channelStates;
};

#endif
