/*
 * EXT_INT_INTERFACE.h
 *
 * Created: 10/16/2024 7:08:15 PM
 *  Author: Eng_A
 */ 


#ifndef EXT_INT_INTERFACE_H_
#define EXT_INT_INTERFACE_H_




#include "MCAL/EXT_INT/EXT_INT_PRIVATE.h"



typedef enum
{
	LOW_LVL,
	CHANGE,
	FALLING_EDGE,
	RISING_EDGE
	}SENSE_MODE;
	
	
	
typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
}EXT_INT_LINES;
	
	
void  EXTI_INIT(EXT_INT_LINES LINE , SENSE_MODE MODE) ;

void  EXTI_DEINIT(EXT_INT_LINES LINE) ;

void EXTI_SET_CALLBACK(void (*ptr)(void) , EXT_INT_LINES LINE) ;

#endif /* EXT_INT_INTERFACE_H_ */