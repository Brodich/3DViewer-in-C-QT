MKFILE_PATH := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
TARGET_DIR  := $(MKFILE_PATH)/build
TARGET      := $(TARGET_DIR)/3DViewer
SRC_DIR     := $(MKFILE_PATH)
SRC_STRIPPED:= back/parser.c 
SRC         := $(SRC_DIR)/$(SRC_STRIPPED)
CFLAGS      := --debug -Wall -Wextra -g


ifeq ($(OS), Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
	INSTALL_OS = ./viewer
else
	FLAGS = -lcheck -lm
	INSTALL_OS = viewer.app/Contents/MacOS/viewer
endif


all: clang install 
	-@mkdir $(TARGET_DIR)
	gcc $(SRC) $(CFLAGS) -o $(TARGET)
	build/3DViewer
# run:


%.o: %.c
	$(CC) -c -o $@ $<


info:
	@echo -e "MKFILE_PATH := $(MKFILE_PATH)"
	@echo -e "TARGET_DIR  := $(TARGET_DIR)"
	@echo -e "TARGET      := $(TARGET)"
	@echo -e "SRC_DIR     := $(SRC_DIR)"
	@echo -e "SRC         := $(SRC)"
	@echo -e "CFLAGS      := $(CFLAGS)"

run:
	cd build && \
	$(INSTALL_OS)

install:
	-@mkdir build 
	cd build && \
	cmake .. && \
	make && \
	unset GTK_PATH && \
	$(INSTALL_OS)

uninstall:
	rm -rf build/ *.tar.gz


clang:
	clang-format -style=google -i front/*.cpp front/*.h
	clang-format -style=google -i back/*.c back/*.h
