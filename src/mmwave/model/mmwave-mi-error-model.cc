 /* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
 /*
 *   Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *   Copyright (c) 2015, NYU WIRELESS, Tandon School of Engineering, New York University
 *   Copyright (c) 2016, University of Padova, Dep. of Information Engineering, SIGNET lab. 
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
 *
 * Modified by: Michele Polese <michele.polese@gmail.com> 
 *                 Dual Connectivity and Handover functionalities
 */



#include <list>
#include <vector>
#include <ns3/log.h>
#include <ns3/pointer.h>
#include <stdint.h>
#include <cmath>
#include <stdint.h>
#include "stdlib.h"
#include "mmwave-mi-error-model.h"



NS_LOG_COMPONENT_DEFINE ("MmWaveMiErrorModel");

namespace ns3 {




double 
MmWaveMiErrorModel::Mib (const SpectrumValue& sinr, const std::vector<int>& map, uint8_t mcs)
{
  NS_LOG_FUNCTION (sinr << &map << (uint32_t) mcs);
  
  double MI;
  double MIsum = 0.0;
  SpectrumValue sinrCopy = sinr;
  
  for (uint32_t i = 0; i < map.size (); i++)
    {
      double sinrLin = sinrCopy[map.at (i)];
      if (mcs <= MMWAVE_MI_QPSK_MAX_ID) // QPSK
        {

          if (sinrLin > MI_map_qpsk_axis[MMWAVE_MI_MAP_QPSK_SIZE-1])
            {
              MI = 1;
            }
          else 
            { 
              // since the values in MI_map_qpsk_axis are uniformly spaced, we have
              // index = ((sinrLin - value[0]) / (value[SIZE-1] - value[0])) * (SIZE-1)
              // the scaling coefficient is always the same, so we use a static const
              // to speed up the calculation
              static const double scalingCoeffQpsk = 
                (MMWAVE_MI_MAP_QPSK_SIZE - 1) / (MI_map_qpsk_axis[MMWAVE_MI_MAP_QPSK_SIZE-1] - MI_map_qpsk_axis[0]);
              double sinrIndexDouble = (sinrLin -  MI_map_qpsk_axis[0]) * scalingCoeffQpsk + 1;
              uint32_t sinrIndex = std::max(0.0, std::floor (sinrIndexDouble));
              NS_ASSERT_MSG (sinrIndex < MMWAVE_MI_MAP_QPSK_SIZE, "MI map out of data");
              MI = MI_map_qpsk[sinrIndex];
            }
        }
      else
        {
          if (mcs > MMWAVE_MI_QPSK_MAX_ID && mcs <= MMWAVE_MI_16QAM_MAX_ID )	// 16-QAM
            {
              if (sinrLin > MI_map_16qam_axis[MMWAVE_MI_MAP_16QAM_SIZE-1])
                {
                  MI = 1;
                }
              else 
                {
                  // since the values in MI_map_16QAM_axis are uniformly spaced, we have
                  // index = ((sinrLin - value[0]) / (value[SIZE-1] - value[0])) * (SIZE-1)
                  // the scaling coefficient is always the same, so we use a static const
                  // to speed up the calculation
                  static const double scalingCoeff16qam = 
                    (MMWAVE_MI_MAP_16QAM_SIZE - 1) / (MI_map_16qam_axis[MMWAVE_MI_MAP_16QAM_SIZE-1] - MI_map_16qam_axis[0]);
                  double sinrIndexDouble = (sinrLin -  MI_map_16qam_axis[0]) * scalingCoeff16qam + 1;
                  uint32_t sinrIndex = std::max(0.0, std::floor (sinrIndexDouble));
                  NS_ASSERT_MSG (sinrIndex < MMWAVE_MI_MAP_16QAM_SIZE, "MI map out of data");
                  MI = MI_map_16qam[sinrIndex];
                }
            }
          else // 64-QAM
            {
              if (sinrLin > MI_map_64qam_axis[MMWAVE_MI_MAP_64QAM_SIZE-1])
                {
                  MI = 1;
                }
              else
                {
                  // since the values in MI_map_64QAM_axis are uniformly spaced, we have
                  // index = ((sinrLin - value[0]) / (value[SIZE-1] - value[0])) * (SIZE-1)
                  // the scaling coefficient is always the same, so we use a static const
                  // to speed up the calculation
                  static const double scalingCoeff64qam = 
                    (MMWAVE_MI_MAP_64QAM_SIZE - 1) / (MI_map_64qam_axis[MMWAVE_MI_MAP_64QAM_SIZE-1] - MI_map_64qam_axis[0]);
                  double sinrIndexDouble = (sinrLin -  MI_map_64qam_axis[0]) * scalingCoeff64qam + 1;
                  uint32_t sinrIndex = std::max(0.0, std::floor (sinrIndexDouble));
                  NS_ASSERT_MSG (sinrIndex < MMWAVE_MI_MAP_64QAM_SIZE, "MI map out of data");
                  MI = MI_map_64qam[sinrIndex];
                }
            }
        }
      NS_LOG_LOGIC (" RB " << map.at (i) << "Minimum SNR = " << 10 * std::log10 (sinrLin) << " dB, " << sinrLin << " V, MCS = " << (uint16_t)mcs << ", MI = " << MI);
      MIsum += MI;
    }
  MI = MIsum / map.size ();
  NS_LOG_LOGIC (" MI = " << MI);
  return MI;
}


double 
MmWaveMiErrorModel::MappingMiBler (double mib, uint8_t ecrId, uint32_t cbSize)
{
  NS_LOG_FUNCTION (mib << (uint32_t) ecrId << (uint32_t) cbSize);
  double b = 0;
  double c = 0;

  NS_ASSERT_MSG (ecrId <= MMWAVE_MI_64QAM_BLER_MAX_ID, "ECR out of range [0..37]: " << (uint16_t) ecrId);
  int cbIndex = 1;
  while ((cbIndex < 9)&&(cbMiSizeTable[cbIndex]<= cbSize))
    {
      cbIndex++;
    }
  cbIndex--;
  NS_LOG_LOGIC (" ECRid " << (uint16_t)ecrId << " ECR " << BlerCurvesEcrMap[ecrId] << " CB size " << cbSize << " CB size curve " << cbMiSizeTable[cbIndex]);

  b = bEcrTable[cbIndex][ecrId];
  if (b<0.0)
    {
      //take the lowest CB size including this CB for removing CB size
      //quatization errors
      int i = cbIndex;
      while ((i<9)&&(b<0))
        {
          b = bEcrTable[i++][ecrId];
        }
    }
  c = cEcrTable[cbIndex][ecrId];
  if (c<0.0)
    {
      //take the lowest CB size including this CB for removing CB size
      //quatization errors
      int i = cbIndex;
      while ((i<9)&&(c<0))
        {
          c = cEcrTable[i++][ecrId];
        }
    }
  // see IEEE802.16m EMD formula 55 of section 4.3.2.1
  double bler = 0.5*( 1 - erf((mib-b)/(sqrt(2)*c)) );
  NS_LOG_LOGIC ("MIB: " << mib << " BLER:" << bler << " b:" << b << " c:" << c);
  return bler;
}

MmWaveTbStats_t
MmWaveMiErrorModel::GetTbDecodificationStats (const SpectrumValue& sinr, const std::vector<int>& map, uint32_t size, uint8_t mcs, MmWaveHarqProcessInfoList_t miHistory)
{
  NS_LOG_FUNCTION (sinr << &map << (uint32_t) size << (uint32_t) mcs);

  double tbMi = Mib(sinr, map, mcs);
  double MI = 0.0;
  double Reff = 0.0;
  NS_ASSERT (mcs < 29);
  if (miHistory.size ()>0)
    {
      // evaluate R_eff and MI_eff
      uint32_t codeBitsSum = 0;
      double miSum = 0.0;
      for (uint16_t i = 0; i < miHistory.size (); i++)
        {
          NS_LOG_DEBUG (" Sum MI " << miHistory.at (i).m_mi << " Ci " << miHistory.at (i).m_codeBits);
          codeBitsSum += miHistory.at (i).m_codeBits;
          miSum += (miHistory.at (i).m_mi*miHistory.at (i).m_codeBits);
        }
      codeBitsSum += (((double)size*8.0) / McsEcrTable [mcs]);
      miSum += (tbMi*(((double)size*8.0) / McsEcrTable [mcs]));
      Reff = miHistory.at (0).m_infoBits / (double)codeBitsSum; // information bits are the size of the first TB
      MI = miSum / (double)codeBitsSum;
    }
  else
    {
      MI = tbMi;
    }
  NS_LOG_DEBUG (" MI " << MI << " Reff " << Reff << " HARQ " << miHistory.size ());
  // estimate CB size (according to sec 5.1.2 of TS 36.212)
  uint16_t Z = 6144; // max size of a codeblock (including CRC)
  uint32_t B = size * 8;
//   B = 1234;
  uint32_t L = 0;
  uint32_t C = 0; // no. of codeblocks
  uint32_t Cplus = 0; // no. of codeblocks with size K+
  uint32_t Kplus = 0; // no. of codeblocks with size K+
  uint32_t Cminus = 0; // no. of codeblocks with size K+
  uint32_t Kminus = 0; // no. of codeblocks with size K+
  uint32_t B1 = 0;
  uint32_t deltaK = 0;
  if (B <= Z)
    {
      // only one codeblock
      L = 0;
      C = 1;
      B1 = B;
    }
  else
    {
      L = 24;
      C = ceil ((double)B / ((double)(Z-L)));
      B1 = B + C * L;
    }
  // first segmentation: K+ = minimum K in table such that C * K >= B1
//   uint i = 0;
//   while (B1 > cbSizeTable[i] * C)
//     {
// //       NS_LOG_INFO (" K+ " << cbSizeTable[i] << " means " << cbSizeTable[i] * C);
//       i++;
//     }
//   uint32_t KplusId = i;
//   Kplus = cbSizeTable[i];

  // implement a modified binary search
  int min = 0;
  int max = 187;
  int mid = 0;
  do
    {
      mid = (min+max) / 2;
      if (B1 > cbSizeTable[mid]*C)
        {
          if (B1 < cbSizeTable[mid+1]*C)
            {
              break;
            }
          else
            {
              min = mid + 1;
            }
        }
      else
        {
          if (B1 > cbSizeTable[mid-1]*C)
            {
              break;
            }
          else
            {
              max = mid - 1;
            }
        }
  } while ((cbSizeTable[mid]*C != B1) && (min < max));
  // adjust binary search to the largest integer value of K containing B1
  if (B1 > cbSizeTable[mid]*C)
    {
      mid ++;
    }

  uint32_t KplusId = mid;
  Kplus = cbSizeTable[mid];


  if (C==1)
    {
      Cplus = 1;
      Cminus = 0;
      Kminus = 0;
    }
  else
    {
      // second segmentation size: K- = maximum K in table such that K < K+
      // -fstrict-overflow sensitive, see bug 1868
      Kminus = cbSizeTable[ KplusId > 1 ? KplusId - 1 : 0];
      deltaK = Kplus - Kminus;
      Cminus = floor ((((double) C * Kplus) - (double)B1) / (double)deltaK);
      Cplus = C - Cminus;
    }
  NS_LOG_INFO ("--------------------LteMiErrorModel: TB size of " << B << " needs of " << B1 << " bits reparted in " << C << " CBs as "<< Cplus << " block(s) of " << Kplus << " and " << Cminus << " of " << Kminus);

  double errorRate = 1.0;
  uint8_t ecrId = 0;
  if (miHistory.size ()==0)
    {
      // first tx -> get ECR from MCS
      ecrId = McsEcrBlerTableMapping[mcs];
      NS_LOG_DEBUG ("NO HARQ MCS " << (uint16_t)mcs << " ECR id " << (uint16_t)ecrId);
    }
  else
    {
      NS_LOG_DEBUG ("HARQ block no. " << miHistory.size ());
      // harq retx -> get closest ECR to Reff from available ones
      if (mcs <= MMWAVE_MI_QPSK_MAX_ID)
        {
          // Modulation order 2
          uint8_t i = MMWAVE_MI_QPSK_BLER_MAX_ID;
          while ((BlerCurvesEcrMap[i]>Reff)&&(i>0))
            {
              i--;
            }
          ecrId = i;
        }
      else if (mcs <= MMWAVE_MI_16QAM_MAX_ID)
        {
          // Modulation order 4
          uint8_t i = MMWAVE_MI_16QAM_BLER_MAX_ID;
          while ((BlerCurvesEcrMap[i]>Reff)&&(i>MMWAVE_MI_QPSK_BLER_MAX_ID + 1))
            {
              i--;
            }
          ecrId = i;
        }
      else
        {
          // Modulation order 6
          uint8_t i = MMWAVE_MI_64QAM_BLER_MAX_ID;
          while ((BlerCurvesEcrMap[i]>Reff)&&(i>MMWAVE_MI_16QAM_BLER_MAX_ID + 1))
            {
              i--;
            }
          ecrId = i;
        }
      NS_LOG_DEBUG ("HARQ ECR " << (uint16_t)ecrId);
    }

  if (C!=1)
    {
      double cbler = MappingMiBler (MI, ecrId, Kplus);
      errorRate *= pow (1.0 - cbler, Cplus);
      cbler = MappingMiBler (MI, ecrId, Kminus);
      errorRate *= pow (1.0 - cbler, Cminus);
      errorRate = 1.0 - errorRate;
    }
  else
    {
      errorRate = MappingMiBler (MI, ecrId, Kplus);
    }

  NS_LOG_LOGIC (" Error rate " << errorRate);
  MmWaveTbStats_t ret;
  ret.tbler = errorRate;
  ret.mi = tbMi;
  ret.miTotal = MI;
  return ret;
}




} // namespace ns3

