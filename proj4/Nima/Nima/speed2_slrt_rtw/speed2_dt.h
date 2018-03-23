/*
 * speed2_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&speed2_B.PulseGenerator), 0, 0, 25 },

  { (char_T *)(&speed2_B.Memory1), 8, 0, 9 },

  { (char_T *)(&speed2_B.SampleandHold2.In), 0, 0, 1 },

  { (char_T *)(&speed2_B.SampleandHold1.In), 0, 0, 1 }
  ,

  { (char_T *)(&speed2_DW.TmpLatchAtSampleandHold1Inport1), 0, 0, 67 },

  { (char_T *)(&speed2_DW.Scope_PWORK.LoggedData), 11, 0, 4 },

  { (char_T *)(&speed2_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&speed2_DW.Counter2_Count), 7, 0, 8 },

  { (char_T *)(&speed2_DW.PCI6024EDO_IWORK[0]), 10, 0, 79 },

  { (char_T *)(&speed2_DW.SampleandHold3_SubsysRanBC), 2, 0, 2 },

  { (char_T *)(&speed2_DW.Memory1_PreviousInput), 8, 0, 5 },

  { (char_T *)(&speed2_DW.SampleandHold2.SampleandHold1_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&speed2_DW.SampleandHold1.SampleandHold1_SubsysRanBC), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  13U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&speed2_P.Counter2_InitialCount), 7, 0, 3 },

  { (char_T *)(&speed2_P._Y0), 0, 0, 89 },

  { (char_T *)(&speed2_P.Q_Y0), 8, 0, 24 },

  { (char_T *)(&speed2_P.SampleandHold2._Y0), 0, 0, 1 },

  { (char_T *)(&speed2_P.SampleandHold1._Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] speed2_dt.h */
