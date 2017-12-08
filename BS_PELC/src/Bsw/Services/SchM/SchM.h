/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
* $Source: SchM.h $
* $Revision: version 3 $
* $Author: Rodrigo Mortera $
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
/*  Rafael Sanchez   |      2             |  Update OsTick, difenes where the */
/*     				|                    |  tasks status change               */
/* Rodrigo Mortera   |      3             | include overload, background functions*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef BSW_SERVICES_SCHM_SCHM_H_
#define BSW_SERVICES_SCHM_SCHM_H_

/* Includes */
#include "Std_Types.h"
#include "SchM_Cfg.h"
#include "SchM_Types.h"
#include "Port.h"
/*============================================================================*/

/* Constants and types */
#define NUM_OF_TASKS (0x1)

const SchM_ConfigType *GlbSchMConfig;

typedef struct {
  uint8_t FlagOverLoad: 1;
  uint8_t FlagTaskState: 1;
}FlagsStatus;

/*============================================================================*/

/* Exported Variables */
SchM_TaskControlBlockType SchM_TaskControlBlock[NUM_OF_TASKS];
SchM_SchedulerStatusType SchM_SchedulerStatus;
uint8_t LocTaskIdx;

/*============================================================================*/

/* Exported functions prototypes */
extern void SchM_Init( const SchM_ConfigType *SchMConfig );
extern void SchM_Start( void );
extern void SchM_Stop( void );
void SetOverloadState(void);
void SetBackgroundState(void);
void SetOffBackgroundState(void);
/*============================================================================*/

#endif /* BSW_SERVICES_SCHM_SCHM_H_ */
