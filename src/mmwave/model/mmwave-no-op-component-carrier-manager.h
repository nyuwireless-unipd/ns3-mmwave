/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2015 Danilo Abrignani
 * Copyright (c) 2016 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 * Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 * Authors: Danilo Abrignani <danilo.abrignani@unibo.it>
 *          Biljana Bojovic <biljana.bojovic@cttc.es>
 *
 * Modified by: Tommaso Zugno <tommasozugno@gmail.com>
 *                               Integration of Carrier Aggregation for the mmWave module
 */

#ifndef MMWAVE_NO_OP_COMPONENT_CARRIER_MANAGER_H
#define MMWAVE_NO_OP_COMPONENT_CARRIER_MANAGER_H

#include <ns3/lte-ccm-rrc-sap.h>
#include <ns3/lte-enb-component-carrier-manager.h>
#include <ns3/lte-rrc-sap.h>

#include <map>

namespace ns3
{

class UeManager;
class LteCcmRrcSapProvider;

namespace mmwave
{

/**
 * \brief The default component carrier manager that forwards all traffic, the uplink and the
 * downlink, over the primary carrier, and will not use secondary carriers. To enable carrier
 * aggregation feature, select another component carrier manager class, i.e., some of child classes
 * of LteEnbComponentCarrierManager of MmWaveNoOpComponentCarrierManager.
 */

class MmWaveNoOpComponentCarrierManager : public LteEnbComponentCarrierManager
{
    /// allow EnbMacMemberLteMacSapProvider<MmWaveNoOpComponentCarrierManager> class friend access
    friend class EnbMacMemberLteMacSapProvider<MmWaveNoOpComponentCarrierManager>;
    /// allow MemberLteCcmRrcSapProvider<MmWaveNoOpComponentCarrierManager> class friend access
    friend class MemberLteCcmRrcSapProvider<MmWaveNoOpComponentCarrierManager>;
    /// allow MemberLteCcmRrcSapUser<MmWaveNoOpComponentCarrierManager> class friend access
    friend class MemberLteCcmRrcSapUser<MmWaveNoOpComponentCarrierManager>;
    /// allow MemberLteCcmMacSapUser<MmWaveNoOpComponentCarrierManager> class friend access
    friend class MemberLteCcmMacSapUser<MmWaveNoOpComponentCarrierManager>;

  public:
    MmWaveNoOpComponentCarrierManager();
    virtual ~MmWaveNoOpComponentCarrierManager();
    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId();

  protected:
    // Inherited methods
    virtual void DoInitialize() override;
    virtual void DoDispose() override;
    virtual void DoReportUeMeas(uint16_t rnti, LteRrcSap::MeasResults measResults) override;
    /**
     * \brief Add UE.
     * \param rnti the RNTI
     * \param state the state
     */
    virtual void DoAddUe(uint16_t rnti, uint8_t state);
    /**
     * \brief Add LC.
     * \param lcInfo the LC info
     * \param msu the MSU
     */
    virtual void DoAddLc(LteEnbCmacSapProvider::LcInfo lcInfo, LteMacSapUser* msu);
    /**
     * \brief Setup data radio bearer.
     * \param bearer the radio bearer
     * \param bearerId the bearerID
     * \param rnti the RNTI
     * \param lcid the LCID
     * \param lcGroup the LC group
     * \param msu the MSU
     * \returns std::vector<LteCcmRrcSapProvider::LcsConfig>
     */
    virtual std::vector<LteCcmRrcSapProvider::LcsConfig> DoSetupDataRadioBearer(EpsBearer bearer,
                                                                                uint8_t bearerId,
                                                                                uint16_t rnti,
                                                                                uint8_t lcid,
                                                                                uint8_t lcGroup,
                                                                                LteMacSapUser* msu);
    /**
     * \brief Transmit PDU.
     * \param params the transmit PDU parameters
     */
    virtual void DoTransmitPdu(LteMacSapProvider::TransmitPduParameters params);
    /**
     * \brief Report buffer status.
     * \param params the report buffer status parameters
     */
    virtual void DoReportBufferStatus(LteMacSapProvider::ReportBufferStatusParameters params);
    /**
     * \brief Notify transmit opportunity.
     * \param txOpParams the TX opportunity parameters
     */
    virtual void DoNotifyTxOpportunity(LteMacSapUser::TxOpportunityParameters txOpParams);
    /**
     * \brief Receive PDU.
     * \param rxPduParams the parameters of the received PDU
     */
    virtual void DoReceivePdu(LteMacSapUser::ReceivePduParameters rxPduParams);
    /// Notify HARQ delivery failure
    virtual void DoNotifyHarqDeliveryFailure();
    /**
     * \brief Remove UE.
     * \param rnti the RNTI
     */
    virtual void DoRemoveUe(uint16_t rnti);
    /**
     * \brief Release data radio bearer.
     * \param rnti the RNTI
     * \param lcid the LCID
     * \returns updated data radio bearer list
     */
    virtual std::vector<uint8_t> DoReleaseDataRadioBearer(uint16_t rnti, uint8_t lcid);
    /**
     * \brief Configure the signal bearer.
     * \param lcinfo the LteEnbCmacSapProvider::LcInfo
     * \param msu the MSU
     * \returns updated data radio bearer list
     */
    virtual LteMacSapUser* DoConfigureSignalBearer(LteEnbCmacSapProvider::LcInfo lcinfo,
                                                   LteMacSapUser* msu);
    /**
     * \brief Forwards uplink BSR to CCM, called by MAC through CCM SAP interface.
     * \param bsr the BSR
     * \param componentCarrierId the component carrier ID
     */
    virtual void DoUlReceiveMacCe(MacCeListElement_s bsr, uint8_t componentCarrierId);
    /**
     * \brief Function implements the function of the SAP interface of CCM instance which is used by
     * MAC to notify the PRB occupancy reported by scheduler. \param prbOccupancy the PRB occupancy
     * \param componentCarrierId the component carrier ID
     */
    virtual void DoNotifyPrbOccupancy(double prbOccupancy, uint8_t componentCarrierId);

  protected:
    std::map<uint8_t, double>
        m_ccPrbOccupancy; //!< The physical resource block occupancy per carrier.

}; // end of class MmWaveNoOpComponentCarrierManager

/*
 * \brief Component carrier manager implementation that splits traffic equally among carriers.
 */
class MmWaveRrComponentCarrierManager : public MmWaveNoOpComponentCarrierManager
{
  public:
    MmWaveRrComponentCarrierManager();
    virtual ~MmWaveRrComponentCarrierManager();
    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId();

  protected:
    // Inherited methods
    virtual void DoReportBufferStatus(LteMacSapProvider::ReportBufferStatusParameters params);
    virtual void DoUlReceiveMacCe(MacCeListElement_s bsr, uint8_t componentCarrierId);

}; // end of class MmWaveRrComponentCarrierManager

/*
 * \brief Component carrier manager implementation. The MmWaveBaRrComponentCarrierManager
 *        divides the BSR according to the bandwidth ratio across the carriers.
 */
class MmWaveBaRrComponentCarrierManager : public MmWaveNoOpComponentCarrierManager
{
  public:
    MmWaveBaRrComponentCarrierManager();
    virtual ~MmWaveBaRrComponentCarrierManager();
    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId();

  protected:
    // Inherited methods
    virtual void DoReportBufferStatus(LteMacSapProvider::ReportBufferStatusParameters params);
    virtual void DoUlReceiveMacCe(MacCeListElement_s bsr, uint8_t componentCarrierId);

}; // end of class MmWaveBaRrComponentCarrierManager

} // end of namespace mmwave

} // end of namespace ns3

#endif /* MMWAVE_NO_OP_COMPONENT_CARRIER_MANAGER_H */
