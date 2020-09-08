/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
*   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
*   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
*   Copyright (c) 2016, 2018, University of Padova, Dep. of Information Engineering, SIGNET lab.
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
*                         Sourjya Dutta <sdutta@nyu.edu>
*                         Russell Ford <russell.ford@nyu.edu>
*                         Menglei Zhang <menglei@nyu.edu>
*
*        Modified by: Tommaso Zugno <tommasozugno@gmail.com>
*								 Integration of Carrier Aggregation
*/



#ifndef SRC_MMWAVE_MODEL_MMWAVE_ENB_NET_DEVICE_H_
#define SRC_MMWAVE_MODEL_MMWAVE_ENB_NET_DEVICE_H_


#include "mmwave-net-device.h"
#include "ns3/event-id.h"
#include "ns3/traced-callback.h"
#include "ns3/nstime.h"
#include "mmwave-phy.h"
#include "mmwave-enb-phy.h"
#include "mmwave-enb-mac.h"
#include "mmwave-mac-scheduler.h"
#include <vector>
#include <map>
#include <ns3/lte-enb-rrc.h>


namespace ns3 {
/* Add forward declarations here */
class Packet;
class PacketBurst;
class Node;
class LteEnbComponentCarrierManager;

namespace mmwave {
//class MmWavePhy;
class MmWaveEnbPhy;
class MmWaveEnbMac;

class MmWaveEnbNetDevice : public MmWaveNetDevice
{
public:
  static TypeId GetTypeId (void);

  MmWaveEnbNetDevice ();

  virtual ~MmWaveEnbNetDevice (void);
  virtual void DoDispose (void) override;
  virtual bool DoSend (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber) override;

  Ptr<MmWaveEnbPhy> GetPhy (void) const;

  Ptr<MmWaveEnbPhy> GetPhy (uint8_t index);

  uint16_t GetCellId () const;

  bool HasCellId (uint16_t cellId) const;

  uint8_t GetBandwidth () const;

  void SetBandwidth (uint8_t bw);

  Ptr<MmWaveEnbMac> GetMac (void);

  Ptr<MmWaveEnbMac> GetMac (uint8_t index);

  void SetRrc (Ptr<LteEnbRrc> rrc);

  Ptr<LteEnbRrc> GetRrc (void);

  void SetCcMap (std::map< uint8_t, Ptr<MmWaveComponentCarrier> > ccm) override;

protected:
  virtual void DoInitialize (void) override;
  void UpdateConfig ();


private:
  Ptr<MmWaveMacScheduler> m_scheduler;

  Ptr<LteEnbRrc> m_rrc;

  uint16_t m_cellId;       /* Cell Identifer. To uniquely identify an E-nodeB  */

  uint8_t m_Bandwidth;       /* bandwidth in RBs (?) */

  Ptr<LteEnbComponentCarrierManager> m_componentCarrierManager; ///< the component carrier manager of this eNb

  bool m_isConfigured;

};
}
}


#endif /* SRC_MMWAVE_MODEL_MMWAVE_ENB_NET_DEVICE_H_ */
