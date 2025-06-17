#include "student.h"
#include <numeric>

using namespace std;

void Student::calculateAverage() {
    if (scores.empty()) {
        average = 0.0f;
        return;
    }
    
    float sum = accumulate(scores.begin(), scores.end(), 0.0f);
    average = sum / static_cast<float>(scores.size());
}

void Student::calculateGrade() {
    if (average >= 90.0f) {
        grade = 'A';
    } else if (average >= 80.0f) {
        grade = 'B';
    } else if (average >= 70.0f) {
        grade = 'C';
    } else if (average >= 60.0f) {
        grade = 'D';
    } else {
        grade = 'F';
    }
}

void Student::recalculate() {
    calculateAverage();
    calculateGrade();
}