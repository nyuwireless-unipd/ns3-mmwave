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
 *                         Sourjya Dutta <sdutta@nyu.edu>
 *                         Russell Ford <russell.ford@nyu.edu>
 *                         Menglei Zhang <menglei@nyu.edu>
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_CONTROL_MESSAGES_H_
#define SRC_MMWAVE_MODEL_MMWAVE_CONTROL_MESSAGES_H_

#include "mmwave-phy-mac-common.h"

#include <ns3/ff-mac-common.h>
#include <ns3/lte-rrc-sap.h>
#include <ns3/ptr.h>
#include <ns3/simple-ref-count.h>

#include <list>

namespace ns3
{

namespace mmwave
{

class MmWaveControlMessage : public SimpleRefCount<MmWaveControlMessage>
{
  public:
    enum messageType
    {
        DCI, // The resources allocation map from the BS to the attached UEs
        DCI_TDMA,
        DL_CQI,
        MIB,           // Master Information Block
        SIB1,          // System Information Block Type 1
        RACH_PREAMBLE, // Random Access Preamble
        RAR,           // Random Access Response
        BSR,           // Buffer Status Report
        DL_HARQ        // DL HARQ feedback
    };

    MmWaveControlMessage(void);
    virtual ~MmWaveControlMessage(void);

    void SetMessageType(messageType type);

    messageType GetMessageType(void);

  private:
    messageType m_messageType;
};

class MmWaveTdmaDciMessage : public MmWaveControlMessage
{
  public:
    MmWaveTdmaDciMessage(void);
    virtual ~MmWaveTdmaDciMessage(void);

    //  void SetRbAllocationMap (SfAllocInfo allocMap);
    //  SfAllocInfo GetRbAllocationMap (void);

    void SetDciInfoElement(DciInfoElementTdma dci);
    DciInfoElementTdma GetDciInfoElement(void);

    void SetSfnSf(SfnSf sfn);
    SfnSf GetSfnSf(void);

  private:
    SfnSf m_sfnSf; // frame num and sf num for debugging
    // bool m_ulGrant;  // is ul grant
    //  SfAllocInfo m_rscAllocationMap;
    DciInfoElementTdma m_dciInfoElement;
};

class MmWaveDlCqiMessage : public MmWaveControlMessage
{
  public:
    MmWaveDlCqiMessage(void);
    virtual ~MmWaveDlCqiMessage(void);

    void SetDlCqi(DlCqiInfo cqi);
    DlCqiInfo GetDlCqi();

  private:
    DlCqiInfo m_cqi;
};

/**
 * \ingroup mmwave
 * The uplink BsrLteControlMessage defines the specific
 * extension of the CE element for reporting the buffer status report
 */
class MmWaveBsrMessage : public MmWaveControlMessage
{
  public:
    MmWaveBsrMessage(void);
    virtual ~MmWaveBsrMessage(void);

    /**
     * \brief add a BSR feedback record into the message.
     * \param bsr the BSR feedback
     */
    void SetBsr(MacCeElement bsr);

    /**
     * \brief Get BSR informations
     * \return BSR message
     */
    MacCeElement GetBsr(void);

  private:
    MacCeElement m_bsr;
};

// ---------------------------------------------------------------------------

/**
 * \ingroup mmWave
 * \brief Abstract model for broadcasting the Master Information Block (MIB)
 *        within the control channel (BCCH).
 *
 */
class MmWaveMibMessage : public MmWaveControlMessage
{
  public:
    /**
     * \brief Create a new instance of MIB control message.
     */
    MmWaveMibMessage(void);

    /**
     * \brief Replace the MIB content of this control message.
     * \param mib the desired MIB content
     */
    void SetMib(LteRrcSap::MasterInformationBlock mib);

    /**
     * \brief Retrieve the MIB content from this control message.
     * \return the current MIB content that this control message holds
     */
    LteRrcSap::MasterInformationBlock GetMib() const;

  private:
    LteRrcSap::MasterInformationBlock m_mib;

}; // end of class MmWaveMibMessage

// ---------------------------------------------------------------------------

/**
 * \ingroup mmWave
 * \brief Abstract model for broadcasting the System Information Block Type 1
 *        (SIB1) within the control channel (BCCH).
 *
 */
class MmWaveSib1Message : public MmWaveControlMessage
{
  public:
    /**
     * \brief Create a new instance of SIB1 control message.
     */
    MmWaveSib1Message(void);

    /**
     * \brief Replace the SIB1 content of this control message.
     * \param sib1 the desired SIB1 content
     */
    void SetSib1(LteRrcSap::SystemInformationBlockType1 sib1);

    /**
     * \brief Retrieve the SIB1 content from this control message.
     * \return the current SIB1 content that this control message holds
     */
    LteRrcSap::SystemInformationBlockType1 GetSib1() const;

  private:
    LteRrcSap::SystemInformationBlockType1 m_sib1;

}; // end of class MmWaveSib1Message

// ---------------------------------------------------------------------------

/**
 * \ingroup mmWave
 *
 * abstract model for the Random Access Preamble
 */
class MmWaveRachPreambleMessage : public MmWaveControlMessage
{
  public:
    MmWaveRachPreambleMessage(void);

    /**
     * Set the Random Access Preamble Identifier (RAPID), see 3GPP TS 36.321 6.2.2
     *
     * \param rapid the RAPID
     */
    void SetRapId(uint32_t rapid);

    /**
     *
     * \return the RAPID
     */
    uint32_t GetRapId() const;

  private:
    uint32_t m_rapId;
};

// ---------------------------------------------------------------------------

/**
 * \ingroup mmWave
 *
 * abstract model for the MAC Random Access Response message
 */
class MmWaveRarMessage : public MmWaveControlMessage
{
  public:
    MmWaveRarMessage(void);

    /**
     *
     * \param raRnti the RA-RNTI, see 3GPP TS 36.321 5.1.4
     */
    void SetRaRnti(uint16_t raRnti);

    /**
     *
     * \return  the RA-RNTI, see 3GPP TS 36.321 5.1.4
     */
    uint16_t GetRaRnti() const;

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
    void AddRar(Rar rar);

    /**
     *
     * \return a const iterator to the beginning of the RAR list
     */
    std::list<Rar>::const_iterator RarListBegin() const;

    /**
     *
     * \return a const iterator to the end of the RAR list
     */
    std::list<Rar>::const_iterator RarListEnd() const;

  private:
    std::list<Rar> m_rarList;
    uint16_t m_raRnti;
};

/**
 * \ingroup mmEave
 * The downlink MmwaveDlHarqFeedbackMessage defines the specific
 * messages for transmitting the DL HARQ feedback through PUCCH
 */
class MmWaveDlHarqFeedbackMessage : public MmWaveControlMessage
{
  public:
    MmWaveDlHarqFeedbackMessage(void);
    virtual ~MmWaveDlHarqFeedbackMessage(void);

    /**
     * \brief add a DL HARQ feedback record into the message.
     * \param m the DL HARQ feedback
     */
    void SetDlHarqFeedback(DlHarqInfo m);

    /**
     * \brief Get DL HARQ informations
     * \return DL HARQ message
     */
    DlHarqInfo GetDlHarqFeedback(void);

  private:
    DlHarqInfo m_dlHarqInfo;
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_CONTROL_MESSAGES_H_ */
