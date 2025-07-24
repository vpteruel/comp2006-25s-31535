#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

using namespace std;

class Deck {
private:
    vector<Card> cards;

public:
    Deck();
    void shuffle();
    int getCardCount() const;
    Card dealCard();
};

#endif // DECK_H