/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: message.c
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
#include "message.h"
#include "ADC_Manager.h"
/*============================================================================*/
/* Constants and types  */
/*============================================================================*/
/* Variables */
int i = 0;
unsigned char mode = 0, mode_2=0;
int cont_1, cont_2, cont_3 = 0;

unsigned char dayLight=0;

int time_on, time_off, time_on_2, time_off_2, time_on_3, time_off_3 = 0;
int percent_MAX, percent_MIN = 0;
/*============================================================================*/
/* Private functions prototypes */
void CAN_message_void_Turn_Right();
void CAN_message_void_Turn_Left();
void CAN_message_void_Hazard_ON();
void CAN_message_void_MainLights_Auto();

/*============================================================================*/
/* Inline functions */
/*============================================================================*/
/* Private functions */

void CAN_message_void_Hazard_ON(){
	switch(mode){
	case 0:
		CAN_LEDS_void_PWM_Hazard_FRONT(percent_MIN);
		CAN_LEDS_void_PWM_Hazard_REAR(0);
		cont_2++;
		if(cont_2 >= time_on_2){
			mode = 1;
			cont_2 = 0;
		}
		else {
			mode = 0;
		}
		break;

	case 1:
		CAN_LEDS_void_PWM_Hazard_FRONT(100);
		CAN_LEDS_void_PWM_Hazard_REAR(100);
		cont_2++;
		if(cont_2 >= time_off_2){
			mode = 0;
			cont_2 = 0;
		}
		else {
			mode = 1;
		}
		break;
	}
}

void CAN_message_void_Turn_Right(){
	switch(mode_2){
	case 0:
		//PTB->PCOR |= 1<<LedBar_3;
		CAN_LEDS_void_PWM_Turn_Right_FRONT(percent_MIN);
		CAN_LEDS_void_PWM_Turn_Right_REAR(0);
		cont_3++;
		if(cont_3 >= time_on_3){
			mode_2 = 1;
			cont_3 = 0;
		}
		else {
			mode_2 = 0;
		}
		break;

	case 1:
		CAN_LEDS_void_PWM_Turn_Right_FRONT(100);
		CAN_LEDS_void_PWM_Turn_Right_REAR(100);
		cont_3++;
		if(cont_3 >= time_off_3){
			mode_2 = 0;
			cont_3 = 0;
		}
		else {
			mode_2 = 1;
		}
		break;
	}
}

void CAN_message_void_Turn_Left(){
	switch(mode_2){
	case 0:
		CAN_LEDS_void_PWM_Turn_Left_FRONT(percent_MIN);
		CAN_LEDS_void_PWM_Turn_Left_REAR(0);
		cont_3++;
		if(cont_3 >= time_on_3){
			mode_2 = 1;
			cont_3 = 0;
		}
		else {
			mode_2 = 0;
		}
		break;

	case 1:
		CAN_LEDS_void_PWM_Turn_Left_FRONT(100);
		CAN_LEDS_void_PWM_Turn_Left_REAR(100);
		cont_3++;
		if(cont_3 >= time_off_3){
			mode_2 = 0;
			cont_3 = 0;
		}
		else {
			mode_2 = 1;
		}
		break;
	}
}

void CAN_message_void_MainLights_Auto(){
	switch(dayLight){

	case 0: /*DAY*/
		percent_MIN = 0;
		CAN_LEDS_void_PWM_Heads(0);
		if(Sensor() <= 60 && Sensor() > 15){
			dayLight = 1;
		}
		break;

	case 1: /*afternoon*/
		percent_MIN = 5;
		CAN_LEDS_void_PWM_Heads(0);
		if(Sensor() <= 15){
			dayLight = 2;
		}
		break;

	case 2: /*Night*/
		percent_MIN = 5;
		CAN_LEDS_void_PWM_Heads(100);
		if(Sensor() >= 65){
			dayLight = 3;
		}
		break;

	case 3: /*Morning*/
		percent_MIN = 5;
		CAN_LEDS_void_PWM_Heads(0);
		if(Sensor() >= 80){
			dayLight = 0;
		}
		break;
	}
	Control_ADC_clean_flag();
}

/*============================================================================*/
/* Exported functions */

void CAN_message_void_TurnBehavior(){
	//CAN_message_void_fillParams3();
	time_on_3 = params3[1] * 5;
	time_off_3 = params3[2] * 5;
	switch(params3[0]){
	case 0x01:
		CAN_LEDS_void_PWM_Turn_Right_FRONT(percent_MIN);
		CAN_LEDS_void_PWM_Turn_Left_FRONT(percent_MIN);
		CAN_LEDS_void_PWM_Turn_Right_REAR(0);
		CAN_LEDS_void_PWM_Turn_Left_REAR(0);
		break;

	case 0x0A:
		CAN_message_void_Turn_Right();
		break;

	case 0x0B:
		CAN_message_void_Turn_Left();
		break;
	}
}

void CAN_message_void_Hazard(){
	//CAN_message_void_fillParams2();
	time_on_2 = params2[1] * 5;
	time_off_2 = params2[2] * 5;
	switch(params2[0]){
	case 0x00:
		hazardflag = 0;
		CAN_LEDS_void_PWM_Hazard_FRONT(percent_MIN);
		CAN_LEDS_void_PWM_Hazard_REAR(0);
		params2[0] = 0x01;
		break;

	case 0x01:
		hazardflag = 0;
		break;

	case 0x0F:
		hazardflag = 1;
		CAN_message_void_Hazard_ON();
		break;
	}
}

void CAN_message_void_Stop(){
	switch (params5[0]) {
	case 0x00:
		CAN_LEDS_void_PWM_Stop(percent_MIN);
		break;

	case 0x0F:
		CAN_LEDS_void_PWM_Stop(100);
		break;

	}
}

void CAN_message_void_Reverse(){
	switch (params6[0]) {
	case 0x00:
		CAN_LEDS_void_PWM_Reverse(0);
		break;

	case 0x0F:
		CAN_LEDS_void_PWM_Reverse(100);
		break;

	}
}

void CAN_message_void_MainLights(){
	switch (params4[0]) {
	case 0x01:
		percent_MAX = 100;
		percent_MIN = 0;
		CAN_LEDS_void_PWM_Heads(0);
		break;

	case 0x02:
		percent_MAX = 100;
		percent_MIN = 5;
		CAN_LEDS_void_PWM_Heads(0);
		break;

	case 0x03:
		percent_MAX = 100;
		percent_MIN = 5;
		CAN_LEDS_void_PWM_Heads(100);
		break;

	case 0x04:
		CAN_message_void_MainLights_Auto();
		break;

	default:
		percent_MIN = 5;
	break;
	}
}

/*============================================================================*/
/* Notice: the file ends with a blank new line to avoid compiler warnings */
