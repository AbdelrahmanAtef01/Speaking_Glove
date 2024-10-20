/*
 * TIMER_interface.h
 *
 *  Created on: Nov 9, 2023
 *      Author: andre
 */

#ifndef COTS_MCAL_TIMER_TIMER_INTERFACE_H_
#define COTS_MCAL_TIMER_TIMER_INTERFACE_H_


/*Prescaler options*/
#define NO_CLOCK_SOURCE				0
#define CLK							1
#define	CLK_8                       2
#define CLK_64            		 	3
#define CLK_256             		4
#define CLK_1024             		5
#define EXTC0_FALLING_EDGE          6
#define EXTC0_RISING_EDGE           7

void TIMER_voidInit(void);

void TIMER_voidDisable(void);

uint8_t TIMER_uint8SetPrescaler(uint8_t Copy_uint8Prescaler);

void TIMER_voidSetCounterRegister(uint8_t Copy_uint8CounterStart);

void TIMER_voidSetCTCTime(uint8_t Copy_uint8CompareTime);

void TIMER_voidSetTimerMode(uint8_t Copy_uint8Mode);

void TIMER_voidSetCallBackNormal(void (* Copy_uint8pSetCallBackNormal)(void));

void TIMER_voidSetCallBackCTC(void (* Copy_uint8pSetCallBackCTC)(void));

void TIMER_voidGetNumCountCTC(uint16_ Copy_uint16DesiredTime, uint16_ * Copy_uint16pNumOfCounts, uint8_t * Copy_uint8pCompareValue);

#endif /* COTS_MCAL_TIMER_TIMER_INTERFACE_H_ */
