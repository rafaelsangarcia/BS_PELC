/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: params.h
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
 #ifndef BSW_SERVICES_CAN_PARAMS_H_
 #define BSW_SERVICES_CAN_PARAMS_H_

/* Includes */
#include "Std_Types.h"
#include "General.h"
#include "structs.h"

/*============================================================================*/

/* Constants and types */
/*============================================================================*/

/* Exported Variables */

unsigned char params[3], params2[3], params3[3], params4[3], params5[3], params6[3];
/*============================================================================*/


/* Exported functions prototypes */
void CAN_params_void_fillParams();
void CAN_params_void_fillParams2();
void CAN_params_void_fillParams3();
void CAN_params_void_fillParams4();
void CAN_params_void_fillParams5();
void CAN_params_void_fillParams6();
/*============================================================================*/
#endif /* BSW_SERVICES_SCHM_SCHM_CFG_H_ */
