

#include "mmwave-chunk-processor.h"

#include <ns3/log.h>
#include <ns3/spectrum-value.h>

NS_LOG_COMPONENT_DEFINE ("mmWaveChunkProcessor");

namespace ns3 {

mmWaveChunkProcessor::mmWaveChunkProcessor ()
{
  NS_LOG_FUNCTION (this);
}

mmWaveChunkProcessor::~mmWaveChunkProcessor ()
{
  NS_LOG_FUNCTION (this);
}

void
mmWaveChunkProcessor::AddCallback (mmWaveChunkProcessorCallback c)
{
  NS_LOG_FUNCTION (this);
  m_mmWaveChunkProcessorCallbacks.push_back (c);
}

void
mmWaveChunkProcessor::Start ()
{
  NS_LOG_FUNCTION (this);
  m_sumValues = 0;
  m_totDuration = MicroSeconds (0);
}


void
mmWaveChunkProcessor::EvaluateChunk (const SpectrumValue& sinr, Time duration)
{
  NS_LOG_FUNCTION (this << sinr << duration);
  if (m_sumValues == 0)
    {
      m_sumValues = Create<SpectrumValue> (sinr.GetSpectrumModel ());
    }
  (*m_sumValues) += sinr * duration.GetSeconds ();
  m_totDuration += duration;
}

void
mmWaveChunkProcessor::End ()
{
	NS_LOG_FUNCTION (this);
	if (m_totDuration.GetSeconds () > 0)
	{
		std::vector<mmWaveChunkProcessorCallback>::iterator it;
		for (it = m_mmWaveChunkProcessorCallbacks.begin (); it != m_mmWaveChunkProcessorCallbacks.end (); it++)
		{
			(*it)((*m_sumValues) / m_totDuration.GetSeconds ());
		}
	}
	else
	{
		NS_LOG_WARN ("m_numSinr == 0");
	}
}


} // namespace ns3
