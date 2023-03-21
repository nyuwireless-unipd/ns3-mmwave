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

#ifndef MMWAVE_CHUNK_PROCESSOR_H
#define MMWAVE_CHUNK_PROCESSOR_H

#include <ns3/nstime.h>
#include <ns3/object.h>
#include <ns3/ptr.h>

namespace ns3
{

class SpectrumValue;

namespace mmwave
{

typedef Callback<void, const SpectrumValue&> mmWaveChunkProcessorCallback;

class mmWaveChunkProcessor : public SimpleRefCount<mmWaveChunkProcessor>
{
  public:
    mmWaveChunkProcessor();
    virtual ~mmWaveChunkProcessor();

    virtual void AddCallback(mmWaveChunkProcessorCallback c);

    virtual void Start();

    virtual void EvaluateChunk(const SpectrumValue& sinr, Time duration);

    virtual void End();

  private:
    Ptr<SpectrumValue> m_sumValues;
    Time m_totDuration;

    std::vector<mmWaveChunkProcessorCallback> m_mmWaveChunkProcessorCallbacks;
};

} // namespace mmwave

} // namespace ns3

#endif /* MMWAVE_CHUNK_PROCESSOR_H */
