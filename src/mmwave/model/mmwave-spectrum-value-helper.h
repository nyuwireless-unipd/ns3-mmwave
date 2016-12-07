 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2 as
 *   published by the Free Software Foundation;
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *   Author: Marco Miozzo <marco.miozzo@cttc.es>
 *           Nicola Baldo  <nbaldo@cttc.es>
 *
 *   Modified by: Marco Mezzavilla < mezzavilla@nyu.edu>
 *        	 	  Sourjya Dutta <sdutta@nyu.edu>
 *        	 	  Russell Ford <russell.ford@nyu.edu>
 *        		  Menglei Zhang <menglei@nyu.edu>
 */


#ifndef MMWAVE_SPECTRUM_VALUE_HELPER_H
#define MMWAVE_SPECTRUM_VALUE_HELPER_H

#include <ns3/spectrum-value.h>
#include <ns3/mmwave-phy-mac-common.h>
#include <vector>


namespace ns3 {


/**
 * \ingroup mmwave
 *
 * \brief This class defines all functions to create spectrum model for mmwave
 */
class MmWaveSpectrumValueHelper
{
public:

  static Ptr<SpectrumModel> GetSpectrumModel (Ptr<MmWavePhyMacCommon> ptrConfig);

  static Ptr<SpectrumValue> CreateTxPowerSpectralDensity (Ptr<MmWavePhyMacCommon> ptrConfig,
                                                          double powerTx,
                                                          std::vector <int> activeRbs);


  static Ptr<SpectrumValue> CreateTxPowerSpectralDensity (Ptr<MmWavePhyMacCommon> ptrConfig,
                                                          double powerTx,
                                                          std::map<int, double> powerTxMap,
                                                          std::vector <int> activeRbs);

  static Ptr<SpectrumValue> CreateNoisePowerSpectralDensity (Ptr<MmWavePhyMacCommon> ptrConfig, double noiseFigure);


  static Ptr<SpectrumValue> CreateNoisePowerSpectralDensity (double noiseFigure, Ptr<SpectrumModel> spectrumModel);

private:
  static Ptr<SpectrumModel> m_model;
};


} // namespace ns3



#endif /*  MMWAVE_SPECTRUM_VALUE_HELPER_H */
