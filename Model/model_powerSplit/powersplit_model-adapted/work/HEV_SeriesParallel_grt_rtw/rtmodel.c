/*
 *  rtmodel.c:
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

#include "rtmodel.h"

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void HEV_SeriesParallel_step(int_T tid)
{
  switch (tid) {
   case 0 :
    HEV_SeriesParallel_step0();
    break;

   case 2 :
    HEV_SeriesParallel_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}
