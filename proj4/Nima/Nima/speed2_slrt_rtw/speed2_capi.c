/*
 * speed2_capi.c
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
#include "rtw_capi.h"
#include "speed2_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Data Type Conversion",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Pulse Generator",
    "", 0, 0, 0, 0, 0 },

  { 2, 0, "Gain",
    "", 0, 0, 0, 0, 0 },

  { 3, 0, "Gain1",
    "", 0, 0, 0, 0, 1 },

  { 4, 0, "Gain2",
    "", 0, 0, 0, 0, 0 },

  { 5, 0, "Memory",
    "", 0, 1, 0, 0, 0 },

  { 6, 0, "Memory1",
    "", 0, 1, 0, 0, 0 },

  { 7, 0, "Divide",
    "", 0, 0, 0, 0, 0 },

  { 8, 0, "Divide1",
    "", 0, 0, 0, 0, 0 },

  { 9, 0, "Divide2",
    "", 0, 0, 0, 0, 0 },

  { 10, 0, "Divide3",
    "", 0, 0, 0, 0, 0 },

  { 11, 0, "multply",
    "", 0, 0, 0, 0, 0 },

  { 12, 0, "multply1",
    "", 0, 0, 0, 0, 0 },

  { 13, 0, "Counter",
    "", 0, 0, 0, 0, 0 },

  { 14, 0, "Counter1",
    "", 0, 0, 0, 0, 0 },

  { 15, 0, "Counter2",
    "", 0, 0, 0, 0, 0 },

  { 16, 0, "PCI-6024E AD",
    "", 0, 0, 0, 0, 0 },

  { 17, 0, "PCI-6024E DI",
    "", 0, 0, 0, 0, 0 },

  { 18, 0, "PCI-6024E DI1",
    "", 0, 0, 0, 0, 0 },

  { 19, 0, "Subtract",
    "", 0, 0, 0, 0, 0 },

  { 20, 0, "Subtract1",
    "", 0, 0, 0, 0, 0 },

  { 21, 0, "Sum",
    "", 0, 0, 0, 0, 0 },

  { 22, 0, "Uniform Random Number",
    "", 0, 0, 0, 0, 0 },

  { 23, 0, "Async Rate Transition /Rate Transition",
    "", 0, 0, 0, 0, 1 },

  { 24, 0, "Compare To Zero/Compare",
    "", 0, 1, 0, 0, 0 },

  { 25, 2, "Sample and Hold1/In",
    "", 0, 0, 0, 0, 2 },

  { 26, 3, "Sample and Hold2/In",
    "", 0, 0, 0, 0, 2 },

  { 27, 4, "Sample and Hold3/In",
    "", 0, 0, 0, 0, 2 },

  { 28, 1, "J-K Flip-Flop/J-K Flip-Flop/Logic",
    "", 0, 1, 1, 0, 2 },

  { 29, 1, "J-K Flip-Flop/J-K Flip-Flop/Memory",
    "", 0, 1, 0, 0, 2 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 30, "1 rev=360 degree",
    "Value", 0, 0, 0 },

  { 31, "1 rev=360 degree1",
    "Value", 0, 0, 0 },

  { 32, "24 counts=1 rev",
    "Value", 0, 0, 0 },

  { 33, "24 counts=1 rev1",
    "Value", 0, 0, 0 },

  { 34, "Constant",
    "Value", 1, 0, 0 },

  { 35, "converstion factor 21.3:1",
    "Value", 0, 0, 0 },

  { 36, "converstion factor 21.3:2",
    "Value", 0, 0, 0 },

  { 37, "Pulse Generator",
    "Amplitude", 0, 0, 0 },

  { 38, "Pulse Generator",
    "Period", 0, 0, 0 },

  { 39, "Pulse Generator",
    "PulseWidth", 0, 0, 0 },

  { 40, "Pulse Generator",
    "PhaseDelay", 0, 0, 0 },

  { 41, "Gain",
    "Gain", 0, 0, 0 },

  { 42, "Gain1",
    "Gain", 0, 0, 0 },

  { 43, "Gain2",
    "Gain", 0, 0, 0 },

  { 44, "Memory",
    "X0", 1, 0, 0 },

  { 45, "Memory1",
    "X0", 1, 0, 0 },

  { 46, "Counter",
    "InitialCount", 2, 0, 0 },

  { 47, "Counter1",
    "InitialCount", 2, 0, 0 },

  { 48, "Counter2",
    "InitialCount", 2, 0, 0 },

  { 49, "PCI-6024E AD",
    "P1", 0, 0, 0 },

  { 50, "PCI-6024E AD",
    "P2", 0, 0, 0 },

  { 51, "PCI-6024E AD",
    "P3", 0, 0, 0 },

  { 52, "PCI-6024E AD",
    "P4", 0, 0, 0 },

  { 53, "PCI-6024E AD",
    "P5", 0, 0, 0 },

  { 54, "PCI-6024E AD",
    "P6", 0, 0, 0 },

  { 55, "PCI-6024E DI",
    "P1", 0, 0, 0 },

  { 56, "PCI-6024E DI",
    "P2", 0, 0, 0 },

  { 57, "PCI-6024E DI",
    "P3", 0, 0, 0 },

  { 58, "PCI-6024E DI",
    "P4", 0, 0, 0 },

  { 59, "PCI-6024E DI",
    "P5", 0, 0, 0 },

  { 60, "PCI-6024E DI1",
    "P1", 0, 0, 0 },

  { 61, "PCI-6024E DI1",
    "P2", 0, 0, 0 },

  { 62, "PCI-6024E DI1",
    "P3", 0, 0, 0 },

  { 63, "PCI-6024E DI1",
    "P4", 0, 0, 0 },

  { 64, "PCI-6024E DI1",
    "P5", 0, 0, 0 },

  { 65, "PCI-6024E DO",
    "P1", 0, 0, 0 },

  { 66, "PCI-6024E DO",
    "P2", 0, 0, 0 },

  { 67, "PCI-6024E DO",
    "P3", 0, 0, 0 },

  { 68, "PCI-6024E DO",
    "P4", 0, 0, 0 },

  { 69, "PCI-6024E DO",
    "P5", 0, 0, 0 },

  { 70, "PCI-6024E DO",
    "P6", 0, 0, 0 },

  { 71, "PCI-6024E DO",
    "P7", 0, 0, 0 },

  { 72, "Uniform Random Number",
    "Minimum", 0, 0, 0 },

  { 73, "Uniform Random Number",
    "Maximum", 0, 0, 0 },

  { 74, "Uniform Random Number",
    "Seed", 0, 0, 0 },

  { 75, "Compare To Zero/Constant",
    "Value", 0, 0, 0 },

  { 76, "Sample and Hold1/ ",
    "InitialOutput", 0, 0, 0 },

  { 77, "Sample and Hold2/ ",
    "InitialOutput", 0, 0, 0 },

  { 78, "Sample and Hold3/ ",
    "InitialOutput", 0, 0, 0 },

  { 79, "J-K Flip-Flop/J-K Flip-Flop/Q",
    "InitialOutput", 1, 0, 0 },

  { 80, "J-K Flip-Flop/J-K Flip-Flop/!Q",
    "InitialOutput", 1, 0, 0 },

  { 81, "J-K Flip-Flop/J-K Flip-Flop/Logic",
    "TruthTable", 1, 2, 0 },

  { 82, "J-K Flip-Flop/J-K Flip-Flop/Memory",
    "X0", 1, 0, 0 },

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
  &speed2_B.DataTypeConversion,        /* 0: Signal */
  &speed2_B.PulseGenerator,            /* 1: Signal */
  &speed2_B.Gain,                      /* 2: Signal */
  &speed2_B.Gain1,                     /* 3: Signal */
  &speed2_B.Gain2,                     /* 4: Signal */
  &speed2_B.Memory,                    /* 5: Signal */
  &speed2_B.Memory1,                   /* 6: Signal */
  &speed2_B.Divide,                    /* 7: Signal */
  &speed2_B.Divide1,                   /* 8: Signal */
  &speed2_B.Divide2,                   /* 9: Signal */
  &speed2_B.Divide3,                   /* 10: Signal */
  &speed2_B.multply,                   /* 11: Signal */
  &speed2_B.multply1,                  /* 12: Signal */
  &speed2_B.Counter,                   /* 13: Signal */
  &speed2_B.Counter1,                  /* 14: Signal */
  &speed2_B.Counter2,                  /* 15: Signal */
  &speed2_B.PCI6024EAD,                /* 16: Signal */
  &speed2_B.PCI6024EDI,                /* 17: Signal */
  &speed2_B.PCI6024EDI1,               /* 18: Signal */
  &speed2_B.Subtract,                  /* 19: Signal */
  &speed2_B.Subtract1,                 /* 20: Signal */
  &speed2_B.Sum,                       /* 21: Signal */
  &speed2_B.UniformRandomNumber,       /* 22: Signal */
  &speed2_B.RateTransition,            /* 23: Signal */
  &speed2_B.Compare,                   /* 24: Signal */
  &speed2_B.SampleandHold1.In,         /* 25: Signal */
  &speed2_B.SampleandHold2.In,         /* 26: Signal */
  &speed2_B.In,                        /* 27: Signal */
  &speed2_B.Logic[0],                  /* 28: Signal */
  &speed2_B.Memory_c,                  /* 29: Signal */
  &speed2_P.rev360degree_Value,        /* 30: Block Parameter */
  &speed2_P.rev360degree1_Value,       /* 31: Block Parameter */
  &speed2_P.ucounts1rev_Value,         /* 32: Block Parameter */
  &speed2_P.ucounts1rev1_Value,        /* 33: Block Parameter */
  &speed2_P.Constant_Value_m,          /* 34: Block Parameter */
  &speed2_P.converstionfactor2131_Value,/* 35: Block Parameter */
  &speed2_P.converstionfactor2132_Value,/* 36: Block Parameter */
  &speed2_P.PulseGenerator_Amp,        /* 37: Block Parameter */
  &speed2_P.PulseGenerator_Period,     /* 38: Block Parameter */
  &speed2_P.PulseGenerator_Duty,       /* 39: Block Parameter */
  &speed2_P.PulseGenerator_PhaseDelay, /* 40: Block Parameter */
  &speed2_P.Gain_Gain,                 /* 41: Block Parameter */
  &speed2_P.Gain1_Gain,                /* 42: Block Parameter */
  &speed2_P.Gain2_Gain,                /* 43: Block Parameter */
  &speed2_P.Memory_X0_c,               /* 44: Block Parameter */
  &speed2_P.Memory1_X0,                /* 45: Block Parameter */
  &speed2_P.Counter_InitialCount,      /* 46: Block Parameter */
  &speed2_P.Counter1_InitialCount,     /* 47: Block Parameter */
  &speed2_P.Counter2_InitialCount,     /* 48: Block Parameter */
  &speed2_P.PCI6024EAD_P1,             /* 49: Block Parameter */
  &speed2_P.PCI6024EAD_P2,             /* 50: Block Parameter */
  &speed2_P.PCI6024EAD_P3,             /* 51: Block Parameter */
  &speed2_P.PCI6024EAD_P4,             /* 52: Block Parameter */
  &speed2_P.PCI6024EAD_P5,             /* 53: Block Parameter */
  &speed2_P.PCI6024EAD_P6,             /* 54: Block Parameter */
  &speed2_P.PCI6024EDI_P1,             /* 55: Block Parameter */
  &speed2_P.PCI6024EDI_P2,             /* 56: Block Parameter */
  &speed2_P.PCI6024EDI_P3,             /* 57: Block Parameter */
  &speed2_P.PCI6024EDI_P4,             /* 58: Block Parameter */
  &speed2_P.PCI6024EDI_P5,             /* 59: Block Parameter */
  &speed2_P.PCI6024EDI1_P1,            /* 60: Block Parameter */
  &speed2_P.PCI6024EDI1_P2,            /* 61: Block Parameter */
  &speed2_P.PCI6024EDI1_P3,            /* 62: Block Parameter */
  &speed2_P.PCI6024EDI1_P4,            /* 63: Block Parameter */
  &speed2_P.PCI6024EDI1_P5,            /* 64: Block Parameter */
  &speed2_P.PCI6024EDO_P1,             /* 65: Block Parameter */
  &speed2_P.PCI6024EDO_P2,             /* 66: Block Parameter */
  &speed2_P.PCI6024EDO_P3,             /* 67: Block Parameter */
  &speed2_P.PCI6024EDO_P4,             /* 68: Block Parameter */
  &speed2_P.PCI6024EDO_P5,             /* 69: Block Parameter */
  &speed2_P.PCI6024EDO_P6,             /* 70: Block Parameter */
  &speed2_P.PCI6024EDO_P7,             /* 71: Block Parameter */
  &speed2_P.UniformRandomNumber_Minimum,/* 72: Block Parameter */
  &speed2_P.UniformRandomNumber_Maximum,/* 73: Block Parameter */
  &speed2_P.UniformRandomNumber_Seed,  /* 74: Block Parameter */
  &speed2_P.Constant_Value,            /* 75: Block Parameter */
  &speed2_P.SampleandHold1._Y0,        /* 76: Block Parameter */
  &speed2_P.SampleandHold2._Y0,        /* 77: Block Parameter */
  &speed2_P._Y0,                       /* 78: Block Parameter */
  &speed2_P.Q_Y0,                      /* 79: Block Parameter */
  &speed2_P.Q_Y0_i,                    /* 80: Block Parameter */
  &speed2_P.Logic_table[0],            /* 81: Block Parameter */
  &speed2_P.Memory_X0                  /* 82: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 }
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

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  2,                                   /* 2 */
  1,                                   /* 3 */
  8,                                   /* 4 */
  2                                    /* 5 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0001, 0.0, 0.001
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
    0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (NULL), (NULL), -1, 0 }
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
  { rtBlockSignals, 30 },

  { rtBlockParameters, 53,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1330278854U,
    1632065287U,
    201435141U,
    626921919U },
  NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void speed2_InitializeDataMapInfo(RT_MODEL_speed2_T *speed2_M
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(speed2_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(speed2_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(speed2_M->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(speed2_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(speed2_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  speed2_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam(speed2_M);
  speed2_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof(P_speed2_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(speed2_M->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(speed2_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(speed2_M->DataMapInfo.mmi, 0);
}

/* EOF: speed2_capi.c */
