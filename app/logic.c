#include "../libraries/std_types.h"
#include "../services/glove_handler/glove_int.h"
#include "../services/get_word_sound/get_word_sound.h"
#include "../services/show/show.h"
#include "../hal/lcd_handler/lcd_int.h"
#include "../hal/M16P_handler/M16P.h"
#include "../mcal/global_interrupt_driver/global_interrupt_int.h"
#include "../mcal/TIMER1/TIMER1_interface.h"
#include "util/delay.h"
#include "app_mode_cfg.h"


uint16_ sensor_reads[8];

#if APP_MODE == TRAIN

/*
 *
 * 179
 * 156
 * 190
 * 192
 * 190
 * 0
 * 1
 *
 * */

int main()
{
	uint8_t s1[9] =  "Thumb : ";
	uint8_t s2[11] = "Finger1 : ";
	uint8_t s3[11] = "Finger2 : ";
	uint8_t s4[11] = "Finger3 : ";
	uint8_t s5[11] = "Finger4 : ";
	uint8_t s6[19] = "Horizontal tilt : ";
	uint8_t s7[17] = "Vertical tilt : ";

	LCD_vidInit();
	GLOVE_vidSensorsInit();
	GLOVE_vidSetGloveParams(&sensor_reads[0],7);

	while(1)
	{
		GLOVE_vidGetHandRead();
		if(sensor_reads[7]==1)
		{
			LCD_vidClearDisplay();
			LCD_vidDisplayString(&s1[0]);
			LCD_vidWriteInteger(sensor_reads[4]);
			LCD_vidNewLine();
			LCD_vidDisplayString(&s2[0]);
			LCD_vidWriteInteger(sensor_reads[0]);
			_delay_ms(2000);
			LCD_vidClearDisplay();
			LCD_vidDisplayString(&s3[0]);
			LCD_vidWriteInteger(sensor_reads[2]);
			LCD_vidNewLine();
			LCD_vidDisplayString(&s4[0]);
			LCD_vidWriteInteger(sensor_reads[1]);
			_delay_ms(2000);
			LCD_vidClearDisplay();
			LCD_vidDisplayString(&s5[0]);
			LCD_vidWriteInteger(sensor_reads[3]);
			_delay_ms(2000);
			LCD_vidClearDisplay();
			LCD_vidDisplayString(&s6[0]);
			LCD_vidNewLine();
			LCD_vidWriteInteger(sensor_reads[5]);
			_delay_ms(2000);
			LCD_vidClearDisplay();
			LCD_vidDisplayString(&s7[0]);
			LCD_vidNewLine();
			LCD_vidWriteInteger(sensor_reads[6]);
			_delay_ms(2000);
		}

	}
	return 0;
}



#else

uint8_t word_location_buffer[10];
uint8_t word_location[10];
uint8_t get_another_read_flag = 1;
extern compare_cnt1;
void get_word();

int main()
{
	GLOBAL_INTERRUPT_vidGlobalInterruptEnable(ENABLED);
	uint8_t ready_flag = 0;
	uint8_t compare_value;
	GLOVE_vidSensorsInit();
	SHOW_vidShowAndPlayInit(&ready_flag);
	GLOVE_vidSetGloveParams(&sensor_reads[0],7);
	TIMER1_voidInit();
	TIMER1_voidGetNumCountCTC(100, &compare_cnt1, &compare_value);
	TIMER1_voidSetCTCTime(compare_value);
	TIMER1_voidSetCallBackCTC(&get_word);
	GLOVE_vidGetHandRead();
	while(1)
	{
		while(ready_flag);
		LCD_vidDisplayString((uint8_t*)"H");
		get_another_read_flag = 1;
		SHOW_vidShowAndPlay(&word_location[0]);
	}

	return 0;
}

void get_word()
{
	static uint8_t i = 0;
	if(i<5 && sensor_reads[7] && get_another_read_flag)
	{
		LCD_vidDisplayString((uint8_t*)"A");
		GET_vidGetWordAndSound(&sensor_reads[0], &word_location_buffer[i*2]);
		if(word_location_buffer[i*2]== 0 && word_location_buffer[i*2+1]== 1 )i--;
		else if(word_location_buffer[i*2]== 0 && word_location_buffer[i*2+1]== 0 )i=5;
		GLOVE_vidGetHandRead();
		i++;
	}else {
		i = 0;
		get_another_read_flag = 0;
	}

}
#endif

