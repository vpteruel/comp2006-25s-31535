#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

struct Student {
    string id;
    string name;
    vector<float> scores;
    float average;
    char grade;

    // calculate average from scores vector
    void calculateAverage();
    
    // determine letter grade based on average
    void calculateGrade();
    
    // recalculate both average and grade
    void recalculate();
};

#endif // STUDENT_H