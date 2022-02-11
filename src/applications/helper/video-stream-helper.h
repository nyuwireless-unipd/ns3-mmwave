/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#ifndef VIDEO_STREAM_HELPER_H
#define VIDEO_STREAM_HELPER_H

#include <stdint.h>
#include "ns3/application-container.h"
#include "ns3/node-container.h"
#include "ns3/object-factory.h"
#include "ns3/ipv4-address.h"
#include "ns3/ipv6-address.h"

namespace ns3 {

/**
 * @brief Create a server application that sends the video frames to a client.
 */
class VideoStreamServerHelper
{
private:
  /**
   * @brief Install an ns3::VideoStreamServer on the node configured with all the 
   * attributes set with SetAttribute.
   * 
   * @param node the node on which an VideoStreamServer will be installed
   * @return Ptr<Application> 
   */
  Ptr<Application> InstallPriv (Ptr<Node> node) const;
  ObjectFactory m_factory;

public:
  /**
   * @brief Construct a new VideoStreamServerHelper object. 
   * 
   * @param port the port the server will receive incoming packets
   */
  VideoStreamServerHelper (uint16_t port);
  
  /**
   * @brief Record an attribute to be set in each application after it is created.
   * 
   * @param name the name of the attribute to set
   * @param value the value of the attribute to set
   */
  void SetAttribute (std::string name, const AttributeValue &value);

  /**
   * @brief Create a VideoStreamServerApplication on the specified node.
   * 
   * @param node the node on which to create the application
   * @return ApplicationContainer holding the created application
   */
  ApplicationContainer Install (Ptr<Node> node) const;

  /**
   * @brief Create a VideoStreamServerApplication on the specified node.
   * 
   * @param nodeName the node on which to create the application
   * @return ApplicationContainer holding the created application
   */
  ApplicationContainer Install (std::string nodeName) const;
  
  /**
   * @brief Create a VideoStreamServerApplication on the specified node.
   * 
   * @param c the nodes on which to create the applications
   * @return ApplicationContainer with one application per node in the NodeContainer
   */
  ApplicationContainer Install (NodeContainer c) const;
};

class VideoStreamClientHelper
{
private:
  /**
   * @brief Install an ns3::VideoStreamClient on the node configured with all the 
   * attributes set with SetAttribute.
   * 
   * @param node the node on which an VideoStreamClient will be installed
   * @return Ptr<Application> 
   */
  Ptr<Application> InstallPriv (Ptr<Node> node) const;
  ObjectFactory m_factory; 

public:
  /**
   * @brief Construct a new VideoStreamClientHelper object. 
   * 
   * @param ip the IP address of the remote server
   * @param port the port number of the remote server
   */
  VideoStreamClientHelper (Address ip, uint16_t port);
  /**
   * @brief Construct a new VideoStreamClientHelper object. 
   * 
   * @param addr the address of the remote server
   */
  VideoStreamClientHelper (Address addr);
  
  /**
   * @brief Record an attribute to be set in each application after it is created.
   * 
   * @param name the name of the attribute to set
   * @param value the value of the attribute to set
   */
  void SetAttribute (std::string name, const AttributeValue &value);
  
  /**
   * @brief Create a VideoStreamClientApplication on the specified node.
   * 
   * @param node the node on which to create the application
   * @return ApplicationContainer holding the created application
   */
  ApplicationContainer Install (Ptr<Node> node) const;

  /**
   * @brief Create a VideoStreamClientApplication on the specified node.
   * 
   * @param nodeName the node on which to create the application
   * @return ApplicationContainer holding the created application
   */
  ApplicationContainer Install (std::string nodeName) const;
  
  /**
   * @brief Create a VideoStreamClientApplication on the specified node.
   * 
   * @param c the nodes on which to create the applications
   * @return ApplicationContainer with one application per node in the NodeContainer
   */
  ApplicationContainer Install (NodeContainer c) const;
};

} // namespace ns3

#endif /* VIDEO_STREAM_HELPER_H */
