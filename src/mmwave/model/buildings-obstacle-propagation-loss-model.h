
#ifndef BUILDINGS_OBSTACLE_PROPAGATION_LOSS_MODEL_H_
#define BUILDINGS_OBSTACLE_PROPAGATION_LOSS_MODEL_H_

#include <ns3/buildings-propagation-loss-model.h>
#include "mmwave-beamforming.h"
#include <ns3/simulator.h>



namespace ns3 {


class BuildingsObstaclePropagationLossModel : public BuildingsPropagationLossModel
{

public:
	static TypeId GetTypeId (void);
	BuildingsObstaclePropagationLossModel ();
	~BuildingsObstaclePropagationLossModel ();
	virtual double GetLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	  // inherited from PropagationLossModel
	virtual double DoCalcRxPower (double txPowerDbm, Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	void SetFrequency (double freq);
	void SetBeamforming (Ptr<MmWaveBeamforming> beamforming);

private:
	double mmWaveLosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	double mmWaveNlosLoss (Ptr<MobilityModel> a, Ptr<MobilityModel> b) const;
	double m_frequency;
	double m_lambda;
	Ptr<MmWaveBeamforming> m_beamforming;

};

}

#endif /* BUILDINGS_OBSTACLE_PROPAGATION_LOSS_MODEL_H_ */
