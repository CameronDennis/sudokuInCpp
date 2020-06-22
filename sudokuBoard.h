//
// Created by Cameron on 02/12/2020.
//

#ifndef SUDOKUV2_SUDOKUBOARD_H
#define SUDOKUV2_SUDOKUBOARD_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <vector>


class SudokuBoard {
    private:
    short board[9][9];

    public:
    bool forward(short &row, short &col);
    bool backward(short &row, short &col);
    void fillBoard(void);
    void randomFill(short &row, short &col);
    bool placeNum(short num, short row, short col);
    bool isOpen(short num, short row, short col);
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
