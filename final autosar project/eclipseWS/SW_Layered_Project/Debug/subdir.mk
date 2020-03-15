################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App.c \
../Button.c \
../Det.c \
../Dio.c \
../Dio_PBcfg.c \
../Gpt.c \
../Led.c \
../Os.c \
../Project.c 

OBJS += \
./App.o \
./Button.o \
./Det.o \
./Dio.o \
./Dio_PBcfg.o \
./Gpt.o \
./Led.o \
./Os.o \
./Project.o 

C_DEPS += \
./App.d \
./Button.d \
./Det.d \
./Dio.d \
./Dio_PBcfg.d \
./Gpt.d \
./Led.d \
./Os.d \
./Project.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


