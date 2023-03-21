/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
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
 */

#include "ns3/mmwave-helper.h"
#include "ns3/mobility-helper.h"
#include "ns3/node-container.h"
#include "ns3/phased-array-model.h"
#include "ns3/test.h"

NS_LOG_COMPONENT_DEFINE("MmWaveAntennaInitializationTestSuite");

using namespace ns3;
using namespace mmwave;

/**
 * This test case checks if the MmWaveHelper correctly initializes the
 * device antennas
 */
class MmwaveThreeGppAntennaInitializationTestCase : public TestCase
{
  public:
    /**
     * Constructor
     */
    MmwaveThreeGppAntennaInitializationTestCase();

    /**
     * Destructor
     */
    virtual ~MmwaveThreeGppAntennaInitializationTestCase();

  private:
    /**
     * Run the test
     */
    virtual void DoRun(void);
};

MmwaveThreeGppAntennaInitializationTestCase::MmwaveThreeGppAntennaInitializationTestCase()
    : TestCase("Checks if the MmWaveHelper correctly initializes the 3GPP channel model")
{
}

MmwaveThreeGppAntennaInitializationTestCase::~MmwaveThreeGppAntennaInitializationTestCase()
{
}

void
MmwaveThreeGppAntennaInitializationTestCase::DoRun(void)
{
    uint8_t numCc = 2;                 // number of CCs
    double freq[]{6.0e9, 28.0e9};      // frequency of the CCs
    uint8_t m_numUeAntennaColumns = 2; // number of columns of the UE antenna array
    uint8_t m_numUeAntennaRows = 2;    // number of rows of the UE antenna array
    uint8_t m_numEnbAntennaColums = 4; // number of columns of the BS antenna array
    uint8_t m_numEnbAntennaRows = 4;   // number of rows of the BS antenna array

    // create the MmWaveHelper
    Ptr<MmWaveHelper> helper = CreateObject<MmWaveHelper>();
    helper->SetAttribute("UseCa", BooleanValue((numCc > 1)));
    helper->SetAttribute("NumberOfComponentCarriers", UintegerValue(numCc));

    // set the number of antennas in the devices
    helper->SetUePhasedArrayModelAttribute("NumColumns", UintegerValue(m_numUeAntennaColumns));
    helper->SetUePhasedArrayModelAttribute("NumRows", UintegerValue(m_numUeAntennaRows));
    helper->SetEnbPhasedArrayModelAttribute("NumColumns", UintegerValue(m_numEnbAntennaColums));
    helper->SetEnbPhasedArrayModelAttribute("NumRows", UintegerValue(m_numEnbAntennaRows));

    // create and configure the CCs
    std::map<uint8_t, MmWaveComponentCarrier> ccMap;
    for (uint8_t i = 0; i < numCc; i++)
    {
        Ptr<MmWavePhyMacCommon> phyMacConfig = CreateObject<MmWavePhyMacCommon>();
        phyMacConfig->SetAttribute("CenterFreq", DoubleValue(freq[i]));

        Ptr<MmWaveComponentCarrier> cc = CreateObject<MmWaveComponentCarrier>();
        cc->SetConfigurationParameters(phyMacConfig);
        cc->SetAsPrimary((i == 0));
        ccMap[i] = *cc;
    }

    // assign the map of CCs to the helper
    helper->SetCcPhyParams(ccMap);

    // choose the pathloss model to use
    helper->SetPathlossModelType("ns3::ThreeGppUmaPropagationLossModel");

    // choose the channel condition model to use
    helper->SetChannelConditionModelType("ns3::ThreeGppUmaChannelConditionModel");

    // choose the spectrum propagation loss model
    helper->SetChannelModelType("ns3::ThreeGppSpectrumPropagationLossModel");

    // create the BS node
    NodeContainer bsNodes;
    bsNodes.Create(1);

    // create a ListPositionAllocator and add the position of the BS
    Ptr<ListPositionAllocator> bsPositionAlloc = CreateObject<ListPositionAllocator>();
    bsPositionAlloc->Add(Vector(0.0, 0.0, 10.0));

    // use a MobilityHelper to install the MobilityModel for the BS
    MobilityHelper bsMobility;
    bsMobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    bsMobility.SetPositionAllocator(bsPositionAlloc);
    bsMobility.Install(bsNodes);

    // install the BS device on the proper Node
    NetDeviceContainer bsNetDev = helper->InstallEnbDevice(bsNodes);

    // retrive the MmWaveEnbNetDevice
    Ptr<MmWaveEnbNetDevice> mmWaveEnbDev = DynamicCast<MmWaveEnbNetDevice>(bsNetDev.Get(0));

    // iterate through the CCs
    for (auto ccIndex : mmWaveEnbDev->GetCcMap())
    {
        // retrieve the MmWaveEnbPhy
        Ptr<MmWaveEnbPhy> mmWaveEnbPhy = mmWaveEnbDev->GetPhy(ccIndex.first);

        // retrieve the MmWaveSpectrumPhy
        Ptr<MmWaveSpectrumPhy> mmWaveSpectrumPhy = mmWaveEnbPhy->GetDlSpectrumPhy();

        // retrieve the MmWaveBeamformingModel
        Ptr<MmWaveBeamformingModel> mmwaveBfModel = mmWaveSpectrumPhy->GetBeamformingModel();

        // retrieve the PhasedArrayModel
        Ptr<PhasedArrayModel> antenna = mmwaveBfModel->GetAntenna();

        // check if the number of antenna elements has been configured
        NS_TEST_ASSERT_MSG_EQ(antenna->GetNumberOfElements(),
                              m_numEnbAntennaRows * m_numEnbAntennaColums,
                              "The number of antenna elements was not properly configured");
    }

    // create the UE node
    NodeContainer ueNodes;
    ueNodes.Create(1);

    // create a ListPositionAllocator and add the position of the UE
    Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator>();
    uePositionAlloc->Add(Vector(0.0, 0.0, 10.0));

    // use a MobilityHelper to install the MobilityModel for the UE
    MobilityHelper ueMobility;
    ueMobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    ueMobility.SetPositionAllocator(uePositionAlloc);
    ueMobility.Install(ueNodes);

    // install the UE device on the proper Node
    NetDeviceContainer ueNetDev = helper->InstallUeDevice(ueNodes);

    // retrieve the MmWaveUeNetDevice
    Ptr<MmWaveUeNetDevice> mmWaveUeDev = DynamicCast<MmWaveUeNetDevice>(ueNetDev.Get(0));

    for (auto ccIndex : mmWaveUeDev->GetCcMap())
    {
        // retrieve the MmWaveUePhy
        Ptr<MmWaveUePhy> mmWaveUePhy = mmWaveUeDev->GetPhy(ccIndex.first);

        // retrieve the MmWaveSpectrumPhy
        Ptr<MmWaveSpectrumPhy> mmWaveSpectrumPhy = mmWaveUePhy->GetDlSpectrumPhy();

        // retrieve the MmWaveBeamformingModel
        Ptr<MmWaveBeamformingModel> mmwaveBfModel = mmWaveSpectrumPhy->GetBeamformingModel();

        // retrieve the PhasedArrayModel
        Ptr<PhasedArrayModel> antenna = mmwaveBfModel->GetAntenna();

        // check if the number of antenna elements has been configured
        NS_TEST_ASSERT_MSG_EQ(antenna->GetNumberOfElements(),
                              m_numUeAntennaRows * m_numUeAntennaColumns,
                              "The number of antenna elements was not properly configured");
    }
}

/**
 * This suite tests if the MmWaveHelper correctly initializes the channel model
 */
class MmWaveAntennaInitializationTestSuite : public TestSuite
{
  public:
    MmWaveAntennaInitializationTestSuite();
};

MmWaveAntennaInitializationTestSuite::MmWaveAntennaInitializationTestSuite()
    : TestSuite("mmwave-antenna-initialization-test", UNIT)
{
    // TestDuration for TestCase can be QUICK, EXTENSIVE or TAKES_FOREVER
    AddTestCase(new MmwaveThreeGppAntennaInitializationTestCase, TestCase::QUICK);
}

// Do not forget to allocate an instance of this TestSuite
static MmWaveAntennaInitializationTestSuite mmwaveTestSuite;
