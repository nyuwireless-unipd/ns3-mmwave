/*
 * mmwave-phy-rx-race.cc
 *
 *  Created on: Feb 2, 2015
 *      Author: macair
 */

#include <ns3/log.h>
#include "mmwave-phy-rx-trace.h"
#include <ns3/simulator.h>
#include <stdio.h>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("mmWavePhyRxTrace");

NS_OBJECT_ENSURE_REGISTERED (mmWavePhyRxTrace);

mmWavePhyRxTrace::mmWavePhyRxTrace()
{

}

mmWavePhyRxTrace::~mmWavePhyRxTrace()
{

}

TypeId
mmWavePhyRxTrace::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::mmWavePhyRxTrace")
    .SetParent<Object> ()
    .AddConstructor<mmWavePhyRxTrace> ()
  ;
  return tid;
}

void
mmWavePhyRxTrace::ReportCurrentCellRsrpSinrCallback (Ptr<mmWavePhyRxTrace> phyStats, std::string path,
																uint64_t imsi, SpectrumValue& sinr, SpectrumValue& power)
{
	NS_LOG_INFO ("UE"<<imsi<<"->Generate RsrpSinrTrace");
	phyStats->ReportInterferenceTrace (imsi, sinr);
	//phyStats->ReportPowerTrace (imsi, power);
}

void
mmWavePhyRxTrace::ReportInterferenceTrace (uint64_t imsi, SpectrumValue& sinr)
{
	uint64_t slot_count = Now().GetMicroSeconds ()/125;
	uint32_t rb_count = 1;
	FILE* log_file;
	char fname[255];
	sprintf(fname, "UE_%llu_SINR_dB.txt", (long long unsigned ) imsi);
	log_file = fopen(fname, "a");
	Values::iterator it = sinr.ValuesBegin();
	while(it!=sinr.ValuesEnd())
	{
		//fprintf(log_file, "%d\t%d\t%f\t \n", slot_count/2, rb_count, 10*log10(*it));
		fprintf(log_file, "%llu\t%llu\t%d\t%f\t \n",slot_count/8+1, slot_count%8+1, rb_count, 10*log10(*it));
		rb_count++;
		it++;
	}
	fflush(log_file);
	fclose(log_file);
}

void
mmWavePhyRxTrace::ReportPowerTrace (uint64_t imsi, SpectrumValue& power)
{

	uint32_t slot_count = Now().GetMicroSeconds ()/125;
	uint32_t rb_count = 1;
	FILE* log_file;
	char fname[255];
	printf (fname, "UE_%llu_ReceivedPower_dB.txt", (long long unsigned) imsi);
	log_file = fopen(fname, "a");
	Values::iterator it = power.ValuesBegin();
	while(it!=power.ValuesEnd())
	{
		fprintf(log_file, "%llu\t%llu\t%d\t%f\t \n",(long long unsigned) slot_count/8+1,(long long unsigned) slot_count%8+1, rb_count, 10*log10(*it));
		rb_count++;
		it++;
	}
	fflush(log_file);
	fclose(log_file);
}

void
mmWavePhyRxTrace::ReportPacketCountUeCallback (Ptr<mmWavePhyRxTrace> phyStats, std::string path,
			UePhyPacketCountParameter param)
{
	phyStats->ReportPacketCountUe (param);
}
void
mmWavePhyRxTrace::ReportPacketCountEnbCallback (Ptr<mmWavePhyRxTrace> phyStats, std::string path,
		EnbPhyPacketCountParameter param)
{
	phyStats->ReportPacketCountEnb (param);
}

void
mmWavePhyRxTrace::ReportDownLinkTBSize (Ptr<mmWavePhyRxTrace> phyStats, std::string path,
		uint64_t imsi, uint64_t tbSize)
{
	phyStats->ReportDLTbSize (imsi, tbSize);
}



void
mmWavePhyRxTrace::ReportPacketCountUe (UePhyPacketCountParameter param)
{
	FILE* log_file;
	char fname[255];
	sprintf (fname,"UE_%llu_Packet_Trace.txt", (long long unsigned) param.m_imsi);
	log_file = fopen (fname, "a");
	if (param.m_isTx)
	{
		fprintf (log_file, "%d\t%d\t%d\n", param.m_subframeno, param.m_noBytes, 0);
	}
	else
	{
		fprintf (log_file, "%d\t%d\t%d\n", param.m_subframeno, 0, param.m_noBytes);
	}

	fflush(log_file);
	fclose(log_file);

}

void
mmWavePhyRxTrace::ReportPacketCountEnb (EnbPhyPacketCountParameter param)
{
	FILE* log_file;
	char fname[255];
	sprintf (fname,"BS_%llu_Packet_Trace.txt",(long long unsigned) param.m_cellId);
	log_file = fopen (fname, "a");
	if (param.m_isTx)
	{
		fprintf (log_file, "%d\t%d\t%d\n", param.m_subframeno, param.m_noBytes, 0);
	}
	else
	{
		fprintf (log_file, "%d\t%d\t%d\n", param.m_subframeno, 0, param.m_noBytes);
	}

	fflush(log_file);
	fclose(log_file);
}

void
mmWavePhyRxTrace::ReportDLTbSize (uint64_t imsi, uint64_t tbSize)
{
	FILE* log_file;
	char fname[255];
	sprintf (fname,"UE_%llu_Tb_Size.txt", (long long unsigned) imsi);
	log_file = fopen (fname, "a");

	fprintf (log_file, "%lld \t %llu \n",(long long int) Now().GetMicroSeconds (), (long long unsigned) tbSize);
	fflush(log_file);
	fclose(log_file);

}

} /* namespace ns3 */
