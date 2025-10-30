# Compilers
WCC := i686-w64-mingw32-g++
LCC := clang++

# Common flags
FLAGS := -Wall -static

# Source files
SOURCES := $(wildcard *.cpp)

# Build directory
BUILD_DIR := build

# Output names
OUT_LINUX := $(BUILD_DIR)/stack
OUT_WINDOWS := $(BUILD_DIR)/stack.exe

# Default target
all: linux windows

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build Linux version
linux: $(BUILD_DIR)
	$(LCC) $(FLAGS) $(SOURCES) -o $(OUT_LINUX)
	@echo "✅ Compiled for Linux -> $(OUT_LINUX)"

# Build Windows version
windows: $(BUILD_DIR)
	$(WCC) $(FLAGS) $(SOURCES) -o $(OUT_WINDOWS)
	@echo "✅ Compiled for Windows -> $(OUT_WINDOWS)"

# Clean up
clean:
	rm -rf $(BUILD_DIR)

