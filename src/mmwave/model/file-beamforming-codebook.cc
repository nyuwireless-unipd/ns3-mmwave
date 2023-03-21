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

#include "ns3/file-beamforming-codebook.h"

#include "ns3/uniform-planar-array.h"
#include <ns3/double.h>
#include <ns3/log.h>
#include <ns3/pointer.h>
#include <ns3/string.h>
#include <ns3/uinteger.h>

#include <fstream>
#include <sstream>
#include <stdlib.h>

namespace ns3
{

namespace mmwave
{

NS_LOG_COMPONENT_DEFINE("FileBeamformingCodebook");

NS_OBJECT_ENSURE_REGISTERED(FileBeamformingCodebook);

TypeId
FileBeamformingCodebook::GetTypeId()
{
    static TypeId tid =
        TypeId("ns3::FileBeamformingCodebook")
            .SetParent<BeamformingCodebook>()
            .AddConstructor<FileBeamformingCodebook>()
            .AddAttribute("CodebookFilename",
                          "The filename for the codebook file",
                          StringValue(""),
                          MakeStringAccessor(&FileBeamformingCodebook::m_codebookFilename),
                          MakeStringChecker());
    return tid;
}

FileBeamformingCodebook::FileBeamformingCodebook()
{
    NS_LOG_FUNCTION(this);
}

void
FileBeamformingCodebook::DoInitialize(void)
{
    ImportCodebookFromFile();
    BeamformingCodebook::DoInitialize();
}

FileBeamformingCodebook::~FileBeamformingCodebook()
{
}

PhasedArrayModel::ComplexVector
FileBeamformingCodebook::GetCodeword(uint32_t idx) const
{
    NS_LOG_FUNCTION(this << idx);
    return m_codewords[idx];
}

uint32_t
FileBeamformingCodebook::GetCodebookSize(void) const
{
    NS_LOG_FUNCTION(this);
    return m_codewords.size();
}

void
FileBeamformingCodebook::ImportCodebookFromFile(void)
{
    NS_LOG_FUNCTION(this);

    std::ifstream cbFile{m_codebookFilename.c_str()};
    NS_ABORT_MSG_IF(!cbFile.good(), m_codebookFilename + " not found");

    ValidateAntenna(cbFile);

    std::string line{};

    // read codebook size
    std::getline(cbFile, line);
    int tmp = atoi(line.c_str());
    NS_ABORT_MSG_IF(tmp <= 0, "Codebook size must be strictly positive");
    uint32_t cbSize = uint32_t(tmp);

    m_codewords.reserve(cbSize); // allocate memory

    // read codewords size
    std::getline(cbFile, line);
    tmp = atoi(line.c_str());
    NS_ABORT_MSG_IF(tmp <= 0, "Codeword size must be strictly positive");
    uint32_t cwSize = uint32_t(tmp);

    NS_LOG_DEBUG("A codeword with " << cbSize << " codewords of size " << cwSize);

    while (std::getline(cbFile, line))
    {
        // lines with CSV for each codeword
        PhasedArrayModel::ComplexVector cw = ParseCodeword(line, cwSize);
        m_codewords.push_back(cw);
    }

    NS_ABORT_MSG_IF(m_codewords.size() != cbSize,
                    "Codebook of unexpected size: m_codewords.size ()=" << m_codewords.size()
                                                                        << ", cbSize=" << cbSize);
    NS_LOG_LOGIC("Codebook successfully imported from " << m_codebookFilename);
}

void
FileBeamformingCodebook::ValidateAntenna(std::ifstream& cbFile) const
{
    std::string arrayId;

    // read PhasedArrayModel TypeId
    std::getline(cbFile, arrayId);
    // TODO find a way to do this check
    NS_ABORT_MSG_IF(!m_array, "Array was not set");
    NS_ABORT_MSG_IF(arrayId != m_array->GetInstanceTypeId().GetName(),
                    arrayId << " != " << m_array->GetInstanceTypeId().GetName());

    std::string line{};
    std::string attribute{};
    std::string value{};

    if (arrayId == UniformPlanarArray::GetTypeId().GetName())
    {
        for (uint8_t i = 0; i < 5; i++)
        {
            // split CSV line
            std::getline(cbFile, line);
            std::stringstream ss(line);
            std::getline(ss, attribute, ',');
            std::getline(ss, value, ',');

            if (attribute == "AntennaHorizontalSpacing" || attribute == "AntennaVerticalSpacing")
            {
                DoubleValue attributeValue;
                m_array->GetAttribute(attribute, attributeValue);
                double fileValue{std::atof(value.c_str())};

                NS_ABORT_MSG_IF(fileValue != attributeValue.Get(),
                                attribute << ": " << fileValue << " != " << attributeValue.Get());
            }
            else if (attribute == "NumRows" || attribute == "NumColumns")
            {
                UintegerValue attributeValue;
                m_array->GetAttribute(attribute, attributeValue);
                uint64_t fileValue{std::stoul(value)};

                NS_ABORT_MSG_IF(fileValue != attributeValue.Get(),
                                attribute << ": " << fileValue << " != " << attributeValue.Get());
            }
            else if (attribute == "AntennaElement")
            {
                PointerValue attributeValue;
                m_array->GetAttribute(attribute, attributeValue);
                std::string fileValue{value};

                // Ignore antenna element for the moment
                // NS_ABORT_MSG_IF (fileValue != attributeValue.GetObject ()->GetInstanceTypeId
                // ().GetName (),
                //                  attribute << ": " << fileValue << " != " <<
                //                  attributeValue.GetObject ()->GetInstanceTypeId ().GetName ());
            }
            else
            {
                NS_FATAL_ERROR("Attribute '" << attribute << "' not recognized");
            }
        }
    }
    else
    {
        NS_FATAL_ERROR("arrayId '" << arrayId << "' not recognized");
    }
}

PhasedArrayModel::ComplexVector
FileBeamformingCodebook::ParseCodeword(const std::string& line, uint32_t cwSize)
{
    NS_LOG_FUNCTION(line << cwSize);

    std::stringstream ss(line);
    PhasedArrayModel::ComplexVector cw(cwSize);

    uint16_t index = 0;
    for (std::complex<double> i; ss >> i;)
    {
        cw[index++] = i;
        if (ss.peek() == ';')
        {
            ss.ignore();
        }
    }

    NS_ABORT_MSG_IF(cw.GetSize() != cwSize,
                    "Codeword of unexpected size: cw.size ()=" << cw.GetSize()
                                                               << ", cwSize=" << cwSize);
    return cw;
}

} // namespace mmwave
} // namespace ns3
