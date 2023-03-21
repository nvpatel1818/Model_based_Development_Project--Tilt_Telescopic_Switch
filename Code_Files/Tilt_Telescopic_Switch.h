/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Tilt_Telescopic_Switch.h
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

#ifndef RTW_HEADER_Tilt_Telescopic_Switch_h_
#define RTW_HEADER_Tilt_Telescopic_Switch_h_
#ifndef Tilt_Telescopic_Switch_COMMON_INCLUDES_
#define Tilt_Telescopic_Switch_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                             /* Tilt_Telescopic_Switch_COMMON_INCLUDES_ */

#include "Tilt_Telescopic_Switch_types.h"
#include "enum_types.h"

/* Includes for objects with custom storage classes */
#include "tilt_tele_switch_func.h"

/* Block signals (default storage) */
typedef struct {
  boolean_T Up_Switch_Output;          /* '<S13>/Tilt_Up_Debounce_Logic' */
  boolean_T Switch_Stuck;              /* '<S13>/Tilt_Up_Debounce_Logic' */
  boolean_T Rearward_Switch_Output;    /* '<S8>/Tele_Rearward_Debounce_Logic' */
  boolean_T Switch_Stuck_j;            /* '<S8>/Tele_Rearward_Debounce_Logic' */
  boolean_T Forward_Switch_Output;     /* '<S7>/Tele_Forward_Debounce_Logic' */
  boolean_T Switch_Stuck_l;            /* '<S7>/Tele_Forward_Debounce_Logic' */
  boolean_T Down_Switch_Output;        /* '<S6>/Tilt_Down_Debounce_Logic' */
  boolean_T Switch_Stuck_i;            /* '<S6>/Tilt_Down_Debounce_Logic' */
} B_Tilt_Telescopic_Switch_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<S13>/Tilt_Up_Debounce_Logic' */
  uint32_T temporalCounter_i1_d;       /* '<S8>/Tele_Rearward_Debounce_Logic' */
  uint32_T temporalCounter_i1_g;       /* '<S7>/Tele_Forward_Debounce_Logic' */
  uint32_T temporalCounter_i1_p;       /* '<S6>/Tilt_Down_Debounce_Logic' */
  uint8_T is_active_c3_Tilt_Telescopic_Sw;/* '<S13>/Tilt_Up_Debounce_Logic' */
  uint8_T is_c3_Tilt_Telescopic_Switch;/* '<S13>/Tilt_Up_Debounce_Logic' */
  uint8_T is_Debounce;                 /* '<S13>/Tilt_Up_Debounce_Logic' */
  uint8_T is_active_c4_Tilt_Telescopic_Sw;/* '<S8>/Tele_Rearward_Debounce_Logic' */
  uint8_T is_c4_Tilt_Telescopic_Switch;/* '<S8>/Tele_Rearward_Debounce_Logic' */
  uint8_T is_Debounce_o;               /* '<S8>/Tele_Rearward_Debounce_Logic' */
  uint8_T is_active_c2_Tilt_Telescopic_Sw;/* '<S7>/Tele_Forward_Debounce_Logic' */
  uint8_T is_c2_Tilt_Telescopic_Switch;/* '<S7>/Tele_Forward_Debounce_Logic' */
  uint8_T is_Debounce_f;               /* '<S7>/Tele_Forward_Debounce_Logic' */
  uint8_T is_active_c1_Tilt_Telescopic_Sw;/* '<S6>/Tilt_Down_Debounce_Logic' */
  uint8_T is_c1_Tilt_Telescopic_Switch;/* '<S6>/Tilt_Down_Debounce_Logic' */
  uint8_T is_Debounce_a;               /* '<S6>/Tilt_Down_Debounce_Logic' */
} DW_Tilt_Telescopic_Switch_T;

/* Real-time Model Data Structure */
struct tag_RTM_Tilt_Telescopic_Switc_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_Tilt_Telescopic_Switch_T Tilt_Telescopic_Switch_B;

/* Block states (default storage) */
extern DW_Tilt_Telescopic_Switch_T Tilt_Telescopic_Switch_DW;

/* Model entry point functions */
extern void Tilt_Telescopic_Switch_initialize(void);
extern void Tilt_Telescopic_Switch_step(void);
extern void Tilt_Telescopic_Switch_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Tilt_Telescopic_Swit_T *const Tilt_Telescopic_Switch_M;

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
 * '<Root>' : 'Tilt_Telescopic_Switch'
 * '<S1>'   : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch'
 * '<S2>'   : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele'
 * '<S3>'   : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Valid_Voltage'
 * '<S4>'   : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination'
 * '<S5>'   : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/Tilt_Tele_Enabled_Condition'
 * '<S6>'   : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Down'
 * '<S7>'   : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Forward'
 * '<S8>'   : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Rearward'
 * '<S9>'   : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Tele_Forward_Status'
 * '<S10>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Tele_Rearward_Status'
 * '<S11>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Tilt_Down_Status'
 * '<S12>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Tilt_Up_Status'
 * '<S13>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Up'
 * '<S14>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Down/Tilt_Down_Debounce_Logic'
 * '<S15>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Forward/Tele_Forward_Debounce_Logic'
 * '<S16>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Rearward/Tele_Rearward_Debounce_Logic'
 * '<S17>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Tele_Forward_Status/Compare To Constant'
 * '<S18>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Tele_Rearward_Status/Compare To Constant'
 * '<S19>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Tilt_Down_Status/Compare To Constant'
 * '<S20>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Tilt_Up_Status/Compare To Constant'
 * '<S21>'  : 'Tilt_Telescopic_Switch/Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Up/Tilt_Up_Debounce_Logic'
 */
#endif                                /* RTW_HEADER_Tilt_Telescopic_Switch_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
