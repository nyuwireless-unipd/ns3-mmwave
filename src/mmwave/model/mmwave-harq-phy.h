

#ifndef MMWAVE_HARQ_PHY_MODULE_H
#define MMWAVE_HARQ_PHY_MODULE_H



#include <ns3/log.h>
#include <ns3/assert.h>
#include <math.h>
#include <vector>
#include <map>
#include <ns3/simple-ref-count.h>
#include "mmwave-phy-mac-common.h"


namespace ns3 {



struct MmWaveHarqProcessInfoElement_t
{
   double m_mi;
   uint8_t m_rv;
   uint32_t m_infoBits;
   uint32_t m_codeBits;
};

typedef std::vector <MmWaveHarqProcessInfoElement_t> MmWaveHarqProcessInfoList_t;

/**
 * \ingroup MmWave
 * \brief The MmWaveHarqPhy class implements the HARQ functionalities related to PHY layer
 *(i.e., decodification buffers for incremental redundancy managment)
 *
*/
class MmWaveHarqPhy : public SimpleRefCount<MmWaveHarqPhy>
{
public:
  MmWaveHarqPhy (uint32_t harqNum);
  ~MmWaveHarqPhy ();

  void SubframeIndication (SfnSf);

  /**
  * \brief Return the cumulated MI of the HARQ procId in case of retranmissions
  * for DL (asynchronous)
  * \param harqProcId the HARQ proc id
  * \param layer layer no. (for MIMO spatial multiplexing)
  * \return the MI accumulated
  */
  double GetAccumulatedMiDl (uint16_t rnti, uint8_t harqId);

  /**
  * \brief Return the info of the HARQ procId in case of retranmissions
  * for DL (asynchronous)
  * \param harqProcId the HARQ proc id
  * \param layer layer no. (for MIMO spatail multiplexing)
  * \return the vector of the info related to HARQ proc Id
  */
  MmWaveHarqProcessInfoList_t GetHarqProcessInfoDl (uint16_t rnti, uint8_t harqProcId);

  /**
  * \brief Return the cumulated MI of the HARQ procId in case of retranmissions
  * for UL (synchronous)
  * \return the MI accumulated
  */
  double GetAccumulatedMiUl (uint16_t rnti, uint8_t harqId);

  /**
  * \brief Return the info of the HARQ procId in case of retranmissions
  * for UL (asynchronous)
  * \param rnti the RNTI of the transmitter
  * \param harqProcId the HARQ proc id
  * \return the vector of the info related to HARQ proc Id
  */
  MmWaveHarqProcessInfoList_t GetHarqProcessInfoUl (uint16_t rnti, uint8_t harqProcId);

  /**
  * \brief Update the Info associated to the decodification of an HARQ process
  * for DL (asynchronous)
  * \param id the HARQ proc id
  * \param layer layer no. (for MIMO spatail multiplexing)
  * \param mi the new MI
  * \param infoBytes the no. of bytes of info
  * \param mi the total no. of bytes txed
  */
  void UpdateDlHarqProcessStatus (uint16_t rnti, uint8_t id, double mi, uint32_t infoBytes, uint32_t codeBytes);

  /**
  * \brief Reset  the info associated to the decodification of an HARQ process
  * for DL (asynchronous)
  * \param id the HARQ proc id
  */
  void ResetDlHarqProcessStatus(uint16_t rnti, uint8_t id);

  /**
  * \brief Update the MI value associated to the decodification of an HARQ process
  * for DL (asynchronous)
  * \param rnti the RNTI of the transmitter
  * \param mi the new MI
  * \param infoBytes the no. of bytes of info
  * \param mi the total no. of bytes txed
  */
  void UpdateUlHarqProcessStatus (uint16_t rnti, uint8_t harqId, double mi, uint32_t infoBytes, uint32_t codeBytes);

  /**
  * \brief Reset  the info associated to the decodification of an HARQ process
  * for DL (asynchronous)
  * \param id the HARQ proc id
  */
  void ResetUlHarqProcessStatus(uint16_t rnti, uint8_t id);
  

private:

  uint32_t m_harqNum;
  std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> > m_miDlHarqProcessesInfoMap;
  std::map <uint16_t, std::vector <MmWaveHarqProcessInfoList_t> > m_miUlHarqProcessesInfoMap;
  

};


}

#endif /* MMWAVE_HARQ_PHY_MODULE_H */
