################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/flex_sensor_driver/flex_sensor_proj.c 

OBJS += \
./hal/flex_sensor_driver/flex_sensor_proj.o 

C_DEPS += \
./hal/flex_sensor_driver/flex_sensor_proj.d 


# Each subdirectory must supply rules for building sources it contributes
hal/flex_sensor_driver/%.o: ../hal/flex_sensor_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


