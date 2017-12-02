// **********************************************
// COSC 501 LAB #3
// Elias Becker
// PROGRAM-NAME: Lab3_1
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
 * Created on September 20, 2017, 7:05 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    int input;
    cout << "Enter an integer: ";
    cin >> input;

    if (input > 0) {
        if (input % 2 != 0) {
            cout << input << " is Positive and Odd";
        } else if (input % 2 == 0) {
            cout << input << " is Positive and Even";
        }
    } else if (input < 0) {
        if (input % 2 != 0) {
            cout << input << " is Negative and Odd";
        } else if (input % 2 == 0) {
            cout << input << " is Negative and Even";
        }
    } else {
        cout << "You've inputted zero";
    }
     return 0;
}

