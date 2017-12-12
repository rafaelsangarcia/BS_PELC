/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Cfg.c
 * $Revision: 1
 * $Author: Rodrigo Mortera
 * $Date: 17/NOV/2017
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
/*  Rodrigo Mortera   |      1             |  Use the template and add the code*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 *
 * SchM_Cfg.c
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

/* Constants and types  */
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
/* Variables */
unsigned char  *ptr_rx, *ptr_struct;
bytes_struct rx_bytes;
/*============================================================================*/
/* Private functions prototypes */
void CAN_message_void_fillStruct();
void test_void();
void CAN_message_void_Turn();
/*============================================================================*/

/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/

#endif /* BSW_SERVICES_SCHM_SCHM_TASKS_H_ */

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
