/*
 * Header file for: Model base/C2000_28379D
 * Generated with : PLECS 4.8.3
 *                  TI2837x 1.7.4
 * Generated on   : 21 Aug 2024 10:00:34
 */
#ifndef PLECS_HEADER_C2000_28379D_h_
#define PLECS_HEADER_C2000_28379D_h_

#include <stdbool.h>
#include <stdint.h>

/* Target typedefs */
typedef int_fast8_t int8_t;
typedef uint_fast8_t uint8_t;


/* Model floating point type */
typedef float C2000_28379D_FloatType;

/* Target declarations */
extern void C2000_28379D_background(void);

/* Model checksum */
extern const char * const C2000_28379D_checksum;

/* Model error status */
extern const char * C2000_28379D_errorStatus;


/* Model sample time */
extern const float C2000_28379D_sampleTime;


/* Block outputs */
typedef struct
{
   float Control[3];                /* C2000_28379D/Control */
   float TriangularWave1;           /* C2000_28379D/SW A/Triangular Wave1 */
   float TriangularWave2;           /* C2000_28379D/SW A/Triangular Wave2 */
   float TriangularWave1_1;         /* C2000_28379D/SW A1/Triangular Wave1 */
   float TriangularWave2_1;         /* C2000_28379D/SW A1/Triangular Wave2 */
   float TriangularWave1_2;         /* C2000_28379D/SW A2/Triangular Wave1 */
   float TriangularWave2_2;         /* C2000_28379D/SW A2/Triangular Wave2 */
   float i2[3];                     /* C2000_28379D/i2 */
   float Vc[3];                     /* C2000_28379D/Vc */
   float i1[3];                     /* C2000_28379D/i1 */
   float Pot;                       /* C2000_28379D/Pot */
   float Fcn;                       /* C2000_28379D/SW A/Fcn */
   float Fcn_1;                     /* C2000_28379D/SW A1/Fcn */
   float Fcn_2;                     /* C2000_28379D/SW A2/Fcn */
} C2000_28379D_BlockOutputs;
extern C2000_28379D_BlockOutputs C2000_28379D_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define C2000_28379D_NumExtModeSignals 0
extern const float * const C2000_28379D_ExtModeSignals[];
/* Tunable parameters */
#define C2000_28379D_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void C2000_28379D_initialize(void);
void C2000_28379D_step(void);
void C2000_28379D_terminate(void);

#endif /* PLECS_HEADER_C2000_28379D_h_ */
