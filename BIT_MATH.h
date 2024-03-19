/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    BIT_MATH.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Hagar Zaki Hashesh
 *  Layer  : LIB
 *
 */
 
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define REGISTER_SIZE 8

#define SET_BIT(REG,BIT_NUM) 	(REG) |= (1<<(BIT_NUM))
#define CLR_BIT(REG,BIT_NUM) 	(REG) &=~(1<<(BIT_NUM))
#define TOG_BIT(REG,BIT_NUM) 	(REG) ^= (1<<(BIT_NUM))
#define GET_BIT(REG,BIT_NUM) 	(((REG)>>(BIT_NUM)) &1)
#define IS_BIT_SET(REG,BIT_NUM) (REG&(1<<BIT_NUM))>>BIT_NUM
#define IS_BIT_CLR(REG,BIT_NUM) !((REG&(1<<BIT_NUM))>>BIT_NUM)

#endif