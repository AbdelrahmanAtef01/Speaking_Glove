/*
 * TIMER1_reg.h
 *
 *  Created on: Sep 12, 2024
 *      Author: andre
 */

#ifndef COTS_MCAL_TIMER1_TIMER1_REG_H_
#define COTS_MCAL_TIMER1_TIMER1_REG_H_


#define TCCR1A			(*(volatile uint8_t*)0x4F)			//Timer/Counter1 control register A
/*TCCR1A register bits*/
#define	WGM10						(uint8_t)0
#define	WGM11						(uint8_t)1
#define	FOC1B						(uint8_t)2
#define	FOC1A						(uint8_t)3
#define	COM1B0						(uint8_t)4
#define	COM1B1						(uint8_t)5
#define	COM1A0						(uint8_t)6
#define	COM1A1						(uint8_t)7


#define TCCR1B			(*(volatile uint8_t*)0x4E) 			//Timer/Counter1 control register B
/*TCCR1B register bits*/
#define	CS10						(uint8_t)0
#define	CS11						(uint8_t)1
#define	CS12						(uint8_t)2
#define	WGM12						(uint8_t)3
#define	WGM13						(uint8_t)4
/*------------------------------*/
#define	ICES1						(uint8_t)6
#define	ICNC1						(uint8_t)7


#define TCNT1H			(*(volatile uint8_t*)0x4D)			//Timer/Counter1 High Register

#define TCNT1L			(*(volatile uint8_t*)0x4C)			//Timer/Counter2 Low Register


#define OCR1AH			(*(volatile uint8_t*)0x4B)			//Output Compare High Register 1 A

#define OCR1AL			(*(volatile uint8_t*)0x4A)			//Output Compare Low Register 1 A


#define OCR1BH			(*(volatile uint8_t*)0x49)			//Output Compare High Register 1 B

#define OCR1BL			(*(volatile uint8_t*)0x48)			//Output Compare Low Register 1 B


#define ICR1H			(*(volatile uint8_t*)0x47)			//Input Capture High Register 1

#define ICR1L			(*(volatile uint8_t*)0x46)			//Input Capture Low Register 1


#define TIMSK			(*(volatile uint8_t*)0x59)			//Timer/Counter interrupt mask register
/*TIMSK register bits*/
#define	TOIE1						(uint8_t)2
#define	OCIE1B						(uint8_t)3
#define	OCIE1A						(uint8_t)4
#define	TICIE1						(uint8_t)5


#define TIFR			(*(volatile uint8_t*)0x58)			//Timer/Counter interrupt flag register
/*TIFR register bits*/
#define	TOV1						(uint8_t)2
#define	OCF1B						(uint8_t)3
#define	OCF1A						(uint8_t)4
#define	ICF1						(uint8_t)5


#endif /* COTS_MCAL_TIMER1_TIMER1_REG_H_ */
