#ifndef SERVICES_GLOVE_HANDLER_GLOVE_INT_H_
#define SERVICES_GLOVE_HANDLER_GLOVE_INT_H_


void GLOVE_vidSensorsInit();

void GLOVE_vidSetGloveParams(uint16_* sensor_read,uint8_t no_of_sensors);

void GLOVE_vidGetHandRead();

#endif
