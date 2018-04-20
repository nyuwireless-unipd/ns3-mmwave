//
// BbrState.cpp
//
// State machine and states for TcpBbr.
//

// Include files.
#include "ns3/log.h"
#include "tcp-bbr.h"
#include "tcp-bbr-state.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("BbrState");
NS_OBJECT_ENSURE_REGISTERED(BbrState);

///////////////////////////////////////////////
// BBR' State Machine
// Executes current state through update().
// Changes state through exit() and enter().

// Update state: STARTUP, DRAIN, PROBE_BW, PROBE_RTT.
//
//  State transition diagram:
//          |
//          V
//       STARTUP  
//          |     
//          V     
//        DRAIN   
//          |     
//          V     
// +---> PROBE_BW ----+
// |      ^    |      |
// |      |    |      |
// |      +----+      |
// |                  |
// +---- PROBE_RTT <--+

// Default constructor.
BbrStateMachine::BbrStateMachine() {
  NS_LOG_FUNCTION(this);
  m_owner = NULL;
  m_state = NULL;
}

// Default constructor.
BbrStateMachine::BbrStateMachine(TcpBbr *owner) {
  NS_LOG_FUNCTION(this);
  m_owner = owner;
  m_state = NULL;
}

// Get type id.
TypeId BbrStateMachine::GetTypeId(void) {
  static TypeId tid = TypeId("ns3::BbrStateMachine")
    .SetParent<Object>()
    .SetGroupName("Internet")
    .AddConstructor<BbrStateMachine>();
  return tid;
}

// Get name of object.
std::string BbrStateMachine::GetName() const {
  NS_LOG_FUNCTION(this);
  return "BbrStateMachine";
}

// Get type of current state.
bbr::bbr_state BbrStateMachine::getStateType() const {
  return m_state -> getType();
}

// Update by executing current state.
void BbrStateMachine::update() {
  NS_LOG_FUNCTION(this);

  if (m_state == NULL) {
    NS_LOG_INFO(this << " m_state NULL. Probably flow terminated, so ok.");
    return;
  }

  NS_LOG_LOGIC(this << "  State: " << m_state -> GetName());

  // Check if should enter PROBE_RTT.
  if (m_owner -> checkProbeRTT())
    changeState(&m_owner -> m_state_probe_rtt);

  // Execute current state.
  m_state -> execute();

  // Cull RTT window.
  m_owner -> cullRTTwindow();

  // Cull BW window (except in DRAIN state).
  m_owner -> cullBWwindow();

  // Schedule next event (if we can).
  Time rtt = m_owner -> getRTT();
  if (!rtt.IsNegative()) {
    Simulator::Schedule(rtt, &BbrStateMachine::update, this);
    NS_LOG_LOGIC(this << "  Next event: " << rtt.GetSeconds());
  } else // update() will be called in PktsAcked() upon getting first rtt.
    NS_LOG_LOGIC(this << "  Not scheduling next event.");
}

// Change current state to new state.
void BbrStateMachine::changeState(BbrState *new_state) {
  NS_LOG_FUNCTION(this);
  NS_ASSERT(new_state != NULL);
  if (m_state)
    NS_LOG_LOGIC(this <<
		"  Old: " << m_state -> GetName() <<
		"  New: " << new_state -> GetName());
  else
    NS_LOG_LOGIC(this << " Initial state: " << new_state -> GetName());

  // Call exit on old state.
  if (m_state)
    m_state -> exit();

  // Change to new state.
  m_state = new_state;

  // Call enter on new state.
  m_state -> enter();
}

///////////////////////////////////////////////
// BBR' State

BbrState::BbrState(TcpBbr *owner) {
  m_owner = owner;
}

BbrState::BbrState() {
  m_owner = NULL;
}

BbrState::~BbrState() {
}

// Get type id.
TypeId BbrState::GetTypeId(void) {
  static TypeId tid = TypeId("ns3::BbrState")
    .SetParent<BbrStateMachine>()
    .SetGroupName("Internet");
  return tid;
}

// Get name of object.
std::string BbrState::GetName() const {
  return "BbrState";
}

// Invoked when state first entered.
void BbrState::enter() {
}

// Invoked when state exited.
void BbrState::exit() {
}

///////////////////////////////////////////////
// BBR' STARTUP
  
BbrStartupState::BbrStartupState(TcpBbr *owner) : BbrState(owner),
  m_full_bw(0),
  m_full_bw_count(0) {
  NS_LOG_FUNCTION(this);
}

BbrStartupState::BbrStartupState() : BbrState(),
  m_full_bw(0),
  m_full_bw_count(0) {
  NS_LOG_FUNCTION(this);
}

// Get type id.
TypeId BbrStartupState::GetTypeId(void) {
  static TypeId tid = TypeId("ns3::BbrStartupState")
    .SetParent<BbrStateMachine>()
    .SetGroupName("Internet")
    .AddConstructor<BbrStartupState>();
  return tid;
}

// Get name of object.
std::string BbrStartupState::GetName() const {
  return "BbrStartupState";
}

// Get state type.
bbr::bbr_state BbrStartupState::getType(void) const {
  return bbr::STARTUP_STATE;
}

// Invoked when state first entered.
void BbrStartupState::enter() {
  NS_LOG_FUNCTION(this);
  NS_LOG_INFO(this << " State: " << GetName());

  // Set gains to 2/ln(2).
  m_owner -> m_pacing_gain = bbr::STARTUP_GAIN;
  m_owner -> m_cwnd_gain = bbr::STARTUP_GAIN;
}

// Invoked when state updated.
void BbrStartupState::execute() {
  NS_LOG_FUNCTION(this);
  NS_LOG_LOGIC(this << " State: " << GetName());

  double new_bw = m_owner -> getBW();

  // If no legitimate estimates yet, no more to do.
  if (new_bw < 0) {
    NS_LOG_LOGIC(this << "  No BW estimates yet.");
    return;
  }
  
  // Still growing?
  if (new_bw > m_full_bw * bbr::STARTUP_THRESHOLD) { 
    NS_LOG_LOGIC(this << "  Still growing. old_bw: " << m_full_bw << "  new_bw: " << new_bw);
    m_full_bw = new_bw;
    m_full_bw_count = 0;
    return;
  }

  // Another round w/o much growth.
  m_full_bw_count++;
  NS_LOG_LOGIC(this << "  Growth stalled. old_bw: " << m_full_bw << "  new_bw: " << new_bw << "  full-bw-count: " << m_full_bw_count);
  
  // If 3+ rounds w/out much growth, STARTUP --> DRAIN.
  if (m_full_bw_count > 2) {
    NS_LOG_LOGIC(this << "  Exiting STARTUP, next state DRAIN");
    m_owner -> m_machine.changeState(&m_owner -> m_state_drain);
  }

  return;
}

///////////////////////////////////////////////
// BBR' DRAIN
  
BbrDrainState::BbrDrainState(TcpBbr *owner) :
  BbrState(owner),
  m_inflight_limit(0),
  m_round_count(0) {
  NS_LOG_FUNCTION(this);
}

BbrDrainState::BbrDrainState() :
  BbrState(),
  m_inflight_limit(0),
  m_round_count(0) {
  NS_LOG_FUNCTION(this);
}

// Get type id.
TypeId BbrDrainState::GetTypeId(void) {
  static TypeId tid = TypeId("ns3::BbrDrainState")
    .SetParent<BbrStateMachine>()
    .SetGroupName("Internet")
    .AddConstructor<BbrDrainState>();
  return tid;
}

// Get name of object.
std::string BbrDrainState::GetName() const {
  return "BbrDrainState";
}

// Get state type.
bbr::bbr_state BbrDrainState::getType(void) const {
  return bbr::DRAIN_STATE;
}

// Invoked when state first entered.
void BbrDrainState::enter() {
  NS_LOG_FUNCTION(this);
  NS_LOG_INFO(this << " State: " << GetName());

  // Set pacing gain to 1/[2/ln(2)].
  m_owner -> m_pacing_gain = 1 / bbr::STARTUP_GAIN;

  // Maintain high cwnd gain.
  if (PACING_CONFIG == NO_PACING)
    m_owner -> m_cwnd_gain = 1 / bbr::STARTUP_GAIN; // Slow cwnd if no pacing.
  else
    m_owner -> m_cwnd_gain = bbr::STARTUP_GAIN; // Maintain high cwnd gain.

  // Get BDP for target inflight limit when will exit STARTUUP..
  double bdp = m_owner -> getBDP();
  bdp = bdp * 1000000 / 8; // Convert to bytes.
  m_inflight_limit = (uint32_t) bdp;  
  m_round_count = 0;
}

// Invoked when state updated.
void BbrDrainState::execute() {
  NS_LOG_FUNCTION(this);
  NS_LOG_LOGIC(this << " State: " << GetName());

  NS_LOG_LOGIC(this << " " <<
	      GetName() <<
	      "  round: " << m_round_count <<
	      "  bytes_in_flight: " << m_owner -> m_bytes_in_flight <<
	      "  inflight_limit: " << m_inflight_limit);

  // See if should exit DRAIN state.
  // Do when byte-in-flight are under limit or 5 rounds
  // have passed (2.89/(1-1/2.89) ~ 4.5), whichever is first.
  m_round_count++;
  if (m_owner -> m_bytes_in_flight < m_inflight_limit ||
      m_round_count == 5) {
    NS_LOG_LOGIC(this << " Exiting DRAIN, next state PROBE_BW");
    m_owner -> m_machine.changeState(&m_owner -> m_state_probe_bw);
  }
}

///////////////////////////////////////////////
// BBR' PROBE_BW
  
BbrProbeBWState::BbrProbeBWState(TcpBbr *owner) : BbrState(owner) {
  NS_LOG_FUNCTION(this);
}

BbrProbeBWState::BbrProbeBWState() : BbrState() {
  NS_LOG_FUNCTION(this);
}

// Get type id.
TypeId BbrProbeBWState::GetTypeId(void) {
  static TypeId tid = TypeId("ns3::BbrProbeBWState")
    .SetParent<BbrStateMachine>()
    .SetGroupName("Internet")
    .AddConstructor<BbrProbeBWState>();
  return tid;
}

// Get name of object.
std::string BbrProbeBWState::GetName() const {
  return "BbrProbeBWState";
}

// Get state type.
bbr::bbr_state BbrProbeBWState::getType(void) const {
  return bbr::PROBE_BW_STATE;
}

// Invoked when state first entered.
void BbrProbeBWState::enter() {
  NS_LOG_FUNCTION(this);
  NS_LOG_INFO(this << " State: " << GetName());

  // Pick random start cycle phase (except "low") to avoid synch of
  // flows that enter PROBE_BW simultaneously.
  do {
    m_gain_cycle = rand() % 8;
  } while (m_gain_cycle == 1);  // Phase 1 is "low" cycle.

  NS_LOG_LOGIC(this << " " << GetName() << " Start cycle: " << m_gain_cycle);

  // Set gains based on phase.
  m_owner -> m_pacing_gain = bbr::STEADY_FACTOR;
  if (m_gain_cycle == 0) // Phase 0 is "high" cycle.
    m_owner -> m_pacing_gain += bbr::PROBE_FACTOR;
  if (PACING_CONFIG == NO_PACING)
    m_owner -> m_cwnd_gain = m_owner -> m_pacing_gain;
  else
    m_owner -> m_cwnd_gain = bbr::STEADY_FACTOR * 2;
}

// Invoked when state updated.
void BbrProbeBWState::execute() {
  NS_LOG_FUNCTION(this);
  NS_LOG_LOGIC(this << " " << GetName() << "  m_gain_cycle: " << m_gain_cycle);

  // Set gain rate: [high, low, stdy, stdy, stdy, stdy, stdy, stdy]
  if (m_gain_cycle == 0)
    m_owner -> m_pacing_gain = bbr::STEADY_FACTOR + bbr::PROBE_FACTOR;
  else if (m_gain_cycle == 1)
    if (PACING_CONFIG == NO_PACING) 
      m_owner -> m_pacing_gain = bbr::STEADY_FACTOR - bbr::DRAIN_FACTOR/8;
    else
      m_owner -> m_pacing_gain = bbr::STEADY_FACTOR - bbr::DRAIN_FACTOR;
  else
    m_owner -> m_pacing_gain = bbr::STEADY_FACTOR;

  if (PACING_CONFIG == NO_PACING)
    // If configed for NO_PACING, rate is controlled by cwnd at bdp.
    m_owner -> m_cwnd_gain = m_owner -> m_pacing_gain;
  else
    // Otherwise, cwnd can be twice bdp.
    m_owner -> m_cwnd_gain = 2 * bbr::STEADY_FACTOR;

  // Move to next cycle, wrapping.
  m_gain_cycle++;
  if (m_gain_cycle > 7)
    m_gain_cycle = 0;

  NS_LOG_LOGIC(this << " " <<
	      GetName() << " DATA pacing-gain: " << m_owner -> m_pacing_gain);
}

///////////////////////////////////////////////
// BBR' PROBE_RTT
  
BbrProbeRTTState::BbrProbeRTTState(TcpBbr *owner) : BbrState(owner) {
  NS_LOG_FUNCTION(this);
}

BbrProbeRTTState::BbrProbeRTTState() : BbrState() {
  NS_LOG_FUNCTION(this);
}

// Get type id.
TypeId BbrProbeRTTState::GetTypeId(void) {
  static TypeId tid = TypeId("ns3::BbrProbeRTTState")
    .SetParent<BbrStateMachine>()
    .SetGroupName("Internet")
    .AddConstructor<BbrProbeRTTState>();
  return tid;
}

// Get name of object.
std::string BbrProbeRTTState::GetName() const {
  return "BbrProbeRTTState";
}

// Get state type.
bbr::bbr_state BbrProbeRTTState::getType(void) const {
  return bbr::PROBE_RTT_STATE;
}

// Invoked when state first entered.
void BbrProbeRTTState::enter() {
  NS_LOG_FUNCTION(this);
  NS_LOG_LOGIC(this << " State: " << GetName());

  // Set gains (Send() will minimize window);
  m_owner -> m_pacing_gain = bbr::STEADY_FACTOR;
  m_owner -> m_cwnd_gain = bbr::STEADY_FACTOR;

  // Compute time when to exit: max (0.2 seconds, min RTT).
  Time rtt = m_owner -> getRTT();
  if (rtt.GetSeconds() > 0.2)
    m_probe_rtt_time = rtt;
  else
    m_probe_rtt_time = Time(0.2 * 1000000000);
  m_probe_rtt_time = m_probe_rtt_time + Simulator::Now();
    
  NS_LOG_LOGIC(this << " " <<
	      GetName() << " In PROBE_RTT until: " << m_probe_rtt_time.GetSeconds());
}

// Invoked when state updated.
void BbrProbeRTTState::execute() {
  NS_LOG_FUNCTION(this);
  NS_LOG_LOGIC(this << " State: " << GetName());

  // Cwnd target is minimum.
  m_owner -> m_cwnd = bbr::MIN_CWND * 1500; // In bytes.

  // If enough time elapsed, PROBE_RTT --> PROBE_BW.
  Time now = Simulator::Now();
  if (now > m_probe_rtt_time) {
      NS_LOG_LOGIC(this << " Exiting PROBE_RTT, next state PROBE_BW");
      m_owner -> m_machine.changeState(&m_owner -> m_state_probe_bw);
  }
}
