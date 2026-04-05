/*
 * Control.c
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
#include "rtwtypes.h"
#include <string.h>
#include "Control_private.h"
#include "zero_crossing_types.h"
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S1>/Mode Logic' */
#define Control_EngOffRPM              (790.0)
#define Control_EngOnRPM               (800.0)
#define Control_IN_Accelerate_mode     ((uint8_T)1U)
#define Control_IN_Brake_mode          ((uint8_T)1U)
#define Control_IN_Cruise_mode         ((uint8_T)2U)
#define Control_IN_Motion_mode         ((uint8_T)2U)
#define Control_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define Control_IN_Normal_mode         ((uint8_T)1U)
#define Control_IN_Start_mode          ((uint8_T)2U)
#define Control_IN_charge              ((uint8_T)1U)
#define Control_IN_nocharge            ((uint8_T)2U)

/* Block signals (default storage) */
B_Control_T Control_B;

/* Continuous states */
X_Control_T Control_X;

/* Disabled State Vector */
XDis_Control_T Control_XDis;

/* Block states (default storage) */
DW_Control_T Control_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Control_T Control_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_Control_T Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Control_T Control_Y;

/* Real-time model */
static RT_MODEL_Control_T Control_M_;
RT_MODEL_Control_T *const Control_M = &Control_M_;

/* Forward declaration for local functions */
static real_T Control_oldspeed(void);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Control_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Control_step0();
  Control_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Control_step0();
  Control_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for Chart: '<S1>/Mode Logic' */
static real_T Control_oldspeed(void)
{
  real_T tmp[20];
  real_T accumulatedData;
  real_T speed_buffer;
  int32_T k;

  /* MATLAB Function 'oldspeed': '<S5>:6' */
  /* '<S5>:6:2' */
  memcpy(&tmp[0], &Control_DW.speed_buffer[0], 20U * sizeof(real_T));

  /* '<S5>:6:3' */
  Control_DW.speed_buffer[0] = Control_B.TmpRTBAtModeLogicInport1;

  /* '<S5>:6:4' */
  accumulatedData = Control_DW.speed_buffer[0];
  for (k = 0; k < 20; k++) {
    speed_buffer = tmp[k];
    Control_DW.speed_buffer[k + 1] = speed_buffer;
    accumulatedData += speed_buffer;
  }

  return accumulatedData / 21.0;
}

/* Model step function for TID0 */
void Control_step0(void)               /* Sample time: [0.0s, 0.0s] */
{
  real_T rtb_Sum;
  real_T rtb_Sum_e;
  real_T rtb_Sum_i;
  real_T rtb_Switch;
  real_T u0;
  boolean_T tmp;
  boolean_T tmp_0;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(Control_M)) {
    /* set solver stop time */
    if (!(Control_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Control_M->solverInfo,
                            ((Control_M->Timing.clockTickH0 + 1) *
        Control_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Control_M->solverInfo,
                            ((Control_M->Timing.clockTick0 + 1) *
        Control_M->Timing.stepSize0 + Control_M->Timing.clockTickH0 *
        Control_M->Timing.stepSize0 * 4294967296.0));
    }

    /* Update the flag to indicate when data transfers from
     *  Sample time: [1.0E-5s, 0.0s] to Sample time: [0.1s, 0.0s]  */
    (Control_M->Timing.RateInteraction.TID1_2)++;
    if ((Control_M->Timing.RateInteraction.TID1_2) > 9999) {
      Control_M->Timing.RateInteraction.TID1_2 = 0;
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Control_M)) {
    Control_M->Timing.t[0] = rtsiGetT(&Control_M->solverInfo);
  }

  /* RateTransition generated from: '<S8>/Select Logic' incorporates:
   *  RateTransition generated from: '<S1>/Mode Logic'
   * */
  tmp_0 = rtmIsMajorTimeStep(Control_M);
  if (tmp_0 && (Control_M->Timing.RateInteraction.TID1_2 == 1)) {
    /* RateTransition generated from: '<S8>/Select Logic' */
    Control_B.TmpRTBAtSelectLogicOutport1 =
      Control_DW.TmpRTBAtSelectLogicOutport1_Buf;
  }

  /* End of RateTransition generated from: '<S8>/Select Logic' */

  /* Integrator: '<S10>/Limits [-5,5]' incorporates:
   *  Integrator: '<S3>/Limits [0,1]'
   */
  /* Limited  Integrator  */
  tmp = rtsiIsModeUpdateTimeStep(&Control_M->solverInfo);
  if (tmp) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&Control_PrevZCX.Limits55_Reset_ZCE,
                       (Control_B.TmpRTBAtSelectLogicOutport1));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      Control_X.Limits55_CSTATE = Control_P.Limits55_IC;
    }
  }

  if (Control_X.Limits55_CSTATE >= Control_P.Limits55_UpperSat) {
    Control_X.Limits55_CSTATE = Control_P.Limits55_UpperSat;
  } else if (Control_X.Limits55_CSTATE <= Control_P.Limits55_LowerSat) {
    Control_X.Limits55_CSTATE = Control_P.Limits55_LowerSat;
  }

  /* Lookup_n-D: '<S1>/Acc to wMot' incorporates:
   *  Inport: '<Root>/Acc'
   */
  rtb_Sum_i = look1_binlxpw(Control_U.Acc, Control_P.AcctowMot_bp01Data,
    Control_P.AcctowMot_tableData, 2U);

  /* Lookup_n-D: '<S1>/Acc to wEng' incorporates:
   *  Inport: '<Root>/Acc'
   */
  rtb_Switch = look1_binlxpw(Control_U.Acc, Control_P.AcctowEng_bp01Data,
    Control_P.AcctowEng_tableData, 3U);

  /* Sum: '<S10>/Sum' incorporates:
   *  Fcn: '<S4>/Set generator RPM so that engine RPM is controlled to zero or the idle speed'
   *  Gain: '<S10>/rpm2volts'
   *  TransferFcn: '<S10>/20Hz Lowpass Filter'
   */
  rtb_Sum = (3.6 * rtb_Switch - 2.6 * rtb_Sum_i) * Control_P.rpm2volts_Gain -
    Control_P.u0HzLowpassFilter_C_m * Control_X.u0HzLowpassFilter_CSTATE_g;

  /* Sum: '<S10>/Sum1' incorporates:
   *  Gain: '<S10>/Kp'
   *  Integrator: '<S10>/Limits [-5,5]'
   */
  rtb_Sum_e = Control_P.HEV_Param.Control.Gen.Kp * rtb_Sum +
    Control_X.Limits55_CSTATE;

  /* Saturate: '<S10>/[-5,5]' */
  if (rtb_Sum_e > Control_P.u5_UpperSat) {
    rtb_Sum_e = Control_P.u5_UpperSat;
  } else if (rtb_Sum_e < Control_P.u5_LowerSat) {
    rtb_Sum_e = Control_P.u5_LowerSat;
  }

  /* End of Saturate: '<S10>/[-5,5]' */

  /* ManualSwitch: '<S9>/Select Logic' */
  if (Control_P.SelectLogic_CurrentSetting == 1) {
    /* Outport: '<Root>/TrqReqGen' incorporates:
     *  Gain: '<S10>/Volts//Nm'
     *  Product: '<S9>/Product'
     *  TransferFcn: '<S9>/20Hz Lowpass Filter'
     */
    Control_Y.TrqReqGen = Control_P.u0HzLowpassFilter_C *
      Control_X.u0HzLowpassFilter_CSTATE * (Control_P.VoltsNm_Gain * rtb_Sum_e);
  } else {
    /* Outport: '<Root>/TrqReqGen' incorporates:
     *  Gain: '<S10>/Volts//Nm'
     */
    Control_Y.TrqReqGen = Control_P.VoltsNm_Gain * rtb_Sum_e;
  }

  /* End of ManualSwitch: '<S9>/Select Logic' */

  /* Integrator: '<S6>/Limits [-5,5]' */
  /* Limited  Integrator  */
  if (Control_X.Limits55_CSTATE_n >= Control_P.Limits55_UpperSat_g) {
    Control_X.Limits55_CSTATE_n = Control_P.Limits55_UpperSat_g;
  } else if (Control_X.Limits55_CSTATE_n <= Control_P.Limits55_LowerSat_c) {
    Control_X.Limits55_CSTATE_n = Control_P.Limits55_LowerSat_c;
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/rpm2volts'
   *  TransferFcn: '<S6>/20Hz Lowpass Filter'
   */
  rtb_Sum_e = Control_P.rpm2volts_Gain_p * rtb_Sum_i -
    Control_P.u0HzLowpassFilter_C_f * Control_X.u0HzLowpassFilter_CSTATE_l;

  /* ManualSwitch: '<S12>/Select Logic' */
  if (Control_P.SelectLogic_CurrentSetting_i == 1) {
    /* Sum: '<S6>/Sum1' incorporates:
     *  Gain: '<S6>/Kp'
     *  Integrator: '<S6>/Limits [-5,5]'
     */
    u0 = Control_P.HEV_Param.Control.Mot.Kp * rtb_Sum_e +
      Control_X.Limits55_CSTATE_n;

    /* Saturate: '<S6>/[-5,5]' */
    if (u0 > Control_P.u5_UpperSat_m) {
      u0 = Control_P.u5_UpperSat_m;
    } else if (u0 < Control_P.u5_LowerSat_a) {
      u0 = Control_P.u5_LowerSat_a;
    }

    /* Outport: '<Root>/trqReqM' incorporates:
     *  Gain: '<S6>/Volts//Nm'
     *  Product: '<S12>/Product'
     *  Saturate: '<S6>/[-5,5]'
     */
    Control_Y.trqReqM = Control_P.VoltsNm_Gain_c * u0 * 0.0;
  } else {
    /* Sum: '<S6>/Sum1' incorporates:
     *  Gain: '<S6>/Kp'
     *  Integrator: '<S6>/Limits [-5,5]'
     */
    u0 = Control_P.HEV_Param.Control.Mot.Kp * rtb_Sum_e +
      Control_X.Limits55_CSTATE_n;

    /* Saturate: '<S6>/[-5,5]' */
    if (u0 > Control_P.u5_UpperSat_m) {
      u0 = Control_P.u5_UpperSat_m;
    } else if (u0 < Control_P.u5_LowerSat_a) {
      u0 = Control_P.u5_LowerSat_a;
    }

    /* Outport: '<Root>/trqReqM' incorporates:
     *  Gain: '<S6>/Volts//Nm'
     *  Saturate: '<S6>/[-5,5]'
     */
    Control_Y.trqReqM = Control_P.VoltsNm_Gain_c * u0;
  }

  /* End of ManualSwitch: '<S12>/Select Logic' */

  /* Outport: '<Root>/Accb' incorporates:
   *  Inport: '<Root>/Acc'
   */
  Control_Y.Accb = Control_U.Acc;

  /* Outport: '<Root>/SOCb' incorporates:
   *  Inport: '<Root>/SOC'
   */
  Control_Y.SOCb = Control_U.SOC;

  /* Outport: '<Root>/wICEreq' */
  Control_Y.wICEreq = rtb_Switch;

  /* Integrator: '<S3>/Limits [0,1]' */
  /* Limited  Integrator  */
  if (tmp) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&Control_PrevZCX.Limits01_Reset_ZCE,
                       (Control_B.TmpRTBAtSelectLogicOutport1));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      Control_X.Limits01_CSTATE = Control_P.Limits01_IC;
    }
  }

  if (Control_X.Limits01_CSTATE >= Control_P.Limits01_UpperSat) {
    Control_X.Limits01_CSTATE = Control_P.Limits01_UpperSat;
  } else if (Control_X.Limits01_CSTATE <= Control_P.Limits01_LowerSat) {
    Control_X.Limits01_CSTATE = Control_P.Limits01_LowerSat;
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Engine Idle'
   */
  if (!(Control_B.TmpRTBAtSelectLogicOutport1 >= Control_P.Switch_Threshold)) {
    rtb_Switch = Control_P.EngineIdle_Value;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Switch: '<S3>/Switch'
   *  TransferFcn: '<S3>/20Hz Lowpass Filter'
   */
  rtb_Sum_i = rtb_Switch - Control_P.u0HzLowpassFilter_C_o *
    Control_X.u0HzLowpassFilter_CSTATE_f;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Gain: '<S3>/Kp'
   *  Integrator: '<S3>/Limits [0,1]'
   */
  u0 = Control_P.HEV_Param.Control.ICE.Kp * rtb_Sum_i +
    Control_X.Limits01_CSTATE;

  /* Saturate: '<S3>/[0,1]' */
  if (u0 > Control_P.u1_UpperSat) {
    /* Outport: '<Root>/Thr' */
    Control_Y.Thr = Control_P.u1_UpperSat;
  } else if (u0 < Control_P.u1_LowerSat) {
    /* Outport: '<Root>/Thr' */
    Control_Y.Thr = Control_P.u1_LowerSat;
  } else {
    /* Outport: '<Root>/Thr' */
    Control_Y.Thr = u0;
  }

  /* End of Saturate: '<S3>/[0,1]' */

  /* Gain: '<S3>/Ki' */
  Control_B.Ki = Control_P.HEV_Param.Control.ICE.Ki * rtb_Sum_i;

  /* Gain: '<S10>/Gen RPM to V' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Inport: '<Root>/wb'
   */
  Control_B.GenRPMtoV = Control_P.Gain1_Gain * Control_U.w_n *
    Control_P.GenRPMtoV_Gain;

  /* Gain: '<S10>/Ki' */
  Control_B.Ki_p = Control_P.HEV_Param.Control.Gen.Ki * rtb_Sum;

  /* Gain: '<S6>/Ki' */
  Control_B.Ki_m = Control_P.HEV_Param.Control.Mot.Ki * rtb_Sum_e;

  /* Gain: '<S6>/Mot RPM to V' incorporates:
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/w'
   */
  Control_B.MotRPMtoV = Control_P.Gain_Gain * Control_U.w *
    Control_P.MotRPMtoV_Gain;

  /* RateTransition generated from: '<S1>/Mode Logic' incorporates:
   *  Inport: '<Root>/SOC'
   */
  if (tmp_0 && (Control_M->Timing.RateInteraction.TID1_2 == 1)) {
    Control_DW.SOC_Buffer = Control_U.SOC;
  }

  /* Gain: '<S7>/Gain' incorporates:
   *  Integrator: '<S7>/Integrator'
   */
  Control_B.Gain = 1.0 / Control_P.HEV_Param.ICE.sensor_time_constant *
    Control_X.Integrator_CSTATE;

  /* Sum: '<S7>/Sum' incorporates:
   *  Inport: '<Root>/vSpd'
   */
  Control_B.Sum = Control_U.vSpd - Control_B.Gain;

  /* RateTransition generated from: '<S1>/Mode Logic' */
  if (tmp_0 && (Control_M->Timing.RateInteraction.TID1_2 == 1)) {
    Control_DW.TmpRTBAtModeLogicInport1_Buffer = Control_B.Gain;

    /* RateTransition generated from: '<S1>/Mode Logic' */
    Control_B.TmpRTBAtModeLogicOutport2 =
      Control_DW.TmpRTBAtModeLogicOutport2_Buffe;

    /* RateTransition generated from: '<S1>/Mode Logic' incorporates:
     *  Inport: '<Root>/wEng'
     */
    Control_DW.wEng_Buffer = Control_U.wEng;
  }

  if (rtmIsMajorTimeStep(Control_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Control_M->rtwLogInfo, (Control_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Control_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Control_M)!=-1) &&
          !((rtmGetTFinal(Control_M)-(((Control_M->Timing.clockTick1+
               Control_M->Timing.clockTickH1* 4294967296.0)) * 1.0E-5)) >
            (((Control_M->Timing.clockTick1+Control_M->Timing.clockTickH1*
               4294967296.0)) * 1.0E-5) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Control_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Control_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Control_M->Timing.clockTick0)) {
      ++Control_M->Timing.clockTickH0;
    }

    Control_M->Timing.t[0] = rtsiGetSolverStopTime(&Control_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Control_M->Timing.clockTick1++;
    if (!Control_M->Timing.clockTick1) {
      Control_M->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Control_derivatives(void)
{
  XDot_Control_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_Control_T *) Control_M->derivs);

  /* Derivatives for TransferFcn: '<S9>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE = Control_P.u0HzLowpassFilter_A *
    Control_X.u0HzLowpassFilter_CSTATE;
  _rtXdot->u0HzLowpassFilter_CSTATE += Control_B.TmpRTBAtModeLogicOutport2;

  /* Derivatives for Integrator: '<S10>/Limits [-5,5]' */
  lsat = (Control_X.Limits55_CSTATE <= Control_P.Limits55_LowerSat);
  usat = (Control_X.Limits55_CSTATE >= Control_P.Limits55_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Control_B.Ki_p > 0.0)) || (usat &&
       (Control_B.Ki_p < 0.0))) {
    _rtXdot->Limits55_CSTATE = Control_B.Ki_p;
  } else {
    /* in saturation */
    _rtXdot->Limits55_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S10>/Limits [-5,5]' */

  /* Derivatives for TransferFcn: '<S10>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_g = Control_P.u0HzLowpassFilter_A_o *
    Control_X.u0HzLowpassFilter_CSTATE_g;
  _rtXdot->u0HzLowpassFilter_CSTATE_g += Control_B.GenRPMtoV;

  /* Derivatives for Integrator: '<S6>/Limits [-5,5]' */
  lsat = (Control_X.Limits55_CSTATE_n <= Control_P.Limits55_LowerSat_c);
  usat = (Control_X.Limits55_CSTATE_n >= Control_P.Limits55_UpperSat_g);
  if (((!lsat) && (!usat)) || (lsat && (Control_B.Ki_m > 0.0)) || (usat &&
       (Control_B.Ki_m < 0.0))) {
    _rtXdot->Limits55_CSTATE_n = Control_B.Ki_m;
  } else {
    /* in saturation */
    _rtXdot->Limits55_CSTATE_n = 0.0;
  }

  /* End of Derivatives for Integrator: '<S6>/Limits [-5,5]' */

  /* Derivatives for TransferFcn: '<S6>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_l = Control_P.u0HzLowpassFilter_A_b *
    Control_X.u0HzLowpassFilter_CSTATE_l;
  _rtXdot->u0HzLowpassFilter_CSTATE_l += Control_B.MotRPMtoV;

  /* Derivatives for Integrator: '<S3>/Limits [0,1]' */
  lsat = (Control_X.Limits01_CSTATE <= Control_P.Limits01_LowerSat);
  usat = (Control_X.Limits01_CSTATE >= Control_P.Limits01_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Control_B.Ki > 0.0)) || (usat &&
       (Control_B.Ki < 0.0))) {
    _rtXdot->Limits01_CSTATE = Control_B.Ki;
  } else {
    /* in saturation */
    _rtXdot->Limits01_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S3>/Limits [0,1]' */

  /* Derivatives for TransferFcn: '<S3>/20Hz Lowpass Filter' incorporates:
   *  Inport: '<Root>/wEng'
   */
  _rtXdot->u0HzLowpassFilter_CSTATE_f = Control_P.u0HzLowpassFilter_A_a *
    Control_X.u0HzLowpassFilter_CSTATE_f;
  _rtXdot->u0HzLowpassFilter_CSTATE_f += Control_U.wEng;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = Control_B.Sum;
}

/* Model step function for TID2 */
void Control_step2(void)               /* Sample time: [0.1s, 0.0s] */
{
  /* RateTransition generated from: '<S1>/Mode Logic' */
  Control_B.TmpRTBAtModeLogicInport1 =
    Control_DW.TmpRTBAtModeLogicInport1_Buffer;

  /* Chart: '<S1>/Mode Logic' incorporates:
   *  Constant: '<S1>/Constant'
   *  RateTransition generated from: '<S1>/Mode Logic'
   * */
  /* Gateway: Control/Mode Logic */
  /* During: Control/Mode Logic */
  if (Control_DW.is_active_c3_Control == 0) {
    /* Entry: Control/Mode Logic */
    Control_DW.is_active_c3_Control = 1U;

    /* Entry Internal: Control/Mode Logic */
    /* Transition: '<S5>:18' */
    Control_DW.is_c3_Control = Control_IN_Motion_mode;

    /* Entry Internal 'Motion_mode': '<S5>:9' */
    /* Transition: '<S5>:11' */
    Control_DW.is_Motion_mode = Control_IN_Start_mode;

    /* RateTransition generated from: '<S1>/Mode Logic' */
    /* Entry 'Start_mode': '<S5>:4' */
    Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;

    /* RateTransition generated from: '<S8>/Select Logic' */
    Control_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;
  } else if (Control_DW.is_c3_Control == Control_IN_Brake_mode) {
    /* RateTransition generated from: '<S1>/Mode Logic' */
    Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;

    /* RateTransition generated from: '<S8>/Select Logic' */
    Control_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;

    /* During 'Brake_mode': '<S5>:5' */
    if (Control_P.Constant_Value_i < 0.05) {
      /* Transition: '<S5>:17' */
      Control_DW.is_c3_Control = Control_IN_Motion_mode;

      /* Entry Internal 'Motion_mode': '<S5>:9' */
      /* Transition: '<S5>:11' */
      Control_DW.is_Motion_mode = Control_IN_Start_mode;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      /* Entry 'Start_mode': '<S5>:4' */
      Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;
    }

    /* During 'Motion_mode': '<S5>:9' */
  } else if (Control_P.Constant_Value_i >= 0.05) {
    /* Transition: '<S5>:16' */
    /* Exit Internal 'Motion_mode': '<S5>:9' */
    /* Exit Internal 'Normal_mode': '<S5>:1' */
    /* Exit Internal 'Cruise_mode': '<S5>:2' */
    Control_DW.is_Cruise_mode = Control_IN_NO_ACTIVE_CHILD;
    Control_DW.is_Normal_mode = Control_IN_NO_ACTIVE_CHILD;
    Control_DW.is_Motion_mode = Control_IN_NO_ACTIVE_CHILD;
    Control_DW.is_c3_Control = Control_IN_Brake_mode;

    /* RateTransition generated from: '<S1>/Mode Logic' */
    /* Entry 'Brake_mode': '<S5>:5' */
    Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;

    /* RateTransition generated from: '<S8>/Select Logic' */
    Control_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;
  } else if (Control_DW.is_Motion_mode == Control_IN_Normal_mode) {
    /* RateTransition generated from: '<S8>/Select Logic' */
    Control_DW.TmpRTBAtSelectLogicOutport1_Buf = 1.0;

    /* During 'Normal_mode': '<S5>:1' */
    if (Control_DW.wEng_Buffer <= Control_EngOffRPM) {
      /* Transition: '<S5>:12' */
      /* Exit Internal 'Normal_mode': '<S5>:1' */
      /* Exit Internal 'Cruise_mode': '<S5>:2' */
      Control_DW.is_Cruise_mode = Control_IN_NO_ACTIVE_CHILD;
      Control_DW.is_Normal_mode = Control_IN_NO_ACTIVE_CHILD;
      Control_DW.is_Motion_mode = Control_IN_Start_mode;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      /* Entry 'Start_mode': '<S5>:4' */
      Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;

      /* RateTransition generated from: '<S8>/Select Logic' */
      Control_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;
    } else if (Control_DW.is_Normal_mode == Control_IN_Accelerate_mode) {
      /* RateTransition generated from: '<S1>/Mode Logic' */
      Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;

      /* During 'Accelerate_mode': '<S5>:3' */
      if (((Control_B.TmpRTBAtModeLogicInport1 > 0.998 * Control_oldspeed()) &&
           (Control_B.TmpRTBAtModeLogicInport1 < 1.002 * Control_oldspeed())) ||
          (Control_DW.SOC_Buffer <= 30.0)) {
        /* Transition: '<S5>:10' */
        Control_DW.is_Normal_mode = Control_IN_Cruise_mode;

        /* Entry 'Cruise_mode': '<S5>:2' */
        /* Entry Internal 'Cruise_mode': '<S5>:2' */
        /* Transition: '<S5>:13' */
        Control_DW.is_Cruise_mode = Control_IN_charge;

        /* RateTransition generated from: '<S1>/Mode Logic' */
        /* Entry 'charge': '<S5>:8' */
        Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;
      }

      /* During 'Cruise_mode': '<S5>:2' */
    } else if (((Control_B.TmpRTBAtModeLogicInport1 < 0.998 * Control_oldspeed())
                || (Control_B.TmpRTBAtModeLogicInport1 > 1.002 *
                    Control_oldspeed())) && (Control_DW.SOC_Buffer > 30.0)) {
      /* Transition: '<S5>:15' */
      /* Exit Internal 'Cruise_mode': '<S5>:2' */
      Control_DW.is_Cruise_mode = Control_IN_NO_ACTIVE_CHILD;
      Control_DW.is_Normal_mode = Control_IN_Accelerate_mode;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      /* Entry 'Accelerate_mode': '<S5>:3' */
      Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;
    } else if (Control_DW.is_Cruise_mode == Control_IN_charge) {
      /* RateTransition generated from: '<S1>/Mode Logic' */
      Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;

      /* During 'charge': '<S5>:8' */
      if (Control_DW.SOC_Buffer > 99.9) {
        /* Transition: '<S5>:19' */
        Control_DW.is_Cruise_mode = Control_IN_nocharge;

        /* RateTransition generated from: '<S1>/Mode Logic' */
        /* Entry 'nocharge': '<S5>:7' */
        Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;
      }
    } else {
      /* RateTransition generated from: '<S1>/Mode Logic' */
      Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;

      /* During 'nocharge': '<S5>:7' */
      if (Control_DW.SOC_Buffer < 30.0) {
        /* Transition: '<S5>:20' */
        Control_DW.is_Cruise_mode = Control_IN_charge;

        /* RateTransition generated from: '<S1>/Mode Logic' */
        /* Entry 'charge': '<S5>:8' */
        Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;
      }
    }
  } else {
    /* RateTransition generated from: '<S1>/Mode Logic' */
    Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;

    /* RateTransition generated from: '<S8>/Select Logic' */
    Control_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;

    /* During 'Start_mode': '<S5>:4' */
    if (Control_DW.wEng_Buffer > Control_EngOnRPM) {
      /* Transition: '<S5>:21' */
      Control_DW.is_Motion_mode = Control_IN_Normal_mode;

      /* RateTransition generated from: '<S8>/Select Logic' */
      /* Entry 'Normal_mode': '<S5>:1' */
      Control_DW.TmpRTBAtSelectLogicOutport1_Buf = 1.0;

      /* Entry Internal 'Normal_mode': '<S5>:1' */
      /* Transition: '<S5>:14' */
      Control_DW.is_Normal_mode = Control_IN_Accelerate_mode;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      /* Entry 'Accelerate_mode': '<S5>:3' */
      Control_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;
    }
  }

  /* End of Chart: '<S1>/Mode Logic' */

  /* ManualSwitch: '<S8>/Select Logic' */
  if (Control_P.SelectLogic_CurrentSetting_n == 1) {
    /* RateTransition generated from: '<S8>/Select Logic' incorporates:
     *  Constant: '<S8>/Constant'
     */
    Control_DW.TmpRTBAtSelectLogicOutport1_Buf = Control_P.Constant_Value;
  }

  /* End of ManualSwitch: '<S8>/Select Logic' */
}

/* Model initialize function */
void Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Control_M, 0,
                sizeof(RT_MODEL_Control_T));

  /* Set task counter limit used by the static main program */
  (Control_M)->Timing.TaskCounters.cLimit[0] = 1;
  (Control_M)->Timing.TaskCounters.cLimit[1] = 1;
  (Control_M)->Timing.TaskCounters.cLimit[2] = 10000;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Control_M->solverInfo, &Control_M->Timing.simTimeStep);
    rtsiSetTPtr(&Control_M->solverInfo, &rtmGetTPtr(Control_M));
    rtsiSetStepSizePtr(&Control_M->solverInfo, &Control_M->Timing.stepSize0);
    rtsiSetdXPtr(&Control_M->solverInfo, &Control_M->derivs);
    rtsiSetContStatesPtr(&Control_M->solverInfo, (real_T **)
                         &Control_M->contStates);
    rtsiSetNumContStatesPtr(&Control_M->solverInfo,
      &Control_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Control_M->solverInfo,
      &Control_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Control_M->solverInfo,
      &Control_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Control_M->solverInfo,
      &Control_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Control_M->solverInfo, (boolean_T**)
      &Control_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Control_M->solverInfo, (&rtmGetErrorStatus(Control_M)));
    rtsiSetRTModelPtr(&Control_M->solverInfo, Control_M);
  }

  rtsiSetSimTimeStep(&Control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Control_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Control_M->solverInfo, false);
  Control_M->intgData.y = Control_M->odeY;
  Control_M->intgData.f[0] = Control_M->odeF[0];
  Control_M->intgData.f[1] = Control_M->odeF[1];
  Control_M->intgData.f[2] = Control_M->odeF[2];
  Control_M->contStates = ((X_Control_T *) &Control_X);
  Control_M->contStateDisabled = ((XDis_Control_T *) &Control_XDis);
  Control_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Control_M->solverInfo, (void *)&Control_M->intgData);
  rtsiSetSolverName(&Control_M->solverInfo,"ode3");
  rtmSetTPtr(Control_M, &Control_M->Timing.tArray[0]);
  rtmSetTFinal(Control_M, 195.00000000000003);
  Control_M->Timing.stepSize0 = 1.0E-5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Control_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Control_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Control_M->rtwLogInfo, (NULL));
    rtliSetLogT(Control_M->rtwLogInfo, "tout");
    rtliSetLogX(Control_M->rtwLogInfo, "");
    rtliSetLogXFinal(Control_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Control_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Control_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Control_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Control_M->rtwLogInfo, 1);
    rtliSetLogY(Control_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Control_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Control_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Control_B), 0,
                sizeof(B_Control_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Control_X, 0,
                  sizeof(X_Control_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&Control_XDis, 0,
                  sizeof(XDis_Control_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Control_DW, 0,
                sizeof(DW_Control_T));

  /* external inputs */
  (void)memset(&Control_U, 0, sizeof(ExtU_Control_T));

  /* external outputs */
  (void)memset(&Control_Y, 0, sizeof(ExtY_Control_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Control_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Control_M), Control_M->Timing.stepSize0, (&rtmGetErrorStatus(Control_M)));

  /* Start for RateTransition generated from: '<S8>/Select Logic' */
  Control_B.TmpRTBAtSelectLogicOutport1 =
    Control_P.TmpRTBAtSelectLogicOutport1_Ini;

  /* Start for RateTransition generated from: '<S1>/Mode Logic' */
  Control_B.TmpRTBAtModeLogicOutport2 =
    Control_P.TmpRTBAtModeLogicOutport2_Initi;
  Control_PrevZCX.Limits55_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Control_PrevZCX.Limits01_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for TransferFcn: '<S9>/20Hz Lowpass Filter' */
  Control_X.u0HzLowpassFilter_CSTATE = 0.0;

  /* InitializeConditions for RateTransition generated from: '<S8>/Select Logic' */
  Control_DW.TmpRTBAtSelectLogicOutport1_Buf =
    Control_P.TmpRTBAtSelectLogicOutport1_Ini;

  /* InitializeConditions for Integrator: '<S10>/Limits [-5,5]' */
  Control_X.Limits55_CSTATE = Control_P.Limits55_IC;

  /* InitializeConditions for TransferFcn: '<S10>/20Hz Lowpass Filter' */
  Control_X.u0HzLowpassFilter_CSTATE_g = 0.0;

  /* InitializeConditions for Integrator: '<S6>/Limits [-5,5]' */
  Control_X.Limits55_CSTATE_n = Control_P.Limits55_IC_h;

  /* InitializeConditions for TransferFcn: '<S6>/20Hz Lowpass Filter' */
  Control_X.u0HzLowpassFilter_CSTATE_l = 0.0;

  /* InitializeConditions for Integrator: '<S3>/Limits [0,1]' */
  Control_X.Limits01_CSTATE = Control_P.Limits01_IC;

  /* InitializeConditions for TransferFcn: '<S3>/20Hz Lowpass Filter' */
  Control_X.u0HzLowpassFilter_CSTATE_f = 0.0;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  Control_X.Integrator_CSTATE = Control_P.SensorDynamics_x_initial;

  /* InitializeConditions for RateTransition generated from: '<S1>/Mode Logic' */
  Control_DW.TmpRTBAtModeLogicOutport2_Buffe =
    Control_P.TmpRTBAtModeLogicOutport2_Initi;

  /* SystemInitialize for Chart: '<S1>/Mode Logic' */
  memset(&Control_DW.speed_buffer[0], 0, 21U * sizeof(real_T));
  Control_DW.is_active_c3_Control = 0U;
  Control_DW.is_c3_Control = Control_IN_NO_ACTIVE_CHILD;
  Control_DW.is_Motion_mode = Control_IN_NO_ACTIVE_CHILD;
  Control_DW.is_Normal_mode = Control_IN_NO_ACTIVE_CHILD;
  Control_DW.is_Cruise_mode = Control_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void Control_terminate(void)
{
  /* (no terminate code required) */
}
