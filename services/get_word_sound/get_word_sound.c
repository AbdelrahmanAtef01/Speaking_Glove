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

// HELPING FUNCTIONS 
// #1 Function to calculate Euclidean distance between two sensor readings
float calculate_distance(uint16_t* sensor_reads, word* word) {
    float distance = 0.0;
    distance += pow((float)(sensor_reads[0] - word->thumb), 2);
    distance += pow((float)(sensor_reads[1] - word->finger_1), 2);
    distance += pow((float)(sensor_reads[2] - word->finger_2), 2);
    distance += pow((float)(sensor_reads[3] - word->finger_3), 2);
    distance += pow((float)(sensor_reads[4] - word->finger_4), 2);
    distance += pow((float)(sensor_reads[5] - word->tilt0), 2);
    distance += pow((float)(sensor_reads[6] - word->tilt1), 2);
    return sqrt(distance);
}


// #2 Function to find the closest predefined sensor data
int find_closest_sensor(word* words, uint16_t* sensor_reads, int num_words) {
    int closest_index = 0;
    float min_distance = calculate_distance(sensor_reads, &words[0]);

    for (int i = 1; i < num_words; i++) {
        float distance = calculate_distance(sensor_reads, &words[i]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_index = i;
        }
    }
    return closest_index;
}


// Main Function 
void GET_vidGetWordAndSound(uint16_t * sensor_reads, uint8_t * word_location )
{
	
uint8_t i = find_closest_sensor(words, sensor_reads, TOTAL_NO_OF_WORDS);

word_location[0] = words[i].sentence;
word_location[1] = words[i].word;

}
