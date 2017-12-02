// **********************************************
// COSC 501 LAB #3
// Elias Becker
// PROGRAM-NAME: Lab3_2
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
 * Created on September 20, 2017, 7:38 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int input, i = 1, sum = 0;
    cout << "Enter an integer (greater than or equal to 1): ";
    cin >> input;
    
    if (input <= 0) {
        cout << "Invalid input";
    } else {
        while (i <= input) {
            sum += i;
            i++;
        }
        cout << "Adding the numbers 1 to " << input <<": " << sum;
    }
    
    return 0;
}

