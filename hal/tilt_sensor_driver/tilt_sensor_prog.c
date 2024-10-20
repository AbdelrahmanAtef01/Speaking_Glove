#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"
#include "tilt_sensor_cfg.h"
#include "tilt_sensor_int.h"

typedef struct{
	uint8_t port;
	uint8_t pin;
} TILT_SENSOR_PIN;

TILT_SENSOR_PIN tilt_pins[NO_OF_SENSORS] ={TILT_1_PIN,TILT_2_PIN,TILT_3_PIN,TILT_4_PIN,
										TILT_5_PIN,TILT_6_PIN,TILT_7_PIN,TILT_8_PIN};


void TILT_vidInit(uint8_t tilt_pin)
{
	if(tilt_pin<8)DIO_u8SetPinMode(tilt_pins[tilt_pin].port,tilt_pins[tilt_pin].pin,INPUT);
	else if(tilt_pin==8)
	{
		for(uint8_t i=0;i<8;i++)
		{
			DIO_u8SetPinMode(tilt_pins[i].port,tilt_pins[i].pin,INPUT);
		}
	}
}

void TILT_vidGetTiltRead(uint8_t * tilt_read, uint8_t tilt_pin)
{
	DIO_u8GetPinValue(tilt_pins[tilt_pin].port,tilt_pins[tilt_pin].pin,tilt_read);
}

void TILT_vidGetAllTiltRead(uint8_t * tilt_read)
{
	tilt_read[NO_OF_SENSORS]=0;
	for(uint8_t i=0; i<NO_OF_SENSORS;i++)
	{
		DIO_u8GetPinValue(tilt_pins[i].port,tilt_pins[i].pin,&(tilt_read[i]));
	}
	tilt_read[NO_OF_SENSORS]=1;
}
