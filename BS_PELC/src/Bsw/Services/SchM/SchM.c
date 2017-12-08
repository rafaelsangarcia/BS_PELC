/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM.c $
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
/*     				 |                    |  tasks status changes			  */
/* Rodrigo Mortera   |      3             | include overload, background functions*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
#include "General.h"
#include "SchM.h"
#include "Lpit.h"
/* #include "Dio.h" line must be removed as it is just an example to access on Port D pin 0 !!!
 * Note: Dio module provides access to all Dio (Digital Input Output channels configured as GPIO). The user must ensure that
 *       the PORT pins are properly configured from Port module as GPIO input or output channel from the intended PORT
 *       Currently the Port module configures the Port E channel 0 only as an output
 *
 *       Please: Remove this comment !
 *
 *  */
#include "Dio.h"
/*============================================================================*/

/* Constants and types  */
/*============================================================================*/

/* Variables */
FlagsStatus FlagsScheduler = {
	0,0
};
uint32_t OsTickCounter = 0; /* Remove this line */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/

/* Exported functions */
void SchM_OsTick( void ){
	uint8_t LocTaskIdx;
	SchM_SchedulerStatus.OsTickCounter++;
	for(LocTaskIdx = 0; LocTaskIdx < GlbSchMConfig->NumOfTasks; LocTaskIdx++){

		if((SchM_SchedulerStatus.OsTickCounter & GlbSchMConfig->TaskConfig[LocTaskIdx].TaskMask) == GlbSchMConfig->TaskConfig[LocTaskIdx].TaskOffset){

			if(FlagsScheduler.FlagTaskState == 1) {
				FlagsScheduler.FlagOverLoad = 1;
				SetOverloadState(); 					 //TurnOn the OVERLOADPIN
			}
					SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState=SCHM_TASK_STATE_READY;
					FlagsScheduler.FlagTaskState = 1;
			}
	}
}
void SchM_Background( void ){

	uint8_t LocTaskIdx;

	for(;;)
	{
		for(LocTaskIdx = 0; LocTaskIdx < GlbSchMConfig->NumOfTasks; LocTaskIdx++)
		{
			if ( SCHM_TASK_STATE_READY == SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState )
			{
				SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState = SCHM_TASK_STATE_RUNNING;
				SchM_SchedulerStatus.SchM_SchedulerState = SCHM_RUNNING;
				SetOffBackgroundState();
				GlbSchMConfig->TaskConfig[LocTaskIdx].TaskCallback();
				SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState = SCHM_TASK_STATE_SUSPENDED;
				FlagsScheduler.FlagTaskState = 0 ;
				SchM_SchedulerStatus.SchM_SchedulerState = SCHM_IDLE;
				SetBackgroundState();
			}
		}
	}
}
void SchM_Init( const SchM_ConfigType *SchMConfig ){
	GlbSchMConfig = SchMConfig;
	uint8_t LocTaskIdx;
	SchM_SchedulerStatus.SchM_SchedulerState = SCHM_UNINIT;

	for(LocTaskIdx = 0; LocTaskIdx < GlbSchMConfig->NumOfTasks; LocTaskIdx++)
	{
		SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState = SCHM_TASK_STATE_SUSPENDED;
	}

	LPIT0_init(SchM_OsTick);            /* Initialize PIT0 for 781.25 micro-seconds timeout & Callback Install */

	SchM_SchedulerStatus.SchM_SchedulerState = SCHM_INIT;
}
void SchM_Start( void ){
	LPIT0_Start();
	SchM_Background();
}
void SchM_Stop( void ){
	LPIT0_Stop();
}

void SetOverloadState(void){
	Dio_PortClearPin(PORTCH_D,RedLed);
}

void SetBackgroundState(void){
	Dio_PortClearPin(PORTCH_D,BlueLed);
}

void SetOffBackgroundState(void){
	Dio_PortSetPin(PORTCH_D,BlueLed);

}
/*============================================================================*/

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
