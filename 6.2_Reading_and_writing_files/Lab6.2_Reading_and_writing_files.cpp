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
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    string last, first;
    int num, count;
    double total, avg;
    ifstream fin;
    ofstream fout;

    fin.open("Lab6_2data.txt");

    if (fin.fail()) {
        cout << "File failed to upload" << endl;
        exit(1);
    }

    fout.open("Lab6_2outputdata.txt");
    if (fout.fail()) {
        cout << "Output file opening failed" << endl;
        exit(1);
    }

    while (!fin.eof()) {

        fin >> last >> first;
        fout << last << " " << first << " ";
        cout << last << " " << first << endl;

        for (int i = 0; i < 10; i++) {

            fin >> num;
            fout << " " << num;
            cout << " " << num;
            total = total + num;
            count++;

        }

        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(2);
        
        avg = total / count;
        fout << " " << avg << '\r' << endl;
        cout << " " << avg << endl;
    }

    fin.close();
    fout.close();

    return 0;
}