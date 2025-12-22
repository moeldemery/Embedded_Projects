################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1-MCAL/SRC/DIO_driver.c 

OBJS += \
./1-MCAL/SRC/DIO_driver.o 

C_DEPS += \
./1-MCAL/SRC/DIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
1-MCAL/SRC/%.o: ../1-MCAL/SRC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti\AVR\workspace\AVR_LAB\UTILITIES" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


