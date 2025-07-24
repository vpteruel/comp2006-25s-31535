#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
private:
    string rank;
    string suit;

public:
    Card(const string& rank, const string& suit);
    string toString() const;
    
    string getRank() const;
    string getSuit() const;
};

#endif // CARD_H