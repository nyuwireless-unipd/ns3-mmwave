/*
 * mmwave-mac-sched-sap.h
 *
 *  Created on: Apr 17, 2015
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHED_SAP_H_
#define SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHED_SAP_H_

#include "mmwave-phy-mac-common.h"
#include <set>

namespace ns3
{

class mmWaveMacSchedSapProvider
{
public:
	virtual ~mmWaveMacSchedSapProvider ();

	struct SchedCqiInfoReqParameters
	{
		uint32_t m_sfnsf;
		std::vector <struct CqiInfo> m_cqiList;
	};

	struct SchedTriggerReqParameters
	{
		uint32_t m_snfSf;
		std::list <uint64_t> m_ueList; // Add HARQ elements here...make a struct for this if needed
	};

	virtual void SchedTriggerReq (const struct SchedTriggerReqParameters& params) = 0;

	virtual void SchedCqiInfoReq (const struct SchedCqiInfoReqParameters& params) = 0;

private:

};

class mmWaveMacSchedSapUser
{
public:
	virtual ~mmWaveMacSchedSapUser ();

	struct SchedConfigIndParameters
	{
		uint32_t m_sfn;
		Schedule m_tddPattern;
		allocationList m_allocationList;
	};

	virtual void SchedConfigInd (const struct SchedConfigIndParameters& params) = 0;
private:
};

}

#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHED_SAP_H_ */
