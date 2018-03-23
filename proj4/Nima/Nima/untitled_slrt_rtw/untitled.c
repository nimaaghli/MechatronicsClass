/*
 * untitled.c
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
#include "rt_logging_mmi.h"
#include "untitled_capi.h"
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block signals (auto storage) */
B_untitled_T untitled_B;

/* Block states (auto storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(untitled_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(untitled_M, 2);
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
  (untitled_M->Timing.TaskCounters.TID[2])++;
  if ((untitled_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.006s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model output function for TID0 */
void untitled_output0(void)            /* Sample time: [0.0s, 0.0s] */
{
  real_T accumulator;
  real_T product;
  int32_T i;
  int32_T j;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  untitled_B.SignalGenerator = sin(untitled_P.SignalGenerator_Frequency *
    untitled_M->Timing.t[0]) * untitled_P.SignalGenerator_Amplitude;

  /* Level2 S-Function Block: '<Root>/PCI-6024E DA' (danipcie) */
  {
    SimStruct *rts = untitled_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* RateTransition: '<S1>/Rate Transition' */
  untitled_B.RateTransition = untitled_B.PCI6024EAD;

  /* DiscreteFir: '<Root>/Discrete FIR Filter' */
  /* Consume delay line and beginning of input samples */
  for (i = 1; i - 1 < 1; i++) {
    accumulator = 0.0;
    for (j = 0; j < i; j++) {
      product = untitled_B.RateTransition *
        untitled_P.DiscreteFIRFilter_Coefficients[j];
      accumulator += product;
    }

    for (j = 0; j < 2 - i; j++) {
      product = untitled_P.DiscreteFIRFilter_Coefficients[i + j] *
        untitled_DW.DiscreteFIRFilter_states;
      accumulator += product;
    }

    untitled_B.DiscreteFIRFilter = accumulator;
  }

  /* Update delay line for next frame */
  i = 0;
  while (i < 1) {
    untitled_DW.DiscreteFIRFilter_states = untitled_B.RateTransition;
    i = 1;
  }

  /* End of DiscreteFir: '<Root>/Discrete FIR Filter' */

  /* ok to acquire for <S2>/S-Function */
  untitled_DW.SFunction_IWORK.AcquireOK = 1;
}

/* Model update function for TID0 */
void untitled_update0(void)            /* Sample time: [0.0s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++untitled_M->Timing.clockTick0)) {
    ++untitled_M->Timing.clockTickH0;
  }

  untitled_M->Timing.t[0] = untitled_M->Timing.clockTick0 *
    untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
    untitled_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++untitled_M->Timing.clockTick1)) {
    ++untitled_M->Timing.clockTickH1;
  }

  untitled_M->Timing.t[1] = untitled_M->Timing.clockTick1 *
    untitled_M->Timing.stepSize1 + untitled_M->Timing.clockTickH1 *
    untitled_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output function for TID2 */
void untitled_output2(void)            /* Sample time: [0.006s, 0.0s] */
{
  /* Level2 S-Function Block: '<Root>/PCI-6024E AD' (adnipcie) */
  {
    SimStruct *rts = untitled_M->childSfunctions[1];
    sfcnOutputs(rts, 2);
  }
}

/* Model update function for TID2 */
void untitled_update2(void)            /* Sample time: [0.006s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++untitled_M->Timing.clockTick2)) {
    ++untitled_M->Timing.clockTickH2;
  }

  untitled_M->Timing.t[2] = untitled_M->Timing.clockTick2 *
    untitled_M->Timing.stepSize2 + untitled_M->Timing.clockTickH2 *
    untitled_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void untitled_output(int_T tid)
{
  switch (tid) {
   case 0 :
    untitled_output0();
    break;

   case 2 :
    untitled_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void untitled_update(int_T tid)
{
  switch (tid) {
   case 0 :
    untitled_update0();
    break;

   case 2 :
    untitled_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/PCI-6024E DA' (danipcie) */
  {
    SimStruct *rts = untitled_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<Root>/PCI-6024E AD' (adnipcie) */
  {
    SimStruct *rts = untitled_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Signal Generator"));
        rl32eAddSignal(1, rl32eGetSignalNo("Discrete FIR Filter"));
        rl32eSetScope(1, 4, 600);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Signal Generator"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 0.0);
        xpceScopeAcqOK(1, &untitled_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter' */
  untitled_DW.DiscreteFIRFilter_states =
    untitled_P.DiscreteFIRFilter_InitialStates;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/PCI-6024E DA' (danipcie) */
  {
    SimStruct *rts = untitled_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/PCI-6024E AD' (adnipcie) */
  {
    SimStruct *rts = untitled_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  untitled_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  untitled_update(tid);
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
  untitled_initialize();
}

void MdlTerminate(void)
{
  untitled_terminate();
}

/* Registration function */
RT_MODEL_untitled_T *untitled(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  untitled_M->solverInfoPtr = (&untitled_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = untitled_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    untitled_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    untitled_M->Timing.sampleTimes = (&untitled_M->Timing.sampleTimesArray[0]);
    untitled_M->Timing.offsetTimes = (&untitled_M->Timing.offsetTimesArray[0]);

    /* task periods */
    untitled_M->Timing.sampleTimes[0] = (0.0);
    untitled_M->Timing.sampleTimes[1] = (0.003);
    untitled_M->Timing.sampleTimes[2] = (0.006);

    /* task offsets */
    untitled_M->Timing.offsetTimes[0] = (0.0);
    untitled_M->Timing.offsetTimes[1] = (0.0);
    untitled_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = untitled_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = untitled_M->Timing.perTaskSampleHitsArray;
    untitled_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    untitled_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(untitled_M, 3.999);
  untitled_M->Timing.stepSize0 = 0.003;
  untitled_M->Timing.stepSize1 = 0.003;
  untitled_M->Timing.stepSize2 = 0.006;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    untitled_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(untitled_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(untitled_M->rtwLogInfo, (NULL));
    rtliSetLogT(untitled_M->rtwLogInfo, "tout");
    rtliSetLogX(untitled_M->rtwLogInfo, "");
    rtliSetLogXFinal(untitled_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(untitled_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(untitled_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(untitled_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(untitled_M->rtwLogInfo, 1);
    rtliSetLogY(untitled_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(untitled_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(untitled_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1404218382U);
  untitled_M->Sizes.checksums[1] = (631146411U);
  untitled_M->Sizes.checksums[2] = (2045652886U);
  untitled_M->Sizes.checksums[3] = (3211938998U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  untitled_M->solverInfoPtr = (&untitled_M->solverInfo);
  untitled_M->Timing.stepSize = (0.003);
  rtsiSetFixedStepSize(&untitled_M->solverInfo, 0.003);
  rtsiSetSolverMode(&untitled_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  untitled_M->ModelData.blockIO = ((void *) &untitled_B);
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* parameters */
  untitled_M->ModelData.defaultParam = ((real_T *)&untitled_P);

  /* states (dwork) */
  untitled_M->ModelData.dwork = ((void *) &untitled_DW);
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    untitled_M->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  untitled_InitializeDataMapInfo(untitled_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &untitled_M->NonInlinedSFcns.sfcnInfo;
    untitled_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(untitled_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &untitled_M->Sizes.numSampTimes);
    untitled_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(untitled_M)[0]);
    untitled_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(untitled_M)[1]);
    untitled_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr(untitled_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,untitled_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(untitled_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(untitled_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(untitled_M));
    rtssSetStepSizePtr(sfcnInfo, &untitled_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(untitled_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &untitled_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &untitled_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &untitled_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &untitled_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &untitled_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &untitled_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &untitled_M->solverInfoPtr);
  }

  untitled_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&untitled_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    untitled_M->childSfunctions =
      (&untitled_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    untitled_M->childSfunctions[0] =
      (&untitled_M->NonInlinedSFcns.childSFunctions[0]);
    untitled_M->childSfunctions[1] =
      (&untitled_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: untitled/<Root>/PCI-6024E DA (danipcie) */
    {
      SimStruct *rts = untitled_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = untitled_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = untitled_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = untitled_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &untitled_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, untitled_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &untitled_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &untitled_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &untitled_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &untitled_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &untitled_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &untitled_B.SignalGenerator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6024E DA");
      ssSetPath(rts, "untitled/PCI-6024E DA");
      ssSetRTModel(rts,untitled_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &untitled_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)untitled_P.PCI6024EDA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)untitled_P.PCI6024EDA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)untitled_P.PCI6024EDA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)untitled_P.PCI6024EDA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)untitled_P.PCI6024EDA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)untitled_P.PCI6024EDA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)untitled_P.PCI6024EDA_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &untitled_DW.PCI6024EDA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &untitled_DW.PCI6024EDA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &untitled_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &untitled_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &untitled_DW.PCI6024EDA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &untitled_DW.PCI6024EDA_IWORK[0]);
      }

      /* registration */
      danipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: untitled/<Root>/PCI-6024E AD (adnipcie) */
    {
      SimStruct *rts = untitled_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = untitled_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = untitled_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = untitled_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &untitled_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, untitled_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &untitled_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &untitled_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &untitled_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &untitled_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &untitled_B.PCI6024EAD));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6024E AD");
      ssSetPath(rts, "untitled/PCI-6024E AD");
      ssSetRTModel(rts,untitled_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &untitled_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)untitled_P.PCI6024EAD_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)untitled_P.PCI6024EAD_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)untitled_P.PCI6024EAD_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)untitled_P.PCI6024EAD_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)untitled_P.PCI6024EAD_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)untitled_P.PCI6024EAD_P6_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &untitled_DW.PCI6024EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &untitled_DW.PCI6024EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &untitled_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &untitled_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &untitled_DW.PCI6024EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &untitled_DW.PCI6024EAD_IWORK[0]);
      }

      /* registration */
      adnipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.006);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  untitled_M->Sizes.numContStates = (0);/* Number of continuous states */
  untitled_M->Sizes.numY = (0);        /* Number of model outputs */
  untitled_M->Sizes.numU = (0);        /* Number of model inputs */
  untitled_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  untitled_M->Sizes.numSampTimes = (3);/* Number of sample times */
  untitled_M->Sizes.numBlocks = (7);   /* Number of blocks */
  untitled_M->Sizes.numBlockIO = (4);  /* Number of block outputs */
  untitled_M->Sizes.numBlockPrms = (44);/* Sum of parameter "widths" */
  return untitled_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
