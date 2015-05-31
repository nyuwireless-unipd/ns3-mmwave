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

namespace ns3 {

class mmWavePhyRxTrace : public Object
{
public:
	mmWavePhyRxTrace();
	virtual ~mmWavePhyRxTrace();
	static TypeId GetTypeId (void);
	static void ReportCurrentCellRsrpSinrCallback (Ptr<mmWavePhyRxTrace> phyStats, std::string path,
						uint64_t imsi, SpectrumValue& sinr, SpectrumValue& power);

	static void ReportPacketCountUeCallback (Ptr<mmWavePhyRxTrace> phyStats, std::string path,
			UePhyPacketCountParameter param);
	static void ReportPacketCountEnbCallback (Ptr<mmWavePhyRxTrace> phyStats, std::string path,
			EnbPhyPacketCountParameter param);
	static void ReportDownLinkTBSize (Ptr<mmWavePhyRxTrace> phyStats, std::string path,
			uint64_t imsi, uint64_t tbSize);
private:
	void ReportInterferenceTrace (uint64_t imsi, SpectrumValue& sinr);
	void ReportPowerTrace (uint64_t imsi, SpectrumValue& power);
	void ReportPacketCountUe (UePhyPacketCountParameter param);
	void ReportPacketCountEnb (EnbPhyPacketCountParameter param);
	void ReportDLTbSize (uint64_t imsi, uint64_t tbSize);
};

} /* namespace ns3 */

#endif /* SRC_MMWAVE_HELPER_MMWAVE_PHY_RX_TRACE_H_ */
