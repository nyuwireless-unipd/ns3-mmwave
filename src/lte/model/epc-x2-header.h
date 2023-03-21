/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2012 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 * Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Manuel Requena <manuel.requena@cttc.es>
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *          Dual Connectivity functionalities
 */

#ifndef EPC_X2_HEADER_H
#define EPC_X2_HEADER_H

#include "ns3/epc-x2-sap.h"
#include "ns3/header.h"

#include <vector>

namespace ns3
{

class EpcX2Header : public Header
{
  public:
    EpcX2Header();
    virtual ~EpcX2Header();

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    /**
     * Get message type function
     * \returns the message type
     */
    uint8_t GetMessageType() const;
    /**
     * Set message type function
     * \param messageType the message type
     */
    void SetMessageType(uint8_t messageType);

    /**
     * Get procedure code function
     * \returns the procedure code
     */
    uint8_t GetProcedureCode() const;
    /**
     * Set procedure code function
     * \param procedureCode the procedure code
     */
    void SetProcedureCode(uint8_t procedureCode);

    /**
     * Set length of IEs function
     * \param lengthOfIes the length of IEs
     */
    void SetLengthOfIes(uint32_t lengthOfIes);
    /**
     * Set number of IEs function
     * \param numberOfIes the number of IEs
     */
    void SetNumberOfIes(uint32_t numberOfIes);

    /// Procedure code enumeration
    enum ProcedureCode_t
    {
        HandoverPreparation = 0,
        LoadIndication = 2,
        SnStatusTransfer = 4,
        UeContextRelease = 5,
        ResourceStatusReporting = 10,
        RlcSetupRequest = 11, // added for MC functionalities
        RlcSetupCompleted = 12,
        NotifyMcConnection = 13,
        UpdateUeSinr = 14,
        RequestMcHandover = 15,
        NotifyMmWaveLteHandover = 16,
        NotifyCoordinatorHandoverFailed = 17,
        SwitchConnection = 18,
        SecondaryCellHandoverCompleted = 19
    };

    /// Type of message enumeration
    enum TypeOfMessage_t
    {
        InitiatingMessage = 0,
        SuccessfulOutcome = 1,
        UnsuccessfulOutcome = 2,
        McForwardDownlinkData = 3, // added for MC functionalities
        McForwardUplinkData = 4
    };

  private:
    uint8_t m_messageType;   ///< message type
    uint8_t m_procedureCode; ///< procedure code

    uint32_t m_lengthOfIes; ///< length of IEs
    uint32_t m_numberOfIes; ///< number of IEs
};

/**
 * EpcX2HandoverRequestHeader
 */
class EpcX2HandoverRequestHeader : public Header
{
  public:
    EpcX2HandoverRequestHeader();
    virtual ~EpcX2HandoverRequestHeader();

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    /**
     * Get old ENB X2 AP ID function
     * \returns the old ENB UE X2 AP ID
     */
    uint16_t GetOldEnbUeX2apId() const;
    /**
     * Set old ENB X2 AP ID function
     * \param x2apId the X2 AP ID
     */
    void SetOldEnbUeX2apId(uint16_t x2apId);

    /**
     * Get cause function
     * \returns the cause
     */
    uint16_t GetCause() const;
    /**
     * Set cause function
     * \param cause
     */
    void SetCause(uint16_t cause);

    bool GetIsMc() const;
    void SetIsMc(bool isMc);

    /**
     * Get target cell id function
     * \returns the target cell ID
     */
    uint16_t GetTargetCellId() const;
    /**
     * Set target cell id function
     * \param targetCellId the target cell ID
     */
    void SetTargetCellId(uint16_t targetCellId);

    /**
     * Get MME UE S1 AP ID function
     * \returns the MME UE S1 AP ID
     */
    uint32_t GetMmeUeS1apId() const;
    /**
     * Set MME UE S1 AP ID function
     * \param mmeUeS1apId the MME UE S1 AP ID
     */
    void SetMmeUeS1apId(uint32_t mmeUeS1apId);

    /**
     * Get bearers function
     * \returns <EpcX2Sap::ErabToBeSetupItem>
     */
    std::vector<EpcX2Sap::ErabToBeSetupItem> GetBearers() const;
    /**
     * Set bearers function
     * \param bearers std::vector <EpcX2Sap::ErabToBeSetupItem>
     */
    void SetBearers(std::vector<EpcX2Sap::ErabToBeSetupItem> bearers);

    std::vector<EpcX2Sap::RlcSetupRequest> GetRlcSetupRequests() const;
    void SetRlcSetupRequests(std::vector<EpcX2Sap::RlcSetupRequest> rlcRequests);

    /**
     * Get UE Aggregate Max Bit Rate Downlink function
     * \returns the UE aggregate max bit rate downlink
     */
    uint64_t GetUeAggregateMaxBitRateDownlink() const;
    /**
     * Set UE Aggregrate Max Bit Rate Downlink function
     * \param bitRate the bit rate
     */
    void SetUeAggregateMaxBitRateDownlink(uint64_t bitRate);

    /**
     * Get UE Aggregrate Max Bit Rate Uplik function
     * \returns the UE aggregate max bit rate uplink
     */
    uint64_t GetUeAggregateMaxBitRateUplink() const;
    /**
     * Set UE Aggregrate Max Bit Rate Uplik function
     * \param bitRate the bit rate
     */
    void SetUeAggregateMaxBitRateUplink(uint64_t bitRate);

    /**
     * Get length of IEs
     * \returns the length of IEs
     */
    uint32_t GetLengthOfIes() const;
    /**
     * Get number of IEs
     * \returns the number of IEs
     */
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;  ///< number of IEs
    uint32_t m_headerLength; ///< header length

    uint16_t m_oldEnbUeX2apId;                ///< old ENB UE X1 AP ID
    uint16_t m_cause;                         ///< cause
    uint16_t m_targetCellId;                  ///< target cell ID
    uint32_t m_mmeUeS1apId;                   ///< MME UE S1 AP ID
    uint64_t m_ueAggregateMaxBitRateDownlink; ///< aggregate max bit rate downlink
    uint64_t m_ueAggregateMaxBitRateUplink;   ///< aggregate max bit rate uplink
    std::vector<EpcX2Sap::ErabToBeSetupItem> m_erabsToBeSetupList; ///< ERAB to be setup list
    std::vector<EpcX2Sap::RlcSetupRequest> m_rlcRequestsList;
    bool m_isMc;
};

class EpcX2RlcSetupRequestHeader : public Header
{
  public:
    EpcX2RlcSetupRequestHeader();
    virtual ~EpcX2RlcSetupRequestHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint16_t GetSourceCellId() const;
    void SetSourceCellId(uint16_t sourceCellId);

    uint16_t GetTargetCellId() const;
    void SetTargetCellId(uint16_t targetCellId);

    uint32_t GetGtpTeid() const;
    void SetGtpTeid(uint32_t gtpTeid);

    uint16_t GetMmWaveRnti() const;
    void SetMmWaveRnti(uint16_t rnti);

    uint16_t GetLteRnti() const;
    void SetLteRnti(uint16_t rnti);

    uint8_t GetDrbid() const;
    void SetDrbid(uint8_t drbid);

    LteEnbCmacSapProvider::LcInfo GetLcInfo() const;
    void SetLcInfo(LteEnbCmacSapProvider::LcInfo lcInfo);

    LteRrcSap::RlcConfig GetRlcConfig() const;
    void SetRlcConfig(LteRrcSap::RlcConfig rlcConfig);

    LteRrcSap::LogicalChannelConfig GetLogicalChannelConfig();
    void SetLogicalChannelConfig(LteRrcSap::LogicalChannelConfig conf);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;

    uint16_t m_sourceCellId;
    uint16_t m_targetCellId;
    uint32_t m_gtpTeid;
    uint16_t m_mmWaveRnti;
    uint16_t m_lteRnti;
    uint8_t m_drbid;
    LteEnbCmacSapProvider::LcInfo m_lcInfo;
    LteRrcSap::RlcConfig m_rlcConfig;
    LteRrcSap::LogicalChannelConfig m_lcConfig;
};

class EpcX2RlcSetupCompletedHeader : public Header
{
  public:
    EpcX2RlcSetupCompletedHeader();
    virtual ~EpcX2RlcSetupCompletedHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint16_t GetSourceCellId() const;
    void SetSourceCellId(uint16_t sourceCellId);

    uint16_t GetTargetCellId() const;
    void SetTargetCellId(uint16_t targetCellId);

    uint32_t GetGtpTeid() const;
    void SetGtpTeid(uint32_t gtpTeid);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;

    uint16_t m_sourceCellId;
    uint16_t m_targetCellId;
    uint32_t m_gtpTeid;
};

class EpcX2McHandoverHeader : public Header
{
  public:
    EpcX2McHandoverHeader();
    virtual ~EpcX2McHandoverHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint16_t GetTargetCellId() const;
    void SetTargetCellId(uint16_t targetCellId);

    uint16_t GetOldCellId() const;
    void SetOldCellId(uint16_t oldCellId);

    uint64_t GetImsi() const;
    void SetImsi(uint64_t imsi);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;

    uint16_t m_targetCellId;
    uint16_t m_oldCellId;
    uint64_t m_imsi;
};

class EpcX2SecondaryCellHandoverCompletedHeader : public Header
{
  public:
    EpcX2SecondaryCellHandoverCompletedHeader();
    virtual ~EpcX2SecondaryCellHandoverCompletedHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint16_t GetMmWaveRnti() const;
    void SetMmWaveRnti(uint16_t mmWaveRnti);

    uint16_t GetOldEnbUeX2apId() const;
    void SetOldEnbUeX2apId(uint16_t oldEnbUeX2apId);

    uint64_t GetImsi() const;
    void SetImsi(uint64_t imsi);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;

    uint16_t m_mmWaveRnti;
    uint16_t m_oldEnbUeX2apId;
    uint64_t m_imsi;
};

class EpcX2NotifyCoordinatorHandoverFailedHeader : public Header
{
  public:
    EpcX2NotifyCoordinatorHandoverFailedHeader();
    virtual ~EpcX2NotifyCoordinatorHandoverFailedHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint16_t GetTargetCellId() const;
    void SetTargetCellId(uint16_t targetCellId);

    uint16_t GetSourceCellId() const;
    void SetSourceCellId(uint16_t oldCellId);

    uint64_t GetImsi() const;
    void SetImsi(uint64_t imsi);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;

    uint16_t m_targetCellId;
    uint16_t m_sourceCellId;
    uint64_t m_imsi;
};

/**
 * EpcX2HandoverRequestAckHeader
 */
class EpcX2HandoverRequestAckHeader : public Header
{
  public:
    EpcX2HandoverRequestAckHeader();
    virtual ~EpcX2HandoverRequestAckHeader();

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    /**
     * Get old ENB UE X2 AP ID function
     * \returns the old ENB UE X2 AP ID
     */
    uint16_t GetOldEnbUeX2apId() const;
    /**
     * Set old ENB UE X2 AP ID function
     * \param x2apId the old ENB UE X2 AP ID
     */
    void SetOldEnbUeX2apId(uint16_t x2apId);

    /**
     * Get new ENB UE X2 AP ID function
     * \returns the new ENB UE X2 AP ID
     */
    uint16_t GetNewEnbUeX2apId() const;
    /**
     * Set new ENB UE X2 AP ID function
     * \param x2apId the new ENB UE X2 AP ID
     */
    void SetNewEnbUeX2apId(uint16_t x2apId);

    /**
     * Get admittied bearers function
     * \returns <EpcX2Sap::ErabAdmittedItem>
     */
    std::vector<EpcX2Sap::ErabAdmittedItem> GetAdmittedBearers() const;
    /**
     * Set admitted bearers function
     * \param bearers the admitted bearers
     */
    void SetAdmittedBearers(std::vector<EpcX2Sap::ErabAdmittedItem> bearers);

    /**
     * Get not admitted bearers function
     * \returns the not admitted bearers
     */
    std::vector<EpcX2Sap::ErabNotAdmittedItem> GetNotAdmittedBearers() const;
    /**
     * Set not admitted bearers function
     * \param bearers the not admitted bearers
     */
    void SetNotAdmittedBearers(std::vector<EpcX2Sap::ErabNotAdmittedItem> bearers);

    /**
     * Get length of IEs function
     * \returns the length of IEs
     */
    uint32_t GetLengthOfIes() const;
    /**
     * Get number of IEs function
     * \returns the number of IEs
     */
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;  ///< number of IEs
    uint32_t m_headerLength; ///< header length

    uint16_t m_oldEnbUeX2apId;                                         ///< old ENB UE X2 AP ID
    uint16_t m_newEnbUeX2apId;                                         ///< new ENB UE X2 AP ID
    std::vector<EpcX2Sap::ErabAdmittedItem> m_erabsAdmittedList;       ///< ERABs admitted list
    std::vector<EpcX2Sap::ErabNotAdmittedItem> m_erabsNotAdmittedList; ///< ERABs not admitted list
};

/**
 * EpcX2HandoverPreparationFailureHeader
 */
class EpcX2HandoverPreparationFailureHeader : public Header
{
  public:
    EpcX2HandoverPreparationFailureHeader();
    virtual ~EpcX2HandoverPreparationFailureHeader();

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    /**
     * Get old ENB UE X2 AP ID function
     * \returns the old ENB UE X2 AP ID
     */
    uint16_t GetOldEnbUeX2apId() const;
    /**
     * Set old ENB UE X2 AP ID function
     * \param x2apId the old ENB UE X2 AP ID
     */
    void SetOldEnbUeX2apId(uint16_t x2apId);

    /**
     * Get cause function
     * \returns the cause
     */
    uint16_t GetCause() const;
    /**
     * Set cause function
     * \param cause
     */
    void SetCause(uint16_t cause);

    /**
     * Get criticality diagnostics function
     * \returns the criticality diagnostics
     */
    uint16_t GetCriticalityDiagnostics() const;
    /**
     * Set criticality diagnostics function
     * \param criticalityDiagnostics the criticality diagnostics
     */
    void SetCriticalityDiagnostics(uint16_t criticalityDiagnostics);

    /**
     * Get length of IEs function
     * \returns the length of IEs
     */
    uint32_t GetLengthOfIes() const;
    /**
     * Get number of IEs function
     * \returns the number of IEs
     */
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;  ///< number of IEs
    uint32_t m_headerLength; ///< header length

    uint16_t m_oldEnbUeX2apId;         ///< old ENB UE X2 AP ID
    uint16_t m_cause;                  ///< cause
    uint16_t m_criticalityDiagnostics; ///< criticality diagnostics
};

/**
 * EpcX2SnStatusTransferHeader
 */
class EpcX2SnStatusTransferHeader : public Header
{
  public:
    EpcX2SnStatusTransferHeader();
    virtual ~EpcX2SnStatusTransferHeader();

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    /**
     * Get old ENB UE X2 AP ID function
     * \returns the old ENB UE X2 AP ID
     */
    uint16_t GetOldEnbUeX2apId() const;
    /**
     * Set old ENB UE X2 AP ID function
     * \param x2apId the old ENB UE X2 AP ID
     */
    void SetOldEnbUeX2apId(uint16_t x2apId);

    /**
     * Get new ENB UE X2 AP ID function
     * \returns the new ENB UE X2AP ID
     */
    uint16_t GetNewEnbUeX2apId() const;
    /**
     * Set new ENB UE X2 AP ID function
     * \param x2apId the new ENB UE X2AP ID
     */
    void SetNewEnbUeX2apId(uint16_t x2apId);

    /**
     * Get ERABs subject to status transfer list function
     * \returns std::vector <EpcX2Sap::ErabsSubjectToStatusTransferItem>
     */
    std::vector<EpcX2Sap::ErabsSubjectToStatusTransferItem> GetErabsSubjectToStatusTransferList()
        const;
    /**
     * Set ERABs subject to status transfer list function
     * \param erabs std::vector <EpcX2Sap::ErabsSubjectToStatusTransferItem>
     */
    void SetErabsSubjectToStatusTransferList(
        std::vector<EpcX2Sap::ErabsSubjectToStatusTransferItem> erabs);

    /**
     * Get length of IEs function
     * \returns the length of IEs
     */
    uint32_t GetLengthOfIes() const;
    /**
     * Get number of IEs function
     * \returns the number of IEs
     */
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;  ///< number of IEs
    uint32_t m_headerLength; ///< header length

    uint16_t m_oldEnbUeX2apId; ///< old ENB UE X2 AP ID
    uint16_t m_newEnbUeX2apId; ///< new ENB UE X2 AP ID
    std::vector<EpcX2Sap::ErabsSubjectToStatusTransferItem>
        m_erabsSubjectToStatusTransferList; ///< ERABs subject to status transfer list
};

/**
 * EpcX2UeContextReleaseHeader
 */
class EpcX2UeContextReleaseHeader : public Header
{
  public:
    EpcX2UeContextReleaseHeader();
    virtual ~EpcX2UeContextReleaseHeader();

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    /**
     * Get old ENB UE X2 AP ID function
     * \returns the old ENB UE X2 AP ID
     */
    uint16_t GetOldEnbUeX2apId() const;
    /**
     * Set old ENB UE X2 AP ID function
     * \param x2apId the old ENB UE X2 AP ID
     */
    void SetOldEnbUeX2apId(uint16_t x2apId);

    /**
     * Get new ENB UE X2 AP ID function
     * \returns the new ENB UE X2 AP ID
     */
    uint16_t GetNewEnbUeX2apId() const;
    /**
     * Set new ENB UE X2 AP ID function
     * \param x2apId the new ENB UE X2 AP ID
     */
    void SetNewEnbUeX2apId(uint16_t x2apId);

    /**
     * Get length of IEs function
     * \returns the length of IEs
     */
    uint32_t GetLengthOfIes() const;
    /**
     * Set length of IEs function
     * \returns the number of IEs
     */
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;  ///< number of IEs
    uint32_t m_headerLength; ///< header length

    uint16_t m_oldEnbUeX2apId; ///< old ENB UE X2 AP ID
    uint16_t m_newEnbUeX2apId; ///< new ENB UE X2 AP ID
};

/**
 * EpcX2LoadInformationHeader
 */
class EpcX2LoadInformationHeader : public Header
{
  public:
    EpcX2LoadInformationHeader();
    virtual ~EpcX2LoadInformationHeader();

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    /**
     * Get cell information list function
     * \returns std::vector <EpcX2Sap::CellInformationItem>
     */
    std::vector<EpcX2Sap::CellInformationItem> GetCellInformationList() const;
    /**
     * Set cell information list function
     * \param cellInformationList std::vector <EpcX2Sap::CellInformationItem>
     */
    void SetCellInformationList(std::vector<EpcX2Sap::CellInformationItem> cellInformationList);

    /**
     * Get length of IEs function
     * \returns the length of IEs
     */
    uint32_t GetLengthOfIes() const;
    /**
     * Get number of IEs function
     * \returns the number of IEs
     */
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;  ///< number of IEs
    uint32_t m_headerLength; ///< length of IEs

    std::vector<EpcX2Sap::CellInformationItem> m_cellInformationList; ///< cell information list
};

/**
 * EpcX2ResourceStatusUpdateHeader
 */
class EpcX2ResourceStatusUpdateHeader : public Header
{
  public:
    EpcX2ResourceStatusUpdateHeader();
    virtual ~EpcX2ResourceStatusUpdateHeader();

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    /**
     * Get ENB1 measurement ID function
     * \returns the ENB1 measurement ID
     */
    uint16_t GetEnb1MeasurementId() const;
    /**
     * Set ENB1 measurement ID function
     * \param enb1MeasurementId the ENB1 measurement ID
     */
    void SetEnb1MeasurementId(uint16_t enb1MeasurementId);

    /**
     * Get ENB2 measurement ID function
     * \returns the ENB2 measurement ID
     */
    uint16_t GetEnb2MeasurementId() const;
    /**
     * Set ENB2 measurement ID function
     * \param enb2MeasurementId ENB2 measruement ID
     */
    void SetEnb2MeasurementId(uint16_t enb2MeasurementId);

    /**
     * Get cell measurement results list function
     * \returns the cell measurement results list
     */
    std::vector<EpcX2Sap::CellMeasurementResultItem> GetCellMeasurementResultList() const;
    /**
     * Set cell measurement results list function
     * \param cellMeasurementResultList the cell measurement results list
     */
    void SetCellMeasurementResultList(
        std::vector<EpcX2Sap::CellMeasurementResultItem> cellMeasurementResultList);

    /**
     * Get length of IEs function
     * \returns the length of IEs
     */
    uint32_t GetLengthOfIes() const;
    /**
     * Get number of IEs function
     * \returns the number of IEs
     */
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;  ///< number of IEs
    uint32_t m_headerLength; ///< header length

    uint16_t m_enb1MeasurementId; ///< ENB1 measurement
    uint16_t m_enb2MeasurementId; ///< ENB2 measurement
    std::vector<EpcX2Sap::CellMeasurementResultItem>
        m_cellMeasurementResultList; ///< cell measurement result list
};

class EpcX2UeImsiSinrUpdateHeader : public Header
{
  public:
    EpcX2UeImsiSinrUpdateHeader();
    virtual ~EpcX2UeImsiSinrUpdateHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    std::map<uint64_t, double> GetUeImsiSinrMap() const;
    void SetUeImsiSinrMap(std::map<uint64_t, double> map);

    uint16_t GetSourceCellId() const;
    void SetSourceCellId(uint16_t sourceCellId);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;

    // from http://beej.us/guide/bgnet/examples/ieee754.c, to convert
    // uint64_t to double and viceversa according to IEEE754 format
    static uint64_t pack754(long double f);
    static long double unpack754(uint64_t i);

    std::map<uint64_t, double> m_map;
    uint16_t m_sourceCellId;
};

class EpcX2ConnectionSwitchHeader : public Header
{
  public:
    EpcX2ConnectionSwitchHeader();
    virtual ~EpcX2ConnectionSwitchHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint16_t GetMmWaveRnti() const;
    void SetMmWaveRnti(uint16_t rnti);

    bool GetUseMmWaveConnection() const;
    void SetUseMmWaveConnection(bool useMmWaveConnection);

    uint8_t GetDrbid() const;
    void SetDrbid(uint8_t bid);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;

    uint16_t m_mmWaveRnti;
    uint8_t m_drbid;
    bool m_useMmWaveConnection;
};

} // namespace ns3

#endif // EPC_X2_HEADER_H
