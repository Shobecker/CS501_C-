/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on November 1, 2017, 6:57 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char seats[7][4];

    //populates seats
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            seats[i][j] = 'A' + j;
        }
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            cout << seats[i][j] << ' ';
        }
        cout << endl;
    }

    char seatRow, seatCol;
    int row, col;
    while (true) {
        cout << "Enter the seat you want to reserve (e.g. 1A, 2B) (enter -1 to end program): ";
        cin >> seatRow >> seatCol;

        if (seatRow == '-' && seatCol == '1') {
            break;
        }

        row = seatRow - '1';
        col = seatCol - 'A';
        
        if (seats[row][col] == 'X') {
            cout << "Seat is occupied, please choose different seat" << endl;
        }
        
        seats[row][col] = 'X';

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 4; j++) {
                cout << seats[i][j] << ' ';
            }
            cout << endl;
        }

        //Program ends if all seats are filled
        int counter = 0;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 4; j++) {
                if (seats[i][j] == 'X') {
                    counter++;
                    if (counter == 28) {
                        cout << "Seats are full" << endl;
                        exit(1);
                    }
                }
            }
        }

    }
    return 0;
}

