/*
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
 */

/**
 * This header file contains defines, global variables and function definitions
 * to use with TCP CUBIC. The format of this file was designed from other ns-3
 * TCP implementation header files.
 */
#ifndef TCP_CUBIC_H
#define TCP_CUBIC_H


/**
 * The following defines come from the ns-2 implementation and Linux Kernel
 * version 3.11 implementation for TCP CUBIC. The Linux implemenation was taken
 * from the Web Site:
 * http://lxr.free-electrons.com/source/net/ipv4/tcp_cubic.c?v=3.11
 */
#define BICTCP_BETA_SCALE    1024       /* Scale factor beta calculation
                                         * max_cwnd = snd_cwnd * beta
                                         */
#define BICTCP_B                4        /*
                                          * In binary search,
                                          * go to point (max+min)/N
                                          */
#define BICTCP_HZ               10      /* BIC HZ 2^10 = 1024 */

#define HZ 1000

#define JIFFY_RATIO 1000

#define ACK_RATIO_SHIFT 4

#include "tcp-socket-base.h"
#include "ns3/packet.h"

namespace ns3 {

/**
 * \ingroup socket
 * \ingroup tcp
 *
 * This class implements TCP Cubic, which as of the time of this writing is one
 * of the two major versions of TCP used (Cubic in Linux systems, Compound in
 * Windows).
 */
class TcpCubic : public TcpSocketBase
{
public:
  static TypeId GetTypeId (void);

  /**
   * Default constructor.
   */
  TcpCubic (void);

  /**
   * Copy constructor.
   */
  TcpCubic (const TcpCubic& sock);

  /**
   * Default deconstructor.
   */
  virtual ~TcpCubic (void);

protected:
  virtual Ptr<TcpSocketBase> Fork (void); // Call CopyObject<TcpNewReno> to clone me
  virtual void NewAck (SequenceNumber32 const& seq); // Inc cwnd and call NewAck() of parent
  virtual void DelAckTimeout (void); // Timeout for delayed ACK
  virtual void DupAck (const TcpHeader& t, uint32_t count);  // Halving cwnd and reset nextTxSequence
  virtual void Retransmit (void); // Exit fast recovery upon retransmit timeout

private:
  
  /**
   * Return the index of the last set bit. In the original Linux implementation
   * this method is provided in the Linux Kernel. This method is copied from the
   * the ns-2 TCP package.
   */
  uint32_t fls64(uint64_t a);

  /**
   * Return the index of the last set bit. The ns-2 implementation of the method
   * fls64 uses this method with normal integers. This method is copied from the
   * ns-2 TCP package.
   */
  int fls(int x);

  /**
   * The CUBIC algorithm in Linux and ns-2 does not use the normal C++ pow
   * function to take the cubed root. Instead they use their own method. While
   * this method does not produce a perfect cubed root it is what CUBIC uses.
   */
  uint32_t CubicRoot (uint64_t a);
  
  /**
   * Get the next size of the congestion window using the CUBIC update algorithm.
   * Depending on the current situation this could be a TCP Friendly update or a
   * standard CUBIC update for a concave or convex region.
   */
  uint32_t CubicUpdate ();

  /**
   * Get the next size of the congestion window when CUBIC is in the TCP
   * TCP Friendly region.
   */
  uint32_t CubicTcpFriendliness (uint32_t cnt);

  /**
   * Setup CUBIC variables. Reset is called at initialization and for timeouts.
   */
  void CubicReset ();

  unsigned long tcp_time_stamp();

protected:
  //TracedValue<uint32_t>  m_cWnd;         //< Congestion window
  //uint32_t               m_ssThresh;     //< Slow Start Threshold
  //uint32_t               m_initialCWnd;  //< Initial cWnd value   ZML
  SequenceNumber32       m_recover;      //< Previous highest Tx seqnum for fast recovery
  uint32_t               m_retxThresh;   //< Fast Retransmit threshold
  bool                   m_inFastRec;    //< currently in fast recovery
  bool                   m_limitedTx;    //< perform limited transmit


  // Cubic specific variables
  /** Cubic scaling factor. */
  uint64_t m_cubeFactor;

  /** Constant multiplication decrease factor in Cubic algorithm. */ 
  double m_beta;

  /**
   * While not part of the original CUBIC algorithm this is used in the real
   * Linux implementation instead of the normal C CUBIC scaling factor.
   */
  uint32_t m_cubeRttScale;

  /**
   * BIC Scale. This is not part of the CUBIC paper but it is in the Linux and
   * ns-2 implementation.
   */
  int m_bicScale;

  /**
   * This is not part of the CUBIC paper but it is in the Linux and ns-2
   * implementation.
   */
  uint32_t m_betaScale;


  // Estimate the ratio of Packets/ACKs << 4
  uint32_t m_delayedAck;

  /**
   * The time the last congestion window reduction occured. This is used to
   * find the elapsed time 't' used in the Cubic algorithm.
   */
  int64_t m_epochStart;

  // Time when updated last.
  uint32_t m_lastTime;

  /** The congestion window size just before the last reduction. */
  uint32_t m_windowMax;

  /* cwnd before last lost event. */
  uint32_t m_lastMax;

  /** The previouse congestion window size for the last reduction. */
  uint32_t m_lastCwnd; 

  /** 
   * Interval between two consecutive loss events in the steady-state.
   */
  double m_k;

  /** The shortest RTT observed. */ 
  uint32_t m_dMin;

  /** The starting size of the congestion window at the last window reduction. */
  uint32_t m_originPoint;

  /** The new cwnd suggested for TCP freiendliness. */
  uint32_t m_tcpCwnd;

  /** Flag for TCP Friendly region. */
  bool m_tcpFriendly;

  /** 
   * Count of ACKs. Due to the ns-3 implementation of using bytes instead of
   * packets this has been implemented as the number of bytes ACKed.
   */
  uint32_t m_ackCnt;

  /** Track the number of segments acked since the last cwnd increment.. */
  uint32_t m_cWndCnt;
};

} // namespace ns3

#endif /* TCP_CUBIC_H */
