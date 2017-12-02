/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on November 1, 2017, 6:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
const int SIZE = 50;

/*
 * 
 */
void sort(string a[], int numbersUsed);
void swap_string(string& v1, string& v2);
int index_of_smallest(const string a[], int startIndext, int numberUsed);

int main(int argc, char** argv) {
    ifstream fin("fruits.txt");
    string input;
    string array[SIZE];
    int count = 0;

    if (fin.fail()) {
        cout << "Failed to upload file";
        exit(1);
    }

    cout << "Before sorting:" << endl;
    while (!fin.eof()) {
        fin >> input;
        array[count] = input;
        cout << array[count] << ", ";
        count++;
    }

    cout << endl << "After sorting:" << endl;
    sort(array, count);

    for (int i = count - 1; i >= 0; i--) {
        cout << array[i] << ", ";
    }

    return 0;
}

void sort(string a[], int numbersUsed) {
    int indexOfNextSmallest;
    for (int i = 0; i < numbersUsed; i++) {
        indexOfNextSmallest = index_of_smallest(a, i, numbersUsed);
        swap_string(a[i], a[indexOfNextSmallest]);
    }
}

void swap_string(string& v1, string& v2) {
    string temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int index_of_smallest(const string a[], int startIndex, int numberUsed) {
    string min = a[startIndex]; 
    int indexOfMin = startIndex;

    for (int i = startIndex + 1; i < numberUsed; i++) {
        if (a[i] > min) {
            min = a[i];
            indexOfMin = i;
        }
    }
    return indexOfMin;
}