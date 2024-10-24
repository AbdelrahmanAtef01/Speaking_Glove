#ifndef _TMR0_CONFIG_H
#define _TMR0_CONFIG_H


// Define Timer modes
#define TMR0_MODE_NORMAL      0
#define TMR0_MODE_CTC         1
#define TMR0_MODE_PWM         2

// Define Clock Source (Prescaler values)
#define TMR0_PRESCALER_NO     1
#define TMR0_PRESCALER_8      2
#define TMR0_PRESCALER_64     3
#define TMR0_PRESCALER_256    4
#define TMR0_PRESCALER_1024   5

// Choose the timer mode and prescaler for your configuration
#define TMR0_MODE            TMR0_MODE_CTC
#define TMR0_PRESCALER       TMR0_PRESCALER_64

#endif /* _TMR0_CONFIG_H */

