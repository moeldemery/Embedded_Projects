################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp_clkconfig.c \
../src/bsp_gpio.c \
../src/bsp_led.c \
../src/bsp_systick2.c \
../src/bsp_systick_wifi.c \
../src/bsp_usart.c \
../src/bsp_usart1.c \
../src/bsp_usart2.c \
../src/main.c \
../src/stm32f10x_it.c \
../src/wifi_config.c \
../src/wifi_function.c 

OBJS += \
./src/bsp_clkconfig.o \
./src/bsp_gpio.o \
./src/bsp_led.o \
./src/bsp_systick2.o \
./src/bsp_systick_wifi.o \
./src/bsp_usart.o \
./src/bsp_usart1.o \
./src/bsp_usart2.o \
./src/main.o \
./src/stm32f10x_it.o \
./src/wifi_config.o \
./src/wifi_function.o 

C_DEPS += \
./src/bsp_clkconfig.d \
./src/bsp_gpio.d \
./src/bsp_led.d \
./src/bsp_systick2.d \
./src/bsp_systick_wifi.d \
./src/bsp_usart.d \
./src/bsp_usart1.d \
./src/bsp_usart2.d \
./src/main.d \
./src/stm32f10x_it.d \
./src/wifi_config.d \
./src/wifi_function.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


