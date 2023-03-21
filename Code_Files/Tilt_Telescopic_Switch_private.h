/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Tilt_Telescopic_Switch_private.h
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

#ifndef RTW_HEADER_Tilt_Telescopic_Switch_private_h_
#define RTW_HEADER_Tilt_Telescopic_Switch_private_h_
#include "rtwtypes.h"

/* Imported (extern) block signals */
extern uint8_T Input_Voltage;          /* '<Root>/Input_Voltage' */
extern boolean_T Tilt_Tele_Config_Param;/* '<Root>/Tilt_Tele_Config_Param' */
extern boolean_T Tilt_Up_Input;        /* '<Root>/Tilt_Up_Input' */
extern boolean_T Tilt_Down_Input;      /* '<Root>/Tilt_Down_Input' */
extern boolean_T Tele_Forward_Input;   /* '<Root>/Tele_Forward_Input' */
extern boolean_T Tele_Rearward_Input;  /* '<Root>/Tele_Rearward_Input' */

/* Imported (extern) states */
extern boolean_T Tilt_Down_Stuck_Switch;/* '<S6>/Data Store Memory' */
extern boolean_T Tele_Forward_Stuck_Switch;/* '<S7>/Data Store Memory' */
extern boolean_T Tele_Rearward_Stuck_Switch;/* '<S8>/Data Store Memory' */
extern boolean_T Tilt_Up_Stuck_Switch; /* '<S13>/Data Store Memory' */

#endif                        /* RTW_HEADER_Tilt_Telescopic_Switch_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
