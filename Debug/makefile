################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/SPI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KAYPAD/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SENSOR_PROJ.lss \

FLASH_IMAGE += \
SENSOR_PROJ.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SENSOR_PROJ.elf secondary-outputs

# Tool invocations
SENSOR_PROJ.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SENSOR_PROJ.map -mmcu=atmega32 -o "SENSOR_PROJ.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SENSOR_PROJ.lss: SENSOR_PROJ.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SENSOR_PROJ.elf  >"SENSOR_PROJ.lss"
	@echo 'Finished building: $@'
	@echo ' '

SENSOR_PROJ.hex: SENSOR_PROJ.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SENSOR_PROJ.elf  "SENSOR_PROJ.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SENSOR_PROJ.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SENSOR_PROJ.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SENSOR_PROJ.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
