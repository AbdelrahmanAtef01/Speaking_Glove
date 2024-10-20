/*
 * TIMER1_config.h
 *
 *  Created on: Sep 12, 2024
 *      Author: andre
 */

#ifndef COTS_MCAL_TIMER1_TIMER1_CONFIG_H_
#define COTS_MCAL_TIMER1_TIMER1_CONFIG_H_


/*Setting timer mode
 * 1-NORMAL_T_MODE
 * 2-PWM_T_MODE
 * 3-CTC_T_MODE
 * 4-FAST_PWM_T_MODE
 */
#define TIMER1_MODE				CTC_T_MODE


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
#define TIMER1_PRESCALER			CLK_1024


#endif /* COTS_MCAL_TIMER1_TIMER1_CONFIG_H_ */
