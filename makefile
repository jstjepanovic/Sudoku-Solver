# Makefile

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall
LDFLAGS := -static

# Directories
SRC_DIR := src
HEADERS_DIR := headers
BUILD_DIR := build

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Executable
TARGET := $(BUILD_DIR)/program

# Build rules
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(HEADERS_DIR) -c -o $@ $<

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Phony targets
.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)