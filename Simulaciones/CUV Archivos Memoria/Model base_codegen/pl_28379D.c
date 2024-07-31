/*
 * Implementation file for: Model base/28379D
 * Generated with         : PLECS 4.8.3
 *                          TI2837x 1.7.4
 * Generated on           : 26 Jul 2024 13:15:47
 */
#include "pl_28379D.h"
#ifndef PLECS_HEADER_pl_28379D_h_
#error The wrong header file "pl_28379D.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_pl_28379D_h_ */
#if defined(__GNUC__) && (__GNUC__ > 4)
#   define _ALIGNMENT 16
#   define _RESTRICT __restrict
#   define _ALIGN __attribute__((aligned(_ALIGNMENT)))
#   if defined(__clang__)
#      if __has_builtin(__builtin_assume_aligned)
#         define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#      else
#         define _ASSUME_ALIGNED(a) a
#      endif
#   else
#      define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#   endif
#else
#   ifndef _RESTRICT
#      define _RESTRICT
#   endif
#   ifndef _ALIGN
#      define _ALIGN
#   endif
#   ifndef _ASSUME_ALIGNED
#      define _ASSUME_ALIGNED(a) a
#   endif
#endif
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "plx_hal.h"
#include <stdlib.h>
#define PLECSRunTimeError(msg) pl_28379D_errorStatus = msg
struct CScriptStruct
{
   int numInputTerminals;
   int numOutputTerminals;
   int* numInputSignals;
   int* numOutputSignals;
   int numContStates;
   int numDiscStates;
   int numZCSignals;
   int numSampleTimes;
   int numParameters;
   int isMajorTimeStep;
   float time;
   const float ***inputs;
   float ***outputs;
   float *contStates;
   float *contDerivs;
   float *discStates;
   float *zCSignals;
   const int *paramNumDims;
   const int **paramDims;
   const int *paramNumElements;
   const float **paramRealData;
   const char **paramStringData;
   const char * const *sampleHits;
   const float *sampleTimePeriods;
   const float *sampleTimeOffsets;
   const float * const *inputSampleTimePeriods;
   const float * const *inputSampleTimeOffsets;
   float *nextSampleHit;
   const char** errorStatus;
   const char** warningStatus;
   const char** rangeErrorMsg;
   int* rangeErrorLine;
   void (*writeCustomStateDouble)(void*, float);
   float (*readCustomStateDouble)(void*);
   void (*writeCustomStateInt)(void*, int);
   void (*writeCustomStateData)(void*, const void*, int);
   void (*readCustomStateData)(void*, void*, int);
};
static struct CScriptStruct pl_28379D_cScriptStruct[1];
static const uint32_t pl_28379D_subTaskPeriod[1]= {
   /* [0.0002, 0], [0, 0] */
   2
};
static uint32_t pl_28379D_subTaskTick[1];
static char pl_28379D_subTaskHit[1];
#define pl_28379D_UNCONNECTED 0
static uint32_t pl_28379D_D_uint32_t[6];
void pl_28379D_0_cScriptStart(const struct CScriptStruct *cScriptStruct);
void pl_28379D_0_cScriptOutput(const struct CScriptStruct *cScriptStruct);
void pl_28379D_0_cScriptUpdate(const struct CScriptStruct *cScriptStruct);
void pl_28379D_0_cScriptDerivative(const struct CScriptStruct *cScriptStruct);
void pl_28379D_0_cScriptTerminate(const struct CScriptStruct *cScriptStruct);
static uint32_t pl_28379D_tickLo;
static int32_t pl_28379D_tickHi;
pl_28379D_BlockOutputs pl_28379D_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
const float * const pl_28379D_ExtModeSignals[] = {
   &pl_28379D_B.ControlCorriente[0],
   &pl_28379D_B.ControlCorriente[1],
   &pl_28379D_B.ControlCorriente[2],
   &pl_28379D_B.ControlCorriente[3],
   &pl_28379D_B.ControlCorriente[4],
   &pl_28379D_B.ControlCorriente[5],
   &pl_28379D_B.ControlCorriente[6],
   &pl_28379D_B.ControlCorriente[7],
   &pl_28379D_B.ControlCorriente[8],
   &pl_28379D_B.ControlCorriente[9],
   &pl_28379D_B.ControlCorriente[10],
   &pl_28379D_B.ControlCorriente[11],
   &pl_28379D_B.ControlCorriente[12]
};
#endif /* defined(EXTERNAL_MODE) */
const char * pl_28379D_errorStatus;
const float pl_28379D_sampleTime = 0.0001f;
const char * const pl_28379D_checksum =
   "e51c5ef3d2e0ea8c1f0351d9285da216649e12ae";
/* Target declarations */
// tag step function to allow special linking
#pragma CODE_SECTION(pl_28379D_step, "step")
extern void pl_28379D_initHal();

void pl_28379D_initialize(void)
{
   pl_28379D_tickHi = 0;
   pl_28379D_tickLo = 0;
   /* Initialize sub-task tick counters */
   pl_28379D_subTaskTick[0] = 0;    /* [0, 0], [0.0002, 0] */


   /* Target pre-initialization */
   pl_28379D_initHal();


   /* Initialization for C-Script : '28379D/Control Corriente' */
   {
      static int numInputSignals[] = {
         10
      };
      static const float* inputPtrs[] = {
         &pl_28379D_B.i2[0], &pl_28379D_B.i2[1], &pl_28379D_B.i2[2],
         &pl_28379D_B.Vc[0], &pl_28379D_B.Vc[1], &pl_28379D_B.Vc[2],
         &pl_28379D_B.i1[0], &pl_28379D_B.i1[1], &pl_28379D_B.i1[2],
         &pl_28379D_B.Pot
      };
      static const float** inputs[] = {
         &inputPtrs[0]
      };
      static int numOutputSignals[] = {
         13
      };
      static float* outputPtrs[] = {
         &pl_28379D_B.ControlCorriente[0], &pl_28379D_B.ControlCorriente[1],
         &pl_28379D_B.ControlCorriente[2], &pl_28379D_B.ControlCorriente[3],
         &pl_28379D_B.ControlCorriente[4], &pl_28379D_B.ControlCorriente[5],
         &pl_28379D_B.ControlCorriente[6], &pl_28379D_B.ControlCorriente[7],
         &pl_28379D_B.ControlCorriente[8], &pl_28379D_B.ControlCorriente[9],
         &pl_28379D_B.ControlCorriente[10], &pl_28379D_B.ControlCorriente[11],
         &pl_28379D_B.ControlCorriente[12]
      };
      static float** outputs[] = {
         &outputPtrs[0]
      };
      static float nextSampleHit;
      static const char * sampleHits[] = {
         &pl_28379D_subTaskHit[0]
      };
      static float sampleTimePeriods[] = {
         0.0002
      };
      static float sampleTimeOffsets[] = {
         0
      };
      static float terminalSampleTimePeriods[] = {
         0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f
      };
      static float terminalSampleTimeOffsets[] = {
         -1.f, -1.f, -1.f, -1.f, -1.f, -1.f, -1.f, -1.f, -1.f, -1.f
      };
      static const float* terminalSampleTimePeriodPtrs[] = {
         &terminalSampleTimePeriods[0]
      };
      static const float* terminalSampleTimeOffsetPtrs[] = {
         &terminalSampleTimeOffsets[0]
      };
      static const char* errorStatus;
      static const char* warningStatus;
      static const char* rangeErrorMsg;
      static const float paramData[] = {
         0.0002f,800.f,0.001f,314.1593f,1000.f,0.f,0.001422f,0.000142f,
         0.000329f,2137492.04f,7042.25352f,10000.f,220.f,0.f,703.23488f,
         3039.51368f
      };
      static const float* paramDataPtr[] = {
         paramData+0,paramData+1,paramData+2,paramData+3,paramData+4,
         paramData+5,paramData+6,paramData+7,paramData+8,paramData+9,
         paramData+10,paramData+11,paramData+12,paramData+13,paramData+14,
         paramData+15
      };
      static const char paramStringData[] =
         "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
      static const char* paramStringDataPtr[] = {
         paramStringData+0,paramStringData+1,paramStringData+2,
         paramStringData+3,paramStringData+4,paramStringData+5,
         paramStringData+6,paramStringData+7,paramStringData+8,
         paramStringData+9,paramStringData+10,paramStringData+11,
         paramStringData+12,paramStringData+13,paramStringData+14,
         paramStringData+15
      };
      static const int paramDim[] = {
         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      };
      static const int* paramDimPtr[] = {
         paramDim+0,paramDim+2,paramDim+4,paramDim+6,paramDim+8,paramDim+10,
         paramDim+12,paramDim+14,paramDim+16,paramDim+18,paramDim+20,paramDim+
         22,paramDim+24,paramDim+26,paramDim+28,paramDim+30
      };
      static const int paramNumElements[] = {
         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      };
      static const int paramNumDims[] = {
         2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
      };
      errorStatus = NULL;
      warningStatus = NULL;
      rangeErrorMsg = NULL;
      pl_28379D_cScriptStruct[0].isMajorTimeStep = 1;
      pl_28379D_cScriptStruct[0].numInputTerminals = 1;
      pl_28379D_cScriptStruct[0].numInputSignals = numInputSignals;
      pl_28379D_cScriptStruct[0].inputs = inputs;
      pl_28379D_cScriptStruct[0].numOutputTerminals = 1;
      pl_28379D_cScriptStruct[0].numOutputSignals = numOutputSignals;
      pl_28379D_cScriptStruct[0].outputs = outputs;
      pl_28379D_cScriptStruct[0].numContStates = 0;
      pl_28379D_cScriptStruct[0].contStates = NULL;
      pl_28379D_cScriptStruct[0].contDerivs = NULL;
      pl_28379D_cScriptStruct[0].numDiscStates = 0;
      pl_28379D_cScriptStruct[0].discStates = NULL;
      pl_28379D_cScriptStruct[0].numZCSignals = 0;
      pl_28379D_cScriptStruct[0].numParameters = 16;
      pl_28379D_cScriptStruct[0].paramNumDims = paramNumDims;
      pl_28379D_cScriptStruct[0].paramDims = paramDimPtr;
      pl_28379D_cScriptStruct[0].paramNumElements = paramNumElements;
      pl_28379D_cScriptStruct[0].paramRealData = paramDataPtr;
      pl_28379D_cScriptStruct[0].paramStringData = paramStringDataPtr;
      pl_28379D_cScriptStruct[0].numSampleTimes = 1;
      pl_28379D_cScriptStruct[0].sampleTimePeriods = sampleTimePeriods;
      pl_28379D_cScriptStruct[0].sampleTimeOffsets = sampleTimeOffsets;
      pl_28379D_cScriptStruct[0].inputSampleTimePeriods =
         terminalSampleTimePeriodPtrs;
      pl_28379D_cScriptStruct[0].inputSampleTimeOffsets =
         terminalSampleTimeOffsetPtrs;
      pl_28379D_cScriptStruct[0].sampleHits = sampleHits;
      pl_28379D_cScriptStruct[0].nextSampleHit = &nextSampleHit;
      pl_28379D_cScriptStruct[0].errorStatus = &errorStatus;
      pl_28379D_cScriptStruct[0].warningStatus = &warningStatus;
      pl_28379D_cScriptStruct[0].rangeErrorMsg = &rangeErrorMsg;
      pl_28379D_0_cScriptStart(&pl_28379D_cScriptStruct[0]);
      if (*pl_28379D_cScriptStruct[0].errorStatus)
         pl_28379D_errorStatus = *pl_28379D_cScriptStruct[0].errorStatus;
   }

   /* Initialization for Triangular Wave Generator : '28379D/Switch/SW A/Triangular Wave1' */
   pl_28379D_D_uint32_t[0] = 0;

   /* Initialization for Triangular Wave Generator : '28379D/Switch/SW A/Triangular Wave2' */
   pl_28379D_D_uint32_t[1] = 0;

   /* Initialization for Triangular Wave Generator : '28379D/Switch/SW A1/Triangular Wave1' */
   pl_28379D_D_uint32_t[2] = 0;

   /* Initialization for Triangular Wave Generator : '28379D/Switch/SW A1/Triangular Wave2' */
   pl_28379D_D_uint32_t[3] = 0;

   /* Initialization for Triangular Wave Generator : '28379D/Switch/SW A2/Triangular Wave1' */
   pl_28379D_D_uint32_t[4] = 0;

   /* Initialization for Triangular Wave Generator : '28379D/Switch/SW A2/Triangular Wave2' */
   pl_28379D_D_uint32_t[5] = 0;
}

void pl_28379D_step(void)
{
   if (pl_28379D_errorStatus)
   {
      return;
   }
   {
      size_t i;
      for (i = 0; i < 1; ++i)
      {
         pl_28379D_subTaskHit[i] = (pl_28379D_subTaskTick[i] == 0);
      }
   }

   /* ADC : '28379D/i2' */
   pl_28379D_B.i2[0] = PLXHAL_ADC_getIn(0, 0);
   pl_28379D_B.i2[1] = PLXHAL_ADC_getIn(0, 1);
   pl_28379D_B.i2[2] = PLXHAL_ADC_getIn(0, 2);

   /* ADC : '28379D/Vc' */
   pl_28379D_B.Vc[0] = PLXHAL_ADC_getIn(1, 0);
   pl_28379D_B.Vc[1] = PLXHAL_ADC_getIn(1, 1);
   pl_28379D_B.Vc[2] = PLXHAL_ADC_getIn(1, 2);

   /* ADC : '28379D/i1' */
   pl_28379D_B.i1[0] = PLXHAL_ADC_getIn(2, 0);
   pl_28379D_B.i1[1] = PLXHAL_ADC_getIn(2, 1);
   pl_28379D_B.i1[2] = PLXHAL_ADC_getIn(2, 2);

   /* ADC : '28379D/Pot' */
   pl_28379D_B.Pot = PLXHAL_ADC_getIn(3, 0);
   if (pl_28379D_subTaskHit[0])
   {
      /* C-Script : '28379D/Control Corriente' */
      pl_28379D_0_cScriptOutput(&pl_28379D_cScriptStruct[0]);
      if (*pl_28379D_cScriptStruct[0].errorStatus)
         pl_28379D_errorStatus = *pl_28379D_cScriptStruct[0].errorStatus;
   }
   /* Triangular Wave Generator : '28379D/Switch/SW A/Triangular Wave1' */
   {
      float frac;
      if (pl_28379D_D_uint32_t[0] < 1)
      {
         frac = pl_28379D_D_uint32_t[0]*((float)1/1);
      }
      else
      {
         frac = 1-(pl_28379D_D_uint32_t[0]-1)*((float)1/1);
      }
      pl_28379D_B.TriangularWave1 = 1e-05f+0.99999f*frac;
   }

   /* Triangular Wave Generator : '28379D/Switch/SW A/Triangular Wave2' */
   {
      float frac;
      if (pl_28379D_D_uint32_t[1] < 1)
      {
         frac = pl_28379D_D_uint32_t[1]*((float)1/1);
      }
      else
      {
         frac = 1-(pl_28379D_D_uint32_t[1]-1)*((float)1/1);
      }
      pl_28379D_B.TriangularWave2 = -1.f+0.999999f*frac;
   }

   /* Function : '28379D/Switch/SW A/Fcn'
    * incorporates
    *  Relational Operator : '28379D/Switch/SW A/Relational\nOperator5'
    *  Relational Operator : '28379D/Switch/SW A/Relational\nOperator6'
    */
   pl_28379D_B.Fcn =
      ((1.f) *
       ((float)(pl_28379D_B.ControlCorriente[0] >=
                pl_28379D_B.TriangularWave1)))-
      ((1.f) *
       ((float)(pl_28379D_B.ControlCorriente[0] <=
                pl_28379D_B.TriangularWave2)));
   /* Digital Out : '28379D/Sa1' */
   PLXHAL_DIO_set(0, pl_28379D_B.Fcn > 0.f);
   /* Digital Out : '28379D/Sa2' */
   PLXHAL_DIO_set(1, pl_28379D_B.Fcn == 0.f);
   /* Digital Out : '28379D/Sa4' */
   PLXHAL_DIO_set(2, pl_28379D_B.Fcn < 0.f);

   /* Triangular Wave Generator : '28379D/Switch/SW A1/Triangular Wave1' */
   {
      float frac;
      if (pl_28379D_D_uint32_t[2] < 1)
      {
         frac = pl_28379D_D_uint32_t[2]*((float)1/1);
      }
      else
      {
         frac = 1-(pl_28379D_D_uint32_t[2]-1)*((float)1/1);
      }
      pl_28379D_B.TriangularWave1_1 = 1e-05f+0.99999f*frac;
   }

   /* Triangular Wave Generator : '28379D/Switch/SW A1/Triangular Wave2' */
   {
      float frac;
      if (pl_28379D_D_uint32_t[3] < 1)
      {
         frac = pl_28379D_D_uint32_t[3]*((float)1/1);
      }
      else
      {
         frac = 1-(pl_28379D_D_uint32_t[3]-1)*((float)1/1);
      }
      pl_28379D_B.TriangularWave2_1 = -1.f+0.999999f*frac;
   }

   /* Function : '28379D/Switch/SW A1/Fcn'
    * incorporates
    *  Relational Operator : '28379D/Switch/SW A1/Relational\nOperator5'
    *  Relational Operator : '28379D/Switch/SW A1/Relational\nOperator6'
    */
   pl_28379D_B.Fcn_1 =
      ((1.f) *
       ((float)(pl_28379D_B.ControlCorriente[1] >=
                pl_28379D_B.TriangularWave1_1)))-
      ((1.f) *
       ((float)(pl_28379D_B.ControlCorriente[1] <=
                pl_28379D_B.TriangularWave2_1)));
   /* Digital Out : '28379D/Sb1' */
   PLXHAL_DIO_set(3, pl_28379D_B.Fcn_1 > 0.f);
   /* Digital Out : '28379D/Sb2' */
   PLXHAL_DIO_set(4, pl_28379D_B.Fcn_1 == 0.f);
   /* Digital Out : '28379D/Sb4' */
   PLXHAL_DIO_set(5, pl_28379D_B.Fcn_1 < 0.f);

   /* Triangular Wave Generator : '28379D/Switch/SW A2/Triangular Wave1' */
   {
      float frac;
      if (pl_28379D_D_uint32_t[4] < 1)
      {
         frac = pl_28379D_D_uint32_t[4]*((float)1/1);
      }
      else
      {
         frac = 1-(pl_28379D_D_uint32_t[4]-1)*((float)1/1);
      }
      pl_28379D_B.TriangularWave1_2 = 1e-05f+0.99999f*frac;
   }

   /* Triangular Wave Generator : '28379D/Switch/SW A2/Triangular Wave2' */
   {
      float frac;
      if (pl_28379D_D_uint32_t[5] < 1)
      {
         frac = pl_28379D_D_uint32_t[5]*((float)1/1);
      }
      else
      {
         frac = 1-(pl_28379D_D_uint32_t[5]-1)*((float)1/1);
      }
      pl_28379D_B.TriangularWave2_2 = -1.f+0.999999f*frac;
   }

   /* Function : '28379D/Switch/SW A2/Fcn'
    * incorporates
    *  Relational Operator : '28379D/Switch/SW A2/Relational\nOperator5'
    *  Relational Operator : '28379D/Switch/SW A2/Relational\nOperator6'
    */
   pl_28379D_B.Fcn_2 =
      ((1.f) *
       ((float)(pl_28379D_B.ControlCorriente[2] >=
                pl_28379D_B.TriangularWave1_2)))-
      ((1.f) *
       ((float)(pl_28379D_B.ControlCorriente[2] <=
                pl_28379D_B.TriangularWave2_2)));
   /* Digital Out : '28379D/Sc1' */
   PLXHAL_DIO_set(6, pl_28379D_B.Fcn_2 > 0.f);
   /* Digital Out : '28379D/Sc2' */
   PLXHAL_DIO_set(7, pl_28379D_B.Fcn_2 == 0.f);
   /* Digital Out : '28379D/Sc4' */
   PLXHAL_DIO_set(8, pl_28379D_B.Fcn_2 < 0.f);
   if (pl_28379D_errorStatus)
   {
      return;
   }
   if (pl_28379D_subTaskHit[0])
   {
      /* Update for C-Script : '28379D/Control Corriente' */
      pl_28379D_0_cScriptUpdate(&pl_28379D_cScriptStruct[0]);
      if (*pl_28379D_cScriptStruct[0].errorStatus)
         pl_28379D_errorStatus = *pl_28379D_cScriptStruct[0].errorStatus;
   }
   /* Update for Triangular Wave Generator : '28379D/Switch/SW A/Triangular Wave1' */
   pl_28379D_D_uint32_t[0] += 1;
   if (pl_28379D_D_uint32_t[0] > 1)
   {
      pl_28379D_D_uint32_t[0] -= 2;
   }

   /* Update for Triangular Wave Generator : '28379D/Switch/SW A/Triangular Wave2' */
   pl_28379D_D_uint32_t[1] += 1;
   if (pl_28379D_D_uint32_t[1] > 1)
   {
      pl_28379D_D_uint32_t[1] -= 2;
   }

   /* Update for Triangular Wave Generator : '28379D/Switch/SW A1/Triangular Wave1' */
   pl_28379D_D_uint32_t[2] += 1;
   if (pl_28379D_D_uint32_t[2] > 1)
   {
      pl_28379D_D_uint32_t[2] -= 2;
   }

   /* Update for Triangular Wave Generator : '28379D/Switch/SW A1/Triangular Wave2' */
   pl_28379D_D_uint32_t[3] += 1;
   if (pl_28379D_D_uint32_t[3] > 1)
   {
      pl_28379D_D_uint32_t[3] -= 2;
   }

   /* Update for Triangular Wave Generator : '28379D/Switch/SW A2/Triangular Wave1' */
   pl_28379D_D_uint32_t[4] += 1;
   if (pl_28379D_D_uint32_t[4] > 1)
   {
      pl_28379D_D_uint32_t[4] -= 2;
   }

   /* Update for Triangular Wave Generator : '28379D/Switch/SW A2/Triangular Wave2' */
   pl_28379D_D_uint32_t[5] += 1;
   if (pl_28379D_D_uint32_t[5] > 1)
   {
      pl_28379D_D_uint32_t[5] -= 2;
   }
   /* Increment sub-task tick counters */
   {
      size_t i;
      for (i = 0; i < 1; ++i)
      {
         pl_28379D_subTaskTick[i]++;
         if (pl_28379D_subTaskTick[i] >= pl_28379D_subTaskPeriod[i])
         {
            pl_28379D_subTaskTick[i] = 0;
         }
      }
   }
}

void pl_28379D_terminate(void)
{
   /* Termination for C-Script : '28379D/Control Corriente' */
   pl_28379D_0_cScriptTerminate(&pl_28379D_cScriptStruct[0]);
   if (*pl_28379D_cScriptStruct[0].errorStatus)
      pl_28379D_errorStatus = *pl_28379D_cScriptStruct[0].errorStatus;
}
