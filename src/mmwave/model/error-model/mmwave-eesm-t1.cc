#include "mmwave-eesm-t1.h"

namespace ns3
{

namespace mmwave
{

/**
 * \brief Table of SE of the standard MCSs: 29 (0 to 28) MCSs as per Table1 in TS38.214
 */
static const std::vector<double> SpectralEfficiencyForMcs1 = {
    // QPSK (M=2)
    0.23,
    0.31,
    0.38,
    0.49,
    0.6,
    0.74,
    0.88,
    1.03,
    1.18,
    1.33, // SEs of MCSs
    // 16QAM (M=4)
    1.33,
    1.48,
    1.70,
    1.91,
    2.16,
    2.41,
    2.57, // SEs of MCSs
    // 64QAM (M=6)
    2.57,
    2.73,
    3.03,
    3.32,
    3.61,
    3.90,
    4.21,
    4.52,
    4.82,
    5.12,
    5.33,
    5.55 // SEs of MCSs
};

/**
 * \brief Table of SE of the standard CQIs: 16 CQIs as per Table1 in TS38.214
 */
static const std::vector<double> SpectralEfficiencyForCqi1 = {0.0, // out of range
                                                              0.15,
                                                              0.23,
                                                              0.38,
                                                              0.6,
                                                              0.88,
                                                              1.18,
                                                              1.48,
                                                              1.91,
                                                              2.41,
                                                              2.73,
                                                              3.32,
                                                              3.9,
                                                              4.52,
                                                              5.12,
                                                              5.55};

/**
 * \brief SINR to BLER mapping for MCSs in Table1
 */
static const MmWaveEesmErrorModel::SimulatedBlerFromSINR BlerForSinr1 = {
    { // BG TYPE 1
     {// MCS 0
      {0U, MmWaveEesmErrorModel::DoubleTuple{{0.0}, {0.0}}}},
     {// MCS 1
      {0U, MmWaveEesmErrorModel::DoubleTuple{{0.0}, {0.0}}}},
     {// MCS 2
      {0U, MmWaveEesmErrorModel::DoubleTuple{{0.0}, {0.0}}}},
     {// MCS 3
      {0U, MmWaveEesmErrorModel::DoubleTuple{{0.0}, {0.0}}}},
     {        // MCS 4
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.247500e+00, 1.730000e+00, 1.965000e+00, 2.200000e+00, 2.682500e+00}, // SINR
           {1, 6.107143e-01, 1.336713e-01, 5.800000e-03, 0}                        // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {5.300000e-01,
            1.247500e+00,
            1.730000e+00,
            1.965000e+00,
            2.200000e+00,
            2.682500e+00},                                                // SINR
           {1, 9.990385e-01, 4.936275e-01, 6.590000e-02, 1.800000e-03, 0} // BLER
       }},
      {4224U, // SINR and BLER for CBS 4224
       MmWaveEesmErrorModel::DoubleTuple{
           {8.300000e-01,
            1.330000e+00,
            1.580000e+00,
            1.830000e+00,
            2.330000e+00,
            3.080000e+00},                                                // SINR
           {1, 9.942308e-01, 8.384740e-01, 2.903226e-01, 1.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {8.300000e-01,
            1.485000e+00,
            1.920000e+00,
            2.140000e+00,
            2.360000e+00,
            2.795000e+00},                                                // SINR
           {1, 9.664179e-01, 1.431612e-01, 6.600000e-03, 1.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.150000e+00,
            1.587500e+00,
            1.880000e+00,
            2.025000e+00,
            2.170000e+00,
            2.462500e+00},                                                // SINR
           {1, 9.425182e-01, 3.457084e-01, 8.510000e-02, 9.100000e-03, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {9.100000e-01,
            1.407500e+00,
            1.740000e+00,
            1.905000e+00,
            2.070000e+00,
            2.402500e+00},                                                // SINR
           {1, 9.828244e-01, 5.014881e-01, 1.342444e-01, 1.590000e-02, 0} // BLER
       }},
      {6144U, // SINR and BLER for CBS 6144
       MmWaveEesmErrorModel::DoubleTuple{
           {1.100000e+00, 1.625000e+00, 2.150000e+00, 2.675000e+00}, // SINR
           {1, 7.973602e-01, 3.400000e-03, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.400000e+00,
            1.680000e+00,
            1.812500e+00,
            1.950000e+00,
            2.225000e+00,
            2.637500e+00},                                                           // SINR
           {9.942308e-01, 6.936141e-01, 3.416442e-01, 9.228120e-02, 4.000000e-04, 0} // BLER
       }},
      {7168U, // SINR and BLER for CBS 7168
       MmWaveEesmErrorModel::DoubleTuple{
           {1.200000e+00,
            1.550000e+00,
            1.725000e+00,
            1.900000e+00,
            2.250000e+00,
            2.775000e+00},                                                // SINR
           {1, 9.257246e-01, 5.852535e-01, 1.739583e-01, 3.000000e-04, 0} // BLER
       }},
      {8064U, // SINR and BLER for CBS 8064
       MmWaveEesmErrorModel::DoubleTuple{
           {8.000000e-01,
            1.375000e+00,
            1.760000e+00,
            1.950000e+00,
            2.140000e+00,
            2.525000e+00},                                                // SINR
           {1, 9.951923e-01, 5.070000e-01, 1.073718e-01, 5.700000e-03, 0} // BLER
       }}},
     {        // MCS 5
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.660000e+00, 2.070000e+00, 2.480000e+00, 2.890000e+00, 3.300000e+00}, // SINR
           {1, 9.961538e-01, 7.266949e-01, 4.200000e-02, 0}                        // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.600000e+00, 2.310000e+00, 2.670000e+00, 3.030000e+00, 3.740000e+00}, // SINR
           {1, 9.498175e-01, 2.741848e-01, 3.000000e-03, 0}                        // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.600000e+00, 2.160000e+00, 2.432500e+00, 2.710000e+00, 3.265000e+00}, // SINR
           {1, 9.865385e-01, 7.385057e-01, 1.674434e-01, 0}                        // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {2.070000e+00, 2.465000e+00, 2.860000e+00, 3.255000e+00}, // SINR
           {1, 7.581361e-01, 4.100000e-02, 0}                        // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.500000e+00, 2.130000e+00, 2.437500e+00, 2.750000e+00, 3.375000e+00}, // SINR
           {1, 9.990385e-01, 8.826531e-01, 1.996417e-01, 0}                        // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.600000e+00, 2.300000e+00, 2.770000e+00, 3, 3.230000e+00}, // SINR
           {1, 9.489051e-01, 9.651115e-02, 3.400000e-03, 0}             // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.400000e+00, 2.200000e+00, 2.730000e+00, 3, 3.270000e+00}, // SINR
           {1, 9.951923e-01, 1.776408e-01, 3.500000e-03, 0}             // BLER
       }},
      {6400U, // SINR and BLER for CBS 6400
       MmWaveEesmErrorModel::DoubleTuple{
           {1.900000e+00,
            2.325000e+00,
            2.610000e+00,
            2.750000e+00,
            2.890000e+00,
            3.175000e+00},                                                // SINR
           {1, 9.199640e-01, 2.974646e-01, 6.550000e-02, 6.300000e-03, 0} // BLER
       }},
      {7552U, // SINR and BLER for CBS 7552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.700000e+00, 2.340000e+00, 2.657500e+00, 2.980000e+00, 3.615000e+00}, // SINR
           {1, 9.366071e-01, 2.765899e-01, 3.500000e-03, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.800000e+00, 2.480000e+00, 2.812500e+00, 3.150000e+00}, // SINR
           {1, 6.337500e-01, 2.920000e-02, 0}                        // BLER
       }}},
     {        // MCS 6
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {2.500000e+00, 2.937500e+00, 3.375000e+00, 3.812500e+00, 4.250000e+00}, // SINR
           {1, 9.836538e-01, 3.882979e-01, 3.600000e-03, 0}                        // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {2.750000e+00, 3.187500e+00, 3.625000e+00, 4.062500e+00}, // SINR
           {9.990385e-01, 6.552835e-01, 1.330000e-02, 0}             // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {2.680000e+00, 3.072500e+00, 3.465000e+00, 3.857500e+00, 4.250000e+00}, // SINR
           {1, 8.511513e-01, 9.743852e-02, 2.000000e-04, 0}                        // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {2.730000e+00, 3.072500e+00, 3.415000e+00, 3.757500e+00, 4.100000e+00}, // SINR
           {1, 9.476103e-01, 3.244885e-01, 4.100000e-03, 0}                        // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {2.500000e+00,
            2.970000e+00,
            3.280000e+00,
            3.440000e+00,
            3.600000e+00,
            3.910000e+00,
            4.380000e+00},                                                              // SINR
           {1, 9.836538e-01, 5.947674e-01, 2.395636e-01, 4.410000e-02, 1.000000e-04, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {2.100000e+00, 3, 3.300000e+00, 3.600000e+00, 3.900000e+00}, // SINR
           {1, 9.552920e-01, 4.180464e-01, 1.930000e-02, 0}             // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {2.830000e+00, 3.172500e+00, 3.515000e+00, 3.857500e+00, 4.200000e+00}, // SINR
           {1, 8.948276e-01, 1.525579e-01, 2.000000e-04, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {2.880000e+00, 3.217500e+00, 3.555000e+00, 3.892500e+00}, // SINR
           {9.990385e-01, 7.223011e-01, 5.800000e-02, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {2.800000e+00,
            3.175000e+00,
            3.430000e+00,
            3.550000e+00,
            3.680000e+00,
            3.925000e+00},                                                // SINR
           {1, 9.316547e-01, 3.304036e-01, 1.097454e-01, 1.650000e-02, 0} // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {2.800000e+00, 3.150000e+00, 3.500000e+00, 3.850000e+00}, // SINR
           {1, 8.007813e-01, 6.460000e-02, 0}                        // BLER
       }}},
     {        // MCS 7
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {3.210000e+00, 3.670000e+00, 3.905000e+00, 4.140000e+00, 4.600000e+00}, // SINR
           {1, 9.498175e-01, 5.937500e-01, 1.341561e-01, 0}                        // BLER
       }},
      {4032U, // SINR and BLER for CBS 4032
       MmWaveEesmErrorModel::DoubleTuple{
           {3.505800e+00, 3.920000e+00, 4.131400e+00, 4.340000e+00, 4.757000e+00}, // SINR
           {9.971154e-01, 5.647124e-01, 1.275329e-01, 7.800000e-03, 0}             // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {3, 3.400000e+00, 3.800000e+00, 4.200000e+00, 4.600000e+00}, // SINR
           {1, 9.990385e-01, 8.295455e-01, 7.440000e-02, 1.000000e-04}  // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {3.350000e+00,
            3.730000e+00,
            3.912500e+00,
            4.100000e+00,
            4.475000e+00,
            5.037500e+00},                                                // SINR
           {1, 9.163732e-01, 6.060427e-01, 1.863905e-01, 8.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {3.560800e+00, 3.950000e+00, 4.138000e+00, 4.330000e+00, 4.715300e+00}, // SINR
           {9.932692e-01, 5.287657e-01, 1.362284e-01, 1.140000e-02, 0}             // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {3.200000e+00, 3.775000e+00, 4.350000e+00, 4.925000e+00}, // SINR
           {1, 8.724662e-01, 2.900000e-03, 0}                        // BLER
       }},
      {5632U, // SINR and BLER for CBS 5632
       MmWaveEesmErrorModel::DoubleTuple{
           {3.217600e+00,
            3.600000e+00,
            3.797200e+00,
            3.990000e+00,
            4.376900e+00,
            4.956500e+00},                                                // SINR
           {1, 9.798077e-01, 7.356322e-01, 2.335952e-01, 3.000000e-04, 0} // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {3.208800e+00,
            3.663000e+00,
            3.970000e+00,
            4.117300e+00,
            4.270000e+00,
            4.571500e+00},                                                // SINR
           {1, 9.778846e-01, 4.511649e-01, 1.352481e-01, 1.810000e-02, 0} // BLER
       }},
      {7296U, // SINR and BLER for CBS 7296
       MmWaveEesmErrorModel::DoubleTuple{
           {3.200000e+00, 3.762500e+00, 4.140000e+00, 4.325000e+00, 4.510000e+00}, // SINR
           {1, 9.357143e-01, 1.146122e-01, 6.000000e-03, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {3.304500e+00, 3.728600e+00, 4.152600e+00, 4.576600e+00}, // SINR
           {9.990385e-01, 8.879310e-01, 4.210000e-02, 0}             // BLER
       }}},
     {        // MCS 8
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {4.400000e+00, 4.675000e+00, 4.950000e+00, 5.225000e+00, 5.500000e+00}, // SINR
           {9.546296e-01, 5.407839e-01, 7.560000e-02, 1.800000e-03, 0}             // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {4.258500e+00, 4.509200e+00, 4.760000e+00, 5.010700e+00, 5.261500e+00}, // SINR
           {9.903846e-01, 8.172468e-01, 2.485149e-01, 1.240000e-02, 2.000000e-04}  // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {4.100000e+00, 4.550000e+00, 5, 5.450000e+00}, // SINR
           {1, 7.371429e-01, 1.280000e-02, 0}             // BLER
       }},
      {4608U, // SINR and BLER for CBS 4608
       MmWaveEesmErrorModel::DoubleTuple{
           {3.800000e+00,
            4.250000e+00,
            4.550000e+00,
            4.700000e+00,
            4.850000e+00,
            5.150000e+00,
            5.600000e+00},                                                              // SINR
           {1, 9.971154e-01, 7.934451e-01, 4.168033e-01, 1.133167e-01, 9.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {4.300000e+00, 4.550000e+00, 4.800000e+00, 5.050000e+00, 5.300000e+00}, // SINR
           {9.836538e-01, 7.619048e-01, 2.128608e-01, 8.900000e-03, 1.000000e-04}  // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {3.850000e+00, 4.287500e+00, 4.725000e+00, 5.162500e+00, 5.600000e+00}, // SINR
           {1, 9.884615e-01, 3.526536e-01, 1.100000e-03, 0}                        // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {4, 4.375000e+00, 4.750000e+00, 5.125000e+00, 5.500000e+00}, // SINR
           {1, 9.884615e-01, 3.973354e-01, 2.600000e-03, 0}             // BLER
       }},
      {6528U, // SINR and BLER for CBS 6528
       MmWaveEesmErrorModel::DoubleTuple{
           {4.400000e+00, 4.675000e+00, 4.950000e+00, 5.225000e+00, 5.500000e+00}, // SINR
           {9.942308e-01, 7.021858e-01, 8.430937e-02, 4.000000e-04, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {4.200000e+00, 4.600000e+00, 5, 5.400000e+00}, // SINR
           {1, 7.774390e-01, 2.110000e-02, 0}             // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {4.005500e+00,
            4.406800e+00,
            4.670000e+00,
            4.808200e+00,
            4.940000e+00,
            5.209600e+00,
            5.610900e+00},                                                              // SINR
           {1, 9.465580e-01, 4.442509e-01, 1.276650e-01, 1.910000e-02, 1.000000e-04, 0} // BLER
       }}},
     {        // MCS 9
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {4.500000e+00, 4.900000e+00, 5.300000e+00, 5.700000e+00, 6.100000e+00}, // SINR
           {1, 9.990385e-01, 8.559603e-01, 1.185142e-01, 7.000000e-04}             // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {4.800000e+00, 5.225000e+00, 5.650000e+00, 6.075000e+00}, // SINR
           {1, 8.250000e-01, 6.090000e-02, 0}                        // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {4.603200e+00,
            5.115600e+00,
            5.460000e+00,
            5.628000e+00,
            5.800000e+00,
            6.140400e+00,
            6.652800e+00},                                                              // SINR
           {1, 9.673507e-01, 4.353596e-01, 1.145833e-01, 1.220000e-02, 1.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {4.800000e+00, 5.300000e+00, 5.550000e+00, 5.800000e+00, 6.300000e+00}, // SINR
           {1, 7.842988e-01, 2.034036e-01, 7.700000e-03, 0}                        // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {4.953500e+00, 5.276300e+00, 5.599100e+00, 5.921900e+00, 6.244700e+00}, // SINR
           {1, 9.317376e-01, 2.850679e-01, 3.800000e-03, 0}                        // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {5.003900e+00, 5.456900e+00, 5.909900e+00, 6.362900e+00}, // SINR
           {9.942308e-01, 4.560932e-01, 2.200000e-03, 0}             // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {4.600000e+00,
            5.100000e+00,
            5.430000e+00,
            5.600000e+00,
            5.770000e+00,
            6.100000e+00},                                                // SINR
           {1, 9.932692e-01, 5.336134e-01, 1.555556e-01, 1.820000e-02, 0} // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {4.800000e+00,
            5.250000e+00,
            5.550000e+00,
            5.700000e+00,
            5.850000e+00,
            6.150000e+00},                                                // SINR
           {1, 9.307554e-01, 2.857143e-01, 6.010000e-02, 5.500000e-03, 0} // BLER
       }},
      {7296U, // SINR and BLER for CBS 7296
       MmWaveEesmErrorModel::DoubleTuple{
           {4.986800e+00,
            5.320000e+00,
            5.486800e+00,
            5.650000e+00,
            5.986800e+00,
            6.486800e+00},                                                           // SINR
           {9.990385e-01, 8.388158e-01, 4.005503e-01, 8.560000e-02, 1.000000e-04, 0} // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {4.700000e+00,
            5.150000e+00,
            5.450000e+00,
            5.600000e+00,
            5.750000e+00,
            6.050000e+00},                                                // SINR
           {1, 9.640152e-01, 4.233333e-01, 1.113596e-01, 1.280000e-02, 0} // BLER
       }}},
     {        // MCS 10
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {5.427500e+00, 6.080000e+00, 6.407600e+00, 6.730000e+00, 7.387700e+00}, // SINR
           {1, 7.362717e-01, 8.080000e-02, 4.000000e-04, 0}                        // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {5.500000e+00, 6.005600e+00, 6.511200e+00, 7.016700e+00}, // SINR
           {1, 7.329545e-01, 2.500000e-03, 0}                        // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {5.400000e+00, 5.950000e+00, 6.500000e+00, 7.050000e+00}, // SINR
           {1, 8.967014e-01, 5.400000e-03, 0}                        // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {4.900000e+00,
            5.775000e+00,
            6.070000e+00,
            6.360000e+00,
            6.650000e+00,
            7.525000e+00},                                                // SINR
           {1, 9.932692e-01, 6.627604e-01, 5.410000e-02, 1.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {5.400000e+00,
            5.850000e+00,
            6.150000e+00,
            6.300000e+00,
            6.450000e+00,
            6.750000e+00},                                                // SINR
           {1, 9.923077e-01, 6.425879e-01, 2.392857e-01, 2.900000e-02, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {5.500000e+00,
            5.950000e+00,
            6.250000e+00,
            6.400000e+00,
            6.550000e+00,
            6.850000e+00},                                                // SINR
           {1, 9.163732e-01, 2.252232e-01, 3.710000e-02, 1.700000e-03, 0} // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {5.301600e+00,
            5.864100e+00,
            6.240000e+00,
            6.426600e+00,
            6.610000e+00,
            6.989100e+00},                                                // SINR
           {1, 9.884615e-01, 2.865646e-01, 2.200000e-02, 4.000000e-04, 0} // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {5.200000e+00,
            5.743800e+00,
            6.110000e+00,
            6.287500e+00,
            6.470000e+00,
            6.831200e+00},                                                // SINR
           {1, 9.980769e-01, 6.734293e-01, 1.668874e-01, 8.600000e-03, 0} // BLER
       }},
      {7296U, // SINR and BLER for CBS 7296
       MmWaveEesmErrorModel::DoubleTuple{
           {5.950000e+00, 6.137500e+00, 6.325000e+00, 6.512500e+00, 6.700000e+00}, // SINR
           {9.518519e-01, 5.514069e-01, 7.160000e-02, 1.800000e-03, 0}             // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {5.776700e+00, 6.050600e+00, 6.324600e+00, 6.598500e+00}, // SINR
           {9.971154e-01, 7.448529e-01, 5.430000e-02, 0}             // BLER
       }}},
     {        // MCS 11
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {6.139500e+00, 6.479600e+00, 6.819600e+00, 7.159700e+00, 7.499800e+00}, // SINR
           {1, 9.770992e-01, 4.874517e-01, 1.410000e-02, 0}                        // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {6.163800e+00, 6.511000e+00, 6.858200e+00, 7.205300e+00, 7.552500e+00}, // SINR
           {1, 9.122340e-01, 2.001192e-01, 1.000000e-03, 0}                        // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {6.193800e+00, 6.590000e+00, 6.791300e+00, 6.990000e+00, 7.388800e+00}, // SINR
           {1, 7.989130e-01, 2.857545e-01, 2.860000e-02, 0}                        // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {6, 6.525000e+00, 6.880000e+00, 7.050000e+00, 7.230000e+00, 7.575000e+00}, // SINR
           {1, 9.509259e-01, 1.926448e-01, 2.070000e-02, 7.000000e-04, 0}             // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {6, 6.575000e+00, 6.960000e+00, 7.150000e+00, 7.340000e+00}, // SINR
           {1, 9.045139e-01, 5.810000e-02, 1.100000e-03, 0}             // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {5.823000e+00, 6.453200e+00, 6.870000e+00, 7.083400e+00, 7.290000e+00}, // SINR
           {1, 9.770992e-01, 1.452312e-01, 3.600000e-03, 0}                        // BLER
       }},
      {5760U, // SINR and BLER for CBS 5760
       MmWaveEesmErrorModel::DoubleTuple{
           {6.008100e+00,
            6.446900e+00,
            6.740000e+00,
            6.885700e+00,
            7.030000e+00,
            7.324500e+00},                                                // SINR
           {1, 9.654851e-01, 3.772388e-01, 7.960000e-02, 7.400000e-03, 0} // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {6.071200e+00,
            6.517900e+00,
            6.820000e+00,
            6.964500e+00,
            7.110000e+00,
            7.411200e+00},                                                // SINR
           {1, 9.826923e-01, 4.340753e-01, 9.364919e-02, 7.900000e-03, 0} // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {6.300000e+00, 6.706200e+00, 7.112500e+00, 7.518700e+00}, // SINR
           {1, 6.994536e-01, 1.900000e-03, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {6, 6.468800e+00, 6.780000e+00, 6.937500e+00, 7.090000e+00, 7.406200e+00}, // SINR
           {1, 9.990385e-01, 6.453046e-01, 1.720246e-01, 1.300000e-02, 0}             // BLER
       }}},
     {        // MCS 12
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {7.036100e+00, 7.363400e+00, 7.690600e+00, 8.017900e+00, 8.345100e+00}, // SINR
           {9.990385e-01, 9.001736e-01, 2.305403e-01, 2.100000e-03, 0}             // BLER
       }},
      {4032U, // SINR and BLER for CBS 4032
       MmWaveEesmErrorModel::DoubleTuple{
           {7.156200e+00, 7.421100e+00, 7.686000e+00, 7.951000e+00, 8.215900e+00}, // SINR
           {9.990385e-01, 9.302536e-01, 4.011076e-01, 2.410000e-02, 5.000000e-04}  // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {6.650000e+00,
            7.122200e+00,
            7.440000e+00,
            7.594500e+00,
            7.750000e+00,
            8.066700e+00,
            8.538900e+00},                                                              // SINR
           {1, 9.990385e-01, 8.607383e-01, 5.209184e-01, 1.716826e-01, 7.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {6.912700e+00,
            7.342700e+00,
            7.630000e+00,
            7.772700e+00,
            7.920000e+00,
            8.202700e+00},                                                // SINR
           {1, 9.370438e-01, 3.542837e-01, 8.668544e-02, 1.050000e-02, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {6.960000e+00,
            7.324600e+00,
            7.570000e+00,
            7.689200e+00,
            7.810000e+00,
            8.053900e+00,
            8.418500e+00},                                                              // SINR
           {1, 9.727444e-01, 6.130383e-01, 2.946636e-01, 8.160000e-02, 9.000000e-04, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {6.342900e+00, 7.269100e+00, 7.580000e+00, 7.890000e+00, 8.195400e+00}, // SINR
           {1, 9.942308e-01, 6.225490e-01, 2.880000e-02, 0}                        // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {7, 7.420000e+00, 7.625000e+00, 7.830000e+00, 8.250000e+00}, // SINR
           {1, 8.741497e-01, 3.327836e-01, 2.290000e-02, 0}             // BLER
       }},
      {6656U, // SINR and BLER for CBS 6656
       MmWaveEesmErrorModel::DoubleTuple{
           {7, 7.370000e+00, 7.550000e+00, 7.730000e+00, 8.100000e+00, 8.650000e+00}, // SINR
           {1, 9.715909e-01, 7.060440e-01, 1.843842e-01, 2.000000e-04, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {7.100000e+00, 7.475000e+00, 7.850000e+00, 8.225000e+00}, // SINR
           {1, 8.344156e-01, 2.220000e-02, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {7.300000e+00, 7.600000e+00, 7.750000e+00, 7.900000e+00, 8.200000e+00}, // SINR
           {9.913462e-01, 3.776042e-01, 6.510000e-02, 4.500000e-03, 0}             // BLER
       }}},
     {        // MCS 13
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {7.500000e+00, 7.875000e+00, 8.250000e+00, 8.625000e+00, 9}, // SINR
           {1, 9.971154e-01, 5.805180e-01, 2.100000e-02, 1.000000e-04}  // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {7.500000e+00, 7.850000e+00, 8.200000e+00, 8.550000e+00, 8.900000e+00}, // SINR
           {1, 9.980769e-01, 6.381250e-01, 3.460000e-02, 0}                        // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {7.500000e+00,
            7.970000e+00,
            8.200000e+00,
            8.430000e+00,
            8.900000e+00,
            9.600000e+00},                                                // SINR
           {1, 9.770992e-01, 6.858289e-01, 1.487884e-01, 2.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {7.830000e+00, 8.210000e+00, 8.400000e+00, 8.590000e+00, 8.975000e+00}, // SINR
           {1, 7.463873e-01, 2.925287e-01, 3.730000e-02, 0}                        // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {7.500000e+00,
            7.975000e+00,
            8.290000e+00,
            8.450000e+00,
            8.610000e+00,
            8.925000e+00,
            9.400000e+00},                                                              // SINR
           {1, 9.961538e-01, 6.854839e-01, 2.876712e-01, 5.060000e-02, 2.000000e-04, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {7.400000e+00,
            8.070000e+00,
            8.400000e+00,
            8.730000e+00,
            9.400000e+00,
            1.040000e+01},                                                // SINR
           {1, 9.524254e-01, 3.061594e-01, 2.800000e-03, 1.000000e-04, 0} // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {7.600000e+00, 8.200000e+00, 8.500000e+00, 8.800000e+00, 9.400000e+00}, // SINR
           {1, 8.641667e-01, 1.451333e-01, 9.000000e-04, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00, 8.210000e+00, 8.573700e+00, 8.940000e+00}, // SINR
           {1, 8.933566e-01, 5.790000e-02, 0}                        // BLER
       }},
      {7552U, // SINR and BLER for CBS 7552
       MmWaveEesmErrorModel::DoubleTuple{
           {7.980000e+00, 8.420000e+00, 8.635000e+00, 8.850000e+00, 9.290000e+00}, // SINR
           {9.980769e-01, 3.709677e-01, 1.890000e-02, 1.000000e-04, 0}             // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            8.120000e+00,
            8.340000e+00,
            8.449800e+00,
            8.560000e+00,
            8.780000e+00,
            9.430300e+00},                                                              // SINR
           {1, 9.527778e-01, 4.825472e-01, 1.947674e-01, 4.330000e-02, 4.000000e-04, 0} // BLER
       }}},
     {        // MCS 14
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {8.075000e+00,
            8.660000e+00,
            8.950000e+00,
            9.240000e+00,
            9.825000e+00,
            1.070000e+01},                                                // SINR
           {1, 9.990385e-01, 8.827055e-01, 3.225703e-01, 1.000000e-04, 0} // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {8.700000e+00, 9.067500e+00, 9.435000e+00, 9.802500e+00}, // SINR
           {9.980769e-01, 6.602564e-01, 3.350000e-02, 0}             // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {8.175000e+00,
            8.690000e+00,
            8.950000e+00,
            9.210000e+00,
            9.725000e+00,
            1.050000e+01},                                                // SINR
           {1, 9.971154e-01, 8.907343e-01, 3.275194e-01, 2.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {8.700000e+00, 9.112500e+00, 9.525000e+00, 9.937500e+00}, // SINR
           {9.971154e-01, 5.393908e-01, 5.700000e-03, 0}             // BLER
       }},
      {5120U, // SINR and BLER for CBS 5120
       MmWaveEesmErrorModel::DoubleTuple{
           {8, 8.740000e+00, 9.105100e+00, 9.470000e+00, 1.021010e+01}, // SINR
           {1, 9.971154e-01, 7.947531e-01, 4.930000e-02, 0}             // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00, 9.130000e+00, 9.510000e+00, 9.902500e+00}, // SINR
           {1, 6.393750e-01, 2.060000e-02, 0}                        // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00, 9.100000e+00, 9.470000e+00, 9.840600e+00}, // SINR
           {9.990385e-01, 7.281073e-01, 2.370000e-02, 0}             // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00, 9.080000e+00, 9.430000e+00, 9.778700e+00, 1.082090e+01}, // SINR
           {9.990385e-01, 7.427746e-01, 3.350000e-02, 1.000000e-04, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.060000e+00,
            9.280000e+00,
            9.390000e+00,
            9.500000e+00,
            9.716900e+00,
            1.069720e+01},                                                              // SINR
           {1, 9.093310e-01, 3.563380e-01, 1.177162e-01, 2.170000e-02, 1.000000e-04, 0} // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {8.052500e+00, 8.865900e+00, 9.140000e+00, 9.410000e+00, 9.679300e+00}, // SINR
           {1, 9.903846e-01, 6.123188e-01, 3.500000e-02, 0}                        // BLER
       }}},
     {        // MCS 15
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {8.590100e+00,
            9.770000e+00,
            1.016000e+01,
            1.035700e+01,
            1.056000e+01,
            1.095000e+01},                                                // SINR
           {1, 9.790076e-01, 5.559211e-01, 1.849340e-01, 2.350000e-02, 0} // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {9.286000e+00, 1.008000e+01, 1.047910e+01, 1.088000e+01}, // SINR
           {1, 4.729478e-01, 1.020000e-02, 0}                        // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {8.713900e+00,
            9.790000e+00,
            1.015000e+01,
            1.032600e+01,
            1.050000e+01,
            1.086000e+01},                                                // SINR
           {1, 9.522059e-01, 3.103448e-01, 6.040000e-02, 4.100000e-03, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {9.250000e+00, 9.990000e+00, 1.035920e+01, 1.073000e+01, 1.146850e+01}, // SINR
           {1, 6.705729e-01, 3.740000e-02, 1.000000e-04, 0}                        // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {9.143700e+00,
            9.680000e+00,
            9.941600e+00,
            1.021000e+01,
            1.073950e+01,
            1.153750e+01},                                                // SINR
           {1, 9.894231e-01, 8.066038e-01, 1.856563e-01, 1.000000e-04, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {9.135600e+00, 9.830000e+00, 1.018060e+01, 1.053000e+01, 1.122560e+01}, // SINR
           {1, 9.244604e-01, 1.925883e-01, 1.000000e-03, 0}                        // BLER
       }},
      {5632U, // SINR and BLER for CBS 5632
       MmWaveEesmErrorModel::DoubleTuple{
           {9.125000e+00, 9.790000e+00, 1.012620e+01, 1.046000e+01, 1.112740e+01}, // SINR
           {1, 9.537037e-01, 2.420977e-01, 1.600000e-03, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {9.085300e+00, 1.000360e+01, 1.031000e+01, 1.062000e+01, 1.092190e+01}, // SINR
           {1, 9.005282e-01, 2.451362e-01, 3.500000e-03, 0}                        // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00, 9.870000e+00, 1.020220e+01, 1.053000e+01, 1.119530e+01}, // SINR
           {1, 9.875000e-01, 4.294764e-01, 6.000000e-03, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00,
            9.870000e+00,
            1.009000e+01,
            1.020220e+01,
            1.031000e+01,
            1.053000e+01,
            1.119530e+01},                                                              // SINR
           {1, 9.456522e-01, 4.937016e-01, 2.031250e-01, 5.280000e-02, 6.000000e-04, 0} // BLER
       }}},
     {        // MCS 16
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.030000e+01, 1.068250e+01, 1.106500e+01, 1.144750e+01, 1.183000e+01}, // SINR
           {9.761450e-01, 5.619469e-01, 3.500000e-02, 2.000000e-04, 0}             // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {9.690000e+00, 1.043000e+01, 1.117250e+01, 1.191500e+01}, // SINR
           {1, 8.835616e-01, 1.200000e-03, 0}                        // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {9.640800e+00, 1.024000e+01, 1.054610e+01, 1.085000e+01, 1.145150e+01}, // SINR
           {1, 9.961538e-01, 8.136792e-01, 1.850220e-01, 0}                        // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {9.702700e+00, 1.047000e+01, 1.084790e+01, 1.123000e+01}, // SINR
           {1, 8.423203e-01, 1.084639e-01, 0}                        // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {9.764600e+00, 1.049000e+01, 1.084790e+01, 1.121000e+01, 1.193120e+01}, // SINR
           {1, 8.853448e-01, 1.578204e-01, 7.000000e-04, 0}                        // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.023060e+01, 1.081000e+01, 1.110450e+01, 1.140000e+01}, // SINR
           {9.980769e-01, 2.500000e-01, 7.100000e-03, 0}             // BLER
       }},
      {6144U, // SINR and BLER for CBS 6144
       MmWaveEesmErrorModel::DoubleTuple{
           {1.025000e+01, 1.077000e+01, 1.102630e+01, 1.129000e+01, 1.180250e+01}, // SINR
           {1, 6.549745e-01, 1.022918e-01, 8.000000e-04, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.021290e+01, 1.074000e+01, 1.099840e+01, 1.126000e+01, 1.178400e+01}, // SINR
           {9.990385e-01, 6.059524e-01, 9.010459e-02, 9.000000e-04, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.017250e+01, 1.070000e+01, 1.096820e+01, 1.123000e+01, 1.176380e+01}, // SINR
           {1, 7.286932e-01, 1.131222e-01, 1.600000e-03, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.031250e+01, 1.057000e+01, 1.082000e+01, 1.107310e+01, 1.183380e+01}, // SINR
           {9.913462e-01, 7.168079e-01, 1.062126e-01, 1.000000e-03, 0}             // BLER
       }}},
     {        // MCS 17
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {11, 1.137500e+01, 1.175000e+01, 1.212500e+01, 1.250000e+01}, // SINR
           {9.942308e-01, 7.226124e-01, 7.890000e-02, 5.000000e-04, 0}   // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.002380e+01,
            1.082790e+01,
            1.136000e+01,
            1.163190e+01,
            1.190000e+01,
            1.243600e+01},                                                // SINR
           {1, 9.971154e-01, 6.413317e-01, 1.254990e-01, 4.200000e-03, 0} // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.159000e+01, 1.197210e+01, 1.235000e+01}, // SINR
           {1, 2.418426e-01, 2.000000e-03, 0}                        // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.137000e+01,
            1.163960e+01,
            1.191000e+01,
            1.245130e+01,
            1.326310e+01},                                                // SINR
           {1, 5.927419e-01, 8.954327e-02, 8.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.147000e+01, 1.178640e+01, 1.211000e+01}, // SINR
           {1, 4.636949e-01, 1.870000e-02, 0}                        // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.138000e+01, 1.166260e+01, 1.194000e+01, 1.249730e+01}, // SINR
           {1, 5.669643e-01, 5.120000e-02, 3.000000e-04, 0}                        // BLER
       }},
      {6016U, // SINR and BLER for CBS 6016
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.138000e+01, 1.166260e+01, 1.194000e+01, 1.249730e+01}, // SINR
           {1, 5.292887e-01, 3.740000e-02, 1.000000e-04, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.138000e+01, 1.166260e+01, 1.194000e+01, 1.249730e+01}, // SINR
           {1, 8.691667e-01, 2.263393e-01, 5.900000e-03, 0}                        // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.138000e+01, 1.166260e+01, 1.194000e+01, 1.249730e+01}, // SINR
           {1, 9.060284e-01, 2.320111e-01, 4.800000e-03, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.138000e+01, 1.166260e+01, 1.194000e+01, 1.249730e+01}, // SINR
           {1, 6.363065e-01, 4.330000e-02, 1.000000e-04, 0}                        // BLER
       }}},
     {        // MCS 18
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.042550e+01, 1.146000e+01, 1.198460e+01, 1.250000e+01, 1.354370e+01}, // SINR
           {1, 9.961538e-01, 5.806818e-01, 6.000000e-03, 0}                        // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.088260e+01,
            1.167280e+01,
            1.220000e+01,
            1.246300e+01,
            1.273000e+01,
            1.325330e+01,
            1.404350e+01},                                                              // SINR
           {1, 9.038462e-01, 7.320000e-02, 1.300000e-03, 1.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.092380e+01,
            1.167280e+01,
            1.217000e+01,
            1.242170e+01,
            1.267000e+01,
            1.317070e+01,
            1.391970e+01},                                                              // SINR
           {1, 9.790076e-01, 2.155394e-01, 1.460000e-02, 2.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.067310e+01,
            1.167280e+01,
            1.201000e+01,
            1.234000e+01,
            1.267240e+01,
            1.367210e+01},                                                // SINR
           {1, 9.751908e-01, 5.204918e-01, 2.560000e-02, 1.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.079690e+01,
            1.167280e+01,
            1.196000e+01,
            1.226000e+01,
            1.254870e+01,
            1.342450e+01},                                                // SINR
           {1, 9.875000e-01, 6.184211e-01, 6.330000e-02, 5.000000e-04, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.079690e+01, 1.153000e+01, 1.189180e+01, 1.226000e+01, 1.298660e+01}, // SINR
           {1, 9.990385e-01, 7.901235e-01, 6.580000e-02, 0}                        // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.167280e+01, 1.196000e+01, 1.226000e+01, 1.254870e+01}, // SINR
           {9.778846e-01, 6.007109e-01, 4.270000e-02, 0}             // BLER
       }},
      {6400U, // SINR and BLER for CBS 6400
       MmWaveEesmErrorModel::DoubleTuple{
           {1.167280e+01, 1.196000e+01, 1.226000e+01, 1.254870e+01}, // SINR
           {9.558824e-01, 4.305085e-01, 1.570000e-02, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.167280e+01, 1.226000e+01, 1.254870e+01, 1.284000e+01}, // SINR
           {9.990385e-01, 1.650851e-01, 1.800000e-03, 0}             // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.079690e+01, 1.167280e+01, 1.196000e+01, 1.226000e+01, 1.254870e+01}, // SINR
           {1, 9.913462e-01, 6.945946e-01, 5.500000e-02, 0}                        // BLER
       }}},
     {        // MCS 19
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.213650e+01, 1.285000e+01, 1.321120e+01, 1.357000e+01, 1.428590e+01}, // SINR
           {1, 7.626488e-01, 1.377607e-01, 1.200000e-03, 0}                        // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.226030e+01, 1.289000e+01, 1.321120e+01, 1.353000e+01, 1.416210e+01}, // SINR
           {9.990385e-01, 6.136364e-01, 7.770000e-02, 1.200000e-03, 0}             // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.226030e+01,
            1.289000e+01,
            1.321120e+01,
            1.353000e+01,
            1.416210e+01,
            1.511300e+01},                                                // SINR
           {1, 6.363065e-01, 8.280000e-02, 1.000000e-03, 1.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.176080e+01,
            1.248000e+01,
            1.283660e+01,
            1.320000e+01,
            1.391230e+01,
            1.498810e+01},                                                // SINR
           {1, 9.951923e-01, 7.717066e-01, 9.284566e-02, 1.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.226030e+01, 1.289000e+01, 1.321120e+01, 1.353000e+01, 1.416210e+01}, // SINR
           {1, 7.032967e-01, 8.947262e-02, 7.000000e-04, 0}                        // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.226030e+01, 1.289000e+01, 1.321120e+01, 1.353000e+01, 1.416210e+01}, // SINR
           {1, 6.086957e-01, 4.830000e-02, 2.000000e-04, 0}                        // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.226030e+01, 1.289000e+01, 1.321120e+01, 1.353000e+01}, // SINR
           {1, 6.759259e-01, 5.210000e-02, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.226030e+01, 1.274000e+01, 1.297350e+01, 1.321000e+01, 1.368670e+01}, // SINR
           {1, 9.020979e-01, 3.896154e-01, 3.080000e-02, 0}                        // BLER
       }},
      {7168U, // SINR and BLER for CBS 7168
       MmWaveEesmErrorModel::DoubleTuple{
           {1.258000e+01, 1.289420e+01, 1.321120e+01, 1.352820e+01, 1.384510e+01}, // SINR
           {9.913462e-01, 6.993243e-01, 4.940000e-02, 2.000000e-04, 0}             // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.226030e+01, 1.274000e+01, 1.297350e+01, 1.321000e+01, 1.368670e+01}, // SINR
           {1, 9.425182e-01, 4.897860e-01, 5.140000e-02, 0}                        // BLER
       }}},
     {        // MCS 20
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.319000e+01,
            1.367000e+01,
            1.390720e+01,
            1.415000e+01,
            1.462260e+01,
            1.533790e+01},                                                           // SINR
           {9.980769e-01, 8.066038e-01, 4.098558e-01, 8.280000e-02, 2.000000e-04, 0} // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.267070e+01,
            1.335000e+01,
            1.369520e+01,
            1.404000e+01,
            1.471960e+01,
            1.574410e+01},                                                // SINR
           {1, 9.990385e-01, 8.509934e-01, 2.323394e-01, 1.000000e-04, 0} // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.324000e+01,
            1.371000e+01,
            1.394470e+01,
            1.418000e+01,
            1.465060e+01,
            1.535660e+01,
            1.606260e+01}, // SINR
           {9.990385e-01,
            7.176966e-01,
            2.530000e-01,
            3.160000e-02,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.307000e+01,
            1.356000e+01,
            1.381250e+01,
            1.406000e+01,
            1.455150e+01,
            1.529050e+01},                                                // SINR
           {1, 9.586466e-01, 6.493590e-01, 1.726272e-01, 2.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.356000e+01, 1.385000e+01, 14, 1.414000e+01, 1.443600e+01, 1.487210e+01}, // SINR
           {9.375000e-01, 4.624094e-01, 1.669430e-01, 3.650000e-02, 1.000000e-04, 0}   // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {13, 1.363000e+01, 1.394210e+01, 1.426000e+01, 1.488430e+01}, // SINR
           {1, 8.906250e-01, 2.850679e-01, 8.400000e-03, 0}              // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.339000e+01, 1.385850e+01, 1.432990e+01, 1.480130e+01}, // SINR
           {9.971154e-01, 4.589350e-01, 1.100000e-03, 0}             // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.350000e+01, 1.387000e+01, 1.406100e+01, 1.425000e+01, 1.462210e+01}, // SINR
           {9.807692e-01, 3.727876e-01, 5.480000e-02, 2.100000e-03, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.334000e+01, 1.381830e+01, 1.429980e+01, 1.478120e+01}, // SINR
           {1, 7.145833e-01, 3.400000e-03, 0}                        // BLER
       }},
      {7808U, // SINR and BLER for CBS 7808
       MmWaveEesmErrorModel::DoubleTuple{
           {1.350000e+01, 1.387000e+01, 1.406100e+01, 1.425000e+01, 1.462210e+01}, // SINR
           {9.807692e-01, 3.695652e-01, 5.320000e-02, 1.700000e-03, 0}             // BLER
       }}},
     {        // MCS 21
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.381000e+01, 1.442000e+01, 1.472460e+01, 1.503000e+01, 1.564120e+01}, // SINR
           {1, 9.913462e-01, 8.330645e-01, 3.339947e-01, 0}                        // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.429000e+01,
            1.469000e+01,
            1.488840e+01,
            1.509000e+01,
            1.548990e+01,
            1.609140e+01},                                                           // SINR
           {9.855769e-01, 5.816210e-01, 2.148370e-01, 2.920000e-02, 2.000000e-04, 0} // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.412000e+01,
            1.454000e+01,
            1.475610e+01,
            1.497000e+01,
            1.539070e+01,
            1.602520e+01,
            1.665980e+01}, // SINR
           {9.990385e-01,
            8.176752e-01,
            4.037540e-01,
            9.073398e-02,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.401000e+01,
            1.445000e+01,
            1.466400e+01,
            1.488000e+01,
            1.532160e+01,
            1.597920e+01,
            1.663680e+01},                                                              // SINR
           {1, 9.284420e-01, 6.026995e-01, 1.808165e-01, 3.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.397000e+01,
            1.441000e+01,
            1.463540e+01,
            1.486000e+01,
            1.530010e+01,
            1.596490e+01},                                                // SINR
           {1, 9.580224e-01, 6.935484e-01, 2.100000e-01, 4.000000e-04, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.430000e+01,
            1.463000e+01,
            1.480000e+01,
            1.497000e+01,
            1.530000e+01,
            1.580000e+01},                                                           // SINR
           {9.923077e-01, 6.628205e-01, 2.744035e-01, 5.130000e-02, 2.000000e-04, 0} // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.423270e+01, 1.491000e+01, 1.525330e+01, 1.559000e+01}, // SINR
           {1, 2.932135e-01, 2.200000e-03, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.455000e+01, 1.480000e+01, 1.505000e+01, 1.530000e+01, 1.555000e+01}, // SINR
           {9.611111e-01, 4.903101e-01, 4.570000e-02, 2.000000e-04, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.402000e+01, 1.446000e+01, 1.467120e+01, 1.489000e+01, 1.532700e+01}, // SINR
           {1, 9.903846e-01, 7.761976e-01, 2.463450e-01, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.407000e+01, 1.450000e+01, 1.471580e+01, 1.493000e+01, 1.536040e+01}, // SINR
           {1, 9.022887e-01, 3.806647e-01, 3.420000e-02, 0}                        // BLER
       }}},
     {        // MCS 22
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.532000e+01,
            1.558610e+01,
            1.585110e+01,
            1.611610e+01,
            1.638100e+01,
            1.664600e+01},                                                           // SINR
           {9.626866e-01, 7.178771e-01, 2.286364e-01, 2.100000e-02, 6.000000e-04, 0} // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.536000e+01, 1.562260e+01, 1.588300e+01, 1.614340e+01, 1.640380e+01}, // SINR
           {9.148936e-01, 5.069721e-01, 9.200405e-02, 3.300000e-03, 0}             // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.520000e+01,
            1.541000e+01,
            1.562260e+01,
            1.583090e+01,
            1.603920e+01,
            1.624760e+01,
            1.645590e+01}, // SINR
           {9.706439e-01,
            7.765152e-01,
            3.371011e-01,
            6.040000e-02,
            3.500000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.494000e+01, 1.545590e+01, 1.597190e+01, 1.648790e+01}, // SINR
           {1, 8.417208e-01, 2.870000e-02, 0}                        // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.532570e+01, 1.568570e+01, 1.604570e+01, 1.640580e+01}, // SINR
           {9.846154e-01, 5.755682e-01, 2.450000e-02, 0}             // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.527000e+01,
            1.546000e+01,
            1.564740e+01,
            1.583910e+01,
            1.603080e+01,
            1.622250e+01,
            1.641420e+01}, // SINR
           {9.817308e-01,
            8.750000e-01,
            4.990157e-01,
            1.266431e-01,
            1.120000e-02,
            2.000000e-04,
            0} // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.539000e+01,
            1.559650e+01,
            1.580740e+01,
            1.601840e+01,
            1.622930e+01,
            1.644020e+01},                                                           // SINR
           {9.434307e-01, 6.318069e-01, 1.663907e-01, 8.000000e-03, 2.000000e-04, 0} // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.533920e+01, 1.563500e+01, 1.593090e+01, 1.622670e+01}, // SINR
           {9.836538e-01, 5.748874e-01, 3.320000e-02, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.533090e+01, 1.562780e+01, 1.592460e+01, 1.622150e+01, 1.651840e+01}, // SINR
           {9.961538e-01, 5.887097e-01, 2.860000e-02, 1.000000e-04, 1.000000e-04}  // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.517000e+01, 1.545590e+01, 1.573710e+01, 1.601840e+01, 1.629960e+01}, // SINR
           {9.990385e-01, 8.455882e-01, 1.342444e-01, 8.000000e-04, 0}             // BLER
       }}},
     {       // MCS 23
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.580000e+01,
            1.617500e+01,
            1.655000e+01,
            1.692500e+01,
            1.730000e+01,
            1.768000e+01,
            1.805000e+01,
            1.843000e+01,
            1.880000e+01,
            1.918000e+01,
            1.955000e+01,
            1.993000e+01,
            2.030000e+01,
            2.068000e+01}, // SINR
           {9.836538e-01,
            9.420290e-01,
            8.553922e-01,
            6.895161e-01,
            4.805871e-01,
            2.873858e-01,
            1.358460e-01,
            4.970000e-02,
            1.320000e-02,
            3.200000e-03,
            7.000000e-04,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {1.580000e+01,
            1.636250e+01,
            1.692500e+01,
            1.748750e+01,
            1.805000e+01,
            1.861000e+01,
            1.918000e+01,
            1.974000e+01,
            2.030000e+01,
            2.086000e+01}, // SINR
           {9.980769e-01,
            9.583333e-01,
            8.279221e-01,
            5.268595e-01,
            2.314220e-01,
            5.080000e-02,
            5.800000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {352U, // SINR and BLER for CBS 352
       MmWaveEesmErrorModel::DoubleTuple{
           {1.610000e+01,
            1.637500e+01,
            1.665000e+01,
            1.692500e+01,
            1.720000e+01,
            1.747000e+01,
            1.775000e+01,
            1.803000e+01,
            1.830000e+01,
            1.857000e+01,
            1.885000e+01,
            1.912000e+01,
            1.940000e+01,
            1.967000e+01,
            1.995000e+01}, // SINR
           {9.293478e-01,
            8.690878e-01,
            7.529240e-01,
            6.118421e-01,
            4.467430e-01,
            3.057229e-01,
            1.699798e-01,
            8.070388e-02,
            3.470000e-02,
            1.240000e-02,
            3.900000e-03,
            5.000000e-04,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {408U, // SINR and BLER for CBS 408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.631920e+01,
            1.675150e+01,
            1.718390e+01,
            1.761630e+01,
            1.804860e+01,
            1.848000e+01,
            1.891000e+01,
            1.935000e+01,
            1.978000e+01,
            2.021000e+01}, // SINR
           {9.285714e-01,
            7.718373e-01,
            5.090000e-01,
            2.594969e-01,
            8.633814e-02,
            1.750000e-02,
            1.900000e-03,
            5.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.581200e+01,
            1.633990e+01,
            1.686780e+01,
            1.739570e+01,
            1.792360e+01,
            1.845000e+01,
            1.898000e+01,
            1.951000e+01}, // SINR
           {9.865385e-01,
            8.809932e-01,
            6.293103e-01,
            2.754376e-01,
            6.800000e-02,
            8.300000e-03,
            7.000000e-04,
            0} // BLER
       }},
      {504U, // SINR and BLER for CBS 504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.598620e+01,
            1.637490e+01,
            1.676350e+01,
            1.715210e+01,
            1.754080e+01,
            1.793000e+01,
            1.832000e+01,
            1.871000e+01,
            1.910000e+01,
            1.948000e+01}, // SINR
           {9.592593e-01,
            8.437500e-01,
            6.000000e-01,
            3.377660e-01,
            1.379121e-01,
            3.910000e-02,
            5.300000e-03,
            8.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.604000e+01,
            1.643010e+01,
            1.681910e+01,
            1.720810e+01,
            1.759710e+01,
            1.798610e+01,
            1.838000e+01,
            1.876000e+01,
            1.915000e+01}, // SINR
           {9.406934e-01,
            7.750000e-01,
            5.075000e-01,
            2.425481e-01,
            7.880000e-02,
            1.540000e-02,
            1.900000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {576U, // SINR and BLER for CBS 576
       MmWaveEesmErrorModel::DoubleTuple{
           {1.594000e+01,
            1.616000e+01,
            1.638000e+01,
            1.660000e+01,
            1.682500e+01,
            1.705000e+01,
            1.727500e+01,
            1.750000e+01,
            1.773000e+01,
            1.795000e+01,
            1.817000e+01,
            1.840000e+01,
            1.863000e+01,
            1.885000e+01}, // SINR
           {9.518519e-01,
            8.818493e-01,
            7.695783e-01,
            6.250000e-01,
            4.558036e-01,
            2.980094e-01,
            1.707938e-01,
            8.410184e-02,
            3.400000e-02,
            1.130000e-02,
            2.800000e-03,
            5.000000e-04,
            3.000000e-04,
            0} // BLER
       }},
      {640U, // SINR and BLER for CBS 640
       MmWaveEesmErrorModel::DoubleTuple{
           {1.615110e+01,
            1.644130e+01,
            1.673150e+01,
            1.702180e+01,
            1.731200e+01,
            1.760000e+01,
            1.789000e+01,
            1.818000e+01,
            1.847000e+01,
            1.876000e+01,
            1.905000e+01}, // SINR
           {9.778846e-01,
            8.938356e-01,
            7.376453e-01,
            5.146761e-01,
            3.100490e-01,
            1.372951e-01,
            4.560000e-02,
            1.140000e-02,
            1.500000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {672U, // SINR and BLER for CBS 672
       MmWaveEesmErrorModel::DoubleTuple{
           {1.627270e+01,
            1.664770e+01,
            1.702270e+01,
            1.739770e+01,
            1.777270e+01,
            1.815000e+01,
            1.852000e+01,
            1.890000e+01,
            1.927000e+01}, // SINR
           {9.645522e-01,
            8.609272e-01,
            6.287313e-01,
            3.207908e-01,
            1.102810e-01,
            1.970000e-02,
            2.500000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.630000e+01,
            1.654860e+01,
            1.679860e+01,
            1.704860e+01,
            1.729860e+01,
            1.754860e+01,
            1.780000e+01,
            1.805000e+01,
            1.830000e+01,
            1.855000e+01,
            1.880000e+01}, // SINR
           {9.447464e-01,
            8.431373e-01,
            6.458333e-01,
            4.355670e-01,
            2.520040e-01,
            1.107904e-01,
            3.960000e-02,
            1.110000e-02,
            2.700000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.627230e+01,
            1.665000e+01,
            1.702780e+01,
            1.740550e+01,
            1.778320e+01,
            1.816000e+01,
            1.854000e+01,
            1.892000e+01}, // SINR
           {9.632353e-01,
            8.140823e-01,
            4.841954e-01,
            1.857459e-01,
            4.090000e-02,
            4.300000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.590000e+01,
            1.615000e+01,
            1.640000e+01,
            1.665000e+01,
            1.690000e+01,
            1.715000e+01,
            1.740000e+01,
            1.765000e+01,
            1.790000e+01,
            1.815000e+01,
            1.840000e+01,
            1.865000e+01}, // SINR
           {9.642857e-01,
            8.792808e-01,
            7.212079e-01,
            4.864865e-01,
            2.671053e-01,
            1.139908e-01,
            3.600000e-02,
            8.800000e-03,
            1.100000e-03,
            3.000000e-04,
            3.000000e-04,
            1.000000e-04} // BLER
       }},
      {1032U, // SINR and BLER for CBS 1032
       MmWaveEesmErrorModel::DoubleTuple{
           {1.620000e+01, 1.665000e+01, 1.710000e+01, 1.755000e+01, 18},          // SINR
           {9.055944e-01, 4.825472e-01, 1.268920e-01, 1.310000e-02, 2.000000e-04} // BLER
       }},
      {1128U, // SINR and BLER for CBS 1128
       MmWaveEesmErrorModel::DoubleTuple{
           {1.606000e+01, 1.660750e+01, 1.715500e+01, 1.770250e+01, 1.825000e+01}, // SINR
           {9.875954e-01, 7.848485e-01, 2.598140e-01, 2.230000e-02, 6.000000e-04}  // BLER
       }},
      {1192U, // SINR and BLER for CBS 1192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.616000e+01,
            1.641000e+01,
            1.665580e+01,
            1.690580e+01,
            1.715580e+01,
            1.740580e+01,
            1.765580e+01,
            1.791000e+01,
            1.816000e+01}, // SINR
           {9.430147e-01,
            7.919207e-01,
            5.778409e-01,
            3.184375e-01,
            1.279277e-01,
            3.800000e-02,
            6.800000e-03,
            1.100000e-03,
            3.000000e-04} // BLER
       }},
      {1288U, // SINR and BLER for CBS 1288
       MmWaveEesmErrorModel::DoubleTuple{
           {1.605000e+01, 1.670000e+01, 1.735000e+01, 18}, // SINR
           {9.542910e-01, 4.364407e-01, 2.720000e-02, 0}   // BLER
       }},
      {1352U, // SINR and BLER for CBS 1352
       MmWaveEesmErrorModel::DoubleTuple{
           {1.584000e+01, 1.673620e+01, 1.763190e+01, 1.852760e+01}, // SINR
           {9.990385e-01, 5.446809e-01, 7.700000e-03, 0}             // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.603000e+01,
            1.670000e+01,
            1.737500e+01,
            1.805000e+01,
            1.872500e+01,
            1.940000e+01},                                                           // SINR
           {9.790076e-01, 4.285714e-01, 1.440000e-02, 2.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.620000e+01, 1.670000e+01, 1.720000e+01, 1.770000e+01, 1.820000e+01}, // SINR
           {9.611111e-01, 5.745516e-01, 6.960000e-02, 1.600000e-03, 0}             // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.587000e+01,
            1.636000e+01,
            1.685000e+01,
            1.733750e+01,
            1.782500e+01,
            1.831250e+01},                                                           // SINR
           {9.913462e-01, 7.457143e-01, 1.429181e-01, 4.200000e-03, 1.000000e-04, 0} // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {1.604000e+01, 1.647000e+01, 1.690000e+01, 1.732500e+01, 1.775000e+01}, // SINR
           {9.564815e-01, 5.318930e-01, 8.030000e-02, 2.000000e-03, 0}             // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {1.595000e+01, 1.660000e+01, 1.725000e+01, 1.790000e+01}, // SINR
           {9.855769e-01, 3.603152e-01, 5.300000e-03, 0}             // BLER
       }},
      {2408U, // SINR and BLER for CBS 2408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.574000e+01, 1.632000e+01, 1.690000e+01, 1.747500e+01}, // SINR
           {9.971154e-01, 7.247191e-01, 4.200000e-02, 0}             // BLER
       }},
      {2600U, // SINR and BLER for CBS 2600
       MmWaveEesmErrorModel::DoubleTuple{
           {1.605000e+01,
            1.640000e+01,
            1.675000e+01,
            1.710000e+01,
            1.745000e+01,
            1.780000e+01},                                                           // SINR
           {9.725379e-01, 7.129121e-01, 1.937790e-01, 1.350000e-02, 4.000000e-04, 0} // BLER
       }},
      {2792U, // SINR and BLER for CBS 2792
       MmWaveEesmErrorModel::DoubleTuple{
           {1.551000e+01, 1.618000e+01, 1.651000e+01, 1.684000e+01, 1.750550e+01}, // SINR
           {1, 9.040493e-01, 4.444930e-01, 6.170000e-02, 0}                        // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.588000e+01, 1.648610e+01, 1.708870e+01, 1.769130e+01}, // SINR
           {9.923077e-01, 3.436649e-01, 1.100000e-03, 0}             // BLER
       }},
      {3368U, // SINR and BLER for CBS 3368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.611000e+01,
            1.644000e+01,
            1.677000e+01,
            1.710000e+01,
            1.743360e+01,
            1.776390e+01},                                                           // SINR
           {9.932692e-01, 8.073899e-01, 2.753821e-01, 1.690000e-02, 1.000000e-04, 0} // BLER
       }},
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.593000e+01,
            1.641000e+01,
            1.689060e+01,
            1.737520e+01,
            1.785990e+01,
            1.834450e+01},                                                           // SINR
           {9.990385e-01, 8.624161e-01, 1.537638e-01, 1.600000e-03, 1.000000e-04, 0} // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.615000e+01, 1.658000e+01, 1.700860e+01, 1.743360e+01}, // SINR
           {9.479927e-01, 3.550978e-01, 9.300000e-03, 0}             // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.599000e+01,
            1.632000e+01,
            1.665000e+01,
            1.698000e+01,
            1.730860e+01,
            1.764190e+01},                                                           // SINR
           {9.990385e-01, 8.476821e-01, 2.611284e-01, 1.760000e-02, 1.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.568000e+01,
            16,
            1.632000e+01,
            1.663000e+01,
            1.695000e+01,
            1.726950e+01,
            1.758690e+01,
            1.790430e+01}, // SINR
           {1,
            9.990385e-01,
            8.767007e-01,
            3.412162e-01,
            2.330000e-02,
            5.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.623000e+01, 1.664000e+01, 1.705240e+01, 1.746660e+01}, // SINR
           {9.568015e-01, 3.684402e-01, 6.500000e-03, 0}             // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.622000e+01, 1.664000e+01, 1.705860e+01, 1.747530e+01}, // SINR
           {9.865385e-01, 4.870192e-01, 1.670000e-02, 0}             // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.637000e+01,
            1.668000e+01,
            1.683230e+01,
            1.699000e+01,
            1.729660e+01,
            1.776090e+01},                                                           // SINR
           {9.509259e-01, 4.540179e-01, 1.719604e-01, 3.640000e-02, 4.000000e-04, 0} // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.539000e+01, 1.606000e+01, 1.639000e+01, 1.672000e+01, 1.738740e+01}, // SINR
           {1, 9.980769e-01, 8.741497e-01, 1.904312e-01, 0}                        // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.607000e+01,
            1.641000e+01,
            1.675000e+01,
            1.708860e+01,
            1.742860e+01,
            1.776860e+01},                                                           // SINR
           {9.990385e-01, 9.024823e-01, 1.780895e-01, 2.400000e-03, 2.000000e-04, 0} // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.502000e+01, 1.602000e+01, 1.635000e+01, 1.669000e+01, 1.701850e+01}, // SINR
           {1, 9.990385e-01, 7.619048e-01, 5.800000e-02, 0}                        // BLER
       }}},
     {       // MCS 24
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.730000e+01,
            1.769380e+01,
            1.808750e+01,
            1.848120e+01,
            1.887500e+01,
            1.927000e+01,
            1.966000e+01,
            2.006000e+01,
            2.045000e+01,
            2.084000e+01,
            2.124000e+01,
            2.163000e+01}, // SINR
           {9.552239e-01,
            8.863636e-01,
            7.595588e-01,
            5.330882e-01,
            3.291344e-01,
            1.584596e-01,
            6.330000e-02,
            1.820000e-02,
            3.900000e-03,
            8.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {320U, // SINR and BLER for CBS 320
       MmWaveEesmErrorModel::DoubleTuple{
           {1.668000e+01,
            1.720000e+01,
            1.772340e+01,
            1.824180e+01,
            1.876030e+01,
            1.927880e+01,
            1.979720e+01,
            2.032000e+01}, // SINR
           {9.725379e-01,
            8.862847e-01,
            6.425879e-01,
            3.459699e-01,
            1.270325e-01,
            2.880000e-02,
            3.500000e-03,
            6.000000e-04} // BLER
       }},
      {352U, // SINR and BLER for CBS 352
       MmWaveEesmErrorModel::DoubleTuple{
           {1.702000e+01,
            1.728000e+01,
            1.754000e+01,
            1.780500e+01,
            1.807000e+01,
            1.833500e+01,
            1.860000e+01,
            1.887000e+01,
            1.913000e+01,
            1.940000e+01,
            1.966000e+01,
            1.993000e+01,
            2.019000e+01,
            2.046000e+01}, // SINR
           {9.347826e-01,
            8.827586e-01,
            7.970679e-01,
            6.902174e-01,
            5.348958e-01,
            3.783784e-01,
            2.320442e-01,
            1.174528e-01,
            5.920000e-02,
            2.750000e-02,
            1.000000e-02,
            3.400000e-03,
            1.100000e-03,
            0} // BLER
       }},
      {408U, // SINR and BLER for CBS 408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.711330e+01,
            1.748360e+01,
            1.785400e+01,
            1.822440e+01,
            1.859470e+01,
            1.897000e+01,
            1.934000e+01,
            1.971000e+01,
            2.008000e+01,
            2.045000e+01,
            2.082000e+01}, // SINR
           {9.438406e-01,
            8.357843e-01,
            6.538462e-01,
            4.229167e-01,
            2.029483e-01,
            7.270000e-02,
            2.000000e-02,
            4.800000e-03,
            1.000000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.704000e+01,
            1.727000e+01,
            1.750000e+01,
            1.772790e+01,
            1.795890e+01,
            1.819000e+01,
            1.842100e+01,
            1.865200e+01,
            1.888000e+01,
            1.911000e+01,
            1.935000e+01,
            1.958000e+01,
            1.981000e+01,
            2.004000e+01,
            2.027000e+01,
            2.050000e+01,
            2.073000e+01}, // SINR
           {9.131206e-01,
            8.248408e-01,
            7.233146e-01,
            5.924419e-01,
            4.258333e-01,
            2.842971e-01,
            1.586599e-01,
            7.720000e-02,
            3.570000e-02,
            1.310000e-02,
            4.800000e-03,
            1.700000e-03,
            7.000000e-04,
            3.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {504U, // SINR and BLER for CBS 504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.750490e+01,
            1.773040e+01,
            1.795580e+01,
            1.818120e+01,
            1.840670e+01,
            1.863000e+01,
            1.886000e+01,
            1.908000e+01,
            1.931000e+01,
            1.953000e+01,
            1.976000e+01,
            1.998000e+01,
            2.021000e+01,
            2.044000e+01,
            2.066000e+01}, // SINR
           {9.629630e-01,
            9.262590e-01,
            8.196203e-01,
            6.908967e-01,
            5.296875e-01,
            3.655523e-01,
            2.280741e-01,
            1.289866e-01,
            6.170000e-02,
            2.900000e-02,
            9.300000e-03,
            3.400000e-03,
            1.100000e-03,
            5.000000e-04,
            2.000000e-04} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.747950e+01,
            1.770810e+01,
            1.793670e+01,
            1.816540e+01,
            1.839400e+01,
            1.862000e+01,
            1.885000e+01,
            1.908000e+01,
            1.931000e+01,
            1.954000e+01,
            1.977000e+01,
            1.999000e+01,
            2.022000e+01,
            2.045000e+01}, // SINR
           {9.082168e-01,
            8.173077e-01,
            6.964286e-01,
            5.247934e-01,
            3.523045e-01,
            2.096506e-01,
            1.080638e-01,
            4.740000e-02,
            1.950000e-02,
            6.800000e-03,
            1.600000e-03,
            5.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {576U, // SINR and BLER for CBS 576
       MmWaveEesmErrorModel::DoubleTuple{
           {1.680000e+01,
            1.730000e+01,
            1.780000e+01,
            1.830000e+01,
            1.880000e+01,
            1.930000e+01,
            1.980000e+01,
            2.030000e+01}, // SINR
           {9.903846e-01,
            9.148936e-01,
            6.956522e-01,
            3.366667e-01,
            7.330000e-02,
            9.400000e-03,
            9.000000e-04,
            0} // BLER
       }},
      {640U, // SINR and BLER for CBS 640
       MmWaveEesmErrorModel::DoubleTuple{
           {1.758980e+01,
            1.844000e+01,
            1.885810e+01,
            1.928000e+01,
            2.012640e+01,
            2.139470e+01},                                                           // SINR
           {9.151786e-01, 3.614286e-01, 1.021967e-01, 1.590000e-02, 4.000000e-04, 0} // BLER
       }},
      {672U, // SINR and BLER for CBS 672
       MmWaveEesmErrorModel::DoubleTuple{
           {1.637000e+01, 1.759430e+01, 1.881510e+01, 2.003580e+01, 2.125660e+01}, // SINR
           {9.980769e-01, 6.130383e-01, 1.010000e-02, 1.000000e-04, 0}             // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.640000e+01, 1.758980e+01, 1.878080e+01, 1.997170e+01, 2.116260e+01}, // SINR
           {1, 7.842988e-01, 3.700000e-02, 2.000000e-04, 0}                        // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.731000e+01,
            1.772000e+01,
            1.813000e+01,
            1.854550e+01,
            1.895640e+01,
            1.936720e+01,
            1.977810e+01,
            2.018900e+01}, // SINR
           {9.128521e-01,
            6.747382e-01,
            3.019596e-01,
            6.520000e-02,
            6.600000e-03,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.720000e+01,
            1.751000e+01,
            1.782000e+01,
            1.813000e+01,
            1.844550e+01,
            1.875970e+01,
            1.907390e+01,
            1.938820e+01,
            1.970240e+01}, // SINR
           {9.311594e-01,
            7.888720e-01,
            5.385021e-01,
            2.509921e-01,
            7.250000e-02,
            1.410000e-02,
            2.400000e-03,
            6.000000e-04,
            2.000000e-04} // BLER
       }},
      {1032U, // SINR and BLER for CBS 1032
       MmWaveEesmErrorModel::DoubleTuple{
           {1.713000e+01,
            1.742000e+01,
            1.771000e+01,
            18,
            1.830000e+01,
            1.858990e+01,
            1.888350e+01,
            1.917710e+01,
            1.947070e+01}, // SINR
           {9.370504e-01,
            7.986111e-01,
            5.357143e-01,
            2.525100e-01,
            7.470000e-02,
            1.300000e-02,
            1.400000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {1128U, // SINR and BLER for CBS 1128
       MmWaveEesmErrorModel::DoubleTuple{
           {1.731000e+01,
            1.768000e+01,
            1.805000e+01,
            1.842400e+01,
            1.879420e+01,
            1.916430e+01,
            1.953450e+01,
            1.990470e+01}, // SINR
           {9.307554e-01,
            7.363506e-01,
            3.757440e-01,
            9.430354e-02,
            1.150000e-02,
            1.400000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {1192U, // SINR and BLER for CBS 1192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.720000e+01,
            1.743000e+01,
            1.766000e+01,
            1.789000e+01,
            1.812000e+01,
            1.836000e+01,
            1.858980e+01,
            1.882410e+01,
            1.905850e+01,
            1.929290e+01}, // SINR
           {9.047203e-01,
            7.551775e-01,
            5.232438e-01,
            3.002976e-01,
            1.166357e-01,
            2.930000e-02,
            5.200000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1288U, // SINR and BLER for CBS 1288
       MmWaveEesmErrorModel::DoubleTuple{
           {1.706000e+01,
            1.737000e+01,
            1.768000e+01,
            1.799000e+01,
            1.829110e+01,
            1.859600e+01,
            1.890100e+01,
            1.920590e+01,
            1.951080e+01}, // SINR
           {9.799618e-01,
            8.924825e-01,
            6.408629e-01,
            3.212025e-01,
            9.009282e-02,
            1.370000e-02,
            2.000000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {1352U, // SINR and BLER for CBS 1352
       MmWaveEesmErrorModel::DoubleTuple{
           {1.709000e+01,
            1.731000e+01,
            1.753000e+01,
            1.775000e+01,
            1.797000e+01,
            1.819000e+01,
            1.841000e+01,
            1.862910e+01,
            1.884990e+01,
            1.907070e+01,
            1.929140e+01}, // SINR
           {9.316547e-01,
            8.121019e-01,
            6.024882e-01,
            3.481405e-01,
            1.486128e-01,
            4.580000e-02,
            1.000000e-02,
            1.400000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.703000e+01,
            1.739000e+01,
            1.775000e+01,
            1.811000e+01,
            1.847080e+01,
            1.883320e+01},                                                           // SINR
           {9.638889e-01, 7.795455e-01, 3.806138e-01, 7.470000e-02, 5.700000e-03, 0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.712000e+01,
            1.755000e+01,
            1.798000e+01,
            1.840790e+01,
            1.883580e+01,
            1.926370e+01},                                                           // SINR
           {9.518519e-01, 6.053571e-01, 1.346463e-01, 6.400000e-03, 2.000000e-04, 0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.729000e+01, 1.795000e+01, 1.861010e+01, 1.927030e+01}, // SINR
           {9.339286e-01, 2.647059e-01, 1.900000e-03, 0}             // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {17, 1.750000e+01, 18, 1.850000e+01, 19},                   // SINR
           {9.875000e-01, 6.489899e-01, 8.360064e-02, 8.000000e-04, 0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {1.695000e+01,
            1.726000e+01,
            1.757000e+01,
            1.788000e+01,
            1.819000e+01,
            1.850000e+01,
            1.881250e+01}, // SINR
           {9.799618e-01,
            8.576159e-01,
            4.765918e-01,
            1.152957e-01,
            8.800000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {2408U, // SINR and BLER for CBS 2408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.680000e+01, 1.725000e+01, 1.770000e+01, 1.815000e+01, 1.860000e+01}, // SINR
           {9.980769e-01, 8.632550e-01, 3.082108e-01, 1.190000e-02, 0}             // BLER
       }},
      {2600U, // SINR and BLER for CBS 2600
       MmWaveEesmErrorModel::DoubleTuple{
           {1.683000e+01,
            1.725000e+01,
            1.768000e+01,
            1.810000e+01,
            1.852500e+01,
            1.895000e+01,
            1.937500e+01,
            1.980000e+01}, // SINR
           {9.971154e-01,
            8.625000e-01,
            3.245501e-01,
            1.590000e-02,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2792U, // SINR and BLER for CBS 2792
       MmWaveEesmErrorModel::DoubleTuple{
           {1.696000e+01, 1.748000e+01, 18, 1.852500e+01}, // SINR
           {9.942308e-01, 6.343284e-01, 4.240000e-02, 0}   // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.716000e+01, 1.763000e+01, 1.810000e+01, 1.857500e+01}, // SINR
           {9.219858e-01, 2.924365e-01, 4.300000e-03, 0}             // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.704000e+01, 1.746000e+01, 1.788000e+01, 1.830000e+01, 1.872500e+01}, // SINR
           {9.809160e-01, 6.556122e-01, 6.660000e-02, 2.000000e-04, 0}             // BLER
       }},
      {3624U, // SINR and BLER for CBS 3624
       MmWaveEesmErrorModel::DoubleTuple{
           {1.720000e+01, 1.765000e+01, 1.810000e+01, 1.855000e+01, 19}, // SINR
           {9.809160e-01, 5.675223e-01, 2.810000e-02, 4.000000e-04, 0}   // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.678000e+01, 1.744000e+01, 1.810000e+01, 1.875750e+01}, // SINR
           {1, 7.285714e-01, 1.020000e-02, 0}                        // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.653000e+01, 1.720000e+01, 1.753000e+01, 1.787000e+01, 1.853330e+01}, // SINR
           {1, 9.140071e-01, 4.646739e-01, 5.410000e-02, 0}                        // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.727000e+01, 1.758000e+01, 1.789000e+01, 1.820000e+01, 1.851250e+01}, // SINR
           {9.866412e-01, 7.514793e-01, 1.875000e-01, 7.700000e-03, 0}             // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.650000e+01, 1.717000e+01, 1.750000e+01, 1.783000e+01, 1.850000e+01}, // SINR
           {1, 9.923077e-01, 7.858232e-01, 1.923664e-01, 0}                        // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.722000e+01, 1.767000e+01, 1.790000e+01, 1.812000e+01, 1.857500e+01}, // SINR
           {9.894231e-01, 5.080321e-01, 1.238872e-01, 1.040000e-02, 0}             // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.667000e+01, 1.720000e+01, 1.746570e+01, 1.773000e+01, 1.826050e+01}, // SINR
           {1, 9.759615e-01, 7.356322e-01, 2.078512e-01, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.716000e+01, 1.763000e+01, 1.810000e+01, 1.857500e+01}, // SINR
           {9.990385e-01, 7.056011e-01, 1.550000e-02, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.650000e+01, 1.717000e+01, 1.750000e+01, 1.783000e+01, 1.850000e+01}, // SINR
           {1, 9.980769e-01, 7.989130e-01, 1.201004e-01, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.668000e+01,
            1.712000e+01,
            1.734000e+01,
            1.756000e+01,
            1.800210e+01,
            1.866280e+01},                                                // SINR
           {1, 9.980769e-01, 8.827586e-01, 4.135552e-01, 9.000000e-04, 0} // BLER
       }}},
     {       // MCS 25
      {320U, // SINR and BLER for CBS 320
       MmWaveEesmErrorModel::DoubleTuple{
           {1.795960e+01,
            1.835780e+01,
            1.875590e+01,
            1.915410e+01,
            1.955230e+01,
            1.995000e+01,
            2.035000e+01,
            2.075000e+01,
            2.115000e+01,
            2.154000e+01,
            2.194000e+01,
            2.234000e+01,
            2.274000e+01}, // SINR
           {9.734848e-01,
            9.280576e-01,
            8.229167e-01,
            6.342822e-01,
            4.231728e-01,
            2.367925e-01,
            1.089130e-01,
            3.520000e-02,
            9.700000e-03,
            3.200000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.776000e+01,
            1.833000e+01,
            1.890000e+01,
            1.947500e+01,
            2.005000e+01,
            2.062500e+01,
            2.120000e+01}, // SINR
           {9.443431e-01,
            7.633929e-01,
            4.449301e-01,
            1.609435e-01,
            3.430000e-02,
            3.900000e-03,
            1.000000e-04} // BLER
       }},
      {408U, // SINR and BLER for CBS 408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.825000e+01,
            1.850000e+01,
            1.875000e+01,
            19,
            1.925000e+01,
            1.950000e+01,
            1.975000e+01,
            20,
            2.025000e+01,
            2.050000e+01,
            2.075000e+01,
            21,
            2.125000e+01,
            2.150000e+01,
            2.175000e+01,
            22}, // SINR
           {9.329710e-01,
            8.733108e-01,
            7.878086e-01,
            6.752646e-01,
            5.198980e-01,
            3.656069e-01,
            2.306113e-01,
            1.365114e-01,
            7.560000e-02,
            3.700000e-02,
            1.530000e-02,
            6.800000e-03,
            2.900000e-03,
            1.000000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.777000e+01,
            1.809000e+01,
            1.841000e+01,
            1.873000e+01,
            1.905000e+01,
            1.938000e+01,
            1.970000e+01,
            2.002500e+01,
            2.035000e+01,
            2.067500e+01,
            21}, // SINR
           {9.611742e-01,
            8.977273e-01,
            7.647059e-01,
            5.760135e-01,
            3.549296e-01,
            1.657895e-01,
            6.950000e-02,
            2.380000e-02,
            4.300000e-03,
            4.000000e-04,
            1.000000e-04} // BLER
       }},
      {504U, // SINR and BLER for CBS 504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.852410e+01,
            1.917830e+01,
            1.983250e+01,
            2.048680e+01,
            2.114100e+01,
            2.180000e+01},                                                           // SINR
           {9.425182e-01, 6.987705e-01, 2.678191e-01, 4.330000e-02, 1.700000e-03, 0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.801000e+01,
            1.841000e+01,
            1.881000e+01,
            1.920720e+01,
            1.960730e+01,
            2.000740e+01,
            2.040750e+01,
            2.080760e+01}, // SINR
           {9.696970e-01,
            8.699324e-01,
            6.552835e-01,
            3.735294e-01,
            1.539522e-01,
            4.060000e-02,
            6.100000e-03,
            6.000000e-04} // BLER
       }},
      {576U, // SINR and BLER for CBS 576
       MmWaveEesmErrorModel::DoubleTuple{
           {1.770000e+01,
            1.820000e+01,
            1.870000e+01,
            1.920000e+01,
            1.970000e+01,
            2.020000e+01,
            2.070000e+01,
            2.120000e+01}, // SINR
           {9.913462e-01,
            8.827586e-01,
            6.077381e-01,
            2.507455e-01,
            5.050000e-02,
            6.300000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {640U, // SINR and BLER for CBS 640
       MmWaveEesmErrorModel::DoubleTuple{
           {1.812000e+01,
            1.857000e+01,
            1.902030e+01,
            1.946840e+01,
            1.991660e+01,
            2.036480e+01,
            2.081290e+01}, // SINR
           {9.507299e-01,
            7.927019e-01,
            4.631818e-01,
            1.784446e-01,
            3.110000e-02,
            4.100000e-03,
            1.000000e-04} // BLER
       }},
      {672U, // SINR and BLER for CBS 672
       MmWaveEesmErrorModel::DoubleTuple{
           {1.819000e+01,
            1.848000e+01,
            1.877000e+01,
            1.906000e+01,
            1.934380e+01,
            1.962930e+01,
            1.991470e+01,
            2.020020e+01,
            2.048560e+01,
            2.077000e+01}, // SINR
           {9.543796e-01,
            8.716443e-01,
            7.001366e-01,
            4.782197e-01,
            2.675159e-01,
            1.158902e-01,
            4.110000e-02,
            1.130000e-02,
            2.800000e-03,
            4.000000e-04} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.849000e+01,
            1.888000e+01,
            1.927090e+01,
            1.966190e+01,
            2.005300e+01,
            2.044400e+01,
            2.083500e+01}, // SINR
           {9.271583e-01,
            7.315341e-01,
            4.161238e-01,
            1.585750e-01,
            3.500000e-02,
            5.800000e-03,
            7.000000e-04} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.813000e+01,
            1.852000e+01,
            1.891000e+01,
            1.929520e+01,
            1.968270e+01,
            2.007030e+01,
            2.045780e+01,
            2.084530e+01}, // SINR
           {9.753788e-01,
            8.501656e-01,
            5.464744e-01,
            2.266187e-01,
            5.430000e-02,
            8.300000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {18,
            1.840000e+01,
            1.880000e+01,
            1.920000e+01,
            1.960000e+01,
            20,
            2.040000e+01,
            2.080000e+01}, // SINR
           {9.687500e-01,
            8.319805e-01,
            5.281250e-01,
            1.806556e-01,
            3.080000e-02,
            2.800000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {1032U, // SINR and BLER for CBS 1032
       MmWaveEesmErrorModel::DoubleTuple{
           {1.815000e+01,
            1.852000e+01,
            1.889000e+01,
            1.926610e+01,
            1.964070e+01,
            2.001520e+01,
            2.038970e+01,
            2.076430e+01}, // SINR
           {9.826923e-01,
            8.914931e-01,
            6.400000e-01,
            2.935164e-01,
            6.900000e-02,
            8.900000e-03,
            7.000000e-04,
            0} // BLER
       }},
      {1128U, // SINR and BLER for CBS 1128
       MmWaveEesmErrorModel::DoubleTuple{
           {1.798000e+01,
            1.838000e+01,
            1.878000e+01,
            1.918230e+01,
            1.958600e+01,
            1.998970e+01,
            2.039330e+01,
            2.079700e+01}, // SINR
           {9.778846e-01,
            8.224522e-01,
            4.522321e-01,
            1.247510e-01,
            1.480000e-02,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1192U, // SINR and BLER for CBS 1192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.807000e+01,
            1.832000e+01,
            1.857000e+01,
            1.882000e+01,
            1.907000e+01,
            1.932370e+01,
            1.957540e+01,
            1.982700e+01,
            2.007860e+01,
            2.033030e+01}, // SINR
           {9.671053e-01,
            8.879310e-01,
            6.983696e-01,
            4.370719e-01,
            2.133475e-01,
            6.780000e-02,
            1.690000e-02,
            3.800000e-03,
            7.000000e-04,
            0} // BLER
       }},
      {1288U, // SINR and BLER for CBS 1288
       MmWaveEesmErrorModel::DoubleTuple{
           {1.839000e+01,
            1.856000e+01,
            1.873000e+01,
            1.891000e+01,
            1.908000e+01,
            1.925000e+01,
            1.943000e+01,
            1.960000e+01,
            1.977500e+01,
            1.995000e+01,
            2.012500e+01,
            2.030000e+01}, // SINR
           {9.058099e-01,
            7.996894e-01,
            6.350000e-01,
            4.387931e-01,
            2.666139e-01,
            1.366848e-01,
            5.830000e-02,
            2.150000e-02,
            7.000000e-03,
            1.500000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {1352U, // SINR and BLER for CBS 1352
       MmWaveEesmErrorModel::DoubleTuple{
           {18, 1.847000e+01, 1.894000e+01, 1.941220e+01, 1.987970e+01}, // SINR
           {9.476103e-01, 5.963785e-01, 1.330688e-01, 7.000000e-03, 0}   // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.799000e+01,
            1.831000e+01,
            1.863000e+01,
            1.895000e+01,
            1.926810e+01,
            1.958910e+01,
            1.991000e+01,
            2.023100e+01}, // SINR
           {9.865385e-01,
            8.958333e-01,
            6.426768e-01,
            2.745098e-01,
            5.670000e-02,
            6.500000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {18, 1.845000e+01, 1.890000e+01, 1.935000e+01, 1.980000e+01, 2.025000e+01}, // SINR
           {9.701493e-01, 6.815160e-01, 1.791311e-01, 9.800000e-03, 3.000000e-04, 0}   // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.802000e+01, 1.851000e+01, 1.900250e+01, 1.949170e+01, 1.998090e+01}, // SINR
           {9.817308e-01, 7.217514e-01, 1.603954e-01, 4.300000e-03, 0}             // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {1.798000e+01,
            1.835000e+01,
            1.873000e+01,
            1.910000e+01,
            1.947500e+01,
            1.985000e+01,
            2.022500e+01}, // SINR
           {9.133929e-01,
            5.391949e-01,
            1.088710e-01,
            5.200000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {1.735000e+01,
            1.770000e+01,
            1.805000e+01,
            1.840000e+01,
            1.875000e+01,
            1.910000e+01,
            1.945590e+01,
            1.980690e+01,
            2.015790e+01,
            2.050890e+01}, // SINR
           {1,
            9.971154e-01,
            9.379496e-01,
            6.014151e-01,
            1.565609e-01,
            1.210000e-02,
            4.000000e-04,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2408U, // SINR and BLER for CBS 2408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.792000e+01,
            1.821000e+01,
            1.851000e+01,
            1.880000e+01,
            1.909000e+01,
            1.938170e+01,
            1.967350e+01,
            1.996540e+01}, // SINR
           {9.715909e-01,
            7.710843e-01,
            3.510417e-01,
            6.580000e-02,
            4.500000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2600U, // SINR and BLER for CBS 2600
       MmWaveEesmErrorModel::DoubleTuple{
           {1.757000e+01,
            1.791000e+01,
            1.824000e+01,
            1.858000e+01,
            1.891000e+01,
            1.925000e+01,
            1.958250e+01,
            1.991770e+01,
            2.025290e+01}, // SINR
           {1,
            9.913462e-01,
            8.567881e-01,
            3.953762e-01,
            6.760000e-02,
            2.200000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2792U, // SINR and BLER for CBS 2792
       MmWaveEesmErrorModel::DoubleTuple{
           {1.792000e+01, 1.829000e+01, 1.866000e+01, 1.903300e+01, 1.940640e+01}, // SINR
           {9.846154e-01, 7.377874e-01, 1.875929e-01, 8.700000e-03, 0}             // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.780000e+01, 1.847000e+01, 1.880000e+01, 1.913000e+01, 1.979500e+01}, // SINR
           {9.942308e-01, 4.049521e-01, 5.020000e-02, 1.400000e-03, 0}             // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.758000e+01, 1.823000e+01, 1.888000e+01, 1.953180e+01}, // SINR
           {1, 8.801370e-01, 3.280000e-02, 0}                        // BLER
       }},
      {3824U, // SINR and BLER for CBS 3824
       MmWaveEesmErrorModel::DoubleTuple{
           {1.825000e+01, 1.863000e+01, 19, 1.937500e+01, 1.975000e+01}, // SINR
           {9.073427e-01, 3.286554e-01, 1.230000e-02, 4.000000e-04, 0}   // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.781000e+01, 1.848000e+01, 1.881000e+01, 1.915000e+01, 1.981330e+01}, // SINR
           {9.971154e-01, 4.631818e-01, 5.320000e-02, 1.000000e-03, 0}             // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.834000e+01,
            1.870000e+01,
            1.888300e+01,
            1.906000e+01,
            1.942470e+01,
            1.996630e+01},                                                           // SINR
           {9.005282e-01, 3.285714e-01, 1.026560e-01, 1.840000e-02, 5.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.782000e+01,
            1.820000e+01,
            1.859000e+01,
            1.897000e+01,
            1.935240e+01,
            1.973590e+01},                                                // SINR
           {1, 8.906250e-01, 2.413462e-01, 6.800000e-03, 1.000000e-04, 0} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.793000e+01,
            1.838000e+01,
            1.860000e+01,
            1.883000e+01,
            1.927500e+01,
            1.995000e+01},                                                           // SINR
           {9.990385e-01, 8.303571e-01, 4.313559e-01, 8.934295e-02, 1.000000e-04, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.827000e+01, 1.869000e+01, 1.911490e+01, 1.953980e+01}, // SINR
           {9.193262e-01, 2.233570e-01, 2.000000e-03, 0}             // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.826000e+01,
            1.854000e+01,
            1.868000e+01,
            1.882000e+01,
            1.910000e+01,
            1.952500e+01},                                                           // SINR
           {9.294643e-01, 4.913462e-01, 2.075783e-01, 5.750000e-02, 9.000000e-04, 0} // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.820000e+01,
            1.845000e+01,
            1.870000e+01,
            1.895000e+01,
            1.920000e+01,
            1.945000e+01},                                                           // SINR
           {9.961538e-01, 8.241935e-01, 2.855530e-01, 2.140000e-02, 2.000000e-04, 0} // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.740000e+01, 1.807000e+01, 1.840000e+01, 1.873000e+01, 1.940000e+01}, // SINR
           {1, 9.990385e-01, 8.758503e-01, 1.871269e-01, 0}                        // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.767000e+01, 1.826000e+01, 1.885360e+01, 1.944980e+01}, // SINR
           {1, 8.053797e-01, 2.200000e-03, 0}                        // BLER
       }}},
     {       // MCS 26
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.907000e+01,
            1.975230e+01,
            2.043940e+01,
            2.112640e+01,
            2.181340e+01,
            2.250050e+01,
            2.319000e+01}, // SINR
           {9.498175e-01,
            7.672156e-01,
            4.379340e-01,
            1.579445e-01,
            3.240000e-02,
            3.000000e-03,
            1.000000e-04} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {1.940000e+01,
            1.985000e+01,
            2.030000e+01,
            2.075000e+01,
            2.120000e+01,
            2.165000e+01,
            2.210000e+01,
            2.255000e+01,
            23}, // SINR
           {9.022887e-01,
            7.500000e-01,
            5.166331e-01,
            2.841928e-01,
            1.188330e-01,
            3.750000e-02,
            8.300000e-03,
            1.500000e-03,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.860000e+01,
            1.947670e+01,
            2.035680e+01,
            2.123680e+01,
            2.211680e+01,
            2.299690e+01}, // SINR
           {9.913462e-01,
            8.932292e-01,
            4.865385e-01,
            1.058761e-01,
            8.000000e-03,
            3.000000e-04} // BLER
       }},
      {408U, // SINR and BLER for CBS 408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.931640e+01,
            2.023650e+01,
            2.115660e+01,
            2.207680e+01,
            2.299690e+01,
            2.392000e+01},                                                           // SINR
           {9.788462e-01, 7.901235e-01, 3.056901e-01, 3.490000e-02, 1.100000e-03, 0} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.895000e+01,
            1.940000e+01,
            1.985000e+01,
            2.030000e+01,
            2.075000e+01,
            2.120000e+01,
            2.165000e+01,
            2.210000e+01}, // SINR
           {9.494485e-01,
            8.261218e-01,
            6.018957e-01,
            3.215190e-01,
            1.146214e-01,
            3.150000e-02,
            4.300000e-03,
            4.000000e-04} // BLER
       }},
      {504U, // SINR and BLER for CBS 504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.950500e+01, 2.037800e+01, 2.125090e+01, 2.212390e+01, 2.299690e+01}, // SINR
           {9.659091e-01, 7.064917e-01, 2.146508e-01, 1.390000e-02, 1.000000e-04}  // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.932990e+01, 2.024660e+01, 2.116340e+01, 2.208010e+01, 2.299690e+01}, // SINR
           {9.038462e-01, 3.896154e-01, 3.200000e-02, 5.000000e-04, 0}             // BLER
       }},
      {576U, // SINR and BLER for CBS 576
       MmWaveEesmErrorModel::DoubleTuple{
           {1.848000e+01,
            1.903000e+01,
            1.958000e+01,
            2.012930e+01,
            2.067520e+01,
            2.122120e+01,
            2.176720e+01,
            2.231310e+01}, // SINR
           {9.913462e-01,
            8.880208e-01,
            6.450000e-01,
            2.675159e-01,
            5.520000e-02,
            6.700000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {640U, // SINR and BLER for CBS 640
       MmWaveEesmErrorModel::DoubleTuple{
           {1.846000e+01, 1.936540e+01, 2.027330e+01, 2.118120e+01, 2.208900e+01}, // SINR
           {9.942308e-01, 8.168790e-01, 2.154437e-01, 5.800000e-03, 0}             // BLER
       }},
      {672U, // SINR and BLER for CBS 672
       MmWaveEesmErrorModel::DoubleTuple{
           {1.842000e+01,
            1.933930e+01,
            2.025370e+01,
            2.116810e+01,
            2.208250e+01,
            2.299690e+01},                                                           // SINR
           {9.951923e-01, 8.369205e-01, 2.406966e-01, 6.900000e-03, 1.000000e-04, 0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.884000e+01,
            1.934000e+01,
            1.984000e+01,
            2.034000e+01,
            2.084000e+01,
            2.134000e+01,
            2.184000e+01}, // SINR
           {9.828244e-01,
            8.690878e-01,
            5.538043e-01,
            1.898567e-01,
            3.130000e-02,
            1.400000e-03,
            0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.921000e+01,
            1.984000e+01,
            2.047110e+01,
            2.110260e+01,
            2.173400e+01,
            2.236540e+01,
            2.299690e+01}, // SINR
           {9.875954e-01,
            8.566667e-01,
            3.952492e-01,
            5.860000e-02,
            2.600000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.934000e+01,
            1.961000e+01,
            1.988000e+01,
            2.015000e+01,
            2.042000e+01,
            2.070000e+01,
            2.097500e+01,
            2.125000e+01,
            2.152500e+01,
            2.180000e+01}, // SINR
           {9.205357e-01,
            7.906442e-01,
            6.070574e-01,
            3.921340e-01,
            1.819826e-01,
            6.470000e-02,
            1.610000e-02,
            3.900000e-03,
            7.000000e-04,
            0} // BLER
       }},
      {1032U, // SINR and BLER for CBS 1032
       MmWaveEesmErrorModel::DoubleTuple{
           {1.954000e+01,
            1.975000e+01,
            1.996000e+01,
            2.017000e+01,
            2.037500e+01,
            2.058130e+01,
            2.078750e+01,
            2.099370e+01,
            2.120000e+01,
            2.141000e+01,
            2.161000e+01,
            2.182000e+01}, // SINR
           {9.250000e-01,
            8.341503e-01,
            6.929945e-01,
            5.125502e-01,
            3.282468e-01,
            1.741010e-01,
            7.700000e-02,
            3.030000e-02,
            1.050000e-02,
            2.900000e-03,
            9.000000e-04,
            3.000000e-04} // BLER
       }},
      {1128U, // SINR and BLER for CBS 1128
       MmWaveEesmErrorModel::DoubleTuple{
           {1.895000e+01,
            1.929000e+01,
            1.963000e+01,
            1.996000e+01,
            2.030000e+01,
            2.063750e+01,
            2.097500e+01,
            2.131250e+01,
            2.165000e+01}, // SINR
           {9.592593e-01,
            8.077532e-01,
            5.173469e-01,
            2.174007e-01,
            4.980000e-02,
            6.700000e-03,
            1.200000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {1192U, // SINR and BLER for CBS 1192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.907000e+01,
            1.950800e+01,
            1.994410e+01,
            2.038030e+01,
            2.081640e+01,
            2.125250e+01}, // SINR
           {9.181338e-01,
            6.312189e-01,
            2.202797e-01,
            3.500000e-02,
            1.800000e-03,
            1.000000e-04} // BLER
       }},
      {1288U, // SINR and BLER for CBS 1288
       MmWaveEesmErrorModel::DoubleTuple{
           {1.889000e+01,
            1.933000e+01,
            1.977000e+01,
            2.021260e+01,
            2.065290e+01,
            2.109330e+01,
            2.153370e+01,
            2.197400e+01}, // SINR
           {9.751908e-01,
            8.216561e-01,
            4.195261e-01,
            8.986268e-02,
            4.400000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1352U, // SINR and BLER for CBS 1352
       MmWaveEesmErrorModel::DoubleTuple{
           {1.887000e+01,
            1.927000e+01,
            1.966560e+01,
            2.006130e+01,
            2.045700e+01,
            2.085270e+01,
            2.124840e+01}, // SINR
           {9.894231e-01,
            8.616667e-01,
            5.594714e-01,
            1.809541e-01,
            2.320000e-02,
            1.300000e-03,
            0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.890000e+01,
            1.936000e+01,
            1.982110e+01,
            2.028060e+01,
            2.074010e+01,
            2.119950e+01},                                                           // SINR
           {9.903846e-01, 8.827586e-01, 4.549107e-01, 7.930000e-02, 3.500000e-03, 0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.901000e+01,
            1.944000e+01,
            1.987000e+01,
            2.029560e+01,
            2.072080e+01,
            2.114590e+01},                                                           // SINR
           {9.961538e-01, 8.843537e-01, 4.738806e-01, 8.650000e-02, 4.400000e-03, 0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.933000e+01, 1.980830e+01, 2.028660e+01, 2.076490e+01, 2.124320e+01}, // SINR
           {9.461679e-01, 5.769231e-01, 9.455645e-02, 3.000000e-03, 0}             // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {1.884000e+01, 1.933000e+01, 1.981820e+01, 2.030570e+01, 2.079320e+01}, // SINR
           {9.903846e-01, 8.274194e-01, 2.475490e-01, 9.000000e-03, 0}             // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {19, 1.950000e+01, 1.999690e+01, 2.049690e+01, 2.099690e+01}, // SINR
           {9.875000e-01, 6.658031e-01, 1.088004e-01, 1.100000e-03, 0}   // BLER
       }},
      {2408U, // SINR and BLER for CBS 2408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.881000e+01,
            1.913000e+01,
            1.945000e+01,
            1.978000e+01,
            2.010000e+01,
            2.042500e+01,
            2.075000e+01,
            2.107500e+01}, // SINR
           {9.866412e-01,
            8.657718e-01,
            4.932171e-01,
            1.123532e-01,
            8.900000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2600U, // SINR and BLER for CBS 2600
       MmWaveEesmErrorModel::DoubleTuple{
           {1.911000e+01, 1.945000e+01, 1.979000e+01, 2.012850e+01, 2.047180e+01}, // SINR
           {9.271583e-01, 5.705556e-01, 1.437572e-01, 9.000000e-03, 0}             // BLER
       }},
      {2792U, // SINR and BLER for CBS 2792
       MmWaveEesmErrorModel::DoubleTuple{
           {1.920000e+01, 1.965000e+01, 2.010000e+01, 2.055000e+01, 21}, // SINR
           {9.003497e-01, 3.298429e-01, 1.980000e-02, 1.000000e-04, 0}   // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.851000e+01, 1.918000e+01, 1.951000e+01, 1.985000e+01, 2.051490e+01}, // SINR
           {1, 7.898773e-01, 2.723599e-01, 2.580000e-02, 0}                        // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.911000e+01, 1.949000e+01, 1.987000e+01, 2.024950e+01, 2.062440e+01}, // SINR
           {9.605263e-01, 5.365466e-01, 6.250000e-02, 1.000000e-03, 0}             // BLER
       }},
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.833000e+01, 19, 1.933000e+01, 1.967000e+01, 2.033380e+01}, // SINR
           {1, 9.740385e-01, 6.522843e-01, 1.376096e-01, 0}              // BLER
       }},
      {4032U, // SINR and BLER for CBS 4032
       MmWaveEesmErrorModel::DoubleTuple{
           {1.896000e+01,
            1.927000e+01,
            1.958000e+01,
            1.989000e+01,
            2.020000e+01,
            2.051250e+01},                                                           // SINR
           {9.865385e-01, 7.852761e-01, 2.644130e-01, 1.900000e-02, 4.000000e-04, 0} // BLER
       }},
      {4480U, // SINR and BLER for CBS 4480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.926000e+01,
            1.967000e+01,
            1.988000e+01,
            2.009000e+01,
            2.050000e+01,
            2.112500e+01},                                                           // SINR
           {9.494485e-01, 3.836858e-01, 1.189573e-01, 1.900000e-02, 2.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.860000e+01, 1.927000e+01, 1.960000e+01, 1.993000e+01, 2.060000e+01}, // SINR
           {1, 9.598881e-01, 6.070574e-01, 1.181539e-01, 0}                        // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {1.850000e+01,
            1.917000e+01,
            1.950000e+01,
            1.983000e+01,
            2.050000e+01,
            2.150000e+01},                                                // SINR
           {1, 9.980769e-01, 8.614865e-01, 3.149876e-01, 3.000000e-04, 0} // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {19, 1.967000e+01, 20, 2.033000e+01, 21},        // SINR
           {1, 4.209437e-01, 4.120000e-02, 3.000000e-04, 0} // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.880000e+01, 1.947000e+01, 1.980000e+01, 2.013000e+01, 2.080000e+01}, // SINR
           {1, 5.358650e-01, 4.780000e-02, 5.000000e-04, 0}                        // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {1.895000e+01, 1.962000e+01, 1.995000e+01, 2.028000e+01}, // SINR
           {9.942308e-01, 2.007154e-01, 4.100000e-03, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {1.930000e+01, 1.963000e+01, 1.997000e+01, 2.030000e+01}, // SINR
           {9.338768e-01, 3.520195e-01, 1.090000e-02, 0}             // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.860000e+01, 1.927000e+01, 1.960000e+01, 1.993000e+01, 2.060000e+01}, // SINR
           {1, 8.625000e-01, 1.967919e-01, 3.200000e-03, 0}                        // BLER
       }}},
     {       // MCS 27
      {320U, // SINR and BLER for CBS 320
       MmWaveEesmErrorModel::DoubleTuple{
           {2.025300e+01,
            2.055880e+01,
            2.086460e+01,
            2.117040e+01,
            2.147620e+01,
            2.178000e+01,
            2.209000e+01,
            2.239000e+01,
            2.270000e+01,
            2.301000e+01,
            2.331000e+01,
            2.362000e+01,
            2.392000e+01,
            2.423000e+01,
            2.453000e+01}, // SINR
           {9.490741e-01,
            8.931034e-01,
            7.955247e-01,
            6.785714e-01,
            5.400844e-01,
            4.230132e-01,
            2.815996e-01,
            1.794872e-01,
            1.008699e-01,
            5.070000e-02,
            2.640000e-02,
            1.160000e-02,
            5.300000e-03,
            1.400000e-03,
            3.000000e-04} // BLER
       }},
      {352U, // SINR and BLER for CBS 352
       MmWaveEesmErrorModel::DoubleTuple{
           {2.037450e+01,
            2.105850e+01,
            2.174240e+01,
            2.242630e+01,
            2.311030e+01,
            2.379000e+01,
            2.448000e+01,
            2.516000e+01}, // SINR
           {9.082168e-01,
            6.871693e-01,
            3.656609e-01,
            1.178471e-01,
            2.470000e-02,
            2.600000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {408U, // SINR and BLER for CBS 408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.979000e+01,
            2.036820e+01,
            2.095020e+01,
            2.153230e+01,
            2.211430e+01,
            2.269630e+01,
            2.328000e+01}, // SINR
           {9.131206e-01,
            7.233146e-01,
            4.195545e-01,
            1.502088e-01,
            3.170000e-02,
            3.600000e-03,
            2.000000e-04} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {2.040810e+01,
            2.091480e+01,
            2.142140e+01,
            2.192800e+01,
            2.243470e+01,
            2.294000e+01,
            2.345000e+01,
            2.395000e+01,
            2.446000e+01,
            2.497000e+01,
            2.547000e+01,
            2.598000e+01,
            2.649000e+01}, // SINR
           {9.715909e-01,
            8.834459e-01,
            6.788564e-01,
            4.462413e-01,
            2.245989e-01,
            8.150000e-02,
            2.380000e-02,
            7.000000e-03,
            1.700000e-03,
            4.000000e-04,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {504U, // SINR and BLER for CBS 504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.941000e+01,
            1.990000e+01,
            2.039220e+01,
            2.088670e+01,
            2.138130e+01,
            2.187580e+01,
            2.237030e+01,
            2.286000e+01,
            2.336000e+01}, // SINR
           {9.734848e-01,
            8.932292e-01,
            7.015027e-01,
            4.111201e-01,
            1.520024e-01,
            3.590000e-02,
            4.800000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {576U, // SINR and BLER for CBS 576
       MmWaveEesmErrorModel::DoubleTuple{
           {2.010000e+01,
            2.060000e+01,
            2.110000e+01,
            2.160000e+01,
            2.210000e+01,
            2.260000e+01,
            2.310000e+01,
            2.360000e+01}, // SINR
           {9.375000e-01,
            7.665663e-01,
            4.572842e-01,
            1.772599e-01,
            4.180000e-02,
            5.900000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {640U, // SINR and BLER for CBS 640
       MmWaveEesmErrorModel::DoubleTuple{
           {2.010000e+01,
            2.060000e+01,
            2.110000e+01,
            2.160000e+01,
            2.210000e+01,
            2.260000e+01,
            2.310000e+01,
            2.360000e+01}, // SINR
           {9.266304e-01,
            7.301136e-01,
            4.001572e-01,
            1.357104e-01,
            2.370000e-02,
            2.500000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {672U, // SINR and BLER for CBS 672
       MmWaveEesmErrorModel::DoubleTuple{
           {2.013000e+01, 2.078750e+01, 2.144500e+01, 2.210250e+01, 2.276000e+01}, // SINR
           {9.228723e-01, 6.171117e-01, 1.826087e-01, 2.250000e-02, 6.000000e-04}  // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.972000e+01,
            2.020000e+01,
            2.067500e+01,
            2.115000e+01,
            2.162500e+01,
            2.210000e+01,
            2.258000e+01,
            2.305000e+01}, // SINR
           {9.817308e-01,
            8.880208e-01,
            6.107143e-01,
            2.938799e-01,
            7.360000e-02,
            1.080000e-02,
            3.000000e-04,
            0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {2.003000e+01,
            2.040000e+01,
            2.077500e+01,
            2.115000e+01,
            2.152500e+01,
            2.190000e+01,
            2.228000e+01,
            2.265000e+01,
            2.303000e+01}, // SINR
           {9.325540e-01,
            7.822086e-01,
            5.080000e-01,
            2.332714e-01,
            6.820000e-02,
            1.330000e-02,
            1.500000e-03,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {1032U, // SINR and BLER for CBS 1032
       MmWaveEesmErrorModel::DoubleTuple{
           {20, 2.062500e+01, 2.125000e+01, 2.187500e+01, 2.250000e+01, 2.313000e+01}, // SINR
           {9.742366e-01,
            7.602339e-01,
            2.852709e-01,
            3.120000e-02,
            2.300000e-03,
            3.000000e-04} // BLER
       }},
      {1128U, // SINR and BLER for CBS 1128
       MmWaveEesmErrorModel::DoubleTuple{
           {2.020000e+01,
            2.055000e+01,
            2.090000e+01,
            2.125000e+01,
            2.160000e+01,
            2.195000e+01,
            2.230000e+01,
            2.265000e+01}, // SINR
           {9.384058e-01,
            7.786145e-01,
            5.079365e-01,
            2.093647e-01,
            5.310000e-02,
            9.300000e-03,
            9.000000e-04,
            0} // BLER
       }},
      {1192U, // SINR and BLER for CBS 1192
       MmWaveEesmErrorModel::DoubleTuple{
           {2.020000e+01,
            2.046250e+01,
            2.072500e+01,
            2.098750e+01,
            2.125000e+01,
            2.151000e+01,
            2.178000e+01,
            2.204000e+01,
            2.230000e+01,
            2.256000e+01}, // SINR
           {9.420290e-01,
            8.113208e-01,
            5.985915e-01,
            3.717105e-01,
            1.768934e-01,
            6.650000e-02,
            1.570000e-02,
            1.900000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {1288U, // SINR and BLER for CBS 1288
       MmWaveEesmErrorModel::DoubleTuple{
           {1.999690e+01,
            2.044080e+01,
            2.088470e+01,
            2.132860e+01,
            2.177250e+01,
            2.222000e+01,
            2.266000e+01,
            2.310000e+01}, // SINR
           {9.652256e-01,
            8.344156e-01,
            4.507168e-01,
            1.077773e-01,
            1.170000e-02,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1352U, // SINR and BLER for CBS 1352
       MmWaveEesmErrorModel::DoubleTuple{
           {2.003000e+01, 2.059250e+01, 2.115500e+01, 2.171750e+01, 2.228000e+01}, // SINR
           {9.687500e-01, 6.959459e-01, 1.808549e-01, 1.260000e-02, 3.000000e-04}  // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.993000e+01,
            2.030000e+01,
            2.067500e+01,
            2.105000e+01,
            2.142500e+01,
            2.180000e+01,
            2.218000e+01}, // SINR
           {9.818702e-01,
            8.758562e-01,
            5.737613e-01,
            2.126678e-01,
            3.870000e-02,
            2.700000e-03,
            1.000000e-04} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {2.006000e+01,
            2.028000e+01,
            2.050000e+01,
            2.072500e+01,
            2.095000e+01,
            2.117500e+01,
            2.140000e+01,
            2.163000e+01,
            2.185000e+01,
            2.207000e+01,
            2.230000e+01}, // SINR
           {9.589552e-01,
            8.630952e-01,
            6.915761e-01,
            4.572842e-01,
            2.288636e-01,
            8.220000e-02,
            2.400000e-02,
            4.700000e-03,
            8.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {2.003000e+01,
            2.030160e+01,
            2.057220e+01,
            2.084270e+01,
            2.111330e+01,
            2.138380e+01,
            2.165000e+01,
            2.192000e+01,
            2.220000e+01}, // SINR
           {9.512868e-01,
            8.559603e-01,
            6.165865e-01,
            3.085558e-01,
            9.701797e-02,
            2.020000e-02,
            1.900000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {1.980000e+01,
            2.007000e+01,
            2.034000e+01,
            2.061370e+01,
            2.088880e+01,
            2.116390e+01,
            2.143900e+01,
            2.171410e+01}, // SINR
           {9.029720e-01,
            6.848118e-01,
            3.709795e-01,
            1.209056e-01,
            2.190000e-02,
            2.800000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {1.956000e+01, 2.003000e+01, 2.050000e+01, 2.097000e+01, 2.144000e+01}, // SINR
           {9.836538e-01, 7.492690e-01, 2.118465e-01, 1.200000e-02, 0}             // BLER
       }},
      {2408U, // SINR and BLER for CBS 2408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.963000e+01, 2.014250e+01, 2.065330e+01, 2.116420e+01, 2.167500e+01}, // SINR
           {9.855769e-01, 6.798942e-01, 8.700000e-02, 1.600000e-03, 0}             // BLER
       }},
      {2600U, // SINR and BLER for CBS 2600
       MmWaveEesmErrorModel::DoubleTuple{
           {1.980000e+01,
            2.010000e+01,
            2.040000e+01,
            2.070000e+01,
            21,
            2.130000e+01,
            2.160000e+01}, // SINR
           {9.489051e-01,
            7.180556e-01,
            3.183249e-01,
            6.080000e-02,
            3.600000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {2792U, // SINR and BLER for CBS 2792
       MmWaveEesmErrorModel::DoubleTuple{
           {1.933000e+01, 1.992000e+01, 2.051500e+01, 2.111000e+01, 2.170500e+01}, // SINR
           {1, 8.897569e-01, 1.761522e-01, 4.000000e-04, 0}                        // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.970000e+01,
            2.004000e+01,
            2.038010e+01,
            2.071950e+01,
            2.105890e+01,
            2.139840e+01},                                                           // SINR
           {9.790076e-01, 7.625740e-01, 2.638309e-01, 2.400000e-02, 8.000000e-04, 0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.970000e+01,
            2.004000e+01,
            2.037500e+01,
            2.071500e+01,
            2.105490e+01,
            2.139490e+01},                                                           // SINR
           {9.913462e-01, 8.319805e-01, 3.554469e-01, 3.660000e-02, 6.000000e-04, 0} // BLER
       }},
      {3840U, // SINR and BLER for CBS 3840
       MmWaveEesmErrorModel::DoubleTuple{
           {1.972000e+01,
            2.006000e+01,
            2.040030e+01,
            2.073760e+01,
            2.107480e+01,
            2.141210e+01,
            2.174930e+01}, // SINR
           {9.932692e-01,
            8.376623e-01,
            2.851474e-01,
            2.390000e-02,
            6.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {4096U, // SINR and BLER for CBS 4096
       MmWaveEesmErrorModel::DoubleTuple{
           {1.973000e+01, 2.007000e+01, 2.040550e+01, 2.074220e+01, 2.107890e+01}, // SINR
           {9.608209e-01, 5.414894e-01, 8.263052e-02, 1.800000e-03, 0}             // BLER
       }},
      {4224U, // SINR and BLER for CBS 4224
       MmWaveEesmErrorModel::DoubleTuple{
           {2.006000e+01,
            2.039390e+01,
            2.073180e+01,
            2.106980e+01,
            2.140780e+01,
            2.174570e+01},                                                           // SINR
           {9.742366e-01, 6.645078e-01, 1.425936e-01, 5.400000e-03, 1.000000e-04, 0} // BLER
       }},
      {4864U, // SINR and BLER for CBS 4864
       MmWaveEesmErrorModel::DoubleTuple{
           {2.005000e+01,
            2.030000e+01,
            2.055000e+01,
            2.080000e+01,
            2.105000e+01,
            2.130000e+01}, // SINR
           {9.734848e-01,
            7.870370e-01,
            4.105987e-01,
            9.784879e-02,
            8.400000e-03,
            3.000000e-04} // BLER
       }},
      {5248U, // SINR and BLER for CBS 5248
       MmWaveEesmErrorModel::DoubleTuple{
           {2.010000e+01, 2.040000e+01, 2.070000e+01, 21, 2.130000e+01, 2.160000e+01}, // SINR
           {9.661654e-01, 6.712963e-01, 1.803957e-01, 1.020000e-02, 2.000000e-04, 0}   // BLER
       }},
      {5504U, // SINR and BLER for CBS 5504
       MmWaveEesmErrorModel::DoubleTuple{
           {1.990000e+01,
            2.015000e+01,
            2.040000e+01,
            2.065000e+01,
            2.090000e+01,
            2.115000e+01,
            2.140000e+01}, // SINR
           {9.807692e-01,
            8.360390e-01,
            4.321672e-01,
            9.324104e-02,
            5.600000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {6272U, // SINR and BLER for CBS 6272
       MmWaveEesmErrorModel::DoubleTuple{
           {2.007310e+01,
            2.042000e+01,
            2.059430e+01,
            2.077000e+01,
            2.111560e+01,
            2.163690e+01},                                                           // SINR
           {9.420290e-01, 4.330205e-01, 1.532702e-01, 2.830000e-02, 1.000000e-04, 0} // BLER
       }},
      {6912U, // SINR and BLER for CBS 6912
       MmWaveEesmErrorModel::DoubleTuple{
           {2.020000e+01, 2.052500e+01, 2.085000e+01, 2.117500e+01, 2.150000e+01}, // SINR
           {9.884615e-01, 7.005495e-01, 1.332359e-01, 3.900000e-03, 0}             // BLER
       }},
      {7680U, // SINR and BLER for CBS 7680
       MmWaveEesmErrorModel::DoubleTuple{
           {2.033000e+01, 2.062980e+01, 2.092540e+01, 2.122100e+01}, // SINR
           {9.375000e-01, 4.534050e-01, 4.480000e-02, 0}             // BLER
       }},
      {8192U, // SINR and BLER for CBS 8192
       MmWaveEesmErrorModel::DoubleTuple{
           {2.014000e+01, 2.051700e+01, 2.089590e+01, 2.127480e+01}, // SINR
           {9.397482e-01, 2.915704e-01, 3.000000e-03, 0}             // BLER
       }}},
     {       // MCS 28
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.968790e+01,
            2.079870e+01,
            2.190940e+01,
            2.302020e+01,
            2.413100e+01,
            2.524000e+01,
            2.635000e+01,
            2.746000e+01,
            2.857000e+01,
            2.968000e+01}, // SINR
           {1,
            9.961538e-01,
            9.366071e-01,
            6.135266e-01,
            2.525050e-01,
            6.050000e-02,
            1.030000e-02,
            1.200000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {408U, // SINR and BLER for CBS 408
       MmWaveEesmErrorModel::DoubleTuple{
           {2.141890e+01,
            2.217820e+01,
            2.293740e+01,
            2.369670e+01,
            2.446000e+01,
            2.522000e+01,
            2.597000e+01,
            2.673000e+01,
            2.749000e+01,
            2.825000e+01,
            2.901000e+01,
            2.977000e+01,
            3.053000e+01}, // SINR
           {1,
            9.826923e-01,
            9.020979e-01,
            7.308239e-01,
            4.574373e-01,
            2.514940e-01,
            1.127473e-01,
            4.310000e-02,
            1.410000e-02,
            3.900000e-03,
            1.400000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {2.126270e+01,
            2.203000e+01,
            2.279740e+01,
            2.356480e+01,
            2.433210e+01,
            2.510000e+01,
            2.587000e+01,
            2.663000e+01,
            2.740000e+01}, // SINR
           {9.713740e-01,
            8.282258e-01,
            5.079681e-01,
            2.168675e-01,
            6.430000e-02,
            1.410000e-02,
            2.700000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {504U, // SINR and BLER for CBS 504
       MmWaveEesmErrorModel::DoubleTuple{
           {2.097120e+01,
            2.181140e+01,
            2.265170e+01,
            2.349190e+01,
            2.433210e+01,
            2.517000e+01,
            2.601000e+01,
            2.685000e+01}, // SINR
           {9.971154e-01,
            9.262590e-01,
            6.337500e-01,
            2.602881e-01,
            6.390000e-02,
            7.700000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {528U, // SINR and BLER for CBS 528
       MmWaveEesmErrorModel::DoubleTuple{
           {2.010300e+01,
            2.089590e+01,
            2.168890e+01,
            2.248190e+01,
            2.327480e+01,
            2.407000e+01,
            2.486000e+01,
            2.565000e+01}, // SINR
           {9.980769e-01,
            9.489051e-01,
            6.998626e-01,
            2.955607e-01,
            5.510000e-02,
            4.900000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {576U, // SINR and BLER for CBS 576
       MmWaveEesmErrorModel::DoubleTuple{
           {2.035660e+01,
            2.101270e+01,
            2.166880e+01,
            2.232500e+01,
            2.298110e+01,
            2.364000e+01,
            2.429000e+01,
            2.495000e+01,
            2.561000e+01,
            2.626000e+01,
            2.692000e+01,
            2.757000e+01,
            2.823000e+01}, // SINR
           {1,
            9.980769e-01,
            9.770992e-01,
            8.724662e-01,
            6.380597e-01,
            3.393817e-01,
            1.416479e-01,
            3.940000e-02,
            7.900000e-03,
            1.700000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {640U, // SINR and BLER for CBS 640
       MmWaveEesmErrorModel::DoubleTuple{
           {2.087880e+01,
            2.135810e+01,
            2.183750e+01,
            2.231680e+01,
            2.279620e+01,
            2.328000e+01,
            2.375000e+01,
            2.423000e+01,
            2.471000e+01,
            2.519000e+01,
            2.567000e+01,
            2.615000e+01}, // SINR
           {9.961538e-01,
            9.903846e-01,
            9.133929e-01,
            7.099448e-01,
            4.483216e-01,
            2.166523e-01,
            7.750000e-02,
            1.960000e-02,
            3.300000e-03,
            6.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {672U, // SINR and BLER for CBS 672
       MmWaveEesmErrorModel::DoubleTuple{
           {2.095520e+01,
            2.135390e+01,
            2.175250e+01,
            2.215120e+01,
            2.254980e+01,
            2.295000e+01,
            2.335000e+01,
            2.375000e+01,
            2.414000e+01,
            2.454000e+01,
            2.494000e+01,
            2.534000e+01,
            2.574000e+01}, // SINR
           {9.942308e-01,
            9.694656e-01,
            8.916084e-01,
            7.265625e-01,
            5.161943e-01,
            2.804204e-01,
            1.211390e-01,
            4.510000e-02,
            1.160000e-02,
            2.400000e-03,
            7.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {2.092320e+01,
            2.139890e+01,
            2.187450e+01,
            2.235010e+01,
            2.282580e+01,
            2.330000e+01,
            2.378000e+01,
            2.425000e+01,
            2.473000e+01,
            2.520000e+01,
            2.568000e+01,
            2.616000e+01}, // SINR
           {9.780534e-01,
            8.996479e-01,
            7.125000e-01,
            4.267677e-01,
            1.791548e-01,
            4.880000e-02,
            1.140000e-02,
            2.200000e-03,
            7.000000e-04,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {2.094130e+01,
            2.137450e+01,
            2.180770e+01,
            2.224090e+01,
            2.267410e+01,
            2.311000e+01,
            2.354000e+01,
            2.397000e+01,
            2.441000e+01,
            2.484000e+01,
            2.527000e+01,
            2.571000e+01,
            2.614000e+01}, // SINR
           {9.503676e-01,
            8.105346e-01,
            5.751121e-01,
            2.663502e-01,
            9.080000e-02,
            2.580000e-02,
            6.200000e-03,
            2.000000e-03,
            1.800000e-03,
            9.000000e-04,
            7.000000e-04,
            6.000000e-04,
            3.000000e-04} // BLER
       }}}},
    {       // BG TYPE 2
     {      // MCS 0
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.498600e+00, -1.393600e+00, -2.886500e-01, 8.163200e-01, 1.921300e+00}, // SINR
           {9.466912e-01, 6.599741e-01, 1.915906e-01, 8.100000e-03, 1.000000e-04}     // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.500000e+00, -1.342500e+00, -1.850000e-01, 9.725000e-01, 2.130000e+00}, // SINR
           {9.479927e-01, 6.070574e-01, 9.377559e-02, 8.000000e-04, 0}                // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.700000e+00, -1.475000e+00, -2.500000e-01, 9.750000e-01, 2.200000e+00}, // SINR
           {9.696970e-01, 6.201456e-01, 5.760000e-02, 6.000000e-04, 0}                // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.570000e+00, -1.557500e+00, -5.450000e-01, 4.675000e-01, 1.480000e+00}, // SINR
           {9.671053e-01, 6.878378e-01, 1.253754e-01, 1.500000e-03, 0}                // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.430000e+00, -1.490000e+00, -5.500000e-01, 3.900000e-01, 1.330000e+00}, // SINR
           {9.626866e-01, 6.361940e-01, 1.016472e-01, 1.700000e-03, 1.000000e-04}     // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.550000e+00, -1.737500e+00, -9.250000e-01, -1.125000e-01, 7.000000e-01}, // SINR
           {9.742366e-01, 7.099448e-01, 1.794413e-01, 6.700000e-03, 1.000000e-04}      // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.550000e+00, -1.737500e+00, -9.250000e-01, -1.125000e-01, 7.000000e-01}, // SINR
           {9.788462e-01, 7.320402e-01, 1.785206e-01, 6.600000e-03, 0}                 // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.300000e+00, -2.300000e+00, -1.300000e+00, -3.000000e-01, 7.000000e-01}, // SINR
           {1, 9.577068e-01, 4.131494e-01, 1.410000e-02, 0}                            // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.680000e+00, -1.612500e+00, -5.450000e-01, 5.225000e-01}, // SINR
           {9.875000e-01, 6.060427e-01, 2.430000e-02, 0}                // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.200000e+00, -1.200000e+00, -2.000000e-01, 8.000000e-01}, // SINR
           {9.361511e-01, 2.635983e-01, 2.000000e-03, 0}                // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.442700e+00, -2.430200e+00, -1.417800e+00, -4.053400e-01, 6.071200e-01}, // SINR
           {1, 9.725379e-01, 4.003968e-01, 3.900000e-03, 0}                            // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.600000e+00,
            -2.225000e+00,
            -1.310000e+00,
            -8.500000e-01,
            -3.900000e-01,
            5.250000e-01},                                                // SINR
           {1, 9.574074e-01, 2.997024e-01, 5.010000e-02, 3.000000e-03, 0} // BLER
       }},
      {152U, // SINR and BLER for CBS 152
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.074700e+00, -2.263900e+00, -1.453100e+00, -6.422300e-01, 1.685900e-01}, // SINR
           {1, 9.589552e-01, 3.970126e-01, 9.900000e-03, 0}                            // BLER
       }},
      {160U, // SINR and BLER for CBS 160
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.153500e+00, -1.579600e+00, -1.005800e+00, -4.318800e-01, 1.419900e-01}, // SINR
           {9.169643e-01, 4.701493e-01, 5.590000e-02, 9.000000e-04, 0}                 // BLER
       }},
      {176U, // SINR and BLER for CBS 176
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.300000e+00, -1.550000e+00, -8.000000e-01, -5.000000e-02}, // SINR
           {9.713740e-01, 4.647436e-01, 1.490000e-02, 0}                 // BLER
       }},
      {184U, // SINR and BLER for CBS 184
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.800000e+00, -2.050000e+00, -1.300000e+00, -5.500000e-01, 2.000000e-01}, // SINR
           {1, 9.271583e-01, 2.715517e-01, 2.000000e-03, 0}                            // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.179100e+00, -1.261800e+00, -3.445500e-01, 5.727300e-01}, // SINR
           {9.855769e-01, 4.248339e-01, 2.600000e-03, 0}                // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.260000e+00, -1.600000e+00, -9.400000e-01, -2.800000e-01, 3.800000e-01}, // SINR
           {9.961538e-01, 8.001543e-01, 1.222168e-01, 2.000000e-04, 0}                 // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.341500e+00, -1.575800e+00, -8.100000e-01, -4.423100e-02}, // SINR
           {1, 7.657186e-01, 4.390000e-02, 0}                            // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.200000e+00, -1.587500e+00, -9.750000e-01, -3.625000e-01, 2.500000e-01}, // SINR
           {9.990385e-01, 7.818182e-01, 1.066396e-01, 7.000000e-04, 0}                 // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.160000e+00, -1.425000e+00, -6.900000e-01, 4.500000e-02}, // SINR
           {9.903846e-01, 5.223029e-01, 6.500000e-03, 0}                // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.300000e+00, -1.475000e+00, -6.500000e-01, 1.750000e-01}, // SINR
           {9.990385e-01, 6.483586e-01, 6.800000e-03, 0}                // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.236300e+00, -1.439700e+00, -6.431500e-01, 1.534300e-01}, // SINR
           {9.980769e-01, 5.720721e-01, 2.800000e-03, 0}                // BLER
       }},
      {528U, // SINR and BLER for CBS 528
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.700000e+00, -1.850000e+00, -1.280000e+00, -1, -7.200000e-01, -1.500000e-01}, // SINR
           {1, 9.205357e-01, 1.950699e-01, 2.390000e-02, 1.200000e-03, 0}                   // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.600000e+00, -1.592500e+00, -5.850000e-01, 4.225000e-01}, // SINR
           {1, 7.911491e-01, 1.400000e-03, 0}                           // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.300000e+00, -1.700000e+00, -1.100000e+00, -5.000000e-01, 1.000000e-01}, // SINR
           {9.990385e-01, 9.352518e-01, 2.256696e-01, 1.000000e-03, 0}                 // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.210000e+00, -1.665000e+00, -1.120000e+00, -5.750000e-01, -3.000000e-02}, // SINR
           {1, 9.479927e-01, 2.495069e-01, 1.100000e-03, 0}                             // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.400000e+00, -1.900000e+00, -1.400000e+00, -9.000000e-01, -4.000000e-01}, // SINR
           {1, 9.990385e-01, 7.001366e-01, 4.800000e-02, 0}                             // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.300000e+00, -1.775000e+00, -1.250000e+00, -7.250000e-01, -2.000000e-01}, // SINR
           {1, 9.817308e-01, 4.436189e-01, 1.150000e-02, 0}                             // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.300000e+00, -1.737500e+00, -1.175000e+00, -6.125000e-01, -5.000000e-02}, // SINR
           {1, 9.778846e-01, 3.181533e-01, 1.300000e-03, 0}                             // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.200000e+00, -1.562500e+00, -9.250000e-01, -2.875000e-01}, // SINR
           {1, 8.792517e-01, 5.670000e-02, 0}                            // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.980000e+00, -1.495000e+00, -1.010000e+00, -5.250000e-01, -4.000000e-02}, // SINR
           {9.990385e-01, 8.277244e-01, 8.336702e-02, 1.000000e-04, 0}                  // BLER
       }},
      {1320U, // SINR and BLER for CBS 1320
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.250000e+00, -1.725000e+00, -1.200000e+00, -6.750000e-01, -1.500000e-01}, // SINR
           {1, 9.865385e-01, 3.560393e-01, 1.900000e-03, 1.000000e-04}                  // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.880000e+00, -1.465000e+00, -1.050000e+00, -6.350000e-01, -2.200000e-01}, // SINR
           {9.961538e-01, 8.360390e-01, 1.396733e-01, 1.200000e-03, 1.000000e-04}       // BLER
       }},
      {1672U, // SINR and BLER for CBS 1672
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.750000e+00, -1.375000e+00, -1, -6.250000e-01, -2.500000e-01},      // SINR
           {9.855769e-01, 6.798942e-01, 7.300000e-02, 6.000000e-04, 4.000000e-04} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.191200e+00, -1.600000e+00, -1.299200e+00, -1, -4.073000e-01, 4.846500e-01}, // SINR
           {1, 9.333942e-01, 4.960784e-01, 7.060000e-02, 1.000000e-04, 0}                  // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.406200e+00, -1.770000e+00, -1.446500e+00, -1.130000e+00, -4.867000e-01}, // SINR
           {1, 9.961538e-01, 7.960938e-01, 2.022947e-01, 0}                             // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.780000e+00, -1.367500e+00, -9.550000e-01, -5.425000e-01, -1.300000e-01}, // SINR
           {9.932692e-01, 7.356322e-01, 6.410000e-02, 3.000000e-04, 1.000000e-04}       // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.149300e+00,
            -1.660000e+00,
            -1.413500e+00,
            -1.170000e+00,
            -6.776900e-01,
            5.812300e-02},                                                // SINR
           {1, 9.552920e-01, 7.008197e-01, 2.178819e-01, 4.000000e-04, 0} // BLER
       }},
      {2408U, // SINR and BLER for CBS 2408
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.730000e+00, -1.297500e+00, -8.650000e-01, -4.325000e-01, 0},       // SINR
           {9.942308e-01, 5.126518e-01, 8.400000e-03, 2.000000e-04, 2.000000e-04} // BLER
       }},
      {2792U, // SINR and BLER for CBS 2792
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.830000e+00, -1.297500e+00, -7.650000e-01, -2.325000e-01, 3.000000e-01}, // SINR
           {1, 5.567686e-01, 3.200000e-03, 1.000000e-04, 0}                            // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.680000e+00,
            -1.370000e+00,
            -1.210000e+00,
            -1.050000e+00,
            -7.400000e-01,
            -2.700000e-01,
            2.000000e-01}, // SINR
           {9.865385e-01,
            6.135817e-01,
            2.600932e-01,
            5.850000e-02,
            7.000000e-04,
            2.000000e-04,
            2.000000e-04} // BLER
       }},
      {3240U, // SINR and BLER for CBS 3240
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.325500e+00, -1.610000e+00, -1.245800e+00, -8.900000e-01, -1.661500e-01}, // SINR
           {1, 9.761450e-01, 4.875479e-01, 2.100000e-02, 0}                             // BLER
       }},
      {3624U, // SINR and BLER for CBS 3624
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.144400e+00, -1.550000e+00, -1.250000e+00, -9.500000e-01, -3.555500e-01}, // SINR
           {1, 9.680451e-01, 5.543478e-01, 6.290000e-02, 0}                             // BLER
       }}},
     {      // MCS 1
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.400000e+00, -3.000000e-01, 8.000000e-01, 1.900000e+00, 3}, // SINR
           {9.038462e-01, 5.473404e-01, 1.214874e-01, 4.300000e-03, 0}    // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.400000e+00,
            -7.250000e-01,
            -5.000000e-02,
            6.250000e-01,
            1.300000e+00,
            1.980000e+00,
            2.650000e+00,
            3.330000e+00}, // SINR
           {9.181338e-01,
            7.113764e-01,
            4.029968e-01,
            1.252485e-01,
            1.830000e-02,
            1.200000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.220000e+00,
            -1.424200e+00,
            -6.255700e-01,
            1.730500e-01,
            9.716700e-01,
            1.770300e+00}, // SINR
           {9.932692e-01,
            8.974138e-01,
            6.124402e-01,
            2.077145e-01,
            2.140000e-02,
            2.000000e-04} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.611900e+00, -7.471300e-01, 1.176500e-01, 9.824300e-01, 1.847200e+00}, // SINR
           {9.577206e-01, 6.824866e-01, 2.027733e-01, 1.360000e-02, 3.000000e-04}    // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.627200e+00, -8.531800e-01, -7.915000e-02, 6.948700e-01, 1.468900e+00}, // SINR
           {9.713740e-01, 7.292857e-01, 2.748362e-01, 2.950000e-02, 3.000000e-04}     // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.700000e+00, -9.250000e-01, -1.500000e-01, 6.250000e-01, 1.400000e+00}, // SINR
           {9.696970e-01, 7.377168e-01, 2.440019e-01, 1.960000e-02, 2.000000e-04}     // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.662500e+00, -9.804500e-01, -2.984000e-01, 3.836500e-01, 1.065700e+00}, // SINR
           {9.608209e-01, 7.536550e-01, 3.162688e-01, 4.050000e-02, 1.000000e-03}     // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.473700e+00,
            -8.859800e-01,
            -2.982700e-01,
            2.894500e-01,
            8.771700e-01,
            1.460000e+00},                                                           // SINR
           {9.370504e-01, 7.398844e-01, 3.109681e-01, 4.970000e-02, 2.300000e-03, 0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.250000e+00, -1.062500e+00, 1.250000e-01, 1.312500e+00}, // SINR
           {9.980769e-01, 7.878086e-01, 6.260000e-02, 0}               // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.526300e+00, -9.385800e-01, -3.508600e-01, 2.368500e-01, 8.245700e-01}, // SINR
           {9.514925e-01, 7.338483e-01, 2.590021e-01, 2.540000e-02, 5.000000e-04}     // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.810000e+00,
            -1.302600e+00,
            -7.982100e-01,
            -2.938300e-01,
            2.105600e-01,
            7.149500e-01}, // SINR
           {9.865385e-01,
            8.836207e-01,
            5.908565e-01,
            1.825253e-01,
            2.070000e-02,
            6.000000e-04} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.909600e+00, -1.223400e+00, -5.371300e-01, 1.491000e-01, 8.353300e-01}, // SINR
           {9.932692e-01, 8.741497e-01, 3.501381e-01, 2.380000e-02, 1.000000e-04}     // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.315100e+00, -7.560400e-01, -1.969700e-01, 3.620900e-01, 9.211500e-01}, // SINR
           {9.415468e-01, 6.141304e-01, 1.345021e-01, 6.600000e-03, 1.000000e-04}     // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.432400e+00, -8.778500e-01, -3.233100e-01, 2.312300e-01, 7.857800e-01}, // SINR
           {9.718045e-01, 6.895161e-01, 1.740028e-01, 9.800000e-03, 1.000000e-04}     // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.214100e+00, -6.934300e-01, -1.727500e-01, 3.479200e-01, 8.685900e-01}, // SINR
           {9.113475e-01, 5.095000e-01, 8.130000e-02, 3.000000e-03, 0}                // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.447100e+00, -7.869500e-01, -1.268000e-01, 5.333500e-01, 1.193500e+00}, // SINR
           {9.790076e-01, 6.519231e-01, 7.820000e-02, 1.200000e-03, 0}                // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.053100e+00, -5.052200e-01, 4.265000e-02, 5.905300e-01, 1.138400e+00}, // SINR
           {9.306569e-01, 5.542763e-01, 9.936161e-02, 3.600000e-03, 0}               // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.500000e+00, -8.500000e-01, -2.000000e-01, 4.500000e-01, 1.100000e+00}, // SINR
           {9.961538e-01, 8.376623e-01, 2.265343e-01, 4.000000e-03, 0}                // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.400000e+00, -8.000000e-01, -2.000000e-01, 4.000000e-01, 1}, // SINR
           {9.951923e-01, 8.181090e-01, 2.001595e-01, 5.100000e-03, 0}     // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.200000e+00, -7.500000e-01, -3.000000e-01, 1.500000e-01, 6.000000e-01}, // SINR
           {9.846154e-01, 7.908951e-01, 2.663502e-01, 2.460000e-02, 5.000000e-04}     // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.500000e+00, -7.500000e-01, -3.750000e-01, 0, 7.500000e-01}, // SINR
           {9.961538e-01, 6.779101e-01, 2.434846e-01, 3.170000e-02, 0}     // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.200000e+00, -5.625000e-01, 7.500000e-02, 7.125000e-01, 1.350000e+00}, // SINR
           {9.903846e-01, 5.686384e-01, 2.780000e-02, 1.000000e-04, 0}               // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.322500e+00,
            -9.230700e-01,
            -5.236400e-01,
            -1.242100e-01,
            2.752200e-01,
            6.700000e-01},                                                           // SINR
           {9.923077e-01, 8.690878e-01, 4.392241e-01, 6.810000e-02, 2.600000e-03, 0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.350000e+00, -7.375000e-01, -1.250000e-01, 4.875000e-01}, // SINR
           {9.951923e-01, 5.438034e-01, 1.150000e-02, 0}                // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.300000e+00,
            -8.300000e-01,
            -6.000000e-01,
            -3.700000e-01,
            1.000000e-01,
            8.000000e-01},                                                           // SINR
           {9.913462e-01, 6.815160e-01, 3.010143e-01, 6.280000e-02, 2.000000e-04, 0} // BLER
       }},
      {736U, // SINR and BLER for CBS 736
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.300000e+00,
            -8.600000e-01,
            -6.425000e-01,
            -4.200000e-01,
            1.500000e-02,
            6.725000e-01},                                                           // SINR
           {9.961538e-01, 7.514620e-01, 3.904321e-01, 9.838642e-02, 4.000000e-04, 0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.309400e+00, -9.554500e-01, -6.014900e-01, -2.475400e-01, 1.064100e-01}, // SINR
           {9.980769e-01, 8.274194e-01, 3.073171e-01, 1.820000e-02, 3.000000e-04}      // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.354500e+00, -9.379000e-01, -5.212900e-01, -1.046900e-01, 3.119200e-01}, // SINR
           {9.961538e-01, 8.431373e-01, 1.936538e-01, 3.400000e-03, 0}                 // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.299000e+00, -9.238200e-01, -5.486300e-01, -1.734500e-01, 2.017300e-01}, // SINR
           {9.971154e-01, 8.256369e-01, 2.201134e-01, 4.800000e-03, 0}                 // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.299800e+00, -9.519700e-01, -6.041300e-01, -2.563000e-01, 9.153800e-02}, // SINR
           {9.971154e-01, 8.633333e-01, 2.568737e-01, 1.110000e-02, 3.000000e-04}      // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.312500e+00, -9.890400e-01, -6.655800e-01, -3.421200e-01, -1.865400e-02}, // SINR
           {1, 9.075704e-01, 3.805804e-01, 2.820000e-02, 4.000000e-04}                  // BLER
       }},
      {1224U, // SINR and BLER for CBS 1224
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.290400e+00, -9.274100e-01, -5.644300e-01, -2.014500e-01, 1.615400e-01}, // SINR
           {9.990385e-01, 8.590604e-01, 2.302632e-01, 3.300000e-03, 2.000000e-04}      // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.190000e+00, -9.097400e-01, -6.294900e-01, -3.492300e-01, -6.897400e-02}, // SINR
           {9.865385e-01, 8.392857e-01, 3.394772e-01, 3.550000e-02, 1.000000e-03}       // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.109900e+00, -8.397600e-01, -5.696300e-01, -2.994900e-01, -2.935900e-02}, // SINR
           {9.807692e-01, 7.265625e-01, 1.981947e-01, 1.280000e-02, 1.000000e-04}       // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.050000e+00, -7.900000e-01, -5.300000e-01, -2.700000e-01, -1.000000e-02}, // SINR
           {9.836538e-01, 7.657186e-01, 2.255824e-01, 1.300000e-02, 3.000000e-04}       // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.010400e+00, -7.605200e-01, -5.106500e-01, -2.607700e-01, -1.089700e-02}, // SINR
           {9.490741e-01, 5.627778e-01, 1.170930e-01, 5.900000e-03, 3.000000e-04}       // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.470500e+00,
            -1.028500e+00,
            -7.300000e-01,
            -5.864200e-01,
            -4.400000e-01,
            -1.443800e-01,
            2.976600e-01}, // SINR
           {1,
            9.531250e-01,
            5.265625e-01,
            2.274368e-01,
            5.900000e-02,
            8.000000e-04,
            1.000000e-04} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {-9.919200e-01,
            -7.852600e-01,
            -5.786100e-01,
            -3.719500e-01,
            -1.652900e-01,
            4.000000e-02}, // SINR
           {9.601852e-01,
            7.455882e-01,
            2.787611e-01,
            3.310000e-02,
            1.600000e-03,
            1.000000e-04} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.013100e+00, -7.387200e-01, -4.643400e-01, -1.899600e-01, 8.442300e-02}, // SINR
           {9.329710e-01, 4.936770e-01, 5.530000e-02, 1.200000e-03, 1.000000e-04}      // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.298000e+00, -9.479100e-01, -5.978100e-01, -2.477200e-01, 1.023700e-01}, // SINR
           {1, 9.181338e-01, 2.487648e-01, 3.600000e-03, 1.000000e-04}                 // BLER
       }},
      {2664U, // SINR and BLER for CBS 2664
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.329200e+00, -1.017400e+00, -7.056500e-01, -3.938700e-01, -8.210000e-02}, // SINR
           {1, 9.476103e-01, 3.867424e-01, 1.800000e-02, 2.000000e-04}                  // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.210500e+00, -8.776500e-01, -5.448000e-01, -2.119500e-01, 1.209000e-01}, // SINR
           {9.971154e-01, 8.015625e-01, 1.034664e-01, 6.000000e-04, 1.000000e-04}      // BLER
       }},
      {3240U, // SINR and BLER for CBS 3240
       MmWaveEesmErrorModel::DoubleTuple{
           {-9.714000e-01, -7.241300e-01, -4.768500e-01, -2.295700e-01, 1.770000e-02}, // SINR
           {9.694656e-01, 6.465736e-01, 1.323840e-01, 6.700000e-03, 3.000000e-04}      // BLER
       }},
      {3624U, // SINR and BLER for CBS 3624
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.126900e+00, -7.500300e-01, -3.731600e-01, 3.702500e-03}, // SINR
           {9.932692e-01, 4.829545e-01, 7.600000e-03, 0}                // BLER
       }}},
     {      // MCS 2
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.400000e+00,
            -7.000000e-01,
            0,
            7.000000e-01,
            1.400000e+00,
            2.100000e+00,
            2.800000e+00,
            3.500000e+00,
            4.200000e+00}, // SINR
           {9.778846e-01,
            8.869863e-01,
            6.810811e-01,
            4.048567e-01,
            1.455440e-01,
            3.000000e-02,
            4.300000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.200000e+00,
            -3.750000e-01,
            4.500000e-01,
            1.275000e+00,
            2.100000e+00,
            2.930000e+00,
            3.750000e+00,
            4.570000e+00}, // SINR
           {9.636194e-01,
            8.431373e-01,
            5.054781e-01,
            1.494372e-01,
            1.730000e-02,
            1.000000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.400000e+00,
            -7.000000e-01,
            0,
            7.000000e-01,
            1.400000e+00,
            2.100000e+00,
            2.800000e+00,
            3.500000e+00}, // SINR
           {9.818702e-01,
            8.977273e-01,
            6.293317e-01,
            2.745098e-01,
            5.740000e-02,
            5.200000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {-7.000000e-01,
            -2.500000e-02,
            6.500000e-01,
            1.325000e+00,
            2,
            2.680000e+00,
            3.350000e+00}, // SINR
           {9.142857e-01,
            6.692708e-01,
            2.827181e-01,
            6.090000e-02,
            4.900000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {-9.037900e-01, -1.300200e-01, 6.437500e-01, 1.417500e+00, 2.191300e+00}, // SINR
           {9.476103e-01, 6.586788e-01, 2.307692e-01, 2.700000e-02, 9.000000e-04}    // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.290000e+00,
            -5.981000e-01,
            9.245000e-02,
            7.830000e-01,
            1.473500e+00,
            2.164100e+00}, // SINR
           {9.846154e-01,
            8.792230e-01,
            5.234694e-01,
            1.500896e-01,
            1.380000e-02,
            7.000000e-04} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.047100e+00, -2.477000e-01, 5.517000e-01, 1.351100e+00, 2.150500e+00}, // SINR
           {9.568015e-01, 7.113260e-01, 2.070957e-01, 1.220000e-02, 1.000000e-04}    // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {-8.000000e-01,
            -2.500000e-01,
            3.000000e-01,
            8.500000e-01,
            1.400000e+00,
            1.950000e+00,
            2.500000e+00}, // SINR
           {9.447464e-01,
            7.266949e-01,
            3.791168e-01,
            9.113100e-02,
            1.050000e-02,
            4.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.100000e+00, -3.250000e-01, 4.500000e-01, 1.225000e+00, 2}, // SINR
           {9.761450e-01, 7.434971e-01, 2.107802e-01, 1.190000e-02, 0}    // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {-9.559100e-01,
            -3.424300e-01,
            2.710400e-01,
            8.845200e-01,
            1.498000e+00,
            2.110000e+00},                                                           // SINR
           {9.589552e-01, 7.500000e-01, 2.924312e-01, 3.650000e-02, 1.300000e-03, 0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.110000e+00,
            -6.029000e-01,
            -9.425000e-02,
            4.144000e-01,
            9.230500e-01,
            1.431700e+00}, // SINR
           {9.807692e-01,
            8.615772e-01,
            5.216049e-01,
            1.627267e-01,
            2.060000e-02,
            3.000000e-04} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {-8.529000e-01, -2.652300e-01, 3.224500e-01, 9.101200e-01, 1.497800e+00}, // SINR
           {9.522059e-01, 6.337065e-01, 1.775388e-01, 1.330000e-02, 1.000000e-04}    // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {-8.281500e-01, -1.514900e-01, 5.251800e-01, 1.201800e+00, 1.878500e+00}, // SINR
           {9.788462e-01, 6.591495e-01, 1.067416e-01, 1.100000e-03, 0}               // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {-4.634300e-01,
            -1.308400e-01,
            2.017600e-01,
            5.343500e-01,
            8.669400e-01,
            1.200000e+00,
            1.530000e+00,
            1.860000e+00}, // SINR
           {9.005282e-01,
            6.492347e-01,
            3.167506e-01,
            9.252850e-02,
            1.610000e-02,
            1.900000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {-6.572400e-01, -9.413000e-02, 4.689800e-01, 1.032100e+00, 1.595200e+00}, // SINR
           {9.583333e-01, 5.969626e-01, 1.112613e-01, 3.800000e-03, 0}               // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {-7.600000e-01,
            -3.709700e-01,
            1.864700e-02,
            4.082600e-01,
            7.978800e-01,
            1.187500e+00}, // SINR
           {9.744318e-01,
            8.460265e-01,
            4.960938e-01,
            1.437572e-01,
            1.570000e-02,
            9.000000e-04} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {-5.700000e-01,
            -2.821100e-01,
            5.297500e-03,
            2.927000e-01,
            5.801100e-01,
            8.675200e-01,
            1.150000e+00,
            1.440000e+00}, // SINR
           {9.388489e-01,
            7.774390e-01,
            4.815341e-01,
            1.969044e-01,
            4.560000e-02,
            6.100000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {-4.202000e-01, 5.120000e-02, 5.226000e-01, 9.940000e-01, 1.465400e+00}, // SINR
           {9.285714e-01, 5.210041e-01, 8.930000e-02, 3.900000e-03, 1.000000e-04}   // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.087300e-01,
            4.765200e-02,
            4.040300e-01,
            7.604200e-01,
            1.116800e+00,
            1.470000e+00,
            1.830000e+00}, // SINR
           {9.303571e-01,
            6.851604e-01,
            2.916667e-01,
            6.490000e-02,
            6.400000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {-8.000000e-01, -1.750000e-01, 4.500000e-01, 1.075000e+00, 1.700000e+00}, // SINR
           {9.961538e-01, 8.478618e-01, 2.200088e-01, 4.600000e-03, 0}               // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {-5.088500e-01, -5.423700e-02, 4.003800e-01, 8.549900e-01, 1.309600e+00}, // SINR
           {9.750000e-01, 7.081044e-01, 2.212214e-01, 1.670000e-02, 1.000000e-04}    // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {-4.850500e-01, -4.936200e-02, 3.863300e-01, 8.220100e-01, 1.257700e+00}, // SINR
           {9.782197e-01, 7.717066e-01, 2.643528e-01, 2.470000e-02, 1.000000e-03}    // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.218500e-01,
            1.388700e-02,
            3.496200e-01,
            6.853600e-01,
            1.021100e+00,
            1.360000e+00}, // SINR
           {9.166667e-01,
            6.503807e-01,
            2.535070e-01,
            4.170000e-02,
            2.800000e-03,
            1.000000e-04} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {-5.899000e-01, -1.539700e-01, 2.819500e-01, 7.178700e-01, 1.153800e+00}, // SINR
           {9.865385e-01, 7.434211e-01, 2.036062e-01, 1.040000e-02, 0}               // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {-5.281000e-01, -1.335700e-01, 2.609500e-01, 6.554800e-01, 1.050000e+00}, // SINR
           {9.829545e-01, 7.074022e-01, 1.710884e-01, 6.200000e-03, 0}               // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {-6.140700e-01, -2.240100e-01, 1.660400e-01, 5.561000e-01, 9.461500e-01}, // SINR
           {9.932692e-01, 7.772727e-01, 2.181542e-01, 8.900000e-03, 1.000000e-04}    // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {-5.025700e-01, -8.760200e-02, 3.273700e-01, 7.423300e-01, 1.157300e+00}, // SINR
           {9.734848e-01, 5.917431e-01, 6.190000e-02, 3.000000e-04, 0}               // BLER
       }},
      {888U, // SINR and BLER for CBS 888
       MmWaveEesmErrorModel::DoubleTuple{
           {-6.367800e-01, -2.154600e-01, 2.058600e-01, 6.271800e-01, 1.048500e+00}, // SINR
           {9.961538e-01, 7.914110e-01, 1.661726e-01, 2.800000e-03, 0}               // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {-8.928000e-01, -4.347000e-01, 2.341000e-02, 4.815100e-01, 9.396200e-01}, // SINR
           {1, 9.671053e-01, 4.970472e-01, 3.330000e-02, 1.000000e-04}               // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {-9.168100e-01, -4.799100e-01, -4.302000e-02, 3.938800e-01, 8.307700e-01}, // SINR
           {1, 9.913462e-01, 6.201220e-01, 5.680000e-02, 2.000000e-04}                // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {-1, -4.200000e-01, -1.250000e-01, 1.700000e-01, 7.500000e-01, 1.625000e+00}, // SINR
           {1, 9.642857e-01, 7.046703e-01, 2.220018e-01, 5.000000e-04, 0}                // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {-1, -5.242300e-01, -4.846000e-02, 4.273100e-01, 9.030800e-01}, // SINR
           {1, 9.932692e-01, 6.268473e-01, 3.080000e-02, 0}                // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.746200e-01, -1.121200e-01, 1.503800e-01, 4.128800e-01, 6.753800e-01}, // SINR
           {9.836538e-01, 7.529240e-01, 2.710129e-01, 3.170000e-02, 5.000000e-04}    // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {-8.000000e-01, -1.000000e-01, 6.000000e-01, 1.300000e+00}, // SINR
           {1, 8.924825e-01, 1.090000e-02, 0}                          // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.000000e-01, -4.000000e-02, 2.200000e-01, 4.800000e-01, 7.400000e-01}, // SINR
           {9.531250e-01, 6.621094e-01, 1.737259e-01, 1.230000e-02, 3.000000e-04}    // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.000000e-01, 8.000000e-02, 2.625000e-01, 4.500000e-01, 8.250000e-01}, // SINR
           {9.476103e-01, 3.513231e-01, 9.430533e-02, 1.080000e-02, 0}              // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {-8.000000e-01, -2.800000e-01, -2.500000e-02, 2.300000e-01, 7.500000e-01}, // SINR
           {1, 9.489051e-01, 5.842890e-01, 1.237599e-01, 0}                           // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.330800e-01, -8.830000e-03, 2.154200e-01, 4.396700e-01, 6.639200e-01}, // SINR
           {9.255319e-01, 5.816210e-01, 1.502994e-01, 1.620000e-02, 2.000000e-04}    // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {-4.707700e-01, -1.837000e-01, 1.033800e-01, 3.904500e-01, 6.775300e-01}, // SINR
           {9.875000e-01, 8.015625e-01, 2.552817e-01, 1.430000e-02, 2.000000e-04}    // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.884600e-01, -1.372200e-02, 2.610200e-01, 5.357500e-01, 8.104900e-01}, // SINR
           {9.704198e-01, 5.924419e-01, 1.080934e-01, 3.400000e-03, 1.000000e-04}    // BLER
       }},
      {2664U, // SINR and BLER for CBS 2664
       MmWaveEesmErrorModel::DoubleTuple{
           {-9.526700e-01, -4.898700e-01, -2.707500e-02, 4.357200e-01, 8.985200e-01}, // SINR
           {1, 9.951923e-01, 5.666667e-01, 8.000000e-03, 0}                           // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {-7.000000e-01,
            -2.250000e-01,
            9.000000e-02,
            2.500000e-01,
            4.100000e-01,
            7.250000e-01,
            1.200000e+00}, // SINR
           {1,
            9.104610e-01,
            2.964706e-01,
            7.200000e-02,
            8.400000e-03,
            3.000000e-04,
            2.000000e-04} // BLER
       }},
      {3368U, // SINR and BLER for CBS 3368
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.562800e-01,
            -1.000000e-02,
            1.676400e-01,
            3.400000e-01,
            6.915600e-01,
            1.215500e+00},                                                           // SINR
           {9.980769e-01, 7.898773e-01, 3.928019e-01, 9.919154e-02, 1.000000e-04, 0} // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {-7.000000e-01,
            -2.700000e-01,
            -5.000000e-02,
            1.700000e-01,
            6.000000e-01,
            1.250000e+00},                                                // SINR
           {1, 9.734848e-01, 6.688482e-01, 1.921756e-01, 3.000000e-04, 0} // BLER
       }}},
     {      // MCS 3
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {-5.000000e-01,
            5.000000e-01,
            1.500000e+00,
            2.500000e+00,
            3.500000e+00,
            4.500000e+00,
            5.500000e+00,
            6.500000e+00}, // SINR
           {9.817308e-01,
            8.716443e-01,
            5.649780e-01,
            2.005582e-01,
            2.520000e-02,
            1.000000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {1.000000e-01,
            7.750000e-01,
            1.450000e+00,
            2.125000e+00,
            2.800000e+00,
            3.470000e+00,
            4.150000e+00,
            4.830000e+00}, // SINR
           {9.223214e-01,
            7.725904e-01,
            4.965953e-01,
            2.151709e-01,
            5.250000e-02,
            9.600000e-03,
            1.300000e-03,
            0} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {-5.000000e-01,
            3.500000e-01,
            1.200000e+00,
            2.050000e+00,
            2.900000e+00,
            3.750000e+00,
            4.600000e+00}, // SINR
           {9.788462e-01,
            8.567881e-01,
            5.069721e-01,
            1.550185e-01,
            1.660000e-02,
            6.000000e-04,
            0} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {-2.000000e-01,
            4.250000e-01,
            1.050000e+00,
            1.675000e+00,
            2.300000e+00,
            2.930000e+00,
            3.550000e+00,
            4.180000e+00,
            4.800000e+00}, // SINR
           {9.558271e-01,
            8.245192e-01,
            5.540393e-01,
            2.188589e-01,
            4.910000e-02,
            6.600000e-03,
            6.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.000000e-01,
            6.000000e-01,
            1.300000e+00,
            2,
            2.700000e+00,
            3.400000e+00,
            4.100000e+00}, // SINR
           {9.583333e-01,
            7.881098e-01,
            4.366438e-01,
            1.162953e-01,
            1.470000e-02,
            9.000000e-04,
            0} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.000000e-01,
            6.000000e-01,
            1.300000e+00,
            2,
            2.700000e+00,
            3.400000e+00,
            4.100000e+00}, // SINR
           {9.601852e-01,
            7.700893e-01,
            3.506944e-01,
            7.810000e-02,
            6.700000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.417400e-01,
            5.573900e-01,
            1.256500e+00,
            1.955700e+00,
            2.654800e+00,
            3.350000e+00,
            4.050000e+00}, // SINR
           {9.542910e-01,
            7.617647e-01,
            3.543994e-01,
            7.040000e-02,
            6.400000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {-1.509200e-01,
            5.474600e-01,
            1.245800e+00,
            1.944200e+00,
            2.642600e+00,
            3.340000e+00,
            4.040000e+00}, // SINR
           {9.780534e-01,
            8.132911e-01,
            3.928571e-01,
            8.690000e-02,
            8.600000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {6.247500e-02, 8.445100e-01, 1.626500e+00, 2.408600e+00, 3.190600e+00}, // SINR
           {9.343525e-01, 5.786199e-01, 1.388122e-01, 8.200000e-03, 1.000000e-04}  // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {-8.323800e-02, 5.500700e-01, 1.183400e+00, 1.816700e+00, 2.450000e+00}, // SINR
           {9.416058e-01, 7.001366e-01, 2.736413e-01, 3.130000e-02, 1.000000e-03}   // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {-8.586200e-02, 6.304500e-01, 1.346800e+00, 2.063100e+00, 2.779400e+00}, // SINR
           {9.661654e-01, 7.321429e-01, 2.393466e-01, 1.980000e-02, 4.000000e-04}   // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {-3.077500e-02, 6.449900e-01, 1.320800e+00, 1.996500e+00, 2.672300e+00}, // SINR
           {9.512868e-01, 6.393750e-01, 1.471704e-01, 6.200000e-03, 2.000000e-04}   // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.480000e-01, 7.042700e-01, 1.260500e+00, 1.816800e+00, 2.373100e+00}, // SINR
           {9.617537e-01, 7.005495e-01, 2.184783e-01, 2.050000e-02, 2.000000e-04}  // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {2.695700e-01, 9.349800e-01, 1.600400e+00, 2.265800e+00, 2.931200e+00}, // SINR
           {9.199640e-01, 4.240772e-01, 3.880000e-02, 1.000000e-04, 0}             // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {2.155800e-01, 7.539900e-01, 1.292400e+00, 1.830800e+00, 2.369200e+00}, // SINR
           {9.489051e-01, 6.010514e-01, 1.472222e-01, 7.500000e-03, 1.000000e-04}  // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {1.169100e-01, 6.617300e-01, 1.206600e+00, 1.751400e+00, 2.296200e+00}, // SINR
           {9.630682e-01, 6.804813e-01, 1.684492e-01, 8.900000e-03, 1.000000e-04}  // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.975700e-01, 7.094000e-01, 1.221200e+00, 1.733100e+00, 2.244900e+00}, // SINR
           {9.434307e-01, 5.644444e-01, 1.238927e-01, 6.200000e-03, 1.000000e-04}  // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {2.552300e-01, 7.215000e-01, 1.187800e+00, 1.654000e+00, 2.120300e+00}, // SINR
           {9.303571e-01, 5.358650e-01, 1.079348e-01, 6.000000e-03, 1.000000e-04}  // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {3.300000e-01,
            7.001500e-01,
            1.065500e+00,
            1.430900e+00,
            1.796200e+00,
            2.161600e+00},                                                           // SINR
           {9.276786e-01, 6.147837e-01, 2.027464e-01, 2.700000e-02, 9.000000e-04, 0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.502900e-01, 6.354700e-01, 1.120600e+00, 1.605800e+00, 2.091000e+00}, // SINR
           {9.678030e-01, 6.686198e-01, 1.406250e-01, 6.200000e-03, 1.000000e-04}  // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {2.330100e-01, 6.846800e-01, 1.136400e+00, 1.588000e+00, 2.039700e+00}, // SINR
           {9.567669e-01, 6.078199e-01, 1.271465e-01, 5.200000e-03, 0}             // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {3.708900e-01, 8.587900e-01, 1.346700e+00, 1.834600e+00, 2.322500e+00}, // SINR
           {9.680451e-01, 6.712963e-01, 1.789530e-01, 8.700000e-03, 1.000000e-04}  // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {4.190100e-01, 8.814600e-01, 1.343900e+00, 1.806400e+00, 2.268800e+00}, // SINR
           {9.608209e-01, 6.195388e-01, 1.512605e-01, 8.300000e-03, 0}             // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {4.136600e-01, 8.639900e-01, 1.314300e+00, 1.764700e+00, 2.215000e+00}, // SINR
           {9.704198e-01, 6.536990e-01, 1.299325e-01, 5.800000e-03, 0}             // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {4.564400e-01, 8.692100e-01, 1.282000e+00, 1.694700e+00, 2.107500e+00}, // SINR
           {9.730769e-01, 6.666667e-01, 1.396321e-01, 5.500000e-03, 0}             // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {4.836300e-01, 8.627200e-01, 1.241800e+00, 1.620900e+00, 2},           // SINR
           {9.782197e-01, 7.046703e-01, 1.964006e-01, 1.060000e-02, 3.000000e-04} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {5.477000e-01, 8.839000e-01, 1.220100e+00, 1.556300e+00, 1.892500e+00}, // SINR
           {9.388686e-01, 6.078199e-01, 1.415917e-01, 5.800000e-03, 0}             // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {5.130000e-01, 8.310000e-01, 1.149000e+00, 1.467000e+00, 1.785000e+00}, // SINR
           {9.642857e-01, 7.015027e-01, 1.911204e-01, 1.590000e-02, 2.000000e-04}  // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {5.546000e-01, 8.534700e-01, 1.152300e+00, 1.451200e+00, 1.750100e+00}, // SINR
           {9.673507e-01, 6.983696e-01, 2.283394e-01, 2.030000e-02, 4.000000e-04}  // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {5.000000e-01, 8.423700e-01, 1.184700e+00, 1.527100e+00, 1.869500e+00}, // SINR
           {9.836538e-01, 7.294034e-01, 1.663360e-01, 5.800000e-03, 0}             // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {5.787800e-01, 9.983600e-01, 1.417900e+00, 1.837500e+00, 2.257100e+00}, // SINR
           {9.503676e-01, 4.021226e-01, 1.220000e-02, 1.000000e-04, 0}             // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {5.625000e-01, 9.054200e-01, 1.248300e+00, 1.591300e+00, 1.934200e+00}, // SINR
           {9.801136e-01, 6.939189e-01, 1.658940e-01, 5.400000e-03, 0}             // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {5.805100e-01, 8.602600e-01, 1.140000e+00, 1.419800e+00, 1.699500e+00}, // SINR
           {9.788462e-01, 7.300000e-01, 2.647059e-01, 2.510000e-02, 7.000000e-04}  // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {6.551300e-01, 9.250000e-01, 1.194900e+00, 1.464700e+00, 1.734600e+00}, // SINR
           {9.577068e-01, 6.311576e-01, 1.730110e-01, 1.370000e-02, 2.000000e-04}  // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {7.100000e-01, 9.700000e-01, 1.230000e+00, 1.490000e+00, 1.750000e+00}, // SINR
           {9.148936e-01, 5.348101e-01, 9.968880e-02, 3.500000e-03, 0}             // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {4.950000e-01, 7.898000e-01, 1.084600e+00, 1.379400e+00, 1.674200e+00}, // SINR
           {9.980769e-01, 8.412829e-01, 2.821508e-01, 1.630000e-02, 1.000000e-04}  // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {7.605100e-01,
            9.718300e-01,
            1.183200e+00,
            1.394500e+00,
            1.605800e+00,
            1.820000e+00},                                                           // SINR
           {9.836538e-01, 8.274194e-01, 4.138072e-01, 8.466773e-02, 5.200000e-03, 0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {5.257700e-01,
            7.813800e-01,
            1.037000e+00,
            1.292600e+00,
            1.548200e+00,
            1.800000e+00},                                                           // SINR
           {9.971154e-01, 8.715986e-01, 4.158416e-01, 5.410000e-02, 1.200000e-03, 0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {6.214000e-01, 9.021000e-01, 1.182800e+00, 1.463500e+00, 1.744200e+00}, // SINR
           {9.809160e-01, 7.039835e-01, 1.721956e-01, 6.500000e-03, 0}             // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {5.420000e-01, 8.850000e-01, 1.228000e+00, 1.571000e+00, 1.914000e+00}, // SINR
           {9.932692e-01, 6.945946e-01, 7.820000e-02, 3.000000e-04, 0}             // BLER
       }},
      {2728U, // SINR and BLER for CBS 2728
       MmWaveEesmErrorModel::DoubleTuple{
           {5.874000e-01, 8.522300e-01, 1.117000e+00, 1.381900e+00, 1.646700e+00}, // SINR
           {9.923077e-01, 8.565436e-01, 3.092752e-01, 1.700000e-02, 1.000000e-04}  // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {5.145500e-01, 9.101400e-01, 1.305700e+00, 1.701300e+00}, // SINR
           {1, 6.492347e-01, 2.510000e-02, 0}                        // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {7.646800e-01, 1.036800e+00, 1.308900e+00, 1.581000e+00, 1.853100e+00}, // SINR
           {9.356884e-01, 4.092742e-01, 2.650000e-02, 2.000000e-04, 0}             // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {5.736200e-01, 8.934200e-01, 1.213200e+00, 1.533000e+00, 1.852800e+00}, // SINR
           {9.942308e-01, 7.250000e-01, 9.064268e-02, 3.000000e-04, 0}             // BLER
       }}},
     {      // MCS 4
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {1,
            1.600000e+00,
            2.200000e+00,
            2.800000e+00,
            3.400000e+00,
            4,
            4.600000e+00,
            5.200000e+00,
            5.800000e+00,
            6.400000e+00,
            7}, // SINR
           {9.379496e-01,
            8.504902e-01,
            6.915323e-01,
            4.784644e-01,
            2.666139e-01,
            1.082969e-01,
            3.150000e-02,
            7.600000e-03,
            1.000000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {6.531000e-01,
            1.265400e+00,
            1.877700e+00,
            2.490000e+00,
            3.102300e+00,
            3.710000e+00,
            4.330000e+00,
            4.940000e+00,
            5.550000e+00}, // SINR
           {9.293478e-01,
            7.978395e-01,
            5.839041e-01,
            3.187814e-01,
            1.176195e-01,
            2.700000e-02,
            3.500000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {4.800000e-01,
            9.961000e-01,
            1.516900e+00,
            2.037700e+00,
            2.558600e+00,
            3.079400e+00,
            3.600000e+00,
            4.120000e+00,
            4.640000e+00,
            5.160000e+00,
            5.680000e+00}, // SINR
           {9.564815e-01,
            8.682886e-01,
            7.192737e-01,
            4.917636e-01,
            2.611746e-01,
            1.012949e-01,
            2.400000e-02,
            4.100000e-03,
            6.000000e-04,
            3.000000e-04,
            0} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {6.000000e-01,
            1.225000e+00,
            1.850000e+00,
            2.475000e+00,
            3.100000e+00,
            3.730000e+00,
            4.350000e+00,
            4.980000e+00,
            5.600000e+00}, // SINR
           {9.522059e-01,
            8.243671e-01,
            5.728700e-01,
            2.658562e-01,
            7.170000e-02,
            1.090000e-02,
            7.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {5.000000e-01,
            1.275000e+00,
            2.050000e+00,
            2.825000e+00,
            3.600000e+00,
            4.380000e+00,
            5.150000e+00}, // SINR
           {9.723282e-01,
            8.117089e-01,
            4.744424e-01,
            1.267659e-01,
            1.370000e-02,
            3.000000e-04,
            0} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {7.407700e-01, 1.637300e+00, 2.533800e+00, 3.430400e+00, 4.326900e+00}, // SINR
           {9.555556e-01, 6.792328e-01, 1.980315e-01, 1.410000e-02, 4.000000e-04}  // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {8.217700e-01, 1.604900e+00, 2.388100e+00, 3.171200e+00, 3.954400e+00}, // SINR
           {9.014085e-01, 5.777027e-01, 1.597661e-01, 1.360000e-02, 3.000000e-04}  // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {4.386000e-01, 1.331600e+00, 2.224700e+00, 3.117800e+00, 4.010800e+00}, // SINR
           {9.782197e-01, 7.434211e-01, 2.240691e-01, 1.280000e-02, 1.000000e-04}  // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {3.870000e-01, 1.179400e+00, 1.971800e+00, 2.764100e+00, 3.556500e+00}, // SINR
           {9.826923e-01, 8.209677e-01, 3.378016e-01, 4.010000e-02, 9.000000e-04}  // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {5.546200e-01, 1.298500e+00, 2.042300e+00, 2.786200e+00, 3.530000e+00}, // SINR
           {9.617537e-01, 7.240169e-01, 2.379717e-01, 1.790000e-02, 6.000000e-04}  // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {5.828800e-01, 1.313000e+00, 2.043200e+00, 2.773300e+00, 3.503500e+00}, // SINR
           {9.564815e-01, 7.094972e-01, 2.182093e-01, 1.490000e-02, 4.000000e-04}  // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {1.888300e-01, 1.010800e+00, 1.832900e+00, 2.654900e+00, 3.476900e+00}, // SINR
           {9.951923e-01, 8.775338e-01, 3.446866e-01, 1.840000e-02, 2.000000e-04}  // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {8.031500e-01, 1.465000e+00, 2.126800e+00, 2.788600e+00, 3.450400e+00}, // SINR
           {9.671053e-01, 6.752646e-01, 1.661162e-01, 1.220000e-02, 2.000000e-04}  // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {9.113000e-01, 1.539400e+00, 2.167600e+00, 2.795700e+00, 3.423800e+00}, // SINR
           {9.525547e-01, 6.419598e-01, 1.426337e-01, 9.100000e-03, 3.000000e-04}  // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {1.005300e+00, 1.603300e+00, 2.201300e+00, 2.799300e+00, 3.397300e+00}, // SINR
           {9.262590e-01, 5.268595e-01, 9.710912e-02, 4.800000e-03, 0}             // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {9.621000e-01, 1.564300e+00, 2.166500e+00, 2.768600e+00, 3.370800e+00}, // SINR
           {9.485294e-01, 5.703829e-01, 1.068841e-01, 6.400000e-03, 2.000000e-04}  // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {9.607000e-01, 1.549900e+00, 2.139200e+00, 2.728500e+00, 3.317700e+00}, // SINR
           {9.411232e-01, 5.688889e-01, 9.712084e-02, 2.700000e-03, 0}             // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {9.645000e-01, 1.539500e+00, 2.114500e+00, 2.689600e+00, 3.264600e+00}, // SINR
           {9.393116e-01, 5.152439e-01, 7.650000e-02, 3.400000e-03, 0}             // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {8.037500e-01, 1.320600e+00, 1.837500e+00, 2.354300e+00, 2.871200e+00}, // SINR
           {9.836538e-01, 7.349138e-01, 2.156947e-01, 1.750000e-02, 3.000000e-04}  // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {5.414500e-01, 1.195700e+00, 1.850000e+00, 2.504200e+00, 3.158500e+00}, // SINR
           {9.971154e-01, 8.316993e-01, 1.835766e-01, 3.000000e-03, 0}             // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {9.441000e-01, 1.484400e+00, 2.024800e+00, 2.565100e+00, 3.105400e+00}, // SINR
           {9.605263e-01, 5.427350e-01, 6.480000e-02, 1.900000e-03, 0}             // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {8.758500e-01, 1.336700e+00, 1.797500e+00, 2.258400e+00, 2.719200e+00}, // SINR
           {9.770992e-01, 7.122905e-01, 2.114250e-01, 1.750000e-02, 3.000000e-04}  // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {8.300000e-01, 1.297700e+00, 1.765400e+00, 2.233200e+00, 2.700900e+00}, // SINR
           {9.846154e-01, 7.385057e-01, 1.952399e-01, 1.120000e-02, 0}             // BLER
       }},
      {480U, // SINR and BLER for CBS 480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.011600e+00, 1.495200e+00, 1.978900e+00, 2.462600e+00, 2.946200e+00}, // SINR
           {9.636194e-01, 5.745516e-01, 8.710000e-02, 2.800000e-03, 0}             // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {1.184500e+00, 1.598400e+00, 2.012200e+00, 2.426100e+00, 2.840000e+00}, // SINR
           {9.763258e-01, 7.377168e-01, 2.084020e-01, 1.330000e-02, 0}             // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {6.791000e-01, 1.192800e+00, 1.706500e+00, 2.220100e+00, 2.733800e+00}, // SINR
           {1, 9.685185e-01, 5.477468e-01, 4.500000e-02, 1.000000e-04}             // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.146900e+00, 1.517100e+00, 1.887300e+00, 2.257500e+00, 2.627700e+00}, // SINR
           {9.817308e-01, 7.793675e-01, 2.706989e-01, 2.100000e-02, 7.000000e-04}  // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.375000e+00, 1.738800e+00, 2.102600e+00, 2.466500e+00, 2.830300e+00}, // SINR
           {9.181655e-01, 4.824811e-01, 7.190000e-02, 1.700000e-03, 0}             // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {1.199800e+00, 1.579600e+00, 1.959500e+00, 2.339300e+00, 2.719200e+00}, // SINR
           {9.828244e-01, 7.092541e-01, 1.799431e-01, 8.200000e-03, 1.000000e-04}  // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {1.250000e+00, 1.589600e+00, 1.929100e+00, 2.268700e+00, 2.608200e+00}, // SINR
           {9.798077e-01, 6.929348e-01, 1.811777e-01, 1.030000e-02, 0}             // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {1.320800e+00, 1.614900e+00, 1.909000e+00, 2.203100e+00, 2.497200e+00}, // SINR
           {9.671053e-01, 6.908602e-01, 2.208333e-01, 2.150000e-02, 2.000000e-04}  // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {1.250000e+00, 1.606300e+00, 1.962700e+00, 2.319000e+00, 2.675400e+00}, // SINR
           {9.895038e-01, 7.152778e-01, 1.662814e-01, 4.900000e-03, 0}             // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {1.325600e+00, 1.605100e+00, 1.884600e+00, 2.164100e+00, 2.443600e+00}, // SINR
           {9.751908e-01, 7.104167e-01, 2.205624e-01, 2.020000e-02, 4.000000e-04}  // BLER
       }},
      {1480U, // SINR and BLER for CBS 1480
       MmWaveEesmErrorModel::DoubleTuple{
           {1.402600e+00, 1.672300e+00, 1.942100e+00, 2.211800e+00, 2.481500e+00}, // SINR
           {9.770992e-01, 7.265625e-01, 2.706545e-01, 2.460000e-02, 6.000000e-04}  // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.460000e+00, 1.720000e+00, 1.980000e+00, 2.240000e+00, 2.500000e+00}, // SINR
           {9.481481e-01, 6.305419e-01, 1.713847e-01, 1.480000e-02, 2.000000e-04}  // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {9.979000e-01, 1.435600e+00, 1.873300e+00, 2.311000e+00, 2.748700e+00}, // SINR
           {1, 9.605263e-01, 3.123449e-01, 3.600000e-03, 0}                        // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {1.516400e+00, 1.809700e+00, 2.103100e+00, 2.396400e+00, 2.689800e+00}, // SINR
           {9.029720e-01, 4.065495e-01, 3.870000e-02, 4.000000e-04, 0}             // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {1.284600e+00, 1.627600e+00, 1.970700e+00, 2.313700e+00, 2.656700e+00}, // SINR
           {9.923077e-01, 6.844920e-01, 8.950000e-02, 1.000000e-03, 0}             // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {1.273800e+00, 1.544600e+00, 1.815400e+00, 2.086200e+00, 2.357000e+00}, // SINR
           {9.942308e-01, 8.221154e-01, 2.941005e-01, 2.350000e-02, 3.000000e-04}  // BLER
       }},
      {2408U, // SINR and BLER for CBS 2408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.243600e+00, 1.587400e+00, 1.931200e+00, 2.274900e+00, 2.618700e+00}, // SINR
           {1, 8.317308e-01, 1.756285e-01, 2.700000e-03, 0}                        // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {1.472800e+00, 1.716700e+00, 1.960600e+00, 2.204500e+00, 2.448400e+00}, // SINR
           {9.626866e-01, 6.530612e-01, 1.669419e-01, 1.170000e-02, 2.000000e-04}  // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.373700e+00, 1.703100e+00, 2.032500e+00, 2.361900e+00, 2.691300e+00}, // SINR
           {9.788462e-01, 5.652902e-01, 3.720000e-02, 2.000000e-04, 0}             // BLER
       }},
      {3368U, // SINR and BLER for CBS 3368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.166800e+00, 1.524500e+00, 1.882200e+00, 2.239900e+00, 2.597600e+00}, // SINR
           {1, 9.325540e-01, 2.862812e-01, 2.800000e-03, 0}                        // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {9.700000e-01, 1.555000e+00, 2.140000e+00, 2.725000e+00}, // SINR
           {1, 8.844178e-01, 9.300000e-03, 0}                        // BLER
       }}},
     {      // MCS 5
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {1.600000e+00,
            2.200000e+00,
            2.800000e+00,
            3.400000e+00,
            4,
            4.600000e+00,
            5.200000e+00,
            5.800000e+00,
            6.400000e+00,
            7,
            7.600000e+00}, // SINR
           {9.142857e-01,
            8.352273e-01,
            6.848118e-01,
            4.675926e-01,
            2.560976e-01,
            1.058587e-01,
            3.380000e-02,
            8.300000e-03,
            1.700000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {1.700000e+00,
            2.550000e+00,
            3.400000e+00,
            4.250000e+00,
            5.100000e+00,
            5.950000e+00,
            6.800000e+00,
            7.650000e+00}, // SINR
           {9.196429e-01,
            7.028689e-01,
            3.757440e-01,
            1.096760e-01,
            1.750000e-02,
            1.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {1.700000e+00,
            2.375000e+00,
            3.050000e+00,
            3.725000e+00,
            4.400000e+00,
            5.080000e+00,
            5.750000e+00,
            6.430000e+00,
            7.100000e+00}, // SINR
           {9.420290e-01,
            8.085443e-01,
            5.835253e-01,
            3.056569e-01,
            1.005524e-01,
            1.920000e-02,
            2.200000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {1.800000e+00,
            2.175000e+00,
            2.550000e+00,
            2.925000e+00,
            3.300000e+00,
            3.680000e+00,
            4.050000e+00,
            4.430000e+00,
            4.800000e+00,
            5.180000e+00,
            5.550000e+00,
            5.920000e+00,
            6.300000e+00}, // SINR
           {9.356884e-01,
            8.518212e-01,
            7.363506e-01,
            5.728700e-01,
            3.888462e-01,
            2.328386e-01,
            1.236453e-01,
            5.530000e-02,
            1.940000e-02,
            4.200000e-03,
            1.200000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {1.800000e+00,
            2.250000e+00,
            2.700000e+00,
            3.150000e+00,
            3.600000e+00,
            4.050000e+00,
            4.500000e+00,
            4.950000e+00,
            5.400000e+00,
            5.850000e+00,
            6.300000e+00}, // SINR
           {9.148936e-01,
            8.078125e-01,
            6.111779e-01,
            3.971273e-01,
            2.058101e-01,
            7.980000e-02,
            2.560000e-02,
            6.200000e-03,
            1.000000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {1.580000e+00,
            1.860000e+00,
            2.140400e+00,
            2.420400e+00,
            2.700300e+00,
            2.980300e+00,
            3.260200e+00,
            3.540000e+00,
            3.820000e+00,
            4.100000e+00,
            4.380000e+00,
            4.660000e+00,
            4.940000e+00,
            5.220000e+00,
            5.500000e+00,
            5.780000e+00}, // SINR
           {9.457721e-01,
            8.911565e-01,
            7.898773e-01,
            6.688482e-01,
            5.395570e-01,
            3.891871e-01,
            2.502495e-01,
            1.451100e-01,
            7.690000e-02,
            3.370000e-02,
            1.430000e-02,
            5.200000e-03,
            1.100000e-03,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {1.460000e+00,
            1.820000e+00,
            2.178500e+00,
            2.535300e+00,
            2.892100e+00,
            3.248900e+00,
            3.605700e+00,
            3.960000e+00,
            4.320000e+00,
            4.680000e+00,
            5.030000e+00,
            5.390000e+00,
            5.750000e+00}, // SINR
           {9.494485e-01,
            8.648649e-01,
            7.449422e-01,
            5.650000e-01,
            3.670749e-01,
            1.847426e-01,
            7.830000e-02,
            2.670000e-02,
            7.400000e-03,
            1.900000e-03,
            6.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {1.250000e+00, 2.187500e+00, 3.125000e+00, 4.062500e+00, 5},           // SINR
           {9.865385e-01, 8.188291e-01, 3.282861e-01, 3.380000e-02, 1.000000e-03} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {1.610000e+00,
            1.880000e+00,
            2.150000e+00,
            2.416200e+00,
            2.682500e+00,
            2.948700e+00,
            3.215000e+00,
            3.480000e+00,
            3.750000e+00,
            4.010000e+00,
            4.280000e+00,
            4.550000e+00,
            4.810000e+00,
            5.080000e+00,
            5.350000e+00}, // SINR
           {9.438406e-01,
            8.862069e-01,
            7.998466e-01,
            6.730263e-01,
            5.269710e-01,
            3.466530e-01,
            2.063525e-01,
            1.101243e-01,
            4.620000e-02,
            1.940000e-02,
            7.400000e-03,
            1.700000e-03,
            6.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.069600e+00, 1.954100e+00, 2.838500e+00, 3.723000e+00, 4.607500e+00}, // SINR
           {9.894231e-01, 8.347039e-01, 3.085366e-01, 1.990000e-02, 1.000000e-04}  // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {1.230000e+00, 2.072500e+00, 2.915000e+00, 3.757500e+00, 4.600000e+00}, // SINR
           {9.799618e-01, 7.449422e-01, 2.270270e-01, 1.290000e-02, 1.000000e-04}  // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {1.700000e+00, 2.325000e+00, 2.950000e+00, 3.575000e+00, 4.200000e+00}, // SINR
           {9.285714e-01, 6.305970e-01, 2.157534e-01, 2.450000e-02, 7.000000e-04}  // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.480000e+00,
            2.089300e+00,
            2.698300e+00,
            3.307300e+00,
            3.916300e+00,
            4.525300e+00},                                                           // SINR
           {9.799618e-01, 7.544118e-01, 2.952687e-01, 3.560000e-02, 1.300000e-03, 0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {1.780000e+00,
            2.254500e+00,
            2.728100e+00,
            3.201700e+00,
            3.675300e+00,
            4.148900e+00},                                                           // SINR
           {9.384058e-01, 6.798942e-01, 2.874714e-01, 5.550000e-02, 5.100000e-03, 0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {1.740000e+00,
            2.216200e+00,
            2.692900e+00,
            3.169500e+00,
            3.646100e+00,
            4.122700e+00},                                                           // SINR
           {9.439338e-01, 6.881720e-01, 2.771382e-01, 5.140000e-02, 4.400000e-03, 0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {1.780000e+00,
            2.315500e+00,
            2.847400e+00,
            3.379300e+00,
            3.911200e+00,
            4.443100e+00},                                                           // SINR
           {9.438406e-01, 6.407828e-01, 1.840278e-01, 1.820000e-02, 8.000000e-04, 0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.800000e+00,
            2.245000e+00,
            2.694800e+00,
            3.144600e+00,
            3.594300e+00,
            4.044100e+00},                                                           // SINR
           {9.142857e-01, 6.317402e-01, 2.434971e-01, 3.930000e-02, 3.000000e-03, 0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.840000e+00,
            2.270100e+00,
            2.700500e+00,
            3.130900e+00,
            3.561300e+00,
            3.991700e+00},                                                           // SINR
           {9.128521e-01, 6.219807e-01, 2.086777e-01, 3.230000e-02, 1.700000e-03, 0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {1.620000e+00,
            1.950000e+00,
            2.281300e+00,
            2.611000e+00,
            2.940600e+00,
            3.270300e+00,
            3.600000e+00}, // SINR
           {9.826923e-01,
            8.862069e-01,
            6.042654e-01,
            2.581967e-01,
            6.660000e-02,
            9.900000e-03,
            5.000000e-04} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.760000e+00,
            1.980000e+00,
            2.200000e+00,
            2.425000e+00,
            2.650000e+00,
            2.875000e+00,
            3.100000e+00,
            3.330000e+00,
            3.550000e+00,
            3.780000e+00}, // SINR
           {9.580292e-01,
            8.809932e-01,
            6.908602e-01,
            4.544643e-01,
            2.365819e-01,
            8.580000e-02,
            2.430000e-02,
            4.400000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {1.700000e+00,
            1.950000e+00,
            2.200000e+00,
            2.450000e+00,
            2.700000e+00,
            2.950000e+00,
            3.200000e+00,
            3.450000e+00,
            3.700000e+00}, // SINR
           {9.500000e-01,
            8.544408e-01,
            6.100478e-01,
            3.252584e-01,
            1.146024e-01,
            2.730000e-02,
            5.400000e-03,
            7.000000e-04,
            1.000000e-04} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {1.800000e+00,
            2.050000e+00,
            2.300000e+00,
            2.550000e+00,
            2.800000e+00,
            3.050000e+00,
            3.300000e+00,
            3.550000e+00}, // SINR
           {9.503676e-01,
            7.975460e-01,
            5.193878e-01,
            2.318140e-01,
            7.480000e-02,
            1.440000e-02,
            1.900000e-03,
            2.000000e-04} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.600000e+00, 2.200000e+00, 2.800000e+00, 3.400000e+00, 4}, // SINR
           {9.836538e-01, 6.274752e-01, 6.540000e-02, 7.000000e-04, 0}  // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.600000e+00, 2.275000e+00, 2.950000e+00, 3.625000e+00}, // SINR
           {9.836538e-01, 4.880268e-01, 1.060000e-02, 0}             // BLER
       }},
      {608U, // SINR and BLER for CBS 608
       MmWaveEesmErrorModel::DoubleTuple{
           {1.960000e+00,
            2.230000e+00,
            2.497500e+00,
            2.765000e+00,
            3.032500e+00,
            3.300000e+00,
            3.570000e+00}, // SINR
           {9.592593e-01,
            8.059006e-01,
            4.605978e-01,
            1.563670e-01,
            2.690000e-02,
            3.200000e-03,
            0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.860000e+00,
            2.180000e+00,
            2.500000e+00,
            2.821300e+00,
            3.142700e+00,
            3.464100e+00,
            3.785400e+00}, // SINR
           {9.951923e-01,
            8.775510e-01,
            5.298117e-01,
            1.524575e-01,
            2.220000e-02,
            1.200000e-03,
            1.000000e-04} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.798400e+00, 2.267700e+00, 2.737100e+00, 3.206500e+00, 3.675800e+00}, // SINR
           {9.971154e-01, 8.274194e-01, 2.292048e-01, 9.000000e-03, 1.000000e-04}  // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {2.110000e+00,
            2.350000e+00,
            2.594600e+00,
            2.837500e+00,
            3.080400e+00,
            3.323300e+00,
            3.566200e+00}, // SINR
           {9.451439e-01,
            7.514793e-01,
            4.040605e-01,
            1.261284e-01,
            2.220000e-02,
            1.500000e-03,
            0} // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {2.040000e+00,
            2.270000e+00,
            2.502500e+00,
            2.735000e+00,
            2.967500e+00,
            3.200000e+00,
            3.430000e+00}, // SINR
           {9.611111e-01,
            8.192675e-01,
            5.189549e-01,
            2.120573e-01,
            4.950000e-02,
            5.600000e-03,
            0} // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {2.153000e+00, 2.526100e+00, 2.899200e+00, 3.272300e+00, 3.645400e+00}, // SINR
           {9.262590e-01, 4.792453e-01, 6.550000e-02, 2.300000e-03, 0}             // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {1.680000e+00, 2.085000e+00, 2.490000e+00, 2.895000e+00, 3.300000e+00}, // SINR
           {1, 9.624060e-01, 5.391949e-01, 6.240000e-02, 9.000000e-04}             // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {1.972400e+00, 2.405700e+00, 2.838900e+00, 3.272100e+00, 3.705400e+00}, // SINR
           {9.923077e-01, 7.000000e-01, 1.013854e-01, 1.300000e-03, 0}             // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {1.850000e+00,
            2.184400e+00,
            2.518900e+00,
            2.853300e+00,
            3.187700e+00,
            3.520000e+00},                                                           // SINR
           {9.990385e-01, 9.299645e-01, 4.885057e-01, 7.010000e-02, 1.600000e-03, 0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {2.150000e+00, 2.487000e+00, 2.824000e+00, 3.161100e+00, 3.498100e+00}, // SINR
           {9.429348e-01, 5.080000e-01, 6.360000e-02, 1.200000e-03, 0}             // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {2.200000e+00, 2.475000e+00, 2.750000e+00, 3.025000e+00, 3.300000e+00}, // SINR
           {9.338768e-01, 5.625000e-01, 1.128597e-01, 4.800000e-03, 0}             // BLER
       }},
      {1800U, // SINR and BLER for CBS 1800
       MmWaveEesmErrorModel::DoubleTuple{
           {2.080000e+00,
            2.300000e+00,
            2.520000e+00,
            2.740000e+00,
            2.960000e+00,
            3.180000e+00}, // SINR
           {9.923077e-01,
            8.887931e-01,
            5.488197e-01,
            1.628739e-01,
            1.880000e-02,
            6.000000e-04} // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {2.031500e+00,
            2.260200e+00,
            2.488900e+00,
            2.717700e+00,
            2.946400e+00,
            3.180000e+00,
            3.400000e+00}, // SINR
           {9.903846e-01,
            8.996479e-01,
            5.644273e-01,
            1.889098e-01,
            2.380000e-02,
            8.000000e-04,
            0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {2.043500e+00, 2.332400e+00, 2.621400e+00, 2.910400e+00, 3.199300e+00}, // SINR
           {9.942308e-01, 8.462171e-01, 3.189547e-01, 2.740000e-02, 6.000000e-04}  // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {2.200000e+00, 2.450000e+00, 2.700000e+00, 2.950000e+00, 3.200000e+00}, // SINR
           {9.448529e-01, 5.985915e-01, 1.469555e-01, 1.030000e-02, 1.000000e-04}  // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {1.850000e+00, 2.350000e+00, 2.850000e+00, 3.350000e+00}, // SINR
           {1, 8.015625e-01, 3.500000e-02, 0}                        // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {2.100000e+00, 2.375000e+00, 2.650000e+00, 2.925000e+00, 3.200000e+00}, // SINR
           {9.932692e-01, 7.903963e-01, 2.112795e-01, 1.290000e-02, 1.000000e-04}  // BLER
       }},
      {2976U, // SINR and BLER for CBS 2976
       MmWaveEesmErrorModel::DoubleTuple{
           {1.017300e+00,
            1.864600e+00,
            2.430000e+00,
            2.711900e+00,
            2.990000e+00,
            3.559200e+00},                                                // SINR
           {1, 9.990385e-01, 7.448830e-01, 1.598282e-01, 3.800000e-03, 0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.900000e+00, 2.450000e+00, 3, 3.550000e+00}, // SINR
           {1, 6.464646e-01, 3.000000e-03, 0}             // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {1.800000e+00,
            2.300000e+00,
            2.630000e+00,
            2.800000e+00,
            2.970000e+00,
            3.300000e+00},                                                // SINR
           {1, 9.027778e-01, 2.579082e-01, 4.390000e-02, 4.300000e-03, 0} // BLER
       }}},
     {      // MCS 6
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {2.570000e+00, 2.838100e+00, 3.108100e+00, 3.378200e+00, 3.648200e+00,
            3.918300e+00, 4.190000e+00, 4.460000e+00, 4.730000e+00, 5,
            5.270000e+00, 5.540000e+00, 5.810000e+00, 6.080000e+00, 6.350000e+00,
            6.620000e+00, 6.890000e+00, 7.160000e+00, 7.430000e+00, 7.700000e+00,
            7.970000e+00, 8.240000e+00, 8.510000e+00}, // SINR
           {9.001736e-01,
            8.575000e-01,
            7.934783e-01,
            7.292857e-01,
            6.496212e-01,
            5.600437e-01,
            4.605978e-01,
            3.638329e-01,
            2.760417e-01,
            2.020465e-01,
            1.319444e-01,
            8.797038e-02,
            5.230000e-02,
            3.110000e-02,
            1.760000e-02,
            9.800000e-03,
            4.300000e-03,
            2.700000e-03,
            1.400000e-03,
            5.000000e-04,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {2.250000e+00,
            3.212500e+00,
            4.175000e+00,
            5.137500e+00,
            6.100000e+00,
            7.060000e+00,
            8.020000e+00,
            8.990000e+00}, // SINR
           {9.699248e-01,
            8.303571e-01,
            5.414894e-01,
            2.099332e-01,
            3.680000e-02,
            3.000000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {2.170000e+00,
            2.533500e+00,
            2.898100e+00,
            3.262600e+00,
            3.627200e+00,
            3.991800e+00,
            4.360000e+00,
            4.720000e+00,
            5.090000e+00,
            5.450000e+00,
            5.810000e+00,
            6.180000e+00,
            6.540000e+00,
            6.910000e+00,
            7.270000e+00}, // SINR
           {9.458955e-01,
            8.895548e-01,
            8.109375e-01,
            6.936141e-01,
            5.514069e-01,
            4.003165e-01,
            2.453704e-01,
            1.367102e-01,
            6.300000e-02,
            2.480000e-02,
            9.000000e-03,
            3.000000e-03,
            7.000000e-04,
            2.000000e-04,
            1.000000e-04} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {2.480000e+00,
            2.740000e+00,
            3,
            3.261200e+00,
            3.522500e+00,
            3.783700e+00,
            4.045000e+00,
            4.310000e+00,
            4.570000e+00,
            4.830000e+00,
            5.090000e+00,
            5.350000e+00,
            5.610000e+00,
            5.870000e+00,
            6.140000e+00,
            6.400000e+00,
            6.660000e+00,
            6.920000e+00}, // SINR
           {9.255319e-01,
            8.758562e-01,
            8.245192e-01,
            7.536765e-01,
            6.610825e-01,
            5.427350e-01,
            4.385813e-01,
            3.311346e-01,
            2.127750e-01,
            1.368464e-01,
            8.260000e-02,
            4.340000e-02,
            2.270000e-02,
            1.090000e-02,
            4.900000e-03,
            2.300000e-03,
            9.000000e-04,
            2.000000e-04} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {2.250000e+00,
            2.500000e+00,
            2.750000e+00,
            2.999200e+00,
            3.251700e+00,
            3.504200e+00,
            3.756800e+00,
            4.009300e+00,
            4.260000e+00,
            4.510000e+00,
            4.770000e+00,
            5.020000e+00,
            5.270000e+00,
            5.520000e+00,
            5.780000e+00,
            6.030000e+00,
            6.280000e+00}, // SINR
           {9.411232e-01,
            8.888889e-01,
            8.429276e-01,
            7.742424e-01,
            6.621094e-01,
            5.630531e-01,
            4.420732e-01,
            3.200758e-01,
            2.322417e-01,
            1.450404e-01,
            8.600000e-02,
            5.070000e-02,
            2.620000e-02,
            1.270000e-02,
            5.300000e-03,
            1.600000e-03,
            3.000000e-04} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {2.590000e+00,
            2.871100e+00,
            3.150000e+00,
            3.429000e+00,
            3.707900e+00,
            3.986800e+00,
            4.270000e+00,
            4.540000e+00,
            4.820000e+00,
            5.100000e+00,
            5.380000e+00,
            5.660000e+00,
            5.940000e+00,
            6.220000e+00,
            6.500000e+00}, // SINR
           {9.137324e-01,
            8.470395e-01,
            7.634731e-01,
            6.268473e-01,
            4.912791e-01,
            3.593750e-01,
            2.425193e-01,
            1.462456e-01,
            7.750000e-02,
            3.500000e-02,
            1.550000e-02,
            5.000000e-03,
            2.200000e-03,
            7.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {2.510000e+00,
            2.720000e+00,
            2.930000e+00,
            3.140300e+00,
            3.349100e+00,
            3.558000e+00,
            3.766800e+00,
            3.975700e+00,
            4.180000e+00,
            4.390000e+00,
            4.600000e+00,
            4.810000e+00,
            5.020000e+00,
            5.230000e+00,
            5.440000e+00,
            5.650000e+00,
            5.860000e+00,
            6.070000e+00}, // SINR
           {9.137324e-01,
            8.565436e-01,
            7.814417e-01,
            6.929348e-01,
            5.748874e-01,
            4.688662e-01,
            3.618608e-01,
            2.661547e-01,
            1.835766e-01,
            1.221951e-01,
            6.840000e-02,
            3.920000e-02,
            2.050000e-02,
            9.500000e-03,
            5.100000e-03,
            2.200000e-03,
            1.000000e-03,
            4.000000e-04} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {2.580000e+00,
            2.810000e+00,
            3.041800e+00,
            3.272500e+00,
            3.503200e+00,
            3.733900e+00,
            3.964600e+00,
            4.200000e+00,
            4.430000e+00,
            4.660000e+00,
            4.890000e+00,
            5.120000e+00,
            5.350000e+00,
            5.580000e+00,
            5.810000e+00,
            6.040000e+00}, // SINR
           {9.271583e-01,
            8.715986e-01,
            7.927019e-01,
            6.925676e-01,
            5.685841e-01,
            4.405172e-01,
            3.238491e-01,
            2.197300e-01,
            1.369565e-01,
            8.176164e-02,
            4.510000e-02,
            2.120000e-02,
            7.600000e-03,
            2.800000e-03,
            8.000000e-04,
            4.000000e-04} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {2.330000e+00,
            2.560000e+00,
            2.790000e+00,
            3.022800e+00,
            3.252700e+00,
            3.482500e+00,
            3.712400e+00,
            3.942300e+00,
            4.170000e+00,
            4.400000e+00,
            4.630000e+00,
            4.860000e+00,
            5.090000e+00,
            5.320000e+00,
            5.550000e+00,
            5.780000e+00,
            6.010000e+00}, // SINR
           {9.375000e-01,
            8.818027e-01,
            8.188291e-01,
            7.169944e-01,
            5.952103e-01,
            4.678309e-01,
            3.348806e-01,
            2.189119e-01,
            1.326558e-01,
            7.060000e-02,
            3.580000e-02,
            1.510000e-02,
            6.800000e-03,
            2.300000e-03,
            1.000000e-03,
            4.000000e-04,
            1.000000e-04} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {2.340000e+00,
            2.600000e+00,
            2.862500e+00,
            3.126900e+00,
            3.391200e+00,
            3.655600e+00,
            3.920000e+00,
            4.180000e+00,
            4.450000e+00,
            4.710000e+00,
            4.980000e+00,
            5.240000e+00,
            5.510000e+00,
            5.770000e+00}, // SINR
           {9.485294e-01,
            8.951049e-01,
            7.987421e-01,
            6.610825e-01,
            5.070000e-01,
            3.542837e-01,
            2.205624e-01,
            1.201004e-01,
            5.600000e-02,
            2.300000e-02,
            9.100000e-03,
            2.700000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {2.310000e+00,
            2.695100e+00,
            3.080200e+00,
            3.465300e+00,
            3.850400e+00,
            4.235500e+00,
            4.620000e+00,
            5.010000e+00,
            5.390000e+00,
            5.780000e+00,
            6.160000e+00}, // SINR
           {9.546296e-01,
            8.750000e-01,
            7.302260e-01,
            5.105000e-01,
            2.768640e-01,
            1.066681e-01,
            3.150000e-02,
            5.700000e-03,
            6.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {2.400000e+00,
            2.800000e+00,
            3.200000e+00,
            3.600000e+00,
            4,
            4.400000e+00,
            4.800000e+00,
            5.200000e+00,
            5.600000e+00,
            6,
            6.400000e+00}, // SINR
           {9.694656e-01,
            8.698980e-01,
            6.527062e-01,
            3.944704e-01,
            1.634241e-01,
            4.750000e-02,
            9.200000e-03,
            2.100000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {2.200000e+00,
            2.700000e+00,
            3.200000e+00,
            3.700000e+00,
            4.200000e+00,
            4.700000e+00,
            5.200000e+00}, // SINR
           {9.770992e-01,
            8.501656e-01,
            5.054134e-01,
            1.614249e-01,
            2.400000e-02,
            1.800000e-03,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {2.400000e+00,
            2.975000e+00,
            3.550000e+00,
            4.125000e+00,
            4.700000e+00,
            5.280000e+00}, // SINR
           {9.512868e-01,
            6.824866e-01,
            2.375470e-01,
            3.000000e-02,
            1.500000e-03,
            1.000000e-04} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {2.400000e+00,
            2.950000e+00,
            3.500000e+00,
            4.050000e+00,
            4.600000e+00,
            5.150000e+00},                                                           // SINR
           {9.549632e-01, 7.099719e-01, 2.527500e-01, 2.820000e-02, 1.300000e-03, 0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {2.500000e+00, 3.025000e+00, 3.550000e+00, 4.075000e+00, 4.600000e+00}, // SINR
           {9.379496e-01, 6.425000e-01, 2.040650e-01, 2.240000e-02, 1.000000e-03}  // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {2.500000e+00,
            3.025000e+00,
            3.550000e+00,
            4.075000e+00,
            4.600000e+00,
            5.130000e+00}, // SINR
           {9.325540e-01,
            6.060427e-01,
            1.741690e-01,
            1.600000e-02,
            1.200000e-03,
            1.000000e-04} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {2.331300e+00,
            2.769800e+00,
            3.208400e+00,
            3.646900e+00,
            4.085400e+00,
            4.520000e+00,
            4.960000e+00}, // SINR
           {9.740385e-01,
            8.184713e-01,
            4.292373e-01,
            1.051402e-01,
            1.050000e-02,
            1.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {2.349000e+00,
            2.771300e+00,
            3.193600e+00,
            3.615800e+00,
            4.038100e+00,
            4.460000e+00,
            4.880000e+00}, // SINR
           {9.807692e-01,
            8.366013e-01,
            4.323630e-01,
            1.078303e-01,
            1.010000e-02,
            6.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {2.492800e+00, 2.984500e+00, 3.476200e+00, 3.968000e+00, 4.459700e+00}, // SINR
           {9.570896e-01, 6.374378e-01, 1.733150e-01, 1.490000e-02, 1.000000e-04}  // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {2.400000e+00, 2.950000e+00, 3.500000e+00, 4.050000e+00, 4.600000e+00}, // SINR
           {9.687500e-01, 6.280788e-01, 1.126014e-01, 2.700000e-03, 1.000000e-04}  // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {2.444300e+00, 2.925700e+00, 3.407200e+00, 3.888600e+00, 4.370000e+00}, // SINR
           {9.759615e-01, 6.845238e-01, 1.860163e-01, 1.260000e-02, 1.000000e-04}  // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {2.330000e+00,
            2.700000e+00,
            3.075000e+00,
            3.450000e+00,
            3.825000e+00,
            4.200000e+00}, // SINR
           {9.809160e-01,
            8.516667e-01,
            4.629121e-01,
            1.107679e-01,
            9.400000e-03,
            6.000000e-04} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {2.480500e+00, 3.005900e+00, 3.531300e+00, 4.056700e+00, 4.582100e+00}, // SINR
           {9.617537e-01, 5.131048e-01, 3.880000e-02, 4.000000e-04, 0}             // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {2.500000e+00, 3, 3.500000e+00, 4, 4.500000e+00},           // SINR
           {9.836538e-01, 6.553030e-01, 7.830000e-02, 1.200000e-03, 0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {2.250000e+00, 2.737900e+00, 3.225800e+00, 3.713600e+00, 4.201500e+00}, // SINR
           {1, 9.447464e-01, 5.105847e-01, 5.950000e-02, 8.000000e-04}             // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {2.349300e+00, 2.864500e+00, 3.379800e+00, 3.895100e+00, 4.410300e+00}, // SINR
           {9.980769e-01, 8.895548e-01, 3.184975e-01, 1.280000e-02, 1.000000e-04}  // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {2.763000e+00, 3.147800e+00, 3.532600e+00, 3.917300e+00, 4.302100e+00}, // SINR
           {9.649621e-01, 6.256098e-01, 1.367358e-01, 6.700000e-03, 0}             // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {2.683800e+00, 3.061300e+00, 3.438800e+00, 3.816300e+00, 4.193800e+00}, // SINR
           {9.884615e-01, 7.672156e-01, 2.446394e-01, 1.780000e-02, 1.000000e-04}  // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {2.816700e+00, 3.133900e+00, 3.451200e+00, 3.768400e+00, 4.085600e+00}, // SINR
           {9.586466e-01, 6.932432e-01, 2.281137e-01, 2.340000e-02, 6.000000e-04}  // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {2.755100e+00, 3.134000e+00, 3.512900e+00, 3.891700e+00, 4.270600e+00}, // SINR
           {9.772727e-01, 6.885135e-01, 1.554054e-01, 6.100000e-03, 0}             // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {2.700900e+00, 3.065100e+00, 3.429300e+00, 3.793500e+00, 4.157700e+00}, // SINR
           {9.807692e-01, 7.198034e-01, 1.723901e-01, 7.800000e-03, 1.000000e-04}  // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {2.536900e+00, 2.885600e+00, 3.234400e+00, 3.583100e+00, 3.931800e+00}, // SINR
           {9.980769e-01, 9.226619e-01, 4.444444e-01, 4.770000e-02, 7.000000e-04}  // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {2.825000e+00, 3.143700e+00, 3.462500e+00, 3.781200e+00, 4.100000e+00}, // SINR
           {9.642857e-01, 6.021127e-01, 1.125790e-01, 4.900000e-03, 0}             // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {2.600000e+00, 2.975000e+00, 3.350000e+00, 3.725000e+00, 4.100000e+00}, // SINR
           {9.990385e-01, 8.750000e-01, 2.446498e-01, 6.000000e-03, 0}             // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {2.700000e+00, 3.025000e+00, 3.350000e+00, 3.675000e+00, 4}, // SINR
           {9.971154e-01, 8.169355e-01, 2.217314e-01, 8.500000e-03, 0}  // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {2.700000e+00, 3.025000e+00, 3.350000e+00, 3.675000e+00, 4}, // SINR
           {9.980769e-01, 8.093354e-01, 2.229789e-01, 5.000000e-03, 0}  // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {2.300000e+00,
            2.925000e+00,
            3.340000e+00,
            3.550000e+00,
            3.760000e+00,
            4.175000e+00},                                                // SINR
           {1, 9.151786e-01, 1.965397e-01, 2.390000e-02, 7.000000e-04, 0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {2.798500e+00, 3.171200e+00, 3.543800e+00, 3.916500e+00, 4.289100e+00}, // SINR
           {9.798077e-01, 5.791855e-01, 4.510000e-02, 1.000000e-04, 0}             // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {2.399800e+00, 2.824700e+00, 3.249600e+00, 3.674400e+00, 4.099300e+00}, // SINR
           {1, 9.836538e-01, 4.157072e-01, 7.600000e-03, 0}                        // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {2.848100e+00, 3.238700e+00, 3.629200e+00, 4.019800e+00}, // SINR
           {9.790076e-01, 4.502688e-01, 1.110000e-02, 0}             // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {2.315000e+00, 2.754800e+00, 3.194700e+00, 3.634500e+00, 4.074400e+00}, // SINR
           {1, 9.932692e-01, 4.913127e-01, 5.700000e-03, 0}                        // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {2.729900e+00, 3.085800e+00, 3.441700e+00, 3.797600e+00, 4.153500e+00}, // SINR
           {1, 8.415033e-01, 1.176539e-01, 2.000000e-04, 0}                        // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {2.830800e+00, 3.224700e+00, 3.618500e+00, 4.012300e+00}, // SINR
           {9.932692e-01, 5.374473e-01, 1.150000e-02, 0}             // BLER
       }}},
     {      // MCS 7
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {3.250000e+00, 3.500000e+00, 3.747700e+00, 4,
            4.252300e+00, 4.504600e+00, 4.756900e+00, 5.010000e+00,
            5.260000e+00, 5.510000e+00, 5.770000e+00, 6.020000e+00,
            6.270000e+00, 6.520000e+00, 6.780000e+00, 7.030000e+00,
            7.280000e+00, 7.530000e+00, 7.790000e+00, 8.040000e+00,
            8.290000e+00, 8.540000e+00, 8.800000e+00, 9.050000e+00,
            9.300000e+00}, // SINR
           {9.205357e-01, 8.845486e-01, 8.521242e-01, 8.020186e-01, 7.434593e-01,
            6.692708e-01, 6.023810e-01, 5.141700e-01, 4.181743e-01, 3.355438e-01,
            2.509940e-01, 1.847426e-01, 1.341104e-01, 9.639658e-02, 6.100000e-02,
            3.670000e-02, 2.240000e-02, 1.290000e-02, 6.000000e-03, 3.700000e-03,
            1.800000e-03, 7.000000e-04, 3.000000e-04, 3.000000e-04, 1.000000e-04} // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {3.479200e+00,
            3.847400e+00,
            4.215600e+00,
            4.583700e+00,
            4.951900e+00,
            5.320000e+00,
            5.690000e+00,
            6.060000e+00,
            6.420000e+00,
            6.790000e+00,
            7.160000e+00,
            7.530000e+00,
            7.900000e+00,
            8.270000e+00,
            8.630000e+00}, // SINR
           {9.273050e-01,
            8.649329e-01,
            7.850610e-01,
            6.759259e-01,
            5.556769e-01,
            4.151639e-01,
            2.825112e-01,
            1.807554e-01,
            1.024746e-01,
            5.200000e-02,
            2.090000e-02,
            7.200000e-03,
            2.600000e-03,
            8.000000e-04,
            3.000000e-04} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {3.300000e+00,
            3.862500e+00,
            4.425000e+00,
            4.987500e+00,
            5.550000e+00,
            6.110000e+00,
            6.680000e+00,
            7.240000e+00,
            7.800000e+00,
            8.360000e+00,
            8.930000e+00,
            9.490000e+00}, // SINR
           {9.574074e-01,
            8.897569e-01,
            7.514620e-01,
            5.445279e-01,
            3.351064e-01,
            1.594663e-01,
            5.350000e-02,
            1.530000e-02,
            3.300000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {2.880000e+00,
            3.835000e+00,
            4.790000e+00,
            5.745000e+00,
            6.700000e+00,
            7.660000e+00},                                                           // SINR
           {9.522059e-01, 7.715774e-01, 3.821970e-01, 8.690000e-02, 8.300000e-03, 0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {3.340000e+00,
            3.620500e+00,
            3.899300e+00,
            4.178000e+00,
            4.456800e+00,
            4.735600e+00,
            5.010000e+00,
            5.290000e+00,
            5.570000e+00,
            5.850000e+00,
            6.130000e+00,
            6.410000e+00,
            6.690000e+00,
            6.970000e+00,
            7.240000e+00,
            7.520000e+00}, // SINR
           {9.097222e-01,
            8.609272e-01,
            7.852761e-01,
            6.865079e-01,
            5.825688e-01,
            4.603102e-01,
            3.407859e-01,
            2.288251e-01,
            1.387665e-01,
            7.791165e-02,
            4.180000e-02,
            2.020000e-02,
            7.000000e-03,
            2.100000e-03,
            1.100000e-03,
            3.000000e-04} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {3.480300e+00,
            3.788600e+00,
            4.096900e+00,
            4.405200e+00,
            4.713500e+00,
            5.020000e+00,
            5.330000e+00,
            5.640000e+00,
            5.950000e+00,
            6.250000e+00,
            6.560000e+00,
            6.870000e+00,
            7.180000e+00,
            7.490000e+00,
            7.800000e+00}, // SINR
           {9.280576e-01,
            8.472222e-01,
            7.514620e-01,
            6.037736e-01,
            4.663284e-01,
            3.259044e-01,
            1.892911e-01,
            1.104626e-01,
            5.350000e-02,
            2.410000e-02,
            8.600000e-03,
            2.400000e-03,
            1.000000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {3.639900e+00,
            3.905500e+00,
            4.171200e+00,
            4.436800e+00,
            4.702500e+00,
            4.970000e+00,
            5.230000e+00,
            5.500000e+00,
            5.770000e+00,
            6.030000e+00,
            6.300000e+00,
            6.560000e+00,
            6.830000e+00,
            7.090000e+00,
            7.360000e+00}, // SINR
           {9.038462e-01,
            8.282258e-01,
            7.385714e-01,
            6.030806e-01,
            4.771863e-01,
            3.538194e-01,
            2.397814e-01,
            1.443966e-01,
            7.770000e-02,
            3.820000e-02,
            1.690000e-02,
            6.700000e-03,
            2.100000e-03,
            1.100000e-03,
            6.000000e-04} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {3.277100e+00,
            3.719100e+00,
            4.161100e+00,
            4.603100e+00,
            5.045100e+00,
            5.490000e+00,
            5.930000e+00,
            6.370000e+00,
            6.810000e+00,
            7.260000e+00}, // SINR
           {9.029720e-01,
            7.771084e-01,
            5.767045e-01,
            3.354388e-01,
            1.642253e-01,
            5.670000e-02,
            1.360000e-02,
            1.900000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {3.260000e+00,
            3.656400e+00,
            4.052900e+00,
            4.449300e+00,
            4.845800e+00,
            5.240000e+00,
            5.640000e+00,
            6.040000e+00,
            6.430000e+00,
            6.830000e+00,
            7.220000e+00}, // SINR
           {9.267857e-01,
            8.400974e-01,
            6.552835e-01,
            4.622727e-01,
            2.407495e-01,
            1.025913e-01,
            3.380000e-02,
            7.300000e-03,
            1.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {3.242200e+00,
            3.637400e+00,
            4.032600e+00,
            4.427800e+00,
            4.823000e+00,
            5.220000e+00,
            5.610000e+00,
            6.010000e+00,
            6.400000e+00,
            6.800000e+00,
            7.190000e+00}, // SINR
           {9.117133e-01,
            7.745536e-01,
            5.771396e-01,
            3.582621e-01,
            1.625162e-01,
            5.480000e-02,
            1.210000e-02,
            2.200000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {3.220000e+00,
            3.575100e+00,
            3.925200e+00,
            4.275300e+00,
            4.625400e+00,
            4.975500e+00,
            5.330000e+00,
            5.680000e+00,
            6.030000e+00,
            6.380000e+00,
            6.730000e+00}, // SINR
           {9.370504e-01,
            8.379934e-01,
            6.776316e-01,
            4.735130e-01,
            2.725054e-01,
            1.205529e-01,
            3.910000e-02,
            1.000000e-02,
            2.400000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {3.210000e+00,
            3.440000e+00,
            3.673100e+00,
            3.905700e+00,
            4.138300e+00,
            4.370900e+00,
            4.603500e+00,
            4.840000e+00,
            5.070000e+00,
            5.300000e+00,
            5.530000e+00,
            5.770000e+00,
            6,
            6.230000e+00,
            6.460000e+00}, // SINR
           {9.064685e-01,
            8.382353e-01,
            7.164804e-01,
            5.740950e-01,
            4.290541e-01,
            2.908986e-01,
            1.739281e-01,
            8.910000e-02,
            4.280000e-02,
            1.790000e-02,
            6.300000e-03,
            1.700000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {3.230000e+00,
            3.538400e+00,
            3.842600e+00,
            4.146900e+00,
            4.451200e+00,
            4.755400e+00,
            5.060000e+00,
            5.360000e+00,
            5.670000e+00,
            5.970000e+00,
            6.280000e+00,
            6.580000e+00}, // SINR
           {9.438406e-01,
            8.400974e-01,
            6.610825e-01,
            4.313559e-01,
            2.409178e-01,
            1.056624e-01,
            3.500000e-02,
            9.400000e-03,
            1.200000e-03,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {3.173000e+00,
            3.526800e+00,
            3.880600e+00,
            4.234400e+00,
            4.588200e+00,
            4.940000e+00,
            5.300000e+00,
            5.650000e+00,
            6}, // SINR
           {9.402174e-01,
            8.192675e-01,
            5.965116e-01,
            3.168970e-01,
            1.209135e-01,
            3.370000e-02,
            6.200000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {3.200000e+00,
            3.501200e+00,
            3.803400e+00,
            4.105600e+00,
            4.407900e+00,
            4.710100e+00,
            5.010000e+00,
            5.310000e+00,
            5.620000e+00,
            5.920000e+00,
            6.220000e+00,
            6.520000e+00}, // SINR
           {9.570896e-01,
            8.650000e-01,
            6.775266e-01,
            4.586331e-01,
            2.353352e-01,
            9.081796e-02,
            2.510000e-02,
            4.900000e-03,
            7.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {3.300000e+00, 3.900000e+00, 4.500000e+00, 5.100000e+00, 5.700000e+00}, // SINR
           {9.242958e-01, 5.786199e-01, 1.411155e-01, 9.500000e-03, 1.000000e-04}  // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {3.180000e+00,
            3.390000e+00,
            3.600000e+00,
            3.807700e+00,
            4.018900e+00,
            4.230100e+00,
            4.441200e+00,
            4.652400e+00,
            4.860000e+00,
            5.070000e+00,
            5.290000e+00,
            5.500000e+00,
            5.710000e+00,
            5.920000e+00}, // SINR
           {9.476103e-01,
            8.914931e-01,
            7.703313e-01,
            6.243902e-01,
            4.565412e-01,
            2.926334e-01,
            1.549014e-01,
            6.950000e-02,
            2.690000e-02,
            8.400000e-03,
            2.400000e-03,
            4.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {3.300000e+00,
            3.625000e+00,
            3.950000e+00,
            4.275000e+00,
            4.600000e+00,
            4.930000e+00,
            5.250000e+00,
            5.570000e+00}, // SINR
           {9.470803e-01,
            8.097826e-01,
            5.188776e-01,
            2.398201e-01,
            7.310000e-02,
            1.450000e-02,
            1.900000e-03,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {3.330000e+00,
            3.540000e+00,
            3.745700e+00,
            3.951800e+00,
            4.158000e+00,
            4.364100e+00,
            4.570300e+00,
            4.780000e+00,
            4.980000e+00,
            5.190000e+00,
            5.390000e+00,
            5.600000e+00,
            5.810000e+00}, // SINR
           {9.303571e-01,
            8.550000e-01,
            7.247191e-01,
            5.141129e-01,
            3.233974e-01,
            1.664456e-01,
            6.880000e-02,
            2.430000e-02,
            5.600000e-03,
            7.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {3.430000e+00,
            3.620000e+00,
            3.814100e+00,
            4.005300e+00,
            4.196500e+00,
            4.387700e+00,
            4.578900e+00,
            4.770000e+00,
            4.960000e+00,
            5.150000e+00,
            5.340000e+00,
            5.530000e+00}, // SINR
           {9.117133e-01,
            8.039063e-01,
            6.483586e-01,
            4.595324e-01,
            2.827915e-01,
            1.430398e-01,
            6.010000e-02,
            2.180000e-02,
            7.000000e-03,
            1.900000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {3.180000e+00, 3.833200e+00, 4.486400e+00, 5.139600e+00, 5.792800e+00}, // SINR
           {9.759615e-01, 5.625000e-01, 5.730000e-02, 7.000000e-04, 0}             // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {3.202900e+00, 3.837600e+00, 4.472300e+00, 5.107000e+00, 5.741700e+00}, // SINR
           {9.642857e-01, 5.370763e-01, 5.100000e-02, 4.000000e-04, 0}             // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {3.267100e+00, 3.873000e+00, 4.478900e+00, 5.084800e+00, 5.690700e+00}, // SINR
           {9.533582e-01, 4.724813e-01, 3.370000e-02, 3.000000e-04, 0}             // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {3.140000e+00, 3.683500e+00, 4.227100e+00, 4.770600e+00, 5.314100e+00}, // SINR
           {9.715909e-01, 6.787634e-01, 1.028723e-01, 1.300000e-03, 0}             // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {3.071600e+00, 3.688100e+00, 4.304500e+00, 4.921000e+00, 5.537500e+00}, // SINR
           {9.923077e-01, 6.225490e-01, 3.100000e-02, 1.000000e-04, 0}             // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {3.219800e+00, 3.773700e+00, 4.327600e+00, 4.881500e+00, 5.435400e+00}, // SINR
           {9.790076e-01, 4.980469e-01, 2.230000e-02, 1.000000e-04, 0}             // BLER
       }},
      {808U, // SINR and BLER for CBS 808
       MmWaveEesmErrorModel::DoubleTuple{
           {3.250000e+00, 3.770800e+00, 4.291700e+00, 4.812500e+00, 5.333300e+00}, // SINR
           {9.742366e-01, 4.874517e-01, 2.410000e-02, 1.000000e-04, 0}             // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {3.004000e+00, 3.637500e+00, 4.271000e+00, 4.904400e+00, 5.537900e+00}, // SINR
           {9.990385e-01, 9.102113e-01, 1.943374e-01, 1.500000e-03, 0}             // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {2.900000e+00, 3.400000e+00, 3.900000e+00, 4.400000e+00, 4.900000e+00}, // SINR
           {1, 9.826923e-01, 6.482412e-01, 7.800000e-02, 4.000000e-04}             // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {3.020000e+00, 3.540600e+00, 4.061100e+00, 4.581600e+00, 5.102200e+00}, // SINR
           {1, 9.734848e-01, 4.700375e-01, 2.100000e-02, 0}                        // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {3.500000e+00, 3.875000e+00, 4.250000e+00, 4.625000e+00, 5}, // SINR
           {9.646947e-01, 6.381250e-01, 1.401895e-01, 4.500000e-03, 0}  // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {3.246500e+00, 3.784600e+00, 4.322600e+00, 4.860700e+00, 5.398800e+00}, // SINR
           {9.990385e-01, 7.733434e-01, 7.020000e-02, 1.000000e-04, 0}             // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {3.339700e+00, 3.798800e+00, 4.257800e+00, 4.716900e+00, 5.175900e+00}, // SINR
           {9.932692e-01, 7.245763e-01, 8.200000e-02, 2.000000e-04, 0}             // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {3.144900e+00,
            3.664300e+00,
            4.010000e+00,
            4.183600e+00,
            4.360000e+00,
            4.702900e+00,
            5.222300e+00},                                                              // SINR
           {1, 9.329710e-01, 4.311224e-01, 1.742424e-01, 4.500000e-02, 9.000000e-04, 0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {3.450000e+00, 3.900000e+00, 4.350000e+00, 4.800000e+00}, // SINR
           {9.903846e-01, 5.797018e-01, 2.560000e-02, 0}             // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {3.005800e+00, 3.506400e+00, 4.007000e+00, 4.507700e+00, 5.008300e+00}, // SINR
           {1, 9.761450e-01, 3.431572e-01, 1.200000e-03, 0}                        // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {3.042800e+00, 3.522000e+00, 4.001200e+00, 4.480500e+00, 4.959700e+00}, // SINR
           {1, 9.903846e-01, 4.083601e-01, 3.800000e-03, 0}                        // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {3.300000e+00,
            3.720000e+00,
            3.925000e+00,
            4.130000e+00,
            4.550000e+00,
            5.175000e+00},                                                           // SINR
           {9.990385e-01, 8.412829e-01, 4.458627e-01, 1.013289e-01, 1.000000e-04, 0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {3.060800e+00,
            3.588000e+00,
            3.940000e+00,
            4.115100e+00,
            4.290000e+00,
            4.642300e+00},                                                // SINR
           {1, 9.699248e-01, 4.198505e-01, 1.272983e-01, 1.770000e-02, 0} // BLER
       }},
      {2472U, // SINR and BLER for CBS 2472
       MmWaveEesmErrorModel::DoubleTuple{
           {3.500000e+00, 3.781200e+00, 4.062500e+00, 4.343800e+00, 4.625000e+00}, // SINR
           {1, 9.031690e-01, 3.310547e-01, 2.060000e-02, 1.000000e-04}             // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {3.058300e+00,
            3.672400e+00,
            4.080000e+00,
            4.286500e+00,
            4.490000e+00,
            4.900500e+00},                                                // SINR
           {1, 9.375000e-01, 2.372642e-01, 3.390000e-02, 1.200000e-03, 0} // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {3.550000e+00,
            3.800000e+00,
            4.050000e+00,
            4.300000e+00,
            4.550000e+00,
            4.800000e+00},                                                           // SINR
           {9.856870e-01, 8.117089e-01, 2.794604e-01, 2.480000e-02, 4.000000e-04, 0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {3.100000e+00,
            3.604200e+00,
            3.940000e+00,
            4.108300e+00,
            4.280000e+00,
            4.612400e+00},                                                // SINR
           {1, 9.837786e-01, 4.828897e-01, 1.583333e-01, 2.020000e-02, 0} // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {3.260000e+00,
            3.707500e+00,
            4.010000e+00,
            4.155000e+00,
            4.300000e+00,
            4.602500e+00},                                                // SINR
           {1, 9.356884e-01, 3.525910e-01, 9.977533e-02, 1.400000e-02, 0} // BLER
       }}},
     {      // MCS 8
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {3.900000e+00,
            4.343000e+00,
            4.782000e+00,
            5.221000e+00,
            5.660000e+00,
            6.099000e+00,
            6.540000e+00,
            6.980000e+00,
            7.420000e+00,
            7.860000e+00,
            8.290000e+00}, // SINR
           {9.131206e-01,
            8.213141e-01,
            6.727749e-01,
            4.815341e-01,
            2.873858e-01,
            1.398942e-01,
            5.640000e-02,
            1.690000e-02,
            3.600000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {3.440000e+00,
            4.075000e+00,
            4.712500e+00,
            5.350000e+00,
            5.987500e+00,
            6.625000e+00,
            7.260000e+00,
            7.900000e+00,
            8.540000e+00,
            9.180000e+00}, // SINR
           {9.736842e-01,
            8.810345e-01,
            6.821809e-01,
            4.071543e-01,
            1.673333e-01,
            4.650000e-02,
            8.200000e-03,
            1.100000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {3.958200e+00,
            4.481400e+00,
            5.004600e+00,
            5.527800e+00,
            6.051000e+00,
            6.570000e+00,
            7.100000e+00,
            7.620000e+00,
            8.140000e+00,
            8.670000e+00}, // SINR
           {9.297445e-01,
            7.873476e-01,
            5.616740e-01,
            3.150000e-01,
            1.349569e-01,
            3.980000e-02,
            6.700000e-03,
            1.200000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {3.940700e+00,
            4.549200e+00,
            5.157700e+00,
            5.766100e+00,
            6.374600e+00,
            6.980000e+00,
            7.590000e+00,
            8.200000e+00,
            8.810000e+00}, // SINR
           {9.388686e-01,
            7.739521e-01,
            5.000000e-01,
            2.366071e-01,
            6.360000e-02,
            9.500000e-03,
            7.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {3.923900e+00,
            4.443600e+00,
            4.963400e+00,
            5.483200e+00,
            6.002900e+00,
            6.520000e+00,
            7.040000e+00,
            7.560000e+00,
            8.080000e+00}, // SINR
           {9.452555e-01,
            8.243671e-01,
            6.135266e-01,
            3.409704e-01,
            1.350590e-01,
            3.680000e-02,
            5.400000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {4,
            4.625000e+00,
            5.250000e+00,
            5.875000e+00,
            6.500000e+00,
            7.130000e+00,
            7.750000e+00,
            8.380000e+00}, // SINR
           {9.522059e-01,
            7.929688e-01,
            4.885057e-01,
            1.775388e-01,
            3.260000e-02,
            3.400000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {3.889600e+00,
            4.319800e+00,
            4.750100e+00,
            5.180300e+00,
            5.610600e+00,
            6.040000e+00,
            6.470000e+00,
            6.900000e+00,
            7.330000e+00}, // SINR
           {9.117133e-01,
            7.778614e-01,
            5.686937e-01,
            3.028846e-01,
            1.214908e-01,
            3.330000e-02,
            5.600000e-03,
            8.000000e-04,
            0} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {3.850000e+00,
            4.200000e+00,
            4.550000e+00,
            4.900000e+00,
            5.250000e+00,
            5.600000e+00,
            5.950000e+00,
            6.300000e+00,
            6.650000e+00,
            7,
            7.350000e+00}, // SINR
           {9.537037e-01,
            8.698980e-01,
            7.205056e-01,
            4.912451e-01,
            2.828652e-01,
            1.336070e-01,
            4.860000e-02,
            1.190000e-02,
            3.100000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {3.800000e+00,
            4.260000e+00,
            4.718800e+00,
            5.180100e+00,
            5.641500e+00,
            6.102800e+00,
            6.564200e+00}, // SINR
           {9.742366e-01,
            8.314516e-01,
            5.461373e-01,
            2.268851e-01,
            5.740000e-02,
            7.500000e-03,
            1.000000e-03} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {3.830000e+00,
            4.200000e+00,
            4.575000e+00,
            4.950000e+00,
            5.325000e+00,
            5.700000e+00,
            6.080000e+00,
            6.450000e+00,
            6.830000e+00,
            7.200000e+00}, // SINR
           {9.661654e-01,
            8.810764e-01,
            7.008197e-01,
            4.185855e-01,
            1.720246e-01,
            4.710000e-02,
            7.300000e-03,
            1.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {4.100000e+00,
            4.400000e+00,
            4.700000e+00,
            5,
            5.300000e+00,
            5.600000e+00,
            5.900000e+00,
            6.200000e+00,
            6.500000e+00,
            6.800000e+00,
            7.100000e+00}, // SINR
           {9.293478e-01,
            8.066038e-01,
            6.117150e-01,
            3.791168e-01,
            1.782932e-01,
            6.120000e-02,
            1.670000e-02,
            3.200000e-03,
            7.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {3.840000e+00,
            4.287700e+00,
            4.733800e+00,
            5.180000e+00,
            5.626100e+00,
            6.072300e+00,
            6.520000e+00}, // SINR
           {9.583333e-01,
            8.109177e-01,
            4.635036e-01,
            1.605314e-01,
            2.650000e-02,
            1.900000e-03,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {3.800000e+00,
            4.100000e+00,
            4.400000e+00,
            4.700000e+00,
            5,
            5.300000e+00,
            5.600000e+00,
            5.900000e+00,
            6.200000e+00,
            6.500000e+00,
            6.800000e+00}, // SINR
           {9.725379e-01,
            8.956897e-01,
            7.350000e-01,
            5.162602e-01,
            2.887931e-01,
            1.120651e-01,
            3.020000e-02,
            6.500000e-03,
            8.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {3.760000e+00,
            4.130000e+00,
            4.500400e+00,
            4.868200e+00,
            5.236000e+00,
            5.603700e+00,
            5.971500e+00,
            6.340000e+00}, // SINR
           {9.778846e-01,
            8.827055e-01,
            6.502525e-01,
            3.022076e-01,
            9.564777e-02,
            1.620000e-02,
            2.000000e-03,
            1.000000e-04} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {3.800000e+00,
            4.150000e+00,
            4.506200e+00,
            4.860000e+00,
            5.213700e+00,
            5.567500e+00,
            5.921200e+00,
            6.270000e+00}, // SINR
           {9.855769e-01,
            8.968531e-01,
            6.738281e-01,
            3.458672e-01,
            1.035894e-01,
            1.730000e-02,
            2.000000e-03,
            1.000000e-04} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {4.020000e+00,
            4.389500e+00,
            4.759900e+00,
            5.130200e+00,
            5.500500e+00,
            5.870800e+00}, // SINR
           {9.253597e-01,
            7.042350e-01,
            3.695335e-01,
            1.034120e-01,
            1.430000e-02,
            7.000000e-04} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {3.780000e+00,
            4.090000e+00,
            4.400000e+00,
            4.712500e+00,
            5.025000e+00,
            5.337500e+00,
            5.650000e+00,
            5.960000e+00,
            6.280000e+00}, // SINR
           {9.817308e-01,
            8.986014e-01,
            7.171788e-01,
            4.034810e-01,
            1.485765e-01,
            3.140000e-02,
            4.000000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {4.090000e+00,
            4.407100e+00,
            4.722600e+00,
            5.038100e+00,
            5.353700e+00,
            5.669200e+00,
            5.980000e+00}, // SINR
           {9.047203e-01,
            7.023481e-01,
            3.896605e-01,
            1.219631e-01,
            2.390000e-02,
            2.300000e-03,
            1.000000e-04} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {4.030000e+00,
            4.290000e+00,
            4.546200e+00,
            4.801800e+00,
            5.057300e+00,
            5.312900e+00,
            5.568500e+00,
            5.820000e+00,
            6.080000e+00}, // SINR
           {9.258929e-01,
            7.947531e-01,
            5.772727e-01,
            2.992874e-01,
            1.136980e-01,
            2.730000e-02,
            4.400000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {4.080000e+00,
            4.356300e+00,
            4.634100e+00,
            4.912000e+00,
            5.189800e+00,
            5.467700e+00,
            5.750000e+00}, // SINR
           {9.316547e-01,
            7.543605e-01,
            4.212046e-01,
            1.518182e-01,
            3.090000e-02,
            2.700000e-03,
            2.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {4.110000e+00,
            4.478800e+00,
            4.851600e+00,
            5.224400e+00,
            5.597200e+00,
            5.970000e+00},                                                           // SINR
           {9.361511e-01, 5.873288e-01, 1.442308e-01, 1.230000e-02, 1.000000e-04, 0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {4.130000e+00,
            4.478800e+00,
            4.824100e+00,
            5.169400e+00,
            5.514700e+00,
            5.860000e+00},                                                           // SINR
           {9.285714e-01, 5.759132e-01, 1.566397e-01, 1.160000e-02, 1.000000e-04, 0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {4.100000e+00,
            4.430700e+00,
            4.760500e+00,
            5.090300e+00,
            5.420200e+00,
            5.750000e+00}, // SINR
           {9.365809e-01,
            6.014151e-01,
            1.500896e-01,
            1.150000e-02,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {3.840000e+00,
            4.201500e+00,
            4.561100e+00,
            4.920700e+00,
            5.280400e+00,
            5.640000e+00},                                                           // SINR
           {9.961538e-01, 8.792808e-01, 4.050481e-01, 4.610000e-02, 1.800000e-03, 0} // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {4.306100e+00, 4.654200e+00, 5.002300e+00, 5.350400e+00, 5.698500e+00}, // SINR
           {9.512868e-01, 6.891892e-01, 2.377358e-01, 2.630000e-02, 7.000000e-04}  // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {4.392300e+00,
            4.661500e+00,
            4.930700e+00,
            5.200000e+00,
            5.469200e+00,
            5.740000e+00,
            6.010000e+00}, // SINR
           {9.119718e-01,
            6.479592e-01,
            2.649371e-01,
            5.080000e-02,
            4.200000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {4.200000e+00,
            4.460000e+00,
            4.720000e+00,
            4.980000e+00,
            5.240000e+00,
            5.500000e+00,
            5.760000e+00}, // SINR
           {9.668561e-01,
            8.011006e-01,
            4.463028e-01,
            1.361292e-01,
            1.610000e-02,
            1.000000e-03,
            0} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {4.258500e+00,
            4.509200e+00,
            4.760000e+00,
            5.010700e+00,
            5.261500e+00,
            5.510000e+00,
            5.760000e+00}, // SINR
           {9.708647e-01,
            8.125000e-01,
            4.598540e-01,
            1.344717e-01,
            1.790000e-02,
            7.000000e-04,
            0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {4.300000e+00, 4.675000e+00, 5.050000e+00, 5.425000e+00, 5.800000e+00}, // SINR
           {9.489051e-01, 5.029762e-01, 5.610000e-02, 5.000000e-04, 0}             // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {4.087700e+00,
            4.399400e+00,
            4.711100e+00,
            5.022800e+00,
            5.334500e+00,
            5.650000e+00},                                                           // SINR
           {9.971154e-01, 9.049296e-01, 4.267677e-01, 6.600000e-02, 2.200000e-03, 0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {4.323100e+00,
            4.516300e+00,
            4.709500e+00,
            4.902700e+00,
            5.095900e+00,
            5.290000e+00,
            5.480000e+00}, // SINR
           {9.457721e-01,
            7.901235e-01,
            4.494681e-01,
            1.408708e-01,
            2.240000e-02,
            1.800000e-03,
            0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {4.307700e+00, 4.598100e+00, 4.888500e+00, 5.178900e+00, 5.469300e+00}, // SINR
           {9.516423e-01, 6.329657e-01, 1.434497e-01, 7.300000e-03, 0}             // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {3.830800e+00, 4.262600e+00, 4.694400e+00, 5.126300e+00, 5.558100e+00}, // SINR
           {1, 9.664179e-01, 3.871951e-01, 5.700000e-03, 0}                        // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {3.353800e+00,
            4.024100e+00,
            4.470000e+00,
            4.694500e+00,
            4.920000e+00,
            5.364800e+00},                                                // SINR
           {1, 9.980769e-01, 7.924383e-01, 3.731618e-01, 5.990000e-02, 0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {4.220000e+00, 4.669800e+00, 5.118000e+00, 5.566200e+00}, // SINR
           {9.913462e-01, 4.449301e-01, 5.200000e-03, 0}             // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {4.100000e+00,
            4.480000e+00,
            4.663500e+00,
            4.850000e+00,
            5.229300e+00,
            5.795200e+00},                                                           // SINR
           {9.980769e-01, 7.891104e-01, 4.244966e-01, 1.023109e-01, 1.000000e-04, 0} // BLER
       }},
      {2792U, // SINR and BLER for CBS 2792
       MmWaveEesmErrorModel::DoubleTuple{
           {4.310000e+00, 4.630000e+00, 4.950000e+00, 5.275000e+00, 5.600000e+00}, // SINR
           {9.734848e-01, 5.084325e-01, 2.880000e-02, 1.000000e-04, 0}             // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {4.260000e+00,
            4.510000e+00,
            4.760000e+00,
            5.011200e+00,
            5.262100e+00,
            5.513000e+00},                                                           // SINR
           {9.894231e-01, 8.097484e-01, 3.067354e-01, 2.920000e-02, 5.000000e-04, 0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {4.330000e+00,
            4.570000e+00,
            4.810000e+00,
            5.054100e+00,
            5.295900e+00,
            5.537700e+00},                                                           // SINR
           {9.884615e-01, 7.448830e-01, 2.200612e-01, 1.350000e-02, 1.000000e-04, 0} // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {4.390000e+00, 4.620000e+00, 4.850000e+00, 5.078800e+00, 5.311500e+00}, // SINR
           {9.302536e-01, 5.495690e-01, 8.700000e-02, 2.800000e-03, 0}             // BLER
       }}},
     {      // MCS 9
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {4.570000e+00,
            5.002300e+00,
            5.433900e+00,
            5.865500e+00,
            6.297200e+00,
            6.728800e+00,
            7.160000e+00,
            7.590000e+00,
            8.020000e+00,
            8.460000e+00,
            8.890000e+00,
            9.320000e+00,
            9.750000e+00,
            1.018000e+01}, // SINR
           {9.202128e-01,
            8.387097e-01,
            7.258523e-01,
            5.363924e-01,
            3.652457e-01,
            2.175606e-01,
            1.073165e-01,
            4.570000e-02,
            1.750000e-02,
            6.500000e-03,
            2.200000e-03,
            4.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {4.639900e+00,
            5.156200e+00,
            5.672500e+00,
            6.188800e+00,
            6.705100e+00,
            7.220000e+00,
            7.740000e+00,
            8.250000e+00,
            8.770000e+00,
            9.290000e+00,
            9.800000e+00,
            1.032000e+01}, // SINR
           {9.280576e-01,
            8.089623e-01,
            6.153382e-01,
            3.955745e-01,
            2.107802e-01,
            8.852492e-02,
            2.920000e-02,
            7.100000e-03,
            1.600000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {4.700000e+00,
            5.150000e+00,
            5.600000e+00,
            6.050000e+00,
            6.500000e+00,
            6.950000e+00,
            7.400000e+00,
            7.850000e+00,
            8.300000e+00,
            8.750000e+00,
            9.200000e+00}, // SINR
           {9.131206e-01,
            7.875767e-01,
            6.009390e-01,
            3.945313e-01,
            2.087479e-01,
            9.937500e-02,
            3.550000e-02,
            9.600000e-03,
            2.100000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {3.970000e+00,
            4.800000e+00,
            5.625000e+00,
            6.450000e+00,
            7.275000e+00,
            8.100000e+00,
            8.920000e+00,
            9.750000e+00}, // SINR
           {9.807692e-01,
            8.707483e-01,
            5.786199e-01,
            2.231826e-01,
            3.940000e-02,
            4.900000e-03,
            1.100000e-03,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {3.740000e+00,
            4.700000e+00,
            5.662500e+00,
            6.625000e+00,
            7.587500e+00,
            8.550000e+00}, // SINR
           {9.932692e-01,
            8.924825e-01,
            5.647124e-01,
            1.382597e-01,
            1.380000e-02,
            1.000000e-04} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {4.540000e+00,
            4.880000e+00,
            5.213200e+00,
            5.550600e+00,
            5.888000e+00,
            6.225400e+00,
            6.562800e+00,
            6.900000e+00,
            7.240000e+00,
            7.580000e+00,
            7.910000e+00,
            8.250000e+00,
            8.590000e+00,
            8.920000e+00}, // SINR
           {9.320652e-01,
            8.576159e-01,
            7.470930e-01,
            5.706278e-01,
            4.077670e-01,
            2.418582e-01,
            1.207811e-01,
            5.300000e-02,
            2.080000e-02,
            5.400000e-03,
            1.700000e-03,
            5.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {4.590000e+00,
            5.175000e+00,
            5.761400e+00,
            6.347800e+00,
            6.934300e+00,
            7.520700e+00,
            8.110000e+00,
            8.690000e+00}, // SINR
           {9.285714e-01,
            7.619760e-01,
            4.639599e-01,
            1.750349e-01,
            3.600000e-02,
            5.400000e-03,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {4.600000e+00, 5.475000e+00, 6.350000e+00, 7.225000e+00, 8.100000e+00}, // SINR
           {9.253597e-01, 5.658482e-01, 1.319590e-01, 8.100000e-03, 3.000000e-04}  // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {4.680000e+00, 5.635000e+00, 6.590000e+00, 7.545000e+00, 8.500000e+00}, // SINR
           {9.214286e-01, 4.036624e-01, 2.520000e-02, 1.000000e-04, 0}             // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {4.380000e+00, 5.297500e+00, 6.215000e+00, 7.132500e+00, 8.050000e+00}, // SINR
           {9.746241e-01, 6.469849e-01, 9.261134e-02, 1.300000e-03, 0}             // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {4.510000e+00,
            4.850000e+00,
            5.187500e+00,
            5.525000e+00,
            5.862500e+00,
            6.200000e+00,
            6.540000e+00,
            6.880000e+00,
            7.210000e+00,
            7.550000e+00}, // SINR
           {9.636194e-01,
            8.801020e-01,
            6.949728e-01,
            4.425087e-01,
            2.229130e-01,
            7.570000e-02,
            1.770000e-02,
            2.500000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {4.480000e+00, 5.435000e+00, 6.390000e+00, 7.345000e+00}, // SINR
           {9.725379e-01, 5.391949e-01, 3.100000e-02, 0}             // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {4.320000e+00,
            4.740000e+00,
            5.154700e+00,
            5.571500e+00,
            5.988200e+00,
            6.404900e+00,
            6.821700e+00}, // SINR
           {9.826923e-01,
            8.974138e-01,
            6.994536e-01,
            3.868502e-01,
            1.291280e-01,
            2.080000e-02,
            1.000000e-03} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {4.570000e+00,
            5,
            5.429400e+00,
            5.858900e+00,
            6.288300e+00,
            6.717700e+00,
            7.150000e+00,
            7.580000e+00}, // SINR
           {9.790076e-01,
            8.576159e-01,
            5.801136e-01,
            2.339385e-01,
            5.650000e-02,
            6.900000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {4.800000e+00, 5.645000e+00, 6.490000e+00, 7.335000e+00, 8.180000e+00}, // SINR
           {9.310662e-01, 3.779851e-01, 1.660000e-02, 1.000000e-04, 0}             // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {4.760000e+00,
            5.110300e+00,
            5.460200e+00,
            5.810000e+00,
            6.159800e+00,
            6.509700e+00,
            6.860000e+00,
            7.210000e+00}, // SINR
           {9.452555e-01,
            7.965839e-01,
            5.160643e-01,
            2.287523e-01,
            6.060000e-02,
            8.400000e-03,
            9.000000e-04,
            1.000000e-04} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {4.790000e+00,
            5.110300e+00,
            5.434200e+00,
            5.758000e+00,
            6.081900e+00,
            6.405800e+00,
            6.730000e+00,
            7.050000e+00}, // SINR
           {9.452555e-01,
            7.908951e-01,
            5.132653e-01,
            2.284483e-01,
            6.920000e-02,
            1.210000e-02,
            1.000000e-03,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {4.819800e+00,
            5.264400e+00,
            5.709000e+00,
            6.153600e+00,
            6.598200e+00,
            7.040000e+00}, // SINR
           {9.420290e-01,
            6.521465e-01,
            2.504990e-01,
            3.670000e-02,
            2.800000e-03,
            1.000000e-04} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {4.875000e+00, 5.351600e+00, 5.828300e+00, 6.304900e+00, 6.781500e+00}, // SINR
           {9.293478e-01, 6.066351e-01, 1.651316e-01, 1.500000e-02, 5.000000e-04}  // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {4.657300e+00, 5.160100e+00, 5.662900e+00, 6.165700e+00, 6.668500e+00}, // SINR
           {9.769231e-01, 7.712121e-01, 2.621888e-01, 2.010000e-02, 2.000000e-04}  // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {4.650000e+00, 5, 5.350000e+00, 5.700000e+00, 6.050000e+00, 6.400000e+00}, // SINR
           {9.865385e-01,
            8.842905e-01,
            5.004883e-01,
            1.488731e-01,
            1.600000e-02,
            7.000000e-04} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {4.870600e+00, 5.274300e+00, 5.677900e+00, 6.081600e+00, 6.485300e+00}, // SINR
           {9.388489e-01, 5.990566e-01, 1.621622e-01, 1.080000e-02, 0}             // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {4.950000e+00,
            5.275000e+00,
            5.600000e+00,
            5.925000e+00,
            6.250000e+00,
            6.580000e+00},                                                           // SINR
           {9.125000e-01, 6.225490e-01, 2.145586e-01, 3.270000e-02, 1.500000e-03, 0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {5, 5.300000e+00, 5.600000e+00, 5.900000e+00, 6.200000e+00, 6.500000e+00}, // SINR
           {9.020979e-01, 5.946262e-01, 1.970173e-01, 2.590000e-02, 2.000000e-03, 0}  // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {4.800400e+00, 5.300400e+00, 5.800400e+00, 6.300400e+00, 6.800400e+00}, // SINR
           {9.807692e-01, 5.527174e-01, 4.590000e-02, 4.000000e-04, 0}             // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {5.078800e+00,
            5.364300e+00,
            5.649800e+00,
            5.935300e+00,
            6.220800e+00,
            6.510000e+00},                                                           // SINR
           {9.208633e-01, 6.532051e-01, 2.350467e-01, 3.230000e-02, 1.200000e-03, 0} // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {5.100000e+00,
            5.425000e+00,
            5.750000e+00,
            6.075000e+00,
            6.400000e+00,
            6.730000e+00,
            7.050000e+00}, // SINR
           {9.788462e-01,
            7.812500e-01,
            3.688227e-01,
            7.460000e-02,
            4.600000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {5.200000e+00,
            5.475000e+00,
            5.750000e+00,
            6.025000e+00,
            6.300000e+00,
            6.570000e+00,
            6.850000e+00}, // SINR
           {9.512868e-01,
            7.238701e-01,
            3.361037e-01,
            7.890000e-02,
            7.400000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {4.603200e+00, 5.300800e+00, 5.998400e+00, 6.696000e+00}, // SINR
           {1, 8.245192e-01, 4.870000e-02, 0}                        // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {4.800000e+00, 5.250000e+00, 5.700000e+00, 6.150000e+00, 6.600000e+00}, // SINR
           {9.951923e-01, 7.581361e-01, 1.079004e-01, 8.000000e-04, 1.000000e-04}  // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {4.900000e+00, 5.200000e+00, 5.500000e+00, 5.800000e+00, 6.100000e+00}, // SINR
           {9.932692e-01, 8.406863e-01, 3.396667e-01, 4.320000e-02, 9.000000e-04}  // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {4.700000e+00, 5.100000e+00, 5.500000e+00, 5.900000e+00, 6.300000e+00}, // SINR
           {1, 9.452555e-01, 3.825529e-01, 1.560000e-02, 2.000000e-04}             // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {5.060000e+00, 5.380000e+00, 5.700000e+00, 6.025000e+00, 6.350000e+00}, // SINR
           {9.434307e-01, 5.459402e-01, 7.560000e-02, 1.400000e-03, 0}             // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {5.010000e+00,
            5.260000e+00,
            5.510000e+00,
            5.763800e+00,
            6.014800e+00,
            6.265900e+00},                                                           // SINR
           {9.798077e-01, 7.771084e-01, 3.074572e-01, 3.700000e-02, 1.000000e-03, 0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {5.090000e+00,
            5.330000e+00,
            5.570000e+00,
            5.809700e+00,
            6.051800e+00,
            6.293800e+00},                                                           // SINR
           {9.397482e-01, 5.925926e-01, 1.595102e-01, 1.490000e-02, 2.000000e-04, 0} // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {4.970000e+00, 5.260000e+00, 5.550000e+00, 5.837700e+00, 6.129000e+00}, // SINR
           {9.817308e-01, 7.092541e-01, 1.541054e-01, 6.200000e-03, 0}             // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {4.890000e+00, 5.347700e+00, 5.808800e+00, 6.270000e+00}, // SINR
           {1, 5.647124e-01, 7.800000e-03, 0}                        // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {5.020000e+00,
            5.190000e+00,
            5.360000e+00,
            5.540000e+00,
            5.710000e+00,
            5.883800e+00,
            6.058800e+00}, // SINR
           {9.706439e-01,
            8.164557e-01,
            4.750940e-01,
            1.271508e-01,
            1.640000e-02,
            7.000000e-04,
            0} // BLER
       }},
      {3240U, // SINR and BLER for CBS 3240
       MmWaveEesmErrorModel::DoubleTuple{
           {5.300000e+00,
            5.630000e+00,
            5.800000e+00,
            5.970000e+00,
            6.300000e+00,
            6.800000e+00},                                                           // SINR
           {9.732824e-01, 5.795455e-01, 2.252232e-01, 4.400000e-02, 2.000000e-04, 0} // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {4.911500e+00, 5.370000e+00, 5.597200e+00, 5.830000e+00, 6.282900e+00}, // SINR
           {9.971154e-01, 6.925134e-01, 2.070957e-01, 1.310000e-02, 0}             // BLER
       }}},
     {      // MCS 10
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {5.280000e+00, 5.540000e+00, 5.805400e+00, 6.066800e+00, 6.328300e+00,
            6.589800e+00, 6.851200e+00, 7.110000e+00, 7.370000e+00, 7.640000e+00,
            7.900000e+00, 8.160000e+00, 8.420000e+00, 8.680000e+00, 8.940000e+00,
            9.200000e+00, 9.460000e+00, 9.720000e+00, 9.980000e+00, 1.025000e+01,
            1.051000e+01, 1.077000e+01, 1.103000e+01, 1.129000e+01, 1.155000e+01}, // SINR
           {9.093310e-01, 8.800676e-01, 8.443709e-01, 7.850610e-01, 7.327586e-01,
            6.645078e-01, 5.858295e-01, 5.084661e-01, 4.192881e-01, 3.390457e-01,
            2.587629e-01, 1.957878e-01, 1.394444e-01, 9.657702e-02, 6.560000e-02,
            4.370000e-02, 2.610000e-02, 1.420000e-02, 8.900000e-03, 3.700000e-03,
            1.600000e-03, 9.000000e-04, 3.000000e-04, 3.000000e-04, 1.000000e-04} // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {5.010000e+00, 5.270000e+00, 5.530000e+00, 5.787500e+00, 6.048100e+00, 6.308700e+00,
            6.569400e+00, 6.830000e+00, 7.090000e+00, 7.350000e+00, 7.610000e+00, 7.870000e+00,
            8.130000e+00, 8.390000e+00, 8.650000e+00, 8.920000e+00, 9.180000e+00, 9.440000e+00,
            9.700000e+00, 9.960000e+00, 1.022000e+01, 1.048000e+01, 1.074000e+01, 11}, // SINR
           {9.273050e-01, 8.940972e-01, 8.551325e-01, 8.042453e-01, 7.321429e-01, 6.516497e-01,
            5.717489e-01, 4.852662e-01, 4.103084e-01, 3.210660e-01, 2.427885e-01, 1.731431e-01,
            1.159639e-01, 7.440000e-02, 4.390000e-02, 2.480000e-02, 1.360000e-02, 7.600000e-03,
            4.400000e-03, 1.900000e-03, 6.000000e-04, 6.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {5.180000e+00,
            5.450000e+00,
            5.723600e+00,
            5.994900e+00,
            6.266200e+00,
            6.537500e+00,
            6.808800e+00,
            7.080000e+00,
            7.350000e+00,
            7.620000e+00,
            7.890000e+00,
            8.170000e+00,
            8.440000e+00,
            8.710000e+00,
            8.980000e+00,
            9.250000e+00,
            9.520000e+00,
            9.790000e+00,
            1.006000e+01}, // SINR
           {9.095745e-01,
            8.666667e-01,
            8.136792e-01,
            7.271429e-01,
            6.468750e-01,
            5.573144e-01,
            4.586331e-01,
            3.580028e-01,
            2.617188e-01,
            1.795422e-01,
            1.169543e-01,
            7.060000e-02,
            3.960000e-02,
            1.990000e-02,
            9.500000e-03,
            4.700000e-03,
            1.900000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {5.100000e+00,
            5.478200e+00,
            5.857700e+00,
            6.237100e+00,
            6.616600e+00,
            6.996100e+00,
            7.380000e+00,
            7.760000e+00,
            8.130000e+00,
            8.510000e+00,
            8.890000e+00,
            9.270000e+00,
            9.650000e+00,
            1.003000e+01,
            1.041000e+01}, // SINR
           {9.375000e-01,
            8.625000e-01,
            7.588235e-01,
            6.381910e-01,
            4.975490e-01,
            3.419811e-01,
            2.046926e-01,
            1.074523e-01,
            4.730000e-02,
            1.590000e-02,
            5.600000e-03,
            1.900000e-03,
            5.000000e-04,
            4.000000e-04,
            0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {5.200000e+00, 5.390000e+00, 5.580000e+00, 5.760000e+00, 5.950000e+00, 6.137500e+00,
            6.325000e+00, 6.512500e+00, 6.700000e+00, 6.890000e+00, 7.080000e+00, 7.260000e+00,
            7.450000e+00, 7.640000e+00, 7.830000e+00, 8.010000e+00, 8.200000e+00, 8.390000e+00,
            8.570000e+00, 8.760000e+00, 8.950000e+00, 9.140000e+00, 9.320000e+00, 9.510000e+00,
            9.700000e+00, 9.880000e+00}, // SINR
           {9.064685e-01, 8.640203e-01,
            8.221154e-01, 7.740964e-01,
            6.967213e-01, 6.366995e-01,
            5.524892e-01, 4.755639e-01,
            3.928571e-01, 3.170426e-01,
            2.407143e-01, 1.852876e-01,
            1.372683e-01, 9.567268e-02,
            6.330000e-02, 4.090000e-02,
            2.270000e-02, 1.300000e-02,
            7.600000e-03, 4.000000e-03,
            2.000000e-03, 9.000000e-04,
            4.000000e-04, 2.000000e-04,
            1.000000e-04, 0} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {5.150000e+00,
            5.400000e+00,
            5.650000e+00,
            5.900000e+00,
            6.150000e+00,
            6.400000e+00,
            6.650000e+00,
            6.900000e+00,
            7.150000e+00,
            7.400000e+00,
            7.650000e+00,
            7.900000e+00,
            8.150000e+00,
            8.400000e+00,
            8.650000e+00,
            8.900000e+00,
            9.150000e+00}, // SINR
           {9.276786e-01,
            8.750000e-01,
            8.093750e-01,
            7.278571e-01,
            6.147343e-01,
            5.121457e-01,
            4.050481e-01,
            3.033573e-01,
            2.046748e-01,
            1.360931e-01,
            8.020000e-02,
            4.300000e-02,
            2.150000e-02,
            1.020000e-02,
            3.500000e-03,
            1.800000e-03,
            2.000000e-04} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {4.850000e+00,
            5.286800e+00,
            5.719700e+00,
            6.152500e+00,
            6.585400e+00,
            7.018300e+00,
            7.450000e+00,
            7.880000e+00,
            8.320000e+00,
            8.750000e+00,
            9.180000e+00,
            9.620000e+00}, // SINR
           {9.533582e-01,
            8.977273e-01,
            7.856061e-01,
            6.105072e-01,
            3.990536e-01,
            2.186957e-01,
            9.100965e-02,
            3.160000e-02,
            7.300000e-03,
            1.300000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {4.860000e+00,
            5.286800e+00,
            5.716600e+00,
            6.146400e+00,
            6.576300e+00,
            7.006100e+00,
            7.440000e+00,
            7.870000e+00,
            8.300000e+00,
            8.730000e+00,
            9.160000e+00,
            9.590000e+00}, // SINR
           {9.592593e-01,
            8.898601e-01,
            7.782012e-01,
            5.883028e-01,
            3.666667e-01,
            1.908194e-01,
            7.250000e-02,
            2.280000e-02,
            5.600000e-03,
            9.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {5.213200e+00,
            5.646100e+00,
            6.078900e+00,
            6.511800e+00,
            6.944700e+00,
            7.380000e+00,
            7.810000e+00,
            8.240000e+00,
            8.680000e+00,
            9.110000e+00,
            9.540000e+00}, // SINR
           {9.140071e-01,
            8.046875e-01,
            6.031840e-01,
            3.798799e-01,
            1.955426e-01,
            7.330000e-02,
            1.990000e-02,
            3.500000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {5.221400e+00,
            5.647100e+00,
            6.072900e+00,
            6.498700e+00,
            6.924400e+00,
            7.350000e+00,
            7.780000e+00,
            8.200000e+00,
            8.630000e+00,
            9.050000e+00,
            9.480000e+00}, // SINR
           {9.175532e-01,
            7.940252e-01,
            5.934579e-01,
            3.783683e-01,
            1.724315e-01,
            5.560000e-02,
            1.400000e-02,
            2.500000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {5.170000e+00,
            5.470000e+00,
            5.772800e+00,
            6.073700e+00,
            6.374600e+00,
            6.675600e+00,
            6.976500e+00,
            7.280000e+00,
            7.580000e+00,
            7.880000e+00,
            8.180000e+00,
            8.480000e+00,
            8.780000e+00,
            9.080000e+00}, // SINR
           {9.223214e-01,
            8.633333e-01,
            7.551775e-01,
            6.061321e-01,
            4.279661e-01,
            2.622141e-01,
            1.367358e-01,
            5.790000e-02,
            2.210000e-02,
            7.300000e-03,
            1.500000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {5.310000e+00,
            5.660800e+00,
            6.011100e+00,
            6.361400e+00,
            6.711800e+00,
            7.062100e+00,
            7.410000e+00,
            7.760000e+00,
            8.110000e+00,
            8.460000e+00,
            8.810000e+00,
            9.160000e+00,
            9.510000e+00}, // SINR
           {9.241071e-01,
            8.066038e-01,
            6.268382e-01,
            4.035714e-01,
            2.032767e-01,
            8.390000e-02,
            2.730000e-02,
            7.500000e-03,
            2.200000e-03,
            4.000000e-04,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {5.310000e+00,
            5.616700e+00,
            5.927300e+00,
            6.237800e+00,
            6.548400e+00,
            6.859000e+00,
            7.170000e+00,
            7.480000e+00,
            7.790000e+00,
            8.100000e+00,
            8.410000e+00}, // SINR
           {9.258929e-01,
            8.128931e-01,
            6.350000e-01,
            4.147727e-01,
            2.250000e-01,
            8.520000e-02,
            2.470000e-02,
            6.600000e-03,
            1.100000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {5.290000e+00,
            5.625000e+00,
            5.963600e+00,
            6.302300e+00,
            6.641000e+00,
            6.979600e+00,
            7.320000e+00,
            7.660000e+00,
            8,
            8.330000e+00,
            8.670000e+00}, // SINR
           {9.253597e-01,
            7.989130e-01,
            5.873843e-01,
            3.497230e-01,
            1.425936e-01,
            4.090000e-02,
            8.300000e-03,
            1.600000e-03,
            3.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {5.340000e+00,
            5.662400e+00,
            5.984800e+00,
            6.307300e+00,
            6.629800e+00,
            6.952200e+00,
            7.270000e+00,
            7.600000e+00,
            7.920000e+00,
            8.240000e+00,
            8.560000e+00}, // SINR
           {9.217626e-01,
            8.000000e-01,
            6.135266e-01,
            3.573446e-01,
            1.480224e-01,
            4.160000e-02,
            8.300000e-03,
            1.000000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {5.300000e+00,
            5.490000e+00,
            5.680000e+00,
            5.860000e+00,
            6.050000e+00,
            6.237500e+00,
            6.425000e+00,
            6.612500e+00,
            6.800000e+00,
            6.990000e+00,
            7.180000e+00,
            7.360000e+00,
            7.550000e+00,
            7.740000e+00,
            7.930000e+00,
            8.110000e+00}, // SINR
           {9.397810e-01,
            8.724662e-01,
            7.939815e-01,
            6.708115e-01,
            5.204082e-01,
            3.635714e-01,
            2.282609e-01,
            1.267659e-01,
            6.460000e-02,
            2.720000e-02,
            9.700000e-03,
            3.700000e-03,
            1.500000e-03,
            6.000000e-04,
            3.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {5.220000e+00,
            5.440000e+00,
            5.660000e+00,
            5.878100e+00,
            6.094500e+00,
            6.311000e+00,
            6.527400e+00,
            6.743800e+00,
            6.960000e+00,
            7.180000e+00,
            7.390000e+00,
            7.610000e+00,
            7.830000e+00}, // SINR
           {9.485294e-01,
            8.932292e-01,
            7.812500e-01,
            6.317402e-01,
            4.618182e-01,
            2.871315e-01,
            1.484099e-01,
            6.400000e-02,
            2.510000e-02,
            6.900000e-03,
            1.800000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {5.370000e+00,
            5.580000e+00,
            5.790000e+00,
            5.997400e+00,
            6.203800e+00,
            6.410200e+00,
            6.616700e+00,
            6.823100e+00,
            7.030000e+00,
            7.240000e+00,
            7.440000e+00,
            7.650000e+00,
            7.860000e+00}, // SINR
           {9.370504e-01,
            8.495066e-01,
            7.178771e-01,
            5.307292e-01,
            3.428284e-01,
            1.858358e-01,
            8.560000e-02,
            3.180000e-02,
            9.200000e-03,
            1.600000e-03,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {5.290000e+00,
            5.540000e+00,
            5.790000e+00,
            6.039200e+00,
            6.289100e+00,
            6.539000e+00,
            6.788900e+00,
            7.038800e+00,
            7.290000e+00,
            7.540000e+00}, // SINR
           {9.466912e-01,
            8.583333e-01,
            7.090278e-01,
            4.792453e-01,
            2.514940e-01,
            1.005165e-01,
            2.800000e-02,
            6.600000e-03,
            1.100000e-03,
            2.000000e-04} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {5.380000e+00,
            5.600000e+00,
            5.820000e+00,
            6.042000e+00,
            6.266700e+00,
            6.491400e+00,
            6.716100e+00,
            6.940800e+00,
            7.170000e+00,
            7.390000e+00}, // SINR
           {9.276786e-01,
            8.197115e-01,
            6.535533e-01,
            4.543011e-01,
            2.540080e-01,
            1.072826e-01,
            3.560000e-02,
            7.400000e-03,
            2.100000e-03,
            7.000000e-04} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {5.290000e+00,
            5.510000e+00,
            5.730000e+00,
            5.955500e+00,
            6.177300e+00,
            6.399100e+00,
            6.620900e+00,
            6.842700e+00,
            7.060000e+00,
            7.290000e+00,
            7.510000e+00}, // SINR
           {9.633459e-01,
            8.888889e-01,
            7.307143e-01,
            5.280083e-01,
            3.207071e-01,
            1.497024e-01,
            5.060000e-02,
            1.530000e-02,
            3.600000e-03,
            7.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {5.410000e+00,
            5.580000e+00,
            5.750000e+00,
            5.910000e+00,
            6.078800e+00,
            6.245300e+00,
            6.411700e+00,
            6.578100e+00,
            6.744600e+00,
            6.910000e+00,
            7.080000e+00,
            7.240000e+00,
            7.410000e+00}, // SINR
           {9.148936e-01,
            8.443709e-01,
            7.298851e-01,
            5.801136e-01,
            3.936916e-01,
            2.267599e-01,
            1.124664e-01,
            5.050000e-02,
            1.860000e-02,
            6.000000e-03,
            1.700000e-03,
            7.000000e-04,
            2.000000e-04} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {5.212200e+00, 5.841500e+00, 6.470800e+00, 7.100100e+00, 7.729400e+00}, // SINR
           {9.755639e-01, 6.458333e-01, 8.470000e-02, 1.400000e-03, 0}             // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {5.474600e+00,
            5.877300e+00,
            6.280000e+00,
            6.682700e+00,
            7.085400e+00,
            7.490000e+00}, // SINR
           {9.271583e-01,
            5.994186e-01,
            1.670561e-01,
            1.430000e-02,
            1.100000e-03,
            2.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {5.296500e+00, 5.824400e+00, 6.352300e+00, 6.880300e+00, 7.408200e+00}, // SINR
           {9.721154e-01, 6.451005e-01, 7.900000e-02, 6.000000e-04, 0}             // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {5.400000e+00, 5.700000e+00, 6, 6.300000e+00, 6.600000e+00, 6.900000e+00}, // SINR
           {9.542910e-01,
            7.603550e-01,
            3.884202e-01,
            9.491115e-02,
            9.800000e-03,
            1.000000e-04} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {5.200000e+00, 5.775000e+00, 6.350000e+00, 6.925000e+00, 7.500000e+00}, // SINR
           {9.942308e-01, 7.028689e-01, 6.020000e-02, 5.000000e-04, 1.000000e-04}  // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {5.263800e+00, 5.764800e+00, 6.265900e+00, 6.766900e+00, 7.267900e+00}, // SINR
           {9.932692e-01, 7.104167e-01, 8.300000e-02, 1.100000e-03, 0}             // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {5.188100e+00, 5.650100e+00, 6.112000e+00, 6.573900e+00, 7.035900e+00}, // SINR
           {9.990385e-01, 8.117188e-01, 1.900530e-01, 4.600000e-03, 3.000000e-04}  // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {5.264500e+00, 5.789200e+00, 6.313900e+00, 6.838600e+00, 7.363300e+00}, // SINR
           {9.990385e-01, 7.804878e-01, 7.910000e-02, 5.000000e-04, 0}             // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {5.292700e+00, 5.780500e+00, 6.268400e+00, 6.756300e+00, 7.244100e+00}, // SINR
           {9.990385e-01, 9.357143e-01, 3.691860e-01, 1.270000e-02, 1.000000e-04}  // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {5.124600e+00, 5.640800e+00, 6.157000e+00, 6.673300e+00, 7.189500e+00}, // SINR
           {1, 9.807692e-01, 5.121457e-01, 1.930000e-02, 0}                        // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {5.288700e+00, 5.848500e+00, 6.408300e+00, 6.968100e+00}, // SINR
           {1, 8.750000e-01, 9.950249e-02, 0}                        // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {5.247800e+00, 5.916000e+00, 6.584100e+00, 7.252300e+00, 7.920500e+00}, // SINR
           {1, 8.495066e-01, 1.690000e-02, 1.000000e-04, 0}                        // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {5.250000e+00, 5.898000e+00, 6.546100e+00, 7.194100e+00, 7.842100e+00}, // SINR
           {1, 8.827055e-01, 1.950000e-02, 1.000000e-04, 0}                        // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {5.566200e+00, 6.093800e+00, 6.621400e+00, 7.149000e+00}, // SINR
           {9.875000e-01, 4.569892e-01, 3.300000e-03, 0}             // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {5.610000e+00, 6.033800e+00, 6.457900e+00, 6.881900e+00}, // SINR
           {9.923077e-01, 6.348522e-01, 3.430000e-02, 0}             // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {5.580000e+00, 6.016500e+00, 6.454900e+00, 6.893300e+00}, // SINR
           {9.942308e-01, 5.691964e-01, 1.080000e-02, 0}             // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {5.330000e+00, 5.823100e+00, 6.315400e+00, 6.807700e+00, 7.300000e+00}, // SINR
           {1, 8.690068e-01, 5.350000e-02, 1.000000e-04, 0}                        // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {5.490000e+00, 5.780000e+00, 6.070000e+00, 6.363100e+00, 6.655000e+00}, // SINR
           {1, 8.968531e-01, 3.569915e-01, 1.790000e-02, 0}                        // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {5.450000e+00, 5.990000e+00, 6.262500e+00, 6.530000e+00, 7.075000e+00}, // SINR
           {1, 5.968310e-01, 6.400000e-02, 1.000000e-03, 0}                        // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {5.710000e+00, 6.050000e+00, 6.390000e+00, 6.730800e+00}, // SINR
           {9.732824e-01, 3.656069e-01, 6.200000e-03, 0}             // BLER
       }},
      {3240U, // SINR and BLER for CBS 3240
       MmWaveEesmErrorModel::DoubleTuple{
           {5.930000e+00,
            6.180000e+00,
            6.300000e+00,
            6.430000e+00,
            6.675000e+00,
            7.050000e+00,
            7.425000e+00}, // SINR
           {9.402174e-01,
            4.927885e-01,
            2.136824e-01,
            4.870000e-02,
            8.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {5.730000e+00, 6.134900e+00, 6.534900e+00, 6.934900e+00}, // SINR
           {9.903846e-01, 3.794776e-01, 1.600000e-03, 0}             // BLER
       }}},
     {      // MCS 11
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {6.124900e+00, 6.561400e+00, 6.997900e+00, 7.434400e+00, 7.870900e+00,
            8.310000e+00, 8.740000e+00, 9.180000e+00, 9.620000e+00, 1.005000e+01,
            1.049000e+01, 1.093000e+01, 1.136000e+01, 1.180000e+01, 1.224000e+01,
            1.268000e+01, 1.311000e+01, 1.355000e+01, 1.399000e+01, 1.442000e+01}, // SINR
           {9.807692e-01, 9.568015e-01, 9.329710e-01, 8.724662e-01, 8.081761e-01,
            7.231638e-01, 5.924419e-01, 4.797932e-01, 3.618608e-01, 2.475490e-01,
            1.596692e-01, 9.248788e-02, 4.850000e-02, 2.280000e-02, 9.100000e-03,
            3.300000e-03, 1.700000e-03, 5.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {6.300000e+00,
            6.675000e+00,
            7.050000e+00,
            7.425000e+00,
            7.800000e+00,
            8.180000e+00,
            8.550000e+00,
            8.930000e+00,
            9.300000e+00,
            9.680000e+00,
            1.005000e+01,
            1.043000e+01,
            1.080000e+01,
            1.118000e+01,
            1.155000e+01,
            1.193000e+01,
            1.230000e+01,
            1.268000e+01}, // SINR
           {9.425182e-01,
            9.113475e-01,
            8.608333e-01,
            7.778614e-01,
            6.763158e-01,
            5.514069e-01,
            4.460526e-01,
            3.273964e-01,
            2.170259e-01,
            1.300206e-01,
            7.100000e-02,
            3.610000e-02,
            1.660000e-02,
            8.000000e-03,
            3.400000e-03,
            1.900000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {5.983800e+00,
            6.427300e+00,
            6.870800e+00,
            7.314300e+00,
            7.757800e+00,
            8.200000e+00,
            8.640000e+00,
            9.090000e+00,
            9.530000e+00,
            9.980000e+00,
            1.042000e+01,
            1.086000e+01,
            1.131000e+01,
            1.175000e+01,
            1.219000e+01}, // SINR
           {9.476103e-01,
            8.975694e-01,
            8.205128e-01,
            7.176966e-01,
            5.686384e-01,
            4.088710e-01,
            2.492545e-01,
            1.400670e-01,
            6.700000e-02,
            2.400000e-02,
            8.100000e-03,
            2.100000e-03,
            6.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {6.204500e+00,
            6.568200e+00,
            6.931900e+00,
            7.295600e+00,
            7.659300e+00,
            8.020000e+00,
            8.390000e+00,
            8.750000e+00,
            9.110000e+00,
            9.480000e+00,
            9.840000e+00,
            1.021000e+01,
            1.057000e+01,
            1.093000e+01,
            1.130000e+01}, // SINR
           {9.047203e-01,
            8.333333e-01,
            7.529412e-01,
            6.532051e-01,
            5.024606e-01,
            3.600427e-01,
            2.348414e-01,
            1.299274e-01,
            6.250000e-02,
            2.490000e-02,
            9.400000e-03,
            2.600000e-03,
            7.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {6.050000e+00,
            6.401200e+00,
            6.751100e+00,
            7.101000e+00,
            7.450900e+00,
            7.800800e+00,
            8.150000e+00,
            8.500000e+00,
            8.850000e+00,
            9.200000e+00,
            9.550000e+00,
            9.900000e+00,
            1.025000e+01,
            1.060000e+01,
            1.095000e+01}, // SINR
           {9.095745e-01,
            8.462171e-01,
            7.456395e-01,
            6.165459e-01,
            4.699074e-01,
            3.240385e-01,
            1.983909e-01,
            1.137201e-01,
            5.370000e-02,
            2.300000e-02,
            9.100000e-03,
            1.700000e-03,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {5.710000e+00,
            6.060000e+00,
            6.405700e+00,
            6.753800e+00,
            7.101900e+00,
            7.450000e+00,
            7.798100e+00,
            8.150000e+00,
            8.490000e+00,
            8.840000e+00,
            9.190000e+00,
            9.540000e+00,
            9.890000e+00,
            1.023000e+01}, // SINR
           {9.437500e-01,
            8.942308e-01,
            8.061709e-01,
            6.821809e-01,
            5.319038e-01,
            3.829787e-01,
            2.480315e-01,
            1.457373e-01,
            7.440000e-02,
            2.880000e-02,
            1.050000e-02,
            2.500000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {5.430000e+00,
            5.900000e+00,
            6.368800e+00,
            6.837500e+00,
            7.306300e+00,
            7.775000e+00,
            8.240000e+00,
            8.710000e+00,
            9.180000e+00,
            9.650000e+00,
            1.012000e+01}, // SINR
           {9.574074e-01,
            8.880208e-01,
            7.558824e-01,
            5.745516e-01,
            3.648844e-01,
            1.829710e-01,
            6.760000e-02,
            1.980000e-02,
            3.700000e-03,
            7.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {6.006300e+00,
            6.381300e+00,
            6.756300e+00,
            7.131300e+00,
            7.506300e+00,
            7.880000e+00,
            8.260000e+00,
            8.630000e+00,
            9.010000e+00,
            9.380000e+00,
            9.760000e+00,
            1.013000e+01,
            1.051000e+01}, // SINR
           {9.708647e-01,
            9.208633e-01,
            8.196203e-01,
            6.649485e-01,
            4.913793e-01,
            3.092910e-01,
            1.555933e-01,
            6.910000e-02,
            2.370000e-02,
            6.000000e-03,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {6.020000e+00,
            6.387900e+00,
            6.758700e+00,
            7.129600e+00,
            7.500400e+00,
            7.871200e+00,
            8.240000e+00,
            8.610000e+00,
            8.980000e+00,
            9.350000e+00,
            9.730000e+00}, // SINR
           {9.343525e-01,
            8.485099e-01,
            7.434593e-01,
            5.559211e-01,
            3.560393e-01,
            1.818017e-01,
            7.680000e-02,
            2.380000e-02,
            4.700000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {6,
            6.230000e+00,
            6.464400e+00,
            6.694600e+00,
            6.924900e+00,
            7.155100e+00,
            7.385300e+00,
            7.620000e+00,
            7.850000e+00,
            8.080000e+00,
            8.310000e+00,
            8.540000e+00,
            8.770000e+00,
            9,
            9.230000e+00,
            9.460000e+00}, // SINR
           {9.361314e-01,
            8.913793e-01,
            8.282258e-01,
            7.363506e-01,
            6.318750e-01,
            4.951172e-01,
            3.688047e-01,
            2.477941e-01,
            1.538344e-01,
            8.260000e-02,
            4.210000e-02,
            1.950000e-02,
            7.500000e-03,
            2.800000e-03,
            1.000000e-03,
            0} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {6,
            6.344700e+00,
            6.689400e+00,
            7.034100e+00,
            7.378800e+00,
            7.720000e+00,
            8.070000e+00,
            8.410000e+00,
            8.760000e+00,
            9.100000e+00,
            9.450000e+00,
            9.790000e+00}, // SINR
           {9.169643e-01,
            8.245192e-01,
            6.662304e-01,
            4.515125e-01,
            2.482776e-01,
            1.115556e-01,
            3.620000e-02,
            1.050000e-02,
            1.500000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {6.067600e+00,
            6.356800e+00,
            6.646000e+00,
            6.935100e+00,
            7.224300e+00,
            7.510000e+00,
            7.800000e+00,
            8.090000e+00,
            8.380000e+00,
            8.670000e+00,
            8.960000e+00,
            9.250000e+00}, // SINR
           {9.003497e-01,
            7.945313e-01,
            6.213415e-01,
            4.308874e-01,
            2.468075e-01,
            1.120145e-01,
            3.850000e-02,
            1.060000e-02,
            2.100000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {5.790000e+00,
            6.200000e+00,
            6.612300e+00,
            7.024700e+00,
            7.437000e+00,
            7.849300e+00,
            8.260000e+00,
            8.670000e+00,
            9.090000e+00}, // SINR
           {9.633459e-01,
            8.544408e-01,
            6.231618e-01,
            3.165829e-01,
            9.817772e-02,
            1.860000e-02,
            1.800000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {5.750000e+00,
            6.162800e+00,
            6.573900e+00,
            6.984900e+00,
            7.396000e+00,
            7.807100e+00,
            8.220000e+00,
            8.630000e+00,
            9.040000e+00}, // SINR
           {9.501812e-01,
            8.390523e-01,
            6.059524e-01,
            2.958824e-01,
            8.848315e-02,
            1.460000e-02,
            8.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {5.920000e+00,
            6.180000e+00,
            6.440000e+00,
            6.698600e+00,
            6.959500e+00,
            7.220400e+00,
            7.481400e+00,
            7.742300e+00,
            8,
            8.260000e+00,
            8.530000e+00,
            8.790000e+00,
            9.050000e+00}, // SINR
           {9.568015e-01,
            8.986014e-01,
            7.820122e-01,
            6.183252e-01,
            4.306973e-01,
            2.397619e-01,
            1.082317e-01,
            3.950000e-02,
            1.190000e-02,
            2.800000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {6.013800e+00,
            6.356800e+00,
            6.699900e+00,
            7.043000e+00,
            7.386000e+00,
            7.730000e+00,
            8.070000e+00,
            8.420000e+00,
            8.760000e+00}, // SINR
           {9.196429e-01,
            7.786145e-01,
            5.219388e-01,
            2.463307e-01,
            7.630000e-02,
            1.470000e-02,
            1.900000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {6,
            6.290000e+00,
            6.578600e+00,
            6.866800e+00,
            7.154900e+00,
            7.443100e+00,
            7.731300e+00,
            8.020000e+00,
            8.310000e+00,
            8.600000e+00}, // SINR
           {9.289568e-01,
            7.958075e-01,
            5.737613e-01,
            3.052536e-01,
            1.251246e-01,
            3.800000e-02,
            8.600000e-03,
            1.800000e-03,
            5.000000e-04,
            2.000000e-04} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {6,
            6.220000e+00,
            6.443600e+00,
            6.665400e+00,
            6.887100e+00,
            7.108800e+00,
            7.330600e+00,
            7.550000e+00,
            7.770000e+00,
            8,
            8.220000e+00,
            8.440000e+00,
            8.660000e+00}, // SINR
           {9.433453e-01,
            8.708054e-01,
            7.448830e-01,
            5.641593e-01,
            3.596429e-01,
            1.851988e-01,
            7.760000e-02,
            2.600000e-02,
            7.000000e-03,
            1.700000e-03,
            2.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {5.850000e+00,
            6.070000e+00,
            6.290000e+00,
            6.510400e+00,
            6.726100e+00,
            6.941700e+00,
            7.157400e+00,
            7.373100e+00,
            7.590000e+00,
            7.800000e+00,
            8.020000e+00,
            8.240000e+00,
            8.450000e+00}, // SINR
           {9.570896e-01,
            8.986014e-01,
            7.881098e-01,
            6.095972e-01,
            4.083601e-01,
            2.244624e-01,
            9.718776e-02,
            3.460000e-02,
            9.700000e-03,
            2.100000e-03,
            7.000000e-04,
            2.000000e-04,
            1.000000e-04} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {5.870000e+00,
            6.168200e+00,
            6.464300e+00,
            6.760300e+00,
            7.056400e+00,
            7.352500e+00,
            7.650000e+00,
            7.940000e+00,
            8.240000e+00,
            8.540000e+00,
            8.830000e+00}, // SINR
           {9.614662e-01,
            8.439542e-01,
            6.178230e-01,
            3.500000e-01,
            1.265121e-01,
            3.260000e-02,
            4.100000e-03,
            8.000000e-04,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {6.084600e+00,
            6.359500e+00,
            6.634300e+00,
            6.909200e+00,
            7.184100e+00,
            7.460000e+00,
            7.730000e+00,
            8.010000e+00,
            8.280000e+00,
            8.560000e+00}, // SINR
           {9.020979e-01,
            7.449422e-01,
            4.765918e-01,
            2.195709e-01,
            6.900000e-02,
            1.290000e-02,
            2.300000e-03,
            5.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {5.815300e+00,
            6.208200e+00,
            6.601200e+00,
            6.994200e+00,
            7.387100e+00,
            7.780000e+00,
            8.170000e+00,
            8.570000e+00}, // SINR
           {9.770992e-01,
            8.464052e-01,
            4.921875e-01,
            1.325158e-01,
            1.730000e-02,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {6.100000e+00,
            6.300000e+00,
            6.502500e+00,
            6.704000e+00,
            6.905400e+00,
            7.106800e+00,
            7.308300e+00,
            7.510000e+00,
            7.710000e+00,
            7.910000e+00}, // SINR
           {9.175532e-01,
            7.880435e-01,
            5.608407e-01,
            3.312500e-01,
            1.450404e-01,
            5.210000e-02,
            1.300000e-02,
            3.900000e-03,
            8.000000e-04,
            3.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {5.900000e+00,
            6.275000e+00,
            6.650000e+00,
            7.025000e+00,
            7.400000e+00,
            7.780000e+00},                                                           // SINR
           {9.706439e-01, 7.908951e-01, 3.584040e-01, 5.620000e-02, 2.300000e-03, 0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {6.080000e+00,
            6.400000e+00,
            6.725000e+00,
            7.050000e+00,
            7.375000e+00,
            7.700000e+00}, // SINR
           {9.411765e-01,
            6.732804e-01,
            2.768053e-01,
            4.630000e-02,
            3.500000e-03,
            2.000000e-04} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {5.800000e+00, 6.400000e+00, 7, 7.600000e+00, 8.200000e+00}, // SINR
           {9.971154e-01, 7.220670e-01, 5.260000e-02, 3.000000e-04, 0}  // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {5.940000e+00,
            6.265400e+00,
            6.594600e+00,
            6.923800e+00,
            7.253100e+00,
            7.582300e+00},                                                           // SINR
           {9.855769e-01, 8.431373e-01, 3.970820e-01, 6.750000e-02, 3.800000e-03, 0} // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {5.800000e+00, 6.350000e+00, 6.900000e+00, 7.450000e+00, 8}, // SINR
           {9.951923e-01, 7.778614e-01, 8.510000e-02, 7.000000e-04, 0}  // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {6.100000e+00, 6.625000e+00, 7.150000e+00, 7.675000e+00}, // SINR
           {9.406934e-01, 2.770788e-01, 4.500000e-03, 0}             // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {5.900000e+00, 6.440000e+00, 6.712500e+00, 6.980000e+00, 7.525000e+00}, // SINR
           {9.923077e-01, 6.286765e-01, 2.048046e-01, 2.680000e-02, 0}             // BLER
       }},
      {1192U, // SINR and BLER for CBS 1192
       MmWaveEesmErrorModel::DoubleTuple{
           {6.200000e+00, 6.800000e+00, 7.100000e+00, 7.400000e+00, 8, 8.900000e+00}, // SINR
           {9.528986e-01, 2.197300e-01, 2.510000e-02, 1.000000e-03, 1.000000e-04, 0}  // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {5.950000e+00, 6.480000e+00, 6.737500e+00, 7, 7.525000e+00, 8.312500e+00}, // SINR
           {1, 8.552632e-01, 4.786932e-01, 1.262575e-01, 7.000000e-04, 0}             // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {6.348600e+00,
            6.730000e+00,
            6.916400e+00,
            7.110000e+00,
            7.484200e+00,
            8.052000e+00},                                                           // SINR
           {9.425182e-01, 4.441021e-01, 1.605314e-01, 3.420000e-02, 4.000000e-04, 0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {5.900000e+00, 6.462500e+00, 7.025000e+00, 7.587500e+00, 8.150000e+00}, // SINR
           {1, 8.792808e-01, 6.770000e-02, 2.000000e-04, 0}                        // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {5.800000e+00,
            6.306300e+00,
            6.640000e+00,
            6.812500e+00,
            6.980000e+00,
            7.318700e+00,
            7.825000e+00},                                                              // SINR
           {1, 9.652256e-01, 5.622247e-01, 2.663158e-01, 7.220000e-02, 6.000000e-04, 0} // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {6.200000e+00, 6.870000e+00, 7.200000e+00, 7.530000e+00}, // SINR
           {9.903846e-01, 1.610115e-01, 5.800000e-03, 0}             // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {6.010000e+00,
            6.390000e+00,
            6.769200e+00,
            7.145500e+00,
            7.521800e+00,
            7.898100e+00},                                                           // SINR
           {9.990385e-01, 8.835034e-01, 2.052696e-01, 3.200000e-03, 1.000000e-04, 0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {6.080000e+00,
            6.450000e+00,
            6.821000e+00,
            7.188500e+00,
            7.556100e+00,
            7.923700e+00,
            8.291200e+00}, // SINR
           {9.990385e-01,
            8.724490e-01,
            1.829446e-01,
            2.900000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {6.260000e+00,
            6.560000e+00,
            6.855400e+00,
            7.155800e+00,
            7.456200e+00,
            7.756600e+00},                                                           // SINR
           {9.687500e-01, 6.299505e-01, 8.480000e-02, 9.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {6.060000e+00, 6.470000e+00, 6.872300e+00, 7.278700e+00, 7.685100e+00}, // SINR
           {1, 8.043478e-01, 5.950000e-02, 1.000000e-04, 0}                        // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {6.410000e+00,
            6.720000e+00,
            6.871800e+00,
            7.030000e+00,
            7.338200e+00,
            7.804600e+00},                                                           // SINR
           {9.223214e-01, 2.946846e-01, 6.840000e-02, 6.400000e-03, 1.000000e-04, 0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {6.300000e+00,
            6.630000e+00,
            6.800000e+00,
            6.970000e+00,
            7.300000e+00,
            7.800000e+00},                                                           // SINR
           {9.826923e-01, 4.563849e-01, 1.075936e-01, 8.400000e-03, 2.000000e-04, 0} // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {6.220000e+00, 6.610000e+00, 7.004100e+00, 7.396600e+00, 7.789000e+00}, // SINR
           {9.951923e-01, 6.131517e-01, 1.170000e-02, 1.000000e-04, 0}             // BLER
       }}},
     {      // MCS 12
      {24U, // SINR and BLER for CBS 24
       MmWaveEesmErrorModel::DoubleTuple{
           {6.342900e+00,
            6.990600e+00,
            7.638300e+00,
            8.286000e+00,
            8.933700e+00,
            9.580000e+00,
            1.023000e+01,
            1.088000e+01,
            1.152000e+01,
            1.217000e+01,
            1.282000e+01,
            1.347000e+01,
            1.412000e+01,
            1.476000e+01}, // SINR
           {9.723282e-01,
            9.311594e-01,
            8.483333e-01,
            7.349138e-01,
            5.531116e-01,
            3.688227e-01,
            2.101419e-01,
            9.825820e-02,
            3.860000e-02,
            9.700000e-03,
            3.000000e-03,
            5.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {6.950000e+00,
            7.450000e+00,
            7.950000e+00,
            8.450000e+00,
            8.950000e+00,
            9.450000e+00,
            9.950000e+00,
            1.045000e+01,
            1.095000e+01,
            1.145000e+01,
            1.195000e+01,
            1.245000e+01,
            1.295000e+01,
            1.345000e+01,
            1.395000e+01}, // SINR
           {9.790076e-01,
            9.546296e-01,
            9.146127e-01,
            8.266129e-01,
            7.120166e-01,
            5.605727e-01,
            3.925234e-01,
            2.535425e-01,
            1.423925e-01,
            6.640000e-02,
            2.590000e-02,
            9.300000e-03,
            1.900000e-03,
            8.000000e-04,
            0} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {6.342900e+00,
            6.958900e+00,
            7.575000e+00,
            8.191000e+00,
            8.807000e+00,
            9.420000e+00,
            1.004000e+01,
            1.066000e+01,
            1.127000e+01,
            1.189000e+01,
            1.250000e+01,
            1.312000e+01}, // SINR
           {9.894231e-01,
            9.518519e-01,
            8.758503e-01,
            7.315341e-01,
            5.198171e-01,
            3.076456e-01,
            1.328042e-01,
            4.660000e-02,
            1.110000e-02,
            2.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {6.342900e+00,
            6.958900e+00,
            7.575000e+00,
            8.191000e+00,
            8.807000e+00,
            9.420000e+00,
            1.004000e+01,
            1.066000e+01}, // SINR
           {9.640152e-01,
            8.623311e-01,
            6.651554e-01,
            3.360000e-01,
            9.523322e-02,
            1.420000e-02,
            1.400000e-03,
            0} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {6.342900e+00,
            6.958900e+00,
            7.575000e+00,
            8.191000e+00,
            8.807000e+00,
            9.420000e+00,
            1.004000e+01,
            1.066000e+01}, // SINR
           {9.790076e-01,
            9.093310e-01,
            7.203390e-01,
            3.702624e-01,
            1.009330e-01,
            1.560000e-02,
            1.400000e-03,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {6.342900e+00,
            6.958900e+00,
            7.575000e+00,
            8.191000e+00,
            8.807000e+00,
            9.420000e+00,
            1.004000e+01,
            1.066000e+01}, // SINR
           {9.913462e-01,
            9.223214e-01,
            6.573834e-01,
            2.649685e-01,
            4.630000e-02,
            3.000000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {6.342900e+00,
            6.958900e+00,
            7.575000e+00,
            8.191000e+00,
            8.807000e+00,
            9.420000e+00,
            1.004000e+01}, // SINR
           {9.903846e-01,
            8.871528e-01,
            5.761364e-01,
            1.581344e-01,
            1.720000e-02,
            4.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {6.342900e+00,
            6.958900e+00,
            7.575000e+00,
            8.191000e+00,
            8.807000e+00,
            9.420000e+00,
            1.004000e+01,
            1.066000e+01}, // SINR
           {9.971154e-01,
            9.325540e-01,
            6.549745e-01,
            2.334730e-01,
            2.950000e-02,
            1.400000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {6.342900e+00,
            6.958900e+00,
            7.575000e+00,
            8.191000e+00,
            8.807000e+00,
            9.420000e+00,
            1.004000e+01}, // SINR
           {9.875000e-01,
            8.924825e-01,
            5.423820e-01,
            1.439783e-01,
            1.240000e-02,
            2.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00,
            7.318200e+00,
            7.677600e+00,
            8.036900e+00,
            8.396200e+00,
            8.760000e+00,
            9.110000e+00,
            9.470000e+00,
            9.830000e+00}, // SINR
           {9.075704e-01,
            7.383721e-01,
            4.758364e-01,
            2.077145e-01,
            5.970000e-02,
            1.080000e-02,
            1.300000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00,
            7.318200e+00,
            7.677600e+00,
            8.036900e+00,
            8.396200e+00,
            8.760000e+00,
            9.110000e+00,
            9.470000e+00,
            9.830000e+00}, // SINR
           {9.241071e-01,
            7.456140e-01,
            4.563849e-01,
            1.916031e-01,
            4.870000e-02,
            7.500000e-03,
            1.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00,
            7.420900e+00,
            7.883000e+00,
            8.345000e+00,
            8.807000e+00,
            9.270000e+00}, // SINR
           {9.298561e-01,
            6.949728e-01,
            2.999409e-01,
            5.680000e-02,
            3.900000e-03,
            1.000000e-04} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00,
            7.420900e+00,
            7.883000e+00,
            8.345000e+00,
            8.807000e+00,
            9.270000e+00},                                                           // SINR
           {9.276786e-01, 6.604381e-01, 2.669133e-01, 3.980000e-02, 2.300000e-03, 0} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {6.600000e+00,
            6.958900e+00,
            7.318200e+00,
            7.677600e+00,
            8.036900e+00,
            8.396200e+00,
            8.760000e+00,
            9.110000e+00,
            9.470000e+00}, // SINR
           {9.846154e-01,
            8.987676e-01,
            6.681937e-01,
            3.466530e-01,
            1.006426e-01,
            1.390000e-02,
            1.600000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {6.500000e+00,
            6.958900e+00,
            7.420900e+00,
            7.883000e+00,
            8.345000e+00,
            8.807000e+00}, // SINR
           {9.913462e-01,
            8.914931e-01,
            5.530303e-01,
            1.408175e-01,
            1.100000e-02,
            5.000000e-04} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {7.020000e+00,
            7.300000e+00,
            7.575000e+00,
            7.850000e+00,
            8.125000e+00,
            8.400000e+00,
            8.680000e+00,
            8.950000e+00,
            9.230000e+00}, // SINR
           {9.017241e-01,
            7.092541e-01,
            4.370690e-01,
            1.803957e-01,
            5.080000e-02,
            1.100000e-02,
            1.200000e-03,
            3.000000e-04,
            1.000000e-04} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {6.600000e+00,
            6.958900e+00,
            7.318200e+00,
            7.677600e+00,
            8.036900e+00,
            8.396200e+00,
            8.760000e+00}, // SINR
           {9.894231e-01,
            8.827586e-01,
            5.689462e-01,
            1.947900e-01,
            3.150000e-02,
            1.900000e-03,
            2.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00, 7.420900e+00, 7.883000e+00, 8.345000e+00, 8.807000e+00}, // SINR
           {9.388489e-01, 5.295643e-01, 8.240000e-02, 2.500000e-03, 1.000000e-04}  // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {6.650000e+00,
            6.958900e+00,
            7.266900e+00,
            7.574900e+00,
            7.882900e+00,
            8.190900e+00,
            8.500000e+00}, // SINR
           {9.932692e-01,
            8.977273e-01,
            6.213592e-01,
            2.527555e-01,
            4.540000e-02,
            2.900000e-03,
            1.000000e-04} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00,
            7.266900e+00,
            7.574900e+00,
            7.882900e+00,
            8.190900e+00,
            8.500000e+00},                                                           // SINR
           {9.169643e-01, 6.375628e-01, 2.204983e-01, 2.800000e-02, 1.100000e-03, 0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00, 7.343900e+00, 7.728900e+00, 8.113900e+00, 8.498900e+00}, // SINR
           {9.119718e-01, 4.898649e-01, 6.280000e-02, 2.500000e-03, 2.000000e-04}  // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00, 7.266900e+00, 7.574900e+00, 7.882900e+00, 8.190900e+00}, // SINR
           {9.375000e-01, 6.393035e-01, 2.049347e-01, 2.150000e-02, 8.000000e-04}  // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00, 7.266900e+00, 7.574900e+00, 7.882900e+00, 8.190900e+00}, // SINR
           {9.223214e-01, 6.262195e-01, 1.721311e-01, 1.530000e-02, 3.000000e-04}  // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00, 7.266900e+00, 7.574900e+00, 7.882900e+00, 8.190900e+00}, // SINR
           {9.379496e-01, 6.530612e-01, 1.857407e-01, 1.590000e-02, 6.000000e-04}  // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {6.958900e+00, 7.266900e+00, 7.574900e+00, 7.882900e+00, 8.190900e+00}, // SINR
           {9.239130e-01, 5.746606e-01, 1.323996e-01, 6.400000e-03, 3.000000e-04}  // BLER
       }},
      {1352U, // SINR and BLER for CBS 1352
       MmWaveEesmErrorModel::DoubleTuple{
           {7.080000e+00, 7.390000e+00, 7.702700e+00, 8.013400e+00, 8.324000e+00}, // SINR
           {9.055944e-01, 4.669118e-01, 7.600000e-02, 1.900000e-03, 0}             // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {7.090000e+00,
            7.410000e+00,
            7.725800e+00,
            8.044700e+00,
            8.363600e+00,
            8.682600e+00,
            9.001500e+00}, // SINR
           {9.791667e-01,
            7.981366e-01,
            3.034010e-01,
            2.980000e-02,
            5.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {7.090000e+00,
            7.410000e+00,
            7.725800e+00,
            8.044700e+00,
            8.363600e+00,
            8.682600e+00},                                                           // SINR
           {9.687500e-01, 6.668848e-01, 1.562500e-01, 5.700000e-03, 1.000000e-04, 0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {7.090000e+00,
            7.330000e+00,
            7.570000e+00,
            7.810000e+00,
            8.044700e+00,
            8.283900e+00,
            8.523100e+00}, // SINR
           {9.763258e-01,
            8.062500e-01,
            4.007120e-01,
            7.840000e-02,
            4.900000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {7.090000e+00,
            7.330000e+00,
            7.570000e+00,
            7.810000e+00,
            8.044700e+00,
            8.283900e+00,
            8.523100e+00,
            8.762300e+00}, // SINR
           {9.856870e-01,
            8.316993e-01,
            4.265203e-01,
            8.600000e-02,
            4.500000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {6.610000e+00,
            6.850000e+00,
            7.090000e+00,
            7.330000e+00,
            7.570000e+00,
            7.810000e+00,
            8.044700e+00,
            8.283900e+00,
            8.523100e+00,
            8.762300e+00}, // SINR
           {1,
            9.990385e-01,
            9.680451e-01,
            7.544118e-01,
            2.859163e-01,
            3.510000e-02,
            1.300000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {6.610000e+00,
            6.850000e+00,
            7.090000e+00,
            7.330000e+00,
            7.570000e+00,
            7.810000e+00,
            8.044700e+00,
            8.283900e+00,
            8.523100e+00,
            8.762300e+00,
            9.001500e+00}, // SINR
           {1,
            9.990385e-01,
            9.817308e-01,
            8.089623e-01,
            3.145161e-01,
            3.960000e-02,
            1.300000e-03,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {7.090000e+00,
            7.330000e+00,
            7.570000e+00,
            7.810000e+00,
            8.044700e+00,
            8.283900e+00,
            8.523100e+00}, // SINR
           {9.903846e-01,
            8.269231e-01,
            3.318063e-01,
            3.930000e-02,
            1.400000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {6.930000e+00,
            7.110000e+00,
            7.300000e+00,
            7.490000e+00,
            7.670000e+00,
            7.860000e+00,
            8.044700e+00,
            8.230800e+00,
            8.416800e+00,
            8.602900e+00,
            8.788900e+00}, // SINR
           {1,
            9.778846e-01,
            8.152866e-01,
            4.188742e-01,
            9.627265e-02,
            7.700000e-03,
            3.000000e-04,
            2.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {6.740000e+00,
            6.930000e+00,
            7.110000e+00,
            7.300000e+00,
            7.490000e+00,
            7.670000e+00,
            7.860000e+00,
            8.044700e+00,
            8.230800e+00,
            8.416800e+00,
            8.602900e+00,
            8.788900e+00}, // SINR
           {1,
            9.990385e-01,
            9.846154e-01,
            8.421053e-01,
            4.253356e-01,
            1.000827e-01,
            7.000000e-03,
            4.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {6.840000e+00,
            7.120000e+00,
            7.410000e+00,
            7.700000e+00,
            7.987000e+00,
            8.274500e+00,
            8.562000e+00},                                                              // SINR
           {1, 9.847328e-01, 5.846774e-01, 4.400000e-02, 5.000000e-04, 2.000000e-04, 0} // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {6.530000e+00,
            7.160000e+00,
            7.590000e+00,
            7.800000e+00,
            8.010000e+00,
            8.437500e+00,
            9.075000e+00},                                                              // SINR
           {1, 9.826923e-01, 1.942724e-01, 1.190000e-02, 7.000000e-04, 4.000000e-04, 0} // BLER
       }}},
     {      // MCS 13
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            8.065500e+00,
            8.661600e+00,
            9.257600e+00,
            9.853700e+00,
            1.045000e+01,
            1.105000e+01,
            1.164000e+01,
            1.224000e+01,
            1.283000e+01,
            1.343000e+01,
            1.403000e+01,
            1.462000e+01,
            1.522000e+01,
            1.581000e+01}, // SINR
           {9.913462e-01,
            9.734848e-01,
            9.411232e-01,
            8.606419e-01,
            7.427746e-01,
            5.877294e-01,
            4.226589e-01,
            2.550505e-01,
            1.319517e-01,
            5.870000e-02,
            2.220000e-02,
            7.400000e-03,
            1.600000e-03,
            2.000000e-04,
            1.000000e-04} // BLER
       }},
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            8.140300e+00,
            8.811300e+00,
            9.482300e+00,
            1.015320e+01,
            1.082000e+01,
            1.150000e+01,
            1.217000e+01,
            1.284000e+01,
            1.351000e+01,
            1.418000e+01}, // SINR
           {9.564815e-01,
            8.809932e-01,
            7.514535e-01,
            5.578603e-01,
            3.392380e-01,
            1.706081e-01,
            6.090000e-02,
            1.620000e-02,
            2.800000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            8.140300e+00,
            8.811300e+00,
            9.482300e+00,
            1.015320e+01,
            1.082000e+01,
            1.150000e+01,
            1.217000e+01,
            1.284000e+01,
            1.351000e+01,
            1.418000e+01,
            1.485000e+01}, // SINR
           {9.818702e-01,
            9.348214e-01,
            8.336039e-01,
            6.645078e-01,
            4.413793e-01,
            2.258065e-01,
            8.290000e-02,
            2.070000e-02,
            4.400000e-03,
            6.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            8.140300e+00,
            8.811300e+00,
            9.482300e+00,
            1.015320e+01,
            1.082000e+01,
            1.150000e+01,
            1.217000e+01,
            1.284000e+01,
            1.351000e+01,
            1.418000e+01}, // SINR
           {9.570896e-01,
            8.741611e-01,
            6.747382e-01,
            4.116450e-01,
            1.863971e-01,
            5.470000e-02,
            1.180000e-02,
            1.200000e-03,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01,
            1.099000e+01,
            1.150000e+01,
            12,
            1.250000e+01,
            13,
            1.351000e+01,
            1.401000e+01,
            1.451000e+01}, // SINR
           {9.788462e-01,
            9.465580e-01,
            8.518212e-01,
            6.912162e-01,
            5.024704e-01,
            3.001781e-01,
            1.507530e-01,
            5.840000e-02,
            1.530000e-02,
            1.900000e-03,
            4.000000e-04,
            2.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            8.140300e+00,
            8.811300e+00,
            9.482300e+00,
            1.015320e+01,
            1.082000e+01,
            1.150000e+01,
            1.217000e+01,
            1.284000e+01}, // SINR
           {9.636194e-01,
            8.390523e-01,
            6.130952e-01,
            3.112624e-01,
            9.660494e-02,
            1.960000e-02,
            2.500000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {96U, // SINR and BLER for CBS 96
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01,
            1.099000e+01,
            1.150000e+01,
            12}, // SINR
           {9.235612e-01,
            8.141026e-01,
            6.177184e-01,
            3.757440e-01,
            1.803161e-01,
            5.750000e-02,
            1.360000e-02,
            2.200000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {7.500000e+00,
            8,
            8.500000e+00,
            9,
            9.500000e+00,
            10,
            1.050000e+01,
            11,
            1.150000e+01,
            12}, // SINR
           {9.725379e-01,
            8.958333e-01,
            7.328571e-01,
            4.837165e-01,
            2.395437e-01,
            8.650000e-02,
            2.330000e-02,
            4.100000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {120U, // SINR and BLER for CBS 120
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01,
            1.099000e+01,
            1.150000e+01,
            12}, // SINR
           {9.546296e-01,
            8.398693e-01,
            6.089286e-01,
            3.450272e-01,
            1.461963e-01,
            4.170000e-02,
            7.900000e-03,
            1.200000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            8.140300e+00,
            8.811300e+00,
            9.482300e+00,
            1.015320e+01,
            1.082000e+01,
            1.150000e+01}, // SINR
           {9.636194e-01,
            7.797256e-01,
            3.865031e-01,
            7.920000e-02,
            6.700000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01,
            1.099000e+01,
            1.150000e+01}, // SINR
           {9.846154e-01,
            8.932292e-01,
            6.993243e-01,
            3.895706e-01,
            1.224539e-01,
            2.110000e-02,
            2.000000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01,
            1.099000e+01}, // SINR
           {9.649621e-01,
            8.101266e-01,
            4.908654e-01,
            1.745839e-01,
            3.410000e-02,
            3.300000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01,
            1.099000e+01}, // SINR
           {9.817308e-01,
            8.758446e-01,
            5.974178e-01,
            2.477898e-01,
            5.440000e-02,
            3.800000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01,
            1.099000e+01}, // SINR
           {9.671053e-01,
            8.287338e-01,
            4.752799e-01,
            1.541054e-01,
            2.280000e-02,
            2.200000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01}, // SINR
           {9.636194e-01,
            8.055556e-01,
            3.972656e-01,
            9.944123e-02,
            8.500000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01,
            1.099000e+01}, // SINR
           {9.818702e-01,
            8.879310e-01,
            5.739910e-01,
            1.800787e-01,
            2.260000e-02,
            1.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00,
            1.049000e+01}, // SINR
           {9.884615e-01,
            8.409091e-01,
            4.563849e-01,
            1.123318e-01,
            1.040000e-02,
            2.000000e-04,
            0} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00},                                                           // SINR
           {9.580224e-01, 7.718373e-01, 3.479452e-01, 5.700000e-02, 2.700000e-03, 0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00}, // SINR
           {9.732824e-01,
            8.001543e-01,
            3.582621e-01,
            5.190000e-02,
            1.900000e-03,
            1.000000e-04} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00},                                                           // SINR
           {9.780534e-01, 7.967791e-01, 3.642550e-01, 4.720000e-02, 2.700000e-03, 0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00,
            7.972600e+00,
            8.475900e+00,
            8.979100e+00,
            9.482300e+00,
            9.990000e+00}, // SINR
           {9.846154e-01,
            8.400974e-01,
            3.383737e-01,
            3.360000e-02,
            1.200000e-03,
            1.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00, 7.972600e+00, 8.475900e+00, 8.979100e+00, 9.482300e+00}, // SINR
           {9.923077e-01, 8.437500e-01, 2.984634e-01, 1.700000e-02, 0}             // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00, 7.972600e+00, 8.475900e+00, 8.979100e+00, 9.482300e+00}, // SINR
           {9.875000e-01, 7.901235e-01, 2.138325e-01, 8.000000e-03, 2.000000e-04}  // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00, 7.972600e+00, 8.475900e+00, 8.979100e+00, 9.482300e+00}, // SINR
           {9.942308e-01, 8.007813e-01, 1.836735e-01, 5.300000e-03, 0}             // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00, 7.972600e+00, 8.475900e+00, 8.979100e+00, 9.482300e+00}, // SINR
           {9.903846e-01, 7.942547e-01, 1.554012e-01, 2.600000e-03, 0}             // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00, 7.972600e+00, 8.475900e+00, 8.979100e+00, 9.482300e+00}, // SINR
           {9.923077e-01, 7.724551e-01, 1.386139e-01, 2.500000e-03, 0}             // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {7.469400e+00, 7.972600e+00, 8.475900e+00, 8.979100e+00, 9.482300e+00}, // SINR
           {9.913462e-01, 7.733434e-01, 1.177162e-01, 1.300000e-03, 0}             // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {7.510000e+00,
            7.900000e+00,
            8.295000e+00,
            8.690000e+00,
            9.085000e+00,
            9.480000e+00},                                                           // SINR
           {9.971154e-01, 8.732993e-01, 3.370000e-01, 2.600000e-02, 2.000000e-04, 0} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {7.680000e+00,
            7.910000e+00,
            8.140000e+00,
            8.380000e+00,
            8.610000e+00,
            8.843500e+00,
            9.079100e+00}, // SINR
           {9.666031e-01,
            8.168790e-01,
            4.752799e-01,
            1.501497e-01,
            2.350000e-02,
            1.500000e-03,
            0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {7.430000e+00,
            7.670000e+00,
            7.900000e+00,
            8.140000e+00,
            8.370000e+00,
            8.610000e+00,
            8.843500e+00,
            9.079100e+00,
            9.314700e+00,
            9.550200e+00,
            9.785800e+00}, // SINR
           {1,
            9.875000e-01,
            8.888889e-01,
            5.616740e-01,
            1.872214e-01,
            2.650000e-02,
            1.700000e-03,
            2.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {7.890000e+00,
            8.130000e+00,
            8.370000e+00,
            8.610000e+00,
            8.843500e+00,
            9.079100e+00,
            9.314700e+00}, // SINR
           {9.574074e-01,
            7.420977e-01,
            3.480191e-01,
            6.720000e-02,
            4.900000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {7.890000e+00,
            8.130000e+00,
            8.370000e+00,
            8.610000e+00,
            8.843500e+00,
            9.079100e+00,
            9.314700e+00,
            9.550200e+00,
            9.785800e+00}, // SINR
           {9.865385e-01,
            8.978873e-01,
            5.605727e-01,
            1.752434e-01,
            2.460000e-02,
            1.800000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {7.890000e+00,
            8.130000e+00,
            8.370000e+00,
            8.610000e+00,
            8.843500e+00,
            9.079100e+00,
            9.314700e+00,
            9.550200e+00}, // SINR
           {9.675573e-01,
            8.269231e-01,
            4.514134e-01,
            1.164352e-01,
            1.280000e-02,
            1.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {8.130000e+00,
            8.370000e+00,
            8.610000e+00,
            8.843500e+00,
            9.079100e+00,
            9.314700e+00,
            9.550200e+00,
            9.785800e+00}, // SINR
           {9.187500e-01,
            5.922897e-01,
            1.991256e-01,
            2.370000e-02,
            7.000000e-04,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {7.910000e+00,
            8.140000e+00,
            8.370000e+00,
            8.610000e+00,
            8.843500e+00,
            9.079100e+00,
            9.314700e+00}, // SINR
           {9.531250e-01,
            7.233146e-01,
            2.746746e-01,
            3.500000e-02,
            2.000000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {7.430000e+00,
            7.670000e+00,
            7.900000e+00,
            8.140000e+00,
            8.370000e+00,
            8.610000e+00,
            8.843500e+00,
            9.079100e+00,
            9.314700e+00,
            9.550200e+00,
            9.785800e+00}, // SINR
           {1,
            9.990385e-01,
            9.788462e-01,
            8.550000e-01,
            4.537367e-01,
            8.270000e-02,
            4.400000e-03,
            4.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {7.850000e+00,
            8.100000e+00,
            8.350000e+00,
            8.600000e+00,
            8.850000e+00,
            9.100000e+00}, // SINR
           {9.884615e-01,
            8.085443e-01,
            3.442623e-01,
            4.130000e-02,
            1.000000e-03,
            1.000000e-04} // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {7.910000e+00,
            8.140000e+00,
            8.370000e+00,
            8.610000e+00,
            8.843500e+00,
            9.079100e+00,
            9.314700e+00}, // SINR
           {9.826923e-01,
            8.250000e-01,
            3.309399e-01,
            3.790000e-02,
            1.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {7.900000e+00,
            8.300000e+00,
            8.500000e+00,
            8.700000e+00,
            9.100000e+00,
            9.700000e+00},                                                           // SINR
           {9.715909e-01, 3.418022e-01, 5.160000e-02, 2.400000e-03, 2.000000e-04, 0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {8, 8.350000e+00, 8.700000e+00, 9.050000e+00, 1.010000e+01}, // SINR
           {9.537037e-01, 2.975352e-01, 4.100000e-03, 1.000000e-04, 0}  // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {7.920000e+00, 8.440000e+00, 8.700000e+00, 8.960000e+00, 9.475000e+00}, // SINR
           {9.923077e-01, 1.512921e-01, 4.400000e-03, 3.000000e-04, 0}             // BLER
       }}},
     {      // MCS 14
      {32U, // SINR and BLER for CBS 32
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.469200e+00,
            1.020200e+01,
            1.093470e+01,
            1.166740e+01,
            1.240000e+01,
            1.313000e+01,
            1.387000e+01,
            1.460000e+01,
            1.533000e+01,
            1.606000e+01,
            1.680000e+01}, // SINR
           {9.343525e-01,
            8.189103e-01,
            6.503807e-01,
            4.547491e-01,
            2.446498e-01,
            1.061542e-01,
            3.640000e-02,
            9.300000e-03,
            1.700000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {8.003800e+00,
            8.919700e+00,
            9.835600e+00,
            1.075150e+01,
            1.166740e+01,
            1.258000e+01,
            1.350000e+01,
            1.442000e+01,
            1.533000e+01}, // SINR
           {9.826923e-01,
            9.379496e-01,
            7.908951e-01,
            5.296875e-01,
            2.425908e-01,
            6.170000e-02,
            6.900000e-03,
            8.000000e-04,
            0} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {8.003800e+00,
            8.919700e+00,
            9.835600e+00,
            1.075150e+01,
            1.166740e+01,
            1.258000e+01,
            1.350000e+01,
            1.442000e+01,
            1.533000e+01}, // SINR
           {9.903846e-01,
            9.555556e-01,
            7.970679e-01,
            5.192308e-01,
            2.126897e-01,
            5.000000e-02,
            6.100000e-03,
            9.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {8.250000e+00,
            8.921200e+00,
            9.592300e+00,
            1.026350e+01,
            1.093470e+01,
            1.161000e+01,
            1.228000e+01,
            1.295000e+01,
            1.362000e+01,
            1.429000e+01,
            1.496000e+01}, // SINR
           {9.470803e-01,
            8.591667e-01,
            6.775266e-01,
            4.138072e-01,
            1.957878e-01,
            6.210000e-02,
            1.250000e-02,
            2.400000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.469200e+00,
            1.020200e+01,
            1.093470e+01,
            1.166740e+01,
            1.240000e+01,
            1.313000e+01,
            1.387000e+01}, // SINR
           {9.420290e-01,
            7.837423e-01,
            5.120482e-01,
            2.152659e-01,
            5.550000e-02,
            6.500000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {96U, // SINR and BLER for CBS 96
       MmWaveEesmErrorModel::DoubleTuple{
           {8,
            8.550500e+00,
            9.101000e+00,
            9.651400e+00,
            1.020190e+01,
            1.075000e+01,
            1.130000e+01,
            1.185000e+01,
            1.240000e+01,
            1.295000e+01,
            1.350000e+01,
            1.406000e+01}, // SINR
           {9.671053e-01,
            9.104610e-01,
            7.470930e-01,
            5.260417e-01,
            2.994668e-01,
            1.213557e-01,
            3.280000e-02,
            6.700000e-03,
            1.000000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {8,
            8.550500e+00,
            9.101000e+00,
            9.651400e+00,
            1.020190e+01,
            1.075000e+01,
            1.130000e+01,
            1.185000e+01,
            1.240000e+01,
            1.295000e+01,
            1.350000e+01}, // SINR
           {9.836538e-01,
            9.425182e-01,
            8.224522e-01,
            6.225728e-01,
            3.621060e-01,
            1.561725e-01,
            4.800000e-02,
            8.500000e-03,
            1.100000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {8,
            8.550500e+00,
            9.101000e+00,
            9.651400e+00,
            1.020190e+01,
            1.075000e+01,
            1.130000e+01,
            1.185000e+01,
            1.240000e+01,
            1.295000e+01}, // SINR
           {9.923077e-01,
            9.668561e-01,
            8.690878e-01,
            7.005495e-01,
            4.134304e-01,
            1.800787e-01,
            5.490000e-02,
            9.700000e-03,
            1.700000e-03,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {8.003800e+00,
            8.736500e+00,
            9.469200e+00,
            1.020200e+01,
            1.093470e+01,
            1.167000e+01,
            1.240000e+01}, // SINR
           {9.932692e-01,
            9.214286e-01,
            6.411692e-01,
            2.371013e-01,
            3.620000e-02,
            2.100000e-03,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.011300e+00,
            9.286000e+00,
            9.560800e+00,
            9.835600e+00,
            1.011000e+01,
            1.039000e+01,
            1.066000e+01,
            1.093000e+01,
            1.121000e+01,
            1.148000e+01,
            1.176000e+01,
            1.203000e+01,
            1.231000e+01}, // SINR
           {9.293478e-01,
            8.699664e-01,
            7.771084e-01,
            6.516497e-01,
            4.801887e-01,
            3.101966e-01,
            1.786984e-01,
            8.800000e-02,
            4.070000e-02,
            1.570000e-02,
            5.400000e-03,
            1.700000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01,
            1.057000e+01,
            1.093000e+01,
            1.130000e+01,
            1.167000e+01,
            1.203000e+01,
            1.240000e+01}, // SINR
           {9.614662e-01,
            8.724662e-01,
            7.064917e-01,
            4.884615e-01,
            2.787829e-01,
            1.160880e-01,
            3.850000e-02,
            9.300000e-03,
            2.300000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {8.460000e+00,
            8.736500e+00,
            9.011300e+00,
            9.286000e+00,
            9.560800e+00,
            9.835600e+00,
            1.011000e+01,
            1.039000e+01,
            1.066000e+01,
            1.093000e+01,
            1.121000e+01,
            1.148000e+01,
            1.176000e+01,
            1.203000e+01}, // SINR
           {9.420956e-01,
            8.801020e-01,
            7.647929e-01,
            6.312189e-01,
            4.497331e-01,
            2.815965e-01,
            1.508103e-01,
            6.820000e-02,
            2.620000e-02,
            9.500000e-03,
            2.800000e-03,
            6.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.011300e+00,
            9.286000e+00,
            9.560700e+00,
            9.835500e+00,
            1.011000e+01,
            1.039000e+01,
            1.066000e+01,
            1.093000e+01,
            1.121000e+01,
            1.148000e+01,
            1.176000e+01,
            1.203000e+01,
            1.231000e+01}, // SINR
           {9.406475e-01,
            8.617550e-01,
            7.233146e-01,
            5.313808e-01,
            3.573446e-01,
            2.008786e-01,
            9.336859e-02,
            3.590000e-02,
            1.340000e-02,
            3.500000e-03,
            1.000000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01,
            1.057000e+01,
            1.093000e+01,
            1.130000e+01,
            1.167000e+01}, // SINR
           {9.031690e-01,
            7.182203e-01,
            4.288721e-01,
            2.003589e-01,
            6.760000e-02,
            1.410000e-02,
            2.000000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01,
            1.057000e+01,
            1.093000e+01,
            1.130000e+01,
            1.167000e+01}, // SINR
           {9.343525e-01,
            7.862654e-01,
            5.418432e-01,
            2.807650e-01,
            9.532520e-02,
            2.010000e-02,
            3.700000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {8.370000e+00,
            8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01,
            1.057000e+01,
            1.093000e+01,
            1.130000e+01}, // SINR
           {9.744318e-01,
            8.809524e-01,
            6.736842e-01,
            3.814006e-01,
            1.399108e-01,
            3.500000e-02,
            5.000000e-03,
            9.000000e-04,
            0} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {8.370000e+00,
            8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01,
            1.057000e+01,
            1.093000e+01,
            1.130000e+01}, // SINR
           {9.751908e-01,
            8.956897e-01,
            6.932432e-01,
            3.965517e-01,
            1.482901e-01,
            3.150000e-02,
            3.200000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01,
            1.057000e+01,
            1.093000e+01,
            1.130000e+01,
            1.167000e+01}, // SINR
           {9.552239e-01,
            8.274194e-01,
            5.675223e-01,
            2.553245e-01,
            7.050000e-02,
            1.310000e-02,
            1.400000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01,
            1.057000e+01,
            1.093000e+01,
            1.130000e+01,
            1.167000e+01}, // SINR
           {9.498175e-01,
            7.860429e-01,
            4.960784e-01,
            1.924694e-01,
            4.880000e-02,
            6.200000e-03,
            5.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01,
            1.057000e+01,
            1.093000e+01}, // SINR
           {9.055944e-01,
            6.472081e-01,
            2.809710e-01,
            6.820000e-02,
            8.600000e-03,
            5.000000e-04,
            1.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {8.003800e+00,
            8.553300e+00,
            9.102900e+00,
            9.652400e+00,
            1.020190e+01,
            1.075000e+01},                                                // SINR
           {1, 9.798077e-01, 7.205056e-01, 1.672770e-01, 6.400000e-03, 0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01,
            1.057000e+01},                                                           // SINR
           {9.241071e-01, 6.736842e-01, 2.787611e-01, 5.400000e-02, 2.800000e-03, 0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {8.370000e+00,
            8.736500e+00,
            9.102900e+00,
            9.469200e+00,
            9.835500e+00,
            1.020190e+01}, // SINR
           {9.951923e-01,
            8.987676e-01,
            5.182186e-01,
            1.397715e-01,
            1.290000e-02,
            2.000000e-04} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00, 9.102900e+00, 9.469200e+00, 9.835500e+00, 1.020190e+01}, // SINR
           {9.031690e-01, 5.584061e-01, 1.462704e-01, 1.290000e-02, 9.000000e-04}  // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {8.003800e+00, 8.553300e+00, 9.102900e+00, 9.652400e+00, 1.020190e+01}, // SINR
           {1, 9.817308e-01, 5.825792e-01, 5.660000e-02, 2.000000e-04}             // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {8.736500e+00, 9.102900e+00, 9.469200e+00, 9.835500e+00, 1.020190e+01}, // SINR
           {9.324818e-01, 6.106459e-01, 1.574248e-01, 1.100000e-02, 1.000000e-04}  // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {8.720000e+00,
            9.030000e+00,
            9.340000e+00,
            9.651900e+00,
            9.961100e+00,
            1.027040e+01,
            1.057960e+01,
            1.088890e+01}, // SINR
           {9.131206e-01,
            6.078199e-01,
            1.907197e-01,
            2.410000e-02,
            1.400000e-03,
            3.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {8.720000e+00,
            9.030000e+00,
            9.340000e+00,
            9.651900e+00,
            9.961100e+00,
            1.027040e+01},                                                           // SINR
           {9.393116e-01, 6.433081e-01, 1.993671e-01, 2.240000e-02, 1.700000e-03, 0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {8.720000e+00,
            9.030000e+00,
            9.340000e+00,
            9.651900e+00,
            9.961100e+00,
            1.027040e+01},                                                           // SINR
           {9.540441e-01, 6.596154e-01, 2.041396e-01, 1.890000e-02, 5.000000e-04, 0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {8.720000e+00,
            9.030000e+00,
            9.340000e+00,
            9.651900e+00,
            9.961100e+00,
            1.027040e+01},                                                           // SINR
           {9.494485e-01, 6.612694e-01, 1.771127e-01, 1.450000e-02, 2.000000e-04, 0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {8.720000e+00,
            9.030000e+00,
            9.340000e+00,
            9.651900e+00,
            9.961100e+00,
            1.027040e+01},                                                           // SINR
           {9.855769e-01, 8.274194e-01, 3.409704e-01, 3.380000e-02, 9.000000e-04, 0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {8.720000e+00,
            9.030000e+00,
            9.340000e+00,
            9.651900e+00,
            9.961100e+00,
            1.027040e+01},                                                           // SINR
           {9.826923e-01, 8.295455e-01, 3.779674e-01, 5.840000e-02, 1.700000e-03, 0} // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {8.960000e+00,
            9.190000e+00,
            9.420000e+00,
            9.651900e+00,
            9.883800e+00,
            1.011580e+01,
            1.034780e+01,
            1.057970e+01}, // SINR
           {9.187500e-01,
            6.517857e-01,
            2.717742e-01,
            5.620000e-02,
            4.600000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {8.720000e+00,
            9.030000e+00,
            9.340000e+00,
            9.651900e+00,
            9.961100e+00,
            1.027040e+01,
            1.057960e+01}, // SINR
           {9.951923e-01,
            8.681973e-01,
            3.826220e-01,
            4.160000e-02,
            1.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {8.720000e+00,
            9.030000e+00,
            9.340000e+00,
            9.651900e+00,
            9.961100e+00,
            1.027040e+01,
            1.057960e+01}, // SINR
           {9.913462e-01,
            8.184713e-01,
            3.126543e-01,
            2.560000e-02,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {8.960000e+00,
            9.190000e+00,
            9.420000e+00,
            9.651900e+00,
            9.883800e+00,
            1.011580e+01,
            1.034780e+01}, // SINR
           {9.407407e-01,
            6.503807e-01,
            2.477941e-01,
            3.870000e-02,
            1.900000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {8, 8.670000e+00, 9, 9.330000e+00, 10},          // SINR
           {1, 9.951923e-01, 8.293269e-01, 2.243304e-01, 0} // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {8.500000e+00, 9, 9.500000e+00, 1.049670e+01}, // SINR
           {1, 8.943662e-01, 6.720000e-02, 0}             // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {7.890000e+00, 8.800000e+00, 9.250000e+00, 9.710000e+00, 1.061460e+01}, // SINR
           {1, 9.971154e-01, 4.665428e-01, 3.900000e-03, 0}                        // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {7.720000e+00, 8.640000e+00, 9.102900e+00, 9.560000e+00, 1.048100e+01}, // SINR
           {1, 9.990385e-01, 6.918919e-01, 1.370000e-02, 0}                        // BLER
       }}},
     {      // MCS 15
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00,
            1.000360e+01,
            1.079810e+01,
            1.159260e+01,
            1.238710e+01,
            1.318000e+01,
            1.398000e+01,
            1.477000e+01,
            1.557000e+01,
            1.636000e+01,
            1.715000e+01,
            1.795000e+01,
            1.874000e+01,
            1.954000e+01}, // SINR
           {9.942308e-01,
            9.689850e-01,
            8.784247e-01,
            7.192737e-01,
            4.834906e-01,
            2.728987e-01,
            1.067888e-01,
            3.480000e-02,
            6.000000e-03,
            1.800000e-03,
            3.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00,
            1.000360e+01,
            1.079810e+01,
            1.159260e+01,
            1.238710e+01,
            1.318000e+01,
            1.398000e+01,
            1.477000e+01,
            1.557000e+01,
            1.636000e+01,
            1.715000e+01}, // SINR
           {9.875954e-01,
            9.498175e-01,
            8.293269e-01,
            5.965116e-01,
            3.600852e-01,
            1.634864e-01,
            4.480000e-02,
            8.500000e-03,
            1.400000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00,
            1.000360e+01,
            1.079810e+01,
            1.159260e+01,
            1.238710e+01,
            1.318000e+01,
            1.398000e+01,
            1.477000e+01,
            1.557000e+01,
            1.636000e+01}, // SINR
           {9.875000e-01,
            9.444444e-01,
            8.144654e-01,
            5.584061e-01,
            2.844731e-01,
            8.947368e-02,
            1.810000e-02,
            2.500000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00,
            1.000360e+01,
            1.079810e+01,
            1.159260e+01,
            1.238710e+01,
            1.318000e+01,
            1.398000e+01,
            1.477000e+01}, // SINR
           {9.379562e-01,
            8.093354e-01,
            5.162602e-01,
            2.303114e-01,
            6.130000e-02,
            9.200000e-03,
            8.000000e-04,
            0} // BLER
       }},
      {96U, // SINR and BLER for CBS 96
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00,
            9.805000e+00,
            1.040080e+01,
            1.099670e+01,
            1.159260e+01,
            1.219000e+01,
            1.278000e+01,
            1.338000e+01,
            1.398000e+01,
            1.457000e+01,
            1.517000e+01}, // SINR
           {9.652256e-01,
            8.844828e-01,
            7.071823e-01,
            4.784644e-01,
            2.439320e-01,
            9.380048e-02,
            2.580000e-02,
            6.300000e-03,
            1.100000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00,
            9.805000e+00,
            1.040080e+01,
            1.099670e+01,
            1.159260e+01,
            1.219000e+01,
            1.278000e+01,
            1.338000e+01,
            1.398000e+01,
            1.457000e+01}, // SINR
           {9.652256e-01,
            8.939655e-01,
            7.021858e-01,
            4.729478e-01,
            2.259874e-01,
            7.290000e-02,
            1.450000e-02,
            2.600000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {9.503600e+00,
            9.827200e+00,
            1.015090e+01,
            1.047450e+01,
            1.079810e+01,
            1.112000e+01,
            1.145000e+01,
            1.177000e+01,
            1.209000e+01,
            1.242000e+01,
            1.274000e+01,
            1.306000e+01,
            1.339000e+01,
            1.371000e+01,
            1.403000e+01}, // SINR
           {9.678030e-01,
            9.223214e-01,
            8.140823e-01,
            6.915323e-01,
            5.414894e-01,
            3.968750e-01,
            2.512450e-01,
            1.449422e-01,
            7.510000e-02,
            3.320000e-02,
            1.280000e-02,
            4.600000e-03,
            1.400000e-03,
            9.000000e-04,
            1.000000e-04} // BLER
       }},
      {184U, // SINR and BLER for CBS 184
       MmWaveEesmErrorModel::DoubleTuple{
           {9.600000e+00,
            10,
            1.039810e+01,
            1.079630e+01,
            1.119440e+01,
            1.159260e+01,
            1.199000e+01,
            1.239000e+01,
            1.279000e+01,
            1.319000e+01,
            1.358000e+01}, // SINR
           {9.217626e-01,
            7.984375e-01,
            5.974178e-01,
            3.761194e-01,
            1.881559e-01,
            7.130000e-02,
            2.140000e-02,
            4.400000e-03,
            5.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {10,
            1.039810e+01,
            1.079630e+01,
            1.119440e+01,
            1.159260e+01,
            1.199000e+01,
            1.239000e+01,
            1.279000e+01,
            1.319000e+01,
            1.358000e+01}, // SINR
           {9.258929e-01,
            8.097484e-01,
            6.342365e-01,
            3.982650e-01,
            1.894737e-01,
            6.950000e-02,
            1.980000e-02,
            3.400000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {9.080000e+00,
            9.500000e+00,
            9.920100e+00,
            1.033820e+01,
            1.075630e+01,
            1.117450e+01,
            1.159260e+01,
            1.201000e+01,
            1.243000e+01,
            1.285000e+01,
            1.327000e+01}, // SINR
           {9.751908e-01,
            8.923611e-01,
            7.133978e-01,
            4.837786e-01,
            2.422929e-01,
            8.360000e-02,
            2.240000e-02,
            4.500000e-03,
            7.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00,
            9.805000e+00,
            1.040080e+01,
            1.099670e+01,
            1.159260e+01,
            1.219000e+01,
            1.278000e+01}, // SINR
           {9.730769e-01,
            8.007813e-01,
            4.895038e-01,
            1.585443e-01,
            2.310000e-02,
            1.200000e-03,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {9.503600e+00,
            9.827200e+00,
            1.015090e+01,
            1.047450e+01,
            1.079810e+01,
            1.112000e+01,
            1.145000e+01,
            1.177000e+01,
            1.209000e+01,
            1.242000e+01,
            1.274000e+01,
            1.306000e+01}, // SINR
           {9.333942e-01,
            8.441558e-01,
            6.854839e-01,
            4.664522e-01,
            2.460938e-01,
            1.130523e-01,
            3.770000e-02,
            1.120000e-02,
            2.000000e-03,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00,
            9.805000e+00,
            1.040080e+01,
            1.099670e+01,
            1.159260e+01,
            1.219000e+01,
            1.278000e+01,
            1.338000e+01,
            1.398000e+01}, // SINR
           {9.875000e-01,
            8.699324e-01,
            5.456009e-01,
            1.712773e-01,
            2.280000e-02,
            1.400000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {9.612800e+00,
            1.010770e+01,
            1.060270e+01,
            1.109760e+01,
            1.159260e+01,
            1.209000e+01,
            1.258000e+01,
            1.308000e+01}, // SINR
           {9.420290e-01,
            7.602941e-01,
            4.331897e-01,
            1.377188e-01,
            1.820000e-02,
            1.500000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {9.130000e+00,
            9.625000e+00,
            1.011690e+01,
            1.060880e+01,
            1.110070e+01,
            1.159260e+01,
            1.208000e+01}, // SINR
           {9.778846e-01,
            8.384740e-01,
            5.264523e-01,
            1.855670e-01,
            2.960000e-02,
            1.400000e-03,
            3.000000e-04} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {9.290000e+00,
            9.750000e+00,
            1.021060e+01,
            1.067130e+01,
            1.113190e+01,
            1.159260e+01,
            1.205000e+01}, // SINR
           {9.500000e-01,
            8.027950e-01,
            4.970472e-01,
            1.620668e-01,
            2.850000e-02,
            2.500000e-03,
            1.000000e-04} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {8.987000e+00, 1.000360e+01, 1.102020e+01, 1.203670e+01, 1.305330e+01}, // SINR
           {9.971154e-01, 7.087989e-01, 5.270000e-02, 2.000000e-04, 0}             // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {9.500000e+00,
            9.907500e+00,
            1.031500e+01,
            1.072250e+01,
            1.113000e+01,
            1.154000e+01,
            1.195000e+01,
            1.235000e+01}, // SINR
           {9.258929e-01,
            6.990489e-01,
            3.562853e-01,
            9.954658e-02,
            1.360000e-02,
            1.100000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {9.500000e+00,
            9.907500e+00,
            1.031500e+01,
            1.072250e+01,
            1.113000e+01,
            1.154000e+01,
            1.195000e+01,
            1.235000e+01}, // SINR
           {9.608209e-01,
            7.976562e-01,
            4.390138e-01,
            1.246283e-01,
            1.770000e-02,
            1.100000e-03,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {9.600000e+00, 10, 1.039810e+01, 1.079630e+01, 1.119440e+01, 1.159260e+01}, // SINR
           {9.280576e-01,
            6.299505e-01,
            2.444391e-01,
            4.130000e-02,
            3.500000e-03,
            1.000000e-04} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {9.209100e+00, 9.805000e+00, 1.040080e+01, 1.099670e+01, 1.159260e+01}, // SINR
           {9.971154e-01, 8.453947e-01, 2.857955e-01, 1.500000e-02, 1.000000e-04}  // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {9.600000e+00, 10, 1.039810e+01, 1.079630e+01, 1.119440e+01, 1.159260e+01}, // SINR
           {9.402574e-01, 6.350000e-01, 1.895770e-01, 2.260000e-02, 7.000000e-04, 0}   // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {8.993500e+00, 1.000360e+01, 1.101370e+01, 1.202390e+01}, // SINR
           {1, 7.212079e-01, 6.000000e-03, 0}                        // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {9.473900e+00, 1.000360e+01, 1.053320e+01, 1.106290e+01, 1.159260e+01}, // SINR
           {9.798077e-01, 6.784759e-01, 1.056127e-01, 1.500000e-03, 0}             // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {9.470000e+00,
            9.780000e+00,
            1.009000e+01,
            1.040000e+01,
            1.070600e+01,
            1.101200e+01,
            1.131800e+01,
            1.162400e+01}, // SINR
           {9.769231e-01,
            8.374183e-01,
            4.708333e-01,
            1.312630e-01,
            1.620000e-02,
            6.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {9.710000e+00,
            9.940000e+00,
            1.017000e+01,
            1.040000e+01,
            1.062950e+01,
            1.085900e+01,
            1.108850e+01,
            1.131800e+01}, // SINR
           {9.146127e-01,
            7.300000e-01,
            4.223422e-01,
            1.693657e-01,
            4.120000e-02,
            5.400000e-03,
            4.000000e-04,
            1.000000e-04} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {9.470000e+00,
            9.780000e+00,
            1.009000e+01,
            1.040000e+01,
            1.070600e+01,
            1.101200e+01,
            1.131800e+01,
            1.162400e+01}, // SINR
           {9.884615e-01,
            8.511513e-01,
            4.709410e-01,
            1.173780e-01,
            1.140000e-02,
            6.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {9.670000e+00,
            9.980000e+00,
            1.028680e+01,
            1.059310e+01,
            1.089940e+01,
            1.120570e+01,
            1.151200e+01}, // SINR
           {9.275362e-01,
            6.231707e-01,
            1.851103e-01,
            2.110000e-02,
            7.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {9.470000e+00,
            9.780000e+00,
            1.009000e+01,
            1.040000e+01,
            1.070600e+01,
            1.101200e+01},                                                           // SINR
           {9.837786e-01, 8.415033e-01, 4.166667e-01, 8.110000e-02, 3.900000e-03, 0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {9.710000e+00,
            9.940000e+00,
            1.017000e+01,
            1.040000e+01,
            1.062950e+01,
            1.085900e+01,
            1.108850e+01}, // SINR
           {9.202128e-01,
            7.053571e-01,
            3.180101e-01,
            7.260000e-02,
            8.900000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {9.470000e+00,
            9.780000e+00,
            1.009000e+01,
            1.040000e+01,
            1.070600e+01,
            1.101200e+01,
            1.131800e+01}, // SINR
           {9.894231e-01,
            8.474026e-01,
            4.039683e-01,
            5.460000e-02,
            1.900000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {1928U, // SINR and BLER for CBS 1928
       MmWaveEesmErrorModel::DoubleTuple{
           {9.780000e+00,
            1.009000e+01,
            1.040000e+01,
            1.070600e+01,
            1.101200e+01,
            1.131800e+01},                                                           // SINR
           {9.352190e-01, 5.532609e-01, 1.039552e-01, 4.200000e-03, 2.000000e-04, 0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {9.780000e+00,
            1.009000e+01,
            1.040000e+01,
            1.070600e+01,
            1.101200e+01,
            1.131800e+01},                                                           // SINR
           {9.668561e-01, 7.413295e-01, 2.595361e-01, 2.500000e-02, 7.000000e-04, 0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {9.760000e+00,
            1.005000e+01,
            1.033890e+01,
            1.063220e+01,
            1.092550e+01,
            1.121870e+01},                                                           // SINR
           {9.577206e-01, 6.765873e-01, 2.005538e-01, 1.680000e-02, 3.000000e-04, 0} // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {9.830000e+00, 1.044000e+01, 1.074750e+01, 1.105000e+01}, // SINR
           {9.122340e-01, 8.000000e-02, 3.400000e-03, 0}             // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {9.800000e+00,
            1.020000e+01,
            1.040000e+01,
            1.060000e+01,
            11,
            1.160000e+01,
            1.220000e+01}, // SINR
           {9.759615e-01,
            4.711896e-01,
            1.538814e-01,
            2.240000e-02,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {9.750000e+00,
            1.012000e+01,
            1.030000e+01,
            1.048000e+01,
            1.085000e+01,
            1.140000e+01},                                                           // SINR
           {9.732824e-01, 5.461373e-01, 2.186411e-01, 4.570000e-02, 8.000000e-04, 0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {9.830000e+00,
            1.005000e+01,
            1.028000e+01,
            1.050000e+01,
            1.072500e+01,
            1.095000e+01},                                                           // SINR
           {9.589552e-01, 7.278571e-01, 2.636555e-01, 3.470000e-02, 1.500000e-03, 0} // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {9.510000e+00, 1.008000e+01, 1.037000e+01, 1.066000e+01, 1.122750e+01}, // SINR
           {1, 6.189614e-01, 9.623260e-02, 2.200000e-03, 0}                        // BLER
       }}},
     {      // MCS 16
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {1.031000e+01,
            1.075000e+01,
            1.119230e+01,
            1.163470e+01,
            1.207700e+01,
            1.251930e+01,
            1.296000e+01,
            1.340000e+01,
            1.385000e+01,
            1.429000e+01,
            1.473000e+01,
            1.517000e+01,
            1.562000e+01,
            1.606000e+01,
            1.650000e+01,
            1.694000e+01}, // SINR
           {9.329710e-01,
            8.870690e-01,
            8.132911e-01,
            7.087989e-01,
            5.816210e-01,
            4.517857e-01,
            3.320210e-01,
            2.262545e-01,
            1.258776e-01,
            7.090000e-02,
            3.550000e-02,
            1.690000e-02,
            6.100000e-03,
            2.500000e-03,
            1.300000e-03,
            5.000000e-04} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {1.001220e+01,
            1.063900e+01,
            1.126580e+01,
            1.189250e+01,
            1.251930e+01,
            1.315000e+01,
            1.377000e+01,
            1.440000e+01,
            1.503000e+01,
            1.565000e+01,
            1.628000e+01,
            1.691000e+01}, // SINR
           {9.489051e-01,
            8.503289e-01,
            7.113260e-01,
            5.146761e-01,
            3.267487e-01,
            1.691275e-01,
            6.510000e-02,
            1.940000e-02,
            4.700000e-03,
            1.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {1.001220e+01,
            1.063900e+01,
            1.126580e+01,
            1.189250e+01,
            1.251930e+01,
            1.315000e+01,
            1.377000e+01,
            1.440000e+01,
            1.503000e+01,
            1.565000e+01,
            1.628000e+01}, // SINR
           {9.439338e-01,
            8.501656e-01,
            6.647135e-01,
            4.528470e-01,
            2.407319e-01,
            9.528186e-02,
            2.960000e-02,
            5.900000e-03,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {9.960000e+00,
            1.039000e+01,
            1.081250e+01,
            1.123920e+01,
            1.166590e+01,
            1.209260e+01,
            1.251930e+01,
            1.295000e+01,
            1.337000e+01,
            1.380000e+01,
            1.423000e+01,
            1.465000e+01,
            1.508000e+01,
            1.551000e+01,
            1.593000e+01}, // SINR
           {9.552239e-01,
            8.948276e-01,
            8.012422e-01,
            6.717105e-01,
            4.941406e-01,
            3.331135e-01,
            1.947450e-01,
            1.026042e-01,
            4.760000e-02,
            1.590000e-02,
            6.000000e-03,
            2.700000e-03,
            7.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {10,
            1.062980e+01,
            1.125970e+01,
            1.188950e+01,
            1.251930e+01,
            1.315000e+01,
            1.378000e+01,
            1.441000e+01,
            1.504000e+01,
            1.567000e+01,
            1.630000e+01}, // SINR
           {9.659091e-01,
            8.445724e-01,
            6.293317e-01,
            3.844985e-01,
            1.691275e-01,
            5.050000e-02,
            1.200000e-02,
            2.500000e-03,
            5.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {120U, // SINR and BLER for CBS 120
       MmWaveEesmErrorModel::DoubleTuple{
           {9.920000e+00,
            1.044070e+01,
            1.096030e+01,
            1.148000e+01,
            1.199960e+01,
            1.251930e+01,
            1.304000e+01,
            1.356000e+01,
            1.408000e+01,
            1.460000e+01,
            1.512000e+01,
            1.564000e+01}, // SINR
           {9.654851e-01,
            8.968531e-01,
            7.427746e-01,
            5.450644e-01,
            3.143564e-01,
            1.428167e-01,
            4.870000e-02,
            1.340000e-02,
            3.200000e-03,
            6.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {184U, // SINR and BLER for CBS 184
       MmWaveEesmErrorModel::DoubleTuple{
           {1.004000e+01,
            1.053450e+01,
            1.103070e+01,
            1.152690e+01,
            1.202310e+01,
            1.251930e+01,
            1.302000e+01,
            1.351000e+01,
            1.401000e+01,
            1.450000e+01,
            15}, // SINR
           {9.561567e-01,
            8.640940e-01,
            6.712240e-01,
            4.006309e-01,
            1.696429e-01,
            4.960000e-02,
            1.000000e-02,
            1.300000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {1.004000e+01,
            1.053450e+01,
            1.103070e+01,
            1.152690e+01,
            1.202310e+01,
            1.251930e+01,
            1.302000e+01,
            1.351000e+01}, // SINR
           {9.151786e-01,
            7.558824e-01,
            4.956226e-01,
            2.184783e-01,
            6.360000e-02,
            1.190000e-02,
            1.200000e-03,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {9.700000e+00,
            1.017000e+01,
            1.063900e+01,
            1.110910e+01,
            1.157910e+01,
            1.204920e+01,
            1.251930e+01,
            1.299000e+01,
            1.346000e+01}, // SINR
           {9.725379e-01,
            8.741497e-01,
            6.895161e-01,
            4.239130e-01,
            1.731824e-01,
            4.820000e-02,
            8.700000e-03,
            9.000000e-04,
            1.000000e-04} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {10,
            1.050000e+01,
            1.100480e+01,
            1.150970e+01,
            1.201450e+01,
            1.251930e+01,
            1.302000e+01,
            1.353000e+01}, // SINR
           {9.326241e-01,
            7.573964e-01,
            4.871673e-01,
            2.079901e-01,
            5.320000e-02,
            8.300000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {9.900000e+00,
            1.020000e+01,
            1.050000e+01,
            1.079590e+01,
            1.109180e+01,
            1.138770e+01,
            1.168360e+01,
            1.198000e+01,
            1.228000e+01,
            1.257000e+01,
            1.287000e+01,
            1.316000e+01,
            1.346000e+01}, // SINR
           {9.489051e-01,
            8.888889e-01,
            7.763554e-01,
            6.072275e-01,
            4.317406e-01,
            2.558198e-01,
            1.207973e-01,
            4.750000e-02,
            1.520000e-02,
            4.200000e-03,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {9.960000e+00,
            1.025000e+01,
            1.053450e+01,
            1.082180e+01,
            1.110900e+01,
            1.139630e+01,
            1.168360e+01,
            1.197000e+01,
            1.226000e+01,
            1.255000e+01,
            1.283000e+01,
            1.312000e+01}, // SINR
           {9.598881e-01,
            8.986014e-01,
            8.020186e-01,
            6.425000e-01,
            4.355670e-01,
            2.497530e-01,
            1.199905e-01,
            4.910000e-02,
            1.390000e-02,
            4.100000e-03,
            9.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {1.020000e+01,
            1.045000e+01,
            1.069890e+01,
            1.094510e+01,
            1.119120e+01,
            1.143740e+01,
            1.168360e+01,
            1.193000e+01,
            1.218000e+01,
            1.242000e+01,
            1.267000e+01,
            1.291000e+01,
            1.316000e+01}, // SINR
           {9.082168e-01,
            8.192675e-01,
            6.660156e-01,
            5.124008e-01,
            3.273964e-01,
            1.931126e-01,
            9.428052e-02,
            3.820000e-02,
            1.260000e-02,
            3.500000e-03,
            5.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.011000e+01,
            1.037000e+01,
            1.063400e+01,
            1.089640e+01,
            1.115880e+01,
            1.142120e+01,
            1.168360e+01,
            1.195000e+01,
            1.221000e+01,
            1.247000e+01,
            1.273000e+01,
            13,
            1.326000e+01}, // SINR
           {9.483696e-01,
            8.616667e-01,
            7.265625e-01,
            5.714286e-01,
            3.642241e-01,
            1.956522e-01,
            9.023312e-02,
            2.980000e-02,
            7.900000e-03,
            1.300000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {1.022000e+01,
            1.051550e+01,
            1.080750e+01,
            1.109950e+01,
            1.139160e+01,
            1.168360e+01,
            1.198000e+01,
            1.227000e+01,
            1.256000e+01,
            1.285000e+01}, // SINR
           {9.110915e-01,
            7.865854e-01,
            6.088517e-01,
            3.611506e-01,
            1.839416e-01,
            7.480000e-02,
            1.990000e-02,
            4.000000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {9.990000e+00,
            1.049480e+01,
            1.100100e+01,
            1.150710e+01,
            1.201320e+01,
            1.251930e+01}, // SINR
           {9.799618e-01,
            8.282258e-01,
            4.800380e-01,
            1.293501e-01,
            1.490000e-02,
            5.000000e-04} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.017000e+01,
            1.064120e+01,
            1.111070e+01,
            1.158020e+01,
            1.204980e+01,
            1.251930e+01},                                                           // SINR
           {9.003497e-01, 6.047619e-01, 2.380169e-01, 4.330000e-02, 3.300000e-03, 0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.016000e+01,
            1.041000e+01,
            1.066770e+01,
            1.092160e+01,
            1.117560e+01,
            1.142960e+01,
            1.168360e+01,
            1.194000e+01,
            1.219000e+01,
            1.245000e+01}, // SINR
           {9.338768e-01,
            8.101266e-01,
            5.835253e-01,
            3.621429e-01,
            1.756285e-01,
            6.090000e-02,
            1.560000e-02,
            2.900000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {1.009000e+01,
            1.057950e+01,
            1.106440e+01,
            1.154940e+01,
            1.203430e+01,
            1.251930e+01}, // SINR
           {9.393116e-01,
            6.001185e-01,
            1.675567e-01,
            1.200000e-02,
            2.000000e-04,
            1.000000e-04} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.002000e+01,
            1.030000e+01,
            1.057950e+01,
            1.085550e+01,
            1.113160e+01,
            1.140760e+01,
            1.168360e+01,
            1.196000e+01,
            1.224000e+01}, // SINR
           {9.689850e-01,
            8.566667e-01,
            6.344697e-01,
            3.393817e-01,
            1.230431e-01,
            2.930000e-02,
            3.900000e-03,
            7.000000e-04,
            0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.009000e+01,
            1.036000e+01,
            1.062830e+01,
            1.089210e+01,
            1.115600e+01,
            1.141980e+01,
            1.168360e+01,
            1.195000e+01}, // SINR
           {9.574074e-01,
            8.453947e-01,
            6.171875e-01,
            3.194095e-01,
            1.072052e-01,
            2.390000e-02,
            2.800000e-03,
            4.000000e-04} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.009000e+01,
            1.036000e+01,
            1.062830e+01,
            1.089210e+01,
            1.115600e+01,
            1.141980e+01,
            1.168360e+01,
            1.195000e+01}, // SINR
           {9.715909e-01,
            8.657718e-01,
            6.219807e-01,
            3.228372e-01,
            9.857143e-02,
            1.740000e-02,
            2.400000e-03,
            2.000000e-04} // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {1.007000e+01,
            1.038000e+01,
            1.069000e+01,
            1.099440e+01,
            1.130050e+01,
            1.160660e+01,
            1.191270e+01,
            1.221880e+01}, // SINR
           {9.678030e-01,
            8.192675e-01,
            4.551971e-01,
            1.419683e-01,
            2.170000e-02,
            2.300000e-03,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {1.016000e+01,
            1.040000e+01,
            1.064000e+01,
            1.088000e+01,
            1.111850e+01,
            1.135530e+01,
            1.159220e+01,
            1.182900e+01,
            1.206580e+01}, // SINR
           {9.527778e-01,
            8.221154e-01,
            5.432692e-01,
            2.522590e-01,
            7.470000e-02,
            1.240000e-02,
            1.400000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {1.006000e+01,
            1.028000e+01,
            1.050000e+01,
            1.072000e+01,
            1.095000e+01,
            1.116970e+01,
            1.139370e+01,
            1.161780e+01,
            1.184180e+01,
            1.206580e+01}, // SINR
           {9.769231e-01,
            8.887931e-01,
            7.152778e-01,
            4.522321e-01,
            1.856618e-01,
            4.870000e-02,
            8.300000e-03,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {9.900000e+00, 1.039000e+01, 1.088000e+01, 1.136750e+01, 1.185500e+01}, // SINR
           {9.894231e-01, 8.608333e-01, 2.701180e-01, 9.800000e-03, 0}             // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {1.013000e+01,
            1.042000e+01,
            1.071000e+01,
            1.099440e+01,
            1.128140e+01,
            1.156840e+01,
            1.185530e+01}, // SINR
           {9.617537e-01,
            7.500000e-01,
            3.624282e-01,
            7.670000e-02,
            5.900000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {9.890000e+00, 1.042000e+01, 1.095000e+01, 1.147500e+01, 12}, // SINR
           {1, 7.903727e-01, 1.073898e-01, 9.000000e-04, 0}              // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.020000e+01, 1.055000e+01, 1.090000e+01, 1.125000e+01, 1.160000e+01}, // SINR
           {9.542910e-01, 5.594714e-01, 1.022632e-01, 2.500000e-03, 0}             // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {9.850000e+00, 1.030000e+01, 1.075000e+01, 1.120000e+01, 1.165000e+01}, // SINR
           {9.990385e-01, 8.827055e-01, 2.304189e-01, 3.700000e-03, 0}             // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {1.015000e+01,
            1.038000e+01,
            1.061000e+01,
            1.084000e+01,
            1.107000e+01,
            1.130050e+01,
            1.153010e+01}, // SINR
           {9.865385e-01,
            8.551325e-01,
            5.060000e-01,
            1.562887e-01,
            2.230000e-02,
            5.000000e-04,
            0} // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {1.038000e+01,
            1.061000e+01,
            1.084000e+01,
            1.107000e+01,
            1.130050e+01,
            1.153010e+01,
            1.175970e+01,
            1.198920e+01}, // SINR
           {9.788462e-01,
            8.224522e-01,
            4.618182e-01,
            1.353162e-01,
            1.930000e-02,
            8.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {1.020000e+01, 1.080000e+01, 1.140000e+01, 12, 1.260000e+01}, // SINR
           {9.942308e-01, 5.518559e-01, 7.900000e-03, 1.000000e-04, 0}   // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {9.950000e+00, 1.073000e+01, 1.111250e+01, 1.150000e+01, 1.227500e+01}, // SINR
           {9.990385e-01, 5.242769e-01, 5.430000e-02, 4.000000e-04, 0}             // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {1.005000e+01, 1.078000e+01, 1.113750e+01, 1.150000e+01, 1.222500e+01}, // SINR
           {1, 4.176325e-01, 3.230000e-02, 6.000000e-04, 0}                        // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {9.950000e+00,
            1.052000e+01,
            1.080000e+01,
            1.108000e+01,
            1.165000e+01,
            1.250000e+01},                                                // SINR
           {1, 8.886054e-01, 4.595324e-01, 6.590000e-02, 2.000000e-04, 0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.043000e+01, 1.080000e+01, 1.116750e+01, 1.153500e+01, 1.190250e+01}, // SINR
           {9.352518e-01, 3.328947e-01, 1.050000e-02, 2.000000e-04, 0}             // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {1.035000e+01, 1.092000e+01, 1.121250e+01, 1.150000e+01, 1.207500e+01}, // SINR
           {9.826923e-01, 1.877794e-01, 8.100000e-03, 1.000000e-04, 0}             // BLER
       }}},
     {      // MCS 17
      {40U, // SINR and BLER for CBS 40
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.166260e+01,
            1.249730e+01,
            1.333200e+01,
            1.416670e+01,
            15,
            1.584000e+01,
            1.667000e+01,
            1.751000e+01,
            1.834000e+01,
            1.917000e+01}, // SINR
           {9.452555e-01,
            8.480392e-01,
            6.400000e-01,
            4.101438e-01,
            2.012000e-01,
            6.950000e-02,
            1.430000e-02,
            1.600000e-03,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.145390e+01,
            1.208000e+01,
            1.270600e+01,
            1.333200e+01,
            1.396000e+01,
            1.458000e+01,
            1.521000e+01,
            1.584000e+01,
            1.646000e+01,
            1.709000e+01,
            1.771000e+01}, // SINR
           {9.275362e-01,
            8.582215e-01,
            7.171788e-01,
            5.152439e-01,
            3.012590e-01,
            1.462704e-01,
            5.360000e-02,
            1.620000e-02,
            2.500000e-03,
            5.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.145390e+01,
            1.208000e+01,
            1.270600e+01,
            1.333200e+01,
            1.396000e+01,
            1.458000e+01,
            1.521000e+01,
            1.584000e+01,
            1.646000e+01}, // SINR
           {9.148936e-01,
            8.128981e-01,
            6.153382e-01,
            4.088710e-01,
            2.112647e-01,
            8.090000e-02,
            2.300000e-02,
            4.900000e-03,
            9.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.145390e+01,
            1.208000e+01,
            1.270600e+01,
            1.333200e+01,
            1.396000e+01,
            1.458000e+01,
            1.521000e+01,
            1.584000e+01,
            1.646000e+01}, // SINR
           {9.388686e-01,
            8.240446e-01,
            6.008255e-01,
            3.580508e-01,
            1.550613e-01,
            4.930000e-02,
            8.500000e-03,
            1.000000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.145390e+01,
            1.208000e+01,
            1.270600e+01,
            1.333200e+01,
            1.396000e+01,
            1.458000e+01,
            1.521000e+01,
            1.584000e+01,
            1.646000e+01}, // SINR
           {9.347826e-01,
            8.200637e-01,
            6.105769e-01,
            3.414634e-01,
            1.293679e-01,
            3.580000e-02,
            6.900000e-03,
            7.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {120U, // SINR and BLER for CBS 120
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.145390e+01,
            1.208000e+01,
            1.270600e+01,
            1.333200e+01,
            1.396000e+01,
            1.458000e+01,
            1.521000e+01,
            1.584000e+01}, // SINR
           {9.406934e-01,
            8.216561e-01,
            5.761364e-01,
            2.991706e-01,
            9.954090e-02,
            1.990000e-02,
            2.500000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {184U, // SINR and BLER for CBS 184
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.145390e+01,
            1.208000e+01,
            1.270600e+01,
            1.333200e+01,
            1.396000e+01,
            1.458000e+01,
            1.521000e+01}, // SINR
           {9.516423e-01,
            7.687126e-01,
            5.044821e-01,
            1.932692e-01,
            3.790000e-02,
            3.800000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {1.020000e+01,
            1.082790e+01,
            1.145390e+01,
            1.208000e+01,
            1.270600e+01,
            1.333200e+01,
            1.396000e+01,
            1.458000e+01}, // SINR
           {9.809160e-01,
            8.913793e-01,
            6.368159e-01,
            2.937935e-01,
            6.920000e-02,
            8.400000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.145390e+01,
            1.208000e+01,
            1.270600e+01,
            1.333200e+01,
            1.396000e+01,
            1.458000e+01}, // SINR
           {9.022887e-01,
            6.361940e-01,
            2.792494e-01,
            6.210000e-02,
            5.600000e-03,
            3.000000e-04,
            2.000000e-04} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.145390e+01,
            1.208000e+01,
            1.270600e+01,
            1.333200e+01,
            1.396000e+01,
            1.458000e+01}, // SINR
           {9.193262e-01,
            6.640625e-01,
            2.765899e-01,
            5.930000e-02,
            6.400000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.110610e+01,
            1.138430e+01,
            1.166260e+01,
            1.194080e+01,
            1.222000e+01,
            1.250000e+01,
            1.278000e+01,
            1.305000e+01,
            1.333000e+01,
            1.361000e+01,
            1.389000e+01,
            1.417000e+01}, // SINR
           {9.058099e-01,
            8.176752e-01,
            6.972973e-01,
            5.095382e-01,
            3.410618e-01,
            1.823444e-01,
            8.958838e-02,
            3.680000e-02,
            1.170000e-02,
            3.200000e-03,
            7.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.124520e+01,
            1.166260e+01,
            1.208000e+01,
            1.249730e+01,
            1.291000e+01,
            1.333000e+01,
            1.375000e+01,
            1.417000e+01}, // SINR
           {9.384058e-01,
            7.981366e-01,
            5.438034e-01,
            2.740175e-01,
            9.523322e-02,
            2.010000e-02,
            3.500000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.124520e+01,
            1.166260e+01,
            1.208000e+01,
            1.249730e+01,
            1.291000e+01,
            1.333000e+01,
            1.375000e+01}, // SINR
           {9.430147e-01,
            7.765152e-01,
            5.004941e-01,
            2.420673e-01,
            6.900000e-02,
            1.360000e-02,
            1.300000e-03,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.145390e+01, 1.208000e+01, 1.270600e+01, 1.333200e+01}, // SINR
           {9.470803e-01, 6.695026e-01, 2.230088e-01, 2.450000e-02, 8.000000e-04}  // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.124520e+01,
            1.166260e+01,
            1.208000e+01,
            1.249730e+01,
            1.291000e+01,
            1.333000e+01,
            1.375000e+01}, // SINR
           {9.356884e-01,
            7.687126e-01,
            4.702602e-01,
            2.052846e-01,
            4.740000e-02,
            6.100000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.145390e+01, 1.208000e+01, 1.270600e+01, 1.333200e+01}, // SINR
           {9.580224e-01, 6.824866e-01, 1.970703e-01, 1.580000e-02, 3.000000e-04}  // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.083000e+01,
            1.111000e+01,
            1.138440e+01,
            1.166260e+01,
            1.194080e+01,
            1.221910e+01,
            1.249730e+01,
            1.278000e+01,
            1.305000e+01,
            1.333000e+01}, // SINR
           {9.143357e-01,
            8.009259e-01,
            6.225728e-01,
            3.593305e-01,
            1.704082e-01,
            6.240000e-02,
            1.660000e-02,
            2.800000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.083000e+01,
            1.111000e+01,
            1.138440e+01,
            1.166260e+01,
            1.194080e+01,
            1.221910e+01,
            1.249730e+01,
            1.278000e+01,
            1.305000e+01}, // SINR
           {9.267857e-01,
            7.981366e-01,
            5.862269e-01,
            3.245501e-01,
            1.297828e-01,
            3.790000e-02,
            6.500000e-03,
            9.000000e-04,
            5.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01,
            1.124520e+01,
            1.166260e+01,
            1.208000e+01,
            1.249730e+01,
            1.291000e+01},                                                           // SINR
           {9.465580e-01, 6.990489e-01, 2.858770e-01, 4.880000e-02, 3.500000e-03, 0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.083000e+01,
            1.111000e+01,
            1.138440e+01,
            1.166260e+01,
            1.194080e+01,
            1.221910e+01,
            1.249730e+01,
            1.278000e+01}, // SINR
           {9.453704e-01,
            7.981366e-01,
            5.510870e-01,
            2.679325e-01,
            8.410000e-02,
            1.510000e-02,
            1.200000e-03,
            0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.082790e+01, 1.124520e+01, 1.166260e+01, 1.208000e+01, 1.249730e+01}, // SINR
           {9.562044e-01, 7.314286e-01, 2.787611e-01, 3.410000e-02, 2.000000e-04}  // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.094000e+01,
            1.111000e+01,
            1.128000e+01,
            1.145000e+01,
            1.162000e+01,
            1.179000e+01,
            1.196360e+01,
            1.213400e+01,
            1.230430e+01,
            1.247470e+01,
            1.264510e+01}, // SINR
           {9.316547e-01,
            8.567881e-01,
            7.004076e-01,
            5.257202e-01,
            3.128094e-01,
            1.602360e-01,
            6.490000e-02,
            2.230000e-02,
            5.200000e-03,
            1.500000e-03,
            5.000000e-04} // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {1.081000e+01,
            1.118000e+01,
            1.155000e+01,
            1.192500e+01,
            1.230000e+01,
            1.267500e+01,
            1.305000e+01}, // SINR
           {9.580224e-01,
            7.434971e-01,
            3.131188e-01,
            5.040000e-02,
            2.200000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {1.077000e+01,
            1.107000e+01,
            1.137000e+01,
            1.167000e+01,
            1.196360e+01,
            1.225900e+01,
            1.255430e+01,
            1.284970e+01}, // SINR
           {9.715909e-01,
            8.470395e-01,
            5.333333e-01,
            1.924543e-01,
            3.350000e-02,
            3.400000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {1.077000e+01,
            1.107000e+01,
            1.137000e+01,
            1.167000e+01,
            1.196360e+01,
            1.225900e+01,
            1.255430e+01,
            1.284970e+01}, // SINR
           {9.855769e-01,
            8.784014e-01,
            5.524892e-01,
            1.986572e-01,
            3.640000e-02,
            2.800000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {1.071000e+01,
            1.105000e+01,
            1.139000e+01,
            1.173000e+01,
            1.207250e+01,
            1.241500e+01,
            1.275750e+01}, // SINR
           {9.865385e-01,
            8.423203e-01,
            4.204167e-01,
            8.493590e-02,
            5.700000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {1.094000e+01,
            1.111000e+01,
            1.128000e+01,
            1.145000e+01,
            1.162000e+01,
            1.179000e+01,
            1.196360e+01,
            1.213400e+01,
            1.230430e+01,
            1.247470e+01,
            1.264510e+01}, // SINR
           {9.241071e-01,
            8.024691e-01,
            5.957944e-01,
            3.645533e-01,
            1.746170e-01,
            5.290000e-02,
            1.320000e-02,
            2.500000e-03,
            5.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.102000e+01,
            1.128000e+01,
            1.154000e+01,
            1.180220e+01,
            1.206340e+01,
            1.232450e+01,
            1.258570e+01,
            1.284690e+01}, // SINR
           {9.223214e-01,
            6.387500e-01,
            2.558081e-01,
            5.020000e-02,
            3.800000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.095000e+01,
            1.124000e+01,
            1.153000e+01,
            1.181210e+01,
            1.209610e+01,
            1.238010e+01},                                                           // SINR
           {9.334532e-01, 6.482412e-01, 2.058703e-01, 2.250000e-02, 1.200000e-03, 0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.095000e+01, 1.129000e+01, 1.163000e+01, 1.197250e+01, 1.231500e+01}, // SINR
           {9.384058e-01, 5.521739e-01, 1.003086e-01, 2.600000e-03, 0}             // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {1.097000e+01,
            1.120000e+01,
            1.143000e+01,
            1.166000e+01,
            1.188790e+01,
            1.211510e+01,
            1.234220e+01}, // SINR
           {9.589552e-01,
            7.435345e-01,
            3.597301e-01,
            8.613782e-02,
            8.200000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {2088U, // SINR and BLER for CBS 2088
       MmWaveEesmErrorModel::DoubleTuple{
           {1.113000e+01,
            1.151000e+01,
            1.169750e+01,
            1.189000e+01,
            1.226500e+01,
            1.283250e+01,
            1.340000e+01}, // SINR
           {9.516423e-01,
            5.193878e-01,
            2.093750e-01,
            4.720000e-02,
            6.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {1.113000e+01, 1.169750e+01, 1.226500e+01, 1.283250e+01, 1.340000e+01}, // SINR
           {9.595865e-01, 2.652632e-01, 1.600000e-03, 1.000000e-04, 0}             // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {1.090000e+01,
            1.130000e+01,
            1.170000e+01,
            1.210000e+01,
            1.250000e+01,
            1.290000e+01}, // SINR
           {9.932692e-01,
            8.035714e-01,
            1.686828e-01,
            3.700000e-03,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {1.115000e+01,
            1.152000e+01,
            1.170000e+01,
            1.188000e+01,
            1.225000e+01,
            1.280000e+01},                                                           // SINR
           {9.114583e-01, 4.041534e-01, 1.441312e-01, 2.850000e-02, 1.000000e-04, 0} // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {11, 1.135000e+01, 1.170000e+01, 1.205000e+01, 1.240000e+01, 1.275000e+01}, // SINR
           {9.942308e-01, 7.823795e-01, 1.678856e-01, 5.200000e-03, 1.000000e-04, 0}   // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.104000e+01, 1.137000e+01, 1.170000e+01, 1.203250e+01, 1.236500e+01}, // SINR
           {9.866412e-01, 6.679688e-01, 9.671160e-02, 1.200000e-03, 0}             // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {1.080000e+01,
            1.123000e+01,
            1.145000e+01,
            1.167000e+01,
            1.210000e+01,
            1.275000e+01},                                                // SINR
           {1, 9.280576e-01, 6.147837e-01, 1.694858e-01, 7.000000e-04, 0} // BLER
       }}},
     {      // MCS 18
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {1.120000e+01,
            1.168750e+01,
            1.217500e+01,
            1.266250e+01,
            1.315000e+01,
            1.364000e+01,
            1.413000e+01,
            1.461000e+01,
            1.510000e+01,
            1.559000e+01,
            1.608000e+01,
            1.656000e+01,
            1.705000e+01,
            1.754000e+01,
            1.803000e+01,
            1.852000e+01,
            1.901000e+01,
            1.949000e+01}, // SINR
           {9.875000e-01,
            9.706439e-01,
            9.486940e-01,
            8.993056e-01,
            8.431373e-01,
            7.420520e-01,
            6.225610e-01,
            4.566787e-01,
            3.230230e-01,
            2.004792e-01,
            1.017828e-01,
            4.690000e-02,
            2.100000e-02,
            8.700000e-03,
            2.900000e-03,
            9.000000e-04,
            5.000000e-04,
            1.000000e-04} // BLER
       }},
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {1.079690e+01,
            1.145380e+01,
            1.211070e+01,
            1.276760e+01,
            1.342450e+01,
            1.408000e+01,
            1.474000e+01,
            1.540000e+01,
            1.605000e+01,
            1.671000e+01,
            1.737000e+01,
            1.802000e+01,
            1.868000e+01,
            1.934000e+01,
            1.999000e+01}, // SINR
           {9.855769e-01,
            9.470803e-01,
            8.931034e-01,
            7.901235e-01,
            6.107143e-01,
            3.904799e-01,
            2.054739e-01,
            7.780000e-02,
            1.920000e-02,
            3.200000e-03,
            7.000000e-04,
            2.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {1.079690e+01,
            1.145380e+01,
            1.211070e+01,
            1.276760e+01,
            1.342450e+01,
            1.408000e+01,
            1.474000e+01,
            1.540000e+01,
            1.605000e+01,
            1.671000e+01,
            1.737000e+01}, // SINR
           {9.855769e-01,
            9.558824e-01,
            8.783784e-01,
            7.101955e-01,
            4.814639e-01,
            2.525000e-01,
            9.440419e-02,
            2.210000e-02,
            2.600000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {96U, // SINR and BLER for CBS 96
       MmWaveEesmErrorModel::DoubleTuple{
           {1.120000e+01,
            1.168750e+01,
            1.217500e+01,
            1.266250e+01,
            1.315000e+01,
            1.364000e+01,
            1.413000e+01,
            1.461000e+01,
            1.510000e+01,
            1.559000e+01,
            1.608000e+01,
            1.656000e+01,
            1.705000e+01,
            1.754000e+01,
            1.803000e+01}, // SINR
           {9.701493e-01,
            9.133929e-01,
            8.269231e-01,
            6.608073e-01,
            4.773585e-01,
            2.964706e-01,
            1.568750e-01,
            6.370000e-02,
            1.950000e-02,
            4.500000e-03,
            4.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {1.117280e+01,
            1.151680e+01,
            1.186070e+01,
            1.220470e+01,
            1.254860e+01,
            1.289000e+01,
            1.324000e+01,
            1.358000e+01,
            1.392000e+01,
            1.427000e+01,
            1.461000e+01,
            1.496000e+01,
            1.530000e+01,
            1.564000e+01,
            1.599000e+01}, // SINR
           {9.630682e-01,
            9.276786e-01,
            8.758562e-01,
            7.878086e-01,
            6.541878e-01,
            5.280083e-01,
            3.757418e-01,
            2.353352e-01,
            1.352481e-01,
            6.670000e-02,
            3.100000e-02,
            9.500000e-03,
            3.200000e-03,
            9.000000e-04,
            2.000000e-04} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {1.117280e+01,
            1.151680e+01,
            1.186070e+01,
            1.220470e+01,
            1.254860e+01,
            1.289000e+01,
            1.324000e+01,
            1.358000e+01,
            1.392000e+01,
            1.427000e+01,
            1.461000e+01,
            1.496000e+01,
            1.530000e+01,
            1.564000e+01,
            1.599000e+01}, // SINR
           {9.601852e-01,
            9.237589e-01,
            8.606419e-01,
            7.434593e-01,
            6.047619e-01,
            4.454225e-01,
            2.979858e-01,
            1.715553e-01,
            8.927142e-02,
            3.750000e-02,
            1.460000e-02,
            4.800000e-03,
            9.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.116000e+01,
            1.150000e+01,
            1.184500e+01,
            1.219000e+01,
            1.253500e+01,
            1.288000e+01,
            1.323000e+01,
            1.357000e+01,
            1.392000e+01,
            1.426000e+01,
            1.461000e+01,
            1.495000e+01,
            1.530000e+01,
            1.564000e+01}, // SINR
           {9.531250e-01,
            8.952465e-01,
            7.960123e-01,
            6.439394e-01,
            4.328231e-01,
            2.611515e-01,
            1.280644e-01,
            5.430000e-02,
            1.850000e-02,
            4.600000e-03,
            9.000000e-04,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {1.118000e+01,
            1.162500e+01,
            1.207490e+01,
            1.252480e+01,
            1.297460e+01,
            1.342450e+01,
            1.387000e+01,
            1.432000e+01,
            1.477000e+01,
            1.522000e+01,
            1.567000e+01}, // SINR
           {9.481481e-01,
            8.525000e-01,
            6.612694e-01,
            4.383621e-01,
            1.986572e-01,
            6.830000e-02,
            1.820000e-02,
            4.000000e-03,
            6.000000e-04,
            3.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {1.139190e+01,
            1.190010e+01,
            1.240820e+01,
            1.291630e+01,
            1.342450e+01,
            1.393000e+01,
            1.444000e+01,
            1.495000e+01,
            1.546000e+01}, // SINR
           {9.178571e-01,
            7.111111e-01,
            4.353448e-01,
            1.851103e-01,
            4.770000e-02,
            8.500000e-03,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {1.079690e+01,
            1.145380e+01,
            1.211070e+01,
            1.276760e+01,
            1.342450e+01,
            1.408000e+01,
            1.474000e+01,
            1.540000e+01}, // SINR
           {9.875000e-01,
            8.959790e-01,
            5.877294e-01,
            2.337361e-01,
            3.750000e-02,
            2.800000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.250000e+01,
            1.280000e+01,
            1.310000e+01,
            1.340000e+01,
            1.370000e+01,
            14,
            1.430000e+01,
            1.460000e+01,
            1.490000e+01}, // SINR
           {9.225352e-01,
            8.176752e-01,
            6.636598e-01,
            4.847328e-01,
            3.045564e-01,
            1.560174e-01,
            6.480000e-02,
            2.350000e-02,
            8.100000e-03,
            2.400000e-03,
            6.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.065370e+01, 1.167280e+01, 1.269190e+01, 1.371100e+01, 1.473010e+01}, // SINR
           {9.971154e-01, 8.000000e-01, 1.721730e-01, 3.800000e-03, 0}             // BLER
       }},
      {320U, // SINR and BLER for CBS 320
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.165000e+01,
            12,
            1.235000e+01,
            1.270000e+01,
            1.305000e+01,
            1.340000e+01,
            1.375000e+01,
            1.410000e+01,
            1.445000e+01,
            1.480000e+01,
            1.515000e+01,
            1.550000e+01}, // SINR
           {9.073427e-01,
            7.712121e-01,
            5.575658e-01,
            3.270725e-01,
            1.385509e-01,
            3.810000e-02,
            9.200000e-03,
            1.300000e-03,
            6.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.150000e+01,
            1.170000e+01,
            1.190000e+01,
            1.210000e+01,
            1.230000e+01,
            1.250000e+01,
            1.270000e+01,
            1.290000e+01,
            1.310000e+01,
            1.330000e+01,
            1.350000e+01,
            1.370000e+01,
            1.390000e+01,
            1.410000e+01,
            1.430000e+01}, // SINR
           {9.586397e-01,
            8.984375e-01,
            8.250000e-01,
            7.183989e-01,
            5.844749e-01,
            4.422743e-01,
            3.085172e-01,
            1.926606e-01,
            1.022917e-01,
            4.770000e-02,
            1.990000e-02,
            8.100000e-03,
            2.500000e-03,
            9.000000e-04,
            2.000000e-04} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {1.150000e+01,
            1.177500e+01,
            1.205000e+01,
            1.232500e+01,
            1.260000e+01,
            1.288000e+01,
            1.315000e+01,
            1.342000e+01,
            1.370000e+01,
            1.398000e+01,
            1.425000e+01,
            1.452000e+01}, // SINR
           {9.509259e-01,
            8.758446e-01,
            7.514620e-01,
            5.470085e-01,
            3.500693e-01,
            1.797210e-01,
            7.320000e-02,
            2.170000e-02,
            5.300000e-03,
            1.000000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {1.167280e+01,
            1.211070e+01,
            1.254870e+01,
            1.298660e+01,
            1.342450e+01,
            1.386000e+01,
            1.430000e+01,
            1.474000e+01}, // SINR
           {9.029720e-01,
            6.615385e-01,
            3.083741e-01,
            8.504428e-02,
            1.200000e-02,
            1.000000e-03,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.142000e+01,
            1.170000e+01,
            1.197500e+01,
            1.225000e+01,
            1.252500e+01,
            1.280000e+01,
            1.308000e+01,
            1.335000e+01,
            1.363000e+01,
            1.390000e+01,
            1.418000e+01,
            1.445000e+01}, // SINR
           {9.241071e-01,
            7.970679e-01,
            6.195652e-01,
            4.041534e-01,
            1.960938e-01,
            7.210000e-02,
            2.010000e-02,
            5.100000e-03,
            7.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.142000e+01,
            1.170000e+01,
            1.197500e+01,
            1.225000e+01,
            1.252500e+01,
            1.280000e+01,
            1.308000e+01,
            1.335000e+01,
            1.363000e+01,
            1.390000e+01,
            1.418000e+01}, // SINR
           {9.175532e-01,
            7.740964e-01,
            5.418432e-01,
            2.823661e-01,
            1.078856e-01,
            3.320000e-02,
            5.000000e-03,
            1.200000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {1.138000e+01,
            1.167280e+01,
            1.196480e+01,
            1.225670e+01,
            1.254870e+01,
            1.284060e+01,
            1.313000e+01,
            1.342000e+01,
            1.372000e+01}, // SINR
           {9.294643e-01,
            8.070312e-01,
            5.490302e-01,
            2.487648e-01,
            7.970000e-02,
            1.460000e-02,
            1.600000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01,
            1.338450e+01}, // SINR
           {9.485294e-01,
            8.224522e-01,
            5.584061e-01,
            2.535141e-01,
            7.110000e-02,
            1.260000e-02,
            9.000000e-04,
            0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01,
            1.338450e+01,
            1.368150e+01}, // SINR
           {9.583333e-01,
            8.097484e-01,
            5.226337e-01,
            2.107802e-01,
            4.670000e-02,
            5.400000e-03,
            8.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01,
            1.338450e+01,
            1.368150e+01}, // SINR
           {9.548872e-01,
            8.026730e-01,
            5.039526e-01,
            1.801576e-01,
            3.690000e-02,
            3.900000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01,
            1.338450e+01}, // SINR
           {9.696970e-01,
            8.518212e-01,
            5.437764e-01,
            2.035308e-01,
            3.880000e-02,
            2.900000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01,
            1.338450e+01}, // SINR
           {9.696970e-01,
            8.346774e-01,
            5.039370e-01,
            1.730372e-01,
            3.100000e-02,
            2.200000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01}, // SINR
           {9.706439e-01,
            8.392857e-01,
            4.819392e-01,
            1.505376e-01,
            2.360000e-02,
            2.000000e-03,
            0} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01}, // SINR
           {9.750000e-01,
            8.241935e-01,
            4.557762e-01,
            1.250000e-01,
            1.450000e-02,
            8.000000e-04,
            0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01}, // SINR
           {9.913462e-01,
            8.750000e-01,
            5.339958e-01,
            1.471704e-01,
            1.720000e-02,
            1.300000e-03,
            0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.130000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01,
            1.338450e+01}, // SINR
           {9.884615e-01,
            8.836207e-01,
            4.743470e-01,
            1.135332e-01,
            9.900000e-03,
            6.000000e-04,
            3.000000e-04,
            0} // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.071000e+01,
            1.101000e+01,
            1.131000e+01,
            1.160000e+01,
            1.190000e+01,
            1.220000e+01,
            1.249360e+01,
            1.279060e+01,
            1.308760e+01,
            1.338450e+01,
            1.368150e+01}, // SINR
           {1,
            9.990385e-01,
            9.865385e-01,
            8.551325e-01,
            4.261745e-01,
            7.810000e-02,
            5.400000e-03,
            3.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.136280e+01,
            1.188000e+01,
            1.213000e+01,
            1.239000e+01,
            1.290000e+01,
            1.367330e+01},                                                           // SINR
           {9.727444e-01, 4.194079e-01, 1.075758e-01, 1.010000e-02, 1.000000e-04, 0} // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {1.121000e+01, 1.188000e+01, 1.221000e+01, 1.254000e+01, 1.321120e+01}, // SINR
           {9.913462e-01, 3.691520e-01, 3.240000e-02, 6.000000e-04, 0}             // BLER
       }},
      {2152U, // SINR and BLER for CBS 2152
       MmWaveEesmErrorModel::DoubleTuple{
           {9.950000e+00, 1.104000e+01, 1.157940e+01, 1.212000e+01, 1.321120e+01}, // SINR
           {1, 9.990385e-01, 8.173077e-01, 6.750000e-02, 0}                        // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {1.164130e+01, 1.216000e+01, 1.269000e+01, 1.321120e+01}, // SINR
           {9.732824e-01, 3.825758e-01, 4.500000e-03, 0}             // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {1.117000e+01, 1.165840e+01, 1.215000e+01, 1.313120e+01, 1.460390e+01}, // SINR
           {1, 8.968531e-01, 2.010000e-01, 1.000000e-04, 0}                        // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {1.083000e+01, 1.152000e+01, 1.186290e+01, 1.220000e+01, 1.289210e+01}, // SINR
           {1, 9.875954e-01, 7.898773e-01, 2.239305e-01, 0}                        // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.024000e+01, 1.134000e+01, 1.188890e+01, 1.244000e+01, 1.354180e+01}, // SINR
           {1, 9.990385e-01, 7.567365e-01, 2.300000e-02, 0}                        // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.060000e+01, 1.145000e+01, 1.187500e+01, 1.230000e+01, 1.315440e+01}, // SINR
           {1, 9.990385e-01, 7.908951e-01, 7.350000e-02, 0}                        // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {1.176080e+01, 1.218000e+01, 1.260000e+01, 1.302230e+01, 1.428370e+01}, // SINR
           {9.205357e-01, 2.176166e-01, 1.700000e-03, 2.000000e-04, 0}             // BLER
       }}},
     {      // MCS 19
      {48U, // SINR and BLER for CBS 48
       MmWaveEesmErrorModel::DoubleTuple{
           {12,
            1.277820e+01,
            1.355650e+01,
            1.433470e+01,
            1.511300e+01,
            1.589000e+01,
            1.667000e+01,
            1.745000e+01,
            1.823000e+01,
            19,
            1.978000e+01}, // SINR
           {9.533582e-01,
            8.886986e-01,
            7.522189e-01,
            5.506466e-01,
            3.176692e-01,
            1.328125e-01,
            4.180000e-02,
            1.030000e-02,
            2.200000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {1.234600e+01,
            1.303780e+01,
            1.372950e+01,
            1.442130e+01,
            1.511300e+01,
            1.580000e+01,
            1.650000e+01,
            1.719000e+01,
            1.788000e+01,
            1.857000e+01,
            1.926000e+01}, // SINR
           {9.761450e-01,
            9.258929e-01,
            8.173077e-01,
            6.231796e-01,
            3.840634e-01,
            1.791845e-01,
            5.520000e-02,
            1.530000e-02,
            3.000000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {1.262500e+01,
            1.300930e+01,
            1.339360e+01,
            1.377780e+01,
            1.416210e+01,
            1.455000e+01,
            1.493000e+01,
            1.531000e+01,
            1.570000e+01,
            1.608000e+01,
            1.647000e+01,
            1.685000e+01,
            1.724000e+01,
            1.762000e+01,
            18}, // SINR
           {9.169643e-01,
            8.551325e-01,
            7.702096e-01,
            6.640625e-01,
            5.254149e-01,
            3.791291e-01,
            2.460784e-01,
            1.427557e-01,
            6.770000e-02,
            2.690000e-02,
            1.040000e-02,
            3.500000e-03,
            1.300000e-03,
            5.000000e-04,
            3.000000e-04} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.229000e+01,
            1.260000e+01,
            1.291160e+01,
            1.322420e+01,
            1.353690e+01,
            1.384950e+01,
            1.416210e+01,
            1.447000e+01,
            1.479000e+01,
            1.510000e+01,
            1.541000e+01,
            1.573000e+01,
            1.604000e+01,
            1.635000e+01,
            1.666000e+01,
            1.698000e+01}, // SINR
           {9.334532e-01,
            8.750000e-01,
            8.078125e-01,
            7.219101e-01,
            6.177536e-01,
            4.913127e-01,
            3.691691e-01,
            2.723599e-01,
            1.666114e-01,
            9.533034e-02,
            4.780000e-02,
            2.060000e-02,
            7.700000e-03,
            2.200000e-03,
            1.100000e-03,
            4.000000e-04} // BLER
       }},
      {120U, // SINR and BLER for CBS 120
       MmWaveEesmErrorModel::DoubleTuple{
           {1.212910e+01,
            1.253490e+01,
            1.294070e+01,
            1.334650e+01,
            1.375230e+01,
            1.416000e+01,
            1.456000e+01,
            1.497000e+01,
            1.538000e+01,
            1.578000e+01,
            1.619000e+01,
            1.659000e+01,
            17}, // SINR
           {9.214286e-01,
            8.500000e-01,
            7.413295e-01,
            5.856164e-01,
            4.176325e-01,
            2.550607e-01,
            1.333510e-01,
            5.400000e-02,
            1.860000e-02,
            6.200000e-03,
            1.600000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {144U, // SINR and BLER for CBS 144
       MmWaveEesmErrorModel::DoubleTuple{
           {1.242000e+01,
            1.276510e+01,
            1.311440e+01,
            1.346360e+01,
            1.381290e+01,
            1.416210e+01,
            1.451000e+01,
            1.486000e+01,
            1.521000e+01,
            1.556000e+01,
            1.591000e+01,
            1.626000e+01,
            1.661000e+01,
            1.696000e+01,
            1.731000e+01}, // SINR
           {9.452555e-01,
            8.881119e-01,
            7.885802e-01,
            6.627604e-01,
            5.260417e-01,
            3.753687e-01,
            2.404580e-01,
            1.190814e-01,
            5.150000e-02,
            1.890000e-02,
            6.000000e-03,
            1.600000e-03,
            6.000000e-04,
            2.000000e-04,
            1.000000e-04} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.194000e+01,
            1.247000e+01,
            13,
            1.352820e+01,
            1.405650e+01,
            1.458470e+01,
            1.511300e+01,
            1.564000e+01,
            1.617000e+01}, // SINR
           {9.570896e-01,
            8.566667e-01,
            6.516497e-01,
            3.753698e-01,
            1.457126e-01,
            3.820000e-02,
            6.800000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {1.274730e+01,
            1.310100e+01,
            1.345470e+01,
            1.380840e+01,
            1.416210e+01,
            1.452000e+01,
            1.487000e+01,
            1.522000e+01,
            1.558000e+01,
            1.593000e+01,
            1.628000e+01,
            1.664000e+01}, // SINR
           {9.343525e-01,
            8.415033e-01,
            7.085635e-01,
            5.235656e-01,
            3.393333e-01,
            1.753134e-01,
            7.340000e-02,
            2.260000e-02,
            4.800000e-03,
            1.000000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {1.276260e+01,
            1.311250e+01,
            1.346230e+01,
            1.381220e+01,
            1.416210e+01,
            1.451000e+01,
            1.486000e+01,
            1.521000e+01,
            1.556000e+01,
            1.591000e+01,
            1.626000e+01}, // SINR
           {9.226619e-01,
            8.168239e-01,
            6.318408e-01,
            4.340753e-01,
            2.500000e-01,
            1.110864e-01,
            4.040000e-02,
            9.900000e-03,
            2.100000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.233000e+01,
            1.269950e+01,
            1.306520e+01,
            1.343080e+01,
            1.379650e+01,
            1.416210e+01,
            1.453000e+01,
            1.489000e+01,
            1.526000e+01,
            1.562000e+01,
            1.599000e+01}, // SINR
           {9.416058e-01,
            8.429276e-01,
            6.967213e-01,
            4.815341e-01,
            2.757592e-01,
            1.243812e-01,
            3.950000e-02,
            9.700000e-03,
            1.200000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.225000e+01,
            1.263580e+01,
            1.301740e+01,
            1.339900e+01,
            1.378050e+01,
            1.416210e+01,
            1.454000e+01,
            1.493000e+01,
            1.531000e+01,
            1.569000e+01}, // SINR
           {9.546296e-01,
            8.224522e-01,
            6.053571e-01,
            3.643162e-01,
            1.671647e-01,
            5.720000e-02,
            1.250000e-02,
            1.900000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {320U, // SINR and BLER for CBS 320
       MmWaveEesmErrorModel::DoubleTuple{
           {1.231000e+01,
            1.267930e+01,
            1.305000e+01,
            1.342070e+01,
            1.379140e+01,
            1.416210e+01,
            1.453000e+01,
            1.490000e+01,
            1.527000e+01}, // SINR
           {9.012238e-01,
            7.514620e-01,
            5.141129e-01,
            2.983491e-01,
            1.187144e-01,
            3.600000e-02,
            7.100000e-03,
            1.300000e-03,
            0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.214000e+01,
            1.273250e+01,
            1.332760e+01,
            1.392280e+01,
            1.451790e+01,
            1.511300e+01}, // SINR
           {9.780534e-01,
            8.724490e-01,
            5.378151e-01,
            1.689098e-01,
            2.180000e-02,
            1.000000e-03} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {1.238000e+01,
            1.273630e+01,
            1.309280e+01,
            1.344920e+01,
            1.380560e+01,
            1.416210e+01,
            1.452000e+01,
            1.488000e+01,
            1.523000e+01,
            1.559000e+01}, // SINR
           {9.558271e-01,
            8.431373e-01,
            6.387500e-01,
            3.924689e-01,
            1.833212e-01,
            5.720000e-02,
            1.120000e-02,
            1.300000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {1.211000e+01,
            1.245000e+01,
            1.279470e+01,
            1.313660e+01,
            1.347840e+01,
            1.382030e+01,
            1.416210e+01,
            1.450000e+01,
            1.485000e+01,
            1.519000e+01,
            1.553000e+01}, // SINR
           {9.790076e-01,
            8.958333e-01,
            7.278571e-01,
            4.806604e-01,
            2.223940e-01,
            7.940000e-02,
            2.110000e-02,
            4.500000e-03,
            7.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.242000e+01,
            1.276870e+01,
            1.311710e+01,
            1.346540e+01,
            1.381380e+01,
            1.416210e+01,
            1.451000e+01,
            1.486000e+01,
            1.521000e+01,
            1.556000e+01}, // SINR
           {9.402174e-01,
            8.184713e-01,
            5.868056e-01,
            3.039157e-01,
            1.187263e-01,
            2.950000e-02,
            3.900000e-03,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.241000e+01,
            1.274000e+01,
            1.307000e+01,
            1.340000e+01,
            1.372590e+01,
            1.405180e+01,
            1.437780e+01,
            1.470370e+01}, // SINR
           {9.715909e-01,
            8.784247e-01,
            6.323892e-01,
            3.401084e-01,
            1.316964e-01,
            3.300000e-02,
            5.200000e-03,
            7.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {1.238000e+01,
            1.267000e+01,
            1.296000e+01,
            1.325000e+01,
            1.353890e+01,
            1.383010e+01,
            1.412130e+01,
            1.441250e+01,
            1.470370e+01}, // SINR
           {9.119718e-01,
            7.241379e-01,
            4.583333e-01,
            2.093023e-01,
            6.140000e-02,
            1.070000e-02,
            1.300000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.245000e+01,
            1.281000e+01,
            1.317000e+01,
            1.353890e+01,
            1.390290e+01,
            1.426690e+01,
            1.463090e+01,
            1.499490e+01}, // SINR
           {9.379496e-01,
            7.005495e-01,
            3.373016e-01,
            8.850000e-02,
            1.100000e-02,
            1.000000e-03,
            2.000000e-04,
            1.000000e-04} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.231000e+01,
            1.278650e+01,
            1.326580e+01,
            1.374510e+01,
            1.422440e+01,
            1.470370e+01}, // SINR
           {9.352190e-01,
            5.848624e-01,
            1.361413e-01,
            8.000000e-03,
            4.000000e-04,
            3.000000e-04} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.238000e+01,
            1.267000e+01,
            1.296000e+01,
            1.325000e+01,
            1.353890e+01,
            1.383010e+01,
            1.412130e+01,
            1.441250e+01,
            1.470370e+01}, // SINR
           {9.388489e-01,
            7.739521e-01,
            4.372837e-01,
            1.697154e-01,
            3.690000e-02,
            4.600000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {1.216000e+01,
            1.252000e+01,
            1.288000e+01,
            1.324770e+01,
            1.361170e+01,
            1.397570e+01,
            1.433970e+01,
            1.470370e+01}, // SINR
           {9.894231e-01,
            8.921233e-01,
            5.723094e-01,
            1.668883e-01,
            2.410000e-02,
            1.600000e-03,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {1.238000e+01,
            1.267000e+01,
            1.296000e+01,
            1.325000e+01,
            1.353890e+01,
            1.383010e+01,
            1.412130e+01,
            1.441250e+01,
            1.470370e+01}, // SINR
           {9.642857e-01,
            8.180380e-01,
            5.384615e-01,
            2.001192e-01,
            4.090000e-02,
            3.400000e-03,
            3.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {1.217000e+01, 1.270000e+01, 1.323250e+01, 1.376500e+01, 1.429750e+01}, // SINR
           {9.865385e-01, 6.792328e-01, 1.088106e-01, 2.300000e-03, 0}             // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {1.217000e+01,
            1.261860e+01,
            1.306710e+01,
            1.351560e+01,
            1.396400e+01,
            1.441250e+01},                                                           // SINR
           {9.894231e-01, 8.081761e-01, 2.545363e-01, 1.890000e-02, 2.000000e-04, 0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {1.217000e+01, 1.270000e+01, 1.323250e+01, 1.376500e+01, 1.429750e+01}, // SINR
           {9.903846e-01, 6.759259e-01, 7.370000e-02, 4.000000e-04, 0}             // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.217000e+01, 1.280000e+01, 1.343250e+01, 1.406500e+01, 1.469750e+01}, // SINR
           {9.903846e-01, 5.425532e-01, 1.290000e-02, 2.000000e-04, 0}             // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.190000e+01, 1.260000e+01, 1.330000e+01, 14, 1.470000e+01, 1.540000e+01}, // SINR
           {1, 8.566667e-01, 4.260000e-02, 1.000000e-04, 1.000000e-04, 0}              // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.245000e+01, 13, 1.355000e+01, 1.410000e+01}, // SINR
           {9.307554e-01, 2.791020e-01, 3.000000e-03, 0}   // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {1.156000e+01, 1.261000e+01, 1.313810e+01, 1.367000e+01, 1.471970e+01}, // SINR
           {1, 8.293269e-01, 9.367446e-02, 1.000000e-04, 0}                        // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {1.179000e+01,
            1.257000e+01,
            1.296120e+01,
            1.335000e+01,
            1.412970e+01,
            1.529820e+01},                                                // SINR
           {1, 7.433824e-01, 1.374589e-01, 2.300000e-03, 1.000000e-04, 0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {1.193000e+01,
            1.286000e+01,
            1.332380e+01,
            1.379000e+01,
            1.471970e+01,
            1.611550e+01},                                                // SINR
           {1, 2.826577e-01, 4.300000e-03, 1.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {2408U, // SINR and BLER for CBS 2408
       MmWaveEesmErrorModel::DoubleTuple{
           {1.205170e+01,
            1.294000e+01,
            1.338570e+01,
            1.383000e+01,
            1.471960e+01,
            1.605360e+01},                                                // SINR
           {1, 2.605670e-01, 4.000000e-03, 2.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {1.189000e+01,
            1.261000e+01,
            1.296120e+01,
            1.332000e+01,
            1.403680e+01,
            1.511250e+01},                                                // SINR
           {1, 9.780534e-01, 6.642670e-01, 1.081349e-01, 4.000000e-04, 0} // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.188000e+01, 1.256000e+01, 1.290620e+01, 1.325000e+01, 1.393370e+01}, // SINR
           {1, 9.687500e-01, 5.950704e-01, 8.320000e-02, 0}                        // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.267070e+01, 1.310000e+01, 1.352000e+01, 1.395130e+01, 1.523190e+01}, // SINR
           {9.379496e-01, 2.940835e-01, 3.900000e-03, 2.000000e-04, 0}             // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {1.225000e+01, 1.275000e+01, 13, 1.325000e+01, 1.375000e+01, 1.450460e+01}, // SINR
           {1, 8.262987e-01, 3.447690e-01, 4.350000e-02, 3.000000e-04, 0}              // BLER
       }}},
     {      // MCS 20
      {56U, // SINR and BLER for CBS 56
       MmWaveEesmErrorModel::DoubleTuple{
           {1.346970e+01,
            1.403830e+01,
            1.460700e+01,
            1.517560e+01,
            1.574420e+01,
            1.631000e+01,
            1.688000e+01,
            1.745000e+01,
            1.802000e+01,
            1.859000e+01,
            1.916000e+01,
            1.972000e+01,
            2.029000e+01,
            2.086000e+01}, // SINR
           {9.525547e-01,
            9.055944e-01,
            8.117188e-01,
            6.743421e-01,
            4.975869e-01,
            3.228900e-01,
            1.884384e-01,
            9.369952e-02,
            4.010000e-02,
            1.340000e-02,
            3.700000e-03,
            1.000000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {1.279000e+01,
            1.328000e+01,
            1.377050e+01,
            1.426390e+01,
            1.475730e+01,
            1.525080e+01,
            1.574420e+01,
            1.624000e+01,
            1.673000e+01,
            1.722000e+01,
            1.772000e+01,
            1.821000e+01,
            1.870000e+01,
            1.920000e+01,
            1.969000e+01}, // SINR
           {9.457721e-01,
            8.972603e-01,
            8.089623e-01,
            6.664474e-01,
            5.223577e-01,
            3.447690e-01,
            1.938657e-01,
            8.788122e-02,
            3.520000e-02,
            1.390000e-02,
            3.700000e-03,
            1.100000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {96U, // SINR and BLER for CBS 96
       MmWaveEesmErrorModel::DoubleTuple{
           {1.331000e+01,
            1.379550e+01,
            1.428270e+01,
            1.476990e+01,
            1.525700e+01,
            1.574420e+01,
            1.623000e+01,
            1.672000e+01,
            1.721000e+01,
            1.769000e+01,
            1.818000e+01,
            1.867000e+01,
            1.915000e+01}, // SINR
           {9.476103e-01,
            8.784014e-01,
            7.733434e-01,
            6.050469e-01,
            4.265940e-01,
            2.400000e-01,
            1.204327e-01,
            5.060000e-02,
            1.830000e-02,
            4.800000e-03,
            1.200000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {1.319000e+01, 1.334000e+01, 1.349000e+01, 1.365000e+01, 1.379940e+01, 1.395280e+01,
            1.410610e+01, 1.425950e+01, 1.441290e+01, 1.457000e+01, 1.472000e+01, 1.487000e+01,
            1.503000e+01, 1.518000e+01, 1.533000e+01, 1.549000e+01, 1.564000e+01, 1.579000e+01,
            1.595000e+01, 1.610000e+01, 1.625000e+01, 1.641000e+01, 1.656000e+01, 1.672000e+01,
            1.687000e+01, 1.702000e+01, 1.717000e+01, 1.733000e+01, 1.748000e+01, 1.763000e+01,
            1.779000e+01, 1.794000e+01, 1.809000e+01}, // SINR
           {9.113475e-01, 8.869863e-01, 8.657718e-01, 8.317308e-01, 7.842988e-01, 7.349138e-01,
            6.878378e-01, 6.299505e-01, 5.622222e-01, 4.879344e-01, 4.308874e-01, 3.636040e-01,
            3.064320e-01, 2.502485e-01, 1.958723e-01, 1.535758e-01, 1.140073e-01, 8.490000e-02,
            5.950000e-02, 4.290000e-02, 2.830000e-02, 1.870000e-02, 1.300000e-02, 1.030000e-02,
            7.000000e-03, 4.200000e-03, 2.800000e-03, 1.600000e-03, 1.400000e-03, 7.000000e-04,
            3.000000e-04, 2.000000e-04, 1.000000e-04} // BLER
       }},
      {152U, // SINR and BLER for CBS 152
       MmWaveEesmErrorModel::DoubleTuple{
           {1.293460e+01,
            1.363700e+01,
            1.433940e+01,
            1.504180e+01,
            1.574420e+01,
            1.645000e+01,
            1.715000e+01,
            1.785000e+01,
            1.855000e+01,
            1.926000e+01}, // SINR
           {9.617537e-01,
            8.327922e-01,
            5.334728e-01,
            2.287138e-01,
            4.980000e-02,
            6.700000e-03,
            7.000000e-04,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.318000e+01,
            1.340000e+01,
            1.362000e+01,
            1.384360e+01,
            1.406260e+01,
            1.428160e+01,
            1.450070e+01,
            1.471970e+01,
            1.494000e+01,
            1.516000e+01,
            1.538000e+01,
            1.560000e+01,
            1.581000e+01,
            1.603000e+01,
            1.625000e+01,
            1.647000e+01,
            1.669000e+01}, // SINR
           {9.253597e-01,
            8.889860e-01,
            8.261218e-01,
            7.441860e-01,
            6.413317e-01,
            5.348958e-01,
            4.168033e-01,
            3.148148e-01,
            2.050081e-01,
            1.293860e-01,
            6.970000e-02,
            3.640000e-02,
            1.830000e-02,
            8.400000e-03,
            3.400000e-03,
            1.300000e-03,
            5.000000e-04} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {1.270740e+01,
            1.346660e+01,
            1.422580e+01,
            1.498500e+01,
            1.574420e+01,
            1.650000e+01,
            1.726000e+01,
            1.802000e+01}, // SINR
           {9.980769e-01,
            9.547101e-01,
            7.695783e-01,
            3.787313e-01,
            7.520000e-02,
            4.600000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {1.270740e+01,
            1.346660e+01,
            1.422580e+01,
            1.498500e+01,
            1.574420e+01,
            1.650000e+01,
            1.726000e+01}, // SINR
           {9.932692e-01,
            9.241071e-01,
            6.717105e-01,
            2.683511e-01,
            3.330000e-02,
            1.200000e-03,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.324000e+01,
            1.373880e+01,
            1.424010e+01,
            1.474150e+01,
            1.524280e+01,
            1.574420e+01,
            1.625000e+01,
            1.675000e+01}, // SINR
           {9.211957e-01,
            7.559172e-01,
            4.742509e-01,
            2.037338e-01,
            4.760000e-02,
            6.000000e-03,
            4.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.324060e+01,
            1.361040e+01,
            1.398020e+01,
            1.434990e+01,
            1.471970e+01,
            1.509000e+01,
            1.546000e+01,
            1.583000e+01,
            1.620000e+01,
            1.657000e+01,
            1.694000e+01,
            1.731000e+01}, // SINR
           {9.894231e-01,
            9.311594e-01,
            8.077532e-01,
            6.243873e-01,
            3.871951e-01,
            1.934799e-01,
            6.670000e-02,
            1.250000e-02,
            2.100000e-03,
            3.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {336U, // SINR and BLER for CBS 336
       MmWaveEesmErrorModel::DoubleTuple{
           {1.324810e+01,
            1.361600e+01,
            1.398390e+01,
            1.435180e+01,
            1.471970e+01,
            1.509000e+01,
            1.546000e+01,
            1.582000e+01,
            1.619000e+01,
            1.656000e+01}, // SINR
           {9.494485e-01,
            8.344156e-01,
            6.602564e-01,
            4.372852e-01,
            2.216608e-01,
            7.740000e-02,
            1.880000e-02,
            3.800000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {352U, // SINR and BLER for CBS 352
       MmWaveEesmErrorModel::DoubleTuple{
           {1.270740e+01,
            1.346660e+01,
            1.422580e+01,
            1.498500e+01,
            1.574420e+01,
            1.650000e+01},                                                           // SINR
           {9.865385e-01, 8.547297e-01, 3.982650e-01, 5.200000e-02, 1.200000e-03, 0} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {1.342000e+01,
            1.371970e+01,
            1.402290e+01,
            1.432600e+01,
            1.462910e+01,
            1.493230e+01,
            1.524000e+01,
            1.554000e+01,
            1.584000e+01,
            1.614000e+01,
            1.645000e+01,
            1.675000e+01,
            1.705000e+01,
            1.736000e+01,
            1.766000e+01}, // SINR
           {9.485294e-01,
            8.641667e-01,
            7.205056e-01,
            5.219388e-01,
            3.232648e-01,
            1.557453e-01,
            5.620000e-02,
            1.390000e-02,
            2.500000e-03,
            5.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {1.289000e+01,
            1.336000e+01,
            1.383000e+01,
            1.430000e+01,
            1.477500e+01,
            1.525000e+01,
            1.572500e+01,
            1.620000e+01}, // SINR
           {9.809160e-01,
            8.914931e-01,
            6.655928e-01,
            3.138958e-01,
            8.557924e-02,
            7.500000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.310000e+01,
            1.345000e+01,
            1.380000e+01,
            1.415000e+01,
            1.450000e+01,
            1.485000e+01,
            1.520000e+01,
            1.555000e+01,
            1.590000e+01}, // SINR
           {9.732824e-01,
            8.965517e-01,
            7.399425e-01,
            4.833650e-01,
            2.437259e-01,
            7.790000e-02,
            1.700000e-02,
            1.900000e-03,
            1.000000e-04} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.327000e+01,
            1.371000e+01,
            1.415000e+01,
            1.458750e+01,
            1.502500e+01,
            1.546250e+01,
            1.590000e+01}, // SINR
           {9.221014e-01,
            6.756579e-01,
            3.152985e-01,
            7.760000e-02,
            9.400000e-03,
            7.000000e-04,
            1.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {1.320000e+01,
            1.365000e+01,
            1.410000e+01,
            1.455000e+01,
            15,
            1.545000e+01,
            1.590000e+01}, // SINR
           {9.725379e-01,
            8.330592e-01,
            4.776119e-01,
            1.315651e-01,
            1.290000e-02,
            9.000000e-04,
            1.000000e-04} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.326000e+01,
            1.378000e+01,
            1.430000e+01,
            1.482500e+01,
            1.535000e+01,
            1.587500e+01},                                                           // SINR
           {9.790076e-01, 7.633136e-01, 3.261568e-01, 3.450000e-02, 6.000000e-04, 0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.355000e+01, 1.430000e+01, 1.505000e+01, 1.580000e+01}, // SINR
           {9.102113e-01, 2.771978e-01, 4.100000e-03, 0}             // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.353000e+01, 14, 1.447500e+01, 1.495000e+01, 1.542500e+01, 1.590000e+01}, // SINR
           {9.014085e-01, 5.351891e-01, 1.122654e-01, 5.600000e-03, 1.000000e-04, 0}   // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {1.350000e+01,
            1.390000e+01,
            1.430000e+01,
            1.470000e+01,
            1.510000e+01,
            1.550000e+01},                                                           // SINR
           {9.064685e-01, 5.641593e-01, 1.692568e-01, 1.890000e-02, 5.000000e-04, 0} // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {1.310000e+01,
            1.355000e+01,
            14,
            1.445000e+01,
            1.490000e+01,
            1.535000e+01,
            1.580000e+01}, // SINR
           {9.942308e-01,
            8.809932e-01,
            4.433798e-01,
            7.300000e-02,
            3.000000e-03,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {1.334000e+01,
            1.377000e+01,
            1.420000e+01,
            1.462500e+01,
            1.505000e+01,
            1.547500e+01},                                                           // SINR
           {9.555556e-01, 6.406250e-01, 1.748605e-01, 1.100000e-02, 1.000000e-04, 0} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {13, 1.360000e+01, 1.420000e+01, 1.480000e+01, 1.540000e+01, 16},         // SINR
           {9.980769e-01, 8.031250e-01, 1.347908e-01, 1.300000e-03, 1.000000e-04, 0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {1.343000e+01,
            1.375000e+01,
            1.408000e+01,
            1.440000e+01,
            1.472500e+01,
            1.505000e+01},                                                           // SINR
           {9.225352e-01, 6.317402e-01, 2.009215e-01, 2.650000e-02, 8.000000e-04, 0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.338000e+01, 1.386000e+01, 1.434000e+01, 1.482500e+01, 1.531000e+01}, // SINR
           {9.592593e-01, 5.360169e-01, 5.000000e-02, 7.000000e-04, 0}             // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.340000e+01,
            1.370000e+01,
            14,
            1.430000e+01,
            1.460000e+01,
            1.490000e+01,
            1.520000e+01}, // SINR
           {9.505597e-01,
            6.756579e-01,
            2.500000e-01,
            3.400000e-02,
            1.700000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.313830e+01, 1.365000e+01, 1.416000e+01, 1.466810e+01, 1.619790e+01}, // SINR
           {9.971154e-01, 7.878788e-01, 1.218416e-01, 9.000000e-04, 0}             // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {1.305000e+01, 1.360000e+01, 1.415000e+01, 1.470000e+01, 1.525000e+01}, // SINR
           {9.990385e-01, 8.309295e-01, 1.131436e-01, 5.000000e-04, 0}             // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {1.305000e+01, 1.360000e+01, 1.415000e+01, 1.470000e+01}, // SINR
           {9.932692e-01, 6.483586e-01, 2.830000e-02, 0}             // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {1.295000e+01, 1.350000e+01, 1.405000e+01, 1.460000e+01, 1.515000e+01}, // SINR
           {9.990385e-01, 8.160377e-01, 7.460000e-02, 1.000000e-04, 0}             // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {1.281000e+01, 1.348000e+01, 1.381000e+01, 1.415000e+01, 1.481250e+01}, // SINR
           {1, 8.417208e-01, 3.056901e-01, 1.990000e-02, 0}                        // BLER
       }},
      {2664U, // SINR and BLER for CBS 2664
       MmWaveEesmErrorModel::DoubleTuple{
           {1.295000e+01, 1.362000e+01, 1.395000e+01, 1.429000e+01, 1.495330e+01}, // SINR
           {1, 8.958333e-01, 4.015873e-01, 3.240000e-02, 0}                        // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.315000e+01,
            1.373000e+01,
            1.402000e+01,
            1.431000e+01,
            1.489070e+01,
            1.576580e+01,
            1.664080e+01},                                                              // SINR
           {1, 8.085443e-01, 3.446866e-01, 4.370000e-02, 1.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.289000e+01, 1.356000e+01, 1.389000e+01, 1.422000e+01, 1.489070e+01}, // SINR
           {1, 9.884615e-01, 7.507310e-01, 1.939522e-01, 0}                        // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {1.330000e+01, 1.385000e+01, 1.440000e+01, 1.495000e+01}, // SINR
           {1, 6.036730e-01, 6.600000e-03, 0}                        // BLER
       }}},
     {      // MCS 21
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {1.461340e+01,
            1.528360e+01,
            1.595390e+01,
            1.662410e+01,
            1.729440e+01,
            1.796000e+01,
            1.863000e+01,
            1.931000e+01,
            1.998000e+01,
            2.065000e+01,
            2.132000e+01,
            2.199000e+01,
            2.266000e+01,
            2.333000e+01}, // SINR
           {9.668561e-01,
            9.166667e-01,
            8.156646e-01,
            6.458333e-01,
            4.688645e-01,
            2.839888e-01,
            1.388274e-01,
            5.480000e-02,
            1.850000e-02,
            4.700000e-03,
            7.000000e-04,
            4.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {1.380000e+01,
            1.422500e+01,
            1.465000e+01,
            1.507500e+01,
            1.550000e+01,
            1.593000e+01,
            1.635000e+01,
            1.678000e+01,
            1.720000e+01,
            1.763000e+01,
            1.805000e+01,
            1.847000e+01,
            1.890000e+01,
            1.933000e+01,
            1.975000e+01}, // SINR
           {9.577206e-01,
            9.099650e-01,
            8.482143e-01,
            7.463663e-01,
            6.135817e-01,
            4.414063e-01,
            2.924365e-01,
            1.770099e-01,
            1.020937e-01,
            5.080000e-02,
            2.070000e-02,
            7.000000e-03,
            2.700000e-03,
            6.000000e-04,
            1.000000e-04} // BLER
       }},
      {104U, // SINR and BLER for CBS 104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.440000e+01,
            1.485000e+01,
            1.530000e+01,
            1.575000e+01,
            1.620000e+01,
            1.665000e+01,
            1.710000e+01,
            1.755000e+01,
            18,
            1.845000e+01,
            1.890000e+01,
            1.935000e+01,
            1.980000e+01}, // SINR
           {9.137324e-01,
            8.298387e-01,
            7.042350e-01,
            5.475427e-01,
            3.746302e-01,
            2.122483e-01,
            1.126902e-01,
            5.030000e-02,
            1.920000e-02,
            5.400000e-03,
            1.400000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {128U, // SINR and BLER for CBS 128
       MmWaveEesmErrorModel::DoubleTuple{
           {1.455000e+01, 1.480000e+01, 1.505000e+01, 1.530000e+01, 1.555000e+01, 1.580000e+01,
            1.605000e+01, 1.630000e+01, 1.655000e+01, 1.680000e+01, 1.705000e+01, 1.730000e+01,
            1.755000e+01, 1.780000e+01, 1.805000e+01, 1.830000e+01, 1.855000e+01, 1.880000e+01,
            1.905000e+01, 1.930000e+01, 1.955000e+01}, // SINR
           {9.122340e-01, 8.716216e-01, 7.996894e-01,
            7.315341e-01, 6.293532e-01, 5.126008e-01,
            3.995253e-01, 3.008929e-01, 2.160653e-01,
            1.488731e-01, 9.652549e-02, 5.980000e-02,
            3.550000e-02, 1.870000e-02, 9.900000e-03,
            4.300000e-03, 1.900000e-03, 9.000000e-04,
            4.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {144U, // SINR and BLER for CBS 144
       MmWaveEesmErrorModel::DoubleTuple{
           {1.384000e+01,
            1.418000e+01,
            1.452000e+01,
            1.485420e+01,
            1.519010e+01,
            1.552600e+01,
            1.586200e+01,
            1.619790e+01,
            1.653000e+01,
            1.687000e+01,
            1.721000e+01,
            1.754000e+01,
            1.788000e+01,
            1.821000e+01,
            1.855000e+01}, // SINR
           {9.439338e-01,
            8.931034e-01,
            8.229167e-01,
            6.983696e-01,
            5.683333e-01,
            4.215604e-01,
            2.690043e-01,
            1.476608e-01,
            7.620000e-02,
            3.680000e-02,
            1.630000e-02,
            5.600000e-03,
            1.800000e-03,
            7.000000e-04,
            0} // BLER
       }},
      {192U, // SINR and BLER for CBS 192
       MmWaveEesmErrorModel::DoubleTuple{
           {1.439000e+01,
            1.475420e+01,
            1.511510e+01,
            1.547600e+01,
            1.583700e+01,
            1.619790e+01,
            1.656000e+01,
            1.692000e+01,
            1.728000e+01,
            1.764000e+01,
            18,
            1.836000e+01}, // SINR
           {9.020979e-01,
            8.176752e-01,
            6.688482e-01,
            4.846743e-01,
            2.825724e-01,
            1.400838e-01,
            6.000000e-02,
            2.220000e-02,
            6.900000e-03,
            2.200000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {1.440000e+01,
            1.485000e+01,
            1.530000e+01,
            1.575000e+01,
            1.620000e+01,
            1.665000e+01,
            1.710000e+01,
            1.755000e+01,
            18,
            1.845000e+01,
            1.890000e+01}, // SINR
           {9.725379e-01,
            9.157801e-01,
            7.852761e-01,
            5.688889e-01,
            3.052536e-01,
            1.207729e-01,
            3.860000e-02,
            8.200000e-03,
            1.400000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {1.428000e+01,
            1.466220e+01,
            1.504610e+01,
            1.543000e+01,
            1.581400e+01,
            1.619790e+01,
            1.658000e+01,
            1.697000e+01,
            1.735000e+01,
            1.773000e+01,
            1.812000e+01,
            1.850000e+01}, // SINR
           {9.636194e-01,
            8.640203e-01,
            7.301136e-01,
            5.276042e-01,
            3.228900e-01,
            1.397550e-01,
            5.270000e-02,
            1.450000e-02,
            4.000000e-03,
            1.000000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {256U, // SINR and BLER for CBS 256
       MmWaveEesmErrorModel::DoubleTuple{
           {14,
            1.430000e+01,
            1.460000e+01,
            1.490000e+01,
            1.520000e+01,
            1.550000e+01,
            1.580000e+01,
            1.610000e+01,
            1.640000e+01,
            1.670000e+01,
            17,
            1.730000e+01,
            1.760000e+01,
            1.790000e+01}, // SINR
           {9.531250e-01,
            8.948276e-01,
            8.173077e-01,
            6.765873e-01,
            4.980315e-01,
            3.223350e-01,
            1.726680e-01,
            7.770000e-02,
            2.810000e-02,
            8.600000e-03,
            2.000000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.417000e+01,
            1.457290e+01,
            1.497920e+01,
            1.538540e+01,
            1.579170e+01,
            1.619790e+01,
            1.660000e+01,
            1.701000e+01,
            1.742000e+01,
            1.782000e+01}, // SINR
           {9.624060e-01,
            8.682886e-01,
            6.743421e-01,
            4.208333e-01,
            1.941244e-01,
            6.020000e-02,
            1.460000e-02,
            2.400000e-03,
            2.000000e-04,
            0} // BLER
       }},
      {320U, // SINR and BLER for CBS 320
       MmWaveEesmErrorModel::DoubleTuple{
           {1.383380e+01, 1.472040e+01, 1.560690e+01, 1.649350e+01, 1.738010e+01}, // SINR
           {9.710821e-01, 7.008197e-01, 1.746170e-01, 7.400000e-03, 3.000000e-04}  // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.435000e+01,
            1.460000e+01,
            1.485000e+01,
            1.510000e+01,
            1.535000e+01,
            1.560000e+01,
            1.585000e+01,
            1.610000e+01,
            1.635000e+01,
            1.660000e+01,
            1.685000e+01,
            1.710000e+01}, // SINR
           {9.166667e-01,
            8.269231e-01,
            7.090278e-01,
            5.528017e-01,
            3.607550e-01,
            2.019231e-01,
            9.501212e-02,
            3.980000e-02,
            1.400000e-02,
            3.900000e-03,
            1.600000e-03,
            4.000000e-04} // BLER
       }},
      {384U, // SINR and BLER for CBS 384
       MmWaveEesmErrorModel::DoubleTuple{
           {1.410000e+01,
            1.460000e+01,
            1.510000e+01,
            1.560000e+01,
            1.610000e+01,
            1.660000e+01,
            1.710000e+01}, // SINR
           {9.329710e-01,
            7.315341e-01,
            4.075563e-01,
            1.238938e-01,
            1.570000e-02,
            1.200000e-03,
            1.000000e-04} // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {1.431000e+01,
            1.510000e+01,
            1.588750e+01,
            1.667500e+01,
            1.746250e+01,
            1.825000e+01},                                                           // SINR
           {9.175532e-01, 4.639599e-01, 4.940000e-02, 1.300000e-03, 2.000000e-04, 0} // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.419000e+01,
            1.456000e+01,
            1.493000e+01,
            1.530000e+01,
            1.567500e+01,
            1.605000e+01,
            1.642500e+01,
            1.680000e+01}, // SINR
           {9.555556e-01,
            8.617550e-01,
            6.160287e-01,
            3.342105e-01,
            1.173994e-01,
            2.590000e-02,
            3.700000e-03,
            9.000000e-04} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.430000e+01,
            1.480000e+01,
            1.530000e+01,
            1.580000e+01,
            1.630000e+01,
            1.680000e+01,
            1.730000e+01}, // SINR
           {9.671053e-01,
            8.184713e-01,
            4.161184e-01,
            8.757062e-02,
            7.300000e-03,
            6.000000e-04,
            1.000000e-04} // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {1.419000e+01,
            1.456000e+01,
            1.493000e+01,
            1.530000e+01,
            1.567500e+01,
            1.605000e+01,
            1.642500e+01,
            1.680000e+01}, // SINR
           {9.809160e-01,
            8.977273e-01,
            6.588010e-01,
            3.223350e-01,
            9.032847e-02,
            1.110000e-02,
            9.000000e-04,
            1.000000e-04} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.430000e+01,
            1.455000e+01,
            1.480000e+01,
            1.505000e+01,
            1.530000e+01,
            1.555000e+01,
            1.580000e+01,
            1.605000e+01,
            1.630000e+01}, // SINR
           {9.531250e-01,
            8.817568e-01,
            7.294034e-01,
            5.039841e-01,
            2.745680e-01,
            1.028982e-01,
            2.770000e-02,
            5.300000e-03,
            1.000000e-03} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.420000e+01,
            1.460000e+01,
            15,
            1.540000e+01,
            1.580000e+01,
            1.620000e+01,
            1.660000e+01}, // SINR
           {9.671053e-01,
            8.125000e-01,
            4.586299e-01,
            1.167672e-01,
            1.030000e-02,
            2.000000e-04,
            0} // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.412000e+01,
            1.444000e+01,
            1.476000e+01,
            1.508000e+01,
            1.540000e+01,
            1.572500e+01,
            1.605000e+01,
            1.637500e+01}, // SINR
           {9.624060e-01,
            8.308824e-01,
            5.644273e-01,
            2.409178e-01,
            5.370000e-02,
            4.500000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {1.440000e+01, 1.490000e+01, 1.540000e+01, 1.590000e+01, 1.640000e+01}, // SINR
           {9.442446e-01, 5.767045e-01, 1.067550e-01, 3.800000e-03, 0}             // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {1.388000e+01, 1.474380e+01, 1.560770e+01, 1.647170e+01}, // SINR
           {9.990385e-01, 6.559278e-01, 1.290000e-02, 0}             // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {1.430000e+01,
            1.455000e+01,
            1.480000e+01,
            1.505000e+01,
            1.530000e+01,
            1.555000e+01,
            1.580000e+01,
            1.605000e+01,
            1.630000e+01}, // SINR
           {9.680451e-01,
            8.809524e-01,
            6.818783e-01,
            3.731618e-01,
            1.366848e-01,
            2.560000e-02,
            2.700000e-03,
            3.000000e-04,
            1.000000e-04} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {1.424000e+01,
            1.457000e+01,
            1.490000e+01,
            1.523130e+01,
            1.556250e+01,
            1.589380e+01,
            1.622500e+01}, // SINR
           {9.583333e-01,
            7.827744e-01,
            4.042722e-01,
            8.270000e-02,
            6.300000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {1.403000e+01, 1.471480e+01, 1.540400e+01, 1.609320e+01}, // SINR
           {9.980769e-01, 6.601563e-01, 2.640000e-02, 0}             // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.424000e+01, 1.469540e+01, 1.515060e+01, 1.560580e+01, 1.606100e+01}, // SINR
           {9.713740e-01, 6.623711e-01, 1.107679e-01, 1.800000e-03, 0}             // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.389000e+01, 1.461000e+01, 1.532510e+01, 1.604400e+01}, // SINR
           {1, 7.413295e-01, 1.820000e-02, 0}                        // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.405000e+01, 1.447000e+01, 1.488900e+01, 1.531240e+01, 1.573590e+01}, // SINR
           {9.932692e-01, 8.480392e-01, 2.849099e-01, 1.180000e-02, 0}             // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {1.410000e+01, 1.451000e+01, 1.491990e+01, 1.532790e+01, 1.573590e+01}, // SINR
           {9.980769e-01, 8.887931e-01, 3.202141e-01, 1.360000e-02, 0}             // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {1.425000e+01, 1.463000e+01, 1.501200e+01, 1.539840e+01, 1.578480e+01}, // SINR
           {9.522059e-01, 5.222107e-01, 5.930000e-02, 7.000000e-04, 0}             // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {1.417000e+01,
            1.456000e+01,
            1.495090e+01,
            1.534340e+01,
            1.573590e+01,
            1.612840e+01,
            1.652090e+01}, // SINR
           {9.753788e-01,
            6.343284e-01,
            9.503284e-02,
            1.300000e-03,
            1.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {1.368000e+01,
            1.397000e+01,
            1.427000e+01,
            1.456000e+01,
            1.486000e+01,
            1.515620e+01,
            1.545200e+01,
            1.574780e+01,
            1.604370e+01,
            1.633950e+01}, // SINR
           {1,
            9.971154e-01,
            9.330357e-01,
            5.865826e-01,
            1.256225e-01,
            6.200000e-03,
            2.000000e-04,
            1.000000e-04,
            1.000000e-04,
            1.000000e-04} // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {1.441000e+01, 1.481270e+01, 1.521900e+01, 1.562530e+01}, // SINR
           {9.104610e-01, 2.701180e-01, 5.400000e-03, 0}             // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.440000e+01,
            1.468000e+01,
            1.496000e+01,
            1.523870e+01,
            1.551850e+01,
            1.579830e+01,
            1.607810e+01}, // SINR
           {9.734848e-01,
            7.536550e-01,
            2.799335e-01,
            3.020000e-02,
            9.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.445000e+01, 1.485540e+01, 1.525740e+01, 1.565950e+01, 1.606160e+01}, // SINR
           {9.640152e-01, 4.985294e-01, 2.130000e-02, 2.000000e-04, 0}             // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {1.356000e+01, 1.456000e+01, 1.489000e+01, 1.523000e+01, 1.556470e+01}, // SINR
           {1, 9.049296e-01, 3.645533e-01, 1.680000e-02, 0}                        // BLER
       }}},
     {      // MCS 22
      {64U, // SINR and BLER for CBS 64
       MmWaveEesmErrorModel::DoubleTuple{
           {1.530000e+01, 1.557500e+01, 1.585000e+01, 1.612500e+01, 1.640000e+01,
            1.667000e+01, 1.695000e+01, 1.722000e+01, 1.750000e+01, 1.777000e+01,
            1.805000e+01, 1.832000e+01, 1.860000e+01, 1.887000e+01, 1.915000e+01,
            1.942000e+01, 1.970000e+01, 1.997000e+01, 2.025000e+01, 2.053000e+01,
            2.080000e+01, 2.107000e+01, 2.135000e+01, 2.162000e+01, 2.190000e+01}, // SINR
           {9.128521e-01, 8.887931e-01, 8.425325e-01, 7.734848e-01, 6.948925e-01,
            6.375000e-01, 5.672222e-01, 4.922179e-01, 4.069489e-01, 3.360818e-01,
            2.600515e-01, 1.997218e-01, 1.455202e-01, 1.049145e-01, 7.110000e-02,
            4.540000e-02, 2.860000e-02, 1.790000e-02, 1.170000e-02, 5.400000e-03,
            3.400000e-03, 1.300000e-03, 7.000000e-04, 6.000000e-04, 5.000000e-04} // BLER
       }},
      {88U, // SINR and BLER for CBS 88
       MmWaveEesmErrorModel::DoubleTuple{
           {1.515000e+01, 1.536000e+01, 1.556730e+01, 1.577410e+01, 1.598090e+01, 1.618770e+01,
            1.639450e+01, 1.660000e+01, 1.681000e+01, 1.701000e+01, 1.722000e+01, 1.743000e+01,
            1.764000e+01, 1.784000e+01, 1.805000e+01, 1.826000e+01, 1.847000e+01, 1.867000e+01,
            1.888000e+01, 1.909000e+01, 1.930000e+01, 1.950000e+01, 1.971000e+01, 1.992000e+01,
            2.012000e+01, 2.033000e+01, 2.053000e+01, 2.074000e+01, 2.095000e+01, 2.116000e+01,
            2.136000e+01}, // SINR
           {9.266304e-01, 8.939655e-01, 8.496732e-01, 8.176752e-01, 7.703313e-01, 7.245763e-01,
            6.570513e-01, 5.938940e-01, 5.325630e-01, 4.589416e-01, 3.896154e-01, 3.306136e-01,
            2.738612e-01, 2.234043e-01, 1.757650e-01, 1.333866e-01, 9.803512e-02, 7.140000e-02,
            4.930000e-02, 3.360000e-02, 2.460000e-02, 1.560000e-02, 9.500000e-03, 5.500000e-03,
            3.600000e-03, 2.500000e-03, 1.300000e-03, 5.000000e-04, 4.000000e-04, 1.000000e-04,
            1.000000e-04} // BLER
       }},
      {112U, // SINR and BLER for CBS 112
       MmWaveEesmErrorModel::DoubleTuple{
           {1.530000e+01, 1.557500e+01, 1.585000e+01, 1.612500e+01, 1.640000e+01,
            1.667000e+01, 1.695000e+01, 1.722000e+01, 1.750000e+01, 1.777000e+01,
            1.805000e+01, 1.832000e+01, 1.860000e+01, 1.887000e+01, 1.915000e+01,
            1.942000e+01, 1.970000e+01, 1.997000e+01, 2.025000e+01, 2.053000e+01,
            2.080000e+01, 2.107000e+01, 2.135000e+01, 2.162000e+01}, // SINR
           {9.029720e-01, 8.582215e-01, 7.852761e-01, 6.971154e-01, 6.190191e-01,
            5.110442e-01, 4.063505e-01, 3.210660e-01, 2.418426e-01, 1.735537e-01,
            1.134928e-01, 7.270000e-02, 4.330000e-02, 2.410000e-02, 1.430000e-02,
            6.600000e-03, 3.400000e-03, 2.500000e-03, 1.400000e-03, 8.000000e-04,
            7.000000e-04, 5.000000e-04, 3.000000e-04, 2.000000e-04} // BLER
       }},
      {160U, // SINR and BLER for CBS 160
       MmWaveEesmErrorModel::DoubleTuple{
           {15,
            1.545000e+01,
            1.590000e+01,
            1.635000e+01,
            1.680000e+01,
            1.725000e+01,
            1.770000e+01,
            1.815000e+01,
            1.860000e+01,
            1.905000e+01,
            1.950000e+01,
            1.995000e+01,
            2.040000e+01}, // SINR
           {9.558824e-01,
            8.818027e-01,
            7.169944e-01,
            5.236626e-01,
            3.306136e-01,
            1.892750e-01,
            9.210526e-02,
            3.290000e-02,
            1.220000e-02,
            2.700000e-03,
            9.000000e-04,
            3.000000e-04,
            0} // BLER
       }},
      {184U, // SINR and BLER for CBS 184
       MmWaveEesmErrorModel::DoubleTuple{
           {1.514000e+01,
            1.540000e+01,
            1.566250e+01,
            1.592500e+01,
            1.618750e+01,
            1.645000e+01,
            1.671000e+01,
            1.697000e+01,
            1.724000e+01,
            1.750000e+01,
            1.776000e+01,
            1.803000e+01,
            1.829000e+01,
            1.855000e+01,
            1.881000e+01,
            1.907000e+01,
            1.933000e+01}, // SINR
           {9.370504e-01,
            8.922414e-01,
            8.181090e-01,
            7.136872e-01,
            5.985915e-01,
            4.724813e-01,
            3.586182e-01,
            2.420520e-01,
            1.486967e-01,
            9.377534e-02,
            5.050000e-02,
            2.520000e-02,
            1.120000e-02,
            4.700000e-03,
            1.800000e-03,
            4.000000e-04,
            2.000000e-04} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {1.470000e+01,
            1.532500e+01,
            1.595000e+01,
            1.657500e+01,
            1.720000e+01,
            1.783000e+01,
            1.845000e+01,
            1.908000e+01,
            1.970000e+01}, // SINR
           {9.807692e-01,
            9.047203e-01,
            7.012363e-01,
            3.757440e-01,
            1.299020e-01,
            2.700000e-02,
            2.600000e-03,
            1.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {1.510000e+01,
            1.542500e+01,
            1.575000e+01,
            1.607500e+01,
            1.640000e+01,
            1.672000e+01,
            1.705000e+01,
            1.737000e+01,
            1.770000e+01,
            1.803000e+01,
            1.835000e+01,
            1.867000e+01,
            19,
            1.932000e+01,
            1.965000e+01}, // SINR
           {9.742366e-01,
            9.489051e-01,
            8.809932e-01,
            7.718373e-01,
            6.387500e-01,
            4.604545e-01,
            2.919540e-01,
            1.760885e-01,
            8.310000e-02,
            3.730000e-02,
            1.250000e-02,
            3.500000e-03,
            1.300000e-03,
            6.000000e-04,
            2.000000e-04} // BLER
       }},
      {256U, // SINR and BLER for CBS 256
       MmWaveEesmErrorModel::DoubleTuple{
           {1.483000e+01,
            1.580000e+01,
            1.677500e+01,
            1.775000e+01,
            1.872500e+01,
            1.970000e+01},                                                           // SINR
           {9.706439e-01, 7.285714e-01, 2.191871e-01, 1.600000e-02, 2.000000e-04, 0} // BLER
       }},
      {304U, // SINR and BLER for CBS 304
       MmWaveEesmErrorModel::DoubleTuple{
           {1.490000e+01,
            1.590000e+01,
            1.690000e+01,
            1.790000e+01,
            1.890000e+01,
            1.990000e+01},                                                           // SINR
           {9.807692e-01, 6.632124e-01, 1.379121e-01, 5.500000e-03, 1.000000e-04, 0} // BLER
       }},
      {320U, // SINR and BLER for CBS 320
       MmWaveEesmErrorModel::DoubleTuple{
           {1.463000e+01,
            1.560000e+01,
            1.657500e+01,
            1.755000e+01,
            1.852500e+01,
            1.950000e+01},                                                           // SINR
           {9.725379e-01, 6.541878e-01, 1.097855e-01, 4.100000e-03, 1.000000e-04, 0} // BLER
       }},
      {368U, // SINR and BLER for CBS 368
       MmWaveEesmErrorModel::DoubleTuple{
           {1.408000e+01, 1.520000e+01, 1.632500e+01, 1.745000e+01, 1.857500e+01}, // SINR
           {9.990385e-01, 8.775685e-01, 2.112795e-01, 3.300000e-03, 0}             // BLER
       }},
      {432U, // SINR and BLER for CBS 432
       MmWaveEesmErrorModel::DoubleTuple{
           {1.540000e+01, 1.645000e+01, 1.750000e+01, 1.855000e+01, 1.960000e+01}, // SINR
           {9.443431e-01, 3.989780e-01, 2.430000e-02, 6.000000e-04, 0}             // BLER
       }},
      {456U, // SINR and BLER for CBS 456
       MmWaveEesmErrorModel::DoubleTuple{
           {1.490000e+01,
            1.565000e+01,
            1.640000e+01,
            1.715000e+01,
            1.790000e+01,
            1.865000e+01},                                                           // SINR
           {9.923077e-01, 8.940972e-01, 4.190199e-01, 6.560000e-02, 3.100000e-03, 0} // BLER
       }},
      {552U, // SINR and BLER for CBS 552
       MmWaveEesmErrorModel::DoubleTuple{
           {1.540000e+01, 1.620000e+01, 17, 1.780000e+01, 1.860000e+01}, // SINR
           {9.583333e-01, 5.452128e-01, 6.880000e-02, 1.500000e-03, 0}   // BLER
       }},
      {704U, // SINR and BLER for CBS 704
       MmWaveEesmErrorModel::DoubleTuple{
           {1.464000e+01,
            1.542000e+01,
            1.620000e+01,
            1.697500e+01,
            1.775000e+01,
            1.852500e+01},                                                           // SINR
           {9.971154e-01, 8.216561e-01, 1.617458e-01, 3.500000e-03, 1.000000e-04, 0} // BLER
       }},
      {768U, // SINR and BLER for CBS 768
       MmWaveEesmErrorModel::DoubleTuple{
           {1.456000e+01,
            1.545590e+01,
            1.635660e+01,
            1.725730e+01,
            1.815800e+01,
            1.905870e+01},                                                           // SINR
           {9.971154e-01, 7.166193e-01, 4.380000e-02, 4.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {848U, // SINR and BLER for CBS 848
       MmWaveEesmErrorModel::DoubleTuple{
           {1.486000e+01, 1.567690e+01, 1.649140e+01, 1.730590e+01, 1.812040e+01}, // SINR
           {9.923077e-01, 6.323892e-01, 3.000000e-02, 6.000000e-04, 0}             // BLER
       }},
      {928U, // SINR and BLER for CBS 928
       MmWaveEesmErrorModel::DoubleTuple{
           {1.495000e+01, 1.570000e+01, 1.645000e+01, 1.720000e+01, 1.795000e+01}, // SINR
           {9.961538e-01, 7.626488e-01, 9.483454e-02, 1.000000e-03, 0}             // BLER
       }},
      {984U, // SINR and BLER for CBS 984
       MmWaveEesmErrorModel::DoubleTuple{
           {1.482000e+01,
            1.542000e+01,
            1.602390e+01,
            1.662790e+01,
            1.723180e+01,
            1.783570e+01},                                                           // SINR
           {9.913462e-01, 7.803030e-01, 1.697635e-01, 5.800000e-03, 2.000000e-04, 0} // BLER
       }},
      {1064U, // SINR and BLER for CBS 1064
       MmWaveEesmErrorModel::DoubleTuple{
           {1.515000e+01,
            1.575000e+01,
            1.635400e+01,
            1.695800e+01,
            1.756200e+01,
            1.816600e+01},                                                           // SINR
           {9.761450e-01, 5.461373e-01, 4.280000e-02, 8.000000e-04, 2.000000e-04, 0} // BLER
       }},
      {1160U, // SINR and BLER for CBS 1160
       MmWaveEesmErrorModel::DoubleTuple{
           {1.492000e+01,
            1.546000e+01,
            16,
            1.654150e+01,
            1.708300e+01,
            1.762450e+01,
            1.816600e+01}, // SINR
           {9.903846e-01,
            8.346774e-01,
            2.463379e-01,
            1.000000e-02,
            7.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1256U, // SINR and BLER for CBS 1256
       MmWaveEesmErrorModel::DoubleTuple{
           {1.501000e+01,
            1.554000e+01,
            1.606700e+01,
            1.659180e+01,
            1.711650e+01,
            1.764120e+01},                                                           // SINR
           {9.932692e-01, 7.965839e-01, 1.786984e-01, 6.200000e-03, 2.000000e-04, 0} // BLER
       }},
      {1416U, // SINR and BLER for CBS 1416
       MmWaveEesmErrorModel::DoubleTuple{
           {1.505000e+01,
            1.557000e+01,
            1.609220e+01,
            1.661060e+01,
            1.712910e+01,
            1.764750e+01,
            1.816600e+01}, // SINR
           {9.913462e-01,
            6.881720e-01,
            9.380000e-02,
            1.500000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {1544U, // SINR and BLER for CBS 1544
       MmWaveEesmErrorModel::DoubleTuple{
           {1.472000e+01, 1.544400e+01, 1.617010e+01, 1.689630e+01, 1.762240e+01}, // SINR
           {9.980769e-01, 7.244318e-01, 1.790000e-02, 2.000000e-04, 0}             // BLER
       }},
      {1736U, // SINR and BLER for CBS 1736
       MmWaveEesmErrorModel::DoubleTuple{
           {1.521000e+01, 1.570000e+01, 1.619300e+01, 1.668630e+01, 1.717950e+01}, // SINR
           {9.438406e-01, 4.073625e-01, 1.620000e-02, 1.000000e-04, 0}             // BLER
       }},
      {1864U, // SINR and BLER for CBS 1864
       MmWaveEesmErrorModel::DoubleTuple{
           {1.498000e+01, 1.551000e+01, 1.604200e+01, 1.657300e+01, 1.710400e+01}, // SINR
           {9.942308e-01, 7.427326e-01, 6.400000e-02, 3.000000e-04, 0}             // BLER
       }},
      {2024U, // SINR and BLER for CBS 2024
       MmWaveEesmErrorModel::DoubleTuple{
           {1.498000e+01,
            1.551000e+01,
            1.604200e+01,
            1.657300e+01,
            1.710400e+01,
            1.763500e+01},                                                           // SINR
           {9.961538e-01, 7.032967e-01, 4.950000e-02, 7.000000e-04, 1.000000e-04, 0} // BLER
       }},
      {2216U, // SINR and BLER for CBS 2216
       MmWaveEesmErrorModel::DoubleTuple{
           {1.511000e+01,
            1.555000e+01,
            1.598620e+01,
            1.642610e+01,
            1.686610e+01,
            1.730600e+01,
            1.774600e+01}, // SINR
           {9.680451e-01,
            4.641544e-01,
            2.470000e-02,
            5.000000e-04,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {2280U, // SINR and BLER for CBS 2280
       MmWaveEesmErrorModel::DoubleTuple{
           {1.463000e+01,
            1.505000e+01,
            1.547000e+01,
            1.589240e+01,
            1.631300e+01,
            1.673360e+01,
            1.715420e+01,
            1.757480e+01}, // SINR
           {9.990385e-01,
            9.778846e-01,
            5.481602e-01,
            4.180000e-02,
            6.000000e-04,
            3.000000e-04,
            3.000000e-04,
            1.000000e-04} // BLER
       }},
      {2536U, // SINR and BLER for CBS 2536
       MmWaveEesmErrorModel::DoubleTuple{
           {1.477000e+01,
            1.520000e+01,
            1.563000e+01,
            1.605760e+01,
            1.648420e+01,
            1.691080e+01},                                                // SINR
           {1, 8.984375e-01, 2.584356e-01, 3.600000e-03, 1.000000e-04, 0} // BLER
       }},
      {2856U, // SINR and BLER for CBS 2856
       MmWaveEesmErrorModel::DoubleTuple{
           {1.517000e+01, 1.556000e+01, 1.595000e+01, 1.633920e+01, 1.672750e+01}, // SINR
           {9.241071e-01, 3.282468e-01, 7.000000e-03, 2.000000e-04, 0}             // BLER
       }},
      {3104U, // SINR and BLER for CBS 3104
       MmWaveEesmErrorModel::DoubleTuple{
           {1.510000e+01,
            1.549000e+01,
            1.589240e+01,
            1.629020e+01,
            1.668800e+01,
            1.708580e+01,
            1.748360e+01}, // SINR
           {9.923077e-01,
            7.125000e-01,
            6.060000e-02,
            1.600000e-03,
            5.000000e-04,
            3.000000e-04,
            1.000000e-04} // BLER
       }},
      {3496U, // SINR and BLER for CBS 3496
       MmWaveEesmErrorModel::DoubleTuple{
           {1.512000e+01,
            1.543000e+01,
            1.574000e+01,
            1.605000e+01,
            1.635500e+01,
            1.666280e+01},                                                           // SINR
           {9.932692e-01, 8.853448e-01, 3.856061e-01, 3.370000e-02, 6.000000e-04, 0} // BLER
       }},
      {3752U, // SINR and BLER for CBS 3752
       MmWaveEesmErrorModel::DoubleTuple{
           {1.514000e+01,
            1.552000e+01,
            1.589000e+01,
            1.626710e+01,
            1.664210e+01,
            1.701710e+01,
            1.739210e+01},                                                              // SINR
           {1, 9.210993e-01, 3.129653e-01, 1.250000e-02, 5.000000e-04, 3.000000e-04, 0} // BLER
       }}},
     {      // MCS 23
      {72U, // SINR and BLER for CBS 72
       MmWaveEesmErrorModel::DoubleTuple{
           {1.660000e+01, 1.690000e+01, 1.720000e+01, 1.750390e+01, 1.780470e+01, 1.810550e+01,
            1.840620e+01, 1.870700e+01, 1.901000e+01, 1.931000e+01, 1.961000e+01, 1.991000e+01,
            2.021000e+01, 2.051000e+01, 2.081000e+01, 2.111000e+01, 2.141000e+01, 2.171000e+01,
            2.201000e+01, 2.231000e+01, 2.261000e+01, 2.291000e+01, 2.321000e+01, 2.352000e+01,
            2.382000e+01, 2.412000e+01}, // SINR
           {9.290780e-01, 8.951049e-01,
            8.518212e-01, 8.164557e-01,
            7.427746e-01, 6.472081e-01,
            5.700673e-01, 4.779135e-01,
            3.837121e-01, 3.049517e-01,
            2.357210e-01, 1.775388e-01,
            1.260050e-01, 8.363600e-02,
            5.400000e-02, 3.320000e-02,
            1.930000e-02, 1.050000e-02,
            5.700000e-03, 3.000000e-03,
            1.900000e-03, 1.000000e-03,
            6.000000e-04, 3.000000e-04,
            1.000000e-04, 0} // BLER
       }},
      {96U, // SINR and BLER for CBS 96
       MmWaveEesmErrorModel::DoubleTuple{
           {1.611000e+01, 1.640000e+01, 1.669000e+01, 1.698000e+01, 1.727000e+01, 1.755860e+01,
            1.785030e+01, 1.814200e+01, 1.843360e+01, 1.872530e+01, 1.902000e+01, 1.931000e+01,
            1.960000e+01, 1.989000e+01, 2.018000e+01, 2.048000e+01, 2.077000e+01, 2.106000e+01,
            2.135000e+01, 2.164000e+01, 2.193000e+01, 2.223000e+01, 2.252000e+01}, // SINR
           {9.370504e-01, 8.975694e-01, 8.470395e-01, 7.780303e-01, 7.067308e-01, 6.362500e-01,
            5.405983e-01, 4.494681e-01, 3.550978e-01, 2.530120e-01, 1.869436e-01, 1.293860e-01,
            8.811147e-02, 5.570000e-02, 3.230000e-02, 1.830000e-02, 1.000000e-02, 5.000000e-03,
            2.700000e-03, 1.500000e-03, 1.100000e-03, 6.000000e-04, 6.000000e-04} // BLER
       }},
      {208U, // SINR and BLER for CBS 208
       MmWaveEesmErrorModel::DoubleTuple{
           {1.659000e+01,
            17,
            1.740490e+01,
            1.781200e+01,
            1.821910e+01,
            1.862630e+01,
            1.903340e+01,
            1.944000e+01,
            1.985000e+01,
            2.025000e+01,
            2.066000e+01,
            2.107000e+01}, // SINR
           {9.352190e-01,
            8.518212e-01,
            7.233146e-01,
            5.519481e-01,
            3.709677e-01,
            2.036062e-01,
            8.910000e-02,
            3.250000e-02,
            8.900000e-03,
            2.700000e-03,
            6.000000e-04,
            0} // BLER
       }},
      {224U, // SINR and BLER for CBS 224
       MmWaveEesmErrorModel::DoubleTuple{
           {1.607000e+01,
            1.631000e+01,
            1.655000e+01,
            1.679000e+01,
            1.703000e+01,
            1.727000e+01,
            1.750000e+01,
            1.773890e+01,
            1.797440e+01,
            1.820980e+01,
            1.844530e+01,
            1.868070e+01,
            1.892000e+01,
            1.915000e+01,
            1.939000e+01,
            1.962000e+01,
            1.986000e+01,
            2.009000e+01,
            2.033000e+01}, // SINR
           {9.110915e-01,
            8.501656e-01,
            7.795455e-01,
            6.997283e-01,
            5.904378e-01,
            4.735130e-01,
            3.652738e-01,
            2.576531e-01,
            1.690094e-01,
            1.053541e-01,
            5.870000e-02,
            3.030000e-02,
            1.420000e-02,
            7.300000e-03,
            2.300000e-03,
            1.200000e-03,
            2.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.566000e+01,
            1.604000e+01,
            1.642000e+01,
            1.680000e+01,
            1.718000e+01,
            1.755860e+01,
            1.793690e+01,
            1.831520e+01,
            1.869350e+01,
            1.907180e+01,
            1.945000e+01}, // SINR
           {9.617537e-01,
            8.975694e-01,
            7.679641e-01,
            5.669643e-01,
            3.798653e-01,
            2.220018e-01,
            9.631148e-02,
            3.230000e-02,
            9.100000e-03,
            2.000000e-03,
            9.000000e-04} // BLER
       }}},
     {      // MCS 24
      {80U, // SINR and BLER for CBS 80
       MmWaveEesmErrorModel::DoubleTuple{
           {1.733010e+01,
            1.808790e+01,
            1.884580e+01,
            1.960370e+01,
            2.036150e+01,
            2.112000e+01,
            2.188000e+01,
            2.264000e+01,
            2.339000e+01,
            2.415000e+01,
            2.491000e+01,
            2.567000e+01,
            2.642000e+01}, // SINR
           {9.885496e-01,
            9.595865e-01,
            8.708333e-01,
            7.122905e-01,
            4.837165e-01,
            3.040865e-01,
            1.478210e-01,
            6.140000e-02,
            2.000000e-02,
            4.400000e-03,
            8.000000e-04,
            1.000000e-04,
            0} // BLER
       }},
      {184U, // SINR and BLER for CBS 184
       MmWaveEesmErrorModel::DoubleTuple{
           {17,
            1.752000e+01,
            1.804100e+01,
            1.856180e+01,
            1.908270e+01,
            1.960350e+01,
            2.012430e+01,
            2.065000e+01,
            2.117000e+01,
            2.169000e+01,
            2.221000e+01}, // SINR
           {9.117133e-01,
            8.165064e-01,
            6.274390e-01,
            4.003165e-01,
            1.948529e-01,
            7.850000e-02,
            2.630000e-02,
            5.600000e-03,
            1.500000e-03,
            3.000000e-04,
            0} // BLER
       }},
      {240U, // SINR and BLER for CBS 240
       MmWaveEesmErrorModel::DoubleTuple{
           {1.696000e+01,
            1.738000e+01,
            1.780140e+01,
            1.821930e+01,
            1.863730e+01,
            1.905530e+01,
            1.947320e+01,
            1.989000e+01,
            2.031000e+01,
            2.073000e+01,
            2.114000e+01,
            2.156000e+01,
            2.198000e+01}, // SINR
           {9.312500e-01,
            8.387097e-01,
            6.759259e-01,
            4.898649e-01,
            3.019093e-01,
            1.463912e-01,
            6.060000e-02,
            2.140000e-02,
            7.400000e-03,
            2.000000e-03,
            1.000000e-03,
            5.000000e-04,
            0} // BLER
       }},
      {272U, // SINR and BLER for CBS 272
       MmWaveEesmErrorModel::DoubleTuple{
           {1.735000e+01,
            1.777010e+01,
            1.819200e+01,
            1.861390e+01,
            1.903580e+01,
            1.945770e+01,
            1.988000e+01,
            2.030000e+01,
            2.072000e+01,
            2.115000e+01,
            2.157000e+01,
            2.199000e+01}, // SINR
           {9.025862e-01,
            7.908951e-01,
            6.171117e-01,
            3.977987e-01,
            2.098586e-01,
            8.730000e-02,
            2.660000e-02,
            8.100000e-03,
            2.700000e-03,
            4.000000e-04,
            1.000000e-04,
            0} // BLER
       }}},
     {// MCS 25
      {0U, MmWaveEesmErrorModel::DoubleTuple{{0.0}, {0.0}}}},
     {       // MCS 26
      {120U, // SINR and BLER for CBS 120
       MmWaveEesmErrorModel::DoubleTuple{
           {1.985000e+01,
            2.110000e+01,
            2.235000e+01,
            2.360000e+01,
            2.485000e+01,
            2.610000e+01,
            2.735000e+01,
            2.860000e+01,
            2.985000e+01}, // SINR
           {9.713740e-01,
            7.992187e-01,
            4.692096e-01,
            1.808357e-01,
            4.640000e-02,
            9.300000e-03,
            1.300000e-03,
            2.000000e-04,
            0} // BLER
       }}},
     {       // MCS 27
      {152U, // SINR and BLER for CBS 152
       MmWaveEesmErrorModel::DoubleTuple{
           {2.050000e+01,
            2.117500e+01,
            2.185000e+01,
            2.252500e+01,
            2.320000e+01,
            2.388000e+01,
            2.455000e+01,
            2.522000e+01,
            2.590000e+01,
            2.658000e+01,
            2.725000e+01,
            2.792000e+01,
            2.860000e+01,
            2.928000e+01,
            2.995000e+01}, // SINR
           {9.470803e-01,
            8.557047e-01,
            6.918919e-01,
            4.975586e-01,
            3.286554e-01,
            1.873140e-01,
            9.564777e-02,
            4.470000e-02,
            1.870000e-02,
            7.700000e-03,
            3.100000e-03,
            1.300000e-03,
            4.000000e-04,
            2.000000e-04,
            0} // BLER
       }},
      {184U, // SINR and BLER for CBS 184
       MmWaveEesmErrorModel::DoubleTuple{
           {2.002000e+01,
            2.039000e+01,
            2.076000e+01,
            2.113000e+01,
            2.149750e+01,
            2.186500e+01,
            2.223250e+01,
            2.260000e+01,
            2.297000e+01,
            2.334000e+01,
            2.370000e+01,
            2.407000e+01,
            2.444000e+01,
            2.481000e+01,
            2.517000e+01,
            2.554000e+01}, // SINR
           {9.228723e-01,
            8.649329e-01,
            7.780303e-01,
            6.629581e-01,
            5.535714e-01,
            4.236577e-01,
            3.050847e-01,
            2.133221e-01,
            1.311007e-01,
            8.080000e-02,
            4.600000e-02,
            2.480000e-02,
            1.160000e-02,
            4.600000e-03,
            1.500000e-03,
            4.000000e-04} // BLER
       }},
      {256U, // SINR and BLER for CBS 256
       MmWaveEesmErrorModel::DoubleTuple{
           {2.086000e+01,
            2.135000e+01,
            2.183750e+01,
            2.232500e+01,
            2.281250e+01,
            2.330000e+01,
            2.379000e+01,
            2.428000e+01,
            2.476000e+01,
            2.525000e+01,
            2.574000e+01,
            2.623000e+01,
            2.671000e+01,
            2.720000e+01,
            2.769000e+01,
            2.818000e+01,
            2.867000e+01}, // SINR
           {9.537037e-01,
            8.852740e-01,
            7.837423e-01,
            6.374378e-01,
            4.782197e-01,
            3.370000e-01,
            2.324723e-01,
            1.544027e-01,
            8.670000e-02,
            4.920000e-02,
            2.610000e-02,
            1.350000e-02,
            8.300000e-03,
            3.500000e-03,
            1.800000e-03,
            6.000000e-04,
            4.000000e-04} // BLER
       }}},
     {// MCS 28
      {0U, MmWaveEesmErrorModel::DoubleTuple{{0.0}, {0.0}}}}}};

/**
 * \brief Table of beta values for each standard MCS in Table1 in TS38.214
 */
static const std::vector<double> BetaTable1 = {
    1.6,   1.61,  1.63,  1.65,  1.67,  1.7,   1.73,  1.76,  1.79,  1.82,
    3.97,  4.27,  4.71,  5.16,  5.66,  6.16,  6.5,   9.95,  10.97, 12.92,
    14.96, 17.06, 19.33, 21.85, 24.51, 27.14, 29.94, 32.05, 34.28};

/**
 * \brief Table of ECR of the standard MCSs: 29 MCSs as per Table1 in TS38.214
 */
static const std::vector<double> McsEcrTable1 = {
    // QPSK (M=2)
    0.12,
    0.15,
    0.19,
    0.25,
    0.30,
    0.37,
    0.44,
    0.51,
    0.59,
    0.66, // ECRs of MCSs
    // 16QAM (M=4)
    0.33,
    0.37,
    0.42,
    0.48,
    0.54,
    0.60,
    0.64, // ECRs of MCSs
    // 64QAM (M=6)
    0.43,
    0.46,
    0.50,
    0.55,
    0.60,
    0.65,
    0.70,
    0.75,
    0.80,
    0.85,
    0.89,
    0.93 // ECRs of MCSs
};

/**
 * \brief Table of modulation order of the standard MCSs: 29 MCSs as per Table1
 * in TS38.214
 */
static const std::vector<uint8_t> McsMTable1 = {
    // QPSK (M=2)
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    // 16QAM (M=4)
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    // 64QAM (M=6)
    6,
    6,
    6,
    6,
    6,
    6,
    6,
    6,
    6,
    6,
    6,
    6};

MmWaveEesmT1::MmWaveEesmT1()
{
    m_betaTable = &BetaTable1;
    m_mcsEcrTable = &McsEcrTable1;
    m_simulatedBlerFromSINR = &BlerForSinr1;
    m_mcsMTable = &McsMTable1;
    m_spectralEfficiencyForMcs = &SpectralEfficiencyForMcs1;
    m_spectralEfficiencyForCqi = &SpectralEfficiencyForCqi1;
}

} // namespace mmwave
} // namespace ns3
