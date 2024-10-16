/*
 * EXT_INT_PROVATE.h
 *
 * Created: 10/16/2024 7:08:42 PM
 *  Author: Eng_A
 */ 


#ifndef EXT_INT_PRIVATE_H_
#define EXT_INT_PRIVATE_H_


#include "LIB/BITMATH.h"


#define MCUCR    REGISTER(0X55)

#define MCUCSR	 REGISTER(0X54)

#define GICR 	 REGISTER(0X5B)

#define GIFR 	 REGISTER(0X5A)

#endif /* EXT_INT_PROVATE_H_ */