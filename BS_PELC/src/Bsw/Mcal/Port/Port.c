/*
 * Port.c
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#include "General.h"          /* include peripheral declarations */
#include "Port.h"

void PORT_init (void) {
  PCC-> PCCn[PCC_PORTB_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
  PCC-> PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
  PCC-> PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
  PCC-> PCCn[PCC_PORTE_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */

  PTD->PDDR |= 1<<BlueLed;            /* Port D0:  Data Direction= output */
  PTD->PDDR |= 1<<RedLed;            /* Port D0:  Data Direction= output */

  PORTD->PCR[BlueLed] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */
  PORTD->PCR[RedLed] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */

  /*CAN CONFIGURATION*/
  PORTD->PCR[16] |=  0x00000100;     /* Port D16: MUX = GPIO (to green LED) */
  PORTE->PCR[4] |= PORT_PCR_MUX(5); /* Port E4: MUX = ALT5, CAN0_RX */
  PORTE->PCR[5] |= PORT_PCR_MUX(5); /* Port E5: MUX = ALT5, CAN0_TX */
  PTD->PDDR |= 1<<16;               /* Port D16: Data direction = output */
  /*-------------------------------*/

  PTD->PSOR |= 1<<BlueLed;
  PTD->PSOR |= 1<<RedLed;

  /*LedBars*/
  PTC->PDDR |= 1<<LedBar_1;
	PTB->PDDR |= 1<<LedBar_2;
	PTB->PDDR |= 1<<LedBar_3;
	PTB->PDDR |= 1<<LedBar_4;
	PTB->PDDR |= 1<<LedBar_5;
	PTC->PDDR |= 1<<LedBar_6;

  PORTC->PCR[LedBar_1] = 0x00000100;
  PORTB->PCR[LedBar_2] = 0x00000100;
  PORTB->PCR[LedBar_3] = 0x00000100;
  PORTB->PCR[LedBar_4] = 0x00000100;
  PORTB->PCR[LedBar_5] = 0x00000100;
  PORTC->PCR[LedBar_6] = 0x00000100;

  PTC->PCOR |= 1<<LedBar_1;
  PTB->PCOR |= 1<<LedBar_2;
  PTB->PCOR |= 1<<LedBar_3;
  PTB->PCOR |= 1<<LedBar_4;
  PTB->PCOR |= 1<<LedBar_5;
  PTC->PCOR |= 1<<LedBar_6;
}
