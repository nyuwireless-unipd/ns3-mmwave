/*
 * mmwave-rr-mac-scheduler.h
 *
 *  Created on: Jan 10, 2015
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_RR_MAC_SCHEDULER_H_
#define SRC_MMWAVE_MODEL_MMWAVE_RR_MAC_SCHEDULER_H_


#include "mmwave-mac-scheduler.h"
#include "mmwave-amc.h"
#include "string"
#include <vector>
#include <set>

namespace ns3 {

class mmWaveRRMacScheduler : public mmWaveMacScheduler
{
public:
	mmWaveRRMacScheduler ();

	virtual ~mmWaveRRMacScheduler ();
	virtual void DoDispose (void);
	static TypeId GetTypeId (void);

	virtual void SetMacSchedSapUser (mmWaveMacSchedSapUser* sap);

	virtual mmWaveMacSchedSapProvider* GetMacSchedSapProvider ();

	virtual void ConfigureCommonParameters (Ptr<mmWavePhyMacCommon> config);

	void DoSchedCqiInfoReq (const mmWaveMacSchedSapProvider::SchedCqiInfoReqParameters& params); // Put in UML

	void DoSchedTriggerReq (const struct mmWaveMacSchedSapProvider::SchedTriggerReqParameters& params); // Put in UML

	struct schedCqi
	{
		uint16_t m_wbCqi;
		std::vector<int> m_rbCqi;
	};

	friend class mmWaveRrMemberMacSchedSapProvider;

private:
	void SetTBSizeAssigned ();
	allocationList ScheduleUsersInTime (uint32_t slotNum);
	void SetScheduleDirection  (std::string patt);

	Schedule m_tddMap;

	Ptr<mmWaveAmc> m_amc;

	std::map <uint64_t, uint32_t> m_AssignedTBSizeMap;

	std::map <uint64_t, schedCqi> m_rxCqi;

	std::string m_directions; //UL or DL Need to to this in a better way
	bool m_isDirnUpdated;

	uint64_t m_NextUserDL;
	uint64_t m_NextUserUL;

	uint32_t m_SubframeNo;
	uint32_t m_FrameNo;

	mmWaveMacSchedSapProvider* m_macSchedSapProvider;
	mmWaveMacSchedSapUser* m_macSchedSapUser;
};

}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_RR_MAC_SCHEDULER_H_ */
