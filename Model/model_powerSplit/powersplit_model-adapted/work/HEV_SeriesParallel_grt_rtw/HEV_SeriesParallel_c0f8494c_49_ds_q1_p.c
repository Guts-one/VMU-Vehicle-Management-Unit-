/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_q1_p.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_q1_p(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_2[23] = { 0, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28,
    29, 30, 33, 34, 35, 40, 41, 42, 45, 46, 54, 55 };

  (void)t1;
  (void)LC;
  out->mQ1_P.mNumCol = 1ULL;
  out->mQ1_P.mNumRow = 58ULL;
  out->mQ1_P.mJc[0] = 0;
  out->mQ1_P.mJc[1] = 23;
  out->mQ1_P.mIr[0] = _cg_const_2[0];
  out->mQ1_P.mIr[1] = _cg_const_2[1];
  out->mQ1_P.mIr[2] = _cg_const_2[2];
  out->mQ1_P.mIr[3] = _cg_const_2[3];
  out->mQ1_P.mIr[4] = _cg_const_2[4];
  out->mQ1_P.mIr[5] = _cg_const_2[5];
  out->mQ1_P.mIr[6] = _cg_const_2[6];
  out->mQ1_P.mIr[7] = _cg_const_2[7];
  out->mQ1_P.mIr[8] = _cg_const_2[8];
  out->mQ1_P.mIr[9] = _cg_const_2[9];
  out->mQ1_P.mIr[10] = _cg_const_2[10];
  out->mQ1_P.mIr[11] = _cg_const_2[11];
  out->mQ1_P.mIr[12] = _cg_const_2[12];
  out->mQ1_P.mIr[13] = _cg_const_2[13];
  out->mQ1_P.mIr[14] = _cg_const_2[14];
  out->mQ1_P.mIr[15] = _cg_const_2[15];
  out->mQ1_P.mIr[16] = _cg_const_2[16];
  out->mQ1_P.mIr[17] = _cg_const_2[17];
  out->mQ1_P.mIr[18] = _cg_const_2[18];
  out->mQ1_P.mIr[19] = _cg_const_2[19];
  out->mQ1_P.mIr[20] = _cg_const_2[20];
  out->mQ1_P.mIr[21] = _cg_const_2[21];
  out->mQ1_P.mIr[22] = _cg_const_2[22];
  (void)LC;
  (void)out;
  return 0;
}
