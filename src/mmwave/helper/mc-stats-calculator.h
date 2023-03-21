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

#ifndef MC_STATS_CALCULATOR_H_
#define MC_STATS_CALCULATOR_H_

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

class McStatsCalculator : public Object
{
  public:
    /**
     * Class constructor
     */
    McStatsCalculator();

    /**
     * Class destructor
     */
    virtual ~McStatsCalculator();

    // Inherited from ns3::Object
    /**
     *  Register this type.
     *  \return The object TypeId.
     */
    static TypeId GetTypeId(void);
    void DoDispose();

    std::string GetLteOutputFilename(void);
    std::string GetMmWaveOutputFilename(void);
    std::string GetCellIdInTimeOutputFilename(void);

    void SetLteOutputFilename(std::string outputFilename);
    void SetMmWaveOutputFilename(std::string outputFilename);
    void SetCellIdInTimeOutputFilename(std::string outputFilename);

    void SwitchToLte(uint64_t imsi, uint16_t cellId, uint16_t rnti);

    void SwitchToMmWave(uint64_t imsi, uint16_t cellId, uint16_t rnti);

  private:
    /**
     * Name of the file where the downlink PDCP statistics will be saved
     */
    std::string m_lteOutputFilename;

    /**
     * Name of the file where the uplink PDCP statistics will be saved
     */
    std::string m_mmWaveOutputFilename;

    std::string m_cellInTimeFilename;

    std::ofstream m_lteOutFile;
    std::ofstream m_mmWaveOutFile;
    std::ofstream m_cellInTimeOutFile;
};

} // namespace mmwave

} // namespace ns3

#endif /* MC_STATS_CALCULATOR_H_ */
