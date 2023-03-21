/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Adapted from the release 1.0 of the 5G-LENA simulator, please refer to https://5g-lena.cttc.es/
 * for further details and https://gitlab.com/cttc-lena/nr/-/tree/v1.0 for the reference code.
 *
 *   Copyright (c) 2019 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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

#ifndef SRC_MMWAVE_MODEL_MMWAVE_ERRORMODEL_H_
#define SRC_MMWAVE_MODEL_MMWAVE_ERRORMODEL_H_

#include <ns3/object.h>
#include <ns3/spectrum-value.h>

#include <vector>

namespace ns3
{

namespace mmwave
{

/**
 * \ingroup error-models
 * \brief Store the output of an MmWaveErrorModel
 *
 */
struct MmWaveErrorModelOutput : public SimpleRefCount<MmWaveErrorModelOutput>
{
    /**
     * \brief MmWaveErrorModelOutput default constructor (deleted)
     */
    MmWaveErrorModelOutput() = delete;

    /**
     * \brief Official MmWaveErrorModelOutput constructor
     * \param tbler transport block error rate to store
     */
    MmWaveErrorModelOutput(double tbler)
        : m_tbler(tbler)
    {
    }

    /**
     * \brief ~MmWaveErrorModelOutput
     */
    virtual ~MmWaveErrorModelOutput()
    {
    }

    double m_tbler{0.0}; //!< Transport Block Error Rate
};

/**
 * \ingroup error-models
 * \brief Interface for calculating the error probability for a transport block
 *
 * Any error model that wishes to work in Spectrum or in AMC should use
 * this class as a base class. Please implement The GetInstanceTypeId method
 * in your subclasses.
 *
 * \section nr_error_model_conf Configuration
 *
 * The type of the error model can be configured through the helper method
 * MmWaveHelper::SetUlErrorModel() or MmWaveHelper::SetDlErrorModel().
 *
 * The types of error model that can be used are the following:
 * MmWaveEesmIrT2, MmWaveEesmIrT1, MmWaveEesmCcT1, MmWaveEesmCcT2, MmWaveLteMiErrorModel.
 *
 * \see GetTbDecodificationStats
 * \see MmWaveEesmIrT2
 * \see MmWaveEesmIrT1
 * \see MmWaveEesmCcT1
 * \see MmWaveEesmCcT2
 * \see MmWaveLteMiErrorModel
 */
class MmWaveErrorModel : public Object
{
  public:
    /**
     * \brief GetTypeId
     * \return the TypeId of the class
     */
    static TypeId GetTypeId();

    /**
     * \brief Get the type ID of this instance
     * \return the Type ID of this instance
     */
    TypeId GetInstanceTypeId(void) const override;

    /**
     * \brief MmWaveErrorModel default constructor
     */
    MmWaveErrorModel();

    /**
     * \brief deconstructor
     */
    virtual ~MmWaveErrorModel() override;

    /**
     * \brief Indicate the mode (UL or DL)
     *
     * In some methods, the error model has to know if the asked value
     * is for UL or DL.
     */
    enum Mode
    {
        DL, //!< DL
        UL  //!< UL
    };

    /**
     * \brief Vector of previous output
     *
     *
     * Used in case of HARQ: any result will ve stored in this vector and used
     * to decode next retransmissions.
     */
    typedef std::vector<Ptr<MmWaveErrorModelOutput>> MmWaveErrorModelHistory;

    /**
     * \brief Get an output for the decodification error probability of a given
     * transport block.
     *
     * The subclasses can store more information by subclassing the MmWaveErrorModelOutput
     * class, and returning a casted instance. The error model should take into
     * consideration the history, even if some time (e.g., when called by the AMC
     * or when called the first time by the spectrum model) the history will be
     * empty.
     *
     * This method should not return a nullptr, ever.
     *
     * \param sinr SINR vector
     * \param map RB map
     * \param size Transport block size
     * \param mcs MCS
     * \param history History of the retransmission
     * \return A pointer to an output, with the tbler and other customized values
     */
    virtual Ptr<MmWaveErrorModelOutput> GetTbDecodificationStats(
        const SpectrumValue& sinr,
        const std::vector<int>& map,
        uint32_t size,
        uint8_t mcs,
        const MmWaveErrorModelHistory& history) = 0;

    /**
     * \brief Get the SpectralEfficiency for a given CQI
     * \param cqi CQI to take into consideration
     * \return the spectral efficiency
     */
    virtual double GetSpectralEfficiencyForCqi(uint8_t cqi) = 0;

    /**
     * \brief Get the SpectralEfficiency for a given MCS
     * \param mcs MCS to take into consideration
     * \return the spectral efficiency
     */
    virtual double GetSpectralEfficiencyForMcs(uint8_t mcs) const = 0;

    /**
     * \brief Get the payload size (in bytes) for a given mcs and resource block number
     *
     * \param usefulSc Useful subcarriers
     * \param mcs MCS
     * \param rbNum Number of resource blocks (even in more than 1 symbol)
     * \param mode UL or DL mode
     * \return The payload size of the resource blocks, in bytes
     */
    virtual uint32_t GetPayloadSize(uint32_t usefulSc,
                                    uint8_t mcs,
                                    uint32_t rbNum,
                                    Mode mode) const = 0;

    /**
     * \brief Get the maximum codeblock size
     *
     * \param tbSize Transport block size for which calculate the CB size
     * \param mcs MCS of the transmission
     * \return the codeblock size
     */
    virtual uint32_t GetMaxCbSize(uint32_t tbSize, uint8_t mcs) const = 0;

    /**
     * \brief Get the maximum MCS
     *
     * \return the maximum MCS that is permitted with the error model
     */
    virtual uint8_t GetMaxMcs() const = 0;
};

} // namespace mmwave
} // namespace ns3

#endif // SRC_MMWAVE_MODEL_MMWAVE_ERRORMODEL_H_
