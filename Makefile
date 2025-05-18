BUILD_DIR = build
CC = gcc
CFLAGS = -Wall -Wextra -O2

all:
	@echo "Usage: make file_name"

# Extract filename without extension
TARGET = $(BUILD_DIR)/$(basename $(MAKECMDGOALS))

# Rule to handle dynamic targets
$(BUILD_DIR)/%: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Create the build directory if it does not exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Phony target to clean the build directory
clean:
	rm -rf $(BUILD_DIR)

# Special handling to redirect "make file" to "make build/file"
%:
	make $(BUILD_DIR)/$(basename $@)

# Prevent make from complaining about unknown targets

.PHONY: all clean
