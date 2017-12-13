/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Cfg.c
 * $Revision: 1
 * $Author: Rafael Sanchez
 * $Date: 12/Dic/2017
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
#include "CAN_message.h"
/*============================================================================*/
/* Constants and types  */
/*============================================================================*/
/* Variables */
int i = 0;
unsigned char mode = 0;
int cont_1 = 0;
unsigned char params[3];
int time_on, time_off = 0;
/*============================================================================*/
/* Private functions prototypes */
void CAN_message_void_fillParams();
void CAN_message_void_Turn_Right();
void CAN_message_void_Turn_Left();
void CAN_message_void_Hazard_ON();
/*============================================================================*/
/* Inline functions */
/*============================================================================*/
/* Private functions */
void CAN_message_void_fillParams(){
  ptr_struct= &rx_bytes;
  for(i = 0; i < rx_bytes.byte1; i++){
    params[i] = *(ptr_struct + 1 + i);
  }
}

void CAN_message_void_Turn_Right(){
  switch(mode){
    case 0:
      PTC->PSOR |= 1<<LedBar_1;
      cont_1++;
      if(cont_1 >= time_on){
        mode = 1;
        cont_1 = 0;
      }
      else {
        mode = 0;
      }
      break;

    case 1:
      PTC->PCOR |= 1<<LedBar_1;
      cont_1++;
      if(cont_1 >= time_off){
        mode = 0;
        cont_1 = 0;
      }
      else {
        mode = 1;
      }
      break;
  }
}

void CAN_message_void_Turn_Left(){
  switch(mode){
    case 0:
      PTC->PSOR |= 1<<LedBar_6;
      cont_1++;
      if(cont_1 >= time_on){
        mode = 1;
        cont_1 = 0;
      }
      else {
        mode = 0;
      }
      break;

    case 1:
      PTC->PCOR |= 1<<LedBar_6;
      cont_1++;
      if(cont_1 >= time_off){
        mode = 0;
        cont_1 = 0;
      }
      else {
        mode = 1;
      }
      break;
  }
}

void CAN_message_void_Hazard_ON(){
  switch(mode){
    case 0:
      PTC->PCOR |= 1<<LedBar_1;
      PTC->PCOR |= 1<<LedBar_6;
      cont_1++;
      if(cont_1 >= time_on){
        mode = 1;
        cont_1 = 0;
      }
      else {
        mode = 0;
      }
      break;

    case 1:
      PTC->PSOR |= 1<<LedBar_1;
      PTC->PSOR |= 1<<LedBar_6;
      cont_1++;
      if(cont_1 >= time_off){
        mode = 0;
        cont_1 = 0;
      }
      else {
        mode = 1;
      }
      break;
  }
}
/*============================================================================*/
/* Exported functions */
void CAN_message_void_fillStruct(){
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

void CAN_message_void_TurnBehavior(){
  CAN_message_void_fillParams();
  time_on = params[1] * 100;
  time_off = params[2] * 100;
  switch(params[0]){
    case 0x01:
    PTC->PCOR |= 1<<LedBar_1;
    PTC->PCOR |= 1<<LedBar_6;
    break;

    case 0x0A:
      CAN_message_void_Turn_Right();
    break;

    case 0x0B:
      CAN_message_void_Turn_Left();
    break;
  }
}

void CAN_message_void_Hazard(){
  CAN_message_void_fillParams();
  time_on = params[1] * 20;
  time_off = params[2] * 20;
  switch(params[0]){
    case 0x00:
    PTC->PCOR |= 1<<LedBar_1;
    PTC->PCOR |= 1<<LedBar_6;
    break;

    case 0x0F:
      CAN_message_void_Hazard_ON();
    break;
  }
}

/*============================================================================*/
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
