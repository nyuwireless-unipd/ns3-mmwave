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

#ifndef SRC_MMWAVE_MODEL_MMWAVE_MAC_H_
#define SRC_MMWAVE_MODEL_MMWAVE_MAC_H_

#include "mmwave-control-messages.h"
#include "mmwave-enb-phy.h"
#include "mmwave-mac-pdu-header.h"
#include "mmwave-mac-pdu-tag.h"
#include "mmwave-mac-sched-sap.h"
#include "mmwave-mac-scheduler.h"
#include "mmwave-phy-mac-common.h"

#include <ns3/lte-mac-sap.h>
#include <ns3/lte-radio-bearer-tag.h>
#include <ns3/packet-burst.h>
#include <ns3/packet.h>

#include <list>
#include <map>
#include <vector>

namespace ns3
{

namespace mmwave
{

struct MacPduInfo
{
    MacPduInfo(SfnSf sfn, uint32_t size, uint8_t numRlcPdu)
        : m_sfnSf(sfn),
          m_size(size),
          m_numRlcPdu(numRlcPdu)
    {
        m_pdu = Create<Packet>();
        m_macHeader = MmWaveMacPduHeader();
        MmWaveMacPduTag tag(sfn);
        m_pdu->AddPacketTag(tag);
    }

    MacPduInfo(SfnSf sfn, uint32_t size, uint8_t numRlcPdu, DciInfoElementTdma dci)
        : m_sfnSf(sfn),
          m_size(size),
          m_numRlcPdu(numRlcPdu)
    {
        m_pdu = Create<Packet>();
        m_macHeader = MmWaveMacPduHeader();
        // TODO: set dci.m_symStart in SfnSf
        MmWaveMacPduTag tag(sfn, dci.m_numSym);
        m_pdu->AddPacketTag(tag);
    }

    SfnSf m_sfnSf;
    uint32_t m_size;
    uint8_t m_numRlcPdu;
    Ptr<Packet> m_pdu;
    MmWaveMacPduHeader m_macHeader;
};

class MmWaveMac : public Object
{
  public:
    /* Do not put the set TypeId function. */
    MmWaveMac();
    ~MmWaveMac();

    void SetConfigurationParameters(Ptr<MmWavePhyMacCommon> ptrConfig);
    Ptr<MmWavePhyMacCommon> GetConfigurationParameters(void) const;

    bool QueueData(Ptr<Packet> packet);
    Ptr<PacketBurst> GetPacketBurstFromMacQueue();

  protected:
    Ptr<MmWavePhyMacCommon> m_phyMacConfig;

    Ptr<PacketBurst> m_macQueue;
};

} // namespace mmwave

} // namespace ns3

#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAC_H_ */
