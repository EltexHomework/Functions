# Compiler and flags
CC := gcc
CFLAGS := -Wall -Werror -O2 -I$(SRC_DIR)/headers

# Directories
SRC_DIR := src
BIN_DIR := bin

# Source files and corresponding object files
SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SOURCES))

# Default target
all: $(BIN_DIR) $(BIN_DIR)/main

# Rule to create bin directory
$(BIN_DIR):
	@mkdir -p $@

# Rule to compile each source file to an object file
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create the final executable
$(BIN_DIR)/main: $(OBJECTS)
	@echo "Linking $@"
	@$(CC) $(OBJECTS) -o $@

# Clean target to remove binaries and object files
clean:
	@echo "Cleaning up..."
	@rm -rf $(BIN_DIR)

.PHONY: all clean
