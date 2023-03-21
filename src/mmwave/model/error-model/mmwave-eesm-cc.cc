/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Adapted from the release 1.0 of the 5G-LENA simulator, please refer to https://5g-lena.cttc.es/
 * for further details and https://gitlab.com/cttc-lena/nr/-/tree/v1.0 for the reference code.
 *
 *   Copyright (c) 2020 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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
#include "mmwave-eesm-cc.h"

#include <ns3/log.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveEesmCc");
NS_OBJECT_ENSURE_REGISTERED(MmWaveEesmCc);

MmWaveEesmCc::MmWaveEesmCc()
{
    NS_LOG_FUNCTION(this);
}

MmWaveEesmCc::~MmWaveEesmCc()
{
    NS_LOG_FUNCTION(this);
}

TypeId
MmWaveEesmCc::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::MmWaveEesmCc").SetParent<MmWaveEesmErrorModel>();
    return tid;
}

double
MmWaveEesmCc::ComputeSINR(const SpectrumValue& sinr,
                          const std::vector<int>& map,
                          uint8_t mcs,
                          uint32_t sizeBit,
                          const MmWaveErrorModel::MmWaveErrorModelHistory& sinrHistory) const
{
    NS_LOG_FUNCTION(this);

    // HARQ CHASE COMBINING: update SINReff, but not ECR after retx
    // repetition of coded bits

    // make a vector of history that contains the last tx (but without modifying
    // sinrHistory, as it will be modified by the caller when it will be the time)
    Ptr<MmWaveEesmErrorModelOutput> last = Create<MmWaveEesmErrorModelOutput>(0.0);
    last->m_map = map;
    last->m_sinr = sinr;

    MmWaveErrorModel::MmWaveErrorModelHistory total = sinrHistory;
    total.push_back(last);

    // evaluate SINR_eff over "total", as per Chase Combining

    NS_ASSERT(sinr.GetSpectrumModel()->GetNumBands() == sinr.GetValuesN());

    SpectrumValue sinr_sum(sinr.GetSpectrumModel());
    uint32_t historySize = static_cast<uint32_t>(total.size());
    uint32_t maxRBUsed = 0;
    for (uint32_t i = 0; i < historySize; ++i)
    {
        Ptr<MmWaveEesmErrorModelOutput> output =
            DynamicCast<MmWaveEesmErrorModelOutput>(total.at(i));
        maxRBUsed = std::max(maxRBUsed, static_cast<uint32_t>(output->m_map.size()));
    }

    std::vector<int> map_sum;
    map_sum.reserve(maxRBUsed);

    for (uint32_t i = 0; i < maxRBUsed; ++i)
    {
        sinr_sum[i] = 0;
        map_sum.push_back(static_cast<int>(i));
    }

    /* combine at the bit level. Example:
     * SINR{1}=[0 0 10 20 10 0 0];
     * SINR{2}=[1 2 1 2 1 0 3];
     * SINR{3}=[5 0 0 0 0 0 0];
     *
     * map{1}=[2 3 4];
     * map{2}=[0 1 2 3 4 6];
     * map{3}=[0];
     *
     * MAP_SUM = [0 1 2 3 4 5]
     * SINR_SUM = [16 27 16 17 26 18]
     *
     * (the value at SINR_SUM[0] is SINR{1}[2] + SINR{2}[0] + SINR{3}[0])
     */
    for (uint32_t i = 0; i < historySize; ++i)
    {
        Ptr<MmWaveEesmErrorModelOutput> output =
            DynamicCast<MmWaveEesmErrorModelOutput>(total.at(i));
        uint32_t size = output->m_map.size();
        for (uint32_t j = 0; j < maxRBUsed; ++j)
        {
            sinr_sum[j] += output->m_sinr[output->m_map[j % size]];
        }
    }

    NS_LOG_INFO("\tHISTORY:");
    for (const auto& element : total)
    {
        Ptr<MmWaveEesmErrorModelOutput> output = DynamicCast<MmWaveEesmErrorModelOutput>(element);
        NS_LOG_INFO("\tMAP:" << PrintMap(output->m_map));
        NS_LOG_INFO("\tSINR: " << output->m_sinr);
    }

    NS_LOG_INFO("MAP_SUM: " << PrintMap(map_sum));
    NS_LOG_INFO("SINR_SUM: " << sinr_sum);

    // compute effective SINR with the sinr_sum vector and map_sum RB map
    return SinrEff(sinr_sum, map_sum, mcs);
}

double
MmWaveEesmCc::GetMcsEq(uint8_t mcsTx) const
{
    NS_LOG_FUNCTION(this);
    return mcsTx;
}

} // namespace mmwave
} // namespace ns3
