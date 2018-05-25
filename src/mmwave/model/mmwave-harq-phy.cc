 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *                 Dual Connectivity and Handover functionalities
 */


#include <ns3/mmwave-harq-phy.h>
#include <ns3/log.h>
#include <ns3/assert.h>

NS_LOG_COMPONENT_DEFINE ("MmWaveHarqPhy");

namespace ns3 {

namespace mmwave {

//NS_OBJECT_ENSURE_REGISTERED (MmWaveHarqPhy)
//  ;


MmWaveHarqPhy::MmWaveHarqPhy (uint32_t harqNum)
{
	m_harqNum = harqNum;
	NS_LOG_DEBUG ("m_miDlHarqProcessesInfoMap size == " << m_miDlHarqProcessesInfoMap.size());
}


MmWaveHarqPhy::~MmWaveHarqPhy ()
{
  m_miDlHarqProcessesInfoMap.clear ();
  m_miUlHarqProcessesInfoMap.clear ();
}

void
MmWaveHarqPhy::SubframeIndication (SfnSf sfn)
{
  NS_LOG_FUNCTION (this);
  return;
}


double
MmWaveHarqPhy::GetAccumulatedMiDl (uint16_t rnti, uint8_t harqId)
{
  NS_LOG_FUNCTION (this << (uint16_t)rnti << (uint16_t)harqId);
  std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> >::iterator it;
  it = m_miDlHarqProcessesInfoMap.find (rnti);
  NS_ASSERT_MSG (it!=m_miDlHarqProcessesInfoMap.end (), " Does not find MI for RNTI");
  MmWaveHarqProcessInfoList_t list = (*it).second.at (harqId);
  double mi = 0.0;
  for (uint8_t i = 0; i < list.size (); i++)
  {
  	mi += list.at (i).m_mi;
  }
  return (mi);
}

MmWaveHarqProcessInfoList_t
MmWaveHarqPhy::GetHarqProcessInfoDl (uint16_t rnti, uint8_t harqProcId)
{
	NS_LOG_FUNCTION (this << rnti << (uint16_t)harqProcId);
	std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> >::iterator it;
	it = m_miDlHarqProcessesInfoMap.find (rnti);
	if (it==m_miDlHarqProcessesInfoMap.end ())
	{
		// new entry
		std::vector <MmWaveHarqProcessInfoList_t> harqList;
		harqList.resize (m_harqNum);
		m_miDlHarqProcessesInfoMap.insert (std::pair <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> > (rnti, harqList));
		return (harqList.at (harqProcId));
	}
	else
	{
		return ((*it).second.at (harqProcId));
	}
}


double
MmWaveHarqPhy::GetAccumulatedMiUl (uint16_t rnti, uint8_t harqId)
{
  NS_LOG_FUNCTION (this << rnti);

  std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> >::iterator it;
  it = m_miUlHarqProcessesInfoMap.find (rnti);
  NS_ASSERT_MSG (it!=m_miUlHarqProcessesInfoMap.end (), " Does not find MI for RNTI");
  MmWaveHarqProcessInfoList_t list = (*it).second.at (harqId);
  double mi = 0.0;
  for (uint8_t i = 0; i < list.size (); i++)
  {
  	mi += list.at (i).m_mi;
  }
  return (mi);
}

MmWaveHarqProcessInfoList_t
MmWaveHarqPhy::GetHarqProcessInfoUl (uint16_t rnti, uint8_t harqProcId)
{
	NS_LOG_FUNCTION (this << rnti << (uint16_t)harqProcId);
	std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> >::iterator it;
	it = m_miUlHarqProcessesInfoMap.find (rnti);
	if (it==m_miUlHarqProcessesInfoMap.end ())
	{
		// new entry
		std::vector <MmWaveHarqProcessInfoList_t> harqList;
		harqList.resize (m_harqNum);
		m_miUlHarqProcessesInfoMap.insert (std::pair <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> > (rnti, harqList));
		return (harqList.at (harqProcId));
	}
	else
	{
		return ((*it).second.at (harqProcId));
	}
}



void
MmWaveHarqPhy::UpdateDlHarqProcessStatus (uint16_t rnti, uint8_t harqId, double mi, uint32_t infoBytes, uint32_t codeBytes)
{
  NS_LOG_FUNCTION (this << (uint16_t) harqId << mi);
  std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> >::iterator it;
    it = m_miDlHarqProcessesInfoMap.find (rnti);
    if (it==m_miDlHarqProcessesInfoMap.end ())
      {
        // new entry
        std::vector <MmWaveHarqProcessInfoList_t> harqList;
        harqList.resize (m_harqNum);
        MmWaveHarqProcessInfoElement_t el;
        el.m_mi = mi;
        el.m_rv = 0;
        el.m_infoBits = infoBytes * 8;
        el.m_codeBits = codeBytes * 8;
        harqList.at (harqId).push_back (el);
        m_miDlHarqProcessesInfoMap.insert (std::pair <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> > (rnti, harqList));
      }
    else
      {
        if ((*it).second.at (harqId).size () == 3) // MAX HARQ RETX
          {
            // HARQ should be disabled -> discard info
            return;
          }
        MmWaveHarqProcessInfoElement_t el;
        el.m_mi = mi;
        if(!(*it).second.at (harqId).empty ())
        {
        	el.m_rv = (*it).second.at (harqId).back().m_rv + 1;
        }
        else
        {
        	el.m_rv = 0;
        }
        el.m_infoBits = infoBytes * 8;
        el.m_codeBits = codeBytes * 8;
        (*it).second.at (harqId).push_back (el);
      }
}


void
MmWaveHarqPhy::ResetDlHarqProcessStatus (uint16_t rnti, uint8_t id)
{
  NS_LOG_FUNCTION (this << (uint16_t) id);

  NS_LOG_FUNCTION (this << rnti << (uint16_t)id);
  std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> >::iterator it;
  it = m_miDlHarqProcessesInfoMap.find (rnti);
  if (it==m_miDlHarqProcessesInfoMap.end ())
  {
  	// new entry
  	std::vector <MmWaveHarqProcessInfoList_t> harqList;
  	harqList.resize (m_harqNum);
  	m_miDlHarqProcessesInfoMap.insert (std::pair <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> > (rnti, harqList));
  }
  else
  {
  	(*it).second.at (id).clear ();
  }
}


void
MmWaveHarqPhy::UpdateUlHarqProcessStatus (uint16_t rnti, uint8_t harqId, double mi, uint32_t infoBytes, uint32_t codeBytes)
{
  NS_LOG_FUNCTION (this << rnti << mi);
  std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> >::iterator it;
  it = m_miUlHarqProcessesInfoMap.find (rnti);
  if (it==m_miUlHarqProcessesInfoMap.end ())
    {
      // new entry
      std::vector <MmWaveHarqProcessInfoList_t> harqList;
      harqList.resize (m_harqNum);
      MmWaveHarqProcessInfoElement_t el;
      el.m_mi = mi;
      el.m_rv = 0;
      el.m_infoBits = infoBytes * 8;
      el.m_codeBits = codeBytes * 8;
      harqList.at (harqId).push_back (el);
      m_miUlHarqProcessesInfoMap.insert (std::pair <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> > (rnti, harqList));
    }
  else
    {
      if ((*it).second.at (harqId).size () == 3) // MAX HARQ RETX
        {
          // HARQ should be disabled -> discard info
          return;
        }
      MmWaveHarqProcessInfoElement_t el;
      el.m_mi = mi;
      if(!(*it).second.at (harqId).empty ())
      {
      	el.m_rv = (*it).second.at (harqId).back().m_rv + 1;
      }
      else
      {
      	el.m_rv = 0;
      }
      el.m_infoBits = infoBytes * 8;
      el.m_codeBits = codeBytes * 8;
      (*it).second.at (harqId).push_back (el);
    }
}

void
MmWaveHarqPhy::ResetUlHarqProcessStatus (uint16_t rnti, uint8_t id)
{
	NS_LOG_FUNCTION (this << rnti << (uint16_t)id);
	std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> >::iterator it;
	it = m_miUlHarqProcessesInfoMap.find (rnti);
	if (it==m_miUlHarqProcessesInfoMap.end ())
	{
		// new entry
		std::vector <MmWaveHarqProcessInfoList_t> harqList;
		harqList.resize (m_harqNum);
		m_miUlHarqProcessesInfoMap.insert (std::pair <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> > (rnti, harqList));
	}
	else
	{
		(*it).second.at (id).clear ();
	}
}


} // namespace mmwave

} // namespace ns3
