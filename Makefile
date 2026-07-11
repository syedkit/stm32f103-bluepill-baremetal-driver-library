###############################################################################
# Project
###############################################################################

TARGET = led_blink

###############################################################################
# Toolchain
###############################################################################

CC      = arm-none-eabi-gcc
AS      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

###############################################################################
# Directories
###############################################################################

BUILD_DIR = Build

INCLUDES = \
-I./Drivers/Inc

C_SOURCES = \
./Drivers/Src/gpio.c \
./examples/led_blink/main.c

ASM_SOURCES = \
./Startup/startup_stm32f103c8t6.s

LDSCRIPT = ./Linker/linker.ld

###############################################################################
# Compiler Flags
###############################################################################

CFLAGS = \
-mcpu=cortex-m3 \
-mthumb \
-Wall \
-O0 \
-g \
$(INCLUDES)

LDFLAGS = \
-T$(LDSCRIPT) \
-nostartfiles \
-Wl,-Map=$(BUILD_DIR)/$(TARGET).map

###############################################################################
# Build Rules
###############################################################################

all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET).elf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET).elf: $(C_SOURCES) $(ASM_SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) \
	$(C_SOURCES) \
	$(ASM_SOURCES) \
	-o $@

	$(SIZE) $@

	$(OBJCOPY) -O binary $@ $(BUILD_DIR)/$(TARGET).bin

clean:
	rm -rf $(BUILD_DIR)
