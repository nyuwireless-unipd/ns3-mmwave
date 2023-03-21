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

#include "ns3/mmwave-beamforming-model.h"

#include "ns3/boolean.h"
#include "ns3/channel-condition-model.h"
#include "ns3/double.h"
#include "ns3/file-beamforming-codebook.h"
#include "ns3/log.h"
#include "ns3/matrix-based-channel-model.h"
#include "ns3/mmwave-phy-mac-common.h"
#include "ns3/mmwave-spectrum-signal-parameters.h"
#include "ns3/mmwave-spectrum-value-helper.h"
#include "ns3/mobility-model.h"
#include "ns3/net-device.h"
#include "ns3/node.h"
#include "ns3/object-factory.h"
#include "ns3/phased-array-model.h"
#include "ns3/pointer.h"
#include "ns3/string.h"
#include "ns3/uinteger.h"

#include <algorithm>
#include <fstream>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveBeamformingModel");

/*----------------------------------------------------------------------------*/

NS_OBJECT_ENSURE_REGISTERED(MmWaveBeamformingModel);

TypeId
MmWaveBeamformingModel::GetTypeId()
{
    static TypeId tid = TypeId("ns3::MmWaveBeamformingModel")
                            .SetParent<Object>()
                            .AddAttribute("Device",
                                          "The current NetDevice",
                                          PointerValue(0),
                                          MakePointerAccessor(&MmWaveBeamformingModel::SetDevice,
                                                              &MmWaveBeamformingModel::GetDevice),
                                          MakePointerChecker<NetDevice>())
                            .AddAttribute("Antenna",
                                          "The antenna of the Device to configure",
                                          PointerValue(0),
                                          MakePointerAccessor(&MmWaveBeamformingModel::SetAntenna,
                                                              &MmWaveBeamformingModel::GetAntenna),
                                          MakePointerChecker<PhasedArrayModel>());
    return tid;
}

MmWaveBeamformingModel::MmWaveBeamformingModel()
{
    NS_LOG_FUNCTION(this);
}

MmWaveBeamformingModel::~MmWaveBeamformingModel()
{
}

void
MmWaveBeamformingModel::DoDispose()
{
    NS_LOG_FUNCTION(this);
    m_device = 0;
    m_antenna = 0;
}

Ptr<NetDevice>
MmWaveBeamformingModel::GetDevice() const
{
    NS_LOG_FUNCTION(this);
    return m_device;
}

void
MmWaveBeamformingModel::SetDevice(Ptr<NetDevice> device)
{
    NS_LOG_FUNCTION(this << device);
    m_device = device;
}

Ptr<PhasedArrayModel>
MmWaveBeamformingModel::GetAntenna(void) const
{
    NS_LOG_FUNCTION(this);
    return m_antenna;
}

void
MmWaveBeamformingModel::SetAntenna(Ptr<PhasedArrayModel> antenna)
{
    NS_LOG_FUNCTION(this << antenna);
    m_antenna = antenna;
}

/*----------------------------------------------------------------------------*/

NS_OBJECT_ENSURE_REGISTERED(MmWaveDftBeamforming);

TypeId
MmWaveDftBeamforming::GetTypeId()
{
    static TypeId tid = TypeId("ns3::MmWaveDftBeamforming")
                            .SetParent<MmWaveBeamformingModel>()
                            .AddConstructor<MmWaveDftBeamforming>();
    return tid;
}

MmWaveDftBeamforming::MmWaveDftBeamforming()
{
    NS_LOG_FUNCTION(this);
}

MmWaveDftBeamforming::~MmWaveDftBeamforming()
{
}

void
MmWaveDftBeamforming::SetBeamformingVectorForDevice(Ptr<NetDevice> otherDevice,
                                                    Ptr<PhasedArrayModel> otherAntenna)
{
    NS_LOG_FUNCTION(this << otherDevice << otherAntenna);

    // retrieve the position of the two devices
    Ptr<MobilityModel> mobility = m_device->GetNode()->GetObject<MobilityModel>();
    Vector aPos = mobility->GetPosition();

    NS_ASSERT_MSG(otherDevice->GetNode(),
                  "the device " << otherDevice << " is not associated to a node");
    NS_ASSERT_MSG(otherDevice->GetNode()->GetObject<MobilityModel>(),
                  "the device " << otherDevice << " has not a mobility model");
    Vector bPos = otherDevice->GetNode()->GetObject<MobilityModel>()->GetPosition();

    // compute the azimuth and the elevation angles
    Angles completeAngle(bPos, aPos);

    // configure the antenna to use the new beamforming vector
    PhasedArrayModel::ComplexVector antennaWeights = m_antenna->GetBeamformingVector(completeAngle);
    m_antenna->SetBeamformingVector(antennaWeights);

    // compute the azimuth and the elevation angles for the other device
    Angles completeAngleOtherDevice(aPos, bPos);

    // configure the antenna of the other device to use the new beamforming vector
    PhasedArrayModel::ComplexVector otherAntennaWeights =
        otherAntenna->GetBeamformingVector(completeAngleOtherDevice);
    otherAntenna->SetBeamformingVector(otherAntennaWeights);
}

/*----------------------------------------------------------------------------*/

NS_OBJECT_ENSURE_REGISTERED(MmWaveSvdBeamforming);

TypeId
MmWaveSvdBeamforming::GetTypeId()
{
    static TypeId tid =
        TypeId("ns3::MmWaveSvdBeamforming")
            .SetParent<MmWaveBeamformingModel>()
            .AddConstructor<MmWaveSvdBeamforming>()
            .AddAttribute(
                "ChannelModel",
                "Pointer to the MatrixBasedChannelModel object used in the simulation scenario",
                PointerValue(),
                MakePointerAccessor(&MmWaveSvdBeamforming::m_channel),
                MakePointerChecker<MatrixBasedChannelModel>())
            .AddAttribute(
                "MaxIterations",
                "Maximum number of iterations to numerically approximate the SVD decomposition",
                UintegerValue(30),
                MakeUintegerAccessor(&MmWaveSvdBeamforming::m_maxIterations),
                MakeUintegerChecker<uint32_t>())
            .AddAttribute("Tolerance",
                          "Tolerance to numerically approximate the SVD decomposition",
                          DoubleValue(1e-8),
                          MakeDoubleAccessor(&MmWaveSvdBeamforming::m_tolerance),
                          MakeDoubleChecker<double>())
            .AddAttribute("UseCache",
                          "Use the cache for the BF vectors. Do not set it to false unless you "
                          "have very good reasons",
                          BooleanValue(true),
                          MakeBooleanAccessor(&MmWaveSvdBeamforming::m_useCache),
                          MakeBooleanChecker());
    return tid;
}

MmWaveSvdBeamforming::MmWaveSvdBeamforming()
    : m_useCache{false}
{
    NS_LOG_FUNCTION(this);
}

MmWaveSvdBeamforming::~MmWaveSvdBeamforming()
{
}

void
MmWaveSvdBeamforming::DoDispose(void)
{
    NS_LOG_FUNCTION(this);
    m_channel = 0;
    MmWaveBeamformingModel::DoDispose();
}

void
MmWaveSvdBeamforming::SetBeamformingVectorForDevice(Ptr<NetDevice> otherDevice,
                                                    Ptr<PhasedArrayModel> otherAntenna)
{
    NS_LOG_FUNCTION(this << otherDevice << otherAntenna);

    Ptr<MobilityModel> thisMob = m_device->GetNode()->GetObject<MobilityModel>();
    NS_ASSERT_MSG(thisMob, "This device " << m_device << " does not have a mobility model");
    Ptr<MobilityModel> otherMob = otherDevice->GetNode()->GetObject<MobilityModel>();
    NS_ASSERT_MSG(otherMob, "The otherDevice " << otherDevice << " does not have a mobility model");

    // this will trigger a new computation (if needed)
    auto channelMatrix = m_channel->GetChannel(thisMob, otherMob, m_antenna, otherAntenna);

    std::pair<PhasedArrayModel::ComplexVector, PhasedArrayModel::ComplexVector> bfVectors;

    bool toCache{false};

    if (m_useCache)
    {
        auto entry{m_cacheChannelMap.find(otherDevice)};
        if (entry != m_cacheChannelMap.end() &&
            entry->second == channelMatrix) // hit: the channel was already cached
        {
            NS_LOG_DEBUG("channel cached " << channelMatrix);
            bfVectors = m_cacheBfVectors.find(otherDevice)->second;
        }
        else
        {
            NS_LOG_DEBUG("new channel " << channelMatrix);
            toCache = true;
        }
    }

    if (!m_useCache || toCache)
    {
        if (channelMatrix->m_channel.GetNumPages() == 0)
        {
            NS_LOG_LOGIC("Channel has no MPCs");

            uint64_t thisAntennaNumElements = m_antenna->GetNumberOfElements();
            uint64_t otherAntennaNumElements = otherAntenna->GetNumberOfElements();
            PhasedArrayModel::ComplexVector thisBf(thisAntennaNumElements);
            PhasedArrayModel::ComplexVector otherBf(otherAntennaNumElements);

            bfVectors = std::make_pair(thisBf, otherBf);
        }
        else
        {
            bfVectors = ComputeBeamformingVectors(channelMatrix);

            if (channelMatrix->IsReverse(m_antenna->GetId(), otherAntenna->GetId()))
            {
                // reverse BF vectors
                bfVectors = std::make_pair(std::get<1>(bfVectors), std::get<0>(bfVectors));
            }
        }
    }

    // configure the antenna to use the new beamforming vector
    m_antenna->SetBeamformingVector(std::get<0>(bfVectors));
    NS_LOG_LOGIC("antenna " << m_antenna << " set BF vector"
                            << " numAntennaElem " << m_antenna->GetNumberOfElements()
                            << " this device ID=" << m_device->GetNode()->GetId()
                            << " otherDevice ID=" << otherDevice->GetNode()->GetId());
    otherAntenna->SetBeamformingVector(std::get<1>(bfVectors));
    NS_LOG_LOGIC("antenna " << otherAntenna << " set BF vector"
                            << " numAntennaElem " << otherAntenna->GetNumberOfElements()
                            << " this device ID=" << otherDevice->GetNode()->GetId()
                            << " otherDevice ID=" << m_device->GetNode()->GetId());

    if (toCache)
    {
        auto entry{m_cacheChannelMap.find(otherDevice)};
        if (entry != m_cacheChannelMap.end())
        {
            entry->second = channelMatrix;
            // this means there is also an entry for the bf vector
            m_cacheBfVectors.find(otherDevice)->second = bfVectors;
        }
        else
        {
            m_cacheChannelMap.insert(std::make_pair(otherDevice, channelMatrix));
            m_cacheBfVectors.insert(std::make_pair(otherDevice, bfVectors));
        }
    }
}

std::pair<PhasedArrayModel::ComplexVector, PhasedArrayModel::ComplexVector>
MmWaveSvdBeamforming::ComputeBeamformingVectors(
    Ptr<const MatrixBasedChannelModel::ChannelMatrix> params) const
{
    // generate transmitter side spatial correlation matrix
    uint16_t aSize = params->m_channel.GetNumRows();
    uint16_t bSize = params->m_channel.GetNumCols();
    uint16_t clusterSize = params->m_channel.GetNumPages();

    // compute narrowband channel by summing over the cluster index
    MatrixBasedChannelModel::Complex2DVector narrowbandChannel(aSize, bSize);

    for (uint16_t aIndex = 0; aIndex < aSize; aIndex++)
    {
        for (uint16_t bIndex = 0; bIndex < bSize; bIndex++)
        {
            std::complex<double> cSum(0, 0);
            for (uint16_t cIndex = 0; cIndex < clusterSize; cIndex++)
            {
                cSum += params->m_channel(aIndex, bIndex, cIndex);
            }
            narrowbandChannel(aIndex, bIndex) = cSum;
        }
    }

    // compute the transmitter side spatial correlation matrix bQ = H*H, where H is the sum of H_n
    // over n clusters.
    MatrixBasedChannelModel::Complex2DVector bQ(bSize, bSize);

    for (uint16_t b1Index = 0; b1Index < bSize; b1Index++)
    {
        for (uint16_t b2Index = 0; b2Index < bSize; b2Index++)
        {
            std::complex<double> aSum(0, 0);
            for (uint16_t aIndex = 0; aIndex < aSize; aIndex++)
            {
                aSum += std::conj(narrowbandChannel(aIndex, b1Index) *
                                  narrowbandChannel(aIndex, b2Index));
            }
            bQ(b1Index, b2Index) += aSum;
        }
    }

    // calculate beamforming vector from spatial correlation matrix
    PhasedArrayModel::ComplexVector bW = GetFirstEigenvector(bQ);

    // compute the receiver side spatial correlation matrix aQ = HH*, where H is the sum of H_n over
    // n clusters.
    MatrixBasedChannelModel::Complex2DVector aQ(aSize, aSize);

    for (uint16_t a1Index = 0; a1Index < aSize; a1Index++)
    {
        for (uint16_t a2Index = 0; a2Index < aSize; a2Index++)
        {
            std::complex<double> bSum(0, 0);
            for (uint16_t bIndex = 0; bIndex < bSize; bIndex++)
            {
                bSum += narrowbandChannel(a1Index, bIndex) *
                        std::conj(narrowbandChannel(a2Index, bIndex));
            }
            aQ(a1Index, a2Index) += bSum;
        }
    }

    // calculate beamforming vector from spatial correlation matrix.
    PhasedArrayModel::ComplexVector aW = GetFirstEigenvector(aQ);

    for (size_t i = 0; i < aW.GetSize(); ++i)
    {
        aW[i] = std::conj(aW[i]);
    }

    return std::make_pair(bW, aW);
}

PhasedArrayModel::ComplexVector
MmWaveSvdBeamforming::GetFirstEigenvector(MatrixBasedChannelModel::Complex2DVector A) const
{
    uint16_t arraySize = A.GetNumCols();
    PhasedArrayModel::ComplexVector antennaWeights(arraySize);

    for (uint16_t eIndex = 0; eIndex < arraySize; eIndex++)
    {
        antennaWeights[eIndex] = A(0, eIndex);
    }

    uint32_t iter = 0;
    double diff = 1;
    while (iter < m_maxIterations && diff > m_tolerance)
    {
        PhasedArrayModel::ComplexVector antennaWeightsNew(arraySize);
        unsigned int elemIdx = 0;

        for (uint16_t row = 0; row < arraySize; row++)
        {
            std::complex<double> sum(0, 0);
            for (uint16_t col = 0; col < arraySize; col++)
            {
                sum += A(row, col) * antennaWeights[col];
            }

            antennaWeightsNew[elemIdx++] = sum;
        }
        // normalize antennaWeights;
        double weighbSum = 0;
        for (uint16_t i = 0; i < arraySize; i++)
        {
            weighbSum += norm(antennaWeightsNew[i]);
        }
        for (uint16_t i = 0; i < arraySize; i++)
        {
            antennaWeightsNew[i] = antennaWeightsNew[i] / sqrt(weighbSum);
        }
        diff = 0;
        for (uint16_t i = 0; i < arraySize; i++)
        {
            diff += std::norm(antennaWeightsNew[i] - antennaWeights[i]);
        }
        iter++;
        antennaWeights = antennaWeightsNew;
    }
    NS_LOG_DEBUG("antennaWeigths stopped after " << iter << " iterations with diff=" << diff
                                                 << std::endl);

    return antennaWeights;
}

/*----------------------------------------------------------------------------*/

NS_OBJECT_ENSURE_REGISTERED(MmWaveCodebookBeamforming);

TypeId
MmWaveCodebookBeamforming::GetTypeId()
{
    static TypeId tid =
        TypeId("ns3::MmWaveCodebookBeamforming")
            .SetParent<MmWaveBeamformingModel>()
            .AddConstructor<MmWaveCodebookBeamforming>()
            .AddAttribute("SpectrumPropagationLossModel",
                          "Pointer to SpectrumPropagationLossModel",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveCodebookBeamforming::m_splm),
                          MakePointerChecker<SpectrumPropagationLossModel>())
            .AddAttribute("PhasedArraySpectrumPropagationLossModel",
                          "Pointer to SpectrumPropagationLossModel",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveCodebookBeamforming::m_pSplm),
                          MakePointerChecker<PhasedArraySpectrumPropagationLossModel>())
            .AddAttribute("MmWavePhyMacCommon",
                          "Pointer to MmWavePhyMacCommon",
                          PointerValue(),
                          MakePointerAccessor(&MmWaveCodebookBeamforming::SetMmWavePhyMacCommon),
                          MakePointerChecker<MmWavePhyMacCommon>())
            .AddAttribute("UpdatePeriod",
                          "Specify the channel coherence time",
                          TimeValue(MilliSeconds(0.0)),
                          MakeTimeAccessor(&MmWaveCodebookBeamforming::m_updatePeriod),
                          MakeTimeChecker());
    return tid;
}

MmWaveCodebookBeamforming::MmWaveCodebookBeamforming()
{
    NS_LOG_FUNCTION(this);
}

MmWaveCodebookBeamforming::~MmWaveCodebookBeamforming()
{
}

void
MmWaveCodebookBeamforming::SetBeamformingCodebookFactory(ObjectFactory factory)
{
    NS_LOG_FUNCTION(this << factory);
    NS_ABORT_MSG_IF(!factory.GetTypeId().IsChildOf(BeamformingCodebook::GetTypeId()),
                    "The given factory does not create BeamformingCodebook objects");
    m_beamformingCodebookFactory = factory;
}

void
MmWaveCodebookBeamforming::SetMmWavePhyMacCommon(Ptr<MmWavePhyMacCommon> mwpmc)
{
    NS_LOG_FUNCTION(this << mwpmc);

    std::vector<int> activeRbs;
    for (uint32_t i = 0; i < mwpmc->GetNumRb(); i++)
    {
        activeRbs.push_back(i);
    }
    m_txPsd = MmWaveSpectrumValueHelper::CreateTxPowerSpectralDensity(
        mwpmc,
        0.0,
        activeRbs); // TODO should i copy this?
}

void
MmWaveCodebookBeamforming::DoInitialize(void)
{
    NS_LOG_FUNCTION(this);

    NS_ASSERT_MSG(m_beamformingCodebookFactory.IsTypeIdSet(),
                  "The BeamformingCodebook factory is not initialized");

    Ptr<BeamformingCodebook> cb = m_beamformingCodebookFactory.Create<BeamformingCodebook>();
    cb->SetAttribute("Array", PointerValue(m_antenna));
    cb->Initialize();

    NS_ASSERT_MSG(cb->GetCodebookSize() > 0, "Empty codebook");
    NS_ASSERT_MSG(cb->GetCodeword(0).GetSize() == m_antenna->GetNumberOfElements(),
                  "Inappropriate codebook for the given PhasedArrayModel");
    m_antenna->AggregateObject(cb);

    // TODO what if SetAntenna is used?
}

void
MmWaveCodebookBeamforming::SetBeamformingVectorForDevice(Ptr<NetDevice> otherDevice,
                                                         Ptr<PhasedArrayModel> otherAntenna)
{
    NS_LOG_FUNCTION(this << otherDevice << otherAntenna);

    uint32_t thisCbIdx;  // index of the codeword selected for this antenna
    uint32_t otherCbIdx; // index of the codeword selected for the other antenna

    // check if the best beam pair has already been computed
    bool notFound = true;
    bool update = false;
    auto it = m_codebookIdsCache.find(otherAntenna);
    if (it != m_codebookIdsCache.end())
    {
        notFound = false;
        thisCbIdx = it->second.thisCbIdx;
        otherCbIdx = it->second.otherCbIdx;

        // check if it has to be updated
        if (!m_updatePeriod.IsZero() && Simulator::Now() - it->second.lastUpdate > m_updatePeriod)
        {
            update = true;
        }

        NS_LOG_DEBUG(this << " found an entry in the map for antenna " << otherAntenna);
        NS_LOG_DEBUG("Codebook index for this antenna " << it->second.thisCbIdx);
        NS_LOG_DEBUG("Codebook index for other antenna " << it->second.otherCbIdx);
        NS_LOG_DEBUG("Last update " << it->second.lastUpdate.GetSeconds() << " s ");
        NS_LOG_DEBUG("Now " << Simulator::Now().GetSeconds() << ", update? " << update);
    }

    if (notFound || update)
    {
        MmWaveCodebookBeamforming::Matrix2D powerMatrix =
            ComputeBeamformingCodebookMatrix(otherDevice, otherAntenna);

        // find best beam couple
        std::vector<double> maxPowers;
        maxPowers.reserve(powerMatrix.size());
        std::vector<uint32_t> argMaxPowers;
        argMaxPowers.reserve(powerMatrix.size());

        for (uint32_t i = 0; i < powerMatrix.size(); i++)
        {
            auto argMaxIt = std::max_element(powerMatrix[i].begin(), powerMatrix[i].end());
            argMaxPowers.push_back(std::distance(powerMatrix[i].begin(), argMaxIt));
            maxPowers.push_back(*argMaxIt);
        }

        auto argMaxIt = std::max_element(maxPowers.begin(), maxPowers.end());
        thisCbIdx = std::distance(maxPowers.begin(), argMaxIt);
        otherCbIdx = argMaxPowers[thisCbIdx];

        NS_LOG_DEBUG("Best beam pair: thisCbIdx=" << thisCbIdx << ", otherCbIdx=" << otherCbIdx
                                                  << " with power "
                                                  << 10 * std::log10(*argMaxIt) + 30 << " dBm");

        // insert the new entry in the map
        Entry newEntry;
        newEntry.thisCbIdx = thisCbIdx;
        newEntry.otherCbIdx = otherCbIdx;
        newEntry.lastUpdate = Simulator::Now();
        m_codebookIdsCache[otherAntenna] = newEntry;
    }

    // set best BF codewords for both devices
    Ptr<BeamformingCodebook> thisCodebook = m_antenna->GetObject<BeamformingCodebook>();
    Ptr<BeamformingCodebook> otherCodebook = otherAntenna->GetObject<BeamformingCodebook>();

    PhasedArrayModel::ComplexVector thisAntennaWeights = thisCodebook->GetCodeword(thisCbIdx);
    PhasedArrayModel::ComplexVector otherAntennaWeights = otherCodebook->GetCodeword(otherCbIdx);

    m_antenna->SetBeamformingVector(thisAntennaWeights);
    otherAntenna->SetBeamformingVector(otherAntennaWeights);
}

MmWaveCodebookBeamforming::Matrix2D
MmWaveCodebookBeamforming::ComputeBeamformingCodebookMatrix(
    Ptr<NetDevice> otherDevice,
    Ptr<PhasedArrayModel> otherAntenna) const
{
    NS_LOG_FUNCTION(this << otherDevice << otherAntenna);

    // check whether we are performing the initial configuration
    bool isInitialConf = m_codebookIdsCache.find(otherAntenna) == m_codebookIdsCache.end();

    Ptr<BeamformingCodebook> thisCodebook = m_antenna->GetObject<BeamformingCodebook>();
    Ptr<BeamformingCodebook> otherCodebook = otherAntenna->GetObject<BeamformingCodebook>();

    Ptr<MobilityModel> thisMob = m_device->GetNode()->GetObject<MobilityModel>();
    Ptr<MobilityModel> otherMob = otherDevice->GetNode()->GetObject<MobilityModel>();

    // init matrix
    MmWaveCodebookBeamforming::Matrix2D matrix{};
    matrix.resize(thisCodebook->GetCodebookSize());
    for (uint64_t i = 0; i < thisCodebook->GetCodebookSize(); i++)
    {
        matrix[i].reserve(otherCodebook->GetCodebookSize());
    }

    // save pre-existing bf vectors
    PhasedArrayModel::ComplexVector thisOldBfVector;
    PhasedArrayModel::ComplexVector otherOldBfVector;
    if (!isInitialConf)
    {
        thisOldBfVector = m_antenna->GetBeamformingVector();
        otherOldBfVector = otherAntenna->GetBeamformingVector();
    }

    // fill matrix
    for (uint32_t thisIdx = 0; thisIdx < thisCodebook->GetCodebookSize(); thisIdx++)
    {
        m_antenna->SetBeamformingVector(thisCodebook->GetCodeword(thisIdx));

        for (uint32_t otherIdx = 0; otherIdx < otherCodebook->GetCodebookSize(); otherIdx++)
        {
            otherAntenna->SetBeamformingVector(otherCodebook->GetCodeword(otherIdx));

            Ptr<SpectrumValue> rxPsd;
            Ptr<SpectrumSignalParameters> rxParams = Create<SpectrumSignalParameters>();
            rxParams->psd = Copy<SpectrumValue>(m_txPsd); // PSD needs to be initialized

            if (m_splm)
            {
                rxPsd = m_splm->CalcRxPowerSpectralDensity(rxParams, thisMob, otherMob);
            }
            else if (m_pSplm)
            {
                rxPsd = m_pSplm->CalcRxPowerSpectralDensity(rxParams,
                                                            thisMob,
                                                            otherMob,
                                                            m_antenna,
                                                            otherAntenna);
            }

            double avgRxPsd = Sum(*rxPsd) / (rxPsd->GetSpectrumModel()->GetNumBands());
            matrix[thisIdx].push_back(avgRxPsd);
        }
    }
    NS_LOG_DEBUG("Matrix of size " << matrix.size() << "x" << matrix[0].size());

    // reset to pre-existing bf vectors, if configured
    if (!isInitialConf)
    {
        m_antenna->SetBeamformingVector(thisOldBfVector);
        otherAntenna->SetBeamformingVector(otherOldBfVector);
    }

    return matrix;
}

} // namespace mmwave
} // namespace ns3
