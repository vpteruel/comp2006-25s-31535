#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct MenuItem {
    string name;
    int price;
    string day;
};

// function declarations related to MenuItem
vector<MenuItem> loadMenuItems(const string& filename);
void displayMenuItemsForDay(const vector<MenuItem>& items, const string& day);

#endif // MENU_ITEM_H