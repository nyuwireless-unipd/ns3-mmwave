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
 *                 Dual Connectivity and Handover functionalities
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                          Integration of Carrier Aggregation for the mmWave module
 */

#include "mmwave-phy-trace.h"

#include <ns3/log.h>
#include <ns3/simulator.h>

#include <stdio.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWavePhyTrace");

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWavePhyTrace);

std::ofstream MmWavePhyTrace::m_rxPacketTraceFile;
std::string MmWavePhyTrace::m_rxPacketTraceFilename;

std::ofstream MmWavePhyTrace::m_ulPhyTraceFile{};
std::string MmWavePhyTrace::m_ulPhyTraceFilename{};

std::ofstream MmWavePhyTrace::m_dlPhyTraceFile{};
std::string MmWavePhyTrace::m_dlPhyTraceFilename{};

MmWavePhyTrace::MmWavePhyTrace()
{
}

MmWavePhyTrace::~MmWavePhyTrace()
{
    if (m_rxPacketTraceFile.is_open())
    {
        m_rxPacketTraceFile.close();
    }
}

TypeId
MmWavePhyTrace::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWavePhyTrace")
            .SetParent<Object>()
            .AddConstructor<MmWavePhyTrace>()
            .AddAttribute("OutputFilename",
                          "Name of the file where the uplink results will be saved.",
                          StringValue("RxPacketTrace.txt"),
                          MakeStringAccessor(&MmWavePhyTrace::SetPhyRxOutputFilename),
                          MakeStringChecker())
            .AddAttribute("UlPhyTransmissionFilename",
                          "Name of the file where the UL transmission info will be saved.",
                          StringValue("UlPhyTransmissionTrace.txt"),
                          MakeStringAccessor(&MmWavePhyTrace::SetUlPhyTxOutputFilename),
                          MakeStringChecker())
            .AddAttribute("DlPhyTransmissionFilename",
                          "Name of the file where the DL transmission info will be saved.",
                          StringValue("DlPhyTransmissionTrace.txt"),
                          MakeStringAccessor(&MmWavePhyTrace::SetDlPhyTxOutputFilename),
                          MakeStringChecker())

        ;
    return tid;
}

void
MmWavePhyTrace::SetPhyRxOutputFilename(std::string fileName)
{
    NS_LOG_INFO("RxPacketTrace main filename: " << fileName);
    m_rxPacketTraceFilename = fileName;
}

void
MmWavePhyTrace::SetUlPhyTxOutputFilename(std::string fileName)
{
    NS_LOG_INFO("UL PHY transmission trace filename: " << fileName);
    m_ulPhyTraceFilename = fileName;
}

void
MmWavePhyTrace::SetDlPhyTxOutputFilename(std::string fileName)
{
    NS_LOG_INFO("DL PHY transmission trace filename: " << fileName);
    m_dlPhyTraceFilename = fileName;
}

void
MmWavePhyTrace::ReportCurrentCellRsrpSinrCallback(Ptr<MmWavePhyTrace> phyStats,
                                                  std::string path,
                                                  uint64_t imsi,
                                                  SpectrumValue& sinr,
                                                  SpectrumValue& power)
{
    NS_LOG_INFO("UE" << imsi << "->Generate RsrpSinrTrace");
    // phyStats->ReportInterferenceTrace (imsi, sinr);
}

/*void
MmWavePhyTrace::ReportInterferenceTrace (uint64_t imsi, SpectrumValue& sinr)
{
        uint64_t slot_count = Now().GetMicroSeconds ()/125;
        uint32_t rb_count = 1;
        FILE* log_file;
        char fname[255];
        sprintf(fname, "UE_%llu_SINR_dB.txt", (long long unsigned ) imsi);
        log_file = fopen(fname, "a");
        Values::iterator it = sinr.ValuesBegin();
        while(it!=sinr.ValuesEnd())
        {
                //fprintf(log_file, "%d\t%d\t%f\t \n", slot_count/2, rb_count, 10*log10(*it));
                fprintf(log_file, "%llu\t%llu\t%d\t%f\t \n",(long long unsigned) slot_count/8+1,
(long long unsigned) slot_count%8+1, rb_count, 10*log10(*it)); rb_count++; it++;
        }
        fflush(log_file);
        fclose(log_file);
}*/

void
MmWavePhyTrace::ReportDownLinkTBSize(Ptr<MmWavePhyTrace> phyStats,
                                     std::string path,
                                     uint64_t imsi,
                                     uint64_t tbSize)
{
    // phyStats->ReportDLTbSize (imsi, tbSize);
}

/*
void
MmWavePhyTrace::ReportPacketCountEnb (EnbPhyPacketCountParameter param)
{
        FILE* log_file;
        char fname[255];
        sprintf (fname,"BS_%llu_Packet_Trace.txt",(long long unsigned) param.m_cellId);
        log_file = fopen (fname, "a");
        if (param.m_isTx)
        {
                fprintf (log_file, "%d\t%d\t%d\n", param.m_subframeno, param.m_noBytes, 0);
        }
        else
        {
                fprintf (log_file, "%d\t%d\t%d\n", param.m_subframeno, 0, param.m_noBytes);
        }

        fflush(log_file);
        fclose(log_file);
}

void
MmWavePhyTrace::ReportDLTbSize (uint64_t imsi, uint64_t tbSize)
{
        FILE* log_file;
        char fname[255];
        sprintf (fname,"UE_%llu_Tb_Size.txt", (long long unsigned) imsi);
        log_file = fopen (fname, "a");

        fprintf (log_file, "%llu \t %llu\n", Now().GetMicroSeconds (), tbSize);
        fprintf (log_file, "%lld \t %llu \n",(long long int) Now().GetMicroSeconds (), (long long
unsigned) tbSize); fflush(log_file); fclose(log_file);
}
*/
void
MmWavePhyTrace::ReportUlPhyTransmissionCallback(Ptr<MmWavePhyTrace> phyStats,
                                                PhyTransmissionTraceParams param)
{
    if (!m_ulPhyTraceFile.is_open())
    {
        m_ulPhyTraceFile.open(m_ulPhyTraceFilename.c_str());
        if (!m_ulPhyTraceFile.is_open())
        {
            NS_FATAL_ERROR("Could not open tracefile");
        }
        m_ulPhyTraceFile
            << "frame\tsubF\tslot\trnti\tfirstSym\tnumSym\ttype\ttddMode\tretxNum\tccId"
            << std::endl;
    }

    // Trace the UL PHY transmission info
    m_ulPhyTraceFile << +param.m_frameNum << "\t" << +param.m_sfNum << "\t" << +param.m_slotNum
                     << "\t" << +param.m_rnti << "\t" << +param.m_symStart << "\t"
                     << +param.m_numSym << "\t" << +param.m_ttiType << "\t" << +param.m_tddMode
                     << "\t" << +param.m_rv << "\t" << +param.m_ccId << std::endl;
}

void
MmWavePhyTrace::ReportDlPhyTransmissionCallback(Ptr<MmWavePhyTrace> phyStats,
                                                PhyTransmissionTraceParams param)
{
    if (!m_dlPhyTraceFile.is_open())
    {
        m_dlPhyTraceFile.open(m_dlPhyTraceFilename.c_str());
        if (!m_dlPhyTraceFile.is_open())
        {
            NS_FATAL_ERROR("Could not open tracefile");
        }
        m_dlPhyTraceFile
            << "frame\tsubF\tslot\trnti\tfirstSym\tnumSym\ttype\ttddMode\tretxNum\tccId"
            << std::endl;
    }

    // Trace the DL PHY transmission info
    m_dlPhyTraceFile << +param.m_frameNum << "\t" << +param.m_sfNum << "\t" << +param.m_slotNum
                     << "\t" << +param.m_rnti << "\t" << +param.m_symStart << "\t"
                     << +param.m_numSym << "\t" << +param.m_ttiType << "\t" << +param.m_tddMode
                     << "\t" << +param.m_rv << "\t" << +param.m_ccId << std::endl;
}

void
MmWavePhyTrace::RxPacketTraceUeCallback(Ptr<MmWavePhyTrace> phyStats,
                                        std::string path,
                                        RxPacketTraceParams params)
{
    if (!m_rxPacketTraceFile.is_open())
    {
        m_rxPacketTraceFile.open(m_rxPacketTraceFilename.c_str());
        m_rxPacketTraceFile << "DL/"
                               "UL\ttime\tframe\tsubF\tslot\t1stSym\tsymbol#"
                               "\tcellId\trnti\tccId\ttbSize\tmcs\trv\tSINR(dB)\tcorrupt\tTBler"
                            << std::endl;
        if (!m_rxPacketTraceFile.is_open())
        {
            NS_FATAL_ERROR("Could not open tracefile");
        }
    }
    m_rxPacketTraceFile << "DL\t" << Simulator::Now().GetSeconds() << "\t" << params.m_frameNum
                        << "\t" << +params.m_sfNum << "\t" << +params.m_slotNum << "\t"
                        << +params.m_symStart << "\t" << +params.m_numSym << "\t" << params.m_cellId
                        << "\t" << params.m_rnti << "\t" << +params.m_ccId << "\t"
                        << params.m_tbSize << "\t" << +params.m_mcs << "\t" << +params.m_rv << "\t"
                        << 10 * std::log10(params.m_sinr) << "\t" << params.m_corrupt << "\t"
                        << params.m_tbler << std::endl;

    if (params.m_corrupt)
    {
        NS_LOG_DEBUG("DL TB error\t"
                     << params.m_frameNum << "\t" << +params.m_sfNum << "\t" << +params.m_slotNum
                     << "\t" << +params.m_symStart << "\t" << +params.m_numSym << "\t"
                     << params.m_rnti << "\t" << +params.m_ccId << "\t" << params.m_tbSize << "\t"
                     << +params.m_mcs << "\t" << +params.m_rv << "\t"
                     << 10 * std::log10(params.m_sinr) << "\t" << params.m_tbler << "\t"
                     << params.m_corrupt);
    }
}

void
MmWavePhyTrace::RxPacketTraceEnbCallback(Ptr<MmWavePhyTrace> phyStats,
                                         std::string path,
                                         RxPacketTraceParams params)
{
    if (!m_rxPacketTraceFile.is_open())
    {
        m_rxPacketTraceFile.open(m_rxPacketTraceFilename.c_str());
        m_rxPacketTraceFile << "DL/"
                               "UL\ttime\tframe\tsubF\tslot\t1stSym\tsymbol#"
                               "\tcellId\trnti\tccId\ttbSize\tmcs\trv\tSINR(dB)\tcorrupt\tTBler"
                            << std::endl;
        if (!m_rxPacketTraceFile.is_open())
        {
            NS_FATAL_ERROR("Could not open tracefile");
        }
    }
    m_rxPacketTraceFile << "UL\t" << Simulator::Now().GetSeconds() << "\t" << params.m_frameNum
                        << "\t" << +params.m_sfNum << "\t" << +params.m_slotNum << "\t"
                        << +params.m_symStart << "\t" << +params.m_numSym << "\t" << params.m_cellId
                        << "\t" << params.m_rnti << "\t" << +params.m_ccId << "\t"
                        << params.m_tbSize << "\t" << +params.m_mcs << "\t" << +params.m_rv << "\t"
                        << 10 * std::log10(params.m_sinr) << " \t" << params.m_corrupt << "\t"
                        << params.m_tbler << std::endl;

    if (params.m_corrupt)
    {
        NS_LOG_DEBUG("UL TB error\t"
                     << params.m_frameNum << "\t" << +params.m_sfNum << "\t" << +params.m_slotNum
                     << "\t" << +params.m_symStart << "\t" << +params.m_numSym << "\t"
                     << params.m_rnti << "\t" << +params.m_ccId << "\t" << params.m_tbSize << "\t"
                     << +params.m_mcs << "\t" << +params.m_rv << "\t"
                     << 10 * std::log10(params.m_sinr) << "\t" << params.m_tbler << "\t"
                     << params.m_corrupt << "\t" << params.m_sinrMin);
    }
}

} // namespace mmwave

} /* namespace ns3 */
