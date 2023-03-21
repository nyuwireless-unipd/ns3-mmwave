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
 * Author: Nicola Baldo <nbaldo@cttc.es> wrote the EpcMme class
 * Author: Michele Polese <michele.polese@gmail.com> wrote the Application version
 */

#ifndef EPC_MME_APPLICATION_H
#define EPC_MME_APPLICATION_H

#include <ns3/application.h>
#include <ns3/epc-s11-sap.h>
#include <ns3/epc-s1ap-sap.h>
#include <ns3/object.h>

#include <list>
#include <map>

namespace ns3
{

class Node;
class NetDevice;

/**
 * \brief This object implements as an application the MME functionality.
 *
 */
class EpcMmeApplication : public Application
{
    friend class MemberEpcS1apSapMme<EpcMmeApplication>;
    friend class MemberEpcS11SapMme<EpcMmeApplication>;

  public:
    /**
     * Constructor
     */
    EpcMmeApplication();

    /**
     * Destructor
     */
    virtual ~EpcMmeApplication();

    // inherited from Object
    static TypeId GetTypeId(void);

  protected:
    virtual void DoDispose();

  public:
    /**
     *
     * \return the MME side of the S1-AP SAP
     */
    EpcS1apSapMme* GetS1apSapMme();

    /**
     * \param the MME provider, given by the S1AP object associated to this application
     */
    void SetS1apSapMmeProvider(EpcS1apSapMmeProvider* provider);

    /**
     * Set the SGW side of the S11 SAP
     *
     * \param s the SGW side of the S11 SAP
     */
    void SetS11SapSgw(EpcS11SapSgw* s);

    /**
     *
     * \return the MME side of the S11 SAP
     */
    EpcS11SapMme* GetS11SapMme();

    /**
     * Add a new ENB to the MME.
     * \param ecgi E-UTRAN Cell Global ID, the unique identifier of the eNodeB
     * \param the eNB S1UAddr
     */
    void AddEnb(uint16_t ecgi, Ipv4Address enbS1UAddr);

    /**
     * Add a new UE to the MME. This is the equivalent of storing the UE
     * credentials before the UE is ever turned on.
     *
     * \param imsi the unique identifier of the UE
     */
    void AddUe(uint64_t imsi);

    /**
     * Add an EPS bearer to the list of bearers to be activated for this
     * UE. The bearer will be activated when the UE enters the ECM
     * connected state.
     *
     * \param imsi UE identifier
     * \param tft traffic flow template of the bearer
     * \param bearer QoS characteristics of the bearer
     */
    uint8_t AddBearer(uint64_t imsi, Ptr<EpcTft> tft, EpsBearer bearer);

  private:
    // S1-AP SAP MME forwarded methods
    void DoInitialUeMessage(uint64_t mmeUeS1Id, uint16_t enbUeS1Id, uint64_t imsi, uint16_t ecgi);
    void DoInitialContextSetupResponse(uint64_t mmeUeS1Id,
                                       uint16_t enbUeS1Id,
                                       std::list<EpcS1apSapMme::ErabSetupItem> erabSetupList);
    void DoPathSwitchRequest(
        uint64_t enbUeS1Id,
        uint64_t mmeUeS1Id,
        uint16_t cgi,
        std::list<EpcS1apSapMme::ErabSwitchedInDownlinkItem> erabToBeSwitchedInDownlinkList);
    void DoErabReleaseIndication(
        uint64_t mmeUeS1Id,
        uint16_t enbUeS1Id,
        std::list<EpcS1apSapMme::ErabToBeReleasedIndication> erabToBeReleaseIndication);

    // S11 SAP MME forwarded methods
    void DoCreateSessionResponse(EpcS11SapMme::CreateSessionResponseMessage msg);
    void DoModifyBearerResponse(EpcS11SapMme::ModifyBearerResponseMessage msg);
    void DoDeleteBearerRequest(EpcS11SapMme::DeleteBearerRequestMessage msg);

    /**
     * Hold info on an EPS bearer to be activated
     *
     */
    struct BearerInfo
    {
        Ptr<EpcTft> tft;
        EpsBearer bearer;
        uint8_t bearerId;
    };

    /**
     * Hold info on a UE
     *
     */
    struct UeInfo : public SimpleRefCount<UeInfo>
    {
        uint64_t mmeUeS1Id;
        uint16_t enbUeS1Id;
        uint64_t imsi;
        uint16_t cellId;
        std::list<BearerInfo> bearersToBeActivated;
        uint16_t bearerCounter;
    };

    /**
     * UeInfo stored by IMSI
     *
     */
    std::map<uint64_t, Ptr<UeInfo>> m_ueInfoMap;

    /**
     * \brief This Function erases all contexts of bearer from MME side
     * \param ueInfo UE information pointer
     * \param epsBearerId Bearer Id which need to be removed corresponding to UE
     */
    void RemoveBearer(Ptr<UeInfo> ueInfo, uint8_t epsBearerId);

    /**
     * Hold info on a ENB
     *
     */
    struct EnbInfo : public SimpleRefCount<EnbInfo>
    {
        uint16_t gci;
        Ipv4Address s1uAddr;
    };

    /**
     * EnbInfo stored by EGCI
     *
     */
    std::map<uint16_t, Ptr<EnbInfo>> m_enbInfoMap;

    EpcS1apSapMme* m_s1apSapMme;
    EpcS1apSapMmeProvider* m_s1apSapMmeProvider;

    EpcS11SapMme* m_s11SapMme;
    EpcS11SapSgw* m_s11SapSgw;
};

} // namespace ns3

#endif // EPC_MME_APPLICATION_H
