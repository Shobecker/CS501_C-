/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 4, 2017, 6:58 PM
 */
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double input;
    double inputPower;
    
    cout << "Input number for absolute number." << endl;
    cin >> input;
    cout << "abs(" << input << ") = " << abs(input) << endl; // returns the absolute value of x: (|x|)

    cout << "Input number and a power" << endl;
    cin >> input >> inputPower;
    cout << "pow(" << input << "," << inputPower << ") = " << pow(input, inputPower) << endl; // returns b raised to the power e: (be)

    cout << "Input number for square root." << endl;
    cin >> input;
    cout << "sqrt(" << input << ") = " << sqrt(input) << endl; // returns the square root of x: (√𝑥2F)

    cout << "Input number for ceil." << endl;
    cin >> input;
    cout << "ceil(" << input << ") = " << ceil(input) << endl; // returns x upward

    cout << "Input number for floor." << endl;
    cin >> input;
    cout << "floor(" << input << ") = " << floor(input) << endl; // returns x downward

    cout << "Input number for floor." << endl;
    cin >> input;
    cout << "round(" << input << ") = " << round(input) << endl; // returns the integral value that is nearest to x

    return 0;
}

