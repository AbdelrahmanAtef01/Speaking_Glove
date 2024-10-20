#include"../../libraries/std_types.h"
#include"../../libraries/bit_math.h"
#include"dio_register.h"
#include"dio_int.h"

uint8_t DIO_u8SetPinMode(uint8_t port_id,uint8_t pin_no,uint8_t mode)
{
	uint8_t error_status = E_OK;
		switch(port_id)
		{
		case PORT_A:
			if(mode==INPUT)CLR_BIT(DDRA_REG,pin_no);
			else if(mode==OUTPUT)SET_BIT(DDRA_REG,pin_no);
			else error_status = E_NOK;
		break;
		case PORT_B:
			if(mode==INPUT)CLR_BIT(DDRB_REG,pin_no);
			else if(mode==OUTPUT)SET_BIT(DDRB_REG,pin_no);
			else error_status = E_NOK;
		break;
		case PORT_C:
			if(mode==INPUT)CLR_BIT(DDRC_REG,pin_no);
			else if(mode==OUTPUT)SET_BIT(DDRC_REG,pin_no);
			else error_status = E_NOK;
		break;
		case PORT_D:
			if(mode==INPUT)CLR_BIT(DDRD_REG,pin_no);
			else if(mode==OUTPUT)SET_BIT(DDRD_REG,pin_no);
			else error_status = E_NOK;
		break;
		default : error_status = E_NOK; break;
		}
		return error_status;
}
uint8_t DIO_u8SetPinValue(uint8_t port_id,uint8_t pin_no,uint8_t value)
{
	uint8_t error_status = E_OK;
		switch(port_id)
		{
		case PORT_A:
			if(value==LOW)CLR_BIT(PORTA_REG,pin_no);
			else if(value==HIGH)SET_BIT(PORTA_REG,pin_no);
			else error_status = E_NOK;
		break;
		case PORT_B:
			if(value==LOW)CLR_BIT(PORTB_REG,pin_no);
			else if(value==HIGH)SET_BIT(PORTB_REG,pin_no);
			else error_status = E_NOK;
		break;
		case PORT_C:
			if(value==LOW)CLR_BIT(PORTC_REG,pin_no);
			else if(value==HIGH)SET_BIT(PORTC_REG,pin_no);
			else error_status = E_NOK;
		break;
		case PORT_D:
			if(value==LOW)CLR_BIT(PORTD_REG,pin_no);
			else if(value==HIGH)SET_BIT(PORTD_REG,pin_no);
			else error_status = E_NOK;
		break;
		default : error_status = E_NOK; break;
		}
		return error_status;
}
uint8_t DIO_u8GetPinValue(uint8_t port_id,uint8_t pin_no,uint8_t * value)
{
	uint8_t error_status = E_OK;
	if(pin_no>=0&&pin_no<8)
	{
		switch(port_id)
		{
		case PORT_A: *value = GET_BIT(PINA_REG,pin_no); break;
		case PORT_B: *value = GET_BIT(PINB_REG,pin_no); break;
		case PORT_C: *value = GET_BIT(PINC_REG,pin_no); break;
		case PORT_D: *value = GET_BIT(PIND_REG,pin_no); break;
		default : error_status = E_NOK; break;
		}
	}else error_status = E_NOK;
	return error_status;
}
uint8_t DIO_u8IsPinOutPut(uint8_t port_id,uint8_t pin_no,uint8_t * value)
{
	uint8_t error_status = E_OK;
	if(pin_no>=0&&pin_no<8)
		{
			switch(port_id)
			{
			case PORT_A: *value = GET_BIT(DDRA_REG,pin_no); break;
			case PORT_B: *value = GET_BIT(DDRB_REG,pin_no); break;
			case PORT_C: *value = GET_BIT(DDRC_REG,pin_no); break;
			case PORT_D: *value = GET_BIT(DDRD_REG,pin_no); break;
			default : error_status = E_NOK; break;
			}
		}else error_status = E_NOK;
	return error_status;
}
uint8_t DIO_u8SetPullUpMode(uint8_t port_id,uint8_t pin_no,uint8_t mode)
{
	uint8_t error_status = E_OK;
	if(pin_no>=0&&pin_no<8)
	{
	switch(port_id)
	{
	case PORT_A: mode==Enabled?SET_BIT(PORTA_REG,pin_no):CLR_BIT(PORTA_REG,pin_no); break;
	case PORT_B: mode==Enabled?SET_BIT(PORTB_REG,pin_no):CLR_BIT(PORTB_REG,pin_no); break;
	case PORT_C: mode==Enabled?SET_BIT(PORTC_REG,pin_no):CLR_BIT(PORTC_REG,pin_no); break;
	case PORT_D: mode==Enabled?SET_BIT(PORTD_REG,pin_no):CLR_BIT(PORTD_REG,pin_no); break;
	default : error_status = E_NOK; break;
	}
	}else error_status=E_NOK;
	return error_status;
}

uint8_t DIO_u8SetPortMode(uint8_t port_id,uint8_t mode)
{
	uint8_t error_status = E_OK;
	switch(port_id)
	{
	case PORT_A: DDRA_REG = mode; break;
	case PORT_B: DDRB_REG = mode; break;
	case PORT_C: DDRC_REG = mode; break;
	case PORT_D: DDRD_REG = mode; break;
	default : error_status = E_NOK; break;
	}
	return error_status;
}
uint8_t DIO_u8SetPortValue(uint8_t port_id,uint8_t value)
{
	uint8_t error_status = E_OK;
		switch(port_id)
		{
		case PORT_A: PORTA_REG = value; break;
		case PORT_B: PORTB_REG = value; break;
		case PORT_C: PORTC_REG = value; break;
		case PORT_D: PORTD_REG = value; break;
		default : error_status = E_NOK; break;
		}
		return error_status;
}
uint8_t DIO_u8GetPortValue(uint8_t port_id,uint8_t * value)
{
	uint8_t error_status = E_OK;
		switch(port_id)
		{
		case PORT_A: *value = PINA_REG; break;
		case PORT_B: *value = PINB_REG; break;
		case PORT_C: *value = PINC_REG; break;
		case PORT_D: *value = PIND_REG; break;
		default : error_status = E_NOK; break;
		}
		return error_status;
}

uint8_t DIO_u8SetPortPullUpMode(uint8_t port_id,uint8_t mode)
{
	uint8_t error_status = E_OK;
	switch(port_id)
	{
	case PORT_A: PORTA_REG=mode; break;
	case PORT_B: PORTB_REG=mode; break;
	case PORT_C: PORTC_REG=mode; break;
	case PORT_D: PORTD_REG=mode; break;
	default : error_status = E_NOK; break;
	}
	return error_status;
}
