/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on November 29, 2017, 7:12 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n, input, highest, lowest;
    float sum = 0, average = 0;
    cout << "enter number of scores" << endl;
    cin >> n;
    int *array = new int[n];
    cout << "Input the test scores: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> input;
        array[i] = input;
    }

    //highest
    highest = array[0];
    for (int i = 1; i < n; i++) {
        if (highest < array[i]) {
            highest = array[i];
        }
    }

    //lowest
    lowest = array[0];
    for (int i = 1; i < n; i++) {
        if (lowest > array[i]) {
            lowest = array[i];
        }
    }

    //average
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    average = (sum * 1.0) / (n * 1.0);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Highest " << highest << endl;
    cout << "Lowest " << lowest << endl;
    cout << "Average " << average << endl;

    delete [] array;
    return 0;
}

