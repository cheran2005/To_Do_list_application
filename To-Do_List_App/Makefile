# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude     

# Source and object files
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, build/%.o, $(SRC))
TARGET = to_do

# Default build target
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile .c files to .o files
build/%.o: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf build $(TARGET)