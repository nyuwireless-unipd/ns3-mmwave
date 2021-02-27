/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2020 IITKGP
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
 * Author: Niloy Ganguly <gangulyniloy@gmail.com>
 * Author: Sandip Chakraborty <sandipchkraborty@gmail.com>
 */

#ifndef MMWAVE_ENERGY_HELPER_H
#define MMWAVE_ENERGY_HELPER_H

#include "ns3/energy-model-helper.h"
#include "ns3/mmwave-energy.h"

namespace ns3 {

/**
 * \ingroup energy
 * \brief Assign MmWaveRadioEnergyModel to MmWave devices.
 *
 * This installer installs MmWaveRadioEnergyModel for only MmWaveNetDevice objects.
 *
 */
class MmWaveRadioEnergyModelHelper : public DeviceEnergyModelHelper
{
public:
  /**
   * Construct a helper which is used to add a radio energy model to a node
   */
  MmWaveRadioEnergyModelHelper ();

  /**
   * Destroy a RadioEnergy Helper
   */
  ~MmWaveRadioEnergyModelHelper ();

  /**
   * \param name the name of the attribute to set
   * \param v the value of the attribute
   *
   * Sets an attribute of the underlying PHY object.
   */
  void Set (std::string name, const AttributeValue &v){}

  /**
   * \param callback Callback function for energy depletion handling.
   *
   * Sets the callback to be invoked when energy is depleted.
   */
  void SetDepletionCallback (MmWaveRadioEnergyModel::MmWaveRadioEnergyDepletionCallback callback);

  /**
   * \param callback Callback function for energy recharged handling.
   *
   * Sets the callback to be invoked when energy is recharged.
   */
  void SetRechargedCallback (MmWaveRadioEnergyModel::MmWaveRadioEnergyRechargedCallback callback);

  

private:
  /**
   * \param device Pointer to the NetDevice to install DeviceEnergyModel.
   * \param source Pointer to EnergySource to install.
   * \returns Ptr<DeviceEnergyModel>
   *
   * Implements DeviceEnergyModel::Install.
   */
  Ptr<DeviceEnergyModel> DoInstall (Ptr<NetDevice> device,
                                            Ptr<EnergySource> source) const;

private:
  ObjectFactory m_radioEnergy; ///< radio energy
  MmWaveRadioEnergyModel::MmWaveRadioEnergyDepletionCallback m_depletionCallback; ///< radio energy depletion callback
  MmWaveRadioEnergyModel::MmWaveRadioEnergyRechargedCallback m_rechargedCallback; ///< radio energy recharged callback

};

} // namespace ns3

#endif /* MMWAVE_RADIO_ENERGY_MODEL_HELPER_H */