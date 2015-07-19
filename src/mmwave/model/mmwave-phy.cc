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
#include "mmwave-phy-sap.h"
#include <sstream>
#include <vector>

namespace ns3{

NS_LOG_COMPONENT_DEFINE ("MmWavePhy");

NS_OBJECT_ENSURE_REGISTERED ( MmWavePhy);

/*   SAP   */
class MmWaveMemberPhySapProvider : public MmWavePhySapProvider
{
public:
	MmWaveMemberPhySapProvider (MmWavePhy* phy);

	virtual void SendMacPdu (Ptr<Packet> p );

	virtual void SendControlMessage (Ptr<MmWaveControlMessage> msg);

	virtual void SendRachPreamble(uint8_t PreambleId, uint8_t Rnti);
private:
	MmWavePhy* m_phy;
};

MmWaveMemberPhySapProvider::MmWaveMemberPhySapProvider (MmWavePhy* phy)
:m_phy(phy)
{
//	 Nothing more to do
}

void
MmWaveMemberPhySapProvider::SendMacPdu (Ptr<Packet> p)
{
	m_phy->SetMacPdu (p);
}

void
MmWaveMemberPhySapProvider::SendControlMessage (Ptr<MmWaveControlMessage> msg)
{
	m_phy->SetControlMessage(msg); //May need to change
}

void
MmWaveMemberPhySapProvider::SendRachPreamble(uint8_t PreambleId, uint8_t Rnti)
{
	m_phy->SendRachPreamble (PreambleId, Rnti);
}
/* ======= */

TypeId
MmWavePhy::GetTypeId ()
{
	static TypeId
	    tid =
	    TypeId ("ns3::MmWavePhy")
	    .SetParent<Object> ()
	;

	return tid;
}

MmWavePhy::MmWavePhy()
{
	NS_LOG_FUNCTION (this);
	NS_FATAL_ERROR ("This constructor should not be called");
}

MmWavePhy::MmWavePhy(Ptr<MmWaveSpectrumPhy> dlChannelPhy, Ptr<MmWaveSpectrumPhy> ulChannelPhy)
	:m_downlinkSpectrumPhy(dlChannelPhy),
	 m_uplinkSpectrumPhy(ulChannelPhy),
	 m_cellId(0)
{
	NS_LOG_FUNCTION(this);
	m_phySapProvider = new MmWaveMemberPhySapProvider (this);
}

MmWavePhy::~MmWavePhy ()
{

}

void
MmWavePhy::DoInitialize ()
{
	m_packetBurstQueue.resize (m_phyMacConfig->GetSubframesPerFrame ());
	for (unsigned i = 0; i < m_phyMacConfig->GetSubframesPerFrame (); i++)
	{
		m_packetBurstQueue[i] = std::vector<Ptr<PacketBurst> > (m_phyMacConfig->GetSlotsPerSubframe (), 0);
		for (unsigned j = 0; j < m_phyMacConfig->GetSlotsPerSubframe (); j++)
		{
			m_packetBurstQueue[i][j] = CreateObject<PacketBurst> ();
		}
	}
}

void
MmWavePhy::DoDispose ()
{
	NS_LOG_FUNCTION (this);
	m_controlMessageQueue.clear ();

	Object::DoDispose ();
}

void
MmWavePhy::SetDevice (Ptr<MmWaveNetDevice> d)
{
	m_netDevice = d;
}

Ptr<MmWaveNetDevice>
MmWavePhy::GetDevice ()
{
	return m_netDevice;
}

void
MmWavePhy::SetChannel (Ptr<SpectrumChannel> c)
{

}

double
MmWavePhy::GetTti (void) const
{
	NS_LOG_FUNCTION (this);
	return m_phyMacConfig->GetTti();
}

void
MmWavePhy::DoSetCellId (uint16_t cellId)
{

	NS_LOG_FUNCTION (this);
	m_cellId = cellId;
}


void
MmWavePhy::SetNoiseFigure (double nf)
{
	m_noiseFigure = nf;
}

double
MmWavePhy::GetNoiseFigure (void) const
{
	return m_noiseFigure;
}

void
MmWavePhy::SendRachPreamble (uint32_t PreambleId, uint32_t Rnti)
{
	m_raPreambleId = PreambleId;
	Ptr<MmWaveRachPreambleMessage> msg = Create<MmWaveRachPreambleMessage> ();
	msg->SetRapId (PreambleId);
	SetControlMessage (msg);
}

void
MmWavePhy::SetMacPdu (Ptr<Packet> p)
{
	MmWaveMacPduHeader header;
	if(p->PeekHeader (header))
	{
		uint8_t sfNum = header.GetSubframeNum ();
		uint8_t slotNum = header.GetSlotNum ();
		//	uint16_t key = ((0xFF * sfNum) << 8) | (0xFF * slotNum);
		NS_ASSERT((sfNum > 0) && (sfNum <= m_phyMacConfig->GetSubframesPerFrame ()));
		NS_ASSERT((slotNum > 0) && (slotNum <= m_phyMacConfig->GetSlotsPerSubframe ()));
//		NS_ASSERT ((header.GetSubframeNum() == sfNum) && (header.GetSlotNum() == slotNum));

//		NS_LOG_DEBUG ("m_packetBurstQueue.size () == " << m_packetBurstQueue.size () << " " << m_packetBurstQueue[sfNum-1].size ());
		Ptr<PacketBurst> pburst = m_packetBurstQueue[sfNum-1][slotNum-1];
//		std::list< Ptr<Packet> > pkts = pburst->GetPackets ();
//		NS_LOG_DEBUG ("pkts.size () == " << pkts.size ());
		pburst->AddPacket (p);
	}
	else
	{
		NS_FATAL_ERROR ("No MAC packet PDU header available");
	}
}

Ptr<PacketBurst>
MmWavePhy::GetPacketBurst (uint8_t sfNum, uint8_t slotNum)
{
	Ptr<PacketBurst> pburst;
	if((m_packetBurstQueue.size () >= sfNum) && (m_packetBurstQueue[sfNum-1].size () >= slotNum))
	{
		pburst = m_packetBurstQueue[sfNum-1][slotNum-1];
		std::list< Ptr<Packet> > pkts = pburst->GetPackets ();
		if (!pkts.empty ())
		{
			MmWaveMacPduHeader macHeader;
			pkts.front ()->PeekHeader (macHeader);
			NS_ASSERT ((macHeader.GetSubframeNum() == sfNum) && (macHeader.GetSlotNum() == slotNum));
		}
		m_packetBurstQueue[sfNum-1][slotNum-1] = CreateObject<PacketBurst> ();
	}
	else
	{
		NS_FATAL_ERROR ("GetPacketBurst(): Subframe and slot index out of bounds");
	}

	return pburst;
}

void
MmWavePhy::SetControlMessage (Ptr<MmWaveControlMessage> m)
{
	if (m_controlMessageQueue.empty ())
	{
		std::list<Ptr<MmWaveControlMessage> > l;
		l.push_back(m);
		m_controlMessageQueue.push_back (l);
	}
	else
	{
		m_controlMessageQueue.at (m_controlMessageQueue.size () - 1).push_back (m);
	}
}

std::list<Ptr<MmWaveControlMessage> >
MmWavePhy::GetControlMessages (void)
{
	NS_LOG_FUNCTION (this);
	if (m_controlMessageQueue.empty())
	{
		std::list<Ptr<MmWaveControlMessage> > emptylist;
		return (emptylist);
	}

	if (m_controlMessageQueue.at (0).size () > 0)
	{
	    std::list<Ptr<MmWaveControlMessage> > ret = m_controlMessageQueue.front ();
	    m_controlMessageQueue.erase (m_controlMessageQueue.begin ());
	    std::list<Ptr<MmWaveControlMessage> > newlist;
	    m_controlMessageQueue.push_back (newlist);
	    return (ret);
	}
	else
	{
	    m_controlMessageQueue.erase (m_controlMessageQueue.begin ());
	    std::list<Ptr<MmWaveControlMessage> > newlist;
	    m_controlMessageQueue.push_back (newlist);
	    std::list<Ptr<MmWaveControlMessage> > emptylist;
	    return (emptylist);
	}
}

void
MmWavePhy::SetCofigurationParameters (Ptr<MmWavePhyMacCommon> ptrConfig)
{
	m_phyMacConfig = ptrConfig;
}

Ptr<MmWavePhyMacCommon>
MmWavePhy::GetConfigurationParameters (void) const
{
	return m_phyMacConfig;
}


MmWavePhySapProvider*
MmWavePhy::GetPhySapProvider ()
{
	return m_phySapProvider;
}

void
MmWavePhy::UpdateCurrentAllocationAndSchedule (uint32_t frame, uint32_t sf)
{
	/*std::map<uint32_t,TddSlotTypeList>::iterator it_sched;

	uint32_t sfnsf = ((0x3FF & frame) << 16) | ((0xFF & sf) << 8) | ((0xFF & 1));

	//NS_LOG_UNCOND ("Search SFN : "<< sfnsf);

	it_sched = m_tddPatternForSlotMap.find(sfnsf);
	if (it_sched != m_tddPatternForSlotMap.end ())
	{
		m_currTddMap = (*it_sched).second;
		m_tddPatternForSlotMap.erase (it_sched);
	}
	else
	{
		 Should be discussed before finalizing
		TddSlotTypeList defaultSched;
		for (uint32_t i = 0; i< m_phyMacConfig->GetSlotsPerSubframe(); i++)
		{
			defaultSched.push_back (CTRL);
		}
		m_currTddMap = defaultSched;
	}

	std::map<uint32_t,SfAllocationInfo>::iterator it_alloc;
	it_alloc = m_slotAllocInfoMap.find(sfnsf);
	if (it_alloc != m_slotAllocInfoMap.end ())
	{
		m_currentSfAllocInfo = (*it_alloc).second;
		m_slotAllocInfoMap.erase (it_alloc);
	}
	else
	{
		SfAllocationInfo defaultAllocList;
		unsigned numSymbPerSlot = m_phyMacConfig->GetSymbPerSlot();
		unsigned numCtrlSym = m_phyMacConfig->GetCtrlSymbols();
		unsigned remCtrlSym = numCtrlSym;	// remaining ctrl symbols in subframe

		for (uint32_t i = 0; i< m_phyMacConfig->GetSlotsPerSubframe (); i++)
		{
			SlotAllocInfo allocInfo;
			allocInfo.m_isUl = (bool)((i+1)%2);

			if(remCtrlSym > 0)
			{
				if(remCtrlSym >= numSymbPerSlot)
				{
					allocInfo.m_numCtrlSym = numSymbPerSlot;
					allocInfo.m_slotType = SlotAllocInfo::CTRL;
					remCtrlSym -= numSymbPerSlot;
				}
				else
				{
					allocInfo.m_numCtrlSym = remCtrlSym;
					allocInfo.m_slotType = SlotAllocInfo::CTRL_DATA;
					remCtrlSym = 0;
				}
			}
			else
			{
				allocInfo.m_numCtrlSym = 0;
				allocInfo.m_slotType = SlotAllocInfo::DATA;
			}

			for(uint32_t j = 0; j < m_phyMacConfig->GetNumRb (); j++)
			{
				RbAllocationInfo usr;
				usr.m_noAllocation = true;
				usr.m_userImsi = 0;
				allocInfo.m_user.push_back (usr);
				 What about MCS??
			}

			defaultAllocList.m_slotAllocInfo.push_back (allocInfo);
		}

		m_currentSfAllocInfo = defaultAllocList;
	}*/
}


}
