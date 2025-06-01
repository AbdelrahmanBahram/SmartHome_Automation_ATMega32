/*
 * common_macros.h
 *
 *  Created on: Oct 3, 2024
 *      Author: Administrator
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_
#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLEAR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)
#define BIT_IS_SET(REG,BIT) (REG & (1<<BIT))
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))
#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )
#endif /* COMMON_MACROS_H_ */
