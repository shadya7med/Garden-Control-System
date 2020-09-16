################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_FUNC.c \
../KeyPad_FUNC.c \
../LCD_FUNC.c \
../UART_FUNC.c \
../main.c 

OBJS += \
./DIO_FUNC.o \
./KeyPad_FUNC.o \
./LCD_FUNC.o \
./UART_FUNC.o \
./main.o 

C_DEPS += \
./DIO_FUNC.d \
./KeyPad_FUNC.d \
./LCD_FUNC.d \
./UART_FUNC.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


