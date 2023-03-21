/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Adapted from the release 1.0 of the 5G-LENA simulator, please refer to https://5g-lena.cttc.es/
 * for further details and https://gitlab.com/cttc-lena/nr/-/tree/v1.0 for the reference code.
 *
 *   Copyright (c) 2019 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2021 University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 */

#include "mmwave-harq-phy.h"

#include <ns3/assert.h>
#include <ns3/log.h>

NS_LOG_COMPONENT_DEFINE("MmWaveHarqPhy");

namespace ns3
{

namespace mmwave
{

MmWaveHarqPhy::~MmWaveHarqPhy()
{
    NS_LOG_FUNCTION(this);
    m_dlHistory.clear();
    m_ulHistory.clear();
}

const MmWaveErrorModel::MmWaveErrorModelHistory&
MmWaveHarqPhy::GetHarqProcessInfoDl(uint16_t rnti, uint8_t harqProcId)
{
    NS_LOG_FUNCTION(this);
    return GetHarqProcessInfo(&m_dlHistory, rnti, harqProcId);
}

const MmWaveErrorModel::MmWaveErrorModelHistory&
MmWaveHarqPhy::GetHarqProcessInfoUl(uint16_t rnti, uint8_t harqProcId)
{
    NS_LOG_FUNCTION(this);
    return GetHarqProcessInfo(&m_ulHistory, rnti, harqProcId);
}

void
MmWaveHarqPhy::UpdateDlHarqProcessStatus(uint16_t rnti,
                                         uint8_t harqProcId,
                                         const Ptr<MmWaveErrorModelOutput>& output)
{
    NS_LOG_FUNCTION(this);
    UpdateHarqProcessStatus(&m_dlHistory, rnti, harqProcId, output);
}

void
MmWaveHarqPhy::ResetDlHarqProcessStatus(uint16_t rnti, uint8_t id)
{
    NS_LOG_FUNCTION(this);
    ResetHarqProcessStatus(&m_dlHistory, rnti, id);
}

void
MmWaveHarqPhy::UpdateUlHarqProcessStatus(uint16_t rnti,
                                         uint8_t harqProcId,
                                         const Ptr<MmWaveErrorModelOutput>& output)
{
    NS_LOG_FUNCTION(this);
    UpdateHarqProcessStatus(&m_ulHistory, rnti, harqProcId, output);
}

void
MmWaveHarqPhy::ResetUlHarqProcessStatus(uint16_t rnti, uint8_t id)
{
    NS_LOG_FUNCTION(this);
    ResetHarqProcessStatus(&m_ulHistory, rnti, id);
}

MmWaveHarqPhy::HistoryMap::iterator
MmWaveHarqPhy::GetHistoryMapOf(MmWaveHarqPhy::HistoryMap* map, uint16_t rnti) const
{
    NS_LOG_FUNCTION(this);

    MmWaveHarqPhy::HistoryMap::iterator it = map->find(rnti);
    if (it == map->end())
    {
        auto ret = map->insert(std::make_pair(rnti, ProcIdHistoryMap()));
        NS_ASSERT(ret.second);

        it = ret.first;
    }

    return it;
}

MmWaveHarqPhy::ProcIdHistoryMap::iterator
MmWaveHarqPhy::GetProcIdHistoryMapOf(MmWaveHarqPhy::ProcIdHistoryMap* map, uint16_t procId) const
{
    NS_LOG_FUNCTION(this);

    MmWaveHarqPhy::ProcIdHistoryMap::iterator it = map->find(procId);
    if (it == map->end())
    {
        auto ret = map->insert(std::make_pair(procId, MmWaveErrorModel::MmWaveErrorModelHistory()));
        NS_ASSERT(ret.second);

        it = ret.first;
    }

    return it;
}

void
MmWaveHarqPhy::ResetHarqProcessStatus(MmWaveHarqPhy::HistoryMap* map,
                                      uint16_t rnti,
                                      uint8_t harqProcId) const
{
    NS_LOG_FUNCTION(this);

    MmWaveHarqPhy::HistoryMap::iterator historyMap = GetHistoryMapOf(map, rnti);

    ProcIdHistoryMap* procIdMap = &(historyMap->second);

    GetProcIdHistoryMapOf(procIdMap, harqProcId)->second.clear();
}

void
MmWaveHarqPhy::UpdateHarqProcessStatus(MmWaveHarqPhy::HistoryMap* map,
                                       uint16_t rnti,
                                       uint8_t harqProcId,
                                       const Ptr<MmWaveErrorModelOutput>& output) const
{
    NS_LOG_FUNCTION(this);

    MmWaveHarqPhy::HistoryMap::iterator historyMap = GetHistoryMapOf(map, rnti);

    ProcIdHistoryMap* procIdMap = &(historyMap->second);

    GetProcIdHistoryMapOf(procIdMap, harqProcId)->second.emplace_back(output);
}

const MmWaveErrorModel::MmWaveErrorModelHistory&
MmWaveHarqPhy::GetHarqProcessInfo(MmWaveHarqPhy::HistoryMap* map,
                                  uint16_t rnti,
                                  uint8_t harqProcId) const
{
    NS_LOG_FUNCTION(this);

    MmWaveHarqPhy::HistoryMap::iterator historyMap = GetHistoryMapOf(map, rnti);

    ProcIdHistoryMap* procIdMap = &(historyMap->second);

    return GetProcIdHistoryMapOf(procIdMap, harqProcId)->second;
}

} // namespace mmwave
} // namespace ns3
