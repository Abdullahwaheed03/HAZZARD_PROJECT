 
/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 26 - 9 - 2023   @ ***********************/
/**************** @ FILE   : DIO_PRIVATE.h   @ ***********************/
/**************** @ BRIEF  : DIO REGISTERS   @ ***********************/
/*********************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"



/***************** PORTA REGS *********************/

#define PORTA_  REGISTER(0X3B)
#define  DDRA_  REGISTER(0X3A)
#define  PINA_  REGISTER(0X39) 

/**************************************************/


/***************** PORTB REGS *********************/

#define PORTB_  REGISTER(0X38)
#define  DDRB_  REGISTER(0X37)
#define  PINB_  REGISTER(0X36)

/**************************************************/


/***************** PORTC REGS *********************/

#define PORTC_  REGISTER(0X35)
#define  DDRC_  REGISTER(0X34)
#define  PINC_  REGISTER(0X33)

/**************************************************/


/***************** PORTD REGS *********************/

#define PORTD_  REGISTER(0X32)
#define  DDRD_  REGISTER(0X31)
#define  PIND_  REGISTER(0X30)

/**************************************************/



#define SPIFOR  REGISTER(0X50)  // for pull up 

#endif /* DIO_PRIVATE_H_ */