/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 18, 2017, 7:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string male, female, name;
    int rank, count, count2;
    ifstream fin;

    fin.open("babynames2012.txt");

    if (fin.fail()) {
        cout << "File failed to upload" << endl;
        exit(1);
    }

    cout << "Enter a name: ";
    cin >> name;

    while (!fin.eof()) {
        fin >> rank;
        fin >> male >> female;
        while (name == male) {
            cout << male << " is ranked " << rank << " in popularity among boys." << endl;
            count++;
            break;
        }

        while (name == female) {
            cout << female << " is ranked " << rank << " in popularity among boys." << endl;
            count2++;
            break;
        }
    }
    if (count == 0) {
        cout << name << " is not ranked among the top 1000 boys." << endl;
    } 
    if (count2 == 0){
        cout << name << " is not ranked among the top 1000 girls." << endl;
    }
    
    fin.close();
    return 0;
}

