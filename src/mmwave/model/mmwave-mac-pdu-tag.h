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



#ifndef MMWAVE_MAC_PDU_TAG_H
#define MMWAVE_MAC_PDU_TAG_H

#include "ns3/packet.h"
#include "ns3/nstime.h"
#include "mmwave-phy-mac-common.h"

namespace ns3 {

namespace mmwave {


struct SfnSf;

class MmWaveMacPduTag : public Tag
{
public:
  static TypeId  GetTypeId (void);
  virtual TypeId  GetInstanceTypeId (void) const;

  /**
   * Create an empty MacP PDU tag
   */
  MmWaveMacPduTag ();

  MmWaveMacPduTag (SfnSf sfn);

  MmWaveMacPduTag (SfnSf sfn, uint8_t symStart, uint8_t numSym);

  virtual void  Serialize (TagBuffer i) const;
  virtual void  Deserialize (TagBuffer i);
  virtual uint32_t  GetSerializedSize () const;
  virtual void Print (std::ostream &os) const;

  SfnSf  GetSfn () const
  {
  	return m_sfnSf;
  }

  void  SetSfn (SfnSf sfn)
  {
  	this->m_sfnSf = sfn;
  }

  uint8_t GetSymStart ()
  {
  	return m_symStart;
  }

  uint8_t GetNumSym ()
  {
  	return m_numSym;
  }

  void SetSymStart (uint8_t symStart)
  {
  	m_symStart = symStart;
  }

  void SetNumSym (uint8_t numSym)
  {
  	m_numSym = numSym;
  }

protected:
  SfnSf m_sfnSf;
  uint8_t m_symStart;
  uint8_t m_numSym;
  uint32_t m_tagSize;
};

} // namespace mmwave

} // namespace ns3

#endif /* MMWAVE_MAC_PDU_TAG_H */
