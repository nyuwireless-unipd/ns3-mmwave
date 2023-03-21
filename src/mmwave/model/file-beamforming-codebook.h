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

#ifndef FILE_BEAMFORMING_CODEBOOK_H
#define FILE_BEAMFORMING_CODEBOOK_H

#include "ns3/beamforming-codebook.h"
#include "ns3/object.h"

namespace ns3
{
namespace mmwave
{

/**
 *
 */
class FileBeamformingCodebook : public BeamformingCodebook
{
  public:
    FileBeamformingCodebook();
    virtual ~FileBeamformingCodebook() override;

    /**
     * Returns the object type id
     * \return the type id
     */
    static TypeId GetTypeId(void);

    /**
     *
     */
    PhasedArrayModel::ComplexVector GetCodeword(uint32_t idx) const override;

    /**
     *
     */
    uint32_t GetCodebookSize(void) const override;

  private:
    /**
     *
     */
    virtual void DoInitialize(void) override;

    /**
     *
     */
    void ImportCodebookFromFile(void);

    /**
     *
     */
    void ValidateAntenna(std::ifstream& cbFile) const;

    /**
     *
     */
    static PhasedArrayModel::ComplexVector ParseCodeword(const std::string& line, uint32_t cwSize);

    std::string m_codebookFilename;
    std::vector<PhasedArrayModel::ComplexVector> m_codewords;
};

} // namespace mmwave
} // namespace ns3

#endif /* FILE_BEAMFORMING_CODEBOOK_H */
