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

class MmWaveAmc: public Object
{
public:
	static TypeId GetTypeId (void);
	MmWaveAmc ();
	MmWaveAmc(Ptr<MmWavePhyMacCommon> ConfigParams);
	virtual ~MmWaveAmc();
	enum AmcModel
	{
		PiroEW2010,
		MiErrorModel // model based on 10% of BER according to LteMiErrorModel
	};

	int GetMcsFromCqi (int cqi);
	int GetTbSizeFromMcs (unsigned mcs, unsigned nprb);
	int GetTbSizeFromMcsSymbols (unsigned mcs, unsigned nsym);  // for TDMA
	std::vector<int> CreateCqiFeedbacks (const SpectrumValue& sinr, uint8_t rbgSize);
	std::vector<int> CreateCqiFeedbacksTdma (const SpectrumValue& sinr, uint8_t numSym);
	int CreateCqiFeedbackWbTdma (const SpectrumValue& sinr, uint8_t numSym, uint32_t tbs, int &mcsWb);
	int GetCqiFromSpectralEfficiency (double s);

	static const unsigned int m_crcLen=24;

private:
	  double m_ber;
	  AmcModel m_amcModel;

	  Ptr<MmWavePhyMacCommon> m_phyMacConfig;
		Ptr<SpectrumModel> m_lteRbModel;
};

} // end namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_AMC_H_ */
