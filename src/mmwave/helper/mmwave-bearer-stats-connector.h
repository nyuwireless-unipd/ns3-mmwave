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
 *                Dual Connectivity and Handover functionalities
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                          Integration of Carrier Aggregation
 */

#ifndef MMWAVE_BEARER_STATS_CONNECTOR_H
#define MMWAVE_BEARER_STATS_CONNECTOR_H

#include "mc-stats-calculator.h"

#include "ns3/object.h"
#include <ns3/config.h>
#include <ns3/ptr.h>
#include <ns3/simple-ref-count.h>
#include <ns3/traced-callback.h>

#include <fstream>
#include <map>
#include <set>
#include <string>

namespace ns3
{

namespace mmwave
{

class MmWaveBearerStatsCalculator;

// class McStatsCalculator;

/**
 * \ingroup lte
 *
 * This class is very useful when user needs to collect
 * statistics from PDCD and RLC. It automatically connects
 * MmWaveBearerStatsCalculator to appropriate trace sinks.
 * Usually user do not use this class. All he/she needs to
 * to do is to call: LteHelper::EnablePdcpTraces() and/or
 * LteHelper::EnableRlcTraces().
 */

class MmWaveBearerStatsConnector : public Object
{
  public:
    /// Constructor
    MmWaveBearerStatsConnector();

    /**
     * Class destructor
     */
    virtual ~MmWaveBearerStatsConnector();

    // Inherited from ns3::Object
    /**
     *  Register this type.
     *  \return The object TypeId.
     */
    static TypeId GetTypeId(void);
    void DoDispose();

    /**
     * Enables trace sinks for RLC layer. Usually, this function
     * is called by LteHelper::EnableRlcTraces().
     * \param rlcStats statistics calculator for RLC layer
     */
    void EnableRlcStats(Ptr<MmWaveBearerStatsCalculator> rlcStats);

    /**
     * Enables trace sinks for PDCP layer. Usually, this function
     * is called by LteHelper::EnablePdcpTraces().
     * \param pdcpStats statistics calculator for PDCP layer
     */
    void EnablePdcpStats(Ptr<MmWaveBearerStatsCalculator> pdcpStats);

    void EnableMcStats(Ptr<McStatsCalculator> mcStats);

    /**
     * Connects trace sinks to appropriate trace sources
     */
    void EnsureConnected();

    // trace sinks, to be used with MakeBoundCallback

    /**
     * Function hooked to RandomAccessSuccessful trace source at UE RRC,
     * which is fired upon successful completion of the random access procedure
     * \param c
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    static void NotifyRandomAccessSuccessfulUe(MmWaveBearerStatsConnector* c,
                                               std::string context,
                                               uint64_t imsi,
                                               uint16_t cellid,
                                               uint16_t rnti);

    /**
     * Sink connected source of UE Connection Setup trace. Not used.
     * \param c
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    static void NotifyConnectionSetupUe(MmWaveBearerStatsConnector* c,
                                        std::string context,
                                        uint64_t imsi,
                                        uint16_t cellid,
                                        uint16_t rnti);

    /**
     * Function hooked to ConnectionReconfiguration trace source at UE RRC,
     * which is fired upon RRC connection reconfiguration
     * \param c
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    static void NotifyConnectionReconfigurationUe(MmWaveBearerStatsConnector* c,
                                                  std::string context,
                                                  uint64_t imsi,
                                                  uint16_t cellid,
                                                  uint16_t rnti);

    /**
     * Function hooked to HandoverStart trace source at UE RRC,
     * which is fired upon start of a handover procedure
     * \param c
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     * \param targetCellId
     */
    static void NotifyHandoverStartUe(MmWaveBearerStatsConnector* c,
                                      std::string context,
                                      uint64_t imsi,
                                      uint16_t cellid,
                                      uint16_t rnti,
                                      uint16_t targetCellId);

    /**
     * Function hooked to HandoverStart trace source at UE RRC,
     * which is fired upon successful termination of a handover procedure
     * \param c
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    static void NotifyHandoverEndOkUe(MmWaveBearerStatsConnector* c,
                                      std::string context,
                                      uint64_t imsi,
                                      uint16_t cellid,
                                      uint16_t rnti);

    /**
     * Function hooked to NewUeContext trace source at eNB RRC,
     * which is fired upon creation of a new UE context
     * \param c
     * \param context
     * \param cellid
     * \param rnti
     */
    static void NotifyNewUeContextEnb(MmWaveBearerStatsConnector* c,
                                      std::string context,
                                      uint16_t cellid,
                                      uint16_t rnti);

    /**
     * Function hooked to ConnectionReconfiguration trace source at eNB RRC,
     * which is fired upon RRC connection reconfiguration
     * \param c
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    static void NotifyConnectionReconfigurationEnb(MmWaveBearerStatsConnector* c,
                                                   std::string context,
                                                   uint64_t imsi,
                                                   uint16_t cellid,
                                                   uint16_t rnti);

    /**
     * Function hooked to HandoverStart trace source at eNB RRC,
     * which is fired upon start of a handover procedure
     * \param c
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     * \param targetCellId
     */
    static void NotifyHandoverStartEnb(MmWaveBearerStatsConnector* c,
                                       std::string context,
                                       uint64_t imsi,
                                       uint16_t cellid,
                                       uint16_t rnti,
                                       uint16_t targetCellId);

    /**
     * Function hooked to HandoverEndOk trace source at eNB RRC,
     * which is fired upon successful termination of a handover procedure
     * \param c
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    static void NotifyHandoverEndOkEnb(MmWaveBearerStatsConnector* c,
                                       std::string context,
                                       uint64_t imsi,
                                       uint16_t cellid,
                                       uint16_t rnti);

    // TODO doc
    static void NotifySwitchToMmWaveUe(MmWaveBearerStatsConnector* c,
                                       std::string context,
                                       uint64_t imsi,
                                       uint16_t cellId,
                                       uint16_t rnti);

    static void NotifySecondaryMmWaveEnbAvailable(MmWaveBearerStatsConnector* c,
                                                  std::string context,
                                                  uint64_t imsi,
                                                  uint16_t cellId,
                                                  uint16_t rnti);

    static void NotifyMmWaveSinr(MmWaveBearerStatsConnector* c,
                                 std::string context,
                                 uint64_t imsi,
                                 uint16_t cellId,
                                 long double sinr);
    void PrintMmWaveSinr(uint64_t imsi, uint16_t cellId, long double sinr);
    static void NotifyLteSinr(MmWaveBearerStatsConnector* c,
                              std::string context,
                              uint16_t cellId,
                              uint16_t rnti,
                              double rsrp,
                              double sinr,
                              uint8_t cc);
    void PrintLteSinr(uint16_t rnti, uint16_t cellId, double sinr);

    std::string GetEnbHandoverStartOutputFilename(void);
    std::string GetUeHandoverStartOutputFilename(void);
    std::string GetEnbHandoverEndOutputFilename(void);
    std::string GetUeHandoverEndOutputFilename(void);
    std::string GetCellIdStatsOutputFilename(void);
    std::string GetMmWaveSinrOutputFilename(void);
    std::string GetLteSinrOutputFilename(void);

    void SetEnbHandoverStartOutputFilename(std::string outputFilename);
    void SetUeHandoverStartOutputFilename(std::string outputFilename);
    void SetEnbHandoverEndOutputFilename(std::string outputFilename);
    void SetUeHandoverEndOutputFilename(std::string outputFilename);
    void SetCellIdStatsOutputFilename(std::string outputFilename);
    void SetMmWaveSinrOutputFilename(std::string outputFilename);
    void SetLteSinrOutputFilename(std::string outputFilename);

  private:
    /**
     * Creates UE Manager path and stores it in m_ueManagerPathByCellIdRnti
     * \param ueManagerPath
     * \param cellId
     * \param rnti
     */
    void StoreUeManagerPath(std::string ueManagerPath, uint16_t cellId, uint16_t rnti);

    /**
     * Connects Srb0 trace sources at UE and eNB to RLC and PDCP calculators,
     * and Srb1 trace sources at eNB to RLC and PDCP calculators,
     * \param ueRrcPath
     * \param imsi
     * \param cellId
     * \param rnti
     */
    void ConnectSrb0Traces(std::string ueRrcPath, uint64_t imsi, uint16_t cellId, uint16_t rnti);

    /**
     * Connects all trace sources at UE to RLC and PDCP calculators.
     * This function can connect traces only once for UE.
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    void ConnectTracesUeIfFirstTime(std::string context,
                                    uint64_t imsi,
                                    uint16_t cellid,
                                    uint16_t rnti);

    /**
     * Connects all trace sources at eNB to RLC and PDCP calculators.
     * This function can connect traces only once for eNB.
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    void ConnectTracesEnbIfFirstTime(std::string context,
                                     uint64_t imsi,
                                     uint16_t cellid,
                                     uint16_t rnti);

    /**
     * Connects DRBs trace sources at UE to RLC and PDCP calculators.
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    void ConnectDrbTracesUe(std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti);

    /**
     * Connects SRB1 trace sources at UE to RLC and PDCP calculators
     * \param ueRrcPath
     * \param imsi
     * \param cellId
     * \param rnti
     */
    void ConnectSrb1TracesUe(std::string ueRrcPath, uint64_t imsi, uint16_t cellId, uint16_t rnti);

    /**
     * Disconnects all trace sources at UE to RLC and PDCP calculators.
     * Function is not implemented.
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    void DisconnectTracesUe(std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti);

    /**
     * Disconnects DRB trace sources at UE to RLC and PDCP calculators.
     * Function is not implemented.
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    void DisconnectDrbTracesUe(std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti);

    /**
     * Connects SRB1 trace sources at eNB to RLC and PDCP calculators
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    void ConnectSrb1TracesEnb(std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti);

    /**
     * Connects DRBs trace sources at eNB to RLC and PDCP calculators
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    void ConnectDrbTracesEnb(std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti);

    /**
     * Disconnects all trace sources at eNB to RLC and PDCP calculators.
     * Function is not implemented.
     * \param context
     * \param imsi
     * \param cellid
     * \param rnti
     */
    void DisconnectTracesEnb(std::string context, uint64_t imsi, uint16_t cellid, uint16_t rnti);

    void ConnectSecondaryTracesUe(std::string context,
                                  uint64_t imsi,
                                  uint16_t cellId,
                                  uint16_t rnti);
    void ConnectSecondaryTracesEnb(std::string context,
                                   uint64_t imsi,
                                   uint16_t cellId,
                                   uint16_t rnti);

    void PrintEnbStartHandover(uint64_t imsi,
                               uint16_t sourceCellid,
                               uint16_t targetCellId,
                               uint16_t rnti);
    void PrintEnbEndHandover(uint64_t imsi, uint16_t targetCellId, uint16_t rnti);
    void PrintUeStartHandover(uint64_t imsi,
                              uint16_t sourceCellid,
                              uint16_t targetCellId,
                              uint16_t rnti);
    void PrintUeEndHandover(uint64_t imsi, uint16_t targetCellId, uint16_t rnti);

    Ptr<MmWaveBearerStatsCalculator> m_rlcStats;  //!< Calculator for RLC Statistics
    Ptr<MmWaveBearerStatsCalculator> m_pdcpStats; //!< Calculator for PDCP Statistics
    Ptr<McStatsCalculator> m_mcStats;             //!< Calculator for multi-connectivity Statistics

    std::map<uint64_t, CallbackBase> m_rlcDrbDlRxCb; //!< Sinks for the received DL RLC data packets
    std::map<uint64_t, CallbackBase> m_rlcDrbUlTxCb; //!< Sinks for the sent UL RLC data packets

    std::map<uint64_t, CallbackBase>
        m_pdcpDrbDlRxCb; //!< Sinks for the received DL PDCP data packets
    std::map<uint64_t, CallbackBase> m_pdcpDrbUlTxCb; //!< Sinks for the sent UL PDCP data packets

    bool m_connected; //!< true if traces are connected to sinks, initially set to false
    std::set<uint64_t>
        m_imsiSeenUeSrb; //!< stores all UEs for which RLC and PDCP for SRB1 traces were connected
    std::map<uint64_t, uint16_t>
        m_imsiSeenUeDrb; //!< stores all UEs for which RLC and PDCP traces for DRBs were connected
    std::set<uint64_t>
        m_imsiSeenEnbDrb; //!< stores all eNBs for which RLC and PDCP traces for DRBs were connected

    /**
     * Struct used as key in m_ueManagerPathByCellIdRnti map
     */
    struct CellIdRnti
    {
        uint16_t cellId; //!< cellId
        uint16_t rnti;   //!< rnti
    };

    /**
     * Less than operator for CellIdRnti, because it is used as key in map
     */
    friend bool operator<(const CellIdRnti& a, const CellIdRnti& b);

    /**
     * List UE Manager Paths by CellIdRnti
     */
    std::map<CellIdRnti, std::string> m_ueManagerPathByCellIdRnti;

    std::string m_enbHandoverStartFilename;
    std::string m_enbHandoverEndFilename;
    std::string m_ueHandoverStartFilename;
    std::string m_ueHandoverEndFilename;
    std::string m_cellIdInTimeHandoverFilename;
    std::string m_mmWaveSinrOutputFilename;
    std::string m_lteSinrOutputFilename;

    std::ofstream m_enbHandoverStartOutFile;
    std::ofstream m_ueHandoverStartOutFile;
    std::ofstream m_enbHandoverEndOutFile;
    std::ofstream m_ueHandoverEndOutFile;
    std::ofstream m_cellIdInTimeHandoverOutFile;
    std::ofstream m_mmWaveSinrOutFile;
    std::ofstream m_lteSinrOutFile;
};

} // namespace mmwave

} // namespace ns3

#endif // MMWAVE_BEARER_STATS_CONNECTOR_H
