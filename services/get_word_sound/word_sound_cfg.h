#ifndef SERVICES_GET_WORD_SOUND_WORD_SOUND_CFG_H_
#define SERVICES_GET_WORD_SOUND_WORD_SOUND_CFG_H_

// #define TOTAL_NO_OF_WORDS	(uint8_t)22    // commented for debugging
#define TOTAL_NO_OF_WORDS	(uint8_t)20   
#define NUM_SENSORS (uint8_t)7



#define SEN_1_WORD_1	{(uint16_)145, (uint16_)135, (uint16_)227, (uint16_)167, (uint16_)207, (uint16_)1, (uint16_)1, (uint8_t)1, (uint8_t)1}
#define SEN_1_WORD_2	{(uint16_)156, (uint16_)159, (uint16_)199, (uint16_)163, (uint16_)153, (uint16_)0, (uint16_)1, (uint8_t)1, (uint8_t)2}

#define SEN_2_WORD_1	{(uint16_)176, (uint16_)153, (uint16_)179, (uint16_)175, (uint16_)167, (uint16_)0, (uint16_)1, (uint8_t)2, (uint8_t)1}

#define SEN_3_WORD_1	{(uint16_)184, (uint16_)147, (uint16_)184, (uint16_)184, (uint16_)159, (uint16_)0, (uint16_)1, (uint8_t)3, (uint8_t)1}
#define SEN_3_WORD_2	{(uint16_)152, (uint16_)206, (uint16_)192, (uint16_)161, (uint16_)204, (uint16_)0, (uint16_)1, (uint8_t)3, (uint8_t)2}
#define SEN_3_WORD_3	{(uint16_)176, (uint16_)143, (uint16_)240, (uint16_)167, (uint16_)199, (uint16_)0, (uint16_)1, (uint8_t)3, (uint8_t)3}

#define SEN_4_WORD_1	{(uint16_)209, (uint16_)127, (uint16_)255, (uint16_)216, (uint16_)204, (uint16_)0, (uint16_)1, (uint8_t)4, (uint8_t)1}
#define SEN_4_WORD_2	{(uint16_)192, (uint16_)152, (uint16_)207, (uint16_)183, (uint16_)188, (uint16_)1, (uint16_)1, (uint8_t)4, (uint8_t)2}
#define SEN_4_WORD_3	{(uint16_)176, (uint16_)153, (uint16_)172, (uint16_)172, (uint16_)156, (uint16_)0, (uint16_)1, (uint8_t)4, (uint8_t)3}
#define SEN_4_WORD_4	{(uint16_)193, (uint16_)176, (uint16_)206, (uint16_)199, (uint16_)188, (uint16_)0, (uint16_)1, (uint8_t)4, (uint8_t)4}

#define SEN_5_WORD_1	{(uint16_)216, (uint16_)198, (uint16_)225, (uint16_)211, (uint16_)222, (uint16_)0, (uint16_)1, (uint8_t)5, (uint8_t)1}
#define SEN_5_WORD_2	{(uint16_)207, (uint16_)143, (uint16_)231, (uint16_)207, (uint16_)207, (uint16_)0, (uint16_)1, (uint8_t)5, (uint8_t)2}
#define SEN_5_WORD_3	{(uint16_)224, (uint16_)143, (uint16_)206, (uint16_)195, (uint16_)408, (uint16_)1, (uint16_)1, (uint8_t)5, (uint8_t)3}
#define SEN_5_WORD_4	{(uint16_)192, (uint16_)145, (uint16_)172, (uint16_)177, (uint16_)167, (uint16_)1, (uint16_)1, (uint8_t)5, (uint8_t)4}

#define SEN_6_WORD_1	{(uint16_)177, (uint16_)145, (uint16_)174, (uint16_)177, (uint16_)172, (uint16_)1, (uint16_)1, (uint8_t)6, (uint8_t)1}
#define SEN_6_WORD_2	{(uint16_)174, (uint16_)152, (uint16_)176, (uint16_)179, (uint16_)159, (uint16_)1, (uint16_)1, (uint8_t)6, (uint8_t)2}

#define SEN_7_WORD_1	{(uint16_)209, (uint16_)127, (uint16_)255, (uint16_)216, (uint16_)204, (uint16_)0, (uint16_)1, (uint8_t)7, (uint8_t)1}
#define SEN_7_WORD_2	{(uint16_)182, (uint16_)152, (uint16_)207, (uint16_)183, (uint16_)188, (uint16_)1, (uint16_)1, (uint8_t)7, (uint8_t)2}
#define SEN_7_WORD_3	{(uint16_)182, (uint16_)152, (uint16_)209, (uint16_)206, (uint16_)190, (uint16_)0, (uint16_)1, (uint8_t)7, (uint8_t)3}
#define SEN_7_WORD_4	{(uint16_)199, (uint16_)236, (uint16_)209, (uint16_)206, (uint16_)211, (uint16_)1, (uint16_)1, (uint8_t)7, (uint8_t)4}


#define STOPPING_WORD	{(uint16_)170, (uint16_)190, (uint16_)145, (uint16_)165, (uint16_)180, (uint16_)200, (uint16_)182, (uint16_)202, (uint16_)180, (uint16_)200, (uint16_)0, (uint16_)1, (uint8_t)0, (uint8_t)0}
#define NOT_FOUND		{(uint16_)100, (uint16_)120, (uint16_)100, (uint16_)120, (uint16_)100, (uint16_)120, (uint16_)100, (uint16_)120, (uint16_)100, (uint16_)120, (uint16_)1, (uint16_)1, (uint8_t)0, (uint8_t)1}



#endif
