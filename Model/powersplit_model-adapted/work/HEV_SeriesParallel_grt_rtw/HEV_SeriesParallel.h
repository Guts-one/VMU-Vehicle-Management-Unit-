/*
 * HEV_SeriesParallel.h
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

#ifndef HEV_SeriesParallel_h_
#define HEV_SeriesParallel_h_
#ifndef HEV_SeriesParallel_COMMON_INCLUDES_
#define HEV_SeriesParallel_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "nesl_rtw_rtp.h"
#include "HEV_SeriesParallel_c0f8494c_1_gateway.h"
#include "nesl_rtw.h"
#endif                                 /* HEV_SeriesParallel_COMMON_INCLUDES_ */

#include "HEV_SeriesParallel_types.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rt_zcfcn.h"
#include <float.h>
#include "math.h"
#include "rt_matrixlib.h"
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

#ifndef rtmGetMassMatrixIr
#define rtmGetMassMatrixIr(rtm)        ((rtm)->massMatrixIr)
#endif

#ifndef rtmSetMassMatrixIr
#define rtmSetMassMatrixIr(rtm, val)   ((rtm)->massMatrixIr = (val))
#endif

#ifndef rtmGetMassMatrixJc
#define rtmGetMassMatrixJc(rtm)        ((rtm)->massMatrixJc)
#endif

#ifndef rtmSetMassMatrixJc
#define rtmSetMassMatrixJc(rtm, val)   ((rtm)->massMatrixJc = (val))
#endif

#ifndef rtmGetMassMatrixNzMax
#define rtmGetMassMatrixNzMax(rtm)     ((rtm)->massMatrixNzMax)
#endif

#ifndef rtmSetMassMatrixNzMax
#define rtmSetMassMatrixNzMax(rtm, val) ((rtm)->massMatrixNzMax = (val))
#endif

#ifndef rtmGetMassMatrixPr
#define rtmGetMassMatrixPr(rtm)        ((rtm)->massMatrixPr)
#endif

#ifndef rtmSetMassMatrixPr
#define rtmSetMassMatrixPr(rtm, val)   ((rtm)->massMatrixPr = (val))
#endif

#ifndef rtmGetMassMatrixType
#define rtmGetMassMatrixType(rtm)      ((rtm)->massMatrixType)
#endif

#ifndef rtmSetMassMatrixType
#define rtmSetMassMatrixType(rtm, val) ((rtm)->massMatrixType = (val))
#endif

#ifndef rtmGetOdeDELTA
#define rtmGetOdeDELTA(rtm)            ((rtm)->odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
#define rtmSetOdeDELTA(rtm, val)       ((rtm)->odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
#define rtmGetOdeDFDX(rtm)             ((rtm)->odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
#define rtmSetOdeDFDX(rtm, val)        ((rtm)->odeDFDX = (val))
#endif

#ifndef rtmGetOdeE
#define rtmGetOdeE(rtm)                ((rtm)->odeE)
#endif

#ifndef rtmSetOdeE
#define rtmSetOdeE(rtm, val)           ((rtm)->odeE = (val))
#endif

#ifndef rtmGetOdeEDOT
#define rtmGetOdeEDOT(rtm)             ((rtm)->odeEDOT)
#endif

#ifndef rtmSetOdeEDOT
#define rtmSetOdeEDOT(rtm, val)        ((rtm)->odeEDOT = (val))
#endif

#ifndef rtmGetOdeF0
#define rtmGetOdeF0(rtm)               ((rtm)->odeF0)
#endif

#ifndef rtmSetOdeF0
#define rtmSetOdeF0(rtm, val)          ((rtm)->odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
#define rtmGetOdeF1(rtm)               ((rtm)->odeF1)
#endif

#ifndef rtmSetOdeF1
#define rtmSetOdeF1(rtm, val)          ((rtm)->odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
#define rtmGetOdeFAC(rtm)              ((rtm)->odeFAC)
#endif

#ifndef rtmSetOdeFAC
#define rtmSetOdeFAC(rtm, val)         ((rtm)->odeFAC = (val))
#endif

#ifndef rtmGetOdeFMXDOT
#define rtmGetOdeFMXDOT(rtm)           ((rtm)->odeFMXDOT)
#endif

#ifndef rtmSetOdeFMXDOT
#define rtmSetOdeFMXDOT(rtm, val)      ((rtm)->odeFMXDOT = (val))
#endif

#ifndef rtmGetOdeMASSMATRIX_M
#define rtmGetOdeMASSMATRIX_M(rtm)     ((rtm)->odeMASSMATRIX_M)
#endif

#ifndef rtmSetOdeMASSMATRIX_M
#define rtmSetOdeMASSMATRIX_M(rtm, val) ((rtm)->odeMASSMATRIX_M = (val))
#endif

#ifndef rtmGetOdeMASSMATRIX_M1
#define rtmGetOdeMASSMATRIX_M1(rtm)    ((rtm)->odeMASSMATRIX_M1)
#endif

#ifndef rtmSetOdeMASSMATRIX_M1
#define rtmSetOdeMASSMATRIX_M1(rtm, val) ((rtm)->odeMASSMATRIX_M1 = (val))
#endif

#ifndef rtmGetOdePIVOTS
#define rtmGetOdePIVOTS(rtm)           ((rtm)->odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
#define rtmSetOdePIVOTS(rtm, val)      ((rtm)->odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
#define rtmGetOdeW(rtm)                ((rtm)->odeW)
#endif

#ifndef rtmSetOdeW
#define rtmSetOdeW(rtm, val)           ((rtm)->odeW = (val))
#endif

#ifndef rtmGetOdeX0
#define rtmGetOdeX0(rtm)               ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
#define rtmSetOdeX0(rtm, val)          ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetOdeX1START
#define rtmGetOdeX1START(rtm)          ((rtm)->odeX1START)
#endif

#ifndef rtmSetOdeX1START
#define rtmSetOdeX1START(rtm, val)     ((rtm)->odeX1START = (val))
#endif

#ifndef rtmGetOdeXDOT
#define rtmGetOdeXDOT(rtm)             ((rtm)->odeXDOT)
#endif

#ifndef rtmSetOdeXDOT
#define rtmSetOdeXDOT(rtm, val)        ((rtm)->odeXDOT = (val))
#endif

#ifndef rtmGetOdeXTMP
#define rtmGetOdeXTMP(rtm)             ((rtm)->odeXTMP)
#endif

#ifndef rtmSetOdeXTMP
#define rtmSetOdeXTMP(rtm, val)        ((rtm)->odeXTMP = (val))
#endif

#ifndef rtmGetOdeZTMP
#define rtmGetOdeZTMP(rtm)             ((rtm)->odeZTMP)
#endif

#ifndef rtmSetOdeZTMP
#define rtmSetOdeZTMP(rtm, val)        ((rtm)->odeZTMP = (val))
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
  real_T Limits55;                     /* '<S81>/Limits [-5,5]' */
  real_T u0HzLowpassFilter;            /* '<S81>/20Hz Lowpass Filter' */
  real_T RefSpd;                       /* '<S5>/Multiport Switch' */
  real_T Sum;                          /* '<S81>/Sum' */
  real_T Kp;                           /* '<S81>/Kp' */
  real_T Sum1;                         /* '<S81>/Sum1' */
  real_T LimitAcc;                     /* '<S81>/Limit Acc' */
  real_T SpdReqIce;                    /* '<S1>/Acc to wEng' */
  real_T StateSpace;                   /* '<S76>/State Space' */
  real_T u0HzLowpassFilter_j;          /* '<S16>/20Hz Lowpass Filter' */
  real_T TmpRTBAtSelectLogicOutport1;  /* '<S15>/Select Logic' */
  real_T Limits55_h;                   /* '<S17>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_d;          /* '<S17>/20Hz Lowpass Filter' */
  real_T rpm2volts;                    /* '<S17>/rpm2volts' */
  real_T Sum_g;                        /* '<S17>/Sum' */
  real_T Kp_n;                         /* '<S17>/Kp' */
  real_T Sum1_b;                       /* '<S17>/Sum1' */
  real_T u5;                           /* '<S17>/[-5,5]' */
  real_T VoltsNm;                      /* '<S17>/Volts//Nm' */
  real_T SelectLogic;                  /* '<S16>/Select Logic' */
  real_T INPUT_1_1_1[4];               /* '<S71>/INPUT_1_1_1' */
  real_T Limits55_p;                   /* '<S13>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_k;          /* '<S13>/20Hz Lowpass Filter' */
  real_T rpm2volts_b;                  /* '<S13>/rpm2volts' */
  real_T Sum_e;                        /* '<S13>/Sum' */
  real_T Kp_d;                         /* '<S13>/Kp' */
  real_T Sum1_m;                       /* '<S13>/Sum1' */
  real_T u5_f;                         /* '<S13>/[-5,5]' */
  real_T VoltsNm_a;                    /* '<S13>/Volts//Nm' */
  real_T SelectLogic_c;                /* '<S19>/Select Logic' */
  real_T INPUT_2_1_1[4];               /* '<S71>/INPUT_2_1_1' */
  real_T Limits01;                     /* '<S10>/Limits [0,1]' */
  real_T u0HzLowpassFilter_b;          /* '<S10>/20Hz Lowpass Filter' */
  real_T Switch;                       /* '<S10>/Switch' */
  real_T Sum_i;                        /* '<S10>/Sum' */
  real_T Kp_e;                         /* '<S10>/Kp' */
  real_T Sum1_d;                       /* '<S10>/Sum1' */
  real_T u1;                           /* '<S10>/[0,1]' */
  real_T INPUT_3_1_1[4];               /* '<S71>/INPUT_3_1_1' */
  real_T LimitBrk;                     /* '<S81>/Limit Brk' */
  real_T Gain;                         /* '<S81>/Gain' */
  real_T INPUT_4_1_1[4];               /* '<S71>/INPUT_4_1_1' */
  real_T RTP_1;                        /* '<S24>/RTP_1' */
  real_T STATE_1[71];                  /* '<S71>/STATE_1' */
  real_T OUTPUT_1_0[26];               /* '<S71>/OUTPUT_1_0' */
  real_T InitialchargeAh0;             /* '<S43>/Initial charge Ah0' */
  real_T Gain_g;                       /* '<S42>/Gain' */
  real_T Gain4;                        /* '<S99>/Gain4' */
  real_T RateTransition9;              /* '<S7>/Rate Transition9' */
  real_T Gain4_o;                      /* '<S98>/Gain4' */
  real_T Ki;                           /* '<S10>/Ki' */
  real_T Gain_n;                       /* '<S1>/Gain' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T GenRPMtoV;                    /* '<S17>/Gen RPM to V' */
  real_T Ki_p;                         /* '<S17>/Ki' */
  real_T Ki_m;                         /* '<S13>/Ki' */
  real_T MotRPMtoV;                    /* '<S13>/Mot RPM to V' */
  real_T Integrator;                   /* '<S14>/Integrator' */
  real_T Gain_a;                       /* '<S14>/Gain' */
  real_T Sum_c;                        /* '<S14>/Sum' */
  real_T TmpRTBAtModeLogicOutport2;    /* '<S1>/Mode Logic' */
  real_T wEng;                         /* '<S72>/Product' */
  real_T Ki_b;                         /* '<S81>/Ki' */
  real_T CumulativeL;                  /* '<S80>/Cumulative L' */
  real_T gstoKgs;                      /* '<S80>/g//s to Kg//s' */
  real_T Divide;                       /* '<S80>/Divide' */
  real_T m3toL;                        /* '<S80>/m^3 to L' */
  real_T m3togal;                      /* '<S80>/m^3 to gal' */
  real_T KphtoKps;                     /* '<S80>/Kph to Kps' */
  real_T TmpRTBAtModeLogicInport1;     /* '<S1>/Sensor Dynamics' */
  real_T Product;                      /* '<S19>/Product' */
  real_T Product_n;                    /* '<S16>/Product' */
} B_HEV_SeriesParallel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_1_1_1_Discrete_1262858739[2];/* '<S71>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete_216386339[2];/* '<S71>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete_830857875[2];/* '<S71>/INPUT_3_1_1' */
  real_T INPUT_4_1_1_Discrete_2208644739;/* '<S71>/INPUT_4_1_1' */
  real_T INPUT_4_1_1_FirstOutput_2208644;/* '<S71>/INPUT_4_1_1' */
  real_T TmpRTBAtSelectLogicOutport1_Buf;/* synthesized block */
  real_T STATE_1_Discrete;             /* '<S71>/STATE_1' */
  real_T STATE_1_ZcValueStore;         /* '<S71>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S71>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_ZcValueStore;      /* '<S71>/OUTPUT_1_0' */
  real_T SOC_Buffer;                   /* synthesized block */
  real_T TmpRTBAtModeLogicInport1_Buffer;/* synthesized block */
  real_T TmpRTBAtModeLogicOutport2_Buffe;/* synthesized block */
  real_T wEng_Buffer;                  /* synthesized block */
  real_T OUTPUT_1_1_Discrete;          /* '<S71>/OUTPUT_1_1' */
  real_T OUTPUT_1_1_ZcValueStore;      /* '<S71>/OUTPUT_1_1' */
  real_T speed_buffer[21];             /* '<S1>/Mode Logic' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } DriveCycle1_PWORK;                 /* '<S5>/Drive Cycle 1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } DriveCycle2_PWORK;                 /* '<S5>/Drive Cycle 2' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } DriveCycle3_PWORK;                 /* '<S5>/Drive Cycle 3' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } DriveCycle4_PWORK;                 /* '<S5>/Drive Cycle 4' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } DriveCycle5_PWORK;                 /* '<S5>/Drive Cycle 5' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } DriveCycle6_PWORK;                 /* '<S5>/Drive Cycle 6' */

  void* RTP_1_RtpManager;              /* '<S24>/RTP_1' */
  void* STATE_1_Simulator;             /* '<S71>/STATE_1' */
  void* STATE_1_SimData;               /* '<S71>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S71>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S71>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S71>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S71>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S71>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S71>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S71>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S71>/OUTPUT_1_0' */
  void* SINK_1_RtwLogger;              /* '<S71>/SINK_1' */
  void* SINK_1_RtwLogBuffer;           /* '<S71>/SINK_1' */
  void* SINK_1_RtwLogFcnManager;       /* '<S71>/SINK_1' */
  void* SINK_1_InstRtwLogger;          /* '<S71>/SINK_1' */
  void* SINK_1_InstRtwLogBuffer;       /* '<S71>/SINK_1' */
  void* OUTPUT_1_1_Simulator;          /* '<S71>/OUTPUT_1_1' */
  void* OUTPUT_1_1_SimData;            /* '<S71>/OUTPUT_1_1' */
  void* OUTPUT_1_1_DiagMgr;            /* '<S71>/OUTPUT_1_1' */
  void* OUTPUT_1_1_ZcLogger;           /* '<S71>/OUTPUT_1_1' */
  void* OUTPUT_1_1_TsInfo;             /* '<S71>/OUTPUT_1_1' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S80>/To Workspace' */

  struct {
    int_T PrevIndex;
  } DriveCycle1_IWORK;                 /* '<S5>/Drive Cycle 1' */

  struct {
    int_T PrevIndex;
  } DriveCycle2_IWORK;                 /* '<S5>/Drive Cycle 2' */

  struct {
    int_T PrevIndex;
  } DriveCycle3_IWORK;                 /* '<S5>/Drive Cycle 3' */

  struct {
    int_T PrevIndex;
  } DriveCycle4_IWORK;                 /* '<S5>/Drive Cycle 4' */

  struct {
    int_T PrevIndex;
  } DriveCycle5_IWORK;                 /* '<S5>/Drive Cycle 5' */

  struct {
    int_T PrevIndex;
  } DriveCycle6_IWORK;                 /* '<S5>/Drive Cycle 6' */

  int_T STATE_1_Modes[13];             /* '<S71>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S71>/OUTPUT_1_0' */
  int_T OUTPUT_1_1_Modes;              /* '<S71>/OUTPUT_1_1' */
  int32_T STATE_1_MASS_MATRIX_PR;      /* '<S71>/STATE_1' */
  uint8_T STATE_1_ZcSignalDir;         /* '<S71>/STATE_1' */
  uint8_T STATE_1_ZcStateStore;        /* '<S71>/STATE_1' */
  uint8_T OUTPUT_1_0_ZcSignalDir;      /* '<S71>/OUTPUT_1_0' */
  uint8_T OUTPUT_1_0_ZcStateStore;     /* '<S71>/OUTPUT_1_0' */
  uint8_T OUTPUT_1_1_ZcSignalDir;      /* '<S71>/OUTPUT_1_1' */
  uint8_T OUTPUT_1_1_ZcStateStore;     /* '<S71>/OUTPUT_1_1' */
  uint8_T is_active_c3_HEV_SeriesParallel;/* '<S1>/Mode Logic' */
  uint8_T is_c3_HEV_SeriesParallel;    /* '<S1>/Mode Logic' */
  uint8_T is_Motion_mode;              /* '<S1>/Mode Logic' */
  uint8_T is_Normal_mode;              /* '<S1>/Mode Logic' */
  uint8_T is_Cruise_mode;              /* '<S1>/Mode Logic' */
  boolean_T RTP_1_SetParametersNeeded; /* '<S24>/RTP_1' */
  boolean_T STATE_1_FirstOutput;       /* '<S71>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S71>/OUTPUT_1_0' */
  boolean_T OUTPUT_1_1_FirstOutput;    /* '<S71>/OUTPUT_1_1' */
} DW_HEV_SeriesParallel_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Limits55_CSTATE;              /* '<S81>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE;     /* '<S81>/20Hz Lowpass Filter' */
  real_T StateSpace_CSTATE;            /* '<S76>/State Space' */
  real_T u0HzLowpassFilter_CSTATE_o;   /* '<S16>/20Hz Lowpass Filter' */
  real_T Limits55_CSTATE_f;            /* '<S17>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE_g;   /* '<S17>/20Hz Lowpass Filter' */
  real_T Limits55_CSTATE_n;            /* '<S13>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE_l;   /* '<S13>/20Hz Lowpass Filter' */
  real_T Limits01_CSTATE;              /* '<S10>/Limits [0,1]' */
  real_T u0HzLowpassFilter_CSTATE_f;   /* '<S10>/20Hz Lowpass Filter' */
  real_T HEV_SeriesParallelVehicleSimuli;/* '<S71>/INPUT_4_1_1' */
  real_T HEV_SeriesParallelElectricalGen[58];/* '<S71>/STATE_1' */
  real_T InitialchargeAh0_CSTATE;      /* '<S43>/Initial charge Ah0' */
  real_T Integrator_CSTATE;            /* '<S14>/Integrator' */
  real_T CumulativeL_CSTATE;           /* '<S80>/Cumulative L' */
  real_T CumulativeGal_CSTATE;         /* '<S80>/Cumulative Gal' */
  real_T CumulativeDistanceKm_CSTATE;  /* '<S80>/Cumulative Distance Km' */
} X_HEV_SeriesParallel_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Limits55_CSTATE;              /* '<S81>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE;     /* '<S81>/20Hz Lowpass Filter' */
  real_T StateSpace_CSTATE;            /* '<S76>/State Space' */
  real_T u0HzLowpassFilter_CSTATE_o;   /* '<S16>/20Hz Lowpass Filter' */
  real_T Limits55_CSTATE_f;            /* '<S17>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE_g;   /* '<S17>/20Hz Lowpass Filter' */
  real_T Limits55_CSTATE_n;            /* '<S13>/Limits [-5,5]' */
  real_T u0HzLowpassFilter_CSTATE_l;   /* '<S13>/20Hz Lowpass Filter' */
  real_T Limits01_CSTATE;              /* '<S10>/Limits [0,1]' */
  real_T u0HzLowpassFilter_CSTATE_f;   /* '<S10>/20Hz Lowpass Filter' */
  real_T HEV_SeriesParallelVehicleSimuli;/* '<S71>/INPUT_4_1_1' */
  real_T HEV_SeriesParallelElectricalGen[58];/* '<S71>/STATE_1' */
  real_T InitialchargeAh0_CSTATE;      /* '<S43>/Initial charge Ah0' */
  real_T Integrator_CSTATE;            /* '<S14>/Integrator' */
  real_T CumulativeL_CSTATE;           /* '<S80>/Cumulative L' */
  real_T CumulativeGal_CSTATE;         /* '<S80>/Cumulative Gal' */
  real_T CumulativeDistanceKm_CSTATE;  /* '<S80>/Cumulative Distance Km' */
} XDot_HEV_SeriesParallel_T;

/* State disabled  */
typedef struct {
  boolean_T Limits55_CSTATE;           /* '<S81>/Limits [-5,5]' */
  boolean_T u0HzLowpassFilter_CSTATE;  /* '<S81>/20Hz Lowpass Filter' */
  boolean_T StateSpace_CSTATE;         /* '<S76>/State Space' */
  boolean_T u0HzLowpassFilter_CSTATE_o;/* '<S16>/20Hz Lowpass Filter' */
  boolean_T Limits55_CSTATE_f;         /* '<S17>/Limits [-5,5]' */
  boolean_T u0HzLowpassFilter_CSTATE_g;/* '<S17>/20Hz Lowpass Filter' */
  boolean_T Limits55_CSTATE_n;         /* '<S13>/Limits [-5,5]' */
  boolean_T u0HzLowpassFilter_CSTATE_l;/* '<S13>/20Hz Lowpass Filter' */
  boolean_T Limits01_CSTATE;           /* '<S10>/Limits [0,1]' */
  boolean_T u0HzLowpassFilter_CSTATE_f;/* '<S10>/20Hz Lowpass Filter' */
  boolean_T HEV_SeriesParallelVehicleSimuli;/* '<S71>/INPUT_4_1_1' */
  boolean_T HEV_SeriesParallelElectricalGen[58];/* '<S71>/STATE_1' */
  boolean_T InitialchargeAh0_CSTATE;   /* '<S43>/Initial charge Ah0' */
  boolean_T Integrator_CSTATE;         /* '<S14>/Integrator' */
  boolean_T CumulativeL_CSTATE;        /* '<S80>/Cumulative L' */
  boolean_T CumulativeGal_CSTATE;      /* '<S80>/Cumulative Gal' */
  boolean_T CumulativeDistanceKm_CSTATE;/* '<S80>/Cumulative Distance Km' */
} XDis_HEV_SeriesParallel_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Limits55_Reset_ZCE;       /* '<S17>/Limits [-5,5]' */
  ZCSigState Limits01_Reset_ZCE;       /* '<S10>/Limits [0,1]' */
} PrevZCX_HEV_SeriesParallel_T;

/* Mass Matrix (global) */
typedef struct {
  int_T ir[36];
  int_T jc[75];
  real_T pr[36];
} MassMatrix_HEV_SeriesParallel_T;

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

/* Parameters (default storage) */
struct P_HEV_SeriesParallel_T_ {
  struct_viMUS9ki6lFwfEmklEsm9G HEV_Param;/* Variable: HEV_Param
                                           * Referenced by:
                                           *   '<S4>/Fuel Consumption Table'
                                           *   '<S10>/Ki'
                                           *   '<S10>/Kp'
                                           *   '<S13>/Ki'
                                           *   '<S13>/Kp'
                                           *   '<S14>/Gain'
                                           *   '<S3>/Subsystem_around_RTP_3224FFEB_w'
                                           *   '<S81>/Ki'
                                           *   '<S81>/Kp'
                                           *   '<S8>/Subsystem_around_RTP_494A81BE_mass'
                                           *   '<S17>/Ki'
                                           *   '<S17>/Kp'
                                           */
  real_T AH;                           /* Variable: AH
                                        * Referenced by: '<S42>/Calc Pct'
                                        */
  real_T AH0;                          /* Variable: AH0
                                        * Referenced by:
                                        *   '<S22>/Subsystem_around_RTP_1737879D_charge'
                                        *   '<S43>/Initial charge Ah0'
                                        */
  real_T Drive_Cycle_Num;              /* Variable: Drive_Cycle_Num
                                        * Referenced by: '<S5>/Select Cycle'
                                        */
  real_T SensorDynamics_x_initial;   /* Mask Parameter: SensorDynamics_x_initial
                                      * Referenced by: '<S14>/Integrator'
                                      */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Limits55_IC;                  /* Expression: 0
                                        * Referenced by: '<S81>/Limits [-5,5]'
                                        */
  real_T Limits55_UpperSat;            /* Expression: 5
                                        * Referenced by: '<S81>/Limits [-5,5]'
                                        */
  real_T Limits55_LowerSat;            /* Expression: -5
                                        * Referenced by: '<S81>/Limits [-5,5]'
                                        */
  real_T u0HzLowpassFilter_A;         /* Computed Parameter: u0HzLowpassFilter_A
                                       * Referenced by: '<S81>/20Hz Lowpass Filter'
                                       */
  real_T u0HzLowpassFilter_C;         /* Computed Parameter: u0HzLowpassFilter_C
                                       * Referenced by: '<S81>/20Hz Lowpass Filter'
                                       */
  real_T LimitAcc_UpperSat;            /* Expression: 1
                                        * Referenced by: '<S81>/Limit Acc'
                                        */
  real_T LimitAcc_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S81>/Limit Acc'
                                        */
  real_T AcctowEng_tableData[4];       /* Expression: [800 5000 6000 6000]
                                        * Referenced by: '<S1>/Acc to wEng'
                                        */
  real_T AcctowEng_bp01Data[4];        /* Expression: [0 0.9 0.95 1]
                                        * Referenced by: '<S1>/Acc to wEng'
                                        */
  real_T StateSpace_A_pr;              /* Computed Parameter: StateSpace_A_pr
                                        * Referenced by: '<S76>/State Space'
                                        */
  real_T StateSpace_B_pr;              /* Computed Parameter: StateSpace_B_pr
                                        * Referenced by: '<S76>/State Space'
                                        */
  real_T StateSpace_C_pr;              /* Computed Parameter: StateSpace_C_pr
                                        * Referenced by: '<S76>/State Space'
                                        */
  real_T StateSpace_InitialCondition;  /* Expression: X0
                                        * Referenced by: '<S76>/State Space'
                                        */
  real_T u0HzLowpassFilter_A_c;     /* Computed Parameter: u0HzLowpassFilter_A_c
                                     * Referenced by: '<S16>/20Hz Lowpass Filter'
                                     */
  real_T u0HzLowpassFilter_C_l;     /* Computed Parameter: u0HzLowpassFilter_C_l
                                     * Referenced by: '<S16>/20Hz Lowpass Filter'
                                     */
  real_T TmpRTBAtSelectLogicOutport1_Ini;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Limits55_IC_c;                /* Expression: 0
                                        * Referenced by: '<S17>/Limits [-5,5]'
                                        */
  real_T Limits55_UpperSat_f;          /* Expression: 5
                                        * Referenced by: '<S17>/Limits [-5,5]'
                                        */
  real_T Limits55_LowerSat_d;          /* Expression: -5
                                        * Referenced by: '<S17>/Limits [-5,5]'
                                        */
  real_T u0HzLowpassFilter_A_o;     /* Computed Parameter: u0HzLowpassFilter_A_o
                                     * Referenced by: '<S17>/20Hz Lowpass Filter'
                                     */
  real_T u0HzLowpassFilter_C_m;     /* Computed Parameter: u0HzLowpassFilter_C_m
                                     * Referenced by: '<S17>/20Hz Lowpass Filter'
                                     */
  real_T AcctowMot_tableData[3];       /* Expression: [0 6000 6000]
                                        * Referenced by: '<S1>/Acc to wMot'
                                        */
  real_T AcctowMot_bp01Data[3];        /* Expression: [0 1 1.2]
                                        * Referenced by: '<S1>/Acc to wMot'
                                        */
  real_T rpm2volts_Gain;               /* Expression: 5/10000
                                        * Referenced by: '<S17>/rpm2volts'
                                        */
  real_T u5_UpperSat;                  /* Expression: 5
                                        * Referenced by: '<S17>/[-5,5]'
                                        */
  real_T u5_LowerSat;                  /* Expression: -5
                                        * Referenced by: '<S17>/[-5,5]'
                                        */
  real_T VoltsNm_Gain;                 /* Expression: 400/5
                                        * Referenced by: '<S17>/Volts//Nm'
                                        */
  real_T Limits55_IC_h;                /* Expression: 0
                                        * Referenced by: '<S13>/Limits [-5,5]'
                                        */
  real_T Limits55_UpperSat_g;          /* Expression: 5
                                        * Referenced by: '<S13>/Limits [-5,5]'
                                        */
  real_T Limits55_LowerSat_c;          /* Expression: -5
                                        * Referenced by: '<S13>/Limits [-5,5]'
                                        */
  real_T u0HzLowpassFilter_A_b;     /* Computed Parameter: u0HzLowpassFilter_A_b
                                     * Referenced by: '<S13>/20Hz Lowpass Filter'
                                     */
  real_T u0HzLowpassFilter_C_f;     /* Computed Parameter: u0HzLowpassFilter_C_f
                                     * Referenced by: '<S13>/20Hz Lowpass Filter'
                                     */
  real_T rpm2volts_Gain_p;             /* Expression: 5/6500
                                        * Referenced by: '<S13>/rpm2volts'
                                        */
  real_T u5_UpperSat_m;                /* Expression: 5
                                        * Referenced by: '<S13>/[-5,5]'
                                        */
  real_T u5_LowerSat_a;                /* Expression: -5
                                        * Referenced by: '<S13>/[-5,5]'
                                        */
  real_T VoltsNm_Gain_c;               /* Expression: 400/5
                                        * Referenced by: '<S13>/Volts//Nm'
                                        */
  real_T Limits01_IC;                  /* Expression: 0
                                        * Referenced by: '<S10>/Limits [0,1]'
                                        */
  real_T Limits01_UpperSat;            /* Expression: 1
                                        * Referenced by: '<S10>/Limits [0,1]'
                                        */
  real_T Limits01_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S10>/Limits [0,1]'
                                        */
  real_T u0HzLowpassFilter_A_a;     /* Computed Parameter: u0HzLowpassFilter_A_a
                                     * Referenced by: '<S10>/20Hz Lowpass Filter'
                                     */
  real_T u0HzLowpassFilter_C_o;     /* Computed Parameter: u0HzLowpassFilter_C_o
                                     * Referenced by: '<S10>/20Hz Lowpass Filter'
                                     */
  real_T EngineIdle_Value;             /* Expression: 800
                                        * Referenced by: '<S10>/Engine Idle'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T u1_UpperSat;                  /* Expression: 1
                                        * Referenced by: '<S10>/[0,1]'
                                        */
  real_T u1_LowerSat;                  /* Expression: 0
                                        * Referenced by: '<S10>/[0,1]'
                                        */
  real_T LimitBrk_UpperSat;            /* Expression: 0
                                        * Referenced by: '<S81>/Limit Brk'
                                        */
  real_T LimitBrk_LowerSat;            /* Expression: -inf
                                        * Referenced by: '<S81>/Limit Brk'
                                        */
  real_T Gain_Gain;                    /* Expression: 200
                                        * Referenced by: '<S81>/Gain'
                                        */
  real_T RTP_0BC1812E_w_Value;         /* Expression: 0
                                        * Referenced by: '<S25>/Subsystem_around_RTP_0BC1812E_w'
                                        */
  real_T RTP_DB87A893_w_Value;         /* Expression: 0
                                        * Referenced by: '<S54>/Subsystem_around_RTP_DB87A893_w'
                                        */
  real_T RTP_494A81BE_v_Value;         /* Expression: 0
                                        * Referenced by: '<S8>/Subsystem_around_RTP_494A81BE_v'
                                        */
  real_T RTP_4B685322_w_Value;         /* Expression: 0
                                        * Referenced by: '<S8>/Subsystem_around_RTP_4B685322_w'
                                        */
  real_T RTP_ACD07E25_w_Value;         /* Expression: 0
                                        * Referenced by: '<S8>/Subsystem_around_RTP_ACD07E25_w'
                                        */
  real_T RTP_DBD74EB3_w_Value;         /* Expression: 0
                                        * Referenced by: '<S8>/Subsystem_around_RTP_DBD74EB3_w'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 1/100
                                        * Referenced by: '<S42>/Gain'
                                        */
  real_T Zero1_Value[2];               /* Expression: [0 0]
                                        * Referenced by: '<S54>/Zero1'
                                        */
  real_T Zero7_Value[2];               /* Expression: [0 0]
                                        * Referenced by: '<S54>/Zero7'
                                        */
  real_T Zero4_Value;                  /* Expression: 0
                                        * Referenced by: '<S54>/Zero4'
                                        */
  real_T Zero3_Value;                  /* Expression: 0
                                        * Referenced by: '<S54>/Zero3'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Zero6_Value;                  /* Expression: 0
                                        * Referenced by: '<S54>/Zero6'
                                        */
  real_T rpm2rads_Gain;                /* Expression: pi/30
                                        * Referenced by: '<S99>/rpm2rad//s'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S99>/Gain4'
                                        */
  real_T rpm2rads_Gain_f;              /* Expression: pi/30
                                        * Referenced by: '<S98>/rpm2rad//s'
                                        */
  real_T Gain4_Gain_j;                 /* Expression: 1/1000
                                        * Referenced by: '<S98>/Gain4'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 60/(2*pi)
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 60/(2*pi)
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T GenRPMtoV_Gain;               /* Expression: 5/10000
                                        * Referenced by: '<S17>/Gen RPM to V'
                                        */
  real_T MotRPMtoV_Gain;               /* Expression: 5/6700
                                        * Referenced by: '<S13>/Mot RPM to V'
                                        */
  real_T TmpRTBAtModeLogicOutport2_Initi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T radstorpm_Value;              /* Expression: 60/(2*pi)
                                        * Referenced by: '<S72>/rad//s to rpm'
                                        */
  real_T CumulativeL_IC;               /* Expression: eps
                                        * Referenced by: '<S80>/Cumulative L'
                                        */
  real_T CumulativeGal_IC;             /* Expression: eps
                                        * Referenced by: '<S80>/Cumulative Gal'
                                        */
  real_T gstoKgs_Gain;                 /* Expression: 0.001
                                        * Referenced by: '<S80>/g//s to Kg//s'
                                        */
  real_T GasolineDensityKgm3_Value;    /* Expression: 750
                                        * Referenced by: '<S80>/Gasoline Density Kg//m^3'
                                        */
  real_T m3toL_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S80>/m^3 to L'
                                        */
  real_T m3togal_Gain;                 /* Expression: 264.172
                                        * Referenced by: '<S80>/m^3 to gal'
                                        */
  real_T CumulativeDistanceKm_IC;      /* Expression: eps
                                        * Referenced by: '<S80>/Cumulative Distance Km'
                                        */
  real_T KphtoKps_Gain;                /* Expression: 1/3600
                                        * Referenced by: '<S80>/Kph to Kps'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint32_T StateSpace_A_ir;            /* Computed Parameter: StateSpace_A_ir
                                        * Referenced by: '<S76>/State Space'
                                        */
  uint32_T StateSpace_A_jc[2];         /* Computed Parameter: StateSpace_A_jc
                                        * Referenced by: '<S76>/State Space'
                                        */
  uint32_T StateSpace_B_ir;            /* Computed Parameter: StateSpace_B_ir
                                        * Referenced by: '<S76>/State Space'
                                        */
  uint32_T StateSpace_B_jc[2];         /* Computed Parameter: StateSpace_B_jc
                                        * Referenced by: '<S76>/State Space'
                                        */
  uint32_T StateSpace_C_ir;            /* Computed Parameter: StateSpace_C_ir
                                        * Referenced by: '<S76>/State Space'
                                        */
  uint32_T StateSpace_C_jc[2];         /* Computed Parameter: StateSpace_C_jc
                                        * Referenced by: '<S76>/State Space'
                                        */
  uint8_T SelectLogic_CurrentSetting;
                               /* Computed Parameter: SelectLogic_CurrentSetting
                                * Referenced by: '<S16>/Select Logic'
                                */
  uint8_T SelectLogic_CurrentSetting_i;
                             /* Computed Parameter: SelectLogic_CurrentSetting_i
                              * Referenced by: '<S19>/Select Logic'
                              */
  uint8_T SelectLogic_CurrentSetting_n;
                             /* Computed Parameter: SelectLogic_CurrentSetting_n
                              * Referenced by: '<S15>/Select Logic'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_HEV_SeriesParallel_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_HEV_SeriesParallel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_HEV_SeriesParallel_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  int_T massMatrixType;
  int_T massMatrixNzMax;
  int_T *massMatrixIr;
  int_T *massMatrixJc;
  real_T *massMatrixPr;
  real_T odeX0[74];
  real_T odeF0[74];
  real_T odeX1START[74];
  real_T odeF1[74];
  real_T odeDELTA[74];
  real_T odeE[4*74];
  real_T odeFAC[74];
  real_T odeDFDX[74*74];
  real_T odeW[74*74];
  int_T odePIVOTS[74];
  real_T odeXTMP[74];
  real_T odeZTMP[74];
  real_T odeMASSMATRIX_M[36];
  real_T odeMASSMATRIX_M1[36];
  real_T odeEDOT[4*74];
  real_T odeXDOT[74];
  real_T odeFMXDOT[74];
  ODE14X_IntgData intgData;

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
extern P_HEV_SeriesParallel_T HEV_SeriesParallel_P;

/* Block signals (default storage) */
extern B_HEV_SeriesParallel_T HEV_SeriesParallel_B;

/* Continuous states (default storage) */
extern X_HEV_SeriesParallel_T HEV_SeriesParallel_X;

/* Disabled states (default storage) */
extern XDis_HEV_SeriesParallel_T HEV_SeriesParallel_XDis;

/* Block states (default storage) */
extern DW_HEV_SeriesParallel_T HEV_SeriesParallel_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_HEV_SeriesParallel_T HEV_SeriesParallel_PrevZCX;

/* global MassMatrix */
extern MassMatrix_HEV_SeriesParallel_T HEV_SeriesParallel_MassMatrix;

/* Model entry point functions */
extern void HEV_SeriesParallel_initialize(void);
extern void HEV_SeriesParallel_step0(void);
extern void HEV_SeriesParallel_step2(void);/* Sample time: [0.1s, 0.0s] */
extern void HEV_SeriesParallel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HEV_SeriesParallel_T *const HEV_SeriesParallel_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'HEV_SeriesParallel'
 * '<S1>'   : 'HEV_SeriesParallel/Control'
 * '<S2>'   : 'HEV_SeriesParallel/Electrical'
 * '<S3>'   : 'HEV_SeriesParallel/Engine'
 * '<S4>'   : 'HEV_SeriesParallel/Fuel Economy'
 * '<S5>'   : 'HEV_SeriesParallel/Kph  Demand'
 * '<S6>'   : 'HEV_SeriesParallel/Power Split Device'
 * '<S7>'   : 'HEV_SeriesParallel/Scopes'
 * '<S8>'   : 'HEV_SeriesParallel/Vehicle'
 * '<S9>'   : 'HEV_SeriesParallel/Control/Battery Charge Controller'
 * '<S10>'  : 'HEV_SeriesParallel/Control/Engine Speed Controller'
 * '<S11>'  : 'HEV_SeriesParallel/Control/Generator Controller'
 * '<S12>'  : 'HEV_SeriesParallel/Control/Mode Logic'
 * '<S13>'  : 'HEV_SeriesParallel/Control/Motor Controller'
 * '<S14>'  : 'HEV_SeriesParallel/Control/Sensor Dynamics'
 * '<S15>'  : 'HEV_SeriesParallel/Control/Engine Speed Controller/Engine Running'
 * '<S16>'  : 'HEV_SeriesParallel/Control/Generator Controller/Enable Torque Demand'
 * '<S17>'  : 'HEV_SeriesParallel/Control/Generator Controller/Speed controller'
 * '<S18>'  : 'HEV_SeriesParallel/Control/Generator Controller/Subsystem1'
 * '<S19>'  : 'HEV_SeriesParallel/Control/Motor Controller/Enable Torque Demand'
 * '<S20>'  : 'HEV_SeriesParallel/Electrical/DC-DC Converter'
 * '<S21>'  : 'HEV_SeriesParallel/Electrical/Generator'
 * '<S22>'  : 'HEV_SeriesParallel/Electrical/Generic'
 * '<S23>'  : 'HEV_SeriesParallel/Electrical/Motor'
 * '<S24>'  : 'HEV_SeriesParallel/Electrical/Solver Configuration'
 * '<S25>'  : 'HEV_SeriesParallel/Electrical/Generator/System'
 * '<S26>'  : 'HEV_SeriesParallel/Electrical/Generator/System/GF'
 * '<S27>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Meas V'
 * '<S28>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Power Sensor'
 * '<S29>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft'
 * '<S30>'  : 'HEV_SeriesParallel/Electrical/Generator/System/GF/Simulink-PS Converter'
 * '<S31>'  : 'HEV_SeriesParallel/Electrical/Generator/System/GF/Simulink-PS Converter/EVAL_KEY'
 * '<S32>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Meas V/PS-Simulink Converter4'
 * '<S33>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Meas V/PS-Simulink Converter4/EVAL_KEY'
 * '<S34>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/PS-Simulink Converter4'
 * '<S35>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Power Sensor/PS-Simulink Converter4/EVAL_KEY'
 * '<S36>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/PS-Simulink Converter1'
 * '<S37>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/PS-Simulink Converter2'
 * '<S38>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/PS-Simulink Converter3'
 * '<S39>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/PS-Simulink Converter1/EVAL_KEY'
 * '<S40>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/PS-Simulink Converter2/EVAL_KEY'
 * '<S41>'  : 'HEV_SeriesParallel/Electrical/Generator/System/Sensor shaft/PS-Simulink Converter3/EVAL_KEY'
 * '<S42>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1'
 * '<S43>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge'
 * '<S44>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/PS-Simulink Converter1'
 * '<S45>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/PS-Simulink Converter2'
 * '<S46>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS-Simulink Converter'
 * '<S47>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS-Simulink Converter1'
 * '<S48>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS-Simulink Converter2'
 * '<S49>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS-Simulink Converter/EVAL_KEY'
 * '<S50>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS-Simulink Converter1/EVAL_KEY'
 * '<S51>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/Calculate battery power & charge/PS-Simulink Converter2/EVAL_KEY'
 * '<S52>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/PS-Simulink Converter1/EVAL_KEY'
 * '<S53>'  : 'HEV_SeriesParallel/Electrical/Generic/Measurements1/PS-Simulink Converter2/EVAL_KEY'
 * '<S54>'  : 'HEV_SeriesParallel/Electrical/Motor/System'
 * '<S55>'  : 'HEV_SeriesParallel/Electrical/Motor/System/GF'
 * '<S56>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Meas V'
 * '<S57>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Power Sensor'
 * '<S58>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft'
 * '<S59>'  : 'HEV_SeriesParallel/Electrical/Motor/System/GF/Simulink-PS Converter'
 * '<S60>'  : 'HEV_SeriesParallel/Electrical/Motor/System/GF/Simulink-PS Converter/EVAL_KEY'
 * '<S61>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Meas V/PS-Simulink Converter4'
 * '<S62>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Meas V/PS-Simulink Converter4/EVAL_KEY'
 * '<S63>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/PS-Simulink Converter4'
 * '<S64>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Power Sensor/PS-Simulink Converter4/EVAL_KEY'
 * '<S65>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/PS-Simulink Converter1'
 * '<S66>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/PS-Simulink Converter2'
 * '<S67>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/PS-Simulink Converter3'
 * '<S68>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/PS-Simulink Converter1/EVAL_KEY'
 * '<S69>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/PS-Simulink Converter2/EVAL_KEY'
 * '<S70>'  : 'HEV_SeriesParallel/Electrical/Motor/System/Sensor shaft/PS-Simulink Converter3/EVAL_KEY'
 * '<S71>'  : 'HEV_SeriesParallel/Electrical/Solver Configuration/EVAL_KEY'
 * '<S72>'  : 'HEV_SeriesParallel/Engine/Sensor'
 * '<S73>'  : 'HEV_SeriesParallel/Engine/Simulink-PS Converter'
 * '<S74>'  : 'HEV_SeriesParallel/Engine/Sensor/PS-Simulink Converter'
 * '<S75>'  : 'HEV_SeriesParallel/Engine/Sensor/PS-Simulink Converter1'
 * '<S76>'  : 'HEV_SeriesParallel/Engine/Sensor/Transfer Fcn (with initial outputs)'
 * '<S77>'  : 'HEV_SeriesParallel/Engine/Sensor/PS-Simulink Converter/EVAL_KEY'
 * '<S78>'  : 'HEV_SeriesParallel/Engine/Sensor/PS-Simulink Converter1/EVAL_KEY'
 * '<S79>'  : 'HEV_SeriesParallel/Engine/Simulink-PS Converter/EVAL_KEY'
 * '<S80>'  : 'HEV_SeriesParallel/Fuel Economy/Calculate  Fuel Economy'
 * '<S81>'  : 'HEV_SeriesParallel/Kph  Demand/Vehicle Speed Controller'
 * '<S82>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft'
 * '<S83>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft'
 * '<S84>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft'
 * '<S85>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/PS-Simulink Converter'
 * '<S86>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/PS-Simulink Converter1'
 * '<S87>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/PS-Simulink Converter/EVAL_KEY'
 * '<S88>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Carrier Shaft/PS-Simulink Converter1/EVAL_KEY'
 * '<S89>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/PS-Simulink Converter'
 * '<S90>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/PS-Simulink Converter1'
 * '<S91>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/PS-Simulink Converter/EVAL_KEY'
 * '<S92>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Ring Shaft/PS-Simulink Converter1/EVAL_KEY'
 * '<S93>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/PS-Simulink Converter'
 * '<S94>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/PS-Simulink Converter1'
 * '<S95>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/PS-Simulink Converter/EVAL_KEY'
 * '<S96>'  : 'HEV_SeriesParallel/Power Split Device/Sensor Sun Shaft/PS-Simulink Converter1/EVAL_KEY'
 * '<S97>'  : 'HEV_SeriesParallel/Scopes/Drivetrain Scopes'
 * '<S98>'  : 'HEV_SeriesParallel/Scopes/Power Calculation2'
 * '<S99>'  : 'HEV_SeriesParallel/Scopes/Power Calculation'
 * '<S100>' : 'HEV_SeriesParallel/Vehicle/PS-Simulink Converter1'
 * '<S101>' : 'HEV_SeriesParallel/Vehicle/PS-Simulink Converter3'
 * '<S102>' : 'HEV_SeriesParallel/Vehicle/Sensor Speed and  Power'
 * '<S103>' : 'HEV_SeriesParallel/Vehicle/Simulink-PS Converter'
 * '<S104>' : 'HEV_SeriesParallel/Vehicle/PS-Simulink Converter1/EVAL_KEY'
 * '<S105>' : 'HEV_SeriesParallel/Vehicle/PS-Simulink Converter3/EVAL_KEY'
 * '<S106>' : 'HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/PS-Simulink Converter'
 * '<S107>' : 'HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/PS-Simulink Converter1'
 * '<S108>' : 'HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/PS-Simulink Converter/EVAL_KEY'
 * '<S109>' : 'HEV_SeriesParallel/Vehicle/Sensor Speed and  Power/PS-Simulink Converter1/EVAL_KEY'
 * '<S110>' : 'HEV_SeriesParallel/Vehicle/Simulink-PS Converter/EVAL_KEY'
 */
#endif                                 /* HEV_SeriesParallel_h_ */
