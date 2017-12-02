// **********************************************
// COSC 501 LAB #2
// Elias Becker
// PROGRAM-NAME: Lab2_3
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
 * Created on September 13, 2017, 9:00 PM
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    float amount;
    double item, taxes, total;
    const double SALES_TAX = .06;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Please the amount of the item purchased: " << endl;
    cin >> amount;
    
    taxes = SALES_TAX * amount;
    total = taxes + amount;
    
    cout << "The item purchased was: " << amount << endl;
    cout << "Taxes on this item are: " << taxes << endl;
    cout << "Total amount of purchase is: " << total << endl;

    return 0;
}


