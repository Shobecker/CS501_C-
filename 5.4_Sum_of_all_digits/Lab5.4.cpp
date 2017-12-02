/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 4, 2017, 8:05 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int number, sum;
    cout << "Enter a number: ";
    cin >> number;
    
    while (number != 0) {
        sum += number%10;
        number = number/10;
        
    }
    cout << "The sum of digits = " << sum;
    return 0;
}

