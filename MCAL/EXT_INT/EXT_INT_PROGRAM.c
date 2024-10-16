/*
 * EXT_INT_PROGRAM.c
 *
 * Created: 10/16/2024 7:08:03 PM
 *  Author: Eng_A
 */ 


#include "LIB/STD_TYPES.h"
#include "MCAL/EXT_INT/EXT_INT_PRIVATE.h"
#include "MCAL/EXT_INT/EXT_INT_INTERFACE.h"
#include "MCAL/EXT_INT/EXT_INT_CONFIG.h"




void (*EXTI_CallBack[3]) (void) = { NULL_PTR } ;


		
	
	

void  EXTI_INIT(EXT_INT_LINES LINE , SENSE_MODE MODE)
{
	switch(LINE)
	{
		case EXT_INT0 :
		{
          BIT_SET(GICR,6);   
		  switch(MODE)
		  {
			 case LOW_LVL : 
			 {
				BIT_CLR(MCUCR,0);
				BIT_CLR(MCUCR,1);

			 }break;
			 
			 case CHANGE :
			 {
			    BIT_SET(MCUCR,0);
			    BIT_CLR(MCUCR,1);
			 }break;
			 
			 case FALLING_EDGE :
			 {
			   	BIT_CLR(MCUCR,0);
			   	BIT_SET(MCUCR,1);
			 }break;
			 
			 case RISING_EDGE :
			 {
			    BIT_SET(MCUCR,0);
			   	BIT_SET(MCUCR,1);
			 }break;
		  }
		} break;
		case EXT_INT1 :
		{
			BIT_SET(GICR,7);
			 switch(MODE)
			 {
				 case LOW_LVL :
				 {
					 BIT_CLR(MCUCR,2);
					 BIT_CLR(MCUCR,3);

				 }break;
				 
				 case CHANGE :
				 {
					 BIT_SET(MCUCR,2);
					 BIT_CLR(MCUCR,3);
				 }break;
				 
				 case FALLING_EDGE :
				 {
					 BIT_CLR(MCUCR,2);
					 BIT_SET(MCUCR,3);
				 }break;
				 
				 case RISING_EDGE :
				 {
					 BIT_SET(MCUCR,2);
					 BIT_SET(MCUCR,3);
				 }break;
			 }
		} break;
		case EXT_INT2 :
		{
			BIT_SET(GICR,5);
		     switch(MODE)
		     {
			     
			     
			     case FALLING_EDGE :
			     {
				     BIT_CLR(MCUCSR,6);
			     }break;
			     
			     case RISING_EDGE :
			     {
				     BIT_SET(MCUCSR,6);

			     }break;
		     }
		} break;
	}
	
}

	void  EXTI_DEINIT(EXT_INT_LINES LINE) 
	{
	    switch(LINE)
		{
			case EXT_INT0 : BIT_CLR(GICR,6) ; break ;
			case EXT_INT1 : BIT_CLR(GICR,7) ; break ;
			case EXT_INT2 : BIT_CLR(GICR,5) ; break ;
		}
		
	    }
		



void EXTI_SET_CALLBACK(void (*ptr)(void) , EXT_INT_LINES LINE) 
{
	if (ptr != NULL_PTR)
	{
		     EXTI_CallBack[LINE] = ptr ;
	}

}
	
	
	
	

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	if( EXTI_CallBack[0] != NULL_PTR  ){

		EXTI_CallBack[0](); /*  Call The Global Pointer to Func   */

	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{

	if( EXTI_CallBack[1] != NULL_PTR ){

		EXTI_CallBack[1]();

	}

}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{

	if( EXTI_CallBack[2] != NULL_PTR ){

		EXTI_CallBack[2]();

	}

}