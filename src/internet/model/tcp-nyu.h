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

#ifndef TCPNYU_H
#define TCPNYU_H

#include "ns3/tcp-congestion-ops.h"
#include "ns3/traced-value.h"
#include "ns3/data-rate.h"
#include "ns3/random-variable-stream.h"
#include "ns3/windowed-filter.h"

class TcpNyuCheckGainValuesTest;

namespace ns3 {

class TcpNyu : public TcpCongestionOps
{
public:
  /**
   * \brief The number of phases in the NYU ProbeBW gain cycle.
   */
  static const uint8_t GAIN_CYCLE_LENGTH = 10;

  /**
   * \brief NYU uses an eight-phase cycle with the given pacing_gain value
   * in the NYU ProbeBW gain cycle.
   */
  const static double PACING_GAIN_CYCLE [];
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);

  /**
   * \brief Constructor
   */
  TcpNyu ();

  /**
   * Copy constructor.
   * \param sock The socket to copy from.
   */
  TcpNyu (const TcpNyu &sock);

  /* NYU has the following modes for deciding how fast to send: */
  typedef enum
  {
    NYU_STARTUP,        /* ramp up sending rate rapidly to fill pipe */
    NYU_DRAIN,          /* drain any queue created during startup */
    NYU_PROBE_BW,       /* discover, share bw: pace around estimated bw */
    NYU_PROBE_RTT,      /* cut inflight to min to probe min_rtt */
  } NyuMode_t;

  typedef WindowedFilter<DataRate,
                         MaxFilter<DataRate>,
                         uint32_t,
                         uint32_t>
  MaxBandwidthFilter_t;

  virtual std::string GetName () const;
  virtual bool HasCongControl () const;
  virtual void CongControl (Ptr<TcpSocketState> tcb, const struct RateSample *rs);
  virtual void CongestionStateSet (Ptr<TcpSocketState> tcb,
                                   const TcpSocketState::TcpCongState_t newState);
  virtual void CwndEvent (Ptr<TcpSocketState> tcb,
                          const TcpSocketState::TcpCAEvent_t event);
  virtual uint32_t GetSsThresh (Ptr<const TcpSocketState> tcb,
                                uint32_t bytesInFlight);
  virtual Ptr<TcpCongestionOps> Fork ();

protected:
  /**
   * \brief TcpNyuCheckGainValuesTest friend class (for tests).
   * \relates TcpNyuCheckGainValuesTest
   */
  friend class TcpNyuCheckGainValuesTest;

  /**
   * \brief Advances pacing gain using cycle gain algorithm, while in NYU_PROBE_BW state
   */
  void AdvanceCyclePhase ();

  /**
   * \brief Checks whether to advance pacing gain in NYU_PROBE_BW state,
   *  and if allowed calls AdvanceCyclePhase ()
   * \param tcb the socket state.
   * \param rs  rate sample
   */
  void CheckCyclePhase (Ptr<TcpSocketState> tcb, const struct RateSample * rs);

  /**
   * \brief Checks whether its time to enter NYU_DRAIN or NYU_PROBE_BW state
   * \param tcb the socket state.
   */
  void CheckDrain (Ptr<TcpSocketState> tcb);

  /**
   * \brief Identifies whether pipe or BDP is already full
   * \param rs  rate sample
   */
  void CheckFullPipe (const struct RateSample * rs);

  /**
   * \brief Updates variables specific to NYU_DRAIN state
   */
  void EnterDrain ();

  /**
   * \brief Updates variables specific to NYU_PROBE_BW state
   */
  void EnterProbeBW ();

  /**
   * \brief Updates variables specific to NYU_STARTUP state
   */
  void EnterStartup ();

  /**
   * \brief Gets NYU state.
   * \return returns NYU state.
   */
  uint32_t GetNyuState ();

  /**
   * \brief Gets current pacing gain.
   * \return returns current pacing gain.
   */
  double GetPacingGain ();

  /**
   * \brief Gets current cwnd gain.
   * \return returns current cwnd gain.
   */
  double GetCwndGain ();

  /**
   * \brief Updates pacing rate if socket is restarting from idle state.
   * \param tcb the socket state.
   * \param rs  rate sample
   */
  void HandleRestartFromIdle (Ptr<TcpSocketState> tcb, const struct RateSample * rs);

  /**
   * \brief Estimates the target value for congestion window
   * \param tcb  the socket state.
   * \param gain cwnd gain
   */
  uint32_t InFlight (Ptr<TcpSocketState> tcb, double gain);

  /**
   * \brief Intializes the full pipe estimator.
   */
  void InitFullPipe ();

  /**
   * \brief Intializes the pacing rate.
   * \param tcb  the socket state.
   */
  void InitPacingRate (Ptr<TcpSocketState> tcb);

  /**
   * \brief Intializes the round counting related variables.
   */
  void InitRoundCounting ();

  /**
   * \brief Checks whether to move to next value of pacing gain while in NYU_PROBE_BW.
   * \param tcb the socket state.
   * \param rs  rate sample
   * \returns true if want to move to next value otherwise false.
   */
  bool IsNextCyclePhase (Ptr<TcpSocketState> tcb, const struct RateSample * rs);

  /**
   * \brief Modulates congestion window in CA_RECOVERY.
   * \param tcb the socket state.
   * \param rs  rate sample
   */
  void ModulateCwndForRecovery (Ptr<TcpSocketState> tcb, const struct RateSample * rs);

  /**
   * \brief Helper to restore the last-known good congestion window
   * \param tcb the socket state.
   */
  void RestoreCwnd (Ptr<TcpSocketState> tcb);

  /**
   * \brief Helper to remember the last-known good congestion window or
   *        the latest congestion window unmodulated by loss recovery or ProbeRTT.
   * \param tcb the socket state.
   */
  void SaveCwnd (Ptr<const TcpSocketState> tcb);

  /**
   * \brief Updates congestion window based on the network model.
   * \param tcb the socket state.
   * \param rs  rate sample
   */
  void SetCwnd (Ptr<TcpSocketState> tcb, const struct RateSample * rs);

  /**
   * \brief Updates pacing rate based on network model.
   * \param tcb the socket state.
   * \param gain pacing gain
   */
  void SetPacingRate (Ptr<TcpSocketState> tcb, double gain);

  /**
   * \brief Updates maximum bottleneck.
   * \param tcb the socket state.
   * \param rs rate sample
   */
  void UpdateBtlBw (Ptr<TcpSocketState> tcb, const struct RateSample * rs);

  /**
   * \brief Updates control parameters congestion windowm, pacing rate, send quantum.
   * \param tcb the socket state.
   * \param rs rate sample
   */
  void UpdateControlParameters (Ptr<TcpSocketState> tcb, const struct RateSample * rs);

  /**
   * \brief Updates NYU network model (Maximum bandwidth and minimum RTT).
   * \param tcb the socket state.
   * \param rs rate sample
   */
  void UpdateModelAndState (Ptr<TcpSocketState> tcb, const struct RateSample * rs);

  /**
   * \brief Updates round counting related variables.
   * \param tcb the socket state.
   * \param rs rate sample
   */
  void UpdateRound (Ptr<TcpSocketState> tcb, const struct RateSample * rs);

  /**
   * \brief Updates minimum RTT.
   * \param tcb the socket state.
   */
  void UpdateRTprop (Ptr<TcpSocketState> tcb);

  /**
   * \brief Updates target congestion window.
   * \param tcb the socket state.
   */
  void UpdateTargetCwnd (Ptr<TcpSocketState> tcb);

  /**
   * \brief Sets NYU state.
   * \param state NYU state.
   */
  void SetNyuState (NyuMode_t state);

  /**
   * \brief Maps mode into string.
   * \return string translation of mode value.
   */
  std::string WhichState (NyuMode_t state) const;

private:
  NyuMode_t   m_state        {NyuMode_t::NYU_STARTUP};           //!< Current state of NYU state machine
  MaxBandwidthFilter_t   m_maxBwFilter;                          //!< Maximum bandwidth filter
  uint32_t    m_bandwidthWindowLength       {0};                 //!< A constant specifying the length of the NYU.BtlBw max filter window, default 10 packet-timed round trips.
  double      m_pacingGain                  {0};                 //!< The dynamic pacing gain factor
  double      m_cWndGain                    {0};                 //!< The dynamic congestion window gain factor
  double      m_highGain                    {0};                 //!< A constant specifying highest gain factor, default is 2.89
  bool        m_isPipeFilled                {false};             //!< A boolean that records whether NYU has filled the pipe
  uint32_t    m_minPipeCwnd                 {0};                 //!< The minimal congestion window value NYU tries to target, default 4 Segment size
  uint32_t    m_roundCount                  {0};                 //!< Count of packet-timed round trips
  bool        m_roundStart                  {false};             //!< A boolean that NYU sets to true once per packet-timed round trip
  uint32_t    m_nextRoundDelivered          {0};                 //!< Denotes the end of a packet-timed round trip
  Time        m_probeRttDuration            {MilliSeconds (200)};//!< A constant specifying the minimum duration for which ProbeRTT state, default 200 millisecs
  Time        m_probeRtPropStamp            {Seconds (0)};       //!< The wall clock time at which the current NYU.RTProp sample was obtained.
  Time        m_probeRttDoneStamp           {Seconds (0)};       //!< Time to exit from NYU_PROBE_RTT state
  bool        m_probeRttRoundDone           {false};             //!< True when it is time to exit NYU_PROBE_RTT
  bool        m_packetConservation          {false};             //!<
  uint32_t    m_priorCwnd                   {0};                 //!< The last-known good congestion window
  bool        m_idleRestart                 {false};             //!< When restarting from idle, set it true
  uint32_t    m_targetCWnd                  {0};                 //!< Target value for congestion window, adapted to the estimated BDP
  DataRate    m_fullBandwidth               {0};                 //!< Value of full bandwidth recorded
  uint32_t    m_fullBandwidthCount          {0};                 //!< Count of full bandwidth recorded consistently
  Time        m_rtProp                      {Time::Max ()};      //!< Estimated two-way round-trip propagation delay of the path, estimated from the windowed minimum recent round-trip delay sample.
  uint32_t    m_sendQuantum                 {0};                 //!< The maximum size of a data aggregate scheduled and transmitted together
  Time        m_cycleStamp                  {Seconds (0)};       //!< Last time gain cycle updated
  uint32_t    m_cycleIndex                  {0};                 //!< Current index of gain cycle
  bool        m_rtPropExpired               {false};             //!< A boolean recording whether the NYU.RTprop has expired
  Time        m_rtPropFilterLen             {Seconds (10)};      //!< A constant specifying the length of the RTProp min filter window, default 10 secs.
  Time        m_rtPropStamp                 {Seconds (0)};       //!< The wall clock time at which the current NYU.RTProp sample was obtained
  bool        m_isInitialized               {false};             //!< Set to true after first time initializtion variables
  std::vector<Time> m_rttSamples;
  std::vector<DataRate> m_bwSamples;
  DataRate    m_sendRate                    {0};                 //!< Sending data rate
  uint32_t    m_preTimestamp                {0};                 //previous timestamp
  bool        m_lowEfficiency               {false};
  uint32_t    m_preRttMin                   {0};                 //RTT milliseconds
  double      m_min                         {0.5};
  double      m_max                         {1.1};

  std::vector<uint32_t>    m_rttList;
  std::vector<uint64_t>    m_bwList;




};

} // namespace ns3
#endif // TCPNYU_H
