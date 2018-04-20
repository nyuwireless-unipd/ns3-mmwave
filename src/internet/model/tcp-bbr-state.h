//
// BbrState.h
//
// State machine (and states) for TcpBbr.
//

#ifndef BBR_STATE_H
#define BBR_STATE_H

#include "ns3/object.h"
#include "ns3/nstime.h"

namespace ns3 {

class TcpBbr; 
class BbrState;

namespace bbr {

// Defined BBR' states.
enum bbr_state {
  UNDEFINED_STATE=-1,
  STARTUP_STATE,
  DRAIN_STATE,
  PROBE_BW_STATE,
  PROBE_RTT_STATE,
};

} // end of namespace bbr

///////////////////////////////////////////////
// BBR' State Machine
class BbrStateMachine : public Object {

 public:
  // Get type id.
  static TypeId GetTypeId();

  // Get name of object.
  std::string GetName() const;

  // Constructor.
  BbrStateMachine();
  BbrStateMachine(TcpBbr *owner);

  // Change state machine to new state.
  void changeState(BbrState *p_new_state);

  // Get type of current state.
  bbr::bbr_state getStateType() const;

  // Update by executing current state.
  void update();

 private:
  BbrState *m_state;           // Current state.
  TcpBbr *m_owner;             // BBR' flow that owns machine.
};

///////////////////////////////////////////////
// BBR' State.
class BbrState : public Object {

 public:
  // Get type id.
  static TypeId GetTypeId();

  // Get name of object.
  virtual std::string GetName() const;
  
  // Constructors.
  BbrState();
  BbrState(TcpBbr *owner);

  // Destructor.
  virtual ~BbrState();

  // Get state type.
  virtual bbr::bbr_state getType() const=0;

  // Invoked when state first entered.
  virtual void enter();

  // Invoked when state updated.
  virtual void execute()=0;

  // Invoked when state exited.
  virtual void exit();

 protected:
  TcpBbr *m_owner;             // BBR' flow that owns state.
};

///////////////////////////////////////////////
// BBR' STARTUP state

class BbrStartupState : public BbrState {

 public:
  // Get type id.
  static TypeId GetTypeId();

  // Get name of object.
  std::string GetName() const;
  
  // Constructors.
  BbrStartupState(TcpBbr *owner);
  BbrStartupState();

  // Get state type.
  bbr::bbr_state getType() const;

  // Invoked when state first entered.
  void enter();

  // Invoked when state updated.
  void execute();

 private:
  double m_full_bw;                        // Max prev BW in STARTUP.
  int m_full_bw_count;                     // Times BW not grown in STARTUP.
};

///////////////////////////////////////////////
// BBR' DRAIN

class BbrDrainState : public BbrState {

 public:
  // Get type id.
  static TypeId GetTypeId();

  // Get name of object.
  std::string GetName() const;
  
  // Constructors.
  BbrDrainState(TcpBbr *owner);
  BbrDrainState();

  // Get state type.
  bbr::bbr_state getType() const;

  // Invoked when state first entered.
  void enter();

  // Invoked when state updated.
  void execute();

 private:
  uint32_t m_inflight_limit; // Target bytes in flight to exit DRAIN state.
  uint32_t m_round_count;    // Number of rounds in DRAIN state.
};

///////////////////////////////////////////////
// BBR' PROBE_BW

class BbrProbeBWState : public BbrState {

 public:
  // Get type id.
  static TypeId GetTypeId();

  // Get name of object.
  std::string GetName() const;
  
  // Constructors.
  BbrProbeBWState(TcpBbr *owner);
  BbrProbeBWState();

  // Get state type.
  bbr::bbr_state getType() const;

  // Invoked when state first entered.
  void enter();

  // Invoked when state updated.
  void execute();

 private:
  int m_gain_cycle;                        // For cycling gain in PROBE_BW.
};

///////////////////////////////////////////////
// BBR' PROBE_RTT

class BbrProbeRTTState : public BbrState {

 public:
  // Get type id.
  static TypeId GetTypeId();

  // Get name of object.
  std::string GetName() const;
  
  // Constructors.
  BbrProbeRTTState(TcpBbr *owner);
  BbrProbeRTTState();

  // Get state type.
  bbr::bbr_state getType() const;

  // Invoked when state first entered.
  void enter();

  // Invoked when state updated.
  void execute();

 private:
  Time m_probe_rtt_time;     // Time to remain in PROBE_RTT.
};

} // end of namespace ns3
#endif
