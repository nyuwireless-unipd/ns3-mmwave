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

NS_LOG_COMPONENT_DEFINE ("MmWavePhyMacCommon");

NS_OBJECT_ENSURE_REGISTERED (MmWavePhyMacCommon);

TypeId
MmWavePhyMacCommon::GetTypeId (void)
{
	static TypeId tid = TypeId("ns3::MmWavePhyMacCommon")
			.SetParent<Object> ()
			.AddConstructor<MmWavePhyMacCommon> ()
			.AddAttribute ("SymbolPerSlot",
						   "Number of symbols per slot",
						   UintegerValue (30),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_symbolsPerSlot),
						   MakeUintegerChecker<uint32_t> ())
		   .AddAttribute ("CtrlSymbols",
							 "Number of OFDM symbols for DL control per subframe",
							 UintegerValue (1),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_ctrlSymbols),
							 MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SymbolPeriod",
						   "Symbol period in microseconds",
						   DoubleValue (4.16),
						   MakeDoubleAccessor (&MmWavePhyMacCommon::m_symbolPeriod),
						   MakeDoubleChecker<double> ())
			.AddAttribute ("SlotsPerSubframe",
						   "Number of slots in one subframe",
						   UintegerValue (8),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_slotsPerSubframe),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SubframePerFrame",
						   "Number of subframe per frame",
						   UintegerValue (10),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_subframesPerFrame),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SubcarriersPerChunk",
						   "Number of sub-carriers per chunk",
						   UintegerValue (48),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_numSubCarriersPerChunk),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("ChunkPerRB",
						   "Number of chunks comprising a resource block",
						   UintegerValue (9),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_chunksPerRb),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("ChunkWidth",
						   "Width of each chunk in Hz",
						   DoubleValue (13.889e6),
						   MakeDoubleAccessor (&MmWavePhyMacCommon::m_chunkWidth),
						   MakeDoubleChecker<double> ())
			.AddAttribute ("ResourceBlockNum",
						   "Number of resource blocks the entire bandwidth is split into",
						   UintegerValue (8),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_numRb),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("NumReferenceSymbols",
						   "Number of reference symbols per slot",
						   UintegerValue (6),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_numRefSymbols),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("CenterFreq",
						   "The center frequency in Hz",
						   DoubleValue (28e9),
						   MakeDoubleAccessor (&MmWavePhyMacCommon::m_centerFrequency),
						   MakeDoubleChecker<double> ())
			.AddAttribute ("TDDPattern",
						   "The control-data pattern for TDD transmission",
						   StringValue ("ccdddddd"),
						   MakeStringAccessor (&MmWavePhyMacCommon::m_staticTddPattern),
						   MakeStringChecker ())
		  .AddAttribute ("UlSchedDelay",
							 "Number of TTIs between UL scheduling decision and subframe to which it applies",
							 UintegerValue (3),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_ulSchedDelay),
							 MakeUintegerChecker<uint32_t> ())
		  .AddAttribute ("NumRbPerRbg",
							 "Number of resource blocks per resource block group",
							 UintegerValue (1),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_numRbPerRbg),
							 MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("WbCqiPeriod",
							 "Microseconds between wideband DL-CQI reports",
							 DoubleValue (500.0),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_wbCqiPeriodUs),
							 MakeUintegerChecker<double> ())
		 .AddAttribute ("GuardPeriod",
							 "Guard period for UL to DL slot transition in microseconds",
							 DoubleValue (4.16),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_guardPeriod),
							 MakeUintegerChecker<double> ())
		 .AddAttribute ("NumHarqProcess",
							 "Number of concurrent stop-and-wait Hybrid ARQ processes per user",
							 UintegerValue (20),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_numHarqProcess),
							 MakeUintegerChecker<uint8_t> ())
		 .AddAttribute ("HarqDlTimeout",
							 "Number of concurrent stop-and-wait Hybrid ARQ processes per user",
							 UintegerValue (20),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_harqTimeout),
							 MakeUintegerChecker<uint8_t> ())
	;

	return tid;
}

MmWavePhyMacCommon::MmWavePhyMacCommon ()
: m_symbolsPerSlot (30),
  m_symbolPeriod (4.16),
  m_ctrlSymbols (1),
  m_slotsPerSubframe (8),
  m_subframesPerFrame (10),
  m_numRefSymbols (6),
	m_numRbPerRbg (4),
  m_numSubCarriersPerChunk (48),
  m_chunksPerRb (18),
  m_chunkWidth (14e6),
  m_numRb (20),
  m_numHarqProcess (20),
  m_harqTimeout (20),
  m_centerFrequency (28e9),
	m_guardPeriod (4.16),
  m_l1L2CtrlLatency (2),
  m_l1L2DataLatency (3),
	m_wbCqiPeriodUs (500)
{
	NS_LOG_INFO ("Initialized MmWavePhyMacCommon");
}
MmWavePhyMacCommon::~MmWavePhyMacCommon (void)
{

}

uint32_t
MmWavePhyMacCommon::GetSymbPerSlot (void)
{
	return m_symbolsPerSlot;
}

double
MmWavePhyMacCommon::GetSymbolPeriod (void)
{
	return m_symbolPeriod;
}

uint32_t
MmWavePhyMacCommon::GetCtrlSymbols (void)
{
	return m_ctrlSymbols;
}

double
MmWavePhyMacCommon::GetTti (void)
{
	return (m_symbolsPerSlot*m_symbolPeriod*1e-6);
}

uint32_t
MmWavePhyMacCommon::GetSlotsPerSubframe (void)
{
	return m_slotsPerSubframe;
}
uint32_t
MmWavePhyMacCommon::GetSubframesPerFrame (void)
{
	return m_subframesPerFrame;
}

uint32_t
MmWavePhyMacCommon::GetNumReferenceSymbols (void)
{
	return m_numRefSymbols;
}

double
MmWavePhyMacCommon::GetGuardPeriod (void)
{
	return m_guardPeriod;
}

uint8_t
MmWavePhyMacCommon::GetUlSchedDelay (void)
{
	return m_ulSchedDelay;
}

uint32_t
MmWavePhyMacCommon::GetNumSCperChunk (void)
{
	return m_numSubCarriersPerChunk;
}


double
MmWavePhyMacCommon::GetChunkWidth (void)
{
	return m_chunkWidth;
}

uint32_t
MmWavePhyMacCommon::GetNumChunkPerRb (void)
{
	return m_chunksPerRb;
}
uint32_t
MmWavePhyMacCommon::GetNumRb (void)
{
	return m_numRb;
}

uint32_t
MmWavePhyMacCommon::GetNumRbPerRbg (void)
{
	return m_numRbPerRbg;
}

double
MmWavePhyMacCommon::GetRBWidth (void)
{
	return (m_chunksPerRb*m_chunkWidth);
}

double
MmWavePhyMacCommon::GetSystemBandwidth (void)
{
	return (GetRBWidth ()*m_numRb);
}

uint32_t
MmWavePhyMacCommon::GetTotalNumChunk ()
{
	return (m_chunksPerRb*m_numRb);
}

double
MmWavePhyMacCommon::GetCentreFrequency (void)
{
	return m_centerFrequency;
}

uint32_t
MmWavePhyMacCommon::GetL1L2CtrlLatency (void)
{
	return m_l1L2CtrlLatency;
}

uint32_t
MmWavePhyMacCommon::GetL1L2DataLatency (void)
{
	return m_l1L2DataLatency;
}

double
MmWavePhyMacCommon::GetWbCqiPeriodUs (void)
{
	return m_wbCqiPeriodUs;
}

std::string
MmWavePhyMacCommon::GetStaticTDDPattern ()
{
	return m_staticTddPattern;
}

uint32_t
MmWavePhyMacCommon::GetNumHarqProcess (void)
{
	return m_numHarqProcess;
}

uint8_t
MmWavePhyMacCommon::GetHarqTimeout (void)
{
	return m_harqTimeout;
}

void
MmWavePhyMacCommon::SetSymbPerSlot (uint32_t numSym)
{
	m_symbolsPerSlot = numSym;
}

void
MmWavePhyMacCommon::SetSymbolPeriod (double prdSym)
{
	m_symbolPeriod = prdSym;
}

void
MmWavePhyMacCommon::SetCtrlSymbols (uint32_t ctrlSymbols)
{
	m_ctrlSymbols = ctrlSymbols;
}

void
MmWavePhyMacCommon::SetSlotPerSubframe (uint32_t numSlot)
{
	m_slotsPerSubframe = numSlot;
}

void
MmWavePhyMacCommon::SetSubframePerFrame (uint32_t numSf)
{
	m_subframesPerFrame = numSf;
}

void
MmWavePhyMacCommon::SetNumReferenceSymbols (uint32_t refSym)
{
	m_numRefSymbols = refSym;
}

void
MmWavePhyMacCommon::SetGuardPeriod (double usec)
{
	m_guardPeriod = usec;
}

void
MmWavePhyMacCommon::SetUlSchedDelay (uint32_t tti)
{
	m_ulSchedDelay = tti;
}

void
MmWavePhyMacCommon::SetNumSCperChunk (uint32_t numSC)
{
	m_numSubCarriersPerChunk = numSC;
}

void
MmWavePhyMacCommon::SetNumChunkPerRB (uint32_t numChunk)
{
	m_chunksPerRb = numChunk;
}

void
MmWavePhyMacCommon::SetChunkWidth (double chumkWidth)
{
	m_chunkWidth = chumkWidth;
}
void
MmWavePhyMacCommon::SetNumRb (uint32_t numRB)
{
	m_numRb = numRB;
}

void
MmWavePhyMacCommon::SetNumRbPerRbg (uint32_t numRB)
{
	m_numRbPerRbg = numRB;
}

void
MmWavePhyMacCommon::SetCentreFrequency (double fc)
{
	m_centerFrequency = fc;
}

void
MmWavePhyMacCommon::SetL1L2CtrlLatency (uint32_t delaySfs)
{
	m_l1L2CtrlLatency = delaySfs;
}

void
MmWavePhyMacCommon::SetL1L2DataLatency (uint32_t delaySlots)
{
	m_l1L2DataLatency = delaySlots;
}

void
MmWavePhyMacCommon::SetWbCqiPeriodUs (double us)
{
	m_wbCqiPeriodUs = us;
}

void
MmWavePhyMacCommon::SetStaticTDDPattern (std::string p)
{
	if (p.length () != m_slotsPerSubframe)
	{
		NS_LOG_ERROR ("TDD pattern length should be equal to the number of slots per SF");
	}
	m_staticTddPattern = p;
}

void
MmWavePhyMacCommon::SetNumHarqProcess (uint32_t numProcess)
{
	m_numHarqProcess = numProcess;
}

void
MmWavePhyMacCommon::SetHarqDlTimeout (uint8_t harqDlTimeout)
{
	m_harqTimeout = harqDlTimeout;
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
L1toL2Messages::SetTxOpportunityInfo (SlotAllocInfo allocMap)
{
	m_TxOpportunity = allocMap;
}

void
L1toL2Messages::RequestRbAllocationMap (bool req)
{
	m_GetRbAllocationMap = req;
}

bool
L1toL2Messages::IsRbAllocationMapRequested ()
{
	return m_GetRbAllocationMap;
}

SlotAllocInfo
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
L2toL1Messages::SetTDDPattern (TddSlotTypeList pattern, SFNSF sf)
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


