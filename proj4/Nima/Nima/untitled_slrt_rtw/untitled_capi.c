/*
 * untitled_capi.c
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
#include "rtw_capi.h"
#include "untitled_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "PCI-6024E AD",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Signal Generator",
    "", 0, 0, 0, 0, 1 },

  { 2, 0, "Discrete FIR Filter",
    "", 0, 0, 0, 0, 2 },

  { 3, 0, "Async Rate Transition /Rate Transition",
    "", 0, 0, 0, 0, 2 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 4, "PCI-6024E AD",
    "P1", 0, 0, 0 },

  { 5, "PCI-6024E AD",
    "P2", 0, 0, 0 },

  { 6, "PCI-6024E AD",
    "P3", 0, 0, 0 },

  { 7, "PCI-6024E AD",
    "P4", 0, 0, 0 },

  { 8, "PCI-6024E AD",
    "P5", 0, 0, 0 },

  { 9, "PCI-6024E AD",
    "P6", 0, 0, 0 },

  { 10, "PCI-6024E DA",
    "P1", 0, 0, 0 },

  { 11, "PCI-6024E DA",
    "P2", 0, 0, 0 },

  { 12, "PCI-6024E DA",
    "P3", 0, 0, 0 },

  { 13, "PCI-6024E DA",
    "P4", 0, 0, 0 },

  { 14, "PCI-6024E DA",
    "P5", 0, 0, 0 },

  { 15, "PCI-6024E DA",
    "P6", 0, 0, 0 },

  { 16, "PCI-6024E DA",
    "P7", 0, 0, 0 },

  { 17, "Signal Generator",
    "Amplitude", 0, 0, 0 },

  { 18, "Signal Generator",
    "Frequency", 0, 0, 0 },

  { 19, "Discrete FIR Filter",
    "InitialStates", 0, 0, 0 },

  { 20, "Discrete FIR Filter",
    "Coefficients", 0, 1, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &untitled_B.PCI6024EAD,              /* 0: Signal */
  &untitled_B.SignalGenerator,         /* 1: Signal */
  &untitled_B.DiscreteFIRFilter,       /* 2: Signal */
  &untitled_B.RateTransition,          /* 3: Signal */
  &untitled_P.PCI6024EAD_P1,           /* 4: Block Parameter */
  &untitled_P.PCI6024EAD_P2,           /* 5: Block Parameter */
  &untitled_P.PCI6024EAD_P3,           /* 6: Block Parameter */
  &untitled_P.PCI6024EAD_P4,           /* 7: Block Parameter */
  &untitled_P.PCI6024EAD_P5,           /* 8: Block Parameter */
  &untitled_P.PCI6024EAD_P6,           /* 9: Block Parameter */
  &untitled_P.PCI6024EDA_P1,           /* 10: Block Parameter */
  &untitled_P.PCI6024EDA_P2,           /* 11: Block Parameter */
  &untitled_P.PCI6024EDA_P3,           /* 12: Block Parameter */
  &untitled_P.PCI6024EDA_P4,           /* 13: Block Parameter */
  &untitled_P.PCI6024EDA_P5,           /* 14: Block Parameter */
  &untitled_P.PCI6024EDA_P6,           /* 15: Block Parameter */
  &untitled_P.PCI6024EDA_P7,           /* 16: Block Parameter */
  &untitled_P.SignalGenerator_Amplitude,/* 17: Block Parameter */
  &untitled_P.SignalGenerator_Frequency,/* 18: Block Parameter */
  &untitled_P.DiscreteFIRFilter_InitialStates,/* 19: Block Parameter */
  &untitled_P.DiscreteFIRFilter_Coefficients[0]/* 20: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  2                                    /* 3 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.006, 0.0, 0.003
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    2, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 4 },

  { rtBlockParameters, 17,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1404218382U,
    631146411U,
    2045652886U,
    3211938998U },
  NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void untitled_InitializeDataMapInfo(RT_MODEL_untitled_T *untitled_M
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(untitled_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(untitled_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(untitled_M->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(untitled_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(untitled_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  untitled_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (untitled_M);
  untitled_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof(P_untitled_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(untitled_M->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(untitled_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(untitled_M->DataMapInfo.mmi, 0);
}

/* EOF: untitled_capi.c */
