################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SRC/ADC.c \
../MCAL/SRC/DIO_config.c \
../MCAL/SRC/DIO_driver.c \
../MCAL/SRC/INT_program.c \
../MCAL/SRC/SPI.c \
../MCAL/SRC/TMR.c \
../MCAL/SRC/UART_driver.c 

OBJS += \
./MCAL/SRC/ADC.o \
./MCAL/SRC/DIO_config.o \
./MCAL/SRC/DIO_driver.o \
./MCAL/SRC/INT_program.o \
./MCAL/SRC/SPI.o \
./MCAL/SRC/TMR.o \
./MCAL/SRC/UART_driver.o 

C_DEPS += \
./MCAL/SRC/ADC.d \
./MCAL/SRC/DIO_config.d \
./MCAL/SRC/DIO_driver.d \
./MCAL/SRC/INT_program.d \
./MCAL/SRC/SPI.d \
./MCAL/SRC/TMR.d \
./MCAL/SRC/UART_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SRC/%.o: ../MCAL/SRC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti\AVR\workspace\AVR_LAB\UTILITIES" -I"D:\iti\AVR\workspace\AVR_LAB\MCAL\INC" -I"D:\iti\AVR\workspace\AVR_LAB\MCAL\SRC" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


