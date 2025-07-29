#include "../include/book.h"

using namespace std;

Book::Book() : pageCount(0) {}

Book::Book(const string& t, const string& a, int id, int pages) 
    : LibraryItem(t, a, id), pageCount(pages) {}

int Book::getPageCount() const { 
    return pageCount; 
}

void Book::setPageCount(int pages) { 
    pageCount = pages; 
}

void Book::inputDetails() {
    LibraryItem::inputDetails();
    cout << "Enter number of pages: ";
    cin >> pageCount;
}

void Book::displayDetails() const {
    cout << "\n===== BOOK DETAILS =====" << endl;
    cout << "ID: " << itemID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Page Count: " << pageCount << endl;
    cout << "=========================" << endl;
}