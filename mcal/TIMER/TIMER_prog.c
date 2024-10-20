/*
 * TIMER_prog.c
 *
 *  Created on: Nov 9, 2023
 *      Author: andre
 */

#include"../../libraries/std_types.h"
#include"../../libraries/bit_math.h"
#include"TIMER_config.h"
#include"TIMER_private.h"
#include"TIMER_reg.h"
#include"TIMER_interface.h"

void (* TIMER_voidpSetCallBackNormal)(void) = NULL;

static void (* TIMER_voidpSetCallBackCTC)(void) = NULL;

uint16_ compare_cnt;

void TIMER_voidInit(void){

	//Setting timer mode;
#if TIMER_MODE == NORMAL_T_MODE

	CLR_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);

	//Enabling timer flag;
	SET_BIT(TIMSK , TOIE0);

	//selecting prescaler;
	TCCR0 &= 0b11111000;
	TCCR0 |= TIMER_PRESCALER;

#elif TIMER_MODE == PWM_T_MODE

	SET_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);

	//setting output compare mode;
	TCCR0 |= (OUTPUT_COMPARE_MODE<<4);

	//selecting prescaler;
	TCCR0 &= 0b11111000;
	TCCR0 |= TIMER_PRESCALER;

#elif TIMER_MODE == CTC_T_MODE

	CLR_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);

	//Enabling CTC flag;
	SET_BIT(TIMSK , OCIE0);

	//Set compare match value 250;
	//OCR0 = 250;

	//selecting prescaler;
	TCCR0 &= 0b11111000;
	TCCR0 |= TIMER_PRESCALER;

#elif TIMER_MODE == FAST_PWM_T_MODE

	SET_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);

	//setting output compare mode;
	TCCR0 |= (OUTPUT_COMPARE_MODE<<4);

	//selecting prescaler;
	TCCR0 &= 0b11111000;
	TCCR0 |= TIMER_PRESCALER;

#else

#error "wrong timer mode"


#endif


}

void TIMER_voidDisable(void){

	TCCR0 &= 0b11111000;

}

uint8_t TIMER_uint8SetPrescaler(uint8_t Copy_uint8Prescaler){

	uint8_t Local_uint8ErrorState = 0;

	if(Copy_uint8Prescaler <8){

		//selecting prescaler;
		TCCR0 &= 0b11111000;
		TCCR0 |= Copy_uint8Prescaler;

	}
	else{

		Local_uint8ErrorState = 1;

	}

	return Local_uint8ErrorState;

}

void TIMER_voidSetCounterRegister(uint8_t Copy_uint8CounterStart){

	TCNT0 = Copy_uint8CounterStart;

}

void TIMER_voidSetCTCTime(uint8_t Copy_uint8CompareTime){

	OCR0 = Copy_uint8CompareTime;

}

void TIMER_voidGetNumCountCTC(uint16_ Copy_uint8DesiredTime, uint16_ * Copy_uint16pNumOfCounts, uint8_t * Copy_uint8pCompareValue){

#define PRESCALER		TIMER_PRESCALER

#if PRESCALER == CLK_1024
#define TICK_TIME		128

	* Copy_uint16pNumOfCounts = (uint16_)(((uint32_t)Copy_uint8DesiredTime*1000)/((uint32_t)TICK_TIME*250));
	* Copy_uint8pCompareValue = 250;

#elif PRESCALER == CLK_256
#define TICK_TIME		32

	* Copy_uint16pNumOfCounts = (uint16_)(((uint32_t)Copy_uint8DesiredTime*1000)/((uint32_t)TICK_TIME*250));
	* Copy_uint8pCompareValue = 250;

#elif PRESCALER == CLK_64
#define TICK_TIME		8

	* Copy_uint16pNumOfCounts = (uint16_)(((uint32_t)Copy_uint8DesiredTime*1000)/((uint32_t)TICK_TIME*250));
	* Copy_uint8pCompareValue = 250;

#elif PRESCALER == CLK_8

	* Copy_uint16pNumOfCounts = (uint16_)(((uint32_t)Copy_uint8DesiredTime*1000)/250);
	* Copy_uint8pCompareValue = 250;

#elif PRESCALER == CLK
#define TICK_TIME		12/100
	* Copy_uint16pNumOfCounts = (uint16_)(((uint32_t)Copy_uint8DesiredTime*1000)/(250*TICK_TIME));
	* Copy_uint8pCompareValue = 250;

#endif
}


void TIMER_voidSetCallBackNormal(void (* Copy_uint8pSetCallBackNormal)(void)){

	TIMER_voidpSetCallBackNormal = Copy_uint8pSetCallBackNormal;

}

void TIMER_voidSetCallBackCTC(void (* Copy_uint8pSetCallBackCTC)(void)){

	TIMER_voidpSetCallBackCTC = Copy_uint8pSetCallBackCTC;

}

void __vector_11(void) __attribute__((signal));
void __vector_11(void){

	if(TIMER_voidpSetCallBackNormal != NULL){

		TIMER_voidpSetCallBackNormal();

	}
	else{

		//do nothing;

	}

}

void __vector_10(void) __attribute__((signal));
void __vector_10(void){


	static uint16_ cnt = 0;
	//extern uint16_ compare_cnt;
	cnt++;
	if(cnt == compare_cnt){

//		TIMER_voidSetCounterRegister(123);
		if(TIMER_voidpSetCallBackCTC != NULL){

			TIMER_voidpSetCallBackCTC();
			cnt = 0;
		}
		else{

			//do nothing;

		}


	}


}
