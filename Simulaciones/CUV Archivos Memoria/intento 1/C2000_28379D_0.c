/*
 * C-Script file for: C2000_28379D/Control
 * Generated with   : PLECS 4.8.3
 * Generated on     : 21 Aug 2024 10:00:34
 */
typedef float real_t;
#define REAL_MAX FLT_MAX
#define REAL_MIN FLT_MIN
#define REAL_EPSILON FLT_EPSILON
#include <float.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <complex.h>
#include <code.c>
#include <code.h>
#include <variables.c>

/***** Entradas ****/
#define isa Input(0)
#define isb Input(1)
#define isc Input(2)

#define Vc_a Input(3)
#define Vc_b Input(4)
#define Vc_c Input(5)

#define i1a Input(6)
#define i1b Input(7)
#define i1c Input(8)

#define Pot Input(9)

/***** Salidas ****/
#define Out0 Output(0)
#define Out1 Output(1)
#define Out2 Output(2)

#define Out3 Output(3)
#define Out4 Output(4)
#define Out5 Output(5)
#define Out6 Output(6)
#define Out7 Output(7)
#define Out8 Output(8)
#define Out9 Output(9)
#define Out10 Output(10)
#define Out11 Output(11)
#define Out12 Output(12)
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
#define NumInputs cScriptStruct->numInputSignals[0]
#define NumOutputs cScriptStruct->numOutputSignals[0]
#define Input(signalIdx) (*cScriptStruct->inputs[0][signalIdx])
#define Output(signalIdx) (*cScriptStruct->outputs[0][signalIdx])
#define NumInputTerminals cScriptStruct->numInputTerminals
#define NumOutputTerminals cScriptStruct->numOutputTerminals
#define NumInputSignals(terminalIdx) cScriptStruct->numInputSignals[ \
      terminalIdx]
#define NumOutputSignals(terminalIdx) cScriptStruct->numOutputSignals[ \
      terminalIdx]
#define InputSignal(terminalIdx, \
                    signalIdx) (*cScriptStruct->inputs[terminalIdx][signalIdx])
#define OutputSignal(terminalIdx, \
                     signalIdx) (*cScriptStruct->outputs[terminalIdx][ \
                                    signalIdx])
#define NumContStates cScriptStruct->numContStates
#define NumDiscStates cScriptStruct->numDiscStates
#define NumZCSignals cScriptStruct->numZCSignals
#define NumParameters cScriptStruct->numParameters
#define NumSampleTimes cScriptStruct->numSampleTimes
#define IsMajorStep cScriptStruct->isMajorTimeStep
#define CurrentTime cScriptStruct->time
#define NextSampleHit (*cScriptStruct->nextSampleHit)
#define SetErrorMessage(string) { *cScriptStruct->errorStatus=(string); }
#define SetWarningMessage(string)
#define ContState(idx) cScriptStruct->contStates[idx]
#define ContDeriv(idx) cScriptStruct->contDerivs[idx]
#define DiscState(idx) cScriptStruct->discStates[idx]
#define ZCSignal(idx) cScriptStruct->zCSignals[idx]
#define IsSampleHit(idx) (*cScriptStruct->sampleHits[idx])
#define SampleTimePeriod(idx) cScriptStruct->sampleTimePeriods[idx]
#define SampleTimeOffset(idx) cScriptStruct->sampleTimeOffsets[idx]
#define InputSampleTimePeriod(terminalIdx, \
                              signalIdx) cScriptStruct->inputSampleTimePeriods \
   [terminalIdx][signalIdx]
#define InputSampleTimeOffset(terminalIdx, \
                              signalIdx) cScriptStruct->inputSampleTimeOffsets \
   [terminalIdx][signalIdx]
#define ParamNumDims(idx) cScriptStruct->paramNumDims[idx]
#define ParamDim(pIdx, dIdx) cScriptStruct->paramDims[pIdx][dIdx]
#define ParamRealData(pIdx, dIdx) cScriptStruct->paramRealData[pIdx][dIdx]
#define ParamStringData(pIdx) cScriptStruct->paramStringData[pIdx]

void C2000_28379D_0_cScriptStart(const struct CScriptStruct *cScriptStruct)
{
}

void C2000_28379D_0_cScriptOutput(const struct CScriptStruct *cScriptStruct)
{
   Out0=Sa[x_opt];
   Out1=Sb[x_opt];
   Out2=Sc[x_opt];

}

void C2000_28379D_0_cScriptUpdate(const struct CScriptStruct *cScriptStruct)
{
   angle(&theta, h, w, dp);

   Ref(&id_r, &iq_r, &Vcd_r, &Vcq_r, Pot, Vgd_r, Vgq_r, R);

   /************ Vector de corriente medida salida del conv ************/

   abc_dq( &i1d_k, &i1q_k, theta, i1a, i1b, i1c);

   /************ Vector de corriente medida en carga ************/

   abc_dq( &i2d_k, &i2q_k, theta, isa, isb, isc);

   /************ Vector de tension capacitores ************/

   abc_dq( &Vcd, &Vcq, theta, Vc_a, Vc_b, Vc_c);

   /************ Predicción k+1 ************/

   Vabc_dq(&V_d, &V_q, theta, Vdc, Sa[x_opt], Sb[x_opt], Sc[x_opt]); //Tension a la salida del convertidor

   i1p(&i1d_k0, &i1q_k0, h, d1_L1, w, i1d_k, i1q_k, V_d, V_q, Vcd, Vcq);
   Vcp(&Vcd_k0, &Vcq_k0, h, d1_c, w, i1d_k0, i1q_k0, i2d_k, i2q_k, Vcd, Vcq);
   i2p(&i2d_k0, &i2q_k0, i2d_k, i2q_k, Vcd_k0, Vcq_k0, h, w, R, d1_L2, Vgd_r,
       Vgq_r);

   /************ Loop para determinar combinacion optima ************/

   g_opt=1e20;
   for (x=0; x <= 124; x=x+1)
   {

      Vabc_dq(&V_d, &V_q, theta, Vdc, Sa[x], Sb[x], Sc[x]);

      i1p(&i1d_k1, &i1q_k1, h, d1_L1, w, i1d_k0, i1q_k0, V_d, V_q, Vcd_k0,
          Vcq_k0);
      Vcp(&Vcd_k1, &Vcq_k1, h, d1_c, w, i1d_k1, i1q_k1, i2d_k0, i2q_k0,
          Vcd_k0, Vcq_k0);
      i2p(&i2d_k1, &i2q_k1, i2d_k0, i2q_k0, Vcd_k1, Vcq_k1, h, w, R, d1_L2,
          Vgd_r, Vgq_r);

      FC_cuad(&g[x], id_r,  iq_r,  i2d_k1,  i2q_k1);
      FC_cuad(&gv[x], Vcd_r, Vcq_r,  Vcd_k1,  Vcq_k1);
      FC_cuad(&gb[x], id_r,  iq_r,  i1d_k1,  i1q_k1);

      optp(&g_opt, &x_opt, 0.3333*(g[x]+gv[x]+gb[x]), x, Sa[x], Sb[x], Sc[x],
           Sa[x_opt], Sb[x_opt], Sc[x_opt]);                                                                      // actualizar combinacion de switch optima
   }
}

void C2000_28379D_0_cScriptDerivative(
                                      const struct CScriptStruct *cScriptStruct)
{
}

void C2000_28379D_0_cScriptTerminate(const struct CScriptStruct *cScriptStruct)
{
}
