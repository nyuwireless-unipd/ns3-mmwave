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
 *        	 	  Sourjya Dutta <sdutta@nyu.edu>
 *        	 	  Russell Ford <russell.ford@nyu.edu>
 *        		  Menglei Zhang <menglei@nyu.edu>
 *
 * Modified by: Michele Polese <michele.polese@gmail.com> 
 *                Dual Connectivity and Handover functionalities
 */


#include "mmwave-bearer-stats-calculator.h"
#include "mmwave-bearer-stats-connector.h"

#include <ns3/log.h>
#include <ns3/config.h>

#include "ns3/string.h"
#include "ns3/nstime.h"

#include <ns3/lte-enb-rrc.h>
#include <ns3/lte-enb-net-device.h>
#include <ns3/lte-ue-rrc.h>
#include <ns3/lte-ue-net-device.h>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("MmWaveBearerStatsConnector");
NS_OBJECT_ENSURE_REGISTERED (MmWaveBearerStatsConnector);

/**
  * Less than operator for CellIdRnti, because it is used as key in map
  */
bool
operator < (const MmWaveBearerStatsConnector::CellIdRnti& a, const MmWaveBearerStatsConnector::CellIdRnti& b)
{
  return ( (a.cellId < b.cellId) || ( (a.cellId == b.cellId) && (a.rnti < b.rnti) ) );
}

/**
 * This structure is used as interface between trace
 * sources and MmWaveBearerStatsCalculator. It stores
 * and provides calculators with cellId and IMSI,
 * because most trace sources do not provide it.
 */
struct MmWaveBoundCallbackArgument : public SimpleRefCount<MmWaveBoundCallbackArgument>
{
public:
  Ptr<MmWaveBearerStatsCalculator> stats;  //!< statistics calculator
  uint64_t imsi; //!< imsi
  uint16_t cellId; //!< cellId
};

struct McMmWaveBoundCallbackArgument : public SimpleRefCount<McMmWaveBoundCallbackArgument>
{
public:
  Ptr<McStatsCalculator> stats;
};

/**
 * Callback function for DL TX statistics for both RLC and PDCP
 * /param arg
 * /param path
 * /param rnti
 * /param lcid
 * /param packetSize
 */
void
DlTxPduCallback (Ptr<MmWaveBoundCallbackArgument> arg, std::string path,
                 uint16_t rnti, uint8_t lcid, uint32_t packetSize)
{
  NS_LOG_FUNCTION (path << rnti << (uint16_t)lcid << packetSize);
  arg->stats->DlTxPdu (arg->cellId, arg->imsi, rnti, lcid, packetSize);
}

/**
 * Callback function for DL RX statistics for both RLC and PDCP
 * /param arg
 * /param path
 * /param rnti
 * /param lcid
 * /param packetSize
 * /param delay
 */
void
DlRxPduCallback (Ptr<MmWaveBoundCallbackArgument> arg, std::string path,
                 uint16_t rnti, uint8_t lcid, uint32_t packetSize, uint64_t delay)
{
  NS_LOG_FUNCTION (path << rnti << (uint16_t)lcid << packetSize << delay);
  arg->stats->DlRxPdu (arg->cellId, arg->imsi, rnti, lcid, packetSize, delay);
}

/**
 * Callback function for UL TX statistics for both RLC and PDCP
 * /param arg
 * /param path
 * /param rnti
 * /param lcid
 * /param packetSize
 */
void
UlTxPduCallback (Ptr<MmWaveBoundCallbackArgument> arg, std::string path,
                 uint16_t rnti, uint8_t lcid, uint32_t packetSize)
{
  NS_LOG_FUNCTION (path << rnti << (uint16_t)lcid << packetSize);
 
  arg->stats->UlTxPdu (arg->cellId, arg->imsi, rnti, lcid, packetSize);
}

/**
 * Callback function for UL RX statistics for both RLC and PDCP
 * /param arg
 * /param path
 * /param rnti
 * /param lcid
 * /param packetSize
 * /param delay
 */
void
UlRxPduCallback (Ptr<MmWaveBoundCallbackArgument> arg, std::string path,
                 uint16_t rnti, uint8_t lcid, uint32_t packetSize, uint64_t delay)
{
  NS_LOG_FUNCTION (path << rnti << (uint16_t)lcid << packetSize << delay);
 
  arg->stats->UlRxPdu (arg->cellId, arg->imsi, rnti, lcid, packetSize, delay);
}

void
SwitchToLteCallback (Ptr<McMmWaveBoundCallbackArgument> arg, std::string path, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (path << rnti << cellId << imsi);
 
  arg->stats->SwitchToLte (imsi, cellId, rnti);
}

void
SwitchToMmWaveCallback (Ptr<McMmWaveBoundCallbackArgument> arg, std::string path, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (path << rnti << cellId << imsi);
 
  arg->stats->SwitchToMmWave (imsi, cellId, rnti);
}


MmWaveBearerStatsConnector::MmWaveBearerStatsConnector ()
  : m_connected (false),
    m_enbHandoverStartFilename ("EnbHandoverStartStats.txt"),
    m_enbHandoverEndFilename ("EnbHandoverEndStats.txt"),
    m_ueHandoverStartFilename ("UeHandoverStartStats.txt"),
    m_ueHandoverEndFilename ("UeHandoverEndStats.txt"),
    m_cellIdInTimeHandoverFilename ("CellIdStatsHandover.txt")
{

}

MmWaveBearerStatsConnector::~MmWaveBearerStatsConnector ()
{
  NS_LOG_FUNCTION (this);
  if(m_enbHandoverStartOutFile.is_open())
  {
    m_enbHandoverStartOutFile.close();
  }
  if(m_ueHandoverStartOutFile.is_open())
  {
    m_ueHandoverStartOutFile.close();
  }
  if(m_enbHandoverEndOutFile.is_open())
  {
    m_enbHandoverEndOutFile.close();
  }
  if(m_ueHandoverEndOutFile.is_open())
  {
    m_ueHandoverEndOutFile.close();
  }

  if(m_cellIdInTimeHandoverOutFile.is_open())
  {
    m_cellIdInTimeHandoverOutFile.close();
  }
  if(m_mmWaveSinrOutFile.is_open())
  {
    m_mmWaveSinrOutFile.close();
  }
  if(m_lteSinrOutFile.is_open())
  {
    m_lteSinrOutFile.close();
  }
}

TypeId
MmWaveBearerStatsConnector::GetTypeId (void)
{
  static TypeId tid =
    TypeId ("ns3::MmWaveBearerStatsConnector") 
    .SetParent<Object> ()
    .AddConstructor<MmWaveBearerStatsConnector> ()
    .SetGroupName("Lte")
    .AddAttribute ("EnbHandoverStartOutputFilename",
                   "Name of the file where the eNB handover start traces will be saved.",
                   StringValue ("EnbHandoverStartStats.txt"),
                   MakeStringAccessor (&MmWaveBearerStatsConnector::SetEnbHandoverStartOutputFilename),
                   MakeStringChecker ())
    .AddAttribute ("EnbHandoverEndOutputFilename",
                   "Name of the file where the eNB handover end traces will be saved.",
                   StringValue ("EnbHandoverEndStats.txt"),
                   MakeStringAccessor (&MmWaveBearerStatsConnector::SetEnbHandoverEndOutputFilename),
                   MakeStringChecker ())
    .AddAttribute ("MmWaveSinrOutputFilename",
               "Name of the file where the mmWave eNB sinr will be saved.",
               StringValue ("MmWaveSinrTime.txt"),
               MakeStringAccessor (&MmWaveBearerStatsConnector::SetMmWaveSinrOutputFilename),
               MakeStringChecker ())
    .AddAttribute ("LteSinrOutputFilename",
               "Name of the file where the LTE eNB sinr will be saved.",
               StringValue ("LteSinrTime.txt"),
               MakeStringAccessor (&MmWaveBearerStatsConnector::SetLteSinrOutputFilename),
               MakeStringChecker ())
    .AddAttribute ("UeHandoverStartOutputFilename",
                   "Name of the file where the UE handover start events will be saved.",
                   StringValue ("UeHandoverStartStats.txt"),
                   MakeStringAccessor (&MmWaveBearerStatsConnector::SetUeHandoverStartOutputFilename),
                   MakeStringChecker ())
    .AddAttribute ("UeHandoverEndOutputFilename",
                   "Name of the file where the UE handover end events will be saved.",
                   StringValue ("UeHandoverEndStats.txt"),
                   MakeStringAccessor (&MmWaveBearerStatsConnector::SetUeHandoverEndOutputFilename),
                   MakeStringChecker ())
    .AddAttribute ("CellIdStatsHandoverOutputFilename",
                   "Name of the file where the current cellId for the UE will be stored.",
                   StringValue ("CellIdStatsHandover.txt"),
                   MakeStringAccessor (&MmWaveBearerStatsConnector::SetCellIdStatsOutputFilename),
                   MakeStringChecker ())
  ;
  return tid;
}

void
MmWaveBearerStatsConnector::DoDispose ()
{
  NS_LOG_FUNCTION (this);
}

void 
MmWaveBearerStatsConnector::EnableRlcStats (Ptr<MmWaveBearerStatsCalculator> rlcStats)
{
  m_rlcStats = rlcStats;
  EnsureConnected ();
}

void 
MmWaveBearerStatsConnector::EnablePdcpStats (Ptr<MmWaveBearerStatsCalculator> pdcpStats)
{
  m_pdcpStats = pdcpStats;
  EnsureConnected ();
}

void
MmWaveBearerStatsConnector::EnableMcStats (Ptr<McStatsCalculator> mcStats)
{
  m_mcStats = mcStats;
  EnsureConnected();
}

void 
MmWaveBearerStatsConnector::EnsureConnected ()
{
  NS_LOG_FUNCTION (this);
  if (!m_connected)
    {
      Config::Connect ("/NodeList/*/DeviceList/*/LteEnbRrc/NewUeContext",
		       MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyNewUeContextEnb, this));
      Config::Connect ("/NodeList/*/DeviceList/*/LteUeRrc/RandomAccessSuccessful",
		       MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyRandomAccessSuccessfulUe, this));
      Config::Connect ("/NodeList/*/DeviceList/*/MmWaveUeRrc/RandomAccessSuccessful",
           MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyRandomAccessSuccessfulUe, this));
      Config::Connect ("/NodeList/*/DeviceList/*/LteEnbRrc/ConnectionReconfiguration",
		       MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyConnectionReconfigurationEnb, this));
      Config::Connect ("/NodeList/*/DeviceList/*/LteUeRrc/ConnectionReconfiguration",
		       MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyConnectionReconfigurationUe, this));
      Config::Connect ("/NodeList/*/DeviceList/*/MmWaveUeRrc/ConnectionReconfiguration",
           MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyConnectionReconfigurationUe, this));
      Config::Connect ("/NodeList/*/DeviceList/*/LteEnbRrc/HandoverStart",
		       MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyHandoverStartEnb, this));
      Config::Connect ("/NodeList/*/DeviceList/*/LteUeRrc/HandoverStart",
		       MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyHandoverStartUe, this));
      Config::Connect ("/NodeList/*/DeviceList/*/MmWaveUeRrc/HandoverStart",
           MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyHandoverStartUe, this));
      Config::Connect ("/NodeList/*/DeviceList/*/LteEnbRrc/HandoverEndOk",
		       MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyHandoverEndOkEnb, this));
      Config::Connect ("/NodeList/*/DeviceList/*/LteUeRrc/HandoverEndOk",
		       MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyHandoverEndOkUe, this));
      Config::Connect ("/NodeList/*/DeviceList/*/MmWaveUeRrc/HandoverEndOk",
          MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyHandoverEndOkUe, this));
      Config::Connect ("/NodeList/*/DeviceList/*/LteUeRrc/SwitchToMmWave",
           MakeBoundCallback (&MmWaveBearerStatsConnector::NotifySwitchToMmWaveUe, this));
      // mmWave SINR from RT, LTE SINR from the PHY callbacks
      Config::Connect ("/NodeList/*/DeviceList/*/LteEnbRrc/NotifyMmWaveSinr",
          MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyMmWaveSinr, this));
      Config::Connect ("/NodeList/*/DeviceList/*/LteUePhy/ReportCurrentCellRsrpSinr",
                   MakeBoundCallback (&MmWaveBearerStatsConnector::NotifyLteSinr, this));
      m_connected = true;
    }
}

void 
MmWaveBearerStatsConnector::NotifyRandomAccessSuccessfulUe (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  c->ConnectSrb0Traces (context, imsi, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifyConnectionSetupUe (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  c->ConnectSrb1TracesUe (context, imsi, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifyConnectionReconfigurationUe (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  c->ConnectTracesUeIfFirstTime (context, imsi, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifyHandoverStartUe (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti, uint16_t targetCellId)
{
  c->PrintUeStartHandover(imsi, cellId, targetCellId, rnti);
  c->DisconnectTracesUe (context, imsi, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifyHandoverEndOkUe (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  c->PrintUeEndHandover (imsi, cellId, rnti);
  c->ConnectTracesUe (context, imsi, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifyNewUeContextEnb (MmWaveBearerStatsConnector* c, std::string context, uint16_t cellId, uint16_t rnti)
{
  c->StoreUeManagerPath (context, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifyConnectionReconfigurationEnb (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  c->ConnectTracesEnbIfFirstTime (context, imsi, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifyHandoverStartEnb (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti, uint16_t targetCellId)
{
  c->PrintEnbStartHandover(imsi, cellId, targetCellId, rnti);
  c->DisconnectTracesEnb (context, imsi, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifyHandoverEndOkEnb (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  c->PrintEnbEndHandover (imsi, cellId, rnti);
  c->ConnectTracesEnb (context, imsi, cellId, rnti);
}

void
MmWaveBearerStatsConnector::NotifySwitchToMmWaveUe (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  c->ConnectSecondaryTracesUe (context, imsi, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifySecondaryMmWaveEnbAvailable (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  c->ConnectSecondaryTracesEnb (context, imsi, cellId, rnti);
}

void 
MmWaveBearerStatsConnector::NotifyMmWaveSinr (MmWaveBearerStatsConnector* c, std::string context, uint64_t imsi, uint16_t cellId, long double sinr)
{
  c->PrintMmWaveSinr (imsi, cellId, sinr);
}

void
MmWaveBearerStatsConnector::PrintMmWaveSinr (uint64_t imsi, uint16_t cellId, long double sinr)
{
  NS_LOG_FUNCTION(this << " PrintMmWaveSinr " << Simulator::Now().GetSeconds());
  if(!m_mmWaveSinrOutFile.is_open ())
  {
    m_mmWaveSinrOutFile.open(GetMmWaveSinrOutputFilename() .c_str());
  }
  m_mmWaveSinrOutFile << Simulator::Now().GetNanoSeconds()/1.0e9 << " " << imsi << " " << cellId << " " << 10*std::log10(sinr) << std::endl;
}

void 
MmWaveBearerStatsConnector::NotifyLteSinr (MmWaveBearerStatsConnector* c, std::string context, uint16_t cellId, uint16_t rnti, double rsrp, double sinr, uint8_t cc)
{
  c->PrintLteSinr (rnti, cellId, sinr);
}

void
MmWaveBearerStatsConnector::PrintLteSinr (uint16_t rnti, uint16_t cellId, double sinr)
{
  NS_LOG_FUNCTION(this << " PrintLteSinr " << Simulator::Now().GetSeconds());
  if(!m_lteSinrOutFile.is_open ())
  {
    m_lteSinrOutFile.open(GetLteSinrOutputFilename() .c_str());
  }
  m_lteSinrOutFile << Simulator::Now().GetNanoSeconds()/1.0e9 << " " << rnti << " " << cellId << " " << sinr << std::endl;
}

std::string 
MmWaveBearerStatsConnector::GetEnbHandoverStartOutputFilename (void)
{
  return m_enbHandoverStartFilename;
}

std::string 
MmWaveBearerStatsConnector::GetEnbHandoverEndOutputFilename (void)
{
  return m_enbHandoverEndFilename;
}

std::string 
MmWaveBearerStatsConnector::GetMmWaveSinrOutputFilename (void)
{
  return m_mmWaveSinrOutputFilename;
}

std::string 
MmWaveBearerStatsConnector::GetLteSinrOutputFilename (void)
{
  return m_lteSinrOutputFilename;
}

std::string 
MmWaveBearerStatsConnector::GetUeHandoverStartOutputFilename (void)
{
  return m_ueHandoverStartFilename;
}

std::string 
MmWaveBearerStatsConnector::GetUeHandoverEndOutputFilename (void)
{
  return m_ueHandoverEndFilename;
}

std::string 
MmWaveBearerStatsConnector::GetCellIdStatsOutputFilename (void)
{
  return m_cellIdInTimeHandoverFilename;
}

void MmWaveBearerStatsConnector::SetEnbHandoverEndOutputFilename (std::string outputFilename)
{
  m_enbHandoverEndFilename = outputFilename;
}

void MmWaveBearerStatsConnector::SetEnbHandoverStartOutputFilename (std::string outputFilename)
{
  m_enbHandoverStartFilename = outputFilename;
}

void 
MmWaveBearerStatsConnector::SetUeHandoverStartOutputFilename (std::string outputFilename)
{
  m_ueHandoverStartFilename = outputFilename;
}

void 
MmWaveBearerStatsConnector::SetUeHandoverEndOutputFilename (std::string outputFilename)
{
  m_ueHandoverEndFilename = outputFilename;
}

void
MmWaveBearerStatsConnector::SetCellIdStatsOutputFilename (std::string outputFilename)
{
  m_cellIdInTimeHandoverFilename = outputFilename;
}

void
MmWaveBearerStatsConnector::SetMmWaveSinrOutputFilename (std::string outputFilename)
{
  m_mmWaveSinrOutputFilename = outputFilename;
}

void
MmWaveBearerStatsConnector::SetLteSinrOutputFilename (std::string outputFilename)
{
  m_lteSinrOutputFilename = outputFilename;
}

void 
MmWaveBearerStatsConnector::PrintEnbStartHandover(uint64_t imsi, uint16_t sourceCellid, uint16_t targetCellId, uint16_t rnti)
{
  NS_LOG_FUNCTION(this << " NotifyHandoverStartEnb " << Simulator::Now().GetSeconds());
  if(!m_enbHandoverStartOutFile.is_open ())
  {
    m_enbHandoverStartOutFile.open(GetEnbHandoverStartOutputFilename() .c_str());
  }
  m_enbHandoverStartOutFile << Simulator::Now().GetNanoSeconds()/1.0e9 << " " << imsi << " " << rnti << " " << sourceCellid << " " << targetCellId << std::endl;
}

void 
MmWaveBearerStatsConnector::PrintEnbEndHandover(uint64_t imsi, uint16_t targetCellId, uint16_t rnti)
{
  NS_LOG_FUNCTION("NotifyHandoverOkEnb " << Simulator::Now().GetSeconds());
  if(!m_enbHandoverEndOutFile.is_open ())
  {
    m_enbHandoverEndOutFile.open(GetEnbHandoverEndOutputFilename() .c_str());
  }
  m_enbHandoverEndOutFile << Simulator::Now().GetNanoSeconds()/1.0e9 << " " << imsi << " " << rnti << " " << targetCellId << std::endl;
}

void 
MmWaveBearerStatsConnector::PrintUeStartHandover(uint64_t imsi, uint16_t sourceCellid, uint16_t targetCellId, uint16_t rnti)
{
  NS_LOG_FUNCTION("NotifyHandoverStartUe " << Simulator::Now().GetSeconds());
  if(!m_ueHandoverStartOutFile.is_open ())
  {
    m_ueHandoverStartOutFile.open(GetUeHandoverStartOutputFilename() .c_str());
  }
  m_ueHandoverStartOutFile << Simulator::Now().GetNanoSeconds()/1.0e9 << " " << imsi << " " << rnti << " " << sourceCellid << " " << targetCellId << std::endl;
}

void 
MmWaveBearerStatsConnector::PrintUeEndHandover(uint64_t imsi, uint16_t targetCellId, uint16_t rnti)
{
  NS_LOG_FUNCTION("NotifyHandoverOkUe " << Simulator::Now().GetSeconds());
  if(!m_ueHandoverEndOutFile.is_open ())
  {
    m_ueHandoverEndOutFile.open(GetUeHandoverEndOutputFilename() .c_str());
  }
  m_ueHandoverEndOutFile << Simulator::Now().GetNanoSeconds()/1.0e9 << " " << imsi << " " << rnti << " " << targetCellId << std::endl;

  if(!m_cellIdInTimeHandoverOutFile.is_open ())
  {
    m_cellIdInTimeHandoverOutFile.open(GetCellIdStatsOutputFilename() .c_str());
  }
  m_cellIdInTimeHandoverOutFile << Simulator::Now().GetNanoSeconds()/1.0e9 << " " << imsi << " " << rnti << " " << targetCellId << std::endl;
}

void 
MmWaveBearerStatsConnector::StoreUeManagerPath (std::string context, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << context << cellId << rnti);
  std::ostringstream ueManagerPath;
  ueManagerPath <<  context.substr (0, context.rfind ("/")) << "/UeMap/" << (uint32_t) rnti;
  CellIdRnti key;
  key.cellId = cellId;
  key.rnti = rnti;
  m_ueManagerPathByCellIdRnti[key] = ueManagerPath.str ();
}

void 
MmWaveBearerStatsConnector::ConnectSrb0Traces (std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << imsi << cellId << rnti);
  std::string ueRrcPath =  context.substr (0, context.rfind ("/"));
  CellIdRnti key;
  key.cellId = cellId;
  key.rnti = rnti;
  std::map<CellIdRnti, std::string>::iterator it = m_ueManagerPathByCellIdRnti.find (key);
  NS_ASSERT (it != m_ueManagerPathByCellIdRnti.end ());
  std::string ueManagerPath = it->second;  
  NS_LOG_LOGIC (this << " ueManagerPath: " << ueManagerPath);
  m_ueManagerPathByCellIdRnti.erase (it);

  if (m_rlcStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_rlcStats;

      // diconnect eventually previously connected SRB0 both at UE and eNB
      Config::Disconnect (ueRrcPath + "/Srb0/LteRlc/TxPDU",
                          MakeBoundCallback (&UlTxPduCallback, arg));
      Config::Disconnect (ueRrcPath + "/Srb0/LteRlc/RxPDU",
                          MakeBoundCallback (&DlRxPduCallback, arg));
      Config::Disconnect (ueManagerPath + "/Srb0/LteRlc/TxPDU",
                          MakeBoundCallback (&DlTxPduCallback, arg));
      Config::Disconnect (ueManagerPath + "/Srb0/LteRlc/RxPDU",
                          MakeBoundCallback (&UlRxPduCallback, arg));

      // connect SRB0 both at UE and eNB
      Config::Connect (ueRrcPath + "/Srb0/LteRlc/TxPDU",
                       MakeBoundCallback (&UlTxPduCallback, arg));
      Config::Connect (ueRrcPath + "/Srb0/LteRlc/RxPDU",
                       MakeBoundCallback (&DlRxPduCallback, arg));
      Config::Connect (ueManagerPath + "/Srb0/LteRlc/TxPDU",
                       MakeBoundCallback (&DlTxPduCallback, arg));
      Config::Connect (ueManagerPath + "/Srb0/LteRlc/RxPDU",
                       MakeBoundCallback (&UlRxPduCallback, arg));

      // connect SRB1 at eNB only (at UE SRB1 will be setup later)
      Config::Connect (ueManagerPath + "/Srb1/LteRlc/TxPDU",
                       MakeBoundCallback (&DlTxPduCallback, arg));
      Config::Connect (ueManagerPath + "/Srb1/LteRlc/RxPDU",
                       MakeBoundCallback (&UlRxPduCallback, arg));
      
      Config::Connect (ueManagerPath + "/SecondaryRlcCreated",
                       MakeBoundCallback (&NotifySecondaryMmWaveEnbAvailable, this));

    }
  if (m_pdcpStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_pdcpStats;

      // connect SRB1 at eNB only (at UE SRB1 will be setup later)
      Config::Connect (ueManagerPath + "/Srb1/LtePdcp/RxPDU",
		       MakeBoundCallback (&UlRxPduCallback, arg));
      Config::Connect (ueManagerPath + "/Srb1/LtePdcp/TxPDU",
		       MakeBoundCallback (&DlTxPduCallback, arg));
    }
}

void 
MmWaveBearerStatsConnector::ConnectSrb1TracesUe (std::string ueRrcPath, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << imsi << cellId << rnti);
   if (m_rlcStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_rlcStats;
      Config::Connect (ueRrcPath + "/Srb1/LteRlc/TxPDU",
                       MakeBoundCallback (&UlTxPduCallback, arg));
      Config::Connect (ueRrcPath + "/Srb1/LteRlc/RxPDU",
                       MakeBoundCallback (&DlRxPduCallback, arg));
    }
  if (m_pdcpStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_pdcpStats;
      Config::Connect (ueRrcPath + "/Srb1/LtePdcp/RxPDU",
		       MakeBoundCallback (&DlRxPduCallback, arg));
      Config::Connect (ueRrcPath + "/Srb1/LtePdcp/TxPDU",
		       MakeBoundCallback (&UlTxPduCallback, arg));
    }
}
  
void 
MmWaveBearerStatsConnector::ConnectTracesUeIfFirstTime (std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << context);
  if (m_imsiSeenUe.find (imsi) == m_imsiSeenUe.end ())
    {
      m_imsiSeenUe.insert (imsi);
      ConnectTracesUe (context, imsi, cellId, rnti);
    }
}
 
void 
MmWaveBearerStatsConnector::ConnectTracesEnbIfFirstTime (std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << context);
   if (m_imsiSeenEnb.find (imsi) == m_imsiSeenEnb.end ())
    {
      m_imsiSeenEnb.insert (imsi);
      ConnectTracesEnb (context, imsi, cellId, rnti);
    }
}

void 
MmWaveBearerStatsConnector::ConnectTracesUe (std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << context);
  NS_LOG_LOGIC (this << "expected context should match /NodeList/*/DeviceList/*/LteUeRrc/");
  std::string basePath = context.substr (0, context.rfind ("/"));
  Config::MatchContainer objects = Config::LookupMatches(basePath + "/DataRadioBearerMap/*/LteRlc/");
  NS_LOG_LOGIC("basePath " << basePath);

  if (m_rlcStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_rlcStats;
      Config::Connect (basePath + "/DataRadioBearerMap/*/LteRlc/TxPDU",
		       MakeBoundCallback (&UlTxPduCallback, arg));
      Config::Connect (basePath + "/DataRadioBearerMap/*/LteRlc/RxPDU",
		       MakeBoundCallback (&DlRxPduCallback, arg));
      Config::Connect (basePath + "/Srb1/LteRlc/TxPDU",
		       MakeBoundCallback (&UlTxPduCallback, arg));
      Config::Connect (basePath + "/Srb1/LteRlc/RxPDU",
		       MakeBoundCallback (&DlRxPduCallback, arg));
      // for MC devices
      Config::Disconnect (basePath + "/DataRadioRlcMap/LteRlc/TxPDU",
           MakeBoundCallback (&UlTxPduCallback, arg));
      Config::Disconnect (basePath + "/DataRadioRlcMap/LteRlc/RxPDU",
           MakeBoundCallback (&DlRxPduCallback, arg));
      Config::Connect (basePath + "/DataRadioRlcMap/LteRlc/TxPDU",
           MakeBoundCallback (&UlTxPduCallback, arg));
      Config::Connect (basePath + "/DataRadioRlcMap/LteRlc/RxPDU",
           MakeBoundCallback (&DlRxPduCallback, arg));

    }
  if (m_pdcpStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_pdcpStats;
      Config::Connect (basePath + "/DataRadioBearerMap/*/LtePdcp/RxPDU",
		       MakeBoundCallback (&DlRxPduCallback, arg));
      Config::Connect (basePath + "/DataRadioBearerMap/*/LtePdcp/TxPDU",
		       MakeBoundCallback (&UlTxPduCallback, arg));
      Config::Connect (basePath + "/Srb1/LtePdcp/RxPDU",
		       MakeBoundCallback (&DlRxPduCallback, arg));
      Config::Connect (basePath + "/Srb1/LtePdcp/TxPDU",
		       MakeBoundCallback (&UlTxPduCallback, arg));
    }
  if(m_mcStats)
    {
      Ptr<McMmWaveBoundCallbackArgument> arg = Create<McMmWaveBoundCallbackArgument> ();
      arg->stats = m_mcStats;
      Config::Connect (basePath + "/SwitchToLte",
            MakeBoundCallback (&SwitchToLteCallback, arg));
      Config::Connect (basePath + "/SwitchToMmWave",
            MakeBoundCallback (&SwitchToMmWaveCallback, arg));
    }
}

void 
MmWaveBearerStatsConnector::ConnectTracesEnb (std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << context);
  NS_LOG_LOGIC (this << "expected context  should match /NodeList/*/DeviceList/*/LteEnbRrc/");
  std::ostringstream basePath;
  basePath <<  context.substr (0, context.rfind ("/")) << "/UeMap/" << (uint32_t) rnti;
  if (m_rlcStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_rlcStats;
      Config::Connect (basePath.str () + "/DataRadioBearerMap/*/LteRlc/RxPDU",
		       MakeBoundCallback (&UlRxPduCallback, arg));
      Config::Connect (basePath.str () + "/DataRadioBearerMap/*/LteRlc/TxPDU",
		       MakeBoundCallback (&DlTxPduCallback, arg));
      Config::Connect (basePath.str () + "/Srb0/LteRlc/RxPDU",
		       MakeBoundCallback (&UlRxPduCallback, arg));
      Config::Connect (basePath.str () + "/Srb0/LteRlc/TxPDU",
		       MakeBoundCallback (&DlTxPduCallback, arg));
      Config::Connect (basePath.str () + "/Srb1/LteRlc/RxPDU",
		       MakeBoundCallback (&UlRxPduCallback, arg));
      Config::Connect (basePath.str () + "/Srb1/LteRlc/TxPDU",
		       MakeBoundCallback (&DlTxPduCallback, arg));
    }
  if (m_pdcpStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_pdcpStats;
      Config::Connect (basePath.str () + "/DataRadioBearerMap/*/LtePdcp/TxPDU",
		       MakeBoundCallback (&DlTxPduCallback, arg));
      Config::Connect (basePath.str () + "/DataRadioBearerMap/*/LtePdcp/RxPDU",
		       MakeBoundCallback (&UlRxPduCallback, arg));
      Config::Connect (basePath.str () + "/Srb1/LtePdcp/TxPDU",
		       MakeBoundCallback (&DlTxPduCallback, arg));
      Config::Connect (basePath.str () + "/Srb1/LtePdcp/RxPDU",
		       MakeBoundCallback (&UlRxPduCallback, arg));
    }
}

void 
MmWaveBearerStatsConnector::DisconnectTracesUe (std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << context);
  NS_LOG_LOGIC (this << "expected context should match /NodeList/*/DeviceList/*/LteUeRrc/");
  std::string basePath = context.substr (0, context.rfind ("/"));
  Config::MatchContainer objects = Config::LookupMatches(basePath + "/DataRadioBearerMap/*/LteRlc/");
  NS_LOG_LOGIC("basePath " << basePath);

  if(m_mcStats)
    {
      Ptr<McMmWaveBoundCallbackArgument> arg = Create<McMmWaveBoundCallbackArgument> ();
      arg->stats = m_mcStats;
      Config::Disconnect (basePath + "/SwitchToLte",
          MakeBoundCallback (&SwitchToLteCallback, arg));
      Config::Disconnect (basePath + "/SwitchToMmWave",
          MakeBoundCallback (&SwitchToMmWaveCallback, arg));
  }
}


void 
MmWaveBearerStatsConnector::DisconnectTracesEnb (std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this);
}


void
MmWaveBearerStatsConnector::ConnectSecondaryTracesUe (std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_LOGIC (this << context);
  NS_LOG_LOGIC (this << "expected context should match /NodeList/*/DeviceList/*/LteUeRrc/");
  std::string basePath = context.substr (0, context.rfind ("/"));
  Config::MatchContainer objects = Config::LookupMatches(basePath + "/DataRadioRlcMap/*");
  NS_LOG_LOGIC("basePath " << basePath);

  if (m_rlcStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_rlcStats;
      // for MC devices
      Config::Connect (basePath + "/DataRadioRlcMap/*/TxPDU",
           MakeBoundCallback (&UlTxPduCallback, arg));
      Config::Connect (basePath + "/DataRadioRlcMap/*/RxPDU",
           MakeBoundCallback (&DlRxPduCallback, arg));
    }
}

void
MmWaveBearerStatsConnector::ConnectSecondaryTracesEnb (std::string context, uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << context);
  NS_LOG_LOGIC (this << "expected context should match /NodeList/*/DeviceList/*/LteEnbRrc/UeMap/*");
  std::ostringstream basePath;
  basePath <<  context.substr (0, context.rfind ("/"));
  Config::MatchContainer objects = Config::LookupMatches(basePath.str() + "/DataRadioRlcMap/*/LteRlc/");
  NS_LOG_LOGIC("basePath " << basePath.str());

  if (m_rlcStats)
    {
      Ptr<MmWaveBoundCallbackArgument> arg = Create<MmWaveBoundCallbackArgument> ();
      arg->imsi = imsi;
      arg->cellId = cellId; 
      arg->stats = m_rlcStats;
      // for MC devices
      Config::Connect (basePath.str() + "/DataRadioRlcMap/*/LteRlc/RxPDU",
           MakeBoundCallback (&UlRxPduCallback, arg));
      Config::Connect (basePath.str() + "/DataRadioRlcMap/*/LteRlc/TxPDU",
           MakeBoundCallback (&DlTxPduCallback, arg));
    }
}

} // namespace ns3
