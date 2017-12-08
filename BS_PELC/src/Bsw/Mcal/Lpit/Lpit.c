/*
 * Lpit.c
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#include "General.h"          /* include peripheral declarations */
#include "Lpit.h"

tCallbackFunction GlbPit0Callback;

void LPIT0_init ( tCallbackFunction Pit0Callback ) {
  PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6);    /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
  PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
  LPIT0->MCR = 0x00000001;    /* DBG_EN-0: Timer chans stop in Debug mode */
                              /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
                              /* SW_RST=0: SW reset does not reset timer chans, regs */
                           /* M_CEN=1: enable module clk (allows writing other LPIT0 regs)*/
  LPIT0->MIER = 0x00000001;   /* TIE0=1: Timer Interrupt Enabled fot Chan 0 */
  LPIT0->TMR[0].TVAL = 31250;    /* Chan 0 Timeout period: 31250 ticks */

  GlbPit0Callback = Pit0Callback;        /* Callback Initialization */
}

void LPIT0_Start ( void ) {
  LPIT0->TMR[0].TCTRL |= 0x00000001; /* T_EN=1: Timer channel is enabled */
}

void LPIT0_Stop ( void ) {
  LPIT0->TMR[0].TCTRL &= ~(0x00000001); /* T_EN=1: Timer channel is enabled */
}

void LPIT0_Ch0_IRQHandler (void) {
  LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
  if ( NULL!= GlbPit0Callback)
	  GlbPit0Callback();
}
