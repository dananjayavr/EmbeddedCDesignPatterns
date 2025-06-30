# Makefile to wrap CMake commands

# Variables
BUILD_DIR := build

# Default target
.PHONY: all
all:
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && cmake --build .

# Build the 'sensor' target
.PHONY: sensor
sensor:
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && cmake --build . --target sensor

# Build the 'queue' target
.PHONY: queue
queue:
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && cmake --build . --target queue

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Partial clean - run cmake clean target (preserves build files)
.PHONY: partial-clean
partial-clean:
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && cmake --build . --target clean