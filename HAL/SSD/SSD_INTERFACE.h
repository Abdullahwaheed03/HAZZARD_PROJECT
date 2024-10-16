
/**********************************************************************/
/**************** @ AUTHOR : Abdullah waheed  @ ***********************/
/**************** @ DATE   : 26 - 9 - 2023    @ ***********************/
/**************** @ FILE   : SSD_INTERFACE    @ ***********************/
/**************** @ BRIEF  : SSD FUNCS        @ ***********************/
/**********************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


#include "MCAL/DIO/DIO_INTERFACE.h"
#include "HAL/SSD/SSD_PRTIVATE.h"
typedef enum 
{
	COMMON_ANODE,
	COMMON_CATHODE
	}SSD_TYPE;

typedef enum
{
	SSD_OK,
	SSD_NOK
}SSD_ERROR_TYPE;

typedef struct
{
	SSD_TYPE TYPE ;
	PORTS DATA_PORT ;
	PORTS ENABLE_PORT ;
	PINS PIN_A ;
	PINS PIN_B ;
	PINS PIN_C ;
	PINS PIN_D ;
	PINS PIN_E ;
	PINS PIN_F ;
	PINS PIN_G ;
	PINS PIN_EN ;
	}SSD_CONFIG;

SSD_ERROR_TYPE SSD_ENUM_INIT(SSD_CONFIG CONFIG) ; /* INITALIZE SSD  */ 

SSD_ERROR_TYPE SSD_ENUM_SEND_DATA(SSD_CONFIG CONFIG , uint8 DATA) ; /* SEND DATA TO SSD  */

SSD_ERROR_TYPE SSD_ENUM_ENABLE(SSD_CONFIG CONFIG) ; /* ENABLE SSD  */ 

SSD_ERROR_TYPE SSD_ENUM_DISABLE(SSD_CONFIG CONFIG) ; /* DISABLE SSD  */ 

#endif /* SSD_INTERFACE_H_ */