/*
 * mmwave-rr-mac-scheduler.cc
 *
 *  Created on: Jan 11, 2015
 *      Author: sourjya
 */

#include <ns3/log.h>
#include <ns3/abort.h>
#include "mmwave-rr-mac-scheduler.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("mmWaveRRMacScheduler");

NS_OBJECT_ENSURE_REGISTERED (mmWaveRRMacScheduler);

class mmWaveRrMemberMacSchedSapProvider : public mmWaveMacSchedSapProvider
{
public:
	mmWaveRrMemberMacSchedSapProvider (mmWaveRRMacScheduler* sched);

	virtual void SchedTriggerReq (const struct SchedTriggerReqParameters& params);
	virtual void SchedCqiInfoReq (const struct SchedCqiInfoReqParameters& params);

private:
	mmWaveRRMacScheduler* m_scheduler;
};

mmWaveRrMemberMacSchedSapProvider::mmWaveRrMemberMacSchedSapProvider (mmWaveRRMacScheduler* sched)
	:m_scheduler(sched)
{

}

void
mmWaveRrMemberMacSchedSapProvider::SchedTriggerReq (const struct SchedTriggerReqParameters& params)
{
	m_scheduler->DoSchedTriggerReq(params);
}

void
mmWaveRrMemberMacSchedSapProvider::SchedCqiInfoReq (const struct SchedCqiInfoReqParameters& params)
{
	m_scheduler->DoSchedCqiInfoReq (params);
}

mmWaveRRMacScheduler::mmWaveRRMacScheduler ()
: m_directions (""),
  m_isDirnUpdated (false),
  m_NextUserDL (0),
  m_NextUserUL (0),
  m_SubframeNo (0),
  m_macSchedSapUser (0)
{
	NS_LOG_FUNCTION (this);

	m_macSchedSapProvider = new mmWaveRrMemberMacSchedSapProvider (this);
}

mmWaveRRMacScheduler::~mmWaveRRMacScheduler ()
{
	NS_LOG_FUNCTION (this);
}

void
mmWaveRRMacScheduler::DoDispose (void)
{
	NS_LOG_FUNCTION (this);
	m_AssignedTBSizeMap.clear();
	m_rxCqi.clear();
	//m_directions.clear ();
}

TypeId
mmWaveRRMacScheduler::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::mmWaveRRMacScheduler")
	    .SetParent<mmWaveMacScheduler> ()
		.AddConstructor<mmWaveRRMacScheduler> ()
		;

	return tid;
}

void
mmWaveRRMacScheduler::SetMacSchedSapUser (mmWaveMacSchedSapUser* sap)
{
	m_macSchedSapUser = sap;
}

mmWaveMacSchedSapProvider*
mmWaveRRMacScheduler::GetMacSchedSapProvider ()
{
	return m_macSchedSapProvider;
}

void
mmWaveRRMacScheduler::ConfigureCommonParameters (Ptr<mmWavePhyMacCommon> config)
{
	m_PhyMACConfig = config;
	m_amc = CreateObject <mmWaveAmc> (m_PhyMACConfig);
}

void
mmWaveRRMacScheduler::DoSchedCqiInfoReq (const mmWaveMacSchedSapProvider::SchedCqiInfoReqParameters& params)
{
	std::map <uint64_t, schedCqi>::iterator it;
	for (uint32_t i = 0; i < params.m_cqiList.size (); i++)
	{
		CqiInfo cqi = params.m_cqiList.at (i);
		it = m_rxCqi.find (cqi.m_ueId);
		schedCqi element;
		element.m_rbCqi = cqi.m_rbCqi;
		element.m_wbCqi = cqi.m_wbCqi;
		if (it == m_rxCqi.end ())
		{
			m_rxCqi.insert (std::pair <uint64_t, schedCqi> (cqi.m_ueId, element) );
		}
		else
		{
			(*it).second = element;
		}

	}
}

/**/
void
mmWaveRRMacScheduler::SetScheduleDirection  (std::string patt)
{
	uint16_t ctrlCount = 0;

	for (uint16_t i = 0; i<patt.length(); i++)
	{
		if (patt.at(i) == 'c')
		{
			std::string ch = ((ctrlCount%2 == 0) ? "D":"U");
			m_directions+= (ch);
			ctrlCount++;
		}
		else if (patt.at(i) == 'd')
		{
			std::string ch1 = ( (i < (patt.length () + ctrlCount)/2) ? "D" : "U");
			m_directions+=  ch1;
		}
	}

	m_isDirnUpdated = true;/*
	m_directions = "CCDDDUUU";
	m_isDirnUpdated = true;*/
}

void
mmWaveRRMacScheduler::DoSchedTriggerReq (const struct mmWaveMacSchedSapProvider::SchedTriggerReqParameters& params)
{
	NS_LOG_INFO ("Frame Num"<< (params.m_snfSf >> 16) <<" Subframe Num:" << ((params.m_snfSf & 0xff00)>>8) );

	mmWaveMacSchedSapUser::SchedConfigIndParameters ret;
	Schedule pattern;
	allocationList allocList;
	std::list <uint64_t> usrList = params.m_ueList;
	std::list<uint64_t>::iterator dlit = usrList.begin ();
	std::list<uint64_t>::iterator ulit = usrList.begin ();

	if (usrList.size() == 0)
	{
		/* No users associated hence no scheduling*/
		return;
	}
	std::string strPattern = m_PhyMACConfig->GetStaticTDDPattern();
	for (uint16_t loop = 0; loop < strPattern.length(); loop++)
	{
		char type = strPattern.at(loop);
		if (type == 'c')
		{
			pattern.m_slotType.push_back (CTRL);
		}
		else if (type == 'd')
		{
			pattern.m_slotType.push_back (DATA);
		}
		else
		{
			NS_LOG_ERROR ("Error in TDD pattern entry");
		}
	}

	if (!m_isDirnUpdated)
	{
		SetScheduleDirection (strPattern);
	}


	if (m_NextUserDL != 0 || m_NextUserUL != 0)
	{
		uint16_t count = 0;
		std::list <uint64_t>::iterator it;
		for (it = usrList.begin (); it != usrList.end (); it++)
		{
			if (*it == m_NextUserDL)
			{
				dlit = it;
				count++;
			}

			if (*it == m_NextUserUL)
			{
				ulit = it;
				count++;
			}

			if (count == 2) { break; }
		}
	}


	for (uint32_t i = 0; i < m_PhyMACConfig->GetSlotPerSubframe (); i++)
	{
		allocationMap alMap;
		alMap.m_IsUL = (m_directions[i] == 'U') ? true : false;

		if (pattern.m_slotType.at (i) == CTRL)
		{
			for (uint16_t j = 0; j < m_PhyMACConfig->GetRBperSlot(); j++)
			{
				AllocatedTo user;
				// Assume omni-directional control messages
				user.noAllocation = true;
				user.userImsi = 0;
				alMap.m_user.push_back (user);
			}
		}
		else
		{
			for (uint16_t j = 0; j < m_PhyMACConfig->GetRBperSlot(); j++)
			{
				// Assume omni-directional control messages
				AllocatedTo user;
				user.userImsi = alMap.m_IsUL ? (*ulit) : (*dlit);

				int cqi = 1;
				if (!m_rxCqi.empty())
				{
					std::map <uint64_t, schedCqi>::iterator mapIt = m_rxCqi.find(user.userImsi);

					if (mapIt == m_rxCqi.end ())
					{
						cqi = 1;
					}
					else
					{
						schedCqi userCqiInfo = (*mapIt).second;
						cqi = userCqiInfo.m_wbCqi;
					}
				}
				user.m_mcs = m_amc->GetMcsFromCqi(cqi);
				user.m_tbsSize = (m_amc->GetTbSizeFromMcs (user.m_mcs, 1/*m_PhyMACConfig->GetNumChunkPerRB ()*/) / 8);

				alMap.m_user.push_back (user);

			}
			if (alMap.m_IsUL)
			{
				ulit++;
				ulit = (ulit != usrList.end ()) ? ulit : usrList.begin ();
			}
			else
			{
				dlit++;
				dlit = (dlit != usrList.end ()) ? dlit : usrList.begin ();
			}

		}
		allocList.m_AllocationMapforSF.push_back (alMap);
	}

	m_NextUserDL = (*dlit);
	m_NextUserUL = (*ulit);

	ret.m_allocationList = allocList;
	ret.m_tddPattern = pattern;
	ret.m_sfn = params.m_snfSf;
	m_macSchedSapUser->SchedConfigInd (ret);

}

}


