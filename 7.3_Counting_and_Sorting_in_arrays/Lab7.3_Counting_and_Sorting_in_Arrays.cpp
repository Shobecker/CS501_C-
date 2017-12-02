/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 25, 2017, 7:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */

void printArray(int a[], int size);

int main(int argc, char** argv) {
    const int SIZE = 20;
    ifstream fin;
    int number, checker, counter = 0;
    int distNum[SIZE] = {0}, count[SIZE] = {0};
    bool match;

    fin.open("Lab7_3input.txt");

    if (fin.fail()) {
        cout << "File failed to upload" << endl;
        exit(1);
    }

    while (!fin.eof()) {
        match = false;
        fin >> number;
        
        //cout << "Current number: " << number << endl;
        //checking array for repeating numbers.
        for (int i = 0; i < SIZE; i++) {
            if (distNum[i] == number) {
                match = true;
                checker = i;
            }
        }
        //if there is no match create a new counter equal to 1. 
        if (!match) {
            distNum[counter] = number;
            count[counter] = 1;
        //if repeating number is found counter for that number is increased by 1. 
        } else if (match) {
            count[checker] = count[checker] + 1;
        }
        
        match = false;
        counter++;
    }


    cout << "N" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (distNum[i] != 0) {
            cout << distNum[i] << endl;
        }
    }

    cout << "Count" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (count[i] != 0) {
            cout << count[i] << endl;
        }
    }


    fin.close();
    return 0;
}