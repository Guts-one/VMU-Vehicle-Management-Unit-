/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_log.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_log(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t27, NeDsMethodOutput *out)
{
  real_T Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  real_T Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  real_T Electrical_Generator_System_Motor_and_Drive_i;
  real_T Electrical_Generator_System_Motor_and_Drive_t;
  real_T Electrical_Generator_System_Power_Sensor_PS_Product1_O;
  real_T Electrical_Generic_Battery_x;
  real_T Electrical_Motor_System_Motor_and_Drive_t;
  real_T Electrical_Motor_System_Power_Sensor_PS_Product1_O;
  real_T Engine_Damper_t;
  real_T Engine_Sensor_Ideal_Torque_Sensor_T;
  real_T Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t;
  real_T Vehicle_Final_Drive_t_in;
  real_T Vehicle_Rear_Differential_base_gear_damperB_w;
  real_T Vehicle_Rear_Differential_sun_planet_left_P_w;
  real_T Vehicle_Rear_Differential_sun_planet_left_t_C;
  real_T Vehicle_Rotational_Damper_t;
  real_T Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t7;
  (void)LC;
  Electrical_DC_DC_Converter_Ideal_Transformer_i1 = (t27->mX.mX[0ULL] * 0.1 +
    t27->mX.mX[17ULL] * -0.071428571428571438) - t27->mX.mX[18ULL];
  Electrical_DC_DC_Converter_Ideal_Transformer_p1_v = t27->mX.mX[17ULL] *
    0.7142857142857143;
  out->mLOG.mX[14ULL] = ((t27->mX.mX[19ULL] * -0.02001 + t27->mX.mX[21ULL] *
    0.02) - t27->mX.mX[22ULL]) + t27->mX.mX[20ULL];
  Electrical_Generator_System_Motor_and_Drive_i = ((t27->mX.mX[0ULL] *
    0.071428571428571438 + t27->mX.mX[17ULL] * -0.051020408163265314) +
    t27->mX.mX[18ULL] * -0.7142857142857143) - t27->mX.mX[24ULL];
  Electrical_Generator_System_Motor_and_Drive_t = t27->mX.mX[19ULL] * 1.0E-5 -
    t27->mX.mX[20ULL];
  out->mLOG.mX[31ULL] = ((t27->mX.mX[0ULL] * -0.00071428571428571439 +
    t27->mX.mX[17ULL] * 1.0005102040816327) + t27->mX.mX[18ULL] *
    0.0071428571428571435) + t27->mX.mX[24ULL] * 0.01;
  Electrical_Generator_System_Power_Sensor_PS_Product1_O = t27->mX.mX[17ULL] *
    Electrical_Generator_System_Motor_and_Drive_i * 0.001;
  out->mLOG.mX[63ULL] = t27->mX.mX[3ULL] + 1.0E-6;
  Electrical_Generic_Battery_x = 0.75000000000000011;
  t7 = Electrical_Generic_Battery_x > 0.0 ? Electrical_Generic_Battery_x : 0.0;
  Electrical_Generic_Battery_x = t27->mX.mX[4ULL] / 288000.0;
  t11 = 1.0 - (1.0 - Electrical_Generic_Battery_x) * t7;
  out->mLOG.mX[72ULL] = Electrical_Generic_Battery_x * 250.0 / (t11 == 0.0 ?
    1.0E-16 : t11);
  out->mLOG.mX[73ULL] = 0.24999999999999994;
  out->mLOG.mX[75ULL] = t27->mX.mX[18ULL] * t27->mX.mX[18ULL] * 0.001 * 0.001;
  out->mLOG.mX[80ULL] = t27->mX.mX[0ULL] * -0.1 + t27->mX.mX[17ULL] *
    0.071428571428571438;
  t12 = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    Electrical_DC_DC_Converter_Ideal_Transformer_p1_v * 0.001;
  t13 = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[111ULL] = ((((t27->mX.mX[26ULL] * -0.00011 - t27->mX.mX[28ULL]) +
    t27->mX.mX[29ULL] * -0.76923076923076916) + t27->mX.mX[30ULL] *
    -0.76923076923076916) + t27->mU.mX[3ULL] * 0.76923076923076916) + t27->
    mX.mX[27ULL];
  Electrical_Motor_System_Motor_and_Drive_t = t27->mX.mX[26ULL] * 1.0E-5 -
    t27->mX.mX[27ULL];
  out->mLOG.mX[128ULL] = t27->mX.mX[24ULL] * -0.01 + t27->mX.mX[17ULL];
  Electrical_Motor_System_Power_Sensor_PS_Product1_O = t27->mX.mX[17ULL] *
    t27->mX.mX[24ULL] * 0.001;
  Engine_Damper_t = t27->mX.mX[21ULL] * 0.2079;
  out->mLOG.mX[162ULL] = Engine_Damper_t * Engine_Damper_t * 4.8100048100048109;
  out->mLOG.mX[165ULL] = (((t27->mX.mX[19ULL] * 0.02 + t27->mX.mX[21ULL] *
    -0.2279) - t27->mX.mX[34ULL]) - t27->mX.mX[35ULL]) + t27->mX.mX[33ULL];
  if (t27->mX.mX[21ULL] > 52.359877559829883) {
    out->mLOG.mX[174ULL] = tanh((t27->mX.mX[21ULL] - 52.359877559829883) * 4.0 /
      10.471975511965976);
  } else {
    out->mLOG.mX[174ULL] = 0.0;
  }

  out->mLOG.mX[175ULL] = (t27->mX.mX[21ULL] * 0.41582213766815418 + t27->mX.mX
    [21ULL] * t27->mX.mX[21ULL] * -0.00079416178388310419) + 217.7239621497128;
  Engine_Sensor_Ideal_Torque_Sensor_T = ((t27->mX.mX[19ULL] * -0.02 + t27->
    mX.mX[21ULL] * 0.02) + t27->mX.mX[34ULL]) + t27->mX.mX[35ULL];
  t11 = (((tanh(-t27->mX.mX[40ULL] * (t27->mX.mX[8ULL] - t27->mX.mX[21ULL]) *
                4.0 / 1.0E-6 * 0.001) * 0.03960000000000008 + 1.96) -
          0.96039999999999992) - 1.0) * (-t27->mX.mX[40ULL] / 1.96);
  out->mLOG.mX[204ULL] = -t27->mX.mX[21ULL] + t27->mX.mX[8ULL];
  out->mLOG.mX[206ULL] = (t27->mX.mX[8ULL] - t27->mX.mX[21ULL]) * t11;
  t11 = (((tanh(t27->mX.mX[22ULL] * (t27->mX.mX[19ULL] - t27->mX.mX[21ULL]) *
                4.0 / 1.0E-6 * 0.001) * 0.078400000000000025 + 1.92) - 0.9216) -
         1.0) * (t27->mX.mX[22ULL] / 1.92);
  Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t = t27->mX.mX[19ULL]
    * 0.02 + t27->mX.mX[21ULL] * -0.02;
  out->mLOG.mX[217ULL] =
    Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t *
    Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t * 50.0;
  out->mLOG.mX[218ULL] = (t27->mX.mX[19ULL] - t27->mX.mX[21ULL]) * t11;
  t11 = (t27->mX.mX[19ULL] * -0.02 + t27->mX.mX[21ULL] * 0.02) - t27->mX.mX
    [22ULL];
  Vehicle_Final_Drive_t_in = (t27->mX.mX[29ULL] * 0.76923076923076916 +
    t27->mX.mX[30ULL] * 0.76923076923076916) + t27->mU.mX[3ULL] *
    -0.76923076923076916;
  out->mLOG.mX[265ULL] = (-t27->mX.mX[41ULL] + t27->mX.mX[42ULL] * -0.3) +
    t27->mX.mX[30ULL] * 0.5;
  out->mLOG.mX[269ULL] = (t27->mX.mX[30ULL] * 0.5 - t27->mX.mX[45ULL]) +
    t27->mX.mX[46ULL] * -0.3;
  out->mLOG.mX[287ULL] = -t27->mX.mX[54ULL] - t27->mX.mX[55ULL];
  out->mLOG.mX[289ULL] = -t27->mX.mX[42ULL] * (t27->mX.mX[13ULL] - t27->mX.mX
    [43ULL] * 0.3);
  Vehicle_Rear_Differential_base_gear_damperB_w = t27->mX.mX[26ULL] *
    0.76923076923076916;
  Vehicle_Rear_Differential_sun_planet_left_P_w = t27->mX.mX[26ULL] *
    -0.76923076923076916 + t27->mX.mX[47ULL];
  Vehicle_Rear_Differential_sun_planet_left_t_C = t27->mX.mX[30ULL] * 0.5;
  out->mLOG.mX[326ULL] = t27->mX.mX[26ULL] * -0.76923076923076916 + t27->mX.mX
    [43ULL];
  out->mLOG.mX[345ULL] = -t27->mX.mX[46ULL] * (t27->mX.mX[13ULL] - t27->mX.mX
    [47ULL] * 0.3);
  Vehicle_Rotational_Damper_t = t27->mX.mX[26ULL] * 0.0001;
  out->mLOG.mX[353ULL] = Vehicle_Rotational_Damper_t *
    Vehicle_Rotational_Damper_t * 10000.0;
  Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T = ((t27->mX.mX[26ULL] *
    0.0001 + t27->mX.mX[29ULL] * 0.76923076923076916) + t27->mX.mX[30ULL] *
    0.76923076923076916) + t27->mU.mX[3ULL] * -0.76923076923076916;
  out->mLOG.mX[369ULL] = t27->mU.mX[3ULL];
  out->mLOG.mX[370ULL] = -t27->mU.mX[3ULL];
  out->mLOG.mX[371ULL] = -(t27->mX.mX[26ULL] * 0.76923076923076916);
  out->mLOG.mX[374ULL] = (t27->mDP_R.mX[1ULL] * 1.35 - t27->mX.mX[55ULL] * 0.5) /
    2.7 / 2.0;
  out->mLOG.mX[380ULL] = ((real_T)(t27->mX.mX[13ULL] >= 0.0) * 2.0 - 1.0) *
    t27->mX.mX[13ULL] * t27->mX.mX[13ULL] * 0.331344 * t27->mX.mX[13ULL];
  out->mLOG.mX[0ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[1ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    -0.7142857142857143;
  out->mLOG.mX[2ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[3ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[4ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[5ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v * 1.4;
  out->mLOG.mX[6ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[7ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[8ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[9ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[10ULL] = t27->mU.mX[0ULL];
  out->mLOG.mX[11ULL] = t27->mU.mX[0ULL];
  out->mLOG.mX[12ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[13ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[15ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[16ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[17ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[18ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[19ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[20ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[21ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[22ULL] = t27->mU.mX[0ULL];
  out->mLOG.mX[23ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[24ULL] = Electrical_Generator_System_Motor_and_Drive_i;
  out->mLOG.mX[25ULL] = ((Electrical_Generator_System_Motor_and_Drive_i *
    Electrical_Generator_System_Motor_and_Drive_i * 1.0E-5 + t27->mX.mX[19ULL] *
    t27->mX.mX[19ULL] * 1.0E-8) + t27->mX.mX[20ULL] * t27->mX.mX[20ULL] *
    0.00011635528346628851) * 1000.0;
  out->mLOG.mX[26ULL] = Electrical_Generator_System_Motor_and_Drive_t;
  out->mLOG.mX[27ULL] = t27->mX.mX[25ULL];
  out->mLOG.mX[28ULL] = t27->mX.mX[25ULL];
  out->mLOG.mX[29ULL] = t27->mX.mX[20ULL];
  out->mLOG.mX[30ULL] = t27->mX.mX[1ULL];
  out->mLOG.mX[32ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[33ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[34ULL] = Electrical_Generator_System_Motor_and_Drive_i;
  out->mLOG.mX[35ULL] = Electrical_Generator_System_Motor_and_Drive_i;
  out->mLOG.mX[36ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[37ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[38ULL] = Electrical_Generator_System_Motor_and_Drive_i;
  out->mLOG.mX[39ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[40ULL] = Electrical_Generator_System_Power_Sensor_PS_Product1_O *
    1000.0;
  out->mLOG.mX[41ULL] = Electrical_Generator_System_Power_Sensor_PS_Product1_O *
    1000.0;
  out->mLOG.mX[42ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[43ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[44ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[45ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[46ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[47ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[48ULL] = t27->mX.mX[2ULL];
  out->mLOG.mX[49ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[50ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[51ULL] = t27->mX.mX[2ULL] * 57.295779513082323;
  out->mLOG.mX[52ULL] = t27->mX.mX[2ULL];
  out->mLOG.mX[53ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[54ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[55ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[56ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[57ULL] = -Electrical_Generator_System_Motor_and_Drive_t;
  out->mLOG.mX[58ULL] = -Electrical_Generator_System_Motor_and_Drive_t;
  out->mLOG.mX[59ULL] = -Electrical_Generator_System_Motor_and_Drive_t;
  out->mLOG.mX[60ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[61ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[62ULL] = t27->mX.mX[3ULL];
  out->mLOG.mX[64ULL] = t27->mX.mX[18ULL];
  out->mLOG.mX[65ULL] = 288000.0;
  out->mLOG.mX[66ULL] = 0.5;
  out->mLOG.mX[67ULL] = 200.0;
  out->mLOG.mX[68ULL] = 0.8;
  out->mLOG.mX[69ULL] = t7;
  out->mLOG.mX[70ULL] = t27->mX.mX[4ULL] * 0.00027777777777777778;
  out->mLOG.mX[71ULL] = Electrical_Generic_Battery_x;
  out->mLOG.mX[74ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[76ULL] = t27->mX.mX[4ULL];
  out->mLOG.mX[77ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[78ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[79ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[81ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[82ULL] = t27->mX.mX[0ULL];
  out->mLOG.mX[83ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[84ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[85ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[86ULL] = t12 * 1000.0;
  out->mLOG.mX[87ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[88ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[89ULL] = t13;
  out->mLOG.mX[90ULL] = t12 * 1000.0;
  out->mLOG.mX[91ULL] = t13;
  out->mLOG.mX[92ULL] = t13 * 0.24691;
  out->mLOG.mX[93ULL] = t13 * 0.24691;
  out->mLOG.mX[94ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[95ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[96ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    -0.00027777777777777778;
  out->mLOG.mX[97ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    -0.00027777777777777778;
  out->mLOG.mX[98ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[99ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[100ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mLOG.mX[101ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[102ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[103ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[104ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mLOG.mX[105ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[106ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[107ULL] = t27->mU.mX[1ULL];
  out->mLOG.mX[108ULL] = t27->mU.mX[1ULL];
  out->mLOG.mX[109ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[110ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[112ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[113ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[114ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[115ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[116ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[117ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[118ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[119ULL] = t27->mU.mX[1ULL];
  out->mLOG.mX[120ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[121ULL] = t27->mX.mX[24ULL];
  out->mLOG.mX[122ULL] = ((t27->mX.mX[24ULL] * t27->mX.mX[24ULL] * 1.0E-5 +
    t27->mX.mX[26ULL] * t27->mX.mX[26ULL] * 1.0E-8) + t27->mX.mX[27ULL] *
    t27->mX.mX[27ULL] * 0.00010356898857988329) * 1000.0;
  out->mLOG.mX[123ULL] = Electrical_Motor_System_Motor_and_Drive_t;
  out->mLOG.mX[124ULL] = t27->mX.mX[32ULL];
  out->mLOG.mX[125ULL] = t27->mX.mX[32ULL];
  out->mLOG.mX[126ULL] = t27->mX.mX[27ULL];
  out->mLOG.mX[127ULL] = t27->mX.mX[5ULL];
  out->mLOG.mX[129ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[130ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[131ULL] = t27->mX.mX[24ULL];
  out->mLOG.mX[132ULL] = t27->mX.mX[24ULL];
  out->mLOG.mX[133ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[134ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[135ULL] = t27->mX.mX[24ULL];
  out->mLOG.mX[136ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[137ULL] = Electrical_Motor_System_Power_Sensor_PS_Product1_O *
    1000.0;
  out->mLOG.mX[138ULL] = Electrical_Motor_System_Power_Sensor_PS_Product1_O *
    1000.0;
  out->mLOG.mX[139ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[140ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[141ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[142ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[143ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[144ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[145ULL] = t27->mX.mX[6ULL];
  out->mLOG.mX[146ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[147ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[148ULL] = t27->mX.mX[6ULL] * 57.295779513082323;
  out->mLOG.mX[149ULL] = t27->mX.mX[6ULL];
  out->mLOG.mX[150ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[151ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[152ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[153ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[154ULL] = -Electrical_Motor_System_Motor_and_Drive_t;
  out->mLOG.mX[155ULL] = -Electrical_Motor_System_Motor_and_Drive_t;
  out->mLOG.mX[156ULL] = -Electrical_Motor_System_Motor_and_Drive_t;
  out->mLOG.mX[157ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[158ULL] = t27->mX.mX[17ULL];
  out->mLOG.mX[159ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[160ULL] = Engine_Damper_t;
  out->mLOG.mX[161ULL] = Engine_Damper_t * 4.81000481000481;
  out->mLOG.mX[163ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[164ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[166ULL] = t27->mX.mX[21ULL] * 9.5492965855137211;
  out->mLOG.mX[167ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[168ULL] = t27->mX.mX[37ULL];
  out->mLOG.mX[169ULL] = t27->mX.mX[21ULL] * t27->mX.mX[33ULL] * 0.001 * 1000.0;
  out->mLOG.mX[170ULL] = t27->mU.mX[2ULL];
  out->mLOG.mX[171ULL] = t27->mX.mX[38ULL];
  out->mLOG.mX[172ULL] = t27->mX.mX[38ULL];
  out->mLOG.mX[173ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[176ULL] = t27->mX.mX[33ULL];
  out->mLOG.mX[177ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[178ULL] = t27->mX.mX[7ULL];
  out->mLOG.mX[179ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[180ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[181ULL] = t27->mX.mX[7ULL];
  out->mLOG.mX[182ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[183ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[184ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[185ULL] = Engine_Sensor_Ideal_Torque_Sensor_T;
  out->mLOG.mX[186ULL] = Engine_Sensor_Ideal_Torque_Sensor_T;
  out->mLOG.mX[187ULL] = Engine_Sensor_Ideal_Torque_Sensor_T;
  out->mLOG.mX[188ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[189ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[190ULL] = t27->mU.mX[2ULL];
  out->mLOG.mX[191ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[192ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[193ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[194ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[195ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[196ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[197ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[198ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[199ULL] = t27->mX.mX[8ULL];
  out->mLOG.mX[200ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[201ULL] = -t27->mX.mX[40ULL];
  out->mLOG.mX[202ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[203ULL] = t27->mX.mX[8ULL];
  out->mLOG.mX[205ULL] = 0.0;
  out->mLOG.mX[207ULL] = t27->mX.mX[34ULL];
  out->mLOG.mX[208ULL] = t27->mX.mX[28ULL];
  out->mLOG.mX[209ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[210ULL] = t27->mX.mX[8ULL];
  out->mLOG.mX[211ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[212ULL] = t27->mX.mX[22ULL];
  out->mLOG.mX[213ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[214ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[215ULL] =
    Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t;
  out->mLOG.mX[216ULL] =
    Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t * 50.0;
  out->mLOG.mX[219ULL] = t27->mX.mX[35ULL];
  out->mLOG.mX[220ULL] = t27->mX.mX[40ULL];
  out->mLOG.mX[221ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[222ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[223ULL] = t27->mX.mX[9ULL];
  out->mLOG.mX[224ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[225ULL] = -t27->mX.mX[21ULL];
  out->mLOG.mX[226ULL] = t27->mX.mX[9ULL];
  out->mLOG.mX[227ULL] = -t27->mX.mX[21ULL];
  out->mLOG.mX[228ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[229ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[230ULL] = -Engine_Sensor_Ideal_Torque_Sensor_T;
  out->mLOG.mX[231ULL] = -Engine_Sensor_Ideal_Torque_Sensor_T;
  out->mLOG.mX[232ULL] = -Engine_Sensor_Ideal_Torque_Sensor_T;
  out->mLOG.mX[233ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[234ULL] = t27->mX.mX[21ULL];
  out->mLOG.mX[235ULL] = t27->mX.mX[10ULL];
  out->mLOG.mX[236ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[237ULL] = -t27->mX.mX[26ULL];
  out->mLOG.mX[238ULL] = t27->mX.mX[10ULL];
  out->mLOG.mX[239ULL] = -t27->mX.mX[26ULL];
  out->mLOG.mX[240ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[241ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[242ULL] = -t27->mX.mX[28ULL];
  out->mLOG.mX[243ULL] = -t27->mX.mX[28ULL];
  out->mLOG.mX[244ULL] = -t27->mX.mX[28ULL];
  out->mLOG.mX[245ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[246ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[247ULL] = t27->mX.mX[11ULL];
  out->mLOG.mX[248ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[249ULL] = -t27->mX.mX[19ULL];
  out->mLOG.mX[250ULL] = t27->mX.mX[11ULL];
  out->mLOG.mX[251ULL] = -t27->mX.mX[19ULL];
  out->mLOG.mX[252ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[253ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[254ULL] = t11;
  out->mLOG.mX[255ULL] = t11;
  out->mLOG.mX[256ULL] = t11;
  out->mLOG.mX[257ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[258ULL] = t27->mX.mX[19ULL];
  out->mLOG.mX[259ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[260ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[261ULL] = Vehicle_Final_Drive_t_in;
  out->mLOG.mX[262ULL] = Vehicle_Final_Drive_t_in * -1.3;
  out->mLOG.mX[263ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[264ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[266ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[267ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[268ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[270ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[271ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[272ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[273ULL] = t27->mX.mX[29ULL];
  out->mLOG.mX[274ULL] = t27->mX.mX[49ULL];
  out->mLOG.mX[275ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[276ULL] = t27->mX.mX[13ULL];
  out->mLOG.mX[277ULL] = t27->mX.mX[51ULL];
  out->mLOG.mX[278ULL] = t27->mX.mX[52ULL];
  out->mLOG.mX[279ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[280ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[281ULL] = t27->mX.mX[41ULL];
  out->mLOG.mX[282ULL] = t27->mX.mX[12ULL] * 9.5492965855137211;
  out->mLOG.mX[283ULL] = t27->mX.mX[13ULL];
  out->mLOG.mX[284ULL] = t27->mX.mX[51ULL];
  out->mLOG.mX[285ULL] = t27->mX.mX[52ULL];
  out->mLOG.mX[286ULL] = t27->mX.mX[43ULL] * 0.3;
  out->mLOG.mX[288ULL] = t27->mX.mX[42ULL];
  out->mLOG.mX[290ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[291ULL] = t27->mX.mX[43ULL] * 0.3;
  out->mLOG.mX[292ULL] = -t27->mX.mX[42ULL];
  out->mLOG.mX[293ULL] = t27->mX.mX[42ULL] * 0.3;
  out->mLOG.mX[294ULL] = t27->mX.mX[52ULL];
  out->mLOG.mX[295ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[296ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[297ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[298ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[299ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[300ULL] = t27->mX.mX[30ULL];
  out->mLOG.mX[301ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[302ULL] = Vehicle_Rear_Differential_base_gear_damperB_w;
  out->mLOG.mX[303ULL] = 0.0;
  out->mLOG.mX[304ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[305ULL] = Vehicle_Rear_Differential_base_gear_damperB_w;
  out->mLOG.mX[306ULL] = 0.0;
  out->mLOG.mX[307ULL] = 0.0;
  out->mLOG.mX[308ULL] = -t27->mX.mX[30ULL];
  out->mLOG.mX[309ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[310ULL] = Vehicle_Rear_Differential_sun_planet_left_P_w;
  out->mLOG.mX[311ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[312ULL] = -Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mLOG.mX[313ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[314ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[315ULL] = Vehicle_Rear_Differential_sun_planet_left_P_w;
  out->mLOG.mX[316ULL] = 0.0;
  out->mLOG.mX[317ULL] = 0.0;
  out->mLOG.mX[318ULL] = Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mLOG.mX[319ULL] = Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mLOG.mX[320ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[321ULL] = Vehicle_Rear_Differential_sun_planet_left_P_w;
  out->mLOG.mX[322ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[323ULL] = -Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mLOG.mX[324ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[325ULL] = t27->mX.mX[43ULL];
  out->mLOG.mX[327ULL] = 0.0;
  out->mLOG.mX[328ULL] = 0.0;
  out->mLOG.mX[329ULL] = Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mLOG.mX[330ULL] = -Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mLOG.mX[331ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[332ULL] = t27->mX.mX[13ULL];
  out->mLOG.mX[333ULL] = t27->mX.mX[51ULL];
  out->mLOG.mX[334ULL] = t27->mX.mX[56ULL];
  out->mLOG.mX[335ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[336ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[337ULL] = t27->mX.mX[45ULL];
  out->mLOG.mX[338ULL] = t27->mX.mX[14ULL] * 9.5492965855137211;
  out->mLOG.mX[339ULL] = t27->mX.mX[13ULL];
  out->mLOG.mX[340ULL] = t27->mX.mX[51ULL];
  out->mLOG.mX[341ULL] = t27->mX.mX[56ULL];
  out->mLOG.mX[342ULL] = t27->mX.mX[47ULL] * 0.3;
  out->mLOG.mX[343ULL] = t27->mX.mX[54ULL];
  out->mLOG.mX[344ULL] = t27->mX.mX[46ULL];
  out->mLOG.mX[346ULL] = t27->mX.mX[47ULL];
  out->mLOG.mX[347ULL] = t27->mX.mX[47ULL] * 0.3;
  out->mLOG.mX[348ULL] = -t27->mX.mX[46ULL];
  out->mLOG.mX[349ULL] = t27->mX.mX[46ULL] * 0.3;
  out->mLOG.mX[350ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[351ULL] = Vehicle_Rotational_Damper_t;
  out->mLOG.mX[352ULL] = Vehicle_Rotational_Damper_t * 10000.0;
  out->mLOG.mX[354ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[355ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[356ULL] = t27->mX.mX[15ULL];
  out->mLOG.mX[357ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[358ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[359ULL] = t27->mX.mX[15ULL];
  out->mLOG.mX[360ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[361ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[362ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[363ULL] = Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T;
  out->mLOG.mX[364ULL] = Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T;
  out->mLOG.mX[365ULL] = Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T;
  out->mLOG.mX[366ULL] = t27->mX.mX[26ULL];
  out->mLOG.mX[367ULL] = t27->mU.mX[3ULL];
  out->mLOG.mX[368ULL] = t27->mX.mX[26ULL] * 0.76923076923076916;
  out->mLOG.mX[372ULL] = t27->mX.mX[13ULL];
  out->mLOG.mX[373ULL] = t27->mX.mX[13ULL];
  out->mLOG.mX[375ULL] = t27->mX.mX[51ULL];
  out->mLOG.mX[376ULL] = t27->mX.mX[13ULL];
  out->mLOG.mX[377ULL] = t27->mX.mX[16ULL];
  out->mLOG.mX[378ULL] = t27->mDP_R.mX[0ULL] * t27->mX.mX[16ULL] * 9.81 * 0.001;
  out->mLOG.mX[379ULL] = t27->mX.mX[55ULL];
  out->mLOG.mX[381ULL] = t27->mX.mX[13ULL] * 3.6000000000000005;
  out->mLOG.mX[382ULL] = t27->mX.mX[23ULL];
  out->mLOG.mX[383ULL] = t27->mX.mX[31ULL];
  out->mLOG.mX[384ULL] = t27->mX.mX[36ULL];
  out->mLOG.mX[385ULL] = t27->mX.mX[44ULL];
  out->mLOG.mX[386ULL] = t27->mX.mX[48ULL];
  out->mLOG.mX[387ULL] = t27->mX.mX[50ULL];
  out->mLOG.mX[388ULL] = t27->mX.mX[53ULL];
  out->mLOG.mX[389ULL] = t27->mX.mX[57ULL];
  out->mLOG.mX[390ULL] = t27->mX.mX[39ULL];
  (void)LC;
  (void)out;
  return 0;
}
