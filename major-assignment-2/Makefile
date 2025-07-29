CXX = g++
CXXFLAGS = -Wall -std=c++11 -I$(INCLUDE_DIR)
SRC_DIR = src
INCLUDE_DIR = include
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/library_item.cpp $(SRC_DIR)/book.cpp $(SRC_DIR)/dvd.cpp $(SRC_DIR)/library_system.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = library_management_system

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)