/**********************************************************************/
/**************** @ AUTHOR : Abdullah waheed  @ ***********************/
/**************** @ DATE   :  7- 10 - 2023    @ ***********************/
/**************** @ FILE   : LCD_PROGRAM.c    @ ***********************/
/**************** @ BRIEF  : LCD LIB SRC CODE @ ***********************/
/********************************************1*************************/



/******************** HOW LCD WORKS   8 BIT MODE ****************/  /******************** HOW LCD WORKS   4 BIT MODE ****************/
/*  YOU HAVE TWO OPTIONS                                                                       YOU HAVE TWO OPTIONS   
                                                 
  1-  SEND COMMAND                                                                                1-  SEND COMMAND 
  2-  SEND DATA 														                          2-  SEND DATA 
  
  FIRSTLY TO SEND COMMANDS YOU HAVE TO FOLLOW THIS 						    FIRSTLY TO SEND COMMANDS YOU HAVE TO FOLLOW THIS
  1-   SEND COMMAND ON DATA PORT 											                        1-   SEND  MSBS FROM COMMAND ON DATA PINS 
  2-   REST RS PIN 															                        2-   REST RS PIN 
  3-   SET  EN PIN																                    3-   SET  EN PIN
  4-   WAIT FOR SMALL DELAY 100US TO 1MS										                    4-   WAIT FOR SMALL DELAY 100US TO 1MS
  5-   RESET EN PIN																	                5-   RESET EN PIN
  6-   WAIT FOR SMALL DELAY 100US TO 1MS												            6-   SEND  LSBS FROM COMMAND ON DATA PINS
  																						            7-   SET  EN PIN
									  															    8-   RESET EN PIN
									  													   
  AFTER INIT LCD  TO SEND DATA FOLLOW THIS                                                       AFTER INIT LCD  TO SEND DATA FOLLOW THIS 
  			                             														    1-   SEND  MSBS FROM DATA ON DATA PINS
   1-   SEND DATA ON DATA PORT																		2-   SET RS PIN 
   2-   SET RS PIN																				    3-   SET  EN PIN
   3-   SET  EN PIN																				    4-   WAIT FOR SMALL DELAY 100US TO 1MS
   4-   WAIT FOR SMALL DELAY 100US TO 1MS														    5-   RESET EN PIN
   5-   RESET EN PIN																			    6-   SEND  MSBS FROM DATA ON DATA PINS
   6-   WAIT FOR SMALL DELAY 100US TO 1MS															7-   SET  EN PIN
   																								    8-   RESET EN PIN
   
   
  
   /*************************************************************/


#include "HAL/LCD/LCD_INTERFACE.h"


LCD_ERROR LCD_CMD(LCD_CONFIG LCD,uint8 command)
{
	LCD_ERROR STATUS = LCD_OK ;
	if (LCD.DATA <= PORTD && LCD.CONTROL <= PORTD )
	{
		#if (LCD_MODE == 8)
		{
			DIO_ENUM_SET_PORT_VAL(LCD.DATA,command) ;
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.RS,LOW);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.RW,LOW);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,HIGH);
			_delay_ms(1);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,LOW);
			_delay_ms(1);
		}
		#elif (LCD_MODE == 4)
		{
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D7,BIT_GET(command,7));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D6,BIT_GET(command,6));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D5,BIT_GET(command,5));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D4,BIT_GET(command,4));
             
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.RS,LOW);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.RW,LOW);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,HIGH);
			_delay_ms(1);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,LOW);
			_delay_ms(1);
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D7,BIT_GET(command,3));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D6,BIT_GET(command,2));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D5,BIT_GET(command,1));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D4,BIT_GET(command,0));
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,HIGH);
			_delay_ms(1);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,LOW);
			_delay_ms(1);
			
		}
		#endif
	}
	else
	{
		STATUS = LCD_NOK ;
	}
	return STATUS ;
}


LCD_ERROR LCD_INIT(LCD_CONFIG LCD)
{
	LCD_ERROR STATUS = LCD_OK ;
	_delay_ms(50);
	if (LCD.DATA <= PORTD && LCD.CONTROL <= PORTD )
	{
		DIO_ENUM_SET_PIN_DIR(LCD.CONTROL,LCD.RW,OUTPUT) ;	 /* INIT CONTROL PINS AS OUTPUT */
		DIO_ENUM_SET_PIN_DIR(LCD.CONTROL,LCD.RS,OUTPUT) ;	 /* INIT CONTROL PINS AS OUTPUT */
		DIO_ENUM_SET_PIN_DIR(LCD.CONTROL,LCD.EN,OUTPUT) ;	 /* INIT CONTROL PINS AS OUTPUT */

		#if (LCD_MODE == 8)
		{
		  DIO_ENUM_SET_PORT_DIR(LCD.DATA,OUTPUT);            /* INIT DATA PORT AS OUTPUT */	
		  LCD_CMD(LCD,LCD_8BIT_MODE)	;                    /* SEND 8BIT MODE COMMAND FOR LCD */ 
		}
		#elif (LCD_MODE == 4)
		{
		DIO_ENUM_SET_PIN_DIR(LCD.DATA,LCD.D7,OUTPUT);         /* SETUP DATA PINS AS OUTPUT D7 */
		DIO_ENUM_SET_PIN_DIR(LCD.DATA,LCD.D6,OUTPUT);         /* SETUP DATA PINS AS OUTPUT D6 */
		DIO_ENUM_SET_PIN_DIR(LCD.DATA,LCD.D5,OUTPUT);         /* SETUP DATA PINS AS OUTPUT D5 */
		DIO_ENUM_SET_PIN_DIR(LCD.DATA,LCD.D4,OUTPUT);         /* SETUP DATA PINS AS OUTPUT D4 */
		LCD_CMD(LCD,RETURN_HOME);                                 /* COMMAND TO INIT LCD */
		LCD_CMD(LCD,LCD_4BIT_MODE);                               /* COMMAND TO MAKE LCD CNFG AS 4BIT MODE */
		}											          
		#endif
		LCD_CMD(LCD,LCD_DISPLAY_ON_CURSOR_OFF);                    /* SEND DISPLAY ON COMMAND FOR LCD */
		LCD_CMD(LCD,LCD_CLR) ;                                    /* SEND CLEAR COMMAND FOR LCD */
		LCD_CMD(LCD,LCD_CURSOR_SHIFT_RIGHT);                      /* COMMAND TO SHIFT CURSOR */
	}
	else
	{
		STATUS = LCD_NOK ;
	}
	return STATUS ;
}



LCD_ERROR LCD_WRITE_STRING(LCD_CONFIG LCD, const uint8 *data)
{
	uint16 index = 0 ;
	while (data[index] !=  0 )
	{
		LCD_WRITE_CHAR(LCD,data[index++]);
	}
}


LCD_ERROR LCD_WRITE_CHAR(LCD_CONFIG LCD,const uint8 data)
{
	LCD_ERROR STATUS = LCD_OK ;
	if (LCD.DATA <= PORTD && LCD.CONTROL <= PORTD )
	{
		#if (LCD_MODE == 8)
		{
			DIO_ENUM_SET_PORT_VAL(LCD.DATA,data) ;
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.RS,HIGH);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.RW,LOW);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,HIGH);
			_delay_ms(1);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,LOW);
			_delay_ms(1);
		}
		#elif (LCD_MODE == 4)
		{
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D7,BIT_GET(data,7));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D6,BIT_GET(data,6));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D5,BIT_GET(data,5));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D4,BIT_GET(data,4));
			
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.RS,HIGH);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.RW,LOW);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,HIGH);
			_delay_ms(1);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,LOW);
			_delay_ms(1);
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D7,BIT_GET(data,3));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D6,BIT_GET(data,2));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D5,BIT_GET(data,1));
			DIO_ENUM_SET_PIN_VAL(LCD.DATA,LCD.D4,BIT_GET(data,0));
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,HIGH);
			_delay_ms(1);
			DIO_ENUM_SET_PIN_VAL(LCD.CONTROL,LCD.EN,LOW);
			_delay_ms(1);
			
		}
		#endif
	}
	else
	{
		STATUS = LCD_NOK ;
	}
	return STATUS ;
}


LCD_ERROR LCD_SET_CURSOR(LCD_CONFIG LCD,uint8 ROW , uint8 COLOM) 
{
	LCD_ERROR STATUS = LCD_OK ;
	if (LCD.DATA <= PORTD && LCD.CONTROL <= PORTD )
	{
		switch(LCD.TYPE)
		{
			case LCD16X2 :
			{
				switch (ROW) 
				{
					case 0 : LCD_CMD(LCD,0X80 + COLOM) ; break;
					case 1 : LCD_CMD(LCD,0XC0 + COLOM) ; break;
				}
			}break;
			case LCD20X4 : 
			{
				switch (ROW)
				{
					case 0 : LCD_CMD(LCD,0X80 + COLOM) ; break;
					case 1 : LCD_CMD(LCD,0XC0 + COLOM) ; break;
					case 2 : LCD_CMD(LCD,0X94 + COLOM) ; break;
					case 3 : LCD_CMD(LCD,0XD4 + COLOM) ; break;
				}
			}break ;
			
		}
	}
	else
	{
		STATUS = LCD_NOK ;
	}
	return STATUS ;
}


LCD_ERROR LCD_WRITE_NUM(LCD_CONFIG LCD,sint32 num) 
{
	char data[10] ;
	itoa(num,data,10);
	LCD_WRITE_STRING(LCD,data) ;
}


LCD_ERROR LCD_CLEAR(LCD_CONFIG LCD)
	{
		LCD_CMD(LCD,LCD_CLR);
	}

