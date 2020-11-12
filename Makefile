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
# Make file to compile en two platforms, the host and MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#     
#      compile-all - Compiles all sources files but do not link 
#      build - Builds all the objects files
#      clean - Remove all the generated files
#
# Platform Overrides:
#      HOST - The host environment
#      MSP342 - The target enbedded system
#
#
# Author: Gonzales Loayza Pool Diego
# Date: 11/11/2020
#    
#------------------------------------------------------------------------------
include sources.mk

ifeq ($(PLATFORM),MSP432)
		CC = arm-none-eabi-gcc
		LD = arm-none-eabi-ld
		LINKER_FILE = msp432p401r.lds
		LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

		CPU = cortex-m4
		ARCH = thumb
		SPECS = nosys.specs
		FPU = fpv4-sp-d16
		ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=$(FPU)		
		OBJDUMP = arm-none-eabi-objdump

		SIZE = arm-none-eabi-size 
else
		CC = gcc
		LD = ld

		SIZE = size
		LDFLAGS = -Wl,-Map=$(TARGET).map
		OBJDUMP = objdump
endif

VPATH = ./src
 
ifeq ($(VERBOSE),VERBOSE)
	VER = -g
endif

TARGET = final
CFLAGS = -Wall -Werror $(VER) -O0 -std=c99 $(INCLUDEHEADER) -D$(PLATFORM) $(ARMFLAGS) -D$(VERBOSE) -D$(COURSE1)
CPPFLAGS = -E
MAIN = main

OBJS = $(SOURCES:.c=.o)
PREPRO = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)
FILES = *.asm *.i *.o *.d

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(TARGET).out  

$(TARGET).out: $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)

.PHONY: clean
clean:
	rm -f $(TARGET).asm $(FILES) $(TARGET).out $(TARGET).map $(PREPRO) $(ASMS) $(DEPS) $(OBJS)