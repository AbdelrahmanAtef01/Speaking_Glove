################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include services/show/subdir.mk
-include services/glove_handler/subdir.mk
-include services/get_word_sound/subdir.mk
-include mcal/global_interrupt_driver/subdir.mk
-include mcal/dio_driver/subdir.mk
-include mcal/adc_driver/subdir.mk
-include mcal/UART_DRIVER/subdir.mk
-include mcal/TIMER1/subdir.mk
-include mcal/TIMER/subdir.mk
-include hal/tilt_sensor_driver/subdir.mk
-include hal/lcd_handler/subdir.mk
-include hal/flex_sensor_driver/subdir.mk
-include hal/M16P_handler/subdir.mk
-include app/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Glove_project.lss \

FLASH_IMAGE += \
Glove_project.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Glove_project.elf secondary-outputs

# Tool invocations
Glove_project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Glove_project.map -mmcu=atmega32 -o "Glove_project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Glove_project.lss: Glove_project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Glove_project.elf  >"Glove_project.lss"
	@echo 'Finished building: $@'
	@echo ' '

Glove_project.hex: Glove_project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Glove_project.elf  "Glove_project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Glove_project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Glove_project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Glove_project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
