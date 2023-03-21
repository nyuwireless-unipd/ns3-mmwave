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
 * Inspired by epc-x2-header.cc
 */

#include "ns3/epc-s1ap-header.h"

#include "ns3/log.h"

#include <list>

// TODO
// According to 36.413 9.2.3.4: enbUeS1Id should be 3 byte, but in the SAP interface
// already defined in the ns-3 release is 2 byte
// The same holds for mmeUeS1Id, which should be 4 byte, but is 8 byte in the SAP interface

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("EpcS1APHeader");

NS_OBJECT_ENSURE_REGISTERED(EpcS1APHeader);

EpcS1APHeader::EpcS1APHeader()
    : m_procedureCode(0xfa),
      m_lengthOfIes(0xfa),
      m_numberOfIes(0xfa)
{
}

EpcS1APHeader::~EpcS1APHeader()
{
    m_procedureCode = 0xfb;
    m_lengthOfIes = 0xfb;
    m_numberOfIes = 0xfb;
}

TypeId
EpcS1APHeader::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::EpcS1APHeader")
                            .SetParent<Header>()
                            .SetGroupName("Lte")
                            .AddConstructor<EpcS1APHeader>();
    return tid;
}

TypeId
EpcS1APHeader::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

uint32_t
EpcS1APHeader::GetSerializedSize(void) const
{
    return 6; // 6 bytes in this header
}

void
EpcS1APHeader::Serialize(Buffer::Iterator start) const
{
    Buffer::Iterator i = start;

    i.WriteU8(m_procedureCode);

    i.WriteU8(0x00); // 36.413 9.1.2.2 Criticality - if not recognized, 0 == reject
    i.WriteU8(m_lengthOfIes + 3);
    i.WriteHtonU16(0);
    i.WriteU8(m_numberOfIes);
}

uint32_t
EpcS1APHeader::Deserialize(Buffer::Iterator start)
{
    Buffer::Iterator i = start;

    m_procedureCode = i.ReadU8();

    i.ReadU8();
    m_lengthOfIes = i.ReadU8() - 3;
    i.ReadNtohU16();
    m_numberOfIes = i.ReadU8();

    return GetSerializedSize();
}

void
EpcS1APHeader::Print(std::ostream& os) const
{
    os << " ProcedureCode=" << (uint32_t)m_procedureCode;
    os << " LengthOfIEs=" << (uint32_t)m_lengthOfIes;
    os << " NumberOfIEs=" << (uint32_t)m_numberOfIes;
}

uint8_t
EpcS1APHeader::GetProcedureCode() const
{
    return m_procedureCode;
}

void
EpcS1APHeader::SetProcedureCode(uint8_t procedureCode)
{
    m_procedureCode = procedureCode;
}

void
EpcS1APHeader::SetLengthOfIes(uint32_t lengthOfIes)
{
    m_lengthOfIes = lengthOfIes;
}

void
EpcS1APHeader::SetNumberOfIes(uint32_t numberOfIes)
{
    m_numberOfIes = numberOfIes;
}

/////////////////////////////////////////////////////////////////////

NS_OBJECT_ENSURE_REGISTERED(EpcS1APInitialUeMessageHeader);

EpcS1APInitialUeMessageHeader::EpcS1APInitialUeMessageHeader()
    : m_numberOfIes(1 + 1 + 1 + 1 + 1 + 1 + 1),
      m_headerLength(3 + 2 + 6 + 4 + 2 + 9 + 9),
      m_stmsi(0xfffffffa),
      m_mmeUeS1Id(0xfffffffa),
      m_enbUeS1Id(0xfffa),
      m_ecgi(0xfffa)
{
}

EpcS1APInitialUeMessageHeader::~EpcS1APInitialUeMessageHeader()
{
    m_numberOfIes = 0;
    m_headerLength = 0;
    m_stmsi = 0xfffffffb;
    m_enbUeS1Id = 0xfffb;
    m_ecgi = 0xfffb;
    m_mmeUeS1Id = 0xfffffffb;
}

TypeId
EpcS1APInitialUeMessageHeader::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::EpcS1APInitialUeMessageHeader")
                            .SetParent<Header>()
                            .SetGroupName("Lte")
                            .AddConstructor<EpcS1APInitialUeMessageHeader>();
    return tid;
}

TypeId
EpcS1APInitialUeMessageHeader::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

uint32_t
EpcS1APInitialUeMessageHeader::GetSerializedSize(void) const
{
    return m_headerLength;
}

void
EpcS1APInitialUeMessageHeader::Serialize(Buffer::Iterator start) const
{
    Buffer::Iterator i = start;

    // message type is already in EpcS1APHeader
    i.WriteHtonU16(m_enbUeS1Id); // m_enbUeS1Id
    i.WriteU8(0);                // criticality = REJECT

    i.WriteU8(0); // NAS PDU, not implemented
    i.WriteU8(0); // criticality = REJECT

    i.WriteU32(0); // TAI, not implemented
    i.WriteU8(0);
    i.WriteU8(0); // criticality = REJECT

    i.WriteHtonU16(m_ecgi); // E-UTRAN CGI, it should have a different size
    i.WriteU8(1 << 6);      // criticality = IGNORE

    i.WriteU8(0);      // RRC Establishment cause
    i.WriteU8(1 << 6); // criticality = IGNORE

    i.WriteU64(m_stmsi); // S-TMSI
    i.WriteU8(0);        // criticality = REJECT

    i.WriteU64(m_mmeUeS1Id); // mmeUeS1Id, not in the standard?
    i.WriteU8(0);            // criticality = REJECT
}

uint32_t
EpcS1APInitialUeMessageHeader::Deserialize(Buffer::Iterator start)
{
    Buffer::Iterator i = start;

    m_headerLength = 0;
    m_numberOfIes = 0;

    m_enbUeS1Id = i.ReadNtohU16();
    i.ReadU8();
    m_headerLength += 3;
    m_numberOfIes++;

    i.ReadU8();
    i.ReadU8();
    m_headerLength += 2;
    m_numberOfIes++;

    i.ReadU32(); // TAI, not implemented
    i.ReadU8();
    i.ReadU8();
    m_headerLength += 6;
    m_numberOfIes++;

    m_ecgi = i.ReadNtohU16(); // E-UTRAN CGI, it should have a different size
    i.ReadU8();
    m_headerLength += 3;
    m_numberOfIes++;

    i.ReadU8();
    i.ReadU8();
    m_headerLength += 2;
    m_numberOfIes++;

    m_stmsi = i.ReadU64(); // S-TMSI
    i.ReadU8();
    m_headerLength += 9;
    m_numberOfIes++;

    m_mmeUeS1Id = i.ReadU64(); // MME UE ID
    i.ReadU8();
    m_headerLength += 9;
    m_numberOfIes++;

    return GetSerializedSize();
}

void
EpcS1APInitialUeMessageHeader::Print(std::ostream& os) const
{
    os << "MmeUeS1apId = " << m_mmeUeS1Id;
    os << " EnbUeS1Id = " << m_enbUeS1Id;
    os << " ECGI = " << m_ecgi;
    os << " S-TMSI = " << m_stmsi;
}

uint64_t
EpcS1APInitialUeMessageHeader::GetMmeUeS1Id() const
{
    return m_mmeUeS1Id;
}

void
EpcS1APInitialUeMessageHeader::SetMmeUeS1Id(uint64_t mmeUeS1Id)
{
    m_mmeUeS1Id = mmeUeS1Id;
}

uint16_t
EpcS1APInitialUeMessageHeader::GetEnbUeS1Id() const
{
    return m_enbUeS1Id;
}

void
EpcS1APInitialUeMessageHeader::SetEnbUeS1Id(uint16_t enbUeS1Id)
{
    m_enbUeS1Id = enbUeS1Id;
}

uint64_t
EpcS1APInitialUeMessageHeader::GetSTmsi() const
{
    return m_stmsi;
}

void
EpcS1APInitialUeMessageHeader::SetSTmsi(uint64_t stmsi)
{
    m_stmsi = stmsi;
}

uint16_t
EpcS1APInitialUeMessageHeader::GetEcgi() const
{
    return m_ecgi;
}

void
EpcS1APInitialUeMessageHeader::SetEcgi(uint16_t ecgi)
{
    m_ecgi = ecgi;
}

uint32_t
EpcS1APInitialUeMessageHeader::GetLengthOfIes() const
{
    return m_headerLength;
}

uint32_t
EpcS1APInitialUeMessageHeader::GetNumberOfIes() const
{
    return m_numberOfIes;
}

/////////////////////////////////////////////////////////////////////

NS_OBJECT_ENSURE_REGISTERED(EpcS1APErabReleaseIndicationHeader);

EpcS1APErabReleaseIndicationHeader::EpcS1APErabReleaseIndicationHeader()
    : m_numberOfIes(1 + 1 + 1),
      m_headerLength(9 + 3 + 4 + 1),
      m_enbUeS1Id(0xfffa),
      m_mmeUeS1Id(0xfffffffa)
{
    m_erabToBeReleaseIndication.clear();
}

EpcS1APErabReleaseIndicationHeader::~EpcS1APErabReleaseIndicationHeader()
{
    m_numberOfIes = 0;
    m_headerLength = 0;
    m_enbUeS1Id = 0xfffb;
    m_mmeUeS1Id = 0xfffffffb;
    m_erabToBeReleaseIndication.clear();
}

TypeId
EpcS1APErabReleaseIndicationHeader::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::EpcS1APErabReleaseIndicationHeader")
                            .SetParent<Header>()
                            .SetGroupName("Lte")
                            .AddConstructor<EpcS1APErabReleaseIndicationHeader>();
    return tid;
}

TypeId
EpcS1APErabReleaseIndicationHeader::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

uint32_t
EpcS1APErabReleaseIndicationHeader::GetSerializedSize(void) const
{
    return m_headerLength;
}

void
EpcS1APErabReleaseIndicationHeader::Serialize(Buffer::Iterator start) const
{
    Buffer::Iterator i = start;

    // message type is already in EpcS1APHeader
    i.WriteU64(m_mmeUeS1Id); // mmeUeS1Id
    i.WriteU8(0);            // criticality = REJECT

    i.WriteHtonU16(m_enbUeS1Id); // m_enbUeS1Id
    i.WriteU8(0);                // criticality = REJECT

    std::list<EpcS1apSap::ErabToBeReleasedIndication>::size_type sz =
        m_erabToBeReleaseIndication.size();
    i.WriteHtonU32(sz); // number of bearers
    for (std::list<EpcS1apSap::ErabToBeReleasedIndication>::const_iterator l_iter =
             m_erabToBeReleaseIndication.begin();
         l_iter != m_erabToBeReleaseIndication.end();
         ++l_iter) // content of ErabToBeReleasedIndication
    {
        i.WriteU8(l_iter->erabId);
    }
    i.WriteU8(0); // criticality = REJECT, just one for the whole list
}

uint32_t
EpcS1APErabReleaseIndicationHeader::Deserialize(Buffer::Iterator start)
{
    Buffer::Iterator i = start;

    m_headerLength = 0;
    m_numberOfIes = 0;

    m_mmeUeS1Id = i.ReadU64(); // mmeUeS1Id
    i.ReadU8();
    m_headerLength += 9;
    m_numberOfIes++;

    m_enbUeS1Id = i.ReadNtohU16(); // m_enbUeS1Id
    i.ReadU8();
    m_headerLength += 3;
    m_numberOfIes++;

    int sz = i.ReadNtohU32(); // number of bearers
    m_headerLength += 4;

    for (int j = 0; j < (int)sz; j++) // content of ErabToBeReleasedIndication
    {
        EpcS1apSap::ErabToBeReleasedIndication erabItem;
        erabItem.erabId = i.ReadU8();

        m_erabToBeReleaseIndication.push_back(erabItem);
        m_headerLength += 1;
    }
    i.ReadU8();
    m_headerLength += 1;
    m_numberOfIes++;

    return GetSerializedSize();
}

void
EpcS1APErabReleaseIndicationHeader::Print(std::ostream& os) const
{
    os << "MmeUeS1apId = " << m_mmeUeS1Id;
    os << " EnbUeS1Id = " << m_enbUeS1Id;
    for (std::list<EpcS1apSap::ErabToBeReleasedIndication>::const_iterator l_iter =
             m_erabToBeReleaseIndication.begin();
         l_iter != m_erabToBeReleaseIndication.end();
         ++l_iter)
    {
        os << " ErabId " << l_iter->erabId;
    }
}

uint64_t
EpcS1APErabReleaseIndicationHeader::GetMmeUeS1Id() const
{
    return m_mmeUeS1Id;
}

void
EpcS1APErabReleaseIndicationHeader::SetMmeUeS1Id(uint64_t mmeUeS1Id)
{
    m_mmeUeS1Id = mmeUeS1Id;
}

uint16_t
EpcS1APErabReleaseIndicationHeader::GetEnbUeS1Id() const
{
    return m_enbUeS1Id;
}

void
EpcS1APErabReleaseIndicationHeader::SetEnbUeS1Id(uint16_t enbUeS1Id)
{
    m_enbUeS1Id = enbUeS1Id;
}

std::list<EpcS1apSap::ErabToBeReleasedIndication>
EpcS1APErabReleaseIndicationHeader::GetErabToBeReleaseIndication() const
{
    return m_erabToBeReleaseIndication;
}

void
EpcS1APErabReleaseIndicationHeader::SetErabReleaseIndication(
    std::list<EpcS1apSap::ErabToBeReleasedIndication> erabToBeReleaseIndication)
{
    m_headerLength += erabToBeReleaseIndication.size();
    m_erabToBeReleaseIndication = erabToBeReleaseIndication;
}

uint32_t
EpcS1APErabReleaseIndicationHeader::GetLengthOfIes() const
{
    return m_headerLength;
}

uint32_t
EpcS1APErabReleaseIndicationHeader::GetNumberOfIes() const
{
    return m_numberOfIes;
}

/////////////////////////////////////////////////////////////////////

NS_OBJECT_ENSURE_REGISTERED(EpcS1APInitialContextSetupResponseHeader);

EpcS1APInitialContextSetupResponseHeader::EpcS1APInitialContextSetupResponseHeader()
    : m_numberOfIes(1 + 1 + 1),
      m_headerLength(9 + 3 + 4 + 1),
      m_enbUeS1Id(0xfffa),
      m_mmeUeS1Id(0xfffffffa)
{
    m_erabSetupList.clear();
}

EpcS1APInitialContextSetupResponseHeader::~EpcS1APInitialContextSetupResponseHeader()
{
    m_numberOfIes = 0;
    m_headerLength = 0;
    m_enbUeS1Id = 0xfffb;
    m_mmeUeS1Id = 0xfffffffb;
    m_erabSetupList.clear();
}

TypeId
EpcS1APInitialContextSetupResponseHeader::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::EpcS1APInitialContextSetupResponseHeader")
                            .SetParent<Header>()
                            .SetGroupName("Lte")
                            .AddConstructor<EpcS1APInitialContextSetupResponseHeader>();
    return tid;
}

TypeId
EpcS1APInitialContextSetupResponseHeader::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

uint32_t
EpcS1APInitialContextSetupResponseHeader::GetSerializedSize(void) const
{
    return m_headerLength;
}

void
EpcS1APInitialContextSetupResponseHeader::Serialize(Buffer::Iterator start) const
{
    Buffer::Iterator i = start;

    // message type is already in EpcS1APHeader
    i.WriteU64(m_mmeUeS1Id); // mmeUeS1Id
    i.WriteU8(1 << 6);       // criticality = IGNORE

    i.WriteHtonU16(m_enbUeS1Id); // m_enbUeS1Id
    i.WriteU8(1 << 6);           // criticality = IGNORE

    std::list<EpcS1apSap::ErabSetupItem>::size_type sz = m_erabSetupList.size();
    i.WriteHtonU32(sz); // number of bearers
    for (std::list<EpcS1apSap::ErabSetupItem>::const_iterator l_iter = m_erabSetupList.begin();
         l_iter != m_erabSetupList.end();
         ++l_iter) // content of m_erabSetupList
    {
        i.WriteU8(l_iter->erabId);
        i.WriteHtonU32(l_iter->enbTransportLayerAddress.Get());
        i.WriteHtonU32(l_iter->enbTeid);
        i.WriteU8(1 << 6); // criticality = IGNORE each
    }
    i.WriteU8(1 << 6); // criticality = IGNORE
}

uint32_t
EpcS1APInitialContextSetupResponseHeader::Deserialize(Buffer::Iterator start)
{
    Buffer::Iterator i = start;

    m_headerLength = 0;
    m_numberOfIes = 0;

    m_mmeUeS1Id = i.ReadU64(); // mmeUeS1Id
    i.ReadU8();
    m_headerLength += 9;
    m_numberOfIes++;

    m_enbUeS1Id = i.ReadNtohU16(); // m_enbUeS1Id
    i.ReadU8();
    m_headerLength += 3;
    m_numberOfIes++;

    int sz = i.ReadNtohU32(); // number of bearers
    m_headerLength += 4;

    for (int j = 0; j < (int)sz; j++) // content of ErabToBeReleasedIndication
    {
        EpcS1apSap::ErabSetupItem erabItem;
        erabItem.erabId = i.ReadU8();
        erabItem.enbTransportLayerAddress = Ipv4Address(i.ReadNtohU32());
        erabItem.enbTeid = i.ReadNtohU32();
        i.ReadU8();

        m_erabSetupList.push_back(erabItem);
        m_headerLength += 10;
    }
    i.ReadU8();
    m_headerLength += 1;
    m_numberOfIes++;

    return GetSerializedSize();
}

void
EpcS1APInitialContextSetupResponseHeader::Print(std::ostream& os) const
{
    os << "MmeUeS1apId = " << m_mmeUeS1Id;
    os << " EnbUeS1Id = " << m_enbUeS1Id;
    for (std::list<EpcS1apSap::ErabSetupItem>::const_iterator l_iter = m_erabSetupList.begin();
         l_iter != m_erabSetupList.end();
         ++l_iter) // content of m_erabSetupList
    {
        os << " ErabId " << l_iter->erabId;
        os << " enbTransportLayerAddress " << l_iter->enbTransportLayerAddress;
        os << " enbTeid " << l_iter->enbTeid;
    }
}

uint64_t
EpcS1APInitialContextSetupResponseHeader::GetMmeUeS1Id() const
{
    return m_mmeUeS1Id;
}

void
EpcS1APInitialContextSetupResponseHeader::SetMmeUeS1Id(uint64_t mmeUeS1Id)
{
    m_mmeUeS1Id = mmeUeS1Id;
}

uint16_t
EpcS1APInitialContextSetupResponseHeader::GetEnbUeS1Id() const
{
    return m_enbUeS1Id;
}

void
EpcS1APInitialContextSetupResponseHeader::SetEnbUeS1Id(uint16_t enbUeS1Id)
{
    m_enbUeS1Id = enbUeS1Id;
}

std::list<EpcS1apSap::ErabSetupItem>
EpcS1APInitialContextSetupResponseHeader::GetErabSetupItem() const
{
    return m_erabSetupList;
}

void
EpcS1APInitialContextSetupResponseHeader::SetErabSetupItem(
    std::list<EpcS1apSap::ErabSetupItem> erabSetupList)
{
    m_headerLength += erabSetupList.size() * 10;
    m_erabSetupList = erabSetupList;
}

uint32_t
EpcS1APInitialContextSetupResponseHeader::GetLengthOfIes() const
{
    return m_headerLength;
}

uint32_t
EpcS1APInitialContextSetupResponseHeader::GetNumberOfIes() const
{
    return m_numberOfIes;
}

/////////////////////////////////////////////////////////////////////

NS_OBJECT_ENSURE_REGISTERED(EpcS1APPathSwitchRequestHeader);

EpcS1APPathSwitchRequestHeader::EpcS1APPathSwitchRequestHeader()
    : m_numberOfIes(1 + 1 + 1 + 1 + 1),
      m_headerLength(3 + 4 + 1 + 9 + 3 + 6),
      m_enbUeS1Id(0xfffa),
      m_ecgi(0xfffa),
      m_mmeUeS1Id(0xfffffffa)
{
    m_erabToBeSwitchedInDownlinkList.clear();
}

EpcS1APPathSwitchRequestHeader::~EpcS1APPathSwitchRequestHeader()
{
    m_numberOfIes = 0;
    m_headerLength = 0;
    m_enbUeS1Id = 0xfffb;
    m_ecgi = 0xfffb;
    m_mmeUeS1Id = 0xfffffffb;
    m_erabToBeSwitchedInDownlinkList.clear();
}

TypeId
EpcS1APPathSwitchRequestHeader::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::EpcS1APPathSwitchRequestHeader")
                            .SetParent<Header>()
                            .SetGroupName("Lte")
                            .AddConstructor<EpcS1APPathSwitchRequestHeader>();
    return tid;
}

TypeId
EpcS1APPathSwitchRequestHeader::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

uint32_t
EpcS1APPathSwitchRequestHeader::GetSerializedSize(void) const
{
    return m_headerLength;
}

void
EpcS1APPathSwitchRequestHeader::Serialize(Buffer::Iterator start) const
{
    Buffer::Iterator i = start;

    // message type is already in EpcS1APHeader
    i.WriteHtonU16(m_enbUeS1Id); // m_enbUeS1Id
    i.WriteU8(0);                // criticality = REJECT

    std::list<EpcS1apSap::ErabSwitchedInDownlinkItem>::size_type sz =
        m_erabToBeSwitchedInDownlinkList.size();
    i.WriteHtonU32(sz); // number of bearers
    for (std::list<EpcS1apSap::ErabSwitchedInDownlinkItem>::const_iterator l_iter =
             m_erabToBeSwitchedInDownlinkList.begin();
         l_iter != m_erabToBeSwitchedInDownlinkList.end();
         ++l_iter) // content of ErabToBeReleasedIndication // content of
                   // m_erabToBeSwitchedInDownlinkList
    {
        i.WriteU8(l_iter->erabId);
        i.WriteHtonU32(l_iter->enbTransportLayerAddress.Get());
        i.WriteHtonU32(l_iter->enbTeid);
        i.WriteU8(0); // criticality = REJECT each
    }
    i.WriteU8(0); // criticality = REJECT

    i.WriteU64(m_mmeUeS1Id); // mmeUeS1Id
    i.WriteU8(0);            // criticality = REJECT

    i.WriteU16(m_ecgi); // ecgi
    i.WriteU8(1 << 6);  // criticality = IGNORE

    i.WriteU32(0); // TAI, not implemented
    i.WriteU8(0);
    i.WriteU8(1 << 6); // criticality = IGNORE

    // TODO add 9.2.1.40
}

uint32_t
EpcS1APPathSwitchRequestHeader::Deserialize(Buffer::Iterator start)
{
    Buffer::Iterator i = start;

    m_headerLength = 0;
    m_numberOfIes = 0;

    m_enbUeS1Id = i.ReadNtohU16(); // m_enbUeS1Id
    i.ReadU8();
    m_headerLength += 3;
    m_numberOfIes++;

    int sz = i.ReadNtohU32(); // number of bearers
    m_headerLength += 4;

    for (int j = 0; j < (int)sz; j++) // content of ErabToBeReleasedIndication
    {
        EpcS1apSap::ErabSwitchedInDownlinkItem erabItem;
        erabItem.erabId = i.ReadU8();
        erabItem.enbTransportLayerAddress = Ipv4Address(i.ReadNtohU32());
        erabItem.enbTeid = i.ReadNtohU32();
        i.ReadU8();

        m_erabToBeSwitchedInDownlinkList.push_back(erabItem);
        m_headerLength += 10;
    }
    i.ReadU8();
    m_headerLength += 1;
    m_numberOfIes++;

    m_mmeUeS1Id = i.ReadU64(); // mmeUeS1Id
    i.ReadU8();
    m_headerLength += 9;
    m_numberOfIes++;

    m_ecgi = i.ReadU16(); // ecgi
    i.ReadU8();
    m_headerLength += 3;
    m_numberOfIes++;

    i.ReadU32(); // TAI, not implemented
    i.ReadU8();
    i.ReadU8(); // criticality = IGNORE

    m_headerLength += 6;
    m_numberOfIes++;

    return GetSerializedSize();
}

void
EpcS1APPathSwitchRequestHeader::Print(std::ostream& os) const
{
    os << "MmeUeS1apId = " << m_mmeUeS1Id;
    os << " EnbUeS1Id = " << m_enbUeS1Id;
    os << " ECGI = " << m_ecgi;
    for (std::list<EpcS1apSap::ErabSwitchedInDownlinkItem>::const_iterator l_iter =
             m_erabToBeSwitchedInDownlinkList.begin();
         l_iter != m_erabToBeSwitchedInDownlinkList.end();
         ++l_iter) // content of ErabToBeReleasedIndication // content of
                   // m_erabToBeSwitchedInDownlinkList
    {
        os << " ErabId " << l_iter->erabId;
        os << " enbTransportLayerAddress " << l_iter->enbTransportLayerAddress;
        os << " enbTeid " << l_iter->enbTeid;
    }
}

uint64_t
EpcS1APPathSwitchRequestHeader::GetMmeUeS1Id() const
{
    return m_mmeUeS1Id;
}

void
EpcS1APPathSwitchRequestHeader::SetMmeUeS1Id(uint64_t mmeUeS1Id)
{
    m_mmeUeS1Id = mmeUeS1Id;
}

uint16_t
EpcS1APPathSwitchRequestHeader::GetEnbUeS1Id() const
{
    return m_enbUeS1Id;
}

void
EpcS1APPathSwitchRequestHeader::SetEnbUeS1Id(uint16_t enbUeS1Id)
{
    m_enbUeS1Id = enbUeS1Id;
}

std::list<EpcS1apSap::ErabSwitchedInDownlinkItem>
EpcS1APPathSwitchRequestHeader::GetErabSwitchedInDownlinkItemList() const
{
    return m_erabToBeSwitchedInDownlinkList;
}

void
EpcS1APPathSwitchRequestHeader::SetErabSwitchedInDownlinkItemList(
    std::list<EpcS1apSap::ErabSwitchedInDownlinkItem> erabSetupList)
{
    m_headerLength += erabSetupList.size() * 10;
    m_erabToBeSwitchedInDownlinkList = erabSetupList;
}

uint16_t
EpcS1APPathSwitchRequestHeader::GetEcgi() const
{
    return m_ecgi;
}

void
EpcS1APPathSwitchRequestHeader::SetEcgi(uint16_t ecgi)
{
    m_ecgi = ecgi;
}

uint32_t
EpcS1APPathSwitchRequestHeader::GetLengthOfIes() const
{
    return m_headerLength;
}

uint32_t
EpcS1APPathSwitchRequestHeader::GetNumberOfIes() const
{
    return m_numberOfIes;
}

/////////////////////////////////////////////////////////////////////

NS_OBJECT_ENSURE_REGISTERED(EpcS1APInitialContextSetupRequestHeader);

EpcS1APInitialContextSetupRequestHeader::EpcS1APInitialContextSetupRequestHeader()
    : m_numberOfIes(1 + 1 + 1),
      m_headerLength(9 + 3 + 9 + 4 + 1),
      m_enbUeS1Id(0xfffa),
      m_mmeUeS1Id(0xfffffffa)
{
    m_erabsToBeSetupList.clear();
}

EpcS1APInitialContextSetupRequestHeader::~EpcS1APInitialContextSetupRequestHeader()
{
    m_numberOfIes = 0;
    m_headerLength = 0;
    m_enbUeS1Id = 0xfffb;
    m_mmeUeS1Id = 0xfffffffb;
    m_erabsToBeSetupList.clear();
}

TypeId
EpcS1APInitialContextSetupRequestHeader::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::EpcS1APInitialContextSetupRequestHeader")
                            .SetParent<Header>()
                            .SetGroupName("Lte")
                            .AddConstructor<EpcS1APInitialContextSetupRequestHeader>();
    return tid;
}

TypeId
EpcS1APInitialContextSetupRequestHeader::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

uint32_t
EpcS1APInitialContextSetupRequestHeader::GetSerializedSize(void) const
{
    return m_headerLength;
}

void
EpcS1APInitialContextSetupRequestHeader::Serialize(Buffer::Iterator start) const
{
    Buffer::Iterator i = start;

    // message type is already in EpcS1APHeader
    i.WriteU64(m_mmeUeS1Id); // mmeUeS1Id
    i.WriteU8(1 << 6);       // criticality = IGNORE

    i.WriteHtonU16(m_enbUeS1Id); // m_enbUeS1Id
    i.WriteU8(1 << 6);           // criticality = IGNORE

    i.WriteHtonU64(0); // aggregate maximum bitrate, not implemented
    i.WriteU8(0);

    std::list<EpcS1apSap::ErabToBeSetupItem>::size_type sz = m_erabsToBeSetupList.size();
    i.WriteHtonU32(sz); // number of bearers
    for (std::list<EpcS1apSap::ErabToBeSetupItem>::const_iterator l_iter =
             m_erabsToBeSetupList.begin();
         l_iter != m_erabsToBeSetupList.end();
         ++l_iter) // content of m_erabsToBeSetupList
    {
        i.WriteU8(l_iter->erabId);
        i.WriteHtonU16(l_iter->erabLevelQosParameters.qci);
        i.WriteHtonU64(l_iter->erabLevelQosParameters.gbrQosInfo.gbrDl);
        i.WriteHtonU64(l_iter->erabLevelQosParameters.gbrQosInfo.gbrUl);
        i.WriteHtonU64(l_iter->erabLevelQosParameters.gbrQosInfo.mbrDl);
        i.WriteHtonU64(l_iter->erabLevelQosParameters.gbrQosInfo.mbrUl);
        i.WriteU8(l_iter->erabLevelQosParameters.arp.priorityLevel);
        i.WriteU8(l_iter->erabLevelQosParameters.arp.preemptionCapability);
        i.WriteU8(l_iter->erabLevelQosParameters.arp.preemptionVulnerability);
        i.WriteHtonU32(l_iter->transportLayerAddress.Get());
        i.WriteHtonU32(l_iter->sgwTeid);

        i.WriteU8(0); // a criticaloty each, REJECT
    }
    i.WriteU8(0); // criticality = REJECT

    // TODO 9.2.140, 9.2.1.41
}

uint32_t
EpcS1APInitialContextSetupRequestHeader::Deserialize(Buffer::Iterator start)
{
    Buffer::Iterator i = start;

    m_headerLength = 0;
    m_numberOfIes = 0;

    m_mmeUeS1Id = i.ReadU64(); // mmeUeS1Id
    i.ReadU8();
    m_headerLength += 9;
    m_numberOfIes++;

    m_enbUeS1Id = i.ReadNtohU16(); // m_enbUeS1Id
    i.ReadU8();
    m_headerLength += 3;
    m_numberOfIes++;

    i.ReadU64(); // aggregate maximum bitrate, not implemented
    i.ReadU8();
    m_headerLength += 9;
    m_numberOfIes++;

    int sz = i.ReadNtohU32(); // number of bearers
    m_headerLength += 4;

    for (int j = 0; j < (int)sz; j++) // content of m_erabToBeSetupList
    {
        EpcS1apSap::ErabToBeSetupItem erabItem;
        erabItem.erabId = i.ReadU8();

        erabItem.erabLevelQosParameters = EpsBearer((EpsBearer::Qci)i.ReadNtohU16());
        erabItem.erabLevelQosParameters.gbrQosInfo.gbrDl = i.ReadNtohU64();
        erabItem.erabLevelQosParameters.gbrQosInfo.gbrUl = i.ReadNtohU64();
        erabItem.erabLevelQosParameters.gbrQosInfo.mbrDl = i.ReadNtohU64();
        erabItem.erabLevelQosParameters.gbrQosInfo.mbrUl = i.ReadNtohU64();
        erabItem.erabLevelQosParameters.arp.priorityLevel = i.ReadU8();
        erabItem.erabLevelQosParameters.arp.preemptionCapability = i.ReadU8();
        erabItem.erabLevelQosParameters.arp.preemptionVulnerability = i.ReadU8();

        erabItem.transportLayerAddress = Ipv4Address(i.ReadNtohU32());
        erabItem.sgwTeid = i.ReadNtohU32();

        i.ReadU8();

        m_erabsToBeSetupList.push_back(erabItem);
        m_headerLength += 46;
    }
    i.ReadU8();
    m_headerLength += 1;
    m_numberOfIes++;

    return GetSerializedSize();
}

void
EpcS1APInitialContextSetupRequestHeader::Print(std::ostream& os) const
{
    os << " MmeUeS1Id = " << m_mmeUeS1Id;
    os << " EnbUeS1Id = " << m_enbUeS1Id;
    os << " NumOfBearers = " << m_erabsToBeSetupList.size();

    std::list<EpcS1apSap::ErabToBeSetupItem>::size_type sz = m_erabsToBeSetupList.size();
    if (sz > 0)
    {
        os << " [";
    }
    int j = 0;
    for (std::list<EpcS1apSap::ErabToBeSetupItem>::const_iterator l_iter =
             m_erabsToBeSetupList.begin();
         l_iter != m_erabsToBeSetupList.end();
         ++l_iter) // content of m_erabsToBeSetupList
    {
        os << l_iter->erabId;
        if (j < (int)sz - 1)
        {
            os << ", ";
        }
        else
        {
            os << "]";
        }
        j++;
    }
}

uint64_t
EpcS1APInitialContextSetupRequestHeader::GetMmeUeS1Id() const
{
    return m_mmeUeS1Id;
}

void
EpcS1APInitialContextSetupRequestHeader::SetMmeUeS1Id(uint64_t mmeUeS1Id)
{
    m_mmeUeS1Id = mmeUeS1Id;
}

uint16_t
EpcS1APInitialContextSetupRequestHeader::GetEnbUeS1Id() const
{
    return m_enbUeS1Id;
}

void
EpcS1APInitialContextSetupRequestHeader::SetEnbUeS1Id(uint16_t enbUeS1Id)
{
    m_enbUeS1Id = enbUeS1Id;
}

std::list<EpcS1apSap::ErabToBeSetupItem>
EpcS1APInitialContextSetupRequestHeader::GetErabToBeSetupItem() const
{
    return m_erabsToBeSetupList;
}

void
EpcS1APInitialContextSetupRequestHeader::SetErabToBeSetupItem(
    std::list<EpcS1apSap::ErabToBeSetupItem> erabSetupList)
{
    m_headerLength += erabSetupList.size() * 47;
    m_erabsToBeSetupList = erabSetupList;
}

uint32_t
EpcS1APInitialContextSetupRequestHeader::GetLengthOfIes() const
{
    return m_headerLength;
}

uint32_t
EpcS1APInitialContextSetupRequestHeader::GetNumberOfIes() const
{
    return m_numberOfIes;
}

/////////////////////////////////////////////////////////////////////

NS_OBJECT_ENSURE_REGISTERED(EpcS1APPathSwitchRequestAcknowledgeHeader);

EpcS1APPathSwitchRequestAcknowledgeHeader::EpcS1APPathSwitchRequestAcknowledgeHeader()
    : m_numberOfIes(1 + 1 + 1 + 1),
      m_headerLength(3 + 4 + 1 + 9 + 3 + 6),
      m_enbUeS1Id(0xfffa),
      m_ecgi(0xfffa),
      m_mmeUeS1Id(0xfffffffa)
{
    m_erabToBeSwitchedInUplinkList.clear();
}

EpcS1APPathSwitchRequestAcknowledgeHeader::~EpcS1APPathSwitchRequestAcknowledgeHeader()
{
    m_numberOfIes = 0;
    m_headerLength = 0;
    m_enbUeS1Id = 0xfffb;
    m_ecgi = 0xfffb;
    m_mmeUeS1Id = 0xfffffffb;
    m_erabToBeSwitchedInUplinkList.clear();
}

TypeId
EpcS1APPathSwitchRequestAcknowledgeHeader::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::EpcS1APPathSwitchRequestAcknowledgeHeader")
                            .SetParent<Header>()
                            .SetGroupName("Lte")
                            .AddConstructor<EpcS1APPathSwitchRequestAcknowledgeHeader>();
    return tid;
}

TypeId
EpcS1APPathSwitchRequestAcknowledgeHeader::GetInstanceTypeId(void) const
{
    return GetTypeId();
}

uint32_t
EpcS1APPathSwitchRequestAcknowledgeHeader::GetSerializedSize(void) const
{
    return m_headerLength;
}

void
EpcS1APPathSwitchRequestAcknowledgeHeader::Serialize(Buffer::Iterator start) const
{
    Buffer::Iterator i = start;

    // message type is already in EpcS1APHeader
    i.WriteHtonU16(m_enbUeS1Id); // m_enbUeS1Id
    i.WriteU8(0);                // criticality = REJECT

    std::vector<EpcS1apSap::ErabSwitchedInUplinkItem>::size_type sz =
        m_erabToBeSwitchedInUplinkList.size();
    i.WriteHtonU32(sz); // number of bearers
    for (std::list<EpcS1apSap::ErabSwitchedInUplinkItem>::const_iterator l_iter =
             m_erabToBeSwitchedInUplinkList.begin();
         l_iter != m_erabToBeSwitchedInUplinkList.end();
         ++l_iter) // content of m_erabsToBeSetupList
    {
        i.WriteU8(l_iter->erabId);
        i.WriteHtonU32(l_iter->transportLayerAddress.Get());
        i.WriteHtonU32(l_iter->enbTeid);
        i.WriteU8(0); // criticality = REJECT each
    }
    i.WriteU8(0); // criticality = REJECT

    i.WriteU64(m_mmeUeS1Id); // mmeUeS1Id
    i.WriteU8(0);            // criticality = REJECT

    i.WriteU16(m_ecgi); // ecgi
    i.WriteU8(1 << 6);  // criticality = IGNORE

    i.WriteU32(0); // TAI, not implemented
    i.WriteU8(0);
    i.WriteU8(1 << 6); // criticality = IGNORE

    // TODO add 9.2.1.40
}

uint32_t
EpcS1APPathSwitchRequestAcknowledgeHeader::Deserialize(Buffer::Iterator start)
{
    Buffer::Iterator i = start;

    m_headerLength = 0;
    m_numberOfIes = 0;

    m_enbUeS1Id = i.ReadNtohU16(); // m_enbUeS1Id
    i.ReadU8();
    m_headerLength += 3;
    m_numberOfIes++;

    int sz = i.ReadNtohU32(); // number of bearers
    m_headerLength += 4;

    for (int j = 0; j < (int)sz; j++) // content of ErabToBeReleasedIndication
    {
        EpcS1apSap::ErabSwitchedInUplinkItem erabItem;
        erabItem.erabId = i.ReadU8();
        erabItem.transportLayerAddress = Ipv4Address(i.ReadNtohU32());
        erabItem.enbTeid = i.ReadNtohU32();
        i.ReadU8();

        m_erabToBeSwitchedInUplinkList.push_back(erabItem);
        m_headerLength += 9;
    }
    i.ReadU8();
    m_headerLength += 1;
    m_numberOfIes++;

    m_mmeUeS1Id = i.ReadU64(); // mmeUeS1Id
    i.ReadU8();
    m_headerLength += 9;
    m_numberOfIes++;

    m_ecgi = i.ReadU16(); // ecgi
    i.ReadU8();
    m_headerLength += 3;
    m_numberOfIes++;

    i.ReadU32(); // TAI, not implemented
    i.ReadU8();
    i.ReadU8(); // criticality = IGNORE

    m_headerLength += 6;
    m_numberOfIes++;

    return GetSerializedSize();
}

void
EpcS1APPathSwitchRequestAcknowledgeHeader::Print(std::ostream& os) const
{
    os << "MmeUeS1apId = " << m_mmeUeS1Id;
    os << " EnbUeS1Id = " << m_enbUeS1Id;
    os << " ECGI = " << m_ecgi;
    for (std::list<EpcS1apSap::ErabSwitchedInUplinkItem>::const_iterator l_iter =
             m_erabToBeSwitchedInUplinkList.begin();
         l_iter != m_erabToBeSwitchedInUplinkList.end();
         ++l_iter) // content of m_erabsToBeSetupList
    {
        os << " ErabId " << l_iter->erabId;
        os << " TransportLayerAddress " << l_iter->transportLayerAddress;
        os << " enbTeid " << l_iter->enbTeid;
    }
}

uint64_t
EpcS1APPathSwitchRequestAcknowledgeHeader::GetMmeUeS1Id() const
{
    return m_mmeUeS1Id;
}

void
EpcS1APPathSwitchRequestAcknowledgeHeader::SetMmeUeS1Id(uint64_t mmeUeS1Id)
{
    m_mmeUeS1Id = mmeUeS1Id;
}

uint16_t
EpcS1APPathSwitchRequestAcknowledgeHeader::GetEnbUeS1Id() const
{
    return m_enbUeS1Id;
}

void
EpcS1APPathSwitchRequestAcknowledgeHeader::SetEnbUeS1Id(uint16_t enbUeS1Id)
{
    m_enbUeS1Id = enbUeS1Id;
}

std::list<EpcS1apSap::ErabSwitchedInUplinkItem>
EpcS1APPathSwitchRequestAcknowledgeHeader::GetErabSwitchedInUplinkItemList() const
{
    return m_erabToBeSwitchedInUplinkList;
}

void
EpcS1APPathSwitchRequestAcknowledgeHeader::SetErabSwitchedInUplinkItemList(
    std::list<EpcS1apSap::ErabSwitchedInUplinkItem> erabSetupList)
{
    m_headerLength += erabSetupList.size() * 10;
    m_erabToBeSwitchedInUplinkList = erabSetupList;
}

uint16_t
EpcS1APPathSwitchRequestAcknowledgeHeader::GetEcgi() const
{
    return m_ecgi;
}

void
EpcS1APPathSwitchRequestAcknowledgeHeader::SetEcgi(uint16_t ecgi)
{
    m_ecgi = ecgi;
}

uint32_t
EpcS1APPathSwitchRequestAcknowledgeHeader::GetLengthOfIes() const
{
    return m_headerLength;
}

uint32_t
EpcS1APPathSwitchRequestAcknowledgeHeader::GetNumberOfIes() const
{
    return m_numberOfIes;
}

/////////////////////////////////////////////////////////////////////

}; // end of namespace ns3
