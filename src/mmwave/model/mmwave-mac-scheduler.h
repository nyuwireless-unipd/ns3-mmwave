/*
 * mmwave-mac-scheduler.h
 *
 *  Created on: Jan 10, 2015
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHEDULER_H_
#define SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHEDULER_H_

#include <ns3/object.h>
#include "mmwave-phy.h"
#include "mmwave-phy-mac-common.h"
#include "mmwave-mac-sched-sap.h"
#include <ns3/string.h>
#include <ns3/math.h>
#include <ns3/enum.h>

namespace ns3 {

class MacSchedSapProvider;
class MacSchedSapUser;

class mmWaveMacScheduler : public Object
{
public:
	mmWaveMacScheduler ();

	virtual ~mmWaveMacScheduler ();
	virtual void DoDispose (void);
	static TypeId GetTypeId (void);

	virtual void ConfigureCommonParameters (Ptr<mmWavePhyMacCommon> config) = 0;

	virtual void SetMacSchedSapUser (mmWaveMacSchedSapUser* sap) = 0;

	virtual mmWaveMacSchedSapProvider* GetMacSchedSapProvider () = 0;

protected:

	std::string m_TDDPattern;
	Ptr<mmWavePhyMacCommon> m_PhyMACConfig;
};

}
#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHEDULER_H_ */
