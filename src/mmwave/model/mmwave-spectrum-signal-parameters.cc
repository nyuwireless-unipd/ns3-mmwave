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

#include "mmwave-spectrum-signal-parameters.h"

#include "mmwave-control-messages.h"

#include <ns3/log.h>
#include <ns3/packet-burst.h>
#include <ns3/ptr.h>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("mmwaveSpectrumSignalParameters");

namespace mmwave
{

mmwaveSpectrumSignalParameters::mmwaveSpectrumSignalParameters()
{
    NS_LOG_FUNCTION(this);
}

mmwaveSpectrumSignalParameters::mmwaveSpectrumSignalParameters(
    const mmwaveSpectrumSignalParameters& p)
    : SpectrumSignalParameters(p)
{
    NS_LOG_FUNCTION(this << &p);
    packetBurst = p.packetBurst->Copy();
}

Ptr<SpectrumSignalParameters>
mmwaveSpectrumSignalParameters::Copy() const
{
    NS_LOG_FUNCTION(this);

    return Create<mmwaveSpectrumSignalParameters>(*this);
}

MmwaveSpectrumSignalParametersDataFrame::MmwaveSpectrumSignalParametersDataFrame()
{
    NS_LOG_FUNCTION(this);
}

MmwaveSpectrumSignalParametersDataFrame::MmwaveSpectrumSignalParametersDataFrame(
    const MmwaveSpectrumSignalParametersDataFrame& p)
    : SpectrumSignalParameters(p)
{
    NS_LOG_FUNCTION(this << &p);
    cellId = p.cellId;
    if (p.packetBurst)
    {
        packetBurst = p.packetBurst->Copy();
    }
    ctrlMsgList = p.ctrlMsgList;
    slotInd = p.slotInd;
}

Ptr<SpectrumSignalParameters>
MmwaveSpectrumSignalParametersDataFrame::Copy() const
{
    NS_LOG_FUNCTION(this);

    return Create<MmwaveSpectrumSignalParametersDataFrame>(*this);
}

MmWaveSpectrumSignalParametersDlCtrlFrame::MmWaveSpectrumSignalParametersDlCtrlFrame()
{
    NS_LOG_FUNCTION(this);
}

MmWaveSpectrumSignalParametersDlCtrlFrame::MmWaveSpectrumSignalParametersDlCtrlFrame(
    const MmWaveSpectrumSignalParametersDlCtrlFrame& p)
    : SpectrumSignalParameters(p)
{
    NS_LOG_FUNCTION(this << &p);
    cellId = p.cellId;
    pss = p.pss;
    ctrlMsgList = p.ctrlMsgList;
}

Ptr<SpectrumSignalParameters>
MmWaveSpectrumSignalParametersDlCtrlFrame::Copy() const
{
    NS_LOG_FUNCTION(this);

    return Create<MmWaveSpectrumSignalParametersDlCtrlFrame>(*this);
}

} // namespace mmwave

} // namespace ns3
