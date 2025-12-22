################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/APP_Calc.c \
../APP/APP_Story.c \
../APP/APP_UnitTesting.c 

OBJS += \
./APP/APP_Calc.o \
./APP/APP_Story.o \
./APP/APP_UnitTesting.o 

C_DEPS += \
./APP/APP_Calc.d \
./APP/APP_Story.d \
./APP/APP_UnitTesting.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti\AVR\workspace\AVR_LAB\UTILITIES" -I"D:\iti\AVR\workspace\AVR_LAB\MCAL\INC" -I"D:\iti\AVR\workspace\AVR_LAB\MCAL\SRC" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


