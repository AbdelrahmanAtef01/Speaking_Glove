#ifndef HAL_FLEX_SENSOR_DRIVER_FLEX_SENSOR_INT_H_
#define HAL_FLEX_SENSOR_DRIVER_FLEX_SENSOR_INT_H_

/*available pins to use with the sensor_pin param*/
#define FLEX_0	ADC_0
#define FLEX_1	ADC_1
#define FLEX_2	ADC_2
#define FLEX_3	ADC_3
#define FLEX_4	ADC_4
#define FLEX_5	ADC_5
#define FLEX_6	ADC_6
#define FLEX_7	ADC_7
#define FLEX_ALL	ADC_ALL


void FLEX_vidFlexInit(uint8_t sensor_pin);

void FLEX_vidGetFlexRead(uint16_* sensor_read, uint8_t sensor_pin);

void FLEX_vidSetCallBack(void (*func)(void));



#endif
