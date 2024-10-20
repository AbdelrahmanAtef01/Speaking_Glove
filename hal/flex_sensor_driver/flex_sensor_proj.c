#include"../../libraries/bit_math.h"
#include"../../libraries/std_types.h"
#include"../../mcal/adc_driver/adc_int.h"
#include"flex_sensor_int.h"


void FLEX_vidFlexInit(uint8_t sensor_pin)
{

	ADC_vidAdcInit(AREF_VOLTAGE);
	ADC_vidAdcPinInit(sensor_pin);

}

void FLEX_vidGetFlexRead(uint16_* sensor_read, uint8_t sensor_pin)
{
	ADC_vidSetReadingVariable(sensor_read);
	ADC_vidAdcGetRead(sensor_pin);
}

void FLEX_vidSetCallBack(void (*func)(void))
{
	ADC_vidSetCallBack(func);
}

