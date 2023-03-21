/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Adapted from the release 1.0 of the 5G-LENA simulator, please refer to https://5g-lena.cttc.es/
 * for further details and https://gitlab.com/cttc-lena/nr/-/tree/v1.0 for the reference code.
 *
 *   Copyright (c) 2018 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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
#include "mmwave-error-model.h"

#include <ns3/log.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("MmWaveErrorModel");
NS_OBJECT_ENSURE_REGISTERED(MmWaveErrorModel);

MmWaveErrorModel::MmWaveErrorModel()
    : Object()
{
    NS_LOG_FUNCTION(this);
}

MmWaveErrorModel::~MmWaveErrorModel()
{
}

TypeId
MmWaveErrorModel::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::MmWaveErrorModel").SetParent<Object>();
    return tid;
}

TypeId
MmWaveErrorModel::GetInstanceTypeId() const
{
    return MmWaveErrorModel::GetTypeId();
}

} // namespace mmwave
} // namespace ns3
