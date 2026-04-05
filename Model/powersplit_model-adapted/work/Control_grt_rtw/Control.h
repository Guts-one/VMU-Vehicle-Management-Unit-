/*
 * Control.h
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

#ifndef Control_h_
#define Control_h_
#ifndef Control_COMMON_INCLUDES_
#define Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Control_COMMON_INCLUDES_ */

#include "Control_types.h"
#include "rt_zcfcn.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TmpRTBAtSelectLogicOutport1;  /* '<S8>/Select Logic' */
  real_T Ki;                           /* '<S3>/Ki' */
  real_T GenRPMtoV;                    /* '<S10>/Gen RPM to V' */
  real_T Ki_p;                         /* '<S10>/Ki' */
  real_T Ki_m;                         /* '<S6>/Ki' */
  real_T MotRPMtoV;                    /* '<S6>/Mot RPM to V' */
  real_T Gain;                         /* '<S7>/Gain' */
  real_T Sum;                          /* '<S7>/Sum' */
  real_T TmpRTBAtModeLogicOutport2;    /* '<S1>/Mode Logic' */
  real_T TmpRTBAtModeLogicInport1;     /* '<S1>/Sensor Dynamics' */
} B_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TmpRTBAtSelectLogicOutport1_Buf;/* synthesized block */
  real_T SOC_Buffer;                   /* synthesized block */
  real_T TmpRTBAtModeLogicInport1_Buffer;/* synthesized block */
  real_T TmpRTBAtModeLogicOutport2_Buffe;/* synthesized block */
  real_T wEng_Buffer;                  /* synthesized block */
  real_T speed_buffer[21];             /* '<S1>/Mode Logic' */
  uint8_T is_active_c3_Control;        /* '<S1>/Mode Logic' */
  uint8_T is_c3_Control;               /* '<S1>/Mode Logic' */
  uint8_T is_Motion_mode;              /* '<S1>/Mode Logic' */
  uint8_T is_Normal_mode;              /* '<S1>/Mode Logic' */
  uint8_T is_Cruise_mode;              /* '<S1>/Mode Logic' */
} DW_Control_T;

/* Continuous states (default storage) */
typedef struct {
  real_T u0HzLowpassFilter_CSTATE;     /* '<S9>/20Hz Lowpass Filter' */
  real_T Limits55_CSTATE;              /* '<S10>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE_g;   /* '<S10>/20Hz Lowpass Filter' */
  real_T Limits55_CSTATE_n;            /* '<S6>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE_l;   /* '<S6>/20Hz Lowpass Filter' */
  real_T Limits01_CSTATE;              /* '<S3>/Limits [0,1]' */
  real_T u0HzLowpassFilter_CSTATE_f;   /* '<S3>/20Hz Lowpass Filter' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
} X_Control_T;

/* State derivatives (default storage) */
typedef struct {
  real_T u0HzLowpassFilter_CSTATE;     /* '<S9>/20Hz Lowpass Filter' */
  real_T Limits55_CSTATE;              /* '<S10>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE_g;   /* '<S10>/20Hz Lowpass Filter' */
  real_T Limits55_CSTATE_n;            /* '<S6>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE_l;   /* '<S6>/20Hz Lowpass Filter' */
  real_T Limits01_CSTATE;              /* '<S3>/Limits [0,1]' */
  real_T u0HzLowpassFilter_CSTATE_f;   /* '<S3>/20Hz Lowpass Filter' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
} XDot_Control_T;

/* State disabled  */
typedef struct {
  boolean_T u0HzLowpassFilter_CSTATE;  /* '<S9>/20Hz Lowpass Filter' */
  boolean_T Limits55_CSTATE;           /* '<S10>/Limits [-5,5]' */
  boolean_T u0HzLowpassFilter_CSTATE_g;/* '<S10>/20Hz Lowpass Filter' */
  boolean_T Limits55_CSTATE_n;         /* '<S6>/Limits [-5,5]' */
  boolean_T u0HzLowpassFilter_CSTATE_l;/* '<S6>/20Hz Lowpass Filter' */
  boolean_T Limits01_CSTATE;           /* '<S3>/Limits [0,1]' */
  boolean_T u0HzLowpassFilter_CSTATE_f;/* '<S3>/20Hz Lowpass Filter' */
  boolean_T Integrator_CSTATE;         /* '<S7>/Integrator' */
} XDis_Control_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Limits55_Reset_ZCE;       /* '<S10>/Limits [-5,5]' */
  ZCSigState Limits01_Reset_ZCE;       /* '<S3>/Limits [0,1]' */
} PrevZCX_Control_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T w;                            /* '<Root>/w' */
  real_T A;                            /* '<Root>/A' */
  real_T Tq;                           /* '<Root>/Tq' */
  real_T iabc;                         /* '<Root>/iabc' */
  real_T vdc;                          /* '<Root>/vdc' */
  real_T w_n;                          /* '<Root>/wb' */
  real_T A_a;                          /* '<Root>/Ab' */
  real_T Tq_i;                         /* '<Root>/Tqb' */
  real_T iabc_e;                       /* '<Root>/iabcb' */
  real_T vdc_h;                        /* '<Root>/vdcb' */
  real_T SOC;                          /* '<Root>/SOC' */
  real_T TqRef;                        /* '<Root>/TqRef' */
  real_T Spd;                          /* '<Root>/Spd' */
  real_T idqRef[2];                    /* '<Root>/idqRef' */
  real_T TqRef_k;                      /* '<Root>/TqRefb' */
  real_T TqLim;                        /* '<Root>/TqLim' */
  real_T TqEstim;                      /* '<Root>/TqEstim' */
  real_T Spd_b;                        /* '<Root>/Spdb' */
  real_T iabc_b;                       /* '<Root>/iabca' */
  real_T idq[2];                       /* '<Root>/idq' */
  real_T vSpd;                         /* '<Root>/vSpd' */
  real_T Acc;                          /* '<Root>/Acc' */
  real_T wEng;                         /* '<Root>/wEng' */
  real_T trq;                          /* '<Root>/trq' */
  real_T P;                            /* '<Root>/P' */
} ExtU_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T TrqReqGen;                    /* '<Root>/TrqReqGen' */
  real_T trqReqM;                      /* '<Root>/trqReqM' */
  real_T Accb;                         /* '<Root>/Accb' */
  real_T SOCb;                         /* '<Root>/SOCb' */
  real_T wICEreq;                      /* '<Root>/wICEreq' */
  real_T Thr;                          /* '<Root>/Thr' */
} ExtY_Control_T;

/* Parameters (default storage) */
struct P_Control_T_ {
  struct_viMUS9ki6lFwfEmklEsm9G HEV_Param;/* Variable: HEV_Param
                                           * Referenced by:
                                           *   '<S3>/Ki'
                                           *   '<S3>/Kp'
                                           *   '<S6>/Ki'
                                           *   '<S6>/Kp'
                                           *   '<S7>/Gain'
                                           *   '<S10>/Ki'
                                           *   '<S10>/Kp'
                                           */
  real_T SensorDynamics_x_initial;   /* Mask Parameter: SensorDynamics_x_initial
                                      * Referenced by: '<S7>/Integrator'
                                      */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T u0HzLowpassFilter_A;         /* Computed Parameter: u0HzLowpassFilter_A
                                       * Referenced by: '<S9>/20Hz Lowpass Filter'
                                       */
  real_T u0HzLowpassFilter_C;         /* Computed Parameter: u0HzLowpassFilter_C
                                       * Referenced by: '<S9>/20Hz Lowpass Filter'
                                       */
  real_T TmpRTBAtSelectLogicOutport1_Ini;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Limits55_IC;                  /* Expression: 0
                                        * Referenced by: '<S10>/Limits [-5,5]'
                                        */
  real_T Limits55_UpperSat;            /* Expression: 5
                                        * Referenced by: '<S10>/Limits [-5,5]'
                                        */
  real_T Limits55_LowerSat;            /* Expression: -5
                                        * Referenced by: '<S10>/Limits [-5,5]'
                                        */
  real_T u0HzLowpassFilter_A_o;     /* Computed Parameter: u0HzLowpassFilter_A_o
                                     * Referenced by: '<S10>/20Hz Lowpass Filter'
                                     */
  real_T u0HzLowpassFilter_C_m;     /* Computed Parameter: u0HzLowpassFilter_C_m
                                     * Referenced by: '<S10>/20Hz Lowpass Filter'
                                     */
  real_T AcctowMot_tableData[3];       /* Expression: [0 6000 6000]
                                        * Referenced by: '<S1>/Acc to wMot'
                                        */
  real_T AcctowMot_bp01Data[3];        /* Expression: [0 1 1.2]
                                        * Referenced by: '<S1>/Acc to wMot'
                                        */
  real_T AcctowEng_tableData[4];       /* Expression: [800 5000 6000 6000]
                                        * Referenced by: '<S1>/Acc to wEng'
                                        */
  real_T AcctowEng_bp01Data[4];        /* Expression: [0 0.9 0.95 1]
                                        * Referenced by: '<S1>/Acc to wEng'
                                        */
  real_T rpm2volts_Gain;               /* Expression: 5/10000
                                        * Referenced by: '<S10>/rpm2volts'
                                        */
  real_T u5_UpperSat;                  /* Expression: 5
                                        * Referenced by: '<S10>/[-5,5]'
                                        */
  real_T u5_LowerSat;                  /* Expression: -5
                                        * Referenced by: '<S10>/[-5,5]'
                                        */
  real_T VoltsNm_Gain;                 /* Expression: 400/5
                                        * Referenced by: '<S10>/Volts//Nm'
                                        */
  real_T Limits55_IC_h;                /* Expression: 0
                                        * Referenced by: '<S6>/Limits [-5,5]'
                                        */
  real_T Limits55_UpperSat_g;          /* Expression: 5
                                        * Referenced by: '<S6>/Limits [-5,5]'
                                        */
  real_T Limits55_LowerSat_c;          /* Expression: -5
                                        * Referenced by: '<S6>/Limits [-5,5]'
                                        */
  real_T u0HzLowpassFilter_A_b;     /* Computed Parameter: u0HzLowpassFilter_A_b
                                     * Referenced by: '<S6>/20Hz Lowpass Filter'
                                     */
  real_T u0HzLowpassFilter_C_f;     /* Computed Parameter: u0HzLowpassFilter_C_f
                                     * Referenced by: '<S6>/20Hz Lowpass Filter'
                                     */
  real_T rpm2volts_Gain_p;             /* Expression: 5/6500
                                        * Referenced by: '<S6>/rpm2volts'
                                        */
  real_T u5_UpperSat_m;                /* Expression: 5
                                        * Referenced by: '<S6>/[-5,5]'
                                        */
  real_T u5_LowerSat_a;                /* Expression: -5
                                        * Referenced by: '<S6>/[-5,5]'
                                        */
  real_T VoltsNm_Gain_c;               /* Expression: 400/5
                                        * Referenced by: '<S6>/Volts//Nm'
                                        */
  real_T Limits01_IC;                  /* Expression: 0
                                        * Referenced by: '<S3>/Limits [0,1]'
                                        */
  real_T Limits01_UpperSat;            /* Expression: 1
                                        * Referenced by: '<S3>/Limits [0,1]'
                                        */
  real_T Limits01_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S3>/Limits [0,1]'
                                        */
  real_T u0HzLowpassFilter_A_a;     /* Computed Parameter: u0HzLowpassFilter_A_a
                                     * Referenced by: '<S3>/20Hz Lowpass Filter'
                                     */
  real_T u0HzLowpassFilter_C_o;     /* Computed Parameter: u0HzLowpassFilter_C_o
                                     * Referenced by: '<S3>/20Hz Lowpass Filter'
                                     */
  real_T EngineIdle_Value;             /* Expression: 800
                                        * Referenced by: '<S3>/Engine Idle'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T u1_UpperSat;                  /* Expression: 1
                                        * Referenced by: '<S3>/[0,1]'
                                        */
  real_T u1_LowerSat;                  /* Expression: 0
                                        * Referenced by: '<S3>/[0,1]'
                                        */
  real_T Gain_Gain;                    /* Expression: 60/(2*pi)
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 60/(2*pi)
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T GenRPMtoV_Gain;               /* Expression: 5/10000
                                        * Referenced by: '<S10>/Gen RPM to V'
                                        */
  real_T MotRPMtoV_Gain;               /* Expression: 5/6700
                                        * Referenced by: '<S6>/Mot RPM to V'
                                        */
  real_T TmpRTBAtModeLogicOutport2_Initi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T SelectLogic_CurrentSetting;
                               /* Computed Parameter: SelectLogic_CurrentSetting
                                * Referenced by: '<S9>/Select Logic'
                                */
  uint8_T SelectLogic_CurrentSetting_i;
                             /* Computed Parameter: SelectLogic_CurrentSetting_i
                              * Referenced by: '<S12>/Select Logic'
                              */
  uint8_T SelectLogic_CurrentSetting_n;
                             /* Computed Parameter: SelectLogic_CurrentSetting_n
                              * Referenced by: '<S8>/Select Logic'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_Control_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_Control_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Control_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[8];
  real_T odeF[3][8];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint16_T TID[3];
      uint16_T cLimit[3];
    } TaskCounters;

    struct {
      uint16_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Control_T Control_P;

/* Block signals (default storage) */
extern B_Control_T Control_B;

/* Continuous states (default storage) */
extern X_Control_T Control_X;

/* Disabled states (default storage) */
extern XDis_Control_T Control_XDis;

/* Block states (default storage) */
extern DW_Control_T Control_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Control_T Control_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_Control_T Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Control_T Control_Y;

/* Model entry point functions */
extern void Control_initialize(void);
extern void Control_step0(void);
extern void Control_step2(void);       /* Sample time: [0.1s, 0.0s] */
extern void Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Control_T *const Control_M;

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
 * hilite_system('HEV_SeriesParallel/Control')    - opens subsystem HEV_SeriesParallel/Control
 * hilite_system('HEV_SeriesParallel/Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'HEV_SeriesParallel'
 * '<S1>'   : 'HEV_SeriesParallel/Control'
 * '<S2>'   : 'HEV_SeriesParallel/Control/Battery Charge Controller'
 * '<S3>'   : 'HEV_SeriesParallel/Control/Engine Speed Controller'
 * '<S4>'   : 'HEV_SeriesParallel/Control/Generator Controller'
 * '<S5>'   : 'HEV_SeriesParallel/Control/Mode Logic'
 * '<S6>'   : 'HEV_SeriesParallel/Control/Motor Controller'
 * '<S7>'   : 'HEV_SeriesParallel/Control/Sensor Dynamics'
 * '<S8>'   : 'HEV_SeriesParallel/Control/Engine Speed Controller/Engine Running'
 * '<S9>'   : 'HEV_SeriesParallel/Control/Generator Controller/Enable Torque Demand'
 * '<S10>'  : 'HEV_SeriesParallel/Control/Generator Controller/Speed controller'
 * '<S11>'  : 'HEV_SeriesParallel/Control/Generator Controller/Subsystem1'
 * '<S12>'  : 'HEV_SeriesParallel/Control/Motor Controller/Enable Torque Demand'
 */
#endif                                 /* Control_h_ */
