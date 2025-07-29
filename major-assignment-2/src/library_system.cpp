#include "../include/library_system.h"

using namespace std;

LibrarySystem::LibrarySystem() : nextItemID(1001) {}

void LibrarySystem::addBook() {
    Book newBook;
    newBook.setItemID(nextItemID++);
    newBook.inputDetails();
    books.push_back(newBook);
    cout << "Book added successfully!" << endl;
}

void LibrarySystem::addDVD() {
    DVD newDVD;
    newDVD.setItemID(nextItemID++);
    newDVD.inputDetails();
    dvds.push_back(newDVD);
    cout << "DVD added successfully!" << endl;
}

void LibrarySystem::displayAllBooks() const {
    if (books.empty()) {
        cout << "No books in the library." << endl;
        return;
    }
    
    cout << "\n------ LIBRARY BOOKS ------" << endl;
    for (const auto& book : books) {
        book.displayDetails();
    }
}

void LibrarySystem::displayAllDVDs() const {
    if (dvds.empty()) {
        cout << "No DVDs in the library." << endl;
        return;
    }
    
    cout << "\n------ LIBRARY DVDs ------" << endl;
    for (const auto& dvd : dvds) {
        dvd.displayDetails();
    }
}