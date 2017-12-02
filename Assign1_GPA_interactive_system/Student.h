/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.h
 * Author: Elias
 *
 * Created on October 2, 2017, 2:59 PM
 */
#include <iostream>
#include <string>

#ifndef STUDENT_H
#define STUDENT_H

using std::string;

class Student {
public:
    //Default Constructor
    Student();
    //Overload Constructor
    Student(string newIDNumber, string newLastName, string newFirstName, char newMiddleInitial, string newPhoneNumber, char newGender, string newClassLevel, int fallCredits, int numberOfSpringCourses);
    addCourse(string newCourse, int newCredit, char newGrade);

    //Destructor
    virtual ~Student();

    //Accessor Functions
    string getIDNumber() const; //returns ID number of student
    string getLastName() const; //returns Last name of student
    string getFirstName() const; //returns first name of student
    char getMiddleInitial() const; // returns middle initial of student
    string getPhoneNumber() const; // returns phone number of student
    char getGender() const; // returns gender of student
    string getClassLevel() const; // returns class level of student
    int getFallCredits() const; //returns total fall credits for student
    int getNumberOfSpringCourses() const; // returns number of spring courses
    double getGPAFall(); // returns fall GPA for student
    double getGPASpring(); //returns spring GPA
    double getTotalGPA(); // returns total GPA


private:
    //Member Variables
    string newIDNumber, newLastName, newFirstName, newPhoneNumber, newClassLevel, newCourse;
    char newGender, newMiddleInitial, newGrade;
    int newCredit, newFallCredits, newNumberOfSpringCourses;
    double newGPAFall, newGPASpring, newTotalGPA;
};

#endif /* STUDENT_H */

