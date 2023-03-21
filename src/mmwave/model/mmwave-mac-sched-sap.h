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

#ifndef SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHED_SAP_H_
#define SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHED_SAP_H_

#include "mmwave-phy-mac-common.h"

#include <map>
#include <set>

namespace ns3
{

namespace mmwave
{

class MmWaveMacSchedSapProvider
{
  public:
    virtual ~MmWaveMacSchedSapProvider();

    struct SchedDlRlcBufferReqParameters
    {
        uint16_t m_rnti;
        uint8_t m_logicalChannelIdentity;
        uint32_t m_rlcTransmissionQueueSize;
        uint16_t m_rlcTransmissionQueueHolDelay;
        uint32_t m_rlcRetransmissionQueueSize;
        uint16_t m_rlcRetransmissionHolDelay;
        uint16_t m_rlcStatusPduSize;

        std::list<uint32_t> m_txPacketSizes;
        std::list<uint32_t> m_retxPacketSizes;
        std::list<double> m_txPacketDelays;
        std::list<double> m_retxPacketDelays;
        double m_arrivalRate;
    };

    struct SchedDlCqiInfoReqParameters
    {
        SfnSf m_sfnsf;
        std::vector<struct DlCqiInfo> m_cqiList;
    };

    struct SchedUlMacCtrlInfoReqParameters
    {
        SfnSf m_sfnSf;
        std::vector<struct MacCeElement> m_macCeList;
    };

    struct SchedUlCqiInfoReqParameters
    {
        SfnSf m_sfnSf;
        struct UlCqiInfo m_ulCqi;
    };

    struct SchedTriggerReqParameters
    {
        SfnSf m_snfSf;
        std::vector<struct DlHarqInfo> m_dlHarqInfoList;
        std::vector<struct UlHarqInfo> m_ulHarqInfoList;
        std::list<uint16_t> m_ueList;
    };

    virtual void SchedDlRlcBufferReq(const struct SchedDlRlcBufferReqParameters& params) = 0;

    virtual void SchedDlCqiInfoReq(const SchedDlCqiInfoReqParameters& params) = 0;

    virtual void SchedUlCqiInfoReq(const struct SchedUlCqiInfoReqParameters& params) = 0;

    virtual void SchedTriggerReq(const struct SchedTriggerReqParameters& params) = 0;

    virtual void SchedUlMacCtrlInfoReq(const struct SchedUlMacCtrlInfoReqParameters& params) = 0;

    virtual void SchedSetMcs(int mcs)
    {
    }

  private:
};

class MmWaveMacSchedSapUser
{
  public:
    virtual ~MmWaveMacSchedSapUser();

    struct SchedConfigIndParameters
    {
        SfnSf m_sfnSf;
        SlotAllocInfo m_slotAllocInfo;
    };

    virtual void SchedConfigInd(const struct SchedConfigIndParameters& params) = 0;

  private:
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHED_SAP_H_ */
