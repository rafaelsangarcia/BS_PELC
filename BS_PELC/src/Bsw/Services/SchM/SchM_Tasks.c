/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 ** $Source: SchM_Tasks.c $
 * $Revision: version 11 $
 * $Author: Rodrigo Mortera Peña $
 * $Date: 20/Dic/2017 $
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
/*  Rafael Sanchez   |      10             |  Split functions		              */
/*  Rodrigo Mortera  |      11            |  Add third light stop             */
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
#include "message.h"

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
		CAN_structs_void_fill_MainLightsStruct();
		CAN_params_void_fillParams4();
		FLEXCAN0_transmit_msg (17,0x15540000,tx_msg_data);
	}

	if ((CAN0->IFLAG1 >> 1) & 1){
		FLEXCAN0_receive_msg (1,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_structs_void_fill_HazardStruct();
		CAN_params_void_fillParams2();
		FLEXCAN0_transmit_msg (17,0x15540000,tx_msg_data);
	}
	if ((CAN0->IFLAG1 >> 2) & 1){
		FLEXCAN0_receive_msg (2,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_structs_void_fill_TurnStruct();
		CAN_params_void_fillParams3();
		FLEXCAN0_transmit_msg (18,0x04100000,tx_msg_data);
	}
	if ((CAN0->IFLAG1 >> 3) & 1){
		FLEXCAN0_receive_msg (3,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_structs_void_fill_ReverseStruct();
		CAN_params_void_fillParams6();
		FLEXCAN0_transmit_msg (18,0x04100000,tx_msg_data);
	}
	if ((CAN0->IFLAG1 >> 4) & 1){
		FLEXCAN0_receive_msg (4,rx_msg_data);
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		CAN_structs_void_fill_StopStruct();
		CAN_params_void_fillParams5();
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

/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */
