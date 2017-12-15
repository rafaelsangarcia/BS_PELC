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
#include "SchM.h"
#include "SchM_Tasks.h"
/*============================================================================*/



/* Constants and types  */
const SchM_TaskConfigType TaskDescriptor[]=
{
		{
				SCHM_TASKID_LISTEN,
				SCHM_MASK_LISTEN,
				SCHM_OFFSET_LISTEN,
				/* ... */
				SchM_LISTEN_Task
		},
		{
				SCHM_TASKID_HAZARD,
				SCHM_MASK_HAZARD,
				SCHM_OFFSET_HAZARD,
				SchM_HAZARD_Task
		},
		{
				SCHM_TASKID_TURN,
				SCHM_MASK_TURN,
				SCHM_OFFSET_TURN,
				SchM_TURN_Task
		}/*,
		{
				SCHM_TASKID_25MS,
				SCHM_MASK_25MS,
				SCHM_OFFSET_25MS,
				SchM_25ms_Task
		},
		{
				SCHM_TASKID_50MS,
				SCHM_MASK_50MS,
				SCHM_OFFSET_50MS,
				SchM_50ms_Task
		},
		{
				SCHM_TASKID_100MS,
				SCHM_MASK_100MS,
				SCHM_OFFSET_100MS,
				SchM_100ms_Task
		}*/

};

const SchM_ConfigType SchedulerConfig =
{
		sizeof(TaskDescriptor)/sizeof(SchM_TaskConfigType),
		&TaskDescriptor[0]
};
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
