/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */


#include "largeandburst-helper.h"
#include "ns3/core-module.h"

namespace ns3 {

/* ... */
LargeHelper::LargeHelper(uint32_t totalTxBytes, uint32_t writeSize)
{
    m_txbytes = totalTxBytes;
    m_wsize = writeSize;
}
void 
LargeHelper::SetAddress(Address address)
{
    m_address = address;
}
ApplicationContainer
LargeHelper::Install(Ptr<Node> node) const
{
    Ptr<Socket> ns3TcpSocket_lt = Socket::CreateSocket (node, TcpSocketFactory::GetTypeId ());
    Ptr<longTermApp> lt_app = CreateObject<longTermApp> ();
    lt_app->Setup(ns3TcpSocket_lt , m_address, m_txbytes, m_wsize);
    node->AddApplication(lt_app);
    ApplicationContainer app;
    app.Add(lt_app);
    return app;
}
BurstHelper::BurstHelper(uint32_t packetSize,uint32_t nPackets, uint32_t iters)
{
    m_pktsize = packetSize;
    m_npkts = nPackets;
    m_itrs = iters;
}
void
BurstHelper::SetAddress(Address address)
{
    m_address = address;
}
ApplicationContainer
BurstHelper::Install(Ptr<Node> node) const
{
    Ptr<Socket> ns3TcpSocket_burst = Socket::CreateSocket (node, TcpSocketFactory::GetTypeId ());
    Ptr<burstApp> burst_app = CreateObject<burstApp> ();
    burst_app->Setup (ns3TcpSocket_burst,m_address,m_pktsize,m_npkts,m_itrs);
    node->AddApplication(burst_app);
    ApplicationContainer app;
    app.Add(burst_app);
    return app; 
}
}
