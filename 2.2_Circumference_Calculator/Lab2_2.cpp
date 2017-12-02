// **********************************************
// COSC 501 LAB #2
// Elias Becker
// PROGRAM-NAME: Lab2_2
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
 * Created on September 13, 2017, 8:39 PM
 */

#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main() {
    int radius;
    double diameter, area, circumference;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // need to implement something
    cout << "Please enter a value for the radius of a circle: " << endl;
    cin >> radius;
    while (radius < 0) {
        cout << "Please enter a positive value for the radius of a circle: " << endl;
        cin >> radius;
    }
    diameter = radius * 2;
    area = M_PI * radius * radius;
    circumference = 2 * M_PI * radius;
    cout << "Diameter = " << diameter << endl;
    cout << "Area = " << area << endl;
    cout << "Circumference = " << circumference << endl;

    return 0;
}

