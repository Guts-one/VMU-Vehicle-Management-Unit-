/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_mcon_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_mcon_p(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[59] = { 0, 0, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    11, 12, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14 };

  static int32_T _cg_const_2[14] = { 3, 4, 6, 8, 9, 10, 2, 11, 12, 13, 0, 1, 14,
    16 };

  (void)t1;
  (void)LC;
  out->mMCON_P.mNumCol = 58ULL;
  out->mMCON_P.mNumRow = 58ULL;
  out->mMCON_P.mJc[0] = _cg_const_1[0];
  out->mMCON_P.mJc[1] = _cg_const_1[1];
  out->mMCON_P.mJc[2] = _cg_const_1[2];
  out->mMCON_P.mJc[3] = _cg_const_1[3];
  out->mMCON_P.mJc[4] = _cg_const_1[4];
  out->mMCON_P.mJc[5] = _cg_const_1[5];
  out->mMCON_P.mJc[6] = _cg_const_1[6];
  out->mMCON_P.mJc[7] = _cg_const_1[7];
  out->mMCON_P.mJc[8] = _cg_const_1[8];
  out->mMCON_P.mJc[9] = _cg_const_1[9];
  out->mMCON_P.mJc[10] = _cg_const_1[10];
  out->mMCON_P.mJc[11] = _cg_const_1[11];
  out->mMCON_P.mJc[12] = _cg_const_1[12];
  out->mMCON_P.mJc[13] = _cg_const_1[13];
  out->mMCON_P.mJc[14] = _cg_const_1[14];
  out->mMCON_P.mJc[15] = _cg_const_1[15];
  out->mMCON_P.mJc[16] = _cg_const_1[16];
  out->mMCON_P.mJc[17] = _cg_const_1[17];
  out->mMCON_P.mJc[18] = _cg_const_1[18];
  out->mMCON_P.mJc[19] = _cg_const_1[19];
  out->mMCON_P.mJc[20] = _cg_const_1[20];
  out->mMCON_P.mJc[21] = _cg_const_1[21];
  out->mMCON_P.mJc[22] = _cg_const_1[22];
  out->mMCON_P.mJc[23] = _cg_const_1[23];
  out->mMCON_P.mJc[24] = _cg_const_1[24];
  out->mMCON_P.mJc[25] = _cg_const_1[25];
  out->mMCON_P.mJc[26] = _cg_const_1[26];
  out->mMCON_P.mJc[27] = _cg_const_1[27];
  out->mMCON_P.mJc[28] = _cg_const_1[28];
  out->mMCON_P.mJc[29] = _cg_const_1[29];
  out->mMCON_P.mJc[30] = _cg_const_1[30];
  out->mMCON_P.mJc[31] = _cg_const_1[31];
  out->mMCON_P.mJc[32] = _cg_const_1[32];
  out->mMCON_P.mJc[33] = _cg_const_1[33];
  out->mMCON_P.mJc[34] = _cg_const_1[34];
  out->mMCON_P.mJc[35] = _cg_const_1[35];
  out->mMCON_P.mJc[36] = _cg_const_1[36];
  out->mMCON_P.mJc[37] = _cg_const_1[37];
  out->mMCON_P.mJc[38] = _cg_const_1[38];
  out->mMCON_P.mJc[39] = _cg_const_1[39];
  out->mMCON_P.mJc[40] = _cg_const_1[40];
  out->mMCON_P.mJc[41] = _cg_const_1[41];
  out->mMCON_P.mJc[42] = _cg_const_1[42];
  out->mMCON_P.mJc[43] = _cg_const_1[43];
  out->mMCON_P.mJc[44] = _cg_const_1[44];
  out->mMCON_P.mJc[45] = _cg_const_1[45];
  out->mMCON_P.mJc[46] = _cg_const_1[46];
  out->mMCON_P.mJc[47] = _cg_const_1[47];
  out->mMCON_P.mJc[48] = _cg_const_1[48];
  out->mMCON_P.mJc[49] = _cg_const_1[49];
  out->mMCON_P.mJc[50] = _cg_const_1[50];
  out->mMCON_P.mJc[51] = _cg_const_1[51];
  out->mMCON_P.mJc[52] = _cg_const_1[52];
  out->mMCON_P.mJc[53] = _cg_const_1[53];
  out->mMCON_P.mJc[54] = _cg_const_1[54];
  out->mMCON_P.mJc[55] = _cg_const_1[55];
  out->mMCON_P.mJc[56] = _cg_const_1[56];
  out->mMCON_P.mJc[57] = _cg_const_1[57];
  out->mMCON_P.mJc[58] = _cg_const_1[58];
  out->mMCON_P.mIr[0] = _cg_const_2[0];
  out->mMCON_P.mIr[1] = _cg_const_2[1];
  out->mMCON_P.mIr[2] = _cg_const_2[2];
  out->mMCON_P.mIr[3] = _cg_const_2[3];
  out->mMCON_P.mIr[4] = _cg_const_2[4];
  out->mMCON_P.mIr[5] = _cg_const_2[5];
  out->mMCON_P.mIr[6] = _cg_const_2[6];
  out->mMCON_P.mIr[7] = _cg_const_2[7];
  out->mMCON_P.mIr[8] = _cg_const_2[8];
  out->mMCON_P.mIr[9] = _cg_const_2[9];
  out->mMCON_P.mIr[10] = _cg_const_2[10];
  out->mMCON_P.mIr[11] = _cg_const_2[11];
  out->mMCON_P.mIr[12] = _cg_const_2[12];
  out->mMCON_P.mIr[13] = _cg_const_2[13];
  (void)LC;
  (void)out;
  return 0;
}
