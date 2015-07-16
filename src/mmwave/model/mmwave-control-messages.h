/*
 * mmwave-control-messages.h
 *
 *  Created on: Jan 13, 2015
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_CONTROL_MESSAGES_H_
#define SRC_MMWAVE_MODEL_MMWAVE_CONTROL_MESSAGES_H_

#include <ns3/ptr.h>
#include <ns3/simple-ref-count.h>
#include "mmwave-phy-mac-common.h"
#include <list>
#include <ns3/lte-rrc-sap.h>
#include <ns3/ff-mac-common.h>

namespace ns3 {


class mmWaveControlMessages : public SimpleRefCount<mmWaveControlMessages>
{
public:
	enum messageType
	{
		RSC_ALLOCATION, // The resources allocation map from the BS to the attached UEs
		CQI,
	    MIB, // Master Information Block
	    SIB1, // System Information Block Type 1
	    RACH_PREAMBLE, // Random Access Preamble
	    RAR, // Random Access Response
	};

	mmWaveControlMessages (void);
	virtual ~mmWaveControlMessages (void);

	void SetMessageType (messageType type);

	messageType GetMessageType (void);

private:
	messageType m_messageType;
};

/************************************************************
 * Defines the time and frequency based resource allocation *
 * for the UEs attached to a given BS.                      *
 ************************************************************/

class mmWaveResourceAllocation : public mmWaveControlMessages
{
public:
	mmWaveResourceAllocation (void);
	virtual ~mmWaveResourceAllocation (void);

	void SetAllocationMap (allocationList allocMap);
	allocationList GetAllocationMap (void);

	void SetSchedule (Schedule sched);
	Schedule GetSchedule (void);

	void SetSFNSF (uint32_t sfn);
	uint32_t GetSFNSF (void);

private:
	uint32_t m_sfnsf;
	allocationList m_rscAllocationMap;
	Schedule m_currentSchedule;
};

class mmWaveCqiReport : public mmWaveControlMessages
{
public:
	mmWaveCqiReport (void);
	virtual ~mmWaveCqiReport (void);

	void SetCqiReport (CqiInfo cqi);
	CqiInfo GetCqiReport ();

private:
	CqiInfo m_Cqi;
};


// ---------------------------------------------------------------------------

/**
 * \ingroup mmWave
 * \brief Abstract model for broadcasting the Master Information Block (MIB)
 *        within the control channel (BCCH).
 *
 */
class MibmmWaveControlMessage : public mmWaveControlMessages
{
public:
  /**
   * \brief Create a new instance of MIB control message.
   */
  MibmmWaveControlMessage (void);

  /**
   * \brief Replace the MIB content of this control message.
   * \param mib the desired MIB content
   */
  void SetMib (LteRrcSap::MasterInformationBlock mib);

  /**
   * \brief Retrieve the MIB content from this control message.
   * \return the current MIB content that this control message holds
   */
  LteRrcSap::MasterInformationBlock GetMib () const;

private:
  LteRrcSap::MasterInformationBlock m_mib;

}; // end of class MibmmWaveControlMessage


// ---------------------------------------------------------------------------

/**
 * \ingroup mmWave
 * \brief Abstract model for broadcasting the System Information Block Type 1
 *        (SIB1) within the control channel (BCCH).
 *
 */
class Sib1mmWaveControlMessage : public mmWaveControlMessages
{
public:
  /**
   * \brief Create a new instance of SIB1 control message.
   */
  Sib1mmWaveControlMessage (void);

  /**
   * \brief Replace the SIB1 content of this control message.
   * \param sib1 the desired SIB1 content
   */
  void SetSib1 (LteRrcSap::SystemInformationBlockType1 sib1);

  /**
   * \brief Retrieve the SIB1 content from this control message.
   * \return the current SIB1 content that this control message holds
   */
  LteRrcSap::SystemInformationBlockType1 GetSib1 () const;

private:
  LteRrcSap::SystemInformationBlockType1 m_sib1;

}; // end of class Sib1mmWaveControlMessage
// ---------------------------------------------------------------------------

/**
 * \ingroup mmWave
 *
 * abstract model for the Random Access Preamble
 */
class RachPreamblemmWaveControlMessage : public mmWaveControlMessages
{
public:
  RachPreamblemmWaveControlMessage (void);

  /**
   * Set the Random Access Preamble Identifier (RAPID), see 3GPP TS 36.321 6.2.2
   *
   * \param rapid the RAPID
   */
  void SetRapId (uint32_t rapid);

  /**
   *
   * \return the RAPID
   */
  uint32_t GetRapId () const;

private:
  uint32_t m_rapId;

};
// ---------------------------------------------------------------------------

/**
 * \ingroup lte
 *
 * abstract model for the MAC Random Access Response message
 */
class RarmmWaveControlMessage : public mmWaveControlMessages
{
public:
	RarmmWaveControlMessage (void);

  /**
   *
   * \param raRnti the RA-RNTI, see 3GPP TS 36.321 5.1.4
   */
  void SetRaRnti (uint16_t raRnti);

  /**
   *
   * \return  the RA-RNTI, see 3GPP TS 36.321 5.1.4
   */
  uint16_t GetRaRnti () const;

  /**
   * a MAC RAR and the corresponding RAPID subheader
   *
   */
  struct Rar
  {
    uint8_t rapId;
    BuildRarListElement_s rarPayload;
  };

  /**
   * add a RAR to the MAC PDU, see 3GPP TS 36.321 6.2.3
   *
   * \param rar the rar
   */
  void AddRar (Rar rar);

  /**
   *
   * \return a const iterator to the beginning of the RAR list
   */
  std::list<Rar>::const_iterator RarListBegin () const;

  /**
   *
   * \return a const iterator to the end of the RAR list
   */
  std::list<Rar>::const_iterator RarListEnd () const;

private:
  std::list<Rar> m_rarList;
  uint16_t m_raRnti;

};

}

#endif /* SRC_MMWAVE_MODEL_MMWAVE_CONTROL_MESSAGES_H_ */
