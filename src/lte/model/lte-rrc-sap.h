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
 * Authors: Nicola Baldo <nbaldo@cttc.es>
 *          Lluis Parcerisa <lparcerisa@cttc.cat>
 *
 * Modified by: Michele Polese <michele.polese@gmail.com>
 *          Dual Connectivity functionalities
 * Modified by: Argha Sen <arghasen10@gmail.com>
 *              Integration of RRC Energy Module
 */


#ifndef LTE_RRC_SAP_H
#define LTE_RRC_SAP_H

#include <stdint.h>
#include <list>

#include <ns3/ptr.h>
#include <ns3/simulator.h>

namespace ns3 {

class LteRlcSapUser;
class LtePdcpSapUser;
class LteRlcSapProvider;
class LtePdcpSapProvider;
class Packet;

/**
 * \ingroup lte
 *
 * \brief Class holding definition common to all UE/eNodeB SAP Users/Providers.
 *
 * See 3GPP TS 36.331 for reference.
 *
 * Note that only those values that are (expected to be) used by the
 * ns-3 model are mentioned here. The naming of the variables that are
 * defined here is the same of 36.331, except for removal of "-" and
 * conversion to CamelCase or ALL_CAPS where needed in order to follow
 * the ns-3 coding style. Due to the 1-to-1 mapping with TS 36.331,
 * detailed doxygen documentation is omitted, so please refer to
 * 36.331 for the meaning of these data structures / fields.
 *
 */
class LteRrcSap
{
public:
  virtual ~LteRrcSap ();

  /// Constraint values
  static const uint8_t MaxReportCells = 8;

  // Information Elements
  /// PlmnIdentityInfo structure
  struct PlmnIdentityInfo
  {
    uint32_t plmnIdentity; ///< PLMN identity
  };

  /// CellAccessRelatedInfo structure
  struct CellAccessRelatedInfo
  {
    PlmnIdentityInfo plmnIdentityInfo; ///< PLMN identity info
    uint32_t cellIdentity; ///< cell identity
    bool csgIndication; ///< CSG indication
    uint32_t csgIdentity; ///< CSG identity
  };

  /// CellSelectionInfo structure
  struct CellSelectionInfo
  {
    int8_t qRxLevMin; ///< INTEGER (-70..-22), actual value = IE value * 2 [dBm].
    int8_t qQualMin; ///< INTEGER (-34..-3), actual value = IE value [dB].
  };

  /// FreqInfo structure
  struct FreqInfo
  {
    uint32_t ulCarrierFreq; ///< UL carrier frequency
    uint8_t ulBandwidth; ///< UL bandwidth
  };

  /// RlcConfig structure
  struct RlcConfig
  {
    /// the direction choice
    enum direction
    {
      AM,
      UM_BI_DIRECTIONAL,
      UM_UNI_DIRECTIONAL_UL,
      UM_UNI_DIRECTIONAL_DL,
      UM_BI_DIRECTIONAL_LOWLAT
    } choice; ///< direction choice
  };

  /// LogicalChannelConfig structure
  struct LogicalChannelConfig
  {
    uint8_t priority; ///< priority
    uint16_t prioritizedBitRateKbps; ///< prioritized bit rate Kbps
    uint16_t bucketSizeDurationMs; ///< bucket size duration ms
    uint8_t logicalChannelGroup; ///< logical channel group
  };

  /// SoundingRsUlConfigCommon structure
  struct SoundingRsUlConfigCommon
  {
    /// the config action
    enum action
    {
      SETUP, RESET
    } type; ///< action type
    uint8_t srsBandwidthConfig; ///< SRS bandwidth config
    uint8_t srsSubframeConfig; ///< SRS subframe config
  };

  /// SoundingRsUlConfigDedicated structure
  struct SoundingRsUlConfigDedicated
  {
    /// the config action
    enum action
    {
      SETUP, RESET
    } type; ///< action type
    uint8_t srsBandwidth; ///< SRS bandwidth
    uint16_t srsConfigIndex; ///< SRS config index
  };

  /// AntennaInfoDedicated structure
  struct AntennaInfoDedicated
  {
    uint8_t transmissionMode; ///< transmission mode
  };

  /// PdschConfigCommon structure
  struct PdschConfigCommon
  {
    int8_t referenceSignalPower;  ///< INTEGER (-60..50),
    int8_t pb;                    ///< INTEGER (0..3),
  };

  /// PdschConfigDedicated structure
  struct PdschConfigDedicated
  {
    /**
     * P_A values, TS 36.331 6.3.2 PDSCH-Config
     * ENUMERATED { dB-6, dB-4dot77, dB-3, dB-1dot77, dB0, dB1, dB2, dB3 }
     */
    enum db
    {
      dB_6,
      dB_4dot77,
      dB_3,
      dB_1dot77,
      dB0,
      dB1,
      dB2,
      dB3
    };
    uint8_t pa; ///< P_A value
  };

  /**
   * Convert PDSCH config dedicated function
   *
   * \param pdschConfigDedicated PdschConfigDedicated
   * \returns double value
   */
  static double ConvertPdschConfigDedicated2Double (PdschConfigDedicated pdschConfigDedicated)
  {
    double pa = 0;
    switch (pdschConfigDedicated.pa)
      {
      case PdschConfigDedicated::dB_6:
        pa = -6;
        break;
      case PdschConfigDedicated::dB_4dot77:
        pa = -4.77;
        break;
      case PdschConfigDedicated::dB_3:
        pa = -3;
        break;
      case PdschConfigDedicated::dB_1dot77:
        pa = -1.77;
        break;
      case PdschConfigDedicated::dB0:
        pa = 0;
        break;
      case PdschConfigDedicated::dB1:
        pa = 1;
        break;
      case PdschConfigDedicated::dB2:
        pa = 2;
        break;
      case PdschConfigDedicated::dB3:
        pa = 3;
        break;
      default:
        break;
      }
    return pa;
  }

  /// PhysicalConfigDedicated structure
  struct PhysicalConfigDedicated
  {
    bool haveSoundingRsUlConfigDedicated; ///< have sounding RS UL config dedicated?
    SoundingRsUlConfigDedicated soundingRsUlConfigDedicated; ///< sounding RS UL config dedicated
    bool haveAntennaInfoDedicated; ///< have antenna info dedicated?
    AntennaInfoDedicated antennaInfo; ///< antenna info
    bool havePdschConfigDedicated; ///< have PDSCH config dedicated?
    PdschConfigDedicated pdschConfigDedicated; ///< PDSCH config dedicated
  };


  /// SrbToAddMod structure
  struct SrbToAddMod
  {
    uint8_t srbIdentity; ///< SB identity
    LogicalChannelConfig logicalChannelConfig; ///< logical channel config
  };

  /// DrbToAddMod structure
  struct DrbToAddMod
  {
    uint8_t epsBearerIdentity; ///< EPS bearer identity
    uint8_t drbIdentity; ///< DRB identity
    RlcConfig rlcConfig; ///< RLC config
    uint8_t logicalChannelIdentity; ///< logical channel identify
    LogicalChannelConfig logicalChannelConfig; ///< logical channel config
    bool is_mc;
  };

  /// PreambleInfo structure
  struct PreambleInfo
  {
    uint8_t numberOfRaPreambles; ///< number of RA preambles
  };

  /// RaSupervisionInfo structure
  struct RaSupervisionInfo
  {
    uint8_t preambleTransMax; ///< preamble transmit maximum
    uint8_t raResponseWindowSize; ///< RA response window size
  };

  /// RachConfigCommon structure
  struct RachConfigCommon
  {
    PreambleInfo preambleInfo; ///< preamble info
    RaSupervisionInfo raSupervisionInfo; ///< RA supervision info
  };

  /// RadioResourceConfigCommon structure
  struct RadioResourceConfigCommon
  {
    RachConfigCommon rachConfigCommon; ///< RACH config common
  };

  struct PcchConfig
  {
    uint16_t defaultPagingCycle;
    float nb;
  };

  struct BcchConfig
  {
    uint16_t modificationPeriodCoeff;
  };

  /// RadioResourceConfigCommonSib structure
  struct RadioResourceConfigCommonSib
  {
    RachConfigCommon rachConfigCommon; ///< RACH config common
    PdschConfigCommon pdschConfigCommon; ///< PDSCH config common
  };

  /// RadioResourceConfigDedicated structure
  struct RadioResourceConfigDedicated
  {
    std::list<SrbToAddMod> srbToAddModList; ///< SRB to add mod list
    std::list<DrbToAddMod> drbToAddModList; ///< DRB to add mod list
    std::list<uint8_t> drbToReleaseList; ///< DRB to release list
    bool havePhysicalConfigDedicated; ///< have physical config dedicated?
    PhysicalConfigDedicated physicalConfigDedicated; ///< physical config dedicated
  };

  /// QuantityConfig structure
  struct QuantityConfig
  {
    uint8_t filterCoefficientRSRP; ///< filter coefficient RSRP
    uint8_t filterCoefficientRSRQ; ///< filter coefficient RSRQ
  };

  /// CellsToAddMod structure
  struct CellsToAddMod
  {
    uint8_t cellIndex; ///< cell index
    uint16_t physCellId; ///< Phy cell ID
    int8_t cellIndividualOffset; ///< cell individual offset
  };

  /// PhysCellIdRange structure
  struct PhysCellIdRange
  {
    uint16_t start; ///< starting cell ID
    bool haveRange; ///< has a range?
    uint16_t range; ///< the range
  };

  /// BlackCellsToAddMod structure
  struct BlackCellsToAddMod
  {
    uint8_t cellIndex; ///< cell index
    PhysCellIdRange physCellIdRange; ///< Phy cell ID range
  };

  /// MeasObjectEutra structure
  struct MeasObjectEutra
  {
    uint32_t carrierFreq; ///< carrier frequency
    uint8_t allowedMeasBandwidth; ///< allowed measure bandwidth
    bool presenceAntennaPort1; ///< antenna port 1 present?
    uint8_t neighCellConfig; ///< neighbor cell config
    int8_t offsetFreq; ///< offset frequency
    std::list<uint8_t> cellsToRemoveList; ///< cells to remove list
    std::list<CellsToAddMod> cellsToAddModList; ///< cells to add mod list
    std::list<uint8_t> blackCellsToRemoveList; ///< black cells to remove list
    std::list<BlackCellsToAddMod> blackCellsToAddModList; ///< black cells to add mod list
    bool haveCellForWhichToReportCGI; ///< have cell for which to report CGI?
    uint16_t cellForWhichToReportCGI; ///< cell for which to report CGI
  };

  /**
   * \brief Threshold for event evaluation.
   *
   * For RSRP-based threshold, the actual value is (value - 140) dBm. While for
   * RSRQ-based threshold, the actual value is (value - 40) / 2 dB. This is in
   * accordance with section 9.1.4 and 9.1.7 of 3GPP TS 36.133.
   *
   * \sa ns3::EutranMeasurementMapping
   */
  struct ThresholdEutra
  {
    /// Threshold enumeration
    enum
    {
      THRESHOLD_RSRP, ///< RSRP is used for the threshold.
      THRESHOLD_RSRQ ///< RSRQ is used for the threshold.
    } choice;
    uint8_t range; ///< Value range used in RSRP/RSRQ threshold.
  };

  /// Specifies criteria for triggering of an E-UTRA measurement reporting event.
  struct ReportConfigEutra
  {
    /// Trigger enumeration
    enum
    {
      EVENT,      ///< event report
      PERIODICAL  ///< periodical report
    } triggerType; ///< trigger type

    /// Event enumeration
    enum
    {
      EVENT_A1, ///< Event A1: Serving becomes better than absolute threshold.
      EVENT_A2, ///< Event A2: Serving becomes worse than absolute threshold.
      EVENT_A3, ///< Event A3: Neighbour becomes amount of offset better than PCell.
      EVENT_A4, ///< Event A4: Neighbour becomes better than absolute threshold.
      EVENT_A5  ///< Event A5: PCell becomes worse than absolute `threshold1` AND Neighbour becomes better than another absolute `threshold2`.

    } eventId; ///< Choice of E-UTRA event triggered reporting criteria.

    ThresholdEutra threshold1; ///< Threshold for event A1, A2, A4, and A5.
    ThresholdEutra threshold2; ///< Threshold for event A5.

    /// Indicates whether or not the UE shall initiate the measurement reporting procedure when the leaving condition is met for a cell in `cellsTriggeredList`, as specified in 5.5.4.1 of 3GPP TS 36.331.
    bool reportOnLeave;

    /// Offset value for Event A3. An integer between -30 and 30. The actual value is (value * 0.5) dB.
    int8_t a3Offset;

    /// Parameter used within the entry and leave condition of an event triggered reporting condition. The actual value is (value * 0.5) dB.
    uint8_t hysteresis;

    /// Time during which specific criteria for the event needs to be met in order to trigger a measurement report.
    uint16_t timeToTrigger;

    /// the report purpose
    enum report
    {
      REPORT_STRONGEST_CELLS,
      REPORT_CGI
    } purpose; ///< purpose

    /// Trigger type enumeration
    enum
    {
      RSRP, ///< Reference Signal Received Power
      RSRQ ///< Reference Signal Received Quality
    } triggerQuantity; ///< The quantities used to evaluate the triggering condition for the event, see 3GPP TS 36.214.

    /// Report type enumeration
    enum
    {
      SAME_AS_TRIGGER_QUANTITY,
      BOTH ///< Both the RSRP and RSRQ quantities are to be included in the measurement report.
    } reportQuantity; ///< The quantities to be included in the measurement report, always assumed to be BOTH.

    /// Maximum number of cells, excluding the serving cell, to be included in the measurement report.
    uint8_t maxReportCells;

    /// Report interval enumeration
    enum
    {
      MS120,
      MS240,
      MS480,
      MS640,
      MS1024,
      MS2048,
      MS5120,
      MS10240,
      MIN1,
      MIN6,
      MIN12,
      MIN30,
      MIN60,
      SPARE3,
      SPARE2,
      SPARE1
    } reportInterval; ///< Indicates the interval between periodical reports.

    /// Number of measurement reports applicable, always assumed to be infinite.
    uint8_t reportAmount;

    /// Report config eutra function
    ReportConfigEutra ();

  }; // end of struct ReportConfigEutra

  /// MeasObjectToAddMod structure
  struct MeasObjectToAddMod
  {
    uint8_t measObjectId; ///< measure object ID
    MeasObjectEutra measObjectEutra; ///< measure object eutra
  };

  /// ReportConfigToAddMod structure
  struct ReportConfigToAddMod
  {
    uint8_t reportConfigId; ///< report config ID
    ReportConfigEutra reportConfigEutra; ///< report config eutra
  };

  /// MeasIdToAddMod structure
  struct MeasIdToAddMod
  {
    uint8_t measId; ///< measure ID
    uint8_t measObjectId; ///< measure object ID
    uint8_t reportConfigId; ///< report config ID
  };

  /// MeasGapConfig structure
  struct MeasGapConfig
  {
    /// the action type
    enum action
    {
      SETUP, RESET
    } type; ///< action type
    /// the gap offest
    enum gap
    {
      GP0, GP1
    } gapOffsetChoice; ///< gap offset
    uint8_t gapOffsetValue; ///< gap offset value
  };

  /// MobilityStateParameters structure
  struct MobilityStateParameters
  {
    uint8_t tEvaluation; ///< evaluation
    uint8_t tHystNormal; ///< hyst normal
    uint8_t nCellChangeMedium; ///< cell change medium
    uint8_t nCellChangeHigh; ///< cell change high
  };

  /// SpeedStateScaleFactors structure
  struct SpeedStateScaleFactors
  {
    // 25 = oDot25, 50 = oDot5, 75 = oDot75, 100 = lDot0
    uint8_t sfMedium; ///< scale factor medium
    uint8_t sfHigh; ///< scale factor high
  };

  /// SpeedStatePars structure
  struct SpeedStatePars
  {
    /// the action type
    enum action
    {
      SETUP,
      RESET
    } type; ///< action type
    MobilityStateParameters mobilityStateParameters; ///< mobility state parameters
    SpeedStateScaleFactors timeToTriggerSf; ///< time to trigger scale factors
  };

  /// MeasConfig structure
  struct MeasConfig
  {
    std::list<uint8_t> measObjectToRemoveList; ///< measure object to remove list
    std::list<MeasObjectToAddMod> measObjectToAddModList; ///< measure object to add mod list
    std::list<uint8_t> reportConfigToRemoveList; ///< report config to remove list
    std::list<ReportConfigToAddMod> reportConfigToAddModList; ///< report config to add mod list
    std::list<uint8_t> measIdToRemoveList; ///< measure ID to remove list
    std::list<MeasIdToAddMod> measIdToAddModList; ///< measure ID to add mod list
    bool haveQuantityConfig; ///< have quantity config?
    QuantityConfig quantityConfig; ///< quantity config
    bool haveMeasGapConfig; ///< have measure gap config?
    MeasGapConfig measGapConfig; ///< measure gap config
    bool haveSmeasure; ///< have S measure?
    uint8_t sMeasure; ///< S measure
    bool haveSpeedStatePars; ///< have speed state parameters?
    SpeedStatePars speedStatePars; ///< speed state parameters
  };

  /// CarrierFreqEutra structure
  struct CarrierFreqEutra
  {
    uint32_t dlCarrierFreq; ///< DL carrier frequency
    uint32_t ulCarrierFreq; ///< UL carrier frequency
  };

  /// CarrierBandwidthEutra structure
  struct CarrierBandwidthEutra
  {
    uint8_t dlBandwidth; ///< DL bandwidth
    uint8_t ulBandwidth; ///< UL bandwidth
  };

  /// RachConfigDedicated structure
  struct RachConfigDedicated
  {
    uint8_t raPreambleIndex; ///< RA preamble index
    uint8_t raPrachMaskIndex; ///< RA PRACH mask index
  };

  /// MobilityControlInfo structure
  struct MobilityControlInfo
  {
    uint16_t targetPhysCellId; ///< target Phy cell ID
    bool haveCarrierFreq; ///< have carrier frequency?
    CarrierFreqEutra carrierFreq; ///< carrier frequency
    bool haveCarrierBandwidth; ///< have carrier bandwidth?
    CarrierBandwidthEutra carrierBandwidth; ///< carrier bandwidth
    uint16_t newUeIdentity; ///< new UE identity
    RadioResourceConfigCommon radioResourceConfigCommon; ///< radio resource config common
    bool haveRachConfigDedicated; ///< Have RACH config dedicated?
    RachConfigDedicated rachConfigDedicated; ///< RACH config dedicated
  };

  /// ReestabUeIdentity structure
  struct ReestabUeIdentity
  {
    uint16_t cRnti; ///< RNTI
    uint16_t physCellId; ///< Phy cell ID
  };

  /// ReestablishmentCause enumeration
  enum ReestablishmentCause
  {
    RECONFIGURATION_FAILURE,
    HANDOVER_FAILURE,
    OTHER_FAILURE
  };

  /// MasterInformationBlock structure
  struct MasterInformationBlock
  {
    uint8_t dlBandwidth; ///< DL bandwidth
    uint8_t systemFrameNumber; ///< system frame number
  };

  /// SystemInformationBlockType1 structure
  struct SystemInformationBlockType1
  {
    CellAccessRelatedInfo cellAccessRelatedInfo; ///< cell access related info
    CellSelectionInfo cellSelectionInfo; ///< cell selection info
  };

  /// SystemInformationBlockType2 structure
  struct SystemInformationBlockType2
  {
    RadioResourceConfigCommonSib radioResourceConfigCommon; ///< radio resource config common
    FreqInfo freqInfo; ///< frequency info
  };

  /// SystemInformation structure
  struct SystemInformation
  {
    bool haveSib2; ///< have SIB2?
    SystemInformationBlockType2 sib2; ///< SIB2
  };

  struct pagingRecordList
  {
    uint64_t ue_id;
    uint8_t cn_domain;
    bool systemInfoModified;
    bool etwsIndication;
  };

  struct PagingInformation
  {
    bool pagingRecordListExist;
    std::list<pagingRecordList> pagingRecord;
  };

  /// AsConfig structure
  struct AsConfig
  {
    MeasConfig sourceMeasConfig; ///< source measure config
    RadioResourceConfigDedicated sourceRadioResourceConfig; ///< source radio resource config
    uint16_t sourceUeIdentity; ///< source UE identity
    MasterInformationBlock sourceMasterInformationBlock; ///< source master information block
    SystemInformationBlockType1 sourceSystemInformationBlockType1; ///< source system information block type 1
    SystemInformationBlockType2 sourceSystemInformationBlockType2; ///< source system information block type 2
    uint32_t sourceDlCarrierFreq; ///< source DL carrier frequency
  };

  /// CgiInfo structure
  struct CgiInfo
  {
    uint32_t plmnIdentity; ///< PLMN identity
    uint32_t cellIdentity; ///< cell identity
    uint16_t trackingAreaCode; ///< tracking area code
    std::list<uint32_t> plmnIdentityList; ///< PLMN identity list
  };

  /// MeasResultEutra structure
  struct MeasResultEutra
  {
    uint16_t physCellId; ///< Phy cell ID
    bool haveCgiInfo; ///< have CGI info?
    CgiInfo cgiInfo; ///< CGI info
    bool haveRsrpResult; ///< have RSRP result
    uint8_t rsrpResult; ///< RSRP result
    bool haveRsrqResult; ///< have RSRQ result?
    uint8_t rsrqResult; ///< RSRQ result
  };

  /// MeasResultScell structure
  struct MeasResultScell
  {
    uint16_t servFreqId; ///< service frequency ID
    bool haveRsrpResult; ///< have RSRP result?
    uint8_t rsrpResult; ///< the RSRP result
    bool haveRsrqResult; ///< have RSRQ result?
    uint8_t rsrqResult; ///< the RSRQ result
  };

  /// MeasResultBestNeighCell structure
  struct MeasResultBestNeighCell
  {
    uint16_t servFreqId; ///< service frequency ID
    uint16_t physCellId; ///< physical cell ID
    bool haveRsrpResult; ///< have RSRP result?
    uint8_t rsrpResult; ///< the RSRP result
    bool haveRsrqResult; ///< have RSRQ result?
    uint8_t rsrqResult; ///< the RSRQ result
  };

  /// MeasResultServFreqList
  struct MeasResultServFreqList
  {
    bool haveMeasurementResultsServingSCells; ///< have measure results serving Scells
    std::list<MeasResultScell> measResultScell; ///< measure results Scells
    bool haveMeasurementResultsNeighCell; ///< always false since not implemented
    std::list<MeasResultBestNeighCell> measResultBestNeighCell; ///< measure result best neighbor cell
  };

  /// MeasResults structure
  struct MeasResults
  {
    uint8_t measId; ///< measure ID
    uint8_t rsrpResult; ///< RSRP result
    uint8_t rsrqResult; ///< RSRQ result
    bool haveMeasResultNeighCells; ///< have measure result neighbor cells
    std::list<MeasResultEutra> measResultListEutra; ///< measure result list eutra
    bool haveScellsMeas; ///< has SCells measure
    MeasResultServFreqList measScellResultList; ///< measure SCell result list
  };

  // Messages

  /// RrcConnectionRequest structure
  struct RrcConnectionRequest
  {
    uint64_t ueIdentity; ///< UE identity
    bool isMc;
  };

  /// RrcConnectionSetup structure
  struct RrcConnectionSetup
  {
    uint8_t rrcTransactionIdentifier; ///< RRC transaction identifier
    RadioResourceConfigDedicated radioResourceConfigDedicated; ///< radio resource config dedicated
  };

  /// RrcConnectionSetupCompleted structure
  struct RrcConnectionSetupCompleted
  {
    uint8_t rrcTransactionIdentifier; ///< RRC transaction identifier
  };


  /// CellIdentification structure
  struct CellIdentification
  {
    uint32_t physCellId; ///< physical cell ID
    uint32_t dlCarrierFreq; ///<  ARFCN - valueEUTRA
  };

  /// AntennaInfoCommon structure
  struct AntennaInfoCommon
  {
    uint16_t antennaPortsCount; ///< antenna ports count
  };

  /// UlPowerControlCommonSCell structure
  struct UlPowerControlCommonSCell
  {
    uint16_t alpha; ///< alpha value
  };

  /// PrachConfigSCell structure
  struct PrachConfigSCell
  {
    uint16_t index; ///< the index
  };

  /// NonUlConfiguration structure
  struct NonUlConfiguration
  {
    // 3GPP TS 36.311 v.11.10 R11 pag.220
    /// 1: Cell characteristics
    uint16_t dlBandwidth;
    /// 2: Physical configuration, general antennaInfoCommon-r10
    AntennaInfoCommon antennaInfoCommon;
    // 3: Physical configuration, control phich-Config-r10
    // Not Implemented
    /// 4: Physical configuration, physical channels pdsch-ConfigCommon-r10
    PdschConfigCommon pdschConfigCommon;
    // 5: tdd-Config-r10
    //Not Implemented
  };

  /// UlConfiguration structure
  struct UlConfiguration
  {
    FreqInfo ulFreqInfo; ///< UL frequency info
    UlPowerControlCommonSCell ulPowerControlCommonSCell; ///< 3GPP TS 36.331 v.11.10 R11 pag.223
    SoundingRsUlConfigCommon soundingRsUlConfigCommon; ///< sounding RS UL config common
    PrachConfigSCell prachConfigSCell; ///< PRACH config SCell
    //PushConfigCommon pushConfigCommon; //NOT IMPLEMENTED!
  };

  /// AntennaInfoUl structure
  struct AntennaInfoUl
  {
    uint8_t transmissionMode; ///< transmission mode
  };

  /// PuschConfigDedicatedSCell structure
  struct PuschConfigDedicatedSCell
  {
    /// 3GPP TS 36.331 v.11.10 R11 page 216
    uint16_t nPuschIdentity;
  };

  /// UlPowerControlDedicatedSCell structure
  struct UlPowerControlDedicatedSCell
  {
    /// 3GPP TS 36.331 v.11.10 R11 page 234
    uint16_t pSrsOffset;
  };

  /// PhysicalConfigDedicatedSCell structure
  struct PhysicalConfigDedicatedSCell
  {
    // Non-Ul Configuration
    bool haveNonUlConfiguration; ///< have non UL configuration?
    bool haveAntennaInfoDedicated; ///< have antenna info dedicated?
    AntennaInfoDedicated antennaInfo; ///< antenna info dedicated
    bool crossCarrierSchedulingConfig; ///< currently implemented as boolean variable --> implementing crossCarrierScheduling is out of the scope of this GSoC proposal
    bool havePdschConfigDedicated; ///< have PDSCH config dedicated?
    PdschConfigDedicated pdschConfigDedicated; ///< PDSCH config dedicated

    // Ul Configuration
    bool haveUlConfiguration; ///< have UL configuration?
    bool haveAntennaInfoUlDedicated; ///< have antenna info UL dedicated?
    AntennaInfoDedicated antennaInfoUl; ///< antenna info UL
    PuschConfigDedicatedSCell pushConfigDedicatedSCell; ///< PUSCH config dedicated SCell
    UlPowerControlDedicatedSCell  ulPowerControlDedicatedSCell; ///< UL power control dedicated SCell
    bool haveSoundingRsUlConfigDedicated; ///< have sounding RS UL config dedicated?
    SoundingRsUlConfigDedicated soundingRsUlConfigDedicated; ///< sounding RS UL config dedicated
  };

  /// RadioResourceConfigCommonSCell
  struct RadioResourceConfigCommonSCell
  {
    bool haveNonUlConfiguration; ///< have non UL configuration?
    NonUlConfiguration nonUlConfiguration; ///< non UL configuration
    bool haveUlConfiguration; ///< have UL configuration
    UlConfiguration ulConfiguration; ///< UL configuration
  };

  /// RadioResourceConfigDedicatedSCell structure
  struct RadioResourceConfigDedicatedSCell
  {
    PhysicalConfigDedicatedSCell physicalConfigDedicatedSCell; ///< physical config dedicated SCell
  };

  /// SCellToAddMod structure
  struct SCellToAddMod
  {
    uint32_t sCellIndex; ///< SCell index
    CellIdentification cellIdentification; ///< cell identification
    RadioResourceConfigCommonSCell radioResourceConfigCommonSCell; ///< radio resource config common SCell
    bool haveRadioResourceConfigDedicatedSCell; ///< have radio resource config dedicated SCell?
    RadioResourceConfigDedicatedSCell radioResourceConfigDedicateSCell; ///< radio resource config dedicated SCell
  };

  /// NonCriticalExtensionConfiguration structure
  struct NonCriticalExtensionConfiguration
  {
    std::list<SCellToAddMod> sCellsToAddModList; ///< SCell to add mod list
    std::list<uint32_t> sCellToReleaseList; ///< SCell to release list
  };

  /// RrcConnectionReconfiguration structure
  struct RrcConnectionReconfiguration
  {
    uint8_t rrcTransactionIdentifier; ///< RRC transaction identifier
    bool haveMeasConfig; ///< have measure config
    MeasConfig measConfig; ///< measure config
    bool haveMobilityControlInfo; ///< have mobility control info
    MobilityControlInfo mobilityControlInfo; ///< mobility control info
    bool haveRadioResourceConfigDedicated; ///< have radio resource config dedicated
    RadioResourceConfigDedicated radioResourceConfigDedicated; ///< radio resource config dedicated
    bool haveNonCriticalExtension; ///< have critical extension?
    /// 3GPP TS 36.331 v.11.10 R11 Sec. 6.2.2 pag. 147 (also known as ETSI TS 136 331 v.11.10 Feb-2015)
    NonCriticalExtensionConfiguration nonCriticalExtension;
 };

  /// RrcConnectionReconfigurationCompleted structure
  struct RrcConnectionReconfigurationCompleted
  {
    uint8_t rrcTransactionIdentifier; ///< RRC transaction identifier
  };


  /// RrcConnectionReestablishmentRequest structure
  struct RrcConnectionReestablishmentRequest
  {
    ReestabUeIdentity ueIdentity; ///< UE identity
    ReestablishmentCause reestablishmentCause; ///< reestablishment cause
  };

  /// RrcConnectionReestablishment structure
  struct RrcConnectionReestablishment
  {
    uint8_t rrcTransactionIdentifier; ///< RRC transaction identifier
    RadioResourceConfigDedicated radioResourceConfigDedicated; ///< radio resource config dedicated
  };

  /// RrcConnectionReestablishmentComplete structure
  struct RrcConnectionReestablishmentComplete
  {
    uint8_t rrcTransactionIdentifier; ///< RRC transaction identifier
  };

  /// RrcConnectionReestablishmentReject structure
  struct RrcConnectionReestablishmentReject
  {
  };

  /// RrcConnectionRelease structure
  struct RrcConnectionRelease
  {
    uint8_t rrcTransactionIdentifier; ///< RRC transaction identifier
  };

  struct RrcConnectionSwitch
  {
    uint8_t rrcTransactionIdentifier;
    std::vector<uint8_t> drbidList;
    uint16_t useMmWaveConnection;
  };

  /// RrcConnectionReject structure
  struct RrcConnectionReject
  {
    uint8_t waitTime; ///< wait time
  };

  /// HandoverPreparationInfo structure
  struct HandoverPreparationInfo
  {
    AsConfig asConfig; ///< AS config
  };

  /// MeasurementReport structure
  struct MeasurementReport
  {
    MeasResults measResults; ///< measure results
  };

};



/**
 * \brief Part of the RRC protocol. This Service Access Point (SAP) is used by
 *        the UE RRC to send messages to the eNB. Each method defined in this
 *        class corresponds to the transmission of a message that is defined in
 *        Section 6.2.2 of TS 36.331.
 */
class LteUeRrcSapUser : public LteRrcSap
{
public:
  /// SetupParameters structure
  struct SetupParameters
  {
    LteRlcSapProvider* srb0SapProvider; ///< SRB0 SAP provider
    LtePdcpSapProvider* srb1SapProvider; ///< SRB1 SAP provider
  };

  /**
   * \brief Setup function
   * \param params the setup parameters
   */
  virtual void Setup (SetupParameters params) = 0;

  /**
   * \brief Send an _RRCConnectionRequest message to the serving eNodeB
   *        during an RRC connection establishment procedure
   *        (Section 5.3.3 of TS 36.331).
   * \param msg the message
   */
  virtual void SendRrcConnectionRequest (RrcConnectionRequest msg) = 0;

  /**
   * \brief Send an _RRCConnectionSetupComplete_ message to the serving eNodeB
   *        during an RRC connection establishment procedure
   *        (Section 5.3.3 of TS 36.331).
   * \param msg the message
   */
  virtual void SendRrcConnectionSetupCompleted (RrcConnectionSetupCompleted msg) = 0;

  /**
   * \brief Send an _RRCConnectionReconfigurationComplete_ message to the serving eNodeB
   *        during an RRC connection reconfiguration procedure
   *        (Section 5.3.5 of TS 36.331).
   * \param msg the message
   */
  virtual void SendRrcConnectionReconfigurationCompleted (RrcConnectionReconfigurationCompleted msg) = 0;

  /**
   * \brief Send an _RRCConnectionReestablishmentRequest_ message to the serving eNodeB
   *        during an RRC connection re-establishment procedure
   *        (Section 5.3.7 of TS 36.331).
   * \param msg the message
   */
  virtual void SendRrcConnectionReestablishmentRequest (RrcConnectionReestablishmentRequest msg) = 0;

  /**
   * \brief Send an _RRCConnectionReestablishmentComplete_ message to the serving eNodeB
   *        during an RRC connection re-establishment procedure
   *        (Section 5.3.7 of TS 36.331).
   * \param msg the message
   */
  virtual void SendRrcConnectionReestablishmentComplete (RrcConnectionReestablishmentComplete msg) = 0;

  /**
   * \brief Send a _MeasurementReport_ message to the serving eNodeB
   *        during a measurement reporting procedure
   *        (Section 5.5.5 of TS 36.331).
   * \param msg the message
   */
  virtual void SendMeasurementReport (MeasurementReport msg) = 0;

  virtual void SendNotifySecondaryCellConnected (uint16_t mmWaveRnti, uint16_t mmWaveCellId) = 0;

};


/**
 * \brief Part of the RRC protocol. This Service Access Point (SAP) is used to
 *        let the UE RRC receive a message from the eNB RRC. Each method defined
 *        in this class corresponds to the reception of a message that is
 *        defined in Section 6.2.2 of TS 36.331.
 */
class LteUeRrcSapProvider : public LteRrcSap
{
public:
  /// CompleteSetupParameters structure
  struct CompleteSetupParameters
  {
    LteRlcSapUser* srb0SapUser; ///< SRB0 SAP user
    LtePdcpSapUser* srb1SapUser; ///< SRB1 SAP user
  };

  /**
   * \brief Complete setup function
   * \param params the complete setup parameters
   */
  virtual void CompleteSetup (CompleteSetupParameters params) = 0;

  /**
   * \brief Receive a _SystemInformation_ message from the serving eNodeB
   *        during a system information acquisition procedure
   *        (Section 5.2.2 of TS 36.331).
   * \param msg the message
   */
  virtual void RecvSystemInformation (SystemInformation msg) = 0;

  /**
   * \brief Receive an _RRCConnectionSetup_ message from the serving eNodeB
   *        during an RRC connection establishment procedure
   *        (Section 5.3.3 of TS 36.331).
   * \param msg the message
   */
  virtual void RecvRrcConnectionSetup (RrcConnectionSetup msg) = 0;

  /**
   * \brief Receive an _RRCConnectionReconfiguration_ message from the serving eNodeB
   *        during an RRC connection reconfiguration procedure
   *        (Section 5.3.5 of TS 36.331).
   * \param msg the message
   */
  virtual void RecvRrcConnectionReconfiguration (RrcConnectionReconfiguration msg) = 0;

  /**
   * \brief Receive an _RRCConnectionReestablishment_ message from the serving eNodeB
   *        during an RRC connection re-establishment procedure
   *        (Section 5.3.7 of TS 36.331).
   * \param msg the message
   */
  virtual void RecvRrcConnectionReestablishment (RrcConnectionReestablishment msg) = 0;

  /**
   * \brief Receive an _RRCConnectionReestablishmentReject_ message from the serving eNodeB
   *        during an RRC connection re-establishment procedure
   *        (Section 5.3.7 of TS 36.331).
   * \param msg the message
   */
  virtual void RecvRrcConnectionReestablishmentReject (RrcConnectionReestablishmentReject msg) = 0;

  /**
   * \brief Receive an _RRCConnectionRelease_ message from the serving eNodeB
   *        during an RRC connection release procedure
   *        (Section 5.3.8 of TS 36.331).
   * \param msg the message
   */
  virtual void RecvRrcConnectionRelease (RrcConnectionRelease msg) = 0;

  virtual void RecvRrcPagingDirect () = 0;
  /**
   * \brief Receive an _RRCConnectionReject_ message from the serving eNodeB
   *        during an RRC connection establishment procedure
   *        (Section 5.3.3 of TS 36.331).
   * \param msg the message
   */
  virtual void RecvRrcConnectionReject (RrcConnectionReject msg) = 0;

  /**
   * \brief Receive an _RRCConnectionSwitch_ message from the serving eNodeB
   *        to switch data connection from LTE to MmWave or viceversa
   *        (added to support MC functionalities)
   * \param msg the message
   */
  virtual void RecvRrcConnectionSwitch (RrcConnectionSwitch msg) = 0;

  /**
   * \brief Receive an _RRCConnectToMmWave_ message from the serving eNodeB
   *        during an RRC connection establishment procedure
   *        (added to support MC functionalities).
   * \param msg the message
   */
  virtual void RecvRrcConnectToMmWave (uint16_t mmWaveCellId) = 0;

};


/**
 * \brief Part of the RRC protocol. This Service Access Point (SAP) is used by
 *        the eNB RRC to send messages to the UE RRC.  Each method defined in
 *        this class corresponds to the transmission of a message that is
 *        defined in Section 6.2.2 of TS 36.331.
 */
class LteEnbRrcSapUser : public LteRrcSap
{
public:
  /// SetupUeParameters structure
  struct SetupUeParameters
  {
    LteRlcSapProvider* srb0SapProvider; ///< SRB0 SAP provider
    LtePdcpSapProvider* srb1SapProvider; ///< SRB1 SAP provider
  };

  /**
   * \brief Setup UE function
   * \param rnti the RNTI
   * \param params the setup UE parameters
   */
  virtual void SetupUe (uint16_t rnti, SetupUeParameters params) = 0;
  /**
   * \brief Remove UE function
   * \param rnti the RNTI
   */
  virtual void RemoveUe (uint16_t rnti) = 0;

  /**
   * \brief Send a _SystemInformation_ message to all attached UEs
   *        during a system information acquisition procedure
   *        (Section 5.2.2 of TS 36.331).
   * \param cellId cell ID
   * \param msg the message
   */
  virtual void SendSystemInformation (uint16_t cellId, SystemInformation msg) = 0;

  /**
   * \brief Send an _RRCConnectionSetup_ message to a UE
   *        during an RRC connection establishment procedure
   *        (Section 5.3.3 of TS 36.331).
   * \param rnti the RNTI of the destination UE
   * \param msg the message
   */
  virtual void SendRrcConnectionSetup (uint16_t rnti, RrcConnectionSetup msg) = 0;

  /**
   * \brief Send an _RRCConnectionReconfiguration_ message to a UE
   *        during an RRC connection reconfiguration procedure
   *        (Section 5.3.5 of TS 36.331).
   * \param rnti the RNTI of the destination UE
   * \param msg the message
   */
  virtual void SendRrcConnectionReconfiguration (uint16_t rnti, RrcConnectionReconfiguration msg) = 0;

  /**
   * \brief Send an _RRCConnectionReestablishment_ message to a UE
   *        during an RRC connection re-establishment procedure
   *        (Section 5.3.7 of TS 36.331).
   * \param rnti the RNTI of the destination UE
   * \param msg the message
   */
  virtual void SendRrcConnectionReestablishment (uint16_t rnti, RrcConnectionReestablishment msg) = 0;

  /**
   * \brief Send an _RRCConnectionReestablishmentReject_ message to a UE
   *        during an RRC connection re-establishment procedure
   *        (Section 5.3.7 of TS 36.331).
   * \param rnti the RNTI of the destination UE
   * \param msg the message
   */
  virtual void SendRrcConnectionReestablishmentReject (uint16_t rnti, RrcConnectionReestablishmentReject msg) = 0;

  /**
   * \brief Send an _RRCConnectionRelease_ message to a UE
   *        during an RRC connection release procedure
   *        (Section 5.3.8 of TS 36.331).
   * \param rnti the RNTI of the destination UE
   * \param msg the message
   */
  virtual void SendRrcConnectionRelease (uint16_t rnti, RrcConnectionRelease msg) = 0;

  virtual void SendRrcPagingDirect (uint16_t rnti) = 0;
  /**
   * \brief Send an _RRCConnectionReject_ message to a UE
   *        during an RRC connection establishment procedure
   *        (Section 5.3.3 of TS 36.331).
   * \param rnti the RNTI of the destination UE
   * \param msg the message
   */
  virtual void SendRrcConnectionReject (uint16_t rnti, RrcConnectionReject msg) = 0;

  /**
   * \brief Send an _RRCConnectionSwitch_ message to a UE
   *        (added to support MC functionalities).
   * \param rnti the RNTI of the destination UE
   * \param msg the message
   */
  virtual void SendRrcConnectionSwitch (uint16_t rnti, RrcConnectionSwitch msg) = 0;

  /**
   * \brief Send an _RRCConnectToMmWave_ message to a UE
   *        during an RRC connection establishment procedure
   *        (added to support MC functionalities).
   * \param rnti the RNTI of the destination UE
   * \param mmWaveCellId the cellId to which connect
   */
  virtual void SendRrcConnectToMmWave (uint16_t rnti, uint16_t mmWaveCellId) = 0;

  /**
   * \brief Encode handover prepration information
   * \param msg HandoverPreparationInfo
   * \returns the packet
   */
  virtual Ptr<Packet> EncodeHandoverPreparationInformation (HandoverPreparationInfo msg) = 0;
  /**
   * \brief Decode handover prepration information
   * \param p the packet
   * \returns HandoverPreparationInfo
   */
  virtual HandoverPreparationInfo DecodeHandoverPreparationInformation (Ptr<Packet> p) = 0;
  /**
   * \brief Encode handover command
   * \param msg RrcConnectionReconfiguration
   * \returns the packet
   */
  virtual Ptr<Packet> EncodeHandoverCommand (RrcConnectionReconfiguration msg) = 0;
  /**
   * \brief Decode handover command
   * \param p the packet
   * \returns RrcConnectionReconfiguration
   */
  virtual RrcConnectionReconfiguration DecodeHandoverCommand (Ptr<Packet> p) = 0;

};


/**
 * \brief Part of the RRC protocol. This Service Access Point (SAP) is used to
 *        let the eNB RRC receive a message from a UE RRC.  Each method defined
 *        in this class corresponds to the reception of a message that is
 *        defined in Section 6.2.2 of TS 36.331.
 */
class LteEnbRrcSapProvider : public LteRrcSap
{
public:
  /// CompleteSetupUeParameters structure
  struct CompleteSetupUeParameters
  {
    LteRlcSapUser* srb0SapUser; ///< SRB0 SAP user
    LtePdcpSapUser* srb1SapUser; ///< SRB1 SAP user
  };

  /**
   * \brief Complete setup UE function
   * \param rnti the RNTI of UE which sent the message
   * \param params CompleteSetupUeParameters
   */
  virtual void CompleteSetupUe (uint16_t rnti, CompleteSetupUeParameters params) = 0;

  /**
   * \brief Receive an _RRCConnectionRequest_ message from a UE
   *        during an RRC connection establishment procedure
   *        (Section 5.3.3 of TS 36.331).
   * \param rnti the RNTI of UE which sent the message
   * \param msg the message
   */
  virtual void RecvRrcConnectionRequest (uint16_t rnti,
                                         RrcConnectionRequest msg) = 0;

  /**
   * \brief Receive an _RRCConnectionSetupComplete_ message from a UE
   *        during an RRC connection establishment procedure
   *        (Section 5.3.3 of TS 36.331).
   * \param rnti the RNTI of UE which sent the message
   * \param msg the message
   */
  virtual void RecvRrcConnectionSetupCompleted (uint16_t rnti,
                                                RrcConnectionSetupCompleted msg) = 0;

  /**
   * \brief Receive an _RRCConnectionReconfigurationComplete_ message from a UE
   *        during an RRC connection reconfiguration procedure
   *        (Section 5.3.5 of TS 36.331).
   * \param rnti the RNTI of UE which sent the message
   * \param msg the message
   */
  virtual void RecvRrcConnectionReconfigurationCompleted (uint16_t rnti,
                                                          RrcConnectionReconfigurationCompleted msg) = 0;

  /**
   * \brief Receive an _RRCConnectionReestablishmentRequest_ message from a UE
   *        during an RRC connection re-establishment procedure
   *        (Section 5.3.7 of TS 36.331).
   * \param rnti the RNTI of UE which sent the message
   * \param msg the message
   */
  virtual void RecvRrcConnectionReestablishmentRequest (uint16_t rnti,
                                                        RrcConnectionReestablishmentRequest msg) = 0;

  /**
   * \brief Receive an _RRCConnectionReestablishmentComplete_ message from a UE
   *        during an RRC connection re-establishment procedure
   *        (Section 5.3.7 of TS 36.331).
   * \param rnti the RNTI of UE which sent the message
   * \param msg the message
   */
  virtual void RecvRrcConnectionReestablishmentComplete (uint16_t rnti,
                                                         RrcConnectionReestablishmentComplete msg) = 0;

  /**
   * \brief Receive a _MeasurementReport_ message from a UE
   *        during a measurement reporting procedure
   *        (Section 5.5.5 of TS 36.331).
   * \param rnti the RNTI of UE which sent the message
   * \param msg the message
   */
  virtual void RecvMeasurementReport (uint16_t rnti, MeasurementReport msg) = 0;

  virtual void RecvRrcSecondaryCellInitialAccessSuccessful (uint16_t rnti, uint16_t mmWaveRnti, uint16_t mmWaveCellId) = 0;
};






////////////////////////////////////
//   templates
////////////////////////////////////


/**
 * Template for the implementation of the LteUeRrcSapUser as a member
 * of an owner class of type C to which all methods are forwarded
 *
 */
template <class C>
class MemberLteUeRrcSapUser : public LteUeRrcSapUser
{
public:
  /**
   * Constructor
   *
   * \param owner the owner class
   */
  MemberLteUeRrcSapUser (C* owner);

  // inherited from LteUeRrcSapUser
  virtual void Setup (SetupParameters params);
  virtual void SendRrcConnectionRequest (RrcConnectionRequest msg);
  virtual void SendRrcConnectionSetupCompleted (RrcConnectionSetupCompleted msg);
  virtual void SendRrcConnectionReconfigurationCompleted (RrcConnectionReconfigurationCompleted msg);
  virtual void SendRrcConnectionReestablishmentRequest (RrcConnectionReestablishmentRequest msg);
  virtual void SendRrcConnectionReestablishmentComplete (RrcConnectionReestablishmentComplete msg);
  virtual void SendMeasurementReport (MeasurementReport msg);
  virtual void SendNotifySecondaryCellConnected (uint16_t mmWaveRnti, uint16_t mmWaveCellId);

private:
  MemberLteUeRrcSapUser ();
  C* m_owner; ///< the owner class
};

template <class C>
MemberLteUeRrcSapUser<C>::MemberLteUeRrcSapUser (C* owner)
  : m_owner (owner)
{
}

template <class C>
MemberLteUeRrcSapUser<C>::MemberLteUeRrcSapUser ()
{
}

template <class C>
void
MemberLteUeRrcSapUser<C>::Setup (SetupParameters params)
{
  m_owner->DoSetup (params);
}

template <class C>
void
MemberLteUeRrcSapUser<C>::SendRrcConnectionRequest (RrcConnectionRequest msg)
{
  m_owner->DoSendRrcConnectionRequest (msg);
}

template <class C>
void
MemberLteUeRrcSapUser<C>::SendRrcConnectionSetupCompleted (RrcConnectionSetupCompleted msg)
{
  m_owner->DoSendRrcConnectionSetupCompleted (msg);
}

template <class C>
void
MemberLteUeRrcSapUser<C>::SendRrcConnectionReconfigurationCompleted (RrcConnectionReconfigurationCompleted msg)
{
  m_owner->DoSendRrcConnectionReconfigurationCompleted (msg);
}

template <class C>
void
MemberLteUeRrcSapUser<C>::SendRrcConnectionReestablishmentRequest (RrcConnectionReestablishmentRequest msg)
{
  m_owner->DoSendRrcConnectionReestablishmentRequest (msg);
}

template <class C>
void
MemberLteUeRrcSapUser<C>::SendRrcConnectionReestablishmentComplete (RrcConnectionReestablishmentComplete msg)
{
  m_owner->DoSendRrcConnectionReestablishmentComplete (msg);
}

template <class C>
void
MemberLteUeRrcSapUser<C>::SendMeasurementReport (MeasurementReport msg)
{
  m_owner->DoSendMeasurementReport (msg);
}

template <class C>
void
MemberLteUeRrcSapUser<C>::SendNotifySecondaryCellConnected (uint16_t mmWaveRnti, uint16_t mmWaveCellId)
{
  m_owner->DoSendNotifySecondaryCellConnected (mmWaveRnti, mmWaveCellId);
}

/**
 * Template for the implementation of the LteUeRrcSapProvider as a member
 * of an owner class of type C to which all methods are forwarded
 *
 */
template <class C>
class MemberLteUeRrcSapProvider : public LteUeRrcSapProvider
{
public:
  /**
   * Constructor
   *
   * \param owner the owner class
   */
  MemberLteUeRrcSapProvider (C* owner);

  // methods inherited from LteUeRrcSapProvider go here
  virtual void CompleteSetup (CompleteSetupParameters params);
  virtual void RecvSystemInformation (SystemInformation msg);
  virtual void RecvRrcConnectionSetup (RrcConnectionSetup msg);
  virtual void RecvRrcConnectionReconfiguration (RrcConnectionReconfiguration msg);
  virtual void RecvRrcConnectionReestablishment (RrcConnectionReestablishment msg);
  virtual void RecvRrcConnectionReestablishmentReject (RrcConnectionReestablishmentReject msg);
  virtual void RecvRrcConnectionRelease (RrcConnectionRelease msg);
  virtual void RecvRrcPagingDirect ();
  virtual void RecvRrcConnectionReject (RrcConnectionReject msg);
  virtual void RecvRrcConnectToMmWave (uint16_t mmWaveCellId);
  virtual void RecvRrcConnectionSwitch (RrcConnectionSwitch msg);

private:
  MemberLteUeRrcSapProvider ();
  C* m_owner; ///< the owner class
};

template <class C>
MemberLteUeRrcSapProvider<C>::MemberLteUeRrcSapProvider (C* owner)
  : m_owner (owner)
{
}

template <class C>
MemberLteUeRrcSapProvider<C>::MemberLteUeRrcSapProvider ()
{
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::CompleteSetup (CompleteSetupParameters params)
{
  m_owner->DoCompleteSetup (params);
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvSystemInformation (SystemInformation msg)
{
  Simulator::ScheduleNow (&C::DoRecvSystemInformation, m_owner, msg);
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvRrcConnectionSetup (RrcConnectionSetup msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionSetup, m_owner, msg);
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvRrcConnectionReconfiguration (RrcConnectionReconfiguration msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionReconfiguration, m_owner, msg);
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvRrcConnectionReestablishment (RrcConnectionReestablishment msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionReestablishment, m_owner, msg);
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvRrcConnectionReestablishmentReject (RrcConnectionReestablishmentReject msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionReestablishmentReject, m_owner, msg);
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvRrcConnectionRelease (RrcConnectionRelease msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionRelease, m_owner, msg);
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvRrcPagingDirect ()
{
  Simulator::ScheduleNow (&C::DoRecvRrcPagingDirect, m_owner);
}


template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvRrcConnectionReject (RrcConnectionReject msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionReject, m_owner, msg);
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvRrcConnectToMmWave (uint16_t mmWaveCellId)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectToMmWave, m_owner, mmWaveCellId);
}

template <class C>
void
MemberLteUeRrcSapProvider<C>::RecvRrcConnectionSwitch (RrcConnectionSwitch msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionSwitch, m_owner, msg);
}

/**
 * Template for the implementation of the LteEnbRrcSapUser as a member
 * of an owner class of type C to which all methods are forwarded
 *
 */
template <class C>
class MemberLteEnbRrcSapUser : public LteEnbRrcSapUser
{
public:
  /**
   * Constructor
   *
   * \param owner the owner class
   */
  MemberLteEnbRrcSapUser (C* owner);

  // inherited from LteEnbRrcSapUser

  virtual void SetupUe (uint16_t rnti, SetupUeParameters params);
  virtual void RemoveUe (uint16_t rnti);
  //TODO remove the following declaration
  //virtual void SendSystemInformation (SystemInformation msg);
  virtual void SendSystemInformation (uint16_t cellId, SystemInformation msg);
  virtual void SendRrcConnectionSetup (uint16_t rnti, RrcConnectionSetup msg);
  virtual void SendRrcConnectionReconfiguration (uint16_t rnti, RrcConnectionReconfiguration msg);
  virtual void SendRrcConnectionReestablishment (uint16_t rnti, RrcConnectionReestablishment msg);
  virtual void SendRrcConnectionReestablishmentReject (uint16_t rnti, RrcConnectionReestablishmentReject msg);
  virtual void SendRrcConnectionRelease (uint16_t rnti, RrcConnectionRelease msg);
  virtual void SendRrcPagingDirect(uint16_t rnti);
  virtual void SendRrcConnectionReject (uint16_t rnti, RrcConnectionReject msg);
  virtual void SendRrcConnectionSwitch (uint16_t rnti, RrcConnectionSwitch msg);
  virtual void SendRrcConnectToMmWave (uint16_t rnti, uint16_t mmWaveCellId);
  virtual Ptr<Packet> EncodeHandoverPreparationInformation (HandoverPreparationInfo msg);
  virtual HandoverPreparationInfo DecodeHandoverPreparationInformation (Ptr<Packet> p);
  virtual Ptr<Packet> EncodeHandoverCommand (RrcConnectionReconfiguration msg);
  virtual RrcConnectionReconfiguration DecodeHandoverCommand (Ptr<Packet> p);

private:
  MemberLteEnbRrcSapUser ();
  C* m_owner; ///< the owner class
};

template <class C>
MemberLteEnbRrcSapUser<C>::MemberLteEnbRrcSapUser (C* owner)
  : m_owner (owner)
{
}

template <class C>
MemberLteEnbRrcSapUser<C>::MemberLteEnbRrcSapUser ()
{
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SetupUe (uint16_t rnti, SetupUeParameters params)
{
  m_owner->DoSetupUe (rnti, params);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::RemoveUe (uint16_t rnti)
{
  m_owner->DoRemoveUe (rnti);
}

//TODO REMOVE THIS FUNCTION
/*
template <class C>
void
MemberLteEnbRrcSapUser<C>::SendSystemInformation (SystemInformation msg)
{
  m_owner->DoSendSystemInformation (msg);
}*/

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendSystemInformation (uint16_t cellId, SystemInformation msg)
{
  m_owner->DoSendSystemInformation (cellId, msg);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendRrcConnectionSetup (uint16_t rnti, RrcConnectionSetup msg)
{
  m_owner->DoSendRrcConnectionSetup (rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendRrcConnectionReconfiguration (uint16_t rnti, RrcConnectionReconfiguration msg)
{
  m_owner->DoSendRrcConnectionReconfiguration (rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendRrcConnectionReestablishment (uint16_t rnti, RrcConnectionReestablishment msg)
{
  m_owner->DoSendRrcConnectionReestablishment (rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendRrcConnectionReestablishmentReject (uint16_t rnti, RrcConnectionReestablishmentReject msg)
{
  m_owner->DoSendRrcConnectionReestablishmentReject (rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendRrcConnectionRelease (uint16_t rnti, RrcConnectionRelease msg)
{
  m_owner->DoSendRrcConnectionRelease (rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendRrcPagingDirect (uint16_t rnti)
{
  m_owner->DoSendRrcPagingDirect (rnti);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendRrcConnectionReject (uint16_t rnti, RrcConnectionReject msg)
{
  m_owner->DoSendRrcConnectionReject (rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendRrcConnectionSwitch (uint16_t rnti, RrcConnectionSwitch msg)
{
  m_owner->DoSendRrcConnectionSwitch (rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapUser<C>::SendRrcConnectToMmWave (uint16_t rnti, uint16_t mmWaveCellId)
{
  m_owner->DoSendRrcConnectToMmWave (rnti, mmWaveCellId);
}

template <class C>
Ptr<Packet>
MemberLteEnbRrcSapUser<C>::EncodeHandoverPreparationInformation (HandoverPreparationInfo msg)
{
  return m_owner->DoEncodeHandoverPreparationInformation (msg);
}

template <class C>
LteRrcSap::HandoverPreparationInfo
MemberLteEnbRrcSapUser<C>::DecodeHandoverPreparationInformation (Ptr<Packet> p)
{
  return m_owner->DoDecodeHandoverPreparationInformation (p);
}


template <class C>
Ptr<Packet>
MemberLteEnbRrcSapUser<C>::EncodeHandoverCommand (RrcConnectionReconfiguration msg)
{
  return m_owner->DoEncodeHandoverCommand (msg);
}

template <class C>
LteRrcSap::RrcConnectionReconfiguration
MemberLteEnbRrcSapUser<C>::DecodeHandoverCommand (Ptr<Packet> p)
{
  return m_owner->DoDecodeHandoverCommand (p);
}

/**
 * Template for the implementation of the LteEnbRrcSapProvider as a member
 * of an owner class of type C to which all methods are forwarded
 *
 */
template <class C>
class MemberLteEnbRrcSapProvider : public LteEnbRrcSapProvider
{
public:
  /**
   * Constructor
   *
   * \param owner
   */
  MemberLteEnbRrcSapProvider (C* owner);

  // methods inherited from LteEnbRrcSapProvider go here

  virtual void CompleteSetupUe (uint16_t rnti, CompleteSetupUeParameters params);
  virtual void RecvRrcConnectionRequest (uint16_t rnti, RrcConnectionRequest msg);
  virtual void RecvRrcConnectionSetupCompleted (uint16_t rnti, RrcConnectionSetupCompleted msg);
  virtual void RecvRrcConnectionReconfigurationCompleted (uint16_t rnti, RrcConnectionReconfigurationCompleted msg);
  virtual void RecvRrcConnectionReestablishmentRequest (uint16_t rnti, RrcConnectionReestablishmentRequest msg);
  virtual void RecvRrcConnectionReestablishmentComplete (uint16_t rnti, RrcConnectionReestablishmentComplete msg);
  virtual void RecvMeasurementReport (uint16_t rnti, MeasurementReport msg);
  virtual void RecvRrcSecondaryCellInitialAccessSuccessful (uint16_t rnti, uint16_t mmWaveRnti, uint16_t mmWaveCellId);

private:
  MemberLteEnbRrcSapProvider ();
  C* m_owner; ///< the owner class
};

template <class C>
MemberLteEnbRrcSapProvider<C>::MemberLteEnbRrcSapProvider (C* owner)
  : m_owner (owner)
{
}

template <class C>
MemberLteEnbRrcSapProvider<C>::MemberLteEnbRrcSapProvider ()
{
}

template <class C>
void
MemberLteEnbRrcSapProvider<C>::CompleteSetupUe (uint16_t rnti, CompleteSetupUeParameters params)
{
  m_owner->DoCompleteSetupUe (rnti, params);
}

template <class C>
void
MemberLteEnbRrcSapProvider<C>::RecvRrcConnectionRequest (uint16_t rnti, RrcConnectionRequest msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionRequest, m_owner, rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapProvider<C>::RecvRrcConnectionSetupCompleted (uint16_t rnti, RrcConnectionSetupCompleted msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionSetupCompleted, m_owner, rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapProvider<C>::RecvRrcConnectionReconfigurationCompleted (uint16_t rnti, RrcConnectionReconfigurationCompleted msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionReconfigurationCompleted, m_owner, rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapProvider<C>::RecvRrcConnectionReestablishmentRequest (uint16_t rnti, RrcConnectionReestablishmentRequest msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionReestablishmentRequest, m_owner, rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapProvider<C>::RecvRrcConnectionReestablishmentComplete (uint16_t rnti, RrcConnectionReestablishmentComplete msg)
{
  Simulator::ScheduleNow (&C::DoRecvRrcConnectionReestablishmentComplete, m_owner, rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapProvider<C>::RecvMeasurementReport (uint16_t rnti, MeasurementReport msg)
{
  Simulator::ScheduleNow (&C::DoRecvMeasurementReport, m_owner, rnti, msg);
}

template <class C>
void
MemberLteEnbRrcSapProvider<C>::RecvRrcSecondaryCellInitialAccessSuccessful (uint16_t rnti, uint16_t mmWaveRnti, uint16_t mmWaveCellId)
{
  Simulator::ScheduleNow (&C::DoRecvRrcSecondaryCellInitialAccessSuccessful, m_owner, rnti, mmWaveRnti, mmWaveCellId);
}













} // namespace ns3


#endif // LTE_RRC_SAP_H
