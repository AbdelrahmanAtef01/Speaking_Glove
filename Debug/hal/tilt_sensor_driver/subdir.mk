################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/tilt_sensor_driver/tilt_sensor_prog.c 

OBJS += \
./hal/tilt_sensor_driver/tilt_sensor_prog.o 

C_DEPS += \
./hal/tilt_sensor_driver/tilt_sensor_prog.d 


# Each subdirectory must supply rules for building sources it contributes
hal/tilt_sensor_driver/%.o: ../hal/tilt_sensor_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


