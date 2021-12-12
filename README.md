[![Codacy Badge](https://app.codacy.com/project/badge/Grade/91a73b5827b44e08bd2aef3a057a88b3)](https://www.codacy.com/gh/dosart/Fifteen-Puzzle-Game/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=dosart/Fifteen-Puzzle-Game&amp;utm_campaign=Badge_Grade)
 ![cppcheck-action](https://github.com/stepin654321/MiniProject_Template/workflows/cppcheck-action/badge.svg) ![Valgrind](https://github.com/stepin654321/MiniProject_Template/workflows/Valgrind/badge.svg)

# Fifteen-Puzzle-Game

The 15 puzzle (also called Gem Puzzle, Boss Puzzle, Game of Fifteen, Mystic Square and many others) is a sliding puzzle having 15 square tiles numbered 1–15 in a frame that is 4 tiles high and 4 tiles wide, leaving one unoccupied tile position. Tiles in the same row or column of the open position can be moved by sliding them horizontally or vertically, respectively. The goal of the puzzle is to place the tiles in numerical order.

- **Technology stack:** sfml, c++17, spdlog, google test, doxygen, cmake
- **Status:** v.1.0
- **Architecture:** MVC

first pictures  | second pictures |
------------- | ------------- | 
![alt text](https://github.com/dosart/Fifteen-Puzzle-Game/blob/main/resources/images/11.png) | ![alt text](https://github.com/dosart/Fifteen-Puzzle-Game/blob/main/resources/images/22.png) 

The key bindings are: <kbd>&uarr;</kbd>, <kbd>&darr;</kbd>, <kbd>&larr;</kbd>, <kbd>&rarr;</kbd>. <kbd>F2</kbd>

## Installation

```console
$ git clone https://github.com/dosart/Fifteen-Puzzle-Game.git
$ cd Fifteen-Puzzle-Game.git
$ git submodule init && git submodule update
$ sudo apt-get install libsfml-dev
$ sudo apt-get install libgtest-dev

$ mkdir build && cd build
$ cmake .. && make -j
```
