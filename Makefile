# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -O2

# Folders
SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := obj

# Output binary name
TARGET := $(BIN_DIR)/app

# Find all C source files
SRCS := $(wildcard $(SRC_DIR)/*.c)
# Replace .c with .o in a build folder
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default rule
all: $(TARGET)

# Link objects into the final binary
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create bin directory if missing
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Create obj directory if missing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build files
clean:
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run