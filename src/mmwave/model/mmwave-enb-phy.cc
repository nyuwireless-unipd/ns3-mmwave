/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *                 Dual Connectivity and Handover functionalities\
 *              Marco Giordani <m.giordani91@gmail.com>
 *                  LOS-NLOS transitions, SINR measurement error and filtering
 */

#include "mmwave-enb-phy.h"

#include "mc-ue-net-device.h"
#include "mmwave-net-device.h"
#include "mmwave-radio-bearer-tag.h"
#include "mmwave-spectrum-value-helper.h"
#include "mmwave-ue-net-device.h"
#include "mmwave-ue-phy.h"

#include <ns3/antenna-model.h>
#include <ns3/attribute-accessor-helper.h>
#include <ns3/average.h>
#include <ns3/double.h>
#include <ns3/log.h>
#include <ns3/node-list.h>
#include <ns3/node.h>
#include <ns3/object-factory.h>
#include <ns3/phased-array-model.h>
#include <ns3/pointer.h>
#include <ns3/random-variable-stream.h>
#include <ns3/simulator.h>

#include <algorithm>
#include <array>
#include <cfloat>
#include <cmath>
#include <complex.h>
#include <fstream>
#include <iostream>
#include <math.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveEnbPhy");

NS_OBJECT_ENSURE_REGISTERED(MmWaveEnbPhy);

MmWaveEnbPhy::MmWaveEnbPhy()
{
    NS_LOG_FUNCTION(this);
    NS_FATAL_ERROR("This constructor should not be called");
}

MmWaveEnbPhy::MmWaveEnbPhy(Ptr<MmWaveSpectrumPhy> dlPhy, Ptr<MmWaveSpectrumPhy> ulPhy)
    : MmWavePhy(dlPhy, ulPhy),
      m_prevSlot(0),
      m_prevTtiDir(TtiAllocInfo::NA),
      m_currSymStart(0)
{
    m_enbCphySapProvider = new MemberLteEnbCphySapProvider<MmWaveEnbPhy>(this);
    m_roundFromLastUeSinrUpdate = 0;
    Simulator::ScheduleNow(&MmWaveEnbPhy::StartSlot, this);
}

MmWaveEnbPhy::~MmWaveEnbPhy()
{
    m_sinrMap.clear();
}

TypeId
MmWaveEnbPhy::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveEnbPhy")
            .SetParent<MmWavePhy>()
            .AddConstructor<MmWaveEnbPhy>()
            .AddAttribute("TxPower",
                          "Transmission power in dBm",
                          DoubleValue(30.0),
                          MakeDoubleAccessor(&MmWaveEnbPhy::SetTxPower, &MmWaveEnbPhy::GetTxPower),
                          MakeDoubleChecker<double>())
            .AddAttribute(
                "NoiseAndFilter",
                "If true, use noisy SINR samples, filtered. If false, just use the SINR measure",
                BooleanValue(false),
                MakeBooleanAccessor(&MmWaveEnbPhy::m_noiseAndFilter),
                MakeBooleanChecker())
            .AddAttribute("UpdateSinrEstimatePeriod",
                          "Period (in microseconds) of update of SINR estimate of all the UE",
                          IntegerValue(1600), // TODO considering refactoring in MmWavePhyMacCommon
                          MakeIntegerAccessor(&MmWaveEnbPhy::m_updateSinrPeriod),
                          MakeIntegerChecker<int>())
            .AddAttribute("UpdateUeSinrEstimatePeriod",
                          "Period (in ms) of reporting of SINR estimate of all the UE",
                          DoubleValue(25.6),
                          MakeDoubleAccessor(&MmWaveEnbPhy::m_ueUpdateSinrPeriod),
                          MakeDoubleChecker<double>())
            .AddAttribute("Transient",
                          "Transient period (in microseconds) in which just collect SINR values "
                          "without filtering the sample",
                          IntegerValue(320000),
                          MakeIntegerAccessor(&MmWaveEnbPhy::m_transient),
                          MakeIntegerChecker<int>())
            .AddAttribute(
                "NoiseFigure",
                "Loss (dB) in the Signal-to-Noise-Ratio due to non-idealities in the receiver."
                " According to Wikipedia (http://en.wikipedia.org/wiki/Noise_figure), this is "
                "\"the difference in decibels (dB) between"
                " the noise output of the actual receiver to the noise output of an "
                " ideal receiver with the same overall gain and bandwidth when the receivers "
                " are connected to sources at the standard noise temperature T0.\" "
                "In this model, we consider T0 = 290K.",
                DoubleValue(5.0),
                MakeDoubleAccessor(&MmWavePhy::SetNoiseFigure, &MmWavePhy::GetNoiseFigure),
                MakeDoubleChecker<double>())
            .AddAttribute("DlSpectrumPhy",
                          "The downlink MmWaveSpectrumPhy associated to this MmWavePhy",
                          TypeId::ATTR_GET,
                          PointerValue(),
                          MakePointerAccessor(&MmWaveEnbPhy::GetDlSpectrumPhy),
                          MakePointerChecker<MmWaveSpectrumPhy>())
            .AddAttribute("UlSpectrumPhy",
                          "The uplink MmWaveSpectrumPhy associated to this MmWavePhy",
                          TypeId::ATTR_GET,
                          PointerValue(),
                          MakePointerAccessor(&MmWaveEnbPhy::GetUlSpectrumPhy),
                          MakePointerChecker<MmWaveSpectrumPhy>())
            .AddTraceSource("UlSinrTrace",
                            "UL SINR statistics.",
                            MakeTraceSourceAccessor(&MmWaveEnbPhy::m_ulSinrTrace),
                            "ns3::UlSinr::TracedCallback")
            .AddTraceSource("ReportDlPhyTransmission",
                            "Report the allocation info for the current DL transmission",
                            MakeTraceSourceAccessor(&MmWaveEnbPhy::m_dlPhyTrace),
                            "ns3::DlPhyTransmission::TracedCallback")

        ;
    return tid;
}

void
MmWaveEnbPhy::DoInitialize(void)
{
    NS_LOG_FUNCTION(this);
    Ptr<SpectrumValue> noisePsd =
        MmWaveSpectrumValueHelper::CreateNoisePowerSpectralDensity(m_phyMacConfig, m_noiseFigure);
    m_downlinkSpectrumPhy->SetNoisePowerSpectralDensity(noisePsd);

    for (unsigned i = 0; i < m_phyMacConfig->GetL1L2Latency(); i++)
    { // push elements onto queue for initial scheduling delay
        m_controlMessageQueue.push_back(std::list<Ptr<MmWaveControlMessage>>());
    }
    // m_sfAllocInfoUpdated = true;

    for (uint32_t i = 0; i < m_phyMacConfig->GetNumRb(); i++)
    {
        m_channelChunks.push_back(i);
    }
    SetSubChannels(m_channelChunks);

    m_slotPeriod = m_phyMacConfig->GetSubframePeriod() / m_phyMacConfig->GetSlotsPerSubframe();

    for (unsigned i = 0; i < m_phyMacConfig->GetSlotsPerSubframe(); i++)
    {
        m_slotAllocInfo.push_back(SlotAllocInfo(SfnSf(m_frameNum, m_sfNum, i)));
        MmWavePhy::SetSlotCtrlStructure(i);
    }

    NS_LOG_DEBUG("In mmWaveEnbPhy, the RT periodicity is: " << m_updateSinrPeriod
                                                            << " microseconds");
    NS_LOG_DEBUG("In mmWaveEnbPhy, the transient duration is: " << m_transient << " microseconds");
    if (m_noiseAndFilter)
    {
        NS_ASSERT_MSG(
            (double)m_transient / m_updateSinrPeriod >= 16,
            "Window too small to compute the variance according to the ApplyFilter method");
    }
    Simulator::Schedule(MicroSeconds(0), &MmWaveEnbPhy::UpdateUeSinrEstimate, this);
    MmWavePhy::DoInitialize();
}

void
MmWaveEnbPhy::DoDispose(void)
{
}

// TODO remove these methods
// Function for average
double
MmWaveEnbPhy::MakeAvg(std::vector<double> v)
{
    double return_value = 0.0;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        return_value += v.at(i);
    }

    return (return_value / v.size());
}

//****************End of average funtion****************

// Function for variance
double
MmWaveEnbPhy::MakeVar(std::vector<double> v, double mean)
{
    double sum = 0.0;
    double temp = 0.0;
    double var = 0.0;
    int n = v.size();

    for (int j = 0; j < n; j++)
    {
        temp = std::pow((v.at(j) - mean), 2);
        sum += temp;
    }

    return var = sum / (v.size());
}

//****************End of variance funtion****************

double
MmWaveEnbPhy::AddGaussianNoise(double LastSinrValue)
{
    double N0 = 3.98107170e-12;
    std::complex<double> gaussianNoise;
    double signalEnergy;
    double noisySample;

    Ptr<NormalRandomVariable> randomVariable = CreateObject<NormalRandomVariable>();
    double gaussianSampleRe = randomVariable->GetValue();
    double gaussianSampleIm = randomVariable->GetValue();
    gaussianNoise = std::complex<double>(sqrt(0.5) * sqrt(N0) * gaussianSampleRe,
                                         sqrt(0.5) * sqrt(N0) * gaussianSampleIm);

    signalEnergy = LastSinrValue * N0;

    noisySample = (std::pow(std::abs(sqrt(signalEnergy) + gaussianNoise), 2) - N0) / N0;

    return noisySample;
}

std::pair<uint64_t, uint64_t>
MmWaveEnbPhy::ApplyFilter(std::vector<double> noisySinr)
{
    std::vector<double> noisySinrdB;
    for (uint64_t i = 0; i < noisySinr.size(); ++i)
    {
        noisySinrdB.push_back(10 * std::log10(noisySinr.at(i)));
    }

    std::vector<double> vectorVar;
    NS_LOG_DEBUG("noisySinrdBSize() " << noisySinrdB.size());
    for (uint64_t i = 0; i < noisySinrdB.size() - 1; ++i)
    {
        std::vector<double> partialSamples;
        partialSamples.push_back(noisySinrdB.at(i));
        partialSamples.push_back(noisySinrdB.at(i + 1));
        double meanValue = MakeAvg(partialSamples);
        double varValue = MakeVar(partialSamples, meanValue);
        vectorVar.push_back(varValue);
        partialSamples.clear();
    }

    uint64_t startFilter = 1e6;
    uint64_t endFilter = 1e6;

    bool flagStartFilter = true;
    bool flagEndFilter = true;

    uint64_t noisySinrIndex = 0;

    for (uint64_t varIndex = vectorVar.size() - 1; varIndex > 0;
         varIndex--) // start filter when variance of the noisy trace is high
    {
        NS_LOG_DEBUG("varIndex " << varIndex);
        noisySinrIndex = varIndex + 1;
        NS_LOG_DEBUG("vectorVar[i] " << vectorVar.at(varIndex));
        NS_LOG_DEBUG("vectorVar[i] == NaN " << (std::isnan(vectorVar.at(varIndex))));
        bool highVariance = (vectorVar.at(varIndex) > 5 || std::isnan(vectorVar.at(varIndex)));
        bool lowSinr = noisySinr.at(noisySinrIndex) < 10;

        if (highVariance ||
            (lowSinr && !highVariance)) // filter is applied only for low-SINR regimes [dB]
        {
            endFilter = noisySinrIndex;
            flagEndFilter = false; // a "start" sample has been identified
            break;
        }
    }

    if (flagEndFilter) // in this case, we can avoid the filtering
    {
        endFilter = 0;
    }

    /* in this case, consider at least a window of 15 samples, after which we can consider
     * as we are leaving the blockage phase and we start coming back to LOS PL regimes
     */
    uint64_t varIndex = 0;
    uint64_t numberOfVarWindow = 16;
    NS_LOG_DEBUG("VectorVarSize() " << vectorVar.size());
    for (uint64_t noisySinrIndex = endFilter; noisySinrIndex > numberOfVarWindow;
         --noisySinrIndex) // must be at least after the beginnning of the blocakge
    {
        NS_LOG_DEBUG("noisySinrIndex " << noisySinrIndex);
        varIndex = noisySinrIndex - 1;

        std::vector<double>::const_iterator first = vectorVar.begin() + varIndex;
        std::vector<double>::const_iterator last =
            vectorVar.begin() + varIndex -
            (numberOfVarWindow - 1); // vectorVar has one sample less than noisySinrdB
        std::vector<double> prov(last, first);

        std::vector<double>::const_iterator firstNoisy = noisySinrdB.begin() + noisySinrIndex;
        std::vector<double>::const_iterator lastNoisy =
            noisySinrdB.begin() + noisySinrIndex - numberOfVarWindow;
        std::vector<double> provNoisy(lastNoisy, firstNoisy);

        NS_LOG_INFO("provNoisy.size " << provNoisy.size());
        for (std::vector<double>::const_iterator h = provNoisy.begin(); h != provNoisy.end(); h++)
        {
            NS_LOG_INFO("h " << *h);
            NS_LOG_INFO("i " << noisySinrIndex);
            NS_LOG_INFO("hh " << *(noisySinrdB.begin() + noisySinrIndex - numberOfVarWindow));
        }

        /* the filtering ends when the variance of the noisy trace is almost the same, so when
         * the SINR is on sufficiently high values
         */

        if (Simulator::Now() > Seconds(2.1) && Simulator::Now() < Seconds(2.3))
        {
            NS_LOG_DEBUG(
                "(std::all_of(prov.begin(),prov.end(), [](double j){return j < 1;})) "
                << (std::all_of(prov.begin(), prov.end(), [](double j) { return j < 1; })));
            NS_LOG_DEBUG("(std::all_of(prov.begin(),prov.end(), [](double j){nan;})) "
                         << (std::all_of(prov.begin(), prov.end(), [](double k) {
                                return !std::isnan(k);
                            })));
            NS_LOG_DEBUG(
                "(std::all_of(provNoisy.begin(),provNoisy.end(), [](double p){return p > 10;})) "
                << (std::all_of(provNoisy.begin(), provNoisy.end(), [](double p) {
                       return p > 10;
                   })));
        }

        if (((std::all_of(prov.begin(), prov.end(), [](double j) { return j < 1; })) &&
             (std::all_of(prov.begin(), prov.end(), [](double k) { return !std::isnan(k); }))) ||
            (std::all_of(provNoisy.begin(), provNoisy.end(), [](double p) { return p > 10; })))
        {
            startFilter = noisySinrIndex;
            flagStartFilter = false; // a "end" sample has been identified
            break;
        }

        // bool lowVariance = (vectorVar.at(varIndex) < 1 && !std::isnan(vectorVar.at(varIndex)));
        // bool highSinr = noisySinr.at(noisySinrIndex) > 10;

        // if (highSinr && lowVariance)  // filter is applied only for low-SINR regimes [dB]
        // {
        //        startFilter = noisySinrIndex;
        //        flagStartFilter = false; // a "start" sample has been identified
        //        break;
        // }
    }

    if (flagStartFilter) // in this case, filter till the end of the trace
    {
        startFilter = 0;
    }

    std::pair<uint64_t, uint64_t> pairFiltering = std::make_pair(startFilter, endFilter);

    return pairFiltering;
}

std::vector<double>
MmWaveEnbPhy::MakeFilter(std::vector<double> noisySinr,
                         std::vector<double> realSinr,
                         std::pair<uint64_t, uint64_t> pairFiltering)
{
    for (uint64_t i = 0; i < noisySinr.size(); ++i)
    {
        NS_LOG_DEBUG("() " << noisySinr.at(i));
    }
    // const uint64_t lengthFiltering  = (std::get<1>(pairFiltering) - std::get<0>(pairFiltering));
    /* find best alpha parameter for the Kalman estimation */
    int rep = 0;
    std::array<double, 100> meanError;
    for (double alpha = 0; alpha < 1; alpha = alpha + 0.01)
    {
        std::vector<double> x;
        x.push_back(0); // initialization of array
        int counter = 0;

        for (uint64_t i = std::get<0>(pairFiltering); i < std::get<1>(pairFiltering); i++)
        {
            x.push_back((1 - alpha) * x.at(counter) + alpha * (noisySinr.at(i)));
            counter++;
        }

        std::vector<double> errorEstimation;
        counter = 0;
        for (uint64_t i = std::get<0>(pairFiltering); i < std::get<1>(pairFiltering); i++)
        {
            errorEstimation.push_back(std::abs(x.at(counter + 1) - realSinr.at(i)));
            counter++;
        }

        meanError.at(rep) = MakeAvg(errorEstimation);
        if (Simulator::Now() > Seconds(2.1) && Simulator::Now() < Seconds(2.3))
        {
            NS_LOG_DEBUG("meanError " << meanError.at(rep) << " rep " << rep);
        }
        rep++;
    }

    int posMinAlpha =
        std::distance(meanError.begin(), std::min_element(meanError.begin(), meanError.end()));
    double minAlpha = (posMinAlpha + 1) * 0.01;
    if (minAlpha > 0.5)
    {
        minAlpha = 0.2;
    }
    NS_LOG_DEBUG("! " << minAlpha);

    std::vector<double> blockageTrace;
    blockageTrace.push_back(0);
    int counter = 0;
    for (uint64_t i = std::get<0>(pairFiltering); i < std::get<1>(pairFiltering); i++)
    {
        NS_LOG_DEBUG(noisySinr.at(i));
        blockageTrace.push_back((1 - minAlpha) * blockageTrace.at(counter) +
                                minAlpha * (noisySinr.at(i)));
        NS_LOG_DEBUG("fff " << blockageTrace.at(counter));
        counter++;
    }

    std::vector<double> retFinalTrace;
    /* first piece */
    std::vector<double>::const_iterator firstPieceStart = noisySinr.begin();
    std::vector<double>::const_iterator firstPieceEnd =
        noisySinr.begin() + std::get<0>(pairFiltering) + 1;
    std::vector<double> firstPiece;
    firstPiece.insert(firstPiece.begin(), firstPieceStart, firstPieceEnd);
    for (std::vector<double>::const_iterator i = firstPiece.begin(); i != firstPiece.end(); i++)
    {
        NS_LOG_DEBUG("/ " << *i);
    }

    /*last piece*/
    std::vector<double>::const_iterator lastPieceStart =
        noisySinr.begin() + std::get<1>(pairFiltering) + 1;
    std::vector<double>::const_iterator lastPieceEnd = noisySinr.end();
    std::vector<double> lastPiece;

    firstPiece.insert(firstPiece.end(), blockageTrace.begin() + 1, blockageTrace.end() - 1);
    for (std::vector<double>::const_iterator i = firstPiece.begin(); i != firstPiece.end(); i++)
    {
        NS_LOG_DEBUG("// " << *i);
    }

    firstPiece.insert(firstPiece.end(), lastPieceStart, lastPieceEnd);
    for (std::vector<double>::const_iterator i = firstPiece.begin(); i != firstPiece.end(); i++)
    {
        NS_LOG_DEBUG("/// " << *i);
    }

    /* insert blockageTrace (from begin + 1, in order to AVOID THE TRANSIENT, to end) in the
     * noisySinr trace, after std::get<0>(pairFiltering) +1 samples, which are the samples in which
     * we estimate that a blockage occurs and the Kalmn filter is applied
     */
    // std::copy(blockageTrace.begin(),blockageTrace.end(),noisySinr.begin()+std::get<0>(pairFiltering)
    // );
    // std::copy(blockageTrace.begin()+1,blockageTrace.end(),noisySinr.begin()+std::get<0>(pairFiltering)+1
    // ); // AVOID TRANSIENT

    return firstPiece; // this noisySinr trace has already been updated with the filtered samples,
                       // where applied.
}

void
MmWaveEnbPhy::SetMmWaveEnbCphySapUser(LteEnbCphySapUser* s)
{
    NS_LOG_FUNCTION(this);
    m_enbCphySapUser = s;
}

LteEnbCphySapProvider*
MmWaveEnbPhy::GetMmWaveEnbCphySapProvider()
{
    NS_LOG_FUNCTION(this);
    return m_enbCphySapProvider;
}

void
MmWaveEnbPhy::SetTxPower(double pow)
{
    m_txPower = pow;
}

double
MmWaveEnbPhy::GetTxPower() const
{
    return m_txPower;
}

void
MmWaveEnbPhy::SetNoiseFigure(double nf)
{
    m_noiseFigure = nf;
}

double
MmWaveEnbPhy::GetNoiseFigure() const
{
    return m_noiseFigure;
}

Ptr<SpectrumValue>
MmWaveEnbPhy::CreateTxPowerSpectralDensity()
{
    Ptr<SpectrumValue> psd =
        MmWaveSpectrumValueHelper::CreateTxPowerSpectralDensity(m_phyMacConfig,
                                                                m_txPower,
                                                                m_listOfSubchannels);
    return psd;
}

void
MmWaveEnbPhy::SetSubChannels(std::vector<int> mask)
{
    m_listOfSubchannels = mask;
    Ptr<SpectrumValue> txPsd = CreateTxPowerSpectralDensity();
    NS_ASSERT(txPsd);
    m_downlinkSpectrumPhy->SetTxPowerSpectralDensity(txPsd);
}

Ptr<MmWaveSpectrumPhy>
MmWaveEnbPhy::GetDlSpectrumPhy() const
{
    return m_downlinkSpectrumPhy;
}

Ptr<MmWaveSpectrumPhy>
MmWaveEnbPhy::GetUlSpectrumPhy() const
{
    return m_uplinkSpectrumPhy;
}

void
MmWaveEnbPhy::UpdateUeSinrEstimate()
{
    NS_LOG_FUNCTION(this);

    m_sinrMap.clear();
    m_rxPsdMap.clear();

    Ptr<SpectrumValue> noisePsd =
        MmWaveSpectrumValueHelper::CreateNoisePowerSpectralDensity(m_phyMacConfig, m_noiseFigure);
    Ptr<SpectrumValue> totalReceivedPsd =
        Create<SpectrumValue>(SpectrumValue(noisePsd->GetSpectrumModel()));

    for (std::map<uint64_t, Ptr<NetDevice>>::iterator ue = m_ueAttachedImsiMap.begin();
         ue != m_ueAttachedImsiMap.end();
         ++ue)
    {
        // distinguish between MC and MmWaveNetDevice
        Ptr<mmwave::MmWaveUeNetDevice> ueNetDevice =
            DynamicCast<mmwave::MmWaveUeNetDevice>(ue->second);
        Ptr<McUeNetDevice> mcUeDev = DynamicCast<McUeNetDevice>(ue->second);
        Ptr<MmWaveUePhy> uePhy;
        // get tx power
        double ueTxPower = 0;
        if (ueNetDevice)
        {
            uePhy = ueNetDevice->GetPhy();
            ueTxPower = uePhy->GetTxPower();
        }
        else if (mcUeDev) // it may be a MC device
        {
            uePhy = mcUeDev->GetMmWavePhy();
            ueTxPower = uePhy->GetTxPower();
        }
        else
        {
            NS_FATAL_ERROR("Unrecognized device");
        }
        NS_LOG_LOGIC("UE Tx power = " << ueTxPower);
        double powerTxW = std::pow(10., (ueTxPower - 30) / 10);
        double txPowerDensity = 0;
        txPowerDensity = (powerTxW / (m_phyMacConfig->GetBandwidth()));
        NS_LOG_LOGIC("Linear UE Tx power = " << powerTxW);
        NS_LOG_LOGIC("System bandwidth = " << m_phyMacConfig->GetBandwidth());
        NS_LOG_LOGIC("txPowerDensity = " << txPowerDensity);
        // create tx psd
        Ptr<SpectrumValue> txPsd = // it is the eNB that dictates the conf, m_listOfSubchannels
                                   // contains all the subch
            MmWaveSpectrumValueHelper::CreateTxPowerSpectralDensity(m_phyMacConfig,
                                                                    ueTxPower,
                                                                    m_listOfSubchannels);
        NS_LOG_LOGIC("TxPsd " << *txPsd);

        // get this node and remote node mobility
        Ptr<MobilityModel> enbMob = m_netDevice->GetNode()->GetObject<MobilityModel>();
        NS_LOG_LOGIC("eNB mobility " << enbMob->GetPosition());
        Ptr<MobilityModel> ueMob = ue->second->GetNode()->GetObject<MobilityModel>();
        NS_LOG_DEBUG("UE mobility " << ueMob->GetPosition());

        // compute rx psd

        // adjuts beamforming of antenna model wrt user
        m_downlinkSpectrumPhy->ConfigureBeamforming(ue->second);
        uePhy->GetDlSpectrumPhy()->ConfigureBeamforming(m_netDevice);
        // Dl, since the Ul is not actually used (TDD device)
        double pathLossDb = 0;
        if (m_propagationLoss)
        {
            double propagationGainDb = m_propagationLoss->CalcRxPower(0, ueMob, enbMob);
            NS_LOG_LOGIC("propagationGainDb = " << propagationGainDb << " dB");
            pathLossDb -= propagationGainDb;
        }

        NS_LOG_DEBUG("Total pathLoss = " << pathLossDb << " dB");

        double pathGainLinear = std::pow(10.0, (-pathLossDb) / 10.0);
        Ptr<SpectrumValue> rxPsd = txPsd->Copy();
        *(rxPsd) *= pathGainLinear;

        // Not actually used for the gain, but needed for the call to CalcRxPowerSpectralDensity
        // anyway
        Ptr<PhasedArrayModel> rxPam =
            DynamicCast<PhasedArrayModel>(GetDlSpectrumPhy()->GetAntenna());
        Ptr<PhasedArrayModel> txPam =
            DynamicCast<PhasedArrayModel>(uePhy->GetDlSpectrumPhy()->GetAntenna());

        Ptr<SpectrumSignalParameters> rxParams = Create<SpectrumSignalParameters>();
        rxParams->psd = rxPsd->Copy();

        if (m_spectrumPropagationLossModel)
        {
            rxPsd =
                m_spectrumPropagationLossModel->CalcRxPowerSpectralDensity(rxParams, ueMob, enbMob);
        }
        else if (m_phasedArraySpectrumPropagationLossModel)
        {
            rxPsd = m_phasedArraySpectrumPropagationLossModel->CalcRxPowerSpectralDensity(rxParams,
                                                                                          ueMob,
                                                                                          enbMob,
                                                                                          txPam,
                                                                                          rxPam);
        }

        NS_LOG_LOGIC("RxPsd " << *rxPsd);

        m_rxPsdMap[ue->first] = rxPsd;
        *totalReceivedPsd += *rxPsd;

        // set back the bf vector to the main eNB
        if (ueNetDevice)
        { // target not set yet
            if ((ueNetDevice->GetTargetEnb() != m_netDevice) && (ueNetDevice->GetTargetEnb()))
            {
                uePhy->GetDlSpectrumPhy()->ConfigureBeamforming(ueNetDevice->GetTargetEnb());
            }
        }
        else if (mcUeDev) // it may be a MC device
        {                 // target not set yet
            if ((mcUeDev->GetMmWaveTargetEnb() != m_netDevice) && (mcUeDev->GetMmWaveTargetEnb()))
            {
                uePhy->GetDlSpectrumPhy()->ConfigureBeamforming(mcUeDev->GetMmWaveTargetEnb());
            }
        }
        else
        {
            NS_FATAL_ERROR("Unrecognized device");
        }
    }

    for (std::map<uint64_t, Ptr<SpectrumValue>>::iterator ue = m_rxPsdMap.begin();
         ue != m_rxPsdMap.end();
         ++ue)
    {
        SpectrumValue interference = *totalReceivedPsd - *(ue->second);
        NS_LOG_LOGIC("interference " << interference);
        SpectrumValue sinr = *(ue->second) / (*noisePsd); // + interference);
        // we consider the SNR only!
        NS_LOG_LOGIC("sinr " << sinr);
        double sinrAvg = Sum(sinr) / (sinr.GetSpectrumModel()->GetNumBands());
        NS_LOG_DEBUG("Time " << Simulator::Now().GetSeconds() << " CellId " << m_cellId << " UE "
                             << ue->first << "Average SINR " << 10 * std::log10(sinrAvg));

        if (m_noiseAndFilter)
        {
            pairDevices_t pairDevices =
                std::make_pair(ue->first, m_cellId);            // this is the current pair (UE-eNB)
            auto iteratorSinr = m_sinrVector.find(pairDevices); // pair [pairDevices,Sinrvalue]
            if (iteratorSinr != m_sinrVector.end()) // this map has already been initialized, so I
                                                    // can add a new element for the SINR collection
            {
                if (Now().GetMicroSeconds() <= m_transient)
                {
                    m_sinrVector.at(pairDevices)
                        .push_back(sinrAvg); // before transient, so just collect SINR values
                }
                else
                {
                    m_sinrVector.at(pairDevices).erase(m_sinrVector.at(pairDevices).begin());
                    m_sinrVector.at(pairDevices)
                        .push_back(sinrAvg); // before transient, so just collect SINR values
                }

                NS_LOG_DEBUG("At time " << Now().GetMicroSeconds() << " push back the REAL SINR "
                                        << 10 * std::log10(sinrAvg) << " for pair with CellId "
                                        << m_cellId << " and UE " << ue->first);
            }
            else // vector is not initialized, so it means that we are still in the initial
                 // transient phase, for that pair
            {
                m_sinrVector.insert(std::make_pair(pairDevices, std::vector<double>()));
                m_sinrVector.at(pairDevices).push_back(sinrAvg); // push back a new SINR value
                NS_LOG_DEBUG("At time " << Now().GetMicroSeconds()
                                        << " first initializazion and push back the SINR "
                                        << 10 * std::log10(sinrAvg) << " for pair with CellId "
                                        << m_cellId << " and UE " << ue->first);
            }

            auto iteratorFinalTrace =
                m_finalSinrVector.find(pairDevices); // pair [pairDevices,Sinrvalue]
            if (iteratorFinalTrace == m_finalSinrVector.end())
            {
                m_samplesFilter.insert(
                    std::make_pair(pairDevices, std::pair<uint64_t, uint64_t>()));
                m_finalSinrVector.insert(std::make_pair(pairDevices, std::vector<double>()));
            }

            auto iteratorSinrToFilter =
                m_sinrVectorToFilter.find(pairDevices); // pair [pairDevices,Sinrvalue]
            if (iteratorSinrToFilter == m_sinrVectorToFilter.end())
            {
                m_sinrVectorToFilter.insert(std::make_pair(pairDevices, std::vector<double>()));
                m_sinrVectorNoisy.insert(std::make_pair(pairDevices, std::vector<double>()));
            }

            /* generate Gaussian noise for the last SINR value (that is the current one) */
            double sinrNoisy = AddGaussianNoise(m_sinrVector.at(pairDevices).back());

            /* UPDATE TRACE TO BE FILTERED */
            if (Now().GetMicroSeconds() <= m_transient)
            {
                m_sinrVectorNoisy.at(pairDevices).push_back(sinrNoisy);

                // if (sinrNoisy < 0)
                // {
                //        NS_LOG_DEBUG("Old SINR value was " << 10*std::log10(sinrNoisy) << " while
                //        now is " << 10*std::log10(0.1)); sinrNoisy = 0.1;
                // }
                m_sinrVectorToFilter.at(pairDevices).push_back(sinrNoisy);
            }
            else
            {
                m_sinrVectorNoisy.at(pairDevices).erase(m_sinrVectorNoisy.at(pairDevices).begin());
                m_sinrVectorNoisy.at(pairDevices).push_back(sinrNoisy);

                // if (sinrNoisy < 0)
                // {
                //        NS_LOG_DEBUG("Old SINR value was " << 10*std::log10(sinrNoisy) << " while
                //        now is " << 10*std::log10(0.1)); sinrNoisy = 0.1;
                // }

                double toPlot = *m_sinrVectorToFilter.at(pairDevices).begin();
                double toPlotbis = sinrNoisy;
                NS_LOG_DEBUG("(Remove SINR)  " << toPlot);
                NS_LOG_DEBUG("(Add SINR)  " << toPlotbis);

                m_sinrVectorToFilter.at(pairDevices)
                    .erase(m_sinrVectorToFilter.at(pairDevices).begin());
                m_sinrVectorToFilter.at(pairDevices).push_back(sinrNoisy);
            }

            if (Now().GetMicroSeconds() > m_transient) // apply filter only when I have a
                                                       // sufficiently large set of SINR samples
            {
                std::vector<double> vectorNoisy = m_sinrVectorNoisy.at(pairDevices);
                std::pair<uint64_t, uint64_t> pairFiltering = ApplyFilter(
                    vectorNoisy); // find where to apply the filter, according to the variance
                m_samplesFilter.at(pairDevices) = pairFiltering; // where to apply the linear filter
                NS_LOG_DEBUG("Noisy vector start at sample " << std::get<0>(pairFiltering));
                NS_LOG_DEBUG("Noisy vector end at sample " << std::get<1>(pairFiltering));

                /* just apply filter where the SINR is too low and we are in a blockage situation */
                if (std::get<0>(m_samplesFilter.at(pairDevices)) ==
                    std::get<1>(m_samplesFilter.at(pairDevices))) // if start = end
                {
                    m_finalSinrVector.at(pairDevices) =
                        m_sinrVectorToFilter.at(pairDevices); // no need to apply the filter
                    NS_LOG_DEBUG("At time "
                                 << Now().GetMicroSeconds()
                                 << " there is no need to apply the Kalman filter for mmWave eNB "
                                 << m_cellId << " and UE " << ue->first);
                }
                else
                {
                    std::vector<double> vectorToFilter = m_sinrVectorToFilter.at(pairDevices);
                    std::vector<double> sinrVector = m_sinrVector.at(pairDevices);
                    std::pair<uint64_t, uint64_t> filterPair = m_samplesFilter.at(pairDevices);
                    m_finalSinrVector.at(pairDevices) =
                        MakeFilter(vectorNoisy, sinrVector, filterPair);
                    NS_LOG_DEBUG("finaltrace " << m_finalSinrVector.at(pairDevices).back());
                }

                /* the last sample in the filtered sequence is referred to the current time instant,
                 * referred to the uplink reference signal that is used to build the RT in the
                 * LteEnbRrc class */
                double sampleToForward = m_finalSinrVector.at(pairDevices).back();
                if (sampleToForward < 0) // this would be converted in NaN, in the log scale
                {
                    sampleToForward = 1e-20;
                }
                NS_LOG_DEBUG(" mmWave eNB " << m_cellId << " reports the SINR "
                                            << 10 * std::log10(sampleToForward) << " for UE "
                                            << ue->first);
                m_sinrMap[ue->first] =
                    sampleToForward; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< in order to
                                     // FORWARD to LteEnbRrc the value of SINR for the RT

                // m_sinrVectorToFilter.at(pairDevices).erase(m_sinrVectorToFilter.at(pairDevices).begin());
                // m_sinrVectorToFilter.at(pairDevices).push_back(m_finalSinrVector.at(pairDevices).back());
                m_sinrVectorToFilter.at(pairDevices).pop_back();
                m_sinrVectorToFilter.at(pairDevices)
                    .push_back(m_finalSinrVector.at(pairDevices).back());
            }
            else // before the transient is over, just forwart the (last) noisy sample, without
                 // having filtered
            {
                double sampleToForward = m_sinrVectorToFilter.at(pairDevices).back();
                if (sampleToForward < 0) // this would be converted in NaN, in the log scale
                {
                    sampleToForward = 1e-20;
                }
                NS_LOG_DEBUG(" mmWave eNB " << m_cellId << " FIRST reports the SINR "
                                            << 10 * std::log10(sampleToForward) << " for UE "
                                            << ue->first);
                m_sinrMap[ue->first] =
                    sampleToForward; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< in order to
                                     // FORWARD to LteEnbRrc the value of SINR for the RT
            }

            /* after the SINR sample is forwarded, I need to REFRESH all the maps, so that
             * a new SINR sequence can be created, to generate a new SINR sample
             * for the next RT
             */
            m_finalSinrVector.erase(pairDevices);
            m_samplesFilter.erase(pairDevices);
            NS_LOG_DEBUG("ERASE MAPS FOR RT");
        }
        else // noise and filtering processes are not applied!
        {
            m_sinrMap[ue->first] = sinrAvg;
        }
    }

    if (m_roundFromLastUeSinrUpdate >= (m_ueUpdateSinrPeriod / m_updateSinrPeriod))
    {
        m_roundFromLastUeSinrUpdate = 0;
        for (auto ueIt = m_ueAttachedImsiMap.begin(); ueIt != m_ueAttachedImsiMap.end(); ++ueIt)
        {
            // distinguish between MC and MmWaveNetDevice
            Ptr<mmwave::MmWaveUeNetDevice> ueNetDevice =
                DynamicCast<mmwave::MmWaveUeNetDevice>(ueIt->second);
            Ptr<McUeNetDevice> mcUeDev = DynamicCast<McUeNetDevice>(ueIt->second);
            Ptr<MmWaveUePhy> uePhy;
            if (ueNetDevice)
            {
                uePhy = ueNetDevice->GetPhy();
            }
            else if (mcUeDev) // it may be a MC device
            {
                uePhy = mcUeDev->GetMmWavePhy();
            }
            uePhy->UpdateSinrEstimate(m_cellId, m_sinrMap.find(ueIt->first)->second);
        }
    }
    else
    {
        m_roundFromLastUeSinrUpdate++;
    }

    LteEnbCphySapUser::UeAssociatedSinrInfo info;
    info.ueImsiSinrMap = m_sinrMap;
    info.componentCarrierId = m_componentCarrierId;
    m_enbCphySapUser->UpdateUeSinrEstimate(info);

    Simulator::Schedule(MicroSeconds(m_updateSinrPeriod),
                        &MmWaveEnbPhy::UpdateUeSinrEstimate,
                        this); // recall after m_updateSinrPeriod microseconds
}

void
MmWaveEnbPhy::StartSlot(void)
{
    NS_LOG_FUNCTION(this);

    m_lastSlotStart = Simulator::Now();
    m_currSlotAllocInfo = m_slotAllocInfo[m_slotNum];
    NS_LOG_DEBUG("currSlotAllocInfo referring to: frame "
                 << m_currSlotAllocInfo.m_sfnSf.m_frameNum << " subframe "
                 << (uint16_t)m_currSlotAllocInfo.m_sfnSf.m_sfNum);
    NS_LOG_DEBUG("Member variables counters indicating: frame " << m_frameNum << " subframe "
                                                                << (uint16_t)m_sfNum);
    m_currSlotNumTti = m_currSlotAllocInfo.m_ttiAllocInfo.size();

    NS_ASSERT((m_currSlotAllocInfo.m_sfnSf.m_frameNum == m_frameNum) &&
              (m_currSlotAllocInfo.m_sfnSf.m_sfNum == m_sfNum) &&
              (m_currSlotAllocInfo.m_sfnSf.m_slotNum == m_slotNum));

    // TODO: the MIB and the SIB transmissions need to be updated to the scheduling of NR
    if (m_sfNum == 0 && m_frameNum % 2 == 0) // send MIB at the beginning of each even frame
    {
        LteRrcSap::MasterInformationBlock mib;
        mib.dlBandwidth = (uint8_t)4;
        mib.systemFrameNumber = 1;
        Ptr<MmWaveMibMessage> mibMsg = Create<MmWaveMibMessage>();
        mibMsg->SetMib(mib);
        if (m_controlMessageQueue.empty())
        {
            std::list<Ptr<MmWaveControlMessage>> l;
            m_controlMessageQueue.push_back(l);
        }
        m_controlMessageQueue.at(0).push_back(mibMsg);
    }
    else if (m_sfNum == 0 && m_frameNum % 2 == 1) // send MIB at the beginning of each odd frame
    {
        Ptr<MmWaveSib1Message> msg = Create<MmWaveSib1Message>();
        msg->SetSib1(m_sib1);
        m_controlMessageQueue.at(0).push_back(msg);
    }

    StartTti();
}

void
MmWaveEnbPhy::StartTti(void)
{
    // TODO uncomment this lines for non-omni transmission of ctrl channels
    // This does not make any difference, since error model for the control messages
    // is not supported and ctrl messages are always received correctly
    // assume the control signal is omni
    // Ptr<AntennaArrayModel> antennaArray = DynamicCast<AntennaArrayModel> (GetDlSpectrumPhy
    // ()->GetRxAntenna()); antennaArray->ChangeToOmniTx ();

    NS_LOG_FUNCTION(this);
    NS_LOG_INFO("MmWave eNB " << m_cellId << " frame " << m_frameNum << " subframe "
                              << (uint16_t)m_sfNum << " slot " << (uint16_t)m_slotNum
                              << " TTI index " << (uint16_t)m_ttiIndex);

    TtiAllocInfo currTti = m_currSlotAllocInfo.m_ttiAllocInfo[m_ttiIndex];
    m_currSymStart = currTti.m_dci.m_symStart;

    SfnSf sfn = SfnSf(m_frameNum, m_sfNum, m_slotNum);
    std::list<Ptr<MmWaveControlMessage>> dciMsgList;
    Time guardPeriod;
    Time ttiPeriod;

    if (m_ttiIndex == 0) // First TTI: reserved DL control
    {
        // get control messages to be transmitted in DL-Control period
        std::list<Ptr<MmWaveControlMessage>> ctrlMsgs = GetControlMessages();
        // std::list <Ptr<MmWaveControlMessage > >::iterator it = ctrlMsgs.begin ();
        //  find all DL/UL DCI elements and create DCI messages to be transmitted in DL control
        //  period
        for (unsigned iTti = 0; iTti < m_currSlotAllocInfo.m_ttiAllocInfo.size(); iTti++)
        {
            if (m_currSlotAllocInfo.m_ttiAllocInfo[iTti].m_ttiType != TtiAllocInfo::CTRL &&
                m_currSlotAllocInfo.m_ttiAllocInfo[iTti].m_tddMode ==
                    TtiAllocInfo::DL_slotAllocInfo)
            {
                DciInfoElementTdma& dciElem = m_currSlotAllocInfo.m_ttiAllocInfo[iTti].m_dci;
                NS_ASSERT(dciElem.m_format == DciInfoElementTdma::DL_dci);
                if (dciElem.m_tbSize > 0)
                {
                    Ptr<MmWaveTdmaDciMessage> dciMsg = Create<MmWaveTdmaDciMessage>();
                    dciMsg->SetDciInfoElement(dciElem);
                    dciMsg->SetSfnSf(sfn);
                    dciMsgList.push_back(dciMsg);
                    ctrlMsgs.push_back(dciMsg);
                }
            }
        }

        unsigned ulSlotNum =
            (m_slotNum + m_phyMacConfig->GetUlSchedDelay()) % m_phyMacConfig->GetSlotsPerSubframe();
        for (unsigned iTti = 0; iTti < m_slotAllocInfo[ulSlotNum].m_ttiAllocInfo.size(); iTti++)
        {
            if (m_slotAllocInfo[ulSlotNum].m_ttiAllocInfo[iTti].m_ttiType != TtiAllocInfo::CTRL &&
                m_slotAllocInfo[ulSlotNum].m_ttiAllocInfo[iTti].m_tddMode ==
                    TtiAllocInfo::UL_slotAllocInfo)
            {
                DciInfoElementTdma& dciElem = m_slotAllocInfo[ulSlotNum].m_ttiAllocInfo[iTti].m_dci;
                NS_ASSERT(dciElem.m_format == DciInfoElementTdma::UL_dci);
                if (dciElem.m_tbSize > 0)
                {
                    Ptr<MmWaveTdmaDciMessage> dciMsg = Create<MmWaveTdmaDciMessage>();
                    dciMsg->SetDciInfoElement(dciElem);
                    dciMsg->SetSfnSf(sfn);
                    // dciMsgList.push_back (dciMsg);
                    ctrlMsgs.push_back(dciMsg);
                }
            }
        }

        // DL control data duration
        ttiPeriod = NanoSeconds(m_phyMacConfig->GetSymbolPeriod().GetNanoSeconds() *
                                m_phyMacConfig->GetDlCtrlSymbols());
        NS_LOG_DEBUG("ENB " << m_cellId << " TXing DL CTRL frame " << m_frameNum << " subframe "
                            << (unsigned)m_sfNum << " slot " << (uint16_t)m_slotNum << " symbols "
                            << (unsigned)currTti.m_dci.m_symStart << "-"
                            << (unsigned)(currTti.m_dci.m_symStart + currTti.m_dci.m_numSym - 1)
                            << "\t start " << Simulator::Now() << " end "
                            << Simulator::Now() + ttiPeriod - NanoSeconds(1.0));

        // Trace current DL transmission info
        TraceDlPhyTransmission(currTti.m_dci, PhyTransmissionTraceParams::CTRL);

        SendCtrlChannels(ctrlMsgs,
                         ttiPeriod -
                             NanoSeconds(1.0)); // -1 ns ensures control ends before data period
    }
    else if (m_ttiIndex == m_currSlotNumTti - 1) // Last TTI of this slot: reserved UL control
    {
        ttiPeriod = NanoSeconds(m_phyMacConfig->GetSymbolPeriod().GetNanoSeconds() *
                                m_phyMacConfig->GetUlCtrlSymbols());
        NS_LOG_DEBUG("ENB " << m_cellId << " RXing UL CTRL frame " << m_frameNum << " subframe "
                            << (unsigned)m_sfNum << " slot " << (uint16_t)m_slotNum << " symbols "
                            << (unsigned)currTti.m_dci.m_symStart << "-"
                            << (unsigned)(currTti.m_dci.m_symStart + currTti.m_dci.m_numSym - 1)
                            << "\t start " << Simulator::Now() << " end "
                            << Simulator::Now() + ttiPeriod);
    }
    else if (currTti.m_tddMode == TtiAllocInfo::DL_slotAllocInfo) // Scheduled DL data Tti
    {
        ttiPeriod = NanoSeconds(m_phyMacConfig->GetSymbolPeriod().GetNanoSeconds() *
                                currTti.m_dci.m_numSym);
        NS_ASSERT(currTti.m_tddMode == TtiAllocInfo::DL_slotAllocInfo);

        Ptr<PacketBurst> pktBurst =
            GetPacketBurst(SfnSf(m_frameNum, m_sfNum, m_slotNum, currTti.m_dci.m_symStart));
        if (pktBurst && pktBurst->GetNPackets() > 0)
        {
            std::list<Ptr<Packet>> pkts = pktBurst->GetPackets();
            MmWaveMacPduTag macTag;
            pkts.front()->PeekPacketTag(macTag);
            NS_ASSERT((macTag.GetSfn().m_frameNum == m_frameNum) &&
                      (macTag.GetSfn().m_sfNum == m_sfNum) &&
                      (macTag.GetSfn().m_slotNum == m_slotNum) &&
                      (macTag.GetSfn().m_symStart == currTti.m_dci.m_symStart));
        }
        else
        {
            // sometimes the UE will be scheduled when no data is queued
            // in this case, send an empty PDU
            MmWaveMacPduTag tag(SfnSf(m_frameNum, m_sfNum, m_slotNum, currTti.m_dci.m_symStart));
            Ptr<Packet> emptyPdu = Create<Packet>();
            MmWaveMacPduHeader header;
            MacSubheader subheader(3, 0); // lcid = 3, size = 0
            header.AddSubheader(subheader);
            emptyPdu->AddHeader(header);
            emptyPdu->AddPacketTag(tag);
            LteRadioBearerTag bearerTag(currTti.m_dci.m_rnti, 3, 0);
            emptyPdu->AddPacketTag(bearerTag);
            pktBurst = CreateObject<PacketBurst>();
            pktBurst->AddPacket(emptyPdu);
        }
        NS_LOG_DEBUG("ENB " << m_cellId << " TXing DL DATA frame " << m_frameNum << " subframe "
                            << (unsigned)m_sfNum << " slot " << (uint16_t)m_slotNum << " symbols "
                            << (unsigned)currTti.m_dci.m_symStart << "-"
                            << (unsigned)(currTti.m_dci.m_symStart + currTti.m_dci.m_numSym - 1)
                            << "\t start " << Simulator::Now() + NanoSeconds(1.0) << " end "
                            << Simulator::Now() + ttiPeriod - NanoSeconds(2.0));

        // Trace current DL transmission info
        TraceDlPhyTransmission(currTti.m_dci, PhyTransmissionTraceParams::DATA);

        Simulator::Schedule(NanoSeconds(1.0),
                            &MmWaveEnbPhy::SendDataChannels,
                            this,
                            pktBurst,
                            ttiPeriod - NanoSeconds(2.0),
                            currTti);
    }
    else if (currTti.m_tddMode == TtiAllocInfo::UL_slotAllocInfo) // Scheduled UL data Tti
    {
        ttiPeriod = NanoSeconds(m_phyMacConfig->GetSymbolPeriod().GetNanoSeconds() *
                                currTti.m_dci.m_numSym);
        // NS_LOG_DEBUG ("Slot " << (uint8_t)m_slotNum << " scheduled for Uplink");
        m_downlinkSpectrumPhy->AddExpectedTb(currTti.m_dci.m_rnti,
                                             currTti.m_dci.m_ndi,
                                             currTti.m_dci.m_tbSize,
                                             currTti.m_dci.m_mcs,
                                             m_channelChunks,
                                             currTti.m_dci.m_harqProcess,
                                             currTti.m_dci.m_rv,
                                             false,
                                             currTti.m_dci.m_symStart,
                                             currTti.m_dci.m_numSym);

        for (uint8_t i = 0; i < m_deviceMap.size(); i++)
        {
            Ptr<mmwave::MmWaveUeNetDevice> ueDev =
                DynamicCast<mmwave::MmWaveUeNetDevice>(m_deviceMap.at(i));
            Ptr<McUeNetDevice> mcUeDev = DynamicCast<McUeNetDevice>(m_deviceMap.at(i));
            uint64_t ueRnti =
                (ueDev) ? (ueDev->GetPhy()->GetRnti()) : (mcUeDev->GetMmWavePhy()->GetRnti());
            Ptr<NetDevice> associatedEnb =
                (ueDev) ? (ueDev->GetTargetEnb()) : (mcUeDev->GetMmWaveTargetEnb());

            NS_LOG_DEBUG("Scheduled rnti: " << currTti.m_rnti << " ue rnti: " << ueRnti
                                            << " target eNB " << associatedEnb << " this eNB "
                                            << m_netDevice);

            if (currTti.m_rnti == ueRnti && m_netDevice == associatedEnb)
            {
                // point the beam towards the user
                m_downlinkSpectrumPhy->ConfigureBeamforming(m_deviceMap.at(i));
                break;
            }
        }

        NS_LOG_DEBUG("ENB " << m_cellId << " RXing UL DATA frame " << m_frameNum << " subframe "
                            << (unsigned)m_sfNum << " slot " << (uint16_t)m_slotNum << " symbols "
                            << (unsigned)currTti.m_dci.m_symStart << "-"
                            << (unsigned)(currTti.m_dci.m_symStart + currTti.m_dci.m_numSym - 1)
                            << "\t start " << Simulator::Now() << " end "
                            << Simulator::Now() + ttiPeriod);
    }

    m_prevTtiDir = currTti.m_tddMode;

    NS_ASSERT(m_ttiIndex != 0 || currTti.m_dci.m_symStart == m_ttiIndex);
    m_phySapUser->SlotIndication(
        SfnSf(m_frameNum, m_sfNum, m_slotNum, currTti.m_dci.m_symStart)); // trigger MAC

    Simulator::Schedule(ttiPeriod, &MmWaveEnbPhy::EndTti, this);
}

void
MmWaveEnbPhy::EndTti(void)
{
    NS_LOG_FUNCTION(this << Simulator::Now().GetSeconds());

    // Ptr<AntennaArrayModel> antennaArray = DynamicCast<AntennaArrayModel> (GetDlSpectrumPhy
    // ()->GetRxAntenna()); antennaArray->ChangeToOmniTx ();

    if (m_ttiIndex == m_currSlotNumTti - 1) // End of the current NR slot
    {
        Time nextSlotDelay = MmWavePhy::GetNextSlotDelay();
        Simulator::Schedule(nextSlotDelay, &MmWaveEnbPhy::EndSlot, this);
    }
    else
    {
        m_ttiIndex++;
        Time nextTtiStart = m_phyMacConfig->GetSymbolPeriod() *
                            m_currSlotAllocInfo.m_ttiAllocInfo[m_ttiIndex].m_dci.m_symStart;
        Simulator::Schedule(nextTtiStart + m_lastSlotStart - Simulator::Now(),
                            &MmWaveEnbPhy::StartTti,
                            this);
    }
}

void
MmWaveEnbPhy::EndSlot(void)
{
    NS_LOG_FUNCTION(this << Simulator::Now().GetSeconds());

    m_ttiIndex = 0;

    if (m_slotNum == m_phyMacConfig->GetSlotsPerSubframe() - 1) // End of this subframe
    {
        m_slotNum = 0;
        if (m_sfNum == m_phyMacConfig->GetSubframesPerFrame() - 1) // End of the frame as well
        {
            m_sfNum = 0;
            m_frameNum++;
        }
        else // End of the current subframe only
        {
            m_sfNum++;
        }
    }
    else // End of just the slot
    {
        m_slotNum++;
    }

    // The slot end time should already be anchored to the proper value, hence try to avoid using
    // Schedule.
    NS_ASSERT(MmWavePhy::GetNextSlotDelay() == Time(0));
    StartSlot();
}

void
MmWaveEnbPhy::SendDataChannels(Ptr<PacketBurst> pb, Time slotPrd, TtiAllocInfo& slotInfo)
{
    if (slotInfo.m_isOmni)
    {
        // TODO should we support this?
        // Ptr<AntennaArrayModel> antennaArray = DynamicCast<AntennaArrayModel> (GetDlSpectrumPhy
        // ()->GetRxAntenna ()); antennaArray->ChangeToOmniTx ();
    }
    else
    { // update beamforming vectors (currently supports 1 user only)
        // std::map<uint16_t, std::vector<unsigned> >::iterator ueRbIt = slotInfo.m_ueRbMap.begin();
        // uint16_t rnti = ueRbIt->first;
        for (uint8_t i = 0; i < m_deviceMap.size(); i++)
        {
            uint64_t ueRnti = 0;
            Ptr<mmwave::MmWaveUeNetDevice> ueDev =
                m_deviceMap.at(i)->GetObject<mmwave::MmWaveUeNetDevice>();
            Ptr<NetDevice> associatedEnb = 0;
            if (ueDev)
            {
                ueRnti = ueDev->GetPhy()->GetRnti();
                associatedEnb = ueDev->GetTargetEnb();
            }
            else
            {
                Ptr<McUeNetDevice> ueMcDev = m_deviceMap.at(i)->GetObject<McUeNetDevice>();
                ueRnti = ueMcDev->GetMmWavePhy()->GetRnti();
                associatedEnb = ueMcDev->GetMmWaveTargetEnb();
            }

            NS_LOG_DEBUG("Scheduled rnti: " << slotInfo.m_dci.m_rnti << " ue rnti: " << ueRnti
                                            << " target eNB " << associatedEnb << " this eNB "
                                            << m_netDevice);
            if (slotInfo.m_dci.m_rnti == ueRnti && m_netDevice == associatedEnb)
            {
                NS_LOG_DEBUG("Change Beamforming Vector");
                m_downlinkSpectrumPhy->ConfigureBeamforming(m_deviceMap.at(i));
                break;
            }
        }
    }

    std::list<Ptr<MmWaveControlMessage>> ctrlMsgs;
    m_downlinkSpectrumPhy->StartTxDataFrames(pb, ctrlMsgs, slotPrd, slotInfo.m_ttiIdx);
}

void
MmWaveEnbPhy::SendCtrlChannels(std::list<Ptr<MmWaveControlMessage>> ctrlMsgs, Time slotPrd)
{
    /* Send Ctrl messages*/
    NS_LOG_FUNCTION(this << "Send Ctrl");
    m_downlinkSpectrumPhy->StartTxDlControlFrames(ctrlMsgs, slotPrd);
}

bool
MmWaveEnbPhy::AddUePhy(uint64_t imsi, Ptr<NetDevice> ueDevice)
{
    NS_LOG_FUNCTION(this << imsi);
    std::set<uint64_t>::iterator it;
    it = m_ueAttached.find(imsi);

    if (it == m_ueAttached.end())
    {
        m_ueAttached.insert(imsi);
        m_deviceMap.push_back(ueDevice);
        m_ueAttachedImsiMap[imsi] = ueDevice;
        return (true);
    }
    else
    {
        NS_LOG_ERROR("Programming error...UE already attached");
        return (false);
    }
}

void
MmWaveEnbPhy::PhyDataPacketReceived(Ptr<Packet> p)
{
    Simulator::ScheduleWithContext(m_netDevice->GetNode()->GetId(),
                                   MicroSeconds(m_phyMacConfig->GetTbDecodeLatency()),
                                   &MmWaveEnbPhySapUser::ReceivePhyPdu,
                                   m_phySapUser,
                                   p);
    //      m_phySapUser->ReceivePhyPdu(p);
}

void
MmWaveEnbPhy::GenerateDataCqiReport(const SpectrumValue& sinr)
{
    NS_LOG_LOGIC("Sinr from DataCqiReport = " << sinr);
    double sinrAvg = Sum(sinr) / (sinr.GetSpectrumModel()->GetNumBands());
    NS_LOG_INFO("Average SINR on DataCqiReport " << 10 * std::log10(sinrAvg));

    Values::const_iterator it;
    MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters ulcqi;
    ulcqi.m_ulCqi.m_type = UlCqiInfo::PUSCH;
    int i = 0;
    for (it = sinr.ConstValuesBegin(); it != sinr.ConstValuesEnd(); it++)
    {
        //      double sinrdb = 10 * std::log10 ((*it));
        //       NS_LOG_DEBUG ("ULCQI RB " << i << " value " << sinrdb);
        // convert from double to fixed point notaltion Sxxxxxxxxxxx.xxx
        //      int16_t sinrFp = LteFfConverter::double2fpS11dot3 (sinrdb);
        ulcqi.m_ulCqi.m_sinr.push_back(*it);
        i++;
    }

    // here we use the start symbol index of the slot in place of the slot index because the
    // absolute UL slot index is not known to the scheduler when m_allocationMap gets populated
    ulcqi.m_sfnSf = SfnSf(m_frameNum,
                          m_sfNum,
                          m_slotNum,
                          m_currSymStart); // TODO: .m_slotNum expected to carry m_currSymStart
    SpectrumValue newSinr = sinr;
    m_ulSinrTrace(0, newSinr, newSinr);
    m_phySapUser->UlCqiReport(ulcqi);
}

void
MmWaveEnbPhy::PhyCtrlMessagesReceived(std::list<Ptr<MmWaveControlMessage>> msgList)
{
    std::list<Ptr<MmWaveControlMessage>>::iterator ctrlIt = msgList.begin();

    while (ctrlIt != msgList.end())
    {
        Ptr<MmWaveControlMessage> msg = (*ctrlIt);

        if (msg->GetMessageType() == MmWaveControlMessage::DL_CQI)
        {
            NS_LOG_INFO("ENB " << m_cellId << " received CQI");
            m_phySapUser->ReceiveControlMessage(msg);
        }
        else if (msg->GetMessageType() == MmWaveControlMessage::BSR)
        {
            NS_LOG_INFO("ENB " << m_cellId << " received BSR");
            m_phySapUser->ReceiveControlMessage(msg);
        }
        else if (msg->GetMessageType() == MmWaveControlMessage::RACH_PREAMBLE)
        {
            NS_LOG_INFO("ENB " << m_cellId << " received RACH_PREAMBLE");
            NS_ASSERT(m_cellId > 0);
            Ptr<MmWaveRachPreambleMessage> rachPreamble =
                DynamicCast<MmWaveRachPreambleMessage>(msg);
            m_phySapUser->ReceiveRachPreamble(rachPreamble->GetRapId());
        }
        else if (msg->GetMessageType() == MmWaveControlMessage::DL_HARQ)
        {
            Ptr<MmWaveDlHarqFeedbackMessage> dlharqMsg =
                DynamicCast<MmWaveDlHarqFeedbackMessage>(msg);
            DlHarqInfo dlharq = dlharqMsg->GetDlHarqFeedback();
            // check whether the UE is connected
            if (m_ueAttachedRnti.find(dlharq.m_rnti) != m_ueAttachedRnti.end())
            {
                m_phySapUser->ReceiveControlMessage(msg);
            }
        }

        ctrlIt++;
    }
}

uint32_t
MmWaveEnbPhy::GetAbsoluteSubframeNo()
{
    return ((m_frameNum - 1) *
                (m_phyMacConfig->GetSubframesPerFrame() * m_phyMacConfig->GetSlotsPerSubframe()) +
            m_slotNum);
}

void
MmWaveEnbPhy::TraceDlPhyTransmission(DciInfoElementTdma dciInfo, uint8_t tddType)
{
    PhyTransmissionTraceParams dlPhyTraceInfo; //!< Holds the current DL transmission info
    dlPhyTraceInfo.m_frameNum = m_frameNum;
    dlPhyTraceInfo.m_sfNum = m_sfNum;
    dlPhyTraceInfo.m_slotNum = m_slotNum;
    dlPhyTraceInfo.m_symStart = dciInfo.m_symStart;
    dlPhyTraceInfo.m_numSym = dciInfo.m_numSym;
    dlPhyTraceInfo.m_tddMode = PhyTransmissionTraceParams::DL;
    dlPhyTraceInfo.m_ttiType = tddType;
    dlPhyTraceInfo.m_rnti = dciInfo.m_rnti;
    dlPhyTraceInfo.m_rv = dciInfo.m_rv;
    dlPhyTraceInfo.m_ccId = m_componentCarrierId;
    m_dlPhyTrace(dlPhyTraceInfo);
}

////////////////////////////////////////////////////////////
/////////                     sap                 /////////
///////////////////////////////////////////////////////////

void
MmWaveEnbPhy::DoSetBandwidth(uint8_t ulBandwidth, uint8_t dlBandwidth)
{
    NS_LOG_FUNCTION(this << (uint32_t)ulBandwidth << (uint32_t)dlBandwidth);
}

void
MmWaveEnbPhy::DoSetEarfcn(uint16_t ulEarfcn, uint16_t dlEarfcn)
{
    NS_LOG_FUNCTION(this << ulEarfcn << dlEarfcn);
}

void
MmWaveEnbPhy::DoAddUe(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);
    bool success = AddUePhy(rnti);
    NS_ASSERT_MSG(success, "AddUePhy() failed");
}

bool
MmWaveEnbPhy::AddUePhy(uint16_t rnti)
{
    NS_LOG_FUNCTION(this << rnti);
    std::set<uint16_t>::iterator it;
    it = m_ueAttachedRnti.find(rnti);
    if (it == m_ueAttachedRnti.end())
    {
        m_ueAttachedRnti.insert(rnti);
        return (true);
    }
    else
    {
        NS_LOG_ERROR("UE already attached");
        return (false);
    }
}

void
MmWaveEnbPhy::DoRemoveUe(uint16_t rnti)
{
    std::set<uint16_t>::iterator it = m_ueAttachedRnti.find(rnti);
    if (it != m_ueAttachedRnti.end())
    {
        m_ueAttachedRnti.erase(it);
    }
    else
    {
        NS_FATAL_ERROR("Impossible to remove UE, not attached!");
    }
    NS_LOG_FUNCTION(this << rnti);
}

void
MmWaveEnbPhy::DoSetPa(uint16_t rnti, double pa)
{
    NS_LOG_FUNCTION(this << rnti);
}

void
MmWaveEnbPhy::DoSetTransmissionMode(uint16_t rnti, uint8_t txMode)
{
    NS_LOG_FUNCTION(this << rnti << (uint16_t)txMode);
    // UL supports only SISO MODE
}

void
MmWaveEnbPhy::DoSetSrsConfigurationIndex(uint16_t rnti, uint16_t srcCi)
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveEnbPhy::DoSetMasterInformationBlock(LteRrcSap::MasterInformationBlock mib)
{
    NS_LOG_FUNCTION(this);
    // m_mib = mib;
}

void
MmWaveEnbPhy::DoSetSystemInformationBlockType1(LteRrcSap::SystemInformationBlockType1 sib1)
{
    NS_LOG_FUNCTION(this);
    m_sib1 = sib1;
}

int8_t
MmWaveEnbPhy::DoGetReferenceSignalPower() const
{
    NS_LOG_FUNCTION(this);
    return m_txPower;
}

void
MmWaveEnbPhy::SetPhySapUser(MmWaveEnbPhySapUser* ptr)
{
    m_phySapUser = ptr;
}

void
MmWaveEnbPhy::SetHarqPhyModule(Ptr<MmWaveHarqPhy> harq)
{
    m_harqPhyModule = harq;
}

void
MmWaveEnbPhy::ReceiveUlHarqFeedback(UlHarqInfo mes)
{
    NS_LOG_FUNCTION(this);
    // forward to scheduler
    //
    if (m_ueAttachedRnti.find(mes.m_rnti) != m_ueAttachedRnti.end())
    {
        m_phySapUser->UlHarqFeedback(mes);
    }
}

} // namespace mmwave

} // namespace ns3
