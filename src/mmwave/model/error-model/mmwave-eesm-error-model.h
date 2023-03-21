/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2018 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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

#ifndef SRC_MMWAVE_EESM_ERROR_MODEL_H
#define SRC_MMWAVE_EESM_ERROR_MODEL_H

#include "mmwave-error-model.h"

#include <map>

class MmWaveL2smEesmTestCase;

namespace ns3
{

namespace mmwave
{

/**
 * \ingroup error-models
 * \brief The MmWaveEesmErrorModelOutput struct
 *
 * Error model output returned by the class MmWaveEesmErrorModel.
 * \see MmWaveEesmErrorModel
 */
struct MmWaveEesmErrorModelOutput : public MmWaveErrorModelOutput
{
    /**
     * \brief MmWaveEesmErrorModelOutput constructor (deleted)
     */
    MmWaveEesmErrorModelOutput() = delete;

    /**
     * \brief MmWaveEesmErrorModelOutput constructor to use
     * \param tbler the reference TBler
     */
    MmWaveEesmErrorModelOutput(double tbler)
        : MmWaveErrorModelOutput(tbler)
    {
    }

    double m_sinrEff{0.0};  //!< Effective SINR
    SpectrumValue m_sinr;   //!< perceived SINRs in the whole bandwidth
    std::vector<int> m_map; //!< map of the active RBs
    uint32_t m_infoBits{0}; //!< number of info bits
    uint32_t m_codeBits{0}; //!< number of code bits
};

/**
 * \ingroup error-models
 *
 * \brief Eesm error model
 *
 * This class provides the BLER estimation based on EESM metrics, assuming LDPC
 * coding with block segmentation as per TS 38.212 Sect. 5.2.2, and modulation
 * and coding of MCS Table1/Table2 in TS 38.214 including up to 256-QAM. The MCS
 * and CQI Tables of NR (Table1/Table2) are specified in McsTable. The BLER-SINR
 * curves are obtained from a link level simulator (from ID) that uses LDPC
 * coding and said MCSs. In case of HARQ, the model currently follows HARQ with
 * Chase Combining, so that the SINReff is updated, but not the ECR, as per
 * IEEE 802.16m-08/004r2.
 *
 * The classes to use in your simulations are:
 *
 * * MmWaveEesmIrT1, for IR - Table 1
 * * MmWaveEesmIrT2, for IR - Table 2
 * * MmWaveEesmCcT1, for CC - Table 1
 * * MmWaveEesmCcT2, for CC - Table 2
 *
 * We provide the implementation of the Chase Combining-HARQ and the IR-HARQ
 * in MmWaveEesmCc and MmWaveEesmIr, respectively.
 *
 * \see MmWaveEesmIrT1
 * \see MmWaveEesmIrT2
 * \see MmWaveEesmCcT1
 * \see MmWaveEesmCcT2
 */
class MmWaveEesmErrorModel : public MmWaveErrorModel
{
  public:
    friend MmWaveL2smEesmTestCase;
    /**
     * \brief GetTypeId
     * \return the type id of the object
     */
    static TypeId GetTypeId();

    /**
     * \brief Get the type ID of this instance
     * \return the Type ID of this instance
     */
    TypeId GetInstanceTypeId(void) const override;

    /**
     * \brief MmWaveEesmErrorModel constructor
     */
    MmWaveEesmErrorModel();
    /**
     * \brief ~MmWaveEesmErrorModel
     */
    virtual ~MmWaveEesmErrorModel() override;

    /**
     * \brief Get an output for the decodification error probability of a given
     * transport block, assuming the EESM method, NR LDPC coding and block
     * segmentation, MCSs Table1/Table2 in NR, and HARQ based on CC.
     *
     * \param sinr SINR vector
     * \param map RB map
     * \param size Transport block size in Bytes
     * \param mcs MCS
     * \param sinrHistory History of the retransmission
     * \return A pointer to an output, with the tbler and SINR vector, effective
     * SINR, RB map, code bits, and info bits.
     */
    virtual Ptr<MmWaveErrorModelOutput> GetTbDecodificationStats(
        const SpectrumValue& sinr,
        const std::vector<int>& map,
        uint32_t size,
        uint8_t mcs,
        const MmWaveErrorModelHistory& sinrHistory) override;

    /**
     * \brief Get the SE for a given CQI, following the CQIs in NR Table1/Table2
     * in TS38.214
     */
    virtual double GetSpectralEfficiencyForCqi(uint8_t cqi) override;
    /**
     * \brief Get the SE for a given MCS, following the MCSs in NR Table1/Table2
     * in TS38.214
     */
    virtual double GetSpectralEfficiencyForMcs(uint8_t mcs) const override;
    /**
     * \brief Get the payload size in Bytes, following the MCSs in NR. It follows
     * TS 38.214 Section 5.1.3.2 (DL) and 6.1.4.2 (UL) but without including
     * quantizations and and limits (i.e., only up to Step 2)
     * \param usefulSc the number of useful subcarrier per RB, substracting DMRS overhead
     * \param mcs MCS
     * \param rbNum the number of RBs (time x frequency)
     * \param mode Mode
     *
     */
    virtual uint32_t GetPayloadSize(uint32_t usefulSc,
                                    uint8_t mcs,
                                    uint32_t rbNum,
                                    Mode mode) const override;
    /**
     * \brief Get the maximum code block size in Bytes, as per NR. It depends on the LDPC
     * base graph type
     * \param tbSize Transport block size in Bytes
     * \param mcs MCS
     */
    virtual uint32_t GetMaxCbSize(uint32_t tbSize, uint8_t mcs) const override;
    /**
     * \brief Get the maximum MCS. It depends on NR tables being used
     */
    virtual uint8_t GetMaxMcs() const override;

    typedef std::vector<double> DoubleVector;
    typedef std::tuple<DoubleVector, DoubleVector> DoubleTuple;
    typedef std::vector<std::vector<std::map<uint32_t, DoubleTuple>>> SimulatedBlerFromSINR;

  protected:
    /**
     * \brief function to print the RB map
     * \param map the RB map
     * \return a string that contains the RB map in a readable way
     */
    std::string PrintMap(const std::vector<int>& map) const;

    /**
     * \brief compute the effective SINR for the specified MCS and SINR, according
     * to the EESM method
     *
     * \param sinr the perceived sinrs in the whole bandwidth (vector, per RB)
     * \param map the actives RBs for the TB
     * \param mcs the MCS of the TB
     * \return the effective SINR
     */
    double SinrEff(const SpectrumValue& sinr, const std::vector<int>& map, uint8_t mcs) const;

    /**
     * \brief Compute the effective SINR after retransmission combining
     * \param sinr SINR of the new transmission
     * \param map RB map
     * \param mcs MCS of the transmission
     * \param sizeBit size (in bit) of the transmission
     * \param sinrHistory history of the SINR of the previous transmission
     * \return the single SINR value
     *
     * Called in GetTbBitDecodificationStats(). Please implement this function
     * in a way that calculating the SINR of the new transmission
     * takes in consideration the sinr history.
     *
     * \see MmWaveEesmIr
     * \see MmWaveEesmCc
     */
    virtual double ComputeSINR(
        const SpectrumValue& sinr,
        const std::vector<int>& map,
        uint8_t mcs,
        uint32_t sizeBit,
        const MmWaveErrorModel::MmWaveErrorModelHistory& sinrHistory) const = 0;

    /**
     * \brief Get the "Equivalent MCS" after retransmission combining
     * \param mcsTx MCS of the transmission
     * \return the equivalent MCS
     *
     * Called in GetTbDecodificationStats()
     * \see MmWaveEesmIr
     * \see MmWaveEesmCc
     */
    virtual double GetMcsEq(uint8_t mcsTx) const = 0;

    /**
     * \return pointer to a static vector that represents the beta table
     */
    virtual const std::vector<double>* GetBetaTable() const = 0;
    /**
     * \return pointer to a static vector that represents the MCS-ECR table
     */
    virtual const std::vector<double>* GetMcsEcrTable() const = 0;
    /**
     * \return pointer to a table of BLER vs SINR
     */
    virtual const SimulatedBlerFromSINR* GetSimulatedBlerFromSINR() const = 0;
    /**
     * \return pointer to a static vector that represents the MCS-M table
     */
    virtual const std::vector<uint8_t>* GetMcsMTable() const = 0;
    /**
     * \return pointer to a static vector that represents the spectral efficiency for MCS
     */
    virtual const std::vector<double>* GetSpectralEfficiencyForMcs() const = 0;
    /**
     * \return pointer to a static vector that represents the spectral efficiency for CQI
     */
    virtual const std::vector<double>* GetSpectralEfficiencyForCqi() const = 0;

  private:
    static std::vector<std::string> m_bgTypeName; //!< Base graph name

    /**
     * \brief map the effective SINR into CBLER for the specified MCS and CB size,
     * according to the EESM method
     *
     * \param sinrEff effective SINR per bit of a code-block
     * \param mcs the MCS of the TB
     * \param cbSize the size of the CB in BITS
     * \return the code block error rate
     */
    double MappingSinrBler(double sinrEff, uint8_t mcs, uint32_t cbSize);

    /**
     * \brief Get an output for the decodification error probability of a given
     * transport block, assuming the EESM method, NR LDPC coding and block
     * segmentation, MCSs Table1/Table2 in NR, and HARQ based on CC.
     *
     * \param sinr SINR vector
     * \param map RB map
     * \param size Transport block size in BITS
     * \param mcs MCS
     * \param sinrHistory History of the retransmission
     * \return A pointer to an output, with the tbler and SINR vector, effective
     * SINR, RB map, code bits, and info bits.
     */
    Ptr<MmWaveErrorModelOutput> GetTbBitDecodificationStats(
        const SpectrumValue& sinr,
        const std::vector<int>& map,
        uint32_t size,
        uint8_t mcs,
        const MmWaveErrorModelHistory& sinrHistory);

    /**
     * \brief Type of base graph for LDPC coding
     */
    enum GraphType
    {
        FIRST = 0, //!< LDPC base graph 1
        SECOND = 1 //!< LDPC base graph 2
    };

    /**
     * \brief Get Base Graph type of LDPC coding (1 or 2) for the given TBS and MCS
     * of a specific NR table, as per TS 38.212 Section 6.2.2 (UL) and 7.2.2 (DL)
     *
     * \param tbSize the size of the TB (in bits) (A, payload, in TS 38.212)
     * \param mcs the MCS of the TB
     * \return the GraphType used for the TB
     */
    GraphType GetBaseGraphType(uint32_t tbSize, uint8_t mcs) const;

    /**
     * \brief Code Block Segmentation for the given TBS and BG type, as per TS
     * 38.212 Section 5.2.2 (LDPC coding)
     *
     * \param B the size of the TB including transport block CRC attachment
     * (in bits) (B, in TS 38.212)
     * \param the GraphType used for the TB
     * \return std::pair (K,C) being K the number of bits in each code block, C
     * the number of code blocks
     */
    std::pair<uint32_t, uint32_t> CodeBlockSegmentation(uint32_t B, GraphType bg_type) const;

    /**
     * \brief Get SinrDb Vector From Simulated Values
     * \param graphType
     * \param mcs
     * \param cbSizeIndex
     * \return
     */
    const std::vector<double>& GetSinrDbVectorFromSimulatedValues(GraphType graphType,
                                                                  uint8_t mcs,
                                                                  uint32_t cbSizeIndex) const;
    /**
     * \brief Get BLER Vector From Simulated Values
     * \param graphType
     * \param mcs
     * \param cbSizeIndex
     * \return
     */
    const std::vector<double>& GetBLERVectorFromSimulatedValues(GraphType graphType,
                                                                uint8_t mcs,
                                                                uint32_t cbSizeIndex) const;
};

} // namespace mmwave
} // namespace ns3

#endif /* SRC_MMWAVE_EESM_ERROR_MODEL_H */
