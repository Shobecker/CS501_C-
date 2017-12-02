/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 25, 2017, 7:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*
 * 
 */
void fillArray(int a[ ], int size); //fill array elements with random numbers
void printArray(int a[], int size); //print array elements from a[0] to a[size-1]
void printArrayReverse(int a[], int size); //print array elements from a[size-1] to a[0]
int max(int a[], int size); //return the maximum value of the array
int min(int a[], int size); //return the minimum value of the array 

int main(int argc, char** argv) {
    const int SIZE = 20;
    int array[SIZE];

    fillArray(array, SIZE);
    cout << "Random Array: ";
    printArray(array, SIZE);
    cout << "\nRandom Array In Reverse Order: ";
    printArrayReverse(array, SIZE);
    cout << "\nMax value of the array: " << max(array, SIZE);
    cout << "\nMin value of the array: " << min(array, SIZE);
    return 0;
}

void fillArray(int a[], int size) {
    int max = 100, min = 1;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        a[i] = (rand() % (max - min + 1) + min);
    }
}

void printArray(int a[], int size) {

    cout << "Random Array" << endl;
    for (int i = 0; i < size; i++) {
        cout << "array [" << i << "]: " << a[i] << endl;
    }
}

void printArrayReverse(int a[], int size) {
    cout << "Random Array In Reverse Order: " << endl;
    for (int i = size - 1; i >= 0; i--) {
        cout << "array [" << i << "]: " << a[i] << endl;
    }
}

int max(int a[], int size) {
    int max = a[0];
    for (int i = 0; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int min(int a[], int size) {
    int min = a[0];
    for (int i = 0; i < size; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}
