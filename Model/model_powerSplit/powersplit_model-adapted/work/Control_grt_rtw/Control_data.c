/*
 * Control_data.c
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "Control".
 *
 * Model version              : 11.0
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Tue Mar 24 15:00:46 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Control.h"

/* Block parameters (default storage) */
P_Control_T Control_P = {
  /* Variable: HEV_Param
   * Referenced by:
   *   '<S3>/Ki'
   *   '<S3>/Kp'
   *   '<S6>/Ki'
   *   '<S6>/Kp'
   *   '<S7>/Gain'
   *   '<S10>/Ki'
   *   '<S10>/Kp'
   */
  {
    {
      200.0,
      8.1,
      75.75,
      0.02
    },

    {
      217.0,
      0.24691,
      6.9,
      6.2100000000000009,
      215.0342,
      2.3438,

      {
        2500.0,
        19.0,
        1.0e-6
      },
      0.3,
      1.8,
      6.9
    },

    {
      1000.0,
      0.2,
      10.0,
      500.0,
      217.0
    },

    {
      0.091,

      {
        { 0.0, 1200.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 6500.0, 10000.0 },

        { 400.0, 400.0, 225.0, 150.0, 100.0, 80.0, 70.0, 0.0, 0.0 }
      },
      1.0e-5,
      0.026666666666666668,
      0.2,
      0.01,

      { 0.001597972349731, 0.002057052250467 },
      91.0
    },

    {
      0.0047500000000000007,

      { 0.000635, 0.000635 },

      {
        { 0.0, 1200.0, 2000.0, 3000.0, 4000.0, 10000.0, 15000.0 },

        { 400.0, 400.0, 250.0, 150.0, 110.0, 0.0, 0.0 }
      },
      1.0e-5,
      0.04,
      0.2,
      0.01,
      0.0,
      1000.0,
      100.0
    },

    {
      500.0,
      0.625,
      0.01,
      10.0,
      20.0,

      {
        0.001,
        1.0
      },
      0.1,
      1.0,
      100.0,
      25.0,
      298.0,

      {
        20.0,
        100.0
      }
    },

    {
      800.0,
      790.0,
      0.1,

      {
        0.02,
        0.01
      },

      {
        10.0,
        3.0
      },

      {
        500.0,
        300.0
      },

      {
        0.02,
        0.04
      }
    },

    {
      1200.0,
      0.3,
      0.1,
      0.26,
      0.0,
      1.3,
      1.35,
      1.35,
      0.5,
      2.16,

      {
        3000.0,
        3500.0,
        6.0,
        0.25
      },

      {
        0.5,
        0.0001
      }
    },

    {
      2.6
    },

    {
      0.25,
      114000.0,
      5000.0,
      6000.0,
      0.2079,
      0.005,

      {
        { 1209.7, 1520.7333333333333, 1831.7666666666669, 2142.8,
          2453.8333333333335, 2764.8666666666668, 3075.9000000000005,
          3386.9333333333334, 3697.9666666666672, 4009.0 },

        { 24.81, 32.963333333333331, 41.11666666666666, 49.269999999999996,
          57.423333333333332, 65.576666666666668, 73.72999999999999,
          81.883333333333326, 90.036666666666662, 98.19 },

        { 0.32032317033934543, 0.35970260188122261, 0.40736176554259107,
          0.463300661323451, 0.5275192892238022, 0.60001764924364487,
          0.6807957413829786, 0.769853565641804, 0.86719112202012072,
          0.97280841051792866, 0.37775799534794763, 0.4285905823805789,
          0.4877029015327014, 0.55509495280431542, 0.63076673619542067,
          0.71471825170601733, 0.80694949933610516, 0.9074604790856845,
          1.0162511909547551, 1.1333216349433175, 0.44564253976283463,
          0.50792828228621989, 0.57849375692909644, 0.65733896369146461,
          0.74446390257332384, 0.83986857357467459, 0.94355297669551641,
          1.05551711193585, 1.1757609792956749, 1.304284578774991,
          0.52397680358400611, 0.59771570159814547, 0.67973433173177611,
          0.77003269398489826, 0.86861078835751171, 0.97546861484961656,
          1.0906061734612125, 1.2140234641923, 1.3457204870428789,
          1.4856972420129493, 0.6127607868114624, 0.69795284031635574,
          0.79142462594074048, 0.89317614368461662, 1.0032073935479842,
          1.1215183755308429, 1.248109089633193, 1.3829795358550347,
          1.5261297141963679, 1.6775596246571918, 0.71199448944520327,
          0.80863969844085071, 0.91356463955598954, 1.02676931279062,
          1.1482537181447414, 1.2780178556183543, 1.4160617252114582,
          1.5623853269240542, 1.7169886607561411, 1.8798717267077194,
          0.82167791148522906, 0.92977627597163048, 1.0461543725775235,
          1.1708122013029079, 1.3037497621477836, 1.4449670551121507,
          1.5944640801960086, 1.7522408373993585, 1.9182973267221999,
          2.0926335481645322, 0.94181105293153911, 1.0613625729086948,
          1.1891938250053415, 1.32530480922148, 1.4696955255571098,
          1.6223659740122309, 1.7833161545868428, 1.9525460672809469,
          2.130055712094542, 2.3158450890276283, 1.0723939137841343,
          1.203398589252044, 1.3426829968394449, 1.4902471365463374,
          1.6460910083727212, 1.8102146123185963, 1.9826179483839625,
          2.1633010165688202, 2.3522638168731698, 2.54950634929701,
          1.2134264940430137, 1.3558843250016774, 1.5066218880798325,
          1.6656391832774791, 1.832936210594617, 2.0085129700312461,
          2.1923694615873663, 2.3845056852629782, 2.5849216410580818,
          2.7936173289726765 }
      }
    },

    {
      50.0,
      0.8,
      25.0,
      400.0,
      0.01,
      20.0,
      1.2,
      180000.0,

      { 25.0, 40.0, 60.0, 75.0 },

      { 0.8, 1.1, 1.2, 1.12 },
      0.73,
      15.0,
      -40.0,
      1.95,
      2.0e-11,
      0.12,
      2.0,
      3.0,
      21.8,
      0.0006,
      -0.6,
      0.0042,
      0.001,
      -10.0,
      -8.75,
      0.11,
      100.0,
      6.0,
      34559.999999999993
    }
  },

  /* Mask Parameter: SensorDynamics_x_initial
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant'
   */
  1.0,

  /* Computed Parameter: u0HzLowpassFilter_A
   * Referenced by: '<S9>/20Hz Lowpass Filter'
   */
  -125.66370614359172,

  /* Computed Parameter: u0HzLowpassFilter_C
   * Referenced by: '<S9>/20Hz Lowpass Filter'
   */
  125.66370614359172,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Limits [-5,5]'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S10>/Limits [-5,5]'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S10>/Limits [-5,5]'
   */
  -5.0,

  /* Computed Parameter: u0HzLowpassFilter_A_o
   * Referenced by: '<S10>/20Hz Lowpass Filter'
   */
  -125.66370614359172,

  /* Computed Parameter: u0HzLowpassFilter_C_m
   * Referenced by: '<S10>/20Hz Lowpass Filter'
   */
  125.66370614359172,

  /* Expression: [0 6000 6000]
   * Referenced by: '<S1>/Acc to wMot'
   */
  { 0.0, 6000.0, 6000.0 },

  /* Expression: [0 1 1.2]
   * Referenced by: '<S1>/Acc to wMot'
   */
  { 0.0, 1.0, 1.2 },

  /* Expression: [800 5000 6000 6000]
   * Referenced by: '<S1>/Acc to wEng'
   */
  { 800.0, 5000.0, 6000.0, 6000.0 },

  /* Expression: [0 0.9 0.95 1]
   * Referenced by: '<S1>/Acc to wEng'
   */
  { 0.0, 0.9, 0.95, 1.0 },

  /* Expression: 5/10000
   * Referenced by: '<S10>/rpm2volts'
   */
  0.0005,

  /* Expression: 5
   * Referenced by: '<S10>/[-5,5]'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S10>/[-5,5]'
   */
  -5.0,

  /* Expression: 400/5
   * Referenced by: '<S10>/Volts//Nm'
   */
  80.0,

  /* Expression: 0
   * Referenced by: '<S6>/Limits [-5,5]'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S6>/Limits [-5,5]'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S6>/Limits [-5,5]'
   */
  -5.0,

  /* Computed Parameter: u0HzLowpassFilter_A_b
   * Referenced by: '<S6>/20Hz Lowpass Filter'
   */
  -125.66370614359172,

  /* Computed Parameter: u0HzLowpassFilter_C_f
   * Referenced by: '<S6>/20Hz Lowpass Filter'
   */
  125.66370614359172,

  /* Expression: 5/6500
   * Referenced by: '<S6>/rpm2volts'
   */
  0.00076923076923076923,

  /* Expression: 5
   * Referenced by: '<S6>/[-5,5]'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S6>/[-5,5]'
   */
  -5.0,

  /* Expression: 400/5
   * Referenced by: '<S6>/Volts//Nm'
   */
  80.0,

  /* Expression: 0
   * Referenced by: '<S3>/Limits [0,1]'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Limits [0,1]'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Limits [0,1]'
   */
  0.0,

  /* Computed Parameter: u0HzLowpassFilter_A_a
   * Referenced by: '<S3>/20Hz Lowpass Filter'
   */
  -125.66370614359172,

  /* Computed Parameter: u0HzLowpassFilter_C_o
   * Referenced by: '<S3>/20Hz Lowpass Filter'
   */
  125.66370614359172,

  /* Expression: 800
   * Referenced by: '<S3>/Engine Idle'
   */
  800.0,

  /* Expression: 0.5
   * Referenced by: '<S3>/Switch'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S3>/[0,1]'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/[0,1]'
   */
  0.0,

  /* Expression: 60/(2*pi)
   * Referenced by: '<S1>/Gain'
   */
  9.5492965855137211,

  /* Expression: 60/(2*pi)
   * Referenced by: '<S1>/Gain1'
   */
  9.5492965855137211,

  /* Expression: 5/10000
   * Referenced by: '<S10>/Gen RPM to V'
   */
  0.0005,

  /* Expression: 5/6700
   * Referenced by: '<S6>/Mot RPM to V'
   */
  0.00074626865671641792,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Computed Parameter: SelectLogic_CurrentSetting
   * Referenced by: '<S9>/Select Logic'
   */
  0U,

  /* Computed Parameter: SelectLogic_CurrentSetting_i
   * Referenced by: '<S12>/Select Logic'
   */
  0U,

  /* Computed Parameter: SelectLogic_CurrentSetting_n
   * Referenced by: '<S8>/Select Logic'
   */
  1U
};
