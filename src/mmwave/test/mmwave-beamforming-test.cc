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

#include "simple-matrix-based-channel-model.h"

#include "ns3/boolean.h"
#include "ns3/constant-position-mobility-model.h"
#include "ns3/double.h"
#include "ns3/isotropic-antenna-model.h"
#include "ns3/log.h"
#include "ns3/mmwave-beamforming-model.h"
#include "ns3/node.h"
#include "ns3/object-factory.h"
#include "ns3/pointer.h"
#include "ns3/simple-net-device.h"
#include "ns3/test.h"
#include "ns3/uinteger.h"
#include "ns3/uniform-planar-array.h"

NS_LOG_COMPONENT_DEFINE("MmWaveBeamformingTest");

using namespace ns3;
using namespace mmwave;

/**
 * This test case checks if the MmWaveDftBeamforming works properly
 */
class MmWaveDftBeamformingTestCase : public TestCase
{
  public:
    /**
     * Constructor
     */
    MmWaveDftBeamformingTestCase();

    /**
     * Destructor
     */
    virtual ~MmWaveDftBeamformingTestCase();

  private:
    /**
     * Run the test
     */
    virtual void DoRun(void);
};

MmWaveDftBeamformingTestCase::MmWaveDftBeamformingTestCase()
    : TestCase("Checks if the MmWaveDftBeamforming class works as expected")
{
}

MmWaveDftBeamformingTestCase::~MmWaveDftBeamformingTestCase()
{
}

void
MmWaveDftBeamformingTestCase::DoRun(void)
{
    // create the mobility model for this device
    Ptr<MobilityModel> mm1 = CreateObject<ConstantPositionMobilityModel>();
    mm1->SetPosition(Vector(0, 0, 0));

    // create the mobility model for the other device
    Ptr<MobilityModel> mm2 = CreateObject<ConstantPositionMobilityModel>();
    mm2->SetPosition(Vector(1, 0, 0));

    Angles losAngle(mm2->GetPosition(), mm1->GetPosition()); // the LOS direction

    // create a node for the this device
    Ptr<Node> thisNode = CreateObject<Node>();

    // aggregate the mobility model to the node
    thisNode->AggregateObject(mm1);

    // create the other net device and associate it with the node
    Ptr<NetDevice> thisDevice = CreateObject<SimpleNetDevice>();
    thisDevice->SetNode(thisNode);
    thisNode->AddDevice(thisDevice);

    // create the antenna
    Ptr<PhasedArrayModel> thisAntenna =
        CreateObjectWithAttributes<UniformPlanarArray>("NumRows",
                                                       UintegerValue(4),
                                                       "NumColumns",
                                                       UintegerValue(4));

    // create a node for the other device
    Ptr<Node> otherNode = CreateObject<Node>();

    // aggregate the mobility model to the node
    otherNode->AggregateObject(mm2);

    // create the other net device and associate it with the node
    Ptr<NetDevice> otherDevice = CreateObject<SimpleNetDevice>();
    otherDevice->SetNode(otherNode);
    otherNode->AddDevice(otherDevice);

    // create the antenna
    Ptr<PhasedArrayModel> otherAntenna =
        CreateObjectWithAttributes<UniformPlanarArray>("NumRows",
                                                       UintegerValue(4),
                                                       "NumColumns",
                                                       UintegerValue(4));

    // create the beamforming module
    Ptr<MmWaveDftBeamforming> bfModule =
        CreateObjectWithAttributes<MmWaveDftBeamforming>("Device",
                                                         PointerValue(thisDevice),
                                                         "Antenna",
                                                         PointerValue(thisAntenna));

    bfModule->SetBeamformingVectorForDevice(otherDevice, otherAntenna);
    PhasedArrayModel::ComplexVector bfVector = thisAntenna->GetBeamformingVector();

    double maxGain = 0;    // used to store the max |AF|
    Angles maxAngle(0, 0); // used to store the direction where max |AF| is achieved

    uint32_t numSteps = 10;
    double angleStep = 2 * M_PI / numSteps;
    for (uint32_t hIndex = 0; hIndex < numSteps; hIndex++)
    {
        for (uint32_t vIndex = 0; vIndex < numSteps; vIndex++)
        {
            double hAngle = hIndex * angleStep;     // azimuth [0, 2*PI]
            double vAngle = vIndex * angleStep / 2; // elevation [0, PI]

            // compute the steering vector
            PhasedArrayModel::ComplexVector steeringVector(thisAntenna->GetNumberOfElements());
            for (uint64_t eIndex = 0; eIndex < thisAntenna->GetNumberOfElements(); eIndex++)
            {
                Vector loc = thisAntenna->GetElementLocation(eIndex);
                double phase = -2 * M_PI *
                               (sin(vAngle) * cos(hAngle) * loc.x +
                                sin(vAngle) * sin(hAngle) * loc.y + cos(vAngle) * loc.z);
                steeringVector[eIndex] = exp(std::complex<double>(0, phase));
            }

            // compute the gain
            std::complex<double> arrayFactor = 0;
            for (uint64_t eIndex = 0; eIndex < thisAntenna->GetNumberOfElements(); eIndex++)
            {
                arrayFactor += bfVector[eIndex] * std::conj(steeringVector[eIndex]);
            }

            NS_LOG_DEBUG("hAngle " << hAngle << " vAngle " << vAngle << " |AF| "
                                   << abs(arrayFactor));

            if (abs(arrayFactor) > maxGain)
            {
                maxGain = abs(arrayFactor);
                maxAngle.SetAzimuth(hAngle);
                maxAngle.SetInclination(vAngle);
            }
        }
    }

    NS_TEST_ASSERT_MSG_EQ_TOL(maxAngle.GetAzimuth(),
                              losAngle.GetAzimuth(),
                              angleStep / 2,
                              "|AF| should be max in the LOS direction");
    NS_TEST_ASSERT_MSG_EQ_TOL(maxAngle.GetInclination(),
                              losAngle.GetInclination(),
                              angleStep / 4,
                              "|AF| should be max in the LOS direction");
    NS_TEST_ASSERT_MSG_EQ_TOL(maxGain,
                              std::sqrt(thisAntenna->GetNumberOfElements()),
                              0.05,
                              "|AF| should be equal to sqrt (N) in the LOS direction");
}

/**
 * This test case checks if the MmWaveSvdBeamforming works properly
 */
class MmWaveSvdBeamformingTestCase : public TestCase
{
  public:
    /**
     * Constructor
     */
    MmWaveSvdBeamformingTestCase();

    /**
     * Destructor
     */
    virtual ~MmWaveSvdBeamformingTestCase();

  private:
    /**
     * Run the test
     */
    virtual void DoRun(void);
};

MmWaveSvdBeamformingTestCase::MmWaveSvdBeamformingTestCase()
    : TestCase("Checks if the MmWaveSvdBeamforming class works as expected")
{
}

MmWaveSvdBeamformingTestCase::~MmWaveSvdBeamformingTestCase()
{
}

PhasedArrayModel::ComplexVector
GetManualBfVector(Ptr<PhasedArrayModel> antenna, Angles angle)
{
    uint32_t numElements = antenna->GetNumberOfElements();

    PhasedArrayModel::ComplexVector bfVector(numElements);

    for (uint32_t i = 0; i < numElements; ++i)
    {
        Vector loc = antenna->GetElementLocation(i);
        double phase = -2 * M_PI *
                       (sin(angle.GetInclination()) * cos(angle.GetAzimuth()) * loc.x +
                        sin(angle.GetInclination()) * sin(angle.GetAzimuth()) * loc.y +
                        cos(angle.GetInclination()) * loc.z);
        bfVector[i] = std::polar(1 / std::sqrt(numElements), phase);
    }

    return bfVector;
}

void
MmWaveSvdBeamformingTestCase::DoRun(void)
{
    // Create the mobility model for tx device
    Ptr<MobilityModel> txMob = CreateObject<ConstantPositionMobilityModel>();
    txMob->SetPosition(Vector(0, 0, 0));

    // Create the mobility model for the rx device
    Ptr<MobilityModel> rxMob = CreateObject<ConstantPositionMobilityModel>();
    rxMob->SetPosition(Vector(1, 0, 0));

    Angles losAngle(rxMob->GetPosition(), txMob->GetPosition()); // the LOS direction

    // Create a node for the tx device
    Ptr<Node> txNode = CreateObject<Node>();

    // Aggregate the mobility model to the node
    txNode->AggregateObject(txMob);

    // Create the rx net device and associate it with the node
    Ptr<NetDevice> txDevice = CreateObject<SimpleNetDevice>();
    txDevice->SetNode(txNode);
    txNode->AddDevice(txDevice);

    // Create the antenna
    Ptr<PhasedArrayModel> txAntenna = CreateObjectWithAttributes<UniformPlanarArray>(
        "NumRows",
        UintegerValue(4),
        "NumColumns",
        UintegerValue(4),
        "AntennaElement",
        PointerValue(CreateObject<IsotropicAntennaModel>()));

    // Create a node for the rx device
    Ptr<Node> rxNode = CreateObject<Node>();

    // Aggregate the mobility model to the node
    rxNode->AggregateObject(rxMob);

    // Create the rx net device and associate it with the node
    Ptr<NetDevice> rxDevice = CreateObject<SimpleNetDevice>();
    rxDevice->SetNode(rxNode);
    rxNode->AddDevice(rxDevice);

    // Create the antenna
    Ptr<PhasedArrayModel> rxAntenna = CreateObjectWithAttributes<UniformPlanarArray>(
        "NumRows",
        UintegerValue(2),
        "NumColumns",
        UintegerValue(2),
        "AntennaElement",
        PointerValue(CreateObject<IsotropicAntennaModel>()));

    // Create the channel model
    MatrixBasedChannelModel::DoubleVector aodAz{10};
    MatrixBasedChannelModel::DoubleVector aodEl{20};
    MatrixBasedChannelModel::DoubleVector aoaAz{30};
    MatrixBasedChannelModel::DoubleVector aoaEl{40};
    MatrixBasedChannelModel::DoubleVector phaseShift{0};
    MatrixBasedChannelModel::DoubleVector pathLoss{0};
    MatrixBasedChannelModel::DoubleVector delay{0};

    Ptr<SimpleMatrixBasedChannelModel> channelModel = CreateObject<SimpleMatrixBasedChannelModel>();
    channelModel->SetAodAzimuth(aodAz);
    channelModel->SetAodElevation(aodEl);
    channelModel->SetAoaAzimuth(aoaAz);
    channelModel->SetAoaElevation(aoaEl);
    channelModel->SetPhaseShift(phaseShift);
    channelModel->SetPathLoss(pathLoss);
    channelModel->SetDelay(delay);

    // Create the (overly precise) beamforming module
    Ptr<MmWaveSvdBeamforming> bfModule =
        CreateObjectWithAttributes<MmWaveSvdBeamforming>("Device",
                                                         PointerValue(txDevice),
                                                         "Antenna",
                                                         PointerValue(txAntenna),
                                                         "ChannelModel",
                                                         PointerValue(channelModel),
                                                         "MaxIterations",
                                                         UintegerValue(100),
                                                         "Tolerance",
                                                         DoubleValue(1e-50));

    // Setup beamforming
    bfModule->SetBeamformingVectorForDevice(rxDevice, rxAntenna);
    PhasedArrayModel::ComplexVector txBfVector = txAntenna->GetBeamformingVector();
    PhasedArrayModel::ComplexVector rxBfVector = rxAntenna->GetBeamformingVector();

    // Compute reference beamforming
    PhasedArrayModel::ComplexVector manualTxBfVector =
        GetManualBfVector(txAntenna,
                          Angles(DegreesToRadians(aodAz[0]), DegreesToRadians(aodEl[0])));
    PhasedArrayModel::ComplexVector manualRxBfVector =
        GetManualBfVector(rxAntenna,
                          Angles(DegreesToRadians(aoaAz[0]), DegreesToRadians(aoaEl[0])));

    // Check if the beamforming vectors are as expected (minus a constant phase difference)
    double tol = 1e-10;

    std::complex<double> txPhaseDifference = txBfVector[0] / manualTxBfVector[0];
    NS_TEST_ASSERT_MSG_EQ_TOL(std::abs(txPhaseDifference),
                              1,
                              tol,
                              "There should not be a magnitude difference between the computed and "
                              "expected beamforming vector");
    for (uint32_t i = 0; i < txAntenna->GetNumberOfElements(); ++i)
    {
        std::complex<double> correctedBf = txBfVector[i] / txPhaseDifference;
        double magDiff = std::abs(correctedBf - manualTxBfVector[i]);
        NS_TEST_ASSERT_MSG_LT(magDiff,
                              tol,
                              "TX beamforming vector different from what was expected");
    }

    std::complex<double> rxPhaseDifference = rxBfVector[0] / manualRxBfVector[0];
    NS_TEST_ASSERT_MSG_EQ_TOL(std::abs(rxPhaseDifference),
                              1,
                              tol,
                              "There should not be a magnitude difference between the computed and "
                              "expected beamforming vector");
    for (uint32_t i = 0; i < rxAntenna->GetNumberOfElements(); ++i)
    {
        std::complex<double> correctedBf = rxBfVector[i] / rxPhaseDifference;
        double magDiff = std::abs(correctedBf - manualRxBfVector[i]);
        NS_TEST_ASSERT_MSG_LT(magDiff,
                              tol,
                              "RX beamforming vector different from what was expected");
    }
}

/**
 * This suite tests if the beamforming module works properly
 */
class MmWaveBeamformingTest : public TestSuite
{
  public:
    MmWaveBeamformingTest();
};

MmWaveBeamformingTest::MmWaveBeamformingTest()
    : TestSuite("mmwave-beamforming-test", UNIT)
{
    // TestDuration for TestCase can be QUICK, EXTENSIVE or TAKES_FOREVER
    AddTestCase(new MmWaveDftBeamformingTestCase, TestCase::QUICK);
    AddTestCase(new MmWaveSvdBeamformingTestCase, TestCase::QUICK);
}

// Do not forget to allocate an instance of this TestSuite
static MmWaveBeamformingTest mmwaveTestSuite;
