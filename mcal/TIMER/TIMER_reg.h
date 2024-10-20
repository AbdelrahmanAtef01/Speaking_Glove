/*
 * TIMER_reg.h
 *
 *  Created on: Nov 9, 2023
 *      Author: andre
 */

#ifndef COTS_MCAL_TIMER_TIMER_REG_H_
#define COTS_MCAL_TIMER_TIMER_REG_H_


#define TCCR0               (*(volatile uint8_t*)0x53)          //Timer/Counter control register
/*TCCR0 register bits*/
#define FOC0                  (uint8_t)7
#define WGM00                 (uint8_t)6
#define COM01                 (uint8_t)5
#define COM00                 (uint8_t)4
#define WGM01                 (uint8_t)3
#define CS02                  (uint8_t)2
#define CS01                  (uint8_t)1
#define CS00                  (uint8_t)0

#define TCNT0               (*(volatile uint8_t*)0x52)          //Timer/Counter register
/*TCNT0 register bits*/
#define TCNT0_0               (uint8_t)0
#define TCNT0_1               (uint8_t)1
#define TCNT0_2               (uint8_t)2
#define TCNT0_3               (uint8_t)3
#define TCNT0_4               (uint8_t)4
#define TCNT0_5               (uint8_t)5
#define TCNT0_6               (uint8_t)6
#define TCNT0_7               (uint8_t)7

#define OCR0                (*(volatile uint8_t*)0x5C)          //Output compare register
/*OCR0 register bits*/
#define OCR0_0                (uint8_t)0
#define OCR0_1                (uint8_t)1
#define OCR0_2                (uint8_t)2
#define OCR0_3                (uint8_t)3
#define OCR0_4                (uint8_t)4
#define OCR0_5                (uint8_t)5
#define OCR0_6                (uint8_t)6
#define OCR0_7                (uint8_t)7

#define TIMSK               (*(volatile uint8_t*)0x59)          //Timer/Counter interrupt mask register
/*TIMSK register bits*/
#define TOIE0                 (uint8_t)0
#define OCIE0                 (uint8_t)1

#define TIFR                (*(volatile uint8_t*)0x58)          //Timer/Counter interrupt flag register
/*TIFR register bits*/
#define TOV0                  (uint8_t)0
#define OCF0                  (uint8_t)1


#endif /* COTS_MCAL_TIMER_TIMER_REG_H_ */
