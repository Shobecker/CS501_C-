/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 4, 2017, 7:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>


using namespace std;

/*
 * 
 */
int getRand(int min, int max);

int main(int argc, char** argv) {
    int min, max;
    srand(time(NULL));
    cout << "Enter the min and max of the random number: ";
    cin >> min >> max;
    cout << "Generating 10 random numbers…" << endl;

    for (int i = 0; i < 10; i++) {
        cout << getRand(min, max) << " ";
    }


    return 0;
}

int getRand(int min, int max) {
    return (rand() % (max - min + 1) + min);
}
