#include <iostream>

#include "../include/library_system.h"

using namespace std;

int main() {
    LibrarySystem library;
    int choice;
    
    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add a new Book" << endl;
        cout << "2. Add a new DVD" << endl;
        cout << "3. Display all Books" << endl;
        cout << "4. Display all DVDs" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.addDVD();
                break;
            case 3:
                library.displayAllBooks();
                break;
            case 4:
                library.displayAllDVDs();
                break;
            case 5:
                cout << "Thank you for using the Library Management System!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}