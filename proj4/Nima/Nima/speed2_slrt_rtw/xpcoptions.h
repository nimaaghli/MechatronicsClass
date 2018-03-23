#ifndef __speed2_XPCOPTIONS_H___
#define __speed2_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "speed2.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_speed2_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            128
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0

/* Change all stepsize using the newBaseRateStepSize */
void speed2_ChangeStepSize(real_T newBaseRateStepSize, RT_MODEL_speed2_T *const
  speed2_M)
{
  real_T ratio = newBaseRateStepSize / 0.0001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  speed2_M->Timing.stepSize0 = speed2_M->Timing.stepSize0 * ratio;
  speed2_M->Timing.stepSize1 = speed2_M->Timing.stepSize1 * ratio;
  speed2_M->Timing.stepSize = speed2_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  speed2_ChangeStepSize(stepSize, speed2_M);
}

#endif                                 /* __speed2_XPCOPTIONS_H___ */
