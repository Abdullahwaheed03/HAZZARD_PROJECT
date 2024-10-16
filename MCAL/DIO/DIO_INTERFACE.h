
/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/                              
/**************** @ DATE   : 26 - 9 - 2023   @ ***********************/
/**************** @ FILE   : DIO_INTERFACE.h @ ***********************/     
/**************** @ BRIEF  : DIO FUNCTIONS   @ ***********************/
/*********************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"


#define PUD  2   /* PULLUP DISABLE BIT IN SPIFOR */ 

/********************** Enum for ports id ******************/

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
	}PORTS;
	
/************************************************************/



/********************** Enum for PINS id ******************/

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}PINS;

/************************************************************/	


/********************** Enum for DATA DIRECTIONS ******************/

typedef enum
{
	INPUT,
	OUTPUT,
	INPUT_PULLUP
}DIRECTIONS;

/************************************************************/



/********************** Enum for DATA STATS  ******************/

typedef enum
{
	LOW = 0,
	HIGH
}VALUES;


/************************************************************/



/********************** Enum for ERROR STATS ******************/

typedef enum
{
	DIO_OK,
	DIO_NOT_OK
}DIO_ERROR_STATE;

/************************************************************/



/******************************  DIO FUNCTIONS *****************************************/

DIO_ERROR_STATE DIO_ENUM_SET_PIN_DIR(PORTS PORT , PINS PIN , DIRECTIONS DIR ) ; /* SET PIN  DATA DIRECTION AS INPUT OR OUTOUT */

DIO_ERROR_STATE DIO_ENUM_SET_PIN_VAL(PORTS PORT , PINS PIN , VALUES VAL ) ;  /* SET PIN  DATA  AS HIGH OR LOW */

DIO_ERROR_STATE DIO_ENUM_TOGGLE_PIN_VAL(PORTS PORT , PINS PIN ) ; /* TOGGLE PIN STATE  */

DIO_ERROR_STATE DIO_ENUM_GET_PIN_VAL(PORTS PORT , PINS PIN , uint8 *DATA_CPY ) ; /* GET PIN  STATE  AS HIGH OR LOW */ 

DIO_ERROR_STATE DIO_ENUM_SET_PORT_DIR(PORTS PORT , DIRECTIONS DIR) ; /* SET PORT  DATA DIRECTION AS INPUT OR OUTOUT */

DIO_ERROR_STATE DIO_ENUM_SET_PORT_VAL(PORTS PORT , uint8 VAL) ;  /* SEND DATA THROUGH PORT */

DIO_ERROR_STATE DIO_ENUM_GET_PORT_VAL(PORTS PORT , uint8 *DATA_CPY ) ; /* GET DATA FROM PORT */

DIO_ERROR_STATE DIO_ENUM_PIN_DISABLE_PULLUP(PORTS PORT , PINS PIN);  /* DISABLE PULL UP FOR ONE PIN */

DIO_ERROR_STATE DIO_ENUM_ALL_DISABLE_PULLUP(void);  /* DISABLE PULL UP FOR THE WHOLE SYSTEM */ 


/****************************************************************************************/

#endif /* DIO_INTERFACE_H_ */