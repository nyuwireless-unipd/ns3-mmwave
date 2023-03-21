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
#include "ns3/three-gpp-propagation-loss-model.h"
#include "ns3/three-gpp-spectrum-propagation-loss-model.h"

using namespace ns3;
using namespace mmwave;

/**
 * This test case checks if the MmWaveHelper correctly initializes the
 * 3GPP channel model
 */
class MmwaveThreeGppChannelInitializationTestCase : public TestCase
{
  public:
    /**
     * Constructor
     */
    MmwaveThreeGppChannelInitializationTestCase();

    /**
     * Destructor
     */
    virtual ~MmwaveThreeGppChannelInitializationTestCase();

  private:
    /**
     * Run the test
     */
    virtual void DoRun(void);
};

MmwaveThreeGppChannelInitializationTestCase::MmwaveThreeGppChannelInitializationTestCase()
    : TestCase("Checks if the MmWaveHelper correctly initializes the 3GPP channel model")
{
}

MmwaveThreeGppChannelInitializationTestCase::~MmwaveThreeGppChannelInitializationTestCase()
{
}

void
MmwaveThreeGppChannelInitializationTestCase::DoRun(void)
{
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

        // retrieve the SpectrumChannel
        Ptr<SpectrumChannel> channel = mmWaveSpectrumPhy->GetSpectrumChannel();

        // retrive the PropagationLossModel
        // NOTE the class SpectrumChannel does not provide a method to retrieve the
        // associated PropagationLossModel, so we obtain it using the attribute system
        PointerValue ptr;
        channel->GetAttribute("PropagationLossModel", ptr);
        Ptr<PropagationLossModel> plm = ptr.Get<PropagationLossModel>();

        // cast the PropagationLossModel
        Ptr<ThreeGppUmaPropagationLossModel> threeGppPlm =
            DynamicCast<ThreeGppUmaPropagationLossModel>(plm);

        // be sure the MmWaveHelper has created the proper propagation loss model
        if (!threeGppPlm)
        {
            NS_TEST_ASSERT_MSG_EQ(false,
                                  true,
                                  "The propagation loss model is not properly configured");
        }

        // retrieve the spectrum propagation loss model
        Ptr<PhasedArraySpectrumPropagationLossModel> splm =
            channel->GetPhasedArraySpectrumPropagationLossModel();
        Ptr<ThreeGppSpectrumPropagationLossModel> threeGppSplm =
            DynamicCast<ThreeGppSpectrumPropagationLossModel>(splm);

        // be sure that the MmWaveHelper has created the proper spectrum propagation loss model
        if (!threeGppSplm)
        {
            NS_TEST_ASSERT_MSG_EQ(false,
                                  true,
                                  "The spectrum propagation loss model is not properly configured");
        }

        // be sure that the MmWaveHelper has correctly configured the operating frequency
        double phyFreq = mmWaveEnbPhy->GetConfigurationParameters()->GetCenterFrequency();
        DoubleValue plmFreq;
        threeGppPlm->GetAttribute("Frequency", plmFreq);
        NS_TEST_ASSERT_MSG_EQ(
            phyFreq,
            freq[ccIndex.first],
            "The operating frequency of the PHY layer has not been properly configured");
        NS_TEST_ASSERT_MSG_EQ(
            phyFreq,
            plmFreq.Get(),
            "The operating frequency of the propagation loss model has not properly configured");
        DoubleValue splmFreq;
        threeGppSplm->GetChannelModelAttribute("Frequency", splmFreq);
        NS_TEST_ASSERT_MSG_EQ(phyFreq,
                              splmFreq.Get(),
                              "The operating frequency of the spectrum propagation loss model has "
                              "not properly configured");

        // be sure that the MmWaveHelper has created the proper channel condition
        // model and associated it to the propagation loss model
        Ptr<ChannelConditionModel> ccm = threeGppPlm->GetChannelConditionModel();
        Ptr<ThreeGppUmaChannelConditionModel> threeGppCcm =
            DynamicCast<ThreeGppUmaChannelConditionModel>(ccm);
        if (!threeGppCcm)
        {
            NS_TEST_ASSERT_MSG_EQ(false,
                                  true,
                                  "The channel condition model is not properly configured");
        }

        threeGppSplm->GetChannelModelAttribute("ChannelConditionModel", ptr);
        Ptr<ChannelConditionModel> threeGppSplmCcm = ptr.Get<ChannelConditionModel>();

        // be sure that the MmWaveHelper has associated the same channel condition model
        // also with the spectrum propagation loss model
        NS_TEST_ASSERT_MSG_EQ(
            ccm,
            threeGppSplmCcm,
            "The channel condition model associated to the propagation loss model is not the same "
            "as the one associated to the spectrum propagation loss model");
    }
}

/**
 * This suite tests if the MmWaveHelper correctly initializes the channel model
 */
class MmWaveChannelModelInitializationTestSuite : public TestSuite
{
  public:
    MmWaveChannelModelInitializationTestSuite();
};

MmWaveChannelModelInitializationTestSuite::MmWaveChannelModelInitializationTestSuite()
    : TestSuite("mmwave-channel-model-initialization-test", UNIT)
{
    // TestDuration for TestCase can be QUICK, EXTENSIVE or TAKES_FOREVER
    AddTestCase(new MmwaveThreeGppChannelInitializationTestCase, TestCase::QUICK);
}

// Do not forget to allocate an instance of this TestSuite
static MmWaveChannelModelInitializationTestSuite mmwaveTestSuite;
