/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2020 University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 */

#include "ns3/config-store.h"
#include "ns3/core-module.h"
#include "ns3/log.h"
#include "ns3/mmwave-helper.h"
#include "ns3/mobility-module.h"
#include "ns3/uinteger.h"
#include <ns3/buildings-helper.h>
#include <ns3/buildings-module.h>

using namespace ns3;
using namespace mmwave;

/*
 * This example shows how to cofigure the beamforming model to use a codebook.
 * The scenario is the same as in mmwave-simple-building-obstacle.cc.
 */
int
main(int argc, char* argv[])
{
    CommandLine cmd;
    cmd.Parse(argc, argv);

    Ptr<MmWaveHelper> ptr_mmWave = CreateObject<MmWaveHelper>();
    ptr_mmWave->SetChannelConditionModelType("ns3::BuildingsChannelConditionModel");

    // select the beamforming model
    ptr_mmWave->SetBeamformingModelType("ns3::MmWaveCodebookBeamforming");

    // configure the UE antennas:
    // 1. specify the path of the file containing the codebook
    ptr_mmWave->SetUeBeamformingCodebookAttribute(
        "CodebookFilename",
        StringValue("src/mmwave/model/Codebooks/1x2.txt"));
    // 2. set the antenna dimensions
    ptr_mmWave->SetUePhasedArrayModelAttribute("NumRows", UintegerValue(1));
    ptr_mmWave->SetUePhasedArrayModelAttribute("NumColumns", UintegerValue(2));

    // configure the BS antennas:
    // 1. specify the path of the file containing the codebook
    ptr_mmWave->SetEnbBeamformingCodebookAttribute(
        "CodebookFilename",
        StringValue("src/mmwave/model/Codebooks/8x8.txt"));
    ptr_mmWave->SetEnbPhasedArrayModelAttribute("NumRows", UintegerValue(8));
    // 2. set the antenna dimensions
    ptr_mmWave->SetEnbPhasedArrayModelAttribute("NumColumns", UintegerValue(8));

    NodeContainer enbNodes;
    NodeContainer ueNodes;
    enbNodes.Create(1);
    ueNodes.Create(1);

    Ptr<Building> building;
    building = Create<Building>();
    building->SetBoundaries(Box(20.0, 40.0, 0.0, 20.0, 0.0, 20.0));
    building->SetBuildingType(Building::Residential);
    building->SetExtWallsType(Building::ConcreteWithWindows);
    building->SetNFloors(1);
    building->SetNRoomsX(1);
    building->SetNRoomsY(1);

    Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator>();
    enbPositionAlloc->Add(Vector(0.0, 0.0, 0.0));
    MobilityHelper enbmobility;
    enbmobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    enbmobility.SetPositionAllocator(enbPositionAlloc);
    enbmobility.Install(enbNodes);
    BuildingsHelper::Install(enbNodes);

    MobilityHelper uemobility;
    uemobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");
    uemobility.Install(ueNodes);
    ueNodes.Get(0)->GetObject<MobilityModel>()->SetPosition(Vector(60, -20, 0));
    ueNodes.Get(0)->GetObject<ConstantVelocityMobilityModel>()->SetVelocity(Vector(0, 100, 0));

    BuildingsHelper::Install(ueNodes);

    NetDeviceContainer enbNetDev = ptr_mmWave->InstallEnbDevice(enbNodes);
    NetDeviceContainer ueNetDev = ptr_mmWave->InstallUeDevice(ueNodes);

    ptr_mmWave->AttachToClosestEnb(ueNetDev, enbNetDev);
    ptr_mmWave->EnableTraces();

    // Activate a data radio bearer
    enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
    EpsBearer bearer(q);
    ptr_mmWave->ActivateDataRadioBearer(ueNetDev, bearer);

    Simulator::Stop(Seconds(1));
    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
