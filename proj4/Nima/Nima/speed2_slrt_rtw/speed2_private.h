/*
 * speed2_private.h
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
#ifndef RTW_HEADER_speed2_private_h_
#define RTW_HEADER_speed2_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta);
extern uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta);
extern void donipcie(SimStruct *rts);
extern void dinipcie(SimStruct *rts);
extern void adnipcie(SimStruct *rts);
extern void speed2_SampleandHold1_Start(B_SampleandHold1_speed2_T *localB,
  P_SampleandHold1_speed2_T *localP);
extern void speed2_SampleandHold1(real_T rtu_Trigger, real_T rtu_In,
  B_SampleandHold1_speed2_T *localB, DW_SampleandHold1_speed2_T *localDW,
  ZCE_SampleandHold1_speed2_T *localZCE);
void speed2_output0(void);
void speed2_update0(void);
void speed2_output1(void);
void speed2_update1(void);

#endif                                 /* RTW_HEADER_speed2_private_h_ */
