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

#ifndef SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHEDULER_H_
#define SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHEDULER_H_

#include "mmwave-mac-csched-sap.h"
#include "mmwave-mac-sched-sap.h"
#include "mmwave-phy-mac-common.h"
#include "mmwave-phy.h"

#include <ns3/abort.h>
#include <ns3/enum.h>
#include <ns3/math.h>
#include <ns3/object.h>
#include <ns3/string.h>

namespace ns3
{

class MacSchedSapProvider;
class MacSchedSapUser;

namespace mmwave
{

static const uint32_t BufferSizeLevelBsrTable[64] = {
    0,     10,    12,    14,    17,    19,    22,    26,    31,     36,     42,     49,    57,
    67,    78,    91,    107,   125,   146,   171,   200,   234,    274,    321,    376,   440,
    515,   603,   706,   826,   967,   1132,  1326,  1552,  1817,   2127,   2490,   2915,  3413,
    3995,  4677,  5476,  6411,  7505,  8787,  10287, 12043, 14099,  16507,  19325,  22624, 26487,
    31009, 36304, 42502, 49759, 58255, 68201, 79846, 93749, 109439, 128125, 150000, 150000};

class MmWaveMacScheduler : public Object
{
  public:
    MmWaveMacScheduler();
    virtual ~MmWaveMacScheduler();

    virtual void DoDispose(void) override;
    static TypeId GetTypeId(void);

    virtual void ConfigureCommonParameters(Ptr<MmWavePhyMacCommon> config) = 0;

    virtual void SetMacSchedSapUser(MmWaveMacSchedSapUser* sap) = 0;

    virtual MmWaveMacSchedSapProvider* GetMacSchedSapProvider() = 0;

    virtual void SetMacCschedSapUser(MmWaveMacCschedSapUser* sap) = 0;

    virtual MmWaveMacCschedSapProvider* GetMacCschedSapProvider() = 0;

  protected:
    Ptr<MmWavePhyMacCommon> m_phyMacConfig;
    uint32_t m_rbgSize; // RBs per RB group for res alloc type 0
};

} // namespace mmwave
} // namespace ns3
#endif /* SRC_MMWAVE_MODEL_MMWAVE_MAC_SCHEDULER_H_ */
