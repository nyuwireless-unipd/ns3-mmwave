#include "adaptive-a2-a4-rsrq-handover-algorithm.h"

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED(AdaptiveA2A4RsrqHandoverAlgorithm);

TypeId AdaptiveA2A4RsrqHandoverAlgorithm::GetTypeId(void)
{
  static TypeId tid = TypeId("ns3::AdaptiveA2A4RsrqHandoverAlgorithm")
    .SetParent<A2A4RsrqHandoverAlgorithm>()
    .SetGroupName("Lte")
    .AddConstructor<AdaptiveA2A4RsrqHandoverAlgorithm>();
  return tid;
}

AdaptiveA2A4RsrqHandoverAlgorithm::AdaptiveA2A4RsrqHandoverAlgorithm()
  : m_defaultThreshold(30) 
{}

AdaptiveA2A4RsrqHandoverAlgorithm::~AdaptiveA2A4RsrqHandoverAlgorithm()
{}

void AdaptiveA2A4RsrqHandoverAlgorithm::SetServingCellThresholdForCell(uint16_t cellId, uint8_t threshold)
{
  m_thresholdPerCell[cellId] = threshold;
}

uint8_t AdaptiveA2A4RsrqHandoverAlgorithm::GetServingCellThresholdForCell(uint16_t cellId) const
{
  auto it = m_thresholdPerCell.find(cellId);
  if (it != m_thresholdPerCell.end())
    return it->second;
  return m_defaultThreshold;
}

uint8_t AdaptiveA2A4RsrqHandoverAlgorithm::GetServingCellThreshold(uint16_t cellId) const
{
  return GetServingCellThresholdForCell(cellId);
}

void
AdaptiveA2A4RsrqHandoverAlgorithm::UpdateThresholds(ns3::NodeContainer ueNodes)
{
  std::map<uint16_t, uint32_t> uePerCell;

  for (uint32_t i = 0; i < ueNodes.GetN(); ++i)
    {
      Ptr<NetDevice> ueDevice = ueNodes.Get(i)->GetDevice(0);
      Ptr<LteUeNetDevice> lteUeDev = DynamicCast<LteUeNetDevice>(ueDevice);
      if (lteUeDev && lteUeDev->GetRrc())
        {
          uint16_t cellId = lteUeDev->GetRrc()->GetCellId();
          uePerCell[cellId]++;
        }
    }

  for (auto& kv : uePerCell)
    {
      uint16_t cellId = kv.first;
      uint32_t count = kv.second;

      if (count > 13)
        {
          SetServingCellThresholdForCell(cellId, 20);  // нагрузка ↑ → снижаем порог
        }
      else
        {
          SetServingCellThresholdForCell(cellId, 30);  // нагрузка ↓ → возвращаем
        }

      NS_LOG_UNCOND("Time: " << Simulator::Now().GetSeconds()
                     << "s, CellId: " << cellId
                     << ", UE count: " << count
                     << ", Threshold: " << GetServingCellThreshold(cellId));
    }
}


} 


