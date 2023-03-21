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

#include "mmwave-amc.h"

#include "mmwave-spectrum-value-helper.h"

#include "ns3/mmwave-eesm-ir-t1.h"
#include <ns3/double.h>
#include <ns3/enum.h>
#include <ns3/log.h>
#include <ns3/math.h>
#include <ns3/mmwave-lte-mi-error-model.h>
#include <ns3/object-factory.h>
#include <ns3/uinteger.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveAmc");
NS_OBJECT_ENSURE_REGISTERED(MmWaveAmc);

MmWaveAmc::MmWaveAmc()
{
    NS_ABORT_MSG("This constructor should not be used!");
}

MmWaveAmc::MmWaveAmc(const Ptr<MmWavePhyMacCommon> phyMacParams)
    : m_phyMacConfig{phyMacParams}
{
}

MmWaveAmc::~MmWaveAmc()
{
}

void
MmWaveAmc::SetDlMode()
{
    NS_LOG_FUNCTION(this);
    m_emMode = MmWaveErrorModel::DL;
}

void
MmWaveAmc::SetUlMode()
{
    NS_LOG_FUNCTION(this);
    m_emMode = MmWaveErrorModel::UL;
}

TypeId
MmWaveAmc::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveAmc")
            .SetParent<Object>()
            .AddAttribute("AmcModel",
                          "AMC model used to assign CQI",
                          EnumValue(MmWaveAmc::ErrorModel),
                          MakeEnumAccessor(&MmWaveAmc::SetAmcModel, &MmWaveAmc::GetAmcModel),
                          MakeEnumChecker(MmWaveAmc::ErrorModel,
                                          "ErrorModel",
                                          MmWaveAmc::ShannonModel,
                                          "ShannonModel"))
            .AddAttribute("Ber",
                          "The target BER, used for assigning the MCS"
                          "This parameter is used only by the ShannonModel",
                          DoubleValue(0.00001),
                          MakeDoubleAccessor(&MmWaveAmc::SetBer),
                          MakeDoubleChecker<double>())
            .AddAttribute(
                "ErrorModelType",
                "Type of the Error Model to use when AmcModel is set to ErrorModel. "
                "This parameter has to match the ErrorModelType in mmwave-spectrum-model,"
                "because they need to refer to same MCS tables and indexes",
                TypeIdValue(MmWaveEesmIrT1::GetTypeId()),
                MakeTypeIdAccessor(&MmWaveAmc::SetErrorModelType, &MmWaveAmc::GetErrorModelType),
                MakeTypeIdChecker())
            .AddConstructor<MmWaveAmc>();
    return tid;
}

TypeId
MmWaveAmc::GetInstanceTypeId() const
{
    return MmWaveAmc::GetTypeId();
}

void
MmWaveAmc::SetBer(double ber)
{
    m_ber = ber;
}

uint8_t
MmWaveAmc::GetMcsFromCqi(uint8_t cqi) const
{
    NS_LOG_FUNCTION(cqi);
    NS_ASSERT_MSG(cqi >= 0 && cqi <= 15, "CQI must be in [0..15] = " << cqi);

    double spectralEfficiency = m_errorModel->GetSpectralEfficiencyForCqi(cqi);
    uint8_t mcs = 0;

    while ((mcs < m_errorModel->GetMaxMcs()) &&
           (m_errorModel->GetSpectralEfficiencyForMcs(mcs + 1) <= spectralEfficiency))
    {
        ++mcs;
    }

    NS_LOG_LOGIC("mcs = " << mcs);

    return mcs;
}

uint32_t
MmWaveAmc::CalculateTbSize(uint8_t mcs, uint8_t nSym) const
{
    NS_LOG_FUNCTION(this << +mcs);

    NS_ASSERT_MSG(mcs <= m_errorModel->GetMaxMcs(),
                  "MCS=" << +mcs << " while maximum MCS is " << +(m_errorModel->GetMaxMcs()));

    uint32_t payloadSize = GetPayloadSize(mcs, nSym);
    uint32_t tbSize = payloadSize;

    if (payloadSize >= m_crcLen)
    {
        tbSize = payloadSize - m_crcLen; // subtract parity bits of m_crcLen used in transport block
    }
    uint32_t cbSize =
        m_errorModel->GetMaxCbSize(payloadSize,
                                   mcs); // max size of a code block (including m_crcLen)
    if (tbSize > cbSize)                 // segmentation of the transport block occurs
    {
        double C = ceil(tbSize / cbSize);
        tbSize = payloadSize -
                 static_cast<uint32_t>(C * m_crcLen); // subtract bits of m_crcLen used in code
                                                      // blocks, in case of code block segmentation
    }

    NS_LOG_INFO(" mcs:" << (unsigned)mcs << " TB size:" << tbSize);

    return tbSize;
}

uint8_t
MmWaveAmc::GetMinNumSymForTbSize(uint32_t tbSize, uint8_t mcs) const
{
    uint32_t effTbSize{0};
    uint8_t numSym{0};
    while (effTbSize < tbSize && numSym < m_phyMacConfig->GetSymbPerSlot())
    {
        numSym++;
        effTbSize = CalculateTbSize(mcs, numSym);
    }
    NS_ABORT_MSG_IF(effTbSize < tbSize, "No way to create such TB size, something went wrong!");

    return numSym;
}

uint32_t
MmWaveAmc::GetPayloadSize(uint8_t mcs, uint8_t nSym) const
{
    uint32_t effNumRb{static_cast<uint32_t>(nSym) * m_phyMacConfig->GetNumRb()};
    return m_errorModel->GetPayloadSize(MmWavePhyMacCommon::SUBCARRIERS_PER_RB -
                                            MmWavePhyMacCommon::REF_SUBCARRIERS_PER_RB,
                                        mcs,
                                        effNumRb,
                                        m_emMode);
}

uint8_t
MmWaveAmc::CreateCqiFeedbackWbTdma(const SpectrumValue& sinr, uint8_t& mcs) const
{
    NS_LOG_FUNCTION(this);

    // produces a single CQI/MCS value

    // std::vector<int> cqi;
    uint8_t cqi = 0;
    double seAvg = 0;
    double mcsAvg = 0;
    double cqiAvg = 0;

    Values::const_iterator it;
    if (m_amcModel == ShannonModel)
    {
        uint32_t rbNum = 0;
        for (it = sinr.ConstValuesBegin(); it != sinr.ConstValuesEnd(); it++)
        {
            double itSinr = (*it);
            if (itSinr == 0.0)
            {
                // cqi.push_back (-1); // SINR == 0 (linear units) means no signal in this RB
            }
            else
            {
                /*
                 * Compute the spectral efficiency from the SINR
                 *                                        SINR
                 * spectralEfficiency = log2 (1 + -------------------- )
                 *                                    -ln(5*BER)/1.5
                 * NB: SINR must be expressed in linear units
                 */

                double se = log2(1 + (itSinr / ((-std::log(5.0 * m_ber)) / 1.5)));
                seAvg += se;

                int cqi = GetCqiFromSpectralEfficiency(se);
                mcsAvg += GetMcsFromSpectralEfficiency(se);
                cqiAvg += cqi;
                rbNum++;

                NS_LOG_LOGIC(" PRB =" << sinr.GetSpectrumModel()->GetNumBands() << ", sinr = "
                                      << itSinr << " (=" << 10 * std::log10(itSinr) << " dB)"
                                      << ", spectral efficiency =" << se << ", CQI = " << cqi
                                      << ", BER = " << m_ber);
                // cqi.push_back (cqi);
            }
        }
        seAvg /= rbNum;
        mcsAvg /= rbNum;
        cqiAvg /= rbNum;
        cqi = ceil(cqiAvg);                        // GetCqiFromSpectralEfficiency (seAvg);
        mcs = GetMcsFromSpectralEfficiency(seAvg); // ceil(mcsAvg);
    }
    else if (m_amcModel == ErrorModel)
    {
        std::vector<int> rbMap;
        int rbId = 0;
        for (it = sinr.ConstValuesBegin(); it != sinr.ConstValuesEnd(); it++)
        {
            if (*it != 0.0)
            {
                rbMap.push_back(rbId);
            }
            rbId += 1;
        }

        mcs = 0;
        Ptr<MmWaveErrorModelOutput> output;
        while (mcs <= m_errorModel->GetMaxMcs())
        {
            output =
                m_errorModel->GetTbDecodificationStats(sinr,
                                                       rbMap,
                                                       CalculateTbSize(mcs, m_numSymForCqi),
                                                       mcs,
                                                       MmWaveErrorModel::MmWaveErrorModelHistory());
            if (output->m_tbler > 0.1)
            {
                break;
            }
            mcs++;
        }

        if (mcs > 0)
        {
            mcs--;
        }

        if ((output->m_tbler > 0.1) && (mcs == 0))
        {
            cqi = 0;
        }
        else if (mcs == m_errorModel->GetMaxMcs())
        {
            cqi = 15; // all MCSs can guarantee the 10 % of BER
        }
        else
        {
            double s = m_errorModel->GetSpectralEfficiencyForMcs(mcs);
            cqi = 0;
            while ((cqi < 15) && (m_errorModel->GetSpectralEfficiencyForCqi(cqi + 1) <= s))
            {
                ++cqi;
            }
        }
        NS_LOG_DEBUG(this << "\t MCS " << (uint16_t)mcs << "-> CQI " << cqi);
    }
    return cqi;
}

uint8_t
MmWaveAmc::GetCqiFromSpectralEfficiency(double s) const
{
    NS_LOG_FUNCTION(s);
    NS_ASSERT_MSG(s >= 0.0, "negative spectral efficiency = " << s);
    uint8_t cqi = 0;
    while ((cqi < 15) && (m_errorModel->GetSpectralEfficiencyForCqi(cqi + 1) < s))
    {
        ++cqi;
    }
    NS_LOG_LOGIC("cqi = " << cqi);
    return cqi;
}

uint8_t
MmWaveAmc::GetMcsFromSpectralEfficiency(double s) const
{
    NS_LOG_FUNCTION(s);
    NS_ASSERT_MSG(s >= 0.0, "negative spectral efficiency = " << s);
    uint8_t mcs = 0;
    while ((mcs < m_errorModel->GetMaxMcs()) &&
           (m_errorModel->GetSpectralEfficiencyForMcs(mcs + 1) < s))
    {
        ++mcs;
    }
    NS_LOG_LOGIC("cqi = " << mcs);
    return mcs;
}

uint32_t
MmWaveAmc::GetMaxMcs() const
{
    NS_LOG_FUNCTION(this);
    return m_errorModel->GetMaxMcs();
}

void
MmWaveAmc::SetAmcModel(MmWaveAmc::AmcModel m)
{
    NS_LOG_FUNCTION(this);
    m_amcModel = m;
}

MmWaveAmc::AmcModel
MmWaveAmc::GetAmcModel() const
{
    NS_LOG_FUNCTION(this);
    return m_amcModel;
}

void
MmWaveAmc::SetErrorModelType(const TypeId& type)
{
    NS_LOG_FUNCTION(this);
    ObjectFactory factory;
    m_errorModelType = type;

    factory.SetTypeId(m_errorModelType);
    m_errorModel = DynamicCast<MmWaveErrorModel>(factory.Create());
    NS_ASSERT(m_errorModel != nullptr);
}

TypeId
MmWaveAmc::GetErrorModelType() const
{
    NS_LOG_FUNCTION(this);
    return m_errorModelType;
}

} // end namespace mmwave

} // end namespace ns3
