/*
 * C-Script file for: C2000_28379D/Control
 * Generated with   : PLECS 4.8.6
 * Generated on     : 23 Sep 2024 15:42:19
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
#define Out4 Output(4)
#define Out5 Output(5)
#define Out6 Output(6)
#define Out7 Output(7)
#define Out8 Output(8)
#define Out9 Output(9)
#define Out10 Output(10)
#define Out11 Output(11)
#define Out12 Output(12)

double h=2e-04;
double Vdc=800;
double L1=1.422e-3;
double L2=0.142e-3;
double Cf=0.329e-3;
double R=0.001;
double rc=10;
double w=314.1593;
double R1=1000;
double Vgd_r=220;
double Vgq_r=0;
double e=0;
double d1_L1C=2137152;
double d1_L2=7042.25;
double C2=0.0001;
double d1_C2=10000;
double d1_L1=703.66;
double d1_c=3038;

double ik_d=0, ik_q=0, ik1_d=0, ik1_q=0;
double V_d=0, V_q=0;
double Vd_ant_2=0, Vd_ant=0, Vgd_ant_2=0, Vgd_ant=0;
double Vq_ant_2=0, Vq_ant=0, Vgq_ant_2=0, Vgq_ant=0;
double Vcdp=0, Vcqp=0;
double Vcd_ant_2=0, Vcd_ant=0, Vcd=0, Vcd_k0=0, Vcd_k1=0;
double Vcq_ant_2=0, Vcq_ant=0, Vcq=0, Vcq_k0=0, Vcq_k1=0;
double i2d_k=0, i2d_k0=0, i2d_k1=0, i2d_ant=0, i2d_ant_2=0;
double i2q_k=0, i2q_k0=0, i2q_k1=0, i2q_ant=0, i2q_ant_2=0;
double i1d_k=0, i1d_k0=0, i1d_k1=0, i1d_ant=0, i1d_ant_2=0;
double i1q_k=0, i1q_k0=0, i1q_k1=0, i1q_ant=0, i1q_ant_2=0;
double Vgd_k=0, Vgd_k0=0, Vgd_k1=0;
double Vgq_k=0, Vgq_k0=0, Vgq_k1=0;
double id_ref=30, iq_ref=0;
double ia_ref=0, ib_ref=0;
double id=0, iq=0, theta=0;
double ed=0, xd=0, vd=0, edp=0;
double eq=0, xq=0, vq=0, eqp=0;
double ma=0, mb=0, mc=0;
double sat=1.15, dp=6.28318530718;
double id_r=0, iq_r=0, Vcd_r=0, Vcq_r=0;
double g[125], g_opt=10000000;
double gv[125];
double gb[125];
double gg[125];
double t=0, gx=0, e_ant=0;
double ik0_d=0, ik0_q=0;
double e1=-0.99;

int Sa1=0;
int Sa2=0;
int Sa3=0;
int Sb1=0;
int Sb2=0;
int Sb3=0;
int Sc1=0;
int Sc2=0;
int Sc3=0;

int cont_v=0;
int x=0;
int x_opt=0;

double Sa[125]= {
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
   -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
   -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
   0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
   0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
   1, 1
};
double Sb[125]= {
   -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0.5, 0.5,
   0.5, 0.5, 0.5, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5,
   -0.5, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, -1, -1, -1,
   -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5,
   0.5, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0,
   0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -0.5,
   -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1,
   1
};
double Sc[125]= {
   -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0,
   0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1,
   -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0,
   0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1,
   -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0,
   0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1,
   -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0, 0.5, 1, -1, -0.5, 0,
   0.5, 1
};

double PI23=2.0943951023931954923084289221863;
double CS=0.666666666666666666667;
#define sq3     1.732050807568877
#define sq3_2 0.86602540378
#define sq3_3 0.57735026919
#define d2_3 0.66666666666666666666666666666666666666666666666666666666666666
#define d1_3 \
   0.3333333333333333333333333333333333333333333333333333333333333333
#define d1_sq3 0.57735026918962576450914878050196
#define pi  3.1415926535897932384626433832795
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

   theta+=w*h;
   if(theta < -dp)
   {
      theta+=dp;
   }
   if(theta > dp)
   {
      theta-=dp;
   }

   /************ Referencias ************/

   id_r = Pot/Vgd_r;
   iq_r = 314.16*396e-6*(id_r);
   Vcd_r = Vgd_r+(id_r)*R - 314.16*396e-6*(iq_r);
   Vcq_r = Vgq_r+(iq_r)*R + 314.16*396e-6*(id_r);

   /************ Vector de corriente medida salida del conv ************/

   i1d_k=CS*(i1a*cos(theta)+i1b*cos(theta-PI23)+i1c*cos(theta+PI23));
   i1q_k=-CS*(i1a*sin(theta)+i1b*sin(theta-PI23)+i1c*sin(theta+PI23));

   /************ Vector de corriente medida en carga ************/

   i2d_k=CS*(isa*cos(theta)+isb*cos(theta-PI23)+isc*cos(theta+PI23));
   i2q_k=-CS*(isa*sin(theta)+isb*sin(theta-PI23)+isc*sin(theta+PI23));

   /************ Vector de tension capacitores ************/

   Vcd=CS*(Vc_a*cos(theta)+Vc_b*cos(theta-PI23)+Vc_c*cos(theta+PI23));
   Vcq=-CS*(Vc_a*sin(theta)+Vc_b*sin(theta-PI23)+Vc_c*sin(theta+PI23));

   /************ Tension Convertidor ************/

   V_d=0.5*Vdc*CS*
        (Sa[x_opt]*cos(theta)+Sb[x_opt]*
         cos(theta-PI23)+Sc[x_opt]*cos(theta+PI23));
   V_q=-0.5*Vdc*CS*
        (Sa[x_opt]*sin(theta)+Sb[x_opt]*
         sin(theta-PI23)+Sc[x_opt]*sin(theta+PI23));

   /************ Predicción k+1 ************/
   i1d_k0= (h*d1_L1)*(V_d-Vcd) + w*h*i1q_k + i1d_k;
   i1q_k0= (h*d1_L1)*(V_q-Vcq) - w*h*i1d_k + i1q_k;

   Vcd_k0=(h*d1_c)*(i1d_k0-i2d_k) + w*h*Vcq + Vcd;
   Vcq_k0=(h*d1_c)*(i1q_k0-i2q_k) - w*h*Vcd + Vcq;

   i2d_k0 = h*(Vcd_k0-Vgd_r-i2d_k*R)*d1_L2 + i2d_k + w*h*i2q_k;
   i2q_k0 = h*(Vcq_k0-Vgq_r-i2q_k*R)*d1_L2 + i2q_k - w*h*i2d_k;

   /************ Loop para determinar combinacion optima ************/

   g_opt=1e20;
   for (x=0; x <= 124; x=x+1)
   {

      V_d=0.5*Vdc*CS*
           (Sa[x]*cos(theta)+Sb[x]*cos(theta-PI23)+Sc[x]*cos(theta+PI23));
      V_q=-0.5*Vdc*CS*
           (Sa[x]*sin(theta)+Sb[x]*sin(theta-PI23)+Sc[x]*sin(theta+PI23));

      i1d_k1= (h*d1_L1)*(V_d-Vcd_k0) + w*h*i1q_k0 + i1d_k0;
      i1q_k1= (h*d1_L1)*(V_q-Vcq_k0) - w*h*i1d_k0 + i1q_k0;

      Vcd_k1=(h*d1_c)*(i1d_k1-i2d_k0) + w*h*Vcq_k0 + Vcd_k0;
      Vcq_k1=(h*d1_c)*(i1q_k1-i2q_k0) - w*h*Vcd_k0 + Vcq_k0;

      i2d_k1 = h*(Vcd_k1-Vgd_r-i2d_k0*R)*d1_L2 + i2d_k0 + w*h*i2q_k0;
      i2q_k1 = h*(Vcq_k1-Vgq_r-i2q_k0*R)*d1_L2 + i2q_k0 - w*h*i2d_k0;

      g[x]=
         sqrt((id_r -
               i2d_k1)*
              (id_r - i2d_k1)) + sqrt((iq_r - i2q_k1)*(iq_r - i2q_k1));
      gv[x]=
         sqrt((Vcd_r -
               Vcd_k1)*
              (Vcd_r - Vcd_k1)) + sqrt((Vcq_r - Vcq_k1)*(Vcq_r - Vcq_k1));
      gb[x]=
         sqrt((id_r -
               i1d_k1)*
              (id_r - i1d_k1)) + sqrt((iq_r - i1q_k1)*(iq_r - i1q_k1));

      // actualizar combinacion de switch optima
      if(  (Sa[x] == Sa[x_opt]+0.5 || Sa[x] == Sa[x_opt]-0.5 || Sa[x] ==
            Sa[x_opt] ) &&
         (Sb[x] == Sb[x_opt]+0.5 || Sb[x] == Sb[x_opt]-0.5 || Sb[x] ==
          Sb[x_opt]) &&
         (Sc[x] == Sc[x_opt]+0.5 || Sc[x] == Sc[x_opt]-0.5 || Sc[x] ==
          Sc[x_opt]) )
      {
         if (0.3333*(g[x]+gv[x]+gb[x]) < g_opt)
         {
            g_opt = 0.3333*(g[x]+gv[x]+gb[x]);
            x_opt = x;
         }
      }
   }
}

void C2000_28379D_0_cScriptDerivative(
                                      const struct CScriptStruct *cScriptStruct)
{
}

void C2000_28379D_0_cScriptTerminate(const struct CScriptStruct *cScriptStruct)
{
}
