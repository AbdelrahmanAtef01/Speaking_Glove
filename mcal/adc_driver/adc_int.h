#ifndef MCAL_ADC_DRIVER_ADC_INT_H_
#define MCAL_ADC_DRIVER_ADC_INT_H_

/*modes to use with ADC_TRIGGERING_MODE*/
#define AUTO_TRIGGER	  0
#define SOFTWARE_TRIGGER  1

/*modes to use with ADC_READING_NO_OF_BITS*/
#define _8_BIT_MODE	  0
#define _16_BIT_MODE  1

/*modes to use with ADC_READING_TECHNIQUE*/
#define INTERRUPT_MODE	0
#define BOOLING_MODE	1

/*adcs to use with the adc_pin param*/
#define ADC_0	(uint8_t)0
#define ADC_1	(uint8_t)1
#define ADC_2	(uint8_t)2
#define ADC_3	(uint8_t)3
#define ADC_4	(uint8_t)4
#define ADC_5	(uint8_t)5
#define ADC_6	(uint8_t)6
#define ADC_7	(uint8_t)7
#define ADC_ALL (uint8_t)8

/*modes to use with set auto trigger mode param*/
#define INT_0		(uint8_t)1

/*adcs to use with the voltage_reference param*/
#define INTERNAL_2_56_	(uint8_t)0
#define VCC	(uint8_t)1
#define AREF_VOLTAGE	(uint8_t)2

void ADC_vidAdcInit(uint8_t voltage_reference);

void ADC_vidAdcPinInit(uint8_t adc_pin);

void ADC_vidAdcGetRead(uint8_t adc_pin);

void ADC_vidGetAutoTriggerRead();

void ADC_VIDSetAutoTriggerMode(uint8_t mode);

void ADC_vidSetReadingVariable(uint16_* adc_read);

void ADC_vidSetCallBack( void (*func)(void));

#endif
