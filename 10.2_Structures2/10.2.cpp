/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on November 15, 2017, 7:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*
 * 
 */

struct StudentInfo {
    string fname;
    string lname;
    int quiz1;
    int quiz2;
    int midterm;
    int final;
    float grade;
    char letterGrade;
};

int main(int argc, char** argv) {
    ifstream fin;
    ofstream fout;
    string fname, lname;
    StudentInfo s;
    
    fin.open("Lab10_2input.txt");
    fout.open("Lab10_2output.txt");

    if (fin.fail()) {
        cout << "in file failed to open";
        return -1;
    }

    if (fin.fail()) {
        cout << "out file failed to open";
        return -1;
    }
    
    fin >> s.fname;
    while (!fin.eof()) {
        fin >> s.lname >> s.quiz1 >> s.quiz2 >> s.midterm >> s.final;
        s.grade = (((s.quiz1 + s.quiz2) / 20.0)*0.25 + s.midterm / 100.0 * .25 + s.final / 100.0 * .5) * 100;
        
        if (s.grade >= 90) {
            s.letterGrade = 'A';
        } else if (s.grade >= 80 && s.grade < 90) {
            s.letterGrade = 'B';
        } else if (s.grade >= 70 && s.grade < 80) {
            s.letterGrade = 'C';
        } else if (s.grade >= 60 && s.grade < 70) {
            s.letterGrade = 'D';
        } else {
            s.letterGrade = 'F';
        }
        
        fout << s.fname << " " << s.lname << " " << s.quiz1 << " " << s.quiz2 << " " << s.midterm << " " << s.final << " " << setprecision(2) << fixed << s.grade << " " << s.letterGrade << " " << "\r" << endl;;
        cout << s.fname << " " << s.lname << " " << s.quiz1 << " " << s.quiz2 << " " << s.midterm << " " << s.final << " " << setprecision(2) << fixed << s.grade << " " << s.letterGrade << endl;
        fin >> s.fname;
    }

    fin.close();
    fout.close();

    return 0;
}

