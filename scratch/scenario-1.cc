#include <ns3/mmwave-helper.h>
#include <scratch/simulation-config/simulation-config.h>

using namespace ns3;

/*
	A number noCc continuous component carriers are created aroud the central
	frequency centerFreq. The total bandwidth bw is equally splitted among the
	CCs.
	The UE is placed in a random position along the street (0:100, -5:0, 1.6).
	The eNB is placed at (50, 50, 10). In between there are 7 random buildings.
	RLC-SM is used.
*/
int
main (int argc, char *argv[])
{
	std::string filePath = ""; // where to save the traces
	double simTime = 0.5; 		 // simulation time
	double centerFreq = 28e9;  // center frequency
	double bw = 1e9; 						 // total bandwidth
	double noCc = 1;  				 // number of CCs
	bool useBuilding = true;	 // choose the propagation loss model
	int runSet = 1;

	CommandLine cmd;
	cmd.AddValue ("centerFreq", "Central frequency", centerFreq);
	cmd.AddValue ("simTime", "Simulation time", simTime);
	cmd.AddValue ("filePath", "Where to put the output files", filePath);
	cmd.AddValue ("runSet", "Run number", runSet);
	cmd.AddValue ("noCc", "Number of CCs", noCc);
	cmd.AddValue ("bw", "Total bandwidth", bw);
	cmd.Parse (argc, argv);

	// RNG
	RngSeedManager::SetSeed (1);
	RngSeedManager::SetRun (runSet);

	SimulationConfig::SetTracesPath (filePath);

	Config::SetDefault ("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(true));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::TbDecodeLatency", UintegerValue(200.0));
  Config::SetDefault ("ns3::MmWavePhyMacCommon::NumHarqProcess", UintegerValue(100));

  //The available channel scenarios are 'RMa', 'UMa', 'UMi-StreetCanyon', 'InH-OfficeMixed', 'InH-OfficeOpen', 'InH-ShoppingMall'
  std::string scenario = "UMa";
  std::string condition = "l"; // n = NLOS, l = LOS
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::ChannelCondition", StringValue(condition));
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Scenario", StringValue(scenario));
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::OptionalNlos", BooleanValue(false));
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Shadowing", BooleanValue(false)); // enable or disable the shadowing effect
  Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::InCar", BooleanValue(false)); // enable or disable the shadowing effect

  Config::SetDefault ("ns3::MmWave3gppBuildingsPropagationLossModel::UpdateCondition", BooleanValue(true)); // enable or disable the LOS/NLOS update when the UE moves

  bool directBeam = true;
  bool is3gppRadiationPattern = true;
  
  Config::SetDefault ("ns3::MmWave3gppChannel::UpdatePeriod", TimeValue (MilliSeconds (100))); // Set channel update period, 0 stands for no update.
  Config::SetDefault ("ns3::MmWave3gppChannel::DirectBeam", BooleanValue(directBeam)); // Set true to perform the beam in the exact direction of receiver node.
  Config::SetDefault ("ns3::AntennaArrayModel::IsotropicAntennaElements", BooleanValue(!is3gppRadiationPattern));
  Config::SetDefault ("ns3::MmWave3gppChannel::PortraitMode", BooleanValue(true)); // use blockage model with UT in portrait mode
  Config::SetDefault ("ns3::MmWave3gppChannel::NumNonselfBlocking", IntegerValue(4)); // number of non-self blocking obstacles
  Config::SetDefault ("ns3::MmWave3gppChannel::BlockerSpeed", DoubleValue(1)); // speed of non-self blocking obstacles

  // Create the component carriers
	std::map<uint8_t, mmwave::MmWaveComponentCarrier> ccMap;
  for(int i = 0; i < noCc; i++)
  {
	  double ccFreq = centerFreq + bw/(2*noCc)*(2*i-noCc+1); // compute the CC frequency
	  Ptr<mmwave::MmWaveComponentCarrier> cc = SimulationConfig::CreateMmWaveCc (ccFreq,   // frequency
		 																																					 i, 		 	 // CC ID
																																							 i==0,	 	 // is primary?
																																						 	 bw/noCc); // bandwidth

		ccMap.insert(std::pair<uint8_t, mmwave::MmWaveComponentCarrier> (i, *cc));
  }

 // Create and set the helper
 // First set UseCa = true, then NumberOfComponentCarriers
 Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(noCc>1));
 Config::SetDefault("ns3::MmWaveHelper::NumberOfComponentCarriers", UintegerValue(noCc));
 Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::RrComponentCarrierManager"));
 Config::SetDefault("ns3::MmWaveHelper::ChannelModel",StringValue("ns3::MmWave3gppChannel"));
 if (useBuilding)
 {
	 Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppBuildingsPropagationLossModel"));
 }
 else
 {
	 Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppPropagationLossModel"));
 }

 Ptr<mmwave::MmWaveHelper> helper = CreateObject<mmwave::MmWaveHelper> ();
 helper->SetCcPhyParams(ccMap);

 // Create the eNB node
 NodeContainer enbNodes;
 enbNodes.Create(1);

 // Create UE node
 NodeContainer ueNodes;
 ueNodes.Create(1);

 // Set eNB mobility
 SimulationConfig::SetConstantPositionMobility (enbNodes, Vector (50.0, 50.0, 10.0));

 // Set UE mobility (random position, constant mobility)
 Ptr<UniformRandomVariable> x = CreateObject<UniformRandomVariable> ();
 x->SetAttribute ("Min", DoubleValue (0));
 x->SetAttribute ("Max", DoubleValue (100));

 Ptr<UniformRandomVariable> y = CreateObject<UniformRandomVariable> ();
 y->SetAttribute ("Min", DoubleValue (-5));
 y->SetAttribute ("Max", DoubleValue (0));

 SimulationConfig::SetConstantPositionMobility (ueNodes, Vector (x->GetValue (), y->GetValue (), 1.6));

 std::cout << "UE position " << ueNodes.Get(0)->GetObject<MobilityModel>()->GetPosition() << "\n" << std::endl;

 // Create random buildings
 RandomBuildings::CreateRandomBuildings (0, 	// street width
	 																			 20, 	// block size
																				 100, // max x-axis
																				 50,	// max y-axis
																				 7);	// number of buildings

 // Install eNB device
 NetDeviceContainer enbNetDevices = helper->InstallEnbDevice (enbNodes);

 // Install UE device
 NetDeviceContainer ueNetDevices = helper->InstallUeDevice(ueNodes);

 helper->AttachToClosestEnb (ueNetDevices, enbNetDevices);
 helper->EnableTraces();

 // Activate a data radio bearer
 enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
 EpsBearer bearer (q);
 helper->ActivateDataRadioBearer (ueNetDevices, bearer);

 BuildingsHelper::MakeMobilityModelConsistent ();
 RandomBuildings::PrintGnuplottableBuildingListToFile (filePath + "buildings.txt");

 Simulator::Stop (Seconds (simTime));
 Simulator::Run ();
 Simulator::Destroy ();

 return 0;
}
