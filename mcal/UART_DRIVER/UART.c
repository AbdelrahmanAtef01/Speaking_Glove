#include "../../libraries/std_types.h"
#include "../../libraries/bit_math.h"
#include "UART.h"
#include "UART_REGISTERS.h"

void UART_Init(uint16_ baud) {
    uint16_ ubrr = F_CPU/16/baud-1;
    UBRRH = (uint8_t)(ubrr>>8);
    UBRRL = (uint8_t)ubrr;
    SET_BIT(UCSRB,4);
    SET_BIT(UCSRB,3);
    UCSRC = (1<<7) | (3<<1);
}

void UART_Transmit(uint8_t data) {
    while (!GET_BIT(UCSRA,5));
    UDR = data;
}

uint8_t UART_Receive(void) {
    while (!GET_BIT(UCSRA,7));
    return UDR;
}
