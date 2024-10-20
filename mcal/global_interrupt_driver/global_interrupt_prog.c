#include"../../libraries/std_types.h"
#include"../../libraries/bit_math.h"
#include "../global_interrupt_driver/global_interrupt_int.h"
#include "../global_interrupt_driver/global_interrupt_register.h"

void GLOBAL_INTERRUPT_vidGlobalInterruptEnable(uint8_t mode)
{
	switch(mode)
	{
		case ENABLED:
			SET_BIT(SREG,7);
			break;
		case DISABLED:
			CLR_BIT(SREG,7);
			break;
	}
}

