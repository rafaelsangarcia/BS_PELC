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
	PTD->PDDR |= 1<<GreenLed;            /* Port D0:  Data Direction= output */

	PORTD->PCR[BlueLed] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */
	PORTD->PCR[RedLed] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */
	PORTD->PCR[GreenLed] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */

	/*CAN CONFIGURATION*/
	PORTD->PCR[16] |=  0x00000100;     /* Port D16: MUX = GPIO (to green LED) */
	PORTE->PCR[4] |= PORT_PCR_MUX(5); /* Port E4: MUX = ALT5, CAN0_RX */
	PORTE->PCR[5] |= PORT_PCR_MUX(5); /* Port E5: MUX = ALT5, CAN0_TX */
	PTD->PDDR |= 1<<16;               /* Port D16: Data direction = output */
	/*-------------------------------*/

	PTD->PSOR |= 1<<BlueLed;
	PTD->PSOR |= 1<<RedLed;
	PTD->PSOR |= 1<<GreenLed;

	/*LedBars*/
	/*PTC->PDDR |= 1<<LedBar_1;
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

	PTC->PCOR |= 1<<LedBar_1;//7
	PTB->PCOR |= 1<<LedBar_2;//17
	PTB->PCOR |= 1<<LedBar_3;//14
	PTB->PCOR |= 1<<LedBar_4;//15
	PTB->PCOR |= 1<<LedBar_5;//16
	PTC->PCOR |= 1<<LedBar_6;//14*/

	PORTD->PCR[1]|=PORT_PCR_MUX(2); /* Port D1: MUX = ALT2, FTM0CH1 */
	PORTC->PCR[1]|=PORT_PCR_MUX(2); /* Port C1: MUX = ALT2, FTM0CH1 */
	PORTC->PCR[2]|=PORT_PCR_MUX(2); /* Port C2: MUX = ALT2, FTM0CH1 */
	PORTC->PCR[3]|=PORT_PCR_MUX(2); /* Port C3: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[2]|=PORT_PCR_MUX(2); /* Port B2: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[3]|=PORT_PCR_MUX(2); /* Port B3: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[4]|=PORT_PCR_MUX(2); /* Port B4: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[5]|=PORT_PCR_MUX(2); /* Port B5: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[12]|=PORT_PCR_MUX(2); /* Port B12: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[13]|=PORT_PCR_MUX(2); /* Port B13: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[14]|=PORT_PCR_MUX(2); /* Port B14: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[15]|=PORT_PCR_MUX(2); /* Port B15: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[16]|=PORT_PCR_MUX(2); /* Port B16: MUX = ALT2, FTM0CH1 */
	PORTB->PCR[17]|=PORT_PCR_MUX(2); /* Port B17: MUX = ALT2, FTM0CH1 */
	PORTE->PCR[9]|=PORT_PCR_MUX(2); /* Port B17: MUX = ALT2, FTM0CH1 */

}
