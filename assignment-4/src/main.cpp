#include <iostream>
#include <algorithm>
#include "menu_item.h"

using namespace std;

void displayCommandMenu();

int main() {
    cout << "Menu of the Day\n\n";

    // Load menu items from file
    vector<MenuItem> menuItems = loadMenuItems("data/menu.txt");

    if (menuItems.empty()) {
        cerr << "Error: Could not load menu items.\n";
        return 1;
    }
    
    displayCommandMenu();

    string dayInput;
    while (true) {
        cout << "\nDay: ";
        cin >> dayInput;

        // Convert input to lowercase
        transform(dayInput.begin(), dayInput.end(), dayInput.begin(), 
                      [](unsigned char c){ return tolower(c); });

        if (dayInput == "exit") {
            cout << "Bye!\n";
            break;
        }
        
        // Display menu items for the specified day
        displayMenuItemsForDay(menuItems, dayInput);
    }
    
    return 0;
}

void displayCommandMenu() {
    cout << "COMMAND MENU" << endl;
    cout << "Specify the day using the three-letter format (mon, tue, wed, thu, fri, sat, sun). "
         << "Or, enter 'exit' to exit." << endl;
}