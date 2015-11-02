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
#include <map>

namespace ns3
{

class MmWaveMacSchedSapProvider
{
public:
	virtual ~MmWaveMacSchedSapProvider ();

	struct SchedDlRlcBufferReqParameters
	{
		uint16_t  m_rnti;
		uint8_t   m_logicalChannelIdentity;
		uint32_t  m_rlcTransmissionQueueSize;
		uint16_t  m_rlcTransmissionQueueHolDelay;
		uint32_t  m_rlcRetransmissionQueueSize;
		uint16_t  m_rlcRetransmissionHolDelay;
		uint16_t  m_rlcStatusPduSize;
	};

	struct SchedDlCqiInfoReqParameters
	{
		uint32_t m_sfnsf;
		std::vector <struct DlCqiInfo> m_cqiList;
	};

  struct SchedUlMacCtrlInfoReqParameters
  {
    uint16_t  m_sfnSf;
    std::vector <struct MacCeElement> m_macCeList;
  };

  struct SchedUlCqiInfoReqParameters
  {
    uint32_t  m_sfnSf;
    struct UlCqiInfo m_ulCqi;
  };

	struct SchedTriggerReqParameters
	{
		uint32_t m_snfSf;
    std::vector <struct DlHarqInfo> m_dlHarqInfoList;
    std::vector <struct UlHarqInfo> m_ulHarqInfoList;
		std::list <uint16_t> m_ueList;
	};

  virtual void SchedDlRlcBufferReq (const struct SchedDlRlcBufferReqParameters& params) = 0;

	virtual void SchedDlCqiInfoReq (const SchedDlCqiInfoReqParameters& params) = 0;

	virtual void SchedUlCqiInfoReq (const struct SchedUlCqiInfoReqParameters& params) = 0;

	virtual void SchedTriggerReq (const struct SchedTriggerReqParameters& params) = 0;

  virtual void SchedUlMacCtrlInfoReq (const struct SchedUlMacCtrlInfoReqParameters& params) = 0;

private:

};

class MmWaveMacSchedSapUser
{
public:
	virtual ~MmWaveMacSchedSapUser ();

	struct SchedConfigIndParameters
	{
		uint32_t m_sfn;
//		TddSlotTypeList m_tddPattern;
//		SfAllocationInfo m_allocationList;

		std::map<uint16_t, SchedInfoElement> m_schedInfoMap;
	};

	virtual void SchedConfigInd (const struct SchedConfigIndParameters& params) = 0;
private:
};

}

#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHED_SAP_H_ */
