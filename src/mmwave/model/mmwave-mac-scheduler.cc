/*
 * mmwave-mac-scheduler.cc
 *
 *  Created on: Jan 10, 2015
 *      Author: sourjya
 */

#include "mmwave-mac-scheduler.h"
#include <ns3/log.h>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("mmWaveMacScheduler");

NS_OBJECT_ENSURE_REGISTERED (mmWaveMacScheduler);

mmWaveMacScheduler::mmWaveMacScheduler ()
{
	NS_LOG_FUNCTION (this);
}

mmWaveMacScheduler::~mmWaveMacScheduler ()
{
	NS_LOG_FUNCTION (this);
}

void
mmWaveMacScheduler::DoDispose (void)
{
	NS_LOG_FUNCTION (this);
}

TypeId
mmWaveMacScheduler::GetTypeId (void)
{
    static TypeId tid = TypeId ("ns3::mmWaveMacScheduler")
    .SetParent<Object> ()
	.AddAttribute ("TimeDivisionDuplexPattern",
			"The pattern in which slots are assigned to UL, DL or Sync",
			StringValue ("ccdddddd"),
			MakeStringAccessor (&mmWaveMacScheduler::m_TDDPattern),
			MakeStringChecker ())
	;

  return tid;
}

/*void
mmWaveMacScheduler::ConfigureCommonParameters (Ptr<mmWavePhyMacCommon> config)
{
	m_PhyMACConfig = config;
}*/

}


