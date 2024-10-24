#include "../../libraries/std_types.h"
#include "TMR0_Config.h"
#include "TMR0_Interface.h"
#include "TMR0_Address.h"

// Pointer to the user-defined callback function
static void (*TMR0_Callback)(void) = 0;

// Number of compare matches required to reach the desired time
static uint16_ TMR0_RequiredMatches = 0;

// Counter to track the number of compare matches
static uint16_ TMR0_CurrentMatches = 0;

// Function prototypes
static uint16_ TMR0_CalculateTicks(uint16_ milliseconds);

void TMR0_Init(void)
{
	// Set mode based on configuration
	#if TMR0_MODE == TMR0_MODE_NORMAL
	TCCR0_REG &= ~(1 << TCCR0_WGM00);
	TCCR0_REG &= ~(1 << TCCR0_WGM01);  // Normal mode
	#elif TMR0_MODE == TMR0_MODE_CTC
	TCCR0_REG &= ~(1 << TCCR0_WGM00);
	TCCR0_REG |= (1 << TCCR0_WGM01);   // CTC mode
	#elif TMR0_MODE == TMR0_MODE_PWM
	TCCR0_REG |= (1 << TCCR0_WGM00);
	TCCR0_REG |= (1 << TCCR0_WGM01);   // Fast PWM mode
	#endif

	// Enable Timer interrupt based on the mode
	#if TMR0_MODE == TMR0_MODE_NORMAL
	TIMSK_REG |= (1 << TIMSK_TOIE0);   // Enable Overflow Interrupt
	#elif TMR0_MODE == TMR0_MODE_CTC
	TIMSK_REG |= (1 << TIMSK_OCIE0);   // Enable Compare Match Interrupt
	#endif
	// Enable global interrupts
	SREG |= (1 << 7);
}

void TMR0_Start(uint16_ milliseconds)
{
	uint16_ ticks = TMR0_CalculateTicks(milliseconds);

	// Set compare value for CTC mode
	if (TMR0_MODE == TMR0_MODE_CTC)
	{
		OCR0_REG = ticks;
	}

	// Reset the match counter
	TMR0_CurrentMatches = 0;

	// Start the timer with the configured prescaler
	switch (TMR0_PRESCALER)
	{
		case TMR0_PRESCALER_NO:
		TCCR0_REG |= (1 << TCCR0_CS00);
		break;
		case TMR0_PRESCALER_8:
		TCCR0_REG |= (1 << TCCR0_CS01);
		break;
		case TMR0_PRESCALER_64:
		TCCR0_REG |= (1 << TCCR0_CS00) | (1 << TCCR0_CS01);
		break;
		case TMR0_PRESCALER_256:
		TCCR0_REG |= (1 << TCCR0_CS02);
		break;
		case TMR0_PRESCALER_1024:
		TCCR0_REG |= (1 << TCCR0_CS00) | (1 << TCCR0_CS02);
		break;
	}
}

void TMR0_Stop(void)
{
	// Stop the timer by clearing the clock source bits
	TCCR0_REG &= ~((1 << TCCR0_CS00) | (1 << TCCR0_CS01) | (1 << TCCR0_CS02));
}

void TMR0_SetCallback(void (*callbackFunc)(void))
{
	TMR0_Callback = callbackFunc;
}

// Interrupt Service Routine for Timer0 Compare Match
void __vector_10(void) __attribute__((signal));
void __vector_10(void){

	TMR0_CurrentMatches++;
	
	// Check if we've reached the required number of matches
	if (TMR0_CurrentMatches >= TMR0_RequiredMatches)
	{
		if (TMR0_Callback != 0)
		{
			TMR0_Callback();
		}
		TMR0_CurrentMatches = 0;  // Reset matches for the next cycle
	}
}

// Function to calculate ticks based on the desired time in milliseconds and the configured prescaler
static uint16_ TMR0_CalculateTicks(uint16_ milliseconds)
{
	uint32_t prescaler_value = 1;
	switch (TMR0_PRESCALER)
	{
		case TMR0_PRESCALER_NO:
		prescaler_value = 1;
		break;
		case TMR0_PRESCALER_8:
		prescaler_value = 8;
		break;
		case TMR0_PRESCALER_64:
		prescaler_value = 64;
		break;
		case TMR0_PRESCALER_256:
		prescaler_value = 256;
		break;
		case TMR0_PRESCALER_1024:
		prescaler_value = 1024;
		break;
	}

	// Calculate ticks based on prescaler and the desired time in milliseconds
	uint32_t ticks = ((8000000 / (prescaler_value * 1000)) * milliseconds);

	// If the number of ticks exceeds 255 (the max value for an 8-bit timer), calculate how many compare matches are required
	if (ticks > 255)
	{
		TMR0_RequiredMatches = ticks / 255;
		ticks = 255;  // Set the compare value to the maximum for the first match
	}
	else
	{
		TMR0_RequiredMatches = 1;  // Only one match is needed
	}

	return (uint16_)ticks;
}

