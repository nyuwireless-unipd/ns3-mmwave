/*
 * mmwave-phy-mac-common.cc
 *
 *  Created on: Mar 16, 2015
 *      Author: sourjya
 */

#include <ns3/mmwave-phy-mac-common.h>
#include <ns3/log.h>
#include <ns3/uinteger.h>
#include <ns3/double.h>
#include <ns3/string.h>
#include <ns3/attribute-accessor-helper.h>
#include <ns3/simulator.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE ("mmWavePhyMacCommon");

NS_OBJECT_ENSURE_REGISTERED (mmWavePhyMacCommon);

TypeId
mmWavePhyMacCommon::GetTypeId (void)
{
	static TypeId tid = TypeId("ns3::mmWavePhyMacCommon")
			.SetParent<Object> ()
			.AddConstructor<mmWavePhyMacCommon> ()
			.AddAttribute ("SymbolPerSlot",
						   "Number of symbols per slot",
						   UintegerValue (30),
						   MakeUintegerAccessor (&mmWavePhyMacCommon::m_symbolsPerSlot),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SymbolPeriod",
						   "Symbol period in microseconds",
						   DoubleValue (4.16),
						   MakeDoubleAccessor (&mmWavePhyMacCommon::m_symbolPeriod),
						   MakeDoubleChecker<double> ())
			.AddAttribute ("SlotsPerSubframe",
						   "Number of slots in one subframe",
						   UintegerValue (8),
						   MakeUintegerAccessor (&mmWavePhyMacCommon::m_slotsPerSubframe),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SubframePerFrame",
						   "Number of subframe per frame",
						   UintegerValue (10),
						   MakeUintegerAccessor (&mmWavePhyMacCommon::m_subframesPerFrame),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SubcarriersPerChunk",
						   "Number of sub-carriers per chunk",
						   UintegerValue (48),
						   MakeUintegerAccessor (&mmWavePhyMacCommon::m_numSubCarriersPerChunk),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("ChunkPerRB",
						   "Number of chunks comprising a resource block",
						   UintegerValue (18),
						   MakeUintegerAccessor (&mmWavePhyMacCommon::m_chunksPerRB),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("ChunkWidth",
						   "Width of each chunk in Hz",
						   DoubleValue (13.889e6),
						   MakeDoubleAccessor (&mmWavePhyMacCommon::m_chunkWidth),
						   MakeDoubleChecker<double> ())
			.AddAttribute ("ResourceBlockNum",
						   "Number of resource blocks the entire bandwidth is split into",
						   UintegerValue (4),
						   MakeUintegerAccessor (&mmWavePhyMacCommon::m_rscBlocksPerSlot),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("NumReferenceSymbols",
						   "Number of reference symbols per slot",
						   UintegerValue (6),
						   MakeUintegerAccessor (&mmWavePhyMacCommon::m_numRefSymbols),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("CentreFreq",
						   "The center frequency in Hz",
						   DoubleValue (28e9),
						   MakeDoubleAccessor (&mmWavePhyMacCommon::m_centreFrequency),
						   MakeDoubleChecker<double> ())
			.AddAttribute ("TDDPattern",
						   "The control-data pattern for TDD transmission",
						   StringValue ("ccdddddd"),
						   MakeStringAccessor (&mmWavePhyMacCommon::m_staticTddPattern),
						   MakeStringChecker ())

	;

	return tid;
}

mmWavePhyMacCommon::mmWavePhyMacCommon ()
: m_symbolsPerSlot (30),
  m_symbolPeriod (4.16),
  m_slotsPerSubframe (8),
  m_subframesPerFrame (10),
  m_numRefSymbols (6),
  m_numSubCarriersPerChunk (48),
  m_chunksPerRB (18),
  m_chunkWidth (14e6),
  m_rscBlocksPerSlot (4),
  m_centreFrequency (28e9),
  m_L1L2CtrlLatency (2),
  m_L1L2DataLatency (3)
{
	NS_LOG_INFO ("Initialized mmWavePhyMacCommon");
}
mmWavePhyMacCommon::~mmWavePhyMacCommon (void)
{

}

uint32_t
mmWavePhyMacCommon::GetSymbPerSlot (void)
{
	return m_symbolsPerSlot;
}

double
mmWavePhyMacCommon::GetSymbolPeriod (void)
{
	return m_symbolPeriod;
}

double
mmWavePhyMacCommon::GetTTI (void)
{
	return (m_symbolsPerSlot*m_symbolPeriod*1e-6);
}

uint32_t
mmWavePhyMacCommon::GetSlotPerSubframe (void)
{
	return m_slotsPerSubframe;
}
uint32_t
mmWavePhyMacCommon::GetSubframePerFrame (void)
{
	return m_subframesPerFrame;
}

uint32_t
mmWavePhyMacCommon::GetNumReferenceSymbols (void)
{
	return m_numRefSymbols;
}

uint32_t
mmWavePhyMacCommon::GetNumSCperChunk (void)
{
	return m_numSubCarriersPerChunk;
}
double
mmWavePhyMacCommon::GetChunkWidth (void)
{
	return m_chunkWidth;
}

uint32_t
mmWavePhyMacCommon::GetNumChunkPerRB (void)
{
	return m_chunksPerRB;
}
uint32_t
mmWavePhyMacCommon::GetRBperSlot (void)
{
	return m_rscBlocksPerSlot;
}
double
mmWavePhyMacCommon::GetRBWidth (void)
{
	return (m_chunksPerRB*m_chunkWidth);
}
double
mmWavePhyMacCommon::GetSystemBandwidth (void)
{
	return (GetRBWidth ()*m_rscBlocksPerSlot);
}

uint32_t
mmWavePhyMacCommon::GetTotalNumChunk ()
{
	return (m_chunksPerRB*m_rscBlocksPerSlot);
}

double
mmWavePhyMacCommon::GetCentreFrequency (void)
{
	return m_centreFrequency;
}

uint32_t
mmWavePhyMacCommon::GetL1L2CtrlLatency (void)
{
	return m_L1L2CtrlLatency;
}

uint32_t
mmWavePhyMacCommon::GetL1L2DataLatency (void)
{
	return m_L1L2DataLatency;
}

std::string
mmWavePhyMacCommon::GetStaticTDDPattern ()
{
	return m_staticTddPattern;
}

void
mmWavePhyMacCommon::SetSymbPerSlot (uint32_t numSym)
{
	m_symbolsPerSlot = numSym;
}

void
mmWavePhyMacCommon::SetSymbolPeriod (double prdSym)
{
	m_symbolPeriod = prdSym;
}

void
mmWavePhyMacCommon::SetSlotPerSubframe (uint32_t numSlot)
{
	m_slotsPerSubframe = numSlot;
}

void
mmWavePhyMacCommon::SetSubframePerFrame (uint32_t numSf)
{
	m_subframesPerFrame = numSf;
}

void
mmWavePhyMacCommon::SetNumReferenceSymbols (uint32_t refSym)
{
	m_numRefSymbols = refSym;
}

void
mmWavePhyMacCommon::SetNumSCperChunk (uint32_t numSC)
{
	m_numSubCarriersPerChunk = numSC;
}

void
mmWavePhyMacCommon::SetNumChunkPerRB (uint32_t numChunk)
{
	m_chunksPerRB = numChunk;
}

void
mmWavePhyMacCommon::SetChunkWidth (double chumkWidth)
{
	m_chunkWidth = chumkWidth;
}
void
mmWavePhyMacCommon::SetRBperSlot (uint32_t numRB)
{
	m_rscBlocksPerSlot = numRB;
}

void
mmWavePhyMacCommon::SetCentreFrequency (double fc)
{
	m_centreFrequency = fc;
}

void
mmWavePhyMacCommon::SetL1L2CtrlLatency (uint32_t del)
{
	m_L1L2CtrlLatency = del;
}

void
mmWavePhyMacCommon::SetL1L2DataLatency (uint32_t del)
{
	m_L1L2DataLatency = del;
}

void
mmWavePhyMacCommon::SetStaticTDDPattern (std::string p)
{
	if (p.length () != m_slotsPerSubframe)
	{
		NS_LOG_ERROR ("TDD pattern length should be equal to the number of slots per SF");
	}
	m_staticTddPattern = p;
}

#if 0

/*
 *  Functions for L1toL2Messages
 */

L1toL2Messages::L1toL2Messages (void)
{
	NS_LOG_INFO ("Initialize L1toL2Messages ");
}
virtual
L1toL2Messages::~L1toL2Messages (void)
{
	NS_LOG_INFO (this);
}

void
L1toL2Messages::SetSFNSF (uint16_t f, uint16_t sf, uint16_t slot)
{
	m_subframeNum.m_frameNum = f;
	m_subframeNum.m_subFrameNum = sf;
	m_subframeNum.m_slotNum = slot;

}

SFNSF
L1toL2Messages::GetSFNSF (void)
{
	return m_subframeNum;
}

void
L1toL2Messages::RequestTDDPattern (bool req)
{
	m_GetTddPattern = req;
}

bool
L1toL2Messages::IsTDDPatternRequested (void)
{
	return m_GetTddPattern;
}

void
L1toL2Messages::SetTxOpportunityInfo (allocationMap allocMap)
{
	m_TxOpportunity = allocMap;
}

void
L1toL2Messages::RequestAllocationMap (bool req)
{
	m_GetAllocationMap = req;
}

bool
L1toL2Messages::IsAllocationMapRequested ()
{
	return m_GetAllocationMap;
}

allocationMap
L1toL2Messages::GetTxOpportunityInfo (void)
{
	return m_TxOpportunity;
}

void
L1toL2Messages::SetCQIReport (CQI cqi)
{
	m_CQiReport = cqi;
}

CQI
L1toL2Messages::GetCQIReport (void)
{
	return m_CQiReport;
}

void
L1toL2Messages::SetPacketBurst (Ptr<PacketBurst> pb)
{
	m_packetBurst = pb;
}

Ptr<PacketBurst>
L1toL2Messages::GetPAcketBurts (void)
{
	return m_packetBurst;
}

/**
 *  Functions for L2toL1Messages
 */

L2toL1Messages::L2toL1Messages (void)
{
	NS_LOG_INFO ("Initialize L2toL1Messages ");
}
L2toL1Messages::~L2toL1Messages (void)
{
	NS_LOG_INFO (this);
}

void
L2toL1Messages::SetTDDPattern (Schedule pattern, SFNSF sf)
{
	m_tddPatternforSF.m_SF = sf;
	m_tddPatternforSF.m_tddMap = pattern;
}

L2toL1Messages::patternForSF
L2toL1Messages::GetPatternForSubframe (void)
{
	return m_tddPatternforSF;
}

void
L2toL1Messages::SetAllocationList (L2toL1Messages::allocListForSF alloc)
{
	m_ULDLallocationList = alloc;
}

L2toL1Messages::allocListForSF
L2toL1Messages::GetAllocationList (void)
{
	return m_ULDLallocationList;
}

void
L2toL1Messages::SetPacketBurst (Ptr<PacketBurst> pb)
{
	m_packetBurst = pb;
}

Ptr<PacketBurst>
L2toL1Messages::GetPacketBurst (void)
{
	return m_packetBurst;
}

void
L2toL1Messages::SetIsDataReply (bool b)
{
	m_isDataReply = b;
}

bool
L2toL1Messages::IsDataReply ()
{
	return m_isDataReply;
}
#endif
}


