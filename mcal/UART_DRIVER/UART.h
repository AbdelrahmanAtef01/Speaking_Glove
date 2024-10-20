#ifndef MCAL_UART_DRIVER_UART_H_
#define MCAL_UART_DRIVER_UART_H_

void UART_Init(uint16_ baud);
void UART_Transmit(uint8_t data);
uint8_t UART_Receive(void);

#endif
