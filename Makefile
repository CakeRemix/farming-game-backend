CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I include
TARGET   := AgriTopia
BUILD    := build
SRCDIR   := src

SRCS     := $(SRCDIR)/main.cpp $(SRCDIR)/plant.cpp $(SRCDIR)/game.cpp
OBJS     := $(patsubst $(SRCDIR)/%.cpp, $(BUILD)/%.o, $(SRCS))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD)/%.o: $(SRCDIR)/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD):
	mkdir -p $(BUILD)

run: all
	./$(TARGET)

clean:
	rm -rf $(BUILD) $(TARGET)
