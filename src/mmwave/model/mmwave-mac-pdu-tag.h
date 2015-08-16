/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */

#ifndef MMWAVE_MAC_PDU_TAG_H
#define MMWAVE_MAC_PDU_TAG_H

#include "ns3/packet.h"
#include "ns3/nstime.h"

namespace ns3 {

class MmWaveMacPduTag : public Tag
{
public:
  static TypeId  GetTypeId (void);
  virtual TypeId  GetInstanceTypeId (void) const;

  /**
   * Create an empty MacP PDU tag
   */
  MmWaveMacPduTag ();

  MmWaveMacPduTag (uint16_t frameNo, uint8_t sfNo, uint8_t slotNo);

  virtual void  Serialize (TagBuffer i) const;
  virtual void  Deserialize (TagBuffer i);
  virtual uint32_t  GetSerializedSize () const;
  virtual void Print (std::ostream &os) const;

  uint16_t  GetFrameNum (void) const
  {
  	return m_frameNum;
  }

  void  SetFrameNum (uint16_t frameNum)
  {
  	this->m_frameNum = frameNum;
  }

  uint8_t  GetSubframeNum (void) const
  {
    return m_sfNum;
  }

  void  SetSubframeNum (uint8_t sfNum)
  {
    this->m_sfNum = sfNum;
  }

  uint8_t  GetSlotNum (void) const
  {
    return m_slotNum;
  }

  void  SetSlotNum (uint8_t slotNum)
  {
    this->m_slotNum = slotNum;
  }


protected:
  uint8_t m_frameNum;
  uint8_t m_sfNum;
  uint8_t m_slotNum;
  uint32_t m_tagSize;
};

} //namespace ns3

#endif /* MMWAVE_MAC_PDU_TAG_H */
