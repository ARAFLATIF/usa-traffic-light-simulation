# Traffic Light Simulation Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -Isrc
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O2

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BUILD_DIR = build

# Source files
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/traffic_light.c $(SRC_DIR)/simulation.c $(SRC_DIR)/user_interface.c $(SRC_DIR)/utils.c
TEST_TRAFFIC_LIGHT_SOURCES = $(TEST_DIR)/test_traffic_light.c $(SRC_DIR)/traffic_light.c $(SRC_DIR)/utils.c
TEST_SIMULATION_SOURCES = $(TEST_DIR)/test_simulation.c $(SRC_DIR)/traffic_light.c $(SRC_DIR)/simulation.c $(SRC_DIR)/utils.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Executable names
TARGET = traffic_sim
TEST_TRAFFIC_LIGHT = test_traffic_light
TEST_SIMULATION = test_simulation

# Default target
all: $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Main executable
$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $(BUILD_DIR)/$(TARGET) $(OBJECTS)
	@echo "Build complete: $(BUILD_DIR)/$(TARGET)"

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Individual object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test executables
test_traffic_light: $(TEST_TRAFFIC_LIGHT_SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TEST_TRAFFIC_LIGHT) $(TEST_TRAFFIC_LIGHT_SOURCES)
	@echo "Test build complete: $(BUILD_DIR)/$(TEST_TRAFFIC_LIGHT)"

test_simulation: $(TEST_SIMULATION_SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TEST_SIMULATION) $(TEST_SIMULATION_SOURCES)
	@echo "Test build complete: $(BUILD_DIR)/$(TEST_SIMULATION)"

# Run tests
test: test_traffic_light test_simulation
	@echo "Running traffic light tests..."
	./$(BUILD_DIR)/$(TEST_TRAFFIC_LIGHT)
	@echo "Running simulation tests..."
	./$(BUILD_DIR)/$(TEST_SIMULATION)

# Run the main program
run: $(TARGET)
	./$(BUILD_DIR)/$(TARGET)

# Clean build files
clean:
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o
	rm -rf $(BUILD_DIR)
	@echo "Cleaned build files"

# Install (copy to system directory - optional)
install: $(TARGET)
	cp $(BUILD_DIR)/$(TARGET) /usr/local/bin/

# Help
help:
	@echo "Available targets:"
	@echo "  all       - Build the main executable (default)"
	@echo "  debug     - Build with debug flags"
	@echo "  test      - Build and run all tests"
	@echo "  run       - Build and run the main program"
	@echo "  clean     - Remove all build files"
	@echo "  install   - Install to system directory"
	@echo "  help      - Show this help message"

.PHONY: all debug test run clean install help
