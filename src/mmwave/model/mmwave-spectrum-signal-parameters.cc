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

#include <ns3/log.h>
#include <ns3/packet-burst.h>
#include <ns3/ptr.h>
#include "mmwave-spectrum-signal-parameters.h"
#include "mmwave-control-messages.h"



namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("mmwaveSpectrumSignalParameters");

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



mmwaveSpectrumSignalParametersDataFrame::mmwaveSpectrumSignalParametersDataFrame ()
{
  NS_LOG_FUNCTION (this);
}

mmwaveSpectrumSignalParametersDataFrame::mmwaveSpectrumSignalParametersDataFrame (const mmwaveSpectrumSignalParametersDataFrame& p)
: SpectrumSignalParameters (p)
{
  NS_LOG_FUNCTION (this << &p);
  cellId = p.cellId;
  if (p.packetBurst)
    {
      packetBurst = p.packetBurst->Copy ();
    }
  ctrlMsgList = p.ctrlMsgList;
}

Ptr<SpectrumSignalParameters>
mmwaveSpectrumSignalParametersDataFrame::Copy ()
{
  NS_LOG_FUNCTION (this);
  // Ideally we would use:
  //   return Copy<mmwaveSpectrumSignalParametersDataFrame> (*this);
  // but for some reason it doesn't work. Another ammwavernative is
  //   return Copy<mmwaveSpectrumSignalParametersDataFrame> (this);
  // but it causes a double creation of the object, hence it is less efficient.
  // The solution below is copied from the implementation of Copy<> (Ptr<>) in ptr.h
  Ptr<mmwaveSpectrumSignalParametersDataFrame> lssp (new mmwaveSpectrumSignalParametersDataFrame (*this), false);
  return lssp;
}



mmwaveSpectrumSignalParametersDlCtrlFrame::mmwaveSpectrumSignalParametersDlCtrlFrame ()
{
  NS_LOG_FUNCTION (this);
}

mmwaveSpectrumSignalParametersDlCtrlFrame::mmwaveSpectrumSignalParametersDlCtrlFrame (const mmwaveSpectrumSignalParametersDlCtrlFrame& p)
: SpectrumSignalParameters (p)
{
  NS_LOG_FUNCTION (this << &p);
  cellId = p.cellId;
  pss = p.pss;
  ctrlMsgList = p.ctrlMsgList;
}

Ptr<SpectrumSignalParameters>
mmwaveSpectrumSignalParametersDlCtrlFrame::Copy ()
{
  NS_LOG_FUNCTION (this);
  // Ideally we would use:
  //   return Copy<mmwaveSpectrumSignalParametersDlCtrlFrame> (*this);
  // but for some reason it doesn't work. Another alternative is
  //   return Copy<mmwaveSpectrumSignalParametersDlCtrlFrame> (this);
  // but it causes a double creation of the object, hence it is less efficient.
  // The solution below is copied from the implementation of Copy<> (Ptr<>) in ptr.h
  Ptr<mmwaveSpectrumSignalParametersDlCtrlFrame> lssp (new mmwaveSpectrumSignalParametersDlCtrlFrame (*this), false);
  return lssp;
}

}
