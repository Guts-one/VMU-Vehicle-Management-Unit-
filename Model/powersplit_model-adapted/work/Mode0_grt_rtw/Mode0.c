/*
 * Mode0.c
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "Mode0".
 *
 * Model version              : 11.0
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Tue Mar 24 15:01:34 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Mode0.h"
#include "rtwtypes.h"
#include <string.h>
#include "Mode0_private.h"
#include "rt_nonfinite.h"

/* Named constants for Chart: '<Root>/Mode Logic' */
#define Mode0_EngOffRPM                (790.0)
#define Mode0_EngOnRPM                 (800.0)
#define Mode0_IN_Accelerate_mode       ((uint8_T)1U)
#define Mode0_IN_Brake_mode            ((uint8_T)1U)
#define Mode0_IN_Cruise_mode           ((uint8_T)2U)
#define Mode0_IN_Motion_mode           ((uint8_T)2U)
#define Mode0_IN_NO_ACTIVE_CHILD       ((uint8_T)0U)
#define Mode0_IN_Normal_mode           ((uint8_T)1U)
#define Mode0_IN_Start_mode            ((uint8_T)2U)
#define Mode0_IN_charge                ((uint8_T)1U)
#define Mode0_IN_nocharge              ((uint8_T)2U)

/* Block states (default storage) */
DW_Mode0_T Mode0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Mode0_T Mode0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Mode0_T Mode0_Y;

/* Real-time model */
static RT_MODEL_Mode0_T Mode0_M_;
RT_MODEL_Mode0_T *const Mode0_M = &Mode0_M_;

/* Forward declaration for local functions */
static real_T Mode0_oldspeed(void);

/* Function for Chart: '<Root>/Mode Logic' */
static real_T Mode0_oldspeed(void)
{
  real_T tmp[20];
  real_T accumulatedData;
  real_T speed_buffer;
  int32_T k;

  /* MATLAB Function 'oldspeed': '<S1>:6' */
  /* '<S1>:6:2' */
  memcpy(&tmp[0], &Mode0_DW.speed_buffer[0], 20U * sizeof(real_T));

  /* Inport: '<Root>/speed' */
  /* '<S1>:6:3' */
  Mode0_DW.speed_buffer[0] = Mode0_U.speed;

  /* '<S1>:6:4' */
  accumulatedData = Mode0_DW.speed_buffer[0];
  for (k = 0; k < 20; k++) {
    speed_buffer = tmp[k];
    Mode0_DW.speed_buffer[k + 1] = speed_buffer;
    accumulatedData += speed_buffer;
  }

  return accumulatedData / 21.0;
}

/* Model step function */
void Mode0_step(void)
{
  /* Chart: '<Root>/Mode Logic' incorporates:
   *  Inport: '<Root>/brake'
   *  Inport: '<Root>/charge'
   *  Inport: '<Root>/engine_speed'
   */
  /* Gateway: Mode Logic */
  /* During: Mode Logic */
  if (Mode0_DW.is_active_c3_Mode0 == 0) {
    /* Entry: Mode Logic */
    Mode0_DW.is_active_c3_Mode0 = 1U;

    /* Entry Internal: Mode Logic */
    /* Transition: '<S1>:18' */
    Mode0_DW.is_c3_Mode0 = Mode0_IN_Motion_mode;

    /* Entry Internal 'Motion_mode': '<S1>:9' */
    /* Transition: '<S1>:11' */
    Mode0_DW.is_Motion_mode = Mode0_IN_Start_mode;

    /* Outport: '<Root>/Gen_Enable' */
    /* Entry 'Start_mode': '<S1>:4' */
    Mode0_Y.Gen_Enable = 1.0;

    /* Outport: '<Root>/Mot_Enable' */
    Mode0_Y.Mot_Enable = 1.0;

    /* Outport: '<Root>/ICE_Enable' */
    Mode0_Y.ICE_Enable = 0.0;
  } else if (Mode0_DW.is_c3_Mode0 == Mode0_IN_Brake_mode) {
    /* Outport: '<Root>/Mot_Enable' */
    Mode0_Y.Mot_Enable = 1.0;

    /* Outport: '<Root>/Gen_Enable' */
    Mode0_Y.Gen_Enable = 0.0;

    /* Outport: '<Root>/ICE_Enable' */
    Mode0_Y.ICE_Enable = 0.0;

    /* During 'Brake_mode': '<S1>:5' */
    if (Mode0_U.brake < 0.05) {
      /* Transition: '<S1>:17' */
      Mode0_DW.is_c3_Mode0 = Mode0_IN_Motion_mode;

      /* Entry Internal 'Motion_mode': '<S1>:9' */
      /* Transition: '<S1>:11' */
      Mode0_DW.is_Motion_mode = Mode0_IN_Start_mode;

      /* Outport: '<Root>/Gen_Enable' */
      /* Entry 'Start_mode': '<S1>:4' */
      Mode0_Y.Gen_Enable = 1.0;
    }

    /* During 'Motion_mode': '<S1>:9' */
  } else if (Mode0_U.brake >= 0.05) {
    /* Transition: '<S1>:16' */
    /* Exit Internal 'Motion_mode': '<S1>:9' */
    /* Exit Internal 'Normal_mode': '<S1>:1' */
    /* Exit Internal 'Cruise_mode': '<S1>:2' */
    Mode0_DW.is_Cruise_mode = Mode0_IN_NO_ACTIVE_CHILD;
    Mode0_DW.is_Normal_mode = Mode0_IN_NO_ACTIVE_CHILD;
    Mode0_DW.is_Motion_mode = Mode0_IN_NO_ACTIVE_CHILD;
    Mode0_DW.is_c3_Mode0 = Mode0_IN_Brake_mode;

    /* Outport: '<Root>/Mot_Enable' */
    /* Entry 'Brake_mode': '<S1>:5' */
    Mode0_Y.Mot_Enable = 1.0;

    /* Outport: '<Root>/Gen_Enable' */
    Mode0_Y.Gen_Enable = 0.0;

    /* Outport: '<Root>/ICE_Enable' */
    Mode0_Y.ICE_Enable = 0.0;
  } else if (Mode0_DW.is_Motion_mode == Mode0_IN_Normal_mode) {
    /* Outport: '<Root>/ICE_Enable' */
    Mode0_Y.ICE_Enable = 1.0;

    /* During 'Normal_mode': '<S1>:1' */
    if (Mode0_U.wEng <= Mode0_EngOffRPM) {
      /* Transition: '<S1>:12' */
      /* Exit Internal 'Normal_mode': '<S1>:1' */
      /* Exit Internal 'Cruise_mode': '<S1>:2' */
      Mode0_DW.is_Cruise_mode = Mode0_IN_NO_ACTIVE_CHILD;
      Mode0_DW.is_Normal_mode = Mode0_IN_NO_ACTIVE_CHILD;
      Mode0_DW.is_Motion_mode = Mode0_IN_Start_mode;

      /* Outport: '<Root>/Gen_Enable' */
      /* Entry 'Start_mode': '<S1>:4' */
      Mode0_Y.Gen_Enable = 1.0;

      /* Outport: '<Root>/Mot_Enable' */
      Mode0_Y.Mot_Enable = 1.0;

      /* Outport: '<Root>/ICE_Enable' */
      Mode0_Y.ICE_Enable = 0.0;
    } else if (Mode0_DW.is_Normal_mode == Mode0_IN_Accelerate_mode) {
      /* Outport: '<Root>/Gen_Enable' */
      Mode0_Y.Gen_Enable = 0.0;

      /* Outport: '<Root>/Mot_Enable' */
      Mode0_Y.Mot_Enable = 1.0;

      /* During 'Accelerate_mode': '<S1>:3' */
      if (((Mode0_U.speed > 0.998 * Mode0_oldspeed()) && (Mode0_U.speed < 1.002 *
            Mode0_oldspeed())) || (Mode0_U.SOC <= 30.0)) {
        /* Transition: '<S1>:10' */
        Mode0_DW.is_Normal_mode = Mode0_IN_Cruise_mode;

        /* Entry 'Cruise_mode': '<S1>:2' */
        /* Entry Internal 'Cruise_mode': '<S1>:2' */
        /* Transition: '<S1>:13' */
        Mode0_DW.is_Cruise_mode = Mode0_IN_charge;

        /* Outport: '<Root>/Gen_Enable' */
        /* Entry 'charge': '<S1>:8' */
        Mode0_Y.Gen_Enable = 1.0;
      }
    } else {
      /* Outport: '<Root>/Mot_Enable' */
      Mode0_Y.Mot_Enable = 1.0;

      /* During 'Cruise_mode': '<S1>:2' */
      if (((Mode0_U.speed < 0.998 * Mode0_oldspeed()) || (Mode0_U.speed > 1.002 *
            Mode0_oldspeed())) && (Mode0_U.SOC > 30.0)) {
        /* Transition: '<S1>:15' */
        /* Exit Internal 'Cruise_mode': '<S1>:2' */
        Mode0_DW.is_Cruise_mode = Mode0_IN_NO_ACTIVE_CHILD;
        Mode0_DW.is_Normal_mode = Mode0_IN_Accelerate_mode;

        /* Outport: '<Root>/Gen_Enable' */
        /* Entry 'Accelerate_mode': '<S1>:3' */
        Mode0_Y.Gen_Enable = 0.0;
      } else if (Mode0_DW.is_Cruise_mode == Mode0_IN_charge) {
        /* Outport: '<Root>/Gen_Enable' */
        Mode0_Y.Gen_Enable = 1.0;

        /* During 'charge': '<S1>:8' */
        if (Mode0_U.SOC > 99.9) {
          /* Transition: '<S1>:19' */
          Mode0_DW.is_Cruise_mode = Mode0_IN_nocharge;

          /* Outport: '<Root>/Gen_Enable' */
          /* Entry 'nocharge': '<S1>:7' */
          Mode0_Y.Gen_Enable = 0.0;
        }
      } else {
        /* Outport: '<Root>/Gen_Enable' */
        Mode0_Y.Gen_Enable = 0.0;

        /* During 'nocharge': '<S1>:7' */
        if (Mode0_U.SOC < 30.0) {
          /* Transition: '<S1>:20' */
          Mode0_DW.is_Cruise_mode = Mode0_IN_charge;

          /* Outport: '<Root>/Gen_Enable' */
          /* Entry 'charge': '<S1>:8' */
          Mode0_Y.Gen_Enable = 1.0;
        }
      }
    }
  } else {
    /* Outport: '<Root>/Gen_Enable' */
    Mode0_Y.Gen_Enable = 1.0;

    /* Outport: '<Root>/Mot_Enable' */
    Mode0_Y.Mot_Enable = 1.0;

    /* Outport: '<Root>/ICE_Enable' */
    Mode0_Y.ICE_Enable = 0.0;

    /* During 'Start_mode': '<S1>:4' */
    if (Mode0_U.wEng > Mode0_EngOnRPM) {
      /* Transition: '<S1>:21' */
      Mode0_DW.is_Motion_mode = Mode0_IN_Normal_mode;

      /* Outport: '<Root>/ICE_Enable' */
      /* Entry 'Normal_mode': '<S1>:1' */
      Mode0_Y.ICE_Enable = 1.0;

      /* Entry Internal 'Normal_mode': '<S1>:1' */
      /* Transition: '<S1>:14' */
      Mode0_DW.is_Normal_mode = Mode0_IN_Accelerate_mode;

      /* Outport: '<Root>/Gen_Enable' */
      /* Entry 'Accelerate_mode': '<S1>:3' */
      Mode0_Y.Gen_Enable = 0.0;
    }
  }

  /* End of Chart: '<Root>/Mode Logic' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(Mode0_M->rtwLogInfo, (&Mode0_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(Mode0_M)!=-1) &&
        !((rtmGetTFinal(Mode0_M)-Mode0_M->Timing.taskTime0) >
          Mode0_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Mode0_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Mode0_M->Timing.clockTick0)) {
    ++Mode0_M->Timing.clockTickH0;
  }

  Mode0_M->Timing.taskTime0 = Mode0_M->Timing.clockTick0 *
    Mode0_M->Timing.stepSize0 + Mode0_M->Timing.clockTickH0 *
    Mode0_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Mode0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Mode0_M, 0,
                sizeof(RT_MODEL_Mode0_T));
  rtmSetTFinal(Mode0_M, 195.0);
  Mode0_M->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Mode0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Mode0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Mode0_M->rtwLogInfo, (NULL));
    rtliSetLogT(Mode0_M->rtwLogInfo, "tout");
    rtliSetLogX(Mode0_M->rtwLogInfo, "");
    rtliSetLogXFinal(Mode0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Mode0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Mode0_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Mode0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Mode0_M->rtwLogInfo, 1);
    rtliSetLogY(Mode0_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Mode0_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Mode0_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Mode0_DW, 0,
                sizeof(DW_Mode0_T));

  /* external inputs */
  (void)memset(&Mode0_U, 0, sizeof(ExtU_Mode0_T));

  /* external outputs */
  (void)memset(&Mode0_Y, 0, sizeof(ExtY_Mode0_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Mode0_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Mode0_M), Mode0_M->Timing.stepSize0, (&rtmGetErrorStatus(Mode0_M)));

  /* SystemInitialize for Outport: '<Root>/Mot_Enable' incorporates:
   *  Chart: '<Root>/Mode Logic'
   */
  Mode0_Y.Mot_Enable = 0.0;

  /* SystemInitialize for Outport: '<Root>/Gen_Enable' incorporates:
   *  Chart: '<Root>/Mode Logic'
   */
  Mode0_Y.Gen_Enable = 0.0;

  /* SystemInitialize for Chart: '<Root>/Mode Logic' */
  memset(&Mode0_DW.speed_buffer[0], 0, 21U * sizeof(real_T));

  /* SystemInitialize for Outport: '<Root>/ICE_Enable' incorporates:
   *  Chart: '<Root>/Mode Logic'
   */
  Mode0_Y.ICE_Enable = 0.0;

  /* SystemInitialize for Chart: '<Root>/Mode Logic' */
  Mode0_DW.is_active_c3_Mode0 = 0U;
  Mode0_DW.is_c3_Mode0 = Mode0_IN_NO_ACTIVE_CHILD;
  Mode0_DW.is_Motion_mode = Mode0_IN_NO_ACTIVE_CHILD;
  Mode0_DW.is_Normal_mode = Mode0_IN_NO_ACTIVE_CHILD;
  Mode0_DW.is_Cruise_mode = Mode0_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void Mode0_terminate(void)
{
  /* (no terminate code required) */
}
