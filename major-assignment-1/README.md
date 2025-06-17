# Student Record Management System

A simple C++ application for managing student academic records.

## Project Structure

```
major-assignment-1
├── src                       # Source code files
│   ├── main.cpp              # Main application entry point
│   ├── student.h             # Student structure definition
│   ├── student.cpp           # Student functionality implementation
│   ├── record_manager.h      # Record management class definition
│   └── record_manager.cpp    # Record manager implementation
├── data                      # Data files directory
│   └── records.txt           # Student records storage
├── .editorconfig             # Editor configuration for consistent coding style
├── .gitignore                # Define which files and folders to ignore (not track)
├── Makefile                  # Build configuration
└── README.md                 # Project documentation
```

## Features

- Load and save student records from/to a text file
- Display all student records in a formatted table
- Add new students with ID, name, and scores
- Update existing student information
- Delete students by ID
- Automatically calculate average scores and letter grades

## Building the Application

To compile the application, run:

```
make
```

This will create an executable called `student_records`

## Running the Application

To run the application:

```
./student_records
```

Or use the make run target:

```
make run
```

The program will attempt to load existing records from `data/records.txt`.
If the file doesn't exist, it will be created when you save your changes.

## File Format

The application uses a simple CSV format for storing records:

```
ID,Name,Score1,Score2,Score3,...
```

For example:
```
1001,Alice Smith,85,88,82
1002,Bob Taylor,92,94,90
```

## Usage

Follow the on-screen menu to:
1. Display all student records
2. Add a new student
3. Update an existing student
4. Delete a student
5. Save changes and exit