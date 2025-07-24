# Card Dealer Program

A C++ object-oriented application that creates, shuffles, and deals cards from a standard deck.

## Project Structure

```bash
assignment-5
├── include                 # Header files directory
│   ├── card.h              # Card class definition
│   └── deck.h              # Deck class definition
├── src                     # Source code files
│   ├── main.cpp            # Main application entry point
│   ├── card.cpp            # Card class implementation
│   └── deck.cpp            # Deck class implementation
├── Makefile                # Build configuration
└── README.md               # Project documentation
```

## Features

- Object-oriented design with Card and Deck classes
- Standard 52-card deck (4 suits × 13 ranks)
- Deck shuffling functionality
- Card dealing with proper tracking of remaining cards
- User-friendly command interface

## Building the Application

To compile the application, run:

```bash
g++ -o card_dealer src/main.cpp src/Card.cpp src/Deck.cpp -Iinclude
```

Or if you have a Makefile:

```bash
make
```

This will create an executable called `card_dealer`

## Running the Application

To run the application:

```bash
./card_dealer
```

Or use the make run target:

```bash
make run
```

## Class Structure

### Card Class
- Stores rank and suit for each card
- Provides string representation (e.g., "Ace of Spades")
- Getter methods for rank and suit

### Deck Class
- Creates a standard 52-card deck
- Shuffles cards using random algorithm
- Tracks number of remaining cards
- Deals cards from the deck

## Usage

When you run the application:

1. The program creates and shuffles a standard 52-card deck
2. You'll be prompted for the number of cards you want to be dealt
3. The program displays your cards and reports how many remain in the deck

Example output:
```
Card Dealer

I have shuffled a deck of 52 cards.

How many cards would you like?: 7

Here are your cards:
Jack of Hearts
Jack of Diamonds
2 of Diamonds
6 of Spades
Jack of Spades
6 of Hearts
King of Diamonds

There are 45 cards left in the deck.

Good luck!
```