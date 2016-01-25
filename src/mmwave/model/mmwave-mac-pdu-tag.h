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

  MmWaveMacPduTag (SfnSf sfn, uint8_t symStart, uint8_t numSym);

  virtual void  Serialize (TagBuffer i) const;
  virtual void  Deserialize (TagBuffer i);
  virtual uint32_t  GetSerializedSize () const;
  virtual void Print (std::ostream &os) const;

  SfnSf  GetSfn () const
  {
  	return m_sfnSf;
  }

  void  SetSfn (SfnSf sfn)
  {
  	this->m_sfnSf = sfn;
  }

  uint8_t GetSymStart ()
  {
  	return m_symStart;
  }

  uint8_t GetNumSym ()
  {
  	return m_numSym;
  }

  void SetSymStart (uint8_t symStart)
  {
  	m_symStart = symStart;
  }

  void SetNumSym (uint8_t numSym)
  {
  	m_numSym = numSym;
  }

protected:
  SfnSf m_sfnSf;
  uint8_t m_symStart;
  uint8_t m_numSym;
  uint32_t m_tagSize;
};

} //namespace ns3

#endif /* MMWAVE_MAC_PDU_TAG_H */
