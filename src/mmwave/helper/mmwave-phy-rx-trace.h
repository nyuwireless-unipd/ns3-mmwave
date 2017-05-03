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
 *        	 	  Sourjya Dutta <sdutta@nyu.edu>
 *        	 	  Russell Ford <russell.ford@nyu.edu>
 *        		  Menglei Zhang <menglei@nyu.edu>
 */


#ifndef SRC_MMWAVE_HELPER_MMWAVE_PHY_RX_TRACE_H_
#define SRC_MMWAVE_HELPER_MMWAVE_PHY_RX_TRACE_H_
#include <ns3/object.h>
#include <ns3/spectrum-value.h>
#include <ns3/mmwave-phy-mac-common.h>
#include <fstream>
#include <iostream>

namespace ns3 {

class MmWavePhyRxTrace : public Object
{
public:
	MmWavePhyRxTrace();
	virtual ~MmWavePhyRxTrace();
	static TypeId GetTypeId (void);
	static void ReportCurrentCellRsrpSinrCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path,
						uint64_t imsi, SpectrumValue& sinr, SpectrumValue& power);
	static void ReportPacketCountUeCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path,
			UePhyPacketCountParameter param);
	static void ReportPacketCountEnbCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path,
			EnbPhyPacketCountParameter param);
	static void ReportDownLinkTBSize (Ptr<MmWavePhyRxTrace> phyStats, std::string path,
			uint64_t imsi, uint64_t tbSize);
	static void RxPacketTraceUeCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path, RxPacketTraceParams param);
	static void RxPacketTraceEnbCallback (Ptr<MmWavePhyRxTrace> phyStats, std::string path, RxPacketTraceParams param);

private:
	//void ReportInterferenceTrace (uint64_t imsi, SpectrumValue& sinr);
	//void ReportPacketCountUe (UePhyPacketCountParameter param);
	//void ReportPacketCountEnb (EnbPhyPacketCountParameter param);
	//void ReportDLTbSize (uint64_t imsi, uint64_t tbSize);

	static std::ofstream m_rxPacketTraceFile;
	static std::string m_rxPacketTraceFilename;
};

} /* namespace ns3 */

#endif /* SRC_MMWAVE_HELPER_MMWAVE_PHY_RX_TRACE_H_ */
