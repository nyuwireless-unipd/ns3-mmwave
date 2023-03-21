/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Adapted from the release 1.0 of the 5G-LENA simulator, please refer to https://5g-lena.cttc.es/
 * for further details and https://gitlab.com/cttc-lena/nr/-/tree/v1.0 for the reference code.
 *
 *   Copyright (c) 2019 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2021 University of Padova, Dep. of Information Engineering, SIGNET lab.
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

#ifndef SRC_MMWAVE_MODEL_MMWAVE_AMC_H_
#define SRC_MMWAVE_MODEL_MMWAVE_AMC_H_

#include "mmwave-phy-mac-common.h"

#include <ns3/mmwave-error-model.h>

namespace ns3
{

namespace mmwave
{

/**
 * \ingroup error-models
 * \brief Adaptive Modulation and Coding class for the MmWave module
 *
 * The class has two option to calculate the CQI feedback (which is the MCS to use
 * in the future transmissions): the "ShannonModel" or the "ErrorModel" model,
 * which uses the output of an error model to find the optimal MCS.
 *
 * Please note that it is necessary, even when using the ShannonModel, to correctly
 * configure the ErrorModel type, which must be the same as the one set in the
 * MmWaveSpectrumPhy class.
 *
 * \todo Pass MmWaveAmc parameters through RRC, and don't pass pointers to AMC
 * between GNB and UE
 */
class MmWaveAmc : public Object
{
  public:
    /**
     * \brief GetTypeId
     * \return the TypeId of the Object
     */
    static TypeId GetTypeId(void);

    /**
     * \brief GetInstanceTypeId
     * \return the instance typeid
     */
    TypeId GetInstanceTypeId() const override;

    /**
     * \brief MmWaveAmc constructor, not to be used!
     */
    MmWaveAmc();

    /**
     * \brief MmWaveAmc proper constructor
     */
    MmWaveAmc(const Ptr<MmWavePhyMacCommon> phyMacParams);

    /**
     * \brief ~MmWaveAmc deconstructor
     */
    virtual ~MmWaveAmc() override;

    /**
     * \brief Set the target BER.
     *
     * Please note that this parameter is used only when the ShannonModel is set.
     *
     * \param ber the BER
     */
    void SetBer(double ber);

    /**
     * \brief Set the object to be in "DL" mode.
     *
     * In this mode, all the requests made to the underlying error model
     * will be done keeping in consideration that the requests refers to
     * DL transmissions.
     */
    void SetDlMode();

    /**
     * \brief Set the object to be in "UL" mode.
     *
     * In this mode, all the requests made to the underlying error model
     * will be done keeping in consideration that the requests refers to
     * UL transmissions.
     */
    void SetUlMode();

    /**
     * \brief Valid types of the model used to create a cqi feedback
     *
     * \see CreateCqiFeedbackWbTdma
     */
    enum AmcModel
    {
        ShannonModel, //!< Shannon based model (very conservative)
        ErrorModel //!< Error Model version (can use different error models, see MmWaveErrorModel)
    };

    /**
     * \brief Get the MCS value from a CQI value
     * \param cqi the CQI
     * \return the MCS that corresponds to that CQI (it depends on the error model)
     */
    uint8_t GetMcsFromCqi(uint8_t cqi) const;

    /**
     * \brief Create a CQI/MCS wideband feedback from a SINR values
     *
     * For CQI creation, a CSI reference resource equal to all RBs in
     * which the gNB/UE has transmitted power, and from which the SINR can be
     * measured, during 1 OFDM symbol, is assumed.
     *
     * \param sinr the sinr values
     * \param mcsWb The calculated MCS
     * \return The calculated CQI
     */
    uint8_t CreateCqiFeedbackWbTdma(const SpectrumValue& sinr, uint8_t& mcsWb) const;

    /**
     * \brief Get CQI from a SpectralEfficiency value
     * \param s spectral efficiency
     * \return the CQI (depends on the Error Model)
     */
    uint8_t GetCqiFromSpectralEfficiency(double s) const;

    /**
     * \brief Get MCS from a SpectralEfficiency value
     * \param s spectral efficiency
     * \return the MCS (depends on the Error Model)
     */
    uint8_t GetMcsFromSpectralEfficiency(double s) const;

    /**
     * \brief Get the maximum MCS (depends on the underlying error model)
     * \return the maximum MCS
     */
    uint32_t GetMaxMcs() const;

    /**
     * \brief Set the AMC model type
     * \param m the AMC model
     */
    void SetAmcModel(AmcModel m);
    /**
     * \brief Get the AMC model type
     * \return the AMC model type
     */
    AmcModel GetAmcModel() const;

    /**
     * \brief Set Error model type
     * \param type the Error model type
     */
    void SetErrorModelType(const TypeId& type);

    /**
     * \brief Get the error model type
     * \return the error model type
     */
    TypeId GetErrorModelType() const;

    /**
     * \brief Calculate the TransportBlock size (in bytes) giving the MCS and the number of
     * allocated OFDM symbols
     *
     * The actual implementation depends on the chosen error model and the "mode" configured with
     * SetMode(). Since the mmWave schedulers operate in TDMA mode, all the available Physical RBs
     * are assumed to be scheduled for the transmission.
     *
     * \param mcs the MCS of the transmission
     * \param nSym the number of allocated OFDM symbols
     * \return the TBS in bytes
     */
    uint32_t CalculateTbSize(uint8_t mcs, uint8_t nSym) const;

    /**
     * \brief Calculate the min number of OFDM symbols needed to transmit a TB of given size (in
     * bytes).
     *
     * The actual implementation depends on the chosen error model and the "mode" configured with
     * SetMode(). Since the mmWave schedulers operate in TDMA mode, all the available Physical RBs
     * are assumed to be scheduled for the transmission.
     *
     * \param tbSize the TB size
     * \param mcs the MCS of the transmission
     * \return the amount of OFDM symbols
     */
    uint8_t GetMinNumSymForTbSize(uint32_t tbSize, uint8_t mcs) const;

    /**
     * \brief Calculate the Payload Size (in bytes) from MCS and the number of allocated OFDM
     * symbols
     *
     * Since the mmWave schedulers operate in TDMA mode, all the available Physical RBs are assumed
     * to be scheduled for the transmission.
     *
     * \param mcs MCS of the transmission
     * \param nSym the number of allocated OFDM symbols
     * \return the payload size in bytes
     */
    uint32_t GetPayloadSize(uint8_t mcs, uint8_t nSym) const;

  private:
    double m_ber;                       //!< The target BER. Used only by the ShannonModel AMC
    AmcModel m_amcModel;                //!< Type of the CQI feedback model
    Ptr<MmWaveErrorModel> m_errorModel; //!< Pointer to an instance of ErrorModel
    TypeId m_errorModelType;            //!< Type of the error model
    MmWaveErrorModel::Mode m_emMode{MmWaveErrorModel::DL}; //!< Error model mode
    static const unsigned int m_crcLen = 24 / 8;           //!< CRC length (in bytes)
    static const unsigned int m_numSymForCqi =
        12; //!< The number of PDSCH OFDM symbols to be used for CQI determination. See Sec. 5.2.2.5
            //!< of TS 38.214
    Ptr<MmWavePhyMacCommon> m_phyMacConfig; //!< Pointer to an instance of MmWavePhyMacCommon
};

} // end namespace mmwave

} // end namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_AMC_H_ */
