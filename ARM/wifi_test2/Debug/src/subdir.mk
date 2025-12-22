################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ESP8266Client.c \
../src/MQTTConnectClient.c \
../src/MQTTConnectServer.c \
../src/MQTTDeserializePublish.c \
../src/MQTTFormat.c \
../src/MQTTPacket.c \
../src/MQTTSerializePublish.c \
../src/MQTTSubscribeClient.c \
../src/MQTTSubscribeServer.c \
../src/MQTTUnsubscribeClient.c \
../src/MQTTUnsubscribeServer.c \
../src/_write.c \
../src/croutine.c \
../src/event_groups.c \
../src/heap_1.c \
../src/led.c \
../src/list.c \
../src/main.c \
../src/networkwrapper.c \
../src/port.c \
../src/queue.c \
../src/stream_buffer.c \
../src/tasks.c \
../src/temperature.c \
../src/timers.c \
../src/transport.c 

OBJS += \
./src/ESP8266Client.o \
./src/MQTTConnectClient.o \
./src/MQTTConnectServer.o \
./src/MQTTDeserializePublish.o \
./src/MQTTFormat.o \
./src/MQTTPacket.o \
./src/MQTTSerializePublish.o \
./src/MQTTSubscribeClient.o \
./src/MQTTSubscribeServer.o \
./src/MQTTUnsubscribeClient.o \
./src/MQTTUnsubscribeServer.o \
./src/_write.o \
./src/croutine.o \
./src/event_groups.o \
./src/heap_1.o \
./src/led.o \
./src/list.o \
./src/main.o \
./src/networkwrapper.o \
./src/port.o \
./src/queue.o \
./src/stream_buffer.o \
./src/tasks.o \
./src/temperature.o \
./src/timers.o \
./src/transport.o 

C_DEPS += \
./src/ESP8266Client.d \
./src/MQTTConnectClient.d \
./src/MQTTConnectServer.d \
./src/MQTTDeserializePublish.d \
./src/MQTTFormat.d \
./src/MQTTPacket.d \
./src/MQTTSerializePublish.d \
./src/MQTTSubscribeClient.d \
./src/MQTTSubscribeServer.d \
./src/MQTTUnsubscribeClient.d \
./src/MQTTUnsubscribeServer.d \
./src/_write.d \
./src/croutine.d \
./src/event_groups.d \
./src/heap_1.d \
./src/led.d \
./src/list.d \
./src/main.d \
./src/networkwrapper.d \
./src/port.d \
./src/queue.d \
./src/stream_buffer.d \
./src/tasks.d \
./src/temperature.d \
./src/timers.d \
./src/transport.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\diag" -I"D:\iti\ARM\wifi_test2\system\include\cortexm" -I"D:\iti\ARM\wifi_test2\system\include\cmsis" -I"D:\iti\ARM\wifi_test2\system\include\arm" -I"D:\iti\ARM\wifi_test2\lib\esp8266driver" -I"D:\iti\ARM\wifi_test2\lib\MQTTPacket" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\portable\GCC\ARM_CM3" -I"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -I"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


