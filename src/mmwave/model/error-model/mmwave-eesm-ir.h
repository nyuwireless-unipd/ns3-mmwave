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
#ifndef SRC_MMWAVE_EESM_IR_H
#define SRC_MMWAVE_EESM_IR_H

#include "mmwave-eesm-error-model.h"

namespace ns3
{

namespace mmwave
{

/**
 * \ingroup error-models
 * \brief Eesm error model, based on the IR HARQ
 *
 * In HARQ-IR, every retransmission contains different coded bits than the previous
 * one. The different retransmissions typically use a different set of coding bits.
 * Therefore, both the effective SINR and the equivalent ECR need to be recomputed
 * after each retransmission.
 *
 * In HARQ-IR, the HARQ history contains the last computed effective SINR and
 * number of coded bits of each of the previous retransmissions. Given the current
 * SINR vector and the HARQ history, the effective SINR is computed according to EESM.
 *
 * NOTE: The method GetMcsEq() must be called after ComputeSINR(), as it uses
 * the value m_Reff.
 *
 * Please, don't use this class directly, but one between MmWaveEesmIrT1 or MmWaveEesmIrT2,
 * depending on what table you want to use.
 *
 */
class MmWaveEesmIr : public MmWaveEesmErrorModel
{
  public:
    /**
     * \brief Get the type id of the object
     * \return the type id of the object
     */
    static TypeId GetTypeId(void);
    /**
     * \brief MmWaveEesmIr constructor
     */
    MmWaveEesmIr();
    /**
     * \brief ~MmWaveEesmIr deconstructor
     */
    virtual ~MmWaveEesmIr() override;

  protected:
    // Inherited from MmWaveEesmErrorModel
    /**
     * \brief Computes the effective SINR after retransmission combining with HARQ-IR.
     * Also, it updates the equivalent ECR after retransmissions (m_Reff).
     *
     * \param sinr the SINR vector of current transmission
     * \param map the RB map of current transmission
     * \param sizeBit the Transport block size in bits
     * \param mcs the MCS
     * \param sinrHistory the History of the previous transmissions of the same block
     * \return The effective SINR
     */
    double ComputeSINR(const SpectrumValue& sinr,
                       const std::vector<int>& map,
                       uint8_t mcs,
                       uint32_t sizeBit,
                       const MmWaveErrorModel::MmWaveErrorModelHistory& sinrHistory) const override;

    /**
     * \brief Returns the MCS corresponding to the ECR after retransmissions. In case of
     * HARQ-IR the equivalent ECR changes after retransmissions, and it is updated
     * inside ComputeSINR function. GetMcsEq gets the closest ECR to m_Reff from
     * the available ones that belong to the same modulation order.
     *
     * \param mcsTx the MCS of the transmission
     * \return The equivalent MCS after retransmissions
     */
    double GetMcsEq(uint8_t mcsTx) const override;

  private:
    double m_Reff{0.0}; //!< equivalent effective code rate after retransmissions
};

} // namespace mmwave
} // namespace ns3

#endif // SRC_MMWAVE_EESM_IR_H
