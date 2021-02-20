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

#include "mmwave-energy-helper.h"
#include "ns3/mmwave-ue-net-device.h"
#include "ns3/mc-ue-net-device.h"
#include "ns3/mmwave-spectrum-phy.h"
#include "ns3/mmwave-phy.h"

namespace ns3{


MmWaveRadioEnergyModelHelper::MmWaveRadioEnergyModelHelper ()
{
    m_radioEnergy.SetTypeId ("ns3::MmWaveRadioEnergyModel");
    m_depletionCallback.Nullify ();
    m_rechargedCallback.Nullify ();
}

MmWaveRadioEnergyModelHelper::~MmWaveRadioEnergyModelHelper ()
{
    
}

void
MmWaveRadioEnergyModelHelper::SetDepletionCallback (
    MmWaveRadioEnergyModel::MmWaveRadioEnergyDepletionCallback callback )
{
    m_depletionCallback = callback;
}
void
MmWaveRadioEnergyModelHelper::SetRechargedCallback (
    MmWaveRadioEnergyModel::MmWaveRadioEnergyRechargedCallback callback )
{
    m_rechargedCallback = callback;
}

Ptr<DeviceEnergyModel>
MmWaveRadioEnergyModelHelper::DoInstall(Ptr<NetDevice> device,
                                            Ptr<EnergySource> source) const
{
    NS_ASSERT (device != NULL);
    NS_ASSERT (source != NULL);
    std::string deviceName = device->GetInstanceTypeId ().GetName ();
    if (deviceName.compare ("ns3::MmWaveUeNetDevice") != 0)
    {

    }

    Ptr<Node> node = device->GetNode ();
    Ptr<MmWaveRadioEnergyModel> model = m_radioEnergy.Create ()->GetObject<MmWaveRadioEnergyModel> ();
    NS_ASSERT (model != NULL);
    model->SetNode (node);
    Ptr<mmwave::MmWaveUeNetDevice> mmwaveDevice;
    Ptr<mmwave::McUeNetDevice> mcDevice;
    Ptr<ns3::mmwave::MmWaveUePhy> mmwavePhy;
    
    if (deviceName == "ns3::MmWaveUeNetDevice")
    {
        mmwaveDevice = DynamicCast<mmwave::MmWaveUeNetDevice> (device);
        mmwavePhy = mmwaveDevice->GetPhy ();
        // mcDevice->DoDispose ();
    }
    else if (deviceName == "ns3::McUeNetDevice")
    {
        // mmwaveDevice->DoDispose ();
        mcDevice = DynamicCast<ns3::mmwave::McUeNetDevice> (device);
        mmwavePhy = mcDevice->GetMmWavePhy ();
    }
    
    Ptr<ns3::mmwave::MmWaveSpectrumPhy> mmwaveDlSpectrumPhy = mmwavePhy->GetDlSpectrumPhy();
    Ptr<ns3::mmwave::MmWaveSpectrumPhy> mmwaveUlSpectrumPhy = mmwavePhy->GetUlSpectrumPhy ();
    mmwaveDlSpectrumPhy->TraceConnectWithoutContext ("State", MakeCallback (&MmWaveRadioEnergyModel::ChangeStateEvent, model));
    mmwaveUlSpectrumPhy->TraceConnectWithoutContext ("State", MakeCallback (&MmWaveRadioEnergyModel::ChangeStateEvent, model));
    model->SetEnergyDepletionCallback (m_depletionCallback);
    model->SetEnergyRechargedCallback (m_rechargedCallback);
    source->AppendDeviceEnergyModel (model);
    model->SetEnergySource (source);

    return model;
}
}
