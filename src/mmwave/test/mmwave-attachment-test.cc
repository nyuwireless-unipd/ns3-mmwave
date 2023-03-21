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
#include "ns3/test.h"

NS_LOG_COMPONENT_DEFINE("MmWaveAttachmentTest");

using namespace ns3;
using namespace mmwave;

/**
 * This test case checks if attachment procedure works properly
 */
class MmWaveAttachmentTestCase : public TestCase
{
  public:
    /**
     * Constructor
     */
    MmWaveAttachmentTestCase();

    /**
     * Destructor
     */
    virtual ~MmWaveAttachmentTestCase();

  private:
    /**
     * Run the test
     */
    virtual void DoRun(void);
};

MmWaveAttachmentTestCase::MmWaveAttachmentTestCase()
    : TestCase("Checks if the MmWaveHelper correctly attaches the UEs to the BSs")
{
}

MmWaveAttachmentTestCase::~MmWaveAttachmentTestCase()
{
}

void
MmWaveAttachmentTestCase::DoRun(void)
{
    // Create two UE-BS pairs, call the method AttachToClosestEnb () and check
    // if the UEs are correctly attached.

    // (0,20,1.6)--------------------(100,20,1.6)
    //   UE1-----------------------------UE2
    //    |                               |
    //   BS1-----------------------------BS2
    // (0,0,25)----------------------(100,0,25)

    uint8_t numCc = 2;            // number of CCs
    double freq[]{6.0e9, 28.0e9}; // frequency of the CCs

    // create the MmWaveHelper
    Ptr<MmWaveHelper> helper = CreateObject<MmWaveHelper>();
    helper->SetAttribute("UseCa", BooleanValue((numCc > 1)));
    helper->SetAttribute("NumberOfComponentCarriers", UintegerValue(numCc));

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

    // create the BS nodes
    NodeContainer bsNodes;
    bsNodes.Create(2);

    // create a ListPositionAllocator and add the position of the BS
    Ptr<ListPositionAllocator> bsPositionAlloc = CreateObject<ListPositionAllocator>();
    bsPositionAlloc->Add(Vector(0.0, 0.0, 25.0));
    bsPositionAlloc->Add(Vector(100.0, 0.0, 25.0));

    // use a MobilityHelper to install the MobilityModel for the BS
    MobilityHelper bsMobility;
    bsMobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    bsMobility.SetPositionAllocator(bsPositionAlloc);
    bsMobility.Install(bsNodes);

    // install the BS device on the proper Node
    NetDeviceContainer bsNetDevs = helper->InstallEnbDevice(bsNodes);

    // create the UE nodes
    NodeContainer ueNodes;
    ueNodes.Create(2);

    // create a ListPositionAllocator and add the position of the UEs
    Ptr<ListPositionAllocator> uePositionAlloc = CreateObject<ListPositionAllocator>();
    uePositionAlloc->Add(Vector(0.0, 20.0, 1.6));
    uePositionAlloc->Add(Vector(100.0, 20.0, 1.6));

    // use a MobilityHelper to install the MobilityModel for the UEs
    MobilityHelper ueMobility;
    ueMobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    ueMobility.SetPositionAllocator(uePositionAlloc);
    ueMobility.Install(ueNodes);

    // install the UE device on the proper Node
    NetDeviceContainer ueNetDevs = helper->InstallUeDevice(ueNodes);

    // attach the UE
    helper->AttachToClosestEnb(ueNetDevs, bsNetDevs);

    // check if the UEs are correctly attached
    Ptr<MmWaveUeNetDevice> mmWaveUeDev1 = DynamicCast<MmWaveUeNetDevice>(ueNetDevs.Get(0));
    Ptr<MmWaveEnbNetDevice> targetBs1 = mmWaveUeDev1->GetTargetEnb();
    NS_TEST_ASSERT_MSG_EQ(bsNetDevs.Get(0), targetBs1, "UE 1 should be attached to BS 1");

    Ptr<MmWaveUeNetDevice> mmWaveUeDev2 = DynamicCast<MmWaveUeNetDevice>(ueNetDevs.Get(1));
    Ptr<MmWaveEnbNetDevice> targetBs2 = mmWaveUeDev2->GetTargetEnb();
    NS_TEST_ASSERT_MSG_EQ(bsNetDevs.Get(1), targetBs2, "UE 2 should be attached to BS 2");
}

/**
 * This suite tests if the beamforming module works properly
 */
class MmWaveAttachmentTest : public TestSuite
{
  public:
    MmWaveAttachmentTest();
};

MmWaveAttachmentTest::MmWaveAttachmentTest()
    : TestSuite("mmwave-attachment-test", UNIT)
{
    // TestDuration for TestCase can be QUICK, EXTENSIVE or TAKES_FOREVER
    AddTestCase(new MmWaveAttachmentTestCase, TestCase::QUICK);
}

// Do not forget to allocate an instance of this TestSuite
static MmWaveAttachmentTest mmwaveTestSuite;
