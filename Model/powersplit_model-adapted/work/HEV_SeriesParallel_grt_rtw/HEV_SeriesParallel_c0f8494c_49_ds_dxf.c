/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_dxf.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_dxf(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t321, NeDsMethodOutput *out)
{
  ETTSf3049b48 t0;
  ETTSf3049b48 t1;
  real_T t36[6];
  real_T t32[4];
  real_T t34[4];
  real_T t44[4];
  real_T t39[1];
  real_T Electrical_Generic_Battery_xV1;
  real_T Electrical_Generic_Battery_y1;
  real_T Vehicle_Left_Tire_tire_road_interaction_v_rel;
  real_T Vehicle_Right_Tire_tire_road_interaction_v_rel;
  real_T intermediate_der139;
  real_T intermediate_der142;
  real_T intermediate_der145;
  real_T intermediate_der147;
  real_T intermediate_der156;
  real_T intermediate_der32;
  real_T intermediate_der37;
  real_T intermediate_der76;
  real_T intermediate_der78;
  real_T intermediate_der80;
  real_T intermediate_der88;
  real_T intermediate_der92;
  real_T intermediate_der93;
  real_T intrm_sf_mf_20;
  real_T intrm_sf_mf_7;
  real_T t111;
  real_T t119;
  real_T t12;
  real_T t121;
  real_T t125;
  real_T t128;
  real_T t129;
  real_T t132;
  real_T t148;
  real_T t151;
  real_T t16;
  real_T t175;
  real_T t243;
  real_T t7;
  real_T t8;
  real_T t83;
  real_T t87;
  real_T t95;
  real_T zc_int10;
  size_t t18[1];
  size_t t19[1];
  size_t t21[1];
  size_t t54;
  t12 = ((t321->mX.mX[0ULL] * -0.00071428571428571439 + t321->mX.mX[17ULL] *
          1.0005102040816327) + t321->mX.mX[18ULL] * 0.0071428571428571435) +
    t321->mX.mX[24ULL] * 0.01;
  Electrical_Generic_Battery_xV1 = t321->mX.mX[4ULL] / 288000.0;
  t16 = t321->mX.mX[24ULL] * -0.01 + t321->mX.mX[17ULL];
  t111 = (t321->mX.mX[21ULL] * 0.41582213766815418 + t321->mX.mX[21ULL] *
          t321->mX.mX[21ULL] * -0.00079416178388310419) + 217.7239621497128;
  intermediate_der76 = t321->mX.mX[8ULL] - t321->mX.mX[21ULL];
  intermediate_der92 = t321->mX.mX[19ULL] - t321->mX.mX[21ULL];
  Vehicle_Left_Tire_tire_road_interaction_v_rel = t321->mX.mX[13ULL] -
    t321->mX.mX[43ULL] * 0.3;
  Vehicle_Right_Tire_tire_road_interaction_v_rel = t321->mX.mX[13ULL] -
    t321->mX.mX[47ULL] * 0.3;
  if (fabs(t321->mX.mX[13ULL]) <= 0.095) {
    intermediate_der156 = 0.1;
  } else if (fabs(t321->mX.mX[13ULL]) < 0.10500000000000001) {
    t119 = fabs(t321->mX.mX[13ULL]) * -0.19 + fabs(t321->mX.mX[13ULL]) * fabs
      (t321->mX.mX[13ULL]);
    intermediate_der156 = t119 / 0.020000000000000004 + 0.55125;
  } else if (fabs(t321->mX.mX[13ULL]) <= 9.9999999995E+7) {
    intermediate_der156 = fabs(t321->mX.mX[13ULL]);
  } else if (fabs(t321->mX.mX[13ULL]) < 1.00000000005E+8) {
    intrm_sf_mf_20 = fabs(t321->mX.mX[13ULL]) * 2.0000000001E+8 - fabs
      (t321->mX.mX[13ULL]) * fabs(t321->mX.mX[13ULL]);
    intermediate_der156 = intrm_sf_mf_20 / 0.020000000000000004 -
      4.9999999994999987E+17;
  } else {
    intermediate_der156 = 1.0E+8;
  }

  t119 = t321->mX.mX[52ULL] * 100.0 / 0.54894784995425439;
  intrm_sf_mf_20 = t321->mX.mX[56ULL] * 100.0 / 0.54894784995425439;
  t121 = t321->mX.mX[19ULL] * t321->mX.mX[20ULL] * 0.001 + t321->mX.mX[20ULL] *
    t321->mX.mX[20ULL] * 0.00011635528346628851;
  intrm_sf_mf_7 = t321->mX.mX[26ULL] * t321->mX.mX[27ULL] * 0.001 + t321->mX.mX
    [27ULL] * t321->mX.mX[27ULL] * 0.00010356898857988329;
  if (t321->mM.mX[0ULL] != 0) {
    t95 = 0.75000000000000011;
  } else {
    t95 = 0.0;
  }

  t8 = (t321->mM.mX[5ULL] != 0 ? 0.0 : t321->mX.mX[51ULL]) / 0.95565749235474007;
  t7 = t8 * -21.3 / 1.0E+6 + 1.144;
  t83 = t8 * 49.6;
  t243 = t8 * 0.069;
  t129 = pmf_exp(t243 / 1000.0) * t7 * 1.65;
  zc_int10 = (t83 / 1.0E+6 + 0.226) / (t129 == 0.0 ? 1.0E-16 : t129);
  t125 = (t8 / 1000.0 * (t8 / 1000.0) * -0.006 + t8 * 0.056 / 1000.0) + 0.486;
  if (fabs(t321->mX.mX[13ULL]) <= 0.095) {
    t128 = 0.1;
  } else if (fabs(t321->mX.mX[13ULL]) < 0.10500000000000001) {
    t132 = fabs(t321->mX.mX[13ULL]) * -0.19 + fabs(t321->mX.mX[13ULL]) * fabs
      (t321->mX.mX[13ULL]);
    t128 = t132 / 0.020000000000000004 + 0.55125;
  } else if (fabs(t321->mX.mX[13ULL]) <= 9.9999999995E+7) {
    t128 = fabs(t321->mX.mX[13ULL]);
  } else if (fabs(t321->mX.mX[13ULL]) < 1.00000000005E+8) {
    t132 = fabs(t321->mX.mX[13ULL]) * 2.0000000001E+8 - fabs(t321->mX.mX[13ULL])
      * fabs(t321->mX.mX[13ULL]);
    t128 = t132 / 0.020000000000000004 - 4.9999999994999987E+17;
  } else {
    t128 = 1.0E+8;
  }

  if (t321->mM.mX[1ULL] != 0) {
    t129 = tanh((t321->mX.mX[21ULL] - 52.359877559829883) * 4.0 /
                10.471975511965976);
  } else {
    t129 = 0.0;
  }

  intermediate_der32 = -0.0;
  intermediate_der37 = -t321->mX.mX[4ULL] / 8.2944E+10 * 0.0;
  intermediate_der139 = -t321->mX.mX[40ULL] * intermediate_der76 * 4.0;
  t132 = cosh(intermediate_der139 / 1.0E-6 * 0.001) * cosh(intermediate_der139 /
    1.0E-6 * 0.001);
  intermediate_der78 = (((tanh(intermediate_der139 / 1.0E-6 * 0.001) *
    0.03960000000000008 + 1.96) - 0.96039999999999992) - 1.0) *
    -0.51020408163265307 + -t321->mX.mX[40ULL] / 1.96 * (-intermediate_der76 *
    4.0 / 1.0E-6) * (1.0 / (t132 == 0.0 ? 1.0E-16 : t132)) *
    3.9600000000000082E-5;
  t132 = cosh(intermediate_der139 / 1.0E-6 * 0.001) * cosh(intermediate_der139 /
    1.0E-6 * 0.001);
  intermediate_der76 = -t321->mX.mX[40ULL] / 1.96 * (t321->mX.mX[40ULL] * 4.0 /
    1.0E-6) * (1.0 / (t132 == 0.0 ? 1.0E-16 : t132)) * 3.9600000000000082E-5;
  t132 = cosh(intermediate_der139 / 1.0E-6 * 0.001) * cosh(intermediate_der139 /
    1.0E-6 * 0.001);
  intermediate_der80 = -t321->mX.mX[40ULL] / 1.96 * (-t321->mX.mX[40ULL] * 4.0 /
    1.0E-6) * (1.0 / (t132 == 0.0 ? 1.0E-16 : t132)) * 3.9600000000000082E-5;
  t148 = t321->mX.mX[22ULL] * intermediate_der92 * 4.0;
  intermediate_der139 = cosh(t148 / 1.0E-6 * 0.001) * cosh(t148 / 1.0E-6 * 0.001);
  intermediate_der88 = t321->mX.mX[22ULL] / 1.92 * (-t321->mX.mX[22ULL] * 4.0 /
    1.0E-6) * (1.0 / (intermediate_der139 == 0.0 ? 1.0E-16 : intermediate_der139))
    * 7.8400000000000022E-5;
  intermediate_der145 = cosh(t148 / 1.0E-6 * 0.001) * cosh(t148 / 1.0E-6 * 0.001);
  intermediate_der92 = (((tanh(t148 / 1.0E-6 * 0.001) * 0.078400000000000025 +
    1.92) - 0.9216) - 1.0) * 0.52083333333333337 + t321->mX.mX[22ULL] / 1.92 *
    (intermediate_der92 * 4.0 / 1.0E-6) * (1.0 / (intermediate_der145 == 0.0 ?
    1.0E-16 : intermediate_der145)) * 7.8400000000000022E-5;
  t151 = cosh(t148 / 1.0E-6 * 0.001) * cosh(t148 / 1.0E-6 * 0.001);
  intermediate_der93 = t321->mX.mX[22ULL] / 1.92 * (t321->mX.mX[22ULL] * 4.0 /
    1.0E-6) * (1.0 / (t151 == 0.0 ? 1.0E-16 : t151)) * 7.8400000000000022E-5;
  if (t321->mM.mX[0ULL] != 0) {
    t175 = 0.64000000000000012;
    t148 = 0.25;
    intermediate_der139 = -0.60000000000000009 / (t175 == 0.0 ? 1.0E-16 : t175) *
      0.0 + (-0.30000000000000004 / (t148 == 0.0 ? 1.0E-16 : t148) *
             intermediate_der32 + intermediate_der32 / 0.5) / 0.8;
  } else {
    intermediate_der139 = 0.0;
  }

  Electrical_Generic_Battery_y1 = (real_T)(t321->mM.mX[5ULL] == 0) /
    0.95565749235474007;
  intermediate_der142 = Electrical_Generic_Battery_y1 * -21.3 / 1.0E+6;
  t132 = pmf_exp(t243 / 1000.0) * pmf_exp(t243 / 1000.0) * t7 * t7 *
    2.7224999999999997;
  t148 = pmf_exp(t243 / 1000.0) * t7 * 1.65;
  intermediate_der32 = (pmf_exp(t243 / 1000.0) * intermediate_der142 * 1.65 +
                        Electrical_Generic_Battery_y1 * 0.069 / 1000.0 * pmf_exp
                        (t243 / 1000.0) * t7 * 1.65) * (-(t83 / 1.0E+6 + 0.226) /
    (t132 == 0.0 ? 1.0E-16 : t132)) + Electrical_Generic_Battery_y1 * 49.6 /
    1.0E+6 / (t148 == 0.0 ? 1.0E-16 : t148);
  t87 = t8 / 1000.0 * (Electrical_Generic_Battery_y1 / 1000.0) * -0.012 +
    Electrical_Generic_Battery_y1 * 0.056 / 1000.0;
  if (fabs(t321->mX.mX[13ULL]) <= 0.095) {
    intermediate_der145 = 0.0;
  } else if (fabs(t321->mX.mX[13ULL]) < 0.10500000000000001) {
    if (t321->mX.mX[13ULL] != t321->mX.mX[13ULL]) {
      t132 = t321->mX.mX[13ULL];
    } else if (t321->mX.mX[13ULL] > 0.0) {
      t132 = 1.0;
    } else {
      t132 = t321->mX.mX[13ULL] < 0.0 ? -1.0 : 0.0;
    }

    if (t321->mX.mX[13ULL] != t321->mX.mX[13ULL]) {
      t148 = t321->mX.mX[13ULL];
    } else if (t321->mX.mX[13ULL] > 0.0) {
      t148 = 1.0;
    } else {
      t148 = t321->mX.mX[13ULL] < 0.0 ? -1.0 : 0.0;
    }

    if (t321->mX.mX[13ULL] != t321->mX.mX[13ULL]) {
      t243 = t321->mX.mX[13ULL];
    } else if (t321->mX.mX[13ULL] > 0.0) {
      t243 = 1.0;
    } else {
      t243 = t321->mX.mX[13ULL] < 0.0 ? -1.0 : 0.0;
    }

    t148 = (t132 * -0.19 + t148 * fabs(t321->mX.mX[13ULL])) + t243 * fabs
      (t321->mX.mX[13ULL]);
    intermediate_der145 = t148 / 0.020000000000000004;
  } else if (fabs(t321->mX.mX[13ULL]) <= 9.9999999995E+7) {
    if (t321->mX.mX[13ULL] != t321->mX.mX[13ULL]) {
      intermediate_der145 = t321->mX.mX[13ULL];
    } else if (t321->mX.mX[13ULL] > 0.0) {
      intermediate_der145 = 1.0;
    } else {
      intermediate_der145 = t321->mX.mX[13ULL] < 0.0 ? -1.0 : 0.0;
    }
  } else if (fabs(t321->mX.mX[13ULL]) < 1.00000000005E+8) {
    if (t321->mX.mX[13ULL] != t321->mX.mX[13ULL]) {
      t132 = t321->mX.mX[13ULL];
    } else if (t321->mX.mX[13ULL] > 0.0) {
      t132 = 1.0;
    } else {
      t132 = t321->mX.mX[13ULL] < 0.0 ? -1.0 : 0.0;
    }

    if (t321->mX.mX[13ULL] != t321->mX.mX[13ULL]) {
      t243 = t321->mX.mX[13ULL];
    } else if (t321->mX.mX[13ULL] > 0.0) {
      t243 = 1.0;
    } else {
      t243 = t321->mX.mX[13ULL] < 0.0 ? -1.0 : 0.0;
    }

    if (t321->mX.mX[13ULL] != t321->mX.mX[13ULL]) {
      t148 = t321->mX.mX[13ULL];
    } else if (t321->mX.mX[13ULL] > 0.0) {
      t148 = 1.0;
    } else {
      t148 = t321->mX.mX[13ULL] < 0.0 ? -1.0 : 0.0;
    }

    t175 = t132 * 2.0000000001E+8 - (t243 * fabs(t321->mX.mX[13ULL]) + t148 *
      fabs(t321->mX.mX[13ULL]));
    intermediate_der145 = t175 / 0.020000000000000004;
  } else {
    intermediate_der145 = 0.0;
  }

  t148 = -(Electrical_Generic_Battery_xV1 * 250.0);
  t132 = (1.0 - (1.0 - Electrical_Generic_Battery_xV1) * t95) * (1.0 - (1.0 -
    Electrical_Generic_Battery_xV1) * t95);
  t243 = 1.0 - (1.0 - Electrical_Generic_Battery_xV1) * t95;
  t151 = -(-3.4722222222222224E-6 * t95) * (t148 / (t132 == 0.0 ? 1.0E-16 : t132))
    + 0.00086805555555555562 / (t243 == 0.0 ? 1.0E-16 : t243);
  intermediate_der147 = -((1.0 - Electrical_Generic_Battery_xV1) *
    intermediate_der139 + -intermediate_der37 * t95) * (t148 / (t132 == 0.0 ?
    1.0E-16 : t132)) + intermediate_der37 * 250.0 / (t243 == 0.0 ? 1.0E-16 :
    t243);
  if (t321->mM.mX[1ULL] != 0) {
    t83 = cosh((t321->mX.mX[21ULL] - 52.359877559829883) * 4.0 /
               10.471975511965976) * cosh((t321->mX.mX[21ULL] -
      52.359877559829883) * 4.0 / 10.471975511965976);
    Electrical_Generic_Battery_xV1 = 0.38197186342054884 * (1.0 / (t83 == 0.0 ?
      1.0E-16 : t83));
  } else {
    Electrical_Generic_Battery_xV1 = 0.0;
  }

  if (-Vehicle_Left_Tire_tire_road_interaction_v_rel / (intermediate_der156 ==
       0.0 ? 1.0E-16 : intermediate_der156) <= -100000.005) {
    t95 = 0.0;
  } else if (-Vehicle_Left_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <
             -99999.995) {
    t243 = t128 * t128;
    t175 = t128 * t128;
    t132 = t128 * t128;
    t95 = (((Vehicle_Left_Tire_tire_road_interaction_v_rel / (t243 == 0.0 ?
              1.0E-16 : t243) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
              1.0E-16 : t128)) * 200000.01 +
            (Vehicle_Left_Tire_tire_road_interaction_v_rel / (t175 == 0.0 ?
              1.0E-16 : t175) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
              1.0E-16 : t128)) * (-Vehicle_Left_Tire_tire_road_interaction_v_rel
             / (t128 == 0.0 ? 1.0E-16 : t128))) +
           (Vehicle_Left_Tire_tire_road_interaction_v_rel / (t132 == 0.0 ?
             1.0E-16 : t132) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
             1.0E-16 : t128)) * (-Vehicle_Left_Tire_tire_road_interaction_v_rel /
            (t128 == 0.0 ? 1.0E-16 : t128))) / 0.020000000000000004;
  } else if (-Vehicle_Left_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <=
             99999.995) {
    t148 = t128 * t128;
    t95 = Vehicle_Left_Tire_tire_road_interaction_v_rel / (t148 == 0.0 ? 1.0E-16
      : t148) * intermediate_der145 + -1.0 / (t128 == 0.0 ? 1.0E-16 : t128);
  } else if (-Vehicle_Left_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <
             100000.005) {
    t132 = t128 * t128;
    t148 = t128 * t128;
    t243 = t128 * t128;
    t95 = ((Vehicle_Left_Tire_tire_road_interaction_v_rel / (t132 == 0.0 ?
             1.0E-16 : t132) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
             1.0E-16 : t128)) * 200000.01 -
           ((Vehicle_Left_Tire_tire_road_interaction_v_rel / (t148 == 0.0 ?
              1.0E-16 : t148) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
              1.0E-16 : t128)) * (-Vehicle_Left_Tire_tire_road_interaction_v_rel
             / (t128 == 0.0 ? 1.0E-16 : t128)) +
            (Vehicle_Left_Tire_tire_road_interaction_v_rel / (t243 == 0.0 ?
              1.0E-16 : t243) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
              1.0E-16 : t128)) * (-Vehicle_Left_Tire_tire_road_interaction_v_rel
             / (t128 == 0.0 ? 1.0E-16 : t128)))) / 0.020000000000000004;
  } else {
    t95 = 0.0;
  }

  if (-Vehicle_Left_Tire_tire_road_interaction_v_rel / (intermediate_der156 ==
       0.0 ? 1.0E-16 : intermediate_der156) <= -100000.005) {
    intermediate_der37 = 0.0;
  } else if (-Vehicle_Left_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <
             -99999.995) {
    intermediate_der37 = ((0.3 / (t128 == 0.0 ? 1.0E-16 : t128) * 200000.01 +
      -Vehicle_Left_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ? 1.0E-16 :
      t128) * (0.3 / (t128 == 0.0 ? 1.0E-16 : t128))) +
                          -Vehicle_Left_Tire_tire_road_interaction_v_rel / (t128
      == 0.0 ? 1.0E-16 : t128) * (0.3 / (t128 == 0.0 ? 1.0E-16 : t128))) /
      0.020000000000000004;
  } else if (-Vehicle_Left_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <=
             99999.995) {
    intermediate_der37 = 0.3 / (t128 == 0.0 ? 1.0E-16 : t128);
  } else if (-Vehicle_Left_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <
             100000.005) {
    intermediate_der37 = (0.3 / (t128 == 0.0 ? 1.0E-16 : t128) * 200000.01 -
                          (-Vehicle_Left_Tire_tire_road_interaction_v_rel /
      (t128 == 0.0 ? 1.0E-16 : t128) * (0.3 / (t128 == 0.0 ? 1.0E-16 : t128)) +
      -Vehicle_Left_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ? 1.0E-16 :
      t128) * (0.3 / (t128 == 0.0 ? 1.0E-16 : t128)))) / 0.020000000000000004;
  } else {
    intermediate_der37 = 0.0;
  }

  t83 = t119 * t119 * zc_int10 * zc_int10 + 1.0;
  t243 = (t119 * zc_int10 - (t119 * zc_int10 - atan(t119 * zc_int10)) * t125) *
    (t119 * zc_int10 - (t119 * zc_int10 - atan(t119 * zc_int10)) * t125) + 1.0;
  Vehicle_Left_Tire_tire_road_interaction_v_rel = (intermediate_der142 * t8 *
    1.0351048413332149 + Electrical_Generic_Battery_y1 * t7 * 1.0351048413332149)
    * sin(atan(t119 * zc_int10 - (t119 * zc_int10 - atan(t119 * zc_int10)) *
               t125) * 1.65) + (intermediate_der32 * t119 - ((t119 * zc_int10 -
    atan(t119 * zc_int10)) * t87 + (intermediate_der32 * t119 - 1.0 / (t83 ==
    0.0 ? 1.0E-16 : t83) * intermediate_der32 * t119) * t125)) * (1.0 / (t243 ==
    0.0 ? 1.0E-16 : t243)) * cos(atan(t119 * zc_int10 - (t119 * zc_int10 - atan
    (t119 * zc_int10)) * t125) * 1.65) * t8 * t7 * 1.7079229881998046;
  intermediate_der139 = (182.16666666666666 * zc_int10 - (182.16666666666666 *
    zc_int10 - 1.0 / (t83 == 0.0 ? 1.0E-16 : t83) * 182.16666666666666 *
    zc_int10) * t125) * (1.0 / (t243 == 0.0 ? 1.0E-16 : t243)) * cos(atan(t119 *
    zc_int10 - (t119 * zc_int10 - atan(t119 * zc_int10)) * t125) * 1.65) * t8 *
    t7 * 1.7079229881998046;
  if (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intermediate_der156 ==
       0.0 ? 1.0E-16 : intermediate_der156) <= -100000.005) {
    t119 = 0.0;
  } else if (-Vehicle_Right_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <
             -99999.995) {
    t119 = ((0.3 / (t128 == 0.0 ? 1.0E-16 : t128) * 200000.01 +
             -Vehicle_Right_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ?
              1.0E-16 : t128) * (0.3 / (t128 == 0.0 ? 1.0E-16 : t128))) +
            -Vehicle_Right_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ?
             1.0E-16 : t128) * (0.3 / (t128 == 0.0 ? 1.0E-16 : t128))) /
      0.020000000000000004;
  } else if (-Vehicle_Right_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <=
             99999.995) {
    t119 = 0.3 / (t128 == 0.0 ? 1.0E-16 : t128);
  } else if (-Vehicle_Right_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <
             100000.005) {
    t119 = (0.3 / (t128 == 0.0 ? 1.0E-16 : t128) * 200000.01 -
            (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ?
              1.0E-16 : t128) * (0.3 / (t128 == 0.0 ? 1.0E-16 : t128)) +
             -Vehicle_Right_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ?
              1.0E-16 : t128) * (0.3 / (t128 == 0.0 ? 1.0E-16 : t128)))) /
      0.020000000000000004;
  } else {
    t119 = 0.0;
  }

  if (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intermediate_der156 ==
       0.0 ? 1.0E-16 : intermediate_der156) <= -100000.005) {
    t243 = 0.0;
  } else if (-Vehicle_Right_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <
             -99999.995) {
    t132 = t128 * t128;
    t148 = t128 * t128;
    t243 = t128 * t128;
    t243 = (((Vehicle_Right_Tire_tire_road_interaction_v_rel / (t132 == 0.0 ?
               1.0E-16 : t132) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
               1.0E-16 : t128)) * 200000.01 +
             (Vehicle_Right_Tire_tire_road_interaction_v_rel / (t148 == 0.0 ?
               1.0E-16 : t148) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
               1.0E-16 : t128)) *
             (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ?
               1.0E-16 : t128))) +
            (Vehicle_Right_Tire_tire_road_interaction_v_rel / (t243 == 0.0 ?
              1.0E-16 : t243) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
              1.0E-16 : t128)) *
            (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ?
              1.0E-16 : t128))) / 0.020000000000000004;
  } else if (-Vehicle_Right_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <=
             99999.995) {
    t243 = t128 * t128;
    t243 = Vehicle_Right_Tire_tire_road_interaction_v_rel / (t243 == 0.0 ?
      1.0E-16 : t243) * intermediate_der145 + -1.0 / (t128 == 0.0 ? 1.0E-16 :
      t128);
  } else if (-Vehicle_Right_Tire_tire_road_interaction_v_rel /
             (intermediate_der156 == 0.0 ? 1.0E-16 : intermediate_der156) <
             100000.005) {
    t132 = t128 * t128;
    t243 = t128 * t128;
    t148 = t128 * t128;
    t243 = ((Vehicle_Right_Tire_tire_road_interaction_v_rel / (t132 == 0.0 ?
              1.0E-16 : t132) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
              1.0E-16 : t128)) * 200000.01 -
            ((Vehicle_Right_Tire_tire_road_interaction_v_rel / (t243 == 0.0 ?
               1.0E-16 : t243) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
               1.0E-16 : t128)) *
             (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ?
               1.0E-16 : t128)) +
             (Vehicle_Right_Tire_tire_road_interaction_v_rel / (t148 == 0.0 ?
               1.0E-16 : t148) * intermediate_der145 + -1.0 / (t128 == 0.0 ?
               1.0E-16 : t128)) *
             (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (t128 == 0.0 ?
               1.0E-16 : t128)))) / 0.020000000000000004;
  } else {
    t243 = 0.0;
  }

  intermediate_der145 = intrm_sf_mf_20 * intrm_sf_mf_20 * zc_int10 * zc_int10 +
    1.0;
  t83 = (intrm_sf_mf_20 * zc_int10 - (intrm_sf_mf_20 * zc_int10 - atan
          (intrm_sf_mf_20 * zc_int10)) * t125) * (intrm_sf_mf_20 * zc_int10 -
    (intrm_sf_mf_20 * zc_int10 - atan(intrm_sf_mf_20 * zc_int10)) * t125) + 1.0;
  Vehicle_Right_Tire_tire_road_interaction_v_rel = (182.16666666666666 *
    zc_int10 - (182.16666666666666 * zc_int10 - 1.0 / (intermediate_der145 ==
    0.0 ? 1.0E-16 : intermediate_der145) * 182.16666666666666 * zc_int10) * t125)
    * (1.0 / (t83 == 0.0 ? 1.0E-16 : t83)) * cos(atan(intrm_sf_mf_20 * zc_int10
    - (intrm_sf_mf_20 * zc_int10 - atan(intrm_sf_mf_20 * zc_int10)) * t125) *
    1.65) * t8 * t7 * 1.7079229881998046;
  intermediate_der156 = (intermediate_der142 * t8 * 1.0351048413332149 +
    Electrical_Generic_Battery_y1 * t7 * 1.0351048413332149) * sin(atan
    (intrm_sf_mf_20 * zc_int10 - (intrm_sf_mf_20 * zc_int10 - atan
    (intrm_sf_mf_20 * zc_int10)) * t125) * 1.65) + (intermediate_der32 *
    intrm_sf_mf_20 - ((intrm_sf_mf_20 * zc_int10 - atan(intrm_sf_mf_20 *
    zc_int10)) * t87 + (intermediate_der32 * intrm_sf_mf_20 - 1.0 /
                        (intermediate_der145 == 0.0 ? 1.0E-16 :
    intermediate_der145) * intermediate_der32 * intrm_sf_mf_20) * t125)) * (1.0 /
    (t83 == 0.0 ? 1.0E-16 : t83)) * cos(atan(intrm_sf_mf_20 * zc_int10 -
    (intrm_sf_mf_20 * zc_int10 - atan(intrm_sf_mf_20 * zc_int10)) * t125) * 1.65)
    * t8 * t7 * 1.7079229881998046;
  if (t321->mX.mX[1ULL] != t321->mX.mX[1ULL]) {
    t83 = t321->mX.mX[1ULL];
  } else if (t321->mX.mX[1ULL] > 0.0) {
    t83 = 1.0;
  } else {
    t83 = t321->mX.mX[1ULL] < 0.0 ? -1.0 : 0.0;
  }

  t39[0ULL] = t83 * t321->mX.mX[19ULL];
  t18[0] = 13ULL;
  t19[0] = 1ULL;
  tlu2_linear_nearest_prelookup(&t0.mField0[0ULL], &t0.mField1[0ULL],
    &t0.mField2[0ULL], ((const _NeDynamicSystem*)(LC))->mField1, &t39[0ULL],
    &t18[0ULL], &t19[0ULL]);
  if (t321->mX.mX[5ULL] != t321->mX.mX[5ULL]) {
    t83 = t321->mX.mX[5ULL];
  } else if (t321->mX.mX[5ULL] > 0.0) {
    t83 = 1.0;
  } else {
    t83 = t321->mX.mX[5ULL] < 0.0 ? -1.0 : 0.0;
  }

  t39[0ULL] = t83 * t321->mX.mX[26ULL];
  t21[0] = 17ULL;
  tlu2_linear_nearest_prelookup(&t1.mField0[0ULL], &t1.mField1[0ULL],
    &t1.mField2[0ULL], ((const _NeDynamicSystem*)(LC))->mField3, &t39[0ULL],
    &t21[0ULL], &t19[0ULL]);
  intermediate_der145 = t12 * t12;
  out->mDXF.mX[0ULL] = -(-t121 / (intermediate_der145 == 0.0 ? 1.0E-16 :
    intermediate_der145) * -0.00071428571428571439 * 1000.0);
  if (t321->mM.mX[7ULL] != 0) {
    out->mDXF.mX[1ULL] = 0.0;
  } else {
    out->mDXF.mX[1ULL] = t321->mM.mX[8ULL] != 0 ? 0.0 : -1.0;
  }

  if (t321->mM.mX[9ULL] != 0) {
    out->mDXF.mX[5ULL] = 0.0;
  } else {
    out->mDXF.mX[5ULL] = t321->mM.mX[10ULL] != 0 ? 0.0 : -1.0;
  }

  t132 = t12 * t12;
  out->mDXF.mX[11ULL] = -(-t121 / (t132 == 0.0 ? 1.0E-16 : t132) *
    1.0005102040816327 * 1000.0);
  t132 = t16 * t16;
  out->mDXF.mX[12ULL] = -(-intrm_sf_mf_7 / (t132 == 0.0 ? 1.0E-16 : t132) *
    1000.0);
  t132 = t12 * t12;
  t32[2ULL] = -(-t121 / (t132 == 0.0 ? 1.0E-16 : t132) * 0.0071428571428571435 *
                1000.0);
  t34[0ULL] = -(t321->mX.mX[20ULL] * 0.001 / (t12 == 0.0 ? 1.0E-16 : t12) *
                1000.0);
  zc_int10 = -((t321->mX.mX[19ULL] * 0.001 + t321->mX.mX[20ULL] *
                0.00023271056693257701) / (t12 == 0.0 ? 1.0E-16 : t12) * 1000.0);
  if (t321->mX.mX[21ULL] >= 0.0) {
    t36[1ULL] = -3.9788735772973834E-6;
  } else {
    t36[1ULL] = 0.0;
  }

  t132 = t12 * t12;
  t148 = -(-t121 / (t132 == 0.0 ? 1.0E-16 : t132) * 0.01 * 1000.0);
  t132 = t16 * t16;
  t12 = -(-intrm_sf_mf_7 / (t132 == 0.0 ? 1.0E-16 : t132) * -0.01 * 1000.0);
  if (t321->mM.mX[7ULL] != 0) {
    intrm_sf_mf_7 = -1.0;
  } else {
    intrm_sf_mf_7 = (real_T)(t321->mM.mX[8ULL] != 0);
  }

  t121 = -(t321->mX.mX[27ULL] * 0.001 / (t16 == 0.0 ? 1.0E-16 : t16) * 1000.0);
  t128 = -((t321->mX.mX[26ULL] * 0.001 + t321->mX.mX[27ULL] *
            0.00020713797715976657) / (t16 == 0.0 ? 1.0E-16 : t16) * 1000.0);
  if (t321->mM.mX[9ULL] != 0) {
    t16 = -1.0;
  } else {
    t16 = (real_T)(t321->mM.mX[10ULL] != 0);
  }

  out->mDXF.mX[2ULL] = -(-t321->mX.mX[18ULL] * (real_T)(t321->mX.mX[18ULL] < 0.0))
    / 8.2944E+10 * 0.0;
  out->mDXF.mX[3ULL] = -(t321->mX.mX[18ULL] * 0.0 + intermediate_der147);
  out->mDXF.mX[6ULL] = -intermediate_der80 / 1.000204081632653;
  out->mDXF.mX[8ULL] = t321->mX.mX[13ULL] * ((real_T)(t321->mX.mX[13ULL] >= 0.0)
    * 2.0 - 1.0) * 0.662688;
  out->mDXF.mX[9ULL] = -t95 / 10.0;
  out->mDXF.mX[10ULL] = -t243 / 10.0;
  t32[0ULL] = -(t321->mM.mX[6ULL] != 0 ? -1.0 : 0.0);
  t32[1ULL] = -(real_T)(t321->mX.mX[18ULL] < 0.0) / 288000.0;
  t32[3ULL] = -0.001;
  tlu2_1d_linear_nearest_value(&t39[0ULL], &t0.mField1[0ULL], &t0.mField2[0ULL],
    ((const _NeDynamicSystem*)(LC))->mField0, &t18[0ULL], &t19[0ULL]);
  if (t321->mX.mX[1ULL] != t321->mX.mX[1ULL]) {
    t8 = t321->mX.mX[1ULL];
  } else if (t321->mX.mX[1ULL] > 0.0) {
    t8 = 1.0;
  } else {
    t8 = t321->mX.mX[1ULL] < 0.0 ? -1.0 : 0.0;
  }

  t34[1ULL] = -(t39[0ULL] * t8);
  t34[2ULL] = -intermediate_der93 / 1.25;
  t34[3ULL] = intermediate_der93 / 2.25;
  t36[0ULL] = -(((0.41582213766815418 + t321->mX.mX[21ULL] *
                  -0.0015883235677662084) * t129 + t111 *
                 Electrical_Generic_Battery_xV1) * t321->mX.mX[38ULL]);
  t36[2ULL] = -intermediate_der76 / 1.000204081632653;
  t36[3ULL] = intermediate_der76;
  t36[4ULL] = -intermediate_der88 / 1.25;
  t36[5ULL] = intermediate_der88 / 2.25;
  tlu2_1d_linear_nearest_value(&t39[0ULL], &t1.mField1[0ULL], &t1.mField2[0ULL],
    ((const _NeDynamicSystem*)(LC))->mField2, &t21[0ULL], &t19[0ULL]);
  if (t321->mX.mX[5ULL] != t321->mX.mX[5ULL]) {
    t7 = t321->mX.mX[5ULL];
  } else if (t321->mX.mX[5ULL] > 0.0) {
    t7 = 1.0;
  } else {
    t7 = t321->mX.mX[5ULL] < 0.0 ? -1.0 : 0.0;
  }

  t44[0ULL] = -Vehicle_Left_Tire_tire_road_interaction_v_rel;
  t44[1ULL] = Vehicle_Left_Tire_tire_road_interaction_v_rel;
  t44[2ULL] = -intermediate_der156;
  t44[3ULL] = intermediate_der156;
  out->mDXF.mX[4ULL] = -t151;
  out->mDXF.mX[7ULL] = intermediate_der80;
  for (t54 = 0ULL; t54 < 4ULL; t54++) {
    out->mDXF.mX[t54 + 13ULL] = t32[t54];
  }

  for (t54 = 0ULL; t54 < 4ULL; t54++) {
    out->mDXF.mX[t54 + 17ULL] = t34[t54];
  }

  out->mDXF.mX[21ULL] = 1.0;
  out->mDXF.mX[22ULL] = zc_int10;
  for (t54 = 0ULL; t54 < 6ULL; t54++) {
    out->mDXF.mX[t54 + 23ULL] = t36[t54];
  }

  out->mDXF.mX[29ULL] = -intermediate_der92 / 1.25;
  out->mDXF.mX[30ULL] = intermediate_der92 / 2.25;
  out->mDXF.mX[31ULL] = t148;
  out->mDXF.mX[32ULL] = t12;
  out->mDXF.mX[33ULL] = intrm_sf_mf_7;
  out->mDXF.mX[34ULL] = t121;
  out->mDXF.mX[35ULL] = -(t39[0ULL] * t7);
  out->mDXF.mX[36ULL] = 1.0;
  out->mDXF.mX[37ULL] = t128;
  out->mDXF.mX[38ULL] = t16;
  out->mDXF.mX[39ULL] = 1.0;
  out->mDXF.mX[40ULL] = -(t111 * t129);
  out->mDXF.mX[41ULL] = 1.0;
  out->mDXF.mX[42ULL] = -intermediate_der78 / 1.000204081632653;
  out->mDXF.mX[43ULL] = intermediate_der78;
  out->mDXF.mX[44ULL] = -intermediate_der37 / 10.0;
  out->mDXF.mX[45ULL] = -t119 / 10.0;
  for (t54 = 0ULL; t54 < 4ULL; t54++) {
    out->mDXF.mX[t54 + 46ULL] = t44[t54];
  }

  out->mDXF.mX[50ULL] = -intermediate_der139;
  out->mDXF.mX[51ULL] = intermediate_der139;
  out->mDXF.mX[52ULL] = -Vehicle_Right_Tire_tire_road_interaction_v_rel;
  out->mDXF.mX[53ULL] = Vehicle_Right_Tire_tire_road_interaction_v_rel;
  (void)LC;
  (void)out;
  return 0;
}
