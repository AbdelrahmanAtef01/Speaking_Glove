#include "../../libraries/std_types.h"
#include "get_word_sound.h"
#include "word_sound_cfg.h"


typedef struct{

	uint16_ thumb_min;
	uint16_ thumb_max;

	uint16_ finger_1_min;
	uint16_ finger_1_max;

	uint16_ finger_2_min;
	uint16_ finger_2_max;

	uint16_ finger_3_min;
	uint16_ finger_3_max;

	uint16_ finger_4_min;
	uint16_ finger_4_max;

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
		if(/*sensor_reads[4]>=words[i].thumb_min && sensor_reads[4]<=words[i].thumb_max &&
		   sensor_reads[0]>=words[i].finger_1_min && sensor_reads[0]<=words[i].finger_1_max &&
		   sensor_reads[2]>=words[i].finger_2_min && sensor_reads[2]<=words[i].finger_2_max &&
		   sensor_reads[1]>=words[i].finger_3_min && sensor_reads[1]<=words[i].finger_3_max &&
		   sensor_reads[3]>=words[i].finger_4_min && sensor_reads[3]<=words[i].finger_4_max &&*/
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

