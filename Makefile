# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Name of the final executable
TARGET = parkingSystem

# Automatically find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)

# Generate a list of .o files based on the found .cpp files
OBJS = $(SRCS:.cpp=.o)

# Default target: build the executable
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	-del /Q /F $(subset /,\,$(OBJS)) $(TARGET).exe

.PHONY: all clean