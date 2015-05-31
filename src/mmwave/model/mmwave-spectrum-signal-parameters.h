/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 CTTC
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
 * Author: Nicola Baldo <nbaldo@cttc.es>
 * Modified by Marco Miozzo <mmiozzo@cttc.es> (add data and ctrl diversity)
 */

#ifndef MMWAVE_SPECTRUM_SIGNAL_PARAMETERS_H
#define MMWAVE_SPECTRUM_SIGNAL_PARAMETERS_H


#include <ns3/spectrum-signal-parameters.h>

namespace ns3 {

class PacketBurst;
class mmWaveControlMessages;

/**
 * \ingroup mmwave
 *
 * Signal parameters for mmwave
 */
struct mmwaveSpectrumSignalParameters : public SpectrumSignalParameters
{

  // inherited from SpectrumSignalParameters
  virtual Ptr<SpectrumSignalParameters> Copy ();

  /**
   * default constructor
   */
  mmwaveSpectrumSignalParameters ();

  /**
   * copy constructor
   */
  mmwaveSpectrumSignalParameters (const mmwaveSpectrumSignalParameters& p);

  Ptr<PacketBurst> packetBurst;

};



struct mmwaveSpectrumSignalParametersDataFrame : public SpectrumSignalParameters
{
  
  // inherited from SpectrumSignalParameters
  virtual Ptr<SpectrumSignalParameters> Copy ();
  
  /**
  * default constructor
  */
  mmwaveSpectrumSignalParametersDataFrame ();
  
  /**
  * copy constructor
  */
  mmwaveSpectrumSignalParametersDataFrame (const mmwaveSpectrumSignalParametersDataFrame& p);
  
  Ptr<PacketBurst> packetBurst;

  std::list<Ptr<mmWaveControlMessages> > ctrlMsgList;
  
  uint16_t cellId;
};


struct mmwaveSpectrumSignalParametersDlCtrlFrame : public SpectrumSignalParameters
{
  
  // inherited from SpectrumSignalParameters
  virtual Ptr<SpectrumSignalParameters> Copy ();
  
  /**
  * default constructor
  */
  mmwaveSpectrumSignalParametersDlCtrlFrame ();
  
  /**
  * copy constructor
  */
  mmwaveSpectrumSignalParametersDlCtrlFrame (const mmwaveSpectrumSignalParametersDlCtrlFrame& p);
  

  std::list<Ptr<mmWaveControlMessages> > ctrlMsgList;

  bool pss;
  uint16_t cellId;
};


}  // namespace ns3


#endif /* MMWAVE_SPECTRUM_SIGNAL_PARAMETERS_H */
