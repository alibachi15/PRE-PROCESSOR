# PREPROCESSOR – Mini C Preprocessor

## About the Project

This project is a simple implementation of a C Preprocessor using C programming. It demonstrates how some of the basic preprocessing operations are performed before the actual compilation of a C program.

The project focuses on handling header file inclusion, removing comments and exploring macro processing.

## Features

- **File Inclusion:** Reads header files specified using `#include` and incorporates their contents into the output file.
- **Comment Removal:** Removes single-line (`//`) and multi-line (`/* */`) comments from the source file.
- **Macro Handling:** Includes an initial implementation of macro processing using structures and linked lists.
- **Output Generation:** Generates an intermediate `.i` file containing the processed source code.

## Technologies Used

- C Programming
- File Handling
- String Manipulation
- Dynamic Memory Allocation
- Structures and Linked Lists
- GCC Compiler

## Project Structure

```text
PREPROCESSOR/
│
├── preprocessor_main.c
├── file_inclusion.c
├── comment_removal_file.c
├── macro_handler.c
├── header.h
└── README.md
```

## Compilation

Compile the source files using GCC:

```bash
gcc preprocessor_main.c file_inclusion.c \
comment_removal_file.c macro_handler.c -o mypreprocessor
```

## How to Run

Execute the program by passing a C source file as a command-line argument.

```bash
./mypreprocessor input.c
```

After successful execution, the program generates an intermediate `.i` file.

## Learning Outcomes

Through this project, I explored:

- How a C preprocessor works.
- Handling files using C standard library functions.
- Reading and writing files.
- String processing and manipulation.
- Working with structures and linked lists.
- Passing command-line arguments in C.

## Author

**Muhammed Ali B**

Electronics and Communication Engineering  
Embedded Systems | C Programming | Linux

---

*This project was developed as part of my learning journey in C programming and embedded systems.*
