
#ifndef MMWAVE_CHANNEL_MATRIX_H_
#define MMWAVE_CHANNEL_MATRIX_H_


#include <ns3/spectrum-value.h>
#include <complex>
#include <ns3/spectrum-signal-parameters.h>
#include <ns3/mobility-model.h>
#include <ns3/spectrum-propagation-loss-model.h>
#include <ns3/net-device.h>
#include <map>
#include <ns3/angles.h>
#include <ns3/net-device-container.h>





namespace ns3{


typedef std::vector<double> doubleVector_t;
typedef std::vector< std::complex<double> > complexVector_t;
typedef std::vector<complexVector_t> complex2DVector_t;
typedef std::pair<Ptr<NetDevice>, Ptr<NetDevice> > key_t;


struct ChannelParams : public SimpleRefCount<ChannelParams>
{
	complex2DVector_t 	m_txSpatialMatrix; // tx side spatial matrix
	complex2DVector_t 	m_rxSpatialMatrix; // rx side spatial matrix
};

struct mmWaveBeamFormingParams : public SimpleRefCount<mmWaveBeamFormingParams>
{
	complexVector_t 		m_txW; // tx antenna weights
	complexVector_t 		m_rxW; // rx antenna weights
	Ptr<ChannelParams>  	m_channelParams;
};


class mmWaveChannelMatrix : public SpectrumPropagationLossModel
{
public:

	mmWaveChannelMatrix ();
	virtual ~mmWaveChannelMatrix ();

	static TypeId GetTypeId (void);
	void DoDispose ();
	void ConnectDevices (Ptr<NetDevice> dev1, Ptr<NetDevice> dev2);
	void Initial(NetDeviceContainer ueDevices, NetDeviceContainer enbDevices);


private:

	Ptr<SpectrumValue> DoCalcRxPowerSpectralDensity (Ptr<const SpectrumValue> txPsd,
														Ptr<const MobilityModel> a,
														Ptr<const MobilityModel> b) const;

	complex2DVector_t GenSpatialMatrix (Angles angle, uint8_t* antennaNum) const;
	complexVector_t GenSinglePath (double hAngle, double vAngle, uint8_t* antennaNum) const;
	doubleVector_t GetBfGain (Ptr<mmWaveBeamFormingParams> bfParams, double speed) const;
	Ptr<SpectrumValue> GetPsd (Ptr<const SpectrumValue> rxPsd, doubleVector_t gain) const;
	complexVector_t CalcBeamformingVector (complex2DVector_t SpatialMatrix) const;

	mutable std::map< key_t, int > m_connectedPair;
	mutable std::map< key_t, Ptr<ChannelParams> > m_channelMatrixMap;
	double m_antennaSeparation; //the ratio of the distance between 2 antennas over wave length
	double m_subBW;
	double m_centreF;
	uint32_t m_numRB;
	uint32_t m_numSBPerRB;

};



}  //namespace ns3


#endif /* MMWAVE_CHANNEL_MATRIX_H_ */
