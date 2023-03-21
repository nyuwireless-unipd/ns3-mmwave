/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H
#define SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H

#include <ns3/log.h>
#include <ns3/nstime.h>
#include <ns3/object.h>
#include <ns3/packet.h>
#include <ns3/string.h>

#include <deque>
#include <list>
#include <map>
#include <vector>

namespace ns3
{

namespace mmwave
{

/**
 * Struct holding the numerology information such as frame, subframe,
 * slot and (eventually) starting OFDM symbol number.
 */
struct SfnSf
{
    /**
     * Default constructor, the starting symbol is optional
     *
     * \param frameNum the frame number
     * \param sfNum the subframe number
     * \param slotNum the slot number
     * \param symStart the (optional) starting symbol
     */
    SfnSf(uint32_t frameNum = 0, uint8_t sfNum = 0, uint8_t slotNum = 0, uint8_t symStart = 0)
        : m_frameNum(frameNum),
          m_sfNum(sfNum),
          m_slotNum(slotNum),
          m_symStart(symStart)
    {
        // Non-negative
        NS_ASSERT((m_frameNum >= 0) && (m_sfNum >= 0) && (m_slotNum >= 0) && (m_symStart >= 0));
    }

    /**
     * Encodes the struct into an uint64_t
     */
    uint64_t Encode() const
    {
        return ((uint64_t(m_frameNum) << 24) | ((m_sfNum & 0xFF) << 16) |
                ((m_slotNum & 0xFF) << 8) | (m_symStart & 0xFF));
    }

    /**
     * Decodes the struct from an uint64_t and updates the struct variables with the given values
     */
    void Decode(uint64_t sfn)
    {
        m_frameNum = sfn >> 24;
        m_sfNum = ((sfn & 0xFF0000) >> 16);
        m_slotNum = ((sfn & 0xFF00) >> 8);
        m_symStart = sfn & 0xFF;
    }

    uint32_t m_frameNum; //!< Frame number
    uint8_t m_sfNum;     //!< Subframe number
    uint8_t m_slotNum;   //!< Slot number
    uint8_t
        m_symStart; //!< Starting symbol (not always used!), sometimes used to indicate the ttiIndex
};

/**
 * Struct used to trace a PHY layer transmission.
 * \see mmwave-phy-trace.cc
 */
struct PhyTransmissionTraceParams
{
    enum TddMode
    {
        TDD_NA = 0, //!< unknown
        DL = 1,     //!< downlink transmission
        UL = 2,     //!< uplink transmission
    };

    enum TddTtiType
    {
        DATA = 0,    //!< data transmission
        TYPE_NA = 1, //!< unknown
        CTRL = 2,    //!< transmission of control signals
    };

    PhyTransmissionTraceParams()
        : m_tddMode(0),
          m_slotNum(0),
          m_sfNum(0),
          m_frameNum(0),
          m_rnti(0),
          m_symStart(0),
          m_numSym(0),
          m_ttiType(0),
          m_rv(0),
          m_ccId(0)
    {
    }

    uint8_t m_tddMode;   //!< TDD mode. Either DL or UL
    uint8_t m_slotNum;   //!< Slot number
    uint8_t m_sfNum;     //!< Subframe number
    uint32_t m_frameNum; //!< Frame number
    uint16_t m_rnti;     //!< UE RNTI (where such distinction is applicable, 0 otherwise)
    uint8_t m_symStart;  //!< Starting OFDM symbol of the current transmission
    uint8_t m_numSym;    //!< Amount of OFDM symbols of current transmission
    uint8_t m_ttiType;   //!< TDD transmission type. Either DATA or CTRL.
    uint8_t m_rv;        //!< (Re)TX number. If 0 the TTI refers to new data, otherwise to a retx.
    uint8_t m_ccId;      //!< The Component Carrier (CC) ID
};

/**
 * Struct holding the information of a DCI message
 */
struct DciInfoElementTdma
{
    enum DciFormat
    {
        DL_dci = 0,
        UL_dci = 1
    };

    DciInfoElementTdma()
        : m_rnti(0),
          m_format(0),
          m_symStart(0),
          m_numSym(0),
          m_mcs(0),
          m_tbSize(0),
          m_ndi(0),
          m_rv(0),
          m_harqProcess(0)
    {
    }

    DciInfoElementTdma(uint16_t rnti,
                       uint8_t format,
                       uint8_t symStart,
                       uint8_t numSym,
                       uint8_t mcs,
                       uint32_t tbs,
                       uint8_t ndi,
                       uint8_t rv,
                       uint8_t harqProc)
        : m_rnti(rnti),
          m_format(format),
          m_symStart(symStart),
          m_numSym(numSym),
          m_mcs(mcs),
          m_tbSize(tbs),
          m_ndi(ndi),
          m_rv(rv),
          m_harqProcess(harqProc)
    {
    }

    uint16_t m_rnti;       //!< the RNTI
    uint8_t m_format;      //!< {DL assig. = 0, UL grant = 1}, only contiguous symbols supported
    uint8_t m_symStart;    //!< index of the first allocated symbol
    uint8_t m_numSym;      //!< number of allocated symbols
    uint8_t m_mcs;         //!< selected MCS
    uint32_t m_tbSize;     //!< transport block size
    uint8_t m_ndi;         //!< if 1 indicates a new transmission, if 0 indicates a retransmission
    uint8_t m_rv;          //!< counter holding the number of retransmissions
    uint8_t m_harqProcess; //!< HARQ process ID
};

/**
 * Struct used to schedule the transmission of RLC PDUs
 */
struct RlcPduInfo
{
    RlcPduInfo()
        : m_lcid(0),
          m_size(0)
    {
    }

    RlcPduInfo(uint8_t lcid, uint16_t size)
        : m_lcid(lcid),
          m_size(size)
    {
    }

    uint8_t m_lcid;  //!< the logical channel ID
    uint32_t m_size; //!< the grant size
};

/**
 * Struct holding the scheduling information of a TTI
 */
struct TtiAllocInfo
{
    enum TddMode
    {
        NA = 0,               //!< unknown
        DL_slotAllocInfo = 1, //!< downlink transmission
        UL_slotAllocInfo = 2, //!< uplink transmission
    };

    enum TddTtiType
    {
        CTRL_DATA = 0,
        DATA = 1, //!< data transmission
        CTRL = 2  //!< transmission of control signals
    };

    TtiAllocInfo()
        : m_tddMode(NA),
          m_isOmni(0),
          m_ttiType(CTRL_DATA),
          m_numCtrlSym(0),
          m_ttiIdx(0),
          m_rnti(0)
    {
    }

    TtiAllocInfo(uint8_t ttiIdx, TddMode tddMode, TddTtiType ttiType, uint16_t rnti)
        : m_tddMode(tddMode),
          m_isOmni(0),
          m_ttiType(ttiType),
          m_numCtrlSym(0),
          m_ttiIdx(ttiIdx),
          m_rnti(rnti)
    {
    }

    TddMode m_tddMode;    //!< indicates the transmission mode, uplink or downlink
    bool m_isOmni;        //!< if true, the transmission is omnidirectional
    TddTtiType m_ttiType; //!< indicates the type of information transmitted
    uint8_t m_numCtrlSym; //!< number of DL ctrl symbols at beginning of slot
    uint8_t m_ttiIdx;     //!< index of the TTI inside the slot
    uint16_t m_rnti;      //!< the RNTI
    struct DciInfoElementTdma
        m_dci; //!< the DCI containing the scheduling information corresponding to this TTI
    std::vector<RlcPduInfo> m_rlcPduInfo; //!< vector of RlcPduInfo instances to be transmitted
};

/**
 * Struct holding the scheduling information of a slot.
 * SlotAllocInfo contains the TtiAllocInfo instances associated with a slot.
 */
struct SlotAllocInfo
{
    SlotAllocInfo()
        : m_sfnSf(SfnSf()),
          m_numSymAlloc(0)
    {
    }

    SlotAllocInfo(SfnSf sfn)
        : m_sfnSf(sfn),
          m_numSymAlloc(0)
    {
    }

    SfnSf m_sfnSf;          //!< frame, subframe and slot indices
    uint32_t m_numSymAlloc; //!< number of allocated OFDM symbols
    std::deque<TtiAllocInfo>
        m_ttiAllocInfo; //!< contains the TtiAllocInfo instances corresponding to this slot
};

/**
 * Struct carrying a downlink CQI
 */
struct DlCqiInfo
{
    uint16_t m_rnti;
    uint8_t m_ri;

    enum DlCqiType
    {
        WB,
        SB
    } m_cqiType;

    std::vector<uint8_t> m_rbCqi; // CQI for each Rsc Block, set to -1 if SINR < Threshold
    uint8_t m_wbCqi;              // Wide band CQI
    uint8_t m_wbPmi;
};

/**
 * Struct carrying a downlink CQI
 */
struct UlCqiInfo
{
    std::vector<double> m_sinr;

    enum UlCqiType
    {
        SRS,
        PUSCH,
        PUCCH_1,
        PUCCH_2,
        PRACH
    } m_type;
};

/**
 * Represents a MAC Control Element value
 */
struct MacCeValue
{
    uint8_t m_phr;
    uint8_t m_crnti;
    std::vector<uint8_t> m_bufferStatus;
};

/**
 * Represents a MAC Control Element
 */
struct MacCeElement
{
    uint16_t m_rnti;

    enum MacCeType
    {
        BSR,
        PHR,
        CRNTI
    } m_macCeType;
    struct MacCeValue m_macCeValue;
};

/**
 * Struct used to trace the reception of a transport block by the PHY layer
 * \see mmwave-phy-trace.cc
 */
struct RxPacketTraceParams
{
    uint64_t m_cellId;   //!< the cell ID
    uint8_t m_ccId;      //!< the component carrier ID
    uint16_t m_rnti;     //!< the RNTI
    uint32_t m_frameNum; //!< frame index
    uint8_t m_sfNum;     //!< subframe index
    uint8_t m_slotNum;   //!< slot index
    uint8_t m_symStart;  //!< index of the first OFDM symbol
    uint8_t m_numSym;    //!< number of OFDM symbols
    uint32_t m_tbSize;   //!< transport block size
    uint8_t m_mcs;       //!< the MCS
    uint8_t m_rv;        //!< the number of retransmissions
    double m_sinr;       //!< the average SINR over all the subchannels
    double m_sinrMin;    //!< the minimum SINR value over all the subchannels
    double m_tbler;      //!< the transport block error rate
    bool m_corrupt;      //!< if true the TB has failed
};

/**
 * Struct holding the information of a DL HARQ process
 */
struct DlHarqInfo
{
    uint16_t m_rnti;         //!< the RNTI
    uint8_t m_harqProcessId; //!< the HARQ process ID

    enum HarqStatus
    {
        ACK,
        NACK
    };
    enum HarqStatus m_harqStatus; //!< the status of the process
    uint8_t m_numRetx;            //!< the number of retransmissions
};

/**
 * Struct holding the information of an UL HARQ process
 */
struct UlHarqInfo
{
    uint16_t m_rnti;         //!< the RNTI
    uint8_t m_harqProcessId; //!< the HARQ process ID

    enum ReceptionStatus
    {
        Ok,
        NotOk,
        NotValid
    } m_receptionStatus; //!< the status of the process

    uint8_t m_numRetx; //!< the number of retransmissions
};

/**
 * This class is a containter holding the parameters used by MAC and PHY layers.
 */
class MmWavePhyMacCommon : public Object
{
  public:
    static const uint8_t SUBCARRIERS_PER_RB{
        12}; //!< The amount of subcarriers per Resource Block. See TS 38.211 Sec 4.4.4.1
    static const uint8_t REF_SUBCARRIERS_PER_RB{
        1}; //!< The amount of reference subcarriers per Resource Block. TODO: check in the TS

    /**
     * Represents the PHY layer numerology configuration
     */
    enum Numerology
    {
        NrNumerology2 = 2, //!< NR numerology index 2
        NrNumerology3 = 3  //!< NR numerology index 3
    };

    /**
     * Constructor
     */
    MmWavePhyMacCommon(void);

    /**
     * Destructor
     */
    ~MmWavePhyMacCommon(void)
    {
    }

    static TypeId GetTypeId(void);

    /**
     * Returns the number of OFDM symbols inside a slot.
     */
    inline uint32_t GetSymbPerSlot(void)
    {
        return m_symbolsPerSlot;
    }

    /**
     * Returns the duration of a single OFDM symbol.
     */
    inline Time GetSymbolPeriod(void)
    {
        return m_symbolPeriod;
    }

    /**
     * Returns the number of OFDM symbols in a slot which are used to carry
     * downlink and uplink control information.
     */
    inline uint32_t GetCtrlSymbols(void)
    {
        return (m_dlCtrlSymbols + m_ulCtrlSymbols);
    }

    /**
     * Returns the number of OFDM symbols in a slot which are used to carry
     * downlink control information.
     */
    inline uint32_t GetDlCtrlSymbols(void)
    {
        return m_dlCtrlSymbols;
    }

    /**
     * Returns the number of OFDM symbols in a slot which are used to carry
     * uplink control information.
     */
    inline uint32_t GetUlCtrlSymbols(void)
    {
        return m_ulCtrlSymbols;
    }

    /**
     * Returns the number of OFDM symbols in a subframe.
     */
    inline uint32_t GetSymbolsPerSubframe(void)
    {
        return m_symbolsPerSubframe;
    }

    /**
     * Returns the duration of a subframe.
     */
    inline Time GetSubframePeriod(void)
    {
        return m_subframePeriod;
    }

    /**
     * Returns the duration of a slot.
     */
    inline Time GetSlotPeriod(void)
    {
        return NanoSeconds(m_symbolsPerSlot * m_symbolPeriod.GetNanoSeconds()); // seconds
    }

    /**
     * Returns the number of slots in a subframe.
     */
    inline uint32_t GetSlotsPerSubframe(void)
    {
        return m_slotsPerSubframe;
    }

    /**
     * Returns the number of subframes in a frame.
     */
    inline uint32_t GetSubframesPerFrame(void)
    {
        return m_subframesPerFrame;
    }

    // TODO this parameter is used by MmWaveAmc::GetTbSizeFromMcs, which is never used
    // consider to remove it
    inline uint32_t GetNumReferenceSymbols(void)
    {
        return m_numRefSymbols;
    }

    /**
     * Returns the delay between the UL-DCI transmission and when such scheduled UL
     * will take place, defined as # of NR slots.
     */
    inline uint8_t GetUlSchedDelay(void)
    {
        return m_ulSchedDelay;
    }

    /**
     * Returns the width of a Resource Block in Hz.
     */
    inline double GetRbWidth(void)
    {
        return m_rbWidth;
    }

    /**
     * Returns the number of Resource Blocks.
     */
    inline uint32_t GetNumRb(void)
    {
        return m_numRbs;
    }

    /**
     * Returns the number of subcarriers used to carry reference
     * signals in each symbol.
     */
    inline uint32_t GetNumRefScPerSym(void)
    {
        return m_numRefSc;
    }

    /**
     * Returns the carrier bandwidth in Hz.
     */
    inline double GetBandwidth(void)
    {
        return (GetRbWidth() * GetNumRb());
    }

    /**
     * Returns the carrier frequency in Hz.
     */
    inline double GetCenterFrequency(void)
    {
        return m_centerFrequency;
    }

    /**
     * Returns the L1L2 control info latency, expressed in # of NR slots.
     */
    inline uint32_t GetL1L2Latency(void)
    {
        return m_L1L2Latency;
    }

    /**
     * Returns number of concurrent stop-and-wait Hybrid ARQ processes per user.
     */
    inline uint32_t GetNumHarqProcess(void)
    {
        return m_numHarqProcess;
    }

    /**
     * Returns the Hybrid ARQ timeout period.
     */
    inline uint8_t GetHarqTimeout(void)
    {
        return m_harqTimeout;
    }

    /**
     * Returns the time required by the PHY layer to decode a transport block
     * in micro seconds.
     */
    inline uint32_t GetTbDecodeLatency(void)
    {
        return m_tbDecodeLatencyUs;
    }

    /**
     * Configures the PHY layer parameters based on the desired numerology
     *
     * \param num The desired numerology configuration
     *
     **/
    void SetNumerology(Numerology num);

    /**
     * Sets the desired bandwidth for a given \ref MmWavePhyMacCommon object.
     *
     * \param bw The intended bandwidth.
     *
     **/
    void SetBandwidth(double bw);

    /**
     * Sets the desired delay between when UL DCIs are sent by the scheduler and the slot they refer
     *to.
     *
     * \param delay The intended UL scheduling delay, expressed as number of NR slots.
     *
     **/
    void SetUlSchedDelay(uint32_t delay);

    void SetSymbPerSlot(uint32_t numSym)
    {
        m_symbolsPerSlot = numSym;
    }

    void SetSymbolPeriod(Time prdSym)
    {
        m_symbolPeriod = prdSym;
    }

    void SetSymbolsPerSubframe(uint32_t numSym)
    {
        m_symbolsPerSubframe = numSym;
    }

    void SetSubframePeriod(Time period)
    {
        m_subframePeriod = period;
    }

    void SetDlCtrlSymbols(uint32_t ctrlSymbols)
    {
        m_dlCtrlSymbols = ctrlSymbols;
    }

    void SetUlCtrlSymbols(uint32_t ctrlSymbols)
    {
        m_ulCtrlSymbols = ctrlSymbols;
    }

    void SetSlotPerSubframe(uint32_t numSlot)
    {
        m_slotsPerSubframe = numSlot;
    }

    void SetSubframePerFrame(uint32_t numSf)
    {
        m_subframesPerFrame = numSf;
    }

    void SetNumReferenceSymbols(uint32_t refSym)
    {
        m_numRefSymbols = refSym;
    }

    void SetNumRefScPerSym(uint32_t numRefSc)
    {
        m_numRefSc = numRefSc;
    }

    void SetChunkWidth(double chumkWidth)
    {
        m_rbWidth = chumkWidth;
    }

    void SetCentreFrequency(double fc)
    {
        m_centerFrequency = fc;
    }

    void SetL1L2Latency(uint32_t delaySfs)
    {
        m_L1L2Latency = delaySfs;
    }

    void SetNumHarqProcess(uint32_t numProcess)
    {
        m_numHarqProcess = numProcess;
    }

    void SetHarqDlTimeout(uint8_t harqDlTimeout)
    {
        m_harqTimeout = harqDlTimeout;
    }

    void SetTbDecodeLatency(uint32_t us)
    {
        m_tbDecodeLatencyUs = us;
    }

    void SetCcId(uint8_t ccId)
    {
        m_componentCarrierId = ccId;
    }

    uint8_t GetCcId(void)
    {
        return m_componentCarrierId;
    }

  private:
    /**
     * Makes a MmWavePhyMacCommon object NR-compliant by adjusting its parameters
     *
     * \param index The numerology index, as per TS 38.211 Sec 4.3.2.
     *
     **/
    void SetNrNumerology(uint8_t index);

    uint32_t m_symbolsPerSlot;     //!< number of OFDM symbols in a slot
    Time m_symbolPeriod;           //!< time duration of a single OFDM symbol
    uint32_t m_symbolsPerSubframe; //!< number of OFDM symbols in a subframe
    Time m_subframePeriod;         //!< time duration of a single subframe
    uint32_t m_dlCtrlSymbols;      //!< num OFDM symbols for downlink control
    uint32_t m_ulCtrlSymbols;      //!< num OFDM symbols for uplink control
    uint32_t m_slotsPerSubframe;   //!< number of slots in a subframe
    uint32_t m_subframesPerFrame;  //!< number of subframes in a frame
    uint32_t m_numRefSymbols; // TODO this parameter is used by MmWaveAmc::GetTbSizeFromMcs, which
                              // is never used

    uint32_t m_numRbs;        //!< number of Resource Blocks
    uint32_t m_numRefSc;      //!< number of reference subcarriers across entire bandwidth
    double m_rbWidth;         //!< width of a Resource Block in Hz
    uint8_t m_numHarqProcess; //!< number of concurrent stop-and-wait Hybrid ARQ processes per user
    uint8_t m_harqTimeout;    //!< hybrid ARQ timeout period

    double m_centerFrequency; //!< the carrier frequency

    uint32_t m_L1L2Latency;  //!< L1L2 control latency, expressed in # of NR slots.
    uint32_t m_ulSchedDelay; //!<  Delay between the UL-DCI transmission and when such scheduled UL
                             //!<  will take place, defined as # of NR slots.

    uint32_t m_tbDecodeLatencyUs; //!< time required by the PHY layer to decode a transport block
    uint8_t m_componentCarrierId; //!< the component carrier ID
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_PHY_MAC_COMMON_H_ */
