/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "video-stream-helper.h"
#include "ns3/video-stream-server.h"
#include "ns3/video-stream-client.h"
#include "ns3/uinteger.h"
#include "ns3/names.h"

namespace ns3{

VideoStreamServerHelper::VideoStreamServerHelper(uint16_t port)
{
  m_factory.SetTypeId (VideoStreamServer::GetTypeId ());
  SetAttribute ("Port", UintegerValue (port));
}

void
VideoStreamServerHelper::SetAttribute(std::string name, const AttributeValue &value)
{
  m_factory.Set (name, value);
}

ApplicationContainer 
VideoStreamServerHelper::Install (Ptr<Node> node) const
{
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer 
VideoStreamServerHelper::Install (std::string nodeName) const
{
  Ptr<Node> node = Names::Find<Node> (nodeName);
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer 
VideoStreamServerHelper::Install (NodeContainer c) const
{
  ApplicationContainer apps;
  for (NodeContainer::Iterator i = c.Begin(); i != c.End(); i++)
  {
    apps.Add (InstallPriv (*i));
  }
  
  return apps;
}

Ptr<Application>
VideoStreamServerHelper::InstallPriv (Ptr<Node> node) const
{
  Ptr<Application> app = m_factory.Create<VideoStreamServer> ();
  node->AddApplication (app);

  return app;
}

VideoStreamClientHelper::VideoStreamClientHelper(Address ip, uint16_t port)
{
  m_factory.SetTypeId (VideoStreamClient::GetTypeId ());
  SetAttribute ("RemoteAddress", AddressValue (ip));
  SetAttribute ("RemotePort", UintegerValue (port));
}


VideoStreamClientHelper::VideoStreamClientHelper(Address addr)
{
  m_factory.SetTypeId (VideoStreamClient::GetTypeId ());
  SetAttribute ("RemoteAddress", AddressValue (addr));
}

void
VideoStreamClientHelper::SetAttribute(std::string name, const AttributeValue &value)
{
  m_factory.Set (name, value);
}

ApplicationContainer 
VideoStreamClientHelper::Install (Ptr<Node> node) const
{
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer 
VideoStreamClientHelper::Install (std::string nodeName) const
{
  Ptr<Node> node = Names::Find<Node> (nodeName);
  return ApplicationContainer (InstallPriv (node));
}

ApplicationContainer 
VideoStreamClientHelper::Install (NodeContainer c) const
{
  ApplicationContainer apps;
  for (NodeContainer::Iterator i = c.Begin(); i != c.End(); i++)
  {
    apps.Add (InstallPriv (*i));
  }
  
  return apps;
}

Ptr<Application>
VideoStreamClientHelper::InstallPriv (Ptr<Node> node) const
{
  Ptr<Application> app = m_factory.Create<VideoStreamClient> ();
  node->AddApplication (app);

  return app;
}

} // namespace ns3
