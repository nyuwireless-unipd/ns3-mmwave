/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */

#ifndef MMWAVE_MAC_PDU_HEADER_H
#define MMWAVE_MAC_PDU_HEADER_H

#include "ns3/packet.h"
#include "ns3/nstime.h"

namespace ns3 {

class Tag;

struct MacSubheader
{
	MacSubheader (uint8_t lcid, uint16_t size) :
		m_lcid (lcid), m_size (size)
	{
	}

	uint32_t GetSize ()
	{
		if (m_size > 127)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}

  uint8_t   m_lcid;
  uint16_t  m_size;
};

class MmWaveMacPduHeader : public Header
{
public:
  static TypeId  GetTypeId (void);
  virtual TypeId  GetInstanceTypeId (void) const;

  /**
   * Create an empty MacP PDU tag
   */
  MmWaveMacPduHeader ();

  MmWaveMacPduHeader (uint16_t frameNo, uint8_t sfNo, uint8_t slotNo);

  virtual void  Serialize (Buffer::Iterator i) const;
  virtual uint32_t  Deserialize (Buffer::Iterator i);
  virtual uint32_t  GetSerializedSize () const;
  virtual void Print (std::ostream &os) const;
  void  AddSubheader (MacSubheader rlcPduInfo);

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

  void SetSubheaders (std::vector<MacSubheader> macSubheaderList)
  {
  	m_subheaderList = macSubheaderList;
  }

	std::vector<MacSubheader> GetSubheaders (void)
  {
		return m_subheaderList;
  }

protected:
  uint8_t m_frameNum;
  uint8_t m_sfNum;
  uint8_t m_slotNum;
  std::vector<MacSubheader> m_subheaderList;
  uint32_t m_headerSize;
};

} //namespace ns3

#endif /* MMWAVE_MAC_PDU_HEADER_H */
