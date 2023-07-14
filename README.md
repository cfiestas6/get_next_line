# Project Name: get_next_line

This project is part of the curriculum at 42 School and is written in the C programming language. This projects is about creating a function that, allows to read a line ending with a newline character ('\n') from a file descriptor, without knowing its size beforehand. 

## Table of Contents

- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Project Structure](#project-structure)

## Introduction

One of the goal of this project is to learn a highly interesting new concept in C programming: static variables, and to gain a deeper understanding of allocations, whether they happen on the stack memory or in the heap memory, the manipulation and the life cycle of a buffer, the unexpected complexity implied in the use of one or many static variables.
## Prerequisites

To run this project, you need to have the following prerequisites:

- C compiler (GCC, Clang, etc.)
- Standard C library (libc)

## Installation

To compile and run the project, follow these steps:

1. Clone or download the repository to your local machine.
2. Navigate to the project directory.
3. Compile the source code using the C compiler of your choice. For example, using GCC:
   ```bash
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<buffer_size> get_next_line.c get_next_line_utils.c main.c -o get_next_line
   ```
   Replace `<buffer_size>` with the desired buffer size (e.g., 32, 64, 128).
4. Run the executable:
   ```bash
   ./get_next_line <filename>
   ```
   Replace `<filename>` with the path to the text file you want to read.

## Project Structure

The project structure is organized as follows:

```
get_next_line/
  ├── get_next_line.c
  ├── get_next_line.h
  ├── get_next_line_utils.c
  ├── get_next_line_bonus.c
  ├── get_next_line_bonus.h
  ├── get_next_line_utils_bonus.c
  └── README.md
```

- `get_next_line.c`: The main implementation of the `get_next_line` function.
- `get_next_line.h`: The header file containing function prototypes and necessary definitions.
- `get_next_line_utils.c`: Utility functions used by `get_next_line`.
- `*_bonus.c`: Implementation for the bonus.
- `*_bonus.h`: The header file for the bonus.
- `README.md`: This file providing an overview and instructions for the project.
