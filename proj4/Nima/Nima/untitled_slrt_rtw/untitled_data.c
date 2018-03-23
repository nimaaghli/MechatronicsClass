/*
 * untitled_data.c
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Sun Nov 26 18:06:45 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "untitled.h"
#include "untitled_private.h"

/* Block parameters (auto storage) */
P_untitled_T untitled_P = {
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  31.415926535897931,                  /* Computed Parameter: SignalGenerator_Frequency
                                        * Referenced by: '<Root>/Signal Generator'
                                        */

  /*  Computed Parameter: PCI6024EDA_P1_Size
   * Referenced by: '<Root>/PCI-6024E DA'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6024E DA'
                                        */

  /*  Computed Parameter: PCI6024EDA_P2_Size
   * Referenced by: '<Root>/PCI-6024E DA'
   */
  { 1.0, 1.0 },
  -10.0,                               /* Expression: range
                                        * Referenced by: '<Root>/PCI-6024E DA'
                                        */

  /*  Computed Parameter: PCI6024EDA_P3_Size
   * Referenced by: '<Root>/PCI-6024E DA'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6024E DA'
                                        */

  /*  Computed Parameter: PCI6024EDA_P4_Size
   * Referenced by: '<Root>/PCI-6024E DA'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6024E DA'
                                        */

  /*  Computed Parameter: PCI6024EDA_P5_Size
   * Referenced by: '<Root>/PCI-6024E DA'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6024E DA'
                                        */

  /*  Computed Parameter: PCI6024EDA_P6_Size
   * Referenced by: '<Root>/PCI-6024E DA'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6024E DA'
                                        */

  /*  Computed Parameter: PCI6024EDA_P7_Size
   * Referenced by: '<Root>/PCI-6024E DA'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6024E DA'
                                        */

  /*  Computed Parameter: PCI6024EAD_P1_Size
   * Referenced by: '<Root>/PCI-6024E AD'
   */
  { 1.0, 1.0 },
  9.0,                                 /* Expression: channel
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
  0.006,                               /* Expression: sampletime
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete FIR Filter'
                                        */

  /*  Expression: [0.5 0.5]
   * Referenced by: '<Root>/Discrete FIR Filter'
   */
  { 0.5, 0.5 }
};
