
/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 26 - 9 - 2023   @ ***********************/
/**************** @ FILE   : STD_TYPES.h     @ ***********************/
/**************** @ BRIEF  : STANDARD TYPES  @ ***********************/
/*********************************************************************/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_



typedef unsigned char       uint8   ;
typedef unsigned short      uint16  ;
typedef unsigned int        uint32  ;
typedef unsigned long long  uint64  ;


typedef signed char         sint8   ;
typedef signed short        sint16  ;
typedef signed int          sint32  ;
typedef signed long long    sint64  ;



typedef  float              float32 ;
typedef  double             float64 ;

typedef enum 
{
	FALSE,
	TRUE 
	}bool;
#define NULL_PTR   ((void*)0)


#endif /* STD_TYPES_H_ */