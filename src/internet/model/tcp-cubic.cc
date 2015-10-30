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
 * This class implementes TCP CUBIC for ns-3 based on the class TcpSocketBase.
 * As packets are sent, arive or loss events occur the TcpSocketBase class is
 * called to process what should be done. Congestion control algorithms for TCP
 * extend from TcpSocketBase and override a set of methods to implement their
 * specific rules. Much of the code in this class was taken from the ns-2
 * and Linux Kernel 3.11 implementations to ensure this implementation would
 * be as realistic to what is actually implemented as possible. This code
 * did however need to be modified so that it would work within the setup of
 * TcpSocketBase.
 *
 * The Linux Kernel 3.11 implementation was taken from:
 * http://lxr.free-electrons.com/source/net/ipv4/tcp_cubic.c?v=3.11
 */

#include "tcp-cubic.h"
#include "ns3/log.h"
#include "ns3/trace-source-accessor.h"
#include "ns3/simulator.h"
#include "ns3/abort.h"
#include "ns3/node.h"

#include <math.h>       /* round, floor, ceil, trunc */

NS_LOG_COMPONENT_DEFINE ("TcpCubic");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED(TcpCubic);

/**
 * Get the TypeId which allows users running the simulation to set configurable
 * parameters.
 */
TypeId TcpCubic::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::TcpCubic")
    .SetParent<TcpSocketBase> ()
    .AddConstructor<TcpCubic> ();
  return tid;
}

/**
 * Default constructor.
 */
TcpCubic::TcpCubic (void)
  : m_retxThresh(3),
    m_inFastRec (false),
    m_cubeFactor((1ull << (10+3*BICTCP_HZ)) / 410),
    m_beta(819),        // Based on ns-2 implementation
    m_bicScale(41),     // Based on Linux 3.11 implementation
    m_maxIncrement(16), // Based on ns-2 implementation
    m_delayedAck( 2 << ACK_RATIO_SHIFT),
    m_epochStart(0),
    m_windowMax(0),
    m_lastMax(0),
    m_k(0.0),
    m_dMin(0),
    m_originPoint(0),
    m_tcpCwnd(0),
    m_tcpFriendly(true), // It looks like I leave this true
    m_ackCnt(0),
    m_cWndCnt(0)
{
  NS_LOG_FUNCTION (this);
  m_ssThresh = 100 * m_segmentSize;

  m_betaScale = 8*(BICTCP_BETA_SCALE+m_beta)/ 3 / (BICTCP_BETA_SCALE - m_beta);

  // Setup the cube_rtt_scale
  m_cubeRttScale = (m_bicScale * 10);
}

/**
 * Copy constructor.
 */
TcpCubic::TcpCubic (const TcpCubic& sock) :
  TcpSocketBase(sock),
  m_recover(sock.m_recover),
  m_retxThresh(sock.m_retxThresh),
  m_inFastRec(sock.m_inFastRec),
  m_limitedTx(sock.m_limitedTx),
  m_cubeFactor(sock.m_cubeFactor),
  m_beta(sock.m_beta),
  m_cubeRttScale(sock.m_cubeRttScale),
  m_bicScale(sock.m_bicScale),
  m_betaScale(sock.m_betaScale),
  m_maxIncrement(sock.m_maxIncrement),
  m_delayedAck(sock.m_delayedAck),
  m_epochStart(sock.m_epochStart),
  m_windowMax(sock.m_windowMax),
  m_lastMax(sock.m_lastMax),
  m_k(sock.m_k),
  m_dMin(sock.m_dMin),
  m_originPoint(sock.m_originPoint),
  m_tcpCwnd(sock.m_tcpCwnd),
  m_tcpFriendly(sock.m_tcpFriendly),
  m_ackCnt(sock.m_ackCnt),
  m_cWndCnt(sock.m_cWndCnt)
{
  NS_LOG_FUNCTION (this);
  NS_LOG_LOGIC ("Invoked the copy constructor");
}

/**
 * Default deconstructor.
 */
TcpCubic::~TcpCubic (void)
{
}


Ptr<TcpSocketBase>
TcpCubic::Fork (void)
{
  return CopyObject<TcpCubic> (this);
}

void
TcpCubic::NewAck (const SequenceNumber32& seq)
{
  NS_LOG_FUNCTION (this << seq);
  NS_LOG_LOGIC ("TcpCubic receieved ACK for seq " << seq <<
                " cwnd " << m_cWnd <<
                " ssthresh " << m_ssThresh);

  // Check for exit condition of fast recovery
  if (m_inFastRec)
    {// First new ACK after fast recovery, reset cwnd as in Reno
      m_inFastRec = false;
      NS_LOG_DEBUG ("Reset cwnd to " << m_cWnd);
    };

  NS_LOG_DEBUG( "SegmentSize = " << m_segmentSize );
  // Check if the current cwnd < ssthresh, if so normal cwnd increase
  if (m_cWnd <= m_ssThresh)
    { // Slow start mode, add one segSize to cWnd. Default m_ssThresh is 65535. (RFC2001, sec.1)
      m_cWnd += m_segmentSize;
      NS_LOG_DEBUG ("  In SlowStart, updated to cwnd " << m_cWnd << " ssthresh " << m_ssThresh);
    }
  else
    {
      Time rtt = m_rtt->GetEstimate (); //changed by ZMl
      NS_LOG_INFO( "RTT = " << rtt.GetMilliSeconds () );
      // Check if this RTT is the smallest
      if ( m_dMin == 0 || m_dMin > rtt.GetMilliSeconds () )
        {
          m_dMin = rtt.GetMilliSeconds ();
        }


      // Run the CUBIC update algorithm
      uint32_t cnt = CubicUpdate ();

      // Update only if a number of ACKs have returned
      if ( cnt != 0 )
        {
          NS_LOG_DEBUG("CubicUpdate suggests: " << cnt);

          // According to the CUBIC paper and RFC 6356 even once the new cwnd is
          // calculated you must compare this to the number of ACKs received since
          // the last cwnd update. If not enough ACKs have been received then cwnd
          // cannot be updated.
          if (m_cWndCnt > cnt)
            {
              m_cWnd += m_segmentSize;
              m_cWndCnt = 0;
             NS_LOG_DEBUG("Increment cwnd to " << m_cWnd);
            }
          else
            {
              NS_LOG_DEBUG("Not enough segments have been ACKed to increment cwnd.");
              m_cWndCnt += 1;
            }
        }
    }

  // Complete newAck processing
  TcpSocketBase::NewAck(seq);
}

/**
 * Perform CUBIC reset when a delayed ACK timeout occurs.
 */
void
TcpCubic::DelAckTimeout (void)
{
  CubicReset();
  TcpSocketBase::DelAckTimeout();
}

/**
 * Return the index of the last set bit. In the original Linux implementation
 * this method is provided in the Linux Kernel. This method is copied from the
 * the ns-2 TCP package.
 */
uint32_t
TcpCubic::fls64(uint64_t x)
{
  uint32_t h = x >> 32;
  if (h)
    return fls(h) + 32;
  return fls(x);
}

/**
 * Return the index of the last set bit. The ns-2 implementation of the method
 * fls64 uses this method with normal integers. This method is copied from the
 * ns-2 TCP package.
 */
int
TcpCubic::fls(int x)
{
  int r = 32;

  if (!x)
    return 0;
  if (!(x & 0xffff0000u)) {
    x <<= 16;
    r -= 16;
  }
  if (!(x & 0xff000000u)) {
    x <<= 8;
    r -= 8;
  }
  if (!(x & 0xf0000000u)) {
    x <<= 4;
    r -= 4;
  }
  if (!(x & 0xc0000000u)) {
    x <<= 2;
    r -= 2;
  }
  if (!(x & 0x80000000u)) {
    x <<= 1;
    r -= 1;
  }
  return r;
}

/**
 * The CUBIC algorithm in Linux and ns-2 does not use the normal C++ pow
 * function to take the cubed root. Instead they use their own method. While
 * this method does not produce a perfect cubed root it is what CUBIC uses.
 */
uint32_t
TcpCubic::CubicRoot(uint64_t a)
{
  uint32_t x, b, shift;
  /*
   * cbrt(x) MSB values for x MSB values in [0..63].
   * Precomputed then refined by hand - Willy Tarreau
   *
   * For x in [0..63],
   *   v = cbrt(x << 18) - 1
   *   cbrt(x) = (v[x] + 10) >> 6
   */
  static const uint8_t v[] = {
    /* 0x00 */    0,   54,   54,   54,  118,  118,  118,  118,
    /* 0x08 */  123,  129,  134,  138,  143,  147,  151,  156,
    /* 0x10 */  157,  161,  164,  168,  170,  173,  176,  179,
    /* 0x18 */  181,  185,  187,  190,  192,  194,  197,  199,
    /* 0x20 */  200,  202,  204,  206,  209,  211,  213,  215,
    /* 0x28 */  217,  219,  221,  222,  224,  225,  227,  229,
    /* 0x30 */  231,  232,  234,  236,  237,  239,  240,  242,
    /* 0x38 */  244,  245,  246,  248,  250,  251,  252,  254,
  };

  b = fls64(a);

  if (b < 7)
    {
      /* a in [0..63] */
      return ((uint32_t)v[(uint32_t)a] + 35) >> 6;
    }

  b = ((b * 84) >> 8) - 1;
  shift = (a >> (b * 3));

  x = ((uint32_t)(((uint32_t)v[shift] + 10) << b)) >> 6;

  /*
   * Newton-Raphson iteration
   *                         2
   * x    = ( 2 * x  +  a / x  ) / 3
   *  k+1          k         k
   */
  // NOTE:
  // The Linux and ns-2 implementation use the method div64_64 to divide these
  // numbers as not all systems support 64 bit numbers. I could not find a
  // similar method in C++ so for now this code assumes that 64 bit numbers are
  // supported.
  //x = (2 * x + (uint32_t)div64_64(a, (uint64_t)x * (uint64_t)(x - 1)));
  x = (2 * x + (uint32_t)(a / ((uint64_t)x * (uint64_t)(x - 1))));
  x = ((x * 341) >> 10);
  return x;
}


unsigned long
TcpCubic::tcp_time_stamp ()
{
  return trunc(Simulator::Now().GetSeconds () * JIFFY_RATIO);
}


/**
 * Get the next size of the congestion window using the CUBIC update algorithm.
 * Depending on the current situation this could be a TCP Friendly update or a
 * standard CUBIC update for a concave or convex region.
 */
uint32_t
TcpCubic::CubicUpdate ()
{
   NS_LOG_DEBUG("Run a CUBIC update.");

  // Convert the cwnd stored in bytes to a cwnd in segments. Whenever the
  // CUBIC algorithm uses cwnd the value cwndSeg will be used.
  uint32_t cwndSeg = m_cWnd / m_segmentSize;
  // The suggested amount to add to the new congestion window size.
  uint32_t windowTarget = 0;
  // The new congestion window size recommended by CUBIC.
  uint32_t cnt, min_cnt = 0;

  // Increment the number of ACKs counted
  m_ackCnt += 1;


  // The Linux implementation includes a check here to stop the update of cwnd
  // when the current cwnd has reached Wmax when less than a particular amount
  // of time has passed.
  if ( m_lastMax == cwndSeg &&
       (int32_t)(tcp_time_stamp() - m_lastTime) <= HZ / 32)
    {
      // Return 0 to indicate that no cwnd update should be made.
      return 0;
    }


  m_lastCwnd = cwndSeg; 
  m_lastTime = tcp_time_stamp ();


  // If there has not been a packet drop yet
  if (m_epochStart == 0)
    {
      // Record the beginning of an epoch.
      m_epochStart = tcp_time_stamp ();
      m_ackCnt = 1;
      m_tcpCwnd = cwndSeg;


      if (m_lastMax <= cwndSeg)
        {
          // The congestion window has grown beyond W_lastMax, which was Wmax
          // before the previouse congestion window drop. So the window size
          // has now grown to the previouse Wmax and K is set to 0.
          m_k = 0;
          m_originPoint = cwndSeg;
        }
      else
        {
          // The value of K is not calculated the same way in the Linux
          // implementation than it is in the orrginal paper.
          // C = 2681735677
          m_k = CubicRoot(((m_lastMax - cwndSeg) * m_cubeFactor));
          m_originPoint = m_lastMax;
          NS_LOG_DEBUG("  K set to " << m_k << "  Origin Point set to " << m_originPoint );
        }
    }


  // Next calculate 't' or the current time since epoch. When the value of
  // 't' is equal to 'K' then the CUBIC algorithm should have reached the
  // origin or Wmax point.
  //
  // Unfortunetly ns-3.18 does not suppor the TCP timestamp header.
  // Instead this code calls tcp_time_stamp which gets a TCP timestamp
  // similar to ns-2 (by using the simulators clock) but this is the
  // current time, not the time from the sender.
  uint32_t t = ((tcp_time_stamp () - m_epochStart + (m_dMin>>3))
                 << BICTCP_HZ) / HZ;

  NS_LOG_DEBUG("  t = " << t << " time stamp = " << tcp_time_stamp () << " delay = " << (m_dMin>>3) << " Epoch Start = " << m_epochStart << "  BICTCP_HZ = " << BICTCP_HZ << "  HZ = " << HZ  );

  // Calculate t - K for CUBIC. In Linux and ns-2 this is done with checks to
  // make sure the result is positive
  uint64_t offs;
  if (t < m_k)
    {
      offs = m_k - t;
    }
  else
   {
     offs = t - m_k;
   }

  // In the CUBIC paper the equation
  // C * (t-K)^3
  // is used to help find the CUBIC target. The Linux implementation however
  // differs from this. Instread a value reffered to as the cube RTT scale is
  // used instread of C. This cube RTT scale seems to take some expected RTT
  // into account. However the Linux implementation also indicates that the
  // units that result from this change need to be shifted so they can be in
  // a unit called BICTCP_HZ. It is not clear exactly what this unit is but
  // many of the unit convertions inside the Linux implementation seem to be
  // for converting the TCP timestamps value to some other unit based on
  // information specific to the particular architecture of the system.
  uint32_t delta = (m_cubeRttScale * offs * offs * offs) >> (10+3*BICTCP_HZ);

  // Next this delta value is either subtracted from or added to the origin.
  // In the Linux paper it is suggested that the cubic equation can be used
  // the same when above or below the Wmax or origin value but the Linux
  // implementation differs here.
  if (t < m_k)
    { // Below origin
      windowTarget = m_originPoint - delta;
      NS_LOG_DEBUG("  Below origin, W_target: " << windowTarget);
      NS_LOG_DEBUG("  W_target = Origin_point - delta");
      NS_LOG_DEBUG("  " << windowTarget << " = " << m_originPoint << " - " << delta);
    }
  else
    { // Above origin
      windowTarget = m_originPoint + delta;
      NS_LOG_DEBUG("  Above origin, W_target: " << windowTarget);
      NS_LOG_DEBUG("  W_target = Origin_point + delta");
      NS_LOG_DEBUG("  " << windowTarget << " = " << m_originPoint << " + " << delta);
    }

  
  // Next the window target is converted into a cnt or count value. CUBIC will
  // wait until enough new ACKs have arrived that a counter meets or exceeds
  // this cnt value. This is how the CUBIC implementation simulates growing
  // cwnd by values other than 1 segment size.
  if (windowTarget > cwndSeg)
    {
      cnt = cwndSeg/(windowTarget - cwndSeg);
    }
  else
    {
      // Make a very small increment.
      cnt = 100 * cwndSeg;
    }


  if (m_dMin > 0)
    {
      /* max increment = Smax * rtt / 0.1  */
      min_cnt = (cwndSeg * HZ * 8)/(10 * m_maxIncrement * m_dMin);

      /* use concave growth when the target is above the origin */
      if (cnt < min_cnt && t >= m_k)
        {
          cnt = min_cnt;
        }
    }


  // An extra check that the target suggested works in slow start and during
  // low utilization periods.
  if (m_lastMax == 0 ) // couble be aggresive in slow start
   {
     cnt = 50;
   }


  // Check the TCP Friendliness version to see if the congestion window should
  // be set differently.
  if (m_tcpFriendly)
    {
      cnt = CubicTcpFriendliness(cnt);
    }

  NS_LOG_DEBUG( "cnt = " << cnt );
  return cnt;
}


/**
 * Get the next size of the congestion window when CUBIC is in the TCP
 * TCP Friendly region.
 */
uint32_t
TcpCubic::CubicTcpFriendliness(uint32_t cnt)
{
  // Convert the cwnd stored in bytes to a cwnd in segments. Whenever the
  // CUBIC algorithm uses cwnd the value cwndSeg will be used.
  uint32_t cwndSeg = m_cWnd / m_segmentSize;
  uint32_t max_cnt = 0;
  uint32_t scale = m_betaScale;
  uint32_t delta = (cwndSeg * scale) >> 3;

  // update tcp cwnd
  while (m_ackCnt > delta)
    {
      m_ackCnt -= delta;
      m_tcpCwnd += 1;
    }
  
  // If BIC is slower than TCP
  if (m_tcpCwnd > cwndSeg)
    {
      delta = m_tcpCwnd - cwndSeg;
      max_cnt = cwndSeg / delta;
      if (cnt > max_cnt)
        {
          cnt = max_cnt;
        }
    }

  cnt = (cnt << ACK_RATIO_SHIFT) / m_delayedAck;
  if ( cnt == 0 ) // cannot be zero
    {
      cnt = 1;
    }


  return cnt;
}

void
TcpCubic::DupAck (const TcpHeader& t, uint32_t count)
{
  NS_LOG_FUNCTION (this);

  // Convert the cwnd stored in bytes to a cwnd in segments. Whenever the
  // CUBIC algorithm uses cwnd the value cwndSeg will be used.
  uint32_t cwndSeg = m_cWnd / m_segmentSize;

  if (count == m_retxThresh && !m_inFastRec)
    {
      NS_LOG_DEBUG( "Reached " << m_retxThresh << " and not in fast recovery" );     

      // triple duplicate ack triggers fast retransmit (RFC2582 sec.3 bullet #1)
      // TCP Cubic rules
      m_epochStart = 0;

      // NOTE: Linux and ns-2 CUBIC check a flag to see if Fast Convergence is
      // in use.
      if ( cwndSeg < m_lastMax )
        {
          m_lastMax = (cwndSeg * (BICTCP_BETA_SCALE + m_beta)) / (2 * BICTCP_BETA_SCALE);
        }
      else
        {
          m_lastMax = cwndSeg;
        }


      uint32_t temp = (cwndSeg * m_beta) / BICTCP_BETA_SCALE;
      if (temp < 2U)
        {
         temp = 2;
        }
      
      m_cWnd = temp * m_segmentSize;
      m_ssThresh = temp * m_segmentSize;
 
      m_inFastRec = true;
      DoRetransmit ();
    }
  else if (m_inFastRec)
    { // Increase cwnd for every additional dupack (RFC2582, sec.3 bullet #3)
      m_cWnd += m_segmentSize;
      SendPendingData (m_connected);
    }
  else if (!m_inFastRec && m_limitedTx && m_txBuffer->SizeFromSequence (m_nextTxSequence) > 0)
    { // RFC3042 Limited transmit: Send a new packet for each duplicated ACK before fast retransmit
      uint32_t sz = SendDataPacket (m_nextTxSequence, m_segmentSize, true);
      m_nextTxSequence += sz;                    // Advance next tx sequence
    };
}

void
TcpCubic::Retransmit (void)
{
  // Temporatily do what NewReno does:
  NS_LOG_FUNCTION (this);
  m_inFastRec = false;

  // If erroneous timeout in closed/timed-wait state, just return
  if (m_state == CLOSED || m_state == TIME_WAIT) return;
  // If all data are received (non-closing socket and nothing to send), just return
  if (m_state <= ESTABLISHED && m_txBuffer->HeadSequence () >= m_highTxMark) return;


  //---------------------------------------------------------------------------
  // Timeout requires a CUBIC reset. The rest of the code in this file is from
  // New Reno and may need to be removed or modified.
  CubicReset();
  //---------------------------------------------------------------------------



  // According to RFC2581 sec.3.1, upon RTO, ssthresh is set to half of flight
  // size and cwnd is set to 1*MSS, then the lost packet is retransmitted and
  // TCP back to slow start
  //  m_ssThresh = std::max (2 * m_segmentSize, BytesInFlight () / 2);
  //  m_cWnd = m_segmentSize;
  m_nextTxSequence = m_txBuffer->HeadSequence (); // Restart from highest Ack
   // NS_LOG_INFO ("RTO. Reset cwnd to " << m_cWnd <<
   //            ", ssthresh to " << m_ssThresh << ", restart from seqnum " << m_nextTxSequence);
  // changed by ZML m_rtt->IncreaseMultiplier ();             // Double the next RTO
  DoRetransmit ();                          // Retransmit the packet
}

/**
 * Setup CUBIC variables. Reset is called at initialization and for timeouts.
 */
void
TcpCubic::CubicReset(void)
{
  m_lastMax = 0;
  m_tcpCwnd = 0;
  m_epochStart = 0;
  m_originPoint = 0;
  m_dMin = 0;
  m_ackCnt = 0;
  m_lastTime = 0;
}


} // namespace ns3
