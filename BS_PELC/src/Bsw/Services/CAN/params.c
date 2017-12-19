/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: CAN_message.c
 * $Revision: 7
 * $Author: Rafael Sanchez
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
/*  Rodrigo Mortera  |      6             |  Add reverseStruct                */
/*  Rafael Sanchez   |      7             |  Add Auto mainLights              */
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
#include "params.h"
#include "structs.h"
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

/*============================================================================*/
/* Notice: the file ends with a blank new line to avoid compiler warnings */
