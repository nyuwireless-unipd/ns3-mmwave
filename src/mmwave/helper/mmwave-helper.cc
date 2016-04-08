/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include <ns3/string.h>
#include <ns3/log.h>
#include <ns3/abort.h>
#include <ns3/pointer.h>
#include <iostream>
#include <string>
#include <sstream>
#include "mmwave-helper.h"
#include <ns3/abort.h>
#include <ns3/buildings-propagation-loss-model.h>
#include <ns3/multi-model-spectrum-channel.h>
#include <ns3/uinteger.h>
#include <ns3/double.h>
#include <ns3/ipv4.h>
#include <ns3/mmwave-rrc-protocol-ideal.h>
#include <ns3/lte-rrc-protocol-real.h>
#include <ns3/epc-enb-application.h>
#include <ns3/epc-x2.h>
#include <ns3/buildings-obstacle-propagation-loss-model.h>

#include <ns3/friis-spectrum-propagation-loss.h>
#include <ns3/lte-rrc-protocol-ideal.h>
#include <ns3/lte-spectrum-phy.h>
#include <ns3/lte-chunk-processor.h>
#include <ns3/isotropic-antenna-model.h>


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
	 m_useIdealRrc (true)
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

	if(m_channelModelType == "ns3::MmWaveBeamforming")
	{
		m_beamforming = CreateObject<MmWaveBeamforming> (m_noTxAntenna, m_noRxAntenna);
		m_channel->AddSpectrumPropagationLossModel (m_beamforming);
		m_beamforming->SetCofigurationParameters (m_phyMacCommon);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelMatrix")
	{
		m_channelMatrix = CreateObject<MmWaveChannelMatrix> ();
		m_channel->AddSpectrumPropagationLossModel (m_channelMatrix);
		m_channelMatrix->SetCofigurationParameters (m_phyMacCommon);
	}
	else if(m_channelModelType == "ns3::MmWaveChannelRaytracing")
	{
		m_raytracing = CreateObject<MmWaveChannelRaytracing> ();
		m_channel->AddSpectrumPropagationLossModel (m_raytracing);
		m_raytracing->SetCofigurationParameters (m_phyMacCommon);
	}

	if (!m_pathlossModelType.empty ())
	{
		m_pathlossModel = m_pathlossModelFactory.Create ();
		Ptr<PropagationLossModel> splm = m_pathlossModel->GetObject<PropagationLossModel> ();
		if( splm )
		{
			NS_LOG_LOGIC (this << " using a PropagationLossModel");
			m_channel->AddPropagationLossModel (splm);
		}

		if (m_pathlossModel->GetObject<BuildingsObstaclePropagationLossModel> ())
		{
			Ptr<BuildingsObstaclePropagationLossModel> building = m_pathlossModel->GetObject<BuildingsObstaclePropagationLossModel> ();
			building->SetBeamforming (m_beamforming);
		}
	}
	else
	{
		NS_LOG_UNCOND (this << " No PropagationLossModel!");
	}

	m_phyStats = CreateObject<MmWavePhyRxTrace> ();

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

	if (m_useIdealRrc)
	{
		Ptr<mmWaveUeRrcProtocolIdeal> rrcProtocol = CreateObject<mmWaveUeRrcProtocolIdeal> ();
		rrcProtocol->SetUeRrc (mmWaveRrc);
		mmWaveRrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (mmWaveRrc->GetLteUeRrcSapProvider ());
		mmWaveRrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}
	else
	{
		Ptr<LteUeRrcProtocolReal> rrcProtocol = CreateObject<LteUeRrcProtocolReal> ();
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
	Ptr<EpcUeNas> mmWaveNas = CreateObject<EpcUeNas> ();
	mmWaveNas->SetAsSapProvider (mmWaveRrc->GetAsSapProvider ());
	mmWaveRrc->SetAsSapUser (mmWaveNas->GetAsSapUser ());

	mmWaveRrc->SetLteUeCmacSapProvider (mmWaveMac->GetUeCmacSapProvider ());
	mmWaveMac->SetUeCmacSapUser (mmWaveRrc->GetLteUeCmacSapUser ());
	mmWaveRrc->SetLteMacSapProvider (mmWaveMac->GetUeMacSapProvider ());

	mmWavePhy->SetUeCphySapUser (mmWaveRrc->GetLteUeCphySapUser ());
	mmWaveRrc->SetLteUeCphySapProvider (mmWavePhy->GetUeCphySapProvider ());

	NS_ABORT_MSG_IF (m_imsiCounter >= 0xFFFFFFFF, "max num UEs exceeded");
	uint64_t mmWaveImsi = ++m_imsiCounter;

	mmWavePhy->SetCofigurationParameters (m_phyMacCommon);
	mmWaveMac->SetCofigurationParameters (m_phyMacCommon);

	mmWavePhy->SetPhySapUser (mmWaveMac->GetPhySapUser());
	mmWaveMac->SetPhySapProvider (mmWavePhy->GetPhySapProvider());

	device->SetNode(n);
	device->SetAttribute ("MmWaveImsi", UintegerValue(mmWaveImsi));
	device->SetAttribute ("MmWaveUePhy", PointerValue(mmWavePhy));
	device->SetAttribute ("MmWaveUeMac", PointerValue(mmWaveMac));
	device->SetAttribute ("EpcUeNas", PointerValue (mmWaveNas));
	device->SetAttribute ("MmWaveUeRrc", PointerValue (mmWaveRrc));

	mmWavePhy->SetDevice (device);
	mmWavePhy->SetImsi (mmWaveImsi); 
	//mmWavePhy->SetForwardUpCallback (MakeCallback (&McUeNetDevice::Receive, device));
	mmWaveDlPhy->SetDevice(device);
	mmWaveUlPhy->SetDevice(device);
	mmWaveNas->SetDevice(device);


	mmWaveDlPhy->SetPhyRxDataEndOkCallback (MakeCallback (&MmWaveUePhy::PhyDataPacketReceived, mmWavePhy));
	mmWaveDlPhy->SetPhyRxCtrlEndOkCallback (MakeCallback (&MmWaveUePhy::ReceiveControlMessageList, mmWavePhy));
	mmWaveNas->SetForwardUpCallback (MakeCallback (&McUeNetDevice::Receive, device));
	if (m_epcHelper != 0)
	{
		m_epcHelper->AddUe (device, device->GetMmWaveImsi ());
	}

	// ----------------------- LTE stack ----------------------

	Ptr<LteUeMac> lteMac = CreateObject<LteUeMac> ();
	Ptr<LteUeRrc> lteRrc = CreateObject<LteUeRrc> ();

	if (m_useIdealRrc)
	{
		Ptr<LteUeRrcProtocolIdeal> rrcProtocol = CreateObject<LteUeRrcProtocolIdeal> ();
		rrcProtocol->SetUeRrc (lteRrc);
		lteRrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (lteRrc->GetLteUeRrcSapProvider ());
		lteRrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}
	else
	{
		Ptr<LteUeRrcProtocolReal> rrcProtocol = CreateObject<LteUeRrcProtocolReal> ();
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
	lteRrc->SetAsSapUser (lteNas->GetAsSapUser ());

	lteRrc->SetLteUeCmacSapProvider (lteMac->GetLteUeCmacSapProvider ());
	lteMac->SetLteUeCmacSapUser (lteRrc->GetLteUeCmacSapUser ());
	lteRrc->SetLteMacSapProvider (lteMac->GetLteMacSapProvider ());

	ltePhy->SetLteUePhySapUser (lteMac->GetLteUePhySapUser ());
	lteMac->SetLteUePhySapProvider (ltePhy->GetLteUePhySapProvider ());

	ltePhy->SetLteUeCphySapUser (lteRrc->GetLteUeCphySapUser ());
	lteRrc->SetLteUeCphySapProvider (ltePhy->GetLteUeCphySapProvider ());

	NS_ABORT_MSG_IF (m_imsiCounter >= 0xFFFFFFFF, "max num UEs exceeded");
	uint64_t lteImsi = ++m_imsiCounter;

	device->SetAttribute ("LteImsi", UintegerValue (lteImsi));
	device->SetAttribute ("LteUePhy", PointerValue (ltePhy));
	device->SetAttribute ("LteUeMac", PointerValue (lteMac));
	device->SetAttribute ("LteUeRrc", PointerValue (lteRrc));
	device->SetAttribute ("LteEpcUeNas", PointerValue (lteNas));

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
		m_epcHelper->AddUe (device, device->GetLteImsi ());
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
	 * phy->SetCofigurationParameters(m_phyMacCommon);*/

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
		Ptr<mmWaveUeRrcProtocolIdeal> rrcProtocol = CreateObject<mmWaveUeRrcProtocolIdeal> ();
		rrcProtocol->SetUeRrc (rrc);
		rrc->AggregateObject (rrcProtocol);
		rrcProtocol->SetLteUeRrcSapProvider (rrc->GetLteUeRrcSapProvider ());
		rrc->SetLteUeRrcSapUser (rrcProtocol->GetLteUeRrcSapUser ());
	}
	else
	{
		Ptr<LteUeRrcProtocolReal> rrcProtocol = CreateObject<LteUeRrcProtocolReal> ();
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

	phy->SetCofigurationParameters (m_phyMacCommon);
	mac->SetCofigurationParameters (m_phyMacCommon);

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

	phy->SetCofigurationParameters(m_phyMacCommon);

	ulPhy->SetChannel (m_channel);
	dlPhy->SetChannel (m_channel);

	Ptr<MobilityModel> mm = n->GetObject<MobilityModel> ();
	NS_ASSERT_MSG (mm, "MobilityModel needs to be set on node before calling MmWaveHelper::InstallEnbDevice ()");
	ulPhy->SetMobility (mm);
	dlPhy->SetMobility (mm);

	/* Antenna model */
	Ptr<AntennaModel> antenna = (m_enbAntennaModelFactory.Create ())->GetObject<AntennaModel> ();
	NS_ASSERT_MSG (antenna, "error in creating the AntennaModel object");
	dlPhy->SetAntenna (antenna);
	ulPhy->SetAntenna (antenna);

	Ptr<MmWaveEnbMac> mac = CreateObject<MmWaveEnbMac> ();
	mac->SetCofigurationParameters (m_phyMacCommon);
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
		Ptr<LteEnbRrcProtocolReal> rrcProtocol = CreateObject<LteEnbRrcProtocolReal> ();
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
	phy->SetmmWaveEnbCphySapUser (rrc->GetLteEnbCphySapUser ());
	rrc->SetLteEnbCphySapProvider (phy->GetmmWaveEnbCphySapProvider ());

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

	dlPhy->SetPhyRxDataEndOkCallback (MakeCallback (&MmWaveEnbPhy::PhyDataPacketReceived, phy));
	dlPhy->SetPhyRxCtrlEndOkCallback (MakeCallback (&MmWaveEnbPhy::PhyCtrlMessagesReceived, phy));
  	dlPhy->SetPhyUlHarqFeedbackCallback (MakeCallback (&MmWaveEnbPhy::ReceiveUlHarqFeedback, phy));

	//mac->SetForwardUpCallback (MakeCallback (&MmWaveEnbNetDevice::Receive, device));
	rrc->SetForwardUpCallback (MakeCallback (&MmWaveEnbNetDevice::Receive, device));


	NS_LOG_LOGIC ("set the propagation model frequencies");
	double freq = m_phyMacCommon->GetCentreFrequency ();
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
	  Ptr<LteEnbRrcProtocolIdeal> rrcProtocol = CreateObject<LteEnbRrcProtocolIdeal> ();
	  rrcProtocol->SetLteEnbRrcSapProvider (rrc->GetLteEnbRrcSapProvider ());
	  rrc->SetLteEnbRrcSapUser (rrcProtocol->GetLteEnbRrcSapUser ());
	  rrc->AggregateObject (rrcProtocol);
	  rrcProtocol->SetCellId (cellId);
	}
	else
	{
	  Ptr<LteEnbRrcProtocolReal> rrcProtocol = CreateObject<LteEnbRrcProtocolReal> ();
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
	      rrc->SetAttribute ("EpsBearerToRlcMapping", EnumValue (LteEnbRrc::RLC_UM_ALWAYS));
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
	NS_LOG_LOGIC ("DL freq: " << dlFreq);
	bool dlFreqOk = m_downlinkPathlossModel->SetAttributeFailSafe ("Frequency", DoubleValue (dlFreq));
	if (!dlFreqOk)
	{
	  NS_LOG_WARN ("DL propagation model does not have a Frequency attribute");
	}
	double ulFreq = LteSpectrumValueHelper::GetCarrierFrequency (dev->GetUlEarfcn ());
	NS_LOG_LOGIC ("UL freq: " << ulFreq);
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
	}

	return dev;
}

// only for mmWave-only devices
void
MmWaveHelper::AttachToClosestEnb (NetDeviceContainer ueDevices, NetDeviceContainer enbDevices)
{
	NS_LOG_FUNCTION(this);

	for (NetDeviceContainer::Iterator i = ueDevices.Begin(); i != ueDevices.End(); i++)
	{
		AttachToClosestEnb(*i, enbDevices);
	}

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

	uint16_t cellId = closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetCellId ();
	Ptr<MmWavePhyMacCommon> configParams = closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetPhy()->GetConfigurationParameters();

	closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetPhy ()->AddUePhy (ueDevice->GetObject<MmWaveUeNetDevice> ()->GetImsi (), ueDevice);
	ueDevice->GetObject<MmWaveUeNetDevice> ()->GetPhy ()->RegisterToEnb (cellId, configParams);
	closestEnbDevice->GetObject<MmWaveEnbNetDevice> ()->GetMac ()->AssociateUeMAC (ueDevice->GetObject<MmWaveUeNetDevice> ()->GetImsi ());

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
	
	// Find the closest mmWave station	
	Vector uepos = ueDevice->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();
	double minDistance = std::numeric_limits<double>::infinity ();
	Ptr<NetDevice> closestEnbDevice;
	for (NetDeviceContainer::Iterator i = mmWaveEnbDevices.Begin (); i != mmWaveEnbDevices.End (); ++i)
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

	// Attach the MC device to the MmWave eNB
	Ptr<MmWaveEnbNetDevice> closestMmWave = closestEnbDevice->GetObject<MmWaveEnbNetDevice> (); 
	uint16_t mmWaveCellId = closestMmWave->GetCellId ();
	Ptr<MmWavePhyMacCommon> configParams = closestMmWave->GetPhy()->GetConfigurationParameters();

	closestMmWave->GetPhy ()->AddUePhy (mcDevice->GetMmWaveImsi (), ueDevice);
	mcDevice->GetMmWavePhy ()->RegisterToEnb (mmWaveCellId, configParams);
	closestMmWave->GetMac ()->AssociateUeMAC (mcDevice->GetMmWaveImsi ());

	Ptr<EpcUeNas> ueNas = mcDevice->GetMmWaveNas (); // TODO once there is only one PDCP, there will be one NAS
	ueNas->Connect (mmWaveCellId,
					closestMmWave->GetEarfcn ());

	if (m_epcHelper != 0)
	{
		// activate default EPS bearer
		m_epcHelper->ActivateEpsBearer (ueDevice, ueNas, mcDevice->GetMmWaveImsi (), EpcTft::Default (), EpsBearer (EpsBearer::NGBR_VIDEO_TCP_DEFAULT));
	}

	mcDevice->SetMmWaveTargetEnb (closestMmWave);

	// Find the closest LTE station
	minDistance = std::numeric_limits<double>::infinity ();
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

	// Attach the MC device the LTE eNB
	Ptr<LteEnbNetDevice> enbLteDevice = lteClosestEnbDevice->GetObject<LteEnbNetDevice> ();
	Ptr<EpcUeNas> lteUeNas = mcDevice->GetLteNas ();
	lteUeNas->Connect (enbLteDevice->GetCellId (), enbLteDevice->GetDlEarfcn ());

	if (m_epcHelper != 0)
	{
	  // activate default EPS bearer
	  m_epcHelper->ActivateEpsBearer (ueDevice, lteUeNas, mcDevice->GetLteImsi (), EpcTft::Default (), EpsBearer (EpsBearer::NGBR_VIDEO_TCP_DEFAULT));
	}

  	mcDevice->SetLteTargetEnb (enbLteDevice);
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
}

void
MmWaveHelper::AddX2Interface (Ptr<Node> enbNode1, Ptr<Node> enbNode2)
{
  NS_LOG_FUNCTION (this);
  NS_LOG_INFO ("setting up the X2 interface");

  m_epcHelper->AddX2Interface (enbNode1, enbNode2);
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

	if (paramName.compare("CentreFreq") == 0)
	{
		double cf;
		ss >> cf;
		m_phyMacCommon->SetAttribute ("CentreFreq", DoubleValue(cf));
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

class DrbActivator : public SimpleRefCount<DrbActivator>
{
public:
  DrbActivator (Ptr<NetDevice> ueDevice, EpsBearer bearer);
  static void ActivateCallback (Ptr<DrbActivator> a, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti);
  void ActivateDrb (uint64_t imsi, uint16_t cellId, uint16_t rnti);
private:
  bool m_active;
  Ptr<NetDevice> m_ueDevice;
  EpsBearer m_bearer;
  uint64_t m_imsi;
};

DrbActivator::DrbActivator (Ptr<NetDevice> ueDevice, EpsBearer bearer)
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
		m_imsi = m_ueDevice->GetObject< McUeNetDevice> ()->GetMmWaveImsi (); // TODO support for LTE part
	}
}

void
DrbActivator::ActivateCallback (Ptr<DrbActivator> a, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (a << context << imsi << cellId << rnti);
  a->ActivateDrb (imsi, cellId, rnti);
}

void
DrbActivator::ActivateDrb (uint64_t imsi, uint16_t cellId, uint16_t rnti)
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
  Ptr<DrbActivator> arg = Create<DrbActivator> (ueDevice, bearer);
  Config::Connect (path.str (), MakeBoundCallback (&DrbActivator::ActivateCallback, arg));
}


void
MmWaveHelper::EnableTraces (void)
{
	EnableDlPhyTrace ();
	EnableUlPhyTrace ();
	//EnableEnbPacketCountTrace ();
	//EnableUePacketCountTrace ();
	//EnableTransportBlockTrace ();
	EnableRlcTraces ();
	EnablePdcpTraces ();
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
  m_radioBearerStatsConnector.EnableRlcStats (m_rlcStats);
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
  m_radioBearerStatsConnector.EnablePdcpStats (m_pdcpStats);
}

Ptr<MmWaveBearerStatsCalculator>
MmWaveHelper::GetPdcpStats (void)
{
  return m_pdcpStats;
}

}

