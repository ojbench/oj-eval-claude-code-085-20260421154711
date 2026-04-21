CXX := g++
CXXFLAGS := -std=gnu++17 -O2 -pipe -Wall -Wextra -Wno-unused-parameter
LDFLAGS :=
TARGET := code
SRC := code.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)
