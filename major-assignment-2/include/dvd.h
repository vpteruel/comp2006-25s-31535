#pragma once

#include "library_item.h"

using namespace std;

class DVD : public LibraryItem {
private:
    float duration; // in minutes

public:
    // Constructors
    DVD();
    DVD(const string& t, const string& a, int id, float dur);
    
    // Getters and Setters
    float getDuration() const;
    void setDuration(float dur);
    
    // Override virtual functions
    void inputDetails() override;
    void displayDetails() const override;
};