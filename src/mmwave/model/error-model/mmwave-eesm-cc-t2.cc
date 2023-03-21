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
#include "mmwave-eesm-cc-t2.h"

#include <ns3/log.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveEesmCcT2");
NS_OBJECT_ENSURE_REGISTERED(MmWaveEesmCcT2);

MmWaveEesmCcT2::MmWaveEesmCcT2()
{
}

MmWaveEesmCcT2::~MmWaveEesmCcT2()
{
}

TypeId
MmWaveEesmCcT2::GetTypeId(void)
{
    static TypeId tid =
        TypeId("ns3::MmWaveEesmCcT2").SetParent<MmWaveEesmCc>().AddConstructor<MmWaveEesmCcT2>();
    return tid;
}

const std::vector<double>*
MmWaveEesmCcT2::GetBetaTable() const
{
    return m_t2.m_betaTable;
}

const std::vector<double>*
MmWaveEesmCcT2::GetMcsEcrTable() const
{
    return m_t2.m_mcsEcrTable;
}

const MmWaveEesmErrorModel::SimulatedBlerFromSINR*
MmWaveEesmCcT2::GetSimulatedBlerFromSINR() const
{
    return m_t2.m_simulatedBlerFromSINR;
}

const std::vector<uint8_t>*
MmWaveEesmCcT2::GetMcsMTable() const
{
    return m_t2.m_mcsMTable;
}

const std::vector<double>*
MmWaveEesmCcT2::GetSpectralEfficiencyForMcs() const
{
    return m_t2.m_spectralEfficiencyForMcs;
}

const std::vector<double>*
MmWaveEesmCcT2::GetSpectralEfficiencyForCqi() const
{
    return m_t2.m_spectralEfficiencyForCqi;
}

} // namespace mmwave
} // namespace ns3
