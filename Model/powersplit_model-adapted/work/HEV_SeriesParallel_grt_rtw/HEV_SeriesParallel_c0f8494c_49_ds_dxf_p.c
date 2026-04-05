/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxf_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_dxf_p(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[59] = { 0, 1, 2, 2, 4, 5, 6, 6, 6, 8, 8, 8, 8, 8,
    11, 11, 11, 11, 13, 17, 21, 23, 29, 31, 31, 33, 34, 36, 38, 38, 38, 38, 38,
    39, 39, 39, 39, 39, 40, 42, 42, 44, 44, 44, 45, 45, 45, 45, 46, 46, 46, 46,
    50, 52, 52, 52, 52, 54, 54 };

  static int32_T _cg_const_2[54] = { 26, 25, 6, 28, 28, 29, 36, 37, 15, 43, 48,
    26, 30, 5, 6, 26, 28, 26, 27, 39, 40, 25, 26, 32, 34, 36, 37, 39, 40, 39, 40,
    26, 30, 25, 30, 31, 29, 30, 29, 34, 32, 33, 36, 37, 43, 48, 44, 45, 49, 50,
    44, 45, 49, 50 };

  (void)t1;
  (void)LC;
  out->mDXF_P.mNumCol = 58ULL;
  out->mDXF_P.mNumRow = 58ULL;
  out->mDXF_P.mJc[0] = _cg_const_1[0];
  out->mDXF_P.mJc[1] = _cg_const_1[1];
  out->mDXF_P.mJc[2] = _cg_const_1[2];
  out->mDXF_P.mJc[3] = _cg_const_1[3];
  out->mDXF_P.mJc[4] = _cg_const_1[4];
  out->mDXF_P.mJc[5] = _cg_const_1[5];
  out->mDXF_P.mJc[6] = _cg_const_1[6];
  out->mDXF_P.mJc[7] = _cg_const_1[7];
  out->mDXF_P.mJc[8] = _cg_const_1[8];
  out->mDXF_P.mJc[9] = _cg_const_1[9];
  out->mDXF_P.mJc[10] = _cg_const_1[10];
  out->mDXF_P.mJc[11] = _cg_const_1[11];
  out->mDXF_P.mJc[12] = _cg_const_1[12];
  out->mDXF_P.mJc[13] = _cg_const_1[13];
  out->mDXF_P.mJc[14] = _cg_const_1[14];
  out->mDXF_P.mJc[15] = _cg_const_1[15];
  out->mDXF_P.mJc[16] = _cg_const_1[16];
  out->mDXF_P.mJc[17] = _cg_const_1[17];
  out->mDXF_P.mJc[18] = _cg_const_1[18];
  out->mDXF_P.mJc[19] = _cg_const_1[19];
  out->mDXF_P.mJc[20] = _cg_const_1[20];
  out->mDXF_P.mJc[21] = _cg_const_1[21];
  out->mDXF_P.mJc[22] = _cg_const_1[22];
  out->mDXF_P.mJc[23] = _cg_const_1[23];
  out->mDXF_P.mJc[24] = _cg_const_1[24];
  out->mDXF_P.mJc[25] = _cg_const_1[25];
  out->mDXF_P.mJc[26] = _cg_const_1[26];
  out->mDXF_P.mJc[27] = _cg_const_1[27];
  out->mDXF_P.mJc[28] = _cg_const_1[28];
  out->mDXF_P.mJc[29] = _cg_const_1[29];
  out->mDXF_P.mJc[30] = _cg_const_1[30];
  out->mDXF_P.mJc[31] = _cg_const_1[31];
  out->mDXF_P.mJc[32] = _cg_const_1[32];
  out->mDXF_P.mJc[33] = _cg_const_1[33];
  out->mDXF_P.mJc[34] = _cg_const_1[34];
  out->mDXF_P.mJc[35] = _cg_const_1[35];
  out->mDXF_P.mJc[36] = _cg_const_1[36];
  out->mDXF_P.mJc[37] = _cg_const_1[37];
  out->mDXF_P.mJc[38] = _cg_const_1[38];
  out->mDXF_P.mJc[39] = _cg_const_1[39];
  out->mDXF_P.mJc[40] = _cg_const_1[40];
  out->mDXF_P.mJc[41] = _cg_const_1[41];
  out->mDXF_P.mJc[42] = _cg_const_1[42];
  out->mDXF_P.mJc[43] = _cg_const_1[43];
  out->mDXF_P.mJc[44] = _cg_const_1[44];
  out->mDXF_P.mJc[45] = _cg_const_1[45];
  out->mDXF_P.mJc[46] = _cg_const_1[46];
  out->mDXF_P.mJc[47] = _cg_const_1[47];
  out->mDXF_P.mJc[48] = _cg_const_1[48];
  out->mDXF_P.mJc[49] = _cg_const_1[49];
  out->mDXF_P.mJc[50] = _cg_const_1[50];
  out->mDXF_P.mJc[51] = _cg_const_1[51];
  out->mDXF_P.mJc[52] = _cg_const_1[52];
  out->mDXF_P.mJc[53] = _cg_const_1[53];
  out->mDXF_P.mJc[54] = _cg_const_1[54];
  out->mDXF_P.mJc[55] = _cg_const_1[55];
  out->mDXF_P.mJc[56] = _cg_const_1[56];
  out->mDXF_P.mJc[57] = _cg_const_1[57];
  out->mDXF_P.mJc[58] = _cg_const_1[58];
  out->mDXF_P.mIr[0] = _cg_const_2[0];
  out->mDXF_P.mIr[1] = _cg_const_2[1];
  out->mDXF_P.mIr[2] = _cg_const_2[2];
  out->mDXF_P.mIr[3] = _cg_const_2[3];
  out->mDXF_P.mIr[4] = _cg_const_2[4];
  out->mDXF_P.mIr[5] = _cg_const_2[5];
  out->mDXF_P.mIr[6] = _cg_const_2[6];
  out->mDXF_P.mIr[7] = _cg_const_2[7];
  out->mDXF_P.mIr[8] = _cg_const_2[8];
  out->mDXF_P.mIr[9] = _cg_const_2[9];
  out->mDXF_P.mIr[10] = _cg_const_2[10];
  out->mDXF_P.mIr[11] = _cg_const_2[11];
  out->mDXF_P.mIr[12] = _cg_const_2[12];
  out->mDXF_P.mIr[13] = _cg_const_2[13];
  out->mDXF_P.mIr[14] = _cg_const_2[14];
  out->mDXF_P.mIr[15] = _cg_const_2[15];
  out->mDXF_P.mIr[16] = _cg_const_2[16];
  out->mDXF_P.mIr[17] = _cg_const_2[17];
  out->mDXF_P.mIr[18] = _cg_const_2[18];
  out->mDXF_P.mIr[19] = _cg_const_2[19];
  out->mDXF_P.mIr[20] = _cg_const_2[20];
  out->mDXF_P.mIr[21] = _cg_const_2[21];
  out->mDXF_P.mIr[22] = _cg_const_2[22];
  out->mDXF_P.mIr[23] = _cg_const_2[23];
  out->mDXF_P.mIr[24] = _cg_const_2[24];
  out->mDXF_P.mIr[25] = _cg_const_2[25];
  out->mDXF_P.mIr[26] = _cg_const_2[26];
  out->mDXF_P.mIr[27] = _cg_const_2[27];
  out->mDXF_P.mIr[28] = _cg_const_2[28];
  out->mDXF_P.mIr[29] = _cg_const_2[29];
  out->mDXF_P.mIr[30] = _cg_const_2[30];
  out->mDXF_P.mIr[31] = _cg_const_2[31];
  out->mDXF_P.mIr[32] = _cg_const_2[32];
  out->mDXF_P.mIr[33] = _cg_const_2[33];
  out->mDXF_P.mIr[34] = _cg_const_2[34];
  out->mDXF_P.mIr[35] = _cg_const_2[35];
  out->mDXF_P.mIr[36] = _cg_const_2[36];
  out->mDXF_P.mIr[37] = _cg_const_2[37];
  out->mDXF_P.mIr[38] = _cg_const_2[38];
  out->mDXF_P.mIr[39] = _cg_const_2[39];
  out->mDXF_P.mIr[40] = _cg_const_2[40];
  out->mDXF_P.mIr[41] = _cg_const_2[41];
  out->mDXF_P.mIr[42] = _cg_const_2[42];
  out->mDXF_P.mIr[43] = _cg_const_2[43];
  out->mDXF_P.mIr[44] = _cg_const_2[44];
  out->mDXF_P.mIr[45] = _cg_const_2[45];
  out->mDXF_P.mIr[46] = _cg_const_2[46];
  out->mDXF_P.mIr[47] = _cg_const_2[47];
  out->mDXF_P.mIr[48] = _cg_const_2[48];
  out->mDXF_P.mIr[49] = _cg_const_2[49];
  out->mDXF_P.mIr[50] = _cg_const_2[50];
  out->mDXF_P.mIr[51] = _cg_const_2[51];
  out->mDXF_P.mIr[52] = _cg_const_2[52];
  out->mDXF_P.mIr[53] = _cg_const_2[53];
  (void)LC;
  (void)out;
  return 0;
}
