#include "../../libraries/std_types.h"
#include "get_word_sound.h"
#include "word_sound_cfg.h"


typedef struct{

	uint16_ thumb;
	uint16_ finger_1;
	uint16_ finger_2;
	uint16_ finger_3;
	uint16_ finger_4;
	
	uint16_ tilt0;
	uint16_ tilt1;

	uint8_t sentence;
	uint8_t word;

} word;

word words[TOTAL_NO_OF_WORDS] = {SEN_1_WORD_1, SEN_1_WORD_2, SEN_2_WORD_1, SEN_3_WORD_1,
									  SEN_3_WORD_2, SEN_3_WORD_3, SEN_4_WORD_1, SEN_4_WORD_2,
									  SEN_4_WORD_3, SEN_4_WORD_4, SEN_5_WORD_1, SEN_5_WORD_2,
									  SEN_5_WORD_3, SEN_5_WORD_4, SEN_6_WORD_1, SEN_6_WORD_2,
									  SEN_7_WORD_1, SEN_7_WORD_2, SEN_7_WORD_3, SEN_7_WORD_4,
									  STOPPING_WORD, NOT_FOUND};

void GET_vidGetWordAndSound(uint16_ * sensor_reads, uint8_t * word_location )
{
	for (uint8_t i=0; i<TOTAL_NO_OF_WORDS-1; i++)
	{
		if(/*word mapping technique*/
		   sensor_reads[5]==(uint16_)words[i].tilt0 && sensor_reads[6]==(uint16_)words[i].tilt1 )
		{
			word_location[0] = words[i].sentence;
			word_location[1] = words[i].word;
			break;
		}else{
			word_location[0] = words[TOTAL_NO_OF_WORDS-1].sentence;
			word_location[1] = words[TOTAL_NO_OF_WORDS-1].word;
		}
	}


}

