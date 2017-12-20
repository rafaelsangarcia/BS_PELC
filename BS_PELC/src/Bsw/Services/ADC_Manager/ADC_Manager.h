/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: ADC_Manager.h $
 * $Revision: 3 $
 * $Author: Rodrigo Mortera $
 * $Date: 20/12/2017 $
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
/*  AUTHOR           |        VERSION     | DECRIPTION    */
/*----------------------------------------------------------------------------*/
/*  Rodrigo Mortera  |         1           |  Add control ADC function        */
/*  Rodrigo Mortera  |         2           |  Add control ADC Clean Flag function*/
/*  Rodrigo Mortera  |         3           |  Enable FTM0 & FTM1 channels       */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef FILENAME_H
#define FILENAME_H

/* Includes */
#include "ADC.h"
/*============================================================================*/


/* Constants and types */
/*============================================================================*/


/* Exported Variables */
int dutyCycle, value;
/*============================================================================*/


/* Exported functions prototypes */
//percentage;

void Control_ADC (int);
void Control_ADC_clean_flag (void);
void PWM_0 (int channel);
void PWM_1 (int channel);
int Sensor(void);
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
