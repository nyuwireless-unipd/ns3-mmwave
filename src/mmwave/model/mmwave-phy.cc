/*
 * mmwave-phy.cc
 *
 *  Created on: Nov 5, 2014
 *      Author: sourjya
 */

#include <ns3/simulator.h>
#include <ns3/callback.h>
#include <ns3/node.h>
#include <ns3/packet.h>
#include <ns3/log.h>
#include "mmwave-phy.h"
#include <sstream>
#include "mmwave-phy-sap.h"


namespace ns3{

NS_LOG_COMPONENT_DEFINE ("mmWavePhy");

NS_OBJECT_ENSURE_REGISTERED ( mmWavePhy);

/*   SAP   */
class MembermmWavePhySapProvider : public mmWavePhySapProvider
{
public:
	MembermmWavePhySapProvider (mmWavePhy* phy);

	virtual void SendMacPdu (Ptr<PacketBurst> p );

	virtual void SendmmWaveControlMessage (Ptr<mmWaveControlMessages> msg);

	virtual void SendRachPreamble(uint8_t PreambleId, uint8_t Rnti);
private:
	mmWavePhy* m_phy;
};

MembermmWavePhySapProvider::MembermmWavePhySapProvider (mmWavePhy* phy)
:m_phy(phy)
{
	/* Nothing more to do*/
}

void
MembermmWavePhySapProvider::SendMacPdu (Ptr<PacketBurst> pb)
{
	m_phy->SetMacData (pb);
}

void
MembermmWavePhySapProvider::SendmmWaveControlMessage (Ptr<mmWaveControlMessages> msg)
{
	m_phy->SetControlMessages(msg); //May need to change
}

void
MembermmWavePhySapProvider::SendRachPreamble(uint8_t PreambleId, uint8_t Rnti)
{
	m_phy->SendRachPreamble (PreambleId, Rnti);
}
/* ======= */

TypeId
mmWavePhy::GetTypeId ()
{
	static TypeId
	    tid =
	    TypeId ("ns3::mmWavePhy")
	    .SetParent<Object> ()
	;

	return tid;
}

mmWavePhy::mmWavePhy()
{
	NS_LOG_FUNCTION (this);
	NS_FATAL_ERROR ("This constructor should not be called");
}

mmWavePhy::mmWavePhy(Ptr<mmWaveSpectrumPhy> dlChannelPhy, Ptr<mmWaveSpectrumPhy> ulChannelPhy)
	:m_downlinkSpectrumPhy(dlChannelPhy),
	 m_uplinkSpectrumPhy(ulChannelPhy),
	 m_cellId(0)
{
	m_phySapProvider = new MembermmWavePhySapProvider (this);
	NS_LOG_FUNCTION(this);
}

mmWavePhy::~mmWavePhy ()
{

}

void
mmWavePhy::DoDispose ()
{
	NS_LOG_FUNCTION (this);
	m_controlMessagesQueue.clear ();

	Object::DoDispose ();
}

void
mmWavePhy::SetDevice (Ptr<mmWaveNetDevice> d)
{
	m_netDevice = d;
}

Ptr<mmWaveNetDevice>
mmWavePhy::GetDevice ()
{
	return m_netDevice;
}

void
mmWavePhy::SetChannel (Ptr<SpectrumChannel> c)
{

}

double
mmWavePhy::GetTti (void) const
{
	NS_LOG_FUNCTION (this);
	return m_PhyMACConfig->GetTTI();
}

void
mmWavePhy::DoSetCellId (uint16_t cellId)
{

	NS_LOG_FUNCTION (this);
	m_cellId = cellId;
}


void
mmWavePhy::SetNoiseFigure (double nf)
{
	m_noiseFigure = nf;
}

double
mmWavePhy::GetNoiseFigure (void) const
{
	return m_noiseFigure;
}

void
mmWavePhy::SetControlMessages (Ptr<mmWaveControlMessages> m)
{
	if (m_controlMessagesQueue.empty ())
	{
		std::list<Ptr<mmWaveControlMessages> > l;
		l.push_back(m);
		m_controlMessagesQueue.push_back (l);
	}
	else
	{
		m_controlMessagesQueue.at (m_controlMessagesQueue.size () - 1).push_back (m);
	}
}

void
mmWavePhy::SendRachPreamble (uint32_t PreambleId, uint32_t Rnti)
{
	m_raPreambleId = PreambleId;
	Ptr<RachPreamblemmWaveControlMessage> msg = Create<RachPreamblemmWaveControlMessage> ();
	msg->SetRapId (PreambleId);
	SetControlMessages (msg);
}

void
mmWavePhy::SetMacData (Ptr<PacketBurst> pb)
{
	m_packetBurstQueue.push_back (pb);
}

std::list<Ptr<mmWaveControlMessages> >
mmWavePhy::GetControlMessages (void)
{
	NS_LOG_FUNCTION (this);
	if (m_controlMessagesQueue.empty())
	{
		std::list<Ptr<mmWaveControlMessages> > emptylist;
		return (emptylist);
	}

	if (m_controlMessagesQueue.at (0).size () > 0)
	{
	    std::list<Ptr<mmWaveControlMessages> > ret = m_controlMessagesQueue.front ();
	    m_controlMessagesQueue.erase (m_controlMessagesQueue.begin ());
	    std::list<Ptr<mmWaveControlMessages> > newlist;
	    m_controlMessagesQueue.push_back (newlist);
	    return (ret);
	}
	else
	{
	    m_controlMessagesQueue.erase (m_controlMessagesQueue.begin ());
	    std::list<Ptr<mmWaveControlMessages> > newlist;
	    m_controlMessagesQueue.push_back (newlist);
	    std::list<Ptr<mmWaveControlMessages> > emptylist;
	    return (emptylist);
	}
}

Ptr<PacketBurst>
mmWavePhy::GetPacketBurst (void)
{
	if (m_packetBurstQueue.empty())
	{
		Ptr<PacketBurst> empty = CreateObject <PacketBurst> ();
		m_packetBurstQueue.push_back (empty);
		return (0);//empty;
	}

	if (m_packetBurstQueue.at (0)->GetSize () > 0)
	{
		Ptr<PacketBurst> ret = m_packetBurstQueue.at (0)->Copy ();
		m_packetBurstQueue.erase (m_packetBurstQueue.begin ());
		m_packetBurstQueue.push_back (CreateObject <PacketBurst> ());
		return (ret);
	}
    else
	{
		m_packetBurstQueue.erase (m_packetBurstQueue.begin ());
		m_packetBurstQueue.push_back (CreateObject <PacketBurst> ());
		return (0);
	}
}

void
mmWavePhy::SetCofigurationParameters (Ptr<mmWavePhyMacCommon> ptrConfig)
{
	m_PhyMACConfig = ptrConfig;
}

Ptr<mmWavePhyMacCommon>
mmWavePhy::GetConfigurationParameters (void) const
{
	return m_PhyMACConfig;
}


mmWavePhySapProvider*
mmWavePhy::GetmmWavePhySapProvider ()
{
	return m_phySapProvider;
}

void
mmWavePhy::SetmmWavePhySapUser (mmWavePhySapUser* ptr)
{
	m_phySapUser = ptr;
}

void
mmWavePhy::UpdateCurrentAllocationAndSchedule (uint32_t frame, uint32_t sf)
{
	std::map<uint32_t,Schedule>::iterator it_sched;

	uint32_t sfnsf = ((0x3FF & frame) << 16) | ((0xFF & sf) << 8) | ((0xFF & 1));

	//NS_LOG_UNCOND ("Search SFN : "<< sfnsf);

	it_sched = m_TDDPatternsFrorSF.find(sfnsf);
	if (it_sched != m_TDDPatternsFrorSF.end ())
	{
		m_CurrentTDDMap = (*it_sched).second;
		m_TDDPatternsFrorSF.erase (it_sched);
	}
	else
	{
		/* Should be discussed before finalizing */
		Schedule defaultSched;
		for (uint32_t i = 0; i< m_PhyMACConfig->GetSlotPerSubframe(); i++)
		{
			defaultSched.m_slotType.push_back (CTRL);
		}
		m_CurrentTDDMap = defaultSched;
	}

	std::map<uint32_t,allocationList>::iterator it_alloc;
	it_alloc = m_AllocationListforSF.find(sfnsf);
	if (it_alloc != m_AllocationListforSF.end ())
	{
		m_CurrentAllocationList = (*it_alloc).second;
		m_AllocationListforSF.erase (it_alloc);
	}
	else
	{
		allocationList defaultAllocList;
		for (uint32_t i = 0; i< m_PhyMACConfig->GetSlotPerSubframe(); i++)
		{
			allocationMap alMap;
			alMap.m_IsUL = (bool)((i+1)%2);
			for(uint32_t j = 0; j < m_PhyMACConfig->GetRBperSlot (); j++)
			{
				AllocatedTo usr;
				usr.noAllocation = true;
				usr.userImsi = 0;
				alMap.m_user.push_back (usr);
				/* What about MCS??*/
			}

			defaultAllocList.m_AllocationMapforSF.push_back (alMap);
		}

		m_CurrentAllocationList = defaultAllocList;

	}
}


}
