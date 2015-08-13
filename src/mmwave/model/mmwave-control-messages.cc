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

MmWaveControlMessage::MmWaveControlMessage (void)
{
	NS_LOG_INFO (this);
}

MmWaveControlMessage::~MmWaveControlMessage (void)
{
	NS_LOG_INFO (this);
}

void
MmWaveControlMessage::SetMessageType (messageType type)
{
	m_messageType = type;
}

MmWaveControlMessage::messageType
MmWaveControlMessage::GetMessageType (void)
{
	return m_messageType;
}

MmWaveDciMessage::MmWaveDciMessage (void)
{
	NS_LOG_INFO (this);
	SetMessageType (MmWaveControlMessage::DCI);
}

MmWaveDciMessage::~MmWaveDciMessage (void)
{
	NS_LOG_INFO (this);
}


void
MmWaveDciMessage::SetDciInfoElement (DciInfoElement dci)
{
	m_dciInfoElement = dci;
}

DciInfoElement
MmWaveDciMessage::GetDciInfoElement (void)
{
	return m_dciInfoElement;
}

void
MmWaveDciMessage::SetSfnSf (uint32_t sfn)
{
	m_sfnSf = sfn;
}

uint32_t
MmWaveDciMessage::GetSfnSf (void)
{
	return m_sfnSf;
}

MmWaveDlCqiMessage::MmWaveDlCqiMessage (void)
{
	SetMessageType (MmWaveControlMessage::DL_CQI);
	NS_LOG_INFO (this);
}
MmWaveDlCqiMessage::~MmWaveDlCqiMessage (void)
{
	NS_LOG_INFO (this);
}

void
MmWaveDlCqiMessage::SetDlCqi (DlCqiInfo cqi)
{
	m_cqi = cqi;
}

DlCqiInfo
MmWaveDlCqiMessage::GetDlCqi ()
{
	return m_cqi;
}

// ----------------------------------------------------------------------------------------------------------

MmWaveBsrMessage::MmWaveBsrMessage (void)
{
  SetMessageType (MmWaveControlMessage::BSR);
}


MmWaveBsrMessage::~MmWaveBsrMessage (void)
{

}

void
MmWaveBsrMessage::SetBsr (MacCeElement bsr)
{
  m_bsr = bsr;

}


MacCeElement
MmWaveBsrMessage::GetBsr (void)
{
  return m_bsr;
}

// ----------------------------------------------------------------------------------------------------------



MmWaveMibMessage::MmWaveMibMessage (void)
{
  SetMessageType (MmWaveControlMessage::MIB);
}


void
MmWaveMibMessage::SetMib (LteRrcSap::MasterInformationBlock  mib)
{
  m_mib = mib;
}

LteRrcSap::MasterInformationBlock
MmWaveMibMessage::GetMib () const
{
  return m_mib;
}


// ----------------------------------------------------------------------------------------------------------



MmWaveSib1Message::MmWaveSib1Message (void)
{
  SetMessageType (MmWaveControlMessage::SIB1);
}


void
MmWaveSib1Message::SetSib1 (LteRrcSap::SystemInformationBlockType1 sib1)
{
  m_sib1 = sib1;
}

LteRrcSap::SystemInformationBlockType1
MmWaveSib1Message::GetSib1 () const
{
  return m_sib1;
}



// ----------------------------------------------------------------------------------------------------------

MmWaveRachPreambleMessage::MmWaveRachPreambleMessage (void)
{
  SetMessageType (MmWaveControlMessage::RACH_PREAMBLE);
}

void
MmWaveRachPreambleMessage::SetRapId (uint32_t rapId)
{
  m_rapId = rapId;
}

uint32_t
MmWaveRachPreambleMessage::GetRapId () const
{
  return m_rapId;
}

// ----------------------------------------------------------------------------------------------------------


MmWaveRarMessage::MmWaveRarMessage (void)
{
  SetMessageType (MmWaveControlMessage::RAR);
}


void
MmWaveRarMessage::SetRaRnti (uint16_t raRnti)
{
  m_raRnti = raRnti;
}

uint16_t
MmWaveRarMessage::GetRaRnti () const
{
  return m_raRnti;
}


void
MmWaveRarMessage::AddRar (Rar rar)
{
  m_rarList.push_back (rar);
}

std::list<MmWaveRarMessage::Rar>::const_iterator
MmWaveRarMessage::RarListBegin () const
{
  return m_rarList.begin ();
}

std::list<MmWaveRarMessage::Rar>::const_iterator
MmWaveRarMessage::RarListEnd () const
{
  return m_rarList.end ();
}

MmWaveDlHarqFeedbackMessage::MmWaveDlHarqFeedbackMessage (void)
{
  SetMessageType (MmWaveControlMessage::DL_HARQ);
}


MmWaveDlHarqFeedbackMessage::~MmWaveDlHarqFeedbackMessage (void)
{

}

void
MmWaveDlHarqFeedbackMessage::SetDlHarqFeedback (DlHarqInfo m)
{
  m_dlHarqInfo = m;
}


DlHarqInfo
MmWaveDlHarqFeedbackMessage::GetDlHarqFeedback (void)
{
  return m_dlHarqInfo;
}

}

