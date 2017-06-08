/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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
 * Author: Jaume Nin <jnin@cttc.es>
 *         Nicola Baldo <nbaldo@cttc.es>
 */

#ifndef RETX_STATS_CALCULATOR_H_
#define RETX_STATS_CALCULATOR_H_

#include "ns3/lte-common.h"
#include "ns3/uinteger.h"
#include "ns3/object.h"
#include "ns3/basic-data-calculators.h"
#include "ns3/lte-common.h"
#include <string>
#include <map>
#include <fstream>

namespace ns3
{

class RetxStatsCalculator : public Object
{
public:
  /**
   * Class constructor
   */
  RetxStatsCalculator ();

  /**
   * Class destructor
   */
  virtual
  ~RetxStatsCalculator ();

  // Inherited from ns3::Object
  /**
   *  Register this type.
   *  \return The object TypeId.
   */
  static TypeId GetTypeId (void);
  void DoDispose ();

  void RegisterRetxDl(uint64_t imsi, uint16_t cellId, uint16_t rnti, uint8_t lcid, uint32_t packetSize, uint32_t numRetx);
  void RegisterRetxUl(uint64_t imsi, uint16_t cellId, uint16_t rnti, uint8_t lcid, uint32_t packetSize, uint32_t numRetx);

  std::ofstream m_retxDlFile;
  std::string m_retxDlFilename;

  std::ofstream m_retxUlFile;
  std::string m_retxUlFilename;
};

}

#endif /* RETX_STATS_CALCULATOR_H_ */
