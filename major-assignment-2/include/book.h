#pragma once

#include "library_item.h"

using namespace std;

class Book : public LibraryItem {
private:
    int pageCount;

public:
    // Constructors
    Book();
    Book(const string& t, const string& a, int id, int pages);
    
    // Getters and Setters
    int getPageCount() const;
    void setPageCount(int pages);
    
    // Override virtual functions
    void inputDetails() override;
    void displayDetails() const override;
};