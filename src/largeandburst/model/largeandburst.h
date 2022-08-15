/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef LARGEANDBURST_H
#define LARGEANDBURST_H

#include <fstream>
#include "ns3/network-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/applications-module.h"
namespace ns3 {

/* ... */
class burstApp:public Application
{
    public:
    burstApp();
    virtual ~burstApp();

    void Setup (Ptr<Socket> socket,Address address, uint32_t packetSize,
        uint32_t nPackets, uint32_t iters);
    
    private:
    virtual void StartApplication(void);
    virtual void StopApplication (void);

    void CallScheduler (void);
    void SendManyPackets (void);

    Ptr<Socket>     m_socket;
    Address         m_peer;
    uint32_t        m_packetSize;
    uint32_t        m_nPackets;
    EventId         m_sendEvent;
    bool            m_running;
    uint32_t        m_packetsSent;
    uint32_t		m_iters;
    uint32_t		m_itersDone;
};

class longTermApp:public Application{
    public:
    longTermApp();
    virtual ~longTermApp();
    void Setup (Ptr<Socket> socket, Address address, uint32_t totalTxBytes, uint32_t writeSize);
    void WriteUntilBufferFull (Ptr<Socket> localSocket, uint32_t txSpace);

    private:
        virtual void StartApplication (void);
        virtual void StopApplication (void);

        void StartFlow ();
        // void WriteUntilBufferFull (Ptr<Socket>, uint32_t);

        Ptr<Socket>     m_socket;
        Address         m_peer;
        uint32_t 		  m_totalTxBytes;
        uint32_t 		  m_currentTxBytes;
        // Perform series of 1040 byte writes (this is a multiple of 26 since
        // we want to detect data splicing in the output stream)
        uint32_t 		  m_writeSize;
        uint8_t 		  m_data[1040];
};
}

#endif /* LARGEANDBURST_H */
