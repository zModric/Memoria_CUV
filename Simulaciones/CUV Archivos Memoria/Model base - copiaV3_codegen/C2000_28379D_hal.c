/*
 * Hardware configuration file for: TI2837x
 * Generated with                 : PLECS 4.8.3
 * Generated on                   : Wed Oct  9 18:16:58 2024
 */

/* HAL Includes */
#include "C2000_28379D.h"
#include "plx_hal.h"
#include "plx_dispatcher.h"
#include "pil.h"
#include "plx_sci.h"
#include "pin_map.h"
#include "gpio.h"
#include "xbar.h"
#include "asysctl.h"
#include "sysctl.h"
#include "plx_dio.h"
#include "plx_ain.h"
#include "plx_dac.h"

/* HAL Declarations */
void DevInit(uint32_t aDeviceClkConf);
void InitFlashHz(Uint32 clkHz);
void DSP28x_usDelay(long LoopCount);

// clock configurations
#define PLX_DEVICE_SETCLOCK_CFG  (SYSCTL_OSCSRC_OSC2 | SYSCTL_IMULT(19) |  \
                                  SYSCTL_FMULT_0 | SYSCTL_SYSDIV(1) |   \
                                  SYSCTL_PLL_ENABLE)

#define SYSCLK_HZ 190000000L
#define SYSCLK_WC_HI_HZ 196000000L
#define LSPCLK_HZ (SYSCLK_HZ / 4l)
#define PLX_DELAY_US(A)  DSP28x_usDelay( \
                                        ((((long double) A * \
                                           1000.0L) / \
                                          5.263158L) - 9.0L) / 5.0L)

PIL_Obj_t PilObj;
PIL_Handle_t PilHandle = 0;
PLX_SCI_Obj_t SciObj;
PLX_SCI_Handle_t SciHandle;
// external mode helper symbols
PIL_CONFIG_DEF(uint32_t, ExtMode_targetFloat_Size,
               sizeof(C2000_28379D_FloatType));
PIL_CONFIG_DEF(uint32_t, ExtMode_targetPointer_Size,
               sizeof(C2000_28379D_FloatType*));
PIL_CONFIG_DEF(uint32_t, ExtMode_sampleTime_Ptr,
               (uint32_t)&C2000_28379D_sampleTime);
PIL_CONFIG_DEF(uint32_t, ExtMode_checksum_Ptr,
               (uint32_t)&C2000_28379D_checksum);
#if defined(C2000_28379D_NumTunableParameters) && \
   (C2000_28379D_NumTunableParameters > 0)
PIL_CONFIG_DEF(uint32_t, ExtMode_P_Ptr, (uint32_t)&C2000_28379D_P);
PIL_CONFIG_DEF(uint32_t, ExtMode_P_Size,
               (uint32_t)C2000_28379D_NumTunableParameters);
#endif
#if defined(C2000_28379D_NumExtModeSignals) && \
   (C2000_28379D_NumExtModeSignals > 0)
PIL_CONFIG_DEF(uint32_t, ExtMode_ExtModeSignals_Ptr,
               (uint32_t)&C2000_28379D_ExtModeSignals[0]);
PIL_CONFIG_DEF(uint32_t, ExtMode_ExtModeSignals_Size,
               (uint32_t)C2000_28379D_NumExtModeSignals);
#endif

#define CODE_GUID {0x09, 0x3c, 0x97, 0x5e, 0xdb, 0x2d, 0xb8, 0x40};
PIL_CONST_DEF(unsigned char, Guid[], CODE_GUID);
PIL_CONST_DEF(unsigned char, CompiledDate[], "10/09/2024 06:16 PM");
PIL_CONST_DEF(unsigned char, CompiledBy[], "PLECS Coder");
PIL_CONST_DEF(uint16_t, FrameworkVersion, PIL_FRAMEWORK_VERSION);
PIL_CONST_DEF(char, FirmwareDescription[], "TIC2000 Project (CPU0)");
PIL_CONST_DEF(uint16_t, StationAddress, 0);
PIL_CONST_DEF(uint32_t, BaudRate, 115200);
static void SciPoll(PIL_Handle_t aHandle)
{
   if(PLX_SCI_breakOccurred(SciHandle))
   {
      PLX_SCI_reset(SciHandle);
   }
   while(PLX_SCI_rxReady(SciHandle))
   {
      // assuming that there will be a "break" when FIFO is empty
      PIL_SERIAL_IN(aHandle, (int16)PLX_SCI_getChar(SciHandle));
   }
   int16_t ch;
   if(!PLX_SCI_txIsBusy(SciHandle))
   {
      if(PIL_SERIAL_OUT(aHandle, &ch))
      {
         PLX_SCI_putChar(SciHandle, ch);
      }
   }
}

#pragma DATA_SECTION(ScopeBuffer, "scope")
uint16_t ScopeBuffer[1004] /*__attribute__((aligned(16)))*/;
extern void PIL_setAndConfigScopeBuffer(PIL_Handle_t aPilHandle,
                                        uint16_t* aBufPtr, uint16_t aBufSize,
                                        uint16_t aMaxTraceWidthInWords);
extern const char * const C2000_28379D_checksum;

uint16_t ScopeFlagCpuRemote;
#pragma DATA_SECTION(ScopeFlagCpuRemote, "scopeflag_remote")
#pragma RETAIN(ScopeFlagCpuRemote)
uint16_t ScopeFlagCpuThis;
#pragma DATA_SECTION(ScopeFlagCpuThis, "scopeflag_local")
#pragma RETAIN(ScopeFlagCpuThis)
PIL_SYMBOL_DEF(ScopeFlagCpuRemote, 0, 1.0, "");
PIL_SYMBOL_DEF(ScopeFlagCpuThis, 0, 1.0, "");
extern void PIL_setAndConfigureScopeIndicator(PIL_Handle_t aPilHandle,
                                              uint16_t* aIndicatorPtr);

PLX_DIO_Handle_t DoutHandles[9];
PLX_DIO_Obj_t DoutObj[9];
void PLXHAL_DIO_set(uint16_t aHandle, bool aVal)
{
   PLX_DIO_set(DoutHandles[aHandle], aVal);
}
PLX_AIN_Handle_t AdcHandles[4];
PLX_AIN_Obj_t AdcObj[4];
float PLXHAL_ADC_getIn(uint16_t aHandle, uint16_t aChannel)
{
   return PLX_AIN_getInF(AdcHandles[aHandle], aChannel);
}
PLX_DAC_Handle_t DacHandles[1];
PLX_DAC_Obj_t DacObj[1];
void PLXHAL_DAC_set(uint16_t aHandle, float aValue)
{
   PLX_DAC_setValF(DacHandles[aHandle], aValue);
}
extern PIL_Handle_t PilHandle;
DISPR_TaskObj_t TaskObj[1];
extern void C2000_28379D_step();
extern void C2000_28379D_enableTasksInterrupt();
extern void C2000_28379D_syncTimers();
static void Tasks(bool aInit, void * const aParam)
{
   if(aInit)
   {
      C2000_28379D_enableTasksInterrupt();
   }
   else
   {
      C2000_28379D_step();
   }
}


interrupt void C2000_28379D_baseTaskInterrupt(void)
{
   AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;              // clear ADCINT1 flag reinitialize for next SOC
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;  // acknowledge interrupt to PIE (All ADCS in group 1)
   IER |= M_INT1;

   DISPR_dispatch();
}


/* Interrupt Enable Code */
void C2000_28379D_enableTasksInterrupt(void)
{
   IER |= M_INT1;
}

/* Timer Synchronization Code */
void C2000_28379D_syncTimers(void)
{
   CpuTimer0Regs.TCR.bit.TSS = 0;
}

/* Background tasks */
void C2000_28379D_background(void)
{

}
/* HAL Initialization Code */
static bool HalInitialized = false;
void C2000_28379D_initHal()
{
   if(HalInitialized == true)
   {
      return;
   }
   HalInitialized = true;
   // Pre init code
   {
      uint32_t sysPllConfig = PLX_DEVICE_SETCLOCK_CFG;
      DevInit(sysPllConfig);
      SysCtl_setLowSpeedClock(SYSCTL_LSPCLK_PRESCALE_4);

      PLX_ASSERT(SysCtl_getClock(10000000) == SYSCLK_HZ);
      PLX_ASSERT(SysCtl_getLowSpeedClock(10000000) == LSPCLK_HZ);
   }
   InitFlashHz(SYSCLK_WC_HI_HZ);
   // set cpu timers to same clock as ePWM
   CpuTimer0Regs.TPR.all = 3;
   CpuTimer1Regs.TPR.all = 3;
   CpuTimer2Regs.TPR.all = 3;
   EALLOW;
   CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;
   CpuSysRegs.PCLKCR0.bit.CPUTIMER1 = 1;
   CpuSysRegs.PCLKCR0.bit.CPUTIMER2 = 1;
   CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // stop all the TB clocks on the local cpu
   CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC = 0; // stop all the TB clocks
   ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 1;
   EDIS;

   SciHandle = PLX_SCI_init(&SciObj, sizeof(SciObj));
   PLX_SCI_configure(SciHandle, PLX_SCI_SCI_A, 47500000);
   (void)PLX_SCI_setupPort(SciHandle, 115200);
   PilHandle = PIL_init(&PilObj, sizeof(PilObj));
   PIL_setGuid(PilHandle, PIL_GUID_PTR);
   PIL_setChecksum(PilHandle, C2000_28379D_checksum);
   PIL_setAndConfigScopeBuffer(PilHandle, (uint16_t *)&ScopeBuffer, 1004, 2);
   PIL_setAndConfigureScopeIndicator(PilHandle, &ScopeFlagCpuThis);
   PIL_setNodeAddress(PilHandle, PIL_D_StationAddress);

   PIL_setSerialComCallback(PilHandle, (PIL_CommCallbackPtr_t)SciPoll);
   {
      // early system configuration
      PLX_DIO_sinit();
   }
   {
      PLX_DIO_sinit();
      int i;
      for(i=0; i < 9; i++)
      {
         DoutHandles[i] = PLX_DIO_init(&DoutObj[i], sizeof(DoutObj[i]));
      }
   }

   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[0], 0,  &props);
   }
   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[1], 1,  &props);
   }
   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[2], 2,  &props);
   }
   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[3], 3,  &props);
   }
   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[4], 4,  &props);
   }
   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[5], 5,  &props);
   }
   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[6], 6,  &props);
   }
   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[7], 7,  &props);
   }
   {
      PLX_DIO_OutputProperties_t props = {
         0
      };
      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[8], 8,  &props);
   }
   {
      PLX_AIN_sinit(190000000);
      int i;
      for(i=0; i < 4; i++)
      {
         AdcHandles[i] = PLX_AIN_init(&AdcObj[i], sizeof(AdcObj[i]));
      }
   }

   // configure ADC B

   {
      PLX_AIN_AdcParams_t params;
      PLX_AIN_setDefaultAdcParams(&params, 1, 3.000000, 0);
      PLX_AIN_configure(AdcHandles[2], (PLX_AIN_Unit_t)1, &params);
   }
   // configure SOC1 of ADC-B to measure ADCIN2
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  2.000000000e+02f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[2], 0, 2, &params);
   }

   // configure SOC2 of ADC-B to measure ADCIN3
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  2.000000000e+02f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[2], 1, 3, &params);
   }

   // configure SOC3 of ADC-B to measure ADCIN4
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  2.000000000e+02f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[2], 2, 4, &params);
   }

   // configure ADC C

   {
      PLX_AIN_AdcParams_t params;
      PLX_AIN_setDefaultAdcParams(&params, 1, 3.000000, 0);
      PLX_AIN_configure(AdcHandles[0], (PLX_AIN_Unit_t)2, &params);
   }
   // configure SOC1 of ADC-C to measure ADCIN2
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  3.333333333e+02f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[0], 0, 2, &params);
   }

   // configure SOC2 of ADC-C to measure ADCIN3
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  3.333333333e+02f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[0], 1, 3, &params);
   }

   // configure SOC3 of ADC-C to measure ADCIN4
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  3.333333333e+02f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[0], 2, 4, &params);
   }

   // configure ADC D

   {
      PLX_AIN_AdcParams_t params;
      PLX_AIN_setDefaultAdcParams(&params, 1, 3.000000, 0);
      PLX_AIN_configure(AdcHandles[3], (PLX_AIN_Unit_t)3, &params);
   }
   // configure SOC1 of ADC-D to measure ADCIN14
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  3.333333333e+04f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[3], 0, 14, &params);
   }

   // configure ADC A

   {
      PLX_AIN_AdcParams_t params;
      PLX_AIN_setDefaultAdcParams(&params, 1, 3.000000, 0);
      PLX_AIN_configure(AdcHandles[1], (PLX_AIN_Unit_t)0, &params);
   }
   // configure SOC1 of ADC-A to measure ADCIN2
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  3.333333333e+02f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[1], 0, 2, &params);
   }

   // configure SOC2 of ADC-A to measure ADCIN3
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  3.333333333e+02f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[1], 1, 3, &params);
   }

   // configure SOC3 of ADC-A to measure ADCIN4
   {

      PLX_AIN_ChannelParams_t params;
      PLX_AIN_setDefaultChannelParams(&params);
      params.scale =  3.333333333e+02f;
      params.offset = 0.000000000e+00f;
      // set SOC trigger to CPU 1 Timer0
      params.ADCSOCxCTL.bit.TRIGSEL = 1;
      params.ADCSOCxCTL.bit.ACQPS = 14;
      PLX_AIN_setupChannel(AdcHandles[1], 2, 4, &params);
   }

   {
      PLX_DAC_sinit();
      int i;
      for(i=0; i < 1; i++)
      {
         DacHandles[i] = PLX_DAC_init(&DacObj[i], sizeof(DacObj[i]));
      }
   }

   // configure DACA

   {

      PLX_DAC_configure(DacHandles[0], PLX_DAC_A, 1, 3.000000000e+00f);
      PLX_DAC_configureScaling(DacHandles[0], 3.333333333e-01f,
                               0.000000000e+00f, 0.000000000e+00f,
                               3.300000000e+00f);
   }

   DISPR_sinit();
   DISPR_configure((uint32_t)(2375), PilHandle, &TaskObj[0],
                   sizeof(TaskObj)/sizeof(DISPR_TaskObj_t));
   DISPR_registerIdleTask(&C2000_28379D_background);
   DISPR_registerSyncCallback(&C2000_28379D_syncTimers);
   DISPR_setPowerupDelay(20);
   {
      static int taskId = 0;
      // Task 0 at 2.000000e+04 Hz
      DISPR_registerTask(0, &Tasks, 2375L, (void *)&taskId);
   }
   {
      CpuTimer0Regs.TCR.bit.TSS = 1;   // stop timer
      CpuTimer0Regs.TPRH.all = 0;
      CpuTimer0Regs.PRD.all = 2375-1;
      CpuTimer0Regs.TCR.bit.TRB = 1;   // reload period
      CpuTimer0Regs.TCR.bit.TIE = 1;   // enable trigger to SOC/interrupt

   }
   EALLOW;
   AdcaRegs.ADCINTSEL1N2.bit.INT1CONT = 0;  // disable ADCINT1 Continuous mode
   AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 2;  // setup EOC2 to trigger ADCINT1
   AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1;  // enable ADCINT1
   AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;  // ADCINT1 trips after AdcResults latch
   EDIS;
   EALLOW;
   *(PINT *)((uint32_t)(&PieVectTable.ADCA1_INT) + ((uint32_t)0)*
             sizeof(PINT *)) = &C2000_28379D_baseTaskInterrupt;
   PieCtrlRegs.PIEIER1.all |= 1;
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
   EDIS;


   // Post init code (for modules that depend on other modules)

   {
      // late system configuration
      GPIO_setPadConfig(0, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(0, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(1, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(1, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(2, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(2, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(3, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(3, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(4, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(4, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(5, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(5, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(6, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(6, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(7, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(7, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(8, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(8, GPIO_DIR_MODE_OUT);
      GPIO_setPinConfig(GPIO_43_SCIRXDA);
      GPIO_setPinConfig(GPIO_42_SCITXDA);
   }
}
