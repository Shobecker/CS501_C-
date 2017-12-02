// **********************************************
// COSC 501 LAB #3
// Elias Becker
// PROGRAM-NAME: Lab3_3
//**********************************************
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on September 20, 2017, 7:44 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char user1, user2;
    cout << "User1 - please enter your selection (P, R, or S): ";
    cin >> user1;
    cout << "User2 - please enter your selection (P, R, or S): ";
    cin >> user2;
    user1 = tolower(user1);
    user2 = tolower(user2);

    if (user1 == 'p') {
        if (user2 == 'r') {
            cout << "User 1 wins! Paper covers rock";
        } else if (user2 == 's') {
            cout << "User 2 wins! Scissors cut paper";
        } else if (user2 == 'p') {
            cout << "Nobody wins";
        } else {
            cout << "Invalid Selection ... Good Bye!";
        }
    } else if (user1 == 'r') {
        if (user2 == 'r') {
            cout << "Nobody wins";
        } else if (user2 == 's') {
            cout << "User1 wins! Rock breaks scissors";
        } else if (user2 == 'p') {
            cout << "User2 wins! Paper covers rock";
        } else {
            cout << "Invalid Selection ... Good Bye!";
        }
    } else if (user1 == 's') {
        if (user2 == 'r') {
            cout << "User2 wins! Rock breaks scissors";
        } else if (user2 == 's') {
            cout << "Nobody wins";
        } else if (user2 == 'p') {
            cout << "User1 wins! Scissors cut paper";
        } else {
            cout << "Invalid Selection ... Good Bye!";
        }
    } else {
        cout << "Invalid Selection ... Good Bye!";
    }


    return 0;
}

