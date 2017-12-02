/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on November 8, 2017, 7:01 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    const int SIZE = 50;
    int sum = 0, count = 0;
    char input[SIZE] = {0};
    int total[SIZE] = {0};

    cout << "Enter any texts: ";
    cin.getline(input, SIZE);

    for (int i = 0; i < SIZE; i++) {

        if (input[i] >= 48 && input[i] <= 57) {
            total[count] = input[i] - 48;
            cout << total[count] << " ";
            sum += total[count];
            count++;
        }
    }
    
    cout << endl << "Sum of all the digits is: " << sum << endl;
    return 0;
}
