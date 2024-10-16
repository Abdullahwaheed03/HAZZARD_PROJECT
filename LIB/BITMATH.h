
/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 26 - 9 - 2023   @ ***********************/
/**************** @ FILE   : BITMATH.h       @ ***********************/
/**************** @ BRIEF  : BITMATH MACROS  @ ***********************/
/*********************************************************************/

#ifndef BITMATH_H_
#define BITMATH_H_
#include "LIB/STD_TYPES.h"

#define REGISTER_SIZE 8


#define BIT_SET(reg,bit)    reg|=(1<<bit)
#define BIT_CLR(reg,bit)    reg&=(~(1<<bit))
#define BIT_TOG(reg,bit)    reg^=(1<<bit)
#define BIT_GET(reg,bit)    (reg&(1<<bit))>>bit

#define REGISTER(X)   *((volatile uint8*)X)


#endif /* BITMATH_H_ */