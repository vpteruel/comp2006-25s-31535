# Menu of the Day Program

A simple C++ application for displaying daily menu items based on user input.

## Project Structure

```bash
assignment-4
├── data                    # Data files directory
│   └── menu.txt            # Menu items storage in tab-delimited format
├── src                     # Source code files
│   ├── main.cpp            # Main application entry point
│   ├── menu_item.cpp       # MenuItem functionality implementation
│   └── menu_item.h         # MenuItem structure definition
├── Makefile                # Build configuration
└── README.md               # Project documentation
```

## Features

- Load menu items from a tab-delimited text file
- Display menu items filtered by day
- User-friendly command interface
- Properly formatted item display with name and price alignment

## Building the Application

To compile the application, run:

```bash
g++ -o menu_app src/main.cpp src/menu_item.cpp -Isrc
```

Or if you have a Makefile:

```bash
make
```

This will create an executable called `menu_app`

## Running the Application

To run the application:

```bash
./menu_app
```

Or use the make run target:

```bash
make run
```

The program will attempt to load menu items from `data/menu.txt`.

## File Format

The application uses a tab-delimited format for storing menu items:

```
Name    Price   Day
```

For example:
```
Roast beef  10  mon
Potato soup 6   mon
Baked cod   10  mon
```

## Usage

When you run the application:

1. Enter a three-letter day code (mon, tue, wed, thu, fri, sat, sun) to see the menu for that day
2. Type "exit" to quit the program

Each menu item will be displayed with its name and price formatted in columns.