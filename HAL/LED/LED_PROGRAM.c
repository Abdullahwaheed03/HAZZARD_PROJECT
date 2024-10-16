/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 26 - 9 - 2023   @ ***********************/
/**************** @ FILE   : LED_PROGRAM.c   @ ***********************/
/**************** @ BRIEF  : SRC CODE        @ ***********************/
/*********************************************************************/



#include "HAL/LED/LED_INTERFACE.h"
#include "HAL/LED/LED_CONFIG.h"
#include "HAL/LED/LED_PRIVATE.h"

LED_ERROR_TYPE LED_ENUM_INIT(LED_CONFIG CONFIG)
{
	
	LED_ERROR_TYPE state = LED_OK ;
	if (CONFIG.PORT <= PORTD && CONFIG.PIN <= PIN7 && CONFIG.TYPE <= ACTIVE_LOW)
	{
		DIO_ENUM_SET_PIN_DIR(CONFIG.PORT,CONFIG.PIN,OUTPUT) ;
	}
	else
	{
		state = LED_NOT_OK ;
	}

	return state ;
	
}



LED_ERROR_TYPE LED_ENUM_ON(LED_CONFIG CONFIG)
{
	LED_ERROR_TYPE state = LED_OK ;
	if (CONFIG.PORT <= PORTD && CONFIG.PIN <= PIN7 && CONFIG.TYPE <= ACTIVE_LOW)
	{
		if (CONFIG.TYPE ==  ACTIVE_HIGH)
		{
			DIO_ENUM_SET_PIN_VAL(CONFIG.PORT,CONFIG.PIN,HIGH);
		}
		else if (CONFIG.TYPE ==  ACTIVE_LOW)
		{
			DIO_ENUM_SET_PIN_VAL(CONFIG.PORT,CONFIG.PIN,LOW);
		}
	}
	else
	{
		state = LED_NOT_OK ;
	}
	
	return state ;
	
	
	
}



LED_ERROR_TYPE LED_ENUM_OFF(LED_CONFIG CONFIG) 
{
		LED_ERROR_TYPE state = LED_OK ;
		if (CONFIG.PORT <= PORTD && CONFIG.PIN <= PIN7 && CONFIG.TYPE <= ACTIVE_LOW)
		{
			if (CONFIG.TYPE ==  ACTIVE_HIGH)
			{
				DIO_ENUM_SET_PIN_VAL(CONFIG.PORT,CONFIG.PIN,LOW);
			}
			else if (CONFIG.TYPE ==  ACTIVE_LOW)
			{
				DIO_ENUM_SET_PIN_VAL(CONFIG.PORT,CONFIG.PIN,HIGH);
			}
		}
		else
		{
			state = LED_NOT_OK ;
		}
		
		return state ;
		
		
}



LED_ERROR_TYPE LED_ENUM_TOGGLE(LED_CONFIG CONFIG)
{
		LED_ERROR_TYPE state = LED_OK ;
		if (CONFIG.PORT <= PORTD && CONFIG.PIN <= PIN7 && CONFIG.TYPE <= ACTIVE_LOW)
		{
		   DIO_ENUM_TOGGLE_PIN_VAL(CONFIG.PORT,CONFIG.PIN);
		}
		else
		{
			state = LED_NOT_OK ;
		}
		
		return state ;
		
		
}












