/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2018 NITK Surathkal
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors: Vivek Jain <jain.vivek.anand@gmail.com>
 *          Viyom Mittal <viyommittal@gmail.com>
 *          Mohit P. Tahiliani <tahiliani@nitk.edu.in>
 */

#include "tcp-nyu.h"
#include "ns3/log.h"
#include "ns3/tcp-socket-base.h"
#include "tcp-option-ts.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("TcpNyu");
NS_OBJECT_ENSURE_REGISTERED (TcpNyu);

//const double TcpNyu::PACING_GAIN_CYCLE [] = {0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1.0, 1.05};

TypeId
TcpNyu::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::TcpNyu")
    .SetParent<TcpCongestionOps> ()
    .AddConstructor<TcpNyu> ()
    .SetGroupName ("Internet")
    .AddAttribute ("HighGain",
                   "Value of high gain",
                   DoubleValue (2.89),
                   MakeDoubleAccessor (&TcpNyu::m_highGain),
                   MakeDoubleChecker<double> ())
    .AddAttribute ("BwWindowLength",
                   "Length of bandwidth windowed filter",
                   UintegerValue (GAIN_CYCLE_LENGTH+2),
                   MakeUintegerAccessor (&TcpNyu::m_bandwidthWindowLength),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("RttWindowLength",
                   "Length of bandwidth windowed filter",
                   TimeValue (Seconds (100)),
                   MakeTimeAccessor (&TcpNyu::m_rtPropFilterLen),
                   MakeTimeChecker ())
    .AddAttribute ("ProbeRttDuration",
                   "Length of bandwidth windowed filter",
                   TimeValue (MilliSeconds (200)),
                   MakeTimeAccessor (&TcpNyu::m_probeRttDuration),
                   MakeTimeChecker ())
  ;
  return tid;
}

TcpNyu::TcpNyu ()
  : TcpCongestionOps ()
{
  NS_LOG_FUNCTION (this);
}

TcpNyu::TcpNyu (const TcpNyu &sock)
  : TcpCongestionOps (sock),
    m_bandwidthWindowLength (sock.m_bandwidthWindowLength),
    m_pacingGain (sock.m_pacingGain),
    m_cWndGain (sock.m_cWndGain),
    m_highGain (sock.m_highGain),
    m_isPipeFilled (sock.m_isPipeFilled),
    m_minPipeCwnd (sock.m_minPipeCwnd),
    m_roundCount (sock.m_roundCount),
    m_roundStart (sock.m_roundStart),
    m_nextRoundDelivered (sock.m_nextRoundDelivered),
    m_probeRttDuration (sock.m_probeRttDuration),
    m_probeRtPropStamp (sock.m_probeRtPropStamp),
    m_probeRttDoneStamp (sock.m_probeRttDoneStamp),
    m_probeRttRoundDone (sock.m_probeRttRoundDone),
    m_packetConservation (sock.m_packetConservation),
    m_priorCwnd (sock.m_priorCwnd),
    m_idleRestart (sock.m_idleRestart),
    m_targetCWnd (sock.m_targetCWnd),
    m_fullBandwidth (sock.m_fullBandwidth),
    m_fullBandwidthCount (sock.m_fullBandwidthCount),
    m_rtProp (Time::Max ()),
    m_sendQuantum (sock.m_sendQuantum),
    m_cycleStamp (sock.m_cycleStamp),
    m_cycleIndex (sock.m_cycleIndex),
    m_rtPropExpired (sock.m_rtPropExpired),
    m_rtPropFilterLen (sock.m_rtPropFilterLen),
    m_rtPropStamp (sock.m_rtPropStamp),
    m_isInitialized (sock.m_isInitialized)
{
  NS_LOG_FUNCTION (this);
}


void
TcpNyu::InitRoundCounting ()
{
  NS_LOG_FUNCTION (this);
  m_nextRoundDelivered = 0;
  m_roundStart = false;
  m_roundCount = 0;
}

void
TcpNyu::InitFullPipe ()
{
  NS_LOG_FUNCTION (this);
  m_isPipeFilled = false;
  m_fullBandwidth = 0;
  m_fullBandwidthCount = 0;
}

void
TcpNyu::InitPacingRate (Ptr<TcpSocketState> tcb)
{
  NS_LOG_FUNCTION (this << tcb);

  if (!tcb->m_pacing)
    {
      NS_LOG_WARN ("NYU must use pacing");
      tcb->m_pacing = true;
    }
  Time rtt = tcb->m_lastRtt != Time::Max () ? tcb->m_lastRtt.Get () : MilliSeconds (1);
  DataRate nominalBandwidth (tcb->m_initialCWnd * tcb->m_segmentSize * 8 / rtt.GetSeconds ());
  tcb->m_currentPacingRate = DataRate (m_pacingGain * nominalBandwidth.GetBitRate ());

  for(uint8_t ind = 0; ind < GAIN_CYCLE_LENGTH; ind++)
  {
    m_rttList.push_back(0);
    m_bwList.push_back(0);
  }
  std::cout << m_rttList.size()<<"\n";
}

void
TcpNyu::EnterStartup ()
{
  NS_LOG_FUNCTION (this);
  SetNyuState (NyuMode_t::NYU_STARTUP);
  m_pacingGain = m_highGain;
  m_cWndGain = m_highGain;
}

void
TcpNyu::HandleRestartFromIdle (Ptr<TcpSocketState> tcb, const RateSample * rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  if (tcb->m_bytesInFlight.Get () == 0U && rs->m_isAppLimited)
    {
      m_idleRestart = true;
      if (m_state == NyuMode_t::NYU_PROBE_BW)
        {
          SetPacingRate (tcb, 1);
        }
    }
}

void
TcpNyu::SetPacingRate (Ptr<TcpSocketState> tcb, double gain)
{
  NS_LOG_FUNCTION (this << tcb << gain);
  DataRate rate (gain * m_maxBwFilter.GetBest ().GetBitRate ());
  /*if(m_sendRate == DataRate(0) || m_state!=NYU_PROBE_BW)
  {
  }
  else
  {
    rate = DataRate (gain * m_sendRate.GetBitRate ());
  }*/

  rate = std::min (rate, tcb->m_maxPacingRate);
  if (m_isPipeFilled || rate > tcb->m_currentPacingRate)
    {
      tcb->m_currentPacingRate = rate;
    }

    if( tcb->m_bytesInFlight != 0)
    {

    FILE* log_file;

    char* fname = (char*)malloc(sizeof(char) * 255);

    memset(fname, 0, sizeof(char) * 255);
    std::string temp;


    int pointer = reinterpret_cast<size_t>(this);

    temp = "rate"+std::to_string(pointer)+".txt";
    //temp = "rate.txt";

    log_file = fopen(temp.c_str(), "a");

    fprintf(log_file, "%f \t  %llu \t %u \n", Now().GetSeconds(), tcb->m_currentPacingRate.GetBitRate(), m_cycleIndex);

    fflush(log_file);

    fclose(log_file);

    if(fname)

    free(fname);

    fname = 0; 
    }

}

uint32_t
TcpNyu::InFlight (Ptr<TcpSocketState> tcb, double gain)
{
  NS_LOG_FUNCTION (this << tcb << gain);
  if (m_rtProp == Time::Max ())
    {
      return tcb->m_initialCWnd * tcb->m_segmentSize;
    }
  double quanta = 3 * m_sendQuantum;
  double estimatedBdp = m_maxBwFilter.GetBest () * m_rtProp / 8.0;
  return gain * estimatedBdp + quanta;
}

void
TcpNyu::AdvanceCyclePhase ()
{
  NS_LOG_FUNCTION (this);
  m_cycleStamp = Simulator::Now ();
  m_cycleIndex = (m_cycleIndex + 1) % GAIN_CYCLE_LENGTH;
  //m_pacingGain = m_min + (m_max-m_min)*m_cycleIndex/(GAIN_CYCLE_LENGTH-1);

  double factor = (double)m_cycleIndex/(GAIN_CYCLE_LENGTH-1) - 0.5; 
  //m_pacingGain = 0.8+2.4* std::pow(factor, 3);    //0.5 - 1.1
  //m_pacingGain = 0.9+1.6* std::pow(factor, 3);    //0.7 - 1.1
  m_pacingGain = 0.7+3.2* std::pow(factor, 3);    //0.3 - 1.1


  /*if(Now().GetSeconds() > 15 && Now().GetSeconds() < 25)
  {
    if(m_pacingGain > 0.69 && m_pacingGain < 0.91)
    {
       m_pacingGain = 0.8;
    }
  }
  else if(Now().GetSeconds() > 25 )
  {
    if(m_pacingGain > 0.51 && m_pacingGain < 1.04)
    {
       m_pacingGain = 0.8;
    }
  }*/
   /* if(m_pacingGain > 0.51 && m_pacingGain < 1.04)
    {
       m_pacingGain = 0.8;
    }*/

  if(!m_rttSamples.empty())
  {
    uint32_t minRtt = m_rttSamples.at(0).GetMicroSeconds();
    uint32_t aveRtt = m_rttSamples.at(0).GetMicroSeconds();
    uint32_t maxRtt = m_rttSamples.at(0).GetMicroSeconds();

    for (uint32_t ind = 1; ind < m_rttSamples.size(); ind++)
    {
      aveRtt += m_rttSamples.at(ind).GetMicroSeconds();
      if(minRtt > m_rttSamples.at(ind).GetMicroSeconds())
      {
        minRtt = m_rttSamples.at(ind).GetMicroSeconds();
      }
      if(maxRtt < m_rttSamples.at(ind).GetMicroSeconds())
      {
        maxRtt = m_rttSamples.at(ind).GetMicroSeconds();
      }

    }
    aveRtt = aveRtt/m_rttSamples.size();
    //std::cout << Now().GetSeconds() << " phase:" << m_cycleIndex << " Gain:" << m_pacingGain << " minRTT:" << minRtt<< " aveRTT:" <<aveRtt << "\n";
    m_rttSamples.clear();

    uint64_t aveBW  = 0;
    for (uint32_t ind = 0; ind < m_bwSamples.size(); ind++)
    {
      aveBW += m_bwSamples.at(ind).GetBitRate();

    }
    aveBW = aveBW/m_bwSamples.size();
    m_bwSamples.clear();
    //std::cout << Now().GetSeconds() << " phase:" << m_cycleIndex << " BW:" << aveBW << "\n";
   m_rttList.at(m_cycleIndex) = minRtt;
   m_bwList.at(m_cycleIndex) = aveBW;


    if(m_cycleIndex == GAIN_CYCLE_LENGTH-1)
    {
      uint32_t maxTime  =  m_rttList.at(0);
      uint32_t minTime  =  m_rttList.at(0);

      uint64_t maxRate = m_bwList.at(0);
      for(uint8_t ind = 0; ind < GAIN_CYCLE_LENGTH; ind++)
      {
        if(maxTime < m_rttList.at(ind))
        {
          maxTime = m_rttList.at(ind);
        }
        if(minTime > m_rttList.at(ind))
        {
          minTime = m_rttList.at(ind);
        }
        if(maxRate < m_bwList.at(ind))
        {
          maxRate = m_bwList.at(ind);
        }
      }

      if(minTime != 0)
      {
          //std::cout << maxTime << "  " << minTime << "  " << maxRate << "\n";
                double sumXY = 0;
                double sumX = 0;
                double sumY = 0;
                double sumSqX = 0;
          for(uint8_t ind = 0; ind < GAIN_CYCLE_LENGTH; ind++)
          { 
            double xData = (double)m_bwList.at(ind)/maxRate;
            double yData = (double)m_rttList.at(ind)/maxTime;
            sumXY += xData * yData;
            sumX += xData;
            sumY += yData;
            sumSqX += xData*xData;
          }
          double slope = (GAIN_CYCLE_LENGTH*sumXY-sumX*sumY)/(GAIN_CYCLE_LENGTH*sumSqX - sumX*sumX);
          std::cout <<this << " time:"<< Now().GetSeconds() <<" slope:"<< slope << "\n";

      }

      std::fill(m_rttList.begin(), m_rttList.end(), 0);
      std::fill(m_bwList.begin(), m_bwList.end(), 0);

    }



  }


  /*if(!m_rttSamples.empty() && !m_bwSamples.empty())
  {
    uint32_t minRtt = m_rttSamples.at(0).GetMilliSeconds();
    uint32_t aveRtt = 0;
    for (uint32_t ind = 0; ind < m_rttSamples.size(); ind++)
    {
      aveRtt += m_rttSamples.at(ind).GetMilliSeconds();
      if(m_rttSamples.at(ind).GetMilliSeconds() < minRtt)
      {
        minRtt = m_rttSamples.at(ind).GetMilliSeconds();
      }
    }
    aveRtt = aveRtt/m_rttSamples.size();

    std::cout << Now().GetSeconds() <<"minRTT" << minRtt<< " aveRTT" <<aveRtt << "\n";

    m_rttSamples.clear();

    double maxBW = m_bwSamples.at(0).GetBitRate();
    double minBW = m_bwSamples.at(0).GetBitRate();
    double aveBW = 0;
    for (uint32_t ind = 0; ind < m_bwSamples.size(); ind++)
    {
      aveBW += m_bwSamples.at(ind).GetBitRate();
      if(m_bwSamples.at(ind).GetBitRate() > maxBW)
      {
        maxBW = m_bwSamples.at(ind).GetBitRate();
      }
      if(m_bwSamples.at(ind).GetBitRate() < minBW)
      {
        minBW = m_bwSamples.at(ind).GetBitRate();
      }
    }
    aveBW = aveBW/m_bwSamples.size();

    std::cout << Now().GetSeconds() <<"  maxBW: " << maxBW<< "  aveBW: " <<aveBW << "  minBW: " <<minBW<< "\n";

    if(minRtt > m_preRttMin)
    {
      if(m_preRttMin != 0)
      {
        //m_sendRate = maxBW*m_preRttMin/minRtt;
        m_sendRate = 2*maxBW*m_preRttMin/minRtt-maxBW;
        //m_sendRate = minBW;
      }
    }
    else
    {
      if(m_lowEfficiency)
      {
        m_sendRate = maxBW;
        m_lowEfficiency = false;
      }
      else
      {
        m_sendRate = maxBW;
      }
    }

    m_bwSamples.clear();

    m_preRttMin = minRtt;
  }*/

}

bool
TcpNyu::IsNextCyclePhase (Ptr<TcpSocketState> tcb, const struct RateSample * rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  bool isFullLength = (Simulator::Now () - m_cycleStamp) > std::max(m_rtProp, MilliSeconds(10));
  return isFullLength;
}

void
TcpNyu::CheckCyclePhase (Ptr<TcpSocketState> tcb, const struct RateSample * rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  if (m_state == NyuMode_t::NYU_PROBE_BW && IsNextCyclePhase (tcb, rs))
    {
      AdvanceCyclePhase ();
    }
}

void
TcpNyu::CheckFullPipe (const struct RateSample * rs)
{
  NS_LOG_FUNCTION (this << rs);
  if (m_isPipeFilled || !m_roundStart || rs->m_isAppLimited)
    {
      return;
    }

  /* Check if Bottleneck bandwidth is still growing*/
  if (m_maxBwFilter.GetBest ().GetBitRate () >= m_fullBandwidth.GetBitRate () * 1.25)
    {
      m_fullBandwidth = m_maxBwFilter.GetBest ();
      m_fullBandwidthCount = 0;
      return;
    }

  m_fullBandwidthCount++;
  if (m_fullBandwidthCount >= 3)
    {
      NS_LOG_DEBUG ("Pipe filled");
      m_isPipeFilled = true;
    }
}

void
TcpNyu::EnterDrain ()
{
  NS_LOG_FUNCTION (this);
  SetNyuState (NyuMode_t::NYU_DRAIN);
  m_pacingGain = 1.0 / m_highGain;
  m_cWndGain = m_highGain;
}

void
TcpNyu::EnterProbeBW ()
{
  NS_LOG_FUNCTION (this);
  SetNyuState (NyuMode_t::NYU_PROBE_BW);
  m_pacingGain = 1;
  m_cWndGain = 10;
  AdvanceCyclePhase ();
}

void
TcpNyu::CheckDrain (Ptr<TcpSocketState> tcb)
{
  NS_LOG_FUNCTION (this << tcb);
  if (m_state == NyuMode_t::NYU_STARTUP && m_isPipeFilled)
    {
      EnterDrain ();
    }

  if (m_state == NyuMode_t::NYU_DRAIN && tcb->m_bytesInFlight <= InFlight (tcb, 1))
    {
      EnterProbeBW ();
    }
}

void
TcpNyu::UpdateRTprop (Ptr<TcpSocketState> tcb)
{
  NS_LOG_FUNCTION (this << tcb);
  m_rtPropExpired = Simulator::Now () > (m_rtPropStamp + m_rtPropFilterLen);

  if(tcb->m_lastRtt !=Time::Max () && m_state == NyuMode_t::NYU_PROBE_BW)
  {
    m_rttSamples.push_back(tcb->m_lastRtt);
  }
  if (tcb->m_lastRtt >= Seconds (0) && (tcb->m_lastRtt <= m_rtProp || m_rtPropExpired))
    {
      m_rtProp = tcb->m_lastRtt;
      m_rtPropStamp = Simulator::Now ();
    }

    if(tcb->m_rcvTimestampValue - m_preTimestamp > 1)
    {
      m_lowEfficiency = true;
    }

    m_preTimestamp = tcb->m_rcvTimestampValue;

    if( tcb->m_bytesInFlight != 0)
    {

    FILE* log_file;

    char* fname = (char*)malloc(sizeof(char) * 255);

    memset(fname, 0, sizeof(char) * 255);
    std::string temp;


    int pointer = reinterpret_cast<size_t>(this);

    temp = "rtt"+std::to_string(pointer)+".txt";
    //temp = "rate.txt";

    log_file = fopen(temp.c_str(), "a");

    fprintf(log_file, "%f \t  %f \t %u\n", Now().GetSeconds(), tcb->m_lastRtt.Get().GetSeconds(), m_cycleIndex);

    fflush(log_file);

    fclose(log_file);

    if(fname)

    free(fname);

    fname = 0; 
    }

}


void
TcpNyu::SaveCwnd (Ptr<const TcpSocketState> tcb)
{
  NS_LOG_FUNCTION (this << tcb);
  if (tcb->m_congState != TcpSocketState::CA_RECOVERY && m_state != NyuMode_t::NYU_PROBE_RTT)
    {
      m_priorCwnd = tcb->m_cWnd;
    }
  else
    {
      m_priorCwnd = std::max (m_priorCwnd, tcb->m_cWnd.Get ());
    }
}

void
TcpNyu::RestoreCwnd (Ptr<TcpSocketState> tcb)
{
  NS_LOG_FUNCTION (this << tcb);
  tcb->m_cWnd = std::max (m_priorCwnd, tcb->m_cWnd.Get ());
}


void
TcpNyu::UpdateTargetCwnd (Ptr<TcpSocketState> tcb)
{
  NS_LOG_FUNCTION (this << tcb);
  m_targetCWnd = InFlight (tcb, m_cWndGain);
}

void
TcpNyu::ModulateCwndForRecovery (Ptr<TcpSocketState> tcb, const struct RateSample * rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  if ( rs->m_packetLoss > 0)
    {
      //tcb->m_cWnd = std::max (tcb->m_cWnd.Get () - rs->m_packetLoss, tcb->m_segmentSize);
      tcb->m_cWnd = std::max ((int)tcb->m_cWnd.Get () - (int)rs->m_packetLoss, (int)tcb->m_segmentSize);
    }

  if (m_packetConservation)
    {
      tcb->m_cWnd = std::max (tcb->m_cWnd.Get (), tcb->m_bytesInFlight.Get () + tcb->m_lastAckedSackedBytes);
    }
}

void
TcpNyu::SetCwnd (Ptr<TcpSocketState> tcb, const struct RateSample * rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  UpdateTargetCwnd (tcb);

  if (tcb->m_congState == TcpSocketState::CA_RECOVERY)
    {
      ModulateCwndForRecovery (tcb, rs);
    }

  if (!m_packetConservation)
    {
      if (m_isPipeFilled)
        {
          tcb->m_cWnd = std::min (tcb->m_cWnd.Get () + (uint32_t) tcb->m_lastAckedSackedBytes, m_targetCWnd);
        }
      else if (tcb->m_cWnd < m_targetCWnd || tcb->m_delivered < tcb->m_initialCWnd * tcb->m_segmentSize)
        {
          tcb->m_cWnd = tcb->m_cWnd.Get () + tcb->m_lastAckedSackedBytes;
        }
      tcb->m_cWnd = std::max (tcb->m_cWnd.Get (), m_minPipeCwnd);
    }
  if (tcb->m_congState == TcpSocketState::CA_RECOVERY)
    {
      m_packetConservation = false;
    }
}

void
TcpNyu::UpdateRound (Ptr<TcpSocketState> tcb, const struct RateSample * rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  if (tcb->m_txItemDelivered >= m_nextRoundDelivered)
    {
      m_nextRoundDelivered = tcb->m_delivered;
      m_roundCount++;
      m_roundStart = true;
    }
  else
    {
      m_roundStart = false;
    }
}

void
TcpNyu::UpdateBtlBw (Ptr<TcpSocketState> tcb, const struct RateSample * rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  if (rs->m_deliveryRate == 0)
    {
      return;
    }

  UpdateRound (tcb, rs);

  if(m_state == NyuMode_t::NYU_PROBE_BW)
  {
    m_bwSamples.push_back(rs->m_deliveryRate);
  }

  if (rs->m_deliveryRate >= m_maxBwFilter.GetBest () || !rs->m_isAppLimited)
  {
    m_maxBwFilter.Update (rs->m_deliveryRate, m_roundCount);
  }

  if( tcb->m_bytesInFlight != 0)
    {

    FILE* log_file;

    char* fname = (char*)malloc(sizeof(char) * 255);

    memset(fname, 0, sizeof(char) * 255);
    std::string temp;


    int pointer = reinterpret_cast<size_t>(this);

    temp = "est"+std::to_string(pointer)+".txt";
    //temp = "rate.txt";

    log_file = fopen(temp.c_str(), "a");

    fprintf(log_file, "%f \t  %llu \t %u \n", Now().GetSeconds(), rs->m_deliveryRate.GetBitRate(), m_cycleIndex);

    fflush(log_file);

    fclose(log_file);

    if(fname)

    free(fname);

    fname = 0; 
    }

}

void
TcpNyu::UpdateModelAndState (Ptr<TcpSocketState> tcb, const struct RateSample * rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  UpdateBtlBw (tcb, rs);
  CheckCyclePhase (tcb, rs);
  CheckFullPipe (rs);
  CheckDrain (tcb);
  UpdateRTprop (tcb);
}

void
TcpNyu::UpdateControlParameters (Ptr<TcpSocketState> tcb, const struct RateSample * rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  SetPacingRate (tcb, m_pacingGain);
  SetCwnd (tcb, rs);
}

std::string
TcpNyu::WhichState (NyuMode_t mode) const
{
  switch (mode)
    {
    case 0:
      return "NYU_STARTUP";
    case 1:
      return "NYU_DRAIN";
    case 2:
      return "NYU_PROBE_BW";
    case 3:
      return "NYU_PROBE_RTT";
    }
  NS_ASSERT (false);
}

void
TcpNyu::SetNyuState (NyuMode_t mode)
{
  NS_LOG_FUNCTION (this << mode);
  NS_LOG_DEBUG (Simulator::Now () << " Changing from " << WhichState (m_state) << " to " << WhichState (mode));
  m_state = mode;
}

uint32_t
TcpNyu::GetNyuState ()
{
  NS_LOG_FUNCTION (this);
  return m_state;
}

double
TcpNyu::GetCwndGain ()
{
  NS_LOG_FUNCTION (this);
  return m_cWndGain;
}

double
TcpNyu::GetPacingGain ()
{
  NS_LOG_FUNCTION (this);
  return m_pacingGain;
}

std::string
TcpNyu::GetName () const
{
  return "TcpNyu";
}

bool
TcpNyu::HasCongControl () const
{
  NS_LOG_FUNCTION (this);
  return true;
}

void
TcpNyu::CongControl (Ptr<TcpSocketState> tcb, const struct RateSample *rs)
{
  NS_LOG_FUNCTION (this << tcb << rs);
  UpdateModelAndState (tcb, rs);
  UpdateControlParameters (tcb, rs);


    if( tcb->m_bytesInFlight != 0)
    {

    FILE* log_file;

    char* fname = (char*)malloc(sizeof(char) * 255);

    memset(fname, 0, sizeof(char) * 255);
    std::string temp;
        int pointer = reinterpret_cast<size_t>(this);

    temp = "ack"+std::to_string(pointer)+".txt";
    //temp = "ack.txt";

    log_file = fopen(temp.c_str(), "a");

    fprintf(log_file, "%f \t  %d \n", Now().GetSeconds(), m_cycleIndex);

    fflush(log_file);

    fclose(log_file);

    if(fname)

    free(fname);

    fname = 0; 
  }
}

void
TcpNyu::CongestionStateSet (Ptr<TcpSocketState> tcb,
                            const TcpSocketState::TcpCongState_t newState)
{
  NS_LOG_FUNCTION (this << tcb << newState);
  if (newState == TcpSocketState::CA_OPEN && !m_isInitialized)
    {
      NS_LOG_DEBUG ("CongestionStateSet triggered to CA_OPEN :: " << newState);
      m_rtProp = tcb->m_lastRtt.Get () != Time::Max () ? tcb->m_lastRtt.Get () : Time::Max ();
      m_rtPropStamp = Simulator::Now ();
      m_priorCwnd = tcb->m_initialCWnd * tcb->m_segmentSize;
      m_targetCWnd = tcb->m_initialCWnd * tcb->m_segmentSize;
      m_minPipeCwnd = 4 * tcb->m_segmentSize;
      m_sendQuantum = 1 * tcb->m_segmentSize;
      m_maxBwFilter = MaxBandwidthFilter_t (m_bandwidthWindowLength,
                                            DataRate (tcb->m_initialCWnd * tcb->m_segmentSize * 8 / m_rtProp.GetSeconds ())
                                            , 0);
      InitRoundCounting ();
      InitFullPipe ();
      EnterStartup ();
      InitPacingRate (tcb);
      m_isInitialized = true;
    }
  else if (newState == TcpSocketState::CA_LOSS)
    {
      NS_LOG_DEBUG ("CongestionStateSet triggered to CA_LOSS :: " << newState);
      SaveCwnd (tcb);
      m_roundStart = true;
    }
  else if (newState == TcpSocketState::CA_RECOVERY)
    {
      NS_LOG_DEBUG ("CongestionStateSet triggered to CA_RECOVERY :: " << newState);
      SaveCwnd (tcb);
      tcb->m_cWnd = tcb->m_bytesInFlight.Get () + std::max (tcb->m_lastAckedSackedBytes, tcb->m_segmentSize);
      m_packetConservation = true;
    }
}

void
TcpNyu::CwndEvent (Ptr<TcpSocketState> tcb,
                   const TcpSocketState::TcpCAEvent_t event)
{
  NS_LOG_FUNCTION (this << tcb << event);
  if (event == TcpSocketState::CA_EVENT_COMPLETE_CWR)
    {
      NS_LOG_DEBUG ("CwndEvent triggered to CA_EVENT_COMPLETE_CWR :: " << event);
      m_packetConservation = false;
      RestoreCwnd (tcb);
    }
  else if (event == TcpSocketState::CA_EVENT_TX_START)
    {
      NS_LOG_DEBUG ("CwndEvent triggered to CA_EVENT_TX_START :: " << event);
      if (tcb->m_bytesInFlight.Get () == 0 && tcb->m_appLimited)
        {
          m_idleRestart = true;
          if (m_state == NyuMode_t::NYU_PROBE_BW && tcb->m_appLimited)
            {
              SetPacingRate (tcb, 1);
            }
        }
    }
}

uint32_t
TcpNyu::GetSsThresh (Ptr<const TcpSocketState> tcb, uint32_t bytesInFlight)
{
  NS_LOG_FUNCTION (this << tcb << bytesInFlight);
  SaveCwnd (tcb);
  return tcb->m_initialSsThresh;
}

Ptr<TcpCongestionOps>
TcpNyu::Fork (void)
{
  return CopyObject<TcpNyu> (this);
}

} // namespace ns3
