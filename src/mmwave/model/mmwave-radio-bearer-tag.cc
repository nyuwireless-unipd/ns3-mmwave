/*
 * mmwave-radio-bearer-tag.cc
 *
 *  Created on: Feb 1, 2015
 *      Author: sourjya
 */

#include "mmwave-radio-bearer-tag.h"
#include "ns3/tag.h"
#include "ns3/uinteger.h"

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (mmWaveRadioBearerTag);

TypeId
mmWaveRadioBearerTag::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::mmWaveRadioBearerTag")
    .SetParent<Tag> ()
    .AddConstructor<mmWaveRadioBearerTag> ()
    .AddAttribute ("imsi", "The imsi that indicates the UE to which packet belongs",
                   UintegerValue (0),
                   MakeUintegerAccessor (&mmWaveRadioBearerTag::GetImsi),
                   MakeUintegerChecker<uint64_t> ())
  ;
  return tid;
}

TypeId
mmWaveRadioBearerTag::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

mmWaveRadioBearerTag::mmWaveRadioBearerTag ()
  : m_imsi (0)
{
}

mmWaveRadioBearerTag::mmWaveRadioBearerTag (uint64_t imsi)
: m_imsi (imsi)
{
}

void
mmWaveRadioBearerTag::SetImsi (uint64_t imsi)
{
  m_imsi = imsi;
}


uint32_t
mmWaveRadioBearerTag::GetSerializedSize (void) const
{
  return 4;
}

void
mmWaveRadioBearerTag::Serialize (TagBuffer i) const
{
  i.WriteU64 (m_imsi);
}

void
mmWaveRadioBearerTag::Deserialize (TagBuffer i)
{
  m_imsi = (uint64_t) i.ReadU64 ();
}

uint64_t
mmWaveRadioBearerTag::GetImsi () const
{
  return m_imsi;
}

void
mmWaveRadioBearerTag::Print (std::ostream &os) const
{
	os << "imsi=" << m_imsi;
}

} // namespace ns3


