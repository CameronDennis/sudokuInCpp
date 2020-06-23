#include <iostream>
#include "sudokuBoard.h"

int main() {
    SudokuBoard board;
    board.fillFromFile("puzzles.txt");
    board.print();
    board.free();
    return 0;
}


