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
 *                         Sourjya Dutta <sdutta@nyu.edu>
 *                         Russell Ford <russell.ford@nyu.edu>
 *                         Menglei Zhang <menglei@nyu.edu>
 */

#include "ns3/applications-module.h"
#include "ns3/config-store.h"
#include "ns3/core-module.h"
#include "ns3/global-route-manager.h"
#include "ns3/internet-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/log.h"
#include "ns3/mmwave-helper.h"
#include "ns3/mmwave-propagation-loss-model.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include <ns3/buildings-helper.h>

using namespace ns3;
using namespace mmwave;

NS_LOG_COMPONENT_DEFINE("MmwaveAmcTest");

double snrUpdateIntervalMs = 100.0; // in ms
double snrIncDb = 0.5;              // increment by 0.5 dB
double snrMinDb = -7.0;             // eNB-UE distance in meters
double snrMaxDb = 30;               // eNB-UE distance in meters

void
updateSnr(double snrInit,
          Ptr<MmWaveEnbNetDevice> enbDev,
          Ptr<SpectrumModel> model,
          Ptr<MmWaveAmc> amc)
{
    Ptr<MmWavePhyMacCommon> config = enbDev->GetPhy()->GetConfigurationParameters();

    SpectrumValue specVals(model);
    Values::iterator specIt = specVals.ValuesBegin();
    for (unsigned ichunk = 0; ichunk < model->GetNumBands(); ichunk++)
    {
        NS_ASSERT(specIt != specVals.ValuesEnd());
        *specIt = std::pow(10, snrInit / 10); // sinrLin;
        specIt++;
    }

    int mcsTmp = 28;
    uint8_t mcs = 0;
    int mcsOrig = 0;
    while (true)
    {
        amc->CreateCqiFeedbackWbTdma(specVals, mcs);
        if (mcs == mcsTmp || mcs == mcsOrig)
        {
            break;
        }
        mcsOrig = mcsTmp;
        mcsTmp = mcs;
    }
    enbDev->GetMac()->SetMcs(mcs);
    Simulator::Schedule(MicroSeconds(3 * 100),
                        &MmWaveSpectrumPhy::UpdateSinrPerceived,
                        enbDev->GetPhy()->GetDlSpectrumPhy(),
                        specVals);

    NS_LOG_INFO("************* SINR changing to " << snrInit << " (MCS = " << +mcs
                                                  << " ) *************");

    if (snrInit > snrMaxDb)
    {
        return;
    }

    Simulator::Schedule(MilliSeconds(snrUpdateIntervalMs),
                        &updateSnr,
                        snrInit + 0.1,
                        enbDev,
                        model,
                        amc);
}

int
main(int argc, char* argv[])
{
    /* Information regarding the traces generated:
     *
     * 1. UE_1_SINR.txt : Gives the SINR for each sub-band
     *    Subframe no.  | Slot No. | Sub-band  | SINR (db)
     *
     * 2. UE_1_Tb_size.txt : Allocated transport block size
     *    Time (micro-sec)  |  Tb-size in bytes
     * */
    uint16_t numEnb = 1;
    uint16_t numUe = 1;

    bool harqEnabled = true;
    int mcsDl = 28;
    std::string channelState = "n";

    // Command line arguments
    CommandLine cmd;
    cmd.AddValue("numEnb", "Number of eNBs", numEnb);
    cmd.AddValue("numUe", "Number of UEs per eNB", numUe);
    cmd.AddValue("harq", "Enable Hybrid ARQ", harqEnabled);
    cmd.AddValue("mcsDl", "Fixed DL MCS", mcsDl);
    cmd.AddValue("channelState", "Channel state 'l'=LOS, 'n'=NLOS, 'a'=all", channelState);
    cmd.AddValue("snrMinDb", "Minimum (final) SNR", snrMinDb);
    cmd.AddValue("snrMaxDb", "Maximum (initial) SNR", snrMaxDb);
    cmd.AddValue("snrIncDb", "SNR increment", snrIncDb);
    cmd.AddValue("snrUpdateIntervalMs",
                 "Period after which distance is updated",
                 snrUpdateIntervalMs);
    cmd.Parse(argc, argv);

    double simTime = ((snrMaxDb - snrMinDb) / snrIncDb) * (snrUpdateIntervalMs / 1000.0) + 1;

    if (mcsDl >= 0 && mcsDl < 29)
    {
        Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::FixedMcsUl", BooleanValue(true));
        Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::McsDefaultUl", UintegerValue(mcsDl));
    }

    Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::HarqEnabled", BooleanValue(harqEnabled));
    Config::SetDefault("ns3::MmWaveFlexTtiMacScheduler::UlSchedOnly", BooleanValue(true));
    Config::SetDefault("ns3::LteEnbRrc::SystemInformationPeriodicity",
                       TimeValue(MilliSeconds(1.0)));
    Config::SetDefault("ns3::MmWaveAmc::Ber", DoubleValue(0.001));
    Config::SetDefault("ns3::MmWavePropagationLossModel::FixedLossTst", BooleanValue(false));
    Config::SetDefault("ns3::MmWavePropagationLossModel::LossFixedDb", DoubleValue(100.0));
    Config::SetDefault("ns3::MmWaveHelper::UseIdealRrc", BooleanValue(true));
    Ptr<MmWaveHelper> mmwHelper = CreateObject<MmWaveHelper>();

    mmwHelper->Initialize();
    mmwHelper->SetHarqEnabled(harqEnabled);
    mmwHelper->SetSnrTest(true);

    NodeContainer enbNodes;
    NodeContainer ueNodes;
    enbNodes.Create(numEnb);
    ueNodes.Create(numUe);

    Ptr<ListPositionAllocator> enbPositionAlloc = CreateObject<ListPositionAllocator>();
    enbPositionAlloc->Add(Vector(0.0, 0.0, 0.0));

    MobilityHelper enbmobility;
    enbmobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    enbmobility.SetPositionAllocator(enbPositionAlloc);
    enbmobility.Install(enbNodes);
    BuildingsHelper::Install(enbNodes);

    MobilityHelper uemobility;
    Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator>();
    uePositionAlloc->Add(Vector(snrMinDb, 0.0, 0.0));

    uemobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");
    uemobility.SetPositionAllocator(uePositionAlloc);
    uemobility.Install(ueNodes);
    BuildingsHelper::Install(ueNodes);

    NetDeviceContainer enbNetDev = mmwHelper->InstallEnbDevice(enbNodes);
    NetDeviceContainer ueNetDev = mmwHelper->InstallUeDevice(ueNodes);

    mmwHelper->AttachToClosestEnb(ueNetDev, enbNetDev);
    mmwHelper->EnableTraces();

    // Activate a data radio bearer
    enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
    EpsBearer bearer(q);
    mmwHelper->ActivateDataRadioBearer(ueNetDev, bearer);
    Ptr<MmWaveEnbNetDevice> enbMmwDev = enbNetDev.Get(0)->GetObject<MmWaveEnbNetDevice>();

    Ptr<MmWaveAmc> amc =
        CreateObject<MmWaveAmc>(mmwHelper->GetCcPhyParams().at(0).GetConfigurationParameters());

    Simulator::Schedule(MilliSeconds(0),
                        &updateSnr,
                        snrMinDb,
                        enbMmwDev,
                        MmWaveSpectrumValueHelper::GetSpectrumModel(
                            mmwHelper->GetCcPhyParams().at(0).GetConfigurationParameters()),
                        amc);

    Simulator::Stop(Seconds(simTime));
    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
