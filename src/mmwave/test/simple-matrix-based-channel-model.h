/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2020 SIGNET Lab, Department of Information Engineering,
 * University of Padova
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
 */

#ifndef SIMPLE_MATRIX_BASED_CHANNEL_MODEL_H
#define SIMPLE_MATRIX_BASED_CHANNEL_MODEL_H

#include <ns3/matrix-based-channel-model.h>
#include <ns3/vector.h>

namespace ns3
{

class MobilityModel;

/**
 * \ingroup spectrum
 * \brief Simple constant channel matrix with given channel parameters
 *
 * The channel matrix is created based on the ray characteristics manually set.
 * The ray characteristics are arrays of double values and they must have the same size.
 *
 * \see GetChannel
 */
class SimpleMatrixBasedChannelModel : public MatrixBasedChannelModel
{
  public:
    /**
     * Constructor
     */
    SimpleMatrixBasedChannelModel();

    /**
     * Destructor
     */
    virtual ~SimpleMatrixBasedChannelModel() override;

    /**
     * Get the type ID
     * \return the object TypeId
     */
    static TypeId GetTypeId();

    void SetFrequency(double f);
    double GetFrequency(void) const;

    void SetAodAzimuth(DoubleVector x);
    DoubleVector GetAodAzimuth(void) const;

    void SetAodElevation(DoubleVector x);
    DoubleVector GetAodElevation(void) const;

    void SetAoaAzimuth(DoubleVector x);
    DoubleVector GetAoaAzimuth(void) const;

    void SetAoaElevation(DoubleVector x);
    DoubleVector GetAoaElevation(void) const;

    void SetPhaseShift(DoubleVector x);
    DoubleVector GetPhaseShift(void) const;

    void SetPathLoss(DoubleVector x);
    DoubleVector GetPathLoss(void) const;

    void SetDelay(DoubleVector x);
    DoubleVector GetDelay(void) const;

    /**
     * It creates a channel matrix based on the given rays' parameters.
     * If the parameters are inconsistent, the simulation is aborted.
     *
     * \param aMob mobility model of the a device
     * \param bMob mobility model of the b device
     * \param aAntenna antenna of the a device
     * \param bAntenna antenna of the b device
     * \return the channel matrix
     */
    Ptr<const ChannelMatrix> GetChannel(Ptr<const MobilityModel> aMob,
                                        Ptr<const MobilityModel> bMob,
                                        Ptr<const PhasedArrayModel> aAntenna,
                                        Ptr<const PhasedArrayModel> bAntenna) override;

    /**
     * Returns a channel parameters structure used to obtain the channel between
     * the nodes with mobility objects passed as input parameters.
     *
     * \param aMob mobility model of the a device
     * \param bMob mobility model of the b device
     * \return the channel matrix
     */
    Ptr<const ChannelParams> GetParams(Ptr<const MobilityModel> aMob,
                                       Ptr<const MobilityModel> bMob) const override;

  private:
    void DoDispose() override;

    double m_frequency;        //!< the operating frequency
    DoubleVector m_aodAz;      //!< the list of AoD azimuth [deg]
    DoubleVector m_aodEl;      //!< the list of AoD elevation [deg]
    DoubleVector m_aoaAz;      //!< the list of AoA azimuth [deg]
    DoubleVector m_aoaEl;      //!< the list of AoA elevation [deg]
    DoubleVector m_phaseShift; //!< the list of phase shifts [rad]
    DoubleVector m_pathLoss;   //!< the list of path losses [dB]
    DoubleVector m_delay;      //!< the list of delays [s]
};

} // namespace ns3

#endif /* SIMPLE_MATRIX_BASED_CHANNEL_MODEL_H */
