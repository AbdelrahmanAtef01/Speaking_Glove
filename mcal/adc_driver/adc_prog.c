#include"../../libraries/bit_math.h"
#include"../../libraries/std_types.h"
#include"../dio_driver/dio_int.h"
#include "../global_interrupt_driver/global_interrupt_int.h"
#include"adc_config.h"
#include"adc_int.h"
#include"adc_register.h"


typedef struct{
	uint8_t port;
	uint8_t pin;
} ADC_PIN;

ADC_PIN ADC_PINS[8]={ADC_0_CONNECTION,ADC_1_CONNECTION,ADC_2_CONNECTION,ADC_3_CONNECTION,
		             ADC_4_CONNECTION,ADC_5_CONNECTION,ADC_6_CONNECTION,ADC_7_CONNECTION};

void (*vector_16)(void) = NULL;
uint16_* ADC_READ=NULL;

static void ADC_vidSetMultiPlexer(uint8_t adc_pin);

void ADC_vidAdcInit(uint8_t voltage_reference)
{
	SET_BIT(ADCSRA,7);
	CLR_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,0);
	switch(voltage_reference)
	{
	case AREF_VOLTAGE:
		CLR_BIT(ADMUX,7);
		CLR_BIT(ADMUX,6);
		break;
	case VCC:
		CLR_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
		break;
	case INTERNAL_2_56_:
		SET_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
		break;
	}
#if ADC_TRIGGERING_MODE == 0
	ADC_vidAdcPinInit(ADC_AUTO_TRIGGER_PIN);
	ADC_vidSetMultiPlexer(ADC_AUTO_TRIGGER_PIN);
	ADC_VIDSetAutoTriggerMode(INT_0);
	SET_BIT(ADCSRA,5);
#elif ADC_TRIGGERING_MODE == 1
	CLR_BIT(ADCSRA,5);
#endif

#if ADC_READING_TECHNIQUE == 0
	SET_BIT(ADCSRA,3);
	GLOBAL_INTERRUPT_vidGlobalInterruptEnable(ENABLED);
#elif ADC_READING_TECHNIQUE == 1
	CLR_BIT(ADCSRA,3);
#endif

#if ADC_READING_NO_OF_BITS == 0
	SET_BIT(ADMUX,5);
#elif ADC_READING_NO_OF_BITS == 1
	CLR_BIT(ADMUX,5);
#endif

}

void ADC_vidAdcPinInit(uint8_t adc_pin)
{
	if(adc_pin<8)DIO_u8SetPinMode(ADC_PINS[adc_pin].port,ADC_PINS[adc_pin].pin,INPUT);
	else if(adc_pin==8)
	{
		for(uint8_t i=0;i<8;i++)
		{
			DIO_u8SetPinMode(ADC_PINS[i].port,ADC_PINS[i].pin,INPUT);
		}
	}
}

void ADC_vidAdcGetRead(uint8_t adc_pin)
{
	ADC_vidSetMultiPlexer(adc_pin);
	SET_BIT(ADCSRA,6);
#if ADC_READING_TECHNIQUE == 1
	while(GET_BIT(ADCSRA,4)!=1){asm("NOP");}
#if ADC_READING_NO_OF_BITS == 1
	*ADC_READ=ADCL16;
#elif ADC_READING_NO_OF_BITS == 0
	*ADC_READ=(uint16_)ADCL8;
#endif
	SET_BIT(ADCSRA,4);
#endif
}

void ADC_vidGetAutoTriggerRead()
{
#if	ADC_READING_TECHNIQUE == 1
	while(GET_BIT(ADCSRA,4)!=1);
#if ADC_READING_NO_OF_BITS == 1
	*ADC_READ=ADCL16;
#elif ADC_READING_NO_OF_BITS == 0
	*ADC_READ=(uint16_)ADCL8;
#endif
	SET_BIT(ADCSRA,4);
#endif
}

void ADC_VIDSetAutoTriggerMode(uint8_t mode)
{
	switch(mode)
	{
	case INT_0:
		CLR_BIT(SFIOR,5);
		SET_BIT(SFIOR,6);
		CLR_BIT(SFIOR,7);
		break;
	}
}

void ADC_vidSetReadingVariable(uint16_* adc_read)
{
	ADC_READ=adc_read;
}

void ADC_vidSetCallBack(void (*func)(void))
{
	vector_16=func;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
#if ADC_READING_TECHNIQUE == 0
	if(ADC_READ!=NULL)
	{
#if ADC_READING_NO_OF_BITS == 1
	*ADC_READ=ADCL16;
#elif ADC_READING_NO_OF_BITS == 0
	*ADC_READ=(uint16_)ADCL8;
#endif
	}
	if(vector_16!=NULL)vector_16();
#endif
}

static void ADC_vidSetMultiPlexer(uint8_t adc_pin)
{
	switch(adc_pin)
	{
	case ADC_0:
			CLR_BIT(ADMUX,4);
			CLR_BIT(ADMUX,3);
			CLR_BIT(ADMUX,2);
			CLR_BIT(ADMUX,1);
			CLR_BIT(ADMUX,0);
			break;
	case ADC_1:
			CLR_BIT(ADMUX,4);
			CLR_BIT(ADMUX,3);
			CLR_BIT(ADMUX,2);
			CLR_BIT(ADMUX,1);
			SET_BIT(ADMUX,0);
			break;
	case ADC_2:
			CLR_BIT(ADMUX,4);
			CLR_BIT(ADMUX,3);
			CLR_BIT(ADMUX,2);
			SET_BIT(ADMUX,1);
			CLR_BIT(ADMUX,0);
			break;
	case ADC_3:
			CLR_BIT(ADMUX,4);
			CLR_BIT(ADMUX,3);
			CLR_BIT(ADMUX,2);
			SET_BIT(ADMUX,1);
			SET_BIT(ADMUX,0);
			break;
	case ADC_4:
			CLR_BIT(ADMUX,4);
			CLR_BIT(ADMUX,3);
			SET_BIT(ADMUX,2);
			CLR_BIT(ADMUX,1);
			CLR_BIT(ADMUX,0);
			break;
	case ADC_5:
			CLR_BIT(ADMUX,4);
			CLR_BIT(ADMUX,3);
			SET_BIT(ADMUX,2);
			CLR_BIT(ADMUX,1);
			SET_BIT(ADMUX,0);
			break;
	case ADC_6:
			CLR_BIT(ADMUX,4);
			CLR_BIT(ADMUX,3);
			SET_BIT(ADMUX,2);
			SET_BIT(ADMUX,1);
			CLR_BIT(ADMUX,0);
			break;
	case ADC_7:
			CLR_BIT(ADMUX,4);
			CLR_BIT(ADMUX,3);
			SET_BIT(ADMUX,2);
			SET_BIT(ADMUX,1);
			SET_BIT(ADMUX,0);
			break;
	}
}

