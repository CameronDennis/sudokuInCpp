//
// Created by Cameron on 02/18/2020.
//

#include <iostream>
#include <random>
#include <cfloat>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <vector>

int main() {
    //c rand
    srand(time(nullptr));
    for (int i = 0; i++ < 20;) {
        std::cout << (rand()>>6)%9 << ' ';
    }


    /* c++ random
    std::random_device rd{};
    std::mt19937 mt(rd());
    std::uniform_int_distribution<short> dist(0, 1023);
    int i = 0;
    while (i++ < 10) {
        std::cout << (dist(mt)<<6) << std::endl;
    }
    */
    return 0;
}