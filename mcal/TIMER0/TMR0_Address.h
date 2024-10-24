#ifndef _TMR0_ADDRESS_H
#define _TMR0_ADDRESS_H


// Memory addresses for Timer0 registers
#define TCCR0_REG     (*((volatile uint8_t *)0x53))  // Timer/Counter Control Register
#define TCNT0_REG     (*((volatile uint8_t *)0x52))  // Timer/Counter Register
#define OCR0_REG      (*((volatile uint8_t *)0x5C))  // Output Compare Register
#define TIMSK_REG     (*((volatile uint8_t *)0x59))  // Timer Interrupt Mask Register
#define TIFR_REG      (*((volatile uint8_t *)0x58))  // Timer Interrupt Flag Register
#define SREG	      (*((volatile uint8_t *)0x5F))

// Bit positions
#define TCCR0_CS00    0
#define TCCR0_CS01    1
#define TCCR0_CS02    2
#define TCCR0_WGM01   3
#define TCCR0_COM00   4
#define TCCR0_COM01   5
#define TCCR0_WGM00   6
#define TCCR0_FOC0    7

#define TIMSK_TOIE0   0
#define TIMSK_OCIE0   1

#endif /* _TMR0_ADDRESS_H */

