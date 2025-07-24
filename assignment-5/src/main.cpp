#include <iostream>
#include <vector>
#include <limits>
#include "../include/card.h"
#include "../include/deck.h"

using namespace std;

int main() {
    cout << "Card Dealer\n\n";

    // Create and shuffle a new deck
    Deck deck;
    deck.shuffle();

    cout << "I have shuffled a deck of " << deck.getCardCount() << " cards.\n\n";
    
    // Ask the user how many cards they want
    int numCards;
    bool validInput = false;
    do {
        cout << "How many cards would you like?: ";
        cin >> numCards;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
        } else if (numCards <= 0) {
            cout << "Please enter a positive number.\n";
        } else if (numCards > deck.getCardCount()) {
            cout << "There are only " << deck.getCardCount() << " cards in the deck.\n";
        } else {
            validInput = true;
        }
    } while (!validInput);

    cout << "\nHere are your cards:\n";

    // Deal and display the cards
    vector<Card> dealtCards;
    for (int i = 0; i < numCards; i++) {
        Card card = deck.dealCard();
        dealtCards.push_back(card);
        cout << card.toString() << endl;
    }
    
    // Display remaining cards
    cout << "\nThere are " << deck.getCardCount() << " cards left in the deck.\n\n";
    cout << "Good luck!\n";
    
    return 0;
}