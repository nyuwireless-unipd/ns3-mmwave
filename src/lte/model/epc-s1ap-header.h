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
 * Author: Michele Polese <michele.polese@gmail.com>
 * Inspired by epc-x2-header.h
 */

#ifndef EPC_S1AP_HEADER_H
#define EPC_S1AP_HEADER_H

#include "ns3/epc-s1ap-sap.h"
#include "ns3/header.h"

#include <list>

namespace ns3
{

class EpcS1APHeader : public Header
{
  public:
    EpcS1APHeader();
    virtual ~EpcS1APHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint8_t GetProcedureCode() const;
    void SetProcedureCode(uint8_t procedureCode);

    void SetLengthOfIes(uint32_t lengthOfIes);
    void SetNumberOfIes(uint32_t numberOfIes);

    enum ProcedureCode_t
    {
        InitialUeMessage = 71,
        PathSwitchRequest = 58,
        ErabReleaseIndication = 37,
        InitialContextSetupResponse = 43,
        InitialContextSetupRequest = 41,
        PathSwitchRequestAck = 59
    };

  private:
    uint8_t m_procedureCode;

    uint32_t m_lengthOfIes;
    uint32_t m_numberOfIes;
};

// Header for initial Ue message
class EpcS1APInitialUeMessageHeader : public Header
{
  public:
    EpcS1APInitialUeMessageHeader();
    virtual ~EpcS1APInitialUeMessageHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint64_t GetMmeUeS1Id() const;
    void SetMmeUeS1Id(uint64_t mmeUeS1Id);

    uint16_t GetEnbUeS1Id() const;
    void SetEnbUeS1Id(uint16_t enbUeS1Id);

    uint64_t GetSTmsi() const;
    void SetSTmsi(uint64_t stmsi);

    uint16_t GetEcgi() const;
    void SetEcgi(uint16_t ecgi);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;
    uint64_t m_stmsi;
    uint64_t m_mmeUeS1Id;
    uint16_t m_enbUeS1Id;
    uint16_t m_ecgi;
};

class EpcS1APErabReleaseIndicationHeader : public Header
{
  public:
    EpcS1APErabReleaseIndicationHeader();
    virtual ~EpcS1APErabReleaseIndicationHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint64_t GetMmeUeS1Id() const;
    void SetMmeUeS1Id(uint64_t mmeUeS1Id);

    uint16_t GetEnbUeS1Id() const;
    void SetEnbUeS1Id(uint16_t enbUeS1Id);

    std::list<EpcS1apSap::ErabToBeReleasedIndication> GetErabToBeReleaseIndication() const;
    void SetErabReleaseIndication(
        std::list<EpcS1apSap::ErabToBeReleasedIndication> erabToBeReleaseIndication);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;
    uint16_t m_enbUeS1Id;
    uint64_t m_mmeUeS1Id;
    std::list<EpcS1apSap::ErabToBeReleasedIndication> m_erabToBeReleaseIndication;
};

class EpcS1APInitialContextSetupResponseHeader : public Header
{
  public:
    EpcS1APInitialContextSetupResponseHeader();
    virtual ~EpcS1APInitialContextSetupResponseHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint64_t GetMmeUeS1Id() const;
    void SetMmeUeS1Id(uint64_t mmeUeS1Id);

    uint16_t GetEnbUeS1Id() const;
    void SetEnbUeS1Id(uint16_t enbUeS1Id);

    std::list<EpcS1apSap::ErabSetupItem> GetErabSetupItem() const;
    void SetErabSetupItem(std::list<EpcS1apSap::ErabSetupItem> erabSetupList);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;
    uint16_t m_enbUeS1Id;
    uint64_t m_mmeUeS1Id;
    std::list<EpcS1apSap::ErabSetupItem> m_erabSetupList;
};

class EpcS1APPathSwitchRequestHeader : public Header
{
  public:
    EpcS1APPathSwitchRequestHeader();
    virtual ~EpcS1APPathSwitchRequestHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint64_t GetMmeUeS1Id() const;
    void SetMmeUeS1Id(uint64_t mmeUeS1Id);

    uint16_t GetEnbUeS1Id() const;
    void SetEnbUeS1Id(uint16_t enbUeS1Id);

    uint16_t GetEcgi() const;
    void SetEcgi(uint16_t ecgi);

    std::list<EpcS1apSap::ErabSwitchedInDownlinkItem> GetErabSwitchedInDownlinkItemList() const;
    void SetErabSwitchedInDownlinkItemList(
        std::list<EpcS1apSap::ErabSwitchedInDownlinkItem> erabToBeSwitchedInDownlinkList);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;
    uint16_t m_enbUeS1Id;
    uint16_t m_ecgi;
    uint64_t m_mmeUeS1Id;
    std::list<EpcS1apSap::ErabSwitchedInDownlinkItem> m_erabToBeSwitchedInDownlinkList;
};

class EpcS1APInitialContextSetupRequestHeader : public Header
{
  public:
    EpcS1APInitialContextSetupRequestHeader();
    virtual ~EpcS1APInitialContextSetupRequestHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint64_t GetMmeUeS1Id() const;
    void SetMmeUeS1Id(uint64_t mmeUeS1Id);

    uint16_t GetEnbUeS1Id() const;
    void SetEnbUeS1Id(uint16_t enbUeS1Id);

    std::list<EpcS1apSap::ErabToBeSetupItem> GetErabToBeSetupItem() const;
    void SetErabToBeSetupItem(std::list<EpcS1apSap::ErabToBeSetupItem> erabToBeSetupList);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;
    uint16_t m_enbUeS1Id;
    uint64_t m_mmeUeS1Id;
    std::list<EpcS1apSap::ErabToBeSetupItem> m_erabsToBeSetupList;
};

class EpcS1APPathSwitchRequestAcknowledgeHeader : public Header
{
  public:
    EpcS1APPathSwitchRequestAcknowledgeHeader();
    virtual ~EpcS1APPathSwitchRequestAcknowledgeHeader();

    static TypeId GetTypeId(void);
    virtual TypeId GetInstanceTypeId(void) const;
    virtual uint32_t GetSerializedSize(void) const;
    virtual void Serialize(Buffer::Iterator start) const;
    virtual uint32_t Deserialize(Buffer::Iterator start);
    virtual void Print(std::ostream& os) const;

    uint64_t GetMmeUeS1Id() const;
    void SetMmeUeS1Id(uint64_t mmeUeS1Id);

    uint16_t GetEnbUeS1Id() const;
    void SetEnbUeS1Id(uint16_t enbUeS1Id);

    uint16_t GetEcgi() const;
    void SetEcgi(uint16_t ecgi);

    std::list<EpcS1apSap::ErabSwitchedInUplinkItem> GetErabSwitchedInUplinkItemList() const;
    void SetErabSwitchedInUplinkItemList(
        std::list<EpcS1apSap::ErabSwitchedInUplinkItem> erabToBeSwitchedInDownlinkList);

    uint32_t GetLengthOfIes() const;
    uint32_t GetNumberOfIes() const;

  private:
    uint32_t m_numberOfIes;
    uint32_t m_headerLength;
    uint16_t m_enbUeS1Id;
    uint16_t m_ecgi;
    uint64_t m_mmeUeS1Id;
    std::list<EpcS1apSap::ErabSwitchedInUplinkItem> m_erabToBeSwitchedInUplinkList;
};

} // namespace ns3

#endif // EPC_S1AP_HEADER_H
