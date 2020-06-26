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

#ifndef SRC_MMWAVE_BEAMFORMING_MODEL_H_
#define SRC_MMWAVE_BEAMFORMING_MODEL_H_

#include "ns3/object.h"

namespace ns3 {

class MobilityModel;
class ThreeGppAntennaArrayModel;
class NetDevice;

namespace mmwave {


/**
 * This class handles the beamforming operations.
 * Extend this class to implement a specific beamforming algorithm.
 */
class MmWaveBeamformingModel : public Object
{
public:
  /**
   * Constructor
   */
  MmWaveBeamformingModel ();

  /**
   * Destructor
   */
  virtual ~MmWaveBeamformingModel ();

  /**
   * Returns the object type id
   * \return the type id
   */
  static TypeId GetTypeId (void);

  /**
   * Returns the NetDevice
   * \return the net device
   */
  Ptr<NetDevice> GetDevice (void) const;

  /**
   * Set the NetDevice
   * \param device the net device
   */
  void SetDevice (Ptr<NetDevice> device);

  /**
   * Get the antenna on which beamforming is applied
   * \return the antenna
   */
  Ptr<ThreeGppAntennaArrayModel> GetAntenna (void) const;

  /**
   * Set the antenna on which beamforming is applied
   * \param antenna
   */
  void SetAntenna (Ptr<ThreeGppAntennaArrayModel> antenna);

  /**
   * Computes the beamforming vector to communicate with the target device and antenna
   * and configures the antenna
   * \param otherDevice the target device
   * \param otherAntenna the target antenna of otherDevice
   */
  virtual void SetBeamformingVectorForDevice (Ptr<NetDevice> otherDevice, Ptr<ThreeGppAntennaArrayModel> otherAntenna) = 0;

protected:
  virtual void DoDispose (void) override;

  Ptr<NetDevice> m_device; //!< pointer to the NetDevice
  Ptr<ThreeGppAntennaArrayModel> m_antenna; //!< The antenna of the device on which the beamforming is applied
};


/**
 * This class extends the MmWaveBeamformingModel interface.
 * It implements a DFT-based beamforming algorithm.
 */
class MmWaveDftBeamforming : public MmWaveBeamformingModel
{
public:
  /**
   * Constructor
   */
  MmWaveDftBeamforming ();

  /**
   * Destructor
   */
  virtual ~MmWaveDftBeamforming ();

  /**
   * Returns the object type id
   * \return the type id
   */
  static TypeId GetTypeId (void);

  /**
   * Computes the beamforming vector to communicate with the target device and antenna
   * and configures the antenna
   * \param otherDevice the target device
   * \param otherAntenna the target antenna of otherDevice
   */
  void SetBeamformingVectorForDevice (Ptr<NetDevice> otherDevice, Ptr<ThreeGppAntennaArrayModel> otherAntenna) override;
};

} // namespace mmwave
} // namespace ns3

#endif /* SRC_MMWAVE_BEAMFORMING_MODEL_H_ */
