

#ifndef MMWAVE_CHUNK_PROCESSOR_H
#define MMWAVE_CHUNK_PROCESSOR_H

#include <ns3/ptr.h>
#include <ns3/nstime.h>
#include <ns3/object.h>

namespace ns3 {

class SpectrumValue;

typedef Callback< void, const SpectrumValue& > mmWaveChunkProcessorCallback;

class mmWaveChunkProcessor : public SimpleRefCount<mmWaveChunkProcessor>
{
public:
  mmWaveChunkProcessor ();
  virtual ~mmWaveChunkProcessor ();

  virtual void AddCallback (mmWaveChunkProcessorCallback c);

  virtual void Start ();

  virtual void EvaluateChunk (const SpectrumValue& sinr, Time duration);

  virtual void End ();

private:
  Ptr<SpectrumValue> m_sumValues;
  Time m_totDuration;

  std::vector<mmWaveChunkProcessorCallback> m_mmWaveChunkProcessorCallbacks;
};

} // namespace ns3



#endif /* MMWAVE_CHUNK_PROCESSOR_H */
