


#ifndef MMWAVE_INTERFERENCE_H
#define MMWAVE_INTERFERENCE_H

#include <ns3/object.h>
#include <ns3/packet.h>
#include <ns3/nstime.h>
#include <ns3/spectrum-value.h>
#include <string.h>
#include <ns3/mmwave-chunk-processor.h>


namespace ns3 {

class mmWaveInterference : public Object
{
public:
	mmWaveInterference ();
	virtual ~mmWaveInterference ();
	static TypeId GetTypeId (void);
	virtual void DoDispose ();
	void StartRx (Ptr<const SpectrumValue> rxPsd);
	void EndRx ();
	void AddSignal (Ptr<const SpectrumValue> spd, const Time duration);
	void SetNoisePowerSpectralDensity (Ptr<const SpectrumValue> noisePsd);
	void AddPowerChunkProcessor (Ptr<mmWaveChunkProcessor> p);
	void AddSinrChunkProcessor (Ptr<mmWaveChunkProcessor> p);

private:
	void ConditionallyEvaluateChunk ();
	void DoAddSignal (Ptr<const SpectrumValue> spd);
	void DoSubtractSignal  (Ptr<const SpectrumValue> spd, uint32_t signalId);
	std::list<Ptr<mmWaveChunkProcessor> > m_PowerChunkProcessorList;
	std::list<Ptr<mmWaveChunkProcessor> > m_sinrChunkProcessorList;


	bool m_receiving;

	Ptr<SpectrumValue> m_rxSignal;
	Ptr<SpectrumValue> m_allSignals;
	Ptr<const SpectrumValue> m_noise;

	Time m_lastChangeTime;

	uint32_t m_lastSignalId;
	uint32_t m_lastSignalIdBeforeReset;
};

} // namespace ns3

#endif /* MMWAVE_INTERFERENCE_H */
