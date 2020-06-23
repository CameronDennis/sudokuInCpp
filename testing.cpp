//
// Created by Cameron on 02/18/2020.
//


#include "sudokuBoard.h"

int main() {
//    //c randq
//    srand(time(nullptr));
//    for (int i = 0; i++ < 20;) {
//        cout << (rand()>>6)%9 << ' ';
//    }
    SudokuBoard board;
    for (short row = 0; row < 9; row++) {
        for (short col = 0; col < 9; col++) {
            int boxInt = (row/3)*3+col/3;
            auto box = (short) boxInt;
            board.placeNum(box, row, col);
    //        cout << boxInt << ' ';
    //        if (col == 8) cout << endl;
        }
    }
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int boxInt = (row/3)*3+col/3;
            auto box = (short) boxInt;
            short *boxArray = board.boxGen(box);
            cout << "#######" << row << ' ' << col << ' ' << box << endl;
            for (int square = 0; square < 9; square++) {
                cout << boxArray[square] << ' ';
                if ((square == 2)||(square == 5)) cout << endl;
            }
            cout << endl;
        }
    }

    /* c++ random
    random_device rd{};
    mt19937 mt(rd());
    uniform_int_distribution<short> dist(0, 1023);
    int i = 0;
    while (i++ < 10) {
        cout << (dist(mt)<<6) << endl;
    }
    */
    return 0;
}