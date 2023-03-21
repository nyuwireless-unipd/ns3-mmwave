/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 *   Copyright (c) 2019 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
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
 */
#include "ns3/enum.h"
#include "ns3/mmwave-eesm-cc-t1.h"
#include "ns3/mmwave-eesm-cc-t2.h"
#include "ns3/mmwave-eesm-error-model.h"
#include "ns3/mmwave-eesm-ir-t1.h"
#include "ns3/mmwave-eesm-ir-t2.h"
#include "ns3/test.h"

using namespace ns3;
using namespace mmwave;

/**
 * \file mmwave-test-l2sm-eesm.cc
 * \ingroup test
 *
 * \brief This test validates specific functions of the NR PHY abstraction model.
 * The test checks two issues: 1) LDPC base graph (BG) selection works properly, and 2)
 * BLER values are properly obtained from the BLER-SINR look up tables for different
 * block sizes, MCS Tables, BG types, and SINR values.
 *
 */

/**
 * \brief MmWaveL2smEesm testcase
 */
class MmWaveL2smEesmTestCase : public TestCase
{
  public:
    MmWaveL2smEesmTestCase(const std::string& name)
        : TestCase(name)
    {
    }

    /**
     * \brief Destroy the object instance
     */
    virtual ~MmWaveL2smEesmTestCase() override
    {
    }

  private:
    virtual void DoRun(void) override;

    void TestMappingSinrBler1(const Ptr<MmWaveEesmErrorModel>& em);
    void TestMappingSinrBler2(const Ptr<MmWaveEesmErrorModel>& em);
    void TestBgType1(const Ptr<MmWaveEesmErrorModel>& em);
    void TestBgType2(const Ptr<MmWaveEesmErrorModel>& em);

    void TestEesmCcTable1();
    void TestEesmCcTable2();
    void TestEesmIrTable1();
    void TestEesmIrTable2();
};

void
MmWaveL2smEesmTestCase::TestBgType1(const Ptr<MmWaveEesmErrorModel>& em)
{
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3200, 18),
                          MmWaveEesmErrorModel::SECOND,
                          "TestBgType1-a: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3900, 18),
                          MmWaveEesmErrorModel::FIRST,
                          "TestBgType1-b: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(200, 18),
                          MmWaveEesmErrorModel::SECOND,
                          "TestBgType1-c: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(4000, 0),
                          MmWaveEesmErrorModel::SECOND,
                          "TestBgType1-d: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3200, 28),
                          MmWaveEesmErrorModel::FIRST,
                          "TestBgType1-e: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3200, 2),
                          MmWaveEesmErrorModel::SECOND,
                          "TestBgType2-f: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3200, 16),
                          MmWaveEesmErrorModel::SECOND,
                          "TestBgType2-g: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3900, 14),
                          MmWaveEesmErrorModel::FIRST,
                          "TestBgType2-h: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
}

void
MmWaveL2smEesmTestCase::TestBgType2(const Ptr<MmWaveEesmErrorModel>& em)
{
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3200, 18),
                          MmWaveEesmErrorModel::FIRST,
                          "TestBgType2-a: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3900, 18),
                          MmWaveEesmErrorModel::FIRST,
                          "TestBgType2-b: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(200, 18),
                          MmWaveEesmErrorModel::SECOND,
                          "TestBgType2-c: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(4000, 0),
                          MmWaveEesmErrorModel::SECOND,
                          "TestBgType2-d: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3200, 27),
                          MmWaveEesmErrorModel::FIRST,
                          "TestBgType2-e: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3200, 2),
                          MmWaveEesmErrorModel::SECOND,
                          "TestBgType2-f: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3200, 16),
                          MmWaveEesmErrorModel::FIRST,
                          "TestBgType2-g: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
    NS_TEST_ASSERT_MSG_EQ(em->GetBaseGraphType(3900, 14),
                          MmWaveEesmErrorModel::FIRST,
                          "TestBgType2-h: The calculated value differs from the 3GPP base graph "
                          "selection algorithm.");
}

typedef std::tuple<double, uint8_t, uint32_t, double> MappingTable;

static std::vector<MappingTable> resultTable1 = {
    // sinr (lineal), mcs, cbsize, result

    // MCS 18, all CBS in continuation use BGtype2
    // CBS=3200, in table corresponds to 3104
    MappingTable{19.95, 18, 3200, 0.023},      // sinr 13 db
    MappingTable{15.849, 18, 3200, 0.7567365}, // sinr 12 db
    MappingTable{10, 18, 3200, 1.00},          // sinr 10 db
    // CBS=3500, in table corresponds to 3496
    MappingTable{19.95, 18, 3500, 0.0735},     // sinr 13 db
    MappingTable{15.849, 18, 3500, 0.7908951}, // sinr 12 db
    MappingTable{10, 18, 3500, 1.00},          // sinr 10 db

    // MCS 14, all CBS in continuation use BGtype1
    // CBS=3900, in table corresponds to 3840
    MappingTable{8.9125, 14, 3900, 0.3225703}, // sinr 9.5db
    MappingTable{7.9433, 14, 3900, 0.8827055}, // sinr 9 db
    MappingTable{6.3095, 14, 3900, 1.00},      // sinr 8 db
    // CBS=6300, in table corresponds to 6272
    MappingTable{8.9125, 14, 6300, 0.0237},    // sinr 9.5db
    MappingTable{7.9433, 14, 6300, 0.9990385}, // sinr 9 db
    MappingTable{6.3095, 14, 6300, 1.00}       // sinr 8 db

};
static std::vector<MappingTable> resultTable2 = {
    // sinr (lineal), mcs, cbsize, result

    // MCS 11, all CBS in continuation use BGtype2
    // CBS=3200, in table corresponds to 3104
    MappingTable{19.95, 11, 3200, 0.023},      // sinr 13 db
    MappingTable{15.849, 11, 3200, 0.7567365}, // sinr 12 db
    MappingTable{10, 11, 3200, 1.00},          // sinr 10 db
    // CBS=3500, in table corresponds to 3496
    MappingTable{19.95, 11, 3500, 0.0735},     // sinr 13 db
    MappingTable{15.849, 11, 3500, 0.7908951}, // sinr 12 db
    MappingTable{10, 11, 3500, 1.00},          // sinr 10 db

    // MCS 8, all CBS in continuation use BGtype1
    // CBS=3900, in table corresponds to 3840
    MappingTable{8.9125, 8, 3900, 0.3225703}, // sinr 9.5db
    MappingTable{7.9433, 8, 3900, 0.8827055}, // sinr 9 db
    MappingTable{6.3095, 8, 3900, 1.00},      // sinr 8 db
    // CBS=6300, in table corresponds to 6272
    MappingTable{8.9125, 8, 6300, 0.0237},    // sinr 9.5db
    MappingTable{7.9433, 8, 6300, 0.9990385}, // sinr 9 db
    MappingTable{6.3095, 8, 6300, 1.00}       // sinr 8 db

};

void
MmWaveL2smEesmTestCase::TestMappingSinrBler1(const Ptr<MmWaveEesmErrorModel>& em)
{
    for (auto result : resultTable1)
    {
        NS_TEST_ASSERT_MSG_EQ(
            em->MappingSinrBler(std::get<0>(result), std::get<1>(result), std::get<2>(result)),
            std::get<3>(result),
            "TestMappingSinrBler1: The calculated value differs from "
            " the SINR-BLER table. SINR="
                << std::get<0>(result) << " MCS " << static_cast<uint32_t>(std::get<1>(result))
                << " CBS " << std::get<2>(result));
    }
}

void
MmWaveL2smEesmTestCase::TestMappingSinrBler2(const Ptr<MmWaveEesmErrorModel>& em)
{
    for (auto result : resultTable2)
    {
        NS_TEST_ASSERT_MSG_EQ(
            em->MappingSinrBler(std::get<0>(result), std::get<1>(result), std::get<2>(result)),
            std::get<3>(result),
            "TestMappingSinrBler2: The calculated value differs from "
            " the SINR-BLER table. SINR="
                << std::get<0>(result) << " MCS " << static_cast<uint32_t>(std::get<1>(result))
                << " CBS " << std::get<2>(result));
    }
}

void
MmWaveL2smEesmTestCase::TestEesmCcTable1()
{
    // Create an object of type MmWaveEesmCcT1 and cast it to MmWaveEesmErrorModel
    Ptr<MmWaveEesmErrorModel> em = CreateObject<MmWaveEesmCcT1>();

    // Check that the object was created
    bool ret = em == nullptr;
    NS_TEST_ASSERT_MSG_EQ(ret, false, "Could not create MmWaveEesmCcT1 object");

    // Test here the functions:
    TestBgType1(em);
    TestMappingSinrBler1(em);
}

void
MmWaveL2smEesmTestCase::TestEesmCcTable2()
{
    // Create an object of type MmWaveEesmCcT2 and cast it to MmWaveEesmErrorModel
    Ptr<MmWaveEesmErrorModel> em = CreateObject<MmWaveEesmCcT2>();

    // Check that the object was created
    bool ret = em == nullptr;
    NS_TEST_ASSERT_MSG_EQ(ret, false, "Could not create MmWaveEesmCcT2 object");

    // Test here the functions:
    TestBgType2(em);
    TestMappingSinrBler2(em);
}

void
MmWaveL2smEesmTestCase::TestEesmIrTable1()
{
    // Create an object of type MmWaveEesmIrT1 and cast it to MmWaveEesmErrorModel
    Ptr<MmWaveEesmErrorModel> em = CreateObject<MmWaveEesmIrT1>();

    // Check that the object was created
    bool ret = em == nullptr;
    NS_TEST_ASSERT_MSG_EQ(ret, false, "Could not create MmWaveEesmIrT1 object");

    // Test here the functions:
    TestBgType1(em);
    TestMappingSinrBler1(em);
}

void
MmWaveL2smEesmTestCase::TestEesmIrTable2()
{
    // Create an object of type MmWaveEesmIrT2 and cast it to MmWaveEesmErrorModel
    Ptr<MmWaveEesmErrorModel> em = CreateObject<MmWaveEesmIrT2>();

    // Check that the object was created
    bool ret = em == nullptr;
    NS_TEST_ASSERT_MSG_EQ(ret, false, "Could not create MmWaveEesmIrT2 object");

    // Test here the functions:
    TestBgType2(em);
    TestMappingSinrBler2(em);
}

void
MmWaveL2smEesmTestCase::DoRun()
{
    TestEesmCcTable1();
    TestEesmCcTable2();
    TestEesmIrTable1();
    TestEesmIrTable2();
}

class MmWaveTestL2smEesm : public TestSuite
{
  public:
    MmWaveTestL2smEesm()
        : TestSuite("mmwave-l2sm-test", UNIT)
    {
        AddTestCase(new MmWaveL2smEesmTestCase("First test"), QUICK);
    }
};

static MmWaveTestL2smEesm mmwaveTestSuite; //!< MmWave test suite
