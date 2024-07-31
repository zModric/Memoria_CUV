/*
 * Header file for: Model base/28379D
 * Generated with : PLECS 4.8.3
 *                  TI2837x 1.7.4
 * Generated on   : 26 Jul 2024 13:15:47
 */
#ifndef PLECS_HEADER_pl_28379D_h_
#define PLECS_HEADER_pl_28379D_h_

#include <stdbool.h>
#include <stdint.h>

/* Target typedefs */
typedef int_fast8_t int8_t;
typedef uint_fast8_t uint8_t;


/* Model floating point type */
typedef float pl_28379D_FloatType;

/* Target declarations */
extern void pl_28379D_background(void);

/* Model checksum */
extern const char * const pl_28379D_checksum;

/* Model error status */
extern const char * pl_28379D_errorStatus;


/* Model sample time */
extern const float pl_28379D_sampleTime;


/* Block outputs */
typedef struct
{
   float ControlCorriente[13];      /* 28379D/Control Corriente */
   float TriangularWave1;           /* 28379D/Switch/SW A/Triangular Wave1 */
   float TriangularWave2;           /* 28379D/Switch/SW A/Triangular Wave2 */
   float TriangularWave1_1;         /* 28379D/Switch/SW A1/Triangular Wave1 */
   float TriangularWave2_1;         /* 28379D/Switch/SW A1/Triangular Wave2 */
   float TriangularWave1_2;         /* 28379D/Switch/SW A2/Triangular Wave1 */
   float TriangularWave2_2;         /* 28379D/Switch/SW A2/Triangular Wave2 */
   float i2[3];                     /* 28379D/i2 */
   float Vc[3];                     /* 28379D/Vc */
   float i1[3];                     /* 28379D/i1 */
   float Pot;                       /* 28379D/Pot */
   float Fcn;                       /* 28379D/Switch/SW A/Fcn */
   float Fcn_1;                     /* 28379D/Switch/SW A1/Fcn */
   float Fcn_2;                     /* 28379D/Switch/SW A2/Fcn */
} pl_28379D_BlockOutputs;
extern pl_28379D_BlockOutputs pl_28379D_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define pl_28379D_NumExtModeSignals 13
extern const float * const pl_28379D_ExtModeSignals[];
/* Tunable parameters */
#define pl_28379D_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void pl_28379D_initialize(void);
void pl_28379D_step(void);
void pl_28379D_terminate(void);

#endif /* PLECS_HEADER_pl_28379D_h_ */
