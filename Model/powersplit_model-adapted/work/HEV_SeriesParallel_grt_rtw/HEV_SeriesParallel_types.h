/*
 * HEV_SeriesParallel_types.h
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

#ifndef HEV_SeriesParallel_types_h_
#define HEV_SeriesParallel_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_JDETPJj2kcGIsweBPQ98fB_
#define DEFINED_TYPEDEF_FOR_struct_JDETPJj2kcGIsweBPQ98fB_

typedef struct {
  real_T Nominal_Voltage;
  real_T Rated_Capacity;
  real_T Initial_SOC;
  real_T Series_Resistance;
} struct_JDETPJj2kcGIsweBPQ98fB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_JhoKYoz2hGV8jDIlH4En1_
#define DEFINED_TYPEDEF_FOR_struct_JhoKYoz2hGV8jDIlH4En1_

typedef struct {
  real_T Capacitance;
  real_T Initial_Voltage;
  real_T Series_Resistance;
} struct_JhoKYoz2hGV8jDIlH4En1;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_N6cmUIP8FQ5nBiL358fYKC_
#define DEFINED_TYPEDEF_FOR_struct_N6cmUIP8FQ5nBiL358fYKC_

typedef struct {
  real_T Nominal_Voltage;
  real_T Internal_Resistance;
  real_T Rated_Capacity;
  real_T Initial_Charge;
  real_T Expn_Voltage;
  real_T Expn_Charge;
  struct_JhoKYoz2hGV8jDIlH4En1 C1;
  real_T R2;
  real_T R1;
  real_T Maximum_Capacity;
} struct_N6cmUIP8FQ5nBiL358fYKC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_EwKldMrEr7itAF7eaynbsC_
#define DEFINED_TYPEDEF_FOR_struct_EwKldMrEr7itAF7eaynbsC_

typedef struct {
  real_T Nominal_Capacitance;
  real_T Rate_C_V;
  real_T Series_R;
  real_T Self_Discharge_R;
  real_T Initial_Voltage;
} struct_EwKldMrEr7itAF7eaynbsC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_AQRTbntO0SR8Q0kxeuukpB_
#define DEFINED_TYPEDEF_FOR_struct_AQRTbntO0SR8Q0kxeuukpB_

typedef struct {
  real_T SpeedRPM[9];
  real_T TorqueNm[9];
} struct_AQRTbntO0SR8Q0kxeuukpB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_8aPerL8pmtzxlK76aYJqtE_
#define DEFINED_TYPEDEF_FOR_struct_8aPerL8pmtzxlK76aYJqtE_

typedef struct {
  real_T Stator_Resistance;
  struct_AQRTbntO0SR8Q0kxeuukpB TorqSpdLUT;
  real_T Damping;
  real_T TorqueControl_TimeConst;
  real_T Shaft_Inertia;
  real_T Series_Resistance;
  real_T Inductances[2];
  real_T Efficiency;
} struct_8aPerL8pmtzxlK76aYJqtE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_fpbCCNPhA7pFiJQ5vSPIpH_
#define DEFINED_TYPEDEF_FOR_struct_fpbCCNPhA7pFiJQ5vSPIpH_

typedef struct {
  real_T SpeedRPM[7];
  real_T TorqueNm[7];
} struct_fpbCCNPhA7pFiJQ5vSPIpH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_xRWva094RObxqjRA82FQXC_
#define DEFINED_TYPEDEF_FOR_struct_xRWva094RObxqjRA82FQXC_

typedef struct {
  real_T Stator_Resistance;
  real_T Inductances[2];
  struct_fpbCCNPhA7pFiJQ5vSPIpH TorqSpdLUT;
  real_T Damping;
  real_T TorqueControl_TimeConst;
  real_T Shaft_Inertia;
  real_T Series_Resistance;
  real_T TorqIndep_Elec_Loss;
  real_T Shaft_Stiffness;
  real_T Shaft_Damping;
} struct_xRWva094RObxqjRA82FQXC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_xYTLf9xRBpYnquzooZvpnD_
#define DEFINED_TYPEDEF_FOR_struct_xYTLf9xRBpYnquzooZvpnD_

typedef struct {
  real_T Kp;
  real_T Ki;
} struct_xYTLf9xRBpYnquzooZvpnD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_H09AU7rwkGXM61cCx7vfx_
#define DEFINED_TYPEDEF_FOR_struct_H09AU7rwkGXM61cCx7vfx_

typedef struct {
  real_T Area;
  real_T HT_Coefficient;
} struct_H09AU7rwkGXM61cCx7vfx;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_guGsYHR0LvyROtuPQaWGZC_
#define DEFINED_TYPEDEF_FOR_struct_guGsYHR0LvyROtuPQaWGZC_

typedef struct {
  real_T Output_Voltage;
  real_T Resistance_Losses;
  real_T Kp;
  real_T Ki;
  real_T MinVin;
  struct_xYTLf9xRBpYnquzooZvpnD Mean_Boost;
  real_T EPower2Heat;
  real_T Thermal_Mass;
  real_T Specific_Heat;
  real_T Initial_Temperature;
  real_T Air_Temperature;
  struct_H09AU7rwkGXM61cCx7vfx Convection;
} struct_guGsYHR0LvyROtuPQaWGZC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_N6UAlcLsvmIfVRPUGEMzLH_
#define DEFINED_TYPEDEF_FOR_struct_N6UAlcLsvmIfVRPUGEMzLH_

typedef struct {
  real_T Engine_Start_RPM;
  real_T Engine_Stop_RPM;
  real_T Mode_Logic_TS;
  struct_xYTLf9xRBpYnquzooZvpnD ICE;
  struct_xYTLf9xRBpYnquzooZvpnD Gen;
  struct_xYTLf9xRBpYnquzooZvpnD Mot;
  struct_xYTLf9xRBpYnquzooZvpnD Veh_Spd;
} struct_N6UAlcLsvmIfVRPUGEMzLH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_wu3Jk9giObpYBD7deqwJfF_
#define DEFINED_TYPEDEF_FOR_struct_wu3Jk9giObpYBD7deqwJfF_

typedef struct {
  real_T Rated_Vertical_Load;
  real_T Rated_Peak_Long_Force;
  real_T Slip_At_Peak_Force;
  real_T Relaxation_Length;
} struct_wu3Jk9giObpYBD7deqwJfF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_KpsyKQBtfBnTUOG3C2PSWF_
#define DEFINED_TYPEDEF_FOR_struct_KpsyKQBtfBnTUOG3C2PSWF_

typedef struct {
  real_T Inertia;
  real_T Friction;
} struct_KpsyKQBtfBnTUOG3C2PSWF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_pkbgkMLZjkDAlrgmDUDbRE_
#define DEFINED_TYPEDEF_FOR_struct_pkbgkMLZjkDAlrgmDUDbRE_

typedef struct {
  real_T Mass;
  real_T Tire_Radius;
  real_T Wheel_Inertia;
  real_T Aero_Drag_Coeff;
  real_T Incline;
  real_T Engine_Vehicle_Gear_Ratio;
  real_T Distance_CG_FrontAxle;
  real_T Distance_CG_RearAxle;
  real_T Distance_CG_Ground;
  real_T Frontal_Area;
  struct_wu3Jk9giObpYBD7deqwJfF Tire;
  struct_KpsyKQBtfBnTUOG3C2PSWF Trans;
} struct_pkbgkMLZjkDAlrgmDUDbRE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nnko5zLY5S8ohlsir3KnqH_
#define DEFINED_TYPEDEF_FOR_struct_nnko5zLY5S8ohlsir3KnqH_

typedef struct {
  real_T Ratio_Ring2Sun;
} struct_nnko5zLY5S8ohlsir3KnqH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_wiERIn8bOAze3d5T3Q7LgD_
#define DEFINED_TYPEDEF_FOR_struct_wiERIn8bOAze3d5T3Q7LgD_

typedef struct {
  real_T Speed_Vector[10];
  real_T Torque_Vector[10];
  real_T Consumption_Table[100];
} struct_wiERIn8bOAze3d5T3Q7LgD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_7OZMJUDwpN0kP7QD8tCAsG_
#define DEFINED_TYPEDEF_FOR_struct_7OZMJUDwpN0kP7QD8tCAsG_

typedef struct {
  real_T Shaft_Inertia;
  real_T Max_Power;
  real_T Speed_At_Max_Power;
  real_T Max_Speed;
  real_T Friction;
  real_T sensor_time_constant;
  struct_wiERIn8bOAze3d5T3Q7LgD FC;
} struct_7OZMJUDwpN0kP7QD8tCAsG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_OlzbVjuCjSQXjozUzT8IJE_
#define DEFINED_TYPEDEF_FOR_struct_OlzbVjuCjSQXjozUzT8IJE_

typedef struct {
  real_T NominalCap;
  real_T SOC_init;
  real_T theta_init;
  real_T Ctheta;
  real_T Area;
  real_T Rtheta;
  real_T Kc;
  real_T Costar;
  real_T Kt_Temps[4];
  real_T Kt[4];
  real_T delta;
  real_T Istar;
  real_T theta_f;
  real_T Ep;
  real_T Gpo;
  real_T Vpo;
  real_T Ap;
  real_T Taup;
  real_T Emo;
  real_T Ke;
  real_T Ao;
  real_T Roo;
  real_T R10;
  real_T A21;
  real_T A22;
  real_T R20;
  real_T Tau1;
  real_T ns;
  real_T Qe_init;
} struct_OlzbVjuCjSQXjozUzT8IJE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_viMUS9ki6lFwfEmklEsm9G_
#define DEFINED_TYPEDEF_FOR_struct_viMUS9ki6lFwfEmklEsm9G_

typedef struct {
  struct_JDETPJj2kcGIsweBPQ98fB Battery_Det;
  struct_N6cmUIP8FQ5nBiL358fYKC Battery_Sys;
  struct_EwKldMrEr7itAF7eaynbsC UltraCapacitor;
  struct_8aPerL8pmtzxlK76aYJqtE Motor;
  struct_xRWva094RObxqjRA82FQXC Generator;
  struct_guGsYHR0LvyROtuPQaWGZC DCDCConv;
  struct_N6UAlcLsvmIfVRPUGEMzLH Control;
  struct_pkbgkMLZjkDAlrgmDUDbRE Vehicle;
  struct_nnko5zLY5S8ohlsir3KnqH Power_Split;
  struct_7OZMJUDwpN0kP7QD8tCAsG ICE;
  struct_OlzbVjuCjSQXjozUzT8IJE Battery_Cell;
} struct_viMUS9ki6lFwfEmklEsm9G;

#endif

/* Parameters (default storage) */
typedef struct P_HEV_SeriesParallel_T_ P_HEV_SeriesParallel_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_HEV_SeriesParallel_T RT_MODEL_HEV_SeriesParallel_T;

#endif                                 /* HEV_SeriesParallel_types_h_ */
