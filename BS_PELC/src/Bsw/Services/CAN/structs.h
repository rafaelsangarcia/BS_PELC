/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: structs.h
 * $Revision: 6
 * $Author: Rafael Sanchez
 * $Date: 19/DIC/2017
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
/*  Rafael Sanchez   |      3            |  Create mainLights              	  */
/*  Rodrigo Mortera  |      4            |  Create Stop                       */
/*  Rafael Sanchez   |      5            |  Complete function                 */
/*  Rafael Sanchez   |      6             |  Split functions		              */
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
 #ifndef BSW_SERVICES_CAN_STRUCTS_H_
 #define BSW_SERVICES_CAN_STRUCTS_H_

/* Includes */
#include "Std_Types.h"
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

/*typedef struct
{
  unsigned char Hazard_Front_ON;
  unsigned char Hazard_Front_OFF;
  unsigned char Hazard_Rear_ON;
  unsigned char Hazard_Rear_OFF;
  unsigned char Turn_Front_ON;
  unsigned char Turn_Front_OFF;
  unsigned char Turn_Rear_ON;
  unsigned char Turn_Rear_OFF;
  unsigned char Position_Front_ON;
  unsigned char Position_Front_OFF;
  unsigned char Position_Rear_ON;
  unsigned char Position_Rear_OFF;
}percentage_struct;
*/

/*============================================================================*/

/* Exported Variables */
unsigned char *ptr_rx, *ptr_struct;
int i;
bytes_struct rx_bytes, hazardStruct, listenStruct, mainLightsStruct, turnStruct, stopStruct, reverseStruct;
/*============================================================================*/

/* Exported functions prototypes */
void CAN_structs_void_fillStruct();
void CAN_structs_void_fill_ListenStruct();
void CAN_structs_void_fill_MainLightsStruct();
void CAN_structs_void_fill_HazardStruct();
void CAN_structs_void_fill_TurnStruct();
void CAN_structs_void_fill_StopStruct();
void CAN_structs_void_fill_ReverseStruct();
/*============================================================================*/
#endif /* BSW_SERVICES_SCHM_SCHM_CFG_H_ */
