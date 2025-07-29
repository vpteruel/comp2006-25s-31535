#include "../include/dvd.h"

using namespace std;

DVD::DVD() : duration(0.0) {}

DVD::DVD(const string& t, const string& a, int id, float dur) 
    : LibraryItem(t, a, id), duration(dur) {}

float DVD::getDuration() const { 
    return duration; 
}

void DVD::setDuration(float dur) { 
    duration = dur; 
}

void DVD::inputDetails() {
    LibraryItem::inputDetails();
    cout << "Enter duration (in minutes): ";
    cin >> duration;
}

void DVD::displayDetails() const {
    cout << "\n===== DVD DETAILS =====" << endl;
    cout << "ID: " << itemID << endl;
    cout << "Title: " << title << endl;
    cout << "Director/Creator: " << author << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "=======================" << endl;
}