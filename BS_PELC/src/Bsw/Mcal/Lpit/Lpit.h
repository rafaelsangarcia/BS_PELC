/*
 * Lpit.h
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#ifndef BSW_MCAL_LPIT_LPIT_H_
#define BSW_MCAL_LPIT_LPIT_H_

#include "Std_Types.h"

void LPIT0_init ( tCallbackFunction Pit0Callback );
void LPIT0_Start ( void );
void LPIT0_Stop ( void );

#endif /* BSW_MCAL_LPIT_LPIT_H_ */
