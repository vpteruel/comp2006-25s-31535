#ifndef RECORD_MANAGER_H
#define RECORD_MANAGER_H

#include "student.h"
#include <vector>
#include <string>

using namespace std;

class RecordManager {
private:
    vector<Student> students;
    string filename;
    
    // helper function to find student by ID
    int findStudentIndex(const string& id);

public:
    // constructor with filename
    RecordManager(const string& file);
    
    // load records from file
    bool loadRecords();
    
    // save records to file
    bool saveRecords();
    
    // display all student records
    void displayRecords();
    
    // add a new student
    bool addStudent();
    
    // update existing student
    bool updateStudent();
    
    // delete student
    bool deleteStudent();
    
    // check if student ID exists
    bool idExists(const string& id);
};

#endif // RECORD_MANAGER_H