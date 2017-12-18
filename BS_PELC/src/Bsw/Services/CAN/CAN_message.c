/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: CAN_message.c
 * $Revision: 4
 * $Author: Rodrigo Mortera
 * $Date: 18/Dic/2017
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
#include "CAN_message.h"
#include "ADC_Manager.h"
/*============================================================================*/
/* Constants and types  */
/*============================================================================*/
/* Variables */
int i = 0;
unsigned char mode = 0, mode_2=0;
int cont_1, cont_2, cont_3 = 0;

int time_on, time_off, time_on_2, time_off_2, time_on_3, time_off_3 = 0;
int percent_MAX, percent_MIN = 0;
/*============================================================================*/
/* Private functions prototypes */
void CAN_message_void_fillParams();
void CAN_message_void_fillParams2();
void CAN_message_void_fillParams3();
void CAN_message_void_Turn_Right();
void CAN_message_void_Turn_Left();
void CAN_message_void_Hazard_ON();
void CAN_message_void_Hazard_FRONT(int);
void CAN_message_void_Hazard_REAR(int);
/*============================================================================*/
/* Inline functions */
/*============================================================================*/
/* Private functions */
void CAN_message_void_fillParams(){
	ptr_struct= &rx_bytes;
	for(i = 0; i < rx_bytes.byte1; i++){
		params[i] = *(ptr_struct + 1 + i);
	}
}

void CAN_message_void_fillParams2(){
	ptr_struct= &hazardStruct;
	for(i = 0; i < hazardStruct.byte1; i++){
		params2[i] = *(ptr_struct + 1 + i);
	}
}

void CAN_message_void_fillParams3(){
	ptr_struct= &turnStruct;
	for(i = 0; i < turnStruct.byte1; i++){
		params3[i] = *(ptr_struct + 1 + i);
	}
}

void CAN_message_void_fillParams4(){
	ptr_struct= &mainLightsStruct;
	for(i = 0; i < mainLightsStruct.byte1; i++){
		params4[i] = *(ptr_struct + 1 + i);
	}
}

void CAN_message_void_fillParams5(){
	ptr_struct= &stopStruct;
	for(i = 0; i < stopStruct.byte1; i++){
		params5[i] = *(ptr_struct + 1 + i);
	}
}

void CAN_message_void_fillParams6(){
	ptr_struct= &reverseStruct;
	for(i = 0; i < reverseStruct.byte1; i++){
		params6[i] = *(ptr_struct + 1 + i);
	}
}

void CAN_message_void_Turn_Right(){
	switch(mode_2){
	case 0:
		//PTB->PCOR |= 1<<LedBar_3;
		CAN_message_void_PWM_Turn_Right_FRONT(percent_MIN);
		CAN_message_void_PWM_Turn_Right_REAR(0);
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
		CAN_message_void_PWM_Turn_Right_FRONT(100);
		CAN_message_void_PWM_Turn_Right_REAR(100);
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
		CAN_message_void_PWM_Turn_Left_FRONT(percent_MIN);
		CAN_message_void_PWM_Turn_Left_REAR(0);
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
		CAN_message_void_PWM_Turn_Left_FRONT(100);
		CAN_message_void_PWM_Turn_Left_REAR(100);
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

void CAN_message_void_PWM_Hazard_FRONT(int percentage){
	Control_ADC(percentage);
	PWM_0(0);
	PWM_0(1);
}

void CAN_message_void_PWM_Hazard_REAR(int percentage){
	Control_ADC(percentage);
	PWM_0(2);
	PWM_0(4);
}

void CAN_message_void_PWM_Turn_Right_FRONT(int percentage){
	Control_ADC(percentage);
	PWM_0(0);
}

void CAN_message_void_PWM_Turn_Left_FRONT(int percentage){
	Control_ADC(percentage);
	PWM_0(1);
}

void CAN_message_void_PWM_Turn_Right_REAR(int percentage){
	Control_ADC(percentage);
	PWM_0(2);
}

void CAN_message_void_PWM_Turn_Left_REAR(int percentage){
	Control_ADC(percentage);
	PWM_0(4);
}

void CAN_message_void_PWM_Stop(int percentage){
	Control_ADC(percentage);
	PWM_0(5);
}

void CAN_message_void_PWM_Reverse(int percentage){
	Control_ADC(percentage);
	PWM_0(6);
}

void CAN_message_void_Hazard_ON(){
	switch(mode){
	case 0:
		CAN_message_void_PWM_Hazard_FRONT(percent_MIN);
		CAN_message_void_PWM_Hazard_REAR(0);
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
		CAN_message_void_PWM_Hazard_FRONT(100);
		CAN_message_void_PWM_Hazard_REAR(100);
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


/*============================================================================*/
/* Exported functions */


void CAN_message_void_fillStruct(){
	ptr_rx = rx_msg_data;
	ptr_rx = ptr_rx + 3;

	ptr_struct = &rx_bytes;

	for (i = 0 ; i < 8; i++){
		if ( i == 4 ){
			ptr_rx = ptr_rx + 8;
		}
		*ptr_struct = *ptr_rx;
		ptr_struct++;
		ptr_rx--;
	}
}

void CAN_message_void_fill_MainLightsStruct(){
	ptr_rx = rx_msg_data;
	ptr_rx = ptr_rx + 3;

	ptr_struct = &mainLightsStruct;

	for (i = 0 ; i < 8; i++){
		if ( i == 4 ){
			ptr_rx = ptr_rx + 8;
		}
		*ptr_struct = *ptr_rx;
		ptr_struct++;
		ptr_rx--;
	}
}

void CAN_message_void_fill_HazardStruct(){
	ptr_rx = rx_msg_data;
	ptr_rx = ptr_rx + 3;

	ptr_struct = &hazardStruct;

	for (i = 0 ; i < 8; i++){
		if ( i == 4 ){
			ptr_rx = ptr_rx + 8;
		}
		*ptr_struct = *ptr_rx;
		ptr_struct++;
		ptr_rx--;
	}
}

void CAN_message_void_fill_TurnStruct(){
	ptr_rx = rx_msg_data;
	ptr_rx = ptr_rx + 3;

	ptr_struct = &turnStruct;

	for (i = 0 ; i < 8; i++){
		if ( i == 4 ){
			ptr_rx = ptr_rx + 8;
		}
		*ptr_struct = *ptr_rx;
		ptr_struct++;
		ptr_rx--;
	}
}

void CAN_message_void_fill_StopStruct(){
	ptr_rx = rx_msg_data;
	ptr_rx = ptr_rx + 3;

	ptr_struct = &stopStruct;

	for (i = 0 ; i < 8; i++){
		if ( i == 4 ){
			ptr_rx = ptr_rx + 8;
		}
		*ptr_struct = *ptr_rx;
		ptr_struct++;
		ptr_rx--;
	}
}

void CAN_message_void_fill_ReverseStruct(){
	ptr_rx = rx_msg_data;
	ptr_rx = ptr_rx + 3;

	ptr_struct = &reverseStruct;

	for (i = 0 ; i < 8; i++){
		if ( i == 4 ){
			ptr_rx = ptr_rx + 8;
		}
		*ptr_struct = *ptr_rx;
		ptr_struct++;
		ptr_rx--;
	}
}

void test_void() {
	ptr_struct = &rx_bytes;
	for (i = 0; i < rx_bytes.byte1; i++ ){
		if ( *(ptr_struct + 1 + i) == 0x01){
			PTD->PCOR |= 1<<15;
			PTD->PSOR |= 1<<16;
		}
		else if (*(ptr_struct + 1 + i)  == 0x14){
			PTD->PSOR |= 1<<15;
			PTD->PCOR |= 1<<16;
		}
	}
}

void CAN_message_void_TurnBehavior(){
	//CAN_message_void_fillParams3();
	time_on_3 = params3[1] * 6;
	time_off_3 = params3[2] * 6;
	switch(params3[0]){
	case 0x01:
		CAN_message_void_PWM_Turn_Right_FRONT(percent_MIN);
		CAN_message_void_PWM_Turn_Left_FRONT(percent_MIN);
		CAN_message_void_PWM_Turn_Right_REAR(0);
		CAN_message_void_PWM_Turn_Left_REAR(0);
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
	time_on_2 = params2[1] * 25;
	time_off_2 = params2[2] * 25;
	switch(params2[0]){
	case 0x00:
		hazardflag = 0;
		CAN_message_void_PWM_Hazard_FRONT(percent_MIN);
		CAN_message_void_PWM_Hazard_REAR(0);
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
		CAN_message_void_PWM_Stop(percent_MIN);
		break;

	case 0x0F:
		CAN_message_void_PWM_Stop(100);
		break;

	}
}

void CAN_message_void_Reverse(){
	switch (params6[0]) {
	case 0x00:
		CAN_message_void_PWM_Reverse(percent_MIN);
		break;

	case 0x0F:
		CAN_message_void_PWM_Reverse(100);
		break;

	}
}

void CAN_message_void_MainLights(){
	switch (params4[0]) {
	case 0x01:
		percent_MAX = 100;
		percent_MIN = 0;
		break;

	case 0x02:
		percent_MAX = 100;
		percent_MIN = 20;
		break;

	}
}

/*============================================================================*/
/* Notice: the file ends with a blank new line to avoid compiler warnings */
