//
// Created by Cameron on 02/12/2020.
//

#ifndef SUDOKUV2_SUDOKUBOARD_H
#define SUDOKUV2_SUDOKUBOARD_H
#include <iostream>
#include <random>
#include <cfloat>
#include <ctime>

class SudokuBoard {
    private:
    short board[9][9];

    public:
    void randomFill(short row = 0, short col = 0);
    bool placeNum(short num, short row, short col);
    bool isOpen(short num, short row, short col);
    bool isPossible(short row, short col);
    SudokuBoard();//default constructor
    void print();
    short *rowGen(short row);
    short *colGen(short col);
    short *boxGen(short box);
    //short *surGen(short row, short col);
};


//macros
#define TLCORNER char (218)
#define TRCORNER char (191)
#define BLCORNER char (192)
#define BRCORNER char (217)
#define RMIDDLE char (195)
#define LMIDDLE char (180)
#define HLINE char (196)
#define VLINE char (179)
#define CROSS char (197)
#define TCROSS char (194)
#define BCROSS char (193)
#endif //SUDOKUV2_SUDOKUBOARD_H
