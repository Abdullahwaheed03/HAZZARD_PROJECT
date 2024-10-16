/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 14 - 10 - 2023  @ ***********************/
/**************** @ FILE   : KPD_PRG.C       @ ***********************/
/**************** @ BRIEF  : KPD_FUNCS       @ ***********************/
/*********************************************************************/


#include "HAL/KPD/KPD_INTERFACE.h"



/*   array of chars from kpd */ 
static uint8 KPD_U8_CHARS[4][4] = {
                                	{'7','8','9','/'} ,
									{'4','5','6','*'} ,
									{'3','2','1','-'} ,
									{'C','0','=','+'} ,
                                  };
                                

void KPD_INIT(void)
{
	
	DIO_ENUM_SET_PIN_DIR(KPD_PORT,ROW0,OUTPUT) ;
	DIO_ENUM_SET_PIN_DIR(KPD_PORT,ROW1,OUTPUT) ;
	DIO_ENUM_SET_PIN_DIR(KPD_PORT,ROW2,OUTPUT) ;
	DIO_ENUM_SET_PIN_DIR(KPD_PORT,ROW3,OUTPUT) ;
	
	DIO_ENUM_SET_PIN_DIR(KPD_PORT,COL0, INPUT_PULLUP) ;
	DIO_ENUM_SET_PIN_DIR(KPD_PORT,COL1, INPUT_PULLUP) ;
	DIO_ENUM_SET_PIN_DIR(KPD_PORT,COL2, INPUT_PULLUP) ;
	DIO_ENUM_SET_PIN_DIR(KPD_PORT,COL3, INPUT_PULLUP) ;
	
    DIO_ENUM_SET_PIN_VAL(KPD_PORT,ROW0,HIGH);
    DIO_ENUM_SET_PIN_VAL(KPD_PORT,ROW1,HIGH);
    DIO_ENUM_SET_PIN_VAL(KPD_PORT,ROW2,HIGH);
    DIO_ENUM_SET_PIN_VAL(KPD_PORT,ROW3,HIGH);
	
}													   



uint8 KPD_U8_GETPRESSED(void)
{
	
	bool flag = FALSE ;
	volatile uint8 counter0 , counter1 ;
	uint8 RETURN_DATA = 'N' ;
	for (PINS LOC_ROW  = ROW0  ,  counter0 = 0; LOC_ROW <= ROW3 ; LOC_ROW++  , counter0++ )
	{
		DIO_ENUM_SET_PIN_VAL(KPD_PORT,LOC_ROW,LOW);
		for (PINS LOC_COL = COL0 ,  counter1 = 0 ; LOC_COL <= COL3 ; LOC_COL++ , counter1++)
		{
			uint8 DATA ;
			DIO_ENUM_GET_PIN_VAL(KPD_PORT,LOC_COL,&DATA) ;
			while(DATA == LOW) 
			{
				DIO_ENUM_GET_PIN_VAL(KPD_PORT,LOC_COL,&DATA) ;
				flag = TRUE ;
			}
			if ( flag == TRUE )
			{
				RETURN_DATA = KPD_U8_CHARS[counter0][counter1] ;
				break ;
			}
			
			
		}
		DIO_ENUM_SET_PIN_VAL(KPD_PORT,LOC_ROW,HIGH);
		if (RETURN_DATA != 'N') break ;
	}
	
	return RETURN_DATA ;
}

