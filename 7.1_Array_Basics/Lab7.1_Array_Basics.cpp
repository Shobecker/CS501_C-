/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 25, 2017, 7:06 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
void printArray(int a[], int size);

int main(int argc, char** argv) {
    const int SIZE = 10;
    int array[SIZE] = {0};
    cout << "Enter 10 numbers: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> array[i];
    }
    printArray(array, SIZE);
    return 0;
}

void printArray(int a[], int size) {
    double sumEven = 0, sumOdd = 0;

    cout << "List the array elements" << endl;
    for (int i = 0; i < size; i++) {
        cout << "array [" << i << "]: " << a[i] << endl;
    }

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            sumEven += a[i];
        } else {
            sumOdd += a[i];
        }
    }
    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Average of even elements: " << sumEven / (size/2.0) << endl;
    cout << "Average of odd elements: " << sumOdd / (size/2.0) << endl;
}