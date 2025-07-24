#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>
#include "../include/deck.h"

using namespace std;

Deck::Deck() {
    // initialize a standard 52-card deck
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            cards.emplace_back(rank, suit);
        }
    }
}

void Deck::shuffle() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), default_random_engine(seed));
}

int Deck::getCardCount() const {
    return cards.size();
}

Card Deck::dealCard() {
    if (cards.empty()) {
        throw runtime_error("No cards left in the deck!");
    }
    
    Card dealtCard = cards.back();
    cards.pop_back();
    return dealtCard;
}