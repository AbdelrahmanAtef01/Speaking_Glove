#ifndef _TMR0_INTERFACE_H
#define _TMR0_INTERFACE_H

#include "TMR0_Config.h"

// Initialize the timer with configuration
void TMR0_Init(void);

// Start the timer for a given time in milliseconds
void TMR0_Start(uint16_ milliseconds);

// Stop the timer
void TMR0_Stop(void);

// Set a callback function to be called after the timer completes
void TMR0_SetCallback(void (*callbackFunc)(void));

#endif /* _TMR0_INTERFACE_H */

