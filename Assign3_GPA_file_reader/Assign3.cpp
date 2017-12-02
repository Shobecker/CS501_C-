/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on September 30, 2017, 2:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <valarray>



using namespace std;
using std::vector;
using std::string;

const int SIZE = 10;
const int SSIZE = 50;

struct StudentInfo {
    string idNumber;
    string lastName;
    string firstName;
    char middleInt;
    string phoneNumber;
    char sex;
    string classLevel;
    int creditsFall;
    float cGPA;
    int numberOfClasses;
    string courses[SIZE];
    int credits[SIZE];
    char grades[SIZE];
    float calcSemGPA;
    float calcCGPA;
    float totalSpringCredits;
    float springHonorPoints;
    string registration2017;
};

void GetInput(StudentInfo matrix[]);
void CalcSemGPA(StudentInfo matrix[]);
void CalcCGPA(StudentInfo matrix[]);
void OutPut(StudentInfo matrix[]);

int main(int argc, char** argv) {
    StudentInfo s[SSIZE];

    //initialize int and float values to zero
    for (int i = 0; i < SSIZE; i++) {
        s[i].numberOfClasses = 0;
        s[i].cGPA = 0;
        s[i].creditsFall = 0;
        s[i].calcCGPA = 0;
        s[i].calcSemGPA = 0;
        s[i].numberOfClasses = 0;
        s[i].springHonorPoints = 0;
        s[i].totalSpringCredits = 0;
    }

    GetInput(s);
    CalcSemGPA(s);
    CalcCGPA(s);
    OutPut(s);

    return 0;
}

void GetInput(StudentInfo m[]) {
    ifstream fin("Stud.txt");
    StudentInfo s;
    string course;
    int credit;
    char grade;
    int j = 0;

    if (fin.fail()) {
        cout << "Failed to upload file" << endl;
        exit(1);
    }

    while (!fin.eof()) {
        fin >> s.idNumber >> s.lastName >> s.firstName >> s.middleInt >> s.phoneNumber >> s.sex >> s.classLevel >> s.creditsFall >> s.cGPA >> s.numberOfClasses;
        //cout << s.idNumber << " " << s.lastName << " " << s.firstName << " " << s.middleInt << " " << s.phoneNumber << " " << s.sex << " " << s.classLevel << " " << s.creditsFall << " " << s.cGPA << " " << s.numberOfClasses << " ";

        m[j].idNumber = s.idNumber;
        m[j].lastName = s.lastName;
        m[j].firstName = s.firstName;
        m[j].middleInt = s.middleInt;
        m[j].phoneNumber = s.phoneNumber;
        m[j].sex = s.sex;
        m[j].classLevel = s.classLevel;
        m[j].creditsFall = s.creditsFall;
        m[j].cGPA = s.cGPA;
        m[j].numberOfClasses = s.numberOfClasses;

        if (!(s.numberOfClasses == 0)) {
            for (int i = 0; i < s.numberOfClasses; i++) {
                fin >> course >> credit >> grade;
                s.courses[i] = course;
                s.credits[i] = credit;
                s.grades[i] = grade;
                m[j].courses[i] = course;
                m[j].credits[i] = credit;
                m[j].grades[i] = grade;
                m[j].registration2017 = "Yes";
                //cout << s.courses[i] << " " << s.credits[i] << " " << s.grades[i] << " ";
            }
        } else {
            m[j].registration2017 = "No";
        }
        //cout << endl;
        j++;
    }
    fin.close();
}

void CalcSemGPA(StudentInfo m[]) {
    float gradeValue, totalSpringCredits, springHonorPoints, springGPA;

    for (int j = 0; j < SSIZE; j++) {
        totalSpringCredits = 0;
        springHonorPoints = 0;
        gradeValue = 0;
        springGPA = 0;
        //cout << "J: " << j << endl;
        //cout << "Number of Classes: " << m[j].numberOfClasses << endl;

        // calculate total spring credits
        if (!(m[j].numberOfClasses == 0)) {
            for (int i = 0; i < m[j].numberOfClasses; i++) {
                //cout << "I: " << i << endl;

                if (m[j].grades[i] == 'w' || m[j].grades[i] == 'W') {
                    continue;
                }
                //cout << m[j].credits[i] << endl;
                totalSpringCredits += m[j].credits[i];
            }
            //cout << "Total Spring Credits " << totalSpringCredits << endl;

            //calculate honorPoints (grade * credits)
            for (int i = 0; i < m[j].numberOfClasses; i++) {
                if (m[j].grades[i] == 'w' || m[j].grades[i] == 'W') {
                    continue;
                } else if (m[j].grades[i] == 'A' || m[j].grades[i] == 'a') {
                    gradeValue = 4.0;
                } else if (m[j].grades[i] == 'B' || m[j].grades[i] == 'b') {
                    gradeValue = 3.0;
                } else if (m[j].grades[i] == 'C' || m[j].grades[i] == 'c') {
                    gradeValue = 2.0;
                } else if (m[j].grades[i] == 'D' || m[j].grades[i] == 'd') {
                    gradeValue = 1.0;
                } else {
                    gradeValue = 0.0;
                }
                springHonorPoints += (gradeValue * m[j].credits[i]);
                //cout << "Spring Honor Points " << springHonorPoints << endl;
            }
            springGPA = springHonorPoints / totalSpringCredits;
            //cout << "Spring GPA " << springGPA << endl;
            m[j].calcSemGPA = springGPA;
            m[j].springHonorPoints = springHonorPoints;
            m[j].totalSpringCredits = totalSpringCredits;
        } else {
            m[j].calcSemGPA = 0;
            m[j].springHonorPoints = 0;
            m[j].totalSpringCredits = 0;
        }
    }
}

void CalcCGPA(StudentInfo m[]) {
    for (int j = 0; j < SSIZE; j++) {
        if (!(m[j].cGPA == 0)) {
            m[j].calcCGPA = ((m[j].cGPA * m[j].creditsFall) + m[j].springHonorPoints) / (m[j].creditsFall + m[j].totalSpringCredits);
            //cout << m[j].calcCGPA << endl;
        }
    }
}

void OutPut(StudentInfo m[]) {
    ofstream fout("ReportsOut.txt");

    if (fout.fail()) {
        cout << "Out put file failed" << endl;
        exit(1);
    }

    for (int j = 0; j < SSIZE; j++) {
        if (m[j].idNumber > "0000000" && m[j].idNumber < "9999999") {
            cout << "***************************************************" << endl;
            fout << "***************************************************" << "\r" << endl;

            cout << "Student ID Number: " << m[j].idNumber << endl;
            fout << "Student ID Number: " << m[j].idNumber << "\r" << endl;

            cout << "Name: " << m[j].lastName << ", " << m[j].firstName << " " << m[j].middleInt << endl;
            fout << "Name: " << m[j].lastName << ", " << m[j].firstName << " " << m[j].middleInt << "\r" << endl;

            cout << "Tel: " << m[j].phoneNumber << endl;
            fout << "Tel: " << m[j].phoneNumber << "\r" << endl;

            if (m[j].sex == 'M') {
                cout << "Gender: " << "Male" << endl;
                fout << "Gender: " << "Male" << "\r" << endl;
            } else if (m[j].sex == 'F') {
                cout << "Gender: " << "Female" << endl;
                fout << "Gender: " << "Female" << "\r" << endl;
            }

            if (m[j].classLevel == "fr") {
                cout << "Class Level: " << "Freshman" << endl;
                fout << "Class Level: " << "Freshman" << "\r" << endl;
            } else if (m[j].classLevel == "so") {
                cout << "Class Level: " << "Sophomore" << endl;
                fout << "Class Level: " << "Sophomore" << "\r" << endl;
            } else if (m[j].classLevel == "jr") {
                cout << "Class Level: " << "Junior" << endl;
                fout << "Class Level: " << "Junior" << "\r" << endl;
            } else if (m[j].classLevel == "sr") {
                cout << "Class Level: " << "Senior" << endl;
                fout << "Class Level: " << "Senior" << "\r" << endl;
            }

            cout << "Registration of Spring 2017: " << m[j].registration2017 << endl;
            fout << "Registration of Spring 2017: " << m[j].registration2017 << "\r" << endl;

            cout << endl;
            fout << "\r" << endl;

            cout << "   Unofficial Report Card" << endl;
            fout << "   Unofficial Report Card" << "\r" << endl;

            cout << "Grade     Credits      Class" << endl;
            fout << "Grade     Credits      Class" << "\r" << endl;

            for (int i = 0; i < m[j].numberOfClasses; i++) {
                cout << m[j].grades[i] << "         " << m[j].credits[i] << "            " << m[j].courses[i] << endl;
                fout << m[j].grades[i] << "         " << m[j].credits[i] << "            " << m[j].courses[i] << "\r" << endl;
            }

            //Change decimals shown
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(2);
            fout.setf(ios::fixed);
            fout.setf(ios::showpoint);
            fout.precision(2);

            cout << endl;
            fout << "\r" << endl;

            cout << "Credits for Spring 2017: " << m[j].totalSpringCredits << endl;
            fout << "Credits for Spring 2017: " << m[j].totalSpringCredits << "\r" << endl;

            cout << "Spring 2017 Semester GPA: " << m[j].calcSemGPA << endl;
            fout << "Spring 2017 Semester GPA: " << m[j].calcSemGPA << "\r" << endl;

            cout << endl;
            fout << "\r" << endl;

            cout << "Total Credits: " << m[j].creditsFall + m[j].totalSpringCredits << endl;
            fout << "Total Credits: " << m[j].creditsFall + m[j].totalSpringCredits << "\r" << endl;

            cout << "New Cumulative GPA: " << m[j].calcCGPA << endl;
            fout << "New Cumulative GPA: " << m[j].calcCGPA << "\r" << endl;

            cout << "***************************************************" << endl;
            fout << "***************************************************" << "\r" << endl;
        }
    }
    fout.close();
}