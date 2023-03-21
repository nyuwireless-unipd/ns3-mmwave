/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
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
 *
 *   Author: Marco Miozzo <marco.miozzo@cttc.es>
 *           Nicola Baldo  <nbaldo@cttc.es>
 *
 *   Modified by: Marco Mezzavilla < mezzavilla@nyu.edu>
 *                         Sourjya Dutta <sdutta@nyu.edu>
 *                         Russell Ford <russell.ford@nyu.edu>
 *                         Menglei Zhang <menglei@nyu.edu>
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_PROPAGATION_LOSS_MODEL_H_
#define SRC_MMWAVE_MODEL_MMWAVE_PROPAGATION_LOSS_MODEL_H_

#include "ns3/object.h"
#include "ns3/random-variable-stream.h"
#include <ns3/mmwave-phy-mac-common.h>
#include <ns3/propagation-loss-model.h>

#include <map>

namespace ns3
{

namespace mmwave
{

struct channelScenario
{
    char m_channelScenario;
    double m_shadowing;
};

// map store the path loss scenario(LOS,NLOS,OUTAGE) of each propapgation channel
typedef std::map<std::pair<Ptr<MobilityModel>, Ptr<MobilityModel>>, channelScenario>
    channelScenarioMap_t;

class MmWavePropagationLossModel : public PropagationLossModel
{
  public:
    static TypeId GetTypeId(void);
    MmWavePropagationLossModel();

    /**
     * Set the configuration parameters which are common in the whole simulation
     * \param ptrConfig a pointer to the MmWavePhyMacCommon object
     */
    void SetConfigurationParameters(Ptr<MmWavePhyMacCommon> ptrConfig);

    /**
     * \param minLoss the minimum loss (dB)
     *
     * no matter how short the distance, the total propagation loss (in
     * dB) will always be greater or equal than this value
     */
    void SetMinLoss(double minLoss);

    /**
     * \return the minimum loss.
     */
    double GetMinLoss(void) const;

    /**
     * \returns the current frequency (Hz)
     */
    double GetFrequency(void) const;

    void SetLossFixedDb(double loss);

  private:
    MmWavePropagationLossModel(const MmWavePropagationLossModel& o);
    MmWavePropagationLossModel& operator=(const MmWavePropagationLossModel& o);
    virtual double DoCalcRxPower(double txPowerDbm,
                                 Ptr<MobilityModel> a,
                                 Ptr<MobilityModel> b) const;
    virtual int64_t DoAssignStreams(int64_t stream);
    void UpDataScenarioMap();

    double m_lambda;
    mutable double m_frequency;
    double m_minLoss;
    mutable channelScenarioMap_t m_channelScenarioMap;
    std::string m_channelStates;
    double m_lossFixedDb;
    bool m_fixedLossTst;
    Ptr<MmWavePhyMacCommon> m_phyMacConfig;
};

} // namespace mmwave

} // namespace ns3

#endif
