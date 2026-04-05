/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_mode.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_mode(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t5, NeDsMethodOutput *out)
{
  boolean_T t0;
  (void)LC;
  if (t5->mX.mX[4ULL] > 0.0) {
    t0 = true;
  } else if (t5->mX.mX[4ULL] <= 0.0) {
    t0 = (t5->mX.mX[18ULL] > 0.0);
  } else {
    t0 = false;
  }

  out->mMODE.mX[0ULL] = 1;
  out->mMODE.mX[1ULL] = (int32_T)(t5->mX.mX[21ULL] > 52.359877559829883);
  out->mMODE.mX[2ULL] = (int32_T)(t5->mX.mX[3ULL] + 1.0E-6 >= 0.0);
  out->mMODE.mX[3ULL] = (int32_T)(t5->mX.mX[24ULL] * -0.01 + t5->mX.mX[17ULL] >
    0.0);
  out->mMODE.mX[4ULL] = (int32_T)(t5->mX.mX[21ULL] <= 628.31853071795865);
  out->mMODE.mX[5ULL] = (int32_T)(t5->mX.mX[51ULL] < 0.0);
  out->mMODE.mX[6ULL] = (int32_T)t0;
  out->mMODE.mX[7ULL] = (int32_T)(t5->mX.mX[1ULL] > t5->mX.mX[25ULL]);
  out->mMODE.mX[8ULL] = (int32_T)(t5->mX.mX[1ULL] < -t5->mX.mX[25ULL]);
  out->mMODE.mX[9ULL] = (int32_T)(t5->mX.mX[5ULL] > t5->mX.mX[32ULL]);
  out->mMODE.mX[10ULL] = (int32_T)(t5->mX.mX[5ULL] < -t5->mX.mX[32ULL]);
  out->mMODE.mX[11ULL] = (int32_T)(((t5->mX.mX[0ULL] * -0.00071428571428571439 +
    t5->mX.mX[17ULL] * 1.0005102040816327) + t5->mX.mX[18ULL] *
    0.0071428571428571435) + t5->mX.mX[24ULL] * 0.01 > 0.0);
  out->mMODE.mX[12ULL] = 1;
  (void)LC;
  (void)out;
  return 0;
}
