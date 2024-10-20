#ifndef MCAL_UART_DRIVER_UART_REGISTERS_H_
#define MCAL_UART_DRIVER_UART_REGISTERS_H_

#define UBRRH (*((volatile uint8_t*)0x40))
#define UBRRL (*((volatile uint8_t*)0x29))
#define UCSRA (*((volatile uint8_t*)0x2B))
#define UCSRB (*((volatile uint8_t*)0x2A))
#define UCSRC (*((volatile uint8_t*)0x40))
#define UDR   (*((volatile uint8_t*)0x2C))

#endif
