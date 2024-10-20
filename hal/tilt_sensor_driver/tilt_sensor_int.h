#ifndef HAL_TILT_SENSOR_DRIVER_TILT_SENSOR_INT_H_
#define HAL_TILT_SENSOR_DRIVER_TILT_SENSOR_INT_H_


/*tilt sensors to use with the tilt_pin param*/
#define TILT_0	(uint8_t)0
#define TILT_1	(uint8_t)1
#define TILT_2	(uint8_t)2
#define TILT_3	(uint8_t)3
#define TILT_4	(uint8_t)4
#define TILT_5	(uint8_t)5
#define TILT_6	(uint8_t)6
#define TILT_7	(uint8_t)7
#define ALL_TILT (uint8_t)8

void TILT_vidInit(uint8_t tilt_pin);

void TILT_vidGetTiltRead(uint8_t * tilt_read, uint8_t tilt_pin);

void TILT_vidGetAllTiltRead(uint8_t * tilt_read);

#endif
