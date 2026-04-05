/*
 * Mode0.h
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

#ifndef Mode0_h_
#define Mode0_h_
#ifndef Mode0_COMMON_INCLUDES_
#define Mode0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Mode0_COMMON_INCLUDES_ */

#include "Mode0_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T speed_buffer[21];             /* '<Root>/Mode Logic' */
  uint8_T is_active_c3_Mode0;          /* '<Root>/Mode Logic' */
  uint8_T is_c3_Mode0;                 /* '<Root>/Mode Logic' */
  uint8_T is_Motion_mode;              /* '<Root>/Mode Logic' */
  uint8_T is_Normal_mode;              /* '<Root>/Mode Logic' */
  uint8_T is_Cruise_mode;              /* '<Root>/Mode Logic' */
} DW_Mode0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T speed;                        /* '<Root>/speed' */
  real_T brake;                        /* '<Root>/brake' */
  real_T SOC;                          /* '<Root>/charge' */
  real_T wEng;                         /* '<Root>/engine_speed' */
} ExtU_Mode0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mot_Enable;                   /* '<Root>/Mot_Enable' */
  real_T Gen_Enable;                   /* '<Root>/Gen_Enable' */
  real_T ICE_Enable;                   /* '<Root>/ICE_Enable' */
} ExtY_Mode0_T;

/* Real-time Model Data Structure */
struct tag_RTM_Mode0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block states (default storage) */
extern DW_Mode0_T Mode0_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Mode0_T Mode0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Mode0_T Mode0_Y;

/* Model entry point functions */
extern void Mode0_initialize(void);
extern void Mode0_step(void);
extern void Mode0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Mode0_T *const Mode0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('HEV_SeriesParallel/Control/Mode Logic')    - opens subsystem HEV_SeriesParallel/Control/Mode Logic
 * hilite_system('HEV_SeriesParallel/Control/Mode Logic/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'HEV_SeriesParallel/Control'
 * '<S1>'   : 'HEV_SeriesParallel/Control/Mode Logic'
 */
#endif                                 /* Mode0_h_ */
