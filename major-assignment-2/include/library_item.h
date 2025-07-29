#pragma once
#include <iostream>
#include <string>

using namespace std;

class LibraryItem {
protected:
    string title;
    string author;
    int itemID;

public:
    // Constructors
    LibraryItem();
    LibraryItem(const string& t, const string& a, int id);
    
    // Destructor
    virtual ~LibraryItem();
    
    // Getters
    string getTitle() const;
    string getAuthor() const;
    int getItemID() const;
    
    // Setters
    void setTitle(const string& t);
    void setAuthor(const string& a);
    void setItemID(int id);
    
    // Virtual functions
    virtual void inputDetails();
    virtual void displayDetails() const = 0;
};