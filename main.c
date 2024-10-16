/******************************************************************************/
/*                                                                            */
/* !Layer           : Application Layer                                       */
/*                                                                            */
/* !Component       : main                                                    */
/* !Description     : Application Entry Point                                 */
/*                                                                            */
/* !Module          : main                                                    */
/* !Description     : Main Module implementation                              */
/*                                                                            */
/* !File            : mian.c                                                  */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Embedded Diploma Project-1                              */
/*                                                                            */
/* !Target          : ATMega32                                                */
/*                                                                            */
/* !Compiler        : AVR GCC Cross Compiler                                  */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Designed by     : Mahmoud Karem                      !Date : NOV 21, 2023 */
/* !Coded by        : Mahmoud Karem                      !Date : NOV 21, 2023 */
/*                                                                            */
/******************************************************************************/

/*! Include compiler types header                                             */


#define F_CPU 8000000UL
#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_INTERFACE.h"

#include "HAL/LCD/LCD_INTERFACE.h"
#include "HAL/SWITCH/SWITCH_INTERFACE.h"
#include "HAL/SSD/SSD_INTERFACE.h"
#include "MODE_int.h"


static void vidInit(void);
/***********************************************/

SSD_CONFIG SSD1 =
{
	COMMON_CATHODE,
	PORTC,
	PORTC,
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
};


SSD_CONFIG SSD2 =
{
	COMMON_CATHODE,
	PORTD,
	PORTD,
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
};


LCD_CONFIG LCD =
{
	PORTB,
	PORTB,
	PIN7,
	PIN6,
	PIN5,
	PIN4,
	PIN1,
	PIN2,
	PIN3
};


SWITCH_CONFIG LEFT =
{
	PORTA,
	PIN0,
	INT_PULLUP
	};
	
SWITCH_CONFIG HAZZARD =
{
	PORTA,
	PIN1,
	INT_PULLUP
};
SWITCH_CONFIG RIGHT =
{
	PORTA,
	PIN2,
	INT_PULLUP
};


/***********************************************/
int main(void)
{
	/*! Initialize the software                                               */
    vidInit();


	/*! Start the Application                                                 */


	
	while(1)
	{
		MODE_vidTask();
		_delay_ms(12);
	}
  return 0 ;
}



static void vidInit(void)
{
	LCD_INIT(LCD);
	
	SSD_ENUM_INIT(SSD1);
	SSD_ENUM_INIT(SSD2);
	
	SWITCH_ENUM_INIT(LEFT);
	SWITCH_ENUM_INIT(HAZZARD);
	SWITCH_ENUM_INIT(RIGHT);
	
	MODE_vidInit();

}
