 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab. 
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
 *        	 	  Sourjya Dutta <sdutta@nyu.edu>
 *        	 	  Russell Ford <russell.ford@nyu.edu>
 *        		  Menglei Zhang <menglei@nyu.edu>
 *
 * Modified by: Michele Polese <michele.polese@gmail.com> 
 *                 Dual Connectivity and Handover functionalities
 */


#include <ns3/mmwave-phy-mac-common.h>
#include <ns3/log.h>
#include <ns3/uinteger.h>
#include <ns3/double.h>
#include <ns3/string.h>
#include <ns3/attribute-accessor-helper.h>
#include <ns3/simulator.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE ("MmWavePhyMacCommon");

NS_OBJECT_ENSURE_REGISTERED (MmWavePhyMacCommon);

TypeId
MmWavePhyMacCommon::GetTypeId (void)
{
	static TypeId tid = TypeId("ns3::MmWavePhyMacCommon")
			.SetParent<Object> ()
			.AddConstructor<MmWavePhyMacCommon> ()
			.AddAttribute ("SymbolPerSlot",
						   "Number of symbols per slot",
						   UintegerValue (30),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_symbolsPerSlot),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SymbolsPerSubframe",
							 "OFDM symbols per subframe",
							 UintegerValue (24),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_symbolsPerSubframe),
							 MakeUintegerChecker<uint32_t> ())
			 .AddAttribute ("SubframePeriod",
										 "Symbol period in microseconds",
										 DoubleValue (100.0),
										 MakeDoubleAccessor (&MmWavePhyMacCommon::m_subframePeriod),
										 MakeDoubleChecker<double> ())
		   .AddAttribute ("CtrlSymbols",
							 "Number of OFDM symbols for DL control per subframe",
							 UintegerValue (1),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_ctrlSymbols),
							 MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SymbolPeriod",
						   "Symbol period in microseconds",
						   DoubleValue (4.16),
						   MakeDoubleAccessor (&MmWavePhyMacCommon::m_symbolPeriod),
						   MakeDoubleChecker<double> ())
			.AddAttribute ("SlotsPerSubframe",
						   "Number of slots in one subframe",
						   UintegerValue (8),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_slotsPerSubframe),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SubframePerFrame",
						   "Number of subframe per frame",
						   UintegerValue (10),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_subframesPerFrame),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("SubcarriersPerChunk",
						   "Number of sub-carriers per chunk",
						   UintegerValue (48),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_numSubCarriersPerChunk),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("ChunkPerRB",
						   "Number of chunks comprising a resource block",
						   UintegerValue (72),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_chunksPerRb),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("ChunkWidth",
						   "Width of each chunk in Hz",
						   DoubleValue (13.889e6),
						   MakeDoubleAccessor (&MmWavePhyMacCommon::m_chunkWidth),
						   MakeDoubleChecker<double> ())
			.AddAttribute ("ResourceBlockNum",
						   "Number of resource blocks the entire bandwidth is split into",
						   UintegerValue (1),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_numRb),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("NumReferenceSymbols",
						   "Number of reference symbols per slot",
						   UintegerValue (6),
						   MakeUintegerAccessor (&MmWavePhyMacCommon::m_numRefSymbols),
						   MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("CenterFreq",
						   "The center frequency in Hz",
						   DoubleValue (28e9),
						   MakeDoubleAccessor (&MmWavePhyMacCommon::m_centerFrequency),
						   MakeDoubleChecker<double> ())
			.AddAttribute ("TDDPattern",
						   "The control-data pattern for TDD transmission",
						   StringValue ("ccdddddd"),
						   MakeStringAccessor (&MmWavePhyMacCommon::m_staticTddPattern),
						   MakeStringChecker ())
		  .AddAttribute ("UlSchedDelay",
							 "Number of TTIs between UL scheduling decision and subframe to which it applies",
							 UintegerValue (1),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_ulSchedDelay),
							 MakeUintegerChecker<uint32_t> ())
		  .AddAttribute ("NumRbPerRbg",
							 "Number of resource blocks per resource block group",
							 UintegerValue (1),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_numRbPerRbg),
							 MakeUintegerChecker<uint32_t> ())
			.AddAttribute ("WbCqiPeriod",
							 "Microseconds between wideband DL-CQI reports",
							 DoubleValue (500.0),
							 MakeDoubleAccessor (&MmWavePhyMacCommon::m_wbCqiPeriodUs),
							 MakeDoubleChecker<double> ())
		 .AddAttribute ("GuardPeriod",
							 "Guard period for UL to DL slot transition in microseconds",
							 DoubleValue (4.16),
							 MakeDoubleAccessor (&MmWavePhyMacCommon::m_guardPeriod),
							 MakeDoubleChecker<double> ())
		 .AddAttribute ("NumHarqProcess",
							 "Number of concurrent stop-and-wait Hybrid ARQ processes per user",
							 UintegerValue (20),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_numHarqProcess),
							 MakeUintegerChecker<uint8_t> ())
		 .AddAttribute ("HarqDlTimeout",
							 "Number of concurrent stop-and-wait Hybrid ARQ processes per user",
							 UintegerValue (20),
							 MakeUintegerAccessor (&MmWavePhyMacCommon::m_harqTimeout),
							 MakeUintegerChecker<uint8_t> ())
		 .AddAttribute ("TbDecodeLatency",
									 "Number of concurrent stop-and-wait Hybrid ARQ processes per user",
									 UintegerValue (100.0),
									 MakeUintegerAccessor (&MmWavePhyMacCommon::m_tbDecodeLatencyUs),
									 MakeUintegerChecker<uint32_t> ())
	;

	return tid;
}

MmWavePhyMacCommon::MmWavePhyMacCommon ()
: m_symbolsPerSlot (30),
  m_symbolPeriod (4.16),
  m_symbolsPerSubframe (24),
  m_subframePeriod (100.0),
  m_ctrlSymbols (1),
  m_dlCtrlSymbols (1),
  m_ulCtrlSymbols (1),
  m_slotsPerSubframe (8),
  m_subframesPerFrame (10),
  m_numRefSymbols (6),
	m_numRbPerRbg (1),
  m_numSubCarriersPerChunk (48),
  m_chunksPerRb (72),
  m_numRefScPerRb (6),
  m_numRefScPerSym (864),
  m_chunkWidth (14e6),
  m_numRb (1),
  m_numHarqProcess (20),
  m_harqTimeout (20),
  m_centerFrequency (28e9),
	m_guardPeriod (4.16),
  m_l1L2CtrlLatency (2),
  m_l1L2DataLatency (2),
  m_ulSchedDelay (1),
	m_wbCqiPeriodUs (500.0),
	m_tbDecodeLatencyUs (100.0),
	m_maxTbSizeBytes (0x7FFF)
{
	NS_LOG_INFO ("Initialized MmWavePhyMacCommon");
}

}


