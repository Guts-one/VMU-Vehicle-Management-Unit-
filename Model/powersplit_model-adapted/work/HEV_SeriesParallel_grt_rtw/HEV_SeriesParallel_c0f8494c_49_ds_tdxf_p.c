/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_tdxf_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_tdxf_p(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_2[154] = { 7, 26, 3, 25, 27, 5, 6, 28, 5, 28, 8, 29,
    31, 35, 36, 37, 38, 42, 15, 16, 43, 48, 47, 7, 26, 28, 30, 5, 6, 26, 28, 4,
    13, 17, 19, 26, 27, 38, 39, 40, 17, 25, 26, 10, 11, 17, 19, 32, 34, 35, 36,
    37, 38, 39, 40, 17, 39, 40, 17, 53, 26, 30, 25, 27, 9, 12, 14, 18, 30, 31,
    35, 41, 46, 18, 29, 30, 18, 36, 37, 18, 22, 18, 20, 21, 18, 52, 54, 56, 29,
    31, 19, 32, 19, 37, 19, 40, 19, 52, 53, 34, 32, 33, 2, 52, 53, 36, 37, 39,
    40, 20, 23, 20, 44, 42, 43, 46, 20, 55, 56, 21, 24, 21, 49, 46, 47, 48, 21,
    56, 57, 41, 22, 54, 44, 45, 49, 50, 51, 43, 44, 45, 0, 23, 55, 45, 50, 15,
    45, 51, 48, 49, 50, 1, 24, 57 };

  static int32_T _cg_const_1[59] = { 0, 2, 5, 5, 8, 10, 13, 13, 13, 17, 17, 17,
    17, 18, 22, 23, 23, 23, 27, 31, 40, 43, 55, 58, 60, 62, 64, 73, 76, 79, 81,
    84, 88, 90, 92, 94, 96, 99, 100, 102, 105, 109, 111, 113, 116, 119, 121, 123,
    126, 129, 130, 132, 137, 140, 143, 145, 148, 151, 154 };

  int32_T i1;
  (void)t1;
  (void)LC;
  out->mTDXF_P.mNumCol = 58ULL;
  out->mTDXF_P.mNumRow = 58ULL;
  out->mTDXF_P.mJc[0] = _cg_const_1[0];
  out->mTDXF_P.mJc[1] = _cg_const_1[1];
  out->mTDXF_P.mJc[2] = _cg_const_1[2];
  out->mTDXF_P.mJc[3] = _cg_const_1[3];
  out->mTDXF_P.mJc[4] = _cg_const_1[4];
  out->mTDXF_P.mJc[5] = _cg_const_1[5];
  out->mTDXF_P.mJc[6] = _cg_const_1[6];
  out->mTDXF_P.mJc[7] = _cg_const_1[7];
  out->mTDXF_P.mJc[8] = _cg_const_1[8];
  out->mTDXF_P.mJc[9] = _cg_const_1[9];
  out->mTDXF_P.mJc[10] = _cg_const_1[10];
  out->mTDXF_P.mJc[11] = _cg_const_1[11];
  out->mTDXF_P.mJc[12] = _cg_const_1[12];
  out->mTDXF_P.mJc[13] = _cg_const_1[13];
  out->mTDXF_P.mJc[14] = _cg_const_1[14];
  out->mTDXF_P.mJc[15] = _cg_const_1[15];
  out->mTDXF_P.mJc[16] = _cg_const_1[16];
  out->mTDXF_P.mJc[17] = _cg_const_1[17];
  out->mTDXF_P.mJc[18] = _cg_const_1[18];
  out->mTDXF_P.mJc[19] = _cg_const_1[19];
  out->mTDXF_P.mJc[20] = _cg_const_1[20];
  out->mTDXF_P.mJc[21] = _cg_const_1[21];
  out->mTDXF_P.mJc[22] = _cg_const_1[22];
  out->mTDXF_P.mJc[23] = _cg_const_1[23];
  out->mTDXF_P.mJc[24] = _cg_const_1[24];
  out->mTDXF_P.mJc[25] = _cg_const_1[25];
  out->mTDXF_P.mJc[26] = _cg_const_1[26];
  out->mTDXF_P.mJc[27] = _cg_const_1[27];
  out->mTDXF_P.mJc[28] = _cg_const_1[28];
  out->mTDXF_P.mJc[29] = _cg_const_1[29];
  out->mTDXF_P.mJc[30] = _cg_const_1[30];
  out->mTDXF_P.mJc[31] = _cg_const_1[31];
  out->mTDXF_P.mJc[32] = _cg_const_1[32];
  out->mTDXF_P.mJc[33] = _cg_const_1[33];
  out->mTDXF_P.mJc[34] = _cg_const_1[34];
  out->mTDXF_P.mJc[35] = _cg_const_1[35];
  out->mTDXF_P.mJc[36] = _cg_const_1[36];
  out->mTDXF_P.mJc[37] = _cg_const_1[37];
  out->mTDXF_P.mJc[38] = _cg_const_1[38];
  out->mTDXF_P.mJc[39] = _cg_const_1[39];
  out->mTDXF_P.mJc[40] = _cg_const_1[40];
  out->mTDXF_P.mJc[41] = _cg_const_1[41];
  out->mTDXF_P.mJc[42] = _cg_const_1[42];
  out->mTDXF_P.mJc[43] = _cg_const_1[43];
  out->mTDXF_P.mJc[44] = _cg_const_1[44];
  out->mTDXF_P.mJc[45] = _cg_const_1[45];
  out->mTDXF_P.mJc[46] = _cg_const_1[46];
  out->mTDXF_P.mJc[47] = _cg_const_1[47];
  out->mTDXF_P.mJc[48] = _cg_const_1[48];
  out->mTDXF_P.mJc[49] = _cg_const_1[49];
  out->mTDXF_P.mJc[50] = _cg_const_1[50];
  out->mTDXF_P.mJc[51] = _cg_const_1[51];
  out->mTDXF_P.mJc[52] = _cg_const_1[52];
  out->mTDXF_P.mJc[53] = _cg_const_1[53];
  out->mTDXF_P.mJc[54] = _cg_const_1[54];
  out->mTDXF_P.mJc[55] = _cg_const_1[55];
  out->mTDXF_P.mJc[56] = _cg_const_1[56];
  out->mTDXF_P.mJc[57] = _cg_const_1[57];
  out->mTDXF_P.mJc[58] = _cg_const_1[58];
  for (i1 = 0; i1 < 154; i1++) {
    out->mTDXF_P.mIr[i1] = _cg_const_2[i1];
  }

  (void)LC;
  (void)out;
  return 0;
}
