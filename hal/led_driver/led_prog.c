#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"
#include"util/delay.h"
#include"led_helper.h"

uint8_t LED_u8LedOn(uint8_t port_id,uint8_t led_pin)
{
	uint8_t IsOut;
	uint8_t error_status = DIO_u8IsPinOutPut(port_id,led_pin,&IsOut);
	if(error_status==E_OK)
	{
	if(IsOut==0)error_status=LED_u8InitializeLed(port_id,led_pin);
	error_status = DIO_u8SetPinValue(port_id,led_pin,HIGH);
	}
	return error_status;
}
uint8_t LED_u8LedOff(uint8_t port_id,uint8_t led_pin)
{
	uint8_t IsOut;
		uint8_t error_status = DIO_u8IsPinOutPut(port_id,led_pin,&IsOut);
		if(error_status==E_OK)
		{
		if(IsOut==0)error_status=LED_u8InitializeLed(port_id,led_pin);
	    error_status = DIO_u8SetPinValue(port_id,led_pin,LOW);
		}
	return error_status;
}
uint8_t LED_u8LedToggle(uint8_t port_id,uint8_t led_pin)
{
	uint8_t value;
	uint8_t IsOut;
		uint8_t error_status = DIO_u8IsPinOutPut(port_id,led_pin,&IsOut);
		if(error_status==E_OK)
		{
		if(IsOut==0)error_status=LED_u8InitializeLed(port_id,led_pin);
		error_status = DIO_u8GetPinValue(port_id,led_pin,&value);
		if(error_status==E_OK){
			if(value==HIGH)error_status=DIO_u8SetPinValue(port_id,led_pin,LOW);
			else error_status=DIO_u8SetPinValue(port_id,led_pin,HIGH);
		}
		}
	return error_status;
}
uint8_t LED_u8LedBlink(uint8_t port_id,uint8_t led_pin,uint16_ delay_time_ms)
{
	uint8_t IsOut;
	uint8_t error_status = DIO_u8IsPinOutPut(port_id,led_pin,&IsOut);
	if(error_status==E_OK)
	{
	if(IsOut==0)error_status=LED_u8InitializeLed(port_id,led_pin);
	error_status = LED_u8LedOn(port_id,led_pin);
 	 _delay_ms(delay_time_ms);
	if(error_status==E_OK){
	error_status = LED_u8LedOff(port_id,led_pin);
	_delay_ms(delay_time_ms);
	}
	}
	return error_status;
}


uint8_t LED_u8LedPortOn(uint8_t port_id)
{
	uint8_t IsOut;
	uint8_t error_status = DIO_u8IsPinOutPut(port_id,PIN_0,&IsOut);
	if(error_status==E_OK)
	{
	if(IsOut==0)error_status=LED_u8InitializeLedPort(port_id);
    error_status = DIO_u8SetPortValue(port_id,255);
	}
	return error_status;
}
uint8_t LED_u8LedPortOff(uint8_t port_id)
{
	uint8_t IsOut;
	uint8_t error_status = DIO_u8IsPinOutPut(port_id,PIN_0,&IsOut);
	if(error_status==E_OK)
	{
	if(IsOut==0)error_status=LED_u8InitializeLedPort(port_id);
	error_status = DIO_u8SetPortValue(port_id,LOW);
	}
	return error_status;
}
uint8_t LED_u8LedPortToggle(uint8_t port_id)
{
	uint8_t value;
	uint8_t IsOut;
	uint8_t error_status = DIO_u8IsPinOutPut(port_id,PIN_0,&IsOut);
	if(error_status==E_OK)
	{
	if(IsOut==0)error_status=LED_u8InitializeLedPort(port_id);
	error_status = DIO_u8GetPortValue(port_id,&value);
	if(error_status==E_OK){
		if(value==HIGH)error_status=DIO_u8SetPortValue(port_id,LOW);
		else error_status=DIO_u8SetPortValue(port_id,255);
	}
	}
	return error_status;
}
uint8_t LED_u8LedPortBlink(uint8_t port_id,uint16_ delay_time_ms)
{
	uint8_t IsOut;
		uint8_t error_status = DIO_u8IsPinOutPut(port_id,PIN_0,&IsOut);
		if(error_status==E_OK)
		{
		if(IsOut==0)error_status=LED_u8InitializeLedPort(port_id);
		error_status = LED_u8LedPortOn(port_id);
		_delay_ms(delay_time_ms);
		if(error_status==E_OK){
		error_status = LED_u8LedPortOff(port_id);
		_delay_ms(delay_time_ms);
		}
		}

	return error_status;
}
