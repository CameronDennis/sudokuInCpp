//
// Created by Cameron on 02/12/2020.
//


#include "sudokuBoard.h"
using namespace std;

bool SudokuBoard::placeNum(short num, short row, short col) {
    if ((row > 8)||(col > 8)|(num > 9)) return false;
    board[row][col] = num;
    return true;
}

bool SudokuBoard::fillFromFile(const string& name) {
    ifstream entries;
    entries.open(name);
    if (entries.is_open()) {
        string line;
        while (getline(entries,line)) {
            size_t found = line.find("board");//checks for string board
            if (found != string::npos) { //if board is found
                short num;
                short row = 0, col = 0;
                getline(entries, line); //adds line containing board data to line
                for (int i = 0; i < 89; i++) {
                    if (line.at(i) == ' ') i++; //statement ignores spaces
                    num = ((short) line.at(i)) - 48;
                    if (num) occupied++;
                    board[row][col++] = num;//adds entries to board
                    if (col == 9) {
                        col = 0;
                        row++;
                    }
                }
            }
        }
        entries.close();
        return true;
    }
    else {
        cout << "File failed to open." << endl;
        return false;
    }
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
            if (row == 0) cout << TLCORNER;
            if ((row == 3)||(row == 6)) cout << RMIDDLE;
            if (row == 9) cout << (char) BLCORNER;
            for (short i = 0; i < 33; i++) {
                if (((i == 11)||(i == 22))&&(row%9 !=0)) {
                    cout << CROSS;
                }
                if (((i == 11)||(i == 22))&&(row == 0)) {
                    cout << TCROSS;
                }
                if (((i == 11)||(i == 23))&&(row == 9)) {
                    cout << BCROSS;
                }
                else cout << HLINE;
            }
            if (row == 0) cout << TRCORNER;
            if ((row == 3)||(row == 6)) cout << LMIDDLE;
            if (row == 9) cout << HLINE << HLINE << BRCORNER;
            cout << endl;
        }
        if (row < 9) {
            for (short col = 0; col < 9; col++) {
                if (col == 0) cout << VLINE;
                if (board[row][col] == 0) cout << "   ";
                else cout << "  " << board[row][col];
                if ((col+1)%3 == 0)  cout << "  " << VLINE;
            }
        }
            cout << endl;
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


void SudokuBoard::randomFill(short &row, short &col) {

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

}

void SudokuBoard::free() const {
    cout << occupied << endl;
}







/*
for (int i=0; i<16; ++i) {
    cout << dist(mt) << "\n";
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



