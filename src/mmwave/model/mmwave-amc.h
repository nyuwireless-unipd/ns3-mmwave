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



#ifndef SRC_MMWAVE_MODEL_MMWAVE_AMC_H_
#define SRC_MMWAVE_MODEL_MMWAVE_AMC_H_
#include <ns3/object.h>
#include <ns3/spectrum-value.h>
#include <ns3/mmwave-phy-mac-common.h>

namespace ns3 {

namespace mmwave {

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
	int GetNumSymbolsFromTbsMcs (unsigned tbSize, unsigned mcs);
	std::vector<int> CreateCqiFeedbacks (const SpectrumValue& sinr, uint8_t rbgSize);
	std::vector<int> CreateCqiFeedbacksTdma (const SpectrumValue& sinr, uint8_t numSym);
	int CreateCqiFeedbackWbTdma (const SpectrumValue& sinr, uint8_t numSym, uint32_t tbs, int &mcsWb);
	int GetCqiFromSpectralEfficiency (double s);
	int GetMcsFromSpectralEfficiency (double s);

	static const unsigned int m_crcLen=24;

private:
	  double m_ber;
	  AmcModel m_amcModel;

	  Ptr<MmWavePhyMacCommon> m_phyMacConfig;
		Ptr<SpectrumModel> m_lteRbModel;
};

} // end namespace mmwave

} // end namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_AMC_H_ */
