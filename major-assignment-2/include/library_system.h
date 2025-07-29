#pragma once
#include <vector>

#include "book.h"
#include "dvd.h"

using namespace std;

class LibrarySystem {
private:
    vector<Book> books;
    vector<DVD> dvds;
    int nextItemID;

public:
    LibrarySystem();
    
    void addBook();
    void addDVD();
    void displayAllBooks() const;
    void displayAllDVDs() const;
};