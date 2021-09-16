PROJECT_NAME := CaseStudy
SRC_DIR := src
INC_DIRS := inc
BUILD_DIR := build

SRC := src/activity1.c\ 
src/activity2.c\ 
src/activity3.c\ 
main.c\ 

INC := -I inc

ifdef OBJ
	FixPath = $(subst /,\,$1)
	CC := avr-gcc.exe
	AVR_OBJ_CPY = avr-objcopy.exe

else
	ifeq ($(shell uname), Linux)
		FixPath = $1
		CC = avr-gcc
		AVR_OBJ_CPY = avr-objcopy
	endif
endif

.PHONY: all analysis clean doc

all: $(BUILD_DIR)
	$(CC) -g -Wall -Os -mmcu=atmega328 -DF_CPU=16000000UL  $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

analysis: $(SRC)
	cppcheck --enable=all $^

doc:
	make -C documentation

clean:
	rm -rf $(call FixPath,$(BUILD_DIR)/*)
	make -C documentation clean