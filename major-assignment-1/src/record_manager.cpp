#include "record_manager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

RecordManager::RecordManager(const string& file) : filename(file) {}

bool RecordManager::loadRecords() {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return false;
    }
    
    students.clear();
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        Student student;
        string score;
        
        // parse ID and name
        getline(ss, student.id, ',');
        getline(ss, student.name, ',');
        
        // parse scores
        while (getline(ss, score, ',')) {
            if (!score.empty()) {
                try {
                    float value = stof(score);
                    student.scores.push_back(value);
                } catch (const exception& e) {
                    cerr << "Error parsing score: " << score << endl;
                }
            }
        }
        
        // calculate average and grade
        student.recalculate();
        
        // add to vector
        students.push_back(student);
    }
    
    file.close();
    return true;
}

bool RecordManager::saveRecords() {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file for writing: " << filename << endl;
        return false;
    }
    
    for (const Student& student : students) {
        file << student.id << "," << student.name;
        
        for (float score : student.scores) {
            file << "," << score;
        }
        
        file << endl;
    }
    
    file.close();
    return true;
}

void RecordManager::displayRecords() {
    cout << left << setw(10) << "ID"
              << setw(25) << "Name"
              << setw(10) << "Average"
              << "Grade" << endl;
    cout << "--------------------------------------------------" << endl;
    
    for (const Student& student : students) {
        cout << left << setw(10) << student.id
                  << setw(25) << student.name
                  << fixed << setprecision(1) << setw(10) << student.average
                  << student.grade << endl;
    }
    
    if (students.empty()) {
        cout << "No records found." << endl;
    }
}

bool RecordManager::addStudent() {
    Student student;
    
    // get student ID
    do {
        cout << "Enter student ID: ";
        cin >> student.id;
        
        if (idExists(student.id)) {
            cout << "ID already exists. Please enter a unique ID." << endl;
        }
    } while (idExists(student.id));
    
    // clear input buffer
    cin.ignore();
    
    // get name
    cout << "Enter student name: ";
    getline(cin, student.name);
    
    // get scores
    int numScores;
    cout << "How many scores to enter (minimum 3): ";
    cin >> numScores;
    
    if (numScores < 3) {
        numScores = 3;
        cout << "Minimum 3 scores required. Will collect 3 scores." << endl;
    }
    
    for (int i = 0; i < numScores; i++) {
        float score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        student.scores.push_back(score);
    }
    
    // galculate average and grade
    student.recalculate();
    
    // add to vector
    students.push_back(student);
    
    cout << "Student added successfully." << endl;
    return true;
}

int RecordManager::findStudentIndex(const string& id) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool RecordManager::updateStudent() {
    string id;
    cout << "Enter student ID to update: ";
    cin >> id;
    
    int index = findStudentIndex(id);
    if (index == -1) {
        cout << "Student not found with ID: " << id << endl;
        return false;
    }
    
    Student& student = students[index];
    
    // clear input buffer
    cin.ignore();
    
    // update name
    cout << "Enter new name (current: " << student.name << "): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty()) {
        student.name = newName;
    }
    
    // update scores
    char updateScores;
    cout << "Update scores? (y/n): ";
    cin >> updateScores;
    
    if (updateScores == 'y' || updateScores == 'Y') {
        student.scores.clear();
        
        int numScores;
        cout << "How many scores to enter (minimum 3): ";
        cin >> numScores;
        
        if (numScores < 3) {
            numScores = 3;
            cout << "Minimum 3 scores required. Will collect 3 scores." << endl;
        }
        
        for (int i = 0; i < numScores; i++) {
            float score;
            cout << "Enter score " << (i + 1) << ": ";
            cin >> score;
            student.scores.push_back(score);
        }
        
        // recalculate average and grade
        student.recalculate();
    }
    
    cout << "Student record updated successfully." << endl;
    return true;
}

bool RecordManager::deleteStudent() {
    string id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    
    int index = findStudentIndex(id);
    if (index == -1) {
        cout << "Student not found with ID: " << id << endl;
        return false;
    }
    
    students.erase(students.begin() + index);
    cout << "Student deleted successfully." << endl;
    return true;
}

bool RecordManager::idExists(const string& id) {
    return findStudentIndex(id) != -1;
}