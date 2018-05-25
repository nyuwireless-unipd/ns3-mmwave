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



#ifndef SRC_MMWAVE_MODEL_MMWAVE_PHY_SAP_H_
#define SRC_MMWAVE_MODEL_MMWAVE_PHY_SAP_H_

#include <ns3/packet-burst.h>
#include <ns3/mmwave-phy-mac-common.h>
#include <ns3/mmwave-mac-sched-sap.h>

namespace ns3 {

namespace mmwave {

class MmWaveControlMessage;
/* Mac to Phy comm*/
class MmWavePhySapProvider
{
public:
	virtual ~MmWavePhySapProvider ();

	virtual void SendMacPdu (Ptr<Packet> p ) = 0;

	virtual void SendControlMessage (Ptr<MmWaveControlMessage> msg) = 0;

	virtual void SendRachPreamble(uint8_t PreambleId, uint8_t Rnti) = 0;

	virtual void SetDlSfAllocInfo (SfAllocInfo sfAllocInfo) = 0;

	virtual void SetUlSfAllocInfo (SfAllocInfo sfAllocInfo) = 0;
};

/* Phy to Mac comm */
class MmWaveEnbPhySapUser
{
public:
	virtual ~MmWaveEnbPhySapUser ()
	{
	}

  /**
   * Called by the Phy to notify the MAC of the reception of a new PHY-PDU
   *
   * \param p
   */
	virtual void ReceivePhyPdu (Ptr<Packet> p) = 0;

  /**
   * \brief Receive SendLteControlMessage (PDCCH map, CQI feedbacks) using the ideal control channel
   * \param msg the Ideal Control Message to receive
   */
	virtual void ReceiveControlMessage (Ptr<MmWaveControlMessage> msg) = 0;

  /**
   * \brief Trigger the start from a new frame (input from Phy layer)
   * \param frameNo frame number
   * \param subframeNo subframe number
   */
	virtual void SubframeIndication (SfnSf) = 0;

  /**
   * \brief Returns to MAC level the UL-CQI evaluated
   * \param ulcqi the UL-CQI (see FF MAC API 4.3.29)
   */
	virtual void UlCqiReport (MmWaveMacSchedSapProvider::SchedUlCqiInfoReqParameters ulcqi) = 0;

	/**
	 * notify the reception of a RACH preamble on the PRACH
	 *
	 * \param prachId the ID of the preamble
	 */
	virtual void ReceiveRachPreamble (uint32_t raId) = 0;

	/**
	 * Notify the HARQ on the UL tranmission status
	 *
	 * \param params
	 */
  virtual void UlHarqFeedback (UlHarqInfo params) = 0;
};

class MmWaveUePhySapUser
{
public:
	virtual ~MmWaveUePhySapUser ()
	{
	}

  /**
   * Called by the Phy to notify the MAC of the reception of a new PHY-PDU
   *
   * \param p
   */
	virtual void ReceivePhyPdu (Ptr<Packet> p) = 0;

	/**
	 * \brief Receive SendLteControlMessage (PDCCH map, CQI feedbacks) using the ideal control channel
	 * \param msg the Ideal Control Message to receive
	 */
	virtual void ReceiveControlMessage (Ptr<MmWaveControlMessage> msg) = 0;

  /**
   * \brief Trigger the start from a new frame (input from Phy layer)
   * \param frameNo frame number
   * \param subframeNo subframe number
   */
	virtual void SubframeIndication (SfnSf) = 0;

	/**
	 * When PHY connects to a new eNB, update the configuration parameters
	 */
	virtual void SetConfigurationParameters(Ptr<MmWavePhyMacCommon> params) = 0;

	//virtual void NotifyHarqDeliveryFailure (uint8_t harqId) = 0;
};

}

}



#endif /* SRC_MMWAVE_MODEL_MMWAVE_PHY_SAP_H_ */
