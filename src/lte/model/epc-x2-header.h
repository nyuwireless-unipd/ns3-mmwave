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


namespace ns3 {


class EpcX2Header : public Header
{
public:
  EpcX2Header ();
  virtual ~EpcX2Header ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  uint8_t GetMessageType () const;
  void SetMessageType (uint8_t messageType);

  uint8_t GetProcedureCode () const;
  void SetProcedureCode (uint8_t procedureCode);

  void SetLengthOfIes (uint32_t lengthOfIes);
  void SetNumberOfIes (uint32_t numberOfIes);


  enum ProcedureCode_t {
    HandoverPreparation     = 0,
    LoadIndication          = 2,
    SnStatusTransfer        = 4,
    UeContextRelease        = 5,
    ResourceStatusReporting = 10,
    RlcSetupRequest         = 11, // added for MC functionalities
    RlcSetupCompleted       = 12,
    NotifyMcConnection      = 13,
    UpdateUeSinr            = 14,
    RequestMcHandover       = 15,
    NotifyMmWaveLteHandover = 16,
    NotifyCoordinatorHandoverFailed = 17,
    SwitchConnection        = 18,
    SecondaryCellHandoverCompleted = 19

  };

  enum TypeOfMessage_t {
    InitiatingMessage       = 0,
    SuccessfulOutcome       = 1,
    UnsuccessfulOutcome     = 2,
    McForwardDownlinkData   = 3, // added for MC functionalities
    McForwardUplinkData     = 4
  };

private:
  uint8_t m_messageType;
  uint8_t m_procedureCode;

  uint32_t m_lengthOfIes;
  uint32_t m_numberOfIes;
};


class EpcX2HandoverRequestHeader : public Header
{
public:
  EpcX2HandoverRequestHeader ();
  virtual ~EpcX2HandoverRequestHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  uint16_t GetOldEnbUeX2apId () const;
  void SetOldEnbUeX2apId (uint16_t x2apId);

  uint16_t GetCause () const;
  void SetCause (uint16_t cause);

  bool GetIsMc () const;
  void SetIsMc (bool isMc);

  uint16_t GetTargetCellId () const;
  void SetTargetCellId (uint16_t targetCellId);

  uint32_t GetMmeUeS1apId () const;
  void SetMmeUeS1apId (uint32_t mmeUeS1apId);

  std::vector <EpcX2Sap::ErabToBeSetupItem> GetBearers () const;
  void SetBearers (std::vector <EpcX2Sap::ErabToBeSetupItem> bearers);

  std::vector <EpcX2Sap::RlcSetupRequest> GetRlcSetupRequests () const;
  void SetRlcSetupRequests (std::vector <EpcX2Sap::RlcSetupRequest> rlcRequests);

  uint64_t GetUeAggregateMaxBitRateDownlink () const;
  void SetUeAggregateMaxBitRateDownlink (uint64_t bitRate);

  uint64_t GetUeAggregateMaxBitRateUplink () const;
  void SetUeAggregateMaxBitRateUplink (uint64_t bitRate);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_oldEnbUeX2apId;
  uint16_t          m_cause;
  uint16_t          m_targetCellId;
  uint32_t          m_mmeUeS1apId;
  uint64_t          m_ueAggregateMaxBitRateDownlink;
  uint64_t          m_ueAggregateMaxBitRateUplink;
  std::vector <EpcX2Sap::ErabToBeSetupItem> m_erabsToBeSetupList;
  std::vector <EpcX2Sap::RlcSetupRequest> m_rlcRequestsList;
  bool              m_isMc;
};


class EpcX2RlcSetupRequestHeader : public Header
{
public:
  EpcX2RlcSetupRequestHeader ();
  virtual ~EpcX2RlcSetupRequestHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;

  uint16_t GetSourceCellId () const;
  void SetSourceCellId (uint16_t sourceCellId);

  uint16_t GetTargetCellId () const;
  void SetTargetCellId (uint16_t targetCellId);

  uint32_t GetGtpTeid () const;
  void SetGtpTeid (uint32_t gtpTeid);

  uint16_t GetMmWaveRnti () const;
  void SetMmWaveRnti (uint16_t rnti);

  uint16_t GetLteRnti () const;
  void SetLteRnti (uint16_t rnti);

  uint8_t GetDrbid () const;
  void SetDrbid (uint8_t drbid);

  LteEnbCmacSapProvider::LcInfo GetLcInfo() const;
  void SetLcInfo(LteEnbCmacSapProvider::LcInfo lcInfo);

  LteRrcSap::RlcConfig GetRlcConfig() const;
  void SetRlcConfig(LteRrcSap::RlcConfig rlcConfig);

  LteRrcSap::LogicalChannelConfig GetLogicalChannelConfig();
  void SetLogicalChannelConfig(LteRrcSap::LogicalChannelConfig conf);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_sourceCellId;
  uint16_t          m_targetCellId;
  uint32_t          m_gtpTeid;
  uint16_t          m_mmWaveRnti;
  uint16_t          m_lteRnti;
  uint8_t           m_drbid;
  LteEnbCmacSapProvider::LcInfo m_lcInfo;
  LteRrcSap::RlcConfig m_rlcConfig;
  LteRrcSap::LogicalChannelConfig m_lcConfig;
};

class EpcX2RlcSetupCompletedHeader : public Header
{
public:
  EpcX2RlcSetupCompletedHeader ();
  virtual ~EpcX2RlcSetupCompletedHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;

  uint16_t GetSourceCellId () const;
  void SetSourceCellId (uint16_t sourceCellId);

  uint16_t GetTargetCellId () const;
  void SetTargetCellId (uint16_t targetCellId);

  uint32_t GetGtpTeid () const;
  void SetGtpTeid (uint32_t gtpTeid);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_sourceCellId;
  uint16_t          m_targetCellId;
  uint32_t          m_gtpTeid;
};

class EpcX2McHandoverHeader : public Header
{
public:
  EpcX2McHandoverHeader ();
  virtual ~EpcX2McHandoverHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;

  uint16_t GetTargetCellId () const;
  void SetTargetCellId (uint16_t targetCellId);

  uint16_t GetOldCellId () const;
  void SetOldCellId (uint16_t oldCellId);

  uint64_t GetImsi () const;
  void SetImsi (uint64_t imsi);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_targetCellId;
  uint16_t          m_oldCellId;
  uint64_t          m_imsi;
};

class EpcX2SecondaryCellHandoverCompletedHeader : public Header
{
public:
  EpcX2SecondaryCellHandoverCompletedHeader ();
  virtual ~EpcX2SecondaryCellHandoverCompletedHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;

  uint16_t GetMmWaveRnti () const;
  void SetMmWaveRnti (uint16_t mmWaveRnti);

  uint16_t GetOldEnbUeX2apId () const;
  void SetOldEnbUeX2apId (uint16_t oldEnbUeX2apId);

  uint64_t GetImsi () const;
  void SetImsi (uint64_t imsi);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_mmWaveRnti;
  uint16_t          m_oldEnbUeX2apId;
  uint64_t          m_imsi;
};

class EpcX2NotifyCoordinatorHandoverFailedHeader : public Header
{
public:
  EpcX2NotifyCoordinatorHandoverFailedHeader ();
  virtual ~EpcX2NotifyCoordinatorHandoverFailedHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;

  uint16_t GetTargetCellId () const;
  void SetTargetCellId (uint16_t targetCellId);

  uint16_t GetSourceCellId () const;
  void SetSourceCellId (uint16_t oldCellId);

  uint64_t GetImsi () const;
  void SetImsi (uint64_t imsi);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_targetCellId;
  uint16_t          m_sourceCellId;
  uint64_t          m_imsi;
};

class EpcX2HandoverRequestAckHeader : public Header
{
public:
  EpcX2HandoverRequestAckHeader ();
  virtual ~EpcX2HandoverRequestAckHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  uint16_t GetOldEnbUeX2apId () const;
  void SetOldEnbUeX2apId (uint16_t x2apId);

  uint16_t GetNewEnbUeX2apId () const;
  void SetNewEnbUeX2apId (uint16_t x2apId);

  std::vector <EpcX2Sap::ErabAdmittedItem> GetAdmittedBearers () const;
  void SetAdmittedBearers (std::vector <EpcX2Sap::ErabAdmittedItem> bearers);

  std::vector <EpcX2Sap::ErabNotAdmittedItem> GetNotAdmittedBearers () const;
  void SetNotAdmittedBearers (std::vector <EpcX2Sap::ErabNotAdmittedItem> bearers);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_oldEnbUeX2apId;
  uint16_t          m_newEnbUeX2apId;
  std::vector <EpcX2Sap::ErabAdmittedItem>     m_erabsAdmittedList;
  std::vector <EpcX2Sap::ErabNotAdmittedItem>  m_erabsNotAdmittedList;
};


class EpcX2HandoverPreparationFailureHeader : public Header
{
public:
  EpcX2HandoverPreparationFailureHeader ();
  virtual ~EpcX2HandoverPreparationFailureHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  uint16_t GetOldEnbUeX2apId () const;
  void SetOldEnbUeX2apId (uint16_t x2apId);

  uint16_t GetCause () const;
  void SetCause (uint16_t cause);

  uint16_t GetCriticalityDiagnostics () const;
  void SetCriticalityDiagnostics (uint16_t criticalityDiagnostics);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_oldEnbUeX2apId;
  uint16_t          m_cause;
  uint16_t          m_criticalityDiagnostics;
};


class EpcX2SnStatusTransferHeader : public Header
{
public:
  EpcX2SnStatusTransferHeader ();
  virtual ~EpcX2SnStatusTransferHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  uint16_t GetOldEnbUeX2apId () const;
  void SetOldEnbUeX2apId (uint16_t x2apId);

  uint16_t GetNewEnbUeX2apId () const;
  void SetNewEnbUeX2apId (uint16_t x2apId);

  std::vector <EpcX2Sap::ErabsSubjectToStatusTransferItem> GetErabsSubjectToStatusTransferList () const;
  void SetErabsSubjectToStatusTransferList (std::vector <EpcX2Sap::ErabsSubjectToStatusTransferItem> erabs);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_oldEnbUeX2apId;
  uint16_t          m_newEnbUeX2apId;
  std::vector <EpcX2Sap::ErabsSubjectToStatusTransferItem> m_erabsSubjectToStatusTransferList;
};


class EpcX2UeContextReleaseHeader : public Header
{
public:
  EpcX2UeContextReleaseHeader ();
  virtual ~EpcX2UeContextReleaseHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  uint16_t GetOldEnbUeX2apId () const;
  void SetOldEnbUeX2apId (uint16_t x2apId);

  uint16_t GetNewEnbUeX2apId () const;
  void SetNewEnbUeX2apId (uint16_t x2apId);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_oldEnbUeX2apId;
  uint16_t          m_newEnbUeX2apId;
};


class EpcX2LoadInformationHeader : public Header
{
public:
  EpcX2LoadInformationHeader ();
  virtual ~EpcX2LoadInformationHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  std::vector <EpcX2Sap::CellInformationItem> GetCellInformationList () const;
  void SetCellInformationList (std::vector <EpcX2Sap::CellInformationItem> cellInformationList);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  std::vector <EpcX2Sap::CellInformationItem> m_cellInformationList;
};


class EpcX2ResourceStatusUpdateHeader : public Header
{
public:
  EpcX2ResourceStatusUpdateHeader ();
  virtual ~EpcX2ResourceStatusUpdateHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  uint16_t GetEnb1MeasurementId () const;
  void SetEnb1MeasurementId (uint16_t enb1MeasurementId);

  uint16_t GetEnb2MeasurementId () const;
  void SetEnb2MeasurementId (uint16_t enb2MeasurementId);

  std::vector <EpcX2Sap::CellMeasurementResultItem> GetCellMeasurementResultList () const;
  void SetCellMeasurementResultList (std::vector <EpcX2Sap::CellMeasurementResultItem> cellMeasurementResultList);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t          m_enb1MeasurementId;
  uint16_t          m_enb2MeasurementId;
  std::vector <EpcX2Sap::CellMeasurementResultItem> m_cellMeasurementResultList;
};

class EpcX2UeImsiSinrUpdateHeader : public Header
{
public:
  EpcX2UeImsiSinrUpdateHeader ();
  virtual ~EpcX2UeImsiSinrUpdateHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  std::map <uint64_t, double> GetUeImsiSinrMap () const;
  void SetUeImsiSinrMap (std::map<uint64_t, double> map);

  uint16_t GetSourceCellId () const;
  void SetSourceCellId (uint16_t sourceCellId);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  // from http://beej.us/guide/bgnet/examples/ieee754.c, to convert 
  // uint64_t to double and viceversa according to IEEE754 format
  static uint64_t pack754(long double f);
  static long double unpack754(uint64_t i);

  std::map <uint64_t, double> m_map;
  uint16_t m_sourceCellId;
};

class EpcX2ConnectionSwitchHeader : public Header
{
public:
  EpcX2ConnectionSwitchHeader ();
  virtual ~EpcX2ConnectionSwitchHeader ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;


  uint16_t GetMmWaveRnti () const;
  void SetMmWaveRnti (uint16_t rnti);

  bool GetUseMmWaveConnection () const;
  void SetUseMmWaveConnection (bool useMmWaveConnection);

  uint8_t GetDrbid () const;
  void SetDrbid (uint8_t bid);

  uint32_t GetLengthOfIes () const;
  uint32_t GetNumberOfIes () const;

private:
  uint32_t          m_numberOfIes;
  uint32_t          m_headerLength;

  uint16_t m_mmWaveRnti;
  uint8_t m_drbid;
  bool     m_useMmWaveConnection;
};

} // namespace ns3

#endif // EPC_X2_HEADER_H
