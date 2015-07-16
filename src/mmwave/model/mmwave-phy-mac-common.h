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
#include <ns3/object.h>
#include <ns3/packet.h>
#include <ns3/string.h>

namespace ns3 {

struct SFNSF
{
	uint16_t m_frameNum;
	uint16_t m_subFrameNum;
	uint16_t m_slotNum;
};

/* Equivalent to the DCI in LTE*/

struct AllocatedTo
{
	bool noAllocation;
	uint64_t userImsi;
	uint32_t m_tbsSize;
	int m_mcs;

	uint8_t m_harqProcess;
};

struct allocationMap
{
	/* Specifies which users the resource blocks are assigned to.
	 * The Scheduler populates the vector based on the number of
	 * RBs the entire band is divided in */
	std::vector<AllocatedTo> m_user;

	bool m_IsUL; // If set to false implies DL
};

struct allocationList
{
	std::list <allocationMap> m_AllocationMapforSF;
};

enum slotType
{
	CTRL = 0,
	DATA = 1
};

struct Schedule
{
	std::vector<slotType> m_slotType;
};

struct CqiInfo
{
	uint64_t m_ueId;
	std::vector<int> m_rbCqi; // CQI for each Rsc Block, set to -1 if SINR < Threshold
	uint16_t m_wbCqi; // Wide band CQI
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

class mmWavePhyMacCommon : public Object
{
public:
	mmWavePhyMacCommon (void);
	~mmWavePhyMacCommon (void);

	static TypeId GetTypeId (void);

	uint32_t GetSymbPerSlot (void);
	double GetSymbolPeriod (void);
	double GetTTI (void);
	uint32_t GetSlotPerSubframe (void);
	uint32_t GetSubframePerFrame (void);
	uint32_t GetNumReferenceSymbols (void);

	uint32_t GetNumSCperChunk (void);
	uint32_t GetNumChunkPerRB (void);
	double GetChunkWidth (void);
	uint32_t GetRBperSlot (void);
	double GetRBWidth (void);
	double GetSystemBandwidth (void);
	double GetCentreFrequency (void);
	uint32_t GetTotalNumChunk (void);
	uint32_t GetL1L2CtrlLatency (void);
	uint32_t GetL1L2DataLatency (void);

	std::string GetStaticTDDPattern ();

	void SetSymbPerSlot (uint32_t sym);
	void SetSymbolPeriod (double prd);
	void SetSlotPerSubframe (uint32_t numSlot);
	void SetSubframePerFrame (uint32_t numSf);
	void SetNumReferenceSymbols (uint32_t numRefSym);

	void SetNumSCperChunk (uint32_t numSC);
	void SetNumChunkPerRB (uint32_t numChunk);
	void SetChunkWidth (double width);
	void SetRBperSlot (uint32_t numRB);
	void SetCentreFrequency (double fc);
	void SetL1L2CtrlLatency (uint32_t del);
	void SetL1L2DataLatency (uint32_t del);

	void SetStaticTDDPattern (std::string p);


private:
	uint32_t m_symbolsPerSlot;
	double m_symbolPeriod; //enter in micro seconds
	uint32_t m_slotsPerSubframe;
	uint32_t m_subframesPerFrame;
	uint32_t m_numRefSymbols;

	uint32_t m_numSubCarriersPerChunk;
	uint32_t m_chunksPerRB;
	double m_chunkWidth; //enter in Hz.
	uint32_t m_rscBlocksPerSlot;

	double m_centreFrequency;

	uint32_t m_L1L2CtrlLatency; // In no. of sub-frames
	uint32_t m_L1L2DataLatency; // In no. of slots

	std::string m_staticTddPattern;
};

}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H_ */
