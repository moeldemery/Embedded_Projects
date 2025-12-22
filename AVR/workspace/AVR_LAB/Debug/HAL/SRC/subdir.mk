################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SRC/BTN.c \
../HAL/SRC/KPD.c \
../HAL/SRC/LCD_config.c \
../HAL/SRC/LCD_driver.c \
../HAL/SRC/LED.c \
../HAL/SRC/SVNSEG.c 

OBJS += \
./HAL/SRC/BTN.o \
./HAL/SRC/KPD.o \
./HAL/SRC/LCD_config.o \
./HAL/SRC/LCD_driver.o \
./HAL/SRC/LED.o \
./HAL/SRC/SVNSEG.o 

C_DEPS += \
./HAL/SRC/BTN.d \
./HAL/SRC/KPD.d \
./HAL/SRC/LCD_config.d \
./HAL/SRC/LCD_driver.d \
./HAL/SRC/LED.d \
./HAL/SRC/SVNSEG.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SRC/%.o: ../HAL/SRC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti\AVR\workspace\AVR_LAB\UTILITIES" -I"D:\iti\AVR\workspace\AVR_LAB\MCAL\INC" -I"D:\iti\AVR\workspace\AVR_LAB\MCAL\SRC" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


