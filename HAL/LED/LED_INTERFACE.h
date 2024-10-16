/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 26 - 9 - 2023   @ ***********************/
/**************** @ FILE   : LED_INTERFACE.h @ ***********************/
/**************** @ BRIEF  : LED FUNCTIONS   @ ***********************/
/*********************************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "MCAL/DIO/DIO_INTERFACE.h"

/******************************* LED ACTIVATION TYPE  *********************************/
typedef enum
{
	ACTIVE_HIGH,
	ACTIVE_LOW
}ACTIVATION_TYPE;
/**************************************************************************************/

/******************************* LED ERROR TYPE  *********************************/
typedef enum
{
	LED_OK,
	LED_NOT_OK 
	
}LED_ERROR_TYPE;
/**************************************************************************************/




/******************************* LED CONFIG STRUCTURE *********************************/

typedef struct
{
	PORTS PORT ;
	PINS  PIN  ;
	ACTIVATION_TYPE TYPE ;
	}LED_CONFIG;

/**************************************************************************************/





LED_ERROR_TYPE LED_ENUM_INIT(LED_CONFIG CONFIG) ;  /* LED INITALIZE FUNCTION */ 



LED_ERROR_TYPE LED_ENUM_ON(LED_CONFIG CONFIG) ;  /* TURN LED ON FUNCTION */



LED_ERROR_TYPE LED_ENUM_OFF(LED_CONFIG CONFIG) ; /* TURN LED OFF FUNCTION */



LED_ERROR_TYPE LED_ENUM_TOGGLE(LED_CONFIG CONFIG) ; /* TOGGLE LED STATE FUNCTION */ 

#endif /* LED_INTERFACE_H_ */