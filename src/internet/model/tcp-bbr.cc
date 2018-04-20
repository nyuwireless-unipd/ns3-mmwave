/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2017 WPI, Verizon
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
 */

// System includes.
#include <iostream>

// NS includes.
#include "ns3/log.h"
#include "ns3/simulator.h"
#include "tcp-socket-base.h"          // For pacing configuration options.

// BBR' includes.
#include "rtt-estimator.h"
#include "tcp-bbr.h"

using namespace ns3;

// Logging components. 
NS_LOG_COMPONENT_DEFINE("TcpBbr");
NS_OBJECT_ENSURE_REGISTERED(TcpBbr);

// Default constructor.
TcpBbr::TcpBbr(void) :
  TcpCongestionOps(),
  m_pacing_gain(0.0),
  m_cwnd_gain(0.0),
  m_round(0),
  m_delivered(0),
  m_next_round_delivered(0),
  m_bytes_in_flight(0),
  m_min_rtt_change(Time(0)),
  m_cwnd(0.0),
  m_prior_cwnd(0.0), 
  m_packet_conservation(Time(0)),
  m_in_retrans_seq(false),
  m_retrans_seq(0),
  m_machine(this),
  m_state_startup(this),
  m_state_drain(this),
  m_state_probe_bw(this),
  m_state_probe_rtt(this) {

  NS_LOG_FUNCTION(this);
  NS_LOG_INFO(this << "  BBR' version: v" << bbr::VERSION);

  // Constants in "tcp-bbr.h"
  NS_LOG_INFO(this << "  INIT_RTT: " << bbr::INIT_RTT.GetSeconds() << " sec");
  NS_LOG_INFO(this << "  INIT_BW: " << bbr::INIT_BW << " Mb/s");
  NS_LOG_INFO(this << "  BW_WINDOW_TIME: " << bbr::BW_WINDOW_TIME << " rtts");
  NS_LOG_INFO(this << "  MIN_CWND: " << bbr::MIN_CWND << " bytes");
  NS_LOG_INFO(this << "  STARTUP_THRESHOLD: " << bbr::STARTUP_THRESHOLD);
  NS_LOG_INFO(this << "  STARTUP_GAIN: " << bbr::STARTUP_GAIN);
  NS_LOG_INFO(this << "  STEADY_FACTOR: " << bbr::STEADY_FACTOR);
  NS_LOG_INFO(this << "  PROBE_FACTOR: " << bbr::PROBE_FACTOR);
  NS_LOG_INFO(this << "  DRAIN_FACTOR: " << bbr::DRAIN_FACTOR);
  NS_LOG_INFO(this << "  PACING_FACTOR: " << bbr::PACING_FACTOR);

  // Timing config (used for culling BW window) in "tcp-bbr.h"
  if (bbr::TIME_CONFIG == bbr::WALLCLOCK_TIME) 
    NS_LOG_INFO("TIME_CONFIG: WALLCLOCK_TIME - BW window culling with wallclock time.");
  else if (bbr::TIME_CONFIG == bbr::PACKET_TIME) 
    NS_LOG_INFO("TIME_CONFIG: PACKET_TIME - BW window culling with packet time.");
  else  {
    NS_LOG_INFO("WARNING! Unknown TIME_CONFIG: " << bbr::TIME_CONFIG);
    NS_LOG_INFO("BW window culling with packet time.");
  }

  // Constant in "tcp-socket-base.h"
  if (PACING_CONFIG == NO_PACING) 
    NS_LOG_INFO(this << "  Note: BBR' configured with pacing NO_PACING.");

  // First state is STARTUP.
  m_machine.changeState(&m_state_startup);
}

// Copy constructor.
TcpBbr::TcpBbr(const TcpBbr &sock) :
  TcpCongestionOps(sock),
  m_pacing_gain(0.0),
  m_cwnd_gain(0.0),
  m_round(0),
  m_delivered(0),
  m_next_round_delivered(0),
  m_bytes_in_flight(0),
  m_min_rtt_change(Time(0)),
  m_cwnd(0.0),
  m_prior_cwnd(0.0), 
  m_packet_conservation(Time(0)),
  m_in_retrans_seq(false),
  m_retrans_seq(0),
  m_machine(this),
  m_state_startup(this),
  m_state_drain(this),
  m_state_probe_bw(this),
  m_state_probe_rtt(this) {  
  NS_LOG_FUNCTION("[copy constructor]" << this << &sock);
}

// Default destructor.
TcpBbr::~TcpBbr(void) {
  NS_LOG_FUNCTION(this);
}

// Get type id.
TypeId TcpBbr::GetTypeId(void) {
  static TypeId tid = TypeId("ns3::TcpBbr")
    .SetParent<TcpCongestionOps>()
    .SetGroupName("Internet")
    .AddConstructor<TcpBbr>();
  return tid;
}

// Get name of congestion control algorithm.
std::string TcpBbr::GetName() const {
  NS_LOG_FUNCTION(this);
  return "TcpBbr";
}

// Copy BBR' congestion control algorithm across socket.
Ptr<TcpCongestionOps> TcpBbr::Fork() {
  NS_LOG_FUNCTION(this);
  return CopyObject<TcpBbr> (this);
}

// BBR' ignores calls to increase window.
// tcb = internal congestion state
void TcpBbr::IncreaseWindow(Ptr<TcpSocketState> tcb, uint32_t segs_acked) {
  NS_LOG_FUNCTION(this << tcb << segs_acked);
  NS_LOG_INFO(this << "  Ignored.");
  return;
}

// BBR' does not use ssthresh, so ignored.
// tcb = transmission control block
uint32_t TcpBbr::GetSsThresh(Ptr<const TcpSocketState> tcb,
                             uint32_t b_in_flight) {
  NS_LOG_FUNCTION(this << tcb << b_in_flight);
  NS_LOG_INFO(this << "  Ignored.  Returning max (65535).");
  return 65535;
}

// On receiving ack:
// - update congestion window
// - store RTT
// - compute and store estimated BW
// - compute and set pacing rate
// tcb = transmission control block
void TcpBbr::PktsAcked(Ptr<TcpSocketState> tcb, uint32_t packets_acked,
                       const Time &rtt) {

  NS_LOG_FUNCTION(this << packets_acked << rtt);

  ////////////////////////////////////////////
  // UPDATE TCP CONGESTION WINDOW (CWND)

  uint32_t bytes_delivered = packets_acked * 1500;

  // If in Fast Recovery, target cwnd was set in CongestionStateSet().
  if (tcb->m_congState == TcpSocketState::CA_RECOVERY) {
    // If in first RTT of Fast Recovery, modulate cwnd.
    if (m_packet_conservation > Simulator::Now()) {
      NS_LOG_LOGIC(this << "  Modulating cwnd until: " <<
                  m_packet_conservation.GetSeconds());
      NS_LOG_LOGIC(this << "  m_cwnd: " << m_cwnd <<
                  "  bytes_in_flight: " << m_bytes_in_flight <<
                  "  bytes_delivered: " << bytes_delivered);
      if ((m_bytes_in_flight + bytes_delivered) > m_cwnd)
        m_cwnd = m_bytes_in_flight + bytes_delivered;
    }
  } else {
    // Not in Fast Recovery, so re-compute target cwnd.
    updateTargetCwnd();
  }

  // If growing cwnd, do so conservatively.
  if (tcb -> m_cWnd < m_cwnd) {
    NS_LOG_LOGIC(this << "  Increasing cwnd by: " << bytes_delivered);
    tcb -> m_cWnd = tcb -> m_cWnd + bytes_delivered;
  } else
    // If shrinking cwnd, adjust immediately.
    tcb -> m_cWnd = (uint32_t) m_cwnd;

  ////////////////////////////////////////////
  // STORE RTT
  if (rtt.IsZero() || rtt.IsNegative()) {
    NS_LOG_WARN("RTT measured is zero (or less)! Not stored.");
    return;
  }

  // See if changed minimum RTT (to decide when to PROBE_RTT).
  Time now = Simulator::Now();
  Time min_rtt = getRTT();
  if (rtt < getRTT()) {
    NS_LOG_LOGIC(this << "  New min RTT: " << 
                rtt << " sec (was: " << min_rtt.GetSeconds() << ")");
    m_min_rtt_change = now;  
  }

  // Add to RTT window.
  m_rtt_window[now] = rtt;

  // Upon first RTT, call update() to initialize timer.
  if (m_rtt_window.size() == 1) {
    NS_LOG_LOGIC(this << "  First rtt, calling update() to init.");
    m_machine.update();
  }

  ////////////////////////////////////////////
  // BW ESTIMATION
  // Based on [CCYJ17b]:
  // Cheng et al., "Delivery Rate Estimation", IETF Draft, Jul 3, 2017
  //
  //                                (outstanding)
  // TCP Window: (latest ACKed) W_a [W_1 ... W_n] W_s (next sent)
  //
  // Send() 
  //   Record W_a
  //   Record time W_t
  //   Send W_s
  // PktsAcked()
  //   Record time W_t'
  //   Compute BW: bw = (W_s - W_a) / (W_t' - W_t)
  //   Update data structures

  SequenceNumber32 ack = tcb->m_lastAckedSeq;  // W_s
  now = Simulator::Now();                      // W_t'
  bbr::packet_struct packet;

  // Update packet-timed RTT.
  m_delivered += tcb->m_segmentSize;
  packet.delivered = -1;
  for (auto it = m_pkt_window.begin(); it != m_pkt_window.end(); it++) {
    if (it->sent == ack)
      packet = *it;
  }
  if (packet.delivered >= m_next_round_delivered) {
    m_next_round_delivered = m_delivered;
    m_round++;
    NS_LOG_LOGIC(this << " New packet-timed RTT.  Round: " << m_round);
  }

  // See if retransmission sequence should end.
  bool do_est_bw = true;
  if (m_in_retrans_seq) {
    NS_LOG_LOGIC(this << "  In retransmission sequence: " << m_retrans_seq);
    if (ack != m_retrans_seq) {
      m_in_retrans_seq = false;
      NS_LOG_LOGIC(this << "  Retransmission sequence ended: " << ack);
    }
    // Don't estimate BW if in retrans sequence (or just ending_.
    do_est_bw = false; 
  }

  // If ack not in list (or list empty), unknown when sent so ignore.
  // This happens most often during retransmission sequences.
  if (m_pkt_window.size() == 0) {
    NS_LOG_LOGIC(this << " Packet window size is zero.");
    return; // Nothing more to do.
  }
  auto first = m_pkt_window.begin()->sent;
  if (ack < first) {
    NS_LOG_LOGIC(this << " Not found.  Ack: "<< ack <<
                "  Earliest in list: "<< first);
    return;  // Nothing more to do.
  }

  // Find oldest ack in window, <= current.
  packet.sent = 0;
  packet.time = Time(0);
  for (auto it = m_pkt_window.begin(); it != m_pkt_window.end(); it++)
    if (it->sent <= ack && it->sent > packet.sent)
      packet = *it;  // W_a

  // Remove all entries with acks <= current from window.
  for (unsigned int i=0; i < m_pkt_window.size(); )
    if (m_pkt_window[i].sent <= packet.sent) 
      m_pkt_window.erase(m_pkt_window.begin() + i);
    else
      i++;

  // Estimate BW.
  double bw_est = 0.0;
  if (do_est_bw) {

    // Estimate BW: bw = (W_s - W_a) / (W_t' - W_t)
    bw_est = (ack - packet.acked) /
             (now.GetSeconds() - packet.time.GetSeconds());
    bw_est *= 8;          // Convert to b/s.
    bw_est /= 1000000;    // Convert to Mb/s.

    // Add to BW window.
    bbr::bw_struct bw;
    bw.bw_est = bw_est;
    bw.time = now;
    bw.round = m_round;
    m_bw_window.push_back(bw);
  }

  ////////////////////////////////////////////
  // COMPUTE AND SET PACING RATE.
  // Set pacing rate (in Mb/s), adjusted by gain.
  double pacing_rate = getBW() * m_pacing_gain;

  // There may be some advantages to pacing at just under BW.
  // Either way, this is adjustable in header file.
  if (m_pacing_gain == 1)
    pacing_rate *= bbr::PACING_FACTOR;
  
  if (pacing_rate < 0)
    pacing_rate = 0.0;

  if (PACING_CONFIG != NO_PACING) {

    // If in PROBE_RTT, minimize pacing rate since TCP pacing
    // might have built-up queue.
    if (m_machine.getStateType() == bbr::PROBE_RTT_STATE) {
      double probe_rtt_pacing_rate = bbr::MIN_CWND;   // Bytes (B).
      probe_rtt_pacing_rate /=  min_rtt.GetSeconds(); // B/s.
      probe_rtt_pacing_rate *= 8;                     // Convert to b/s.
      probe_rtt_pacing_rate /= 1000000;               // Convert to Mb/s.
      NS_LOG_LOGIC(this << " In PROBE_RTT," <<
                   "  bbr::MIN_CWND: " << bbr::MIN_CWND <<
                   "  min_rtt: " << min_rtt.GetSeconds() << 
                   "  pacing rate: " << pacing_rate << 
                   "  probe_rtt pacing rate: " << probe_rtt_pacing_rate);
      if (probe_rtt_pacing_rate < pacing_rate)
        pacing_rate = probe_rtt_pacing_rate;
    }
    
    // Set rate.
    tcb -> SetPacingRate(pacing_rate);
  }

  ////////////////////////////////////////////
  // Report data.
  NS_LOG_LOGIC(this << 
              " m_round: " << m_round <<
              "  W_s: " << ack <<
              "  W_a: " << packet.acked <<
              "  W_t': " << now.GetSeconds() <<
              "  W_t: " << packet.time.GetSeconds());
  NS_LOG_LOGIC(this << "  byte-diff: " << (ack - packet.acked));
  NS_LOG_LOGIC(this << "  time-diff: " <<
              (now.GetSeconds() - packet.time.GetSeconds()));
  NS_LOG_INFO(this << "  DATA rtt: " << rtt.GetSeconds() << "  " <<
              "pacing-gain " << m_pacing_gain <<  "  " <<
              "pacing-rate " << pacing_rate << " Mb/s  " <<
              "bw: " << bw_est << " Mb/s  " <<
              "m_cwnd: " << m_cwnd << " bytes  " <<
              "tcb->m_cWnd: " << tcb->m_cWnd);
}

// Before sending packet:
// - Record information to estimate BW
// tsb = tcp socket base
// tcb = transmission control block
void TcpBbr::Send(Ptr<TcpSocketBase> tsb, Ptr<TcpSocketState> tcb,
                  SequenceNumber32 seq, bool isRetrans) {

  NS_LOG_FUNCTION(this);

  // Get the bytes in flight (needed for STARTUP/CA_RECOVERY).
  m_bytes_in_flight = tsb -> BytesInFlight();

  // If retransmission, start sequence (PktsAcked() finds end of sequence).
  if (isRetrans) {
    m_in_retrans_seq = true;
    m_retrans_seq = seq;
    NS_LOG_LOGIC(this << "  Starting retrans sequence: " << seq);
  }

  // If not in retrans sequence, record info for BW est (in PktsAcked()).
  if (!m_in_retrans_seq) {

    // Get last sequence number ACKed.
    bbr::packet_struct p;
    p.acked = tcb -> m_lastAckedSeq;
    p.sent = seq;
    p.time = Simulator::Now();
    p.delivered = m_delivered;
    m_pkt_window.push_back(p);
  
    NS_LOG_LOGIC(this << "  Last acked: " << p.acked <<
                " Next sequence: " << p.sent);
  } else {
    NS_LOG_LOGIC(this << "  seq: " << seq <<
                "  In retrans sequence: " << m_retrans_seq);
  }
}

// Return bandwidth (maximum of window, in Mb/s).
// Return -1 if no BW estimates.
double TcpBbr::getBW() const {
  double max_bw = 0;

  NS_LOG_FUNCTION(this);

  if (m_bw_window.size() == 0)

    // Special case if no BW estimates.
    max_bw = -1.0;

  else

    // Find max BW in window.
    for (auto it = m_bw_window.begin(); it != m_bw_window.end(); it++)
      max_bw = std::max(max_bw, it->bw_est);
  
  NS_LOG_INFO(this << "  DATA bws in window: " << m_bw_window.size() <<
              "  max_bw: " << max_bw);

  // Return it.
  return max_bw;
}

// Return round-trip time (min of window, in seconds).
// Return -1 if no RTT estimates.
Time TcpBbr::getRTT() const {
  Time min_rtt = Time::Max();

  NS_LOG_FUNCTION(this);

  if (m_rtt_window.size() == 0)

    // Special case if no RTT estimates.
    min_rtt = Time(-1.0);

  else
    
    // Find minimum RTT in window.
    for (auto it = m_rtt_window.begin(); it != m_rtt_window.end(); it++)
      min_rtt = std::min(min_rtt, it->second);

  NS_LOG_INFO(this << "  DATA rtts in window: " << m_rtt_window.size() <<
              "  min_rtt: " << min_rtt.GetSeconds());

  // Return it.
  return min_rtt;
}

// Return bandwidth-delay product (in Mbits).
double TcpBbr::getBDP() const {
  NS_LOG_FUNCTION(this);
  Time rtt = getRTT();
  if (rtt.IsNegative())
    rtt = bbr::INIT_RTT;
  double bw = getBW();
  if (bw < 0)
    bw = bbr::INIT_BW;
  return (double) (rtt.GetSeconds() * bw);
}

// Remove BW estimates that are too old (greater than 10 RTTs).
void TcpBbr::cullBWwindow() {

  NS_LOG_FUNCTION(this);

  // If no BW estimates, leave window unchanged.
  double bw = getBW();
  if (bw < 0)
    return;

  // If no RTT estimates, leave window unchanged.
  Time rtt = getRTT();
  if (rtt.IsNegative())
    return;

  // Compute time delta, 10 RTTs ago until now.
  Time now = Simulator::Now();
  Time time_delta = now - rtt * bbr::BW_WINDOW_TIME;
  int round_delta = m_round - bbr::BW_WINDOW_TIME;
  
  // Erase any values that are too old.
  auto it = m_bw_window.begin();
  while (it != m_bw_window.end()) {

    // Configured with either WALLCLOCK or PACKET time.
    if (bbr::TIME_CONFIG == bbr::WALLCLOCK_TIME) { // Use wallclock time.
      if (it -> time < time_delta)
        it = m_bw_window.erase(it);
      else
        it++;
    } else {                          // Use packet time.
      if (it -> round < round_delta)
        it = m_bw_window.erase(it);
      else
        it++;
    }

  }

  // Log info.
  int size = m_bw_window.size();
  if (size == 0)
    NS_LOG_LOGIC(this << " BW window empty.");
  else
    NS_LOG_INFO(this << " DATA" <<
               "  m_bw_window_size: " << size <<
                " [" << m_bw_window.begin()->round << ", " <<
                m_bw_window.rbegin()->round << "]" << 
                " [" << m_bw_window.begin()->time.GetSeconds() << ", " <<
                m_bw_window.rbegin()->time.GetSeconds() << "]");
}

// Remove RTT estimates that are too old (greater than 10 seconds).
void TcpBbr::cullRTTwindow() {

  NS_LOG_FUNCTION(this);

  // If no RTT estimates, leave window unchanged.
  Time rtt = getRTT();
  if (rtt.IsNegative())
    return;

  // Compute time delta, 10 seconds ago until now.
  Time now = Simulator::Now();
  Time delta = Time(now - bbr::RTT_WINDOW_TIME * 1000000000.0); // Units are nanoseconds.

  // Erase any values that are too old.
  auto it = m_rtt_window.begin();
  while (it != m_rtt_window.end()) {
    if (it -> first < delta)
      it = m_rtt_window.erase(it);
    else
      it++;
  }
 
  int size = m_rtt_window.size();
  if (size == 0)
    NS_LOG_LOGIC(this << " RTT window empty.");
  else
    NS_LOG_INFO(this << " DATA" <<
                "  m_rtt_window_size: " << size <<
                " [" << m_rtt_window.begin()->first.GetSeconds() << ", " <<
                m_rtt_window.rbegin()->first.GetSeconds() << "]");
}

// Return true if should enter PROBE_RTT state.
bool TcpBbr::checkProbeRTT() {

  NS_LOG_FUNCTION(this);

  // Check if PROBE_BW and min RTT hasn't changed in 10 seconds.
  Time now = Simulator::Now();
  if (m_machine.getStateType() == bbr::PROBE_BW_STATE &&
      (now.GetSeconds() - m_min_rtt_change.GetSeconds()) >
      bbr::RTT_NOCHANGE_LIMIT) {

    NS_LOG_LOGIC(this << "  min RTT last changed: " << m_min_rtt_change.GetSeconds());

    m_min_rtt_change = now;

    return true; // Should enter PROBE_RTT.
  }

  return false; // Should not enter PROBE_RTT.
}

// Events/calculations specific to BBR' congestion state.
// tcb = transmission control block
void TcpBbr::CongestionStateSet(Ptr<TcpSocketState> tcb,
                        const TcpSocketState::TcpCongState_t new_state) {

  NS_LOG_FUNCTION(this << tcb << new_state);
  auto old_state = tcb->m_congState;
  NS_LOG_LOGIC(this << " old_state: " <<
              TcpSocketState::TcpCongStateName[old_state] <<
              ", new_state: " <<
              TcpSocketState::TcpCongStateName[new_state]);
    
  // Enter RTO --> minimal cwnd.
  if (new_state == TcpSocketState::CA_LOSS) {
    NS_LOG_LOGIC(this << " Entering RTO (CA_LOSS)");
    m_prior_cwnd = m_cwnd;
    m_cwnd = 1000; // bytes
    NS_LOG_LOGIC(this << " cwnd: " << m_cwnd);
  }

  // Enter Fast Recovery --> save cwnd.
  // Modulate cwnd for 1 RTT.
  if (new_state == TcpSocketState::CA_RECOVERY) {
    NS_LOG_LOGIC(this << " Entering Fast Recovery (CA_RECOVERY)");
    m_prior_cwnd = m_cwnd;
    m_cwnd = m_bytes_in_flight + 1;
    m_packet_conservation = Simulator::Now() + getRTT(); // Modulate for 1 RTT.
    NS_LOG_LOGIC(this << " m_cwnd: " << m_cwnd <<
                "  prior_cwnd: " << m_prior_cwnd <<
                "  packet_cons: " << m_packet_conservation.GetSeconds());
  }

  // Exit RTO or Fast Recovery --> restore cwnd.
  if ((old_state == TcpSocketState::CA_RECOVERY ||
       old_state == TcpSocketState::CA_LOSS) &&
      (new_state != TcpSocketState::CA_RECOVERY &&
       new_state != TcpSocketState::CA_LOSS)) {
    NS_LOG_LOGIC(this << " Exiting RTO/Fast Recovery (CA_LOSS/CA_RECOVERY)");
    m_packet_conservation = Simulator::Now(); // Stop packet conservation.
    if (m_prior_cwnd > m_cwnd)
      m_cwnd = m_prior_cwnd;
    NS_LOG_LOGIC(this << "  m_cwnd: " << m_cwnd <<
                "  prior_cwnd: " << m_prior_cwnd);
  }
}

// Compute target TCP cwnd (m_cwnd) based on BDP and gain.
void TcpBbr::updateTargetCwnd() {

  NS_LOG_FUNCTION(this);

  double bdp = getBDP();
  if (PACING_CONFIG == NO_PACING)
    // If no pacing, cwnd is used to control pace.
    m_cwnd = bdp * m_pacing_gain;
  else
    // If pacing, cwnd adjusted larger.
    m_cwnd = bdp * m_cwnd_gain;
  m_cwnd = (m_cwnd * 1000000 / 8); // Mbits to bytes.

  // Make sure cwnd not too small (roughly, 4 packets).
  if (m_cwnd < bbr::MIN_CWND) {
    NS_LOG_LOGIC(this << "  m_cwnd (bytes): " << m_cwnd <<
                 "  Boosting to (bytes): " << bbr::MIN_CWND);
    m_cwnd = bbr::MIN_CWND; // In bytes.
  }

  // Log info.
  NS_LOG_INFO(this << "  DATA bdp (Mbits): " << bdp <<
              "  bdp (bytes): " << bdp * 1000000 / 8 <<
              "  m_cwnd (bytes): " << m_cwnd);
}
