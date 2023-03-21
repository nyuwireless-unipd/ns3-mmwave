/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab.
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

#include "ns3/enum.h"
#include <ns3/attribute-accessor-helper.h>
#include <ns3/double.h>
#include <ns3/log.h>
#include <ns3/mmwave-phy-mac-common.h>
#include <ns3/simulator.h>
#include <ns3/string.h>
#include <ns3/uinteger.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWavePhyMacCommon");

NS_OBJECT_ENSURE_REGISTERED(MmWavePhyMacCommon);

TypeId
MmWavePhyMacCommon::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWavePhyMacCommon")
            .SetParent<Object>()
            .AddConstructor<MmWavePhyMacCommon>()
            .AddAttribute(
                "Numerology",
                "The PHY layer numerology",
                EnumValue(2),
                MakeEnumAccessor(&MmWavePhyMacCommon::SetNumerology),
                MakeEnumChecker(NrNumerology2, "NrNumerology2", NrNumerology3, "NrNumerology3"))
            .AddAttribute("Bandwidth",
                          "The carrier bandwidth in Hz",
                          DoubleValue(200e6),
                          MakeDoubleAccessor(&MmWavePhyMacCommon::SetBandwidth),
                          MakeDoubleChecker<double>())
            .AddAttribute("CenterFreq",
                          "The center frequency in Hz",
                          DoubleValue(28e9),
                          MakeDoubleAccessor(&MmWavePhyMacCommon::m_centerFrequency),
                          MakeDoubleChecker<double>())
            .AddAttribute("UlSchedDelay",
                          "Delay between the UL-DCI transmission and when such scheduled UL will "
                          "take place, defined as # of NR slots.",
                          UintegerValue(1),
                          MakeUintegerAccessor(&MmWavePhyMacCommon::m_ulSchedDelay),
                          MakeUintegerChecker<uint32_t>())
            .AddAttribute("NumHarqProcess",
                          "Number of concurrent stop-and-wait Hybrid ARQ processes per user",
                          UintegerValue(20),
                          MakeUintegerAccessor(&MmWavePhyMacCommon::m_numHarqProcess),
                          MakeUintegerChecker<uint8_t>())
            .AddAttribute("HarqDlTimeout",
                          "Hybrid ARQ timeout period",
                          UintegerValue(20),
                          MakeUintegerAccessor(&MmWavePhyMacCommon::m_harqTimeout),
                          MakeUintegerChecker<uint8_t>())
            .AddAttribute("TbDecodeLatency",
                          "Time required by the PHY layer to decode a transport block in us.",
                          UintegerValue(100.0),
                          MakeUintegerAccessor(&MmWavePhyMacCommon::m_tbDecodeLatencyUs),
                          MakeUintegerChecker<uint32_t>())
            .AddAttribute("ComponentCarrierId",
                          "Component carrier ID",
                          UintegerValue(0),
                          MakeUintegerAccessor(&MmWavePhyMacCommon::m_componentCarrierId),
                          MakeUintegerChecker<uint8_t>());

    return tid;
}

MmWavePhyMacCommon::MmWavePhyMacCommon()
    : m_dlCtrlSymbols(1),
      m_ulCtrlSymbols(1),
      m_numRefSc(864),
      m_L1L2Latency(2)
{
    NS_LOG_INFO("Initialized MmWavePhyMacCommon");
}

void
MmWavePhyMacCommon::SetNumerology(Numerology num)
{
    NS_LOG_FUNCTION(this << num);

    if (num == Numerology::NrNumerology2)
        SetNrNumerology(2);
    else if (num == Numerology::NrNumerology3)
        SetNrNumerology(3);
    else
        NS_FATAL_ERROR("Currently, only numerologies 2 and 3 are supported!");
}

void
MmWavePhyMacCommon::SetNrNumerology(uint8_t index)
{
    NS_LOG_FUNCTION(this << index);
    NS_ASSERT_MSG((index == 2) || (index == 3),
                  "Numerology index is not valid."); // Only 2 and 3 are supported in NR for FR2.

    double subcarrierSpacing =
        15 * std::pow(2, index) *
        1000; // Subcarrier spacing, only 60KHz and 120KHz are supported in NR for FR2.

    m_symbolsPerSlot = 14; // TS 38.211 Sec 4.3.2: each slot must have 14 symbols
    m_slotsPerSubframe =
        std::pow(2, index); // Number of slots per subframe, see TS 38.211 Sec 4.3.2
    m_symbolsPerSubframe = m_symbolsPerSlot * m_slotsPerSubframe;
    m_subframesPerFrame = 10;
    m_subframePeriod =
        Time(MilliSeconds(1)); // TS 38.211 Section 4.3.1: the subframe duration is 1ms
    m_symbolPeriod = Time(m_subframePeriod / m_symbolsPerSlot /
                          m_slotsPerSubframe); // Duration of an OFDM symbol
    m_rbWidth = SUBCARRIERS_PER_RB * subcarrierSpacing;
}

void
MmWavePhyMacCommon::SetBandwidth(double bw)
{
    NS_LOG_FUNCTION(this << bw);

    m_numRbs =
        std::ceil(bw / m_rbWidth); // The amount of RBs is fixed to 1 as only TDMA is supported
    m_numRefSc = REF_SUBCARRIERS_PER_RB * m_numRbs;
}

void
MmWavePhyMacCommon::SetUlSchedDelay(uint32_t delay)
{
    NS_LOG_FUNCTION(this);

    // The scheduler assigns resources m_L1L2Latency slots in advance. Since UL DCIs must be sent
    // m_ulSchedDelay slots in advance, the latter parameter must be smaller than m_L1L2Latency for
    // the UL DCIs to be correctly received at the intended subframe.
    NS_ASSERT_MSG(delay < m_L1L2Latency,
                  "The UL scheduling delay must be lower than the L1L2Latency!");

    m_ulSchedDelay = delay;
}

} // namespace mmwave

} // namespace ns3
