#ifndef ADAPTIVE_A2A4_RSRQ_HANDOVER_ALGORITHM_H
#define ADAPTIVE_A2A4_RSRQ_HANDOVER_ALGORITHM_H

#include "ns3/a2-a4-rsrq-handover-algorithm.h"
#include "ns3/node-container.h"
#include "ns3/lte-ue-net-device.h"
#include "ns3/lte-ue-rrc.h"
#include "ns3/log.h"
#include <map>

namespace ns3 {

class AdaptiveA2A4RsrqHandoverAlgorithm : public A2A4RsrqHandoverAlgorithm
{
public:
  static TypeId GetTypeId(void);

  AdaptiveA2A4RsrqHandoverAlgorithm();
  virtual ~AdaptiveA2A4RsrqHandoverAlgorithm();

  void SetServingCellThresholdForCell(uint16_t cellId, uint8_t threshold);
  uint8_t GetServingCellThresholdForCell(uint16_t cellId) const;

  uint8_t GetServingCellThreshold(uint16_t cellId) const;  // без override
  
  void UpdateThresholds(ns3::NodeContainer ueNodes);  // новый метод

private:
  uint8_t m_defaultThreshold;
  std::map<uint16_t, uint8_t> m_thresholdPerCell;
};

} // namespace ns3

#endif /* ADAPTIVE_A2A4_RSRQ_HANDOVER_ALGORITHM_H */


