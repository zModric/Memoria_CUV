/*
 * C-Script file for: C2000_28379D/Control
 * Generated with   : PLECS 4.8.6
 * Generated on     : 24 Sep 2024 11:48:29
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

const float Vgd_r=220;
const float Vgq_r=0;
float V_d=0, V_q=0;
float Vcd=0, Vcd_k0=0, Vcd_k1=0;
float Vcq=0, Vcq_k0=0, Vcq_k1=0;
float i2d_k=0, i2d_k0=0, i2d_k1=0;
float i2q_k=0, i2q_k0=0, i2q_k1=0;
float i1d_k=0, i1d_k0=0, i1d_k1=0;
float i1q_k=0, i1q_k0=0, i1q_k1=0;
float id=0, iq=0, theta=0;
const float dp=6.28318530718;
float id_r=0, iq_r=0, Vcd_r=0, Vcq_r=0;
float g[125], g_opt=10000000;
float gv[125];
float gb[125];
float gg[125];
//float g[27], g_opt=10000000;
//float gv[27];
//float gb[27];
//float gg[27];

int x=0;
int x_opt=0;

float Sa[125]= {
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
   -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
   -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
   0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
   0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
   1, 1
};
float Sb[125]= {
   -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0.5, 0.5,
   0.5, 0.5, 0.5, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5,
   -0.5, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, -1, -1, -1,
   -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5,
   0.5, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0,
   0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -0.5,
   -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1,
   1
};
float Sc[125]= {
   -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0,
   0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1,
   -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0,
   0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1,
   -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0,
   0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1,
   -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0,
   0.5, 1
};

//float Sa[27]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1};
//float Sb[27]= {-1,-1,-1,0,0,0,1,1,1,-1,-1,-1,0,0,0,1,1,1,-1,-1,-1,0,0,0,1,1,1};
//float Sc[27]= {-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1};

float coseno=0;
float seno=0;
float cosma2pi3=0;
float cosme2pi3=0;
float sinma2pi3=0;
float sinme2pi3=0;

float fa_cosa=0;
float fa_cosb=0;
float fa_cosc=0;
float fa_sinoa=0;
float fa_sinob=0;
float fa_sinoc=0;

float vari1d=0;
float vari1q=0;
float varvcd=0;
float varvcq=0;
float vari2d=0;
float vari2q=0;
float wh=0.06283;

const float CS=0.66666666667;
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

   Out3=theta;
}

void C2000_28379D_0_cScriptUpdate(const struct CScriptStruct *cScriptStruct)
{
   /************ Forma angulo ************/

   theta+=wh;
   if(theta < -dp)
   {
      theta+=dp;
   }
   if(theta > dp)
   {
      theta-=dp;
   }

   coseno = cosf(theta);
   seno = sinf(theta);
   sinma2pi3 = seno*(-0.5) + coseno*0.866; //sinf(theta+PI23); // sin(a+b)
   sinme2pi3 = seno*(-0.5) - coseno*0.866; // sin(a-b)
   cosma2pi3 = coseno*(-0.5) - seno*0.866; // cos(a+b)
   cosme2pi3 = coseno*(-0.5) + seno*0.866; // cos(a-b)

   /************ Referencias ************/

   id_r = Pot/Vgd_r;
   iq_r = 0.124407*(id_r);
   Vcd_r = Vgd_r+(id_r)*0.001 - 0.124407*(iq_r);
   Vcq_r = Vgq_r+(iq_r)*0.001 + 0.124407*(id_r);

   /************ Vector de corriente medida salida del conv ************/

   i1d_k=CS*(i1a*coseno+i1b*cosme2pi3+i1c*cosma2pi3);
   i1q_k=-CS*(i1a*seno+i1b*sinme2pi3+i1c*sinma2pi3);

   /************ Vector de corriente medida en carga ************/

   i2d_k=CS*(isa*coseno+isb*cosme2pi3+isc*cosma2pi3);
   i2q_k=-CS*(isa*seno+isb*sinme2pi3+isc*sinma2pi3);

   /************ Vector de tension capacitores ************/

   Vcd=CS*(Vc_a*coseno+Vc_b*cosme2pi3+Vc_c*cosma2pi3);
   Vcq=-CS*(Vc_a*seno+Vc_b*sinme2pi3+Vc_c*sinma2pi3);

   /************ Tension Convertidor ************/

   V_d=266.666666*(Sa[x_opt]*coseno+Sb[x_opt]*cosme2pi3+Sc[x_opt]*cosma2pi3);
   V_q=-266.666666*(Sa[x_opt]*seno+Sb[x_opt]*sinme2pi3+Sc[x_opt]*sinma2pi3);

   /************ Predicción k+1 ************/
   i1d_k0= (0.1407)*(V_d-Vcd) + wh*i1q_k + i1d_k;
   i1q_k0= (0.1407)*(V_q-Vcq) - wh*i1d_k + i1q_k;

   Vcd_k0=(0.6076)*(i1d_k0-i2d_k) + wh*Vcq + Vcd;
   Vcq_k0=(0.6076)*(i1q_k0-i2q_k) - wh*Vcd + Vcq;

   i2d_k0 = (1.40845)*(Vcd_k0-Vgd_r-i2d_k*0.001) + i2d_k + wh*i2q_k;
   i2q_k0 = (1.40845)*(Vcq_k0-Vgq_r-i2q_k*0.001) + i2q_k - wh*i2d_k;

   /*** Calculo preliminar para minimizar calculos en loop ****/

   vari1d=wh*i1q_k0 + i1d_k0 - Vcd_k0*0.1407;
   vari1q=wh*i1d_k0 + i1q_k0 + Vcq_k0*0.1407;
   varvcd=wh*Vcq_k0 + Vcd_k0 - i2d_k0*0.6076;
   varvcq=wh*Vcd_k0 + Vcq_k0 + i2q_k0*0.6076;
   vari2d=i2d_k0 + wh*i2q_k0 - (Vgd_r-i2d_k0*0.00140845);
   vari2q=i2q_k0 - wh*i2d_k0 - (Vgq_r-i2q_k0*0.00140845);

   /************ Loop para determinar combinacion optima ************/

   g_opt=1e20;
   for (x=0; x <= 124; x=x+1)
   {
      //for (x=0; x <= 26; x=x+1) {
      V_d=266.666666*(Sa[x]*coseno+Sb[x]*cosme2pi3+Sc[x]*cosma2pi3);
      V_q=-266.666666*(Sa[x]*seno+Sb[x]*sinme2pi3+Sc[x]*sinma2pi3);

      i1d_k1= (0.1407)*(V_d) + vari1d;
      i1q_k1= (0.1407)*(V_q) - vari1q;

      Vcd_k1=(0.6076)*(i1d_k1) + varvcd;
      Vcq_k1=(0.6076)*(i1q_k1) - varvcq;

      i2d_k1 = (1.40845)*(Vcd_k1) + vari2d;
      i2q_k1 = (1.40845)*(Vcq_k1) + vari2q;

      g[x]=
         sqrt((id_r -
               i2d_k1)*
              (id_r - i2d_k1)) + sqrt((iq_r - i2q_k1)*(iq_r - i2q_k1));
      //gv[x]=sqrt((Vcd_r - Vcd_k1)*(Vcd_r - Vcd_k1)) + sqrt((Vcq_r - Vcq_k1)*(Vcq_r - Vcq_k1));
      //gb[x]=sqrt((id_r - i1d_k1)*(id_r - i1d_k1)) + sqrt((iq_r - i1q_k1)*(iq_r - i1q_k1));

      // actualizar combinacion de switch optima
      //if(  (Sa[x] == Sa[x_opt]+0.5 || Sa[x] == Sa[x_opt]-0.5 || Sa[x] == Sa[x_opt] ) && (Sb[x] == Sb[x_opt]+0.5 || Sb[x] == Sb[x_opt]-0.5 || Sb[x] == Sb[x_opt]) && (Sc[x] == Sc[x_opt]+0.5 || Sc[x] == Sc[x_opt]-0.5 || Sc[x] == Sc[x_opt]) ){
      //if (0.3333*(g[x]+gv[x]+gb[x]) < g_opt) {
      //if (0.5*(g[x]+gv[x]) < g_opt) {
      if (g[x] < g_opt)
      {
         //g_opt = 0.3333*(g[x]+gv[x]+gb[x]);
         //g_opt = 0.5*(g[x]+gv[x]);
         g_opt = g[x];
         x_opt = x;
      }
      //}
   }
}

void C2000_28379D_0_cScriptDerivative(
                                      const struct CScriptStruct *cScriptStruct)
{
}

void C2000_28379D_0_cScriptTerminate(const struct CScriptStruct *cScriptStruct)
{
}
