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



#ifndef SRC_MMWAVE_MODEL_MMWAVE_ENB_NET_DEVICE_H_
#define SRC_MMWAVE_MODEL_MMWAVE_ENB_NET_DEVICE_H_


#include "mmwave-net-device.h"
#include "ns3/event-id.h"
#include "ns3/mac48-address.h"
#include "ns3/traced-callback.h"
#include "ns3/nstime.h"
#include "mmwave-phy.h"
#include "mmwave-enb-phy.h"
#include "mmwave-enb-mac.h"
#include "mmwave-mac-scheduler.h"
#include <vector>
#include <ns3/lte-enb-rrc.h>


namespace ns3{
/* Add forward declarations here */
class Packet;
class PacketBurst;
class Node;
//class MmWavePhy;
class MmWaveEnbPhy;
class MmWaveEnbMac;

class MmWaveEnbNetDevice : public MmWaveNetDevice
{
public:
	static TypeId GetTypeId (void);

	MmWaveEnbNetDevice ();

	virtual ~MmWaveEnbNetDevice (void);
	virtual void DoDispose (void);
	virtual bool DoSend (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber);

    Ptr<MmWaveEnbPhy> GetPhy (void) const;

    uint16_t GetCellId () const;

    uint8_t GetBandwidth () const;

    void SetBandwidth (uint8_t bw);

    void SetEarfcn(uint16_t earfcn);

    uint16_t GetEarfcn() const;

    void SetMac (Ptr<MmWaveEnbMac> mac);

    Ptr<MmWaveEnbMac> GetMac (void);

    void SetRrc (Ptr<LteEnbRrc> rrc);

    Ptr<LteEnbRrc> GetRrc (void);

    void SetAntennaNum (uint8_t antennaNum);

    uint8_t GetAntennaNum () const;

protected:

    virtual void DoInitialize(void);
    void UpdateConfig ();


private:

	Ptr<MmWaveEnbPhy> m_phy;

	Ptr<MmWaveEnbMac> m_mac;

	Ptr<MmWaveMacScheduler> m_scheduler;

	Ptr<LteEnbRrc> m_rrc;

	uint16_t m_cellId; /* Cell Identifer. To uniquely identify an E-nodeB  */

	uint8_t m_Bandwidth; /* bandwidth in RBs (?) */

	uint16_t m_Earfcn;  /* carrier frequency */
	bool m_isConstructed;
	bool m_isConfigured;
	uint8_t m_antennaNum;

};
}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_ENB_NET_DEVICE_H_ */
