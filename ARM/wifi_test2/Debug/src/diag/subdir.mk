################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/diag/Trace.c \
../src/diag/trace_impl.c 

OBJS += \
./src/diag/Trace.o \
./src/diag/trace_impl.o 

C_DEPS += \
./src/diag/Trace.d \
./src/diag/trace_impl.d 


# Each subdirectory must supply rules for building sources it contributes
src/diag/%.o: ../src/diag/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\diag" -I"D:\iti\ARM\wifi_test2\system\include\cortexm" -I"D:\iti\ARM\wifi_test2\system\include\cmsis" -I"D:\iti\ARM\wifi_test2\system\include\arm" -I"D:\iti\ARM\wifi_test2\lib\esp8266driver" -I"D:\iti\ARM\wifi_test2\lib\MQTTPacket" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\portable\GCC\ARM_CM3" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


