/*
 * C-Script file for: C2000_28379D/Control
 * Generated with   : PLECS 4.8.3
 * Generated on     : 30 Sep 2024 15:53:09
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
const float dp=6.28318530718;
float V_d=0, V_q=0;
float Vcd=0, Vcd_k0=0, Vcd_k1=0;
float Vcq=0, Vcq_k0=0, Vcq_k1=0;
float i2d_k=0, i2d_k0=0, i2d_k1=0;
float i2q_k=0, i2q_k0=0, i2q_k1=0;
float i1d_k=0, i1d_k0=0, i1d_k1=0;
float i1q_k=0, i1q_k0=0, i1q_k1=0;
float id=0, iq=0, theta=0;
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

const float Sa[125]= {
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
   -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
   -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
   0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
   0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
   1, 1
};
const float Sb[125]= {
   -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0.5, 0.5,
   0.5, 0.5, 0.5, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5,
   -0.5, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, -1, -1, -1,
   -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5,
   0.5, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -0.5, -0.5, -0.5, -0.5, -0.5, 0, 0,
   0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -0.5,
   -0.5, -0.5, -0.5, -0.5, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1,
   1
};
const float Sc[125]= {
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
float comb=0;

float vari1d=0;
float vari1q=0;
float varvcd=0;
float varvcq=0;
float vari2d=0;
float vari2q=0;

const float wh=0.06283;
const float CS=0.66666666667;
const float angulo[101] = {
   0, 0.062832, 0.125664, 0.188495, 0.251327, 0.314159, 0.376991, 0.439823,
   0.502654, 0.565486, 0.628318, 0.69115, 0.753982, 0.816813, 0.879645,
   0.942477, 1.005309, 1.068141, 1.130972, 1.193804, 1.256636, 1.319468,
   1.3823, 1.445131, 1.507963, 1.570795, 1.633627, 1.696459, 1.75929,
   1.822122, 1.884954, 1.947786, 2.010618, 2.073449, 2.136281, 2.199113,
   2.261945, 2.324777, 2.387608, 2.45044, 2.513272, 2.576104, 2.638936,
   2.701767, 2.764599, 2.827431, 2.890263, 2.953095, 3.015926, 3.078758,
   3.14159, 3.204422, 3.267254, 3.330085, 3.392917, 3.455749, 3.518581,
   3.581413, 3.644244, 3.707076, 3.769908, 3.83274, 3.895572, 3.958403,
   4.021235, 4.084067, 4.146899, 4.209731, 4.272562, 4.335394, 4.398226,
   4.461058, 4.52389, 4.586721, 4.649553, 4.712385, 4.775217, 4.838049,
   4.90088, 4.963712, 5.026544, 5.089376, 5.152208, 5.215039, 5.277871,
   5.340703, 5.403535, 5.466367, 5.529198, 5.59203, 5.654862, 5.717694,
   5.780526, 5.843357, 5.906189, 5.969021, 6.031853, 6.094685, 6.157516,
   6.220348, 6.28318
};
const float cosenos[101] = {
   1.0, 0.998027, 0.992115, 0.982287, 0.968583, 0.951057, 0.929777, 0.904827,
   0.876307, 0.844328, 0.809017, 0.770514, 0.728969, 0.684548, 0.637425,
   0.587786, 0.535828, 0.481754, 0.42578, 0.368125, 0.309018, 0.248691,
   0.187382, 0.125334, 0.062792, 1e-06, -0.062789, -0.125332, -0.18738,
   -0.248688, -0.309015, -0.368123, -0.425778, -0.481752, -0.535825,
   -0.587784, -0.637423, -0.684546, -0.728967, -0.770512, -0.809016,
   -0.844327, -0.876306, -0.904826, -0.929776, -0.951056, -0.968583,
   -0.982287, -0.992114, -0.998027, -1.0, -0.998027, -0.992115, -0.982288,
   -0.968584, -0.951057, -0.929778, -0.904828, -0.876308, -0.84433, -0.809019,
   -0.770515, -0.728971, -0.68455, -0.637427, -0.587788, -0.53583, -0.481757,
   -0.425783, -0.368128, -0.309021, -0.248694, -0.187385, -0.125337,
   -0.062794, -4e-06, 0.062786, 0.125329, 0.187377, 0.248686, 0.309013,
   0.368121, 0.425775, 0.48175, 0.535823, 0.587782, 0.63742, 0.684544,
   0.728965, 0.77051, 0.809014, 0.844325, 0.876304, 0.904825, 0.929775,
   0.951055, 0.968582, 0.982286, 0.992114, 0.998026, 1.0
};
const float senos[101]= {
   0.0, 0.06279, 0.125333, 0.187381, 0.24869, 0.309017, 0.368124, 0.425779,
   0.481753, 0.535826, 0.587785, 0.637424, 0.684547, 0.728968, 0.770513,
   0.809017, 0.844327, 0.876306, 0.904827, 0.929776, 0.951056, 0.968583,
   0.982287, 0.992115, 0.998027, 1.0, 0.998027, 0.992115, 0.982288, 0.968584,
   0.951057, 0.929777, 0.904828, 0.876308, 0.844329, 0.809018, 0.770514,
   0.72897, 0.684549, 0.637426, 0.587787, 0.535829, 0.481756, 0.425781,
   0.368127, 0.309019, 0.248692, 0.187384, 0.125336, 0.062793, 3e-06,
   -0.062788, -0.12533, -0.187379, -0.248687, -0.309014, -0.368122, -0.425777,
   -0.481751, -0.535824, -0.587783, -0.637421, -0.684545, -0.728966,
   -0.770511, -0.809015, -0.844326, -0.876305, -0.904826, -0.929775,
   -0.951055, -0.968582, -0.982287, -0.992114, -0.998026, -1.0, -0.998027,
   -0.992115, -0.982288, -0.968584, -0.951058, -0.929778, -0.904829,
   -0.876309, -0.84433, -0.80902, -0.770516, -0.728972, -0.684551, -0.637428,
   -0.587789, -0.535831, -0.481758, -0.425784, -0.368129, -0.309022,
   -0.248695, -0.187386, -0.125338, -0.062796, -5e-06
};
const float cosme2pi3[101] = {
   -0.5, -0.444637, -0.387519, -0.328872, -0.268926, -0.20792, -0.146093,
   -0.083689, -0.020955, 0.041861, 0.104513, 0.166752, 0.228333, 0.289012,
   0.348552, 0.406716, 0.463273, 0.518004, 0.57069, 0.621124, 0.669105,
   0.714447, 0.75697, 0.796505, 0.832895, 0.866, 0.895686, 0.921838, 0.944351,
   0.963138, 0.978123, 0.989248, 0.99647, 0.999759, 0.999101, 0.994502,
   0.985977, 0.973561, 0.957303, 0.937267, 0.913532, 0.886191, 0.855354,
   0.821139, 0.783686, 0.743138, 0.699659, 0.653418, 0.604598, 0.553392,
   0.500003, 0.444639, 0.387522, 0.328874, 0.268929, 0.207922, 0.146095,
   0.083691, 0.020958, -0.041859, -0.104511, -0.166749, -0.22833, -0.28901,
   -0.348549, -0.406713, -0.463271, -0.518002, -0.570688, -0.621121,
   -0.669103, -0.714445, -0.756968, -0.796502, -0.832894, -0.865998,
   -0.895684, -0.921836, -0.94435, -0.963137, -0.978123, -0.989248, -0.996469,
   -0.999759, -0.999101, -0.994502, -0.985977, -0.973562, -0.957304,
   -0.937268, -0.913532, -0.886192, -0.855354, -0.821141, -0.783687,
   -0.743141, -0.699661, -0.653419, -0.6046, -0.553394, -0.500004
};
const float cosma2pi3[101] = {
   -0.5, -0.55339, -0.604596, -0.653415, -0.699657, -0.743137, -0.783684,
   -0.821138, -0.855352, -0.886189, -0.91353, -0.937266, -0.957302, -0.97356,
   -0.985977, -0.994502, -0.999101, -0.999758, -0.99647, -0.989249, -0.978123,
   -0.963138, -0.944352, -0.921839, -0.895687, -0.866, -0.832897, -0.796506,
   -0.756971, -0.71445, -0.669108, -0.621125, -0.570692, -0.518007, -0.463276,
   -0.406718, -0.348554, -0.289015, -0.228336, -0.166755, -0.104516,
   -0.041864, 0.020952, 0.083687, 0.14609, 0.207918, 0.268924, 0.328869,
   0.387516, 0.444635, 0.499997, 0.553388, 0.604593, 0.653414, 0.699655,
   0.743135, 0.783683, 0.821137, 0.85535, 0.886189, 0.91353, 0.937264,
   0.957301, 0.97356, 0.985976, 0.994501, 0.999101, 0.999759, 0.996471,
   0.989249, 0.978124, 0.963139, 0.944353, 0.921839, 0.895688, 0.866002,
   0.832898, 0.796507, 0.756973, 0.714451, 0.66911, 0.621127, 0.570694,
   0.518009, 0.463278, 0.40672, 0.348557, 0.289018, 0.228339, 0.166758,
   0.104518, 0.041867, -0.02095, -0.083684, -0.146088, -0.207914, -0.268921,
   -0.328867, -0.387514, -0.444632, -0.499996
};
const float sinme2pi3[101] = {
   -0.866, -0.895686, -0.921838, -0.944351, -0.963138, -0.978124, -0.989249,
   -0.99647, -0.999758, -0.999101, -0.994501, -0.985977, -0.973561, -0.957303,
   -0.937267, -0.913531, -0.886191, -0.855352, -0.821139, -0.783684,
   -0.743138, -0.699658, -0.653416, -0.604597, -0.553391, -0.500001,
   -0.444638, -0.38752, -0.328873, -0.268928, -0.207922, -0.146094, -0.08369,
   -0.020957, 0.04186, 0.104512, 0.166751, 0.228332, 0.289011, 0.34855,
   0.406714, 0.463273, 0.518003, 0.570689, 0.621123, 0.669105, 0.714447,
   0.756969, 0.796503, 0.832895, 0.865999, 0.895685, 0.921837, 0.944351,
   0.963137, 0.978122, 0.989249, 0.99647, 0.999758, 0.999102, 0.994502,
   0.985976, 0.973561, 0.957303, 0.937267, 0.913532, 0.886192, 0.855354,
   0.821141, 0.783686, 0.74314, 0.69966, 0.653419, 0.604599, 0.553393,
   0.500003, 0.444641, 0.387523, 0.328876, 0.26893, 0.207924, 0.146096,
   0.083693, 0.020959, -0.041858, -0.104509, -0.166748, -0.228329, -0.289008,
   -0.348548, -0.406712, -0.46327, -0.518, -0.570686, -0.621121, -0.669103,
   -0.714445, -0.756967, -0.796502, -0.832893, -0.865997
};
const float sinma2pi3[101] = {
   0.866, 0.832896, 0.796505, 0.75697, 0.714448, 0.669107, 0.621125, 0.570691,
   0.518005, 0.463275, 0.406716, 0.348553, 0.289014, 0.228335, 0.166754,
   0.104514, 0.041864, -0.020954, -0.083688, -0.146092, -0.207918, -0.268925,
   -0.328871, -0.387518, -0.444636, -0.499999, -0.553389, -0.604595,
   -0.653415, -0.699656, -0.743135, -0.783683, -0.821138, -0.855351,
   -0.886189, -0.91353, -0.937265, -0.957302, -0.97356, -0.985976, -0.994501,
   -0.999102, -0.999759, -0.99647, -0.98925, -0.978124, -0.963139, -0.944353,
   -0.921839, -0.895688, -0.866001, -0.832897, -0.796507, -0.756972, -0.71445,
   -0.669108, -0.621127, -0.570693, -0.518007, -0.463278, -0.406719,
   -0.348555, -0.289016, -0.228337, -0.166756, -0.104517, -0.041866, 0.020951,
   0.083685, 0.146089, 0.207915, 0.268922, 0.328868, 0.387515, 0.444633,
   0.499997, 0.553386, 0.604592, 0.653412, 0.699654, 0.743134, 0.783682,
   0.821136, 0.85535, 0.886188, 0.913529, 0.937264, 0.957301, 0.973559,
   0.985976, 0.994501, 0.999101, 0.999758, 0.99647, 0.98925, 0.978125,
   0.96314, 0.944353, 0.92184, 0.895689, 0.866003
};

float Sav[3]={
   0,0,0
};
float Sbv[3]={
   0,0,0
};
float Scv[3]={
   0,0,0
};

float Saopt=0;
float Sbopt=0;
float Scopt=0;
int a=0;
int b=0;
int c=0;
int i=0;
int j=0;
int k=0;
float error=0;
float error2=0;
float error3=0;


int muestra=0;
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
   Out0=Saopt;
   Out1=Sbopt;
   Out2=Scopt;

   Out3=angulo[muestra];
}

void C2000_28379D_0_cScriptUpdate(const struct CScriptStruct *cScriptStruct)
{
   /************ Forma angulo ************/
   muestra+=1;
   if(muestra > 100)
   {
      muestra=1;
   }

   /************ Referencias ************/

   id_r = Pot/Vgd_r;
   iq_r = 0.124407*(id_r);
   Vcd_r = Vgd_r+(id_r)*0.001 - 0.124407*(iq_r);
   Vcq_r = Vgq_r+(iq_r)*0.001 + 0.124407*(id_r);

   /************ Vector de corriente medida salida del conv ************/

   i1d_k=CS*
          (i1a*cosenos[muestra]+i1b*cosme2pi3[muestra]+i1c*
           cosma2pi3[muestra]);
   i1q_k=-CS*
          (i1a*senos[muestra]+i1b*sinme2pi3[muestra]+i1c*sinma2pi3[muestra]);

   /************ Vector de corriente medida en carga ************/

   i2d_k=CS*
          (isa*cosenos[muestra]+isb*cosme2pi3[muestra]+isc*
           cosma2pi3[muestra]);
   i2q_k=-CS*
          (isa*senos[muestra]+isb*sinme2pi3[muestra]+isc*sinma2pi3[muestra]);

   /************ Vector de tension capacitores ************/

   Vcd=CS*
        (Vc_a*cosenos[muestra]+Vc_b*cosme2pi3[muestra]+Vc_c*
         cosma2pi3[muestra]);
   Vcq=-CS*
        (Vc_a*senos[muestra]+Vc_b*sinme2pi3[muestra]+Vc_c*sinma2pi3[muestra]);

   /************ Tension Convertidor ************/

   V_d=266.666666*
        (Saopt*cosenos[muestra]+Sbopt*cosme2pi3[muestra]+Scopt*
         cosma2pi3[muestra]);
   V_q=-266.666666*
        (Saopt*senos[muestra]+Sbopt*sinme2pi3[muestra]+Scopt*
         sinma2pi3[muestra]);

   /************ Predicción k+1 ************/
   i1d_k0= (0.1407)*(V_d-Vcd) + wh*i1q_k + i1d_k;
   i1q_k0= (0.1407)*(V_q-Vcq) - wh*i1d_k + i1q_k;

   Vcd_k0=(0.6076)*(i1d_k0-i2d_k) + wh*Vcq + Vcd;
   Vcq_k0=(0.6076)*(i1q_k0-i2q_k) - wh*Vcd + Vcq;

   i2d_k0 = (1.40845)*(Vcd_k0-Vgd_r-i2d_k*0.001) + i2d_k + wh*i2q_k;
   i2q_k0 = (1.40845)*(Vcq_k0-Vgq_r-i2q_k*0.001) + i2q_k - wh*i2d_k;

   /*** Calculo preliminar para minimizar calculos en loop ****/

   vari1d=wh*i1q_k0 + i1d_k0 - Vcd_k0*0.1407;
   vari1q=wh*i1d_k0 - i1q_k0 + Vcq_k0*0.1407;

   varvcd=wh*Vcq_k0 + Vcd_k0 - i2d_k0*0.6076;
   varvcq=-i2q_k0*0.6076 -wh*Vcd_k0 + Vcq_k0;

   vari2d=i2d_k0 + wh*i2q_k0 - (1.40845)*(Vgd_r+i2d_k0*0.001);
   vari2q=i2q_k0 - wh*i2d_k0 - (1.40845)*(Vgq_r+i2q_k0*0.001);

   /**** Reducir combinaciones posibles de Loop ***/

   if(Saopt > -1 && Saopt < 1)
   {
      Sav[0]=Saopt-0.5;
      Sav[1]=Saopt;
      Sav[2]=Saopt+0.5;
      a=2;
   }
   if(Saopt == -1)
   {
      Sav[0]=-1;
      Sav[1]=-0.5;
      a=1;
   }
   if(Saopt == 1)
   {
      Sav[0]=0.5;
      Sav[1]=1;
      a=1;
   }

   if(Sbopt > -1 && Sbopt < 1)
   {
      Sbv[0]=Sbopt-0.5;
      Sbv[1]=Sbopt;
      Sbv[2]=Sbopt+0.5;
      b=2;
   }
   if(Sbopt == -1)
   {
      Sbv[0]=-1;
      Sbv[1]=-0.5;
      b=1;
   }
   if(Sbopt == 1)
   {
      Sbv[0]=0.5;
      Sbv[1]=1;
      b=1;
   }

   if(Scopt > -1 && Scopt < 1)
   {
      Scv[0]=Scopt-0.5;
      Scv[1]=Scopt;
      Scv[2]=Scopt+0.5;
      c=2;
   }
   if(Scopt == -1)
   {
      Scv[0]=-1;
      Scv[1]=-0.5;
      c=1;
   }
   if(Scopt == 1)
   {
      Scv[0]=0.5;
      Scv[1]=1;
      c=1;
   }
   g_opt=1e20;
   for(i=0; i <= a; i+=1)
   {
      for(j=0; j <= b; j+=1)
      {
         for(k=0; k <= c; k+=1)
         {
            V_d=266.666666*
                 (Sav[i]*cosenos[muestra]+Sbv[j]*cosme2pi3[muestra]+Scv[k]*
                  cosma2pi3[muestra]);
            V_q=-266.666666*
                 (Sav[i]*senos[muestra]+Sbv[j]*sinme2pi3[muestra]+Scv[k]*
                  sinma2pi3[muestra]);

            i1d_k1= (0.1407)*(V_d) + vari1d;
            i1q_k1= (0.1407)*(V_q) - vari1q;

            Vcd_k1=(0.6076)*(i1d_k1) + varvcd;
            Vcq_k1=(0.6076)*(i1q_k1) - varvcq;

            i2d_k1 = (1.40845)*(Vcd_k1) + vari2d;
            i2q_k1 = (1.40845)*(Vcq_k1) + vari2q;

            error=
               sqrtf((id_r -
                      i1d_k1)*
                     ((id_r) - i1d_k1)) + sqrtf(
                                                (iq_r -
                                                 i1q_k1)*(iq_r - i1q_k1));
            error2=
               sqrtf((id_r -
                      i2d_k1)*
                     (id_r -
                      i2d_k1)) + sqrtf((iq_r - i2q_k1)*(iq_r - i2q_k1));
            error3=
               sqrtf((Vcd_r - Vcd_k1)*(Vcd_r - Vcd_k1)) + sqrtf(
                                                                (Vcq_r -
                                                                 Vcq_k1)*
                                                                (Vcq_r -
                                                                 Vcq_k1));
            if (0.3333*(error+error2+error3) < g_opt)
            {
               g_opt = 0.3333*(error+error2+error3);
               Saopt=Sav[i];
               Sbopt=Sbv[j];
               Scopt=Scv[k];
            }
            ;
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
