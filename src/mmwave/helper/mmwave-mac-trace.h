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

#ifndef SRC_MMWAVE_HELPER_MMWAVE_MAC_TRACE_H_
#define SRC_MMWAVE_HELPER_MMWAVE_MAC_TRACE_H_

#include <ns3/mmwave-enb-mac.h>
#include <ns3/mmwave-phy-mac-common.h>
#include <ns3/object.h>

#include <fstream>

namespace ns3
{

namespace mmwave
{

/**
 * This class contains the MmWave, MAC-related tracing entities
 *
 * The purpose of this class is to implement the MmWave, MAC-related callbacks and to
 * organize their setup (such as the traces' filename and their output streams)
 *
 */
class MmWaveMacTrace : public Object
{
  public:
    MmWaveMacTrace();
    virtual ~MmWaveMacTrace();
    static TypeId GetTypeId(void);

    /**
     * Sets the filename for the MAC-related traces
     *
     * \param fileName the intended filename
     */
    void SetOutputFilename(std::string fileName);

    /**
     * Callback used to trace the reception of a scheduling decision by the eNB and from the
     * scheduler itself.
     *
     * \param schedParams the actual scheduling info
     * \param enbStats the pointer to an object of this class
     */
    static void ReportEnbSchedulingInfo(Ptr<MmWaveMacTrace> enbStats,
                                        MmWaveEnbMac::MmWaveSchedTraceInfo schedParams);

  private:
    static std::ofstream
        m_schedAllocTraceFile; //!< Output stream for the scheduling allocations trace
    static std::string
        m_schedAllocTraceFilename; //!< Output filename for the scheduling allocations trace
};

} // namespace mmwave

} /* namespace ns3 */

#endif /* SRC_MMWAVE_HELPER_MMWAVE_ENB_TRACE_H_ */
