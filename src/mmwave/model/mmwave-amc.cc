/*
 * mmwave-amc.cc
 *
 *  Created on: Feb 1, 2015
 *      Author: macair
 */

#include "mmwave-amc.h"
#include <ns3/log.h>
#include <ns3/double.h>
#include <ns3/math.h>
#include "ns3/enum.h"
#include "mmwave-mi-error-model.h"

#define CRC 24

NS_LOG_COMPONENT_DEFINE ("mmWaveAmc");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (mmWaveAmc);

static const double SpectralEfficiencyForCqi[16] = {
	0.0, // out of range
	0.15, 0.23, 0.38, 0.6, 0.88, 1.18,
	1.48, 1.91, 2.41,
	2.73, 3.32, 3.9, 4.52, 5.12, 5.55
};

static const double SpectralEfficiencyForMcs[32] = {
	0.15, 0.19, 0.23, 0.31, 0.38, 0.49, 0.6, 0.74, 0.88, 1.03, 1.18,
	1.33, 1.48, 1.7, 1.91, 2.16, 2.41, 2.57,
	2.73, 3.03, 3.32, 3.61, 3.9, 4.21, 4.52, 4.82, 5.12, 5.33, 5.55,
	0, 0, 0
};

mmWaveAmc::mmWaveAmc ()
{
	NS_LOG_ERROR ("This construcor should not be invoked");
}

mmWaveAmc::mmWaveAmc (Ptr<MmWavePhyMacCommon> ConfigParams)
: m_ConfigParams (ConfigParams)
{
	NS_LOG_INFO ("Initialze AMC module");
}

mmWaveAmc::~mmWaveAmc ()
{

}

TypeId
mmWaveAmc::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::mmWaveAmc")
	.SetParent<Object> ()
	.AddConstructor<mmWaveAmc> ()
	.AddAttribute ("Ber",
				 "The requested BER in assigning MCS (default is 0.00005).",
				 DoubleValue (0.00005),
				 MakeDoubleAccessor (&mmWaveAmc::m_ber),
				 MakeDoubleChecker<double> ())
	.AddAttribute ("AmcModel",
				"AMC model used to assign CQI",
				 EnumValue (mmWaveAmc::MiErrorModel),
				 MakeEnumAccessor (&mmWaveAmc::m_amcModel),
				 MakeEnumChecker (mmWaveAmc::MiErrorModel, "Vienna",
								  mmWaveAmc::PiroEW2010, "PiroEW2010"))
	;
	return tid;
}

int
mmWaveAmc::GetMcsFromCqi (int cqi)
{
  NS_LOG_FUNCTION (cqi);
  NS_ASSERT_MSG (cqi >= 0 && cqi <= 15, "CQI must be in [0..15] = " << cqi);
  double spectralEfficiency = SpectralEfficiencyForCqi[cqi];
  int mcs = 0;
  while ((mcs < 28) && (SpectralEfficiencyForMcs[mcs + 1] <= spectralEfficiency))
    {
      ++mcs;
    }
  NS_LOG_LOGIC ("mcs = " << mcs);
  return mcs;
}

int
mmWaveAmc::GetTbSizeFromMcs (int mcs, int nprb)
{
	NS_LOG_FUNCTION (mcs);
	NS_ASSERT_MSG (mcs < 29, "MCS=" << mcs);
	//NS_ASSERT_MSG (nprb < 5, "NPRB=" << nprb);
	int rscElement = m_ConfigParams->GetNumSCperChunk ()*m_ConfigParams->GetNumChunkPerRb ()*nprb*(m_ConfigParams->GetSymbPerSlot () - m_ConfigParams->GetNumReferenceSymbols ());
	double s = SpectralEfficiencyForMcs[mcs];

	int tbSize = rscElement*s - CRC;
	uint16_t cbSize = 6144;  //max size of a code-block (including CRC)
    if (tbSize > cbSize)
    {
        int C = ceil ((double)tbSize / ((double)(6144)));
    	tbSize -= C*CRC; //subtract bits of CRC used in code-blocks.
    }
   	return tbSize;

}

std::vector<int>
mmWaveAmc::CreateCqiFeedbacks (const SpectrumValue& sinr, uint8_t rbgSize)
{
	NS_LOG_FUNCTION (this);

	std::vector<int> cqi;
	Values::const_iterator it;
	if (m_amcModel == PiroEW2010)
	{
		//use PiroEW2010 model
		for (it = sinr.ConstValuesBegin (); it != sinr.ConstValuesEnd (); it++)
		{
			double sinr_ = (*it);
			if (sinr_ == 0.0)
			{
				cqi.push_back (-1); // SINR == 0 (linear units) means no signal in this RB
			}
			else
			{
			/*
			* Compute the spectral efficiency from the SINR
			*                                        SINR
			* spectralEfficiency = log2 (1 + -------------------- )
			*                                    -ln(5*BER)/1.5
			* NB: SINR must be expressed in linear units
			*/

			double s = log2 ( 1 + ( sinr_ / ( (-std::log (5.0 * m_ber )) / 1.5) ));

			int cqi_ = GetCqiFromSpectralEfficiency (s);

			NS_LOG_LOGIC (" PRB =" << cqi.size ()
								<< ", sinr = " << sinr_
								<< " (=" << 10 * std::log10 (sinr_) << " dB)"
								<< ", spectral efficiency =" << s
								<< ", CQI = " << cqi_ << ", BER = " << m_ber);

			cqi.push_back (cqi_);
			}
		}
	}
	else if (m_amcModel == MiErrorModel)
	{
		std::vector <int> rbgMap;
		int rbId = 0;
		for (it = sinr.ConstValuesBegin (); it != sinr.ConstValuesEnd (); it++)
		{
			rbgMap.push_back (rbId++);
			if ((rbId % rbgSize == 0)||((it+1)==sinr.ConstValuesEnd ()))
			{
				uint8_t mcs = 0;
				TbStats_t tbStats;
				while (mcs <= 28)
				{
					HarqProcessInfoList_t harqInfoList;
					tbStats = MmWaveMiErrorModel::GetTbDecodificationStats (sinr, rbgMap, (uint16_t)GetTbSizeFromMcs (mcs, rbgSize/18) / 8, mcs, harqInfoList);
					if (tbStats.tbler > 0.1)
					{
						break;
					}
					mcs++;

				}
				if (mcs > 0)
				{
					mcs--;
				}
				NS_LOG_DEBUG (this << "\t RBG " << rbId << " MCS " << (uint16_t)mcs << " TBLER " << tbStats.tbler);
				int rbgCqi = 0;
				if ((tbStats.tbler > 0.1)&&(mcs==0))
				{
					rbgCqi = 0;
				}
				else if (mcs == 28)
				{
					rbgCqi = 15; // all MCSs can guarantee the 10 % of BER
				}
				else
				{
					double s = SpectralEfficiencyForMcs[mcs];
					rbgCqi = 0;
					while ((rbgCqi < 15) && (SpectralEfficiencyForCqi[rbgCqi + 1] < s))
					{
						++rbgCqi;
					}
				}
				NS_LOG_DEBUG (this << "\t MCS " << (uint16_t)mcs << "-> CQI " << rbgCqi);
				// fill the cqi vector (per RB basis)
				for (uint8_t j = 0; j < rbgSize; j++)
				{
					cqi.push_back (rbgCqi);
				}
				rbgMap.clear ();
			}

		}
	}
	return cqi;
}

int
mmWaveAmc::GetCqiFromSpectralEfficiency (double s)
{
	NS_LOG_FUNCTION (s);
	NS_ASSERT_MSG (s >= 0.0, "negative spectral efficiency = " << s);
	int cqi = 0;
	while ((cqi < 15) && (SpectralEfficiencyForCqi[cqi + 1] < s))
	{
		++cqi;
	}
	NS_LOG_LOGIC ("cqi = " << cqi);
	return cqi;
}

}

