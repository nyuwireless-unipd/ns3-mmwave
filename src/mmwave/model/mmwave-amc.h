/*
 * mmwave-amc.h
 *
 *  Created on: Feb 1, 2015
 *      Author: macair
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_AMC_H_
#define SRC_MMWAVE_MODEL_MMWAVE_AMC_H_
#include <ns3/object.h>
#include <ns3/spectrum-value.h>
#include <ns3/mmwave-phy-mac-common.h>

namespace ns3 {

class mmWaveAmc: public Object
{
public:
	static TypeId GetTypeId (void);
	mmWaveAmc ();
	mmWaveAmc(Ptr<mmWavePhyMacCommon> ConfigParams);
	virtual ~mmWaveAmc();
	enum AmcModel
	{
		PiroEW2010,
		MiErrorModel // model based on 10% of BER according to LteMiErrorModel
	};

	int GetMcsFromCqi (int cqi);
	int GetTbSizeFromMcs (int mcs, int nprb);
	std::vector<int> CreateCqiFeedbacks (const SpectrumValue& sinr, uint8_t rbgSize);
	int GetCqiFromSpectralEfficiency (double s);

private:
	  double m_ber;
	  AmcModel m_amcModel;

	  Ptr<mmWavePhyMacCommon> m_ConfigParams;
};

} // end namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_AMC_H_ */
