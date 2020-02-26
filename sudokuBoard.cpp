//
// Created by Cameron on 02/12/2020.
//


#include "sudokuBoard.h"


bool SudokuBoard::placeNum(short num, short row, short col) {
    if ((row > 8)||(col > 8)|(num > 9)) return false;
    board[row][col] = num;
    return true;
}

SudokuBoard::SudokuBoard() :
board{
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0}} {}

void SudokuBoard::print() {
    for (short row = 0; row < 10; row++) {
        if ((row%3 == 0)) {
            if (row == 0) std::cout << TLCORNER;
            if ((row == 3)||(row == 6)) std::cout << RMIDDLE;
            if (row == 9) std::cout << (char) BLCORNER;
            for (short i = 0; i < 33; i++) {
                if (((i == 11)||(i == 22))&&(row%9 !=0)) {
                    std::cout << CROSS;
                }
                if (((i == 11)||(i == 22))&&(row == 0)) {
                    std::cout << TCROSS;
                }
                if (((i == 11)||(i == 23))&&(row == 9)) {
                    std::cout << BCROSS;
                }
                else std::cout << HLINE;
            }
            if (row == 0) std::cout << TRCORNER;
            if ((row == 3)||(row == 6)) std::cout << LMIDDLE;
            if (row == 9) std::cout << HLINE << HLINE << BRCORNER;
            std::cout << std::endl;
        }
        if (row < 9) {
            for (short col = 0; col < 9; col++) {
                if (col == 0) std::cout << VLINE;
                if (board[row][col] == 0) std::cout << "   ";
                else std::cout << "  " << board[row][col];
                if ((col+1)%3 == 0)  std::cout << "  " << VLINE;
            }
        }
            std::cout << std::endl;
    }
}

bool SudokuBoard::isOpen(short num, short row, short col) {
    int boxInt = (row/3)*3+col/3;
    auto box = (short) boxInt;
    short *boxArray = boxGen(box);
    short *rowArray = rowGen(row);
    short *colArray = colGen(row);
    for (short i = 0; i < 9; i++) {
        if ((boxArray[i]==num)||(rowArray[i]==num)||(colArray[i]==num)) {
            return false;
        }
    }
    delete[] boxArray;
    delete[] rowArray;
    delete[] colArray;
    return true;
}

short *SudokuBoard::rowGen(short row) {
    auto * rowArray = new short[9];
    for (short col = 0; col < 9; col++) {
        rowArray[col] = board[row][col];
    }
    return rowArray;
}

short *SudokuBoard::colGen(short col) {
    auto * colArray = new short[9];
    for (short row = 0; row < 9; row++) {
        colArray[row] = board[row][col];
    }
    return colArray;
}

short *SudokuBoard::boxGen(short box) {
    auto * boxArray = new short[9];
    //Box 0 - row 0-2, col 0-2
    //Box 1 - row 0-2, col 3-5
    //Box 2 - row 0-2, col 6-8
    //Box 3 - row 3-5, col 0-2
    short i = 0;
    for (int row = (box/3)*3; row < (box/3)*3+3; row++) {
        for (int col = (box%3)*3; col < (box%3)*3+3; col++) {
            boxArray[i++] = board[row][col];
        }
    }
    return boxArray;
}

//short *SudokuBoard::surGen(short row, short col) {
//    auto * surArray = new short[21];
//    int boxInt = (row/3)*3+col/3;
//    auto box = (short) boxInt;
//
//
//    return nullptr;
//}



bool SudokuBoard::isPossible(short row, short col) {
    for (short num = 1; num < 10; num++) {
        if (isOpen(num, row, col)) return true;
    }
    return false;
}

void SudokuBoard::randomFill(short &row, short &col) {
    if (row == 9) return;
    short numIndex;
    short val;
//    bool available[9] = {true};
    std::vector<short> available = {1,2,3,4,5,6,7,8,9};
    std::vector<short>::iterator it;
    srand(time(nullptr));
    numIndex = (short) ((rand()>>6)%available.size());
    while(true) {
        if (isOpen(available.at(numIndex), row, col)) {
            val = available.at(numIndex);
            it = available.begin();
            advance(it, numIndex);
            available.erase(it);
            placeNum(val, row, col);
            print();
            if (!forward(row, col)) return;
            randomFill(row, col); //square moved forward
            if (row == 9) return;
            backward(row, col); //return to this location
            placeNum(0, row, col); //clears this location
            if (available.empty()) {
                return;
            }
            numIndex = numIndex%available.size();
        }
        else {
            it = available.begin();
            advance(it, numIndex);
            available.erase(it);
            if (available.empty()) return;
            numIndex = numIndex%available.size();
        }
    }



}

bool SudokuBoard::forward(short &row, short &col) {
    if (col == 8) {
        if (row == 8) return false;
        row++;
        col = 0;
        return true;
    }
    else {
        col++;
        return true;
    }
}

bool SudokuBoard::backward(short &row, short &col) {
    if (col == 0) {
        if (row == 0) return false;
        row--;
        col = 8;
        return true;
    }
    else {
        col--;
        return true;
    }
}

void SudokuBoard::fillBoard() {
    short row = 0;
    short col = 0;
    randomFill(row, col);
}





/*
for (int i=0; i<16; ++i) {
    std::cout << dist(mt) << "\n";
}

     for (short row = 0; row < 9; row++) {
        for (short col = 0; col < 9; col++) {
            placeNum(0, row, col);
            num = dist(mt);
            while (!isOpen(num, row, col)) {
                if (!isPossible(row, col)) {
                    possible = false;
                    break;
                }
                possible = true;
                num = dist(mt);
                for (const short& i : available) {
                    if (num == i)
                }
            }
            if(possible) placeNum(num, row, col);
            else {

            }
            print();
        }
 */



