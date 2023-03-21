/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tilt_tele_switch_func_ROM.c
 *
 * Code generated for Simulink model 'Tilt_Telescopic_Switch'.
 *
 * Model version                  : 1.46
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Mar 21 15:30:45 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tilt_tele_switch_func.h"
#include "rtwtypes.h"
#include "Tilt_Telescopic_Switch_types.h"

/* Exported data definition */

/* ConstVolatile memory section */
/* Definition for custom storage class: ConstVolatile */
const volatile uint8_T k_switchdebounce_time = 50U;/* Referenced by:
                                                    * '<S6>/Constant2'
                                                    * '<S7>/Constant5'
                                                    * '<S8>/Constant5'
                                                    * '<S13>/Constant2'
                                                    */
const volatile uint8_T k_switchrelease_time = 100U;/* Referenced by:
                                                    * '<S6>/Constant'
                                                    * '<S7>/Constant3'
                                                    * '<S8>/Constant3'
                                                    * '<S13>/Constant'
                                                    */
const volatile uint8_T k_switchstuck_time = 120U;/* Referenced by:
                                                  * '<S6>/Constant1'
                                                  * '<S7>/Constant4'
                                                  * '<S8>/Constant4'
                                                  * '<S13>/Constant1'
                                                  */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
