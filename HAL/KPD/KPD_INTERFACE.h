/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 14 - 10 - 2023  @ ***********************/
/**************** @ FILE   : KPD_INTERFACE.h @ ***********************/
/**************** @ BRIEF  : KPD_PROTOTYPES  @ ***********************/
/*********************************************************************/



#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_


#include "avr/delay.h"
#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_INTERFACE.h"
#include "HAL/KPD/KPD_INTERFACE.h"
#include "HAL/KPD/KPD_CONFIG.h"
#include "HAL/KPD/KPD_PRIVATE.h"

void    KPD_INIT(void);
uint8   KPD_U8_GETPRESSED( void );

#endif 