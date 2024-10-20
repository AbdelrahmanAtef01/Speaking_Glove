/*
 * TIMER1_private.h
 *
 *  Created on: Sep 12, 2024
 *      Author: andre
 */

#ifndef COTS_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define COTS_MCAL_TIMER1_TIMER1_PRIVATE_H_


/*Timer mode options*/
#define NORMAL_T_MODE		    	1
#define PWM_T_MODE			    	2
#define CTC_T_MODE			    	3
#define FAST_PWM_T_MODE		    	4

/*Prescaler options*/
#define NO_CLOCK_SOURCE				0
#define CLK							1
#define	CLK_8                       2
#define CLK_64            		 	3
#define CLK_256             		4
#define CLK_1024             		5
#define EXTC0_FALLING_EDGE          6
#define EXTC0_RISING_EDGE           7

#endif /* COTS_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
