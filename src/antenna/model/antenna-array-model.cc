/*
 * antenna-array.cc
 *
 *  Created on: Feb 17, 2015
 *      Author: macair
 */

#include "antenna-array-model.h"
#include <ns3/log.h>

NS_LOG_COMPONENT_DEFINE ("AntennaArrayModel");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (AntennaArrayModel);

AntennaArrayModel::AntennaArrayModel()
{

}

AntennaArrayModel::~AntennaArrayModel()
{

}

TypeId
AntennaArrayModel::GetTypeId ()
{
	static TypeId tid = TypeId ("ns3::AntennaArrayModel")
	.SetParent<Object> ()
	.AddConstructor<AntennaArrayModel> ()
	;
	return tid;
}

double
AntennaArrayModel::GetGainDb (Angles a)
{
  return 0.0;
}

void
AntennaArrayModel::SetBeamformingVector (complexVector_t antennaWeights, Ptr<NetDevice> device)
{
	if (device != 0)
	{
		std::map< Ptr<NetDevice>, complexVector_t >::iterator iter = m_beamformingVectorMap.find (device);
		if (iter != m_beamformingVectorMap.end ())
		{
			m_beamformingVectorMap.erase (iter);
		}
		m_beamformingVectorMap.insert (std::make_pair (device, antennaWeights) );
	}
	m_beamformingVector = antennaWeights;
}

void
AntennaArrayModel::ChangeBeamformingVector (Ptr<NetDevice> device)
{
	std::map< Ptr<NetDevice>, complexVector_t >::iterator it = m_beamformingVectorMap.find (device);
	NS_ASSERT_MSG (it != m_beamformingVectorMap.end (), "could not find");
	m_beamformingVector = it->second;
}

complexVector_t
AntennaArrayModel::GetBeamformingVector ()
{
	return m_beamformingVector;
}

complexVector_t
AntennaArrayModel::GetBeamformingVector (Ptr<NetDevice> device)
{
	complexVector_t weights;
	std::map< Ptr<NetDevice>, complexVector_t >::iterator it = m_beamformingVectorMap.find (device);
	if (it != m_beamformingVectorMap.end ())
	{
		weights = it->second;
	}
	else
	{
		weights = m_beamformingVector;
	}
	return weights;
}


} /* namespace ns3 */
