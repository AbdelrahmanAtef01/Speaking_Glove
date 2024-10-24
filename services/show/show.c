#include "../../libraries/std_types.h"
#include "show.h"
#include "show_cfg.h"
#include "../../hal/lcd_handler/lcd_int.h"
#include "../../hal/M16P_handler/M16P.h"
#include "../../mcal/TIMER0/TMR0_Interface.h"

typedef struct{

	uint16_ sound_duration;
	uint16_ folder;
	uint16_ file;

} out_put;

out_put outputs[NO_OF_WORDS] = {SEN_1_WORD_1_OUT, SEN_1_WORD_2_OUT, SEN_2_WORD_1_OUT, SEN_3_WORD_1_OUT,
								SEN_3_WORD_2_OUT, SEN_3_WORD_3_OUT, SEN_4_WORD_1_OUT, SEN_4_WORD_2_OUT,
								SEN_4_WORD_3_OUT, SEN_4_WORD_4_OUT, SEN_5_WORD_1_OUT, SEN_5_WORD_2_OUT,
								SEN_5_WORD_3_OUT, SEN_5_WORD_4_OUT, SEN_6_WORD_1_OUT, SEN_6_WORD_2_OUT,
								SEN_7_WORD_1_OUT, SEN_7_WORD_2_OUT, SEN_7_WORD_3_OUT, SEN_7_WORD_4_OUT};

out_put sound_buffer[5];
uint8_t sound_buffer_size=0;
uint8_t* ready_flag_glob;

uint8_t s1[5]   =  "I'm ";
uint8_t s2[13]  = "Intelligent ";
uint8_t s3[11]  = "Thank You ";
uint8_t s4[8]   = "Hello, ";
uint8_t s5[5]   = "How ";
uint8_t s6[9]   = "Are You ";
uint8_t s7[3]   =  "I ";
uint8_t s8[6]   = "Like ";
uint8_t s9[4]   = "My ";
uint8_t s10[8]  = "Family ";
uint8_t s11[5]  = "Can ";
uint8_t s12[5]  = "You ";
uint8_t s13[6]  = "Read ";
uint8_t s14[10] =  "The Book ";
uint8_t s15[8]  = "Please ";
uint8_t s16[6]  = "Stop ";
uint8_t s17[3]  = "I ";
uint8_t s18[6]  = "Like ";
uint8_t s19[8]  = "To Eat ";
uint8_t s20[8]  = "Apples ";

uint8_t * strings[NO_OF_WORDS] = {&s1[0], &s2[0], &s3[0], &s4[0], &s5[0], &s6[0], &s7[0], &s8[0], &s9[0], &s10[0],
						 &s11[0], &s12[0], &s13[0], &s14[0], &s15[0], &s16[0], &s17[0], &s18[0], &s19[0],
						 &s20[0]};

uint8_t strings_length[NO_OF_WORDS] = {4, 12, 10, 7, 4, 8, 2, 5, 3, 7, 4, 4, 5, 9, 7, 5, 2, 5, 7, 7};

uint8_t sentences_length[7] = {2, 1, 3, 4, 4, 2, 4};

void callback();

void SHOW_vidShowAndPlayInit (uint8_t * ready_flag)
{
	ready_flag_glob = ready_flag;
	(*ready_flag)=0;
	LCD_vidInit();
	M16P_vidInit(9600);
	TMR0_Init();
	TMR0_SetCallback(&callback);
}

uint8_t SHOW_u8CalcTrackNumber(uint8_t folder, uint8_t file)
{
	uint8_t track_number = 0;
	for(uint8_t i = 1; i<folder; i++)
	{
		track_number += i*sentences_length[i-1];
	}
	track_number += file
	return track_number;
}

void SHOW_vidShowAndPlay (uint8_t * words)
{
	uint8_t string_output[32] ={0};
	uint8_t words_cpy[10];
	uint8_t l = 0;
	for(uint8_t i=0; i<10; i++)words_cpy[i]=words[i];
	LCD_vidClearDisplay();
	(*ready_flag_glob) = 1;
	uint8_t j=0;
	for(uint8_t i=0; words_cpy[i]!=0 && words_cpy[i+1]!=0; i +=2)
	{
		for(j =0; j<NO_OF_WORDS; j++)
		{
			if(words_cpy[i]==outputs[j].folder && words_cpy[i+1]==outputs[j].file)break;
		}
		sound_buffer_size++;
		sound_buffer[i]=outputs[j];
		uint8_t * ptr = strings[j];
		for(uint8_t k = 0; k < strings_length[j]; k++)
		{
			string_output[l++] = ptr[k];
		}
	}
	string_output[l]= '\0';
	LCD_vidDisplayString(&string_output[0]);
	TMR0_Start(sound_buffer[0].sound_duration);
	//M16P_vidPlayFileInFolder(sound_buffer[0].folder, sound_buffer[0].file);
	M16P_vidPlayTrack((uint16_)SHOW_u8CalcTrackNumber(sound_buffer[0].folder, sound_buffer[0].file));
}

void callback()
{
	M16P_vidPause();
	static uint8_t current_file = 1;
	if(current_file < (sound_buffer_size-1))
	{
		M16P_vidPlayTrack((uint16_)SHOW_u8CalcTrackNumber(sound_buffer[current_file].folder, sound_buffer[current_file].file));
		//M16P_vidPlayFileInFolder(sound_buffer[current_file].folder, sound_buffer[current_file].file);
		TMR0_Start(sound_buffer[current_file].sound_duration);
		current_file++;

	}else{
		current_file = 1;
		sound_buffer_size = 0;
		(*ready_flag_glob) = 0;
	}
}
