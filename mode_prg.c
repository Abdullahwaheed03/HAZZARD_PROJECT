/******************************************************************************/
/*                                                                            */
/* !Layer           : Application Abstraction Layer                           */
/*                                                                            */
/* !Component       : MODE                                                    */
/* !Description     : Hazzard Indicator Function module                       */
/*                                                                            */
/* !Module          : MODE                                                    */
/* !Description     : MODE Module interface                                   */
/*                                                                            */
/* !File            : mode_prg.c                                              */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Induction training exercise project                     */
/*                                                                            */
/* !Target          : ATMega32                                                */
/*                                                                            */
/* !Compiler        : AVR GCC Cross Compiler                                  */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Coded by        : Mahmoud Karem Zamel             !Date : NOV 21, 2023    */
/*                                                                            */
/******************************************************************************/
#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_INTERFACE.h"

#include "HAL/LCD/LCD_INTERFACE.h"
#include "HAL/SWITCH/SWITCH_INTERFACE.h"
#include "HAL/SSD/SSD_INTERFACE.h"



#include "mode_int.h"

/******************************************************************************/

MODE_enutModeState Mode_MyState;

uint8 u8PreviousState = IDLE;

/*****************************************************************************************/

extern SSD_CONFIG SSD1 ;
extern SSD_CONFIG SSD2 ;

extern LCD_CONFIG LCD  ;

extern SWITCH_CONFIG LEFT ;
extern SWITCH_CONFIG HAZZARD ;
extern SWITCH_CONFIG RIGHT ;

/*****************************************************************************************/

/******************************************************************************/
/*! \Description Helper Functions                                             */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void APP_vidSetMode(MODE_enutModeState enutSetMode)
{
	switch(enutSetMode)
	{
	case IDLE:
		SSD_ENUM_DISABLE(SSD1);
		SSD_ENUM_DISABLE(SSD2);
	    LCD_CLEAR(LCD);
		LCD_WRITE_STRING(LCD,"IDLE");
		
		break;

	case RIGHT_BLINK:
				SSD_ENUM_ENABLE(SSD1);
				SSD_ENUM_DISABLE(SSD2);
				SSD_ENUM_SEND_DATA(SSD1,0);
				LCD_CLEAR(LCD);
				LCD_WRITE_STRING(LCD,"RIGHT");
	
		break;

	case LEFT_BLINK:
		SSD_ENUM_DISABLE(SSD1);
		SSD_ENUM_ENABLE(SSD2);
		SSD_ENUM_SEND_DATA(SSD2,0);
		LCD_CLEAR(LCD);
		LCD_WRITE_STRING(LCD,"LEFT");
	
		break;

	case HAZZARD_BLINK:
		SSD_ENUM_ENABLE(SSD1);
		SSD_ENUM_ENABLE(SSD2);
		SSD_ENUM_SEND_DATA(SSD1,0);
		SSD_ENUM_SEND_DATA(SSD2,0);
	    LCD_CLEAR(LCD);
		LCD_WRITE_STRING(LCD,"HAZARD");
		
		break;
	}

}

/***************************************/
void MODE_vidIdle (void)
{
   APP_vidSetMode(IDLE);
   uint8 RIGHT_SW , LEFT_SW , HAZZARD_SW ;
   
   SWITCH_ENUM_GET_STATE(RIGHT,&RIGHT_SW);
   SWITCH_ENUM_GET_STATE(LEFT,&LEFT_SW);
   SWITCH_ENUM_GET_STATE(HAZZARD,&HAZZARD_SW);
   
   if (RIGHT_SW == PRESSED)
   {
	   Mode_MyState = RIGHT_BLINK ;
   }
   if (LEFT_SW == PRESSED)
   {
	   Mode_MyState = LEFT_BLINK ;
   }
   if (HAZZARD_SW == PRESSED)
   {
	   Mode_MyState = HAZZARD_BLINK ;
	   u8PreviousState = IDLE ;
   }
   

}
void MODE_vidRightBlink (void)
{
	 APP_vidSetMode(RIGHT_BLINK);
	 uint8   LEFT_SW , HAZZARD_SW ;
	 
	 SWITCH_ENUM_GET_STATE(LEFT,&LEFT_SW);
	 SWITCH_ENUM_GET_STATE(HAZZARD,&HAZZARD_SW);
	 
	 if (LEFT_SW == PRESSED)
	 {
		 Mode_MyState = IDLE ;
	 }
	 if (HAZZARD_SW == PRESSED)
	 {
		 Mode_MyState = HAZZARD_BLINK ;
		 u8PreviousState = RIGHT_BLINK ;
	 }

}
void MODE_vidLeftBlink (void)
{
		 APP_vidSetMode(LEFT_BLINK);
		 uint8 RIGHT_SW  , HAZZARD_SW ;
		 
		 SWITCH_ENUM_GET_STATE(RIGHT,&RIGHT_SW);
		 SWITCH_ENUM_GET_STATE(HAZZARD,&HAZZARD_SW);
		 
		 if (RIGHT_SW == PRESSED)
		 {
			 Mode_MyState = IDLE ;
		 }
		 if (HAZZARD_SW == PRESSED)
		 {
			 Mode_MyState = HAZZARD_BLINK ;
			 u8PreviousState = LEFT_BLINK ;
		 }


}
void MODE_vidHazardBlink (void)
{
    APP_vidSetMode(HAZZARD_BLINK);
    uint8  HAZZARD_SW ;
    
    SWITCH_ENUM_GET_STATE(HAZZARD,&HAZZARD_SW);
    

    if (HAZZARD_SW == PRESSED)
    {
	    Mode_MyState = u8PreviousState ;
    }
}


/*****************************************************************************************/

/******************************************************************************/
/*! \Description Initialize the MODE driver variables                         */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_vidInit(void)
{
	Mode_MyState  = IDLE;
	APP_vidSetMode(IDLE);
}

/******************************************************************************/
/*! \Description The MODE driver task, should be called periodically.
				 This service update the state of all configured push
                 buttons.                                                     */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_vidTask(void)
{
	switch (Mode_MyState)
	{
		case IDLE : MODE_vidIdle() ; break ;
		case RIGHT_BLINK : MODE_vidRightBlink() ; break ;
		case LEFT_BLINK : MODE_vidLeftBlink() ; break ;
		case HAZZARD_BLINK : MODE_vidHazardBlink() ; break ;

	}
	
}

/**********************************************************************************************/
