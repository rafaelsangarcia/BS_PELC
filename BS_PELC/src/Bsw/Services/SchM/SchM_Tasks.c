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
#include "communication.h"

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
	test();
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
