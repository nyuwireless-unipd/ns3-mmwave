/*
 * mmwave-control-messages.cc
 *
 *  Created on: Jan 13, 2015
 *      Author: sourjya
 */

#include <ns3/log.h>
#include "mmwave-control-messages.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("mmWaveControlMessage");

mmWaveControlMessages::mmWaveControlMessages (void)
{
	NS_LOG_INFO (this);
}

mmWaveControlMessages::~mmWaveControlMessages (void)
{
	NS_LOG_INFO (this);
}

void
mmWaveControlMessages::SetMessageType (messageType type)
{
	m_messageType = type;
}

mmWaveControlMessages::messageType
mmWaveControlMessages::GetMessageType (void)
{
	return m_messageType;
}

mmWaveResourceAllocation::mmWaveResourceAllocation (void)
{
	NS_LOG_INFO (this);
	SetMessageType (mmWaveControlMessages::RSC_ALLOCATION);
}

mmWaveResourceAllocation::~mmWaveResourceAllocation (void)
{
	NS_LOG_INFO (this);
}

void
mmWaveResourceAllocation::SetAllocationMap (allocationList allocMap)
{
	m_rscAllocationMap = allocMap;
}

allocationList
mmWaveResourceAllocation::GetAllocationMap (void)
{
	return m_rscAllocationMap;
}

void
mmWaveResourceAllocation::SetSchedule (Schedule sched)
{
	m_currentSchedule = sched;
}

Schedule
mmWaveResourceAllocation::GetSchedule (void)
{
	return m_currentSchedule;
}

void
mmWaveResourceAllocation::SetSFNSF (uint32_t sfn)
{
	m_sfnsf = sfn;
}

uint32_t
mmWaveResourceAllocation::GetSFNSF (void)
{
	return m_sfnsf;
}

mmWaveCqiReport::mmWaveCqiReport (void)
{
	SetMessageType (mmWaveControlMessages::CQI);
	NS_LOG_INFO (this);
}
mmWaveCqiReport::~mmWaveCqiReport (void)
{
	NS_LOG_INFO (this);
}

void
mmWaveCqiReport::SetCqiReport (CqiInfo cqi)
{
	m_Cqi = cqi;
}

CqiInfo
mmWaveCqiReport::GetCqiReport ()
{
	return m_Cqi;
}

// ----------------------------------------------------------------------------------------------------------



MibmmWaveControlMessage::MibmmWaveControlMessage (void)
{
  SetMessageType (mmWaveControlMessages::MIB);
}


void
MibmmWaveControlMessage::SetMib (LteRrcSap::MasterInformationBlock  mib)
{
  m_mib = mib;
}

LteRrcSap::MasterInformationBlock
MibmmWaveControlMessage::GetMib () const
{
  return m_mib;
}


// ----------------------------------------------------------------------------------------------------------



Sib1mmWaveControlMessage::Sib1mmWaveControlMessage (void)
{
  SetMessageType (mmWaveControlMessages::SIB1);
}


void
Sib1mmWaveControlMessage::SetSib1 (LteRrcSap::SystemInformationBlockType1 sib1)
{
  m_sib1 = sib1;
}

LteRrcSap::SystemInformationBlockType1
Sib1mmWaveControlMessage::GetSib1 () const
{
  return m_sib1;
}



// ----------------------------------------------------------------------------------------------------------

RachPreamblemmWaveControlMessage::RachPreamblemmWaveControlMessage (void)
{
  SetMessageType (mmWaveControlMessages::RACH_PREAMBLE);
}

void
RachPreamblemmWaveControlMessage::SetRapId (uint32_t rapId)
{
  m_rapId = rapId;
}

uint32_t
RachPreamblemmWaveControlMessage::GetRapId () const
{
  return m_rapId;
}

// ----------------------------------------------------------------------------------------------------------


RarmmWaveControlMessage::RarmmWaveControlMessage (void)
{
  SetMessageType (mmWaveControlMessages::RAR);
}


void
RarmmWaveControlMessage::SetRaRnti (uint16_t raRnti)
{
  m_raRnti = raRnti;
}

uint16_t
RarmmWaveControlMessage::GetRaRnti () const
{
  return m_raRnti;
}


void
RarmmWaveControlMessage::AddRar (Rar rar)
{
  m_rarList.push_back (rar);
}

std::list<RarmmWaveControlMessage::Rar>::const_iterator
RarmmWaveControlMessage::RarListBegin () const
{
  return m_rarList.begin ();
}

std::list<RarmmWaveControlMessage::Rar>::const_iterator
RarmmWaveControlMessage::RarListEnd () const
{
  return m_rarList.end ();
}


}

