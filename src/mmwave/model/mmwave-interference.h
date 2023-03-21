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

#ifndef MMWAVE_INTERFERENCE_H
#define MMWAVE_INTERFERENCE_H

#include <ns3/mmwave-chunk-processor.h>
#include <ns3/nstime.h>
#include <ns3/object.h>
#include <ns3/packet.h>
#include <ns3/spectrum-value.h>

#include <string.h>

namespace ns3
{

namespace mmwave
{

class mmWaveInterference : public Object
{
  public:
    mmWaveInterference();
    virtual ~mmWaveInterference();
    static TypeId GetTypeId(void);
    virtual void DoDispose() override;
    void StartRx(Ptr<const SpectrumValue> rxPsd);
    void EndRx();
    void AddSignal(Ptr<const SpectrumValue> spd, const Time duration);
    void SetNoisePowerSpectralDensity(Ptr<const SpectrumValue> noisePsd);
    void AddPowerChunkProcessor(Ptr<mmWaveChunkProcessor> p);
    void AddSinrChunkProcessor(Ptr<mmWaveChunkProcessor> p);

  private:
    void ConditionallyEvaluateChunk();
    void DoAddSignal(Ptr<const SpectrumValue> spd);
    void DoSubtractSignal(Ptr<const SpectrumValue> spd, uint32_t signalId);
    std::list<Ptr<mmWaveChunkProcessor>> m_PowerChunkProcessorList;
    std::list<Ptr<mmWaveChunkProcessor>> m_sinrChunkProcessorList;

    bool m_receiving;

    Ptr<SpectrumValue> m_rxSignal;
    Ptr<SpectrumValue> m_allSignals;
    Ptr<const SpectrumValue> m_noise;

    Time m_lastChangeTime;

    uint32_t m_lastSignalId;
    uint32_t m_lastSignalIdBeforeReset;
};

} // namespace mmwave

} // namespace ns3

#endif /* MMWAVE_INTERFERENCE_H */
