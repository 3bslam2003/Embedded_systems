################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BUZ_program.c \
../DIO_programe.c \
../LED_program.c \
../SSD_programe.c \
../main.c 

OBJS += \
./BUZ_program.o \
./DIO_programe.o \
./LED_program.o \
./SSD_programe.o \
./main.o 

C_DEPS += \
./BUZ_program.d \
./DIO_programe.d \
./LED_program.d \
./SSD_programe.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


