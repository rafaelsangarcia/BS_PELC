/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: CAN_message.h
 * $Revision: 2
 * $Author: Rafael Sanchez
 * $Date: 15/DIC/2017
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
/*  Rafael Sanchez   |      1             |  Add Prototype for Hazard and turn*/
/*  Rafael Sanchez   |      2             |  Create new variable to mgn sch	  */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 *
 * SchM_Cfg.h
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */
 /* ============================================================================*/
 #ifndef BSW_SERVICES_CAN_CAN_TYPES_H_
 #define BSW_SERVICES_CAN_CAN_TYPES_H_

/* Includes */
#include "Std_Types.h"
#include "FlexCAN.h"
#include "Dio.h"
#include "Port.h"
#include "General.h"
/*============================================================================*/


/* Constants and types */
typedef struct
{
  unsigned char byte1;
  unsigned char byte2;
  unsigned char byte3;
  unsigned char byte4;
  unsigned char byte5;
  unsigned char byte6;
  unsigned char byte7;
  unsigned char byte8;
}bytes_struct;
/*============================================================================*/


/* Exported Variables */
unsigned char  *ptr_rx, *ptr_struct, *ptr_hazard, *ptr_turn, *ptr_stop;
bytes_struct rx_bytes, hazardStruct, listenStruct, turnStruct, stopStruct;
unsigned char params[3], params2[3], params3[3], params4[3];
int hazardflag;
/*============================================================================*/


/* Exported functions prototypes */
void CAN_message_void_fillStruct();
void CAN_message_void_fill_ListenStruct();
void CAN_message_void_fill_HazardStruct();
void CAN_message_void_fill_TurnStruct();
void CAN_message_void_fill_StopStruct();
void test_void();
void CAN_message_void_TurnBehavior();
void CAN_message_void_Hazard();
void CAN_message_void_Stop();
/*============================================================================*/
#endif /* BSW_SERVICES_SCHM_SCHM_CFG_H_ */
