/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "largeandburst.h"

#include <fstream>
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

namespace ns3 {
/* ... */
burstApp::burstApp()
    :m_socket(0),
    m_peer(),
    m_packetSize(0),
    m_nPackets(0),
    m_sendEvent(),
    m_running(false),
    m_packetsSent(0),
    m_iters(0),
    m_itersDone(0)
    {
    }
burstApp::~burstApp()
{
    m_socket=0;
}
void burstApp::Setup(Ptr<Socket> socket, Address address,
 uint32_t packetSize, uint32_t nPackets, uint32_t iters)
 {
     m_socket = socket;
     m_peer = address;
     m_packetSize = packetSize;
     m_nPackets = nPackets;
     m_iters = iters;
 }

void burstApp::StartApplication (void)
{
    m_running = true;
    m_packetsSent = 0;
    m_socket->Bind();
    m_socket->Connect(m_peer);
    SendManyPackets();
}
void burstApp::StopApplication(void)
{
    m_running = false;
    if(m_sendEvent.IsRunning())
    {
        Simulator::Cancel(m_sendEvent);
    }
    if(m_socket)
    {
        m_socket->Close();
    }
}
void burstApp::SendManyPackets(void){
    Ptr<Packet> packet = Create<Packet> (m_packetSize);
    if(m_itersDone++ < m_iters)
    {
        while(m_packetsSent++ < m_nPackets)
        {
            m_socket->Send(packet);
        }
    }
    m_packetsSent = 0;
    CallScheduler();
}
void burstApp::CallScheduler (void)
{
    if(m_running)
    {
        Time tNext (Seconds(5));
        
        m_sendEvent = Simulator::Schedule(tNext,&burstApp::SendManyPackets,this);

    }
}
longTermApp::longTermApp()
    :m_socket(0),
    m_peer()
    {

    }
longTermApp::~longTermApp()
{
    m_socket = 0;
}    
void longTermApp::Setup(Ptr<Socket> socket, Address address,
uint32_t totalTxBytes, uint32_t writeSize)
{
    m_socket = socket;
    m_peer = address;
    m_totalTxBytes = totalTxBytes;
    m_writeSize = writeSize;
    for(uint32_t i = 0; i< writeSize; ++i){
        char m = toascii(97+i%26);
        m_data[i] = m;
    }
}
void longTermApp::StartApplication(void)
{
    m_currentTxBytes = 0;
    m_socket->Bind();
    m_socket->Connect(m_peer);
    StartFlow();
}
void longTermApp::StopApplication(void){
    if(m_socket){
        m_socket->Close();
    }
}
void longTermApp::StartFlow()
{
    m_socket->SetSendCallback(MakeCallback(&longTermApp::WriteUntilBufferFull,this));
    WriteUntilBufferFull(m_socket,m_socket->GetTxAvailable());

}
void longTermApp::WriteUntilBufferFull(Ptr<Socket> localsocket,uint32_t txSpace)
{
    while(m_currentTxBytes<m_totalTxBytes && localsocket->GetTxAvailable()>0)
    {
        uint32_t left = m_totalTxBytes - m_currentTxBytes;
        uint32_t dataOffset = m_currentTxBytes % m_writeSize;
         uint32_t toWrite = m_writeSize - dataOffset;
         toWrite = std::min (toWrite, left);
         toWrite = std::min (toWrite, localsocket->GetTxAvailable ());
         int amountSent = localsocket->Send (&m_data[dataOffset], toWrite, 0);
         if(amountSent < 0)
            {
                return;
            }
        m_currentTxBytes += amountSent;
      // std::cout<<"curr sent="<<m_currentTxBytes<<" ;; avail="<<localSocket->GetTxAvailable ()<<std::endl;
    }
    localsocket->Close();
}
}
