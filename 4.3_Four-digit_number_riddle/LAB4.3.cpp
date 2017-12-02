/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on September 27, 2017, 7:00 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int x4, x3, x2, x1;

    for (int i = 1001; i <= 9999; i += 2) {
        x1 = i / 1000 % 10;
        x2 = i / 100 % 10;
        x3 = i / 10 % 10;
        x4 = i % 10;

        //check first number is 3 times the third.
        if (x1 != (x3 * 3)) {
            continue;
        }
        
        //unique number check
        if (x1 != x2 && x1 != x3 && x1 != x4 && x2 != x3 && x2 != x4 && x3 != x4) {
            // sum check
            if((x1 + x2 + x3 + x4) == 27) {
                cout << i;
            }
        }
    }
    return 0;
}

