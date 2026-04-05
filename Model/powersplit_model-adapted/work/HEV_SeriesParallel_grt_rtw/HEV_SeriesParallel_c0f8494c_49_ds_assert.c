/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_assert.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_assert(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t13, NeDsMethodOutput *out)
{
  real_T Electrical_Generic_Battery_x;
  real_T Vehicle_Right_Tire_tire_road_interaction_v_rel;
  real_T intrm_sf_mf_0;
  real_T intrm_sf_mf_11;
  real_T intrm_sf_mf_13;
  real_T t5;
  (void)LC;
  Electrical_Generic_Battery_x = 0.75000000000000011;
  t5 = t13->mX.mX[13ULL] - t13->mX.mX[43ULL] * 0.3;
  Vehicle_Right_Tire_tire_road_interaction_v_rel = t13->mX.mX[13ULL] -
    t13->mX.mX[47ULL] * 0.3;
  if (fabs(t13->mX.mX[13ULL]) <= 0.095) {
    intrm_sf_mf_0 = 0.1;
  } else if (fabs(t13->mX.mX[13ULL]) < 0.10500000000000001) {
    intrm_sf_mf_13 = fabs(t13->mX.mX[13ULL]) * -0.19 + fabs(t13->mX.mX[13ULL]) *
      fabs(t13->mX.mX[13ULL]);
    intrm_sf_mf_0 = intrm_sf_mf_13 / 0.020000000000000004 + 0.55125;
  } else if (fabs(t13->mX.mX[13ULL]) <= 9.9999999995E+7) {
    intrm_sf_mf_0 = fabs(t13->mX.mX[13ULL]);
  } else if (fabs(t13->mX.mX[13ULL]) < 1.00000000005E+8) {
    intrm_sf_mf_11 = fabs(t13->mX.mX[13ULL]) * 2.0000000001E+8 - fabs(t13->
      mX.mX[13ULL]) * fabs(t13->mX.mX[13ULL]);
    intrm_sf_mf_0 = intrm_sf_mf_11 / 0.020000000000000004 -
      4.9999999994999987E+17;
  } else {
    intrm_sf_mf_0 = 1.0E+8;
  }

  intrm_sf_mf_11 = (t13->mX.mX[51ULL] < 0.0 ? 0.0 : t13->mX.mX[51ULL]) /
    0.95565749235474007;
  intrm_sf_mf_13 = intrm_sf_mf_11 * -21.3 / 1.0E+6 + 1.144;
  out->mASSERT.mX[0ULL] = (int32_T)(t13->mM.mX[11ULL] != 0);
  out->mASSERT.mX[1ULL] = 1;
  out->mASSERT.mX[2ULL] = (int32_T)(t13->mM.mX[12ULL] != 0);
  out->mASSERT.mX[3ULL] = (int32_T)(t13->mM.mX[2ULL] != 0);
  out->mASSERT.mX[4ULL] = (int32_T)(t13->mM.mX[3ULL] != 0);
  out->mASSERT.mX[5ULL] = (int32_T)(t13->mM.mX[4ULL] != 0);
  out->mASSERT.mX[6ULL] = (int32_T)(t13->mX.mX[3ULL] + 1.0E-6 >= 0.0);
  out->mASSERT.mX[7ULL] = (int32_T)(t13->mX.mX[3ULL] + 1.0E-6 >= 0.0);
  out->mASSERT.mX[8ULL] = 1;
  out->mASSERT.mX[9ULL] = 1;
  out->mASSERT.mX[10ULL] = 1;
  out->mASSERT.mX[11ULL] = 1;
  out->mASSERT.mX[12ULL] = (int32_T)(1.0 - (1.0 - t13->mX.mX[4ULL] / 288000.0) *
    (Electrical_Generic_Battery_x > 0.0 ? Electrical_Generic_Battery_x : 0.0) !=
    0.0);
  out->mASSERT.mX[13ULL] = 1;
  out->mASSERT.mX[14ULL] = 1;
  Electrical_Generic_Battery_x = intrm_sf_mf_11 * 0.069;
  out->mASSERT.mX[15ULL] = (int32_T)(Electrical_Generic_Battery_x / 1000.0 <
    663.67513503334737);
  out->mASSERT.mX[16ULL] = (int32_T)((!(Electrical_Generic_Battery_x / 1000.0 <
    663.67513503334737)) || (pmf_exp(Electrical_Generic_Battery_x / 1000.0) *
    intrm_sf_mf_13 * 1.65 != 0.0));
  out->mASSERT.mX[17ULL] = (int32_T)(intrm_sf_mf_0 != 0.0);
  out->mASSERT.mX[18ULL] = (int32_T)
    ((-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
       1.0E-16 : intrm_sf_mf_0) <= -100000.005) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[19ULL] = (int32_T)
    ((!(-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
        1.0E-16 : intrm_sf_mf_0) < -99999.995)) ||
     (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
       1.0E-16 : intrm_sf_mf_0) <= -100000.005) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[20ULL] = 1;
  out->mASSERT.mX[21ULL] = (int32_T)
    ((-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
       1.0E-16 : intrm_sf_mf_0) < -99999.995) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[22ULL] = (int32_T)
    ((!(-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
        1.0E-16 : intrm_sf_mf_0) <= 99999.995)) ||
     (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
       1.0E-16 : intrm_sf_mf_0) < -99999.995) ||
     (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
       1.0E-16 : intrm_sf_mf_0) <= -100000.005) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[23ULL] = (int32_T)
    ((-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
       1.0E-16 : intrm_sf_mf_0) <= 99999.995) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[24ULL] = (int32_T)
    ((!(-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
        1.0E-16 : intrm_sf_mf_0) < 100000.005)) ||
     (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
       1.0E-16 : intrm_sf_mf_0) < -99999.995) ||
     (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
       1.0E-16 : intrm_sf_mf_0) <= -100000.005) ||
     (-Vehicle_Right_Tire_tire_road_interaction_v_rel / (intrm_sf_mf_0 == 0.0 ?
       1.0E-16 : intrm_sf_mf_0) <= 99999.995) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[25ULL] = 1;
  out->mASSERT.mX[26ULL] = (int32_T)(Electrical_Generic_Battery_x / 1000.0 <
    663.67513503334737);
  out->mASSERT.mX[27ULL] = (int32_T)((!(Electrical_Generic_Battery_x / 1000.0 <
    663.67513503334737)) || (pmf_exp(Electrical_Generic_Battery_x / 1000.0) *
    intrm_sf_mf_13 * 1.65 != 0.0));
  out->mASSERT.mX[28ULL] = (int32_T)(intrm_sf_mf_0 != 0.0);
  out->mASSERT.mX[29ULL] = (int32_T)((-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) <= -100000.005) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[30ULL] = (int32_T)((!(-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) < -99999.995)) || (-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) <= -100000.005) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[31ULL] = 1;
  out->mASSERT.mX[32ULL] = (int32_T)((-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) < -99999.995) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[33ULL] = (int32_T)((!(-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) <= 99999.995)) || (-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) < -99999.995) || (-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) <= -100000.005) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[34ULL] = (int32_T)((-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) <= 99999.995) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[35ULL] = (int32_T)((!(-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) < 100000.005)) || (-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) < -99999.995) || (-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) <= -100000.005) || (-t5 / (intrm_sf_mf_0 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_0) <= 99999.995) || (intrm_sf_mf_0 != 0.0));
  out->mASSERT.mX[36ULL] = 1;
  out->mASSERT.mX[37ULL] = 1;
  out->mASSERT.mX[38ULL] = (int32_T)(((t13->mX.mX[0ULL] *
    -0.00071428571428571439 + t13->mX.mX[17ULL] * 1.0005102040816327) +
    t13->mX.mX[18ULL] * 0.0071428571428571435) + t13->mX.mX[24ULL] * 0.01 != 0.0);
  out->mASSERT.mX[39ULL] = (int32_T)(t13->mX.mX[24ULL] * -0.01 + t13->mX.mX
    [17ULL] != 0.0);
  (void)LC;
  (void)out;
  return 0;
}
