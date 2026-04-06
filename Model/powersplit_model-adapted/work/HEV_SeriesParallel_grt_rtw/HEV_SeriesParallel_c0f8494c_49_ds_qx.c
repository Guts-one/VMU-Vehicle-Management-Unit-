/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_qx.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_qx(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static real_T _cg_const_1[99] = { 0.0453061224489796, -0.032361516034985431,
    -0.35306122448979593, -0.14285714285714288, -0.032361516034985431,
    0.023115368596418166, 0.25218658892128287, 0.10204081632653063,
    -0.35306122448979593, 0.25218658892128287, 4.5306122448979593,
    1.4285714285714286, 0.0024004003, -0.02003, -0.0065582, 0.040010000000000004,
    0.02, -0.06, -0.06, -0.02003, 3.0, 0.02, -1.0, -0.0065582, 0.02,
    0.097160819999999981, -0.04, -0.2279, 0.26789999999999997,
    0.26789999999999997, 0.040010000000000004, -1.0, -0.04, 3.0,
    -0.14285714285714288, 0.10204081632653063, 1.4285714285714286, 4.0,
    3.2300000000000005E-8, -0.00013000000000000002, 0.00011,
    0.00016153846153846155, 0.00016153846153846155, -0.00013000000000000002, 3.0,
    -1.0, -0.76923076923076916, -0.76923076923076916, 0.00011, -1.0, 3.0,
    0.76923076923076916, 0.76923076923076916, 0.00016153846153846155,
    -0.76923076923076916, 0.76923076923076916, 3.7751479289940826,
    2.7751479289940826, 0.00016153846153846155, -0.76923076923076916,
    0.76923076923076916, 2.7751479289940826, 6.7751479289940821, -0.5, -0.15,
    -0.5, -0.15, 0.02, -0.2279, 2.0, -1.0, -1.0, -0.06, 0.26789999999999997,
    -1.0, 4.0, 3.0, -0.06, 0.26789999999999997, -1.0, 3.0, 4.0, 2.0, -0.5, 2.0,
    0.3, -0.15, 0.3, 2.1799999999999997, -0.5, 2.0, 0.3, -0.15, 0.3,
    2.1799999999999997, 2.0, 1.0, 1.0, 2.0 };

  (void)t1;
  (void)LC;
  out->mQX.mX[0] = _cg_const_1[0];
  out->mQX.mX[1] = _cg_const_1[1];
  out->mQX.mX[2] = _cg_const_1[2];
  out->mQX.mX[3] = _cg_const_1[3];
  out->mQX.mX[4] = _cg_const_1[4];
  out->mQX.mX[5] = _cg_const_1[5];
  out->mQX.mX[6] = _cg_const_1[6];
  out->mQX.mX[7] = _cg_const_1[7];
  out->mQX.mX[8] = _cg_const_1[8];
  out->mQX.mX[9] = _cg_const_1[9];
  out->mQX.mX[10] = _cg_const_1[10];
  out->mQX.mX[11] = _cg_const_1[11];
  out->mQX.mX[12] = _cg_const_1[12];
  out->mQX.mX[13] = _cg_const_1[13];
  out->mQX.mX[14] = _cg_const_1[14];
  out->mQX.mX[15] = _cg_const_1[15];
  out->mQX.mX[16] = _cg_const_1[16];
  out->mQX.mX[17] = _cg_const_1[17];
  out->mQX.mX[18] = _cg_const_1[18];
  out->mQX.mX[19] = _cg_const_1[19];
  out->mQX.mX[20] = _cg_const_1[20];
  out->mQX.mX[21] = _cg_const_1[21];
  out->mQX.mX[22] = _cg_const_1[22];
  out->mQX.mX[23] = _cg_const_1[23];
  out->mQX.mX[24] = _cg_const_1[24];
  out->mQX.mX[25] = _cg_const_1[25];
  out->mQX.mX[26] = _cg_const_1[26];
  out->mQX.mX[27] = _cg_const_1[27];
  out->mQX.mX[28] = _cg_const_1[28];
  out->mQX.mX[29] = _cg_const_1[29];
  out->mQX.mX[30] = _cg_const_1[30];
  out->mQX.mX[31] = _cg_const_1[31];
  out->mQX.mX[32] = _cg_const_1[32];
  out->mQX.mX[33] = _cg_const_1[33];
  out->mQX.mX[34] = _cg_const_1[34];
  out->mQX.mX[35] = _cg_const_1[35];
  out->mQX.mX[36] = _cg_const_1[36];
  out->mQX.mX[37] = _cg_const_1[37];
  out->mQX.mX[38] = _cg_const_1[38];
  out->mQX.mX[39] = _cg_const_1[39];
  out->mQX.mX[40] = _cg_const_1[40];
  out->mQX.mX[41] = _cg_const_1[41];
  out->mQX.mX[42] = _cg_const_1[42];
  out->mQX.mX[43] = _cg_const_1[43];
  out->mQX.mX[44] = _cg_const_1[44];
  out->mQX.mX[45] = _cg_const_1[45];
  out->mQX.mX[46] = _cg_const_1[46];
  out->mQX.mX[47] = _cg_const_1[47];
  out->mQX.mX[48] = _cg_const_1[48];
  out->mQX.mX[49] = _cg_const_1[49];
  out->mQX.mX[50] = _cg_const_1[50];
  out->mQX.mX[51] = _cg_const_1[51];
  out->mQX.mX[52] = _cg_const_1[52];
  out->mQX.mX[53] = _cg_const_1[53];
  out->mQX.mX[54] = _cg_const_1[54];
  out->mQX.mX[55] = _cg_const_1[55];
  out->mQX.mX[56] = _cg_const_1[56];
  out->mQX.mX[57] = _cg_const_1[57];
  out->mQX.mX[58] = _cg_const_1[58];
  out->mQX.mX[59] = _cg_const_1[59];
  out->mQX.mX[60] = _cg_const_1[60];
  out->mQX.mX[61] = _cg_const_1[61];
  out->mQX.mX[62] = _cg_const_1[62];
  out->mQX.mX[63] = _cg_const_1[63];
  out->mQX.mX[64] = _cg_const_1[64];
  out->mQX.mX[65] = _cg_const_1[65];
  out->mQX.mX[66] = _cg_const_1[66];
  out->mQX.mX[67] = _cg_const_1[67];
  out->mQX.mX[68] = _cg_const_1[68];
  out->mQX.mX[69] = _cg_const_1[69];
  out->mQX.mX[70] = _cg_const_1[70];
  out->mQX.mX[71] = _cg_const_1[71];
  out->mQX.mX[72] = _cg_const_1[72];
  out->mQX.mX[73] = _cg_const_1[73];
  out->mQX.mX[74] = _cg_const_1[74];
  out->mQX.mX[75] = _cg_const_1[75];
  out->mQX.mX[76] = _cg_const_1[76];
  out->mQX.mX[77] = _cg_const_1[77];
  out->mQX.mX[78] = _cg_const_1[78];
  out->mQX.mX[79] = _cg_const_1[79];
  out->mQX.mX[80] = _cg_const_1[80];
  out->mQX.mX[81] = _cg_const_1[81];
  out->mQX.mX[82] = _cg_const_1[82];
  out->mQX.mX[83] = _cg_const_1[83];
  out->mQX.mX[84] = _cg_const_1[84];
  out->mQX.mX[85] = _cg_const_1[85];
  out->mQX.mX[86] = _cg_const_1[86];
  out->mQX.mX[87] = _cg_const_1[87];
  out->mQX.mX[88] = _cg_const_1[88];
  out->mQX.mX[89] = _cg_const_1[89];
  out->mQX.mX[90] = _cg_const_1[90];
  out->mQX.mX[91] = _cg_const_1[91];
  out->mQX.mX[92] = _cg_const_1[92];
  out->mQX.mX[93] = _cg_const_1[93];
  out->mQX.mX[94] = _cg_const_1[94];
  out->mQX.mX[95] = _cg_const_1[95];
  out->mQX.mX[96] = _cg_const_1[96];
  out->mQX.mX[97] = _cg_const_1[97];
  out->mQX.mX[98] = _cg_const_1[98];
  (void)LC;
  (void)out;
  return 0;
}
