#ifndef HAL_LED_DRIVER_LED_INT_H_
#define HAL_LED_DRIVER_LED_INT_H_

/*
 * macros to be used in port_id param
 */
#define PORT_A (uint8_t)0
#define PORT_B (uint8_t)1
#define PORT_C (uint8_t)2
#define PORT_D (uint8_t)3

/*
 * macros to be used with pin_no param
 */
#define PIN_0 (uint8_t)0
#define PIN_1 (uint8_t)1
#define PIN_2 (uint8_t)2
#define PIN_3 (uint8_t)3
#define PIN_4 (uint8_t)4
#define PIN_5 (uint8_t)5
#define PIN_6 (uint8_t)6
#define PIN_7 (uint8_t)7

/*
 * error messages
 */
#define E_OK (uint8_t)0
#define E_NOK (uint8_t)1

uint8_t LED_u8LedOn(uint8_t port_id,uint8_t led_pin);
uint8_t LED_u8LedOff(uint8_t port_id,uint8_t led_pin);
uint8_t LED_u8LedToggle(uint8_t port_id,uint8_t led_pin);
uint8_t LED_u8LedBlink(uint8_t port_id,uint8_t led_pin,uint16_ delay_time_ms);

uint8_t LED_u8LedPortOn(uint8_t port_id);
uint8_t LED_u8LedPortOff(uint8_t port_id);
uint8_t LED_u8LedPortToggle(uint8_t port_id);
uint8_t LED_u8LedPortBlink(uint8_t port_id,uint16_ delay_time_ms);

#endif
