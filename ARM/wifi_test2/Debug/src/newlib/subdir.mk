################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/newlib/_exit.c \
../src/newlib/_sbrk.c \
../src/newlib/_startup.c \
../src/newlib/_syscalls.c \
../src/newlib/assert.c 

CPP_SRCS += \
../src/newlib/_cxx.cpp 

OBJS += \
./src/newlib/_cxx.o \
./src/newlib/_exit.o \
./src/newlib/_sbrk.o \
./src/newlib/_startup.o \
./src/newlib/_syscalls.o \
./src/newlib/assert.o 

C_DEPS += \
./src/newlib/_exit.d \
./src/newlib/_sbrk.d \
./src/newlib/_startup.d \
./src/newlib/_syscalls.d \
./src/newlib/assert.d 

CPP_DEPS += \
./src/newlib/_cxx.d 


# Each subdirectory must supply rules for building sources it contributes
src/newlib/%.o: ../src/newlib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/newlib/%.o: ../src/newlib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\diag" -I"D:\iti\ARM\wifi_test2\system\include\cortexm" -I"D:\iti\ARM\wifi_test2\system\include\cmsis" -I"D:\iti\ARM\wifi_test2\system\include\arm" -I"D:\iti\ARM\wifi_test2\lib\esp8266driver" -I"D:\iti\ARM\wifi_test2\lib\MQTTPacket" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\portable\GCC\ARM_CM3" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


