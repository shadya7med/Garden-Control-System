################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
Garden-Control-System.lss \

FLASH_IMAGE += \
Garden-Control-System.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Garden-Control-System.elf secondary-outputs

# Tool invocations
Garden-Control-System.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Garden-Control-System.map -mmcu=atmega32 -o "Garden-Control-System.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Garden-Control-System.lss: Garden-Control-System.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Garden-Control-System.elf  >"Garden-Control-System.lss"
	@echo 'Finished building: $@'
	@echo ' '

Garden-Control-System.hex: Garden-Control-System.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Garden-Control-System.elf  "Garden-Control-System.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Garden-Control-System.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Garden-Control-System.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Garden-Control-System.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
