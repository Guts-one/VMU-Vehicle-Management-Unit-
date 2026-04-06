/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_ic.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_ic(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)LC;
  out->mIC.mX[0ULL] = 0.0;
  out->mIC.mX[1ULL] = 0.0;
  out->mIC.mX[2ULL] = 0.0;
  out->mIC.mX[3ULL] = 0.0;
  out->mIC.mX[4ULL] = t1->mP_R.mX[2ULL] * 3600.0;
  out->mIC.mX[5ULL] = 0.0;
  out->mIC.mX[6ULL] = 0.0;
  out->mIC.mX[7ULL] = 0.0;
  out->mIC.mX[8ULL] = 0.0;
  out->mIC.mX[9ULL] = 0.0;
  out->mIC.mX[10ULL] = 0.0;
  out->mIC.mX[11ULL] = 0.0;
  out->mIC.mX[12ULL] = 0.0;
  out->mIC.mX[13ULL] = t1->mP_R.mX[5ULL];
  out->mIC.mX[14ULL] = 0.0;
  out->mIC.mX[15ULL] = 0.0;
  out->mIC.mX[16ULL] = 0.0;
  out->mIC.mX[17ULL] = 0.0;
  out->mIC.mX[18ULL] = 0.0;
  out->mIC.mX[19ULL] = t1->mP_R.mX[0ULL];
  out->mIC.mX[20ULL] = 0.0;
  out->mIC.mX[21ULL] = t1->mP_R.mX[1ULL] * 0.10471975511965977;
  out->mIC.mX[22ULL] = 0.0;
  out->mIC.mX[23ULL] = 0.0;
  out->mIC.mX[24ULL] = 0.0;
  out->mIC.mX[25ULL] = 0.0;
  out->mIC.mX[26ULL] = t1->mP_R.mX[3ULL];
  out->mIC.mX[27ULL] = 0.0;
  out->mIC.mX[28ULL] = 0.0;
  out->mIC.mX[29ULL] = 0.0;
  out->mIC.mX[30ULL] = 0.0;
  out->mIC.mX[31ULL] = 0.0;
  out->mIC.mX[32ULL] = 0.0;
  out->mIC.mX[33ULL] = 0.0;
  out->mIC.mX[34ULL] = 0.0;
  out->mIC.mX[35ULL] = 0.0;
  out->mIC.mX[36ULL] = 0.0;
  out->mIC.mX[37ULL] = 0.0;
  out->mIC.mX[38ULL] = 0.0;
  out->mIC.mX[39ULL] = 0.0;
  out->mIC.mX[40ULL] = 0.0;
  out->mIC.mX[41ULL] = 0.0;
  out->mIC.mX[42ULL] = 0.0;
  out->mIC.mX[43ULL] = t1->mP_R.mX[6ULL];
  out->mIC.mX[44ULL] = 0.0;
  out->mIC.mX[45ULL] = 0.0;
  out->mIC.mX[46ULL] = 0.0;
  out->mIC.mX[47ULL] = t1->mP_R.mX[8ULL];
  out->mIC.mX[48ULL] = 0.0;
  out->mIC.mX[49ULL] = t1->mP_R.mX[7ULL];
  out->mIC.mX[50ULL] = 0.0;
  out->mIC.mX[51ULL] = 0.0;
  out->mIC.mX[52ULL] = 0.0;
  out->mIC.mX[53ULL] = 0.0;
  out->mIC.mX[54ULL] = 0.0;
  out->mIC.mX[55ULL] = 0.0;
  out->mIC.mX[56ULL] = 0.0;
  out->mIC.mX[57ULL] = 0.0;
  (void)LC;
  (void)out;
  return 0;
}
