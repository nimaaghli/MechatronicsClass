/*
 * speed2_data.c
 *
 * Code generation for model "speed2".
 *
 * Model version              : 1.19
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Dec 05 01:50:08 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "speed2.h"
#include "speed2_private.h"

/* Block parameters (auto storage) */
P_speed2_T speed2_P = {
  0U,                                  /* Mask Parameter: Counter2_InitialCount
                                        * Referenced by: '<Root>/Counter2'
                                        */
  0U,                                  /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<Root>/Counter'
                                        */
  0U,                                  /* Mask Parameter: Counter1_InitialCount
                                        * Referenced by: '<Root>/Counter1'
                                        */
  2.0,                                 /* Expression: initCond
                                        * Referenced by: '<S6>/ '
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  100.0,                               /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  50.0,                                /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: synthesized block
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: synthesized block
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Uniform Random Number'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Uniform Random Number'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Uniform Random Number'
                                        */
  100.0,                               /* Expression: 1/0.01
                                        * Referenced by: '<Root>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */

  /*  Computed Parameter: PCI6024EDO_P1_Size
   * Referenced by: '<Root>/PCI-6024E DO'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */

  /*  Computed Parameter: PCI6024EDO_P2_Size
   * Referenced by: '<Root>/PCI-6024E DO'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */

  /*  Computed Parameter: PCI6024EDO_P3_Size
   * Referenced by: '<Root>/PCI-6024E DO'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */

  /*  Computed Parameter: PCI6024EDO_P4_Size
   * Referenced by: '<Root>/PCI-6024E DO'
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */

  /*  Computed Parameter: PCI6024EDO_P5_Size
   * Referenced by: '<Root>/PCI-6024E DO'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */

  /*  Computed Parameter: PCI6024EDO_P6_Size
   * Referenced by: '<Root>/PCI-6024E DO'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: control
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */

  /*  Computed Parameter: PCI6024EDO_P7_Size
   * Referenced by: '<Root>/PCI-6024E DO'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  100.0,                               /* Expression: 1/0.01
                                        * Referenced by: '<Root>/Gain'
                                        */
  24.0,                                /* Expression: 24
                                        * Referenced by: '<Root>/24 counts=1 rev1'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<Root>/1 rev=360 degree1'
                                        */
  21.3,                                /* Expression: 21.3
                                        * Referenced by: '<Root>/converstion factor 21.3:2'
                                        */

  /*  Computed Parameter: PCI6024EDI_P1_Size
   * Referenced by: '<Root>/PCI-6024E DI'
   */
  { 1.0, 1.0 },
  7.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */

  /*  Computed Parameter: PCI6024EDI_P2_Size
   * Referenced by: '<Root>/PCI-6024E DI'
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */

  /*  Computed Parameter: PCI6024EDI_P3_Size
   * Referenced by: '<Root>/PCI-6024E DI'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */

  /*  Computed Parameter: PCI6024EDI_P4_Size
   * Referenced by: '<Root>/PCI-6024E DI'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: control
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */

  /*  Computed Parameter: PCI6024EDI_P5_Size
   * Referenced by: '<Root>/PCI-6024E DI'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */

  /*  Computed Parameter: PCI6024EDI1_P1_Size
   * Referenced by: '<Root>/PCI-6024E DI1'
   */
  { 1.0, 1.0 },
  8.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */

  /*  Computed Parameter: PCI6024EDI1_P2_Size
   * Referenced by: '<Root>/PCI-6024E DI1'
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */

  /*  Computed Parameter: PCI6024EDI1_P3_Size
   * Referenced by: '<Root>/PCI-6024E DI1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */

  /*  Computed Parameter: PCI6024EDI1_P4_Size
   * Referenced by: '<Root>/PCI-6024E DI1'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: control
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */

  /*  Computed Parameter: PCI6024EDI1_P5_Size
   * Referenced by: '<Root>/PCI-6024E DI1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  24.0,                                /* Expression: 24
                                        * Referenced by: '<Root>/24 counts=1 rev'
                                        */
  360.0,                               /* Expression: 360
                                        * Referenced by: '<Root>/1 rev=360 degree'
                                        */
  21.3,                                /* Expression: 21.3
                                        * Referenced by: '<Root>/converstion factor 21.3:1'
                                        */

  /*  Computed Parameter: PCI6024EAD_P1_Size
   * Referenced by: '<Root>/PCI-6024E AD'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */

  /*  Computed Parameter: PCI6024EAD_P2_Size
   * Referenced by: '<Root>/PCI-6024E AD'
   */
  { 1.0, 1.0 },
  -10.0,                               /* Expression: range
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */

  /*  Computed Parameter: PCI6024EAD_P3_Size
   * Referenced by: '<Root>/PCI-6024E AD'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: coupling
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */

  /*  Computed Parameter: PCI6024EAD_P4_Size
   * Referenced by: '<Root>/PCI-6024E AD'
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */

  /*  Computed Parameter: PCI6024EAD_P5_Size
   * Referenced by: '<Root>/PCI-6024E AD'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */

  /*  Computed Parameter: PCI6024EAD_P6_Size
   * Referenced by: '<Root>/PCI-6024E AD'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  0,                                   /* Expression: initial_condition
                                        * Referenced by: '<S11>/Q'
                                        */
  1,                                   /* Expression: ~initial_condition
                                        * Referenced by: '<S11>/!Q'
                                        */
  0,                                   /* Expression: initial_condition
                                        * Referenced by: '<S11>/Memory'
                                        */

  /*  Computed Parameter: Logic_table
   * Referenced by: '<S11>/Logic'
   */
  { 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1 },
  0,                                   /* Computed Parameter: Memory1_X0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  0,                                   /* Computed Parameter: TmpLatchAtJKFlipFlopInport1_X0
                                        * Referenced by: synthesized block
                                        */
  0,                                   /* Computed Parameter: TmpLatchAtJKFlipFlopInport2_X0
                                        * Referenced by: synthesized block
                                        */
  0,                                   /* Computed Parameter: Memory_X0_c
                                        * Referenced by: '<Root>/Memory'
                                        */
  1,                                   /* Expression: true
                                        * Referenced by: '<Root>/Constant'
                                        */

  /* Start of '<Root>/Sample and Hold2' */
  {
    0.0                                /* Expression: initCond
                                        * Referenced by: '<S5>/ '
                                        */
  }
  /* End of '<Root>/Sample and Hold2' */
  ,

  /* Start of '<Root>/Sample and Hold1' */
  {
    0.0                                /* Expression: initCond
                                        * Referenced by: '<S4>/ '
                                        */
  }
  /* End of '<Root>/Sample and Hold1' */
};
