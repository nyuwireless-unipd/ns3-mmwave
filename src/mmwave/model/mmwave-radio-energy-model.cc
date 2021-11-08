/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2020 IITKGP, INTEL
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Argha Sen <arghasen10@gmail.com>
 * Author: Abhijit Mondal <abhijit.manpur@gmail.com>
 * Author: Basabdatta Palit <basabdatta.iitkgp@gmail.com>
 * Author: Jay Jayatheerthan <jay.jayatheerthan@intel.com>
 * Author: Krishna Paul <krishna.paul@intel.com>
 * Author: Niloy Ganguly <gangulyniloy@gmail.com>
 * Author: Sandip Chakraborty <sandipchkraborty@gmail.com>
 */
#include "ns3/simulator.h"
#include "ns3/trace-source-accessor.h"
#include "ns3/energy-source.h"
#include "mmwave-radio-energy-model.h"
#include "ns3/log.h"
#include "ns3/config-store-module.h"
#include "ns3/config.h"

namespace ns3 {
NS_LOG_COMPONENT_DEFINE ("MmWaveRadioEnergyModel");
NS_OBJECT_ENSURE_REGISTERED (MmWaveRadioEnergyModel);

TypeId
MmWaveRadioEnergyModel::GetTypeId (void)
{
    static TypeId tid = TypeId ("ns3::MmWaveRadioEnergyModel")
        .SetParent<DeviceEnergyModel> ()
        .AddConstructor<MmWaveRadioEnergyModel> ()
        .AddTraceSource ("TotalEnergyConsumption",
                        "Total energy consumption of the radio device.",
                        MakeTraceSourceAccessor (&MmWaveRadioEnergyModel::m_totalEnergyConsumption),
                        "ns3::TracedValueCallback::Double")
        .AddAttribute ("DeepSleepA",
                        "The default Deep Sleep Current in Amperes.",
                        DoubleValue (0.001),
                        MakeDoubleAccessor (&MmWaveRadioEnergyModel::SetDeepSleepA,
                                            &MmWaveRadioEnergyModel::GetDeepSleepA),
                        MakeDoubleChecker<double> ())
        .AddAttribute ("RxCurrentA",
                        "The default Rx current in Amperes",
                        DoubleValue (0.350),
                        MakeDoubleAccessor (&MmWaveRadioEnergyModel::SetRxCurrentA,
                                            &MmWaveRadioEnergyModel::GetRxCurrentA),
                        MakeDoubleChecker<double> ())
        .AddAttribute ("TxCurrentA",
                        "The default Tx current in Amperes",
                        DoubleValue(0.350),
                        MakeDoubleAccessor (&MmWaveRadioEnergyModel::SetTxCurrentA,
                                            &MmWaveRadioEnergyModel::GetTxCurrentA),
                        MakeDoubleChecker<double> ())
  ;
  return tid;
}

MmWaveRadioEnergyModel::MmWaveRadioEnergyModel ()
:
 m_lastUpdateTime (Seconds(0.0))
{
    NS_LOG_FUNCTION (this);
    m_energyDepletionCallback.Nullify ();
    m_source = 0;
    m_currentState = 0;
    m_lastUpdateTime = Seconds (0);
}

MmWaveRadioEnergyModel::~MmWaveRadioEnergyModel ()
{
    NS_LOG_FUNCTION (this);
}

void
MmWaveRadioEnergyModel::SetEnergySource (Ptr<EnergySource> source)
{
    NS_LOG_FUNCTION (this << source);
    NS_ASSERT (source != NULL);
    m_source = source;
}

void
MmWaveRadioEnergyModel::SetNode (Ptr<Node> node)
{
  NS_LOG_FUNCTION (this << node);
  NS_ASSERT (node != NULL);
  m_node = node;
}

Ptr<Node>
MmWaveRadioEnergyModel::GetNode () const
{
  NS_LOG_FUNCTION (this);
  return m_node;
}

double
MmWaveRadioEnergyModel::GetTotalEnergyConsumption (void) const
{
  NS_LOG_FUNCTION (this);
  Time duration = Simulator::Now () - m_lastUpdateTime;
  NS_ASSERT (duration.IsPositive ());
  double energyToDecrease = 0.0;
  double supplyVoltage = m_source->GetSupplyVoltage ();
  energyToDecrease = duration.GetSeconds () * GetStateA(m_currentState) * supplyVoltage;

  m_source->UpdateEnergySource ();
  
  return m_totalEnergyConsumption + energyToDecrease;
}

double 
MmWaveRadioEnergyModel::GetDeepSleepA (void) const
{
  NS_LOG_FUNCTION (this);
  return m_deepSleepCurrentA;
}

void
MmWaveRadioEnergyModel::SetDeepSleepA (double deepSleepA)
{
  NS_LOG_FUNCTION (this << deepSleepA);
  m_deepSleepCurrentA = deepSleepA;
}


double 
MmWaveRadioEnergyModel::GetRxCurrentA (void) const
{
  NS_LOG_FUNCTION (this);
  return m_rxCurrentA;
}

void 
MmWaveRadioEnergyModel::SetRxCurrentA (double rxCurrentA)
{
  NS_LOG_FUNCTION (this << rxCurrentA);
  m_rxCurrentA = rxCurrentA;
} 

double 
MmWaveRadioEnergyModel::GetTxCurrentA (void) const
{
  NS_LOG_FUNCTION (this);
  return m_txCurrentA;
}

void 
MmWaveRadioEnergyModel::SetTxCurrentA (double txCurrentA)
{
  NS_LOG_FUNCTION (this << txCurrentA);
  m_txCurrentA = txCurrentA;
}

void
MmWaveRadioEnergyModel::SetEnergyDepletionCallback (
  MmWaveRadioEnergyDepletionCallback callback
)
{
  NS_LOG_FUNCTION (this);
  if (callback.IsNull ())
  {
    NS_LOG_DEBUG ("MmWaveRadioEnergyModel:Setting NULL energy depletion callback!");
  }
  m_energyDepletionCallback = callback;
}

void
MmWaveRadioEnergyModel::SetEnergyRechargedCallback (
  MmWaveRadioEnergyRechargedCallback callback
)
{
  NS_LOG_FUNCTION (this);
  if (callback.IsNull ())
  {
    NS_LOG_DEBUG ("MmWaveRadioEnergyModel:Setting NULL energy recharged callback!");
  }
  m_energyRechargedCallback = callback;
}

void 
MmWaveRadioEnergyModel::ChangeStateEvent(int32_t oldState, int32_t newState)
{
  ChangeState (newState);
}
void 
MmWaveRadioEnergyModel::ChangeState (int state)
{
  NS_LOG_FUNCTION (this << state);


  Time duration = Simulator::Now () - m_lastUpdateTime;
  NS_ASSERT (duration.IsPositive ());

  double supplyVoltage = m_source->GetSupplyVoltage ();
  double energyToDecrease = duration.GetSeconds () * GetStateA (m_currentState) * supplyVoltage;

  m_totalEnergyConsumption += energyToDecrease;
  NS_ASSERT (m_totalEnergyConsumption <= m_source->GetInitialEnergy ());

  m_lastUpdateTime = Simulator::Now ();
  m_source->UpdateEnergySource ();
  m_currentState = state;
  m_previousState = m_currentState;


}

void 
MmWaveRadioEnergyModel::HandleEnergyDepletion (void)
{
  NS_LOG_FUNCTION (this);
  NS_LOG_DEBUG ("MmWaveRadioEnergyModel:Energy is depleted!");
  // invoke energy depletion callback, if set.
  if (!m_energyDepletionCallback.IsNull ())
    {
      m_energyDepletionCallback ();
    }
}

void
MmWaveRadioEnergyModel::HandleEnergyRecharged (void)
{
  NS_LOG_FUNCTION (this);
  NS_LOG_DEBUG ("MmWaveRadioEnergyModel:Energy is recharged!");
  // invoke energy recharged callback, if set.
  if (!m_energyRechargedCallback.IsNull ())
    {
      m_energyRechargedCallback ();
    }
}


/* 
* Private functions start here
*/

void 
MmWaveRadioEnergyModel::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
  m_source = NULL;
  m_energyDepletionCallback.Nullify ();
}

double
MmWaveRadioEnergyModel::GetStateA (int state) const
{
  switch (state)
  {
  case 0:
    return m_deepSleepCurrentA;
  case 1:
    return m_txCurrentA;
  case 2:
    return m_rxCurrentA;
  case 3:
    return m_rxCurrentA;
  }
  NS_FATAL_ERROR ("MmWaveRadioEnergyModel: undefined radio state " << state);
}


void
MmWaveRadioEnergyModel::SetCurrentA (double current)
{
  NS_LOG_FUNCTION (this << current);
  Time duration = Simulator::Now () - m_lastUpdateTime;

  double energyToDecrease = 0.0;
  double supplyVoltage = m_source->GetSupplyVoltage ();
  energyToDecrease = duration.GetSeconds () * current * supplyVoltage;

  // update total energy consumption
  m_totalEnergyConsumption += energyToDecrease;
  // update last update time stamp
  m_lastUpdateTime = Simulator::Now ();
  // notify energy source
  m_source->UpdateEnergySource ();
}


double
MmWaveRadioEnergyModel::DoGetCurrentA (void) const
{
  return GetStateA (m_currentState);
}


}