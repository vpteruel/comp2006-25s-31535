#include "../include/card.h"

using namespace std;

Card::Card(const string& rank, const string& suit)
    : rank(rank), suit(suit) {}

string Card::toString() const {
    return rank + " of " + suit;
}

string Card::getRank() const {
    return rank;
}

string Card::getSuit() const {
    return suit;
}