/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 ** $Source: SchM_Tasks.c $
 * $Revision: version 4 $
 * $Author: Rafael Sanchez $
 * $Date: 13/Dic/2017 $
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
/*  Rafael Sanchez   |      4	            | Fix Scheduler											*/
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
	if ((CAN0->IFLAG1 >> 4) & 1)
	{
		FLEXCAN0_receive_msg (4,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		FLEXCAN0_transmit_msg (0,0x15540000,tx_msg_data);
		CAN_message_void_fillStruct();
		id = 1;
	}
	if ((CAN0->IFLAG1 >> 1) & 1)
	{
		FLEXCAN0_receive_msg (1,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		FLEXCAN0_transmit_msg (2,0x04100000,tx_msg_data );
		id = 2;
	}
	CAN_message_void_fillStruct();
	//CAN_message_void_Hazard();
	//CAN_message_void_TurnBehavior();
	//CAN_message_void_Hazard();
}

void SchM_HAZARD_Task ( void ){
	//PTC->PTOR |= 1<<LedBar_1;
	if (id == 1){
		CAN_message_void_Hazard();
	}
}
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
