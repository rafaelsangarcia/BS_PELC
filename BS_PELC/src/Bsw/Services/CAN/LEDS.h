/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: CAN_message.h
 * $Revision: 5
 * $Author: Rafael Sanchez
 * $Date: 18/DIC/2017
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
 #ifndef BSW_SERVICES_CAN_CAN_LEDS_H_
 #define BSW_SERVICES_CAN_CAN_LEDS_H_

/* Includes */
#include "Std_Types.h"
#include "General.h"
#include "ADC_Manager.h"

/*============================================================================*/
/* Constants and types */
/*============================================================================*/
/* Exported Variables */

/*============================================================================*/
/* Exported functions prototypes */
void CAN_message_void_PWM_Hazard_FRONT(int);
void CAN_message_void_PWM_Hazard_REAR(int);
void CAN_message_void_PWM_Turn_Right_FRONT(int);
void CAN_message_void_PWM_Turn_Right_REAR(int);
void CAN_message_void_PWM_Turn_Left_FRONT(int);
void CAN_message_void_PWM_Turn_Left_REAR(int);
void CAN_message_void_PWM_Stop(int);
void CAN_message_void_PWM_Heads(int);
/*============================================================================*/
#endif /* BSW_SERVICES_SCHM_SCHM_CFG_H_ */
