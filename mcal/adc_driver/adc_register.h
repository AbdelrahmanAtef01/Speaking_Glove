#ifndef MCAL_ADC_DRIVER_ADC_REGISTER_H_
#define MCAL_ADC_DRIVER_ADC_REGISTER_H_

#define ADMUX (*((volatile uint8_t*)0x27))
#define ADCSRA (*((volatile uint8_t*)0x26))
#define ADCL16 (*((volatile uint16_*)0x24))
#define ADCL8 (*((volatile uint8_t*)0x25))
#define SFIOR (*((volatile uint8_t*)0x50))


#endif
