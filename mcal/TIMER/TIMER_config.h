/*
 * TIMER_config.h
 *
 *  Created on: Nov 9, 2023
 *      Author: andre
 */

#ifndef COTS_MCAL_TIMER_TIMER_CONFIG_H_
#define COTS_MCAL_TIMER_TIMER_CONFIG_H_

/*Setting timer mode
 * 1-NORMAL_T_MODE
 * 2-PWM_T_MODE
 * 3-CTC_T_MODE
 * 4-FAST_PWM_T_MODE
 */
#define TIMER_MODE				CTC_T_MODE

/*Setting prescaler mode
 *1-NO_CLOCK_SOURCE
 *2-CLK
 *3-CLK_8
 *4-CLK_64
 *5-CLK_256
 *6-CLK_1024
 *7-EXTC0_FALLING_EDGE
 *8-EXTC0_RISING_EDGE
 */
#define TIMER_PRESCALER			CLK_1024

/*output compare mode options in non-PWM mode:
*1-DISCONNECTED
*2-TOGGLE_OC0
*3-CLEAR_OC0
*4-SET_OC0
*/
/*output compare mode options in fast PWM mode:
*1-DISCONNECTED
*2-CLEAR_OC0
*3-SET_OC0
*/
/*output compare mode options in phase correct PWM mode:
*1-DISCONNECTED
*2-CLEAR_OC0
*3-SET_OC0
*/
#define OUTPUT_COMPARE_MODE		CLEAR_OC0


#endif /* COTS_MCAL_TIMER_TIMER_CONFIG_H_ */
