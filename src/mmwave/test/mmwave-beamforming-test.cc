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

#include "ns3/mmwave-beamforming-model.h"
#include "ns3/test.h"
#include "ns3/simple-net-device.h"
#include "ns3/constant-position-mobility-model.h"
#include "ns3/log.h"
#include "ns3/pointer.h"
#include "ns3/three-gpp-antenna-array-model.h"
#include "ns3/object-factory.h"
#include "ns3/node.h"
#include "ns3/uinteger.h"

NS_LOG_COMPONENT_DEFINE ("MmWaveBeamformingTest");

using namespace ns3;
using namespace mmwave;

/**
* This test case checks if the MmWaveDftBeamforming works properly
*/
class MmWaveBeamformingTestCase : public TestCase
{
public:
  /**
  * Constructor
  */
  MmWaveBeamformingTestCase ();

  /**
  * Destructor
  */
  virtual ~MmWaveBeamformingTestCase ();

private:
  /**
  * Run the test
  */
  virtual void DoRun (void);
};

MmWaveBeamformingTestCase::MmWaveBeamformingTestCase ()
  : TestCase ("Checks if the MmWaveHelper correctly initializes the 3GPP channel model")
{
}

MmWaveBeamformingTestCase::~MmWaveBeamformingTestCase ()
{
}

void
MmWaveBeamformingTestCase::DoRun (void)
{
  // create the mobility model for this device
  Ptr<MobilityModel> mm1 = CreateObject<ConstantPositionMobilityModel> ();
  mm1->SetPosition (Vector (0, 0, 0));

  // create the mobility model for the other device
  Ptr<MobilityModel> mm2 = CreateObject<ConstantPositionMobilityModel> ();
  mm2->SetPosition (Vector (1, 0, 0));
  
  Angles losAngle (mm2->GetPosition (), mm1->GetPosition ()); // the LOS direction

  // create a node for the this device
  Ptr<Node> thisNode = CreateObject<Node> ();

  // aggregate the mobility model to the node
  thisNode->AggregateObject (mm1);

  // create the other net device and associate it with the node
  Ptr<NetDevice> thisDevice = CreateObject<SimpleNetDevice> ();
  thisDevice->SetNode (thisNode);
  thisNode->AddDevice (thisDevice);

  // create the antenna
  Ptr<ThreeGppAntennaArrayModel> thisAntenna = CreateObjectWithAttributes<ThreeGppAntennaArrayModel> ("NumRows", UintegerValue (4), "NumColumns", UintegerValue (4));

  // create a node for the other device
  Ptr<Node> otherNode = CreateObject<Node> ();

  // aggregate the mobility model to the node
  otherNode->AggregateObject (mm2);

  // create the other net device and associate it with the node
  Ptr<NetDevice> otherDevice = CreateObject<SimpleNetDevice> ();
  otherDevice->SetNode (otherNode);
  otherNode->AddDevice (otherDevice);

  // create the antenna
  Ptr<ThreeGppAntennaArrayModel> otherAntenna = CreateObjectWithAttributes<ThreeGppAntennaArrayModel> ("NumRows", UintegerValue (4), "NumColumns", UintegerValue (4));

  // create the beamforming module
  Ptr<MmWaveDftBeamforming> bfModule = CreateObjectWithAttributes<MmWaveDftBeamforming> ("Device", PointerValue (thisDevice), "Antenna", PointerValue (thisAntenna));

  bfModule->SetBeamformingVectorForDevice (otherDevice, otherAntenna);
  ThreeGppAntennaArrayModel::ComplexVector bfVector = thisAntenna->GetBeamformingVector ();
  
  double maxGain = 0; // used to store the max |AF|
  Angles maxAngle; // used to store the direction where max |AF| is achieved
  
  uint32_t numSteps = 10;
  double angleStep = 2 * M_PI / numSteps;
  for (uint32_t hIndex = 0; hIndex < numSteps; hIndex++)
  {
    for (uint32_t vIndex = 0; vIndex < numSteps; vIndex++)
    {
      double hAngle = hIndex * angleStep; // azimuth [0, 2*PI]
      double vAngle = vIndex * angleStep / 2; // elevation [0, PI]
      
      // compute the steering vector
      ThreeGppAntennaArrayModel::ComplexVector steeringVector (thisAntenna->GetNumberOfElements ());
      for (uint64_t eIndex = 0; eIndex < thisAntenna->GetNumberOfElements (); eIndex++)
      {
        Vector loc = thisAntenna->GetElementLocation (eIndex);
        double phase = -2 * M_PI * (sin (vAngle) * cos (hAngle) * loc.x
                                    + sin (vAngle) * sin (hAngle) * loc.y
                                    + cos (vAngle) * loc.z);
        steeringVector.at (eIndex) = exp (std::complex<double> (0, phase));
      }
      
      // compute the gain
      std::complex<double> arrayFactor = 0;
      for (uint64_t eIndex = 0; eIndex < thisAntenna->GetNumberOfElements (); eIndex++) 
      {
        arrayFactor += bfVector.at (eIndex) * std::conj (steeringVector.at (eIndex));
      }
      
      NS_LOG_DEBUG ("hAngle " << hAngle <<  " vAngle " << vAngle << " |AF| " << abs (arrayFactor));
      
      if (abs (arrayFactor) > maxGain)
      {
        maxGain = abs (arrayFactor);
        maxAngle.phi = hAngle; 
        maxAngle.theta = vAngle;
      }
    }
  }
  
  NS_TEST_ASSERT_MSG_EQ_TOL (maxAngle.phi, losAngle.phi, angleStep/2, "|AF| should be max in the LOS direction");
  NS_TEST_ASSERT_MSG_EQ_TOL (maxAngle.theta, losAngle.theta, angleStep/4, "|AF| should be max in the LOS direction");
  NS_TEST_ASSERT_MSG_EQ_TOL (maxGain, std::sqrt (thisAntenna->GetNumberOfElements ()), 0.05, "|AF| should be equal to sqrt (N) in the LOS direction");
}

/**
* This suite tests if the beamforming module works properly
*/
class MmWaveBeamformingTest : public TestSuite
{
public:
  MmWaveBeamformingTest ();
};

MmWaveBeamformingTest::MmWaveBeamformingTest ()
  : TestSuite ("mmwave-beamforming-test", UNIT)
{
  // TestDuration for TestCase can be QUICK, EXTENSIVE or TAKES_FOREVER
  AddTestCase (new MmWaveBeamformingTestCase, TestCase::QUICK);
}

// Do not forget to allocate an instance of this TestSuite
static MmWaveBeamformingTest mmwaveTestSuite;
