# Makefile

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall

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
$(TARGET): $(OBJS) | create_build_directory
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | create_build_directory
	$(CXX) $(CXXFLAGS) -I$(HEADERS_DIR) -c -o $@ $<

# Phony targets
.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)

create_build_directory:
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)