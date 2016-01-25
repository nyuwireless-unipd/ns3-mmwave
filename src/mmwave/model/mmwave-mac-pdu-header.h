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
  uint32_t  m_size;		// 22 bits
};

class MmWaveMacPduHeader : public Header
{
public:
  static TypeId  GetTypeId (void);
  virtual TypeId  GetInstanceTypeId (void) const;

  /**
   * Create an empty Mac header
   */
  MmWaveMacPduHeader ();

  MmWaveMacPduHeader (uint16_t frameNo, uint8_t sfNo, uint8_t slotNo);

  virtual void  Serialize (Buffer::Iterator i) const;
  virtual uint32_t  Deserialize (Buffer::Iterator i);
  virtual uint32_t  GetSerializedSize () const;
  virtual void Print (std::ostream &os) const;
  void  AddSubheader (MacSubheader rlcPduInfo);

  void SetSubheaders (std::vector<MacSubheader> macSubheaderList)
  {
  	m_subheaderList = macSubheaderList;
  }

	std::vector<MacSubheader> GetSubheaders (void)
  {
		return m_subheaderList;
  }

protected:
  std::vector<MacSubheader> m_subheaderList;
  uint32_t m_headerSize;
};

} //namespace ns3

#endif /* MMWAVE_MAC_PDU_HEADER_H */
