#ifndef MCAL_DIO_DRIVER_DIO_INT_H_
#define MCAL_DIO_DRIVER_DIO_INT_H_

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
 * macros to be used in mode param
 */
#define OUTPUT (uint8_t)1
#define INPUT  (uint8_t)0

/*
 * macros to be used in value param
 */
#define HIGH (uint8_t)1
#define LOW  (uint8_t)0

/*
 * macros to be used in pullup mode param
 */
#define Enabled (uint8_t)1
#define Disabled  (uint8_t)0

/*
 * error messages
 */
#define E_OK (uint8_t)0
#define E_NOK (uint8_t)1

uint8_t DIO_u8SetPinMode(uint8_t port_id,uint8_t pin_no,uint8_t mode);
uint8_t DIO_u8SetPinValue(uint8_t port_id,uint8_t pin_no,uint8_t value);
uint8_t DIO_u8GetPinValue(uint8_t port_id,uint8_t pin_no,uint8_t * value);
uint8_t DIO_u8IsPinOutPut(uint8_t port_id,uint8_t pin_no,uint8_t * value);
uint8_t DIO_u8SetPullUpMode(uint8_t port_id,uint8_t pin_no,uint8_t mode);

uint8_t DIO_u8SetPortMode(uint8_t port_id,uint8_t mode);
uint8_t DIO_u8SetPortValue(uint8_t port_id,uint8_t value);
uint8_t DIO_u8GetPortValue(uint8_t port_id,uint8_t * value);
uint8_t DIO_u8SetPortPullUpMode(uint8_t port_id,uint8_t mode);

#endif
