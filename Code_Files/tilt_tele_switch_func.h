/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tilt_tele_switch_func.h
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

#ifndef RTW_HEADER_tilt_tele_switch_func_h_
#define RTW_HEADER_tilt_tele_switch_func_h_
#include "enum_types.h"
#include "rtwtypes.h"
#include "Tilt_Telescopic_Switch_types.h"

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern TELE_INPUT Tele_Forward_Switch_Status;/* '<S9>/Switch' */
extern TELE_INPUT Tele_Rearward_Switch_Status;/* '<S10>/Switch' */
extern TILT_INPUT Tilt_Down_Switch_Status;/* '<S11>/Switch' */
extern TILT_INPUT Tilt_Up_Switch_Status;/* '<S12>/Switch' */

/* ConstVolatile memory section */
/* Declaration for custom storage class: ConstVolatile */
extern const volatile uint8_T k_switchdebounce_time;/* Referenced by:
                                                     * '<S6>/Constant2'
                                                     * '<S7>/Constant5'
                                                     * '<S8>/Constant5'
                                                     * '<S13>/Constant2'
                                                     */
extern const volatile uint8_T k_switchrelease_time;/* Referenced by:
                                                    * '<S6>/Constant'
                                                    * '<S7>/Constant3'
                                                    * '<S8>/Constant3'
                                                    * '<S13>/Constant'
                                                    */
extern const volatile uint8_T k_switchstuck_time;/* Referenced by:
                                                  * '<S6>/Constant1'
                                                  * '<S7>/Constant4'
                                                  * '<S8>/Constant4'
                                                  * '<S13>/Constant1'
                                                  */

#endif                                 /* RTW_HEADER_tilt_tele_switch_func_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
