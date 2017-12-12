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

/* Includes */
#include "CAN_message.h"


/*============================================================================*/



/* Constants and types  */

/*============================================================================*/



/* Variables */
int i = 0;
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/


/* Exported functions */
void CAN_message_void_fillStruct(){
  ptr_rx = rx_msg_data;
  ptr_rx = ptr_rx + 3;

  ptr_struct = &rx_bytes;
  ptr_struct = ptr_struct;

  for (i = 0 ; i < 8; i++){
    if ( i == 4 ){
      ptr_rx = ptr_rx + 8;
    }
    *ptr_struct = *ptr_rx;
    ptr_struct++;
    ptr_rx--;
  }
}

void test_void() {
  ptr_struct = &rx_bytes;
  for (i = 0; i < rx_bytes.byte1; i++ ){
    if ( *(ptr_struct + 1 + i) == 0x01){
      PTD->PCOR |= 1<<15;
      PTD->PSOR |= 1<<16;
    }
    else if (*(ptr_struct + 1 + i)  == 0x14){
      PTD->PSOR |= 1<<15;
      PTD->PCOR |= 1<<16;
    }
  }
}
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
