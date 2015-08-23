
#include <ns3/mmwave-harq-phy.h>
#include <ns3/log.h>
#include <ns3/assert.h>

NS_LOG_COMPONENT_DEFINE ("MmWaveHarqPhy");

namespace ns3 {

//NS_OBJECT_ENSURE_REGISTERED (MmWaveHarqPhy)
//  ;


MmWaveHarqPhy::MmWaveHarqPhy (uint32_t harqNum)
{
	m_harqNum = harqNum;
	// Create DL Decodification HARQ buffers
	std::vector <HarqProcessInfoList_t> dlHarqLayer0;
	dlHarqLayer0.resize (m_harqNum);
	std::vector <HarqProcessInfoList_t> dlHarqLayer1;
	dlHarqLayer1.resize (m_harqNum);
	m_miDlHarqProcessesInfoMap.push_back (dlHarqLayer0);
	m_miDlHarqProcessesInfoMap.push_back (dlHarqLayer1);
	NS_LOG_DEBUG ("m_miDlHarqProcessesInfoMap size == " << m_miDlHarqProcessesInfoMap.size());

}


MmWaveHarqPhy::~MmWaveHarqPhy ()
{
  m_miDlHarqProcessesInfoMap.clear ();
  m_miUlHarqProcessesInfoMap.clear ();
}

void
MmWaveHarqPhy::SubframeIndication (uint32_t frameNo, uint32_t subframeNo)
{
  NS_LOG_FUNCTION (this);

  // left shift UL HARQ buffers
  std::map <uint16_t, std::vector <HarqProcessInfoList_t> >:: iterator it;
  for (it = m_miUlHarqProcessesInfoMap.begin (); it != m_miUlHarqProcessesInfoMap.end (); it++)
    {
      (*it).second.erase ((*it).second.begin ());
      HarqProcessInfoList_t h;
      (*it).second.push_back (h);      
    }

}


double
MmWaveHarqPhy::GetAccumulatedMiDl (uint8_t harqProcId, uint8_t layer)
{
  NS_LOG_FUNCTION (this << (uint32_t)harqProcId << (uint16_t)layer);
  HarqProcessInfoList_t list = m_miDlHarqProcessesInfoMap.at (layer).at (harqProcId);
  double mi = 0.0;
  for (uint8_t i = 0; i < list.size (); i++)
    {
      mi += list.at (i).m_mi;
    }
  return (mi);
}

HarqProcessInfoList_t
MmWaveHarqPhy::GetHarqProcessInfoDl (uint8_t harqProcId, uint8_t layer)
{
  NS_LOG_FUNCTION (this << (uint32_t)harqProcId << (uint16_t)layer);
  return (m_miDlHarqProcessesInfoMap.at (layer).at (harqProcId));   
}


double
MmWaveHarqPhy::GetAccumulatedMiUl (uint16_t rnti)
{
  NS_LOG_FUNCTION (this << rnti);

  std::map <uint16_t, std::vector <HarqProcessInfoList_t> >::iterator it;
  it = m_miUlHarqProcessesInfoMap.find (rnti);
  NS_ASSERT_MSG (it!=m_miUlHarqProcessesInfoMap.end (), " Does not find MI for RNTI");
  HarqProcessInfoList_t list = (*it).second.at (0);
  double mi = 0.0;
  for (uint8_t i = 0; i < list.size (); i++)
    {
      mi += list.at (i).m_mi;
    }
  return (mi);
}

HarqProcessInfoList_t
MmWaveHarqPhy::GetHarqProcessInfoUl (uint16_t rnti, uint8_t harqProcId)
{
  NS_LOG_FUNCTION (this << rnti << (uint16_t)harqProcId);
  std::map <uint16_t, std::vector <HarqProcessInfoList_t> >::iterator it;
  it = m_miUlHarqProcessesInfoMap.find (rnti);
  if (it==m_miUlHarqProcessesInfoMap.end ())
    {
      // new entry
      std::vector <HarqProcessInfoList_t> harqList;
      harqList.resize (m_harqNum);
      m_miUlHarqProcessesInfoMap.insert (std::pair <uint16_t, std::vector <HarqProcessInfoList_t> > (rnti, harqList));
      return (harqList.at (harqProcId));
    }
  else
    {
      return ((*it).second.at (harqProcId));
    }
}



void
MmWaveHarqPhy::UpdateDlHarqProcessStatus (uint8_t id, uint8_t layer, double mi, uint16_t infoBytes, uint16_t codeBytes)
{
  NS_LOG_FUNCTION (this << (uint16_t) id << mi);
  if (m_miDlHarqProcessesInfoMap.at (layer).at (id).size () == 3)  // MAX HARQ RETX
    {
      // HARQ should be disabled -> discard info
      return;
    }
  HarqProcessInfoElement_t el;
  el.m_mi = mi;
  el.m_infoBits = infoBytes * 8;
  el.m_codeBits = codeBytes * 8;
  m_miDlHarqProcessesInfoMap.at (layer).at (id).push_back (el);
}


void
MmWaveHarqPhy::ResetDlHarqProcessStatus (uint8_t id)
{
  NS_LOG_FUNCTION (this << (uint16_t) id);

  for (unsigned int i = 0; i < m_miDlHarqProcessesInfoMap.size (); i++)
  {
//  	if(!m_miDlHarqProcessesInfoMap.at (i).at (id).empty())
  	{
//  		m_miDlHarqProcessesInfoMap.at (i).at (id).clear ();
  	}
  }
	NS_LOG_DEBUG ("m_miDlHarqProcessesInfoMap size == " << m_miDlHarqProcessesInfoMap.size());

}


void
MmWaveHarqPhy::UpdateUlHarqProcessStatus (uint16_t rnti, double mi, uint16_t infoBytes, uint16_t codeBytes)
{
  NS_LOG_FUNCTION (this << rnti << mi);
  std::map <uint16_t, std::vector <HarqProcessInfoList_t> >::iterator it;
  it = m_miUlHarqProcessesInfoMap.find (rnti);
  if (it==m_miUlHarqProcessesInfoMap.end ())
    {
      // new entry
      std::vector <HarqProcessInfoList_t> harqList;
      harqList.resize (m_harqNum);
      HarqProcessInfoElement_t el;
      el.m_mi = mi;
      el.m_infoBits = infoBytes * 8;
      el.m_codeBits = codeBytes * 8;
      harqList.at (m_harqNum-1).push_back (el);
      m_miUlHarqProcessesInfoMap.insert (std::pair <uint16_t, std::vector <HarqProcessInfoList_t> > (rnti, harqList));
    }
  else
    {
      if ((*it).second.at (m_harqNum-1).size () == 3) // MAX HARQ RETX
        {
          // HARQ should be disabled -> discard info
          return;
        }
      HarqProcessInfoElement_t el;
      el.m_mi = mi;
      el.m_infoBits = infoBytes * 8;
      el.m_codeBits = codeBytes * 8;
      (*it).second.at (m_harqNum-1).push_back (el);
    }
}

void
MmWaveHarqPhy::ResetUlHarqProcessStatus (uint16_t rnti, uint8_t id)
{
  NS_LOG_FUNCTION (this << rnti << (uint16_t)id);
  std::map <uint16_t, std::vector <HarqProcessInfoList_t> >::iterator it;
  it = m_miUlHarqProcessesInfoMap.find (rnti);
  if (it==m_miUlHarqProcessesInfoMap.end ())
    {
      // new entry
      std::vector <HarqProcessInfoList_t> harqList;
      harqList.resize (m_harqNum);
      m_miUlHarqProcessesInfoMap.insert (std::pair <uint16_t, std::vector <HarqProcessInfoList_t> > (rnti, harqList));
    }
  else
    {
      (*it).second.at (id).clear ();
    }
}




} // end namespace
