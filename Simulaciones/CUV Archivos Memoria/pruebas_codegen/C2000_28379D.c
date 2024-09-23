/*
 * Implementation file for: Pruebas/C2000_28379D
 * Generated with         : PLECS 4.8.6
 *                          TI2837x 1.7.4
 * Generated on           : 23 Sep 2024 17:50:22
 */
#include "C2000_28379D.h"
#ifndef PLECS_HEADER_C2000_28379D_h_
#error The wrong header file "C2000_28379D.h" was included. Please check
#error your include path to see whether this file name conflicts with the
#error name of another header file.
#endif /* PLECS_HEADER_C2000_28379D_h_ */
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
#define PLECSRunTimeError(msg) C2000_28379D_errorStatus = msg
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
static struct CScriptStruct C2000_28379D_cScriptStruct[1];
static const uint32_t C2000_28379D_subTaskPeriod[1]= {
   /* [0.0002, 0], [0, 0] */
   2
};
static uint32_t C2000_28379D_subTaskTick[1];
static char C2000_28379D_subTaskHit[1];
#define C2000_28379D_UNCONNECTED 0
static uint32_t C2000_28379D_D_uint32_t[6];
void C2000_28379D_0_cScriptStart(const struct CScriptStruct *cScriptStruct);
void C2000_28379D_0_cScriptOutput(const struct CScriptStruct *cScriptStruct);
void C2000_28379D_0_cScriptUpdate(const struct CScriptStruct *cScriptStruct);
void C2000_28379D_0_cScriptDerivative(
                                      const struct CScriptStruct *cScriptStruct);
void C2000_28379D_0_cScriptTerminate(const struct CScriptStruct *cScriptStruct);
static uint32_t C2000_28379D_tickLo;
static int32_t C2000_28379D_tickHi;
C2000_28379D_BlockOutputs C2000_28379D_B;
const char * C2000_28379D_errorStatus;
const float C2000_28379D_sampleTime = 0.0001f;
const char * const C2000_28379D_checksum =
   "269392ed68687ab6c336689561782b2d519cff14";
/* Target declarations */
// tag step function to allow special linking
#pragma CODE_SECTION(C2000_28379D_step, "step")
extern void C2000_28379D_initHal();

void C2000_28379D_initialize(void)
{
   C2000_28379D_tickHi = 0;
   C2000_28379D_tickLo = 0;
   /* Initialize sub-task tick counters */
   C2000_28379D_subTaskTick[0] = 0; /* [0, 0], [0.0002, 0] */


   /* Target pre-initialization */
   C2000_28379D_initHal();


   /* Initialization for C-Script : 'C2000_28379D/Control' */
   {
      static int numInputSignals[] = {
         10
      };
      static const float* inputPtrs[] = {
         &C2000_28379D_B.Sum1[0], &C2000_28379D_B.Sum1[1],
         &C2000_28379D_B.Sum1[2], &C2000_28379D_B.Sum2[0],
         &C2000_28379D_B.Sum2[1], &C2000_28379D_B.Sum2[2],
         &C2000_28379D_B.Sum3[0], &C2000_28379D_B.Sum3[1],
         &C2000_28379D_B.Sum3[2], &C2000_28379D_B.Pot
      };
      static const float** inputs[] = {
         &inputPtrs[0]
      };
      static int numOutputSignals[] = {
         4
      };
      static float* outputPtrs[] = {
         &C2000_28379D_B.Control[0], &C2000_28379D_B.Control[1],
         &C2000_28379D_B.Control[2], &C2000_28379D_B.Control[3]
      };
      static float** outputs[] = {
         &outputPtrs[0]
      };
      static float nextSampleHit;
      static const char * sampleHits[] = {
         &C2000_28379D_subTaskHit[0]
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
      errorStatus = NULL;
      warningStatus = NULL;
      rangeErrorMsg = NULL;
      C2000_28379D_cScriptStruct[0].isMajorTimeStep = 1;
      C2000_28379D_cScriptStruct[0].numInputTerminals = 1;
      C2000_28379D_cScriptStruct[0].numInputSignals = numInputSignals;
      C2000_28379D_cScriptStruct[0].inputs = inputs;
      C2000_28379D_cScriptStruct[0].numOutputTerminals = 1;
      C2000_28379D_cScriptStruct[0].numOutputSignals = numOutputSignals;
      C2000_28379D_cScriptStruct[0].outputs = outputs;
      C2000_28379D_cScriptStruct[0].numContStates = 0;
      C2000_28379D_cScriptStruct[0].contStates = NULL;
      C2000_28379D_cScriptStruct[0].contDerivs = NULL;
      C2000_28379D_cScriptStruct[0].numDiscStates = 0;
      C2000_28379D_cScriptStruct[0].discStates = NULL;
      C2000_28379D_cScriptStruct[0].numZCSignals = 0;
      C2000_28379D_cScriptStruct[0].numParameters = 0;
      C2000_28379D_cScriptStruct[0].paramNumDims = NULL;
      C2000_28379D_cScriptStruct[0].paramDims = NULL;
      C2000_28379D_cScriptStruct[0].paramNumElements = NULL;
      C2000_28379D_cScriptStruct[0].paramRealData = NULL;
      C2000_28379D_cScriptStruct[0].paramStringData = NULL;
      C2000_28379D_cScriptStruct[0].numSampleTimes = 1;
      C2000_28379D_cScriptStruct[0].sampleTimePeriods = sampleTimePeriods;
      C2000_28379D_cScriptStruct[0].sampleTimeOffsets = sampleTimeOffsets;
      C2000_28379D_cScriptStruct[0].inputSampleTimePeriods =
         terminalSampleTimePeriodPtrs;
      C2000_28379D_cScriptStruct[0].inputSampleTimeOffsets =
         terminalSampleTimeOffsetPtrs;
      C2000_28379D_cScriptStruct[0].sampleHits = sampleHits;
      C2000_28379D_cScriptStruct[0].nextSampleHit = &nextSampleHit;
      C2000_28379D_cScriptStruct[0].errorStatus = &errorStatus;
      C2000_28379D_cScriptStruct[0].warningStatus = &warningStatus;
      C2000_28379D_cScriptStruct[0].rangeErrorMsg = &rangeErrorMsg;
      C2000_28379D_0_cScriptStart(&C2000_28379D_cScriptStruct[0]);
      if (*C2000_28379D_cScriptStruct[0].errorStatus)
         C2000_28379D_errorStatus =
            *C2000_28379D_cScriptStruct[0].errorStatus;
   }

   /* Initialization for Triangular Wave Generator : 'C2000_28379D/SW A/Triangular Wave1' */
   C2000_28379D_D_uint32_t[0] = 0;

   /* Initialization for Triangular Wave Generator : 'C2000_28379D/SW A/Triangular Wave2' */
   C2000_28379D_D_uint32_t[1] = 0;

   /* Initialization for Triangular Wave Generator : 'C2000_28379D/SW A1/Triangular Wave1' */
   C2000_28379D_D_uint32_t[2] = 0;

   /* Initialization for Triangular Wave Generator : 'C2000_28379D/SW A1/Triangular Wave2' */
   C2000_28379D_D_uint32_t[3] = 0;

   /* Initialization for Triangular Wave Generator : 'C2000_28379D/SW A2/Triangular Wave1' */
   C2000_28379D_D_uint32_t[4] = 0;

   /* Initialization for Triangular Wave Generator : 'C2000_28379D/SW A2/Triangular Wave2' */
   C2000_28379D_D_uint32_t[5] = 0;
}

void C2000_28379D_step(void)
{
   if (C2000_28379D_errorStatus)
   {
      return;
   }
   {
      size_t i;
      for (i = 0; i < 1; ++i)
      {
         C2000_28379D_subTaskHit[i] = (C2000_28379D_subTaskTick[i] == 0);
      }
   }

   /* Sum : 'C2000_28379D/Sum1'
    * incorporates
    *  ADC : 'C2000_28379D/i2'
    *  Constant : 'C2000_28379D/Constant1'
    */
   C2000_28379D_B.Sum1[0] = (PLXHAL_ADC_getIn(0, 0)) + (-500.f);
   C2000_28379D_B.Sum1[1] = (PLXHAL_ADC_getIn(0, 1)) + (-500.f);
   C2000_28379D_B.Sum1[2] = (PLXHAL_ADC_getIn(0, 2)) + (-500.f);

   /* Sum : 'C2000_28379D/Sum2'
    * incorporates
    *  ADC : 'C2000_28379D/Vc'
    *  Constant : 'C2000_28379D/Constant2'
    */
   C2000_28379D_B.Sum2[0] = (PLXHAL_ADC_getIn(1, 0)) + (-300.f);
   C2000_28379D_B.Sum2[1] = (PLXHAL_ADC_getIn(1, 1)) + (-300.f);
   C2000_28379D_B.Sum2[2] = (PLXHAL_ADC_getIn(1, 2)) + (-300.f);

   /* Sum : 'C2000_28379D/Sum3'
    * incorporates
    *  ADC : 'C2000_28379D/i1'
    *  Constant : 'C2000_28379D/Constant3'
    */
   C2000_28379D_B.Sum3[0] = (PLXHAL_ADC_getIn(2, 0)) + (-500.f);
   C2000_28379D_B.Sum3[1] = (PLXHAL_ADC_getIn(2, 1)) + (-500.f);
   C2000_28379D_B.Sum3[2] = (PLXHAL_ADC_getIn(2, 2)) + (-500.f);

   /* ADC : 'C2000_28379D/Pot' */
   C2000_28379D_B.Pot = PLXHAL_ADC_getIn(3, 0);
   if (C2000_28379D_subTaskHit[0])
   {
      /* C-Script : 'C2000_28379D/Control' */
      C2000_28379D_0_cScriptOutput(&C2000_28379D_cScriptStruct[0]);
      if (*C2000_28379D_cScriptStruct[0].errorStatus)
         C2000_28379D_errorStatus =
            *C2000_28379D_cScriptStruct[0].errorStatus;
   }

   /* DAC : 'C2000_28379D/DAC' */
   PLXHAL_DAC_set(0, C2000_28379D_B.Control[3]);

   /* Triangular Wave Generator : 'C2000_28379D/SW A/Triangular Wave1' */
   {
      float frac;
      if (C2000_28379D_D_uint32_t[0] < 1)
      {
         frac = C2000_28379D_D_uint32_t[0]*((float)1/1);
      }
      else
      {
         frac = 1-(C2000_28379D_D_uint32_t[0]-1)*((float)1/1);
      }
      C2000_28379D_B.TriangularWave1 = 1e-05f+0.99999f*frac;
   }

   /* Triangular Wave Generator : 'C2000_28379D/SW A/Triangular Wave2' */
   {
      float frac;
      if (C2000_28379D_D_uint32_t[1] < 1)
      {
         frac = C2000_28379D_D_uint32_t[1]*((float)1/1);
      }
      else
      {
         frac = 1-(C2000_28379D_D_uint32_t[1]-1)*((float)1/1);
      }
      C2000_28379D_B.TriangularWave2 = -1.f+0.999999f*frac;
   }

   /* Function : 'C2000_28379D/SW A/Fcn'
    * incorporates
    *  Relational Operator : 'C2000_28379D/SW A/Relational\nOperator5'
    *  Relational Operator : 'C2000_28379D/SW A/Relational\nOperator6'
    */
   C2000_28379D_B.Fcn =
      ((1.f) *
    ((float)(C2000_28379D_B.Control[0] >=
             C2000_28379D_B.TriangularWave1)))-
      ((1.f) *
    ((float)(C2000_28379D_B.Control[0] <= C2000_28379D_B.TriangularWave2)));
   /* Digital Out : 'C2000_28379D/Sa1' */
   PLXHAL_DIO_set(0, C2000_28379D_B.Fcn > 0.f);
   /* Digital Out : 'C2000_28379D/Sa2' */
   PLXHAL_DIO_set(1, C2000_28379D_B.Fcn == 0.f);
   /* Digital Out : 'C2000_28379D/Sa4' */
   PLXHAL_DIO_set(2, C2000_28379D_B.Fcn < 0.f);

   /* Triangular Wave Generator : 'C2000_28379D/SW A1/Triangular Wave1' */
   {
      float frac;
      if (C2000_28379D_D_uint32_t[2] < 1)
      {
         frac = C2000_28379D_D_uint32_t[2]*((float)1/1);
      }
      else
      {
         frac = 1-(C2000_28379D_D_uint32_t[2]-1)*((float)1/1);
      }
      C2000_28379D_B.TriangularWave1_1 = 1e-05f+0.99999f*frac;
   }

   /* Triangular Wave Generator : 'C2000_28379D/SW A1/Triangular Wave2' */
   {
      float frac;
      if (C2000_28379D_D_uint32_t[3] < 1)
      {
         frac = C2000_28379D_D_uint32_t[3]*((float)1/1);
      }
      else
      {
         frac = 1-(C2000_28379D_D_uint32_t[3]-1)*((float)1/1);
      }
      C2000_28379D_B.TriangularWave2_1 = -1.f+0.999999f*frac;
   }

   /* Function : 'C2000_28379D/SW A1/Fcn'
    * incorporates
    *  Relational Operator : 'C2000_28379D/SW A1/Relational\nOperator5'
    *  Relational Operator : 'C2000_28379D/SW A1/Relational\nOperator6'
    */
   C2000_28379D_B.Fcn_1 =
      ((1.f) *
    ((float)(C2000_28379D_B.Control[1] >=
             C2000_28379D_B.TriangularWave1_1)))-
      ((1.f) *
    ((float)(C2000_28379D_B.Control[1] <= C2000_28379D_B.TriangularWave2_1)));
   /* Digital Out : 'C2000_28379D/Sb1' */
   PLXHAL_DIO_set(3, C2000_28379D_B.Fcn_1 > 0.f);
   /* Digital Out : 'C2000_28379D/Sb2' */
   PLXHAL_DIO_set(4, C2000_28379D_B.Fcn_1 == 0.f);
   /* Digital Out : 'C2000_28379D/Sb4' */
   PLXHAL_DIO_set(5, C2000_28379D_B.Fcn_1 < 0.f);

   /* Triangular Wave Generator : 'C2000_28379D/SW A2/Triangular Wave1' */
   {
      float frac;
      if (C2000_28379D_D_uint32_t[4] < 1)
      {
         frac = C2000_28379D_D_uint32_t[4]*((float)1/1);
      }
      else
      {
         frac = 1-(C2000_28379D_D_uint32_t[4]-1)*((float)1/1);
      }
      C2000_28379D_B.TriangularWave1_2 = 1e-05f+0.99999f*frac;
   }

   /* Triangular Wave Generator : 'C2000_28379D/SW A2/Triangular Wave2' */
   {
      float frac;
      if (C2000_28379D_D_uint32_t[5] < 1)
      {
         frac = C2000_28379D_D_uint32_t[5]*((float)1/1);
      }
      else
      {
         frac = 1-(C2000_28379D_D_uint32_t[5]-1)*((float)1/1);
      }
      C2000_28379D_B.TriangularWave2_2 = -1.f+0.999999f*frac;
   }

   /* Function : 'C2000_28379D/SW A2/Fcn'
    * incorporates
    *  Relational Operator : 'C2000_28379D/SW A2/Relational\nOperator5'
    *  Relational Operator : 'C2000_28379D/SW A2/Relational\nOperator6'
    */
   C2000_28379D_B.Fcn_2 =
      ((1.f) *
    ((float)(C2000_28379D_B.Control[2] >=
             C2000_28379D_B.TriangularWave1_2)))-
      ((1.f) *
    ((float)(C2000_28379D_B.Control[2] <= C2000_28379D_B.TriangularWave2_2)));
   /* Digital Out : 'C2000_28379D/Sc1' */
   PLXHAL_DIO_set(6, C2000_28379D_B.Fcn_2 > 0.f);
   /* Digital Out : 'C2000_28379D/Sc2' */
   PLXHAL_DIO_set(7, C2000_28379D_B.Fcn_2 == 0.f);
   /* Digital Out : 'C2000_28379D/Sc4' */
   PLXHAL_DIO_set(8, C2000_28379D_B.Fcn_2 < 0.f);
   if (C2000_28379D_errorStatus)
   {
      return;
   }
   if (C2000_28379D_subTaskHit[0])
   {
      /* Update for C-Script : 'C2000_28379D/Control' */
      C2000_28379D_0_cScriptUpdate(&C2000_28379D_cScriptStruct[0]);
      if (*C2000_28379D_cScriptStruct[0].errorStatus)
         C2000_28379D_errorStatus =
            *C2000_28379D_cScriptStruct[0].errorStatus;
   }
   /* Update for Triangular Wave Generator : 'C2000_28379D/SW A/Triangular Wave1' */
   C2000_28379D_D_uint32_t[0] += 1;
   if (C2000_28379D_D_uint32_t[0] > 1)
   {
      C2000_28379D_D_uint32_t[0] -= 2;
   }

   /* Update for Triangular Wave Generator : 'C2000_28379D/SW A/Triangular Wave2' */
   C2000_28379D_D_uint32_t[1] += 1;
   if (C2000_28379D_D_uint32_t[1] > 1)
   {
      C2000_28379D_D_uint32_t[1] -= 2;
   }

   /* Update for Triangular Wave Generator : 'C2000_28379D/SW A1/Triangular Wave1' */
   C2000_28379D_D_uint32_t[2] += 1;
   if (C2000_28379D_D_uint32_t[2] > 1)
   {
      C2000_28379D_D_uint32_t[2] -= 2;
   }

   /* Update for Triangular Wave Generator : 'C2000_28379D/SW A1/Triangular Wave2' */
   C2000_28379D_D_uint32_t[3] += 1;
   if (C2000_28379D_D_uint32_t[3] > 1)
   {
      C2000_28379D_D_uint32_t[3] -= 2;
   }

   /* Update for Triangular Wave Generator : 'C2000_28379D/SW A2/Triangular Wave1' */
   C2000_28379D_D_uint32_t[4] += 1;
   if (C2000_28379D_D_uint32_t[4] > 1)
   {
      C2000_28379D_D_uint32_t[4] -= 2;
   }

   /* Update for Triangular Wave Generator : 'C2000_28379D/SW A2/Triangular Wave2' */
   C2000_28379D_D_uint32_t[5] += 1;
   if (C2000_28379D_D_uint32_t[5] > 1)
   {
      C2000_28379D_D_uint32_t[5] -= 2;
   }
   /* Increment sub-task tick counters */
   {
      size_t i;
      for (i = 0; i < 1; ++i)
      {
         C2000_28379D_subTaskTick[i]++;
         if (C2000_28379D_subTaskTick[i] >= C2000_28379D_subTaskPeriod[i])
         {
            C2000_28379D_subTaskTick[i] = 0;
         }
      }
   }
}

void C2000_28379D_terminate(void)
{
   /* Termination for C-Script : 'C2000_28379D/Control' */
   C2000_28379D_0_cScriptTerminate(&C2000_28379D_cScriptStruct[0]);
   if (*C2000_28379D_cScriptStruct[0].errorStatus)
      C2000_28379D_errorStatus = *C2000_28379D_cScriptStruct[0].errorStatus;
}
