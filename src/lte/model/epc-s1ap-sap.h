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
 * Author: Nicola Baldo <nbaldo@cttc.cat>
 * Modified by: Michele Polese <michele.polese@gmail.com>
 */

#ifndef EPC_S1AP_SAP_H
#define EPC_S1AP_SAP_H

#include <ns3/address.h>
#include <ns3/epc-tft.h>
#include <ns3/eps-bearer.h>
#include <ns3/object.h>
#include <ns3/ptr.h>

#include <list>

namespace ns3
{

class EpcS1apSap
{
  public:
    virtual ~EpcS1apSap();

    // useful structures as defined in 3GPP ts 36.413

    /**
     *  E-RAB Release Indication Item IEs, 3GPP TS 36.413 version 9.8.0 section 9.1.3.7
     *
     */
    struct ErabToBeReleasedIndication
    {
        uint8_t erabId;
    };

    /**
     *  E-RAB Setup Item IEs, see 3GPP TS 36.413 9.1.4.2
     *
     */
    struct ErabSetupItem
    {
        uint16_t erabId;
        Ipv4Address enbTransportLayerAddress;
        uint32_t enbTeid;
    };

    /**
     * E-RABs Switched in Downlink Item IE, see 3GPP TS 36.413 9.1.5.8
     *
     */
    struct ErabSwitchedInDownlinkItem
    {
        uint16_t erabId;
        Ipv4Address enbTransportLayerAddress;
        uint32_t enbTeid;
    };

    struct ErabToBeSetupItem
    {
        uint8_t erabId;
        EpsBearer erabLevelQosParameters;
        Ipv4Address transportLayerAddress;
        uint32_t sgwTeid;
    };

    /**
     * E-RABs Switched in Uplink Item IE, see 3GPP TS 36.413 9.1.5.9
     *
     */
    struct ErabSwitchedInUplinkItem
    {
        uint8_t erabId;
        Ipv4Address transportLayerAddress;
        uint32_t enbTeid;
    };
};

/**
 * \ingroup lte
 *
 * MME side of the S1-AP Service Access Point (SAP) user, provides the MME
 * methods to be called when an S1-AP message is received by the MME S1-AP object.
 * S1-AP ---> MME
 */
class EpcS1apSapMme : public EpcS1apSap
{
  public:
    /**
     * 3GPP TS 36.413 V13.1.0 section 9.1.7.1
     * \param mmeUeS1Id in practice, we use the IMSI
     * \param enbUeS1Id in practice, we use the RNTI
     * \param stmsi in practice, the imsi
     * \param ecgi in practice, the cell Id
     *
     */
    virtual void InitialUeMessage(uint64_t mmeUeS1Id,
                                  uint16_t enbUeS1Id,
                                  uint64_t stmsi,
                                  uint16_t ecgi) = 0;

    /**
     * \brief As per 3GPP TS 23.401 Release 9 V9.5.0 Figure 5.4.4.2-1  eNB sends indication of
     * Bearer Release to MME \brief As per 3GPP TS version 9.8.0 section 8.2.3.2.2, the eNB
     * initiates the procedure by sending an E-RAB RELEASE INDICATION message towards MME \param
     * mmeUeS1Id in practice, we use the IMSI \param enbUeS1Id in practice, we use the RNTI \param
     * erabToBeReleaseIndication, List of bearers to be deactivated
     *
     */
    virtual void ErabReleaseIndication(
        uint64_t mmeUeS1Id,
        uint16_t enbUeS1Id,
        std::list<ErabToBeReleasedIndication> erabToBeReleaseIndication) = 0;

    /**
     * INITIAL CONTEXT SETUP RESPONSE message,  see 3GPP TS 36.413 9.1.4.2
     *
     * \param mmeUeS1Id in practice, we use the IMSI
     * \param enbUeS1Id in practice, we use the RNTI
     * \param erabSetupList
     *
     */
    virtual void InitialContextSetupResponse(uint64_t mmeUeS1Id,
                                             uint16_t enbUeS1Id,
                                             std::list<ErabSetupItem> erabSetupList) = 0;

    /**
     * PATH SWITCH REQUEST message, see 3GPP TS 36.413 9.1.5.8
     *
     */
    virtual void PathSwitchRequest(
        uint64_t enbUeS1Id,
        uint64_t mmeUeS1Id,
        uint16_t gci,
        std::list<ErabSwitchedInDownlinkItem> erabToBeSwitchedInDownlinkList) = 0;
};

/**
 * \ingroup lte
 *
 * eNB side of the S1-AP Service Access Point (SAP) provider, provides the S1-AP methods
 * to be called when the eNB wants to send an S1-AP message
 * eNB ---> S1-AP
 */
class EpcS1apSapEnbProvider : public EpcS1apSap
{
  public:
    virtual void SendInitialUeMessage(uint64_t mmeUeS1Id,
                                      uint16_t enbUeS1Id,
                                      uint64_t stmsi,
                                      uint16_t ecgi) = 0;

    virtual void SendErabReleaseIndication(
        uint64_t mmeUeS1Id,
        uint16_t enbUeS1Id,
        std::list<ErabToBeReleasedIndication> erabToBeReleaseIndication) = 0;

    virtual void SendInitialContextSetupResponse(uint64_t mmeUeS1Id,
                                                 uint16_t enbUeS1Id,
                                                 std::list<ErabSetupItem> erabSetupList) = 0;

    virtual void SendPathSwitchRequest(
        uint64_t enbUeS1Id,
        uint64_t mmeUeS1Id,
        uint16_t gci,
        std::list<ErabSwitchedInDownlinkItem> erabToBeSwitchedInDownlinkList) = 0;
};

/**
 * \ingroup lte
 *
 * eNB side of the S1-AP Service Access Point (SAP) user, provides the eNB
 * methods to be called when an S1-AP message is received by the eNB S1-AP object.
 * S1-AP ---> eNB
 */
class EpcS1apSapEnb : public EpcS1apSap
{
  public:
    /**
     *
     * 3GPP TS 36.413 9.1.4.1
     * \param mmeUeS1Id in practice, we use the IMSI
     * \param enbUeS1Id in practice, we use the RNTI
     * \param erabToBeSetupList
     * \param cellId, to select the enb to which the MME wants to communicate
     *
     */
    virtual void InitialContextSetupRequest(uint64_t mmeUeS1Id,
                                            uint16_t enbUeS1Id,
                                            std::list<ErabToBeSetupItem> erabToBeSetupList) = 0;

    /**
     * PATH SWITCH REQUEST ACKNOWLEDGE message, see 3GPP TS 36.413 9.1.5.9
     *
     */
    virtual void PathSwitchRequestAcknowledge(
        uint64_t enbUeS1Id,
        uint64_t mmeUeS1Id,
        uint16_t cgi,
        std::list<ErabSwitchedInUplinkItem> erabToBeSwitchedInUplinkList) = 0;
};

/**
 * \ingroup lte
 *
 * MME side of the S1-AP Service Access Point (SAP) provider, provides the S1-AP methods
 * to be called when the MME wants to send an S1-AP message
 * MME ---> S1-AP
 */
class EpcS1apSapMmeProvider : public EpcS1apSap
{
  public:
    virtual void SendInitialContextSetupRequest(uint64_t mmeUeS1Id,
                                                uint16_t enbUeS1Id,
                                                std::list<ErabToBeSetupItem> erabToBeSetupList,
                                                uint16_t cellId) = 0;

    virtual void SendPathSwitchRequestAcknowledge(
        uint64_t enbUeS1Id,
        uint64_t mmeUeS1Id,
        uint16_t cgi,
        std::list<ErabSwitchedInUplinkItem> erabToBeSwitchedInUplinkList) = 0;
};

/**
 * Template for the implementation of the EpcS1apSapMmeUser as a member
 * of an owner class of type C to which all methods are forwarded
 *
 */
template <class C>
class MemberEpcS1apSapMme : public EpcS1apSapMme
{
  public:
    MemberEpcS1apSapMme(C* owner);

    // inherited from EpcS1apSapMme
    virtual void InitialUeMessage(uint64_t mmeUeS1Id,
                                  uint16_t enbUeS1Id,
                                  uint64_t imsi,
                                  uint16_t ecgi);
    virtual void ErabReleaseIndication(
        uint64_t mmeUeS1Id,
        uint16_t enbUeS1Id,
        std::list<ErabToBeReleasedIndication> erabToBeReleaseIndication);

    virtual void InitialContextSetupResponse(uint64_t mmeUeS1Id,
                                             uint16_t enbUeS1Id,
                                             std::list<ErabSetupItem> erabSetupList);
    virtual void PathSwitchRequest(
        uint64_t enbUeS1Id,
        uint64_t mmeUeS1Id,
        uint16_t cgi,
        std::list<ErabSwitchedInDownlinkItem> erabToBeSwitchedInDownlinkList);

  private:
    MemberEpcS1apSapMme();
    C* m_owner;
};

template <class C>
MemberEpcS1apSapMme<C>::MemberEpcS1apSapMme(C* owner)
    : m_owner(owner)
{
}

template <class C>
MemberEpcS1apSapMme<C>::MemberEpcS1apSapMme()
{
}

template <class C>
void
MemberEpcS1apSapMme<C>::InitialUeMessage(uint64_t mmeUeS1Id,
                                         uint16_t enbUeS1Id,
                                         uint64_t imsi,
                                         uint16_t ecgi)
{
    m_owner->DoInitialUeMessage(mmeUeS1Id, enbUeS1Id, imsi, ecgi);
}

template <class C>
void
MemberEpcS1apSapMme<C>::ErabReleaseIndication(
    uint64_t mmeUeS1Id,
    uint16_t enbUeS1Id,
    std::list<ErabToBeReleasedIndication> erabToBeReleaseIndication)
{
    m_owner->DoErabReleaseIndication(mmeUeS1Id, enbUeS1Id, erabToBeReleaseIndication);
}

template <class C>
void
MemberEpcS1apSapMme<C>::InitialContextSetupResponse(uint64_t mmeUeS1Id,
                                                    uint16_t enbUeS1Id,
                                                    std::list<ErabSetupItem> erabSetupList)
{
    m_owner->DoInitialContextSetupResponse(mmeUeS1Id, enbUeS1Id, erabSetupList);
}

template <class C>
void
MemberEpcS1apSapMme<C>::PathSwitchRequest(
    uint64_t enbUeS1Id,
    uint64_t mmeUeS1Id,
    uint16_t cgi,
    std::list<ErabSwitchedInDownlinkItem> erabToBeSwitchedInDownlinkList)
{
    m_owner->DoPathSwitchRequest(enbUeS1Id, mmeUeS1Id, cgi, erabToBeSwitchedInDownlinkList);
}

/**
 * Template for the implementation of the EpcS1apSapEnbProvider as a member
 * of an owner class of type C to which all methods are forwarded
 *
 */
template <class C>
class MemberEpcS1apSapEnbProvider : public EpcS1apSapEnbProvider
{
  public:
    MemberEpcS1apSapEnbProvider(C* owner);

    // inherited from MemberEpcS1apSapEnbProvider
    virtual void SendInitialUeMessage(uint64_t mmeUeS1Id,
                                      uint16_t enbUeS1Id,
                                      uint64_t imsi,
                                      uint16_t ecgi);
    virtual void SendErabReleaseIndication(
        uint64_t mmeUeS1Id,
        uint16_t enbUeS1Id,
        std::list<ErabToBeReleasedIndication> erabToBeReleaseIndication);

    virtual void SendInitialContextSetupResponse(uint64_t mmeUeS1Id,
                                                 uint16_t enbUeS1Id,
                                                 std::list<ErabSetupItem> erabSetupList);
    virtual void SendPathSwitchRequest(
        uint64_t enbUeS1Id,
        uint64_t mmeUeS1Id,
        uint16_t cgi,
        std::list<ErabSwitchedInDownlinkItem> erabToBeSwitchedInDownlinkList);

  private:
    MemberEpcS1apSapEnbProvider();
    C* m_owner;
};

template <class C>
MemberEpcS1apSapEnbProvider<C>::MemberEpcS1apSapEnbProvider(C* owner)
    : m_owner(owner)
{
}

template <class C>
MemberEpcS1apSapEnbProvider<C>::MemberEpcS1apSapEnbProvider()
{
}

template <class C>
void
MemberEpcS1apSapEnbProvider<C>::SendInitialUeMessage(uint64_t mmeUeS1Id,
                                                     uint16_t enbUeS1Id,
                                                     uint64_t imsi,
                                                     uint16_t ecgi)
{
    m_owner->DoSendInitialUeMessage(mmeUeS1Id, enbUeS1Id, imsi, ecgi);
}

template <class C>
void
MemberEpcS1apSapEnbProvider<C>::SendErabReleaseIndication(
    uint64_t mmeUeS1Id,
    uint16_t enbUeS1Id,
    std::list<ErabToBeReleasedIndication> erabToBeReleaseIndication)
{
    m_owner->DoSendErabReleaseIndication(mmeUeS1Id, enbUeS1Id, erabToBeReleaseIndication);
}

template <class C>
void
MemberEpcS1apSapEnbProvider<C>::SendInitialContextSetupResponse(
    uint64_t mmeUeS1Id,
    uint16_t enbUeS1Id,
    std::list<ErabSetupItem> erabSetupList)
{
    m_owner->DoSendInitialContextSetupResponse(mmeUeS1Id, enbUeS1Id, erabSetupList);
}

template <class C>
void
MemberEpcS1apSapEnbProvider<C>::SendPathSwitchRequest(
    uint64_t enbUeS1Id,
    uint64_t mmeUeS1Id,
    uint16_t cgi,
    std::list<ErabSwitchedInDownlinkItem> erabToBeSwitchedInDownlinkList)
{
    m_owner->DoSendPathSwitchRequest(enbUeS1Id, mmeUeS1Id, cgi, erabToBeSwitchedInDownlinkList);
}

/**
 * Template for the implementation of the EpcS1apSapEnb as a member
 * of an owner class of type C to which all methods are forwarded
 *
 */
template <class C>
class MemberEpcS1apSapEnb : public EpcS1apSapEnb
{
  public:
    MemberEpcS1apSapEnb(C* owner);

    // inherited from EpcS1apSapEnb
    virtual void InitialContextSetupRequest(uint64_t mmeUeS1Id,
                                            uint16_t enbUeS1Id,
                                            std::list<ErabToBeSetupItem> erabToBeSetupList);
    virtual void PathSwitchRequestAcknowledge(
        uint64_t enbUeS1Id,
        uint64_t mmeUeS1Id,
        uint16_t cgi,
        std::list<ErabSwitchedInUplinkItem> erabToBeSwitchedInUplinkList);

  private:
    MemberEpcS1apSapEnb();
    C* m_owner;
};

template <class C>
MemberEpcS1apSapEnb<C>::MemberEpcS1apSapEnb(C* owner)
    : m_owner(owner)
{
}

template <class C>
MemberEpcS1apSapEnb<C>::MemberEpcS1apSapEnb()
{
}

template <class C>
void
MemberEpcS1apSapEnb<C>::InitialContextSetupRequest(uint64_t mmeUeS1Id,
                                                   uint16_t enbUeS1Id,
                                                   std::list<ErabToBeSetupItem> erabToBeSetupList)
{
    m_owner->DoInitialContextSetupRequest(mmeUeS1Id, enbUeS1Id, erabToBeSetupList);
}

template <class C>
void
MemberEpcS1apSapEnb<C>::PathSwitchRequestAcknowledge(
    uint64_t enbUeS1Id,
    uint64_t mmeUeS1Id,
    uint16_t cgi,
    std::list<ErabSwitchedInUplinkItem> erabToBeSwitchedInUplinkList)
{
    m_owner->DoPathSwitchRequestAcknowledge(enbUeS1Id,
                                            mmeUeS1Id,
                                            cgi,
                                            erabToBeSwitchedInUplinkList);
}

/**
 * Template for the implementation of the EpcS1apSapMmeProvider as a member
 * of an owner class of type C to which all methods are forwarded
 *
 */
template <class C>
class MemberEpcS1apSapMmeProvider : public EpcS1apSapMmeProvider
{
  public:
    MemberEpcS1apSapMmeProvider(C* owner);

    // inherited from EpcS1apSapMmeProvider
    virtual void SendInitialContextSetupRequest(uint64_t mmeUeS1Id,
                                                uint16_t enbUeS1Id,
                                                std::list<ErabToBeSetupItem> erabToBeSetupList,
                                                uint16_t cellId);
    virtual void SendPathSwitchRequestAcknowledge(
        uint64_t enbUeS1Id,
        uint64_t mmeUeS1Id,
        uint16_t cgi,
        std::list<ErabSwitchedInUplinkItem> erabToBeSwitchedInUplinkList);

  private:
    MemberEpcS1apSapMmeProvider();
    C* m_owner;
};

template <class C>
MemberEpcS1apSapMmeProvider<C>::MemberEpcS1apSapMmeProvider(C* owner)
    : m_owner(owner)
{
}

template <class C>
MemberEpcS1apSapMmeProvider<C>::MemberEpcS1apSapMmeProvider()
{
}

template <class C>
void
MemberEpcS1apSapMmeProvider<C>::SendInitialContextSetupRequest(
    uint64_t mmeUeS1Id,
    uint16_t enbUeS1Id,
    std::list<ErabToBeSetupItem> erabToBeSetupList,
    uint16_t cellId)
{
    m_owner->DoSendInitialContextSetupRequest(mmeUeS1Id, enbUeS1Id, erabToBeSetupList, cellId);
}

template <class C>
void
MemberEpcS1apSapMmeProvider<C>::SendPathSwitchRequestAcknowledge(
    uint64_t enbUeS1Id,
    uint64_t mmeUeS1Id,
    uint16_t cgi,
    std::list<ErabSwitchedInUplinkItem> erabToBeSwitchedInUplinkList)
{
    m_owner->DoSendPathSwitchRequestAcknowledge(enbUeS1Id,
                                                mmeUeS1Id,
                                                cgi,
                                                erabToBeSwitchedInUplinkList);
}

} // namespace ns3

#endif /* EPC_S1AP_SAP_H */
