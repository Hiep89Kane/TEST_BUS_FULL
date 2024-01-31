################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32G0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/TIMER/subdir.mk
-include Core/Src/TEST_BUS/subdir.mk
-include Core/Src/OUTPUT_CONTROL/subdir.mk
-include Core/Src/LCD_i2c/subdir.mk
-include Core/Src/INTERRUPT/subdir.mk
-include Core/Src/INIT/subdir.mk
-include Core/Src/HC595/subdir.mk
-include Core/Src/FLASH/subdir.mk
-include Core/Src/FIFO/subdir.mk
-include Core/Src/COMMON/subdir.mk
-include Core/Src/CB_BUTTON/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := TEST_BUS_FULL
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
TEST_BUS_FULL.elf \

MAP_FILES += \
TEST_BUS_FULL.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
TEST_BUS_FULL.list \

OBJCOPY_HEX += \
TEST_BUS_FULL.hex \


# All Target
all: main-build

# Main-build Target
main-build: TEST_BUS_FULL.elf secondary-outputs

# Tool invocations
TEST_BUS_FULL.elf TEST_BUS_FULL.map: $(OBJS) $(USER_OBJS) D:\1_NGUYEN_VAN_HIEP\25_STM32CubeIDE_Workspace\TEST_BUS_FULL\STM32G070RBTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "TEST_BUS_FULL.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"D:\1_NGUYEN_VAN_HIEP\25_STM32CubeIDE_Workspace\TEST_BUS_FULL\STM32G070RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="TEST_BUS_FULL.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

TEST_BUS_FULL.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "TEST_BUS_FULL.list"
	@echo 'Finished building: $@'
	@echo ' '

TEST_BUS_FULL.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "TEST_BUS_FULL.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) TEST_BUS_FULL.elf TEST_BUS_FULL.hex TEST_BUS_FULL.list TEST_BUS_FULL.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
