/*
 * mmwave-phy-rx-race.h
 *
 *  Created on: Feb 2, 2015
 *      Author: macair
 */

#ifndef SRC_MMWAVE_HELPER_MMWAVE_PHY_RX_TRACE_H_
#define SRC_MMWAVE_HELPER_MMWAVE_PHY_RX_TRACE_H_
#include <ns3/object.h>
#include <ns3/spectrum-value.h>
#include <ns3/mmwave-phy-mac-common.h>
#include <fstream>
#include <iostream>

namespace ns3 {

class MmWavePhyRxTrace : public Object
{
public:
	MmWavePhyRxTrace();
	virtual ~MmWavePhyRxTrace();
	static TypeId GetTypeId (void);
	static void ReportCurrentCellRsrpSinrCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path,
						uint64_t imsi, SpectrumValue& sinr, SpectrumValue& power);
	static void UlSinrTraceCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path,
							uint64_t imsi, SpectrumValue& sinr, SpectrumValue& power);
	static void ReportPacketCountUeCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path,
			UePhyPacketCountParameter param);
	static void ReportPacketCountEnbCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path,
			EnbPhyPacketCountParameter param);
	static void ReportDownLinkTBSize (Ptr<MmWavePhyRxTrace> phyStats, std::string path,
			uint64_t imsi, uint64_t tbSize);
	static void RxPacketTraceUeCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path, RxPacketTraceParams param);
	static void RxPacketTraceEnbCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path, RxPacketTraceParams param);

private:
	void ReportInterferenceTrace (uint64_t imsi, SpectrumValue& sinr);
	void ReportPowerTrace (uint64_t imsi, SpectrumValue& power);
	void ReportPacketCountUe (UePhyPacketCountParameter param);
	void ReportPacketCountEnb (EnbPhyPacketCountParameter param);
	void ReportDLTbSize (uint64_t imsi, uint64_t tbSize);

	static std::ofstream m_rxPacketTraceFile;
	static std::string m_rxPacketTraceFilename;
};

} /* namespace ns3 */

#endif /* SRC_MMWAVE_HELPER_MMWAVE_PHY_RX_TRACE_H_ */
