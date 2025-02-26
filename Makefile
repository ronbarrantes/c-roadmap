BUILD_DIR = build
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Default target
all: 

# Extract filename without extension
TARGET = $(BUILD_DIR)/$(basename $(MAKECMDGOALS))

# Pattern rule to compile C files
$(BUILD_DIR)/%: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Create the build directory if it does not exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Phony target to clean the build directory
clean:
	rm -rf $(BUILD_DIR)

hello: 
	@echo "hello world"

# Prevent make from complaining about unknown targets
.PHONY: all clean
