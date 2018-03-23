/*
 * speed2.c
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
#include "rt_logging_mmi.h"
#include "speed2_capi.h"
#include "speed2.h"
#include "speed2_private.h"
#include "speed2_dt.h"

/* Block signals (auto storage) */
B_speed2_T speed2_B;

/* Block states (auto storage) */
DW_speed2_T speed2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_speed2_T speed2_PrevZCX;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_speed2_T speed2_Y;

/* Real-time model */
RT_MODEL_speed2_T speed2_M_;
RT_MODEL_speed2_T *const speed2_M = &speed2_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(speed2_M, 1);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (speed2_M->Timing.TaskCounters.TID[1])++;
  if ((speed2_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    speed2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Start for trigger system:
 *    '<Root>/Sample and Hold1'
 *    '<Root>/Sample and Hold2'
 */
void speed2_SampleandHold1_Start(B_SampleandHold1_speed2_T *localB,
  P_SampleandHold1_speed2_T *localP)
{
  /* VirtualOutportStart for Outport: '<S4>/ ' */
  localB->In = localP->_Y0;
}

/*
 * Output and update for trigger system:
 *    '<Root>/Sample and Hold1'
 *    '<Root>/Sample and Hold2'
 */
void speed2_SampleandHold1(real_T rtu_Trigger, real_T rtu_In,
  B_SampleandHold1_speed2_T *localB, DW_SampleandHold1_speed2_T *localDW,
  ZCE_SampleandHold1_speed2_T *localZCE)
{
  ZCEventType zcEvent;

  /* Outputs for Triggered SubSystem: '<Root>/Sample and Hold1' incorporates:
   *  TriggerPort: '<S4>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->SampleandHold1_Trig_ZCE,
                     (rtu_Trigger));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S4>/In' */
    localB->In = rtu_In;
    localDW->SampleandHold1_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<Root>/Sample and Hold1' */
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspcount2): '<Root>/Counter2' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (previousState == 5U) {
    newStateR = curState;
  } else {
    if ((uint32_T)curState != previousState) {
      if (previousState == 3U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 2;
          previousState = 1U;
        }
      }

      if (previousState == 4U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 3;
          previousState = 1U;
        }
      }

      if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
        retVal = 2U;
      }

      if (previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == (uint32_T)lastzcevent) {
        retVal = 0U;
      }

      if (((uint32_T)curState == 1U) && (retVal == 2U)) {
        newState = 3;
      } else {
        newState = curState;
      }
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<Root>/Counter2' */
  return retVal;
}

uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspcount2): '<Root>/Counter2' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0.0) {
    curState = 2;
  } else if (evt < 0.0) {
    curState = 0;
  } else {
    curState = 1;
  }

  if (previousState == 5U) {
    newStateR = curState;
  } else {
    if ((uint32_T)curState != previousState) {
      if (previousState == 3U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 2;
          previousState = 1U;
        }
      }

      if (previousState == 4U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 3;
          previousState = 1U;
        }
      }

      if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
        retVal = 2U;
      }

      if (previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == (uint32_T)lastzcevent) {
        retVal = 0U;
      }

      if (((uint32_T)curState == 1U) && (retVal == 2U)) {
        newState = 3;
      } else {
        newState = curState;
      }
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<Root>/Counter2' */
  return retVal;
}

/* Model output function for TID0 */
void speed2_output0(void)              /* Sample time: [0.0001s, 0.0s] */
{
  int32_T rowIdx;
  boolean_T zcEvent;

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(speed2_DW.JKFlipFlop_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(speed2_DW.SampleandHold1.SampleandHold1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(speed2_DW.SampleandHold3_SubsysRanBC);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  speed2_B.PulseGenerator = (speed2_DW.clockTickCounter <
    speed2_P.PulseGenerator_Duty) && (speed2_DW.clockTickCounter >= 0) ?
    speed2_P.PulseGenerator_Amp : 0.0;
  if (speed2_DW.clockTickCounter >= speed2_P.PulseGenerator_Period - 1.0) {
    speed2_DW.clockTickCounter = 0;
  } else {
    speed2_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Memory: '<Root>/Memory1' */
  speed2_B.Memory1 = speed2_DW.Memory1_PreviousInput;

  /* S-Function (sdspcount2): '<Root>/Counter2' */
  if (MWDSP_EPH_R_B(speed2_B.Memory1, &speed2_DW.Counter2_RstEphState) != 0U) {
    speed2_DW.Counter2_Count = speed2_P.Counter2_InitialCount;
  }

  if (MWDSP_EPH_R_D(speed2_B.PulseGenerator, &speed2_DW.Counter2_ClkEphState) !=
      0U) {
    if (speed2_DW.Counter2_Count < 100000000U) {
      speed2_DW.Counter2_Count++;
    } else {
      speed2_DW.Counter2_Count = 0U;
    }
  }

  speed2_B.Counter2 = speed2_DW.Counter2_Count;

  /* End of S-Function (sdspcount2): '<Root>/Counter2' */

  /* Outport: '<Root>/Out1' */
  speed2_Y.Out1 = speed2_B.Counter2;

  /* Memory: '<Root>/TmpLatchAtSample and Hold1Inport1' */
  speed2_B.TmpLatchAtSampleandHold1Inport1 =
    speed2_DW.TmpLatchAtSampleandHold1Inport1;

  /* Outputs for Triggered SubSystem: '<Root>/Sample and Hold1' */
  speed2_SampleandHold1(speed2_B.PulseGenerator,
                        speed2_B.TmpLatchAtSampleandHold1Inport1,
                        &speed2_B.SampleandHold1, &speed2_DW.SampleandHold1,
                        &speed2_PrevZCX.SampleandHold1);

  /* End of Outputs for SubSystem: '<Root>/Sample and Hold1' */

  /* Memory: '<Root>/TmpLatchAtSample and Hold2Inport1' */
  speed2_B.TmpLatchAtSampleandHold2Inport1 =
    speed2_DW.TmpLatchAtSampleandHold2Inport1;

  /* Outputs for Triggered SubSystem: '<Root>/Sample and Hold2' */
  speed2_SampleandHold1(speed2_B.PulseGenerator,
                        speed2_B.TmpLatchAtSampleandHold2Inport1,
                        &speed2_B.SampleandHold2, &speed2_DW.SampleandHold2,
                        &speed2_PrevZCX.SampleandHold2);

  /* End of Outputs for SubSystem: '<Root>/Sample and Hold2' */

  /* Sum: '<Root>/Subtract' */
  speed2_B.Subtract = speed2_B.SampleandHold1.In - speed2_B.SampleandHold2.In;

  /* Memory: '<S3>/TmpLatchAtJ-K Flip-FlopInport1' */
  speed2_B.TmpLatchAtJKFlipFlopInport1 =
    speed2_DW.TmpLatchAtJKFlipFlopInport1_Pre;

  /* Memory: '<S3>/TmpLatchAtJ-K Flip-FlopInport2' */
  speed2_B.TmpLatchAtJKFlipFlopInport2 =
    speed2_DW.TmpLatchAtJKFlipFlopInport2_Pre;

  /* UniformRandomNumber: '<Root>/Uniform Random Number' */
  speed2_B.UniformRandomNumber = speed2_DW.UniformRandomNumber_NextOutput;

  /* Memory: '<Root>/Memory' */
  speed2_B.Memory = speed2_DW.Memory_PreviousInput;

  /* Outputs for Triggered SubSystem: '<Root>/Sample and Hold3' incorporates:
   *  TriggerPort: '<S6>/Trigger'
   */
  zcEvent = (speed2_B.Memory && (speed2_PrevZCX.SampleandHold3_Trig_ZCE !=
              POS_ZCSIG));
  if (zcEvent) {
    /* Inport: '<S6>/In' */
    speed2_B.In = speed2_B.UniformRandomNumber;
    speed2_DW.SampleandHold3_SubsysRanBC = 4;
  }

  speed2_PrevZCX.SampleandHold3_Trig_ZCE = (uint8_T)(speed2_B.Memory ? (int32_T)
    POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<Root>/Sample and Hold3' */

  /* Gain: '<Root>/Gain2' */
  speed2_B.Gain2 = speed2_P.Gain2_Gain * speed2_B.In;

  /* Sum: '<Root>/Subtract1' */
  speed2_B.Subtract1 = speed2_B.Gain2 - speed2_B.Counter2;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  speed2_B.Compare = (speed2_B.Subtract1 <= speed2_P.Constant_Value);

  /* Outputs for Triggered SubSystem: '<S3>/J-K Flip-Flop' incorporates:
   *  TriggerPort: '<S11>/Trigger'
   */
  zcEvent = ((!speed2_B.Compare) && (speed2_PrevZCX.JKFlipFlop_Trig_ZCE !=
              ZERO_ZCSIG));
  if (zcEvent) {
    /* Memory: '<S11>/Memory' */
    speed2_B.Memory_c = speed2_DW.Memory_PreviousInput_j;

    /* CombinatorialLogic: '<S11>/Logic' */
    zcEvent = speed2_B.Memory_c;
    rowIdx = zcEvent;
    zcEvent = speed2_B.TmpLatchAtJKFlipFlopInport1;
    rowIdx = (int32_T)(((uint32_T)rowIdx << 1) + zcEvent);
    zcEvent = speed2_B.TmpLatchAtJKFlipFlopInport2;
    rowIdx = (int32_T)(((uint32_T)rowIdx << 1) + zcEvent);
    speed2_B.Logic[0U] = speed2_P.Logic_table[(uint32_T)rowIdx];
    speed2_B.Logic[1U] = speed2_P.Logic_table[rowIdx + 8U];

    /* SignalConversion: '<S11>/OutportBufferFor!Q' */
    speed2_B.OutportBufferForQ = speed2_B.Logic[1];

    /* Update for Memory: '<S11>/Memory' */
    speed2_DW.Memory_PreviousInput_j = speed2_B.Logic[0];
    speed2_DW.JKFlipFlop_SubsysRanBC = 4;
  }

  speed2_PrevZCX.JKFlipFlop_Trig_ZCE = (uint8_T)(speed2_B.Compare ? (int32_T)
    POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S3>/J-K Flip-Flop' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  speed2_B.DataTypeConversion = speed2_B.Logic[0];

  /* Level2 S-Function Block: '<Root>/PCI-6024E DO' (donipcie) */
  {
    SimStruct *rts = speed2_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<Root>/Gain' */
  speed2_B.Gain = speed2_P.Gain_Gain * speed2_B.Subtract;

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/24 counts=1 rev1'
   */
  speed2_B.Divide2 = speed2_B.Gain / speed2_P.ucounts1rev1_Value;

  /* Product: '<Root>/multply1' incorporates:
   *  Constant: '<Root>/1 rev=360 degree1'
   */
  speed2_B.multply1 = speed2_B.Divide2 * speed2_P.rev360degree1_Value;

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/converstion factor 21.3:2'
   */
  speed2_B.Divide3 = speed2_B.multply1 / speed2_P.converstionfactor2132_Value;

  /* ok to acquire for <S7>/S-Function */
  speed2_DW.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S8>/S-Function */
  speed2_DW.SFunction_IWORK_i.AcquireOK = 1;

  /* ok to acquire for <S9>/S-Function */
  speed2_DW.SFunction_IWORK_o.AcquireOK = 1;

  /* Level2 S-Function Block: '<Root>/PCI-6024E DI' (dinipcie) */
  {
    SimStruct *rts = speed2_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* S-Function (sdspcount2): '<Root>/Counter' */
  if (MWDSP_EPH_R_D(speed2_B.PCI6024EDI, &speed2_DW.Counter_ClkEphState) != 0U)
  {
    if (speed2_DW.Counter_Count < 10000000U) {
      speed2_DW.Counter_Count++;
    } else {
      speed2_DW.Counter_Count = 0U;
    }
  }

  speed2_B.Counter = speed2_DW.Counter_Count;

  /* End of S-Function (sdspcount2): '<Root>/Counter' */

  /* Level2 S-Function Block: '<Root>/PCI-6024E DI1' (dinipcie) */
  {
    SimStruct *rts = speed2_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* S-Function (sdspcount2): '<Root>/Counter1' */
  if (MWDSP_EPH_R_D(speed2_B.PCI6024EDI1, &speed2_DW.Counter1_ClkEphState) != 0U)
  {
    if (speed2_DW.Counter1_Count < 10000000U) {
      speed2_DW.Counter1_Count++;
    } else {
      speed2_DW.Counter1_Count = 0U;
    }
  }

  speed2_B.Counter1 = speed2_DW.Counter1_Count;

  /* End of S-Function (sdspcount2): '<Root>/Counter1' */

  /* Sum: '<Root>/Sum' */
  speed2_B.Sum = speed2_B.Counter + speed2_B.Counter1;

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/24 counts=1 rev'
   */
  speed2_B.Divide = speed2_B.Sum / speed2_P.ucounts1rev_Value;

  /* Product: '<Root>/multply' incorporates:
   *  Constant: '<Root>/1 rev=360 degree'
   */
  speed2_B.multply = speed2_B.Divide * speed2_P.rev360degree_Value;

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/converstion factor 21.3:1'
   */
  speed2_B.Divide1 = speed2_B.multply / speed2_P.converstionfactor2131_Value;

  /* Level2 S-Function Block: '<Root>/PCI-6024E AD' (adnipcie) */
  {
    SimStruct *rts = speed2_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function for TID0 */
void speed2_update0(void)              /* Sample time: [0.0001s, 0.0s] */
{
  real_T tmin;

  /* Update for Memory: '<Root>/Memory1' */
  speed2_DW.Memory1_PreviousInput = speed2_B.Compare;

  /* Update for Memory: '<Root>/TmpLatchAtSample and Hold1Inport1' */
  speed2_DW.TmpLatchAtSampleandHold1Inport1 = speed2_B.Sum;

  /* Update for Memory: '<Root>/TmpLatchAtSample and Hold2Inport1' */
  speed2_DW.TmpLatchAtSampleandHold2Inport1 = speed2_B.SampleandHold1.In;

  /* Update for Memory: '<S3>/TmpLatchAtJ-K Flip-FlopInport1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  speed2_DW.TmpLatchAtJKFlipFlopInport1_Pre = speed2_P.Constant_Value_m;

  /* Update for Memory: '<S3>/TmpLatchAtJ-K Flip-FlopInport2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  speed2_DW.TmpLatchAtJKFlipFlopInport2_Pre = speed2_P.Constant_Value_m;

  /* Update for UniformRandomNumber: '<Root>/Uniform Random Number' */
  tmin = speed2_P.UniformRandomNumber_Minimum;
  speed2_DW.UniformRandomNumber_NextOutput =
    (speed2_P.UniformRandomNumber_Maximum - tmin) * rt_urand_Upu32_Yd_f_pw_snf
    (&speed2_DW.RandSeed) + tmin;

  /* Update for Memory: '<Root>/Memory' */
  speed2_DW.Memory_PreviousInput = speed2_B.Compare;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++speed2_M->Timing.clockTick0)) {
    ++speed2_M->Timing.clockTickH0;
  }

  speed2_M->Timing.t[0] = speed2_M->Timing.clockTick0 *
    speed2_M->Timing.stepSize0 + speed2_M->Timing.clockTickH0 *
    speed2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model output function for TID1 */
void speed2_output1(void)              /* Sample time: [0.001s, 0.0s] */
{
  /* RateTransition: '<S1>/Rate Transition' */
  speed2_B.RateTransition = speed2_B.PCI6024EAD;

  /* Gain: '<Root>/Gain1' */
  speed2_B.Gain1 = speed2_P.Gain1_Gain * speed2_B.RateTransition;

  /* ok to acquire for <S10>/S-Function */
  speed2_DW.SFunction_IWORK_c.AcquireOK = 1;
}

/* Model update function for TID1 */
void speed2_update1(void)              /* Sample time: [0.001s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++speed2_M->Timing.clockTick1)) {
    ++speed2_M->Timing.clockTickH1;
  }

  speed2_M->Timing.t[1] = speed2_M->Timing.clockTick1 *
    speed2_M->Timing.stepSize1 + speed2_M->Timing.clockTickH1 *
    speed2_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void speed2_output(int_T tid)
{
  switch (tid) {
   case 0 :
    speed2_output0();
    break;

   case 1 :
    speed2_output1();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void speed2_update(int_T tid)
{
  switch (tid) {
   case 0 :
    speed2_update0();
    break;

   case 1 :
    speed2_update1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void speed2_initialize(void)
{
  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmin;

    /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
    speed2_DW.clockTickCounter = 0;

    /* Start for Triggered SubSystem: '<Root>/Sample and Hold1' */
    speed2_SampleandHold1_Start(&speed2_B.SampleandHold1,
      (P_SampleandHold1_speed2_T *)&speed2_P.SampleandHold1);

    /* End of Start for SubSystem: '<Root>/Sample and Hold1' */

    /* Start for Triggered SubSystem: '<Root>/Sample and Hold2' */
    speed2_SampleandHold1_Start(&speed2_B.SampleandHold2,
      (P_SampleandHold1_speed2_T *)&speed2_P.SampleandHold2);

    /* End of Start for SubSystem: '<Root>/Sample and Hold2' */

    /* Start for UniformRandomNumber: '<Root>/Uniform Random Number' */
    tmin = floor(speed2_P.UniformRandomNumber_Seed);
    if (rtIsNaN(tmin) || rtIsInf(tmin)) {
      tmin = 0.0;
    } else {
      tmin = fmod(tmin, 4.294967296E+9);
    }

    tseed = tmin < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmin : (uint32_T)tmin;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    speed2_DW.RandSeed = tseed;
    tmin = speed2_P.UniformRandomNumber_Minimum;
    speed2_DW.UniformRandomNumber_NextOutput =
      (speed2_P.UniformRandomNumber_Maximum - tmin) * rt_urand_Upu32_Yd_f_pw_snf
      (&speed2_DW.RandSeed) + tmin;

    /* End of Start for UniformRandomNumber: '<Root>/Uniform Random Number' */

    /* Start for Triggered SubSystem: '<Root>/Sample and Hold3' */
    /* VirtualOutportStart for Outport: '<S6>/ ' */
    speed2_B.In = speed2_P._Y0;

    /* End of Start for SubSystem: '<Root>/Sample and Hold3' */

    /* Start for Triggered SubSystem: '<S3>/J-K Flip-Flop' */
    /* VirtualOutportStart for Outport: '<S11>/Q' */
    speed2_B.Logic[0] = speed2_P.Q_Y0;

    /* VirtualOutportStart for Outport: '<S11>/!Q' */
    speed2_B.OutportBufferForQ = speed2_P.Q_Y0_i;

    /* End of Start for SubSystem: '<S3>/J-K Flip-Flop' */
    /* Level2 S-Function Block: '<Root>/PCI-6024E DO' (donipcie) */
    {
      SimStruct *rts = speed2_M->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* S-Function Block: <S7>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(1)) == 0) {
        if ((i = rl32eDefScope(1,2)) != 0) {
          printf("Error creating scope 1\n");
        } else {
          rl32eAddSignal(1, rl32eGetSignalNo("Divide3"));
          rl32eSetScope(1, 4, 250);
          rl32eSetScope(1, 5, 0);
          rl32eSetScope(1, 6, 1);
          rl32eSetScope(1, 0, 0);
          rl32eSetScope(1, 3, rl32eGetSignalNo("Divide3"));
          rl32eSetScope(1, 1, 0.0);
          rl32eSetScope(1, 2, 0);
          rl32eSetScope(1, 9, 0);
          rl32eSetTargetScope(1, 11, 0.0);
          rl32eSetTargetScope(1, 10, 0.0);
          xpceScopeAcqOK(1, &speed2_DW.SFunction_IWORK.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(1);
      }
    }

    /* S-Function Block: <S8>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(3)) == 0) {
        if ((i = rl32eDefScope(3,2)) != 0) {
          printf("Error creating scope 3\n");
        } else {
          rl32eAddSignal(3, rl32eGetSignalNo("Divide1"));
          rl32eSetScope(3, 4, 600);
          rl32eSetScope(3, 5, 0);
          rl32eSetScope(3, 6, 1);
          rl32eSetScope(3, 0, 0);
          rl32eSetScope(3, 3, rl32eGetSignalNo("Divide1"));
          rl32eSetScope(3, 1, 0.0);
          rl32eSetScope(3, 2, 0);
          rl32eSetScope(3, 9, 0);
          rl32eSetTargetScope(3, 11, 0.0);
          rl32eSetTargetScope(3, 10, 0.0);
          xpceScopeAcqOK(3, &speed2_DW.SFunction_IWORK_i.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(3);
      }
    }

    /* S-Function Block: <S9>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(4)) == 0) {
        if ((i = rl32eDefScope(4,2)) != 0) {
          printf("Error creating scope 4\n");
        } else {
          rl32eAddSignal(4, rl32eGetSignalNo("Data Type Conversion"));
          rl32eSetScope(4, 4, 600);
          rl32eSetScope(4, 5, 0);
          rl32eSetScope(4, 6, 1);
          rl32eSetScope(4, 0, 0);
          rl32eSetScope(4, 3, rl32eGetSignalNo("Data Type Conversion"));
          rl32eSetScope(4, 1, 0.0);
          rl32eSetScope(4, 2, 0);
          rl32eSetScope(4, 9, 0);
          rl32eSetTargetScope(4, 11, 0.0);
          rl32eSetTargetScope(4, 10, 0.0);
          xpceScopeAcqOK(4, &speed2_DW.SFunction_IWORK_o.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(4);
      }
    }

    /* Level2 S-Function Block: '<Root>/PCI-6024E DI' (dinipcie) */
    {
      SimStruct *rts = speed2_M->childSfunctions[1];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<Root>/PCI-6024E DI1' (dinipcie) */
    {
      SimStruct *rts = speed2_M->childSfunctions[2];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<Root>/PCI-6024E AD' (adnipcie) */
    {
      SimStruct *rts = speed2_M->childSfunctions[3];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* S-Function Block: <S10>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(2)) == 0) {
        if ((i = rl32eDefScope(2,2)) != 0) {
          printf("Error creating scope 2\n");
        } else {
          rl32eAddSignal(2, rl32eGetSignalNo("Gain1"));
          rl32eSetScope(2, 4, 60000);
          rl32eSetScope(2, 5, 0);
          rl32eSetScope(2, 6, 1);
          rl32eSetScope(2, 0, 0);
          rl32eSetScope(2, 3, rl32eGetSignalNo("Gain1"));
          rl32eSetScope(2, 1, 0.0);
          rl32eSetScope(2, 2, 0);
          rl32eSetScope(2, 9, 0);
          rl32eSetTargetScope(2, 11, 0.0);
          rl32eSetTargetScope(2, 10, 0.0);
          xpceScopeAcqOK(2, &speed2_DW.SFunction_IWORK_c.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(2);
      }
    }
  }

  speed2_PrevZCX.SampleandHold3_Trig_ZCE = POS_ZCSIG;
  speed2_PrevZCX.SampleandHold2.SampleandHold1_Trig_ZCE = UNINITIALIZED_ZCSIG;
  speed2_PrevZCX.SampleandHold1.SampleandHold1_Trig_ZCE = UNINITIALIZED_ZCSIG;
  speed2_PrevZCX.JKFlipFlop_Trig_ZCE = ZERO_ZCSIG;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  speed2_DW.Memory1_PreviousInput = speed2_P.Memory1_X0;

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter2' */
  speed2_DW.Counter2_ClkEphState = 5U;
  speed2_DW.Counter2_RstEphState = 5U;
  speed2_DW.Counter2_Count = speed2_P.Counter2_InitialCount;

  /* InitializeConditions for Memory: '<Root>/TmpLatchAtSample and Hold1Inport1' */
  speed2_DW.TmpLatchAtSampleandHold1Inport1 =
    speed2_P.TmpLatchAtSampleandHold1Inport1;

  /* InitializeConditions for Memory: '<Root>/TmpLatchAtSample and Hold2Inport1' */
  speed2_DW.TmpLatchAtSampleandHold2Inport1 =
    speed2_P.TmpLatchAtSampleandHold2Inport1;

  /* InitializeConditions for Memory: '<S3>/TmpLatchAtJ-K Flip-FlopInport1' */
  speed2_DW.TmpLatchAtJKFlipFlopInport1_Pre =
    speed2_P.TmpLatchAtJKFlipFlopInport1_X0;

  /* InitializeConditions for Memory: '<S3>/TmpLatchAtJ-K Flip-FlopInport2' */
  speed2_DW.TmpLatchAtJKFlipFlopInport2_Pre =
    speed2_P.TmpLatchAtJKFlipFlopInport2_X0;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  speed2_DW.Memory_PreviousInput = speed2_P.Memory_X0_c;

  /* InitializeConditions for Triggered SubSystem: '<S3>/J-K Flip-Flop' */
  /* InitializeConditions for Memory: '<S11>/Memory' */
  speed2_DW.Memory_PreviousInput_j = speed2_P.Memory_X0;

  /* End of InitializeConditions for SubSystem: '<S3>/J-K Flip-Flop' */

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter' */
  speed2_DW.Counter_ClkEphState = 5U;
  speed2_DW.Counter_Count = speed2_P.Counter_InitialCount;

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter1' */
  speed2_DW.Counter1_ClkEphState = 5U;
  speed2_DW.Counter1_Count = speed2_P.Counter1_InitialCount;
}

/* Model terminate function */
void speed2_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/PCI-6024E DO' (donipcie) */
  {
    SimStruct *rts = speed2_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/PCI-6024E DI' (dinipcie) */
  {
    SimStruct *rts = speed2_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/PCI-6024E DI1' (dinipcie) */
  {
    SimStruct *rts = speed2_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/PCI-6024E AD' (adnipcie) */
  {
    SimStruct *rts = speed2_M->childSfunctions[3];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  speed2_output(tid);
}

void MdlUpdate(int_T tid)
{
  speed2_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  speed2_initialize();
}

void MdlTerminate(void)
{
  speed2_terminate();
}

/* Registration function */
RT_MODEL_speed2_T *speed2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)speed2_M, 0,
                sizeof(RT_MODEL_speed2_T));
  rtsiSetSolverName(&speed2_M->solverInfo,"FixedStepDiscrete");
  speed2_M->solverInfoPtr = (&speed2_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = speed2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    speed2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    speed2_M->Timing.sampleTimes = (&speed2_M->Timing.sampleTimesArray[0]);
    speed2_M->Timing.offsetTimes = (&speed2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    speed2_M->Timing.sampleTimes[0] = (0.0001);
    speed2_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    speed2_M->Timing.offsetTimes[0] = (0.0);
    speed2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(speed2_M, &speed2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = speed2_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = speed2_M->Timing.perTaskSampleHitsArray;
    speed2_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    speed2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(speed2_M, 20.0);
  speed2_M->Timing.stepSize0 = 0.0001;
  speed2_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    speed2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(speed2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(speed2_M->rtwLogInfo, (NULL));
    rtliSetLogT(speed2_M->rtwLogInfo, "tout");
    rtliSetLogX(speed2_M->rtwLogInfo, "");
    rtliSetLogXFinal(speed2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(speed2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(speed2_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(speed2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(speed2_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &speed2_Y.Out1
      };

      rtliSetLogYSignalPtrs(speed2_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        2
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1, 1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL), (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4, 4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "speed2/Out1" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(speed2_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(speed2_M->rtwLogInfo, "yout");
  }

  /* External mode info */
  speed2_M->Sizes.checksums[0] = (1330278854U);
  speed2_M->Sizes.checksums[1] = (1632065287U);
  speed2_M->Sizes.checksums[2] = (201435141U);
  speed2_M->Sizes.checksums[3] = (626921919U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    speed2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&speed2_DW.JKFlipFlop_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &speed2_DW.SampleandHold1.SampleandHold1_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &speed2_DW.SampleandHold2.SampleandHold1_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&speed2_DW.SampleandHold3_SubsysRanBC;
    rteiSetModelMappingInfoPtr(speed2_M->extModeInfo,
      &speed2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(speed2_M->extModeInfo, speed2_M->Sizes.checksums);
    rteiSetTPtr(speed2_M->extModeInfo, rtmGetTPtr(speed2_M));
  }

  speed2_M->solverInfoPtr = (&speed2_M->solverInfo);
  speed2_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&speed2_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&speed2_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  speed2_M->ModelData.blockIO = ((void *) &speed2_B);
  (void) memset(((void *) &speed2_B), 0,
                sizeof(B_speed2_T));

  /* parameters */
  speed2_M->ModelData.defaultParam = ((real_T *)&speed2_P);

  /* states (dwork) */
  speed2_M->ModelData.dwork = ((void *) &speed2_DW);
  (void) memset((void *)&speed2_DW, 0,
                sizeof(DW_speed2_T));

  /* external outputs */
  speed2_M->ModelData.outputs = (&speed2_Y);
  speed2_Y.Out1 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    speed2_M->SpecialInfo.mappingInfo = (&dtInfo);
    speed2_M->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  speed2_InitializeDataMapInfo(speed2_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &speed2_M->NonInlinedSFcns.sfcnInfo;
    speed2_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(speed2_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &speed2_M->Sizes.numSampTimes);
    speed2_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(speed2_M)[0]);
    speed2_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(speed2_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,speed2_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(speed2_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(speed2_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(speed2_M));
    rtssSetStepSizePtr(sfcnInfo, &speed2_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(speed2_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &speed2_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &speed2_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &speed2_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &speed2_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &speed2_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &speed2_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &speed2_M->solverInfoPtr);
  }

  speed2_M->Sizes.numSFcns = (4);

  /* register each child */
  {
    (void) memset((void *)&speed2_M->NonInlinedSFcns.childSFunctions[0], 0,
                  4*sizeof(SimStruct));
    speed2_M->childSfunctions = (&speed2_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    speed2_M->childSfunctions[0] = (&speed2_M->NonInlinedSFcns.childSFunctions[0]);
    speed2_M->childSfunctions[1] = (&speed2_M->NonInlinedSFcns.childSFunctions[1]);
    speed2_M->childSfunctions[2] = (&speed2_M->NonInlinedSFcns.childSFunctions[2]);
    speed2_M->childSfunctions[3] = (&speed2_M->NonInlinedSFcns.childSFunctions[3]);

    /* Level2 S-Function Block: speed2/<Root>/PCI-6024E DO (donipcie) */
    {
      SimStruct *rts = speed2_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = speed2_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = speed2_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = speed2_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &speed2_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, speed2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &speed2_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &speed2_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &speed2_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &speed2_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &speed2_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &speed2_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6024E DO");
      ssSetPath(rts, "speed2/PCI-6024E DO");
      ssSetRTModel(rts,speed2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &speed2_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)speed2_P.PCI6024EDO_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)speed2_P.PCI6024EDO_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)speed2_P.PCI6024EDO_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)speed2_P.PCI6024EDO_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)speed2_P.PCI6024EDO_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)speed2_P.PCI6024EDO_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)speed2_P.PCI6024EDO_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &speed2_DW.PCI6024EDO_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &speed2_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &speed2_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &speed2_DW.PCI6024EDO_IWORK[0]);
      }

      /* registration */
      donipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: speed2/<Root>/PCI-6024E DI (dinipcie) */
    {
      SimStruct *rts = speed2_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = speed2_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = speed2_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = speed2_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &speed2_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, speed2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &speed2_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &speed2_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &speed2_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &speed2_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &speed2_B.PCI6024EDI));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6024E DI");
      ssSetPath(rts, "speed2/PCI-6024E DI");
      ssSetRTModel(rts,speed2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &speed2_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)speed2_P.PCI6024EDI_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)speed2_P.PCI6024EDI_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)speed2_P.PCI6024EDI_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)speed2_P.PCI6024EDI_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)speed2_P.PCI6024EDI_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &speed2_DW.PCI6024EDI_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &speed2_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &speed2_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &speed2_DW.PCI6024EDI_IWORK[0]);
      }

      /* registration */
      dinipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: speed2/<Root>/PCI-6024E DI1 (dinipcie) */
    {
      SimStruct *rts = speed2_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = speed2_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = speed2_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = speed2_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &speed2_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, speed2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &speed2_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &speed2_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &speed2_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &speed2_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &speed2_B.PCI6024EDI1));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6024E DI1");
      ssSetPath(rts, "speed2/PCI-6024E DI1");
      ssSetRTModel(rts,speed2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &speed2_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)speed2_P.PCI6024EDI1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)speed2_P.PCI6024EDI1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)speed2_P.PCI6024EDI1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)speed2_P.PCI6024EDI1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)speed2_P.PCI6024EDI1_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &speed2_DW.PCI6024EDI1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &speed2_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &speed2_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &speed2_DW.PCI6024EDI1_IWORK[0]);
      }

      /* registration */
      dinipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: speed2/<Root>/PCI-6024E AD (adnipcie) */
    {
      SimStruct *rts = speed2_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = speed2_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = speed2_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = speed2_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &speed2_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, speed2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &speed2_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &speed2_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &speed2_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &speed2_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &speed2_B.PCI6024EAD));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6024E AD");
      ssSetPath(rts, "speed2/PCI-6024E AD");
      ssSetRTModel(rts,speed2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &speed2_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)speed2_P.PCI6024EAD_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)speed2_P.PCI6024EAD_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)speed2_P.PCI6024EAD_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)speed2_P.PCI6024EAD_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)speed2_P.PCI6024EAD_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)speed2_P.PCI6024EAD_P6_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &speed2_DW.PCI6024EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &speed2_DW.PCI6024EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &speed2_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &speed2_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &speed2_DW.PCI6024EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &speed2_DW.PCI6024EAD_IWORK[0]);
      }

      /* registration */
      adnipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  speed2_M->Sizes.numContStates = (0); /* Number of continuous states */
  speed2_M->Sizes.numY = (1);          /* Number of model outputs */
  speed2_M->Sizes.numU = (0);          /* Number of model inputs */
  speed2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  speed2_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  speed2_M->Sizes.numBlocks = (59);    /* Number of blocks */
  speed2_M->Sizes.numBlockIO = (35);   /* Number of block outputs */
  speed2_M->Sizes.numBlockPrms = (118);/* Sum of parameter "widths" */
  return speed2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
