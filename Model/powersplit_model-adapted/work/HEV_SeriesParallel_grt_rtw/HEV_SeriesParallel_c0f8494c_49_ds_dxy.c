/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxy.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_dxy(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t36, NeDsMethodOutput *out)
{
  real_T t2[9];
  real_T t4[6];
  real_T t1[5];
  real_T t3[5];
  real_T t5[5];
  real_T t7[5];
  real_T Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  real_T
    Electrical_Generic_Measurements1_Calculate_battery_power_charge_PS_Product_I1;
  real_T intermediate_der48;
  real_T intermediate_der50;
  real_T intermediate_der51;
  size_t t12;
  (void)LC;
  Electrical_DC_DC_Converter_Ideal_Transformer_i1 = (t36->mX.mX[0ULL] * 0.1 +
    t36->mX.mX[17ULL] * -0.071428571428571438) - t36->mX.mX[18ULL];
  Electrical_Generic_Measurements1_Calculate_battery_power_charge_PS_Product_I1 =
    t36->mX.mX[17ULL] * 0.7142857142857143;
  intermediate_der48 = (Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
                        0.7142857142857143 +
                        Electrical_Generic_Measurements1_Calculate_battery_power_charge_PS_Product_I1
                        * -0.071428571428571438) * 0.001;
  intermediate_der50 = -Electrical_DC_DC_Converter_Ideal_Transformer_i1 -
    Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  intermediate_der51 = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    -0.071428571428571438 + Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    -0.071428571428571438;
  Electrical_DC_DC_Converter_Ideal_Transformer_i1 =
    Electrical_DC_DC_Converter_Ideal_Transformer_i1 * 0.1 +
    Electrical_DC_DC_Converter_Ideal_Transformer_i1 * 0.1;
  t7[4ULL] = 0.0001;
  t1[0ULL] = t36->mX.mX[17ULL] * 0.071428571428571438 * 0.001 * 1000.0;
  t1[1ULL] =
    Electrical_Generic_Measurements1_Calculate_battery_power_charge_PS_Product_I1
    * 0.1 * 0.001 * 1000.0;
  t1[2ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 * 0.24691;
  t1[3ULL] = -2.7777777777777779E-5;
  t1[4ULL] = 0.1;
  t2[0ULL] = 1.0;
  t2[1ULL] = (t36->mX.mX[17ULL] * -0.051020408163265314 + (((t36->mX.mX[0ULL] *
    0.071428571428571438 + t36->mX.mX[17ULL] * -0.051020408163265314) +
    t36->mX.mX[18ULL] * -0.7142857142857143) - t36->mX.mX[24ULL])) * 0.001 *
    1000.0;
  t2[2ULL] = intermediate_der48 * 1000.0;
  t2[3ULL] = intermediate_der51 * 0.24691;
  t2[4ULL] = 1.9841269841269845E-5;
  t2[5ULL] = -0.071428571428571438;
  t2[6ULL] = 0.7142857142857143;
  t2[7ULL] = 1.0;
  t2[8ULL] = t36->mX.mX[24ULL] * 0.001 * 1000.0;
  t3[0ULL] = t36->mX.mX[17ULL] * -0.7142857142857143 * 0.001 * 1000.0;
  t3[1ULL] =
    -Electrical_Generic_Measurements1_Calculate_battery_power_charge_PS_Product_I1
    * 0.001 * 1000.0;
  t3[2ULL] = intermediate_der50 * 0.24691;
  t3[3ULL] = 0.00027777777777777778;
  t3[4ULL] = -1.0;
  t4[0ULL] = 1.0;
  t4[1ULL] = -1.0E-5;
  t4[2ULL] = -0.02;
  t4[3ULL] = 0.02;
  t4[4ULL] = -1.0;
  t4[5ULL] = -0.02;
  t5[0ULL] = 1.0;
  t5[1ULL] = 0.02;
  t5[2ULL] = -1.0;
  t5[3ULL] = -0.02;
  t5[4ULL] = 0.02;
  t7[0ULL] = 1.0;
  t7[1ULL] = -1.0E-5;
  t7[2ULL] = -1.0;
  t7[3ULL] = 1.0;
  for (t12 = 0ULL; t12 < 5ULL; t12++) {
    out->mDXY.mX[t12] = t1[t12];
  }

  out->mDXY.mX[5ULL] = 1.0;
  out->mDXY.mX[6ULL] = 1.0;
  out->mDXY.mX[7ULL] = 3.6000000000000005;
  for (t12 = 0ULL; t12 < 9ULL; t12++) {
    out->mDXY.mX[t12 + 8ULL] = t2[t12];
  }

  for (t12 = 0ULL; t12 < 5ULL; t12++) {
    out->mDXY.mX[t12 + 17ULL] = t3[t12];
  }

  for (t12 = 0ULL; t12 < 6ULL; t12++) {
    out->mDXY.mX[t12 + 22ULL] = t4[t12];
  }

  out->mDXY.mX[28ULL] = 1.0;
  for (t12 = 0ULL; t12 < 5ULL; t12++) {
    out->mDXY.mX[t12 + 29ULL] = t5[t12];
  }

  out->mDXY.mX[34ULL] = -1.0;
  out->mDXY.mX[35ULL] = -t36->mX.mX[17ULL] * 0.001 * 1000.0;
  out->mDXY.mX[36ULL] = t36->mX.mX[17ULL] * 0.001 * 1000.0;
  for (t12 = 0ULL; t12 < 5ULL; t12++) {
    out->mDXY.mX[t12 + 37ULL] = t7[t12];
  }

  out->mDXY.mX[42ULL] = 1.0;
  out->mDXY.mX[43ULL] = -1.0;
  out->mDXY.mX[44ULL] = 0.76923076923076916;
  out->mDXY.mX[45ULL] = 0.76923076923076916;
  out->mDXY.mX[46ULL] = 1.0;
  out->mDXY.mX[47ULL] = -1.0;
  out->mDXY.mX[48ULL] = 1.0;
  out->mDXY.mX[49ULL] = -1.0;
  out->mDXY.mX[50ULL] = 1.0;
  (void)LC;
  (void)out;
  return 0;
}
