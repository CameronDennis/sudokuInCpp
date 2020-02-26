#include <iostream>
#include "sudokuBoard.h"

int main() {
    SudokuBoard board;
    //board.placeNum(9, 7, 8);
    //board.placeNum(7, 8, 7);
    //board.placeNum(4, 8, 8);
    //board.placeNum(2, 6, 8);
    //board.print();
//    short * please = board.boxGen(8);
//    for (short i = 0; i < 9; i++) {
//        std::cout << please[i] << ", ";
//    }
    //std::cout << std::endl;
    board.fillBoard();
    board.print();
    return 0;
}


