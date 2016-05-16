#include "mc-stats-calculator.h"
#include "ns3/string.h"
#include "ns3/nstime.h"
#include <ns3/log.h>
#include <vector>
#include <algorithm>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("McStatsCalculator");

NS_OBJECT_ENSURE_REGISTERED ( McStatsCalculator);

McStatsCalculator::McStatsCalculator ()
  : m_lteOutputFilename ("LteSwitchStats.txt"),
    m_mmWaveOutputFilename ("MmWaveSwitchStats.txt"),
    m_cellInTimeFilename ("CellIdStats.txt")
{
  NS_LOG_FUNCTION (this);
}

McStatsCalculator::~McStatsCalculator ()
{
  NS_LOG_FUNCTION (this);
  if(m_mmWaveOutFile.is_open())
  {
    m_mmWaveOutFile.close();
  }
  if(m_lteOutFile.is_open())
  {
    m_lteOutFile.close();
  }
  if(m_cellInTimeOutFile.is_open())
  {
    m_cellInTimeOutFile.close();
  }
}

TypeId
McStatsCalculator::GetTypeId (void)
{
  static TypeId tid =
    TypeId ("ns3::McStatsCalculator") 
    .SetParent<Object> ()
    .AddConstructor<McStatsCalculator> ()
    .SetGroupName("Lte")
    .AddAttribute ("LteOutputFilename",
                   "Name of the file where the LTE Switch will be saved.",
                   StringValue ("LteSwitchStats.txt"),
                   MakeStringAccessor (&McStatsCalculator::SetLteOutputFilename),
                   MakeStringChecker ())
    .AddAttribute ("MmWaveOutputFilename",
                   "Name of the file where the MmWave Switch will be saved.",
                   StringValue ("MmWaveSwitchStats.txt"),
                   MakeStringAccessor (&McStatsCalculator::SetMmWaveOutputFilename),
                   MakeStringChecker ())
    .AddAttribute ("CellIdInTimeOutputFilename",
                   "Name of the file where the MmWave Switch will be saved.",
                   StringValue ("CellIdStats.txt"),
                   MakeStringAccessor (&McStatsCalculator::SetCellIdInTimeOutputFilename),
                   MakeStringChecker ())
  ;
  return tid;
}

void
McStatsCalculator::DoDispose ()
{
  NS_LOG_FUNCTION (this);
}

void 
McStatsCalculator::SetLteOutputFilename (std::string outputFilename)
{
  m_lteOutputFilename = outputFilename;
  NS_LOG_UNCOND("m_lteOutputFilename " << m_lteOutputFilename);
}

void
McStatsCalculator::SetMmWaveOutputFilename (std::string outputFilename)
{
  m_mmWaveOutputFilename = outputFilename;
}

std::string
McStatsCalculator::GetLteOutputFilename() 
{
  return m_lteOutputFilename;
}

std::string
McStatsCalculator::GetMmWaveOutputFilename () 
{
  return m_mmWaveOutputFilename;
}

void
McStatsCalculator::SetCellIdInTimeOutputFilename (std::string outputFilename)
{
  m_cellInTimeFilename = outputFilename;
}

std::string
McStatsCalculator::GetCellIdInTimeOutputFilename() 
{
  return m_cellInTimeFilename;
}

void
McStatsCalculator::SwitchToLte (uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << "SwitchToLte" << cellId << imsi << rnti);

  if (!m_lteOutFile.is_open ())
  {
  	m_lteOutFile.open (GetLteOutputFilename ().c_str ());
  }

  m_lteOutFile << "SwitchToLte " << Simulator::Now ().GetNanoSeconds () / 1.0e9 << " " << imsi << " " << cellId << " " << rnti << " " << std::endl;

  if(!m_cellInTimeOutFile.is_open())
  {
    m_cellInTimeOutFile.open (GetCellIdInTimeOutputFilename().c_str());
  }
  m_cellInTimeOutFile << Simulator::Now ().GetNanoSeconds () / 1.0e9 << " " << imsi << " " << cellId << " " << rnti << " " << std::endl;
}

void
McStatsCalculator::SwitchToMmWave (uint64_t imsi, uint16_t cellId, uint16_t rnti)
{
  NS_LOG_FUNCTION (this << "SwitchToMmWave " << cellId << imsi << rnti);

  if (!m_mmWaveOutFile.is_open ())
  {
    m_mmWaveOutFile.open (GetMmWaveOutputFilename ().c_str ());
  }

  m_mmWaveOutFile << "SwitchToMmWave " << Simulator::Now ().GetNanoSeconds () / 1.0e9 << " " << imsi << " " << cellId << " " << rnti << " " << std::endl;

  if(!m_cellInTimeOutFile.is_open())
  {
    m_cellInTimeOutFile.open (GetCellIdInTimeOutputFilename().c_str());
  }
  m_cellInTimeOutFile << Simulator::Now ().GetNanoSeconds () / 1.0e9 << " " << imsi << " " << cellId << " " << rnti << " " << std::endl;
}

} // namespace ns3
