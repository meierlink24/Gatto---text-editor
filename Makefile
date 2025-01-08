# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g -Iinclude

# Source files and targets
SRC = src/main.cpp src/editor.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = GATTO

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
