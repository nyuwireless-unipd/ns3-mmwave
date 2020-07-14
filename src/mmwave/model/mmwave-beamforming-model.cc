/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
*   Copyright (c) 2019 University of Padova, Dep. of Information Engineering, SIGNET lab.
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

#include "ns3/mmwave-beamforming-model.h"
#include "ns3/three-gpp-antenna-array-model.h"
#include "ns3/mobility-model.h"
#include "ns3/matrix-based-channel-model.h"
#include "ns3/channel-condition-model.h"
#include "ns3/pointer.h"
#include "ns3/uinteger.h"
#include "ns3/double.h"
#include "ns3/boolean.h"
#include "ns3/net-device.h"
#include "ns3/node.h"
#include "ns3/log.h"

namespace ns3 {

namespace mmwave {

NS_LOG_COMPONENT_DEFINE ("MmWaveBeamformingModel");

/*----------------------------------------------------------------------------*/

NS_OBJECT_ENSURE_REGISTERED (MmWaveBeamformingModel);

TypeId
MmWaveBeamformingModel::GetTypeId ()
{
  static TypeId
    tid =
    TypeId ("ns3::MmWaveBeamformingModel")
    .SetParent<Object> ()
    .AddAttribute ("Device",
                   "The current NetDevice",
                   PointerValue (0),
                   MakePointerAccessor (&MmWaveBeamformingModel::SetDevice,
                                        &MmWaveBeamformingModel::GetDevice),
                   MakePointerChecker<NetDevice> ())
    .AddAttribute ("Antenna",
                   "The antenna of the Device to configure",
                   PointerValue (0),
                   MakePointerAccessor (&MmWaveBeamformingModel::SetAntenna,
                                         &MmWaveBeamformingModel::GetAntenna),
                   MakePointerChecker<ThreeGppAntennaArrayModel> ())
  ;
  return tid;
}

MmWaveBeamformingModel::MmWaveBeamformingModel ()
{
  NS_LOG_FUNCTION (this);
}

MmWaveBeamformingModel::~MmWaveBeamformingModel ()
{
}

void
MmWaveBeamformingModel::DoDispose ()
{
  NS_LOG_FUNCTION (this);
  m_device = 0;
  m_antenna = 0;
}

Ptr<NetDevice>
MmWaveBeamformingModel::GetDevice () const
{
  NS_LOG_FUNCTION (this);
  return m_device;
}

void
MmWaveBeamformingModel::SetDevice (Ptr<NetDevice> device)
{
  NS_LOG_FUNCTION (this << device);
  m_device = device;
}

Ptr<ThreeGppAntennaArrayModel>
MmWaveBeamformingModel::GetAntenna (void) const
{
  NS_LOG_FUNCTION (this);
  return m_antenna;
}

void
MmWaveBeamformingModel::SetAntenna (Ptr<ThreeGppAntennaArrayModel> antenna)
{
  NS_LOG_FUNCTION (this << antenna);
  m_antenna = antenna;
}

/*----------------------------------------------------------------------------*/

NS_OBJECT_ENSURE_REGISTERED (MmWaveDftBeamforming);

TypeId
MmWaveDftBeamforming::GetTypeId ()
{
  static TypeId
    tid =
    TypeId ("ns3::MmWaveDftBeamforming")
    .SetParent<MmWaveBeamformingModel> ()
    .AddConstructor<MmWaveDftBeamforming> ()
  ;
  return tid;
}

MmWaveDftBeamforming::MmWaveDftBeamforming ()
{
  NS_LOG_FUNCTION (this);
}

MmWaveDftBeamforming::~MmWaveDftBeamforming ()
{
}


void
MmWaveDftBeamforming::SetBeamformingVectorForDevice (Ptr<NetDevice> otherDevice, Ptr<ThreeGppAntennaArrayModel> otherAntenna)
{
  NS_LOG_FUNCTION (this << otherDevice << otherAntenna);

  ThreeGppAntennaArrayModel::ComplexVector antennaWeights;

  // retrieve the position of the two devices
  Ptr<MobilityModel> mobility = m_device->GetNode ()->GetObject<MobilityModel> ();
  Vector aPos = mobility->GetPosition ();

  NS_ASSERT_MSG (otherDevice->GetNode (), "the device " << otherDevice << " is not associated to a node");
  NS_ASSERT_MSG (otherDevice->GetNode ()->GetObject<MobilityModel> (), "the device " << otherDevice << " has not a mobility model");
  Vector bPos = otherDevice->GetNode ()->GetObject<MobilityModel> ()->GetPosition ();

  // compute the azimuth and the elevation angles
  Angles completeAngle (bPos,aPos);

  double hAngleRadian = fmod (completeAngle.phi, 2.0 * M_PI); // the azimuth angle
  if (hAngleRadian < 0)
  {
    hAngleRadian += 2.0 * M_PI;     
  } 
  double vAngleRadian = completeAngle.theta; // the elevation angle

  // retrieve the number of antenna elements
  uint32_t totNoArrayElements = m_antenna->GetNumberOfElements ();

  // the total power is divided equally among the antenna elements
  double power = 1 / sqrt (totNoArrayElements);

  // compute the antenna weights
  for (uint32_t ind = 0; ind < totNoArrayElements; ind++)
    {
      Vector loc = m_antenna->GetElementLocation (ind);
      double phase = -2 * M_PI * (sin (vAngleRadian) * cos (hAngleRadian) * loc.x
                                  + sin (vAngleRadian) * sin (hAngleRadian) * loc.y
                                  + cos (vAngleRadian) * loc.z);
      antennaWeights.push_back (exp (std::complex<double> (0, phase)) * power);
    }

  // configure the antenna to use the new beamforming vector
  m_antenna->SetBeamformingVector (antennaWeights);
}

/*----------------------------------------------------------------------------*/

NS_OBJECT_ENSURE_REGISTERED (MmWaveSvdBeamforming);

TypeId
MmWaveSvdBeamforming::GetTypeId ()
{
  static TypeId
    tid =
    TypeId ("ns3::MmWaveSvdBeamforming")
    .SetParent<MmWaveBeamformingModel> ()
    .AddConstructor<MmWaveSvdBeamforming> ()
    .AddAttribute ("ChannelModel",
                   "Pointer to the MatrixBasedChannelModel object used in the simulation scenario",
                   PointerValue (),
                   MakePointerAccessor (&MmWaveSvdBeamforming::m_channel),
                   MakePointerChecker<MatrixBasedChannelModel> ())
    .AddAttribute ("MaxIterations",
                   "Maximum number of iterations to numerically approximate the SVD decomposition",
                   UintegerValue (30),
                   MakeUintegerAccessor (&MmWaveSvdBeamforming::m_maxIterations),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("Tolerance",
                   "Tolerance to numerically approximate the SVD decomposition",
                   DoubleValue (1e-8),
                   MakeDoubleAccessor (&MmWaveSvdBeamforming::m_tolerance),
                   MakeDoubleChecker<double> ())
    .AddAttribute ("UseCache",
                   "Use the cache for the BF vectors. Do not set it to false unless you have very good reasons",
                   BooleanValue (true),
                   MakeBooleanAccessor (&MmWaveSvdBeamforming::m_useCache),
                   MakeBooleanChecker ())
  ;
  return tid;
}

MmWaveSvdBeamforming::MmWaveSvdBeamforming ()
  : m_useCache {false}
{
  NS_LOG_FUNCTION (this);
}

MmWaveSvdBeamforming::~MmWaveSvdBeamforming ()
{
}

void
MmWaveSvdBeamforming::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
  m_channel = 0;
  MmWaveBeamformingModel::DoDispose ();
}

void
MmWaveSvdBeamforming::SetBeamformingVectorForDevice (Ptr<NetDevice> otherDevice, Ptr<ThreeGppAntennaArrayModel> otherAntenna)
{
  NS_LOG_FUNCTION (this << otherDevice << otherAntenna);

  Ptr<MobilityModel> thisMob = m_device->GetNode ()->GetObject<MobilityModel> ();
  NS_ASSERT_MSG (thisMob, "This device " << m_device << " does not have a mobility model");
  Ptr<MobilityModel> otherMob = otherDevice->GetNode ()->GetObject<MobilityModel> ();
  NS_ASSERT_MSG (otherMob, "The otherDevice " << otherDevice << " does not have a mobility model");

  // this will trigger a new computation (if needed)
  auto channelMatrix = m_channel->GetChannel (thisMob, otherMob, m_antenna, otherAntenna);

  std::pair<ThreeGppAntennaArrayModel::ComplexVector, ThreeGppAntennaArrayModel::ComplexVector> bfVectors;

  bool toCache {false};

  if (m_useCache)
    {
      auto entry {m_cacheChannelMap.find (otherDevice)};
      if (entry != m_cacheChannelMap.end () && entry->second == channelMatrix) // hit: the channel was already cached
        {
          NS_LOG_DEBUG ("channel cached " << channelMatrix);
          bfVectors = m_cacheBfVectors.find (otherDevice)->second;
        }
      else
        {
          NS_LOG_DEBUG ("new channel " << channelMatrix);
          toCache = true;
        }
    }

  if (!m_useCache || toCache)
    {
      if (channelMatrix->m_channel[0][0].size () == 0)
        {
          NS_LOG_LOGIC ("Channel has no MPCs");

          uint64_t thisAntennaNumElements = m_antenna->GetNumberOfElements ();
          uint64_t otherAntennaNumElements = otherAntenna->GetNumberOfElements ();
          ThreeGppAntennaArrayModel::ComplexVector thisBf;
          thisBf.resize (thisAntennaNumElements);
          ThreeGppAntennaArrayModel::ComplexVector otherBf;
          otherBf.resize (otherAntennaNumElements);

          bfVectors = std::make_pair (thisBf, otherBf);
        }
      else
        {
          bfVectors = ComputeBeamformingVectors (channelMatrix);

          uint32_t thisDeviceId = m_device->GetNode ()->GetId ();
          uint32_t otherDeviceId = otherDevice->GetNode ()->GetId ();
          if (channelMatrix->IsReverse (thisDeviceId, otherDeviceId))
            {
              // reverse BF vectors
              bfVectors = std::make_pair (std::get<1> (bfVectors), std::get<0> (bfVectors));
            }
        }
    }

  // configure the antenna to use the new beamforming vector
  m_antenna->SetBeamformingVector (std::get<0> (bfVectors));
  NS_LOG_LOGIC ("antenna " << m_antenna
                           << " set BF vector"
                           << " numAntennaElem " << m_antenna->GetNumberOfElements ()
                           << " this device ID=" << m_device->GetNode ()->GetId ()
                           << " otherDevice ID=" << otherDevice->GetNode ()->GetId ());
  otherAntenna->SetBeamformingVector (std::get<1> (bfVectors));
  NS_LOG_LOGIC ("antenna " << otherAntenna
                           << " set BF vector"
                           << " numAntennaElem " << otherAntenna->GetNumberOfElements ()
                           << " this device ID=" << otherDevice->GetNode ()->GetId ()
                           << " otherDevice ID=" << m_device->GetNode ()->GetId ());

  if (toCache)
    {
      auto entry {m_cacheChannelMap.find (otherDevice)};
      if (entry != m_cacheChannelMap.end ())
        {
          entry->second = channelMatrix;
          // this means there is also an entry for the bf vector
          m_cacheBfVectors.find (otherDevice)->second = bfVectors;
        }
      else
        {
          m_cacheChannelMap.insert (std::make_pair (otherDevice, channelMatrix));
          m_cacheBfVectors.insert (std::make_pair (otherDevice, bfVectors));
        }
    }
}

std::pair<ThreeGppAntennaArrayModel::ComplexVector, ThreeGppAntennaArrayModel::ComplexVector>
MmWaveSvdBeamforming::ComputeBeamformingVectors (Ptr<const MatrixBasedChannelModel::ChannelMatrix> params) const
{
  //generate transmitter side spatial correlation matrix
  uint16_t aSize = params->m_channel.size ();
  uint16_t bSize = params->m_channel[0].size ();
  uint16_t clusterSize = params->m_channel[0][0].size ();

  // compute narrowband channel by summing over the cluster index
  MatrixBasedChannelModel::Complex2DVector narrowbandChannel;
  narrowbandChannel.resize (aSize);

  for (uint16_t aIndex = 0; aIndex < aSize; aIndex++)
    {
      narrowbandChannel[aIndex].resize (bSize);
    }

  for (uint16_t aIndex = 0; aIndex < aSize; aIndex++)
    {
      for (uint16_t bIndex = 0; bIndex < bSize; bIndex++)
        {
          std::complex<double> cSum (0, 0);
          for (uint16_t cIndex = 0; cIndex < clusterSize; cIndex++)
            {
              cSum += params->m_channel[aIndex][bIndex][cIndex];
            }
          narrowbandChannel[aIndex][bIndex] = cSum;
        }
    }

  //compute the transmitter side spatial correlation matrix bQ = H*H, where H is the sum of H_n over n clusters.
  MatrixBasedChannelModel::Complex2DVector bQ;
  bQ.resize (bSize);

  for (uint16_t bIndex = 0; bIndex < bSize; bIndex++)
    {
      bQ[bIndex].resize (bSize);
    }

  for (uint16_t b1Index = 0; b1Index < bSize; b1Index++)
    {
      for (uint16_t b2Index = 0; b2Index < bSize; b2Index++)
        {
          std::complex<double> aSum (0,0);
          for (uint16_t aIndex = 0; aIndex < aSize; aIndex++)
            {
              aSum += std::conj (narrowbandChannel[aIndex][b1Index]) * narrowbandChannel[aIndex][b2Index];
            }
          bQ[b1Index][b2Index] += aSum;
        }
    }

  //calculate beamforming vector from spatial correlation matrix
  ThreeGppAntennaArrayModel::ComplexVector bW = GetFirstEigenvector (bQ);

  //compute the receiver side spatial correlation matrix aQ = HH*, where H is the sum of H_n over n clusters.
  MatrixBasedChannelModel::Complex2DVector aQ;
  aQ.resize (aSize);

  for (uint16_t aIndex = 0; aIndex < aSize; aIndex++)
    {
      aQ[aIndex].resize (aSize);
    }

  for (uint16_t a1Index = 0; a1Index < aSize; a1Index++)
    {
      for (uint16_t a2Index = 0; a2Index < aSize; a2Index++)
        {
          std::complex<double> bSum (0,0);
          for (uint16_t bIndex = 0; bIndex < bSize; bIndex++)
            {
              bSum += narrowbandChannel[a1Index][bIndex] * std::conj (narrowbandChannel[a2Index][bIndex]);
            }
          aQ[a1Index][a2Index] += bSum;
        }
    }

  //calculate beamforming vector from spatial correlation matrix.
  ThreeGppAntennaArrayModel::ComplexVector aW = GetFirstEigenvector (aQ);

  for (size_t i = 0; i < aW.size (); ++i)
    {
      aW[i] = std::conj (aW[i]);
    }

  return std::make_pair (bW, aW);
}

ThreeGppAntennaArrayModel::ComplexVector
MmWaveSvdBeamforming::GetFirstEigenvector (MatrixBasedChannelModel::Complex2DVector A) const
{
  ThreeGppAntennaArrayModel::ComplexVector antennaWeights;
  uint16_t arraySize = A.size ();
  for (uint16_t eIndex = 0; eIndex < arraySize; eIndex++)
    {
      antennaWeights.push_back (A[0][eIndex]);
    }


  uint32_t iter = 0;
  double diff = 1;
  while (iter < m_maxIterations && diff > m_tolerance)
    {
      ThreeGppAntennaArrayModel::ComplexVector antennaWeightsNew;

      for (uint16_t row = 0; row < arraySize; row++)
        {
          std::complex<double> sum (0,0);
          for (uint16_t col = 0; col < arraySize; col++)
            {
              sum += A[row][col] * antennaWeights[col];
            }

          antennaWeightsNew.push_back (sum);
        }
      //normalize antennaWeights;
      double weighbSum = 0;
      for (uint16_t i = 0; i < arraySize; i++)
        {
          weighbSum += norm (antennaWeightsNew[i]);
        }
      for (uint16_t i = 0; i < arraySize; i++)
        {
          antennaWeightsNew[i] = antennaWeightsNew[i] / sqrt (weighbSum);
        }
      diff = 0;
      for (uint16_t i = 0; i < arraySize; i++)
        {
          diff += std::norm (antennaWeightsNew[i] - antennaWeights[i]);
        }
      iter++;
      antennaWeights = antennaWeightsNew;
    }
  NS_LOG_DEBUG ("antennaWeigths stopped after " << iter << " iterations with diff=" << diff << std::endl);

  return antennaWeights;
}

} // namespace mmwave
} // namespace ns3
