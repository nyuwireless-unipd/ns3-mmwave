/*
 * mmwave-radio-bearer-tag.h
 *
 *  Created on: Feb 1, 2015
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_RADIO_BEARER_TAG_H_
#define SRC_MMWAVE_MODEL_MMWAVE_RADIO_BEARER_TAG_H_


#include "ns3/tag.h"

namespace ns3 {

class Tag;


/**
 * Tag used to define the RNTI and LC id for each MAC packet trasmitted
 */

class mmWaveRadioBearerTag : public Tag
{
public:
	static TypeId GetTypeId (void);
	virtual TypeId GetInstanceTypeId (void) const;

	/**
	* Create an empty LteRadioBearerTag
	*/
	mmWaveRadioBearerTag ();

	/**
	* Create a LteRadioBearerTag with the given RNTI and LC id
	*/
	mmWaveRadioBearerTag (uint64_t  imsi);
	/**
	* Set the IMSI to the given value.
	*
	* @param rnti the value of the IMSI to set
	*/
	void SetImsi (uint64_t  imsi);


	virtual void Serialize (TagBuffer i) const;
	virtual void Deserialize (TagBuffer i);
	virtual uint32_t GetSerializedSize () const;
	virtual void Print (std::ostream &os) const;

	uint64_t GetImsi (void) const;

	private:
	uint64_t  m_imsi;
};



} // namespace ns3



#endif /* SRC_MMWAVE_MODEL_MMWAVE_RADIO_BEARER_TAG_H_ */
