# Settlers of Catan - C++ Implementation

## Overview

This project is a C++ implementation of the popular board game, Settlers of Catan. The game involves players building settlements, cities, and roads on a board representing the island of Catan. Players collect resources, trade with each other, and compete to achieve the largest army.

## Files

- **board.cpp** and **board.hpp**: These files contain the implementation of the game board, including the layout and initialization of tiles, roads, and settlements.
- **catan.cpp** and **catan.hpp**: These files include the core game logic, including the main game loop, player turn management, and win condition checks.
- **player.cpp** and **player.hpp**: These files define the player class, including player resources, development cards, and actions such as building and trading.
- **enums.hpp**: This file defines various enumerations used throughout the project, such as resource types.
- **Demo.cpp**: This file contains a demonstration of the game's functionality, serving as the entry point for running the game.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang)
- CMake (optional, but recommended for building the project)

### Building the Project

If you are using CMake, follow these steps:

1. **Build the project:**
    ```bash
    make
    ```
2. **Running the Game:**
    ```bash
    ./catan
    ```

### Running the Tests

After building the project, you can run the 'Test':
1. **Build the project:**
    ```bash
    make test
    ```
2. **Running the Test:**
    ```bash
    ./test
