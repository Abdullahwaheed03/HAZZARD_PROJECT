
/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 26 - 9 - 2023   @ ***********************/
/**************** @ FILE   : SWITCH_PROGRAM  @ ***********************/
/**************** @ BRIEF  : SRC CODE        @ ***********************/
/*********************************************************************/




#include "HAL/SWITCH/SWITCH_INTERFACE.h"



SWITCH_ERROR_TYPE SWITCH_ENUM_INIT(SWITCH_CONFIG CONFIG)
{
	SWITCH_ERROR_TYPE STATUS = SWITCH_OK ;
	if (CONFIG.PORT <= PORTD && CONFIG.PIN <= PIN7 && CONFIG.CONNECTION <= EXT_PULLDOWN)
	{
		if (  CONFIG.CONNECTION == INT_PULLUP )
		{
			DIO_ENUM_SET_PIN_DIR(CONFIG.PORT,CONFIG.PIN,INPUT_PULLUP) ;
		}
		else
		{
			DIO_ENUM_SET_PIN_DIR(CONFIG.PORT,CONFIG.PIN,INPUT) ;
		}
	}
	else
	{
		STATUS = SWITCH_NOT_OK ;
	}
		return STATUS ;

}

SWITCH_ERROR_TYPE SWITCH_ENUM_GET_STATE(SWITCH_CONFIG CONFIG , uint8 *STATE_CPY) 
{
	SWITCH_ERROR_TYPE STATUS = SWITCH_OK ;
	uint8 DATA ;
	bool flag = FALSE ;
	if (CONFIG.PORT <= PORTD && CONFIG.PIN <= PIN7 && CONFIG.CONNECTION <= EXT_PULLDOWN)
	{
		switch(CONFIG.CONNECTION)
		{
			case EXT_PULLUP ... INT_PULLUP :
			{ 
				
				DIO_ENUM_GET_PIN_VAL(CONFIG.PORT,CONFIG.PIN,&DATA) ;
				
				while(DATA ==  0)
				{
					flag = TRUE ;
					DIO_ENUM_GET_PIN_VAL(CONFIG.PORT,CONFIG.PIN,&DATA) ;
				}
				if (flag == TRUE)
				{
					*STATE_CPY = PRESSED ;
					flag = FALSE ;
				}
				else if ( flag == FALSE  ) *STATE_CPY = NOT_PRESSED ;
			}break;
			case EXT_PULLDOWN :
			{
				DIO_ENUM_GET_PIN_VAL(CONFIG.PORT,CONFIG.PIN,&DATA) ;
				
				while(DATA ==  1)
				{
					flag = TRUE ;
					DIO_ENUM_GET_PIN_VAL(CONFIG.PORT,CONFIG.PIN,&DATA) ;
				}
				if (flag == TRUE)
				{
					*STATE_CPY = PRESSED ;
					flag = FALSE ;
				}
				else if ( flag == FALSE  ) *STATE_CPY = NOT_PRESSED ;
			}break;
			
		}
	}
	else
	{
		STATUS = SWITCH_NOT_OK ;
	}
	return STATUS ;
}





	