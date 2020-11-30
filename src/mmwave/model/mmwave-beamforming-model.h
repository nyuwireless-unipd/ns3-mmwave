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
#include "ns3/matrix-based-channel-model.h"
#include <map>

namespace ns3 {

class MobilityModel;
class ThreeGppAntennaArrayModel;
class NetDevice;
class ChannelConditionModel;

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
  virtual ~MmWaveBeamformingModel () override;

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
  virtual ~MmWaveDftBeamforming () override;

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


/**
 * This class extends the MmWaveBeamformingModel interface.
 * It implements an SVD-based beamforming algorithm.
 * See Sec. 5.1 for references https://arxiv.org/pdf/1702.04822.pdf
 */
class MmWaveSvdBeamforming : public MmWaveBeamformingModel
{
public:
  /**
   * Constructor
   */
  MmWaveSvdBeamforming ();

  /**
   * Destructor
   */
  virtual ~MmWaveSvdBeamforming () override;

  /**
   * Returns the object type id
   * \return the type id
   */
  static TypeId GetTypeId (void);

  /**
   * Computes the beamforming vector to communicate with the target device
   * and sets the antenna.
   * The beamforming vector is computed using a SVD-based beamforming
   * algorithm.
   * \param otherDevice the target device
   * \param otherAntenna the target antenna of otherDevice
   */
  void SetBeamformingVectorForDevice (Ptr<NetDevice> otherDevice, Ptr<ThreeGppAntennaArrayModel> otherAntenna) override;

private:
  void DoDispose (void) override;
  /**
   * Compute the beamforming vectors using SVD
   * \param params the channel matrix
   * \return a pair with the beamforming vectors
   */
  std::pair<ThreeGppAntennaArrayModel::ComplexVector, ThreeGppAntennaArrayModel::ComplexVector> ComputeBeamformingVectors (Ptr<const MatrixBasedChannelModel::ChannelMatrix> params) const;

  /**
   * Compute eigenvector related to highest eigenvalue
   * \param A spatial correlation matrix (complex, hermitian)
   * \return eigenvector
   */
  ThreeGppAntennaArrayModel::ComplexVector GetFirstEigenvector (MatrixBasedChannelModel::Complex2DVector A) const;


  Ptr<MatrixBasedChannelModel> m_channel; //!< pointer to the MatrixChannel, to retrieve the matrix on which the SVD should be computed

  std::map<Ptr<NetDevice>, Ptr<const MatrixBasedChannelModel::ChannelMatrix> > m_cacheChannelMap; //!< map that stores the channel previously computed
  std::map<Ptr<NetDevice>, std::pair<ThreeGppAntennaArrayModel::ComplexVector, ThreeGppAntennaArrayModel::ComplexVector> > m_cacheBfVectors; //!< map that stores the previous bf vectors
  uint32_t m_maxIterations; //!< Maximum number of iterations to numerically approximate the SVD decomposition
  double m_tolerance; //!< Tolerance to numerically approximate the SVD decomposition
  bool m_useCache; //!< Cache the channel matrix whenever possible. NOTE: the SVD decomposition can be extremely computationally expensive, caching is suggested.
};


} // namespace mmwave
} // namespace ns3

#endif /* SRC_MMWAVE_BEAMFORMING_MODEL_H_ */
