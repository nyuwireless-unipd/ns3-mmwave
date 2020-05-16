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
*								 Integration of Carrier Aggregation
*/

#ifndef SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H
#define SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H

#include <vector>
#include <list>
#include <map>
#include <deque>
#include <ns3/nstime.h>
#include <ns3/object.h>
#include <ns3/packet.h>
#include <ns3/string.h>
#include <ns3/log.h>
//#include "mmwave-mac-pdu-header.h"
//#include "mmwave-mac-pdu-tag.h"

namespace ns3 {

namespace mmwave {

/**
 * struct holding the numerology information such as frame, subframe,
 * slot and (eventually) starting OFDM symbol number.
 */
struct SfnSf
{

  /**
   * Default constructor, the starting symbol is optional
   *
   * \param frameNum the frame number
   * \param sfNum the subframe number
   * \param slotNum the slot number
   * \param symStart the (optional) starting symbol
   */
  SfnSf (uint16_t frameNum = 0, uint8_t sfNum = 0, uint8_t slotNum = 0, uint8_t symStart = 0)
    : m_frameNum (frameNum), m_sfNum (sfNum), m_slotNum (slotNum), m_symStart (symStart)
  {
    // Non-negative
    NS_ASSERT ((m_frameNum >= 0) && (m_sfNum >= 0) && (m_slotNum >= 0) && (m_symStart >= 0));
  }

  /**
   * Encodes the struct into an uint64_t
   */
  uint64_t
  Encode () const
  {
    return ((uint64_t (m_frameNum) << 24 ) | ((m_sfNum & 0xFF) << 16) | ((m_slotNum & 0xFF) << 8) | (m_symStart & 0xFF));
  }

  /**
   * Decodes the struct from an uint64_t and updates the struct variables with the given values
   */
  void
  Decode (uint64_t sfn)
  {
    m_frameNum = sfn >> 24;
    m_sfNum = ((sfn & 0xFF0000) >> 16);
    m_slotNum = ((sfn & 0xFF00) >> 8);
    m_symStart = sfn & 0xFF;

  }

  uint16_t m_frameNum;  //!< Frame number
  uint8_t m_sfNum;  //!<Subframe number
  uint8_t m_slotNum;  //!< Slot number
  uint8_t m_symStart;   //!< Starting symbol (not always used!), sometimes used to indicate the ttiIndex
};

/* Equivalent to the DCI in LTE*/

//struct RbAllocationInfo
//{
//	bool m_noAllocation;
//	uint64_t m_userImsi;
//	uint32_t m_tbSize;
//	int mcs;
//
//	uint8_t m_harqProcess;
//};

struct PhyTransmissionTraceParams
{
  enum TddMode
  {
    TDD_NA = 0,
    DL = 1,
    UL = 2,
  };
  enum TddTtiType
  {
    DATA = 0, 
    TYPE_NA = 1,  
    CTRL = 2,
  };

  PhyTransmissionTraceParams()
    : m_tddMode (0),    
    m_slotNum (0),    
    m_sfNum (0),   
    m_frameNum (0),   
    m_rnti (0),   
    m_symStart (0),   
    m_numSym (0),   
    m_ttiType (0),
    m_rv (0),
    m_ccId (0)    
  {

  }

  uint8_t m_tddMode;  //!< TDD mode. Either DL or UL
  uint8_t m_slotNum;  //!< Slot number
  uint8_t m_sfNum;   //!< Subframe number
  uint8_t m_frameNum;  //!< Frame number
  uint16_t m_rnti;    //!< UE RNTI (where such distinction is applicable, 0 otherwise)
  uint8_t m_symStart;   //!< Starting OFDM symbol of the current transmission
  uint8_t m_numSym;   //!< Amount of OFDM symbols of current transmission
  uint8_t m_ttiType;    //!< TDD transmission type. Either DATA or CTRL.
  uint8_t m_rv;    //!< (Re)TX number. If 0 the TTI refers to new data, otherwise to a retx.
  uint8_t m_ccId;    //!< The Component Carrier (CC) ID
};

struct TbInfoElement
{
  TbInfoElement ()
    : m_isUplink (0),
    m_slotIdx (0),
    m_rbBitmap (0),
    m_rbShift (0),
    m_rbStart (0),
    m_rbLen (0),
    m_symStart (0),
    m_numSym (0),
    m_resAlloc (0),
    m_mcs (0),
    m_tbSize (0),
    m_ndi (0),
    m_rv (0),
    m_harqProcess (0)
  {
  }

  bool m_isUplink; // is uplink grant?
  uint8_t m_slotIdx; // slot index
  uint32_t m_rbBitmap; // Resource Block Group bitmap
  uint8_t m_rbShift; // shift for res alloc type 1
  uint8_t m_rbStart; // starting RB index for uplink res alloc type 0
  uint16_t m_rbLen;
  uint8_t m_symStart; // starting symbol index for flexible TTI scheme
  uint8_t m_numSym; // number of symbols for flexible TTI scheme
  uint8_t m_resAlloc; // resource allocation type
  uint8_t m_mcs;
  uint32_t m_tbSize;
  uint8_t m_ndi;
  uint8_t m_rv;
  uint8_t m_harqProcess;
};

struct DlDciInfoElementTdma
{
  DlDciInfoElementTdma ()
    : m_symStart (0),
    m_numSym (0),
    m_mcs (0),
    m_tbSize (0),
    m_ndi (0),
    m_rv (0),
    m_harqProcess (0)
  {
  }

  uint8_t m_symStart; // starting symbol index for flexible TTI scheme
  uint8_t m_numSym; // number of symbols for flexible TTI scheme
  uint8_t m_mcs;
  uint32_t m_tbSize;
  uint8_t m_ndi;
  uint8_t m_rv;
  uint8_t m_harqProcess;
};

struct DciInfoElementTdma
{
  enum DciFormat
  {
    DL_dci = 0, UL_dci = 1
  };

  DciInfoElementTdma ()
    : m_rnti (0),
    m_format (0),
    m_symStart (0),
    m_numSym (0),
    m_mcs (0),
    m_tbSize (0),
    m_ndi (0),
    m_rv (0),
    m_harqProcess (0)
  {
  }

  DciInfoElementTdma (uint16_t rnti, uint8_t format, uint8_t symStart, uint8_t numSym, uint8_t mcs,
                      uint32_t tbs, uint8_t ndi, uint8_t rv, uint8_t harqProc)
    : m_rnti (rnti),
    m_format (format),
    m_symStart (symStart),
    m_numSym (numSym),
    m_mcs (mcs),
    m_tbSize (tbs),
    m_ndi (ndi),
    m_rv (rv),
    m_harqProcess (harqProc)
  {
  }

  uint16_t m_rnti;
  uint8_t m_format; // {DL assig. = 0, UL grant = 1}, only contiguous symbols supported
  uint8_t m_symStart; // starting symbol index for flexible TTI scheme
  uint8_t m_numSym; // number of symbols for flexible TTI scheme
  uint8_t m_mcs;
  uint32_t m_tbSize;
  uint8_t m_ndi;
  uint8_t m_rv; // not used for UL DCI
  uint8_t m_harqProcess;
};

struct TbAllocInfo
{
  TbAllocInfo () : m_rnti (0)
  {
  }
  struct SfnSf m_sfnSf;
  uint16_t m_rnti;
  std::vector<unsigned> m_rbMap;
  TbInfoElement m_tbInfo;
};

struct DciInfoElement
{
  DciInfoElement () : m_rnti (0), m_cceIndex (0), m_format (0), m_tddBitmap (0)
  {
  }

  uint16_t m_rnti;
  uint8_t m_cceIndex;
  uint8_t m_format; // to support different DCI types
  uint16_t m_tddBitmap; // 0 == DL, 1 == UL
  std::vector<TbInfoElement> m_tbInfoElements;
};

struct RlcPduInfo
{
  RlcPduInfo () : m_lcid (0), m_size (0)
  {
  }

  RlcPduInfo (uint8_t lcid, uint16_t size) : m_lcid (lcid), m_size (size)
  {
  }
  uint8_t m_lcid;
  uint32_t m_size;
};

struct TtiAllocInfo
{
  enum TddMode
  {
    NA = 0,
    DL_slotAllocInfo = 1,
    UL_slotAllocInfo = 2,
  };

  enum TddTtiType
  {
    CTRL_DATA = 0, DATA = 1, CTRL = 2
  };

  enum CtrlTxMode
  {
    ANALOG = 0, DIGITAL = 1, OMNI = 2
  };

  TtiAllocInfo ()
    : m_tddMode (NA),
    m_isOmni (0),
    m_ttiType (CTRL_DATA),
    m_numCtrlSym (0),
    m_ttiIdx (0),
    m_ctrlTxMode (DIGITAL),
    m_rnti (0)
  {
  }

  TtiAllocInfo (uint8_t ttiIdx, TddMode tddMode, TddTtiType ttiType, CtrlTxMode ctrlTxMode,
                uint16_t rnti)
    : m_tddMode (tddMode),
    m_isOmni (0),
    m_ttiType (ttiType),
    m_numCtrlSym (0),
    m_ttiIdx (ttiIdx),
    m_ctrlTxMode (ctrlTxMode),
    m_rnti (rnti)
  {
  }

  //	SlotAllocInfo& operator= (const SlotAllocInfo &src)
  //	{
  //		m_tddMode = src.m_tddMode;
  //		m_isOmni = src.m_isOmni;
  //		m_slotType = src.m_slotType;
  //		m_numCtrlSym = src.m_numCtrlSym;
  //		m_slotIdx = src.m_slotIdx;
  //		m_ctrlTxMode = src.m_ctrlTxMode;
  //		m_rnti = src.m_rnti;
  //		m_dci = src.m_dci;
  //		m_rlcPduInfo = src.m_rlcPduInfo;
  //	}

  //std::vector<TbAllocInfo> m_tbInfo;
  //std::vector<unsigned> m_rntiCtrlSymMap;		// RNTI to which ctrl data is TXed for each ctrl symbol index (analog bf only)
  //std::map<uint16_t, std::vector<unsigned> > m_ueRbMap; // for FDMA

  //struct DciInfoElement m_dci;
  //std::vector<TbAllocInfo> m_tbInfo;
  //std::vector<unsigned> m_rntiCtrlSymMap;		// RNTI to which ctrl data is TXed for each ctrl symbol index (analog bf only)
  //std::vector<struct RlcPduInfo >  m_rlcPduList; // RLC PDU elems for MAC TB

  TddMode m_tddMode;
  bool m_isOmni; // Beamforming disabled, true if omnidirectional
  TddTtiType m_ttiType;
  uint8_t m_numCtrlSym; // number of DL ctrl (or ctrl+data) symbols at beginning of slot
  uint8_t m_ttiIdx;
  CtrlTxMode m_ctrlTxMode;
  uint16_t m_rnti;
  struct DciInfoElementTdma m_dci;
  std::vector<RlcPduInfo> m_rlcPduInfo;
  //std::list<MmWaveControlMessage> m_controlMessages;  // ctrl messages for this user
};

struct SlotAllocInfo
{
  SlotAllocInfo () : m_sfnSf (SfnSf ()), m_numSymAlloc (0), m_ulSymStart (0)
  {
    //m_tddPattern.resize (8);
  }

  SlotAllocInfo (SfnSf sfn) : m_sfnSf (sfn), m_numSymAlloc (0), m_ulSymStart (0)
  {
  }

  SfnSf m_sfnSf;
  uint32_t m_numSymAlloc; // number of allocated OFDM symbols
  uint32_t m_ulSymStart; // start of UL region
  //std::vector <SlotAllocInfo::TddMode> m_tddPattern;
  std::deque<TtiAllocInfo> m_dlSlotAllocInfo;
  std::deque<TtiAllocInfo> m_ulSlotAllocInfo;
  std::deque<TtiAllocInfo> m_ttiAllocInfo;
};

struct DlCqiInfo
{
  uint16_t m_rnti;
  uint8_t m_ri;
  enum DlCqiType
  {
    WB, SB
  } m_cqiType;
  std::vector<uint8_t> m_rbCqi; // CQI for each Rsc Block, set to -1 if SINR < Threshold
  uint8_t m_wbCqi; // Wide band CQI
  uint8_t m_wbPmi;
};

struct UlCqiInfo
{
  //std::vector <uint16_t> m_sinr;
  std::vector<double> m_sinr;
  enum UlCqiType
  {
    SRS, PUSCH, PUCCH_1, PUCCH_2, PRACH
  } m_type;
};

struct MacCeValue
{
  uint8_t m_phr;
  uint8_t m_crnti;
  std::vector<uint8_t> m_bufferStatus;
};

/**
 * \brief See section 4.3.14 macCEListElement
 */
struct MacCeElement
{
  uint16_t m_rnti;
  enum MacCeType
  {
    BSR, PHR, CRNTI
  } m_macCeType;
  struct MacCeValue m_macCeValue;
};

struct RlcListElement
{
  std::vector<struct RlcPduInfo> m_rlcPduElements;
};

struct SchedInfo
{
  SchedInfo () : m_frameNum (0), m_sfNum (0), m_rnti (0)
  {
  }
  SchedInfo (unsigned int numSlots) : m_frameNum (0), m_sfNum (0), m_rnti (0)
  {
  }

  uint16_t m_frameNum;
  uint8_t m_sfNum;
  uint16_t m_rnti;

  SlotAllocInfo m_slotAllocInfo;  //!< Holds the allocation info for a single NR slot
  struct DciInfoElement m_dci;
  std::map<uint8_t, std::vector<struct RlcPduInfo> > m_rlcPduMap; // RLC PDU elems for each MAC TB
};

struct UePhyPacketCountParameter
{
  uint64_t m_imsi;
  uint32_t m_noBytes;
  bool m_isTx; //Set to false if Rx and true if tx
  uint32_t m_subframeno;
};

struct EnbPhyPacketCountParameter
{
  uint64_t m_cellId;
  uint32_t m_noBytes;
  bool m_isTx; //Set to false if Rx and true if tx
  uint32_t m_subframeno;
};

struct RxPacketTraceParams
{
  uint64_t m_cellId;
  uint8_t m_ccId;
  uint16_t m_rnti;
  uint32_t m_frameNum;
  uint8_t m_sfNum;
  uint8_t m_slotNum;
  uint8_t m_symStart;
  uint8_t m_numSym;
  uint32_t m_tbSize;
  uint8_t m_mcs;
  uint8_t m_rv;
  double m_sinr;
  double m_sinrMin;
  double m_tbler;
  bool m_corrupt;
};

struct DlHarqInfo
{
  uint16_t m_rnti;
  uint8_t m_harqProcessId;
  enum HarqStatus
  {
    ACK, NACK
  };
  enum HarqStatus m_harqStatus;
  uint8_t m_numRetx;
};

struct UlHarqInfo
{
  uint16_t m_rnti;
  uint8_t m_harqProcessId;
  std::vector<uint16_t> m_ulReception;
  enum ReceptionStatus
  {
    Ok, NotOk, NotValid
  } m_receptionStatus;
  uint8_t m_tpc;
  uint8_t m_numRetx;
};

class MmWavePhyMacCommon : public Object
{
public:
  MmWavePhyMacCommon (void);

  ~MmWavePhyMacCommon (void)
  {
  }

  static TypeId GetTypeId (void);

  inline uint32_t
  GetSymbPerSlot (void)
  {
    return m_symbolsPerSlot;
  }

  inline Time
  GetSymbolPeriod (void)
  {
    return m_symbolPeriod;
  }

  inline uint32_t
  GetCtrlSymbols (void)
  {
    return m_ctrlSymbols;
  }

  inline uint32_t
  GetDlCtrlSymbols (void)
  {
    return m_dlCtrlSymbols;
  }

  inline uint32_t
  GetUlCtrlSymbols (void)
  {
    return m_ulCtrlSymbols;
  }

  inline uint32_t
  GetSymbolsPerSubframe (void)
  {
    return m_symbolsPerSubframe;
  }

  inline Time
  GetSubframePeriod (void)
  {
    return m_subframePeriod;
  }

  inline Time
  GetTti (void)
  {
    return NanoSeconds (m_symbolsPerSlot * m_symbolPeriod.GetNanoSeconds ());  //seconds
  }

  inline uint32_t
  GetSlotsPerSubframe (void)
  {
    return m_slotsPerSubframe;
  }

  inline uint32_t
  GetSubframesPerFrame (void)
  {
    return m_subframesPerFrame;
  }

  inline uint32_t
  GetNumReferenceSymbols (void)
  {
    return m_numRefSymbols;
  }

  inline Time
  GetGuardPeriod (void)
  {
    return m_guardPeriod;
  }

  inline uint8_t
  GetUlSchedDelay (void)
  {
    return m_ulSchedDelay;
  }

  inline uint32_t
  GetNumSCperChunk (void)
  {
    return m_numSubCarriersPerChunk;
  }

  inline double
  GetChunkWidth (void)
  {
    return m_chunkWidth;
  }

  inline uint32_t
  GetNumChunkPerRb (void)
  {
    return m_chunksPerRb;
  }

  inline uint32_t
  GetNumRefScPerRb (void)
  {
    return m_numRefScPerRb;
  }

  inline uint32_t
  GetNumRefScPerSym (void)
  {
    return m_numRefScPerSym;
  }

  inline uint32_t
  GetNumRb (void)
  {
    return m_numRb;
  }

  inline uint32_t
  GetNumRbPerRbg (void)
  {
    return m_numRbPerRbg;
  }

  inline double
  GetRBWidth (void)
  {
    return (m_chunksPerRb * m_chunkWidth);
  }

  inline double
  GetSystemBandwidth (void)
  {
    return (GetRBWidth () * m_numRb);
  }

  inline uint32_t
  GetTotalNumChunk ()
  {
    return (m_chunksPerRb * m_numRb);
  }

  inline double
  GetCenterFrequency (void)
  {
    return m_centerFrequency;
  }


 /**
  * Returns the L1L2 control info latency, expressed in # of NR slots.
  */
  inline uint32_t
  GetL1L2Latency (void)
  {
    return m_L1L2Latency;
  }

  inline Time
  GetWbCqiPeriodUs (void)
  {
    return m_wbCqiPeriodUs;
  }

  inline std::string
  GetStaticTDDPattern ()
  {
    return m_staticTddPattern;
  }

  inline uint32_t
  GetNumHarqProcess (void)
  {
    return m_numHarqProcess;
  }

  inline uint8_t
  GetHarqTimeout (void)
  {
    return m_harqTimeout;
  }

  inline uint32_t
  GetTbDecodeLatency (void)
  {
    return m_tbDecodeLatencyUs;
  }

  inline uint32_t
  GetMaxTbSize (void)
  {
    return m_maxTbSizeBytes;
  }

 /**
  * Makes a MmWavePhyMacCommon object NR-compliant by adjusting its parameters
  * 
  * \param index The numerology index, as per TS 38.211 Sec 4.3.2.
  *
  **/
  void
  SetNumerology (uint8_t index)
  {
    NS_ASSERT_MSG ( (index == 2) || (index == 3), "Numerology index is not valid."); // Only 2 and 3 are supported in NR for FR2.

    double subCarriersPerRB = 12; // TS 38.211 Sec 4.4.4.1
    double subcarrierSpacing = 15 * std::pow (2, index) * 1000; // Subcarrier spacing, only 60KHz and 120KHz are supported in NR for FR2.

    m_symbolsPerSlot = 14; // TS 38.211 Sec 4.3.2: each slot must have 14 symbols
    m_slotsPerSubframe = std::pow (2, index);// Number of slots per subframe, see TS 38.211 Sec 4.3.2
    m_symbolsPerSubframe = m_symbolsPerSlot * m_slotsPerSubframe;
    m_subframePeriod = Time (MilliSeconds (1)); // TS 38.211 Section 4.3.1: the subframe duration is 1ms
    m_symbolPeriod = Time (NanoSeconds (m_subframePeriod / m_symbolsPerSlot / m_slotsPerSubframe)); // Duration of an OFDM symbol
    m_chunkWidth = subCarriersPerRB * subcarrierSpacing;
  }

 /**
  * Sets the desired bandwidth for a given \ref MmWavePhyMacCommon object.
  * 
  * \param bw The intended bandwidth.
  *
  **/
  void
  SetBandwidth (double bw)
  {
    m_chunksPerRb = bw/(m_chunkWidth*m_numRb);  // The amount of RBs is fixed to 1 as only TDMA is supported
    m_numRefScPerSym = 864*bw/1e9; // TODO: check whether 864 is the proper value for 1 GHz of bandwidth
  }

  void
  SetSymbPerSlot (uint32_t numSym)
  {
    m_symbolsPerSlot = numSym;
  }

  void
  SetSymbolPeriod (Time prdSym)
  {
    m_symbolPeriod = prdSym;
  }

  void
  SetSymbolsPerSubframe (uint32_t numSym)
  {
    m_symbolsPerSubframe = numSym;
  }

  void
  SetSubframePeriod (Time period)
  {
    m_subframePeriod = period;
  }

  void
  SetCtrlSymbols (uint32_t ctrlSymbols)
  {
    m_ctrlSymbols = ctrlSymbols;
  }

  void
  SetDlCtrlSymbols (uint32_t ctrlSymbols)
  {
    m_dlCtrlSymbols = ctrlSymbols;
  }

  void
  SetUlCtrlSymbols (uint32_t ctrlSymbols)
  {
    m_ulCtrlSymbols = ctrlSymbols;
  }

  void
  SetSlotPerSubframe (uint32_t numSlot)
  {
    m_slotsPerSubframe = numSlot;
  }

  void
  SetSubframePerFrame (uint32_t numSf)
  {
    m_subframesPerFrame = numSf;
  }

  void
  SetNumReferenceSymbols (uint32_t refSym)
  {
    m_numRefSymbols = refSym;
  }

  void
  SetGuardPeriod (Time usec)
  {
    m_guardPeriod = usec;
  }

  void
  SetUlSchedDelay (uint32_t tti)
  {
    m_ulSchedDelay = tti;
  }

  void
  SetNumSCperChunk (uint32_t numSC)
  {
    m_numSubCarriersPerChunk = numSC;
  }

  void
  SetNumChunkPerRB (uint32_t numChunk)
  {
    m_chunksPerRb = numChunk;
  }

  void
  SetNumRefScPerRb (uint32_t numRefSc)
  {
    m_numRefScPerRb = numRefSc;
  }

  void
  SetNumRefScPerSym (uint32_t numRefSc)
  {
    m_numRefScPerSym = numRefSc;
  }

  void
  SetChunkWidth (double chumkWidth)
  {
    m_chunkWidth = chumkWidth;
  }
  void
  SetNumRb (uint32_t numRB)
  {
    m_numRb = numRB;
  }

  void
  SetNumRbPerRbg (uint32_t numRB)
  {
    m_numRbPerRbg = numRB;
  }

  void
  SetCentreFrequency (double fc)
  {
    m_centerFrequency = fc;
  }

  void
  SetL1L2Latency (uint32_t delaySfs)
  {
    m_L1L2Latency = delaySfs;
  }

  void
  SetWbCqiPeriodUs (Time us)
  {
    m_wbCqiPeriodUs = us;
  }

  void
  SetStaticTDDPattern (std::string p)
  {
    if (p.length () != m_slotsPerSubframe)
      {
        NS_FATAL_ERROR ("TDD pattern length should be equal to the number of slots per SF");
      }
    m_staticTddPattern = p;
  }

  void
  SetNumHarqProcess (uint32_t numProcess)
  {
    m_numHarqProcess = numProcess;
  }

  void
  SetHarqDlTimeout (uint8_t harqDlTimeout)
  {
    m_harqTimeout = harqDlTimeout;
  }

  void
  SetTbDecodeLatency (uint32_t us)
  {
    m_tbDecodeLatencyUs = us;
  }

  void
  SetMaxTbSize (uint32_t bytes)
  {
    m_maxTbSizeBytes = bytes;
  }

  void
  SetCcId (uint8_t ccId)
  {
    m_componentCarrierId = ccId;
  }

  uint8_t
  GetCcId (void)
  {
    return m_componentCarrierId;
  }

private:
  uint32_t m_symbolsPerSlot;
  Time m_symbolPeriod; // time duration of a single OFDM symbol
  uint32_t m_symbolsPerSubframe;
  Time m_subframePeriod; // time duration of a single subframe
  uint32_t m_ctrlSymbols;
  uint32_t m_dlCtrlSymbols; // num OFDM symbols for downlink control at beginning of subframe
  uint32_t m_ulCtrlSymbols; // num OFDM symbols for uplink control at end of subframe
  uint32_t m_slotsPerSubframe;
  uint32_t m_subframesPerFrame;
  uint32_t m_numRefSymbols;
  uint32_t m_numRbPerRbg;

  uint32_t m_numSubCarriersPerChunk;
  uint32_t m_chunksPerRb;
  uint32_t m_numRefScPerRb;
  uint32_t m_numRefScPerSym; // for TDMA, number of reference subcarriers across entire bandwidth (default to 1/4th of SCs)
  double m_chunkWidth; //enter in Hz.
  uint32_t m_numRb;
  uint8_t m_numHarqProcess;
  uint8_t m_harqTimeout;

  double m_centerFrequency;
  Time m_guardPeriod; // UL to DL switching time

  uint32_t m_L1L2Latency; //!< L1L2 control latency, expressed in # of NR slots.
  uint32_t m_ulSchedDelay;   //!<  Delay between the UL-DCI transmission and when such scheduled UL will take place, defined as # of NR slots.
  Time m_wbCqiPeriodUs; // WB CQI periodicity in microseconds

  uint32_t m_tbDecodeLatencyUs;
  uint32_t m_maxTbSizeBytes;

  std::string m_staticTddPattern;

  uint8_t m_componentCarrierId;
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H_ */
