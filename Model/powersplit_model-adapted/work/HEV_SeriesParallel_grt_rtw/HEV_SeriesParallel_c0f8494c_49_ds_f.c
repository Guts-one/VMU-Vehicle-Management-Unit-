/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_f.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_f(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t79, NeDsMethodOutput *out)
{
  ETTSf3049b48 t0;
  ETTSf3049b48 t1;
  real_T t11[1];
  real_T t20[1];
  real_T Electrical_Generic_Battery_x1;
  real_T Electrical_Generic_Battery_xV1;
  real_T Electrical_Motor_System_Motor_and_Drive_v;
  real_T Power_Split_Device_Planetary_Gear_gear_ring_planet_Trq;
  real_T Power_Split_Device_Planetary_Gear_gear_sun_planet_Trq;
  real_T Power_Split_Device_Planetary_Gear_gear_sun_planet_power;
  real_T intrm_sf_mf_3;
  real_T intrm_sf_mf_6;
  real_T t22;
  real_T t27;
  real_T t31;
  real_T t32;
  real_T t4;
  real_T t78;
  real_T zc_int10;
  real_T zc_int18;
  real_T zc_int8;
  size_t t10[1];
  size_t t12[1];
  size_t t9[1];
  t4 = ((t79->mX.mX[0ULL] * -0.00071428571428571439 + t79->mX.mX[17ULL] *
         1.0005102040816327) + t79->mX.mX[18ULL] * 0.0071428571428571435) +
    t79->mX.mX[24ULL] * 0.01;
  Electrical_Generic_Battery_xV1 = t79->mX.mX[4ULL] / 288000.0;
  Electrical_Motor_System_Motor_and_Drive_v = t79->mX.mX[24ULL] * -0.01 +
    t79->mX.mX[17ULL];
  Power_Split_Device_Planetary_Gear_gear_ring_planet_Trq = (((tanh(-t79->mX.mX
    [40ULL] * (t79->mX.mX[8ULL] - t79->mX.mX[21ULL]) * 4.0 / 1.0E-6 * 0.001) *
    0.03960000000000008 + 1.96) - 0.96039999999999992) - 1.0) * (-t79->mX.mX
    [40ULL] / 1.96);
  Power_Split_Device_Planetary_Gear_gear_sun_planet_Trq = (((tanh(t79->mX.mX
    [22ULL] * (t79->mX.mX[19ULL] - t79->mX.mX[21ULL]) * 4.0 / 1.0E-6 * 0.001) *
    0.078400000000000025 + 1.92) - 0.9216) - 1.0) * (t79->mX.mX[22ULL] / 1.92);
  Power_Split_Device_Planetary_Gear_gear_sun_planet_power = t79->mX.mX[13ULL] -
    t79->mX.mX[43ULL] * 0.3;
  t22 = t79->mX.mX[13ULL] - t79->mX.mX[47ULL] * 0.3;
  if (fabs(t79->mX.mX[13ULL]) <= 0.095) {
    zc_int18 = 0.1;
  } else if (fabs(t79->mX.mX[13ULL]) < 0.10500000000000001) {
    t78 = fabs(t79->mX.mX[13ULL]) * -0.19 + fabs(t79->mX.mX[13ULL]) * fabs
      (t79->mX.mX[13ULL]);
    zc_int18 = t78 / 0.020000000000000004 + 0.55125;
  } else if (fabs(t79->mX.mX[13ULL]) <= 9.9999999995E+7) {
    zc_int18 = fabs(t79->mX.mX[13ULL]);
  } else if (fabs(t79->mX.mX[13ULL]) < 1.00000000005E+8) {
    intrm_sf_mf_3 = fabs(t79->mX.mX[13ULL]) * 2.0000000001E+8 - fabs(t79->mX.mX
      [13ULL]) * fabs(t79->mX.mX[13ULL]);
    zc_int18 = intrm_sf_mf_3 / 0.020000000000000004 - 4.9999999994999987E+17;
  } else {
    zc_int18 = 1.0E+8;
  }

  t27 = t79->mX.mX[52ULL] * 100.0 / 0.54894784995425439;
  t78 = t79->mX.mX[56ULL] * 100.0 / 0.54894784995425439;
  if (t79->mM.mX[0ULL] != 0) {
    intrm_sf_mf_6 = 0.75000000000000011;
  } else {
    intrm_sf_mf_6 = 0.0;
  }

  zc_int8 = (t79->mM.mX[5ULL] != 0 ? 0.0 : t79->mX.mX[51ULL]) /
    0.95565749235474007;
  Electrical_Generic_Battery_x1 = zc_int8 * -21.3 / 1.0E+6 + 1.144;
  intrm_sf_mf_3 = pmf_exp(zc_int8 * 0.069 / 1000.0) *
    Electrical_Generic_Battery_x1 * 1.65;
  zc_int10 = (zc_int8 * 49.6 / 1.0E+6 + 0.226) / (intrm_sf_mf_3 == 0.0 ? 1.0E-16
    : intrm_sf_mf_3);
  t31 = (zc_int8 / 1000.0 * (zc_int8 / 1000.0) * -0.006 + zc_int8 * 0.056 /
         1000.0) + 0.486;
  if (fabs(t79->mX.mX[13ULL]) <= 0.095) {
    t32 = 0.1;
  } else if (fabs(t79->mX.mX[13ULL]) < 0.10500000000000001) {
    intrm_sf_mf_3 = fabs(t79->mX.mX[13ULL]) * -0.19 + fabs(t79->mX.mX[13ULL]) *
      fabs(t79->mX.mX[13ULL]);
    t32 = intrm_sf_mf_3 / 0.020000000000000004 + 0.55125;
  } else if (fabs(t79->mX.mX[13ULL]) <= 9.9999999995E+7) {
    t32 = fabs(t79->mX.mX[13ULL]);
  } else if (fabs(t79->mX.mX[13ULL]) < 1.00000000005E+8) {
    intrm_sf_mf_3 = fabs(t79->mX.mX[13ULL]) * 2.0000000001E+8 - fabs(t79->mX.mX
      [13ULL]) * fabs(t79->mX.mX[13ULL]);
    t32 = intrm_sf_mf_3 / 0.020000000000000004 - 4.9999999994999987E+17;
  } else {
    t32 = 1.0E+8;
  }

  intrm_sf_mf_3 = 1.0 - (1.0 - Electrical_Generic_Battery_xV1) * intrm_sf_mf_6;
  Electrical_Generic_Battery_xV1 = Electrical_Generic_Battery_xV1 * 250.0 /
    (intrm_sf_mf_3 == 0.0 ? 1.0E-16 : intrm_sf_mf_3);
  if (t79->mM.mX[1ULL] != 0) {
    intrm_sf_mf_6 = tanh((t79->mX.mX[21ULL] - 52.359877559829883) * 4.0 /
                         10.471975511965976);
  } else {
    intrm_sf_mf_6 = 0.0;
  }

  if (-Power_Split_Device_Planetary_Gear_gear_sun_planet_power / (zc_int18 ==
       0.0 ? 1.0E-16 : zc_int18) <= -100000.005) {
    intrm_sf_mf_3 = -100000.0;
  } else if (-Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
             (zc_int18 == 0.0 ? 1.0E-16 : zc_int18) < -99999.995) {
    intrm_sf_mf_3 = (-Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
                     (t32 == 0.0 ? 1.0E-16 : t32) * 200000.01 +
                     -Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
                     (t32 == 0.0 ? 1.0E-16 : t32) *
                     (-Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
                      (t32 == 0.0 ? 1.0E-16 : t32))) / 0.020000000000000004 +
      4.9999995000000116E+11;
  } else if (-Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
             (zc_int18 == 0.0 ? 1.0E-16 : zc_int18) <= 99999.995) {
    intrm_sf_mf_3 = -Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
      (t32 == 0.0 ? 1.0E-16 : t32);
  } else if (-Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
             (zc_int18 == 0.0 ? 1.0E-16 : zc_int18) < 100000.005) {
    intrm_sf_mf_3 = (-Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
                     (t32 == 0.0 ? 1.0E-16 : t32) * 200000.01 -
                     -Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
                     (t32 == 0.0 ? 1.0E-16 : t32) *
                     (-Power_Split_Device_Planetary_Gear_gear_sun_planet_power /
                      (t32 == 0.0 ? 1.0E-16 : t32))) / 0.020000000000000004 -
      4.9999995000000116E+11;
  } else {
    intrm_sf_mf_3 = 100000.0;
  }

  Power_Split_Device_Planetary_Gear_gear_sun_planet_power = sin(atan(t27 *
    zc_int10 - (t27 * zc_int10 - atan(t27 * zc_int10)) * t31) * 1.65) * zc_int8 *
    Electrical_Generic_Battery_x1 * 1.0351048413332149;
  if (-t22 / (zc_int18 == 0.0 ? 1.0E-16 : zc_int18) <= -100000.005) {
    t27 = -100000.0;
  } else if (-t22 / (zc_int18 == 0.0 ? 1.0E-16 : zc_int18) < -99999.995) {
    t27 = (-t22 / (t32 == 0.0 ? 1.0E-16 : t32) * 200000.01 + -t22 / (t32 == 0.0 ?
            1.0E-16 : t32) * (-t22 / (t32 == 0.0 ? 1.0E-16 : t32))) /
      0.020000000000000004 + 4.9999995000000116E+11;
  } else if (-t22 / (zc_int18 == 0.0 ? 1.0E-16 : zc_int18) <= 99999.995) {
    t27 = -t22 / (t32 == 0.0 ? 1.0E-16 : t32);
  } else if (-t22 / (zc_int18 == 0.0 ? 1.0E-16 : zc_int18) < 100000.005) {
    t27 = (-t22 / (t32 == 0.0 ? 1.0E-16 : t32) * 200000.01 - -t22 / (t32 == 0.0 ?
            1.0E-16 : t32) * (-t22 / (t32 == 0.0 ? 1.0E-16 : t32))) /
      0.020000000000000004 - 4.9999995000000116E+11;
  } else {
    t27 = 100000.0;
  }

  zc_int18 = sin(atan(t78 * zc_int10 - (t78 * zc_int10 - atan(t78 * zc_int10)) *
                      t31) * 1.65) * zc_int8 * Electrical_Generic_Battery_x1 *
    1.0351048413332149;
  if (t79->mX.mX[1ULL] != t79->mX.mX[1ULL]) {
    t78 = t79->mX.mX[1ULL];
  } else if (t79->mX.mX[1ULL] > 0.0) {
    t78 = 1.0;
  } else {
    t78 = t79->mX.mX[1ULL] < 0.0 ? -1.0 : 0.0;
  }

  t11[0ULL] = t78 * t79->mX.mX[19ULL];
  t9[0] = 13ULL;
  t10[0] = 1ULL;
  tlu2_linear_nearest_prelookup(&t0.mField0[0ULL], &t0.mField1[0ULL],
    &t0.mField2[0ULL], ((const _NeDynamicSystem*)(LC))->mField1, &t11[0ULL],
    &t9[0ULL], &t10[0ULL]);
  if (t79->mX.mX[5ULL] != t79->mX.mX[5ULL]) {
    t78 = t79->mX.mX[5ULL];
  } else if (t79->mX.mX[5ULL] > 0.0) {
    t78 = 1.0;
  } else {
    t78 = t79->mX.mX[5ULL] < 0.0 ? -1.0 : 0.0;
  }

  t11[0ULL] = t78 * t79->mX.mX[26ULL];
  t12[0] = 17ULL;
  tlu2_linear_nearest_prelookup(&t1.mField0[0ULL], &t1.mField1[0ULL],
    &t1.mField2[0ULL], ((const _NeDynamicSystem*)(LC))->mField3, &t11[0ULL],
    &t12[0ULL], &t10[0ULL]);
  if (t79->mM.mX[7ULL] != 0) {
    out->mF.mX[25ULL] = t79->mX.mX[20ULL] - t79->mX.mX[25ULL];
  } else if (t79->mM.mX[8ULL] != 0) {
    out->mF.mX[25ULL] = t79->mX.mX[20ULL] - (-t79->mX.mX[25ULL]);
  } else {
    out->mF.mX[25ULL] = t79->mX.mX[20ULL] - t79->mX.mX[1ULL];
  }

  out->mF.mX[26ULL] = -((t79->mX.mX[19ULL] * t79->mX.mX[20ULL] * 0.001 +
    t79->mX.mX[20ULL] * t79->mX.mX[20ULL] * 0.00011635528346628851) / (t4 == 0.0
    ? 1.0E-16 : t4) * 1000.0);
  if (t79->mM.mX[9ULL] != 0) {
    out->mF.mX[29ULL] = t79->mX.mX[27ULL] - t79->mX.mX[32ULL];
  } else if (t79->mM.mX[10ULL] != 0) {
    out->mF.mX[29ULL] = t79->mX.mX[27ULL] - (-t79->mX.mX[32ULL]);
  } else {
    out->mF.mX[29ULL] = t79->mX.mX[27ULL] - t79->mX.mX[5ULL];
  }

  out->mF.mX[30ULL] = -((t79->mX.mX[26ULL] * t79->mX.mX[27ULL] * 0.001 +
    t79->mX.mX[27ULL] * t79->mX.mX[27ULL] * 0.00010356898857988329) /
                        (Electrical_Motor_System_Motor_and_Drive_v == 0.0 ?
    1.0E-16 : Electrical_Motor_System_Motor_and_Drive_v) * 1000.0);
  if (t79->mU.mX[2ULL] > 1.0) {
    out->mF.mX[33ULL] = t79->mX.mX[38ULL] - 1.0;
  } else if (t79->mU.mX[2ULL] >= 0.0) {
    out->mF.mX[33ULL] = t79->mX.mX[38ULL] - t79->mU.mX[2ULL];
  } else {
    out->mF.mX[33ULL] = t79->mX.mX[38ULL];
  }

  if (t79->mX.mX[21ULL] >= 0.0) {
    out->mF.mX[34ULL] = t79->mX.mX[37ULL] - t79->mX.mX[21ULL] *
      3.9788735772973834E-6;
  } else {
    out->mF.mX[34ULL] = t79->mX.mX[37ULL];
  }

  tlu2_1d_linear_nearest_value(&t11[0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL],
    ((const _NeDynamicSystem*)(LC))->mField0, &t9[0ULL], &t10[0ULL]);
  tlu2_1d_linear_nearest_value(&t20[0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL],
    ((const _NeDynamicSystem*)(LC))->mField2, &t12[0ULL], &t10[0ULL]);
  out->mF.mX[0ULL] = -0.0;
  out->mF.mX[1ULL] = -0.0;
  out->mF.mX[2ULL] = -0.0;
  out->mF.mX[3ULL] = -0.0;
  out->mF.mX[4ULL] = -0.0;
  out->mF.mX[5ULL] = -(t79->mM.mX[6ULL] != 0 ? -t79->mX.mX[18ULL] : 0.0);
  out->mF.mX[6ULL] = -t79->mX.mX[18ULL] * (real_T)(t79->mX.mX[18ULL] < 0.0) /
    288000.0;
  out->mF.mX[7ULL] = -0.0;
  out->mF.mX[8ULL] = -0.0;
  out->mF.mX[9ULL] = -0.0;
  out->mF.mX[10ULL] = -0.0;
  out->mF.mX[11ULL] = -0.0;
  out->mF.mX[12ULL] = -0.0;
  out->mF.mX[13ULL] = -0.0;
  out->mF.mX[14ULL] = -0.0;
  out->mF.mX[15ULL] = -(-t79->mDP_R.mX[2ULL] - ((real_T)(t79->mX.mX[13ULL] >=
    0.0) * 2.0 - 1.0) * t79->mX.mX[13ULL] * t79->mX.mX[13ULL] * 0.331344);
  out->mF.mX[16ULL] = -0.0;
  out->mF.mX[17ULL] = 0.0;
  out->mF.mX[18ULL] = 0.0;
  out->mF.mX[19ULL] = 0.0;
  out->mF.mX[20ULL] = 0.0;
  out->mF.mX[21ULL] = 0.0;
  out->mF.mX[22ULL] = 0.0;
  out->mF.mX[23ULL] = 0.0;
  out->mF.mX[24ULL] = 0.0;
  out->mF.mX[27ULL] = -t11[0ULL];
  out->mF.mX[28ULL] = -(t79->mX.mX[18ULL] * 0.001 +
                        Electrical_Generic_Battery_xV1);
  out->mF.mX[31ULL] = -t20[0ULL];
  out->mF.mX[32ULL] = -(t79->mX.mX[38ULL] * ((t79->mX.mX[21ULL] *
    0.41582213766815418 + t79->mX.mX[21ULL] * t79->mX.mX[21ULL] *
    -0.00079416178388310419) + 217.7239621497128) * intrm_sf_mf_6);
  out->mF.mX[35ULL] = 0.0;
  out->mF.mX[36ULL] = -Power_Split_Device_Planetary_Gear_gear_ring_planet_Trq /
    1.000204081632653;
  out->mF.mX[37ULL] = Power_Split_Device_Planetary_Gear_gear_ring_planet_Trq;
  out->mF.mX[38ULL] = 0.0;
  out->mF.mX[39ULL] = -Power_Split_Device_Planetary_Gear_gear_sun_planet_Trq /
    1.25;
  out->mF.mX[40ULL] = Power_Split_Device_Planetary_Gear_gear_sun_planet_Trq /
    2.25;
  out->mF.mX[41ULL] = 0.0;
  out->mF.mX[42ULL] = 0.0;
  out->mF.mX[43ULL] = -intrm_sf_mf_3 / 10.0;
  out->mF.mX[44ULL] = -Power_Split_Device_Planetary_Gear_gear_sun_planet_power;
  out->mF.mX[45ULL] = Power_Split_Device_Planetary_Gear_gear_sun_planet_power;
  out->mF.mX[46ULL] = 0.0;
  out->mF.mX[47ULL] = 0.0;
  out->mF.mX[48ULL] = -t27 / 10.0;
  out->mF.mX[49ULL] = -zc_int18;
  out->mF.mX[50ULL] = zc_int18;
  out->mF.mX[51ULL] = -(t79->mDP_R.mX[1ULL] * 1.35 / 2.7 / 2.0);
  out->mF.mX[52ULL] = 0.0;
  out->mF.mX[53ULL] = 0.0;
  out->mF.mX[54ULL] = 0.0;
  out->mF.mX[55ULL] = 0.0;
  out->mF.mX[56ULL] = 0.0;
  out->mF.mX[57ULL] = 0.0;
  (void)LC;
  (void)out;
  return 0;
}
