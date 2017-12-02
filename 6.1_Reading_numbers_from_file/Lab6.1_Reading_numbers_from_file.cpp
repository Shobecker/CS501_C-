/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 18, 2017, 7:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
//#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream in_stream; // can also declare file here by using in_stream("Lab6_1data.txt");

    in_stream.open("Lab6_1data.txt");

    if (in_stream.fail()) { //can also use if(!in_stream.good())
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    int num, max = 0, min = 1000, sum = 0, count = 0;

    while (in_stream >> num) { //(!in_stream.eof()) - eof means end of file, . in_stream >> num, however, it only works for numbers. If there is text there will be an error.
        //cout << num << endl;
        sum = sum + num;
        count++;
        
        if (max < num) {
            max = num;
        }
        
        if (min > num) {
            min = num;
        }
    }

    double average;
    average = (double)sum / count;

//    cout.setf(ios::fixed);
//    cout.setf(ios::showpoint);
    
    cout << "Average: " << average << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;

    in_stream.close();
    return 0;
}

