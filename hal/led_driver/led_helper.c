#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"

uint8_t LED_u8InitializeLed(uint8_t port_id,uint8_t led_pin)
{
	uint8_t error_status = DIO_u8SetPinMode(port_id,led_pin,OUTPUT);
	return error_status;
}

uint8_t LED_u8InitializeLedPort(uint8_t port_id)
{
	uint8_t error_status = DIO_u8SetPortMode(port_id,255);
	return error_status;
}
