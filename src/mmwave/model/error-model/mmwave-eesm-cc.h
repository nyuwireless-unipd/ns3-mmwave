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
#ifndef SRC_MMWAVE_EESM_CC_H
#define SRC_MMWAVE_EESM_CC_H

#include "mmwave-eesm-error-model.h"

namespace ns3
{

namespace mmwave
{

/**
 * \ingroup error-models
 * \brief The MmWaveEesmCc class
 *
 * In HARQ-CC, every retransmission contains the same coded bits
 * (information and coding bits). Therefore, the ECR after the q-th retransmission
 * remains the same as after the first transmission. Only the effective SINR
 * varies after combining retransmissions. In this case, the SINR values of the
 * corresponding resources are summed across the retransmissions, and the combined
 * SINR values are used to get the effective SINR based on EESM.
 *
 * In HARQ-CC, the HARQ history contains the SINR per allocated RB. Given the current
 * SINR vector and RB map, and the HARQ history, the effective SINR is computed
 * according to EESM.
 *
 * Please, don't use this class directly, but one between MmWaveEesmCcT1 or MmWaveEesmCcT2,
 * depending on what table you want to use.
 */
class MmWaveEesmCc : public MmWaveEesmErrorModel
{
  public:
    /**
     * \brief Get the type id of the object
     * \return the type id of the object
     */
    static TypeId GetTypeId(void);
    /**
     * \brief MmWaveEesmCc constructor
     */
    MmWaveEesmCc();
    /**
     * \brief ~MmWaveEesmCc
     */
    virtual ~MmWaveEesmCc() override;

  protected:
    /**
     * \brief Computes the effective SINR after retransmission combining with HARQ-CC.
     *
     * \param sinr the SINR vector of current transmission
     * \param map the RB map of current transmission
     * \param sizeBit the Transport block size in bits
     * \param mcs the MCS of the transmission
     * \param sinrHistory the History of the previous transmissions of the same block
     * \return The effective SINR
     */
    double ComputeSINR(const SpectrumValue& sinr,
                       const std::vector<int>& map,
                       uint8_t mcs,
                       uint32_t sizeBit,
                       const MmWaveErrorModel::MmWaveErrorModelHistory& sinrHistory) const override;

    /**
     * \brief Returns the MCS corresponding to the ECR after retransmissions. As the ECR
     * does not change with retransmissions with HARQ-CC, and MCS is kept fixed through
     * retransmissions, it returns current MCS.
     *
     * \param mcsTx the MCS of the transmission
     * \return The equivalent MCS after retransmissions
     */
    double GetMcsEq(uint8_t mcsTx) const override;
};

} // namespace mmwave
} // namespace ns3

#endif // SRC_MMWAVE_EESM_CC_H
