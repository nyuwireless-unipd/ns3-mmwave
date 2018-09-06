 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2 as
 *   published by the Free Software Foundation;
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *   Author: Marco Miozzo <marco.miozzo@cttc.es>
 *           Nicola Baldo  <nbaldo@cttc.es>
 *
 *   Modified by: Marco Mezzavilla < mezzavilla@nyu.edu>
 *        	 	  Sourjya Dutta <sdutta@nyu.edu>
 *        	 	  Russell Ford <russell.ford@nyu.edu>
 *        		  Menglei Zhang <menglei@nyu.edu>
 */



#include <ns3/log.h>
#include <ns3/abort.h>
//#include "mmwave-mac-sched-sap.h"
#include "mmwave-rr-mac-scheduler.h"
//#include "mmwave-mac-scheduler.h"
#include <ns3/lte-common.h>
#include <ns3/boolean.h>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("MmWaveRrMacScheduler");

namespace mmwave {

NS_OBJECT_ENSURE_REGISTERED (MmWaveRrMacScheduler);

class MmWaveRrMacSchedSapProvider : public MmWaveMacSchedSapProvider
{
public:
	MmWaveRrMacSchedSapProvider (MmWaveRrMacScheduler* sched);

  virtual void SchedDlRlcBufferReq (const struct MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters& params);
	virtual void SchedTriggerReq (const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params);
	virtual void SchedDlCqiInfoReq (const struct MmWaveMacSchedSapProvider::SchedDlCqiInfoReqParameters& params);
	virtual void SchedUlCqiInfoReq (const struct MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters& params);
  virtual void SchedUlMacCtrlInfoReq (const struct MmWaveMacSchedSapProvider::SchedUlMacCtrlInfoReqParameters& params);

private:
	MmWaveRrMacSchedSapProvider ();
	MmWaveRrMacScheduler* m_scheduler;
};

MmWaveRrMacSchedSapProvider::MmWaveRrMacSchedSapProvider ()
{
}

MmWaveRrMacSchedSapProvider::MmWaveRrMacSchedSapProvider (MmWaveRrMacScheduler* sched)
	:m_scheduler(sched)
{

}

void
MmWaveRrMacSchedSapProvider::SchedDlRlcBufferReq (const struct MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters& params)
{
  m_scheduler->DoSchedDlRlcBufferReq (params);
}

void
MmWaveRrMacSchedSapProvider::SchedTriggerReq (const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params)
{
	m_scheduler->DoSchedTriggerReq(params);
}

void
MmWaveRrMacSchedSapProvider::SchedDlCqiInfoReq (const struct MmWaveMacSchedSapProvider::SchedDlCqiInfoReqParameters& params)
{
	m_scheduler->DoSchedDlCqiInfoReq (params);
}

void
MmWaveRrMacSchedSapProvider::SchedUlCqiInfoReq (const struct MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters& params)
{
  m_scheduler->DoSchedUlCqiInfoReq (params);
}

void
MmWaveRrMacSchedSapProvider::SchedUlMacCtrlInfoReq (const struct MmWaveMacSchedSapProvider::SchedUlMacCtrlInfoReqParameters& params)
{
  m_scheduler->DoSchedUlMacCtrlInfoReq (params);

}


MmWaveRrMacScheduler::MmWaveRrMacScheduler ()
: m_directions (""),
  m_isDirnUpdated (false),
  m_nextRntiDl (0),
  m_nextRntiUl (0),
  m_subframeNo (0),
  m_tbUid (0),
  m_macSchedSapUser (0)
{
	NS_LOG_FUNCTION (this);

	m_macSchedSapProvider = new MmWaveRrMacSchedSapProvider (this);
}

MmWaveRrMacScheduler::~MmWaveRrMacScheduler ()
{
	NS_LOG_FUNCTION (this);
}

void
MmWaveRrMacScheduler::DoDispose (void)
{
	NS_LOG_FUNCTION (this);
	m_wbCqiRxed.clear();
  m_dlHarqProcessesTbInfoMap.clear ();
  m_dlHarqProcessesTimer.clear ();
  m_dlHarqProcessesRlcPduMap.clear ();
  m_dlHarqInfoList.clear ();
  m_ulHarqCurrentProcessId.clear ();
  m_ulHarqProcessesStatus.clear ();
  m_ulHarqProcessesTbInfoMap.clear ();
//  delete m_cschedSapProvider;
  delete m_macSchedSapProvider;
	m_directions.clear ();
}

TypeId
MmWaveRrMacScheduler::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::MmWaveRrMacScheduler")
	    .SetParent<MmWaveMacScheduler> ()
		.AddConstructor<MmWaveRrMacScheduler> ()
    .AddAttribute ("CqiTimerThreshold",
                   "The number of TTIs a CQI is valid (default 1000 - 1 sec.)",
                   UintegerValue (100),
                   MakeUintegerAccessor (&MmWaveRrMacScheduler::m_cqiTimersThreshold),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("HarqEnabled",
                   "Activate/Deactivate the HARQ [by default is active].",
                   BooleanValue (false),
                   MakeBooleanAccessor (&MmWaveRrMacScheduler::m_harqOn),
                   MakeBooleanChecker ())
		;

	return tid;
}

void
MmWaveRrMacScheduler::SetMacSchedSapUser (MmWaveMacSchedSapUser* sap)
{
	m_macSchedSapUser = sap;
}

MmWaveMacSchedSapProvider*
MmWaveRrMacScheduler::GetMacSchedSapProvider ()
{
	return m_macSchedSapProvider;
}

void
MmWaveRrMacScheduler::ConfigureCommonParameters (Ptr<MmWavePhyMacCommon> config)
{
	m_phyMacConfig = config;
	m_amc = CreateObject <MmWaveAmc> (m_phyMacConfig);
	m_numRbg = m_phyMacConfig->GetNumRb () / m_phyMacConfig->GetNumRbPerRbg ();
	m_numHarqProcess = m_phyMacConfig->GetNumHarqProcess ();
	m_harqTimeout = m_phyMacConfig->GetHarqTimeout ();
}

void
MmWaveRrMacScheduler::DoSchedDlRlcBufferReq (const struct MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters& params)
{
  NS_LOG_FUNCTION (this << params.m_rnti << (uint32_t) params.m_logicalChannelIdentity);
  // API generated by RLC for updating RLC parameters on a LC (tx and retx queues)
  std::list<MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it = m_rlcBufferReq.begin ();
  bool newLc = true;
  while (it != m_rlcBufferReq.end ())
    {
      // remove old entries of this UE-LC
      if (((*it).m_rnti == params.m_rnti)&&((*it).m_logicalChannelIdentity == params.m_logicalChannelIdentity))
        {
          it = m_rlcBufferReq.erase (it);
          newLc = false;
        }
      else
        {
          ++it;
        }
    }
  // add the new parameters
  m_rlcBufferReq.insert (it, params);
  NS_LOG_INFO (this << " RNTI " << params.m_rnti << " LC " << (uint16_t)params.m_logicalChannelIdentity << " RLC tx size " << params.m_rlcTransmissionQueueHolDelay << " RLC retx size " << params.m_rlcRetransmissionQueueSize << " RLC stat size " <<  params.m_rlcStatusPduSize);
  // initialize statistics of the flow in case of new flows
  if (newLc == true)
  {
  	m_wbCqiRxed.insert ( std::pair<uint16_t, uint8_t > (params.m_rnti, 1)); // only codeword 0 at this stage (SISO)
  	// initialized to 1 (i.e., the lowest value for transmitting a signal)
  	m_wbCqiTimers.insert ( std::pair<uint16_t, uint32_t > (params.m_rnti, m_cqiTimersThreshold));
  }

  if (m_dlHarqCurrentProcessId.find (params.m_rnti) == m_dlHarqCurrentProcessId.end ())
  {
  	// TODO: Add Csched SAP (currently no csched sap methods, so put this code here for now - RDF)
  	m_dlHarqCurrentProcessId.insert (std::pair <uint16_t,uint8_t > (params.m_rnti, 0));
  	DlHarqProcessesStatus_t dlHarqPrcStatus;
  	dlHarqPrcStatus.resize (m_phyMacConfig->GetNumHarqProcess (), 0);
  	m_dlHarqProcessesStatus.insert (std::pair <uint16_t, DlHarqProcessesStatus_t> (params.m_rnti, dlHarqPrcStatus));
  	DlHarqProcessesTimer_t dlHarqProcessesTimer;
  	dlHarqProcessesTimer.resize (m_phyMacConfig->GetNumHarqProcess (),0);
  	m_dlHarqProcessesTimer.insert (std::pair <uint16_t, DlHarqProcessesTimer_t> (params.m_rnti, dlHarqProcessesTimer));
  	DlHarqProcessesTbInfoList_t dlHarqTbInfoList;
  	dlHarqTbInfoList.resize (m_phyMacConfig->GetNumHarqProcess ());
  	m_dlHarqProcessesTbInfoMap.insert (std::pair <uint16_t, DlHarqProcessesTbInfoList_t> (params.m_rnti, dlHarqTbInfoList));
  	DlHarqRlcPduList_t dlHarqRlcPduList;
  	dlHarqRlcPduList.resize (m_phyMacConfig->GetNumHarqProcess ());
  	m_dlHarqProcessesRlcPduMap.insert (std::pair <uint16_t, DlHarqRlcPduList_t> (params.m_rnti, dlHarqRlcPduList));
  	m_ulHarqCurrentProcessId.insert (std::pair <uint16_t,uint8_t > (params.m_rnti, 0));
  	UlHarqProcessesStatus_t ulHarqPrcStatus;
  	ulHarqPrcStatus.resize (m_phyMacConfig->GetNumHarqProcess (), 0);
  	m_ulHarqProcessesStatus.insert (std::pair <uint16_t, UlHarqProcessesStatus_t> (params.m_rnti, ulHarqPrcStatus));
  	UlHarqProcessesTbInfoList_t ulHarqTbInfoList;
  	ulHarqTbInfoList.resize (m_phyMacConfig->GetNumHarqProcess ());
  	m_ulHarqProcessesTbInfoMap.insert (std::pair <uint16_t, UlHarqProcessesTbInfoList_t> (params.m_rnti, ulHarqTbInfoList));
  }
  return;
}

void
MmWaveRrMacScheduler::DoSchedDlCqiInfoReq (const struct MmWaveMacSchedSapProvider::SchedDlCqiInfoReqParameters& params)
{
  NS_LOG_FUNCTION (this);

  std::map <uint16_t,uint8_t>::iterator it;
  for (unsigned int i = 0; i < params.m_cqiList.size (); i++)
    {
      if ( params.m_cqiList.at (i).m_cqiType == DlCqiInfo::WB )
        {
          // wideband CQI reporting
          std::map <uint16_t,uint8_t>::iterator it;
          uint16_t rnti = params.m_cqiList.at (i).m_rnti;
          it = m_wbCqiRxed.find (rnti);
          if (it == m_wbCqiRxed.end ())
            {
              // create the new entry
              m_wbCqiRxed.insert ( std::pair<uint16_t, uint8_t > (rnti, params.m_cqiList.at (i).m_wbCqi) ); // only codeword 0 at this stage (SISO)
              // generate correspondent timer
              m_wbCqiTimers.insert ( std::pair<uint16_t, uint32_t > (rnti, m_cqiTimersThreshold));
            }
          else
            {
              // update the CQI value
              (*it).second = params.m_cqiList.at (i).m_wbCqi;
              // update correspondent timer
              std::map <uint16_t,uint32_t>::iterator itTimers;
              itTimers = m_wbCqiTimers.find (rnti);
              (*itTimers).second = m_cqiTimersThreshold;
            }
        }
      else if ( params.m_cqiList.at (i).m_cqiType == DlCqiInfo::SB )
        {
          // subband CQI reporting high layer configured
          // Not used by RR Scheduler
        }
      else
        {
          NS_LOG_ERROR (this << " CQI type unknown");
        }
    }

  return;
}


void
MmWaveRrMacScheduler::DoSchedUlCqiInfoReq (const struct MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters& params)
{
  NS_LOG_FUNCTION (this);

	unsigned frameNum = params.m_sfnSf >> 16;
	unsigned subframeNum = (params.m_sfnSf >> 8) & 0xFF;
	unsigned slotNum = params.m_sfnSf & 0xFF;

  switch (params.m_ulCqi.m_type)
    {
    case UlCqiInfo::PUSCH:
      {
        std::map <uint32_t, std::vector <uint16_t> >::iterator itMap;
        std::map <uint16_t, std::vector <double> >::iterator itCqi;
        itMap = m_allocationMaps.find (params.m_sfnSf);
        if (itMap == m_allocationMaps.end ())
          {
            NS_LOG_INFO (this << " Does not find info on allocation, size : " << m_allocationMaps.size ());
            return;
          }
        for (uint32_t i = 0; i < (*itMap).second.size (); i++)
          {
            // convert from fixed point notation Sxxxxxxxxxxx.xxx to double
            double sinr = LteFfConverter::fpS11dot3toDouble (params.m_ulCqi.m_sinr.at (i));
            itCqi = m_ueUlCqi.find ((*itMap).second.at (i));
            if (itCqi == m_ueUlCqi.end ())
              {
                // create a new entry
                std::vector <double> newCqi;
                for (uint32_t j = 0; j < (m_phyMacConfig->GetNumRb () * m_phyMacConfig->GetNumChunkPerRb ()); j++)
                  {
                		unsigned chunkInd = i * m_phyMacConfig->GetNumChunkPerRb ();
                    if (chunkInd == j)
                      {
                        newCqi.push_back (sinr);
                        NS_LOG_INFO ("UL CQI report for RNTI " << (*itMap).second.at (i) << " chunk " << i << " SINR " << sinr << \
                                      " frame " << frameNum << " subframe " << subframeNum << " slot " << slotNum);
                      }
                    else
                      {
                        // initialize with NO_SINR value.
                        newCqi.push_back (30.0);
                      }
                  }
                m_ueUlCqi.insert (std::pair <uint16_t, std::vector <double> > ((*itMap).second.at (i), newCqi));



                // generate correspondent timer
                m_ueCqiTimers.insert (std::pair <uint16_t, uint32_t > ((*itMap).second.at (i), m_cqiTimersThreshold));
              }
            else
              {
                // update the value
                (*itCqi).second.at (i) = sinr;
                // update correspondent timer
                std::map <uint16_t, uint32_t>::iterator itTimers;
                itTimers = m_ueCqiTimers.find ((*itMap).second.at (i));
                (*itTimers).second = m_cqiTimersThreshold;

                NS_LOG_INFO ("UL CQI report for RNTI " << (*itMap).second.at (i) << " chunk " << i << " SINR " << sinr << \
                                                      " frame " << frameNum << " subframe " << subframeNum << " slot " << slotNum);

              }

          }
        // remove obsolete info on allocation
        m_allocationMaps.erase (itMap);
      }
      break;
    default:
      NS_FATAL_ERROR ("Unknown type of UL-CQI");
    }
  return;
}


/**/
void
MmWaveRrMacScheduler::SetScheduleDirection  (std::string patt)
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
MmWaveRrMacScheduler::RefreshHarqProcesses ()
{
	NS_LOG_FUNCTION (this);

	std::map <uint16_t, DlHarqProcessesTimer_t>::iterator itTimers;
	for (itTimers = m_dlHarqProcessesTimer.begin (); itTimers != m_dlHarqProcessesTimer.end (); itTimers ++)
	{
		for (uint16_t i = 0; i < m_phyMacConfig->GetNumHarqProcess (); i++)
		{
			if ((*itTimers).second.at (i) == m_phyMacConfig->GetHarqTimeout ())
			{
				// reset HARQ process

				NS_LOG_INFO (this << " Reset HARQ proc " << i << " for RNTI " << (*itTimers).first);
				std::map <uint16_t, DlHarqProcessesStatus_t>::iterator itStat = m_dlHarqProcessesStatus.find ((*itTimers).first);
				if (itStat == m_dlHarqProcessesStatus.end ())
				{
					NS_FATAL_ERROR ("No Process Id Status found for this RNTI " << (*itTimers).first);
				}
				(*itStat).second.at (i) = 0;
				(*itTimers).second.at (i) = 0;
			}
			else
			{
				(*itTimers).second.at (i)++;
			}
		}
	}

}

uint8_t
MmWaveRrMacScheduler::UpdateDlHarqProcessId (uint16_t rnti)
{
  NS_LOG_FUNCTION (this << rnti);


  if (m_harqOn == false)
    {
  		uint8_t tbUid = m_tbUid;
  		m_tbUid = (m_tbUid+1) % m_phyMacConfig->GetNumHarqProcess ();
      return tbUid;
    }

  std::map <uint16_t, uint8_t>::iterator it = m_dlHarqCurrentProcessId.find (rnti);
  if (it == m_dlHarqCurrentProcessId.end ())
    {
      NS_FATAL_ERROR ("No Process Id found for this RNTI " << rnti);
    }
  std::map <uint16_t, DlHarqProcessesStatus_t>::iterator itStat = m_dlHarqProcessesStatus.find (rnti);
  if (itStat == m_dlHarqProcessesStatus.end ())
    {
      NS_FATAL_ERROR ("No Process Id Statusfound for this RNTI " << rnti);
    }
  uint8_t i = (*it).second;
  do
    {
      i = (i + 1) % m_phyMacConfig->GetNumHarqProcess ();
    }
  while ( ((*itStat).second.at (i) != 0)&&(i != (*it).second));
  if ((*itStat).second.at (i) == 0)
    {
      (*it).second = i;
      (*itStat).second.at (i) = 1;
    }
  else
    {
      return (m_phyMacConfig->GetNumHarqProcess () + 1); // return a not valid harq proc id
    }

  return ((*it).second);
}

uint8_t
MmWaveRrMacScheduler::UpdateUlHarqProcessId (uint16_t rnti)
{
  NS_LOG_FUNCTION (this << rnti);


  if (m_harqOn == false)
  {
  	uint8_t tbUid = m_tbUid;
  	m_tbUid = (m_tbUid+1) % m_phyMacConfig->GetNumHarqProcess ();
  	return tbUid;
  }

  std::map <uint16_t, uint8_t>::iterator it = m_ulHarqCurrentProcessId.find (rnti);
  if (it == m_ulHarqCurrentProcessId.end ())
    {
      NS_FATAL_ERROR ("No Process Id found for this RNTI " << rnti);
    }
  std::map <uint16_t, DlHarqProcessesStatus_t>::iterator itStat = m_ulHarqProcessesStatus.find (rnti);
  if (itStat == m_ulHarqProcessesStatus.end ())
    {
      NS_FATAL_ERROR ("No Process Id Statusfound for this RNTI " << rnti);
    }
  uint8_t i = (*it).second;
  do
    {
      i = (i + 1) % m_phyMacConfig->GetNumHarqProcess ();
    }
  while ( ((*itStat).second.at (i) != 0)&&(i != (*it).second));
  if ((*itStat).second.at (i) == 0)
    {
      (*it).second = i;
      (*itStat).second.at (i) = 1;
    }
  else
    {
      return (m_phyMacConfig->GetNumHarqProcess () + 1); // return a not valid harq proc id
    }

  return ((*it).second);
}

bool
MmWaveRrMacScheduler::DoSchedDlTriggerReq (const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params,
                                           MmWaveMacSchedSapUser::SchedConfigIndParameters& ret,
                                           unsigned int frameNum,
                                           unsigned int sfNum,
                                           unsigned int slotNum)
{
	bool success = false; // was able to allocate at least 1 UE
	// Create RBG map (DL res alloc type 0)
	std::vector <bool> rbgMap;
	uint16_t rbgAllocatedNum = 0;
	std::set <uint16_t> rntiAllocated;
	rbgMap.resize (m_phyMacConfig->GetNumRb (), false);

	std::map<uint16_t,SchedInfo>& schedInfoMap = ret.m_schedInfoMap;

	// ****************** this section for HARQ retx ******************

	//   update UL HARQ proc id
//	std::map <uint16_t, uint8_t>::iterator itProcId;
//	for (itProcId = m_ulHarqCurrentProcessId.begin (); itProcId != m_ulHarqCurrentProcessId.end (); itProcId++)
//	{
//		(*itProcId).second = ((*itProcId).second + 1) % m_phyMacConfig->GetNumHarqProcess ();
//	}

	// Process DL HARQ feedback
	RefreshHarqProcesses ();
	// retrieve past HARQ retx buffered
	if (m_dlHarqInfoList.size () > 0)
	{
		if (params.m_dlHarqInfoList.size () > 0)
		{
			NS_LOG_INFO (this << " Received DL-HARQ feedback");
			m_dlHarqInfoList.insert (m_dlHarqInfoList.end (), params.m_dlHarqInfoList.begin (), params.m_dlHarqInfoList.end ());
		}
	}
	else
	{
		if (params.m_dlHarqInfoList.size () > 0)
		{
			m_dlHarqInfoList = params.m_dlHarqInfoList;
		}
	}
	if (m_harqOn == false)
	{
		// Ignore HARQ feedback
		m_dlHarqInfoList.clear ();
	}
	else
	{
		std::vector <struct DlHarqInfo> dlInfoListUntxed;
		for (uint16_t i = 0; i < m_dlHarqInfoList.size (); i++)
		{
			std::set <uint16_t>::iterator itRnti = rntiAllocated.find (m_dlHarqInfoList.at (i).m_rnti);
			if (itRnti != rntiAllocated.end ())
			{
				// RNTI already allocated for retx
				continue;
			}
			//		uint8_t nLayers = m_dlHarqInfoList.at (i).m_harqStatus.size ();
			//			        std::vector <bool> retx;
			NS_LOG_INFO (this << " Processing DLHARQ feedback");
			//			        if (nLayers == 1)
			//			          {
			//			            retx.push_back (m_dlHarqInfoList.at (i).m_harqStatus.at (0) == DlInfoListElement_s::NACK);
			//			            retx.push_back (false);
			//			          }
			//			        else
			//			          {
			//			            retx.push_back (m_dlHarqInfoList.at (i).m_harqStatus.at (0) == DlInfoListElement_s::NACK);
			//			            retx.push_back (m_dlHarqInfoList.at (i).m_harqStatus.at (1) == DlInfoListElement_s::NACK);
			//			          }
			//			        if (retx.at (0) || retx.at (1))
			if(m_dlHarqInfoList.at (i).m_harqStatus.at (0) == DlHarqInfo::NACK)
			{
				// retrieve HARQ process information
				uint16_t rnti = m_dlHarqInfoList.at (i).m_rnti;
				uint8_t harqId = m_dlHarqInfoList.at (i).m_harqProcessId;
				NS_LOG_INFO (this << " HARQ retx RNTI " << rnti << " harqId " << (uint16_t)harqId);
				std::map <uint16_t, DlHarqProcessesTbInfoList_t>::iterator itHarq = m_dlHarqProcessesTbInfoMap.find (rnti);
				if (itHarq == m_dlHarqProcessesTbInfoMap.end ())
				{
					NS_FATAL_ERROR ("No info find in HARQ buffer for UE " << rnti);
				}

				TbInfoElement harqTbInfo = (*itHarq).second.at (harqId);
				//			if (dci.m_rv.size () == 1)
				//			{
				//				rv = dci.m_rv.at (0);
				//			}
				//			else
				//			{
				//				rv = (dci.m_rv.at (0) > dci.m_rv.at (1) ? dci.m_rv.at (0) : dci.m_rv.at (1));
				//			}

				if (harqTbInfo.m_rv == 3)
				{
					// maximum number of retx reached -> drop process
					NS_LOG_INFO ("Max number of retransmissions reached -> drop process");
					std::map <uint16_t, DlHarqProcessesStatus_t>::iterator it = m_dlHarqProcessesStatus.find (rnti);
					if (it == m_dlHarqProcessesStatus.end ())
					{
						NS_LOG_ERROR ("No info find in HARQ buffer for UE (might change eNB) " << m_dlHarqInfoList.at (i).m_rnti);
					}
					(*it).second.at (harqId) = 0;
					std::map <uint16_t, DlHarqRlcPduList_t>::iterator itRlcPdu =  m_dlHarqProcessesRlcPduMap.find (rnti);
					if (itRlcPdu == m_dlHarqProcessesRlcPduMap.end ())
					{
						NS_FATAL_ERROR ("Unable to find RlcPdcList in HARQ buffer for RNTI " << m_dlHarqInfoList.at (i).m_rnti);
					}
					for (uint16_t k = 0; k < (*itRlcPdu).second.size (); k++)
					{
						(*itRlcPdu).second.at (harqId).clear ();
					}
					continue;
				}
				// check the feasibility of retransmitting on the same RBGs
				// translate the DCI to Spectrum framework
				std::vector <int> dciRbg;
				uint32_t mask = 0x1;
				NS_LOG_INFO ("Original RBGs " << harqTbInfo.m_rbBitmap << " rnti " << rnti);
				for (unsigned int j = 0; j < m_phyMacConfig->GetNumRb (); j++)
				{
					if (((harqTbInfo.m_rbBitmap & mask) >> j) == 1)
					{
						dciRbg.push_back (j);
						NS_LOG_INFO ("\t" << j);
					}
					mask = (mask << 1);
				}
				bool free = true;
				for (uint8_t j = 0; j < dciRbg.size (); j++)
				{
					if (rbgMap.at (dciRbg.at (j)) == true)
					{
						free = false;
						break;
					}
				}
				if (free)
				{
					// use the same RBGs for the retx
					// reserve RBGs
					for (uint8_t j = 0; j < dciRbg.size (); j++)
					{
						rbgMap.at (dciRbg.at (j)) = true;
						NS_LOG_INFO ("RBG " << dciRbg.at (j) << " assigned");
						rbgAllocatedNum++;
					}

					NS_LOG_INFO (this << " Send retx in the same RBGs");
				}
				else
				{
					// find RBGs for sending HARQ retx
					uint8_t j = 0;
					uint8_t rbgId = (dciRbg.at (dciRbg.size () - 1) + 1) % m_phyMacConfig->GetNumRb ();
					uint8_t startRbg = dciRbg.at (dciRbg.size () - 1);
					std::vector <bool> rbgMapCopy = rbgMap;
					while ((j < dciRbg.size ())&&(startRbg != rbgId))
					{
						if (rbgMapCopy.at (rbgId) == false)
						{
							rbgMapCopy.at (rbgId) = true;
							dciRbg.at (j) = rbgId;
							j++;
						}
						rbgId = (rbgId + 1) % m_phyMacConfig->GetNumRb ();
					}
					if (j == dciRbg.size ())
					{
						// find new RBGs -> update DCI map
						uint32_t rbgMask = 0;
						for (uint16_t k = 0; k < dciRbg.size (); k++)
						{
							rbgMask = rbgMask + (0x1 << dciRbg.at (k));
							NS_LOG_INFO (this << " New allocated RBG " << dciRbg.at (k));
							rbgAllocatedNum++;
						}
						harqTbInfo.m_rbBitmap = rbgMask;
						rbgMap = rbgMapCopy;
					}
					else
					{
						// HARQ retx cannot be performed on this TTI -> store it
						dlInfoListUntxed.push_back (m_dlHarqInfoList.at (i));
						NS_LOG_INFO (this << " No resource for this retx -> buffer it");
					}
				}
				// retrieve RLC PDU list for retx TBsize and update DCI
				//			BuildDataListElement_s newEl;
				std::map<uint16_t, SchedInfo>::iterator schedIt = schedInfoMap.find (rnti);
				if (schedIt == schedInfoMap.end ())
				{
					SchedInfo newSchedInfo (m_phyMacConfig->GetSlotsPerSubframe ());
					newSchedInfo.m_rnti = rnti;
					DciInfoElement newDci;
					newDci.m_rnti = rnti;
					newDci.m_tddBitmap = 0;
					newDci.m_format = 0;
					newDci.m_cceIndex = 0;
					//			        newDci.m_harqProcess = UpdateHarqProcessId ((*it).m_rnti);
					newSchedInfo.m_dci = newDci;
					newSchedInfo.m_frameNum = frameNum;
					newSchedInfo.m_sfNum = sfNum;
					schedIt = (schedInfoMap.insert (std::pair<uint16_t,SchedInfo> (rnti, newSchedInfo))).first;
				}
				SchedInfo& schedInfo = schedIt->second;
				harqTbInfo.m_ndi = 0;
				harqTbInfo.m_slotIdx = slotNum;
				harqTbInfo.m_rv++;
				(*itHarq).second.at (harqId).m_rv++;
				//schedInfo.m_rlcPduList.push_back(std::vector<RlcPduInfo> ());  // vector to store RLC PDUs for new TB
				std::map<uint8_t, std::vector<RlcPduInfo> >::iterator rlcPduMapIt = schedInfo.m_rlcPduMap.insert (std::pair<uint8_t, std::vector<RlcPduInfo> > (harqId, std::vector<RlcPduInfo>() )).first;
				NS_LOG_INFO (this << "HARQ ReTx RV " << (uint16_t)harqTbInfo.m_rv);


				/*			for (uint8_t j = 0; j < nLayers; j++)
			{
				if (retx.at (j))
				{
					if (j >= dci.m_ndi.size ())
					{
						// for avoiding errors in MIMO transient phases
						dci.m_ndi.push_back (0);
						dci.m_rv.push_back (0);
						dci.m_mcs.push_back (0);
						dci.m_tbsSize.push_back (0);
						NS_LOG_INFO (this << " layer " << (uint16_t)j << " no txed (MIMO transition)");

					}
					else
					{
						dci.m_ndi.at (j) = 0;
						dci.m_rv.at (j)++;
						(*itHarq).second.at (harqId).m_rv.at (j)++;
						NS_LOG_INFO (this << " layer " << (uint16_t)j << " RV " << (uint16_t)dci.m_rv.at (j));
					}
				}
				else
				{
					// empty TB of layer j
					dci.m_ndi.at (j) = 0;
					dci.m_rv.at (j) = 0;
					dci.m_mcs.at (j) = 0;
					dci.m_tbsSize.at (j) = 0;
					NS_LOG_INFO (this << " layer " << (uint16_t)j << " no retx");
				}
			}*/

				std::map <uint16_t, DlHarqRlcPduList_t>::iterator itRlcList =  m_dlHarqProcessesRlcPduMap.find (rnti);
				if (itRlcList == m_dlHarqProcessesRlcPduMap.end ())
				{
					NS_FATAL_ERROR ("Unable to find RlcPdcList in HARQ buffer for RNTI " << rnti);
				}

//				std::vector <RlcPduInfo> rlcPduListPerLc;
				for (uint16_t k = 0; k < (*itRlcList).second.at(harqTbInfo.m_harqProcess).size (); k++)
				{
					//					for (uint8_t j = 0; j < nLayers; j++)
					//					{
					//						if (retx.at (j))
					//						{
					//							if (j < dci.m_ndi.size ())
					//							{
					//								rlcPduListPerLc.push_back ((*itRlcPdu).second.at (j).at (dci.m_harqProcess).at (k));
					//							}
					//						}
					//					}

					//rlcPduListPerLc.push_back ((*itRlcList).second.at (harqTbInfo.m_harqProcess).at (k));
					rlcPduMapIt->second.push_back ((*itRlcList).second.at (harqTbInfo.m_harqProcess).at (k));
				}
//				if (rlcPduListPerLc.size () > 0)
//				{
//					schedInfo.m_rlcPduList.push_back (rlcPduListPerLc);
//				}
				//				schedIt->second.m_rnti = rnti;
				schedInfo.m_dci.m_tbInfoElements.push_back (harqTbInfo);
				success = true;
				(*itHarq).second.at (harqId).m_rv = harqTbInfo.m_rv;
				// refresh timer
				std::map <uint16_t, DlHarqProcessesTimer_t>::iterator itHarqTimer = m_dlHarqProcessesTimer.find (rnti);
				if (itHarqTimer== m_dlHarqProcessesTimer.end ())
				{
					NS_FATAL_ERROR ("Unable to find HARQ timer for RNTI " << (uint16_t)rnti);
				}
				(*itHarqTimer).second.at (harqId) = 0;
				rntiAllocated.insert (rnti);
			}
			else
			{
				// update HARQ process status
				NS_LOG_INFO (this << " HARQ ACK UE " << m_dlHarqInfoList.at (i).m_rnti);
				std::map <uint16_t, DlHarqProcessesStatus_t>::iterator it = m_dlHarqProcessesStatus.find (m_dlHarqInfoList.at (i).m_rnti);
				if (it == m_dlHarqProcessesStatus.end ())
				{
					NS_FATAL_ERROR ("No info find in HARQ buffer for UE " << m_dlHarqInfoList.at (i).m_rnti);
				}
				(*it).second.at (m_dlHarqInfoList.at (i).m_harqProcessId) = 0;
				std::map <uint16_t, DlHarqRlcPduList_t>::iterator itRlcPdu =  m_dlHarqProcessesRlcPduMap.find (m_dlHarqInfoList.at (i).m_rnti);
				if (itRlcPdu == m_dlHarqProcessesRlcPduMap.end ())
				{
					NS_FATAL_ERROR ("Unable to find RlcPdcList in HARQ buffer for RNTI " << m_dlHarqInfoList.at (i).m_rnti);
				}
				(*itRlcPdu).second.at (m_dlHarqInfoList.at (i).m_harqProcessId).clear ();

				//				for (uint16_t k = 0; k < (*itRlcPdu).second.size (); k++)
				//				{
				//					(*itRlcPdu).second.at (k).at (m_dlHarqInfoList.at (i).m_harqProcessId).clear ();
				//				}
			}
		}
		m_dlHarqInfoList.clear ();
		m_dlHarqInfoList = dlInfoListUntxed;

		if (rbgAllocatedNum == m_phyMacConfig->GetNumRb ())
		{
			// all the RBGs are already allocated -> exit
			//			if ((ret.m_buildDataList.size () > 0) || (ret.m_buildRarList.size () > 0))
			//			{
			//				m_schedSapUser->SchedDlConfigInd (ret);
			//			}
			return success;
		}
	}
	// END OF HARQ SECTION

	// Get the actual active flows (unique RNTI-LCID pairs)
	std::list<MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it;
	m_rlcBufferReq.sort (SortRlcBufferReq);
	int nflows = 0;
	int nTbs = 0;

	std::map <uint16_t,uint8_t> lcActivesPerRnti; // tracks how many active LCs per RNTI there are
	std::map <uint16_t,uint8_t>::iterator itLcRnti;
	for (it = m_rlcBufferReq.begin (); it != m_rlcBufferReq.end (); it++)
	{
		// remove old entries of this UE-LC
		std::set <uint16_t>::iterator itRnti = rntiAllocated.find ((*it).m_rnti);

		if ( (((*it).m_rlcTransmissionQueueSize > 0)
				|| ((*it).m_rlcRetransmissionQueueSize > 0)
				|| ((*it).m_rlcStatusPduSize > 0))
				&& (itRnti == rntiAllocated.end ()) )  // UE must not be allocated for HARQ retx
			//			  				  			&& (HarqProcessAvailability ((*it).m_rnti))  ) // UE needs HARQ proc free
		{
			NS_LOG_INFO (this << " User " << (*it).m_rnti << " LC " << (uint16_t)(*it).m_logicalChannelIdentity << " is active, status  " << (*it).m_rlcStatusPduSize << " retx " << (*it).m_rlcRetransmissionQueueSize << " tx " << (*it).m_rlcTransmissionQueueSize);
			std::map <uint16_t,uint8_t>::iterator itCqi = m_wbCqiRxed.find ((*it).m_rnti);
			uint8_t cqi = 0;
			if (itCqi != m_wbCqiRxed.end ())
			{
				cqi = (*itCqi).second;
			}
			else
			{
				cqi = 1; // lowest value for trying a transmission
			}
			if (cqi != 0)
			{
				// CQI == 0 means "out of range" (see table 7.2.3-1 of 36.213)
				nflows++;
				itLcRnti = lcActivesPerRnti.find ((*it).m_rnti);
				if (itLcRnti != lcActivesPerRnti.end ())
				{
					(*itLcRnti).second++;
				}
				else
				{
					lcActivesPerRnti.insert (std::pair<uint16_t, uint8_t > ((*it).m_rnti, 1));
					nTbs++;
				}
			}
			else
			{
				NS_LOG_INFO ("*** RNTI " << (*it).m_rnti << " DL CQI out of range, skipping allocation in DL for slot " << slotNum+1);
			}
		}
	}

	if (nflows == 0)
	{
		return success; // no DL flows to be scheduled
	}

	// int rbgPerTb = (nTbs > 0) ? ((numRbg - rbgAllocatedNum) / nTbs) : INT_MAX;
	unsigned int rbgPerTb = (nTbs > 0) ? (m_phyMacConfig->GetNumRb ()  / nTbs) : m_phyMacConfig->GetNumRb ();

	NS_LOG_INFO (this << " Flows to be transmitted " << nflows << " rbgPerTb " << rbgPerTb);
	if (rbgPerTb == 0)
	{
		rbgPerTb = 1;
	}

	unsigned int rbgAllocated = 0;

	// round robin assignment to all UEs registered starting from the subsequent of the one
	// served last scheduling trigger event
	if (m_nextRntiDl != 0)
	{
		for (it = m_rlcBufferReq.begin (); it != m_rlcBufferReq.end (); it++)
		{
			if ((*it).m_rnti == m_nextRntiDl)
			{
				break;
			}
		}

		if (it == m_rlcBufferReq.end ())
		{
			NS_FATAL_ERROR (this << " no user found");
		}
	}
	else
	{
		it = m_rlcBufferReq.begin ();
		m_nextRntiDl = (*it).m_rnti;
	}
	//			std::map <uint16_t,uint8_t>::iterator itTxMode;
	do
	{
		itLcRnti = lcActivesPerRnti.find ((*it).m_rnti);
		//				std::set <uint16_t>::iterator itRnti = rntiAllocated.find ((*it).m_rnti);
		//				if ((itLcRnti == lcActivesPerRnti.end ())||(itRnti != rntiAllocated.end ()))
		if ((itLcRnti == lcActivesPerRnti.end ()))
		{
			// skip this RNTI (no active queue or already allocated for HARQ)
			uint16_t rntiDiscared = (*it).m_rnti;
			while (it != m_rlcBufferReq.end ())
			{
				if ((*it).m_rnti != rntiDiscared)
				{
					break;
				}
				it++;
			}
			if (it == m_rlcBufferReq.end ())
			{
				// restart from the first
				it = m_rlcBufferReq.begin ();
			}
			continue;
		}

		int lcNum = (*itLcRnti).second;

		// find existing or create new scheduling info element/DCI element
		std::map<uint16_t,SchedInfo>::iterator schedIt = schedInfoMap.find ((*it).m_rnti);
		if (schedIt == schedInfoMap.end ())
		{
			SchedInfo newSchedInfo (m_phyMacConfig->GetSlotsPerSubframe ());
			newSchedInfo.m_rnti = (*it).m_rnti;
			DciInfoElement newDci;
			newDci.m_rnti = (*it).m_rnti;
			newDci.m_tddBitmap = 0;
			newDci.m_format = 0;
			newDci.m_cceIndex = 0;
			//			        newDci.m_harqProcess = UpdateHarqProcessId ((*it).m_rnti);
			newSchedInfo.m_dci = newDci;
			newSchedInfo.m_frameNum = frameNum;
			newSchedInfo.m_sfNum = sfNum;
			schedIt = (schedInfoMap.insert (std::pair<uint16_t,SchedInfo> ((*it).m_rnti, newSchedInfo))).first;
		}

		SchedInfo& schedInfo = schedIt->second;
		//				schedInfo.m_dci.m_tddBitmap = (schedInfo.m_dci.m_tddBitmap | (0x1 << slotNum));
		TbInfoElement newTbInfoElem;
		newTbInfoElem.m_resAlloc = 0;
		newTbInfoElem.m_rbBitmap = 0;
		newTbInfoElem.m_slotIdx = slotNum;
		newTbInfoElem.m_rbShift = 0;
		newTbInfoElem.m_rbStart = 0;
		newTbInfoElem.m_rbLen = 0;
		newTbInfoElem.m_harqProcess = UpdateDlHarqProcessId ((*it).m_rnti);
		//schedInfo.m_rlcPduList.push_back(std::vector<RlcPduInfo> ());  // vector to store RLC PDUs for new TB
		std::map<uint8_t, std::vector<RlcPduInfo> >::iterator rlcPduMapIt = schedInfo.m_rlcPduMap.insert (std::pair<uint8_t, std::vector<RlcPduInfo> > (newTbInfoElem.m_harqProcess, std::vector<RlcPduInfo> () )).first;

		std::map <uint16_t,uint8_t>::iterator itCqi = m_wbCqiRxed.find (schedInfo.m_rnti);

		if (itCqi == m_wbCqiRxed.end ())
		{
			newTbInfoElem.m_mcs = 0; // no info on this user -> lowest MCS
		}
		else
		{
			newTbInfoElem.m_mcs = m_amc->GetMcsFromCqi ((*itCqi).second);
		}

		MmWaveMacPduHeader macHeader;
		int tbSize = (m_amc->GetTbSizeFromMcs (newTbInfoElem.m_mcs, m_phyMacConfig->GetNumRb()) / 8) - macHeader.GetSerializedSize ();
		uint16_t rlcPduSize = tbSize / lcNum;
		while ((*it).m_rnti == schedInfo.m_rnti)
		{
			if ( ((*it).m_rlcTransmissionQueueSize > 0)
					|| ((*it).m_rlcRetransmissionQueueSize > 0)
					|| ((*it).m_rlcStatusPduSize > 0) )
			{

				RlcPduInfo newRlcEl;
				newRlcEl.m_lcid = (*it).m_logicalChannelIdentity;
				NS_LOG_INFO (this << "LCID " << (uint32_t) newRlcEl.m_lcid << " size " << rlcPduSize << " ID " << (*it).m_rnti);
				newRlcEl.m_size = rlcPduSize;
				UpdateDlRlcBufferInfo ((*it).m_rnti, newRlcEl.m_lcid, rlcPduSize);

				if (m_harqOn == true)
				{
					// store RLC PDU list for HARQ
					std::map <uint16_t, DlHarqRlcPduList_t>::iterator itRlcPdu =  m_dlHarqProcessesRlcPduMap.find ((*it).m_rnti);
					if (itRlcPdu == m_dlHarqProcessesRlcPduMap.end ())
					{
						NS_FATAL_ERROR ("Unable to find RlcPdcList in HARQ buffer for RNTI " << (*it).m_rnti);
					}
					(*itRlcPdu).second.at (newTbInfoElem.m_harqProcess).push_back (newRlcEl);
				}

				// push new element onto RLC PDU vector for this TB
				//schedInfo.m_rlcPduList[schedInfo.m_rlcPduList.size ()-1].push_back (newRlcEl);
				rlcPduMapIt->second.push_back (newRlcEl);
				NS_LOG_INFO ("RLC PDU for LCID " << (unsigned int)newRlcEl.m_lcid << " of size " << newRlcEl.m_size << " added for TB " << newTbInfoElem.m_harqProcess);
				lcNum--;
			}
			it++;
			if (it == m_rlcBufferReq.end ())
			{
				// restart from the first
				it = m_rlcBufferReq.begin ();
				break;
			}
		}
		uint32_t rbgMask = 0;
		uint16_t i = 0;
		NS_LOG_DEBUG ("DL Allocation frame " << frameNum << " subframe " << sfNum << " slot " << slotNum+1 << " " << " RNTI " << schedInfo.m_rnti << " LCs " << (uint16_t)(*itLcRnti).second << " bytes " << tbSize << " mcs " << (uint16_t) newTbInfoElem.m_mcs << " harqId " << (uint16_t)newTbInfoElem.m_harqProcess );
		while (i < rbgPerTb)
		{
			if (rbgMap.at (rbgAllocated) == false)
			{
				rbgMask = rbgMask + (0x1 << rbgAllocated);
				i++;
				rbgMap.at (rbgAllocated) = true;
				rbgAllocatedNum++;
			}
			rbgAllocated++;
		}
		newTbInfoElem.m_rbBitmap = rbgMask; // (32 bit bitmap see 7.1.6 of 36.213)
		newTbInfoElem.m_tbSize = tbSize;
		newTbInfoElem.m_ndi = 1;
		newTbInfoElem.m_rv = 0;

		// newDci.m_tpc = 1; //1 is mapped to 0 in Accumulated Mode and to -1 in Absolute Mode

		schedInfo.m_dci.m_tbInfoElements.push_back (newTbInfoElem);
		success = true;

		if (m_harqOn == true)
		{
			// store DCI for HARQ
			std::map <uint16_t, DlHarqProcessesTbInfoList_t>::iterator itTbInfo = m_dlHarqProcessesTbInfoMap.find (schedInfo.m_dci.m_rnti);
			if (itTbInfo == m_dlHarqProcessesTbInfoMap.end ())
			{
				NS_FATAL_ERROR ("Unable to find RNTI entry in DCI HARQ buffer for RNTI " << schedInfo.m_rnti);
			}
			(*itTbInfo).second.at (newTbInfoElem.m_harqProcess) = newTbInfoElem;
			// refresh timer
			std::map <uint16_t, DlHarqProcessesTimer_t>::iterator itHarqTimer =  m_dlHarqProcessesTimer.find (schedInfo.m_dci.m_rnti);
			if (itHarqTimer== m_dlHarqProcessesTimer.end ())
			{
				NS_FATAL_ERROR ("Unable to find HARQ timer for RNTI " << (uint16_t)schedInfo.m_dci.m_rnti);
			}
			(*itHarqTimer).second.at (newTbInfoElem.m_harqProcess) = 0;
		}

		if (rbgAllocatedNum == m_phyMacConfig->GetNumRb ())
		{
			m_nextRntiDl = (*it).m_rnti; // store last RNTI served
			break;                       // no more RGB to be allocated
		}
	}
	while ((*it).m_rnti != m_nextRntiDl);

	return success;
}

bool
MmWaveRrMacScheduler::DoSchedUlTriggerReq (const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params,
                                           MmWaveMacSchedSapUser::SchedConfigIndParameters& ret,
                                           unsigned int frameNum,
                                           unsigned int sfNum,
                                           unsigned int slotNum)
{
	bool success = false; // was able to allocate at least 1 UE
	// schedule slot in n+3th subframe for UL
	// Create RB map (UL res alloc type 0)
	std::vector <bool> rbMap;
  uint16_t rbAllocatedNum = 0;
	std::set <uint16_t> rntiAllocated;
	std::vector <uint16_t> rbgAllocationMap;
	uint32_t numRb = m_phyMacConfig->GetNumRb ();
	rbMap.resize (numRb);
	rbgAllocationMap.resize (numRb);
	std::map<uint16_t,SchedInfo>& schedInfoMap = ret.m_schedInfoMap;
	uint32_t sfn =  ((0x3FF & frameNum) << 16) | ((0xFF & sfNum) << 8) | (0xFF & (slotNum+1));


	if (m_harqOn == true)
	{
		//   Process UL HARQ feedback
		for (uint16_t i = 0; i < params.m_ulHarqInfoList.size (); i++)
		{
			if (params.m_ulHarqInfoList.at (i).m_receptionStatus == UlHarqInfo::NotOk)
			{
				// retx correspondent block: retrieve the UL-DCI
				uint16_t rnti = params.m_ulHarqInfoList.at (i).m_rnti;
				std::map <uint16_t, uint8_t>::iterator itProcId = m_ulHarqCurrentProcessId.find (rnti);
				if (itProcId == m_ulHarqCurrentProcessId.end ())
				{
					NS_LOG_ERROR ("No info find in HARQ buffer for UE (might change eNB) " << rnti);
				}
				uint8_t harqId = (*itProcId).second;
				NS_LOG_INFO (this << " UL-HARQ retx RNTI " << rnti << " harqId " << (uint16_t)harqId);
				std::map <uint16_t, UlHarqProcessesTbInfoList_t>::iterator itHarq = m_ulHarqProcessesTbInfoMap.find (rnti);
				if (itHarq == m_ulHarqProcessesTbInfoMap.end ())
				{
					NS_LOG_ERROR ("No info find in UL-HARQ buffer for UE (might change eNB) " << rnti);
				}
				TbInfoElement harqTbInfo = (*itHarq).second.at (harqId);
				std::map <uint16_t, UlHarqProcessesStatus_t>::iterator itStat = m_ulHarqProcessesStatus.find (rnti);
				if (itStat == m_ulHarqProcessesStatus.end ())
				{
					NS_LOG_ERROR ("No info find in HARQ buffer for UE (might change eNB) " << rnti);
				}
				if ((*itStat).second.at (harqId) > 3)
				{
					NS_LOG_INFO ("Max number of retransmissions reached (UL)-> drop process");
					continue;
				}
				bool free = true;
				for (int j = harqTbInfo.m_rbStart; j < harqTbInfo.m_rbStart + harqTbInfo.m_rbLen; j++)
				{
					if (rbMap.at (j) == true)
					{
						free = false;
						NS_LOG_INFO (this << " BUSY " << j);
					}
				}
				if (free)
				{
					// retx on the same RBs
					for (int j = harqTbInfo.m_rbStart; j < harqTbInfo.m_rbStart + harqTbInfo.m_rbLen; j++)
					{
						rbMap.at (j) = true;
						rbgAllocationMap.at (j) = rnti;
						NS_LOG_INFO ("\tRB " << j);
						rbAllocatedNum++;
					}
					NS_LOG_INFO (this << " Send retx in the same RBGs " << (uint16_t)harqTbInfo.m_rbStart << " to " << harqTbInfo.m_rbStart + harqTbInfo.m_rbLen << " RV " << (*itStat).second.at (harqId) + 1);
				}
//				else
//				{
//					NS_LOG_INFO ("Cannot allocate retx due to RACH allocations for UE " << rnti);
//					continue;
//				}
				harqTbInfo.m_ndi = 0;
				harqTbInfo.m_slotIdx = slotNum;

				std::map<uint16_t, SchedInfo>::iterator schedIt = schedInfoMap.find (rnti);
				if (schedIt == schedInfoMap.end ())
				{
					SchedInfo newSchedInfo (m_phyMacConfig->GetSlotsPerSubframe ());
					newSchedInfo.m_rnti = rnti;
					DciInfoElement newDci;
					newDci.m_rnti = rnti;
					newDci.m_tddBitmap = 0;
					newDci.m_format = 0;
					newDci.m_cceIndex = 0;
					//			        newDci.m_harqProcess = UpdateHarqProcessId ((*it).m_rnti);
					newSchedInfo.m_dci = newDci;
					newSchedInfo.m_frameNum = frameNum;
					newSchedInfo.m_sfNum = sfNum;
					schedIt = (schedInfoMap.insert (std::pair<uint16_t,SchedInfo> (rnti, newSchedInfo))).first;
				}
				SchedInfo& schedInfo = schedIt->second;
				schedInfo.m_dci.m_tddBitmap = (schedInfo.m_dci.m_tddBitmap | (0x1 << slotNum)); // set bit for UL

				// Update HARQ buffers with new HarqId
				(*itStat).second.at ((*itProcId).second) = (*itStat).second.at (harqId) + 1;
				(*itStat).second.at (harqId) = 0;
				(*itHarq).second.at ((*itProcId).second) = harqTbInfo;
				schedIt->second.m_dci.m_tbInfoElements.push_back (harqTbInfo);
				success = true;
				rntiAllocated.insert (rnti);
			}
		}
	}

	std::map <uint16_t,uint32_t>::iterator it;
	int nflows = 0;

	for (it = m_ceBsrRxed.begin (); it != m_ceBsrRxed.end (); it++)
	{
		//			      std::set <uint16_t>::iterator itRnti = rntiAllocated.find ((*it).first);
		//			      // select UEs with queues not empty and not yet allocated for HARQ
		//			      NS_LOG_INFO (this << " UE " << (*it).first << " queue " << (*it).second);
		//			      if (((*it).second > 0)&&(itRnti == rntiAllocated.end ()))
		//			        {
		//			          nflows++;
		//			        }
		if ((*it).second > 0)
		{
			nflows++;
		}
	}
	if (nflows == 0)
	{
		return success;  // no UL flows to be scheduled
	}

	// Divide the remaining resources equally among the active users starting from after the one served last scheduling trigger
	//			  uint16_t rbPerFlow = numRbg / (nflows + rntiAllocated.size ());
	unsigned int rbPerFlow = m_phyMacConfig->GetNumRb () / nflows;
	if (rbPerFlow == 0)
	{
		rbPerFlow = 1;  // at least 1 rbg per flow (till available resource) to ensure TxOpportunity >= 7 bytes
	}

	if (m_nextRntiUl != 0)
	{
		for (it = m_ceBsrRxed.begin (); it != m_ceBsrRxed.end (); it++)
		{
			if ((*it).first == m_nextRntiUl)
			{
				break;
			}
		}
		if (it == m_ceBsrRxed.end ())
		{
			NS_LOG_ERROR (this << " no user found");
		}
	}
	else
	{
		it = m_ceBsrRxed.begin ();
		m_nextRntiUl = (*it).first;
	}

	NS_LOG_INFO (this << " NFlows " << nflows << " RB per Flow " << rbPerFlow);
	do
	{
		/*std::set <uint16_t>::iterator itRnti = rntiAllocated.find ((*it).first);
					if ((itRnti != rntiAllocated.end ())||((*it).second == 0))
					{
						// UE already allocated for UL-HARQ -> skip it
						it++;
						if (it == m_ceBsrRxed.end ())
						{
							// restart from the first
							it = m_ceBsrRxed.begin ();
						}
						continue;
					}*/
		//				if (rbAllocated + rbPerFlow - 1 > numRb)
		//				{
		//					// limit to physical resources last resource assignment
		//					rbPerFlow = numRb - rbAllocated;
		//					// at least 3 rbg per flow to ensure TxOpportunity >= 7 bytes
		//					if (rbPerFlow < 1)
		//					{
		//						// terminate allocation
		//						rbPerFlow = 0;
		//					}
		//				}
		uint16_t rnti = (*it).first;
		NS_LOG_INFO (this << " try to allocate " << rnti);
		// find existing or create new scheduling info element/DCI element
		std::map<uint16_t,SchedInfo>::iterator schedIt = schedInfoMap.find (rnti);
		if (schedIt == schedInfoMap.end ())
		{
			SchedInfo newSchedInfo (m_phyMacConfig->GetSlotsPerSubframe ());
			newSchedInfo.m_rnti = (*it).first;
			DciInfoElement newDci;
			newDci.m_rnti = (*it).first;
			newDci.m_tddBitmap = 0;
			//			        newDci.m_harqProcess = UpdateHarqProcessId ((*it).m_rnti);
			newSchedInfo.m_dci = newDci;
			newSchedInfo.m_frameNum = frameNum;
			newSchedInfo.m_sfNum = sfNum;
			schedIt = (schedInfoMap.insert (std::pair<uint16_t,SchedInfo> ((*it).first, newSchedInfo))).first;
		}

		SchedInfo& schedInfo = schedIt->second;
		TbInfoElement newTbInfoElem;
		newTbInfoElem.m_resAlloc = 0;
		newTbInfoElem.m_rbLen = rbPerFlow;
		newTbInfoElem.m_slotIdx = slotNum;
		newTbInfoElem.m_rbBitmap = 0;
		newTbInfoElem.m_rbShift = 0;


		//				UlDciListElement uldci;
		//				uldci.m_rnti = (*it).first;
		//				uldci.m_rbLen = rbPerFlow;

		bool allocated = false;
		uint16_t rbAllocated = 0;
		NS_LOG_INFO (this << " RB Allocated " << rbAllocated << " rbPerFlow " << rbPerFlow << " flows " << nflows);
		while ((!allocated)&&((numRb - rbAllocated + rbPerFlow ) > 1) && (rbPerFlow != 0))
		{
			// check availability
			bool free = true;
			for (uint16_t j = rbAllocated; j < rbAllocated + rbPerFlow; j++)
			{
				if (rbMap.at (j) == true)
				{
					free = false;
					break;
				}
			}
			if (free)
			{
				newTbInfoElem.m_rbStart = rbAllocated;

				for (uint16_t j = rbAllocated; j < rbAllocated + rbPerFlow; j++)
				{
					rbMap.at (j) = true;
					// store info on allocation for managing ul-cqi interpretation
					rbgAllocationMap.at (j) = (*it).first;
					NS_LOG_INFO ("\t rbAllocated " << j);
				}
				rbAllocated += rbPerFlow;
				allocated = true;
				break;
			}
			rbAllocated++;
			//					if (rbAllocated + rbPerFlow - 1 > numRb)
			//					{
			//						// limit to physical resources last resource assignment
			//						rbPerFlow = numRb - rbAllocated;
			//						// at least 3 rbg per flow to ensure TxOpportunity >= 7 bytes
			//						if (rbPerFlow < 3)
			//						{
			//							// terminate allocation
			//							rbPerFlow = 0;
			//						}
			//					}
		}
		if (!allocated)
		{
			// unable to allocate new resource: finish scheduling
			m_nextRntiUl = (*it).first;
			m_allocationMaps.insert (std::pair <uint32_t, std::vector <uint16_t> > (sfn, rbgAllocationMap));

			break;
		}
		std::map <uint16_t, std::vector <double> >::iterator itCqi = m_ueUlCqi.find ((*it).first);
		int cqi = 0;
		if (itCqi == m_ueUlCqi.end ())
		{
			// no cqi info about this UE
			newTbInfoElem.m_mcs = 0; // MCS 0 -> UL-AMC TBD
			NS_LOG_INFO (this << " UE does not have UL-CQI " << (*it).first );
		}
		else
		{
			// take the lowest CQI value (worst RB)
			double minSinr = (*itCqi).second.at (newTbInfoElem.m_rbStart);
			for (uint16_t i = newTbInfoElem.m_rbStart; i < newTbInfoElem.m_rbStart + newTbInfoElem.m_rbLen; i++)
			{
				if ((*itCqi).second.at (i) < minSinr)
				{
					minSinr = (*itCqi).second.at (i);
				}
			}
			// translate SINR -> cqi: WILD ACK: same as DL
			double s = log2 ( 1 + (
					std::pow (10, minSinr / 10 )  /
					( (-std::log (5.0 * 0.00005 )) / 1.5) ));


			cqi = m_amc->GetCqiFromSpectralEfficiency (s);
			if (cqi == 0)
			{
				NS_LOG_INFO ("*** RNTI " << schedInfo.m_rnti << " UL CQI out of range, skipping allocation in UL for slot " << slotNum+1);
				it++;
				if (it == m_ceBsrRxed.end ())
				{
					// restart from the first
					it = m_ceBsrRxed.begin ();
				}
				NS_LOG_INFO (this << " UE discared for CQI=0, RNTI " << schedInfo.m_rnti);
				// remove UE from allocation map
				for (uint16_t i = newTbInfoElem.m_rbStart; i < newTbInfoElem.m_rbStart + newTbInfoElem.m_rbLen; i++)
				{
					rbgAllocationMap.at (i) = 0;
					rbMap.at (i) = 0;
				}
				continue; // CQI == 0 means "out of range" (see table 7.2.3-1 of 36.213)
			}
			newTbInfoElem.m_mcs = m_amc->GetMcsFromCqi (cqi);
		}
		MmWaveMacPduHeader macHeader;
		newTbInfoElem.m_tbSize = (m_amc->GetTbSizeFromMcs (newTbInfoElem.m_mcs, rbPerFlow) / 8) - macHeader.GetSerializedSize (); // MCS 0 -> UL-AMC TBD

		UpdateUlRlcBufferInfo (schedInfo.m_rnti, newTbInfoElem.m_tbSize);
		newTbInfoElem.m_ndi = 1;
		schedInfo.m_dci.m_tddBitmap = (schedInfo.m_dci.m_tddBitmap | (0x1 << slotNum)); // set bit for UL
		newTbInfoElem.m_harqProcess = UpdateUlHarqProcessId (rnti);
		//schedInfo.m_rlcPduList.push_back(std::vector<RlcPduInfo> ());  // vector to store RLC PDUs for new TB
		schedInfo.m_dci.m_tbInfoElements.push_back (newTbInfoElem);
		success = true;

		uint8_t harqId = 0;
		if (m_harqOn == true)
		{
			std::map <uint16_t, uint8_t>::iterator itProcId = m_ulHarqCurrentProcessId.find (schedInfo.m_rnti);
			if (itProcId == m_ulHarqCurrentProcessId.end ())
			{
				NS_FATAL_ERROR ("No info find in HARQ buffer for UE " << schedInfo.m_rnti);
			}
			harqId = (*itProcId).second;
			std::map <uint16_t, UlHarqProcessesTbInfoList_t>::iterator itHarqTbInfo = m_ulHarqProcessesTbInfoMap.find (schedInfo.m_rnti);
			if (itHarqTbInfo == m_ulHarqProcessesTbInfoMap.end ())
			{
				NS_FATAL_ERROR ("Unable to find RNTI entry in UL DCI HARQ buffer for RNTI " << schedInfo.m_rnti);
			}
			(*itHarqTbInfo).second.at (harqId) = newTbInfoElem;
			// Update HARQ process status (RV 0)
			std::map <uint16_t, UlHarqProcessesStatus_t>::iterator itStat = m_ulHarqProcessesStatus.find (schedInfo.m_rnti);
			if (itStat == m_ulHarqProcessesStatus.end ())
			{
				NS_LOG_ERROR ("No info find in HARQ buffer for UE (might change eNB) " << schedInfo.m_rnti);
			}
			(*itStat).second.at (harqId) = 0;
		}

		NS_LOG_DEBUG ("UL Allocation frame " << frameNum << " subframe " << sfNum << " slot " << slotNum+1 << " " << " RNTI " << schedInfo.m_dci.m_rnti << " startPRB " << (uint32_t)newTbInfoElem.m_rbStart << " nPRB " << (uint32_t)newTbInfoElem.m_rbLen << " CQI " << cqi << " MCS " << (uint32_t)newTbInfoElem.m_mcs << " TBsize " << newTbInfoElem.m_tbSize << " harqId " << (uint16_t)harqId);

		it++;
		if (it == m_ceBsrRxed.end ())
		{
			// restart from the first
			it = m_ceBsrRxed.begin ();
		}
		if ((rbAllocated == numRb) || (rbPerFlow == 0))
		{
			// Stop allocation: no more PRBs
			m_nextRntiUl = (*it).first;
			break;
		}
	}
	while (((*it).first != m_nextRntiUl)&&(rbPerFlow!=0));

	m_allocationMaps.insert (std::pair <uint32_t, std::vector <uint16_t> > (sfn, rbgAllocationMap));

//	std::cout << "Inserting rbgAllocationMap for sfn " << sfn << " frame " << frameNum << " subframe " << sfNum << " slot " << slotNum+1 << " ";
//	for (unsigned i = 0; i < rbgAllocationMap.size(); i++)
//	{
//		std::cout << "RNTI " << rbgAllocationMap[i] << " ";
//	}
//	std::cout << std::endl;

	return success;
}

void
MmWaveRrMacScheduler::DoSchedTriggerReq (const struct MmWaveMacSchedSapProvider::SchedTriggerReqParameters& params)
{
	uint16_t frameNum = params.m_snfSf >> 16;
	uint8_t	 sfNum = (params.m_snfSf & 0xff00)>>8;
	NS_LOG_INFO ("Scheduling frame "<< (unsigned)frameNum << " subframe " << (unsigned)sfNum );

	MmWaveMacSchedSapUser::SchedConfigIndParameters ret;
	ret.m_sfn = params.m_snfSf;
	//	std::map<uint16_t,SchedInfo>& schedInfoMap = ret.m_schedInfoMap;

	unsigned ulFrameNum;
	unsigned ulSfNum = sfNum + m_phyMacConfig->GetUlSchedDelay () - 1;
	if (ulSfNum > 10)
	{
		ulFrameNum = frameNum + 1;
		ulSfNum = ulSfNum - 10;
	}
	else
	{
		ulFrameNum = frameNum;
	}

	RefreshDlCqiMaps ();
	RefreshUlCqiMaps ();

	for (unsigned int slotNum = 0; slotNum < m_phyMacConfig->GetSlotsPerSubframe (); slotNum++)
	{
		if ((slotNum % 2) == 0) // schedule current slot for DOWNLINK
		{
			if ( !DoSchedDlTriggerReq (params, ret, frameNum, sfNum, slotNum) && (slotNum != 0))
			{
				// failed to allocate any users in DL, try to allocate in UL (slot 1 reserved for DL)
				//DoSchedUlTriggerReq (params, ret, frameNum, sfNum, slotNum);
			}
		}
		else
		{

			if ( !DoSchedUlTriggerReq (params, ret, ulFrameNum, ulSfNum, slotNum) && (slotNum != 1))
			{
				// failed to allocate any users in UL, try to allocate in DL (slot 2 reserved for UL)
				//DoSchedDlTriggerReq (params, ret, frameNum, sfNum, slotNum)
			}

//			std::map<uint16_t, SchedInfo>::const_iterator it = ret.m_schedInfoMap.begin ();
//			for (; it != ret.m_schedInfoMap.end (); it++)
//			{
//				std::cout << "RrScheduler: UL TBs for rnti " << it->second.m_dci.m_rnti << " frame " << ulFrameNum << " subframe " << (unsigned)ulSfNum << " slotNum " << (unsigned)slotNum;
//				for (unsigned itb = 0; itb < it->second.m_dci.m_tbInfoElements.size (); itb++)
//				{
//					std::cout << " tb size " << it->second.m_dci.m_tbInfoElements[itb].m_tbSize;
//				}
//				std::cout << std::endl;
//			}
		}
	}

	m_macSchedSapUser->SchedConfigInd (ret);
	return;
}

void
MmWaveRrMacScheduler::DoSchedUlMacCtrlInfoReq (const struct MmWaveMacSchedSapProvider::SchedUlMacCtrlInfoReqParameters& params)
{
	NS_LOG_FUNCTION (this);

	std::map <uint16_t,uint32_t>::iterator it;

	for (unsigned int i = 0; i < params.m_macCeList.size (); i++)
	{
		if ( params.m_macCeList.at (i).m_macCeType == MacCeElement::BSR )
		{
			// buffer status report
			// note that this scheduler does not differentiate the
			// allocation according to which LCGs have more/less bytes
			// to send.
			// Hence the BSR of different LCGs are just summed up to get
			// a total queue size that is used for allocation purposes.

			uint32_t buffer = 0;
			for (uint8_t lcg = 0; lcg < 4; ++lcg)
			{
				uint8_t bsrId = params.m_macCeList.at (i).m_macCeValue.m_bufferStatus.at (lcg);
				buffer += BsrId2BufferSize (bsrId);
			}

			uint16_t rnti = params.m_macCeList.at (i).m_rnti;
			it = m_ceBsrRxed.find (rnti);
			if (it == m_ceBsrRxed.end ())
			{
				// create the new entry
				m_ceBsrRxed.insert ( std::pair<uint16_t, uint32_t > (rnti, buffer));
				NS_LOG_INFO (this << " Insert RNTI " << rnti << " queue " << buffer);
			}
			else
			{
				// update the buffer size value
				(*it).second = buffer;
				NS_LOG_INFO (this << " Update RNTI " << rnti << " queue " << buffer);
			}
		}
	}

	return;
}

bool
MmWaveRrMacScheduler::SortRlcBufferReq (MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters i, MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters j)
{
  return (i.m_rnti < j.m_rnti);
}


void
MmWaveRrMacScheduler::RefreshDlCqiMaps (void)
{
  NS_LOG_FUNCTION (this << m_wbCqiTimers.size ());
  // refresh DL CQI P01 Map
  std::map <uint16_t,uint32_t>::iterator itP10 = m_wbCqiTimers.begin ();
  while (itP10 != m_wbCqiTimers.end ())
    {
      NS_LOG_INFO (this << " P10-CQI for user " << (*itP10).first << " is " << (uint32_t)(*itP10).second << " thr " << (uint32_t)m_cqiTimersThreshold);
      if ((*itP10).second == 0)
        {
          // delete correspondent entries
          std::map <uint16_t,uint8_t>::iterator itMap = m_wbCqiRxed.find ((*itP10).first);
          NS_ASSERT_MSG (itMap != m_wbCqiRxed.end (), " Does not find CQI report for user " << (*itP10).first);
          NS_LOG_INFO (this << " P10-CQI exired for user " << (*itP10).first);
          m_wbCqiRxed.erase (itMap);
          std::map <uint16_t,uint32_t>::iterator temp = itP10;
          itP10++;
          m_wbCqiTimers.erase (temp);
        }
      else
        {
          (*itP10).second--;
          itP10++;
        }
    }

  return;
}


void
MmWaveRrMacScheduler::RefreshUlCqiMaps (void)
{
  // refresh UL CQI  Map
  std::map <uint16_t,uint32_t>::iterator itUl = m_ueCqiTimers.begin ();
  while (itUl != m_ueCqiTimers.end ())
    {
      NS_LOG_INFO (this << " UL-CQI for user " << (*itUl).first << " is " << (uint32_t)(*itUl).second << " thr " << (uint32_t)m_cqiTimersThreshold);
      if ((*itUl).second == 0)
        {
          // delete correspondent entries
          std::map <uint16_t, std::vector <double> >::iterator itMap = m_ueUlCqi.find ((*itUl).first);
          NS_ASSERT_MSG (itMap != m_ueUlCqi.end (), " Does not find CQI report for user " << (*itUl).first);
          NS_LOG_INFO (this << " UL-CQI expired for user " << (*itUl).first);
          (*itMap).second.clear ();
          m_ueUlCqi.erase (itMap);
          std::map <uint16_t,uint32_t>::iterator temp = itUl;
          itUl++;
          m_ueCqiTimers.erase (temp);
        }
      else
        {
          (*itUl).second--;
          itUl++;
        }
    }

  return;
}

void
MmWaveRrMacScheduler::UpdateDlRlcBufferInfo (uint16_t rnti, uint8_t lcid, uint16_t size)
{
  NS_LOG_FUNCTION (this);
  std::list<MmWaveMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it;
  for (it = m_rlcBufferReq.begin (); it != m_rlcBufferReq.end (); it++)
    {
      if (((*it).m_rnti == rnti) && ((*it).m_logicalChannelIdentity == lcid))
        {
          NS_LOG_INFO (this << " UE " << rnti << " LC " << (uint16_t)lcid << " txqueue " << (*it).m_rlcTransmissionQueueSize << " retxqueue " << (*it).m_rlcRetransmissionQueueSize << " status " << (*it).m_rlcStatusPduSize << " decrease " << size);
          // Update queues: RLC tx order Status, ReTx, Tx
          // Update status queue
           if (((*it).m_rlcStatusPduSize > 0) && (size >= (*it).m_rlcStatusPduSize))
              {
                (*it).m_rlcStatusPduSize = 0;
              }
            else if (((*it).m_rlcRetransmissionQueueSize > 0) && (size >= (*it).m_rlcRetransmissionQueueSize))
              {
                (*it).m_rlcRetransmissionQueueSize = 0;
              }
            else if ((*it).m_rlcTransmissionQueueSize > 0)
              {
                uint32_t rlcOverhead;
                if (lcid == 1)
                  {
                    // for SRB1 (using RLC AM) it's better to
                    // overestimate RLC overhead rather than
                    // underestimate it and risk unneeded
                    // segmentation which increases delay
                    rlcOverhead = 4;
                  }
                else
                  {
                    // minimum RLC overhead due to header
                    rlcOverhead = 2;
                  }
                // update transmission queue
                if ((*it).m_rlcTransmissionQueueSize <= size - rlcOverhead)
                  {
                    (*it).m_rlcTransmissionQueueSize = 0;
                  }
                else
                  {
                    (*it).m_rlcTransmissionQueueSize -= size - rlcOverhead;
                  }
              }
          return;
        }
    }
}

void
MmWaveRrMacScheduler::UpdateUlRlcBufferInfo (uint16_t rnti, uint16_t size)
{

  size = size - 2; // remove the minimum RLC overhead
  std::map <uint16_t,uint32_t>::iterator it = m_ceBsrRxed.find (rnti);
  if (it != m_ceBsrRxed.end ())
    {
      NS_LOG_INFO (this << " Update RLC BSR UE " << rnti << " size " << size << " BSR " << (*it).second);
      if ((*it).second >= size)
        {
          (*it).second -= size;
        }
      else
        {
          (*it).second = 0;
        }
    }
  else
    {
      NS_LOG_ERROR (this << " Does not find BSR report info of UE " << rnti);
    }

}

/*
void
MmWaveRrMacScheduler::DoCschedCellConfigReq (const struct MmWaveMacCschedSapProvider::CschedCellConfigReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // Read the subset of parameters used
  m_cschedCellConfig = params;
  m_rachAllocationMap.resize (m_cschedCellConfig.m_ulBandwidth, 0);
  FfMacCschedSapUser::CschedUeConfigCnfParameters cnf;
  cnf.m_result = SUCCESS;
  m_cschedSapUser->CschedUeConfigCnf (cnf);
  return;
}

void
MmWaveRrMacScheduler::DoCschedUeConfigReq (const struct MmWaveMacCschedSapProvider::CschedUeConfigReqParameters& params)
{
  NS_LOG_FUNCTION (this << " RNTI " << params.m_rnti << " txMode " << (uint16_t)params.m_transmissionMode);
  std::map <uint16_t,uint8_t>::iterator it = m_uesTxMode.find (params.m_rnti);
  if (it == m_uesTxMode.end ())
    {
//      m_uesTxMode.insert (std::pair <uint16_t, double> (params.m_rnti, params.m_transmissionMode));
      // generate HARQ buffers
      m_dlHarqCurrentProcessId.insert (std::pair <uint16_t,uint8_t > (params.m_rnti, 0));
      DlHarqProcessesStatus_t dlHarqPrcStatus;
      dlHarqPrcStatus.resize (8,0);
      m_dlHarqProcessesStatus.insert (std::pair <uint16_t, DlHarqProcessesStatus_t> (params.m_rnti, dlHarqPrcStatus));
      DlHarqProcessesTimer_t dlHarqProcessesTimer;
      dlHarqProcessesTimer.resize (8,0);
      m_dlHarqProcessesTimer.insert (std::pair <uint16_t, DlHarqProcessesTimer_t> (params.m_rnti, dlHarqProcessesTimer));
      DlHarqProcessesDciBuffer_t dlHarqdci;
      dlHarqdci.resize (8);
      m_dlHarqProcessesTbInfoMap.insert (std::pair <uint16_t, DlHarqProcessesTbInfoList_t> (params.m_rnti, dlHarqdci));
      DlHarqRlcPduListBuffer_t dlHarqRlcPdu;
      dlHarqRlcPdu.resize (2);
      dlHarqRlcPdu.at (0).resize (8);
      dlHarqRlcPdu.at (1).resize (8);
      m_dlHarqProcessesRlcPduMap.insert (std::pair <uint16_t, DlHarqRlcPduListBuffer_t> (params.m_rnti, dlHarqRlcPdu));
      m_ulHarqCurrentProcessId.insert (std::pair <uint16_t,uint8_t > (params.m_rnti, 0));
      UlHarqProcessesStatus_t ulHarqPrcStatus;
      ulHarqPrcStatus.resize (8,0);
      m_ulHarqProcessesStatus.insert (std::pair <uint16_t, UlHarqProcessesStatus_t> (params.m_rnti, ulHarqPrcStatus));
      UlHarqProcessesDciBuffer_t ulHarqdci;
      ulHarqdci.resize (8);
      m_ulHarqProcessesTbInfoMap.insert (std::pair <uint16_t, UlHarqProcessesTbInfoList_t> (params.m_rnti, ulHarqdci));
    }
  else
    {
      (*it).second = params.m_transmissionMode;
    }
  return;
}

void
MmWaveRrMacScheduler::DoCschedLcConfigReq (const struct MmwaveMacCschedSapProvider::CschedLcConfigReqParameters& params)
{
  NS_LOG_FUNCTION (this);
  // Not used at this stage (LCs updated by DoSchedDlRlcBufferReq)
  return;
}

void
MmWaveRrMacScheduler::DoCschedLcReleaseReq (const struct MmWaveMacCschedSapProvider::CschedLcReleaseReqParameters& params)
{
  NS_LOG_FUNCTION (this);
    for (uint16_t i = 0; i < params.m_logicalChannelIdentity.size (); i++)
    {
     std::list<FfMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it = m_rlcBufferReq.begin ();
      while (it!=m_rlcBufferReq.end ())
        {
          if (((*it).m_rnti == params.m_rnti)&&((*it).m_logicalChannelIdentity == params.m_logicalChannelIdentity.at (i)))
            {
              it = m_rlcBufferReq.erase (it);
            }
          else
            {
              it++;
            }
        }
    }
  return;
}

void
MmWaveRrMacScheduler::DoCschedUeReleaseReq (const struct MmWaveMacCschedSapProvider::CschedUeReleaseReqParameters& params)
{
  NS_LOG_FUNCTION (this << " Release RNTI " << params.m_rnti);

  m_uesTxMode.erase (params.m_rnti);
  m_dlHarqCurrentProcessId.erase (params.m_rnti);
  m_dlHarqProcessesStatus.erase  (params.m_rnti);
  m_dlHarqProcessesTimer.erase (params.m_rnti);
  m_dlHarqProcessesDciBuffer.erase  (params.m_rnti);
  m_dlHarqProcessesRlcPduListBuffer.erase  (params.m_rnti);
  m_ulHarqCurrentProcessId.erase  (params.m_rnti);
  m_ulHarqProcessesStatus.erase  (params.m_rnti);
  m_ulHarqProcessesDciBuffer.erase  (params.m_rnti);
  m_ceBsrRxed.erase (params.m_rnti);
  std::list<FfMacSchedSapProvider::SchedDlRlcBufferReqParameters>::iterator it = m_rlcBufferReq.begin ();
  while (it != m_rlcBufferReq.end ())
    {
      if ((*it).m_rnti == params.m_rnti)
        {
          NS_LOG_INFO (this << " Erase RNTI " << (*it).m_rnti << " LC " << (uint16_t)(*it).m_logicalChannelIdentity);
          it = m_rlcBufferReq.erase (it);
        }
      else
        {
          it++;
        }
    }
  if (m_nextRntiUl == params.m_rnti)
    {
      m_nextRntiUl = 0;
    }

  if (m_nextRntiDl == params.m_rnti)
    {
      m_nextRntiDl = 0;
    }

  return;
}
*/

}

}
