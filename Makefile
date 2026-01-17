CXX ?= c++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

TARGET := describe_object
SRCS := main.cpp object.cpp shapes.cpp
BUILD := build
OBJS := $(SRCS:%.cpp=$(BUILD)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD)/%.o: %.cpp
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD) $(TARGET)
