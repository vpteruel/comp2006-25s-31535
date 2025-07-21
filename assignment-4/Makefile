CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC_DIR = src
DATA_DIR = data
OBJECTS = $(SRC_DIR)/main.o $(SRC_DIR)/menu_item.o

menu_app: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o menu_app $(OBJECTS)

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(SRC_DIR)/main.o

$(SRC_DIR)/menu_item.o: $(SRC_DIR)/menu_item.cpp $(SRC_DIR)/menu_item.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/menu_item.cpp -o $(SRC_DIR)/menu_item.o

clean:
	rm -f $(SRC_DIR)/*.o menu_app

run: menu_app
	./menu_app