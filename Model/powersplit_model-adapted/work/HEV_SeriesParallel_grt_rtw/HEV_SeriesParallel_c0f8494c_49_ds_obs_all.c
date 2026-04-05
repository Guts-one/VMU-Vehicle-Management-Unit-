/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'HEV_SeriesParallel/Electrical/Solver Configuration'.
 */

#include "ne_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_sys_struct.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_obs_all.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_externals.h"
#include "HEV_SeriesParallel_c0f8494c_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T HEV_SeriesParallel_c0f8494c_49_ds_obs_all(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t20, NeDsMethodOutput *out)
{
  real_T Vehicle_Left_Tire_M[4];
  real_T Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  real_T Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  real_T Electrical_Generator_System_Motor_and_Drive_i;
  real_T Electrical_Generator_System_Motor_and_Drive_t;
  real_T Electrical_Generator_System_Power_Sensor_PS_Product1_O;
  real_T Electrical_Motor_System_Motor_and_Drive_t;
  real_T Electrical_Motor_System_Power_Sensor_PS_Product1_O;
  real_T Engine_Damper_t;
  real_T Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t;
  real_T Power_Split_Device_Sensor_Sun_Shaft_Ideal_Torque_Sensor_T;
  real_T Vehicle_Final_Drive_t_in;
  real_T Vehicle_Rear_Differential_base_gear_damperB_w;
  real_T Vehicle_Rear_Differential_sun_planet_left_P_w;
  real_T Vehicle_Rear_Differential_sun_planet_left_t_C;
  real_T Vehicle_Rotational_Damper_t;
  real_T Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T;
  real_T t12;
  real_T t13;
  real_T t16;
  size_t t6;
  (void)LC;
  out->mOBS_ALL.mX[86ULL] = 298.15;
  Vehicle_Left_Tire_M[0] = 0.0;
  Vehicle_Left_Tire_M[1] = 0.0;
  Vehicle_Left_Tire_M[2] = 0.0;
  Vehicle_Left_Tire_M[3] = 0.0;
  Electrical_DC_DC_Converter_Ideal_Transformer_i1 = (t20->mX.mX[0ULL] * 0.1 +
    t20->mX.mX[17ULL] * -0.071428571428571438) - t20->mX.mX[18ULL];
  Electrical_DC_DC_Converter_Ideal_Transformer_p1_v = t20->mX.mX[17ULL] *
    0.7142857142857143;
  out->mOBS_ALL.mX[20ULL] = ((t20->mX.mX[19ULL] * -0.02001 + t20->mX.mX[21ULL] *
    0.02) - t20->mX.mX[22ULL]) + t20->mX.mX[20ULL];
  Electrical_Generator_System_Motor_and_Drive_i = ((t20->mX.mX[0ULL] *
    0.071428571428571438 + t20->mX.mX[17ULL] * -0.051020408163265314) +
    t20->mX.mX[18ULL] * -0.7142857142857143) - t20->mX.mX[24ULL];
  Electrical_Generator_System_Motor_and_Drive_t = t20->mX.mX[19ULL] * 1.0E-5 -
    t20->mX.mX[20ULL];
  out->mOBS_ALL.mX[46ULL] = ((t20->mX.mX[0ULL] * -0.00071428571428571439 +
    t20->mX.mX[17ULL] * 1.0005102040816327) + t20->mX.mX[18ULL] *
    0.0071428571428571435) + t20->mX.mX[24ULL] * 0.01;
  Electrical_Generator_System_Power_Sensor_PS_Product1_O = t20->mX.mX[17ULL] *
    Electrical_Generator_System_Motor_and_Drive_i * 0.001;
  out->mOBS_ALL.mX[102ULL] = t20->mX.mX[0ULL] * -0.1 + t20->mX.mX[17ULL] *
    0.071428571428571438;
  t12 = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    Electrical_DC_DC_Converter_Ideal_Transformer_p1_v * 0.001;
  t13 = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[136ULL] = ((((t20->mX.mX[26ULL] * -0.00011 - t20->mX.mX[28ULL])
    + t20->mX.mX[29ULL] * -0.76923076923076916) + t20->mX.mX[30ULL] *
    -0.76923076923076916) + t20->mU.mX[3ULL] * 0.76923076923076916) + t20->
    mX.mX[27ULL];
  Electrical_Motor_System_Motor_and_Drive_t = t20->mX.mX[26ULL] * 1.0E-5 -
    t20->mX.mX[27ULL];
  out->mOBS_ALL.mX[162ULL] = t20->mX.mX[24ULL] * -0.01 + t20->mX.mX[17ULL];
  Electrical_Motor_System_Power_Sensor_PS_Product1_O = t20->mX.mX[17ULL] *
    t20->mX.mX[24ULL] * 0.001;
  Engine_Damper_t = t20->mX.mX[21ULL] * 0.2079;
  out->mOBS_ALL.mX[206ULL] = (((t20->mX.mX[19ULL] * 0.02 + t20->mX.mX[21ULL] *
    -0.2279) - t20->mX.mX[34ULL]) - t20->mX.mX[35ULL]) + t20->mX.mX[33ULL];
  t16 = ((t20->mX.mX[19ULL] * -0.02 + t20->mX.mX[21ULL] * 0.02) + t20->mX.mX
         [34ULL]) + t20->mX.mX[35ULL];
  out->mOBS_ALL.mX[250ULL] = -t20->mX.mX[40ULL];
  out->mOBS_ALL.mX[254ULL] = -t20->mX.mX[21ULL] + t20->mX.mX[8ULL];
  Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t = t20->mX.mX[19ULL]
    * 0.02 + t20->mX.mX[21ULL] * -0.02;
  Power_Split_Device_Sensor_Sun_Shaft_Ideal_Torque_Sensor_T = (t20->mX.mX[19ULL]
    * -0.02 + t20->mX.mX[21ULL] * 0.02) - t20->mX.mX[22ULL];
  Vehicle_Final_Drive_t_in = (t20->mX.mX[29ULL] * 0.76923076923076916 +
    t20->mX.mX[30ULL] * 0.76923076923076916) + t20->mU.mX[3ULL] *
    -0.76923076923076916;
  out->mOBS_ALL.mX[322ULL] = (-t20->mX.mX[41ULL] + t20->mX.mX[42ULL] * -0.3) +
    t20->mX.mX[30ULL] * 0.5;
  out->mOBS_ALL.mX[326ULL] = (t20->mX.mX[30ULL] * 0.5 - t20->mX.mX[45ULL]) +
    t20->mX.mX[46ULL] * -0.3;
  Vehicle_Rear_Differential_base_gear_damperB_w = t20->mX.mX[26ULL] *
    0.76923076923076916;
  Vehicle_Rear_Differential_sun_planet_left_P_w = t20->mX.mX[26ULL] *
    -0.76923076923076916 + t20->mX.mX[47ULL];
  Vehicle_Rear_Differential_sun_planet_left_t_C = t20->mX.mX[30ULL] * 0.5;
  Vehicle_Rotational_Damper_t = t20->mX.mX[26ULL] * 0.0001;
  Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T = ((t20->mX.mX[26ULL] *
    0.0001 + t20->mX.mX[29ULL] * 0.76923076923076916) + t20->mX.mX[30ULL] *
    0.76923076923076916) + t20->mU.mX[3ULL] * -0.76923076923076916;
  out->mOBS_ALL.mX[0ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[1ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    -0.7142857142857143;
  out->mOBS_ALL.mX[2ULL] = 0.0;
  out->mOBS_ALL.mX[3ULL] = 0.0;
  out->mOBS_ALL.mX[4ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[5ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[6ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[7ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v *
    1.4;
  out->mOBS_ALL.mX[8ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[9ULL] = 0.0;
  out->mOBS_ALL.mX[10ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[11ULL] = 0.0;
  out->mOBS_ALL.mX[12ULL] = 0.0;
  out->mOBS_ALL.mX[13ULL] = 0.0;
  out->mOBS_ALL.mX[14ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[15ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[16ULL] = t20->mU.mX[0ULL];
  out->mOBS_ALL.mX[17ULL] = t20->mU.mX[0ULL];
  out->mOBS_ALL.mX[18ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[19ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[21ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[22ULL] = 0.0;
  out->mOBS_ALL.mX[23ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[24ULL] = 0.0;
  out->mOBS_ALL.mX[25ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[26ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[27ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[28ULL] = 0.0;
  out->mOBS_ALL.mX[29ULL] = 0.0;
  out->mOBS_ALL.mX[30ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[31ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[32ULL] = t20->mU.mX[0ULL];
  out->mOBS_ALL.mX[33ULL] = 0.0;
  out->mOBS_ALL.mX[34ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[35ULL] = 0.0;
  out->mOBS_ALL.mX[36ULL] = 0.0;
  out->mOBS_ALL.mX[37ULL] = 0.0;
  out->mOBS_ALL.mX[38ULL] = 0.0;
  out->mOBS_ALL.mX[39ULL] = Electrical_Generator_System_Motor_and_Drive_i;
  out->mOBS_ALL.mX[40ULL] = ((Electrical_Generator_System_Motor_and_Drive_i *
    Electrical_Generator_System_Motor_and_Drive_i * 1.0E-5 + t20->mX.mX[19ULL] *
    t20->mX.mX[19ULL] * 1.0E-8) + t20->mX.mX[20ULL] * t20->mX.mX[20ULL] *
    0.00011635528346628851) * 1000.0;
  out->mOBS_ALL.mX[41ULL] = Electrical_Generator_System_Motor_and_Drive_t;
  out->mOBS_ALL.mX[42ULL] = t20->mX.mX[25ULL];
  out->mOBS_ALL.mX[43ULL] = t20->mX.mX[25ULL];
  out->mOBS_ALL.mX[44ULL] = t20->mX.mX[20ULL];
  out->mOBS_ALL.mX[45ULL] = t20->mX.mX[1ULL];
  out->mOBS_ALL.mX[47ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[48ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[49ULL] = Electrical_Generator_System_Motor_and_Drive_i;
  out->mOBS_ALL.mX[50ULL] = Electrical_Generator_System_Motor_and_Drive_i;
  out->mOBS_ALL.mX[51ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[52ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[53ULL] = Electrical_Generator_System_Motor_and_Drive_i;
  out->mOBS_ALL.mX[54ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[55ULL] =
    Electrical_Generator_System_Power_Sensor_PS_Product1_O * 1000.0;
  out->mOBS_ALL.mX[56ULL] =
    Electrical_Generator_System_Power_Sensor_PS_Product1_O * 1000.0;
  out->mOBS_ALL.mX[57ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[58ULL] = 0.0;
  out->mOBS_ALL.mX[59ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[60ULL] = 0.0;
  out->mOBS_ALL.mX[61ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[62ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[63ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[64ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[65ULL] = 0.0;
  out->mOBS_ALL.mX[66ULL] = t20->mX.mX[2ULL];
  out->mOBS_ALL.mX[67ULL] = 0.0;
  out->mOBS_ALL.mX[68ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[69ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[70ULL] = 0.0;
  out->mOBS_ALL.mX[71ULL] = t20->mX.mX[2ULL] * 57.295779513082323;
  out->mOBS_ALL.mX[72ULL] = t20->mX.mX[2ULL];
  out->mOBS_ALL.mX[73ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[74ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[75ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[76ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[77ULL] = -Electrical_Generator_System_Motor_and_Drive_t;
  out->mOBS_ALL.mX[78ULL] = -Electrical_Generator_System_Motor_and_Drive_t;
  out->mOBS_ALL.mX[79ULL] = -Electrical_Generator_System_Motor_and_Drive_t;
  out->mOBS_ALL.mX[80ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[81ULL] = 0.0;
  out->mOBS_ALL.mX[82ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[83ULL] = 0.0;
  out->mOBS_ALL.mX[84ULL] = 0.0;
  out->mOBS_ALL.mX[85ULL] = t20->mX.mX[3ULL];
  out->mOBS_ALL.mX[87ULL] = t20->mX.mX[18ULL];
  out->mOBS_ALL.mX[88ULL] = t20->mX.mX[4ULL] * 0.00027777777777777778;
  out->mOBS_ALL.mX[89ULL] = 0.0;
  out->mOBS_ALL.mX[90ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[91ULL] = 0.0;
  out->mOBS_ALL.mX[92ULL] = 0.0;
  out->mOBS_ALL.mX[93ULL] = 0.0;
  out->mOBS_ALL.mX[94ULL] = 0.0;
  out->mOBS_ALL.mX[95ULL] = 0.0;
  out->mOBS_ALL.mX[96ULL] = t20->mX.mX[4ULL];
  out->mOBS_ALL.mX[97ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[98ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[99ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[100ULL] = 0.0;
  out->mOBS_ALL.mX[101ULL] = 0.0;
  out->mOBS_ALL.mX[103ULL] = 0.0;
  out->mOBS_ALL.mX[104ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[105ULL] = t20->mX.mX[0ULL];
  out->mOBS_ALL.mX[106ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[107ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[108ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[109ULL] = t12 * 1000.0;
  out->mOBS_ALL.mX[110ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[111ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[112ULL] = t13;
  out->mOBS_ALL.mX[113ULL] = t12 * 1000.0;
  out->mOBS_ALL.mX[114ULL] = t13;
  out->mOBS_ALL.mX[115ULL] = t13 * 0.24691;
  out->mOBS_ALL.mX[116ULL] = t13 * 0.24691;
  out->mOBS_ALL.mX[117ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[118ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[119ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    -0.00027777777777777778;
  out->mOBS_ALL.mX[120ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1 *
    -0.00027777777777777778;
  out->mOBS_ALL.mX[121ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[122ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[123ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_i1;
  out->mOBS_ALL.mX[124ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[125ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[126ULL] = 0.0;
  out->mOBS_ALL.mX[127ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[128ULL] = Electrical_DC_DC_Converter_Ideal_Transformer_p1_v;
  out->mOBS_ALL.mX[129ULL] = 0.0;
  out->mOBS_ALL.mX[130ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[131ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[132ULL] = t20->mU.mX[1ULL];
  out->mOBS_ALL.mX[133ULL] = t20->mU.mX[1ULL];
  out->mOBS_ALL.mX[134ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[135ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[137ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[138ULL] = 0.0;
  out->mOBS_ALL.mX[139ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[140ULL] = 0.0;
  out->mOBS_ALL.mX[141ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[142ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[143ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[144ULL] = 0.0;
  out->mOBS_ALL.mX[145ULL] = 0.0;
  out->mOBS_ALL.mX[146ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[147ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[148ULL] = t20->mU.mX[1ULL];
  out->mOBS_ALL.mX[149ULL] = 0.0;
  out->mOBS_ALL.mX[150ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[151ULL] = 0.0;
  out->mOBS_ALL.mX[152ULL] = 0.0;
  out->mOBS_ALL.mX[153ULL] = 0.0;
  out->mOBS_ALL.mX[154ULL] = 0.0;
  out->mOBS_ALL.mX[155ULL] = t20->mX.mX[24ULL];
  out->mOBS_ALL.mX[156ULL] = ((t20->mX.mX[24ULL] * t20->mX.mX[24ULL] * 1.0E-5 +
    t20->mX.mX[26ULL] * t20->mX.mX[26ULL] * 1.0E-8) + t20->mX.mX[27ULL] *
    t20->mX.mX[27ULL] * 0.00010356898857988329) * 1000.0;
  out->mOBS_ALL.mX[157ULL] = Electrical_Motor_System_Motor_and_Drive_t;
  out->mOBS_ALL.mX[158ULL] = t20->mX.mX[32ULL];
  out->mOBS_ALL.mX[159ULL] = t20->mX.mX[32ULL];
  out->mOBS_ALL.mX[160ULL] = t20->mX.mX[27ULL];
  out->mOBS_ALL.mX[161ULL] = t20->mX.mX[5ULL];
  out->mOBS_ALL.mX[163ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[164ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[165ULL] = t20->mX.mX[24ULL];
  out->mOBS_ALL.mX[166ULL] = t20->mX.mX[24ULL];
  out->mOBS_ALL.mX[167ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[168ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[169ULL] = t20->mX.mX[24ULL];
  out->mOBS_ALL.mX[170ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[171ULL] = Electrical_Motor_System_Power_Sensor_PS_Product1_O *
    1000.0;
  out->mOBS_ALL.mX[172ULL] = Electrical_Motor_System_Power_Sensor_PS_Product1_O *
    1000.0;
  out->mOBS_ALL.mX[173ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[174ULL] = 0.0;
  out->mOBS_ALL.mX[175ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[176ULL] = 0.0;
  out->mOBS_ALL.mX[177ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[178ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[179ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[180ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[181ULL] = 0.0;
  out->mOBS_ALL.mX[182ULL] = t20->mX.mX[6ULL];
  out->mOBS_ALL.mX[183ULL] = 0.0;
  out->mOBS_ALL.mX[184ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[185ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[186ULL] = 0.0;
  out->mOBS_ALL.mX[187ULL] = t20->mX.mX[6ULL] * 57.295779513082323;
  out->mOBS_ALL.mX[188ULL] = t20->mX.mX[6ULL];
  out->mOBS_ALL.mX[189ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[190ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[191ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[192ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[193ULL] = -Electrical_Motor_System_Motor_and_Drive_t;
  out->mOBS_ALL.mX[194ULL] = -Electrical_Motor_System_Motor_and_Drive_t;
  out->mOBS_ALL.mX[195ULL] = -Electrical_Motor_System_Motor_and_Drive_t;
  out->mOBS_ALL.mX[196ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[197ULL] = 0.0;
  out->mOBS_ALL.mX[198ULL] = t20->mX.mX[17ULL];
  out->mOBS_ALL.mX[199ULL] = 0.0;
  out->mOBS_ALL.mX[200ULL] = 0.0;
  out->mOBS_ALL.mX[201ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[202ULL] = Engine_Damper_t;
  out->mOBS_ALL.mX[203ULL] = Engine_Damper_t * 4.81000481000481;
  out->mOBS_ALL.mX[204ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[205ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[207ULL] = t20->mX.mX[21ULL] * 9.5492965855137211;
  out->mOBS_ALL.mX[208ULL] = 0.0;
  out->mOBS_ALL.mX[209ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[210ULL] = t20->mX.mX[37ULL];
  out->mOBS_ALL.mX[211ULL] = t20->mX.mX[21ULL] * t20->mX.mX[33ULL] * 0.001 *
    1000.0;
  out->mOBS_ALL.mX[212ULL] = t20->mU.mX[2ULL];
  out->mOBS_ALL.mX[213ULL] = 0.0;
  out->mOBS_ALL.mX[214ULL] = t20->mX.mX[38ULL];
  out->mOBS_ALL.mX[215ULL] = t20->mX.mX[38ULL];
  out->mOBS_ALL.mX[216ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[217ULL] = t20->mX.mX[33ULL];
  out->mOBS_ALL.mX[218ULL] = 0.0;
  out->mOBS_ALL.mX[219ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[220ULL] = t20->mX.mX[7ULL];
  out->mOBS_ALL.mX[221ULL] = 0.0;
  out->mOBS_ALL.mX[222ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[223ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[224ULL] = 0.0;
  out->mOBS_ALL.mX[225ULL] = t20->mX.mX[7ULL];
  out->mOBS_ALL.mX[226ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[227ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[228ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[229ULL] = t16;
  out->mOBS_ALL.mX[230ULL] = t16;
  out->mOBS_ALL.mX[231ULL] = t16;
  out->mOBS_ALL.mX[232ULL] = 0.0;
  out->mOBS_ALL.mX[233ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[234ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[235ULL] = t20->mU.mX[2ULL];
  out->mOBS_ALL.mX[236ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[237ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[238ULL] = 0.0;
  out->mOBS_ALL.mX[239ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[240ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[241ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[242ULL] = 0.0;
  out->mOBS_ALL.mX[243ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[244ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[245ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[246ULL] = 0.0;
  out->mOBS_ALL.mX[247ULL] = t20->mX.mX[8ULL];
  out->mOBS_ALL.mX[248ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[249ULL] = 300.0;
  out->mOBS_ALL.mX[251ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[252ULL] = t20->mX.mX[8ULL];
  out->mOBS_ALL.mX[253ULL] = 0.0;
  out->mOBS_ALL.mX[255ULL] = t20->mX.mX[34ULL];
  out->mOBS_ALL.mX[256ULL] = t20->mX.mX[28ULL];
  out->mOBS_ALL.mX[257ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[258ULL] = 0.0;
  out->mOBS_ALL.mX[259ULL] = t20->mX.mX[8ULL];
  out->mOBS_ALL.mX[260ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[261ULL] = 300.0;
  out->mOBS_ALL.mX[262ULL] = t20->mX.mX[22ULL];
  out->mOBS_ALL.mX[263ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[264ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[265ULL] =
    Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t;
  out->mOBS_ALL.mX[266ULL] =
    Power_Split_Device_Planetary_Gear_gear_sun_planet_damper_t * 50.0;
  out->mOBS_ALL.mX[267ULL] = t20->mX.mX[35ULL];
  out->mOBS_ALL.mX[268ULL] = t20->mX.mX[40ULL];
  out->mOBS_ALL.mX[269ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[270ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[271ULL] = t20->mX.mX[9ULL];
  out->mOBS_ALL.mX[272ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[273ULL] = 0.0;
  out->mOBS_ALL.mX[274ULL] = -t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[275ULL] = 0.0;
  out->mOBS_ALL.mX[276ULL] = t20->mX.mX[9ULL];
  out->mOBS_ALL.mX[277ULL] = -t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[278ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[279ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[280ULL] = -t16;
  out->mOBS_ALL.mX[281ULL] = -t16;
  out->mOBS_ALL.mX[282ULL] = -t16;
  out->mOBS_ALL.mX[283ULL] = 0.0;
  out->mOBS_ALL.mX[284ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[285ULL] = t20->mX.mX[21ULL];
  out->mOBS_ALL.mX[286ULL] = t20->mX.mX[10ULL];
  out->mOBS_ALL.mX[287ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[288ULL] = 0.0;
  out->mOBS_ALL.mX[289ULL] = -t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[290ULL] = 0.0;
  out->mOBS_ALL.mX[291ULL] = t20->mX.mX[10ULL];
  out->mOBS_ALL.mX[292ULL] = -t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[293ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[294ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[295ULL] = -t20->mX.mX[28ULL];
  out->mOBS_ALL.mX[296ULL] = -t20->mX.mX[28ULL];
  out->mOBS_ALL.mX[297ULL] = -t20->mX.mX[28ULL];
  out->mOBS_ALL.mX[298ULL] = 0.0;
  out->mOBS_ALL.mX[299ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[300ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[301ULL] = t20->mX.mX[11ULL];
  out->mOBS_ALL.mX[302ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[303ULL] = 0.0;
  out->mOBS_ALL.mX[304ULL] = -t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[305ULL] = 0.0;
  out->mOBS_ALL.mX[306ULL] = t20->mX.mX[11ULL];
  out->mOBS_ALL.mX[307ULL] = -t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[308ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[309ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[310ULL] =
    Power_Split_Device_Sensor_Sun_Shaft_Ideal_Torque_Sensor_T;
  out->mOBS_ALL.mX[311ULL] =
    Power_Split_Device_Sensor_Sun_Shaft_Ideal_Torque_Sensor_T;
  out->mOBS_ALL.mX[312ULL] =
    Power_Split_Device_Sensor_Sun_Shaft_Ideal_Torque_Sensor_T;
  out->mOBS_ALL.mX[313ULL] = 0.0;
  out->mOBS_ALL.mX[314ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[315ULL] = t20->mX.mX[19ULL];
  out->mOBS_ALL.mX[316ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[317ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[318ULL] = Vehicle_Final_Drive_t_in;
  out->mOBS_ALL.mX[319ULL] = Vehicle_Final_Drive_t_in * -1.3;
  out->mOBS_ALL.mX[320ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[321ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[323ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[324ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[325ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[327ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[328ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[329ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[330ULL] = t20->mX.mX[29ULL];
  out->mOBS_ALL.mX[331ULL] = t20->mX.mX[49ULL];
  out->mOBS_ALL.mX[332ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[333ULL] = t20->mX.mX[13ULL];
  for (t6 = 0ULL; t6 < 4ULL; t6++) {
    out->mOBS_ALL.mX[t6 + 334ULL] = Vehicle_Left_Tire_M[t6];
  }

  out->mOBS_ALL.mX[338ULL] = t20->mX.mX[51ULL];
  out->mOBS_ALL.mX[339ULL] = t20->mX.mX[52ULL];
  out->mOBS_ALL.mX[340ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[341ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[342ULL] = t20->mX.mX[41ULL];
  out->mOBS_ALL.mX[343ULL] = t20->mX.mX[12ULL] * 9.5492965855137211;
  out->mOBS_ALL.mX[344ULL] = t20->mX.mX[13ULL];
  for (t6 = 0ULL; t6 < 4ULL; t6++) {
    out->mOBS_ALL.mX[t6 + 345ULL] = Vehicle_Left_Tire_M[t6];
  }

  out->mOBS_ALL.mX[349ULL] = t20->mX.mX[51ULL];
  out->mOBS_ALL.mX[350ULL] = t20->mX.mX[52ULL];
  out->mOBS_ALL.mX[351ULL] = t20->mX.mX[43ULL] * 0.3;
  out->mOBS_ALL.mX[352ULL] = -t20->mX.mX[54ULL] - t20->mX.mX[55ULL];
  out->mOBS_ALL.mX[353ULL] = t20->mX.mX[42ULL];
  out->mOBS_ALL.mX[354ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[355ULL] = 0.0;
  out->mOBS_ALL.mX[356ULL] = t20->mX.mX[43ULL] * 0.3;
  out->mOBS_ALL.mX[357ULL] = -t20->mX.mX[42ULL];
  out->mOBS_ALL.mX[358ULL] = t20->mX.mX[42ULL] * 0.3;
  out->mOBS_ALL.mX[359ULL] = t20->mX.mX[52ULL];
  out->mOBS_ALL.mX[360ULL] = 0.0;
  out->mOBS_ALL.mX[361ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[362ULL] = 0.0;
  out->mOBS_ALL.mX[363ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[364ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[365ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[366ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[367ULL] = 0.0;
  out->mOBS_ALL.mX[368ULL] = t20->mX.mX[30ULL];
  out->mOBS_ALL.mX[369ULL] = 300.0;
  out->mOBS_ALL.mX[370ULL] = 0.0;
  out->mOBS_ALL.mX[371ULL] = 0.0;
  out->mOBS_ALL.mX[372ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[373ULL] = 0.0;
  out->mOBS_ALL.mX[374ULL] = Vehicle_Rear_Differential_base_gear_damperB_w;
  out->mOBS_ALL.mX[375ULL] = 0.0;
  out->mOBS_ALL.mX[376ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[377ULL] = 0.0;
  out->mOBS_ALL.mX[378ULL] = Vehicle_Rear_Differential_base_gear_damperB_w;
  out->mOBS_ALL.mX[379ULL] = 0.0;
  out->mOBS_ALL.mX[380ULL] = -t20->mX.mX[30ULL];
  out->mOBS_ALL.mX[381ULL] = 0.0;
  out->mOBS_ALL.mX[382ULL] = 0.0;
  out->mOBS_ALL.mX[383ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[384ULL] = 0.0;
  out->mOBS_ALL.mX[385ULL] = Vehicle_Rear_Differential_sun_planet_left_P_w;
  out->mOBS_ALL.mX[386ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[387ULL] = 300.0;
  out->mOBS_ALL.mX[388ULL] = -Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mOBS_ALL.mX[389ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[390ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[391ULL] = 0.0;
  out->mOBS_ALL.mX[392ULL] = Vehicle_Rear_Differential_sun_planet_left_P_w;
  out->mOBS_ALL.mX[393ULL] = Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mOBS_ALL.mX[394ULL] = Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mOBS_ALL.mX[395ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[396ULL] = 0.0;
  out->mOBS_ALL.mX[397ULL] = Vehicle_Rear_Differential_sun_planet_left_P_w;
  out->mOBS_ALL.mX[398ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[399ULL] = 300.0;
  out->mOBS_ALL.mX[400ULL] = -Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mOBS_ALL.mX[401ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[402ULL] = t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[403ULL] = 0.0;
  out->mOBS_ALL.mX[404ULL] = t20->mX.mX[26ULL] * -0.76923076923076916 +
    t20->mX.mX[43ULL];
  out->mOBS_ALL.mX[405ULL] = Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mOBS_ALL.mX[406ULL] = -Vehicle_Rear_Differential_sun_planet_left_t_C;
  out->mOBS_ALL.mX[407ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[408ULL] = t20->mX.mX[13ULL];
  for (t6 = 0ULL; t6 < 4ULL; t6++) {
    out->mOBS_ALL.mX[t6 + 409ULL] = Vehicle_Left_Tire_M[t6];
  }

  out->mOBS_ALL.mX[413ULL] = t20->mX.mX[51ULL];
  out->mOBS_ALL.mX[414ULL] = t20->mX.mX[56ULL];
  out->mOBS_ALL.mX[415ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[416ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[417ULL] = t20->mX.mX[45ULL];
  out->mOBS_ALL.mX[418ULL] = t20->mX.mX[14ULL] * 9.5492965855137211;
  out->mOBS_ALL.mX[419ULL] = t20->mX.mX[13ULL];
  for (t6 = 0ULL; t6 < 4ULL; t6++) {
    out->mOBS_ALL.mX[t6 + 420ULL] = Vehicle_Left_Tire_M[t6];
  }

  out->mOBS_ALL.mX[424ULL] = t20->mX.mX[51ULL];
  out->mOBS_ALL.mX[425ULL] = t20->mX.mX[56ULL];
  out->mOBS_ALL.mX[426ULL] = t20->mX.mX[47ULL] * 0.3;
  out->mOBS_ALL.mX[427ULL] = t20->mX.mX[54ULL];
  out->mOBS_ALL.mX[428ULL] = t20->mX.mX[46ULL];
  out->mOBS_ALL.mX[429ULL] = t20->mX.mX[47ULL];
  out->mOBS_ALL.mX[430ULL] = 0.0;
  out->mOBS_ALL.mX[431ULL] = t20->mX.mX[47ULL] * 0.3;
  out->mOBS_ALL.mX[432ULL] = -t20->mX.mX[46ULL];
  out->mOBS_ALL.mX[433ULL] = t20->mX.mX[46ULL] * 0.3;
  out->mOBS_ALL.mX[434ULL] = 0.0;
  out->mOBS_ALL.mX[435ULL] = 0.0;
  out->mOBS_ALL.mX[436ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[437ULL] = Vehicle_Rotational_Damper_t;
  out->mOBS_ALL.mX[438ULL] = Vehicle_Rotational_Damper_t * 10000.0;
  out->mOBS_ALL.mX[439ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[440ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[441ULL] = t20->mX.mX[15ULL];
  out->mOBS_ALL.mX[442ULL] = 0.0;
  out->mOBS_ALL.mX[443ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[444ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[445ULL] = 0.0;
  out->mOBS_ALL.mX[446ULL] = t20->mX.mX[15ULL];
  out->mOBS_ALL.mX[447ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[448ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[449ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[450ULL] =
    Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T;
  out->mOBS_ALL.mX[451ULL] =
    Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T;
  out->mOBS_ALL.mX[452ULL] =
    Vehicle_Sensor_Speed_and_Power_Ideal_Torque_Sensor_T;
  out->mOBS_ALL.mX[453ULL] = 0.0;
  out->mOBS_ALL.mX[454ULL] = t20->mX.mX[26ULL];
  out->mOBS_ALL.mX[455ULL] = t20->mU.mX[3ULL];
  out->mOBS_ALL.mX[456ULL] = 0.0;
  out->mOBS_ALL.mX[457ULL] = t20->mX.mX[26ULL] * 0.76923076923076916;
  out->mOBS_ALL.mX[458ULL] = t20->mU.mX[3ULL];
  out->mOBS_ALL.mX[459ULL] = -t20->mU.mX[3ULL];
  out->mOBS_ALL.mX[460ULL] = -(t20->mX.mX[26ULL] * 0.76923076923076916);
  out->mOBS_ALL.mX[461ULL] = 0.0;
  out->mOBS_ALL.mX[462ULL] = t20->mX.mX[13ULL];
  out->mOBS_ALL.mX[463ULL] = 0.0;
  out->mOBS_ALL.mX[464ULL] = t20->mX.mX[13ULL];
  out->mOBS_ALL.mX[465ULL] = (t20->mDP_R.mX[1ULL] * 1.35 - t20->mX.mX[55ULL] *
    0.5) / 2.7 / 2.0;
  out->mOBS_ALL.mX[466ULL] = t20->mX.mX[51ULL];
  out->mOBS_ALL.mX[467ULL] = t20->mX.mX[13ULL];
  out->mOBS_ALL.mX[468ULL] = 0.0;
  out->mOBS_ALL.mX[469ULL] = 0.0;
  out->mOBS_ALL.mX[470ULL] = 0.0;
  out->mOBS_ALL.mX[471ULL] = t20->mX.mX[16ULL];
  out->mOBS_ALL.mX[472ULL] = 0.0;
  out->mOBS_ALL.mX[473ULL] = t20->mX.mX[55ULL];
  out->mOBS_ALL.mX[474ULL] = 0.0;
  out->mOBS_ALL.mX[475ULL] = 0.0;
  out->mOBS_ALL.mX[476ULL] = 0.0;
  out->mOBS_ALL.mX[477ULL] = t20->mX.mX[13ULL] * 3.6000000000000005;
  out->mOBS_ALL.mX[478ULL] = 0.0;
  (void)LC;
  (void)out;
  return 0;
}
