/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on November 1, 2017, 4:54 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
const int ROW_SIZE = 25;
const int COL_SIZE = 25;

int main(int argc, char** argv) {
    int range, row, col, input;
    char input2;
    int matrix[ROW_SIZE][COL_SIZE] = {0};
    
    while (true) {
        cout << "enter an odd integer for the size of the magic square: " << endl;
        cin >> input;

        while (!(input % 2 == 1)) {
            cout << "not an odd integer, please enter an odd integer: " << endl;
            cin >> input;
        }

        cout << endl;

        // Initialize for position 1
        range = input - 1;
        row = 0;
        col = (range / 2);

        for (int i = 1; i <= (input * input); i++) {
            matrix[row][col] = i;
            //rule 2, subt 1 from row, add 1 to col
            row--;
            col++;
            //rule 3, check boundary conditions.
            if (row < 0) {
                row = input - 1;
            }

            if (col >= input) {
                col = 0;
            }

            //rule 4, check if the cell has an input
            if (matrix[row][col] != 0) {
                row++;
                matrix[row][col] = i;
            }

        }

        for (int i = 0; i < input; i++) {
            for (int j = 0; j < input; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;

        while (true) {
            cout << "Do you want to do that again? (y/n)" << endl;
            cin >> input2;
            if (input2 == 'y' || input2 == 'Y') {
                break;
            }
            if (input2 == 'n' || input2 == 'N') {
                return 0;
            } else {
                cout << "Invalid input. ";
            }
        }
    }
    return 0;
}


