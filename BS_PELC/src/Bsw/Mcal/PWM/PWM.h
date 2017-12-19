/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: PWM.h $
 * $Revision: 2 $
 * $Author: Rodrigo Mortera $
 * $Date: 19/12/2017 $
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
/*  AUTHOR             |        VERSION     | DESCRIPTION                   */
/*----------------------------------------------------------------------------*/
/*Rodrigo Mortera      |           1         |  Adding prototype functions for PWM*/
/*Rodrigo Mortera      |          2         | Adding prototype functions for FTM1*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef FILENAME_H
#define FILENAME_H

/* Includes */
#include "S32K144.h" /* include peripheral declarations S32K144 */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
void FTM0_init(void);
void FTM1_init(void);

void FTM0_CH_PWM_init(void);
void FTM1_CH_PWM_init(void);

void start_FTM0_counter (void) ;
void start_FTM1_counter (void) ;
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */




