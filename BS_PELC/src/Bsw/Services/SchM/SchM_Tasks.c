/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 ** $Source: SchM_Tasks.c $
 * $Revision: version 10 $
 * $Author: Rodrigo Mortera $
 * $Date: 19/Dic/2017 $
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
/*  Rafael Sanchez   |      1             |  Use the template and add the code*/
/*  Rafael Sanchez   |      2             | Fill each task turning on/off leds*/
/*  Rafael Sanchez   |      3             | Test Hazard and turn lights				*/
/*  Rafael Sanchez   |      4	            | Fix Scheduler	   				 				  */
/*  Rafael Sanchez   |      5	            | Fix Scheduler v2   				        */
/*  Rafael Sanchez   |      6             |  Merge PWM, prioritize hazard			*/
/*  Rafael Sanchez   |      7             |  Updates Task and add mainlight			*/
/*  Rodrigo Mortera  |      8             |  Add Stop command                 */
/*  Rodrigo Mortera  |      9             |  Add reverse command              */
/* Rodrigo Mortera   |      10            |  Add third light stop             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
#include "SchM_Tasks.h"
#include "Dio.h"
#include "FlexCAN.h"
#include "General.h"
#include "Port.h"
#include "CAN_message.h"

/*============================================================================*/

/* Constants and types  */
/*============================================================================*/

/* Variables */
int id = 0;
int j = 0;
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
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
void SchM_LISTEN_Task ( void ){
	PTD->PTOR |= 1<<BlueLed;

	if ((CAN0->IFLAG1 >> 0) & 1){
		FLEXCAN0_receive_msg (0,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_message_void_fill_MainLightsStruct();
		CAN_message_void_fillParams4();
		FLEXCAN0_transmit_msg (17,0x15540000,tx_msg_data);
	}

	if ((CAN0->IFLAG1 >> 1) & 1){
		FLEXCAN0_receive_msg (1,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_message_void_fill_HazardStruct();
		CAN_message_void_fillParams2();
		FLEXCAN0_transmit_msg (17,0x15540000,tx_msg_data);
	}
	if ((CAN0->IFLAG1 >> 2) & 1){
		FLEXCAN0_receive_msg (2,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_message_void_fill_TurnStruct();
		CAN_message_void_fillParams3();
		FLEXCAN0_transmit_msg (18,0x04100000,tx_msg_data);
	}
	if ((CAN0->IFLAG1 >> 3) & 1){
		FLEXCAN0_receive_msg (3,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_message_void_fill_ReverseStruct();
		CAN_message_void_fillParams6();
		FLEXCAN0_transmit_msg (18,0x04100000,tx_msg_data);
	}
	if ((CAN0->IFLAG1 >> 4) & 1){
		FLEXCAN0_receive_msg (4,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_message_void_fill_StopStruct();
		CAN_message_void_fill_ThirdLightStruct();
		CAN_message_void_fillParams5();
		CAN_message_void_fillParams7();
		FLEXCAN0_transmit_msg (18,0x04100000,tx_msg_data);
	}
}

void SchM_MAINLIGHTS_Task(void){

	CAN_message_void_MainLights();
}

void SchM_HAZARD_Task(void){

	CAN_message_void_Hazard();
}

void SchM_TURN_Task(void){

	if (hazardflag == 0){
		CAN_message_void_TurnBehavior();
	}
}

void SchM_STOP_Task(void){

	CAN_message_void_Stop();
	CAN_message_void_Reverse();

}

//void SchM_REVERSE_Task(void){
//	PTD->PTOR |= 1<<BlueLed;
/*if ((CAN0->IFLAG1 >> 3) & 1){
		FLEXCAN0_receive_msg (3,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_message_void_fill_ReverseStruct();
		CAN_message_void_fillParams6();
		FLEXCAN0_transmit_msg (18,0x04100000,tx_msg_data);
	}
	CAN_message_void_Reverse();*/

//}
/*

void SchM_12p5ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_B, LedBar_3);
	for(counter_3=0; counter_3 <= Cycles; counter_3++){}
}
void SchM_25ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_B, LedBar_4);
	for(counter_4=0; counter_4 <= Cycles; counter_4++){}
}
void SchM_50ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_B, LedBar_5);
	for(counter_5=0; counter_5 <= Cycles; counter_5++){}
}
void SchM_100ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_C, LedBar_6);
	for(counter_6=0;counter_6 <= Cycles; counter_6++){}
}*/
/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */
