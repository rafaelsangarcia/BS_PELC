/*
 * Dio.h
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#ifndef BSW_MCAL_DIO_DIO_H_
#define BSW_MCAL_DIO_DIO_H_

#include "Std_Types.h"

typedef enum
{
	PORTCH_A,
	PORTCH_B,
	PORTCH_C,
	PORTCH_D,
	PORTCH_E
}DioPortType;

void Dio_PortSetPin(DioPortType DioPort, uint32_t DioPin);

void Dio_PortClearPin(DioPortType DioPort, uint32_t DioPin);

void Dio_PortTooglePin(DioPortType DioPort, uint32_t DioPin);


#endif /* BSW_MCAL_DIO_DIO_H_ */
