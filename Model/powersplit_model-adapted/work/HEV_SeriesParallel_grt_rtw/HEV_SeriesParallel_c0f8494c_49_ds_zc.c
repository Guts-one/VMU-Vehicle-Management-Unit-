/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_zc.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_zc(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t4, NeDsMethodOutput *out)
{
  boolean_T t2;
  (void)LC;
  out->mZC.mX[0ULL] = ((t4->mX.mX[0ULL] * -0.00071428571428571439 + t4->mX.mX
                        [17ULL] * 1.0005102040816327) + t4->mX.mX[18ULL] *
                       0.0071428571428571435) + t4->mX.mX[24ULL] * 0.01;
  out->mZC.mX[9ULL] = t4->mX.mX[3ULL] + 1.0E-6;
  out->mZC.mX[3ULL] = t4->mX.mX[24ULL] * -0.01 + t4->mX.mX[17ULL];
  if (t4->mM.mX[7ULL] == 0) {
    out->mZC.mX[2ULL] = -t4->mX.mX[25ULL] - t4->mX.mX[1ULL];
  } else {
    out->mZC.mX[2ULL] = 0.0;
  }

  if (t4->mM.mX[9ULL] == 0) {
    out->mZC.mX[5ULL] = -t4->mX.mX[32ULL] - t4->mX.mX[5ULL];
  } else {
    out->mZC.mX[5ULL] = 0.0;
  }

  if (t4->mX.mX[4ULL] > 0.0) {
    t2 = true;
  } else if (t4->mX.mX[4ULL] <= 0.0) {
    t2 = (t4->mX.mX[18ULL] > 0.0);
  } else {
    t2 = false;
  }

  out->mZC.mX[1ULL] = t4->mX.mX[1ULL] - t4->mX.mX[25ULL];
  out->mZC.mX[4ULL] = t4->mX.mX[5ULL] - t4->mX.mX[32ULL];
  out->mZC.mX[6ULL] = 0.75000000000000011;
  out->mZC.mX[7ULL] = 144000.0;
  out->mZC.mX[8ULL] = (real_T)t2;
  out->mZC.mX[10ULL] = t4->mX.mX[21ULL] - 52.359877559829883;
  out->mZC.mX[11ULL] = 628.31853071795865 - t4->mX.mX[21ULL];
  out->mZC.mX[12ULL] = -t4->mX.mX[51ULL];
  (void)LC;
  (void)out;
  return 0;
}
