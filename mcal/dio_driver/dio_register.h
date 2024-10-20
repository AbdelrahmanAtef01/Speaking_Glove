#ifndef MCAL_DIO_DRIVER_DIO_REGISTER_H_
#define MCAL_DIO_DRIVER_DIO_REGISTER_H_

#define PORTA_REG (*((volatile uint8_t*)0x3B))
#define PINA_REG (*((volatile uint8_t*)0x39))
#define DDRA_REG (*((volatile uint8_t*)0x3A))

#define PORTB_REG (*((volatile uint8_t*)0x38))
#define PINB_REG (*((volatile uint8_t*)0x36))
#define DDRB_REG (*((volatile uint8_t*)0x37))

#define PORTC_REG (*((volatile uint8_t*)0x35))
#define PINC_REG (*((volatile uint8_t*)0x33))
#define DDRC_REG (*((volatile uint8_t*)0x34))

#define PORTD_REG (*((volatile uint8_t*)0x32))
#define PIND_REG (*((volatile uint8_t*)0x30))
#define DDRD_REG (*((volatile uint8_t*)0x31))

#endif
