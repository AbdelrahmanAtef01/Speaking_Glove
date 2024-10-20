#include"../../libraries/std_types.h"
#include"../../mcal/adc_driver/adc_int.h"
#include"../../hal/flex_sensor_driver/flex_sensor_int.h"
#include"../../hal/tilt_sensor_driver/tilt_sensor_int.h"

uint16_* SENSOR_READ = NULL;

uint8_t NO_OF_FLEX_SENSORS=0;

uint16_ READ = 0;
uint16_ i = 0;

uint8_t FLEX_SENSORS[8] = {FLEX_0, FLEX_1, FLEX_2, FLEX_3, FLEX_4, FLEX_5, FLEX_6, FLEX_7};

void GLOVE_vidCallBack()
{
	SENSOR_READ[i]=READ;
	if(i < NO_OF_FLEX_SENSORS-1)
	{
		SENSOR_READ[NO_OF_FLEX_SENSORS + 2]=0;
		i++;
		READ=0;
		FLEX_vidGetFlexRead(&READ,FLEX_SENSORS[i]);
	}else if(i == NO_OF_FLEX_SENSORS-1)
	{
		i=0;
		READ=0;
		SENSOR_READ[NO_OF_FLEX_SENSORS + 2]=1;
	}
}

void GLOVE_vidSensorsInit()
{
	FLEX_vidFlexInit(FLEX_ALL);
	TILT_vidInit(TILT_0);
	TILT_vidInit(TILT_1);
	FLEX_vidSetCallBack(&GLOVE_vidCallBack);
}

void GLOVE_vidSetGloveParams(uint16_* sensor_read, uint8_t no_of_sensors)
{
	SENSOR_READ = sensor_read;
	if(no_of_sensors<=8)NO_OF_FLEX_SENSORS = no_of_sensors - 2;
}

void GLOVE_vidGetHandRead()
{
	if(i==0)
	{
		TILT_vidGetTiltRead(&SENSOR_READ[NO_OF_FLEX_SENSORS],TILT_0);
		TILT_vidGetTiltRead(&SENSOR_READ[NO_OF_FLEX_SENSORS + 1],TILT_1);
		FLEX_vidGetFlexRead(&READ,FLEX_SENSORS[i]);
	}
}


