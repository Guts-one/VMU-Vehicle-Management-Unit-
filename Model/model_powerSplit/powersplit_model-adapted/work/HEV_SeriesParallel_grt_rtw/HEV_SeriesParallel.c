/*
 * HEV_SeriesParallel.c
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "HEV_SeriesParallel".
 *
 * Model version              : 11.0
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Tue Mar 24 13:34:11 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "HEV_SeriesParallel.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_look.h"
#include "rt_look2d_normal.h"
#include <stddef.h>
#include "HEV_SeriesParallel_private.h"
#include "zero_crossing_types.h"
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S1>/Mode Logic' */
#define HEV_SeriesPa_IN_Accelerate_mode ((uint8_T)1U)
#define HEV_SeriesPa_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define HEV_SeriesParall_IN_Cruise_mode ((uint8_T)2U)
#define HEV_SeriesParall_IN_Motion_mode ((uint8_T)2U)
#define HEV_SeriesParall_IN_Normal_mode ((uint8_T)1U)
#define HEV_SeriesParalle_IN_Brake_mode ((uint8_T)1U)
#define HEV_SeriesParalle_IN_Start_mode ((uint8_T)2U)
#define HEV_SeriesParallel_EngOffRPM   (790.0)
#define HEV_SeriesParallel_EngOnRPM    (800.0)
#define HEV_SeriesParallel_IN_charge   ((uint8_T)1U)
#define HEV_SeriesParallel_IN_nocharge ((uint8_T)2U)

/* Block signals (default storage) */
B_HEV_SeriesParallel_T HEV_SeriesParallel_B;

/* Continuous states */
X_HEV_SeriesParallel_T HEV_SeriesParallel_X;

/* Disabled State Vector */
XDis_HEV_SeriesParallel_T HEV_SeriesParallel_XDis;

/* Block states (default storage) */
DW_HEV_SeriesParallel_T HEV_SeriesParallel_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_HEV_SeriesParallel_T HEV_SeriesParallel_PrevZCX;

/* Mass Matrices */
MassMatrix_HEV_SeriesParallel_T HEV_SeriesParallel_MassMatrix;

/* Real-time model */
static RT_MODEL_HEV_SeriesParallel_T HEV_SeriesParallel_M_;
RT_MODEL_HEV_SeriesParallel_T *const HEV_SeriesParallel_M =
  &HEV_SeriesParallel_M_;

/* Forward declaration for local functions */
static real_T HEV_SeriesParallel_oldspeed(void);
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

/* Projection for root system: '<Root>' */
void HEV_SeriesParallel_projection(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T tmp_0[16];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[5];
  boolean_T tmp;

  /* Projection for SimscapeExecutionBlock: '<S71>/STATE_1' */
  simulationData = (NeslSimulationData *)HEV_SeriesParallel_DW.STATE_1_SimData;
  time = HEV_SeriesParallel_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 58;
  simulationData->mData->mContStates.mX =
    &HEV_SeriesParallel_X.HEV_SeriesParallelElectricalGen[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &HEV_SeriesParallel_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 13;
  simulationData->mData->mModeVector.mX = &HEV_SeriesParallel_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (HEV_SeriesParallel_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&HEV_SeriesParallel_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&HEV_SeriesParallel_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = HEV_SeriesParallel_B.INPUT_1_1_1[0];
  tmp_0[1] = HEV_SeriesParallel_B.INPUT_1_1_1[1];
  tmp_0[2] = HEV_SeriesParallel_B.INPUT_1_1_1[2];
  tmp_0[3] = HEV_SeriesParallel_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = HEV_SeriesParallel_B.INPUT_2_1_1[0];
  tmp_0[5] = HEV_SeriesParallel_B.INPUT_2_1_1[1];
  tmp_0[6] = HEV_SeriesParallel_B.INPUT_2_1_1[2];
  tmp_0[7] = HEV_SeriesParallel_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = HEV_SeriesParallel_B.INPUT_3_1_1[0];
  tmp_0[9] = HEV_SeriesParallel_B.INPUT_3_1_1[1];
  tmp_0[10] = HEV_SeriesParallel_B.INPUT_3_1_1[2];
  tmp_0[11] = HEV_SeriesParallel_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = HEV_SeriesParallel_B.INPUT_4_1_1[0];
  tmp_0[13] = HEV_SeriesParallel_B.INPUT_4_1_1[1];
  tmp_0[14] = HEV_SeriesParallel_B.INPUT_4_1_1[2];
  tmp_0[15] = HEV_SeriesParallel_B.INPUT_4_1_1[3];
  tmp_1[4] = 16;
  simulationData->mData->mInputValues.mN = 16;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 5;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  diagnosticManager = (NeuDiagnosticManager *)
    HEV_SeriesParallel_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    HEV_SeriesParallel_DW.STATE_1_Simulator, NESL_SIM_PROJECTION, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(HEV_SeriesParallel_M, msg);
    }
  }

  /* End of Projection for SimscapeExecutionBlock: '<S71>/STATE_1' */
}

/* ForcingFunction for root system: '<Root>' */
void HEV_SeriesParallel_forcingfunction(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_HEV_SeriesParallel_T *_rtXdot;
  char *msg;
  real_T tmp[16];
  real_T time;
  int_T tmp_0[5];
  int_T iS;
  uint32_T ri;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_HEV_SeriesParallel_T *) HEV_SeriesParallel_M->derivs);

  /* ForcingFunction for Integrator: '<S81>/Limits [-5,5]' */
  lsat = (HEV_SeriesParallel_X.Limits55_CSTATE <=
          HEV_SeriesParallel_P.Limits55_LowerSat);
  usat = (HEV_SeriesParallel_X.Limits55_CSTATE >=
          HEV_SeriesParallel_P.Limits55_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (HEV_SeriesParallel_B.Ki_b > 0.0)) ||
      (usat && (HEV_SeriesParallel_B.Ki_b < 0.0))) {
    _rtXdot->Limits55_CSTATE = HEV_SeriesParallel_B.Ki_b;
  } else {
    /* in saturation */
    _rtXdot->Limits55_CSTATE = 0.0;
  }

  /* End of ForcingFunction for Integrator: '<S81>/Limits [-5,5]' */

  /* ForcingFunction for TransferFcn: '<S81>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE += HEV_SeriesParallel_P.u0HzLowpassFilter_A *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE;
  _rtXdot->u0HzLowpassFilter_CSTATE += HEV_SeriesParallel_B.OUTPUT_1_0[25];

  /* ForcingFunction for StateSpace: '<S76>/State Space' */
  _rtXdot->StateSpace_CSTATE = 0.0;
  for (ri = HEV_SeriesParallel_P.StateSpace_A_jc[0U]; ri <
       HEV_SeriesParallel_P.StateSpace_A_jc[1U]; ri++) {
    _rtXdot->StateSpace_CSTATE += HEV_SeriesParallel_P.StateSpace_A_pr *
      HEV_SeriesParallel_X.StateSpace_CSTATE;
  }

  for (ri = HEV_SeriesParallel_P.StateSpace_B_jc[0U]; ri <
       HEV_SeriesParallel_P.StateSpace_B_jc[1U]; ri++) {
    _rtXdot->StateSpace_CSTATE += HEV_SeriesParallel_P.StateSpace_B_pr *
      HEV_SeriesParallel_B.wEng;
  }

  /* End of ForcingFunction for StateSpace: '<S76>/State Space' */

  /* ForcingFunction for TransferFcn: '<S16>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_o = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE_o +=
    HEV_SeriesParallel_P.u0HzLowpassFilter_A_c *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_o;
  _rtXdot->u0HzLowpassFilter_CSTATE_o +=
    HEV_SeriesParallel_B.TmpRTBAtModeLogicOutport2;

  /* ForcingFunction for Integrator: '<S17>/Limits [-5,5]' */
  lsat = (HEV_SeriesParallel_X.Limits55_CSTATE_f <=
          HEV_SeriesParallel_P.Limits55_LowerSat_d);
  usat = (HEV_SeriesParallel_X.Limits55_CSTATE_f >=
          HEV_SeriesParallel_P.Limits55_UpperSat_f);
  if (((!lsat) && (!usat)) || (lsat && (HEV_SeriesParallel_B.Ki_p > 0.0)) ||
      (usat && (HEV_SeriesParallel_B.Ki_p < 0.0))) {
    _rtXdot->Limits55_CSTATE_f = HEV_SeriesParallel_B.Ki_p;
  } else {
    /* in saturation */
    _rtXdot->Limits55_CSTATE_f = 0.0;
  }

  /* End of ForcingFunction for Integrator: '<S17>/Limits [-5,5]' */

  /* ForcingFunction for TransferFcn: '<S17>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_g = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE_g +=
    HEV_SeriesParallel_P.u0HzLowpassFilter_A_o *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_g;
  _rtXdot->u0HzLowpassFilter_CSTATE_g += HEV_SeriesParallel_B.GenRPMtoV;

  /* ForcingFunction for Integrator: '<S13>/Limits [-5,5]' */
  lsat = (HEV_SeriesParallel_X.Limits55_CSTATE_n <=
          HEV_SeriesParallel_P.Limits55_LowerSat_c);
  usat = (HEV_SeriesParallel_X.Limits55_CSTATE_n >=
          HEV_SeriesParallel_P.Limits55_UpperSat_g);
  if (((!lsat) && (!usat)) || (lsat && (HEV_SeriesParallel_B.Ki_m > 0.0)) ||
      (usat && (HEV_SeriesParallel_B.Ki_m < 0.0))) {
    _rtXdot->Limits55_CSTATE_n = HEV_SeriesParallel_B.Ki_m;
  } else {
    /* in saturation */
    _rtXdot->Limits55_CSTATE_n = 0.0;
  }

  /* End of ForcingFunction for Integrator: '<S13>/Limits [-5,5]' */

  /* ForcingFunction for TransferFcn: '<S13>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_l = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE_l +=
    HEV_SeriesParallel_P.u0HzLowpassFilter_A_b *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_l;
  _rtXdot->u0HzLowpassFilter_CSTATE_l += HEV_SeriesParallel_B.MotRPMtoV;

  /* ForcingFunction for Integrator: '<S10>/Limits [0,1]' */
  lsat = (HEV_SeriesParallel_X.Limits01_CSTATE <=
          HEV_SeriesParallel_P.Limits01_LowerSat);
  usat = (HEV_SeriesParallel_X.Limits01_CSTATE >=
          HEV_SeriesParallel_P.Limits01_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (HEV_SeriesParallel_B.Ki > 0.0)) || (usat
       && (HEV_SeriesParallel_B.Ki < 0.0))) {
    _rtXdot->Limits01_CSTATE = HEV_SeriesParallel_B.Ki;
  } else {
    /* in saturation */
    _rtXdot->Limits01_CSTATE = 0.0;
  }

  /* End of ForcingFunction for Integrator: '<S10>/Limits [0,1]' */

  /* ForcingFunction for TransferFcn: '<S10>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_f = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE_f +=
    HEV_SeriesParallel_P.u0HzLowpassFilter_A_a *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_f;
  _rtXdot->u0HzLowpassFilter_CSTATE_f += HEV_SeriesParallel_B.StateSpace;

  /* ForcingFunction for SimscapeInputBlock: '<S71>/INPUT_4_1_1' */
  _rtXdot->HEV_SeriesParallelVehicleSimuli = (HEV_SeriesParallel_B.Gain -
    HEV_SeriesParallel_X.HEV_SeriesParallelVehicleSimuli) * 20.0;

  /* ForcingFunction for SimscapeExecutionBlock: '<S71>/STATE_1' */
  simulationData = (NeslSimulationData *)HEV_SeriesParallel_DW.STATE_1_SimData;
  time = HEV_SeriesParallel_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 58;
  simulationData->mData->mContStates.mX =
    &HEV_SeriesParallel_X.HEV_SeriesParallelElectricalGen[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &HEV_SeriesParallel_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 13;
  simulationData->mData->mModeVector.mX = &HEV_SeriesParallel_DW.STATE_1_Modes[0];
  lsat = false;
  simulationData->mData->mFoundZcEvents = lsat;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (HEV_SeriesParallel_M);
  lsat = false;
  simulationData->mData->mIsSolverAssertCheck = lsat;
  simulationData->mData->mIsSolverCheckingCIC = false;
  lsat = rtsiIsSolverComputingJacobian(&HEV_SeriesParallel_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = lsat;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&HEV_SeriesParallel_M->solverInfo);
  tmp_0[0] = 0;
  tmp[0] = HEV_SeriesParallel_B.INPUT_1_1_1[0];
  tmp[1] = HEV_SeriesParallel_B.INPUT_1_1_1[1];
  tmp[2] = HEV_SeriesParallel_B.INPUT_1_1_1[2];
  tmp[3] = HEV_SeriesParallel_B.INPUT_1_1_1[3];
  tmp_0[1] = 4;
  tmp[4] = HEV_SeriesParallel_B.INPUT_2_1_1[0];
  tmp[5] = HEV_SeriesParallel_B.INPUT_2_1_1[1];
  tmp[6] = HEV_SeriesParallel_B.INPUT_2_1_1[2];
  tmp[7] = HEV_SeriesParallel_B.INPUT_2_1_1[3];
  tmp_0[2] = 8;
  tmp[8] = HEV_SeriesParallel_B.INPUT_3_1_1[0];
  tmp[9] = HEV_SeriesParallel_B.INPUT_3_1_1[1];
  tmp[10] = HEV_SeriesParallel_B.INPUT_3_1_1[2];
  tmp[11] = HEV_SeriesParallel_B.INPUT_3_1_1[3];
  tmp_0[3] = 12;
  tmp[12] = HEV_SeriesParallel_B.INPUT_4_1_1[0];
  tmp[13] = HEV_SeriesParallel_B.INPUT_4_1_1[1];
  tmp[14] = HEV_SeriesParallel_B.INPUT_4_1_1[2];
  tmp[15] = HEV_SeriesParallel_B.INPUT_4_1_1[3];
  tmp_0[4] = 16;
  simulationData->mData->mInputValues.mN = 16;
  simulationData->mData->mInputValues.mX = &tmp[0];
  simulationData->mData->mInputOffsets.mN = 5;
  simulationData->mData->mInputOffsets.mX = &tmp_0[0];
  simulationData->mData->mDx.mN = 58;
  simulationData->mData->mDx.mX = &_rtXdot->HEV_SeriesParallelElectricalGen[0];
  diagnosticManager = (NeuDiagnosticManager *)
    HEV_SeriesParallel_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  iS = ne_simulator_method((NeslSimulator *)
    HEV_SeriesParallel_DW.STATE_1_Simulator, NESL_SIM_FORCINGFUNCTION,
    simulationData, diagnosticManager);
  if (iS != 0) {
    lsat = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
    if (lsat) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(HEV_SeriesParallel_M, msg);
    }
  }

  /* End of ForcingFunction for SimscapeExecutionBlock: '<S71>/STATE_1' */

  /* ForcingFunction for Integrator: '<S43>/Initial charge Ah0' */
  _rtXdot->InitialchargeAh0_CSTATE = HEV_SeriesParallel_B.OUTPUT_1_0[7];

  /* ForcingFunction for Integrator: '<S14>/Integrator' */
  _rtXdot->Integrator_CSTATE = HEV_SeriesParallel_B.Sum_c;

  /* ForcingFunction for Integrator: '<S80>/Cumulative L' */
  _rtXdot->CumulativeL_CSTATE = HEV_SeriesParallel_B.m3toL;

  /* ForcingFunction for Integrator: '<S80>/Cumulative Gal' */
  _rtXdot->CumulativeGal_CSTATE = HEV_SeriesParallel_B.m3togal;

  /* ForcingFunction for Integrator: '<S80>/Cumulative Distance Km' */
  _rtXdot->CumulativeDistanceKm_CSTATE = HEV_SeriesParallel_B.KphtoKps;
}

/* MassMatrix for root system: '<Root>' */
void HEV_SeriesParallel_massmatrix(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T tmp_0[16];
  real_T time;
  real_T *tmp_2;
  real_T *tmp_3;
  int32_T tmp_4;
  int_T tmp_1[5];
  boolean_T tmp;

  /* MassMatrix for SimscapeExecutionBlock: '<S71>/STATE_1' */
  simulationData = (NeslSimulationData *)HEV_SeriesParallel_DW.STATE_1_SimData;
  time = HEV_SeriesParallel_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 58;
  simulationData->mData->mContStates.mX =
    &HEV_SeriesParallel_X.HEV_SeriesParallelElectricalGen[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &HEV_SeriesParallel_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 13;
  simulationData->mData->mModeVector.mX = &HEV_SeriesParallel_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (HEV_SeriesParallel_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&HEV_SeriesParallel_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&HEV_SeriesParallel_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = HEV_SeriesParallel_B.INPUT_1_1_1[0];
  tmp_0[1] = HEV_SeriesParallel_B.INPUT_1_1_1[1];
  tmp_0[2] = HEV_SeriesParallel_B.INPUT_1_1_1[2];
  tmp_0[3] = HEV_SeriesParallel_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = HEV_SeriesParallel_B.INPUT_2_1_1[0];
  tmp_0[5] = HEV_SeriesParallel_B.INPUT_2_1_1[1];
  tmp_0[6] = HEV_SeriesParallel_B.INPUT_2_1_1[2];
  tmp_0[7] = HEV_SeriesParallel_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = HEV_SeriesParallel_B.INPUT_3_1_1[0];
  tmp_0[9] = HEV_SeriesParallel_B.INPUT_3_1_1[1];
  tmp_0[10] = HEV_SeriesParallel_B.INPUT_3_1_1[2];
  tmp_0[11] = HEV_SeriesParallel_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = HEV_SeriesParallel_B.INPUT_4_1_1[0];
  tmp_0[13] = HEV_SeriesParallel_B.INPUT_4_1_1[1];
  tmp_0[14] = HEV_SeriesParallel_B.INPUT_4_1_1[2];
  tmp_0[15] = HEV_SeriesParallel_B.INPUT_4_1_1[3];
  tmp_1[4] = 16;
  simulationData->mData->mInputValues.mN = 16;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 5;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  tmp_2 = HEV_SeriesParallel_M->massMatrixPr;
  tmp_3 = double_pointer_shift(tmp_2,
    HEV_SeriesParallel_DW.STATE_1_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 20;
  simulationData->mData->mMassMatrixPr.mX = tmp_3;
  diagnosticManager = (NeuDiagnosticManager *)
    HEV_SeriesParallel_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_4 = ne_simulator_method((NeslSimulator *)
    HEV_SeriesParallel_DW.STATE_1_Simulator, NESL_SIM_MASSMATRIX, simulationData,
    diagnosticManager);
  if (tmp_4 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(HEV_SeriesParallel_M, msg);
    }
  }

  /* End of MassMatrix for SimscapeExecutionBlock: '<S71>/STATE_1' */
}

void local_evaluateMassMatrix(RTWSolverInfo *si, real_T *Mdest )
{
  /* Refresh global mass matrix */
  HEV_SeriesParallel_massmatrix();

  /* Copy the mass matrix from system to the destination, if needed. */
  if (Mdest != rtsiGetSolverMassMatrixPr(si)) {
    real_T *Msrc = rtsiGetSolverMassMatrixPr(si);
    int_T nzmax = rtsiGetSolverMassMatrixNzMax(si);
    (void) memcpy(Mdest, Msrc,
                  (uint_T)nzmax*sizeof(real_T));
  }
}

void local_evaluateFminusMv(RTWSolverInfo *si, const real_T *v, real_T *fminusMv
  )
{
  /* Refresh forcing function */
  rtsiSetdX(si,fminusMv);
  HEV_SeriesParallel_forcingfunction();

  /* Refresh global mass matrix */
  HEV_SeriesParallel_massmatrix();

  /* Form f - M*v */
  {
    real_T *elptr = rtsiGetSolverMassMatrixPr(si);
    int_T *iptr = rtsiGetSolverMassMatrixIr(si);
    int_T *jc = rtsiGetSolverMassMatrixJc(si);
    int_T nx = 74;
    int_T col,row;
    for (col = 0; col < nx; col++) {
      for (row = jc[col]; row < jc[col+1]; row++) {
        fminusMv[*iptr++] -= (*v) * (*elptr++);
      }

      v++;
    }
  }
}

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *v, const real_T
                  *Fty, real_T *fac, real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 74;
  real_T *x = rtsiGetContStates(si);
  boolean_T *xdis = rtsiGetContStateDisabledPtr(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Zero column j of dFdy if state j is currently disabled. */
    if (xdis[j]) {
      (void) memset(p, 0,
                    (uint_T)nx*sizeof(p[0]));
      continue;
    }

    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    HEV_SeriesParallel_step0();
    local_evaluateFminusMv(si,v,p );
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14X fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  boolean_T *xdis = rtsiGetContStateDisabledPtr(si);
  int_T *Mpattern_ir = rtsiGetSolverMassMatrixIr(si);
  int_T *Mpattern_jc = rtsiGetSolverMassMatrixJc(si);
  real_T *M = id->M;
  real_T *M1 = id->M1;
  real_T *xdot = id->xdot;
  real_T *Edot = id->Edot;
  real_T *fminusMxdot = id->fminusMxdot;
  int_T col,row,rowidx;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 74;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  local_evaluateMassMatrix(si,M );
  rtsiSetdX(si, xdot);
  HEV_SeriesParallel_derivatives();

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  HEV_SeriesParallel_forcingfunction();

  /* Form fminusMxdot = f(x) - M(x)*xdot, d(fminusMxdot)/dx = df/dx - d(Mv)/dx */
  (void) memcpy(fminusMxdot, f0,
                (uint_T)nx*sizeof(real_T));
  for (col = 0; col < nx; col++) {
    for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
      real_T m_row_col = M[rowidx];
      row = Mpattern_ir[rowidx];
      fminusMxdot[row] -= m_row_col*xdot[col];
    }
  }

  local_numjac(si,x0,xdot,fminusMxdot,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*(uint_T)nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (col = 0, p = W; col < nx; col++, p += nx) {
      if (xdis[col]) {
        (void) memset(p, 0,
                      (uint_T)nx*sizeof(p[0]));
        p[col] = 1.0;
      } else {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          p[row] += m_row_col;
        }
      }
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      HEV_SeriesParallel_step0();
      HEV_SeriesParallel_forcingfunction();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= m_row_col*xtmp[col];
        }
      }

      /* rhs = rhs - (Mtmp - M)*ztmp*h */
      local_evaluateMassMatrix(si,M1 );
      for (i = 0; i < rtsiGetSolverMassMatrixNzMax(si); i++) {
        M1[i] -= M[i];
      }

      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M1[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= hN*m_row_col*ztmp[col];
        }
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        HEV_SeriesParallel_step0();
        HEV_SeriesParallel_forcingfunction();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (col = 0; col < nx; col++) {
            for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx
                 ++) {
              real_T m_row_col = M[rowidx];
              row = Mpattern_ir[rowidx];
              Delta[row] -= m_row_col*xtmp[col];
            }
          }
        }

        /* For state-dep.,  Mdel = M(ttmp,ytmp) - M */
        HEV_SeriesParallel_step0();
        local_evaluateMassMatrix(si,M1 );
        for (i = 0; i < rtsiGetSolverMassMatrixNzMax(si); i++) {
          M1[i] -= M[i];
        }

        /* rhs = rhs - Mdel*ztmp*h */
        for (col = 0; col < nx; col++) {
          for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++)
          {
            real_T m_row_col = M1[rowidx];
            row = Mpattern_ir[rowidx];
            Delta[row] -= hN*m_row_col*ztmp[col];
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }

    /* Extrapolate the derivative */
    for (i = 0; i < nx; i++) {
      xdot[i] = (x1[i] - x1start[i])/hN;
    }

    (void) memcpy(&(Edot[nx*j]), xdot,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        xdot[i] = Edot[nx*k+i] + coef*(Edot[nx*k+i] - Edot[nx*(k-1)+i]);
      }

      (void) memcpy(&(Edot[nx*(k-1)]), xdot,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* Extrapolated xdot */
  (void) memcpy(xdot, Edot,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  HEV_SeriesParallel_step0();
  HEV_SeriesParallel_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for Chart: '<S1>/Mode Logic' */
static real_T HEV_SeriesParallel_oldspeed(void)
{
  real_T tmp[20];
  real_T accumulatedData;
  real_T speed_buffer;
  int32_T k;

  /* MATLAB Function 'oldspeed': '<S12>:6' */
  /* '<S12>:6:2' */
  memcpy(&tmp[0], &HEV_SeriesParallel_DW.speed_buffer[0], 20U * sizeof(real_T));

  /* '<S12>:6:3' */
  HEV_SeriesParallel_DW.speed_buffer[0] =
    HEV_SeriesParallel_B.TmpRTBAtModeLogicInport1;

  /* '<S12>:6:4' */
  accumulatedData = HEV_SeriesParallel_DW.speed_buffer[0];
  for (k = 0; k < 20; k++) {
    speed_buffer = tmp[k];
    HEV_SeriesParallel_DW.speed_buffer[k + 1] = speed_buffer;
    accumulatedData += speed_buffer;
  }

  return accumulatedData / 21.0;
}

/* Model step function for TID0 */
void HEV_SeriesParallel_step0(void)    /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_DriveCycle1;
  real_T rtb_DriveCycle2;
  real_T rtb_DriveCycle3;
  real_T rtb_DriveCycle4;
  real_T rtb_DriveCycle5;
  real_T rtb_DriveCycle6;
  if (rtmIsMajorTimeStep(HEV_SeriesParallel_M)) {
    /* set solver stop time */
    if (!(HEV_SeriesParallel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&HEV_SeriesParallel_M->solverInfo,
                            ((HEV_SeriesParallel_M->Timing.clockTickH0 + 1) *
        HEV_SeriesParallel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&HEV_SeriesParallel_M->solverInfo,
                            ((HEV_SeriesParallel_M->Timing.clockTick0 + 1) *
        HEV_SeriesParallel_M->Timing.stepSize0 +
        HEV_SeriesParallel_M->Timing.clockTickH0 *
        HEV_SeriesParallel_M->Timing.stepSize0 * 4294967296.0));
    }

    /* Update the flag to indicate when data transfers from
     *  Sample time: [1.0E-5s, 0.0s] to Sample time: [0.1s, 0.0s]  */
    (HEV_SeriesParallel_M->Timing.RateInteraction.TID1_2)++;
    if ((HEV_SeriesParallel_M->Timing.RateInteraction.TID1_2) > 9999) {
      HEV_SeriesParallel_M->Timing.RateInteraction.TID1_2 = 0;
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(HEV_SeriesParallel_M)) {
    HEV_SeriesParallel_M->Timing.t[0] = rtsiGetT
      (&HEV_SeriesParallel_M->solverInfo);
  }

  {
    NeParameterBundle expl_temp;
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diag;
    NeuDiagnosticTree *diagTree;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    char *msg;
    char *msg_0;
    char *msg_1;
    char *msg_2;
    real_T tmp_3[87];
    real_T tmp_5[87];
    real_T tmp_1[16];
    real_T tmp[9];
    real_T rtb_FuelConsumptionTable;
    real_T rtb_Gain;
    real_T rtb_OUTPUT_1_1;
    real_T rtb_SpdReqMot;
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_2;
    real_T time_3;
    real_T time_4;
    real_T time_tmp;
    int_T tmp_4[6];
    int_T tmp_6[6];
    int_T tmp_2[5];
    int_T iy;
    uint32_T ri;
    boolean_T first_output;
    boolean_T tmp_0;
    boolean_T tmp_7;
    boolean_T tmp_8;
    ZCEventType zcEvent;

    /* Integrator: '<S81>/Limits [-5,5]' */
    /* Limited  Integrator  */
    if (HEV_SeriesParallel_X.Limits55_CSTATE >=
        HEV_SeriesParallel_P.Limits55_UpperSat) {
      HEV_SeriesParallel_X.Limits55_CSTATE =
        HEV_SeriesParallel_P.Limits55_UpperSat;
    } else if (HEV_SeriesParallel_X.Limits55_CSTATE <=
               HEV_SeriesParallel_P.Limits55_LowerSat) {
      HEV_SeriesParallel_X.Limits55_CSTATE =
        HEV_SeriesParallel_P.Limits55_LowerSat;
    }

    /* Integrator: '<S81>/Limits [-5,5]' */
    HEV_SeriesParallel_B.Limits55 = HEV_SeriesParallel_X.Limits55_CSTATE;

    /* TransferFcn: '<S81>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_B.u0HzLowpassFilter = 0.0;
    HEV_SeriesParallel_B.u0HzLowpassFilter +=
      HEV_SeriesParallel_P.u0HzLowpassFilter_C *
      HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE;

    /* FromWorkspace: '<S5>/Drive Cycle 1' */
    {
      real_T *pDataValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle1_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle1_PWORK.TimePtr;
      int_T currTimeIndex = HEV_SeriesParallel_DW.DriveCycle1_IWORK.PrevIndex;
      real_T t = HEV_SeriesParallel_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[195]) {
        currTimeIndex = 194;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      HEV_SeriesParallel_DW.DriveCycle1_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_DriveCycle1 = pDataValues[currTimeIndex];
          } else {
            rtb_DriveCycle1 = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_DriveCycle1 = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 196;
        }
      }
    }

    /* FromWorkspace: '<S5>/Drive Cycle 2' */
    {
      real_T *pDataValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle2_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle2_PWORK.TimePtr;
      int_T currTimeIndex = HEV_SeriesParallel_DW.DriveCycle2_IWORK.PrevIndex;
      real_T t = HEV_SeriesParallel_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[400]) {
        currTimeIndex = 399;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      HEV_SeriesParallel_DW.DriveCycle2_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_DriveCycle2 = pDataValues[currTimeIndex];
          } else {
            rtb_DriveCycle2 = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_DriveCycle2 = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 401;
        }
      }
    }

    /* FromWorkspace: '<S5>/Drive Cycle 3' */
    {
      real_T *pDataValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle3_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle3_PWORK.TimePtr;
      int_T currTimeIndex = HEV_SeriesParallel_DW.DriveCycle3_IWORK.PrevIndex;
      real_T t = HEV_SeriesParallel_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[400]) {
        currTimeIndex = 399;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      HEV_SeriesParallel_DW.DriveCycle3_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_DriveCycle3 = pDataValues[currTimeIndex];
          } else {
            rtb_DriveCycle3 = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_DriveCycle3 = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 401;
        }
      }
    }

    /* FromWorkspace: '<S5>/Drive Cycle 4' */
    {
      real_T *pDataValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle4_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle4_PWORK.TimePtr;
      int_T currTimeIndex = HEV_SeriesParallel_DW.DriveCycle4_IWORK.PrevIndex;
      real_T t = HEV_SeriesParallel_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[506]) {
        currTimeIndex = 505;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      HEV_SeriesParallel_DW.DriveCycle4_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_DriveCycle4 = pDataValues[currTimeIndex];
          } else {
            rtb_DriveCycle4 = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_DriveCycle4 = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 507;
        }
      }
    }

    /* FromWorkspace: '<S5>/Drive Cycle 5' */
    {
      real_T *pDataValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle5_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle5_PWORK.TimePtr;
      int_T currTimeIndex = HEV_SeriesParallel_DW.DriveCycle5_IWORK.PrevIndex;
      real_T t = HEV_SeriesParallel_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[660]) {
        currTimeIndex = 659;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      HEV_SeriesParallel_DW.DriveCycle5_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_DriveCycle5 = pDataValues[currTimeIndex];
          } else {
            rtb_DriveCycle5 = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_DriveCycle5 = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 661;
        }
      }
    }

    /* FromWorkspace: '<S5>/Drive Cycle 6' */
    {
      real_T *pDataValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle6_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        HEV_SeriesParallel_DW.DriveCycle6_PWORK.TimePtr;
      int_T currTimeIndex = HEV_SeriesParallel_DW.DriveCycle6_IWORK.PrevIndex;
      real_T t = HEV_SeriesParallel_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[5]) {
        currTimeIndex = 4;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      HEV_SeriesParallel_DW.DriveCycle6_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_DriveCycle6 = pDataValues[currTimeIndex];
          } else {
            rtb_DriveCycle6 = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_DriveCycle6 = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 6;
        }
      }
    }

    /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
     *  Constant: '<S5>/Select Cycle'
     */
    switch ((int32_T)HEV_SeriesParallel_P.Drive_Cycle_Num) {
     case 1:
      /* MultiPortSwitch: '<S5>/Multiport Switch' */
      HEV_SeriesParallel_B.RefSpd = rtb_DriveCycle1;
      break;

     case 2:
      /* MultiPortSwitch: '<S5>/Multiport Switch' */
      HEV_SeriesParallel_B.RefSpd = rtb_DriveCycle2;
      break;

     case 3:
      /* MultiPortSwitch: '<S5>/Multiport Switch' */
      HEV_SeriesParallel_B.RefSpd = rtb_DriveCycle3;
      break;

     case 4:
      /* MultiPortSwitch: '<S5>/Multiport Switch' */
      HEV_SeriesParallel_B.RefSpd = rtb_DriveCycle4;
      break;

     case 5:
      /* MultiPortSwitch: '<S5>/Multiport Switch' */
      HEV_SeriesParallel_B.RefSpd = rtb_DriveCycle5;
      break;

     default:
      /* MultiPortSwitch: '<S5>/Multiport Switch' */
      HEV_SeriesParallel_B.RefSpd = rtb_DriveCycle6;
      break;
    }

    /* End of MultiPortSwitch: '<S5>/Multiport Switch' */

    /* Sum: '<S81>/Sum' */
    HEV_SeriesParallel_B.Sum = HEV_SeriesParallel_B.RefSpd -
      HEV_SeriesParallel_B.u0HzLowpassFilter;

    /* Gain: '<S81>/Kp' */
    HEV_SeriesParallel_B.Kp = HEV_SeriesParallel_P.HEV_Param.Control.Veh_Spd.Kp *
      HEV_SeriesParallel_B.Sum;

    /* Sum: '<S81>/Sum1' */
    HEV_SeriesParallel_B.Sum1 = HEV_SeriesParallel_B.Limits55 +
      HEV_SeriesParallel_B.Kp;

    /* Saturate: '<S81>/Limit Acc' */
    if (HEV_SeriesParallel_B.Sum1 > HEV_SeriesParallel_P.LimitAcc_UpperSat) {
      /* Saturate: '<S81>/Limit Acc' */
      HEV_SeriesParallel_B.LimitAcc = HEV_SeriesParallel_P.LimitAcc_UpperSat;
    } else if (HEV_SeriesParallel_B.Sum1 <
               HEV_SeriesParallel_P.LimitAcc_LowerSat) {
      /* Saturate: '<S81>/Limit Acc' */
      HEV_SeriesParallel_B.LimitAcc = HEV_SeriesParallel_P.LimitAcc_LowerSat;
    } else {
      /* Saturate: '<S81>/Limit Acc' */
      HEV_SeriesParallel_B.LimitAcc = HEV_SeriesParallel_B.Sum1;
    }

    /* End of Saturate: '<S81>/Limit Acc' */

    /* Lookup_n-D: '<S1>/Acc to wEng' incorporates:
     *  Saturate: '<S81>/Limit Acc'
     */
    HEV_SeriesParallel_B.SpdReqIce = look1_binlxpw(HEV_SeriesParallel_B.LimitAcc,
      HEV_SeriesParallel_P.AcctowEng_bp01Data,
      HEV_SeriesParallel_P.AcctowEng_tableData, 3U);

    /* StateSpace: '<S76>/State Space' */
    HEV_SeriesParallel_B.StateSpace = 0.0;

    /* StateSpace: '<S76>/State Space' */
    for (ri = HEV_SeriesParallel_P.StateSpace_C_jc[0U]; ri <
         HEV_SeriesParallel_P.StateSpace_C_jc[1U]; ri++) {
      /* StateSpace: '<S76>/State Space' */
      HEV_SeriesParallel_B.StateSpace += HEV_SeriesParallel_P.StateSpace_C_pr *
        HEV_SeriesParallel_X.StateSpace_CSTATE;
    }

    /* RateTransition generated from: '<S15>/Select Logic' incorporates:
     *  RateTransition generated from: '<S1>/Mode Logic'
     * */
    tmp_7 = rtmIsMajorTimeStep(HEV_SeriesParallel_M);
    if (tmp_7) {
      if (HEV_SeriesParallel_M->Timing.RateInteraction.TID1_2 == 1) {
        /* RateTransition generated from: '<S15>/Select Logic' */
        HEV_SeriesParallel_B.TmpRTBAtSelectLogicOutport1 =
          HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf;
      }
    }

    /* End of RateTransition generated from: '<S15>/Select Logic' */

    /* TransferFcn: '<S16>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_B.u0HzLowpassFilter_j = 0.0;
    HEV_SeriesParallel_B.u0HzLowpassFilter_j +=
      HEV_SeriesParallel_P.u0HzLowpassFilter_C_l *
      HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_o;

    /* Integrator: '<S17>/Limits [-5,5]' incorporates:
     *  Integrator: '<S10>/Limits [0,1]'
     *  SimscapeExecutionBlock: '<S71>/OUTPUT_1_0'
     *  SimscapeExecutionBlock: '<S71>/OUTPUT_1_1'
     *  SimscapeExecutionBlock: '<S71>/STATE_1'
     */
    /* Limited  Integrator  */
    tmp_8 = rtsiIsModeUpdateTimeStep(&HEV_SeriesParallel_M->solverInfo);
    if (tmp_8) {
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &HEV_SeriesParallel_PrevZCX.Limits55_Reset_ZCE,
                         (HEV_SeriesParallel_B.TmpRTBAtSelectLogicOutport1));

      /* evaluate zero-crossings */
      if (zcEvent != NO_ZCEVENT) {
        HEV_SeriesParallel_X.Limits55_CSTATE_f =
          HEV_SeriesParallel_P.Limits55_IC_c;
      }
    }

    if (HEV_SeriesParallel_X.Limits55_CSTATE_f >=
        HEV_SeriesParallel_P.Limits55_UpperSat_f) {
      HEV_SeriesParallel_X.Limits55_CSTATE_f =
        HEV_SeriesParallel_P.Limits55_UpperSat_f;
    } else if (HEV_SeriesParallel_X.Limits55_CSTATE_f <=
               HEV_SeriesParallel_P.Limits55_LowerSat_d) {
      HEV_SeriesParallel_X.Limits55_CSTATE_f =
        HEV_SeriesParallel_P.Limits55_LowerSat_d;
    }

    /* Integrator: '<S17>/Limits [-5,5]' */
    HEV_SeriesParallel_B.Limits55_h = HEV_SeriesParallel_X.Limits55_CSTATE_f;

    /* TransferFcn: '<S17>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_B.u0HzLowpassFilter_d = 0.0;
    HEV_SeriesParallel_B.u0HzLowpassFilter_d +=
      HEV_SeriesParallel_P.u0HzLowpassFilter_C_m *
      HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_g;

    /* Lookup_n-D: '<S1>/Acc to wMot' incorporates:
     *  Saturate: '<S81>/Limit Acc'
     */
    rtb_SpdReqMot = look1_binlxpw(HEV_SeriesParallel_B.LimitAcc,
      HEV_SeriesParallel_P.AcctowMot_bp01Data,
      HEV_SeriesParallel_P.AcctowMot_tableData, 2U);

    /* Gain: '<S17>/rpm2volts' incorporates:
     *  Fcn: '<S11>/Set generator RPM so that engine RPM is controlled to zero or the idle speed'
     */
    HEV_SeriesParallel_B.rpm2volts = (3.6 * HEV_SeriesParallel_B.SpdReqIce - 2.6
      * rtb_SpdReqMot) * HEV_SeriesParallel_P.rpm2volts_Gain;

    /* Sum: '<S17>/Sum' */
    HEV_SeriesParallel_B.Sum_g = HEV_SeriesParallel_B.rpm2volts -
      HEV_SeriesParallel_B.u0HzLowpassFilter_d;

    /* Gain: '<S17>/Kp' */
    HEV_SeriesParallel_B.Kp_n = HEV_SeriesParallel_P.HEV_Param.Control.Gen.Kp *
      HEV_SeriesParallel_B.Sum_g;

    /* Sum: '<S17>/Sum1' */
    HEV_SeriesParallel_B.Sum1_b = HEV_SeriesParallel_B.Limits55_h +
      HEV_SeriesParallel_B.Kp_n;

    /* Saturate: '<S17>/[-5,5]' */
    if (HEV_SeriesParallel_B.Sum1_b > HEV_SeriesParallel_P.u5_UpperSat) {
      /* Saturate: '<S17>/[-5,5]' */
      HEV_SeriesParallel_B.u5 = HEV_SeriesParallel_P.u5_UpperSat;
    } else if (HEV_SeriesParallel_B.Sum1_b < HEV_SeriesParallel_P.u5_LowerSat) {
      /* Saturate: '<S17>/[-5,5]' */
      HEV_SeriesParallel_B.u5 = HEV_SeriesParallel_P.u5_LowerSat;
    } else {
      /* Saturate: '<S17>/[-5,5]' */
      HEV_SeriesParallel_B.u5 = HEV_SeriesParallel_B.Sum1_b;
    }

    /* End of Saturate: '<S17>/[-5,5]' */

    /* Gain: '<S17>/Volts//Nm' */
    HEV_SeriesParallel_B.VoltsNm = HEV_SeriesParallel_P.VoltsNm_Gain *
      HEV_SeriesParallel_B.u5;

    /* ManualSwitch: '<S16>/Select Logic' */
    if (HEV_SeriesParallel_P.SelectLogic_CurrentSetting == 1) {
      /* Product: '<S16>/Product' */
      HEV_SeriesParallel_B.Product_n = HEV_SeriesParallel_B.u0HzLowpassFilter_j *
        HEV_SeriesParallel_B.VoltsNm;

      /* ManualSwitch: '<S16>/Select Logic' */
      HEV_SeriesParallel_B.SelectLogic = HEV_SeriesParallel_B.Product_n;
    } else {
      /* ManualSwitch: '<S16>/Select Logic' */
      HEV_SeriesParallel_B.SelectLogic = HEV_SeriesParallel_B.VoltsNm;
    }

    /* End of ManualSwitch: '<S16>/Select Logic' */

    /* SimscapeInputBlock: '<S71>/INPUT_1_1_1' */
    HEV_SeriesParallel_B.INPUT_1_1_1[0] = HEV_SeriesParallel_B.SelectLogic;
    HEV_SeriesParallel_B.INPUT_1_1_1[1] = 0.0;
    HEV_SeriesParallel_B.INPUT_1_1_1[2] = 0.0;
    HEV_SeriesParallel_B.INPUT_1_1_1[3] = 0.0;

    /* Integrator: '<S13>/Limits [-5,5]' */
    /* Limited  Integrator  */
    if (HEV_SeriesParallel_X.Limits55_CSTATE_n >=
        HEV_SeriesParallel_P.Limits55_UpperSat_g) {
      HEV_SeriesParallel_X.Limits55_CSTATE_n =
        HEV_SeriesParallel_P.Limits55_UpperSat_g;
    } else if (HEV_SeriesParallel_X.Limits55_CSTATE_n <=
               HEV_SeriesParallel_P.Limits55_LowerSat_c) {
      HEV_SeriesParallel_X.Limits55_CSTATE_n =
        HEV_SeriesParallel_P.Limits55_LowerSat_c;
    }

    /* Integrator: '<S13>/Limits [-5,5]' */
    HEV_SeriesParallel_B.Limits55_p = HEV_SeriesParallel_X.Limits55_CSTATE_n;

    /* TransferFcn: '<S13>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_B.u0HzLowpassFilter_k = 0.0;
    HEV_SeriesParallel_B.u0HzLowpassFilter_k +=
      HEV_SeriesParallel_P.u0HzLowpassFilter_C_f *
      HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_l;

    /* Gain: '<S13>/rpm2volts' */
    HEV_SeriesParallel_B.rpm2volts_b = HEV_SeriesParallel_P.rpm2volts_Gain_p *
      rtb_SpdReqMot;

    /* Sum: '<S13>/Sum' */
    HEV_SeriesParallel_B.Sum_e = HEV_SeriesParallel_B.rpm2volts_b -
      HEV_SeriesParallel_B.u0HzLowpassFilter_k;

    /* Gain: '<S13>/Kp' */
    HEV_SeriesParallel_B.Kp_d = HEV_SeriesParallel_P.HEV_Param.Control.Mot.Kp *
      HEV_SeriesParallel_B.Sum_e;

    /* Sum: '<S13>/Sum1' */
    HEV_SeriesParallel_B.Sum1_m = HEV_SeriesParallel_B.Limits55_p +
      HEV_SeriesParallel_B.Kp_d;

    /* Saturate: '<S13>/[-5,5]' */
    if (HEV_SeriesParallel_B.Sum1_m > HEV_SeriesParallel_P.u5_UpperSat_m) {
      /* Saturate: '<S13>/[-5,5]' */
      HEV_SeriesParallel_B.u5_f = HEV_SeriesParallel_P.u5_UpperSat_m;
    } else if (HEV_SeriesParallel_B.Sum1_m < HEV_SeriesParallel_P.u5_LowerSat_a)
    {
      /* Saturate: '<S13>/[-5,5]' */
      HEV_SeriesParallel_B.u5_f = HEV_SeriesParallel_P.u5_LowerSat_a;
    } else {
      /* Saturate: '<S13>/[-5,5]' */
      HEV_SeriesParallel_B.u5_f = HEV_SeriesParallel_B.Sum1_m;
    }

    /* End of Saturate: '<S13>/[-5,5]' */

    /* Gain: '<S13>/Volts//Nm' */
    HEV_SeriesParallel_B.VoltsNm_a = HEV_SeriesParallel_P.VoltsNm_Gain_c *
      HEV_SeriesParallel_B.u5_f;

    /* ManualSwitch: '<S19>/Select Logic' */
    if (HEV_SeriesParallel_P.SelectLogic_CurrentSetting_i == 1) {
      /* Product: '<S19>/Product' */
      HEV_SeriesParallel_B.Product = 0.0 * HEV_SeriesParallel_B.VoltsNm_a;

      /* ManualSwitch: '<S19>/Select Logic' */
      HEV_SeriesParallel_B.SelectLogic_c = HEV_SeriesParallel_B.Product;
    } else {
      /* ManualSwitch: '<S19>/Select Logic' */
      HEV_SeriesParallel_B.SelectLogic_c = HEV_SeriesParallel_B.VoltsNm_a;
    }

    /* End of ManualSwitch: '<S19>/Select Logic' */

    /* SimscapeInputBlock: '<S71>/INPUT_2_1_1' */
    HEV_SeriesParallel_B.INPUT_2_1_1[0] = HEV_SeriesParallel_B.SelectLogic_c;
    HEV_SeriesParallel_B.INPUT_2_1_1[1] = 0.0;
    HEV_SeriesParallel_B.INPUT_2_1_1[2] = 0.0;
    HEV_SeriesParallel_B.INPUT_2_1_1[3] = 0.0;

    /* Integrator: '<S10>/Limits [0,1]' */
    /* Limited  Integrator  */
    if (tmp_8) {
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &HEV_SeriesParallel_PrevZCX.Limits01_Reset_ZCE,
                         (HEV_SeriesParallel_B.TmpRTBAtSelectLogicOutport1));

      /* evaluate zero-crossings */
      if (zcEvent != NO_ZCEVENT) {
        HEV_SeriesParallel_X.Limits01_CSTATE = HEV_SeriesParallel_P.Limits01_IC;
      }
    }

    if (HEV_SeriesParallel_X.Limits01_CSTATE >=
        HEV_SeriesParallel_P.Limits01_UpperSat) {
      HEV_SeriesParallel_X.Limits01_CSTATE =
        HEV_SeriesParallel_P.Limits01_UpperSat;
    } else if (HEV_SeriesParallel_X.Limits01_CSTATE <=
               HEV_SeriesParallel_P.Limits01_LowerSat) {
      HEV_SeriesParallel_X.Limits01_CSTATE =
        HEV_SeriesParallel_P.Limits01_LowerSat;
    }

    /* Integrator: '<S10>/Limits [0,1]' */
    HEV_SeriesParallel_B.Limits01 = HEV_SeriesParallel_X.Limits01_CSTATE;

    /* TransferFcn: '<S10>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_B.u0HzLowpassFilter_b = 0.0;
    HEV_SeriesParallel_B.u0HzLowpassFilter_b +=
      HEV_SeriesParallel_P.u0HzLowpassFilter_C_o *
      HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_f;

    /* Switch: '<S10>/Switch' */
    if (HEV_SeriesParallel_B.TmpRTBAtSelectLogicOutport1 >=
        HEV_SeriesParallel_P.Switch_Threshold) {
      /* Switch: '<S10>/Switch' */
      HEV_SeriesParallel_B.Switch = HEV_SeriesParallel_B.SpdReqIce;
    } else {
      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S10>/Engine Idle'
       */
      HEV_SeriesParallel_B.Switch = HEV_SeriesParallel_P.EngineIdle_Value;
    }

    /* End of Switch: '<S10>/Switch' */

    /* Sum: '<S10>/Sum' */
    HEV_SeriesParallel_B.Sum_i = HEV_SeriesParallel_B.Switch -
      HEV_SeriesParallel_B.u0HzLowpassFilter_b;

    /* Gain: '<S10>/Kp' */
    HEV_SeriesParallel_B.Kp_e = HEV_SeriesParallel_P.HEV_Param.Control.ICE.Kp *
      HEV_SeriesParallel_B.Sum_i;

    /* Sum: '<S10>/Sum1' */
    HEV_SeriesParallel_B.Sum1_d = HEV_SeriesParallel_B.Limits01 +
      HEV_SeriesParallel_B.Kp_e;

    /* Saturate: '<S10>/[0,1]' */
    if (HEV_SeriesParallel_B.Sum1_d > HEV_SeriesParallel_P.u1_UpperSat) {
      /* Saturate: '<S10>/[0,1]' */
      HEV_SeriesParallel_B.u1 = HEV_SeriesParallel_P.u1_UpperSat;
    } else if (HEV_SeriesParallel_B.Sum1_d < HEV_SeriesParallel_P.u1_LowerSat) {
      /* Saturate: '<S10>/[0,1]' */
      HEV_SeriesParallel_B.u1 = HEV_SeriesParallel_P.u1_LowerSat;
    } else {
      /* Saturate: '<S10>/[0,1]' */
      HEV_SeriesParallel_B.u1 = HEV_SeriesParallel_B.Sum1_d;
    }

    /* End of Saturate: '<S10>/[0,1]' */

    /* SimscapeInputBlock: '<S71>/INPUT_3_1_1' */
    HEV_SeriesParallel_B.INPUT_3_1_1[0] = HEV_SeriesParallel_B.u1;
    HEV_SeriesParallel_B.INPUT_3_1_1[1] = 0.0;
    HEV_SeriesParallel_B.INPUT_3_1_1[2] = 0.0;
    HEV_SeriesParallel_B.INPUT_3_1_1[3] = 0.0;

    /* Saturate: '<S81>/Limit Brk' */
    if (HEV_SeriesParallel_B.Sum1 > HEV_SeriesParallel_P.LimitBrk_UpperSat) {
      /* Saturate: '<S81>/Limit Brk' */
      HEV_SeriesParallel_B.LimitBrk = HEV_SeriesParallel_P.LimitBrk_UpperSat;
    } else if (HEV_SeriesParallel_B.Sum1 <
               HEV_SeriesParallel_P.LimitBrk_LowerSat) {
      /* Saturate: '<S81>/Limit Brk' */
      HEV_SeriesParallel_B.LimitBrk = HEV_SeriesParallel_P.LimitBrk_LowerSat;
    } else {
      /* Saturate: '<S81>/Limit Brk' */
      HEV_SeriesParallel_B.LimitBrk = HEV_SeriesParallel_B.Sum1;
    }

    /* End of Saturate: '<S81>/Limit Brk' */

    /* Gain: '<S81>/Gain' */
    HEV_SeriesParallel_B.Gain = HEV_SeriesParallel_P.Gain_Gain *
      HEV_SeriesParallel_B.LimitBrk;

    /* SimscapeInputBlock: '<S71>/INPUT_4_1_1' */
    if (HEV_SeriesParallel_DW.INPUT_4_1_1_FirstOutput_2208644 == 0.0) {
      HEV_SeriesParallel_DW.INPUT_4_1_1_FirstOutput_2208644 = 1.0;
      HEV_SeriesParallel_X.HEV_SeriesParallelVehicleSimuli =
        HEV_SeriesParallel_B.Gain;
    }

    HEV_SeriesParallel_B.INPUT_4_1_1[0] =
      HEV_SeriesParallel_X.HEV_SeriesParallelVehicleSimuli;
    HEV_SeriesParallel_B.INPUT_4_1_1[1] = (HEV_SeriesParallel_B.Gain -
      HEV_SeriesParallel_X.HEV_SeriesParallelVehicleSimuli) * 20.0;
    HEV_SeriesParallel_B.INPUT_4_1_1[2] = 0.0;
    HEV_SeriesParallel_B.INPUT_4_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S71>/INPUT_4_1_1' */
    if (tmp_7) {
      /* SimscapeRtp: '<S24>/RTP_1' incorporates:
       *  Constant: '<S22>/Subsystem_around_RTP_1737879D_charge'
       *  Constant: '<S25>/Subsystem_around_RTP_0BC1812E_w'
       *  Constant: '<S3>/Subsystem_around_RTP_3224FFEB_w'
       *  Constant: '<S54>/Subsystem_around_RTP_DB87A893_w'
       *  Constant: '<S8>/Subsystem_around_RTP_494A81BE_mass'
       *  Constant: '<S8>/Subsystem_around_RTP_494A81BE_v'
       *  Constant: '<S8>/Subsystem_around_RTP_4B685322_w'
       *  Constant: '<S8>/Subsystem_around_RTP_ACD07E25_w'
       *  Constant: '<S8>/Subsystem_around_RTP_DBD74EB3_w'
       */
      if (HEV_SeriesParallel_DW.RTP_1_SetParametersNeeded) {
        tmp[0] = HEV_SeriesParallel_P.RTP_0BC1812E_w_Value;
        tmp[1] = HEV_SeriesParallel_P.HEV_Param.Control.Engine_Start_RPM;
        tmp[2] = HEV_SeriesParallel_P.AH0;
        tmp[3] = HEV_SeriesParallel_P.RTP_DB87A893_w_Value;
        tmp[4] = HEV_SeriesParallel_P.HEV_Param.Vehicle.Mass;
        tmp[5] = HEV_SeriesParallel_P.RTP_494A81BE_v_Value;
        tmp[6] = HEV_SeriesParallel_P.RTP_4B685322_w_Value;
        tmp[7] = HEV_SeriesParallel_P.RTP_ACD07E25_w_Value;
        tmp[8] = HEV_SeriesParallel_P.RTP_DBD74EB3_w_Value;
        diag = rtw_create_diagnostics();
        diagTree = neu_diagnostic_manager_get_initial_tree(diag);
        expl_temp.mRealParameters.mN = 9;
        expl_temp.mRealParameters.mX = &tmp[0];
        expl_temp.mLogicalParameters.mN = 0;
        expl_temp.mLogicalParameters.mX = NULL;
        expl_temp.mIntegerParameters.mN = 0;
        expl_temp.mIntegerParameters.mX = NULL;
        expl_temp.mIndexParameters.mN = 0;
        expl_temp.mIndexParameters.mX = NULL;
        first_output = nesl_rtp_manager_set_rtps((NeslRtpManager *)
          HEV_SeriesParallel_DW.RTP_1_RtpManager, HEV_SeriesParallel_M->
          Timing.t[0], expl_temp, diag);
        if (!first_output) {
          first_output = error_buffer_is_empty(rtmGetErrorStatus
            (HEV_SeriesParallel_M));
          if (first_output) {
            msg = rtw_diagnostics_msg(diagTree);
            rtmSetErrorStatus(HEV_SeriesParallel_M, msg);
          }
        }
      }

      HEV_SeriesParallel_DW.RTP_1_SetParametersNeeded = false;

      /* End of SimscapeRtp: '<S24>/RTP_1' */
    }

    /* SimscapeExecutionBlock: '<S71>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S71>/OUTPUT_1_0'
     *  SimscapeExecutionBlock: '<S71>/OUTPUT_1_1'
     */
    simulationData = (NeslSimulationData *)HEV_SeriesParallel_DW.STATE_1_SimData;
    rtb_SpdReqMot = HEV_SeriesParallel_M->Timing.t[0];
    time = rtb_SpdReqMot;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 58;
    simulationData->mData->mContStates.mX =
      &HEV_SeriesParallel_X.HEV_SeriesParallelElectricalGen[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &HEV_SeriesParallel_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 13;
    simulationData->mData->mModeVector.mX =
      &HEV_SeriesParallel_DW.STATE_1_Modes[0];
    first_output = false;
    simulationData->mData->mFoundZcEvents = first_output;
    simulationData->mData->mHadEvents = false;
    first_output = rtmIsMajorTimeStep(HEV_SeriesParallel_M);
    simulationData->mData->mIsMajorTimeStep = first_output;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&HEV_SeriesParallel_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_8;
    tmp_2[0] = 0;
    tmp_1[0] = HEV_SeriesParallel_B.INPUT_1_1_1[0];
    tmp_1[1] = HEV_SeriesParallel_B.INPUT_1_1_1[1];
    tmp_1[2] = HEV_SeriesParallel_B.INPUT_1_1_1[2];
    tmp_1[3] = HEV_SeriesParallel_B.INPUT_1_1_1[3];
    tmp_2[1] = 4;
    tmp_1[4] = HEV_SeriesParallel_B.INPUT_2_1_1[0];
    tmp_1[5] = HEV_SeriesParallel_B.INPUT_2_1_1[1];
    tmp_1[6] = HEV_SeriesParallel_B.INPUT_2_1_1[2];
    tmp_1[7] = HEV_SeriesParallel_B.INPUT_2_1_1[3];
    tmp_2[2] = 8;
    tmp_1[8] = HEV_SeriesParallel_B.INPUT_3_1_1[0];
    tmp_1[9] = HEV_SeriesParallel_B.INPUT_3_1_1[1];
    tmp_1[10] = HEV_SeriesParallel_B.INPUT_3_1_1[2];
    tmp_1[11] = HEV_SeriesParallel_B.INPUT_3_1_1[3];
    tmp_2[3] = 12;
    tmp_1[12] = HEV_SeriesParallel_B.INPUT_4_1_1[0];
    tmp_1[13] = HEV_SeriesParallel_B.INPUT_4_1_1[1];
    tmp_1[14] = HEV_SeriesParallel_B.INPUT_4_1_1[2];
    tmp_1[15] = HEV_SeriesParallel_B.INPUT_4_1_1[3];
    tmp_2[4] = 16;
    simulationData->mData->mInputValues.mN = 16;
    simulationData->mData->mInputValues.mX = &tmp_1[0];
    simulationData->mData->mInputOffsets.mN = 5;
    simulationData->mData->mInputOffsets.mX = &tmp_2[0];
    simulationData->mData->mOutputs.mN = 71;
    simulationData->mData->mOutputs.mX = &HEV_SeriesParallel_B.STATE_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_tmp = HEV_SeriesParallel_M->Timing.t[0];
    time_0 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)HEV_SeriesParallel_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diag);
    iy = ne_simulator_method((NeslSimulator *)
      HEV_SeriesParallel_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diag);
    if (iy != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
      if (tmp_0) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(HEV_SeriesParallel_M, msg_0);
      }
    }

    /* SimscapeExecutionBlock: '<S71>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)
      HEV_SeriesParallel_DW.OUTPUT_1_0_SimData;
    time_1 = rtb_SpdReqMot;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &HEV_SeriesParallel_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &HEV_SeriesParallel_DW.OUTPUT_1_0_Modes;
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = first_output;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_8;
    tmp_4[0] = 0;
    tmp_3[0] = HEV_SeriesParallel_B.INPUT_1_1_1[0];
    tmp_3[1] = HEV_SeriesParallel_B.INPUT_1_1_1[1];
    tmp_3[2] = HEV_SeriesParallel_B.INPUT_1_1_1[2];
    tmp_3[3] = HEV_SeriesParallel_B.INPUT_1_1_1[3];
    tmp_4[1] = 4;
    tmp_3[4] = HEV_SeriesParallel_B.INPUT_2_1_1[0];
    tmp_3[5] = HEV_SeriesParallel_B.INPUT_2_1_1[1];
    tmp_3[6] = HEV_SeriesParallel_B.INPUT_2_1_1[2];
    tmp_3[7] = HEV_SeriesParallel_B.INPUT_2_1_1[3];
    tmp_4[2] = 8;
    tmp_3[8] = HEV_SeriesParallel_B.INPUT_3_1_1[0];
    tmp_3[9] = HEV_SeriesParallel_B.INPUT_3_1_1[1];
    tmp_3[10] = HEV_SeriesParallel_B.INPUT_3_1_1[2];
    tmp_3[11] = HEV_SeriesParallel_B.INPUT_3_1_1[3];
    tmp_4[3] = 12;
    tmp_3[12] = HEV_SeriesParallel_B.INPUT_4_1_1[0];
    tmp_3[13] = HEV_SeriesParallel_B.INPUT_4_1_1[1];
    tmp_3[14] = HEV_SeriesParallel_B.INPUT_4_1_1[2];
    tmp_3[15] = HEV_SeriesParallel_B.INPUT_4_1_1[3];
    tmp_4[4] = 16;
    memcpy(&tmp_3[16], &HEV_SeriesParallel_B.STATE_1[0], 71U * sizeof(real_T));
    tmp_4[5] = 87;
    simulationData->mData->mInputValues.mN = 87;
    simulationData->mData->mInputValues.mX = &tmp_3[0];
    simulationData->mData->mInputOffsets.mN = 6;
    simulationData->mData->mInputOffsets.mX = &tmp_4[0];
    simulationData->mData->mOutputs.mN = 26;
    simulationData->mData->mOutputs.mX = &HEV_SeriesParallel_B.OUTPUT_1_0[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_2 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_2;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)HEV_SeriesParallel_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diag);
    iy = ne_simulator_method((NeslSimulator *)
      HEV_SeriesParallel_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diag);
    if (iy != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
      if (tmp_0) {
        msg_1 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(HEV_SeriesParallel_M, msg_1);
      }
    }

    /* Integrator: '<S43>/Initial charge Ah0' */
    HEV_SeriesParallel_B.InitialchargeAh0 =
      HEV_SeriesParallel_X.InitialchargeAh0_CSTATE;

    /* Gain: '<S42>/Gain' incorporates:
     *  Gain: '<S42>/Calc Pct'
     */
    HEV_SeriesParallel_B.Gain_g = 1.0 / HEV_SeriesParallel_P.AH * 100.0 *
      HEV_SeriesParallel_B.InitialchargeAh0 * HEV_SeriesParallel_P.Gain_Gain_p;
    if (tmp_7) {
      /* Gain: '<S7>/Gain' incorporates:
       *  Constant: '<S54>/Zero3'
       */
      rtb_Gain = HEV_SeriesParallel_P.Gain_Gain_d *
        HEV_SeriesParallel_P.Zero3_Value;
    }

    /* Gain: '<S99>/rpm2rad//s' */
    rtb_FuelConsumptionTable = HEV_SeriesParallel_P.rpm2rads_Gain *
      HEV_SeriesParallel_B.OUTPUT_1_0[13];

    /* Gain: '<S99>/Gain4' incorporates:
     *  Constant: '<S54>/Zero4'
     *  Product: '<S99>/Product2'
     */
    HEV_SeriesParallel_B.Gain4 = rtb_FuelConsumptionTable *
      HEV_SeriesParallel_P.Zero4_Value * HEV_SeriesParallel_P.Gain4_Gain;
    if (tmp_7) {
    }

    /* Gain: '<S98>/rpm2rad//s' */
    rtb_FuelConsumptionTable = HEV_SeriesParallel_P.rpm2rads_Gain_f *
      HEV_SeriesParallel_B.OUTPUT_1_0[3];

    /* RateTransition: '<S7>/Rate Transition9' */
    if (tmp_7) {
      /* RateTransition: '<S7>/Rate Transition9' */
      HEV_SeriesParallel_B.RateTransition9 = HEV_SeriesParallel_B.OUTPUT_1_0[4];
    }

    /* End of RateTransition: '<S7>/Rate Transition9' */

    /* Gain: '<S98>/Gain4' incorporates:
     *  Product: '<S98>/Product2'
     */
    HEV_SeriesParallel_B.Gain4_o = rtb_FuelConsumptionTable *
      HEV_SeriesParallel_B.RateTransition9 * HEV_SeriesParallel_P.Gain4_Gain_j;
    if (tmp_7) {
    }

    /* Gain: '<S10>/Ki' */
    HEV_SeriesParallel_B.Ki = HEV_SeriesParallel_P.HEV_Param.Control.ICE.Ki *
      HEV_SeriesParallel_B.Sum_i;

    /* Gain: '<S1>/Gain' */
    HEV_SeriesParallel_B.Gain_n = HEV_SeriesParallel_P.Gain_Gain_k *
      HEV_SeriesParallel_B.OUTPUT_1_0[13];

    /* Gain: '<S1>/Gain1' */
    HEV_SeriesParallel_B.Gain1 = HEV_SeriesParallel_P.Gain1_Gain *
      HEV_SeriesParallel_B.OUTPUT_1_0[3];

    /* Gain: '<S17>/Gen RPM to V' */
    HEV_SeriesParallel_B.GenRPMtoV = HEV_SeriesParallel_P.GenRPMtoV_Gain *
      HEV_SeriesParallel_B.Gain1;

    /* Gain: '<S17>/Ki' */
    HEV_SeriesParallel_B.Ki_p = HEV_SeriesParallel_P.HEV_Param.Control.Gen.Ki *
      HEV_SeriesParallel_B.Sum_g;

    /* Gain: '<S13>/Ki' */
    HEV_SeriesParallel_B.Ki_m = HEV_SeriesParallel_P.HEV_Param.Control.Mot.Ki *
      HEV_SeriesParallel_B.Sum_e;

    /* Gain: '<S13>/Mot RPM to V' */
    HEV_SeriesParallel_B.MotRPMtoV = HEV_SeriesParallel_P.MotRPMtoV_Gain *
      HEV_SeriesParallel_B.Gain_n;

    /* RateTransition generated from: '<S1>/Mode Logic' */
    if (tmp_7 && (HEV_SeriesParallel_M->Timing.RateInteraction.TID1_2 == 1)) {
      HEV_SeriesParallel_DW.SOC_Buffer = HEV_SeriesParallel_B.Gain_g;
    }

    /* Integrator: '<S14>/Integrator' */
    HEV_SeriesParallel_B.Integrator = HEV_SeriesParallel_X.Integrator_CSTATE;

    /* Gain: '<S14>/Gain' */
    HEV_SeriesParallel_B.Gain_a = 1.0 /
      HEV_SeriesParallel_P.HEV_Param.ICE.sensor_time_constant *
      HEV_SeriesParallel_B.Integrator;

    /* Sum: '<S14>/Sum' */
    HEV_SeriesParallel_B.Sum_c = HEV_SeriesParallel_B.OUTPUT_1_0[25] -
      HEV_SeriesParallel_B.Gain_a;

    /* RateTransition generated from: '<S1>/Mode Logic' */
    if (tmp_7 && (HEV_SeriesParallel_M->Timing.RateInteraction.TID1_2 == 1)) {
      HEV_SeriesParallel_DW.TmpRTBAtModeLogicInport1_Buffer =
        HEV_SeriesParallel_B.Gain_a;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      HEV_SeriesParallel_B.TmpRTBAtModeLogicOutport2 =
        HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      HEV_SeriesParallel_DW.wEng_Buffer = HEV_SeriesParallel_B.StateSpace;
    }

    /* SimscapeExecutionBlock: '<S71>/OUTPUT_1_1' */
    simulationData = (NeslSimulationData *)
      HEV_SeriesParallel_DW.OUTPUT_1_1_SimData;
    time_3 = rtb_SpdReqMot;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_3;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &HEV_SeriesParallel_DW.OUTPUT_1_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &HEV_SeriesParallel_DW.OUTPUT_1_1_Modes;
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = first_output;
    first_output = false;
    simulationData->mData->mIsSolverAssertCheck = first_output;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_8;
    tmp_6[0] = 0;
    tmp_5[0] = HEV_SeriesParallel_B.INPUT_1_1_1[0];
    tmp_5[1] = HEV_SeriesParallel_B.INPUT_1_1_1[1];
    tmp_5[2] = HEV_SeriesParallel_B.INPUT_1_1_1[2];
    tmp_5[3] = HEV_SeriesParallel_B.INPUT_1_1_1[3];
    tmp_6[1] = 4;
    tmp_5[4] = HEV_SeriesParallel_B.INPUT_2_1_1[0];
    tmp_5[5] = HEV_SeriesParallel_B.INPUT_2_1_1[1];
    tmp_5[6] = HEV_SeriesParallel_B.INPUT_2_1_1[2];
    tmp_5[7] = HEV_SeriesParallel_B.INPUT_2_1_1[3];
    tmp_6[2] = 8;
    tmp_5[8] = HEV_SeriesParallel_B.INPUT_3_1_1[0];
    tmp_5[9] = HEV_SeriesParallel_B.INPUT_3_1_1[1];
    tmp_5[10] = HEV_SeriesParallel_B.INPUT_3_1_1[2];
    tmp_5[11] = HEV_SeriesParallel_B.INPUT_3_1_1[3];
    tmp_6[3] = 12;
    tmp_5[12] = HEV_SeriesParallel_B.INPUT_4_1_1[0];
    tmp_5[13] = HEV_SeriesParallel_B.INPUT_4_1_1[1];
    tmp_5[14] = HEV_SeriesParallel_B.INPUT_4_1_1[2];
    tmp_5[15] = HEV_SeriesParallel_B.INPUT_4_1_1[3];
    tmp_6[4] = 16;
    memcpy(&tmp_5[16], &HEV_SeriesParallel_B.STATE_1[0], 71U * sizeof(real_T));
    tmp_6[5] = 87;
    simulationData->mData->mInputValues.mN = 87;
    simulationData->mData->mInputValues.mX = &tmp_5[0];
    simulationData->mData->mInputOffsets.mN = 6;
    simulationData->mData->mInputOffsets.mX = &tmp_6[0];
    simulationData->mData->mOutputs.mN = 1;
    simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_1;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_4 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_4;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)HEV_SeriesParallel_DW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diag);
    iy = ne_simulator_method((NeslSimulator *)
      HEV_SeriesParallel_DW.OUTPUT_1_1_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diag);
    if (iy != 0) {
      tmp_8 = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
      if (tmp_8) {
        msg_2 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(HEV_SeriesParallel_M, msg_2);
      }
    }

    /* Product: '<S72>/Product' incorporates:
     *  Constant: '<S72>/rad//s to rpm'
     */
    HEV_SeriesParallel_B.wEng = HEV_SeriesParallel_B.OUTPUT_1_0[15] *
      HEV_SeriesParallel_P.radstorpm_Value;
    if (tmp_7) {
    }

    /* Gain: '<S81>/Ki' */
    HEV_SeriesParallel_B.Ki_b =
      HEV_SeriesParallel_P.HEV_Param.Control.Veh_Spd.Ki *
      HEV_SeriesParallel_B.Sum;
    if (tmp_7) {
    }

    /* Integrator: '<S80>/Cumulative L' */
    HEV_SeriesParallel_B.CumulativeL = HEV_SeriesParallel_X.CumulativeL_CSTATE;
    if (tmp_7) {
      /* ToWorkspace: '<S80>/To Workspace' */
      if (rtmIsMajorTimeStep(HEV_SeriesParallel_M)) {
        rt_UpdateLogVar((LogVar *)(LogVar*)
                        (HEV_SeriesParallel_DW.ToWorkspace_PWORK.LoggedData),
                        &HEV_SeriesParallel_B.CumulativeL, 0);
      }
    }

    /* Lookup2D: '<S4>/Fuel Consumption Table' */
    rtb_FuelConsumptionTable = rt_Lookup2D_Normal
      (&HEV_SeriesParallel_P.HEV_Param.ICE.FC.Speed_Vector[0], 10,
       &HEV_SeriesParallel_P.HEV_Param.ICE.FC.Torque_Vector[0], 10,
       &HEV_SeriesParallel_P.HEV_Param.ICE.FC.Consumption_Table[0],
       HEV_SeriesParallel_B.wEng, HEV_SeriesParallel_B.OUTPUT_1_0[18]);

    /* Gain: '<S80>/g//s to Kg//s' */
    HEV_SeriesParallel_B.gstoKgs = HEV_SeriesParallel_P.gstoKgs_Gain *
      rtb_FuelConsumptionTable;

    /* Product: '<S80>/Divide' incorporates:
     *  Constant: '<S80>/Gasoline Density Kg//m^3'
     */
    HEV_SeriesParallel_B.Divide = HEV_SeriesParallel_B.gstoKgs /
      HEV_SeriesParallel_P.GasolineDensityKgm3_Value;

    /* Gain: '<S80>/m^3 to L' */
    HEV_SeriesParallel_B.m3toL = HEV_SeriesParallel_P.m3toL_Gain *
      HEV_SeriesParallel_B.Divide;

    /* Gain: '<S80>/m^3 to gal' */
    HEV_SeriesParallel_B.m3togal = HEV_SeriesParallel_P.m3togal_Gain *
      HEV_SeriesParallel_B.Divide;

    /* Gain: '<S80>/Kph to Kps' */
    HEV_SeriesParallel_B.KphtoKps = HEV_SeriesParallel_P.KphtoKps_Gain *
      HEV_SeriesParallel_B.OUTPUT_1_0[25];
  }

  if (rtmIsMajorTimeStep(HEV_SeriesParallel_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(HEV_SeriesParallel_M->rtwLogInfo,
                        (HEV_SeriesParallel_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(HEV_SeriesParallel_M)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T tmp_0[16];
    real_T time;
    int32_T tmp_2;
    int_T tmp_1[5];
    boolean_T tmp;

    /* Update for SimscapeExecutionBlock: '<S71>/STATE_1' */
    simulationData = (NeslSimulationData *)HEV_SeriesParallel_DW.STATE_1_SimData;
    time = HEV_SeriesParallel_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 58;
    simulationData->mData->mContStates.mX =
      &HEV_SeriesParallel_X.HEV_SeriesParallelElectricalGen[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &HEV_SeriesParallel_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 13;
    simulationData->mData->mModeVector.mX =
      &HEV_SeriesParallel_DW.STATE_1_Modes[0];
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (HEV_SeriesParallel_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&HEV_SeriesParallel_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&HEV_SeriesParallel_M->solverInfo);
    tmp_1[0] = 0;
    tmp_0[0] = HEV_SeriesParallel_B.INPUT_1_1_1[0];
    tmp_0[1] = HEV_SeriesParallel_B.INPUT_1_1_1[1];
    tmp_0[2] = HEV_SeriesParallel_B.INPUT_1_1_1[2];
    tmp_0[3] = HEV_SeriesParallel_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = HEV_SeriesParallel_B.INPUT_2_1_1[0];
    tmp_0[5] = HEV_SeriesParallel_B.INPUT_2_1_1[1];
    tmp_0[6] = HEV_SeriesParallel_B.INPUT_2_1_1[2];
    tmp_0[7] = HEV_SeriesParallel_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = HEV_SeriesParallel_B.INPUT_3_1_1[0];
    tmp_0[9] = HEV_SeriesParallel_B.INPUT_3_1_1[1];
    tmp_0[10] = HEV_SeriesParallel_B.INPUT_3_1_1[2];
    tmp_0[11] = HEV_SeriesParallel_B.INPUT_3_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = HEV_SeriesParallel_B.INPUT_4_1_1[0];
    tmp_0[13] = HEV_SeriesParallel_B.INPUT_4_1_1[1];
    tmp_0[14] = HEV_SeriesParallel_B.INPUT_4_1_1[2];
    tmp_0[15] = HEV_SeriesParallel_B.INPUT_4_1_1[3];
    tmp_1[4] = 16;
    simulationData->mData->mInputValues.mN = 16;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 5;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)
      HEV_SeriesParallel_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)
      HEV_SeriesParallel_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
      diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(HEV_SeriesParallel_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S71>/STATE_1' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(HEV_SeriesParallel_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(HEV_SeriesParallel_M)!=-1) &&
          !((rtmGetTFinal(HEV_SeriesParallel_M)-
             (((HEV_SeriesParallel_M->Timing.clockTick1+
                HEV_SeriesParallel_M->Timing.clockTickH1* 4294967296.0)) *
              1.0E-5)) > (((HEV_SeriesParallel_M->Timing.clockTick1+
                            HEV_SeriesParallel_M->Timing.clockTickH1*
                            4294967296.0)) * 1.0E-5) * (DBL_EPSILON))) {
        rtmSetErrorStatus(HEV_SeriesParallel_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&HEV_SeriesParallel_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++HEV_SeriesParallel_M->Timing.clockTick0)) {
      ++HEV_SeriesParallel_M->Timing.clockTickH0;
    }

    HEV_SeriesParallel_M->Timing.t[0] = rtsiGetSolverStopTime
      (&HEV_SeriesParallel_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    HEV_SeriesParallel_M->Timing.clockTick1++;
    if (!HEV_SeriesParallel_M->Timing.clockTick1) {
      HEV_SeriesParallel_M->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void HEV_SeriesParallel_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_HEV_SeriesParallel_T *_rtXdot;
  char *msg;
  real_T tmp[16];
  real_T time;
  int_T tmp_0[5];
  int_T iS;
  uint32_T ri;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_HEV_SeriesParallel_T *) HEV_SeriesParallel_M->derivs);

  /* Derivatives for Integrator: '<S81>/Limits [-5,5]' */
  lsat = (HEV_SeriesParallel_X.Limits55_CSTATE <=
          HEV_SeriesParallel_P.Limits55_LowerSat);
  usat = (HEV_SeriesParallel_X.Limits55_CSTATE >=
          HEV_SeriesParallel_P.Limits55_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (HEV_SeriesParallel_B.Ki_b > 0.0)) ||
      (usat && (HEV_SeriesParallel_B.Ki_b < 0.0))) {
    _rtXdot->Limits55_CSTATE = HEV_SeriesParallel_B.Ki_b;
  } else {
    /* in saturation */
    _rtXdot->Limits55_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S81>/Limits [-5,5]' */

  /* Derivatives for TransferFcn: '<S81>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE += HEV_SeriesParallel_P.u0HzLowpassFilter_A *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE;
  _rtXdot->u0HzLowpassFilter_CSTATE += HEV_SeriesParallel_B.OUTPUT_1_0[25];

  /* Derivatives for StateSpace: '<S76>/State Space' */
  _rtXdot->StateSpace_CSTATE = 0.0;
  for (ri = HEV_SeriesParallel_P.StateSpace_A_jc[0U]; ri <
       HEV_SeriesParallel_P.StateSpace_A_jc[1U]; ri++) {
    _rtXdot->StateSpace_CSTATE += HEV_SeriesParallel_P.StateSpace_A_pr *
      HEV_SeriesParallel_X.StateSpace_CSTATE;
  }

  for (ri = HEV_SeriesParallel_P.StateSpace_B_jc[0U]; ri <
       HEV_SeriesParallel_P.StateSpace_B_jc[1U]; ri++) {
    _rtXdot->StateSpace_CSTATE += HEV_SeriesParallel_P.StateSpace_B_pr *
      HEV_SeriesParallel_B.wEng;
  }

  /* End of Derivatives for StateSpace: '<S76>/State Space' */

  /* Derivatives for TransferFcn: '<S16>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_o = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE_o +=
    HEV_SeriesParallel_P.u0HzLowpassFilter_A_c *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_o;
  _rtXdot->u0HzLowpassFilter_CSTATE_o +=
    HEV_SeriesParallel_B.TmpRTBAtModeLogicOutport2;

  /* Derivatives for Integrator: '<S17>/Limits [-5,5]' */
  lsat = (HEV_SeriesParallel_X.Limits55_CSTATE_f <=
          HEV_SeriesParallel_P.Limits55_LowerSat_d);
  usat = (HEV_SeriesParallel_X.Limits55_CSTATE_f >=
          HEV_SeriesParallel_P.Limits55_UpperSat_f);
  if (((!lsat) && (!usat)) || (lsat && (HEV_SeriesParallel_B.Ki_p > 0.0)) ||
      (usat && (HEV_SeriesParallel_B.Ki_p < 0.0))) {
    _rtXdot->Limits55_CSTATE_f = HEV_SeriesParallel_B.Ki_p;
  } else {
    /* in saturation */
    _rtXdot->Limits55_CSTATE_f = 0.0;
  }

  /* End of Derivatives for Integrator: '<S17>/Limits [-5,5]' */

  /* Derivatives for TransferFcn: '<S17>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_g = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE_g +=
    HEV_SeriesParallel_P.u0HzLowpassFilter_A_o *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_g;
  _rtXdot->u0HzLowpassFilter_CSTATE_g += HEV_SeriesParallel_B.GenRPMtoV;

  /* Derivatives for Integrator: '<S13>/Limits [-5,5]' */
  lsat = (HEV_SeriesParallel_X.Limits55_CSTATE_n <=
          HEV_SeriesParallel_P.Limits55_LowerSat_c);
  usat = (HEV_SeriesParallel_X.Limits55_CSTATE_n >=
          HEV_SeriesParallel_P.Limits55_UpperSat_g);
  if (((!lsat) && (!usat)) || (lsat && (HEV_SeriesParallel_B.Ki_m > 0.0)) ||
      (usat && (HEV_SeriesParallel_B.Ki_m < 0.0))) {
    _rtXdot->Limits55_CSTATE_n = HEV_SeriesParallel_B.Ki_m;
  } else {
    /* in saturation */
    _rtXdot->Limits55_CSTATE_n = 0.0;
  }

  /* End of Derivatives for Integrator: '<S13>/Limits [-5,5]' */

  /* Derivatives for TransferFcn: '<S13>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_l = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE_l +=
    HEV_SeriesParallel_P.u0HzLowpassFilter_A_b *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_l;
  _rtXdot->u0HzLowpassFilter_CSTATE_l += HEV_SeriesParallel_B.MotRPMtoV;

  /* Derivatives for Integrator: '<S10>/Limits [0,1]' */
  lsat = (HEV_SeriesParallel_X.Limits01_CSTATE <=
          HEV_SeriesParallel_P.Limits01_LowerSat);
  usat = (HEV_SeriesParallel_X.Limits01_CSTATE >=
          HEV_SeriesParallel_P.Limits01_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (HEV_SeriesParallel_B.Ki > 0.0)) || (usat
       && (HEV_SeriesParallel_B.Ki < 0.0))) {
    _rtXdot->Limits01_CSTATE = HEV_SeriesParallel_B.Ki;
  } else {
    /* in saturation */
    _rtXdot->Limits01_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S10>/Limits [0,1]' */

  /* Derivatives for TransferFcn: '<S10>/20Hz Lowpass Filter' */
  _rtXdot->u0HzLowpassFilter_CSTATE_f = 0.0;
  _rtXdot->u0HzLowpassFilter_CSTATE_f +=
    HEV_SeriesParallel_P.u0HzLowpassFilter_A_a *
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_f;
  _rtXdot->u0HzLowpassFilter_CSTATE_f += HEV_SeriesParallel_B.StateSpace;

  /* Derivatives for SimscapeInputBlock: '<S71>/INPUT_4_1_1' */
  _rtXdot->HEV_SeriesParallelVehicleSimuli = (HEV_SeriesParallel_B.Gain -
    HEV_SeriesParallel_X.HEV_SeriesParallelVehicleSimuli) * 20.0;

  /* Derivatives for SimscapeExecutionBlock: '<S71>/STATE_1' */
  simulationData = (NeslSimulationData *)HEV_SeriesParallel_DW.STATE_1_SimData;
  time = HEV_SeriesParallel_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 58;
  simulationData->mData->mContStates.mX =
    &HEV_SeriesParallel_X.HEV_SeriesParallelElectricalGen[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &HEV_SeriesParallel_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 13;
  simulationData->mData->mModeVector.mX = &HEV_SeriesParallel_DW.STATE_1_Modes[0];
  lsat = false;
  simulationData->mData->mFoundZcEvents = lsat;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (HEV_SeriesParallel_M);
  lsat = false;
  simulationData->mData->mIsSolverAssertCheck = lsat;
  simulationData->mData->mIsSolverCheckingCIC = false;
  lsat = rtsiIsSolverComputingJacobian(&HEV_SeriesParallel_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = lsat;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&HEV_SeriesParallel_M->solverInfo);
  tmp_0[0] = 0;
  tmp[0] = HEV_SeriesParallel_B.INPUT_1_1_1[0];
  tmp[1] = HEV_SeriesParallel_B.INPUT_1_1_1[1];
  tmp[2] = HEV_SeriesParallel_B.INPUT_1_1_1[2];
  tmp[3] = HEV_SeriesParallel_B.INPUT_1_1_1[3];
  tmp_0[1] = 4;
  tmp[4] = HEV_SeriesParallel_B.INPUT_2_1_1[0];
  tmp[5] = HEV_SeriesParallel_B.INPUT_2_1_1[1];
  tmp[6] = HEV_SeriesParallel_B.INPUT_2_1_1[2];
  tmp[7] = HEV_SeriesParallel_B.INPUT_2_1_1[3];
  tmp_0[2] = 8;
  tmp[8] = HEV_SeriesParallel_B.INPUT_3_1_1[0];
  tmp[9] = HEV_SeriesParallel_B.INPUT_3_1_1[1];
  tmp[10] = HEV_SeriesParallel_B.INPUT_3_1_1[2];
  tmp[11] = HEV_SeriesParallel_B.INPUT_3_1_1[3];
  tmp_0[3] = 12;
  tmp[12] = HEV_SeriesParallel_B.INPUT_4_1_1[0];
  tmp[13] = HEV_SeriesParallel_B.INPUT_4_1_1[1];
  tmp[14] = HEV_SeriesParallel_B.INPUT_4_1_1[2];
  tmp[15] = HEV_SeriesParallel_B.INPUT_4_1_1[3];
  tmp_0[4] = 16;
  simulationData->mData->mInputValues.mN = 16;
  simulationData->mData->mInputValues.mX = &tmp[0];
  simulationData->mData->mInputOffsets.mN = 5;
  simulationData->mData->mInputOffsets.mX = &tmp_0[0];
  simulationData->mData->mDx.mN = 58;
  simulationData->mData->mDx.mX = &_rtXdot->HEV_SeriesParallelElectricalGen[0];
  diagnosticManager = (NeuDiagnosticManager *)
    HEV_SeriesParallel_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  iS = ne_simulator_method((NeslSimulator *)
    HEV_SeriesParallel_DW.STATE_1_Simulator, NESL_SIM_DERIVATIVES,
    simulationData, diagnosticManager);
  if (iS != 0) {
    lsat = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
    if (lsat) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(HEV_SeriesParallel_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S71>/STATE_1' */

  /* Derivatives for Integrator: '<S43>/Initial charge Ah0' */
  _rtXdot->InitialchargeAh0_CSTATE = HEV_SeriesParallel_B.OUTPUT_1_0[7];

  /* Derivatives for Integrator: '<S14>/Integrator' */
  _rtXdot->Integrator_CSTATE = HEV_SeriesParallel_B.Sum_c;

  /* Derivatives for Integrator: '<S80>/Cumulative L' */
  _rtXdot->CumulativeL_CSTATE = HEV_SeriesParallel_B.m3toL;

  /* Derivatives for Integrator: '<S80>/Cumulative Gal' */
  _rtXdot->CumulativeGal_CSTATE = HEV_SeriesParallel_B.m3togal;

  /* Derivatives for Integrator: '<S80>/Cumulative Distance Km' */
  _rtXdot->CumulativeDistanceKm_CSTATE = HEV_SeriesParallel_B.KphtoKps;
}

/* Model step function for TID2 */
void HEV_SeriesParallel_step2(void)    /* Sample time: [0.1s, 0.0s] */
{
  /* RateTransition generated from: '<S1>/Mode Logic' */
  HEV_SeriesParallel_B.TmpRTBAtModeLogicInport1 =
    HEV_SeriesParallel_DW.TmpRTBAtModeLogicInport1_Buffer;

  /* Chart: '<S1>/Mode Logic' incorporates:
   *  Constant: '<S1>/Constant'
   *  RateTransition generated from: '<S1>/Mode Logic'
   * */
  /* Gateway: Control/Mode Logic */
  /* During: Control/Mode Logic */
  if (HEV_SeriesParallel_DW.is_active_c3_HEV_SeriesParallel == 0) {
    /* Entry: Control/Mode Logic */
    HEV_SeriesParallel_DW.is_active_c3_HEV_SeriesParallel = 1U;

    /* Entry Internal: Control/Mode Logic */
    /* Transition: '<S12>:18' */
    HEV_SeriesParallel_DW.is_c3_HEV_SeriesParallel =
      HEV_SeriesParall_IN_Motion_mode;

    /* Entry Internal 'Motion_mode': '<S12>:9' */
    /* Transition: '<S12>:11' */
    HEV_SeriesParallel_DW.is_Motion_mode = HEV_SeriesParalle_IN_Start_mode;

    /* RateTransition generated from: '<S1>/Mode Logic' */
    /* Entry 'Start_mode': '<S12>:4' */
    HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;

    /* RateTransition generated from: '<S15>/Select Logic' */
    HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;
  } else if (HEV_SeriesParallel_DW.is_c3_HEV_SeriesParallel ==
             HEV_SeriesParalle_IN_Brake_mode) {
    /* RateTransition generated from: '<S1>/Mode Logic' */
    HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;

    /* RateTransition generated from: '<S15>/Select Logic' */
    HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;

    /* During 'Brake_mode': '<S12>:5' */
    if (HEV_SeriesParallel_P.Constant_Value_i < 0.05) {
      /* Transition: '<S12>:17' */
      HEV_SeriesParallel_DW.is_c3_HEV_SeriesParallel =
        HEV_SeriesParall_IN_Motion_mode;

      /* Entry Internal 'Motion_mode': '<S12>:9' */
      /* Transition: '<S12>:11' */
      HEV_SeriesParallel_DW.is_Motion_mode = HEV_SeriesParalle_IN_Start_mode;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      /* Entry 'Start_mode': '<S12>:4' */
      HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;
    }

    /* During 'Motion_mode': '<S12>:9' */
  } else if (HEV_SeriesParallel_P.Constant_Value_i >= 0.05) {
    /* Transition: '<S12>:16' */
    /* Exit Internal 'Motion_mode': '<S12>:9' */
    /* Exit Internal 'Normal_mode': '<S12>:1' */
    /* Exit Internal 'Cruise_mode': '<S12>:2' */
    HEV_SeriesParallel_DW.is_Cruise_mode = HEV_SeriesPa_IN_NO_ACTIVE_CHILD;
    HEV_SeriesParallel_DW.is_Normal_mode = HEV_SeriesPa_IN_NO_ACTIVE_CHILD;
    HEV_SeriesParallel_DW.is_Motion_mode = HEV_SeriesPa_IN_NO_ACTIVE_CHILD;
    HEV_SeriesParallel_DW.is_c3_HEV_SeriesParallel =
      HEV_SeriesParalle_IN_Brake_mode;

    /* RateTransition generated from: '<S1>/Mode Logic' */
    /* Entry 'Brake_mode': '<S12>:5' */
    HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;

    /* RateTransition generated from: '<S15>/Select Logic' */
    HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;
  } else if (HEV_SeriesParallel_DW.is_Motion_mode ==
             HEV_SeriesParall_IN_Normal_mode) {
    /* RateTransition generated from: '<S15>/Select Logic' */
    HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf = 1.0;

    /* During 'Normal_mode': '<S12>:1' */
    if (HEV_SeriesParallel_DW.wEng_Buffer <= HEV_SeriesParallel_EngOffRPM) {
      /* Transition: '<S12>:12' */
      /* Exit Internal 'Normal_mode': '<S12>:1' */
      /* Exit Internal 'Cruise_mode': '<S12>:2' */
      HEV_SeriesParallel_DW.is_Cruise_mode = HEV_SeriesPa_IN_NO_ACTIVE_CHILD;
      HEV_SeriesParallel_DW.is_Normal_mode = HEV_SeriesPa_IN_NO_ACTIVE_CHILD;
      HEV_SeriesParallel_DW.is_Motion_mode = HEV_SeriesParalle_IN_Start_mode;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      /* Entry 'Start_mode': '<S12>:4' */
      HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;

      /* RateTransition generated from: '<S15>/Select Logic' */
      HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;
    } else if (HEV_SeriesParallel_DW.is_Normal_mode ==
               HEV_SeriesPa_IN_Accelerate_mode) {
      /* RateTransition generated from: '<S1>/Mode Logic' */
      HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;

      /* During 'Accelerate_mode': '<S12>:3' */
      if (((HEV_SeriesParallel_B.TmpRTBAtModeLogicInport1 > 0.998 *
            HEV_SeriesParallel_oldspeed()) &&
           (HEV_SeriesParallel_B.TmpRTBAtModeLogicInport1 < 1.002 *
            HEV_SeriesParallel_oldspeed())) || (HEV_SeriesParallel_DW.SOC_Buffer
           <= 30.0)) {
        /* Transition: '<S12>:10' */
        HEV_SeriesParallel_DW.is_Normal_mode = HEV_SeriesParall_IN_Cruise_mode;

        /* Entry 'Cruise_mode': '<S12>:2' */
        /* Entry Internal 'Cruise_mode': '<S12>:2' */
        /* Transition: '<S12>:13' */
        HEV_SeriesParallel_DW.is_Cruise_mode = HEV_SeriesParallel_IN_charge;

        /* RateTransition generated from: '<S1>/Mode Logic' */
        /* Entry 'charge': '<S12>:8' */
        HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;
      }

      /* During 'Cruise_mode': '<S12>:2' */
    } else if (((HEV_SeriesParallel_B.TmpRTBAtModeLogicInport1 < 0.998 *
                 HEV_SeriesParallel_oldspeed()) ||
                (HEV_SeriesParallel_B.TmpRTBAtModeLogicInport1 > 1.002 *
                 HEV_SeriesParallel_oldspeed())) &&
               (HEV_SeriesParallel_DW.SOC_Buffer > 30.0)) {
      /* Transition: '<S12>:15' */
      /* Exit Internal 'Cruise_mode': '<S12>:2' */
      HEV_SeriesParallel_DW.is_Cruise_mode = HEV_SeriesPa_IN_NO_ACTIVE_CHILD;
      HEV_SeriesParallel_DW.is_Normal_mode = HEV_SeriesPa_IN_Accelerate_mode;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      /* Entry 'Accelerate_mode': '<S12>:3' */
      HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;
    } else if (HEV_SeriesParallel_DW.is_Cruise_mode ==
               HEV_SeriesParallel_IN_charge) {
      /* RateTransition generated from: '<S1>/Mode Logic' */
      HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;

      /* During 'charge': '<S12>:8' */
      if (HEV_SeriesParallel_DW.SOC_Buffer > 99.9) {
        /* Transition: '<S12>:19' */
        HEV_SeriesParallel_DW.is_Cruise_mode = HEV_SeriesParallel_IN_nocharge;

        /* RateTransition generated from: '<S1>/Mode Logic' */
        /* Entry 'nocharge': '<S12>:7' */
        HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;
      }
    } else {
      /* RateTransition generated from: '<S1>/Mode Logic' */
      HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;

      /* During 'nocharge': '<S12>:7' */
      if (HEV_SeriesParallel_DW.SOC_Buffer < 30.0) {
        /* Transition: '<S12>:20' */
        HEV_SeriesParallel_DW.is_Cruise_mode = HEV_SeriesParallel_IN_charge;

        /* RateTransition generated from: '<S1>/Mode Logic' */
        /* Entry 'charge': '<S12>:8' */
        HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;
      }
    }
  } else {
    /* RateTransition generated from: '<S1>/Mode Logic' */
    HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 1.0;

    /* RateTransition generated from: '<S15>/Select Logic' */
    HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf = 0.0;

    /* During 'Start_mode': '<S12>:4' */
    if (HEV_SeriesParallel_DW.wEng_Buffer > HEV_SeriesParallel_EngOnRPM) {
      /* Transition: '<S12>:21' */
      HEV_SeriesParallel_DW.is_Motion_mode = HEV_SeriesParall_IN_Normal_mode;

      /* RateTransition generated from: '<S15>/Select Logic' */
      /* Entry 'Normal_mode': '<S12>:1' */
      HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf = 1.0;

      /* Entry Internal 'Normal_mode': '<S12>:1' */
      /* Transition: '<S12>:14' */
      HEV_SeriesParallel_DW.is_Normal_mode = HEV_SeriesPa_IN_Accelerate_mode;

      /* RateTransition generated from: '<S1>/Mode Logic' */
      /* Entry 'Accelerate_mode': '<S12>:3' */
      HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe = 0.0;
    }
  }

  /* End of Chart: '<S1>/Mode Logic' */

  /* ManualSwitch: '<S15>/Select Logic' */
  if (HEV_SeriesParallel_P.SelectLogic_CurrentSetting_n == 1) {
    /* RateTransition generated from: '<S15>/Select Logic' incorporates:
     *  Constant: '<S15>/Constant'
     */
    HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf =
      HEV_SeriesParallel_P.Constant_Value;
  }

  /* End of ManualSwitch: '<S15>/Select Logic' */
}

/* Model initialize function */
void HEV_SeriesParallel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  HEV_SeriesParallel_P.LimitBrk_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)HEV_SeriesParallel_M, 0,
                sizeof(RT_MODEL_HEV_SeriesParallel_T));

  /* Set task counter limit used by the static main program */
  (HEV_SeriesParallel_M)->Timing.TaskCounters.cLimit[0] = 1;
  (HEV_SeriesParallel_M)->Timing.TaskCounters.cLimit[1] = 1;
  (HEV_SeriesParallel_M)->Timing.TaskCounters.cLimit[2] = 10000;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&HEV_SeriesParallel_M->solverInfo,
                          &HEV_SeriesParallel_M->Timing.simTimeStep);
    rtsiSetTPtr(&HEV_SeriesParallel_M->solverInfo, &rtmGetTPtr
                (HEV_SeriesParallel_M));
    rtsiSetStepSizePtr(&HEV_SeriesParallel_M->solverInfo,
                       &HEV_SeriesParallel_M->Timing.stepSize0);
    rtsiSetdXPtr(&HEV_SeriesParallel_M->solverInfo,
                 &HEV_SeriesParallel_M->derivs);
    rtsiSetContStatesPtr(&HEV_SeriesParallel_M->solverInfo, (real_T **)
                         &HEV_SeriesParallel_M->contStates);
    rtsiSetNumContStatesPtr(&HEV_SeriesParallel_M->solverInfo,
      &HEV_SeriesParallel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&HEV_SeriesParallel_M->solverInfo,
      &HEV_SeriesParallel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&HEV_SeriesParallel_M->solverInfo,
      &HEV_SeriesParallel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&HEV_SeriesParallel_M->solverInfo,
      &HEV_SeriesParallel_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&HEV_SeriesParallel_M->solverInfo, (boolean_T**)
      &HEV_SeriesParallel_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&HEV_SeriesParallel_M->solverInfo, (&rtmGetErrorStatus
      (HEV_SeriesParallel_M)));
    rtsiSetSolverMassMatrixIr(&HEV_SeriesParallel_M->solverInfo,
      HEV_SeriesParallel_MassMatrix.ir);
    rtsiSetSolverMassMatrixJc(&HEV_SeriesParallel_M->solverInfo,
      HEV_SeriesParallel_MassMatrix.jc);
    rtsiSetSolverMassMatrixPr(&HEV_SeriesParallel_M->solverInfo,
      HEV_SeriesParallel_MassMatrix.pr);
    rtsiSetRTModelPtr(&HEV_SeriesParallel_M->solverInfo, HEV_SeriesParallel_M);
  }

  rtsiSetSimTimeStep(&HEV_SeriesParallel_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&HEV_SeriesParallel_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&HEV_SeriesParallel_M->solverInfo, false);
  HEV_SeriesParallel_M->intgData.x0 = HEV_SeriesParallel_M->odeX0;
  HEV_SeriesParallel_M->intgData.f0 = HEV_SeriesParallel_M->odeF0;
  HEV_SeriesParallel_M->intgData.x1start = HEV_SeriesParallel_M->odeX1START;
  HEV_SeriesParallel_M->intgData.f1 = HEV_SeriesParallel_M->odeF1;
  HEV_SeriesParallel_M->intgData.Delta = HEV_SeriesParallel_M->odeDELTA;
  HEV_SeriesParallel_M->intgData.E = HEV_SeriesParallel_M->odeE;
  HEV_SeriesParallel_M->intgData.fac = HEV_SeriesParallel_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = HEV_SeriesParallel_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(HEV_SeriesParallel_M->odeFAC)/sizeof(real_T));
         i++) {
      f[i] = 1.5e-8;
    }
  }

  HEV_SeriesParallel_M->intgData.DFDX = HEV_SeriesParallel_M->odeDFDX;
  HEV_SeriesParallel_M->intgData.W = HEV_SeriesParallel_M->odeW;
  HEV_SeriesParallel_M->intgData.pivots = HEV_SeriesParallel_M->odePIVOTS;
  HEV_SeriesParallel_M->intgData.xtmp = HEV_SeriesParallel_M->odeXTMP;
  HEV_SeriesParallel_M->intgData.ztmp = HEV_SeriesParallel_M->odeZTMP;
  HEV_SeriesParallel_M->intgData.M = HEV_SeriesParallel_M->odeMASSMATRIX_M;
  HEV_SeriesParallel_M->intgData.M1 = HEV_SeriesParallel_M->odeMASSMATRIX_M1;
  HEV_SeriesParallel_M->intgData.xdot = HEV_SeriesParallel_M->odeXDOT;
  HEV_SeriesParallel_M->intgData.Edot = HEV_SeriesParallel_M->odeEDOT;
  HEV_SeriesParallel_M->intgData.fminusMxdot = HEV_SeriesParallel_M->odeFMXDOT;
  HEV_SeriesParallel_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&HEV_SeriesParallel_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&HEV_SeriesParallel_M->solverInfo, 1);
  HEV_SeriesParallel_M->contStates = ((X_HEV_SeriesParallel_T *)
    &HEV_SeriesParallel_X);
  HEV_SeriesParallel_M->contStateDisabled = ((XDis_HEV_SeriesParallel_T *)
    &HEV_SeriesParallel_XDis);
  HEV_SeriesParallel_M->Timing.tStart = (0.0);
  HEV_SeriesParallel_M->massMatrixType = ((ssMatrixType)3);
  HEV_SeriesParallel_M->massMatrixNzMax = (36);
  HEV_SeriesParallel_M->massMatrixIr = (HEV_SeriesParallel_MassMatrix.ir);
  HEV_SeriesParallel_M->massMatrixJc = (HEV_SeriesParallel_MassMatrix.jc);
  HEV_SeriesParallel_M->massMatrixPr = (HEV_SeriesParallel_MassMatrix.pr);
  rtsiSetSolverMassMatrixType(&HEV_SeriesParallel_M->solverInfo, (ssMatrixType)3);
  rtsiSetSolverMassMatrixNzMax(&HEV_SeriesParallel_M->solverInfo, 36);
  rtsiSetSolverData(&HEV_SeriesParallel_M->solverInfo, (void *)
                    &HEV_SeriesParallel_M->intgData);
  rtsiSetSolverName(&HEV_SeriesParallel_M->solverInfo,"ode14x");
  rtmSetTPtr(HEV_SeriesParallel_M, &HEV_SeriesParallel_M->Timing.tArray[0]);
  rtmSetTFinal(HEV_SeriesParallel_M, 195.00000000000003);
  HEV_SeriesParallel_M->Timing.stepSize0 = 1.0E-5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    HEV_SeriesParallel_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(HEV_SeriesParallel_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(HEV_SeriesParallel_M->rtwLogInfo, (NULL));
    rtliSetLogT(HEV_SeriesParallel_M->rtwLogInfo, "tout");
    rtliSetLogX(HEV_SeriesParallel_M->rtwLogInfo, "");
    rtliSetLogXFinal(HEV_SeriesParallel_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(HEV_SeriesParallel_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(HEV_SeriesParallel_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(HEV_SeriesParallel_M->rtwLogInfo, 0);
    rtliSetLogDecimation(HEV_SeriesParallel_M->rtwLogInfo, 1);
    rtliSetLogY(HEV_SeriesParallel_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(HEV_SeriesParallel_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(HEV_SeriesParallel_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &HEV_SeriesParallel_B), 0,
                sizeof(B_HEV_SeriesParallel_T));

  /* states (continuous) */
  {
    (void) memset((void *)&HEV_SeriesParallel_X, 0,
                  sizeof(X_HEV_SeriesParallel_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&HEV_SeriesParallel_XDis, 0,
                  sizeof(XDis_HEV_SeriesParallel_T));
  }

  /* global mass matrix */
  {
    int_T *ir = HEV_SeriesParallel_MassMatrix.ir;
    int_T *jc = HEV_SeriesParallel_MassMatrix.jc;
    real_T *pr = HEV_SeriesParallel_MassMatrix.pr;
    (void) memset((void *)ir, 0,
                  36*sizeof(int_T));
    (void) memset((void *)jc, 0,
                  (74+1)*sizeof(int_T));
    (void) memset((void *)pr, 0,
                  36*sizeof(real_T));
  }

  /* states (dwork) */
  (void) memset((void *)&HEV_SeriesParallel_DW, 0,
                sizeof(DW_HEV_SeriesParallel_T));

  /* Root-level init GlobalMassMatrixPr offset */
  {
    HEV_SeriesParallel_DW.STATE_1_MASS_MATRIX_PR = 11;/* '<S71>/STATE_1' */
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(HEV_SeriesParallel_M->rtwLogInfo, 0.0,
    rtmGetTFinal(HEV_SeriesParallel_M), HEV_SeriesParallel_M->Timing.stepSize0,
    (&rtmGetErrorStatus(HEV_SeriesParallel_M)));

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeslRtpManager *manager;
    NeslRtpManager *manager_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp_0;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    char *msg;
    char *msg_0;
    char *msg_1;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp;

    /* SetupRuntimeResources for ToWorkspace: '<S80>/To Workspace' */
    {
      int_T dimensions[1] = { 1 };

      HEV_SeriesParallel_DW.ToWorkspace_PWORK.LoggedData = rt_CreateLogVar(
        HEV_SeriesParallel_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(HEV_SeriesParallel_M),
        HEV_SeriesParallel_M->Timing.stepSize0,
        (&rtmGetErrorStatus(HEV_SeriesParallel_M)),
        "FuelUsedLiters",
        SS_DOUBLE,
        0,
        0,
        0,
        1,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        (NULL),
        1,
        1,
        1.0E-5,
        1);
      if (HEV_SeriesParallel_DW.ToWorkspace_PWORK.LoggedData == (NULL))
        return;
    }

    /* Start for FromWorkspace: '<S5>/Drive Cycle 1' */
    {
      static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0,
        8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,
        20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0,
        32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0,
        44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0,
        56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0,
        68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,
        80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0,
        92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0,
        103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0,
        113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0,
        123.0, 124.0, 125.0, 126.0, 127.0, 128.0, 129.0, 130.0, 131.0, 132.0,
        133.0, 134.0, 135.0, 136.0, 137.0, 138.0, 139.0, 140.0, 141.0, 142.0,
        143.0, 144.0, 145.0, 146.0, 147.0, 148.0, 149.0, 150.0, 151.0, 152.0,
        153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0, 160.0, 161.0, 162.0,
        163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0, 171.0, 172.0,
        173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0, 182.0,
        183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0,
        193.0, 194.0, 195.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 3.8, 7.5, 11.3, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
        15.0, 15.0, 15.0, 12.0, 9.0, 6.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 2.7, 5.3, 8.0, 10.7, 13.3, 16.0, 18.7, 21.3, 24.0, 26.7, 29.3, 32.0,
        32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0,
        32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0, 32.0,
        29.1, 26.2, 23.3, 20.4, 17.5, 14.5, 11.6, 8.7, 5.8, 2.9, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 1.9, 3.8, 5.8, 7.7, 9.6, 11.5, 13.5, 15.4, 17.3,
        19.2, 21.2, 23.4, 25.0, 26.9, 28.8, 30.8, 32.7, 34.6, 36.5, 38.5, 40.4,
        42.3, 44.2, 46.2, 48.1, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 48.1, 46.2, 44.4, 42.5, 40.6, 38.8, 36.9,
        35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0,
        35.0, 35.0, 32.1, 29.2, 26.2, 23.3, 20.4, 17.5, 14.6, 11.7, 8.7, 5.8,
        2.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

      HEV_SeriesParallel_DW.DriveCycle1_PWORK.TimePtr = (void *) pTimeValues0;
      HEV_SeriesParallel_DW.DriveCycle1_PWORK.DataPtr = (void *) pDataValues0;
      HEV_SeriesParallel_DW.DriveCycle1_IWORK.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S5>/Drive Cycle 2' */
    {
      static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0,
        8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,
        20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0,
        32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0,
        44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0,
        56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0,
        68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,
        80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0,
        92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0,
        103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0,
        113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0,
        123.0, 124.0, 125.0, 126.0, 127.0, 128.0, 129.0, 130.0, 131.0, 132.0,
        133.0, 134.0, 135.0, 136.0, 137.0, 138.0, 139.0, 140.0, 141.0, 142.0,
        143.0, 144.0, 145.0, 146.0, 147.0, 148.0, 149.0, 150.0, 151.0, 152.0,
        153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0, 160.0, 161.0, 162.0,
        163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0, 171.0, 172.0,
        173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0, 182.0,
        183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0,
        193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0, 201.0, 202.0,
        203.0, 204.0, 205.0, 206.0, 207.0, 208.0, 209.0, 210.0, 211.0, 212.0,
        213.0, 214.0, 215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0,
        223.0, 224.0, 225.0, 226.0, 227.0, 228.0, 229.0, 230.0, 231.0, 232.0,
        233.0, 234.0, 235.0, 236.0, 237.0, 238.0, 239.0, 240.0, 241.0, 242.0,
        243.0, 244.0, 245.0, 246.0, 247.0, 248.0, 249.0, 250.0, 251.0, 252.0,
        253.0, 254.0, 255.0, 256.0, 257.0, 258.0, 259.0, 260.0, 261.0, 262.0,
        263.0, 264.0, 265.0, 266.0, 267.0, 268.0, 269.0, 270.0, 271.0, 272.0,
        273.0, 274.0, 275.0, 276.0, 277.0, 278.0, 279.0, 280.0, 281.0, 282.0,
        283.0, 284.0, 285.0, 286.0, 287.0, 288.0, 289.0, 290.0, 291.0, 292.0,
        293.0, 294.0, 295.0, 296.0, 297.0, 298.0, 299.0, 300.0, 301.0, 302.0,
        303.0, 304.0, 305.0, 306.0, 307.0, 308.0, 309.0, 310.0, 311.0, 312.0,
        313.0, 314.0, 315.0, 316.0, 317.0, 318.0, 319.0, 320.0, 321.0, 322.0,
        323.0, 324.0, 325.0, 326.0, 327.0, 328.0, 329.0, 330.0, 331.0, 332.0,
        333.0, 334.0, 335.0, 336.0, 337.0, 338.0, 339.0, 340.0, 341.0, 342.0,
        343.0, 344.0, 345.0, 346.0, 347.0, 348.0, 349.0, 350.0, 351.0, 352.0,
        353.0, 354.0, 355.0, 356.0, 357.0, 358.0, 359.0, 360.0, 361.0, 362.0,
        363.0, 364.0, 365.0, 366.0, 367.0, 368.0, 369.0, 370.0, 371.0, 372.0,
        373.0, 374.0, 375.0, 376.0, 377.0, 378.0, 379.0, 380.0, 381.0, 382.0,
        383.0, 384.0, 385.0, 386.0, 387.0, 388.0, 389.0, 390.0, 391.0, 392.0,
        393.0, 394.0, 395.0, 396.0, 397.0, 398.0, 399.0, 400.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0,
        6.0, 9.0, 12.0, 15.0, 15.0, 15.0, 17.2, 19.4, 21.7, 23.9, 26.1, 28.3,
        30.6, 32.8, 35.0, 35.0, 35.0, 36.9, 38.8, 40.6, 42.5, 44.4, 46.3, 48.1,
        50.0, 50.0, 50.0, 51.5, 53.1, 54.6, 56.2, 57.7, 59.2, 60.8, 62.3, 63.8,
        65.4, 66.9, 68.5, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 67.5, 65.0, 62.5, 60.0, 57.5, 55.0,
        52.5, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 51.5,
        53.1, 54.6, 56.2, 57.7, 59.2, 60.8, 62.3, 63.8, 65.4, 66.9, 68.5, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.9, 71.7, 72.6, 73.4, 74.3, 75.1, 76.0, 76.9, 77.7, 78.6,
        79.4, 80.3, 81.1, 82.0, 82.9, 83.7, 84.6, 85.4, 86.3, 87.1, 88.0, 88.9,
        89.7, 90.6, 91.4, 92.3, 93.1, 94.0, 94.9, 95.7, 96.6, 97.4, 98.3, 99.1,
        100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
        100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
        100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
        100.0, 101.0, 102.0, 103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0,
        110.0, 111.0, 112.0, 113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0,
        120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0,
        120.0, 117.5, 115.0, 112.5, 110.0, 107.5, 105.0, 102.5, 100.0, 97.5,
        95.0, 92.5, 90.0, 87.5, 85.0, 82.5, 80.0, 76.3, 72.5, 68.8, 65.0, 61.3,
        57.5, 53.8, 50.0, 45.0, 40.0, 35.0, 30.0, 25.0, 20.0, 15.0, 10.0, 5.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

      HEV_SeriesParallel_DW.DriveCycle2_PWORK.TimePtr = (void *) pTimeValues0;
      HEV_SeriesParallel_DW.DriveCycle2_PWORK.DataPtr = (void *) pDataValues0;
      HEV_SeriesParallel_DW.DriveCycle2_IWORK.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S5>/Drive Cycle 3' */
    {
      static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0,
        8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,
        20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0,
        32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0,
        44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0,
        56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0,
        68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,
        80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0,
        92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0,
        103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0,
        113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0,
        123.0, 124.0, 125.0, 126.0, 127.0, 128.0, 129.0, 130.0, 131.0, 132.0,
        133.0, 134.0, 135.0, 136.0, 137.0, 138.0, 139.0, 140.0, 141.0, 142.0,
        143.0, 144.0, 145.0, 146.0, 147.0, 148.0, 149.0, 150.0, 151.0, 152.0,
        153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0, 160.0, 161.0, 162.0,
        163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0, 171.0, 172.0,
        173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0, 182.0,
        183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0,
        193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0, 201.0, 202.0,
        203.0, 204.0, 205.0, 206.0, 207.0, 208.0, 209.0, 210.0, 211.0, 212.0,
        213.0, 214.0, 215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0,
        223.0, 224.0, 225.0, 226.0, 227.0, 228.0, 229.0, 230.0, 231.0, 232.0,
        233.0, 234.0, 235.0, 236.0, 237.0, 238.0, 239.0, 240.0, 241.0, 242.0,
        243.0, 244.0, 245.0, 246.0, 247.0, 248.0, 249.0, 250.0, 251.0, 252.0,
        253.0, 254.0, 255.0, 256.0, 257.0, 258.0, 259.0, 260.0, 261.0, 262.0,
        263.0, 264.0, 265.0, 266.0, 267.0, 268.0, 269.0, 270.0, 271.0, 272.0,
        273.0, 274.0, 275.0, 276.0, 277.0, 278.0, 279.0, 280.0, 281.0, 282.0,
        283.0, 284.0, 285.0, 286.0, 287.0, 288.0, 289.0, 290.0, 291.0, 292.0,
        293.0, 294.0, 295.0, 296.0, 297.0, 298.0, 299.0, 300.0, 301.0, 302.0,
        303.0, 304.0, 305.0, 306.0, 307.0, 308.0, 309.0, 310.0, 311.0, 312.0,
        313.0, 314.0, 315.0, 316.0, 317.0, 318.0, 319.0, 320.0, 321.0, 322.0,
        323.0, 324.0, 325.0, 326.0, 327.0, 328.0, 329.0, 330.0, 331.0, 332.0,
        333.0, 334.0, 335.0, 336.0, 337.0, 338.0, 339.0, 340.0, 341.0, 342.0,
        343.0, 344.0, 345.0, 346.0, 347.0, 348.0, 349.0, 350.0, 351.0, 352.0,
        353.0, 354.0, 355.0, 356.0, 357.0, 358.0, 359.0, 360.0, 361.0, 362.0,
        363.0, 364.0, 365.0, 366.0, 367.0, 368.0, 369.0, 370.0, 371.0, 372.0,
        373.0, 374.0, 375.0, 376.0, 377.0, 378.0, 379.0, 380.0, 381.0, 382.0,
        383.0, 384.0, 385.0, 386.0, 387.0, 388.0, 389.0, 390.0, 391.0, 392.0,
        393.0, 394.0, 395.0, 396.0, 397.0, 398.0, 399.0, 400.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0,
        6.0, 9.0, 12.0, 15.0, 15.0, 15.0, 17.2, 19.4, 21.7, 23.9, 26.1, 28.3,
        30.6, 32.8, 35.0, 35.0, 35.0, 36.9, 38.8, 40.6, 42.5, 44.4, 46.3, 48.1,
        50.0, 50.0, 50.0, 51.5, 53.1, 54.6, 56.2, 57.7, 59.2, 60.8, 62.3, 63.8,
        65.4, 66.9, 68.5, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 67.5, 65.0, 62.5, 60.0, 57.5, 55.0,
        52.5, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 51.5,
        53.1, 54.6, 56.2, 57.7, 59.2, 60.8, 62.3, 63.8, 65.4, 66.9, 68.5, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 70.8, 71.7, 72.5, 73.3, 74.2, 75.0, 75.8, 76.7, 77.5, 78.3,
        79.2, 80.0, 80.8, 81.7, 82.5, 83.3, 84.2, 85.0, 85.8, 86.7, 87.5, 88.3,
        89.2, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0,
        90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0,
        90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0,
        90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0,
        90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0,
        90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0,
        90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0,
        90.0, 87.5, 85.0, 82.5, 80.0, 76.3, 72.5, 68.8, 65.0, 61.3, 57.5, 53.8,
        50.0, 45.0, 40.0, 35.0, 30.0, 25.0, 20.0, 15.0, 10.0, 5.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0 } ;

      HEV_SeriesParallel_DW.DriveCycle3_PWORK.TimePtr = (void *) pTimeValues0;
      HEV_SeriesParallel_DW.DriveCycle3_PWORK.DataPtr = (void *) pDataValues0;
      HEV_SeriesParallel_DW.DriveCycle3_IWORK.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S5>/Drive Cycle 4' */
    {
      static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0,
        8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,
        20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0,
        32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0,
        44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0,
        56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0,
        68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,
        80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0,
        92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0,
        103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0,
        113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0,
        123.0, 124.0, 125.0, 126.0, 127.0, 128.0, 129.0, 130.0, 131.0, 132.0,
        133.0, 134.0, 135.0, 136.0, 137.0, 138.0, 139.0, 140.0, 141.0, 142.0,
        143.0, 144.0, 145.0, 146.0, 147.0, 148.0, 149.0, 150.0, 151.0, 152.0,
        153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0, 160.0, 161.0, 162.0,
        163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0, 171.0, 172.0,
        173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0, 182.0,
        183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0,
        193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0, 201.0, 202.0,
        203.0, 204.0, 205.0, 206.0, 207.0, 208.0, 209.0, 210.0, 211.0, 212.0,
        213.0, 214.0, 215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0,
        223.0, 224.0, 225.0, 226.0, 227.0, 228.0, 229.0, 230.0, 231.0, 232.0,
        233.0, 234.0, 235.0, 236.0, 237.0, 238.0, 239.0, 240.0, 241.0, 242.0,
        243.0, 244.0, 245.0, 246.0, 247.0, 248.0, 249.0, 250.0, 251.0, 252.0,
        253.0, 254.0, 255.0, 256.0, 257.0, 258.0, 259.0, 260.0, 261.0, 262.0,
        263.0, 264.0, 265.0, 266.0, 267.0, 268.0, 269.0, 270.0, 271.0, 272.0,
        273.0, 274.0, 275.0, 276.0, 277.0, 278.0, 279.0, 280.0, 281.0, 282.0,
        283.0, 284.0, 285.0, 286.0, 287.0, 288.0, 289.0, 290.0, 291.0, 292.0,
        293.0, 294.0, 295.0, 296.0, 297.0, 298.0, 299.0, 300.0, 301.0, 302.0,
        303.0, 304.0, 305.0, 306.0, 307.0, 308.0, 309.0, 310.0, 311.0, 312.0,
        313.0, 314.0, 315.0, 316.0, 317.0, 318.0, 319.0, 320.0, 321.0, 322.0,
        323.0, 324.0, 325.0, 326.0, 327.0, 328.0, 329.0, 330.0, 331.0, 332.0,
        333.0, 334.0, 335.0, 336.0, 337.0, 338.0, 339.0, 340.0, 341.0, 342.0,
        343.0, 344.0, 345.0, 346.0, 347.0, 348.0, 349.0, 350.0, 351.0, 352.0,
        353.0, 354.0, 355.0, 356.0, 357.0, 358.0, 359.0, 360.0, 361.0, 362.0,
        363.0, 364.0, 365.0, 366.0, 367.0, 368.0, 369.0, 370.0, 371.0, 372.0,
        373.0, 374.0, 375.0, 376.0, 377.0, 378.0, 379.0, 380.0, 381.0, 382.0,
        383.0, 384.0, 385.0, 386.0, 387.0, 388.0, 389.0, 390.0, 391.0, 392.0,
        393.0, 394.0, 395.0, 396.0, 397.0, 398.0, 399.0, 400.0, 401.0, 402.0,
        403.0, 404.0, 405.0, 406.0, 407.0, 408.0, 409.0, 410.0, 411.0, 412.0,
        413.0, 414.0, 415.0, 416.0, 417.0, 418.0, 419.0, 420.0, 421.0, 422.0,
        423.0, 424.0, 425.0, 426.0, 427.0, 428.0, 429.0, 430.0, 431.0, 432.0,
        433.0, 434.0, 435.0, 436.0, 437.0, 438.0, 439.0, 440.0, 441.0, 442.0,
        443.0, 444.0, 445.0, 446.0, 447.0, 448.0, 449.0, 450.0, 451.0, 452.0,
        453.0, 454.0, 455.0, 456.0, 457.0, 458.0, 459.0, 460.0, 461.0, 462.0,
        463.0, 464.0, 465.0, 466.0, 467.0, 468.0, 469.0, 470.0, 471.0, 472.0,
        473.0, 474.0, 475.0, 476.0, 477.0, 478.0, 479.0, 480.0, 481.0, 482.0,
        483.0, 484.0, 485.0, 486.0, 487.0, 488.0, 489.0, 490.0, 491.0, 492.0,
        493.0, 494.0, 495.0, 496.0, 497.0, 498.0, 499.0, 500.0, 501.0, 502.0,
        503.0, 504.0, 505.0, 506.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        4.838709677419355, 9.5161290322580641, 13.870967741935484,
        18.548387096774192, 23.064516129032256, 27.258064516129032,
        27.903225806451612, 29.193548387096772, 33.387096774193544, 35.0,
        36.129032258064512, 36.29032258064516, 35.645161290322577,
        34.677419354838712, 33.70967741935484, 32.903225806451609,
        31.93548387096774, 27.419354838709676, 24.032258064516128,
        24.032258064516128, 24.516129032258064, 25.0, 25.806451612903224,
        27.58064516129032, 30.806451612903224, 34.032258064516128,
        36.612903225806448, 36.935483870967744, 36.612903225806448,
        36.451612903225808, 34.354838709677416, 30.64516129032258,
        27.58064516129032, 25.483870967741936, 25.483870967741936,
        28.548387096774192, 31.93548387096774, 34.838709677419352,
        37.41935483870968, 39.032258064516128, 39.677419354838712,
        40.161290322580641, 40.322580645161288, 39.677419354838712,
        39.516129032258064, 39.838709677419352, 40.0, 39.838709677419352,
        39.677419354838712, 39.677419354838712, 40.483870967741936,
        41.29032258064516, 41.451612903225808, 40.967741935483872,
        40.161290322580641, 40.322580645161288, 40.967741935483872,
        41.935483870967744, 41.935483870967744, 41.451612903225808,
        42.096774193548384, 43.064516129032256, 44.354838709677416,
        46.129032258064512, 47.258064516129032, 48.064516129032256,
        48.548387096774192, 49.032258064516128, 49.516129032258064,
        49.516129032258064, 49.193548387096776, 49.032258064516128,
        48.87096774193548, 49.032258064516128, 49.677419354838712,
        49.032258064516128, 48.225806451612904, 47.58064516129032,
        48.064516129032256, 48.87096774193548, 49.516129032258064,
        49.838709677419352, 50.0, 49.838709677419352, 49.032258064516128,
        48.064516129032256, 48.225806451612904, 48.70967741935484,
        49.516129032258064, 50.322580645161288, 51.29032258064516,
        51.935483870967744, 52.258064516129032, 51.935483870967744,
        51.129032258064512, 46.129032258064512, 40.806451612903224,
        35.483870967741936, 30.161290322580644, 24.838709677419356,
        19.516129032258064, 14.193548387096774, 8.870967741935484,
        3.5483870967741935, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 5.32258064516129, 10.64516129032258, 15.96774193548387,
        21.29032258064516, 26.612903225806452, 31.93548387096774,
        35.806451612903224, 39.193548387096776, 41.612903225806448,
        42.58064516129032, 41.451612903225808, 40.483870967741936,
        39.838709677419352, 40.322580645161288, 40.645161290322577,
        40.967741935483872, 41.612903225806448, 43.87096774193548,
        42.741935483870968, 38.70967741935484, 36.612903225806448,
        31.29032258064516, 28.548387096774192, 27.741935483870968,
        29.193548387096772, 30.0, 32.258064516129032, 35.806451612903224,
        39.516129032258064, 44.032258064516128, 49.193548387096776,
        54.032258064516128, 58.387096774193544, 60.161290322580641,
        63.387096774193544, 65.3225806451613, 67.903225806451616,
        70.161290322580641, 72.741935483870961, 74.193548387096769,
        75.483870967741936, 76.612903225806448, 76.612903225806448,
        76.290322580645153, 76.129032258064512, 75.806451612903217,
        75.806451612903217, 75.806451612903217, 75.806451612903217,
        75.806451612903217, 76.129032258064512, 76.451612903225808,
        77.258064516129025, 78.2258064516129, 79.193548387096769,
        79.838709677419359, 80.645161290322577, 81.612903225806448,
        82.258064516129025, 83.064516129032256, 84.193548387096769,
        85.806451612903217, 87.258064516129025, 88.064516129032256,
        88.548387096774192, 88.709677419354833, 88.548387096774192,
        88.064516129032256, 88.064516129032256, 88.387096774193552,
        88.870967741935488, 89.516129032258064, 89.838709677419345,
        90.483870967741936, 90.806451612903217, 91.290322580645153,
        91.451612903225808, 91.451612903225808, 91.129032258064512,
        91.129032258064512, 91.129032258064512, 91.129032258064512,
        91.129032258064512, 91.129032258064512, 90.967741935483872,
        90.483870967741936, 90.0, 88.870967741935488, 88.064516129032256,
        87.41935483870968, 87.096774193548384, 86.612903225806448,
        86.451612903225808, 86.935483870967744, 87.096774193548384,
        87.258064516129025, 87.258064516129025, 86.774193548387089,
        86.129032258064512, 85.483870967741936, 84.838709677419359,
        84.032258064516128, 84.516129032258064, 83.870967741935488,
        83.709677419354833, 83.387096774193552, 83.064516129032256,
        83.2258064516129, 83.064516129032256, 85.161290322580641,
        84.032258064516128, 86.290322580645153, 86.290322580645153,
        87.096774193548384, 88.548387096774192, 89.354838709677423,
        89.6774193548387, 90.322580645161281, 90.322580645161281, 90.0,
        89.032258064516128, 87.903225806451616, 86.451612903225808,
        84.6774193548387, 83.064516129032256, 83.064516129032256,
        83.064516129032256, 82.41935483870968, 80.806451612903217,
        80.645161290322577, 80.806451612903217, 80.645161290322577, 80.0,
        79.838709677419359, 79.838709677419359, 79.838709677419359,
        79.193548387096769, 78.387096774193552, 77.58064516129032,
        76.129032258064512, 74.354838709677423, 72.58064516129032,
        70.645161290322577, 68.709677419354833, 66.935483870967744, 65.0,
        62.096774193548384, 59.677419354838705, 56.774193548387096,
        54.516129032258064, 52.419354838709673, 50.806451612903224,
        49.354838709677416, 49.193548387096776, 48.387096774193544,
        46.774193548387096, 44.354838709677416, 40.0, 34.677419354838712,
        32.41935483870968, 30.806451612903224, 29.838709677419352,
        27.419354838709676, 25.0, 20.161290322580644, 17.419354838709676,
        12.903225806451612, 7.5806451612903221, 2.258064516129032, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        1.6129032258064515, 6.935483870967742, 12.258064516129032,
        17.580645161290324, 22.903225806451612, 27.903225806451612,
        32.258064516129032, 36.29032258064516, 38.225806451612904,
        40.645161290322577, 42.903225806451609, 45.322580645161288,
        48.387096774193544, 49.677419354838712, 50.967741935483872,
        51.774193548387096, 52.903225806451609, 54.193548387096776,
        55.645161290322577, 55.806451612903224, 56.29032258064516,
        56.129032258064512, 55.645161290322577, 55.967741935483872,
        57.258064516129032, 58.064516129032256, 58.064516129032256,
        58.064516129032256, 58.064516129032256, 58.064516129032256,
        58.064516129032256, 58.225806451612904, 58.70967741935484,
        58.87096774193548, 58.70967741935484, 58.064516129032256,
        56.612903225806448, 55.0, 54.032258064516128, 50.645161290322577,
        46.774193548387096, 41.451612903225808, 37.096774193548384,
        32.741935483870968, 28.225806451612904, 23.387096774193548,
        19.35483870967742, 14.032258064516128, 8.7096774193548381,
        3.3870967741935485, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.193548387096774,
        9.5161290322580641, 14.838709677419354, 20.161290322580644,
        25.483870967741936, 30.806451612903224, 36.129032258064512,
        40.322580645161288, 41.29032258064516, 44.354838709677416,
        46.774193548387096, 48.387096774193544, 48.548387096774192,
        48.387096774193544, 47.903225806451609, 47.258064516129032,
        46.451612903225808, 45.161290322580641, 40.322580645161288, 35.0,
        29.677419354838708, 24.35483870967742, 19.032258064516128,
        13.709677419354838, 8.387096774193548, 3.064516129032258, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 5.32258064516129, 10.64516129032258, 15.96774193548387,
        21.29032258064516, 26.612903225806452, 31.93548387096774,
        37.258064516129032, 42.58064516129032, 44.838709677419352,
        46.935483870967744, 50.806451612903224, 53.225806451612904,
        54.193548387096776, 56.129032258064512, 56.612903225806448,
        57.419354838709673, 58.225806451612904, 58.064516129032256,
        58.225806451612904, 58.387096774193544, 58.064516129032256,
        57.58064516129032, 58.064516129032256, 58.064516129032256,
        57.419354838709673, 57.258064516129032, 57.096774193548384,
        56.774193548387096, 56.774193548387096, 56.774193548387096,
        56.774193548387096, 56.774193548387096, 56.774193548387096,
        56.451612903225808, 56.612903225806448, 56.774193548387096,
        57.258064516129032, 56.774193548387096, 56.451612903225808,
        56.451612903225808, 56.451612903225808, 56.129032258064512,
        55.806451612903224, 55.645161290322577, 54.032258064516128,
        51.612903225806448, 48.548387096774192, 45.161290322580641,
        41.129032258064512, 36.29032258064516, 31.93548387096774,
        26.612903225806452, 21.29032258064516, 16.612903225806452,
        11.612903225806452, 6.4516129032258061, 1.6129032258064515, 0.0, 0.0 } ;

      HEV_SeriesParallel_DW.DriveCycle4_PWORK.TimePtr = (void *) pTimeValues0;
      HEV_SeriesParallel_DW.DriveCycle4_PWORK.DataPtr = (void *) pDataValues0;
      HEV_SeriesParallel_DW.DriveCycle4_IWORK.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S5>/Drive Cycle 5' */
    {
      static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0,
        8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,
        20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0,
        32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0,
        44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0,
        56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0,
        68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,
        80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0,
        92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0,
        103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0,
        113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0,
        123.0, 124.0, 125.0, 126.0, 127.0, 128.0, 129.0, 130.0, 131.0, 132.0,
        133.0, 134.0, 135.0, 136.0, 137.0, 138.0, 139.0, 140.0, 141.0, 142.0,
        143.0, 144.0, 145.0, 146.0, 147.0, 148.0, 149.0, 150.0, 151.0, 152.0,
        153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0, 160.0, 161.0, 162.0,
        163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0, 171.0, 172.0,
        173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0, 182.0,
        183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0,
        193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0, 201.0, 202.0,
        203.0, 204.0, 205.0, 206.0, 207.0, 208.0, 209.0, 210.0, 211.0, 212.0,
        213.0, 214.0, 215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0,
        223.0, 224.0, 225.0, 226.0, 227.0, 228.0, 229.0, 230.0, 231.0, 232.0,
        233.0, 234.0, 235.0, 236.0, 237.0, 238.0, 239.0, 240.0, 241.0, 242.0,
        243.0, 244.0, 245.0, 246.0, 247.0, 248.0, 249.0, 250.0, 251.0, 252.0,
        253.0, 254.0, 255.0, 256.0, 257.0, 258.0, 259.0, 260.0, 261.0, 262.0,
        263.0, 264.0, 265.0, 266.0, 267.0, 268.0, 269.0, 270.0, 271.0, 272.0,
        273.0, 274.0, 275.0, 276.0, 277.0, 278.0, 279.0, 280.0, 281.0, 282.0,
        283.0, 284.0, 285.0, 286.0, 287.0, 288.0, 289.0, 290.0, 291.0, 292.0,
        293.0, 294.0, 295.0, 296.0, 297.0, 298.0, 299.0, 300.0, 301.0, 302.0,
        303.0, 304.0, 305.0, 306.0, 307.0, 308.0, 309.0, 310.0, 311.0, 312.0,
        313.0, 314.0, 315.0, 316.0, 317.0, 318.0, 319.0, 320.0, 321.0, 322.0,
        323.0, 324.0, 325.0, 326.0, 327.0, 328.0, 329.0, 330.0, 331.0, 332.0,
        333.0, 334.0, 335.0, 336.0, 337.0, 338.0, 339.0, 340.0, 341.0, 342.0,
        343.0, 344.0, 345.0, 346.0, 347.0, 348.0, 349.0, 350.0, 351.0, 352.0,
        353.0, 354.0, 355.0, 356.0, 357.0, 358.0, 359.0, 360.0, 361.0, 362.0,
        363.0, 364.0, 365.0, 366.0, 367.0, 368.0, 369.0, 370.0, 371.0, 372.0,
        373.0, 374.0, 375.0, 376.0, 377.0, 378.0, 379.0, 380.0, 381.0, 382.0,
        383.0, 384.0, 385.0, 386.0, 387.0, 388.0, 389.0, 390.0, 391.0, 392.0,
        393.0, 394.0, 395.0, 396.0, 397.0, 398.0, 399.0, 400.0, 401.0, 402.0,
        403.0, 404.0, 405.0, 406.0, 407.0, 408.0, 409.0, 410.0, 411.0, 412.0,
        413.0, 414.0, 415.0, 416.0, 417.0, 418.0, 419.0, 420.0, 421.0, 422.0,
        423.0, 424.0, 425.0, 426.0, 427.0, 428.0, 429.0, 430.0, 431.0, 432.0,
        433.0, 434.0, 435.0, 436.0, 437.0, 438.0, 439.0, 440.0, 441.0, 442.0,
        443.0, 444.0, 445.0, 446.0, 447.0, 448.0, 449.0, 450.0, 451.0, 452.0,
        453.0, 454.0, 455.0, 456.0, 457.0, 458.0, 459.0, 460.0, 461.0, 462.0,
        463.0, 464.0, 465.0, 466.0, 467.0, 468.0, 469.0, 470.0, 471.0, 472.0,
        473.0, 474.0, 475.0, 476.0, 477.0, 478.0, 479.0, 480.0, 481.0, 482.0,
        483.0, 484.0, 485.0, 486.0, 487.0, 488.0, 489.0, 490.0, 491.0, 492.0,
        493.0, 494.0, 495.0, 496.0, 497.0, 498.0, 499.0, 500.0, 501.0, 502.0,
        503.0, 504.0, 505.0, 506.0, 507.0, 508.0, 509.0, 510.0, 511.0, 512.0,
        513.0, 514.0, 515.0, 516.0, 517.0, 518.0, 519.0, 520.0, 521.0, 522.0,
        523.0, 524.0, 525.0, 526.0, 527.0, 528.0, 529.0, 530.0, 531.0, 532.0,
        533.0, 534.0, 535.0, 536.0, 537.0, 538.0, 539.0, 540.0, 541.0, 542.0,
        543.0, 544.0, 545.0, 546.0, 547.0, 548.0, 549.0, 550.0, 551.0, 552.0,
        553.0, 554.0, 555.0, 556.0, 557.0, 558.0, 559.0, 560.0, 561.0, 562.0,
        563.0, 564.0, 565.0, 566.0, 567.0, 568.0, 569.0, 570.0, 571.0, 572.0,
        573.0, 574.0, 575.0, 576.0, 577.0, 578.0, 579.0, 580.0, 581.0, 582.0,
        583.0, 584.0, 585.0, 586.0, 587.0, 588.0, 589.0, 590.0, 591.0, 592.0,
        593.0, 594.0, 595.0, 596.0, 597.0, 598.0, 599.0, 600.0, 601.0, 602.0,
        603.0, 604.0, 605.0, 606.0, 607.0, 608.0, 609.0, 610.0, 611.0, 612.0,
        613.0, 614.0, 615.0, 616.0, 617.0, 618.0, 619.0, 620.0, 621.0, 622.0,
        623.0, 624.0, 625.0, 626.0, 627.0, 628.0, 629.0, 630.0, 631.0, 632.0,
        633.0, 634.0, 635.0, 636.0, 637.0, 638.0, 639.0, 640.0, 641.0, 642.0,
        643.0, 644.0, 645.0, 646.0, 647.0, 648.0, 649.0, 650.0, 651.0, 652.0,
        653.0, 654.0, 655.0, 656.0, 657.0, 658.0, 659.0, 660.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.8571428571428581,
        5.7142857142857135, 8.571428571428573, 11.428571428571427,
        14.285714285714286, 17.142857142857146, 20.0, 20.0, 20.0, 20.0, 20.0,
        20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
        17.142857142857142, 14.285714285714286, 11.428571428571427,
        8.5714285714285712, 5.7142857142857135, 2.8571428571428568, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 2.8571428571428559, 5.7142857142857162, 8.571428571428573,
        11.428571428571427, 14.285714285714285, 17.142857142857146, 20.0,
        22.857142857142854, 25.714285714285712, 28.571428571428573,
        31.428571428571427, 34.285714285714292, 37.142857142857146, 40.0, 40.0,
        40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
        40.0, 40.0, 38.0, 36.0, 34.0, 32.0, 30.0, 28.0, 26.0, 24.0, 22.0, 20.0,
        20.0, 20.0, 21.666666666666668, 23.333333333333332, 25.0,
        26.666666666666668, 28.333333333333332, 30.0, 31.666666666666664,
        33.333333333333336, 35.0, 36.666666666666671, 38.333333333333329, 40.0,
        38.0, 36.0, 34.0, 32.0, 30.0, 28.0, 26.0, 24.0, 22.0, 20.0,
        17.142857142857142, 14.285714285714286, 11.428571428571427,
        8.5714285714285712, 5.7142857142857135, 2.8571428571428568, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 2.8571428571428581, 5.7142857142857135,
        8.571428571428573, 11.428571428571427, 14.285714285714286,
        17.142857142857146, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
        20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 17.142857142857142,
        14.285714285714286, 11.428571428571427, 8.5714285714285712,
        5.7142857142857135, 2.8571428571428568, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        2.8571428571428559, 5.7142857142857162, 8.571428571428573,
        11.428571428571427, 14.285714285714285, 17.142857142857146, 20.0,
        22.857142857142854, 25.714285714285712, 28.571428571428573,
        31.428571428571427, 34.285714285714292, 37.142857142857146, 40.0, 40.0,
        40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
        40.0, 40.0, 38.0, 36.0, 34.0, 32.0, 30.0, 28.0, 26.0, 24.0, 22.0, 20.0,
        20.0, 20.0, 21.666666666666668, 23.333333333333332, 25.0,
        26.666666666666668, 28.333333333333332, 30.0, 31.666666666666664,
        33.333333333333336, 35.0, 36.666666666666671, 38.333333333333329, 40.0,
        38.0, 36.0, 34.0, 32.0, 30.0, 28.0, 26.0, 24.0, 22.0, 20.0,
        17.142857142857142, 14.285714285714286, 11.428571428571427,
        8.5714285714285712, 5.7142857142857135, 2.8571428571428568, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 2.8571428571428581, 5.7142857142857135,
        8.571428571428573, 11.428571428571427, 14.285714285714286,
        17.142857142857146, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
        20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 17.142857142857142,
        14.285714285714286, 11.428571428571427, 8.5714285714285712,
        5.7142857142857135, 2.8571428571428568, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        2.8571428571428559, 5.7142857142857162, 8.571428571428573,
        11.428571428571427, 14.285714285714285, 17.142857142857146, 20.0,
        22.857142857142854, 25.714285714285712, 28.571428571428573,
        31.428571428571427, 34.285714285714292, 37.142857142857146, 40.0, 40.0,
        40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0,
        40.0, 40.0, 38.0, 36.0, 34.0, 32.0, 30.0, 28.0, 26.0, 24.0, 22.0, 20.0,
        20.0, 20.0, 21.666666666666668, 23.333333333333332, 25.0,
        26.666666666666668, 28.333333333333332, 30.0, 31.666666666666664,
        33.333333333333336, 35.0, 36.666666666666671, 38.333333333333329, 40.0,
        38.0, 36.0, 34.0, 32.0, 30.0, 28.0, 26.0, 24.0, 22.0, 20.0,
        17.142857142857142, 14.285714285714286, 11.428571428571427,
        8.5714285714285712, 5.7142857142857135, 2.8571428571428568, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.777777777777779,
        5.555555555555558, 8.3333333333333321, 11.111111111111111,
        13.888888888888889, 16.666666666666668, 19.444444444444443,
        22.222222222222221, 25.0, 27.777777777777779, 30.555555555555557,
        33.333333333333336, 36.111111111111107, 38.888888888888893,
        41.666666666666671, 44.444444444444443, 47.222222222222221, 50.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 47.5,
        45.0, 42.5, 40.0, 40.0, 40.0, 40.0, 40.0, 41.25, 42.5, 43.75, 45.0,
        46.25, 47.5, 48.75, 50.0, 51.25, 52.5, 53.75, 55.0, 56.25, 57.5, 58.75,
        60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0,
        60.909090909090914, 61.818181818181813, 62.727272727272734,
        63.63636363636364, 64.545454545454547, 65.454545454545453,
        66.363636363636374, 67.27272727272728, 68.181818181818173,
        69.0909090909091, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0, 70.0,
        70.0, 70.0, 68.0, 66.0, 64.0, 62.0, 60.0, 58.0, 56.0, 54.0, 52.0, 50.0,
        50.0, 50.0, 50.0, 50.0, 50.909090909090907, 51.81818181818182,
        52.727272727272727, 53.63636363636364, 54.545454545454547,
        55.454545454545453, 56.36363636363636, 57.272727272727273,
        58.18181818181818, 59.090909090909093, 60.0, 60.909090909090907,
        61.818181818181813, 62.727272727272734, 63.63636363636364,
        64.545454545454547, 65.454545454545453, 66.36363636363636,
        67.272727272727266, 68.181818181818173, 69.0909090909091, 70.0, 70.0,
        70.0, 70.0, 70.0, 70.0, 68.0, 66.0, 64.0, 62.0, 60.0, 58.0, 56.0, 54.0,
        52.0, 50.0, 48.0, 46.0, 44.0, 42.0, 40.0, 38.0, 36.0, 34.0, 32.0, 30.0,
        27.0, 24.0, 21.0, 18.0, 15.0, 12.0, 9.0, 6.0, 3.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

      HEV_SeriesParallel_DW.DriveCycle5_PWORK.TimePtr = (void *) pTimeValues0;
      HEV_SeriesParallel_DW.DriveCycle5_PWORK.DataPtr = (void *) pDataValues0;
      HEV_SeriesParallel_DW.DriveCycle5_IWORK.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S5>/Drive Cycle 6' */
    {
      static real_T pTimeValues0[] = { 0.0, 0.1, 1.0, 1.5, 2.5, 3.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 6.0, 6.0, 3.0, 3.0 } ;

      HEV_SeriesParallel_DW.DriveCycle6_PWORK.TimePtr = (void *) pTimeValues0;
      HEV_SeriesParallel_DW.DriveCycle6_PWORK.DataPtr = (void *) pDataValues0;
      HEV_SeriesParallel_DW.DriveCycle6_IWORK.PrevIndex = 0;
    }

    /* Start for RateTransition generated from: '<S15>/Select Logic' */
    HEV_SeriesParallel_B.TmpRTBAtSelectLogicOutport1 =
      HEV_SeriesParallel_P.TmpRTBAtSelectLogicOutport1_Ini;

    /* Start for SimscapeRtp: '<S24>/RTP_1' */
    manager_0 = nesl_lease_rtp_manager(
      "HEV_SeriesParallel/Electrical/Solver Configuration_1", 0);
    manager = manager_0;
    tmp = pointer_is_null(manager_0);
    if (tmp) {
      HEV_SeriesParallel_c0f8494c_1_gateway();
      manager = nesl_lease_rtp_manager(
        "HEV_SeriesParallel/Electrical/Solver Configuration_1", 0);
    }

    HEV_SeriesParallel_DW.RTP_1_RtpManager = (void *)manager;
    HEV_SeriesParallel_DW.RTP_1_SetParametersNeeded = true;

    /* End of Start for SimscapeRtp: '<S24>/RTP_1' */

    /* Start for SimscapeExecutionBlock: '<S71>/STATE_1' */
    tmp_0 = nesl_lease_simulator(
      "HEV_SeriesParallel/Electrical/Solver Configuration_1", 0, 0);
    HEV_SeriesParallel_DW.STATE_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(HEV_SeriesParallel_DW.STATE_1_Simulator);
    if (tmp) {
      HEV_SeriesParallel_c0f8494c_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "HEV_SeriesParallel/Electrical/Solver Configuration_1", 0, 0);
      HEV_SeriesParallel_DW.STATE_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    HEV_SeriesParallel_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    HEV_SeriesParallel_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mFixedStepSize = 1.0E-5;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_ON;
    modelParameters.mRTWModifiedTimeStamp = 6.9627083E+8;
    modelParameters.mZcDisabled = true;
    modelParameters.mUseModelRefSolver = false;
    modelParameters.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    modelParameters.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters.mIsUsingODEN = tmp;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      HEV_SeriesParallel_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      HEV_SeriesParallel_DW.STATE_1_Simulator, &modelParameters,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(HEV_SeriesParallel_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S71>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S71>/OUTPUT_1_0' */
    tmp_0 = nesl_lease_simulator(
      "HEV_SeriesParallel/Electrical/Solver Configuration_1", 1, 0);
    HEV_SeriesParallel_DW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(HEV_SeriesParallel_DW.OUTPUT_1_0_Simulator);
    if (tmp) {
      HEV_SeriesParallel_c0f8494c_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "HEV_SeriesParallel/Electrical/Solver Configuration_1", 1, 0);
      HEV_SeriesParallel_DW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    HEV_SeriesParallel_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    HEV_SeriesParallel_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mFixedStepSize = 1.0E-5;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_ON;
    modelParameters_0.mRTWModifiedTimeStamp = 6.9627083E+8;
    modelParameters_0.mZcDisabled = true;
    modelParameters_0.mUseModelRefSolver = false;
    modelParameters_0.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters_0.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_0.mIsUsingODEN = tmp;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      HEV_SeriesParallel_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      HEV_SeriesParallel_DW.OUTPUT_1_0_Simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
      if (tmp) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(HEV_SeriesParallel_M, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S71>/OUTPUT_1_0' */

    /* Start for RateTransition generated from: '<S1>/Mode Logic' */
    HEV_SeriesParallel_B.TmpRTBAtModeLogicOutport2 =
      HEV_SeriesParallel_P.TmpRTBAtModeLogicOutport2_Initi;

    /* Start for SimscapeExecutionBlock: '<S71>/OUTPUT_1_1' */
    tmp_0 = nesl_lease_simulator(
      "HEV_SeriesParallel/Electrical/Solver Configuration_1", 1, 1);
    HEV_SeriesParallel_DW.OUTPUT_1_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(HEV_SeriesParallel_DW.OUTPUT_1_1_Simulator);
    if (tmp) {
      HEV_SeriesParallel_c0f8494c_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "HEV_SeriesParallel/Electrical/Solver Configuration_1", 1, 1);
      HEV_SeriesParallel_DW.OUTPUT_1_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    HEV_SeriesParallel_DW.OUTPUT_1_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    HEV_SeriesParallel_DW.OUTPUT_1_1_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_1.mSolverTolerance = 0.001;
    modelParameters_1.mSolverAbsTol = 0.001;
    modelParameters_1.mSolverRelTol = 0.001;
    modelParameters_1.mVariableStepSolver = false;
    modelParameters_1.mIsUsingODEN = false;
    modelParameters_1.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_1.mFixedStepSize = 1.0E-5;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_ON;
    modelParameters_1.mRTWModifiedTimeStamp = 6.9627083E+8;
    modelParameters_1.mZcDisabled = true;
    modelParameters_1.mUseModelRefSolver = false;
    modelParameters_1.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    modelParameters_1.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters_1.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_1.mIsUsingODEN = tmp;
    modelParameters_1.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      HEV_SeriesParallel_DW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      HEV_SeriesParallel_DW.OUTPUT_1_1_Simulator, &modelParameters_1,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(HEV_SeriesParallel_M));
      if (tmp) {
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(HEV_SeriesParallel_M, msg_1);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S71>/OUTPUT_1_1' */
  }

  HEV_SeriesParallel_PrevZCX.Limits55_Reset_ZCE = UNINITIALIZED_ZCSIG;
  HEV_SeriesParallel_PrevZCX.Limits01_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    int32_T i;
    int_T tmp_1;
    int_T tmp_2;
    int_T tmp_3;
    int_T tmp_4;
    int_T tmp_5;
    boolean_T tmp;
    boolean_T tmp_0;

    /* InitializeConditions for Integrator: '<S81>/Limits [-5,5]' */
    HEV_SeriesParallel_X.Limits55_CSTATE = HEV_SeriesParallel_P.Limits55_IC;

    /* InitializeConditions for TransferFcn: '<S81>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE = 0.0;

    /* InitializeConditions for StateSpace: '<S76>/State Space' */
    HEV_SeriesParallel_X.StateSpace_CSTATE =
      HEV_SeriesParallel_P.StateSpace_InitialCondition;

    /* InitializeConditions for TransferFcn: '<S16>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_o = 0.0;

    /* InitializeConditions for RateTransition generated from: '<S15>/Select Logic' */
    HEV_SeriesParallel_DW.TmpRTBAtSelectLogicOutport1_Buf =
      HEV_SeriesParallel_P.TmpRTBAtSelectLogicOutport1_Ini;

    /* InitializeConditions for Integrator: '<S17>/Limits [-5,5]' */
    HEV_SeriesParallel_X.Limits55_CSTATE_f = HEV_SeriesParallel_P.Limits55_IC_c;

    /* InitializeConditions for TransferFcn: '<S17>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_g = 0.0;

    /* InitializeConditions for Integrator: '<S13>/Limits [-5,5]' */
    HEV_SeriesParallel_X.Limits55_CSTATE_n = HEV_SeriesParallel_P.Limits55_IC_h;

    /* InitializeConditions for TransferFcn: '<S13>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_l = 0.0;

    /* InitializeConditions for Integrator: '<S10>/Limits [0,1]' */
    HEV_SeriesParallel_X.Limits01_CSTATE = HEV_SeriesParallel_P.Limits01_IC;

    /* InitializeConditions for TransferFcn: '<S10>/20Hz Lowpass Filter' */
    HEV_SeriesParallel_X.u0HzLowpassFilter_CSTATE_f = 0.0;

    /* InitializeConditions for SimscapeInputBlock: '<S71>/INPUT_4_1_1' */
    if (rtmIsMajorTimeStep(HEV_SeriesParallel_M)) {
      HEV_SeriesParallel_DW.INPUT_4_1_1_FirstOutput_2208644 = 0.0;
    }

    /* End of InitializeConditions for SimscapeInputBlock: '<S71>/INPUT_4_1_1' */

    /* InitializeConditions for SimscapeExecutionBlock: '<S71>/STATE_1' */
    tmp = false;
    tmp_0 = false;
    if (tmp_0 || tmp) {
      i = strcmp(rtsiGetSolverName(&HEV_SeriesParallel_M->solverInfo), "daessc");
      tmp_1 = strcmp(rtsiGetSolverName(&HEV_SeriesParallel_M->solverInfo),
                     "ode14x");
      tmp_2 = strcmp(rtsiGetSolverName(&HEV_SeriesParallel_M->solverInfo),
                     "ode15s");
      tmp_3 = strcmp(rtsiGetSolverName(&HEV_SeriesParallel_M->solverInfo),
                     "ode1be");
      tmp_4 = strcmp(rtsiGetSolverName(&HEV_SeriesParallel_M->solverInfo),
                     "ode23t");
      tmp_5 = strcmp(rtsiGetSolverName(&HEV_SeriesParallel_M->solverInfo),
                     "odeN");
      if ((boolean_T)((i != 0) & (tmp_1 != 0) & (tmp_2 != 0) & (tmp_3 != 0) &
                      (tmp_4 != 0) & (tmp_5 != 0))) {
        rtmSetErrorStatus(HEV_SeriesParallel_M,
                          "Detected inconsistent solvers in the model reference hierarchy. Model built with ode14x requires one of {daessc, ode14x, ode15s, ode1be, ode23t, odeN} solvers to run. Use one of the required solvers in the top model.");
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S71>/STATE_1' */

    /* InitializeConditions for Integrator: '<S43>/Initial charge Ah0' */
    HEV_SeriesParallel_X.InitialchargeAh0_CSTATE = HEV_SeriesParallel_P.AH0;

    /* InitializeConditions for Integrator: '<S14>/Integrator' */
    HEV_SeriesParallel_X.Integrator_CSTATE =
      HEV_SeriesParallel_P.SensorDynamics_x_initial;

    /* InitializeConditions for RateTransition generated from: '<S1>/Mode Logic' */
    HEV_SeriesParallel_DW.TmpRTBAtModeLogicOutport2_Buffe =
      HEV_SeriesParallel_P.TmpRTBAtModeLogicOutport2_Initi;

    /* InitializeConditions for Integrator: '<S80>/Cumulative L' */
    HEV_SeriesParallel_X.CumulativeL_CSTATE =
      HEV_SeriesParallel_P.CumulativeL_IC;

    /* InitializeConditions for Integrator: '<S80>/Cumulative Gal' */
    HEV_SeriesParallel_X.CumulativeGal_CSTATE =
      HEV_SeriesParallel_P.CumulativeGal_IC;

    /* InitializeConditions for Integrator: '<S80>/Cumulative Distance Km' */
    HEV_SeriesParallel_X.CumulativeDistanceKm_CSTATE =
      HEV_SeriesParallel_P.CumulativeDistanceKm_IC;

    /* SystemInitialize for Chart: '<S1>/Mode Logic' */
    memset(&HEV_SeriesParallel_DW.speed_buffer[0], 0, 21U * sizeof(real_T));
    HEV_SeriesParallel_DW.is_active_c3_HEV_SeriesParallel = 0U;
    HEV_SeriesParallel_DW.is_c3_HEV_SeriesParallel =
      HEV_SeriesPa_IN_NO_ACTIVE_CHILD;
    HEV_SeriesParallel_DW.is_Motion_mode = HEV_SeriesPa_IN_NO_ACTIVE_CHILD;
    HEV_SeriesParallel_DW.is_Normal_mode = HEV_SeriesPa_IN_NO_ACTIVE_CHILD;
    HEV_SeriesParallel_DW.is_Cruise_mode = HEV_SeriesPa_IN_NO_ACTIVE_CHILD;

    /* Root-level InitSystemMatrices */
    {
      static int_T modelMassMatrixIr[36] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        18, 14, 15, 17, 16, 19, 20, 21, 13, 62, 22, 23, 24, 11, 62, 26, 12, 62,
        25, 27, 69, 70, 71, 72, 73 };

      static int_T modelMassMatrixJc[75] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 26, 27, 29, 30, 31,
        31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
        31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
        31, 31, 31, 31, 31, 32, 33, 34, 35, 36 };

      static real_T modelMassMatrixPr[36] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0 };

      (void) memcpy(HEV_SeriesParallel_MassMatrix.ir, modelMassMatrixIr,
                    36*sizeof(int_T));
      (void) memcpy(HEV_SeriesParallel_MassMatrix.jc, modelMassMatrixJc,
                    75*sizeof(int_T));
      (void) memcpy(HEV_SeriesParallel_MassMatrix.pr, modelMassMatrixPr,
                    36*sizeof(real_T));
    }
  }
}

/* Model terminate function */
void HEV_SeriesParallel_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S71>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    HEV_SeriesParallel_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    HEV_SeriesParallel_DW.STATE_1_SimData);
  nesl_erase_simulator("HEV_SeriesParallel/Electrical/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S71>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    HEV_SeriesParallel_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    HEV_SeriesParallel_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("HEV_SeriesParallel/Electrical/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S71>/OUTPUT_1_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    HEV_SeriesParallel_DW.OUTPUT_1_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    HEV_SeriesParallel_DW.OUTPUT_1_1_SimData);
  nesl_erase_simulator("HEV_SeriesParallel/Electrical/Solver Configuration_1");
}
