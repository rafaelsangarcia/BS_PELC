/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: PWM.c $
 * $Revision: 1 $
 * $Author: Rodrigo Mortera $
 * $Date: 18/12/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  AUTHOR           |        VERSION       | DESCRIPTION                     */
/*----------------------------------------------------------------------------*/
/* Rodrigo Mortera   |         1            | Add PWM.C and enabled of PWM channels*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
#include "PWM.h"
/*============================================================================*/



/* Constants and types  */
/*============================================================================*/



/* Variables */
/*uint16_t CurrentCaptureVal = 0;
uint16_t PriorCaptureVal = 0;
uint16_t DeltaCapture = 0;*/
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
void FTM0_init(void) {
	PCC->PCCn[PCC_FTM0_INDEX] &= ~PCC_PCCn_CGC_MASK; /* Ensure clk disabled for config */
	PCC->PCCn[PCC_FTM0_INDEX] |= PCC_PCCn_PCS(0b001)/* Clock Src=1, 8 MHz SOSCDIV1_CLK */
				| PCC_PCCn_CGC_MASK; /* Enable clock for FTM regs */
	FTM0->MODE |= FTM_MODE_WPDIS_MASK; /* Write protect to registers disabled (default) */
	FTM0->SC = 0x00FF0007; /*Enable all the channels in PWM (0,1,2,3,4,5)*/
						   /* TOIE (Timer Overflow Interrupt Ena) = 0 (default) */
						   /* CPWMS (Center aligned PWM Select) = 0 (default, up count) */
						   /* CLKS (Clock source) = 0 (default, no clock; FTM disabled) */
						   /* PS (Prescaler factor) = 7. Prescaler = 128 */
	FTM0->COMBINE = 0x00000000;/* FTM mode settings used: DECAPENx, MCOMBINEx, COMBINEx=0 */
	FTM0->POL = 0x00000000; /* Polarity for all channels is active high (default) */
	FTM0->MOD = 1251 ; /* 62500 FTM1 counter final value (used for PWM mode) */
	/* FTM1 Period = MOD-CNTIN+0x0001 ~= 62500 ctr clks */
	/* 8MHz /128 = 62.5kHz -> ticks -> 1Hz */
}

void FTM1_init(void) {
	PCC->PCCn[PCC_FTM1_INDEX] &= ~PCC_PCCn_CGC_MASK; /* Ensure clk disabled for config */
	PCC->PCCn[PCC_FTM1_INDEX] |= PCC_PCCn_PCS(0b001)/* Clock Src=1, 8 MHz SOSCDIV1_CLK */
				| PCC_PCCn_CGC_MASK; /* Enable clock for FTM regs */
	FTM1->MODE |= FTM_MODE_WPDIS_MASK; /* Write protect to registers disabled (default) */
	FTM1->SC = 0x003F0007; /*Enable all the channels in PWM (0,1,2,3,4,5)*/
						   /* TOIE (Timer Overflow Interrupt Ena) = 0 (default) */
						   /* CPWMS (Center aligned PWM Select) = 0 (default, up count) */
						   /* CLKS (Clock source) = 0 (default, no clock; FTM disabled) */
						   /* PS (Prescaler factor) = 7. Prescaler = 128 */
	FTM1->COMBINE = 0x00000000;/* FTM mode settings used: DECAPENx, MCOMBINEx, COMBINEx=0 */
	FTM1->POL = 0x00000000; /* Polarity for all channels is active high (default) */
	FTM1->MOD = 1251 ; /* 62500 FTM1 counter final value (used for PWM mode) */
	/* FTM1 Period = MOD-CNTIN+0x0001 ~= 62500 ctr clks */
	/* 8MHz /128 = 62.5kHz -> ticks -> 1Hz */
}

void FTM0_CH_PWM_init(void) {
	FTM0->CONTROLS[5].CnSC = 0x00000028; /* FTM0 ch5: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[4].CnSC = 0x00000028; /* FTM0 ch4: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[3].CnSC = 0x00000028; /* FTM0 ch3: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[2].CnSC = 0x00000028; /* FTM0 ch2: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[1].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[0].CnSC = 0x00000028; /* FTM0 ch0: edge-aligned PWM, low true pulses */
	FTM0->CONTROLS[6].CnSC = 0x00000028; /* FTM0 ch5: edge-aligned PWM, low true pulses */
}

void FTM1_CH_PWM_init(void) {
	FTM1->CONTROLS[1].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
	FTM1->CONTROLS[0].CnSC = 0x00000028; /* FTM0 ch1: edge-aligned PWM, low true pulses */
}

void start_FTM0_counter (void) {
	FTM0->SC |= FTM_SC_CLKS(3);
}

void start_FTM1_counter (void) {
	FTM1->SC |= FTM_SC_CLKS(3);
}

/*============================================================================*/




/* Private functions */
/*============================================================================*/

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/



/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
