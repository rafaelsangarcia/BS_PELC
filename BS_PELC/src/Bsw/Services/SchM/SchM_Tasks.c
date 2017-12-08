/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 ** $Source: SchM_Tasks.c $
 * $Revision: version 2 $
 * $Author: Rafael Sanchez $
 * $Date: 17/Nov/2017 $
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
void SchM_3p125ms_Task ( void ){

	if ((CAN0->IFLAG1 >> 4) & 1)
	{  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
		FLEXCAN0_receive_msg (4,rx_msg_data);      /* Read message */
		PTD->PTOR |= 1<<16;         /*   toggle output port D16 (Green LED) */
		tx_msg_data[0]=rx_msg_data[0];
		tx_msg_data[1]=rx_msg_data[1];
		FLEXCAN0_transmit_msg (0,0x15540000,tx_msg_data);     /* MB0 word 1: Tx msg with STD ID 0x555 */
	}

	if ((CAN0->IFLAG1 >> 1) & 1)
    {  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
      FLEXCAN0_receive_msg (1,rx_msg_data);      /* Read message */

      PTD->PTOR &= (~(1<<16));         /*   toggle output port D16 (Green LED) */
      tx_msg_data[0]=rx_msg_data[0];
      tx_msg_data[1]=rx_msg_data[1];
      FLEXCAN0_transmit_msg (2,0x04100000,tx_msg_data );     /* MB0 word 1: Tx msg with STD ID 0x511  */
    }
}
/*
void SchM_6p25ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_B, LedBar_2);
	for(counter_2=0; counter_2 <= Cycles; counter_2++){}
}

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