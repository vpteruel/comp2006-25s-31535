#include "../include/library_item.h"

using namespace std;

LibraryItem::LibraryItem() : itemID(0) {}

LibraryItem::LibraryItem(const string& t, const string& a, int id) 
    : title(t), author(a), itemID(id) {}

LibraryItem::~LibraryItem() {}

string LibraryItem::getTitle() const { 
    return title; 
}

string LibraryItem::getAuthor() const { 
    return author; 
}

int LibraryItem::getItemID() const { 
    return itemID; 
}

void LibraryItem::setTitle(const string& t) { 
    title = t; 
}

void LibraryItem::setAuthor(const string& a) { 
    author = a; 
}

void LibraryItem::setItemID(int id) { 
    itemID = id; 
}

void LibraryItem::inputDetails() {
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author/creator: ";
    getline(cin, author);
    cout << "Enter item ID: ";
    cin >> itemID;
}