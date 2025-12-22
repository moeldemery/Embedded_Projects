################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/stm32f1-stdperiph/misc.c \
../src/stm32f1-stdperiph/stm32f10x_adc.c \
../src/stm32f1-stdperiph/stm32f10x_bkp.c \
../src/stm32f1-stdperiph/stm32f10x_can.c \
../src/stm32f1-stdperiph/stm32f10x_cec.c \
../src/stm32f1-stdperiph/stm32f10x_crc.c \
../src/stm32f1-stdperiph/stm32f10x_dac.c \
../src/stm32f1-stdperiph/stm32f10x_dbgmcu.c \
../src/stm32f1-stdperiph/stm32f10x_dma.c \
../src/stm32f1-stdperiph/stm32f10x_exti.c \
../src/stm32f1-stdperiph/stm32f10x_flash.c \
../src/stm32f1-stdperiph/stm32f10x_fsmc.c \
../src/stm32f1-stdperiph/stm32f10x_gpio.c \
../src/stm32f1-stdperiph/stm32f10x_i2c.c \
../src/stm32f1-stdperiph/stm32f10x_iwdg.c \
../src/stm32f1-stdperiph/stm32f10x_pwr.c \
../src/stm32f1-stdperiph/stm32f10x_rcc.c \
../src/stm32f1-stdperiph/stm32f10x_rtc.c \
../src/stm32f1-stdperiph/stm32f10x_sdio.c \
../src/stm32f1-stdperiph/stm32f10x_spi.c \
../src/stm32f1-stdperiph/stm32f10x_tim.c \
../src/stm32f1-stdperiph/stm32f10x_usart.c \
../src/stm32f1-stdperiph/stm32f10x_wwdg.c 

OBJS += \
./src/stm32f1-stdperiph/misc.o \
./src/stm32f1-stdperiph/stm32f10x_adc.o \
./src/stm32f1-stdperiph/stm32f10x_bkp.o \
./src/stm32f1-stdperiph/stm32f10x_can.o \
./src/stm32f1-stdperiph/stm32f10x_cec.o \
./src/stm32f1-stdperiph/stm32f10x_crc.o \
./src/stm32f1-stdperiph/stm32f10x_dac.o \
./src/stm32f1-stdperiph/stm32f10x_dbgmcu.o \
./src/stm32f1-stdperiph/stm32f10x_dma.o \
./src/stm32f1-stdperiph/stm32f10x_exti.o \
./src/stm32f1-stdperiph/stm32f10x_flash.o \
./src/stm32f1-stdperiph/stm32f10x_fsmc.o \
./src/stm32f1-stdperiph/stm32f10x_gpio.o \
./src/stm32f1-stdperiph/stm32f10x_i2c.o \
./src/stm32f1-stdperiph/stm32f10x_iwdg.o \
./src/stm32f1-stdperiph/stm32f10x_pwr.o \
./src/stm32f1-stdperiph/stm32f10x_rcc.o \
./src/stm32f1-stdperiph/stm32f10x_rtc.o \
./src/stm32f1-stdperiph/stm32f10x_sdio.o \
./src/stm32f1-stdperiph/stm32f10x_spi.o \
./src/stm32f1-stdperiph/stm32f10x_tim.o \
./src/stm32f1-stdperiph/stm32f10x_usart.o \
./src/stm32f1-stdperiph/stm32f10x_wwdg.o 

C_DEPS += \
./src/stm32f1-stdperiph/misc.d \
./src/stm32f1-stdperiph/stm32f10x_adc.d \
./src/stm32f1-stdperiph/stm32f10x_bkp.d \
./src/stm32f1-stdperiph/stm32f10x_can.d \
./src/stm32f1-stdperiph/stm32f10x_cec.d \
./src/stm32f1-stdperiph/stm32f10x_crc.d \
./src/stm32f1-stdperiph/stm32f10x_dac.d \
./src/stm32f1-stdperiph/stm32f10x_dbgmcu.d \
./src/stm32f1-stdperiph/stm32f10x_dma.d \
./src/stm32f1-stdperiph/stm32f10x_exti.d \
./src/stm32f1-stdperiph/stm32f10x_flash.d \
./src/stm32f1-stdperiph/stm32f10x_fsmc.d \
./src/stm32f1-stdperiph/stm32f10x_gpio.d \
./src/stm32f1-stdperiph/stm32f10x_i2c.d \
./src/stm32f1-stdperiph/stm32f10x_iwdg.d \
./src/stm32f1-stdperiph/stm32f10x_pwr.d \
./src/stm32f1-stdperiph/stm32f10x_rcc.d \
./src/stm32f1-stdperiph/stm32f10x_rtc.d \
./src/stm32f1-stdperiph/stm32f10x_sdio.d \
./src/stm32f1-stdperiph/stm32f10x_spi.d \
./src/stm32f1-stdperiph/stm32f10x_tim.d \
./src/stm32f1-stdperiph/stm32f10x_usart.d \
./src/stm32f1-stdperiph/stm32f10x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
src/stm32f1-stdperiph/%.o: ../src/stm32f1-stdperiph/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\diag" -I"D:\iti\ARM\wifi_test2\system\include\cortexm" -I"D:\iti\ARM\wifi_test2\system\include\cmsis" -I"D:\iti\ARM\wifi_test2\system\include\arm" -I"D:\iti\ARM\wifi_test2\lib\esp8266driver" -I"D:\iti\ARM\wifi_test2\lib\MQTTPacket" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\portable\GCC\ARM_CM3" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


