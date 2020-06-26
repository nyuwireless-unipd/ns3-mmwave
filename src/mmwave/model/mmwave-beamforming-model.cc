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
#include "ns3/pointer.h"
#include "ns3/uinteger.h"
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

} // namespace mmwave
} // namespace ns3
