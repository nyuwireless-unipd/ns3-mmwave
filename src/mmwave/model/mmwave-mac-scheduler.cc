/*
 * mmwave-mac-scheduler.cc
 *
 *  Created on: Jan 10, 2015
 *      Author: sourjya
 */

#include "mmwave-mac-scheduler.h"
#include <ns3/log.h>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("MmWaveMacScheduler");

NS_OBJECT_ENSURE_REGISTERED (MmWaveMacScheduler);

MmWaveMacScheduler::MmWaveMacScheduler ()
{
	NS_LOG_FUNCTION (this);
}

MmWaveMacScheduler::~MmWaveMacScheduler ()
{
	NS_LOG_FUNCTION (this);
}

void
MmWaveMacScheduler::DoDispose (void)
{
	NS_LOG_FUNCTION (this);
}

TypeId
MmWaveMacScheduler::GetTypeId (void)
{
    static TypeId tid = TypeId ("ns3::MmWaveMacScheduler")
    .SetParent<Object> ();

  return tid;
}

/*void
MmWaveMacScheduler::ConfigureCommonParameters (Ptr<MmWavePhyMacCommon> config)
{
	m_phyMacConfig = config;
}*/

}


