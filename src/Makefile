MKFILE_PATH := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
TARGET_DIR  := $(MKFILE_PATH)/build
TARGET      := $(TARGET_DIR)/3DViewer
SRC_DIR     := $(MKFILE_PATH)
SRC_STRIPPED:= back/parser.c 
SRC         := $(SRC_DIR)/$(SRC_STRIPPED)
CFLAGS      := --debug -Wall -Wextra

all: info
	-@mkdir $(TARGET_DIR)
	gcc $(SRC) $(CFLAGS) -o $(TARGET)
	build/3DViewer
# run:
	

info:
	@echo -e "MKFILE_PATH := $(MKFILE_PATH)"
	@echo -e "TARGET_DIR  := $(TARGET_DIR)"
	@echo -e "TARGET      := $(TARGET)"
	@echo -e "SRC_DIR     := $(SRC_DIR)"
	@echo -e "SRC         := $(SRC)"
	@echo -e "CFLAGS      := $(CFLAGS)"

