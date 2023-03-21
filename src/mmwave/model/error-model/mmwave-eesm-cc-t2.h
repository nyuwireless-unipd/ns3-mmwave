/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Adapted from the release 1.0 of the 5G-LENA simulator, please refer to https://5g-lena.cttc.es/
 * for further details and https://gitlab.com/cttc-lena/nr/-/tree/v1.0 for the reference code.
 *
 *   Copyright (c) 2020 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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
 */
#ifndef SRC_MMWAVE_EESM_CC_T2_H
#define SRC_MMWAVE_EESM_CC_T2_H

#include "mmwave-eesm-cc.h"
#include "mmwave-eesm-t2.h"

namespace ns3
{

namespace mmwave
{

/**
 * \ingroup error-models
 * \brief The MmWaveEesmCcT2 class
 *
 * Class that implements the CC-HARQ combining with Table 2. It can be used
 * directly in the code.
 */
class MmWaveEesmCcT2 : public MmWaveEesmCc
{
  public:
    /**
     * \brief Get the type id of the object
     * \return the type id of the object
     */
    static TypeId GetTypeId(void);
    /**
     * \brief MmWaveEesmCcT2 constructor
     */
    MmWaveEesmCcT2();
    /**
     * \brief ~MmWaveEesmCcT2 deconstructor
     */
    virtual ~MmWaveEesmCcT2();

  protected:
    virtual const std::vector<double>* GetBetaTable() const override;
    virtual const std::vector<double>* GetMcsEcrTable() const override;
    virtual const SimulatedBlerFromSINR* GetSimulatedBlerFromSINR() const override;
    virtual const std::vector<uint8_t>* GetMcsMTable() const override;
    virtual const std::vector<double>* GetSpectralEfficiencyForMcs() const override;
    virtual const std::vector<double>* GetSpectralEfficiencyForCqi() const override;

  private:
    MmWaveEesmT2 m_t2; //!< The reference table
};

} // namespace mmwave
} // namespace ns3

#endif // SRC_MMWAVE_EESM_CC_T2_H
