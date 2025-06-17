CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC_DIR = src
DATA_DIR = data
OBJECTS = $(SRC_DIR)/main.o $(SRC_DIR)/student.o $(SRC_DIR)/record_manager.o

student_records: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o student_records $(OBJECTS)

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/record_manager.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(SRC_DIR)/main.o

$(SRC_DIR)/student.o: $(SRC_DIR)/student.cpp $(SRC_DIR)/student.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/student.cpp -o $(SRC_DIR)/student.o

$(SRC_DIR)/record_manager.o: $(SRC_DIR)/record_manager.cpp $(SRC_DIR)/record_manager.h $(SRC_DIR)/student.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/record_manager.cpp -o $(SRC_DIR)/record_manager.o

clean:
	rm -f $(SRC_DIR)/*.o student_records

run: student_records
	./student_records