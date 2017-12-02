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
#include <string>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream fin("Lab8_2data.txt");
    string text, results;
    int start, end;
    
    if (fin.fail()) {
        cout << "Unable to read the file.";
        return -1;
    }
    
    getline(fin, text);
    
    // you need to implement from here
    cout << "Text: " << text << endl;
    start = text.find("(", 0); //finds string text starting from index 0
    //cout << start << endl;
    end = text.find(")", start);
    //cout << end << endl;
    results = text.substr(start + 1, end - start - 1);
    cout << "Extracted Word: " << results;
    
    while (end != string::npos) {
        start = text.find("(", end+1);
        //cout << start << endl;
        end = text.find(")", start);
        //cout << end << endl;
        
        if (start == -1 || end == -1) {
            break;
        }
        
        results = text.substr(start + 1, end - start - 1);
        cout << " " << results;
    }

        
    fin.close();

    return 0;
}

