/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */

#ifndef MMWAVE_MAC_PDU_TAG_H
#define MMWAVE_MAC_PDU_TAG_H

#include "ns3/packet.h"
#include "ns3/nstime.h"
#include "mmwave-phy-mac-common.h"

namespace ns3 {

struct SfnSf;

class MmWaveMacPduTag : public Tag
{
public:
  static TypeId  GetTypeId (void);
  virtual TypeId  GetInstanceTypeId (void) const;

  /**
   * Create an empty MacP PDU tag
   */
  MmWaveMacPduTag ();

  MmWaveMacPduTag (SfnSf sfn);

  virtual void  Serialize (TagBuffer i) const;
  virtual void  Deserialize (TagBuffer i);
  virtual uint32_t  GetSerializedSize () const;
  virtual void Print (std::ostream &os) const;

  SfnSf  GetSfn (void) const
  {
  	return m_sfnSf;
  }

  void  SetSfn (SfnSf sfn)
  {
  	this->m_sfnSf = sfn;
  }

protected:
  SfnSf m_sfnSf;
  uint32_t m_tagSize;
};

} //namespace ns3

#endif /* MMWAVE_MAC_PDU_TAG_H */
