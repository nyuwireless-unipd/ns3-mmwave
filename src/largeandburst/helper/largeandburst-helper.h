/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef LARGEANDBURST_HELPER_H
#define LARGEANDBURST_HELPER_H

#include "ns3/object-factory.h"
#include "ns3/ipv4-address.h"
#include "ns3/node-container.h"
#include "ns3/application-container.h"
#include "ns3/largeandburst.h"

namespace ns3 {

/* ... */
class LargeHelper
{
    public:
    LargeHelper(uint32_t totalTxBytes, uint32_t writeSize);
    ApplicationContainer Install (Ptr<Node> node) const;
    void SetAddress(Address address);
    private:
    Address m_address;
    uint32_t m_txbytes;
    uint32_t m_wsize;
};

class BurstHelper
{
    public:
    BurstHelper(uint32_t packetSize,uint32_t nPackets, uint32_t iters);
    void SetAddress(Address address);
    ApplicationContainer Install (Ptr<Node> node) const;
    private:
    Address m_address;
    uint32_t m_pktsize;
    uint32_t m_npkts;
    uint32_t m_itrs;
};

}

#endif /* LARGEANDBURST_HELPER_H */
