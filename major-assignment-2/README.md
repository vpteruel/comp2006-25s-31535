# Library Management System

A C++ application for managing library items (books and DVDs) demonstrating object-oriented programming concepts.

## Project Structure

```
major-assignment-2
├── include
│   ├── book.h                # Book class header
│   ├── dvd.h                 # DVD class header
│   ├── library_item.h        # Base class header
│   └── library_system.h      # Library management class header
├── src                       # Source code files
│   ├── book.cpp              # Book class implementation
│   ├── dvd.cpp               # DVD class implementation
│   ├── library_item.cpp      # Base class implementation
│   ├── library_system.cpp    # Library management class implementation
│   └── main.cpp              # Main application entry point
├── .editorconfig             # Editor configuration for consistent coding style
├── .gitignore                # Define which files and folders to ignore (not track)
├── Makefile                  # Build configuration
└── README.md                 # Project documentation
```

## Features

- Object-oriented design demonstrating encapsulation, inheritance, polymorphism, and abstraction
- Add books with title, author, ID, and page count
- Add DVDs with title, creator, ID, and duration
- Display all books in the library
- Display all DVDs in the library
- Menu-driven user interface

## Building the Application

To compile the application, run:

```
make
```

This will create an executable called `library_management_system`

## Running the Application

To run the application:

```
./library_management_system
```

Or use the make run target:

```
make run
```

## OOP Concepts Demonstrated

- Encapsulation
  - Data members are protected/private
  - Access to data is controlled through getters and setters

- Inheritance
  - Book and DVD classes inherit from the LibraryItem base class
  - Common attributes and methods are defined in the base class

- Polymorphism
  - Virtual functions (displayDetails) are overridden in derived classes
  - Functions behave differently based on the object type

- Abstraction
  - LibraryItem is an abstract class with a pure virtual function
  - Complex operations are hidden within method implementations

## Usage

The menu-driven interface allows you to:

1. Add a new Book
2. Add a new DVD
3. Display all Books
4. Display all DVDs
5. Exit the program

Follow the on-screen prompts to input details for each library item.