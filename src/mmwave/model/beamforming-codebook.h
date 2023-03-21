/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2020 University of Padova, Dep. of Information Engineering, SIGNET lab.
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
 */

#ifndef BEAMFORMING_CODEBOOK_H
#define BEAMFORMING_CODEBOOK_H

#include "ns3/object.h"
#include "ns3/phased-array-model.h"

namespace ns3
{
namespace mmwave
{

/**
 *
 */
class BeamformingCodebook : public Object
{
  public:
    virtual ~BeamformingCodebook() override;

    /**
     * Returns the object type id
     * \return the type id
     */
    static TypeId GetTypeId(void);

    /**
     *
     */
    virtual PhasedArrayModel::ComplexVector GetCodeword(uint32_t idx) const = 0;

    /**
     *
     */
    virtual uint32_t GetCodebookSize(void) const = 0;

  protected:
    virtual void DoInitialize(void);

    Ptr<PhasedArrayModel> m_array;
};

} // namespace mmwave
} // namespace ns3

#endif /* BEAMFORMING_CODEBOOK_H */
