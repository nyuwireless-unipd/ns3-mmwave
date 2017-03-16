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


#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/config-store.h"
#include "ns3/mmwave-helper.h"
#include <ns3/buildings-helper.h>
#include "ns3/log.h"
#include <ns3/buildings-module.h>

using namespace ns3;

void
TraceBuildingLoc()
{
	//Write the location of buildings.
	static bool firstTitme = true;
	if(firstTitme)
	{
		firstTitme = false;
		std::ofstream outFile;
		outFile.open ("building.txt");
		if (!outFile.is_open ())
		{
		  NS_FATAL_ERROR ("Can't open file building.txt");
		}
		for (BuildingList::Iterator bit = BuildingList::Begin (); bit != BuildingList::End (); ++bit)
		{
			Box boundaries = (*bit)->GetBoundaries ();
			outFile << boundaries.xMin<< "\t";
			outFile << boundaries.xMax<< "\t";
			outFile << boundaries.yMin<< "\t";
			outFile << boundaries.yMax<< "\t";
			outFile << boundaries.zMin<< "\t";
			outFile << boundaries.zMax << std::endl;
		}
		outFile.close ();
	}
}

int 
main (int argc, char *argv[])
{
	// This 3GPP channel model example only demonstrate the pathloss model. The fast fading model is still in developing.

	//The available channel scenarios are 'RMa', 'UMa', 'UMi-StreetCanyon', 'InH-OfficeMixed', 'InH-OfficeOpen', 'InH-ShoppingMall'
	std::string scenario = "RMa";
	//'l' for LOS only, 'n' for NLOS only, 'a' for all conditions determined by probability driven model.
	std::string condition = "a";
	//double startDistance = 0; //the start 2D distance in meters.
	//double stopDistance = 1000; //the stop 2D distance in meters.

	bool optionNlos = false; //enable the optional NLOS propagation loss model.
	bool enableBuildings = false;

  CommandLine cmd;
  cmd.AddValue("scenario", "channel scenarios", scenario);
  cmd.AddValue("condition", "channel condition", condition);
  cmd.AddValue("optionNlos", "optional NLOS pathloss", optionNlos);

  cmd.Parse (argc, argv);
  //LogComponentEnable ("MmWave3gppPropagationLossModel", LOG_LEVEL_ALL);


	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::ChannelCondition", StringValue(condition));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Scenario", StringValue(scenario));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::OptionalNlos", BooleanValue(optionNlos));
	Config::SetDefault ("ns3::MmWave3gppPropagationLossModel::Shadowing", BooleanValue(false)); // enable or disable the shadowing effect

  Config::SetDefault ("ns3::MmWave3gppChannel::UpdatePeriod", TimeValue (MilliSeconds (100))); // Set channel update period, 0 stands for no update.
  Config::SetDefault ("ns3::MmWave3gppChannel::CellScan", BooleanValue(false)); // Set true to use cell scanning method, false to use the default power method.
  Config::SetDefault ("ns3::MmWave3gppChannel::Blockage", BooleanValue(false)); // use blockage or not
  Config::SetDefault ("ns3::MmWave3gppChannel::PortraitMode", BooleanValue(true)); // use blockage model with UT in portrait mode
  Config::SetDefault ("ns3::MmWave3gppChannel::NumNonselfBlocking", IntegerValue(4)); // number of non-self blocking obstacles
  Config::SetDefault ("ns3::MmWave3gppChannel::BlockerSpeed", DoubleValue(0)); // speed of non-self blocking obstacles

	double hBS = 0; //base station antenna height in meters;
	double hUT = 0; //user antenna height in meters;
  if(scenario.compare("RMa")==0)
  {
	hBS = 35;
	hUT = 1.5;
  }
  else if(scenario.compare("UMa")==0)
  {
	hBS = 25;
	hUT = 1.5;
  }
  else if (scenario.compare("UMi-StreetCanyon")==0)
  {
	hBS = 10;
	hUT = 1.5;
  }
  else if (scenario.compare("InH-OfficeMixed")==0 || scenario.compare("InH-OfficeOpen")==0 || scenario.compare("InH-ShoppingMall")==0)
  {
	hBS = 3;
	hUT = 1;
  }
  else
  {
	  std::cout<<"Unkown scenario.\n";
	  return 1;
  }

  Ptr<MmWaveHelper> mmWaveHelper = CreateObject<MmWaveHelper> ();

  if(enableBuildings)
  {
	  mmWaveHelper->SetAttribute ("PathlossModel", StringValue ("ns3::MmWave3gppBuildingsPropagationLossModel"));
  }
  else
  {
	  mmWaveHelper->SetAttribute ("PathlossModel", StringValue ("ns3::MmWave3gppPropagationLossModel"));
  }
  mmWaveHelper->SetAttribute ("ChannelModel", StringValue ("ns3::MmWave3gppChannel"));

  mmWaveHelper->Initialize();


  NodeContainer enbNodes;
  NodeContainer ueNodes;
  enbNodes.Create (1);
  ueNodes.Create (1);

  if(enableBuildings)
  {
		Ptr < Building > building1;
		building1 = Create<Building> ();
		building1->SetBoundaries (Box (50.0,60.0,
									0.0, 10,
									0.0, 20));
		Ptr < Building > building2;
		building2 = Create<Building> ();
		building2->SetBoundaries (Box (50.0,60.0,
									10.0, 30,
									0.0, 9));
		Ptr < Building > building3;
		building3 = Create<Building> ();
		building3->SetBoundaries (Box (10.0,40.0,
									30.0, 40,
									0.0, 50));

		Ptr < Building > building4;
		building4 = Create<Building> ();
		building4->SetBoundaries (Box (30.0,70.0,
									60.0, 80,
									0.0, 20));
  }

  Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector (0.0, 0.0, hBS));
  enbPositionAlloc->Add (Vector (0.0, 80.0, hBS));

  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator(enbPositionAlloc);
  enbmobility.Install (enbNodes);


  MobilityHelper uemobility;
  uemobility.SetMobilityModel ("ns3::ConstantVelocityMobilityModel");
  uemobility.Install (ueNodes);

  if(enableBuildings)
  {
	  BuildingsHelper::Install (enbNodes);
	  BuildingsHelper::Install (ueNodes);
  }
  //ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (startDistance, 0.0, hUT));
  //ueNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector ((stopDistance-startDistance), 0, 0));


  ueNodes.Get (0)->GetObject<MobilityModel> ()->SetPosition (Vector (100, 0, hUT));
  ueNodes.Get (0)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (0, 1, 0));

  //ueNodes.Get (1)->GetObject<MobilityModel> ()->SetPosition (Vector (25, 50.0, hUT));
  //ueNodes.Get (1)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector (-20, 0, 0));
  //ueNodes.Get (1)->GetObject<ConstantVelocityMobilityModel> ()->SetVelocity (Vector ((stopDistance-startDistance), 0, 0));

  NetDeviceContainer enbNetDev = mmWaveHelper->InstallEnbDevice (enbNodes);
  NetDeviceContainer ueNetDev = mmWaveHelper->InstallUeDevice (ueNodes);


  mmWaveHelper->AttachToClosestEnb (ueNetDev, enbNetDev);
  mmWaveHelper->EnableTraces();

  // Activate a data radio bearer
  enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VIDEO;
  EpsBearer bearer (q);
  mmWaveHelper->ActivateDataRadioBearer (ueNetDev, bearer);
  if(enableBuildings)
  {
	  BuildingsHelper::MakeMobilityModelConsistent ();
	  TraceBuildingLoc();
  }


  Simulator::Stop (Seconds (1));
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}


