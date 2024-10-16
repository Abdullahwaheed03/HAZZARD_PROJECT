/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 7 - 10 - 2023   @ ***********************/
/**************** @ FILE   : LCD_INTERFACE.h @ ***********************/
/**************** @ BRIEF  : LCD FUNCS       @ ***********************/
/*********************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include <util/delay.h>
#include <stdlib.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"
#include "HAL/LCD/LCD_CONFIG.h"



typedef enum 
{
	LCD_OK,
	LCD_NOK
	}LCD_ERROR;
	
	
	

	/***********************************LCD_Start_Commands*****************************/
	#define LCD_CLR  0X01
	#define LCD_CURSOR_FIRST_LINE 0X80
	#define LCD_4BIT_MODE 0x28
	#define LCD_8BIT_MODE 0x38
	#define LCD_CURSOR_ON 0x0c
	#define LCD_DISPLAY_ON_CURSOR_OFF 0x0C
	#define LCD_DISPLAY_OFF_CURSOR_OFF 0X08
	#define LCD_DISPLAY_ON_CURSOR_ON 0X0E
	#define LCD_DISPLAY_OFF_CURSOR_ON 0X0A
	#define LCD_CURSOR_SEC_LINE 0XC0
	#define LCD_SHIFT_LEFT 0X07
	#define LCD_SHIFT_RIGHT 0X05
	#define LCD_CURSOR_SHIFT_RIGHT 0X06
	#define LCD_CURSOR_SHIFT_LIFT 0X04
	#define RETURN_HOME 0X02
	/*********************************** LCD_End_Commands *****************************/

	/*******************************  START OF PROTOTYPES ***************************************/

LCD_ERROR LCD_CMD(LCD_CONFIG LCD,uint8 command); /*  SEND COMMANDS TO LCD */


LCD_ERROR LCD_INIT(LCD_CONFIG LCD);    /*  MAKE LCD READY TO START */


LCD_ERROR LCD_WRITE_STRING(LCD_CONFIG LCD, const uint8 *data);  /* PRINT ONLY STRINGS ON THE LCD YOU HAVE TO USE " " */


LCD_ERROR LCD_WRITE_CHAR(LCD_CONFIG LCD,const uint8 data);  /*  PRINT ONLY CHARACTERS ON LCD   YOU HAVE TO USE ' ' */


LCD_ERROR LCD_SET_CURSOR(LCD_CONFIG LCD,uint8 ROW , uint8 COLOM) ;  /* SET THE CURSOR IN A SPECIAL PLACE IN THE LCD */


LCD_ERROR LCD_WRITE_NUM(LCD_CONFIG LCD,sint32 num) ;  /* PRINT ONLY INTGER NUMBERS */


LCD_ERROR LCD_CLEAR(LCD_CONFIG LCD) ;          /* CLEAR LCD SCREEN */


	/******************************* END OF  PROTOTYPES ***************************************/





#endif /* LCD_INTERFACE_H_ */