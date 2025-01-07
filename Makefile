# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SRC = src/main.cpp src/editor.cpp src/text_buffer.cpp src/inputhandler.cpp

# Object files (automatically generated from source files)
OBJ = $(SRC:.cpp=.o)

# Target executable
TARGET = gatto

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET) debug
