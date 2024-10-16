/*
 * GIE_PROGRAM.c
 *
 * Created: 10/16/2024 6:57:06 PM
 *  Author: Eng_A
 */ 


#include "MCAL/GIE/GIE_INTERFACE.h"




void GIE_VID_ENABLE() 
{
	BIT_SET(SREG,I_BIT) ;
}

void GIE_VID_DISABLE() 
{
	BIT_CLR(SREG,I_BIT) ;
}