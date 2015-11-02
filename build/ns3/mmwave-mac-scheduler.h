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
#include <ns3/abort.h>

namespace ns3 {

class MacSchedSapProvider;
class MacSchedSapUser;

static const uint32_t BufferSizeLevelBsrTable[64] = {
  0, 10, 12, 14, 17, 19, 22, 26, 31, 36, 42, 49, 57, 67, 78, 91,
  107, 125, 146, 171, 200, 234, 274, 321, 376, 440, 515, 603,
  706, 826, 967, 1132, 1326, 1552, 1817, 2127, 2490, 2915, 3413,
  3995, 4677, 5476, 6411, 7505, 8787, 10287, 12043, 14099, 16507,
  19325, 22624, 26487, 31009, 36304, 42502, 49759, 58255,
  68201, 79846, 93749, 109439, 128125, 150000, 150000
};

class MmWaveMacScheduler : public Object
{
public:
	MmWaveMacScheduler ();
	virtual ~MmWaveMacScheduler ();

	virtual void DoDispose (void);
	static TypeId GetTypeId (void);

	virtual void ConfigureCommonParameters (Ptr<MmWavePhyMacCommon> config) = 0;

	virtual void SetMacSchedSapUser (MmWaveMacSchedSapUser* sap) = 0;

	virtual MmWaveMacSchedSapProvider* GetMacSchedSapProvider () = 0;

protected:

	Ptr<MmWavePhyMacCommon> m_phyMacConfig;
	uint32_t m_rbgSize;		// RBs per RB group for res alloc type 0
	uint32_t m_numRbg;		// Total RBGs for res alloc type 0
};

}
#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHEDULER_H_ */
