CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = matrix_operations
SOURCES = main.cpp Matrix.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Matrix.h

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean


