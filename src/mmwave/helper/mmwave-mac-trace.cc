/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2020, University of Padova, Dep. of Information Engineering, SIGNET lab
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
 *   Author: Matteo Pagin <mattpagg@gmail.com>
 */

#include "mmwave-mac-trace.h"

#include <ns3/log.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWaveMacTrace");

namespace mmwave
{

NS_OBJECT_ENSURE_REGISTERED(MmWaveMacTrace);

std::ofstream MmWaveMacTrace::m_schedAllocTraceFile{};
std::string MmWaveMacTrace::m_schedAllocTraceFilename{};

MmWaveMacTrace::MmWaveMacTrace()
{
}

MmWaveMacTrace::~MmWaveMacTrace()
{
    if (m_schedAllocTraceFile.is_open())
    {
        m_schedAllocTraceFile.close();
    }
}

TypeId
MmWaveMacTrace::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::MmWaveMacTrace")
                            .SetParent<Object>()
                            .AddConstructor<MmWaveMacTrace>()
                            .AddAttribute("SchedInfoOutputFilename",
                                          "Name of the file where the allocation info provided by "
                                          "the scheduler will be saved.",
                                          StringValue("EnbSchedAllocTraces.txt"),
                                          MakeStringAccessor(&MmWaveMacTrace::SetOutputFilename),
                                          MakeStringChecker());
    return tid;
}

void
MmWaveMacTrace::ReportEnbSchedulingInfo(Ptr<MmWaveMacTrace> enbStats,
                                        MmWaveEnbMac::MmWaveSchedTraceInfo schedParams)
{
    // Open the output file if it is not open yet
    if (!m_schedAllocTraceFile.is_open())
    {
        m_schedAllocTraceFile.open(m_schedAllocTraceFilename.c_str());
        if (!m_schedAllocTraceFile.is_open())
        {
            NS_FATAL_ERROR("Could not open tracefile");
        }
        m_schedAllocTraceFile
            << "frame\tsubF\tslot\trnti\tfirstSym\tnumSym\ttype\ttddMode\tretxNum\tccId"
            << std::endl;
    }

    SlotAllocInfo allocInfo = schedParams.m_indParam.m_slotAllocInfo;
    SfnSf dlSfn =
        schedParams.m_indParam.m_sfnSf; // Holds the intended slot, subframe and frame info

    for (auto iTti : allocInfo.m_ttiAllocInfo)
    {
        // Trace the incoming alloc info
        m_schedAllocTraceFile << +dlSfn.m_frameNum << "\t" << +dlSfn.m_sfNum << "\t"
                              << +dlSfn.m_slotNum << "\t" << +iTti.m_dci.m_rnti << "\t"
                              << +iTti.m_dci.m_symStart << "\t" << +iTti.m_dci.m_numSym << "\t"
                              << iTti.m_ttiType << "\t" << iTti.m_tddMode << "\t"
                              << +iTti.m_dci.m_rv << "\t" << +schedParams.m_ccId << std::endl;
    }
}

void
MmWaveMacTrace::SetOutputFilename(std::string fileName)
{
    NS_LOG_INFO("Filename: " << fileName);
    m_schedAllocTraceFilename = fileName;
}

} // namespace mmwave

} /* namespace ns3 */
