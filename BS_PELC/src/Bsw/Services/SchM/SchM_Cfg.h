/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Cfg.h
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
 * SchM_Cfg.h
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */
 /* ============================================================================*/
#ifndef BSW_SERVICES_SCHM_SCHM_CFG_H_
#define BSW_SERVICES_SCHM_SCHM_CFG_H_

/* Includes */
#include "Std_Types.h"
/*============================================================================*/


/* Constants and types */
typedef uint8_t SchM_TaskOffsetType;

typedef enum{
	SCHM_OFFSET_3P125MS = (T_UBYTE) 0x00u,
} Schm_TaskOffsetType;

typedef enum{
	SCHM_MASK_3P125MS = 0x03,
}SchM_TaskMaskType;

typedef enum {
	SCHM_TASKID_BKG,
	SCHM_TASKID_3P125MS,
}SchM_TaskIDType;

typedef struct{
	SchM_TaskIDType TaskID;
	SchM_TaskMaskType TaskMask;
	SchM_TaskOffsetType TaskOffset;
	/* .. */
	tCallbackFunction TaskCallback;
}SchM_TaskConfigType;


typedef struct {
	uint8_t NumOfTasks;
	const SchM_TaskConfigType *TaskConfig;
}SchM_ConfigType;

const SchM_ConfigType SchedulerConfig;
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
#endif /* BSW_SERVICES_SCHM_SCHM_CFG_H_ */
