/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2024
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Test case for AlwaysLosChannelConditionModel stability
 */

#include <ns3/test.h>
#include <ns3/log.h>
#include <ns3/channel-condition-model.h>
#include <ns3/three-gpp-channel-model.h>
#include <ns3/three-gpp-propagation-loss-model.h>
#include <ns3/mobility-model.h>
#include <ns3/constant-position-mobility-model.h>
#include <ns3/simulator.h>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("TestAlwaysLosChannelCondition");

/**
 * \ingroup propagation-tests
 *
 * \brief Test case to verify that AlwaysLosChannelConditionModel
 * maintains stable LOS condition without transitions.
 *
 * This test ensures that when using AlwaysLosChannelConditionModel,
 * the channel condition remains LOS throughout the simulation,
 * preventing SINR instability caused by LOS/NLOS transitions.
 */
class AlwaysLosChannelConditionTestCase : public TestCase
{
public:
    /**
     * Constructor
     */
    AlwaysLosChannelConditionTestCase();
    
    virtual ~AlwaysLosChannelConditionTestCase();

private:
    virtual void DoRun(void);
};

AlwaysLosChannelConditionTestCase::AlwaysLosChannelConditionTestCase()
    : TestCase("Test AlwaysLosChannelConditionModel for stable LOS condition")
{
}

AlwaysLosChannelConditionTestCase::~AlwaysLosChannelConditionTestCase()
{
}

void
AlwaysLosChannelConditionTestCase::DoRun(void)
{
    NS_LOG_FUNCTION(this);
    
    // Create mobility models
    Ptr<MobilityModel> mobA = CreateObject<ConstantPositionMobilityModel>();
    mobA->SetPosition(Vector(0.0, 0.0, 10.0));
    
    Ptr<MobilityModel> mobB = CreateObject<ConstantPositionMobilityModel>();
    mobB->SetPosition(Vector(100.0, 0.0, 1.5));
    
    // Create AlwaysLosChannelConditionModel
    Ptr<AlwaysLosChannelConditionModel> condModel = 
        CreateObject<AlwaysLosChannelConditionModel>();
    
    // Test multiple times over different simulation times
    // to ensure condition doesn't change
    std::vector<double> testTimes = {0.0, 0.1, 0.5, 1.0, 2.0};
    
    for (auto t : testTimes)
    {
        Simulator::Stop(Seconds(t));
        Simulator::Run();
        
        Ptr<ChannelCondition> cond = condModel->GetChannelCondition(mobA, mobB);
        
        NS_TEST_ASSERT_MSG_EQ(cond->GetLosCondition(), 
                              ChannelCondition::LosConditionValue::LOS,
                              "AlwaysLosChannelConditionModel should always return LOS at t=" 
                              << t << "s");
        
        // Also test reverse direction
        Ptr<ChannelCondition> condRev = condModel->GetChannelCondition(mobB, mobA);
        NS_TEST_ASSERT_MSG_EQ(condRev->GetLosCondition(), 
                              ChannelCondition::LosConditionValue::LOS,
                              "AlwaysLosChannelConditionModel should always return LOS (reverse) at t=" 
                              << t << "s");
    }
    
    // Test at different distances
    std::vector<double> distances = {10.0, 50.0, 100.0, 500.0, 1000.0};
    
    for (auto dist : distances)
    {
        mobB->SetPosition(Vector(dist, 0.0, 1.5));
        
        Ptr<ChannelCondition> cond = condModel->GetChannelCondition(mobA, mobB);
        
        NS_TEST_ASSERT_MSG_EQ(cond->GetLosCondition(), 
                              ChannelCondition::LosConditionValue::LOS,
                              "AlwaysLosChannelConditionModel should always return LOS at distance " 
                              << dist << "m");
    }
    
    Simulator::Destroy();
}

/**
 * \ingroup propagation-tests
 *
 * \brief Test case to verify that using AlwaysLosChannelConditionModel
 * prevents SINR fluctuations that would occur with standard models.
 */
class AlwaysLosStabilityTestCase : public TestCase
{
public:
    /**
     * Constructor
     */
    AlwaysLosStabilityTestCase();
    
    virtual ~AlwaysLosStabilityTestCase();

private:
    virtual void DoRun(void);
};

AlwaysLosStabilityTestCase::AlwaysLosStabilityTestCase()
    : TestCase("Test that AlwaysLos prevents channel condition updates")
{
}

AlwaysLosStabilityTestCase::~AlwaysLosStabilityTestCase()
{
}

void
AlwaysLosStabilityTestCase::DoRun(void)
{
    NS_LOG_FUNCTION(this);
    
    // Create mobility models (stationary)
    Ptr<MobilityModel> mobA = CreateObject<ConstantPositionMobilityModel>();
    mobA->SetPosition(Vector(0.0, 0.0, 10.0));
    
    Ptr<MobilityModel> mobB = CreateObject<ConstantPositionMobilityModel>();
    mobB->SetPosition(Vector(200.0, 0.0, 1.5));
    
    // Create AlwaysLosChannelConditionModel
    Ptr<AlwaysLosChannelConditionModel> condModel = 
        CreateObject<AlwaysLosChannelConditionModel>();
    
    // Get initial condition
    Ptr<ChannelCondition> initialCond = condModel->GetChannelCondition(mobA, mobB);
    ChannelCondition::LosConditionValue initialState = initialCond->GetLosCondition();
    
    // Simulate for extended period and check condition doesn't change
    // This mimics the scenario where UpdatePeriod would normally cause transitions
    for (uint32_t i = 0; i < 100; ++i)
    {
        Simulator::Stop(MilliSeconds(10)); // 10ms steps, total 1 second
        Simulator::Run();
        
        Ptr<ChannelCondition> cond = condModel->GetChannelCondition(mobA, mobB);
        
        NS_TEST_ASSERT_MSG_EQ(cond->GetLosCondition(), 
                              initialState,
                              "Channel condition should remain stable (LOS) at iteration " << i);
    }
    
    // Verify we're still in LOS state
    Ptr<ChannelCondition> finalCond = condModel->GetChannelCondition(mobA, mobB);
    NS_TEST_ASSERT_MSG_EQ(finalCond->GetLosCondition(), 
                          ChannelCondition::LosConditionValue::LOS,
                          "Final channel condition should still be LOS");
    
    Simulator::Destroy();
}

/**
 * \ingroup propagation-tests
 *
 * \brief Test suite for AlwaysLos channel condition stability
 */
class AlwaysLosChannelConditionTestSuite : public TestSuite
{
public:
    AlwaysLosChannelConditionTestSuite();
};

AlwaysLosChannelConditionTestSuite::AlwaysLosChannelConditionTestSuite()
    : TestSuite("always-los-channel-condition", Type::UNIT)
{
    AddTestCase(new AlwaysLosChannelConditionTestCase, TestCase::Duration::QUICK);
    AddTestCase(new AlwaysLosStabilityTestCase, TestCase::Duration::QUICK);
}

static AlwaysLosChannelConditionTestSuite g_alwaysLosChannelConditionTestSuite;
