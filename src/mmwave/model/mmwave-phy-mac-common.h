/*
 * mmwave-phy-mac-common.h
 *
 *  Created on: Jan 10, 2015
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H_
#define SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H_

#include <vector>
#include <list>
#include <map>
#include <ns3/object.h>
#include <ns3/packet.h>
#include <ns3/string.h>
#include "mmwave-mac-pdu-header.h"

namespace ns3 {

struct SFNSF
{
	uint16_t m_frameNum;
	uint16_t m_subFrameNum;
	uint16_t m_slotNum;
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

struct MacPduInfo
{
	MacPduInfo (uint16_t frameNum, uint8_t sfNum, uint8_t slotNum, uint32_t size, uint8_t numRlcPdu)
	{
		m_frameNum = frameNum;
		m_sfNum = sfNum;
		m_slotNum = slotNum;
		m_numRlcPdu = numRlcPdu;
		m_size = size;
		m_pdu = Create<Packet> ();
		m_macHeader = MmWaveMacPduHeader (frameNum, sfNum, slotNum);
	}

	uint16_t m_frameNum;
	uint8_t m_sfNum;
	uint8_t	m_slotNum;
	uint8_t m_numRlcPdu;
	uint32_t m_size;
	Ptr<Packet> m_pdu;
	MmWaveMacPduHeader m_macHeader;
};

struct TbInfoElement
{
	uint8_t   m_slotInd;		// slot index
	uint32_t  m_rbBitmap;		// Resource Block Group bitmap
	uint8_t   m_rbShift;		// shift for res alloc type 1
	uint8_t		m_rbStart;		// starting RB index for uplink res alloc type 0
	uint16_t	m_rbLen;
	uint8_t   m_resAlloc;		// resource allocation type
	uint8_t		m_mcs;
	uint32_t	m_tbSize;
	uint8_t		m_ndi;
	uint8_t		m_rv;
	uint8_t   m_harqProcess;
};

struct TbAllocInfo
{
	TbAllocInfo () :
		m_rnti (0)
	{

	}
	uint16_t m_rnti;
	std::vector<unsigned> m_rbMap;
	TbInfoElement m_tbInfo;
};

struct DciInfoElement
{
	uint16_t  m_rnti;
	uint8_t   m_cceIndex;
	uint8_t		m_format;			// to support different DCI types
	uint16_t	m_tddBitmap;	// 0 == DL, 1 == UL
	std::vector<TbInfoElement> m_tbInfoElements;
};

struct SlotAllocInfo
{
	enum TddMode
	{
		NA = 0,
		DL = 1,
		UL = 2,
	};

	enum TddSlotType
	{
		CTRL_DATA = 0,
		DATA = 1,
		CTRL = 2
	};


	SlotAllocInfo (uint8_t slotInd, TddMode tddMode, TddSlotType slotType) :
		m_tddMode(tddMode), m_isOmni (0), m_slotType (slotType), m_numCtrlSym(0), m_slotInd (slotInd)
	{

	}

	std::vector<TbAllocInfo> m_tbInfo;
	std::map<uint16_t, std::vector<unsigned> > m_ueRbMap;

	TddMode m_tddMode; 					// If set to false implies DL
	bool m_isOmni; 	// Beamforming disabled, true if omnidirectional
	TddSlotType m_slotType;
	uint8_t m_numCtrlSym;
	uint8_t m_slotInd;
};

struct SfAllocationInfo
{
	SfAllocationInfo ()
	{
		m_tddPattern.resize (8);
	}

	SfAllocationInfo (unsigned int numSlots)
	{
		m_tddPattern.resize (numSlots, SlotAllocInfo::NA);
		for (unsigned i = 0; i < numSlots; i++)
		{
			m_slotAllocInfo.push_back (SlotAllocInfo (i+1, SlotAllocInfo::NA, SlotAllocInfo::DATA));
		}
		// first slot always set to Downlink CTRL + DATA
		m_slotAllocInfo[0].m_tddMode = SlotAllocInfo::DL;
		m_slotAllocInfo[0].m_slotType = SlotAllocInfo::CTRL_DATA;
		m_slotAllocInfo[0].m_numCtrlSym = 1;
	}

	std::vector <SlotAllocInfo::TddMode> m_tddPattern;
	std::vector <SlotAllocInfo> m_slotAllocInfo;
};


typedef std::vector<SlotAllocInfo::TddSlotType> TddSlotTypeList;


struct DlCqiInfo
{
  uint16_t  m_rnti;
  uint8_t   m_ri;
  enum DlCqiType
  {
    WB,SB
  } m_cqiType;
	std::vector<uint8_t> m_rbCqi; // CQI for each Rsc Block, set to -1 if SINR < Threshold
	uint8_t m_wbCqi; // Wide band CQI
	uint8_t m_wbPmi;
};


struct UlCqiInfo
{
  std::vector <uint16_t> m_sinr;
  enum UlCqiType
  {
    SRS,
    PUSCH,
    PUCCH_1,
    PUCCH_2,
    PRACH
  } m_type;
};

struct MacCeValue
{
  uint8_t   m_phr;
  uint8_t   m_crnti;
  std::vector <uint8_t> m_bufferStatus;
};

/**
 * \brief See section 4.3.14 macCEListElement
 */
struct MacCeElement
{
  uint16_t  m_rnti;
  enum MacCeType
  {
    BSR, PHR, CRNTI
  } m_macCeType;
  struct MacCeValue m_macCeValue;
};

struct RlcPduInfo
{
	RlcPduInfo (): m_lcid (0), m_size (0)
	{
	}

	RlcPduInfo (uint8_t lcid, uint16_t size) :
		m_lcid (lcid), m_size (size)
	{
	}
  uint8_t   m_lcid;
  uint16_t  m_size;
};

struct RlcListElement
{
	std::vector <struct RlcPduInfo> m_rlcPduElements;
};

struct SchedInfoElement
{
	SchedInfoElement () :
		m_frameNum (0), m_sfNum (0), m_rnti (0)
	{
	}
	SchedInfoElement (unsigned int numSlots) :
		m_frameNum (0), m_sfNum (0), m_rnti (0)
	{
	}

	uint16_t	m_frameNum;
	uint8_t	  m_sfNum;
  uint16_t  m_rnti;
  struct DciInfoElement m_dci;
  std::vector<std::vector<struct RlcPduInfo > > m_rlcPduList; // RLC PDU elems for each MAC TB
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

struct DlHarqInfo
{
  uint16_t  m_rnti;
  uint8_t   m_harqProcessId;
  enum HarqStatus
  {
    ACK, NACK
  };
  std::vector <enum HarqStatus> m_harqStatus;
};

struct UlHarqInfo
{
  uint16_t  m_rnti;
  std::vector <uint16_t> m_ulReception;
  enum ReceptionStatus
  {
    Ok, NotOk, NotValid
  } m_receptionStatus;
  uint8_t   m_tpc;
};


class MmWavePhyMacCommon : public Object
{
public:
	MmWavePhyMacCommon (void);
	~MmWavePhyMacCommon (void);

	static TypeId GetTypeId (void);

	uint32_t 	GetSymbPerSlot (void);
	double 		GetSymbolPeriod (void);
	uint32_t	GetCtrlSymbols (void);
	double 		GetTti (void);
	uint32_t 	GetSlotsPerSubframe (void);
	uint32_t 	GetSubframesPerFrame (void);
	uint32_t 	GetNumReferenceSymbols (void);
	double 		GetGuardPeriod (void);
	uint8_t 	GetUlSchedDelay (void);

	uint32_t 	GetNumSCperChunk (void);
	uint32_t 	GetNumChunkPerRb (void);
	double 		GetChunkWidth (void);
	uint32_t 	GetNumRb (void);
	uint32_t 	GetNumRbPerRbg (void);
	double 		GetRBWidth (void);
	double 		GetSystemBandwidth (void);
	double 		GetCentreFrequency (void);
	uint32_t 	GetTotalNumChunk (void);
	uint32_t 	GetL1L2CtrlLatency (void);
	uint32_t	 	GetL1L2DataLatency (void);
	double	GetWbCqiPeriodUs (void);
	std::string GetStaticTDDPattern ();
	uint32_t	 	GetNumHarqProcess (void);
	uint8_t GetHarqTimeout (void);

	void SetSymbPerSlot (uint32_t sym);
	void SetSymbolPeriod (double prd);
	void SetCtrlSymbols (uint32_t prd);
	void SetSlotPerSubframe (uint32_t numSlot);
	void SetSubframePerFrame (uint32_t numSf);
	void SetNumReferenceSymbols (uint32_t numRefSym);
	void SetGuardPeriod (double prd);
	void SetUlSchedDelay (uint32_t tti);

	void SetNumSCperChunk (uint32_t numSC);
	void SetNumChunkPerRB (uint32_t numChunk);
	void SetChunkWidth (double width);
	void SetNumRb (uint32_t numRb);
	void SetNumRbPerRbg (uint32_t numRbPerRbg);
	void SetCentreFrequency (double fc);
	void SetL1L2CtrlLatency (uint32_t delaySf);
	void SetL1L2DataLatency (uint32_t delaySlot);
	void SetWbCqiPeriodUs (double us);
	void SetStaticTDDPattern (std::string p);
	void SetNumHarqProcess (uint32_t numProc);
	void SetHarqDlTimeout (uint8_t harqDlTimeout);

private:
	uint32_t m_symbolsPerSlot;
	double   m_symbolPeriod; // in micro seconds
	uint32_t m_ctrlSymbols;  // num OFDM symbols for downlink control at beginning of subframe
	uint32_t m_slotsPerSubframe;
	uint32_t m_subframesPerFrame;
	uint32_t m_numRefSymbols;
  uint32_t m_numRbPerRbg;

	uint32_t m_numSubCarriersPerChunk;
	uint32_t m_chunksPerRb;
	double m_chunkWidth; //enter in Hz.
	uint32_t m_numRb;
	uint8_t m_numHarqProcess;
	uint8_t m_harqTimeout;

	double m_centerFrequency;
	double   m_guardPeriod; 		// UL to DL switching time in micro seconds

	uint32_t m_l1L2CtrlLatency; // In no. of sub-frames
	uint32_t m_l1L2DataLatency; // In no. of slots
	uint32_t m_ulSchedDelay;	// delay between transmission of UL-DCI and corresponding subframe in TTIs
	uint32_t m_wbCqiPeriodUs;	// WB CQI periodicity in microseconds

	std::string m_staticTddPattern;
};

}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H_ */
