#include "menu_item.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

vector<MenuItem> loadMenuItems(const string& filename) {
    vector<MenuItem> items;
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return items;
    }

    string line;
    while (getline(file, line)) {
        string name, day;
        int price;
        
        size_t firstTabPos = line.find('\t');
        if (firstTabPos == string::npos) continue;

        name = line.substr(0, firstTabPos);

        size_t secondTabPos = line.find('\t', firstTabPos + 1);
        if (secondTabPos == string::npos) continue;
        
        try {
            price = stoi(line.substr(firstTabPos + 1, secondTabPos - firstTabPos - 1));
        } catch (const exception& e) {
            continue; // skip lines with invalid price
        }
        
        day = line.substr(secondTabPos + 1);
        
        // remove any trailing whitespace or newlines from day
        day.erase(day.find_last_not_of(" \n\r\t") + 1);
        
        items.push_back({name, price, day});
    }
    
    file.close();
    return items;
}

void displayMenuItemsForDay(const vector<MenuItem>& items, const string& day) {
    bool found = false;
    
    for (const auto& item : items) {
        if (item.day == day) {
            cout << left << setw(30) << item.name 
                 << right << setw(5) << item.price << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No menu items available for " << day << "." << endl;
    }
}