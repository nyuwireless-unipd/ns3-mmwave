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
*                         Sourjya Dutta <sdutta@nyu.edu>
*                         Russell Ford <russell.ford@nyu.edu>
*                         Menglei Zhang <menglei@nyu.edu>
*/


#include <ns3/log.h>
#include <ns3/packet-burst.h>
#include <ns3/ptr.h>
#include "mmwave-spectrum-signal-parameters.h"
#include "mmwave-control-messages.h"



namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("mmwaveSpectrumSignalParameters");

namespace mmwave {

mmwaveSpectrumSignalParameters::mmwaveSpectrumSignalParameters ()
{
  NS_LOG_FUNCTION (this);
}

mmwaveSpectrumSignalParameters::mmwaveSpectrumSignalParameters (const mmwaveSpectrumSignalParameters& p)
  : SpectrumSignalParameters (p)
{
  NS_LOG_FUNCTION (this << &p);
  packetBurst = p.packetBurst->Copy ();
}

Ptr<SpectrumSignalParameters>
mmwaveSpectrumSignalParameters::Copy ()
{
  NS_LOG_FUNCTION (this);
  // Ideally we would use:
  //   return Copy<mmwaveSpectrumSignalParameters> (*this);
  // but for some reason it doesn't work. Another alternative is
  //   return Copy<mmwaveSpectrumSignalParameters> (this);
  // but it causes a double creation of the object, hence it is less efficient.
  // The solution below is copied from the implementation of Copy<> (Ptr<>) in ptr.h
  Ptr<mmwaveSpectrumSignalParameters> lssp (new mmwaveSpectrumSignalParameters (*this), false);
  return lssp;
}



MmwaveSpectrumSignalParametersDataFrame::MmwaveSpectrumSignalParametersDataFrame ()
{
  NS_LOG_FUNCTION (this);
}

MmwaveSpectrumSignalParametersDataFrame::MmwaveSpectrumSignalParametersDataFrame (const MmwaveSpectrumSignalParametersDataFrame& p)
  : SpectrumSignalParameters (p)
{
  NS_LOG_FUNCTION (this << &p);
  cellId = p.cellId;
  if (p.packetBurst)
    {
      packetBurst = p.packetBurst->Copy ();
    }
  ctrlMsgList = p.ctrlMsgList;
  slotInd = p.slotInd;
}

Ptr<SpectrumSignalParameters>
MmwaveSpectrumSignalParametersDataFrame::Copy ()
{
  NS_LOG_FUNCTION (this);
  // Ideally we would use:
  //   return Copy<MmwaveSpectrumSignalParametersDataFrame> (*this);
  // but for some reason it doesn't work. Another ammwavernative is
  //   return Copy<MmwaveSpectrumSignalParametersDataFrame> (this);
  // but it causes a double creation of the object, hence it is less efficient.
  // The solution below is copied from the implementation of Copy<> (Ptr<>) in ptr.h
  Ptr<MmwaveSpectrumSignalParametersDataFrame> lssp (new MmwaveSpectrumSignalParametersDataFrame (*this), false);
  return lssp;
}



MmWaveSpectrumSignalParametersDlCtrlFrame::MmWaveSpectrumSignalParametersDlCtrlFrame ()
{
  NS_LOG_FUNCTION (this);
}

MmWaveSpectrumSignalParametersDlCtrlFrame::MmWaveSpectrumSignalParametersDlCtrlFrame (const MmWaveSpectrumSignalParametersDlCtrlFrame& p)
  : SpectrumSignalParameters (p)
{
  NS_LOG_FUNCTION (this << &p);
  cellId = p.cellId;
  pss = p.pss;
  ctrlMsgList = p.ctrlMsgList;
}

Ptr<SpectrumSignalParameters>
MmWaveSpectrumSignalParametersDlCtrlFrame::Copy ()
{
  NS_LOG_FUNCTION (this);
  // Ideally we would use:
  //   return Copy<MmWaveSpectrumSignalParametersDlCtrlFrame> (*this);
  // but for some reason it doesn't work. Another alternative is
  //   return Copy<MmWaveSpectrumSignalParametersDlCtrlFrame> (this);
  // but it causes a double creation of the object, hence it is less efficient.
  // The solution below is copied from the implementation of Copy<> (Ptr<>) in ptr.h
  Ptr<MmWaveSpectrumSignalParametersDlCtrlFrame> lssp (new MmWaveSpectrumSignalParametersDlCtrlFrame (*this), false);
  return lssp;
}

}

}
