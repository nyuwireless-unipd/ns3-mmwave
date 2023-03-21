/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 * Author: Michele Polese <michele.polese@gmail.com>
 */

#ifndef CORE_NETWORK_STATS_CALCULATOR_H_
#define CORE_NETWORK_STATS_CALCULATOR_H_

#include "ns3/basic-data-calculators.h"
#include "ns3/lte-common.h"
#include "ns3/object.h"
#include "ns3/uinteger.h"

#include <fstream>
#include <map>
#include <string>

namespace ns3
{

namespace mmwave
{

class CoreNetworkStatsCalculator : public Object
{
  public:
    CoreNetworkStatsCalculator();
    ~CoreNetworkStatsCalculator();

    static TypeId GetTypeId(void);

    void DoDispose();

    void LogX2Packet(std::string path,
                     uint16_t sourceCellId,
                     uint16_t targetCellId,
                     uint32_t size,
                     uint64_t delay,
                     bool data);
    void LogMmePacket(std::string path,
                      uint16_t sourceCellId,
                      uint16_t targetCellId,
                      uint32_t size,
                      uint64_t delay);

    std::string GetX2OutputFilename(void);
    std::string GetMmeOutputFilename(void);
    void SetX2OutputFilename(std::string outputFilename);
    void SetMmeOutputFilename(std::string outputFilename);

  private:
    std::string m_mmeOutFileName;
    std::string m_x2OutFileName;

    std::ofstream m_x2OutFile;
    std::ofstream m_mmeOutFile;
};

} // namespace mmwave

} // namespace ns3

#endif
