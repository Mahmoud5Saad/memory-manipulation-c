#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 	  <FILE>.i - Builds <FILE>.i preprocessed file
#	  <FILE>.asm - Builds <FILE>.asm assembly file
#	  <FILE>.o - Builds <FILE>.o object file
#	  compile-all - compiles all object files stopping at linking stage
#	  build - Builds and links all files, also generate .map file
#	  clean - clears the files generated
#
#
# Platform Overrides:
#      HOST = linux OS
#      MSP432 = TI ARM target platform
#
#------------------------------------------------------------------------------
include sources.mk

# Platform deafult to HOST

OBJS = $(SOURCES_BOTH:.c=.o)
CPPFLAGS = -DHOST
CC = gcc
LD = ld
DUMP = objdump
SIZE = size

# Platform Overrides

ifeq ($(PLATFORM),MSP432)

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
CPPFLAGS = -DMSP432
LDFLAGS_ARCH = -T $(LINKER_FILE)
CFLAGS_ARCH = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
OBJS = $(SOURCES:.c=.o)
DUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size
# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
endif

ifeq ($(PLATFORM),HOST)
OBJS = $(SOURCES_BOTH:.c=.o)
CPPFLAGS = -DHOST
CC = gcc
LD = ld
DUMP = objdump
SIZE = size
endif

ifeq ($(COURSE1), 1)
SPES1_FLAGS += -DCOURSE1
endif

ifeq ($(DEBUG), 1)
SPES2_FLAGS += -DVERBOSE
endif

TARGET = c1m4
LDFLAGS = -Wl,-Map=$(TARGET).map $(LDFLAGS_ARCH)
CFLAGS = $(CFLAGS_ARCH) $(INCLUDES) $(SPES1_FLAGS) $(SPES2_FLAGS)  -Wall -Werror -g -O0  -std=c99 $(CPPFLAGS)
 


.PHONY: build
build: $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: clean
clean:
	# clean compile files
	$(RM) ./src/*.i ./src/*.s ./src/*.asm ./src/*.o ./src/*.dep *.out *.map *.asm

#%.o : %.c

#	$(CC) -c $< $(CFLAGS) -o $@

%.o : %.c
	# dep generation
	$(CC) $(CFLAGS) -MM $< > $<.dep
	# compilation 
	$(CC) -c $< $(CFLAGS) -o $@


%.i : %.c
	$(CC) -E $< $(CFLAGS) -o $@

%.asm :  %.o
	$(DUMP) -S --disassemble $< > $@

%.asm : %.out
	$(DUMP) -S --disassemble $< > $@

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
