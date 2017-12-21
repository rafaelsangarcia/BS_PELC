/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: LEDS.c
 * $Revision: 8
 * $Author: Rafael Sanchez
 * $Date: 19/Dic/2017
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
/*  Author           |        Version     |           DESCRIPTION             */
/*----------------------------------------------------------------------------*/
/*  Rafael Sanchez   |      1             |  Create Hazard and turn functions*/
/*  Rafael Sanchez   |      2             |  fix Scheduler					 				  */
/*  Rafael Sanchez   |      3             |  Merge PWM, prioritize hazard			*/
/*  Rafael Sanchez   |      4             |  Add mainLightsStruct							*/
/*  Rodrigo Mortera  |      5             |  Add stopStruct                   */
/*  Rodrigo Mortera  |      6             |  Add reverseStruct                */
/*  Rafael Sanchez   |      7             |  Add Auto mainLights              */
/*  Rafael Sanchez   |      8             |  Split functions		              */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 *
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */
/* ============================================================================*/

/* Includes */
#include "LEDS.h"
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

void CAN_LEDS_void_PWM_Hazard_FRONT(int percentage){
	Control_ADC(percentage);
	PWM_0(0);
	PWM_0(1);
}

void CAN_LEDS_void_PWM_Hazard_REAR(int percentage){
	Control_ADC(percentage);
	PWM_0(2);
	PWM_0(4);
}

void CAN_LEDS_void_PWM_Turn_Right_FRONT(int percentage){
	Control_ADC(percentage);
	PWM_0(0);
}

void CAN_LEDS_void_PWM_Turn_Left_FRONT(int percentage){
	Control_ADC(percentage);
	PWM_0(1);
}

void CAN_LEDS_void_PWM_Turn_Right_REAR(int percentage){
	Control_ADC(percentage);
	PWM_0(2);
}

void CAN_LEDS_void_PWM_Turn_Left_REAR(int percentage){
	Control_ADC(percentage);
	PWM_0(4);
}

void CAN_LEDS_void_PWM_Stop(int percentage){
	Control_ADC(percentage);
	PWM_0(5);
}

void CAN_LEDS_void_PWM_ThirdLightStop(int percentage){
	Control_ADC(percentage);
	PWM_1(0);
}

void CAN_LEDS_void_PWM_Reverse(int percentage){
	Control_ADC(percentage);
	PWM_0(6);
}

void CAN_LEDS_void_PWM_Heads(int percentage){
	Control_ADC(percentage);
	PWM_0(7);
}

/*============================================================================*/
/* Exported functions */

/*============================================================================*/
/* Notice: the file ends with a blank new line to avoid compiler warnings */
