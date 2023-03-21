/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Tilt_Telescopic_Switch.c
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

#include "Tilt_Telescopic_Switch.h"
#include "rtwtypes.h"
#include "enum_types.h"
#include "Tilt_Telescopic_Switch_private.h"
#include "tilt_tele_switch_func.h"

/* Named constants for Chart: '<S6>/Tilt_Down_Debounce_Logic' */
#define Tilt_Telesco_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Tilt_Telescopic_IN_Off_Debounce ((uint8_T)1U)
#define Tilt_Telescopic_S_IN_Stuck_Wait ((uint8_T)6U)
#define Tilt_Telescopic_Swi_IN_Debounce ((uint8_T)1U)
#define Tilt_Telescopic_Swit_IN_Pressed ((uint8_T)4U)
#define Tilt_Telescopic_Switch_IN_Off  ((uint8_T)3U)
#define Tilt_Telescopic_Switch_IN_Stuck ((uint8_T)5U)
#define Tilt_Telescopic__IN_Not_Pressed ((uint8_T)2U)
#define Tilt_Telescopic__IN_On_Debounce ((uint8_T)2U)

/* Exported data definition */

/* Definition for custom storage class: Localizable */
static TELE_INPUT Tele_Forward_Switch_Status_Delay;/* '<S9>/Unit Delay' */
static TELE_INPUT Tele_Rearward_Switch_Status_Delay;/* '<S10>/Unit Delay' */
static TILT_INPUT Tilt_Down_Switch_Status_Delay;/* '<S11>/Unit Delay' */
static TILT_INPUT Tilt_Up_Switch_Status_Delay;/* '<S12>/Unit Delay' */

/* Block signals (default storage) */
B_Tilt_Telescopic_Switch_T Tilt_Telescopic_Switch_B;

/* Block states (default storage) */
DW_Tilt_Telescopic_Switch_T Tilt_Telescopic_Switch_DW;

/* Real-time model */
static RT_MODEL_Tilt_Telescopic_Swit_T Tilt_Telescopic_Switch_M_;
RT_MODEL_Tilt_Telescopic_Swit_T *const Tilt_Telescopic_Switch_M =
  &Tilt_Telescopic_Switch_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Tilt_Telescopic_Switch_M->Timing.TaskCounters.TID[1])++;
  if ((Tilt_Telescopic_Switch_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [0.01s, 0.0s] */
    Tilt_Telescopic_Switch_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void Tilt_Telescopic_Switch_step(void)
{
  if (Tilt_Telescopic_Switch_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Enabled SubSystem: '<S2>/SwitchPos_Status_Determination' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Constant: '<S3>/VMax'
     *  Constant: '<S3>/VMin'
     *  Inport: '<Root>/Input_Voltage'
     *  Inport: '<Root>/Tilt_Tele_Config_Param'
     *  Logic: '<S3>/Logical Operator'
     *  RelationalOperator: '<S3>/Relational Operator'
     *  RelationalOperator: '<S3>/Relational Operator1'
     */
    if (((Input_Voltage >= 10.0) && (Input_Voltage <= 20.0)) &&
        Tilt_Tele_Config_Param) {
      int32_T tmp;

      /* Chart: '<S6>/Tilt_Down_Debounce_Logic' incorporates:
       *  Constant: '<S6>/Constant'
       *  Constant: '<S6>/Constant1'
       *  Constant: '<S6>/Constant2'
       *  DataStoreRead: '<S6>/Data Store Read'
       *  Inport: '<Root>/Tilt_Down_Input'
       */
      if (Tilt_Telescopic_Switch_DW.temporalCounter_i1_p < MAX_uint32_T) {
        Tilt_Telescopic_Switch_DW.temporalCounter_i1_p++;
      }

      /* Gateway: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Down/Tilt_Down_Debounce_Logic */
      /* During: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Down/Tilt_Down_Debounce_Logic */
      if (Tilt_Telescopic_Switch_DW.is_active_c1_Tilt_Telescopic_Sw == 0U) {
        /* Entry: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Down/Tilt_Down_Debounce_Logic */
        Tilt_Telescopic_Switch_DW.is_active_c1_Tilt_Telescopic_Sw = 1U;

        /* Entry Internal: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Down/Tilt_Down_Debounce_Logic */
        /* Transition: '<S14>:2' */
        Tilt_Telescopic_Switch_DW.is_c1_Tilt_Telescopic_Switch =
          Tilt_Telescopic__IN_Not_Pressed;

        /* Entry 'Not_Pressed': '<S14>:1' */
        Tilt_Telescopic_Switch_B.Down_Switch_Output = false;
      } else {
        switch (Tilt_Telescopic_Switch_DW.is_c1_Tilt_Telescopic_Switch) {
         case Tilt_Telescopic_Swi_IN_Debounce:
          /* During 'Debounce': '<S14>:3' */
          if ((Tilt_Telescopic_Switch_DW.is_Debounce_a !=
               Tilt_Telescopic_IN_Off_Debounce) &&
              (Tilt_Telescopic_Switch_DW.temporalCounter_i1_p >= ((uint32_T)
                (k_switchdebounce_time * 100)))) {
            /* During 'On_Debounce': '<S14>:4' */
            /* Transition: '<S14>:11' */
            Tilt_Telescopic_Switch_DW.is_Debounce_a =
              Tilt_Telesco_IN_NO_ACTIVE_CHILD;
            Tilt_Telescopic_Switch_DW.is_c1_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swit_IN_Pressed;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1_p = 0U;

            /* Entry 'Pressed': '<S14>:6' */
            Tilt_Telescopic_Switch_B.Down_Switch_Output = true;
          } else {
            /* During 'Off_Debounce': '<S14>:5' */
          }
          break;

         case Tilt_Telescopic__IN_Not_Pressed:
          Tilt_Telescopic_Switch_B.Down_Switch_Output = false;

          /* During 'Not_Pressed': '<S14>:1' */
          if ((!Tilt_Down_Stuck_Switch) && Tilt_Down_Input) {
            /* Transition: '<S14>:10' */
            Tilt_Telescopic_Switch_DW.is_c1_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swi_IN_Debounce;
            Tilt_Telescopic_Switch_DW.is_Debounce_a =
              Tilt_Telescopic__IN_On_Debounce;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1_p = 0U;
          }
          break;

         case Tilt_Telescopic_Switch_IN_Off:
          /* During 'Off': '<S14>:9' */
          if (Tilt_Telescopic_Switch_DW.temporalCounter_i1_p >= ((uint32_T)
               (k_switchrelease_time * 100))) {
            /* Transition: '<S14>:17' */
            Tilt_Telescopic_Switch_DW.is_c1_Tilt_Telescopic_Switch =
              Tilt_Telescopic__IN_Not_Pressed;

            /* Entry 'Not_Pressed': '<S14>:1' */
            Tilt_Telescopic_Switch_B.Down_Switch_Output = false;
          }
          break;

         case Tilt_Telescopic_Swit_IN_Pressed:
          Tilt_Telescopic_Switch_B.Down_Switch_Output = true;

          /* During 'Pressed': '<S14>:6' */
          tmp = (k_switchstuck_time - k_switchdebounce_time) * 100;
          if (tmp < 0) {
            tmp = 0;
          }

          if (Tilt_Telescopic_Switch_DW.temporalCounter_i1_p >= ((uint32_T)tmp))
          {
            /* Transition: '<S14>:18' */
            Tilt_Telescopic_Switch_DW.is_c1_Tilt_Telescopic_Switch =
              Tilt_Telescopic_S_IN_Stuck_Wait;
          } else {
            /* Transition: '<S14>:19' */
            Tilt_Telescopic_Switch_DW.is_c1_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swi_IN_Debounce;
            Tilt_Telescopic_Switch_DW.is_Debounce_a =
              Tilt_Telescopic_IN_Off_Debounce;
          }
          break;

         case Tilt_Telescopic_Switch_IN_Stuck:
          Tilt_Telescopic_Switch_B.Down_Switch_Output = false;
          Tilt_Telescopic_Switch_B.Switch_Stuck_i = true;

          /* During 'Stuck': '<S14>:8' */
          if (!Tilt_Down_Input) {
            /* Transition: '<S14>:16' */
            Tilt_Telescopic_Switch_DW.is_c1_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Switch_IN_Off;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1_p = 0U;
          }
          break;

         default:
          /* During 'Stuck_Wait': '<S14>:7' */
          if (Tilt_Down_Input) {
            /* Transition: '<S14>:15' */
            Tilt_Telescopic_Switch_DW.is_c1_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Switch_IN_Stuck;

            /* Entry 'Stuck': '<S14>:8' */
            Tilt_Telescopic_Switch_B.Down_Switch_Output = false;
            Tilt_Telescopic_Switch_B.Switch_Stuck_i = true;
          }
          break;
        }
      }

      /* End of Chart: '<S6>/Tilt_Down_Debounce_Logic' */

      /* DataStoreWrite: '<S6>/Data Store Write' */
      Tilt_Down_Stuck_Switch = Tilt_Telescopic_Switch_B.Switch_Stuck_i;

      /* Chart: '<S7>/Tele_Forward_Debounce_Logic' incorporates:
       *  Constant: '<S7>/Constant3'
       *  Constant: '<S7>/Constant4'
       *  Constant: '<S7>/Constant5'
       *  DataStoreRead: '<S7>/Data Store Read'
       *  Inport: '<Root>/Tele_Forward_Input'
       */
      if (Tilt_Telescopic_Switch_DW.temporalCounter_i1_g < MAX_uint32_T) {
        Tilt_Telescopic_Switch_DW.temporalCounter_i1_g++;
      }

      /* Gateway: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Forward/Tele_Forward_Debounce_Logic */
      /* During: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Forward/Tele_Forward_Debounce_Logic */
      if (Tilt_Telescopic_Switch_DW.is_active_c2_Tilt_Telescopic_Sw == 0U) {
        /* Entry: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Forward/Tele_Forward_Debounce_Logic */
        Tilt_Telescopic_Switch_DW.is_active_c2_Tilt_Telescopic_Sw = 1U;

        /* Entry Internal: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Forward/Tele_Forward_Debounce_Logic */
        /* Transition: '<S15>:2' */
        Tilt_Telescopic_Switch_DW.is_c2_Tilt_Telescopic_Switch =
          Tilt_Telescopic__IN_Not_Pressed;

        /* Entry 'Not_Pressed': '<S15>:1' */
        Tilt_Telescopic_Switch_B.Forward_Switch_Output = false;
      } else {
        switch (Tilt_Telescopic_Switch_DW.is_c2_Tilt_Telescopic_Switch) {
         case Tilt_Telescopic_Swi_IN_Debounce:
          /* During 'Debounce': '<S15>:3' */
          if ((Tilt_Telescopic_Switch_DW.is_Debounce_f !=
               Tilt_Telescopic_IN_Off_Debounce) &&
              (Tilt_Telescopic_Switch_DW.temporalCounter_i1_g >= ((uint32_T)
                (k_switchdebounce_time * 100)))) {
            /* During 'On_Debounce': '<S15>:4' */
            /* Transition: '<S15>:11' */
            Tilt_Telescopic_Switch_DW.is_Debounce_f =
              Tilt_Telesco_IN_NO_ACTIVE_CHILD;
            Tilt_Telescopic_Switch_DW.is_c2_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swit_IN_Pressed;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1_g = 0U;

            /* Entry 'Pressed': '<S15>:6' */
            Tilt_Telescopic_Switch_B.Forward_Switch_Output = true;
          } else {
            /* During 'Off_Debounce': '<S15>:5' */
          }
          break;

         case Tilt_Telescopic__IN_Not_Pressed:
          Tilt_Telescopic_Switch_B.Forward_Switch_Output = false;

          /* During 'Not_Pressed': '<S15>:1' */
          if ((!Tele_Forward_Stuck_Switch) && Tele_Forward_Input) {
            /* Transition: '<S15>:10' */
            Tilt_Telescopic_Switch_DW.is_c2_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swi_IN_Debounce;
            Tilt_Telescopic_Switch_DW.is_Debounce_f =
              Tilt_Telescopic__IN_On_Debounce;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1_g = 0U;
          }
          break;

         case Tilt_Telescopic_Switch_IN_Off:
          /* During 'Off': '<S15>:9' */
          if (Tilt_Telescopic_Switch_DW.temporalCounter_i1_g >= ((uint32_T)
               (k_switchrelease_time * 100))) {
            /* Transition: '<S15>:17' */
            Tilt_Telescopic_Switch_DW.is_c2_Tilt_Telescopic_Switch =
              Tilt_Telescopic__IN_Not_Pressed;

            /* Entry 'Not_Pressed': '<S15>:1' */
            Tilt_Telescopic_Switch_B.Forward_Switch_Output = false;
          }
          break;

         case Tilt_Telescopic_Swit_IN_Pressed:
          Tilt_Telescopic_Switch_B.Forward_Switch_Output = true;

          /* During 'Pressed': '<S15>:6' */
          tmp = (k_switchstuck_time - k_switchdebounce_time) * 100;
          if (tmp < 0) {
            tmp = 0;
          }

          if (Tilt_Telescopic_Switch_DW.temporalCounter_i1_g >= ((uint32_T)tmp))
          {
            /* Transition: '<S15>:18' */
            Tilt_Telescopic_Switch_DW.is_c2_Tilt_Telescopic_Switch =
              Tilt_Telescopic_S_IN_Stuck_Wait;
          } else {
            /* Transition: '<S15>:19' */
            Tilt_Telescopic_Switch_DW.is_c2_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swi_IN_Debounce;
            Tilt_Telescopic_Switch_DW.is_Debounce_f =
              Tilt_Telescopic_IN_Off_Debounce;
          }
          break;

         case Tilt_Telescopic_Switch_IN_Stuck:
          Tilt_Telescopic_Switch_B.Forward_Switch_Output = false;
          Tilt_Telescopic_Switch_B.Switch_Stuck_l = true;

          /* During 'Stuck': '<S15>:8' */
          if (!Tele_Forward_Input) {
            /* Transition: '<S15>:16' */
            Tilt_Telescopic_Switch_DW.is_c2_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Switch_IN_Off;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1_g = 0U;
          }
          break;

         default:
          /* During 'Stuck_Wait': '<S15>:7' */
          if (Tele_Forward_Input) {
            /* Transition: '<S15>:15' */
            Tilt_Telescopic_Switch_DW.is_c2_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Switch_IN_Stuck;

            /* Entry 'Stuck': '<S15>:8' */
            Tilt_Telescopic_Switch_B.Forward_Switch_Output = false;
            Tilt_Telescopic_Switch_B.Switch_Stuck_l = true;
          }
          break;
        }
      }

      /* End of Chart: '<S7>/Tele_Forward_Debounce_Logic' */

      /* DataStoreWrite: '<S7>/Data Store Write' */
      Tele_Forward_Stuck_Switch = Tilt_Telescopic_Switch_B.Switch_Stuck_l;

      /* Chart: '<S8>/Tele_Rearward_Debounce_Logic' incorporates:
       *  Constant: '<S8>/Constant3'
       *  Constant: '<S8>/Constant4'
       *  Constant: '<S8>/Constant5'
       *  DataStoreRead: '<S8>/Data Store Read'
       *  Inport: '<Root>/Tele_Rearward_Input'
       */
      if (Tilt_Telescopic_Switch_DW.temporalCounter_i1_d < MAX_uint32_T) {
        Tilt_Telescopic_Switch_DW.temporalCounter_i1_d++;
      }

      /* Gateway: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Rearward/Tele_Rearward_Debounce_Logic */
      /* During: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Rearward/Tele_Rearward_Debounce_Logic */
      if (Tilt_Telescopic_Switch_DW.is_active_c4_Tilt_Telescopic_Sw == 0U) {
        /* Entry: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Rearward/Tele_Rearward_Debounce_Logic */
        Tilt_Telescopic_Switch_DW.is_active_c4_Tilt_Telescopic_Sw = 1U;

        /* Entry Internal: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Rearward/Tele_Rearward_Debounce_Logic */
        /* Transition: '<S16>:2' */
        Tilt_Telescopic_Switch_DW.is_c4_Tilt_Telescopic_Switch =
          Tilt_Telescopic__IN_Not_Pressed;

        /* Entry 'Not_Pressed': '<S16>:1' */
        Tilt_Telescopic_Switch_B.Rearward_Switch_Output = false;
      } else {
        switch (Tilt_Telescopic_Switch_DW.is_c4_Tilt_Telescopic_Switch) {
         case Tilt_Telescopic_Swi_IN_Debounce:
          /* During 'Debounce': '<S16>:3' */
          if ((Tilt_Telescopic_Switch_DW.is_Debounce_o !=
               Tilt_Telescopic_IN_Off_Debounce) &&
              (Tilt_Telescopic_Switch_DW.temporalCounter_i1_d >= ((uint32_T)
                (k_switchdebounce_time * 100)))) {
            /* During 'On_Debounce': '<S16>:4' */
            /* Transition: '<S16>:11' */
            Tilt_Telescopic_Switch_DW.is_Debounce_o =
              Tilt_Telesco_IN_NO_ACTIVE_CHILD;
            Tilt_Telescopic_Switch_DW.is_c4_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swit_IN_Pressed;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1_d = 0U;

            /* Entry 'Pressed': '<S16>:6' */
            Tilt_Telescopic_Switch_B.Rearward_Switch_Output = true;
          } else {
            /* During 'Off_Debounce': '<S16>:5' */
          }
          break;

         case Tilt_Telescopic__IN_Not_Pressed:
          Tilt_Telescopic_Switch_B.Rearward_Switch_Output = false;

          /* During 'Not_Pressed': '<S16>:1' */
          if ((!Tele_Rearward_Stuck_Switch) && Tele_Rearward_Input) {
            /* Transition: '<S16>:10' */
            Tilt_Telescopic_Switch_DW.is_c4_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swi_IN_Debounce;
            Tilt_Telescopic_Switch_DW.is_Debounce_o =
              Tilt_Telescopic__IN_On_Debounce;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1_d = 0U;
          }
          break;

         case Tilt_Telescopic_Switch_IN_Off:
          /* During 'Off': '<S16>:9' */
          if (Tilt_Telescopic_Switch_DW.temporalCounter_i1_d >= ((uint32_T)
               (k_switchrelease_time * 100))) {
            /* Transition: '<S16>:17' */
            Tilt_Telescopic_Switch_DW.is_c4_Tilt_Telescopic_Switch =
              Tilt_Telescopic__IN_Not_Pressed;

            /* Entry 'Not_Pressed': '<S16>:1' */
            Tilt_Telescopic_Switch_B.Rearward_Switch_Output = false;
          }
          break;

         case Tilt_Telescopic_Swit_IN_Pressed:
          Tilt_Telescopic_Switch_B.Rearward_Switch_Output = true;

          /* During 'Pressed': '<S16>:6' */
          tmp = (k_switchstuck_time - k_switchdebounce_time) * 100;
          if (tmp < 0) {
            tmp = 0;
          }

          if (Tilt_Telescopic_Switch_DW.temporalCounter_i1_d >= ((uint32_T)tmp))
          {
            /* Transition: '<S16>:18' */
            Tilt_Telescopic_Switch_DW.is_c4_Tilt_Telescopic_Switch =
              Tilt_Telescopic_S_IN_Stuck_Wait;
          } else {
            /* Transition: '<S16>:19' */
            Tilt_Telescopic_Switch_DW.is_c4_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swi_IN_Debounce;
            Tilt_Telescopic_Switch_DW.is_Debounce_o =
              Tilt_Telescopic_IN_Off_Debounce;
          }
          break;

         case Tilt_Telescopic_Switch_IN_Stuck:
          Tilt_Telescopic_Switch_B.Rearward_Switch_Output = false;
          Tilt_Telescopic_Switch_B.Switch_Stuck_j = true;

          /* During 'Stuck': '<S16>:8' */
          if (!Tele_Rearward_Input) {
            /* Transition: '<S16>:16' */
            Tilt_Telescopic_Switch_DW.is_c4_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Switch_IN_Off;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1_d = 0U;
          }
          break;

         default:
          /* During 'Stuck_Wait': '<S16>:7' */
          if (Tele_Rearward_Input) {
            /* Transition: '<S16>:15' */
            Tilt_Telescopic_Switch_DW.is_c4_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Switch_IN_Stuck;

            /* Entry 'Stuck': '<S16>:8' */
            Tilt_Telescopic_Switch_B.Rearward_Switch_Output = false;
            Tilt_Telescopic_Switch_B.Switch_Stuck_j = true;
          }
          break;
        }
      }

      /* End of Chart: '<S8>/Tele_Rearward_Debounce_Logic' */

      /* DataStoreWrite: '<S8>/Data Store Write' */
      Tele_Rearward_Stuck_Switch = Tilt_Telescopic_Switch_B.Switch_Stuck_j;

      /* Chart: '<S13>/Tilt_Up_Debounce_Logic' incorporates:
       *  Constant: '<S13>/Constant'
       *  Constant: '<S13>/Constant1'
       *  Constant: '<S13>/Constant2'
       *  DataStoreRead: '<S13>/Data Store Read'
       *  Inport: '<Root>/Tilt_Up_Input'
       */
      if (Tilt_Telescopic_Switch_DW.temporalCounter_i1 < MAX_uint32_T) {
        Tilt_Telescopic_Switch_DW.temporalCounter_i1++;
      }

      /* Gateway: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Up/Tilt_Up_Debounce_Logic */
      /* During: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Up/Tilt_Up_Debounce_Logic */
      if (Tilt_Telescopic_Switch_DW.is_active_c3_Tilt_Telescopic_Sw == 0U) {
        /* Entry: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Up/Tilt_Up_Debounce_Logic */
        Tilt_Telescopic_Switch_DW.is_active_c3_Tilt_Telescopic_Sw = 1U;

        /* Entry Internal: Tilt_Tele_Switch/Power_Tilt_Tele/SwitchPos_Status_Determination/Up/Tilt_Up_Debounce_Logic */
        /* Transition: '<S21>:2' */
        Tilt_Telescopic_Switch_DW.is_c3_Tilt_Telescopic_Switch =
          Tilt_Telescopic__IN_Not_Pressed;

        /* Entry 'Not_Pressed': '<S21>:1' */
        Tilt_Telescopic_Switch_B.Up_Switch_Output = false;
      } else {
        switch (Tilt_Telescopic_Switch_DW.is_c3_Tilt_Telescopic_Switch) {
         case Tilt_Telescopic_Swi_IN_Debounce:
          /* During 'Debounce': '<S21>:3' */
          if ((Tilt_Telescopic_Switch_DW.is_Debounce !=
               Tilt_Telescopic_IN_Off_Debounce) &&
              (Tilt_Telescopic_Switch_DW.temporalCounter_i1 >= ((uint32_T)
                (k_switchdebounce_time * 100)))) {
            /* During 'On_Debounce': '<S21>:4' */
            /* Transition: '<S21>:11' */
            Tilt_Telescopic_Switch_DW.is_Debounce =
              Tilt_Telesco_IN_NO_ACTIVE_CHILD;
            Tilt_Telescopic_Switch_DW.is_c3_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swit_IN_Pressed;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1 = 0U;

            /* Entry 'Pressed': '<S21>:6' */
            Tilt_Telescopic_Switch_B.Up_Switch_Output = true;
          } else {
            /* During 'Off_Debounce': '<S21>:5' */
          }
          break;

         case Tilt_Telescopic__IN_Not_Pressed:
          Tilt_Telescopic_Switch_B.Up_Switch_Output = false;

          /* During 'Not_Pressed': '<S21>:1' */
          if ((!Tilt_Up_Stuck_Switch) && Tilt_Up_Input) {
            /* Transition: '<S21>:10' */
            Tilt_Telescopic_Switch_DW.is_c3_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swi_IN_Debounce;
            Tilt_Telescopic_Switch_DW.is_Debounce =
              Tilt_Telescopic__IN_On_Debounce;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1 = 0U;
          }
          break;

         case Tilt_Telescopic_Switch_IN_Off:
          /* During 'Off': '<S21>:9' */
          if (Tilt_Telescopic_Switch_DW.temporalCounter_i1 >= ((uint32_T)
               (k_switchrelease_time * 100))) {
            /* Transition: '<S21>:17' */
            Tilt_Telescopic_Switch_DW.is_c3_Tilt_Telescopic_Switch =
              Tilt_Telescopic__IN_Not_Pressed;

            /* Entry 'Not_Pressed': '<S21>:1' */
            Tilt_Telescopic_Switch_B.Up_Switch_Output = false;
          }
          break;

         case Tilt_Telescopic_Swit_IN_Pressed:
          Tilt_Telescopic_Switch_B.Up_Switch_Output = true;

          /* During 'Pressed': '<S21>:6' */
          tmp = (k_switchstuck_time - k_switchdebounce_time) * 100;
          if (tmp < 0) {
            tmp = 0;
          }

          if (Tilt_Telescopic_Switch_DW.temporalCounter_i1 >= ((uint32_T)tmp)) {
            /* Transition: '<S21>:18' */
            Tilt_Telescopic_Switch_DW.is_c3_Tilt_Telescopic_Switch =
              Tilt_Telescopic_S_IN_Stuck_Wait;
          } else {
            /* Transition: '<S21>:19' */
            Tilt_Telescopic_Switch_DW.is_c3_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Swi_IN_Debounce;
            Tilt_Telescopic_Switch_DW.is_Debounce =
              Tilt_Telescopic_IN_Off_Debounce;
          }
          break;

         case Tilt_Telescopic_Switch_IN_Stuck:
          Tilt_Telescopic_Switch_B.Up_Switch_Output = false;
          Tilt_Telescopic_Switch_B.Switch_Stuck = true;

          /* During 'Stuck': '<S21>:8' */
          if (!Tilt_Up_Input) {
            /* Transition: '<S21>:16' */
            Tilt_Telescopic_Switch_DW.is_c3_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Switch_IN_Off;
            Tilt_Telescopic_Switch_DW.temporalCounter_i1 = 0U;
          }
          break;

         default:
          /* During 'Stuck_Wait': '<S21>:7' */
          if (Tilt_Up_Input) {
            /* Transition: '<S21>:15' */
            Tilt_Telescopic_Switch_DW.is_c3_Tilt_Telescopic_Switch =
              Tilt_Telescopic_Switch_IN_Stuck;

            /* Entry 'Stuck': '<S21>:8' */
            Tilt_Telescopic_Switch_B.Up_Switch_Output = false;
            Tilt_Telescopic_Switch_B.Switch_Stuck = true;
          }
          break;
        }
      }

      /* End of Chart: '<S13>/Tilt_Up_Debounce_Logic' */

      /* DataStoreWrite: '<S13>/Data Store Write' */
      Tilt_Up_Stuck_Switch = Tilt_Telescopic_Switch_B.Switch_Stuck;

      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S17>/Constant'
       *  RelationalOperator: '<S17>/Compare'
       *  Sum: '<S4>/Add'
       *  Switch: '<S10>/Switch'
       *  Switch: '<S11>/Switch'
       *  Switch: '<S12>/Switch'
       *  Switch: '<S9>/Switch1'
       */
      if (((int32_T)(((((uint32_T)Tilt_Telescopic_Switch_B.Up_Switch_Output) +
                       Tilt_Telescopic_Switch_B.Down_Switch_Output) +
                      Tilt_Telescopic_Switch_B.Forward_Switch_Output) +
                     Tilt_Telescopic_Switch_B.Rearward_Switch_Output)) >
          ((uint8_T)1U)) {
        /* Switch: '<S9>/Switch' incorporates:
         *  UnitDelay: '<S9>/Unit Delay'
         */
        Tele_Forward_Switch_Status = Tele_Forward_Switch_Status_Delay;

        /* Switch: '<S10>/Switch' incorporates:
         *  UnitDelay: '<S10>/Unit Delay'
         */
        Tele_Rearward_Switch_Status = Tele_Rearward_Switch_Status_Delay;

        /* Switch: '<S11>/Switch' incorporates:
         *  UnitDelay: '<S11>/Unit Delay'
         */
        Tilt_Down_Switch_Status = Tilt_Down_Switch_Status_Delay;

        /* Switch: '<S12>/Switch' incorporates:
         *  UnitDelay: '<S12>/Unit Delay'
         */
        Tilt_Up_Switch_Status = Tilt_Up_Switch_Status_Delay;
      } else {
        if (Tilt_Telescopic_Switch_B.Forward_Switch_Output) {
          /* Switch: '<S9>/Switch1' incorporates:
           *  Constant: '<S9>/Forward'
           *  Switch: '<S9>/Switch'
           */
          Tele_Forward_Switch_Status = TELE_Forward;
        } else {
          /* Switch: '<S9>/Switch' incorporates:
           *  Constant: '<S9>/Off'
           *  Switch: '<S9>/Switch1'
           */
          Tele_Forward_Switch_Status = TELE_Off;
        }

        /* Switch: '<S10>/Switch1' */
        if (Tilt_Telescopic_Switch_B.Rearward_Switch_Output) {
          /* Switch: '<S10>/Switch' incorporates:
           *  Constant: '<S10>/Rearward'
           */
          Tele_Rearward_Switch_Status = TELE_Rearward;
        } else {
          /* Switch: '<S10>/Switch' incorporates:
           *  Constant: '<S10>/Off'
           */
          Tele_Rearward_Switch_Status = TELE_Off;
        }

        /* End of Switch: '<S10>/Switch1' */

        /* Switch: '<S11>/Switch1' */
        if (Tilt_Telescopic_Switch_B.Down_Switch_Output) {
          /* Switch: '<S11>/Switch' incorporates:
           *  Constant: '<S11>/Down'
           */
          Tilt_Down_Switch_Status = TILT_Down;
        } else {
          /* Switch: '<S11>/Switch' incorporates:
           *  Constant: '<S11>/Off'
           */
          Tilt_Down_Switch_Status = TILT_Off;
        }

        /* End of Switch: '<S11>/Switch1' */

        /* Switch: '<S12>/Switch1' */
        if (Tilt_Telescopic_Switch_B.Up_Switch_Output) {
          /* Switch: '<S12>/Switch' incorporates:
           *  Constant: '<S12>/Up'
           */
          Tilt_Up_Switch_Status = TILT_Up;
        } else {
          /* Switch: '<S12>/Switch' incorporates:
           *  Constant: '<S12>/Off'
           */
          Tilt_Up_Switch_Status = TILT_Off;
        }

        /* End of Switch: '<S12>/Switch1' */
      }

      /* End of Switch: '<S9>/Switch' */

      /* Update for UnitDelay: '<S9>/Unit Delay' */
      Tele_Forward_Switch_Status_Delay = Tele_Forward_Switch_Status;

      /* Update for UnitDelay: '<S10>/Unit Delay' */
      Tele_Rearward_Switch_Status_Delay = Tele_Rearward_Switch_Status;

      /* Update for UnitDelay: '<S11>/Unit Delay' */
      Tilt_Down_Switch_Status_Delay = Tilt_Down_Switch_Status;

      /* Update for UnitDelay: '<S12>/Unit Delay' */
      Tilt_Up_Switch_Status_Delay = Tilt_Up_Switch_Status;
    }

    /* End of Logic: '<S5>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S2>/SwitchPos_Status_Determination' */
  }

  rate_scheduler();
}

/* Model initialize function */
void Tilt_Telescopic_Switch_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  Tilt_Down_Switch_Status = TILT_Up;
  Tilt_Up_Switch_Status = TILT_Up;
  Tele_Forward_Switch_Status = TELE_Forward;
  Tele_Rearward_Switch_Status = TELE_Forward;

  /* states (dwork) */

  /* custom states */
  Tele_Forward_Switch_Status_Delay = TELE_Forward;
  Tele_Rearward_Switch_Status_Delay = TELE_Forward;
  Tilt_Down_Switch_Status_Delay = TILT_Up;
  Tilt_Up_Switch_Status_Delay = TILT_Up;

  /* SystemInitialize for Enabled SubSystem: '<S2>/SwitchPos_Status_Determination' */
  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  Tele_Forward_Switch_Status_Delay = TELE_Off;

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
  Tele_Rearward_Switch_Status_Delay = TELE_Off;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  Tilt_Down_Switch_Status_Delay = TILT_Off;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
  Tilt_Up_Switch_Status_Delay = TILT_Off;

  /* End of SystemInitialize for SubSystem: '<S2>/SwitchPos_Status_Determination' */
}

/* Model terminate function */
void Tilt_Telescopic_Switch_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
