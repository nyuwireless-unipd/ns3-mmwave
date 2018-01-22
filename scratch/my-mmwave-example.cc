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
#include "ns3/global-route-manager.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/log.h"
#include <map>

using namespace ns3;

int
main (int argc, char *argv[])
{
	//create MmWavePhyMacCommon objects
	Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(28e9));
	Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(0));
	Ptr<MmWavePhyMacCommon> phyMacConfig1 = CreateObject<MmWavePhyMacCommon> ();

	Config::SetDefault("ns3::MmWavePhyMacCommon::CenterFreq",DoubleValue(73e9));
	Config::SetDefault("ns3::MmWavePhyMacCommon::ComponentCarrierId", UintegerValue(1));
	Ptr<MmWavePhyMacCommon> phyMacConfig2 = CreateObject<MmWavePhyMacCommon> ();

	//create the carriers
	Ptr<MmWaveComponentCarrier> cc1 = CreateObject<MmWaveComponentCarrier> ();
	cc1->SetConfigurationParameters(phyMacConfig1);
	cc1->SetAsPrimary(true);

	Ptr<MmWaveComponentCarrier> cc2 = CreateObject<MmWaveComponentCarrier> ();
	cc2->SetConfigurationParameters(phyMacConfig2);
	cc2->SetAsPrimary(false);

	std::cout << "Component Carrier " << std::to_string(phyMacConfig1->GetCcId ()) << " frequency : " << cc1->GetCenterFrequency() << std::endl;
	std::cout << "Component Carrier " << std::to_string(phyMacConfig2->GetCcId ()) << " frequency : " << cc2->GetCenterFrequency() << std::endl;

	//create the ccMap
	std::map<uint8_t, MmWaveComponentCarrier > ccMap;
	ccMap [0] = *cc1;
	ccMap [1] = *cc2;

	//create and set the helper
	//first set UseCa = true, then NumberOfComponentCarriers
	Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(true));
	Config::SetDefault("ns3::MmWaveHelper::NumberOfComponentCarriers",UintegerValue(2));
	Config::SetDefault("ns3::MmWaveHelper::EnbComponentCarrierManager",StringValue ("ns3::RrComponentCarrierManager"));
	Config::SetDefault("ns3::MmWaveHelper::ChannelModel",StringValue("ns3::MmWave3gppChannel"));
	Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppPropagationLossModel"));
	Ptr<MmWaveHelper> helper = CreateObject<MmWaveHelper> ();
	helper->SetCcPhyParams(ccMap);

	//create the enb node
	NodeContainer enbNodes;
	enbNodes.Create(1);

	//set mobility
	Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator> ();
  enbPositionAlloc->Add (Vector (0.0, 0.0, 30.0));

  MobilityHelper enbmobility;
  enbmobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  enbmobility.SetPositionAllocator(enbPositionAlloc);
  enbmobility.Install (enbNodes);
  BuildingsHelper::Install (enbNodes);

	//install enb device
	NetDeviceContainer enbNetDevices = helper->InstallEnbDevice (enbNodes);
	std::cout<< "enb dev installed" << std::endl;

	//create ue node
	NodeContainer ueNodes;
	ueNodes.Create(1);

	//set mobility
	MobilityHelper uemobility;
  Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator> ();
  uePositionAlloc->Add (Vector (80.0, 0.0, 5.0));

  uemobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  uemobility.SetPositionAllocator(uePositionAlloc);
  uemobility.Install (ueNodes);
  BuildingsHelper::Install (ueNodes);

	//install ue device
	NetDeviceContainer ueNetDevices = helper->InstallUeDevice(ueNodes);
	std::cout<< "ue dev installed" << std::endl;

	//test
	Ptr<NetDevice> enbDev = enbNodes.Get(0)->GetDevice(0);
	Ptr<MmWaveEnbNetDevice> mmWaveEnbDev = DynamicCast<MmWaveEnbNetDevice>(enbDev);
	std::map < uint8_t, Ptr<MmWaveComponentCarrierEnb> > enbCcMap = mmWaveEnbDev->GetCcMap();
	Ptr<MmWaveComponentCarrierEnb> enbCC1 = enbCcMap.at(0);
	Ptr<AntennaModel> enbCC1Antenna = enbCC1->GetPhy ()->GetDlSpectrumPhy ()->GetRxAntenna ();
	Ptr<AntennaArrayModel> enbCC1AntennaArray = DynamicCast<AntennaArrayModel> (enbCC1Antenna);
	std::cout << "Enb CC 1 " << enbCC1 << "has antenna " << enbCC1Antenna << std::endl;

	helper->AttachToClosestEnb (ueNetDevices, enbNetDevices);
	helper->EnableTraces();

	// Activate a data radio bearer
	enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
	EpsBearer bearer (q);
	helper->ActivateDataRadioBearer (ueNetDevices, bearer);

	Simulator::Stop (Seconds (0.4));
  Simulator::Run ();
  Simulator::Destroy ();

  return 0;
}
