
/**********************************************************************/
/**************** @ AUTHOR : Abdullah waheed  @ ***********************/
/**************** @ DATE   : 26 - 9 - 2023    @ ***********************/
/**************** @ FILE   : SWITCH_INTERFACE @ ***********************/
/**************** @ BRIEF  : SWITCH FUNCS     @ ***********************/
/**********************************************************************/


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_


#include "MCAL/DIO/DIO_INTERFACE.h"
#include <util/delay.h>


#define PRESSED 1 
#define NOT_PRESSED  0 

   typedef enum 
   {
    EXT_PULLUP,
	INT_PULLUP,
	EXT_PULLDOWN
	}CONNECTIONS;
	

	
	typedef enum
	{
	  SWITCH_OK,
	  SWITCH_NOT_OK
	}SWITCH_ERROR_TYPE;
	
	
	typedef struct 
	{
	 PORTS PORT ;
	 PINS  PIN  ;
	 CONNECTIONS CONNECTION ;	
	}SWITCH_CONFIG;
	
	
	SWITCH_ERROR_TYPE SWITCH_ENUM_INIT(SWITCH_CONFIG CONFIG) ; /* INITALIZE  SWITCH PORT , PIN , CONNECTION   */ 
	
	SWITCH_ERROR_TYPE SWITCH_ENUM_GET_STATE(SWITCH_CONFIG CONFIG , uint8 *STATE_CPY) ; /* GET SWITCH STATE PRESSED OR N_PRESSED */ 
	
		



#endif /* SWITCH_INTERFACE_H_ */