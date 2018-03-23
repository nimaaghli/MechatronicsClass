/*
 * speed2.h
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
#ifndef RTW_HEADER_speed2_h_
#define RTW_HEADER_speed2_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef speed2_COMMON_INCLUDES_
# define speed2_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* speed2_COMMON_INCLUDES_ */

#include "speed2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_speed2                 RT_MODEL_speed2_T

/* Definition for use in the target main file */
#define speed2_rtModel                 RT_MODEL_speed2_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals for system '<Root>/Sample and Hold1' */
typedef struct {
  real_T In;                           /* '<S4>/In' */
} B_SampleandHold1_speed2_T;

/* Block states (auto storage) for system '<Root>/Sample and Hold1' */
typedef struct {
  int8_T SampleandHold1_SubsysRanBC;   /* '<Root>/Sample and Hold1' */
} DW_SampleandHold1_speed2_T;

/* Zero-crossing (trigger) state for system '<Root>/Sample and Hold1' */
typedef struct {
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<Root>/Sample and Hold1' */
} ZCE_SampleandHold1_speed2_T;

/* Block signals (auto storage) */
typedef struct {
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
  real_T Counter2;                     /* '<Root>/Counter2' */
  real_T TmpLatchAtSampleandHold1Inport1;/* '<Root>/Sum' */
  real_T TmpLatchAtSampleandHold2Inport1;/* '<Root>/Sample and Hold1' */
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T UniformRandomNumber;          /* '<Root>/Uniform Random Number' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Subtract1;                    /* '<Root>/Subtract1' */
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Divide2;                      /* '<Root>/Divide2' */
  real_T multply1;                     /* '<Root>/multply1' */
  real_T Divide3;                      /* '<Root>/Divide3' */
  real_T PCI6024EDI;                   /* '<Root>/PCI-6024E DI' */
  real_T Counter;                      /* '<Root>/Counter' */
  real_T PCI6024EDI1;                  /* '<Root>/PCI-6024E DI1' */
  real_T Counter1;                     /* '<Root>/Counter1' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Divide;                       /* '<Root>/Divide' */
  real_T multply;                      /* '<Root>/multply' */
  real_T Divide1;                      /* '<Root>/Divide1' */
  real_T PCI6024EAD;                   /* '<Root>/PCI-6024E AD' */
  real_T RateTransition;               /* '<S1>/Rate Transition' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T In;                           /* '<S6>/In' */
  boolean_T Memory1;                   /* '<Root>/Memory1' */
  boolean_T TmpLatchAtJKFlipFlopInport1;
  boolean_T TmpLatchAtJKFlipFlopInport2;
  boolean_T Memory;                    /* '<Root>/Memory' */
  boolean_T Compare;                   /* '<S2>/Compare' */
  boolean_T Memory_c;                  /* '<S11>/Memory' */
  boolean_T Logic[2];                  /* '<S11>/Logic' */
  boolean_T OutportBufferForQ;
  B_SampleandHold1_speed2_T SampleandHold2;/* '<Root>/Sample and Hold2' */
  B_SampleandHold1_speed2_T SampleandHold1;/* '<Root>/Sample and Hold1' */
} B_speed2_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TmpLatchAtSampleandHold1Inport1;/* synthesized block */
  real_T TmpLatchAtSampleandHold2Inport1;/* synthesized block */
  real_T UniformRandomNumber_NextOutput;/* '<Root>/Uniform Random Number' */
  real_T PCI6024EAD_RWORK[64];         /* '<Root>/PCI-6024E AD' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  uint32_T Counter2_Count;             /* '<Root>/Counter2' */
  uint32_T Counter2_ClkEphState;       /* '<Root>/Counter2' */
  uint32_T Counter2_RstEphState;       /* '<Root>/Counter2' */
  uint32_T RandSeed;                   /* '<Root>/Uniform Random Number' */
  uint32_T Counter_Count;              /* '<Root>/Counter' */
  uint32_T Counter_ClkEphState;        /* '<Root>/Counter' */
  uint32_T Counter1_Count;             /* '<Root>/Counter1' */
  uint32_T Counter1_ClkEphState;       /* '<Root>/Counter1' */
  int_T PCI6024EDO_IWORK[3];           /* '<Root>/PCI-6024E DO' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S7>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S8>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_o;                 /* '<S9>/S-Function' */

  int_T PCI6024EDI_IWORK[3];           /* '<Root>/PCI-6024E DI' */
  int_T PCI6024EDI1_IWORK[3];          /* '<Root>/PCI-6024E DI1' */
  int_T PCI6024EAD_IWORK[66];          /* '<Root>/PCI-6024E AD' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_c;                 /* '<S10>/S-Function' */

  int8_T SampleandHold3_SubsysRanBC;   /* '<Root>/Sample and Hold3' */
  int8_T JKFlipFlop_SubsysRanBC;       /* '<S3>/J-K Flip-Flop' */
  boolean_T Memory1_PreviousInput;     /* '<Root>/Memory1' */
  boolean_T TmpLatchAtJKFlipFlopInport1_Pre;/* synthesized block */
  boolean_T TmpLatchAtJKFlipFlopInport2_Pre;/* synthesized block */
  boolean_T Memory_PreviousInput;      /* '<Root>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S11>/Memory' */
  DW_SampleandHold1_speed2_T SampleandHold2;/* '<Root>/Sample and Hold2' */
  DW_SampleandHold1_speed2_T SampleandHold1;/* '<Root>/Sample and Hold1' */
} DW_speed2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold3_Trig_ZCE;  /* '<Root>/Sample and Hold3' */
  ZCE_SampleandHold1_speed2_T SampleandHold2;/* '<Root>/Sample and Hold1' */
  ZCE_SampleandHold1_speed2_T SampleandHold1;/* '<Root>/Sample and Hold1' */
  ZCSigState JKFlipFlop_Trig_ZCE;      /* '<S3>/J-K Flip-Flop' */
} PrevZCX_speed2_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_speed2_T;

/* Backward compatible GRT Identifiers */
#define rtB                            speed2_B
#define BlockIO                        B_speed2_T
#define rtY                            speed2_Y
#define ExternalOutputs                ExtY_speed2_T
#define rtP                            speed2_P
#define Parameters                     P_speed2_T
#define rtDWork                        speed2_DW
#define D_Work                         DW_speed2_T
#define rtPrevZCSigState               speed2_PrevZCX
#define PrevZCSigStates                PrevZCX_speed2_T

/* Parameters for system: '<Root>/Sample and Hold1' */
struct P_SampleandHold1_speed2_T_ {
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S4>/ '
                                        */
};

/* Parameters (auto storage) */
struct P_speed2_T_ {
  uint32_T Counter2_InitialCount;      /* Mask Parameter: Counter2_InitialCount
                                        * Referenced by: '<Root>/Counter2'
                                        */
  uint32_T Counter_InitialCount;       /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<Root>/Counter'
                                        */
  uint32_T Counter1_InitialCount;      /* Mask Parameter: Counter1_InitialCount
                                        * Referenced by: '<Root>/Counter1'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S6>/ '
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T TmpLatchAtSampleandHold1Inport1;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T TmpLatchAtSampleandHold2Inport1;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T UniformRandomNumber_Minimum;  /* Expression: 0
                                        * Referenced by: '<Root>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 0.5
                                        * Referenced by: '<Root>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<Root>/Uniform Random Number'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/0.01
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T PCI6024EDO_P1_Size[2];        /* Computed Parameter: PCI6024EDO_P1_Size
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P1;                /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P2_Size[2];        /* Computed Parameter: PCI6024EDO_P2_Size
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P2;                /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P3_Size[2];        /* Computed Parameter: PCI6024EDO_P3_Size
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P3;                /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P4_Size[2];        /* Computed Parameter: PCI6024EDO_P4_Size
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P4;                /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P5_Size[2];        /* Computed Parameter: PCI6024EDO_P5_Size
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P5;                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P6_Size[2];        /* Computed Parameter: PCI6024EDO_P6_Size
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P6;                /* Expression: control
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P7_Size[2];        /* Computed Parameter: PCI6024EDO_P7_Size
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T PCI6024EDO_P7;                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6024E DO'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/0.01
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T ucounts1rev1_Value;           /* Expression: 24
                                        * Referenced by: '<Root>/24 counts=1 rev1'
                                        */
  real_T rev360degree1_Value;          /* Expression: 360
                                        * Referenced by: '<Root>/1 rev=360 degree1'
                                        */
  real_T converstionfactor2132_Value;  /* Expression: 21.3
                                        * Referenced by: '<Root>/converstion factor 21.3:2'
                                        */
  real_T PCI6024EDI_P1_Size[2];        /* Computed Parameter: PCI6024EDI_P1_Size
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI_P1;                /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI_P2_Size[2];        /* Computed Parameter: PCI6024EDI_P2_Size
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI_P2;                /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI_P3_Size[2];        /* Computed Parameter: PCI6024EDI_P3_Size
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI_P3;                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI_P4_Size[2];        /* Computed Parameter: PCI6024EDI_P4_Size
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI_P4;                /* Expression: control
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI_P5_Size[2];        /* Computed Parameter: PCI6024EDI_P5_Size
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI_P5;                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6024E DI'
                                        */
  real_T PCI6024EDI1_P1_Size[2];       /* Computed Parameter: PCI6024EDI1_P1_Size
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T PCI6024EDI1_P1;               /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T PCI6024EDI1_P2_Size[2];       /* Computed Parameter: PCI6024EDI1_P2_Size
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T PCI6024EDI1_P2;               /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T PCI6024EDI1_P3_Size[2];       /* Computed Parameter: PCI6024EDI1_P3_Size
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T PCI6024EDI1_P3;               /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T PCI6024EDI1_P4_Size[2];       /* Computed Parameter: PCI6024EDI1_P4_Size
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T PCI6024EDI1_P4;               /* Expression: control
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T PCI6024EDI1_P5_Size[2];       /* Computed Parameter: PCI6024EDI1_P5_Size
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T PCI6024EDI1_P5;               /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6024E DI1'
                                        */
  real_T ucounts1rev_Value;            /* Expression: 24
                                        * Referenced by: '<Root>/24 counts=1 rev'
                                        */
  real_T rev360degree_Value;           /* Expression: 360
                                        * Referenced by: '<Root>/1 rev=360 degree'
                                        */
  real_T converstionfactor2131_Value;  /* Expression: 21.3
                                        * Referenced by: '<Root>/converstion factor 21.3:1'
                                        */
  real_T PCI6024EAD_P1_Size[2];        /* Computed Parameter: PCI6024EAD_P1_Size
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P1;                /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P2_Size[2];        /* Computed Parameter: PCI6024EAD_P2_Size
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P2;                /* Expression: range
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P3_Size[2];        /* Computed Parameter: PCI6024EAD_P3_Size
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P3;                /* Expression: coupling
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P4_Size[2];        /* Computed Parameter: PCI6024EAD_P4_Size
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P4;                /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P5_Size[2];        /* Computed Parameter: PCI6024EAD_P5_Size
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P5;                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P6_Size[2];        /* Computed Parameter: PCI6024EAD_P6_Size
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T PCI6024EAD_P6;                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6024E AD'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  boolean_T Q_Y0;                      /* Expression: initial_condition
                                        * Referenced by: '<S11>/Q'
                                        */
  boolean_T Q_Y0_i;                    /* Expression: ~initial_condition
                                        * Referenced by: '<S11>/!Q'
                                        */
  boolean_T Memory_X0;                 /* Expression: initial_condition
                                        * Referenced by: '<S11>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S11>/Logic'
                                        */
  boolean_T Memory1_X0;                /* Computed Parameter: Memory1_X0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  boolean_T TmpLatchAtJKFlipFlopInport1_X0;/* Computed Parameter: TmpLatchAtJKFlipFlopInport1_X0
                                            * Referenced by: synthesized block
                                            */
  boolean_T TmpLatchAtJKFlipFlopInport2_X0;/* Computed Parameter: TmpLatchAtJKFlipFlopInport2_X0
                                            * Referenced by: synthesized block
                                            */
  boolean_T Memory_X0_c;               /* Computed Parameter: Memory_X0_c
                                        * Referenced by: '<Root>/Memory'
                                        */
  boolean_T Constant_Value_m;          /* Expression: true
                                        * Referenced by: '<Root>/Constant'
                                        */
  P_SampleandHold1_speed2_T SampleandHold2;/* '<Root>/Sample and Hold2' */
  P_SampleandHold1_speed2_T SampleandHold1;/* '<Root>/Sample and Hold1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_speed2_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[4];
    SimStruct *childSFunctionPtrs[4];
    struct _ssBlkInfo2 blkInfo2[4];
    struct _ssSFcnModelMethods2 methods2[4];
    struct _ssSFcnModelMethods3 methods3[4];
    struct _ssStatesInfo2 statesInfo2[4];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn3;
  } NonInlinedSFcns;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_speed2_T speed2_P;

/* Block signals (auto storage) */
extern B_speed2_T speed2_B;

/* Block states (auto storage) */
extern DW_speed2_T speed2_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_speed2_T speed2_Y;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_speed2_T speed2_PrevZCX;

/* Model entry point functions */
extern void speed2_initialize(void);
extern void speed2_output(int_T tid);
extern void speed2_update(int_T tid);
extern void speed2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_speed2_T *const speed2_M;

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
 * '<Root>' : 'speed2'
 * '<S1>'   : 'speed2/Async Rate Transition '
 * '<S2>'   : 'speed2/Compare To Zero'
 * '<S3>'   : 'speed2/J-K Flip-Flop'
 * '<S4>'   : 'speed2/Sample and Hold1'
 * '<S5>'   : 'speed2/Sample and Hold2'
 * '<S6>'   : 'speed2/Sample and Hold3'
 * '<S7>'   : 'speed2/Scope '
 * '<S8>'   : 'speed2/Scope 1'
 * '<S9>'   : 'speed2/Scope 2'
 * '<S10>'  : 'speed2/current'
 * '<S11>'  : 'speed2/J-K Flip-Flop/J-K Flip-Flop'
 */
#endif                                 /* RTW_HEADER_speed2_h_ */
