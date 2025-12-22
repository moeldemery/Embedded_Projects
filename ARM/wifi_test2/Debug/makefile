################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/stm32f1-stdperiph/subdir.mk
-include src/newlib/subdir.mk
-include src/diag/subdir.mk
-include src/cortexm/subdir.mk
-include src/cmsis/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
wifi_test2.hex \

SECONDARY_SIZE += \
wifi_test2.siz \


# All Target
all: wifi_test2.elf secondary-outputs

# Tool invocations
wifi_test2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM GNU C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -T mem.ld -T libs.ld -T sections.ld -nostartfiles -Xlinker --gc-sections -L"../ldscripts" -L"D:\iti\ARM\wifi_test2\lib\c-circus" -L"D:\iti\ARM\wifi_test2\lib\esp8266driver" -L"D:\iti\ARM\wifi_test2\lib\FreeRTOS_Source" -L"D:\iti\ARM\wifi_test2\lib\mculibs" -L"D:\iti\ARM\wifi_test2\lib\MQTTPacket" -L"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -L"D:\iti\ARM\wifi_test2\system\include\stm32f1-stdperiph" -Wl,-Map,"wifi_test2.map" --specs=nano.specs -o "wifi_test2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

wifi_test2.hex: wifi_test2.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "wifi_test2.elf"  "wifi_test2.hex"
	@echo 'Finished building: $@'
	@echo ' '

wifi_test2.siz: wifi_test2.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "wifi_test2.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) wifi_test2.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
