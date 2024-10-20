/*
 * TIMER_private.h
 *
 *  Created on: Nov 9, 2023
 *      Author: andre
 */

#ifndef COTS_MCAL_TIMER_TIMER_PRIVATE_H_
#define COTS_MCAL_TIMER_TIMER_PRIVATE_H_


/*Timer mode options*/
#define NORMAL_T_MODE		    	1
#define PWM_T_MODE			    	2
#define CTC_T_MODE			    	3
#define FAST_PWM_T_MODE		    	4

/*output compare mode options in non-PWM mode*/
#define DISCONNECTED				0b0
#define TOGGLE_OC0					0b1
#define CLEAR_OC0					0b10
#define SET_OC0						0b11

/*output compare mode options in fast PWM mode and phase correct*/
#define DISCONNECTED				0b0
#define CLEAR_OC0					0b10
#define SET_OC0						0b11


#endif /* COTS_MCAL_TIMER_TIMER_PRIVATE_H_ */
