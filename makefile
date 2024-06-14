# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable
TARGET = my_program

# Source files
SRCS = main.cpp LoadBalancer.cpp Request.cpp Server.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
DEPS = LoadBalancer.h Server.h

# Default target
all: $(TARGET)

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
