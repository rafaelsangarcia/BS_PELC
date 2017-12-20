/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: structs.c
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
#include "structs.h"
#include "FLEXCAN.h"
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

void CAN_structs_void_fillStruct(){
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

void CAN_structs_void_fill_MainLightsStruct(){
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

void CAN_structs_void_fill_HazardStruct(){
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

void CAN_structs_void_fill_TurnStruct(){
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

void CAN_structs_void_fill_StopStruct(){
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

void CAN_structs_void_fill_ReverseStruct(){
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

/*============================================================================*/
/* Notice: the file ends with a blank new line to avoid compiler warnings */
