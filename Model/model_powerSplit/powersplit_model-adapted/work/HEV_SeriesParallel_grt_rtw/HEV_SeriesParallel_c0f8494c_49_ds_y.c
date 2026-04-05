/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_y.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_y(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t7, NeDsMethodOutput *out)
{
  real_T Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  real_T
    Electrical_Generic_Measurements1_Calculate_battery_power_charge_PS_Product_I1;
  real_T Engine_Sensor_Ideal_Torque_Sensor_T;
  (void)LC;
  Electrical_DC_DC_Converter_Ideal_Transformer_i1 = (t7->mX.mX[0ULL] * 0.1 +
    t7->mX.mX[17ULL] * -0.071428571428571438) - t7->mX.mX[18ULL];
  out->mY.mX[3ULL] = t7->mX.mX[19ULL];
  Electrical_Generic_Measurements1_Calculate_battery_power_charge_PS_Product_I1 =
    t7->mX.mX[17ULL] * 0.7142857142857143;
  out->mY.mX[15ULL] = t7->mX.mX[21ULL];
  Engine_Sensor_Ideal_Torque_Sensor_T = ((t7->mX.mX[19ULL] * -0.02 + t7->mX.mX
    [21ULL] * 0.02) + t7->mX.mX[34ULL]) + t7->mX.mX[35ULL];
  out->mY.mX[17ULL] = -t7->mX.mX[21ULL];
  out->mY.mX[19ULL] = -t7->mX.mX[26ULL];
  out->mY.mX[21ULL] = -t7->mX.mX[19ULL];
  out->mY.mX[22ULL] = (t7->mX.mX[19ULL] * -0.02 + t7->mX.mX[21ULL] * 0.02) -
    t7->mX.mX[22ULL];
  out->mY.mX[25ULL] = ((t7->mX.mX[26ULL] * 0.0001 + t7->mX.mX[29ULL] *
                        0.76923076923076916) + t7->mX.mX[30ULL] *
                       0.76923076923076916) + t7->mU.mX[3ULL] *
    -0.76923076923076916;
  out->mY.mX[0ULL] = t7->mX.mX[17ULL];
  out->mY.mX[1ULL] = t7->mX.mX[17ULL] * (((t7->mX.mX[0ULL] *
    0.071428571428571438 + t7->mX.mX[17ULL] * -0.051020408163265314) + t7->
    mX.mX[18ULL] * -0.7142857142857143) - t7->mX.mX[24ULL]) * 0.001 * 1000.0;
  out->mY.mX[2ULL] = t7->mX.mX[2ULL];
  out->mY.mX[4ULL] = -(t7->mX.mX[19ULL] * 1.0E-5 - t7->mX.mX[20ULL]);
  out->mY.mX[5ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    Electrical_Generic_Measurements1_Calculate_battery_power_charge_PS_Product_I1
    * 0.001 * 1000.0;
  out->mY.mX[6ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    Electrical_DC_DC_Converter_Ideal_Transformer_i1 * 0.24691;
  out->mY.mX[7ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    -0.00027777777777777778;
  out->mY.mX[8ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mY.mX[9ULL] =
    Electrical_Generic_Measurements1_Calculate_battery_power_charge_PS_Product_I1;
  out->mY.mX[10ULL] = t7->mX.mX[17ULL];
  out->mY.mX[11ULL] = t7->mX.mX[17ULL] * t7->mX.mX[24ULL] * 0.001 * 1000.0;
  out->mY.mX[12ULL] = t7->mX.mX[6ULL];
  out->mY.mX[13ULL] = t7->mX.mX[26ULL];
  out->mY.mX[14ULL] = -(t7->mX.mX[26ULL] * 1.0E-5 - t7->mX.mX[27ULL]);
  out->mY.mX[16ULL] = Engine_Sensor_Ideal_Torque_Sensor_T;
  out->mY.mX[18ULL] = -Engine_Sensor_Ideal_Torque_Sensor_T;
  out->mY.mX[20ULL] = -t7->mX.mX[28ULL];
  out->mY.mX[23ULL] = t7->mX.mX[52ULL];
  out->mY.mX[24ULL] = t7->mX.mX[26ULL];
  out->mY.mX[26ULL] = t7->mX.mX[13ULL] * 3.6000000000000005;
  (void)LC;
  (void)out;
  return 0;
}
