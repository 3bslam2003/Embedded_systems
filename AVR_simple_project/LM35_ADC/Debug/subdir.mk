################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_programe.c \
../DIO_programe.c \
../LCD_program.c \
../LED_program.c \
../LM35_programe.c \
../main.c 

OBJS += \
./ADC_programe.o \
./DIO_programe.o \
./LCD_program.o \
./LED_program.o \
./LM35_programe.o \
./main.o 

C_DEPS += \
./ADC_programe.d \
./DIO_programe.d \
./LCD_program.d \
./LED_program.d \
./LM35_programe.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


