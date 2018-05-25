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
 Ptr<mmwave::MmWavePhyMacCommon> phyMacConfig1 = CreateObject<mmwave::MmWavePhyMacCommon> ();

 //create the carrier
 Ptr<mmwave::MmWaveComponentCarrier> cc1 = CreateObject<mmwave::MmWaveComponentCarrier> ();
 cc1->SetConfigurationParameters(phyMacConfig1);
 cc1->SetAsPrimary(true);

 std::cout << "PCC frequency 1: " << cc1->GetCenterFrequency() << std::endl;

 //create the ccMap
 std::map<uint8_t, mmwave::MmWaveComponentCarrier > ccMap;
 ccMap [0] = *cc1;

 //create and set the helper
 Config::SetDefault("ns3::MmWaveHelper::UseIdealRrc",BooleanValue(false));
 Config::SetDefault("ns3::MmWaveHelper::UseCa",BooleanValue(false));
 Config::SetDefault("ns3::MmWaveHelper::ChannelModel",StringValue("ns3::MmWave3gppChannel"));
 Config::SetDefault("ns3::MmWaveHelper::PathlossModel",StringValue("ns3::MmWave3gppPropagationLossModel"));

 Ptr<mmwave::MmWaveHelper> helper = CreateObject<mmwave::MmWaveHelper> ();
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

 helper->AttachToClosestEnb (ueNetDevices, enbNetDevices);
 helper->EnableTraces();

 // Activate a data radio bearer
 enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
 EpsBearer bearer (q);
 helper->ActivateDataRadioBearer (ueNetDevices, bearer);

/*
 std::cout << "ue spectrum cellid " << ueNetDevices.Get(0)->GetObject<MmWaveUeNetDevice>()->GetPhy()->GetDlSpectrumPhy()->GetCellId() << std::endl;
 std::cout << "enb spectrum cellid " << enbNetDevices.Get(0)->GetObject<MmWaveEnbNetDevice>()->GetPhy()->GetDlSpectrumPhy()->GetCellId() << std::endl;
 std::cout << "enb net device cell id " << enbNetDevices.Get(0)->GetObject<MmWaveEnbNetDevice>()->GetCellId() << std::endl;

 std::cout << "ue net device " << ueNetDevices.Get(0)->GetObject<MmWaveUeNetDevice>()->GetPhy()->GetDlSpectrumPhy() << std::endl;
 std::cout << "enb net device " << enbNetDevices.Get(0)->GetObject<MmWaveEnbNetDevice>()->GetPhy()->GetDlSpectrumPhy() << std::endl;
*/
 Simulator::Stop (Seconds (0.5));
 Simulator::Run ();
 Simulator::Destroy ();

 return 0;
}
