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
 * Author: Sashank Bonda <sashank729@gmail.com>
 * Author: Jay Jayatheerthan <jay.jayatheerthan@intel.com>
 * Author: Sandip Chakraborty <sandipchkraborty@gmail.com>
 */

#include "mmwave-radio-energy-model-enb-helper.h"
#include "ns3/mmwave-ue-net-device.h"
#include "ns3/mmwave-enb-net-device.h"
#include "ns3/mc-ue-net-device.h"
#include "ns3/mmwave-spectrum-phy.h"
#include "ns3/mmwave-phy.h"

namespace ns3{


MmWaveRadioEnergyModelEnbHelper::MmWaveRadioEnergyModelEnbHelper ()
{
    m_radioEnergy.SetTypeId ("ns3::MmWaveRadioEnergyModelEnb");
    m_depletionCallback.Nullify ();
    m_rechargedCallback.Nullify ();
}

MmWaveRadioEnergyModelEnbHelper::~MmWaveRadioEnergyModelEnbHelper ()
{
    
}

void
MmWaveRadioEnergyModelEnbHelper::SetDepletionCallback (
    MmWaveRadioEnergyModelEnb::MmWaveRadioEnergyDepletionCallback callback )
{
    m_depletionCallback = callback;
}
void
MmWaveRadioEnergyModelEnbHelper::SetRechargedCallback (
    MmWaveRadioEnergyModelEnb::MmWaveRadioEnergyRechargedCallback callback )
{
    m_rechargedCallback = callback;
}

Ptr<DeviceEnergyModel>
MmWaveRadioEnergyModelEnbHelper::DoInstall(Ptr<NetDevice> device,
                                            Ptr<EnergySource> source) const
{
    NS_ASSERT (device != NULL);
    NS_ASSERT (source != NULL);
    std::string deviceName = device->GetInstanceTypeId ().GetName ();
    if (deviceName.compare ("ns3::MmWaveEnbNetDevice") != 0)
    {
        NS_LOG_ERROR("Device is not of type EnbNetDevice");
    }

    Ptr<Node> node = device->GetNode ();
    Ptr<MmWaveRadioEnergyModelEnb> model = m_radioEnergy.Create ()->GetObject<MmWaveRadioEnergyModelEnb> ();
    NS_ASSERT (model != NULL);
    model->SetNode (node);
    Ptr<mmwave::MmWaveEnbNetDevice> mmwaveEnbDevice;
    Ptr<ns3::mmwave::MmWaveEnbPhy> mmwavePhy;
    
    if (deviceName == "ns3::MmWaveEnbNetDevice")
    {
        mmwaveEnbDevice = DynamicCast<mmwave::MmWaveEnbNetDevice> (device);
        mmwavePhy = mmwaveEnbDevice->GetPhy ();
        // mcDevice->DoDispose ();
    }
    Ptr<ns3::mmwave::MmWaveSpectrumPhy> mmwaveDlSpectrumPhy = mmwavePhy->GetDlSpectrumPhy();
    Ptr<ns3::mmwave::MmWaveSpectrumPhy> mmwaveUlSpectrumPhy = mmwavePhy->GetUlSpectrumPhy ();
    mmwaveDlSpectrumPhy->TraceConnectWithoutContext ("State", MakeCallback (&MmWaveRadioEnergyModelEnb::ChangeStateEvent, model));
    mmwaveUlSpectrumPhy->TraceConnectWithoutContext ("State", MakeCallback (&MmWaveRadioEnergyModelEnb::ChangeStateEvent, model));
    model->SetEnergyDepletionCallback (m_depletionCallback);
    model->SetEnergyRechargedCallback (m_rechargedCallback);
    source->AppendDeviceEnergyModel (model);
    model->SetEnergySource (source);

    return model;
}
}
