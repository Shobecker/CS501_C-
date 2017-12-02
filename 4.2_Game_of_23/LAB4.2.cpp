/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on September 27, 2017, 6:59 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int toothpicks = 23, turn = 0, player, computer;

    while (toothpicks > 0) {
        cout << "(" << toothpicks << " toothpicks left)" << endl;
        switch (turn) {
            case 0:
                while (true) {
                    cout << "Player: ";
                    cin >> player;
                    if (player > 4) {
                        cout << "Invalid number of toothpicks. Please enter again" << endl;
                    } else if (player > toothpicks) {
                        cout << "It exceeded the number of toothpicks. Please enter again." << endl;
                    } else {
                        toothpicks -= player;
                        break;
                    }
                }
                if (toothpicks <= 0) {
                    cout << "Computer wins!";
                    break;
                }
                turn = (turn + 1) % 2;
                break;
                
            case 1:
                if (toothpicks == 1) {
                    computer = 1;
                } else if (toothpicks == 2) {
                    computer = 1;
                } else if (toothpicks == 3) {
                    computer = 2;
                } else if (toothpicks == 4) {
                    computer = 3;
                } else {
                    computer = 4;
                } 
                cout << "Computer: " << computer << endl;
                toothpicks -= computer;
                if (toothpicks <= 0) {
                    cout << "Player wins!";
                    break;
                }
                turn = (turn + 1) % 2;
        }
    }
    return 0;
}

