/*
 * Nvic.c
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#include "General.h"          /* include peripheral declarations */
#include "Nvic.h"

void NVIC_init_IRQs (void) {
	  S32_NVIC->ICPR[1] = 1 << (48 % 32);  /* IRQ48-LPIT0 ch0: clr any pending IRQ*/
	  S32_NVIC->ISER[1] = 1 << (48 % 32);  /* IRQ48-LPIT0 ch0: enable IRQ */
	  S32_NVIC->IP[48] = 0xA;              /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/
}
