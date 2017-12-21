/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
 * $Revision: 3 $
 * $Author: Rodrigo Mortera $
 * $Date: 20/12/2017 $
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
/*  AUTHOR           |        VERSION     | DESCRIPTION                       */
/*----------------------------------------------------------------------------*/
/*  Rodrigo Mortera  |         1           |  Add control ADC function        */
/*  Rodrigo Mortera  |         2           |  Add control ADC Clean Flag function*/
/*  Rodrigo Mortera  |         3           |  Enable FTM0 & FTM1 channels       */

/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
#include "ADC_Manager.h"
/*============================================================================*/



/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/



/* Exported functions */
void Control_ADC (int percentage) {
	/*convertAdcChan(12);
	while(adc_complete()==0){}*/
	dutyCycle = (1251*percentage)/100;             //(read_adc_chx()*1251)/5000;
}

int Sensor(){
	convertAdcChan(12); /*use with pot*/
	//convertAdcChan(1);
	while(adc_complete()==0){}
	value = (read_adc_chx()*100)/5000;
	return value;
}

void Control_ADC_clean_flag (void) {
	convertAdcChan(29);                   /* Convert chan 29, Vrefsh */
	while(adc_complete()==0){}            /* Wait for conversion complete flag */
	//dutyCycle = read_adc_chx();       /* Get channel's conversion results in mv */
}

void PWM_0 (int channel){
	if (dutyCycle >= 0){
		FTM0->CONTROLS[channel].CnV = dutyCycle;
	}
}

void PWM_1 (int channel){
	if (dutyCycle >= 0){
		FTM1->CONTROLS[channel].CnV = dutyCycle;
	}
}
/*
  FTM0->CONTROLS[0].CnV = i;
			/*FTM0->CONTROLS[5].CnV = i;
			FTM0->CONTROLS[2].CnV = i;
			FTM0->CONTROLS[3].CnV = i;
			FTM0->CONTROLS[4].CnV = i;
			FTM0->CONTROLS[1].CnV = i;
			FTM1->CONTROLS[0].CnV = i;
			FTM1->CONTROLS[1].CnV = i;*/
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */



//int i=0;


