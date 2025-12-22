################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cmsis/system_stm32f10x.c \
../src/cmsis/vectors_stm32f10x.c 

OBJS += \
./src/cmsis/system_stm32f10x.o \
./src/cmsis/vectors_stm32f10x.o 

C_DEPS += \
./src/cmsis/system_stm32f10x.d \
./src/cmsis/vectors_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
src/cmsis/%.o: ../src/cmsis/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\diag" -I"D:\iti\ARM\wifi_test2\system\include\cortexm" -I"D:\iti\ARM\wifi_test2\system\include\cmsis" -I"D:\iti\ARM\wifi_test2\system\include\arm" -I"D:\iti\ARM\wifi_test2\lib\esp8266driver" -I"D:\iti\ARM\wifi_test2\lib\MQTTPacket" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\portable\GCC\ARM_CM3" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


