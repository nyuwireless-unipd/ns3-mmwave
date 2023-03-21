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

#include "mmwave-interference.h"

#include "mmwave-chunk-processor.h"

#include <ns3/log.h>
#include <ns3/simulator.h>

#include <stdio.h>

NS_LOG_COMPONENT_DEFINE("mmWaveInterference");

namespace ns3
{

namespace mmwave
{

mmWaveInterference::mmWaveInterference()
    : m_receiving(false),
      m_lastSignalId(0),
      m_lastSignalIdBeforeReset(0)
{
    NS_LOG_FUNCTION(this);
}

mmWaveInterference::~mmWaveInterference()
{
    NS_LOG_FUNCTION(this);
}

void
mmWaveInterference::DoDispose()
{
    NS_LOG_FUNCTION(this);
    m_PowerChunkProcessorList.clear();
    m_sinrChunkProcessorList.clear();
    m_rxSignal = 0;
    m_allSignals = 0;
    m_noise = 0;
    Object::DoDispose();
}

TypeId
mmWaveInterference::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::mmWaveInterference").SetParent<Object>();
    return tid;
}

void
mmWaveInterference::StartRx(Ptr<const SpectrumValue> rxPsd)
{
    NS_LOG_FUNCTION(this << *rxPsd);
    if (m_receiving == false)
    {
        NS_LOG_LOGIC("first signal");
        m_rxSignal = rxPsd->Copy();
        m_lastChangeTime = Now();
        m_receiving = true;
        for (std::list<Ptr<mmWaveChunkProcessor>>::const_iterator it =
                 m_PowerChunkProcessorList.begin();
             it != m_PowerChunkProcessorList.end();
             ++it)
        {
            (*it)->Start();
        }
        for (std::list<Ptr<mmWaveChunkProcessor>>::const_iterator it =
                 m_sinrChunkProcessorList.begin();
             it != m_sinrChunkProcessorList.end();
             ++it)
        {
            (*it)->Start();
        }
    }
    else
    {
        NS_LOG_LOGIC("additional signal" << *m_rxSignal);
        // receiving multiple simultaneous signals, make sure they are synchronized
        NS_ASSERT(m_lastChangeTime == Now());
        // make sure they use orthogonal resource blocks
        NS_ASSERT(Sum((*rxPsd) * (*m_rxSignal)) == 0.0);
        (*m_rxSignal) += (*rxPsd);
    }
}

void
mmWaveInterference::EndRx()
{
    NS_LOG_FUNCTION(this);
    if (m_receiving != true)
    {
        NS_LOG_INFO("EndRx was already evaluated or RX was aborted");
    }
    else
    {
        ConditionallyEvaluateChunk();
        m_receiving = false;
        for (std::list<Ptr<mmWaveChunkProcessor>>::const_iterator it =
                 m_PowerChunkProcessorList.begin();
             it != m_PowerChunkProcessorList.end();
             ++it)
        {
            (*it)->End();
        }
        for (std::list<Ptr<mmWaveChunkProcessor>>::const_iterator it =
                 m_sinrChunkProcessorList.begin();
             it != m_sinrChunkProcessorList.end();
             ++it)
        {
            (*it)->End();
        }
    }
}

void
mmWaveInterference::AddSignal(Ptr<const SpectrumValue> spd, const Time duration)
{
    NS_LOG_FUNCTION(this << *spd << duration);
    DoAddSignal(spd);
    uint32_t signalId = ++m_lastSignalId;
    if (signalId == m_lastSignalIdBeforeReset)
    {
        // This happens when m_lastSignalId eventually wraps around. Given that so
        // many signals have elapsed since the last reset, we hope that by now there is
        // no stale pending signal (i.e., a signal that was scheduled
        // for subtraction before the reset). So we just move the
        // boundary further.
        m_lastSignalIdBeforeReset += 0x10000000;
    }
    Simulator::Schedule(duration, &mmWaveInterference::DoSubtractSignal, this, spd, signalId);
}

void
mmWaveInterference::DoAddSignal(Ptr<const SpectrumValue> spd)
{
    NS_LOG_FUNCTION(this << *spd);
    ConditionallyEvaluateChunk();
    (*m_allSignals) += (*spd);
}

void
mmWaveInterference::DoSubtractSignal(Ptr<const SpectrumValue> spd, uint32_t signalId)
{
    NS_LOG_FUNCTION(this << *spd);
    ConditionallyEvaluateChunk();
    int32_t deltaSignalId = signalId - m_lastSignalIdBeforeReset;
    if (deltaSignalId > 0)
    {
        (*m_allSignals) -= (*spd);
    }
    else
    {
        NS_LOG_INFO("ignoring signal scheduled for subtraction before last reset");
    }
}

void
mmWaveInterference::ConditionallyEvaluateChunk()
{
    NS_LOG_FUNCTION(this);
    if (m_receiving)
    {
        NS_LOG_DEBUG(this << " Receiving");
    }
    NS_LOG_DEBUG(this << " now " << Now() << " last " << m_lastChangeTime);
    if (m_receiving && (Now() > m_lastChangeTime))
    {
        NS_LOG_LOGIC(this << " signal = " << *m_rxSignal << " allSignals = " << *m_allSignals
                          << " noise = " << *m_noise);
        SpectrumValue interf = (*m_allSignals) - (*m_rxSignal) + (*m_noise);
        SpectrumValue sinr = (*m_rxSignal) / interf;
        Time duration = Now() - m_lastChangeTime;
        for (std::list<Ptr<mmWaveChunkProcessor>>::const_iterator it =
                 m_PowerChunkProcessorList.begin();
             it != m_PowerChunkProcessorList.end();
             ++it)
        {
            (*it)->EvaluateChunk(*m_rxSignal, duration);
        }
        for (std::list<Ptr<mmWaveChunkProcessor>>::const_iterator it =
                 m_sinrChunkProcessorList.begin();
             it != m_sinrChunkProcessorList.end();
             ++it)
        {
            (*it)->EvaluateChunk(sinr, duration);
        }
        m_lastChangeTime = Now();
    }
}

void
mmWaveInterference::SetNoisePowerSpectralDensity(Ptr<const SpectrumValue> noisePsd)
{
    NS_LOG_FUNCTION(this << *noisePsd);
    ConditionallyEvaluateChunk();
    m_noise = noisePsd;
    m_allSignals = Create<SpectrumValue>(noisePsd->GetSpectrumModel());
    if (m_receiving == true)
    {
        // abort rx
        m_receiving = false;
    }
    m_lastSignalIdBeforeReset = m_lastSignalId;
}

void
mmWaveInterference::AddPowerChunkProcessor(Ptr<mmWaveChunkProcessor> p)
{
    NS_LOG_FUNCTION(this << p);
    m_PowerChunkProcessorList.push_back(p);
}

void
mmWaveInterference::AddSinrChunkProcessor(Ptr<mmWaveChunkProcessor> p)
{
    NS_LOG_FUNCTION(this << p);
    m_sinrChunkProcessorList.push_back(p);
}

} // namespace mmwave

} // namespace ns3
