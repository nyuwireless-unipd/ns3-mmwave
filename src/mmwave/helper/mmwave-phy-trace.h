/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *        Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET
 *lab
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
 *        Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                          Integration of Carrier Aggregation for the mmWave module
 */

#ifndef SRC_MMWAVE_HELPER_MMWAVE_PHY_TRACE_H_
#define SRC_MMWAVE_HELPER_MMWAVE_PHY_TRACE_H_
#include <ns3/mmwave-phy-mac-common.h>
#include <ns3/object.h>
#include <ns3/spectrum-value.h>

#include <fstream>
#include <iostream>

namespace ns3
{

namespace mmwave
{

class MmWavePhyTrace : public Object
{
  public:
    MmWavePhyTrace();
    virtual ~MmWavePhyTrace();
    static TypeId GetTypeId(void);
    static void ReportCurrentCellRsrpSinrCallback(Ptr<MmWavePhyTrace> phyStats,
                                                  std::string path,
                                                  uint64_t imsi,
                                                  SpectrumValue& sinr,
                                                  SpectrumValue& power);
    static void ReportDownLinkTBSize(Ptr<MmWavePhyTrace> phyStats,
                                     std::string path,
                                     uint64_t imsi,
                                     uint64_t tbSize);
    static void RxPacketTraceUeCallback(Ptr<MmWavePhyTrace> phyStats,
                                        std::string path,
                                        RxPacketTraceParams param);
    static void RxPacketTraceEnbCallback(Ptr<MmWavePhyTrace> phyStats,
                                         std::string path,
                                         RxPacketTraceParams param);

    /**
     * Callback used to trace an UL PHY tranmission
     */
    static void ReportUlPhyTransmissionCallback(Ptr<MmWavePhyTrace> phyStats,
                                                PhyTransmissionTraceParams param);

    /**
     * Callback used to trace a DL PHY tranmission
     */
    static void ReportDlPhyTransmissionCallback(Ptr<MmWavePhyTrace> phyStats,
                                                PhyTransmissionTraceParams param);

    /**
     * Sets the filename of the PHY reception traces
     * \param fileName the file name
     */
    void SetPhyRxOutputFilename(std::string fileName);

    /**
     * Sets the filename of the UL PHY tranmission traces
     * \param fileName the file name
     */
    void SetUlPhyTxOutputFilename(std::string fileName);

    /**
     * Sets the filename of the DL PHY tranmission traces
     * \param fileName the file name
     */
    void SetDlPhyTxOutputFilename(std::string fileName);

  private:
    // void ReportInterferenceTrace (uint64_t imsi, SpectrumValue& sinr);
    // void ReportDLTbSize (uint64_t imsi, uint64_t tbSize);
    static std::ofstream m_rxPacketTraceFile;   //!< Output stream for the PHY reception trace
    static std::string m_rxPacketTraceFilename; //!< Output filename for the PHY reception trace

    static std::ofstream m_ulPhyTraceFile;   //!< Output stream for the UL PHY transmission trace
    static std::string m_ulPhyTraceFilename; //!< Output filename for the UL PHY transmission trace

    static std::ofstream m_dlPhyTraceFile;   //!< Output stream for the DL PHY transmission trace
    static std::string m_dlPhyTraceFilename; //!< Output filename for the DL PHY transmission trace
};

} // namespace mmwave

} /* namespace ns3 */

#endif /* SRC_MMWAVE_HELPER_MMWAVE_PHY_RX_TRACE_H_ */
