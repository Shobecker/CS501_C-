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
#include "Student.h"


using namespace std;
using std::vector;
using std::string;

int main(int argc, char** argv) {
    string idNumber, lastName, firstName, phoneNumber, classLevel, className;
    char gender, middleInit, classGrade;
    int creditsFall, numberOfCourses, classCredits;
    double gpa;
    vector<string> courses;
    vector<int> credits;
    vector<char> grades;
    vector<int> integerValueGrades;

    cout << "Enter Student ID number: " << endl;
    cin >> idNumber;

    cout << "Enter last name: " << endl;
    cin >> lastName;

    cout << "Enter first name: " << endl;
    cin >> firstName;

    cout << "Enter middle initial: " << endl;
    cin >> middleInit;

    cout << "Enter phone number: " << endl;
    cin >> phoneNumber;

    cout << "Enter gender (M or F): " << endl;
    cin >> gender;
    tolower(gender);
    while (gender != 'm' || gender != 'f') {
        cout << "Invalid input. Please enter gender (M or F). " << endl;
        cin >> gender;
        tolower(gender);
    }

    cout << "Enter class level (FR, SO, JR, or SR): " << endl;
    cin >> classLevel;
    std::transform(classLevel.begin(), classLevel.end(), classLevel.begin(), ::tolower);
    while (classLevel != "fr" || classLevel != "so" || classLevel != "jr" || classLevel != "sr") {
        cout << "Invalid input. Please enter class level (FR, SO, JR, or SR): " << endl;
        cin >> classLevel;
        std::transform(classLevel.begin(), classLevel.end(), classLevel.begin(), ::tolower);
    }

    cout << "Enter number of Fall credits: " << endl;
    cin >> creditsFall;

    cout << "Enter number of Spring courses: " << endl;
    cin >> numberOfCourses;

    //Make Student class object. 
    //Student student = new Student(idNumber, lastName, firstName, middleInit, phoneNumber, gender, classLevel, creditsFall, numberOfCourses);


    for (int i = 0; i < numberOfCourses; i++) {
        cout << "Enter class name: " << endl;
        cin >> className;
        cout << "Enter class credits: " << endl;
        cin >> classCredits;
        cout << "Enter class grade: " << endl;
        cin >> classGrade;
        tolower(classGrade);
        while (classGrade != 'w' || classGrade != 'f' || classGrade != 'd' || classGrade != 'c' || classGrade != 'b' || classGrade != 'a') {
            cout << "Invalid input. Please enter class grade (A, B, C, D, F, or W): " << endl;
            cin >> classGrade;
            tolower(classGrade);
        }
        //add courses to student object
        //student.addCourse(className, classCredits, classGrade);
        //add courses to vector

    }

    return 0;
}