/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
* $Source: SchM_Tasks.h $
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
/*  Rafael Sanchez   |      2             | Add Port.h                        */

/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
  #ifndef BSW_SERVICES_SCHM_SCHM_TASKS_H_
  #define BSW_SERVICES_SCHM_SCHM_TASKS_H_


/* Includes */
#include "Std_Types.h"
#include "Port.h"

/*============================================================================*/

/* Constants and types */
//#define Cycles (uint32_t)2000
/*============================================================================*/

/* Exported Variables */

/*============================================================================*/

/* Exported functions prototypes */
extern void SchM_LISTEN_Task ( void );
extern void SchM_HAZARD_Task ( void );
extern void SchM_TURN_Task ( void );
extern void SchM_STOP_Task ( void );/*
extern void SchM_6p25ms_Task ( void );
extern void SchM_12p5ms_Task ( void );
extern void SchM_25ms_Task ( void );
extern void SchM_50ms_Task ( void );
extern void SchM_100ms_Task ( void );*/
/*============================================================================*/

#endif /* BSW_SERVICES_SCHM_SCHM_TASKS_H_ */
