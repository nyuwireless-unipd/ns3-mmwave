 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab. 
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
 *
 * Modified by: Michele Polese <michele.polese@gmail.com> 
 *                 Dual Connectivity and Handover functionalities
 */



#include <ns3/string.h>
#include <ns3/log.h>
#include <ns3/abort.h>
#include <ns3/pointer.h>
#include <iostream>
#include <string>
#include <sstream>
#include "mmwave-helper.h"
#include <ns3/abort.h>
#include <ns3/multi-model-spectrum-channel.h>
#include <ns3/uinteger.h>
#include <ns3/double.h>
#include <ns3/ipv4.h>
#include <ns3/mmwave-lte-rrc-protocol-real.h>
#include <ns3/epc-enb-application.h>
#include <ns3/epc-x2.h>

#include <ns3/friis-spectrum-propagation-loss.h>
#include <ns3/mmwave-rrc-protocol-ideal.h>
#include <ns3/lte-spectrum-phy.h>
#include <ns3/lte-chunk-processor.h>
#include <ns3/isotropic-antenna-model.h>
#include <ns3/mmwave-propagation-loss-model.h>
#include <ns3/mmwave-3gpp-buildings-propagation-loss-model.h>

namespace ns3 {

/* ... */
NS_LOG_COMPONENT_DEFINE ("MmWaveHelper");

NS_OBJECT_ENSURE_REGISTERED (MmWaveHelper);

MmWaveHelper::MmWaveHelper(void)
	:m_imsiCounter (0),
	 m_cellIdCounter (0),
	 m_noTxAntenna (64),
	 m_noRxAntenna (16),
	 m_harqEnabled (false),
	 m_rlcAmEnabled (false),
	 m_snrTest (false),
	 m_useIdealRrc (false)
{
	NS_LOG_FUNCTION(this);
 	m_channelFactory.SetTypeId (MultiModelSpectrumChannel::GetTypeId ());
	m_lteChannelFactory.SetTypeId (MultiModelSpectrumChannel::GetTypeId ());
	m_enbNetDeviceFactory.SetTypeId (MmWaveEnbNetDevice::GetTypeId ());
	m_lteEnbNetDeviceFactory.SetTypeId (LteEnbNetDevice::GetTypeId ());
	m_ueNetDeviceFactory.SetTypeId (MmWaveUeNetDevice::GetTypeId ());

	m_mcUeNetDeviceFactory.SetTypeId (McUeNetDevice::GetTypeId ());
	m_enbAntennaModelFactory.SetTypeId (AntennaArrayModel::GetTypeId ());
	m_ueAntennaModelFactory.SetTypeId (AntennaArrayModel::GetTypeId ());

	m_lteUeAntennaModelFactory.SetTypeId (IsotropicAntennaModel::GetTypeId ());
	m_lteEnbAntennaModelFactory.SetTypeId (IsotropicAntennaModel::GetTypeId ());
	// TODO add Set methods for LTE antenna
}

MmWaveHelper::~MmWaveHelper(void)
{
	NS_LOG_FUNCTION(this);
}

TypeId
MmWaveHelper::GetTypeId (void)
{
	static TypeId
	    tid =
	    TypeId ("ns3::MmWaveHelper")
	    .SetParent<Object> ()
	    .AddConstructor<MmWaveHelper> ()
		.AddAttribute ("PathlossModel",
					   "The type of path-loss model to be used. "
					   "The allowed values for this attributes are the type names "
					   "of any class inheriting from ns3::PropagationLossModel.",
					   StringValue ("ns3::MmWavePropagationLossModel"),
					   MakeStringAccessor (&MmWaveHelper::SetPathlossModelType),
					   MakeStringChecker ())
		.AddAttribute ("ChannelModel",
					   "The type of MIMO channel model to be used. "
					   "The allowed values for this attributes are the type names "
					   "of any class inheriting from ns3::SpectrumPropagationLossModel.",
					   StringValue ("ns3::MmWaveBeamforming"),
					   MakeStringAccessor (&MmWaveHelper::SetChannelModelType),
					   MakeStringChecker ())
		.AddAttribute ("Scheduler",
				      "The type of scheduler to be used for MmWave eNBs. "
				      "The allowed values for this attributes are the type names "
				      "of any class inheriting from ns3::MmWaveMacScheduler.",
				      StringValue ("ns3::MmWaveFlexTtiMacScheduler"),
				      MakeStringAccessor (&MmWaveHelper::SetSchedulerType,
				                          &MmWaveHelper::GetSchedulerType),
				      MakeStringChecker ())
	  .AddAttribute ("HarqEnabled",
					"Enable Hybrid ARQ",
					BooleanValue (true),
					MakeBooleanAccessor (&MmWaveHelper::m_harqEnabled),
					MakeBooleanChecker ())
		.AddAttribute ("RlcAmEnabled",
					"Enable RLC Acknowledged Mode",
					BooleanValue (false),
					MakeBooleanAccessor (&MmWaveHelper::m_rlcAmEnabled),
					MakeBooleanChecker ())
	    .AddAttribute ("LteScheduler",
	                   "The type of scheduler to be used for LTE eNBs. "
	                   "The allowed values for this attributes are the type names "
	                   "of any class inheriting from ns3::FfMacScheduler.",
	                   StringValue ("ns3::PfFfMacScheduler"),
	                   MakeStringAccessor (&MmWaveHelper::SetLteSchedulerType,
	                                       &MmWaveHelper::GetLteSchedulerType),
	                   MakeStringChecker ())
	    .AddAttribute ("LteFfrAlgorithm",
	                   "The type of FFR algorithm to be used for LTE eNBs. "
	                   "The allowed values for this attributes are the type names "
	                   "of any class inheriting from ns3::LteFfrAlgorithm.",
	                   StringValue ("ns3::LteFrNoOpAlgorithm"),
	                   MakeStringAccessor (&MmWaveHelper::SetLteFfrAlgorithmType,
	                                       &MmWaveHelper::GetLteFfrAlgorithmType),
	                   MakeStringChecker ())
	    .AddAttribute ("LteHandoverAlgorithm",
	                   "The type of handover algorithm to be used for LTE eNBs. "
	                   "The allowed values for this attributes are the type names "
	                   "of any class inheriting from ns3::LteHandoverAlgorithm.",
	                   StringValue ("ns3::NoOpHandoverAlgorithm"),
	                   MakeStringAccessor (&MmWaveHelper::SetLteHandoverAlgorithmType,
	                                       &MmWaveHelper::GetLteHandoverAlgorithmType),
	                   MakeStringChecker ())
	    .AddAttribute ("LtePathlossModel",
	                   "The type of pathloss model to be used for the 2 LTE channels. "
	                   "The allowed values for this attributes are the type names "
	                   "of any class inheriting from ns3::PropagationLossModel.",
	                   StringValue ("ns3::FriisPropagationLossModel"),
	                   MakeStringAccessor (&MmWaveHelper::SetLtePathlossModelType),
	                   MakeStringChecker ())
	    .AddAttribute ("UsePdschForCqiGeneration",
	                   "If true, DL-CQI will be calculated from PDCCH as signal and PDSCH as interference "
	                   "If false, DL-CQI will be calculated from PDCCH as signal and PDCCH as interference  ",
	                   BooleanValue (true),
	                   MakeBooleanAccessor (&MmWaveHelper::m_usePdschForCqiGeneration),
	                   MakeBooleanChecker ())
		.AddAttribute ("AnrEnabled",
	                   "Activate or deactivate Automatic Neighbour Relation function",
	                   BooleanValue (true),
	                   MakeBooleanAccessor (&MmWaveHelper::m_isAnrEnabled),
	                   MakeBooleanChecker ())
		.AddAttribute ("UseIdealRrc",
	                   "Use Ideal or Real RRC",
	                   BooleanValue (false),
	                   MakeBooleanAccessor (&MmWaveHelper::m_useIdealRrc),
	                   MakeBooleanChecker ())
		.AddAttribute ("BasicCellId",
                   "The next value will be the first cellId",
                   UintegerValue (0),
                   MakeUintegerAccessor (&MmWaveHelper::m_cellIdCounter),
                   MakeUintegerChecker<uint16_t> ())
	    .AddAttribute ("BasicImsi",
                   "The next value will be the first  imsi",
                   UintegerValue (0),
                   MakeUintegerAccessor (&MmWaveHelper::m_imsiCounter),
                   MakeUintegerChecker<uint16_t> ())
   	;

	return tid;
}

void
MmWaveHelper::DoDispose (void)
{
	NS_LOG_FUNCTION (this);
	m_channel = 0;
	Object::DoDispose ();
}

void
MmWaveHelper::DoInitialize()
{
	NS_LOG_FUNCTION (this);

	// setup of mmWave channel & related
	m_channel = m_channelFactory.Create<SpectrumChannel> ();
	m_phyMacCommon = CreateObject <MmWavePhyMacCommon> () ;

	if (!m_pathlossModelType.empty ())
	{
		m_pathlossModel = m_pathlossModelFactory.Create ();
		Ptr<PropagationLossModel> splm = m_pathlossModel->GetObject<PropagationLossModel> ();
		if( splm )
		{
			NS_LOG_LOGIC (this << " using a PropagationLossModel");
			m_channel->AddPropagationLossModel (splm);
		}

		if (m_pathlossModelType == "ns3::BuildingsObstaclePropagationLossModel")
		{
			m_losTracker = CreateObject<MmWaveLosTracker>(); // create and initialize m_losTracker
			Ptr<BuildingsObstaclePropagationLossModel> building = m_pathlossModel->GetObject<BuildingsObstaclePropagationLossModel> ();
			building->SetConfigurationParameters(m_phyMacCommon);
			building->SetBeamforming (m_beamforming);
			building->SetLosTracker(m_losTracker); // use m_losTracker in BuildingsObstaclePropagationLossModel
		}
		else if(m_pathlossModelType == "ns3::MmWavePropagationLossModel")
		{
			m_pathlossModel->GetObject<MmWavePropagationLossModel>()->SetConfigurationParameters(m_phyMacCommon);
		}
		else if(m_pathlossModelType == "ns3::MmWave3gppPropagationLossModel")
		{
			m_pathlossModel->GetObject<MmWave3gppPropagationLossModel>()->SetConfigurationParameters(m_phyMacCommon);
		}
		else if(m_pathlossModelType == "ns3::MmWave3gppBuildingsPropagationLossModel")
		{
			m_pathlossModel->GetObject<MmWave3gppBuildingsPropagationLossModel>()->SetConfigurationParameters(m_phyMacCommon);
		}
	}
	else
	{
		NS_LOG_UNCOND (this << " No PropagationLossModel!");
	}

	if(m_channelModelType == "ns3::MmWaveBeamforming")
	{
		m_beamforming = CreateObject<MmWaveBeamforming> (m_noTxAntenna, m_noRxAntenna);
		m_channel->AddSpectrumPropagationLossModel (m_beamforming);
		m_beamforming->SetConfigurationParameters (m_phyMacCommon);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelMatrix")
	{
		m_channelMatrix = CreateObject<MmWaveChannelMatrix> ();
		m_channel->AddSpectrumPropagationLossModel (m_channelMatrix);
		m_channelMatrix->SetConfigurationParameters (m_phyMacCommon);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelRaytracing")
	{
		m_raytracing = CreateObject<MmWaveChannelRaytracing> ();
		m_channel->AddSpectrumPropagationLossModel (m_raytracing);
		m_raytracing->SetConfigurationParameters (m_phyMacCommon);
	}
	else if(m_channelModelType == "ns3::MmWave3gppChannel")
	{
		m_3gppChannel = CreateObject<MmWave3gppChannel> ();
		m_channel->AddSpectrumPropagationLossModel (m_3gppChannel);
		m_3gppChannel->SetConfigurationParameters (m_phyMacCommon);
		if (m_pathlossModelType == "ns3::MmWave3gppBuildingsPropagationLossModel" || m_pathlossModelType == "ns3::MmWave3gppPropagationLossModel" )
		{
			Ptr<PropagationLossModel> pl = m_pathlossModel->GetObject<PropagationLossModel> ();
			m_3gppChannel->SetPathlossModel(pl);
		}
		else
		{
			NS_FATAL_ERROR("The 3GPP channel and propagation loss should be enabled at the same time");
		}
	}

	m_phyStats = CreateObject<MmWavePhyRxTrace> ();
	m_radioBearerStatsConnector = CreateObject<MmWaveBearerStatsConnector> ();

	// setup of LTE channels & related
	m_downlinkChannel = m_lteChannelFactory.Create<SpectrumChannel> ();
	m_uplinkChannel = m_lteChannelFactory.Create<SpectrumChannel> ();
	m_downlinkPathlossModel = m_dlPathlossModelFactory.Create ();
	Ptr<SpectrumPropagationLossModel> dlSplm = m_downlinkPathlossModel->GetObject<SpectrumPropagationLossModel> ();
	if (dlSplm != 0)
	{
	  NS_LOG_LOGIC (this << " using a SpectrumPropagationLossModel in DL");
	  m_downlinkChannel->AddSpectrumPropagationLossModel (dlSplm);
	}
	else
	{
	  NS_LOG_LOGIC (this << " using a PropagationLossModel in DL");
	  Ptr<PropagationLossModel> dlPlm = m_downlinkPathlossModel->GetObject<PropagationLossModel> ();
	  NS_ASSERT_MSG (dlPlm != 0, " " << m_downlinkPathlossModel << " is neither PropagationLossModel nor SpectrumPropagationLossModel");
	  m_downlinkChannel->AddPropagationLossModel (dlPlm);
	}

	m_uplinkPathlossModel = m_ulPathlossModelFactory.Create ();
	Ptr<SpectrumPropagationLossModel> ulSplm = m_uplinkPathlossModel->GetObject<SpectrumPropagationLossModel> ();
	if (ulSplm != 0)
	{
	  NS_LOG_LOGIC (this << " using a SpectrumPropagationLossModel in UL");
	  m_uplinkChannel->AddSpectrumPropagationLossModel (ulSplm);
	}
	else
	{
	  NS_LOG_LOGIC (this << " using a PropagationLossModel in UL");
	  Ptr<PropagationLossModel> ulPlm = m_uplinkPathlossModel->GetObject<PropagationLossModel> ();
	  NS_ASSERT_MSG (ulPlm != 0, " " << m_uplinkPathlossModel << " is neither PropagationLossModel nor SpectrumPropagationLossModel");
	  m_uplinkChannel->AddPropagationLossModel (ulPlm);
	}
	// TODO consider if adding LTE fading
	// TODO add mac & phy LTE stats
	m_cnStats = 0;

	NS_LOG_UNCOND("---- mmh UseIdealRrc " << m_useIdealRrc);
	Object::DoInitialize();
}

void
MmWaveHelper::SetAntenna (uint16_t Nrx, uint16_t Ntx)
{
	m_noTxAntenna = Ntx;
	m_noRxAntenna = Nrx;
}

void
MmWaveHelper::SetLtePathlossModelType (std::string type)
{
	NS_LOG_FUNCTION (this << type);
	m_dlPathlossModelFactory = ObjectFactory ();
	m_dlPathlossModelFactory.SetTypeId (type);
	m_ulPathlossModelFactory = ObjectFactory ();
	m_ulPathlossModelFactory.SetTypeId (type);
}

void
MmWaveHelper::SetPathlossModelType (std::string type)
{
	NS_LOG_FUNCTION (this << type);
	m_pathlossModelType = type;
	if (!type.empty ())
	{
		m_pathlossModelFactory = ObjectFactory ();
		m_pathlossModelFactory.SetTypeId (type);
	}
}

Ptr<PropagationLossModel>
MmWaveHelper::GetPathLossModel ()
{
	return m_pathlossModel->GetObject<PropagationLossModel> ();
}

void
MmWaveHelper::SetChannelModelType (std::string type)
{
	NS_LOG_FUNCTION (this << type);
	m_channelModelType = type;
}

void
MmWaveHelper::SetSchedulerType (std::string type)
{
	NS_LOG_FUNCTION (this << type);
	m_schedulerFactory = ObjectFactory ();
	m_schedulerFactory.SetTypeId (type);
}
std::string
MmWaveHelper::GetSchedulerType () const
{
	return m_schedulerFactory.GetTypeId ().GetName ();
}

void
MmWaveHelper::SetLteSchedulerType (std::string type)
{
	NS_LOG_FUNCTION (this << type);
	m_lteSchedulerFactory = ObjectFactory ();
	m_lteSchedulerFactory.SetTypeId (type);
}

std::string
MmWaveHelper::GetLteSchedulerType () const
{
	return m_lteSchedulerFactory.GetTypeId ().GetName ();
}


std::string
MmWaveHelper::GetLteFfrAlgorithmType () const
{
  return m_lteFfrAlgorithmFactory.GetTypeId ().GetName ();
}

void
MmWaveHelper::SetLteFfrAlgorithmType (std::string type)
{
  NS_LOG_FUNCTION (this << type);
  m_lteFfrAlgorithmFactory = ObjectFactory ();
  m_lteFfrAlgorithmFactory.SetTypeId (type);
}

// TODO add attributes

std::string
MmWaveHelper::GetLteHandoverAlgorithmType () const
{
  return m_lteHandoverAlgorithmFactory.GetTypeId ().GetName ();
}

void
MmWaveHelper::SetLteHandoverAlgorithmType (std::string type)
{
  NS_LOG_FUNCTION (this << type);
  m_lteHandoverAlgorithmFactory = ObjectFactory ();
  m_lteHandoverAlgorithmFactory.SetTypeId (type);
}

void
MmWaveHelper::SetHarqEnabled (bool harqEnabled)
{
	m_harqEnabled = harqEnabled;
}

bool
MmWaveHelper::GetHarqEnabled ()
{
	return m_harqEnabled;
}

void
MmWaveHelper::SetSnrTest (bool snrTest)
{
	m_snrTest = snrTest;
}

bool
MmWaveHelper::GetSnrTest ()
{
	return m_snrTest;
}

NetDeviceContainer
MmWaveHelper::InstallUeDevice (NodeContainer c)
{
	NS_LOG_FUNCTION (this);
	Initialize ();  // Run DoInitialize (), if necessary
	NetDeviceContainer devices;
	for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
	  {
	    Ptr<Node> node = *i;
	    Ptr<NetDevice> device = InstallSingleUeDevice (node);
	    device->SetAddress (Mac48Address::Allocate ());
	    devices.Add (device);
	  }
	return devices;

}

NetDeviceContainer
MmWaveHelper::InstallMcUeDevice (NodeContainer c) {
	NS_LOG_FUNCTION (this);
	Initialize ();  // Run DoInitialize (), if necessary
	NetDeviceContainer devices;
	for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
	  {
	    Ptr<Node> node = *i;
	    Ptr<NetDevice> device = InstallSingleMcUeDevice (node);
	    device->SetAddress (Mac48Address::Allocate ());
	    devices.Add (device);
	  }
	return devices;
}

NetDeviceContainer
MmWaveHelper::InstallInterRatHoCapableUeDevice (NodeContainer c) {
	NS_LOG_FUNCTION (this);
	Initialize ();  // Run DoInitialize (), if necessary
	NetDeviceContainer devices;
	for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
	  {
	    Ptr<Node> node = *i;
	    Ptr<NetDevice> device = InstallSingleInterRatHoCapableUeDevice (node);
	    device->SetAddress (Mac48Address::Allocate ());
	    devices.Add (device);
	  }
	return devices;
}

NetDeviceContainer
MmWaveHelper::InstallEnbDevice (NodeContainer c)
{
	NS_LOG_FUNCTION (this);
	Initialize ();  // Run DoInitialize (), if necessary
	NetDeviceContainer devices;
	for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
	  {
	    Ptr<Node> node = *i;
	    Ptr<NetDevice> device = InstallSingleEnbDevice (node);
	    device->SetAddress (Mac48Address::Allocate ());
	    devices.Add (device);
	  }
	return devices;
}

NetDeviceContainer
MmWaveHelper::InstallLteEnbDevice (NodeContainer c)
{
	NS_LOG_FUNCTION (this);
	Initialize ();  // Run DoInitialize (), if necessary
	NetDeviceContainer devices;
	for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
	  {
	    Ptr<Node> node = *i;
	    Ptr<NetDevice> device = InstallSingleLteEnbDevice (node);
	    device->SetAddress (Mac48Address::Allocate ());
	    devices.Add (device);
	  }
	return devices;
}

Ptr<NetDevice>
MmWaveHelper::InstallSingleMcUeDevice(Ptr<Node> n)
{
	NS_LOG_FUNCTION (this);

	Ptr<McUeNetDevice> device = m_mcUeNetDeviceFactory.Create<McUeNetDevice> ();
	NS_ABORT_MSG_IF (m_imsiCounter >= 0xFFFFFFFF, "max num UEs exceeded");
	uint64_t imsi = ++m_imsiCounter;

	// Phy part of MmWave
	Ptr<MmWaveSpectrumPhy> mmWaveUlPhy = CreateObject<MmWaveSpectrumPhy> ();
	Ptr<MmWaveSpectrumPhy> mmWaveDlPhy = CreateObject<MmWaveSpectrumPhy> ();
	NS_LOG_UNCOND("UE " << imsi << " MmWaveSpectrumPhy " << mmWaveDlPhy);

	Ptr<MmWaveUePhy> mmWavePhy = CreateObject<MmWaveUePhy> (mmWaveDlPhy, mmWaveUlPhy);

	Ptr<MmWaveHarqPhy> mmWaveHarq = Create<MmWaveHarqPhy> (m_phyMacCommon->GetNumHarqProcess ());
	
	mmWaveDlPhy->SetHarqPhyModule (mmWaveHarq);
	mmWavePhy->SetHarqPhyModule (mmWaveHarq);

	Ptr<mmWaveChunkProcessor> mmWavepData = Create<mmWaveChunkProcessor> ();
	mmWavepData->AddCallback (MakeCallback (&MmWaveUePhy::GenerateDlCqiReport, mmWavePhy));
	mmWavepData->AddCallback (MakeCallback (&MmWaveSpectrumPhy::UpdateSinrPerceived, mmWaveDlPhy));
	mmWaveDlPhy->AddDataSinrChunkProcessor (mmWavepData);
	if(m_harqEnabled)
	{
		mmWaveDlPhy->SetPhyDlHarqFeedbackCallback (MakeCallback (&MmWaveUePhy::ReceiveLteDlHarqFeedback, mmWavePhy));
	}

	// hack to allow periodic computation of SINR at the eNB, without pilots
	if(m_channelModelType == "ns3::MmWaveBeamforming")
	{
		mmWavePhy->AddSpectrumPropagationLossModel(m_beamforming);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelMatrix")
	{
		mmWavePhy->AddSpectrumPropagationLossModel(m_channelMatrix);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelRaytracing")
	{
		mmWavePhy->AddSpectrumPropagationLossModel(m_raytracing);
	}
	if (!m_pathlossModelType.empty ())
	{
		Ptr<PropagationLossModel> splm = m_pathlossModel->GetObject<PropagationLossModel> ();
		if( splm )
		{
			mmWavePhy->AddPropagationLossModel (splm);
		}
	}
	else
	{
		NS_LOG_UNCOND (this << " No PropagationLossModel!");
	}

	// Phy part of LTE
	Ptr<LteSpectrumPhy> lteDlPhy = CreateObject<LteSpectrumPhy> ();
	Ptr<LteSpectrumPhy> lteUlPhy = CreateObject<LteSpectrumPhy> ();

	Ptr<LteUePhy> ltePhy = CreateObject<LteUePhy> (lteDlPhy, lteUlPhy);

	Ptr<LteHarqPhy> lteHarq = Create<LteHarqPhy> ();
	lteDlPhy->SetHarqPhyModule (lteHarq);
	lteUlPhy->SetHarqPhyModule (lteHarq);
	ltePhy->SetHarqPhyModule (lteHarq);

	Ptr<LteChunkProcessor> pRs = Create<LteChunkProcessor> ();
	pRs->AddCallback (MakeCallback (&LteUePhy::ReportRsReceivedPower, ltePhy));
	lteDlPhy->AddRsPowerChunkProcessor (pRs);

	Ptr<LteChunkProcessor> pInterf = Create<LteChunkProcessor> ();
	pInterf->AddCallback (MakeCallback (&LteUePhy::ReportInterference, ltePhy));
	lteDlPhy->AddInterferenceCtrlChunkProcessor (pInterf); // for RSRQ evaluation of UE Measurements

	Ptr<LteChunkProcessor> pCtrl = Create<LteChunkProcessor> ();
	pCtrl->AddCallback (MakeCallback (&LteSpectrumPhy::UpdateSinrPerceived, lteDlPhy));
	lteDlPhy->AddCtrlSinrChunkProcessor (pCtrl);

	Ptr<LteChunkProcessor> pData = Create<LteChunkProcessor> ();
	pData->AddCallback (MakeCallback (&LteSpectrumPhy::UpdateSinrPerceived, lteDlPhy));
	lteDlPhy->AddDataSinrChunkProcessor (pData);

	if (m_usePdschForCqiGeneration)
	{
		// CQI calculation based on PDCCH for signal and PDSCH for interference
		pCtrl->AddCallback (MakeCallback (&LteUePhy::GenerateMixedCqiReport, ltePhy));
		Ptr<LteChunkProcessor> pDataInterf = Create<LteChunkProcessor> ();      
		pDataInterf->AddCallback (MakeCallback (&LteUePhy::ReportDataInterference, ltePhy));
		lteDlPhy->AddInterferenceDataChunkProcessor (pDataInterf);
	}
	else
	{
		// CQI calculation based on PDCCH for both signal and interference
		pCtrl->AddCallback (MakeCallback (&LteUePhy::GenerateCtrlCqiReport, ltePhy));
	}

	// Set MmWave channel
	mmWaveUlPhy->SetChannel(m_channel);
	mmWaveDlPhy->SetChannel(m_channel);
	// Set LTE channel
	lteUlPhy->SetChannel(m_uplinkChannel);
	lteDlPhy->SetChannel(m_downlinkChannel);

	Ptr<MobilityModel> mm = n->GetObject<MobilityModel> ();
	NS_ASSERT_MSG (mm, "MobilityModel needs to be set on node before calling MmWaveHelper::InstallUeDevice ()");
	mmWaveUlPhy->SetMobility(mm);
	mmWaveDlPhy->SetMobility(mm);
	lteUlPhy->SetMobility(mm);
	lteDlPhy->SetMobility(mm);

	// Antenna model for mmWave and for LTE
	Ptr<AntennaModel> antenna = (m_ueAntennaModelFactory.Create ())->GetObject<AntennaModel> ();
	NS_ASSERT_MSG (antenna, "error in creating the AntennaModel object");
	mmWaveUlPhy->SetAntenna (antenna);
	mmWaveDlPhy->SetAntenna (antenna);
	antenna = (m_lteUeAntennaModelFactory.Create ())->GetObject<AntennaModel> ();
	lteUlPhy->SetAntenna (antenna);
	lteDlPhy->SetAntenna (antenna);

	// ----------------------- mmWave stack -------------
	Ptr<MmWaveUeMac> mmWaveMac = CreateObject<MmWaveUeMac> ();
	Ptr<LteUeRrc> mmWaveRrc = CreateObject<LteUeRrc> ();

	mmWaveRrc->SetAttribute("SecondaryRRC", BooleanValue(true));
	if (m_useIdealRrc)
	{
		Ptr<MmWaveUeRrcProtocolIdeal> rrcProtocol = CreateObject<MmWaveUeRrcProtocolIdeal> ();
		rrcProtocol->SetUeRrc (mmWaveRrc);
		mmWaveRrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (mmWaveRrc->GetLteUeRrcSapProvider ());
		mmWaveRrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}
	else
	{
		Ptr<MmWaveLteUeRrcProtocolReal> rrcProtocol = CreateObject<MmWaveLteUeRrcProtocolReal> ();
		rrcProtocol->SetUeRrc (mmWaveRrc);
		mmWaveRrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (mmWaveRrc->GetLteUeRrcSapProvider ());
		mmWaveRrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}
	if (m_epcHelper != 0)
	{
		mmWaveRrc->SetUseRlcSm (false);
	}
	else
	{
		mmWaveRrc->SetUseRlcSm (true);
	}

	mmWaveRrc->SetLteUeCmacSapProvider (mmWaveMac->GetUeCmacSapProvider ());
	mmWaveMac->SetUeCmacSapUser (mmWaveRrc->GetLteUeCmacSapUser ());
	mmWaveRrc->SetLteMacSapProvider (mmWaveMac->GetUeMacSapProvider ());

	mmWavePhy->SetUeCphySapUser (mmWaveRrc->GetLteUeCphySapUser ());
	mmWaveRrc->SetLteUeCphySapProvider (mmWavePhy->GetUeCphySapProvider ());

	mmWavePhy->SetConfigurationParameters (m_phyMacCommon);
	mmWaveMac->SetConfigurationParameters (m_phyMacCommon);

	mmWavePhy->SetPhySapUser (mmWaveMac->GetPhySapUser());
	mmWaveMac->SetPhySapProvider (mmWavePhy->GetPhySapProvider());

	device->SetNode(n);
	device->SetAttribute ("MmWaveUePhy", PointerValue(mmWavePhy));
	device->SetAttribute ("MmWaveUeMac", PointerValue(mmWaveMac));
	device->SetAttribute ("MmWaveUeRrc", PointerValue (mmWaveRrc));

	mmWavePhy->SetDevice (device);
	mmWavePhy->SetImsi (imsi); 
	//mmWavePhy->SetForwardUpCallback (MakeCallback (&McUeNetDevice::Receive, device));
	mmWaveDlPhy->SetDevice(device);
	mmWaveUlPhy->SetDevice(device);

	mmWaveDlPhy->SetPhyRxDataEndOkCallback (MakeCallback (&MmWaveUePhy::PhyDataPacketReceived, mmWavePhy));
	mmWaveDlPhy->SetPhyRxCtrlEndOkCallback (MakeCallback (&MmWaveUePhy::ReceiveControlMessageList, mmWavePhy));

	// ----------------------- LTE stack ----------------------
	Ptr<LteUeMac> lteMac = CreateObject<LteUeMac> ();
	Ptr<LteUeRrc> lteRrc = CreateObject<LteUeRrc> ();

	if (m_useIdealRrc)
	{
		Ptr<MmWaveUeRrcProtocolIdeal> rrcProtocol = CreateObject<MmWaveUeRrcProtocolIdeal> ();
		rrcProtocol->SetUeRrc (lteRrc);
		lteRrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (lteRrc->GetLteUeRrcSapProvider ());
		lteRrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}
	else
	{
		Ptr<MmWaveLteUeRrcProtocolReal> rrcProtocol = CreateObject<MmWaveLteUeRrcProtocolReal> ();
		rrcProtocol->SetUeRrc (lteRrc);
		lteRrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (lteRrc->GetLteUeRrcSapProvider ());
		lteRrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}

	if (m_epcHelper != 0)
	{
		lteRrc->SetUseRlcSm (false);
	}

	Ptr<EpcUeNas> lteNas = CreateObject<EpcUeNas> ();

	lteNas->SetAsSapProvider (lteRrc->GetAsSapProvider ());
	lteNas->SetMmWaveAsSapProvider (mmWaveRrc->GetAsSapProvider());
	lteRrc->SetAsSapUser (lteNas->GetAsSapUser ());
	mmWaveRrc->SetAsSapUser (lteNas->GetAsSapUser ());

	lteRrc->SetLteUeCmacSapProvider (lteMac->GetLteUeCmacSapProvider ());
	lteMac->SetLteUeCmacSapUser (lteRrc->GetLteUeCmacSapUser ());
	lteRrc->SetLteMacSapProvider (lteMac->GetLteMacSapProvider ());

	// connect lteRrc (which will setup bearers) also to the MmWave Mac
	lteRrc->SetMmWaveUeCmacSapProvider (mmWaveMac->GetUeCmacSapProvider());
	lteRrc->SetMmWaveMacSapProvider (mmWaveMac->GetUeMacSapProvider()); 

	ltePhy->SetLteUePhySapUser (lteMac->GetLteUePhySapUser ());
	lteMac->SetLteUePhySapProvider (ltePhy->GetLteUePhySapProvider ());

	ltePhy->SetLteUeCphySapUser (lteRrc->GetLteUeCphySapUser ());
	lteRrc->SetLteUeCphySapProvider (ltePhy->GetLteUeCphySapProvider ());

	device->SetAttribute ("LteUePhy", PointerValue (ltePhy));
	device->SetAttribute ("LteUeMac", PointerValue (lteMac));
	device->SetAttribute ("LteUeRrc", PointerValue (lteRrc));
	device->SetAttribute ("EpcUeNas", PointerValue (lteNas));
	device->SetAttribute ("Imsi", UintegerValue(imsi));

	ltePhy->SetDevice (device);
	lteDlPhy->SetDevice (device);
	lteUlPhy->SetDevice (device);
	lteNas->SetDevice (device);

	lteDlPhy->SetLtePhyRxDataEndOkCallback (MakeCallback (&LteUePhy::PhyPduReceived, ltePhy));
	lteDlPhy->SetLtePhyRxCtrlEndOkCallback (MakeCallback (&LteUePhy::ReceiveLteControlMessageList, ltePhy));
	lteDlPhy->SetLtePhyRxPssCallback (MakeCallback (&LteUePhy::ReceivePss, ltePhy));
	lteDlPhy->SetLtePhyDlHarqFeedbackCallback (MakeCallback (&LteUePhy::ReceiveLteDlHarqFeedback, ltePhy));
	lteNas->SetForwardUpCallback (MakeCallback (&McUeNetDevice::Receive, device));

	if (m_epcHelper != 0)
	{
		m_epcHelper->AddUe (device, device->GetImsi ());
	}

	n->AddDevice(device);
	device->Initialize();

	return device;
}

Ptr<NetDevice>
MmWaveHelper::InstallSingleInterRatHoCapableUeDevice(Ptr<Node> n)
{
	NS_LOG_FUNCTION (this);

	// Use a McUeNetDevice but install a single RRC
	Ptr<McUeNetDevice> device = m_mcUeNetDeviceFactory.Create<McUeNetDevice> ();
	NS_ABORT_MSG_IF (m_imsiCounter >= 0xFFFFFFFF, "max num UEs exceeded");
	uint64_t imsi = ++m_imsiCounter;

	// Phy part of MmWave
	Ptr<MmWaveSpectrumPhy> mmWaveUlPhy = CreateObject<MmWaveSpectrumPhy> ();
	Ptr<MmWaveSpectrumPhy> mmWaveDlPhy = CreateObject<MmWaveSpectrumPhy> ();

	Ptr<MmWaveUePhy> mmWavePhy = CreateObject<MmWaveUePhy> (mmWaveDlPhy, mmWaveUlPhy);

	Ptr<MmWaveHarqPhy> mmWaveHarq = Create<MmWaveHarqPhy> (m_phyMacCommon->GetNumHarqProcess ());
	
	mmWaveDlPhy->SetHarqPhyModule (mmWaveHarq);
	mmWavePhy->SetHarqPhyModule (mmWaveHarq);

	Ptr<mmWaveChunkProcessor> mmWavepData = Create<mmWaveChunkProcessor> ();
	mmWavepData->AddCallback (MakeCallback (&MmWaveUePhy::GenerateDlCqiReport, mmWavePhy));
	mmWavepData->AddCallback (MakeCallback (&MmWaveSpectrumPhy::UpdateSinrPerceived, mmWaveDlPhy));
	mmWaveDlPhy->AddDataSinrChunkProcessor (mmWavepData);
	if(m_harqEnabled)
	{
		mmWaveDlPhy->SetPhyDlHarqFeedbackCallback (MakeCallback (&MmWaveUePhy::ReceiveLteDlHarqFeedback, mmWavePhy));
	}

	// hack to allow periodic computation of SINR at the eNB, without pilots
	if(m_channelModelType == "ns3::MmWaveBeamforming")
	{
		mmWavePhy->AddSpectrumPropagationLossModel(m_beamforming);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelMatrix")
	{
		mmWavePhy->AddSpectrumPropagationLossModel(m_channelMatrix);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelRaytracing")
	{
		mmWavePhy->AddSpectrumPropagationLossModel(m_raytracing);
	}
	if (!m_pathlossModelType.empty ())
	{
		Ptr<PropagationLossModel> splm = m_pathlossModel->GetObject<PropagationLossModel> ();
		if( splm )
		{
			mmWavePhy->AddPropagationLossModel (splm);
		}
	}
	else
	{
		NS_LOG_UNCOND (this << " No PropagationLossModel!");
	}

	// Phy part of LTE
	Ptr<LteSpectrumPhy> lteDlPhy = CreateObject<LteSpectrumPhy> ();
	Ptr<LteSpectrumPhy> lteUlPhy = CreateObject<LteSpectrumPhy> ();

	Ptr<LteUePhy> ltePhy = CreateObject<LteUePhy> (lteDlPhy, lteUlPhy);

	Ptr<LteHarqPhy> lteHarq = Create<LteHarqPhy> ();
	lteDlPhy->SetHarqPhyModule (lteHarq);
	lteUlPhy->SetHarqPhyModule (lteHarq);
	ltePhy->SetHarqPhyModule (lteHarq);

	Ptr<LteChunkProcessor> pRs = Create<LteChunkProcessor> ();
	pRs->AddCallback (MakeCallback (&LteUePhy::ReportRsReceivedPower, ltePhy));
	lteDlPhy->AddRsPowerChunkProcessor (pRs);

	Ptr<LteChunkProcessor> pInterf = Create<LteChunkProcessor> ();
	pInterf->AddCallback (MakeCallback (&LteUePhy::ReportInterference, ltePhy));
	lteDlPhy->AddInterferenceCtrlChunkProcessor (pInterf); // for RSRQ evaluation of UE Measurements

	Ptr<LteChunkProcessor> pCtrl = Create<LteChunkProcessor> ();
	pCtrl->AddCallback (MakeCallback (&LteSpectrumPhy::UpdateSinrPerceived, lteDlPhy));
	lteDlPhy->AddCtrlSinrChunkProcessor (pCtrl);

	Ptr<LteChunkProcessor> pData = Create<LteChunkProcessor> ();
	pData->AddCallback (MakeCallback (&LteSpectrumPhy::UpdateSinrPerceived, lteDlPhy));
	lteDlPhy->AddDataSinrChunkProcessor (pData);

	if (m_usePdschForCqiGeneration)
	{
		// CQI calculation based on PDCCH for signal and PDSCH for interference
		pCtrl->AddCallback (MakeCallback (&LteUePhy::GenerateMixedCqiReport, ltePhy));
		Ptr<LteChunkProcessor> pDataInterf = Create<LteChunkProcessor> ();      
		pDataInterf->AddCallback (MakeCallback (&LteUePhy::ReportDataInterference, ltePhy));
		lteDlPhy->AddInterferenceDataChunkProcessor (pDataInterf);
	}
	else
	{
		// CQI calculation based on PDCCH for both signal and interference
		pCtrl->AddCallback (MakeCallback (&LteUePhy::GenerateCtrlCqiReport, ltePhy));
	}

	// Set MmWave channel
	mmWaveUlPhy->SetChannel(m_channel);
	mmWaveDlPhy->SetChannel(m_channel);
	// Set LTE channel
	lteUlPhy->SetChannel(m_uplinkChannel);
	lteDlPhy->SetChannel(m_downlinkChannel);

	Ptr<MobilityModel> mm = n->GetObject<MobilityModel> ();
	NS_ASSERT_MSG (mm, "MobilityModel needs to be set on node before calling MmWaveHelper::InstallUeDevice ()");
	mmWaveUlPhy->SetMobility(mm);
	mmWaveDlPhy->SetMobility(mm);
	lteUlPhy->SetMobility(mm);
	lteDlPhy->SetMobility(mm);

	// Antenna model for mmWave and for LTE
	Ptr<AntennaModel> antenna = (m_ueAntennaModelFactory.Create ())->GetObject<AntennaModel> ();
	NS_ASSERT_MSG (antenna, "error in creating the AntennaModel object");
	mmWaveUlPhy->SetAntenna (antenna);
	mmWaveDlPhy->SetAntenna (antenna);
	antenna = (m_lteUeAntennaModelFactory.Create ())->GetObject<AntennaModel> ();
	lteUlPhy->SetAntenna (antenna);
	lteDlPhy->SetAntenna (antenna);

	// ----------------------- mmWave MAC and connections -------------
	Ptr<MmWaveUeMac> mmWaveMac = CreateObject<MmWaveUeMac> ();

	mmWavePhy->SetConfigurationParameters (m_phyMacCommon);
	mmWaveMac->SetConfigurationParameters (m_phyMacCommon);
	mmWaveMac->SetAttribute("InterRatHoCapable", BooleanValue(true));

	mmWavePhy->SetPhySapUser (mmWaveMac->GetPhySapUser());
	mmWaveMac->SetPhySapProvider (mmWavePhy->GetPhySapProvider());

	device->SetNode(n);
	device->SetAttribute ("MmWaveUePhy", PointerValue(mmWavePhy));
	device->SetAttribute ("MmWaveUeMac", PointerValue(mmWaveMac));

	mmWavePhy->SetDevice (device);
	mmWavePhy->SetImsi (imsi); 
	//mmWavePhy->SetForwardUpCallback (MakeCallback (&McUeNetDevice::Receive, device));
	mmWaveDlPhy->SetDevice(device);
	mmWaveUlPhy->SetDevice(device);

	mmWaveDlPhy->SetPhyRxDataEndOkCallback (MakeCallback (&MmWaveUePhy::PhyDataPacketReceived, mmWavePhy));
	mmWaveDlPhy->SetPhyRxCtrlEndOkCallback (MakeCallback (&MmWaveUePhy::ReceiveControlMessageList, mmWavePhy));

	// ----------------------- LTE stack ----------------------
	Ptr<LteUeMac> lteMac = CreateObject<LteUeMac> ();
	Ptr<LteUeRrc> rrc = CreateObject<LteUeRrc> (); //  single rrc 

	if (m_useIdealRrc)
	{
		Ptr<MmWaveUeRrcProtocolIdeal> rrcProtocol = CreateObject<MmWaveUeRrcProtocolIdeal> ();
		rrcProtocol->SetUeRrc (rrc);
		rrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (rrc->GetLteUeRrcSapProvider ());
		rrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}
	else
	{
		Ptr<MmWaveLteUeRrcProtocolReal> rrcProtocol = CreateObject<MmWaveLteUeRrcProtocolReal> ();
		rrcProtocol->SetUeRrc (rrc);
		rrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (rrc->GetLteUeRrcSapProvider ());
		rrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}

	if (m_epcHelper != 0)
	{
		rrc->SetUseRlcSm (false);
	}

	Ptr<EpcUeNas> lteNas = CreateObject<EpcUeNas> ();

	lteNas->SetAsSapProvider (rrc->GetAsSapProvider ());
	rrc->SetAsSapUser (lteNas->GetAsSapUser ());

	// CMAC SAP
	lteMac->SetLteUeCmacSapUser (rrc->GetLteUeCmacSapUser ());
	mmWaveMac->SetUeCmacSapUser (rrc->GetLteUeCmacSapUser ());
	rrc->SetLteUeCmacSapProvider (lteMac->GetLteUeCmacSapProvider ());
	rrc->SetMmWaveUeCmacSapProvider (mmWaveMac->GetUeCmacSapProvider());

	// CPHY SAP
	ltePhy->SetLteUeCphySapUser (rrc->GetLteUeCphySapUser ());
	mmWavePhy->SetUeCphySapUser (rrc->GetLteUeCphySapUser ());
	rrc->SetLteUeCphySapProvider (ltePhy->GetLteUeCphySapProvider ());
	rrc->SetMmWaveUeCphySapProvider (mmWavePhy->GetUeCphySapProvider());

	// MAC SAP
	rrc->SetLteMacSapProvider (lteMac->GetLteMacSapProvider ());
	rrc->SetMmWaveMacSapProvider (mmWaveMac->GetUeMacSapProvider()); 

	rrc->SetAttribute ("InterRatHoCapable", BooleanValue(true));

	ltePhy->SetLteUePhySapUser (lteMac->GetLteUePhySapUser ());
	lteMac->SetLteUePhySapProvider (ltePhy->GetLteUePhySapProvider ());

	device->SetAttribute ("LteUePhy", PointerValue (ltePhy));
	device->SetAttribute ("LteUeMac", PointerValue (lteMac));
	device->SetAttribute ("LteUeRrc", PointerValue (rrc));
	device->SetAttribute ("EpcUeNas", PointerValue (lteNas));
	device->SetAttribute ("Imsi", UintegerValue(imsi));

	ltePhy->SetDevice (device);
	lteDlPhy->SetDevice (device);
	lteUlPhy->SetDevice (device);
	lteNas->SetDevice (device);

	lteDlPhy->SetLtePhyRxDataEndOkCallback (MakeCallback (&LteUePhy::PhyPduReceived, ltePhy));
	lteDlPhy->SetLtePhyRxCtrlEndOkCallback (MakeCallback (&LteUePhy::ReceiveLteControlMessageList, ltePhy));
	lteDlPhy->SetLtePhyRxPssCallback (MakeCallback (&LteUePhy::ReceivePss, ltePhy));
	lteDlPhy->SetLtePhyDlHarqFeedbackCallback (MakeCallback (&LteUePhy::ReceiveLteDlHarqFeedback, ltePhy));
	lteNas->SetForwardUpCallback (MakeCallback (&McUeNetDevice::Receive, device));

	if (m_epcHelper != 0)
	{
		m_epcHelper->AddUe (device, device->GetImsi ());
	}

	n->AddDevice(device);
	device->Initialize();

	return device;
}

Ptr<NetDevice>
MmWaveHelper::InstallSingleUeDevice (Ptr<Node> n)
{
	Ptr<MmWaveUeNetDevice> device = m_ueNetDeviceFactory.Create<MmWaveUeNetDevice> ();
	//m_imsiCounter++;

	Ptr<MmWaveSpectrumPhy> ulPhy = CreateObject<MmWaveSpectrumPhy> ();
	Ptr<MmWaveSpectrumPhy> dlPhy = CreateObject<MmWaveSpectrumPhy> ();

	Ptr<MmWaveUePhy> phy = CreateObject<MmWaveUePhy> (dlPhy, ulPhy);

	Ptr<MmWaveHarqPhy> harq = Create<MmWaveHarqPhy> (m_phyMacCommon->GetNumHarqProcess ());
	dlPhy->SetHarqPhyModule (harq);
//	ulPhy->SetHarqPhyModule (harq);
	phy->SetHarqPhyModule (harq);

	/* Do not do this here. Do it during registration with the BS
	 * phy->SetConfigurationParameters(m_phyMacCommon);*/

	if(m_channelModelType == "ns3::MmWaveBeamforming")
	{
		phy->AddSpectrumPropagationLossModel(m_beamforming);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelMatrix")
	{
		phy->AddSpectrumPropagationLossModel(m_channelMatrix);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelRaytracing")
	{
		phy->AddSpectrumPropagationLossModel(m_raytracing);
	}
	if (!m_pathlossModelType.empty ())
	{
		Ptr<PropagationLossModel> splm = m_pathlossModel->GetObject<PropagationLossModel> ();
		if( splm )
		{
			phy->AddPropagationLossModel (splm);
		}
	}
	else
	{
		NS_LOG_UNCOND (this << " No PropagationLossModel!");
	}

	Ptr<mmWaveChunkProcessor> pData = Create<mmWaveChunkProcessor> ();
	pData->AddCallback (MakeCallback (&MmWaveUePhy::GenerateDlCqiReport, phy));
	pData->AddCallback (MakeCallback (&MmWaveSpectrumPhy::UpdateSinrPerceived, dlPhy));
	dlPhy->AddDataSinrChunkProcessor (pData);
	if(m_harqEnabled)
	{
		dlPhy->SetPhyDlHarqFeedbackCallback (MakeCallback (&MmWaveUePhy::ReceiveLteDlHarqFeedback, phy));
	}

	ulPhy->SetChannel(m_channel);
	dlPhy->SetChannel(m_channel);

	Ptr<MobilityModel> mm = n->GetObject<MobilityModel> ();
	NS_ASSERT_MSG (mm, "MobilityModel needs to be set on node before calling MmWaveHelper::InstallUeDevice ()");
	ulPhy->SetMobility(mm);
	dlPhy->SetMobility(mm);

	Ptr<MmWaveUeMac> mac = CreateObject<MmWaveUeMac> ();

	/* Antenna model */
	Ptr<AntennaModel> antenna = (m_ueAntennaModelFactory.Create ())->GetObject<AntennaModel> ();
	NS_ASSERT_MSG (antenna, "error in creating the AntennaModel object");
	dlPhy->SetAntenna (antenna);
	ulPhy->SetAntenna (antenna);

	Ptr<LteUeRrc> rrc = CreateObject<LteUeRrc> ();
	if (m_useIdealRrc)
	{
		Ptr<MmWaveUeRrcProtocolIdeal> rrcProtocol = CreateObject<MmWaveUeRrcProtocolIdeal> ();
		rrcProtocol->SetUeRrc (rrc);
		rrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (rrc->GetLteUeRrcSapProvider ());
		rrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}
	else
	{
		Ptr<MmWaveLteUeRrcProtocolReal> rrcProtocol = CreateObject<MmWaveLteUeRrcProtocolReal> ();
		rrcProtocol->SetUeRrc (rrc);
		rrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (rrc->GetLteUeRrcSapProvider ());
		rrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}
	if (m_epcHelper != 0)
	{
		rrc->SetUseRlcSm (false);
	}
	else
	{
		rrc->SetUseRlcSm (true);
	}
	Ptr<EpcUeNas> nas = CreateObject<EpcUeNas> ();
	nas->SetAsSapProvider (rrc->GetAsSapProvider ());
	rrc->SetAsSapUser (nas->GetAsSapUser ());

	rrc->SetLteUeCmacSapProvider (mac->GetUeCmacSapProvider ());
	mac->SetUeCmacSapUser (rrc->GetLteUeCmacSapUser ());
	rrc->SetLteMacSapProvider (mac->GetUeMacSapProvider ());

	phy->SetUeCphySapUser (rrc->GetLteUeCphySapUser ());
	rrc->SetLteUeCphySapProvider (phy->GetUeCphySapProvider ());

	NS_ABORT_MSG_IF (m_imsiCounter >= 0xFFFFFFFF, "max num UEs exceeded");
	uint64_t imsi = ++m_imsiCounter;

	phy->SetConfigurationParameters (m_phyMacCommon);
	mac->SetConfigurationParameters (m_phyMacCommon);

	phy->SetPhySapUser (mac->GetPhySapUser());
	mac->SetPhySapProvider (phy->GetPhySapProvider());

	device->SetNode(n);
	device->SetAttribute ("Imsi", UintegerValue(imsi));
	device->SetAttribute ("MmWaveUePhy", PointerValue(phy));
	device->SetAttribute ("MmWaveUeMac", PointerValue(mac));
	device->SetAttribute ("EpcUeNas", PointerValue (nas));
	device->SetAttribute ("mmWaveUeRrc", PointerValue (rrc));

	phy->SetDevice (device);
	phy->SetImsi (imsi);
	//phy->SetForwardUpCallback (MakeCallback (&MmWaveUeNetDevice::Receive, device));
	ulPhy->SetDevice(device);
	dlPhy->SetDevice(device);
	nas->SetDevice(device);


	n->AddDevice(device);
	dlPhy->SetPhyRxDataEndOkCallback (MakeCallback (&MmWaveUePhy::PhyDataPacketReceived, phy));
	dlPhy->SetPhyRxCtrlEndOkCallback (MakeCallback (&MmWaveUePhy::ReceiveControlMessageList, phy));
	nas->SetForwardUpCallback (MakeCallback (&MmWaveUeNetDevice::Receive, device));
	if (m_epcHelper != 0)
	{
		m_epcHelper->AddUe (device, device->GetImsi ());
	}

	device->Initialize();

	return device;
}

Ptr<NetDevice>
MmWaveHelper::InstallSingleEnbDevice (Ptr<Node> n)
{
	NS_ABORT_MSG_IF (m_cellIdCounter == 65535, "max num eNBs exceeded");
	uint16_t cellId = ++m_cellIdCounter;

	Ptr<MmWaveSpectrumPhy> ulPhy = CreateObject<MmWaveSpectrumPhy> ();
	Ptr<MmWaveSpectrumPhy> dlPhy = CreateObject<MmWaveSpectrumPhy> ();

	Ptr<MmWaveEnbPhy> phy = CreateObject<MmWaveEnbPhy> (dlPhy, ulPhy);
	NS_LOG_UNCOND("eNB " << cellId << " MmWaveSpectrumPhy " << dlPhy);

	Ptr<MmWaveHarqPhy> harq = Create<MmWaveHarqPhy> (m_phyMacCommon->GetNumHarqProcess ());
	dlPhy->SetHarqPhyModule (harq);
//	ulPhy->SetHarqPhyModule (harq);
	phy->SetHarqPhyModule (harq);

	Ptr<mmWaveChunkProcessor> pData = Create<mmWaveChunkProcessor> ();
	if(!m_snrTest)
	{
		pData->AddCallback (MakeCallback (&MmWaveEnbPhy::GenerateDataCqiReport, phy));
		pData->AddCallback (MakeCallback (&MmWaveSpectrumPhy::UpdateSinrPerceived, dlPhy));
	}
	dlPhy->AddDataSinrChunkProcessor (pData);

	phy->SetConfigurationParameters(m_phyMacCommon);

	ulPhy->SetChannel (m_channel);
	dlPhy->SetChannel (m_channel);

	Ptr<MobilityModel> mm = n->GetObject<MobilityModel> ();
	NS_ASSERT_MSG (mm, "MobilityModel needs to be set on node before calling MmWaveHelper::InstallEnbDevice ()");
	ulPhy->SetMobility (mm);
	dlPhy->SetMobility (mm);

	// hack to allow periodic computation of SINR at the eNB, without pilots
	if(m_channelModelType == "ns3::MmWaveBeamforming")
	{
		phy->AddSpectrumPropagationLossModel(m_beamforming);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelMatrix")
	{
		phy->AddSpectrumPropagationLossModel(m_channelMatrix);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelRaytracing")
	{
		phy->AddSpectrumPropagationLossModel(m_raytracing);
	}
	else if(m_channelModelType == "ns3::MmWave3gppChannel")
	{
		phy->AddSpectrumPropagationLossModel(m_3gppChannel);
	}
	if (!m_pathlossModelType.empty ())
	{
		Ptr<PropagationLossModel> splm = m_pathlossModel->GetObject<PropagationLossModel> ();
		if( splm )
		{
			phy->AddPropagationLossModel (splm);
			if (m_losTracker != 0)
			{
				phy->AddLosTracker(m_losTracker); // use m_losTracker in phy (and in particular in enbPhy)
			}
		}
	}
	else
	{
		NS_LOG_UNCOND (this << " No PropagationLossModel!");
	}

	/* Antenna model */
	Ptr<AntennaModel> antenna = (m_enbAntennaModelFactory.Create ())->GetObject<AntennaModel> ();
	NS_ASSERT_MSG (antenna, "error in creating the AntennaModel object");
	dlPhy->SetAntenna (antenna);
	ulPhy->SetAntenna (antenna);

	Ptr<MmWaveEnbMac> mac = CreateObject<MmWaveEnbMac> ();
	mac->SetConfigurationParameters (m_phyMacCommon);
	Ptr<MmWaveMacScheduler> sched = m_schedulerFactory.Create<MmWaveMacScheduler> ();

	/*to use the dummy ffrAlgorithm, I changed the bandwidth to 25 in EnbNetDevice
	m_ffrAlgorithmFactory = ObjectFactory ();
	m_ffrAlgorithmFactory.SetTypeId ("ns3::LteFrNoOpAlgorithm");
	Ptr<LteFfrAlgorithm> ffrAlgorithm = m_ffrAlgorithmFactory.Create<LteFfrAlgorithm> ();
	*/
	sched->ConfigureCommonParameters (m_phyMacCommon);
	mac->SetMmWaveMacSchedSapProvider(sched->GetMacSchedSapProvider());
	sched->SetMacSchedSapUser (mac->GetMmWaveMacSchedSapUser());
	mac->SetMmWaveMacCschedSapProvider(sched->GetMacCschedSapProvider());
	sched->SetMacCschedSapUser (mac->GetMmWaveMacCschedSapUser());

	phy->SetPhySapUser (mac->GetPhySapUser());
	mac->SetPhySapProvider (phy->GetPhySapProvider());
	Ptr<LteEnbRrc> rrc = CreateObject<LteEnbRrc> ();

	if (m_useIdealRrc)
	{
		Ptr<MmWaveEnbRrcProtocolIdeal> rrcProtocol = CreateObject<MmWaveEnbRrcProtocolIdeal> ();
		rrcProtocol->SetLteEnbRrcSapProvider (rrc->GetLteEnbRrcSapProvider ());
		rrc->SetLteEnbRrcSapUser (rrcProtocol->GetLteEnbRrcSapUser ());
		rrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetCellId (cellId);
	}
	else
	{
		Ptr<MmWaveLteEnbRrcProtocolReal> rrcProtocol = CreateObject<MmWaveLteEnbRrcProtocolReal> ();
		rrcProtocol->SetLteEnbRrcSapProvider (rrc->GetLteEnbRrcSapProvider ());
		rrc->SetLteEnbRrcSapUser (rrcProtocol->GetLteEnbRrcSapUser ());
		rrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetCellId (cellId);
	}

	if (m_epcHelper != 0)
	{
		EnumValue epsBearerToRlcMapping;
		rrc->GetAttribute ("EpsBearerToRlcMapping", epsBearerToRlcMapping);
		// it does not make sense to use RLC/SM when also using the EPC
		if (epsBearerToRlcMapping.Get () == LteEnbRrc::RLC_SM_ALWAYS)
		{
			if (m_rlcAmEnabled)
			{
				rrc->SetAttribute ("EpsBearerToRlcMapping", EnumValue (LteEnbRrc::RLC_AM_ALWAYS));
			}
			else
			{
				rrc->SetAttribute ("EpsBearerToRlcMapping", EnumValue (LteEnbRrc::RLC_UM_LOWLAT_ALWAYS));
			}
		}
	}

	rrc->SetAttribute ("mmWaveDevice", BooleanValue(true));
	rrc->SetLteEnbCmacSapProvider (mac->GetEnbCmacSapProvider ());
	mac->SetEnbCmacSapUser (rrc->GetLteEnbCmacSapUser ());

	rrc->SetLteMacSapProvider (mac->GetUeMacSapProvider ());
	phy->SetMmWaveEnbCphySapUser (rrc->GetLteEnbCphySapUser ());
	rrc->SetLteEnbCphySapProvider (phy->GetMmWaveEnbCphySapProvider ());

	//FFR SAP
	//rrc->SetLteFfrRrcSapProvider (ffrAlgorithm->GetLteFfrRrcSapProvider ());
	//ffrAlgorithm->SetLteFfrRrcSapUser (rrc->GetLteFfrRrcSapUser ());


	Ptr<MmWaveEnbNetDevice> device = m_enbNetDeviceFactory.Create<MmWaveEnbNetDevice> ();
	device->SetNode (n);
	device->SetAttribute ("CellId", UintegerValue (cellId));
	device->SetAttribute ("MmWaveEnbPhy", PointerValue (phy));
	device->SetAttribute ("MmWaveEnbMac", PointerValue (mac));
	device->SetAttribute ("mmWaveScheduler", PointerValue(sched));
	device->SetAttribute ("LteEnbRrc", PointerValue (rrc));


	phy->SetDevice (device);
	dlPhy->SetDevice (device);
	dlPhy->SetCellId (cellId);
	ulPhy->SetDevice (device);
	n->AddDevice (device);

	mac->SetCellId(cellId);
	dlPhy->SetPhyRxDataEndOkCallback (MakeCallback (&MmWaveEnbPhy::PhyDataPacketReceived, phy));
	dlPhy->SetPhyRxCtrlEndOkCallback (MakeCallback (&MmWaveEnbPhy::PhyCtrlMessagesReceived, phy));
  	dlPhy->SetPhyUlHarqFeedbackCallback (MakeCallback (&MmWaveEnbPhy::ReceiveUlHarqFeedback, phy));

	//mac->SetForwardUpCallback (MakeCallback (&MmWaveEnbNetDevice::Receive, device));
	rrc->SetForwardUpCallback (MakeCallback (&MmWaveEnbNetDevice::Receive, device));
	rrc->SetAttribute("mmWaveDevice", BooleanValue(true));

	NS_LOG_LOGIC ("set the propagation model frequencies");
	double freq = m_phyMacCommon->GetCenterFrequency ();
	NS_LOG_LOGIC ("Channel Frequency: " << freq);
	if (!m_pathlossModelType.empty ())
	{
		bool freqOk = m_pathlossModel->SetAttributeFailSafe ("Frequency", DoubleValue (freq));
		if (!freqOk)
		{
			NS_LOG_WARN ("Propagation model does not have a Frequency attribute");
		}
	}

	device->Initialize ();

	m_channel->AddRx (dlPhy);


	if (m_epcHelper != 0)
	{
		NS_LOG_INFO ("adding this eNB to the EPC");
		m_epcHelper->AddEnb (n, device, device->GetCellId ());
		Ptr<EpcEnbApplication> enbApp = n->GetApplication (0)->GetObject<EpcEnbApplication> ();
		NS_ASSERT_MSG (enbApp != 0, "cannot retrieve EpcEnbApplication");

		// S1 SAPs
		rrc->SetS1SapProvider (enbApp->GetS1SapProvider ());
		enbApp->SetS1SapUser (rrc->GetS1SapUser ());

		// X2 SAPs
		Ptr<EpcX2> x2 = n->GetObject<EpcX2> ();
		x2->SetEpcX2SapUser (rrc->GetEpcX2SapUser ());
		rrc->SetEpcX2SapProvider (x2->GetEpcX2SapProvider ());
	 	rrc->SetEpcX2RlcProvider (x2->GetEpcX2RlcProvider ());

	}

	return device;
}


Ptr<NetDevice>
MmWaveHelper::InstallSingleLteEnbDevice (Ptr<Node> n)
{
	NS_ABORT_MSG_IF (m_cellIdCounter == 65535, "max num eNBs exceeded");
	uint16_t cellId = ++m_cellIdCounter;

	Ptr<LteSpectrumPhy> dlPhy = CreateObject<LteSpectrumPhy> ();
	Ptr<LteSpectrumPhy> ulPhy = CreateObject<LteSpectrumPhy> ();

	Ptr<LteEnbPhy> phy = CreateObject<LteEnbPhy> (dlPhy, ulPhy);

	Ptr<LteHarqPhy> harq = Create<LteHarqPhy> ();
	dlPhy->SetHarqPhyModule (harq);
	ulPhy->SetHarqPhyModule (harq);
	phy->SetHarqPhyModule (harq);

	Ptr<LteChunkProcessor> pCtrl = Create<LteChunkProcessor> ();
	pCtrl->AddCallback (MakeCallback (&LteEnbPhy::GenerateCtrlCqiReport, phy));
	ulPhy->AddCtrlSinrChunkProcessor (pCtrl); // for evaluating SRS UL-CQI

	Ptr<LteChunkProcessor> pData = Create<LteChunkProcessor> ();
	pData->AddCallback (MakeCallback (&LteEnbPhy::GenerateDataCqiReport, phy));
	pData->AddCallback (MakeCallback (&LteSpectrumPhy::UpdateSinrPerceived, ulPhy));
	ulPhy->AddDataSinrChunkProcessor (pData); // for evaluating PUSCH UL-CQI

	Ptr<LteChunkProcessor> pInterf = Create<LteChunkProcessor> ();
	pInterf->AddCallback (MakeCallback (&LteEnbPhy::ReportInterference, phy));
	ulPhy->AddInterferenceDataChunkProcessor (pInterf); // for interference power tracing

	dlPhy->SetChannel (m_downlinkChannel);
	ulPhy->SetChannel (m_uplinkChannel);

	Ptr<MobilityModel> mm = n->GetObject<MobilityModel> ();
	NS_ASSERT_MSG (mm, "MobilityModel needs to be set on node before calling MmWaveHelper::InstallUeDevice ()");
	dlPhy->SetMobility (mm);
	ulPhy->SetMobility (mm);

	Ptr<AntennaModel> antenna = (m_lteEnbAntennaModelFactory.Create ())->GetObject<AntennaModel> ();
	NS_ASSERT_MSG (antenna, "error in creating the AntennaModel object");
	dlPhy->SetAntenna (antenna);
	ulPhy->SetAntenna (antenna);

	Ptr<LteEnbMac> mac = CreateObject<LteEnbMac> ();
	Ptr<FfMacScheduler> sched = m_lteSchedulerFactory.Create<FfMacScheduler> ();
	Ptr<LteFfrAlgorithm> ffrAlgorithm = m_lteFfrAlgorithmFactory.Create<LteFfrAlgorithm> ();
	Ptr<LteHandoverAlgorithm> handoverAlgorithm = m_lteHandoverAlgorithmFactory.Create<LteHandoverAlgorithm> ();
	Ptr<LteEnbRrc> rrc = CreateObject<LteEnbRrc> ();

	if (m_useIdealRrc)
	{
	  Ptr<MmWaveEnbRrcProtocolIdeal> rrcProtocol = CreateObject<MmWaveEnbRrcProtocolIdeal> ();
	  rrcProtocol->SetLteEnbRrcSapProvider (rrc->GetLteEnbRrcSapProvider ());
	  rrc->SetLteEnbRrcSapUser (rrcProtocol->GetLteEnbRrcSapUser ());
	  rrc->AggregateObject (rrcProtocol);
	  rrcProtocol->SetCellId (cellId);
	}
	else
	{
	  Ptr<MmWaveLteEnbRrcProtocolReal> rrcProtocol = CreateObject<MmWaveLteEnbRrcProtocolReal> ();
	  rrcProtocol->SetLteEnbRrcSapProvider (rrc->GetLteEnbRrcSapProvider ());
	  rrc->SetLteEnbRrcSapUser (rrcProtocol->GetLteEnbRrcSapUser ());
	  rrc->AggregateObject (rrcProtocol);
	  rrcProtocol->SetCellId (cellId);
	}

	if (m_epcHelper != 0)
	{
	  EnumValue epsBearerToRlcMapping;
	  rrc->GetAttribute ("EpsBearerToRlcMapping", epsBearerToRlcMapping);
	  // it does not make sense to use RLC/SM when also using the EPC

// ***************** RDF EDIT 6/9/2016 ***************** //
//	  if (epsBearerToRlcMapping.Get () == LteEnbRrc::RLC_SM_ALWAYS)
//	    {
//	      rrc->SetAttribute ("EpsBearerToRlcMapping", EnumValue (LteEnbRrc::RLC_UM_ALWAYS));
//	    }

    if (m_rlcAmEnabled)
      {
        rrc->SetAttribute ("EpsBearerToRlcMapping", EnumValue (LteEnbRrc::RLC_AM_ALWAYS));
      }
      else
      {
        rrc->SetAttribute ("EpsBearerToRlcMapping", EnumValue (LteEnbRrc::RLC_UM_LOWLAT_ALWAYS));
      }
	}

	rrc->SetLteEnbCmacSapProvider (mac->GetLteEnbCmacSapProvider ());
	mac->SetLteEnbCmacSapUser (rrc->GetLteEnbCmacSapUser ());
	rrc->SetLteMacSapProvider (mac->GetLteMacSapProvider ());

	rrc->SetLteHandoverManagementSapProvider (handoverAlgorithm->GetLteHandoverManagementSapProvider ());
	handoverAlgorithm->SetLteHandoverManagementSapUser (rrc->GetLteHandoverManagementSapUser ());

	mac->SetFfMacSchedSapProvider (sched->GetFfMacSchedSapProvider ());
	mac->SetFfMacCschedSapProvider (sched->GetFfMacCschedSapProvider ());

	sched->SetFfMacSchedSapUser (mac->GetFfMacSchedSapUser ());
	sched->SetFfMacCschedSapUser (mac->GetFfMacCschedSapUser ());

	phy->SetLteEnbPhySapUser (mac->GetLteEnbPhySapUser ());
	mac->SetLteEnbPhySapProvider (phy->GetLteEnbPhySapProvider ());

	phy->SetLteEnbCphySapUser (rrc->GetLteEnbCphySapUser ());
	rrc->SetLteEnbCphySapProvider (phy->GetLteEnbCphySapProvider ());

	//FFR SAP
	sched->SetLteFfrSapProvider (ffrAlgorithm->GetLteFfrSapProvider ());
	ffrAlgorithm->SetLteFfrSapUser (sched->GetLteFfrSapUser ());

	rrc->SetLteFfrRrcSapProvider (ffrAlgorithm->GetLteFfrRrcSapProvider ());
	ffrAlgorithm->SetLteFfrRrcSapUser (rrc->GetLteFfrRrcSapUser ());
	//FFR SAP END

	Ptr<LteEnbNetDevice> dev = m_lteEnbNetDeviceFactory.Create<LteEnbNetDevice> ();
	dev->SetNode (n);
	dev->SetAttribute ("CellId", UintegerValue (cellId)); 
	dev->SetAttribute ("LteEnbPhy", PointerValue (phy));
	dev->SetAttribute ("LteEnbMac", PointerValue (mac));
	dev->SetAttribute ("FfMacScheduler", PointerValue (sched));
	dev->SetAttribute ("LteEnbRrc", PointerValue (rrc)); 
	dev->SetAttribute ("LteHandoverAlgorithm", PointerValue (handoverAlgorithm));
	dev->SetAttribute ("LteFfrAlgorithm", PointerValue (ffrAlgorithm));

	if (m_isAnrEnabled)
	{
	  Ptr<LteAnr> anr = CreateObject<LteAnr> (cellId);
	  rrc->SetLteAnrSapProvider (anr->GetLteAnrSapProvider ());
	  anr->SetLteAnrSapUser (rrc->GetLteAnrSapUser ());
	  dev->SetAttribute ("LteAnr", PointerValue (anr));
	}

	phy->SetDevice (dev);
	dlPhy->SetDevice (dev);
	ulPhy->SetDevice (dev);

	n->AddDevice (dev);
	ulPhy->SetLtePhyRxDataEndOkCallback (MakeCallback (&LteEnbPhy::PhyPduReceived, phy));
	ulPhy->SetLtePhyRxCtrlEndOkCallback (MakeCallback (&LteEnbPhy::ReceiveLteControlMessageList, phy));
	ulPhy->SetLtePhyUlHarqFeedbackCallback (MakeCallback (&LteEnbPhy::ReceiveLteUlHarqFeedback, phy));
	rrc->SetForwardUpCallback (MakeCallback (&LteEnbNetDevice::Receive, dev));

	NS_LOG_LOGIC ("set the propagation model frequencies");
	double dlFreq = LteSpectrumValueHelper::GetCarrierFrequency (dev->GetDlEarfcn ());
	NS_LOG_UNCOND ("DL freq: " << dlFreq);
	bool dlFreqOk = m_downlinkPathlossModel->SetAttributeFailSafe ("Frequency", DoubleValue (dlFreq));
	if (!dlFreqOk)
	{
	  NS_LOG_WARN ("DL propagation model does not have a Frequency attribute");
	}
	double ulFreq = LteSpectrumValueHelper::GetCarrierFrequency (dev->GetUlEarfcn ());
	NS_LOG_UNCOND ("UL freq: " << ulFreq);
	bool ulFreqOk = m_uplinkPathlossModel->SetAttributeFailSafe ("Frequency", DoubleValue (ulFreq));
	if (!ulFreqOk)
	{
	  NS_LOG_WARN ("UL propagation model does not have a Frequency attribute");
	}

	dev->Initialize ();

	m_uplinkChannel->AddRx (ulPhy);

	if (m_epcHelper != 0)
	{
	  NS_LOG_INFO ("adding this eNB to the EPC");
	  m_epcHelper->AddEnb (n, dev, dev->GetCellId ());
	  Ptr<EpcEnbApplication> enbApp = n->GetApplication (0)->GetObject<EpcEnbApplication> ();
	  NS_ASSERT_MSG (enbApp != 0, "cannot retrieve EpcEnbApplication");

	  // S1 SAPs
	  rrc->SetS1SapProvider (enbApp->GetS1SapProvider ());
	  enbApp->SetS1SapUser (rrc->GetS1SapUser ());

	  // X2 SAPs
	  Ptr<EpcX2> x2 = n->GetObject<EpcX2> ();
	  x2->SetEpcX2SapUser (rrc->GetEpcX2SapUser ());
	  rrc->SetEpcX2SapProvider (x2->GetEpcX2SapProvider ());
	  rrc->SetEpcX2PdcpProvider (x2->GetEpcX2PdcpProvider ());
	}

	return dev;
}

// only for mmWave-only devices
void
MmWaveHelper::AttachToClosestEnb (NetDeviceContainer ueDevices, NetDeviceContainer enbDevices)
{
	NS_LOG_FUNCTION(this);

	if(m_channelModelType == "ns3::MmWaveBeamforming")
	{
		m_beamforming->Initial(ueDevices,enbDevices);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelMatrix")
	{
		m_channelMatrix->Initial(ueDevices,enbDevices);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelRaytracing")
	{
		m_raytracing->Initial(ueDevices,enbDevices);
	}
	else if(m_channelModelType == "ns3::MmWave3gppChannel")
	{
		m_3gppChannel->Initial(ueDevices,enbDevices);
	}

	for (NetDeviceContainer::Iterator i = ueDevices.Begin(); i != ueDevices.End(); i++)
	{
		AttachToClosestEnb(*i, enbDevices);
	}

}

// for MC devices
void
MmWaveHelper::AttachToClosestEnb (NetDeviceContainer ueDevices, NetDeviceContainer mmWaveEnbDevices, NetDeviceContainer lteEnbDevices)
{
	NS_LOG_FUNCTION (this);

	for (NetDeviceContainer::Iterator i = ueDevices.Begin(); i != ueDevices.End(); i++)
	{
		AttachMcToClosestEnb(*i, mmWaveEnbDevices, lteEnbDevices);
	}

	if(m_channelModelType == "ns3::MmWaveBeamforming")
	{
		m_beamforming->Initial(ueDevices,mmWaveEnbDevices);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelMatrix")
	{
		m_channelMatrix->Initial(ueDevices,mmWaveEnbDevices);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelRaytracing")
	{
		m_raytracing->Initial(ueDevices,mmWaveEnbDevices);
	}
	else if(m_channelModelType == "ns3::MmWave3gppChannel")
	{
		m_3gppChannel->Initial(ueDevices,mmWaveEnbDevices);
	}
}

// for InterRatHoCapable devices
void
MmWaveHelper::AttachIrToClosestEnb (NetDeviceContainer ueDevices, NetDeviceContainer mmWaveEnbDevices, NetDeviceContainer lteEnbDevices)
{
	NS_LOG_FUNCTION (this);

	// set initial conditions on beamforming before attaching the UE to the eNBs
	if(m_channelModelType == "ns3::MmWaveBeamforming")
	{
		m_beamforming->Initial(ueDevices,mmWaveEnbDevices);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelMatrix")
	{
		m_channelMatrix->Initial(ueDevices,mmWaveEnbDevices);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelRaytracing")
	{
		m_raytracing->Initial(ueDevices,mmWaveEnbDevices);
	}
	else if(m_channelModelType == "ns3::MmWave3gppChannel")
	{
		m_3gppChannel->Initial(ueDevices,mmWaveEnbDevices);
	}

	for (NetDeviceContainer::Iterator i = ueDevices.Begin(); i != ueDevices.End(); i++)
	{
		AttachIrToClosestEnb(*i, mmWaveEnbDevices, lteEnbDevices);
	}
}

void
MmWaveHelper::AttachToClosestEnb (Ptr<NetDevice> ueDevice, NetDeviceContainer enbDevices)
{
	NS_LOG_FUNCTION (this);
	NS_ASSERT_MSG (enbDevices.GetN () > 0, "empty enb device container");
	Vector uepos = ueDevice->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
	double minDistance = std::numeric_limits<double>::infinity ();
	Ptr<NetDevice> closestEnbDevice;
	for (NetDeviceContainer::Iterator i = enbDevices.Begin (); i != enbDevices.End (); ++i)
	{
	    Vector enbpos = (*i)->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
	    double distance = CalculateDistance (uepos, enbpos);
	    if (distance < minDistance)
	    {
	        minDistance = distance;
	        closestEnbDevice = *i;
	    }
	}
	NS_ASSERT (closestEnbDevice != 0);

	Ptr<MmWaveUeNetDevice> mmWaveUe = ueDevice->GetObject<MmWaveUeNetDevice> ();



	// Necessary operation to connect MmWave UE to eNB at lower layers
  	for(NetDeviceContainer::Iterator i = enbDevices.Begin (); i != enbDevices.End(); ++i)
  	{
  		Ptr<MmWaveEnbNetDevice> mmWaveEnb = (*i)->GetObject<MmWaveEnbNetDevice> (); 
		uint16_t mmWaveCellId = mmWaveEnb->GetCellId ();
		Ptr<MmWavePhyMacCommon> configParams = mmWaveEnb->GetPhy()->GetConfigurationParameters();
		mmWaveEnb->GetPhy ()->AddUePhy (mmWaveUe->GetImsi (), ueDevice);
		// register MmWave eNBs informations in the MmWaveUePhy
		mmWaveUe->GetPhy ()->RegisterOtherEnb (mmWaveCellId, configParams, mmWaveEnb);
		//closestMmWave->GetMac ()->AssociateUeMAC (mcDevice->GetImsi ()); //TODO this does not do anything
		NS_LOG_INFO("mmWaveCellId " << mmWaveCellId);
  	}
	
	uint16_t cellId = closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetCellId ();
	Ptr<MmWavePhyMacCommon> configParams = closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetPhy()->GetConfigurationParameters();

	closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetPhy ()->AddUePhy (ueDevice->GetObject<MmWaveUeNetDevice> ()->GetImsi (), ueDevice);
	ueDevice->GetObject<MmWaveUeNetDevice> ()->GetPhy ()->RegisterToEnb (cellId, configParams);
	closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetMac ()->AssociateUeMAC (ueDevice->GetObject<MmWaveUeNetDevice> ()->GetImsi ());

	// connect to the closest one
	Ptr<EpcUeNas> ueNas = ueDevice->GetObject<MmWaveUeNetDevice> ()->GetNas ();
	ueNas->Connect (closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetCellId (),
					closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetEarfcn ());

	if (m_epcHelper != 0)
	{
		// activate default EPS bearer
		m_epcHelper->ActivateEpsBearer (ueDevice, ueDevice->GetObject<MmWaveUeNetDevice> ()->GetImsi (), EpcTft::Default (), EpsBearer (EpsBearer::NGBR_VIDEO_TCP_DEFAULT));
	}

	// tricks needed for the simplified LTE-only simulations
	//if (m_epcHelper == 0)
	//{
	ueDevice->GetObject<MmWaveUeNetDevice> ()->SetTargetEnb (closestEnbDevice->GetObject<MmWaveEnbNetDevice> ());
	//}

}

void
MmWaveHelper::AttachMcToClosestEnb (Ptr<NetDevice> ueDevice, NetDeviceContainer mmWaveEnbDevices, NetDeviceContainer lteEnbDevices)
{
	NS_LOG_FUNCTION (this);
	Ptr<McUeNetDevice> mcDevice = ueDevice->GetObject<McUeNetDevice> ();
	
	NS_ASSERT_MSG (mmWaveEnbDevices.GetN () > 0 && lteEnbDevices.GetN () > 0, 
		"empty lte or mmwave enb device container");
	
	// Find the closest LTE station
	Vector uepos = ueDevice->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
	double minDistance = std::numeric_limits<double>::infinity ();
	Ptr<NetDevice> lteClosestEnbDevice;
	for (NetDeviceContainer::Iterator i = lteEnbDevices.Begin (); i != lteEnbDevices.End (); ++i)
	{
	  Vector enbpos = (*i)->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
	  double distance = CalculateDistance (uepos, enbpos);
	  if (distance < minDistance)
	    {
	      minDistance = distance;
	      lteClosestEnbDevice = *i;
	    }
	}
	NS_ASSERT (lteClosestEnbDevice != 0);

  	// Necessary operation to connect MmWave UE to eNB at lower layers
  	for(NetDeviceContainer::Iterator i = mmWaveEnbDevices.Begin (); i != mmWaveEnbDevices.End(); ++i)
  	{
  		Ptr<MmWaveEnbNetDevice> mmWaveEnb = (*i)->GetObject<MmWaveEnbNetDevice> (); 
		uint16_t mmWaveCellId = mmWaveEnb->GetCellId ();
		Ptr<MmWavePhyMacCommon> configParams = mmWaveEnb->GetPhy()->GetConfigurationParameters();
		mmWaveEnb->GetPhy ()->AddUePhy (mcDevice->GetImsi (), ueDevice);
		// register MmWave eNBs informations in the MmWaveUePhy
		mcDevice->GetMmWavePhy ()->RegisterOtherEnb (mmWaveCellId, configParams, mmWaveEnb);
		//closestMmWave->GetMac ()->AssociateUeMAC (mcDevice->GetImsi ()); //TODO this does not do anything
		NS_LOG_INFO("mmWaveCellId " << mmWaveCellId);
  	}
	
	// Attach the MC device the LTE eNB, the best MmWave eNB will be selected automatically
	Ptr<LteEnbNetDevice> enbLteDevice = lteClosestEnbDevice->GetObject<LteEnbNetDevice> ();
	Ptr<EpcUeNas> lteUeNas = mcDevice->GetNas ();
	lteUeNas->Connect (enbLteDevice->GetCellId (), enbLteDevice->GetDlEarfcn ()); // the MmWaveCell will be automatically selected

	if (m_epcHelper != 0)
	{
	  // activate default EPS bearer
	  m_epcHelper->ActivateEpsBearer (ueDevice, lteUeNas, mcDevice->GetImsi (), EpcTft::Default (), EpsBearer (EpsBearer::NGBR_VIDEO_TCP_DEFAULT));
	}

  	mcDevice->SetLteTargetEnb (enbLteDevice);	
}

void
MmWaveHelper::AttachIrToClosestEnb (Ptr<NetDevice> ueDevice, NetDeviceContainer mmWaveEnbDevices, NetDeviceContainer lteEnbDevices)
{
	NS_LOG_FUNCTION (this);
	Ptr<McUeNetDevice> mcDevice = ueDevice->GetObject<McUeNetDevice> ();
	Ptr<LteUeRrc> ueRrc = mcDevice->GetLteRrc();

	NS_ASSERT_MSG (ueRrc != 0, "McUeDevice with undefined rrc");

	NS_ASSERT_MSG (mmWaveEnbDevices.GetN () > 0 && lteEnbDevices.GetN () > 0, 
		"empty lte or mmwave enb device container");
	
	// Find the closest LTE station
	Vector uepos = ueDevice->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
	double minDistance = std::numeric_limits<double>::infinity ();
	Ptr<NetDevice> lteClosestEnbDevice;
	for (NetDeviceContainer::Iterator i = lteEnbDevices.Begin (); i != lteEnbDevices.End (); ++i)
	{
		Ptr<LteEnbNetDevice> lteEnb = (*i)->GetObject<LteEnbNetDevice> ();
		uint16_t cellId = lteEnb->GetCellId();
		ueRrc->AddLteCellId(cellId);
		// Let the RRC know that the UE in this simulation is InterRatHoCapable
		Ptr<LteEnbRrc> enbRrc = lteEnb->GetRrc();
		enbRrc->SetInterRatHoMode();
	  	Vector enbpos = (*i)->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
	  	double distance = CalculateDistance (uepos, enbpos);
	  	if (distance < minDistance)
	    {
	      minDistance = distance;
	      lteClosestEnbDevice = *i;
	    }
	}
	NS_ASSERT (lteClosestEnbDevice != 0);

  	// Necessary operation to connect MmWave UE to eNB at lower layers
  	minDistance = std::numeric_limits<double>::infinity ();
	Ptr<NetDevice> closestEnbDevice;
  	for(NetDeviceContainer::Iterator i = mmWaveEnbDevices.Begin (); i != mmWaveEnbDevices.End(); ++i)
  	{
  		Ptr<MmWaveEnbNetDevice> mmWaveEnb = (*i)->GetObject<MmWaveEnbNetDevice> (); 
		uint16_t mmWaveCellId = mmWaveEnb->GetCellId ();
		ueRrc->AddMmWaveCellId(mmWaveCellId);
		Ptr<MmWavePhyMacCommon> configParams = mmWaveEnb->GetPhy()->GetConfigurationParameters();
		mmWaveEnb->GetPhy ()->AddUePhy (mcDevice->GetImsi (), ueDevice);
		// register MmWave eNBs informations in the MmWaveUePhy
		mcDevice->GetMmWavePhy ()->RegisterOtherEnb (mmWaveCellId, configParams, mmWaveEnb);
		//closestMmWave->GetMac ()->AssociateUeMAC (mcDevice->GetImsi ()); //TODO this does not do anything
		NS_LOG_INFO("mmWaveCellId " << mmWaveCellId);

		// Let the RRC know that the UE in this simulation is InterRatHoCapable
		Ptr<LteEnbRrc> enbRrc = mmWaveEnb->GetRrc();
		enbRrc->SetInterRatHoMode();
		Vector enbpos = (*i)->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
	    double distance = CalculateDistance (uepos, enbpos);
	    if (distance < minDistance)
	    {
	        minDistance = distance;
	        closestEnbDevice = *i;
	    }
  	}
	
	// Attach the MC device the Closest LTE eNB
	Ptr<LteEnbNetDevice> enbLteDevice = lteClosestEnbDevice->GetObject<LteEnbNetDevice> ();
	Ptr<EpcUeNas> lteUeNas = mcDevice->GetNas ();
	lteUeNas->Connect (enbLteDevice->GetCellId (), enbLteDevice->GetDlEarfcn ()); // force connection to the LTE eNB

	if (m_epcHelper != 0)
	{
	  // activate default EPS bearer
	  m_epcHelper->ActivateEpsBearer (ueDevice, lteUeNas, mcDevice->GetImsi (), EpcTft::Default (), EpsBearer (EpsBearer::NGBR_VIDEO_TCP_DEFAULT));
	}

	// set initial targets
	Ptr<MmWaveEnbNetDevice> enbDevice = closestEnbDevice->GetObject<MmWaveEnbNetDevice> ();
  	mcDevice->SetLteTargetEnb (enbLteDevice);
  	mcDevice->SetMmWaveTargetEnb (enbDevice);
}

void
MmWaveHelper::AddX2Interface (NodeContainer enbNodes)
{
  NS_LOG_FUNCTION (this);

  NS_ASSERT_MSG (m_epcHelper != 0, "X2 interfaces cannot be set up when the EPC is not used");

  for (NodeContainer::Iterator i = enbNodes.Begin (); i != enbNodes.End (); ++i)
    {
      for (NodeContainer::Iterator j = i + 1; j != enbNodes.End (); ++j)
        {
          AddX2Interface (*i, *j);
        }
    }

	// print stats
 	m_cnStats = CreateObject<CoreNetworkStatsCalculator> ();

	// add traces
  	Config::Connect ("/NodeList/*/$ns3::EpcX2/RxPDU",
    	MakeCallback (&CoreNetworkStatsCalculator::LogX2Packet, m_cnStats));
}

void
MmWaveHelper::AddX2Interface (Ptr<Node> enbNode1, Ptr<Node> enbNode2)
{
  NS_LOG_FUNCTION (this);
  NS_LOG_INFO ("setting up the X2 interface");

  m_epcHelper->AddX2Interface (enbNode1, enbNode2);
}

void
MmWaveHelper::AddX2Interface (NodeContainer lteEnbNodes, NodeContainer mmWaveEnbNodes)
{
	NS_LOG_FUNCTION(this);

	NS_ASSERT_MSG (m_epcHelper != 0, "X2 interfaces cannot be set up when the EPC is not used");

	for (NodeContainer::Iterator i = mmWaveEnbNodes.Begin (); i != mmWaveEnbNodes.End (); ++i)
    {
      for (NodeContainer::Iterator j = i + 1; j != mmWaveEnbNodes.End (); ++j)
        {
          AddX2Interface (*i, *j);
        }
    }
    for (NodeContainer::Iterator i = mmWaveEnbNodes.Begin (); i != mmWaveEnbNodes.End (); ++i)
    {
    	// get the position of the mmWave eNB
	 	Vector mmWavePos = (*i)->GetObject<MobilityModel> ()->GetPosition ();
  		double minDistance = std::numeric_limits<double>::infinity ();
  		Ptr<Node> closestLteNode;
		for (NodeContainer::Iterator j = lteEnbNodes.Begin(); j != lteEnbNodes.End (); ++j)
		{
			AddX2Interface (*i, *j);
			Vector ltePos = (*j)->GetObject<MobilityModel> ()->GetPosition ();
			double distance = CalculateDistance (mmWavePos, ltePos);
			if (distance < minDistance)
		    {
				minDistance = distance;
				closestLteNode = *j;
		    }
		}

		// get closestLteNode cellId and store it in the MmWaveEnb RRC
		Ptr<LteEnbNetDevice> closestEnbDevice = closestLteNode->GetDevice(0)->GetObject <LteEnbNetDevice> ();
		if(closestEnbDevice != 0)
		{
			uint16_t lteCellId = closestEnbDevice->GetRrc()->GetCellId();
			NS_LOG_LOGIC("ClosestLteCellId " << lteCellId);	
			(*i)->GetDevice(0)->GetObject <MmWaveEnbNetDevice> ()->GetRrc()->SetClosestLteCellId(lteCellId);
		}
		else
		{
			NS_FATAL_ERROR("LteDevice not retrieved");
		}
		
    }
    for (NodeContainer::Iterator i = lteEnbNodes.Begin (); i != lteEnbNodes.End (); ++i)
    {
      for (NodeContainer::Iterator j = i + 1; j != lteEnbNodes.End (); ++j)
        {
          AddX2Interface (*i, *j);
        }
    }
    // print stats
    if(m_cnStats == 0)
    {
	 	m_cnStats = CreateObject<CoreNetworkStatsCalculator> ();
    }
 	
	// add traces
  	Config::Connect ("/NodeList/*/$ns3::EpcX2/RxPDU",
    	MakeCallback (&CoreNetworkStatsCalculator::LogX2Packet, m_cnStats));
}

/* Call this from a script to configure the MAC PHY common parameters
 * using "SetAttribute" */
Ptr<MmWavePhyMacCommon>
MmWaveHelper::GetPhyMacConfigurable (void)
{
	return (m_phyMacCommon);
}

void
MmWaveHelper::SetPhyMacConfigurationParameters (std::string paramName, std::string value)
{
	std::stringstream ss (value);

	if (paramName.compare("CenterFreq") == 0)
	{
		double cf;
		ss >> cf;
		m_phyMacCommon->SetAttribute ("CenterFreq", DoubleValue(cf));
	}
	else if (paramName.compare("SymbolPerSlot") == 0)
	{
		uint32_t symNum;
		std::stringstream ss (value);
		ss >> symNum;
		m_phyMacCommon->SetAttribute ("SymbolPerSlot", UintegerValue(symNum));
	}
	else if (paramName.compare("SymbolLength") == 0)
	{
		double prd;
		ss >> prd;
		m_phyMacCommon->SetAttribute ("SymbolPeriod", DoubleValue(prd));
	}
	else if (paramName.compare("SlotsPerSubframe") == 0)
	{
		uint32_t slt;
		ss >> slt;
		m_phyMacCommon->SetAttribute ("SlotsPerSubframe", UintegerValue(slt));
	}
	else if (paramName.compare("SubframePerFrame") == 0)
	{
		uint32_t sf;
		ss >> sf;
		m_phyMacCommon->SetAttribute ("SubframePerFrame", UintegerValue(sf));
	}
	else if (paramName.compare("SubcarriersPerSubband") == 0)
	{
		uint32_t sc;
		ss >> sc;
		m_phyMacCommon->SetAttribute ("SubcarriersPerChunk", UintegerValue(sc));
	}
	else if (paramName.compare("SubbandPerRB") == 0)
	{
		uint32_t sb;
		ss >> sb;
		m_phyMacCommon->SetAttribute ("ChunkPerRB", UintegerValue(sb));
		m_channelMatrix->SetAttribute ("NumSubbandPerRB", UintegerValue(sb));
	}
	else if (paramName.compare("SubbandWidth") == 0)
	{
		double w;
		ss >> w;
		m_phyMacCommon->SetAttribute ("ChunkWidth", DoubleValue(w));
		m_channelMatrix->SetAttribute ("ChunkWidth", DoubleValue(w));
	}
	else if (paramName.compare("NumResourceBlock") == 0)
	{
		uint32_t rb;
		ss >> rb;
		m_phyMacCommon->SetAttribute ("ResourceBlockNum", UintegerValue(rb));
		m_channelMatrix->SetAttribute ("NumResourceBlocks", UintegerValue(rb));
	}
	else if (paramName.compare("NumReferenceSymbols") == 0)
	{
		uint32_t ref;
		ss >> ref;
		m_phyMacCommon->SetAttribute ("NumReferenceSymbols", UintegerValue(ref));

	}
	else if (paramName.compare("TDDControlDataPattern") == 0)
	{
		m_phyMacCommon->SetAttribute ("TDDPattern", StringValue (value));

	}
	else
	{
		NS_LOG_ERROR ("Unknown parameter name "<<paramName);
	}
}

void
MmWaveHelper::SetEpcHelper (Ptr<EpcHelper> epcHelper)
{
	m_epcHelper = epcHelper;
}

class MmWaveDrbActivator : public SimpleRefCount<MmWaveDrbActivator>
{
public:
  MmWaveDrbActivator (Ptr<NetDevice> ueDevice, EpsBearer bearer);
  static void ActivateCallback (Ptr<MmWaveDrbActivator> a, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti);
  void ActivateDrb (uint64_t imsi, uint16_t cellId, uint16_t rnti);
private:
  bool m_active;
  Ptr<NetDevice> m_ueDevice;
  EpsBearer m_bearer;
  uint64_t m_imsi;
};

MmWaveDrbActivator::MmWaveDrbActivator (Ptr<NetDevice> ueDevice, EpsBearer bearer)
  : m_active (false),
    m_ueDevice (ueDevice),
    m_bearer (bearer)
{
	if(m_ueDevice->GetObject< MmWaveUeNetDevice> ())
	{	// mmWave
		m_imsi = m_ueDevice->GetObject< MmWaveUeNetDevice> ()->GetImsi ();
	}
	else if (m_ueDevice->GetObject< McUeNetDevice> ())
	{
		m_imsi = m_ueDevice->GetObject< McUeNetDevice> ()->GetImsi (); // TODO support for LTE part
	}
}

void
MmWaveDrbActivator::ActivateCallback (Ptr<MmWaveDrbActivator> a, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (a << context << imsi << cellId << rnti);
  a->ActivateDrb (imsi, cellId, rnti);
}

void
MmWaveDrbActivator::ActivateDrb (uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << imsi << cellId << rnti << m_active);
  if ((!m_active) && (imsi == m_imsi))
    {
      Ptr<LteUeRrc> ueRrc = m_ueDevice->GetObject<MmWaveUeNetDevice> ()->GetRrc ();
      NS_ASSERT (ueRrc->GetState () == LteUeRrc::CONNECTED_NORMALLY);
      uint16_t rnti = ueRrc->GetRnti ();
      Ptr<MmWaveEnbNetDevice> enbLteDevice = m_ueDevice->GetObject<MmWaveUeNetDevice> ()->GetTargetEnb ();
      Ptr<LteEnbRrc> enbRrc = enbLteDevice->GetObject<MmWaveEnbNetDevice> ()->GetRrc ();
      NS_ASSERT (ueRrc->GetCellId () == enbLteDevice->GetCellId ());
      Ptr<UeManager> ueManager = enbRrc->GetUeManager (rnti);
      NS_ASSERT (ueManager->GetState () == UeManager::CONNECTED_NORMALLY ||
                 ueManager->GetState () == UeManager::CONNECTION_RECONFIGURATION);
      EpcEnbS1SapUser::DataRadioBearerSetupRequestParameters params;
      params.rnti = rnti;
      params.bearer = m_bearer;
      params.bearerId = 0;
      params.gtpTeid = 0; // don't care
      enbRrc->GetS1SapUser ()->DataRadioBearerSetupRequest (params);
      m_active = true;
    }
}

// TODO this does not support yet Mc devices
void
MmWaveHelper::ActivateDataRadioBearer (NetDeviceContainer ueDevices, EpsBearer bearer)
{
  NS_LOG_FUNCTION (this);
  for (NetDeviceContainer::Iterator i = ueDevices.Begin (); i != ueDevices.End (); ++i)
    {
      ActivateDataRadioBearer (*i, bearer);
    }
}
void
MmWaveHelper::ActivateDataRadioBearer (Ptr<NetDevice> ueDevice, EpsBearer bearer)
{
  NS_LOG_FUNCTION (this << ueDevice);
  //NS_ASSERT_MSG (m_epcHelper == 0, "this method must not be used when the EPC is being used");

  // Normally it is the EPC that takes care of activating DRBs
  // when the UE gets connected. When the EPC is not used, we achieve
  // the same behavior by hooking a dedicated DRB activation function
  // to the Enb RRC Connection Established trace source


  Ptr<MmWaveEnbNetDevice> enbmmWaveDevice = ueDevice->GetObject<MmWaveUeNetDevice> ()->GetTargetEnb ();

  std::ostringstream path;
  path << "/NodeList/" << enbmmWaveDevice->GetNode ()->GetId ()
       << "/DeviceList/" << enbmmWaveDevice->GetIfIndex ()
       << "/LteEnbRrc/ConnectionEstablished";
  Ptr<MmWaveDrbActivator> arg = Create<MmWaveDrbActivator> (ueDevice, bearer);
  Config::Connect (path.str (), MakeBoundCallback (&MmWaveDrbActivator::ActivateCallback, arg));
}


void
MmWaveHelper::EnableTraces (void)
{
	//EnableDlPhyTrace ();
	//EnableUlPhyTrace ();
	//EnableEnbPacketCountTrace ();
	//EnableUePacketCountTrace ();
	//EnableTransportBlockTrace ();
	EnableRlcTraces ();
	EnablePdcpTraces ();
	EnableMcTraces ();
}


// TODO traces for MC
void
MmWaveHelper::EnableDlPhyTrace (void)
{
	//NS_LOG_FUNCTION_NOARGS ();
	//Config::Connect ("/NodeList/*/DeviceList/*/MmWaveUePhy/ReportCurrentCellRsrpSinr",
	//		MakeBoundCallback (&MmWavePhyRxTrace::ReportCurrentCellRsrpSinrCallback, m_phyStats));

	Config::Connect ("/NodeList/*/DeviceList/*/MmWaveUePhy/DlSpectrumPhy/RxPacketTraceUe",
			MakeBoundCallback (&MmWavePhyRxTrace::RxPacketTraceUeCallback, m_phyStats));
}

void
MmWaveHelper::EnableUlPhyTrace (void)
{
	NS_LOG_FUNCTION_NOARGS ();
	Config::Connect ("/NodeList/*/DeviceList/*/MmWaveEnbPhy/DlSpectrumPhy/RxPacketTraceEnb",
			MakeBoundCallback (&MmWavePhyRxTrace::RxPacketTraceEnbCallback, m_phyStats));
}

void
MmWaveHelper::EnableEnbPacketCountTrace ()
{
	NS_LOG_FUNCTION_NOARGS ();
	Config::Connect ("/NodeList/*/DeviceList/*/MmWaveEnbPhy/DlSpectrumPhy/ReportEnbTxRxPacketCount",
			MakeBoundCallback (&MmWavePhyRxTrace::ReportPacketCountEnbCallback, m_phyStats));

}

void
MmWaveHelper::EnableUePacketCountTrace ()
{
	NS_LOG_FUNCTION_NOARGS ();
	Config::Connect ("/NodeList/*/DeviceList/*/MmWaveUePhy/DlSpectrumPhy/ReportUeTxRxPacketCount",
			MakeBoundCallback (&MmWavePhyRxTrace::ReportPacketCountUeCallback, m_phyStats));

}

void
MmWaveHelper::EnableTransportBlockTrace ()
{
	NS_LOG_FUNCTION_NOARGS ();
	Config::Connect ("/NodeList/*/DeviceList/*/MmWaveUePhy/ReportDownlinkTbSize",
				MakeBoundCallback (&MmWavePhyRxTrace::ReportDownLinkTBSize, m_phyStats));
}


void
MmWaveHelper::EnableRlcTraces (void)
{
  NS_ASSERT_MSG (m_rlcStats == 0, "please make sure that MmWaveHelper::EnableRlcTraces is called at most once");
  m_rlcStats = CreateObject<MmWaveBearerStatsCalculator> ("RLC");
  m_radioBearerStatsConnector->EnableRlcStats (m_rlcStats);
}

Ptr<MmWaveBearerStatsCalculator>
MmWaveHelper::GetRlcStats (void)
{
  return m_rlcStats;
}

void
MmWaveHelper::EnablePdcpTraces (void)
{
  NS_ASSERT_MSG (m_pdcpStats == 0, "please make sure that MmWaveHelper::EnablePdcpTraces is called at most once");
  m_pdcpStats = CreateObject<MmWaveBearerStatsCalculator> ("PDCP");
  m_radioBearerStatsConnector->EnablePdcpStats (m_pdcpStats);
}

Ptr<MmWaveBearerStatsCalculator>
MmWaveHelper::GetPdcpStats (void)
{
  return m_pdcpStats;
}

void
MmWaveHelper::EnableMcTraces (void)
{
  NS_ASSERT_MSG (m_mcStats == 0, "please make sure that MmWaveHelper::EnableMcTraces is called at most once");
  m_mcStats = CreateObject<McStatsCalculator> ();
  m_radioBearerStatsConnector->EnableMcStats (m_mcStats);
}

Ptr<McStatsCalculator>
MmWaveHelper::GetMcStats (void)
{
  return m_mcStats;
}

}

