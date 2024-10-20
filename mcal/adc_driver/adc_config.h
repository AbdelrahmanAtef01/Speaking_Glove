#ifndef MCAL_ADC_DRIVER_ADC_CONFIG_H_
#define MCAL_ADC_DRIVER_ADC_CONFIG_H_

/*choose auto_trigger to activate hardware auto triggering circuit
 * or software_trigger to activate triggering by code
 */
#define ADC_TRIGGERING_MODE SOFTWARE_TRIGGER

/*define the pin to read from when activating auto trigger
 */
#define ADC_AUTO_TRIGGER_PIN ADC_0

/*use _8_bit_mode to ignore the first 2 bits and read faster
 * or use _16_bit_mode to get the best precision but a bit slower
 */
#define ADC_READING_NO_OF_BITS _16_BIT_MODE

/*use interrupt_mode to activate hardware interrupt to update the data when adc finish
 * or use booling mode to wait until adc finish then return the data by software
 */
#define ADC_READING_TECHNIQUE INTERRUPT_MODE

#define ADC_0_CONNECTION {PORT_A,PIN_0}
#define ADC_1_CONNECTION {PORT_A,PIN_1}
#define ADC_2_CONNECTION {PORT_A,PIN_2}
#define ADC_3_CONNECTION {PORT_A,PIN_3}
#define ADC_4_CONNECTION {PORT_A,PIN_4}
#define ADC_5_CONNECTION {PORT_A,PIN_5}
#define ADC_6_CONNECTION {PORT_A,PIN_6}
#define ADC_7_CONNECTION {PORT_A,PIN_7}


#endif
