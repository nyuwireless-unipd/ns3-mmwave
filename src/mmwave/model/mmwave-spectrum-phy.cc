/*
 * mmwave-spectrum-phy.cc
 *
 *  Created on: Nov 5, 2014
 *      Author: sourjya
 */

#include <ns3/object-factory.h>
#include <ns3/log.h>
#include <ns3/ptr.h>
#include <cmath>
#include <ns3/simulator.h>
#include <ns3/trace-source-accessor.h>
#include <ns3/antenna-model.h>
#include "mmwave-spectrum-phy.h"
#include "mmwave-phy-mac-common.h"
#include <ns3/mmwave-enb-net-device.h>
#include <ns3/mmwave-ue-net-device.h>
#include <ns3/mmwave-ue-phy.h>
#include "mmwave-radio-bearer-tag.h"
#include <stdio.h>
#include <ns3/double.h>
#include <ns3/mmwave-mi-error-model.h>



namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("mmWaveSpectrumPhy");

NS_OBJECT_ENSURE_REGISTERED (mmWaveSpectrumPhy);

mmWaveSpectrumPhy::mmWaveSpectrumPhy()
	:m_state(IDLE)
{
	m_interferenceData = CreateObject<mmWaveInterference> ();
	m_random = CreateObject<UniformRandomVariable> ();
	m_random->SetAttribute ("Min", DoubleValue (0.0));
	m_random->SetAttribute ("Max", DoubleValue (1.0));
}
mmWaveSpectrumPhy::~mmWaveSpectrumPhy()
{

}

TypeId
mmWaveSpectrumPhy::GetTypeId(void)
{
	static TypeId
		tid =
	    TypeId ("ns3::mmWaveSpectrumPhy")
	    .SetParent<NetDevice> ()
		.AddTraceSource ("ReportEnbTxRxPacketCount",
						 "The no. of packets received and transmitted by the Base Station",
						 MakeTraceSourceAccessor (&mmWaveSpectrumPhy::m_reportEnbPacketCount))
		.AddTraceSource ("ReportUeTxRxPacketCount",
						 "The no. of packets received and transmitted by the User Device",
						 MakeTraceSourceAccessor (&mmWaveSpectrumPhy::m_reportUePacketCount))

		;

	return tid;
}
void
mmWaveSpectrumPhy::DoDispose()
{

}

void
mmWaveSpectrumPhy::SetDevice(Ptr<NetDevice> d)
{
	m_device = d;
}

Ptr<NetDevice>
mmWaveSpectrumPhy::GetDevice()
{
	return m_device;
}

void
mmWaveSpectrumPhy::SetMobility (Ptr<MobilityModel> m)
{
	m_mobility = m;
}

Ptr<MobilityModel>
mmWaveSpectrumPhy::GetMobility ()
{
	return m_mobility;
}

void
mmWaveSpectrumPhy::SetChannel (Ptr<SpectrumChannel> c)
{
	m_channel = c;
}

Ptr<const SpectrumModel>
mmWaveSpectrumPhy::GetRxSpectrumModel () const
{
	return m_rxSpectrumModel;
}

Ptr<AntennaModel>
mmWaveSpectrumPhy::GetRxAntenna ()
{
	return m_anetnna;
}

void
mmWaveSpectrumPhy::SetAntenna (Ptr<AntennaModel> a)
{
	m_anetnna = a;
}

void
mmWaveSpectrumPhy::SetNoisePowerSpectralDensity(Ptr<const SpectrumValue> noisePsd)
{
	NS_LOG_FUNCTION (this << noisePsd);
	NS_ASSERT (noisePsd);
	m_rxSpectrumModel = noisePsd->GetSpectrumModel ();
	m_interferenceData->SetNoisePowerSpectralDensity (noisePsd);

}

void
mmWaveSpectrumPhy::SetTxPowerSpectralDensity (Ptr<SpectrumValue> TxPsd)
{
	m_txPsd = TxPsd;
}

void
mmWaveSpectrumPhy::SetmmWavePhyRxDataEndOkCallback (mmWavePhyRxDataEndOkCallback c)
{
	m_mmWavePhyRxDataEndOkCallback = c;
}

void
mmWaveSpectrumPhy::AddExpectedTb (uint16_t rnti, uint16_t size, uint8_t mcs, std::vector<int> map, bool downlink)
{
	//tbId.m_layer = layer;
	expectedTbs_t::iterator it;
	it = m_expectedTbs.find (rnti);
	if (it != m_expectedTbs.end ())
	{
		m_expectedTbs.erase (it);
	}
	// insert new entry
	tbInfo_t tbInfo = {size, mcs, map, downlink, false};
	m_expectedTbs.insert (std::pair<uint16_t, tbInfo_t> (rnti,tbInfo));
}


void
mmWaveSpectrumPhy::StartRx (Ptr<SpectrumSignalParameters> params)
{

	NS_LOG_FUNCTION(this);

	Ptr<mmWaveEnbNetDevice> EnbTx =
			DynamicCast<mmWaveEnbNetDevice> (params->txPhy->GetDevice ());
	Ptr<mmWaveEnbNetDevice> EnbRx =
			DynamicCast<mmWaveEnbNetDevice> (GetDevice ());
	if((EnbTx != 0 && EnbRx != 0) || (EnbTx == 0 && EnbRx == 0))
	{
		NS_LOG_INFO ("BS to BS or UE to UE transmission neglected.");
		return;
	}

	Ptr<mmwaveSpectrumSignalParametersDataFrame> mmwaveDataRxParams =
			DynamicCast<mmwaveSpectrumSignalParametersDataFrame> (params);

	if (mmwaveDataRxParams!=0)
	{
		bool isAllocated = true;
		Ptr<mmWaveUeNetDevice> UeRx = DynamicCast<mmWaveUeNetDevice> (GetDevice ());

		if ((UeRx!=0) && (UeRx->GetPhy ()->IsReceptionEnabled () == false))
		{
			isAllocated = false;
		}

		if (isAllocated)
		{
			if(mmwaveDataRxParams->cellId == m_cellId)
			{
				m_interferenceData->AddSignal (mmwaveDataRxParams->psd, mmwaveDataRxParams->duration);
				StartRxData (mmwaveDataRxParams);
			}
			else
			{
				if (UeRx != 0)
				{
					m_interferenceData->AddSignal (mmwaveDataRxParams->psd, mmwaveDataRxParams->duration);
				}
			}
		}
	}
	else
	{
		Ptr<mmwaveSpectrumSignalParametersDlCtrlFrame> DlCtrlRxParams =
				DynamicCast<mmwaveSpectrumSignalParametersDlCtrlFrame> (params);
		if (DlCtrlRxParams!=0)
		{
			if (DlCtrlRxParams->cellId == m_cellId)
			{
				StartRxControl (params);
			}
			else
			{
				// Do nothing
			}
		}
	}
}

void
mmWaveSpectrumPhy::StartRxData (Ptr<mmwaveSpectrumSignalParametersDataFrame> params)
{
	m_interferenceData->StartRx (params->psd);

	NS_LOG_FUNCTION(this);

	Ptr<mmWaveEnbNetDevice> EnbRx =
				DynamicCast<mmWaveEnbNetDevice> (GetDevice ());
	Ptr<mmWaveUeNetDevice> UeRx =
				DynamicCast<mmWaveUeNetDevice> (GetDevice ());
	switch(m_state)
	{
	case TX:
		NS_FATAL_ERROR("Cannot receive while transmitting");
		break;

	case RX:
	case IDLE:
	{
#if 0
		if (UeRx /*&& (params->psd/params->duration > 0)*/ ) //Need to discuss the limit
		{
			/* Process the control messages for the User*/
			UeRx->GetPhy ()->ReceivemmWaveControlMessageList (params->ctrlMsgList, params->cellId);
		}
#endif

		if (params->cellId == m_cellId)
		{
			m_state = RX;

			if (m_rxPacketBurstList.empty())
			{
				Simulator::Schedule (params->duration, &mmWaveSpectrumPhy::EndRxData, this);
			}

			if (params->packetBurst)
			{
				m_rxPacketBurstList.push_back (params->packetBurst);
			}

			/* This section is used for trace */
			if (EnbRx)
			{
				EnbPhyPacketCountParameter traceParam;
				traceParam.m_noBytes = (params->packetBurst)?params->packetBurst->GetSize ():0;
				traceParam.m_cellId = params->cellId;
				traceParam.m_isTx = false;
				traceParam.m_subframeno = EnbRx->GetPhy ()->GetAbsoulteSubframeNo ();
				m_reportEnbPacketCount (traceParam);
			}
			else if (UeRx)
			{
				UePhyPacketCountParameter traceParam;
				traceParam.m_noBytes = (params->packetBurst)?params->packetBurst->GetSize ():0;
				traceParam.m_imsi = UeRx->GetImsi ();
				traceParam.m_isTx = false;
				traceParam.m_subframeno = UeRx->GetPhy ()->GetAbsoulteSubframeNo ();
				m_reportUePacketCount (traceParam);
			}
			/**********************************/
		}
	}
	break;
	default:
		NS_FATAL_ERROR("Programming Error: Unknown State");
	}
}

void
mmWaveSpectrumPhy::StartRxControl (Ptr<SpectrumSignalParameters> params)
{
	NS_LOG_FUNCTION (this);
	switch (m_state)
	{
	case TX:
	{
		NS_FATAL_ERROR ("Already transmitting or receiving");
		break;
	}
	case RX:
	case IDLE:
	{
		m_state = RX;
		Ptr<mmwaveSpectrumSignalParametersDlCtrlFrame> DlCtrlRxParams =
					DynamicCast<mmwaveSpectrumSignalParametersDlCtrlFrame> (params);
		Ptr<mmWaveUePhy> uePhy;
		if ( GetDevice ()->GetObject <mmWaveUeNetDevice> ())
		{
			uePhy = GetDevice ()->GetObject <mmWaveUeNetDevice> ()->GetPhy ();
		}

		if (uePhy != 0)
		{
			uePhy->ReceivemmWaveControlMessageList (DlCtrlRxParams->ctrlMsgList, DlCtrlRxParams->cellId);
		}
		else
		{
			Ptr<mmWaveEnbPhy> enbPhy = GetDevice ()->GetObject <mmWaveEnbNetDevice> ()->GetPhy ();
			enbPhy->PhyCtrlMessageReceived (DlCtrlRxParams->ctrlMsgList);

		}
		Simulator::Schedule (params->duration, &mmWaveSpectrumPhy::EndRxCtrl, this);
		break;
	}
	default:
	{
	    NS_FATAL_ERROR ("unknown state");
	    break;
	}
	}
}

void
mmWaveSpectrumPhy::EndRxData ()
{
	m_interferenceData->EndRx();

	NS_ASSERT(m_state = RX);
	expectedTbs_t::iterator itTb = m_expectedTbs.begin ();
	while (itTb!=m_expectedTbs.end ())
	{
        TbStats_t tbStats = mmWaveMiErrorModel::GetTbDecodificationStats (m_sinrPerceived,
        								(*itTb).second.rbBitmap, (*itTb).second.size, (*itTb).second.mcs);
        (*itTb).second.corrupt = m_random->GetValue () > tbStats.tbler ? false : true;
		itTb++;
	}


	for (std::list<Ptr<PacketBurst> >::const_iterator i = m_rxPacketBurstList.begin ();
		 i != m_rxPacketBurstList.end (); ++i)
	{
		for (std::list<Ptr<Packet> >::const_iterator j = (*i)->Begin (); j != (*i)->End (); ++j)
		{
			LteRadioBearerTag tag;
			(*j)->PeekPacketTag (tag);
			uint16_t rnti = tag.GetRnti ();
			itTb = m_expectedTbs.find (rnti);
			if(itTb != m_expectedTbs.end ())
			{
				if (!(*itTb).second.corrupt)
				{
					m_mmWavePhyRxDataEndOkCallback (*j);
				}
				else
				{
					//Drop Packet
					Time t =  Simulator::Now ();
					//NS_LOG_UNCOND (t.GetSeconds());
				}
			}
			else
			{
				NS_FATAL_ERROR ("End of the tbMap");
			}
		}
	}


	m_state = IDLE;
	m_rxPacketBurstList.clear ();
	m_expectedTbs.clear ();

}

void
mmWaveSpectrumPhy::EndRxCtrl ()
{
	NS_ASSERT(m_state = RX);
	m_state = IDLE;

}

bool
mmWaveSpectrumPhy::StartTxDataFrames (Ptr<PacketBurst> pb, std::list<Ptr<mmWaveControlMessages> > ctrlMsgList, Time duration)
{
	switch (m_state)
	{
	case RX:
		NS_FATAL_ERROR ("cannot TX while RX: Cannot transmit while receiving");
		break;
	case TX:
		NS_FATAL_ERROR ("cannot TX while already Tx: Cannot transmit while a transmission is still on");
		break;
	case IDLE:
	{
		NS_ASSERT(m_txPsd);

		m_state = TX;
		Ptr<mmwaveSpectrumSignalParametersDataFrame> txParams = new mmwaveSpectrumSignalParametersDataFrame ();
		txParams->duration = duration;
		txParams->txPhy = GetObject<SpectrumPhy> ();
		txParams->psd = m_txPsd;
		txParams->packetBurst = pb;
		txParams->cellId = m_cellId;
		txParams->ctrlMsgList = ctrlMsgList;

		/* This section is used for trace */

		Ptr<mmWaveEnbNetDevice> EnbRx =
					DynamicCast<mmWaveEnbNetDevice> (GetDevice ());
		Ptr<mmWaveUeNetDevice> UeRx =
					DynamicCast<mmWaveUeNetDevice> (GetDevice ());
		if (EnbRx)
		{
			EnbPhyPacketCountParameter traceParam;
			traceParam.m_noBytes = (txParams->packetBurst)?txParams->packetBurst->GetSize ():0;
			traceParam.m_cellId = txParams->cellId;
			traceParam.m_isTx = true;
			traceParam.m_subframeno = EnbRx->GetPhy ()->GetAbsoulteSubframeNo ();
			m_reportEnbPacketCount (traceParam);
		}
		else if (UeRx)
		{
			UePhyPacketCountParameter traceParam;
			traceParam.m_noBytes = (txParams->packetBurst)?txParams->packetBurst->GetSize ():0;
			traceParam.m_imsi = UeRx->GetImsi ();
			traceParam.m_isTx = true;
			traceParam.m_subframeno = UeRx->GetPhy ()->GetAbsoulteSubframeNo ();
			m_reportUePacketCount (traceParam);
		}
		/**********************************/

		m_channel->StartTx (txParams);

		Simulator::Schedule (duration, &mmWaveSpectrumPhy::EndTx, this);
	}
	break;
	default:
		NS_LOG_FUNCTION (this<<"Programming Error. Code should not reach this point");
	}
	return true;
}

bool
mmWaveSpectrumPhy::StartTxDlControlFrames (std::list<Ptr<mmWaveControlMessages> > ctrlMsgList, Time duration)
{
	NS_LOG_LOGIC (this << " state: " << m_state);

	switch (m_state)
	{
	case RX:
		NS_FATAL_ERROR ("cannot TX while RX: Cannot transmit while receiving");
		break;
	case TX:
		NS_FATAL_ERROR ("cannot TX while already Tx: Cannot transmit while a transmission is still on");
		break;
	case IDLE:
	{
		NS_ASSERT(m_txPsd);

		m_state = TX;

		Ptr<mmwaveSpectrumSignalParametersDlCtrlFrame> txParams = Create<mmwaveSpectrumSignalParametersDlCtrlFrame> ();
		txParams->duration = duration;
		txParams->txPhy = GetObject<SpectrumPhy> ();
		txParams->psd = m_txPsd;
		txParams->cellId = m_cellId;
		txParams->pss = true;
		txParams->ctrlMsgList = ctrlMsgList;
		m_channel->StartTx (txParams);
		Simulator::Schedule (duration, &mmWaveSpectrumPhy::EndTx, this);
	}
	}
	return false;
}

void
mmWaveSpectrumPhy::EndTx()
{
	NS_ASSERT (m_state == TX);

	m_state = IDLE;
}

Ptr<SpectrumChannel>
mmWaveSpectrumPhy::GetSpectrumChannel ()
{
	return m_channel;
}

void
mmWaveSpectrumPhy::SetCellId (uint16_t cellId)
{
	m_cellId = cellId;
}


void
mmWaveSpectrumPhy::AddDataPowerChunkProcessor (Ptr<mmWaveChunkProcessor> p)
{
	m_interferenceData->AddPowerChunkProcessor (p);
}

void
mmWaveSpectrumPhy::AddDataSinrChunkProcessor (Ptr<mmWaveChunkProcessor> p)
{
	m_interferenceData->AddSinrChunkProcessor (p);
}

void
mmWaveSpectrumPhy::UpdateSinrPerceived (const SpectrumValue& sinr)
{
	NS_LOG_FUNCTION (this << sinr);
	m_sinrPerceived = sinr;
}


}
