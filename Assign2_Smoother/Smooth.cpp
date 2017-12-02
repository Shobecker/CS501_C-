/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 31, 2017, 6:09 PM
 */

#include <cstdlib>
#include <math.h>   
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
const int NUM_ROWS = 20;
const int NUM_COLS = 20;

void Get_Input(int matrix[][NUM_COLS], int sizeRow, int sizeCol);
//pre-condition: input 2-d array and size.
//post-condition: inputs file data into array.
void Pic_Draw(int matrix[][NUM_COLS], char picture[][NUM_COLS], int sizeRow, int sizeCol);
//pre-condition: input 2-d array and sizes
//post-condition: replaces numbers in array with symbols
void Smoothing(int matrix[][NUM_COLS], int sizeRow, int sizeCol);
//pre-condition: input 2-d array and size.
//post-condition: corrects errors of matrix.

int main(int argc, char** argv) {
    ofstream foutOrig, foutSmooth;
    int matrix[NUM_ROWS][NUM_COLS];
    char pic[NUM_ROWS][NUM_COLS];

    foutOrig.open("ORG_Elias_Becker_0673.txt");
    
    if (foutOrig.fail()) {
        cout << "Output origin file opening failed" << endl;
        exit(1);
    }

    foutSmooth.open("SMO_Elias_Becker_0673.txt");
    if (foutSmooth.fail()) {
        cout << "Output smooth file opening failed" << endl;
        exit(1);
    }

    //putting input data into array.
    cout << "inputing data into array" << endl;
    Get_Input(matrix, NUM_ROWS, NUM_COLS);

    //creating picture array with image values.
    cout << "Image value array w/o smoothing" << endl;
    Pic_Draw(matrix, pic, NUM_ROWS, NUM_COLS);

    //input array into ORG file
    cout << "Input character array w/o smoothing into ORG file" << endl;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            foutOrig << pic[i][j] << " ";
        }
        foutOrig << '\r' << endl;
    }

    //smoothing array
    cout << "Smoothing array" << endl;
    Smoothing(matrix, NUM_ROWS, NUM_COLS);
    //printing out smoothed array
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //creating picture array with new smoothed array
    cout << "Character image of smoothed array" << endl;
    Pic_Draw(matrix, pic, NUM_ROWS, NUM_COLS);

    //putting new picture array into SMO file
    cout << "Inputing character array into SMO file" << endl;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            foutSmooth << pic[i][j] << " ";
        }
        foutSmooth << '\r' << endl;
    }


    foutOrig.close();
    foutSmooth.close();
    return 0;
}

void Get_Input(int matrix[][NUM_COLS], int sizeRow, int sizeCol) {
    int numHolder;
    ifstream fin;

    fin.open("HW2inputdata.txt");

    if (fin.fail()) {
        cout << "Fail failed to upload";
        exit(1);
    }

    for (int i = 0; i < sizeRow; i++) {
        for (int j = 0; j < sizeCol; j++) {

            fin >> numHolder;
            matrix[i][j] = numHolder;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    fin.close();
}

void Pic_Draw(int matrix[][NUM_COLS], char picture[][NUM_COLS], int sizeRow, int sizeCol) {
    int numberHolder;
    char characterHolder;

    for (int i = 0; i < sizeRow; i++) {
        for (int j = 0; j < sizeCol; j++) {
            numberHolder = matrix[i][j];

            if (numberHolder >= 5) {
                characterHolder = '$';
            } else if (numberHolder <= 4 && numberHolder >= 2) {
                characterHolder = '*';
            } else if (numberHolder <= 1) {
                characterHolder = '.';
            }
            picture[i][j] = characterHolder;
            //cout << picture[i][j] << " ";
        }
        //cout << endl;
    }
}

void Smoothing(int matrix[][NUM_COLS], int sizeRow, int sizeCol) {
    int left, right, top, bottom, center;
    double average;

    for (int i = 1; i < (sizeRow - 1); i++) {
        for (int j = 1; j < (sizeCol - 1); j++) {
            center = matrix [i][j];
            top = matrix[i - 1][j];
            left = matrix[i][j - 1];
            right = matrix[i][j + 1];
            bottom = matrix[i + 1][j];
            average = round((top + bottom + right + left) / 4.0);

            if (abs(top - center) >= 2 && abs(left - center) >= 2 && abs(right - center) >= 2 && abs(bottom - center) >= 2) {
                matrix[i][j] = average; //error here
            }
        }
    }
}