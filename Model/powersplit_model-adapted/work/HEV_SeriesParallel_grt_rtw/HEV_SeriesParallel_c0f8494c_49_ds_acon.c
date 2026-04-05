/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_acon.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_acon(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t133, NeDsMethodOutput *out)
{
  static real_T _cg_const_1[4] = { -0.2, 1.0, -0.76923076923076916,
    1.5384615384615383 };

  real_T t9[7];
  real_T t5[6];
  real_T t4[5];
  real_T t13[4];
  size_t t41;
  (void)t133;
  (void)LC;
  out->mACON.mX[11ULL] = 0.7142857142857143;
  t4[2ULL] = -0.02001;
  out->mACON.mX[12ULL] = -0.7142857142857143;
  out->mACON.mX[10ULL] = -0.051020408163265314;
  t9[3ULL] = -0.00011;
  t5[3ULL] = -0.2279;
  out->mACON.mX[0ULL] = 0.00010200000000000001;
  out->mACON.mX[9ULL] = -7.1428571428571434E-5;
  t4[0ULL] = 1.0;
  t4[1ULL] = -1.0;
  t4[3ULL] = 0.02;
  t4[4ULL] = 0.55555555555555558;
  t5[0ULL] = 1.0;
  t5[1ULL] = -1.0;
  t5[2ULL] = 0.02;
  t5[4ULL] = -0.69230769230769229;
  t5[5ULL] = -1.0;
  t9[0ULL] = 1.0;
  t9[1ULL] = -1.0;
  t9[2ULL] = 1.0;
  t9[4ULL] = 1.0;
  t9[5ULL] = -0.76923076923076916;
  t9[6ULL] = 1.5384615384615383;
  t13[0] = _cg_const_1[0];
  t13[1] = _cg_const_1[1];
  t13[2] = _cg_const_1[2];
  t13[3] = _cg_const_1[3];
  out->mACON.mX[1ULL] = 0.071428571428571438;
  out->mACON.mX[2ULL] = -1.0;
  out->mACON.mX[3ULL] = -1.0;
  out->mACON.mX[4ULL] = -0.30769230769230771;
  out->mACON.mX[5ULL] = 0.44444444444444442;
  out->mACON.mX[6ULL] = 1.0;
  out->mACON.mX[7ULL] = sin(0.0);
  out->mACON.mX[8ULL] = 1.0;
  for (t41 = 0ULL; t41 < 5ULL; t41++) {
    out->mACON.mX[t41 + 13ULL] = t4[t41];
  }

  out->mACON.mX[18ULL] = 1.0;
  for (t41 = 0ULL; t41 < 6ULL; t41++) {
    out->mACON.mX[t41 + 19ULL] = t5[t41];
  }

  out->mACON.mX[25ULL] = -1.0;
  out->mACON.mX[26ULL] = 0.8;
  out->mACON.mX[27ULL] = -0.2;
  out->mACON.mX[28ULL] = 0.55555555555555547;
  out->mACON.mX[29ULL] = -1.0;
  out->mACON.mX[30ULL] = 1.0;
  out->mACON.mX[31ULL] = 1.0;
  for (t41 = 0ULL; t41 < 7ULL; t41++) {
    out->mACON.mX[t41 + 32ULL] = t9[t41];
  }

  out->mACON.mX[39ULL] = 1.0;
  out->mACON.mX[40ULL] = -1.0;
  out->mACON.mX[41ULL] = 0.30762952615635747;
  out->mACON.mX[42ULL] = 0.69230769230769229;
  out->mACON.mX[43ULL] = -0.76923076923076916;
  out->mACON.mX[44ULL] = 1.0;
  out->mACON.mX[45ULL] = -0.76923076923076916;
  out->mACON.mX[46ULL] = 0.5;
  out->mACON.mX[47ULL] = 0.5;
  for (t41 = 0ULL; t41 < 4ULL; t41++) {
    out->mACON.mX[t41 + 48ULL] = t13[t41];
  }

  out->mACON.mX[52ULL] = 1.0;
  out->mACON.mX[53ULL] = 1.0;
  out->mACON.mX[54ULL] = 1.0;
  out->mACON.mX[55ULL] = -1.0;
  out->mACON.mX[56ULL] = 1.0;
  out->mACON.mX[57ULL] = -1.0;
  out->mACON.mX[58ULL] = 0.44444444444444442;
  out->mACON.mX[59ULL] = -0.25;
  out->mACON.mX[60ULL] = -0.69230769230769229;
  out->mACON.mX[61ULL] = -1.0;
  out->mACON.mX[62ULL] = -1.0;
  out->mACON.mX[63ULL] = -0.30769230769230771;
  out->mACON.mX[64ULL] = 0.44444444444444442;
  out->mACON.mX[65ULL] = -0.99979596000816173;
  out->mACON.mX[66ULL] = -1.0;
  out->mACON.mX[67ULL] = 1.0;
  out->mACON.mX[68ULL] = -1.0;
  out->mACON.mX[69ULL] = 1.0;
  out->mACON.mX[70ULL] = -0.3;
  out->mACON.mX[71ULL] = 1.0;
  out->mACON.mX[72ULL] = -1.0;
  out->mACON.mX[73ULL] = -1.0;
  out->mACON.mX[74ULL] = -0.2;
  out->mACON.mX[75ULL] = -1.0;
  out->mACON.mX[76ULL] = -1.0;
  out->mACON.mX[77ULL] = -1.0;
  out->mACON.mX[78ULL] = 1.0;
  out->mACON.mX[79ULL] = -0.3;
  out->mACON.mX[80ULL] = 1.0;
  out->mACON.mX[81ULL] = -1.0;
  out->mACON.mX[82ULL] = -1.0;
  out->mACON.mX[83ULL] = -0.2;
  out->mACON.mX[84ULL] = -1.0;
  out->mACON.mX[85ULL] = -1.0;
  out->mACON.mX[86ULL] = 1.0;
  out->mACON.mX[87ULL] = -0.5;
  out->mACON.mX[88ULL] = 1.0;
  out->mACON.mX[89ULL] = 1.0;
  out->mACON.mX[90ULL] = 0.1;
  out->mACON.mX[91ULL] = -1.0;
  out->mACON.mX[92ULL] = -0.01;
  out->mACON.mX[93ULL] = 1.0;
  out->mACON.mX[94ULL] = -1.0;
  out->mACON.mX[95ULL] = 1.0;
  out->mACON.mX[96ULL] = -1.0;
  out->mACON.mX[97ULL] = -1.0;
  out->mACON.mX[98ULL] = -0.092592592592592587;
  out->mACON.mX[99ULL] = 0.1;
  out->mACON.mX[100ULL] = -1.0;
  out->mACON.mX[101ULL] = -0.01;
  out->mACON.mX[102ULL] = 1.0;
  (void)LC;
  (void)out;
  return 0;
}
