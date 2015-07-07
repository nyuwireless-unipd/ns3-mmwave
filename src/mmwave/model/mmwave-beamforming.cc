/*
 * mmWaveBeamforming.cc
 *
 *  Created on: 2014年11月25日
 *      Author: menglei
 */

#include "mmwave-beamforming.h"

#include <ns3/log.h>
#include <fstream>
#include <ns3/simulator.h>
#include <ns3/random-variable-stream.h>
#include <ns3/abort.h>
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mmwave-ue-phy.h>
#include <ns3/antenna-array-model.h>
#include <ns3/node.h>
#include <algorithm>
#include <ns3/double.h>

namespace ns3{

NS_LOG_COMPONENT_DEFINE ("mmWaveBeamforming");

NS_OBJECT_ENSURE_REGISTERED (mmWaveBeamforming);

// number of channel matrix instance in beamforming files
// period of updating channel matrix
static const double g_longTermUpdatePeriod = 0.099999;
static const uint32_t g_numInstance = 100;

complex2DVector_t g_enbAntennaInstance; //100 instance of txW
complex2DVector_t g_ueAntennaInstance; //100 instance of rxW
complex3DVector_t g_enbSpatialInstance; //this stores 100 instance of txE
complex3DVector_t g_ueSpatialInstance; //this stores 100 instance of rxE
double2DVector_t g_smallScaleFadingInstance;    //this stores 100 instance of sigma vector

/*
 * The delay spread and Doppler shift is not based on measurement data at this time
 */
static const double DelaySpread[20]  = {0, 3e-9, 4e-9, 5e-9, 5e-9, 6e-9, 7e-9, 7e-9, 7e-9, 17e-9,
			18e-9, 20e-9, 23e-9, 24e-9, 26e-9, 38e-9, 40e-9, 42e-9, 45e-9, 50e-9};

static const double DopplerShift[20] = {0.73, 0.78, 0.68, 0.71, 0.79, 0.69, 0.66, 0.70, 0.69, 0.44,
		0.48, 0.43, 0.42, 0.47,0.50, 0.53, 0.52, 0.49, 0.55, 0.52};



mmWaveBeamforming::mmWaveBeamforming (uint32_t enbAntenna, uint32_t ueAntenna)
	:m_pathNum (20),
	m_enbAntennaSize(enbAntenna),
	m_ueAntennaSize(ueAntenna)
{
	if (g_smallScaleFadingInstance.empty ())
	LoadFile();
}


TypeId
mmWaveBeamforming::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::mmWaveBeamforming")
		.SetParent<Object> ()
		.AddAttribute ("ChunkWidth",
				   "Width of each chunk in Hz",
				   DoubleValue (13.889e6),
				   MakeDoubleAccessor (&mmWaveBeamforming::m_subbandWidth),
				   MakeDoubleChecker<double> ())
		.AddAttribute ("CentreFreq",
				   "The center frequency in Hz",
				   DoubleValue (28e9),
				   MakeDoubleAccessor (&mmWaveBeamforming::m_centreFrequency),
				   MakeDoubleChecker<double> ())
		.AddAttribute ("NumResourceBlocks",
				   "Number of resource blocks in one slot",
				   UintegerValue (4),
				   MakeUintegerAccessor (&mmWaveBeamforming::m_numResourceBlocks),
				   MakeUintegerChecker<uint32_t> ())
		.AddAttribute ("NumSubbandPerRB",
			       "Number of sub-bands in one resource block",
				   UintegerValue (18),
				   MakeUintegerAccessor (&mmWaveBeamforming::m_numSubbbandPerRB),
				   MakeUintegerChecker<uint32_t> ())
	;
  	return tid;
}

mmWaveBeamforming::~mmWaveBeamforming ()
{

}

void
mmWaveBeamforming::DoDispose ()
{
	NS_LOG_FUNCTION (this);
}

std::complex<double>
mmWaveBeamforming::parseComplex (std::string strCmplx)
{
    double re = 0.00;
    double im = 0.00;
    size_t findj = 0;
    std::complex<double> out_complex;

    findj = strCmplx.find("i");
    if( findj == std::string::npos )
    {
        im = -1.00;
    }
    else
    {
        strCmplx[findj] = '\0';
    }
    if( ( strCmplx.find("+",1) == std::string::npos && strCmplx.find("-",1) == std::string::npos ) && im != -1 )
    {
        /* No real value */
        re = -1.00;
    }
    std::stringstream stream( strCmplx );
    if( re != -1.00 )
    {
        stream>>re;
    }
    else
    {
        re = 0;
    }
    if( im != -1 )
    {
        stream>>im;
    }
    else
    {
        im = 0.00;
    }
    //  std::cout<<" ---  "<<re<<"  "<<im<<std::endl;
    out_complex = std::complex<double>(re,im);
    return out_complex;
}

void
mmWaveBeamforming::LoadFile()
{
	LoadSmallScaleFading ();
	LoadEnbAntenna ();
	LoadUeAntenna ();
	LoadEnbSpatialSignature ();
	LoadUeSpatialSignature ();
}


void
mmWaveBeamforming::LoadSmallScaleFading ()
{
	std::string filename = "src/mmwave/model/BeamFormingMatrix/SmallScaleFading.txt";
	NS_LOG_FUNCTION (this << "Loading SmallScaleFading file " << filename);
	std::ifstream singlefile;
	singlefile.open (filename.c_str (), std::ifstream::in);

	NS_LOG_INFO (this << " File: " << filename);
	NS_ASSERT_MSG(singlefile.good (), " SmallScaleFading file not found");
    std::string line;
    std::string token;
    while( std::getline(singlefile, line) ) //Parse each line of the file
    {
    	doubleVector_t path;
        std::istringstream stream(line);
        while( getline(stream,token,',') ) //Parse each comma separated string in a line
        {
            double sigma = 0.00;
            std::stringstream stream( token );
            stream>>sigma;
        	path.push_back(sigma);
		}
        g_smallScaleFadingInstance.push_back (path);
	}
	NS_LOG_INFO ("SmallScaleFading[instance:"<<g_smallScaleFadingInstance.size()<<"][path:"<<g_smallScaleFadingInstance[0].size()<<"]");
}

void
mmWaveBeamforming::LoadEnbAntenna ()
{
	std::string filename = "src/mmwave/model/BeamFormingMatrix/TxAntenna.txt";
	NS_LOG_FUNCTION (this << "Loading TxAntenna file " << filename);
	std::ifstream singlefile;
	std::complex<double> complexVar;
	singlefile.open (filename.c_str (), std::ifstream::in);

	NS_LOG_INFO (this << " File: " << filename);
	NS_ASSERT_MSG(singlefile.good (), " TxAntenna file not found");
    std::string line;
    std::string token;
    while( std::getline(singlefile, line) ) //Parse each line of the file
    {
    	complexVector_t txAntenna;
        std::istringstream stream(line);
        while( getline(stream,token,',') ) //Parse each comma separated string in a line
        {
        	complexVar = parseComplex(token);
		    txAntenna.push_back(complexVar);
		}
		g_enbAntennaInstance.push_back(txAntenna);
	}
    NS_LOG_INFO ("TxAntenna[instance:"<<g_enbAntennaInstance.size()<<"][antennaSize:"<<g_enbAntennaInstance[0].size()<<"]");
}


void
mmWaveBeamforming::LoadUeAntenna ()
{
	std::string filename = "src/mmwave/model/BeamFormingMatrix/RxAntenna.txt";
	NS_LOG_FUNCTION (this << "Loading RxAntenna file " << filename);
	std::ifstream singlefile;
	std::complex<double> complexVar;
	singlefile.open (filename.c_str (), std::ifstream::in);

	NS_LOG_INFO (this << " File: " << filename);
	NS_ASSERT_MSG(singlefile.good (), " RxAntenna file not found");

    std::string line;
    std::string token;
    while( std::getline(singlefile, line) ) //Parse each line of the file
    {
    	complexVector_t rxAntenna;
		std::istringstream stream(line);
		while( getline(stream,token,',') ) //Parse each comma separated string in a line
		{
			complexVar = parseComplex(token);
		    rxAntenna.push_back(complexVar);
		}
		g_ueAntennaInstance.push_back(rxAntenna);
	}
    NS_LOG_INFO ("RxAntenna[instance:"<<g_ueAntennaInstance.size()<<"][antennaSize:"<<g_ueAntennaInstance[0].size()<<"]");
}

void
mmWaveBeamforming::LoadEnbSpatialSignature ()
{
	std::string filename = "src/mmwave/model/BeamFormingMatrix/TxSpatialSigniture.txt";
	NS_LOG_FUNCTION (this << "Loading TxspatialSigniture file " << filename);
	std::ifstream singlefile;
	std::string line;
	std::string token;

	uint16_t counter = 1;
	std::complex<double> complexVar;
	complex2DVector_t txSpatialMatrix;
	singlefile.open (filename.c_str (), std::ifstream::in);

	NS_ASSERT_MSG (singlefile.good (), "TxSpatialSigniture file not found");

    while( std::getline(singlefile, line) ) //Parse each line of the file
    {
    	complexVector_t txSpatialElement;
		std::istringstream stream(line);
		while( getline(stream,token,',') ) //Parse each comma separated string in a line
		{
			complexVar = parseComplex(token);
			txSpatialElement.push_back(complexVar);
		}
		txSpatialMatrix.push_back(txSpatialElement);
		if(counter % m_pathNum ==0 )
		{
			g_enbSpatialInstance.push_back(txSpatialMatrix);
			txSpatialMatrix.clear();
		}
	    counter++;
    }
    NS_LOG_INFO ("TxspatialSigniture[instance:"<<g_enbSpatialInstance.size()<<"][path:"<<g_enbSpatialInstance[0].size()<<"][antennaSize:"<<g_enbSpatialInstance[0][0].size()<<"]");
}

void
mmWaveBeamforming::LoadUeSpatialSignature ()
{
	std::string strFilename = "src/mmwave/model/BeamFormingMatrix/RxSpatialSigniture.txt";
	NS_LOG_FUNCTION (this << "Loading RxspatialSigniture file " << strFilename);
	std::ifstream singlefile;
	std::complex<double> complexVar;
	complex2DVector_t rxSpatialMatrix;
	singlefile.open (strFilename.c_str (), std::ifstream::in);

	NS_LOG_INFO (this << " File: " << strFilename);
	NS_ASSERT_MSG (singlefile.good (), " RxSpatialSigniture file not found");

	std::string line;
	std::string token;
	int counter = 1;
	while (std::getline(singlefile, line) ) //Parse each line of the file
	{
		 complexVector_t rxSpatialElement;
	     std::istringstream stream(line);
	     while (getline(stream,token,',') ) //Parse each comma separated string in a line
	     {
	    	 complexVar = parseComplex (token);
	    	 rxSpatialElement.push_back (complexVar);
	     }
	     rxSpatialMatrix.push_back (rxSpatialElement);
	     if (counter % m_pathNum == 0)
	     {
		   	 g_ueSpatialInstance.push_back (rxSpatialMatrix);
		   	 rxSpatialMatrix.clear ();
		 }
	     counter++;
	}
	NS_LOG_INFO ("RxspatialSigniture[instance:"<<g_ueSpatialInstance.size()<<"][path:"<<g_ueSpatialInstance[0].size()<<"][antennaSize:"<<g_ueSpatialInstance[0][0].size()<<"]");
}


void
mmWaveBeamforming::Initial(NetDeviceContainer ueDevices, NetDeviceContainer enbDevices)
{
	for (NetDeviceContainer::Iterator i = ueDevices.Begin(); i != ueDevices.End(); i++)
	{
		for (NetDeviceContainer::Iterator j = enbDevices.Begin(); j != enbDevices.End(); j++)
		{
			SetChannelMatrix (*i,*j);
		}

	}

	Simulator::Schedule (Seconds (g_longTermUpdatePeriod), &mmWaveBeamforming::Initial,this,ueDevices,enbDevices);
}


void
mmWaveBeamforming::SetChannelMatrix (Ptr<NetDevice> ueDevice, Ptr<NetDevice> enbDevice)
{
	key_t key = std::make_pair(ueDevice,enbDevice);

	Ptr<UniformRandomVariable> uniform = CreateObject<UniformRandomVariable> ();
	std::vector<int>::iterator it;
	//uniform->SetAntithetic(true);
	int randomInstance = uniform->GetValue (0, g_numInstance-1);

	Ptr<BeamformingParams> bfParams = Create<BeamformingParams> ();
	bfParams->m_enbW = g_enbAntennaInstance.at (randomInstance);
	bfParams->m_ueW = g_ueAntennaInstance.at (randomInstance);
	bfParams->m_channelMatrix.m_enbSpatialMatrix = g_enbSpatialInstance.at (randomInstance);
	bfParams->m_channelMatrix.m_ueSpatialMatrix = g_ueSpatialInstance.at (randomInstance);
	bfParams->m_channelMatrix.m_powerFraction = g_smallScaleFadingInstance.at (randomInstance);
	bfParams->m_beam = GetLongTermFading (bfParams);
	std::map< key_t, Ptr<BeamformingParams> >::iterator iter = m_channelMatrixMap.find(key);
	if (iter != m_channelMatrixMap.end ())
	{
		m_channelMatrixMap.erase (iter);
	}
	m_channelMatrixMap.insert(std::make_pair(key,bfParams));
	//update channel matrix periodically
	//Simulator::Schedule (Seconds (g_longTermUpdatePeriod), &mmWaveBeamforming::SetChannelMatrix,this,ueDevice,enbDevice);

	Ptr<mmWaveUeNetDevice> UeDev =
					DynamicCast<mmWaveUeNetDevice> (ueDevice);
	if (UeDev->GetTargetEnb ())
	{
		Ptr<NetDevice> targetBs = UeDev->GetTargetEnb ();
		SetBeamformingVector (ueDevice, targetBs);
	}
}

void
mmWaveBeamforming::SetBeamformingVector (Ptr<NetDevice> ueDevice, Ptr<NetDevice> enbDevice)
{
	key_t key = std::make_pair(ueDevice,enbDevice);
	std::map< key_t, Ptr<BeamformingParams> >::iterator it = m_channelMatrixMap.find(key);
	NS_ASSERT_MSG (it != m_channelMatrixMap.end (), "could not find");
	Ptr<BeamformingParams> bfParams = it->second;
	Ptr<mmWaveEnbNetDevice> EnbDev =
				DynamicCast<mmWaveEnbNetDevice> (enbDevice);
	Ptr<mmWaveUeNetDevice> UeDev =
				DynamicCast<mmWaveUeNetDevice> (ueDevice);

	Ptr<AntennaArrayModel> ueAntennaArray = DynamicCast<AntennaArrayModel> (
			UeDev->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
	Ptr<AntennaArrayModel> enbAntennaArray = DynamicCast<AntennaArrayModel> (
			EnbDev->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
	ueAntennaArray->SetBeamformingVector (bfParams->m_ueW);
	enbAntennaArray->SetBeamformingVector (bfParams->m_enbW, ueDevice);
	//Simulator::Schedule (Seconds (g_longTermUpdatePeriod), &mmWaveBeamforming::SetBeamformingVector,this,ueDevice,enbDevice);
}

complexVector_t
mmWaveBeamforming::GetLongTermFading (Ptr<BeamformingParams> bfParams) const
{
	complexVector_t longTerm;
	for (int pathIndex = 0; pathIndex < m_pathNum; pathIndex++)
	{
		std::complex<double> txsum (0,0);
		for (int txAntennaIndex = 0; txAntennaIndex < m_enbAntennaSize; txAntennaIndex++)
		{
			txsum = txsum +
					bfParams->m_enbW.at (txAntennaIndex)*
					bfParams->m_channelMatrix.m_enbSpatialMatrix.at (pathIndex).at (txAntennaIndex);
		}

		std::complex<double> rxsum (0,0);
		for (int rxAntennaIndex = 0; rxAntennaIndex < m_ueAntennaSize; rxAntennaIndex++)
		{
			rxsum = rxsum +
					bfParams->m_ueW.at (rxAntennaIndex)*
					bfParams->m_channelMatrix.m_ueSpatialMatrix.at (pathIndex).at (rxAntennaIndex);
		}
		NS_LOG_INFO ("rxsum="<<rxsum.real ()<<" "<<rxsum.imag ());
		longTerm.push_back (txsum*rxsum);
	}
	return longTerm;
}

Ptr<SpectrumValue>
mmWaveBeamforming::GetChannelGainVector (Ptr<const SpectrumValue> txPsd, Ptr<BeamformingParams> bfParams, double speed) const
{
	NS_LOG_FUNCTION (this);
	Ptr<SpectrumValue> tempPsd = Copy<SpectrumValue> (txPsd);

	Values::iterator vit = tempPsd->ValuesBegin ();
	uint16_t iSubband = 0;
	while (vit != tempPsd->ValuesEnd ())
	{
		std::complex<double> subsbandGain (0.0,0.0);
		if ((*vit) != 0.00)
		{
			double fsb = m_centreFrequency - GetSystemBandwidth ()/2 + m_subbandWidth*iSubband ;
			for (unsigned int pathIndex = 0; pathIndex < m_pathNum; pathIndex++)
			{
				double sigma = bfParams->m_channelMatrix.m_powerFraction.at (pathIndex);
				Time time = Simulator::Now ();
				double t = time.GetSeconds ();

				std::complex<double> delay (cos (2*M_PI*fsb*DelaySpread[pathIndex]), sin (2*M_PI*fsb*DelaySpread[pathIndex]));
				std::complex<double> doppler (cos (2*M_PI*t*speed*DopplerShift[pathIndex]), sin (2*M_PI*t*speed*DopplerShift[pathIndex]));
				std::complex<double> smallScaleFading = sqrt(2)*sigma*delay/doppler;
				subsbandGain = subsbandGain + bfParams->m_beam.at (pathIndex)*smallScaleFading;
			}
			*vit = (*vit)*(norm (subsbandGain));
		}
		vit++;
		iSubband++;
	}
	return tempPsd;

}

Ptr<SpectrumValue>
mmWaveBeamforming::DoCalcRxPowerSpectralDensity (Ptr<const SpectrumValue> txPsd,
												Ptr<const MobilityModel> a,
												Ptr<const MobilityModel> b) const
{
	Ptr<NetDevice> enbDevice, ueDevice;

	Ptr<NetDevice> txDevice = a->GetObject<Node> ()->GetDevice (0);
	Ptr<NetDevice> rxDevice = b->GetObject<Node> ()->GetDevice (0);
	Ptr<SpectrumValue> rxPsd = Copy (txPsd);
	key_t dlkey = std::make_pair(rxDevice,txDevice);
	key_t ulkey = std::make_pair(txDevice,rxDevice);

	std::map< key_t, Ptr<BeamformingParams> >::iterator it;
	if(m_channelMatrixMap.find(dlkey) != m_channelMatrixMap.end ())
	{
		// this is downlink case
		enbDevice = txDevice;
		ueDevice = rxDevice;
		it = m_channelMatrixMap.find(dlkey);
	}
	else if (m_channelMatrixMap.find(ulkey) != m_channelMatrixMap.end ())
	{
		// this is uplink case
		ueDevice = txDevice;
		enbDevice = rxDevice;
		it = m_channelMatrixMap.find(ulkey);
	}
	else
	{
		// enb to enb or ue to ue transmission, set to 0. Do no consider such scenarios.
		return 0;
	}

	Ptr<BeamformingParams> bfParams = it->second;

	Ptr<mmWaveUeNetDevice> UeDev =
				DynamicCast<mmWaveUeNetDevice> (ueDevice);
	Ptr<mmWaveEnbNetDevice> EnbDev =
				DynamicCast<mmWaveEnbNetDevice> (enbDevice);
	Ptr<AntennaArrayModel> ueAntennaArray = DynamicCast<AntennaArrayModel> (
			UeDev->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
	Ptr<AntennaArrayModel> enbAntennaArray = DynamicCast<AntennaArrayModel> (
			EnbDev->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ());
	complexVector_t ueW = ueAntennaArray->GetBeamformingVector();
	complexVector_t enbW = enbAntennaArray->GetBeamformingVector();

	if(!ueW.empty() && !enbW.empty())
	{
		bfParams->m_ueW = ueW;
		bfParams->m_enbW = enbW;
		bfParams->m_beam = GetLongTermFading (bfParams);
	}
	else
	{
		return rxPsd;
	}

	Vector rxSpeed = b->GetVelocity();
	Vector txSpeed = a->GetVelocity();
	double relativeSpeed = (rxSpeed.x-txSpeed.x)
			+(rxSpeed.y-txSpeed.y)+(rxSpeed.z-txSpeed.z);

	Ptr<SpectrumValue> bfPsd = GetChannelGainVector (rxPsd, bfParams,  relativeSpeed);
	return bfPsd;
}

double
mmWaveBeamforming::GetSystemBandwidth () const
{
	double bw = 0.00;
	bw = m_subbandWidth*m_numSubbbandPerRB*m_numResourceBlocks;
	return bw;
}

}// namespace ns3
