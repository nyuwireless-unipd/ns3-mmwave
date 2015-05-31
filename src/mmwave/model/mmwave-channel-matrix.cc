/*
 * mmWaveChannelMatrix.cc
 *
 *  Created on: 2014年11月25日
 *      Author: menglei
 */

#include "mmwave-channel-matrix.h"
#include <ns3/log.h>
#include <ns3/math.h>
#include <ns3/simulator.h>
#include <ns3/mmwave-phy.h>
#include <ns3/mmwave-net-device.h>
#include <ns3/node.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/antenna-array-model.h>
#include <ns3/mmwave-ue-phy.h>
#include <ns3/mmwave-enb-phy.h>

namespace ns3{

NS_LOG_COMPONENT_DEFINE ("mmWaveChannelMatrix");

NS_OBJECT_ENSURE_REGISTERED (mmWaveChannelMatrix);

static const double PowerSpread[7]  = {0.6598, 0.1466, 0.1100, 0.0733, 0.0051, 0.0029, 0.0022};
static const double DelaySpread[7]  = {0, 3e-9, 7e-9, 9e-9, 12e-9, 19e-9, 41e-9};
static const double DopplerShift[7] = {0.4, 0.6, 0.3, 0.8, 0.4, 0.9, 0.5};
static const double PathAngle[7]    = {0, 0.1, -0.11, 0.223, -0.33, 0.28, -0.44};

mmWaveChannelMatrix::mmWaveChannelMatrix ()
	:m_antennaSeperation(0.5)
{

}

TypeId
mmWaveChannelMatrix::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::mmWaveChannelMatrix")
  .SetParent<Object> ();
  return tid;
}

mmWaveChannelMatrix::~mmWaveChannelMatrix ()
{

}

void
mmWaveChannelMatrix::DoDispose ()
{
	NS_LOG_FUNCTION (this);
}

void
mmWaveChannelMatrix::ConnectDevices (Ptr<NetDevice> dev1, Ptr<NetDevice> dev2)
{
	key_t key = std::make_pair(dev1,dev2);

	std::map< key_t, int >::iterator iter = m_connectedPair.find(key);
	if (iter != m_connectedPair.end ())
	{
		m_connectedPair.erase (iter);
	}
	m_connectedPair.insert(std::make_pair(key,1));
}

Ptr<SpectrumValue>
mmWaveChannelMatrix::DoCalcRxPowerSpectralDensity (Ptr<const SpectrumValue> txPsd,
                                                   Ptr<const MobilityModel> a,
                                                   Ptr<const MobilityModel> b) const
{
	NS_LOG_FUNCTION (this);
	Ptr<SpectrumValue> rxPsd = Copy (txPsd);
	Ptr<AntennaArrayModel> txAntennaArray, rxAntennaArray;

	Ptr<NetDevice> txDevice = a->GetObject<Node> ()->GetDevice (0);
	Ptr<NetDevice> rxDevice = b->GetObject<Node> ()->GetDevice (0);
	Ptr<mmWaveEnbNetDevice> txEnb =
					DynamicCast<mmWaveEnbNetDevice> (txDevice);
	Ptr<mmWaveUeNetDevice> rxUe =
					DynamicCast<mmWaveUeNetDevice> (rxDevice);

	uint8_t txAntennaNum[2];
	uint8_t rxAntennaNum[2];

	if(txEnb!=0 && rxUe!=0)
	{
		NS_LOG_INFO ("this is downlink case");
		txAntennaNum[0] = sqrt (txEnb->GetAntennaNum ());
		txAntennaNum[1] = sqrt (txEnb->GetAntennaNum ());
		rxAntennaNum[0] = sqrt (rxUe->GetAntennaNum ());
		rxAntennaNum[1] = sqrt (rxUe->GetAntennaNum ());

		txAntennaArray = DynamicCast<AntennaArrayModel> (
					txEnb->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
		rxAntennaArray = DynamicCast<AntennaArrayModel> (
					rxUe->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());



	}
	else if (txEnb==0 && rxUe==0 )
	{
		NS_LOG_INFO ("this is uplink case");

		Ptr<mmWaveUeNetDevice> txUe =
						DynamicCast<mmWaveUeNetDevice> (txDevice);
		Ptr<mmWaveEnbNetDevice> rxEnb =
						DynamicCast<mmWaveEnbNetDevice> (rxDevice);

		txAntennaNum[0] = sqrt (txUe->GetAntennaNum ());
		txAntennaNum[1] = sqrt (txUe->GetAntennaNum ());
		rxAntennaNum[0] = sqrt (rxEnb->GetAntennaNum ());
		rxAntennaNum[1] = sqrt (rxEnb->GetAntennaNum ());

		txAntennaArray = DynamicCast<AntennaArrayModel> (
					txUe->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
		rxAntennaArray = DynamicCast<AntennaArrayModel> (
					rxEnb->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
	}
	else
	{
		NS_LOG_INFO ("enb to enb or ue to ue transmission, skip beamforming");
		return rxPsd;
	}

	Angles txAngles (b->GetPosition (), a->GetPosition ());
	Angles rxAngles (a->GetPosition (), b->GetPosition ());

	/*make sure txAngles rxAngles exist, i.e., the position of tx and rx cannot be the same*/
	complex2DVector_t txSpatialMatrix = GenSpatialMatrix (txAngles,txAntennaNum);
	complex2DVector_t rxSpatialMatrix = GenSpatialMatrix (rxAngles,rxAntennaNum);


	/*
	Time time = Simulator::Now ();
	int frame = time.GetMilliSeconds ();
	int subframe = time.GetMicroSeconds ()/125%8;
	*/

	/*calculate antenna weights, better method should be implemented*/
	key_t key = std::make_pair(txDevice,rxDevice);
	std::map< key_t, int >::iterator it1 = m_connectedPair.find (key);
	if(it1 != m_connectedPair.end ())
	{
		complexVector_t txW = CalcBeamformingVector(txSpatialMatrix);
		complexVector_t rxW = CalcBeamformingVector(rxSpatialMatrix);
		txAntennaArray->SetBeamformingVector(txW);
		rxAntennaArray->SetBeamformingVector(rxW);
	}

	Ptr<mmWaveBeamFormingParams> bfParams = Create<mmWaveBeamFormingParams> ();
	bfParams->m_txW = txAntennaArray->GetBeamformingVector ();
	bfParams->m_rxW = rxAntennaArray->GetBeamformingVector ();
	bfParams->m_channelParams.m_txSpatialMatrix = txSpatialMatrix;
	bfParams->m_channelParams.m_rxSpatialMatrix = rxSpatialMatrix;

	Vector rxSpeed = b->GetVelocity();
	Vector txSpeed = a->GetVelocity();
	double relativeSpeed = (rxSpeed.x-txSpeed.x)
			+(rxSpeed.y-txSpeed.y)+(rxSpeed.z-txSpeed.z);
	doubleVector_t gain = GetBfGain(bfParams, relativeSpeed);
	Ptr<SpectrumValue> bfPsd = GetPsd(txPsd, gain);

	/*NS_LOG_UNCOND ("TxAngle("<<txAngles.phi*180/M_PI<<") RxAngle("<<rxAngles.phi*180/M_PI
			<<") Speed["<<relativeSpeed<<"] Gain("<<10*log10(gain.at (3))<<"dB)"); */
	return bfPsd;
}

complexVector_t
mmWaveChannelMatrix::CalcBeamformingVector(complex2DVector_t spatialMatrix) const
{
	/*
	 *    use power algorithm to calculate beamforming vector
	 *
	 * */
	complexVector_t antennaWeights;
	uint16_t antennaNum = spatialMatrix.at (0).size ();
	for (int i = 0; i< antennaNum; i++)
	{
		antennaWeights.push_back(spatialMatrix.at (0).at (i)/sqrt(antennaNum));
	}

	for(int iter = 0; iter<10; iter++)
	{
		complexVector_t antennaWeights_New;

		for(int pathIndex = 0; pathIndex<spatialMatrix.size (); pathIndex++)
		{
			std::complex<double> sum;
			for (int i = 0; i< antennaNum; i++)
			{
				sum += std::conj(spatialMatrix.at (pathIndex).at (i))*antennaWeights.at (i);
			}

			for (int i = 0; i< antennaNum; i++)
			{
				if(pathIndex ==0)
				{
					antennaWeights_New.push_back(PowerSpread[pathIndex]*spatialMatrix.at (pathIndex).at (i)*sum);
				}
				else
				{
					antennaWeights_New.at (i) += PowerSpread[pathIndex]*spatialMatrix.at (pathIndex).at (i)*sum;
				}
			}
		}
		//normalize antennaWeights;
		double weightSum = 0;
		for (int i = 0; i< antennaNum; i++)
		{
			weightSum += pow (std::abs(antennaWeights_New. at(i)),2);
		}
		for (int i = 0; i< antennaNum; i++)
		{
			antennaWeights_New. at(i) = antennaWeights_New. at(i)/sqrt(weightSum);
		}
		antennaWeights = antennaWeights_New;
	}
	return antennaWeights;
}


complex2DVector_t
mmWaveChannelMatrix::GenSpatialMatrix (Angles angle, uint8_t* antennaNum) const
{
	complex2DVector_t spatialMatrix;
	for(int pathIndex = 0; pathIndex < 7; pathIndex++)
	{
		complexVector_t singlePath = GenSinglePath (angle.phi+PathAngle[pathIndex], angle.theta, antennaNum);
		spatialMatrix.push_back(singlePath);
	}
	return spatialMatrix;
}


complexVector_t
mmWaveChannelMatrix::GenSinglePath (double hAngle, double vAngle, uint8_t* antennaNum) const
{
	NS_LOG_FUNCTION (this);
	complexVector_t singlePath;
	uint16_t vSize = antennaNum[0];
	uint16_t hSize = antennaNum[1];

	for (int vIndex = 0; vIndex < vSize; vIndex++)
	{
		for (int hIndex =0; hIndex < hSize; hIndex++)
		{
			double w = (-2)*M_PI*hIndex*m_antennaSeperation*cos(hAngle)
										+ (-2)*M_PI*vIndex*m_antennaSeperation*cos(vAngle);
			singlePath.push_back (std::complex<double> (cos (w), sin (w)));
		}
	}
	return singlePath;
}

doubleVector_t
mmWaveChannelMatrix::GetBfGain (Ptr<mmWaveBeamFormingParams> bfParams, double speed) const
{
	NS_LOG_FUNCTION (this);
	doubleVector_t gain;
	NS_ASSERT(bfParams->m_channelParams.m_rxSpatialMatrix.size () == bfParams->m_channelParams.m_txSpatialMatrix.size ());
	uint16_t pathNum = bfParams->m_channelParams.m_txSpatialMatrix.size ();
	for (int chunkIndex = 0; chunkIndex < 72; chunkIndex++)
	{
		std::complex<double> sum;
		for (int pathIndex = 0; pathIndex < pathNum; pathIndex++)
		{
			/*
			 * should not define carrier frequency and bandwidth here*/
			double f = 27.5e9;
			double bw = 13.9e6;
			Time time = Simulator::Now ();
			double t = time.GetSeconds ();

			std::complex<double> delay (cos (2*M_PI*(f+bw*chunkIndex)*DelaySpread[pathIndex]), sin (2*M_PI*(f+bw*chunkIndex)*DelaySpread[pathIndex]));
			std::complex<double> doppler (cos (2*M_PI*t*speed*DopplerShift[pathIndex]), sin (2*M_PI*t*speed*DopplerShift[pathIndex]));
			std::complex<double> smallScaleFading = sqrt(PowerSpread[pathIndex])*delay*doppler;

			NS_LOG_INFO (smallScaleFading);

			if(bfParams->m_txW.empty ()||bfParams->m_rxW.empty ())
			{
				/*antenna weights is empty, siso*/
				sum = sum + smallScaleFading;
			}
			else
			{
				/* beam forming*/
				std::complex<double> txSum, rxSum;
				for (int i = 0; i < bfParams->m_channelParams.m_txSpatialMatrix.at (pathIndex).size (); i++)
				{
					txSum += std::conj(bfParams->m_channelParams.m_txSpatialMatrix.at (pathIndex).at (i))*bfParams->m_txW.at (i);
				}
				for (int i = 0; i < bfParams->m_channelParams.m_rxSpatialMatrix.at (pathIndex).size (); i++)
				{
					rxSum += bfParams->m_channelParams.m_rxSpatialMatrix.at (pathIndex). at (i)*std::conj(bfParams->m_rxW.at (i));
				}
				sum = sum + smallScaleFading*txSum*rxSum;
			}
		}
		gain.push_back(std::pow(std::abs(sum),2));
	}

	return gain;

}

Ptr<SpectrumValue>
mmWaveChannelMatrix::GetPsd (Ptr<const SpectrumValue> rxPsd, doubleVector_t gain) const
{
	Ptr<SpectrumValue> bfPsd = Copy<SpectrumValue> (rxPsd);
	Values::iterator vit = bfPsd->ValuesBegin ();
	uint32_t subChannel = 0;
	while (vit != bfPsd->ValuesEnd ())
	{
		if (*vit != 0.0)
		{
	        *vit *= gain.at (subChannel);
		}
		vit++;
		subChannel++;
	}
	return bfPsd;
}


}// namespace ns3
