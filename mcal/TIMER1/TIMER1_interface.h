/*
 * TIMER1_init.h
 *
 *  Created on: Sep 12, 2024
 *      Author: andre
 */

#ifndef COTS_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define COTS_MCAL_TIMER1_TIMER1_INTERFACE_H_

/*Prescaler options*/
#define NO_CLOCK_SOURCE				0
#define CLK							1
#define	CLK_8                       2
#define CLK_64            		 	3
#define CLK_256             		4
#define CLK_1024             		5
#define EXTC0_FALLING_EDGE          6
#define EXTC0_RISING_EDGE           7

void TIMER1_voidInit(void);

void TIMER1_voidDisable(void);

void TIMER1_voidSetCounterRegister(uint8_t Copy_uint8Counter1Start);

uint8_t TIMER1_uint8SetPrescaler(uint8_t Copy_uint8Prescaler);

void TIMER1_voidSetCTCTime(uint8_t Copy_uint8CompareTime);

void TIMER1_voidSetCallBackNormal(void (* Copy_uint8pSetCallBackNormal1)(void));

void TIMER1_voidSetCallBackCTC(void (* Copy_uint8pSetCallBackCTC1)(void));

void TIMER1_voidGetNumCountCTC(uint16_ Copy_uint8DesiredTime, uint16_ * Copy_uint16pNumOfCounts, uint8_t * Copy_uint8pCompareValue);

#endif /* COTS_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
