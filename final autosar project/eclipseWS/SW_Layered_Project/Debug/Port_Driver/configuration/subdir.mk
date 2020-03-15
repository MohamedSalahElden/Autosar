################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Port_Driver/configuration/Port_PBcfg.c 

OBJS += \
./Port_Driver/configuration/Port_PBcfg.o 

C_DEPS += \
./Port_Driver/configuration/Port_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
Port_Driver/configuration/%.o: ../Port_Driver/configuration/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


