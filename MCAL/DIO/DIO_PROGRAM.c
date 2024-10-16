
/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 26 - 9 - 2023   @ ***********************/
/**************** @ FILE   : DIO_PROGRAM.c   @ ***********************/
/**************** @ BRIEF  : DIO SRC CODE    @ ***********************/
/*********************************************************************/




#include "MCAL/DIO/DIO_PRIVATE.h"
#include "MCAL/DIO/DIO_INTERFACE.h"
#include "DIO_CONFIG.h"


DIO_ERROR_STATE DIO_ENUM_SET_PIN_DIR(PORTS PORT , PINS PIN , DIRECTIONS DIR )
{
	DIO_ERROR_STATE STATE = DIO_OK ;
	
	if (PORT <= PORTD && PIN <= PIN7)
	{
	   
	  switch(DIR)
	  {
		  case OUTPUT :
		  {
			  switch(PORT)
			  {
				  case PORTA : BIT_SET(DDRA_,PIN); break ;
				  case PORTB : BIT_SET(DDRB_,PIN); break ;
				  case PORTC : BIT_SET(DDRC_,PIN); break ;
				  case PORTD : BIT_SET(DDRD_,PIN); break ;
				  
			  }
		  } break ;
		  case INPUT :
		  {
			   switch(PORT)
			   {
				   case PORTA : BIT_CLR(DDRA_,PIN); break ;
				   case PORTB : BIT_CLR(DDRB_,PIN); break ;
				   case PORTC : BIT_CLR(DDRC_,PIN); break ;
				   case PORTD : BIT_CLR(DDRD_,PIN); break ;
				   
			   }
		  } break ;
		  case INPUT_PULLUP :
		  {
			   BIT_CLR(SPIFOR,PUD) ; /* MAKING PUD BIT CLEARED TO ENABLE PULL UP */
			   switch(PORT)
			   {
				   case PORTA : BIT_CLR(DDRA_,PIN);  BIT_SET(PORTA_,PIN);break ;
				   case PORTB : BIT_CLR(DDRB_,PIN);  BIT_SET(PORTB_,PIN);break ;
				   case PORTC : BIT_CLR(DDRC_,PIN);  BIT_SET(PORTC_,PIN);break ;
				   case PORTD : BIT_CLR(DDRD_,PIN);  BIT_SET(PORTD_,PIN);break ;
				   
			   }
		  } break ;
	  }
	 
	}
	else
	{
 		STATE = DIO_NOT_OK ;
	}
	return STATE ;
}

DIO_ERROR_STATE DIO_ENUM_SET_PIN_VAL(PORTS PORT , PINS PIN , VALUES VAL ) 
{
	
	DIO_ERROR_STATE STATE = DIO_OK ;

	if (PORT <= PORTD && PIN <= PIN7)
	{
		  switch(VAL)
		  {
			  case HIGH :
			  {
				  switch(PORT)
				  {
					  case PORTA : BIT_SET(PORTA_,PIN); break ;
					  case PORTB : BIT_SET(PORTB_,PIN); break ;
					  case PORTC : BIT_SET(PORTC_,PIN); break ;
					  case PORTD : BIT_SET(PORTD_,PIN); break ;
					  
				  }
			  } break ;
			  case LOW :
			  {
				  switch(PORT)
				  {
					  case PORTA : BIT_CLR(PORTA_,PIN); break ;
					  case PORTB : BIT_CLR(PORTB_,PIN); break ;
					  case PORTC : BIT_CLR(PORTC_,PIN); break ;
					  case PORTD : BIT_CLR(PORTD_,PIN); break ;
					  
				  }
			  } break ;
	}
			  }
	else
	{
		STATE = DIO_NOT_OK ;
	}
	return STATE ;

	
}






DIO_ERROR_STATE DIO_ENUM_TOGGLE_PIN_VAL(PORTS PORT , PINS PIN )
{
	DIO_ERROR_STATE STATE = DIO_OK ;

	if (PORT <= PORTD && PIN <= PIN7)
	{
				switch(PORT)
				{
					case PORTA : BIT_TOG(PORTA_,PIN); break ;
					case PORTB : BIT_TOG(PORTB_,PIN); break ;
					case PORTC : BIT_TOG(PORTC_,PIN); break ;
					case PORTD : BIT_TOG(PORTD_,PIN); break ;
					
				}

	}
	else
	{
		STATE = DIO_NOT_OK ;
	}
	return STATE ;

	
}





DIO_ERROR_STATE DIO_ENUM_GET_PIN_VAL(PORTS PORT , PINS PIN , uint8 *DATA_CPY ) 
{
	
	DIO_ERROR_STATE STATE = DIO_OK ;

	if (PORT <= PORTD && PIN <= PIN7)
	{
      switch(PORT)
      {
	      case PORTA : *DATA_CPY = BIT_GET(PINA_,PIN); break ;
	      case PORTB : *DATA_CPY = BIT_GET(PINB_,PIN); break ;
	      case PORTC : *DATA_CPY = BIT_GET(PINC_,PIN); break ;
	      case PORTD : *DATA_CPY = BIT_GET(PIND_,PIN); break ;
	 }
	}
	else
	{
		STATE = DIO_NOT_OK ;
	}
	return STATE ;

}



DIO_ERROR_STATE DIO_ENUM_SET_PORT_DIR(PORTS PORT , DIRECTIONS DIR) 
{
	
	DIO_ERROR_STATE STATE = DIO_OK ;

	if (PORT <= PORTD && DIR <= INPUT_PULLUP )
	{
      switch (PORT)
           {
	      case PORTA : DDRA_  = 0XFF ; break ;
	      case PORTB : DDRB_  = 0XFF ; break ;
	      case PORTC : DDRC_  = 0XFF ; break ;
	      case PORTD : DDRD_  = 0XFF ; break ;
	       }
	}
	else
	{
		STATE = DIO_NOT_OK ;
	}
	return STATE ;

}

DIO_ERROR_STATE DIO_ENUM_SET_PORT_VAL(PORTS PORT , uint8 VAL)
{
	
	DIO_ERROR_STATE STATE = DIO_OK ;

	if (PORT <= PORTD && VAL <= LOW )
	{
        switch (PORT)
        {
	        case PORTA : PORTA_  = VAL ; break ;
	        case PORTB : PORTB_  = VAL ; break ;
	        case PORTC : PORTC_  = VAL ; break ;
	        case PORTD : PORTD_  = VAL ; break ;
        }
	}
	else
	{
		STATE = DIO_NOT_OK ;
	}
	return STATE ;

}

DIO_ERROR_STATE DIO_ENUM_GET_PORT_VAL(PORTS PORT , uint8 *DATA_CPY ) 
{
	
	DIO_ERROR_STATE STATE = DIO_OK ;

	if (PORT <= PORTD )
	{
         switch(PORT)
         {
	         case PORTA : *DATA_CPY = PINA_; break ;
	         case PORTB : *DATA_CPY = PINB_; break ;
	         case PORTC : *DATA_CPY = PINC_; break ;
	         case PORTD : *DATA_CPY = PIND_; break ;
         }
	}
	else
	{
		STATE = DIO_NOT_OK ;
	}
	return STATE ;

}



DIO_ERROR_STATE DIO_ENUM_PIN_DISABLE_PULLUP(PORTS PORT , PINS PIN)
{
	
	DIO_ERROR_STATE STATE = DIO_OK ;

	if (PORT <= PORTD  &&  PIN <= PIN7)
	{
		switch(PORT)
		{
			case PORTA : BIT_CLR(PORTA_,PIN); break ;
			case PORTB : BIT_CLR(PORTB_,PIN); break ;
			case PORTC : BIT_CLR(PORTC_,PIN); break ;
			case PORTD : BIT_CLR(PORTD_,PIN); break ;
			
		}
	}
	else
	{
		STATE = DIO_NOT_OK ;
	}
	return STATE ;
	   
}

DIO_ERROR_STATE DIO_ENUM_ALL_DISABLE_PULLUP(void)
{
	BIT_SET(SPIFOR,PUD) ;
	return DIO_OK ;	
}








