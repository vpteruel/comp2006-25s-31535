#include "record_manager.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "\nStudent Record Management System\n";
    cout << "1. Display all records\n";
    cout << "2. Add a new student\n";
    cout << "3. Update existing student\n";
    cout << "4. Delete student\n";
    cout << "5. Save and Exit\n";
    cout << "Choose an option: ";
}

int main() {
    const string filename = "data/records.txt";
    RecordManager manager(filename);
    
    // load records from file
    if (!manager.loadRecords()) {
        cout << "Creating new records file." << endl;
    }
    
    int choice;
    bool exit = false;
    
    while (!exit) {
        displayMenu();
        cin >> choice;
        
        // clear input buffer
        cin.ignore();
        
        switch (choice) {
            case 1:
                // display all records
                cout << "\n--- Student Records ---\n";
                manager.displayRecords();
                break;
                
            case 2:
                // add a new student
                manager.addStudent();
                break;
                
            case 3:
                // update existing student
                manager.updateStudent();
                break;
                
            case 4:
                // delete student
                manager.deleteStudent();
                break;
                
            case 5:
                // save and Exit
                if (manager.saveRecords()) {
                    cout << "Records saved successfully." << endl;
                } else {
                    cout << "Failed to save records." << endl;
                }
                exit = true;
                break;
                
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    
    return 0;
}